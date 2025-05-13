package common

import "os"

type ExampleParams struct {
	LicenseKey   string
	Product      string
	DataFile     string
	EvidenceYaml string // TODO: ?
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

	//evidenceYaml := os.Getenv("EVIDENCE_YAML")
	//if evidenceYaml == "" {
	//	evidenceYaml = "20000 Evidence Records.yml" // TODO: check if needed this
	//}

	params := ExampleParams{
		LicenseKey: licenseKey,
		DataFile:   dataFile,
		//EvidenceYaml: evidenceYaml,
	}

	err := exampleFunc(params)
	if err != nil {
		panic(err)
	}
}
