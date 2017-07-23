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
name|LLVM_CLANG_LIB_FORMAT_UNWRAPPEDLINEPARSER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_FORMAT_UNWRAPPEDLINEPARSER_H
end_define

begin_include
include|#
directive|include
file|"FormatToken.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/IdentifierTable.h"
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
file|<list>
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
struct_decl|struct
name|UnwrappedLineNode
struct_decl|;
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
expr_stmt|;
comment|// FIXME: Don't use std::list here.
comment|/// \brief The \c Tokens comprising this \c UnwrappedLine.
name|std
operator|::
name|list
operator|<
name|UnwrappedLineNode
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
comment|/// \brief If this \c UnwrappedLine closes a block in a sequence of lines,
comment|/// \c MatchingOpeningBlockLineIndex stores the index of the corresponding
comment|/// opening line. Otherwise, \c MatchingOpeningBlockLineIndex must be
comment|/// \c kInvalidIndex.
name|size_t
name|MatchingOpeningBlockLineIndex
decl_stmt|;
specifier|static
specifier|const
name|size_t
name|kInvalidIndex
init|=
operator|-
literal|1
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
block|{}
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
name|virtual
name|void
name|finishRun
parameter_list|()
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
name|class
name|FormatTokenSource
decl_stmt|;
name|class
name|UnwrappedLineParser
block|{
name|public
label|:
name|UnwrappedLineParser
argument_list|(
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
name|ArrayRef
operator|<
name|FormatToken
operator|*
operator|>
name|Tokens
argument_list|,
name|UnwrappedLineConsumer
operator|&
name|Callback
argument_list|)
expr_stmt|;
name|void
name|parse
parameter_list|()
function_decl|;
name|private
label|:
name|void
name|reset
parameter_list|()
function_decl|;
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
name|bool
name|AddLevel
init|=
name|true
parameter_list|,
name|bool
name|MunchSemi
init|=
name|true
parameter_list|)
function_decl|;
name|void
name|parseChildBlock
parameter_list|()
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
name|parsePPIf
parameter_list|(
name|bool
name|IfDef
parameter_list|)
function_decl|;
name|void
name|parsePPElIf
parameter_list|()
function_decl|;
name|void
name|parsePPElse
parameter_list|()
function_decl|;
name|void
name|parsePPEndIf
parameter_list|()
function_decl|;
name|void
name|parsePPUnknown
parameter_list|()
function_decl|;
name|void
name|readTokenWithJavaScriptASI
parameter_list|()
function_decl|;
name|void
name|parseStructuralElement
parameter_list|()
function_decl|;
name|bool
name|tryToParseBracedList
parameter_list|()
function_decl|;
name|bool
name|parseBracedList
argument_list|(
name|bool
name|ContinueOnSemicolons
operator|=
name|false
argument_list|,
name|tok
operator|::
name|TokenKind
name|ClosingBraceKind
operator|=
name|tok
operator|::
name|r_brace
argument_list|)
decl_stmt|;
name|void
name|parseParens
parameter_list|()
function_decl|;
name|void
name|parseSquare
parameter_list|()
function_decl|;
name|void
name|parseIfThenElse
parameter_list|()
function_decl|;
name|void
name|parseTryCatch
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
name|parseNew
parameter_list|()
function_decl|;
name|void
name|parseAccessSpecifier
parameter_list|()
function_decl|;
name|bool
name|parseEnum
parameter_list|()
function_decl|;
name|void
name|parseJavaEnumBody
parameter_list|()
function_decl|;
comment|// Parses a record (aka class) as a top level element. If ParseAsExpr is true,
comment|// parses the record as a child block, i.e. if the class declaration is an
comment|// expression.
name|void
name|parseRecord
parameter_list|(
name|bool
name|ParseAsExpr
init|=
name|false
parameter_list|)
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
name|parseJavaScriptEs6ImportExport
parameter_list|()
function_decl|;
name|bool
name|tryToParseLambda
parameter_list|()
function_decl|;
name|bool
name|tryToParseLambdaIntroducer
parameter_list|()
function_decl|;
name|void
name|tryToParseJSFunction
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
specifier|const
name|FormatToken
modifier|*
name|getPreviousToken
parameter_list|()
function_decl|;
name|void
name|readToken
parameter_list|()
function_decl|;
comment|// Decides which comment tokens should be added to the current line and which
comment|// should be added as comments before the next token.
comment|//
comment|// Comments specifies the sequence of comment tokens to analyze. They get
comment|// either pushed to the current line or added to the comments before the next
comment|// token.
comment|//
comment|// NextTok specifies the next token. A null pointer NextTok is supported, and
comment|// signifies either the absense of a next token, or that the next token
comment|// shouldn't be taken into accunt for the analysis.
name|void
name|distributeComments
argument_list|(
specifier|const
name|SmallVectorImpl
operator|<
name|FormatToken
operator|*
operator|>
operator|&
name|Comments
argument_list|,
specifier|const
name|FormatToken
operator|*
name|NextTok
argument_list|)
decl_stmt|;
comment|// Adds the comment preceding the next token to unwrapped lines.
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
name|FormatToken
modifier|*
name|Tok
parameter_list|)
function_decl|;
name|void
name|calculateBraceTypes
parameter_list|(
name|bool
name|ExpectClassBody
init|=
name|false
parameter_list|)
function_decl|;
comment|// Marks a conditional compilation edge (for example, an '#if', '#ifdef',
comment|// '#else' or merge conflict marker). If 'Unreachable' is true, assumes
comment|// this branch either cannot be taken (for example '#if false'), or should
comment|// not be taken in this round.
name|void
name|conditionalCompilationCondition
parameter_list|(
name|bool
name|Unreachable
parameter_list|)
function_decl|;
name|void
name|conditionalCompilationStart
parameter_list|(
name|bool
name|Unreachable
parameter_list|)
function_decl|;
name|void
name|conditionalCompilationAlternative
parameter_list|()
function_decl|;
name|void
name|conditionalCompilationEnd
parameter_list|()
function_decl|;
name|bool
name|isOnNewLine
parameter_list|(
specifier|const
name|FormatToken
modifier|&
name|FormatTok
parameter_list|)
function_decl|;
comment|// FIXME: We are constantly running into bugs where Line.Level is incorrectly
comment|// subtracted from beyond 0. Introduce a method to subtract from Line.Level
comment|// and use that everywhere in the Parser.
name|std
operator|::
name|unique_ptr
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
operator|*
operator|,
literal|1
operator|>
name|CommentsBeforeNextToken
expr_stmt|;
name|FormatToken
modifier|*
name|FormatTok
decl_stmt|;
name|bool
name|MustBreakBeforeNextToken
decl_stmt|;
comment|// The parsed lines. Only added to through \c CurrentLines.
name|SmallVector
operator|<
name|UnwrappedLine
operator|,
literal|8
operator|>
name|Lines
expr_stmt|;
comment|// Preprocessor directives are parsed out-of-order from other unwrapped lines.
comment|// Thus, we need to keep a list of preprocessor directives to be reported
comment|// after an unwarpped line that has been started was finished.
name|SmallVector
operator|<
name|UnwrappedLine
operator|,
literal|4
operator|>
name|PreprocessorDirectives
expr_stmt|;
comment|// New unwrapped lines are added via CurrentLines.
comment|// Usually points to \c&Lines. While parsing a preprocessor directive when
comment|// there is an unfinished previous unwrapped line, will point to
comment|// \c&PreprocessorDirectives.
name|SmallVectorImpl
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
name|llvm
operator|::
name|Regex
name|CommentPragmasRegex
expr_stmt|;
name|FormatTokenSource
modifier|*
name|Tokens
decl_stmt|;
name|UnwrappedLineConsumer
modifier|&
name|Callback
decl_stmt|;
comment|// FIXME: This is a temporary measure until we have reworked the ownership
comment|// of the format tokens. The goal is to have the actual tokens created and
comment|// owned outside of and handed into the UnwrappedLineParser.
name|ArrayRef
operator|<
name|FormatToken
operator|*
operator|>
name|AllTokens
expr_stmt|;
comment|// Represents preprocessor branch type, so we can find matching
comment|// #if/#else/#endif directives.
enum|enum
name|PPBranchKind
block|{
name|PP_Conditional
block|,
comment|// Any #if, #ifdef, #ifndef, #elif, block outside #if 0
name|PP_Unreachable
comment|// #if 0 or a conditional preprocessor block inside #if 0
block|}
enum|;
comment|// Keeps a stack of currently active preprocessor branching directives.
name|SmallVector
operator|<
name|PPBranchKind
operator|,
literal|16
operator|>
name|PPStack
expr_stmt|;
comment|// The \c UnwrappedLineParser re-parses the code for each combination
comment|// of preprocessor branches that can be taken.
comment|// To that end, we take the same branch (#if, #else, or one of the #elif
comment|// branches) for each nesting level of preprocessor branches.
comment|// \c PPBranchLevel stores the current nesting level of preprocessor
comment|// branches during one pass over the code.
name|int
name|PPBranchLevel
decl_stmt|;
comment|// Contains the current branch (#if, #else or one of the #elif branches)
comment|// for each nesting level.
name|SmallVector
operator|<
name|int
operator|,
literal|8
operator|>
name|PPLevelBranchIndex
expr_stmt|;
comment|// Contains the maximum number of branches at each nesting level.
name|SmallVector
operator|<
name|int
operator|,
literal|8
operator|>
name|PPLevelBranchCount
expr_stmt|;
comment|// Contains the number of branches per nesting level we are currently
comment|// in while parsing a preprocessor branch sequence.
comment|// This is used to update PPLevelBranchCount at the end of a branch
comment|// sequence.
name|std
operator|::
name|stack
operator|<
name|int
operator|>
name|PPChainBranchIndex
expr_stmt|;
name|friend
name|class
name|ScopedLineState
decl_stmt|;
name|friend
name|class
name|CompoundStatementIndenter
decl_stmt|;
block|}
empty_stmt|;
struct|struct
name|UnwrappedLineNode
block|{
name|UnwrappedLineNode
argument_list|()
operator|:
name|Tok
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|UnwrappedLineNode
argument_list|(
name|FormatToken
operator|*
name|Tok
argument_list|)
operator|:
name|Tok
argument_list|(
argument|Tok
argument_list|)
block|{}
name|FormatToken
operator|*
name|Tok
expr_stmt|;
name|SmallVector
operator|<
name|UnwrappedLine
operator|,
literal|0
operator|>
name|Children
expr_stmt|;
block|}
struct|;
specifier|inline
name|UnwrappedLine
operator|::
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
name|false
argument_list|)
operator|,
name|MatchingOpeningBlockLineIndex
argument_list|(
argument|kInvalidIndex
argument_list|)
block|{}
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

