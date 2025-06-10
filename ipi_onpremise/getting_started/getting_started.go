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
res, err := ipi_interop.GetPropertyValueAsRaw(result.CPtr, property)

```

Expected output:
```
...
2025/06/10 09:45:06 Expected result for 185.28.167.77:
Expected & Actual:
IpRangeStart: "185.28.167.0":1
IpRangeEnd: "185.28.167.127":1
AccuracyRadius: "485920":1
RegisteredCountry: "GB":1
RegisteredName: "CUSTOMERS-Subnet9":1
Longitude: "80.339976195562613":1
Latitude: "25.502792443617054":1
Areas: "POLYGON((83.026215399639881 23.725699636829738,82.993255409405805 23.717459639271219,82.954802087466049 23.714712973418379,82.916348765526294 23.717459639271219,78.444776757103185 24.338206122013002,78.40083010345775 24.349192785424361,78.356883449812315 24.368419446394238,78.31843012787256 24.395886104922635,78.290963469344163 24.431592761009551,78.268990142521446 24.47004608294931,78.208563493758959 24.621112704855495,78.20307016205328 24.637592699972533,77.005523850215155 28.579058198797572,76.994537186803797 28.617511520737327,76.994537186803797 28.655964842677083,77.005523850215155 28.691671498764002,77.027497177037873 28.727378154850918,77.04947050386059 28.760338145084994,77.082430494094666 28.785058137760551,77.120883816034421 28.807031464583268,77.164830469679856 28.82076479384747,77.203283791619612 28.826258125553149,77.25272377697074 28.826258125553149,80.191656239509257 28.474684896389661,80.208136234626295 28.471938230536821,81.630909146397286 28.194524979400008,81.647389141514324 28.189031647694328,83.756828516495261 27.60948515274514,83.789788506729337 27.598498489333782,83.822748496963413 27.582018494216744,83.932615131077 27.513351847895748,83.960081789605397 27.491378521073031,83.982055116428114 27.469405194250314,84.487441633350628 26.859645374919889,84.509414960173345 26.829432050538653,84.558854945524459 26.73879207739494,84.575334940641497 26.697592089602345,84.828028199102761 25.788445692312386,84.83352153080844 25.744499038666952,84.83352153080844 25.703299050874357,84.817041535691402 25.662099063081758,84.795068208868685 25.623645741142003,83.756828516495261 24.272286141544846,83.72936185796685 24.247566148869289,83.542588579973753 24.069032868434707,83.526108584856715 24.055299539170505,83.218482009338658 23.805352946562088,83.185522019104582 23.783379619739371,83.147068697164826 23.766899624622333,83.026215399639881 23.725699636829738,83.026215399639881 23.725699636829738))":1

2025/06/10 09:45:06 Expected result for fdaa:bbcc:ddee:0:995f:d63a:f2a1:f189:
Expected & Actual:
IpRangeStart: "fc00:0000:0000:0000:0000:0000:0000:0000":1
IpRangeEnd: "fdff:ffff:ffff:ffff:ffff:ffff:ffff:ffff":1
AccuracyRadius: "-1":1
RegisteredCountry: "Unknown":1
RegisteredName: "IANA-V6-ULA":1
Longitude: "0":1
Latitude: "0.00274666585284":1
Areas: "POLYGON EMPTY":1

2025/06/10 09:45:06 Not expected result for 127.0.0.1:
Expected:

Actual:
IpRangeStart: "127.0.0.0":1
IpRangeEnd: "127.255.255.255":1
AccuracyRadius: "135802":1
RegisteredCountry: "Unknown":1
RegisteredName: "SPECIAL-IPV4-LOOPBACK-IANA-RESERVED":1
Longitude: "-75.016937772759178":1
Latitude: "40.071108127079071":1
Areas: "POLYGON((-75.110324411755727 39.659108249153114,-75.154271065401161 39.656361583300274,-75.203711050752275 39.664601580858793,-75.291604358043159 39.683828241828671,-75.335551011688594 39.697561571092869,-75.384990997039708 39.716788232062747,-75.417950987273784 39.736014893032625,-75.45091097750786 39.757988219855342,-75.472884304330577 39.785454878383739,-75.494857631153295 39.815668202764975,-75.53331095309305 39.903561510055852,-75.544297616504409 39.939268166142767,-75.544297616504409 39.974974822229683,-75.53331095309305 40.065614795373392,-75.522324289681691 40.101321451460308,-75.505844294564653 40.134281441694391,-75.478377636036257 40.164494766075627,-74.994964445936461 40.573747978148745,-74.967497787408064 40.592974639118623,-74.940031128879667 40.609454634235661,-74.127018036439097 40.947294534134954,-74.088564714499341 40.961027863399153,-74.044618060853907 40.969267860957672,-73.995178075502793 40.969267860957672,-73.951231421857358 40.961027863399153,-73.912778099917603 40.947294534134954,-73.874324777977847 40.928067873165077,-73.841364787743771 40.90334788048952,-73.819391460921054 40.873134556108276,-73.802911465804016 40.84292123172704,-73.76995147556994 40.752281258583331,-73.76445814386426 40.719321268349255,-73.76995147556994 40.689107943968018,-73.775444807275619 40.656147953733942,-73.808404797509695 40.587481307412943,-73.813898129215374 40.568254646443066,-73.907284768211923 40.419934690389724,-73.940244758445999 40.381481368449968,-74.286324655903812 40.060121463667713,-74.324777977843567 40.032654805139316,-74.863124485000156 39.722281563768426,-74.896084475234233 39.705801568651388,-74.945524460585347 39.686574907681511,-74.978484450819423 39.675588244270152,-75.016937772759178 39.670094912564473,-75.110324411755727 39.659108249153114,-75.110324411755727 39.659108249153114))":1
```
*/
package main

import "C"
import (
	"bytes"
	"fmt"
	"github.com/51Degrees/ip-intelligence-examples-go/ipi_onpremise/common"
	"github.com/51Degrees/ip-intelligence-go/ipi_interop"
	"github.com/51Degrees/ip-intelligence-go/ipi_onpremise"
	"log"
)

var gettingStartedTests = []*common.TestIpi{
	{
		IpAddress: "185.28.167.77",
		Expected: `IpRangeStart: "185.28.167.0":1
