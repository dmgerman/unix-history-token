begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Copyright 2005, Google Inc.
end_comment

begin_comment
comment|// All rights reserved.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Redistribution and use in source and binary forms, with or without
end_comment

begin_comment
comment|// modification, are permitted provided that the following conditions are
end_comment

begin_comment
comment|// met:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//     * Redistributions of source code must retain the above copyright
end_comment

begin_comment
comment|// notice, this list of conditions and the following disclaimer.
end_comment

begin_comment
comment|//     * Redistributions in binary form must reproduce the above
end_comment

begin_comment
comment|// copyright notice, this list of conditions and the following disclaimer
end_comment

begin_comment
comment|// in the documentation and/or other materials provided with the
end_comment

begin_comment
comment|// distribution.
end_comment

begin_comment
comment|//     * Neither the name of Google Inc. nor the names of its
end_comment

begin_comment
comment|// contributors may be used to endorse or promote products derived from
end_comment

begin_comment
comment|// this software without specific prior written permission.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
end_comment

begin_comment
comment|// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
end_comment

begin_comment
comment|// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
end_comment

begin_comment
comment|// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
end_comment

begin_comment
comment|// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
end_comment

begin_comment
comment|// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
end_comment

begin_comment
comment|// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
end_comment

begin_comment
comment|// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
end_comment

begin_comment
comment|// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
end_comment

begin_comment
comment|// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
end_comment

begin_comment
comment|// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Author: wan@google.com (Zhanyong Wan)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The Google C++ Testing Framework (Google Test)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This header file defines the public API for Google Test.  It should be
end_comment

begin_comment
comment|// included by any test program that uses Google Test.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// IMPORTANT NOTE: Due to limitation of the C++ language, we have to
end_comment

begin_comment
comment|// leave some internal implementation details in this header file.
end_comment

begin_comment
comment|// They are clearly marked by comments like this:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   // INTERNAL IMPLEMENTATION - DO NOT USE IN A USER PROGRAM.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Such code is NOT meant to be used by a user directly, and is subject
end_comment

begin_comment
comment|// to CHANGE WITHOUT NOTICE.  Therefore DO NOT DEPEND ON IT in a user
end_comment

begin_comment
comment|// program!
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Acknowledgment: Google Test borrowed the idea of automatic test
end_comment

begin_comment
comment|// registration from Barthelemy Dagenais' (barthelemy@prologique.com)
end_comment

begin_comment
comment|// easyUnit framework.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GTEST_INCLUDE_GTEST_GTEST_H_
end_ifndef

begin_define
define|#
directive|define
name|GTEST_INCLUDE_GTEST_GTEST_H_
end_define

begin_comment
comment|// The following platform macros are used throughout Google Test:
end_comment

begin_comment
comment|//   _WIN32_WCE      Windows CE     (set in project files)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Note that even though _MSC_VER and _WIN32_WCE really indicate a compiler
end_comment

begin_comment
comment|// and a Win32 implementation, respectively, we use them to indicate the
end_comment

begin_comment
comment|// combination of compiler - Win 32 API - C library, since the code currently
end_comment

begin_comment
comment|// only supports:
end_comment

begin_comment
comment|// Windows proper with Visual C++ and MS C library (_MSC_VER&& !_WIN32_WCE) and
end_comment

begin_comment
comment|// Windows Mobile with Visual C++ and no C library (_WIN32_WCE).
end_comment

begin_include
include|#
directive|include
file|<limits>
end_include

begin_include
include|#
directive|include
file|<gtest/internal/gtest-internal.h>
end_include

begin_include
include|#
directive|include
file|<gtest/internal/gtest-string.h>
end_include

begin_include
include|#
directive|include
file|<gtest/gtest-death-test.h>
end_include

begin_include
include|#
directive|include
file|<gtest/gtest-message.h>
end_include

begin_include
include|#
directive|include
file|<gtest/gtest-param-test.h>
end_include

begin_include
include|#
directive|include
file|<gtest/gtest_prod.h>
end_include

begin_include
include|#
directive|include
file|<gtest/gtest-test-part.h>
end_include

begin_include
include|#
directive|include
file|<gtest/gtest-typed-test.h>
end_include

begin_comment
comment|// Depending on the platform, different string classes are available.
end_comment

begin_comment
comment|// On Windows, ::std::string compiles only when exceptions are
end_comment

begin_comment
comment|// enabled.  On Linux, in addition to ::std::string, Google also makes
end_comment

begin_comment
comment|// use of class ::string, which has the same interface as
end_comment

begin_comment
comment|// ::std::string, but has a different implementation.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The user can tell us whether ::std::string is available in his
end_comment

begin_comment
comment|// environment by defining the macro GTEST_HAS_STD_STRING to either 1
end_comment

begin_comment
comment|// or 0 on the compiler command line.  He can also define
end_comment

begin_comment
comment|// GTEST_HAS_GLOBAL_STRING to 1 to indicate that ::string is available
end_comment

begin_comment
comment|// AND is a distinct type to ::std::string, or define it to 0 to
end_comment

begin_comment
comment|// indicate otherwise.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// If the user's ::std::string and ::string are the same class due to
end_comment

begin_comment
comment|// aliasing, he should define GTEST_HAS_STD_STRING to 1 and
end_comment

begin_comment
comment|// GTEST_HAS_GLOBAL_STRING to 0.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// If the user doesn't define GTEST_HAS_STD_STRING and/or
end_comment

begin_comment
comment|// GTEST_HAS_GLOBAL_STRING, they are defined heuristically.
end_comment

