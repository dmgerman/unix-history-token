begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Copyright 2008, Google Inc.
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
comment|// Author: mheule@google.com (Markus Heule)
end_comment

begin_comment
comment|//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GTEST_INCLUDE_GTEST_GTEST_TEST_PART_H_
end_ifndef

begin_define
define|#
directive|define
name|GTEST_INCLUDE_GTEST_GTEST_TEST_PART_H_
end_define

begin_include
include|#
directive|include
file|<iosfwd>
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

begin_decl_stmt
name|namespace
name|testing
block|{
comment|// A copyable object representing the result of a test part (i.e. an
comment|// assertion or an explicit FAIL(), ADD_FAILURE(), or SUCCESS()).
comment|//
comment|// Don't inherit from TestPartResult as its destructor is not virtual.
name|class
name|GTEST_API_
name|TestPartResult
block|{
name|public
label|:
comment|// The possible outcomes of a test part (i.e. an assertion or an
comment|// explicit SUCCEED(), FAIL(), or ADD_FAILURE()).
enum|enum
name|Type
block|{
name|kSuccess
block|,
comment|// Succeeded.
name|kNonFatalFailure
block|,
comment|// Failed but the test can continue.
name|kFatalFailure
comment|// Failed and the test should be terminated.
block|}
enum|;
comment|// C'tor.  TestPartResult does NOT have a default constructor.
comment|// Always use this constructor (with parameters) to create a
comment|// TestPartResult object.
name|TestPartResult
argument_list|(
argument|Type a_type
argument_list|,
argument|const char* a_file_name
argument_list|,
argument|int a_line_number
argument_list|,
argument|const char* a_message
argument_list|)
block|:
name|type_
argument_list|(
name|a_type
argument_list|)
operator|,
name|file_name_
argument_list|(
name|a_file_name
argument_list|)
operator|,
name|line_number_
argument_list|(
name|a_line_number
argument_list|)
operator|,
name|summary_
argument_list|(
name|ExtractSummary
argument_list|(
name|a_message
argument_list|)
argument_list|)
operator|,
name|message_
argument_list|(
argument|a_message
argument_list|)
block|{   }
comment|// Gets the outcome of the test part.
name|Type
name|type
argument_list|()
specifier|const
block|{
return|return
name|type_
return|;
block|}
comment|// Gets the name of the source file where the test part took place, or
comment|// NULL if it's unknown.
specifier|const
name|char
operator|*
name|file_name
argument_list|()
specifier|const
block|{
return|return
name|file_name_
operator|.
name|c_str
argument_list|()
return|;
block|}
comment|// Gets the line in the source file where the test part took place,
comment|// or -1 if it's unknown.
name|int
name|line_number
argument_list|()
specifier|const
block|{
return|return
name|line_number_
return|;
block|}
comment|// Gets the summary of the failure message.
specifier|const
name|char
operator|*
name|summary
argument_list|()
specifier|const
block|{
return|return
name|summary_
operator|.
name|c_str
argument_list|()
return|;
block|}
comment|// Gets the message associated with the test part.
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
name|c_str
argument_list|()
return|;
block|}
comment|// Returns true iff the test part passed.
name|bool
name|passed
argument_list|()
specifier|const
block|{
return|return
name|type_
operator|==
name|kSuccess
return|;
block|}
comment|// Returns true iff the test part failed.
name|bool
name|failed
argument_list|()
specifier|const
block|{
return|return
name|type_
operator|!=
name|kSuccess
return|;
block|}
comment|// Returns true iff the test part non-fatally failed.
name|bool
name|nonfatally_failed
argument_list|()
specifier|const
block|{
return|return
name|type_
operator|==
name|kNonFatalFailure
return|;
block|}
comment|// Returns true iff the test part fatally failed.
name|bool
name|fatally_failed
argument_list|()
specifier|const
block|{
return|return
name|type_
operator|==
name|kFatalFailure
return|;
block|}
name|private
label|:
name|Type
name|type_
decl_stmt|;
comment|// Gets the summary of the failure message by omitting the stack
comment|// trace in it.
specifier|static
name|internal
operator|::
name|String
name|ExtractSummary
argument_list|(
specifier|const
name|char
operator|*
name|message
argument_list|)
expr_stmt|;
comment|// The name of the source file where the test part took place, or
comment|// NULL if the source file is unknown.
name|internal
operator|::
name|String
name|file_name_
expr_stmt|;
comment|// The line in the source file where the test part took place, or -1
comment|// if the line number is unknown.
name|int
name|line_number_
decl_stmt|;
name|internal
operator|::
name|String
name|summary_
expr_stmt|;
comment|// The test failure summary.
name|internal
operator|::
name|String
name|message_
expr_stmt|;
comment|// The test failure message.
block|}
empty_stmt|;
comment|// Prints a TestPartResult object.
name|std
operator|::
name|ostream
operator|&
name|operator
operator|<<
operator|(
name|std
operator|::
name|ostream
operator|&
name|os
operator|,
specifier|const
name|TestPartResult
operator|&
name|result
operator|)
expr_stmt|;
comment|// An array of TestPartResult objects.
comment|//
comment|// Don't inherit from TestPartResultArray as its destructor is not
comment|// virtual.
name|class
name|GTEST_API_
name|TestPartResultArray
block|{
name|public
label|:
name|TestPartResultArray
argument_list|()
block|{}
comment|// Appends the given TestPartResult to the array.
name|void
name|Append
parameter_list|(
specifier|const
name|TestPartResult
modifier|&
name|result
parameter_list|)
function_decl|;
comment|// Returns the TestPartResult at the given index (0-based).
specifier|const
name|TestPartResult
modifier|&
name|GetTestPartResult
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
comment|// Returns the number of TestPartResult objects in the array.
name|int
name|size
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|std
operator|::
name|vector
operator|<
name|TestPartResult
operator|>
name|array_
expr_stmt|;
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|TestPartResultArray
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
comment|// This interface knows how to report a test part result.
name|class
name|TestPartResultReporterInterface
block|{
name|public
label|:
name|virtual
operator|~
name|TestPartResultReporterInterface
argument_list|()
expr_stmt|;
name|virtual
name|void
name|ReportTestPartResult
parameter_list|(
specifier|const
name|TestPartResult
modifier|&
name|result
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
name|namespace
name|internal
block|{
comment|// This helper class is used by {ASSERT|EXPECT}_NO_FATAL_FAILURE to check if a
comment|// statement generates new fatal failures. To do so it registers itself as the
comment|// current test part result reporter. Besides checking if fatal failures were
comment|// reported, it only delegates the reporting to the former result reporter.
comment|// The original result reporter is restored in the destructor.
comment|// INTERNAL IMPLEMENTATION - DO NOT USE IN A USER PROGRAM.
name|class
name|GTEST_API_
name|HasNewFatalFailureHelper
range|:
name|public
name|TestPartResultReporterInterface
block|{
name|public
operator|:
name|HasNewFatalFailureHelper
argument_list|()
block|;
name|virtual
operator|~
name|HasNewFatalFailureHelper
argument_list|()
block|;
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
name|bool
name|has_new_fatal_failure
argument_list|()
specifier|const
block|{
return|return
name|has_new_fatal_failure_
return|;
block|}
name|private
operator|:
name|bool
name|has_new_fatal_failure_
block|;
name|TestPartResultReporterInterface
operator|*
name|original_reporter_
block|;
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|HasNewFatalFailureHelper
argument_list|)
block|; }
decl_stmt|;
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
comment|// GTEST_INCLUDE_GTEST_GTEST_TEST_PART_H_
end_comment

end_unit

