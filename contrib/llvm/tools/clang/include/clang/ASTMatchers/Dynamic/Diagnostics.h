begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Diagnostics.h - Helper class for error diagnostics -----*- C++ -*-===//
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
comment|/// \brief Diagnostics class to manage error messages.
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
name|LLVM_CLANG_ASTMATCHERS_DYNAMIC_DIAGNOSTICS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_ASTMATCHERS_DYNAMIC_DIAGNOSTICS_H
end_define

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
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Twine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
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
struct|struct
name|SourceLocation
block|{
name|SourceLocation
argument_list|()
operator|:
name|Line
argument_list|()
operator|,
name|Column
argument_list|()
block|{}
name|unsigned
name|Line
expr_stmt|;
name|unsigned
name|Column
decl_stmt|;
block|}
struct|;
struct|struct
name|SourceRange
block|{
name|SourceLocation
name|Start
decl_stmt|;
name|SourceLocation
name|End
decl_stmt|;
block|}
struct|;
comment|/// \brief A VariantValue instance annotated with its parser context.
struct|struct
name|ParserValue
block|{
name|ParserValue
argument_list|()
operator|:
name|Text
argument_list|()
operator|,
name|Range
argument_list|()
operator|,
name|Value
argument_list|()
block|{}
name|StringRef
name|Text
expr_stmt|;
name|SourceRange
name|Range
decl_stmt|;
name|VariantValue
name|Value
decl_stmt|;
block|}
struct|;
comment|/// \brief Helper class to manage error messages.
name|class
name|Diagnostics
block|{
name|public
label|:
comment|/// \brief Parser context types.
enum|enum
name|ContextType
block|{
name|CT_MatcherArg
init|=
literal|0
block|,
name|CT_MatcherConstruct
init|=
literal|1
block|}
enum|;
comment|/// \brief All errors from the system.
enum|enum
name|ErrorType
block|{
name|ET_None
init|=
literal|0
block|,
name|ET_RegistryMatcherNotFound
init|=
literal|1
block|,
name|ET_RegistryWrongArgCount
init|=
literal|2
block|,
name|ET_RegistryWrongArgType
init|=
literal|3
block|,
name|ET_RegistryNotBindable
init|=
literal|4
block|,
name|ET_RegistryAmbiguousOverload
init|=
literal|5
block|,
name|ET_RegistryValueNotFound
init|=
literal|6
block|,
name|ET_ParserStringError
init|=
literal|100
block|,
name|ET_ParserNoOpenParen
init|=
literal|101
block|,
name|ET_ParserNoCloseParen
init|=
literal|102
block|,
name|ET_ParserNoComma
init|=
literal|103
block|,
name|ET_ParserNoCode
init|=
literal|104
block|,
name|ET_ParserNotAMatcher
init|=
literal|105
block|,
name|ET_ParserInvalidToken
init|=
literal|106
block|,
name|ET_ParserMalformedBindExpr
init|=
literal|107
block|,
name|ET_ParserTrailingCode
init|=
literal|108
block|,
name|ET_ParserNumberError
init|=
literal|109
block|,
name|ET_ParserOverloadedType
init|=
literal|110
block|}
enum|;
comment|/// \brief Helper stream class.
name|class
name|ArgStream
block|{
name|public
label|:
name|ArgStream
argument_list|(
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|*
name|Out
argument_list|)
operator|:
name|Out
argument_list|(
argument|Out
argument_list|)
block|{}
name|template
operator|<
name|class
name|T
operator|>
name|ArgStream
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|T
operator|&
name|Arg
operator|)
block|{
return|return
name|operator
operator|<<
operator|(
name|Twine
argument_list|(
name|Arg
argument_list|)
operator|)
return|;
block|}
name|ArgStream
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|Twine
operator|&
name|Arg
operator|)
expr_stmt|;
name|private
label|:
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|*
name|Out
expr_stmt|;
block|}
empty_stmt|;
comment|/// \brief Class defining a parser context.
comment|///
comment|/// Used by the parser to specify (possibly recursive) contexts where the
comment|/// parsing/construction can fail. Any error triggered within a context will
comment|/// keep information about the context chain.
comment|/// This class should be used as a RAII instance in the stack.
struct|struct
name|Context
block|{
name|public
label|:
comment|/// \brief About to call the constructor for a matcher.
enum|enum
name|ConstructMatcherEnum
block|{
name|ConstructMatcher
block|}
enum|;
name|Context
argument_list|(
argument|ConstructMatcherEnum
argument_list|,
argument|Diagnostics *Error
argument_list|,
argument|StringRef MatcherName
argument_list|,
argument|SourceRange MatcherRange
argument_list|)
empty_stmt|;
comment|/// \brief About to recurse into parsing one argument for a matcher.
enum|enum
name|MatcherArgEnum
block|{
name|MatcherArg
block|}
enum|;
name|Context
argument_list|(
argument|MatcherArgEnum
argument_list|,
argument|Diagnostics *Error
argument_list|,
argument|StringRef MatcherName
argument_list|,
argument|SourceRange MatcherRange
argument_list|,
argument|unsigned ArgNumber
argument_list|)
empty_stmt|;
operator|~
name|Context
argument_list|()
expr_stmt|;
name|private
label|:
name|Diagnostics
modifier|*
specifier|const
name|Error
decl_stmt|;
block|}
struct|;
comment|/// \brief Context for overloaded matcher construction.
comment|///
comment|/// This context will take care of merging all errors that happen within it
comment|/// as "candidate" overloads for the same matcher.
struct|struct
name|OverloadContext
block|{
name|public
label|:
name|OverloadContext
argument_list|(
name|Diagnostics
operator|*
name|Error
argument_list|)
expr_stmt|;
operator|~
name|OverloadContext
argument_list|()
expr_stmt|;
comment|/// \brief Revert all errors that happened within this context.
name|void
name|revertErrors
parameter_list|()
function_decl|;
name|private
label|:
name|Diagnostics
modifier|*
specifier|const
name|Error
decl_stmt|;
name|unsigned
name|BeginIndex
decl_stmt|;
block|}
struct|;
comment|/// \brief Add an error to the diagnostics.
comment|///
comment|/// All the context information will be kept on the error message.
comment|/// \return a helper class to allow the caller to pass the arguments for the
comment|/// error message, using the<< operator.
name|ArgStream
name|addError
parameter_list|(
name|SourceRange
name|Range
parameter_list|,
name|ErrorType
name|Error
parameter_list|)
function_decl|;
comment|/// \brief Information stored for one frame of the context.
struct|struct
name|ContextFrame
block|{
name|ContextType
name|Type
decl_stmt|;
name|SourceRange
name|Range
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|Args
expr_stmt|;
block|}
struct|;
comment|/// \brief Information stored for each error found.
struct|struct
name|ErrorContent
block|{
name|std
operator|::
name|vector
operator|<
name|ContextFrame
operator|>
name|ContextStack
expr_stmt|;
struct|struct
name|Message
block|{
name|SourceRange
name|Range
decl_stmt|;
name|ErrorType
name|Type
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|Args
expr_stmt|;
block|}
struct|;
name|std
operator|::
name|vector
operator|<
name|Message
operator|>
name|Messages
expr_stmt|;
block|}
struct|;
name|ArrayRef
operator|<
name|ErrorContent
operator|>
name|errors
argument_list|()
specifier|const
block|{
return|return
name|Errors
return|;
block|}
comment|/// \brief Returns a simple string representation of each error.
comment|///
comment|/// Each error only shows the error message without any context.
name|void
name|printToStream
argument_list|(
name|llvm
operator|::
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
name|std
operator|::
name|string
name|toString
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Returns the full string representation of each error.
comment|///
comment|/// Each error message contains the full context.
name|void
name|printToStreamFull
argument_list|(
name|llvm
operator|::
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
name|std
operator|::
name|string
name|toStringFull
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
comment|/// \brief Helper function used by the constructors of ContextFrame.
name|ArgStream
name|pushContextFrame
parameter_list|(
name|ContextType
name|Type
parameter_list|,
name|SourceRange
name|Range
parameter_list|)
function_decl|;
name|std
operator|::
name|vector
operator|<
name|ContextFrame
operator|>
name|ContextStack
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|ErrorContent
operator|>
name|Errors
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
comment|// LLVM_CLANG_AST_MATCHERS_DYNAMIC_DIAGNOSTICS_H
end_comment

end_unit

