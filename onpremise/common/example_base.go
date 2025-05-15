package common

import "os"

type ExampleParams struct {
	LicenseKey string
	Product    string
	DataFile   string
}

type ExampleFunc func(params ExampleParams) error

func RunExample(exampleFunc ExampleFunc) {
	licenseKey := os.Getenv("LICENSE_KEY")
	if licenseKey == "" {
		licenseKey = os.Getenv("DEVICE_DETECTION_KEY")
	}

	dataFile := os.Getenv("DATA_FILE")
	if dataFile == "" {
		dataFile = "51Degrees-LiteV41.ipi"
	}

	params := ExampleParams{
		LicenseKey: licenseKey,
		DataFile:   dataFile,
	}

	err := exampleFunc(params)
	if err != nil {
		panic(err)
	}
}

type TestIpi struct {
	IpAddress        string
	Expected         string
	IsWorkingExample bool // This parameter indicates whether the error received is expected or not.
}
