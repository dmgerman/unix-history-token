begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- IRToDWARF.h ---------------------------------------------*- C++ -*-===//
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
name|liblldb_IRToDWARF_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_IRToDWARF_h_
end_define

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/PassManager.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-public.h"
end_include

begin_decl_stmt
name|class
name|Relocator
decl_stmt|;
end_decl_stmt

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|/// @class IRToDWARF IRToDWARF.h "lldb/Expression/IRToDWARF.h"
end_comment

begin_comment
comment|/// @brief Transforms the IR for a function into a DWARF location expression
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Once an expression has been parsed and converted to IR, it can run
end_comment

begin_comment
comment|/// in two contexts: interpreted by LLDB as a DWARF location expression,
end_comment

begin_comment
comment|/// or compiled by the JIT and inserted into the target process for
end_comment

begin_comment
comment|/// execution.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// IRToDWARF makes the first possible, by traversing the control flow
end_comment

begin_comment
comment|/// graph and writing the code for each basic block out as location
end_comment

begin_comment
comment|/// expression bytecode.  To ensure that the links between the basic blocks
end_comment

begin_comment
comment|/// remain intact, it uses a relocator that records the location of every
end_comment

begin_comment
comment|/// location expression instruction that has a relocatable operand, the
end_comment

begin_comment
comment|/// target of that operand (as a basic block), and the mapping of each basic
end_comment

begin_comment
comment|/// block to an actual location.  After all code has been written out, the
end_comment

begin_comment
comment|/// relocator post-processes it and performs all necessary relocations.
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_decl_stmt
name|class
name|IRToDWARF
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
comment|/// @param[in] local_vars
comment|///     A list of variables to populate with the local variables this
comment|///     expression uses.
comment|///
comment|/// @param[in] decl_map
comment|///     The list of externally-referenced variables for the expression,
comment|///     for use in looking up globals.
comment|///
comment|/// @param[in] stream
comment|///     The stream to dump DWARF bytecode onto.
comment|///
comment|/// @param[in] func_name
comment|///     The name of the function to translate to DWARF.
comment|//------------------------------------------------------------------
name|IRToDWARF
argument_list|(
name|lldb_private
operator|::
name|ClangExpressionVariableList
operator|&
name|local_vars
argument_list|,
name|lldb_private
operator|::
name|ClangExpressionDeclMap
operator|*
name|decl_map
argument_list|,
name|lldb_private
operator|::
name|StreamString
operator|&
name|strm
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
name|IRToDWARF
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// Run this IR transformer on a single module
comment|///
comment|/// @param[in] M
comment|///     The module to run on.  This module is searched for the function
comment|///     $__lldb_expr, and that function is converted to a location
comment|///     expression.
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
comment|/// Run this IR transformer on a single basic block
comment|///
comment|/// @param[in] BB
comment|///     The basic block to transform.
comment|///
comment|/// @param[in] Relocator
comment|///     The relocator to use when registering branches.
comment|///
comment|/// @return
comment|///     True on success; false otherwise
comment|//------------------------------------------------------------------
name|bool
name|runOnBasicBlock
argument_list|(
name|llvm
operator|::
name|BasicBlock
operator|&
name|BB
argument_list|,
name|Relocator
operator|&
name|Relocator
argument_list|)
block|;
name|std
operator|::
name|string
name|m_func_name
block|;
comment|///< The name of the function to translate
name|lldb_private
operator|::
name|ClangExpressionVariableList
operator|&
name|m_local_vars
block|;
comment|///< The list of local variables to populate while transforming
name|lldb_private
operator|::
name|ClangExpressionDeclMap
operator|*
name|m_decl_map
block|;
comment|///< The list of external variables
name|lldb_private
operator|::
name|StreamString
operator|&
name|m_strm
block|;
comment|///< The stream to write bytecode to
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

