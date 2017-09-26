begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MemorySSAUpdater.h - Memory SSA Updater-------------------*- C++ -*-===//
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
comment|// \file
end_comment

begin_comment
comment|// \brief An automatic updater for MemorySSA that handles arbitrary insertion,
end_comment

begin_comment
comment|// deletion, and moves.  It performs phi insertion where necessary, and
end_comment

begin_comment
comment|// automatically updates the MemorySSA IR to be correct.
end_comment

begin_comment
comment|// While updating loads or removing instructions is often easy enough to not
end_comment

begin_comment
comment|// need this, updating stores should generally not be attemped outside this
end_comment

begin_comment
comment|// API.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Basic API usage:
end_comment

begin_comment
comment|// Create the memory access you want for the instruction (this is mainly so
end_comment

begin_comment
comment|// we know where it is, without having to duplicate the entire set of create
end_comment

begin_comment
comment|// functions MemorySSA supports).
end_comment

begin_comment
comment|// Call insertDef or insertUse depending on whether it's a MemoryUse or a
end_comment

begin_comment
comment|// MemoryDef.
end_comment

begin_comment
comment|// That's it.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// For moving, first, move the instruction itself using the normal SSA
end_comment

begin_comment
comment|// instruction moving API, then just call moveBefore, moveAfter,or moveTo with
end_comment

