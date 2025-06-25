# 51Degrees Ip Intelligence API

![51Degrees](https://51degrees.com/img/logo.png?utm_source=github&utm_medium=repository&utm_campaign=c_open_source&utm_content=readme_main "Data rewards the curious")
**Examples for IP Intelligence in GO**

## Introduction

This repository contains examples of how to use the module [ip-intelligence-go](https://github.com/51degrees/ip-intelligence-go)

## Pre-requisites

To run these examples you will need a data file and example evidence for some tests. To fetch these assets please run:

```
pwsh ci/fetch-assets.ps1 .
```

or alternatively you can download them from [ip-intelligence-data](https://github.com/51Degrees/ip-intelligence-data)
repo (the links are below) and put in the root of this repository.

### TODO: REPLACE THE FILE PATH TO THI IPI LITE FILE

- [51Degrees-LiteV41.ipi](https://github.com/51Degrees/ip-intelligence-data)
- [20000 Evidence Records.yml](https://github.com/51Degrees/ip-intelligence-data/blob/main/evidence.yml)

### Software

To use ip-intelligence-examples-go the following are required:

- A C compiler that support C11 or above (Gcc on Linux, Clang on MacOS and MinGW-x64 on Windows)
- libatomic - which usually come with default Gcc, Clang installation

### Windows

If you are on Windows, make sure that:

- The path to the `MinGW-x64` `bin` folder is included in the `PATH`. By default, the path should be
  `C:\msys64\ucrt64\bin`
- Go environment variable `CGO_ENABLED` is set to `1`

```
go env -w CGO_ENABLED=1
```

## Examples

**NOTE**: `ip-intelligence-examples-go` references `ip-intelligence-go` as a dependency in `go.mod`. No additional
actions should be required - the module will be downloaded and built when you do `go run`, `go test`, or `go build`
explicitly for any example.

- All examples under `ipi_onpremise` directory are console program examples and are run using `go run`.

Below is a table that describes the examples:

| Example                                                          | Description                                                                                                                               |
|------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------|
| ipi_onpremise/getting_started/getting_sarted.go                  | An example showing how to initialize the engine, what minimum parameters are required to start, how to call the engine and get the result |
| ipi_onpremise/offline_processing/offline_processing.go           | Example showing how to get values from the engine in value-weight format; writing the obtained values to a yaml file                      |
| ipi_onpremise/performance/performance.go                         | An example showing the speed of data processing in multi-threaded mode                                                                    |
| ipi_onpremise/reload_from_file/reload_from_file.go               | An example that demonstrates how a data file can be reloaded while serving IP Intelligence requests.                                      |
| ipi_onpremise/update_polling_interval/update_polling_interval.go | A demo of a higher level ipi_onpremise Engine API to do P Intelligenc and do automatic polling for the data file update                   |

## Run examples

- Navigate to `ipi_onpremise` folder. All examples here are testable and can be run as:
```
go run [example_dir/example_name].go
```
- ipi_onpremise examples are assumed to be run from the root directory:
```
go run onpremise/update_polling_interval/update_polling_interval.go
```
For further details of how to run each example, please read more in the comment section located at the top of each example file.
