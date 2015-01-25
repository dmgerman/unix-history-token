begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- CommentOptions.h - Options for parsing comments -----*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Defines the clang::CommentOptions interface.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_BASIC_COMMENTOPTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_COMMENTOPTIONS_H
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// \brief Options for controlling comment parsing.
struct|struct
name|CommentOptions
block|{
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|BlockCommandNamesTy
expr_stmt|;
comment|/// \brief Command names to treat as block commands in comments.
comment|/// Should not include the leading backslash.
name|BlockCommandNamesTy
name|BlockCommandNames
decl_stmt|;
comment|/// \brief Treat ordinary comments as documentation comments.
name|bool
name|ParseAllComments
decl_stmt|;
name|CommentOptions
argument_list|()
operator|:
name|ParseAllComments
argument_list|(
argument|false
argument_list|)
block|{ }
block|}
struct|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

