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

#ifndef FIFTYONE_DEGREES_SYNONYM_IPI_INCLUDED
#define FIFTYONE_DEGREES_SYNONYM_IPI_INCLUDED

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

#ifndef FIFTYONE_DEGREES_IPI_INCLUDED
#define FIFTYONE_DEGREES_IPI_INCLUDED

/**
 * @ingroup FiftyOneDegreesIpIntelligence
 * @defgroup FiftyOneDegreesIpIntelligenceApi IpIntelligence
 *
 * All the functions specific to the IP Intelligence API.
 * @{
 */

#if !defined(DEBUG) && !defined(_DEBUG) && !defined(NDEBUG)
#define NDEBUG
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <assert.h>
#ifdef _MSC_VER
#include <windows.h>
#endif
/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2023 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

#ifndef FIFTYONE_DEGREES_DATA_H_INCLUDED
#define FIFTYONE_DEGREES_DATA_H_INCLUDED

/**
 * @ingroup FiftyOneDegreesCommon
 * @defgroup FiftyOneDegreesData Data
 *
 * Structure containing memory allocated to store a variable.
 *
 * ## Terms
 *
 * **Data** : a structure containing memory allocated to a certain item. This
 * can be of any type.
 *
 * ## Introduction
 *
 * A Data structure contains memory allocated for the purpose of storing a
 * variable. This differs from a direct pointer in that the memory can be
 * reused for another purpose. By keeping track of how much data has been
 * allocated, the same allocation can be reused if memory of equal or smaller
 * size is needed, otherwise more memory can be automatically allocated in the
 * same method call.
 *
 * ## Creation
 * 
 * A Data structure does not need to be created by a method, it only needs to
 * be allocated in memory. However, it does need to be reset before any
 * operations are carried out with it.
 *
 * ## Allocation
 *
 * To allocate memory for a variable in a Data structure, the 
 * #fiftyoneDegreesDataMalloc method can be called in a similar way to the
 * standard malloc method. Any existing variable in the Data structure will
 * either be overwritten by the new variable, or the previous variable will be
 * freed and new memory allocated.
 *
 * ## Example Usage
 *
 * ```
 * // Allocate a data structure
 * fiftyoneDegreesData *data = Malloc(sizeof(fiftyoneDegreesData));
 *
 * // Reset the data ready to allocate something
 * fiftyoneDegreesDataReset(data);
 *
 * // Create the data to store
 * const char *string = "some data";
 * size_t size = strlen(string) * sizeof(char);
 *
 * // Allocate the memory inside the data structure
 * void *dataPtr = fiftyoneDegreesDataMalloc(data, size);
 *
 * // Check the allocation was succesful
 * if (dataPtr != NULL) {
 *
 *     // Set the data in the data structure and size it uses
 *     strcpy((char*)dataPtr, string);
 *     data->used = size;
 * }
 * ```
 *
 * @{
 */

#include <stdint.h>
#include <stddef.h>
/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2023 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

#ifndef FIFTYONE_DEGREES_COMMON_H_INCLUDED
#define FIFTYONE_DEGREES_COMMON_H_INCLUDED

#ifdef _MSC_FULL_VER
#define DEPRECATED __declspec(deprecated)
#else
#define DEPRECATED __attribute__((deprecated))
#endif

#ifdef __cplusplus
#define EXTERNAL extern "C"
#else
#define EXTERNAL
#endif

#ifdef __cplusplus
#define EXTERNAL_VAR extern "C"
#else
#define EXTERNAL_VAR extern
#endif

// The characters at the start of a cookie or other storage key that indicate
// the item is related to 51Degrees.
#ifndef FIFTYONE_DEGREES_COMMON_COOKIE_PREFIX
#define FIFTYONE_DEGREES_COMMON_COOKIE_PREFIX "51D_"
#endif

#endif

/**
 * Alias for unsigned char
 */
typedef unsigned char byte;

/**
 * Data structure used for reusing memory which may have been allocated in a
 * previous operation.
 */
typedef struct fiftyone_degrees_data_t {
	byte *ptr; /**< Pointer to immutable data */
	uint32_t allocated; /**< Number of bytes allocated at the pointer. Used 
	                        within the collection and is not intended for
	                        consumers to reference. */
	uint32_t used; /**< Number of valid bytes currently referenced by pointer */
} fiftyoneDegreesData;

/**
 * Resets the data structure ready for a new operation. **MUST** be called
 * before using an instance of #fiftyoneDegreesData.
 * @param data to be reset
 */
EXTERNAL void fiftyoneDegreesDataReset(fiftyoneDegreesData *data);

/**
 * Ensures the data structure contains sufficient bytes. If insufficient bytes
 * are available then the current memory is freed and a new block of memory is 
 * allocated.
 * @param data pointer to the data structure to be checked for sufficient bytes
 * @param bytesNeeded the number of bytes the data needs to be able to store
 * @return a pointer to the memory held within data
 */
EXTERNAL void* fiftyoneDegreesDataMalloc(
	fiftyoneDegreesData *data,
	size_t bytesNeeded);

/**
 * @}
 */
#endif
/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2023 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

#ifndef FIFTYONE_DEGREES_EXCEPTIONS_H_INCLUDED
#define FIFTYONE_DEGREES_EXCEPTIONS_H_INCLUDED

/**
 * @ingroup FiftyOneDegreesCommon
 * @defgroup FiftyOneDegreesExceptions Exceptions
 *
 * Allow the bubbling up or errors in C.
 *
 * ## Introduction
 *
 * An exception structure is used to allow the bubbling up of errors, as C
 * does not support exceptions in that way. This means that instead of an error
 * causing a segmentation fault elsewhere, the exception is set and passed all
 * the way up to be checked.
 *
 * ## Creating
 * 
 * Exceptions are created by the caller using the
 * #FIFTYONE_DEGREES_EXCEPTION_CREATE macro which creates an exception pointer
 * named "exception". This is then passed into any method which can potentially
 * throw an exception.
 *
 * ## Checking
 *
 * An exception can be checked using the #FIFTYONE_DEGREES_EXCEPTION_OKAY macro
 * which will return true if there is no exception, or false if an exception
 * has occurred.
 *
 * ## Throwing
 *
 * In the event that an exception has occurred in a method, it can be checked
 * and thrown using the #FIFTYONE_DEGREES_EXCEPTION_THROW macro. If the
 * exception is okay, then nothing will be thrown by this macro, so it is safe
 * to call as a "catch and throw" method. This will behave differently
 * depending on whether it is used in the context of C or C++.
 *
 * **C** : C does not support exceptions, so if there is an exception, the
 * exception message will be printed to standard output, then the process will
 * exit.
 *
 * **C++** : As C++ supports exceptions, a fatal exception with the message
 * will be thrown. This can then be caught or handled in whichever way the
 * caller sees fit.
 *
 * ## Messages
 *
 * The error message returned by an exception consists of the error message
 * itself, the name of the source file which caused the error, the name of the
 * function which caused the error and the line in the source file at which the
 * error occurred.
 *
 * ## Usage Example
 *
 * ```
 * // Create an exception
 * FIFTYONE_DEGREES_EXCEPTION_CREATE;
 * // Set the exception a failure status
 * FIFTYONE_DEGREES_EXCEPTION_SET(FIFTYONE_DEGREES_STATUS_NULL_POINTER);
 * // Check the exception
 * if  (FIFTYONE_DEGREES_EXCEPTION_FAILED) {
 *     // Throw the exception
 *     FIFTYONE_DEGREES_EXCEPTION_THROW;
 * }
 * ```
 *
 * ## Disabling
 *
 * To improve performance, exception handling can be disabled completely by
 * compiling with FIFTYONE_DEGREES_EXCEPTIONS_DISABLED. This changes all the
 * macro calls to do nothing, meaning that no checks occur, and no exceptions
 * are thrown.
 *
 * @{
 */

/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2023 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

#ifndef FIFTYONE_DEGREES_INIT_H_INCLUDED
#define FIFTYONE_DEGREES_INIT_H_INCLUDED

/**
 * @ingroup FiftyOneDegreesCommon
 * @defgroup FiftyOneDegreesStatus Status
 *
 * Status codes and messages indicating the result of an operation.
 *
 * ## Introduction
 *
 * A status code is an enum indicating the result of an operation, usually
 * the initialisation of something. If the status is anything other than
 * #FIFTYONE_DEGREES_STATUS_SUCCESS, then the operation was not successful. In
 * that case, the status code indicates the nature of the failure. 
 *
 * A status code can be returned by any method that wishes to report a specific
 * error rather than just returning `NULL`.
 *
 * Examples of error status codes are `insufficient memory` or `corrupt data`.
 * If an operation was successful then this is reported in the same way by
 * returning a `success` status code.
 *
 * Status codes have related messages which can be fetched using the
 * #fiftyoneDegreesStatusGetMessage method. The messages are intended to be
 * useful messages which are returned to the user in the event of an error
 * occurring.
 *
 * ## Usage Example
 *
 * ```
 * const char *fileName;
 * fiftyoneDegreesStatusCode status;
 *
 * // Check whether the result of an operation was successful
 * if (status != FIFTYONE_DEGREES_STATUS_SUCCESS) {
 *
 *     // Get the status message as the operation has not succeeded
 *     const char *message = fiftyoneDegreesStatusGetMessage(status, fileName);
 *
 *     // Do something with the message
 *     // ...
 * }
 * ```
 *
 * @{
 */

#include <stdint.h>
#include <string.h>
#include <stdio.h>

/** Status returned from the initialisation of a resource. */
typedef enum e_fiftyone_degrees_status_code {
	FIFTYONE_DEGREES_STATUS_SUCCESS, /**< All okay */
	FIFTYONE_DEGREES_STATUS_INSUFFICIENT_MEMORY, /**< Lack of memory */
	FIFTYONE_DEGREES_STATUS_CORRUPT_DATA, /**< Data structure not readable */
	FIFTYONE_DEGREES_STATUS_INCORRECT_VERSION, /**< Data not the required
											   version */
	FIFTYONE_DEGREES_STATUS_FILE_NOT_FOUND, /**< The data file couldn't be
											found */
	FIFTYONE_DEGREES_STATUS_FILE_BUSY, /**< The data file was busy */
	FIFTYONE_DEGREES_STATUS_FILE_FAILURE, /**< Unknown file error */
	FIFTYONE_DEGREES_STATUS_NOT_SET, /**< Should never be returned to the
									 caller */
	FIFTYONE_DEGREES_STATUS_POINTER_OUT_OF_BOUNDS, /**< Working pointer
												   exceeded the amount of
												   memory containing the data */
	FIFTYONE_DEGREES_STATUS_NULL_POINTER, /**< A key pointer was not set */
	FIFTYONE_DEGREES_STATUS_TOO_MANY_OPEN_FILES, /**< Too many files are open */
	FIFTYONE_DEGREES_STATUS_REQ_PROP_NOT_PRESENT, /**< None of the required
	                                                  properties could be found */
	FIFTYONE_DEGREES_STATUS_PROFILE_EMPTY, /**< The profile id represents an
										   empty profile */
	FIFTYONE_DEGREES_STATUS_COLLECTION_FAILURE, /**< There was an error getting
	                                                an item from a collection
	                                                due to too many concurrent 
	                                                operations */
	FIFTYONE_DEGREES_STATUS_FILE_COPY_ERROR, /**< The data file could not be 
	                                             copied */
	FIFTYONE_DEGREES_STATUS_FILE_EXISTS_ERROR, /**< The file or directory
											   already exists, so could not be
											   created */
	FIFTYONE_DEGREES_STATUS_FILE_WRITE_ERROR, /**< The data file could not be 
	                                              created */
	FIFTYONE_DEGREES_STATUS_FILE_READ_ERROR, /**< The data file could not be
												  cread */
	FIFTYONE_DEGREES_STATUS_FILE_PERMISSION_DENIED, /**< File permission denied */
	FIFTYONE_DEGREES_STATUS_FILE_PATH_TOO_LONG, /**< The file path is longer
	                                                than the available memory
	                                                available to store it */
	FIFTYONE_DEGREES_STATUS_FILE_END_OF_DOCUMENT, /**< End of a yaml document
													read */
	FIFTYONE_DEGREES_STATUS_FILE_END_OF_DOCUMENTS, /**< End of yaml documents
													read */
	FIFTYONE_DEGREES_STATUS_FILE_END_OF_FILE, /**< End of file */
	FIFTYONE_DEGREES_STATUS_ENCODING_ERROR, /**< There was an error encoding
	                                            characters of a string */
	FIFTYONE_DEGREES_STATUS_INVALID_COLLECTION_CONFIG, /**< The configuration 
	                                                   provided to create a 
	                                                   collection could not be 
	                                                   used to create a valid 
	                                                   collection */
	FIFTYONE_DEGREES_STATUS_INVALID_CONFIG, /**< An invalid config was provided */
	FIFTYONE_DEGREES_STATUS_INSUFFICIENT_HANDLES, /**< There were not enough
	                                                  handles available to
	                                                  retrieve data from the
	                                                  source*/
	FIFTYONE_DEGREES_STATUS_COLLECTION_INDEX_OUT_OF_RANGE, /**< Index out of
														   range */
	FIFTYONE_DEGREES_STATUS_COLLECTION_OFFSET_OUT_OF_RANGE, /**< Offset out of
															range */
	FIFTYONE_DEGREES_STATUS_COLLECTION_FILE_SEEK_FAIL, /**< Seek failure */
	FIFTYONE_DEGREES_STATUS_COLLECTION_FILE_READ_FAIL, /**< Read failure */
	FIFTYONE_DEGREES_STATUS_INCORRECT_IP_ADDRESS_FORMAT, /**< IP address 
														format is incorrect */
	FIFTYONE_DEGREES_STATUS_TEMP_FILE_ERROR, /**< Error creating temp file */
	FIFTYONE_DEGREES_STATUS_INSUFFICIENT_CAPACITY, /**< Insufficient capacity of
                                                    the array to hold all the items*/
    FIFTYONE_DEGREES_STATUS_INVALID_INPUT, /**< Invalid input data (f.e. base64 / JSON
										   misformat or semantic inconsistency) */
	FIFTYONE_DEGREES_STATUS_UNSUPPORTED_STORED_VALUE_TYPE, /**< StoredValueType
											is not supported at this version. */
	FIFTYONE_DEGREES_STATUS_FILE_TOO_LARGE, /**< File size exceeds malloc capabilities */
	FIFTYONE_DEGREES_STATUS_UNKNOWN_GEOMETRY, /**< Unsupported geometry type found in WKB */
	FIFTYONE_DEGREES_STATUS_RESERVED_GEOMETRY, /**< Geometry type found in WKB is abstract/reserved */
} fiftyoneDegreesStatusCode;

/**
 * Returns an English error message for the status code allocating memory 
 * needed to store the message. The caller must free the memory when they have 
 * finished consuming the error message.
 * @param status code to get the message for
 * @param fileName the source file used for initialisation, or NULL if not
 * applicable to the status code
 * @return pointer to the newly allocated message string
 */
EXTERNAL const char* fiftyoneDegreesStatusGetMessage(
	fiftyoneDegreesStatusCode status,
	const char *fileName);

/**
 * @}
 */

#endif

#ifndef FIFTYONE_DEGREES_EXCEPTIONS_DISABLED

/**
 * Structure used to represent a 51Degrees exception and passed into methods
 * that might generate exceptions. The #FIFTYONE_DEGREES_EXCEPTION_SET macro
 * should be used to set the status code.
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 */
EXTERNAL typedef struct fiftyone_degrees_exception_t {
	const char *file; /**< File generating the exception */
	const char *func; /**< Function generating the exception */
	int line; /**< Line number generating the exception */
	fiftyoneDegreesStatusCode status; /**< Status code to assign */
} fiftyoneDegreesException;

/**
 * Macro used to set an exception to a status code.
 * @param s status code to set
 */
#define FIFTYONE_DEGREES_EXCEPTION_SET(s) \
if (exception != NULL) { \
exception->file = __FILE__; \
exception->func = __func__; \
exception->line = __LINE__; \
exception->status = s; \
}

/**
 * Macro used to clear an exception type.
 */
#define FIFTYONE_DEGREES_EXCEPTION_CLEAR \
{ \
exception->file = NULL; \
exception->func = NULL; \
exception->line = -1; \
exception->status = FIFTYONE_DEGREES_STATUS_NOT_SET; \
}

/**
* Macro used to check if an exception status equals the value of t.
* Warning: this macro should be avoided in anything other than test code as 
* when exceptions are disabled there will be unpredictable results. Using a
* local status variable for checks is a better pattern.
*/
#define FIFTYONE_DEGREES_EXCEPTION_CHECK(t) \
(exception == NULL || exception->status == t)

/**
 * Macro used to check if there is no exception currently.
 */
#define FIFTYONE_DEGREES_EXCEPTION_OKAY \
FIFTYONE_DEGREES_EXCEPTION_CHECK(FIFTYONE_DEGREES_STATUS_NOT_SET)

#ifdef FIFTYONE_DEGREES_EXCEPTIONS_HPP

/**
 * Macro to throw a C++ exception if the C exception is set. Only used if C++
 * exceptions are enabled.
 */
#define FIFTYONE_DEGREES_EXCEPTION_THROW \
if (FIFTYONE_DEGREES_EXCEPTION_OKAY == false) { \
throw FiftyoneDegrees::Common::FatalException(exception); \
}

#else

/**
 * Macro to print to standard error a message if an exception is set.
 */
#define FIFTYONE_DEGREES_EXCEPTION_THROW \
fiftyoneDegreesExceptionCheckAndExit(exception);

#endif

#else

EXTERNAL typedef void* fiftyoneDegreesException;

#define FIFTYONE_DEGREES_EXCEPTION_CLEAR

#define FIFTYONE_DEGREES_EXCEPTION_SET(s)

#define FIFTYONE_DEGREES_EXCEPTION_OKAY true

#define FIFTYONE_DEGREES_EXCEPTION_THROW

#define FIFTYONE_DEGREES_EXCEPTION_CHECK(t) false

#endif

/**
 * Macro used to create an exception.
 */
#define FIFTYONE_DEGREES_EXCEPTION_CREATE \
fiftyoneDegreesException exceptionValue; \
fiftyoneDegreesException *exception = &exceptionValue; \
FIFTYONE_DEGREES_EXCEPTION_CLEAR

/**
 * Macro to test if the exception has been set and is failed.
 */
#define FIFTYONE_DEGREES_EXCEPTION_FAILED \
(FIFTYONE_DEGREES_EXCEPTION_OKAY == false)

/**
 * Returns an English error message for the exception. The caller must free the
 * memory when they have finished consuming the error message.
 * @param exception to get a string message from
 * @return pointer to the newly allocated message string
 */
EXTERNAL const char* fiftyoneDegreesExceptionGetMessage(
	fiftyoneDegreesException *exception);

/**
 * If the exception is set then will print a message to stderr and exit the 
 * process. 
 * @param exception to check and exit if set
 */
EXTERNAL void fiftyoneDegreesExceptionCheckAndExit(
	fiftyoneDegreesException *exception);

/**
 * @}
 */

#endif
/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2023 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

/**
 * @ingroup FiftyOneDegreesCommon
 * @defgroup FiftyOneDegreesThreading Threading
 *
 * Defines multi threading macros if the FIFTYONE_DEGREES_NO_THREADING compiler
 * directive is not explicitly requesting single threaded operation.
 *
 * @{
 */

#ifndef FIFTYONE_DEGREES_THREADING_INCLUDED
#define FIFTYONE_DEGREES_THREADING_INCLUDED

#include <stdbool.h>
#include <stdint.h>

#include <stdio.h>

/**
 * Determines if the methods that should be thread safe have been compiled so
 * they are thread safe. In single threaded operation compiling without
 * threading using the `FIFTYONE_DEGREES_NO_THREADING` directive results in
 * performance improvements.
 * @return true if the library is thread safe, otherwise false.
 */
EXTERNAL bool fiftyoneDegreesThreadingGetIsThreadSafe();

/**
 * A thread method passed to the #FIFTYONE_DEGREES_THREAD_CREATE macro.
 */
#ifdef _MSC_VER
#define FIFTYONE_DEGREES_THREAD_ROUTINE LPTHREAD_START_ROUTINE 
#else
typedef void*(*FIFTYONE_DEGREES_THREAD_ROUTINE)(void*);
#endif

/* Define NDEBUG if needed, to ensure asserts are disabled in release builds */
#if !defined(DEBUG) && !defined(_DEBUG) && !defined(NDEBUG)
#define NDEBUG
#endif

#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable: 5105) 
#include <windows.h>
#pragma warning (default: 5105) 
#pragma warning (pop)
#include <intrin.h>
#pragma intrinsic (_InterlockedIncrement)
#pragma intrinsic (_InterlockedDecrement)
#else
#include <pthread.h>
#include <signal.h>
#endif
#include <assert.h>

/**
 * MUTEX AND THREADING MACROS
 */

/**
 * Mutex used to synchronise access to data structures that could be used
 * in parallel in a multi threaded environment.
 */
#ifdef _MSC_VER
typedef HANDLE fiftyoneDegreesMutex;
#else
typedef pthread_mutex_t fiftyoneDegreesMutex;
/**
 * Initialises the mutex passed to the method.
 * @param mutex to be initialised.
 */
EXTERNAL void fiftyoneDegreesMutexCreate(fiftyoneDegreesMutex *mutex);
/**
 * Closes the mutex passed to the method.
 * @param mutex to be closed.
 */
EXTERNAL void fiftyoneDegreesMutexClose(fiftyoneDegreesMutex *mutex);
/**
 * Locks the mutex passed to the method.
 * @param mutex to be locked.
 */
EXTERNAL void fiftyoneDegreesMutexLock(fiftyoneDegreesMutex *mutex);
/**
 * Unlocks the mutex passed to the method.
 * @param mutex to be unlocked.
 */
EXTERNAL void fiftyoneDegreesMutexUnlock(fiftyoneDegreesMutex *mutex);
#endif

/**
 * A signal used to limit the number of items that can be created by
 * the pool.
 */
#ifdef _MSC_VER
typedef HANDLE fiftyoneDegreesSignal;
#else
typedef struct fiftyone_degrees_signal_t {
	volatile bool wait; /**< Flag indicating if the thread should wait */
	pthread_cond_t cond; /**< Condition variable for the signal */
	pthread_mutex_t mutex; /**< Mutex for the signal */
} fiftyoneDegreesSignal;
#endif

/**
 * Initialises the signal pointer by setting the condition first followed by
 * the mutex if the condition was set correctly. Destroyed is set to false to
 * indicate to the other methods that the signal is still valid. The memory
 * used by the signal should be part of another structure and will be released
 * when that structure is released. If there is a problem creating the mutex
 * the condition is also released.
 * @return new signal
 */
fiftyoneDegreesSignal* fiftyoneDegreesSignalCreate();

/**
 * Closes the signal ensuring there is a lock on the signal before destroying
 * the signal. This means that no other process can be waiting on the signal
 * before it is destroyed. The destroyed field of the signal structure is set
 * to true after the condition is destroyed. All methods that could
 * subsequently try and get a lock on the signal **MUST** check the destroyed
 * field before trying to get the lock.
 * @param signal to be closed.
 */
void fiftyoneDegreesSignalClose(fiftyoneDegreesSignal *signal);

/**
 * If the signal has not been destroyed then sends a signal to a waiting
 * thread that the signal has been set and one can continue. This possible
 * because the condition will auto reset only enabling a signal thread to
 * continue even if multi threads are waiting.
 * @param signal to be set.
 */
void fiftyoneDegreesSignalSet(fiftyoneDegreesSignal *signal);

/**
 * Wait for a signal to be set. Only waits for the signal if the signal has not
 * been destroyed. Locks the mutex before the signal is waited for. This
 * ensures only one thread can be waiting on the signal at any one time.
 * @param signal pointer to the signal used to wait on.
 */
void fiftyoneDegreesSignalWait(fiftyoneDegreesSignal *signal);

/**
 * A thread created with the #FIFTYONE_DEGREES_THREAD_CREATE macro.
 */
#ifdef _MSC_VER
#define FIFTYONE_DEGREES_THREAD HANDLE
#else
#define FIFTYONE_DEGREES_THREAD pthread_t
#endif

/**
 * Creates a new signal that can be used to wait for
 * other operations to complete before continuing.
 * @param s signal to create
 */
#define FIFTYONE_DEGREES_SIGNAL_CREATE(s) s = fiftyoneDegreesSignalCreate()

/**
 * Frees the handle provided to the macro.
 * @param s signal to close
 */
#define FIFTYONE_DEGREES_SIGNAL_CLOSE(s) fiftyoneDegreesSignalClose(s)

/**
 * Signals a thread waiting for the signal to proceed.
 * @param s signal to set
 */
#define FIFTYONE_DEGREES_SIGNAL_SET(s) fiftyoneDegreesSignalSet(s)

/**
 * Waits for the signal to become set by another thread.
 * @param s signal to wait on
 */
#define FIFTYONE_DEGREES_SIGNAL_WAIT(s) fiftyoneDegreesSignalWait(s)

/**
 * Creates a new mutex at the pointer provided.
 * @param m mutex to create
 */
#ifdef _MSC_VER
#define FIFTYONE_DEGREES_MUTEX_CREATE(m) m = CreateMutex(NULL,FALSE,NULL)
#else
#define FIFTYONE_DEGREES_MUTEX_CREATE(m) fiftyoneDegreesMutexCreate(&m)
#endif

/**
 * Frees the mutex at the pointer provided.
 * @param m mutex to close
 */
#ifdef _MSC_VER
#define FIFTYONE_DEGREES_MUTEX_CLOSE(m) if (m != NULL) { CloseHandle(m); }
#else
#define FIFTYONE_DEGREES_MUTEX_CLOSE(m) fiftyoneDegreesMutexClose(&m)
#endif

/**
 * Locks the mutex at the pointer provided.
 * @param m mutex to lock
 */
#ifdef _MSC_VER
#define FIFTYONE_DEGREES_MUTEX_LOCK(m) WaitForSingleObject(*m, INFINITE)
#else
#define FIFTYONE_DEGREES_MUTEX_LOCK(m) fiftyoneDegreesMutexLock(m)
#endif

/**
 * Unlocks the mutex at the pointer provided.
 * @param m mutex to unlock
 */
#ifdef _MSC_VER
#define FIFTYONE_DEGREES_MUTEX_UNLOCK(m) ReleaseMutex(*m)
#else
#define FIFTYONE_DEGREES_MUTEX_UNLOCK(m) fiftyoneDegreesMutexUnlock(m)
#endif

/**
 * Returns true if the mutex is valid.
 * @param m mutex to check
 * @return true if valid
 */
#ifdef _MSC_VER
#define FIFTYONE_DEGREES_MUTEX_VALID(m) (*m != NULL)
#else
#define FIFTYONE_DEGREES_MUTEX_VALID(m) fiftyoneDegreesMutexValid(m)
#endif

/**
 * Creates a new thread with the following parameters:
 * @param t pointer to #FIFTYONE_DEGREES_THREAD memory
 * @param m the method to call when the thread runs
 * @param s pointer to the state data to pass to the method
 * @return new thread
 */
#ifdef _MSC_VER
#define FIFTYONE_DEGREES_THREAD_CREATE(t, m, s) t = \
	(FIFTYONE_DEGREES_THREAD)CreateThread(NULL, 0, m, s, 0, NULL)
#else
#define FIFTYONE_DEGREES_THREAD_CREATE(t, m, s) pthread_create(&t, NULL, m, s)
#endif

/**
 * Joins the thread provided to the current thread waiting
 * indefinitely for the operation to complete.
 * @param t pointer to a previously created thread
 */
#ifdef _MSC_VER
#define FIFTYONE_DEGREES_THREAD_JOIN(t) WaitForSingleObject(t, INFINITE)
#else
#define FIFTYONE_DEGREES_THREAD_JOIN(t) pthread_join(t, NULL)
#endif

/**
 * Closes the thread passed to the macro.
 * @param t thread to close
 */
#ifdef _MSC_VER
#define FIFTYONE_DEGREES_THREAD_CLOSE(t) CloseHandle(t)
#else
#define FIFTYONE_DEGREES_THREAD_CLOSE(t)
#endif

/**
 * Exits the calling thread.
 */
#ifdef _MSC_VER
#define FIFTYONE_DEGREES_THREAD_EXIT ExitThread(0)
#else
#define FIFTYONE_DEGREES_THREAD_EXIT pthread_exit(NULL)
#endif

/**
 * Increments the value and returns the final value.
 * @param v the value to decrement
 * @return value after incrementing
 */
#ifdef _MSC_VER
#define FIFTYONE_DEGREES_INTERLOCK_INC(v) _InterlockedIncrement(v)
#else
#define FIFTYONE_DEGREES_INTERLOCK_INC(v) (__atomic_add_fetch(v, 1, __ATOMIC_SEQ_CST))
#endif

/**
 * Decrements the value and returns the final value.
 * @param v the value to decrement
 * @return value after decrementing
 */
#ifdef _MSC_VER
#define FIFTYONE_DEGREES_INTERLOCK_DEC(v) _InterlockedDecrement(v)
#else
#define FIFTYONE_DEGREES_INTERLOCK_DEC(v) (__atomic_add_fetch(v, -1, __ATOMIC_SEQ_CST))
#endif

/**
 * Replaces the destination value with the exchange value, only if the
 * destination value matched the comparand. Returns the value of d before
 * the swap.
 * @param d the destination to swap
 * @param e the exchange value
 * @param c the comparand
 */
#ifdef _MSC_VER
#define FIFTYONE_DEGREES_INTERLOCK_EXCHANGE(d,e,c) \
	InterlockedCompareExchange(&d, e, c)
#else
/* __sync is still used here, as __atomic only offers a bool return value.
This will end up being resolved to __atomic functions anyway, so is still
supported. */
#define FIFTYONE_DEGREES_INTERLOCK_EXCHANGE(d,e,c) \
	__sync_val_compare_and_swap(&d,c,e) 
#endif

/**
 * 64 bit compare and swap. Replaces the destination value with the exchange
 * value, only if the destination value matched the comparand. Returns the
 * value of d before the swap.
 * @param d the destination to swap
 * @param e the exchange value
 * @param c the comparand
 */
#ifdef _MSC_VER
#define FIFTYONE_DEGREES_INTERLOCK_EXCHANGE_64(d,e,c) \
	InterlockedCompareExchange64((volatile __int64*)&d, (__int64)e, (__int64)c)
#else
#define FIFTYONE_DEGREES_INTERLOCK_EXCHANGE_64(d,e,c) \
    FIFTYONE_DEGREES_INTERLOCK_EXCHANGE(d,e,c)
#endif

/**
 * Replaces the destination pointer with the exchange pointer, only if the
 * destination pointer matched the comparand. Returns the value of d before
 * the swap.
 * @param d the destination to swap
 * @param e the exchange value
 * @param c the comparand
 */
#ifdef _MSC_VER
#define FIFTYONE_DEGREES_INTERLOCK_EXCHANGE_PTR(d,e,c) \
    InterlockedCompareExchangePointer((volatile PVOID*)&d,e,c)
#else
#define FIFTYONE_DEGREES_INTERLOCK_EXCHANGE_PTR(d,e,c) \
    FIFTYONE_DEGREES_INTERLOCK_EXCHANGE(d,e,c)
#endif

/**
 * Double width (64 or 128 depending on the architecture) compare and exchange.
 * Replaces the destination value with the exchange value, only if the
 * destination value matched the comparand. Returns true if the value was
 * exchanged.
 * 
 * Windows: Either InterlockedCompareExchange128 or InterlockedCompareExchange64
 * is used, depending on whether the source is compiled in 32 or 64 bit.
 * InterlockedCompareExchange128 will use the cmpxchg16b instruction on modern
 * Intel and AMD CPUs.
 * 
 * see: https://docs.microsoft.com/en-us/cpp/intrinsics/interlockedcompareexchange128?view=msvc-160
 *
 * Linux: __atomic_compare_exchange is used regardless of architecture. The size
 * of fiftyoneDegreesInterlockDoubleWidth dictates whether
 * __atomic_compare_exchange_8 or __atomic_compare_exchange_16 will be called.
 * The underlying implementation will depend on the hardware - either the compiler
 * intrinsic will be used, or a library function if that is not available.
 *
 * __atomic_compare_exchange_16 will use the cmpxchg16b on modern Intel and AMD CPUs.
 * However, most ARM chips will not support this, so the fallback library function
 * may not offer the same performance. Falling back to a library function may mean
 * that the operation is not lock free. To check, see the
 * FIFTYONE_DEGREES_IS_LOCK_FREE macro.
 *
 * see: https://gcc.gnu.org/onlinedocs/libstdc++/manual/ext_concurrency_impl.html
 * 
 * @param d the destination to swap
 * @param e the exchange value
 * @param c the comparand
 */
#ifdef _MSC_VER
#ifdef _WIN64
typedef struct fiftyone_degrees_interlock_dw_type_t {
    LONG64 low;
    LONG64 high;
} fiftyoneDegreesInterlockDoubleWidth;
#define FIFTYONE_DEGREES_INTERLOCK_EXCHANGE_DW(d,e,c) \
    InterlockedCompareExchange128(&d.low, e.high, e.low, &c.low)
#else // _WIN64
typedef struct fiftyone_degrees_interlock_dw_type_t {
    LONG64 value;
} fiftyoneDegreesInterlockDoubleWidth;
#define FIFTYONE_DEGREES_INTERLOCK_EXCHANGE_DW(d,e,c) \
    InterlockedCompareExchange64(&d.value, e.value, c.value) == c.value
#endif // _WIN64
#else // _MSC_VER
#if (defined(_LP64) || defined(__MINGW64__))
typedef struct fiftyone_degrees_interlock_dw_type_t {
    int64_t low;
    int64_t high;
} __attribute__((aligned(16),packed)) fiftyoneDegreesInterlockDoubleWidth;
#else // _LP64
typedef struct fiftyone_degrees_interlock_dw_type_t {
    int64_t value;
} fiftyoneDegreesInterlockDoubleWidth;
#endif //_LP64
#define FIFTYONE_DEGREES_INTERLOCK_EXCHANGE_DW(d,e,c) \
    (__atomic_compare_exchange( \
        (fiftyoneDegreesInterlockDoubleWidth*)&d, \
        (fiftyoneDegreesInterlockDoubleWidth*)&c, \
        (fiftyoneDegreesInterlockDoubleWidth*)&e, \
        false, \
        __ATOMIC_SEQ_CST, \
        __ATOMIC_SEQ_CST))
#endif // _MSC_VER


#ifdef _MSC_VER
#ifdef _WIN64
#define FIFTYONE_DEGREES_IS_LOCK_FREE IsProcessorFeaturePresent(PF_COMPARE_EXCHANGE128)
#else
#define FIFTYONE_DEGREES_IS_LOCK_FREE true
#endif
#else
#define FIFTYONE_DEGREES_IS_LOCK_FREE __atomic_is_lock_free(sizeof(fiftyoneDegreesInterlockDoubleWidth), NULL)
#endif

/**
 * @}
 */

#endif
/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2023 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

/**
 * @ingroup FiftyOneDegreesCommon
 * @defgroup FiftyOneDegreesFile File
 *
 * File handle pool and simple file operations e.g. copy and delete.
 *
 * ## Introduction
 *
 * Implements a pool of file handles for use within multi-threaded environments
 * where the overhead of opening and closing a file handle for each thread
 * would be too great. Primarily used to load collection items from file with 
 * file based collections or where a cache is used.
 *
 * ## Creation
 *
 * The #fiftyoneDegreesFilePoolInit method is used to initialise a pointer to
 * a #fiftyoneDegreesFilePool. A concurrency value is provided to indicate the
 * maximum number of threads that will be in operation. If this value is lower
 * than the actual number of threads the stack can be exhausted and a null
 * pointer is returned instead of a valid file handle. The concurrency value
 * must always be the same or greater than the number of threads. When compiled
 * in single threaded operation a pool is not strictly required and the
 * implementation maintains a simple stack for consistency of interface and to
 * minimise divergent code.
 *
 * ## Get & Release
 *
 * Handles are retrieved from the pool via the #fiftyoneDegreesFileHandleGet 
 * method. The handle **MUST** be returned with the 
 * #fiftyoneDegreesFileHandleRelease method when it is finished with. The
 * handle will always be open and ready for read only operation. The position
 * of the handle within the source file cannot be assumed. If too many threads
 * are accessing the pool simultaneously, meaning a handle cannot be secured,
 * then a NULL pointer is returned.
 *
 * ## Free
 *
 * The handles are closed when the reader is released via the
 * #fiftyoneDegreesFilePoolRelease method. Any memory allocated by the 
 * implementation for the stack is freed.
 *
 * ## File Operations
 *
 * Common file operations can also be carried out using the methods defined
 * here. The supported operations are:
 *
 * **copy** : #fiftyoneDegreesFileCopy
 *
 * **create directory** : #fiftyoneDegreesFileCreateDirectory
 *
 * **create temp file** : #fiftyoneDegreesFileCreateTempFile
 *
 * **delete** : #fiftyoneDegreesFileDelete
 *
 * **get existing temp file** : #fiftyoneDegreesFileGetExistingTempFile
 *
 * **get file name** : #fiftyoneDegreesFileGetFileName
 *
 * **get path** : #fiftyoneDegreesFileGetPath
 *
 * **get size** : #fiftyoneDegreesFileGetSize
 *
 * **open** : #fiftyoneDegreesFileOpen
 *
 * **read to byte array** : #fiftyoneDegreesFileReadToByteArray
 *
 * **write** : #fiftyoneDegreesFileWrite
 *
 * ## Usage Example
 *
 * ```
 * FIFTYONE_DEGREES_EXCEPTION_CREATE;
 * fiftyoneDegreesFilePool pool;
 * const char *fileName;
 *
 * // Initialise a file pool
 * fiftyoneDegreesStatus status = fiftyoneDegreesFilePoolInit(
 *     &filePool,
 *     fileName,
 *     1,
 *     exception);
 *
 * // Check that the pool was initialised successfully
 * if (status == FIFTYONE_DEGREES_STATUS_SUCCESS) {
 *
 *     // Get a file handle from the pool
 *     fiftyoneDegreesFileHandle *handle = fiftyoneDegreesFileHandleGet(
 *         &pool,
 *         exception);
 *
 *     // Check that the handle was returned successfully
 *     if (FIFTYONE_DEGREES_EXCEPTION_OKAY) {
 *
 *         // Do something with the file pointer in handle->file
 *         // ...
 *
 *         // Release the file handle back to the pool
 *         fiftyoneDegreesFileHandleRelease(handle);
 *     }
 *
 *     // Release the file pool
 *     fiftyoneDegreesFilePoolRelease(&pool);
 * }
 * ```
 *
 * ## Design
 *
 * To improve performance in multi-threaded operation a non locking stack is 
 * used where a Compare and Swap (CAS) atomic operation is used to pop and push 
 * handles on and off the stack. The design was adapted from the following 
 * article (http://nullprogram.com/blog/2014/09/02/) which explains some of the 
 * challenges involved including the ABA problem 
 * (https://en.wikipedia.org/wiki/ABA_problem). It is for this reason the head 
 * structure is implemented as a union between the values and the exchange
 * integer. Pointers are not used as the address space for the stack is 
 * continuous and always very small compared to the total addressable memory 
 * space.
 *
 * @{
 */

#ifndef FIFTYONE_DEGREES_FILE_H_INCLUDED
#define FIFTYONE_DEGREES_FILE_H_INCLUDED

/* Define NDEBUG if needed, to ensure asserts are disabled in release builds */
#if !defined(DEBUG) && !defined(_DEBUG) && !defined(NDEBUG)
#define NDEBUG
#endif

#include <limits.h>
#include <stdio.h>
#include <errno.h>
#include <stdint.h>
#include <stdbool.h>
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable: 5105) 
#include <windows.h>
#pragma warning (default: 5105) 
#pragma warning (pop)
#include <direct.h>
#include <tchar.h>
#else
#include <dirent.h>
#include <sys/stat.h>
#endif
#include <time.h>
#include <assert.h>
#include <limits.h>
#include <time.h>
/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2025 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

#ifndef FIFTYONE_DEGREES_FILE_OFFSET_H_INCLUDED
#define FIFTYONE_DEGREES_FILE_OFFSET_H_INCLUDED

/**
 * @ingroup FiftyOneDegreesCommon
 * @defgroup FiftyOneDegreesFile FileOffset
 *
 * `FileOffset` offset types:
 * - signed `FileOffset` -- for interop with native API (fseek/ftell)
 * - unsigned `FileOffsetUnsigned` -- as present in data file
 *
 *
 * if FIFTYONE_DEGREES_LARGE_DATA_FILE_SUPPORT macro is defined,
 * both types will be 64-bit.
 *
 * Motivation for this is that an offset in a large file
 * beyond 4GB is not addressable by a `uint32_t` variable.
 *
 * For files smaller than 4GB `uint32_t` is fully sufficient to address an offset.
 *
 * `fseek`/`ftell` functions MAY also fail on files larger than 2 GiB
 * due to the limitations of `long int` type used,
 * so enabling the option MIGHT be necessary in those cases as well.
 *
 * On POSIX systems `_FILE_OFFSET_BITS` should be defined as `64` at the same time
 * for `off_t` (used by `fseeko`/`ftello` from `<stdio.h>`) to be 64-bit as well.
 *
 * @{
 */

#include <stdint.h>

typedef
#ifdef FIFTYONE_DEGREES_LARGE_DATA_FILE_SUPPORT
uint64_t
#else
uint32_t
#endif
fiftyoneDegreesFileOffsetUnsigned; /**< Type for collection start offset (in file). [unsigned] */

typedef
#ifdef FIFTYONE_DEGREES_LARGE_DATA_FILE_SUPPORT
int64_t
#else
long
#endif
fiftyoneDegreesFileOffset; /**< Type for file offset in API. [signed] */

/**
 * @}
 */
#endif
/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2023 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

/**
 * @ingroup FiftyOneDegreesCommon
 * @defgroup FiftyOneDegreesMemory Memory
 *
 * Utility methods used to handle common memory operations such as allocating 
 * memory and freeing it, or reading through continuous memory checking for
 * buffer over or under runs.
 *
 * @{
 */

#ifndef FIFTYONE_DEGREES_MEMORY_H_INCLUDED
#define FIFTYONE_DEGREES_MEMORY_H_INCLUDED

#include <stdlib.h>
#include <stdbool.h>
/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2023 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

#ifndef FIFTYONE_DEGREES_TREE_INCLUDED
#define FIFTYONE_DEGREES_TREE_INCLUDED


/**
 * @ingroup FiftyOneDegreesCommon
 * @defgroup FiftyOneDegreesTree Tree
 *
 * Implementation of the classic red black binary tree.
 *
 * ## Introduction
 *
 * Implementation of a classic red black binary tree adapted to support the
 * result set structure used in the LRU cache. Several important considerations
 * should be noted with this implementation.
 *
 * 1. The maximum number of entries in the tree is known when the tree is
 *    created. All memory allocation is performed at initialisation.
 * 2. Once the tree is full it will remain full and never shrinks. The memory
 *    used is freed when the cache is freed.
 * 3. A node in the tree also contains other data such as the linked list
 *    pointers used to identify the first and last entry in the cache, and
 *    the cache data itself. See structure Node.
 * 4. The cache structure Cache contains special fields "empty"
 *    and "root". "Empty" is used in place of NULL to indicate that the left,
 *    right or parent pointer of the node has no data. The use of "empty" makes
 *    the algorithm more efficient as the data structure used to indicate no
 *    data is the same as a valid data structure and therefore does not require
 *    custom logic. The "root" fields left pointer is used as the start of the
 *    tree. Similarly the parent element being a valid data structure
 *    simplifies the algorithm.
 *
 * Developers modifying this section of code should be familiar with the red
 * black tree design template. Code comments assume an understanding of the
 * principles involved.
 *
 * For further information see:
 * https://en.wikipedia.org/wiki/Red%E2%80%93black_tree
 *
 * @{
 */

#include <stdlib.h>
#include <stdint.h>
#include <assert.h>


 /** @cond FORWARD_DECLARATIONS */
typedef struct fiftyone_degrees_tree_node_t fiftyoneDegreesTreeNode;
typedef struct fiftyone_degrees_tree_root_t fiftyoneDegreesTreeRoot;
/** @endcond */

/** Node structure defining a single node in the tree. */
typedef struct fiftyone_degrees_tree_node_t {
	int64_t key; /**< Numeric key associated with the data value */
	fiftyoneDegreesTreeRoot *root; /**< The current root node of the tree */
	fiftyoneDegreesTreeNode *parent; /**< Parent node or NULL if root */
	fiftyoneDegreesTreeNode *left; /**< Left node or NULL if none */
	fiftyoneDegreesTreeNode *right; /**< Right node or NULL if none */
	unsigned char colour; /**< The colour of the node in the red black tree */
} fiftyoneDegreesTreeNode;

/** Tree root structure defining the beginning of the tree. */
typedef struct fiftyone_degrees_tree_root_t {
	fiftyoneDegreesTreeNode root; /**< The current root node of the tree */
	fiftyoneDegreesTreeNode empty; /**< Empty tree node */
} fiftyoneDegreesTreeRoot;

/**
 * Callback method called while iterating over a tree.
 * @param state pointer to any data needed by the method
 * @param node at the current point in the tree
 */
typedef void(*fiftyoneDegreesTreeIterateMethod)(
	void* state,
	fiftyoneDegreesTreeNode* node);

/**
 * Empty tree node.
 */
extern fiftyoneDegreesTreeNode *fiftyoneDegreesTreeEmpty;

/**
 * Used by assert statements to validate the number of entries in the cache for
 * debugging should any changes be made to the logic. Should not be compiled in
 * release builds.
 * @param root pointer to the node being counted.
 * @return the number of children plus 1 for this current node.
 */
uint32_t fiftyoneDegreesTreeCount(fiftyoneDegreesTreeRoot *root);

/**
 * Removes the node from the tree so that it can be used again to store
 * another result. The node will come from the last item in the cache's
 * linked list.
 * @param node pointer to be deleted.
 */
void fiftyoneDegreesTreeDelete(fiftyoneDegreesTreeNode *node);

/**
 * Inserts the node into the red black tree.
 * @param node pointer to the node being inserted.
 */
void fiftyoneDegreesTreeInsert(fiftyoneDegreesTreeNode *node);

/**
 * Returns the node that matches the key code provided.
 * @param root of the tree to search in
 * @param key to get the item for
 * @return the corresponding node if it exists in the tree, otherwise NULL.
 */
fiftyoneDegreesTreeNode* fiftyoneDegreesTreeFind(
	fiftyoneDegreesTreeRoot *root,
	int64_t key);

/**
 * Initialises a newly allocated node.
 * @param node to initialise
 * @param root of the tree to which the node belongs
 */
void fiftyoneDegreesTreeNodeInit(
	fiftyoneDegreesTreeNode *node,
	fiftyoneDegreesTreeRoot *root);

/**
 * Removes a node from the tree it belongs to.
 * @param node to remove
 */
void fiftyoneDegreesTreeNodeRemove(fiftyoneDegreesTreeNode *node);

/**
 * Initialises a newly allocated tree root to a clean state.
 * @param root to initialise
 */
void fiftyoneDegreesTreeRootInit(fiftyoneDegreesTreeRoot *root);

/**
 * Iterates over all the nodes in the tree starting at the root provided,
 * calling the callback method with each node in the tree.
 * @param root of the tree to iterate
 * @param state pointer to pass to the callback method
 * @param callback method to call with each node
 */
void fiftyoneDegreesTreeIterateNodes(
	fiftyoneDegreesTreeRoot *root,
	void *state,
	fiftyoneDegreesTreeIterateMethod callback);

/**
 * @}
 */

#endif

#ifdef _MSC_VER
#define FIFTYONE_DEGREES_CALL_CONV __cdecl
#else
#define FIFTYONE_DEGREES_CALL_CONV
#endif

/**
 * Used to read data from memory in a similar manner to a file handle.
 */
typedef struct fiftyone_degrees_memory_reader_t {
	byte *startByte; /**< The first byte in memory */
	byte *current; /**< The current byte being read from */
	byte *lastByte; /**< The maximum byte that can be read from */
	fiftyoneDegreesFileOffset length; /**< Length of the file in bytes */
} fiftyoneDegreesMemoryReader;

/**
 * Used to read continuous memory checking for buffer over or under runs.
 * @param reader structure used to check for last byte
 * @param advanceBy number of bytes to advance current by
 * @return true if the advance succeeded, otherwise false
 */
bool fiftyoneDegreesMemoryAdvance(
	fiftyoneDegreesMemoryReader *reader,
	size_t advanceBy);

/**
 * Allocates memory using the standard malloc method.
 * @param __size number of bytes to allocate
 * @return pointer to allocated memory or NULL
 */
EXTERNAL void* fiftyoneDegreesMemoryStandardMalloc(size_t __size);

/**
 * Allocates memory while keeping track of the memory which has been allocated
 * using this method since calling #fiftyoneDegreesMemoryTrackingReset.
 * @param __size number of bytes to allocate
 * @return pointer to allocated memory or NULL
 */
EXTERNAL void* fiftyoneDegreesMemoryTrackingMalloc(size_t __size);

/**
 * Allocated aligned memory using the standard malloc method.
 * @param alignment byte boundary to align the allocation to e.g. 16
 * @param __size number of bytes to allocate
 * @return pointer to allocation memory or NULL
 */
EXTERNAL void* fiftyoneDegreesMemoryStandardMallocAligned(
    int alignment,
    size_t __size);


/**
 * Allocates aligned memory while keeping track of the memory which has been
 * allocated using this method since calling
 * #fiftyoneDegreesMemoryTrackingReset.
 * @param alignment byte boundary to align the allocation to e.g. 16
 * @param __size number of bytes to allocate
 * @return pointer to allocation memory or NULL
 */
EXTERNAL void* fiftyoneDegreesMemoryTrackingMallocAligned(
    int alignment,
    size_t __size);

/**
 * Frees memory allocated using the #fiftyoneDegreesMemoryTrackingMalloc method,
 * noting that it has now been freed and does not contribute to the current
 * total.
 * @param __ptr data to free
 */
EXTERNAL void fiftyoneDegreesMemoryTrackingFree(void *__ptr);

/**
 * Frees memory allocated using the #fiftyoneDegreesMemoryTrackingMallocAligned
 *  method, noting that it has now been freed and does not contribute to the
 * current total.
 * @param __ptr data to free
 */
EXTERNAL void fiftyoneDegreesMemoryTrackingFreeAligned(void* __ptr);

/**
 * Frees memory using the standard free method.
 * @param __ptr data to free
 */
EXTERNAL void fiftyoneDegreesMemoryStandardFree(void *__ptr);

/**
 * Frees memory using the standard aligned free method.
 * @param __ptr data to free
 */
EXTERNAL void fiftyoneDegreesMemoryStandardFreeAligned(void *__ptr);

/**
 * Gets the maximum total number of bytes that have been allocated using the
 * #fiftyoneDegreesMemoryTrackingMalloc method. NOTE: this is the total at any
 * point in time since the #fiftyoneDegreesMemoryTrackingReset method was
 * called, NOT the total allocated in a single allocation.
 * @return maximum total allocation
 */
EXTERNAL size_t fiftyoneDegreesMemoryTrackingGetMax();

/**
 * Gets the current number of bytes allocated using the tracking malloc and free
 * methods.
 * @return total bytes currently allocated
 */
EXTERNAL size_t fiftyoneDegreesMemoryTrackingGetAllocated();

/**
 * Resets the memory trackers keeping track of the data allocated using the
 * #fiftyoneDegreesMemoryTrackingMalloc method. This should always be called
 * before tracking memory allocations.
 */
EXTERNAL void fiftyoneDegreesMemoryTrackingReset();

/**
 * Setup memory tracking by resetting memory tracking and setting all Malloc/Free
 * function pointers to pointer to TrackingMalloc/Free functions.
 */
EXTERNAL void fiftyoneDegreesSetUpMemoryTracking();

/**
 * This function works in collaboration with fiftyoneDegreesSetUpMemoryTracking.
 * Check if all tracking memory has been freed.
 * Unset memory tracking by setting all Malloc/Free function pointer to standard
 * Malloc/Free functions. Then, reset memory tracking.
 * @return 0 if all freed, non 0 if there are memory left unfreed. The returned
 * value is the size of allocated memory left unfreed.
 */
EXTERNAL size_t fiftyoneDegreesUnsetMemoryTracking();

/**
 * Pointer to the method used to allocate memory. By default this maps to
 * #fiftyoneDegreesMemoryStandardMalloc which calls the standard library malloc.
 * @param __size to allocate
 * @return pointer to allocated memory or NULL
 */
EXTERNAL_VAR void *(FIFTYONE_DEGREES_CALL_CONV *fiftyoneDegreesMalloc)(size_t __size);

/**
 * Pointer to the method used to allocate aligned memory. By default this maps
 * to #fiftyoneDegreesMemoryStandardMallocAligned which calls the standard
 * library malloc, allocating slightly more that requested, then ensures the
 * pointer is aligned to a boundary.
 * @param alignment byte boundary to align the allocation to e.g. 16
 * @param __size to allocate
 * @return pointer to allocated memory or NULL
 */
EXTERNAL_VAR void* (FIFTYONE_DEGREES_CALL_CONV *fiftyoneDegreesMallocAligned)(
    int alignment,
    size_t __size);

/**
 * Pointer to the method used to free memory. By default this maps to
 * #fiftyoneDegreesMemoryStandardFree which calls the standard library free.
 * @param __ptr pointer to free
 */
EXTERNAL_VAR void (FIFTYONE_DEGREES_CALL_CONV *fiftyoneDegreesFree)(void *__ptr);

/**
 * Pointer to the method used to free memory. By default this maps to
 * #fiftyoneDegreesMemoryStandardFreeAligned which calls the standard library free.
 * @param __ptr pointer to free
 */
EXTERNAL_VAR void (FIFTYONE_DEGREES_CALL_CONV *fiftyoneDegreesFreeAligned)(void* __ptr);

/**
 * @}
 */

#endif
/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2023 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

#ifndef FIFTYONE_DEGREES_POOL_H_INCLUDED
#define FIFTYONE_DEGREES_POOL_H_INCLUDED

/**
 * @ingroup FiftyOneDegreesCommon
 * @defgroup FiftyOneDegreesPool Pool
 *
 * Pool of handles to allow safe access to multiple threads.
 *
 * ## Introduction
 *
 * A Pool structure defines a pool of handles to a resource, and allows a safe
 * way to access them in a multi-threaded environment.
 *
 * ## Creation
 *
 * The #fiftyoneDegreesPoolInit method is used to initialise a pointer to
 * a #fiftyoneDegreesPool. A concurrency value is provided to indicate the
 * maximum number of threads that will be in operation. If this value is lower
 * than the actual number of threads the stack can be exhausted and a null
 * pointer is returned instead of a valid item. The concurrency value must
 * always be the same or greater than the number of threads. When compiled
 * in single threaded operation a pool is not strictly required and the
 * implementation maintains a simple stack for consistency of interface and to
 * minimise divergent code.
 *
 * ## Get & Release
 *
 * Handles are retrieved from the pool via the #fiftyoneDegreesPoolItemGet
 * method. The handle **MUST** be returned with the
 * #fiftyoneDegreesPoolItemRelease method when it is finished with. The
 * handle will always be open and ready for read only operation. If too many
 * threads are accessing the pool simultaneously, meaning a handle cannot be
 * secured, then a NULL pointer is returned.
 *
 * ## Free
 *
 * The items are closed when the pool is released via the
 *  #fiftyoneDegreesPoolFree method. Any memory allocated by the implementation
 * for the stack is freed.
 *
 * ## Usage Example
 *
 * ```
 * FIFTYONE_DEGREES_EXCEPTION_CREATE;
 * void *state;
 * fiftyoneDegreesPoolResourceCreate resourceCreate;
 * fiftyoneDegreesPoolResourceFree resourceFree;
 * fiftyoneDegreesPool pool;
 *
 * // Initialise a pool of resources and check that it was successful
 * if (fiftyoneDegreesPoolInit(
 *     &pool,
 *     1,
 *     state,
 *     resourceCreate,
 *     resourceFree,
 *     exception) != NULL) {
 *
 *     // Get a resource from the pool
 *     fiftyoneDegreesPoolItem *item = fiftyoneDegreesPoolItemGet(
 *         &pool,
 *         exception);
 *
 *     // Check that there was a resource available
 *     if (item != NULL) {
 *
 *         // Do something with the resource without being interrupted by other
 *         // threads
 *         // ...
 *
 *         // Release the resource back to the pool
 *         fiftyoneDegreesPoolItemRelease(item);
 *     }
 *
 *     // Free the pool of resources
 *     fiftyoneDegreesPoolFree(&pool);
 * }
 * ```
 *
 * ## Design
 *
 * To improve performance in multi-threaded operation a non locking stack is 
 * used where a Compare and Swap (CAS) atomic operation is used to pop and push 
 * handles on and off the stack. The design was adapted from the following 
 * article (http://nullprogram.com/blog/2014/09/02/) which explains some of the 
 * challenges involved including the ABA problem 
 * (https://en.wikipedia.org/wiki/ABA_problem). It is for this reason the head 
 * structure is implemented as a union between the values and the exchange
 * integer. Pointers are not used as the address space for the stack is 
 * continuous and always very small compared to the total addressable memory 
 * space.
 *
 * @{
 */

#include <stdio.h>
#include <errno.h>
#include <stdint.h>
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable: 5105) 
#include <windows.h>
#pragma warning (default: 5105) 
#pragma warning (pop)
#endif
#include <assert.h>
#include <limits.h>
#ifndef FIFTYONE_DEGREES_NO_THREADING
#endif

 /** @cond FORWARD_DECLARATIONS */
typedef struct fiftyone_degrees_pool_item_t fiftyoneDegreesPoolItem;
typedef struct fiftyone_degrees_pool_t fiftyoneDegreesPool;
/** @endcond */

/**
 * Used to create a new resource for use in the pool.
 * @param pool to create the resource for
 * @param state pointer to data used by the method
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h
 * @return pointer to the new resource
 */
typedef void*(*fiftyoneDegreesPoolResourceCreate)(
	fiftyoneDegreesPool *pool,
	void *state,
	fiftyoneDegreesException *exception);

/**
 * Used to determine the additional size beyond the pointer used for each 
 * resource added to the pool.
 * @param state pointer to a state containing the resource and any additional
 * data needed for the calculation
 * @return addition size to allocate per resource
 */
typedef size_t(*fiftyoneDegreesPoolResourceSize)(void *state);

/**
 * Frees a resource previously created with #fiftyoneDegreesPoolResourceCreate.
 * @param pool containing the resource
 * @param resource to free
 */
typedef void(*fiftyoneDegreesPoolResourceFree)(
	fiftyoneDegreesPool *pool, 
	void *resource);

/**
 * Pool item node in the stack of items.
 */
typedef struct fiftyone_degrees_pool_item_t {
	void *resource; /**< Pointer to the resource in the pool */
	uint16_t next; /**< The next item in the stack */
	fiftyoneDegreesPool *pool; /**< Reader the handle belongs to */
} fiftyoneDegreesPoolItem;

/**
 * The head of the stack used for pop and push operations.
 */
typedef union fiftyone_degrees_pool_head_t {
	volatile long exchange; /**< Number used in the compare exchange operation */
	struct {
		uint16_t index; /**< Index of the item in the linked list */
		uint16_t aba; /**< ABA value used to ensure proper operation */
	} values; /**< Value index with its ABA value */
} fiftyoneDegreesPoolHead;

/**
 * Pool of resources stored as items in a stack.
 */
typedef struct fiftyone_degrees_pool_t {
	fiftyoneDegreesPoolItem *stack; /**< Pointer to the memory used by the
									    stack */
	fiftyoneDegreesPoolHead head; /**< Head of the stack */
	uint16_t count; /**< Number of resource items that stack can hold */
	fiftyoneDegreesPoolResourceFree resourceFree; /**< Frees a resource */
} fiftyoneDegreesPool;

/**
 * Initialises a pool data structure to support the number of concurrent
 * requests that can be made to the pool for resources that can be reused. 
 * The resourceCreate method is used to create a new resource for use in the 
 * pool which will be freed during when the release method is called on the
 * pool using the resourceFree method.
 * @param pool data structure to be initialised.
 * @param concurrency the number of resources the pool should contain.
 * @param state passed to the create resource method.
 * @param resourceCreate method used to create the resource to be added to 
 * items in the pool.
 * @param resourceFree method used to free a resource from the pool when the 
 * pool is freed.
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return a pointer to the pool if successful, otherwise NULL.
 */
EXTERNAL fiftyoneDegreesPool* fiftyoneDegreesPoolInit(
	fiftyoneDegreesPool *pool,
	uint16_t concurrency,
	void *state,
	fiftyoneDegreesPoolResourceCreate resourceCreate,
	fiftyoneDegreesPoolResourceFree resourceFree,
	fiftyoneDegreesException *exception);

/**
 * Gets the next free item from the pool for exclusive use by the caller. Every 
 * item returned must be released when the caller has finished with it using 
 * the #fiftyoneDegreesPoolItemRelease method.
 * @param pool to return items from.
 * @param exception pointer to an exception data structure to be used if an 
 * exception occurs. See exceptions.h.
 * @return the next free item, or NULL if no items are available.
 */
EXTERNAL fiftyoneDegreesPoolItem* fiftyoneDegreesPoolItemGet(
	fiftyoneDegreesPool *pool,
	fiftyoneDegreesException *exception);

/**
 * Releases the item back to the pool it belongs ready to be reused by another
 * operation.
 * @param item to be released back to the pool
 */
EXTERNAL void fiftyoneDegreesPoolItemRelease(fiftyoneDegreesPoolItem* item);

/**
 * Releases the items used by the pool freeing the resources used by each
 * item by calling the resourceFree method provided when the pool was created.
 * @param pool to be freed
 */
EXTERNAL void fiftyoneDegreesPoolFree(fiftyoneDegreesPool* pool);

/**
 * Resets the pool without releasing any resources.
 * @param pool to be reset
 */
EXTERNAL void fiftyoneDegreesPoolReset(fiftyoneDegreesPool *pool);

/**
 * @}
 */

#endif

/**
 * Platform specific method pointer to return the current working directory.
 */
#ifdef _MSC_FULL_VER
#define GET_CURRENT_DIR _getcwd
#pragma warning (push)
#pragma warning (disable: 5105) 
#include <windows.h>
#pragma warning (default: 5105) 
#pragma warning (pop)
#include <direct.h>
#include <tchar.h>
#else
#define GET_CURRENT_DIR getcwd
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#endif

#define TEMP_UNIQUE_STRING_LENGTH 20

/**
 * Define the max path length on the target system. For Windows this is 
 * `260` characters, and `4096` on most UNIX systems. The compiler defined
 * values are not used here as although Windows MSVC always defined
 * `_MAX_PATH`, UNIX systems do not consistently define the `PATH_MAX` macro
 * resulting in undefined behavior. For this reason the length of `4096` is
 * used as this is almost always the case.
 */
#ifdef _MSC_FULL_VER
#define FIFTYONE_DEGREES_FILE_MAX_PATH 260
#else
#define FIFTYONE_DEGREES_FILE_MAX_PATH 4096
#endif


/**
 * File handle node in the stack of handles.
 */
typedef union fiftyone_degrees_file_handle_t {
	FILE *file; /**< Open read handle to the source data file. */
	fiftyoneDegreesPoolItem item; /**< The pool item with the resource. */
} fiftyoneDegreesFileHandle;

/**
 * Stack of handles used to read data from a single source file.
 */
 typedef struct fiftyone_degrees_file_pool_t {
	 fiftyoneDegreesPool pool; /**< The pool of file handles */
	 fiftyoneDegreesFileOffset length; /**< Length of the file in bytes */
} fiftyoneDegreesFilePool;

/**
 * Moves the file pointer to a specified location.
 * @param stream Pointer to FILE structure.
 * @param offset Number of bytes from origin.
 * @param origin Initial position.
 * @return 
 */
EXTERNAL int fiftyoneDegreesFileSeek(
   FILE *stream,
   fiftyoneDegreesFileOffset offset,
   int origin);

/**
 * Gets the current position of a file pointer.
 * @param stream Target FILE structure.
 * @return The current file position.
 */
EXTERNAL fiftyoneDegreesFileOffset fiftyoneDegreesFileTell(
   FILE *stream
);

/**
 * Releases the file handles contained in the pool and frees any internal
 * memory used by the pool. Does not free the memory pointed to by pool.
 * @param pool pointer to the stack of file handles to be release
 */
EXTERNAL void fiftyoneDegreesFilePoolRelease(fiftyoneDegreesFilePool* pool);

/**
 * Opens the file path provided placing the file handle in the handle
 * parameter.
 * @param fileName full path to the file to open
 * @param handle to be associated with the open file
 * @return the result of the open operation
 */
EXTERNAL fiftyoneDegreesStatusCode fiftyoneDegreesFileOpen(
	const char* fileName,
	FILE** handle);

/**
 * Writes binary data to the file path provided, closing the file once finished.
 * @param fileName full path to the file to write to
 * @param data binary data to write
 * @param length the number of bytes in the data to be written
 * @return the result of the write operation
 */
EXTERNAL fiftyoneDegreesStatusCode fiftyoneDegreesFileWrite(
	const char* fileName,
	const void *data,
	const size_t length);

/**
 * Copy a file from one location to another. If there was an error while
 * creating or copying the file, then the appropriate status code will be
 * returned. If the status code is anything other than
 * #FIFTYONE_DEGREES_STATUS_SUCCESS then the new file will not exist.
 * @param source path to the file to copy
 * @param destination path to the file to create
 * @return the result of the copy operation
 */
EXTERNAL fiftyoneDegreesStatusCode fiftyoneDegreesFileCopy(
	const char *source,
	const char *destination);

/**
 * Delete a file from the file system. If there was an error while removing the
 * file, then the appropriate status code will be returned.
 * @param fileName path to the file to be deleted
 * @return the result of the delete operation 
 */
EXTERNAL fiftyoneDegreesStatusCode fiftyoneDegreesFileDelete(
	const char *fileName);

/**
 * Creates a directory with the specified path, and returns the result of the
 * operation. intermediate directories will not be created.
 * @param pathName path to create
 * @return the result of the operation
 */
EXTERNAL fiftyoneDegreesStatusCode fiftyoneDegreesFileCreateDirectory(
	const char *pathName);

/**
 * Iterates up the folders from the current working directory until a file
 * in the sub folder dataFolderName with the name fileName is found which
 * can be opened. This is assumed to be the data file required by the caller.
 * Enough memory must be allocated to the destination parameter for the full
 * path to be written. The maximum path length is defined by the macro
 * `FIFTYONEDEGREES_FILE_MAX_PATH`.
 * @param dataFolderName the name of the sub folder which is expected to 
 * contain the data file
 * @param fileName the name of the data file
 * @param destination memory to write the absolute path to if the file was
 * found
 * @param size the number of bytes assigned to the destination pointer
 * @return the result of the operation
 */
EXTERNAL fiftyoneDegreesStatusCode fiftyoneDegreesFileGetPath(
	const char *dataFolderName,
	const char *fileName,
	char *destination,
	size_t size);

/**
 * Gets the path to a temporary file which is an exact copy of the master file
 * if one exists. If one is found, true is returned and the path written to the
 * memory pointed to by the destination parameter. If the file found has the
 * same name as the master file, then false is returned to avoid the same file
 * being treated as if it were a copy by external code.
 * If no paths are provided, then the working directory is searched.
 * @param masterFile path to the master file to find a temp version of
 * @param paths list of paths to search in order of preference
 * @param count number of paths in the array
 * @param bytesToCompare number of from the start of the file to compare for
 * equality with the master file, or -1 to compare the whole file
 * @param destination memory to write the found file path to
 * @return true if a copy of the master file was found, and its path written to
 * destination
 */
EXTERNAL bool fiftyoneDegreesFileGetExistingTempFile(
	const char *masterFile,
	const char **paths,
	int count,
	fiftyoneDegreesFileOffset bytesToCompare,
	const char *destination);

/**
 * Finds all the temporary files which is an exact copy of the master file
 * if any exist. If any are found, the method attempts to delete them. The
 * number of successfully deleted temp files is returned. If any files found
 * have the same name as the master file, then false is returned to avoid the
 * same file being treated as if it were a copy by external code.
 * If no paths are provided, then the working directory is searched. Note that
 * this should not be used on Apple systems, as the checks for whether or not
 * a file is in use are not implemented (all files will be deleted regardless
 * of whether they are being used).
 * @param masterFileName path to the master file to find a temp version of
 * @param paths list of paths to search in order of preference
 * @param count number of paths in the array
 * @param bytesToCompare number of from the start of the file to compare for
 * equality with the master file, or -1 to compare the whole file
 * @return the number of matching files which have been successfully deleted
 */
EXTERNAL int fiftyoneDegreesFileDeleteUnusedTempFiles(
	const char *masterFileName,
	const char **paths,
	int count,
	fiftyoneDegreesFileOffset bytesToCompare);

/**
 * Create a temporary file name and add it to the destination.
 * @param masterFileName basename of the master file
 * @param destination buffer to write the temporary file name to
 * @param nameStart position of where the name should be added to the destination
 * @param length length available in the buffer
 * @return the result of the file name creation
 */
EXTERNAL fiftyoneDegreesStatusCode fiftyoneDegreesFileAddTempFileName(
	const char* masterFileName,
	char* destination,
	size_t nameStart,
	size_t length);

/**
 * Create a temporary file containing a copy of the master file using the first
 * writable path in the list of paths provided. The path which is written to
 * (including file name) is written to the destination parameter which must
 * contain enough memory.
 * If no paths are provided, then the working directory used as the destination.
 * @param masterFile full path to the file containing the master data to copy
 * @param paths list of paths to use in order of preference
 * @param count number of paths in the array
 * @param destination memory to write the new file path to
 * @param length size of the memory to be written to
 * @return the result of the create operation
 */
EXTERNAL fiftyoneDegreesStatusCode fiftyoneDegreesFileNewTempFile(
	const char* masterFile,
	const char** paths,
	int count,
	char* destination,
	size_t length);

/**
 * [DEPRECATED - Use #fiftyoneDegreesFileNewTempFile instead]
 * Create a temporary file containing a copy of the master file using the first
 * writable path in the list of paths provided. The path which is written to
 * (including file name) is written to the destination parameter which must
 * contain enough memory.
 * If no paths are provided, then the working directory used as the destination.
 * @param masterFile full path to the file containing the master data to copy
 * @param paths list of paths to use in order of preference
 * @param count number of paths in the array
 * @param destination memory to write the new file path to
 * @return the result of the create operation
 */
EXTERNAL DEPRECATED fiftyoneDegreesStatusCode fiftyoneDegreesFileCreateTempFile(
	const char *masterFile,
	const char **paths,
	int count,
	const char *destination);

/**
 * Initialises the pool with a stack of open read only file handles all 
 * associated with the file name. The concurrency parameter determines the 
 * number of items in the stack.
 * @param filePool to be initialised
 * @param fileName full path to the file to open
 * @param concurrency number of items in the stack
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return the result of the open operation
 */
EXTERNAL fiftyoneDegreesStatusCode fiftyoneDegreesFilePoolInit(
	fiftyoneDegreesFilePool *filePool,
	const char *fileName,
	uint16_t concurrency,
	fiftyoneDegreesException *exception);

/**
 * Retrieves a read only open file handle from the pool. The handle retrieve
 * must be returned to the pool using #fiftyoneDegreesFileHandleGet and must
 * not be freed or closed directly.
 * @param filePool to retrieve the file handle from
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return a read only open file handle or NULL if no available handles remain
 * in the pool
 */
EXTERNAL fiftyoneDegreesFileHandle* fiftyoneDegreesFileHandleGet(
	fiftyoneDegreesFilePool *filePool,
	fiftyoneDegreesException *exception);

/**
 * Returns a handle previously retrieved via #fiftyoneDegreesFileHandleGet back
 * to the pool.
 * @param handle to be returned to the pool
 */
EXTERNAL void fiftyoneDegreesFileHandleRelease(
	fiftyoneDegreesFileHandle* handle);

/**
 * Returns the size of a file in bytes, or -1 if the file does not exist or
 * cannot be accessed.
 * @param fileName path to the file
 * @return size of file in bytes or -1
 */
EXTERNAL fiftyoneDegreesFileOffset fiftyoneDegreesFileGetSize(const char *fileName);

/**
 * Reads the contents of a file into memory. The correct amount of memory will
 * be allocated by the method. This memory needs to be freed by the caller
 * after the data has been finished with.
 * @param fileName path to the source file
 * @param reader to contain the pointer to the memory and the size
 * @return status code indicating whether the read was successful
 */
EXTERNAL fiftyoneDegreesStatusCode fiftyoneDegreesFileReadToByteArray(
	const char *fileName,
	fiftyoneDegreesMemoryReader *reader);

/**
 * Resets the pool without releasing any resources.
 * @param filePool to be reset.
 */
EXTERNAL void fiftyoneDegreesFilePoolReset(fiftyoneDegreesFilePool *filePool);

/**
 * Gets the last, file name, segment of the full file path.
 * @param filePath full path to the file.
 * @return the file name from the file path.
 */
EXTERNAL const char* fiftyoneDegreesFileGetFileName(const char *filePath);

/**
 * @}
 */
#endif
/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2023 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

#ifndef FIFTYONE_DEGREES_COLLECTION_H_INCLUDED
#define FIFTYONE_DEGREES_COLLECTION_H_INCLUDED

/**
 * @ingroup FiftyOneDegreesCommon
 * @defgroup FiftyOneDegreesCollection Collection
 *
 * Group of related items such as strings.
 *
 * ## Terms
 *
 * **Collection** : a group of items that share a common data structure.
 *
 * **Item** : an immutable entity within the collection. The number of bytes
 * used to store the item may be either fixed or variable.
 *
 * **Get** : returns an immutable Item that must be released when the caller is
 * finished with it.
 *
 * **Release** : releases a lock on the Item returned from the Get operation.
 *
 * **Index** : where the Item data uses a fixed number of bytes the index of
 * the item in the Collection.
 *
 * **Offset** : where items do not share the same number of data bytes the 0
 * based offset to the Item from the start of the collection’s data (after any
 * header).
 * 
 * ## Introduction
 * 
 * A Collection is a group of related Items such as strings or properties where 
 * the consumer wishes to access the items without concern for the underlying 
 * storage mechanism and memory management. Immutable items can be retrieved 
 * (Get) from the collection which **MUST** be released once the caller has
 * finished with the data.
 * 
 * In some configurations it may be more efficient to load all related Items
 * into memory in a continuous address space exactly matching the data structure
 * used in the source data. In others it may be desirable to only load in memory
 * the Items from the source data when required. In all configurations the 
 * logical methods to retrieve and release these items are identical.
 * 
 * The methods in the Collection abstract the implementation for collection of 
 * items to support the following configurations:
 * 
 * **Memory** : all the Items in the Collection are held in a continuous
 * address  space. The fastest access option where all memory can be allocated
 * during initialisation.
 * 
 * **File** : none of the Items are loaded into memory and they are retrieved
 * from the data source when required. The slowest access option but the most
 * memory efficient. The memory needed to store the item is allocated when the
 * Item is requested and deallocated when released.
 * 
 * **Cache** : a hybrid mode where the Least Recently Used (LRU) cache is used
 * to store a limited number of Items in memory. Cache is a compromise between
 * in memory and file based configurations. Unlike Memory and File the cache
 * needs to be locked when accessed for both Get and Release and performance
 * may degrade when used in a multi threaded configuration.
 * 
 * Sometimes it may be desirable to use multiple configurations of Collection
 * with the same underlying data. Consider a data structure where the most 
 * frequently required Items exist at the start of the structure. These Items
 * would benefit from being held in memory for fast retrieval whilst the
 * remaining Items which may be infrequently required are cached or loaded when 
 * needed from the file. For these situations Collections can be chained
 * together such that the first Collection may not contain data for the
 * requested index or offset and can pass the retrieval to the next Collection
 * in the chain. It is important to note that all chained Collections must be a
 * subset of the final Collection in the chain (as opposed to additional 
 * Collections), i.e. all elements are 'gettable' from the final Collection.
 * 
 * Once a Collection is created the only methods that should be used to access 
 * data are those exposed in the fiftyoneDegreesCollection instance. It is for 
 * this reason the collection.h file exposes so few external methods.
 * 
 * ## Creation
 * 
 * There are two Collection creation methods:

 * ### #fiftyoneDegreesCollectionCreateFromMemory  
 * 
 * Creates a Collection that is created to access memory that is already
 * allocated in continuous memory simply maps to this memory and provides 
 * relatively simple methods to retrieve Items. No reference to the underlying 
 * data file or source is required but the memory must already be allocated.
 * 
 * ### #fiftyoneDegreesCollectionCreateFromFile 
 * 
 * A Collection mapped to a data file is more complex than the memory method
 * and a greater set of creation configuration features are required. For
 * example; caching options or how many Items at the start of the Collection to
 * store in memory.
 * 
 * A #fiftyoneDegreesCollectionConfig structure is used to configure the 
 * operation of the resulting Collection. This structure has the following 
 * fields.
 * 
 * **loaded** : the number of Items to load into memory from the start of the
 * Collection’s data structure.
 *
 * **capacity** : 0 if a cache should not be used, otherwise the capacity of
 * cache.

 * **concurrency** : the expected number of concurrent operations, 1 or greater.
 * 
 * The file create method will work out the different types of Collection(s)
 * needed and how to chain them based on the configuration provided.
 * 
 * Additionally, a pointer to a method to read an Item into the Collection from 
 * the underlying data file is required. For fixed width Collections the 
 * fiftyoneDegreesCollectionReadFileFixed can be used where the Item key is the
 * zero based index in the Collection. For variable byte width Collections the
 * consumer will need to provide a method that implements
 * #fiftyoneDegreesCollectionFileRead. 
 * 
 * All creation methods return a pointer to an instance of 
 * #fiftyoneDegreesCollection. Following creation only the methods exposed by 
 * this Collection should be used to retrieve and release Items.
 * 
 * ## Free
 * 
 * The freeCollection method of the Collection must be called when the
 * Collection is finished with. After this method is called the Collection data
 * structure and all owned data will be released.
 * 
 * ## Get & Release
 * 
 * All operations that retrieve data from the Collection require an instance of
 * #fiftyoneDegreesCollectionItem to be passed. Items can be reused across
 * multiple Get and Release operations to reduce the frequency of memory
 * allocations. Items contain a handle to the underlying data which might be
 * used during the Release operation.
 *
 * ## Usage Example
 *
 * ```
 * FILE *file;
 * fiftyoneDegreesFilePool *filePool;
 * FIFTYONE_DEGREES_EXCEPTION_CREATE;
 * const fiftyoneDegreesCollectionConfig *config;
 * fiftyoneDegreesCollectionItem item;
 *
 * // Read the collection header from file which contains 32 bit integers
 * fiftyoneDegreesCollectionHeader *header = fiftyoneDegreesCollectionHeaderFromFile(
 *     file,
 *     sizeof(int32_t),
 *     true);
 *
 * // Create the collection from a file which contains 32 bit integers
 * fiftyoneDegreesCollection *collection = fiftyoneDegreesCollectionCreateFromFile(
 *     file,
 *     filePool,
 *     config,
 *     header,
 *     fiftyoneDegreesCollectionGetInteger32);
 *
 * // Check the collection was create successfully
 * if (collection != NULL) {
 *
 *     // Initialise the item ready to store data from the collection
 *     fiftyoneDegreesDataReset(&item.data);
 *
 *     // Get a pointer to the value from the collection
 *     int32_t *valuePtr = collection->get(
 *         collection,
 *         0,
 *         &item,
 *         exception);
 *
 *     // Check the value was returned
 *     if (valuePtr != NULL) {
 *
 *         // Get the value from the pointer
 *         int32_t value = *valuePtr;
 *
 *         // Release the value back to the collection
 *         FIFTYONE_DEGREES_COLLECTION_RELEASE(collection, &item);
 *     }
 *
 *     // Free the collection
 *     FIFTYONE_DEGREES_COLLECTION_FREE(collection);
 * }
 * ```
 *
 * ## Important Considerations
 * 
 * The Item passed to the Get method **MUST** have had
 * #fiftyoneDegreesDataReset called on the data field before use to set the
 * default field values. Without this reset the Collection will not know if it
 * can reuse any memory already allocated from a previous Get operation that is
 * no longer being referenced. For example, if a large string was loaded into
 * an Item, and the Item is then reused for a shorter string, there is no need
 * to reallocate memory. Therefore, the same memory is reused.
 * 
 * The get and release methods of the collection are the only methods that 
 * should be used to retrieve items from a collection. An item retrieved with 
 * the get method **MUST** be released when finished with via a call to the 
 * collection’s release method.
 * 
 * A call to Get **DOES NOT** need to set the Collection field of the Item.
 * Collection is not a mandatory field to avoid the overhead of setting the
 * Collection field where the Collection’s implementation of the Release method
 * does nothing. This is important to avoid a performance penalty when all
 * Collection data is in memory and does not need to be released. For this
 * reason the consumer must always reference the Collection directly and not
 * via the Collection field of the Item. The Collection field is used by 
 * some internal 51Degrees method where a specific Get method is used that will
 * always set the Collection.
 *
 * @{
 */

 /* Define NDEBUG if needed, to ensure asserts are disabled in release builds */
#if !defined(DEBUG) && !defined(_DEBUG) && !defined(NDEBUG)
#define NDEBUG
#endif

/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2023 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

/**
 * @ingroup FiftyOneDegreesCommon
 * @defgroup FiftyOneDegreesCache Cache
 *
 * Fixed size, thread safe, loading, tree based cache.
 *
 * ## Introduction
 *
 * Implements a fixed size, thread safe, loading, tree based cache. Items
 * requested which are not in the cache already are loaded using the specified
 * load method, before returning as with items which are already in the cache.
 *
 * Items are fetched from the cache using the #fiftyoneDegreesCacheGet method
 * and the item is prevented from being expelled from the cache until the 
 * #fiftyoneDegreesCacheRelease method is called. Failure to release cache
 * items once they are finished with will result in the available nodes in the
 * cache being exhausted (i.e. no new items can be loaded into the cache).
 *
 * As the cache is fixed size, the size must be set correctly in order to
 * prevent failures in the get method. The size of a cache **MUST** be equal to
 * or greater than the maximum number of items which will be in use
 * simultaneously across all threads. Fetching more items than the cache was
 * created to expect will result in the same failure as not releasing items.
 *
 * The cache is sharded based on the modulo of the key to improve performance
 * in multi threaded operation where an even distribution of key modulos are
 * present.
 *
 * Details of the red black tree implementation can be found in tree.c.
 *
 * ## Example Usage
 *
 * ```
 * byte *data;
 * fiftyoneDegreesCacheLoadMethod *methodToLoadEntryFromData;
 *
 * // Create a cache
 * fiftyoneDegreesCache cache = fiftyoneDegreesCacheCreate(
 *      100,
 *      1,
 *      methodToLoadEntryFromData,
 *      fiftyoneDegreesCacheHash64,
 *      data);
 *
 * // Get an item from the cache
 * fiftyoneDegreesCacheNode *entry = fiftyoneDegreesCacheGet(
 *     cache,
 *     &0,
 *     exception);
 *
 * // Check that the value was found
 * if (entry != NULL) {
 *
 *     // Get the value from the entry
 *     int *value = (int*)entry->data.ptr;
 *
 *     // Do something with the value
 *     // ...
 *
 *     // Release the entry back to the cache
 *     fiftyoneDegreesCacheRelease(entry);
 * }
 *
 * // Free the cache
 * fiftyoneDegreesCacheFree(cache);
 * ```
 * @{
 */

#ifndef FIFTYONE_DEGREES_CACHE_H_INCLUDED
#define FIFTYONE_DEGREES_CACHE_H_INCLUDED

/* Define NDEBUG if needed, to ensure asserts are disabled in release builds */
#if !defined(DEBUG) && !defined(_DEBUG) && !defined(NDEBUG)
#define NDEBUG
#endif

#include <stdint.h>
#include <stdbool.h>

#ifdef _MSC_VER
#endif
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable: 5105) 
#include <windows.h>
#pragma warning (default: 5105) 
#pragma warning (pop)
#endif
#include <assert.h>

#ifndef FIFTYONE_DEGREES_NO_THREADING
#endif

/** @cond FORWARD_DECLARATIONS */
typedef struct fiftyone_degrees_cache_node_t fiftyoneDegreesCacheNode;
typedef struct fiftyone_degrees_cache_shard_t fiftyoneDegreesCacheShard;
typedef struct fiftyone_degrees_cache_t fiftyoneDegreesCache;
/** @endcond */

/**
 * Cache node structure used for storing data in the cache along with
 * its key.
 */
typedef struct fiftyone_degrees_cache_node_t {
	fiftyoneDegreesTreeNode tree; /**< Tree node for this cache node */
	fiftyoneDegreesData data; /**< Data contained in the node */
	fiftyoneDegreesCacheShard *shard; /**< Shard the node is associated with */
	fiftyoneDegreesCacheNode *listPrevious; /**< Previous node or NULL if first */
	fiftyoneDegreesCacheNode *listNext; /**< Next node or NULL if last */
	int activeCount; /**< Number of external references to the node data */
} fiftyoneDegreesCacheNode;

/**
 * Cache shard structure used to enable concurrent access to the cache.
 */
typedef struct fiftyone_degrees_cache_shard_t {
	fiftyoneDegreesCache *cache; /**< Pointer to the cache to which the node
								     belongs */
	fiftyoneDegreesTreeRoot root; /**< Root node of the red black tree */
	uint32_t capacity; /**< Capacity of the shard */
	uint32_t allocated; /**< Number of nodes currently used in the shard */
	fiftyoneDegreesCacheNode *nodes; /**< Pointer to the array of all nodes */
	fiftyoneDegreesCacheNode *first; /**< Pointer to the first node in the
									     linked list */
	fiftyoneDegreesCacheNode *last; /**< Pointer to the last node in the
									    linked list */
#ifndef FIFTYONE_DEGREES_NO_THREADING
	fiftyoneDegreesMutex lock; /**< Used to ensure exclusive access to the
								   shard for get and release operations */
#endif
} fiftyoneDegreesCacheShard;

/**
 * Method used to load data into the cache.
 * @param state information used for the load operation.
 * @param data structure to be used to store the data loaded.
 * @param key for the item in the collection to be loaded.
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 */
typedef void(*fiftyoneDegreesCacheLoadMethod)(
	const void *state,
	fiftyoneDegreesData *data,
	const void *key,
	fiftyoneDegreesException *exception);

/**
 * Method used to calculate a hash code from the key.
 * @param key the data to be calculate the integer key.
 * @return 64 bit representation of the key data.
 */
typedef int64_t(*fiftyoneDegreesCacheHashCodeMethod)(const void* key);

/**
 * Cache structure to store the root of the red black tree and a list of
 * allocated cache nodes. This also contains cache metrics and pointers to
 * methods used when being used as a loading cache.
 */
typedef struct fiftyone_degrees_cache_t {
	fiftyoneDegreesCacheShard *shards; /**< Array of shards / concurrency */
	fiftyoneDegreesCacheNode *nodes; /**< Array of nodes / capacity */
	uint16_t concurrency; /**< Expected concurrency and number of shards */
	int32_t capacity; /**< Capacity of the cache */
	unsigned long hits; /**< The requests served from the cache */
	unsigned long misses; /**< The requests NOT served from the cache */
	fiftyoneDegreesCacheLoadMethod load; /**< Used by the cache to load an item
										 into the cache */
	fiftyoneDegreesCacheHashCodeMethod hash; /**< Used to hash a key pointer */
	const void* loaderState; /**< Cache loader specific state */
} fiftyoneDegreesCache;

/**
 * Creates a new cache.The cache must be destroyed with the
 * #fiftyoneDegreesCacheFree method.
 * @param capacity maximum number of items that the cache should store
 * @param concurrency the expected number of parallel operations
 * @param load pointer to method used to load an entry into the cache
 * @param hash pointer to a method used to hash the key into a int64_t
 * @param state pointer to state information to pass to the load method
 * @return a pointer to the cache created, or NULL if one was not created.
 */
EXTERNAL fiftyoneDegreesCache *fiftyoneDegreesCacheCreate(
	uint32_t capacity,
	uint16_t concurrency,
	fiftyoneDegreesCacheLoadMethod load,
	fiftyoneDegreesCacheHashCodeMethod hash,
	const void *state);

/**
 * Frees the cache structure, all allocated nodes and their data.
 * @param cache to be freed
 */
EXTERNAL void fiftyoneDegreesCacheFree(fiftyoneDegreesCache *cache);

/**
 * Gets an item from the cache. If an item is not in the cache, it is loaded
 * using the loader the cache was initialized with.
 *
 * The cache being used as a loading cache must have a load method defined
 * which returns a pointer to the data relating to the key used. This method
 * may, or may not, allocate memory or free memory previously allocated to
 * data in the cache node.
 *
 * Nodes fetched from the cache are protected from modification until all
 * references to them are released. This means that the size of the cache must
 * be carefully chosen to be no smaller than the maximum number of nodes which
 * may be in use at any one time. Attempting to fetch a node when there are no
 * free nodes to load the data into will result in a null being returned.
 *
 * @param cache to get the entry from
 * @param key for the item to be returned
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return pointer to the requested item or null if too many items have been 
 * fetched and not released or the key is not valid
 */
EXTERNAL fiftyoneDegreesCacheNode* fiftyoneDegreesCacheGet(
	fiftyoneDegreesCache *cache,
	const void *key,
	fiftyoneDegreesException *exception);

/**
 * Releases the cache node previous obtained via #fiftyoneDegreesCacheGet so 
 * that it can be evicted from the cache if needed.
 * @param node to be released.
 */
EXTERNAL void fiftyoneDegreesCacheRelease(fiftyoneDegreesCacheNode *node);

/**
 * Passed a pointer to a 32 bit / 4 byte data structure and returns the data as
 * a 64 bit / 8 byte value for use in the cache. Used when cache keys are 32 
 * bit integers.
 * @param key to be used in the cache
 * @return key represented as a 64 bit integer
 */
EXTERNAL int64_t fiftyoneDegreesCacheHash32(const void *key);

/**
 * Passed a pointer to a 64 bit / 8 byte data structure and returns the data as
 * a 64 bit / 8 byte value for use in the cache. Used when cache keys are 64
 * bit integers.
 * @param key to be used in the cache
 * @return key represented as a 64 bit integer
 */
EXTERNAL int64_t fiftyoneDegreesCacheHash64(const void *key);

/**
 * @}
 */
#endif
#include <stdio.h>
#include <string.h>

/**
 * Free a collection by checking if it is NULL first.
 * @param c collection to free
 */
#define FIFTYONE_DEGREES_COLLECTION_FREE(c) \
if (c != NULL) { c->freeCollection(c); }

/**
 * Collection release macro used to release a collection item. This should
 * always be used in place of the release method to enable methods to be
 * optimised out at compile time when memory only mode is set.
 * @param c collection the item belongs to
 * @param i item to release
 */
#ifndef FIFTYONE_DEGREES_MEMORY_ONLY
#define FIFTYONE_DEGREES_COLLECTION_RELEASE(c, i) c->release(i)
#else
#define FIFTYONE_DEGREES_COLLECTION_RELEASE(c, i)
#endif

/**
 * Collection header structure which defines the size and location of the
 * collection data.
 */
#pragma pack(push, 1)
typedef struct fiftyone_degrees_collection_header_t {
	fiftyoneDegreesFileOffsetUnsigned startPosition; /**< Start position in the data file of the entities */
	uint32_t length; /**< Length in bytes of all the entities */
	uint32_t count; /**< Number of entities in the collection */
} fiftyoneDegreesCollectionHeader;
#pragma pack(pop)

/**
 * Collection configuration structure which defines how the collection should
 * be created by the create methods.
 */
typedef struct fiftyone_degrees_collection_config_t {
	uint32_t loaded; /**< Number of items to load into memory from the start of
					     the collection */
	uint32_t capacity; /**< Number of items the cache should store, 0 for no
	                       cache */
	uint16_t concurrency; /**< Expected number of concurrent requests, 1 or
						      greater */
} fiftyoneDegreesCollectionConfig;

/** @cond FORWARD_DECLARATIONS */
typedef struct fiftyone_degrees_collection_t fiftyoneDegreesCollection;
typedef struct fiftyone_degrees_collection_item_t fiftyoneDegreesCollectionItem;
typedef struct fiftyone_degrees_collection_file_t fiftyoneDegreesCollectionFile;
/** @endcond */

/**
 * Used to store a handle to the underlying item that could be used to release
 * the item when it's finished with. Also contains a reference to the data 
 * structure used to handle memory allocation enabling memory to be reused
 * across multiple gets reducing the frequency of memory operations.
 */
typedef struct fiftyone_degrees_collection_item_t {
	fiftyoneDegreesData data; /**< Item data including allocated memory */
	void *handle; /**< A handle that relates to the data. i.e. a cache node */
	fiftyoneDegreesCollection *collection; /**< Collection the item came from
	                                           which may not have been set.
	                                           Should not be used by external
	                                           code */
} fiftyoneDegreesCollectionItem;

/**
 * Gets an item from the collection. Returns a pointer to the item, or NULL
 * if the item could not be loaded. The exception parameter is set to the 
 * status code to indicate the failure.
 * @param collection pointer to the file collection
 * @param indexOrOffset index or offset to the item in the data structure
 * @param item pointer to the item structure to place the result in
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return the value in the data->ptr field, or NULL if not successful
 */
typedef void* (*fiftyoneDegreesCollectionGetMethod)(
	fiftyoneDegreesCollection *collection,
	uint32_t indexOrOffset,
	fiftyoneDegreesCollectionItem *item,
	fiftyoneDegreesException *exception);

/**
 * Passed a pointer to the first part of a variable size item and returns
 * the size of the entire item.
 * @param initial pointer to the start of the item
 * @return size of the item in bytes
 */
typedef uint32_t (*fiftyoneDegreesCollectionGetFileVariableSizeMethod)(
	void *initial);

/**
 * Reads the item from the underlying data file. Used by the file related
 * collection methods.
 * @param collection pointer to the file collection
 * @param offsetOrIndex index or offset to the item in the data structure
 * @param data pointer to the data structure to store the item
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return the value in the data->ptr field, or NULL if not successful
 */
typedef void* (*fiftyoneDegreesCollectionFileRead)(
	const fiftyoneDegreesCollectionFile *collection,
	uint32_t offsetOrIndex,
	fiftyoneDegreesData *data,
	fiftyoneDegreesException *exception);

/**
 * Compares two items and returns the difference between them for the purposes
 * of a binary search of ordering operation.
 * @param state to be used for the comparison
 * @param item the value to compare against the state
 * @param curIndex the index of the current item in the collection
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h
 * @return negative if a is lower than b, positive if a is higher than b or 0 
 * if equal.
 */
typedef int(*fiftyoneDegreesCollectionItemComparer)(
	void *state,
	fiftyoneDegreesCollectionItem *item,
	long curIndex,
	fiftyoneDegreesException *exception);

/**
 * Releases the item so that the collection can free the memory or take
 * other actions when the caller no longer needs access to the item.
 * @param item the item returned from Get to be released
 */
typedef void (*fiftyoneDegreesCollectionReleaseMethod)(
	fiftyoneDegreesCollectionItem* item);

/**
 * Frees all the memory and handles associated with the collection.
 * @param collection the collection to be freed
 */
typedef void(*fiftyoneDegreesCollectionFreeMethod)(
	fiftyoneDegreesCollection* collection);

/**
 * Method used to iterate over data held in a collection.
 * @param state state data for all callbacks
 * @param key the key used with get method of the item being returned
 * @param data data for the specific item
 * @return true if the iteration should continue, otherwise false to stop it
 */
typedef bool(*fiftyoneDegreesCollectionIterateMethod)(
	void *state,
	uint32_t key,
	void *data);

/**
 * All the shared methods and fields required by file, memory and cached
 * collections. The state field points to the specific collection data 
 * structure and handles.
 */
typedef struct fiftyone_degrees_collection_t {
	fiftyoneDegreesCollectionGetMethod get; /**< Gets an entry into the 
	                                        item provided. The consumer MUST 
	                                        release the item when it has 
	                                        finished with the data */
	fiftyoneDegreesCollectionReleaseMethod release; /**< Releases the item 
													handle */
	fiftyoneDegreesCollectionFreeMethod freeCollection; /**< Frees collection
	                                                    and all items retrieved 
	                                                    from the collection 
	                                                    will become invalid */
	void *state; /**< Pointer to data for memory, cache or file. Either a 
	                #fiftyoneDegreesCollectionMemory,
	                #fiftyoneDegreesCollectionFile or 
	                #fiftyoneDegreesCollectionCache */
	fiftyoneDegreesCollection *next; /**< The next collection implementation or
	                                    NULL */
	uint32_t count; /**< The number of items, or 0 if not available */
	uint32_t elementSize; /**< The size of each entry, or 0 if variable length */
	uint32_t size; /**< Number of bytes in the source data structure containing
					  the collection's data */
} fiftyoneDegreesCollection;

/**
 * Type of collection where the collection is held in continuous memory.
 */
typedef struct fiftyone_degrees_collection_memory_t {
	fiftyoneDegreesCollection *collection; /**< The generic collection */
	byte *firstByte; /**< The first byte in memory of the collection */
	byte *lastByte; /**< The last byte in memory of the collection */
	void *memoryToFree; /**< Memory to free when freeing the collection, or NULL
						if no memory to free*/
} fiftyoneDegreesCollectionMemory;

/**
 * Type of collection where the collection is streamed from file.
 */
typedef struct fiftyone_degrees_collection_file_t {
	fiftyoneDegreesCollection *collection; /**< The generic collection */
	fiftyoneDegreesFilePool *reader; /**< Reader used to load items into the 
									 cache, or NULL if no cache */
	fiftyoneDegreesFileOffset offset; /**< Offset to the collection in the source data structure */
	fiftyoneDegreesCollectionFileRead read; /**< Read method used to read an
											item from file at an offset or
											index */
} fiftyoneDegreesCollectionFile;

/**
 * Type of collection where items are cached as they are used. This is usually
 * used in conjunction with a file cache to speed up operation while
 * maintaining a small memory footprint.
 */
typedef struct fiftyone_degrees_collection_cache_t {
	fiftyoneDegreesCollection *source; /**< The source collection used to load
									   items into the cache */
	fiftyoneDegreesCache *cache; /**< Loading cache to use as data source */
} fiftyoneDegreesCollectionCache;

/**
 * Determines if in memory collection methods have been compiled so they are
 * fully optimized. This results in the loss of file stream operation.
 * In memory only operation compiling without stream capabilities using the
 * `FIFTYONE_DEGREES_MEMORY_ONLY` directive results in performance improvements.
 * @return true if the library is compiled for memory only operation, otherwise
 * false.
 */
EXTERNAL bool fiftyoneDegreesCollectionGetIsMemoryOnly();

/**
 * Returns a 32 bit integer from collections that provide such values.
 * @param collection the collection of 32 bit integers
 * @param indexOrOffset the index or offset of the integer required
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return the 32 bit integer at the index or offset provided
 */
EXTERNAL int32_t fiftyoneDegreesCollectionGetInteger32(
	fiftyoneDegreesCollection *collection,
	uint32_t indexOrOffset,
	fiftyoneDegreesException *exception);

/**
 * Creates a collection from the file handle at the current position in the 
 * file. The first 4 bytes read will be the number if fixed with items in the 
 * collection OR the number of bytes until the end of the collection data.
 * @param file a file handle positioned at the start of the collection
 * @param reader a pool of file handles to use operationally to retrieve data
 * from the file after the collection has been created. These are often shared
 * across different collections accessing the same data file.
 * @param config settings for the implementation of the collection to be used.
 * If FIFTYONE_DEGREES_MEMORY_ONLY is defined, then this is either NULL or it
 * is ignored
 * @param header containing collection structure
 * @param read a pointer to a function to read an item into the collection
 * @return pointer to the new collection, or NULL if something went wrong
 */
EXTERNAL fiftyoneDegreesCollection* fiftyoneDegreesCollectionCreateFromFile(
	FILE *file,
	fiftyoneDegreesFilePool *reader,
	const fiftyoneDegreesCollectionConfig *config,
	fiftyoneDegreesCollectionHeader header,
	fiftyoneDegreesCollectionFileRead read);

/**
 * Creates the collection from a memory reader where the collection maps to
 * the memory allocated to the reader. The resulting collection does not
 * free the memory used to store the data. This method is used where the entire
 * data structure is loaded into continuous memory and provides a high 
 * performance collection in all threading situations.
 * @param reader with access to the allocated memory
 * @param header containing collection structure
 * @return pointer to the memory collection, or NULL if the collection could 
 * not be created
 */
EXTERNAL fiftyoneDegreesCollection* fiftyoneDegreesCollectionCreateFromMemory(
	fiftyoneDegreesMemoryReader *reader,
	fiftyoneDegreesCollectionHeader header);

/**
 * Get a handle from the file pool associated with the collection and position
 * the file handle at the offset provided.
 * @param file pointer to the #fiftyoneDegreesCollectionFile to use for the read
 * @param offset from the start of the data structure, not the entire file, 
 * where the item should be read from
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return a file handle for further read operations, or NULL if the offset is
 * invalid, or a handle can not be obtained.
 */
EXTERNAL fiftyoneDegreesFileHandle* fiftyoneDegreesCollectionReadFilePosition(
	const fiftyoneDegreesCollectionFile *file,
	uint32_t offset,
	fiftyoneDegreesException *exception);

/**
 * Used with collections where each item is a fixed number of bytes recorded in
 * elementSize. The method will read that number of bytes into the data item
 * ensuring sufficient memory is allocated.
 * Contained in the collection to avoid repeating this common method across
 * different collection consumers.
 * @param file pointer to the #fiftyoneDegreesCollectionFile to use for the
 * read
 * @param data structure to populate with a reference to the item
 * @param index zero based index of the item required in the fixed with data 
 * structure
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return a pointer to the item in the data structure or NULL if can't be 
 * found due to an invalid index
 */
EXTERNAL void* fiftyoneDegreesCollectionReadFileFixed(
	const fiftyoneDegreesCollectionFile *file,
	uint32_t index,
	fiftyoneDegreesData *data,
	fiftyoneDegreesException *exception);

/**
 * Reads the 4 bytes at the current reader position and configures the
 * collection header. The 4 bytes can either represent the number of fixed
 * width items in the collection OR the number of bytes that follow the 4 bytes
 * which form the collection. The caller must know the type of structure
 * expected and set the elementSize and isCount parameters.
 * @param file a file handle positioned at the start of the collection
 * @param elementSize if known the size in bytes of each item, or 0 for
 * variable width items
 * @param isCount the number of items in the collection if known
 * @return a header set with the details for the collection
 */
EXTERNAL fiftyoneDegreesCollectionHeader
fiftyoneDegreesCollectionHeaderFromFile(
	FILE *file,
	uint32_t elementSize,
	bool isCount);

/**
 * Reads a variable size item from the file where the initial bytes can be used
 * to calculate the size of the entire item. 
 * @param file pointer to the #fiftyoneDegreesCollectionFile to use for the
 * read
 * @param data structure to populate with a reference to the item
 * @param offset zero based offset to the item within the data structure
 * @param initial pointer to enough memory to store the initial data
 * @param initialSize amount of initial data to read
 * @param getFinalSize method pass the initial pointer to get the final size
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return a pointer to the item in the data structure or NULL if can't be
 * found due to an invalid index
 */
EXTERNAL void* fiftyoneDegreesCollectionReadFileVariable(
	const fiftyoneDegreesCollectionFile *file,
	fiftyoneDegreesData *data,
	uint32_t offset,
	void *initial,
	size_t initialSize,
	fiftyoneDegreesCollectionGetFileVariableSizeMethod getFinalSize,
	fiftyoneDegreesException *exception);

/**
 * Reads the 4 bytes at the current reader position and configures the 
 * collection header. The 4 bytes can either represent the number of fixed
 * width items in the collection OR the number of bytes that follow the 4 bytes
 * which form the collection. The caller must know the type of structure 
 * expected and set the elementSize and isCount parameters.
 * @param reader with access to the allocated memory
 * @param elementSize if known the size in bytes of each item, or 0 for
 * variable width items
 * @param isCount the number of items in the collection if known
 * @return a header set with the details for the collection
 */
EXTERNAL fiftyoneDegreesCollectionHeader
fiftyoneDegreesCollectionHeaderFromMemory(
	fiftyoneDegreesMemoryReader *reader,
	uint32_t elementSize,
	bool isCount);


/**
 * Where a collection is fixed width and contains an ordered list of items
 * this method is used to perform a divide and conquer search. The state 
 * and the comparer are used to compare the current index with the value
 * being sought. If an item is found in the collection the item parameter
 * will contain that item when the method completes. The caller will therefore
 * need to release the item when it's finished with it.
 * @param collection to be searched
 * @param item memory to be used to store the current value being compared. 
 * Will have a lock on the item at the index returned if an item is found.
 * The caller should release the item when finished with it.
 * @param lowerIndex to start the search at
 * @param upperIndex to end the search at
 * @param state used with the compare method when comparing items
 * @param comparer method used to perform the comparison
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return the index of the item if found, otherwise -1.
 */
EXTERNAL long fiftyoneDegreesCollectionBinarySearch(
	fiftyoneDegreesCollection *collection,
	fiftyoneDegreesCollectionItem *item,
	uint32_t lowerIndex,
	uint32_t upperIndex,
	void *state,
	fiftyoneDegreesCollectionItemComparer comparer,
	fiftyoneDegreesException *exception);

/**
 * Gets the actual number of items in the collection by iterating through to
 * the base collection. In cases where there are chained collections which
 * pre-load and/or cache elements, the first collections may not contain the full
 * collection of elements. Therefore the value of collection->count may not be
 * correct. This method follows the collection->next pointers to get to the
 * base collection containing the true count.
 *
 * It is important to note that this gets the count for a collection of fixed
 * size elements, and does not apply to collections of variable sized elements.
 * @param collection to get the count for
 * @return the number of items in the collection
 */
EXTERNAL uint32_t fiftyoneDegreesCollectionGetCount(
	fiftyoneDegreesCollection *collection);

/**
 * @}
 */

#endif
/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2023 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

#ifndef FIFTYONE_DEGREES_EVIDENCE_H_INCLUDED
#define FIFTYONE_DEGREES_EVIDENCE_H_INCLUDED

/**
 * @ingroup FiftyOneDegreesCommon * @defgroup FiftyOneDegreesEvidence Evidence
 *
 * Contains key value pairs as evidence to be processed.
 *
 * ## Introduction
 *
 * An Evidence structure contains key value pairs to be parsed and processed
 * by an engine.
 *
 * Items of evidence (e.g. an HTTP header) are added to the structure. The
 * values are then parsed based on the key prefix. In the case of an HTTP
 * header the string would simply be copied, but other types can require
 * further parsing.
 * Evidence items can then be accessed by engines in their parsed form,
 * enabling simpler processing.
 *
 * ## Creation
 *
 * An evidence structure is created using the #fiftyoneDegreesEvidenceCreate
 * method. This takes the maximum number of evidence items which the structure
 * can store.
 *
 * ## Prefixes
 *
 * Evidence keys contain a prefix and the key within that prefix. For example,
 * the key `header.user-agent` has the prefix `header` indicating that the
 * second part of the key is an HTTP header name (`user-agent`).
 *
 * Prefixes are stored as an enum value with the type of
 * #fiftyoneDegreesEvidencePrefix. The enum value of the prefix can be found
 * for a key string by using the #fiftyoneDegreesEvidenceMapPrefix method which
 * takes the key string as an argument, and returns the enum value.
 *
 * Prefix values are defined by their bit positions such that multiple prefixes
 * can be filtered when iterating with the #fiftyoneDegreesEvidenceIterate
 * method. For example, to iterate over all HTTP headers and all query
 * parameters two prefixes can be used in combination like
 * `FIFTYONE_DEGREES_EVIDENCE_HTTP_HEADER_STRING | FIFTYONE_DEGREES_EVIDENCE_QUERY`.
 *
 * ## Add
 *
 * An item of evidence is added to the evidence structure using the
 * #fiftyoneDegreesEvidenceAddString method. This then parses the string value
 * it is provided into the correct type which is determined by the prefix.
 *
 * ## Iterate
 *
 * The evidence a particular evidence structure can be iterated over using the
 * #fiftyoneDegreesEvidenceIterate method. This takes a prefix filter (as
 * described in the Prefixes section above), and a callback method which is
 * called for each evidence item which matches the filter. The number of
 * matching items is then returned.
 *
 * ## Free
 *
 * An evidence structure is freed using the #fiftyoneDegreesEvidenceFree
 * method. It is important to note that this method does **NOT** free the
 * original values which are referenced by the structure.
 *
 * ## Usage Example
 *
 * ```
 * void *state;
 * fiftyoneDegreesEvidenceIterateMethod doSomethingToAValue;
 *
 * // Create an evidence structure large enough to hold a single item of
 * // evidence
 * fiftyoneDegreesEvidenceKeyValuePairArray* evidence =
 *     fiftyoneDegreesEvidenceCreate(1);
 *
 * // Add an item of evidence which is a string
 * fiftyoneDegreesEvidenceAddString(
 *     evidence,
 *     fiftyoneDegreesEvidenceMapPrefix("header"),
 *     "some-header-name",
 *     "some-header-value");
 *
 * // Iterate over all HTTP header evidence and call a method which does
 * // something to each item
 * int numberIterated = fiftyoneDegreesEvidenceIterate(
 *     evidence,
 *     FIFTYONE_DEGREES_EVIDENCE_HTTP_HEADER_STRING,
 *     state,
 *     doSomethingToAValue);
 *
 * // Free the evidence
 * fiftyoneDegreesEvidenceFree(evidence);
 * ```
 *
 * @{
 */

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2023 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

#ifndef FIFTYONE_DEGREES_IP_H_INCLUDED
#define FIFTYONE_DEGREES_IP_H_INCLUDED

/**
 * @ingroup FiftyOneDegreesCommon
 * @defgroup fiftyoneDegreesIp IP
 *
 * Types and methods to parse IP address strings.
 *
 * ## Introduction
 *
 * IP v4 and v6 addresses can be parsed using the
 * #fiftyoneDegreesIpAddressParse and #fiftyoneDegreesIpAddressesParse methods.
 *
 * @{
 */

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

/**
 * The number of bytes in an Ipv4 Address
 */
#define FIFTYONE_DEGREES_IPV4_LENGTH 4

/**
 * The number of bytes in an Ipv6 Address
 */
#define FIFTYONE_DEGREES_IPV6_LENGTH 16

/**
 * Enum indicating the type of IP address.
 */
typedef enum e_fiftyone_degrees_ip_evidence_type {
	FIFTYONE_DEGREES_IP_TYPE_INVALID = 0, /**< Invalid IP address */
	FIFTYONE_DEGREES_IP_TYPE_IPV4 = 4, /**< An IPv4 address */
	FIFTYONE_DEGREES_IP_TYPE_IPV6 = 6, /**< An IPv6 address */
} fiftyoneDegreesIpType;

/**
 * The structure to hold a IP Address in byte array format.
 */
typedef struct fiftyone_degrees_ip_address_t {
	byte value[FIFTYONE_DEGREES_IPV6_LENGTH]; /**< Buffer to hold the IP 
											  address bytes array. */
	byte type; /**< The type of the IP. @see fiftyoneDegreesIpType */
} fiftyoneDegreesIpAddress;

/**
 * Parse a single IP address string.
 * Does not modify the last 12 (out of 16) bytes when parsing IPv4.
 * @param start of the string containing the IP address to parse
 * @param end the last character of the string (with IP address) to be considered for parsing
 * @param address memory to write parsed IP address into.
 * @return <c>true</c> if address was parsed correctly, <c>false</c> otherwise
 */
EXTERNAL bool fiftyoneDegreesIpAddressParse(
	const char *start,
	const char *end,
	fiftyoneDegreesIpAddress *address);

/**
 * Compare two IP addresses in its binary form
 * @param ipAddress1 the first IP address
 * @param ipAddress2 the second IP address
 * @param type the type of IP address. This determine
 * the number of bytes to compare. IPv4 require 4 bytes
 * and IPv6 require 16 bytes
 * @return a value indicate the result:
 * 0 for equals
 * > 0 for ipAddress1 comes after ipAddress2
 * < 0 for ipAddress1 comes before ipAddress2
 */
EXTERNAL int fiftyoneDegreesIpAddressesCompare(
	const unsigned char *ipAddress1,
	const unsigned char *ipAddress2,
	fiftyoneDegreesIpType type);

/**
 * @}
 */

#endif
/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2023 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

#ifndef FIFTYONE_DEGREES_STRING_H_INCLUDED
#define FIFTYONE_DEGREES_STRING_H_INCLUDED

/**
 * @ingroup FiftyOneDegreesCommon
 * @defgroup FiftyOneDegreesString String
 *
 * String structures containing the string and length.
 *
 * ## Introduction
 *
 * The String structure allows a string and its length to be stored in one
 * structure. This avoids unnecessary calls to strlen. Both the string and its
 * length are allocated in a single operation, so the size of the actual
 * structure (when including the string terminator) is
 * sizeof(#fiftyoneDegreesString) + length. This means that the string itself
 * starts at "value" and continues into the rest of the allocated memory.
 *
 * ## Get
 *
 * Getting a const char * from a #fiftyoneDegreesString structure can be done
 * by casting a reference to the "value" field:
 * ```
 * (const char*)&string->value
 * ```
 * However, this can be simplified by using the #FIFTYONE_DEGREES_STRING macro
 * which also performs a NULL check on the structure to avoid a segmentation
 * fault.
 *
 * ## Compare
 *
 * This file contains two case insensitive string comparison methods as
 * standards like `stricmp` vary across compilers.
 *
 * **fiftyoneDegreesStringCompare** : compares two strings case insensitively
 *
 * **fiftyoneDegreesStringCompareLength** : compares two strings case
 * insensitively up to the length required. Any characters after this point are
 * ignored
 *
 * @{
 */

#include <stdint.h>
#include <ctype.h>
/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2023 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

#ifndef FIFTYONE_DEGREES_FLOAT_H_INCLUDED
#define FIFTYONE_DEGREES_FLOAT_H_INCLUDED

/**
 * @ingroup FiftyOneDegreesCommon
 * @defgroup fiftyoneDegreesFloat Float
 *
 * IEEE Single Precision Floating Point standard implementation 
 * and methods to convert to native float type.
 *
 * ## Introduction
 * IEEE Single Precision Floating Point standard is supported in
 * majority of modern computers. However, it is not always guaranteed,
 * so a indepdent implementation is required so that on the machines where
 * this standard is not supported, the float type from the data file can
 * still be read correctly.
 *
 * ## Endianness
 * Endianess difference between machines will not be handled at the
 * moment, until it is supported by 51Degrees data file.
 *
 * ## Limitations
 * Positive sign will always be defaulted to during a conversion from native
 * float type when input float is NaN (Not a Number) or Inf (Infinity).
 * 
 * When converting from 51Degrees implementation to native float type, if it results
 * in a NaN or Inf, the value from compiler macros that represent
 * these number will be returned. i.e. NAN and INFINITY
 *
 * @{
 */

#include <stdint.h>

/**
 * IEEE single precision floating point bias value
 */
#define FIFTYONE_DEGREES_FLOAT_BIAS 127
/**
 * IEEE single precision floating point number of bytes
 */
#define FIFTYONE_DEGREES_FLOAT_SIZE 4
/**
 * IEEE single precision floating point base value
 */
#define FIFTYONE_DEGREES_FLOAT_RADIX 2
/**
 * IEEE single precision floating point number of bits for sgn
 */
#define FIFTYONE_DEGREES_FLOAT_SIGN_SIZE 1
/**
 * IEEE single precision floating point number of bits for exponent
 */
#define FIFTYONE_DEGREES_FLOAT_EXP_SIZE 8
/**
 * IEEE single precision floating point number of bits for mantissa
 */
#define FIFTYONE_DEGREES_FLOAT_MANT_SIZE 23
/**
 * IEEE single precision floating point max positive value
 */
#define FIFTYONE_DEGREES_FLOAT_MAX 3.402823466E38f
/**
 * IEEE single precision floating point min positive value
 */
#define FIFTYONE_DEGREES_FLOAT_MIN 1.175494351E-38f
/**
 * IEEE single precision floating point min negative value
 */
#define FIFTYONE_DEGREES_FLOAT_MIN_NEG -3.402823466E38f
/**
 * IEEE single precision floating point max exponent value where all bits
 * are 1. This can only happen in NaN (Not a Number) and Inf (Infinity) cases.
 */
#define FIFTYONE_DEGREES_FLOAT_EXP_MAX 255
/**
 * IEEE single precision floating point max mantissa value where all bits
 * are 1.
 */
#define FIFTYONE_DEGREES_FLOAT_MANT_MAX 8388607

/**
 * Struture that represents 51Degrees implementation, which encapsulate
 * an array of 4 bytes. This array will be formated accordingly to
 * the IEEE standard
 */
typedef struct fiftyone_degrees_float_type {
	byte value[FIFTYONE_DEGREES_FLOAT_SIZE];
} fiftyoneDegreesFloatInternal;

/**
 * Union that breaks down 51Degrees implementation to its components:
 * sign, exponent and mantissa.
 */
typedef union {
	fiftyoneDegreesFloatInternal fValue;
	struct {
		uint32_t mantissa : FIFTYONE_DEGREES_FLOAT_MANT_SIZE;
		uint32_t exponent : FIFTYONE_DEGREES_FLOAT_EXP_SIZE;
		uint32_t sign : FIFTYONE_DEGREES_FLOAT_SIGN_SIZE;
	} parts;
} fiftyoneDegreesFloatU;

/**
 * Function that converts from a 51Degrees float implementation to a
 * native float value.
 * @param f input 51Degrees float value
 * @return a native float value
 */
EXTERNAL float fiftyoneDegreesFloatToNative(fiftyoneDegreesFloatInternal f);
/**
 * Function that converts from a native float value to 51Degrees float
 * value.
 * @param f input native float value
 * @return a 51Degrees float value
 */
EXTERNAL fiftyoneDegreesFloatInternal fiftyoneDegreesNativeToFloat(float f);
/**
 * Function that compare if two 51Degrees float values are equal
 * @param f1 first input 51Degrees float value
 * @param f2 second input 51Degrees float value
 * @return 0 if the two are equal and 1 if they are not.
 */
EXTERNAL int fiftyoneDegreesFloatIsEqual(fiftyoneDegreesFloatInternal f1, fiftyoneDegreesFloatInternal f2);

/**
 * For some compilers such as clang and Microsoft C or computers where
 * the IEEE single precision standard is supported, default the type
 * to the native float type.
 */
#if _MSC_VER || (FLT_RADIX == 2 && FLT_MANT_DIG == 24 && FLT_MAX_EXP == 128 && FLT_MIN_EXP == -125)
/**
 * Define 51Degrees float implementation as native float.
 */
typedef float fiftyoneDegreesFloat;

/**
 * Convert from 51Degrees float to native float
 * @param f 51Degrees float
 * @return native float value. In this case, it is a straight map
 * to the input value itself.
 */
#define FIFTYONE_DEGREES_FLOAT_TO_NATIVE(f) f
/**
 * Convert from native float to 51Degrees float
 * @param f native float type
 * @return a 51Degrees float value. In this case, it is a straight
 * map to the input value itself.
 */
#define FIFTYONE_DEGREES_NATIVE_TO_FLOAT(f) f
/**
 * Compare two 51Degrees float input values.
 * @param f1 a 51Degrees float input value.
 * @param f2 a 51Degrees float input value.
 * @return 0 if the two values are the same and 1 otherwise.
 */
#define FIFTYONE_DEGREES_FLOAT_IS_EQUAL(f1, f2) (f1 == f2 ? 0 : 1)
#else
/**
 * Define 51Degrees float implementation as the internal type
 * IEEE standard is not supported in this case
 */
typedef fiftyoneDegreesFloatInternal fiftyoneDegreesFloat;
/**
 * Function that converts from a 51Degrees float implementation to a
 * native float value.
 * @param f input 51Degrees float value
 * @return a native float value
 */
#define FIFTYONE_DEGREES_FLOAT_TO_NATIVE(f) fiftyoneDegreesFloatToNative(f)
/**
 * Function that converts from a native float value to 51Degrees float
 * value.
 * @param f input native float value
 * @return a 51Degrees float value
 */
#define FIFTYONE_DEGREES_NATIVE_TO_FLOAT(f) fiftyoneDegreesNativeToFloat(f)
/**
 * Function that compare if two 51Degrees float values are equal
 * @param f1 first input 51Degrees float value
 * @param f2 second input 51Degrees float value
 * @return 0 if the two are equal and 1 if they are not.
 */
#define FIFTYONE_DEGREES_FLOAT_IS_EQUAL(f1, f2) fiftyoneDegreesFloatIsEqual(f1, f2)
#endif

/**
 * @}
 */

#endif
/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2023 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

#ifndef FIFTYONE_DEGREES_PROPERTY_VALUE_TYPE_H_INCLUDED
#define FIFTYONE_DEGREES_PROPERTY_VALUE_TYPE_H_INCLUDED

/**
 * Enum of property types.
 */
typedef enum e_fiftyone_degrees_property_value_type {
	FIFTYONE_DEGREES_PROPERTY_VALUE_TYPE_STRING = 0, /**< String */
	FIFTYONE_DEGREES_PROPERTY_VALUE_TYPE_INTEGER = 1, /**< Integer */
	FIFTYONE_DEGREES_PROPERTY_VALUE_TYPE_DOUBLE = 2, /**< Double */
	FIFTYONE_DEGREES_PROPERTY_VALUE_TYPE_BOOLEAN = 3, /**< Boolean */
	FIFTYONE_DEGREES_PROPERTY_VALUE_TYPE_JAVASCRIPT = 4, /**< JavaScript string */
	FIFTYONE_DEGREES_PROPERTY_VALUE_SINGLE_PRECISION_FLOAT = 5, /**< Single precision floating point value */
	FIFTYONE_DEGREES_PROPERTY_VALUE_SINGLE_BYTE = 6, /**< Single byte value */
	FIFTYONE_DEGREES_PROPERTY_VALUE_TYPE_COORDINATE = 7, /**< Coordinate */
	FIFTYONE_DEGREES_PROPERTY_VALUE_TYPE_IP_ADDRESS = 8, /**< Ip Range */
	FIFTYONE_DEGREES_PROPERTY_VALUE_TYPE_WKB = 9, /**< Well-known binary for geometry */
	FIFTYONE_DEGREES_PROPERTY_VALUE_TYPE_OBJECT = 10, /**<  Mainly this is used for nested AspectData. */
	/**
	 * Angle north (positive) or south (negative) of the [celestial] equator,
	 * [-90;90] saved as short (int16_t),
	 * i.e. projected onto [-INT16_MAX;INT16_MAX]
	 */
	FIFTYONE_DEGREES_PROPERTY_VALUE_TYPE_DECLINATION = 11,
	/**
	 * Horizontal angle from a cardinal direction (e.g. 0 meridian),
	 * [-180;180] saved as short (int16_t),
	 * i.e. projected onto [-INT16_MAX;INT16_MAX]
	 */
	FIFTYONE_DEGREES_PROPERTY_VALUE_TYPE_AZIMUTH = 12,
	FIFTYONE_DEGREES_PROPERTY_VALUE_TYPE_WKB_R = 13, /**< Well-known binary (reduced) for geometry */
} fiftyoneDegreesPropertyValueType;

#endif

/**
 * Macro used to check for NULL before returning the string as a const char *.
 * @param s pointer to the #fiftyoneDegreesString
 * @return const char * string or NULL
 */
#define FIFTYONE_DEGREES_STRING(s) \
	(const char*)(s == NULL ? NULL : &((fiftyoneDegreesString*)s)->value)

/** 
 * String structure containing its value and size which maps to the string 
 * byte format used in data files.
 *
 * @example
 * String:
 * 			Short – length – 10
 * 			Byte value – first character of string – '5'
 */
#pragma pack(push, 1)
typedef struct fiftyone_degrees_string_t {
	int16_t size; /**< Size of the string in memory (starting from 'value') */
	char value; /**< The first character of the string */
} fiftyoneDegreesString;
#pragma pack(pop)

#ifndef FIFTYONE_DEGREES_MEMORY_ONLY

/**
 * Reads a string from the source file at the offset within the string
 * structure.
 * @param file collection to read from
 * @param offset of the string in the collection
 * @param data to store the new string in
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return a pointer to the string collection item or NULL if can't be found
 */
EXTERNAL void* fiftyoneDegreesStringRead(
	const fiftyoneDegreesCollectionFile *file,
	uint32_t offset,
	fiftyoneDegreesData *data,
	fiftyoneDegreesException *exception);

#endif

/**
 * Gets the string at the required offset from the collection provided.
 * @param strings collection to get the string from
 * @param offset of the string in the collection
 * @param item to store the string in
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return a pointer to string of NULL if the offset is not valid
 */
EXTERNAL fiftyoneDegreesString* fiftyoneDegreesStringGet(
	fiftyoneDegreesCollection *strings,
	uint32_t offset,
	fiftyoneDegreesCollectionItem *item,
	fiftyoneDegreesException *exception);

/**
 * Case insensitively compare two strings up to the length requested.
 * @param a string to compare
 * @param b other string to compare
 * @param length of the strings to compare
 * @return 0 if same
 */
EXTERNAL int fiftyoneDegreesStringCompareLength(
	char const *a, 
	char const *b, 
	size_t length);

/**
 * Case insensitively compare two strings.
 * @param a string to compare
 * @param b other string to compare
 * @return 0 if same
 */
EXTERNAL int fiftyoneDegreesStringCompare(const char *a, const char *b);

/**
 * Case insensitively searching a first occurrence of a
 * substring.
 * @param a string to search
 * @param b substring to be searched for
 * @return pointer to the first occurrence or NULL if not found
 */
EXTERNAL const char *fiftyoneDegreesStringSubString(const char *a, const char *b);

/**
 * @}
 */

/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2023 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

#ifndef FIFTYONE_DEGREES_STRING_BUILDER_H_INCLUDED
#define FIFTYONE_DEGREES_STRING_BUILDER_H_INCLUDED

/**
 * @ingroup FiftyOneDegreesCommon
 * @defgroup FiftyOneDegreesString String
 *
 * String structures containing the string and length.
 *
 * ## Introduction
 *
 * The String structure allows a string and its length to be stored in one
 * structure. This avoids unnecessary calls to strlen. Both the string and its
 * length are allocated in a single operation, so the size of the actual
 * structure (when including the string terminator) is
 * sizeof(#fiftyoneDegreesString) + length. This means that the string itself
 * starts at "value" and continues into the rest of the allocated memory.
 *
 * ## Get
 *
 * Getting a const char * from a #fiftyoneDegreesString structure can be done
 * by casting a reference to the "value" field:
 * ```
 * (const char*)&string->value
 * ```
 * However, this can be simplified by using the #FIFTYONE_DEGREES_STRING macro
 * which also performs a NULL check on the structure to avoid a segmentation
 * fault.
 *
 * ## Compare
 *
 * This file contains two case insensitive string comparison methods as
 * standards like `stricmp` vary across compilers.
 *
 * **fiftyoneDegreesStringCompare** : compares two strings case insensitively
 *
 * **fiftyoneDegreesStringCompareLength** : compares two strings case
 * insensitively up to the length required. Any characters after this point are
 * ignored
 *
 * @{
 */

#include <stdint.h>
#include <ctype.h>

union fiftyone_degrees_stored_binary_value_t;
typedef union fiftyone_degrees_stored_binary_value_t fiftyoneDegreesStoredBinaryValue;

struct fiftyone_degrees_var_length_byte_array_t;
typedef struct fiftyone_degrees_var_length_byte_array_t fiftyoneDegreesVarLengthByteArray;

/** String buffer for building strings with memory checks */
typedef struct fiftyone_degrees_string_builder_t {
	char* const ptr; /**< Pointer to the memory used by the buffer */
	size_t const length; /**< Length of buffer */
	char* current; /**</ Current position to add characters in the buffer */
	size_t remaining; /**< Remaining characters in the buffer */
	size_t added; /**< Characters added to the buffer or that would be
					  added if the buffer were long enough */
	bool full; /**< True if the buffer is full, otherwise false */
} fiftyoneDegreesStringBuilder;

/**
 * Initializes the buffer.
 * @param builder to initialize
 * @return pointer to the builder passed
 */
EXTERNAL fiftyoneDegreesStringBuilder* fiftyoneDegreesStringBuilderInit(
	fiftyoneDegreesStringBuilder* builder);

/**
 * Adds the character to the buffer.
 * @param builder to add the character to
 * @param value character to add
 * @return pointer to the builder passed
 */
EXTERNAL fiftyoneDegreesStringBuilder* fiftyoneDegreesStringBuilderAddChar(
	fiftyoneDegreesStringBuilder* builder,
	char const value);

/**
 * Adds the integer to the buffer.
 * @param builder to add the character to
 * @param value integer to add
 * @return pointer to the buffer passed
 */
EXTERNAL fiftyoneDegreesStringBuilder* fiftyoneDegreesStringBuilderAddInteger(
	fiftyoneDegreesStringBuilder* builder,
	int64_t const value);

/**
 * Adds the double to the buffer.
 * @param builder to add the character to
 * @param value floating-point number to add
 * @param decimalPlaces precision (places after decimal dot)
 * @return pointer to the buffer passed
 */
EXTERNAL fiftyoneDegreesStringBuilder* fiftyoneDegreesStringBuilderAddDouble(
	fiftyoneDegreesStringBuilder* builder,
	double value,
	uint8_t decimalPlaces);

/**
 * Adds the string to the buffer.
 * @param builder to add the character to
 * @param value of chars to add
 * @param length of chars to add
 * @return pointer to the buffer passed
 */
EXTERNAL fiftyoneDegreesStringBuilder* fiftyoneDegreesStringBuilderAddChars(
	fiftyoneDegreesStringBuilder* builder,
	const char* value,
	size_t length);

/**
 * Adds an the IP (as string) from byte "string".
 * @param builder to add the IP to
 * @param ipAddress binary (packed) "string" with IP to add
 * @param type type of IP inside
 * @param exception pointer to exception struct
 */
EXTERNAL void fiftyoneDegreesStringBuilderAddIpAddress(
	fiftyoneDegreesStringBuilder* builder,
	const fiftyoneDegreesVarLengthByteArray *ipAddress,
	fiftyoneDegreesIpType type,
	fiftyoneDegreesException *exception);

/**
 * Adds a potentially packed value as a proper string to the buffer.
 * @param builder to add the character to
 * @param value from data file to add
 * @param decimalPlaces precision for numbers (places after decimal dot)
 * @param exception pointer to exception struct
 * @return pointer to the buffer passed
 */
EXTERNAL fiftyoneDegreesStringBuilder* fiftyoneDegreesStringBuilderAddStringValue(
	fiftyoneDegreesStringBuilder* builder,
	const fiftyoneDegreesStoredBinaryValue* value,
	fiftyoneDegreesPropertyValueType valueType,
	uint8_t decimalPlaces,
	fiftyoneDegreesException *exception);

/**
 * Adds a null terminating character to the buffer.
 * @param builder to terminate
 * @return pointer to the buffer passed
 */
EXTERNAL fiftyoneDegreesStringBuilder* fiftyoneDegreesStringBuilderComplete(
	fiftyoneDegreesStringBuilder* builder);

/**
 * @}
 */

#endif

#endif
/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2023 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

#ifndef FIFTYONE_DEGREES_ARRAY_H_INCLUDED
#define FIFTYONE_DEGREES_ARRAY_H_INCLUDED

/**
 * @ingroup FiftyOneDegreesCommon
 * @defgroup FiftyOneDegreesArray Arrays
 *
 * Macros used to quickly define array structures.
 *
 * ## Introduction
 *
 * Array structures contain an array of fixed size items, along with the
 * number of items and the capacity of the array. This makes passing it around
 * much simpler as the extra information can be passed with it.
 *
 * The macros also allow additional members to the added to the structure.
 *
 * @{
 */

#include <stdint.h>

/**
 * Simple array structure definition macro used for generic types.
 * @param t type of item
 * @param m additional members
 */
#define FIFTYONE_DEGREES_ARRAY_TYPE(t, m) \
/** Array of items of type t used to easily access and track the
    size of the array. */ \
typedef struct fiftyone_degrees_array_##t##_t { \
	uint32_t count; /**< Number of used items */ \
	uint32_t capacity; /**< Number of available items */ \
	t* items; /**< Pointer to the first item */ \
	m /**< Add any members provided by the caller */ \
} t##Array;

/**
 * Works out the size of the array with a given capacity for the type.
 */
#define FIFTYONE_DEGREES_ARRAY_SIZE(t, c) (sizeof(t##Array) + (sizeof(t) * (c)))

/**
 * Initialises the array.
 */
#define FIFTYONE_DEGREES_ARRAY_CREATE(t, i, c) \
i = (t##Array*)fiftyoneDegreesMalloc(FIFTYONE_DEGREES_ARRAY_SIZE(t,c)); \
if (i != NULL) { \
i->items = c ? (t*)(i + 1) : NULL; \
i->count = 0; \
i->capacity = c; \
}

/**
 * @}
 */ 
#endif
/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2023 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

#ifndef FIFTYONE_DEGREES_PAIR_H_INCLUDED
#define FIFTYONE_DEGREES_PAIR_H_INCLUDED

#include <stddef.h>

typedef struct fiftyone_degrees_key_value_pair_t {
	const char* key; /**< pointer to the key string */
	size_t keyLength; /**< number of characters in key */
	const char* value; /**< pointer to the value string */
	size_t valueLength; /**< number of characters in value */
} fiftyoneDegreesKeyValuePair;

FIFTYONE_DEGREES_ARRAY_TYPE(fiftyoneDegreesKeyValuePair, )

#endif
/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2023 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

#ifndef FIFTYONE_DEGREES_HEADERS_H_INCLUDED
#define FIFTYONE_DEGREES_HEADERS_H_INCLUDED

/**
 * @ingroup FiftyOneDegreesCommon
 * @defgroup FiftyOneDegreesHeaders Headers
 *
 * Common form of evidence in 51Degrees engines.
 *
 * ## Introduction
 *
 * HTTP headers are a common form of evidence, so required headers have their
 * own structure and methods. By storing the unique id of headers, storing
 * duplicates of the same header can be avoided. Duplicates can occur as a
 * result of different cases or prefixes e.g. `User-Agent`, `user-agent` and
 * `HTTP_user-agent` are all the same header.
 *
 * ## Creation
 *
 * A header structure is created using the #fiftyoneDegreesHeadersCreate
 * method. This takes a state and a method used to extract the unique headers
 * from the state. See the method description for more details.
 *
 * ## Get
 *
 * A header can be fetched using it's unique id with the
 * #fiftyoneDegreesHeadersGetHeaderFromUniqueId method.
 *
 * The index of a header in the unique headers structure can also be fetched
 * using the #fiftyoneDegreesHeaderGetIndex method.
 *
 * ## Free
 *
 * Once a headers structure is finished with, it is released using the
 * #fiftyoneDegreesHeadersFree method.
 *
 * ## Usage Example
 *
 * ```
 * fiftyoneDegreesHeadersGetMethod getHeaderId;
 * void *state;
 *
 * // Create the headers structure
 * fiftyoneDegreesHeaders *headers = fiftyoneDegreesHeadersCreate(
 *     false,
 *     state,
 *     getHeaderId,
 *     exception);
 *
 * // Get the index of a header
 * int index = fiftyoneDegreesHeaderGetIndex(
 *     headers,
 *     "user-agent",
 *     strlen("user-agent"));
 *
 * // Check that the header exists in the structure
 * if (index >= 0) {
 *
 *     // Do something with the header
 *     // ...
 * }
 *
 * // Free the headers structure
 * fiftyoneDegreesHeadersFree(headers);
 * ```
 *
 * @{
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#ifdef _MSC_FULL_VER
#include <string.h>
#else
#include <strings.h>
#define _stricmp strcasecmp
#define _strnicmp strncasecmp
#endif
/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2023 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

#ifndef FIFTYONE_DEGREES_LIST_H_INCLUDED
#define FIFTYONE_DEGREES_LIST_H_INCLUDED

/**
 * @ingroup FiftyOneDegreesCommon
 * @defgroup FiftyOneDegreesList List
 *
 * A more manageable way to store arrays.
 *
 * ## Introduction
 *
 * Lists are a way of storing an array of elements in an easy to manage way.
 * This means that the capacity, and the number of elements are both known
 * quantities to any method handling the list, in contrast to a pure array
 * where neither are known.
 * Lists hold collection items, so when they are finished with, they must be
 * freed correctly using the #fiftyoneDegreesListFree method.
 * Cleanup is also handled so as to be simpler to use than an array. By freeing
 * the list, all elements are released from their collection and the memory
 * for the list is freed.
 *
 * ## Creation
 *
 * Lists are created by allocating memory to the list structure, then calling
 * the init method #fiftyoneDegreesListInit to allocate memory for list items
 * and initialise the count and capacity.
 *
 * ## Add
 *
 * Collection items are added to a list using the #fiftyoneDegreesListAdd
 * method. This then holds the reference to the collection item until the list
 * is freed.
 *
 * ## Get
 *
 * Items can be fetched from the list by accessing the collection item
 * directly:
 * ```
 * list->items[index]
 * ```
 * then casting the pointer it contains to the correct type. Or for strings
 * the #fiftyoneDegreesListGetAsString method can be used to access and cast
 * in one call.
 *
 * ## Free
 *
 * Lists must be freed using the #fiftyoneDegreesListFree method. This releases
 * all collection items stored within, and frees the memory for the internal
 * array which stores their pointers.
 *
 * ## Reuse
 *
 * Lists can be reused by releasing all the collection items with the
 * #fiftyoneDegreesListRelease method, clearing the list ready for a new list
 * of items to be added.
 *
 * ## Usage Example
 *
 * ```
 * fiftyoneDegreesList list;
 * fiftyoneDegreesCollectionItem *item;
 *
 * // Initialise the list with the capacity for 1 entry
 * fiftyoneDegreesListInit(&list, 1);
 *
 * // Add an item from a collection to the list
 * fiftyoneDegreesListAdd(&list, item);
 *
 * // Get the first item in the list as a string
 * fiftyoneDegreesString *string = fiftyoneDegreesListGetAsString(&list, 0);
 *
 * // Do Something with the string
 * // ...
 *
 * // Free the list, releasing the items it contains back to their respective
 * // collections
 * fiftyoneDegreesListFree(&list);
 * ```
 *
 * @{
 */


/**
 * List structure which contains a list of collection items.
 */
typedef struct fiftyone_degrees_list_t {
	fiftyoneDegreesCollectionItem *items; /**< Array of items */
	uint32_t capacity; /**< Capacity of the list to store items */
	uint32_t count; /**< Number of items currently in the list  */
} fiftyoneDegreesList;

/**
 * Initialise the list by allocating space for the items in the list structure.
 * @param list pointer to list structure to initialise
 * @param capacity number of items expected in the list
 * @return the initialised list or NULL if memory could not be allocated
 */
EXTERNAL fiftyoneDegreesList* fiftyoneDegreesListInit(
	fiftyoneDegreesList *list,
	uint32_t capacity);

/**
 * Adds a collection item to a list. The reference to the item will be released
 * when the list is released or freed.
 * @param list to add the item to
 * @param item to add to the list
 */
EXTERNAL void fiftyoneDegreesListAdd(
	fiftyoneDegreesList *list,
	fiftyoneDegreesCollectionItem *item);

/**
 * Gets the item at the index provided as a string.
 * @param list to get the item from
 * @param index of the item in the list
 * @return the requested list item as a string
 */
EXTERNAL fiftyoneDegreesString* fiftyoneDegreesListGetAsString(
	fiftyoneDegreesList *list,
	int index);

/**
 * Frees the memory allocated to the list structure and release all items
 * stored in it.
 * @param list to free
 */
EXTERNAL void fiftyoneDegreesListFree(fiftyoneDegreesList *list);

/**
 * Resets a newly allocated list to a clean empty state.
 * @param list to reset
 */
EXTERNAL void fiftyoneDegreesListReset(fiftyoneDegreesList *list);

/**
 * Releases all the items stored in the list.
 * @param list to release
 */
EXTERNAL void fiftyoneDegreesListRelease(fiftyoneDegreesList *list);

/**
 * @}
 */

#endif

#define FIFTYONE_DEGREES_PSEUDO_HEADER_SEP '\x1F' /** unit separator of headers
													and headers' values that
													form pseudo header and
													its evidence */

/**
 * The unique id for the header field string in the data set.
 */
typedef uint32_t fiftyoneDegreesHeaderID;

/**
 * Forward declaration of the header structure.
 */
typedef struct fiftyone_degrees_header_t fiftyoneDegreesHeader;

/**
 * Pointer to a header structure. Used in an array of related headers.
 */
typedef fiftyoneDegreesHeader* fiftyoneDegreesHeaderPtr;

/**
 * Array of header indexes.
 */
FIFTYONE_DEGREES_ARRAY_TYPE(
	fiftyoneDegreesHeaderPtr,
	);
typedef fiftyoneDegreesHeaderPtrArray fiftyoneDegreesHeaderPtrs;

/**
 * Structure for a header known to the corresponding data set.
 */
struct fiftyone_degrees_header_t {
	uint32_t index; /**< Index of the header in the array of all headers */
	const char* name; /**< Name of the header or pseudo header field as a
					       null terminated string */
	size_t nameLength; /**< Length of the name string excluding the terminating 
						null */
	fiftyoneDegreesHeaderID headerId; /**< Unique id in the data set for this 
									  full header */
	bool isDataSet; /**< True if the header originates from the data set and 
					the headerId is valid */
	fiftyoneDegreesHeaderPtrs* pseudoHeaders; /**< Array of pointers to
												related pseudo headers */
	fiftyoneDegreesHeaderPtrs* segmentHeaders; /**< Array of pointers to raw
												  headers that form this pseudo
												  header */
};

#define FIFTYONE_DEGREES_HEADERS_MEMBERS \
bool expectUpperPrefixedHeaders; /**< True if the headers structure should
								 expect input header to be prefixed with
								 'HTTP_' */

/**
 * Array of Headers which should always be ordered in ascending order of 
 * fullHeaderId.
 */
FIFTYONE_DEGREES_ARRAY_TYPE(
	fiftyoneDegreesHeader, 
	FIFTYONE_DEGREES_HEADERS_MEMBERS);

/**
 * Array of headers used to easily access and track the size of the array.
 */
typedef fiftyoneDegreesHeaderArray fiftyoneDegreesHeaders;

/**
 * Gets the unique id and name of the header at the requested index. The caller
 * must use COLLECTION_RELEASE on nameItem when finished with the result.
 * @param state pointer to data used by the method
 * @param index of the header to get
 * @param nameItem pointer to the collection item to populate with the name of
 * the header
 * @return unique id of the header
 */
typedef long(*fiftyoneDegreesHeadersGetMethod)(
	void *state,
	uint32_t index, 
	fiftyoneDegreesCollectionItem *nameItem);

/**
 * Creates a new headers instance configured with the unique HTTP names needed
 * from evidence. If the useUpperPrefixedHeaders flag is true then checks for 
 * the presence of HTTP headers will also include checking for HTTP_ as a
 * prefix to the header key. If header is a pseudo header, the indices of
 * actual headers that form this header will be constructed.
 *
 * @param useUpperPrefixedHeaders true if HTTP_ prefixes should be checked
 * @param state pointer used by getHeaderMethod to retrieve the header integer
 * @param get used to return the HTTP header unique integer
 * @param exception
 * @return a new instance of #fiftyoneDegreesHeaders ready to be used to filter 
 * HTTP headers.
 */
EXTERNAL fiftyoneDegreesHeaders* fiftyoneDegreesHeadersCreate(
	bool useUpperPrefixedHeaders,
	void *state,
	fiftyoneDegreesHeadersGetMethod get,
	fiftyoneDegreesException* exception);

/**
 * Provides the integer index of the HTTP header name, or -1 if there is no 
 * matching header.
 * @param headers structure created by #fiftyoneDegreesHeadersCreate
 * @param httpHeaderName of the header whose index is required
 * @param length number of characters in httpHeaderName
 * @return the index of the HTTP header name, or -1 if the name does not exist
 */
EXTERNAL int fiftyoneDegreesHeaderGetIndex(
	fiftyoneDegreesHeaders *headers,
	const char* httpHeaderName,
	size_t length);

/**
 * Gets a pointer to the header in the headers structure with a unique id
 * matching the one provided. If the headers structure does not contain a
 * header with the unique id, NULL will be returned.
 * This method assumes that the headers in the structure are unique, if they
 * are not, then the first matching header will be returned.
 * @param headers pointer to the headers structure to search
 * @param uniqueId id to search for
 * @return pointer to the matching header, or NULL
 */
EXTERNAL fiftyoneDegreesHeader* fiftyoneDegreesHeadersGetHeaderFromUniqueId(
	fiftyoneDegreesHeaders *headers,
    fiftyoneDegreesHeaderID uniqueId);

/**
 * Frees the memory allocated by the #fiftyoneDegreesHeadersCreate method.
 *
 * @param headers structure created by #fiftyoneDegreesHeadersCreate
 */
EXTERNAL void fiftyoneDegreesHeadersFree(fiftyoneDegreesHeaders *headers);

/**
 * Determines if the field is an HTTP header.
 * @param state results instance to check against
 * @param field name from the evidence pair to be checked
 * @param length of field string
 * @return true if the evidence relates to an HTTP header, otherwise false.
 */
EXTERNAL bool fiftyoneDegreesHeadersIsHttp(
	void *state,
	const char* field,
	size_t length);

/**
 * @}
 */

#endif

/**
 * Evidence prefixes used to determine the category a piece of evidence
 * belongs to. This will determine how the value is parsed.
 */
typedef enum e_fiftyone_degrees_evidence_prefix {
	FIFTYONE_DEGREES_EVIDENCE_HTTP_HEADER_STRING = 1 << 0, /**< An HTTP header
														   value */
	FIFTYONE_DEGREES_EVIDENCE_HTTP_HEADER_IP_ADDRESSES = 1 << 1, /**< A list of
																 IP addresses
																 as a string to
																 be parsed into
																 a IP addresses
																 collection. */
	FIFTYONE_DEGREES_EVIDENCE_SERVER = 1 << 2, /**< A server value e.g. client
											   IP */
	FIFTYONE_DEGREES_EVIDENCE_QUERY = 1 << 3, /**< A query string parameter */
	FIFTYONE_DEGREES_EVIDENCE_COOKIE = 1 << 4, /**< A cookie value */
	FIFTYONE_DEGREES_EVIDENCE_IGNORE = 1 << 7, /**< The evidence is invalid and
											   should be ignored */
} fiftyoneDegreesEvidencePrefix;

/** Map of prefix strings to prefix enum values. */
typedef struct fiftyone_degrees_evidence_prefix_map_t {
	const char *prefix; /**< Name of the prefix */
	size_t prefixLength; /**< Length of the prefix string */
	fiftyoneDegreesEvidencePrefix prefixEnum; /**< Enum value of prefix name */
} fiftyoneDegreesEvidencePrefixMap;

/**
 * Evidence key value pair structure which combines the prefix, key and value.
 */
typedef struct fiftyone_degrees_evidence_key_value_pair_t {
	fiftyoneDegreesEvidencePrefix prefix; /**< e.g. #FIFTYONE_DEGREES_EVIDENCE_HTTP_HEADER_STRING */
	fiftyoneDegreesKeyValuePair item; /**< the field key and original value */
	const void *parsedValue; /**< parsed value which may not be a string */
	size_t parsedLength; /**< length of parsedValue string */
	fiftyoneDegreesHeader* header; /**< Unique header in the data set, or 
								   null if not related to a header */
} fiftyoneDegreesEvidenceKeyValuePair;

/**
 * Forward declaration of the array so that it can point to an instance of the 
 * same type.
 */
typedef struct fiftyone_degrees_array_fiftyoneDegreesEvidenceKeyValuePair_t 
	fiftyoneDegreesEvidenceKeyValuePairArray;

/**
 * Pointers to the next and previous array of evidence key value pairs or 
 * NULL if not present.
 */
#define FIFTYONE_DEGREES_ARRAY_EVIDENCE_MEMBER \
	fiftyoneDegreesEvidenceKeyValuePairArray *next; \
	fiftyoneDegreesEvidenceKeyValuePairArray *prev;

/**
 * Array of evidence key value pairs and a pointer to the next array if present
 * or NULL of not present.
 */
FIFTYONE_DEGREES_ARRAY_TYPE(
	fiftyoneDegreesEvidenceKeyValuePair,
	FIFTYONE_DEGREES_ARRAY_EVIDENCE_MEMBER)

/**
 * Callback method used to iterate evidence key value pairs.
 * @param state pointer provided to the iterator
 * @param pair evidence key value pair with the parsed value set
 * @return true if the iteration should continue otherwise false
 */
typedef bool(*fiftyoneDegreesEvidenceIterateMethod)(
	void *state,
	fiftyoneDegreesEvidenceKeyValuePair *pair);

/**
 * Creates a new evidence array with the capacity requested.
 * @param capacity maximum number of evidence items
 * @return pointer to the newly created array
 */
EXTERNAL fiftyoneDegreesEvidenceKeyValuePairArray* 
	fiftyoneDegreesEvidenceCreate(uint32_t capacity);

/**
 * Frees the memory used by an evidence array and any other arrays pointed to
 * by the instance passed via the next member.
 * @param evidence pointer to the array to be freed
 */
EXTERNAL void fiftyoneDegreesEvidenceFree(
	fiftyoneDegreesEvidenceKeyValuePairArray *evidence);

/**
 * Adds a new entry to the evidence. The memory associated with the 
 * field and original value parameters must not be freed until after the 
 * evidence collection has been freed. This method will NOT copy the values.
 * If there is insufficient capacity in the evidence array then another array
 * will be created and will be pointed to by the next member of the evidence 
 * array passed.
 * @param evidence pointer to the evidence array to add the entry to
 * @param prefix enum indicating the category the entry belongs to
 * @param key string with null terminator
 * @param value string with null terminator
 * @returns the new evidence key value pair instance
 */
EXTERNAL fiftyoneDegreesEvidenceKeyValuePair* fiftyoneDegreesEvidenceAddString(
	fiftyoneDegreesEvidenceKeyValuePairArray *evidence,
	fiftyoneDegreesEvidencePrefix prefix,
	const char *key,
	const char *value);

/**
 * Adds a new entry to the evidence. The memory associated with the
 * field and original value parameters must not be freed until after the
 * evidence collection has been freed. This method will NOT copy the values.
 * If there is insufficient capacity in the evidence array then another array
 * will be created and will be pointed to by the next member of the evidence
 * array passed.
 * @param evidence pointer to the evidence array to add the entry to
 * @param prefix enum indicating the category the entry belongs to
 * @param pair used as the key and value for the new entry
 * @returns the new evidence key value pair instance
 */
EXTERNAL fiftyoneDegreesEvidenceKeyValuePair* fiftyoneDegreesEvidenceAddPair(
	fiftyoneDegreesEvidenceKeyValuePairArray* evidence,
	fiftyoneDegreesEvidencePrefix prefix,
	fiftyoneDegreesKeyValuePair pair);

/**
 * Determines the evidence map prefix from the key.
 * @param key the evidence key including the evidence prefix .i.e. header
 * @return the prefix enumeration, or NULL if one does not exist
 */
EXTERNAL fiftyoneDegreesEvidencePrefixMap* fiftyoneDegreesEvidenceMapPrefix(
	const char *key);

/**
 * Get the prefix string of an evidence prefix
 * @param prefix the evidence prefix enumeration
 * @return null terminated string value of the prefix, including a dot separator
 */
EXTERNAL const char* fiftyoneDegreesEvidencePrefixString(
	fiftyoneDegreesEvidencePrefix prefix);

/**
 * Iterates over the evidence calling the callback method for any values that
 * match the prefixes provided. If there are pseudo evidence, this
 * will also iterate through them and perform the callback on each.
 *
 * @param evidence key value pairs including prefixes
 * @param prefixes one or more prefix flags to return values for
 * @param state pointer passed to the callback method
 * @param callback method called when a matching prefix is found
 * @return the number of matching evidence keys iterated over
 */
EXTERNAL uint32_t fiftyoneDegreesEvidenceIterate(
	fiftyoneDegreesEvidenceKeyValuePairArray *evidence,
	int prefixes,
	void *state,
	fiftyoneDegreesEvidenceIterateMethod callback);

/**
 * Iterates over the headers assembling the evidence values, considering the 
 * prefixes, in the buffer if available. The call back method is called for 
 * each header or pseudo header available. The buffer is only used with pseudo
 * headers where multiple header values need to be combined into a single 
 * value.
 *
 * @param evidence key value pairs including prefixes
 * @param prefixes one or more prefix flags to return values for
 * @param state pointer passed to the callback method
 * @param headers to return evidence for if available
 * @param buffer that MIGHT be used with the callback, null to disable 
 * assembling headers
 * @param length of the buffer
 * @param callback method called when a matching prefix is found
 * @return true if the callback was called successfully, otherwise false
 */
EXTERNAL bool fiftyoneDegreesEvidenceIterateForHeaders(
	fiftyoneDegreesEvidenceKeyValuePairArray* evidence,
	int prefixes,
	fiftyoneDegreesHeaderPtrs* headers,
	char* const buffer,
	size_t const length,
	void* state,
	fiftyoneDegreesEvidenceIterateMethod callback);

/**
 * @}
 */

#endif
/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2023 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

#ifndef FIFTYONE_DEGREES_MANAGER_INCLUDED
#define FIFTYONE_DEGREES_MANAGER_INCLUDED

/**
 * @ingroup FiftyOneDegreesCommon
 * @defgroup FiftyOneDegreesResource Resource Manager
 *
 * Resources to be managed by a resource manager.
 *
 * ## Terms
 * 
 * **Resource** : a pointer to anything which needs to be replaced or freed in
 * a thread-safe manor
 *
 * **Manager** : manages access to a resource by handing out handles and
 * altering the resource safely
 *
 * **Handle** : a reference to a resource which is being managed. This is the
 * only way in which a resource should be accessed
 *
 * ## Introduction
 *
 * A Resource is a structure which can be changed or freed at any time, so
 * is managed by a resource manager to allow safe concurrent access. Any
 * resource which is being used will not be changed or freed until the last
 * reference to it has been released.
 *
 * ## Create
 *
 * A resource manager is created by allocating the memory for the structure and
 * calling the #fiftyoneDegreesResourceManagerInit method to give it a resource
 * to manage, and a method to free it when necessary.
 *
 * ## Get
 *
 * A handle to a resource can be fetched from a resource manager using the
 * #fiftyoneDegreesResourceHandleIncUse method. This increments the "in use"
 * counter in a thread safe manor and returns an exclusive handle to the
 * resource.
 *
 * When getting a handle to a resource, if all the available handles are in use
 * then the method will block until one is available.
 *
 * ## Release
 *
 * Once a resource handle is finished with, it must be released back to the
 * resource manager using the #fiftyoneDegreesResourceHandleDecUse method. This
 * releases the handle so it is available to other threads.
 *
 * ## Free
 *
 * A resource manager is freed, along with its resource, using the
 * #fiftyoneDegreesResourceManagerFree method. This prevents any new handles
 * from being acquired, and frees the resource being managed.
 * If the resource has active handles, then a free method does not block.
 * Instead it prevents new handles from being acquired and sets the manager
 * to free the resource once the last handle has been released.
 *
 *
 * ## Replace
 *
 * A resource can be replaced using the #fiftyoneDegreesResourceReplace method.
 * This swaps the resource being managed so that any new requests for a handle
 * return the new resource. The existing resource is freed once the last active
 * handle to it has been released.
 *
 * ## Usage Example
 *
 * ```
 * typedef struct someResourceType {
 *     fiftyoneDegreesResourceHandle *handle; 
 *     void *data;
 * }
 * someResourceType *resource;
 * fiftyoneDegreesResourceManager manager;
 *
 * // Initialise the resource manager with a resource
 * fiftyoneDegreesResourceManagerInit(
 *     &manager,
 *     resource,
 *     &resource->handle,
 *     Free);
 *
 * // Check that the resource handle was set successfully
 * if (resource->handle != NULL) {
 *
 *     // Get a handle to the resource to ensure it is not freed by any
 *     // other threads
 *     someResourceType *localResource = (someResourceType*)
 *         fiftyoneDegreesResourceHandleIncUse(&manager)->resource;
 *
 *     // Free the resource. This operation will be postponed until there are
 *     // no remaining handled being used
 *     fiftyoneDegreesResourceManagerFree(&manager);
 *
 *     // Do something with the resource while it is guaranteed to be available
 *     // ...
 *
 *     // Release the resource so other threads know it is eligible for freeing
 *     fiftyoneDegreesResourceHandleDecUse(resource->handle);
 *
 *     // This is the point where the call to free the manager will actually
 *     // be carried out now that nothing is referencing the resource
 * }
 * ```
 *
 * @{
 */

/* Define NDEBUG if needed, to ensure asserts are disabled in release builds */
#if !defined(DEBUG) && !defined(_DEBUG) && !defined(NDEBUG)
#define NDEBUG
#endif

#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

/** @cond FORWARD_DECLARATIONS */
typedef struct fiftyone_degrees_resource_manager_t
	fiftyoneDegreesResourceManager;

typedef struct fiftyone_degrees_resource_handle_t
    fiftyoneDegreesResourceHandle;
/** @endcond */

/**
 * Handle for a shared resource. The first data structure counter tracks use
 * of the resource and free resources that are not longer active.
 * Counter must be the first member to ensure correct memory aligned for 
 * interlocked operations.
 */
typedef struct fiftyone_degrees_resource_handle_t {
#ifndef FIFTYONE_DEGREES_NO_THREADING
    volatile 
#endif 
    fiftyoneDegreesInterlockDoubleWidth counter; /**< Counter for this 
                                                 handle. */
    const void* resource; /**< Pointer to the resource being managed. */
    const fiftyoneDegreesResourceManager* manager; /**< Pointer to the manager
                                                   the handle relates to. */
    void(*freeResource)(void*); /**< Pointer to the method used to free the
                                resource. */
} fiftyoneDegreesResourceHandle;

/**
 * Manager structure used to provide access to a shared and changing resource.
 */
typedef struct fiftyone_degrees_resource_manager_t {
#ifndef FIFTYONE_DEGREES_NO_THREADING
    volatile fiftyoneDegreesResourceHandle *active; /**< Current handle
                                                    for resource used 
                                                    by the manager. */
#else
	fiftyoneDegreesResourceHandle *active; /**< Non volatile current handle for
										   the resource used by the manager. */
#endif
} fiftyoneDegreesResourceManager;

/**
 * Initialise a preallocated resource manager structure with a resource for it
 * to manage access to.
 * The resourceHandle parameter must point to the handle within the resource
 * under management so that the handle can be assigned to the resource before
 * the resource is placed under management.
 *
 * @param manager the resource manager to initialise with the resource
 * @param resource pointer to the resource which the manager should manage
 * access to
 * @param resourceHandle points to the location the new handle should be stored
 * @param freeResource method to use when freeing the resource
 */
EXTERNAL void fiftyoneDegreesResourceManagerInit(
	fiftyoneDegreesResourceManager *manager,
	void *resource,
	fiftyoneDegreesResourceHandle **resourceHandle,
	void(*freeResource)(void*));

/**
 * Frees any data associated with the manager and releases the manager. All 
 * memory is released after this operation.
 *
 * @param manager the resource manager to be freed
 */
EXTERNAL void fiftyoneDegreesResourceManagerFree(
	fiftyoneDegreesResourceManager *manager);

/**
 * Increments the usage counter for the resource and returns a handle that can
 * be used to reference it. The handle **MUST** be used to decrement the use
 * count using the #fiftyoneDegreesResourceHandleDecUse method when the
 * resource is finished with. The resource can be guaranteed not to be freed
 * until after the decrement method has been called.
 * @param manager the resource manager to initialise with the resource
 */
EXTERNAL fiftyoneDegreesResourceHandle* fiftyoneDegreesResourceHandleIncUse(
	fiftyoneDegreesResourceManager *manager);

/**
 * Decrements the usage counter. If the count reaches zero then resource will
 * become eligible to be freed either when the manager replaces it or when the
 * manager is freed.
 * @param handle to the resource which should be released by the manager
 */
EXTERNAL void fiftyoneDegreesResourceHandleDecUse(
	fiftyoneDegreesResourceHandle *handle);

/**
 * Return the current usage counter.
 * WARNING: This call is not thread-safe and is suitable for using in
 * testing only.
 * @param handle to the resource which should be released by the manager
 * @return the current usage counter
 */
EXTERNAL int32_t fiftyoneDegreesResourceHandleGetUse(
	fiftyoneDegreesResourceHandle *handle);

/**
 * Replaces the resource with the new resource. If the existing resource is 
 * not being used it will be freed. Otherwise it is left to the decrement 
 * function to free the resource when the usage count is zero.
 * @param manager the resource manager to initialise with the resource
 * @param newResource pointer to the resource which the manager should manage
 * access to
 * @param newResourceHandle points to the location the new handle should be
 * stored
 */
EXTERNAL void fiftyoneDegreesResourceReplace(
	fiftyoneDegreesResourceManager *manager,
	void *newResource,
	fiftyoneDegreesResourceHandle **newResourceHandle);

/**
 * @}
 */

#endif
/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2023 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

/**
 * @ingroup FiftyOneDegreesCommon
 * @defgroup FiftyOneDegreesProperties Properties
 *
 * Structures for properties which are available, or required.
 *
 * ## Terms
 *
 * **Required Property Index** : the 0 based index of the property in the list
 * of required properties. Not the same as the property index.
 *
 * **Property Index** : the 0 based index of the property in the source used to 
 * create the required properties. Not the same as the required property index.
 *
 * **Results** : the structure used to contain the data associated with the 
 * available required properties.
 *
 * **Source** : the source of property names. Typically a call back method to
 * return properties from the data structure used by the aspect engine.
 *
 * ## Introduction
 *
 * Aspect engine performance can often be improved by limiting the properties
 * that can be returned from the engine. As this is a performance feature 
 * shared across different types of aspect engine the utility functions are
 * stored in the common C files.
 *
 * Required properties could be specified at initialisation as a character 
 * separated string, as an array of strings or from an existing set of 
 * properties already obtained from these methods. In all scenarios it is 
 * desirable to be able to query the properties and find their indexes in the 
 * source data structure using a consistent set of methods.
 *
 * ## Creation
 *
 * #fiftyoneDegreesPropertiesCreate is used to create a consistent set of 
 * required properties. The structure passed must have one of the follow set.
 *
 * 1. Separated string of property names. Valid separators include space,
 * comma and pipe.
 * 2. An array of strings.
 * 3. Existing properties results from a previous creation operation. This 
 * method is used when a data set is being reloaded due to a change in the 
 * underlying data.
 *
 * Creation also requires a method to retrieve the name of the properties from 
 * the underlying data source. A method pointer conforming to 
 * #fiftyoneDegreesPropertiesGetMethod must be provided to retrieve the
 * property name string item for a given property index up to the maximum
 * count. The call back is used to avoid any hard dependency between the data
 * structure and the properties methods.
 *
 * Unlike standard collection item retrieval the properties methods will not 
 * know the underlying collection implement or reference from which the item 
 * was obtained from. Therefore the implementation of get MUST set the 
 * collection field of the collection item.
 *
 * Some, or all, of the required properties may not be present in the
 * underlying data source. Any missing properties will be ignored in the
 * results. The get  name from required index method can be used to iterate
 * over the available  properties. The number of available properties after
 * creation can be obtained  from the count field of properties results.
 *
 * Whilst the property names can be provided as string(s) the property names 
 * referenced from the properties results are collection items from a strings 
 * collection. The properties methods are responsible for releasing the 
 * references to these strings when the properties results are freed.
 *
 * The resulting require properties index will be in ascending order of the 
 * property name a string. As such the ordered list can be used with a binary 
 * search (divide and conquer) to quickly determine the required property index
 * from the property name.
 *
 * ## Free
 *
 * When the properties results are finished with, the 
 * #fiftyoneDegreesPropertiesFree method must be used. This will also free the 
 * collection items used to reference the property name strings using the 
 * collection field of the item to obtain the source collection. This
 * collection must have been set by the get method used at creation.
 *
 * ## Operation
 *
 * Several methods are available which can be used to convert from an input 
 * such as a property name or required property index to a property index in 
 * the data structure. The method names are self-explanatory.
 *
 * Where possible using integer property or required property indexes is 
 * preferable to the string representation of the property as this improves 
 * performance.
 *
 * @{
 */

#ifndef FIFTYONE_DEGREES_PROPERTIES_H_INCLUDED
#define FIFTYONE_DEGREES_PROPERTIES_H_INCLUDED

#include <stdint.h>
#ifdef _MSC_FULL_VER
#include <string.h>
#else
#include <strings.h>
#define _stricmp strcasecmp
#define _strnicmp strncasecmp
#endif

/**
 * Index in the properties collection to a property which is required to get
 * evidence for another property.
 */
typedef uint32_t fiftyoneDegreesEvidencePropertyIndex;

FIFTYONE_DEGREES_ARRAY_TYPE(fiftyoneDegreesEvidencePropertyIndex, )

/**
 * Array of properties which are required to fetch additional evidence for
 * a specific property.
 */
typedef fiftyoneDegreesEvidencePropertyIndexArray fiftyoneDegreesEvidenceProperties;

/** Used to access the property item quickly without the need to search. */
typedef struct fiftyone_degrees_property_available_t {
	uint32_t propertyIndex; /**< Index of the property in the collection of all 
	                           properties*/
	fiftyoneDegreesCollectionItem name; /**< Name of the property from strings */
    fiftyoneDegreesEvidenceProperties *evidenceProperties; /**< Evidence
                                                           properties which are
                                                           required by this
                                                           property */
    bool delayExecution; /**< True if the execution any JavaScript returned as
                         a value of this property should be delayed. False if
                         it should be run immediately. This is always
                         initialized to false, so should be set by the calling
                         function */
} fiftyoneDegreesPropertyAvailable;

FIFTYONE_DEGREES_ARRAY_TYPE(fiftyoneDegreesPropertyAvailable,)

/** Array of properties which are available in a data set. */
typedef fiftyoneDegreesPropertyAvailableArray 
fiftyoneDegreesPropertiesAvailable;

/**
 * Defines a set of properties which are required by a caller. Usually to a
 * data set creation method.
 */
EXTERNAL typedef struct fiftyone_degrees_properties_required_t {
	const char **array; /**< Array of required properties or NULL if all 
	                        properties are required. See the count property for
	                        the number of items in the array */
	int count; /**< Number of properties in array */
	const char *string; /**< Separated list of required properties or NULL if 
	                        all properties are required */
	fiftyoneDegreesPropertiesAvailable *existing; /**< A pointer to an existing
	                                                  set of property names
													  from another instance */
} fiftyoneDegreesPropertiesRequired;

/**
 * Returns a string for the property at the index provided or NULL if there
 * is no property available at the index.
 * @param state resource used to obtain the string
 * @param index of the property
 * @param item used to obtain a handle to the string
 * @return pointer to the string or NULL if no property available
 */
typedef fiftyoneDegreesString*(*fiftyoneDegreesPropertiesGetMethod)(
	void *state,
	uint32_t index,
	fiftyoneDegreesCollectionItem *item);

/**
 * Populates the evidence properties structure with the indexes of the
 * properties required by the property provided, and returns the number
 * of property indexes which were added. If the evidence properties structure
 * is null, then this method returns the count but does not populate the
 * structure.
 * @param state pointer to data which the method may need to use
 * @param property pointer to the property to get the evidence properties for
 * @param evidenceProperties pointer to the pre-allocated structure to populate
 * with the evidence property indexes
 * @return the number of property indexes added to the structure. Or the number
 * which would have been added were it not null
 */
typedef uint32_t(*fiftyoneDegreesEvidencePropertiesGetMethod)(
    void* state,
    fiftyoneDegreesPropertyAvailable* property,
    fiftyoneDegreesEvidenceProperties* evidenceProperties);

/**
 * The default properties required to make all possible properties available.
 * Should be used to initialise a new instance of 
 * #fiftyoneDegreesPropertiesRequired.
 */
EXTERNAL_VAR fiftyoneDegreesPropertiesRequired fiftyoneDegreesPropertiesDefault;

/**
 * Creates a properties result instance for use with future property 
 * operations. The resulting required properties will be provided in ascending 
 * order.
 * @param properties required to be available as either a separated list of 
 * property names, an array of property names or an existing properties results 
 * structure from another data set. Valid separators include pipe, comma and 
 * space. The fields are evaluated in order of existing, array and then string.
 * the first field with a value is used.
 * @param state pointer to state used with the get method
 * @param getPropertyMethod method used to return the property name from a 
 * string collection
 * @param getEvidencePropertiesMethod method used to populate the evidence
 * properties for a property
 * @return instance of a properties result for use with future properties
 * methods
 */
EXTERNAL fiftyoneDegreesPropertiesAvailable* fiftyoneDegreesPropertiesCreate(
	fiftyoneDegreesPropertiesRequired *properties,
	void *state,
	fiftyoneDegreesPropertiesGetMethod getPropertyMethod,
    fiftyoneDegreesEvidencePropertiesGetMethod getEvidencePropertiesMethod);

/**
 * Gets the index of the property in the source data structure from the name.
 * @param available properties instance
 * @param propertyName string containing the property name
 * @return 0 based index of the property in the source or -1 if not available
 */
EXTERNAL int fiftyoneDegreesPropertiesGetPropertyIndexFromName(
	fiftyoneDegreesPropertiesAvailable *available,
	const char *propertyName);

/**
 * Gets the required property index in the list of all required properties from 
 * the name.
 * @param available properties instance
 * @param propertyName string containing the property name
 * @return 0 based index of the property in the required properties or -1 if 
 * not available
 */
EXTERNAL int fiftyoneDegreesPropertiesGetRequiredPropertyIndexFromName(
	fiftyoneDegreesPropertiesAvailable *available,
	const char *propertyName);

/**
 * Maps the required property index to the index in the source data structure.
 * @param available properties instance
 * @param requiredPropertyIndex index of the property in the required 
 * properties structure
 * @return 0 based index of the property in the source or -1 if not available
 */
EXTERNAL int fiftyoneDegreesPropertiesGetPropertyIndexFromRequiredIndex(
	fiftyoneDegreesPropertiesAvailable *available,
	int requiredPropertyIndex);

/**
 * Gets the name as a string from the required property index.
 * @param available properties instance
 * @param requiredPropertyIndex index of the property in the required
 * properties structure
 * @return string representation of the property
 */
EXTERNAL fiftyoneDegreesString* 
	fiftyoneDegreesPropertiesGetNameFromRequiredIndex(
		fiftyoneDegreesPropertiesAvailable *available,
		int requiredPropertyIndex);

/**
 * Check if the 'SetHeader' properties are included in the
 * available required properties.
 * @param available properties instance
 * @return bool whether 'SetHeader' properties are included
 */
EXTERNAL bool fiftyoneDegreesPropertiesIsSetHeaderAvailable(
	fiftyoneDegreesPropertiesAvailable* available);

/**
 * Frees the memory and resources used by the properties results previously 
 * created using the #fiftyoneDegreesPropertiesCreate method.
 * @param available properties instance to be freed
 */
EXTERNAL void fiftyoneDegreesPropertiesFree(
	fiftyoneDegreesPropertiesAvailable *available);

/**
 * @}
 */

#endif
/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2023 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

#ifndef FIFTYONE_DEGREES_DATE_H_INCLUDED
#define FIFTYONE_DEGREES_DATE_H_INCLUDED

/**
 * @ingroup FiftyOneDegreesCommon
 * @defgroup FiftyOneDegreesDate Date
 *
 * Represents a date in a data set.
 *
 * ## Introduction
 *
 * The Date structure is used to represent dates in data sets. This is a memory
 * efficient way to store a date, and means that the memory from a data file
 * can be read directly into a structure.
 *
 * @{
 */

#include <stdint.h>
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable: 5105) 
#include <windows.h>
#pragma warning (default: 5105) 
#pragma warning (pop)
#endif


/**
 * Used to store the date when the dataset was produced and next date 51Degrees
 * expect to provide a new data file. Has to be packed at one byte because the 
 * date occurs in the data files in this form.
 */
#pragma pack(push, 1)
typedef struct fiftyone_degrees_date_t {
	int16_t year; /**< Year */
	byte month; /**< Month */
	byte day; /**< Day of the Month */
} fiftyoneDegreesDate;
#pragma pack(pop)

/**
 * @}
 */

#endif
/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2023 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

#ifndef FIFTYONE_DEGREES_COMPONENT_H_INCLUDED
#define FIFTYONE_DEGREES_COMPONENT_H_INCLUDED

/**
 * @ingroup FiftyOneDegreesCommon
 * @defgroup FiftyOneDegreesComponent Component
 *
 * Component of a data set.
 *
 * ## Introduction
 *
 * A Component is stored in a components collection and contains the meta data
 * for a specific component in a data set. Each component relates to a set of
 * properties which a profile relating to the component will hold the values
 * for.
 *
 * ## Get
 *
 * As there are generally only a small number of components in a data set, they
 * can be accessed via a list structure instead of fetching from the base
 * collection. This ensures that a reference the collection item is always held
 * open and can be used at any time.
 *
 * @{
 */

#include <stdint.h>
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable: 5105) 
#include <windows.h>
#pragma warning (default: 5105) 
#pragma warning (pop)
#endif

/**
 * Key value pair contained in each component. This can point to anything. For
 * example, in the Hash device detection API, the key is the unique id of an
 * HTTP header, and the value is the index of the set of root nodes to use.
 */
typedef struct fiftyoneDegrees_component_keyvaluepair_t {
	uint32_t key; /**< Integer key */
	uint32_t value; /**< Integer value */
} fiftyoneDegreesComponentKeyValuePair;

/**
 * A component of a data set. For example a hardware component contains
 * profiles relating to the hardware properties of a device.
 */
#pragma pack(push, 1)
typedef struct fiftyoneDegrees_component_t {
	const byte componentId; /**< The unique Id of the component. */
	const int32_t nameOffset; /**< Offset in the strings data structure to the
	                               name */
	const int32_t defaultProfileOffset; /**< Offset in the profiles data
	                                         structure to the default profile */
	const uint16_t keyValuesCount; /**< The number of key value pairs at
								   firstKeyValuePair */
	const fiftyoneDegreesComponentKeyValuePair firstKeyValuePair; /**< The
																  first key
																  value pair */
} fiftyoneDegreesComponent;
#pragma pack(pop)

/**
 * Returns the string name of the component using the item provided. The
 * collection item must be released when the caller is finished with the
 * string.
 * @param component structure for the name required.
 * @param stringsCollection collection of strings retrieved by offsets.
 * @param item used to store the resulting string in.
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h
 * @return a pointer to a string in the collection item data structure.
 */
EXTERNAL fiftyoneDegreesString* fiftyoneDegreesComponentGetName(
	fiftyoneDegreesCollection *stringsCollection,
	fiftyoneDegreesComponent *component,
	fiftyoneDegreesCollectionItem *item,
	fiftyoneDegreesException *exception);

/**
 * Get a pointer to the key value pair at the specified index within the
 * component's key value pairs list.
 * This pointer does not need to be freed by the caller.
 * @param component to get the pair from
 * @param index of the pair within the component
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h
 * @return pointer to a key value pair
 */
const fiftyoneDegreesComponentKeyValuePair* 
fiftyoneDegreesComponentGetKeyValuePair(
	fiftyoneDegreesComponent *component,
	uint16_t index,
	fiftyoneDegreesException *exception);

/**
 * Initialises the list of components. This holds a reference to the collection
 * items so that collection get methods do not need to be called repeatedly.
 * @param components collection containing the components to add to the list
 * @param list to add the components to
 * @param count number of components in the collection
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h
 */
void fiftyoneDegreesComponentInitList(
	fiftyoneDegreesCollection *components,
	fiftyoneDegreesList *list,
	uint32_t count,
	fiftyoneDegreesException *exception);

#ifndef FIFTYONE_DEGREES_MEMORY_ONLY

/**
 * Read a component from the file collection provided and store in the data
 * pointer. This method is used when creating a collection from file.
 * @param file collection to read from
 * @param offset of the component in the collection
 * @param data to store the resulting component in
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h
 * @return pointer to the component allocated within the data structure
 */
void* fiftyoneDegreesComponentReadFromFile(
	const fiftyoneDegreesCollectionFile *file,
	uint32_t offset,
	fiftyoneDegreesData *data,
	fiftyoneDegreesException *exception);

#endif

/**
 * Get the default profile id for the component provided.
 * @param profiles collection containing the profiles from the same data set as
 * the component
 * @param component to get the default profile id for
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h
 */
EXTERNAL uint32_t fiftyoneDegreesComponentGetDefaultProfileId(
	fiftyoneDegreesCollection *profiles,
	fiftyoneDegreesComponent *component,
	fiftyoneDegreesException *exception);

/**
 * Where the component's key value pairs relate to headers creates an array of
 * pointers to the relevant headers in the same order as the key value pairs.
 * @param component to get the headers for
 * @param headers array to find the corresponding header in
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h
 */
EXTERNAL fiftyoneDegreesHeaderPtrs* fiftyoneDegreesComponentGetHeaders(
	fiftyoneDegreesComponent* component,
	fiftyoneDegreesHeaders* headers,
	fiftyoneDegreesException* exception);

/**
 * @}
 */

#endif
/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2023 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

#ifndef FIFTYONE_DEGREES_PROPERTY_H_INCLUDED
#define FIFTYONE_DEGREES_PROPERTY_H_INCLUDED

/**
 * @ingroup FiftyOneDegreesCommon
 * @defgroup FiftyOneDegreesProperty Property
 *
 * Property in a data set relating to a single component.
 *
 * ## Introduction
 *
 * A property is stored in a properties collection and contains the meta data
 * for a specific property in a data set.
 *
 * ## Get
 *
 * A property can be fetched from a properties collection in one of two ways:
 *
 * **By Index** : The #fiftyoneDegreesPropertyGet method return the property at
 * a specified index. This provides a way to access a property at a known
 * index, or iterate over all properties.
 *
 * **By Name** : If the index of a property is not known, then the property can
 * be fetched using the #fiftyoneDegreesPropertyGetByName method to find the
 * property in a properties collection.
 *
 * @{
 */

#include <stdint.h>
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable: 5105) 
#include <windows.h>
#pragma warning (default: 5105) 
#pragma warning (pop)
#endif

/**
 * Property structure containing all the meta data relating to a property.
 */
#pragma pack(push, 1)
typedef struct property_t {
	const byte componentIndex; /**< Index of the component */
	const byte displayOrder; /**< The order the property should be displayed in 
	                             relative to other properties */
	const byte isMandatory; /**< True if the property is mandatory and must be
	                            provided */
	const byte isList; /**< True if the property is a list can return multiple 
	                       values */
	const byte showValues; /**< True if the values should be shown in GUIs */
	const byte isObsolete; /**< True if the property is obsolete and will be 
	                           removed from future data sets */
	const byte show; /**< True if the property should be shown in GUIs */
	const byte valueType; /**< The type of value the property represents */
	const uint32_t defaultValueIndex; /**< The default value index for the
	                                     property */
	const uint32_t nameOffset; /**< The offset in the strings structure to the 
	                               property name */
	const uint32_t descriptionOffset; /**< The offset in the strings structure
	                                      to the property description */
	const uint32_t categoryOffset; /**< The offset in the strings structure to
	                                   the property category */
	const uint32_t urlOffset; /**< The offset in the strings structure to the
	                              property URL */
	const uint32_t firstValueIndex; /**< Index of the first possible value */
	const uint32_t lastValueIndex; /**< Index of the last possible value */
	const uint32_t mapCount; /**< Number of maps the property is associated with */
	const uint32_t firstMapIndex; /**< The first index in the list of maps the
	                                  property is associated with */
} fiftyoneDegreesProperty;
#pragma pack(pop)

/**
 * Property structure containing stored type of a property.
 */
#pragma pack(push, 1)
typedef struct property_type_record_t {
	const uint32_t nameOffset; /**< The offset in the strings structure to the
	                               property name */
	const byte storedValueType; /**< The type of value the property is stored as */
} fiftyoneDegreesPropertyTypeRecord;
#pragma pack(pop)

/**
 * Returns the string name of the property using the item provided. The 
 * collection item must be released when the caller is finished with the
 * string.
 * @param stringsCollection collection of strings retrieved by offsets.
 * @param property structure for the name required.
 * @param item used to store the resulting string in.
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return a pointer to a string in the collection item data structure.
 */
EXTERNAL fiftyoneDegreesString* fiftyoneDegreesPropertyGetName(
	fiftyoneDegreesCollection *stringsCollection,
	fiftyoneDegreesProperty *property,
	fiftyoneDegreesCollectionItem *item,
	fiftyoneDegreesException *exception);

/**
 * Returns the type the property is stored as.
 * @param propertyTypesCollection collection of property types retrieved by offsets.
 * @param property structure for the type required.
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return a type the property is stored as.
 */
EXTERNAL fiftyoneDegreesPropertyValueType fiftyoneDegreesPropertyGetStoredType(
	fiftyoneDegreesCollection *propertyTypesCollection,
	fiftyoneDegreesProperty *property,
	fiftyoneDegreesException *exception);

/**
 * Returns the type the property is stored as.
 * @param propertyTypesCollection collection of property types retrieved by offsets.
 * @param index of the property to get
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return a type the property is stored as.
 */
EXTERNAL fiftyoneDegreesPropertyValueType fiftyoneDegreesPropertyGetStoredTypeByIndex(
	fiftyoneDegreesCollection *propertyTypesCollection,
	uint32_t index,
	fiftyoneDegreesException *exception);

/**
 * Returns the string description of the property using the item provided. The
 * collection item must be released when the caller is finished with the
 * string.
 * @param stringsCollection collection of strings retrieved by offsets.
 * @param property structure for the description required.
 * @param item used to store the resulting string in.
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return a pointer to a string in the collection item data structure.
 */
EXTERNAL fiftyoneDegreesString* fiftyoneDegreesPropertyGetDescription(
	fiftyoneDegreesCollection *stringsCollection,
	fiftyoneDegreesProperty *property,
	fiftyoneDegreesCollectionItem *item,
	fiftyoneDegreesException *exception);

/**
 * Returns the string category of the property using the item provided. The
 * collection item must be released when the caller is finished with the
 * string.
 * @param stringsCollection collection of strings retrieved by offsets.
 * @param property structure for the category required.
 * @param item used to store the resulting string in.
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return a pointer to a string in the collection item data structure.
 */
EXTERNAL fiftyoneDegreesString* fiftyoneDegreesPropertyGetCategory(
	fiftyoneDegreesCollection *stringsCollection,
	fiftyoneDegreesProperty *property,
	fiftyoneDegreesCollectionItem *item,
	fiftyoneDegreesException *exception);

/**
 * Returns the string URL of the property using the item provided. The
 * collection item must be released when the caller is finished with the
 * string.
 * @param stringsCollection collection of strings retrieved by offsets.
 * @param property structure for the URL required.
 * @param item used to store the resulting string in.
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return a pointer to a string in the collection item data structure.
 */
EXTERNAL fiftyoneDegreesString* fiftyoneDegreesPropertyGetUrl(
	fiftyoneDegreesCollection *stringsCollection,
	fiftyoneDegreesProperty *property,
	fiftyoneDegreesCollectionItem *item,
	fiftyoneDegreesException *exception);

/**
 * Gets the value type for the property at the index in the collection.
 * @param properties collection to retrieve the property type from
 * @param index of the property in the collection
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return the value type as a byte for the property at the index.
 */
EXTERNAL byte fiftyoneDegreesPropertyGetValueType(
	fiftyoneDegreesCollection *properties,
	uint32_t index,
	fiftyoneDegreesException *exception);

/**
 * Gets the property at the requested index from the properties collection
 * provided.
 * @param properties to get the property from
 * @param index of the property to get
 * @param item to store the property item in
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return the property requested or NULL
 */
EXTERNAL fiftyoneDegreesProperty* fiftyoneDegreesPropertyGet(
	fiftyoneDegreesCollection *properties,
	uint32_t index,
	fiftyoneDegreesCollectionItem *item,
	fiftyoneDegreesException *exception);

/**
 * Gets the property with the requested name from the properties collection
 * provided.
 * @param properties to get the property from
 * @param strings collection containing the names of the properties
 * @param requiredPropertyName name of the property to get
 * @param item to store the property item in
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return the property requested or NULL
 */
EXTERNAL fiftyoneDegreesProperty* fiftyoneDegreesPropertyGetByName(
	fiftyoneDegreesCollection *properties,
	fiftyoneDegreesCollection *strings,
	const char *requiredPropertyName,
	fiftyoneDegreesCollectionItem *item,
	fiftyoneDegreesException *exception);

/** 
 * @}
 */

#endif
/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2023 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

#ifndef FIFTYONE_DEGREES_PROPERTY_VALUE_H_INCLUDED
#define FIFTYONE_DEGREES_PROPERTY_VALUE_H_INCLUDED

/**
 * @ingroup FiftyOneDegreesCommon
 * @defgroup FiftyOneDegreesValue Values
 *
 * Value of a data set relating to a property.
 *
 * ## Introduction
 *
 * A Value is stored in a values collection and contains the meta data for a
 * specific value of a property in a data set.
 *
 * ## Get
 *
 * A value can be fetched from a values collection in one of two ways:
 *
 * **By Index** : the #fiftyoneDegreesValueGet method return the value at a
 * specified index. This provides a way to access a value at a known index, or
 * iterate over all values.
 *
 * **By Name** : if the index of a value is not known, then the value can be
 * fetched using the #fiftyoneDegreesValueGetByName method to find the value in
 * a values collection. This requires that the property the value relates to is
 * also known, as values are only unique within the values which relate to a
 * single property. For example "True" could be a value of many properties.
 *
 * @{
 */

#include <stdint.h>
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable: 5105) 
#include <windows.h>
#pragma warning (default: 5105) 
#pragma warning (pop)
#endif
/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2023 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

#ifndef FIFTYONE_DEGREES_STORED_BINARY_VALUE_H_INCLUDED
#define FIFTYONE_DEGREES_STORED_BINARY_VALUE_H_INCLUDED

/**
 * @ingroup FiftyOneDegreesCommon
 * @defgroup FiftyOneDegreesString String
 *
 * Byte array structures containing raw data bytes.
 *
 * @{
 */

#include <stdint.h>
#include <ctype.h>

/**
 * Structure containing raw bytes and size from data files.
 *
 * @example
 * String:
 * 			Short – length – 10
 * 			Byte value – first character of string – '5'
 * @example
 * Byte array:
 * 			Short – length – 3
 * 			Byte[] – bytes – [ 1, 2 ]
 * @example
 * IP (v4) address:
 * 			Short – length – 5
 * 			Byte[] – IP – [ 1, 2, 3, 4 ]
 * @example
 * WKB (value of  POINT(2.0 4.0)):
 * 			Short – length - 21
 * 			Byte[] – value – [
 * 				0 (endianness),
 * 				0, 0, 0, 1 (2D point),
 * 				128, 0, 0, 0, 0, 0, 0, 0 (2.0 float),
 * 				128, 16, 0, 0, 0, 0, 0, 0 (4.0 float)
 * 			]
 */
#pragma pack(push, 1)
typedef struct fiftyone_degrees_var_length_byte_array_t {
 int16_t size; /**< Size of the byte array in memory (starting from 'firstByte') */
 unsigned char firstByte; /**< The first byte of the array */
} fiftyoneDegreesVarLengthByteArray;
#pragma pack(pop)

/**
 * "Packed" value that can be present inside "strings" of dataset.
 */
#pragma pack(push, 1)
typedef union fiftyone_degrees_stored_binary_value_t {
 fiftyoneDegreesString stringValue; /**< String value (ASCII or UTF-8) */
 fiftyoneDegreesVarLengthByteArray byteArrayValue; /**< Byte array value (e.g. IP or WKB) */
 fiftyoneDegreesFloat floatValue; /**< single precision floating point value */
 int32_t intValue; /**< Integer value */
 int16_t shortValue; /**< Short value. Potentially half(-precision float). */
} fiftyoneDegreesStoredBinaryValue;
#pragma pack(pop)

#ifndef FIFTYONE_DEGREES_MEMORY_ONLY

/**
 * Reads a binary value from the source file at the offset within the string
 * structure.
 * @param file collection to read from
 * @param offset of the string in the collection
 * @param data to store the new string in
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return a pointer to the string collection item or NULL if can't be found
 * @note expects `data` to contain `fiftyoneDegreesPropertyValueType`
 * matching the stored value type of the property this value belongs to.
 */
EXTERNAL void* fiftyoneDegreesStoredBinaryValueRead(
 const fiftyoneDegreesCollectionFile *file,
 uint32_t offset,
 fiftyoneDegreesData *data,
 fiftyoneDegreesException *exception);

#endif

/**
 * Gets the binary value at the required offset from the collection provided.
 * @param strings collection to get the string from
 * @param offset of the string in the collection
 * @param storedValueType format of byte array representation
 * @param item to store the string in
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return a pointer to binary value or NULL if the offset is not valid
 */
EXTERNAL fiftyoneDegreesStoredBinaryValue* fiftyoneDegreesStoredBinaryValueGet(
 fiftyoneDegreesCollection *strings,
 uint32_t offset,
 fiftyoneDegreesPropertyValueType storedValueType,
 fiftyoneDegreesCollectionItem *item,
 fiftyoneDegreesException *exception);

/**
 * Function to compare the current binary value to the
 * target string value using the text format.
 * @param value the current binary value item
 * @param storedValueType format of byte array representation
 * @param target the target search value.
 * @param tempBuilder temporary builder to stringify value into.
 * @return 0 if they are equal, otherwise negative
 * for smaller and positive for bigger
 */
EXTERNAL int fiftyoneDegreesStoredBinaryValueCompareWithString(
 const fiftyoneDegreesStoredBinaryValue *value,
 fiftyoneDegreesPropertyValueType storedValueType,
 const char *target,
 fiftyoneDegreesStringBuilder *tempBuilder,
 fiftyoneDegreesException *exception);

/**
 * Function to convert the binary value to int when possible.
 * @param value the current binary value item
 * @param storedValueType format of byte array representation
 * @param defaultValue fallback result.
 * @return converted value (when possible)
 * or default one (when type is not convertible).
 */
EXTERNAL int fiftyoneDegreesStoredBinaryValueToIntOrDefault(
 const fiftyoneDegreesStoredBinaryValue *value,
 fiftyoneDegreesPropertyValueType storedValueType,
 int defaultValue);

/**
 * Function to convert the binary value to double when possible.
 * @param value the current binary value item
 * @param storedValueType format of byte array representation
 * @param defaultValue fallback result.
 * @return converted value (when possible)
 * or default one (when type is not convertible).
 */
EXTERNAL double fiftyoneDegreesStoredBinaryValueToDoubleOrDefault(
 const fiftyoneDegreesStoredBinaryValue *value,
 fiftyoneDegreesPropertyValueType storedValueType,
 double defaultValue);

/**
 * Function to convert the binary value to bool when possible.
 * @param value the current binary value item
 * @param storedValueType format of byte array representation
 * @param defaultValue fallback result.
 * @return converted value (when possible)
 * or default one (when type is not convertible).
 */
EXTERNAL bool fiftyoneDegreesStoredBinaryValueToBoolOrDefault(
 const fiftyoneDegreesStoredBinaryValue *value,
 fiftyoneDegreesPropertyValueType storedValueType,
 bool defaultValue);

/**
 * @}
 */

#endif
/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2023 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

#ifndef FIFTYONE_DEGREES_PROFILE_H_INCLUDED
#define FIFTYONE_DEGREES_PROFILE_H_INCLUDED

/**
 * @ingroup FiftyOneDegreesCommon
 * @defgroup FiftyOneDegreesProfile Profile
 *
 * Profile containing a unique set of values for the properties of a single
 * component.
 *
 * ## Introduction
 *
 * A Profile is stored in a profiles collection and contains the meta data for
 * a specific profile for a component in a data set. Each profile contains
 * a unique set of values for a single component.
 *
 * ## Get
 *
 * A Profile can be fetched from a profiles collection in one of two ways:
 *
 * **By Index** : The #fiftyoneDegreesProfileGetByIndex method return the
 * profile at a specified index. This provides a way to access a profile at a
 * known index, or iterate over all values.
 *
 * **By Id** : If the index of a profile is not known, then the profile can be
 * fetched using the #fiftyoneDegreesProfileGetByProfileId method to find the
 * profile in a profiles collection.
 *
 * ## Iterate
 *
 * A profiles collection can be iterated in two ways:
 *
 * **Values** : The #fiftyoneDegreesProfileIterateValuesForProperty method can
 * be used to iterate over all the values which a profile contains for a
 * specified property.
 *
 * **Profiles** : The #fiftyoneDegreesProfileIterateProfilesForPropertyAndValue
 * method can be used to iterate over all the profiles in a profiles collection
 * which contain a specified property and value pairing.
 *
 * @{
 */

#include <stdint.h>
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable: 5105) 
#include <windows.h>
#pragma warning (default: 5105) 
#pragma warning (pop)
#endif
/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2023 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

#ifndef FIFTYONE_DEGREES_INDICES_H_INCLUDED
#define FIFTYONE_DEGREES_INDICES_H_INCLUDED

 /**
  * @ingroup FiftyOneDegreesCommon
  * @defgroup FiftyOneDegreesIndices Indices
  *
  * A look up structure for profile and property index to the first value 
  * associated with the property and profile.
  *
  * ## Introduction
  * 
  * Data sets relate profiles to the values associated with them. Values are
  * associated with properties. The values associated with a profile are 
  * ordered in ascending order of property. Therefore when a request is made to
  * obtain the value for a property and profile the values needed to be 
  * searched using a binary search to find a value related to the property. 
  * Then the list of prior values is checked until the first value for the 
  * property is found.
  * 
  * The indices methods provide common functionality to create a structure
  * that directly relates profile ids and required property indexes to the 
  * first value index thus increasing the efficiency of retrieving values.
  * 
  * It is expected these methods will be used during data set initialization.
  * 
  * ## Structure
  * 
  * A sparse array of profile ids and required property indexes is used. Whilst
  * this consumes more linear memory than a binary tree or other structure it 
  * is extremely fast to retrieve values from. As the difference between the 
  * lowest and highest profile id is relatively small the memory associated 
  * with absent profile ids is considered justifiable considering the 
  * performance benefit. A further optimization is to use the required property
  * index rather than the index of all possible properties contained in the 
  * data set. In most use cases the caller only requires a sub set of 
  * properties to be available for retrieval.
  * 
  * ## Create
  * 
  * fiftyoneDegreesIndicesPropertyProfileCreate should be called once the data
  * set is initialized with the required data structures. Memory is allocated
  * by the method and a pointer to the index data structure is returned. The
  * caller is not expected to use the returned data structure directly.
  * 
  * Some working memory is allocated during the indexing process. Therefore 
  * this method must be called before a freeze on allocating new memory is
  * required.
  * 
  * ## Free
  * 
  * fiftyoneDegreesIndicesPropertyProfileFree is used to free the memory used
  * by the index returned from Create. Must be called during the freeing of the
  * related data set.
  * 
  * ## Lookup
  * 
  * fiftyoneDegreesIndicesPropertyProfileLookup is used to return the index in
  * the values associated with the profile for the profile id and the required
  * property index.
  * 
  * @{
  */

#include <stdint.h>
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable: 5105) 
#include <windows.h>
#pragma warning (default: 5105) 
#pragma warning (pop)
#endif

/**
 * Maps the profile index and the property index to the first value index of 
 * the profile for the property. Is an array of uint32_t with entries equal to 
 * the number of properties multiplied by the difference between the lowest and
 * highest profile id.
 */
typedef struct fiftyone_degrees_index_property_profile{
	uint32_t* valueIndexes; // array of value indexes
	uint32_t availablePropertyCount; // number of available properties
	uint32_t minProfileId; // minimum profile id
	uint32_t maxProfileId; // maximum profile id
	uint32_t profileCount; // total number of profiles
	uint32_t size; // number elements in the valueIndexes array
	uint32_t filled; // number of elements with values
} fiftyoneDegreesIndicesPropertyProfile;

/**
 * Create an index for the profiles, available properties, and values provided 
 * such that given the index to a property and profile the index of the first 
 * value can be returned by calling fiftyoneDegreesIndicesPropertyProfileLookup.
 * @param profiles collection of variable sized profiles to be indexed
 * @param profileOffsets collection of fixed offsets to profiles to be indexed
 * @param available properties provided by the caller
 * @param values collection to be indexed
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h
 * @return pointer to the index memory structure
 */
EXTERNAL fiftyoneDegreesIndicesPropertyProfile*
fiftyoneDegreesIndicesPropertyProfileCreate(
	fiftyoneDegreesCollection* profiles,
	fiftyoneDegreesCollection* profileOffsets,
	fiftyoneDegreesPropertiesAvailable* available,
	fiftyoneDegreesCollection* values,
	fiftyoneDegreesException* exception);

/**
 * Frees an index previously created by 
 * fiftyoneDegreesIndicesPropertyProfileCreate.
 * @param index to be freed
 */
EXTERNAL void fiftyoneDegreesIndicesPropertyProfileFree(
	fiftyoneDegreesIndicesPropertyProfile* index);

/**
 * For a given profile id and available property index returns the first value 
 * index, or null if a first index can not be determined from the index. The
 * indexes relate to the collections for profiles, properties, and values 
 * provided to the fiftyoneDegreesIndicesPropertyProfileCreate method when the 
 * index was created. The availablePropertyIndex is not the index of all 
 * possible properties, but the index of the ones the data set was created 
 * expecting to return.
 * @param index from fiftyoneDegreesIndicesPropertyProfileCreate to use
 * @param profileId the values need to relate to
 * @param availablePropertyIndex in the list of required properties
 * @return the index in the list of values for the profile for the first value 
 * associated with the property
 */
EXTERNAL uint32_t fiftyoneDegreesIndicesPropertyProfileLookup(
	fiftyoneDegreesIndicesPropertyProfile* index,
	uint32_t profileId,
	uint32_t availablePropertyIndex);

/**
 * @}
 */

#endif

/**
 * Encapsulates a profile stored within a data set. A profile pertains to a
 * specific set of values for the properties relating to a single component.
 */
#pragma pack(push, 1)
typedef struct fiftyoneDegrees_profile_t {
	const byte componentIndex; /**< The index of the component the profile
	                               relates to */
	const uint32_t profileId; /**< Unique id of the profile */
	const uint32_t valueCount; /**< The number of values within the profile */
} fiftyoneDegreesProfile;
#pragma pack(pop)

/**
 * Structure containing the unique id of the profile, and the offset needed to
 * retrieve the actual profile structure from a profiles collection. This takes
 * up less space than the full profile and are of a fixed size, so can be
 * passed around and iterated over more easily.
 */
#pragma pack(push, 4)
typedef struct fiftyoneDegrees_profile_offset_t {
	const uint32_t profileId; /**< The unique Id of the profile */
	const uint32_t offset; /**< Offset to the profile in the profiles structure */
} fiftyoneDegreesProfileOffset;
#pragma pack(pop)

/**
 * Function that extracts "pure" profile offset
 * from a value inside `profileOffsets` collection
 * @param rawProfileOffset a "raw" value retrieved from `profileOffsets`
 * @return Offset to the profile in the profiles structure
 */
typedef uint32_t (*fiftyoneDegreesProfileOffsetValueExtractor)(const void *rawProfileOffset);

/**
 * Function that extracts "pure" profile offset
 * from a fiftyoneDegreesProfileOffset.
 * @param rawProfileOffset a "raw" ProfileOffset retrieved from `profileOffsets`
 * @return Offset to the profile in the profiles structure
 */
uint32_t fiftyoneDegreesProfileOffsetToPureOffset(const void *rawProfileOffset);

/**
 * Function that extracts "pure" profile offset
 * from a value (that starts with a "pure" profile offset)
 * inside `profileOffsets` collection
 * @param rawProfileOffset a "raw" value retrieved from `profileOffsets`
 * @return Offset to the profile in the profiles structure
 */
uint32_t fiftyoneDegreesProfileOffsetAsPureOffset(const void *rawProfileOffset);

/**
 * Definition of a callback function which is passed an item of a type 
 * determined by the iteration method.
 * @param state pointer to data needed by the method
 * @param item to store each profile in while iterating
 * @return true if the iteration should continue, otherwise false to stop
 */
typedef bool(*fiftyoneDegreesProfileIterateMethod)(
	void *state,
	fiftyoneDegreesCollectionItem *item);

/**
 * Definition of a callback function which is passed the next values index for
 * the profile.
 * @param state pointer to data needed by the method
 * @param valueIndex for the next value
 * @return true if the iteration should continue, otherwise false to stop
 */
typedef bool(*fiftyoneDegreesProfileIterateValueIndexesMethod)(
	void* state,
	uint32_t valueIndex);

/**
 * Gets the profile associated with the profileId or NULL if there is no
 * corresponding profile.
 * @param profileOffsets collection containing the profile offsets (with profile ID)
 * @param profiles collection containing the profiles referenced by the profile
 * offsets
 * @param profileId the unique id of the profile to fetch
 * @param item to set as the handle to the profile returned
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h
 * @return pointer to the profile or NULL
 */
EXTERNAL fiftyoneDegreesProfile* fiftyoneDegreesProfileGetByProfileId(
	fiftyoneDegreesCollection *profileOffsets,
	fiftyoneDegreesCollection *profiles,
	uint32_t profileId,
	fiftyoneDegreesCollectionItem *item,
	fiftyoneDegreesException *exception);

/**
 * Gets a pointer to the profile at the index provided. The index refers to the
 * index in the profile offsets collection as this contains fixed size entities
 * which can be quickly looked up. The variable sized profile is then returned
 * from that.
 * @param profileOffsets collection containing the profile offsets
 * @param profiles collection containing the profiles referenced by the profile
 * offsets
 * @param index of the profile to return
 * @param item to set as the handle to the profile returned
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h
 * @return pointer to the profile at the index
 */
EXTERNAL fiftyoneDegreesProfile* fiftyoneDegreesProfileGetByIndex(
	fiftyoneDegreesCollection *profileOffsets,
	fiftyoneDegreesCollection *profiles,
	uint32_t index,
	fiftyoneDegreesCollectionItem *item,
	fiftyoneDegreesException *exception);

#ifndef FIFTYONE_DEGREES_MEMORY_ONLY

/**
 * Read a profile from the file collection provided and store in the data
 * pointer. This method is used when creating a collection from file.
 * @param file collection to read from
 * @param offset of the profile in the collection
 * @param data to store the resulting profile in
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h
 * @return pointer to the profile allocated within the data structure
 */
void* fiftyoneDegreesProfileReadFromFile(
	const fiftyoneDegreesCollectionFile *file,
	uint32_t offset,
	fiftyoneDegreesData *data,
	fiftyoneDegreesException *exception);
#endif

/**
 * Iterate over all values contained in the profile which relate to the
 * specified property, calling the callback method for each.
 * @param values collection containing all values
 * @param profile pointer to the profile to iterate the values of
 * @param property which the values must relate to
 * @param state pointer containing data needed for the callback method
 * @param callback method to be called for each value
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h
 * @return the number of matching values which have been iterated
 */
EXTERNAL uint32_t fiftyoneDegreesProfileIterateValuesForProperty(
	fiftyoneDegreesCollection *values,
	fiftyoneDegreesProfile *profile,
	fiftyoneDegreesProperty *property,
	void *state,
	fiftyoneDegreesProfileIterateMethod callback,
	fiftyoneDegreesException *exception);

/**
 * Iterate over all values contained in the profile which relate to the
 * specified property and profile, calling the callback method for each.
 * @param values collection containing all values
 * @param index array of property and profile first value indexes
 * @param profileIndex the index of the profile
 * @param availablePropertyIndex the index of the available property
 * @param property which the values must relate to
 * @param state pointer containing data needed for the callback method
 * @param callback method to be called for each value
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h
 * @return the number of matching values which have been iterated
 */
EXTERNAL uint32_t fiftyoneDegreesProfileIterateValuesForPropertyWithIndex(
	fiftyoneDegreesCollection* values,
	fiftyoneDegreesIndicesPropertyProfile* index,
	uint32_t availablePropertyIndex,
	fiftyoneDegreesProfile* profile,
	fiftyoneDegreesProperty* property,
	void* state,
	fiftyoneDegreesProfileIterateMethod callback,
	fiftyoneDegreesException* exception);

/**
 * Iterate all profiles which contain the specified value, calling the callback
 * method for each.
 * @param strings collection containing the strings referenced properties and
 * values
 * @param properties collection containing all properties
 * @param propertyTypes collection containing types for all properties
 * @param values collection containing all values
 * @param profiles collection containing the profiles referenced by the profile
 * offsets
 * @param profileOffsets collection containing all profile offsets (with IDs)
 * @param propertyName name of the property the value relates to
 * @param valueName name of the value to iterate the profiles for
 * @param state pointer to data needed by the callback method
 * @param callback method to be called for each matching profile
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h
 * @return the number matching profiles which have been iterated
 */
EXTERNAL uint32_t fiftyoneDegreesProfileIterateProfilesForPropertyWithTypeAndValue(
	fiftyoneDegreesCollection *strings,
	fiftyoneDegreesCollection *properties,
	fiftyoneDegreesCollection *propertyTypes,
	fiftyoneDegreesCollection *values,
	fiftyoneDegreesCollection *profiles,
	fiftyoneDegreesCollection *profileOffsets,
	const char *propertyName,
	const char* valueName,
	void *state,
	fiftyoneDegreesProfileIterateMethod callback,
	fiftyoneDegreesException *exception);

/**
 * Iterate all profiles which contain the specified value, calling the callback
 * method for each.
 * @param strings collection containing the strings referenced properties and
 * values
 * @param properties collection containing all properties
 * @param propertyTypes collection containing types for all properties
 * @param values collection containing all values
 * @param profiles collection containing the profiles referenced by the profile
 * offsets
 * @param profileOffsets collection containing all profile offsets (any form)
 * @param offsetValueExtractor converts `profileOffsets` value to "pure" offset
 * @param propertyName name of the property the value relates to
 * @param valueName name of the value to iterate the profiles for
 * @param state pointer to data needed by the callback method
 * @param callback method to be called for each matching profile
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h
 * @return the number matching profiles which have been iterated
 */
EXTERNAL uint32_t fiftyoneDegreesProfileIterateProfilesForPropertyWithTypeAndValueAndOffsetExtractor(
	fiftyoneDegreesCollection *strings,
	fiftyoneDegreesCollection *properties,
	fiftyoneDegreesCollection *propertyTypes,
	fiftyoneDegreesCollection *values,
	fiftyoneDegreesCollection *profiles,
	fiftyoneDegreesCollection *profileOffsets,
	fiftyoneDegreesProfileOffsetValueExtractor offsetValueExtractor,
	const char *propertyName,
	const char* valueName,
	void *state,
	fiftyoneDegreesProfileIterateMethod callback,
	fiftyoneDegreesException *exception);

/**
 * Iterate all profiles which contain the specified value, calling the callback
 * method for each.
 * @param strings collection containing the strings referenced properties and
 * values
 * @param properties collection containing all properties
 * @param values collection containing all values
 * @param profiles collection containing the profiles referenced by the profile
 * offsets
 * @param profileOffsets collection containing all profile offsets
 * @param propertyName name of the property the value relates to
 * @param valueName name of the value to iterate the profiles for
 * @param state pointer to data needed by the callback method
 * @param callback method to be called for each matching profile
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h
 * @return the number matching profiles which have been iterated
 */
EXTERNAL uint32_t fiftyoneDegreesProfileIterateProfilesForPropertyAndValue(
	fiftyoneDegreesCollection *strings,
	fiftyoneDegreesCollection *properties,
	fiftyoneDegreesCollection *values,
	fiftyoneDegreesCollection *profiles,
	fiftyoneDegreesCollection *profileOffsets,
	const char *propertyName,
	const char* valueName,
	void *state,
	fiftyoneDegreesProfileIterateMethod callback,
	fiftyoneDegreesException *exception);

/**
 * Gets the offset in the profiles collection for the profile with the
 * profileId or NULL if there is no corresponding profile.
 * @param profileOffsets collection containing the profile offsets (with ID)
 * @param profileId the unique id of the profile to fetch
 * @param profileOffset pointer to the integer to set the offset in
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h
 * @return pointer to the profile offset or NULL
 */
EXTERNAL uint32_t* fiftyoneDegreesProfileGetOffsetForProfileId(
	fiftyoneDegreesCollection *profileOffsets,
	uint32_t profileId,
	uint32_t *profileOffset,
	fiftyoneDegreesException *exception);

/**
 * Gets the profile from the profiles collection
 * with the profileId or NULL if there is no corresponding profile.
 * @param profileOffsets collection containing the profile offsets (without ID)
 * @param profiles collection containing the profiles referenced by the profile
 * offsets
 * @param profileId the unique id of the profile to fetch
 * @param outProfileItem pointer to the item to store profile reference in
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h
 * @return pointer to the profile or NULL
 */
EXTERNAL fiftyoneDegreesProfile * fiftyoneDegreesProfileGetByProfileIdIndirect(
	fiftyoneDegreesCollection *profileOffsets,
	fiftyoneDegreesCollection *profiles,
	uint32_t profileId,
	fiftyoneDegreesCollectionItem *outProfileItem,
	fiftyoneDegreesException *exception);

/**
 * Calls the callback for every value index available for the profile.
 * @param profile to return value indexes for
 * @param available required properties
 * @param values collection containing all values
 * @param state pointer to data needed by the callback method
 * @param callback method to be called for each value index
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h
 * @return number of times the callback was called.
 */
EXTERNAL uint32_t fiftyoneDegreesProfileIterateValueIndexes(
	fiftyoneDegreesProfile* profile,
	fiftyoneDegreesPropertiesAvailable* available,
	fiftyoneDegreesCollection* values,
	void* state,
	fiftyoneDegreesProfileIterateValueIndexesMethod callback,
	fiftyoneDegreesException* exception);

/**
 * @}
 */

#endif

/** Value structure containing meta data relating to the value. */
#pragma pack(push, 2)
typedef struct fiftyoneDegrees_value_t {
	const int16_t propertyIndex; /**< Index of the property the value relates to */
	const int32_t nameOffset; /**< The offset in the strings structure to the 
	                              value name */
	const int32_t descriptionOffset; /**< The offset in the strings structure to
	                                     the value description */
	const int32_t urlOffset; /**< The offset in the strings structure to the 
	                             value URL */
} fiftyoneDegreesValue;
#pragma pack(pop)

/**
 * Returns the contents of the value using the item provided. The
 * collection item must be released when the caller is finished with the
 * string.
 * @param strings collection of strings retrieved by offsets.
 * @param value structure for the name required.
 * @param storedValueType format of byte array representation.
 * @param item used to store the resulting string in.
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return a pointer to a contents in the collection item data structure.
 */
EXTERNAL fiftyoneDegreesStoredBinaryValue* fiftyoneDegreesValueGetContent(
	fiftyoneDegreesCollection *strings,
	fiftyoneDegreesValue *value,
	fiftyoneDegreesPropertyValueType storedValueType,
	fiftyoneDegreesCollectionItem *item,
	fiftyoneDegreesException *exception);

/**
 * Returns the string name of the value using the item provided. The
 * collection item must be released when the caller is finished with the
 * string.
 * @param strings collection of strings retrieved by offsets.
 * @param value structure for the name required.
 * @param item used to store the resulting string in.
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return a pointer to a string in the collection item data structure.
 */
EXTERNAL fiftyoneDegreesString* fiftyoneDegreesValueGetName(
	fiftyoneDegreesCollection *strings,
	fiftyoneDegreesValue *value,
	fiftyoneDegreesCollectionItem *item,
	fiftyoneDegreesException *exception);

/**
 * Returns the string description of the value using the item provided. The
 * collection item must be released when the caller is finished with the
 * string.
 * @param strings collection of strings retrieved by offsets.
 * @param value structure for the description required.
 * @param item used to store the resulting string in.
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return a pointer to a string in the collection item data structure.
 */
EXTERNAL fiftyoneDegreesString* fiftyoneDegreesValueGetDescription(
	fiftyoneDegreesCollection *strings,
	fiftyoneDegreesValue *value,
	fiftyoneDegreesCollectionItem *item,
	fiftyoneDegreesException *exception);

/**
 * Returns the string URL of the value using the item provided. The
 * collection item must be released when the caller is finished with the
 * string.
 * @param strings collection of strings retrieved by offsets.
 * @param value structure for the URL required.
 * @param item used to store the resulting string in.
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return a pointer to a string in the collection item data structure.
 */
EXTERNAL fiftyoneDegreesString* fiftyoneDegreesValueGetUrl(
	fiftyoneDegreesCollection *strings,
	fiftyoneDegreesValue *value,
	fiftyoneDegreesCollectionItem *item,
	fiftyoneDegreesException *exception);

/**
 * Gets the value for the requested index from the collection provided.
 * @param values collection to get the value from
 * @param valueIndex index of the value to get
 * @param item to store the value in
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return pointer to the value or NULL
 */
EXTERNAL fiftyoneDegreesValue* fiftyoneDegreesValueGet(
	fiftyoneDegreesCollection *values,
	uint32_t valueIndex,
	fiftyoneDegreesCollectionItem *item,
	fiftyoneDegreesException *exception);

/**
 * Get the value for the requested name from the collection provided.
 * @param values collection to get the value from
 * @param strings collection containing the value names
 * @param property that the value relates to
 * @param storedValueType format of byte array representation.
 * @param valueName name of the value to get
 * @param item to store the value in
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h
 * @return pointer to the value or NULL if it does not exist
 */
EXTERNAL fiftyoneDegreesValue* fiftyoneDegreesValueGetByNameAndType(
	fiftyoneDegreesCollection *values,
	fiftyoneDegreesCollection *strings,
	fiftyoneDegreesProperty *property,
	fiftyoneDegreesPropertyValueType storedValueType,
	const char *valueName,
	fiftyoneDegreesCollectionItem *item,
	fiftyoneDegreesException *exception);

/**
 * Get the value for the requested name from the collection provided.
 * @param values collection to get the value from
 * @param strings collection containing the value names
 * @param property that the value relates to
 * @param valueName name of the value to get
 * @param item to store the value in
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h
 * @return pointer to the value or NULL if it does not exist
 */
EXTERNAL fiftyoneDegreesValue* fiftyoneDegreesValueGetByName(
	fiftyoneDegreesCollection *values,
	fiftyoneDegreesCollection *strings,
	fiftyoneDegreesProperty *property,
	const char *valueName,
	fiftyoneDegreesCollectionItem *item,
	fiftyoneDegreesException *exception);

/**
 * Get index of the value for the requested name from the collection provided.
 * @param values collection to get the value from
 * @param strings collection containing the value names
 * @param property that the value relates to
 * @param storedValueType format of byte array representation
 * @param valueName name of the value to get
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h
 * @return the 0 based index of the item if found, otherwise -1
 */
EXTERNAL long fiftyoneDegreesValueGetIndexByNameAndType(
	fiftyoneDegreesCollection *values,
	fiftyoneDegreesCollection *strings,
	fiftyoneDegreesProperty *property,
	fiftyoneDegreesPropertyValueType storedValueType,
	const char *valueName,
	fiftyoneDegreesException *exception);

/**
 * Get index of the value for the requested name from the collection provided.
 * @param values collection to get the value from
 * @param strings collection containing the value names
 * @param property that the value relates to
 * @param valueName name of the value to get
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h
 * @return the 0 based index of the item if found, otherwise -1
 */
EXTERNAL long fiftyoneDegreesValueGetIndexByName(
	fiftyoneDegreesCollection *values,
	fiftyoneDegreesCollection *strings,
	fiftyoneDegreesProperty *property,
	const char *valueName,
	fiftyoneDegreesException *exception);

/**
 * @}
 */

#endif
/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2023 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

#ifndef FIFTYONE_DEGREES_OVERRIDES_INCLUDED
#define FIFTYONE_DEGREES_OVERRIDES_INCLUDED

/**
 * @ingroup FiftyOneDegreesCommon
 * @defgroup FiftyOneDegreesOverrides Overrides
 *
 * Used to override properties values or an entire profile.
 *
 * ## Introduction
 *
 * Overrides are used to override property values, or an entire profile in a
 * set of results. For example, if the screen size is not known from the HTTP
 * headers alone, it can be fetched using JavaScript and overridden.
 *
 * ## Creation
 *
 * An array of overridable properties is created using the
 * #fiftyoneDegreesOverridePropertiesCreate method. This returns all the
 * properties which are capable of being overridden.
 *
 * An array of override value ready to be populated is created using the
 * #fiftyoneDegreesOverrideValuesCreate method. This is then ready to be added
 * to and used to override the values in a results structure.
 *
 * ## Extraction
 *
 * Override values are extracted from an evidence structure using the
 * #fiftyoneDegreesOverridesExtractFromEvidence method. This looks through the
 * items of evidence for any items which are overrides, then parses and adds
 * them to the override values ready to be applied.
 *
 * ## Add
 *
 * Override values can also be added using the #fiftyoneDegreesOverridesAdd or
 * #fiftyoneDegreesOverrideValuesAdd methods which add a single or multiple 
 * values respectively to the override values.
 *
 * ## Free
 *
 * Property and value overrides are freed using the
 * #fiftyoneDegreesOverridePropertiesFree and
 * #fiftyoneDegreesOverrideValuesFree methods.
 *
 * @{
 */

#include <stdint.h>
#include <stdbool.h>

/**
 * Index and pointer to a property which can be overridden.
 */
typedef struct fiftyone_degrees_override_property_t {
	uint32_t requiredPropertyIndex; /**< Index in the available properties
									structure */
	fiftyoneDegreesPropertyAvailable *available; /**< Pointer to the property */
} fiftyoneDegreesOverrideProperty;

/**
 * String value which should override the value for the property indicated by
 * the required property index.
 */
typedef struct fiftyone_degrees_override_value_t {
	uint32_t requiredPropertyIndex; /**< Index in the available properties
									structure */
	fiftyoneDegreesData string; /**< Overridden value */
} fiftyoneDegreesOverrideValue;

FIFTYONE_DEGREES_ARRAY_TYPE(
	fiftyoneDegreesOverrideProperty,
	bool prefix; /**< Flag which when true requires the `51D_` prefix to be
				 checked for in evidence. */
);

/**
 * An array of properties and values to use when getting override values.
 */
FIFTYONE_DEGREES_ARRAY_TYPE(fiftyoneDegreesOverrideValue,);

/**
 * Array of overridable properties. These are properties in a data set which
 * a capable of being overridden.
 */
typedef fiftyoneDegreesOverridePropertyArray fiftyoneDegreesOverridable;

/**
 * Called when a profile Id has been found and should override the one
 * found from another source such as the `User-Agent`.
 * @param state pointer to be used by the method
 * @param profileId if to override
 */
typedef void(*fiftyoneDegreesOverrideProfileIdMethod)(
	void *state, 
	uint32_t profileId);

/**
 * Determines if the required property index is eligible for overriding 
 * considering the configuration of the data set.
 * @param state pointer to be used by the method
 * @param requiredPropertyIndex index of the property in the available
 * properties structure
 * @return true if the property can be overridden, otherwise false.
 */
typedef bool(*fiftyoneDegreesOverridesFilterMethod)(
	void *state,
	uint32_t requiredPropertyIndex);

/**
 * Creates a fresh array of override values with the given capacity.
 * @param capacity the number of values the array can contain
 * @return a new array of override values
 */
EXTERNAL fiftyoneDegreesOverrideValueArray* fiftyoneDegreesOverrideValuesCreate(
	uint32_t capacity);

/**
 * Returns a list of the evidence keys that are available to support 
 * overriding property values.
 * @param available pointer to the available properties structure
 * @param prefix true if the `51D_` prefix should be checked for in evidence
 * @param state pointer to be used by the method
 * @param filter pointer to a filter method which determines whether or not a
 * property is eligible to be overridden
 * @return a new override properties array
 */
fiftyoneDegreesOverridePropertyArray* 
fiftyoneDegreesOverridePropertiesCreate(
	fiftyoneDegreesPropertiesAvailable *available,
	bool prefix,
	void *state,
	fiftyoneDegreesOverridesFilterMethod filter);

/**
 * Frees the resources used by the override properties.
 * @param properties pointer to the properties to free
 */
void fiftyoneDegreesOverridePropertiesFree(
	fiftyoneDegreesOverridePropertyArray *properties);

/**
 * Extracts override values from evidence.
 * @param properties which can be overridden
 * @param values array to populate with the override values
 * @param evidence to extract any overrides from
 * @return the number of override values which have been extracted
 */
 uint32_t fiftyoneDegreesOverridesExtractFromEvidence(
	fiftyoneDegreesOverridePropertyArray *properties,
	fiftyoneDegreesOverrideValueArray *values,
	fiftyoneDegreesEvidenceKeyValuePairArray *evidence);

/**
 * Gets whether or not the override values contain an override relating to the
 * property identified by the required property index. Note that the required
 * property index MUST be valid when calling this method, so should be checked
 * by the caller.
 * @param values pointer to the values to search in
 * @param requiredPropertyIndex index in the required properties of the 
 * property to check for values of
 * @return true if there are override values for the requested property
 */
 bool fiftyoneDegreesOverrideHasValueForRequiredPropertyIndex(
	 fiftyoneDegreesOverrideValueArray *values,
	 uint32_t requiredPropertyIndex);

/**
 * Adds values from the overrides data structure into the results.
 * @param values array to add the new values to
 * @param requiredPropertyIndex of the property which the values relate to
 * @param list to add the values to
 * @return the number of values which have been added to the list
 */
uint32_t fiftyoneDegreesOverrideValuesAdd(
	fiftyoneDegreesOverrideValueArray *values,
	uint32_t requiredPropertyIndex,
	fiftyoneDegreesList *list);

/**
 * Add an value override to the override values array.
 * @param values the override values array to add the value to
 * @param requiredPropertyIndex the index in the dataset's required properties
 * of the property to override the value of
 * @param value the value string override
 * @return true if the value was added successfully
 */
EXTERNAL bool fiftyoneDegreesOverridesAdd(
	fiftyoneDegreesOverrideValueArray *values,
	int requiredPropertyIndex,
	const char *value);
	
/**
 * Returns the first value for the required property index or NULL of no value
 * exists for the property index.
 * @param values to get the value from
 * @param requiredPropertyIndex index of the property to get the first value of
 * @param item to store the result in
 * @return pointer to the value or NULL if none were found
 */
fiftyoneDegreesString* fiftyoneDegreesOverrideValuesGetFirst(
	fiftyoneDegreesOverrideValueArray *values,
	uint32_t requiredPropertyIndex,
	fiftyoneDegreesCollectionItem *item);

/**
 * Gets the required property index of a property that **MIGHT** provide logic
 * such as JavaScript or Regular Expressions that could override the value
 * of the required property index provided.
 * @param available list of require properties
 * @param requiredPropertyIndex of the property to test for being overridden
 * @return the positive index of the overriding required property, or -1 it 
 * can't be overridden.
 */
int fiftyoneDegreesOverridesGetOverridingRequiredPropertyIndex(
	fiftyoneDegreesPropertiesAvailable *available,
	uint32_t requiredPropertyIndex);

/**
 * Frees the memory used for the override values.
 * @param values to be freed
 */
EXTERNAL void fiftyoneDegreesOverrideValuesFree(
	fiftyoneDegreesOverrideValueArray *values);

/**
 * Reset override array. All existing item memory will not be freed by reset
 * with 0s. Remaining values will be reset to default except the allocateds size..
 * @param values to be reset
 */
EXTERNAL void fiftyoneDegreesOverrideValuesReset(
	fiftyoneDegreesOverrideValueArray *values);

/**
 * Extracts the profile overrides from the evidence and overrides them using
 * the override method supplied.
 * @param evidence to extract the profile ids from
 * @param state pointer to pass to the override method
 * @param callback method called to override a profile id
 */
EXTERNAL void fiftyoneDegreesOverrideProfileIds(
	fiftyoneDegreesEvidenceKeyValuePairArray *evidence, 
	void *state, 
	fiftyoneDegreesOverrideProfileIdMethod callback);

/**
 * @}
 */

#endif
/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2023 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

#ifndef FIFTYONE_DEGREES_CONFIG_H_INCLUDED
#define FIFTYONE_DEGREES_CONFIG_H_INCLUDED

/**
 * @ingroup FiftyOneDegreesCommon
 * @defgroup FiftyOneDegreesConfig Config
 *
 * Configuration for building data sets.
 *
 * ## Introduction
 *
 * Configuration structures based off the base configuration type are used when
 * building data sets. The base configuration describes how the data is handled.
 * For example, whether or not a temporary file should be created, or whether
 * the memory should be freed with the data set.
 *
 * Extending configurations will add options specific to certain categories of
 * data sets.
 *
 * @{
 */

/**
 * Base configuration structure containing common configuration options, and
 * options that apply to structures and methods in the common library.
 */
typedef struct fiftyone_degrees_config_base_t {
	bool allInMemory; /**< True if the data file should be loaded entirely into
	                      continuous memory. */
	bool usesUpperPrefixedHeaders; /**< True if the HTTP header field names
	                                   MIGHT include the prefix HTTP_ */
	bool freeData; /**< True if the memory containing the data set should be
	                   freed after it is no longer needed. This only applies to
	                   externally allocated memory, anything allocated
	                   internally is automatically freed. */
	bool useTempFile; /**< Indicates whether a temporary file should be created
	                      instead of using the original file. */
	bool reuseTempFile; /**< Indicates that an existing temp file may be used.
	                        This should be selected if multiple instances wish
	                        to use the same file to prevent high disk usage. */
	const char **tempDirs; /**< Array of temp directories which can be used in
	                           order of preference. */
	int tempDirCount; /**< Number of directories in the tempDirs array. */
	bool propertyValueIndex; /**< Indicates if an index to values for property 
							     and profiles should be created. */
} fiftyoneDegreesConfigBase;

/** Default value for the #FIFTYONE_DEGREES_CONFIG_USE_TEMP_FILE macro. */
#define FIFTYONE_DEGREES_CONFIG_USE_TEMP_FILE_DEFAULT false

/**
 * Temp file setting used in the default configuration macro
 * #FIFTYONE_DEGREES_CONFIG_DEFAULT.
 */
#define FIFTYONE_DEGREES_CONFIG_USE_TEMP_FILE \
FIFTYONE_DEGREES_CONFIG_USE_TEMP_FILE_DEFAULT

/** Default value for the #FIFTYONE_DEGREES_CONFIG_ALL_IN_MEMORY macro. */
#ifndef FIFTYONE_DEGREES_MEMORY_ONLY
#define FIFTYONE_DEGREES_CONFIG_ALL_IN_MEMORY_DEFAULT false
#else
#define FIFTYONE_DEGREES_CONFIG_ALL_IN_MEMORY_DEFAULT true
#endif

/**
 * All in memory setting used in the default configuration macro
 * #FIFTYONE_DEGREES_CONFIG_DEFAULT.
 */
#define FIFTYONE_DEGREES_CONFIG_ALL_IN_MEMORY \
FIFTYONE_DEGREES_CONFIG_ALL_IN_MEMORY_DEFAULT

/**
 * Default value for the #fiftyoneDegreesConfigBase structure with index.
 */
#define FIFTYONE_DEGREES_CONFIG_DEFAULT_WITH_INDEX \
	FIFTYONE_DEGREES_CONFIG_ALL_IN_MEMORY, /* allInMemory */ \
	true, /* usesUpperPrefixedHeaders */ \
	false, /* freeData */ \
	FIFTYONE_DEGREES_CONFIG_USE_TEMP_FILE, /* useTempFile */ \
	false, /* reuseTempFile */ \
	NULL, /* tempDirs */ \
	0, /* tempDirCount */ \
	true /* propertyValueIndex */

 /**
  * Default value for the #fiftyoneDegreesConfigBase structure without index.
  */
#define FIFTYONE_DEGREES_CONFIG_DEFAULT_NO_INDEX \
	FIFTYONE_DEGREES_CONFIG_ALL_IN_MEMORY, /* allInMemory */ \
	true, /* usesUpperPrefixedHeaders */ \
	false, /* freeData */ \
	FIFTYONE_DEGREES_CONFIG_USE_TEMP_FILE, /* useTempFile */ \
	false, /* reuseTempFile */ \
	NULL, /* tempDirs */ \
	0, /* tempDirCount */ \
	false /* propertyValueIndex */

/**
 * @}
 */
#endif
/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2023 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

#ifndef FIFTYONE_DEGREES_DATASET_H_INCLUDED
#define FIFTYONE_DEGREES_DATASET_H_INCLUDED

/**
 * @ingroup FiftyOneDegreesCommon
 * @defgroup FiftyOneDegreesDataSet Data Set
 *
 * A data file initialised in a structure.
 *
 * ## Terms
 *
 * **Get** : returns an immutable data set that must be released when the
 * caller is finished with it.

 * **Release** : releases a reference on the data set returned from the Get
 * operation.

 * **Reload** : reloads an existing data set while maintaining any current
 * references to the existing data set.
 *
 * ## Introduction
 *
 * A DataSet is a data file initialised in a structure that can be used to
 * process data. Collections from the file may be stored in memory or streamed
 * from the file when needed.
 *
 * A DataSet is used to process data, in most cases this is in the form of
 * evidence. Values for the Properties which the data set is capable of
 * returning can then be retrieved from the result of processing.
 *
 * ## Creation
 *
 * A DataSet is created by allocating the structure and initialising from one
 * of the following:
 *
 * **File** : a data file is either read into memory or handle maintained for
 * streaming by the data set.
 *
 * **Memory** : a data file read into continuous memory is used by the data set.
 *
 * ## Operation
 *
 * A DataSet is a resource to be maintained by a Resource Manager. So any
 * thread wanting to use it must get a reference from the manager
 * (see resource.h).
 *
 * The data set implementation extending will contain methods to process data.
 * Usually these will return a Results instance (or an extending structure),
 * see results.h for more details.
 *
 * ## Reloading
 *
 * A DataSet can be reloaded without interrupting operation by using the 
 * defined Reload methods. These take either a new data file or a new memory
 * pointer, initialise a new data set, and replace the existing one in a
 * thread-safe manor.
 *
 * ## Free
 *
 * A DataSet is a managed resource, so it should not be freed directly. Instead
 * the manager should be freed, so that the data set is safely freed without
 * impacting other threads.
 *
 * @{
 */


/**
 * Base data set structure which contains the 'must have's for all data sets.
 */
typedef struct fiftyone_degrees_dataset_base_t {
	const char fileName[FIFTYONE_DEGREES_FILE_MAX_PATH]; /**< Path to the file
	                                                     used to initialise the
	                                                     data set. This will
	                                                     either be the same as
	                                                     the master file name,
	                                                     or the path to the
	                                                     temp file being used. */
	const char masterFileName[FIFTYONE_DEGREES_FILE_MAX_PATH]; /**< Path to the
	                                                           file used to
	                                                           initialise the
	                                                           data set. */
	void *memoryToFree; /**< A pointer to the memory where the data within the
						data set is held. NULL if the entire data set is not
						held in memory, the caller is going to free the
						memory or there are a mixture of caches and
						partially allocated memory in use. */
	bool isInMemory; /**< True if the data file has been read into continuous
						 memory */
	fiftyoneDegreesFilePool filePool; /**< Linked list of file readers */
	fiftyoneDegreesResourceHandle *handle; /**< Pointer to the handle that
										   tracks this data set instance */
	fiftyoneDegreesPropertiesAvailable *available; /**< Available properties */
	fiftyoneDegreesHeaders *uniqueHeaders; /**< Related HTTP headers */
	fiftyoneDegreesOverridePropertyArray *overridable; /**< Array of properties
													   that can be 
													   overridden */
	fiftyoneDegreesIndicesPropertyProfile* indexPropertyProfile; /**< Index to 
															   look up profile 
															   values by 
															   property */
    const void *config; /**< Pointer to the config used to create the dataset */
} fiftyoneDegreesDataSetBase;

/**
 * Initialses the data set from data stored in continuous memory.
 * @param dataSet pointer to the data set to be initialised
 * @param config configuration for the operation of the data set, or NULL if 
 * default configuration is required
 * @param properties the properties that will be consumed from the data set, or 
 * NULL if all available properties in the hash data file should be available
 * for consumption
 * @param memory pointer to continuous memory containing the data set
 * @param size the number of bytes that make up the data set
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return the status associated with the data set intialisation. Any value
 * other than #FIFTYONE_DEGREES_STATUS_SUCCESS means the data set was not
 * initialised correctly
 */
typedef fiftyoneDegreesStatusCode(*fiftyoneDegreesDataSetInitFromMemoryMethod)(
	void *dataSet,
	const void *config,
	fiftyoneDegreesPropertiesRequired *properties,
	void *memory,
	fiftyoneDegreesFileOffset size,
	fiftyoneDegreesException *exception);

/**
 * Initialses the data set from data stored on file. This method
 * should clean up the resource properly if the initialisation process fails.
 * That means all allocated memory should be freed and pointers to these
 * memorys should be set to NULL. The input dataSet should also be freed.
 * @param dataSet pointer to the data set to be initialised
 * @param config configuration for the operation of the data set, or NULL if
 * default configuration is required
 * @param properties the properties that will be consumed from the data set, or
 * NULL if all available properties in the hash data file should be available
 * for consumption
 * @param fileName the full path to a file with read permission that contains 
 * the data set
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h
 * @return the status associated with the data set intialisation. Any value
 * other than #FIFTYONE_DEGREES_STATUS_SUCCESS means the data set was not
 * initialised correctly
 */
typedef fiftyoneDegreesStatusCode(*fiftyoneDegreesDataSetInitFromFileMethod)(
	void *dataSet,
	const void *config,
	fiftyoneDegreesPropertiesRequired *properties,
	const char *fileName,
	fiftyoneDegreesException *exception);

/**
 * Initialises the properties in the data set. Usually this means constructing
 * an array of pointers to the properties which are required for quick access.
 * @param dataSet pointer to a valid data set
 * @param properties the properties which should be initialised in the data set
 * @param state pointer to data which is needed by getPropertymethod
 * @param getPropertyMethod method used to retrieve the name of a property at
 * a specified index from the data set
 * @param getEvidencePropertiesMethod method used to populate the list of
 * evidence required for a property in the data set
 * @return the status associated with the property initialisation. Any value
 * other than #FIFTYONE_DEGREES_STATUS_SUCCESS  means the properties were not
 * initialised correctly
 */
fiftyoneDegreesStatusCode fiftyoneDegreesDataSetInitProperties(
	fiftyoneDegreesDataSetBase *dataSet,
	fiftyoneDegreesPropertiesRequired *properties,
	void *state,
	fiftyoneDegreesPropertiesGetMethod getPropertyMethod,
    fiftyoneDegreesEvidencePropertiesGetMethod getEvidencePropertiesMethod);

/**
 * Initialises the HTTP headers in the data set. Usually this means
 * constructing an array of pointers to the headers which are required for
 * quick access.
 * @param dataSet pointer to a valid data set
 * @param state pointer to data which is needed by getPropertymethod
 * @param getHeaderMethod method used to retrieve the unique id and name of a
 * header at a specified index from the data set
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return the status associated with the header initialisation. Any value
 * other than #FIFTYONE_DEGREES_STATUS_SUCCESS  means the headers were not
 * initialised correctly
 */
fiftyoneDegreesStatusCode fiftyoneDegreesDataSetInitHeaders(
	fiftyoneDegreesDataSetBase *dataSet,
	void *state,
	fiftyoneDegreesHeadersGetMethod getHeaderMethod,
	fiftyoneDegreesException* exception);

/**
 * Initialses the data set from data stored on file.
 * @param dataSet pointer to the pre allocated data set to be initialised
 * @param fileName the full path to a file with read permission that contains
 * the data set
 * @param bytesToCompare the number of bytes to compare if the reuse temporary
 * file option is enabled. If a temporary file is found and the first bytes are
 * equal to the master file, then the file is used, if not then a new temporary
 * file is created
 * @return the status associated with the data set intialisation. Any value
 * other than #FIFTYONE_DEGREES_STATUS_SUCCESS means the data set was not
 * initialised correctly
 */
fiftyoneDegreesStatusCode fiftyoneDegreesDataSetInitFromFile(
	fiftyoneDegreesDataSetBase *dataSet,
	const char *fileName,
	fiftyoneDegreesFileOffset bytesToCompare);

/**
 * Initialses the data set from data stored in continuous memory.
 * @param dataSet pointer to the pre allocated data set to be initialised
 * @param reader constructed to read the memory containing the data set
 * @return the status associated with the data set intialisation. Any value
 * other than #FIFTYONE_DEGREES_STATUS_SUCCESS means the data set was not
 * initialised correctly
 */
fiftyoneDegreesStatusCode fiftyoneDegreesDataSetInitInMemory(
	fiftyoneDegreesDataSetBase *dataSet,
	fiftyoneDegreesMemoryReader *reader);

/**
 * Resets a newly allocated data set structure ready for initialisation.
 * @param dataSet pointer to the allocated data set
 */
void fiftyoneDegreesDataSetReset(fiftyoneDegreesDataSetBase *dataSet);

/**
 * Gets a pointer to the active data set from a resource manager.
 * Note that when this is finished with it must be released with the
 * corresponding release method.
 * @param manager pointer to the manager which manages the data set resource
 * @return pointer to the data set resource
 */
EXTERNAL fiftyoneDegreesDataSetBase* fiftyoneDegreesDataSetGet(
	fiftyoneDegreesResourceManager *manager);

/** 
 * Releases a reference to a data set which has been fetched via the DataSetGet
 * method.
 * @param dataSet pointer to the data set to release
 */
EXTERNAL void fiftyoneDegreesDataSetRelease(fiftyoneDegreesDataSetBase *dataSet);

/**
 * Closes the data set by freeing anything which has been initialised at
 * creation. This does not free the data set structure itself.
 * @param dataSet pointer to the data set to complete
 */
void fiftyoneDegreesDataSetFree(fiftyoneDegreesDataSetBase *dataSet);

/**
 * Reload the data set being used by the resource manager using a data file
 * loaded into contiguous memory. When initialising the data, the configuration
 * that manager was first created with is used.
 *
 * If the data passed in is successfully initialised, the current data set is
 * replaced The old data will remain in memory until the last reference to it
 * is released.
 * @param manager pointer to the resource manager to reload the data set for
 * @param source pointer to the memory location where the new data file is
 * stored
 * @param length of the data in memory
 * @param dataSetSize size of the data set structure to allocate for the new
 * data set
 * @param initDataSet init method used to initialise the new data set from the
 * memory pointer provided
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return the status associated with the data set reload. Any value other than
 * #FIFTYONE_DEGREES_STATUS_SUCCESS means the data set was not reloaded
 * correctly
 */
fiftyoneDegreesStatusCode fiftyoneDegreesDataSetReloadManagerFromMemory(
	fiftyoneDegreesResourceManager *manager,
	void *source,
	fiftyoneDegreesFileOffset length,
	size_t dataSetSize,
	fiftyoneDegreesDataSetInitFromMemoryMethod initDataSet,
	fiftyoneDegreesException *exception);

/**
 * Reload the data set being used by the resource manager using the data file
 * location specified. When initialising the data, the configuration that
 * manager was first created with is used.
 *
 * If the new data file is successfully initialised, the current data set is
 * replaced The old data will remain in memory until the last reference to it
 * is released.
 * @param manager pointer to the resource manager to reload the data set for
 * @param fileName path to the new data file
 * @param dataSetSize size of the data set structure to allocate for the new
 * data set
 * @param initDataSet init method used to initialise the new data set from the
 * file provided
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return the status associated with the data set reload. Any value other than
 * #FIFTYONE_DEGREES_STATUS_SUCCESS means the data set was not reloaded
 * correctly
 */
fiftyoneDegreesStatusCode fiftyoneDegreesDataSetReloadManagerFromFile(
	fiftyoneDegreesResourceManager* manager,
	const char *fileName,
	size_t dataSetSize,
	fiftyoneDegreesDataSetInitFromFileMethod initDataSet,
	fiftyoneDegreesException *exception);

/**
 * Reload functions are common across all data set implementations where
 * the naming of the data set type and the init methods comform to the common
 * pattern. This macro requires the init methods to be static and of the
 * form initDataFrom[Memory|File]. The data set name must be DataSet[Type].
 * @param t the name of the resource type to define reload methods for
 */
#define FIFTYONE_DEGREES_DATASET_RELOAD(t) \
/** \
 * Reload the data set being used by the resource manager using a data file \
 * loaded into contiguous memory. When initialising the data, the configuration \
 * that manager was first created with is used. \
 * \
 * If the data passed in is successfully initialised, the current data set is \
 * replaced The old data will remain in memory until the last reference to it \
 * is released. \
 * @param manager pointer to the resource manager to reload the data set for \
 * @param source pointer to the memory location where the new data file is \
 * stored \
 * @param length of the data in memory \
 * @param exception pointer to an exception data structure to be used if an \
 * exception occurs. See exceptions.h \
 * @return the status associated with the data set reload. Any value other than \
 * #FIFTYONE_DEGREES_STATUS_SUCCESS means the data set was not reloaded \
 * correctly \
 */ \
fiftyoneDegreesStatusCode fiftyoneDegrees##t##ReloadManagerFromMemory( \
fiftyoneDegreesResourceManager *manager, \
void *source, \
fiftyoneDegreesFileOffset length, \
fiftyoneDegreesException *exception) { \
	return fiftyoneDegreesDataSetReloadManagerFromMemory( \
		manager, \
		source, \
		length, \
		sizeof(DataSet##t), \
		initDataSetFromMemory, \
		exception); \
} \
/** \
 * Reload the data set being used by the resource manager using the data file \
 * location specified. When initialising the data, the configuration that \
 * manager was first created with is used. \
 * \
 * If the new data file is successfully initialised, the current data set is \
 * replaced The old data will remain in memory until the last reference to it \
 * is released. \
 * @param manager pointer to the resource manager to reload the data set for \
 * @param fileName path to the new data file \
 * @param exception pointer to an exception data structure to be used if an \
 * exception occurs. See exceptions.h \
 * @return the status associated with the data set reload. Any value other than \
 * #FIFTYONE_DEGREES_STATUS_SUCCESS means the data set was not reloaded \
 * correctly \
 */ \
fiftyoneDegreesStatusCode fiftyoneDegrees##t##ReloadManagerFromFile( \
fiftyoneDegreesResourceManager* manager, \
const char *fileName, \
fiftyoneDegreesException *exception) { \
	return fiftyoneDegreesDataSetReloadManagerFromFile( \
		manager, \
		fileName, \
		sizeof(DataSet##t), \
		initDataSetFromFile, \
		exception); \
} \
/** \
 * Reload the data set being used by the resource manager using the data file \
 * which the data set was initialised with. When initialising the data, the
 * configuration that manager was first created with is used. \
 * \
 * If the new data file is successfully initialised, the current data set is \
 * replaced The old data will remain in memory until the last reference to it \
 * is released. \
 * @param manager pointer to the resource manager to reload the data set for \
 * @param exception pointer to an exception data structure to be used if an \
 * exception occurs. See exceptions.h \
 * @return the status associated with the data set reload. Any value other than \
 * #FIFTYONE_DEGREES_STATUS_SUCCESS means the data set was not reloaded \
 * correctly \
  */ \
fiftyoneDegreesStatusCode fiftyoneDegrees##t##ReloadManagerFromOriginalFile( \
fiftyoneDegreesResourceManager* manager, \
fiftyoneDegreesException *exception) { \
	fiftyoneDegreesStatusCode status = FIFTYONE_DEGREES_STATUS_NOT_SET; \
	DataSet##t* dataSet = fiftyoneDegreesDataSet##t##Get(manager); \
	status = fiftyoneDegrees##t##ReloadManagerFromFile( \
		manager, \
		dataSet->b.b.masterFileName, \
		exception); \
	fiftyoneDegreesDataSet##t##Release(dataSet); \
	return status; \
}

/**
 * @}
 */

#endif
/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2023 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

#ifndef FIFTYONE_DEGREES_RESULTS_INCLUDED
#define FIFTYONE_DEGREES_RESULTS_INCLUDED

/**
 * @ingroup FiftyOneDegreesCommon
 * @defgroup FiftyOneDegreesResults Results
 *
 * Structure returned by an engine's process method(s), containing values.
 *
 * ## Introduction
 *
 * Results are the structure returned by an engine's process method(s) and
 * contains the values for the properties in the engine.
 * The base structure contains only the essential element of a data set, which
 * is needed to return values. Any engine can extend this structure to add any
 * additional elements which may be needed to format or return values.
 *
 * The data set pointer is a managed resource, meaning that while the results
 * exist, the data set will not be freed by the resource manager. This ensures
 * that values contained in the data set used for processing can always be
 * returned.
 *
 * @{
 */


/**
 * Enum containing reasons which cause a value to not be present or valid.
 */
typedef enum e_fiftyone_degrees_results_no_value_reason {
	FIFTYONE_DEGREES_RESULTS_NO_VALUE_REASON_DIFFERENCE, /**< The difference
														 value is higher than
														 the threshold, see
														 the Pattern API */
	FIFTYONE_DEGREES_RESULTS_NO_VALUE_REASON_NO_MATCHED_NODES, /**< No hash
															   nodes were
															   matched, see the
															   Hash API */
	FIFTYONE_DEGREES_RESULTS_NO_VALUE_REASON_INVALID_PROPERTY, /**< The requested
															   property does
															   not exist, or is
															   not a required
															   property */
	FIFTYONE_DEGREES_RESULTS_NO_VALUE_REASON_NO_RESULT_FOR_PROPERTY, /**< There
																	 is no result
																	 which
																	 contains a
																	 value for
																	 the requested
																	 property */
	FIFTYONE_DEGREES_RESULTS_NO_VALUE_REASON_NO_RESULTS, /**< There are no
														 results to get a value
														 from */
	FIFTYONE_DEGREES_RESULTS_NO_VALUE_REASON_TOO_MANY_VALUES, /**< There are too
															  many values to be
															  expressed as the
															  requested type */
	FIFTYONE_DEGREES_RESULTS_NO_VALUE_REASON_NULL_PROFILE, /**< The results
														   contain a null
														   profile for the
														   required component */
	FIFTYONE_DEGREES_RESULTS_NO_VALUE_REASON_UNKNOWN /**< None of the above */
} fiftyoneDegreesResultsNoValueReason;

/**
 * Base results structure which any processing results should extend.
 */
typedef struct fiftyone_degrees_results_base_t {
	void *dataSet; /**< Pointer to the data set associated with the results */
} fiftyoneDegreesResultsBase;

/**
 * Initialise a set of results by setting the data set they are associated with.
 * @param results pointer to the results to initialise
 * @param dataSet pointer to the data set which will be using the results
 * @return pointer to the initialised results
 */
EXTERNAL fiftyoneDegreesResultsBase* fiftyoneDegreesResultsInit(
	fiftyoneDegreesResultsBase *results,
	void *dataSet);

/**
 * @}
 */

#endif
/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2025 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is the subject of the following patent application, 
 * owned by 51 Degrees Mobile Experts Limited of
 * Regus Forbury Square, Davidson House, Reading RG1 3EU, United Kingdom:
 * United Kingdom Patent Application No. 2506025.2.
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

#ifndef FIFTYONE_DEGREES_IPI_GRAPH_INCLUDED
#define FIFTYONE_DEGREES_IPI_GRAPH_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <assert.h>
#ifdef _MSC_VER
#include <windows.h>
#endif

 /**
 * @ingroup FiftyOneDegreesIpIntelligence
 * @defgroup FiftyOneDegreesIpIntelligenceApi IpIntelligence
 *
 * All the functions specific to the IP Intelligence Graph.
 * @{
 * 
 * Evaluates an IP address and component id to determine the index associated 
 * with the profile or profile group from the related component.
 *
 * ## Overview
 *
 * fiftyoneDegreesIpiGraphCreateFrom[Memory|File] should be used to create an
 * array of component graph information records from a suitable data source.
 * 
 * This array is past to the fiftyoneDegreesIpiGraphEvaluate function along
 * with the IP address and the id of the component required. The following code
 * would be used to obtain the result for component id 1 and IP address 
 * 51.51.51.51.
 * 
 *	Exception exception;
 *	uint32_t result = 0;
 *	const char* ipAddress = "51.51.51.51";
 *	IpAddress parsedIpAddress;
 *	parsedIpAddress.type = 0;
 *	if (IpAddressParse(
 *		ipAddress,
 *		ipAddress + sizeof(ipAddress), 
 *		&parsedIpAddress)) {
 *		result = fiftyoneDegreesIpiGraphEvaluate(
 *			wrapper->array,
 *			(byte)1,
 *			parsedIpAddress,	
 *			&exception);
 *	}
 * 
 * The IP address is parsed from a string into a IpAddress instance using the
 * common-cxx IP functions.
 * 
 * The array created must be freed with the fiftyoneDegreesIpiGraphFree method
 * when finished with.
 * 
 * ## Note
 * 
 * The methods marked trace are for 51Degrees internal purposes and are not
 * intended for production usage.
 * 
 * Associated tests are not provided as open source. Contact 51Degrees if more
 * information is required.
 */

#if !defined(DEBUG) && !defined(_DEBUG) && !defined(NDEBUG)
#define NDEBUG
#endif

/**
 * DATA STRUCTURES
 */

/**
 * Data structure used to extract a value from the bytes that form a fixed
 * width graph node.
 */
#pragma pack(push, 1)
typedef struct fiftyone_degrees_ipi_cg_member_t {
	uint64_t mask; /**< Mask applied to a record to obtain the members bits */
	uint64_t shift; /**< Left shift to apply to the result of the mask to
				    obtain the value */
} fiftyoneDegreesIpiCgMember;
#pragma pack(pop)

/**
 * Data structure used for the values collection.
 */
#pragma pack(push, 1)
typedef struct fiftyone_degrees_ipi_cg_member_node_t {
	fiftyoneDegreesCollectionHeader collection;
	uint16_t recordSize; /**< Number of bits that form the value record */
	fiftyoneDegreesIpiCgMember spanIndex; /**< Bit for the span index */
	fiftyoneDegreesIpiCgMember lowFlag; /**< Bit for the low flag */
	fiftyoneDegreesIpiCgMember value; /**< Bits for the value */
} fiftyoneDegreesIpiCgMemberNode;
#pragma pack(pop)

/**
 * Fixed width record in the collection where the record relates to a component
 * and IP version. All the information needed to evaluate the graph with an IP
 * address is available in the structure.
 */
#pragma pack(push, 1)
typedef struct fiftyone_degrees_ipi_cg_info_t {
	byte version; /**< IP address version (4 or 6). The reason byte is used
				  instead of fiftyoneDegreesIpEvidenceType, is that enum is not
			      necessarily a fixed size, so the struct may not always map to
				  the data file. The value can still be cast to the enum type
				  fiftyoneDegreesIpEvidenceType */
	byte componentId; /**< The component id the graph relates to. */
	uint32_t graphIndex; /**< The index to the entry record in the header data
						 structure for the graph. */
	uint32_t firstProfileIndex; /**< The index to the entry record in the 
								header data structure for the graph. */
	uint32_t profileCount; /**< The total number of profiles (not group 
						   profiles) pointed to by the leaf nodes of the graph.
						   */
	uint32_t firstProfileGroupIndex; /**< The index to the entry record in the
								header data structure for the graph. */
	uint32_t profileGroupCount; /**< The total number of profile groups
								pointed to by the leaf nodes of the graph */
	fiftyoneDegreesCollectionHeader spanBytes;
	fiftyoneDegreesCollectionHeader spans;
	fiftyoneDegreesCollectionHeader clusters;
	fiftyoneDegreesIpiCgMemberNode nodes;
} fiftyoneDegreesIpiCgInfo;
#pragma pack(pop)

/**
 * The information and a working collection to retrieve entries from the 
 * component graph.
 */
typedef struct fiftyone_degrees_ipi_cg_t {
	fiftyoneDegreesIpiCgInfo info;
	fiftyoneDegreesCollection* nodes; /**< Nodes collection */
	fiftyoneDegreesCollection* spans; /**< Spans collection */
	fiftyoneDegreesCollection* spanBytes; /**< Span bytes collection */
	fiftyoneDegreesCollection* clusters; /**< Clusters collection */
	uint32_t spansCount; /**< Number of spans available */
	uint32_t clustersCount; /**< Number of clusters available */
} fiftyoneDegreesIpiCg;

/**
 * The evaluation result from graph collection.
 */
typedef struct fiftyone_degrees_ipi_cg_result_t {
	uint32_t rawOffset; /**< Raw offset as returned by the graph (without 
						mapping applied) */
	uint32_t offset; /**< Offset in profileOffset or profileGroups collection 
					 */
	bool isGroupOffset; /**< If offset is for a profile group */
} fiftyoneDegreesIpiCgResult;

/**
 * Default value for fiftyoneDegreesIpiCgResult
 */
#define FIFTYONE_DEGREES_IPI_CG_RESULT_DEFAULT (fiftyoneDegreesIpiCgResult){ \
	UINT32_MAX, \
	UINT32_MAX, \
	false \
}

/**
 * An array of all the component graphs and collections available.
 */
FIFTYONE_DEGREES_ARRAY_TYPE(fiftyoneDegreesIpiCg,)

/**
 * Frees all the memory and resources associated with an array of graphs
 * previous created with fiftyoneDegreesIpiGraphCreateFromFile or
 * fiftyoneDegreesIpiGraphCreateFromMemory.
 * @param graphs pointer to the array to be freed
 */
void fiftyoneDegreesIpiGraphFree(fiftyoneDegreesIpiCgArray* graphs);

/**
 * Creates and initializes an array of graphs for the collection where the
 * underlying data set is held in memory.
 * @param collection of fiftyoneDegreesIpiCgInfo records
 * @param reader to the source data
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return a pointer to the newly allocated array, or null if the operation
 * was not successful.
 */
EXTERNAL fiftyoneDegreesIpiCgArray* fiftyoneDegreesIpiGraphCreateFromMemory(
	fiftyoneDegreesCollection* collection,
	fiftyoneDegreesMemoryReader* reader,
	fiftyoneDegreesException* exception);

/**
 * Creates and initializes an array of graphs for the collection where the
 * underlying data set is on the file system.
 * @param collection of fiftyoneDegreesIpiCgInfo records
 * @param file for to the source data
 * @param reader pool connected to the file
 * @param config for the collections created for each graph
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return a pointer to the newly allocated array, or null if the operation
 * was not successful.
 */
EXTERNAL fiftyoneDegreesIpiCgArray* fiftyoneDegreesIpiGraphCreateFromFile(
	fiftyoneDegreesCollection* collection,
	FILE* file,
	fiftyoneDegreesFilePool* reader,
	const fiftyoneDegreesCollectionConfig config,
	fiftyoneDegreesException* exception);

/**
 * Obtains the profile index for the IP address and component id provided.
 * @param graphs array for each component id and IP version
 * @param componentId of the index required
 * @param address IP address to return a profile index for
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return the index of the profile (or group) associated with the IP address.
 */
EXTERNAL fiftyoneDegreesIpiCgResult fiftyoneDegreesIpiGraphEvaluate(
	fiftyoneDegreesIpiCgArray* graphs,
	byte componentId,
	fiftyoneDegreesIpAddress address,
	fiftyoneDegreesException* exception);

/**
 * Obtains the profile index for the IP address and component id provided 
 * populating the buffer provided with trace information. Requires the
 * definition FIFTYONE_DEGREES_IPI_GRAPH_TRACE to be present.
 * @param graphs array for each component id and IP version
 * @param componentId of the index required
 * @param address IP address to return a profile index for
 * @param buffer that will be populated with the trace information
 * @param length of the buffer
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return the index of the profile (or group) associated with the IP address.
 */
EXTERNAL fiftyoneDegreesIpiCgResult fiftyoneDegreesIpiGraphEvaluateTrace(
	fiftyoneDegreesIpiCgArray* graphs,
	byte componentId,
	fiftyoneDegreesIpAddress address,
	char* buffer,
	int const length,
	fiftyoneDegreesException* exception);

/**
 * @}
 */

#endif

/** Default value for the cache concurrency used in the default configuration. */
#ifndef FIFTYONE_DEGREES_CACHE_CONCURRENCY
#ifndef FIFTYONE_DEGREES_NO_THREADING
#define FIFTYONE_DEGREES_CACHE_CONCURRENCY 10
#else
#define FIFTYONE_DEGREES_CACHE_CONCURRENCY 1
#endif
#endif

/**
 * Default value for the string cache size used in the default collection
 * configuration.
 */
#ifndef FIFTYONE_DEGREES_STRING_CACHE_SIZE
#define FIFTYONE_DEGREES_STRING_CACHE_SIZE 10000
#endif
/**
 * Default value for the string cache loaded size used in the default
 * collection configuration.
 */
#ifndef FIFTYONE_DEGREES_STRING_LOADED
#define FIFTYONE_DEGREES_STRING_LOADED 100
#endif
/**
 * Default value for the graphs cache size used in the default collection
 * configuration.
 */
#ifndef FIFTYONE_DEGREES_IP_GRAPHS_CACHE_SIZE
#define FIFTYONE_DEGREES_IP_GRAPHS_CACHE_SIZE 1000
#endif
/**
 * Default value for the graphs cache loaded size used in the default 
 * collection configuration.
 */
#ifndef FIFTYONE_DEGREES_IP_GRAPHS_LOADED
#define FIFTYONE_DEGREES_IP_GRAPHS_LOADED 1000
#endif
/**
 * Default value for the graphs cache size used in the default collection
 * configuration.
 */
#ifndef FIFTYONE_DEGREES_IP_GRAPH_CACHE_SIZE
#define FIFTYONE_DEGREES_IP_GRAPH_CACHE_SIZE 50000
#endif
/**
 * Default value for the graphs cache loaded size used in the default 
 * collection configuration.
 */
#ifndef FIFTYONE_DEGREES_IP_GRAPH_LOADED
#define FIFTYONE_DEGREES_IP_GRAPH_LOADED 5000
#endif
/**
 * Default value for the profile groups cache size used in the default 
 * collection configuration.
 */
#ifndef FIFTYONE_DEGREES_PROFILE_GROUPS_CACHE_SIZE
#define FIFTYONE_DEGREES_PROFILE_GROUPS_CACHE_SIZE 50000
#endif
/**
 * Default value for the profile groups cache loaded size used in the default collection
 * configuration.
 */
#ifndef FIFTYONE_DEGREES_PROFILE_GROUPS_LOADED
#define FIFTYONE_DEGREES_PROFILE_GROUPS_LOADED 100
#endif
/**
 * Default value for the profile cache size used in the default collection
 * configuration.
 */
#ifndef FIFTYONE_DEGREES_PROFILE_CACHE_SIZE
#define FIFTYONE_DEGREES_PROFILE_CACHE_SIZE 10000
#endif
/**
 * Default value for the profile cache loaded size used in the default
 * collection configuration.
 */
#ifndef FIFTYONE_DEGREES_PROFILE_LOADED
#define FIFTYONE_DEGREES_PROFILE_LOADED 100
#endif
/**
 * Default value for the value cache size used in the default collection
 * configuration.
 */
#ifndef FIFTYONE_DEGREES_VALUE_CACHE_SIZE
#define FIFTYONE_DEGREES_VALUE_CACHE_SIZE 500
#endif
/**
 * Default value for the value cache loaded size used in the default collection
 * configuration.
 */
#ifndef FIFTYONE_DEGREES_VALUE_LOADED
#define FIFTYONE_DEGREES_VALUE_LOADED 0
#endif
/**
 * Default value for the property cache size used in the default collection
 * configuration.
 */
#ifndef FIFTYONE_DEGREES_PROPERTY_CACHE_SIZE
#define FIFTYONE_DEGREES_PROPERTY_CACHE_SIZE 0
#endif
/**
 * Default value for the property cache loaded size used in the default
 * collection configuration.
 */
#ifndef FIFTYONE_DEGREES_PROPERTY_LOADED
#define FIFTYONE_DEGREES_PROPERTY_LOADED INT_MAX
#endif

/**
 * DATA STRUCTURES
 */

/** Dataset header containing information about the dataset. */
#pragma pack(push, 1)
typedef struct fiftyone_degrees_ipi_dataset_header_t {
	const int32_t versionMajor; /**< Major version of the data file loaded */
	const int32_t versionMinor; /**< Minor version of the data file loaded */
	const int32_t versionBuild; /**< Build version of the data file loaded */
	const int32_t versionRevision; /**< Revision version of the data file 
								   loaded */
	const byte tag[16]; /**< Unique data file tag */
	const byte exportTag[16]; /**< Tag identifying the data file export */
	const int32_t copyrightOffset; /**< Offset of the copyright string in the 
								   strings collection */
	const int16_t age; /**< Age of the data set format */
	const int32_t minUserAgentCount; /**< This is a place holder. Not
									 applicable to IP Intelligence. */
	const int32_t nameOffset; /**< Offset of the data file name in the strings 
							  collection */
	const int32_t formatOffset; /**< Offset of the data file format in the 
								strings collection */
	const fiftyoneDegreesDate published; /**< Date when the data file was 
										 published */
	const fiftyoneDegreesDate nextUpdate; /**< Date when the next data file 
										  will be available */
	const fiftyoneDegreesCollectionHeader strings; /**< Size and location of
												   the strings collection */
	const fiftyoneDegreesCollectionHeader components; /**< Size and location of
													  the components 
													  collection */
	const fiftyoneDegreesCollectionHeader maps; /**< Size and location of the
												maps collection */
	const fiftyoneDegreesCollectionHeader properties; /**< Size and location of
													  the properties 
													  collection */
	const fiftyoneDegreesCollectionHeader values; /**< Size and location of the
												  values collection */
	const fiftyoneDegreesCollectionHeader profiles; /**< Size and location of
													the profiles collection */
	const fiftyoneDegreesCollectionHeader graphs; /**< Headers for component
												  graphs */
	const fiftyoneDegreesCollectionHeader profileGroups; /**< Size and
														  location of the
														  profile group offsets
														  collection */
	const fiftyoneDegreesCollectionHeader propertyTypes; /**< Size and location of
													     the propertyTypes
													     collection */
	const fiftyoneDegreesCollectionHeader profileOffsets; /**< Size and
														  location of the
														  profile offsets
														  collection */
} fiftyoneDegreesDataSetIpiHeader;
#pragma pack(pop)

/**
 * IP Intelligence specific configuration structure.
 */
typedef struct fiftyone_degrees_config_ipi_t {
	fiftyoneDegreesConfigBase b; /**< Base configuration */
	fiftyoneDegreesCollectionConfig strings; /**< Strings collection config */
	fiftyoneDegreesCollectionConfig components; /**< Components collection
												config */
	fiftyoneDegreesCollectionConfig maps; /**< Maps collection config */
	fiftyoneDegreesCollectionConfig properties; /**< Properties collection
												config */
	fiftyoneDegreesCollectionConfig values; /**< Values collection config */
	fiftyoneDegreesCollectionConfig profiles; /**< Profiles collection config 
											  */
	fiftyoneDegreesCollectionConfig graphs; /**< Graphs config */
	fiftyoneDegreesCollectionConfig profileGroups; /**< profileGroups
												   collection config */
	fiftyoneDegreesCollectionConfig profileOffsets; /**< ProfileOffsets
													collection config */
	fiftyoneDegreesCollectionConfig propertyTypes; /**< Property types collection
												   config */
	fiftyoneDegreesCollectionConfig graph; /**< Config for each graph */
} fiftyoneDegreesConfigIpi;

/**
 * Data set structure which contains the base dataset structure. This
 * acts as a wrapper and is used in the dataset structure for IP 
 * intelligence to be compatible with some of the common-cxx
 * APIs.
 */
typedef struct fiftyone_degrees_dataset_ipi_base_t {
	fiftyoneDegreesDataSetBase b; /**< Base structure members */
} fiftyoneDegreesDataSetIpiBase;

/**
 * Data set structure containing all the components used for IP intelligence.
 * This should predominantly be used through a #fiftyoneDegreesResourceManager
 * pointer to maintain a safe reference. If access the data set is needed then
 * a safe reference can be fetched and released with the
 * #fiftyoneDegreesDataSetIpiGet and #fiftyoneDegreesDataSetIpiRelease
 * methods.
 */
typedef struct fiftyone_degrees_dataset_ipi_t {
	fiftyoneDegreesDataSetIpiBase b; /**< Base data set */
	const fiftyoneDegreesDataSetIpiHeader header; /**< Dataset header */
	const fiftyoneDegreesConfigIpi config; /**< Copy of the configuration */
	fiftyoneDegreesCollection *strings; /**< Collection of all strings */
	fiftyoneDegreesCollection *components; /**< Collection of all components */
	fiftyoneDegreesList componentsList; /**< List of component items from the
										components collection */
	bool *componentsAvailable; /**< Array of flags indicating if there are
							   any properties available for the component with
							   the matching index in componentsList */
	uint32_t componentsAvailableCount; /**< Number of components with
									   properties */
	fiftyoneDegreesCollection *maps; /**< Collection data file maps */
	fiftyoneDegreesCollection *properties; /**< Collection data file properties
										   */
	fiftyoneDegreesCollection *values; /**< Collection data file values */
	fiftyoneDegreesCollection *profiles; /**< Collection data file profiles */
	fiftyoneDegreesCollection *graphs; /**< Collection of graph infos used to
									   create the array of graphs */
	fiftyoneDegreesCollection *profileGroups; /**< Collection of all profile 
											  groups where more than one 
											  profile is required with a weight
											  */
	fiftyoneDegreesCollection *propertyTypes; /**< Collection data file properties
											  */
	fiftyoneDegreesCollection *profileOffsets; /**< Collection of all offsets
											   to profiles in the profiles
											   collection */
	fiftyoneDegreesIpiCgArray* graphsArray; /**< Array of graphs from 
											collection */
} fiftyoneDegreesDataSetIpi;


/**
 * The structure to hold a pair of result item and its percentage
 * When getting values for a property from the result
 * the values will be a list of potential matching items
 * and their weights to indicate the proportion of this item
 * for the matched IP range in our data. This structure represents
 * an item in the list.
 */
typedef struct fiftyone_degrees_profile_percentage_t {
	fiftyoneDegreesCollectionItem item; /**< A collection item which contains the value */
	uint16_t rawWeighting; /**< The proportion of the item in the returned values (out of 65535) */
} fiftyoneDegreesProfilePercentage;

/**
 * When the load factor in the list is reached
 * the list will resize to this factor of the current capacity
 */
#define IPI_LIST_RESIZE_FACTOR 1.5f
/**
 * Default load factor for IP intelligence list
 */
#define IPI_LIST_DEFAULT_LOAD_FACTOR 0.7f

/**
 * The structure which represents the list of values
 * returned for the required property from the results.
 * This is a dynamic list which will be resized when
 * the loadFactor is reached.
 */
typedef struct fiftyone_degrees_ipi_list_t {
	fiftyoneDegreesProfilePercentage *items; /**< List of items and their percentages */
	uint32_t capacity; /**< The capacity of the list */
	uint32_t count; /**< The current number of item in the list*/
	float loadFactor; /**< The load factor to determine when the list
							should be resized*/
} fiftyoneDegreesIpiList;

/**
 * Singular IP address result returned by a detection process method.
 */
typedef struct fiftyone_degrees_result_ipi_t {
	fiftyoneDegreesIpType type; /**< The version of the IP */
	fiftyoneDegreesIpiCgResult graphResult; /**< The result of
												 graph evaluation */
	fiftyoneDegreesIpAddress targetIpAddress; /**< The target IP address
											  to find a matching range for */
} fiftyoneDegreesResultIpi;

/**
 * Macro defining the common members of an Ipi result.
 */
#define FIFTYONE_DEGREES_RESULTS_IPI_MEMBERS \
	fiftyoneDegreesResultsBase b; \
	fiftyoneDegreesCollectionItem propertyItem; \
	fiftyoneDegreesIpiList values;

FIFTYONE_DEGREES_ARRAY_TYPE(
	fiftyoneDegreesResultIpi,
	FIFTYONE_DEGREES_RESULTS_IPI_MEMBERS)

/**
 * Array of Ipi results used to easily access and track the size of the
 * array.
 */
typedef fiftyoneDegreesResultIpiArray fiftyoneDegreesResultsIpi;

/**
 * Define the IP range structure
 */
#define FIFTYONE_DEGREES_IP_RANGE(v, s) \
typedef struct fiftyone_degrees_dataset_ip_v##v##_range_t { \
	byte start[s]; /**< the start of the range in byte array format */ \
	int32_t profileOffsetIndex; /**< The index of set the matching profile offset/group */ \
} fiftyoneDegreesIpv##v##Range;

/**
 * Define the ip roots structure
 */
FIFTYONE_DEGREES_IP_RANGE(4, 4)

/**
 * Define the ip nodes structure
 */
FIFTYONE_DEGREES_IP_RANGE(6, 16)

/**
 * Index of a profile in a profile groups item
 * This include the component Index to indicate in which component
 * it belong to.
 */
typedef struct fiftyone_degrees_combination_profile_index_t {
	int32_t componentIndex; /**< Index of the component based on components list */
	int32_t profileIndex; /**< Index of the profile index for the associated component */
} fiftyoneDegreesCombinationProfileIndex;

/**
 * Index of a profile in a profile groups item of a result
 * This include the component and result Indices to indicate in which
 * component the profile belong to in which result. 
 */
typedef struct fiftyone_degrees_result_profile_index_t {
	int16_t resultIndex;
	fiftyoneDegreesCombinationProfileIndex componentProfileIndex;
} fiftyoneDegreesResultProfileIndex;

/**
 * IP INTELLIGENCE CONFIGURATIONS
 */

/**
 * Configuration to be used where the data set is being created using a buffer
 * in memory and concepts like caching are not required. The concurrency
 * setting is ignored as there are no critical sections with this configuration.
 */
EXTERNAL_VAR fiftyoneDegreesConfigIpi fiftyoneDegreesIpiInMemoryConfig;

/**
 * Highest performance configuration. Loads all the data into memory and does
 * not maintain a connection to the source data file used to build the data
 * set. The concurrency setting is ignored as there are no critical sections
 * with this configuration.
 */
EXTERNAL_VAR fiftyoneDegreesConfigIpi fiftyoneDegreesIpiHighPerformanceConfig;

/**
 * Low memory configuration. A connection is maintained to the source data file
 * used to build the data set and used to load data into memory when required.
 * No caching is used resulting in the lowest memory footprint at the expense
 * of performance. The concurrency of each collection must be set to the
 * maximum number of concurrent operations to optimize file reads.
 */
EXTERNAL_VAR fiftyoneDegreesConfigIpi fiftyoneDegreesIpiLowMemoryConfig;

/**
 * Uses caching to balance memory usage and performance. A connection is
 * maintained to the source data file to load data into caches when required.
 * As the cache is loaded, memory will increase until the cache capacity is
 * reached. The concurrency of each collection must be set to the maximum
 * number of concurrent operations to optimize file reads. This is the default
 * configuration.
 */
EXTERNAL_VAR fiftyoneDegreesConfigIpi fiftyoneDegreesIpiBalancedConfig;

/**
 * Balanced configuration modified to create a temporary file copy of the
 * source data file to avoid locking the source data file.
 */
EXTERNAL_VAR fiftyoneDegreesConfigIpi fiftyoneDegreesIpiBalancedTempConfig;

/**
 * Default detection configuration. This configures the data set to not create
 * a temp file.
 */
EXTERNAL_VAR fiftyoneDegreesConfigIpi fiftyoneDegreesIpiDefaultConfig;

/**
 * Configuration designed only for testing. This uses a loaded size of 1 in
 * all collections to ensure all every get and release calls can be tested for
 * items which do not exist in the root collection. This configuration is not
 * exposed through C++ intentionally as it is only used in testing.
 */
EXTERNAL_VAR fiftyoneDegreesConfigIpi fiftyoneDegreesIpiSingleLoadedConfig;


/**
 * EXTERNAL METHODS
 */

/**
 * Gets a safe reference to the IP Intelligencedata set from the resource manager.
 * Fetching through this method ensures that the data set it not freed or moved
 * during the time it is in use.
 * The data set returned by this method should be released with the
 * #fiftyoneDegreesDataSetIpiRelease method.
 * @param manager the resource manager containing a IP intelligence data set initialised
 * by one of the IP intelligence data set init methods
 * @return a fixed pointer to the data set in manager
 */
EXTERNAL fiftyoneDegreesDataSetIpi* fiftyoneDegreesDataSetIpiGet(
	fiftyoneDegreesResourceManager* manager);

/**
 * Release the reference to a data set returned by the
 * #fiftyoneDegreesDataSetIpiGet method. Doing so tell the resource manager
 * linked to the data set that it is no longer being used.
 * @param dataSet pointer to the data set to release
 */
EXTERNAL void fiftyoneDegreesDataSetIpiRelease(fiftyoneDegreesDataSetIpi* dataset);

/**
 * Gets the total size in bytes which will be allocated when intialising a
 * IP Intelligence resource and associated manager with the same parameters. If any of
 * the configuration options prevent the memory from being constant (i.e. more
 * memory may be allocated at process time) then zero is returned.
 * @param config configuration for the operation of the data set, or NULL if
 * default configuration is required
 * @param properties the properties that will be consumed from the data set, or
 * NULL if all available properties in the IP Intelligence data file should be available
 * for consumption
 * @param fileName the full path to a file with read permission that contains
 * the IP Intelligence data set
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return the total number of bytes needed to initialise a IP Intelligence resource
 * and associated manager with the configuration provided or zero
 */
EXTERNAL size_t fiftyoneDegreesIpiSizeManagerFromFile(
	fiftyoneDegreesConfigIpi* config,
	fiftyoneDegreesPropertiesRequired* properties,
	const char* fileName,
	fiftyoneDegreesException* exception);

/**
 * Initialises the resource manager with an IP intelligence data set resource populated
 * from the IP Intelligence data file referred to by fileName. Configures the data set
 * to operate using the configuration set in detection, collection and
 * properties.
 * @param manager the resource manager to manager the share data set resource
 * @param config configuration for the operation of the data set, or NULL if
 * default configuration is required
 * @param properties the properties that will be consumed from the data set, or
 * NULL if all available properties in the IP Intelligence data file should be available
 * for consumption
 * @param fileName the full path to a file with read permission that contains
 * the IP Intelligence data set
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return the status associated with the data set resource assign to the
 * resource manager. Any value other than #FIFTYONE_DEGREES_STATUS_SUCCESS
 * means the data set was not created and the resource manager can not be used.
 */
EXTERNAL fiftyoneDegreesStatusCode fiftyoneDegreesIpiInitManagerFromFile(
	fiftyoneDegreesResourceManager* manager,
	fiftyoneDegreesConfigIpi* config,
	fiftyoneDegreesPropertiesRequired* properties,
	const char* fileName,
	fiftyoneDegreesException* exception);

/**
 * Gets the total size in bytes which will be allocated when intialising a
 * IP Intelligence resource and associated manager with the same parameters. If any of
 * the configuration options prevent the memory from being constant (i.e. more
 * memory may be allocated at process time) then zero is returned.
 * @param config configuration for the operation of the data set, or NULL if
 * default configuration is required
 * @param properties the properties that will be consumed from the data set, or
 * NULL if all available properties in the IP Intelligence data file should be available
 * for consumption
 * @param memory pointer to continuous memory containing the IP intelligence data set
 * @param size the number of bytes that make up the IP intelligence data set
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return the total number of bytes needed to initialise a IP Intelligence resource
 * and associated manager with the configuration provided or zero
 */
EXTERNAL size_t fiftyoneDegreesIpiSizeManagerFromMemory(
	fiftyoneDegreesConfigIpi* config,
	fiftyoneDegreesPropertiesRequired* properties,
	void* memory,
	fiftyoneDegreesFileOffset size,
	fiftyoneDegreesException* exception);

/**
 * Initialises the resource manager with a IP Intelligence data set resource populated
 * from the IP intelligence data set pointed to by the memory parameter. Configures the
 * data set to operate using the configuration set in detection and properties.
 * @param manager the resource manager to manager the share data set resource
 * @param config configuration for the operation of the data set, or NULL if
 * default configuration is required
 * @param properties the properties that will be consumed from the data set, or
 * NULL if all available properties in the IP intelligence data file should be available
 * for consumption
 * @param memory pointer to continuous memory containing the IP Intelligence data set
 * @param size the number of bytes that make up the IP Intelligence data set
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return the status associated with the data set resource assign to the
 * resource manager. Any value other than #FIFTYONE_DEGREES_STATUS_SUCCESS
 * means the data set was not created and the resource manager can not be used.
 */
EXTERNAL fiftyoneDegreesStatusCode fiftyoneDegreesIpiInitManagerFromMemory(
	fiftyoneDegreesResourceManager* manager,
	fiftyoneDegreesConfigIpi* config,
	fiftyoneDegreesPropertiesRequired* properties,
	void* memory,
	fiftyoneDegreesFileOffset size,
	fiftyoneDegreesException* exception);

/**
 * Read a profile groups item from the file collection provided and 
 * store in the data pointer. This method is used when creating a collection
 * from file.
 * @param file collection to read from
 * @param offset of the profile groups in the collection
 * @param data to store the resulting profile groups in
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h
 * @return pointer to the component allocated within the data structure
 */
EXTERNAL void* fiftyoneDegreesProfileCombinationReadFromFile(
	const fiftyoneDegreesCollectionFile* file,
	uint32_t offset,
	fiftyoneDegreesData* data,
	fiftyoneDegreesException* exception);

/**
 * Reload the data set being used by the resource manager using the data file
 * location specified. When initialising the data, the configuration that
 * manager was first created with is used.
 *
 * If the new data file is successfully initialised, the current data set is
 * replaced The old data will remain in memory until the last
 * #fiftyoneDegreesResultsIpi which contain a reference to it are released.
 *
 * This method is defined by the #FIFTYONE_DEGREES_DATASET_RELOAD macro.
 * @param manager pointer to the resource manager to reload the data set for
 * @param fileName path to the new data file
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return the status associated with the data set reload. Any value other than
 * #FIFTYONE_DEGREES_STATUS_SUCCESS means the data set was not reloaded
 * correctly
 */
EXTERNAL fiftyoneDegreesStatusCode fiftyoneDegreesIpiReloadManagerFromFile(
	fiftyoneDegreesResourceManager* manager,
	const char* fileName,
	fiftyoneDegreesException* exception);

/**
 * Reload the data set being used by the resource manager using a data file
 * loaded into contiguous memory. When initialising the data, the configuration
 * that manager was first created with is used.
 *
 * If the data passed in is successfully initialised, the current data set is
 * replaced The old data will remain in memory until the last
 * #fiftyoneDegreesResultsIpi which contain a reference to it are released.
 *
 * This method is defined by the #FIFTYONE_DEGREES_DATASET_RELOAD macro.
 * @param manager pointer to the resource manager to reload the data set for
 * @param source pointer to the memory location where the new data file is
 *               stored
 * @param length of the data in memory
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return the status associated with the data set reload. Any value other than
 * #FIFTYONE_DEGREES_STATUS_SUCCESS means the data set was not reloaded
 * correctly
 */
EXTERNAL fiftyoneDegreesStatusCode fiftyoneDegreesIpiReloadManagerFromMemory(
	fiftyoneDegreesResourceManager* manager,
	void* source,
	fiftyoneDegreesFileOffset length,
	fiftyoneDegreesException* exception);

/**
 * Reload the data set being used by the resource manager using the data file
 * location which was used when the manager was created. When initialising the
 * data, the configuration that manager was first created with is used.
 *
 * If the new data file is successfully initialised, the current data set is
 * replaced The old data will remain in memory until the last
 * #fiftyoneDegreesResultsIpi which contain a reference to it are released.
 *
 * This method is defined by the #FIFTYONE_DEGREES_DATASET_RELOAD macro.
 * @param manager pointer to the resource manager to reload the data set for
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return the status associated with the data set reload. Any value other than
 * #FIFTYONE_DEGREES_STATUS_SUCCESS means the data set was not reloaded
 * correctly
 */
EXTERNAL fiftyoneDegreesStatusCode  
fiftyoneDegreesIpiReloadManagerFromOriginalFile(
	fiftyoneDegreesResourceManager* manager,
	fiftyoneDegreesException* exception);

/**
 * Allocates a results structure containing a reference to the IP Intelligence
 * data set managed by the resource manager provided. The referenced data set
 * will be kept active until the results structure is freed.
 * There can only be one result for per input IP address
 * @param manager pointer to the resource manager which manages a IP 
 * Intelligence data set
 * @return newly created results structure
 */
EXTERNAL fiftyoneDegreesResultsIpi* fiftyoneDegreesResultsIpiCreate(
	fiftyoneDegreesResourceManager* manager);

/**
 * Frees the results structure created by the
 * #fiftyoneDegreesResultsIpiCreate method. When freeing, the reference to
 * the IP Intelligence data set resource is released.
 * @param results pointer to the results structure to release
 */
EXTERNAL void fiftyoneDegreesResultsIpiFree(
	fiftyoneDegreesResultsIpi* results);

/**
 * Process a single byte array format IP Address and populate the IP range 
 * offset in the results structure. The result IP type will need to be checked
 * to determined the version of IP being processed.
 * @param results preallocated results structure to populate
 * @param ipAddress byte array to process
 * @param ipAddressLength of the IP address byte array
 * @param type of the ip
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 */
EXTERNAL void fiftyoneDegreesResultsIpiFromIpAddress(
	fiftyoneDegreesResultsIpi* results,
	const unsigned char* ipAddress,
	size_t ipAddressLength,
	fiftyoneDegreesIpType type,
	fiftyoneDegreesException* exception);

/**
 * Process a single IP Address and populate the IP range offset in the results
 * structure.
 * @param results preallocated results structure to populate
 * @param ipAddress string to process
 * @param ipAddressLength of the ipAddress string
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 */
EXTERNAL void fiftyoneDegreesResultsIpiFromIpAddressString(
	fiftyoneDegreesResultsIpi* results,
	const char* ipAddress,
	size_t ipAddressLength,
	fiftyoneDegreesException* exception);

/**
 * Processes the evidence value pairs in the evidence collection and
 * populates the result in the results structure.
 * @param results preallocated results structure to populate containing a
 *                pointer to an initialised resource manager
 * @param evidence to process containing parsed or unparsed values
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 */
EXTERNAL void fiftyoneDegreesResultsIpiFromEvidence(
	fiftyoneDegreesResultsIpi* results,
	fiftyoneDegreesEvidenceKeyValuePairArray* evidence,
	fiftyoneDegreesException* exception);

/**
 * Gets whether or not the results provided contain valid values for the
 * property index provided.
 * @param results pointer to the results to check
 * @param requiredPropertyIndex index in the required properties of the
 * property to check for values of
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return true if there are valid values in the results for the property index
 * provided
 */
EXTERNAL bool fiftyoneDegreesResultsIpiGetHasValues(
	fiftyoneDegreesResultsIpi* results,
	int requiredPropertyIndex,
	fiftyoneDegreesException* exception);

/**
 * Gets the reason why a results does not contain valid values for a given
 * property. 
 * @param results pointer to the results to check
 * @param requiredPropertyIndex index in the required properties of the
 * property to check for values of
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return enum indicating why a valid value cannot be returned by the results
 */
EXTERNAL fiftyoneDegreesResultsNoValueReason fiftyoneDegreesResultsIpiGetNoValueReason(
	fiftyoneDegreesResultsIpi* results,
	int requiredPropertyIndex,
	fiftyoneDegreesException* exception);

/**
 * Gets a fuller description of the reason why a value is missing.
 * @param reason enum of the reason for the missing value
 * @return full description for the reason
 */
EXTERNAL const char* fiftyoneDegreesResultsIpiGetNoValueReasonMessage(
	fiftyoneDegreesResultsNoValueReason reason);

/**
 * Populates the list of values in the results instance with value structure
 * instances associated with the required property index. When the results 
 * are released then the value items will be released. There is no need for
 * the caller to release the collection item returned. The 
 * fiftyoneDegreesResultsIpiGetValueString method should be used to get
 * the string representation of the value.
 * @param results pointer to the results structure to release
 * @param requiredPropertyIndex
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return a pointer to the first value item 
 */
EXTERNAL const fiftyoneDegreesProfilePercentage* fiftyoneDegreesResultsIpiGetValues(
	fiftyoneDegreesResultsIpi* results,
	int requiredPropertyIndex,
	fiftyoneDegreesException* exception);

/**
 * Adds to builder the values associated in the results for the property name.
 * @param results pointer to the results structure to release
 * @param propertyName name of the property to be used with the values
 * @param builder string builder to fill with values
 * @param separator string to be used to separate multiple values if available
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 */
EXTERNAL void fiftyoneDegreesResultsIpiAddValuesString(
	fiftyoneDegreesResultsIpi* results,
	const char* propertyName,
	fiftyoneDegreesStringBuilder *builder,
	const char* separator,
	fiftyoneDegreesException* exception);

/**
 * Sets the buffer the values associated in the results for the property name.
 * @param results pointer to the results structure to release
 * @param propertyName name of the property to be used with the values
 * @param buffer character buffer allocated by the caller
 * @param bufferLength of the character buffer
 * @param separator string to be used to separate multiple values if available
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return the number of characters available for values. May be larger than
 * bufferLength if the buffer is not long enough to return the result.
 */
EXTERNAL size_t fiftyoneDegreesResultsIpiGetValuesString(
	fiftyoneDegreesResultsIpi* results,
	const char* propertyName,
	char* buffer,
	size_t bufferLength,
	const char* separator,
	fiftyoneDegreesException* exception);

/**
 * Sets the buffer the values associated in the results for the property name.
 * @param results pointer to the results structure to release
 * @param requiredPropertyIndex required property index of for the values
 * @param buffer character buffer allocated by the caller
 * @param bufferLength of the character buffer
 * @param separator string to be used to separate multiple values if available
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h.
 * @return the number of characters available for values. May be larger than
 * bufferLength if the buffer is not long enough to return the result.
 */
EXTERNAL size_t fiftyoneDegreesResultsIpiGetValuesStringByRequiredPropertyIndex(
	fiftyoneDegreesResultsIpi* results,
	const int requiredPropertyIndex,
	char* buffer,
	size_t bufferLength,
	const char* separator,
	fiftyoneDegreesException* exception);

/**
 * Get the network id string from the single result provided. This contains
 * profile ids for all components and their percentages for the matched
 * IP range, delimited by ':'. The profile id percentage pairs are concatenated
 * with the separator character '|'.
 * @param results pointer to the results
 * @param result pointer to the result to get the network id of
 * @param destination pointer to the memory to write the characters to
 * @param size amount of memory allocated to destination
 * @param componentProfileIndex the combination profile index to start
 * constructing the network ID from. Negative values indicate nothing
 * to fetch.
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h
 * @return the combination profile index to start from in the next call for
 * fetching the remaining of the network ID. All indices will be -1s there
 * is no more to fetch. The returned format does not contain leading or
 * trailing separator so the separator will need to be added explicitly
 * if more than one call  is required.
 */
EXTERNAL fiftyoneDegreesCombinationProfileIndex 
fiftyoneDegreesIpiGetNetworkIdFromResult(
	fiftyoneDegreesResultsIpi* results,
	fiftyoneDegreesResultIpi* result,
	char* destination,
	size_t size,
	fiftyoneDegreesCombinationProfileIndex componentProfileIndex,
	fiftyoneDegreesException* exception);

/**
 * Get the network id string from the results provided. This contains
 * profile ids for all components and their percentages for the matched
 * IP range, delimited by ':'. The profile id percentage pairs are concatenated
 * with the separator character '|'.
 * @param results pointer to the results
 * @param destination pointer to the memory to write the characters to
 * @param size amount of memory allocated to destination
 * @param resultProfileIndex the profile index to start constructing the network
 * ID from. Negative values indicate nothing to fetch.
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h
 * @return the result profile index to start from in the next call for
 * fetching the remaining of the network ID. All indices will be -1s there
 * is no more to fetch. The returned format does not contain leading or
 * trailing separator so the separator will need to be added explicitly
 * if more than one call  is required.
 */
EXTERNAL fiftyoneDegreesResultProfileIndex
fiftyoneDegreesIpiGetNetworkIdFromResults(
	fiftyoneDegreesResultsIpi* results,
	char* destination,
	size_t size,
	fiftyoneDegreesResultProfileIndex resultProfileIndex,
	fiftyoneDegreesException* exception);

/**
 * Iterates over the profiles in the data set calling the callback method for
 * any profiles that contain the property and value provided.
 * This currently not applicable for properties 'IpRangeStart', 'IpRangeEnd',
 * 'AverageLocation', 'LocationBoundSouthEast', 'LocationBoundNortWest' as
 * these data are not stored in the profiles collection.
 * @param manager the resource manager containing a IP Intelligence data set initialised
 * by one of the IP Intelligence data set init methods
 * @param propertyName name of the property which the value relates to
 * @param valueName name of the property value which the profiles must contain
 * @param state pointer passed to the callback method
 * @param callback method called when a matching profile is found
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h
 * @return the number of matching profiles iterated over
 */
EXTERNAL uint32_t fiftyoneDegreesIpiIterateProfilesForPropertyAndValue(
	fiftyoneDegreesResourceManager* manager,
	const char* propertyName,
	const char* valueName,
	void* state,
	fiftyoneDegreesProfileIterateMethod callback,
	fiftyoneDegreesException* exception);

/**
 * Get the ipaddress string from the collection item. This should
 * be used on the item returned from #fiftyoneDegreesResultsIpiGetValues
 * where the property is 'RangeStart', 'RangeEnd'.
 * @param item the collection item pointing to the strings item in
 * strings collection
 * @param type the verion of IP which can be check from result
 * @param buffer the preallocated buffer to hold the returned string
 * @param bufferLength the number of bytes allocated for the buffer
 * @param exception pointer to an exception data structure to be used if an
 * exception occurs. See exceptions.h
 * @return the number of characters added to the buffer
 */
EXTERNAL size_t fiftyoneDegreesIpiGetIpAddressAsString(
	const fiftyoneDegreesCollectionItem *item,
	fiftyoneDegreesIpType type,
	char *buffer,
	uint32_t bufferLength,
	fiftyoneDegreesException *exception);

/**
 * @}
 */

#endif
/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2025 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

#ifndef FIFTYONE_DEGREES_CONSTANTSIPI_H
#define FIFTYONE_DEGREES_CONSTANTSIPI_H

#include <stdint.h>

static const uint8_t fiftyoneDegreesDefaultWktDecimalPlaces = 16;

#endif //FIFTYONE_DEGREES_CONSTANTSIPI_H
/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2023 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

/**
 * @defgroup FiftyOneDegreesCommon Common
 *
 * Common 51Degrees methods, types and macros.
 */

/**
 * @ingroup FiftyOneDegreesCommon
 * @defgroup FiftyOneDegreesSynonyms Synonyms
 *
 * Quick shortenings of common methods and types.
 *
 * ## Introduction
 *
 * To ensure compatibility with larger projects where naming conflicts could
 * occur this aliases file enables references to 51degrees functions, 
 * structures and types to be made without requiring the prefix
 * `fiftyoneDegrees` to be provided. This is similar to the use of namespaces
 * in languages which support them and leads to code that is shorter and easier
 * to read.
 *
 * @{
 */

#ifndef FIFTYONE_DEGREES_SYNONYM_COMMON_INCLUDED
#define FIFTYONE_DEGREES_SYNONYM_COMMON_INCLUDED

/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2023 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

#include <stdio.h>

#if defined(__MINGW32__) || defined(__MINGW64__)
// MinGW Snprintf version is defined based on Windows _Snprintf
// which is not standard confirming. Use __mingw_Snprintf which
// is standard conforming implementation of Snprintf.
#define Snprintf __mingw_snprintf
#else
// Other non-mingw the default Snprintf is standard conforming.
#define Snprintf snprintf
#endif
/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2023 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

#ifndef FIFTYONE_DEGREES_BOOL_INCLUDED
#define FIFTYONE_DEGREES_BOOL_INCLUDED

#include <stdbool.h>

#ifdef __cplusplus
#define EXTERNAL extern "C"
#else
#define EXTERNAL
#endif

/**
 * Convert integer to bool type. This is mainly to support
 * language that do not support function to cast to C bool
 * type
 */
EXTERNAL bool fiftyoneDegreesIntToBool(int i);

/**
 * Convert bool to integer type. This is mainly to support
 * language that do not suport function to cast between C
 * bool and integer type.
 */
EXTERNAL int fiftyoneDegreesBoolToInt(bool b);

#endif
/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2023 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

#ifndef FIFTYONE_DEGREES_PROCESS_H_INCLUDED
#define FIFTYONE_DEGREES_PROCESS_H_INCLUDED


/**
 * Get the ID of the current process
 * @return ID of the current process
 */
EXTERNAL uint64_t fiftyoneDegreesProcessGetId();

#endif

/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2023 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

#ifndef FIFTYONE_DEGREES_YAMLFILE_H_INCLUDED
#define FIFTYONE_DEGREES_YAMLFILE_H_INCLUDED

#include <stdio.h>
#include <ctype.h>

/**
 * APIs for iterating through yaml documents.
 * The yaml document is expected be in a simple format
 *
 * i.e.
 * ---
 * key1: value1
 * key2: value2
 * ---
 * keyn: valuen
 * ...
 * 
 * Syntax:
 * - doc-start ::= (---)
 * - docs-end ::= (...)
 * - key ::= [a-zA-Z0-9.]+
 * - value ::= [a-zA-Z0-9.]+
 * - separtor ::= (:)
 * - pair ::= key separator white-space value
 * - documents ::= document* docs-end
 * - document = doc-start linefeed pair*
 */

/**
 * Iterate through documents up to a given limit in a yaml file.
 * Call the callback function for each document.
 * The document should be structured as documented at the top
 * @param fileName name of the file to be processed
 * @param buffer buffer used to hold data read from the file during the process
 * @param length lengh of th buffer
 * @param keyValuePairs an array of key value pairs used to hold the document
 * key value pairs during the process. Each key and value length should be
 * big enough to hold the biggest  key or value. Else, insufficient memory error
 * will be thrown.
 * @param collectionSize size of the keyValuePairs array
 * @param limit number of document to process
 * @param state the state maintained externally. To be passed to the callback
 * function.
 * @param callback function to call back when a document is read.
 */
EXTERNAL fiftyoneDegreesStatusCode fiftyoneDegreesYamlFileIterateWithLimit(
	const char* fileName,
	char* buffer,
	size_t length,
	fiftyoneDegreesKeyValuePair* keyValuePairs,
	uint16_t collectionSize,
	int limit,
	void* state,
	void(*callback)(fiftyoneDegreesKeyValuePair*, uint16_t, void*));

/**
 * Iterate through documents in a yaml file.
 * Call the callback function for each document.
 * The document should be structured as documented at the top
 * @param fileName name of the file to be processed
 * @param buffer buffer used to hold data read from the file during the process
 * @param length lengh of th buffer
 * @param keyValuePairs an array of key value pairs used to hold the document
 * key value pairs during the process. Each key and value length should be
 * big enough to hold the biggest key or value. Else, insufficient memory error
 * will be thrown.
 * @param collectionSize size of the keyValuePairs array
 * @param state the state maintained externally. To be passed to the callback
 * function.
 * @param callback function to call back when a document is read.
 */
EXTERNAL fiftyoneDegreesStatusCode fiftyoneDegreesYamlFileIterate(
	const char* fileName,
	char* buffer,
	size_t length,
	fiftyoneDegreesKeyValuePair* keyValuePairs,
	uint16_t collectionSize,
	void* state,
	void(*callback)(fiftyoneDegreesKeyValuePair*, uint16_t, void*));

#endif

/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2023 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

#ifndef FIFTYONE_DEGREES_JSON_H_INCLUDED
#define FIFTYONE_DEGREES_JSON_H_INCLUDED

 /**
  * @ingroup FiftyOneDegreesCommon
  * @defgroup FiftyOneDegreesJson JSON
  *
  * JSON methods
  *
  * ## Introduction
  * 
  * Contains common methods to create JSON documents, add properties, add 
  * either single or list values to properties. String values are escaped to
  * comply with the JSON specification.
  * 
  * ## Data Structures
  * 
  * A single data structure is used with members for a) the output buffer, and 
  * b) the reference data. 
  * 
  * The output buffer is represented as a pointer and a length. An additional
  * member is used to record the number of characters that would be needed to
  * complete the creation of a valid JSON response. This can be used by the 
  * caller to increase the buffer size if not big enough and call the related
  * methods a subsequent time. 
  * 
  * Reference data for the property being added, the values being added, and
  * a collection of strings is also provided.
  * 
  * @{
  */

#include <stdint.h>
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable: 5105) 
#include <windows.h>
#pragma warning (default: 5105) 
#pragma warning (pop)
#endif

/**
 * Structure used to populated a JSON string for all required properties and 
 * values. The implementation will always check to determine if sufficient 
 * characters remain in the buffer before adding characters. The charsAdded
 * field is always updated to reflect the number of characters that would be
 * needed in the buffer if all the values were to be written. This is needed
 * to determine when the buffer provided needs to be larger.
 */
typedef struct fiftyone_degrees_json {
	fiftyoneDegreesStringBuilder builder; /**< Output buffer */
	fiftyoneDegreesCollection* strings; /**< Collection of strings */
	fiftyoneDegreesProperty* property; /**< The property being added */
	fiftyoneDegreesList* values; /**< The values for the property */
	fiftyoneDegreesException* exception; /**< Exception */
	fiftyoneDegreesPropertyValueType storedPropertyType; /**< Stored type of the values for the property */
} fiftyoneDegreesJson;

/**
 * Writes the start of the JSON document characters to the buffer in json.
 * @param json data structure
 */
EXTERNAL void fiftyoneDegreesJsonDocumentStart(fiftyoneDegreesJson* json);

/**
 * Writes the end of the JSON document characters to the buffer in json.
 * @param json data structure
 */
EXTERNAL void fiftyoneDegreesJsonDocumentEnd(fiftyoneDegreesJson* json);

/**
 * Writes the start of the property in json->property to the buffer in json.
 * @param json data structure
 */
EXTERNAL void fiftyoneDegreesJsonPropertyStart(fiftyoneDegreesJson* json);

/**
 * Writes the end of the property in json->property to the buffer in json.
 * @param json data structure
 */
EXTERNAL void fiftyoneDegreesJsonPropertyEnd(fiftyoneDegreesJson* json);

/**
 * Writes the values in the json->values list to the buffer in json.
 * @param json data structure
 */
EXTERNAL void fiftyoneDegreesJsonPropertyValues(fiftyoneDegreesJson* json);

/**
 * Writes the a property separator to the buffer in json.
 * @param json data structure
 */
EXTERNAL void fiftyoneDegreesJsonPropertySeparator(fiftyoneDegreesJson* json);

/**
 * @}
 */

#endif
/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2025 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

#ifndef FIFTYONE_DEGREES_WKBTOT_H_INCLUDED
#define FIFTYONE_DEGREES_WKBTOT_H_INCLUDED

#include <stdbool.h>


/**
 * Used as a return type from the conversion routines to carry information about
 * the operation results to the caller, allows the caller to f.e. judge about the buffer utilization,
 * and whether the buffer was of sufficient size
 */
typedef struct fiftyone_degrees_transform_wkb_to_t_result {
	/**
	 * number of characters written or that would have been written to the buffer, reflects required buffer size
	 */
	size_t written;

	/**
	 * the caller should check this flag and reallocate the buffer to be of at least `written` size
	 * if this flag is set
	 */
	bool bufferTooSmall;
} fiftyoneDegreesWkbtotResult;

typedef enum {
	FIFTYONE_DEGREES_WKBToT_REDUCTION_NONE = 0, /**< Standard compliant */
	FIFTYONE_DEGREES_WKBToT_REDUCTION_SHORT = 1, /**< Some values reduced to int16_t */
} fiftyoneDegreesWkbtotReductionMode;

/**
 * Converts WKB geometry bytes to WKT string and writes it to string builder.
 * @param wellKnownBinary bytes of WKB geometry.
 * @param reductionMode type/value reduction applied to decrease WKB size.
 * @param decimalPlaces precision for numbers (places after the decimal dot).
 * @param builder string builder to write WKT into.
 * @param exception pointer to the exception struct.
 * @return How many bytes were written to the buffer and if it was too small.
 */
EXTERNAL void
fiftyoneDegreesWriteWkbAsWktToStringBuilder
(const unsigned char *wellKnownBinary,
 fiftyoneDegreesWkbtotReductionMode reductionMode,
 uint8_t decimalPlaces,
 fiftyoneDegreesStringBuilder *builder,
 fiftyoneDegreesException *exception);

/**
 * Converts WKB geometry bytes to WKT string written into provided buffer.
 * @param wellKnownBinary bytes of WKB geometry.
 * @param reductionMode type/value reduction applied to decrease WKB size.
 * @param buffer buffer to write WKT geometry into.
 * @param length length available in the buffer.
 * @param decimalPlaces precision for numbers (places after the decimal dot).
 * @param exception pointer to the exception struct.
 * @return How many bytes were written to the buffer and if it was too small.
 */
EXTERNAL fiftyoneDegreesWkbtotResult
fiftyoneDegreesConvertWkbToWkt
(const unsigned char *wellKnownBinary,
 fiftyoneDegreesWkbtotReductionMode reductionMode,
 char *buffer, size_t length,
 uint8_t decimalPlaces,
 fiftyoneDegreesException *exception);

#endif //FIFTYONE_DEGREES_WKBTOT_H_INCLUDED
/* *********************************************************************
 * This Original Work is copyright of 51 Degrees Mobile Experts Limited.
 * Copyright 2025 51 Degrees Mobile Experts Limited, Davidson House,
 * Forbury Square, Reading, Berkshire, United Kingdom RG1 3EU.
 *
 * This Original Work is licensed under the European Union Public Licence
 * (EUPL) v.1.2 and is subject to its terms as set out below.
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

#ifndef FIFTYONE_DEGREES_CONSTANTS_H
#define FIFTYONE_DEGREES_CONSTANTS_H

#include <stdint.h>

/**
 * Buffer length sufficient to hold any IP address.
 * Technically, 39 + 1(NUL), but with some trailing space just in case.
 */
static const uint8_t fiftyoneDegreesIpAddressStringMaxLength = 50;

/**
 * The length for the buffer most WKT strings are expected to fit into.
 */
#define FIFTYONE_DEGREES_REASONABLE_WKT_STRING_LENGTH 128

/**
 * Max. number of decimal places to be printed for a double.
 */
#define FIFTYONE_DEGREES_MAX_DOUBLE_DECIMAL_PLACES 15

#endif //FIFTYONE_DEGREES_CONSTANTS_H

/**
 * Macro used to support synonym implementation. Creates a typedef which 
 * removes the prefix `fiftyoneDegrees`.
 */
#define MAP_TYPE(t) typedef fiftyoneDegrees##t t; /**< Synonym for #fiftyoneDegrees##t type. */

/* <-- only one asterisk to avoid inclusion in documentation
 * Most mappings simply remove fiftyoneDegrees. However in some cases even 
 * shorter names make sense. These are provided before the general references
 * to MAP_TYPE.
 */

typedef fiftyoneDegreesCollectionItem Item; /**< Synonym for #fiftyoneDegreesCollectionItem type. */

/* <-- only one asterisk to avoid inclusion in documentation
 * General references to MAP_TYPE used to strip fiftyoneDegrees as a prefix
 * from types.
 */

MAP_TYPE(Exception);
MAP_TYPE(CollectionIterateMethod)
MAP_TYPE(CollectionMemory)
#ifndef FIFTYONE_DEGREES_MEMORY_ONLY
MAP_TYPE(CollectionFile)
MAP_TYPE(CollectionFileRead)
MAP_TYPE(CollectionCache)
MAP_TYPE(CollectionFileRead)
#endif
MAP_TYPE(FileHandle)
MAP_TYPE(FileOffset)
MAP_TYPE(FileOffsetUnsigned)
MAP_TYPE(CacheNode)
MAP_TYPE(FilePool)
MAP_TYPE(CollectionHeader)
MAP_TYPE(Data)
MAP_TYPE(Cache)
MAP_TYPE(MemoryReader)
MAP_TYPE(CacheShard)
MAP_TYPE(StatusCode)
MAP_TYPE(PropertiesRequired)
MAP_TYPE(DataSetBase)
MAP_TYPE(ResourceManager)
MAP_TYPE(EvidenceKeyValuePair)
MAP_TYPE(EvidencePrefixMap)
MAP_TYPE(EvidencePrefix)
MAP_TYPE(Headers)
MAP_TYPE(ResourceHandle)
MAP_TYPE(InterlockDoubleWidth)
MAP_TYPE(Pool)
MAP_TYPE(PoolResourceCreate)
MAP_TYPE(PoolResourceFree)
MAP_TYPE(PoolItem)
MAP_TYPE(PoolHead)
MAP_TYPE(PoolResourceSize)
MAP_TYPE(List)
MAP_TYPE(DataSetInitFromFileMethod)
MAP_TYPE(DataSetInitFromMemoryMethod)
MAP_TYPE(DataSetInitFromMemoryMethod)
MAP_TYPE(PropertiesGetMethod)
MAP_TYPE(HeadersGetMethod)
MAP_TYPE(DataSetInitFromFileMethod)
MAP_TYPE(String)
MAP_TYPE(VarLengthByteArray)
MAP_TYPE(StoredBinaryValue)
MAP_TYPE(Property)
MAP_TYPE(PropertyTypeRecord)
MAP_TYPE(Component)
MAP_TYPE(ComponentKeyValuePair)
MAP_TYPE(Value)
MAP_TYPE(Profile)
MAP_TYPE(OverrideProperty)
MAP_TYPE(OverridePropertyArray)
MAP_TYPE(OverrideValue)
MAP_TYPE(OverrideValueArray)
MAP_TYPE(EvidenceKeyValuePair)
MAP_TYPE(EvidenceKeyValuePairArray)
MAP_TYPE(PropertyAvailable)
MAP_TYPE(PropertyValueType)
MAP_TYPE(PropertiesAvailable)
MAP_TYPE(EvidencePropertyIndex)
MAP_TYPE(EvidenceProperties)
MAP_TYPE(Header)
MAP_TYPE(Headers)
MAP_TYPE(HeaderID)
MAP_TYPE(HeaderPtr)
MAP_TYPE(HeaderPtrs)
MAP_TYPE(OverridesFilterMethod)
MAP_TYPE(Mutex)
MAP_TYPE(Signal)
MAP_TYPE(TreeNode)
MAP_TYPE(TreeRoot)
MAP_TYPE(ProfileOffset)
MAP_TYPE(ProfileIterateMethod)
MAP_TYPE(Float)
MAP_TYPE(KeyValuePair)
MAP_TYPE(HeaderID)
MAP_TYPE(IndicesPropertyProfile)
MAP_TYPE(StringBuilder)
MAP_TYPE(Json)
MAP_TYPE(KeyValuePairArray)
MAP_TYPE(IpType)
MAP_TYPE(IpAddress)
MAP_TYPE(WkbtotResult)
MAP_TYPE(WkbtotReductionMode)

#define ProfileGetOffsetForProfileId fiftyoneDegreesProfileGetOffsetForProfileId /**< Synonym for #fiftyoneDegreesProfileGetOffsetForProfileId function. */
#define OverrideValuesAdd fiftyoneDegreesOverrideValuesAdd /**< Synonym for #fiftyoneDegreesOverrideValuesAdd function. */
#define ExceptionGetMessage fiftyoneDegreesExceptionGetMessage /**< Synonym for #fiftyoneDegreesExceptionGetMessage function. */
#define ProfileGetByProfileId fiftyoneDegreesProfileGetByProfileId /**< Synonym for #fiftyoneDegreesProfileGetByProfileId function. */
#define ProfileGetByProfileIdIndirect fiftyoneDegreesProfileGetByProfileIdIndirect /**< Synonym for #fiftyoneDegreesProfileGetByProfileIdIndirect function. */
#define ProfileGetByIndex fiftyoneDegreesProfileGetByIndex /**< Synonym for #fiftyoneDegreesProfileGetByIndex function. */
#define OverridesAdd fiftyoneDegreesOverridesAdd /**< Synonym for #fiftyoneDegreesOverridesAdd function. */
#define OverrideProfileIds fiftyoneDegreesOverrideProfileIds /**< Synonym for #fiftyoneDegreesOverrideProfileIds function. */
#define OverridePropertiesFree fiftyoneDegreesOverridePropertiesFree /**< Synonym for #fiftyoneDegreesOverridePropertiesFree function. */
#define ComponentInitList fiftyoneDegreesComponentInitList /**< Synonym for #fiftyoneDegreesComponentInitList function. */
#define ComponentGetHeaders fiftyoneDegreesComponentGetHeaders /**< Synonym for #fiftyoneDegreesComponentGetHeaders function. */
#define CollectionGetInteger32 fiftyoneDegreesCollectionGetInteger32 /**< Synonym for #fiftyoneDegreesCollectionGetInteger32 function. */
#define PropertyGet fiftyoneDegreesPropertyGet /**< Synonym for #fiftyoneDegreesPropertyGet function. */
#define ProfileIterateValuesForProperty fiftyoneDegreesProfileIterateValuesForProperty /**< Synonym for #fiftyoneDegreesProfileIterateValuesForProperty function. */
#define ProfileIterateValuesForPropertyWithIndex fiftyoneDegreesProfileIterateValuesForPropertyWithIndex /**< Synonym for #fiftyoneDegreesProfileIterateValuesForPropertyWithIndex function. */
#define ProfileIterateValueIndexes fiftyoneDegreesProfileIterateValueIndexes /**< Synonym for #fiftyoneDegreesProfileIterateValueIndexes function. */
#define ProfileIterateProfilesForPropertyAndValue fiftyoneDegreesProfileIterateProfilesForPropertyAndValue /**< Synonym for #fiftyoneDegreesProfileIterateProfilesForPropertyAndValue function. */
#define ProfileIterateProfilesForPropertyWithTypeAndValue fiftyoneDegreesProfileIterateProfilesForPropertyWithTypeAndValue /**< Synonym for #fiftyoneDegreesProfileIterateProfilesForPropertyWithTypeAndValue function. */
#define ProfileIterateProfilesForPropertyWithTypeAndValueAndOffsetExtractor fiftyoneDegreesProfileIterateProfilesForPropertyWithTypeAndValueAndOffsetExtractor /**< Synonym for #fiftyoneDegreesProfileIterateProfilesForPropertyWithTypeAndValueAndOffsetExtractor function. */
#define ProfileOffsetAsPureOffset fiftyoneDegreesProfileOffsetAsPureOffset /**< Synonym for #fiftyoneDegreesProfileOffsetAsPureOffset function. */
#define ProfileOffsetToPureOffset fiftyoneDegreesProfileOffsetToPureOffset /**< Synonym for #fiftyoneDegreesProfileOffsetToPureOffset function. */
#define PropertiesGetPropertyIndexFromName fiftyoneDegreesPropertiesGetPropertyIndexFromName /**< Synonym for #fiftyoneDegreesPropertiesGetPropertyIndexFromName function. */
#define TreeIterate fiftyoneDegreesTreeIterateNodes /**< Synonym for #fiftyoneDegreesTreeIterateNodes function. */
#define TreeCount fiftyoneDegreesTreeCount /**< Synonym for #fiftyoneDegreesTreeCount function. */
#define TreeDelete fiftyoneDegreesTreeDelete /**< Synonym for #fiftyoneDegreesTreeDelete function. */
#define TreeInsert fiftyoneDegreesTreeInsert /**< Synonym for #fiftyoneDegreesTreeInsert function. */
#define TreeFind fiftyoneDegreesTreeFind /**< Synonym for #fiftyoneDegreesTreeFind function. */
#define TreeNodeInit fiftyoneDegreesTreeNodeInit /**< Synonym for #fiftyoneDegreesTreeNodeInit function. */
#define TreeNodeRemove fiftyoneDegreesTreeNodeRemove /**< Synonym for #fiftyoneDegreesTreeNodeRemove function. */
#define TreeRootInit fiftyoneDegreesTreeRootInit /**< Synonym for #fiftyoneDegreesTreeRootInit function. */
#define OverridesGetOverridingRequiredPropertyIndex fiftyoneDegreesOverridesGetOverridingRequiredPropertyIndex /**< Synonym for #fiftyoneDegreesOverridesGetOverridingRequiredPropertyIndex function. */
#define OverridePropertiesCreate fiftyoneDegreesOverridePropertiesCreate /**< Synonym for #fiftyoneDegreesOverridePropertiesCreate function. */
#define EvidenceCreate fiftyoneDegreesEvidenceCreate /**< Synonym for #fiftyoneDegreesEvidenceCreate function. */
#define EvidenceFree fiftyoneDegreesEvidenceFree /**< Synonym for #fiftyoneDegreesEvidenceFree function. */
#define OverridesGetOverridingRequiredPropertyIndex fiftyoneDegreesOverridesGetOverridingRequiredPropertyIndex /**< Synonym for #fiftyoneDegreesOverridesGetOverridingRequiredPropertyIndex function. */
#define StringCompareLength fiftyoneDegreesStringCompareLength /**< Synonym for #fiftyoneDegreesStringCompareLength function. */
#define StringCompare fiftyoneDegreesStringCompare /**< Synonym for #fiftyoneDegreesStringCompare function. */
#define StringSubString fiftyoneDegreesStringSubString /**< Synonym for #fiftyoneDegreesSubString function. */
#define OverridesExtractFromEvidence fiftyoneDegreesOverridesExtractFromEvidence /**< Synonym for #fiftyoneDegreesOverridesExtractFromEvidence function. */
#define EvidenceIterate fiftyoneDegreesEvidenceIterate /**< Synonym for #fiftyoneDegreesEvidenceIterate function. */
#define EvidenceIterateForHeaders fiftyoneDegreesEvidenceIterateForHeaders /**< Synonym for #fiftyoneDegreesEvidenceIterateForHeaders function. */
#define CacheRelease fiftyoneDegreesCacheRelease /**< Synonym for #fiftyoneDegreesCacheRelease function. */
#define DataReset fiftyoneDegreesDataReset /**< Synonym for #fiftyoneDegreesDataReset function. */
#define CacheFree fiftyoneDegreesCacheFree /**< Synonym for #fiftyoneDegreesCacheFree function. */
#define FileHandleGet fiftyoneDegreesFileHandleGet /**< Synonym for #fiftyoneDegreesFileHandleGet function. */
#define FileHandleRelease fiftyoneDegreesFileHandleRelease /**< Synonym for #fiftyoneDegreesFileHandleRelease function. */
#define DataMalloc fiftyoneDegreesDataMalloc /**< Synonym for #fiftyoneDegreesDataMalloc function. */
#define CacheGet fiftyoneDegreesCacheGet /**< Synonym for #fiftyoneDegreesCacheGet function. */
#define CacheCreate fiftyoneDegreesCacheCreate /**< Synonym for #fiftyoneDegreesCacheCreate function. */
#define MemoryAdvance fiftyoneDegreesMemoryAdvance /**< Synonym for #fiftyoneDegreesMemoryAdvance function. */
#define MemoryTrackingReset fiftyoneDegreesMemoryTrackingReset /**< Synonym for #fiftyoneDegreesMemoryTrackingReset function. */
#define MemoryTrackingGetMax fiftyoneDegreesMemoryTrackingGetMax /**< Synonym for #fiftyoneDegreesMemoryTrackingGetMax function. */
#define MemoryTrackingGetAllocated fiftyoneDegreesMemoryTrackingGetAllocated /**< Synonym for #fiftyoneDegreesMemoryTrackingGetAllocated function. */
#define SetUpMemoryTracking fiftyoneDegreesSetUpMemoryTracking /**< Synonym for #fiftyoneDegreesSetUpMemoryTracking function. */
#define UnsetMemoryTracking fiftyoneDegreesUnsetMemoryTracking /**< Synonym for #fiftyoneDegreesUnsetMemoryTracking function. */
#define Malloc fiftyoneDegreesMalloc /**< Synonym for #fiftyoneDegreesMalloc function. */
#define MallocAligned fiftyoneDegreesMallocAligned /**< Synonym for #fiftyoneDegreesMallocAligned function. */
#define Free fiftyoneDegreesFree /**< Synonym for #fiftyoneDegreesFree function. */
#define FreeAligned fiftyoneDegreesFreeAligned /**< Synonym for #fiftyoneDegreesFreeAligned function. */
#define ResourceHandleIncUse fiftyoneDegreesResourceHandleIncUse /**< Synonym for #fiftyoneDegreesResourceHandleIncUse function. */
#define PropertiesDefault fiftyoneDegreesPropertiesDefault /**< Synonym for #fiftyoneDegreesPropertiesDefault function. */
#define ListGetAsString fiftyoneDegreesListGetAsString /**< Synonym for #fiftyoneDegreesListGetAsString function. */
#define ListAdd fiftyoneDegreesListAdd /**< Synonym for #fiftyoneDegreesListAdd function. */
#define ListInit fiftyoneDegreesListInit /**< Synonym for #fiftyoneDegreesListInit function. */
#define ListFree fiftyoneDegreesListFree /**< Synonym for #fiftyoneDegreesListFree function. */
#define FileGetExistingTempFile fiftyoneDegreesFileGetExistingTempFile /**< Synonym for #fiftyoneDegreesFileGetExistingTempFile function. */
#define FileDeleteUnusedTempFiles fiftyoneDegreesFileDeleteUnusedTempFiles /**< Synonym for #fiftyoneDegreesFileDeleteUnusedTempFiles function. */
#define FileCreateTempFile fiftyoneDegreesFileCreateTempFile /**< Synonym for #fiftyoneDegreesFileCreateTempFile function. */
#define FileNewTempFile fiftyoneDegreesFileNewTempFile /**< Synonym for #fiftyoneDegreesFileNewTempFile function. */
#define HeadersFree fiftyoneDegreesHeadersFree /**< Synonym for #fiftyoneDegreesHeadersFree function. */
#define PropertiesFree fiftyoneDegreesPropertiesFree /**< Synonym for #fiftyoneDegreesPropertiesFree function. */
#define FilePoolRelease fiftyoneDegreesFilePoolRelease /**< Synonym for #fiftyoneDegreesFilePoolRelease function. */
#define FileSeek fiftyoneDegreesFileSeek /**< Synonym for #fiftyoneDegreesFileSeek function. */
#define FileTell fiftyoneDegreesFileTell /**< Synonym for #fiftyoneDegreesFileTell function. */
#define FileDelete fiftyoneDegreesFileDelete /**< Synonym for #fiftyoneDegreesFileDelete function. */
#define FilePoolReset fiftyoneDegreesFilePoolReset /**< Synonym for #fiftyoneDegreesFilePoolReset function. */
#define PropertiesCreate fiftyoneDegreesPropertiesCreate /**< Synonym for #fiftyoneDegreesPropertiesCreate function. */
#define HeadersIsPseudo fiftyoneDegreesHeadersIsPseudo /**< Synonym for #fiftyoneDegreesHeadersIsPseudo function. */
#define HeadersCreate fiftyoneDegreesHeadersCreate /**< Synonym for #fiftyoneDegreesHeadersCreate function. */
#define HeadersGetHeaderFromUniqueId fiftyoneDegreesHeadersGetHeaderFromUniqueId /**< Synonym for #fiftyoneDegreesHeadersGetHeaderFromUniqueId function. */
#define PseudoHeadersAddEvidence fiftyoneDegreesPseudoHeadersAddEvidence /**< Synonym for fiftyoneDegreesPseudoHeadersAddEvidence */
#define PseudoHeadersRemoveEvidence fiftyoneDegreesPseudoHeadersRemoveEvidence /**< Synonym for fiftyoneDegreesPseudoHeadersRemoveEvidence */
#define FileReadToByteArray fiftyoneDegreesFileReadToByteArray /**< Synonym for #fiftyoneDegreesFileReadToByteArray function. */
#define ResourceHandleDecUse fiftyoneDegreesResourceHandleDecUse /**< Synonym for #fiftyoneDegreesResourceHandleDecUse function. */
#define ResourceReplace fiftyoneDegreesResourceReplace /**< Synonym for #fiftyoneDegreesResourceReplace function. */
#define StatusGetMessage fiftyoneDegreesStatusGetMessage /**< Synonym for #fiftyoneDegreesStatusGetMessage function. */
#define FileOpen fiftyoneDegreesFileOpen /**< Synonym for #fiftyoneDegreesFileOpen function. */
#define PoolInit fiftyoneDegreesPoolInit /**< Synonym for #fiftyoneDegreesPoolInit function. */
#define PoolItemGet fiftyoneDegreesPoolItemGet /**< Synonym for #fiftyoneDegreesPoolItemGet function. */
#define PoolItemRelease fiftyoneDegreesPoolItemRelease /**< Synonym for #fiftyoneDegreesPoolItemRelease function. */
#define PoolFree fiftyoneDegreesPoolFree /**< Synonym for #fiftyoneDegreesPoolFree function. */
#define PoolReset fiftyoneDegreesPoolReset /**< Synonym for #fiftyoneDegreesPoolReset function. */
#define FileGetSize fiftyoneDegreesFileGetSize /**< Synonym for #fiftyoneDegreesFileGetSize function. */
#define FileCopy fiftyoneDegreesFileCopy /**< Synonym for #fiftyoneDegreesFileCopy function. */
#define MemoryTrackingMalloc fiftyoneDegreesMemoryTrackingMalloc /**< Synonym for #fiftyoneDegreesMemoryTrackingMalloc function. */
#define MemoryTrackingMallocAligned fiftyoneDegreesMemoryTrackingMallocAligned /**< Synonym for #fiftyoneDegreesMemoryTrackingMallocAligned function. */
#define MemoryTrackingFree fiftyoneDegreesMemoryTrackingFree /**< Synonym for #fiftyoneDegreesMemoryTrackingFree function. */
#define MemoryTrackingFreeAligned fiftyoneDegreesMemoryTrackingFreeAligned /**< Synonym for #fiftyoneDegreesMemoryTrackingFreeAligned function. */
#define MemoryStandardMalloc fiftyoneDegreesMemoryStandardMalloc /**< Synonym for #fiftyoneDegreesMemoryStandardMalloc function. */
#define MemoryStandardMallocAligned fiftyoneDegreesMemoryStandardMallocAligned /**< Synonym for #fiftyoneDegreesMemoryStandardMallocAligned function. */
#define MemoryStandardFree fiftyoneDegreesMemoryStandardFree /**< Synonym for #fiftyoneDegreesMemoryStandardFree function. */
#define MemoryStandardFreeAligned fiftyoneDegreesMemoryStandardFreeAligned /**< Synonym for #fiftyoneDegreesMemoryStandardFreeAligned function. */
#define ResourceManagerFree fiftyoneDegreesResourceManagerFree /**< Synonym for #fiftyoneDegreesResourceManagerFree function. */
#define StringGet fiftyoneDegreesStringGet /**< Synonym for #fiftyoneDegreesStringGet function. */
#define StoredBinaryValueGet fiftyoneDegreesStoredBinaryValueGet /**< Synonym for #fiftyoneDegreesStoredBinaryValueGet function. */
#define StoredBinaryValueRead fiftyoneDegreesStoredBinaryValueRead /**< Synonym for #fiftyoneDegreesStoredBinaryValueRead function. */
#define StoredBinaryValueCompareWithString fiftyoneDegreesStoredBinaryValueCompareWithString /**< Synonym for #fiftyoneDegreesStoredBinaryValueCompareWithString function. */
#define StoredBinaryValueToIntOrDefault fiftyoneDegreesStoredBinaryValueToIntOrDefault /**< Synonym for #fiftyoneDegreesStoredBinaryValueToIntOrDefault function. */
#define StoredBinaryValueToDoubleOrDefault fiftyoneDegreesStoredBinaryValueToDoubleOrDefault /**< Synonym for #fiftyoneDegreesStoredBinaryValueToDoubleOrDefault function. */
#define StoredBinaryValueToBoolOrDefault fiftyoneDegreesStoredBinaryValueToBoolOrDefault /**< Synonym for #fiftyoneDegreesStoredBinaryValueToBoolOrDefault function. */
#define EvidenceFree fiftyoneDegreesEvidenceFree /**< Synonym for #fiftyoneDegreesEvidenceFree function. */
#define EvidenceCreate fiftyoneDegreesEvidenceCreate /**< Synonym for #fiftyoneDegreesEvidenceCreate function. */
#define EvidenceMapPrefix fiftyoneDegreesEvidenceMapPrefix /**< Synonym for #fiftyoneDegreesEvidenceMapPrefix function. */
#define EvidencePrefixString fiftyoneDegreesEvidencePrefixString /**< Synonym for #fiftyoneDegreesEvidencePrefixString function. */
#define EvidenceAddPair fiftyoneDegreesEvidenceAddPair /**< Synonym for #fiftyoneDegreesEvidenceAddPair function. */
#define EvidenceAddString fiftyoneDegreesEvidenceAddString /**< Synonym for #fiftyoneDegreesEvidenceAddString function. */
#define PropertiesGetRequiredPropertyIndexFromName fiftyoneDegreesPropertiesGetRequiredPropertyIndexFromName /**< Synonym for #fiftyoneDegreesPropertiesGetRequiredPropertyIndexFromName function. */
#define PropertiesGetNameFromRequiredIndex fiftyoneDegreesPropertiesGetNameFromRequiredIndex /**< Synonym for #fiftyoneDegreesPropertiesGetNameFromRequiredIndex function. */
#define PropertiesIsSetHeaderAvailable fiftyoneDegreesPropertiesIsSetHeaderAvailable /**< Synonym for #fiftyoneDegreesPropertiesIsSetHeaderAvailable */
#define CollectionHeaderFromFile fiftyoneDegreesCollectionHeaderFromFile /**< Synonym for #fiftyoneDegreesCollectionHeaderFromFile function. */
#define CollectionCreateFromFile fiftyoneDegreesCollectionCreateFromFile /**< Synonym for #fiftyoneDegreesCollectionCreateFromFile function. */
#define CollectionHeaderFromMemory fiftyoneDegreesCollectionHeaderFromMemory /**< Synonym for #fiftyoneDegreesCollectionHeaderFromMemory function. */
#define CollectionCreateFromMemory fiftyoneDegreesCollectionCreateFromMemory /**< Synonym for #fiftyoneDegreesCollectionCreateFromMemory function. */
#define CollectionGetCount fiftyoneDegreesCollectionGetCount /**< Synonym for #fiftyoneDegreesCollectionGetCount function. */
#define FileGetPath fiftyoneDegreesFileGetPath /**< Synonym for #fiftyoneDegreesFileGetPath function. */
#define FileGetFileName fiftyoneDegreesFileGetFileName /**< Synonym for #fiftyoneDegreesFileGetFileName function. */
#define ThreadingGetIsThreadSafe fiftyoneDegreesThreadingGetIsThreadSafe /**< Synonym for #fiftyoneDegreesThreadingGetIsThreadSafe function. */
#define CollectionReadFilePosition fiftyoneDegreesCollectionReadFilePosition /**< Synonym for #fiftyoneDegreesCollectionReadFilePosition function. */
#define CollectionReadFileFixed fiftyoneDegreesCollectionReadFileFixed /**< Synonym for #fiftyoneDegreesCollectionReadFileFixed function. */
#define CollectionGetIsMemoryOnly fiftyoneDegreesCollectionGetIsMemoryOnly /**< Synonym for #fiftyoneDegreesCollectionGetIsMemoryOnly function. */
#define HeaderGetIndex fiftyoneDegreesHeaderGetIndex /**< Synonym for #fiftyoneDegreesHeaderGetIndex function. */
#define FileWrite fiftyoneDegreesFileWrite /**< Synonym for #fiftyoneDegreesFileWrite function. */
#define FilePoolInit fiftyoneDegreesFilePoolInit /**< Synonym for #fiftyoneDegreesFilePoolInit function. */
#define FileCreateDirectory fiftyoneDegreesFileCreateDirectory /**< Synonym for #fiftyoneDegreesFileCreateDirectory function. */
#define TextFileIterateWithLimit fiftyoneDegreesTextFileIterateWithLimit /**< Synonym for #fiftyoneDegreesTextFileIterateWithLimit function. */
#define TextFileIterate fiftyoneDegreesTextFileIterate /**< Synonym for #fiftyoneDegreesTextFileIterate function. */
#define ResourceManagerInit fiftyoneDegreesResourceManagerInit /**< Synonym for #fiftyoneDegreesResourceManagerInit function. */
#define PropertiesGetPropertyIndexFromRequiredIndex fiftyoneDegreesPropertiesGetPropertyIndexFromRequiredIndex /**< Synonym for #fiftyoneDegreesPropertiesGetPropertyIndexFromRequiredIndex function. */
#define DataSetRelease fiftyoneDegreesDataSetRelease /**< Synonym for #fiftyoneDegreesDataSetRelease function. */
#define DataSetReset fiftyoneDegreesDataSetReset /**< Synonym for #fiftyoneDegreesDataSetReset function. */
#define DataSetInitProperties fiftyoneDegreesDataSetInitProperties /**< Synonym for #fiftyoneDegreesDataSetInitProperties function. */
#define DataSetInitHeaders fiftyoneDegreesDataSetInitHeaders /**< Synonym for #fiftyoneDegreesDataSetInitHeaders function. */
#define DataSetInitFromFile fiftyoneDegreesDataSetInitFromFile /**< Synonym for #fiftyoneDegreesDataSetInitFromFile function. */
#define DataSetInitInMemory fiftyoneDegreesDataSetInitInMemory /**< Synonym for #fiftyoneDegreesDataSetInitInMemory function. */
#define DataSetGet fiftyoneDegreesDataSetGet /**< Synonym for #fiftyoneDegreesDataSetGet function. */
#define DataSetFree fiftyoneDegreesDataSetFree /**< Synonym for #fiftyoneDegreesDataSetFree function. */
#define DataSetReloadManagerFromMemory fiftyoneDegreesDataSetReloadManagerFromMemory /**< Synonym for #fiftyoneDegreesDataSetReloadManagerFromMemory function. */
#define DataSetReloadManagerFromFile fiftyoneDegreesDataSetReloadManagerFromFile /**< Synonym for #fiftyoneDegreesDataSetReloadManagerFromFile function. */
#define HeadersIsHttp fiftyoneDegreesHeadersIsHttp /**< Synonym for #fiftyoneDegreesHeadersIsHttp function. */
#define ListReset fiftyoneDegreesListReset /**< Synonym for #fiftyoneDegreesListReset function. */
#define ListRelease fiftyoneDegreesListRelease /**< Synonym for #fiftyoneDegreesListRelease function. */
#define ValueGetContent fiftyoneDegreesValueGetContent /**< Synonym for #fiftyoneDegreesValueGetContent function. */
#define ValueGetName fiftyoneDegreesValueGetName /**< Synonym for #fiftyoneDegreesValueGetName function. */
#define ValueGetByName fiftyoneDegreesValueGetByName /**< Synonym for #fiftyoneDegreesValueGetByName function. */
#define ValueGetByNameAndType fiftyoneDegreesValueGetByNameAndType /**< Synonym for #fiftyoneDegreesValueGetByNameAndType function. */
#define ValueGetIndexByName fiftyoneDegreesValueGetIndexByName /**< Synonym for #fiftyoneDegreesValueGetIndexByName function. */
#define ValueGetIndexByNameAndType fiftyoneDegreesValueGetIndexByNameAndType /**< Synonym for #fiftyoneDegreesValueGetIndexByNameAndType function. */
#define ValueGet fiftyoneDegreesValueGet /**< Synonym for #fiftyoneDegreesValueGet function. */
#define CollectionBinarySearch fiftyoneDegreesCollectionBinarySearch /**< Synonym for #fiftyoneDegreesCollectionBinarySearch function. */
#define PropertyGetName fiftyoneDegreesPropertyGetName /**< Synonym for #fiftyoneDegreesPropertyGetName function. */
#define PropertyGetStoredType fiftyoneDegreesPropertyGetStoredType /**< Synonym for #fiftyoneDegreesPropertyGetStoredType function. */
#define PropertyGetStoredTypeByIndex fiftyoneDegreesPropertyGetStoredTypeByIndex /**< Synonym for #fiftyoneDegreesPropertyGetStoredTypeByIndex function. */
#define CollectionReadFileVariable fiftyoneDegreesCollectionReadFileVariable /**< Synonym for #fiftyoneDegreesCollectionReadFileVariable function. */
#define PropertyGetByName fiftyoneDegreesPropertyGetByName /**< Synonym for #fiftyoneDegreesPropertyGetByName function. */
#define ComponentGetKeyValuePair fiftyoneDegreesComponentGetKeyValuePair /**< Synonym for #fiftyoneDegreesComponentGetKeyValuePair function., */
#define PropertyGetValueType fiftyoneDegreesPropertyGetValueType /**< Synonym for #fiftyoneDegreesPropertyGetValueType function. */
#define EvidencePropertiesGetMethod fiftyoneDegreesEvidencePropertiesGetMethod /**< Synonym for #fiftyoneDegreesEvidencePropertiesGetMethod function. */
#define IpiGetCoordinate fiftyoneDegreesIpiGetCoordinate /**< Synonym for #fiftyoneDegreesIpiGetCoordinate function. */
#define SignalCreate fiftyoneDegreesSignalCreate /**< Synonym for #fiftyoneDegreesSignalCreate function. */
#define SignalClose fiftyoneDegreesSignalClose /**< Synonym for #fiftyoneDegreesSignalClose function. */
#define SignalSet fiftyoneDegreesSignalSet /**< Synonym for #fiftyoneDegreesSignalSet function. */
#define SignalWait fiftyoneDegreesSignalWait /**< Synonym for #fiftyoneDegreesSignalWait function. */
#define IntToBool fiftyoneDegreesIntToBool /**< Synonym for #fiftyoneDegreesIntToBool function. */
#define BoolToInt fiftyoneDegreesBoolToInt /**< Synonym for #fiftyoneDegreesBoolToInt function. */
#define ProcessGetId fiftyoneDegreesProcessGetId /**< Synonym for fiftyoneDegreesProcessGetId */
#define YamlFileIterate fiftyoneDegreesYamlFileIterate /**< Synonym for fiftyoneDegreesYamlFileIterate */
#define YamlFileIterateWithLimit fiftyoneDegreesYamlFileIterateWithLimit /**< Synonym for fiftyoneDegreesYamlFileIterateWithLimit */
#define IndicesPropertyProfileCreate fiftyoneDegreesIndicesPropertyProfileCreate /**< Synonym for fiftyoneDegreesIndicesPropertyProfileCreate */
#define IndicesPropertyProfileFree fiftyoneDegreesIndicesPropertyProfileFree /**< Synonym for fiftyoneDegreesIndicesPropertyProfileFree */
#define IndicesPropertyProfileLookup fiftyoneDegreesIndicesPropertyProfileLookup /**< Synonym for fiftyoneDegreesIndicesPropertyProfileLookup */
#define JsonDocumentStart fiftyoneDegreesJsonDocumentStart /**< Synonym for fiftyoneDegreesJsonDocumentStart */
#define JsonDocumentEnd fiftyoneDegreesJsonDocumentEnd /**< Synonym for fiftyoneDegreesJsonDocumentEnd */
#define JsonPropertyStart fiftyoneDegreesJsonPropertyStart /**< Synonym for fiftyoneDegreesJsonPropertyStart */
#define JsonPropertyEnd fiftyoneDegreesJsonPropertyEnd /**< Synonym for fiftyoneDegreesJsonPropertyEnd */
#define JsonPropertyValues fiftyoneDegreesJsonPropertyValues /**< Synonym for fiftyoneDegreesJsonPropertyValues */
#define JsonPropertySeparator fiftyoneDegreesJsonPropertySeparator /**< Synonym for fiftyoneDegreesJsonPropertySeparator */
#define StringBuilderInit fiftyoneDegreesStringBuilderInit /**< Synonym for fiftyoneDegreesStringBuilderInit */
#define StringBuilderAddChar fiftyoneDegreesStringBuilderAddChar /**< Synonym for fiftyoneDegreesStringBuilderAddChar */
#define StringBuilderAddInteger fiftyoneDegreesStringBuilderAddInteger /**< Synonym for fiftyoneDegreesStringBuilderAddInteger */
#define StringBuilderAddDouble fiftyoneDegreesStringBuilderAddDouble /**< Synonym for fiftyoneDegreesStringBuilderAddDouble */
#define StringBuilderAddChars fiftyoneDegreesStringBuilderAddChars /**< Synonym for fiftyoneDegreesStringBuilderAddChars */
#define StringBuilderAddIpAddress fiftyoneDegreesStringBuilderAddIpAddress /**< Synonym for fiftyoneDegreesStringBuilderAddIpAddress */
#define StringBuilderAddStringValue fiftyoneDegreesStringBuilderAddStringValue /**< Synonym for fiftyoneDegreesStringBuilderAddStringValue */
#define StringBuilderComplete fiftyoneDegreesStringBuilderComplete /**< Synonym for fiftyoneDegreesStringBuilderComplete */
#define EvidenceIterateMethod fiftyoneDegreesEvidenceIterateMethod /**< Synonym for fiftyoneDegreesEvidenceIterateMethod */
#define OverrideHasValueForRequiredPropertyIndex fiftyoneDegreesOverrideHasValueForRequiredPropertyIndex /**< Synonym for fiftyoneDegreesOverrideHasValueForRequiredPropertyIndex */
#define IpAddressParse fiftyoneDegreesIpAddressParse /**< Synonym for fiftyoneDegreesIpAddressParse */
#define IpAddressesCompare fiftyoneDegreesIpAddressesCompare /**< Synonym for fiftyoneDegreesIpAddressesCompare */
#define ConvertWkbToWkt fiftyoneDegreesConvertWkbToWkt /**< Synonym for fiftyoneDegreesConvertWkbToWkt */
#define WriteWkbAsWktToStringBuilder fiftyoneDegreesWriteWkbAsWktToStringBuilder /**< Synonym for fiftyoneDegreesWriteWkbAsWktToStringBuilder */

/* <-- only one asterisk to avoid inclusion in documentation
 * Shortened constants.
 */

#define IpAddressStringMaxLength fiftyoneDegreesIpAddressStringMaxLength /**< Synonym for #fiftyoneDegreesIpAddressStringMaxLength constant. */
#define REASONABLE_WKT_STRING_LENGTH FIFTYONE_DEGREES_REASONABLE_WKT_STRING_LENGTH /**< Synonym for #FIFTYONE_DEGREES_REASONABLE_WKT_STRING_LENGTH constant macro. */
#define MAX_DOUBLE_DECIMAL_PLACES FIFTYONE_DEGREES_MAX_DOUBLE_DECIMAL_PLACES /**< Synonym for #FIFTYONE_DEGREES_MAX_DOUBLE_DECIMAL_PLACES constant macro. */

/* <-- only one asterisk to avoid inclusion in documentation
 * Shortened macros.
 */

#define EXCEPTION_SET FIFTYONE_DEGREES_EXCEPTION_SET /**< Synonym for #FIFTYONE_DEGREES_EXCEPTION_SET macro. */
#define EXCEPTION_CLEAR FIFTYONE_DEGREES_EXCEPTION_CLEAR /**< Synonym for #FIFTYONE_DEGREES_EXCEPTION_CLEAR macro. */
#define EXCEPTION_CREATE FIFTYONE_DEGREES_EXCEPTION_CREATE /**< Synonym for #FIFTYONE_DEGREES_EXCEPTION_CREATE macro. */
#define EXCEPTION_OKAY FIFTYONE_DEGREES_EXCEPTION_OKAY /**< Synonym for #FIFTYONE_DEGREES_EXCEPTION_OKAY macro. */
#define EXCEPTION_FAILED FIFTYONE_DEGREES_EXCEPTION_FAILED /**< Synonym for #FIFTYONE_DEGREES_EXCEPTION_FAILED macro. */
#define EXCEPTION_THROW FIFTYONE_DEGREES_EXCEPTION_THROW /**< Synonym for #FIFTYONE_DEGREES_EXCEPTION_THROW macro. */
#define EXCEPTION_CHECK FIFTYONE_DEGREES_EXCEPTION_CHECK /**< Synonym for #FIFTYONE_DEGREES_EXCEPTION_CHECK macro. */
#define STRING FIFTYONE_DEGREES_STRING /**< Synonym for #FIFTYONE_DEGREES_STRING macro. */
#define COLLECTION_RELEASE FIFTYONE_DEGREES_COLLECTION_RELEASE /**< Synonym for #FIFTYONE_DEGREES_COLLECTION_RELEASE macro. */
#define FILE_MAX_PATH FIFTYONE_DEGREES_FILE_MAX_PATH /**< Synonym for #FIFTYONE_DEGREES_FILE_MAX_PATH macro. */
#define THREAD_CREATE FIFTYONE_DEGREES_THREAD_CREATE /**< Synonym for #FIFTYONE_DEGREES_THREAD_CREATE macro. */
#define THREAD_CLOSE FIFTYONE_DEGREES_THREAD_CLOSE /**< Synonym for #FIFTYONE_DEGREES_THREAD_CLOSE macro. */
#define THREAD_EXIT FIFTYONE_DEGREES_THREAD_EXIT /**< Synonym for #FIFTYONE_DEGREES_THREAD_EXIT macro. */
#define THREAD_JOIN FIFTYONE_DEGREES_THREAD_JOIN /**< Synonym for #FIFTYONE_DEGREES_THREAD_JOIN macro. */
#define THREAD_ROUTINE FIFTYONE_DEGREES_THREAD_ROUTINE /**< Synonym for #FIFTYONE_DEGREES_THREAD_ROUTINE macro. */
#define MUTEX_CREATE FIFTYONE_DEGREES_MUTEX_CREATE /**< Synonym for #FIFTYONE_DEGREES_MUTEX_CREATE macro. */
#define MUTEX_CLOSE FIFTYONE_DEGREES_MUTEX_CLOSE /**< Synonym for #FIFTYONE_DEGREES_MUTEX_CLOSE macro. */
#define MUTEX_LOCK FIFTYONE_DEGREES_MUTEX_LOCK /**< Synonym for #FIFTYONE_DEGREES_MUTEX_LOCK macro. */
#define MUTEX_UNLOCK FIFTYONE_DEGREES_MUTEX_UNLOCK /**< Synonym for #FIFTYONE_DEGREES_MUTEX_UNLOCK macro. */
#define MUTEX_VALID FIFTYONE_DEGREES_MUTEX_VALID /**< Synonym for #FIFTYONE_DEGREES_MUTEX_VALID macro. */
#define THREAD FIFTYONE_DEGREES_THREAD /**< Synonym for #FIFTYONE_DEGREES_THREAD macro. */
#define INTERLOCK_INC FIFTYONE_DEGREES_INTERLOCK_INC /**< Synonym for #FIFTYONE_DEGREES_INTERLOCK_INC macro. */
#define INTERLOCK_DEC FIFTYONE_DEGREES_INTERLOCK_DEC /**< Synonym for #FIFTYONE_DEGREES_INTERLOCK_DEC macro. */
#define INTERLOCK_EXCHANGE FIFTYONE_DEGREES_INTERLOCK_EXCHANGE /**< Synonym for #FIFTYONE_DEGREES_INTERLOCK_EXCHANGE macro. */
#define INTERLOCK_EXCHANGE_64 FIFTYONE_DEGREES_INTERLOCK_EXCHANGE_64 /**< Synonym for #FIFTYONE_DEGREES_INTERLOCK_EXCHANGE_64 macro. */
#define INTERLOCK_EXCHANGE_PTR FIFTYONE_DEGREES_INTERLOCK_EXCHANGE_PTR /**< Synonym for #FIFTYONE_DEGREES_INTERLOCK_EXCHANGE_PTR macro. */
#define INTERLOCK_EXCHANGE_PTR_DW FIFTYONE_DEGREES_INTERLOCK_EXCHANGE_PTR_DW /**< Synonym for #FIFTYONE_DEGREES_INTERLOCK_EXCHANGE_PTR_DW macro. */
#define FLOAT_TO_NATIVE FIFTYONE_DEGREES_FLOAT_TO_NATIVE /**< Synonym for #FIFTYONE_DEGREES_FLOAT_TO_NATIVE macro. */
#define NATIVE_TO_FLOAT FIFTYONE_DEGREES_NATIVE_TO_FLOAT /**< Synonym for #FIFTYONE_DEGREES_NATIVE_TO_FLOAT macro. */
#define FLOAT_IS_EQUAL FIFTYONE_DEGREES_FLOAT_IS_EQUAL /**< Synonym for #FIFTYONE_DEGREES_FLOAT_IS_EQUAL macro. */
#define PSEUDO_HEADER_SEP FIFTYONE_DEGREES_PSEUDO_HEADER_SEP /**< Synonym for #FIFTYONE_DEGREES_PSEUDO_HEADER_SEP macro. */
#define REASONABLE_WKT_STRING_LENGTH FIFTYONE_DEGREES_REASONABLE_WKT_STRING_LENGTH /**< Synonym for #FIFTYONE_DEGREES_REASONABLE_WKT_STRING_LENGTH macro. */

/* <-- only one asterisk to avoid inclusion in documentation
 * Shorten status codes.
 */

#define SUCCESS FIFTYONE_DEGREES_STATUS_SUCCESS /**< Synonym for #FIFTYONE_DEGREES_STATUS_SUCCESS status code. */
#define INSUFFICIENT_MEMORY FIFTYONE_DEGREES_STATUS_INSUFFICIENT_MEMORY /**< Synonym for #FIFTYONE_DEGREES_STATUS_INSUFFICIENT_MEMORY status code. */
#define CORRUPT_DATA FIFTYONE_DEGREES_STATUS_CORRUPT_DATA /**< Synonym for #FIFTYONE_DEGREES_STATUS_CORRUPT_DATA status code. */
#define INCORRECT_VERSION FIFTYONE_DEGREES_STATUS_INCORRECT_VERSION /**< Synonym for #FIFTYONE_DEGREES_STATUS_INCORRECT_VERSION status code. */
#define FILE_NOT_FOUND FIFTYONE_DEGREES_STATUS_FILE_NOT_FOUND /**< Synonym for #FIFTYONE_DEGREES_STATUS_FILE_NOT_FOUND status code. */
#define FILE_BUSY FIFTYONE_DEGREES_STATUS_FILE_BUSY /**< Synonym for #FIFTYONE_DEGREES_STATUS_FILE_BUSY status code. */
#define FILE_FAILURE FIFTYONE_DEGREES_STATUS_FILE_FAILURE /**< Synonym for #FIFTYONE_DEGREES_STATUS_FILE_FAILURE status code. */
#define NOT_SET FIFTYONE_DEGREES_STATUS_NOT_SET /**< Synonym for #FIFTYONE_DEGREES_STATUS_NOT_SET status code. */
#define POINTER_OUT_OF_BOUNDS FIFTYONE_DEGREES_STATUS_POINTER_OUT_OF_BOUNDS /**< Synonym for #FIFTYONE_DEGREES_STATUS_POINTER_OUT_OF_BOUNDS status code. */
#define NULL_POINTER FIFTYONE_DEGREES_STATUS_NULL_POINTER /**< Synonym for #FIFTYONE_DEGREES_STATUS_NULL_POINTER status code. */
#define TOO_MANY_OPEN_FILES FIFTYONE_DEGREES_STATUS_TOO_MANY_OPEN_FILES /**< Synonym for #FIFTYONE_DEGREES_STATUS_TOO_MANY_OPEN_FILES status code. */
#define REQ_PROP_NOT_PRESENT FIFTYONE_DEGREES_STATUS_REQ_PROP_NOT_PRESENT /**< Synonym for #FIFTYONE_DEGREES_STATUS_REQ_PROP_NOT_PRESENT status code. */
#define PROFILE_EMPTY FIFTYONE_DEGREES_STATUS_PROFILE_EMPTY /**< Synonym for #FIFTYONE_DEGREES_STATUS_PROFILE_EMPTY status code. */
#define COLLECTION_FAILURE FIFTYONE_DEGREES_STATUS_COLLECTION_FAILURE /**< Synonym for #FIFTYONE_DEGREES_STATUS_COLLECTION_FAILURE status code. */
#define FILE_COPY_ERROR FIFTYONE_DEGREES_STATUS_FILE_COPY_ERROR /**< Synonym for #FIFTYONE_DEGREES_STATUS_FILE_COPY_ERROR status code. */
#define FILE_EXISTS_ERROR FIFTYONE_DEGREES_STATUS_FILE_EXISTS_ERROR /**< Synonym for #FIFTYONE_DEGREES_STATUS_FILE_EXISTS_ERROR status code. */
#define FILE_WRITE_ERROR FIFTYONE_DEGREES_STATUS_FILE_WRITE_ERROR /**< Synonym for #FIFTYONE_DEGREES_STATUS_FILE_WRITE_ERROR status code. */
#define FILE_READ_ERROR FIFTYONE_DEGREES_STATUS_FILE_READ_ERROR /**< Synonym for #FIFTYONE_DEGREES_STATUS_FILE_READ_ERROR. */
#define FILE_PERMISSION_DENIED FIFTYONE_DEGREES_STATUS_FILE_PERMISSION_DENIED /**< Synonym for #FIFTYONE_DEGREES_STATUS_FILE_PERMISSION_DENIED status code. */
#define FILE_PATH_TOO_LONG FIFTYONE_DEGREES_STATUS_FILE_PATH_TOO_LONG /**< Synonym for #FIFTYONE_DEGREES_STATUS_FILE_PATH_TOO_LONG status code. */
#define FILE_END_OF_DOCUMENT FIFTYONE_DEGREES_STATUS_FILE_END_OF_DOCUMENT /**< Synonym for #FIFTYONE_DEGREES_STATUS_FILE_END_OF_DOCUMENT status code. */
#define FILE_END_OF_DOCUMENTS FIFTYONE_DEGREES_STATUS_FILE_END_OF_DOCUMENTS /**< Synonym for #FIFTYONE_DEGREES_STATUS_FILE_END_OF_DOCUMENTS status code. */
#define FILE_END_OF_FILE FIFTYONE_DEGREES_STATUS_FILE_END_OF_FILE /**< Synonym for #FIFTYONE_DEGREES_STATUS_FILE_END_OF_FILE status code. */
#define ENCODING_ERROR FIFTYONE_DEGREES_STATUS_ENCODING_ERROR /**< Synonym for #FIFTYONE_DEGREES_STATUS_ENCODING_ERROR status code. */
#define INVALID_COLLECTION_CONFIG FIFTYONE_DEGREES_STATUS_INVALID_COLLECTION_CONFIG /**< Synonym for #FIFTYONE_DEGREES_STATUS_INVALID_COLLECTION_CONFIG status code. */
#define INVALID_CONFIG FIFTYONE_DEGREES_STATUS_INVALID_CONFIG /**< Synonym for #FIFTYONE_DEGREES_STATUS_INVALID_CONFIG status code. */
#define INSUFFICIENT_HANDLES FIFTYONE_DEGREES_STATUS_INSUFFICIENT_HANDLES /**< Synonym for #FIFTYONE_DEGREES_STATUS_INSUFFICIENT_HANDLES status code. */
#define COLLECTION_INDEX_OUT_OF_RANGE FIFTYONE_DEGREES_STATUS_COLLECTION_INDEX_OUT_OF_RANGE /**< Synonym for #FIFTYONE_DEGREES_STATUS_COLLECTION_INDEX_OUT_OF_RANGE status code. */
#define COLLECTION_OFFSET_OUT_OF_RANGE FIFTYONE_DEGREES_STATUS_COLLECTION_OFFSET_OUT_OF_RANGE /**< Synonym for #FIFTYONE_DEGREES_STATUS_COLLECTION_OFFSET_OUT_OF_RANGE status code. */
#define COLLECTION_FILE_SEEK_FAIL FIFTYONE_DEGREES_STATUS_COLLECTION_FILE_SEEK_FAIL /**< Synonym for #FIFTYONE_DEGREES_STATUS_COLLECTION_FILE_SEEK_FAIL status code. */
#define COLLECTION_FILE_READ_FAIL FIFTYONE_DEGREES_STATUS_COLLECTION_FILE_READ_FAIL /**< Synonym for #FIFTYONE_DEGREES_STATUS_COLLECTION_FILE_READ_FAIL status code. */
#define INCORRECT_IP_ADDRESS_FORMAT FIFTYONE_DEGREES_STATUS_INCORRECT_IP_ADDRESS_FORMAT /**< Synonym for #FIFTYONE_DEGREES_STATUS_INCORRECT_IP_ADDRESS_FORMAT status code. */
#define TEMP_FILE_ERROR FIFTYONE_DEGREES_STATUS_TEMP_FILE_ERROR /**< Synonym for #FIFTYONE_DEGREES_STATUS_TEMP_FILE_ERROR status code. */
#define DATA_FILE_NEEDS_UPDATED FIFTYONE_DEGREES_STATUS_DATA_FILE_NEEDS_UPDATED /**< Synonym for #FIFTYONE_DEGREES_STATUS_DATA_FILE_NEEDS_UPDATED status code. */
#define INSUFFICIENT_CAPACITY FIFTYONE_DEGREES_STATUS_INSUFFICIENT_CAPACITY /**< Synonym for #FIFTYONE_DEGREES_STATUS_INSUFFICIENT_CAPACITY status code. */
#define INVALID_INPUT FIFTYONE_DEGREES_STATUS_INVALID_INPUT /**< Synonym for #FIFTYONE_DEGREES_STATUS_INVALID_INPUT status code.*/
#define UNSUPPORTED_STORED_VALUE_TYPE FIFTYONE_DEGREES_STATUS_UNSUPPORTED_STORED_VALUE_TYPE /**< Synonym for #FIFTYONE_DEGREES_STATUS_UNSUPPORTED_STORED_VALUE_TYPE status code.*/
#define FILE_TOO_LARGE FIFTYONE_DEGREES_STATUS_FILE_TOO_LARGE /**< Synonym for #FIFTYONE_DEGREES_STATUS_FILE_TOO_LARGE status code.*/
#define UNKNOWN_GEOMETRY FIFTYONE_DEGREES_STATUS_UNKNOWN_GEOMETRY /**< Synonym for #FIFTYONE_DEGREES_STATUS_UNKNOWN_GEOMETRY status code.*/
#define RESERVED_GEOMETRY FIFTYONE_DEGREES_STATUS_RESERVED_GEOMETRY /**< Synonym for #FIFTYONE_DEGREES_STATUS_RESERVED_GEOMETRY status code.*/
#define IPV6_LENGTH FIFTYONE_DEGREES_IPV6_LENGTH /**< Synonym for #FIFTYONE_DEGREES_IPV6_LENGTH macro.*/
#define IPV4_LENGTH FIFTYONE_DEGREES_IPV4_LENGTH /**< Synonym for #FIFTYONE_DEGREES_IPV4_LENGTH macro.*/
#define IP_TYPE_IPV4 FIFTYONE_DEGREES_IP_TYPE_IPV4 /**< Synonym for #FIFTYONE_DEGREES_IP_TYPE_IPV4 enum value.*/
#define IP_TYPE_IPV6 FIFTYONE_DEGREES_IP_TYPE_IPV6 /**< Synonym for #FIFTYONE_DEGREES_IP_TYPE_IPV6 enum value.*/
#define IP_TYPE_INVALID FIFTYONE_DEGREES_IP_TYPE_INVALID /**< Synonym for #FIFTYONE_DEGREES_IP_TYPE_INVALID enum value.*/

 /**
 * @}
 */

#endif

// Data types
MAP_TYPE(ProfilePercentage)
MAP_TYPE(ResultIpi)
MAP_TYPE(ResultsIpi)
MAP_TYPE(ResultIpiArray)
MAP_TYPE(ConfigIpi)
MAP_TYPE(DataSetIpi)
MAP_TYPE(DataSetIpiHeader)
MAP_TYPE(Ipv4Range)
MAP_TYPE(Ipv6Range)
MAP_TYPE(CombinationProfileIndex)
MAP_TYPE(ResultProfileIndex)

// Methods
#define ResultsIpiCreate fiftyoneDegreesResultsIpiCreate /**< Synonym for #fiftyoneDegreesResultsIpiCreate function. */
#define ResultsIpiFree fiftyoneDegreesResultsIpiFree /**< Synonym for #fiftyoneDegreesResultsIpiFree function. */
#define ResultsIpiFromIpAddress fiftyoneDegreesResultsIpiFromIpAddress /**< Synonym for #fiftyoneDegreesResultsIpiFromIpAddress function. */
#define ResultsIpiFromIpAddressString fiftyoneDegreesResultsIpiFromIpAddressString /**< Synonym for #fiftyoneDegreesResultsIpiFromIpAddressString function. */
#define ResultsIpiFromEvidence fiftyoneDegreesResultsIpiFromEvidence /**< Synonym for #fiftyoneDegreesResultsIpiFromEvidence function. */
#define ResultsIpiGetValues fiftyoneDegreesResultsIpiGetValues /**< Synonym for #fiftyoneDegreesResultsIpiGetValues function. */
#define ResultsIpiAddValuesString fiftyoneDegreesResultsIpiAddValuesString /**< Synonym for #fiftyoneDegreesResultsIpiAddValuesString function. */
#define ResultsIpiGetValuesString fiftyoneDegreesResultsIpiGetValuesString /**< Synonym for #fiftyoneDegreesResultsIpiGetValuesString function. */
#define ResultsIpiGetValuesStringByRequiredPropertyIndex fiftyoneDegreesResultsIpiGetValuesStringByRequiredPropertyIndex /**< Synonym for #fiftyoneDegreesResultsIpiGetValuesStringByRequiredPropertyIndex function. */
#define ResultsIpiGetHasValues fiftyoneDegreesResultsIpiGetHasValues /**< Synonym for #fiftyoneDegreesResultsIpiGetHasValues function. */
#define ResultsIpiGetNoValueReason fiftyoneDegreesResultsIpiGetNoValueReason /**< Synonym for #fiftyoneDegreesResultsIpiGetNoValueReason function. */
#define ResultsIpiGetNoValueReasonMessage fiftyoneDegreesResultsIpiGetNoValueReasonMessage /**< Synonym for #fiftyoneDegreesResultsIpiGetNoValueReasonMessage function. */
#define IpiInitManagerFromFile fiftyoneDegreesIpiInitManagerFromFile /**< Synonym for #fiftyoneDegreesIpiInitManagerFromFile function. */
#define IpiInitManagerFromMemory fiftyoneDegreesIpiInitManagerFromMemory /**< Synonym for #fiftyoneDegreesIpiInitManagerFromMemory function. */
#define DataSetIpiGet fiftyoneDegreesDataSetIpiGet /**< Synonym for #fiftyoneDegreesDataSetIpiGet function. */
#define DataSetIpiRelease fiftyoneDegreesDataSetIpiRelease /**< Synonym for #fiftyoneDegreesDataSetIpiRelease function. */
#define IpiReloadManagerFromOriginalFile fiftyoneDegreesIpiReloadManagerFromOriginalFile /**< Synonym for #fiftyoneDegreesIpiReloadManagerFromOriginalFile function. */
#define IpiReloadManagerFromFile fiftyoneDegreesIpiReloadManagerFromFile /**< Synonym for #fiftyoneDegreesIpiReloadManagerFromFile function. */
#define IpiReloadManagerFromMemory fiftyoneDegreesIpiReloadManagerFromMemory /**< Synonym for #fiftyoneDegreesIpiReloadManagerFromMemory function. */
#define IpiGetNetworkIdFromResult fiftyoneDegreesIpiGetNetworkIdFromResult /**< Synonym for #fiftyoneDegreesIpiGetNetworkIdFromResult function. */
#define IpiGetNetworkIdFromResults fiftyoneDegreesIpiGetNetworkIdFromResults /**< Synonym for #fiftyoneDegreesIpiGetNetworkIdFromResults function. */
#define IpiGetIpAddressAsString fiftyoneDegreesIpiGetIpAddressAsString /**< Synonym for #fiftyoneDegreesIpiGetIpAddressAsString function. */
#define IpiGetIpAddressAsByteArray fiftyoneDegreesIpiGetIpAddressAsByteArray /**< Synonym for #fiftyoneDegreesIpiGetIpAddressAsByteArray function. */
#define IpiIterateProfilesForPropertyAndValue fiftyoneDegreesIpiIterateProfilesForPropertyAndValue /**< Synonym for #fiftyoneDegreesIpiIterateProfilesForPropertyAndValue function. */

// Constants
#define DefaultWktDecimalPlaces fiftyoneDegreesDefaultWktDecimalPlaces /**< Synonym for #fiftyoneDegreesDefaultWktDecimalPlaces config. */

// Config
#define IpiInMemoryConfig fiftyoneDegreesIpiInMemoryConfig /**< Synonym for #fiftyoneDegreesIpiInMemoryConfig config. */
#define IpiHighPerformanceConfig fiftyoneDegreesIpiHighPerformanceConfig /**< Synonym for #fiftyoneDegreesIpiHighPerformanceConfig config. */
#define IpiLowMemoryConfig fiftyoneDegreesIpiLowMemoryConfig /**< Synonym for #fiftyoneDegreesIpiLowMemoryConfig config. */
#define IpiBalancedConfig fiftyoneDegreesIpiBalancedConfig /**< Synonym for #fiftyoneDegreesIpiBalancedConfig config. */
#define IpiBalancedTempConfig fiftyoneDegreesIpiBalancedTempConfig /**< Synonym for #fiftyoneDegreesIpiBalancedTempConfig config. */
#define IpiDefaultConfig fiftyoneDegreesIpiDefaultConfig /**< Synonym for #fiftyoneDegreesIpiDefaultConfig config. */

#endif
