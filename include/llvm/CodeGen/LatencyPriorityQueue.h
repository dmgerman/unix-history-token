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
name|LATENCY_PRIORITY_QUEUE_H
end_ifndef

begin_define
define|#
directive|define
name|LATENCY_PRIORITY_QUEUE_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/ScheduleDAG.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PriorityQueue.h"
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
comment|/// IgnoreAntiDep - Ignore anti-dependencies
name|bool
name|IgnoreAntiDep
block|;
comment|/// Queue - The queue.
name|PriorityQueue
operator|<
name|SUnit
operator|*
block|,
name|std
operator|::
name|vector
operator|<
name|SUnit
operator|*
operator|>
block|,
name|latency_sort
operator|>
name|Queue
block|;
name|public
operator|:
name|LatencyPriorityQueue
argument_list|()
operator|:
name|IgnoreAntiDep
argument_list|(
name|false
argument_list|)
block|,
name|Queue
argument_list|(
argument|latency_sort(this)
argument_list|)
block|{     }
name|void
name|setIgnoreAntiDep
argument_list|(
argument|bool ignore
argument_list|)
block|{
name|IgnoreAntiDep
operator|=
name|ignore
block|;     }
name|void
name|initNodes
argument_list|(
argument|std::vector<SUnit>&sunits
argument_list|)
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
block|{     }
name|void
name|releaseState
argument_list|()
block|{
name|SUnits
operator|=
literal|0
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
argument_list|(
name|IgnoreAntiDep
argument_list|)
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
name|unsigned
name|size
argument_list|()
specifier|const
block|{
return|return
name|Queue
operator|.
name|size
argument_list|()
return|;
block|}
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|Queue
operator|.
name|empty
argument_list|()
return|;
block|}
name|virtual
name|void
name|push
argument_list|(
argument|SUnit *U
argument_list|)
block|{
name|push_impl
argument_list|(
name|U
argument_list|)
block|;     }
name|void
name|push_impl
argument_list|(
name|SUnit
operator|*
name|U
argument_list|)
block|;
name|void
name|push_all
argument_list|(
argument|const std::vector<SUnit *>&Nodes
argument_list|)
block|{
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|,
name|e
init|=
name|Nodes
operator|.
name|size
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
name|push_impl
argument_list|(
name|Nodes
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
name|SUnit
operator|*
name|pop
argument_list|()
block|{
if|if
condition|(
name|empty
argument_list|()
condition|)
return|return
name|NULL
return|;
name|SUnit
operator|*
name|V
operator|=
name|Queue
operator|.
name|top
argument_list|()
block|;
name|Queue
operator|.
name|pop
argument_list|()
block|;
return|return
name|V
return|;
block|}
name|void
name|remove
parameter_list|(
name|SUnit
modifier|*
name|SU
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|Queue
operator|.
name|empty
argument_list|()
operator|&&
literal|"Not in queue!"
argument_list|)
expr_stmt|;
name|Queue
operator|.
name|erase_one
argument_list|(
name|SU
argument_list|)
expr_stmt|;
block|}
comment|// ScheduledNode - As nodes are scheduled, we look to see if there are any
comment|// successor nodes that have a single unscheduled predecessor.  If so, that
comment|// single predecessor has a higher priority, since scheduling it will make
comment|// the node available.
name|void
name|ScheduledNode
parameter_list|(
name|SUnit
modifier|*
name|Node
parameter_list|)
function_decl|;
name|private
label|:
name|void
name|AdjustPriorityOfUnscheduledPreds
parameter_list|(
name|SUnit
modifier|*
name|SU
parameter_list|)
function_decl|;
name|SUnit
modifier|*
name|getSingleUnscheduledPred
parameter_list|(
name|SUnit
modifier|*
name|SU
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

