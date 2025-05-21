package main

import "C"
import (
	"bytes"
	"fmt"
	"github.com/51Degrees/ip-intelligence-examples-go/ipi_examples_interop"
	"github.com/51Degrees/ip-intelligence-examples-go/ipi_onpremise/common"
	"github.com/51Degrees/ip-intelligence-go/ipi_interop"
	"github.com/51Degrees/ip-intelligence-go/ipi_onpremise"
	"log"
)

var gettingStartedTests = []*ipi_examples_interop.TestIpi{
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

func testIpi(engine *ipi_onpremise.Engine, ipiItem *ipi_examples_interop.TestIpi) {
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
