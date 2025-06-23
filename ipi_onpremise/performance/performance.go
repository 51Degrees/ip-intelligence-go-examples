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
@example examples/ipi_onpremise/performance/performance.go
The example illustrates a "clock-time" benchmark for assessing detection speed.

It's important to understand the trade-offs between performance, memory usage and accuracy, that
the 51Degrees pipeline configuration makes available, and this example shows a range of
different configurations to illustrate the difference in performance.

Requesting properties from a single component
reduces detection time compared with requesting properties from multiple components. If you
don't specify any properties to detect, then all properties are detected.

This example is available in full on [GitHub](https://github.com/51Degrees/ip-intelligence-go-examples/tree/main/ipi_onpremise/performance).

@include{doc} example-require-datafile-ipi.txt

@include{doc} example-how-to-run-ipi.txt

# In detail, the example shows how to


1. Specify config for engine:
This setting specifies the performance profile that will be used when initializing the C library.

```
config := ipi_interop.NewConfigIpi(ipi_interop.InMemory)
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
	// Set only 1 parameter for getting data
	ipi_onpremise.WithProperties([]string{"IpRangeStart"}),
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

# WithProperties configures an Engine with a comma-separated list of manager properties derived from the provided slice.te

```
ipi_onpremise.WithProperties([]string{"IpRangeStart"}),
```

3. Run evidence processing with parameters and get the report as returned value

```
report, err := runPerformance(engine, params)
```

Expected output (performance_report.log):
```
...
Average 0.00510 ms per Evidence Record
Average 196078.43 detections per second
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
	"runtime/debug"
	"sync"
	"sync/atomic"
	"time"
)

// reportFile defines the default path and filename for storing performance test results.
const reportFile = "performance_report.log"

// iterationCount defines the fixed number of iterations to be used for processing or performance testing loops.
const iterationCount = 5

// readYaml reads YAML data from a file, processes it line by line, and parses it into an IpEvidences collection.
// It takes ExampleParams as input, retrieves the file path, and reads evidence records from the specified YAML file.
// Returns IpEvidences containing the parsed data and an error if file operations or unmarshalling fail.
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

// processEvidenceBatch processes a batch of evidence IP addresses using the provided engine over multiple iterations.
// The function updates the evidence processing count in the report and logs errors or missing data as encountered.
func processEvidenceBatch(engine *ipi_onpremise.Engine, wg *sync.WaitGroup, evidenceBatch []string, report *common.Report, iterations int) {
	defer wg.Done()

	for iter := 0; iter < iterations; iter++ {
		for _, ipAddress := range evidenceBatch {
			atomic.AddUint64(&report.EvidenceProcessed, 1)

			result, err := engine.Process(ipAddress)
			if err != nil {
				log.Fatalln(err)
			}

			for _, property := range []string{"IpRangeStart"} {
				// don't use the property in the current step, only processing data
				if _, _, found := result.GetValueWeightByProperty(property); !found {
					log.Printf("Not found values for the next property %s for address %s", property, ipAddress)
				}
			}
		}
	}
}

// runPerformance executes a performance test by processing evidence data with the given engine and parameters.
// It disables garbage collection during execution, utilizes multiple workers for evidence processing, and logs performance.
// Returns a performance report and an error if the execution fails.
func runPerformance(engine *ipi_onpremise.Engine, params *common.ExampleParams) (*common.Report, error) {
	actReport := &common.Report{
		IterationCount: iterationCount,
	}

	// Getting evidences from the file (this can use GC)
	evidences, err := readYaml(params)
	if err != nil {
		log.Fatalf("Failed to read yaml files.\n")
		return nil, err
	}

	// set the count of evidences to our report
	actReport.EvidenceCount = evidences.Size()

	// Force garbage collection before the test
	log.Printf("Running GC before performance test...")
	runtime.GC()
	runtime.GC() // Run twice to ensure thorough cleanup

	// Disable garbage collection during performance test
	log.Printf("Disabling GC for performance test...")
	debug.SetGCPercent(-1)

	// Create evidence batches for each CPU core to process
	numWorkers := runtime.NumCPU()
	evidenceSlice := []string(evidences)
	batchSize := len(evidenceSlice) / numWorkers
	if batchSize == 0 {
		batchSize = 1
		numWorkers = len(evidenceSlice)
	}

	log.Printf("Using batch processing: %d workers, %d evidence per batch", numWorkers, batchSize)

	var wg sync.WaitGroup

	// Start timing after GC is disabled and batches are prepared
	startProcessTime := time.Now()

	// Launch worker goroutines, each processing a batch of evidence
	for i := 0; i < numWorkers; i++ {
		start := i * batchSize
		end := start + batchSize
		if i == numWorkers-1 {
			end = len(evidenceSlice) // Last worker takes any remaining items
		}

		if start < len(evidenceSlice) {
			batch := evidenceSlice[start:end]
			wg.Add(1)
			go processEvidenceBatch(engine, &wg, batch, actReport, actReport.IterationCount)
		}
	}

	wg.Wait()

	actReport.ProcessingTime = time.Since(startProcessTime).Milliseconds()

	// Re-enable garbage collection after test
	log.Printf("Re-enabling GC after performance test...")
	debug.SetGCPercent(100) // Default GC target percentage

	return actReport, nil
}

func main() {
	common.RunExample(
		func(params *common.ExampleParams) error {
			log.Printf("Starting IP Intelligence Performance Test (with GC control)")
			log.Printf("Using data file: %s", params.DataFile)

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
				// Set only 1 parameter for getting data
				ipi_onpremise.WithProperties([]string{"IpRangeStart"}),
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
