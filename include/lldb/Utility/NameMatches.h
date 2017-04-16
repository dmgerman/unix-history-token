begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- NameMatches.h -------------------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLDB_UTILITY_NAMEMATCHES_H
end_ifndef

begin_define
define|#
directive|define
name|LLDB_UTILITY_NAMEMATCHES_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|enum
name|class
name|NameMatch
block|{
name|Ignore
operator|,
name|Equals
operator|,
name|Contains
operator|,
name|StartsWith
operator|,
name|EndsWith
operator|,
name|RegularExpression
block|}
empty_stmt|;
name|bool
name|NameMatches
argument_list|(
name|llvm
operator|::
name|StringRef
name|name
argument_list|,
name|NameMatch
name|match_type
argument_list|,
name|llvm
operator|::
name|StringRef
name|match
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

