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

begin_include
include|#
directive|include
file|<limits>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|"gtest/internal/gtest-internal.h"
end_include

begin_include
include|#
directive|include
file|"gtest/internal/gtest-string.h"
end_include

begin_include
include|#
directive|include
file|"gtest/gtest-death-test.h"
end_include

begin_include
include|#
directive|include
file|"gtest/gtest-message.h"
end_include

begin_include
include|#
directive|include
file|"gtest/gtest-param-test.h"
end_include

begin_include
include|#
directive|include
file|"gtest/gtest-printers.h"
end_include

begin_include
include|#
directive|include
file|"gtest/gtest_prod.h"
end_include

begin_include
include|#
directive|include
file|"gtest/gtest-test-part.h"
end_include

begin_include
include|#
directive|include
file|"gtest/gtest-typed-test.h"
end_include

begin_comment
comment|// Depending on the platform, different string classes are available.
end_comment

begin_comment
comment|// On Linux, in addition to ::std::string, Google also makes use of
end_comment

begin_comment
comment|// class ::string, which has the same interface as ::std::string, but
end_comment

begin_comment
comment|// has a different implementation.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The user can define GTEST_HAS_GLOBAL_STRING to 1 to indicate that
end_comment

begin_comment
comment|// ::string is available AND is a distinct type to ::std::string, or
end_comment

begin_comment
comment|// define it to 0 to indicate otherwise.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// If the user's ::std::string and ::string are the same class due to
end_comment

begin_comment
comment|// aliasing, he should define GTEST_HAS_GLOBAL_STRING to 0.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// If the user doesn't define GTEST_HAS_GLOBAL_STRING, it is defined
end_comment

begin_comment
comment|// heuristically.
end_comment

