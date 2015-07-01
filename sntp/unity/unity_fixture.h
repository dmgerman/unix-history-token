begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//- Copyright (c) 2010 James Grenning and Contributed to Unity Project
end_comment

begin_comment
comment|/* ==========================================     Unity Project - A Test Framework for C     Copyright (c) 2007 Mike Karlesky, Mark VanderVoord, Greg Williams     [Released under MIT License. Please refer to license.txt for details] ========================================== */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UNITY_FIXTURE_H_
end_ifndef

begin_define
define|#
directive|define
name|UNITY_FIXTURE_H_
end_define

begin_include
include|#
directive|include
file|"unity.h"
end_include

begin_include
include|#
directive|include
file|"unity_internals.h"
end_include

begin_include
include|#
directive|include
file|"unity_fixture_malloc_overrides.h"
end_include

begin_include
include|#
directive|include
file|"unity_fixture_internals.h"
end_include

begin_function_decl
name|int
name|UnityMain
parameter_list|(
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|void
function_decl|(
modifier|*
name|runAllTests
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TEST_GROUP
parameter_list|(
name|group
parameter_list|)
define|\
value|static const char* TEST_GROUP_##group = #group
end_define

begin_define
define|#
directive|define
name|TEST_SETUP
parameter_list|(
name|group
parameter_list|)
value|void TEST_##group##_SETUP(void);\     void TEST_##group##_SETUP(void)
end_define

begin_define
define|#
directive|define
name|TEST_TEAR_DOWN
parameter_list|(
name|group
parameter_list|)
value|void TEST_##group##_TEAR_DOWN(void);\     void TEST_##group##_TEAR_DOWN(void)
end_define

begin_define
define|#
directive|define
name|TEST
parameter_list|(
name|group
parameter_list|,
name|name
parameter_list|)
define|\
value|void TEST_##group##_##name##_(void);\     void TEST_##group##_##name##_run(void);\     void TEST_##group##_##name##_run(void)\     {\         UnityTestRunner(TEST_##group##_SETUP,\             TEST_##group##_##name##_,\             TEST_##group##_TEAR_DOWN,\             "TEST(" #group ", " #name ")",\             TEST_GROUP_##group, #name,\             __FILE__, __LINE__);\     }\     void  TEST_##group##_##name##_(void)
end_define

begin_define
define|#
directive|define
name|IGNORE_TEST
parameter_list|(
name|group
parameter_list|,
name|name
parameter_list|)
define|\
value|void TEST_##group##_##name##_(void);\     void TEST_##group##_##name##_run(void);\     void TEST_##group##_##name##_run(void)\     {\         UnityIgnoreTest("IGNORE_TEST(" #group ", " #name ")");\     }\     void TEST_##group##_##name##_(void)
end_define

begin_define
define|#
directive|define
name|DECLARE_TEST_CASE
parameter_list|(
name|group
parameter_list|,
name|name
parameter_list|)
define|\
value|void TEST_##group##_##name##_run(void)
end_define

begin_define
define|#
directive|define
name|RUN_TEST_CASE
parameter_list|(
name|group
parameter_list|,
name|name
parameter_list|)
define|\
value|{ DECLARE_TEST_CASE(group, name);\       TEST_##group##_##name##_run(); }
end_define

begin_comment
comment|//This goes at the bottom of each test file or in a separate c file
end_comment

begin_define
define|#
directive|define
name|TEST_GROUP_RUNNER
parameter_list|(
name|group
parameter_list|)
define|\
value|void TEST_##group##_GROUP_RUNNER_runAll(void);\     void TEST_##group##_GROUP_RUNNER(void);\     void TEST_##group##_GROUP_RUNNER(void)\     {\         TEST_##group##_GROUP_RUNNER_runAll();\     }\     void TEST_##group##_GROUP_RUNNER_runAll(void)
end_define

begin_comment
comment|//Call this from main
end_comment

begin_define
define|#
directive|define
name|RUN_TEST_GROUP
parameter_list|(
name|group
parameter_list|)
define|\
value|{ void TEST_##group##_GROUP_RUNNER(void);\       TEST_##group##_GROUP_RUNNER(); }
end_define

begin_comment
comment|//CppUTest Compatibility Macros
end_comment

begin_define
define|#
directive|define
name|UT_PTR_SET
parameter_list|(
name|ptr
parameter_list|,
name|newPointerValue
parameter_list|)
value|UnityPointer_Set((void**)&ptr, (void*)newPointerValue)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_POINTERS_EQUAL
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|)
value|TEST_ASSERT_EQUAL_PTR(expected, actual)
end_define

begin_define
define|#
directive|define
name|TEST_ASSERT_BYTES_EQUAL
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|)
value|TEST_ASSERT_EQUAL_HEX8(0xff& (expected), 0xff& (actual))
end_define

begin_define
define|#
directive|define
name|FAIL
parameter_list|(
name|message
parameter_list|)
value|TEST_FAIL((message))
end_define

begin_define
define|#
directive|define
name|CHECK
parameter_list|(
name|condition
parameter_list|)
value|TEST_ASSERT_TRUE((condition))
end_define

begin_define
define|#
directive|define
name|LONGS_EQUAL
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|)
value|TEST_ASSERT_EQUAL_INT((expected), (actual))
end_define

begin_define
define|#
directive|define
name|STRCMP_EQUAL
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|)
value|TEST_ASSERT_EQUAL_STRING((expected), (actual))
end_define

begin_define
define|#
directive|define
name|DOUBLES_EQUAL
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|,
name|delta
parameter_list|)
value|TEST_ASSERT_FLOAT_WITHIN(((expected), (actual), (delta))
end_define

begin_function_decl
name|void
name|UnityMalloc_MakeMallocFailAfterCount
parameter_list|(
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNITY_FIXTURE_H_ */
end_comment

end_unit

