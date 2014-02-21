begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- LiveIntervalAnalysis.h - Live Interval Analysis ---------*- C++ -*-===//
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
comment|// This file implements the LiveInterval analysis pass.  Given some numbering of
end_comment

begin_comment
comment|// each the machine instructions (in this implemention depth-first order) an
end_comment

begin_comment
comment|// interval [i, j) is said to be a live interval for register v if there is no
end_comment

begin_comment
comment|// instruction with number j'> j such that v is live at j' and there is no
end_comment

begin_comment
comment|// instruction with number i'< i such that v is live at i'. In this
end_comment

begin_comment
comment|// implementation intervals can have holes, i.e. an interval might look like
end_comment

begin_comment
comment|// [1,20), [50,65), [1000,1001).
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
name|LLVM_CODEGEN_LIVEINTERVAL_ANALYSIS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_LIVEINTERVAL_ANALYSIS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/IndexedMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/LiveInterval.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineBasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunctionPass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SlotIndexes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|<cmath>
end_include

begin_include
include|#
directive|include
file|<iterator>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AliasAnalysis
decl_stmt|;
name|class
name|BitVector
decl_stmt|;
name|class
name|BlockFrequency
decl_stmt|;
name|class
name|LiveRangeCalc
decl_stmt|;
name|class
name|LiveVariables
decl_stmt|;
name|class
name|MachineDominatorTree
decl_stmt|;
name|class
name|MachineLoopInfo
decl_stmt|;
name|class
name|TargetRegisterInfo
decl_stmt|;
name|class
name|MachineRegisterInfo
decl_stmt|;
name|class
name|TargetInstrInfo
decl_stmt|;
name|class
name|TargetRegisterClass
decl_stmt|;
name|class
name|VirtRegMap
decl_stmt|;
name|class
name|LiveIntervals
range|:
name|public
name|MachineFunctionPass
block|{
name|MachineFunction
operator|*
name|MF
block|;
name|MachineRegisterInfo
operator|*
name|MRI
block|;
specifier|const
name|TargetMachine
operator|*
name|TM
block|;
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
block|;
specifier|const
name|TargetInstrInfo
operator|*
name|TII
block|;
name|AliasAnalysis
operator|*
name|AA
block|;
name|SlotIndexes
operator|*
name|Indexes
block|;
name|MachineDominatorTree
operator|*
name|DomTree
block|;
name|LiveRangeCalc
operator|*
name|LRCalc
block|;
comment|/// Special pool allocator for VNInfo's (LiveInterval val#).
comment|///
name|VNInfo
operator|::
name|Allocator
name|VNInfoAllocator
block|;
comment|/// Live interval pointers for all the virtual registers.
name|IndexedMap
operator|<
name|LiveInterval
operator|*
block|,
name|VirtReg2IndexFunctor
operator|>
name|VirtRegIntervals
block|;
comment|/// RegMaskSlots - Sorted list of instructions with register mask operands.
comment|/// Always use the 'r' slot, RegMasks are normal clobbers, not early
comment|/// clobbers.
name|SmallVector
operator|<
name|SlotIndex
block|,
literal|8
operator|>
name|RegMaskSlots
block|;
comment|/// RegMaskBits - This vector is parallel to RegMaskSlots, it holds a
comment|/// pointer to the corresponding register mask.  This pointer can be
comment|/// recomputed as:
comment|///
comment|///   MI = Indexes->getInstructionFromIndex(RegMaskSlot[N]);
comment|///   unsigned OpNum = findRegMaskOperand(MI);
comment|///   RegMaskBits[N] = MI->getOperand(OpNum).getRegMask();
comment|///
comment|/// This is kept in a separate vector partly because some standard
comment|/// libraries don't support lower_bound() with mixed objects, partly to
comment|/// improve locality when searching in RegMaskSlots.
comment|/// Also see the comment in LiveInterval::find().
name|SmallVector
operator|<
specifier|const
name|uint32_t
operator|*
block|,
literal|8
operator|>
name|RegMaskBits
block|;
comment|/// For each basic block number, keep (begin, size) pairs indexing into the
comment|/// RegMaskSlots and RegMaskBits arrays.
comment|/// Note that basic block numbers may not be layout contiguous, that's why
comment|/// we can't just keep track of the first register mask in each basic
comment|/// block.
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
name|unsigned
operator|>
block|,
literal|8
operator|>
name|RegMaskBlocks
block|;
comment|/// Keeps a live range set for each register unit to track fixed physreg
comment|/// interference.
name|SmallVector
operator|<
name|LiveRange
operator|*
block|,
literal|0
operator|>
name|RegUnitRanges
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
comment|// Pass identification, replacement for typeid
name|LiveIntervals
argument_list|()
block|;
name|virtual
operator|~
name|LiveIntervals
argument_list|()
block|;
comment|// Calculate the spill weight to assign to a single instruction.
specifier|static
name|float
name|getSpillWeight
argument_list|(
argument|bool isDef
argument_list|,
argument|bool isUse
argument_list|,
argument|BlockFrequency freq
argument_list|)
block|;
name|LiveInterval
operator|&
name|getInterval
argument_list|(
argument|unsigned Reg
argument_list|)
block|{
if|if
condition|(
name|hasInterval
argument_list|(
name|Reg
argument_list|)
condition|)
return|return
operator|*
name|VirtRegIntervals
index|[
name|Reg
index|]
return|;
else|else
return|return
name|createAndComputeVirtRegInterval
argument_list|(
name|Reg
argument_list|)
return|;
block|}
specifier|const
name|LiveInterval
operator|&
name|getInterval
argument_list|(
argument|unsigned Reg
argument_list|)
specifier|const
block|{
return|return
name|const_cast
operator|<
name|LiveIntervals
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getInterval
argument_list|(
name|Reg
argument_list|)
return|;
block|}
name|bool
name|hasInterval
argument_list|(
argument|unsigned Reg
argument_list|)
specifier|const
block|{
return|return
name|VirtRegIntervals
operator|.
name|inBounds
argument_list|(
name|Reg
argument_list|)
operator|&&
name|VirtRegIntervals
index|[
name|Reg
index|]
return|;
block|}
comment|// Interval creation.
name|LiveInterval
operator|&
name|createEmptyInterval
argument_list|(
argument|unsigned Reg
argument_list|)
block|{
name|assert
argument_list|(
operator|!
name|hasInterval
argument_list|(
name|Reg
argument_list|)
operator|&&
literal|"Interval already exists!"
argument_list|)
block|;
name|VirtRegIntervals
operator|.
name|grow
argument_list|(
name|Reg
argument_list|)
block|;
name|VirtRegIntervals
index|[
name|Reg
index|]
operator|=
name|createInterval
argument_list|(
name|Reg
argument_list|)
block|;
return|return
operator|*
name|VirtRegIntervals
index|[
name|Reg
index|]
return|;
block|}
name|LiveInterval
operator|&
name|createAndComputeVirtRegInterval
argument_list|(
argument|unsigned Reg
argument_list|)
block|{
name|LiveInterval
operator|&
name|LI
operator|=
name|createEmptyInterval
argument_list|(
name|Reg
argument_list|)
block|;
name|computeVirtRegInterval
argument_list|(
name|LI
argument_list|)
block|;
return|return
name|LI
return|;
block|}
comment|// Interval removal.
name|void
name|removeInterval
argument_list|(
argument|unsigned Reg
argument_list|)
block|{
name|delete
name|VirtRegIntervals
index|[
name|Reg
index|]
block|;
name|VirtRegIntervals
index|[
name|Reg
index|]
operator|=
literal|0
block|;     }
comment|/// Given a register and an instruction, adds a live segment from that
comment|/// instruction to the end of its MBB.
name|LiveInterval
operator|::
name|Segment
name|addSegmentToEndOfBlock
argument_list|(
argument|unsigned reg
argument_list|,
argument|MachineInstr* startInst
argument_list|)
block|;
comment|/// shrinkToUses - After removing some uses of a register, shrink its live
comment|/// range to just the remaining uses. This method does not compute reaching
comment|/// defs for new uses, and it doesn't remove dead defs.
comment|/// Dead PHIDef values are marked as unused.
comment|/// New dead machine instructions are added to the dead vector.
comment|/// Return true if the interval may have been separated into multiple
comment|/// connected components.
name|bool
name|shrinkToUses
argument_list|(
name|LiveInterval
operator|*
name|li
argument_list|,
name|SmallVectorImpl
operator|<
name|MachineInstr
operator|*
operator|>
operator|*
name|dead
operator|=
literal|0
argument_list|)
block|;
comment|/// extendToIndices - Extend the live range of LI to reach all points in
comment|/// Indices. The points in the Indices array must be jointly dominated by
comment|/// existing defs in LI. PHI-defs are added as needed to maintain SSA form.
comment|///
comment|/// If a SlotIndex in Indices is the end index of a basic block, LI will be
comment|/// extended to be live out of the basic block.
comment|///
comment|/// See also LiveRangeCalc::extend().
name|void
name|extendToIndices
argument_list|(
name|LiveRange
operator|&
name|LR
argument_list|,
name|ArrayRef
operator|<
name|SlotIndex
operator|>
name|Indices
argument_list|)
block|;
comment|/// pruneValue - If an LI value is live at Kill, prune its live range by
comment|/// removing any liveness reachable from Kill. Add live range end points to
comment|/// EndPoints such that extendToIndices(LI, EndPoints) will reconstruct the
comment|/// value's live range.
comment|///
comment|/// Calling pruneValue() and extendToIndices() can be used to reconstruct
comment|/// SSA form after adding defs to a virtual register.
name|void
name|pruneValue
argument_list|(
argument|LiveInterval *LI
argument_list|,
argument|SlotIndex Kill
argument_list|,
argument|SmallVectorImpl<SlotIndex> *EndPoints
argument_list|)
block|;
name|SlotIndexes
operator|*
name|getSlotIndexes
argument_list|()
specifier|const
block|{
return|return
name|Indexes
return|;
block|}
name|AliasAnalysis
operator|*
name|getAliasAnalysis
argument_list|()
specifier|const
block|{
return|return
name|AA
return|;
block|}
comment|/// isNotInMIMap - returns true if the specified machine instr has been
comment|/// removed or was never entered in the map.
name|bool
name|isNotInMIMap
argument_list|(
argument|const MachineInstr* Instr
argument_list|)
specifier|const
block|{
return|return
operator|!
name|Indexes
operator|->
name|hasIndex
argument_list|(
name|Instr
argument_list|)
return|;
block|}
comment|/// Returns the base index of the given instruction.
name|SlotIndex
name|getInstructionIndex
argument_list|(
argument|const MachineInstr *instr
argument_list|)
specifier|const
block|{
return|return
name|Indexes
operator|->
name|getInstructionIndex
argument_list|(
name|instr
argument_list|)
return|;
block|}
comment|/// Returns the instruction associated with the given index.
name|MachineInstr
operator|*
name|getInstructionFromIndex
argument_list|(
argument|SlotIndex index
argument_list|)
specifier|const
block|{
return|return
name|Indexes
operator|->
name|getInstructionFromIndex
argument_list|(
name|index
argument_list|)
return|;
block|}
comment|/// Return the first index in the given basic block.
name|SlotIndex
name|getMBBStartIdx
argument_list|(
argument|const MachineBasicBlock *mbb
argument_list|)
specifier|const
block|{
return|return
name|Indexes
operator|->
name|getMBBStartIdx
argument_list|(
name|mbb
argument_list|)
return|;
block|}
comment|/// Return the last index in the given basic block.
name|SlotIndex
name|getMBBEndIdx
argument_list|(
argument|const MachineBasicBlock *mbb
argument_list|)
specifier|const
block|{
return|return
name|Indexes
operator|->
name|getMBBEndIdx
argument_list|(
name|mbb
argument_list|)
return|;
block|}
name|bool
name|isLiveInToMBB
argument_list|(
argument|const LiveRange&LR
argument_list|,
argument|const MachineBasicBlock *mbb
argument_list|)
specifier|const
block|{
return|return
name|LR
operator|.
name|liveAt
argument_list|(
name|getMBBStartIdx
argument_list|(
name|mbb
argument_list|)
argument_list|)
return|;
block|}
name|bool
name|isLiveOutOfMBB
argument_list|(
argument|const LiveRange&LR
argument_list|,
argument|const MachineBasicBlock *mbb
argument_list|)
specifier|const
block|{
return|return
name|LR
operator|.
name|liveAt
argument_list|(
name|getMBBEndIdx
argument_list|(
name|mbb
argument_list|)
operator|.
name|getPrevSlot
argument_list|()
argument_list|)
return|;
block|}
name|MachineBasicBlock
operator|*
name|getMBBFromIndex
argument_list|(
argument|SlotIndex index
argument_list|)
specifier|const
block|{
return|return
name|Indexes
operator|->
name|getMBBFromIndex
argument_list|(
name|index
argument_list|)
return|;
block|}
name|void
name|insertMBBInMaps
argument_list|(
argument|MachineBasicBlock *MBB
argument_list|)
block|{
name|Indexes
operator|->
name|insertMBBInMaps
argument_list|(
name|MBB
argument_list|)
block|;
name|assert
argument_list|(
name|unsigned
argument_list|(
name|MBB
operator|->
name|getNumber
argument_list|()
argument_list|)
operator|==
name|RegMaskBlocks
operator|.
name|size
argument_list|()
operator|&&
literal|"Blocks must be added in order."
argument_list|)
block|;
name|RegMaskBlocks
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|RegMaskSlots
operator|.
name|size
argument_list|()
argument_list|,
literal|0
argument_list|)
argument_list|)
block|;     }
name|SlotIndex
name|InsertMachineInstrInMaps
argument_list|(
argument|MachineInstr *MI
argument_list|)
block|{
return|return
name|Indexes
operator|->
name|insertMachineInstrInMaps
argument_list|(
name|MI
argument_list|)
return|;
block|}
name|void
name|InsertMachineInstrRangeInMaps
argument_list|(
argument|MachineBasicBlock::iterator B
argument_list|,
argument|MachineBasicBlock::iterator E
argument_list|)
block|{
for|for
control|(
name|MachineBasicBlock
operator|::
name|iterator
name|I
operator|=
name|B
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
name|Indexes
operator|->
name|insertMachineInstrInMaps
argument_list|(
name|I
argument_list|)
expr_stmt|;
block|}
name|void
name|RemoveMachineInstrFromMaps
argument_list|(
argument|MachineInstr *MI
argument_list|)
block|{
name|Indexes
operator|->
name|removeMachineInstrFromMaps
argument_list|(
name|MI
argument_list|)
block|;     }
name|void
name|ReplaceMachineInstrInMaps
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineInstr *NewMI
argument_list|)
block|{
name|Indexes
operator|->
name|replaceMachineInstrInMaps
argument_list|(
name|MI
argument_list|,
name|NewMI
argument_list|)
block|;     }
name|bool
name|findLiveInMBBs
argument_list|(
argument|SlotIndex Start
argument_list|,
argument|SlotIndex End
argument_list|,
argument|SmallVectorImpl<MachineBasicBlock*>&MBBs
argument_list|)
specifier|const
block|{
return|return
name|Indexes
operator|->
name|findLiveInMBBs
argument_list|(
name|Start
argument_list|,
name|End
argument_list|,
name|MBBs
argument_list|)
return|;
block|}
name|VNInfo
operator|::
name|Allocator
operator|&
name|getVNInfoAllocator
argument_list|()
block|{
return|return
name|VNInfoAllocator
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
name|virtual
name|void
name|releaseMemory
argument_list|()
block|;
comment|/// runOnMachineFunction - pass entry point
name|virtual
name|bool
name|runOnMachineFunction
argument_list|(
name|MachineFunction
operator|&
argument_list|)
block|;
comment|/// print - Implement the dump method.
name|virtual
name|void
name|print
argument_list|(
argument|raw_ostream&O
argument_list|,
argument|const Module* =
literal|0
argument_list|)
specifier|const
block|;
comment|/// intervalIsInOneMBB - If LI is confined to a single basic block, return
comment|/// a pointer to that block.  If LI is live in to or out of any block,
comment|/// return NULL.
name|MachineBasicBlock
operator|*
name|intervalIsInOneMBB
argument_list|(
argument|const LiveInterval&LI
argument_list|)
specifier|const
block|;
comment|/// Returns true if VNI is killed by any PHI-def values in LI.
comment|/// This may conservatively return true to avoid expensive computations.
name|bool
name|hasPHIKill
argument_list|(
argument|const LiveInterval&LI
argument_list|,
argument|const VNInfo *VNI
argument_list|)
specifier|const
block|;
comment|/// addKillFlags - Add kill flags to any instruction that kills a virtual
comment|/// register.
name|void
name|addKillFlags
argument_list|(
specifier|const
name|VirtRegMap
operator|*
argument_list|)
block|;
comment|/// handleMove - call this method to notify LiveIntervals that
comment|/// instruction 'mi' has been moved within a basic block. This will update
comment|/// the live intervals for all operands of mi. Moves between basic blocks
comment|/// are not supported.
comment|///
comment|/// \param UpdateFlags Update live intervals for nonallocatable physregs.
name|void
name|handleMove
argument_list|(
argument|MachineInstr* MI
argument_list|,
argument|bool UpdateFlags = false
argument_list|)
block|;
comment|/// moveIntoBundle - Update intervals for operands of MI so that they
comment|/// begin/end on the SlotIndex for BundleStart.
comment|///
comment|/// \param UpdateFlags Update live intervals for nonallocatable physregs.
comment|///
comment|/// Requires MI and BundleStart to have SlotIndexes, and assumes
comment|/// existing liveness is accurate. BundleStart should be the first
comment|/// instruction in the Bundle.
name|void
name|handleMoveIntoBundle
argument_list|(
argument|MachineInstr* MI
argument_list|,
argument|MachineInstr* BundleStart
argument_list|,
argument|bool UpdateFlags = false
argument_list|)
block|;
comment|/// repairIntervalsInRange - Update live intervals for instructions in a
comment|/// range of iterators. It is intended for use after target hooks that may
comment|/// insert or remove instructions, and is only efficient for a small number
comment|/// of instructions.
comment|///
comment|/// OrigRegs is a vector of registers that were originally used by the
comment|/// instructions in the range between the two iterators.
comment|///
comment|/// Currently, the only only changes that are supported are simple removal
comment|/// and addition of uses.
name|void
name|repairIntervalsInRange
argument_list|(
argument|MachineBasicBlock *MBB
argument_list|,
argument|MachineBasicBlock::iterator Begin
argument_list|,
argument|MachineBasicBlock::iterator End
argument_list|,
argument|ArrayRef<unsigned> OrigRegs
argument_list|)
block|;
comment|// Register mask functions.
comment|//
comment|// Machine instructions may use a register mask operand to indicate that a
comment|// large number of registers are clobbered by the instruction.  This is
comment|// typically used for calls.
comment|//
comment|// For compile time performance reasons, these clobbers are not recorded in
comment|// the live intervals for individual physical registers.  Instead,
comment|// LiveIntervalAnalysis maintains a sorted list of instructions with
comment|// register mask operands.
comment|/// getRegMaskSlots - Returns a sorted array of slot indices of all
comment|/// instructions with register mask operands.
name|ArrayRef
operator|<
name|SlotIndex
operator|>
name|getRegMaskSlots
argument_list|()
specifier|const
block|{
return|return
name|RegMaskSlots
return|;
block|}
comment|/// getRegMaskSlotsInBlock - Returns a sorted array of slot indices of all
comment|/// instructions with register mask operands in the basic block numbered
comment|/// MBBNum.
name|ArrayRef
operator|<
name|SlotIndex
operator|>
name|getRegMaskSlotsInBlock
argument_list|(
argument|unsigned MBBNum
argument_list|)
specifier|const
block|{
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
name|unsigned
operator|>
name|P
operator|=
name|RegMaskBlocks
index|[
name|MBBNum
index|]
block|;
return|return
name|getRegMaskSlots
argument_list|()
operator|.
name|slice
argument_list|(
name|P
operator|.
name|first
argument_list|,
name|P
operator|.
name|second
argument_list|)
return|;
block|}
comment|/// getRegMaskBits() - Returns an array of register mask pointers
comment|/// corresponding to getRegMaskSlots().
name|ArrayRef
operator|<
specifier|const
name|uint32_t
operator|*
operator|>
name|getRegMaskBits
argument_list|()
specifier|const
block|{
return|return
name|RegMaskBits
return|;
block|}
comment|/// getRegMaskBitsInBlock - Returns an array of mask pointers corresponding
comment|/// to getRegMaskSlotsInBlock(MBBNum).
name|ArrayRef
operator|<
specifier|const
name|uint32_t
operator|*
operator|>
name|getRegMaskBitsInBlock
argument_list|(
argument|unsigned MBBNum
argument_list|)
specifier|const
block|{
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
name|unsigned
operator|>
name|P
operator|=
name|RegMaskBlocks
index|[
name|MBBNum
index|]
block|;
return|return
name|getRegMaskBits
argument_list|()
operator|.
name|slice
argument_list|(
name|P
operator|.
name|first
argument_list|,
name|P
operator|.
name|second
argument_list|)
return|;
block|}
comment|/// checkRegMaskInterference - Test if LI is live across any register mask
comment|/// instructions, and compute a bit mask of physical registers that are not
comment|/// clobbered by any of them.
comment|///
comment|/// Returns false if LI doesn't cross any register mask instructions. In
comment|/// that case, the bit vector is not filled in.
name|bool
name|checkRegMaskInterference
argument_list|(
name|LiveInterval
operator|&
name|LI
argument_list|,
name|BitVector
operator|&
name|UsableRegs
argument_list|)
block|;
comment|// Register unit functions.
comment|//
comment|// Fixed interference occurs when MachineInstrs use physregs directly
comment|// instead of virtual registers. This typically happens when passing
comment|// arguments to a function call, or when instructions require operands in
comment|// fixed registers.
comment|//
comment|// Each physreg has one or more register units, see MCRegisterInfo. We
comment|// track liveness per register unit to handle aliasing registers more
comment|// efficiently.
comment|/// getRegUnit - Return the live range for Unit.
comment|/// It will be computed if it doesn't exist.
name|LiveRange
operator|&
name|getRegUnit
argument_list|(
argument|unsigned Unit
argument_list|)
block|{
name|LiveRange
operator|*
name|LR
operator|=
name|RegUnitRanges
index|[
name|Unit
index|]
block|;
if|if
condition|(
operator|!
name|LR
condition|)
block|{
comment|// Compute missing ranges on demand.
name|RegUnitRanges
index|[
name|Unit
index|]
operator|=
name|LR
operator|=
name|new
name|LiveRange
argument_list|()
expr_stmt|;
name|computeRegUnitRange
argument_list|(
operator|*
name|LR
argument_list|,
name|Unit
argument_list|)
expr_stmt|;
block|}
return|return
operator|*
name|LR
return|;
block|}
comment|/// getCachedRegUnit - Return the live range for Unit if it has already
comment|/// been computed, or NULL if it hasn't been computed yet.
name|LiveRange
operator|*
name|getCachedRegUnit
argument_list|(
argument|unsigned Unit
argument_list|)
block|{
return|return
name|RegUnitRanges
index|[
name|Unit
index|]
return|;
block|}
specifier|const
name|LiveRange
operator|*
name|getCachedRegUnit
argument_list|(
argument|unsigned Unit
argument_list|)
specifier|const
block|{
return|return
name|RegUnitRanges
index|[
name|Unit
index|]
return|;
block|}
name|private
operator|:
comment|/// Compute live intervals for all virtual registers.
name|void
name|computeVirtRegs
argument_list|()
block|;
comment|/// Compute RegMaskSlots and RegMaskBits.
name|void
name|computeRegMasks
argument_list|()
block|;
specifier|static
name|LiveInterval
operator|*
name|createInterval
argument_list|(
argument|unsigned Reg
argument_list|)
block|;
name|void
name|printInstrs
argument_list|(
argument|raw_ostream&O
argument_list|)
specifier|const
block|;
name|void
name|dumpInstrs
argument_list|()
specifier|const
block|;
name|void
name|computeLiveInRegUnits
argument_list|()
block|;
name|void
name|computeRegUnitRange
argument_list|(
argument|LiveRange&
argument_list|,
argument|unsigned Unit
argument_list|)
block|;
name|void
name|computeVirtRegInterval
argument_list|(
name|LiveInterval
operator|&
argument_list|)
block|;
name|class
name|HMEditor
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

