begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MachineLoopRanges.h - Ranges of machine loops -----------*- c++ -*--===//
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
comment|// This file provides the interface to the MachineLoopRanges analysis.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Provide on-demand information about the ranges of machine instructions
end_comment

begin_comment
comment|// covered by a loop.
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
name|LLVM_CODEGEN_MACHINELOOPRANGES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_MACHINELOOPRANGES_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/IntervalMap.h"
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
name|MachineLoop
decl_stmt|;
name|class
name|MachineLoopInfo
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// MachineLoopRange - Range information for a single loop.
name|class
name|MachineLoopRange
block|{
name|friend
name|class
name|MachineLoopRanges
decl_stmt|;
name|public
label|:
typedef|typedef
name|IntervalMap
operator|<
name|SlotIndex
operator|,
name|unsigned
operator|,
literal|4
operator|>
name|Map
expr_stmt|;
typedef|typedef
name|Map
operator|::
name|Allocator
name|Allocator
expr_stmt|;
name|private
label|:
comment|/// The mapped loop.
specifier|const
name|MachineLoop
modifier|*
specifier|const
name|Loop
decl_stmt|;
comment|/// Map intervals to a bit mask.
comment|/// Bit 0 = inside loop block.
name|Map
name|Intervals
decl_stmt|;
comment|/// Loop area as measured by SlotIndex::distance.
name|unsigned
name|Area
decl_stmt|;
comment|/// Create a MachineLoopRange, only accessible to MachineLoopRanges.
name|MachineLoopRange
argument_list|(
specifier|const
name|MachineLoop
operator|*
argument_list|,
name|Allocator
operator|&
argument_list|,
name|SlotIndexes
operator|&
argument_list|)
expr_stmt|;
name|public
label|:
comment|/// getLoop - Return the mapped machine loop.
specifier|const
name|MachineLoop
operator|*
name|getLoop
argument_list|()
specifier|const
block|{
return|return
name|Loop
return|;
block|}
comment|/// overlaps - Return true if this loop overlaps the given range of machine
comment|/// inteructions.
name|bool
name|overlaps
parameter_list|(
name|SlotIndex
name|Start
parameter_list|,
name|SlotIndex
name|Stop
parameter_list|)
function_decl|;
comment|/// getNumber - Return the loop number. This is the same as the number of the
comment|/// header block.
name|unsigned
name|getNumber
argument_list|()
specifier|const
expr_stmt|;
comment|/// getArea - Return the loop area. This number is approximately proportional
comment|/// to the number of instructions in the loop.
name|unsigned
name|getArea
argument_list|()
specifier|const
block|{
return|return
name|Area
return|;
block|}
comment|/// getMap - Allow public read-only access for IntervalMapOverlaps.
specifier|const
name|Map
modifier|&
name|getMap
parameter_list|()
block|{
return|return
name|Intervals
return|;
block|}
comment|/// print - Print loop ranges on OS.
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
argument_list|)
decl|const
decl_stmt|;
comment|/// byNumber - Comparator for array_pod_sort that sorts a list of
comment|/// MachineLoopRange pointers by number.
specifier|static
name|int
name|byNumber
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/// byAreaDesc - Comparator for array_pod_sort that sorts a list of
comment|/// MachineLoopRange pointers by descending area, then by number.
specifier|static
name|int
name|byAreaDesc
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
block|}
empty_stmt|;
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
operator|,
specifier|const
name|MachineLoopRange
operator|&
operator|)
expr_stmt|;
comment|/// MachineLoopRanges - Analysis pass that provides on-demand per-loop range
comment|/// information.
name|class
name|MachineLoopRanges
range|:
name|public
name|MachineFunctionPass
block|{
typedef|typedef
name|DenseMap
operator|<
specifier|const
name|MachineLoop
operator|*
operator|,
name|MachineLoopRange
operator|*
operator|>
name|CacheMap
expr_stmt|;
typedef|typedef
name|MachineLoopRange
operator|::
name|Allocator
name|MapAllocator
expr_stmt|;
name|MapAllocator
name|Allocator
decl_stmt|;
name|SlotIndexes
modifier|*
name|Indexes
decl_stmt|;
name|CacheMap
name|Cache
decl_stmt|;
name|public
label|:
specifier|static
name|char
name|ID
decl_stmt|;
comment|// Pass identification, replacement for typeid
name|MachineLoopRanges
argument_list|()
operator|:
name|MachineFunctionPass
argument_list|(
name|ID
argument_list|)
operator|,
name|Indexes
argument_list|(
literal|0
argument_list|)
block|{}
operator|~
name|MachineLoopRanges
argument_list|()
block|{
name|releaseMemory
argument_list|()
block|; }
comment|/// getLoopRange - Return the range of loop.
name|MachineLoopRange
operator|*
name|getLoopRange
argument_list|(
specifier|const
name|MachineLoop
operator|*
name|Loop
argument_list|)
expr_stmt|;
name|private
label|:
name|virtual
name|bool
name|runOnMachineFunction
parameter_list|(
name|MachineFunction
modifier|&
parameter_list|)
function_decl|;
name|virtual
name|void
name|releaseMemory
parameter_list|()
function_decl|;
name|virtual
name|void
name|getAnalysisUsage
argument_list|(
name|AnalysisUsage
operator|&
argument_list|)
decl|const
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CODEGEN_MACHINELOOPRANGES_H
end_comment

end_unit

