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
ipi_onpremise.WithLicenseKey(params.LicenseKey),
```
TODO: add description

```
ipi_onpremise.WithAutoUpdate(true),
```
TODO: add description

```
ipi_onpremise.WithPollingInterval(3),
```
TODO: add description

```
ipi_onpremise.WithRandomization(1),
```
TODO: add description

```
ipi_onpremise.WithUpdateOnStart(false),
```
TODO: add description

```
ipi_onpremise.WithDataUpdateUrl("<custom URL>"),
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
TODO: add description
```
ipRangeStart, err := ipi_interop.GetPropertyValueAsRaw(result.CPtr, "IpRangeStart")

```
TODO: add description
```
ipRangeEnd, err := ipi_interop.GetPropertyValueAsRaw(result.CPtr, "IpRangeEnd")

```
TODO: add description
```
accuracyRadius, err := ipi_interop.GetPropertyValueAsRaw(result.CPtr, "AccuracyRadius")

```
TODO: add description
```
registeredCountry, err := ipi_interop.GetPropertyValueAsRaw(result.CPtr, "RegisteredCountry")

```
TODO: add description
```
registeredName, err := ipi_interop.GetPropertyValueAsRaw(result.CPtr, "RegisteredName")

```
TODO: add description
```
longitude, err := ipi_interop.GetPropertyValueAsRaw(result.CPtr, "Longitude")

```
TODO: add description
```
latitude, err := ipi_interop.GetPropertyValueAsRaw(result.CPtr, "Latitude")

```
TODO: add description
```
areas, err := ipi_interop.GetPropertyValueAsRaw(result.CPtr, "Areas")

```

Expected output (performance_report.log):
```
...
2025/06/10 10:16:40 IpRangeStart: "185.28.167.0":1
2025/06/10 10:16:40 IpRangeEnd: "185.28.167.127":1
2025/06/10 10:16:40 AccuracyRadius: "485920":1
2025/06/10 10:16:40 RegisteredCountry: "GB":1
2025/06/10 10:16:40 RegisteredName: "CUSTOMERS-Subnet9":1
2025/06/10 10:16:40 Longitude: "80.339976195562613":1
2025/06/10 10:16:40 Latitude: "25.502792443617054":1
2025/06/10 10:16:40 Areas: "POLYGON((83.026215399639881 23.725699636829738,82.993255409405805 23.717459639271219,82.954802087466049 23.714712973418379,82.916348765526294 23.717459639271219,78.444776757103185 24.338206122013002,78.40083010345775 24.349192785424361,78.356883449812315 24.368419446394238,78.31843012787256 24.395886104922635,78.290963469344163 24.431592761009551,78.268990142521446 24.47004608294931,78.208563493758959 24.621112704855495,78.20307016205328 24.637592699972533,77.005523850215155 28.579058198797572,76.994537186803797 28.617511520737327,76.994537186803797 28.655964842677083,77.005523850215155 28.691671498764002,77.027497177037873 28.727378154850918,77.04947050386059 28.760338145084994,77.082430494094666 28.785058137760551,77.120883816034421 28.807031464583268,77.164830469679856 28.82076479384747,77.203283791619612 28.826258125553149,77.25272377697074 28.826258125553149,80.191656239509257 28.474684896389661,80.208136234626295 28.471938230536821,81.630909146397286 28.194524979400008,81.647389141514324 28.189031647694328,83.756828516495261 27.60948515274514,83.789788506729337 27.598498489333782,83.822748496963413 27.582018494216744,83.932615131077 27.513351847895748,83.960081789605397 27.491378521073031,83.982055116428114 27.469405194250314,84.487441633350628 26.859645374919889,84.509414960173345 26.829432050538653,84.558854945524459 26.73879207739494,84.575334940641497 26.697592089602345,84.828028199102761 25.788445692312386,84.83352153080844 25.744499038666952,84.83352153080844 25.703299050874357,84.817041535691402 25.662099063081758,84.795068208868685 25.623645741142003,83.756828516495261 24.272286141544846,83.72936185796685 24.247566148869289,83.542588579973753 24.069032868434707,83.526108584856715 24.055299539170505,83.218482009338658 23.805352946562088,83.185522019104582 23.783379619739371,83.147068697164826 23.766899624622333,83.026215399639881 23.725699636829738,83.026215399639881 23.725699636829738))":1
2025/06/10 10:16:40 IpRangeStart: "fc00:0000:0000:0000:0000:0000:0000:0000":1
2025/06/10 10:16:40 IpRangeEnd: "fdff:ffff:ffff:ffff:ffff:ffff:ffff:ffff":1
2025/06/10 10:16:40 AccuracyRadius: "-1":1
2025/06/10 10:16:40 RegisteredCountry: "Unknown":1
2025/06/10 10:16:40 RegisteredName: "IANA-V6-ULA":1
2025/06/10 10:16:40 Longitude: "0":1
2025/06/10 10:16:40 Latitude: "0.00274666585284":1
2025/06/10 10:16:40 Areas: "POLYGON EMPTY":1
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

	if value, weight, found := result.GetValueWeightByProperty("MCC"); !found {
		log.Printf("Not found values for the next property %s for address %s", "MCC", ipAddress)
	} else {
		log.Printf("MCC: %+v:%.2f\n", value, weight)
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
