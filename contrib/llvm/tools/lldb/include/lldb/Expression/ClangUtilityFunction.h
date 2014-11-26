begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ClangUtilityFunction.h ----------------------------------*- C++ -*-===//
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
name|liblldb_ClangUtilityFunction_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ClangUtilityFunction_h_
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
file|<string>
end_include

begin_include
include|#
directive|include
file|<map>
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
file|"lldb/lldb-forward.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ClangForward.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Expression/ClangExpression.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class ClangUtilityFunction ClangUtilityFunction.h "lldb/Expression/ClangUtilityFunction.h"
comment|/// @brief Encapsulates a single expression for use with Clang
comment|///
comment|/// LLDB uses expressions for various purposes, notably to call functions
comment|/// and as a backend for the expr command.  ClangUtilityFunction encapsulates
comment|/// a self-contained function meant to be used from other code.  Utility
comment|/// functions can perform error-checking for ClangUserExpressions,
comment|//----------------------------------------------------------------------
name|class
name|ClangUtilityFunction
range|:
name|public
name|ClangExpression
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
name|ClangUtilityFunction
argument_list|(
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
name|virtual
operator|~
name|ClangUtilityFunction
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// Install the utility function into a process
comment|///
comment|/// @param[in] error_stream
comment|///     A stream to print parse errors and warnings to.
comment|///
comment|/// @param[in] exe_ctx
comment|///     The execution context to install the utility function to.
comment|///
comment|/// @return
comment|///     True on success (no errors); false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|Install
argument_list|(
name|Stream
operator|&
name|error_stream
argument_list|,
name|ExecutionContext
operator|&
name|exe_ctx
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Check whether the given PC is inside the function
comment|///
comment|/// Especially useful if the function dereferences NULL to indicate a failed
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
block|{
return|return
name|m_function_name
operator|.
name|c_str
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Return the object that the parser should use when resolving external
comment|/// values.  May be NULL if everything should be self-contained.
comment|//------------------------------------------------------------------
name|ClangExpressionDeclMap
operator|*
name|DeclMap
argument_list|()
block|{
return|return
name|m_expr_decl_map
operator|.
name|get
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Return the object that the parser should use when registering
comment|/// local variables.  May be NULL if the Expression doesn't care.
comment|//------------------------------------------------------------------
name|ClangExpressionVariableList
operator|*
name|LocalVariables
argument_list|()
block|{
return|return
name|NULL
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Return the object that the parser should allow to access ASTs.
comment|/// May be NULL if the ASTs do not need to be transformed.
comment|///
comment|/// @param[in] passthrough
comment|///     The ASTConsumer that the returned transformer should send
comment|///     the ASTs to after transformation.
comment|//------------------------------------------------------------------
name|clang
operator|::
name|ASTConsumer
operator|*
name|ASTTransformer
argument_list|(
argument|clang::ASTConsumer *passthrough
argument_list|)
block|{
return|return
name|NULL
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Return true if validation code should be inserted into the
comment|/// expression.
comment|//------------------------------------------------------------------
name|bool
name|NeedsValidation
argument_list|()
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
block|{
return|return
name|false
return|;
block|}
name|private
operator|:
name|std
operator|::
name|unique_ptr
operator|<
name|ClangExpressionDeclMap
operator|>
name|m_expr_decl_map
block|;
comment|///< The map to use when parsing and materializing the expression.
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
comment|///< The text of the function.  Must be a well-formed translation unit.
name|std
operator|::
name|string
name|m_function_name
block|;
comment|///< The name of the function.
block|}
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
comment|// liblldb_ClangUtilityFunction_h_
end_comment

end_unit

