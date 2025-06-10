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
