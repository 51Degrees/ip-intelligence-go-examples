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
@example examples/onpremise/update_polling_interval.go
Update polling interval example of using 51Degrees IP intelligence.

This example shows how to use 51Degrees on-premise IP intelligence to
process IP address before and after IPI file will be updated.

This example is available in full on [GitHub](https://github.com/51Degrees/ip-intelligence-go-examples/tree/main/ipi_onpremise/update_polling_interval).

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

	//Create on-premise engine
	engine, err := ipi_onpremise.New(
		// Optimized config provided
		ipi_onpremise.WithConfigIpi(config),
		// Path to your data file
		ipi_onpremise.WithDataFile(params.DataFile),

		// WithLicenseKey sets the license key to use when pulling the data file
		// A license key can be obtained with a subscription from https://51degrees.com/pricing
		ipi_onpremise.WithLicenseKey(params.LicenseKey),

		// WithAutoUpdate enables or disables auto update
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

```
*/
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

	if value, weight, found := result.GetValueWeightByProperty("IpRangeStart"); !found {
		log.Printf("Not found values for the next property %s for address %s", "IpRangeStart", ipAddress)
	} else {
		log.Printf("IpRangeStart: %+v:%.2f\n", value, weight)
	}

	if value, weight, found := result.GetValueWeightByProperty("IpRangeEnd"); !found {
		log.Printf("Not found values for the next property %s for address %s", "IpRangeEnd", ipAddress)
	} else {
		log.Printf("IpRangeEnd: %+v:%.2f\n", value, weight)
	}

	if value, weight, found := result.GetValueWeightByProperty("AccuracyRadius"); !found {
		log.Printf("Not found values for the next property %s for address %s", "AccuracyRadius", ipAddress)
	} else {
		log.Printf("AccuracyRadius: %+v:%.2f\n", value, weight)
	}

	if value, weight, found := result.GetValueWeightByProperty("RegisteredCountry"); !found {
		log.Printf("Not found values for the next property %s for address %s", "RegisteredCountry", ipAddress)
	} else {
		log.Printf("AccuracyRadius: %+v:%.2f\n", value, weight)
	}

	if value, weight, found := result.GetValueWeightByProperty("RegisteredName"); !found {
		log.Printf("Not found values for the next property %s for address %s", "RegisteredName", ipAddress)
	} else {
		log.Printf("RegisteredName: %+v:%.2f\n", value, weight)
	}

	if value, weight, found := result.GetValueWeightByProperty("Longitude"); !found {
		log.Printf("Not found values for the next property %s for address %s", "Longitude", ipAddress)
	} else {
		log.Printf("Longitude: %+v:%.2f\n", value, weight)
	}

	if value, weight, found := result.GetValueWeightByProperty("Latitude"); !found {
		log.Printf("Not found values for the next property %s for address %s", "Latitude", ipAddress)
	} else {
		log.Printf("Latitude: %+v:%.2f\n", value, weight)
	}

	if value, weight, found := result.GetValueWeightByProperty("Areas"); !found {
		log.Printf("Not found values for the next property %s for address %s", "Areas", ipAddress)
	} else {
		log.Printf("Areas: %+v:%.2f\n", value, weight)
	}

	if value, weight, found := result.GetValueWeightByProperty("Mcc"); !found {
		log.Printf("Not found values for the next property %s for address %s", "Mcc", ipAddress)
	} else {
		log.Printf("Mcc: %+v:%.2f\n", value, weight)
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

			//process after file has been updated
			processEvidence(engine, evidences[2])
			processEvidence(engine, evidences[3])

			return nil
		})
}
