begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---------- SplitKit.cpp - Toolkit for splitting live ranges ----------===//
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
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
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
name|LiveInterval
decl_stmt|;
name|class
name|LiveIntervals
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MachineLoop
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
name|VirtRegMap
decl_stmt|;
name|class
name|VNInfo
decl_stmt|;
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
name|mf_
decl_stmt|;
specifier|const
name|LiveIntervals
modifier|&
name|lis_
decl_stmt|;
specifier|const
name|MachineLoopInfo
modifier|&
name|loops_
decl_stmt|;
specifier|const
name|TargetInstrInfo
modifier|&
name|tii_
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
name|usingInstrs_
decl_stmt|;
comment|// The number of instructions using curli in each basic block.
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
name|usingBlocks_
decl_stmt|;
comment|// The number of basic block using curli in each loop.
typedef|typedef
name|DenseMap
operator|<
specifier|const
name|MachineLoop
operator|*
operator|,
name|unsigned
operator|>
name|LoopCountMap
expr_stmt|;
name|LoopCountMap
name|usingLoops_
decl_stmt|;
name|private
label|:
comment|// Current live interval.
specifier|const
name|LiveInterval
modifier|*
name|curli_
decl_stmt|;
comment|// Sumarize statistics by counting instructions using curli_.
name|void
name|analyzeUses
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
name|MachineFunction
operator|&
name|mf
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
comment|/// analyze - set curli to the specified interval, and analyze how it may be
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
comment|/// removeUse - Update statistics by noting that mi no longer uses curli.
name|void
name|removeUse
parameter_list|(
specifier|const
name|MachineInstr
modifier|*
name|mi
parameter_list|)
function_decl|;
specifier|const
name|LiveInterval
modifier|*
name|getCurLI
parameter_list|()
block|{
return|return
name|curli_
return|;
block|}
comment|/// clear - clear all data structures so SplitAnalysis is ready to analyze a
comment|/// new interval.
name|void
name|clear
parameter_list|()
function_decl|;
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
typedef|typedef
name|SmallPtrSet
operator|<
specifier|const
name|MachineLoop
operator|*
operator|,
literal|16
operator|>
name|LoopPtrSet
expr_stmt|;
comment|// Sets of basic blocks surrounding a machine loop.
struct|struct
name|LoopBlocks
block|{
name|BlockPtrSet
name|Loop
decl_stmt|;
comment|// Blocks in the loop.
name|BlockPtrSet
name|Preds
decl_stmt|;
comment|// Loop predecessor blocks.
name|BlockPtrSet
name|Exits
decl_stmt|;
comment|// Loop exit blocks.
name|void
name|clear
parameter_list|()
block|{
name|Loop
operator|.
name|clear
argument_list|()
expr_stmt|;
name|Preds
operator|.
name|clear
argument_list|()
expr_stmt|;
name|Exits
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
block|}
struct|;
comment|// Calculate the block sets surrounding the loop.
name|void
name|getLoopBlocks
parameter_list|(
specifier|const
name|MachineLoop
modifier|*
name|Loop
parameter_list|,
name|LoopBlocks
modifier|&
name|Blocks
parameter_list|)
function_decl|;
comment|/// LoopPeripheralUse - how is a variable used in and around a loop?
comment|/// Peripheral blocks are the loop predecessors and exit blocks.
enum|enum
name|LoopPeripheralUse
block|{
name|ContainedInLoop
block|,
comment|// All uses are inside the loop.
name|SinglePeripheral
block|,
comment|// At most one instruction per peripheral block.
name|MultiPeripheral
block|,
comment|// Multiple instructions in some peripheral blocks.
name|OutsideLoop
comment|// Uses outside loop periphery.
block|}
enum|;
comment|/// analyzeLoopPeripheralUse - Return an enum describing how curli_ is used in
comment|/// and around the Loop.
name|LoopPeripheralUse
name|analyzeLoopPeripheralUse
parameter_list|(
specifier|const
name|LoopBlocks
modifier|&
parameter_list|)
function_decl|;
comment|/// getCriticalExits - It may be necessary to partially break critical edges
comment|/// leaving the loop if an exit block has phi uses of curli. Collect the exit
comment|/// blocks that need special treatment into CriticalExits.
name|void
name|getCriticalExits
parameter_list|(
specifier|const
name|LoopBlocks
modifier|&
name|Blocks
parameter_list|,
name|BlockPtrSet
modifier|&
name|CriticalExits
parameter_list|)
function_decl|;
comment|/// canSplitCriticalExits - Return true if it is possible to insert new exit
comment|/// blocks before the blocks in CriticalExits.
name|bool
name|canSplitCriticalExits
parameter_list|(
specifier|const
name|LoopBlocks
modifier|&
name|Blocks
parameter_list|,
name|BlockPtrSet
modifier|&
name|CriticalExits
parameter_list|)
function_decl|;
comment|/// getBestSplitLoop - Return the loop where curli may best be split to a
comment|/// separate register, or NULL.
specifier|const
name|MachineLoop
modifier|*
name|getBestSplitLoop
parameter_list|()
function_decl|;
comment|/// getMultiUseBlocks - Add basic blocks to Blocks that may benefit from
comment|/// having curli split to a new live interval. Return true if Blocks can be
comment|/// passed to SplitEditor::splitSingleBlocks.
name|bool
name|getMultiUseBlocks
parameter_list|(
name|BlockPtrSet
modifier|&
name|Blocks
parameter_list|)
function_decl|;
comment|/// getBlockForInsideSplit - If curli is contained inside a single basic block,
comment|/// and it wou pay to subdivide the interval inside that block, return it.
comment|/// Otherwise return NULL. The returned block can be passed to
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
comment|/// parentli_ is the larger interval, li_ is the subset interval. Every value
comment|/// in li_ corresponds to exactly one value in parentli_, and the live range
comment|/// of the value is contained within the live range of the parentli_ value.
comment|/// Values in parentli_ may map to any number of openli_ values, including 0.
name|class
name|LiveIntervalMap
block|{
name|LiveIntervals
modifier|&
name|lis_
decl_stmt|;
comment|// The parent interval is never changed.
specifier|const
name|LiveInterval
modifier|&
name|parentli_
decl_stmt|;
comment|// The child interval's values are fully contained inside parentli_ values.
name|LiveInterval
modifier|&
name|li_
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
comment|// Map parentli_ values to simple values in li_ that are defined at the same
comment|// SlotIndex, or NULL for parentli_ values that have complex li_ defs.
comment|// Note there is a difference between values mapping to NULL (complex), and
comment|// values not present (unknown/unmapped).
name|ValueMap
name|valueMap_
decl_stmt|;
comment|// extendTo - Find the last li_ value defined in MBB at or before Idx. The
comment|// parentli_ is assumed to be live at Idx. Extend the live range to Idx.
comment|// Return the found VNInfo, or NULL.
name|VNInfo
modifier|*
name|extendTo
parameter_list|(
name|MachineBasicBlock
modifier|*
name|MBB
parameter_list|,
name|SlotIndex
name|Idx
parameter_list|)
function_decl|;
comment|// addSimpleRange - Add a simple range from parentli_ to li_.
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
name|public
label|:
name|LiveIntervalMap
argument_list|(
name|LiveIntervals
operator|&
name|lis
argument_list|,
specifier|const
name|LiveInterval
operator|&
name|parentli
argument_list|,
name|LiveInterval
operator|&
name|li
argument_list|)
operator|:
name|lis_
argument_list|(
name|lis
argument_list|)
operator|,
name|parentli_
argument_list|(
name|parentli
argument_list|)
operator|,
name|li_
argument_list|(
argument|li
argument_list|)
block|{}
comment|/// defValue - define a value in li_ from the parentli_ value VNI and Idx.
comment|/// Idx does not have to be ParentVNI->def, but it must be contained within
comment|/// ParentVNI's live range in parentli_.
comment|/// Return the new li_ value.
name|VNInfo
operator|*
name|defValue
argument_list|(
argument|const VNInfo *ParentVNI
argument_list|,
argument|SlotIndex Idx
argument_list|)
expr_stmt|;
comment|/// mapValue - map ParentVNI to the corresponding li_ value at Idx. It is
comment|/// assumed that ParentVNI is live at Idx.
comment|/// If ParentVNI has not been defined by defValue, it is assumed that
comment|/// ParentVNI->def dominates Idx.
comment|/// If ParentVNI has been defined by defValue one or more times, a value that
comment|/// dominates Idx will be returned. This may require creating extra phi-def
comment|/// values and adding live ranges to li_.
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
parameter_list|)
function_decl|;
comment|/// addRange - Add live ranges to li_ where [Start;End) intersects parentli_.
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
comment|/// - Rewrite instructions with rewrite().
comment|///
name|class
name|SplitEditor
block|{
name|SplitAnalysis
modifier|&
name|sa_
decl_stmt|;
name|LiveIntervals
modifier|&
name|lis_
decl_stmt|;
name|VirtRegMap
modifier|&
name|vrm_
decl_stmt|;
name|MachineRegisterInfo
modifier|&
name|mri_
decl_stmt|;
specifier|const
name|TargetInstrInfo
modifier|&
name|tii_
decl_stmt|;
comment|/// curli_ - The immutable interval we are currently splitting.
specifier|const
name|LiveInterval
modifier|*
specifier|const
name|curli_
decl_stmt|;
comment|/// dupli_ - Created as a copy of curli_, ranges are carved out as new
comment|/// intervals get added through openIntv / closeIntv. This is used to avoid
comment|/// editing curli_.
name|LiveInterval
modifier|*
name|dupli_
decl_stmt|;
comment|/// Currently open LiveInterval.
name|LiveInterval
modifier|*
name|openli_
decl_stmt|;
comment|/// createInterval - Create a new virtual register and LiveInterval with same
comment|/// register class and spill slot as curli.
name|LiveInterval
modifier|*
name|createInterval
parameter_list|()
function_decl|;
comment|/// getDupLI - Ensure dupli is created and return it.
name|LiveInterval
modifier|*
name|getDupLI
parameter_list|()
function_decl|;
comment|/// valueMap_ - Map values in cupli to values in openli. These are direct 1-1
comment|/// mappings, and do not include values created by inserted copies.
name|DenseMap
operator|<
specifier|const
name|VNInfo
operator|*
operator|,
name|VNInfo
operator|*
operator|>
name|valueMap_
expr_stmt|;
comment|/// mapValue - Return the openIntv value that corresponds to the given curli
comment|/// value.
name|VNInfo
modifier|*
name|mapValue
parameter_list|(
specifier|const
name|VNInfo
modifier|*
name|curliVNI
parameter_list|)
function_decl|;
comment|/// A dupli value is live through openIntv.
name|bool
name|liveThrough_
decl_stmt|;
comment|/// All the new intervals created for this split are added to intervals_.
name|SmallVectorImpl
operator|<
name|LiveInterval
operator|*
operator|>
operator|&
name|intervals_
expr_stmt|;
comment|/// The index into intervals_ of the first interval we added. There may be
comment|/// others from before we got it.
name|unsigned
name|firstInterval
decl_stmt|;
comment|/// Insert a COPY instruction curli -> li. Allocate a new value from li
comment|/// defined by the COPY
name|VNInfo
modifier|*
name|insertCopy
argument_list|(
name|LiveInterval
operator|&
name|LI
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
name|SmallVectorImpl
operator|<
name|LiveInterval
operator|*
operator|>
operator|&
name|newIntervals
argument_list|)
expr_stmt|;
comment|/// getAnalysis - Get the corresponding analysis.
name|SplitAnalysis
modifier|&
name|getAnalysis
parameter_list|()
block|{
return|return
name|sa_
return|;
block|}
comment|/// Create a new virtual register and live interval.
name|void
name|openIntv
parameter_list|()
function_decl|;
comment|/// enterIntvBefore - Enter openli before the instruction at Idx. If curli is
comment|/// not live before Idx, a COPY is not inserted.
name|void
name|enterIntvBefore
parameter_list|(
name|SlotIndex
name|Idx
parameter_list|)
function_decl|;
comment|/// enterIntvAtEnd - Enter openli at the end of MBB.
comment|/// PhiMBB is a successor inside openli where a PHI value is created.
comment|/// Currently, all entries must share the same PhiMBB.
name|void
name|enterIntvAtEnd
parameter_list|(
name|MachineBasicBlock
modifier|&
name|MBB
parameter_list|,
name|MachineBasicBlock
modifier|&
name|PhiMBB
parameter_list|)
function_decl|;
comment|/// useIntv - indicate that all instructions in MBB should use openli.
name|void
name|useIntv
parameter_list|(
specifier|const
name|MachineBasicBlock
modifier|&
name|MBB
parameter_list|)
function_decl|;
comment|/// useIntv - indicate that all instructions in range should use openli.
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
comment|/// leaveIntvAfter - Leave openli after the instruction at Idx.
name|void
name|leaveIntvAfter
parameter_list|(
name|SlotIndex
name|Idx
parameter_list|)
function_decl|;
comment|/// leaveIntvAtTop - Leave the interval at the top of MBB.
comment|/// Currently, only one value can leave the interval.
name|void
name|leaveIntvAtTop
parameter_list|(
name|MachineBasicBlock
modifier|&
name|MBB
parameter_list|)
function_decl|;
comment|/// closeIntv - Indicate that we are done editing the currently open
comment|/// LiveInterval, and ranges can be trimmed.
name|void
name|closeIntv
parameter_list|()
function_decl|;
comment|/// rewrite - after all the new live ranges have been created, rewrite
comment|/// instructions using curli to use the new intervals.
name|void
name|rewrite
parameter_list|()
function_decl|;
comment|// ===--- High level methods ---===
comment|/// splitAroundLoop - Split curli into a separate live interval inside
comment|/// the loop. Return true if curli has been completely replaced, false if
comment|/// curli is still intact, and needs to be spilled or split further.
name|bool
name|splitAroundLoop
parameter_list|(
specifier|const
name|MachineLoop
modifier|*
parameter_list|)
function_decl|;
comment|/// splitSingleBlocks - Split curli into a separate live interval inside each
comment|/// basic block in Blocks. Return true if curli has been completely replaced,
comment|/// false if curli is still intact, and needs to be spilled or split further.
name|bool
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
comment|/// splitInsideBlock - Split curli into multiple intervals inside MBB. Return
comment|/// true if curli has been completely replaced, false if curli is still
comment|/// intact, and needs to be spilled or split further.
name|bool
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

