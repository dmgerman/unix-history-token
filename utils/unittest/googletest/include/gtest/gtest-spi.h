begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Copyright 2007, Google Inc.
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
comment|// Utilities for testing Google Test itself and code that uses Google Test
end_comment

begin_comment
comment|// (e.g. frameworks built on top of Google Test).
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GTEST_INCLUDE_GTEST_GTEST_SPI_H_
end_ifndef

begin_define
define|#
directive|define
name|GTEST_INCLUDE_GTEST_GTEST_SPI_H_
end_define

begin_include
include|#
directive|include
file|<gtest/gtest.h>
end_include

begin_decl_stmt
name|namespace
name|testing
block|{
comment|// This helper class can be used to mock out Google Test failure reporting
comment|// so that we can test Google Test or code that builds on Google Test.
comment|//
comment|// An object of this class appends a TestPartResult object to the
comment|// TestPartResultArray object given in the constructor whenever a Google Test
comment|// failure is reported. It can either intercept only failures that are
comment|// generated in the same thread that created this object or it can intercept
comment|// all generated failures. The scope of this mock object can be controlled with
comment|// the second argument to the two arguments constructor.
name|class
name|ScopedFakeTestPartResultReporter
range|:
name|public
name|TestPartResultReporterInterface
block|{
name|public
operator|:
comment|// The two possible mocking modes of this object.
expr|enum
name|InterceptMode
block|{
name|INTERCEPT_ONLY_CURRENT_THREAD
block|,
comment|// Intercepts only thread local failures.
name|INTERCEPT_ALL_THREADS
comment|// Intercepts all failures.
block|}
block|;
comment|// The c'tor sets this object as the test part result reporter used
comment|// by Google Test.  The 'result' parameter specifies where to report the
comment|// results. This reporter will only catch failures generated in the current
comment|// thread. DEPRECATED
name|explicit
name|ScopedFakeTestPartResultReporter
argument_list|(
name|TestPartResultArray
operator|*
name|result
argument_list|)
block|;
comment|// Same as above, but you can choose the interception scope of this object.
name|ScopedFakeTestPartResultReporter
argument_list|(
argument|InterceptMode intercept_mode
argument_list|,
argument|TestPartResultArray* result
argument_list|)
block|;
comment|// The d'tor restores the previous test part result reporter.
name|virtual
operator|~
name|ScopedFakeTestPartResultReporter
argument_list|()
block|;
comment|// Appends the TestPartResult object to the TestPartResultArray
comment|// received in the constructor.
comment|//
comment|// This method is from the TestPartResultReporterInterface
comment|// interface.
name|virtual
name|void
name|ReportTestPartResult
argument_list|(
specifier|const
name|TestPartResult
operator|&
name|result
argument_list|)
block|;
name|private
operator|:
name|void
name|Init
argument_list|()
block|;
specifier|const
name|InterceptMode
name|intercept_mode_
block|;
name|TestPartResultReporterInterface
operator|*
name|old_reporter_
block|;
name|TestPartResultArray
operator|*
specifier|const
name|result_
block|;
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|ScopedFakeTestPartResultReporter
argument_list|)
block|; }
decl_stmt|;
name|namespace
name|internal
block|{
comment|// A helper class for implementing EXPECT_FATAL_FAILURE() and
comment|// EXPECT_NONFATAL_FAILURE().  Its destructor verifies that the given
comment|// TestPartResultArray contains exactly one failure that has the given
comment|// type and contains the given substring.  If that's not the case, a
comment|// non-fatal failure will be generated.
name|class
name|SingleFailureChecker
block|{
name|public
label|:
comment|// The constructor remembers the arguments.
name|SingleFailureChecker
argument_list|(
argument|const TestPartResultArray* results
argument_list|,
argument|TestPartResultType type
argument_list|,
argument|const char* substr
argument_list|)
empty_stmt|;
operator|~
name|SingleFailureChecker
argument_list|()
expr_stmt|;
name|private
label|:
specifier|const
name|TestPartResultArray
modifier|*
specifier|const
name|results_
decl_stmt|;
specifier|const
name|TestPartResultType
name|type_
decl_stmt|;
specifier|const
name|String
name|substr_
decl_stmt|;
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|SingleFailureChecker
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
block|}
comment|// namespace internal
block|}
end_decl_stmt

begin_comment
comment|// namespace testing
end_comment

begin_comment
comment|// A set of macros for testing Google Test assertions or code that's expected
end_comment

begin_comment
comment|// to generate Google Test fatal failures.  It verifies that the given
end_comment

begin_comment
comment|// statement will cause exactly one fatal Google Test failure with 'substr'
end_comment

begin_comment
comment|// being part of the failure message.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// There are two different versions of this macro. EXPECT_FATAL_FAILURE only
end_comment

begin_comment
comment|// affects and considers failures generated in the current thread and
end_comment

begin_comment
comment|// EXPECT_FATAL_FAILURE_ON_ALL_THREADS does the same but for all threads.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The verification of the assertion is done correctly even when the statement
end_comment

begin_comment
comment|// throws an exception or aborts the current function.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Known restrictions:
end_comment

begin_comment
comment|//   - 'statement' cannot reference local non-static variables or
end_comment

