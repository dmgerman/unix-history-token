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
comment|// This header file defines the public API for death tests.  It is
end_comment

begin_comment
comment|// #included by gtest.h so a user doesn't need to include this
end_comment

begin_comment
comment|// directly.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GTEST_INCLUDE_GTEST_GTEST_DEATH_TEST_H_
end_ifndef

begin_define
define|#
directive|define
name|GTEST_INCLUDE_GTEST_GTEST_DEATH_TEST_H_
end_define

begin_include
include|#
directive|include
file|<gtest/internal/gtest-death-test-internal.h>
end_include

begin_decl_stmt
name|namespace
name|testing
block|{
comment|// This flag controls the style of death tests.  Valid values are "threadsafe",
comment|// meaning that the death test child process will re-execute the test binary
comment|// from the start, running only a single death test, or "fast",
comment|// meaning that the child process will execute the test logic immediately
comment|// after forking.
name|GTEST_DECLARE_string_
argument_list|(
name|death_test_style
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|GTEST_HAS_DEATH_TEST
comment|// The following macros are useful for writing death tests.
comment|// Here's what happens when an ASSERT_DEATH* or EXPECT_DEATH* is
comment|// executed:
comment|//
comment|//   1. It generates a warning if there is more than one active
comment|//   thread.  This is because it's safe to fork() or clone() only
comment|//   when there is a single thread.
comment|//
comment|//   2. The parent process clone()s a sub-process and runs the death
comment|//   test in it; the sub-process exits with code 0 at the end of the
comment|//   death test, if it hasn't exited already.
comment|//
comment|//   3. The parent process waits for the sub-process to terminate.
comment|//
comment|//   4. The parent process checks the exit code and error message of
comment|//   the sub-process.
comment|//
comment|// Examples:
comment|//
comment|//   ASSERT_DEATH(server.SendMessage(56, "Hello"), "Invalid port number");
comment|//   for (int i = 0; i< 5; i++) {
comment|//     EXPECT_DEATH(server.ProcessRequest(i),
comment|//                  "Invalid request .* in ProcessRequest()")
comment|//<< "Failed to die on request "<< i);
comment|//   }
comment|//
comment|//   ASSERT_EXIT(server.ExitNow(), ::testing::ExitedWithCode(0), "Exiting");
comment|//
comment|//   bool KilledBySIGHUP(int exit_code) {
comment|//     return WIFSIGNALED(exit_code)&& WTERMSIG(exit_code) == SIGHUP;
comment|//   }
comment|//
comment|//   ASSERT_EXIT(client.HangUpServer(), KilledBySIGHUP, "Hanging up!");
comment|//
comment|// Known caveats:
comment|//
comment|//   A "threadsafe" style death test obtains the path to the test
comment|//   program from argv[0] and re-executes it in the sub-process.  For
comment|//   simplicity, the current implementation doesn't search the PATH
comment|//   when launching the sub-process.  This means that the user must
comment|//   invoke the test program via a path that contains at least one
comment|//   path separator (e.g. path/to/foo_test and
comment|//   /absolute/path/to/bar_test are fine, but foo_test is not).  This
comment|//   is rarely a problem as people usually don't put the test binary
comment|//   directory in PATH.
comment|//
comment|// TODO(wan@google.com): make thread-safe death tests search the PATH.
comment|// Asserts that a given statement causes the program to exit, with an
comment|// integer exit status that satisfies predicate, and emitting error output
comment|// that matches regex.
define|#
directive|define
name|ASSERT_EXIT
parameter_list|(
name|statement
parameter_list|,
name|predicate
parameter_list|,
name|regex
parameter_list|)
define|\
value|GTEST_DEATH_TEST_(statement, predicate, regex, GTEST_FATAL_FAILURE_)
comment|// Like ASSERT_EXIT, but continues on to successive tests in the
comment|// test case, if any:
define|#
directive|define
name|EXPECT_EXIT
parameter_list|(
name|statement
parameter_list|,
name|predicate
parameter_list|,
name|regex
parameter_list|)
define|\
value|GTEST_DEATH_TEST_(statement, predicate, regex, GTEST_NONFATAL_FAILURE_)
comment|// Asserts that a given statement causes the program to exit, either by
comment|// explicitly exiting with a nonzero exit code or being killed by a
comment|// signal, and emitting error output that matches regex.
define|#
directive|define
name|ASSERT_DEATH
parameter_list|(
name|statement
parameter_list|,
name|regex
parameter_list|)
define|\
value|ASSERT_EXIT(statement, ::testing::internal::ExitedUnsuccessfully, regex)
comment|// Like ASSERT_DEATH, but continues on to successive tests in the
comment|// test case, if any:
define|#
directive|define
name|EXPECT_DEATH
parameter_list|(
name|statement
parameter_list|,
name|regex
parameter_list|)
define|\
value|EXPECT_EXIT(statement, ::testing::internal::ExitedUnsuccessfully, regex)
comment|// Two predicate classes that can be used in {ASSERT,EXPECT}_EXIT*:
comment|// Tests that an exit code describes a normal exit with a given exit code.
name|class
name|ExitedWithCode
block|{
name|public
label|:
name|explicit
name|ExitedWithCode
parameter_list|(
name|int
name|exit_code
parameter_list|)
function_decl|;
name|bool
name|operator
argument_list|()
operator|(
name|int
name|exit_status
operator|)
specifier|const
expr_stmt|;
name|private
label|:
specifier|const
name|int
name|exit_code_
decl_stmt|;
block|}
empty_stmt|;
comment|// Tests that an exit code describes an exit due to termination by a
comment|// given signal.
name|class
name|KilledBySignal
block|{
name|public
label|:
name|explicit
name|KilledBySignal
parameter_list|(
name|int
name|signum
parameter_list|)
function_decl|;
name|bool
name|operator
argument_list|()
operator|(
name|int
name|exit_status
operator|)
specifier|const
expr_stmt|;
name|private
label|:
specifier|const
name|int
name|signum_
decl_stmt|;
block|}
empty_stmt|;
comment|// EXPECT_DEBUG_DEATH asserts that the given statements die in debug mode.
comment|// The death testing framework causes this to have interesting semantics,
comment|// since the sideeffects of the call are only visible in opt mode, and not
comment|// in debug mode.
comment|//
comment|// In practice, this can be used to test functions that utilize the
comment|// LOG(DFATAL) macro using the following style:
comment|//
comment|// int DieInDebugOr12(int* sideeffect) {
comment|//   if (sideeffect) {
comment|//     *sideeffect = 12;
comment|//   }
comment|//   LOG(DFATAL)<< "death";
comment|//   return 12;
comment|// }
comment|//
comment|// TEST(TestCase, TestDieOr12WorksInDgbAndOpt) {
comment|//   int sideeffect = 0;
comment|//   // Only asserts in dbg.
comment|//   EXPECT_DEBUG_DEATH(DieInDebugOr12(&sideeffect), "death");
comment|//
comment|// #ifdef NDEBUG
comment|//   // opt-mode has sideeffect visible.
comment|//   EXPECT_EQ(12, sideeffect);
comment|// #else
comment|//   // dbg-mode no visible sideeffect.
comment|//   EXPECT_EQ(0, sideeffect);
comment|// #endif
comment|// }
comment|//
comment|// This will assert that DieInDebugReturn12InOpt() crashes in debug
comment|// mode, usually due to a DCHECK or LOG(DFATAL), but returns the
comment|// appropriate fallback value (12 in this case) in opt mode. If you
comment|// need to test that a function has appropriate side-effects in opt
comment|// mode, include assertions against the side-effects.  A general
comment|// pattern for this is:
comment|//
comment|// EXPECT_DEBUG_DEATH({
comment|//   // Side-effects here will have an effect after this statement in
comment|//   // opt mode, but none in debug mode.
comment|//   EXPECT_EQ(12, DieInDebugOr12(&sideeffect));
comment|// }, "death");
comment|//
ifdef|#
directive|ifdef
name|NDEBUG
define|#
directive|define
name|EXPECT_DEBUG_DEATH
parameter_list|(
name|statement
parameter_list|,
name|regex
parameter_list|)
define|\
value|do { statement; } while (false)
define|#
directive|define
name|ASSERT_DEBUG_DEATH
parameter_list|(
name|statement
parameter_list|,
name|regex
parameter_list|)
define|\
value|do { statement; } while (false)
else|#
directive|else
define|#
directive|define
name|EXPECT_DEBUG_DEATH
parameter_list|(
name|statement
parameter_list|,
name|regex
parameter_list|)
define|\
value|EXPECT_DEATH(statement, regex)
define|#
directive|define
name|ASSERT_DEBUG_DEATH
parameter_list|(
name|statement
parameter_list|,
name|regex
parameter_list|)
define|\
value|ASSERT_DEATH(statement, regex)
endif|#
directive|endif
comment|// NDEBUG for EXPECT_DEBUG_DEATH
endif|#
directive|endif
comment|// GTEST_HAS_DEATH_TEST
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
comment|// GTEST_INCLUDE_GTEST_GTEST_DEATH_TEST_H_
end_comment

end_unit

