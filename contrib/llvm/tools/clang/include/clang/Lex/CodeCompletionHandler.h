begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- CodeCompletionHandler.h - Preprocessor code completion -*- C++ -*-===//
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
comment|//
end_comment

begin_comment
comment|//  This file defines the CodeCompletionHandler interface, which provides
end_comment

begin_comment
comment|//  code-completion callbacks for the preprocessor.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_LEX_CODECOMPLETIONHANDLER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LEX_CODECOMPLETIONHANDLER_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|IdentifierInfo
decl_stmt|;
name|class
name|MacroInfo
decl_stmt|;
comment|/// \brief Callback handler that receives notifications when performing code
comment|/// completion within the preprocessor.
name|class
name|CodeCompletionHandler
block|{
name|public
label|:
name|virtual
operator|~
name|CodeCompletionHandler
argument_list|()
expr_stmt|;
comment|/// \brief Callback invoked when performing code completion for a preprocessor
comment|/// directive.
comment|///
comment|/// This callback will be invoked when the preprocessor processes a '#' at the
comment|/// start of a line, followed by the code-completion token.
comment|///
comment|/// \param InConditional Whether we're inside a preprocessor conditional
comment|/// already.
name|virtual
name|void
name|CodeCompleteDirective
parameter_list|(
name|bool
name|InConditional
parameter_list|)
block|{ }
comment|/// \brief Callback invoked when performing code completion within a block of
comment|/// code that was excluded due to preprocessor conditionals.
name|virtual
name|void
name|CodeCompleteInConditionalExclusion
parameter_list|()
block|{ }
comment|/// \brief Callback invoked when performing code completion in a context
comment|/// where the name of a macro is expected.
comment|///
comment|/// \param IsDefinition Whether this is the definition of a macro, e.g.,
comment|/// in a \#define.
name|virtual
name|void
name|CodeCompleteMacroName
parameter_list|(
name|bool
name|IsDefinition
parameter_list|)
block|{ }
comment|/// \brief Callback invoked when performing code completion in a preprocessor
comment|/// expression, such as the condition of an \#if or \#elif directive.
name|virtual
name|void
name|CodeCompletePreprocessorExpression
parameter_list|()
block|{ }
comment|/// \brief Callback invoked when performing code completion inside a
comment|/// function-like macro argument.
comment|///
comment|/// There will be another callback invocation after the macro arguments are
comment|/// parsed, so this callback should generally be used to note that the next
comment|/// callback is invoked inside a macro argument.
name|virtual
name|void
name|CodeCompleteMacroArgument
parameter_list|(
name|IdentifierInfo
modifier|*
name|Macro
parameter_list|,
name|MacroInfo
modifier|*
name|MacroInfo
parameter_list|,
name|unsigned
name|ArgumentIndex
parameter_list|)
block|{ }
comment|/// \brief Callback invoked when performing code completion in a part of the
comment|/// file where we expect natural language, e.g., a comment, string, or
comment|/// \#error directive.
name|virtual
name|void
name|CodeCompleteNaturalLanguage
parameter_list|()
block|{ }
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_LEX_CODECOMPLETIONHANDLER_H
end_comment

end_unit

