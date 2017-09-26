begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-------- SplitKit.h - Toolkit for splitting live ranges ----*- C++ -*-===//
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
comment|// This file contains the SplitAnalysis class as well as mutator functions for
end_comment

begin_comment
comment|// live range splitting.
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
name|LLVM_LIB_CODEGEN_SPLITKIT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_CODEGEN_SPLITKIT_H
end_define

begin_include
include|#
directive|include
file|"LiveRangeCalc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/IntervalMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ConnectedVNInfoEqClasses
decl_stmt|;
name|class
name|LiveInterval
decl_stmt|;
name|class
name|LiveIntervals
decl_stmt|;
name|class
name|LiveRangeEdit
decl_stmt|;
name|class
name|MachineBlockFrequencyInfo
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MachineLoopInfo
decl_stmt|;
name|class
name|MachineRegisterInfo
decl_stmt|;
name|class
name|TargetInstrInfo
decl_stmt|;
name|class
name|TargetRegisterInfo
decl_stmt|;
name|class
name|VirtRegMap
decl_stmt|;
name|class
name|VNInfo
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// Determines the latest safe point in a block in which we can insert a split,
comment|/// spill or other instruction related with CurLI.
name|class
name|LLVM_LIBRARY_VISIBILITY
name|InsertPointAnalysis
block|{
name|private
label|:
specifier|const
name|LiveIntervals
modifier|&
name|LIS
decl_stmt|;
comment|/// Last legal insert point in each basic block in the current function.
comment|/// The first entry is the first terminator, the second entry is the
comment|/// last valid point to insert a split or spill for a variable that is
comment|/// live into a landing pad successor.
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|SlotIndex
operator|,
name|SlotIndex
operator|>
operator|,
literal|8
operator|>
name|LastInsertPoint
expr_stmt|;
name|SlotIndex
name|computeLastInsertPoint
parameter_list|(
specifier|const
name|LiveInterval
modifier|&
name|CurLI
parameter_list|,
specifier|const
name|MachineBasicBlock
modifier|&
name|MBB
parameter_list|)
function_decl|;
name|public
label|:
name|InsertPointAnalysis
argument_list|(
argument|const LiveIntervals&lis
argument_list|,
argument|unsigned BBNum
argument_list|)
empty_stmt|;
comment|/// Return the base index of the last valid insert point for \pCurLI in \pMBB.
name|SlotIndex
name|getLastInsertPoint
parameter_list|(
specifier|const
name|LiveInterval
modifier|&
name|CurLI
parameter_list|,
specifier|const
name|MachineBasicBlock
modifier|&
name|MBB
parameter_list|)
block|{
name|unsigned
name|Num
init|=
name|MBB
operator|.
name|getNumber
argument_list|()
decl_stmt|;
comment|// Inline the common simple case.
if|if
condition|(
name|LastInsertPoint
index|[
name|Num
index|]
operator|.
name|first
operator|.
name|isValid
argument_list|()
operator|&&
operator|!
name|LastInsertPoint
index|[
name|Num
index|]
operator|.
name|second
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|LastInsertPoint
index|[
name|Num
index|]
operator|.
name|first
return|;
return|return
name|computeLastInsertPoint
argument_list|(
name|CurLI
argument_list|,
name|MBB
argument_list|)
return|;
block|}
comment|/// Returns the last insert point as an iterator for \pCurLI in \pMBB.
name|MachineBasicBlock
operator|::
name|iterator
name|getLastInsertPointIter
argument_list|(
specifier|const
name|LiveInterval
operator|&
name|CurLI
argument_list|,
name|MachineBasicBlock
operator|&
name|MBB
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
comment|/// SplitAnalysis - Analyze a LiveInterval, looking for live range splitting
comment|/// opportunities.
name|class
name|LLVM_LIBRARY_VISIBILITY
name|SplitAnalysis
block|{
name|public
label|:
specifier|const
name|MachineFunction
modifier|&
name|MF
decl_stmt|;
specifier|const
name|VirtRegMap
modifier|&
name|VRM
decl_stmt|;
specifier|const
name|LiveIntervals
modifier|&
name|LIS
decl_stmt|;
specifier|const
name|MachineLoopInfo
modifier|&
name|Loops
decl_stmt|;
specifier|const
name|TargetInstrInfo
modifier|&
name|TII
decl_stmt|;
comment|/// Additional information about basic blocks where the current variable is
comment|/// live. Such a block will look like one of these templates:
comment|///
comment|///  1. |   o---x   | Internal to block. Variable is only live in this block.
comment|///  2. |---x       | Live-in, kill.
comment|///  3. |       o---| Def, live-out.
comment|///  4. |---x   o---| Live-in, kill, def, live-out. Counted by NumGapBlocks.
comment|///  5. |---o---o---| Live-through with uses or defs.
comment|///  6. |-----------| Live-through without uses. Counted by NumThroughBlocks.
comment|///
comment|/// Two BlockInfo entries are created for template 4. One for the live-in
comment|/// segment, and one for the live-out segment. These entries look as if the
comment|/// block were split in the middle where the live range isn't live.
comment|///
comment|/// Live-through blocks without any uses don't get BlockInfo entries. They
comment|/// are simply listed in ThroughBlocks instead.
comment|///
struct|struct
name|BlockInfo
block|{
name|MachineBasicBlock
modifier|*
name|MBB
decl_stmt|;
name|SlotIndex
name|FirstInstr
decl_stmt|;
comment|///< First instr accessing current reg.
name|SlotIndex
name|LastInstr
decl_stmt|;
comment|///< Last instr accessing current reg.
name|SlotIndex
name|FirstDef
decl_stmt|;
comment|///< First non-phi valno->def, or SlotIndex().
name|bool
name|LiveIn
decl_stmt|;
comment|///< Current reg is live in.
name|bool
name|LiveOut
decl_stmt|;
comment|///< Current reg is live out.
comment|/// isOneInstr - Returns true when this BlockInfo describes a single
comment|/// instruction.
name|bool
name|isOneInstr
argument_list|()
specifier|const
block|{
return|return
name|SlotIndex
operator|::
name|isSameInstr
argument_list|(
name|FirstInstr
argument_list|,
name|LastInstr
argument_list|)
return|;
block|}
block|}
struct|;
name|private
label|:
comment|// Current live interval.
specifier|const
name|LiveInterval
modifier|*
name|CurLI
decl_stmt|;
comment|/// Insert Point Analysis.
name|InsertPointAnalysis
name|IPA
decl_stmt|;
comment|// Sorted slot indexes of using instructions.
name|SmallVector
operator|<
name|SlotIndex
operator|,
literal|8
operator|>
name|UseSlots
expr_stmt|;
comment|/// UseBlocks - Blocks where CurLI has uses.
name|SmallVector
operator|<
name|BlockInfo
operator|,
literal|8
operator|>
name|UseBlocks
expr_stmt|;
comment|/// NumGapBlocks - Number of duplicate entries in UseBlocks for blocks where
comment|/// the live range has a gap.
name|unsigned
name|NumGapBlocks
decl_stmt|;
comment|/// ThroughBlocks - Block numbers where CurLI is live through without uses.
name|BitVector
name|ThroughBlocks
decl_stmt|;
comment|/// NumThroughBlocks - Number of live-through blocks.
name|unsigned
name|NumThroughBlocks
decl_stmt|;
comment|/// DidRepairRange - analyze was forced to shrinkToUses().
name|bool
name|DidRepairRange
decl_stmt|;
comment|// Sumarize statistics by counting instructions using CurLI.
name|void
name|analyzeUses
parameter_list|()
function_decl|;
comment|/// calcLiveBlockInfo - Compute per-block information about CurLI.
name|bool
name|calcLiveBlockInfo
parameter_list|()
function_decl|;
name|public
label|:
name|SplitAnalysis
argument_list|(
specifier|const
name|VirtRegMap
operator|&
name|vrm
argument_list|,
specifier|const
name|LiveIntervals
operator|&
name|lis
argument_list|,
specifier|const
name|MachineLoopInfo
operator|&
name|mli
argument_list|)
expr_stmt|;
comment|/// analyze - set CurLI to the specified interval, and analyze how it may be
comment|/// split.
name|void
name|analyze
parameter_list|(
specifier|const
name|LiveInterval
modifier|*
name|li
parameter_list|)
function_decl|;
comment|/// didRepairRange() - Returns true if CurLI was invalid and has been repaired
comment|/// by analyze(). This really shouldn't happen, but sometimes the coalescer
comment|/// can create live ranges that end in mid-air.
name|bool
name|didRepairRange
argument_list|()
specifier|const
block|{
return|return
name|DidRepairRange
return|;
block|}
comment|/// clear - clear all data structures so SplitAnalysis is ready to analyze a
comment|/// new interval.
name|void
name|clear
parameter_list|()
function_decl|;
comment|/// getParent - Return the last analyzed interval.
specifier|const
name|LiveInterval
operator|&
name|getParent
argument_list|()
specifier|const
block|{
return|return
operator|*
name|CurLI
return|;
block|}
comment|/// isOriginalEndpoint - Return true if the original live range was killed or
comment|/// (re-)defined at Idx. Idx should be the 'def' slot for a normal kill/def,
comment|/// and 'use' for an early-clobber def.
comment|/// This can be used to recognize code inserted by earlier live range
comment|/// splitting.
name|bool
name|isOriginalEndpoint
argument_list|(
name|SlotIndex
name|Idx
argument_list|)
decl|const
decl_stmt|;
comment|/// getUseSlots - Return an array of SlotIndexes of instructions using CurLI.
comment|/// This include both use and def operands, at most one entry per instruction.
name|ArrayRef
operator|<
name|SlotIndex
operator|>
name|getUseSlots
argument_list|()
specifier|const
block|{
return|return
name|UseSlots
return|;
block|}
comment|/// getUseBlocks - Return an array of BlockInfo objects for the basic blocks
comment|/// where CurLI has uses.
name|ArrayRef
operator|<
name|BlockInfo
operator|>
name|getUseBlocks
argument_list|()
specifier|const
block|{
return|return
name|UseBlocks
return|;
block|}
comment|/// getNumThroughBlocks - Return the number of through blocks.
name|unsigned
name|getNumThroughBlocks
argument_list|()
specifier|const
block|{
return|return
name|NumThroughBlocks
return|;
block|}
comment|/// isThroughBlock - Return true if CurLI is live through MBB without uses.
name|bool
name|isThroughBlock
argument_list|(
name|unsigned
name|MBB
argument_list|)
decl|const
block|{
return|return
name|ThroughBlocks
operator|.
name|test
argument_list|(
name|MBB
argument_list|)
return|;
block|}
comment|/// getThroughBlocks - Return the set of through blocks.
specifier|const
name|BitVector
operator|&
name|getThroughBlocks
argument_list|()
specifier|const
block|{
return|return
name|ThroughBlocks
return|;
block|}
comment|/// getNumLiveBlocks - Return the number of blocks where CurLI is live.
name|unsigned
name|getNumLiveBlocks
argument_list|()
specifier|const
block|{
return|return
name|getUseBlocks
argument_list|()
operator|.
name|size
argument_list|()
operator|-
name|NumGapBlocks
operator|+
name|getNumThroughBlocks
argument_list|()
return|;
block|}
comment|/// countLiveBlocks - Return the number of blocks where li is live. This is
comment|/// guaranteed to return the same number as getNumLiveBlocks() after calling
comment|/// analyze(li).
name|unsigned
name|countLiveBlocks
argument_list|(
specifier|const
name|LiveInterval
operator|*
name|li
argument_list|)
decl|const
decl_stmt|;
typedef|typedef
name|SmallPtrSet
operator|<
specifier|const
name|MachineBasicBlock
operator|*
operator|,
literal|16
operator|>
name|BlockPtrSet
expr_stmt|;
comment|/// shouldSplitSingleBlock - Returns true if it would help to create a local
comment|/// live range for the instructions in BI. There is normally no benefit to
comment|/// creating a live range for a single instruction, but it does enable
comment|/// register class inflation if the instruction has a restricted register
comment|/// class.
comment|///
comment|/// @param BI           The block to be isolated.
comment|/// @param SingleInstrs True when single instructions should be isolated.
name|bool
name|shouldSplitSingleBlock
argument_list|(
specifier|const
name|BlockInfo
operator|&
name|BI
argument_list|,
name|bool
name|SingleInstrs
argument_list|)
decl|const
decl_stmt|;
name|SlotIndex
name|getLastSplitPoint
parameter_list|(
name|unsigned
name|Num
parameter_list|)
block|{
return|return
name|IPA
operator|.
name|getLastInsertPoint
argument_list|(
operator|*
name|CurLI
argument_list|,
operator|*
name|MF
operator|.
name|getBlockNumbered
argument_list|(
name|Num
argument_list|)
argument_list|)
return|;
block|}
name|MachineBasicBlock
operator|::
name|iterator
name|getLastSplitPointIter
argument_list|(
argument|MachineBasicBlock *BB
argument_list|)
block|{
return|return
name|IPA
operator|.
name|getLastInsertPointIter
argument_list|(
operator|*
name|CurLI
argument_list|,
operator|*
name|BB
argument_list|)
return|;
block|}
block|}
empty_stmt|;
comment|/// SplitEditor - Edit machine code and LiveIntervals for live range
comment|/// splitting.
comment|///
comment|/// - Create a SplitEditor from a SplitAnalysis.
comment|/// - Start a new live interval with openIntv.
comment|/// - Mark the places where the new interval is entered using enterIntv*
comment|/// - Mark the ranges where the new interval is used with useIntv*
comment|/// - Mark the places where the interval is exited with exitIntv*.
comment|/// - Finish the current interval with closeIntv and repeat from 2.
comment|/// - Rewrite instructions with finish().
comment|///
name|class
name|LLVM_LIBRARY_VISIBILITY
name|SplitEditor
block|{
name|SplitAnalysis
modifier|&
name|SA
decl_stmt|;
name|AliasAnalysis
modifier|&
name|AA
decl_stmt|;
name|LiveIntervals
modifier|&
name|LIS
decl_stmt|;
name|VirtRegMap
modifier|&
name|VRM
decl_stmt|;
name|MachineRegisterInfo
modifier|&
name|MRI
decl_stmt|;
name|MachineDominatorTree
modifier|&
name|MDT
decl_stmt|;
specifier|const
name|TargetInstrInfo
modifier|&
name|TII
decl_stmt|;
specifier|const
name|TargetRegisterInfo
modifier|&
name|TRI
decl_stmt|;
specifier|const
name|MachineBlockFrequencyInfo
modifier|&
name|MBFI
decl_stmt|;
name|public
label|:
comment|/// ComplementSpillMode - Select how the complement live range should be
comment|/// created.  SplitEditor automatically creates interval 0 to contain
comment|/// anything that isn't added to another interval.  This complement interval
comment|/// can get quite complicated, and it can sometimes be an advantage to allow
comment|/// it to overlap the other intervals.  If it is going to spill anyway, no
comment|/// registers are wasted by keeping a value in two places at the same time.
enum|enum
name|ComplementSpillMode
block|{
comment|/// SM_Partition(Default) - Try to create the complement interval so it
comment|/// doesn't overlap any other intervals, and the original interval is
comment|/// partitioned.  This may require a large number of back copies and extra
comment|/// PHI-defs.  Only segments marked with overlapIntv will be overlapping.
name|SM_Partition
block|,
comment|/// SM_Size - Overlap intervals to minimize the number of inserted COPY
comment|/// instructions.  Copies to the complement interval are hoisted to their
comment|/// common dominator, so only one COPY is required per value in the
comment|/// complement interval.  This also means that no extra PHI-defs need to be
comment|/// inserted in the complement interval.
name|SM_Size
block|,
comment|/// SM_Speed - Overlap intervals to minimize the expected execution
comment|/// frequency of the inserted copies.  This is very similar to SM_Size, but
comment|/// the complement interval may get some extra PHI-defs.
name|SM_Speed
block|}
enum|;
name|private
label|:
comment|/// Edit - The current parent register and new intervals created.
name|LiveRangeEdit
modifier|*
name|Edit
decl_stmt|;
comment|/// Index into Edit of the currently open interval.
comment|/// The index 0 is used for the complement, so the first interval started by
comment|/// openIntv will be 1.
name|unsigned
name|OpenIdx
decl_stmt|;
comment|/// The current spill mode, selected by reset().
name|ComplementSpillMode
name|SpillMode
decl_stmt|;
typedef|typedef
name|IntervalMap
operator|<
name|SlotIndex
operator|,
name|unsigned
operator|>
name|RegAssignMap
expr_stmt|;
comment|/// Allocator for the interval map. This will eventually be shared with
comment|/// SlotIndexes and LiveIntervals.
name|RegAssignMap
operator|::
name|Allocator
name|Allocator
expr_stmt|;
comment|/// RegAssign - Map of the assigned register indexes.
comment|/// Edit.get(RegAssign.lookup(Idx)) is the register that should be live at
comment|/// Idx.
name|RegAssignMap
name|RegAssign
decl_stmt|;
typedef|typedef
name|PointerIntPair
operator|<
name|VNInfo
operator|*
operator|,
literal|1
operator|>
name|ValueForcePair
expr_stmt|;
typedef|typedef
name|DenseMap
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
name|ValueForcePair
operator|>
name|ValueMap
expr_stmt|;
comment|/// Values - keep track of the mapping from parent values to values in the new
comment|/// intervals. Given a pair (RegIdx, ParentVNI->id), Values contains:
comment|///
comment|/// 1. No entry - the value is not mapped to Edit.get(RegIdx).
comment|/// 2. (Null, false) - the value is mapped to multiple values in
comment|///    Edit.get(RegIdx).  Each value is represented by a minimal live range at
comment|///    its def.  The full live range can be inferred exactly from the range
comment|///    of RegIdx in RegAssign.
comment|/// 3. (Null, true).  As above, but the ranges in RegAssign are too large, and
comment|///    the live range must be recomputed using LiveRangeCalc::extend().
comment|/// 4. (VNI, false) The value is mapped to a single new value.
comment|///    The new value has no live ranges anywhere.
name|ValueMap
name|Values
decl_stmt|;
comment|/// LRCalc - Cache for computing live ranges and SSA update.  Each instance
comment|/// can only handle non-overlapping live ranges, so use a separate
comment|/// LiveRangeCalc instance for the complement interval when in spill mode.
name|LiveRangeCalc
name|LRCalc
index|[
literal|2
index|]
decl_stmt|;
comment|/// getLRCalc - Return the LRCalc to use for RegIdx.  In spill mode, the
comment|/// complement interval can overlap the other intervals, so it gets its own
comment|/// LRCalc instance.  When not in spill mode, all intervals can share one.
name|LiveRangeCalc
modifier|&
name|getLRCalc
parameter_list|(
name|unsigned
name|RegIdx
parameter_list|)
block|{
return|return
name|LRCalc
index|[
name|SpillMode
operator|!=
name|SM_Partition
operator|&&
name|RegIdx
operator|!=
literal|0
index|]
return|;
block|}
comment|/// Find a subrange corresponding to the lane mask @p LM in the live
comment|/// interval @p LI. The interval @p LI is assumed to contain such a subrange.
comment|/// This function is used to find corresponding subranges between the
comment|/// original interval and the new intervals.
name|LiveInterval
operator|::
name|SubRange
operator|&
name|getSubRangeForMask
argument_list|(
argument|LaneBitmask LM
argument_list|,
argument|LiveInterval&LI
argument_list|)
expr_stmt|;
comment|/// Add a segment to the interval LI for the value number VNI. If LI has
comment|/// subranges, corresponding segments will be added to them as well, but
comment|/// with newly created value numbers. If Original is true, dead def will
comment|/// only be added a subrange of LI if the corresponding subrange of the
comment|/// original interval has a def at this index. Otherwise, all subranges
comment|/// of LI will be updated.
name|void
name|addDeadDef
parameter_list|(
name|LiveInterval
modifier|&
name|LI
parameter_list|,
name|VNInfo
modifier|*
name|VNI
parameter_list|,
name|bool
name|Original
parameter_list|)
function_decl|;
comment|/// defValue - define a value in RegIdx from ParentVNI at Idx.
comment|/// Idx does not have to be ParentVNI->def, but it must be contained within
comment|/// ParentVNI's live range in ParentLI. The new value is added to the value
comment|/// map. The value being defined may either come from rematerialization
comment|/// (or an inserted copy), or it may be coming from the original interval.
comment|/// The parameter Original should be true in the latter case, otherwise
comment|/// it should be false.
comment|/// Return the new LI value.
name|VNInfo
modifier|*
name|defValue
parameter_list|(
name|unsigned
name|RegIdx
parameter_list|,
specifier|const
name|VNInfo
modifier|*
name|ParentVNI
parameter_list|,
name|SlotIndex
name|Idx
parameter_list|,
name|bool
name|Original
parameter_list|)
function_decl|;
comment|/// forceRecompute - Force the live range of ParentVNI in RegIdx to be
comment|/// recomputed by LiveRangeCalc::extend regardless of the number of defs.
comment|/// This is used for values whose live range doesn't match RegAssign exactly.
comment|/// They could have rematerialized, or back-copies may have been moved.
name|void
name|forceRecompute
parameter_list|(
name|unsigned
name|RegIdx
parameter_list|,
specifier|const
name|VNInfo
modifier|*
name|ParentVNI
parameter_list|)
function_decl|;
comment|/// defFromParent - Define Reg from ParentVNI at UseIdx using either
comment|/// rematerialization or a COPY from parent. Return the new value.
name|VNInfo
modifier|*
name|defFromParent
argument_list|(
name|unsigned
name|RegIdx
argument_list|,
name|VNInfo
operator|*
name|ParentVNI
argument_list|,
name|SlotIndex
name|UseIdx
argument_list|,
name|MachineBasicBlock
operator|&
name|MBB
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|I
argument_list|)
decl_stmt|;
comment|/// removeBackCopies - Remove the copy instructions that defines the values
comment|/// in the vector in the complement interval.
name|void
name|removeBackCopies
argument_list|(
name|SmallVectorImpl
operator|<
name|VNInfo
operator|*
operator|>
operator|&
name|Copies
argument_list|)
decl_stmt|;
comment|/// getShallowDominator - Returns the least busy dominator of MBB that is
comment|/// also dominated by DefMBB.  Busy is measured by loop depth.
name|MachineBasicBlock
modifier|*
name|findShallowDominator
parameter_list|(
name|MachineBasicBlock
modifier|*
name|MBB
parameter_list|,
name|MachineBasicBlock
modifier|*
name|DefMBB
parameter_list|)
function_decl|;
comment|/// Find out all the backCopies dominated by others.
name|void
name|computeRedundantBackCopies
argument_list|(
name|DenseSet
operator|<
name|unsigned
operator|>
operator|&
name|NotToHoistSet
argument_list|,
name|SmallVectorImpl
operator|<
name|VNInfo
operator|*
operator|>
operator|&
name|BackCopies
argument_list|)
decl_stmt|;
comment|/// Hoist back-copies to the complement interval. It tries to hoist all
comment|/// the back-copies to one BB if it is beneficial, or else simply remove
comment|/// redundant backcopies dominated by others.
name|void
name|hoistCopies
parameter_list|()
function_decl|;
comment|/// transferValues - Transfer values to the new ranges.
comment|/// Return true if any ranges were skipped.
name|bool
name|transferValues
parameter_list|()
function_decl|;
comment|/// Live range @p LR corresponding to the lane Mask @p LM has a live
comment|/// PHI def at the beginning of block @p B. Extend the range @p LR of
comment|/// all predecessor values that reach this def. If @p LR is a subrange,
comment|/// the array @p Undefs is the set of all locations where it is undefined
comment|/// via<def,read-undef> in other subranges for the same register.
name|void
name|extendPHIRange
argument_list|(
name|MachineBasicBlock
operator|&
name|B
argument_list|,
name|LiveRangeCalc
operator|&
name|LRC
argument_list|,
name|LiveRange
operator|&
name|LR
argument_list|,
name|LaneBitmask
name|LM
argument_list|,
name|ArrayRef
operator|<
name|SlotIndex
operator|>
name|Undefs
argument_list|)
decl_stmt|;
comment|/// extendPHIKillRanges - Extend the ranges of all values killed by original
comment|/// parent PHIDefs.
name|void
name|extendPHIKillRanges
parameter_list|()
function_decl|;
comment|/// rewriteAssigned - Rewrite all uses of Edit.getReg() to assigned registers.
name|void
name|rewriteAssigned
parameter_list|(
name|bool
name|ExtendRanges
parameter_list|)
function_decl|;
comment|/// deleteRematVictims - Delete defs that are dead after rematerializing.
name|void
name|deleteRematVictims
parameter_list|()
function_decl|;
comment|/// Add a copy instruction copying \p FromReg to \p ToReg before
comment|/// \p InsertBefore. This can be invoked with a \p LaneMask which may make it
comment|/// necessary to construct a sequence of copies to cover it exactly.
name|SlotIndex
name|buildCopy
argument_list|(
name|unsigned
name|FromReg
argument_list|,
name|unsigned
name|ToReg
argument_list|,
name|LaneBitmask
name|LaneMask
argument_list|,
name|MachineBasicBlock
operator|&
name|MBB
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|InsertBefore
argument_list|,
name|bool
name|Late
argument_list|,
name|unsigned
name|RegIdx
argument_list|)
decl_stmt|;
name|SlotIndex
name|buildSingleSubRegCopy
argument_list|(
name|unsigned
name|FromReg
argument_list|,
name|unsigned
name|ToReg
argument_list|,
name|MachineBasicBlock
operator|&
name|MB
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|InsertBefore
argument_list|,
name|unsigned
name|SubIdx
argument_list|,
name|LiveInterval
operator|&
name|DestLI
argument_list|,
name|bool
name|Late
argument_list|,
name|SlotIndex
name|PrevCopy
argument_list|)
decl_stmt|;
name|public
label|:
comment|/// Create a new SplitEditor for editing the LiveInterval analyzed by SA.
comment|/// Newly created intervals will be appended to newIntervals.
name|SplitEditor
argument_list|(
name|SplitAnalysis
operator|&
name|SA
argument_list|,
name|AliasAnalysis
operator|&
name|AA
argument_list|,
name|LiveIntervals
operator|&
argument_list|,
name|VirtRegMap
operator|&
argument_list|,
name|MachineDominatorTree
operator|&
argument_list|,
name|MachineBlockFrequencyInfo
operator|&
argument_list|)
expr_stmt|;
comment|/// reset - Prepare for a new split.
name|void
name|reset
parameter_list|(
name|LiveRangeEdit
modifier|&
parameter_list|,
name|ComplementSpillMode
init|=
name|SM_Partition
parameter_list|)
function_decl|;
comment|/// Create a new virtual register and live interval.
comment|/// Return the interval index, starting from 1. Interval index 0 is the
comment|/// implicit complement interval.
name|unsigned
name|openIntv
parameter_list|()
function_decl|;
comment|/// currentIntv - Return the current interval index.
name|unsigned
name|currentIntv
argument_list|()
specifier|const
block|{
return|return
name|OpenIdx
return|;
block|}
comment|/// selectIntv - Select a previously opened interval index.
name|void
name|selectIntv
parameter_list|(
name|unsigned
name|Idx
parameter_list|)
function_decl|;
comment|/// enterIntvBefore - Enter the open interval before the instruction at Idx.
comment|/// If the parent interval is not live before Idx, a COPY is not inserted.
comment|/// Return the beginning of the new live range.
name|SlotIndex
name|enterIntvBefore
parameter_list|(
name|SlotIndex
name|Idx
parameter_list|)
function_decl|;
comment|/// enterIntvAfter - Enter the open interval after the instruction at Idx.
comment|/// Return the beginning of the new live range.
name|SlotIndex
name|enterIntvAfter
parameter_list|(
name|SlotIndex
name|Idx
parameter_list|)
function_decl|;
comment|/// enterIntvAtEnd - Enter the open interval at the end of MBB.
comment|/// Use the open interval from the inserted copy to the MBB end.
comment|/// Return the beginning of the new live range.
name|SlotIndex
name|enterIntvAtEnd
parameter_list|(
name|MachineBasicBlock
modifier|&
name|MBB
parameter_list|)
function_decl|;
comment|/// useIntv - indicate that all instructions in MBB should use OpenLI.
name|void
name|useIntv
parameter_list|(
specifier|const
name|MachineBasicBlock
modifier|&
name|MBB
parameter_list|)
function_decl|;
comment|/// useIntv - indicate that all instructions in range should use OpenLI.
name|void
name|useIntv
parameter_list|(
name|SlotIndex
name|Start
parameter_list|,
name|SlotIndex
name|End
parameter_list|)
function_decl|;
comment|/// leaveIntvAfter - Leave the open interval after the instruction at Idx.
comment|/// Return the end of the live range.
name|SlotIndex
name|leaveIntvAfter
parameter_list|(
name|SlotIndex
name|Idx
parameter_list|)
function_decl|;
comment|/// leaveIntvBefore - Leave the open interval before the instruction at Idx.
comment|/// Return the end of the live range.
name|SlotIndex
name|leaveIntvBefore
parameter_list|(
name|SlotIndex
name|Idx
parameter_list|)
function_decl|;
comment|/// leaveIntvAtTop - Leave the interval at the top of MBB.
comment|/// Add liveness from the MBB top to the copy.
comment|/// Return the end of the live range.
name|SlotIndex
name|leaveIntvAtTop
parameter_list|(
name|MachineBasicBlock
modifier|&
name|MBB
parameter_list|)
function_decl|;
comment|/// overlapIntv - Indicate that all instructions in range should use the open
comment|/// interval, but also let the complement interval be live.
comment|///
comment|/// This doubles the register pressure, but is sometimes required to deal with
comment|/// register uses after the last valid split point.
comment|///
comment|/// The Start index should be a return value from a leaveIntv* call, and End
comment|/// should be in the same basic block. The parent interval must have the same
comment|/// value across the range.
comment|///
name|void
name|overlapIntv
parameter_list|(
name|SlotIndex
name|Start
parameter_list|,
name|SlotIndex
name|End
parameter_list|)
function_decl|;
comment|/// finish - after all the new live ranges have been created, compute the
comment|/// remaining live range, and rewrite instructions to use the new registers.
comment|/// @param LRMap When not null, this vector will map each live range in Edit
comment|///              back to the indices returned by openIntv.
comment|///              There may be extra indices created by dead code elimination.
name|void
name|finish
argument_list|(
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|*
name|LRMap
operator|=
name|nullptr
argument_list|)
decl_stmt|;
comment|/// dump - print the current interval mapping to dbgs().
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
comment|// ===--- High level methods ---===
comment|/// splitSingleBlock - Split CurLI into a separate live interval around the
comment|/// uses in a single block. This is intended to be used as part of a larger
comment|/// split, and doesn't call finish().
name|void
name|splitSingleBlock
argument_list|(
specifier|const
name|SplitAnalysis
operator|::
name|BlockInfo
operator|&
name|BI
argument_list|)
decl_stmt|;
comment|/// splitLiveThroughBlock - Split CurLI in the given block such that it
comment|/// enters the block in IntvIn and leaves it in IntvOut. There may be uses in
comment|/// the block, but they will be ignored when placing split points.
comment|///
comment|/// @param MBBNum      Block number.
comment|/// @param IntvIn      Interval index entering the block.
comment|/// @param LeaveBefore When set, leave IntvIn before this point.
comment|/// @param IntvOut     Interval index leaving the block.
comment|/// @param EnterAfter  When set, enter IntvOut after this point.
name|void
name|splitLiveThroughBlock
parameter_list|(
name|unsigned
name|MBBNum
parameter_list|,
name|unsigned
name|IntvIn
parameter_list|,
name|SlotIndex
name|LeaveBefore
parameter_list|,
name|unsigned
name|IntvOut
parameter_list|,
name|SlotIndex
name|EnterAfter
parameter_list|)
function_decl|;
comment|/// splitRegInBlock - Split CurLI in the given block such that it enters the
comment|/// block in IntvIn and leaves it on the stack (or not at all). Split points
comment|/// are placed in a way that avoids putting uses in the stack interval. This
comment|/// may require creating a local interval when there is interference.
comment|///
comment|/// @param BI          Block descriptor.
comment|/// @param IntvIn      Interval index entering the block. Not 0.
comment|/// @param LeaveBefore When set, leave IntvIn before this point.
name|void
name|splitRegInBlock
argument_list|(
specifier|const
name|SplitAnalysis
operator|::
name|BlockInfo
operator|&
name|BI
argument_list|,
name|unsigned
name|IntvIn
argument_list|,
name|SlotIndex
name|LeaveBefore
argument_list|)
decl_stmt|;
comment|/// splitRegOutBlock - Split CurLI in the given block such that it enters the
comment|/// block on the stack (or isn't live-in at all) and leaves it in IntvOut.
comment|/// Split points are placed to avoid interference and such that the uses are
comment|/// not in the stack interval. This may require creating a local interval
comment|/// when there is interference.
comment|///
comment|/// @param BI          Block descriptor.
comment|/// @param IntvOut     Interval index leaving the block.
comment|/// @param EnterAfter  When set, enter IntvOut after this point.
name|void
name|splitRegOutBlock
argument_list|(
specifier|const
name|SplitAnalysis
operator|::
name|BlockInfo
operator|&
name|BI
argument_list|,
name|unsigned
name|IntvOut
argument_list|,
name|SlotIndex
name|EnterAfter
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

