package main

import (
	"bufio"
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

const reportFile = "ipi_performance_report.log"

const iterationCount = 5

func readYaml(params *common.ExampleParams) (common.IpEvidences, error) {
	evidenceFilePath := common.GetFilePathByPath(params.EvidenceYaml)

	// Open the Evidence Records file for processing
	file, err := os.OpenFile(evidenceFilePath, os.O_RDONLY, 0444)
	if err != nil {
		return common.IpEvidences{}, err
	}

	defer func() {
		if err := file.Close(); err != nil {
			log.Fatalf("Failed to close file \"%s\".\n", evidenceFilePath)
		}
	}()

	// Create a new scanner to read the file line by line
	scanner := bufio.NewScanner(file)

	evidences := make(common.IpEvidences, 0)

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

		evidences.Add(doc["server.client-ip"])
	}

	return evidences, nil
}

func processEvidence(engine *ipi_onpremise.Engine, wg *sync.WaitGroup, ipAddress string, report *common.Report) {
	atomic.AddUint64(&report.EvidenceProcessed, 1)
	// Complete and mark as done
	defer wg.Done()

	result, err := engine.Process(ipAddress)
	if err != nil {
		log.Fatalln(err)
	}

	if result.HasValues() {
		for _, property := range common.Properties {
			// don't use the property in the current step, only processing data
			if _, err := ipi_interop.GetPropertyValueAsRaw(result.CPtr, property); err != nil {
				log.Printf("Error processing property %s with error: %v", property, err)
				return
			}
		}
	}

	defer result.Free()
}

func runPerformance(engine *ipi_onpremise.Engine, params *common.ExampleParams) (*common.Report, error) {
	actReport := &common.Report{
		IterationCount: iterationCount,
	}

	startProcessTime := time.Now()

	// Getting evidences from the file
	evidences, err := readYaml(params)
	if err != nil {
		log.Fatalf("Failed to read yaml files.\n")
		return nil, err
	}

	// set the count of evidences to our report
	actReport.EvidenceCount = evidences.Size()

	var wg sync.WaitGroup

	// process loaded evidences
	for i := 0; i < actReport.IterationCount; i++ {
		for _, evidence := range evidences {
			wg.Add(1)
			go processEvidence(engine, &wg, evidence, actReport)
		}
	}

	wg.Wait()

	actReport.ProcessingTime = time.Since(startProcessTime).Milliseconds()

	return actReport, nil
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
			)
			if err != nil {
				log.Fatalf("Failed to create engine: %v", err)
			}

			// Run example
			report, err := runPerformance(engine, params)
			if err != nil {
				log.Fatalf("Failed to run performance: %v", err)
			}

			// Validation to make sure same number of Evidences have been read and processed
			if report.EvidenceCount*uint64(report.IterationCount) != report.EvidenceProcessed {
				log.Fatalln("Not all Evidence Records have been processed.")
			}

			// print report to the file
			if err := report.PrintReport(reportFile); err != nil {
				log.Fatalf("Failed to print report: %v", err)
			}

			engine.Stop()

			return nil
		})
}
