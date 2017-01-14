begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Copyright 2013, Google Inc.
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
comment|// Author: marcus.boerger@google.com (Marcus Boerger)
end_comment

begin_comment
comment|// Google Mock - a framework for writing C++ mock classes.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file implements some matchers that depend on gmock-generated-matchers.h.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Note that tests are implemented in gmock-matchers_test.cc rather than
end_comment

begin_comment
comment|// gmock-more-matchers-test.cc.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GMOCK_GMOCK_MORE_MATCHERS_H_
end_ifndef

begin_define
define|#
directive|define
name|GMOCK_GMOCK_MORE_MATCHERS_H_
end_define

begin_include
include|#
directive|include
file|"gmock/gmock-generated-matchers.h"
end_include

begin_decl_stmt
name|namespace
name|testing
block|{
comment|// Defines a matcher that matches an empty container. The container must
comment|// support both size() and empty(), which all STL-like containers provide.
name|MATCHER
argument_list|(
argument|IsEmpty
argument_list|,
argument|negation ?
literal|"isn't empty"
argument|:
literal|"is empty"
argument_list|)
block|{
if|if
condition|(
name|arg
operator|.
name|empty
argument_list|()
condition|)
block|{
return|return
name|true
return|;
block|}
operator|*
name|result_listener
operator|<<
literal|"whose size is "
operator|<<
name|arg
operator|.
name|size
argument_list|()
expr_stmt|;
return|return
name|false
return|;
block|}
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
comment|// GMOCK_GMOCK_MORE_MATCHERS_H_
end_comment

end_unit

