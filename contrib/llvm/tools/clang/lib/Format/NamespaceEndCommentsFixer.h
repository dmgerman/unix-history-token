begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- NamespaceEndCommentsFixer.h ----------------------------*- C++ -*-===//
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
comment|/// \brief This file declares NamespaceEndCommentsFixer, a TokenAnalyzer that
end_comment

begin_comment
comment|/// fixes namespace end comments.
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
name|LLVM_CLANG_LIB_FORMAT_NAMESPACEENDCOMMENTSFIXER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_FORMAT_NAMESPACEENDCOMMENTSFIXER_H
end_define

begin_include
include|#
directive|include
file|"TokenAnalyzer.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|format
block|{
name|class
name|NamespaceEndCommentsFixer
range|:
name|public
name|TokenAnalyzer
block|{
name|public
operator|:
name|NamespaceEndCommentsFixer
argument_list|(
specifier|const
name|Environment
operator|&
name|Env
argument_list|,
specifier|const
name|FormatStyle
operator|&
name|Style
argument_list|)
block|;
name|tooling
operator|::
name|Replacements
name|analyze
argument_list|(
argument|TokenAnnotator&Annotator
argument_list|,
argument|SmallVectorImpl<AnnotatedLine *>&AnnotatedLines
argument_list|,
argument|FormatTokenLexer&Tokens
argument_list|)
name|override
block|; }
decl_stmt|;
block|}
comment|// end namespace format
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

