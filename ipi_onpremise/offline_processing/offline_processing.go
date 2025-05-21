package main

import (
	"bufio"
	"fmt"
	"github.com/51Degrees/ip-intelligence-examples-go/ipi_examples_interop"
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
	evidenceFilePath := ipi_examples_interop.GetFilePathByPath(params.EvidenceYaml)
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
