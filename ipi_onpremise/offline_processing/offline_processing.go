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
value, weight, err := ipi_interop.GetPropertyValueAsStringWeightValue(result.CPtr, property)

```

Expected output (20000_ipi_evidence_records.processed.yml):
```
...
---
ip-range-start: 96.235.176.24 #Weight: 1.0
ip-range-end: 96.236.16.23 #Weight: 1.0
accuracy-radius: "135802" #Weight: 1.0
registered-country: Unknown #Weight: 1.0
registered-name: VIS-BLOCK #Weight: 1.0
longitude: "-75.016937772759178" #Weight: 1.0
latitude: "40.071108127079071" #Weight: 1.0
areas: POLYGON((-75.110324411755727 39.659108249153114,-75.154271065401161 39.656361583300274,-75.203711050752275 39.664601580858793,-75.291604358043159 39.683828241828671,-75.335551011688594 39.697561571092869,-75.384990997039708 39.716788232062747,-75.417950987273784 39.736014893032625,-75.45091097750786 39.757988219855342,-75.472884304330577 39.785454878383739,-75.494857631153295 39.815668202764975,-75.53331095309305 39.903561510055852,-75.544297616504409 39.939268166142767,-75.544297616504409 39.974974822229683,-75.53331095309305 40.065614795373392,-75.522324289681691 40.101321451460308,-75.505844294564653 40.134281441694391,-75.478377636036257 40.164494766075627,-74.994964445936461 40.573747978148745,-74.967497787408064 40.592974639118623,-74.940031128879667 40.609454634235661,-74.127018036439097 40.947294534134954,-74.088564714499341 40.961027863399153,-74.044618060853907 40.969267860957672,-73.995178075502793 40.969267860957672,-73.951231421857358 40.961027863399153,-73.912778099917603 40.947294534134954,-73.874324777977847 40.928067873165077,-73.841364787743771 40.90334788048952,-73.819391460921054 40.873134556108276,-73.802911465804016 40.84292123172704,-73.76995147556994 40.752281258583331,-73.76445814386426 40.719321268349255,-73.76995147556994 40.689107943968018,-73.775444807275619 40.656147953733942,-73.808404797509695 40.587481307412943,-73.813898129215374 40.568254646443066,-73.907284768211923 40.419934690389724,-73.940244758445999 40.381481368449968,-74.286324655903812 40.060121463667713,-74.324777977843567 40.032654805139316,-74.863124485000156 39.722281563768426,-74.896084475234233 39.705801568651388,-74.945524460585347 39.686574907681511,-74.978484450819423 39.675588244270152,-75.016937772759178 39.670094912564473,-75.110324411755727 39.659108249153114,-75.110324411755727 39.659108249153114)) #Weight: 1.0
---
```
*/

package main

import (
	"bufio"
	"fmt"
	"github.com/51Degrees/ip-intelligence-examples-go/ipi_onpremise/common"
	"github.com/51Degrees/ip-intelligence-go/ipi_interop"
	"github.com/51Degrees/ip-intelligence-go/ipi_onpremise"
	"github.com/goccy/go-yaml"
	"log"
	"os"
	"path/filepath"
	"strings"
)

type PropertiesData struct {
	IpRangeStart      string `yaml:"ip-range-start"`
	IpRangeEnd        string `yaml:"ip-range-end"`
	AccuracyRadius    string `yaml:"accuracy-radius"`
	RegisteredCountry string `yaml:"registered-country"`
	RegisteredName    string `yaml:"registered-name"`
	Longitude         string `yaml:"longitude"`
	Latitude          string `yaml:"latitude"`
	Areas             string `yaml:"areas"`
}

func getIpi(engine *ipi_onpremise.Engine, IpAddress string) (*PropertiesData, yaml.CommentMap, error) {
	result, err := engine.Process(IpAddress)
	if err != nil {
		log.Printf("Error processing Getting Started Example: %v", err)
		return nil, nil, err
	}
	defer result.Free()

	data := &PropertiesData{}

	comments := yaml.CommentMap{}

	if result.HasValues() {
		for _, property := range common.Properties {
			value, weight, err := ipi_interop.GetPropertyValueAsStringWeightValue(result.CPtr, property)
			if err != nil {
				log.Printf("Error processing property %s for address %s with error: %v", property, IpAddress, err)
				continue
			}

			switch property {
			case "IpRangeStart":
				data.IpRangeStart = value
				comments["$.ip-range-start"] = []*yaml.Comment{
					yaml.LineComment(fmt.Sprintf("Weight: %.1f", weight)),
				}
			case "IpRangeEnd":
				data.IpRangeEnd = value
				comments["$.ip-range-end"] = []*yaml.Comment{
					yaml.LineComment(fmt.Sprintf("Weight: %.1f", weight)),
				}
			case "AccuracyRadius":
				data.AccuracyRadius = value
				comments["$.accuracy-radius"] = []*yaml.Comment{
					yaml.LineComment(fmt.Sprintf("Weight: %.1f", weight)),
				}
			case "RegisteredCountry":
				data.RegisteredCountry = value
				comments["$.registered-country"] = []*yaml.Comment{
					yaml.LineComment(fmt.Sprintf("Weight: %.1f", weight)),
				}
			case "RegisteredName":
				data.RegisteredName = value
				comments["$.registered-name"] = []*yaml.Comment{
					yaml.LineComment(fmt.Sprintf("Weight: %.1f", weight)),
				}
			case "Longitude":
				data.Longitude = value
				comments["$.longitude"] = []*yaml.Comment{
					yaml.LineComment(fmt.Sprintf("Weight: %.1f", weight)),
				}
			case "Latitude":
				data.Latitude = value
				comments["$.latitude"] = []*yaml.Comment{
					yaml.LineComment(fmt.Sprintf("Weight: %.1f", weight)),
				}
			case "Areas":
				data.Areas = value
				comments["$.areas"] = []*yaml.Comment{
					yaml.LineComment(fmt.Sprintf("Weight: %.1f", weight)),
				}
			}
		}
	}

	return data, comments, nil
}

func runOfflineProcessing(engine *ipi_onpremise.Engine, params *common.ExampleParams) {
	evidenceFilePath := common.GetFilePathByPath(params.EvidenceYaml)
	evDir := filepath.Dir(evidenceFilePath)
	evBase := strings.TrimSuffix(filepath.Base(evidenceFilePath), filepath.Ext(evidenceFilePath))
	outputFilePath := fmt.Sprintf("%s/%s.processed.yml", evDir, evBase)

	outFile, err := os.Create(outputFilePath)
	if err != nil {
		log.Fatalf("Failed to create file %s.\n", outputFilePath)
	}
	defer func() {
		if err := outFile.Close(); err != nil {
			log.Fatalf("Failed to close file \"%s\".\n", outputFilePath)
		}
	}()

	// Open the Evidence Records file for processing
	file, err := os.OpenFile(evidenceFilePath, os.O_RDONLY, 0444)
	if err != nil {
		log.Fatalf("Failed to open file \"%s\".\n", evidenceFilePath)
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

		// if the line is empty - skip this line
		if doc == nil {
			continue
		}

		if _, err = outFile.WriteString("---\n"); err != nil {
			log.Printf("Failed to write end for file \"%s\". %v\n", outputFilePath, err)
			continue
		}

		// process client-ip from the file
		data, comments, err := getIpi(engine, doc["server.client-ip"])
		if err != nil {
			log.Printf("Failed to get Ipi for line \"%s\".\n", line)
			continue
		}

		// marshal data to yaml
		dataYml, err := yaml.MarshalWithOptions(data, yaml.WithComment(comments))
		if err != nil {
			log.Printf("Failed to marshal Ipi for line \"%s\".\n", line)
			continue
		}

		if _, err = outFile.Write(dataYml); err != nil {
			log.Printf("Failed to write to file \"%s\".\n", outputFilePath)
			continue
		}
	}

	if _, err = outFile.WriteString("...\n"); err != nil {
		log.Printf("Failed to write end for file \"%s\". %v\n", outputFilePath, err)
	}

	// Check for errors during the scan
	if err := scanner.Err(); err != nil {
		log.Fatalf("Error reading file: %s", err)
	}
}

func main() {
	common.RunExample(
		func(params *common.ExampleParams) error {
			//Create config
			config := ipi_interop.NewConfigIpi(ipi_interop.InMemory)

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
			runOfflineProcessing(engine, params)

			engine.Stop()

			return nil
		})
}
