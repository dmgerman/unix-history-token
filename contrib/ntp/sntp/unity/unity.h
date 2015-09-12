begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ==========================================     Unity Project - A Test Framework for C     Copyright (c) 2007-14 Mike Karlesky, Mark VanderVoord, Greg Williams     [Released under MIT License. Please refer to license.txt for details] ========================================== */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UNITY_FRAMEWORK_H
end_ifndef

begin_define
define|#
directive|define
name|UNITY_FRAMEWORK_H
end_define

begin_define
define|#
directive|define
name|UNITY
end_define

begin_include
include|#
directive|include
file|"unity_internals.h"
end_include

begin_comment
comment|//-------------------------------------------------------
end_comment

begin_comment
comment|// Configuration Options
end_comment

begin_comment
comment|//-------------------------------------------------------
end_comment

begin_comment
comment|// All options described below should be passed as a compiler flag to all files using Unity. If you must add #defines, place them BEFORE the #include above.
end_comment

begin_comment
comment|// Integers/longs/pointers
end_comment

begin_comment
comment|//     - Unity attempts to automatically discover your integer sizes
end_comment

begin_comment
comment|//       - define UNITY_EXCLUDE_STDINT_H to stop attempting to look in<stdint.h>
end_comment

begin_comment
comment|//       - define UNITY_EXCLUDE_LIMITS_H to stop attempting to look in<limits.h>
end_comment

begin_comment
comment|//       - define UNITY_EXCLUDE_SIZEOF to stop attempting to use sizeof in macros
end_comment

begin_comment
comment|//     - If you cannot use the automatic methods above, you can force Unity by using these options:
end_comment

begin_comment
comment|//       - define UNITY_SUPPORT_64
end_comment

begin_comment
comment|//       - define UNITY_INT_WIDTH
end_comment

begin_comment
comment|//       - UNITY_LONG_WIDTH
end_comment

begin_comment
comment|//       - UNITY_POINTER_WIDTH
end_comment

begin_comment
comment|// Floats
end_comment

begin_comment
comment|//     - define UNITY_EXCLUDE_FLOAT to disallow floating point comparisons
end_comment

begin_comment
comment|//     - define UNITY_FLOAT_PRECISION to specify the precision to use when doing TEST_ASSERT_EQUAL_FLOAT
end_comment

begin_comment
comment|//     - define UNITY_FLOAT_TYPE to specify doubles instead of single precision floats
end_comment

begin_comment
comment|//     - define UNITY_FLOAT_VERBOSE to print floating point values in errors (uses sprintf)
end_comment

begin_comment
comment|//     - define UNITY_INCLUDE_DOUBLE to allow double floating point comparisons
end_comment

begin_comment
comment|//     - define UNITY_EXCLUDE_DOUBLE to disallow double floating point comparisons (default)
end_comment

begin_comment
comment|//     - define UNITY_DOUBLE_PRECISION to specify the precision to use when doing TEST_ASSERT_EQUAL_DOUBLE
end_comment

begin_comment
comment|//     - define UNITY_DOUBLE_TYPE to specify something other than double
end_comment

begin_comment
comment|//     - define UNITY_DOUBLE_VERBOSE to print floating point values in errors (uses sprintf)
end_comment

begin_comment
comment|// Output
end_comment

begin_comment
comment|//     - by default, Unity prints to standard out with putchar.  define UNITY_OUTPUT_CHAR(a) with a different function if desired
end_comment

begin_comment
comment|// Optimization
end_comment

begin_comment
comment|//     - by default, line numbers are stored in unsigned shorts.  Define UNITY_LINE_TYPE with a different type if your files are huge
end_comment

begin_comment
comment|//     - by default, test and failure counters are unsigned shorts.  Define UNITY_COUNTER_TYPE with a different type if you want to save space or have more than 65535 Tests.
end_comment

begin_comment
comment|// Test Cases
end_comment

