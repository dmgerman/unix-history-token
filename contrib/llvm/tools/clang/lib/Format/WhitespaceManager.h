begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- WhitespaceManager.h - Format C++ code ------------------*- C++ -*-===//
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
comment|/// \brief WhitespaceManager class manages whitespace around tokens and their
end_comment

begin_comment
comment|/// replacements.
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
name|LLVM_CLANG_LIB_FORMAT_WHITESPACEMANAGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_FORMAT_WHITESPACEMANAGER_H
end_define

begin_include
include|#
directive|include
file|"TokenAnnotator.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceManager.h"
end_include

begin_include
include|#
directive|include
file|"clang/Format/Format.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|format
block|{
comment|/// \brief Manages the whitespaces around tokens and their replacements.
comment|///
comment|/// This includes special handling for certain constructs, e.g. the alignment of
comment|/// trailing line comments.
comment|///
comment|/// To guarantee correctness of alignment operations, the \c WhitespaceManager
comment|/// must be informed about every token in the source file; for each token, there
comment|/// must be exactly one call to either \c replaceWhitespace or
comment|/// \c addUntouchableToken.
comment|///
comment|/// There may be multiple calls to \c breakToken for a given token.
name|class
name|WhitespaceManager
block|{
name|public
label|:
name|WhitespaceManager
argument_list|(
argument|const SourceManager&SourceMgr
argument_list|,
argument|const FormatStyle&Style
argument_list|,
argument|bool UseCRLF
argument_list|)
block|:
name|SourceMgr
argument_list|(
name|SourceMgr
argument_list|)
operator|,
name|Style
argument_list|(
name|Style
argument_list|)
operator|,
name|UseCRLF
argument_list|(
argument|UseCRLF
argument_list|)
block|{}
comment|/// \brief Replaces the whitespace in front of \p Tok. Only call once for
comment|/// each \c AnnotatedToken.
comment|///
comment|/// \p StartOfTokenColumn is the column at which the token will start after
comment|/// this replacement. It is needed for determining how \p Spaces is turned
comment|/// into tabs and spaces for some format styles.
name|void
name|replaceWhitespace
argument_list|(
argument|FormatToken&Tok
argument_list|,
argument|unsigned Newlines
argument_list|,
argument|unsigned Spaces
argument_list|,
argument|unsigned StartOfTokenColumn
argument_list|,
argument|bool InPPDirective = false
argument_list|)
expr_stmt|;
comment|/// \brief Adds information about an unchangeable token's whitespace.
comment|///
comment|/// Needs to be called for every token for which \c replaceWhitespace
comment|/// was not called.
name|void
name|addUntouchableToken
parameter_list|(
specifier|const
name|FormatToken
modifier|&
name|Tok
parameter_list|,
name|bool
name|InPPDirective
parameter_list|)
function_decl|;
comment|/// \brief Inserts or replaces whitespace in the middle of a token.
comment|///
comment|/// Inserts \p PreviousPostfix, \p Newlines, \p Spaces and \p CurrentPrefix
comment|/// (in this order) at \p Offset inside \p Tok, replacing \p ReplaceChars
comment|/// characters.
comment|///
comment|/// Note: \p Spaces can be negative to retain information about initial
comment|/// relative column offset between a line of a block comment and the start of
comment|/// the comment. This negative offset may be compensated by trailing comment
comment|/// alignment here. In all other cases negative \p Spaces will be truncated to
comment|/// 0.
comment|///
comment|/// When \p InPPDirective is true, escaped newlines are inserted. \p Spaces is
comment|/// used to align backslashes correctly.
name|void
name|replaceWhitespaceInToken
parameter_list|(
specifier|const
name|FormatToken
modifier|&
name|Tok
parameter_list|,
name|unsigned
name|Offset
parameter_list|,
name|unsigned
name|ReplaceChars
parameter_list|,
name|StringRef
name|PreviousPostfix
parameter_list|,
name|StringRef
name|CurrentPrefix
parameter_list|,
name|bool
name|InPPDirective
parameter_list|,
name|unsigned
name|Newlines
parameter_list|,
name|int
name|Spaces
parameter_list|)
function_decl|;
comment|/// \brief Returns all the \c Replacements created during formatting.
specifier|const
name|tooling
operator|::
name|Replacements
operator|&
name|generateReplacements
argument_list|()
expr_stmt|;
comment|/// \brief Represents a change before a token, a break inside a token,
comment|/// or the layout of an unchanged token (or whitespace within).
struct|struct
name|Change
block|{
comment|/// \brief Functor to sort changes in original source order.
name|class
name|IsBeforeInFile
block|{
name|public
label|:
name|IsBeforeInFile
argument_list|(
specifier|const
name|SourceManager
operator|&
name|SourceMgr
argument_list|)
operator|:
name|SourceMgr
argument_list|(
argument|SourceMgr
argument_list|)
block|{}
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|Change
operator|&
name|C1
operator|,
specifier|const
name|Change
operator|&
name|C2
operator|)
specifier|const
expr_stmt|;
name|private
label|:
specifier|const
name|SourceManager
modifier|&
name|SourceMgr
decl_stmt|;
block|}
empty_stmt|;
comment|/// \brief Creates a \c Change.
comment|///
comment|/// The generated \c Change will replace the characters at
comment|/// \p OriginalWhitespaceRange with a concatenation of
comment|/// \p PreviousLinePostfix, \p NewlinesBefore line breaks, \p Spaces spaces
comment|/// and \p CurrentLinePrefix.
comment|///
comment|/// \p StartOfTokenColumn and \p InPPDirective will be used to lay out
comment|/// trailing comments and escaped newlines.
name|Change
argument_list|(
argument|const FormatToken&Tok
argument_list|,
argument|bool CreateReplacement
argument_list|,
argument|SourceRange OriginalWhitespaceRange
argument_list|,
argument|int Spaces
argument_list|,
argument|unsigned StartOfTokenColumn
argument_list|,
argument|unsigned NewlinesBefore
argument_list|,
argument|StringRef PreviousLinePostfix
argument_list|,
argument|StringRef CurrentLinePrefix
argument_list|,
argument|bool ContinuesPPDirective
argument_list|,
argument|bool IsInsideToken
argument_list|)
empty_stmt|;
comment|// The kind of the token whose whitespace this change replaces, or in which
comment|// this change inserts whitespace.
comment|// FIXME: Currently this is not set correctly for breaks inside comments, as
comment|// the \c BreakableToken is still doing its own alignment.
specifier|const
name|FormatToken
modifier|*
name|Tok
decl_stmt|;
name|bool
name|CreateReplacement
decl_stmt|;
comment|// Changes might be in the middle of a token, so we cannot just keep the
comment|// FormatToken around to query its information.
name|SourceRange
name|OriginalWhitespaceRange
decl_stmt|;
name|unsigned
name|StartOfTokenColumn
decl_stmt|;
name|unsigned
name|NewlinesBefore
decl_stmt|;
name|std
operator|::
name|string
name|PreviousLinePostfix
expr_stmt|;
name|std
operator|::
name|string
name|CurrentLinePrefix
expr_stmt|;
name|bool
name|ContinuesPPDirective
decl_stmt|;
comment|// The number of spaces in front of the token or broken part of the token.
comment|// This will be adapted when aligning tokens.
comment|// Can be negative to retain information about the initial relative offset
comment|// of the lines in a block comment. This is used when aligning trailing
comment|// comments. Uncompensated negative offset is truncated to 0.
name|int
name|Spaces
decl_stmt|;
comment|// If this change is inside of a token but not at the start of the token or
comment|// directly after a newline.
name|bool
name|IsInsideToken
decl_stmt|;
comment|// \c IsTrailingComment, \c TokenLength, \c PreviousEndOfTokenColumn and
comment|// \c EscapedNewlineColumn will be calculated in
comment|// \c calculateLineBreakInformation.
name|bool
name|IsTrailingComment
decl_stmt|;
name|unsigned
name|TokenLength
decl_stmt|;
name|unsigned
name|PreviousEndOfTokenColumn
decl_stmt|;
name|unsigned
name|EscapedNewlineColumn
decl_stmt|;
comment|// These fields are used to retain correct relative line indentation in a
comment|// block comment when aligning trailing comments.
comment|//
comment|// If this Change represents a continuation of a block comment,
comment|// \c StartOfBlockComment is pointer to the first Change in the block
comment|// comment. \c IndentationOffset is a relative column offset to this
comment|// change, so that the correct column can be reconstructed at the end of
comment|// the alignment process.
specifier|const
name|Change
modifier|*
name|StartOfBlockComment
decl_stmt|;
name|int
name|IndentationOffset
decl_stmt|;
comment|// A combination of nesting level and indent level, which are used in
comment|// tandem to compute lexical scope, for the purposes of deciding
comment|// when to stop consecutive alignment runs.
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|unsigned
operator|>
name|nestingAndIndentLevel
argument_list|()
specifier|const
block|{
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|Tok
operator|->
name|NestingLevel
argument_list|,
name|Tok
operator|->
name|IndentLevel
argument_list|)
return|;
block|}
block|}
struct|;
name|private
label|:
comment|/// \brief Calculate \c IsTrailingComment, \c TokenLength for the last tokens
comment|/// or token parts in a line and \c PreviousEndOfTokenColumn and
comment|/// \c EscapedNewlineColumn for the first tokens or token parts in a line.
name|void
name|calculateLineBreakInformation
parameter_list|()
function_decl|;
comment|/// \brief Align consecutive assignments over all \c Changes.
name|void
name|alignConsecutiveAssignments
parameter_list|()
function_decl|;
comment|/// \brief Align consecutive declarations over all \c Changes.
name|void
name|alignConsecutiveDeclarations
parameter_list|()
function_decl|;
comment|/// \brief Align trailing comments over all \c Changes.
name|void
name|alignTrailingComments
parameter_list|()
function_decl|;
comment|/// \brief Align trailing comments from change \p Start to change \p End at
comment|/// the specified \p Column.
name|void
name|alignTrailingComments
parameter_list|(
name|unsigned
name|Start
parameter_list|,
name|unsigned
name|End
parameter_list|,
name|unsigned
name|Column
parameter_list|)
function_decl|;
comment|/// \brief Align escaped newlines over all \c Changes.
name|void
name|alignEscapedNewlines
parameter_list|()
function_decl|;
comment|/// \brief Align escaped newlines from change \p Start to change \p End at
comment|/// the specified \p Column.
name|void
name|alignEscapedNewlines
parameter_list|(
name|unsigned
name|Start
parameter_list|,
name|unsigned
name|End
parameter_list|,
name|unsigned
name|Column
parameter_list|)
function_decl|;
comment|/// \brief Fill \c Replaces with the replacements for all effective changes.
name|void
name|generateChanges
parameter_list|()
function_decl|;
comment|/// \brief Stores \p Text as the replacement for the whitespace in \p Range.
name|void
name|storeReplacement
parameter_list|(
name|SourceRange
name|Range
parameter_list|,
name|StringRef
name|Text
parameter_list|)
function_decl|;
name|void
name|appendNewlineText
argument_list|(
name|std
operator|::
name|string
operator|&
name|Text
argument_list|,
name|unsigned
name|Newlines
argument_list|)
decl_stmt|;
name|void
name|appendNewlineText
argument_list|(
name|std
operator|::
name|string
operator|&
name|Text
argument_list|,
name|unsigned
name|Newlines
argument_list|,
name|unsigned
name|PreviousEndOfTokenColumn
argument_list|,
name|unsigned
name|EscapedNewlineColumn
argument_list|)
decl_stmt|;
name|void
name|appendIndentText
argument_list|(
name|std
operator|::
name|string
operator|&
name|Text
argument_list|,
name|unsigned
name|IndentLevel
argument_list|,
name|unsigned
name|Spaces
argument_list|,
name|unsigned
name|WhitespaceStartColumn
argument_list|)
decl_stmt|;
name|SmallVector
operator|<
name|Change
operator|,
literal|16
operator|>
name|Changes
expr_stmt|;
specifier|const
name|SourceManager
modifier|&
name|SourceMgr
decl_stmt|;
name|tooling
operator|::
name|Replacements
name|Replaces
expr_stmt|;
specifier|const
name|FormatStyle
modifier|&
name|Style
decl_stmt|;
name|bool
name|UseCRLF
decl_stmt|;
block|}
empty_stmt|;
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

