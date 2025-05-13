package dd

//#include <string.h>
//#include "ip-intelligence-cxx.h"
import "C"
import (
	"fmt"
	"unsafe"
)

type StatusCode C.StatusCode

var (
	STATUS_SUCCESS      C.StatusCode = C.FIFTYONE_DEGREES_STATUS_SUCCESS
	INSUFFICIENT_MEMORY C.StatusCode = C.FIFTYONE_DEGREES_STATUS_INSUFFICIENT_MEMORY
	CORRUPT_DATA        C.StatusCode = C.FIFTYONE_DEGREES_STATUS_CORRUPT_DATA
	INCORRECT_VERSION   C.StatusCode = C.FIFTYONE_DEGREES_STATUS_INCORRECT_VERSION
	FILE_NOT_FOUND      C.StatusCode = C.FIFTYONE_DEGREES_STATUS_FILE_NOT_FOUND
	FILE_BUSY           C.StatusCode = C.FIFTYONE_DEGREES_STATUS_FILE_BUSY
	FILE_FAILURE        C.StatusCode = C.FIFTYONE_DEGREES_STATUS_FILE_FAILURE
	STATUS_NOT_SET      C.StatusCode = C.FIFTYONE_DEGREES_STATUS_NOT_SET
)

func IpiInitManagerFromFile(config ConfigIpi, rm ResourceManager, properties, dataFilePath string) C.StatusCode {
	var exception *C.Exception
	cStr := C.CString(dataFilePath)
	defer C.free(unsafe.Pointer(cStr))

	c := config.CPtr

	p := NewPropertiesRequired(properties)

	return C.IpiInitManagerFromFile(
		rm.CPtr,
		c,
		p.CPtr,
		cStr,
		exception,
	)
}

func ReportStatus(status C.StatusCode, fileName string) string {
	cStr := C.CString(fileName)
	defer C.free(unsafe.Pointer(cStr))

	msg := C.StatusGetMessage(status, cStr)

	//cMessage := C.StatusGetMessage(s, cPath)
	//defer C.MemoryStandardFree(unsafe.Pointer(cMessage))
	//return fmt.Errorf(C.GoString(cMessage))
	//
	//_ = msg

	return fmt.Sprintf("%v", msg)
}
