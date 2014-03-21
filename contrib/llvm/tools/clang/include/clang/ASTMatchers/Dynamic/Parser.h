begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Parser.h - Matcher expression parser -----*- C++ -*-===//
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
comment|/// \brief Simple matcher expression parser.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The parser understands matcher expressions of the form:
end_comment

begin_comment
comment|///   MatcherName(Arg0, Arg1, ..., ArgN)
end_comment

begin_comment
comment|/// as well as simple types like strings.
end_comment

begin_comment
comment|/// The parser does not know how to process the matchers. It delegates this task
end_comment

begin_comment
comment|/// to a Sema object received as an argument.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// Grammar for the expressions supported:
end_comment

begin_comment
comment|///<Expression>        :=<Literal> |<MatcherExpression>
end_comment

begin_comment
comment|///<Literal>           :=<StringLiteral> |<Unsigned>
end_comment

begin_comment
comment|///<StringLiteral>     := "quoted string"
end_comment

begin_comment
comment|///<Unsigned>          := [0-9]+
end_comment

begin_comment
comment|///<MatcherExpression> :=<MatcherName>(<ArgumentList>) |
end_comment

begin_comment
comment|///<MatcherName>(<ArgumentList>).bind(<StringLiteral>)
end_comment

begin_comment
comment|///<MatcherName>       := [a-zA-Z]+
end_comment

begin_comment
comment|///<ArgumentList>      :=<Expression> |<Expression>,<ArgumentList>
end_comment

begin_comment
comment|/// \endcode
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
name|LLVM_CLANG_AST_MATCHERS_DYNAMIC_PARSER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_MATCHERS_DYNAMIC_PARSER_H
end_define

begin_include
include|#
directive|include
file|"clang/ASTMatchers/Dynamic/Diagnostics.h"
end_include

