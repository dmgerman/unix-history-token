begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- FixIt.h - FixIt Hint utilities -------------------------*- C++ -*-===//
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
comment|//  This file implements functions to ease source rewriting from AST-nodes.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Example swapping A and B expressions:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//    Expr *A, *B;
end_comment

begin_comment
comment|//    tooling::fixit::createReplacement(*A, *B);
end_comment

begin_comment
comment|//    tooling::fixit::createReplacement(*B, *A);
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
name|LLVM_CLANG_TOOLING_FIXIT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_TOOLING_FIXIT_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/ASTContext.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|tooling
block|{
name|namespace
name|fixit
block|{
name|namespace
name|internal
block|{
name|StringRef
name|getText
parameter_list|(
name|SourceRange
name|Range
parameter_list|,
specifier|const
name|ASTContext
modifier|&
name|Context
parameter_list|)
function_decl|;
comment|/// \brief Returns the SourceRange of a SourceRange. This identity function is
comment|///        used by the following template abstractions.
specifier|inline
name|SourceRange
name|getSourceRange
parameter_list|(
specifier|const
name|SourceRange
modifier|&
name|Range
parameter_list|)
block|{
return|return
name|Range
return|;
block|}
comment|/// \brief Returns the SourceRange of the token at Location \p Loc.
specifier|inline
name|SourceRange
name|getSourceRange
parameter_list|(
specifier|const
name|SourceLocation
modifier|&
name|Loc
parameter_list|)
block|{
return|return
name|SourceRange
argument_list|(
name|Loc
argument_list|)
return|;
block|}
comment|/// \brief Returns the SourceRange of an given Node. \p Node is typically a
comment|///        'Stmt', 'Expr' or a 'Decl'.
name|template
operator|<
name|typename
name|T
operator|>
name|SourceRange
name|getSourceRange
argument_list|(
argument|const T&Node
argument_list|)
block|{
return|return
name|Node
operator|.
name|getSourceRange
argument_list|()
return|;
block|}
block|}
comment|// end namespace internal
comment|// \brief Returns a textual representation of \p Node.
name|template
operator|<
name|typename
name|T
operator|>
name|StringRef
name|getText
argument_list|(
argument|const T&Node
argument_list|,
argument|const ASTContext&Context
argument_list|)
block|{
return|return
name|internal
operator|::
name|getText
argument_list|(
name|internal
operator|::
name|getSourceRange
argument_list|(
name|Node
argument_list|)
argument_list|,
name|Context
argument_list|)
return|;
block|}
comment|// \brief Returns a FixItHint to remove \p Node.
comment|// TODO: Add support for related syntactical elements (i.e. comments, ...).
name|template
operator|<
name|typename
name|T
operator|>
name|FixItHint
name|createRemoval
argument_list|(
argument|const T&Node
argument_list|)
block|{
return|return
name|FixItHint
operator|::
name|CreateRemoval
argument_list|(
name|internal
operator|::
name|getSourceRange
argument_list|(
name|Node
argument_list|)
argument_list|)
return|;
block|}
comment|// \brief Returns a FixItHint to replace \p Destination by \p Source.
name|template
operator|<
name|typename
name|D
operator|,
name|typename
name|S
operator|>
name|FixItHint
name|createReplacement
argument_list|(
argument|const D&Destination
argument_list|,
argument|const S&Source
argument_list|,
argument|const ASTContext&Context
argument_list|)
block|{
return|return
name|FixItHint
operator|::
name|CreateReplacement
argument_list|(
name|internal
operator|::
name|getSourceRange
argument_list|(
name|Destination
argument_list|)
argument_list|,
name|getText
argument_list|(
name|Source
argument_list|,
name|Context
argument_list|)
argument_list|)
return|;
block|}
comment|// \brief Returns a FixItHint to replace \p Destination by \p Source.
name|template
operator|<
name|typename
name|D
operator|>
name|FixItHint
name|createReplacement
argument_list|(
argument|const D&Destination
argument_list|,
argument|StringRef Source
argument_list|)
block|{
return|return
name|FixItHint
operator|::
name|CreateReplacement
argument_list|(
name|internal
operator|::
name|getSourceRange
argument_list|(
name|Destination
argument_list|)
argument_list|,
name|Source
argument_list|)
return|;
block|}
block|}
comment|// end namespace fixit
block|}
comment|// end namespace tooling
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_TOOLING_FIXINT_H
end_comment

end_unit

