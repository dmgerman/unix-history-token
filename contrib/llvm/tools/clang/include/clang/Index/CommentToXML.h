begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- CommentToXML.h - Convert comments to XML representation ----------===//
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
name|LLVM_CLANG_INDEX_COMMENTTOXML_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_INDEX_COMMENTTOXML_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTContext
decl_stmt|;
name|namespace
name|comments
block|{
name|class
name|FullComment
decl_stmt|;
name|class
name|HTMLTagComment
decl_stmt|;
block|}
name|namespace
name|index
block|{
name|class
name|SimpleFormatContext
decl_stmt|;
name|class
name|CommentToXMLConverter
block|{
name|SimpleFormatContext
modifier|*
name|FormatContext
decl_stmt|;
name|unsigned
name|FormatInMemoryUniqueId
decl_stmt|;
name|public
label|:
name|CommentToXMLConverter
argument_list|()
operator|:
name|FormatContext
argument_list|(
literal|0
argument_list|)
operator|,
name|FormatInMemoryUniqueId
argument_list|(
literal|0
argument_list|)
block|{}
name|void
name|convertCommentToHTML
argument_list|(
specifier|const
name|comments
operator|::
name|FullComment
operator|*
name|FC
argument_list|,
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|HTML
argument_list|,
specifier|const
name|ASTContext
operator|&
name|Context
argument_list|)
expr_stmt|;
name|void
name|convertHTMLTagNodeToText
argument_list|(
specifier|const
name|comments
operator|::
name|HTMLTagComment
operator|*
name|HTC
argument_list|,
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|Text
argument_list|,
specifier|const
name|ASTContext
operator|&
name|Context
argument_list|)
decl_stmt|;
name|void
name|convertCommentToXML
argument_list|(
specifier|const
name|comments
operator|::
name|FullComment
operator|*
name|FC
argument_list|,
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|XML
argument_list|,
specifier|const
name|ASTContext
operator|&
name|Context
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
block|}
comment|// namespace index
block|}
end_decl_stmt

begin_comment
comment|// namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_INDEX_COMMENTTOXML_H
end_comment

end_unit

