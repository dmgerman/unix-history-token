begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ExpressionParser.h --------------------------------------*- C++ -*-===//
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
name|liblldb_ExpressionParser_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ExpressionParser_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Utility/Error.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-public.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|IRExecutionUnit
decl_stmt|;
comment|//----------------------------------------------------------------------
comment|/// @class ExpressionParser ExpressionParser.h
comment|/// "lldb/Expression/ExpressionParser.h"
comment|/// @brief Encapsulates an instance of a compiler that can parse expressions.
comment|///
comment|/// ExpressionParser is the base class for llvm based Expression parsers.
comment|//----------------------------------------------------------------------
name|class
name|ExpressionParser
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|/// Constructor
comment|///
comment|/// Initializes class variables.
comment|///
comment|/// @param[in] exe_scope,
comment|///     If non-NULL, an execution context scope that can help to
comment|///     correctly create an expression with a valid process for
comment|///     optional tuning Objective-C runtime support. Can be NULL.
comment|///
comment|/// @param[in] expr
comment|///     The expression to be parsed.
comment|//------------------------------------------------------------------
name|ExpressionParser
argument_list|(
argument|ExecutionContextScope *exe_scope
argument_list|,
argument|Expression&expr
argument_list|,
argument|bool generate_debug_info
argument_list|)
block|:
name|m_expr
argument_list|(
name|expr
argument_list|)
operator|,
name|m_generate_debug_info
argument_list|(
argument|generate_debug_info
argument_list|)
block|{}
comment|//------------------------------------------------------------------
comment|/// Destructor
comment|//------------------------------------------------------------------
name|virtual
operator|~
name|ExpressionParser
argument_list|()
block|{}
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Parse a single expression and convert it to IR using Clang.  Don't
comment|/// wrap the expression in anything at all.
comment|///
comment|/// @param[in] diagnostic_manager
comment|///     The diagnostic manager in which to store the errors and warnings.
comment|///
comment|/// @return
comment|///     The number of errors encountered during parsing.  0 means
comment|///     success.
comment|//------------------------------------------------------------------
name|virtual
name|unsigned
name|Parse
parameter_list|(
name|DiagnosticManager
modifier|&
name|diagnostic_manager
parameter_list|)
init|=
literal|0
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Try to use the FixIts in the diagnostic_manager to rewrite the
comment|/// expression.  If successful, the rewritten expression is stored
comment|/// in the diagnostic_manager, get it out with GetFixedExpression.
comment|///
comment|/// @param[in] diagnostic_manager
comment|///     The diagnostic manager containing fixit's to apply.
comment|///
comment|/// @return
comment|///     \b true if the rewrite was successful, \b false otherwise.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|RewriteExpression
parameter_list|(
name|DiagnosticManager
modifier|&
name|diagnostic_manager
parameter_list|)
block|{
return|return
name|false
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Ready an already-parsed expression for execution, possibly
comment|/// evaluating it statically.
comment|///
comment|/// @param[out] func_addr
comment|///     The address to which the function has been written.
comment|///
comment|/// @param[out] func_end
comment|///     The end of the function's allocated memory region.  (func_addr
comment|///     and func_end do not delimit an allocated region; the allocated
comment|///     region may begin before func_addr.)
comment|///
comment|/// @param[in] execution_unit_sp
comment|///     After parsing, ownership of the execution unit for
comment|///     for the expression is handed to this shared pointer.
comment|///
comment|/// @param[in] exe_ctx
comment|///     The execution context to write the function into.
comment|///
comment|/// @param[out] can_interpret
comment|///     Set to true if the expression could be interpreted statically;
comment|///     untouched otherwise.
comment|///
comment|/// @param[in] execution_policy
comment|///     Determines whether the expression must be JIT-compiled, must be
comment|///     evaluated statically, or whether this decision may be made
comment|///     opportunistically.
comment|///
comment|/// @return
comment|///     An error code indicating the success or failure of the operation.
comment|///     Test with Success().
comment|//------------------------------------------------------------------
name|virtual
name|Error
name|PrepareForExecution
argument_list|(
name|lldb
operator|::
name|addr_t
operator|&
name|func_addr
argument_list|,
name|lldb
operator|::
name|addr_t
operator|&
name|func_end
argument_list|,
name|std
operator|::
name|shared_ptr
operator|<
name|IRExecutionUnit
operator|>
operator|&
name|execution_unit_sp
argument_list|,
name|ExecutionContext
operator|&
name|exe_ctx
argument_list|,
name|bool
operator|&
name|can_interpret
argument_list|,
name|lldb_private
operator|::
name|ExecutionPolicy
name|execution_policy
argument_list|)
init|=
literal|0
decl_stmt|;
name|bool
name|GetGenerateDebugInfo
argument_list|()
specifier|const
block|{
return|return
name|m_generate_debug_info
return|;
block|}
name|protected
label|:
name|Expression
modifier|&
name|m_expr
decl_stmt|;
comment|///< The expression to be parsed
name|bool
name|m_generate_debug_info
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ExpressionParser_h_
end_comment

end_unit

