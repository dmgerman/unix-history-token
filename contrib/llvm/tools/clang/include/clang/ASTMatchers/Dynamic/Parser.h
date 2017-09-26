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
comment|///<Expression>        :=<Literal> |<NamedValue> |<MatcherExpression>
end_comment

begin_comment
comment|///<Literal>           :=<StringLiteral> |<Boolean> |<Double> |<Unsigned>
end_comment

begin_comment
comment|///<StringLiteral>     := "quoted string"
end_comment

begin_comment
comment|///<Boolean>           := true | false
end_comment

begin_comment
comment|///<Double>            := [0-9]+.[0-9]* | [0-9]+.[0-9]*[eE][-+]?[0-9]+
end_comment

begin_comment
comment|///<Unsigned>          := [0-9]+
end_comment

begin_comment
comment|///<NamedValue>        :=<Identifier>
end_comment

begin_comment
comment|///<MatcherExpression> :=<Identifier>(<ArgumentList>) |
end_comment

begin_comment
comment|///<Identifier>(<ArgumentList>).bind(<StringLiteral>)
end_comment

begin_comment
comment|///<Identifier>        := [a-zA-Z]+
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
name|LLVM_CLANG_ASTMATCHERS_DYNAMIC_PARSER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_ASTMATCHERS_DYNAMIC_PARSER_H
end_define

begin_include
include|#
directive|include
file|"clang/ASTMatchers/Dynamic/Diagnostics.h"
end_include

