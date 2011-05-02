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
name|LLVM_CODEGEN_SPLITKIT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_SPLITKIT_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
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
file|"llvm/ADT/IndexedMap.h"
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

begin_include
include|#
directive|include
file|"llvm/CodeGen/SlotIndexes.h"
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
comment|/// At some point we should just include MachineDominators.h:
name|class
name|MachineDominatorTree
decl_stmt|;
name|template
operator|<
name|class
name|NodeT
operator|>
name|class
name|DomTreeNodeBase
expr_stmt|;
typedef|typedef
name|DomTreeNodeBase
operator|<
name|MachineBasicBlock
operator|>
name|MachineDomTreeNode
expr_stmt|;
comment|/// SplitAnalysis - Analyze a LiveInterval, looking for live range splitting
comment|/// opportunities.
name|class
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
comment|// Sorted slot indexes of using instructions.
name|SmallVector
operator|<
name|SlotIndex
operator|,
literal|8
operator|>
name|UseSlots
expr_stmt|;
comment|/// Additional information about basic blocks where the current variable is
comment|/// live. Such a block will look like one of these templates:
comment|///
comment|///  1. |   o---x   | Internal to block. Variable is only live in this block.
comment|///  2. |---x       | Live-in, kill.
comment|///  3. |       o---| Def, live-out.
comment|///  4. |---x   o---| Live-in, kill, def, live-out.
comment|///  5. |---o---o---| Live-through with uses or defs.
comment|///  6. |-----------| Live-through without uses. Transparent.
comment|///
struct|struct
name|BlockInfo
block|{
name|MachineBasicBlock
modifier|*
name|MBB
decl_stmt|;
name|SlotIndex
name|FirstUse
decl_stmt|;
comment|///< First instr using current reg.
name|SlotIndex
name|LastUse
decl_stmt|;
comment|///< Last instr using current reg.
name|SlotIndex
name|Kill
decl_stmt|;
comment|///< Interval end point inside block.
name|SlotIndex
name|Def
decl_stmt|;
comment|///< Interval start point inside block.
name|bool
name|LiveThrough
decl_stmt|;
comment|///< Live in whole block (Templ 5. or 6. above).
name|bool
name|LiveIn
decl_stmt|;
comment|///< Current reg is live in.
name|bool
name|LiveOut
decl_stmt|;
comment|///< Current reg is live out.
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
comment|/// LastSplitPoint - Last legal split point in each basic block in the current
comment|/// function. The first entry is the first terminator, the second entry is the
comment|/// last valid split point for a variable that is live in to a landing pad
comment|/// successor.
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
name|LastSplitPoint
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
comment|/// ThroughBlocks - Block numbers where CurLI is live through without uses.
name|BitVector
name|ThroughBlocks
decl_stmt|;
comment|/// NumThroughBlocks - Number of live-through blocks.
name|unsigned
name|NumThroughBlocks
decl_stmt|;
name|SlotIndex
name|computeLastSplitPoint
parameter_list|(
name|unsigned
name|Num
parameter_list|)
function_decl|;
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
comment|/// getLastSplitPoint - Return that base index of the last valid split point
comment|/// in the basic block numbered Num.
name|SlotIndex
name|getLastSplitPoint
parameter_list|(
name|unsigned
name|Num
parameter_list|)
block|{
comment|// Inline the common simple case.
if|if
condition|(
name|LastSplitPoint
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
name|LastSplitPoint
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
name|LastSplitPoint
index|[
name|Num
index|]
operator|.
name|first
return|;
return|return
name|computeLastSplitPoint
argument_list|(
name|Num
argument_list|)
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
comment|/// getUseBlocks - Return an array of BlockInfo objects for the basic blocks
comment|/// where CurLI has uses.
name|ArrayRef
operator|<
name|BlockInfo
operator|>
name|getUseBlocks
argument_list|()
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
comment|/// countLiveBlocks - Return the number of blocks where li is live.
comment|/// This is guaranteed to return the same number as getNumThroughBlocks() +
comment|/// getUseBlocks().size() after calling analyze(li).
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
comment|/// getMultiUseBlocks - Add basic blocks to Blocks that may benefit from
comment|/// having CurLI split to a new live interval. Return true if Blocks can be
comment|/// passed to SplitEditor::splitSingleBlocks.
name|bool
name|getMultiUseBlocks
parameter_list|(
name|BlockPtrSet
modifier|&
name|Blocks
parameter_list|)
function_decl|;
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
name|SplitEditor
block|{
name|SplitAnalysis
modifier|&
name|SA
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
name|VNInfo
operator|*
operator|>
name|ValueMap
expr_stmt|;
comment|/// Values - keep track of the mapping from parent values to values in the new
comment|/// intervals. Given a pair (RegIdx, ParentVNI->id), Values contains:
comment|///
comment|/// 1. No entry - the value is not mapped to Edit.get(RegIdx).
comment|/// 2. Null - the value is mapped to multiple values in Edit.get(RegIdx).
comment|///    Each value is represented by a minimal live range at its def.
comment|/// 3. A non-null VNInfo - the value is mapped to a single new value.
comment|///    The new value has no live ranges anywhere.
name|ValueMap
name|Values
decl_stmt|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|VNInfo
operator|*
operator|,
name|MachineDomTreeNode
operator|*
operator|>
name|LiveOutPair
expr_stmt|;
typedef|typedef
name|IndexedMap
operator|<
name|LiveOutPair
operator|,
name|MBB2NumberFunctor
operator|>
name|LiveOutMap
expr_stmt|;
comment|// LiveOutCache - Map each basic block where a new register is live out to the
comment|// live-out value and its defining block.
comment|// One of these conditions shall be true:
comment|//
comment|//  1. !LiveOutCache.count(MBB)
comment|//  2. LiveOutCache[MBB].second.getNode() == MBB
comment|//  3. forall P in preds(MBB): LiveOutCache[P] == LiveOutCache[MBB]
comment|//
comment|// This is only a cache, the values can be computed as:
comment|//
comment|//  VNI = Edit.get(RegIdx)->getVNInfoAt(LIS.getMBBEndIdx(MBB))
comment|//  Node = mbt_[LIS.getMBBFromIndex(VNI->def)]
comment|//
comment|// The cache is also used as a visited set by extendRange(). It can be shared
comment|// by all the new registers because at most one is live out of each block.
name|LiveOutMap
name|LiveOutCache
decl_stmt|;
comment|// LiveOutSeen - Indexed by MBB->getNumber(), a bit is set for each valid
comment|// entry in LiveOutCache.
name|BitVector
name|LiveOutSeen
decl_stmt|;
comment|/// LiveInBlock - Info for updateSSA() about a block where a register is
comment|/// live-in.
comment|/// The updateSSA caller provides DomNode and Kill inside MBB, updateSSA()
comment|/// adds the computed live-in value.
struct|struct
name|LiveInBlock
block|{
comment|// Dominator tree node for the block.
comment|// Cleared by updateSSA when the final value has been determined.
name|MachineDomTreeNode
modifier|*
name|DomNode
decl_stmt|;
comment|// Live-in value filled in by updateSSA once it is known.
name|VNInfo
modifier|*
name|Value
decl_stmt|;
comment|// Position in block where the live-in range ends, or SlotIndex() if the
comment|// range passes through the block.
name|SlotIndex
name|Kill
decl_stmt|;
name|LiveInBlock
argument_list|(
name|MachineDomTreeNode
operator|*
name|node
argument_list|)
operator|:
name|DomNode
argument_list|(
name|node
argument_list|)
operator|,
name|Value
argument_list|(
literal|0
argument_list|)
block|{}
block|}
struct|;
comment|/// LiveInBlocks - List of live-in blocks used by findReachingDefs() and
comment|/// updateSSA(). This list is usually empty, it exists here to avoid frequent
comment|/// reallocations.
name|SmallVector
operator|<
name|LiveInBlock
operator|,
literal|16
operator|>
name|LiveInBlocks
expr_stmt|;
comment|/// defValue - define a value in RegIdx from ParentVNI at Idx.
comment|/// Idx does not have to be ParentVNI->def, but it must be contained within
comment|/// ParentVNI's live range in ParentLI. The new value is added to the value
comment|/// map.
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
parameter_list|)
function_decl|;
comment|/// markComplexMapped - Mark ParentVNI as complex mapped in RegIdx regardless
comment|/// of the number of defs.
name|void
name|markComplexMapped
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
comment|/// extendRange - Extend the live range of Edit.get(RegIdx) so it reaches Idx.
comment|/// Insert PHIDefs as needed to preserve SSA form.
name|void
name|extendRange
parameter_list|(
name|unsigned
name|RegIdx
parameter_list|,
name|SlotIndex
name|Idx
parameter_list|)
function_decl|;
comment|/// findReachingDefs - Starting from MBB, add blocks to LiveInBlocks until all
comment|/// reaching defs for LI are found.
comment|/// @param LI   Live interval whose value is needed.
comment|/// @param MBB  Block where LI should be live-in.
comment|/// @param Kill Kill point in MBB.
comment|/// @return Unique value seen, or NULL.
name|VNInfo
modifier|*
name|findReachingDefs
parameter_list|(
name|LiveInterval
modifier|*
name|LI
parameter_list|,
name|MachineBasicBlock
modifier|*
name|MBB
parameter_list|,
name|SlotIndex
name|Kill
parameter_list|)
function_decl|;
comment|/// updateSSA - Compute and insert PHIDefs such that all blocks in
comment|// LiveInBlocks get a known live-in value. Add live ranges to the blocks.
name|void
name|updateSSA
parameter_list|()
function_decl|;
comment|/// transferValues - Transfer values to the new ranges.
comment|/// Return true if any ranges were skipped.
name|bool
name|transferValues
parameter_list|()
function_decl|;
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
name|LiveIntervals
operator|&
argument_list|,
name|VirtRegMap
operator|&
argument_list|,
name|MachineDominatorTree
operator|&
argument_list|)
expr_stmt|;
comment|/// reset - Prepare for a new split.
name|void
name|reset
parameter_list|(
name|LiveRangeEdit
modifier|&
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
comment|/// enterIntvAtEnd - Enter the open interval at the end of MBB.
comment|/// Use the open interval from he inserted copy to the MBB end.
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
literal|0
argument_list|)
decl_stmt|;
comment|/// dump - print the current interval maping to dbgs().
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
comment|/// splitSingleBlocks - Split CurLI into a separate live interval inside each
comment|/// basic block in Blocks.
name|void
name|splitSingleBlocks
argument_list|(
specifier|const
name|SplitAnalysis
operator|::
name|BlockPtrSet
operator|&
name|Blocks
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

