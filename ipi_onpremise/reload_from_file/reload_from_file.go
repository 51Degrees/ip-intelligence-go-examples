/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2025 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence (EUPL)
 * v.1.2 and is subject to its terms as set out below.
 *
 * If a copy of the EUPL was not distributed with this file, You can obtain
 * one at https://opensource.org/licenses/EUPL-1.2.
 *
 * The 'Compatible Licences' set out in the Appendix to the EUPL (as may be
 * amended by the European Commission) shall be deemed incompatible for
 * the purposes of the Work and the provisions of the compatibility
 * clause in Article 5 of the EUPL shall not apply.
 *
 * If using the Work as, or as part of, a network application, by
 * including the attribution notice(s) required under Article 5 of the EUPL
 * in the end user terms of the application under an appropriate heading,
 * such notice(s) shall fulfill the requirements of that article.
 * ********************************************************************* */
/*
*
@example getting_started.go
Getting started example of using 51Degrees IP intelligence.

The example shows how to use 51Degrees on-premise IP intelligence to
determine the country of a given IP address in golang wrapper integration.

This example is available in full on [GitHub](https://github.com/51Degrees/ip-intelligence-go-examples/tree/main/ipi_onpremise/getting_started).

@include{doc} example-require-datafile-ipi.txt

@include{doc} example-how-to-run-ipi.txt

# In detail, the example shows how to

1. Specify config for engine:
This setting specifies the performance profile that will be used when initializing the C library.

```
config := ipi_interop.NewConfigIpi(ipi_interop.InMemory)
```
TODO: add description
```
config.SetConcurrency(uint16(runtime.NumCPU()))
```

2. Initialization of the engine with the following parameters:
```
engine, err := ipi_onpremise.New(

	// Optimized config provided
	ipi_onpremise.WithConfigIpi(config),
	// Path to your data file
	ipi_onpremise.WithDataFile(params.DataFile),
	// Enable automatic updates.
	ipi_onpremise.WithAutoUpdate(false),

)
```
TODO: add description

```
ipi_onpremise.WithConfigIpi(config)
```
TODO: add description

```
ipi_onpremise.WithDataFile(params.DataFile),
```
TODO: add description

```
ipi_onpremise.WithAutoUpdate(false),
```

3. Engine output with the parameter of the required address to receive data
```
result, err := engine.Process(ipiItem.IpAddress)

```

4. Checking for the presence of the result after engine processing
```
if result.HasValues() {}

```

5. Getting the results of the values after processing
```
_, err := ipi_interop.GetPropertyValueAsRaw(result.CPtr, property);

```

Expected output (ipi_performance_report.log):
```
...
Average 0.08775 ms per Evidence Record
Average 11396.01 detections per second
Total Evidence Records: 20000
Iteration Count: 5
Processed Evidence Records: 100000
Number of CPUs: 14

```
*/
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
