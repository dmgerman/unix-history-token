begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- UnwrappedLineParser.h - Format C++ code ----------------*- C++ -*-===//
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
comment|/// \brief This file contains the declaration of the UnwrappedLineParser,
end_comment

begin_comment
comment|/// which turns a stream of tokens into UnwrappedLines.
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
name|LLVM_CLANG_FORMAT_UNWRAPPED_LINE_PARSER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FORMAT_UNWRAPPED_LINE_PARSER_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/IdentifierTable.h"
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
file|"clang/Lex/Lexer.h"
end_include

begin_include
include|#
directive|include
file|<list>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|DiagnosticsEngine
decl_stmt|;
name|namespace
name|format
block|{
comment|/// \brief A wrapper around a \c Token storing information about the
comment|/// whitespace characters preceeding it.
struct|struct
name|FormatToken
block|{
name|FormatToken
argument_list|()
operator|:
name|NewlinesBefore
argument_list|(
literal|0
argument_list|)
operator|,
name|HasUnescapedNewline
argument_list|(
name|false
argument_list|)
operator|,
name|WhiteSpaceLength
argument_list|(
literal|0
argument_list|)
operator|,
name|LastNewlineOffset
argument_list|(
literal|0
argument_list|)
operator|,
name|TokenLength
argument_list|(
literal|0
argument_list|)
operator|,
name|IsFirst
argument_list|(
name|false
argument_list|)
operator|,
name|MustBreakBefore
argument_list|(
name|false
argument_list|)
operator|,
name|TrailingWhiteSpaceLength
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// \brief The \c Token.
name|Token
name|Tok
expr_stmt|;
comment|/// \brief The number of newlines immediately before the \c Token.
comment|///
comment|/// This can be used to determine what the user wrote in the original code
comment|/// and thereby e.g. leave an empty line between two function definitions.
name|unsigned
name|NewlinesBefore
decl_stmt|;
comment|/// \brief Whether there is at least one unescaped newline before the \c
comment|/// Token.
name|bool
name|HasUnescapedNewline
decl_stmt|;
comment|/// \brief The location of the start of the whitespace immediately preceeding
comment|/// the \c Token.
comment|///
comment|/// Used together with \c WhiteSpaceLength to create a \c Replacement.
name|SourceLocation
name|WhiteSpaceStart
decl_stmt|;
comment|/// \brief The length in characters of the whitespace immediately preceeding
comment|/// the \c Token.
name|unsigned
name|WhiteSpaceLength
decl_stmt|;
comment|/// \brief The offset just past the last '\n' in this token's leading
comment|/// whitespace (relative to \c WhiteSpaceStart). 0 if there is no '\n'.
name|unsigned
name|LastNewlineOffset
decl_stmt|;
comment|/// \brief The length of the non-whitespace parts of the token. This is
comment|/// necessary because we need to handle escaped newlines that are stored
comment|/// with the token.
name|unsigned
name|TokenLength
decl_stmt|;
comment|/// \brief Indicates that this is the first token.
name|bool
name|IsFirst
decl_stmt|;
comment|/// \brief Whether there must be a line break before this token.
comment|///
comment|/// This happens for example when a preprocessor directive ended directly
comment|/// before the token.
name|bool
name|MustBreakBefore
decl_stmt|;
comment|/// \brief Number of characters of trailing whitespace.
name|unsigned
name|TrailingWhiteSpaceLength
decl_stmt|;
comment|/// \brief Returns actual token start location without leading escaped
comment|/// newlines and whitespace.
comment|///
comment|/// This can be different to Tok.getLocation(), which includes leading escaped
comment|/// newlines.
name|SourceLocation
name|getStartOfNonWhitespace
argument_list|()
specifier|const
block|{
return|return
name|WhiteSpaceStart
operator|.
name|getLocWithOffset
argument_list|(
name|WhiteSpaceLength
argument_list|)
return|;
block|}
block|}
struct|;
comment|/// \brief An unwrapped line is a sequence of \c Token, that we would like to
comment|/// put on a single line if there was no column limit.
comment|///
comment|/// This is used as a main interface between the \c UnwrappedLineParser and the
comment|/// \c UnwrappedLineFormatter. The key property is that changing the formatting
comment|/// within an unwrapped line does not affect any other unwrapped lines.
struct|struct
name|UnwrappedLine
block|{
name|UnwrappedLine
argument_list|()
operator|:
name|Level
argument_list|(
literal|0
argument_list|)
operator|,
name|InPPDirective
argument_list|(
name|false
argument_list|)
operator|,
name|MustBeDeclaration
argument_list|(
argument|false
argument_list|)
block|{   }
comment|// FIXME: Don't use std::list here.
comment|/// \brief The \c Tokens comprising this \c UnwrappedLine.
name|std
operator|::
name|list
operator|<
name|FormatToken
operator|>
name|Tokens
expr_stmt|;
comment|/// \brief The indent level of the \c UnwrappedLine.
name|unsigned
name|Level
decl_stmt|;
comment|/// \brief Whether this \c UnwrappedLine is part of a preprocessor directive.
name|bool
name|InPPDirective
decl_stmt|;
name|bool
name|MustBeDeclaration
decl_stmt|;
block|}
struct|;
name|class
name|UnwrappedLineConsumer
block|{
name|public
label|:
name|virtual
operator|~
name|UnwrappedLineConsumer
argument_list|()
block|{   }
name|virtual
name|void
name|consumeUnwrappedLine
argument_list|(
specifier|const
name|UnwrappedLine
operator|&
name|Line
argument_list|)
operator|=
literal|0
expr_stmt|;
block|}
empty_stmt|;
name|class
name|FormatTokenSource
block|{
name|public
label|:
name|virtual
operator|~
name|FormatTokenSource
argument_list|()
block|{   }
name|virtual
name|FormatToken
name|getNextToken
argument_list|()
operator|=
literal|0
expr_stmt|;
block|}
empty_stmt|;
name|class
name|UnwrappedLineParser
block|{
name|public
label|:
name|UnwrappedLineParser
argument_list|(
name|clang
operator|::
name|DiagnosticsEngine
operator|&
name|Diag
argument_list|,
specifier|const
name|FormatStyle
operator|&
name|Style
argument_list|,
name|FormatTokenSource
operator|&
name|Tokens
argument_list|,
name|UnwrappedLineConsumer
operator|&
name|Callback
argument_list|)
expr_stmt|;
comment|/// Returns true in case of a structural error.
name|bool
name|parse
parameter_list|()
function_decl|;
name|private
label|:
name|void
name|parseFile
parameter_list|()
function_decl|;
name|void
name|parseLevel
parameter_list|(
name|bool
name|HasOpeningBrace
parameter_list|)
function_decl|;
name|void
name|parseBlock
parameter_list|(
name|bool
name|MustBeDeclaration
parameter_list|,
name|unsigned
name|AddLevels
init|=
literal|1
parameter_list|)
function_decl|;
name|void
name|parsePPDirective
parameter_list|()
function_decl|;
name|void
name|parsePPDefine
parameter_list|()
function_decl|;
name|void
name|parsePPUnknown
parameter_list|()
function_decl|;
name|void
name|parseStructuralElement
parameter_list|()
function_decl|;
name|void
name|parseBracedList
parameter_list|()
function_decl|;
name|void
name|parseReturn
parameter_list|()
function_decl|;
name|void
name|parseParens
parameter_list|()
function_decl|;
name|void
name|parseIfThenElse
parameter_list|()
function_decl|;
name|void
name|parseForOrWhileLoop
parameter_list|()
function_decl|;
name|void
name|parseDoWhile
parameter_list|()
function_decl|;
name|void
name|parseLabel
parameter_list|()
function_decl|;
name|void
name|parseCaseLabel
parameter_list|()
function_decl|;
name|void
name|parseSwitch
parameter_list|()
function_decl|;
name|void
name|parseNamespace
parameter_list|()
function_decl|;
name|void
name|parseAccessSpecifier
parameter_list|()
function_decl|;
name|void
name|parseEnum
parameter_list|()
function_decl|;
name|void
name|parseRecord
parameter_list|()
function_decl|;
name|void
name|parseObjCProtocolList
parameter_list|()
function_decl|;
name|void
name|parseObjCUntilAtEnd
parameter_list|()
function_decl|;
name|void
name|parseObjCInterfaceOrImplementation
parameter_list|()
function_decl|;
name|void
name|parseObjCProtocol
parameter_list|()
function_decl|;
name|void
name|addUnwrappedLine
parameter_list|()
function_decl|;
name|bool
name|eof
argument_list|()
specifier|const
expr_stmt|;
name|void
name|nextToken
parameter_list|()
function_decl|;
name|void
name|readToken
parameter_list|()
function_decl|;
name|void
name|flushComments
parameter_list|(
name|bool
name|NewlineBeforeNext
parameter_list|)
function_decl|;
name|void
name|pushToken
parameter_list|(
specifier|const
name|FormatToken
modifier|&
name|Tok
parameter_list|)
function_decl|;
comment|// FIXME: We are constantly running into bugs where Line.Level is incorrectly
comment|// subtracted from beyond 0. Introduce a method to subtract from Line.Level
comment|// and use that everywhere in the Parser.
name|OwningPtr
operator|<
name|UnwrappedLine
operator|>
name|Line
expr_stmt|;
comment|// Comments are sorted into unwrapped lines by whether they are in the same
comment|// line as the previous token, or not. If not, they belong to the next token.
comment|// Since the next token might already be in a new unwrapped line, we need to
comment|// store the comments belonging to that token.
name|SmallVector
operator|<
name|FormatToken
operator|,
literal|1
operator|>
name|CommentsBeforeNextToken
expr_stmt|;
name|FormatToken
name|FormatTok
decl_stmt|;
name|bool
name|MustBreakBeforeNextToken
decl_stmt|;
comment|// The parsed lines. Only added to through \c CurrentLines.
name|std
operator|::
name|vector
operator|<
name|UnwrappedLine
operator|>
name|Lines
expr_stmt|;
comment|// Preprocessor directives are parsed out-of-order from other unwrapped lines.
comment|// Thus, we need to keep a list of preprocessor directives to be reported
comment|// after an unwarpped line that has been started was finished.
name|std
operator|::
name|vector
operator|<
name|UnwrappedLine
operator|>
name|PreprocessorDirectives
expr_stmt|;
comment|// New unwrapped lines are added via CurrentLines.
comment|// Usually points to \c&Lines. While parsing a preprocessor directive when
comment|// there is an unfinished previous unwrapped line, will point to
comment|// \c&PreprocessorDirectives.
name|std
operator|::
name|vector
operator|<
name|UnwrappedLine
operator|>
operator|*
name|CurrentLines
expr_stmt|;
comment|// We store for each line whether it must be a declaration depending on
comment|// whether we are in a compound statement or not.
name|std
operator|::
name|vector
operator|<
name|bool
operator|>
name|DeclarationScopeStack
expr_stmt|;
comment|// Will be true if we encounter an error that leads to possibily incorrect
comment|// indentation levels.
name|bool
name|StructuralError
decl_stmt|;
name|clang
operator|::
name|DiagnosticsEngine
operator|&
name|Diag
expr_stmt|;
specifier|const
name|FormatStyle
modifier|&
name|Style
decl_stmt|;
name|FormatTokenSource
modifier|*
name|Tokens
decl_stmt|;
name|UnwrappedLineConsumer
modifier|&
name|Callback
decl_stmt|;
name|friend
name|class
name|ScopedLineState
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
comment|// LLVM_CLANG_FORMAT_UNWRAPPED_LINE_PARSER_H
end_comment

end_unit

