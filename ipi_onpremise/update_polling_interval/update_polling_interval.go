package main

import (
	"github.com/51Degrees/ip-intelligence-examples-go/ipi_onpremise/common"
	"github.com/51Degrees/ip-intelligence-go/ipi_interop"
	"github.com/51Degrees/ip-intelligence-go/ipi_onpremise"
	"log"
	"time"
)

func processEvidence(engine *ipi_onpremise.Engine, ipAddress string) {
	result, err := engine.Process(ipAddress)
	if err != nil {
		log.Printf("Error processing Getting Started Example: %v", err)
		return
	}
	defer result.Free()

	if ipRangeStart, err := ipi_interop.GetPropertyValueAsRaw(result.CPtr, "IpRangeStart"); err != nil {
		log.Printf("Error processing property \"IpRangeStart\" with error: %v\n", err)
		return
	} else {
		log.Printf("IpRangeStart: %s\n", ipRangeStart)
	}

	if ipRangeEnd, err := ipi_interop.GetPropertyValueAsRaw(result.CPtr, "IpRangeEnd"); err != nil {
		log.Printf("Error processing property \"IpRangeEnd\" with error: %v\n", err)
		return
	} else {
		log.Printf("IpRangeEnd: %s\n", ipRangeEnd)
	}

	if accuracyRadius, err := ipi_interop.GetPropertyValueAsRaw(result.CPtr, "AccuracyRadius"); err != nil {
		log.Printf("Error processing property \"AccuracyRadius\" with error: %v\n", err)
		return
	} else {
		log.Printf("AccuracyRadius: %s\n", accuracyRadius)
	}

	if registeredCountry, err := ipi_interop.GetPropertyValueAsRaw(result.CPtr, "RegisteredCountry"); err != nil {
		log.Printf("Error processing property \"RegisteredCountry\" with error: %v\n", err)
		return
	} else {
		log.Printf("RegisteredCountry: %s\n", registeredCountry)
	}

	if registeredName, err := ipi_interop.GetPropertyValueAsRaw(result.CPtr, "RegisteredName"); err != nil {
		log.Printf("Error processing property \"RegisteredName\" with error: %v\n", err)
		return
	} else {
		log.Printf("RegisteredName: %s\n", registeredName)
	}

	if longitude, err := ipi_interop.GetPropertyValueAsRaw(result.CPtr, "Longitude"); err != nil {
		log.Printf("Error processing property \"Longitude\" with error: %v\n", err)
		return
	} else {
		log.Printf("Longitude: %s\n", longitude)
	}

	if latitude, err := ipi_interop.GetPropertyValueAsRaw(result.CPtr, "Latitude"); err != nil {
		log.Printf("Error processing property \"Latitude\" with error: %v\n", err)
		return
	} else {
		log.Printf("Latitude: %s\n", latitude)
	}

	if areas, err := ipi_interop.GetPropertyValueAsRaw(result.CPtr, "Areas"); err != nil {
		log.Printf("Error processing property \"Areas\" with error: %v\n", err)
		return
	} else {
		log.Printf("Areas: %s\n", areas)
	}
}

var evidences = common.IpEvidences{
	"185.28.167.77",
	"fdaa:bbcc:ddee:0:995f:d63a:f2a1:f189",
	"145.23.184.233",
	"e58e:9ea7:1049:5a42:503d:c45c:f55a:0bd3",
}

func main() {
	common.RunExample(
		func(params *common.ExampleParams) error {
			config := ipi_interop.NewConfigIpi(ipi_interop.InMemory)

			//Create on-premise engine
			engine, err := ipi_onpremise.New(
				// Optimized config provided
				ipi_onpremise.WithConfigIpi(config),
				// Path to your data file
				ipi_onpremise.WithDataFile(params.DataFile),

				// For automatic updates to work you will need to provide a license key.
				// A license key can be obtained with a subscription from https://51degrees.com/pricing
				ipi_onpremise.WithLicenseKey(params.LicenseKey),

				// Enable automatic updates.
				ipi_onpremise.WithAutoUpdate(true),

				// Set the frequency in minutes that the pipeline should
				// check for updates to data files. A recommended
				// polling interval in a production environment is
				// around 30 minutes.
				ipi_onpremise.WithPollingInterval(3),

				// Set the max amount of time in seconds that should be
				// added to the polling interval. This is useful in datacenter
				// applications where multiple instances may be polling for
				// updates at the same time. A recommended amount in production
				// environments is 600 seconds.
				ipi_onpremise.WithRandomization(1),

				// Enable update on startup, the auto update system
				// will be used to check for an update before the
				// device detection engine is created.
				ipi_onpremise.WithUpdateOnStart(false),

				// Optionally provide your own file URL
				ipi_onpremise.WithDataUpdateUrl("<custom URL>"),

				// By default a temp copy should be created, unless you are using InMemory performance profile
				// ipi_onpremise.WithTempDataCopy(false),

				// File System Watcher is by default enabled
				// ipi_onpremise.WithFileWatch(false),

				// By default logging is on
				// ipi_onpremise.WithLogging(false),

				// Custom logger implementing LogWriter interface can be passed
				// ipi_onpremise.WithCustomLogger()

				// Set properties for checking, default is [] = all properties
				// ipi_onpremise.WithProperties([]string{}),
			)
			if err != nil {
				log.Fatalf("Failed to create engine: %v", err)
			}

			defer engine.Stop()

			//process before file has been updated
			processEvidence(engine, evidences[0])
			processEvidence(engine, evidences[1])

			<-time.After(30 * time.Second)

			//process before file has been updated
			processEvidence(engine, evidences[2])
			processEvidence(engine, evidences[3])

			return nil
		})
}