begin_comment
comment|//     non-static members of the current object.
end_comment

begin_comment
comment|//   - 'statement' cannot return a value.
end_comment

begin_comment
comment|//   - You cannot stream a failure message to this macro.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Note that even though the implementations of the following two
end_comment

begin_comment
comment|// macros are much alike, we cannot refactor them to use a common
end_comment

begin_comment
comment|// helper macro, due to some peculiarity in how the preprocessor
end_comment

begin_comment
comment|// works.  The AcceptsMacroThatExpandsToUnprotectedComma test in
end_comment

begin_comment
comment|// gtest_unittest.cc will fail to compile if we do that.
end_comment

begin_define
define|#
directive|define
name|EXPECT_FATAL_FAILURE
parameter_list|(
name|statement
parameter_list|,
name|substr
parameter_list|)
define|\
value|do { \     class GTestExpectFatalFailureHelper {\      public:\       static void Execute() { statement; }\     };\     ::testing::TestPartResultArray gtest_failures;\     ::testing::internal::SingleFailureChecker gtest_checker(\&gtest_failures, ::testing::TPRT_FATAL_FAILURE, (substr));\     {\       ::testing::ScopedFakeTestPartResultReporter gtest_reporter(\           ::testing::ScopedFakeTestPartResultReporter:: \           INTERCEPT_ONLY_CURRENT_THREAD,&gtest_failures);\       GTestExpectFatalFailureHelper::Execute();\     }\   } while (false)
end_define

begin_define
define|#
directive|define
name|EXPECT_FATAL_FAILURE_ON_ALL_THREADS
parameter_list|(
name|statement
parameter_list|,
name|substr
parameter_list|)
define|\
value|do { \     class GTestExpectFatalFailureHelper {\      public:\       static void Execute() { statement; }\     };\     ::testing::TestPartResultArray gtest_failures;\     ::testing::internal::SingleFailureChecker gtest_checker(\&gtest_failures, ::testing::TPRT_FATAL_FAILURE, (substr));\     {\       ::testing::ScopedFakeTestPartResultReporter gtest_reporter(\           ::testing::ScopedFakeTestPartResultReporter:: \           INTERCEPT_ALL_THREADS,&gtest_failures);\       GTestExpectFatalFailureHelper::Execute();\     }\   } while (false)
end_define

begin_comment
comment|// A macro for testing Google Test assertions or code that's expected to
end_comment

begin_comment
comment|// generate Google Test non-fatal failures.  It asserts that the given
end_comment

begin_comment
comment|// statement will cause exactly one non-fatal Google Test failure with 'substr'
end_comment

begin_comment
comment|// being part of the failure message.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// There are two different versions of this macro. EXPECT_NONFATAL_FAILURE only
end_comment

begin_comment
comment|// affects and considers failures generated in the current thread and
end_comment

begin_comment
comment|// EXPECT_NONFATAL_FAILURE_ON_ALL_THREADS does the same but for all threads.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// 'statement' is allowed to reference local variables and members of
end_comment

begin_comment
comment|// the current object.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The verification of the assertion is done correctly even when the statement
end_comment

begin_comment
comment|// throws an exception or aborts the current function.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Known restrictions:
end_comment

begin_comment
comment|//   - You cannot stream a failure message to this macro.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Note that even though the implementations of the following two
end_comment

begin_comment
comment|// macros are much alike, we cannot refactor them to use a common
end_comment

begin_comment
comment|// helper macro, due to some peculiarity in how the preprocessor
end_comment

begin_comment
comment|// works.  The AcceptsMacroThatExpandsToUnprotectedComma test in
end_comment

begin_comment
comment|// gtest_unittest.cc will fail to compile if we do that.
end_comment

begin_define
define|#
directive|define
name|EXPECT_NONFATAL_FAILURE
parameter_list|(
name|statement
parameter_list|,
name|substr
parameter_list|)
define|\
value|do {\     ::testing::TestPartResultArray gtest_failures;\     ::testing::internal::SingleFailureChecker gtest_checker(\&gtest_failures, ::testing::TPRT_NONFATAL_FAILURE, (substr));\     {\       ::testing::ScopedFakeTestPartResultReporter gtest_reporter(\           ::testing::ScopedFakeTestPartResultReporter:: \           INTERCEPT_ONLY_CURRENT_THREAD,&gtest_failures);\       statement;\     }\   } while (false)
end_define

begin_define
define|#
directive|define
name|EXPECT_NONFATAL_FAILURE_ON_ALL_THREADS
parameter_list|(
name|statement
parameter_list|,
name|substr
parameter_list|)
define|\
value|do {\     ::testing::TestPartResultArray gtest_failures;\     ::testing::internal::SingleFailureChecker gtest_checker(\&gtest_failures, ::testing::TPRT_NONFATAL_FAILURE, (substr));\     {\       ::testing::ScopedFakeTestPartResultReporter gtest_reporter(\           ::testing::ScopedFakeTestPartResultReporter::INTERCEPT_ALL_THREADS,\&gtest_failures);\       statement;\     }\   } while (false)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_INCLUDE_GTEST_GTEST_SPI_H_
end_comment

end_unit

