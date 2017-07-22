begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- UtilityFunction.h ----------------------------------------*- C++
end_comment

begin_comment
comment|//-*-===//
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
name|liblldb_UtilityFunction_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_UtilityFunction_h_
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

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Expression/Expression.h"
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
comment|/// @class UtilityFunction UtilityFunction.h "lldb/Expression/UtilityFunction.h"
comment|/// @brief Encapsulates a bit of source code that provides a function that is
comment|/// callable
comment|///
comment|/// LLDB uses expressions for various purposes, notably to call functions
comment|/// and as a backend for the expr command.  UtilityFunction encapsulates
comment|/// a self-contained function meant to be used from other code.  Utility
comment|/// functions can perform error-checking for ClangUserExpressions,
comment|//----------------------------------------------------------------------
name|class
name|UtilityFunction
range|:
name|public
name|Expression
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|/// Constructor
comment|///
comment|/// @param[in] text
comment|///     The text of the function.  Must be a full translation unit.
comment|///
comment|/// @param[in] name
comment|///     The name of the function, as used in the text.
comment|//------------------------------------------------------------------
name|UtilityFunction
argument_list|(
name|ExecutionContextScope
operator|&
name|exe_scope
argument_list|,
specifier|const
name|char
operator|*
name|text
argument_list|,
specifier|const
name|char
operator|*
name|name
argument_list|)
block|;
operator|~
name|UtilityFunction
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------------
comment|/// Install the utility function into a process
comment|///
comment|/// @param[in] diagnostic_manager
comment|///     A diagnostic manager to print parse errors and warnings to.
comment|///
comment|/// @param[in] exe_ctx
comment|///     The execution context to install the utility function to.
comment|///
comment|/// @return
comment|///     True on success (no errors); false otherwise.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|Install
argument_list|(
name|DiagnosticManager
operator|&
name|diagnostic_manager
argument_list|,
name|ExecutionContext
operator|&
name|exe_ctx
argument_list|)
operator|=
literal|0
block|;
comment|//------------------------------------------------------------------
comment|/// Check whether the given PC is inside the function
comment|///
comment|/// Especially useful if the function dereferences nullptr to indicate a
comment|/// failed
comment|/// assert.
comment|///
comment|/// @param[in] pc
comment|///     The program counter to check.
comment|///
comment|/// @return
comment|///     True if the program counter falls within the function's bounds;
comment|///     false if not (or the function is not JIT compiled)
comment|//------------------------------------------------------------------
name|bool
name|ContainsAddress
argument_list|(
argument|lldb::addr_t address
argument_list|)
block|{
comment|// nothing is both>= LLDB_INVALID_ADDRESS and< LLDB_INVALID_ADDRESS,
comment|// so this always returns false if the function is not JIT compiled yet
return|return
operator|(
name|address
operator|>=
name|m_jit_start_addr
operator|&&
name|address
operator|<
name|m_jit_end_addr
operator|)
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Return the string that the parser should parse.  Must be a full
comment|/// translation unit.
comment|//------------------------------------------------------------------
specifier|const
name|char
operator|*
name|Text
argument_list|()
name|override
block|{
return|return
name|m_function_text
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
name|m_function_name
operator|.
name|c_str
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Return the object that the parser should use when registering
comment|/// local variables. May be nullptr if the Expression doesn't care.
comment|//------------------------------------------------------------------
name|ExpressionVariableList
operator|*
name|LocalVariables
argument_list|()
block|{
return|return
name|nullptr
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
name|false
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
name|false
return|;
block|}
comment|// This makes the function caller function.
comment|// Pass in the ThreadSP if you have one available, compilation can end up
comment|// calling code (e.g. to look up indirect
comment|// functions) and we don't want this to wander onto another thread.
name|FunctionCaller
operator|*
name|MakeFunctionCaller
argument_list|(
argument|const CompilerType&return_type
argument_list|,
argument|const ValueList&arg_value_list
argument_list|,
argument|lldb::ThreadSP compilation_thread
argument_list|,
argument|Status&error
argument_list|)
block|;
comment|// This one retrieves the function caller that is already made.  If you
comment|// haven't made it yet, this returns nullptr
name|FunctionCaller
operator|*
name|GetFunctionCaller
argument_list|()
block|{
return|return
name|m_caller_up
operator|.
name|get
argument_list|()
return|;
block|}
name|protected
operator|:
name|std
operator|::
name|shared_ptr
operator|<
name|IRExecutionUnit
operator|>
name|m_execution_unit_sp
block|;
name|lldb
operator|::
name|ModuleWP
name|m_jit_module_wp
block|;
name|std
operator|::
name|string
name|m_function_text
block|;
comment|///< The text of the function.  Must be a
comment|///well-formed translation unit.
name|std
operator|::
name|string
name|m_function_name
block|;
comment|///< The name of the function.
name|std
operator|::
name|unique_ptr
operator|<
name|FunctionCaller
operator|>
name|m_caller_up
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_UtilityFunction_h_
end_comment

end_unit