IpRangeEnd: "185.28.167.127":1
AccuracyRadius: "485920":1
RegisteredCountry: "GB":1
RegisteredName: "CUSTOMERS-Subnet9":1
Longitude: "80.339976195562613":1
Latitude: "25.502792443617054":1
Areas: "POLYGON((83.026215399639881 23.725699636829738,82.993255409405805 23.717459639271219,82.954802087466049 23.714712973418379,82.916348765526294 23.717459639271219,78.444776757103185 24.338206122013002,78.40083010345775 24.349192785424361,78.356883449812315 24.368419446394238,78.31843012787256 24.395886104922635,78.290963469344163 24.431592761009551,78.268990142521446 24.47004608294931,78.208563493758959 24.621112704855495,78.20307016205328 24.637592699972533,77.005523850215155 28.579058198797572,76.994537186803797 28.617511520737327,76.994537186803797 28.655964842677083,77.005523850215155 28.691671498764002,77.027497177037873 28.727378154850918,77.04947050386059 28.760338145084994,77.082430494094666 28.785058137760551,77.120883816034421 28.807031464583268,77.164830469679856 28.82076479384747,77.203283791619612 28.826258125553149,77.25272377697074 28.826258125553149,80.191656239509257 28.474684896389661,80.208136234626295 28.471938230536821,81.630909146397286 28.194524979400008,81.647389141514324 28.189031647694328,83.756828516495261 27.60948515274514,83.789788506729337 27.598498489333782,83.822748496963413 27.582018494216744,83.932615131077 27.513351847895748,83.960081789605397 27.491378521073031,83.982055116428114 27.469405194250314,84.487441633350628 26.859645374919889,84.509414960173345 26.829432050538653,84.558854945524459 26.73879207739494,84.575334940641497 26.697592089602345,84.828028199102761 25.788445692312386,84.83352153080844 25.744499038666952,84.83352153080844 25.703299050874357,84.817041535691402 25.662099063081758,84.795068208868685 25.623645741142003,83.756828516495261 24.272286141544846,83.72936185796685 24.247566148869289,83.542588579973753 24.069032868434707,83.526108584856715 24.055299539170505,83.218482009338658 23.805352946562088,83.185522019104582 23.783379619739371,83.147068697164826 23.766899624622333,83.026215399639881 23.725699636829738,83.026215399639881 23.725699636829738))":1
`,
		IsWorkingExample: true,
	},
	{
		IpAddress: "fdaa:bbcc:ddee:0:995f:d63a:f2a1:f189",
		Expected: `IpRangeStart: "fc00:0000:0000:0000:0000:0000:0000:0000":1
IpRangeEnd: "fdff:ffff:ffff:ffff:ffff:ffff:ffff:ffff":1
AccuracyRadius: "-1":1
RegisteredCountry: "Unknown":1
RegisteredName: "IANA-V6-ULA":1
Longitude: "0":1
Latitude: "0.00274666585284":1
Areas: "POLYGON EMPTY":1
`,
	},
	{
		IpAddress:        "127.0.0.1",
		Expected:         ``,
		IsWorkingExample: false,
	},
}

func testIpi(engine *ipi_onpremise.Engine, ipiItem *common.TestIpi) {
	result, err := engine.Process(ipiItem.IpAddress)
	if err != nil {
		log.Printf("Error processing Getting Started Example: %v", err)
		return
	}
	defer result.Free()

	if result.HasValues() {
		var actual bytes.Buffer
		for _, property := range common.Properties {
			res, err := ipi_interop.GetPropertyValueAsRaw(result.CPtr, property)
			if err != nil {
				log.Printf("Error processing property %s with error: %v", property, err)
				return
			}

			actual.WriteString(fmt.Sprintf("%s: %s\n", property, res))
		}

		if actual.String() == ipiItem.Expected {
			log.Printf("Expected result for %s:\nExpected & Actual:\n%s\n", ipiItem.IpAddress, actual.String())
			return
		}

		log.Printf("Not expected result for %s:\nExpected:\n%s\nActual:\n%s\n", ipiItem.IpAddress, ipiItem.Expected, actual.String())
		return
	}

	fmt.Printf("Not found result for ipi: %s\n", ipiItem.IpAddress)
}

func runGettingStarted(engine *ipi_onpremise.Engine) {
	for _, test := range gettingStartedTests {
		testIpi(engine, test)
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
			runGettingStarted(engine)

			engine.Stop()

			return nil
		})
}
