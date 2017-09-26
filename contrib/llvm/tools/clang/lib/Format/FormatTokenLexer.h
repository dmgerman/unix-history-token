begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- FormatTokenLexer.h - Format C++ code ----------------*- C++ ----*-===//
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
comment|/// \brief This file contains FormatTokenLexer, which tokenizes a source file
end_comment

begin_comment
comment|/// into a token stream suitable for ClangFormat.
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
name|LLVM_CLANG_LIB_FORMAT_FORMATTOKENLEXER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_FORMAT_FORMATTOKENLEXER_H
end_define

begin_include
include|#
directive|include
file|"Encoding.h"
end_include

begin_include
include|#
directive|include
file|"FormatToken.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
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
file|"llvm/Support/Regex.h"
end_include

begin_include
include|#
directive|include
file|<stack>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|format
block|{
enum|enum
name|LexerState
block|{
name|NORMAL
block|,
name|TEMPLATE_STRING
block|,
name|TOKEN_STASHED
block|, }
enum|;
name|class
name|FormatTokenLexer
block|{
name|public
label|:
name|FormatTokenLexer
argument_list|(
argument|const SourceManager&SourceMgr
argument_list|,
argument|FileID ID
argument_list|,
argument|const FormatStyle&Style
argument_list|,
argument|encoding::Encoding Encoding
argument_list|)
empty_stmt|;
name|ArrayRef
operator|<
name|FormatToken
operator|*
operator|>
name|lex
argument_list|()
expr_stmt|;
specifier|const
name|AdditionalKeywords
modifier|&
name|getKeywords
parameter_list|()
block|{
return|return
name|Keywords
return|;
block|}
name|private
label|:
name|void
name|tryMergePreviousTokens
parameter_list|()
function_decl|;
name|bool
name|tryMergeLessLess
parameter_list|()
function_decl|;
name|bool
name|tryMergeNSStringLiteral
parameter_list|()
function_decl|;
name|bool
name|tryMergeTokens
argument_list|(
name|ArrayRef
operator|<
name|tok
operator|::
name|TokenKind
operator|>
name|Kinds
argument_list|,
name|TokenType
name|NewType
argument_list|)
decl_stmt|;
comment|// Returns \c true if \p Tok can only be followed by an operand in JavaScript.
name|bool
name|precedesOperand
parameter_list|(
name|FormatToken
modifier|*
name|Tok
parameter_list|)
function_decl|;
name|bool
name|canPrecedeRegexLiteral
parameter_list|(
name|FormatToken
modifier|*
name|Prev
parameter_list|)
function_decl|;
comment|// Tries to parse a JavaScript Regex literal starting at the current token,
comment|// if that begins with a slash and is in a location where JavaScript allows
comment|// regex literals. Changes the current token to a regex literal and updates
comment|// its text if successful.
name|void
name|tryParseJSRegexLiteral
parameter_list|()
function_decl|;
comment|// Handles JavaScript template strings.
comment|//
comment|// JavaScript template strings use backticks ('`') as delimiters, and allow
comment|// embedding expressions nested in ${expr-here}. Template strings can be
comment|// nested recursively, i.e. expressions can contain template strings in turn.
comment|//
comment|// The code below parses starting from a backtick, up to a closing backtick or
comment|// an opening ${. It also maintains a stack of lexing contexts to handle
comment|// nested template parts by balancing curly braces.
name|void
name|handleTemplateStrings
parameter_list|()
function_decl|;
name|bool
name|tryMerge_TMacro
parameter_list|()
function_decl|;
name|bool
name|tryMergeConflictMarkers
parameter_list|()
function_decl|;
name|FormatToken
modifier|*
name|getStashedToken
parameter_list|()
function_decl|;
name|FormatToken
modifier|*
name|getNextToken
parameter_list|()
function_decl|;
name|FormatToken
modifier|*
name|FormatTok
decl_stmt|;
name|bool
name|IsFirstToken
decl_stmt|;
name|std
operator|::
name|stack
operator|<
name|LexerState
operator|>
name|StateStack
expr_stmt|;
name|unsigned
name|Column
decl_stmt|;
name|unsigned
name|TrailingWhitespace
decl_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|Lexer
operator|>
name|Lex
expr_stmt|;
specifier|const
name|SourceManager
modifier|&
name|SourceMgr
decl_stmt|;
name|FileID
name|ID
decl_stmt|;
specifier|const
name|FormatStyle
modifier|&
name|Style
decl_stmt|;
name|IdentifierTable
name|IdentTable
decl_stmt|;
name|AdditionalKeywords
name|Keywords
decl_stmt|;
name|encoding
operator|::
name|Encoding
name|Encoding
expr_stmt|;
name|llvm
operator|::
name|SpecificBumpPtrAllocator
operator|<
name|FormatToken
operator|>
name|Allocator
expr_stmt|;
comment|// Index (in 'Tokens') of the last token that starts a new line.
name|unsigned
name|FirstInLineIndex
decl_stmt|;
name|SmallVector
operator|<
name|FormatToken
operator|*
operator|,
literal|16
operator|>
name|Tokens
expr_stmt|;
name|SmallVector
operator|<
name|IdentifierInfo
operator|*
operator|,
literal|8
operator|>
name|ForEachMacros
expr_stmt|;
name|bool
name|FormattingDisabled
decl_stmt|;
name|llvm
operator|::
name|Regex
name|MacroBlockBeginRegex
expr_stmt|;
name|llvm
operator|::
name|Regex
name|MacroBlockEndRegex
expr_stmt|;
name|void
name|readRawToken
parameter_list|(
name|FormatToken
modifier|&
name|Tok
parameter_list|)
function_decl|;
name|void
name|resetLexer
parameter_list|(
name|unsigned
name|Offset
parameter_list|)
function_decl|;
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

