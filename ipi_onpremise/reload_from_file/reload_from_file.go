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
@example examples/onpremise/reload_from_file.go
Reload from file example of using 51Degrees IP intelligence.

This example illustrates how to use a single reference to the resource manager
to use 51Degrees on-premise IP intelligence and invoke the reload functionality
instead of maintaining a reference to the dataset directly.

This example is available in full on [GitHub](https://github.com/51Degrees/ip-intelligence-go-examples/tree/main/ipi_onpremise/reload_from_file).

@include{doc} example-require-datafile-ipi.txt

@include{doc} example-how-to-run-ipi.txt

# In detail, the example shows how to

1. Specify config for engine:
This setting specifies the performance profile that will be used when initializing the C library.

```
config := ipi_interop.NewConfigIpi(ipi_interop.InMemory)
```

Set concurrency to available CPU size
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
	// File System Watcher is by default enabled
	ipi_onpremise.WithFileWatch(true),

)
```

WithConfigIpi allows to configure the Ipi matching algorithm.

```
ipi_onpremise.WithConfigIpi(config)
```

# WithDataFile sets the path to the local data file, this parameter is required to start the engine

```
ipi_onpremise.WithDataFile(params.DataFile),
```

# WithAutoUpdate enables or disables auto update

```
ipi_onpremise.WithAutoUpdate(false),
```

# WithFileWatch enables or disables file watching in case 3rd party updates the data file

```
ipi_onpremise.WithFileWatch(true),
```

Expected output:
```
...
2025/06/23 11:46:08 Reloaded '2' times.
2025/06/23 11:46:08 Failed to reload '0' times.
2025/06/23 11:46:08 Hashcode '850133199' for iteration '0'.
2025/06/23 11:46:08 Hashcode '850133199' for iteration '1'.
2025/06/23 11:46:08 Hashcode '850133199' for iteration '2'.
2025/06/23 11:46:08 Hashcode '850133199' for iteration '3'.
2025/06/23 11:46:08 Hashcode '850133199' for iteration '4'.
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

// executeTest runs a test by processing an IP address through the engine, updating the report, and marking the work as done.
func executeTest(engine *ipi_onpremise.Engine, wg *sync.WaitGroup, report *common.Report, ipAddress string, iteration uint32) {
	res, err := engine.Process(ipAddress)
	if err != nil {
		log.Fatalln(err)
	}

	var actual bytes.Buffer
	for _, property := range common.Properties {
		value, weight, found := res.GetValueWeightByProperty(property)
		if !found {
			log.Printf("Not found values for the next property %s for address %s", property, ipAddress)
		}

		actual.WriteString(fmt.Sprintf("%s: %+v:%.2f\n", property, value, weight))
	}

	hash := common.GenerateHash(actual.String())
	report.UpdateHashCode(hash, iteration)

	// Increase the number of Evidence Records processed
	atomic.AddUint64(&report.EvidenceProcessed, 1)

	// Complete and mark as done
	defer wg.Done()
}

// performDetectionIterations executes multiple iterations of detection processing using the provided engine and parameters.
// It processes evidence records from a YAML file, performs detection in parallel goroutines, and updates the given report.
// Accepts an ipi_onpremise.Engine instance, a WaitGroup for synchronization, a Report for tracking results, and ExampleParams as input.
// The function manages the lifecycle of file resources and ensures completion of goroutines for concurrent processing.
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

// countEvidenceFromFile reads a YAML file containing evidence records, counts valid entries, and returns the total count.
// It takes an ExampleParams structure for configuration and returns the count of evidence records or an error on failure.
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

// runReloadFromFile handles the reload of evidence data from a file and runs multiple detection iterations using the engine.
// It tracks file reload attempts, processing failures, and ensures synchronization of concurrent operations using a WaitGroup.
// Constructs a detailed report, including hashing data, to validate the correctness of multiple processing iterations.
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

// main is the entry point of the program, managing configuration, initializing the engine, and executing processing logic.
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
