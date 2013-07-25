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
name|LLVM_CLANG_FORMAT_WHITESPACEMANAGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FORMAT_WHITESPACEMANAGER_H
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
name|class
name|WhitespaceManager
block|{
name|public
label|:
name|WhitespaceManager
argument_list|(
name|SourceManager
operator|&
name|SourceMgr
argument_list|,
specifier|const
name|FormatStyle
operator|&
name|Style
argument_list|)
operator|:
name|SourceMgr
argument_list|(
name|SourceMgr
argument_list|)
operator|,
name|Style
argument_list|(
argument|Style
argument_list|)
block|{}
comment|/// \brief Replaces the whitespace in front of \p Tok. Only call once for
comment|/// each \c AnnotatedToken.
name|void
name|replaceWhitespace
argument_list|(
argument|const AnnotatedToken&Tok
argument_list|,
argument|unsigned NewLines
argument_list|,
argument|unsigned Spaces
argument_list|,
argument|unsigned WhitespaceStartColumn
argument_list|)
expr_stmt|;
comment|/// \brief Like \c replaceWhitespace, but additionally adds right-aligned
comment|/// backslashes to escape newlines inside a preprocessor directive.
comment|///
comment|/// This function and \c replaceWhitespace have the same behavior if
comment|/// \c Newlines == 0.
name|void
name|replacePPWhitespace
parameter_list|(
specifier|const
name|AnnotatedToken
modifier|&
name|Tok
parameter_list|,
name|unsigned
name|NewLines
parameter_list|,
name|unsigned
name|Spaces
parameter_list|,
name|unsigned
name|WhitespaceStartColumn
parameter_list|)
function_decl|;
comment|/// \brief Inserts a line break into the middle of a token.
comment|///
comment|/// Will break at \p Offset inside \p Tok, putting \p Prefix before the line
comment|/// break and \p Postfix before the rest of the token starts in the next line.
comment|///
comment|/// \p InPPDirective, \p Spaces, \p WhitespaceStartColumn and \p Style are
comment|/// used to generate the correct line break.
name|void
name|breakToken
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
name|Prefix
parameter_list|,
name|StringRef
name|Postfix
parameter_list|,
name|bool
name|InPPDirective
parameter_list|,
name|unsigned
name|Spaces
parameter_list|,
name|unsigned
name|WhitespaceStartColumn
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
name|void
name|addReplacement
parameter_list|(
specifier|const
name|SourceLocation
modifier|&
name|SourceLoc
parameter_list|,
name|unsigned
name|ReplaceChars
parameter_list|,
name|StringRef
name|Text
parameter_list|)
function_decl|;
name|void
name|addUntouchableComment
parameter_list|(
name|unsigned
name|Column
parameter_list|)
function_decl|;
comment|/// \brief Try to align all stashed comments.
name|void
name|alignComments
parameter_list|()
function_decl|;
comment|/// \brief Try to align all stashed escaped newlines.
name|void
name|alignEscapedNewlines
parameter_list|()
function_decl|;
name|private
label|:
name|std
operator|::
name|string
name|getNewLineText
argument_list|(
argument|unsigned NewLines
argument_list|,
argument|unsigned Spaces
argument_list|)
expr_stmt|;
name|std
operator|::
name|string
name|getNewLineText
argument_list|(
argument|unsigned NewLines
argument_list|,
argument|unsigned Spaces
argument_list|,
argument|unsigned WhitespaceStartColumn
argument_list|,
argument|unsigned EscapedNewlineColumn
argument_list|)
expr_stmt|;
comment|/// \brief Structure to store tokens for later layout and alignment.
struct|struct
name|StoredToken
block|{
name|StoredToken
argument_list|(
argument|SourceLocation ReplacementLoc
argument_list|,
argument|unsigned ReplacementLength
argument_list|,
argument|unsigned MinColumn
argument_list|,
argument|unsigned MaxColumn
argument_list|,
argument|unsigned NewLines
argument_list|,
argument|unsigned Spaces
argument_list|)
block|:
name|ReplacementLoc
argument_list|(
name|ReplacementLoc
argument_list|)
operator|,
name|ReplacementLength
argument_list|(
name|ReplacementLength
argument_list|)
operator|,
name|MinColumn
argument_list|(
name|MinColumn
argument_list|)
operator|,
name|MaxColumn
argument_list|(
name|MaxColumn
argument_list|)
operator|,
name|NewLines
argument_list|(
name|NewLines
argument_list|)
operator|,
name|Spaces
argument_list|(
name|Spaces
argument_list|)
operator|,
name|Untouchable
argument_list|(
argument|false
argument_list|)
block|{}
name|SourceLocation
name|ReplacementLoc
expr_stmt|;
name|unsigned
name|ReplacementLength
decl_stmt|;
name|unsigned
name|MinColumn
decl_stmt|;
name|unsigned
name|MaxColumn
decl_stmt|;
name|unsigned
name|NewLines
decl_stmt|;
name|unsigned
name|Spaces
decl_stmt|;
name|bool
name|Untouchable
decl_stmt|;
name|std
operator|::
name|string
name|Prefix
expr_stmt|;
name|std
operator|::
name|string
name|Postfix
expr_stmt|;
block|}
struct|;
name|SmallVector
operator|<
name|StoredToken
operator|,
literal|16
operator|>
name|Comments
expr_stmt|;
name|SmallVector
operator|<
name|StoredToken
operator|,
literal|16
operator|>
name|EscapedNewlines
expr_stmt|;
typedef|typedef
name|SmallVector
operator|<
name|StoredToken
operator|,
literal|16
operator|>
operator|::
name|iterator
name|token_iterator
expr_stmt|;
comment|/// \brief Put all the comments between \p I and \p E into \p Column.
name|void
name|alignComments
parameter_list|(
name|token_iterator
name|I
parameter_list|,
name|token_iterator
name|E
parameter_list|,
name|unsigned
name|Column
parameter_list|)
function_decl|;
comment|/// \brief Stores \p Text as the replacement for the whitespace in front of
comment|/// \p Tok.
name|void
name|storeReplacement
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
name|unsigned
name|Length
argument_list|,
specifier|const
name|std
operator|::
name|string
name|Text
argument_list|)
decl_stmt|;
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

begin_comment
comment|// LLVM_CLANG_FORMAT_WHITESPACEMANAGER_H
end_comment

end_unit

