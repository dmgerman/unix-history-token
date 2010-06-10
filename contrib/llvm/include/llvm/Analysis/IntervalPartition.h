begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- IntervalPartition.h - Interval partition Calculation -----*- C++ -*-===//
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
comment|// This file contains the declaration of the IntervalPartition class, which
end_comment

begin_comment
comment|// calculates and represents the interval partition of a function, or a
end_comment

begin_comment
comment|// preexisting interval partition.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// In this way, the interval partition may be used to reduce a flow graph down
end_comment

begin_comment
comment|// to its degenerate single node interval partition (unless it is irreducible).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// TODO: The IntervalPartition class should take a bool parameter that tells
end_comment

begin_comment
comment|// whether it should add the "tails" of an interval to an interval itself or if
end_comment

begin_comment
comment|// they should be represented as distinct intervals.
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
name|LLVM_INTERVAL_PARTITION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_INTERVAL_PARTITION_H
end_define

begin_include
include|#
directive|include
file|"llvm/Analysis/Interval.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// IntervalPartition - This class builds and holds an "interval partition" for
comment|// a function.  This partition divides the control flow graph into a set of
comment|// maximal intervals, as defined with the properties above.  Intuitively, a
comment|// BasicBlock is a (possibly nonexistent) loop with a "tail" of non looping
comment|// nodes following it.
comment|//
name|class
name|IntervalPartition
range|:
name|public
name|FunctionPass
block|{
typedef|typedef
name|std
operator|::
name|map
operator|<
name|BasicBlock
operator|*
operator|,
name|Interval
operator|*
operator|>
name|IntervalMapTy
expr_stmt|;
name|IntervalMapTy
name|IntervalMap
decl_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|Interval
operator|*
operator|>
name|IntervalListTy
expr_stmt|;
name|Interval
modifier|*
name|RootInterval
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|Interval
operator|*
operator|>
name|Intervals
expr_stmt|;
name|public
label|:
specifier|static
name|char
name|ID
decl_stmt|;
comment|// Pass identification, replacement for typeid
name|IntervalPartition
argument_list|()
operator|:
name|FunctionPass
argument_list|(
operator|&
name|ID
argument_list|)
operator|,
name|RootInterval
argument_list|(
literal|0
argument_list|)
block|{}
comment|// run - Calculate the interval partition for this function
name|virtual
name|bool
name|runOnFunction
argument_list|(
name|Function
operator|&
name|F
argument_list|)
expr_stmt|;
comment|// IntervalPartition ctor - Build a reduced interval partition from an
comment|// existing interval graph.  This takes an additional boolean parameter to
comment|// distinguish it from a copy constructor.  Always pass in false for now.
comment|//
name|IntervalPartition
argument_list|(
name|IntervalPartition
operator|&
name|I
argument_list|,
name|bool
argument_list|)
expr_stmt|;
comment|// print - Show contents in human readable format...
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
comment|// getRootInterval() - Return the root interval that contains the starting
comment|// block of the function.
specifier|inline
name|Interval
modifier|*
name|getRootInterval
parameter_list|()
block|{
return|return
name|RootInterval
return|;
block|}
comment|// isDegeneratePartition() - Returns true if the interval partition contains
comment|// a single interval, and thus cannot be simplified anymore.
name|bool
name|isDegeneratePartition
parameter_list|()
block|{
return|return
name|Intervals
operator|.
name|size
argument_list|()
operator|==
literal|1
return|;
block|}
comment|// TODO: isIrreducible - look for triangle graph.
comment|// getBlockInterval - Return the interval that a basic block exists in.
specifier|inline
name|Interval
modifier|*
name|getBlockInterval
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
block|{
name|IntervalMapTy
operator|::
name|iterator
name|I
operator|=
name|IntervalMap
operator|.
name|find
argument_list|(
name|BB
argument_list|)
expr_stmt|;
return|return
name|I
operator|!=
name|IntervalMap
operator|.
name|end
argument_list|()
condition|?
name|I
operator|->
name|second
else|:
literal|0
return|;
block|}
comment|// getAnalysisUsage - Implement the Pass API
name|virtual
name|void
name|getAnalysisUsage
argument_list|(
name|AnalysisUsage
operator|&
name|AU
argument_list|)
decl|const
block|{
name|AU
operator|.
name|setPreservesAll
argument_list|()
expr_stmt|;
block|}
comment|// Interface to Intervals vector...
specifier|const
name|std
operator|::
name|vector
operator|<
name|Interval
operator|*
operator|>
operator|&
name|getIntervals
argument_list|()
specifier|const
block|{
return|return
name|Intervals
return|;
block|}
comment|// releaseMemory - Reset state back to before function was analyzed
name|void
name|releaseMemory
parameter_list|()
function_decl|;
name|private
label|:
comment|// addIntervalToPartition - Add an interval to the internal list of intervals,
comment|// and then add mappings from all of the basic blocks in the interval to the
comment|// interval itself (in the IntervalMap).
comment|//
name|void
name|addIntervalToPartition
parameter_list|(
name|Interval
modifier|*
name|I
parameter_list|)
function_decl|;
comment|// updatePredecessors - Interval generation only sets the successor fields of
comment|// the interval data structures.  After interval generation is complete,
comment|// run through all of the intervals and propagate successor info as
comment|// predecessor info.
comment|//
name|void
name|updatePredecessors
parameter_list|(
name|Interval
modifier|*
name|Int
parameter_list|)
function_decl|;
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

