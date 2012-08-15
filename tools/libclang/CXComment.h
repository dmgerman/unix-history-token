begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CXComment.h - Routines for manipulating CXComments -----------------===//
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
comment|// This file defines routines for manipulating CXComments.
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
name|LLVM_CLANG_CXCOMMENT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_CXCOMMENT_H
end_define

begin_include
include|#
directive|include
file|"clang-c/Index.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Comment.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|cxcomment
block|{
specifier|inline
name|CXComment
name|createCXComment
argument_list|(
specifier|const
name|comments
operator|::
name|Comment
operator|*
name|C
argument_list|)
block|{
name|CXComment
name|Result
decl_stmt|;
name|Result
operator|.
name|Data
operator|=
name|C
expr_stmt|;
return|return
name|Result
return|;
block|}
specifier|inline
specifier|const
name|comments
operator|::
name|Comment
operator|*
name|getASTNode
argument_list|(
argument|CXComment CXC
argument_list|)
block|{
return|return
name|static_cast
operator|<
specifier|const
name|comments
operator|::
name|Comment
operator|*
operator|>
operator|(
name|CXC
operator|.
name|Data
operator|)
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
specifier|const
name|T
operator|*
name|getASTNodeAs
argument_list|(
argument|CXComment CXC
argument_list|)
block|{
specifier|const
name|comments
operator|::
name|Comment
operator|*
name|C
operator|=
name|getASTNode
argument_list|(
name|CXC
argument_list|)
block|;
if|if
condition|(
operator|!
name|C
condition|)
return|return
name|NULL
return|;
return|return
name|dyn_cast
operator|<
name|T
operator|>
operator|(
name|C
operator|)
return|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// end namespace cxcomment
end_comment

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

