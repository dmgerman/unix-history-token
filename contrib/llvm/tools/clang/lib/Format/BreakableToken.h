begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- BreakableToken.h - Format C++ code -------------------------------===//
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
comment|/// \brief Declares BreakableToken, BreakableStringLiteral, and
end_comment

begin_comment
comment|/// BreakableBlockComment classes, that contain token type-specific logic to
end_comment

begin_comment
comment|/// break long lines in tokens.
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
name|LLVM_CLANG_FORMAT_BREAKABLETOKEN_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FORMAT_BREAKABLETOKEN_H
end_define

begin_include
include|#
directive|include
file|"Encoding.h"
end_include

begin_include
include|#
directive|include
file|"TokenAnnotator.h"
end_include

begin_include
include|#
directive|include
file|"WhitespaceManager.h"
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|format
block|{
struct_decl|struct
name|FormatStyle
struct_decl|;
comment|/// \brief Base class for strategies on how to break tokens.
comment|///
comment|/// FIXME: The interface seems set in stone, so we might want to just pull the
comment|/// strategy into the class, instead of controlling it from the outside.
name|class
name|BreakableToken
block|{
name|public
label|:
comment|/// \brief Contains starting character index and length of split.
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|StringRef
operator|::
name|size_type
operator|,
name|unsigned
operator|>
name|Split
expr_stmt|;
name|virtual
operator|~
name|BreakableToken
argument_list|()
block|{}
comment|/// \brief Returns the number of lines in this token in the original code.
name|virtual
name|unsigned
name|getLineCount
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// \brief Returns the number of columns required to format the piece of line
comment|/// at \p LineIndex, from byte offset \p Offset with length \p Length.
comment|///
comment|/// Note that previous breaks are not taken into account. \p Offset is always
comment|/// specified from the start of the (original) line.
comment|/// \p Length can be set to StringRef::npos, which means "to the end of line".
name|virtual
name|unsigned
name|getLineLengthAfterSplit
argument_list|(
name|unsigned
name|LineIndex
argument_list|,
name|unsigned
name|Offset
argument_list|,
name|StringRef
operator|::
name|size_type
name|Length
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// \brief Returns a range (offset, length) at which to break the line at
comment|/// \p LineIndex, if previously broken at \p TailOffset. If possible, do not
comment|/// violate \p ColumnLimit.
name|virtual
name|Split
name|getSplit
argument_list|(
name|unsigned
name|LineIndex
argument_list|,
name|unsigned
name|TailOffset
argument_list|,
name|unsigned
name|ColumnLimit
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// \brief Emits the previously retrieved \p Split via \p Whitespaces.
name|virtual
name|void
name|insertBreak
parameter_list|(
name|unsigned
name|LineIndex
parameter_list|,
name|unsigned
name|TailOffset
parameter_list|,
name|Split
name|Split
parameter_list|,
name|WhitespaceManager
modifier|&
name|Whitespaces
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// \brief Replaces the whitespace range described by \p Split with a single
comment|/// space.
name|virtual
name|void
name|replaceWhitespace
parameter_list|(
name|unsigned
name|LineIndex
parameter_list|,
name|unsigned
name|TailOffset
parameter_list|,
name|Split
name|Split
parameter_list|,
name|WhitespaceManager
modifier|&
name|Whitespaces
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// \brief Replaces the whitespace between \p LineIndex-1 and \p LineIndex.
name|virtual
name|void
name|replaceWhitespaceBefore
parameter_list|(
name|unsigned
name|LineIndex
parameter_list|,
name|WhitespaceManager
modifier|&
name|Whitespaces
parameter_list|)
block|{}
name|protected
label|:
name|BreakableToken
argument_list|(
argument|const FormatToken&Tok
argument_list|,
argument|unsigned IndentLevel
argument_list|,
argument|bool InPPDirective
argument_list|,
argument|encoding::Encoding Encoding
argument_list|,
argument|const FormatStyle&Style
argument_list|)
block|:
name|Tok
argument_list|(
name|Tok
argument_list|)
operator|,
name|IndentLevel
argument_list|(
name|IndentLevel
argument_list|)
operator|,
name|InPPDirective
argument_list|(
name|InPPDirective
argument_list|)
operator|,
name|Encoding
argument_list|(
name|Encoding
argument_list|)
operator|,
name|Style
argument_list|(
argument|Style
argument_list|)
block|{}
specifier|const
name|FormatToken
operator|&
name|Tok
expr_stmt|;
specifier|const
name|unsigned
name|IndentLevel
decl_stmt|;
specifier|const
name|bool
name|InPPDirective
decl_stmt|;
specifier|const
name|encoding
operator|::
name|Encoding
name|Encoding
expr_stmt|;
specifier|const
name|FormatStyle
modifier|&
name|Style
decl_stmt|;
block|}
empty_stmt|;
comment|/// \brief Base class for single line tokens that can be broken.
comment|///
comment|/// \c getSplit() needs to be implemented by child classes.
name|class
name|BreakableSingleLineToken
range|:
name|public
name|BreakableToken
block|{
name|public
operator|:
name|virtual
name|unsigned
name|getLineCount
argument_list|()
specifier|const
block|;
name|virtual
name|unsigned
name|getLineLengthAfterSplit
argument_list|(
argument|unsigned LineIndex
argument_list|,
argument|unsigned TailOffset
argument_list|,
argument|StringRef::size_type Length
argument_list|)
specifier|const
block|;
name|protected
operator|:
name|BreakableSingleLineToken
argument_list|(
argument|const FormatToken&Tok
argument_list|,
argument|unsigned IndentLevel
argument_list|,
argument|unsigned StartColumn
argument_list|,
argument|StringRef Prefix
argument_list|,
argument|StringRef Postfix
argument_list|,
argument|bool InPPDirective
argument_list|,
argument|encoding::Encoding Encoding
argument_list|,
argument|const FormatStyle&Style
argument_list|)
block|;
comment|// The column in which the token starts.
name|unsigned
name|StartColumn
block|;
comment|// The prefix a line needs after a break in the token.
name|StringRef
name|Prefix
block|;
comment|// The postfix a line needs before introducing a break.
name|StringRef
name|Postfix
block|;
comment|// The token text excluding the prefix and postfix.
name|StringRef
name|Line
block|; }
decl_stmt|;
name|class
name|BreakableStringLiteral
range|:
name|public
name|BreakableSingleLineToken
block|{
name|public
operator|:
comment|/// \brief Creates a breakable token for a single line string literal.
comment|///
comment|/// \p StartColumn specifies the column in which the token will start
comment|/// after formatting.
name|BreakableStringLiteral
argument_list|(
argument|const FormatToken&Tok
argument_list|,
argument|unsigned IndentLevel
argument_list|,
argument|unsigned StartColumn
argument_list|,
argument|StringRef Prefix
argument_list|,
argument|StringRef Postfix
argument_list|,
argument|bool InPPDirective
argument_list|,
argument|encoding::Encoding Encoding
argument_list|,
argument|const FormatStyle&Style
argument_list|)
block|;
name|virtual
name|Split
name|getSplit
argument_list|(
argument|unsigned LineIndex
argument_list|,
argument|unsigned TailOffset
argument_list|,
argument|unsigned ColumnLimit
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|insertBreak
argument_list|(
argument|unsigned LineIndex
argument_list|,
argument|unsigned TailOffset
argument_list|,
argument|Split Split
argument_list|,
argument|WhitespaceManager&Whitespaces
argument_list|)
block|;
name|virtual
name|void
name|replaceWhitespace
argument_list|(
argument|unsigned LineIndex
argument_list|,
argument|unsigned TailOffset
argument_list|,
argument|Split Split
argument_list|,
argument|WhitespaceManager&Whitespaces
argument_list|)
block|{}
block|}
decl_stmt|;
name|class
name|BreakableLineComment
range|:
name|public
name|BreakableSingleLineToken
block|{
name|public
operator|:
comment|/// \brief Creates a breakable token for a line comment.
comment|///
comment|/// \p StartColumn specifies the column in which the comment will start
comment|/// after formatting.
name|BreakableLineComment
argument_list|(
argument|const FormatToken&Token
argument_list|,
argument|unsigned IndentLevel
argument_list|,
argument|unsigned StartColumn
argument_list|,
argument|bool InPPDirective
argument_list|,
argument|encoding::Encoding Encoding
argument_list|,
argument|const FormatStyle&Style
argument_list|)
block|;
name|virtual
name|Split
name|getSplit
argument_list|(
argument|unsigned LineIndex
argument_list|,
argument|unsigned TailOffset
argument_list|,
argument|unsigned ColumnLimit
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|insertBreak
argument_list|(
argument|unsigned LineIndex
argument_list|,
argument|unsigned TailOffset
argument_list|,
argument|Split Split
argument_list|,
argument|WhitespaceManager&Whitespaces
argument_list|)
block|;
name|virtual
name|void
name|replaceWhitespace
argument_list|(
argument|unsigned LineIndex
argument_list|,
argument|unsigned TailOffset
argument_list|,
argument|Split Split
argument_list|,
argument|WhitespaceManager&Whitespaces
argument_list|)
block|;
name|virtual
name|void
name|replaceWhitespaceBefore
argument_list|(
argument|unsigned LineIndex
argument_list|,
argument|WhitespaceManager&Whitespaces
argument_list|)
block|;
name|private
operator|:
comment|// The prefix without an additional space if one was added.
name|StringRef
name|OriginalPrefix
block|; }
decl_stmt|;
name|class
name|BreakableBlockComment
range|:
name|public
name|BreakableToken
block|{
name|public
operator|:
comment|/// \brief Creates a breakable token for a block comment.
comment|///
comment|/// \p StartColumn specifies the column in which the comment will start
comment|/// after formatting, while \p OriginalStartColumn specifies in which
comment|/// column the comment started before formatting.
comment|/// If the comment starts a line after formatting, set \p FirstInLine to true.
name|BreakableBlockComment
argument_list|(
argument|const FormatToken&Token
argument_list|,
argument|unsigned IndentLevel
argument_list|,
argument|unsigned StartColumn
argument_list|,
argument|unsigned OriginaStartColumn
argument_list|,
argument|bool FirstInLine
argument_list|,
argument|bool InPPDirective
argument_list|,
argument|encoding::Encoding Encoding
argument_list|,
argument|const FormatStyle&Style
argument_list|)
block|;
name|virtual
name|unsigned
name|getLineCount
argument_list|()
specifier|const
block|;
name|virtual
name|unsigned
name|getLineLengthAfterSplit
argument_list|(
argument|unsigned LineIndex
argument_list|,
argument|unsigned TailOffset
argument_list|,
argument|StringRef::size_type Length
argument_list|)
specifier|const
block|;
name|virtual
name|Split
name|getSplit
argument_list|(
argument|unsigned LineIndex
argument_list|,
argument|unsigned TailOffset
argument_list|,
argument|unsigned ColumnLimit
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|insertBreak
argument_list|(
argument|unsigned LineIndex
argument_list|,
argument|unsigned TailOffset
argument_list|,
argument|Split Split
argument_list|,
argument|WhitespaceManager&Whitespaces
argument_list|)
block|;
name|virtual
name|void
name|replaceWhitespace
argument_list|(
argument|unsigned LineIndex
argument_list|,
argument|unsigned TailOffset
argument_list|,
argument|Split Split
argument_list|,
argument|WhitespaceManager&Whitespaces
argument_list|)
block|;
name|virtual
name|void
name|replaceWhitespaceBefore
argument_list|(
argument|unsigned LineIndex
argument_list|,
argument|WhitespaceManager&Whitespaces
argument_list|)
block|;
name|private
operator|:
comment|// Rearranges the whitespace between Lines[LineIndex-1] and Lines[LineIndex],
comment|// so that all whitespace between the lines is accounted to Lines[LineIndex]
comment|// as leading whitespace:
comment|// - Lines[LineIndex] points to the text after that whitespace
comment|// - Lines[LineIndex-1] shrinks by its trailing whitespace
comment|// - LeadingWhitespace[LineIndex] is updated with the complete whitespace
comment|//   between the end of the text of Lines[LineIndex-1] and Lines[LineIndex]
comment|//
comment|// Sets StartOfLineColumn to the intended column in which the text at
comment|// Lines[LineIndex] starts (note that the decoration, if present, is not
comment|// considered part of the text).
name|void
name|adjustWhitespace
argument_list|(
argument|unsigned LineIndex
argument_list|,
argument|int IndentDelta
argument_list|)
block|;
comment|// Returns the column at which the text in line LineIndex starts, when broken
comment|// at TailOffset. Note that the decoration (if present) is not considered part
comment|// of the text.
name|unsigned
name|getContentStartColumn
argument_list|(
argument|unsigned LineIndex
argument_list|,
argument|unsigned TailOffset
argument_list|)
specifier|const
block|;
comment|// Contains the text of the lines of the block comment, excluding the leading
comment|// /* in the first line and trailing */ in the last line, and excluding all
comment|// trailing whitespace between the lines. Note that the decoration (if
comment|// present) is also not considered part of the text.
name|SmallVector
operator|<
name|StringRef
block|,
literal|16
operator|>
name|Lines
block|;
comment|// LeadingWhitespace[i] is the number of characters regarded as whitespace in
comment|// front of Lines[i]. Note that this can include "* " sequences, which we
comment|// regard as whitespace when all lines have a "*" prefix.
name|SmallVector
operator|<
name|unsigned
block|,
literal|16
operator|>
name|LeadingWhitespace
block|;
comment|// StartOfLineColumn[i] is the target column at which Line[i] should be.
comment|// Note that this excludes a leading "* " or "*" in case all lines have
comment|// a "*" prefix.
name|SmallVector
operator|<
name|unsigned
block|,
literal|16
operator|>
name|StartOfLineColumn
block|;
comment|// The column at which the text of a broken line should start.
comment|// Note that an optional decoration would go before that column.
comment|// IndentAtLineBreak is a uniform position for all lines in a block comment,
comment|// regardless of their relative position.
comment|// FIXME: Revisit the decision to do this; the main reason was to support
comment|// patterns like
comment|// /**************//**
comment|//  * Comment
comment|// We could also support such patterns by special casing the first line
comment|// instead.
name|unsigned
name|IndentAtLineBreak
block|;
comment|// This is to distinguish between the case when the last line was empty and
comment|// the case when it started with a decoration ("*" or "* ").
name|bool
name|LastLineNeedsDecoration
block|;
comment|// Either "* " if all lines begin with a "*", or empty.
name|StringRef
name|Decoration
block|; }
decl_stmt|;
block|}
comment|// namespace format
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
comment|// LLVM_CLANG_FORMAT_BREAKABLETOKEN_H
end_comment

end_unit

