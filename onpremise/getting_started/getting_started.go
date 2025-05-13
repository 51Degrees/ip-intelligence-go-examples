package main

import (
	"fmt"
	"log"

	"github.com/51Degrees/ip-intelligence-examples-go/ip-intelligence-go/dd"
	"github.com/51Degrees/ip-intelligence-examples-go/ip-intelligence-go/onpremise"
	"github.com/51Degrees/ip-intelligence-examples-go/onpremise/common"
)

func runGettingStarted(engine *onpremise.Engine, config *dd.ConfigIpi) {
	var ipv4Address = "185.28.167.77"
	var ipv6Address = "fdaa:bbcc:ddee:0:995f:d63a:f2a1:f189"

	fmt.Println("Starting Getting Started Example")

	fmt.Println("\nIpv4 Address: %s\n", ipv4Address)
	fmt.Println("\nIpv6 Address: %s\n", ipv6Address)

	// var properties = "IpRangeStart,IpRangeEnd,AccuracyRadius,RegisteredCountry,RegisteredName,Longitude,Latitude,Areas"
	// _ = properties

	// //rm := dd.NewResourceManager()

	// // Setup a resource manager
	// manager := dd.NewResourceManager()
	// // Free manager
	// defer manager.Free()

	// filePath := "/Users/marinalee/Documents/WORK/Postindustria/51Degrees/ip-intelligence-cxx/ip-intelligence-data/51Degrees-EnterpriseIpiV41.ipi"

	// if err := dd.InitManagerFromFile(manager, *config, properties, filePath); err != nil {
	// 	fmt.Printf("failed to init manager from file: %w", err)
	// }
	//
	//err := dd.InitManagerFromFile(engine.manager, *e.config, e.managerProperties, filePath)
	//
	//if status != dd.STATUS_SUCCESS {
	//	res := dd.ReportStatus(status, filePath)
	//	fmt.Printf("%s\n", res)
	//}
}

func main() {
	common.RunExample(
		func(params common.ExampleParams) error {
			//... Example code
			//Create config
			config := dd.NewConfigIpi(dd.Default)

			//Create on-premise engine
			engine, err := onpremise.New(
				// Optimized config provided
				onpremise.WithConfigIpi(config),
				// Path to your data file
				onpremise.WithDataFile(params.DataFile),
				// Enable automatic updates.
				onpremise.WithAutoUpdate(false),
			)
			if err != nil {
				log.Fatalf("Failed to create engine: %v", err)
			}

			// Run example
			runGettingStarted(engine, config)

			engine.Stop()

			return nil
		})
}
