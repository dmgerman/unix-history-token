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
name|LLVM_CLANG_TOOLS_LIBCLANG_CXCOMMENT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_TOOLS_LIBCLANG_CXCOMMENT_H
end_define

begin_include
include|#
directive|include
file|"CXTranslationUnit.h"
end_include

begin_include
include|#
directive|include
file|"clang-c/Documentation.h"
end_include

begin_include
include|#
directive|include
file|"clang-c/Index.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/ASTContext.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Comment.h"
end_include

begin_include
include|#
directive|include
file|"clang/Frontend/ASTUnit.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|comments
block|{
name|class
name|CommandTraits
decl_stmt|;
block|}
name|namespace
name|cxcomment
block|{
specifier|static
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
argument_list|,
name|CXTranslationUnit
name|TU
argument_list|)
block|{
name|CXComment
name|Result
decl_stmt|;
name|Result
operator|.
name|ASTNode
operator|=
name|C
expr_stmt|;
name|Result
operator|.
name|TranslationUnit
operator|=
name|TU
expr_stmt|;
return|return
name|Result
return|;
block|}
specifier|static
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
name|ASTNode
operator|)
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
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
name|nullptr
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
specifier|static
specifier|inline
name|ASTContext
modifier|&
name|getASTContext
parameter_list|(
name|CXComment
name|CXC
parameter_list|)
block|{
return|return
name|cxtu
operator|::
name|getASTUnit
argument_list|(
name|CXC
operator|.
name|TranslationUnit
argument_list|)
operator|->
name|getASTContext
argument_list|()
return|;
block|}
specifier|static
specifier|inline
name|comments
operator|::
name|CommandTraits
operator|&
name|getCommandTraits
argument_list|(
argument|CXComment CXC
argument_list|)
block|{
return|return
name|getASTContext
argument_list|(
name|CXC
argument_list|)
operator|.
name|getCommentCommandTraits
argument_list|()
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

