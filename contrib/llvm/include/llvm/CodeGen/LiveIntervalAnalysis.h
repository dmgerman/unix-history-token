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
comment|/// \file This file implements the LiveInterval analysis pass.  Given some
end_comment

begin_comment
comment|/// numbering of each the machine instructions (in this implemention depth-first
end_comment

begin_comment
comment|/// order) an interval [i, j) is said to be a live interval for register v if
end_comment

begin_comment
comment|/// there is no instruction with number j'> j such that v is live at j' and
end_comment

begin_comment
comment|/// there is no instruction with number i'< i such that v is live at i'. In
end_comment

begin_comment
comment|/// this implementation intervals can have holes, i.e. an interval might look
end_comment

begin_comment
comment|/// like [1,20), [50,65), [1000,1001).
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
name|LLVM_CODEGEN_LIVEINTERVALANALYSIS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_LIVEINTERVALANALYSIS_H
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
file|"llvm/Analysis/AliasAnalysis.h"
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
file|"llvm/Support/CommandLine.h"
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

begin_decl_stmt
name|namespace
name|llvm
block|{
extern|extern cl::opt<bool> UseSegmentSetForPhysRegs;
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
name|MachineBlockFrequencyInfo
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
comment|/// Sorted list of instructions with register mask operands. Always use the
comment|/// 'r' slot, RegMasks are normal clobbers, not early clobbers.
name|SmallVector
operator|<
name|SlotIndex
block|,
literal|8
operator|>
name|RegMaskSlots
block|;
comment|/// This vector is parallel to RegMaskSlots, it holds a pointer to the
comment|/// corresponding register mask.  This pointer can be recomputed as:
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
name|LiveIntervals
argument_list|()
block|;
operator|~
name|LiveIntervals
argument_list|()
name|override
block|;
comment|/// Calculate the spill weight to assign to a single instruction.
specifier|static
name|float
name|getSpillWeight
argument_list|(
argument|bool isDef
argument_list|,
argument|bool isUse
argument_list|,
argument|const MachineBlockFrequencyInfo *MBFI
argument_list|,
argument|const MachineInstr&Instr
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
comment|/// Interval creation.
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
comment|/// Interval removal.
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
name|nullptr
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
argument|MachineInstr&startInst
argument_list|)
block|;
comment|/// After removing some uses of a register, shrink its live range to just
comment|/// the remaining uses. This method does not compute reaching defs for new
comment|/// uses, and it doesn't remove dead defs.
comment|/// Dead PHIDef values are marked as unused. New dead machine instructions
comment|/// are added to the dead vector. Returns true if the interval may have been
comment|/// separated into multiple connected components.
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
name|nullptr
argument_list|)
block|;
comment|/// Specialized version of
comment|/// shrinkToUses(LiveInterval *li, SmallVectorImpl<MachineInstr*> *dead)
comment|/// that works on a subregister live range and only looks at uses matching
comment|/// the lane mask of the subregister range.
comment|/// This may leave the subrange empty which needs to be cleaned up with
comment|/// LiveInterval::removeEmptySubranges() afterwards.
name|void
name|shrinkToUses
argument_list|(
argument|LiveInterval::SubRange&SR
argument_list|,
argument|unsigned Reg
argument_list|)
block|;
comment|/// Extend the live range \p LR to reach all points in \p Indices. The
comment|/// points in the \p Indices array must be jointly dominated by the union
comment|/// of the existing defs in \p LR and points in \p Undefs.
comment|///
comment|/// PHI-defs are added as needed to maintain SSA form.
comment|///
comment|/// If a SlotIndex in \p Indices is the end index of a basic block, \p LR
comment|/// will be extended to be live out of the basic block.
comment|/// If a SlotIndex in \p Indices is jointy dominated only by points in
comment|/// \p Undefs, the live range will not be extended to that point.
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
argument_list|,
name|ArrayRef
operator|<
name|SlotIndex
operator|>
name|Undefs
argument_list|)
block|;
name|void
name|extendToIndices
argument_list|(
argument|LiveRange&LR
argument_list|,
argument|ArrayRef<SlotIndex> Indices
argument_list|)
block|{
name|extendToIndices
argument_list|(
name|LR
argument_list|,
name|Indices
argument_list|,
comment|/*Undefs=*/
block|{
block|}
block|)
block|;     }
comment|/// If \p LR has a live value at \p Kill, prune its live range by removing
comment|/// any liveness reachable from Kill. Add live range end points to
comment|/// EndPoints such that extendToIndices(LI, EndPoints) will reconstruct the
comment|/// value's live range.
comment|///
comment|/// Calling pruneValue() and extendToIndices() can be used to reconstruct
comment|/// SSA form after adding defs to a virtual register.
name|void
name|pruneValue
argument_list|(
argument|LiveRange&LR
argument_list|,
argument|SlotIndex Kill
argument_list|,
argument|SmallVectorImpl<SlotIndex> *EndPoints
argument_list|)
decl_stmt|;
comment|/// This function should not be used. Its intend is to tell you that
comment|/// you are doing something wrong if you call pruveValue directly on a
comment|/// LiveInterval. Indeed, you are supposed to call pruneValue on the main
comment|/// LiveRange and all the LiveRange of the subranges if any.
name|LLVM_ATTRIBUTE_UNUSED
name|void
name|pruneValue
argument_list|(
name|LiveInterval
operator|&
argument_list|,
name|SlotIndex
argument_list|,
name|SmallVectorImpl
operator|<
name|SlotIndex
operator|>
operator|*
argument_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"Use pruneValue on the main LiveRange and on each subrange"
argument_list|)
expr_stmt|;
block|}
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
comment|/// Returns true if the specified machine instr has been removed or was
comment|/// never entered in the map.
name|bool
name|isNotInMIMap
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|Instr
argument_list|)
decl|const
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
specifier|const
name|MachineInstr
operator|&
name|Instr
argument_list|)
decl|const
block|{
return|return
name|Indexes
operator|->
name|getInstructionIndex
argument_list|(
name|Instr
argument_list|)
return|;
block|}
comment|/// Returns the instruction associated with the given index.
name|MachineInstr
modifier|*
name|getInstructionFromIndex
argument_list|(
name|SlotIndex
name|index
argument_list|)
decl|const
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
specifier|const
name|MachineBasicBlock
operator|*
name|mbb
argument_list|)
decl|const
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
specifier|const
name|MachineBasicBlock
operator|*
name|mbb
argument_list|)
decl|const
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
specifier|const
name|LiveRange
operator|&
name|LR
argument_list|,
specifier|const
name|MachineBasicBlock
operator|*
name|mbb
argument_list|)
decl|const
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
specifier|const
name|LiveRange
operator|&
name|LR
argument_list|,
specifier|const
name|MachineBasicBlock
operator|*
name|mbb
argument_list|)
decl|const
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
modifier|*
name|getMBBFromIndex
argument_list|(
name|SlotIndex
name|index
argument_list|)
decl|const
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
parameter_list|(
name|MachineBasicBlock
modifier|*
name|MBB
parameter_list|)
block|{
name|Indexes
operator|->
name|insertMBBInMaps
argument_list|(
name|MBB
argument_list|)
expr_stmt|;
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
expr_stmt|;
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
expr_stmt|;
block|}
name|SlotIndex
name|InsertMachineInstrInMaps
parameter_list|(
name|MachineInstr
modifier|&
name|MI
parameter_list|)
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
name|MachineBasicBlock
operator|::
name|iterator
name|B
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|E
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
operator|*
name|I
argument_list|)
expr_stmt|;
block|}
name|void
name|RemoveMachineInstrFromMaps
parameter_list|(
name|MachineInstr
modifier|&
name|MI
parameter_list|)
block|{
name|Indexes
operator|->
name|removeMachineInstrFromMaps
argument_list|(
name|MI
argument_list|)
expr_stmt|;
block|}
name|SlotIndex
name|ReplaceMachineInstrInMaps
parameter_list|(
name|MachineInstr
modifier|&
name|MI
parameter_list|,
name|MachineInstr
modifier|&
name|NewMI
parameter_list|)
block|{
return|return
name|Indexes
operator|->
name|replaceMachineInstrInMaps
argument_list|(
name|MI
argument_list|,
name|NewMI
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
name|void
name|getAnalysisUsage
argument_list|(
name|AnalysisUsage
operator|&
name|AU
argument_list|)
decl|const
name|override
decl_stmt|;
name|void
name|releaseMemory
argument_list|()
name|override
expr_stmt|;
comment|/// Pass entry point; Calculates LiveIntervals.
name|bool
name|runOnMachineFunction
argument_list|(
name|MachineFunction
operator|&
argument_list|)
name|override
decl_stmt|;
comment|/// Implement the dump method.
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|O
argument_list|,
specifier|const
name|Module
operator|*
operator|=
name|nullptr
argument_list|)
decl|const
name|override
decl_stmt|;
comment|/// If LI is confined to a single basic block, return a pointer to that
comment|/// block.  If LI is live in to or out of any block, return NULL.
name|MachineBasicBlock
modifier|*
name|intervalIsInOneMBB
argument_list|(
specifier|const
name|LiveInterval
operator|&
name|LI
argument_list|)
decl|const
decl_stmt|;
comment|/// Returns true if VNI is killed by any PHI-def values in LI.
comment|/// This may conservatively return true to avoid expensive computations.
name|bool
name|hasPHIKill
argument_list|(
specifier|const
name|LiveInterval
operator|&
name|LI
argument_list|,
specifier|const
name|VNInfo
operator|*
name|VNI
argument_list|)
decl|const
decl_stmt|;
comment|/// Add kill flags to any instruction that kills a virtual register.
name|void
name|addKillFlags
parameter_list|(
specifier|const
name|VirtRegMap
modifier|*
parameter_list|)
function_decl|;
comment|/// Call this method to notify LiveIntervals that instruction \p MI has been
comment|/// moved within a basic block. This will update the live intervals for all
comment|/// operands of \p MI. Moves between basic blocks are not supported.
comment|///
comment|/// \param UpdateFlags Update live intervals for nonallocatable physregs.
name|void
name|handleMove
parameter_list|(
name|MachineInstr
modifier|&
name|MI
parameter_list|,
name|bool
name|UpdateFlags
init|=
name|false
parameter_list|)
function_decl|;
comment|/// Update intervals for operands of \p MI so that they begin/end on the
comment|/// SlotIndex for \p BundleStart.
comment|///
comment|/// \param UpdateFlags Update live intervals for nonallocatable physregs.
comment|///
comment|/// Requires MI and BundleStart to have SlotIndexes, and assumes
comment|/// existing liveness is accurate. BundleStart should be the first
comment|/// instruction in the Bundle.
name|void
name|handleMoveIntoBundle
parameter_list|(
name|MachineInstr
modifier|&
name|MI
parameter_list|,
name|MachineInstr
modifier|&
name|BundleStart
parameter_list|,
name|bool
name|UpdateFlags
init|=
name|false
parameter_list|)
function_decl|;
comment|/// Update live intervals for instructions in a range of iterators. It is
comment|/// intended for use after target hooks that may insert or remove
comment|/// instructions, and is only efficient for a small number of instructions.
comment|///
comment|/// OrigRegs is a vector of registers that were originally used by the
comment|/// instructions in the range between the two iterators.
comment|///
comment|/// Currently, the only only changes that are supported are simple removal
comment|/// and addition of uses.
name|void
name|repairIntervalsInRange
argument_list|(
name|MachineBasicBlock
operator|*
name|MBB
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|Begin
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|End
argument_list|,
name|ArrayRef
operator|<
name|unsigned
operator|>
name|OrigRegs
argument_list|)
decl_stmt|;
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
comment|/// Returns a sorted array of slot indices of all instructions with
comment|/// register mask operands.
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
comment|/// Returns a sorted array of slot indices of all instructions with register
comment|/// mask operands in the basic block numbered \p MBBNum.
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
comment|/// Returns an array of register mask pointers corresponding to
comment|/// getRegMaskSlots().
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
comment|/// Returns an array of mask pointers corresponding to
comment|/// getRegMaskSlotsInBlock(MBBNum).
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
comment|/// Test if \p LI is live across any register mask instructions, and
comment|/// compute a bit mask of physical registers that are not clobbered by any
comment|/// of them.
comment|///
comment|/// Returns false if \p LI doesn't cross any register mask instructions. In
comment|/// that case, the bit vector is not filled in.
name|bool
name|checkRegMaskInterference
parameter_list|(
name|LiveInterval
modifier|&
name|LI
parameter_list|,
name|BitVector
modifier|&
name|UsableRegs
parameter_list|)
function_decl|;
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
comment|/// Return the live range for register unit \p Unit. It will be computed if
comment|/// it doesn't exist.
name|LiveRange
modifier|&
name|getRegUnit
parameter_list|(
name|unsigned
name|Unit
parameter_list|)
block|{
name|LiveRange
modifier|*
name|LR
init|=
name|RegUnitRanges
index|[
name|Unit
index|]
decl_stmt|;
if|if
condition|(
operator|!
name|LR
condition|)
block|{
comment|// Compute missing ranges on demand.
comment|// Use segment set to speed-up initial computation of the live range.
name|RegUnitRanges
index|[
name|Unit
index|]
operator|=
name|LR
operator|=
name|new
name|LiveRange
argument_list|(
name|UseSegmentSetForPhysRegs
argument_list|)
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
comment|/// Return the live range for register unit \p Unit if it has already been
comment|/// computed, or nullptr if it hasn't been computed yet.
name|LiveRange
modifier|*
name|getCachedRegUnit
parameter_list|(
name|unsigned
name|Unit
parameter_list|)
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
modifier|*
name|getCachedRegUnit
argument_list|(
name|unsigned
name|Unit
argument_list|)
decl|const
block|{
return|return
name|RegUnitRanges
index|[
name|Unit
index|]
return|;
block|}
comment|/// Remove computed live range for register unit \p Unit. Subsequent uses
comment|/// should rely on on-demand recomputation.
name|void
name|removeRegUnit
parameter_list|(
name|unsigned
name|Unit
parameter_list|)
block|{
name|delete
name|RegUnitRanges
index|[
name|Unit
index|]
decl_stmt|;
name|RegUnitRanges
index|[
name|Unit
index|]
operator|=
name|nullptr
expr_stmt|;
block|}
comment|/// Remove value numbers and related live segments starting at position
comment|/// \p Pos that are part of any liverange of physical register \p Reg or one
comment|/// of its subregisters.
name|void
name|removePhysRegDefAt
parameter_list|(
name|unsigned
name|Reg
parameter_list|,
name|SlotIndex
name|Pos
parameter_list|)
function_decl|;
comment|/// Remove value number and related live segments of \p LI and its subranges
comment|/// that start at position \p Pos.
name|void
name|removeVRegDefAt
parameter_list|(
name|LiveInterval
modifier|&
name|LI
parameter_list|,
name|SlotIndex
name|Pos
parameter_list|)
function_decl|;
comment|/// Split separate components in LiveInterval \p LI into separate intervals.
name|void
name|splitSeparateComponents
argument_list|(
name|LiveInterval
operator|&
name|LI
argument_list|,
name|SmallVectorImpl
operator|<
name|LiveInterval
operator|*
operator|>
operator|&
name|SplitLIs
argument_list|)
decl_stmt|;
comment|/// For live interval \p LI with correct SubRanges construct matching
comment|/// information for the main live range. Expects the main live range to not
comment|/// have any segments or value numbers.
name|void
name|constructMainRangeFromSubranges
parameter_list|(
name|LiveInterval
modifier|&
name|LI
parameter_list|)
function_decl|;
name|private
label|:
comment|/// Compute live intervals for all virtual registers.
name|void
name|computeVirtRegs
parameter_list|()
function_decl|;
comment|/// Compute RegMaskSlots and RegMaskBits.
name|void
name|computeRegMasks
parameter_list|()
function_decl|;
comment|/// Walk the values in \p LI and check for dead values:
comment|/// - Dead PHIDef values are marked as unused.
comment|/// - Dead operands are marked as such.
comment|/// - Completely dead machine instructions are added to the \p dead vector
comment|///   if it is not nullptr.
comment|/// Returns true if any PHI value numbers have been removed which may
comment|/// have separated the interval into multiple connected components.
name|bool
name|computeDeadValues
argument_list|(
name|LiveInterval
operator|&
name|LI
argument_list|,
name|SmallVectorImpl
operator|<
name|MachineInstr
operator|*
operator|>
operator|*
name|dead
argument_list|)
decl_stmt|;
specifier|static
name|LiveInterval
modifier|*
name|createInterval
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
function_decl|;
name|void
name|printInstrs
argument_list|(
name|raw_ostream
operator|&
name|O
argument_list|)
decl|const
decl_stmt|;
name|void
name|dumpInstrs
argument_list|()
specifier|const
expr_stmt|;
name|void
name|computeLiveInRegUnits
parameter_list|()
function_decl|;
name|void
name|computeRegUnitRange
parameter_list|(
name|LiveRange
modifier|&
parameter_list|,
name|unsigned
name|Unit
parameter_list|)
function_decl|;
name|void
name|computeVirtRegInterval
parameter_list|(
name|LiveInterval
modifier|&
parameter_list|)
function_decl|;
comment|/// Helper function for repairIntervalsInRange(), walks backwards and
comment|/// creates/modifies live segments in \p LR to match the operands found.
comment|/// Only full operands or operands with subregisters matching \p LaneMask
comment|/// are considered.
name|void
name|repairOldRegInRange
argument_list|(
name|MachineBasicBlock
operator|::
name|iterator
name|Begin
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|End
argument_list|,
specifier|const
name|SlotIndex
name|endIdx
argument_list|,
name|LiveRange
operator|&
name|LR
argument_list|,
name|unsigned
name|Reg
argument_list|,
name|LaneBitmask
name|LaneMask
operator|=
name|LaneBitmask
operator|::
name|getAll
argument_list|()
argument_list|)
decl_stmt|;
name|class
name|HMEditor
decl_stmt|;
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