begin_decl_stmt
name|namespace
name|testing
block|{
comment|// The upper limit for valid stack trace depths.
specifier|const
name|int
name|kMaxStackTraceDepth
init|=
literal|100
decl_stmt|;
comment|// This flag specifies the maximum number of stack frames to be
comment|// printed in a failure message.
name|GTEST_DECLARE_int32_
argument_list|(
name|stack_trace_depth
argument_list|)
expr_stmt|;
comment|// This flag controls whether Google Test includes Google Test internal
comment|// stack frames in failure stack traces.
name|GTEST_DECLARE_bool_
argument_list|(
name|show_internal_stack_frames
argument_list|)
expr_stmt|;
name|namespace
name|internal
block|{
name|class
name|GTestFlagSaver
decl_stmt|;
comment|// Converts a streamable value to a String.  A NULL pointer is
comment|// converted to "(null)".  When the input value is a ::string,
comment|// ::std::string, ::wstring, or ::std::wstring object, each NUL
comment|// character in it is replaced with "\\0".
comment|// Declared in gtest-internal.h but defined here, so that it has access
comment|// to the definition of the Message class, required by the ARM
comment|// compiler.
name|template
operator|<
name|typename
name|T
operator|>
name|String
name|StreamableToString
argument_list|(
argument|const T& streamable
argument_list|)
block|{
return|return
operator|(
name|Message
argument_list|()
operator|<<
name|streamable
operator|)
operator|.
name|GetString
argument_list|()
return|;
block|}
block|}
comment|// namespace internal
comment|// A class for indicating whether an assertion was successful.  When
comment|// the assertion wasn't successful, the AssertionResult object
comment|// remembers a non-empty message that described how it failed.
comment|//
comment|// This class is useful for defining predicate-format functions to be
comment|// used with predicate assertions (ASSERT_PRED_FORMAT*, etc).
comment|//
comment|// The constructor of AssertionResult is private.  To create an
comment|// instance of this class, use one of the factory functions
comment|// (AssertionSuccess() and AssertionFailure()).
comment|//
comment|// For example, in order to be able to write:
comment|//
comment|//   // Verifies that Foo() returns an even number.
comment|//   EXPECT_PRED_FORMAT1(IsEven, Foo());
comment|//
comment|// you just need to define:
comment|//
comment|//   testing::AssertionResult IsEven(const char* expr, int n) {
comment|//     if ((n % 2) == 0) return testing::AssertionSuccess();
comment|//
comment|//     Message msg;
comment|//     msg<< "Expected: "<< expr<< " is even\n"
comment|//<< "  Actual: it's "<< n;
comment|//     return testing::AssertionFailure(msg);
comment|//   }
comment|//
comment|// If Foo() returns 5, you will see the following message:
comment|//
comment|//   Expected: Foo() is even
comment|//     Actual: it's 5
name|class
name|AssertionResult
block|{
name|public
label|:
comment|// Declares factory functions for making successful and failed
comment|// assertion results as friends.
name|friend
name|AssertionResult
name|AssertionSuccess
parameter_list|()
function_decl|;
name|friend
name|AssertionResult
name|AssertionFailure
parameter_list|(
specifier|const
name|Message
modifier|&
parameter_list|)
function_decl|;
comment|// Returns true iff the assertion succeeded.
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|failure_message_
operator|.
name|c_str
argument_list|()
operator|==
name|NULL
return|;
block|}
comment|// NOLINT
comment|// Returns the assertion's failure message.
specifier|const
name|char
operator|*
name|failure_message
argument_list|()
specifier|const
block|{
return|return
name|failure_message_
operator|.
name|c_str
argument_list|()
return|;
block|}
name|private
label|:
comment|// The default constructor.  It is used when the assertion succeeded.
name|AssertionResult
argument_list|()
block|{}
comment|// The constructor used when the assertion failed.
name|explicit
name|AssertionResult
argument_list|(
specifier|const
name|internal
operator|::
name|String
operator|&
name|failure_message
argument_list|)
decl_stmt|;
comment|// Stores the assertion's failure message.
name|internal
operator|::
name|String
name|failure_message_
expr_stmt|;
block|}
empty_stmt|;
comment|// Makes a successful assertion result.
name|AssertionResult
name|AssertionSuccess
parameter_list|()
function_decl|;
comment|// Makes a failed assertion result with the given failure message.
name|AssertionResult
name|AssertionFailure
parameter_list|(
specifier|const
name|Message
modifier|&
name|msg
parameter_list|)
function_decl|;
comment|// The abstract class that all tests inherit from.
comment|//
comment|// In Google Test, a unit test program contains one or many TestCases, and
comment|// each TestCase contains one or many Tests.
comment|//
comment|// When you define a test using the TEST macro, you don't need to
comment|// explicitly derive from Test - the TEST macro automatically does
comment|// this for you.
comment|//
comment|// The only time you derive from Test is when defining a test fixture
comment|// to be used a TEST_F.  For example:
comment|//
comment|//   class FooTest : public testing::Test {
comment|//    protected:
comment|//     virtual void SetUp() { ... }
comment|//     virtual void TearDown() { ... }
comment|//     ...
comment|//   };
comment|//
comment|//   TEST_F(FooTest, Bar) { ... }
comment|//   TEST_F(FooTest, Baz) { ... }
comment|//
comment|// Test is not copyable.
name|class
name|Test
block|{
name|public
label|:
name|friend
name|class
name|internal
operator|::
name|TestInfoImpl
expr_stmt|;
comment|// Defines types for pointers to functions that set up and tear down
comment|// a test case.
typedef|typedef
name|internal
operator|::
name|SetUpTestCaseFunc
name|SetUpTestCaseFunc
expr_stmt|;
typedef|typedef
name|internal
operator|::
name|TearDownTestCaseFunc
name|TearDownTestCaseFunc
expr_stmt|;
comment|// The d'tor is virtual as we intend to inherit from Test.
name|virtual
operator|~
name|Test
argument_list|()
expr_stmt|;
comment|// Sets up the stuff shared by all tests in this test case.
comment|//
comment|// Google Test will call Foo::SetUpTestCase() before running the first
comment|// test in test case Foo.  Hence a sub-class can define its own
comment|// SetUpTestCase() method to shadow the one defined in the super
comment|// class.
specifier|static
name|void
name|SetUpTestCase
parameter_list|()
block|{}
comment|// Tears down the stuff shared by all tests in this test case.
comment|//
comment|// Google Test will call Foo::TearDownTestCase() after running the last
comment|// test in test case Foo.  Hence a sub-class can define its own
comment|// TearDownTestCase() method to shadow the one defined in the super
comment|// class.
specifier|static
name|void
name|TearDownTestCase
parameter_list|()
block|{}
comment|// Returns true iff the current test has a fatal failure.
specifier|static
name|bool
name|HasFatalFailure
parameter_list|()
function_decl|;
comment|// Logs a property for the current test.  Only the last value for a given
comment|// key is remembered.
comment|// These are public static so they can be called from utility functions
comment|// that are not members of the test fixture.
comment|// The arguments are const char* instead strings, as Google Test is used
comment|// on platforms where string doesn't compile.
comment|//
comment|// Note that a driving consideration for these RecordProperty methods
comment|// was to produce xml output suited to the Greenspan charting utility,
comment|// which at present will only chart values that fit in a 32-bit int. It
comment|// is the user's responsibility to restrict their values to 32-bit ints
comment|// if they intend them to be used with Greenspan.
specifier|static
name|void
name|RecordProperty
parameter_list|(
specifier|const
name|char
modifier|*
name|key
parameter_list|,
specifier|const
name|char
modifier|*
name|value
parameter_list|)
function_decl|;
specifier|static
name|void
name|RecordProperty
parameter_list|(
specifier|const
name|char
modifier|*
name|key
parameter_list|,
name|int
name|value
parameter_list|)
function_decl|;
name|protected
label|:
comment|// Creates a Test object.
name|Test
argument_list|()
expr_stmt|;
comment|// Sets up the test fixture.
name|virtual
name|void
name|SetUp
parameter_list|()
function_decl|;
comment|// Tears down the test fixture.
name|virtual
name|void
name|TearDown
parameter_list|()
function_decl|;
name|private
label|:
comment|// Returns true iff the current test has the same fixture class as
comment|// the first test in the current test case.
specifier|static
name|bool
name|HasSameFixtureClass
parameter_list|()
function_decl|;
comment|// Runs the test after the test fixture has been set up.
comment|//
comment|// A sub-class must implement this to define the test logic.
comment|//
comment|// DO NOT OVERRIDE THIS FUNCTION DIRECTLY IN A USER PROGRAM.
comment|// Instead, use the TEST or TEST_F macro.
name|virtual
name|void
name|TestBody
parameter_list|()
init|=
literal|0
function_decl|;
comment|// Sets up, executes, and tears down the test.
name|void
name|Run
parameter_list|()
function_decl|;
comment|// Uses a GTestFlagSaver to save and restore all Google Test flags.
specifier|const
name|internal
operator|::
name|GTestFlagSaver
operator|*
specifier|const
name|gtest_flag_saver_
expr_stmt|;
comment|// Often a user mis-spells SetUp() as Setup() and spends a long time
comment|// wondering why it is never called by Google Test.  The declaration of
comment|// the following method is solely for catching such an error at
comment|// compile time:
comment|//
comment|//   - The return type is deliberately chosen to be not void, so it
comment|//   will be a conflict if a user declares void Setup() in his test
comment|//   fixture.
comment|//
comment|//   - This method is private, so it will be another compiler error
comment|//   if a user calls it from his test fixture.
comment|//
comment|// DO NOT OVERRIDE THIS FUNCTION.
comment|//
comment|// If you see an error about overriding the following function or
comment|// about it being private, you have mis-spelled SetUp() as Setup().
struct|struct
name|Setup_should_be_spelled_SetUp
block|{}
struct|;
name|virtual
name|Setup_should_be_spelled_SetUp
modifier|*
name|Setup
parameter_list|()
block|{
return|return
name|NULL
return|;
block|}
comment|// We disallow copying Tests.
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|Test
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
comment|// A TestInfo object stores the following information about a test:
comment|//
comment|//   Test case name
comment|//   Test name
comment|//   Whether the test should be run
comment|//   A function pointer that creates the test object when invoked
comment|//   Test result
comment|//
comment|// The constructor of TestInfo registers itself with the UnitTest
comment|// singleton such that the RUN_ALL_TESTS() macro knows which tests to
comment|// run.
name|class
name|TestInfo
block|{
name|public
label|:
comment|// Destructs a TestInfo object.  This function is not virtual, so
comment|// don't inherit from TestInfo.
operator|~
name|TestInfo
argument_list|()
expr_stmt|;
comment|// Returns the test case name.
specifier|const
name|char
operator|*
name|test_case_name
argument_list|()
specifier|const
expr_stmt|;
comment|// Returns the test name.
specifier|const
name|char
operator|*
name|name
argument_list|()
specifier|const
expr_stmt|;
comment|// Returns the test case comment.
specifier|const
name|char
operator|*
name|test_case_comment
argument_list|()
specifier|const
expr_stmt|;
comment|// Returns the test comment.
specifier|const
name|char
operator|*
name|comment
argument_list|()
specifier|const
expr_stmt|;
comment|// Returns true if this test should run.
comment|//
comment|// Google Test allows the user to filter the tests by their full names.
comment|// The full name of a test Bar in test case Foo is defined as
comment|// "Foo.Bar".  Only the tests that match the filter will run.
comment|//
comment|// A filter is a colon-separated list of glob (not regex) patterns,
comment|// optionally followed by a '-' and a colon-separated list of
comment|// negative patterns (tests to exclude).  A test is run if it
comment|// matches one of the positive patterns and does not match any of
comment|// the negative patterns.
comment|//
comment|// For example, *A*:Foo.* is a filter that matches any string that
comment|// contains the character 'A' or starts with "Foo.".
name|bool
name|should_run
argument_list|()
specifier|const
expr_stmt|;
comment|// Returns the result of the test.
specifier|const
name|internal
operator|::
name|TestResult
operator|*
name|result
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
ifdef|#
directive|ifdef
name|GTEST_HAS_DEATH_TEST
name|friend
name|class
name|internal
operator|::
name|DefaultDeathTestFactory
expr_stmt|;
endif|#
directive|endif
comment|// GTEST_HAS_DEATH_TEST
name|friend
name|class
name|internal
operator|::
name|TestInfoImpl
expr_stmt|;
name|friend
name|class
name|internal
operator|::
name|UnitTestImpl
expr_stmt|;
name|friend
name|class
name|Test
decl_stmt|;
name|friend
name|class
name|TestCase
decl_stmt|;
name|friend
name|TestInfo
operator|*
name|internal
operator|::
name|MakeAndRegisterTestInfo
argument_list|(
argument|const char* test_case_name
argument_list|,
argument|const char* name
argument_list|,
argument|const char* test_case_comment
argument_list|,
argument|const char* comment
argument_list|,
argument|internal::TypeId fixture_class_id
argument_list|,
argument|Test::SetUpTestCaseFunc set_up_tc
argument_list|,
argument|Test::TearDownTestCaseFunc tear_down_tc
argument_list|,
argument|internal::TestFactoryBase* factory
argument_list|)
expr_stmt|;
comment|// Increments the number of death tests encountered in this test so
comment|// far.
name|int
name|increment_death_test_count
parameter_list|()
function_decl|;
comment|// Accessors for the implementation object.
name|internal
operator|::
name|TestInfoImpl
operator|*
name|impl
argument_list|()
block|{
return|return
name|impl_
return|;
block|}
specifier|const
name|internal
operator|::
name|TestInfoImpl
operator|*
name|impl
argument_list|()
specifier|const
block|{
return|return
name|impl_
return|;
block|}
comment|// Constructs a TestInfo object. The newly constructed instance assumes
comment|// ownership of the factory object.
name|TestInfo
argument_list|(
argument|const char* test_case_name
argument_list|,
argument|const char* name
argument_list|,
argument|const char* test_case_comment
argument_list|,
argument|const char* comment
argument_list|,
argument|internal::TypeId fixture_class_id
argument_list|,
argument|internal::TestFactoryBase* factory
argument_list|)
empty_stmt|;
comment|// An opaque implementation object.
name|internal
operator|::
name|TestInfoImpl
operator|*
name|impl_
expr_stmt|;
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|TestInfo
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
comment|// An Environment object is capable of setting up and tearing down an
comment|// environment.  The user should subclass this to define his own
comment|// environment(s).
comment|//
comment|// An Environment object does the set-up and tear-down in virtual
comment|// methods SetUp() and TearDown() instead of the constructor and the
comment|// destructor, as:
comment|//
comment|//   1. You cannot safely throw from a destructor.  This is a problem
comment|//      as in some cases Google Test is used where exceptions are enabled, and
comment|//      we may want to implement ASSERT_* using exceptions where they are
comment|//      available.
comment|//   2. You cannot use ASSERT_* directly in a constructor or
comment|//      destructor.
name|class
name|Environment
block|{
name|public
label|:
comment|// The d'tor is virtual as we need to subclass Environment.
name|virtual
operator|~
name|Environment
argument_list|()
block|{}
comment|// Override this to define how to set up the environment.
name|virtual
name|void
name|SetUp
argument_list|()
block|{}
comment|// Override this to define how to tear down the environment.
name|virtual
name|void
name|TearDown
argument_list|()
block|{}
name|private
operator|:
comment|// If you see an error about overriding the following function or
comment|// about it being private, you have mis-spelled SetUp() as Setup().
expr|struct
name|Setup_should_be_spelled_SetUp
block|{}
expr_stmt|;
name|virtual
name|Setup_should_be_spelled_SetUp
modifier|*
name|Setup
parameter_list|()
block|{
return|return
name|NULL
return|;
block|}
block|}
empty_stmt|;
comment|// A UnitTest consists of a list of TestCases.
comment|//
comment|// This is a singleton class.  The only instance of UnitTest is
comment|// created when UnitTest::GetInstance() is first called.  This
comment|// instance is never deleted.
comment|//
comment|// UnitTest is not copyable.
comment|//
comment|// This class is thread-safe as long as the methods are called
comment|// according to their specification.
name|class
name|UnitTest
block|{
name|public
label|:
comment|// Gets the singleton UnitTest object.  The first time this method
comment|// is called, a UnitTest object is constructed and returned.
comment|// Consecutive calls will return the same object.
specifier|static
name|UnitTest
modifier|*
name|GetInstance
parameter_list|()
function_decl|;
comment|// Registers and returns a global test environment.  When a test
comment|// program is run, all global test environments will be set-up in
comment|// the order they were registered.  After all tests in the program
comment|// have finished, all global test environments will be torn-down in
comment|// the *reverse* order they were registered.
comment|//
comment|// The UnitTest object takes ownership of the given environment.
comment|//
comment|// This method can only be called from the main thread.
name|Environment
modifier|*
name|AddEnvironment
parameter_list|(
name|Environment
modifier|*
name|env
parameter_list|)
function_decl|;
comment|// Adds a TestPartResult to the current TestResult object.  All
comment|// Google Test assertion macros (e.g. ASSERT_TRUE, EXPECT_EQ, etc)
comment|// eventually call this to report their results.  The user code
comment|// should use the assertion macros instead of calling this directly.
comment|//
comment|// INTERNAL IMPLEMENTATION - DO NOT USE IN A USER PROGRAM.
name|void
name|AddTestPartResult
argument_list|(
name|TestPartResultType
name|result_type
argument_list|,
specifier|const
name|char
operator|*
name|file_name
argument_list|,
name|int
name|line_number
argument_list|,
specifier|const
name|internal
operator|::
name|String
operator|&
name|message
argument_list|,
specifier|const
name|internal
operator|::
name|String
operator|&
name|os_stack_trace
argument_list|)
decl_stmt|;
comment|// Adds a TestProperty to the current TestResult object. If the result already
comment|// contains a property with the same key, the value will be updated.
name|void
name|RecordPropertyForCurrentTest
parameter_list|(
specifier|const
name|char
modifier|*
name|key
parameter_list|,
specifier|const
name|char
modifier|*
name|value
parameter_list|)
function_decl|;
comment|// Runs all tests in this UnitTest object and prints the result.
comment|// Returns 0 if successful, or 1 otherwise.
comment|//
comment|// This method can only be called from the main thread.
comment|//
comment|// INTERNAL IMPLEMENTATION - DO NOT USE IN A USER PROGRAM.
name|int
name|Run
argument_list|()
name|GTEST_MUST_USE_RESULT_
expr_stmt|;
comment|// Returns the working directory when the first TEST() or TEST_F()
comment|// was executed.  The UnitTest object owns the string.
specifier|const
name|char
operator|*
name|original_working_dir
argument_list|()
specifier|const
expr_stmt|;
comment|// Returns the TestCase object for the test that's currently running,
comment|// or NULL if no test is running.
specifier|const
name|TestCase
operator|*
name|current_test_case
argument_list|()
specifier|const
expr_stmt|;
comment|// Returns the TestInfo object for the test that's currently running,
comment|// or NULL if no test is running.
specifier|const
name|TestInfo
operator|*
name|current_test_info
argument_list|()
specifier|const
expr_stmt|;
ifdef|#
directive|ifdef
name|GTEST_HAS_PARAM_TEST
comment|// Returns the ParameterizedTestCaseRegistry object used to keep track of
comment|// value-parameterized tests and instantiate and register them.
name|internal
operator|::
name|ParameterizedTestCaseRegistry
operator|&
name|parameterized_test_registry
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|// GTEST_HAS_PARAM_TEST
comment|// Accessors for the implementation object.
name|internal
operator|::
name|UnitTestImpl
operator|*
name|impl
argument_list|()
block|{
return|return
name|impl_
return|;
block|}
specifier|const
name|internal
operator|::
name|UnitTestImpl
operator|*
name|impl
argument_list|()
specifier|const
block|{
return|return
name|impl_
return|;
block|}
name|private
label|:
comment|// ScopedTrace is a friend as it needs to modify the per-thread
comment|// trace stack, which is a private member of UnitTest.
name|friend
name|class
name|internal
operator|::
name|ScopedTrace
expr_stmt|;
comment|// Creates an empty UnitTest.
name|UnitTest
argument_list|()
expr_stmt|;
comment|// D'tor
name|virtual
operator|~
name|UnitTest
argument_list|()
expr_stmt|;
comment|// Pushes a trace defined by SCOPED_TRACE() on to the per-thread
comment|// Google Test trace stack.
name|void
name|PushGTestTrace
argument_list|(
specifier|const
name|internal
operator|::
name|TraceInfo
operator|&
name|trace
argument_list|)
decl_stmt|;
comment|// Pops a trace from the per-thread Google Test trace stack.
name|void
name|PopGTestTrace
parameter_list|()
function_decl|;
comment|// Protects mutable state in *impl_.  This is mutable as some const
comment|// methods need to lock it too.
name|mutable
name|internal
operator|::
name|Mutex
name|mutex_
expr_stmt|;
comment|// Opaque implementation object.  This field is never changed once
comment|// the object is constructed.  We don't mark it as const here, as
comment|// doing so will cause a warning in the constructor of UnitTest.
comment|// Mutable state in *impl_ is protected by mutex_.
name|internal
operator|::
name|UnitTestImpl
operator|*
name|impl_
expr_stmt|;
comment|// We disallow copying UnitTest.
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|UnitTest
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
comment|// A convenient wrapper for adding an environment for the test
comment|// program.
comment|//
comment|// You should call this before RUN_ALL_TESTS() is called, probably in
comment|// main().  If you use gtest_main, you need to call this before main()
comment|// starts for it to take effect.  For example, you can define a global
comment|// variable like this:
comment|//
comment|//   testing::Environment* const foo_env =
comment|//       testing::AddGlobalTestEnvironment(new FooEnvironment);
comment|//
comment|// However, we strongly recommend you to write your own main() and
comment|// call AddGlobalTestEnvironment() there, as relying on initialization
comment|// of global variables makes the code harder to read and may cause
comment|// problems when you register multiple environments from different
comment|// translation units and the environments have dependencies among them
comment|// (remember that the compiler doesn't guarantee the order in which
comment|// global variables from different translation units are initialized).
specifier|inline
name|Environment
modifier|*
name|AddGlobalTestEnvironment
parameter_list|(
name|Environment
modifier|*
name|env
parameter_list|)
block|{
return|return
name|UnitTest
operator|::
name|GetInstance
argument_list|()
operator|->
name|AddEnvironment
argument_list|(
name|env
argument_list|)
return|;
block|}
comment|// Initializes Google Test.  This must be called before calling
comment|// RUN_ALL_TESTS().  In particular, it parses a command line for the
comment|// flags that Google Test recognizes.  Whenever a Google Test flag is
comment|// seen, it is removed from argv, and *argc is decremented.
comment|//
comment|// No value is returned.  Instead, the Google Test flag variables are
comment|// updated.
comment|//
comment|// Calling the function for the second time has no user-visible effect.
name|void
name|InitGoogleTest
parameter_list|(
name|int
modifier|*
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
comment|// This overloaded version can be used in Windows programs compiled in
comment|// UNICODE mode.
name|void
name|InitGoogleTest
parameter_list|(
name|int
modifier|*
name|argc
parameter_list|,
name|wchar_t
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
name|namespace
name|internal
block|{
comment|// These overloaded versions handle ::std::string and ::std::wstring.
if|#
directive|if
name|GTEST_HAS_STD_STRING
specifier|inline
name|String
name|FormatForFailureMessage
argument_list|(
specifier|const
operator|::
name|std
operator|::
name|string
operator|&
name|str
argument_list|)
block|{
return|return
operator|(
name|Message
argument_list|()
operator|<<
literal|'"'
operator|<<
name|str
operator|<<
literal|'"'
operator|)
operator|.
name|GetString
argument_list|()
return|;
block|}
endif|#
directive|endif
comment|// GTEST_HAS_STD_STRING
if|#
directive|if
name|GTEST_HAS_STD_WSTRING
specifier|inline
name|String
name|FormatForFailureMessage
argument_list|(
specifier|const
operator|::
name|std
operator|::
name|wstring
operator|&
name|wstr
argument_list|)
block|{
return|return
operator|(
name|Message
argument_list|()
operator|<<
literal|"L\""
operator|<<
name|wstr
operator|<<
literal|'"'
operator|)
operator|.
name|GetString
argument_list|()
return|;
block|}
endif|#
directive|endif
comment|// GTEST_HAS_STD_WSTRING
comment|// These overloaded versions handle ::string and ::wstring.
if|#
directive|if
name|GTEST_HAS_GLOBAL_STRING
specifier|inline
name|String
name|FormatForFailureMessage
argument_list|(
specifier|const
operator|::
name|string
operator|&
name|str
argument_list|)
block|{
return|return
operator|(
name|Message
argument_list|()
operator|<<
literal|'"'
operator|<<
name|str
operator|<<
literal|'"'
operator|)
operator|.
name|GetString
argument_list|()
return|;
block|}
endif|#
directive|endif
comment|// GTEST_HAS_GLOBAL_STRING
if|#
directive|if
name|GTEST_HAS_GLOBAL_WSTRING
specifier|inline
name|String
name|FormatForFailureMessage
argument_list|(
specifier|const
operator|::
name|wstring
operator|&
name|wstr
argument_list|)
block|{
return|return
operator|(
name|Message
argument_list|()
operator|<<
literal|"L\""
operator|<<
name|wstr
operator|<<
literal|'"'
operator|)
operator|.
name|GetString
argument_list|()
return|;
block|}
endif|#
directive|endif
comment|// GTEST_HAS_GLOBAL_WSTRING
comment|// Formats a comparison assertion (e.g. ASSERT_EQ, EXPECT_LT, and etc)
comment|// operand to be used in a failure message.  The type (but not value)
comment|// of the other operand may affect the format.  This allows us to
comment|// print a char* as a raw pointer when it is compared against another
comment|// char*, and print it as a C string when it is compared against an
comment|// std::string object, for example.
comment|//
comment|// The default implementation ignores the type of the other operand.
comment|// Some specialized versions are used to handle formatting wide or
comment|// narrow C strings.
comment|//
comment|// INTERNAL IMPLEMENTATION - DO NOT USE IN A USER PROGRAM.
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|>
name|String
name|FormatForComparisonFailureMessage
argument_list|(
argument|const T1& value
argument_list|,
argument|const T2&
comment|/* other_operand */
argument_list|)
block|{
return|return
name|FormatForFailureMessage
argument_list|(
name|value
argument_list|)
return|;
block|}
comment|// The helper function for {ASSERT|EXPECT}_EQ.
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|>
name|AssertionResult
name|CmpHelperEQ
argument_list|(
argument|const char* expected_expression
argument_list|,
argument|const char* actual_expression
argument_list|,
argument|const T1& expected
argument_list|,
argument|const T2& actual
argument_list|)
block|{
if|if
condition|(
name|expected
operator|==
name|actual
condition|)
block|{
return|return
name|AssertionSuccess
argument_list|()
return|;
block|}
return|return
name|EqFailure
argument_list|(
name|expected_expression
argument_list|,
name|actual_expression
argument_list|,
name|FormatForComparisonFailureMessage
argument_list|(
name|expected
argument_list|,
name|actual
argument_list|)
argument_list|,
name|FormatForComparisonFailureMessage
argument_list|(
name|actual
argument_list|,
name|expected
argument_list|)
argument_list|,
name|false
argument_list|)
return|;
block|}
comment|// With this overloaded version, we allow anonymous enums to be used
comment|// in {ASSERT|EXPECT}_EQ when compiled with gcc 4, as anonymous enums
comment|// can be implicitly cast to BiggestInt.
name|AssertionResult
name|CmpHelperEQ
parameter_list|(
specifier|const
name|char
modifier|*
name|expected_expression
parameter_list|,
specifier|const
name|char
modifier|*
name|actual_expression
parameter_list|,
name|BiggestInt
name|expected
parameter_list|,
name|BiggestInt
name|actual
parameter_list|)
function_decl|;
comment|// The helper class for {ASSERT|EXPECT}_EQ.  The template argument
comment|// lhs_is_null_literal is true iff the first argument to ASSERT_EQ()
comment|// is a null pointer literal.  The following default implementation is
comment|// for lhs_is_null_literal being false.
name|template
operator|<
name|bool
name|lhs_is_null_literal
operator|>
name|class
name|EqHelper
block|{
name|public
operator|:
comment|// This templatized version is for the general case.
name|template
operator|<
name|typename
name|T1
block|,
name|typename
name|T2
operator|>
specifier|static
name|AssertionResult
name|Compare
argument_list|(
argument|const char* expected_expression
argument_list|,
argument|const char* actual_expression
argument_list|,
argument|const T1& expected
argument_list|,
argument|const T2& actual
argument_list|)
block|{
return|return
name|CmpHelperEQ
argument_list|(
name|expected_expression
argument_list|,
name|actual_expression
argument_list|,
name|expected
argument_list|,
name|actual
argument_list|)
return|;
block|}
comment|// With this overloaded version, we allow anonymous enums to be used
comment|// in {ASSERT|EXPECT}_EQ when compiled with gcc 4, as anonymous
comment|// enums can be implicitly cast to BiggestInt.
comment|//
comment|// Even though its body looks the same as the above version, we
comment|// cannot merge the two, as it will make anonymous enums unhappy.
specifier|static
name|AssertionResult
name|Compare
argument_list|(
argument|const char* expected_expression
argument_list|,
argument|const char* actual_expression
argument_list|,
argument|BiggestInt expected
argument_list|,
argument|BiggestInt actual
argument_list|)
block|{
return|return
name|CmpHelperEQ
argument_list|(
name|expected_expression
argument_list|,
name|actual_expression
argument_list|,
name|expected
argument_list|,
name|actual
argument_list|)
return|;
block|}
expr|}
block|;
comment|// This specialization is used when the first argument to ASSERT_EQ()
comment|// is a null pointer literal.
name|template
operator|<
operator|>
name|class
name|EqHelper
operator|<
name|true
operator|>
block|{
name|public
operator|:
comment|// We define two overloaded versions of Compare().  The first
comment|// version will be picked when the second argument to ASSERT_EQ() is
comment|// NOT a pointer, e.g. ASSERT_EQ(0, AnIntFunction()) or
comment|// EXPECT_EQ(false, a_bool).
name|template
operator|<
name|typename
name|T1
block|,
name|typename
name|T2
operator|>
specifier|static
name|AssertionResult
name|Compare
argument_list|(
argument|const char* expected_expression
argument_list|,
argument|const char* actual_expression
argument_list|,
argument|const T1& expected
argument_list|,
argument|const T2& actual
argument_list|)
block|{
return|return
name|CmpHelperEQ
argument_list|(
name|expected_expression
argument_list|,
name|actual_expression
argument_list|,
name|expected
argument_list|,
name|actual
argument_list|)
return|;
block|}
comment|// This version will be picked when the second argument to
comment|// ASSERT_EQ() is a pointer, e.g. ASSERT_EQ(NULL, a_pointer).
name|template
operator|<
name|typename
name|T1
block|,
name|typename
name|T2
operator|>
specifier|static
name|AssertionResult
name|Compare
argument_list|(
argument|const char* expected_expression
argument_list|,
argument|const char* actual_expression
argument_list|,
argument|const T1& expected
argument_list|,
argument|T2* actual
argument_list|)
block|{
comment|// We already know that 'expected' is a null pointer.
return|return
name|CmpHelperEQ
argument_list|(
name|expected_expression
argument_list|,
name|actual_expression
argument_list|,
name|static_cast
operator|<
name|T2
operator|*
operator|>
operator|(
name|NULL
operator|)
argument_list|,
name|actual
argument_list|)
return|;
block|}
expr|}
block|;
comment|// A macro for implementing the helper functions needed to implement
comment|// ASSERT_?? and EXPECT_??.  It is here just to avoid copy-and-paste
comment|// of similar code.
comment|//
comment|// For each templatized helper function, we also define an overloaded
comment|// version for BiggestInt in order to reduce code bloat and allow
comment|// anonymous enums to be used with {ASSERT|EXPECT}_?? when compiled
comment|// with gcc 4.
comment|//
comment|// INTERNAL IMPLEMENTATION - DO NOT USE IN A USER PROGRAM.
define|#
directive|define
name|GTEST_IMPL_CMP_HELPER_
parameter_list|(
name|op_name
parameter_list|,
name|op
parameter_list|)
define|\
value|template<typename T1, typename T2>\ AssertionResult CmpHelper##op_name(const char* expr1, const char* expr2, \                                    const T1& val1, const T2& val2) {\   if (val1 op val2) {\     return AssertionSuccess();\   } else {\     Message msg;\     msg<< "Expected: ("<< expr1<< ") " #op " ("<< expr2\<< "), actual: "<< FormatForComparisonFailureMessage(val1, val2)\<< " vs "<< FormatForComparisonFailureMessage(val2, val1);\     return AssertionFailure(msg);\   }\ }\ AssertionResult CmpHelper##op_name(const char* expr1, const char* expr2, \                                    BiggestInt val1, BiggestInt val2);
comment|// INTERNAL IMPLEMENTATION - DO NOT USE IN A USER PROGRAM.
comment|// Implements the helper function for {ASSERT|EXPECT}_NE
name|GTEST_IMPL_CMP_HELPER_
argument_list|(
argument|NE
argument_list|,
argument|!=
argument_list|)
comment|// Implements the helper function for {ASSERT|EXPECT}_LE
name|GTEST_IMPL_CMP_HELPER_
argument_list|(
argument|LE
argument_list|,
argument|<=
argument_list|)
comment|// Implements the helper function for {ASSERT|EXPECT}_LT
name|GTEST_IMPL_CMP_HELPER_
argument_list|(
argument|LT
argument_list|,
argument|<
argument_list|)
comment|// Implements the helper function for {ASSERT|EXPECT}_GE
name|GTEST_IMPL_CMP_HELPER_
argument_list|(
argument|GE
argument_list|,
argument|>=
argument_list|)
comment|// Implements the helper function for {ASSERT|EXPECT}_GT
name|GTEST_IMPL_CMP_HELPER_
argument_list|(
argument|GT
argument_list|,
argument|>
argument_list|)
undef|#
directive|undef
name|GTEST_IMPL_CMP_HELPER_
comment|// The helper function for {ASSERT|EXPECT}_STREQ.
comment|//
comment|// INTERNAL IMPLEMENTATION - DO NOT USE IN A USER PROGRAM.
name|AssertionResult
name|CmpHelperSTREQ
argument_list|(
specifier|const
name|char
operator|*
name|expected_expression
argument_list|,
specifier|const
name|char
operator|*
name|actual_expression
argument_list|,
specifier|const
name|char
operator|*
name|expected
argument_list|,
specifier|const
name|char
operator|*
name|actual
argument_list|)
block|;
comment|// The helper function for {ASSERT|EXPECT}_STRCASEEQ.
comment|//
comment|// INTERNAL IMPLEMENTATION - DO NOT USE IN A USER PROGRAM.
name|AssertionResult
name|CmpHelperSTRCASEEQ
argument_list|(
specifier|const
name|char
operator|*
name|expected_expression
argument_list|,
specifier|const
name|char
operator|*
name|actual_expression
argument_list|,
specifier|const
name|char
operator|*
name|expected
argument_list|,
specifier|const
name|char
operator|*
name|actual
argument_list|)
block|;
comment|// The helper function for {ASSERT|EXPECT}_STRNE.
comment|//
comment|// INTERNAL IMPLEMENTATION - DO NOT USE IN A USER PROGRAM.
name|AssertionResult
name|CmpHelperSTRNE
argument_list|(
specifier|const
name|char
operator|*
name|s1_expression
argument_list|,
specifier|const
name|char
operator|*
name|s2_expression
argument_list|,
specifier|const
name|char
operator|*
name|s1
argument_list|,
specifier|const
name|char
operator|*
name|s2
argument_list|)
block|;
comment|// The helper function for {ASSERT|EXPECT}_STRCASENE.
comment|//
comment|// INTERNAL IMPLEMENTATION - DO NOT USE IN A USER PROGRAM.
name|AssertionResult
name|CmpHelperSTRCASENE
argument_list|(
specifier|const
name|char
operator|*
name|s1_expression
argument_list|,
specifier|const
name|char
operator|*
name|s2_expression
argument_list|,
specifier|const
name|char
operator|*
name|s1
argument_list|,
specifier|const
name|char
operator|*
name|s2
argument_list|)
block|;
comment|// Helper function for *_STREQ on wide strings.
comment|//
comment|// INTERNAL IMPLEMENTATION - DO NOT USE IN A USER PROGRAM.
name|AssertionResult
name|CmpHelperSTREQ
argument_list|(
specifier|const
name|char
operator|*
name|expected_expression
argument_list|,
specifier|const
name|char
operator|*
name|actual_expression
argument_list|,
specifier|const
name|wchar_t
operator|*
name|expected
argument_list|,
specifier|const
name|wchar_t
operator|*
name|actual
argument_list|)
block|;
comment|// Helper function for *_STRNE on wide strings.
comment|//
comment|// INTERNAL IMPLEMENTATION - DO NOT USE IN A USER PROGRAM.
name|AssertionResult
name|CmpHelperSTRNE
argument_list|(
specifier|const
name|char
operator|*
name|s1_expression
argument_list|,
specifier|const
name|char
operator|*
name|s2_expression
argument_list|,
specifier|const
name|wchar_t
operator|*
name|s1
argument_list|,
specifier|const
name|wchar_t
operator|*
name|s2
argument_list|)
block|;  }
comment|// namespace internal
comment|// IsSubstring() and IsNotSubstring() are intended to be used as the
comment|// first argument to {EXPECT,ASSERT}_PRED_FORMAT2(), not by
comment|// themselves.  They check whether needle is a substring of haystack
comment|// (NULL is considered a substring of itself only), and return an
comment|// appropriate error message when they fail.
comment|//
comment|// The {needle,haystack}_expr arguments are the stringified
comment|// expressions that generated the two real arguments.
name|AssertionResult
name|IsSubstring
argument_list|(
specifier|const
name|char
operator|*
name|needle_expr
argument_list|,
specifier|const
name|char
operator|*
name|haystack_expr
argument_list|,
specifier|const
name|char
operator|*
name|needle
argument_list|,
specifier|const
name|char
operator|*
name|haystack
argument_list|)
block|;
name|AssertionResult
name|IsSubstring
argument_list|(
specifier|const
name|char
operator|*
name|needle_expr
argument_list|,
specifier|const
name|char
operator|*
name|haystack_expr
argument_list|,
specifier|const
name|wchar_t
operator|*
name|needle
argument_list|,
specifier|const
name|wchar_t
operator|*
name|haystack
argument_list|)
block|;
name|AssertionResult
name|IsNotSubstring
argument_list|(
specifier|const
name|char
operator|*
name|needle_expr
argument_list|,
specifier|const
name|char
operator|*
name|haystack_expr
argument_list|,
specifier|const
name|char
operator|*
name|needle
argument_list|,
specifier|const
name|char
operator|*
name|haystack
argument_list|)
block|;
name|AssertionResult
name|IsNotSubstring
argument_list|(
specifier|const
name|char
operator|*
name|needle_expr
argument_list|,
specifier|const
name|char
operator|*
name|haystack_expr
argument_list|,
specifier|const
name|wchar_t
operator|*
name|needle
argument_list|,
specifier|const
name|wchar_t
operator|*
name|haystack
argument_list|)
block|;
if|#
directive|if
name|GTEST_HAS_STD_STRING
name|AssertionResult
name|IsSubstring
argument_list|(
specifier|const
name|char
operator|*
name|needle_expr
argument_list|,
specifier|const
name|char
operator|*
name|haystack_expr
argument_list|,
specifier|const
operator|::
name|std
operator|::
name|string
operator|&
name|needle
argument_list|,
specifier|const
operator|::
name|std
operator|::
name|string
operator|&
name|haystack
argument_list|)
block|;
name|AssertionResult
name|IsNotSubstring
argument_list|(
specifier|const
name|char
operator|*
name|needle_expr
argument_list|,
specifier|const
name|char
operator|*
name|haystack_expr
argument_list|,
specifier|const
operator|::
name|std
operator|::
name|string
operator|&
name|needle
argument_list|,
specifier|const
operator|::
name|std
operator|::
name|string
operator|&
name|haystack
argument_list|)
block|;
endif|#
directive|endif
comment|// GTEST_HAS_STD_STRING
if|#
directive|if
name|GTEST_HAS_STD_WSTRING
name|AssertionResult
name|IsSubstring
argument_list|(
specifier|const
name|char
operator|*
name|needle_expr
argument_list|,
specifier|const
name|char
operator|*
name|haystack_expr
argument_list|,
specifier|const
operator|::
name|std
operator|::
name|wstring
operator|&
name|needle
argument_list|,
specifier|const
operator|::
name|std
operator|::
name|wstring
operator|&
name|haystack
argument_list|)
block|;
name|AssertionResult
name|IsNotSubstring
argument_list|(
specifier|const
name|char
operator|*
name|needle_expr
argument_list|,
specifier|const
name|char
operator|*
name|haystack_expr
argument_list|,
specifier|const
operator|::
name|std
operator|::
name|wstring
operator|&
name|needle
argument_list|,
specifier|const
operator|::
name|std
operator|::
name|wstring
operator|&
name|haystack
argument_list|)
block|;
endif|#
directive|endif
comment|// GTEST_HAS_STD_WSTRING
name|namespace
name|internal
block|{
comment|// Helper template function for comparing floating-points.
comment|//
comment|// Template parameter:
comment|//
comment|//   RawType: the raw floating-point type (either float or double)
comment|//
comment|// INTERNAL IMPLEMENTATION - DO NOT USE IN A USER PROGRAM.
name|template
operator|<
name|typename
name|RawType
operator|>
name|AssertionResult
name|CmpHelperFloatingPointEQ
argument_list|(
argument|const char* expected_expression
argument_list|,
argument|const char* actual_expression
argument_list|,
argument|RawType expected
argument_list|,
argument|RawType actual
argument_list|)
block|{
specifier|const
name|FloatingPoint
operator|<
name|RawType
operator|>
name|lhs
argument_list|(
name|expected
argument_list|)
block|,
name|rhs
argument_list|(
name|actual
argument_list|)
block|;
if|if
condition|(
name|lhs
operator|.
name|AlmostEquals
argument_list|(
name|rhs
argument_list|)
condition|)
block|{
return|return
name|AssertionSuccess
argument_list|()
return|;
block|}
name|StrStream
name|expected_ss
decl_stmt|;
name|expected_ss
operator|<<
name|std
operator|::
name|setprecision
argument_list|(
name|std
operator|::
name|numeric_limits
operator|<
name|RawType
operator|>
operator|::
name|digits10
operator|+
literal|2
argument_list|)
operator|<<
name|expected
block|;
name|StrStream
name|actual_ss
block|;
name|actual_ss
operator|<<
name|std
operator|::
name|setprecision
argument_list|(
name|std
operator|::
name|numeric_limits
operator|<
name|RawType
operator|>
operator|::
name|digits10
operator|+
literal|2
argument_list|)
operator|<<
name|actual
block|;
return|return
name|EqFailure
argument_list|(
name|expected_expression
argument_list|,
name|actual_expression
argument_list|,
name|StrStreamToString
argument_list|(
operator|&
name|expected_ss
argument_list|)
argument_list|,
name|StrStreamToString
argument_list|(
operator|&
name|actual_ss
argument_list|)
argument_list|,
name|false
argument_list|)
return|;
block|}
comment|// Helper function for implementing ASSERT_NEAR.
comment|//
comment|// INTERNAL IMPLEMENTATION - DO NOT USE IN A USER PROGRAM.
name|AssertionResult
name|DoubleNearPredFormat
argument_list|(
argument|const char* expr1
argument_list|,
argument|const char* expr2
argument_list|,
argument|const char* abs_error_expr
argument_list|,
argument|double val1
argument_list|,
argument|double val2
argument_list|,
argument|double abs_error
argument_list|)
block|;
comment|// INTERNAL IMPLEMENTATION - DO NOT USE IN USER CODE.
comment|// A class that enables one to stream messages to assertion macros
name|class
name|AssertHelper
block|{
name|public
operator|:
comment|// Constructor.
name|AssertHelper
argument_list|(
argument|TestPartResultType type
argument_list|,
argument|const char* file
argument_list|,
argument|int line
argument_list|,
argument|const char* message
argument_list|)
block|;
comment|// Message assignment is a semantic trick to enable assertion
comment|// streaming; see the GTEST_MESSAGE_ macro below.
name|void
name|operator
operator|=
operator|(
specifier|const
name|Message
operator|&
name|message
operator|)
specifier|const
block|;
name|private
operator|:
name|TestPartResultType
specifier|const
name|type_
block|;
specifier|const
name|char
operator|*
specifier|const
name|file_
block|;
name|int
specifier|const
name|line_
block|;
name|String
specifier|const
name|message_
block|;
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|AssertHelper
argument_list|)
block|; }
block|;  }
comment|// namespace internal
ifdef|#
directive|ifdef
name|GTEST_HAS_PARAM_TEST
comment|// The abstract base class that all value-parameterized tests inherit from.
comment|//
comment|// This class adds support for accessing the test parameter value via
comment|// the GetParam() method.
comment|//
comment|// Use it with one of the parameter generator defining functions, like Range(),
comment|// Values(), ValuesIn(), Bool(), and Combine().
comment|//
comment|// class FooTest : public ::testing::TestWithParam<int> {
comment|//  protected:
comment|//   FooTest() {
comment|//     // Can use GetParam() here.
comment|//   }
comment|//   virtual ~FooTest() {
comment|//     // Can use GetParam() here.
comment|//   }
comment|//   virtual void SetUp() {
comment|//     // Can use GetParam() here.
comment|//   }
comment|//   virtual void TearDown {
comment|//     // Can use GetParam() here.
comment|//   }
comment|// };
comment|// TEST_P(FooTest, DoesBar) {
comment|//   // Can use GetParam() method here.
comment|//   Foo foo;
comment|//   ASSERT_TRUE(foo.DoesBar(GetParam()));
comment|// }
comment|// INSTANTIATE_TEST_CASE_P(OneToTenRange, FooTest, ::testing::Range(1, 10));
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|TestWithParam
operator|:
name|public
name|Test
block|{
name|public
operator|:
typedef|typedef
name|T
name|ParamType
typedef|;
comment|// The current parameter value. Is also available in the test fixture's
comment|// constructor.
specifier|const
name|ParamType
operator|&
name|GetParam
argument_list|()
specifier|const
block|{
return|return
operator|*
name|parameter_
return|;
block|}
name|private
operator|:
comment|// Sets parameter value. The caller is responsible for making sure the value
comment|// remains alive and unchanged throughout the current test.
specifier|static
name|void
name|SetParam
argument_list|(
argument|const ParamType* parameter
argument_list|)
block|{
name|parameter_
operator|=
name|parameter
block|;   }
comment|// Static value used for accessing parameter during a test lifetime.
specifier|static
specifier|const
name|ParamType
operator|*
name|parameter_
expr_stmt|;
comment|// TestClass must be a subclass of TestWithParam<T>.
name|template
operator|<
name|class
name|TestClass
operator|>
name|friend
name|class
name|internal
operator|::
name|ParameterizedTestFactory
expr_stmt|;
block|}
empty_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
specifier|const
name|T
operator|*
name|TestWithParam
operator|<
name|T
operator|>
operator|::
name|parameter_
operator|=
name|NULL
expr_stmt|;
endif|#
directive|endif
comment|// GTEST_HAS_PARAM_TEST
comment|// Macros for indicating success/failure in test code.
comment|// ADD_FAILURE unconditionally adds a failure to the current test.
comment|// SUCCEED generates a success - it doesn't automatically make the
comment|// current test successful, as a test is only successful when it has
comment|// no failure.
comment|//
comment|// EXPECT_* verifies that a certain condition is satisfied.  If not,
comment|// it behaves like ADD_FAILURE.  In particular:
comment|//
comment|//   EXPECT_TRUE  verifies that a Boolean condition is true.
comment|//   EXPECT_FALSE verifies that a Boolean condition is false.
comment|//
comment|// FAIL and ASSERT_* are similar to ADD_FAILURE and EXPECT_*, except
comment|// that they will also abort the current function on failure.  People
comment|// usually want the fail-fast behavior of FAIL and ASSERT_*, but those
comment|// writing data-driven tests often find themselves using ADD_FAILURE
comment|// and EXPECT_* more.
comment|//
comment|// Examples:
comment|//
comment|//   EXPECT_TRUE(server.StatusIsOK());
comment|//   ASSERT_FALSE(server.HasPendingRequest(port))
comment|//<< "There are still pending requests "<< "on port "<< port;
comment|// Generates a nonfatal failure with a generic message.
define|#
directive|define
name|ADD_FAILURE
parameter_list|()
value|GTEST_NONFATAL_FAILURE_("Failed")
comment|// Generates a fatal failure with a generic message.
define|#
directive|define
name|FAIL
parameter_list|()
value|GTEST_FATAL_FAILURE_("Failed")
comment|// Generates a success with a generic message.
define|#
directive|define
name|SUCCEED
parameter_list|()
value|GTEST_SUCCESS_("Succeeded")
comment|// Macros for testing exceptions.
comment|//
comment|//    * {ASSERT|EXPECT}_THROW(statement, expected_exception):
comment|//         Tests that the statement throws the expected exception.
comment|//    * {ASSERT|EXPECT}_NO_THROW(statement):
comment|//         Tests that the statement doesn't throw any exception.
comment|//    * {ASSERT|EXPECT}_ANY_THROW(statement):
comment|//         Tests that the statement throws an exception.
define|#
directive|define
name|EXPECT_THROW
parameter_list|(
name|statement
parameter_list|,
name|expected_exception
parameter_list|)
define|\
value|GTEST_TEST_THROW_(statement, expected_exception, GTEST_NONFATAL_FAILURE_)
define|#
directive|define
name|EXPECT_NO_THROW
parameter_list|(
name|statement
parameter_list|)
define|\
value|GTEST_TEST_NO_THROW_(statement, GTEST_NONFATAL_FAILURE_)
define|#
directive|define
name|EXPECT_ANY_THROW
parameter_list|(
name|statement
parameter_list|)
define|\
value|GTEST_TEST_ANY_THROW_(statement, GTEST_NONFATAL_FAILURE_)
define|#
directive|define
name|ASSERT_THROW
parameter_list|(
name|statement
parameter_list|,
name|expected_exception
parameter_list|)
define|\
value|GTEST_TEST_THROW_(statement, expected_exception, GTEST_FATAL_FAILURE_)
define|#
directive|define
name|ASSERT_NO_THROW
parameter_list|(
name|statement
parameter_list|)
define|\
value|GTEST_TEST_NO_THROW_(statement, GTEST_FATAL_FAILURE_)
define|#
directive|define
name|ASSERT_ANY_THROW
parameter_list|(
name|statement
parameter_list|)
define|\
value|GTEST_TEST_ANY_THROW_(statement, GTEST_FATAL_FAILURE_)
comment|// Boolean assertions.
define|#
directive|define
name|EXPECT_TRUE
parameter_list|(
name|condition
parameter_list|)
define|\
value|GTEST_TEST_BOOLEAN_(condition, #condition, false, true, \                       GTEST_NONFATAL_FAILURE_)
define|#
directive|define
name|EXPECT_FALSE
parameter_list|(
name|condition
parameter_list|)
define|\
value|GTEST_TEST_BOOLEAN_(!(condition), #condition, true, false, \                       GTEST_NONFATAL_FAILURE_)
define|#
directive|define
name|ASSERT_TRUE
parameter_list|(
name|condition
parameter_list|)
define|\
value|GTEST_TEST_BOOLEAN_(condition, #condition, false, true, \                       GTEST_FATAL_FAILURE_)
define|#
directive|define
name|ASSERT_FALSE
parameter_list|(
name|condition
parameter_list|)
define|\
value|GTEST_TEST_BOOLEAN_(!(condition), #condition, true, false, \                       GTEST_FATAL_FAILURE_)
comment|// Includes the auto-generated header that implements a family of
comment|// generic predicate assertion macros.
include|#
directive|include
file|<gtest/gtest_pred_impl.h>
comment|// Macros for testing equalities and inequalities.
comment|//
comment|//    * {ASSERT|EXPECT}_EQ(expected, actual): Tests that expected == actual
comment|//    * {ASSERT|EXPECT}_NE(v1, v2):           Tests that v1 != v2
comment|//    * {ASSERT|EXPECT}_LT(v1, v2):           Tests that v1< v2
comment|//    * {ASSERT|EXPECT}_LE(v1, v2):           Tests that v1<= v2
comment|//    * {ASSERT|EXPECT}_GT(v1, v2):           Tests that v1> v2
comment|//    * {ASSERT|EXPECT}_GE(v1, v2):           Tests that v1>= v2
comment|//
comment|// When they are not, Google Test prints both the tested expressions and
comment|// their actual values.  The values must be compatible built-in types,
comment|// or you will get a compiler error.  By "compatible" we mean that the
comment|// values can be compared by the respective operator.
comment|//
comment|// Note:
comment|//
comment|//   1. It is possible to make a user-defined type work with
comment|//   {ASSERT|EXPECT}_??(), but that requires overloading the
comment|//   comparison operators and is thus discouraged by the Google C++
comment|//   Usage Guide.  Therefore, you are advised to use the
comment|//   {ASSERT|EXPECT}_TRUE() macro to assert that two objects are
comment|//   equal.
comment|//
comment|//   2. The {ASSERT|EXPECT}_??() macros do pointer comparisons on
comment|//   pointers (in particular, C strings).  Therefore, if you use it
comment|//   with two C strings, you are testing how their locations in memory
comment|//   are related, not how their content is related.  To compare two C
comment|//   strings by content, use {ASSERT|EXPECT}_STR*().
comment|//
comment|//   3. {ASSERT|EXPECT}_EQ(expected, actual) is preferred to
comment|//   {ASSERT|EXPECT}_TRUE(expected == actual), as the former tells you
comment|//   what the actual value is when it fails, and similarly for the
comment|//   other comparisons.
comment|//
comment|//   4. Do not depend on the order in which {ASSERT|EXPECT}_??()
comment|//   evaluate their arguments, which is undefined.
comment|//
comment|//   5. These macros evaluate their arguments exactly once.
comment|//
comment|// Examples:
comment|//
comment|//   EXPECT_NE(5, Foo());
comment|//   EXPECT_EQ(NULL, a_pointer);
comment|//   ASSERT_LT(i, array_size);
comment|//   ASSERT_GT(records.size(), 0)<< "There is no record left.";
define|#
directive|define
name|EXPECT_EQ
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|)
define|\
value|EXPECT_PRED_FORMAT2(::testing::internal:: \                       EqHelper<GTEST_IS_NULL_LITERAL_(expected)>::Compare, \                       expected, actual)
define|#
directive|define
name|EXPECT_NE
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|)
define|\
value|EXPECT_PRED_FORMAT2(::testing::internal::CmpHelperNE, expected, actual)
define|#
directive|define
name|EXPECT_LE
parameter_list|(
name|val1
parameter_list|,
name|val2
parameter_list|)
define|\
value|EXPECT_PRED_FORMAT2(::testing::internal::CmpHelperLE, val1, val2)
define|#
directive|define
name|EXPECT_LT
parameter_list|(
name|val1
parameter_list|,
name|val2
parameter_list|)
define|\
value|EXPECT_PRED_FORMAT2(::testing::internal::CmpHelperLT, val1, val2)
define|#
directive|define
name|EXPECT_GE
parameter_list|(
name|val1
parameter_list|,
name|val2
parameter_list|)
define|\
value|EXPECT_PRED_FORMAT2(::testing::internal::CmpHelperGE, val1, val2)
define|#
directive|define
name|EXPECT_GT
parameter_list|(
name|val1
parameter_list|,
name|val2
parameter_list|)
define|\
value|EXPECT_PRED_FORMAT2(::testing::internal::CmpHelperGT, val1, val2)
define|#
directive|define
name|ASSERT_EQ
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|)
define|\
value|ASSERT_PRED_FORMAT2(::testing::internal:: \                       EqHelper<GTEST_IS_NULL_LITERAL_(expected)>::Compare, \                       expected, actual)
define|#
directive|define
name|ASSERT_NE
parameter_list|(
name|val1
parameter_list|,
name|val2
parameter_list|)
define|\
value|ASSERT_PRED_FORMAT2(::testing::internal::CmpHelperNE, val1, val2)
define|#
directive|define
name|ASSERT_LE
parameter_list|(
name|val1
parameter_list|,
name|val2
parameter_list|)
define|\
value|ASSERT_PRED_FORMAT2(::testing::internal::CmpHelperLE, val1, val2)
define|#
directive|define
name|ASSERT_LT
parameter_list|(
name|val1
parameter_list|,
name|val2
parameter_list|)
define|\
value|ASSERT_PRED_FORMAT2(::testing::internal::CmpHelperLT, val1, val2)
define|#
directive|define
name|ASSERT_GE
parameter_list|(
name|val1
parameter_list|,
name|val2
parameter_list|)
define|\
value|ASSERT_PRED_FORMAT2(::testing::internal::CmpHelperGE, val1, val2)
define|#
directive|define
name|ASSERT_GT
parameter_list|(
name|val1
parameter_list|,
name|val2
parameter_list|)
define|\
value|ASSERT_PRED_FORMAT2(::testing::internal::CmpHelperGT, val1, val2)
comment|// C String Comparisons.  All tests treat NULL and any non-NULL string
comment|// as different.  Two NULLs are equal.
comment|//
comment|//    * {ASSERT|EXPECT}_STREQ(s1, s2):     Tests that s1 == s2
comment|//    * {ASSERT|EXPECT}_STRNE(s1, s2):     Tests that s1 != s2
comment|//    * {ASSERT|EXPECT}_STRCASEEQ(s1, s2): Tests that s1 == s2, ignoring case
comment|//    * {ASSERT|EXPECT}_STRCASENE(s1, s2): Tests that s1 != s2, ignoring case
comment|//
comment|// For wide or narrow string objects, you can use the
comment|// {ASSERT|EXPECT}_??() macros.
comment|//
comment|// Don't depend on the order in which the arguments are evaluated,
comment|// which is undefined.
comment|//
comment|// These macros evaluate their arguments exactly once.
define|#
directive|define
name|EXPECT_STREQ
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|)
define|\
value|EXPECT_PRED_FORMAT2(::testing::internal::CmpHelperSTREQ, expected, actual)
define|#
directive|define
name|EXPECT_STRNE
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
define|\
value|EXPECT_PRED_FORMAT2(::testing::internal::CmpHelperSTRNE, s1, s2)
define|#
directive|define
name|EXPECT_STRCASEEQ
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|)
define|\
value|EXPECT_PRED_FORMAT2(::testing::internal::CmpHelperSTRCASEEQ, expected, actual)
define|#
directive|define
name|EXPECT_STRCASENE
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
define|\
value|EXPECT_PRED_FORMAT2(::testing::internal::CmpHelperSTRCASENE, s1, s2)
define|#
directive|define
name|ASSERT_STREQ
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|)
define|\
value|ASSERT_PRED_FORMAT2(::testing::internal::CmpHelperSTREQ, expected, actual)
define|#
directive|define
name|ASSERT_STRNE
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
define|\
value|ASSERT_PRED_FORMAT2(::testing::internal::CmpHelperSTRNE, s1, s2)
define|#
directive|define
name|ASSERT_STRCASEEQ
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|)
define|\
value|ASSERT_PRED_FORMAT2(::testing::internal::CmpHelperSTRCASEEQ, expected, actual)
define|#
directive|define
name|ASSERT_STRCASENE
parameter_list|(
name|s1
parameter_list|,
name|s2
parameter_list|)
define|\
value|ASSERT_PRED_FORMAT2(::testing::internal::CmpHelperSTRCASENE, s1, s2)
comment|// Macros for comparing floating-point numbers.
comment|//
comment|//    * {ASSERT|EXPECT}_FLOAT_EQ(expected, actual):
comment|//         Tests that two float values are almost equal.
comment|//    * {ASSERT|EXPECT}_DOUBLE_EQ(expected, actual):
comment|//         Tests that two double values are almost equal.
comment|//    * {ASSERT|EXPECT}_NEAR(v1, v2, abs_error):
comment|//         Tests that v1 and v2 are within the given distance to each other.
comment|//
comment|// Google Test uses ULP-based comparison to automatically pick a default
comment|// error bound that is appropriate for the operands.  See the
comment|// FloatingPoint template class in gtest-internal.h if you are
comment|// interested in the implementation details.
define|#
directive|define
name|EXPECT_FLOAT_EQ
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|)
define|\
value|EXPECT_PRED_FORMAT2(::testing::internal::CmpHelperFloatingPointEQ<float>, \                       expected, actual)
define|#
directive|define
name|EXPECT_DOUBLE_EQ
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|)
define|\
value|EXPECT_PRED_FORMAT2(::testing::internal::CmpHelperFloatingPointEQ<double>, \                       expected, actual)
define|#
directive|define
name|ASSERT_FLOAT_EQ
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|)
define|\
value|ASSERT_PRED_FORMAT2(::testing::internal::CmpHelperFloatingPointEQ<float>, \                       expected, actual)
define|#
directive|define
name|ASSERT_DOUBLE_EQ
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|)
define|\
value|ASSERT_PRED_FORMAT2(::testing::internal::CmpHelperFloatingPointEQ<double>, \                       expected, actual)
define|#
directive|define
name|EXPECT_NEAR
parameter_list|(
name|val1
parameter_list|,
name|val2
parameter_list|,
name|abs_error
parameter_list|)
define|\
value|EXPECT_PRED_FORMAT3(::testing::internal::DoubleNearPredFormat, \                       val1, val2, abs_error)
define|#
directive|define
name|ASSERT_NEAR
parameter_list|(
name|val1
parameter_list|,
name|val2
parameter_list|,
name|abs_error
parameter_list|)
define|\
value|ASSERT_PRED_FORMAT3(::testing::internal::DoubleNearPredFormat, \                       val1, val2, abs_error)
comment|// These predicate format functions work on floating-point values, and
comment|// can be used in {ASSERT|EXPECT}_PRED_FORMAT2*(), e.g.
comment|//
comment|//   EXPECT_PRED_FORMAT2(testing::DoubleLE, Foo(), 5.0);
comment|// Asserts that val1 is less than, or almost equal to, val2.  Fails
comment|// otherwise.  In particular, it fails if either val1 or val2 is NaN.
name|AssertionResult
name|FloatLE
parameter_list|(
specifier|const
name|char
modifier|*
name|expr1
parameter_list|,
specifier|const
name|char
modifier|*
name|expr2
parameter_list|,
name|float
name|val1
parameter_list|,
name|float
name|val2
parameter_list|)
function_decl|;
name|AssertionResult
name|DoubleLE
parameter_list|(
specifier|const
name|char
modifier|*
name|expr1
parameter_list|,
specifier|const
name|char
modifier|*
name|expr2
parameter_list|,
name|double
name|val1
parameter_list|,
name|double
name|val2
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|GTEST_OS_WINDOWS
comment|// Macros that test for HRESULT failure and success, these are only useful
comment|// on Windows, and rely on Windows SDK macros and APIs to compile.
comment|//
comment|//    * {ASSERT|EXPECT}_HRESULT_{SUCCEEDED|FAILED}(expr)
comment|//
comment|// When expr unexpectedly fails or succeeds, Google Test prints the
comment|// expected result and the actual result with both a human-readable
comment|// string representation of the error, if available, as well as the
comment|// hex result code.
define|#
directive|define
name|EXPECT_HRESULT_SUCCEEDED
parameter_list|(
name|expr
parameter_list|)
define|\
value|EXPECT_PRED_FORMAT1(::testing::internal::IsHRESULTSuccess, (expr))
define|#
directive|define
name|ASSERT_HRESULT_SUCCEEDED
parameter_list|(
name|expr
parameter_list|)
define|\
value|ASSERT_PRED_FORMAT1(::testing::internal::IsHRESULTSuccess, (expr))
define|#
directive|define
name|EXPECT_HRESULT_FAILED
parameter_list|(
name|expr
parameter_list|)
define|\
value|EXPECT_PRED_FORMAT1(::testing::internal::IsHRESULTFailure, (expr))
define|#
directive|define
name|ASSERT_HRESULT_FAILED
parameter_list|(
name|expr
parameter_list|)
define|\
value|ASSERT_PRED_FORMAT1(::testing::internal::IsHRESULTFailure, (expr))
endif|#
directive|endif
comment|// GTEST_OS_WINDOWS
comment|// Macros that execute statement and check that it doesn't generate new fatal
comment|// failures in the current thread.
comment|//
comment|//   * {ASSERT|EXPECT}_NO_FATAL_FAILURE(statement);
comment|//
comment|// Examples:
comment|//
comment|//   EXPECT_NO_FATAL_FAILURE(Process());
comment|//   ASSERT_NO_FATAL_FAILURE(Process())<< "Process() failed";
comment|//
define|#
directive|define
name|ASSERT_NO_FATAL_FAILURE
parameter_list|(
name|statement
parameter_list|)
define|\
value|GTEST_TEST_NO_FATAL_FAILURE_(statement, GTEST_FATAL_FAILURE_)
define|#
directive|define
name|EXPECT_NO_FATAL_FAILURE
parameter_list|(
name|statement
parameter_list|)
define|\
value|GTEST_TEST_NO_FATAL_FAILURE_(statement, GTEST_NONFATAL_FAILURE_)
comment|// Causes a trace (including the source file path, the current line
comment|// number, and the given message) to be included in every test failure
comment|// message generated by code in the current scope.  The effect is
comment|// undone when the control leaves the current scope.
comment|//
comment|// The message argument can be anything streamable to std::ostream.
comment|//
comment|// In the implementation, we include the current line number as part
comment|// of the dummy variable name, thus allowing multiple SCOPED_TRACE()s
comment|// to appear in the same block - as long as they are on different
comment|// lines.
define|#
directive|define
name|SCOPED_TRACE
parameter_list|(
name|message
parameter_list|)
define|\
value|::testing::internal::ScopedTrace GTEST_CONCAT_TOKEN_(gtest_trace_, __LINE__)(\     __FILE__, __LINE__, ::testing::Message()<< (message))
comment|// Defines a test.
comment|//
comment|// The first parameter is the name of the test case, and the second
comment|// parameter is the name of the test within the test case.
comment|//
comment|// The convention is to end the test case name with "Test".  For
comment|// example, a test case for the Foo class can be named FooTest.
comment|//
comment|// The user should put his test code between braces after using this
comment|// macro.  Example:
comment|//
comment|//   TEST(FooTest, InitializesCorrectly) {
comment|//     Foo foo;
comment|//     EXPECT_TRUE(foo.StatusIsOK());
comment|//   }
comment|// Note that we call GetTestTypeId() instead of GetTypeId<
comment|// ::testing::Test>() here to get the type ID of testing::Test.  This
comment|// is to work around a suspected linker bug when using Google Test as
comment|// a framework on Mac OS X.  The bug causes GetTypeId<
comment|// ::testing::Test>() to return different values depending on whether
comment|// the call is from the Google Test framework itself or from user test
comment|// code.  GetTestTypeId() is guaranteed to always return the same
comment|// value, as it always calls GetTypeId<>() from the Google Test
comment|// framework.
define|#
directive|define
name|TEST
parameter_list|(
name|test_case_name
parameter_list|,
name|test_name
parameter_list|)
define|\
value|GTEST_TEST_(test_case_name, test_name,\               ::testing::Test, ::testing::internal::GetTestTypeId())
comment|// Defines a test that uses a test fixture.
comment|//
comment|// The first parameter is the name of the test fixture class, which
comment|// also doubles as the test case name.  The second parameter is the
comment|// name of the test within the test case.
comment|//
comment|// A test fixture class must be declared earlier.  The user should put
comment|// his test code between braces after using this macro.  Example:
comment|//
comment|//   class FooTest : public testing::Test {
comment|//    protected:
comment|//     virtual void SetUp() { b_.AddElement(3); }
comment|//
comment|//     Foo a_;
comment|//     Foo b_;
comment|//   };
comment|//
comment|//   TEST_F(FooTest, InitializesCorrectly) {
comment|//     EXPECT_TRUE(a_.StatusIsOK());
comment|//   }
comment|//
comment|//   TEST_F(FooTest, ReturnsElementCountCorrectly) {
comment|//     EXPECT_EQ(0, a_.size());
comment|//     EXPECT_EQ(1, b_.size());
comment|//   }
define|#
directive|define
name|TEST_F
parameter_list|(
name|test_fixture
parameter_list|,
name|test_name
parameter_list|)
define|\
value|GTEST_TEST_(test_fixture, test_name, test_fixture,\               ::testing::internal::GetTypeId<test_fixture>())
comment|// Use this macro in main() to run all tests.  It returns 0 if all
comment|// tests are successful, or 1 otherwise.
comment|//
comment|// RUN_ALL_TESTS() should be invoked after the command line has been
comment|// parsed by InitGoogleTest().
define|#
directive|define
name|RUN_ALL_TESTS
parameter_list|()
define|\
value|(::testing::UnitTest::GetInstance()->Run())
block|}
end_decl_stmt

begin_comment
comment|// namespace testing
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_INCLUDE_GTEST_GTEST_H_
end_comment

end_unit

