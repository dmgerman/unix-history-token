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

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
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
comment|// Instructions using the the current register.
typedef|typedef
name|SmallPtrSet
operator|<
specifier|const
name|MachineInstr
operator|*
operator|,
literal|16
operator|>
name|InstrPtrSet
expr_stmt|;
name|InstrPtrSet
name|UsingInstrs
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
comment|// The number of instructions using CurLI in each basic block.
typedef|typedef
name|DenseMap
operator|<
specifier|const
name|MachineBasicBlock
operator|*
operator|,
name|unsigned
operator|>
name|BlockCountMap
expr_stmt|;
name|BlockCountMap
name|UsingBlocks
decl_stmt|;
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
comment|/// Last possible point for splitting live ranges.
name|SlotIndex
name|LastSplitPoint
decl_stmt|;
name|bool
name|Uses
decl_stmt|;
comment|///< Current reg has uses or defs in block.
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
comment|// Per-interference pattern scratch data.
name|bool
name|OverlapEntry
decl_stmt|;
comment|///< Interference overlaps entering interval.
name|bool
name|OverlapExit
decl_stmt|;
comment|///< Interference overlaps exiting interval.
block|}
struct|;
comment|/// Basic blocks where var is live. This array is parallel to
comment|/// SpillConstraints.
name|SmallVector
operator|<
name|BlockInfo
operator|,
literal|8
operator|>
name|LiveBlocks
expr_stmt|;
name|private
label|:
comment|// Current live interval.
specifier|const
name|LiveInterval
modifier|*
name|CurLI
decl_stmt|;
comment|// Sumarize statistics by counting instructions using CurLI.
name|void
name|analyzeUses
parameter_list|()
function_decl|;
comment|/// calcLiveBlockInfo - Compute per-block information about CurLI.
name|void
name|calcLiveBlockInfo
parameter_list|()
function_decl|;
comment|/// canAnalyzeBranch - Return true if MBB ends in a branch that can be
comment|/// analyzed.
name|bool
name|canAnalyzeBranch
parameter_list|(
specifier|const
name|MachineBasicBlock
modifier|*
name|MBB
parameter_list|)
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
comment|/// hasUses - Return true if MBB has any uses of CurLI.
name|bool
name|hasUses
argument_list|(
specifier|const
name|MachineBasicBlock
operator|*
name|MBB
argument_list|)
decl|const
block|{
return|return
name|UsingBlocks
operator|.
name|lookup
argument_list|(
name|MBB
argument_list|)
return|;
block|}
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
comment|// Print a set of blocks with use counts.
name|void
name|print
argument_list|(
specifier|const
name|BlockPtrSet
operator|&
argument_list|,
name|raw_ostream
operator|&
argument_list|)
decl|const
decl_stmt|;
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
comment|/// getBlockForInsideSplit - If CurLI is contained inside a single basic
comment|/// block, and it would pay to subdivide the interval inside that block,
comment|/// return it. Otherwise return NULL. The returned block can be passed to
comment|/// SplitEditor::splitInsideBlock.
specifier|const
name|MachineBasicBlock
modifier|*
name|getBlockForInsideSplit
parameter_list|()
function_decl|;
block|}
empty_stmt|;
comment|/// LiveIntervalMap - Map values from a large LiveInterval into a small
comment|/// interval that is a subset. Insert phi-def values as needed. This class is
comment|/// used by SplitEditor to create new smaller LiveIntervals.
comment|///
comment|/// ParentLI is the larger interval, LI is the subset interval. Every value
comment|/// in LI corresponds to exactly one value in ParentLI, and the live range
comment|/// of the value is contained within the live range of the ParentLI value.
comment|/// Values in ParentLI may map to any number of OpenLI values, including 0.
name|class
name|LiveIntervalMap
block|{
name|LiveIntervals
modifier|&
name|LIS
decl_stmt|;
name|MachineDominatorTree
modifier|&
name|MDT
decl_stmt|;
comment|// The parent interval is never changed.
specifier|const
name|LiveInterval
modifier|&
name|ParentLI
decl_stmt|;
comment|// The child interval's values are fully contained inside ParentLI values.
name|LiveInterval
modifier|*
name|LI
decl_stmt|;
typedef|typedef
name|DenseMap
operator|<
specifier|const
name|VNInfo
operator|*
operator|,
name|VNInfo
operator|*
operator|>
name|ValueMap
expr_stmt|;
comment|// Map ParentLI values to simple values in LI that are defined at the same
comment|// SlotIndex, or NULL for ParentLI values that have complex LI defs.
comment|// Note there is a difference between values mapping to NULL (complex), and
comment|// values not present (unknown/unmapped).
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
name|DenseMap
operator|<
name|MachineBasicBlock
operator|*
operator|,
name|LiveOutPair
operator|>
name|LiveOutMap
expr_stmt|;
comment|// LiveOutCache - Map each basic block where LI is live out to the live-out
comment|// value and its defining block. One of these conditions shall be true:
comment|//
comment|//  1. !LiveOutCache.count(MBB)
comment|//  2. LiveOutCache[MBB].second.getNode() == MBB
comment|//  3. forall P in preds(MBB): LiveOutCache[P] == LiveOutCache[MBB]
comment|//
comment|// This is only a cache, the values can be computed as:
comment|//
comment|//  VNI = LI->getVNInfoAt(LIS.getMBBEndIdx(MBB))
comment|//  Node = mbt_[LIS.getMBBFromIndex(VNI->def)]
comment|//
comment|// The cache is also used as a visiteed set by mapValue().
name|LiveOutMap
name|LiveOutCache
decl_stmt|;
comment|// Dump the live-out cache to dbgs().
name|void
name|dumpCache
parameter_list|()
function_decl|;
name|public
label|:
name|LiveIntervalMap
argument_list|(
name|LiveIntervals
operator|&
name|lis
argument_list|,
name|MachineDominatorTree
operator|&
name|mdt
argument_list|,
specifier|const
name|LiveInterval
operator|&
name|parentli
argument_list|)
operator|:
name|LIS
argument_list|(
name|lis
argument_list|)
operator|,
name|MDT
argument_list|(
name|mdt
argument_list|)
operator|,
name|ParentLI
argument_list|(
name|parentli
argument_list|)
operator|,
name|LI
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// reset - clear all data structures and start a new live interval.
name|void
name|reset
argument_list|(
name|LiveInterval
operator|*
argument_list|)
expr_stmt|;
comment|/// getLI - return the current live interval.
name|LiveInterval
operator|*
name|getLI
argument_list|()
specifier|const
block|{
return|return
name|LI
return|;
block|}
comment|/// defValue - define a value in LI from the ParentLI value VNI and Idx.
comment|/// Idx does not have to be ParentVNI->def, but it must be contained within
comment|/// ParentVNI's live range in ParentLI.
comment|/// Return the new LI value.
name|VNInfo
modifier|*
name|defValue
parameter_list|(
specifier|const
name|VNInfo
modifier|*
name|ParentVNI
parameter_list|,
name|SlotIndex
name|Idx
parameter_list|)
function_decl|;
comment|/// mapValue - map ParentVNI to the corresponding LI value at Idx. It is
comment|/// assumed that ParentVNI is live at Idx.
comment|/// If ParentVNI has not been defined by defValue, it is assumed that
comment|/// ParentVNI->def dominates Idx.
comment|/// If ParentVNI has been defined by defValue one or more times, a value that
comment|/// dominates Idx will be returned. This may require creating extra phi-def
comment|/// values and adding live ranges to LI.
comment|/// If simple is not NULL, *simple will indicate if ParentVNI is a simply
comment|/// mapped value.
name|VNInfo
modifier|*
name|mapValue
parameter_list|(
specifier|const
name|VNInfo
modifier|*
name|ParentVNI
parameter_list|,
name|SlotIndex
name|Idx
parameter_list|,
name|bool
modifier|*
name|simple
init|=
literal|0
parameter_list|)
function_decl|;
comment|// extendTo - Find the last LI value defined in MBB at or before Idx. The
comment|// parentli is assumed to be live at Idx. Extend the live range to include
comment|// Idx. Return the found VNInfo, or NULL.
name|VNInfo
modifier|*
name|extendTo
parameter_list|(
specifier|const
name|MachineBasicBlock
modifier|*
name|MBB
parameter_list|,
name|SlotIndex
name|Idx
parameter_list|)
function_decl|;
comment|/// isMapped - Return true is ParentVNI is a known mapped value. It may be a
comment|/// simple 1-1 mapping or a complex mapping to later defs.
name|bool
name|isMapped
argument_list|(
specifier|const
name|VNInfo
operator|*
name|ParentVNI
argument_list|)
decl|const
block|{
return|return
name|Values
operator|.
name|count
argument_list|(
name|ParentVNI
argument_list|)
return|;
block|}
comment|/// isComplexMapped - Return true if ParentVNI has received new definitions
comment|/// with defValue.
name|bool
name|isComplexMapped
argument_list|(
specifier|const
name|VNInfo
operator|*
name|ParentVNI
argument_list|)
decl|const
decl_stmt|;
comment|/// markComplexMapped - Mark ParentVNI as complex mapped regardless of the
comment|/// number of definitions.
name|void
name|markComplexMapped
parameter_list|(
specifier|const
name|VNInfo
modifier|*
name|ParentVNI
parameter_list|)
block|{
name|Values
index|[
name|ParentVNI
index|]
operator|=
literal|0
expr_stmt|;
block|}
comment|// addSimpleRange - Add a simple range from ParentLI to LI.
comment|// ParentVNI must be live in the [Start;End) interval.
name|void
name|addSimpleRange
parameter_list|(
name|SlotIndex
name|Start
parameter_list|,
name|SlotIndex
name|End
parameter_list|,
specifier|const
name|VNInfo
modifier|*
name|ParentVNI
parameter_list|)
function_decl|;
comment|/// addRange - Add live ranges to LI where [Start;End) intersects ParentLI.
comment|/// All needed values whose def is not inside [Start;End) must be defined
comment|/// beforehand so mapValue will work.
name|void
name|addRange
parameter_list|(
name|SlotIndex
name|Start
parameter_list|,
name|SlotIndex
name|End
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
modifier|&
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
comment|/// LIMappers - One LiveIntervalMap or each interval in Edit.
name|SmallVector
operator|<
name|LiveIntervalMap
operator|,
literal|4
operator|>
name|LIMappers
expr_stmt|;
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
comment|/// rewriteAssigned - Rewrite all uses of Edit.getReg() to assigned registers.
name|void
name|rewriteAssigned
parameter_list|()
function_decl|;
comment|/// rewriteComponents - Rewrite all uses of Intv[0] according to the eq
comment|/// classes in ConEQ.
comment|/// This must be done when Intvs[0] is styill live at all uses, before calling
comment|/// ConEq.Distribute().
name|void
name|rewriteComponents
argument_list|(
specifier|const
name|SmallVectorImpl
operator|<
name|LiveInterval
operator|*
operator|>
operator|&
name|Intvs
argument_list|,
specifier|const
name|ConnectedVNInfoEqClasses
operator|&
name|ConEq
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
name|LiveIntervals
operator|&
argument_list|,
name|VirtRegMap
operator|&
argument_list|,
name|MachineDominatorTree
operator|&
argument_list|,
name|LiveRangeEdit
operator|&
argument_list|)
expr_stmt|;
comment|/// getAnalysis - Get the corresponding analysis.
name|SplitAnalysis
modifier|&
name|getAnalysis
parameter_list|()
block|{
return|return
name|SA
return|;
block|}
comment|/// Create a new virtual register and live interval.
name|void
name|openIntv
parameter_list|()
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
comment|/// closeIntv - Indicate that we are done editing the currently open
comment|/// LiveInterval, and ranges can be trimmed.
name|void
name|closeIntv
parameter_list|()
function_decl|;
comment|/// finish - after all the new live ranges have been created, compute the
comment|/// remaining live range, and rewrite instructions to use the new registers.
name|void
name|finish
parameter_list|()
function_decl|;
comment|/// dump - print the current interval maping to dbgs().
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
comment|// ===--- High level methods ---===
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
comment|/// splitInsideBlock - Split CurLI into multiple intervals inside MBB.
name|void
name|splitInsideBlock
parameter_list|(
specifier|const
name|MachineBasicBlock
modifier|*
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

end_unit