begin_decl_stmt
name|namespace
name|testing
block|{
comment|// Declares the flags.
comment|// This flag temporary enables the disabled tests.
name|GTEST_DECLARE_bool_
argument_list|(
name|also_run_disabled_tests
argument_list|)
expr_stmt|;
comment|// This flag brings the debugger on an assertion failure.
name|GTEST_DECLARE_bool_
argument_list|(
name|break_on_failure
argument_list|)
expr_stmt|;
comment|// This flag controls whether Google Test catches all test-thrown exceptions
comment|// and logs them as failures.
name|GTEST_DECLARE_bool_
argument_list|(
name|catch_exceptions
argument_list|)
expr_stmt|;
comment|// This flag enables using colors in terminal output. Available values are
comment|// "yes" to enable colors, "no" (disable colors), or "auto" (the default)
comment|// to let Google Test decide.
name|GTEST_DECLARE_string_
argument_list|(
name|color
argument_list|)
expr_stmt|;
comment|// This flag sets up the filter to select by name using a glob pattern
comment|// the tests to run. If the filter is not given all tests are executed.
name|GTEST_DECLARE_string_
argument_list|(
name|filter
argument_list|)
expr_stmt|;
comment|// This flag causes the Google Test to list tests. None of the tests listed
comment|// are actually run if the flag is provided.
name|GTEST_DECLARE_bool_
argument_list|(
name|list_tests
argument_list|)
expr_stmt|;
comment|// This flag controls whether Google Test emits a detailed XML report to a file
comment|// in addition to its normal textual output.
name|GTEST_DECLARE_string_
argument_list|(
name|output
argument_list|)
expr_stmt|;
comment|// This flags control whether Google Test prints the elapsed time for each
comment|// test.
name|GTEST_DECLARE_bool_
argument_list|(
name|print_time
argument_list|)
expr_stmt|;
comment|// This flag specifies the random number seed.
name|GTEST_DECLARE_int32_
argument_list|(
name|random_seed
argument_list|)
expr_stmt|;
comment|// This flag sets how many times the tests are repeated. The default value
comment|// is 1. If the value is -1 the tests are repeating forever.
name|GTEST_DECLARE_int32_
argument_list|(
name|repeat
argument_list|)
expr_stmt|;
comment|// This flag controls whether Google Test includes Google Test internal
comment|// stack frames in failure stack traces.
name|GTEST_DECLARE_bool_
argument_list|(
name|show_internal_stack_frames
argument_list|)
expr_stmt|;
comment|// When this flag is specified, tests' order is randomized on every iteration.
name|GTEST_DECLARE_bool_
argument_list|(
name|shuffle
argument_list|)
expr_stmt|;
comment|// This flag specifies the maximum number of stack frames to be
comment|// printed in a failure message.
name|GTEST_DECLARE_int32_
argument_list|(
name|stack_trace_depth
argument_list|)
expr_stmt|;
comment|// When this flag is specified, a failed assertion will throw an
comment|// exception if exceptions are enabled, or exit the program with a
comment|// non-zero code otherwise.
name|GTEST_DECLARE_bool_
argument_list|(
name|throw_on_failure
argument_list|)
expr_stmt|;
comment|// When this flag is set with a "host:port" string, on supported
comment|// platforms test results are streamed to the specified port on
comment|// the specified host machine.
name|GTEST_DECLARE_string_
argument_list|(
name|stream_result_to
argument_list|)
expr_stmt|;
comment|// The upper limit for valid stack trace depths.
specifier|const
name|int
name|kMaxStackTraceDepth
init|=
literal|100
decl_stmt|;
name|namespace
name|internal
block|{
name|class
name|AssertHelper
decl_stmt|;
name|class
name|DefaultGlobalTestPartResultReporter
decl_stmt|;
name|class
name|ExecDeathTest
decl_stmt|;
name|class
name|NoExecDeathTest
decl_stmt|;
name|class
name|FinalSuccessChecker
decl_stmt|;
name|class
name|GTestFlagSaver
decl_stmt|;
name|class
name|TestResultAccessor
decl_stmt|;
name|class
name|TestEventListenersAccessor
decl_stmt|;
name|class
name|TestEventRepeater
decl_stmt|;
name|class
name|WindowsDeathTest
decl_stmt|;
name|class
name|UnitTestImpl
modifier|*
name|GetUnitTestImpl
parameter_list|()
function_decl|;
name|void
name|ReportFailureInUnknownLocation
argument_list|(
name|TestPartResult
operator|::
name|Type
name|result_type
argument_list|,
specifier|const
name|String
operator|&
name|message
argument_list|)
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
comment|// The friend relationship of some of these classes is cyclic.
comment|// If we don't forward declare them the compiler might confuse the classes
comment|// in friendship clauses with same named classes on the scope.
name|class
name|Test
decl_stmt|;
name|class
name|TestCase
decl_stmt|;
name|class
name|TestInfo
decl_stmt|;
name|class
name|UnitTest
decl_stmt|;
comment|// A class for indicating whether an assertion was successful.  When
comment|// the assertion wasn't successful, the AssertionResult object
comment|// remembers a non-empty message that describes how it failed.
comment|//
comment|// To create an instance of this class, use one of the factory functions
comment|// (AssertionSuccess() and AssertionFailure()).
comment|//
comment|// This class is useful for two purposes:
comment|//   1. Defining predicate functions to be used with Boolean test assertions
comment|//      EXPECT_TRUE/EXPECT_FALSE and their ASSERT_ counterparts
comment|//   2. Defining predicate-format functions to be
comment|//      used with predicate assertions (ASSERT_PRED_FORMAT*, etc).
comment|//
comment|// For example, if you define IsEven predicate:
comment|//
comment|//   testing::AssertionResult IsEven(int n) {
comment|//     if ((n % 2) == 0)
comment|//       return testing::AssertionSuccess();
comment|//     else
comment|//       return testing::AssertionFailure()<< n<< " is odd";
comment|//   }
comment|//
comment|// Then the failed expectation EXPECT_TRUE(IsEven(Fib(5)))
comment|// will print the message
comment|//
comment|//   Value of: IsEven(Fib(5))
comment|//     Actual: false (5 is odd)
comment|//   Expected: true
comment|//
comment|// instead of a more opaque
comment|//
comment|//   Value of: IsEven(Fib(5))
comment|//     Actual: false
comment|//   Expected: true
comment|//
comment|// in case IsEven is a simple Boolean predicate.
comment|//
comment|// If you expect your predicate to be reused and want to support informative
comment|// messages in EXPECT_FALSE and ASSERT_FALSE (negative assertions show up
comment|// about half as often as positive ones in our tests), supply messages for
comment|// both success and failure cases:
comment|//
comment|//   testing::AssertionResult IsEven(int n) {
comment|//     if ((n % 2) == 0)
comment|//       return testing::AssertionSuccess()<< n<< " is even";
comment|//     else
comment|//       return testing::AssertionFailure()<< n<< " is odd";
comment|//   }
comment|//
comment|// Then a statement EXPECT_FALSE(IsEven(Fib(6))) will print
comment|//
comment|//   Value of: IsEven(Fib(6))
comment|//     Actual: true (8 is even)
comment|//   Expected: false
comment|//
comment|// NB: Predicates that support negative Boolean assertions have reduced
comment|// performance in positive ones so be careful not to use them in tests
comment|// that have lots (tens of thousands) of positive Boolean assertions.
comment|//
comment|// To use this class with EXPECT_PRED_FORMAT assertions such as:
comment|//
comment|//   // Verifies that Foo() returns an even number.
comment|//   EXPECT_PRED_FORMAT1(IsEven, Foo());
comment|//
comment|// you need to define:
comment|//
comment|//   testing::AssertionResult IsEven(const char* expr, int n) {
comment|//     if ((n % 2) == 0)
comment|//       return testing::AssertionSuccess();
comment|//     else
comment|//       return testing::AssertionFailure()
comment|//<< "Expected: "<< expr<< " is even\n  Actual: it's "<< n;
comment|//   }
comment|//
comment|// If Foo() returns 5, you will see the following message:
comment|//
comment|//   Expected: Foo() is even
comment|//     Actual: it's 5
comment|//
name|class
name|GTEST_API_
name|AssertionResult
block|{
name|public
label|:
comment|// Copy constructor.
comment|// Used in EXPECT_TRUE/FALSE(assertion_result).
name|AssertionResult
argument_list|(
specifier|const
name|AssertionResult
operator|&
name|other
argument_list|)
expr_stmt|;
comment|// Used in the EXPECT_TRUE/FALSE(bool_expression).
name|explicit
name|AssertionResult
argument_list|(
argument|bool success
argument_list|)
block|:
name|success_
argument_list|(
argument|success
argument_list|)
block|{}
comment|// Returns true iff the assertion succeeded.
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|success_
return|;
block|}
comment|// NOLINT
comment|// Returns the assertion's negation. Used with EXPECT/ASSERT_FALSE.
name|AssertionResult
name|operator
operator|!
operator|(
operator|)
specifier|const
expr_stmt|;
comment|// Returns the text streamed into this AssertionResult. Test assertions
comment|// use it when they fail (i.e., the predicate's outcome doesn't match the
comment|// assertion's expectation). When nothing has been streamed into the
comment|// object, returns an empty string.
specifier|const
name|char
operator|*
name|message
argument_list|()
specifier|const
block|{
return|return
name|message_
operator|.
name|get
argument_list|()
operator|!=
name|NULL
operator|?
name|message_
operator|->
name|c_str
argument_list|()
operator|:
literal|""
return|;
block|}
comment|// TODO(vladl@google.com): Remove this after making sure no clients use it.
comment|// Deprecated; please use message() instead.
specifier|const
name|char
operator|*
name|failure_message
argument_list|()
specifier|const
block|{
return|return
name|message
argument_list|()
return|;
block|}
comment|// Streams a custom failure message into this object.
name|template
operator|<
name|typename
name|T
operator|>
name|AssertionResult
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|T
operator|&
name|value
operator|)
block|{
name|AppendMessage
argument_list|(
name|Message
argument_list|()
operator|<<
name|value
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
comment|// Allows streaming basic output manipulators such as endl or flush into
comment|// this object.
name|AssertionResult
operator|&
name|operator
operator|<<
operator|(
operator|::
name|std
operator|::
name|ostream
operator|&
call|(
modifier|*
name|basic_manipulator
call|)
argument_list|(
operator|::
name|std
operator|::
name|ostream
operator|&
name|stream
argument_list|)
operator|)
block|{
name|AppendMessage
argument_list|(
name|Message
argument_list|()
operator|<<
name|basic_manipulator
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|private
label|:
comment|// Appends the contents of message to message_.
name|void
name|AppendMessage
parameter_list|(
specifier|const
name|Message
modifier|&
name|a_message
parameter_list|)
block|{
if|if
condition|(
name|message_
operator|.
name|get
argument_list|()
operator|==
name|NULL
condition|)
name|message_
operator|.
name|reset
argument_list|(
name|new
operator|::
name|std
operator|::
name|string
argument_list|)
expr_stmt|;
name|message_
operator|->
name|append
argument_list|(
name|a_message
operator|.
name|GetString
argument_list|()
operator|.
name|c_str
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|// Stores result of the assertion predicate.
name|bool
name|success_
decl_stmt|;
comment|// Stores the message describing the condition in case the expectation
comment|// construct is not satisfied with the predicate's outcome.
comment|// Referenced via a pointer to avoid taking too much stack frame space
comment|// with test assertions.
name|internal
operator|::
name|scoped_ptr
operator|<
operator|::
name|std
operator|::
name|string
operator|>
name|message_
expr_stmt|;
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|AssertionResult
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
comment|// Makes a successful assertion result.
name|GTEST_API_
name|AssertionResult
name|AssertionSuccess
parameter_list|()
function_decl|;
comment|// Makes a failed assertion result.
name|GTEST_API_
name|AssertionResult
name|AssertionFailure
parameter_list|()
function_decl|;
comment|// Makes a failed assertion result with the given failure message.
comment|// Deprecated; use AssertionFailure()<< msg.
name|GTEST_API_
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
name|GTEST_API_
name|Test
block|{
name|public
label|:
name|friend
name|class
name|TestInfo
decl_stmt|;
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
comment|// Returns true iff the current test has a non-fatal failure.
specifier|static
name|bool
name|HasNonfatalFailure
parameter_list|()
function_decl|;
comment|// Returns true iff the current test has a (either fatal or
comment|// non-fatal) failure.
specifier|static
name|bool
name|HasFailure
parameter_list|()
block|{
return|return
name|HasFatalFailure
argument_list|()
operator|||
name|HasNonfatalFailure
argument_list|()
return|;
block|}
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
comment|// Deletes self.  We deliberately pick an unusual name for this
comment|// internal method to avoid clashing with names used in user TESTs.
name|void
name|DeleteSelf_
parameter_list|()
block|{
name|delete
name|this
decl_stmt|;
block|}
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
typedef|typedef
name|internal
operator|::
name|TimeInMillis
name|TimeInMillis
expr_stmt|;
comment|// A copyable object representing a user specified test property which can be
comment|// output as a key/value string pair.
comment|//
comment|// Don't inherit from TestProperty as its destructor is not virtual.
name|class
name|TestProperty
block|{
name|public
label|:
comment|// C'tor.  TestProperty does NOT have a default constructor.
comment|// Always use this constructor (with parameters) to create a
comment|// TestProperty object.
name|TestProperty
argument_list|(
specifier|const
name|char
operator|*
name|a_key
argument_list|,
specifier|const
name|char
operator|*
name|a_value
argument_list|)
operator|:
name|key_
argument_list|(
name|a_key
argument_list|)
operator|,
name|value_
argument_list|(
argument|a_value
argument_list|)
block|{   }
comment|// Gets the user supplied key.
specifier|const
name|char
operator|*
name|key
argument_list|()
specifier|const
block|{
return|return
name|key_
operator|.
name|c_str
argument_list|()
return|;
block|}
comment|// Gets the user supplied value.
specifier|const
name|char
operator|*
name|value
argument_list|()
specifier|const
block|{
return|return
name|value_
operator|.
name|c_str
argument_list|()
return|;
block|}
comment|// Sets a new value, overriding the one supplied in the constructor.
name|void
name|SetValue
parameter_list|(
specifier|const
name|char
modifier|*
name|new_value
parameter_list|)
block|{
name|value_
operator|=
name|new_value
expr_stmt|;
block|}
name|private
label|:
comment|// The key supplied by the user.
name|internal
operator|::
name|String
name|key_
expr_stmt|;
comment|// The value supplied by the user.
name|internal
operator|::
name|String
name|value_
expr_stmt|;
block|}
empty_stmt|;
comment|// The result of a single Test.  This includes a list of
comment|// TestPartResults, a list of TestProperties, a count of how many
comment|// death tests there are in the Test, and how much time it took to run
comment|// the Test.
comment|//
comment|// TestResult is not copyable.
name|class
name|GTEST_API_
name|TestResult
block|{
name|public
label|:
comment|// Creates an empty TestResult.
name|TestResult
argument_list|()
expr_stmt|;
comment|// D'tor.  Do not inherit from TestResult.
operator|~
name|TestResult
argument_list|()
expr_stmt|;
comment|// Gets the number of all test parts.  This is the sum of the number
comment|// of successful test parts and the number of failed test parts.
name|int
name|total_part_count
argument_list|()
specifier|const
expr_stmt|;
comment|// Returns the number of the test properties.
name|int
name|test_property_count
argument_list|()
specifier|const
expr_stmt|;
comment|// Returns true iff the test passed (i.e. no test part failed).
name|bool
name|Passed
argument_list|()
specifier|const
block|{
return|return
operator|!
name|Failed
argument_list|()
return|;
block|}
comment|// Returns true iff the test failed.
name|bool
name|Failed
argument_list|()
specifier|const
expr_stmt|;
comment|// Returns true iff the test fatally failed.
name|bool
name|HasFatalFailure
argument_list|()
specifier|const
expr_stmt|;
comment|// Returns true iff the test has a non-fatal failure.
name|bool
name|HasNonfatalFailure
argument_list|()
specifier|const
expr_stmt|;
comment|// Returns the elapsed time, in milliseconds.
name|TimeInMillis
name|elapsed_time
argument_list|()
specifier|const
block|{
return|return
name|elapsed_time_
return|;
block|}
comment|// Returns the i-th test part result among all the results. i can range
comment|// from 0 to test_property_count() - 1. If i is not in that range, aborts
comment|// the program.
specifier|const
name|TestPartResult
modifier|&
name|GetTestPartResult
argument_list|(
name|int
name|i
argument_list|)
decl|const
decl_stmt|;
comment|// Returns the i-th test property. i can range from 0 to
comment|// test_property_count() - 1. If i is not in that range, aborts the
comment|// program.
specifier|const
name|TestProperty
modifier|&
name|GetTestProperty
argument_list|(
name|int
name|i
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|friend
name|class
name|TestInfo
decl_stmt|;
name|friend
name|class
name|UnitTest
decl_stmt|;
name|friend
name|class
name|internal
operator|::
name|DefaultGlobalTestPartResultReporter
expr_stmt|;
name|friend
name|class
name|internal
operator|::
name|ExecDeathTest
expr_stmt|;
name|friend
name|class
name|internal
operator|::
name|TestResultAccessor
expr_stmt|;
name|friend
name|class
name|internal
operator|::
name|UnitTestImpl
expr_stmt|;
name|friend
name|class
name|internal
operator|::
name|WindowsDeathTest
expr_stmt|;
comment|// Gets the vector of TestPartResults.
specifier|const
name|std
operator|::
name|vector
operator|<
name|TestPartResult
operator|>
operator|&
name|test_part_results
argument_list|()
specifier|const
block|{
return|return
name|test_part_results_
return|;
block|}
comment|// Gets the vector of TestProperties.
specifier|const
name|std
operator|::
name|vector
operator|<
name|TestProperty
operator|>
operator|&
name|test_properties
argument_list|()
specifier|const
block|{
return|return
name|test_properties_
return|;
block|}
comment|// Sets the elapsed time.
name|void
name|set_elapsed_time
parameter_list|(
name|TimeInMillis
name|elapsed
parameter_list|)
block|{
name|elapsed_time_
operator|=
name|elapsed
expr_stmt|;
block|}
comment|// Adds a test property to the list. The property is validated and may add
comment|// a non-fatal failure if invalid (e.g., if it conflicts with reserved
comment|// key names). If a property is already recorded for the same key, the
comment|// value will be updated, rather than storing multiple values for the same
comment|// key.
name|void
name|RecordProperty
parameter_list|(
specifier|const
name|TestProperty
modifier|&
name|test_property
parameter_list|)
function_decl|;
comment|// Adds a failure if the key is a reserved attribute of Google Test
comment|// testcase tags.  Returns true if the property is valid.
comment|// TODO(russr): Validate attribute names are legal and human readable.
specifier|static
name|bool
name|ValidateTestProperty
parameter_list|(
specifier|const
name|TestProperty
modifier|&
name|test_property
parameter_list|)
function_decl|;
comment|// Adds a test part result to the list.
name|void
name|AddTestPartResult
parameter_list|(
specifier|const
name|TestPartResult
modifier|&
name|test_part_result
parameter_list|)
function_decl|;
comment|// Returns the death test count.
name|int
name|death_test_count
argument_list|()
specifier|const
block|{
return|return
name|death_test_count_
return|;
block|}
comment|// Increments the death test count, returning the new count.
name|int
name|increment_death_test_count
parameter_list|()
block|{
return|return
operator|++
name|death_test_count_
return|;
block|}
comment|// Clears the test part results.
name|void
name|ClearTestPartResults
parameter_list|()
function_decl|;
comment|// Clears the object.
name|void
name|Clear
parameter_list|()
function_decl|;
comment|// Protects mutable state of the property vector and of owned
comment|// properties, whose values may be updated.
name|internal
operator|::
name|Mutex
name|test_properites_mutex_
expr_stmt|;
comment|// The vector of TestPartResults
name|std
operator|::
name|vector
operator|<
name|TestPartResult
operator|>
name|test_part_results_
expr_stmt|;
comment|// The vector of TestProperties
name|std
operator|::
name|vector
operator|<
name|TestProperty
operator|>
name|test_properties_
expr_stmt|;
comment|// Running count of death tests.
name|int
name|death_test_count_
decl_stmt|;
comment|// The elapsed time, in milliseconds.
name|TimeInMillis
name|elapsed_time_
decl_stmt|;
comment|// We disallow copying TestResult.
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|TestResult
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
comment|// class TestResult
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
name|GTEST_API_
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
block|{
return|return
name|test_case_name_
operator|.
name|c_str
argument_list|()
return|;
block|}
comment|// Returns the test name.
specifier|const
name|char
operator|*
name|name
argument_list|()
specifier|const
block|{
return|return
name|name_
operator|.
name|c_str
argument_list|()
return|;
block|}
comment|// Returns the name of the parameter type, or NULL if this is not a typed
comment|// or a type-parameterized test.
specifier|const
name|char
operator|*
name|type_param
argument_list|()
specifier|const
block|{
if|if
condition|(
name|type_param_
operator|.
name|get
argument_list|()
operator|!=
name|NULL
condition|)
return|return
name|type_param_
operator|->
name|c_str
argument_list|()
return|;
return|return
name|NULL
return|;
block|}
comment|// Returns the text representation of the value parameter, or NULL if this
comment|// is not a value-parameterized test.
specifier|const
name|char
operator|*
name|value_param
argument_list|()
specifier|const
block|{
if|if
condition|(
name|value_param_
operator|.
name|get
argument_list|()
operator|!=
name|NULL
condition|)
return|return
name|value_param_
operator|->
name|c_str
argument_list|()
return|;
return|return
name|NULL
return|;
block|}
end_decl_stmt

begin_comment
comment|// Returns true if this test should run, that is if the test is not disabled
end_comment

begin_comment
comment|// (or it is disabled but the also_run_disabled_tests flag has been specified)
end_comment

begin_comment
comment|// and its full name matches the user-specified filter.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Google Test allows the user to filter the tests by their full names.
end_comment

begin_comment
comment|// The full name of a test Bar in test case Foo is defined as
end_comment

begin_comment
comment|// "Foo.Bar".  Only the tests that match the filter will run.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// A filter is a colon-separated list of glob (not regex) patterns,
end_comment

begin_comment
comment|// optionally followed by a '-' and a colon-separated list of
end_comment

begin_comment
comment|// negative patterns (tests to exclude).  A test is run if it
end_comment

begin_comment
comment|// matches one of the positive patterns and does not match any of
end_comment

begin_comment
comment|// the negative patterns.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// For example, *A*:Foo.* is a filter that matches any string that
end_comment

begin_comment
comment|// contains the character 'A' or starts with "Foo.".
end_comment

begin_expr_stmt
name|bool
name|should_run
argument_list|()
specifier|const
block|{
return|return
name|should_run_
return|;
block|}
end_expr_stmt

begin_comment
comment|// Returns the result of the test.
end_comment

begin_expr_stmt
specifier|const
name|TestResult
operator|*
name|result
argument_list|()
specifier|const
block|{
return|return
operator|&
name|result_
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_if
if|#
directive|if
name|GTEST_HAS_DEATH_TEST
end_if

begin_expr_stmt
name|friend
name|class
name|internal
operator|::
name|DefaultDeathTestFactory
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_HAS_DEATH_TEST
end_comment

begin_decl_stmt
name|friend
name|class
name|Test
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|TestCase
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|friend
name|class
name|internal
operator|::
name|UnitTestImpl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
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
argument|const char* type_param
argument_list|,
argument|const char* value_param
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
end_expr_stmt

begin_comment
comment|// Constructs a TestInfo object. The newly constructed instance assumes
end_comment

begin_comment
comment|// ownership of the factory object.
end_comment

begin_macro
name|TestInfo
argument_list|(
argument|const char* test_case_name
argument_list|,
argument|const char* name
argument_list|,
argument|const char* a_type_param
argument_list|,
argument|const char* a_value_param
argument_list|,
argument|internal::TypeId fixture_class_id
argument_list|,
argument|internal::TestFactoryBase* factory
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Increments the number of death tests encountered in this test so
end_comment

begin_comment
comment|// far.
end_comment

begin_function
name|int
name|increment_death_test_count
parameter_list|()
block|{
return|return
name|result_
operator|.
name|increment_death_test_count
argument_list|()
return|;
block|}
end_function

begin_comment
comment|// Creates the test object, runs it, records its result, and then
end_comment

begin_comment
comment|// deletes it.
end_comment

begin_function_decl
name|void
name|Run
parameter_list|()
function_decl|;
end_function_decl

begin_function
specifier|static
name|void
name|ClearTestResult
parameter_list|(
name|TestInfo
modifier|*
name|test_info
parameter_list|)
block|{
name|test_info
operator|->
name|result_
operator|.
name|Clear
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// These fields are immutable properties of the test.
end_comment

begin_expr_stmt
specifier|const
name|std
operator|::
name|string
name|test_case_name_
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Test case name
end_comment

begin_expr_stmt
specifier|const
name|std
operator|::
name|string
name|name_
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Test name
end_comment

begin_comment
comment|// Name of the parameter type, or NULL if this is not a typed or a
end_comment

begin_comment
comment|// type-parameterized test.
end_comment

begin_expr_stmt
specifier|const
name|internal
operator|::
name|scoped_ptr
operator|<
specifier|const
operator|::
name|std
operator|::
name|string
operator|>
name|type_param_
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Text representation of the value parameter, or NULL if this is not a
end_comment

begin_comment
comment|// value-parameterized test.
end_comment

begin_expr_stmt
specifier|const
name|internal
operator|::
name|scoped_ptr
operator|<
specifier|const
operator|::
name|std
operator|::
name|string
operator|>
name|value_param_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|const
name|internal
operator|::
name|TypeId
name|fixture_class_id_
expr_stmt|;
end_expr_stmt

begin_comment
comment|// ID of the test fixture class
end_comment

begin_decl_stmt
name|bool
name|should_run_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// True iff this test should run
end_comment

begin_decl_stmt
name|bool
name|is_disabled_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// True iff this test is disabled
end_comment

begin_decl_stmt
name|bool
name|matches_filter_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// True if this test matches the
end_comment

begin_comment
comment|// user-specified filter.
end_comment

begin_expr_stmt
name|internal
operator|::
name|TestFactoryBase
operator|*
specifier|const
name|factory_
expr_stmt|;
end_expr_stmt

begin_comment
comment|// The factory that creates
end_comment

begin_comment
comment|// the test object
end_comment

begin_comment
comment|// This field is mutable and needs to be reset before running the
end_comment

begin_comment
comment|// test for the second time.
end_comment

begin_decl_stmt
name|TestResult
name|result_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|TestInfo
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// A test case, which consists of a vector of TestInfos.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// TestCase is not copyable.
end_comment

begin_decl_stmt
name|class
name|GTEST_API_
name|TestCase
block|{
name|public
label|:
comment|// Creates a TestCase with the given name.
comment|//
comment|// TestCase does NOT have a default constructor.  Always use this
comment|// constructor to create a TestCase object.
comment|//
comment|// Arguments:
comment|//
comment|//   name:         name of the test case
comment|//   a_type_param: the name of the test's type parameter, or NULL if
comment|//                 this is not a type-parameterized test.
comment|//   set_up_tc:    pointer to the function that sets up the test case
comment|//   tear_down_tc: pointer to the function that tears down the test case
name|TestCase
argument_list|(
argument|const char* name
argument_list|,
argument|const char* a_type_param
argument_list|,
argument|Test::SetUpTestCaseFunc set_up_tc
argument_list|,
argument|Test::TearDownTestCaseFunc tear_down_tc
argument_list|)
empty_stmt|;
comment|// Destructor of TestCase.
name|virtual
operator|~
name|TestCase
argument_list|()
expr_stmt|;
comment|// Gets the name of the TestCase.
specifier|const
name|char
operator|*
name|name
argument_list|()
specifier|const
block|{
return|return
name|name_
operator|.
name|c_str
argument_list|()
return|;
block|}
comment|// Returns the name of the parameter type, or NULL if this is not a
comment|// type-parameterized test case.
specifier|const
name|char
operator|*
name|type_param
argument_list|()
specifier|const
block|{
if|if
condition|(
name|type_param_
operator|.
name|get
argument_list|()
operator|!=
name|NULL
condition|)
return|return
name|type_param_
operator|->
name|c_str
argument_list|()
return|;
return|return
name|NULL
return|;
block|}
end_decl_stmt

begin_comment
comment|// Returns true if any test in this test case should run.
end_comment

begin_expr_stmt
name|bool
name|should_run
argument_list|()
specifier|const
block|{
return|return
name|should_run_
return|;
block|}
end_expr_stmt

begin_comment
comment|// Gets the number of successful tests in this test case.
end_comment

begin_expr_stmt
name|int
name|successful_test_count
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Gets the number of failed tests in this test case.
end_comment

begin_expr_stmt
name|int
name|failed_test_count
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Gets the number of disabled tests in this test case.
end_comment

begin_expr_stmt
name|int
name|disabled_test_count
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Get the number of tests in this test case that should run.
end_comment

begin_expr_stmt
name|int
name|test_to_run_count
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Gets the number of all tests in this test case.
end_comment

begin_expr_stmt
name|int
name|total_test_count
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Returns true iff the test case passed.
end_comment

begin_expr_stmt
name|bool
name|Passed
argument_list|()
specifier|const
block|{
return|return
operator|!
name|Failed
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|// Returns true iff the test case failed.
end_comment

begin_expr_stmt
name|bool
name|Failed
argument_list|()
specifier|const
block|{
return|return
name|failed_test_count
argument_list|()
operator|>
literal|0
return|;
block|}
end_expr_stmt

begin_comment
comment|// Returns the elapsed time, in milliseconds.
end_comment

begin_expr_stmt
name|TimeInMillis
name|elapsed_time
argument_list|()
specifier|const
block|{
return|return
name|elapsed_time_
return|;
block|}
end_expr_stmt

begin_comment
comment|// Returns the i-th test among all the tests. i can range from 0 to
end_comment

begin_comment
comment|// total_test_count() - 1. If i is not in that range, returns NULL.
end_comment

begin_decl_stmt
specifier|const
name|TestInfo
modifier|*
name|GetTestInfo
argument_list|(
name|int
name|i
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|friend
name|class
name|Test
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|friend
name|class
name|internal
operator|::
name|UnitTestImpl
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Gets the (mutable) vector of TestInfos in this TestCase.
end_comment

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|TestInfo
operator|*
operator|>
operator|&
name|test_info_list
argument_list|()
block|{
return|return
name|test_info_list_
return|;
block|}
end_expr_stmt

begin_comment
comment|// Gets the (immutable) vector of TestInfos in this TestCase.
end_comment

begin_expr_stmt
specifier|const
name|std
operator|::
name|vector
operator|<
name|TestInfo
operator|*
operator|>
operator|&
name|test_info_list
argument_list|()
specifier|const
block|{
return|return
name|test_info_list_
return|;
block|}
end_expr_stmt

begin_comment
comment|// Returns the i-th test among all the tests. i can range from 0 to
end_comment

begin_comment
comment|// total_test_count() - 1. If i is not in that range, returns NULL.
end_comment

begin_function_decl
name|TestInfo
modifier|*
name|GetMutableTestInfo
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Sets the should_run member.
end_comment

begin_function
name|void
name|set_should_run
parameter_list|(
name|bool
name|should
parameter_list|)
block|{
name|should_run_
operator|=
name|should
expr_stmt|;
block|}
end_function

begin_comment
comment|// Adds a TestInfo to this test case.  Will delete the TestInfo upon
end_comment

begin_comment
comment|// destruction of the TestCase object.
end_comment

begin_function_decl
name|void
name|AddTestInfo
parameter_list|(
name|TestInfo
modifier|*
name|test_info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Clears the results of all tests in this test case.
end_comment

begin_function_decl
name|void
name|ClearResult
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Clears the results of all tests in the given test case.
end_comment

begin_function
specifier|static
name|void
name|ClearTestCaseResult
parameter_list|(
name|TestCase
modifier|*
name|test_case
parameter_list|)
block|{
name|test_case
operator|->
name|ClearResult
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// Runs every test in this TestCase.
end_comment

begin_function_decl
name|void
name|Run
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Runs SetUpTestCase() for this TestCase.  This wrapper is needed
end_comment

begin_comment
comment|// for catching exceptions thrown from SetUpTestCase().
end_comment

begin_function
name|void
name|RunSetUpTestCase
parameter_list|()
block|{
call|(
modifier|*
name|set_up_tc_
call|)
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// Runs TearDownTestCase() for this TestCase.  This wrapper is
end_comment

begin_comment
comment|// needed for catching exceptions thrown from TearDownTestCase().
end_comment

begin_function
name|void
name|RunTearDownTestCase
parameter_list|()
block|{
call|(
modifier|*
name|tear_down_tc_
call|)
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// Returns true iff test passed.
end_comment

begin_function
specifier|static
name|bool
name|TestPassed
parameter_list|(
specifier|const
name|TestInfo
modifier|*
name|test_info
parameter_list|)
block|{
return|return
name|test_info
operator|->
name|should_run
argument_list|()
operator|&&
name|test_info
operator|->
name|result
argument_list|()
operator|->
name|Passed
argument_list|()
return|;
block|}
end_function

begin_comment
comment|// Returns true iff test failed.
end_comment

begin_function
specifier|static
name|bool
name|TestFailed
parameter_list|(
specifier|const
name|TestInfo
modifier|*
name|test_info
parameter_list|)
block|{
return|return
name|test_info
operator|->
name|should_run
argument_list|()
operator|&&
name|test_info
operator|->
name|result
argument_list|()
operator|->
name|Failed
argument_list|()
return|;
block|}
end_function

begin_comment
comment|// Returns true iff test is disabled.
end_comment

begin_function
specifier|static
name|bool
name|TestDisabled
parameter_list|(
specifier|const
name|TestInfo
modifier|*
name|test_info
parameter_list|)
block|{
return|return
name|test_info
operator|->
name|is_disabled_
return|;
block|}
end_function

begin_comment
comment|// Returns true if the given test should run.
end_comment

begin_function
specifier|static
name|bool
name|ShouldRunTest
parameter_list|(
specifier|const
name|TestInfo
modifier|*
name|test_info
parameter_list|)
block|{
return|return
name|test_info
operator|->
name|should_run
argument_list|()
return|;
block|}
end_function

begin_comment
comment|// Shuffles the tests in this test case.
end_comment

begin_decl_stmt
name|void
name|ShuffleTests
argument_list|(
name|internal
operator|::
name|Random
operator|*
name|random
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Restores the test order to before the first shuffle.
end_comment

begin_function_decl
name|void
name|UnshuffleTests
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Name of the test case.
end_comment

begin_expr_stmt
name|internal
operator|::
name|String
name|name_
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Name of the parameter type, or NULL if this is not a typed or a
end_comment

begin_comment
comment|// type-parameterized test.
end_comment

begin_expr_stmt
specifier|const
name|internal
operator|::
name|scoped_ptr
operator|<
specifier|const
operator|::
name|std
operator|::
name|string
operator|>
name|type_param_
expr_stmt|;
end_expr_stmt

begin_comment
comment|// The vector of TestInfos in their original order.  It owns the
end_comment

begin_comment
comment|// elements in the vector.
end_comment

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|TestInfo
operator|*
operator|>
name|test_info_list_
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Provides a level of indirection for the test list to allow easy
end_comment

begin_comment
comment|// shuffling and restoring the test order.  The i-th element in this
end_comment

begin_comment
comment|// vector is the index of the i-th test in the shuffled test list.
end_comment

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|int
operator|>
name|test_indices_
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Pointer to the function that sets up the test case.
end_comment

begin_expr_stmt
name|Test
operator|::
name|SetUpTestCaseFunc
name|set_up_tc_
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Pointer to the function that tears down the test case.
end_comment

begin_expr_stmt
name|Test
operator|::
name|TearDownTestCaseFunc
name|tear_down_tc_
expr_stmt|;
end_expr_stmt

begin_comment
comment|// True iff any test in this test case should run.
end_comment

begin_decl_stmt
name|bool
name|should_run_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Elapsed time, in milliseconds.
end_comment

begin_decl_stmt
name|TimeInMillis
name|elapsed_time_
decl_stmt|;
end_decl_stmt

begin_comment
comment|// We disallow copying TestCases.
end_comment

begin_expr_stmt
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|TestCase
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// An Environment object is capable of setting up and tearing down an
end_comment

begin_comment
comment|// environment.  The user should subclass this to define his own
end_comment

begin_comment
comment|// environment(s).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// An Environment object does the set-up and tear-down in virtual
end_comment

begin_comment
comment|// methods SetUp() and TearDown() instead of the constructor and the
end_comment

begin_comment
comment|// destructor, as:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   1. You cannot safely throw from a destructor.  This is a problem
end_comment

begin_comment
comment|//      as in some cases Google Test is used where exceptions are enabled, and
end_comment

begin_comment
comment|//      we may want to implement ASSERT_* using exceptions where they are
end_comment

begin_comment
comment|//      available.
end_comment

begin_comment
comment|//   2. You cannot use ASSERT_* directly in a constructor or
end_comment

begin_comment
comment|//      destructor.
end_comment

begin_decl_stmt
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
expr_stmt|;
comment|// Override this to define how to set up the environment.
name|virtual
name|void
name|SetUp
parameter_list|()
block|{}
comment|// Override this to define how to tear down the environment.
name|virtual
name|void
name|TearDown
parameter_list|()
block|{}
name|private
label|:
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
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// The interface for tracing execution of tests. The methods are organized in
end_comment

begin_comment
comment|// the order the corresponding events are fired.
end_comment

begin_decl_stmt
name|class
name|TestEventListener
block|{
name|public
label|:
name|virtual
operator|~
name|TestEventListener
argument_list|()
expr_stmt|;
comment|// Fired before any test activity starts.
name|virtual
name|void
name|OnTestProgramStart
parameter_list|(
specifier|const
name|UnitTest
modifier|&
name|unit_test
parameter_list|)
init|=
literal|0
function_decl|;
comment|// Fired before each iteration of tests starts.  There may be more than
comment|// one iteration if GTEST_FLAG(repeat) is set. iteration is the iteration
comment|// index, starting from 0.
name|virtual
name|void
name|OnTestIterationStart
parameter_list|(
specifier|const
name|UnitTest
modifier|&
name|unit_test
parameter_list|,
name|int
name|iteration
parameter_list|)
init|=
literal|0
function_decl|;
comment|// Fired before environment set-up for each iteration of tests starts.
name|virtual
name|void
name|OnEnvironmentsSetUpStart
parameter_list|(
specifier|const
name|UnitTest
modifier|&
name|unit_test
parameter_list|)
init|=
literal|0
function_decl|;
comment|// Fired after environment set-up for each iteration of tests ends.
name|virtual
name|void
name|OnEnvironmentsSetUpEnd
parameter_list|(
specifier|const
name|UnitTest
modifier|&
name|unit_test
parameter_list|)
init|=
literal|0
function_decl|;
comment|// Fired before the test case starts.
name|virtual
name|void
name|OnTestCaseStart
parameter_list|(
specifier|const
name|TestCase
modifier|&
name|test_case
parameter_list|)
init|=
literal|0
function_decl|;
comment|// Fired before the test starts.
name|virtual
name|void
name|OnTestStart
parameter_list|(
specifier|const
name|TestInfo
modifier|&
name|test_info
parameter_list|)
init|=
literal|0
function_decl|;
comment|// Fired after a failed assertion or a SUCCEED() invocation.
name|virtual
name|void
name|OnTestPartResult
parameter_list|(
specifier|const
name|TestPartResult
modifier|&
name|test_part_result
parameter_list|)
init|=
literal|0
function_decl|;
comment|// Fired after the test ends.
name|virtual
name|void
name|OnTestEnd
parameter_list|(
specifier|const
name|TestInfo
modifier|&
name|test_info
parameter_list|)
init|=
literal|0
function_decl|;
comment|// Fired after the test case ends.
name|virtual
name|void
name|OnTestCaseEnd
parameter_list|(
specifier|const
name|TestCase
modifier|&
name|test_case
parameter_list|)
init|=
literal|0
function_decl|;
comment|// Fired before environment tear-down for each iteration of tests starts.
name|virtual
name|void
name|OnEnvironmentsTearDownStart
parameter_list|(
specifier|const
name|UnitTest
modifier|&
name|unit_test
parameter_list|)
init|=
literal|0
function_decl|;
comment|// Fired after environment tear-down for each iteration of tests ends.
name|virtual
name|void
name|OnEnvironmentsTearDownEnd
parameter_list|(
specifier|const
name|UnitTest
modifier|&
name|unit_test
parameter_list|)
init|=
literal|0
function_decl|;
comment|// Fired after each iteration of tests finishes.
name|virtual
name|void
name|OnTestIterationEnd
parameter_list|(
specifier|const
name|UnitTest
modifier|&
name|unit_test
parameter_list|,
name|int
name|iteration
parameter_list|)
init|=
literal|0
function_decl|;
comment|// Fired after all test activities have ended.
name|virtual
name|void
name|OnTestProgramEnd
parameter_list|(
specifier|const
name|UnitTest
modifier|&
name|unit_test
parameter_list|)
init|=
literal|0
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// The convenience class for users who need to override just one or two
end_comment

begin_comment
comment|// methods and are not concerned that a possible change to a signature of
end_comment

begin_comment
comment|// the methods they override will not be caught during the build.  For
end_comment

begin_comment
comment|// comments about each method please see the definition of TestEventListener
end_comment

begin_comment
comment|// above.
end_comment

begin_decl_stmt
name|class
name|EmptyTestEventListener
range|:
name|public
name|TestEventListener
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
name|virtual
name|void
name|OnTestProgramStart
argument_list|(
argument|const UnitTest&
comment|/*unit_test*/
argument_list|)
block|{}
name|virtual
name|void
name|OnTestIterationStart
argument_list|(
argument|const UnitTest&
comment|/*unit_test*/
argument_list|,
argument|int
comment|/*iteration*/
argument_list|)
block|{}
name|virtual
name|void
name|OnEnvironmentsSetUpStart
argument_list|(
argument|const UnitTest&
comment|/*unit_test*/
argument_list|)
block|{}
name|virtual
name|void
name|OnEnvironmentsSetUpEnd
argument_list|(
argument|const UnitTest&
comment|/*unit_test*/
argument_list|)
block|{}
name|virtual
name|void
name|OnTestCaseStart
argument_list|(
argument|const TestCase&
comment|/*test_case*/
argument_list|)
block|{}
name|virtual
name|void
name|OnTestStart
argument_list|(
argument|const TestInfo&
comment|/*test_info*/
argument_list|)
block|{}
name|virtual
name|void
name|OnTestPartResult
argument_list|(
argument|const TestPartResult&
comment|/*test_part_result*/
argument_list|)
block|{}
name|virtual
name|void
name|OnTestEnd
argument_list|(
argument|const TestInfo&
comment|/*test_info*/
argument_list|)
block|{}
name|virtual
name|void
name|OnTestCaseEnd
argument_list|(
argument|const TestCase&
comment|/*test_case*/
argument_list|)
block|{}
name|virtual
name|void
name|OnEnvironmentsTearDownStart
argument_list|(
argument|const UnitTest&
comment|/*unit_test*/
argument_list|)
block|{}
name|virtual
name|void
name|OnEnvironmentsTearDownEnd
argument_list|(
argument|const UnitTest&
comment|/*unit_test*/
argument_list|)
block|{}
name|virtual
name|void
name|OnTestIterationEnd
argument_list|(
argument|const UnitTest&
comment|/*unit_test*/
argument_list|,
argument|int
comment|/*iteration*/
argument_list|)
block|{}
name|virtual
name|void
name|OnTestProgramEnd
argument_list|(
argument|const UnitTest&
comment|/*unit_test*/
argument_list|)
block|{}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// TestEventListeners lets users add listeners to track events in Google Test.
end_comment

begin_decl_stmt
name|class
name|GTEST_API_
name|TestEventListeners
block|{
name|public
label|:
name|TestEventListeners
argument_list|()
expr_stmt|;
operator|~
name|TestEventListeners
argument_list|()
expr_stmt|;
comment|// Appends an event listener to the end of the list. Google Test assumes
comment|// the ownership of the listener (i.e. it will delete the listener when
comment|// the test program finishes).
name|void
name|Append
parameter_list|(
name|TestEventListener
modifier|*
name|listener
parameter_list|)
function_decl|;
comment|// Removes the given event listener from the list and returns it.  It then
comment|// becomes the caller's responsibility to delete the listener. Returns
comment|// NULL if the listener is not found in the list.
name|TestEventListener
modifier|*
name|Release
parameter_list|(
name|TestEventListener
modifier|*
name|listener
parameter_list|)
function_decl|;
comment|// Returns the standard listener responsible for the default console
comment|// output.  Can be removed from the listeners list to shut down default
comment|// console output.  Note that removing this object from the listener list
comment|// with Release transfers its ownership to the caller and makes this
comment|// function return NULL the next time.
name|TestEventListener
operator|*
name|default_result_printer
argument_list|()
specifier|const
block|{
return|return
name|default_result_printer_
return|;
block|}
comment|// Returns the standard listener responsible for the default XML output
comment|// controlled by the --gtest_output=xml flag.  Can be removed from the
comment|// listeners list by users who want to shut down the default XML output
comment|// controlled by this flag and substitute it with custom one.  Note that
comment|// removing this object from the listener list with Release transfers its
comment|// ownership to the caller and makes this function return NULL the next
comment|// time.
name|TestEventListener
operator|*
name|default_xml_generator
argument_list|()
specifier|const
block|{
return|return
name|default_xml_generator_
return|;
block|}
name|private
label|:
name|friend
name|class
name|TestCase
decl_stmt|;
name|friend
name|class
name|TestInfo
decl_stmt|;
name|friend
name|class
name|internal
operator|::
name|DefaultGlobalTestPartResultReporter
expr_stmt|;
name|friend
name|class
name|internal
operator|::
name|NoExecDeathTest
expr_stmt|;
name|friend
name|class
name|internal
operator|::
name|TestEventListenersAccessor
expr_stmt|;
name|friend
name|class
name|internal
operator|::
name|UnitTestImpl
expr_stmt|;
comment|// Returns repeater that broadcasts the TestEventListener events to all
comment|// subscribers.
name|TestEventListener
modifier|*
name|repeater
parameter_list|()
function_decl|;
comment|// Sets the default_result_printer attribute to the provided listener.
comment|// The listener is also added to the listener list and previous
comment|// default_result_printer is removed from it and deleted. The listener can
comment|// also be NULL in which case it will not be added to the list. Does
comment|// nothing if the previous and the current listener objects are the same.
name|void
name|SetDefaultResultPrinter
parameter_list|(
name|TestEventListener
modifier|*
name|listener
parameter_list|)
function_decl|;
comment|// Sets the default_xml_generator attribute to the provided listener.  The
comment|// listener is also added to the listener list and previous
comment|// default_xml_generator is removed from it and deleted. The listener can
comment|// also be NULL in which case it will not be added to the list. Does
comment|// nothing if the previous and the current listener objects are the same.
name|void
name|SetDefaultXmlGenerator
parameter_list|(
name|TestEventListener
modifier|*
name|listener
parameter_list|)
function_decl|;
comment|// Controls whether events will be forwarded by the repeater to the
comment|// listeners in the list.
name|bool
name|EventForwardingEnabled
argument_list|()
specifier|const
expr_stmt|;
name|void
name|SuppressEventForwarding
parameter_list|()
function_decl|;
comment|// The actual list of listeners.
name|internal
operator|::
name|TestEventRepeater
operator|*
name|repeater_
expr_stmt|;
comment|// Listener responsible for the standard result output.
name|TestEventListener
modifier|*
name|default_result_printer_
decl_stmt|;
comment|// Listener responsible for the creation of the XML output file.
name|TestEventListener
modifier|*
name|default_xml_generator_
decl_stmt|;
comment|// We disallow copying TestEventListeners.
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|TestEventListeners
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// A UnitTest consists of a vector of TestCases.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This is a singleton class.  The only instance of UnitTest is
end_comment

begin_comment
comment|// created when UnitTest::GetInstance() is first called.  This
end_comment

begin_comment
comment|// instance is never deleted.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// UnitTest is not copyable.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This class is thread-safe as long as the methods are called
end_comment

begin_comment
comment|// according to their specification.
end_comment

begin_decl_stmt
name|class
name|GTEST_API_
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
comment|// Returns the random seed used at the start of the current test run.
name|int
name|random_seed
argument_list|()
specifier|const
expr_stmt|;
if|#
directive|if
name|GTEST_HAS_PARAM_TEST
comment|// Returns the ParameterizedTestCaseRegistry object used to keep track of
comment|// value-parameterized tests and instantiate and register them.
comment|//
comment|// INTERNAL IMPLEMENTATION - DO NOT USE IN A USER PROGRAM.
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
comment|// Gets the number of successful test cases.
name|int
name|successful_test_case_count
argument_list|()
specifier|const
expr_stmt|;
comment|// Gets the number of failed test cases.
name|int
name|failed_test_case_count
argument_list|()
specifier|const
expr_stmt|;
comment|// Gets the number of all test cases.
name|int
name|total_test_case_count
argument_list|()
specifier|const
expr_stmt|;
comment|// Gets the number of all test cases that contain at least one test
comment|// that should run.
name|int
name|test_case_to_run_count
argument_list|()
specifier|const
expr_stmt|;
comment|// Gets the number of successful tests.
name|int
name|successful_test_count
argument_list|()
specifier|const
expr_stmt|;
comment|// Gets the number of failed tests.
name|int
name|failed_test_count
argument_list|()
specifier|const
expr_stmt|;
comment|// Gets the number of disabled tests.
name|int
name|disabled_test_count
argument_list|()
specifier|const
expr_stmt|;
comment|// Gets the number of all tests.
name|int
name|total_test_count
argument_list|()
specifier|const
expr_stmt|;
comment|// Gets the number of tests that should run.
name|int
name|test_to_run_count
argument_list|()
specifier|const
expr_stmt|;
comment|// Gets the elapsed time, in milliseconds.
name|TimeInMillis
name|elapsed_time
argument_list|()
specifier|const
expr_stmt|;
comment|// Returns true iff the unit test passed (i.e. all test cases passed).
name|bool
name|Passed
argument_list|()
specifier|const
expr_stmt|;
comment|// Returns true iff the unit test failed (i.e. some test case failed
comment|// or something outside of all tests failed).
name|bool
name|Failed
argument_list|()
specifier|const
expr_stmt|;
comment|// Gets the i-th test case among all the test cases. i can range from 0 to
comment|// total_test_case_count() - 1. If i is not in that range, returns NULL.
specifier|const
name|TestCase
modifier|*
name|GetTestCase
argument_list|(
name|int
name|i
argument_list|)
decl|const
decl_stmt|;
comment|// Returns the list of event listeners that can be used to track events
comment|// inside Google Test.
name|TestEventListeners
modifier|&
name|listeners
parameter_list|()
function_decl|;
name|private
label|:
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
name|void
name|AddTestPartResult
argument_list|(
name|TestPartResult
operator|::
name|Type
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
comment|// Gets the i-th test case among all the test cases. i can range from 0 to
comment|// total_test_case_count() - 1. If i is not in that range, returns NULL.
name|TestCase
modifier|*
name|GetMutableTestCase
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
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
comment|// These classes and funcions are friends as they need to access private
comment|// members of UnitTest.
name|friend
name|class
name|Test
decl_stmt|;
name|friend
name|class
name|internal
operator|::
name|AssertHelper
expr_stmt|;
name|friend
name|class
name|internal
operator|::
name|ScopedTrace
expr_stmt|;
name|friend
name|Environment
modifier|*
name|AddGlobalTestEnvironment
parameter_list|(
name|Environment
modifier|*
name|env
parameter_list|)
function_decl|;
name|friend
name|internal
operator|::
name|UnitTestImpl
operator|*
name|internal
operator|::
name|GetUnitTestImpl
argument_list|()
expr_stmt|;
name|friend
name|void
name|internal
operator|::
name|ReportFailureInUnknownLocation
argument_list|(
argument|TestPartResult::Type result_type
argument_list|,
argument|const internal::String& message
argument_list|)
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
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// A convenient wrapper for adding an environment for the test
end_comment

begin_comment
comment|// program.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// You should call this before RUN_ALL_TESTS() is called, probably in
end_comment

begin_comment
comment|// main().  If you use gtest_main, you need to call this before main()
end_comment

begin_comment
comment|// starts for it to take effect.  For example, you can define a global
end_comment

begin_comment
comment|// variable like this:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   testing::Environment* const foo_env =
end_comment

begin_comment
comment|//       testing::AddGlobalTestEnvironment(new FooEnvironment);
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// However, we strongly recommend you to write your own main() and
end_comment

begin_comment
comment|// call AddGlobalTestEnvironment() there, as relying on initialization
end_comment

begin_comment
comment|// of global variables makes the code harder to read and may cause
end_comment

begin_comment
comment|// problems when you register multiple environments from different
end_comment

begin_comment
comment|// translation units and the environments have dependencies among them
end_comment

begin_comment
comment|// (remember that the compiler doesn't guarantee the order in which
end_comment

begin_comment
comment|// global variables from different translation units are initialized).
end_comment

begin_function
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
end_function

begin_comment
comment|// Initializes Google Test.  This must be called before calling
end_comment

begin_comment
comment|// RUN_ALL_TESTS().  In particular, it parses a command line for the
end_comment

begin_comment
comment|// flags that Google Test recognizes.  Whenever a Google Test flag is
end_comment

begin_comment
comment|// seen, it is removed from argv, and *argc is decremented.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// No value is returned.  Instead, the Google Test flag variables are
end_comment

begin_comment
comment|// updated.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Calling the function for the second time has no user-visible effect.
end_comment

begin_function_decl
name|GTEST_API_
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
end_function_decl

begin_comment
comment|// This overloaded version can be used in Windows programs compiled in
end_comment

begin_comment
comment|// UNICODE mode.
end_comment

begin_function_decl
name|GTEST_API_
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
end_function_decl

begin_decl_stmt
name|namespace
name|internal
block|{
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
comment|// C++Builder compiles this incorrectly if the namespace isn't explicitly
comment|// given.
return|return
operator|::
name|testing
operator|::
name|PrintToString
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
ifdef|#
directive|ifdef
name|_MSC_VER
pragma|#
directive|pragma
name|warning
name|(
name|push
name|)
comment|// Saves the current warning state.
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4389
name|)
comment|// Temporarily disables warning on
comment|// signed/unsigned mismatch.
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4805
name|)
comment|// Temporarily disables warning on
comment|// unsafe mix of types
endif|#
directive|endif
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
ifdef|#
directive|ifdef
name|_MSC_VER
pragma|#
directive|pragma
name|warning
name|(
name|pop
name|)
comment|// Restores the warning state.
endif|#
directive|endif
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
name|GTEST_API_
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
comment|// is a null pointer literal, like NULL, false, or 0.
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
argument_list|,
comment|// The following line prevents this overload from being considered if T2
comment|// is not a pointer type.  We need this because ASSERT_EQ(NULL, my_ptr)
comment|// expands to Compare("", "", NULL, my_ptr), which requires a conversion
comment|// to match the Secret* in the other overload, which would otherwise make
comment|// this template match better.
argument|typename EnableIf<!is_pointer<T2>::value>::type* =
literal|0
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
comment|// This version will be picked when the second argument to ASSERT_EQ() is a
comment|// pointer, e.g. ASSERT_EQ(NULL, a_pointer).
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|AssertionResult
name|Compare
argument_list|(
argument|const char* expected_expression
argument_list|,
argument|const char* actual_expression
argument_list|,
comment|// We used to have a second template parameter instead of Secret*.  That
comment|// template parameter would deduce to 'long', making this a better match
comment|// than the first overload even without the first overload's EnableIf.
comment|// Unfortunately, gcc with -Wconversion-null warns when "passing NULL to
comment|// non-pointer argument" (even a deduced integral argument), so the old
comment|// implementation caused warnings in user code.
argument|Secret*
comment|/* expected (NULL) */
argument_list|,
argument|T* actual
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
name|T
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
value|template<typename T1, typename T2>\ AssertionResult CmpHelper##op_name(const char* expr1, const char* expr2, \                                    const T1& val1, const T2& val2) {\   if (val1 op val2) {\     return AssertionSuccess();\   } else {\     return AssertionFailure() \<< "Expected: ("<< expr1<< ") " #op " ("<< expr2\<< "), actual: "<< FormatForComparisonFailureMessage(val1, val2)\<< " vs "<< FormatForComparisonFailureMessage(val2, val1);\   }\ }\ GTEST_API_ AssertionResult CmpHelper##op_name(\     const char* expr1, const char* expr2, BiggestInt val1, BiggestInt val2)
comment|// INTERNAL IMPLEMENTATION - DO NOT USE IN A USER PROGRAM.
comment|// Implements the helper function for {ASSERT|EXPECT}_NE
name|GTEST_IMPL_CMP_HELPER_
argument_list|(
name|NE
argument_list|,
operator|!=
argument_list|)
block|;
comment|// Implements the helper function for {ASSERT|EXPECT}_LE
name|GTEST_IMPL_CMP_HELPER_
argument_list|(
name|LE
argument_list|,
operator|<=
argument_list|)
block|;
comment|// Implements the helper function for {ASSERT|EXPECT}_LT
name|GTEST_IMPL_CMP_HELPER_
argument_list|(
name|LT
argument_list|,
operator|<
argument_list|)
block|;
comment|// Implements the helper function for {ASSERT|EXPECT}_GE
name|GTEST_IMPL_CMP_HELPER_
argument_list|(
name|GE
argument_list|,
operator|>=
argument_list|)
block|;
comment|// Implements the helper function for {ASSERT|EXPECT}_GT
name|GTEST_IMPL_CMP_HELPER_
argument_list|(
name|GT
argument_list|,
operator|>
argument_list|)
block|;
undef|#
directive|undef
name|GTEST_IMPL_CMP_HELPER_
comment|// The helper function for {ASSERT|EXPECT}_STREQ.
comment|//
comment|// INTERNAL IMPLEMENTATION - DO NOT USE IN A USER PROGRAM.
name|GTEST_API_
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
name|GTEST_API_
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
name|GTEST_API_
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
name|GTEST_API_
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
name|GTEST_API_
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
name|GTEST_API_
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
name|GTEST_API_
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
name|GTEST_API_
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
name|GTEST_API_
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
name|GTEST_API_
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
name|GTEST_API_
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
name|GTEST_API_
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
if|#
directive|if
name|GTEST_HAS_STD_WSTRING
name|GTEST_API_
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
name|GTEST_API_
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
operator|::
name|std
operator|::
name|stringstream
name|expected_ss
expr_stmt|;
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
operator|::
name|std
operator|::
name|stringstream
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
name|StringStreamToString
argument_list|(
operator|&
name|expected_ss
argument_list|)
argument_list|,
name|StringStreamToString
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
name|GTEST_API_
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
name|GTEST_API_
name|AssertHelper
block|{
name|public
operator|:
comment|// Constructor.
name|AssertHelper
argument_list|(
argument|TestPartResult::Type type
argument_list|,
argument|const char* file
argument_list|,
argument|int line
argument_list|,
argument|const char* message
argument_list|)
block|;
operator|~
name|AssertHelper
argument_list|()
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
comment|// We put our data in a struct so that the size of the AssertHelper class can
comment|// be as small as possible.  This is important because gcc is incapable of
comment|// re-using stack space even for temporary variables, so every EXPECT_EQ
comment|// reserves stack space for another AssertHelper.
expr|struct
name|AssertHelperData
block|{
name|AssertHelperData
argument_list|(
argument|TestPartResult::Type t
argument_list|,
argument|const char* srcfile
argument_list|,
argument|int line_num
argument_list|,
argument|const char* msg
argument_list|)
operator|:
name|type
argument_list|(
name|t
argument_list|)
block|,
name|file
argument_list|(
name|srcfile
argument_list|)
block|,
name|line
argument_list|(
name|line_num
argument_list|)
block|,
name|message
argument_list|(
argument|msg
argument_list|)
block|{ }
name|TestPartResult
operator|::
name|Type
specifier|const
name|type
block|;
specifier|const
name|char
operator|*
specifier|const
name|file
block|;
name|int
specifier|const
name|line
block|;
name|String
specifier|const
name|message
block|;
name|private
operator|:
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|AssertHelperData
argument_list|)
block|;   }
block|;
name|AssertHelperData
operator|*
specifier|const
name|data_
block|;
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|AssertHelper
argument_list|)
block|; }
block|;  }
comment|// namespace internal
if|#
directive|if
name|GTEST_HAS_PARAM_TEST
comment|// The pure interface class that all value-parameterized tests inherit from.
comment|// A value-parameterized class must inherit from both ::testing::Test and
comment|// ::testing::WithParamInterface. In most cases that just means inheriting
comment|// from ::testing::TestWithParam, but more complicated test hierarchies
comment|// may need to inherit from Test and WithParamInterface at different levels.
comment|//
comment|// This interface has support for accessing the test parameter value via
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
name|WithParamInterface
block|{
name|public
operator|:
typedef|typedef
name|T
name|ParamType
typedef|;
name|virtual
operator|~
name|WithParamInterface
argument_list|()
block|{}
comment|// The current parameter value. Is also available in the test fixture's
comment|// constructor. This member function is non-static, even though it only
comment|// references static data, to reduce the opportunity for incorrect uses
comment|// like writing 'WithParamInterface<bool>::GetParam()' for a test that
comment|// uses a fixture whose parameter type is int.
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
label|:
comment|// Sets parameter value. The caller is responsible for making sure the value
comment|// remains alive and unchanged throughout the current test.
specifier|static
name|void
name|SetParam
parameter_list|(
specifier|const
name|ParamType
modifier|*
name|parameter
parameter_list|)
block|{
name|parameter_
operator|=
name|parameter
expr_stmt|;
block|}
comment|// Static value used for accessing parameter during a test lifetime.
specifier|static
specifier|const
name|ParamType
modifier|*
name|parameter_
decl_stmt|;
comment|// TestClass must be a subclass of WithParamInterface<T> and Test.
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
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|const
name|T
operator|*
name|WithParamInterface
operator|<
name|T
operator|>
operator|::
name|parameter_
operator|=
name|NULL
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Most value-parameterized classes can ignore the existence of
end_comment

begin_comment
comment|// WithParamInterface, and can just inherit from ::testing::TestWithParam.
end_comment

begin_expr_stmt
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
operator|,
name|public
name|WithParamInterface
operator|<
name|T
operator|>
block|{ }
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_HAS_PARAM_TEST
end_comment

begin_comment
comment|// Macros for indicating success/failure in test code.
end_comment

begin_comment
comment|// ADD_FAILURE unconditionally adds a failure to the current test.
end_comment

begin_comment
comment|// SUCCEED generates a success - it doesn't automatically make the
end_comment

begin_comment
comment|// current test successful, as a test is only successful when it has
end_comment

begin_comment
comment|// no failure.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// EXPECT_* verifies that a certain condition is satisfied.  If not,
end_comment

begin_comment
comment|// it behaves like ADD_FAILURE.  In particular:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   EXPECT_TRUE  verifies that a Boolean condition is true.
end_comment

begin_comment
comment|//   EXPECT_FALSE verifies that a Boolean condition is false.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// FAIL and ASSERT_* are similar to ADD_FAILURE and EXPECT_*, except
end_comment

begin_comment
comment|// that they will also abort the current function on failure.  People
end_comment

begin_comment
comment|// usually want the fail-fast behavior of FAIL and ASSERT_*, but those
end_comment

begin_comment
comment|// writing data-driven tests often find themselves using ADD_FAILURE
end_comment

begin_comment
comment|// and EXPECT_* more.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Examples:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   EXPECT_TRUE(server.StatusIsOK());
end_comment

begin_comment
comment|//   ASSERT_FALSE(server.HasPendingRequest(port))
end_comment

begin_comment
comment|//<< "There are still pending requests "<< "on port "<< port;
end_comment

begin_comment
comment|// Generates a nonfatal failure with a generic message.
end_comment

begin_define
define|#
directive|define
name|ADD_FAILURE
parameter_list|()
value|GTEST_NONFATAL_FAILURE_("Failed")
end_define

begin_comment
comment|// Generates a nonfatal failure at the given source file location with
end_comment

begin_comment
comment|// a generic message.
end_comment

begin_define
define|#
directive|define
name|ADD_FAILURE_AT
parameter_list|(
name|file
parameter_list|,
name|line
parameter_list|)
define|\
value|GTEST_MESSAGE_AT_(file, line, "Failed", \                     ::testing::TestPartResult::kNonFatalFailure)
end_define

begin_comment
comment|// Generates a fatal failure with a generic message.
end_comment

begin_define
define|#
directive|define
name|GTEST_FAIL
parameter_list|()
value|GTEST_FATAL_FAILURE_("Failed")
end_define

begin_comment
comment|// Define this macro to 1 to omit the definition of FAIL(), which is a
end_comment

begin_comment
comment|// generic name and clashes with some other libraries.
end_comment

begin_if
if|#
directive|if
operator|!
name|GTEST_DONT_DEFINE_FAIL
end_if

begin_define
define|#
directive|define
name|FAIL
parameter_list|()
value|GTEST_FAIL()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Generates a success with a generic message.
end_comment

begin_define
define|#
directive|define
name|GTEST_SUCCEED
parameter_list|()
value|GTEST_SUCCESS_("Succeeded")
end_define

begin_comment
comment|// Define this macro to 1 to omit the definition of SUCCEED(), which
end_comment

begin_comment
comment|// is a generic name and clashes with some other libraries.
end_comment

begin_if
if|#
directive|if
operator|!
name|GTEST_DONT_DEFINE_SUCCEED
end_if

begin_define
define|#
directive|define
name|SUCCEED
parameter_list|()
value|GTEST_SUCCEED()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Macros for testing exceptions.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//    * {ASSERT|EXPECT}_THROW(statement, expected_exception):
end_comment

begin_comment
comment|//         Tests that the statement throws the expected exception.
end_comment

begin_comment
comment|//    * {ASSERT|EXPECT}_NO_THROW(statement):
end_comment

begin_comment
comment|//         Tests that the statement doesn't throw any exception.
end_comment

begin_comment
comment|//    * {ASSERT|EXPECT}_ANY_THROW(statement):
end_comment

begin_comment
comment|//         Tests that the statement throws an exception.
end_comment

begin_define
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
end_define

begin_define
define|#
directive|define
name|EXPECT_NO_THROW
parameter_list|(
name|statement
parameter_list|)
define|\
value|GTEST_TEST_NO_THROW_(statement, GTEST_NONFATAL_FAILURE_)
end_define

begin_define
define|#
directive|define
name|EXPECT_ANY_THROW
parameter_list|(
name|statement
parameter_list|)
define|\
value|GTEST_TEST_ANY_THROW_(statement, GTEST_NONFATAL_FAILURE_)
end_define

begin_define
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
end_define

begin_define
define|#
directive|define
name|ASSERT_NO_THROW
parameter_list|(
name|statement
parameter_list|)
define|\
value|GTEST_TEST_NO_THROW_(statement, GTEST_FATAL_FAILURE_)
end_define

begin_define
define|#
directive|define
name|ASSERT_ANY_THROW
parameter_list|(
name|statement
parameter_list|)
define|\
value|GTEST_TEST_ANY_THROW_(statement, GTEST_FATAL_FAILURE_)
end_define

begin_comment
comment|// Boolean assertions. Condition can be either a Boolean expression or an
end_comment

begin_comment
comment|// AssertionResult. For more information on how to use AssertionResult with
end_comment

begin_comment
comment|// these macros see comments on that class.
end_comment

begin_define
define|#
directive|define
name|EXPECT_TRUE
parameter_list|(
name|condition
parameter_list|)
define|\
value|GTEST_TEST_BOOLEAN_(condition, #condition, false, true, \                       GTEST_NONFATAL_FAILURE_)
end_define

begin_define
define|#
directive|define
name|EXPECT_FALSE
parameter_list|(
name|condition
parameter_list|)
define|\
value|GTEST_TEST_BOOLEAN_(!(condition), #condition, true, false, \                       GTEST_NONFATAL_FAILURE_)
end_define

begin_define
define|#
directive|define
name|ASSERT_TRUE
parameter_list|(
name|condition
parameter_list|)
define|\
value|GTEST_TEST_BOOLEAN_(condition, #condition, false, true, \                       GTEST_FATAL_FAILURE_)
end_define

begin_define
define|#
directive|define
name|ASSERT_FALSE
parameter_list|(
name|condition
parameter_list|)
define|\
value|GTEST_TEST_BOOLEAN_(!(condition), #condition, true, false, \                       GTEST_FATAL_FAILURE_)
end_define

begin_comment
comment|// Includes the auto-generated header that implements a family of
end_comment

begin_comment
comment|// generic predicate assertion macros.
end_comment

begin_include
include|#
directive|include
file|"gtest/gtest_pred_impl.h"
end_include

begin_comment
comment|// Macros for testing equalities and inequalities.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//    * {ASSERT|EXPECT}_EQ(expected, actual): Tests that expected == actual
end_comment

begin_comment
comment|//    * {ASSERT|EXPECT}_NE(v1, v2):           Tests that v1 != v2
end_comment

begin_comment
comment|//    * {ASSERT|EXPECT}_LT(v1, v2):           Tests that v1< v2
end_comment

begin_comment
comment|//    * {ASSERT|EXPECT}_LE(v1, v2):           Tests that v1<= v2
end_comment

begin_comment
comment|//    * {ASSERT|EXPECT}_GT(v1, v2):           Tests that v1> v2
end_comment

begin_comment
comment|//    * {ASSERT|EXPECT}_GE(v1, v2):           Tests that v1>= v2
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// When they are not, Google Test prints both the tested expressions and
end_comment

begin_comment
comment|// their actual values.  The values must be compatible built-in types,
end_comment

begin_comment
comment|// or you will get a compiler error.  By "compatible" we mean that the
end_comment

begin_comment
comment|// values can be compared by the respective operator.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Note:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   1. It is possible to make a user-defined type work with
end_comment

begin_comment
comment|//   {ASSERT|EXPECT}_??(), but that requires overloading the
end_comment

begin_comment
comment|//   comparison operators and is thus discouraged by the Google C++
end_comment

begin_comment
comment|//   Usage Guide.  Therefore, you are advised to use the
end_comment

begin_comment
comment|//   {ASSERT|EXPECT}_TRUE() macro to assert that two objects are
end_comment

begin_comment
comment|//   equal.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   2. The {ASSERT|EXPECT}_??() macros do pointer comparisons on
end_comment

begin_comment
comment|//   pointers (in particular, C strings).  Therefore, if you use it
end_comment

begin_comment
comment|//   with two C strings, you are testing how their locations in memory
end_comment

begin_comment
comment|//   are related, not how their content is related.  To compare two C
end_comment

begin_comment
comment|//   strings by content, use {ASSERT|EXPECT}_STR*().
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   3. {ASSERT|EXPECT}_EQ(expected, actual) is preferred to
end_comment

begin_comment
comment|//   {ASSERT|EXPECT}_TRUE(expected == actual), as the former tells you
end_comment

begin_comment
comment|//   what the actual value is when it fails, and similarly for the
end_comment

begin_comment
comment|//   other comparisons.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   4. Do not depend on the order in which {ASSERT|EXPECT}_??()
end_comment

begin_comment
comment|//   evaluate their arguments, which is undefined.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   5. These macros evaluate their arguments exactly once.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Examples:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   EXPECT_NE(5, Foo());
end_comment

begin_comment
comment|//   EXPECT_EQ(NULL, a_pointer);
end_comment

begin_comment
comment|//   ASSERT_LT(i, array_size);
end_comment

begin_comment
comment|//   ASSERT_GT(records.size(), 0)<< "There is no record left.";
end_comment

begin_define
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
end_define

begin_define
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
end_define

begin_define
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
end_define

begin_define
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
end_define

begin_define
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
end_define

begin_define
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
end_define

begin_define
define|#
directive|define
name|GTEST_ASSERT_EQ
parameter_list|(
name|expected
parameter_list|,
name|actual
parameter_list|)
define|\
value|ASSERT_PRED_FORMAT2(::testing::internal:: \                       EqHelper<GTEST_IS_NULL_LITERAL_(expected)>::Compare, \                       expected, actual)
end_define

begin_define
define|#
directive|define
name|GTEST_ASSERT_NE
parameter_list|(
name|val1
parameter_list|,
name|val2
parameter_list|)
define|\
value|ASSERT_PRED_FORMAT2(::testing::internal::CmpHelperNE, val1, val2)
end_define

begin_define
define|#
directive|define
name|GTEST_ASSERT_LE
parameter_list|(
name|val1
parameter_list|,
name|val2
parameter_list|)
define|\
value|ASSERT_PRED_FORMAT2(::testing::internal::CmpHelperLE, val1, val2)
end_define

begin_define
define|#
directive|define
name|GTEST_ASSERT_LT
parameter_list|(
name|val1
parameter_list|,
name|val2
parameter_list|)
define|\
value|ASSERT_PRED_FORMAT2(::testing::internal::CmpHelperLT, val1, val2)
end_define

begin_define
define|#
directive|define
name|GTEST_ASSERT_GE
parameter_list|(
name|val1
parameter_list|,
name|val2
parameter_list|)
define|\
value|ASSERT_PRED_FORMAT2(::testing::internal::CmpHelperGE, val1, val2)
end_define

begin_define
define|#
directive|define
name|GTEST_ASSERT_GT
parameter_list|(
name|val1
parameter_list|,
name|val2
parameter_list|)
define|\
value|ASSERT_PRED_FORMAT2(::testing::internal::CmpHelperGT, val1, val2)
end_define

begin_comment
comment|// Define macro GTEST_DONT_DEFINE_ASSERT_XY to 1 to omit the definition of
end_comment

begin_comment
comment|// ASSERT_XY(), which clashes with some users' own code.
end_comment

begin_if
if|#
directive|if
operator|!
name|GTEST_DONT_DEFINE_ASSERT_EQ
end_if

begin_define
define|#
directive|define
name|ASSERT_EQ
parameter_list|(
name|val1
parameter_list|,
name|val2
parameter_list|)
value|GTEST_ASSERT_EQ(val1, val2)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|GTEST_DONT_DEFINE_ASSERT_NE
end_if

begin_define
define|#
directive|define
name|ASSERT_NE
parameter_list|(
name|val1
parameter_list|,
name|val2
parameter_list|)
value|GTEST_ASSERT_NE(val1, val2)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|GTEST_DONT_DEFINE_ASSERT_LE
end_if

begin_define
define|#
directive|define
name|ASSERT_LE
parameter_list|(
name|val1
parameter_list|,
name|val2
parameter_list|)
value|GTEST_ASSERT_LE(val1, val2)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|GTEST_DONT_DEFINE_ASSERT_LT
end_if

begin_define
define|#
directive|define
name|ASSERT_LT
parameter_list|(
name|val1
parameter_list|,
name|val2
parameter_list|)
value|GTEST_ASSERT_LT(val1, val2)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|GTEST_DONT_DEFINE_ASSERT_GE
end_if

begin_define
define|#
directive|define
name|ASSERT_GE
parameter_list|(
name|val1
parameter_list|,
name|val2
parameter_list|)
value|GTEST_ASSERT_GE(val1, val2)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|GTEST_DONT_DEFINE_ASSERT_GT
end_if

begin_define
define|#
directive|define
name|ASSERT_GT
parameter_list|(
name|val1
parameter_list|,
name|val2
parameter_list|)
value|GTEST_ASSERT_GT(val1, val2)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// C String Comparisons.  All tests treat NULL and any non-NULL string
end_comment

begin_comment
comment|// as different.  Two NULLs are equal.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//    * {ASSERT|EXPECT}_STREQ(s1, s2):     Tests that s1 == s2
end_comment

begin_comment
comment|//    * {ASSERT|EXPECT}_STRNE(s1, s2):     Tests that s1 != s2
end_comment

begin_comment
comment|//    * {ASSERT|EXPECT}_STRCASEEQ(s1, s2): Tests that s1 == s2, ignoring case
end_comment

begin_comment
comment|//    * {ASSERT|EXPECT}_STRCASENE(s1, s2): Tests that s1 != s2, ignoring case
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// For wide or narrow string objects, you can use the
end_comment

begin_comment
comment|// {ASSERT|EXPECT}_??() macros.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Don't depend on the order in which the arguments are evaluated,
end_comment

begin_comment
comment|// which is undefined.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// These macros evaluate their arguments exactly once.
end_comment

begin_define
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
end_define

begin_define
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
end_define

begin_define
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
end_define

begin_define
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
end_define

begin_define
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
end_define

begin_define
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
end_define

begin_define
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
end_define

begin_define
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
end_define

begin_comment
comment|// Macros for comparing floating-point numbers.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//    * {ASSERT|EXPECT}_FLOAT_EQ(expected, actual):
end_comment

begin_comment
comment|//         Tests that two float values are almost equal.
end_comment

begin_comment
comment|//    * {ASSERT|EXPECT}_DOUBLE_EQ(expected, actual):
end_comment

begin_comment
comment|//         Tests that two double values are almost equal.
end_comment

begin_comment
comment|//    * {ASSERT|EXPECT}_NEAR(v1, v2, abs_error):
end_comment

begin_comment
comment|//         Tests that v1 and v2 are within the given distance to each other.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Google Test uses ULP-based comparison to automatically pick a default
end_comment

begin_comment
comment|// error bound that is appropriate for the operands.  See the
end_comment

begin_comment
comment|// FloatingPoint template class in gtest-internal.h if you are
end_comment

begin_comment
comment|// interested in the implementation details.
end_comment

begin_define
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
end_define

begin_define
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
end_define

begin_define
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
end_define

begin_define
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
end_define

begin_define
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
end_define

begin_define
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
end_define

begin_comment
comment|// These predicate format functions work on floating-point values, and
end_comment

begin_comment
comment|// can be used in {ASSERT|EXPECT}_PRED_FORMAT2*(), e.g.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   EXPECT_PRED_FORMAT2(testing::DoubleLE, Foo(), 5.0);
end_comment

begin_comment
comment|// Asserts that val1 is less than, or almost equal to, val2.  Fails
end_comment

begin_comment
comment|// otherwise.  In particular, it fails if either val1 or val2 is NaN.
end_comment

begin_function_decl
name|GTEST_API_
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
end_function_decl

begin_function_decl
name|GTEST_API_
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
end_function_decl

begin_if
if|#
directive|if
name|GTEST_OS_WINDOWS
end_if

begin_comment
comment|// Macros that test for HRESULT failure and success, these are only useful
end_comment

begin_comment
comment|// on Windows, and rely on Windows SDK macros and APIs to compile.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//    * {ASSERT|EXPECT}_HRESULT_{SUCCEEDED|FAILED}(expr)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// When expr unexpectedly fails or succeeds, Google Test prints the
end_comment

begin_comment
comment|// expected result and the actual result with both a human-readable
end_comment

begin_comment
comment|// string representation of the error, if available, as well as the
end_comment

begin_comment
comment|// hex result code.
end_comment

begin_define
define|#
directive|define
name|EXPECT_HRESULT_SUCCEEDED
parameter_list|(
name|expr
parameter_list|)
define|\
value|EXPECT_PRED_FORMAT1(::testing::internal::IsHRESULTSuccess, (expr))
end_define

begin_define
define|#
directive|define
name|ASSERT_HRESULT_SUCCEEDED
parameter_list|(
name|expr
parameter_list|)
define|\
value|ASSERT_PRED_FORMAT1(::testing::internal::IsHRESULTSuccess, (expr))
end_define

begin_define
define|#
directive|define
name|EXPECT_HRESULT_FAILED
parameter_list|(
name|expr
parameter_list|)
define|\
value|EXPECT_PRED_FORMAT1(::testing::internal::IsHRESULTFailure, (expr))
end_define

begin_define
define|#
directive|define
name|ASSERT_HRESULT_FAILED
parameter_list|(
name|expr
parameter_list|)
define|\
value|ASSERT_PRED_FORMAT1(::testing::internal::IsHRESULTFailure, (expr))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_OS_WINDOWS
end_comment

begin_comment
comment|// Macros that execute statement and check that it doesn't generate new fatal
end_comment

begin_comment
comment|// failures in the current thread.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   * {ASSERT|EXPECT}_NO_FATAL_FAILURE(statement);
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Examples:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   EXPECT_NO_FATAL_FAILURE(Process());
end_comment

begin_comment
comment|//   ASSERT_NO_FATAL_FAILURE(Process())<< "Process() failed";
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|ASSERT_NO_FATAL_FAILURE
parameter_list|(
name|statement
parameter_list|)
define|\
value|GTEST_TEST_NO_FATAL_FAILURE_(statement, GTEST_FATAL_FAILURE_)
end_define

begin_define
define|#
directive|define
name|EXPECT_NO_FATAL_FAILURE
parameter_list|(
name|statement
parameter_list|)
define|\
value|GTEST_TEST_NO_FATAL_FAILURE_(statement, GTEST_NONFATAL_FAILURE_)
end_define

begin_comment
comment|// Causes a trace (including the source file path, the current line
end_comment

begin_comment
comment|// number, and the given message) to be included in every test failure
end_comment

begin_comment
comment|// message generated by code in the current scope.  The effect is
end_comment

begin_comment
comment|// undone when the control leaves the current scope.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The message argument can be anything streamable to std::ostream.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// In the implementation, we include the current line number as part
end_comment

begin_comment
comment|// of the dummy variable name, thus allowing multiple SCOPED_TRACE()s
end_comment

begin_comment
comment|// to appear in the same block - as long as they are on different
end_comment

begin_comment
comment|// lines.
end_comment

begin_define
define|#
directive|define
name|SCOPED_TRACE
parameter_list|(
name|message
parameter_list|)
define|\
value|::testing::internal::ScopedTrace GTEST_CONCAT_TOKEN_(gtest_trace_, __LINE__)(\     __FILE__, __LINE__, ::testing::Message()<< (message))
end_define

begin_comment
comment|// Compile-time assertion for type equality.
end_comment

begin_comment
comment|// StaticAssertTypeEq<type1, type2>() compiles iff type1 and type2 are
end_comment

begin_comment
comment|// the same type.  The value it returns is not interesting.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Instead of making StaticAssertTypeEq a class template, we make it a
end_comment

begin_comment
comment|// function template that invokes a helper class template.  This
end_comment

begin_comment
comment|// prevents a user from misusing StaticAssertTypeEq<T1, T2> by
end_comment

begin_comment
comment|// defining objects of that type.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CAVEAT:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// When used inside a method of a class template,
end_comment

begin_comment
comment|// StaticAssertTypeEq<T1, T2>() is effective ONLY IF the method is
end_comment

begin_comment
comment|// instantiated.  For example, given:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   template<typename T> class Foo {
end_comment

begin_comment
comment|//    public:
end_comment

begin_comment
comment|//     void Bar() { testing::StaticAssertTypeEq<int, T>(); }
end_comment

begin_comment
comment|//   };
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// the code:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   void Test1() { Foo<bool> foo; }
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// will NOT generate a compiler error, as Foo<bool>::Bar() is never
end_comment

begin_comment
comment|// actually instantiated.  Instead, you need:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   void Test2() { Foo<bool> foo; foo.Bar(); }
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// to cause a compiler error.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|>
name|bool
name|StaticAssertTypeEq
argument_list|()
block|{
operator|(
name|void
operator|)
name|internal
operator|::
name|StaticAssertTypeEqHelper
operator|<
name|T1
block|,
name|T2
operator|>
operator|(
operator|)
block|;
return|return
name|true
return|;
block|}
end_expr_stmt

begin_comment
comment|// Defines a test.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The first parameter is the name of the test case, and the second
end_comment

begin_comment
comment|// parameter is the name of the test within the test case.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The convention is to end the test case name with "Test".  For
end_comment

begin_comment
comment|// example, a test case for the Foo class can be named FooTest.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The user should put his test code between braces after using this
end_comment

begin_comment
comment|// macro.  Example:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   TEST(FooTest, InitializesCorrectly) {
end_comment

begin_comment
comment|//     Foo foo;
end_comment

begin_comment
comment|//     EXPECT_TRUE(foo.StatusIsOK());
end_comment

begin_comment
comment|//   }
end_comment

begin_comment
comment|// Note that we call GetTestTypeId() instead of GetTypeId<
end_comment

begin_comment
comment|// ::testing::Test>() here to get the type ID of testing::Test.  This
end_comment

begin_comment
comment|// is to work around a suspected linker bug when using Google Test as
end_comment

begin_comment
comment|// a framework on Mac OS X.  The bug causes GetTypeId<
end_comment

begin_comment
comment|// ::testing::Test>() to return different values depending on whether
end_comment

begin_comment
comment|// the call is from the Google Test framework itself or from user test
end_comment

begin_comment
comment|// code.  GetTestTypeId() is guaranteed to always return the same
end_comment

begin_comment
comment|// value, as it always calls GetTypeId<>() from the Google Test
end_comment

begin_comment
comment|// framework.
end_comment

begin_define
define|#
directive|define
name|GTEST_TEST
parameter_list|(
name|test_case_name
parameter_list|,
name|test_name
parameter_list|)
define|\
value|GTEST_TEST_(test_case_name, test_name, \               ::testing::Test, ::testing::internal::GetTestTypeId())
end_define

begin_comment
comment|// Define this macro to 1 to omit the definition of TEST(), which
end_comment

begin_comment
comment|// is a generic name and clashes with some other libraries.
end_comment

begin_if
if|#
directive|if
operator|!
name|GTEST_DONT_DEFINE_TEST
end_if

begin_define
define|#
directive|define
name|TEST
parameter_list|(
name|test_case_name
parameter_list|,
name|test_name
parameter_list|)
value|GTEST_TEST(test_case_name, test_name)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Defines a test that uses a test fixture.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The first parameter is the name of the test fixture class, which
end_comment

begin_comment
comment|// also doubles as the test case name.  The second parameter is the
end_comment

begin_comment
comment|// name of the test within the test case.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// A test fixture class must be declared earlier.  The user should put
end_comment

begin_comment
comment|// his test code between braces after using this macro.  Example:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   class FooTest : public testing::Test {
end_comment

begin_comment
comment|//    protected:
end_comment

begin_comment
comment|//     virtual void SetUp() { b_.AddElement(3); }
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//     Foo a_;
end_comment

begin_comment
comment|//     Foo b_;
end_comment

begin_comment
comment|//   };
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   TEST_F(FooTest, InitializesCorrectly) {
end_comment

begin_comment
comment|//     EXPECT_TRUE(a_.StatusIsOK());
end_comment

begin_comment
comment|//   }
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   TEST_F(FooTest, ReturnsElementCountCorrectly) {
end_comment

begin_comment
comment|//     EXPECT_EQ(0, a_.size());
end_comment

begin_comment
comment|//     EXPECT_EQ(1, b_.size());
end_comment

begin_comment
comment|//   }
end_comment

begin_define
define|#
directive|define
name|TEST_F
parameter_list|(
name|test_fixture
parameter_list|,
name|test_name
parameter_list|)
define|\
value|GTEST_TEST_(test_fixture, test_name, test_fixture, \               ::testing::internal::GetTypeId<test_fixture>())
end_define

begin_comment
comment|// Use this macro in main() to run all tests.  It returns 0 if all
end_comment

begin_comment
comment|// tests are successful, or 1 otherwise.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN_ALL_TESTS() should be invoked after the command line has been
end_comment

begin_comment
comment|// parsed by InitGoogleTest().
end_comment

begin_define
define|#
directive|define
name|RUN_ALL_TESTS
parameter_list|()
define|\
value|(::testing::UnitTest::GetInstance()->Run())
end_define

begin_comment
unit|}
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

