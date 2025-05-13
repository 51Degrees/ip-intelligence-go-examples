package dd

//#include <string.h>
//#include "ip-intelligence-cxx.h"
import "C"

// Performance Profile
type PerformanceProfile int

const (
	Default PerformanceProfile = iota
	LowMemory
	BalancedTemp
	Balanced
	HighPerformance
	InMemory
	SingleLoaded
)

// ConfigIpi wraps around pointer to a value of C ConfigIpi structure
type ConfigIpi struct {
	CPtr *C.ConfigIpi
	perf PerformanceProfile
}

/* Constructor and Destructor */

// NewConfigIpi creates a new ConfigIpi object. Target performance profile
// is required as initial setup and any following adjustments will be done
// on top of this initial performance profile. Any invalid input will result
// in default config to be used. In C the default performance profile is the
// same as balanced profile.
func NewConfigIpi(perf PerformanceProfile) *ConfigIpi {
	var config C.ConfigIpi
	profile := perf
	switch perf {
	case InMemory:
		config = C.IpiInMemoryConfig
	case HighPerformance:
		config = C.fiftyoneDegreesIpiHighPerformanceConfig
	case LowMemory:
		config = C.fiftyoneDegreesIpiLowMemoryConfig
	case Balanced:
		config = C.fiftyoneDegreesIpiBalancedConfig
	case BalancedTemp:
		config = C.fiftyoneDegreesIpiBalancedTempConfig
	case SingleLoaded:
		config = C.fiftyoneDegreesIpiSingleLoadedConfig
	default:
		config = C.fiftyoneDegreesIpiDefaultConfig
		profile = Default
	}
	return &ConfigIpi{&config, profile}
}

func cIntToBool(i int) bool {
	if i == 0 {
		return false
	} else {
		return true
	}
}

// UsePerformanceGraph returns whether performance optimized graph should be
// used.
func (config *ConfigIpi) UsePerformanceGraph() bool {
	//i := int(C.BoolToInt(config.CPtr.usePerformanceGraph))
	//return cIntToBool(i)
	return false
}

// UsePredictiveGraph returns whether predictive optmized graph should be
// used.
func (config *ConfigIpi) UsePredictiveGraph() bool {
	//i := int(C.BoolToInt(config.CPtr.usePredictiveGraph))
	//return cIntToBool(i)
	return false
}

// Concurrency returns the configured concurrency
func (config *ConfigIpi) Concurrency() uint16 {
	//minConcurrency := math.Min(
	//	float64(C.ushort(config.CPtr.strings.concurrency)),
	//	float64(C.ushort(config.CPtr.properties.concurrency)))
	//minConcurrency = math.Min(
	//	float64(C.ushort(config.CPtr.values.concurrency)),
	//	float64(minConcurrency))
	//minConcurrency = math.Min(
	//	float64(C.ushort(config.CPtr.profiles.concurrency)),
	//	minConcurrency)
	//minConcurrency = math.Min(
	//	float64(C.ushort(config.CPtr.nodes.concurrency)),
	//	minConcurrency)
	//minConcurrency = math.Min(
	//	float64(C.ushort(config.CPtr.profileOffsets.concurrency)),
	//	minConcurrency)
	//minConcurrency = math.Min(
	//	float64(C.ushort(config.CPtr.maps.concurrency)),
	//	minConcurrency)
	//minConcurrency = math.Min(
	//	float64(C.ushort(config.CPtr.components.concurrency)),
	//	minConcurrency)
	//return uint16(minConcurrency)
	return 1
}

// TraceRoute returns whether route through each graph should be traced.
func (config *ConfigIpi) TraceRoute() bool {
	//i := int(C.BoolToInt(config.CPtr.traceRoute))
	//return cIntToBool(i)
	return false
}

// UseUpperPrefixHeaders returns whether HTTP_ upper case prefixes should be
// considered when evaluating HTTP hreaders.
func (config *ConfigIpi) UseUpperPrefixHeaders() bool {
	//i := int(C.BoolToInt(config.CPtr.b.b.usesUpperPrefixedHeaders))
	//return cIntToBool(i)
	return false
}

// UpdateMatchedUserAgent returns whether tracking the matched
// User-Agent should be enabled
func (config *ConfigIpi) UpdateMatchedUserAgent() bool {
	//i := int(C.BoolToInt(config.CPtr.b.updateMatchedUserAgent))
	//return cIntToBool(i)
	return false
}

// AllowUnmatched returns whether unmatched should be allowed
func (config *ConfigIpi) AllowUnmatched() bool {
	//i := int(C.BoolToInt(config.CPtr.b.allowUnmatched))
	//return cIntToBool(i)
	return false
}
