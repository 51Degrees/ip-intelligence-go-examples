package main

import (
	"bufio"
	"bytes"
	"fmt"
	"github.com/51Degrees/ip-intelligence-examples-go/ipi_onpremise/common"
	"github.com/51Degrees/ip-intelligence-go/ipi_interop"
	"github.com/51Degrees/ip-intelligence-go/ipi_onpremise"
	"github.com/goccy/go-yaml"
	"log"
	"os"
	"runtime"
	"sync"
	"sync/atomic"
	"time"
)

const iterationCount = 5

func executeTest(engine *ipi_onpremise.Engine, wg *sync.WaitGroup, report *common.Report, ipAddress string, iteration uint32) {
	res, err := engine.Process(ipAddress)
	if err != nil {
		log.Fatalln(err)
	}
	defer res.Free()

	if res.HasValues() {
		var actual bytes.Buffer
		for _, property := range common.Properties {
			res, err := ipi_interop.GetPropertyValueAsRaw(res.CPtr, property)
			if err != nil {
				log.Printf("Error processing property %s with error: %v", property, err)
				return
			}

			actual.WriteString(fmt.Sprintf("%s: %s\n", property, res))
		}

		hash := common.GenerateHash(actual.String())
		report.UpdateHashCode(hash, iteration)
	}

	// Increase the number of Evidence Records processed
	atomic.AddUint64(&report.EvidenceProcessed, 1)

	// Complete and mark as done
	defer wg.Done()
}

func performDetectionIterations(engine *ipi_onpremise.Engine, wg *sync.WaitGroup, report *common.Report, params *common.ExampleParams) {
	for i := 0; i < report.IterationCount; i++ {
		evidenceFilePath := common.GetFilePathByPath(params.EvidenceYaml)

		// Open the Evidence Records file for processing
		file, err := os.OpenFile(evidenceFilePath, os.O_RDONLY, 0444)
		if err != nil {
			log.Fatalf("Failed to close file \"%s\".\n", evidenceFilePath)
		}

		defer func() {
			if err := file.Close(); err != nil {
				log.Fatalf("Failed to close file \"%s\".\n", evidenceFilePath)
			}
		}()

		// Create a new scanner to read the file line by line
		scanner := bufio.NewScanner(file)

		// Loop through the file and read each line
		for scanner.Scan() {
			line := scanner.Text() // Get the line as a string

			var doc map[string]string
			if err := yaml.Unmarshal([]byte(line), &doc); err != nil {
				log.Printf("Failed to unmarshal line \"%s\".\n", line)
				continue
			}

			if doc == nil {
				continue
			}

			// Increase wait group
			wg.Add(1)

			go executeTest(engine, wg, report, doc["server.client-ip"], uint32(i))
		}
	}

	wg.Done()
}

func countEvidenceFromFile(params *common.ExampleParams) (uint64, error) {
	evidenceFilePath := common.GetFilePathByPath(params.EvidenceYaml)

	// Open the Evidence Records file for processing
	file, err := os.OpenFile(evidenceFilePath, os.O_RDONLY, 0444)
	if err != nil {
		return 0, err
	}

	defer func() {
		if err := file.Close(); err != nil {
			log.Fatalf("Failed to close file \"%s\".\n", evidenceFilePath)
		}
	}()

	// Create a new scanner to read the file line by line
	scanner := bufio.NewScanner(file)

	var countEvidences uint64 = 0

	// Loop through the file and read each line
	for scanner.Scan() {
		line := scanner.Text() // Get the line as a string

		var doc map[string]string
		if err := yaml.Unmarshal([]byte(line), &doc); err != nil {
			log.Printf("Failed to unmarshal line \"%s\".\n", line)
			continue
		}

		if doc == nil {
			continue
		}

		countEvidences++
	}

	return countEvidences, nil
}

func runReloadFromFile(engine *ipi_onpremise.Engine, params *common.ExampleParams) {
	count, err := countEvidenceFromFile(params)
	if err != nil {
		log.Fatalln(err)
	}

	actReport := &common.Report{
		IterationCount: iterationCount,
		EvidenceCount:  count * iterationCount,
	}

	actReport.InitHashCodes(iterationCount)

	reloads := 0
	reloadFails := 0

	var wg sync.WaitGroup

	wg.Add(1)
	go performDetectionIterations(engine, &wg, actReport, params)

	for actReport.EvidenceProcessed < actReport.EvidenceCount {
		currentTime := time.Now().Local()

		if err := os.Chtimes(params.DataFile, currentTime, currentTime); err != nil {
			reloadFails++
		} else {
			reloads++
		}
		// Sleep 1 seconds between reload
		time.Sleep(1000 * time.Millisecond)
	}

	// Wait until all goroutines finish
	wg.Wait()

	// Construct report
	log.Printf("Reloaded '%d' times.\n", reloads)
	log.Printf("Failed to reload '%d' times.\n", reloadFails)

	initHashCode := actReport.HashCodes[0]
	for i := 0; i < actReport.IterationCount; i++ {
		if initHashCode != actReport.HashCodes[i] {
			log.Fatalf("Hash codes do not match. Initial hash code is '%d', "+
				"but iteration '%d' has hash code '%d'. This indicates not "+
				"all Evidence Records have been processed correctly for each "+
				"iteration.", initHashCode, actReport.HashCodes[i], i)
		}

		log.Printf("Hashcode '%d' for iteration '%d'.\n", actReport.HashCodes[i], i)
	}
}

func main() {
	common.RunExample(
		func(params *common.ExampleParams) error {
			//Create config
			config := ipi_interop.NewConfigIpi(ipi_interop.InMemory)
			config.SetConcurrency(uint16(runtime.NumCPU()))

			//Create on-premise engine
			engine, err := ipi_onpremise.New(
				// Optimized config provided
				ipi_onpremise.WithConfigIpi(config),
				// Path to your data file
				ipi_onpremise.WithDataFile(params.DataFile),
				// Enable automatic updates.
				ipi_onpremise.WithAutoUpdate(false),
				// File System Watcher is by default enabled
				ipi_onpremise.WithFileWatch(true),
			)
			if err != nil {
				log.Fatalf("Failed to create engine: %v", err)
			}

			// Run example
			runReloadFromFile(engine, params)

			engine.Stop()

			return nil
		})
}
