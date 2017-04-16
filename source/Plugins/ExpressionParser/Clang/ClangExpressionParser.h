begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ClangExpressionParser.h ---------------------------------*- C++ -*-===//
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
name|liblldb_ClangExpressionParser_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ClangExpressionParser_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Core/ArchSpec.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ClangForward.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Expression/DiagnosticManager.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Expression/ExpressionParser.h"
end_include

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
name|lldb_private
block|{
name|class
name|IRExecutionUnit
decl_stmt|;
comment|//----------------------------------------------------------------------
comment|/// @class ClangExpressionParser ClangExpressionParser.h
comment|/// "lldb/Expression/ClangExpressionParser.h"
comment|/// @brief Encapsulates an instance of Clang that can parse expressions.
comment|///
comment|/// ClangExpressionParser is responsible for preparing an instance of
comment|/// ClangExpression for execution.  ClangExpressionParser uses ClangExpression
comment|/// as a glorified parameter list, performing the required parsing and
comment|/// conversion to formats (DWARF bytecode, or JIT compiled machine code)
comment|/// that can be executed.
comment|//----------------------------------------------------------------------
name|class
name|ClangExpressionParser
range|:
name|public
name|ExpressionParser
block|{
name|public
operator|:
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
name|ClangExpressionParser
argument_list|(
argument|ExecutionContextScope *exe_scope
argument_list|,
argument|Expression&expr
argument_list|,
argument|bool generate_debug_info
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Destructor
comment|//------------------------------------------------------------------
operator|~
name|ClangExpressionParser
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------------
comment|/// Parse a single expression and convert it to IR using Clang.  Don't
comment|/// wrap the expression in anything at all.
comment|///
comment|/// @param[in] diagnostic_manager
comment|///     The diagnostic manager to report errors to.
comment|///
comment|/// @return
comment|///     The number of errors encountered during parsing.  0 means
comment|///     success.
comment|//------------------------------------------------------------------
name|unsigned
name|Parse
argument_list|(
argument|DiagnosticManager&diagnostic_manager
argument_list|)
name|override
block|;
name|bool
name|RewriteExpression
argument_list|(
argument|DiagnosticManager&diagnostic_manager
argument_list|)
name|override
block|;
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
comment|/// @param[out] evaluated_statically
comment|///     Set to true if the expression could be interpreted statically;
comment|///     untouched otherwise.
comment|///
comment|/// @param[out] const_result
comment|///     If the result of the expression is constant, and the
comment|///     expression has no side effects, this is set to the result of the
comment|///     expression.
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
name|Error
name|PrepareForExecution
argument_list|(
argument|lldb::addr_t&func_addr
argument_list|,
argument|lldb::addr_t&func_end
argument_list|,
argument|lldb::IRExecutionUnitSP&execution_unit_sp
argument_list|,
argument|ExecutionContext&exe_ctx
argument_list|,
argument|bool&can_interpret
argument_list|,
argument|lldb_private::ExecutionPolicy execution_policy
argument_list|)
name|override
block|;
comment|//------------------------------------------------------------------
comment|/// Run all static initializers for an execution unit.
comment|///
comment|/// @param[in] execution_unit_sp
comment|///     The execution unit.
comment|///
comment|/// @param[in] exe_ctx
comment|///     The execution context to use when running them.  Thread can't be null.
comment|///
comment|/// @return
comment|///     The error code indicating the
comment|//------------------------------------------------------------------
name|Error
name|RunStaticInitializers
argument_list|(
name|lldb
operator|::
name|IRExecutionUnitSP
operator|&
name|execution_unit_sp
argument_list|,
name|ExecutionContext
operator|&
name|exe_ctx
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Returns a string representing current ABI.
comment|///
comment|/// @param[in] target_arch
comment|///     The target architecture.
comment|///
comment|/// @return
comment|///     A string representing target ABI for the current architecture.
comment|//-------------------------------------------------------------------
name|std
operator|::
name|string
name|GetClangTargetABI
argument_list|(
specifier|const
name|ArchSpec
operator|&
name|target_arch
argument_list|)
block|;
name|private
operator|:
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|LLVMContext
operator|>
name|m_llvm_context
block|;
comment|///< The LLVM context to generate IR into
name|std
operator|::
name|unique_ptr
operator|<
name|clang
operator|::
name|FileManager
operator|>
name|m_file_manager
block|;
comment|///< The Clang file manager object used by the compiler
name|std
operator|::
name|unique_ptr
operator|<
name|clang
operator|::
name|CompilerInstance
operator|>
name|m_compiler
block|;
comment|///< The Clang compiler used to parse expressions into IR
name|std
operator|::
name|unique_ptr
operator|<
name|clang
operator|::
name|Builtin
operator|::
name|Context
operator|>
name|m_builtin_context
block|;
comment|///< Context for Clang built-ins
name|std
operator|::
name|unique_ptr
operator|<
name|clang
operator|::
name|SelectorTable
operator|>
name|m_selector_table
block|;
comment|///< Selector table for Objective-C methods
name|std
operator|::
name|unique_ptr
operator|<
name|clang
operator|::
name|CodeGenerator
operator|>
name|m_code_generator
block|;
comment|///< The Clang object that generates IR
name|class
name|LLDBPreprocessorCallbacks
block|;
name|LLDBPreprocessorCallbacks
operator|*
name|m_pp_callbacks
block|;
comment|///< Called when the preprocessor
comment|///encounters module imports
name|std
operator|::
name|unique_ptr
operator|<
name|ClangASTContext
operator|>
name|m_ast_context
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ClangExpressionParser_h_
end_comment

end_unit

