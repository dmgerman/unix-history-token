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
comment|// Google Mock - a framework for writing C++ mock classes.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This is the main header file a user should include.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GMOCK_INCLUDE_GMOCK_GMOCK_H_
end_ifndef

begin_define
define|#
directive|define
name|GMOCK_INCLUDE_GMOCK_GMOCK_H_
end_define

begin_comment
comment|// This file implements the following syntax:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   ON_CALL(mock_object.Method(...))
end_comment

begin_comment
comment|//     .With(...) ?
end_comment

begin_comment
comment|//     .WillByDefault(...);
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// where With() is optional and WillByDefault() must appear exactly
end_comment

begin_comment
comment|// once.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   EXPECT_CALL(mock_object.Method(...))
end_comment

begin_comment
comment|//     .With(...) ?
end_comment

begin_comment
comment|//     .Times(...) ?
end_comment

begin_comment
comment|//     .InSequence(...) *
end_comment

begin_comment
comment|//     .WillOnce(...) *
end_comment

begin_comment
comment|//     .WillRepeatedly(...) ?
end_comment

begin_comment
comment|//     .RetiresOnSaturation() ? ;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// where all clauses are optional and WillOnce() can be repeated.
end_comment

begin_include
include|#
directive|include
file|"gmock/gmock-actions.h"
end_include

begin_include
include|#
directive|include
file|"gmock/gmock-cardinalities.h"
end_include

begin_include
include|#
directive|include
file|"gmock/gmock-generated-actions.h"
end_include

begin_include
include|#
directive|include
file|"gmock/gmock-generated-function-mockers.h"
end_include

begin_include
include|#
directive|include
file|"gmock/gmock-generated-nice-strict.h"
end_include

begin_include
include|#
directive|include
file|"gmock/gmock-generated-matchers.h"
end_include

begin_include
include|#
directive|include
file|"gmock/gmock-matchers.h"
end_include

begin_include
include|#
directive|include
file|"gmock/gmock-more-actions.h"
end_include

begin_include
include|#
directive|include
file|"gmock/gmock-more-matchers.h"
end_include

begin_include
include|#
directive|include
file|"gmock/internal/gmock-internal-utils.h"
end_include

begin_decl_stmt
name|namespace
name|testing
block|{
comment|// Declares Google Mock flags that we want a user to use programmatically.
name|GMOCK_DECLARE_bool_
argument_list|(
name|catch_leaked_mocks
argument_list|)
expr_stmt|;
name|GMOCK_DECLARE_string_
argument_list|(
name|verbose
argument_list|)
expr_stmt|;
comment|// Initializes Google Mock.  This must be called before running the
comment|// tests.  In particular, it parses the command line for the flags
comment|// that Google Mock recognizes.  Whenever a Google Mock flag is seen,
comment|// it is removed from argv, and *argc is decremented.
comment|//
comment|// No value is returned.  Instead, the Google Mock flag variables are
comment|// updated.
comment|//
comment|// Since Google Test is needed for Google Mock to work, this function
comment|// also initializes Google Test and parses its flags, if that hasn't
comment|// been done.
name|GTEST_API_
name|void
name|InitGoogleMock
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
name|GTEST_API_
name|void
name|InitGoogleMock
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
comment|// GMOCK_INCLUDE_GMOCK_GMOCK_H_
end_comment

end_unit

