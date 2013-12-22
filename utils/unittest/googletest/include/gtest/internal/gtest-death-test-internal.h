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
comment|// Authors: wan@google.com (Zhanyong Wan), eefacm@gmail.com (Sean Mcafee)
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
comment|// This header file defines internal utilities needed for implementing
end_comment

begin_comment
comment|// death tests.  They are subject to change without notice.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GTEST_INCLUDE_GTEST_INTERNAL_GTEST_DEATH_TEST_INTERNAL_H_
end_ifndef

begin_define
define|#
directive|define
name|GTEST_INCLUDE_GTEST_INTERNAL_GTEST_DEATH_TEST_INTERNAL_H_
end_define

begin_include
include|#
directive|include
file|"gtest/internal/gtest-internal.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
name|namespace
name|testing
block|{
name|namespace
name|internal
block|{
name|GTEST_DECLARE_string_
argument_list|(
name|internal_run_death_test
argument_list|)
expr_stmt|;
comment|// Names of the flags (needed for parsing Google Test flags).
specifier|const
name|char
name|kDeathTestStyleFlag
index|[]
init|=
literal|"death_test_style"
decl_stmt|;
specifier|const
name|char
name|kDeathTestUseFork
index|[]
init|=
literal|"death_test_use_fork"
decl_stmt|;
specifier|const
name|char
name|kInternalRunDeathTestFlag
index|[]
init|=
literal|"internal_run_death_test"
decl_stmt|;
if|#
directive|if
name|GTEST_HAS_DEATH_TEST
comment|// DeathTest is a class that hides much of the complexity of the
comment|// GTEST_DEATH_TEST_ macro.  It is abstract; its static Create method
comment|// returns a concrete class that depends on the prevailing death test
comment|// style, as defined by the --gtest_death_test_style and/or
comment|// --gtest_internal_run_death_test flags.
comment|// In describing the results of death tests, these terms are used with
comment|// the corresponding definitions:
comment|//
comment|// exit status:  The integer exit information in the format specified
comment|//               by wait(2)
comment|// exit code:    The integer code passed to exit(3), _exit(2), or
comment|//               returned from main()
name|class
name|GTEST_API_
name|DeathTest
block|{
name|public
label|:
comment|// Create returns false if there was an error determining the
comment|// appropriate action to take for the current death test; for example,
comment|// if the gtest_death_test_style flag is set to an invalid value.
comment|// The LastMessage method will return a more detailed message in that
comment|// case.  Otherwise, the DeathTest pointer pointed to by the "test"
comment|// argument is set.  If the death test should be skipped, the pointer
comment|// is set to NULL; otherwise, it is set to the address of a new concrete
comment|// DeathTest object that controls the execution of the current test.
specifier|static
name|bool
name|Create
parameter_list|(
specifier|const
name|char
modifier|*
name|statement
parameter_list|,
specifier|const
name|RE
modifier|*
name|regex
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
name|DeathTest
modifier|*
modifier|*
name|test
parameter_list|)
function_decl|;
name|DeathTest
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|DeathTest
argument_list|()
expr_stmt|;
comment|// A helper class that aborts a death test when it's deleted.
name|class
name|ReturnSentinel
block|{
name|public
label|:
name|explicit
name|ReturnSentinel
argument_list|(
name|DeathTest
operator|*
name|test
argument_list|)
operator|:
name|test_
argument_list|(
argument|test
argument_list|)
block|{ }
operator|~
name|ReturnSentinel
argument_list|()
block|{
name|test_
operator|->
name|Abort
argument_list|(
name|TEST_ENCOUNTERED_RETURN_STATEMENT
argument_list|)
block|; }
name|private
operator|:
name|DeathTest
operator|*
specifier|const
name|test_
expr_stmt|;
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|ReturnSentinel
argument_list|)
expr_stmt|;
block|}
name|GTEST_ATTRIBUTE_UNUSED_
expr_stmt|;
comment|// An enumeration of possible roles that may be taken when a death
comment|// test is encountered.  EXECUTE means that the death test logic should
comment|// be executed immediately.  OVERSEE means that the program should prepare
comment|// the appropriate environment for a child process to execute the death
comment|// test, then wait for it to complete.
enum|enum
name|TestRole
block|{
name|OVERSEE_TEST
block|,
name|EXECUTE_TEST
block|}
enum|;
comment|// An enumeration of the three reasons that a test might be aborted.
enum|enum
name|AbortReason
block|{
name|TEST_ENCOUNTERED_RETURN_STATEMENT
block|,
name|TEST_THREW_EXCEPTION
block|,
name|TEST_DID_NOT_DIE
block|}
enum|;
comment|// Assumes one of the above roles.
name|virtual
name|TestRole
name|AssumeRole
parameter_list|()
init|=
literal|0
function_decl|;
comment|// Waits for the death test to finish and returns its status.
name|virtual
name|int
name|Wait
parameter_list|()
init|=
literal|0
function_decl|;
comment|// Returns true if the death test passed; that is, the test process
comment|// exited during the test, its exit status matches a user-supplied
comment|// predicate, and its stderr output matches a user-supplied regular
comment|// expression.
comment|// The user-supplied predicate may be a macro expression rather
comment|// than a function pointer or functor, or else Wait and Passed could
comment|// be combined.
name|virtual
name|bool
name|Passed
parameter_list|(
name|bool
name|exit_status_ok
parameter_list|)
init|=
literal|0
function_decl|;
comment|// Signals that the death test did not die as expected.
name|virtual
name|void
name|Abort
parameter_list|(
name|AbortReason
name|reason
parameter_list|)
init|=
literal|0
function_decl|;
comment|// Returns a human-readable outcome message regarding the outcome of
comment|// the last death test.
specifier|static
specifier|const
name|char
modifier|*
name|LastMessage
parameter_list|()
function_decl|;
specifier|static
name|void
name|set_last_death_test_message
parameter_list|(
specifier|const
name|String
modifier|&
name|message
parameter_list|)
function_decl|;
name|private
label|:
comment|// A string containing a description of the outcome of the last death test.
specifier|static
name|String
name|last_death_test_message_
decl_stmt|;
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|DeathTest
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
comment|// Factory interface for death tests.  May be mocked out for testing.
name|class
name|DeathTestFactory
block|{
name|public
label|:
name|virtual
operator|~
name|DeathTestFactory
argument_list|()
expr_stmt|;
name|virtual
name|bool
name|Create
parameter_list|(
specifier|const
name|char
modifier|*
name|statement
parameter_list|,
specifier|const
name|RE
modifier|*
name|regex
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
name|DeathTest
modifier|*
modifier|*
name|test
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
comment|// A concrete DeathTestFactory implementation for normal use.
name|class
name|DefaultDeathTestFactory
range|:
name|public
name|DeathTestFactory
block|{
name|public
operator|:
name|virtual
name|bool
name|Create
argument_list|(
argument|const char* statement
argument_list|,
argument|const RE* regex
argument_list|,
argument|const char* file
argument_list|,
argument|int line
argument_list|,
argument|DeathTest** test
argument_list|)
block|; }
decl_stmt|;
comment|// Returns true if exit_status describes a process that was terminated
comment|// by a signal, or exited normally with a nonzero exit code.
name|GTEST_API_
name|bool
name|ExitedUnsuccessfully
parameter_list|(
name|int
name|exit_status
parameter_list|)
function_decl|;
comment|// Traps C++ exceptions escaping statement and reports them as test
comment|// failures. Note that trapping SEH exceptions is not implemented here.
if|#
directive|if
name|GTEST_HAS_EXCEPTIONS
define|#
directive|define
name|GTEST_EXECUTE_DEATH_TEST_STATEMENT_
parameter_list|(
name|statement
parameter_list|,
name|death_test
parameter_list|)
define|\
value|try { \     GTEST_SUPPRESS_UNREACHABLE_CODE_WARNING_BELOW_(statement); \   } catch (const ::std::exception& gtest_exception) { \     fprintf(\         stderr, \         "\n%s: Caught std::exception-derived exception escaping the " \         "death test statement. Exception message: %s\n", \         ::testing::internal::FormatFileLocation(__FILE__, __LINE__).c_str(), \         gtest_exception.what()); \     fflush(stderr); \     death_test->Abort(::testing::internal::DeathTest::TEST_THREW_EXCEPTION); \   } catch (...) { \     death_test->Abort(::testing::internal::DeathTest::TEST_THREW_EXCEPTION); \   }
else|#
directive|else
define|#
directive|define
name|GTEST_EXECUTE_DEATH_TEST_STATEMENT_
parameter_list|(
name|statement
parameter_list|,
name|death_test
parameter_list|)
define|\
value|GTEST_SUPPRESS_UNREACHABLE_CODE_WARNING_BELOW_(statement)
endif|#
directive|endif
comment|// This macro is for implementing ASSERT_DEATH*, EXPECT_DEATH*,
comment|// ASSERT_EXIT*, and EXPECT_EXIT*.
define|#
directive|define
name|GTEST_DEATH_TEST_
parameter_list|(
name|statement
parameter_list|,
name|predicate
parameter_list|,
name|regex
parameter_list|,
name|fail
parameter_list|)
define|\
value|GTEST_AMBIGUOUS_ELSE_BLOCKER_ \   if (::testing::internal::AlwaysTrue()) { \     const ::testing::internal::RE& gtest_regex = (regex); \     ::testing::internal::DeathTest* gtest_dt; \     if (!::testing::internal::DeathTest::Create(#statement,&gtest_regex, \         __FILE__, __LINE__,&gtest_dt)) { \       goto GTEST_CONCAT_TOKEN_(gtest_label_, __LINE__); \     } \     if (gtest_dt != NULL) { \       ::testing::internal::scoped_ptr< ::testing::internal::DeathTest> \           gtest_dt_ptr(gtest_dt); \       switch (gtest_dt->AssumeRole()) { \         case ::testing::internal::DeathTest::OVERSEE_TEST: \           if (!gtest_dt->Passed(predicate(gtest_dt->Wait()))) { \             goto GTEST_CONCAT_TOKEN_(gtest_label_, __LINE__); \           } \           break; \         case ::testing::internal::DeathTest::EXECUTE_TEST: { \           ::testing::internal::DeathTest::ReturnSentinel \               gtest_sentinel(gtest_dt); \           GTEST_EXECUTE_DEATH_TEST_STATEMENT_(statement, gtest_dt); \           gtest_dt->Abort(::testing::internal::DeathTest::TEST_DID_NOT_DIE); \           break; \         } \       } \     } \   } else \     GTEST_CONCAT_TOKEN_(gtest_label_, __LINE__): \       fail(::testing::internal::DeathTest::LastMessage())
comment|// The symbol "fail" here expands to something into which a message
comment|// can be streamed.
comment|// A class representing the parsed contents of the
comment|// --gtest_internal_run_death_test flag, as it existed when
comment|// RUN_ALL_TESTS was called.
name|class
name|InternalRunDeathTestFlag
block|{
name|public
label|:
name|InternalRunDeathTestFlag
argument_list|(
argument|const String& a_file
argument_list|,
argument|int a_line
argument_list|,
argument|int an_index
argument_list|,
argument|int a_write_fd
argument_list|)
block|:
name|file_
argument_list|(
name|a_file
argument_list|)
operator|,
name|line_
argument_list|(
name|a_line
argument_list|)
operator|,
name|index_
argument_list|(
name|an_index
argument_list|)
operator|,
name|write_fd_
argument_list|(
argument|a_write_fd
argument_list|)
block|{}
operator|~
name|InternalRunDeathTestFlag
argument_list|()
block|{
if|if
condition|(
name|write_fd_
operator|>=
literal|0
condition|)
name|posix
operator|::
name|Close
argument_list|(
name|write_fd_
argument_list|)
expr_stmt|;
block|}
name|String
name|file
argument_list|()
specifier|const
block|{
return|return
name|file_
return|;
block|}
name|int
name|line
argument_list|()
specifier|const
block|{
return|return
name|line_
return|;
block|}
name|int
name|index
argument_list|()
specifier|const
block|{
return|return
name|index_
return|;
block|}
name|int
name|write_fd
argument_list|()
specifier|const
block|{
return|return
name|write_fd_
return|;
block|}
name|private
label|:
name|String
name|file_
decl_stmt|;
name|int
name|line_
decl_stmt|;
name|int
name|index_
decl_stmt|;
name|int
name|write_fd_
decl_stmt|;
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|InternalRunDeathTestFlag
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
comment|// Returns a newly created InternalRunDeathTestFlag object with fields
comment|// initialized from the GTEST_FLAG(internal_run_death_test) flag if
comment|// the flag is specified; otherwise returns NULL.
name|InternalRunDeathTestFlag
modifier|*
name|ParseInternalRunDeathTestFlag
parameter_list|()
function_decl|;
else|#
directive|else
comment|// GTEST_HAS_DEATH_TEST
comment|// This macro is used for implementing macros such as
comment|// EXPECT_DEATH_IF_SUPPORTED and ASSERT_DEATH_IF_SUPPORTED on systems where
comment|// death tests are not supported. Those macros must compile on such systems
comment|// iff EXPECT_DEATH and ASSERT_DEATH compile with the same parameters on
comment|// systems that support death tests. This allows one to write such a macro
comment|// on a system that does not support death tests and be sure that it will
comment|// compile on a death-test supporting system.
comment|//
comment|// Parameters:
comment|//   statement -  A statement that a macro such as EXPECT_DEATH would test
comment|//                for program termination. This macro has to make sure this
comment|//                statement is compiled but not executed, to ensure that
comment|//                EXPECT_DEATH_IF_SUPPORTED compiles with a certain
comment|//                parameter iff EXPECT_DEATH compiles with it.
comment|//   regex     -  A regex that a macro such as EXPECT_DEATH would use to test
comment|//                the output of statement.  This parameter has to be
comment|//                compiled but not evaluated by this macro, to ensure that
comment|//                this macro only accepts expressions that a macro such as
comment|//                EXPECT_DEATH would accept.
comment|//   terminator - Must be an empty statement for EXPECT_DEATH_IF_SUPPORTED
comment|//                and a return statement for ASSERT_DEATH_IF_SUPPORTED.
comment|//                This ensures that ASSERT_DEATH_IF_SUPPORTED will not
comment|//                compile inside functions where ASSERT_DEATH doesn't
comment|//                compile.
comment|//
comment|//  The branch that has an always false condition is used to ensure that
comment|//  statement and regex are compiled (and thus syntactically correct) but
comment|//  never executed. The unreachable code macro protects the terminator
comment|//  statement from generating an 'unreachable code' warning in case
comment|//  statement unconditionally returns or throws. The Message constructor at
comment|//  the end allows the syntax of streaming additional messages into the
comment|//  macro, for compilational compatibility with EXPECT_DEATH/ASSERT_DEATH.
define|#
directive|define
name|GTEST_UNSUPPORTED_DEATH_TEST_
parameter_list|(
name|statement
parameter_list|,
name|regex
parameter_list|,
name|terminator
parameter_list|)
define|\
value|GTEST_AMBIGUOUS_ELSE_BLOCKER_ \     if (::testing::internal::AlwaysTrue()) { \       GTEST_LOG_(WARNING) \<< "Death tests are not supported on this platform.\n" \<< "Statement '" #statement "' cannot be verified."; \     } else if (::testing::internal::AlwaysFalse()) { \       ::testing::internal::RE::PartialMatch(".*", (regex)); \       GTEST_SUPPRESS_UNREACHABLE_CODE_WARNING_BELOW_(statement); \       terminator; \     } else \       ::testing::Message()
endif|#
directive|endif
comment|// GTEST_HAS_DEATH_TEST
block|}
comment|// namespace internal
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
comment|// GTEST_INCLUDE_GTEST_INTERNAL_GTEST_DEATH_TEST_INTERNAL_H_
end_comment

end_unit

