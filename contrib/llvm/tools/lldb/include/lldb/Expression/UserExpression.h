begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- UserExpression.h ----------------------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|liblldb_UserExpression_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_UserExpression_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<memory>
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

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Core/Address.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Expression/Expression.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Expression/Materializer.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/ExecutionContext.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Target.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class UserExpression UserExpression.h "lldb/Expression/UserExpression.h"
comment|/// @brief Encapsulates a one-time expression for use in lldb.
comment|///
comment|/// LLDB uses expressions for various purposes, notably to call functions
comment|/// and as a backend for the expr command.  UserExpression is a virtual base
comment|/// class that encapsulates the objects needed to parse and interpret or
comment|/// JIT an expression.  The actual parsing part will be provided by the specific
comment|/// implementations of UserExpression - which will be vended through the
comment|/// appropriate TypeSystem.
comment|//----------------------------------------------------------------------
name|class
name|UserExpression
range|:
name|public
name|Expression
block|{
name|public
operator|:
expr|enum
block|{
name|kDefaultTimeout
operator|=
literal|500000u
block|}
block|;
comment|//------------------------------------------------------------------
comment|/// Constructor
comment|///
comment|/// @param[in] expr
comment|///     The expression to parse.
comment|///
comment|/// @param[in] expr_prefix
comment|///     If non-nullptr, a C string containing translation-unit level
comment|///     definitions to be included when the expression is parsed.
comment|///
comment|/// @param[in] language
comment|///     If not eLanguageTypeUnknown, a language to use when parsing
comment|///     the expression.  Currently restricted to those languages
comment|///     supported by Clang.
comment|///
comment|/// @param[in] desired_type
comment|///     If not eResultTypeAny, the type to use for the expression
comment|///     result.
comment|//------------------------------------------------------------------
name|UserExpression
argument_list|(
argument|ExecutionContextScope&exe_scope
argument_list|,
argument|llvm::StringRef expr
argument_list|,
argument|llvm::StringRef prefix
argument_list|,
argument|lldb::LanguageType language
argument_list|,
argument|ResultType desired_type
argument_list|,
argument|const EvaluateExpressionOptions&options
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Destructor
comment|//------------------------------------------------------------------
operator|~
name|UserExpression
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------------
comment|/// Parse the expression
comment|///
comment|/// @param[in] diagnostic_manager
comment|///     A diagnostic manager to report parse errors and warnings to.
comment|///
comment|/// @param[in] exe_ctx
comment|///     The execution context to use when looking up entities that
comment|///     are needed for parsing (locations of functions, types of
comment|///     variables, persistent variables, etc.)
comment|///
comment|/// @param[in] execution_policy
comment|///     Determines whether interpretation is possible or mandatory.
comment|///
comment|/// @param[in] keep_result_in_memory
comment|///     True if the resulting persistent variable should reside in
comment|///     target memory, if applicable.
comment|///
comment|/// @return
comment|///     True on success (no errors); false otherwise.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|Parse
argument_list|(
argument|DiagnosticManager&diagnostic_manager
argument_list|,
argument|ExecutionContext&exe_ctx
argument_list|,
argument|lldb_private::ExecutionPolicy execution_policy
argument_list|,
argument|bool keep_result_in_memory
argument_list|,
argument|bool generate_debug_info
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|CanInterpret
argument_list|()
operator|=
literal|0
block|;
name|bool
name|MatchesContext
argument_list|(
name|ExecutionContext
operator|&
name|exe_ctx
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Execute the parsed expression by callinng the derived class's
comment|/// DoExecute method.
comment|///
comment|/// @param[in] diagnostic_manager
comment|///     A diagnostic manager to report errors to.
comment|///
comment|/// @param[in] exe_ctx
comment|///     The execution context to use when looking up entities that
comment|///     are needed for parsing (locations of variables, etc.)
comment|///
comment|/// @param[in] options
comment|///     Expression evaluation options.
comment|///
comment|/// @param[in] shared_ptr_to_me
comment|///     This is a shared pointer to this UserExpression.  This is
comment|///     needed because Execute can push a thread plan that will hold onto
comment|///     the UserExpression for an unbounded period of time.  So you
comment|///     need to give the thread plan a reference to this object that can
comment|///     keep it alive.
comment|///
comment|/// @param[in] result
comment|///     A pointer to direct at the persistent variable in which the
comment|///     expression's result is stored.
comment|///
comment|/// @return
comment|///     A Process::Execution results value.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|ExpressionResults
name|Execute
argument_list|(
name|DiagnosticManager
operator|&
name|diagnostic_manager
argument_list|,
name|ExecutionContext
operator|&
name|exe_ctx
argument_list|,
specifier|const
name|EvaluateExpressionOptions
operator|&
name|options
argument_list|,
name|lldb
operator|::
name|UserExpressionSP
operator|&
name|shared_ptr_to_me
argument_list|,
name|lldb
operator|::
name|ExpressionVariableSP
operator|&
name|result
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Apply the side effects of the function to program state.
comment|///
comment|/// @param[in] diagnostic_manager
comment|///     A diagnostic manager to report errors to.
comment|///
comment|/// @param[in] exe_ctx
comment|///     The execution context to use when looking up entities that
comment|///     are needed for parsing (locations of variables, etc.)
comment|///
comment|/// @param[in] result
comment|///     A pointer to direct at the persistent variable in which the
comment|///     expression's result is stored.
comment|///
comment|/// @param[in] function_stack_pointer
comment|///     A pointer to the base of the function's stack frame.  This
comment|///     is used to determine whether the expression result resides in
comment|///     memory that will still be valid, or whether it needs to be
comment|///     treated as homeless for the purpose of future expressions.
comment|///
comment|/// @return
comment|///     A Process::Execution results value.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|FinalizeJITExecution
argument_list|(
argument|DiagnosticManager&diagnostic_manager
argument_list|,
argument|ExecutionContext&exe_ctx
argument_list|,
argument|lldb::ExpressionVariableSP&result
argument_list|,
argument|lldb::addr_t function_stack_bottom = LLDB_INVALID_ADDRESS
argument_list|,
argument|lldb::addr_t function_stack_top = LLDB_INVALID_ADDRESS
argument_list|)
operator|=
literal|0
block|;
comment|//------------------------------------------------------------------
comment|/// Return the string that the parser should parse.
comment|//------------------------------------------------------------------
specifier|const
name|char
operator|*
name|Text
argument_list|()
name|override
block|{
return|return
name|m_expr_text
operator|.
name|c_str
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Return the string that the user typed.
comment|//------------------------------------------------------------------
specifier|const
name|char
operator|*
name|GetUserText
argument_list|()
block|{
return|return
name|m_expr_text
operator|.
name|c_str
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Return the function name that should be used for executing the
comment|/// expression.  Text() should contain the definition of this
comment|/// function.
comment|//------------------------------------------------------------------
specifier|const
name|char
operator|*
name|FunctionName
argument_list|()
name|override
block|{
return|return
literal|"$__lldb_expr"
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Return the language that should be used when parsing.  To use
comment|/// the default, return eLanguageTypeUnknown.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|LanguageType
name|Language
argument_list|()
name|override
block|{
return|return
name|m_language
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Return the desired result type of the function, or
comment|/// eResultTypeAny if indifferent.
comment|//------------------------------------------------------------------
name|ResultType
name|DesiredResultType
argument_list|()
name|override
block|{
return|return
name|m_desired_type
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Return true if validation code should be inserted into the
comment|/// expression.
comment|//------------------------------------------------------------------
name|bool
name|NeedsValidation
argument_list|()
name|override
block|{
return|return
name|true
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Return true if external variables in the expression should be
comment|/// resolved.
comment|//------------------------------------------------------------------
name|bool
name|NeedsVariableResolution
argument_list|()
name|override
block|{
return|return
name|true
return|;
block|}
name|EvaluateExpressionOptions
operator|*
name|GetOptions
argument_list|()
name|override
block|{
return|return
operator|&
name|m_options
return|;
block|}
name|virtual
name|lldb
operator|::
name|ExpressionVariableSP
name|GetResultAfterDematerialization
argument_list|(
argument|ExecutionContextScope *exe_scope
argument_list|)
block|{
return|return
name|lldb
operator|::
name|ExpressionVariableSP
argument_list|()
return|;
block|}
name|virtual
name|lldb
operator|::
name|ModuleSP
name|GetJITModule
argument_list|()
block|{
return|return
name|lldb
operator|::
name|ModuleSP
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Evaluate one expression in the scratch context of the
comment|/// target passed in the exe_ctx and return its result.
comment|///
comment|/// @param[in] exe_ctx
comment|///     The execution context to use when evaluating the expression.
comment|///
comment|/// @param[in] options
comment|///     Expression evaluation options.  N.B. The language in the
comment|///     evaluation options will be used to determine the language used for
comment|///     expression evaluation.
comment|///
comment|/// @param[in] expr_cstr
comment|///     A C string containing the expression to be evaluated.
comment|///
comment|/// @param[in] expr_prefix
comment|///     If non-nullptr, a C string containing translation-unit level
comment|///     definitions to be included when the expression is parsed.
comment|///
comment|/// @param[in,out] result_valobj_sp
comment|///      If execution is successful, the result valobj is placed here.
comment|///
comment|/// @param[out] error
comment|///     Filled in with an error in case the expression evaluation
comment|///     fails to parse, run, or evaluated.
comment|///
comment|/// @param[in] line_offset
comment|///     The offset of the first line of the expression from the "beginning" of
comment|///     a virtual source file used for error reporting and debug info.
comment|///
comment|/// @param[out] fixed_expression
comment|///     If non-nullptr, the fixed expression is copied into the provided
comment|///     string.
comment|///
comment|/// @param[out] jit_module_sp_ptr
comment|///     If non-nullptr, used to persist the generated IR module.
comment|///
comment|/// @result
comment|///      A Process::ExpressionResults value.  eExpressionCompleted for
comment|///      success.
comment|//------------------------------------------------------------------
specifier|static
name|lldb
operator|::
name|ExpressionResults
name|Evaluate
argument_list|(
argument|ExecutionContext&exe_ctx
argument_list|,
argument|const EvaluateExpressionOptions&options
argument_list|,
argument|llvm::StringRef expr_cstr
argument_list|,
argument|llvm::StringRef expr_prefix
argument_list|,
argument|lldb::ValueObjectSP&result_valobj_sp
argument_list|,
argument|Status&error
argument_list|,
argument|uint32_t line_offset =
literal|0
argument_list|,
argument|std::string *fixed_expression = nullptr
argument_list|,
argument|lldb::ModuleSP *jit_module_sp_ptr = nullptr
argument_list|)
block|;
specifier|static
specifier|const
name|Status
operator|::
name|ValueType
name|kNoResult
operator|=
literal|0x1001
block|;
comment|///< ValueObject::GetError() returns this if there is no result
comment|/// from the expression.
specifier|const
name|char
operator|*
name|GetFixedText
argument_list|()
block|{
if|if
condition|(
name|m_fixed_text
operator|.
name|empty
argument_list|()
condition|)
return|return
name|nullptr
return|;
return|return
name|m_fixed_text
operator|.
name|c_str
argument_list|()
return|;
block|}
name|protected
label|:
name|virtual
name|lldb
operator|::
name|ExpressionResults
name|DoExecute
argument_list|(
name|DiagnosticManager
operator|&
name|diagnostic_manager
argument_list|,
name|ExecutionContext
operator|&
name|exe_ctx
argument_list|,
specifier|const
name|EvaluateExpressionOptions
operator|&
name|options
argument_list|,
name|lldb
operator|::
name|UserExpressionSP
operator|&
name|shared_ptr_to_me
argument_list|,
name|lldb
operator|::
name|ExpressionVariableSP
operator|&
name|result
argument_list|)
operator|=
literal|0
expr_stmt|;
specifier|static
name|lldb
operator|::
name|addr_t
name|GetObjectPointer
argument_list|(
argument|lldb::StackFrameSP frame_sp
argument_list|,
argument|ConstString&object_name
argument_list|,
argument|Status&err
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Populate m_in_cplusplus_method and m_in_objectivec_method based on the
comment|/// environment.
comment|//------------------------------------------------------------------
name|void
name|InstallContext
parameter_list|(
name|ExecutionContext
modifier|&
name|exe_ctx
parameter_list|)
function_decl|;
name|bool
name|LockAndCheckContext
argument_list|(
name|ExecutionContext
operator|&
name|exe_ctx
argument_list|,
name|lldb
operator|::
name|TargetSP
operator|&
name|target_sp
argument_list|,
name|lldb
operator|::
name|ProcessSP
operator|&
name|process_sp
argument_list|,
name|lldb
operator|::
name|StackFrameSP
operator|&
name|frame_sp
argument_list|)
decl_stmt|;
name|Address
name|m_address
decl_stmt|;
comment|///< The address the process is stopped in.
name|std
operator|::
name|string
name|m_expr_text
expr_stmt|;
comment|///< The text of the expression, as typed by the user
name|std
operator|::
name|string
name|m_expr_prefix
expr_stmt|;
comment|///< The text of the translation-level definitions,
comment|///as provided by the user
name|std
operator|::
name|string
name|m_fixed_text
expr_stmt|;
comment|///< The text of the expression with fix-its applied
comment|///- this won't be set if the fixed text doesn't
comment|///parse.
name|lldb
operator|::
name|LanguageType
name|m_language
expr_stmt|;
comment|///< The language to use when parsing
comment|///(eLanguageTypeUnknown means use defaults)
name|ResultType
name|m_desired_type
decl_stmt|;
comment|///< The type to coerce the expression's result to.
comment|///If eResultTypeAny, inferred from the expression.
name|EvaluateExpressionOptions
name|m_options
decl_stmt|;
comment|///< Additional options provided by the user.
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_UserExpression_h_
end_comment

end_unit