begin_include
include|#
directive|include
file|"clang/ASTMatchers/Dynamic/Registry.h"
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
comment|/// \param Ctor A matcher constructor looked up by lookupMatcherCtor.
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
name|MatcherCtor
name|Ctor
argument_list|,
name|SourceRange
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
comment|/// \brief Look up a matcher by name.
comment|///
comment|/// \param MatcherName The matcher name found by the parser.
comment|///
comment|/// \return The matcher constructor, or Optional<MatcherCtor>() if not
comment|/// found.
name|virtual
name|llvm
operator|::
name|Optional
operator|<
name|MatcherCtor
operator|>
name|lookupMatcherCtor
argument_list|(
argument|StringRef MatcherName
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|/// \brief Compute the list of completion types for \p Context.
comment|///
comment|/// Each element of \p Context represents a matcher invocation, going from
comment|/// outermost to innermost. Elements are pairs consisting of a reference to
comment|/// the matcher constructor and the index of the next element in the
comment|/// argument list of that matcher (or for the last element, the index of
comment|/// the completion point in the argument list). An empty list requests
comment|/// completion for the root matcher.
name|virtual
name|std
operator|::
name|vector
operator|<
name|ArgKind
operator|>
name|getAcceptedCompletionTypes
argument_list|(
name|llvm
operator|::
name|ArrayRef
operator|<
name|std
operator|::
name|pair
operator|<
name|MatcherCtor
argument_list|,
name|unsigned
operator|>>
name|Context
argument_list|)
expr_stmt|;
comment|/// \brief Compute the list of completions that match any of
comment|/// \p AcceptedTypes.
comment|///
comment|/// \param AcceptedTypes All types accepted for this completion.
comment|///
comment|/// \return All completions for the specified types.
comment|/// Completions should be valid when used in \c lookupMatcherCtor().
comment|/// The matcher constructed from the return of \c lookupMatcherCtor()
comment|/// should be convertible to some type in \p AcceptedTypes.
name|virtual
name|std
operator|::
name|vector
operator|<
name|MatcherCompletion
operator|>
name|getMatcherCompletions
argument_list|(
name|llvm
operator|::
name|ArrayRef
operator|<
name|ArgKind
operator|>
name|AcceptedTypes
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
comment|/// \brief Sema implementation that uses the matcher registry to process the
comment|///   tokens.
name|class
name|RegistrySema
range|:
name|public
name|Parser
operator|::
name|Sema
block|{
name|public
operator|:
operator|~
name|RegistrySema
argument_list|()
name|override
block|;
name|llvm
operator|::
name|Optional
operator|<
name|MatcherCtor
operator|>
name|lookupMatcherCtor
argument_list|(
argument|StringRef MatcherName
argument_list|)
name|override
block|;
name|VariantMatcher
name|actOnMatcherExpression
argument_list|(
argument|MatcherCtor Ctor
argument_list|,
argument|SourceRange NameRange
argument_list|,
argument|StringRef BindID
argument_list|,
argument|ArrayRef<ParserValue> Args
argument_list|,
argument|Diagnostics *Error
argument_list|)
name|override
block|;
name|std
operator|::
name|vector
operator|<
name|ArgKind
operator|>
name|getAcceptedCompletionTypes
argument_list|(
argument|llvm::ArrayRef<std::pair<MatcherCtor
argument_list|,
argument|unsigned>> Context
argument_list|)
name|override
block|;
name|std
operator|::
name|vector
operator|<
name|MatcherCompletion
operator|>
name|getMatcherCompletions
argument_list|(
argument|llvm::ArrayRef<ArgKind> AcceptedTypes
argument_list|)
name|override
block|;   }
decl_stmt|;
typedef|typedef
name|llvm
operator|::
name|StringMap
operator|<
name|VariantValue
operator|>
name|NamedValueMap
expr_stmt|;
comment|/// \brief Parse a matcher expression.
comment|///
comment|/// \param MatcherCode The matcher expression to parse.
comment|///
comment|/// \param S The Sema instance that will help the parser
comment|///   construct the matchers. If null, it uses the default registry.
comment|///
comment|/// \param NamedValues A map of precomputed named values.  This provides
comment|///   the dictionary for the<NamedValue> rule of the grammar.
comment|///   If null, it is ignored.
comment|///
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
argument|const NamedValueMap *NamedValues
argument_list|,
argument|Diagnostics *Error
argument_list|)
expr_stmt|;
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
block|{
return|return
name|parseMatcherExpression
argument_list|(
name|MatcherCode
argument_list|,
name|S
argument_list|,
name|nullptr
argument_list|,
name|Error
argument_list|)
return|;
block|}
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
block|{
return|return
name|parseMatcherExpression
argument_list|(
name|MatcherCode
argument_list|,
name|nullptr
argument_list|,
name|Error
argument_list|)
return|;
block|}
comment|/// \brief Parse an expression.
comment|///
comment|/// Parses any expression supported by this parser. In general, the
comment|/// \c parseMatcherExpression function is a better approach to get a matcher
comment|/// object.
comment|///
comment|/// \param S The Sema instance that will help the parser
comment|///   construct the matchers. If null, it uses the default registry.
comment|///
comment|/// \param NamedValues A map of precomputed named values.  This provides
comment|///   the dictionary for the<NamedValue> rule of the grammar.
comment|///   If null, it is ignored.
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
specifier|const
name|NamedValueMap
modifier|*
name|NamedValues
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
block|{
return|return
name|parseExpression
argument_list|(
name|Code
argument_list|,
name|S
argument_list|,
name|nullptr
argument_list|,
name|Value
argument_list|,
name|Error
argument_list|)
return|;
block|}
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
block|{
return|return
name|parseExpression
argument_list|(
name|Code
argument_list|,
name|nullptr
argument_list|,
name|Value
argument_list|,
name|Error
argument_list|)
return|;
block|}
comment|/// \brief Complete an expression at the given offset.
comment|///
comment|/// \param S The Sema instance that will help the parser
comment|///   construct the matchers. If null, it uses the default registry.
comment|///
comment|/// \param NamedValues A map of precomputed named values.  This provides
comment|///   the dictionary for the<NamedValue> rule of the grammar.
comment|///   If null, it is ignored.
comment|///
comment|/// \return The list of completions, which may be empty if there are no
comment|/// available completions or if an error occurred.
specifier|static
name|std
operator|::
name|vector
operator|<
name|MatcherCompletion
operator|>
name|completeExpression
argument_list|(
argument|StringRef Code
argument_list|,
argument|unsigned CompletionOffset
argument_list|,
argument|Sema *S
argument_list|,
argument|const NamedValueMap *NamedValues
argument_list|)
expr_stmt|;
specifier|static
name|std
operator|::
name|vector
operator|<
name|MatcherCompletion
operator|>
name|completeExpression
argument_list|(
argument|StringRef Code
argument_list|,
argument|unsigned CompletionOffset
argument_list|,
argument|Sema *S
argument_list|)
block|{
return|return
name|completeExpression
argument_list|(
name|Code
argument_list|,
name|CompletionOffset
argument_list|,
name|S
argument_list|,
name|nullptr
argument_list|)
return|;
block|}
specifier|static
name|std
operator|::
name|vector
operator|<
name|MatcherCompletion
operator|>
name|completeExpression
argument_list|(
argument|StringRef Code
argument_list|,
argument|unsigned CompletionOffset
argument_list|)
block|{
return|return
name|completeExpression
argument_list|(
name|Code
argument_list|,
name|CompletionOffset
argument_list|,
name|nullptr
argument_list|)
return|;
block|}
name|private
label|:
name|class
name|CodeTokenizer
decl_stmt|;
struct_decl|struct
name|ScopedContextEntry
struct_decl|;
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
specifier|const
name|NamedValueMap
operator|*
name|NamedValues
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
specifier|const
name|TokenInfo
modifier|&
name|NameToken
parameter_list|,
name|VariantValue
modifier|*
name|Value
parameter_list|)
function_decl|;
name|bool
name|parseIdentifierPrefixImpl
parameter_list|(
name|VariantValue
modifier|*
name|Value
parameter_list|)
function_decl|;
name|void
name|addCompletion
parameter_list|(
specifier|const
name|TokenInfo
modifier|&
name|CompToken
parameter_list|,
specifier|const
name|MatcherCompletion
modifier|&
name|Completion
parameter_list|)
function_decl|;
name|void
name|addExpressionCompletions
parameter_list|()
function_decl|;
name|std
operator|::
name|vector
operator|<
name|MatcherCompletion
operator|>
name|getNamedValueCompletions
argument_list|(
name|ArrayRef
operator|<
name|ArgKind
operator|>
name|AcceptedTypes
argument_list|)
expr_stmt|;
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
specifier|const
name|NamedValueMap
modifier|*
specifier|const
name|NamedValues
decl_stmt|;
name|Diagnostics
modifier|*
specifier|const
name|Error
decl_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|MatcherCtor
operator|,
name|unsigned
operator|>
expr|>
name|ContextStackTy
expr_stmt|;
name|ContextStackTy
name|ContextStack
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|MatcherCompletion
operator|>
name|Completions
expr_stmt|;
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