begin_comment
comment|// the right arguments.
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
name|LLVM_ANALYSIS_MEMORYSSAUPDATER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_MEMORYSSAUPDATER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/MemorySSA.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/BasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Dominators.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Module.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/OperandTraits.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Type.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Use.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/User.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Value.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Casting.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Function
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|MemoryAccess
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|MemorySSAUpdater
block|{
name|private
label|:
name|MemorySSA
modifier|*
name|MSSA
decl_stmt|;
name|SmallVector
operator|<
name|MemoryPhi
operator|*
operator|,
literal|8
operator|>
name|InsertedPHIs
expr_stmt|;
name|SmallPtrSet
operator|<
name|BasicBlock
operator|*
operator|,
literal|8
operator|>
name|VisitedBlocks
expr_stmt|;
name|public
label|:
name|MemorySSAUpdater
argument_list|(
name|MemorySSA
operator|*
name|MSSA
argument_list|)
operator|:
name|MSSA
argument_list|(
argument|MSSA
argument_list|)
block|{}
comment|/// Insert a definition into the MemorySSA IR.  RenameUses will rename any use
comment|/// below the new def block (and any inserted phis).  RenameUses should be set
comment|/// to true if the definition may cause new aliases for loads below it.  This
comment|/// is not the case for hoisting or sinking or other forms of code *movement*.
comment|/// It *is* the case for straight code insertion.
comment|/// For example:
comment|/// store a
comment|/// if (foo) { }
comment|/// load a
comment|///
comment|/// Moving the store into the if block, and calling insertDef, does not
comment|/// require RenameUses.
comment|/// However, changing it to:
comment|/// store a
comment|/// if (foo) { store b }
comment|/// load a
comment|/// Where a mayalias b, *does* require RenameUses be set to true.
name|void
name|insertDef
argument_list|(
argument|MemoryDef *Def
argument_list|,
argument|bool RenameUses = false
argument_list|)
expr_stmt|;
name|void
name|insertUse
parameter_list|(
name|MemoryUse
modifier|*
name|Use
parameter_list|)
function_decl|;
name|void
name|moveBefore
parameter_list|(
name|MemoryUseOrDef
modifier|*
name|What
parameter_list|,
name|MemoryUseOrDef
modifier|*
name|Where
parameter_list|)
function_decl|;
name|void
name|moveAfter
parameter_list|(
name|MemoryUseOrDef
modifier|*
name|What
parameter_list|,
name|MemoryUseOrDef
modifier|*
name|Where
parameter_list|)
function_decl|;
name|void
name|moveToPlace
argument_list|(
name|MemoryUseOrDef
operator|*
name|What
argument_list|,
name|BasicBlock
operator|*
name|BB
argument_list|,
name|MemorySSA
operator|::
name|InsertionPlace
name|Where
argument_list|)
decl_stmt|;
comment|// The below are utility functions. Other than creation of accesses to pass
comment|// to insertDef, and removeAccess to remove accesses, you should generally
comment|// not attempt to update memoryssa yourself. It is very non-trivial to get
comment|// the edge cases right, and the above calls already operate in near-optimal
comment|// time bounds.
comment|/// \brief Create a MemoryAccess in MemorySSA at a specified point in a block,
comment|/// with a specified clobbering definition.
comment|///
comment|/// Returns the new MemoryAccess.
comment|/// This should be called when a memory instruction is created that is being
comment|/// used to replace an existing memory instruction. It will *not* create PHI
comment|/// nodes, or verify the clobbering definition. The insertion place is used
comment|/// solely to determine where in the memoryssa access lists the instruction
comment|/// will be placed. The caller is expected to keep ordering the same as
comment|/// instructions.
comment|/// It will return the new MemoryAccess.
comment|/// Note: If a MemoryAccess already exists for I, this function will make it
comment|/// inaccessible and it *must* have removeMemoryAccess called on it.
name|MemoryAccess
modifier|*
name|createMemoryAccessInBB
argument_list|(
name|Instruction
operator|*
name|I
argument_list|,
name|MemoryAccess
operator|*
name|Definition
argument_list|,
specifier|const
name|BasicBlock
operator|*
name|BB
argument_list|,
name|MemorySSA
operator|::
name|InsertionPlace
name|Point
argument_list|)
decl_stmt|;
comment|/// \brief Create a MemoryAccess in MemorySSA before or after an existing
comment|/// MemoryAccess.
comment|///
comment|/// Returns the new MemoryAccess.
comment|/// This should be called when a memory instruction is created that is being
comment|/// used to replace an existing memory instruction. It will *not* create PHI
comment|/// nodes, or verify the clobbering definition.
comment|///
comment|/// Note: If a MemoryAccess already exists for I, this function will make it
comment|/// inaccessible and it *must* have removeMemoryAccess called on it.
name|MemoryUseOrDef
modifier|*
name|createMemoryAccessBefore
parameter_list|(
name|Instruction
modifier|*
name|I
parameter_list|,
name|MemoryAccess
modifier|*
name|Definition
parameter_list|,
name|MemoryUseOrDef
modifier|*
name|InsertPt
parameter_list|)
function_decl|;
name|MemoryUseOrDef
modifier|*
name|createMemoryAccessAfter
parameter_list|(
name|Instruction
modifier|*
name|I
parameter_list|,
name|MemoryAccess
modifier|*
name|Definition
parameter_list|,
name|MemoryAccess
modifier|*
name|InsertPt
parameter_list|)
function_decl|;
comment|/// \brief Remove a MemoryAccess from MemorySSA, including updating all
comment|/// definitions and uses.
comment|/// This should be called when a memory instruction that has a MemoryAccess
comment|/// associated with it is erased from the program.  For example, if a store or
comment|/// load is simply erased (not replaced), removeMemoryAccess should be called
comment|/// on the MemoryAccess for that store/load.
name|void
name|removeMemoryAccess
parameter_list|(
name|MemoryAccess
modifier|*
parameter_list|)
function_decl|;
name|private
label|:
comment|// Move What before Where in the MemorySSA IR.
name|template
operator|<
name|class
name|WhereType
operator|>
name|void
name|moveTo
argument_list|(
argument|MemoryUseOrDef *What
argument_list|,
argument|BasicBlock *BB
argument_list|,
argument|WhereType Where
argument_list|)
expr_stmt|;
name|MemoryAccess
modifier|*
name|getPreviousDef
parameter_list|(
name|MemoryAccess
modifier|*
parameter_list|)
function_decl|;
name|MemoryAccess
modifier|*
name|getPreviousDefInBlock
parameter_list|(
name|MemoryAccess
modifier|*
parameter_list|)
function_decl|;
name|MemoryAccess
modifier|*
name|getPreviousDefFromEnd
parameter_list|(
name|BasicBlock
modifier|*
parameter_list|)
function_decl|;
name|MemoryAccess
modifier|*
name|getPreviousDefRecursive
parameter_list|(
name|BasicBlock
modifier|*
parameter_list|)
function_decl|;
name|MemoryAccess
modifier|*
name|recursePhi
parameter_list|(
name|MemoryAccess
modifier|*
name|Phi
parameter_list|)
function_decl|;
name|template
operator|<
name|class
name|RangeType
operator|>
name|MemoryAccess
operator|*
name|tryRemoveTrivialPhi
argument_list|(
name|MemoryPhi
operator|*
name|Phi
argument_list|,
name|RangeType
operator|&
name|Operands
argument_list|)
expr_stmt|;
name|void
name|fixupDefs
argument_list|(
specifier|const
name|SmallVectorImpl
operator|<
name|MemoryAccess
operator|*
operator|>
operator|&
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_ANALYSIS_MEMORYSSAUPDATER_H
end_comment

end_unit