begin_comment
comment|//     - define UNITY_SUPPORT_TEST_CASES to include the TEST_CASE macro, though really it's mostly about the runner generator script
end_comment

begin_comment
comment|// Parameterized Tests
end_comment

begin_comment
comment|//     - you'll want to create a define of TEST_CASE(...) which basically evaluates to nothing
end_comment

begin_comment
comment|//-------------------------------------------------------
end_comment

begin_comment
comment|// Basic Fail and Ignore
end_comment

begin_comment
comment|//-------------------------------------------------------
end_comment

begin_define
define|#
directive|define
name|TEST_FAIL_MESSAGE
parameter_list|(
name|message
parameter_list|)
value|UNITY_TEST_FAIL(__LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_FAIL
parameter_list|()
value|UNITY_TEST_FAIL(__LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_IGNORE_MESSAGE
parameter_list|(
name|message
parameter_list|)
value|UNITY_TEST_IGNORE(__LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_IGNORE
parameter_list|()
value|UNITY_TEST_IGNORE(__LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ONLY
parameter_list|()
end_define

begin_comment
comment|//-------------------------------------------------------
end_comment

begin_comment
comment|// Test Asserts (simple)
end_comment

begin_comment
comment|//-------------------------------------------------------
end_comment

begin_comment
comment|//Boolean
end_comment

begin_define
define|#
directive|define
name|TEST_ASSERT
parameter_list|(
name|condition
parameter_list|)
value|UNITY_TEST_ASSERT(       (condition), __LINE__, " Expression Evaluated To FALSE")
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_TRUE
parameter_list|(
name|condition
parameter_list|)
value|UNITY_TEST_ASSERT(       (condition), __LINE__, " Expected TRUE Was FALSE")
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_UNLESS
parameter_list|(
name|condition
parameter_list|)
value|UNITY_TEST_ASSERT(      !(condition), __LINE__, " Expression Evaluated To TRUE")
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_FALSE
parameter_list|(
name|condition
parameter_list|)
value|UNITY_TEST_ASSERT(      !(condition), __LINE__, " Expected FALSE Was TRUE")
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_NULL
parameter_list|(
name|pointer
parameter_list|)
value|UNITY_TEST_ASSERT_NULL(    (pointer), __LINE__, " Expected NULL")
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_NOT_NULL
parameter_list|(
name|pointer
parameter_list|)
value|UNITY_TEST_ASSERT_NOT_NULL((pointer), __LINE__, " Expected Non-NULL")
end_define

begin_comment
comment|//Integers (of all sizes)
end_comment

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_INT
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_INT((expected), (actual), __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_INT8
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_INT8((expected), (actual), __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_INT16
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_INT16((expected), (actual), __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_INT32
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_INT32((expected), (actual), __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_INT64
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_INT64((expected), (actual), __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_INT((expected), (actual), __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_NOT_EQUAL
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT(((expected) !=  (actual)), __LINE__, " Expected Not-Equal")
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_UINT
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_UINT( (expected), (actual), __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_UINT8
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_UINT8( (expected), (actual), __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_UINT16
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_UINT16( (expected), (actual), __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_UINT32
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_UINT32( (expected), (actual), __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_UINT64
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_UINT64( (expected), (actual), __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_HEX
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_HEX32((expected), (actual), __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_HEX8
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_HEX8( (expected), (actual), __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_HEX16
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_HEX16((expected), (actual), __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_HEX32
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_HEX32((expected), (actual), __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_HEX64
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_HEX64((expected), (actual), __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_BITS
parameter_list|(
name|mask
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_BITS((mask), (expected), (actual), __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_BITS_HIGH
parameter_list|(
name|mask
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_BITS((mask), (_UU32)(-1), (actual), __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_BITS_LOW
parameter_list|(
name|mask
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_BITS((mask), (_UU32)(0), (actual), __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_BIT_HIGH
parameter_list|(
name|bit
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_BITS(((_UU32)1<< bit), (_UU32)(-1), (actual), __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_BIT_LOW
parameter_list|(
name|bit
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_BITS(((_UU32)1<< bit), (_UU32)(0), (actual), __LINE__, NULL)
end_define

begin_comment
comment|//Integer Ranges (of all sizes)
end_comment

begin_define
define|#
directive|define
name|TEST_ASSERT_INT_WITHIN
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_INT_WITHIN(delta, expected, actual, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_INT8_WITHIN
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_INT8_WITHIN(delta, expected, actual, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_INT16_WITHIN
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_INT16_WITHIN(delta, expected, actual, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_INT32_WITHIN
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_INT32_WITHIN(delta, expected, actual, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_INT64_WITHIN
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_INT64_WITHIN(delta, expected, actual, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_UINT_WITHIN
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_UINT_WITHIN(delta, expected, actual, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_UINT8_WITHIN
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_UINT8_WITHIN(delta, expected, actual, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_UINT16_WITHIN
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_UINT16_WITHIN(delta, expected, actual, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_UINT32_WITHIN
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_UINT32_WITHIN(delta, expected, actual, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_UINT64_WITHIN
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_UINT64_WITHIN(delta, expected, actual, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_HEX_WITHIN
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_HEX32_WITHIN(delta, expected, actual, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_HEX8_WITHIN
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_HEX8_WITHIN(delta, expected, actual, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_HEX16_WITHIN
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_HEX16_WITHIN(delta, expected, actual, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_HEX32_WITHIN
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_HEX32_WITHIN(delta, expected, actual, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_HEX64_WITHIN
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_HEX64_WITHIN(delta, expected, actual, __LINE__, NULL)
end_define

begin_comment
comment|//Structs and Strings
end_comment

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_PTR
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_PTR((expected), (actual), __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_STRING
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_STRING(expected, actual, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_MEMORY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|len
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_MEMORY(expected, actual, len, __LINE__, NULL)
end_define

begin_comment
comment|//Arrays
end_comment

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_INT_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, num_elements, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_INT8_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_INT8_ARRAY(expected, actual, num_elements, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_INT16_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_INT16_ARRAY(expected, actual, num_elements, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_INT32_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_INT32_ARRAY(expected, actual, num_elements, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_INT64_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_INT64_ARRAY(expected, actual, num_elements, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_UINT_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_UINT_ARRAY(expected, actual, num_elements, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_UINT8_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, actual, num_elements, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_UINT16_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_UINT16_ARRAY(expected, actual, num_elements, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_UINT32_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_UINT32_ARRAY(expected, actual, num_elements, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_UINT64_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_UINT64_ARRAY(expected, actual, num_elements, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_HEX_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_HEX32_ARRAY(expected, actual, num_elements, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_HEX8_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_HEX8_ARRAY(expected, actual, num_elements, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_HEX16_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_HEX16_ARRAY(expected, actual, num_elements, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_HEX32_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_HEX32_ARRAY(expected, actual, num_elements, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_HEX64_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_HEX64_ARRAY(expected, actual, num_elements, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_PTR_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_PTR_ARRAY(expected, actual, num_elements, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_STRING_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, num_elements, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_MEMORY_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|len
parameter_list|,
name|num_elements
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_MEMORY_ARRAY(expected, actual, len, num_elements, __LINE__, NULL)
end_define

begin_comment
comment|//Floating Point (If Enabled)
end_comment

begin_define
define|#
directive|define
name|TEST_ASSERT_FLOAT_WITHIN
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_FLOAT_WITHIN(delta, expected, actual, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_FLOAT
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_FLOAT(expected, actual, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_FLOAT_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_FLOAT_ARRAY(expected, actual, num_elements, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_FLOAT_IS_INF
parameter_list|(
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_FLOAT_IS_INF(actual, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_FLOAT_IS_NEG_INF
parameter_list|(
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_FLOAT_IS_NEG_INF(actual, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_FLOAT_IS_NAN
parameter_list|(
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_FLOAT_IS_NAN(actual, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_FLOAT_IS_DETERMINATE
parameter_list|(
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_FLOAT_IS_DETERMINATE(actual, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_FLOAT_IS_NOT_INF
parameter_list|(
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_FLOAT_IS_NOT_INF(actual, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_FLOAT_IS_NOT_NEG_INF
parameter_list|(
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_FLOAT_IS_NOT_NEG_INF(actual, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_FLOAT_IS_NOT_NAN
parameter_list|(
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_FLOAT_IS_NOT_NAN(actual, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_FLOAT_IS_NOT_DETERMINATE
parameter_list|(
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_FLOAT_IS_NOT_DETERMINATE(actual, __LINE__, NULL)
end_define

begin_comment
comment|//Double (If Enabled)
end_comment

begin_define
define|#
directive|define
name|TEST_ASSERT_DOUBLE_WITHIN
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_DOUBLE_WITHIN(delta, expected, actual, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_DOUBLE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_DOUBLE(expected, actual, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_DOUBLE_ARRAY
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_DOUBLE_ARRAY(expected, actual, num_elements, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_DOUBLE_IS_INF
parameter_list|(
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_DOUBLE_IS_INF(actual, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_DOUBLE_IS_NEG_INF
parameter_list|(
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_DOUBLE_IS_NEG_INF(actual, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_DOUBLE_IS_NAN
parameter_list|(
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_DOUBLE_IS_NAN(actual, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_DOUBLE_IS_DETERMINATE
parameter_list|(
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_DOUBLE_IS_DETERMINATE(actual, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_DOUBLE_IS_NOT_INF
parameter_list|(
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_DOUBLE_IS_NOT_INF(actual, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_DOUBLE_IS_NOT_NEG_INF
parameter_list|(
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_DOUBLE_IS_NOT_NEG_INF(actual, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_DOUBLE_IS_NOT_NAN
parameter_list|(
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_DOUBLE_IS_NOT_NAN(actual, __LINE__, NULL)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_DOUBLE_IS_NOT_DETERMINATE
parameter_list|(
name|actual
parameter_list|)
value|UNITY_TEST_ASSERT_DOUBLE_IS_NOT_DETERMINATE(actual, __LINE__, NULL)
end_define

begin_comment
comment|//-------------------------------------------------------
end_comment

begin_comment
comment|// Test Asserts (with additional messages)
end_comment

begin_comment
comment|//-------------------------------------------------------
end_comment

begin_comment
comment|//Boolean
end_comment

begin_define
define|#
directive|define
name|TEST_ASSERT_MESSAGE
parameter_list|(
name|condition
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT(       (condition), __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_TRUE_MESSAGE
parameter_list|(
name|condition
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT(       (condition), __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_UNLESS_MESSAGE
parameter_list|(
name|condition
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT(      !(condition), __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_FALSE_MESSAGE
parameter_list|(
name|condition
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT(      !(condition), __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_NULL_MESSAGE
parameter_list|(
name|pointer
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_NULL(    (pointer), __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_NOT_NULL_MESSAGE
parameter_list|(
name|pointer
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_NOT_NULL((pointer), __LINE__, message)
end_define

begin_comment
comment|//Integers (of all sizes)
end_comment

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_INT_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_INT((expected), (actual), __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_INT8_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_INT8((expected), (actual), __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_INT16_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_INT16((expected), (actual), __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_INT32_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_INT32((expected), (actual), __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_INT64_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_INT64((expected), (actual), __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_INT((expected), (actual), __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_NOT_EQUAL_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT(((expected) !=  (actual)), __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_UINT_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_UINT( (expected), (actual), __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_UINT8_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_UINT8( (expected), (actual), __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_UINT16_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_UINT16( (expected), (actual), __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_UINT32_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_UINT32( (expected), (actual), __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_UINT64_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_UINT64( (expected), (actual), __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_HEX_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_HEX32((expected), (actual), __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_HEX8_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_HEX8( (expected), (actual), __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_HEX16_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_HEX16((expected), (actual), __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_HEX32_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_HEX32((expected), (actual), __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_HEX64_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_HEX64((expected), (actual), __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_BITS_MESSAGE
parameter_list|(
name|mask
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_BITS((mask), (expected), (actual), __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_BITS_HIGH_MESSAGE
parameter_list|(
name|mask
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_BITS((mask), (_UU32)(-1), (actual), __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_BITS_LOW_MESSAGE
parameter_list|(
name|mask
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_BITS((mask), (_UU32)(0), (actual), __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_BIT_HIGH_MESSAGE
parameter_list|(
name|bit
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_BITS(((_UU32)1<< bit), (_UU32)(-1), (actual), __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_BIT_LOW_MESSAGE
parameter_list|(
name|bit
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_BITS(((_UU32)1<< bit), (_UU32)(0), (actual), __LINE__, message)
end_define

begin_comment
comment|//Integer Ranges (of all sizes)
end_comment

begin_define
define|#
directive|define
name|TEST_ASSERT_INT_WITHIN_MESSAGE
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_INT_WITHIN(delta, expected, actual, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_INT8_WITHIN_MESSAGE
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_INT8_WITHIN(delta, expected, actual, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_INT16_WITHIN_MESSAGE
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_INT16_WITHIN(delta, expected, actual, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_INT32_WITHIN_MESSAGE
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_INT32_WITHIN(delta, expected, actual, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_INT64_WITHIN_MESSAGE
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_INT64_WITHIN(delta, expected, actual, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_UINT_WITHIN_MESSAGE
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_UINT_WITHIN(delta, expected, actual, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_UINT8_WITHIN_MESSAGE
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_UINT8_WITHIN(delta, expected, actual, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_UINT16_WITHIN_MESSAGE
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_UINT16_WITHIN(delta, expected, actual, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_UINT32_WITHIN_MESSAGE
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_UINT32_WITHIN(delta, expected, actual, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_UINT64_WITHIN_MESSAGE
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_UINT64_WITHIN(delta, expected, actual, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_HEX_WITHIN_MESSAGE
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_HEX32_WITHIN(delta, expected, actual, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_HEX8_WITHIN_MESSAGE
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_HEX8_WITHIN(delta, expected, actual, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_HEX16_WITHIN_MESSAGE
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_HEX16_WITHIN(delta, expected, actual, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_HEX32_WITHIN_MESSAGE
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_HEX32_WITHIN(delta, expected, actual, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_HEX64_WITHIN_MESSAGE
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_HEX64_WITHIN(delta, expected, actual, __LINE__, message)
end_define

begin_comment
comment|//Structs and Strings
end_comment

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_PTR_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_PTR(expected, actual, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_STRING_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_STRING(expected, actual, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_MEMORY_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|len
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_MEMORY(expected, actual, len, __LINE__, message)
end_define

begin_comment
comment|//Arrays
end_comment

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, num_elements, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_INT8_ARRAY_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_INT8_ARRAY(expected, actual, num_elements, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_INT16_ARRAY_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_INT16_ARRAY(expected, actual, num_elements, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_INT32_ARRAY_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_INT32_ARRAY(expected, actual, num_elements, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_INT64_ARRAY_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_INT64_ARRAY(expected, actual, num_elements, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_UINT_ARRAY_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_UINT_ARRAY(expected, actual, num_elements, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_UINT8_ARRAY_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_UINT8_ARRAY(expected, actual, num_elements, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_UINT16_ARRAY_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_UINT16_ARRAY(expected, actual, num_elements, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_UINT32_ARRAY_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_UINT32_ARRAY(expected, actual, num_elements, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_UINT64_ARRAY_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_UINT64_ARRAY(expected, actual, num_elements, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_HEX_ARRAY_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_HEX32_ARRAY(expected, actual, num_elements, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_HEX8_ARRAY_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_HEX8_ARRAY(expected, actual, num_elements, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_HEX16_ARRAY_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_HEX16_ARRAY(expected, actual, num_elements, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_HEX32_ARRAY_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_HEX32_ARRAY(expected, actual, num_elements, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_HEX64_ARRAY_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_HEX64_ARRAY(expected, actual, num_elements, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_PTR_ARRAY_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_PTR_ARRAY(expected, actual, num_elements, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_STRING_ARRAY_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, num_elements, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_MEMORY_ARRAY_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|len
parameter_list|,
name|num_elements
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_MEMORY_ARRAY(expected, actual, len, num_elements, __LINE__, message)
end_define

begin_comment
comment|//Floating Point (If Enabled)
end_comment

begin_define
define|#
directive|define
name|TEST_ASSERT_FLOAT_WITHIN_MESSAGE
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_FLOAT_WITHIN(delta, expected, actual, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_FLOAT_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_FLOAT(expected, actual, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_FLOAT_ARRAY_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_FLOAT_ARRAY(expected, actual, num_elements, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_FLOAT_IS_INF_MESSAGE
parameter_list|(
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_FLOAT_IS_INF(actual, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_FLOAT_IS_NEG_INF_MESSAGE
parameter_list|(
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_FLOAT_IS_NEG_INF(actual, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_FLOAT_IS_NAN_MESSAGE
parameter_list|(
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_FLOAT_IS_NAN(actual, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_FLOAT_IS_DETERMINATE_MESSAGE
parameter_list|(
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_FLOAT_IS_DETERMINATE(actual, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_FLOAT_IS_NOT_INF_MESSAGE
parameter_list|(
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_FLOAT_IS_NOT_INF(actual, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_FLOAT_IS_NOT_NEG_INF_MESSAGE
parameter_list|(
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_FLOAT_IS_NOT_NEG_INF(actual, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_FLOAT_IS_NOT_NAN_MESSAGE
parameter_list|(
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_FLOAT_IS_NOT_NAN(actual, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_FLOAT_IS_NOT_DETERMINATE_MESSAGE
parameter_list|(
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_FLOAT_IS_NOT_DETERMINATE(actual, __LINE__, message)
end_define

begin_comment
comment|//Double (If Enabled)
end_comment

begin_define
define|#
directive|define
name|TEST_ASSERT_DOUBLE_WITHIN_MESSAGE
parameter_list|(
name|delta
parameter_list|,
name|expected
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_DOUBLE_WITHIN(delta, expected, actual, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_DOUBLE_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_DOUBLE(expected, actual, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_EQUAL_DOUBLE_ARRAY_MESSAGE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|num_elements
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_EQUAL_DOUBLE_ARRAY(expected, actual, num_elements, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_DOUBLE_IS_INF_MESSAGE
parameter_list|(
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_DOUBLE_IS_INF(actual, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_DOUBLE_IS_NEG_INF_MESSAGE
parameter_list|(
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_DOUBLE_IS_NEG_INF(actual, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_DOUBLE_IS_NAN_MESSAGE
parameter_list|(
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_DOUBLE_IS_NAN(actual, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_DOUBLE_IS_DETERMINATE_MESSAGE
parameter_list|(
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_DOUBLE_IS_DETERMINATE(actual, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_DOUBLE_IS_NOT_INF_MESSAGE
parameter_list|(
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_DOUBLE_IS_NOT_INF(actual, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_DOUBLE_IS_NOT_NEG_INF_MESSAGE
parameter_list|(
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_DOUBLE_IS_NOT_NEG_INF(actual, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_DOUBLE_IS_NOT_NAN_MESSAGE
parameter_list|(
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_DOUBLE_IS_NOT_NAN(actual, __LINE__, message)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_DOUBLE_IS_NOT_DETERMINATE_MESSAGE
parameter_list|(
name|actual
parameter_list|,
name|message
parameter_list|)
value|UNITY_TEST_ASSERT_DOUBLE_IS_NOT_DETERMINATE(actual, __LINE__, message)
end_define

begin_comment
comment|//end of UNITY_FRAMEWORK_H
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

