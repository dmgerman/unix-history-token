begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PrologEpilogInserter.h - Prolog/Epilog code insertion -*- C++ -* --===//
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
comment|// This pass is responsible for finalizing the functions frame layout, saving
end_comment

begin_comment
comment|// callee saved registers, and for emitting prolog& epilog code for the
end_comment

begin_comment
comment|// function.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This pass must be run after register allocation.  After this pass is
end_comment

begin_comment
comment|// executed, it is illegal to construct MO_FrameIndex operands.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This pass also implements a shrink wrapping variant of prolog/epilog
end_comment

begin_comment
comment|// insertion.
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
name|LLVM_CODEGEN_PEI_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_PEI_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/Passes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunctionPass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineLoopInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SparseBitVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetRegisterInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|RegScavenger
decl_stmt|;
name|class
name|MachineBasicBlock
decl_stmt|;
name|class
name|PEI
range|:
name|public
name|MachineFunctionPass
block|{
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|PEI
argument_list|()
operator|:
name|MachineFunctionPass
argument_list|(
argument|&ID
argument_list|)
block|{}
specifier|const
name|char
operator|*
name|getPassName
argument_list|()
specifier|const
block|{
return|return
literal|"Prolog/Epilog Insertion& Frame Finalization"
return|;
block|}
name|virtual
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
block|;
comment|/// runOnMachineFunction - Insert prolog/epilog code and replace abstract
comment|/// frame indexes with appropriate references.
comment|///
name|bool
name|runOnMachineFunction
argument_list|(
name|MachineFunction
operator|&
name|Fn
argument_list|)
block|;
name|private
operator|:
name|RegScavenger
operator|*
name|RS
block|;
comment|// MinCSFrameIndex, MaxCSFrameIndex - Keeps the range of callee saved
comment|// stack frame indexes.
name|unsigned
name|MinCSFrameIndex
block|,
name|MaxCSFrameIndex
block|;
comment|// Analysis info for spill/restore placement.
comment|// "CSR": "callee saved register".
comment|// CSRegSet contains indices into the Callee Saved Register Info
comment|// vector built by calculateCalleeSavedRegisters() and accessed
comment|// via MF.getFrameInfo()->getCalleeSavedInfo().
typedef|typedef
name|SparseBitVector
operator|<
operator|>
name|CSRegSet
expr_stmt|;
comment|// CSRegBlockMap maps MachineBasicBlocks to sets of callee
comment|// saved register indices.
typedef|typedef
name|DenseMap
operator|<
name|MachineBasicBlock
operator|*
operator|,
name|CSRegSet
operator|>
name|CSRegBlockMap
expr_stmt|;
comment|// Set and maps for computing CSR spill/restore placement:
comment|//  used in function (UsedCSRegs)
comment|//  used in a basic block (CSRUsed)
comment|//  anticipatable in a basic block (Antic{In,Out})
comment|//  available in a basic block (Avail{In,Out})
comment|//  to be spilled at the entry to a basic block (CSRSave)
comment|//  to be restored at the end of a basic block (CSRRestore)
name|CSRegSet
name|UsedCSRegs
decl_stmt|;
name|CSRegBlockMap
name|CSRUsed
decl_stmt|;
name|CSRegBlockMap
name|AnticIn
decl_stmt|,
name|AnticOut
decl_stmt|;
name|CSRegBlockMap
name|AvailIn
decl_stmt|,
name|AvailOut
decl_stmt|;
name|CSRegBlockMap
name|CSRSave
decl_stmt|;
name|CSRegBlockMap
name|CSRRestore
decl_stmt|;
comment|// Entry and return blocks of the current function.
name|MachineBasicBlock
modifier|*
name|EntryBlock
decl_stmt|;
name|SmallVector
operator|<
name|MachineBasicBlock
operator|*
operator|,
literal|4
operator|>
name|ReturnBlocks
expr_stmt|;
comment|// Map of MBBs to top level MachineLoops.
name|DenseMap
operator|<
name|MachineBasicBlock
operator|*
operator|,
name|MachineLoop
operator|*
operator|>
name|TLLoops
expr_stmt|;
comment|// Flag to control shrink wrapping per-function:
comment|// may choose to skip shrink wrapping for certain
comment|// functions.
name|bool
name|ShrinkWrapThisFunction
decl_stmt|;
comment|// Flag to control whether to use the register scavenger to resolve
comment|// frame index materialization registers. Set according to
comment|// TRI->requiresFrameIndexScavenging() for the curren function.
name|bool
name|FrameIndexVirtualScavenging
decl_stmt|;
comment|// When using the scavenger post-pass to resolve frame reference
comment|// materialization registers, maintain a map of the registers to
comment|// the constant value and SP adjustment associated with it.
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|int
operator|,
name|int
operator|>
name|FrameConstantEntry
expr_stmt|;
name|DenseMap
operator|<
name|unsigned
operator|,
name|FrameConstantEntry
operator|>
name|FrameConstantRegMap
expr_stmt|;
ifndef|#
directive|ifndef
name|NDEBUG
comment|// Machine function handle.
name|MachineFunction
modifier|*
name|MF
decl_stmt|;
comment|// Flag indicating that the current function
comment|// has at least one "short" path in the machine
comment|// CFG from the entry block to an exit block.
name|bool
name|HasFastExitPath
decl_stmt|;
endif|#
directive|endif
name|bool
name|calculateSets
parameter_list|(
name|MachineFunction
modifier|&
name|Fn
parameter_list|)
function_decl|;
name|bool
name|calcAnticInOut
parameter_list|(
name|MachineBasicBlock
modifier|*
name|MBB
parameter_list|)
function_decl|;
name|bool
name|calcAvailInOut
parameter_list|(
name|MachineBasicBlock
modifier|*
name|MBB
parameter_list|)
function_decl|;
name|void
name|calculateAnticAvail
parameter_list|(
name|MachineFunction
modifier|&
name|Fn
parameter_list|)
function_decl|;
name|bool
name|addUsesForMEMERegion
argument_list|(
name|MachineBasicBlock
operator|*
name|MBB
argument_list|,
name|SmallVector
operator|<
name|MachineBasicBlock
operator|*
argument_list|,
literal|4
operator|>
operator|&
name|blks
argument_list|)
decl_stmt|;
name|bool
name|addUsesForTopLevelLoops
argument_list|(
name|SmallVector
operator|<
name|MachineBasicBlock
operator|*
argument_list|,
literal|4
operator|>
operator|&
name|blks
argument_list|)
decl_stmt|;
name|bool
name|calcSpillPlacements
argument_list|(
name|MachineBasicBlock
operator|*
name|MBB
argument_list|,
name|SmallVector
operator|<
name|MachineBasicBlock
operator|*
argument_list|,
literal|4
operator|>
operator|&
name|blks
argument_list|,
name|CSRegBlockMap
operator|&
name|prevSpills
argument_list|)
decl_stmt|;
name|bool
name|calcRestorePlacements
argument_list|(
name|MachineBasicBlock
operator|*
name|MBB
argument_list|,
name|SmallVector
operator|<
name|MachineBasicBlock
operator|*
argument_list|,
literal|4
operator|>
operator|&
name|blks
argument_list|,
name|CSRegBlockMap
operator|&
name|prevRestores
argument_list|)
decl_stmt|;
name|void
name|placeSpillsAndRestores
parameter_list|(
name|MachineFunction
modifier|&
name|Fn
parameter_list|)
function_decl|;
name|void
name|placeCSRSpillsAndRestores
parameter_list|(
name|MachineFunction
modifier|&
name|Fn
parameter_list|)
function_decl|;
name|void
name|calculateCallsInformation
parameter_list|(
name|MachineFunction
modifier|&
name|Fn
parameter_list|)
function_decl|;
name|void
name|calculateCalleeSavedRegisters
parameter_list|(
name|MachineFunction
modifier|&
name|Fn
parameter_list|)
function_decl|;
name|void
name|insertCSRSpillsAndRestores
parameter_list|(
name|MachineFunction
modifier|&
name|Fn
parameter_list|)
function_decl|;
name|void
name|calculateFrameObjectOffsets
parameter_list|(
name|MachineFunction
modifier|&
name|Fn
parameter_list|)
function_decl|;
name|void
name|replaceFrameIndices
parameter_list|(
name|MachineFunction
modifier|&
name|Fn
parameter_list|)
function_decl|;
name|void
name|scavengeFrameVirtualRegs
parameter_list|(
name|MachineFunction
modifier|&
name|Fn
parameter_list|)
function_decl|;
name|void
name|insertPrologEpilogCode
parameter_list|(
name|MachineFunction
modifier|&
name|Fn
parameter_list|)
function_decl|;
comment|// Initialize DFA sets, called before iterations.
name|void
name|clearAnticAvailSets
parameter_list|()
function_decl|;
comment|// Clear all sets constructed by shrink wrapping.
name|void
name|clearAllSets
parameter_list|()
function_decl|;
comment|// Initialize all shrink wrapping data.
name|void
name|initShrinkWrappingInfo
parameter_list|()
function_decl|;
comment|// Convienences for dealing with machine loops.
name|MachineBasicBlock
modifier|*
name|getTopLevelLoopPreheader
parameter_list|(
name|MachineLoop
modifier|*
name|LP
parameter_list|)
function_decl|;
name|MachineLoop
modifier|*
name|getTopLevelLoopParent
parameter_list|(
name|MachineLoop
modifier|*
name|LP
parameter_list|)
function_decl|;
comment|// Propgate CSRs used in MBB to all MBBs of loop LP.
name|void
name|propagateUsesAroundLoop
parameter_list|(
name|MachineBasicBlock
modifier|*
name|MBB
parameter_list|,
name|MachineLoop
modifier|*
name|LP
parameter_list|)
function_decl|;
comment|// Convenience for recognizing return blocks.
name|bool
name|isReturnBlock
parameter_list|(
name|MachineBasicBlock
modifier|*
name|MBB
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|NDEBUG
comment|// Debugging methods.
comment|// Mark this function as having fast exit paths.
name|void
name|findFastExitPath
parameter_list|()
function_decl|;
comment|// Verify placement of spills/restores.
name|void
name|verifySpillRestorePlacement
parameter_list|()
function_decl|;
name|std
operator|::
name|string
name|getBasicBlockName
argument_list|(
specifier|const
name|MachineBasicBlock
operator|*
name|MBB
argument_list|)
expr_stmt|;
name|std
operator|::
name|string
name|stringifyCSRegSet
argument_list|(
specifier|const
name|CSRegSet
operator|&
name|s
argument_list|)
expr_stmt|;
name|void
name|dumpSet
parameter_list|(
specifier|const
name|CSRegSet
modifier|&
name|s
parameter_list|)
function_decl|;
name|void
name|dumpUsed
parameter_list|(
name|MachineBasicBlock
modifier|*
name|MBB
parameter_list|)
function_decl|;
name|void
name|dumpAllUsed
parameter_list|()
function_decl|;
name|void
name|dumpSets
parameter_list|(
name|MachineBasicBlock
modifier|*
name|MBB
parameter_list|)
function_decl|;
name|void
name|dumpSets1
parameter_list|(
name|MachineBasicBlock
modifier|*
name|MBB
parameter_list|)
function_decl|;
name|void
name|dumpAllSets
parameter_list|()
function_decl|;
name|void
name|dumpSRSets
parameter_list|()
function_decl|;
endif|#
directive|endif
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

