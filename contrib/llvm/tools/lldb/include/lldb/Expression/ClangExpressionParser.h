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
file|"lldb/lldb-public.h"
end_include

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
file|"lldb/Core/Error.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Expression/IRForTarget.h"
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
comment|/// @class ClangExpressionParser ClangExpressionParser.h "lldb/Expression/ClangExpressionParser.h"
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
name|ClangExpressionParser
argument_list|(
argument|ExecutionContextScope *exe_scope
argument_list|,
argument|ClangExpression&expr
argument_list|,
argument|bool generate_debug_info
argument_list|)
empty_stmt|;
comment|//------------------------------------------------------------------
comment|/// Destructor
comment|//------------------------------------------------------------------
operator|~
name|ClangExpressionParser
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Parse a single expression and convert it to IR using Clang.  Don't
comment|/// wrap the expression in anything at all.
comment|///
comment|/// @param[in] stream
comment|///     The stream to print errors to.
comment|///
comment|/// @return
comment|///     The number of errors encountered during parsing.  0 means
comment|///     success.
comment|//------------------------------------------------------------------
name|unsigned
name|Parse
parameter_list|(
name|Stream
modifier|&
name|stream
parameter_list|)
function_decl|;
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
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Disassemble the machine code for a JITted function from the target
comment|/// process's memory and print the result to a stream.
comment|///
comment|/// @param[in] stream
comment|///     The stream to print disassembly to.
comment|///
comment|/// @param[in] exc_context
comment|///     The execution context to get the machine code from.
comment|///
comment|/// @return
comment|///     The error generated.  If .Success() is true, disassembly succeeded.
comment|//------------------------------------------------------------------
name|Error
name|DisassembleFunction
parameter_list|(
name|Stream
modifier|&
name|stream
parameter_list|,
name|ExecutionContext
modifier|&
name|exe_ctx
parameter_list|)
function_decl|;
name|bool
name|GetGenerateDebugInfo
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|ClangExpression
modifier|&
name|m_expr
decl_stmt|;
comment|///< The expression to be parsed
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|LLVMContext
operator|>
name|m_llvm_context
expr_stmt|;
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
expr_stmt|;
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
expr_stmt|;
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
expr_stmt|;
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
expr_stmt|;
comment|///< Selector table for Objective-C methods
name|std
operator|::
name|unique_ptr
operator|<
name|clang
operator|::
name|ASTContext
operator|>
name|m_ast_context
expr_stmt|;
comment|///< The AST context used to hold types and names for the parser
name|std
operator|::
name|unique_ptr
operator|<
name|clang
operator|::
name|CodeGenerator
operator|>
name|m_code_generator
expr_stmt|;
comment|///< The Clang object that generates IR
block|}
empty_stmt|;
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

