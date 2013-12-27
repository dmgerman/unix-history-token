begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- IRDynamicChecks.h ---------------------------------------------*- C++ -*-===//
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
name|liblldb_IRDynamicChecks_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_IRDynamicChecks_h_
end_define

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BasicBlock
decl_stmt|;
name|class
name|CallInst
decl_stmt|;
name|class
name|Constant
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|DataLayout
decl_stmt|;
name|class
name|Value
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ClangExpressionDeclMap
decl_stmt|;
name|class
name|ClangUtilityFunction
decl_stmt|;
name|class
name|ExecutionContext
decl_stmt|;
name|class
name|Stream
decl_stmt|;
comment|//----------------------------------------------------------------------
comment|/// @class DynamicCheckerFunctions IRDynamicChecks.h "lldb/Expression/IRDynamicChecks.h"
comment|/// @brief Encapsulates dynamic check functions used by expressions.
comment|///
comment|/// Each of the utility functions encapsulated in this class is responsible
comment|/// for validating some data that an expression is about to use.  Examples are:
comment|///
comment|/// a = *b;     // check that b is a valid pointer
comment|/// [b init];   // check that b is a valid object to send "init" to
comment|///
comment|/// The class installs each checker function into the target process and
comment|/// makes it available to IRDynamicChecks to use.
comment|//----------------------------------------------------------------------
name|class
name|DynamicCheckerFunctions
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|/// Constructor
comment|//------------------------------------------------------------------
name|DynamicCheckerFunctions
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Destructor
comment|//------------------------------------------------------------------
operator|~
name|DynamicCheckerFunctions
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Install the utility functions into a process.  This binds the
comment|/// instance of DynamicCheckerFunctions to that process.
comment|///
comment|/// @param[in] error_stream
comment|///     A stream to print errors on.
comment|///
comment|/// @param[in] exe_ctx
comment|///     The execution context to install the functions into.
comment|///
comment|/// @return
comment|///     True on success; false on failure, or if the functions have
comment|///     already been installed.
comment|//------------------------------------------------------------------
name|bool
name|Install
parameter_list|(
name|Stream
modifier|&
name|error_stream
parameter_list|,
name|ExecutionContext
modifier|&
name|exe_ctx
parameter_list|)
function_decl|;
name|bool
name|DoCheckersExplainStop
argument_list|(
name|lldb
operator|::
name|addr_t
name|addr
argument_list|,
name|Stream
operator|&
name|message
argument_list|)
decl_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|ClangUtilityFunction
operator|>
name|m_valid_pointer_check
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|ClangUtilityFunction
operator|>
name|m_objc_object_check
expr_stmt|;
block|}
empty_stmt|;
comment|//----------------------------------------------------------------------
comment|/// @class IRDynamicChecks IRDynamicChecks.h "lldb/Expression/IRDynamicChecks.h"
comment|/// @brief Adds dynamic checks to a user-entered expression to reduce its likelihood of crashing
comment|///
comment|/// When an IR function is executed in the target process, it may cause
comment|/// crashes or hangs by dereferencing NULL pointers, trying to call Objective-C
comment|/// methods on objects that do not respond to them, and so forth.
comment|///
comment|/// IRDynamicChecks adds calls to the functions in DynamicCheckerFunctions
comment|/// to appropriate locations in an expression's IR.
comment|//----------------------------------------------------------------------
name|class
name|IRDynamicChecks
range|:
name|public
name|llvm
operator|::
name|ModulePass
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|/// Constructor
comment|///
comment|/// @param[in] checker_functions
comment|///     The checker functions for the target process.
comment|///
comment|/// @param[in] func_name
comment|///     The name of the function to prepare for execution in the target.
comment|///
comment|/// @param[in] decl_map
comment|///     The mapping used to look up entities in the target process. In
comment|///     this case, used to find objc_msgSend
comment|//------------------------------------------------------------------
name|IRDynamicChecks
argument_list|(
name|DynamicCheckerFunctions
operator|&
name|checker_functions
argument_list|,
specifier|const
name|char
operator|*
name|func_name
operator|=
literal|"$__lldb_expr"
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Destructor
comment|//------------------------------------------------------------------
name|virtual
operator|~
name|IRDynamicChecks
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// Run this IR transformer on a single module
comment|///
comment|/// @param[in] M
comment|///     The module to run on.  This module is searched for the function
comment|///     $__lldb_expr, and that function is passed to the passes one by
comment|///     one.
comment|///
comment|/// @return
comment|///     True on success; false otherwise
comment|//------------------------------------------------------------------
name|bool
name|runOnModule
argument_list|(
name|llvm
operator|::
name|Module
operator|&
name|M
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Interface stub
comment|//------------------------------------------------------------------
name|void
name|assignPassManager
argument_list|(
argument|llvm::PMStack&PMS
argument_list|,
argument|llvm::PassManagerType T = llvm::PMT_ModulePassManager
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Returns PMT_ModulePassManager
comment|//------------------------------------------------------------------
name|llvm
operator|::
name|PassManagerType
name|getPotentialPassManagerType
argument_list|()
specifier|const
block|;
name|private
operator|:
comment|//------------------------------------------------------------------
comment|/// A basic block-level pass to find all pointer dereferences and
comment|/// validate them before use.
comment|//------------------------------------------------------------------
comment|//------------------------------------------------------------------
comment|/// The top-level pass implementation
comment|///
comment|/// @param[in] M
comment|///     The module currently being processed.
comment|///
comment|/// @param[in] BB
comment|///     The basic block currently being processed.
comment|///
comment|/// @return
comment|///     True on success; false otherwise
comment|//------------------------------------------------------------------
name|bool
name|FindDataLoads
argument_list|(
name|llvm
operator|::
name|Module
operator|&
name|M
argument_list|,
name|llvm
operator|::
name|BasicBlock
operator|&
name|BB
argument_list|)
block|;
name|std
operator|::
name|string
name|m_func_name
block|;
comment|///< The name of the function to add checks to
name|DynamicCheckerFunctions
operator|&
name|m_checker_functions
block|;
comment|///< The checker functions for the process
block|}
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

