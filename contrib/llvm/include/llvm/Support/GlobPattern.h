begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- GlobPattern.h - glob pattern matcher implementation -*- C++ -*-----===//
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

begin_comment
comment|//
end_comment

begin_comment
comment|// This file implements a glob pattern matcher. The glob pattern is the
end_comment

begin_comment
comment|// rule used by the shell.
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
name|LLVM_SUPPORT_GLOB_PATTERN_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_GLOB_PATTERN_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/BitVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_comment
comment|// This class represents a glob pattern. Supported metacharacters
end_comment

begin_comment
comment|// are "*", "?", "[<chars>]" and "[^<chars>]".
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BitVector
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ArrayRef
expr_stmt|;
name|class
name|GlobPattern
block|{
name|public
label|:
specifier|static
name|Expected
operator|<
name|GlobPattern
operator|>
name|create
argument_list|(
argument|StringRef Pat
argument_list|)
expr_stmt|;
name|bool
name|match
argument_list|(
name|StringRef
name|S
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|bool
name|matchOne
argument_list|(
name|ArrayRef
operator|<
name|BitVector
operator|>
name|Pat
argument_list|,
name|StringRef
name|S
argument_list|)
decl|const
decl_stmt|;
comment|// Parsed glob pattern.
name|std
operator|::
name|vector
operator|<
name|BitVector
operator|>
name|Tokens
expr_stmt|;
comment|// The following members are for optimization.
name|Optional
operator|<
name|StringRef
operator|>
name|Exact
expr_stmt|;
name|Optional
operator|<
name|StringRef
operator|>
name|Prefix
expr_stmt|;
name|Optional
operator|<
name|StringRef
operator|>
name|Suffix
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_SUPPORT_GLOB_PATTERN_H
end_comment

end_unit