begin_include
include|#
directive|include
file|"clang/ASTMatchers/Dynamic/VariantValue.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|ast_matchers
block|{
name|namespace
name|dynamic
block|{
comment|/// \brief Matcher expression parser.
name|class
name|Parser
block|{
name|public
label|:
comment|/// \brief Interface to connect the parser with the registry and more.
comment|///
comment|/// The parser uses the Sema instance passed into
comment|/// parseMatcherExpression() to handle all matcher tokens. The simplest
comment|/// processor implementation would simply call into the registry to create
comment|/// the matchers.
comment|/// However, a more complex processor might decide to intercept the matcher
comment|/// creation and do some extra work. For example, it could apply some
comment|/// transformation to the matcher by adding some id() nodes, or could detect
comment|/// specific matcher nodes for more efficient lookup.
name|class
name|Sema
block|{
name|public
label|:
name|virtual
operator|~
name|Sema
argument_list|()
expr_stmt|;
comment|/// \brief Process a matcher expression.
comment|///
comment|/// All the arguments passed here have already been processed.
comment|///
comment|/// \param MatcherName The matcher name found by the parser.
comment|///
comment|/// \param NameRange The location of the name in the matcher source.
comment|///   Useful for error reporting.
comment|///
comment|/// \param BindID The ID to use to bind the matcher, or a null \c StringRef
comment|///   if no ID is specified.
comment|///
comment|/// \param Args The argument list for the matcher.
comment|///
comment|/// \return The matcher objects constructed by the processor, or a null
comment|///   matcher if an error occurred. In that case, \c Error will contain a
comment|///   description of the error.
name|virtual
name|VariantMatcher
name|actOnMatcherExpression
argument_list|(
name|StringRef
name|MatcherName
argument_list|,
specifier|const
name|SourceRange
operator|&
name|NameRange
argument_list|,
name|StringRef
name|BindID
argument_list|,
name|ArrayRef
operator|<
name|ParserValue
operator|>
name|Args
argument_list|,
name|Diagnostics
operator|*
name|Error
argument_list|)
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
comment|/// \brief Parse a matcher expression, creating matchers from the registry.
comment|///
comment|/// This overload creates matchers calling directly into the registry. If the
comment|/// caller needs more control over how the matchers are created, then it can
comment|/// use the overload below that takes a Sema.
comment|///
comment|/// \param MatcherCode The matcher expression to parse.
comment|///
comment|/// \return The matcher object constructed, or an empty Optional if an error
comment|///   occurred.
comment|///   In that case, \c Error will contain a description of the error.
comment|///   The caller takes ownership of the DynTypedMatcher object returned.
specifier|static
name|llvm
operator|::
name|Optional
operator|<
name|DynTypedMatcher
operator|>
name|parseMatcherExpression
argument_list|(
argument|StringRef MatcherCode
argument_list|,
argument|Diagnostics *Error
argument_list|)
expr_stmt|;
comment|/// \brief Parse a matcher expression.
comment|///
comment|/// \param MatcherCode The matcher expression to parse.
comment|///
comment|/// \param S The Sema instance that will help the parser
comment|///   construct the matchers.
comment|/// \return The matcher object constructed by the processor, or an empty
comment|///   Optional if an error occurred. In that case, \c Error will contain a
comment|///   description of the error.
comment|///   The caller takes ownership of the DynTypedMatcher object returned.
specifier|static
name|llvm
operator|::
name|Optional
operator|<
name|DynTypedMatcher
operator|>
name|parseMatcherExpression
argument_list|(
argument|StringRef MatcherCode
argument_list|,
argument|Sema *S
argument_list|,
argument|Diagnostics *Error
argument_list|)
expr_stmt|;
comment|/// \brief Parse an expression, creating matchers from the registry.
comment|///
comment|/// Parses any expression supported by this parser. In general, the
comment|/// \c parseMatcherExpression function is a better approach to get a matcher
comment|/// object.
specifier|static
name|bool
name|parseExpression
parameter_list|(
name|StringRef
name|Code
parameter_list|,
name|VariantValue
modifier|*
name|Value
parameter_list|,
name|Diagnostics
modifier|*
name|Error
parameter_list|)
function_decl|;
comment|/// \brief Parse an expression.
comment|///
comment|/// Parses any expression supported by this parser. In general, the
comment|/// \c parseMatcherExpression function is a better approach to get a matcher
comment|/// object.
specifier|static
name|bool
name|parseExpression
parameter_list|(
name|StringRef
name|Code
parameter_list|,
name|Sema
modifier|*
name|S
parameter_list|,
name|VariantValue
modifier|*
name|Value
parameter_list|,
name|Diagnostics
modifier|*
name|Error
parameter_list|)
function_decl|;
name|private
label|:
name|class
name|CodeTokenizer
decl_stmt|;
struct_decl|struct
name|TokenInfo
struct_decl|;
name|Parser
argument_list|(
name|CodeTokenizer
operator|*
name|Tokenizer
argument_list|,
name|Sema
operator|*
name|S
argument_list|,
name|Diagnostics
operator|*
name|Error
argument_list|)
expr_stmt|;
name|bool
name|parseExpressionImpl
parameter_list|(
name|VariantValue
modifier|*
name|Value
parameter_list|)
function_decl|;
name|bool
name|parseMatcherExpressionImpl
parameter_list|(
name|VariantValue
modifier|*
name|Value
parameter_list|)
function_decl|;
name|CodeTokenizer
modifier|*
specifier|const
name|Tokenizer
decl_stmt|;
name|Sema
modifier|*
specifier|const
name|S
decl_stmt|;
name|Diagnostics
modifier|*
specifier|const
name|Error
decl_stmt|;
block|}
empty_stmt|;
block|}
comment|// namespace dynamic
block|}
comment|// namespace ast_matchers
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
comment|// LLVM_CLANG_AST_MATCHERS_DYNAMIC_PARSER_H
end_comment

end_unit

