begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- LatencyPriorityQueue.h - A latency-oriented priority queue ------===//
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
comment|// This file declares the LatencyPriorityQueue class, which is a
end_comment

begin_comment
comment|// SchedulingPriorityQueue that schedules using latency information to
end_comment

begin_comment
comment|// reduce the length of the critical path through the basic block.
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
name|LLVM_CODEGEN_LATENCYPRIORITYQUEUE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_LATENCYPRIORITYQUEUE_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/ScheduleDAG.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|LatencyPriorityQueue
decl_stmt|;
comment|/// Sorting functions for the Available queue.
name|struct
name|latency_sort
range|:
name|public
name|std
operator|::
name|binary_function
operator|<
name|SUnit
operator|*
decl_stmt|,
name|SUnit
modifier|*
decl_stmt|,
name|bool
decl|>
block|{
name|LatencyPriorityQueue
modifier|*
name|PQ
decl_stmt|;
name|explicit
name|latency_sort
argument_list|(
name|LatencyPriorityQueue
operator|*
name|pq
argument_list|)
operator|:
name|PQ
argument_list|(
argument|pq
argument_list|)
block|{}
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|SUnit
operator|*
name|left
operator|,
specifier|const
name|SUnit
operator|*
name|right
operator|)
specifier|const
expr_stmt|;
block|}
empty_stmt|;
name|class
name|LatencyPriorityQueue
range|:
name|public
name|SchedulingPriorityQueue
block|{
comment|// SUnits - The SUnits for the current graph.
name|std
operator|::
name|vector
operator|<
name|SUnit
operator|>
operator|*
name|SUnits
block|;
comment|/// NumNodesSolelyBlocking - This vector contains, for every node in the
comment|/// Queue, the number of nodes that the node is the sole unscheduled
comment|/// predecessor for.  This is used as a tie-breaker heuristic for better
comment|/// mobility.
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|NumNodesSolelyBlocking
block|;
comment|/// Queue - The queue.
name|std
operator|::
name|vector
operator|<
name|SUnit
operator|*
operator|>
name|Queue
block|;
name|latency_sort
name|Picker
block|;
name|public
operator|:
name|LatencyPriorityQueue
argument_list|()
operator|:
name|Picker
argument_list|(
argument|this
argument_list|)
block|{     }
name|bool
name|isBottomUp
argument_list|()
specifier|const
name|override
block|{
return|return
name|false
return|;
block|}
name|void
name|initNodes
argument_list|(
argument|std::vector<SUnit>&sunits
argument_list|)
name|override
block|{
name|SUnits
operator|=
operator|&
name|sunits
block|;
name|NumNodesSolelyBlocking
operator|.
name|resize
argument_list|(
name|SUnits
operator|->
name|size
argument_list|()
argument_list|,
literal|0
argument_list|)
block|;     }
name|void
name|addNode
argument_list|(
argument|const SUnit *SU
argument_list|)
name|override
block|{
name|NumNodesSolelyBlocking
operator|.
name|resize
argument_list|(
name|SUnits
operator|->
name|size
argument_list|()
argument_list|,
literal|0
argument_list|)
block|;     }
name|void
name|updateNode
argument_list|(
argument|const SUnit *SU
argument_list|)
name|override
block|{     }
name|void
name|releaseState
argument_list|()
name|override
block|{
name|SUnits
operator|=
name|nullptr
block|;     }
name|unsigned
name|getLatency
argument_list|(
argument|unsigned NodeNum
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|NodeNum
operator|<
operator|(
operator|*
name|SUnits
operator|)
operator|.
name|size
argument_list|()
argument_list|)
block|;
return|return
operator|(
operator|*
name|SUnits
operator|)
index|[
name|NodeNum
index|]
operator|.
name|getHeight
argument_list|()
return|;
block|}
name|unsigned
name|getNumSolelyBlockNodes
argument_list|(
argument|unsigned NodeNum
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|NodeNum
operator|<
name|NumNodesSolelyBlocking
operator|.
name|size
argument_list|()
argument_list|)
block|;
return|return
name|NumNodesSolelyBlocking
index|[
name|NodeNum
index|]
return|;
block|}
name|bool
name|empty
argument_list|()
specifier|const
name|override
block|{
return|return
name|Queue
operator|.
name|empty
argument_list|()
return|;
block|}
name|void
name|push
argument_list|(
argument|SUnit *U
argument_list|)
name|override
block|;
name|SUnit
operator|*
name|pop
argument_list|()
name|override
block|;
name|void
name|remove
argument_list|(
argument|SUnit *SU
argument_list|)
name|override
block|;
name|void
name|dump
argument_list|(
argument|ScheduleDAG* DAG
argument_list|)
specifier|const
name|override
block|;
comment|// scheduledNode - As nodes are scheduled, we look to see if there are any
comment|// successor nodes that have a single unscheduled predecessor.  If so, that
comment|// single predecessor has a higher priority, since scheduling it will make
comment|// the node available.
name|void
name|scheduledNode
argument_list|(
argument|SUnit *Node
argument_list|)
name|override
block|;
name|private
operator|:
name|void
name|AdjustPriorityOfUnscheduledPreds
argument_list|(
name|SUnit
operator|*
name|SU
argument_list|)
block|;
name|SUnit
operator|*
name|getSingleUnscheduledPred
argument_list|(
name|SUnit
operator|*
name|SU
argument_list|)
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

