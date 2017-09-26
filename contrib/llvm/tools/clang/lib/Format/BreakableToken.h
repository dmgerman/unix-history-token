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
comment|/// \brief Declares BreakableToken, BreakableStringLiteral, BreakableComment,
end_comment

begin_comment
comment|/// BreakableBlockComment and BreakableLineCommentSection classes, that contain
end_comment

begin_comment
comment|/// token type-specific logic to break long lines in tokens and reflow content
end_comment

begin_comment
comment|/// between tokens.
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
name|LLVM_CLANG_LIB_FORMAT_BREAKABLETOKEN_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_FORMAT_BREAKABLETOKEN_H
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
file|"llvm/Support/Regex.h"
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
comment|/// \brief Checks if \p Token switches formatting, like /* clang-format off */.
comment|/// \p Token must be a comment.
name|bool
name|switchesFormatting
parameter_list|(
specifier|const
name|FormatToken
modifier|&
name|Token
parameter_list|)
function_decl|;
struct_decl|struct
name|FormatStyle
struct_decl|;
comment|/// \brief Base class for strategies on how to break tokens.
comment|///
comment|/// This is organised around the concept of a \c Split, which is a whitespace
comment|/// range that signifies a position of the content of a token where a
comment|/// reformatting might be done. Operating with splits is divided into 3
comment|/// operations:
comment|/// - getSplit, for finding a split starting at a position,
comment|/// - getLineLengthAfterSplit, for calculating the size in columns of the rest
comment|///   of the content after a split has been used for breaking, and
comment|/// - insertBreak, for executing the split using a whitespace manager.
comment|///
comment|/// There is a pair of operations that are used to compress a long whitespace
comment|/// range with a single space if that will bring the line lenght under the
comment|/// column limit:
comment|/// - getLineLengthAfterCompression, for calculating the size in columns of the
comment|///   line after a whitespace range has been compressed, and
comment|/// - compressWhitespace, for executing the whitespace compression using a
comment|///   whitespace manager; note that the compressed whitespace may be in the
comment|///   middle of the original line and of the reformatted line.
comment|///
comment|/// For tokens where the whitespace before each line needs to be also
comment|/// reformatted, for example for tokens supporting reflow, there are analogous
comment|/// operations that might be executed before the main line breaking occurs:
comment|/// - getSplitBefore, for finding a split such that the content preceding it
comment|///   needs to be specially reflown,
comment|/// - getLineLengthAfterSplitBefore, for calculating the line length in columns
comment|///   of the remainder of the content after the beginning of the content has
comment|///   been reformatted, and
comment|/// - replaceWhitespaceBefore, for executing the reflow using a whitespace
comment|///   manager.
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
comment|/// at \p LineIndex, from byte offset \p TailOffset with length \p Length.
comment|///
comment|/// Note that previous breaks are not taken into account. \p TailOffset is
comment|/// always specified from the start of the (original) line.
comment|/// \p Length can be set to StringRef::npos, which means "to the end of line".
name|virtual
name|unsigned
name|getLineLengthAfterSplit
argument_list|(
name|unsigned
name|LineIndex
argument_list|,
name|unsigned
name|TailOffset
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
argument_list|,
name|llvm
operator|::
name|Regex
operator|&
name|CommentPragmasRegex
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
comment|/// \brief Returns the number of columns required to format the piece of line
comment|/// at \p LineIndex, from byte offset \p TailOffset after the whitespace range
comment|/// \p Split has been compressed into a single space.
name|unsigned
name|getLineLengthAfterCompression
argument_list|(
name|unsigned
name|RemainingTokenColumns
argument_list|,
name|Split
name|Split
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Replaces the whitespace range described by \p Split with a single
comment|/// space.
name|virtual
name|void
name|compressWhitespace
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
comment|/// \brief Returns a whitespace range (offset, length) of the content at
comment|/// \p LineIndex such that the content preceding this range needs to be
comment|/// reformatted before any breaks are made to this line.
comment|///
comment|/// \p PreviousEndColumn is the end column of the previous line after
comment|/// formatting.
comment|///
comment|/// A result having offset == StringRef::npos means that no piece of the line
comment|/// needs to be reformatted before any breaks are made.
name|virtual
name|Split
name|getSplitBefore
argument_list|(
name|unsigned
name|LineIndex
argument_list|,
name|unsigned
name|PreviousEndColumn
argument_list|,
name|unsigned
name|ColumnLimit
argument_list|,
name|llvm
operator|::
name|Regex
operator|&
name|CommentPragmasRegex
argument_list|)
decl|const
block|{
return|return
name|Split
argument_list|(
name|StringRef
operator|::
name|npos
argument_list|,
literal|0
argument_list|)
return|;
block|}
comment|/// \brief Returns the number of columns required to format the piece of line
comment|/// at \p LineIndex after the content preceding the whitespace range specified
comment|/// \p SplitBefore has been reformatted, but before any breaks are made to
comment|/// this line.
name|virtual
name|unsigned
name|getLineLengthAfterSplitBefore
argument_list|(
name|unsigned
name|LineIndex
argument_list|,
name|unsigned
name|TailOffset
argument_list|,
name|unsigned
name|PreviousEndColumn
argument_list|,
name|unsigned
name|ColumnLimit
argument_list|,
name|Split
name|SplitBefore
argument_list|)
decl|const
block|{
return|return
name|getLineLengthAfterSplit
argument_list|(
name|LineIndex
argument_list|,
name|TailOffset
argument_list|,
name|StringRef
operator|::
name|npos
argument_list|)
return|;
block|}
comment|/// \brief Replaces the whitespace between \p LineIndex-1 and \p LineIndex.
comment|/// Performs a reformatting of the content at \p LineIndex preceding the
comment|/// whitespace range \p SplitBefore.
name|virtual
name|void
name|replaceWhitespaceBefore
parameter_list|(
name|unsigned
name|LineIndex
parameter_list|,
name|unsigned
name|PreviousEndColumn
parameter_list|,
name|unsigned
name|ColumnLimit
parameter_list|,
name|Split
name|SplitBefore
parameter_list|,
name|WhitespaceManager
modifier|&
name|Whitespaces
parameter_list|)
block|{}
comment|/// \brief Updates the next token of \p State to the next token after this
comment|/// one. This can be used when this token manages a set of underlying tokens
comment|/// as a unit and is responsible for the formatting of the them.
name|virtual
name|void
name|updateNextToken
argument_list|(
name|LineState
operator|&
name|State
argument_list|)
decl|const
block|{}
name|protected
label|:
name|BreakableToken
argument_list|(
argument|const FormatToken&Tok
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
name|unsigned
name|getLineCount
argument_list|()
specifier|const
name|override
block|;
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
name|override
block|;
name|protected
operator|:
name|BreakableSingleLineToken
argument_list|(
argument|const FormatToken&Tok
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
name|Split
name|getSplit
argument_list|(
argument|unsigned LineIndex
argument_list|,
argument|unsigned TailOffset
argument_list|,
argument|unsigned ColumnLimit
argument_list|,
argument|llvm::Regex&CommentPragmasRegex
argument_list|)
specifier|const
name|override
block|;
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
name|override
block|;
name|void
name|compressWhitespace
argument_list|(
argument|unsigned LineIndex
argument_list|,
argument|unsigned TailOffset
argument_list|,
argument|Split Split
argument_list|,
argument|WhitespaceManager&Whitespaces
argument_list|)
name|override
block|{}
block|}
decl_stmt|;
name|class
name|BreakableComment
range|:
name|public
name|BreakableToken
block|{
name|protected
operator|:
comment|/// \brief Creates a breakable token for a comment.
comment|///
comment|/// \p StartColumn specifies the column in which the comment will start after
comment|/// formatting.
name|BreakableComment
argument_list|(
argument|const FormatToken&Token
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
name|public
operator|:
name|unsigned
name|getLineCount
argument_list|()
specifier|const
name|override
block|;
name|Split
name|getSplit
argument_list|(
argument|unsigned LineIndex
argument_list|,
argument|unsigned TailOffset
argument_list|,
argument|unsigned ColumnLimit
argument_list|,
argument|llvm::Regex&CommentPragmasRegex
argument_list|)
specifier|const
name|override
block|;
name|void
name|compressWhitespace
argument_list|(
argument|unsigned LineIndex
argument_list|,
argument|unsigned TailOffset
argument_list|,
argument|Split Split
argument_list|,
argument|WhitespaceManager&Whitespaces
argument_list|)
name|override
block|;
name|protected
operator|:
name|virtual
name|unsigned
name|getContentStartColumn
argument_list|(
argument|unsigned LineIndex
argument_list|,
argument|unsigned TailOffset
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|// Returns a split that divides Text into a left and right parts, such that
comment|// the left part is suitable for reflowing after PreviousEndColumn.
name|Split
name|getReflowSplit
argument_list|(
argument|StringRef Text
argument_list|,
argument|StringRef ReflowPrefix
argument_list|,
argument|unsigned PreviousEndColumn
argument_list|,
argument|unsigned ColumnLimit
argument_list|)
specifier|const
block|;
comment|// Returns the token containing the line at LineIndex.
specifier|const
name|FormatToken
operator|&
name|tokenAt
argument_list|(
argument|unsigned LineIndex
argument_list|)
specifier|const
block|;
comment|// Checks if the content of line LineIndex may be reflown with the previous
comment|// line.
name|virtual
name|bool
name|mayReflow
argument_list|(
argument|unsigned LineIndex
argument_list|,
argument|llvm::Regex&CommentPragmasRegex
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|// Contains the original text of the lines of the block comment.
comment|//
comment|// In case of a block comments, excludes the leading /* in the first line and
comment|// trailing */ in the last line. In case of line comments, excludes the
comment|// leading // and spaces.
name|SmallVector
operator|<
name|StringRef
block|,
literal|16
operator|>
name|Lines
block|;
comment|// Contains the text of the lines excluding all leading and trailing
comment|// whitespace between the lines. Note that the decoration (if present) is also
comment|// not considered part of the text.
name|SmallVector
operator|<
name|StringRef
block|,
literal|16
operator|>
name|Content
block|;
comment|// Tokens[i] contains a reference to the token containing Lines[i] if the
comment|// whitespace range before that token is managed by this block.
comment|// Otherwise, Tokens[i] is a null pointer.
name|SmallVector
operator|<
name|FormatToken
operator|*
block|,
literal|16
operator|>
name|Tokens
block|;
comment|// ContentColumn[i] is the target column at which Content[i] should be.
comment|// Note that this excludes a leading "* " or "*" in case of block comments
comment|// where all lines have a "*" prefix, or the leading "// " or "//" in case of
comment|// line comments.
comment|//
comment|// In block comments, the first line's target column is always positive. The
comment|// remaining lines' target columns are relative to the first line to allow
comment|// correct indentation of comments in \c WhitespaceManager. Thus they can be
comment|// negative as well (in case the first line needs to be unindented more than
comment|// there's actual whitespace in another line).
name|SmallVector
operator|<
name|int
block|,
literal|16
operator|>
name|ContentColumn
block|;
comment|// The intended start column of the first line of text from this section.
name|unsigned
name|StartColumn
block|;
comment|// The prefix to use in front a line that has been reflown up.
comment|// For example, when reflowing the second line after the first here:
comment|// // comment 1
comment|// // comment 2
comment|// we expect:
comment|// // comment 1 comment 2
comment|// and not:
comment|// // comment 1comment 2
name|StringRef
name|ReflowPrefix
operator|=
literal|" "
block|; }
decl_stmt|;
name|class
name|BreakableBlockComment
range|:
name|public
name|BreakableComment
block|{
name|public
operator|:
name|BreakableBlockComment
argument_list|(
argument|const FormatToken&Token
argument_list|,
argument|unsigned StartColumn
argument_list|,
argument|unsigned OriginalStartColumn
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
name|override
block|;
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
name|override
block|;
name|Split
name|getSplitBefore
argument_list|(
argument|unsigned LineIndex
argument_list|,
argument|unsigned PreviousEndColumn
argument_list|,
argument|unsigned ColumnLimit
argument_list|,
argument|llvm::Regex&CommentPragmasRegex
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|getLineLengthAfterSplitBefore
argument_list|(
argument|unsigned LineIndex
argument_list|,
argument|unsigned TailOffset
argument_list|,
argument|unsigned PreviousEndColumn
argument_list|,
argument|unsigned ColumnLimit
argument_list|,
argument|Split SplitBefore
argument_list|)
specifier|const
name|override
block|;
name|void
name|replaceWhitespaceBefore
argument_list|(
argument|unsigned LineIndex
argument_list|,
argument|unsigned PreviousEndColumn
argument_list|,
argument|unsigned ColumnLimit
argument_list|,
argument|Split SplitBefore
argument_list|,
argument|WhitespaceManager&Whitespaces
argument_list|)
name|override
block|;
name|bool
name|mayReflow
argument_list|(
argument|unsigned LineIndex
argument_list|,
argument|llvm::Regex&CommentPragmasRegex
argument_list|)
specifier|const
name|override
block|;
name|private
operator|:
comment|// Rearranges the whitespace between Lines[LineIndex-1] and Lines[LineIndex].
comment|//
comment|// Updates Content[LineIndex-1] and Content[LineIndex] by stripping off
comment|// leading and trailing whitespace.
comment|//
comment|// Sets ContentColumn to the intended column in which the text at
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
comment|// Computes the end column if the full Content from LineIndex gets reflown
comment|// after PreviousEndColumn.
name|unsigned
name|getReflownColumn
argument_list|(
argument|StringRef Content
argument_list|,
argument|unsigned LineIndex
argument_list|,
argument|unsigned PreviousEndColumn
argument_list|)
specifier|const
block|;
name|unsigned
name|getContentStartColumn
argument_list|(
argument|unsigned LineIndex
argument_list|,
argument|unsigned TailOffset
argument_list|)
specifier|const
name|override
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
block|;
comment|// If this block comment has decorations, this is the column of the start of
comment|// the decorations.
name|unsigned
name|DecorationColumn
block|; }
decl_stmt|;
name|class
name|BreakableLineCommentSection
range|:
name|public
name|BreakableComment
block|{
name|public
operator|:
name|BreakableLineCommentSection
argument_list|(
argument|const FormatToken&Token
argument_list|,
argument|unsigned StartColumn
argument_list|,
argument|unsigned OriginalStartColumn
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
name|override
block|;
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
name|override
block|;
name|Split
name|getSplitBefore
argument_list|(
argument|unsigned LineIndex
argument_list|,
argument|unsigned PreviousEndColumn
argument_list|,
argument|unsigned ColumnLimit
argument_list|,
argument|llvm::Regex&CommentPragmasRegex
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|getLineLengthAfterSplitBefore
argument_list|(
argument|unsigned LineIndex
argument_list|,
argument|unsigned TailOffset
argument_list|,
argument|unsigned PreviousEndColumn
argument_list|,
argument|unsigned ColumnLimit
argument_list|,
argument|Split SplitBefore
argument_list|)
specifier|const
name|override
block|;
name|void
name|replaceWhitespaceBefore
argument_list|(
argument|unsigned LineIndex
argument_list|,
argument|unsigned PreviousEndColumn
argument_list|,
argument|unsigned ColumnLimit
argument_list|,
argument|Split SplitBefore
argument_list|,
argument|WhitespaceManager&Whitespaces
argument_list|)
name|override
block|;
name|void
name|updateNextToken
argument_list|(
argument|LineState&State
argument_list|)
specifier|const
name|override
block|;
name|bool
name|mayReflow
argument_list|(
argument|unsigned LineIndex
argument_list|,
argument|llvm::Regex&CommentPragmasRegex
argument_list|)
specifier|const
name|override
block|;
name|private
operator|:
name|unsigned
name|getContentStartColumn
argument_list|(
argument|unsigned LineIndex
argument_list|,
argument|unsigned TailOffset
argument_list|)
specifier|const
name|override
block|;
comment|// OriginalPrefix[i] contains the original prefix of line i, including
comment|// trailing whitespace before the start of the content. The indentation
comment|// preceding the prefix is not included.
comment|// For example, if the line is:
comment|// // content
comment|// then the original prefix is "// ".
name|SmallVector
operator|<
name|StringRef
block|,
literal|16
operator|>
name|OriginalPrefix
block|;
comment|// Prefix[i] contains the intended leading "//" with trailing spaces to
comment|// account for the indentation of content within the comment at line i after
comment|// formatting. It can be different than the original prefix when the original
comment|// line starts like this:
comment|// //content
comment|// Then the original prefix is "//", but the prefix is "// ".
name|SmallVector
operator|<
name|StringRef
block|,
literal|16
operator|>
name|Prefix
block|;
name|SmallVector
operator|<
name|unsigned
block|,
literal|16
operator|>
name|OriginalContentColumn
block|;
comment|/// \brief The token to which the last line of this breakable token belongs
comment|/// to; nullptr if that token is the initial token.
comment|///
comment|/// The distinction is because if the token of the last line of this breakable
comment|/// token is distinct from the initial token, this breakable token owns the
comment|/// whitespace before the token of the last line, and the whitespace manager
comment|/// must be able to modify it.
name|FormatToken
operator|*
name|LastLineTok
operator|=
name|nullptr
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

end_unit

