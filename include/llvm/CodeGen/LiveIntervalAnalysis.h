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
file|"llvm/CodeGen/LiveInterval.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SlotIndexes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/BitVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

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
file|"llvm/Support/Allocator.h"
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
name|LiveVariables
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
name|mf_
block|;
name|MachineRegisterInfo
operator|*
name|mri_
block|;
specifier|const
name|TargetMachine
operator|*
name|tm_
block|;
specifier|const
name|TargetRegisterInfo
operator|*
name|tri_
block|;
specifier|const
name|TargetInstrInfo
operator|*
name|tii_
block|;
name|AliasAnalysis
operator|*
name|aa_
block|;
name|LiveVariables
operator|*
name|lv_
block|;
name|SlotIndexes
operator|*
name|indexes_
block|;
comment|/// Special pool allocator for VNInfo's (LiveInterval val#).
comment|///
name|VNInfo
operator|::
name|Allocator
name|VNInfoAllocator
block|;
typedef|typedef
name|DenseMap
operator|<
name|unsigned
operator|,
name|LiveInterval
operator|*
operator|>
name|Reg2IntervalMap
expr_stmt|;
name|Reg2IntervalMap
name|r2iMap_
decl_stmt|;
comment|/// allocatableRegs_ - A bit vector of allocatable registers.
name|BitVector
name|allocatableRegs_
decl_stmt|;
comment|/// reservedRegs_ - A bit vector of reserved registers.
name|BitVector
name|reservedRegs_
decl_stmt|;
comment|/// RegMaskSlots - Sorted list of instructions with register mask operands.
comment|/// Always use the 'r' slot, RegMasks are normal clobbers, not early
comment|/// clobbers.
name|SmallVector
operator|<
name|SlotIndex
operator|,
literal|8
operator|>
name|RegMaskSlots
expr_stmt|;
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
operator|,
literal|8
operator|>
name|RegMaskBits
expr_stmt|;
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
operator|,
name|unsigned
operator|>
operator|,
literal|8
operator|>
name|RegMaskBlocks
expr_stmt|;
name|public
label|:
specifier|static
name|char
name|ID
decl_stmt|;
comment|// Pass identification, replacement for typeid
name|LiveIntervals
argument_list|()
operator|:
name|MachineFunctionPass
argument_list|(
argument|ID
argument_list|)
block|{
name|initializeLiveIntervalsPass
argument_list|(
operator|*
name|PassRegistry
operator|::
name|getPassRegistry
argument_list|()
argument_list|)
block|;     }
comment|// Calculate the spill weight to assign to a single instruction.
specifier|static
name|float
name|getSpillWeight
argument_list|(
argument|bool isDef
argument_list|,
argument|bool isUse
argument_list|,
argument|unsigned loopDepth
argument_list|)
expr_stmt|;
typedef|typedef
name|Reg2IntervalMap
operator|::
name|iterator
name|iterator
expr_stmt|;
typedef|typedef
name|Reg2IntervalMap
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|r2iMap_
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|r2iMap_
operator|.
name|end
argument_list|()
return|;
block|}
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|r2iMap_
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|end
parameter_list|()
block|{
return|return
name|r2iMap_
operator|.
name|end
argument_list|()
return|;
block|}
name|unsigned
name|getNumIntervals
argument_list|()
specifier|const
block|{
return|return
operator|(
name|unsigned
operator|)
name|r2iMap_
operator|.
name|size
argument_list|()
return|;
block|}
name|LiveInterval
modifier|&
name|getInterval
parameter_list|(
name|unsigned
name|reg
parameter_list|)
block|{
name|Reg2IntervalMap
operator|::
name|iterator
name|I
operator|=
name|r2iMap_
operator|.
name|find
argument_list|(
name|reg
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|I
operator|!=
name|r2iMap_
operator|.
name|end
argument_list|()
operator|&&
literal|"Interval does not exist for register"
argument_list|)
expr_stmt|;
return|return
operator|*
name|I
operator|->
name|second
return|;
block|}
specifier|const
name|LiveInterval
modifier|&
name|getInterval
argument_list|(
name|unsigned
name|reg
argument_list|)
decl|const
block|{
name|Reg2IntervalMap
operator|::
name|const_iterator
name|I
operator|=
name|r2iMap_
operator|.
name|find
argument_list|(
name|reg
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|I
operator|!=
name|r2iMap_
operator|.
name|end
argument_list|()
operator|&&
literal|"Interval does not exist for register"
argument_list|)
expr_stmt|;
return|return
operator|*
name|I
operator|->
name|second
return|;
block|}
name|bool
name|hasInterval
argument_list|(
name|unsigned
name|reg
argument_list|)
decl|const
block|{
return|return
name|r2iMap_
operator|.
name|count
argument_list|(
name|reg
argument_list|)
return|;
block|}
comment|/// isAllocatable - is the physical register reg allocatable in the current
comment|/// function?
name|bool
name|isAllocatable
argument_list|(
name|unsigned
name|reg
argument_list|)
decl|const
block|{
return|return
name|allocatableRegs_
operator|.
name|test
argument_list|(
name|reg
argument_list|)
return|;
block|}
comment|/// isReserved - is the physical register reg reserved in the current
comment|/// function
name|bool
name|isReserved
argument_list|(
name|unsigned
name|reg
argument_list|)
decl|const
block|{
return|return
name|reservedRegs_
operator|.
name|test
argument_list|(
name|reg
argument_list|)
return|;
block|}
comment|/// getScaledIntervalSize - get the size of an interval in "units,"
comment|/// where every function is composed of one thousand units.  This
comment|/// measure scales properly with empty index slots in the function.
name|double
name|getScaledIntervalSize
parameter_list|(
name|LiveInterval
modifier|&
name|I
parameter_list|)
block|{
return|return
operator|(
literal|1000.0
operator|*
name|I
operator|.
name|getSize
argument_list|()
operator|)
operator|/
name|indexes_
operator|->
name|getIndexesLength
argument_list|()
return|;
block|}
comment|/// getFuncInstructionCount - Return the number of instructions in the
comment|/// current function.
name|unsigned
name|getFuncInstructionCount
parameter_list|()
block|{
return|return
name|indexes_
operator|->
name|getFunctionSize
argument_list|()
return|;
block|}
comment|/// getApproximateInstructionCount - computes an estimate of the number
comment|/// of instructions in a given LiveInterval.
name|unsigned
name|getApproximateInstructionCount
parameter_list|(
name|LiveInterval
modifier|&
name|I
parameter_list|)
block|{
name|double
name|IntervalPercentage
init|=
name|getScaledIntervalSize
argument_list|(
name|I
argument_list|)
operator|/
literal|1000.0
decl_stmt|;
return|return
call|(
name|unsigned
call|)
argument_list|(
name|IntervalPercentage
operator|*
name|indexes_
operator|->
name|getFunctionSize
argument_list|()
argument_list|)
return|;
block|}
comment|// Interval creation
name|LiveInterval
modifier|&
name|getOrCreateInterval
parameter_list|(
name|unsigned
name|reg
parameter_list|)
block|{
name|Reg2IntervalMap
operator|::
name|iterator
name|I
operator|=
name|r2iMap_
operator|.
name|find
argument_list|(
name|reg
argument_list|)
expr_stmt|;
if|if
condition|(
name|I
operator|==
name|r2iMap_
operator|.
name|end
argument_list|()
condition|)
name|I
operator|=
name|r2iMap_
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|reg
argument_list|,
name|createInterval
argument_list|(
name|reg
argument_list|)
argument_list|)
argument_list|)
operator|.
name|first
expr_stmt|;
return|return
operator|*
name|I
operator|->
name|second
return|;
block|}
comment|/// dupInterval - Duplicate a live interval. The caller is responsible for
comment|/// managing the allocated memory.
name|LiveInterval
modifier|*
name|dupInterval
parameter_list|(
name|LiveInterval
modifier|*
name|li
parameter_list|)
function_decl|;
comment|/// addLiveRangeToEndOfBlock - Given a register and an instruction,
comment|/// adds a live range from that instruction to the end of its MBB.
name|LiveRange
name|addLiveRangeToEndOfBlock
parameter_list|(
name|unsigned
name|reg
parameter_list|,
name|MachineInstr
modifier|*
name|startInst
parameter_list|)
function_decl|;
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
decl_stmt|;
comment|// Interval removal
name|void
name|removeInterval
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
block|{
name|DenseMap
operator|<
name|unsigned
operator|,
name|LiveInterval
operator|*
operator|>
operator|::
name|iterator
name|I
operator|=
name|r2iMap_
operator|.
name|find
argument_list|(
name|Reg
argument_list|)
expr_stmt|;
name|delete
name|I
operator|->
name|second
decl_stmt|;
name|r2iMap_
operator|.
name|erase
argument_list|(
name|I
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
name|indexes_
return|;
block|}
comment|/// isNotInMIMap - returns true if the specified machine instr has been
comment|/// removed or was never entered in the map.
name|bool
name|isNotInMIMap
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|Instr
argument_list|)
decl|const
block|{
return|return
operator|!
name|indexes_
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
operator|*
name|instr
argument_list|)
decl|const
block|{
return|return
name|indexes_
operator|->
name|getInstructionIndex
argument_list|(
name|instr
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
name|indexes_
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
name|indexes_
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
name|indexes_
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
name|LiveInterval
operator|&
name|li
argument_list|,
specifier|const
name|MachineBasicBlock
operator|*
name|mbb
argument_list|)
decl|const
block|{
return|return
name|li
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
name|LiveInterval
operator|&
name|li
argument_list|,
specifier|const
name|MachineBasicBlock
operator|*
name|mbb
argument_list|)
decl|const
block|{
return|return
name|li
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
name|indexes_
operator|->
name|getMBBFromIndex
argument_list|(
name|index
argument_list|)
return|;
block|}
name|SlotIndex
name|InsertMachineInstrInMaps
parameter_list|(
name|MachineInstr
modifier|*
name|MI
parameter_list|)
block|{
return|return
name|indexes_
operator|->
name|insertMachineInstrInMaps
argument_list|(
name|MI
argument_list|)
return|;
block|}
name|void
name|RemoveMachineInstrFromMaps
parameter_list|(
name|MachineInstr
modifier|*
name|MI
parameter_list|)
block|{
name|indexes_
operator|->
name|removeMachineInstrFromMaps
argument_list|(
name|MI
argument_list|)
expr_stmt|;
block|}
name|void
name|ReplaceMachineInstrInMaps
parameter_list|(
name|MachineInstr
modifier|*
name|MI
parameter_list|,
name|MachineInstr
modifier|*
name|NewMI
parameter_list|)
block|{
name|indexes_
operator|->
name|replaceMachineInstrInMaps
argument_list|(
name|MI
argument_list|,
name|NewMI
argument_list|)
expr_stmt|;
block|}
name|bool
name|findLiveInMBBs
argument_list|(
name|SlotIndex
name|Start
argument_list|,
name|SlotIndex
name|End
argument_list|,
name|SmallVectorImpl
operator|<
name|MachineBasicBlock
operator|*
operator|>
operator|&
name|MBBs
argument_list|)
decl|const
block|{
return|return
name|indexes_
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
name|AnalysisUsage
operator|&
name|AU
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|void
name|releaseMemory
parameter_list|()
function_decl|;
comment|/// runOnMachineFunction - pass entry point
name|virtual
name|bool
name|runOnMachineFunction
parameter_list|(
name|MachineFunction
modifier|&
parameter_list|)
function_decl|;
comment|/// print - Implement the dump method.
name|virtual
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
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// isReMaterializable - Returns true if every definition of MI of every
comment|/// val# of the specified interval is re-materializable. Also returns true
comment|/// by reference if all of the defs are load instructions.
name|bool
name|isReMaterializable
argument_list|(
specifier|const
name|LiveInterval
operator|&
name|li
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|LiveInterval
operator|*
operator|>
operator|*
name|SpillIs
argument_list|,
name|bool
operator|&
name|isLoad
argument_list|)
decl_stmt|;
comment|/// intervalIsInOneMBB - If LI is confined to a single basic block, return
comment|/// a pointer to that block.  If LI is live in to or out of any block,
comment|/// return NULL.
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
comment|/// addKillFlags - Add kill flags to any instruction that kills a virtual
comment|/// register.
name|void
name|addKillFlags
parameter_list|()
function_decl|;
comment|/// handleMove - call this method to notify LiveIntervals that
comment|/// instruction 'mi' has been moved within a basic block. This will update
comment|/// the live intervals for all operands of mi. Moves between basic blocks
comment|/// are not supported.
name|void
name|handleMove
parameter_list|(
name|MachineInstr
modifier|*
name|MI
parameter_list|)
function_decl|;
comment|/// moveIntoBundle - Update intervals for operands of MI so that they
comment|/// begin/end on the SlotIndex for BundleStart.
comment|///
comment|/// Requires MI and BundleStart to have SlotIndexes, and assumes
comment|/// existing liveness is accurate. BundleStart should be the first
comment|/// instruction in the Bundle.
name|void
name|handleMoveIntoBundle
parameter_list|(
name|MachineInstr
modifier|*
name|MI
parameter_list|,
name|MachineInstr
modifier|*
name|BundleStart
parameter_list|)
function_decl|;
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
name|private
label|:
comment|/// computeIntervals - Compute live intervals.
name|void
name|computeIntervals
parameter_list|()
function_decl|;
comment|/// handleRegisterDef - update intervals for a register def
comment|/// (calls handlePhysicalRegisterDef and
comment|/// handleVirtualRegisterDef)
name|void
name|handleRegisterDef
argument_list|(
name|MachineBasicBlock
operator|*
name|MBB
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|MI
argument_list|,
name|SlotIndex
name|MIIdx
argument_list|,
name|MachineOperand
operator|&
name|MO
argument_list|,
name|unsigned
name|MOIdx
argument_list|)
decl_stmt|;
comment|/// isPartialRedef - Return true if the specified def at the specific index
comment|/// is partially re-defining the specified live interval. A common case of
comment|/// this is a definition of the sub-register.
name|bool
name|isPartialRedef
parameter_list|(
name|SlotIndex
name|MIIdx
parameter_list|,
name|MachineOperand
modifier|&
name|MO
parameter_list|,
name|LiveInterval
modifier|&
name|interval
parameter_list|)
function_decl|;
comment|/// handleVirtualRegisterDef - update intervals for a virtual
comment|/// register def
name|void
name|handleVirtualRegisterDef
argument_list|(
name|MachineBasicBlock
operator|*
name|MBB
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|MI
argument_list|,
name|SlotIndex
name|MIIdx
argument_list|,
name|MachineOperand
operator|&
name|MO
argument_list|,
name|unsigned
name|MOIdx
argument_list|,
name|LiveInterval
operator|&
name|interval
argument_list|)
decl_stmt|;
comment|/// handlePhysicalRegisterDef - update intervals for a physical register
comment|/// def.
name|void
name|handlePhysicalRegisterDef
argument_list|(
name|MachineBasicBlock
operator|*
name|mbb
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|mi
argument_list|,
name|SlotIndex
name|MIIdx
argument_list|,
name|MachineOperand
operator|&
name|MO
argument_list|,
name|LiveInterval
operator|&
name|interval
argument_list|)
decl_stmt|;
comment|/// handleLiveInRegister - Create interval for a livein register.
name|void
name|handleLiveInRegister
parameter_list|(
name|MachineBasicBlock
modifier|*
name|mbb
parameter_list|,
name|SlotIndex
name|MIIdx
parameter_list|,
name|LiveInterval
modifier|&
name|interval
parameter_list|)
function_decl|;
comment|/// getReMatImplicitUse - If the remat definition MI has one (for now, we
comment|/// only allow one) virtual register operand, then its uses are implicitly
comment|/// using the register. Returns the virtual register.
name|unsigned
name|getReMatImplicitUse
argument_list|(
specifier|const
name|LiveInterval
operator|&
name|li
argument_list|,
name|MachineInstr
operator|*
name|MI
argument_list|)
decl|const
decl_stmt|;
comment|/// isValNoAvailableAt - Return true if the val# of the specified interval
comment|/// which reaches the given instruction also reaches the specified use
comment|/// index.
name|bool
name|isValNoAvailableAt
argument_list|(
specifier|const
name|LiveInterval
operator|&
name|li
argument_list|,
name|MachineInstr
operator|*
name|MI
argument_list|,
name|SlotIndex
name|UseIdx
argument_list|)
decl|const
decl_stmt|;
comment|/// isReMaterializable - Returns true if the definition MI of the specified
comment|/// val# of the specified interval is re-materializable. Also returns true
comment|/// by reference if the def is a load.
name|bool
name|isReMaterializable
argument_list|(
specifier|const
name|LiveInterval
operator|&
name|li
argument_list|,
specifier|const
name|VNInfo
operator|*
name|ValNo
argument_list|,
name|MachineInstr
operator|*
name|MI
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|LiveInterval
operator|*
operator|>
operator|*
name|SpillIs
argument_list|,
name|bool
operator|&
name|isLoad
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

