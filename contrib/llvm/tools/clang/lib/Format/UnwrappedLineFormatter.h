begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- UnwrappedLineFormatter.h - Format C++ code -------------*- C++ -*-===//
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
comment|/// \brief Implements a combinartorial exploration of all the different
end_comment

begin_comment
comment|/// linebreaks unwrapped lines can be formatted in.
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
name|LLVM_CLANG_LIB_FORMAT_UNWRAPPEDLINEFORMATTER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_FORMAT_UNWRAPPEDLINEFORMATTER_H
end_define

begin_include
include|#
directive|include
file|"ContinuationIndenter.h"
end_include

begin_include
include|#
directive|include
file|"clang/Format/Format.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|format
block|{
name|class
name|ContinuationIndenter
decl_stmt|;
name|class
name|WhitespaceManager
decl_stmt|;
name|class
name|UnwrappedLineFormatter
block|{
name|public
label|:
name|UnwrappedLineFormatter
argument_list|(
name|ContinuationIndenter
operator|*
name|Indenter
argument_list|,
name|WhitespaceManager
operator|*
name|Whitespaces
argument_list|,
specifier|const
name|FormatStyle
operator|&
name|Style
argument_list|,
specifier|const
name|AdditionalKeywords
operator|&
name|Keywords
argument_list|,
name|bool
operator|*
name|IncompleteFormat
argument_list|)
operator|:
name|Indenter
argument_list|(
name|Indenter
argument_list|)
operator|,
name|Whitespaces
argument_list|(
name|Whitespaces
argument_list|)
operator|,
name|Style
argument_list|(
name|Style
argument_list|)
operator|,
name|Keywords
argument_list|(
name|Keywords
argument_list|)
operator|,
name|IncompleteFormat
argument_list|(
argument|IncompleteFormat
argument_list|)
block|{}
comment|/// \brief Format the current block and return the penalty.
name|unsigned
name|format
argument_list|(
argument|const SmallVectorImpl<AnnotatedLine *>&Lines
argument_list|,
argument|bool DryRun = false
argument_list|,
argument|int AdditionalIndent =
literal|0
argument_list|,
argument|bool FixBadIndentation = false
argument_list|)
expr_stmt|;
name|private
label|:
comment|/// \brief Add a new line and the required indent before the first Token
comment|/// of the \c UnwrappedLine if there was no structural parsing error.
name|void
name|formatFirstToken
parameter_list|(
specifier|const
name|AnnotatedLine
modifier|&
name|Line
parameter_list|,
specifier|const
name|AnnotatedLine
modifier|*
name|PreviousLine
parameter_list|,
name|unsigned
name|Indent
parameter_list|)
function_decl|;
comment|/// \brief Returns the column limit for a line, taking into account whether we
comment|/// need an escaped newline due to a continued preprocessor directive.
name|unsigned
name|getColumnLimit
argument_list|(
name|bool
name|InPPDirective
argument_list|,
specifier|const
name|AnnotatedLine
operator|*
name|NextLine
argument_list|)
decl|const
decl_stmt|;
comment|// Cache to store the penalty of formatting a vector of AnnotatedLines
comment|// starting from a specific additional offset. Improves performance if there
comment|// are many nested blocks.
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|SmallVectorImpl
operator|<
name|AnnotatedLine
operator|*
operator|>
operator|*
operator|,
name|unsigned
operator|>
operator|,
name|unsigned
operator|>
name|PenaltyCache
expr_stmt|;
name|ContinuationIndenter
modifier|*
name|Indenter
decl_stmt|;
name|WhitespaceManager
modifier|*
name|Whitespaces
decl_stmt|;
specifier|const
name|FormatStyle
modifier|&
name|Style
decl_stmt|;
specifier|const
name|AdditionalKeywords
modifier|&
name|Keywords
decl_stmt|;
name|bool
modifier|*
name|IncompleteFormat
decl_stmt|;
block|}
empty_stmt|;
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

begin_comment
comment|// LLVM_CLANG_LIB_FORMAT_UNWRAPPEDLINEFORMATTER_H
end_comment

end_unit

