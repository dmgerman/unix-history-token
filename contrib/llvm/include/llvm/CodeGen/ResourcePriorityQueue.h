begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----- ResourcePriorityQueue.h - A DFA-oriented priority queue -------===//
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
comment|// This file implements the ResourcePriorityQueue class, which is a
end_comment

begin_comment
comment|// SchedulingPriorityQueue that schedules using DFA state to
end_comment

begin_comment
comment|// reduce the length of the critical path through the basic block
end_comment

begin_comment
comment|// on VLIW platforms.
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
name|LLVM_CODEGEN_RESOURCEPRIORITYQUEUE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_RESOURCEPRIORITYQUEUE_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/DFAPacketizer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ScheduleDAG.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SelectionDAGISel.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCInstrItineraries.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetInstrInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetRegisterInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ResourcePriorityQueue
decl_stmt|;
comment|/// Sorting functions for the Available queue.
name|struct
name|resource_sort
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
name|ResourcePriorityQueue
modifier|*
name|PQ
decl_stmt|;
name|explicit
name|resource_sort
argument_list|(
name|ResourcePriorityQueue
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
name|ResourcePriorityQueue
range|:
name|public
name|SchedulingPriorityQueue
block|{
comment|/// SUnits - The SUnits for the current graph.
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
comment|/// RegPressure - Tracking current reg pressure per register class.
comment|///
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|RegPressure
block|;
comment|/// RegLimit - Tracking the number of allocatable registers per register
comment|/// class.
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|RegLimit
block|;
name|resource_sort
name|Picker
block|;
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
block|;
specifier|const
name|TargetLowering
operator|*
name|TLI
block|;
specifier|const
name|TargetInstrInfo
operator|*
name|TII
block|;
specifier|const
name|InstrItineraryData
operator|*
name|InstrItins
block|;
comment|/// ResourcesModel - Represents VLIW state.
comment|/// Not limited to VLIW targets per say, but assumes
comment|/// definition of DFA by a target.
name|DFAPacketizer
operator|*
name|ResourcesModel
block|;
comment|/// Resource model - packet/bundle model. Purely
comment|/// internal at the time.
name|std
operator|::
name|vector
operator|<
name|SUnit
operator|*
operator|>
name|Packet
block|;
comment|/// Heuristics for estimating register pressure.
name|unsigned
name|ParallelLiveRanges
block|;
name|signed
name|HorizontalVerticalBalance
block|;
name|public
operator|:
name|ResourcePriorityQueue
argument_list|(
name|SelectionDAGISel
operator|*
name|IS
argument_list|)
block|;
operator|~
name|ResourcePriorityQueue
argument_list|()
block|{
name|delete
name|ResourcesModel
block|;     }
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
block|;
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
block|{}
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
comment|/// Single cost function reflecting benefit of scheduling SU
comment|/// in the current cycle.
name|signed
name|SUSchedulingCost
argument_list|(
name|SUnit
operator|*
name|SU
argument_list|)
block|;
comment|/// InitNumRegDefsLeft - Determine the # of regs defined by this node.
comment|///
name|void
name|initNumRegDefsLeft
argument_list|(
name|SUnit
operator|*
name|SU
argument_list|)
block|;
name|void
name|updateNumRegDefsLeft
argument_list|(
name|SUnit
operator|*
name|SU
argument_list|)
block|;
name|signed
name|regPressureDelta
argument_list|(
argument|SUnit *SU
argument_list|,
argument|bool RawPressure = false
argument_list|)
block|;
name|signed
name|rawRegPressureDelta
argument_list|(
argument|SUnit *SU
argument_list|,
argument|unsigned RCId
argument_list|)
block|;
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
comment|/// scheduledNode - Main resource tracking point.
name|void
name|scheduledNode
argument_list|(
argument|SUnit *Node
argument_list|)
name|override
block|;
name|bool
name|isResourceAvailable
argument_list|(
name|SUnit
operator|*
name|SU
argument_list|)
block|;
name|void
name|reserveResources
argument_list|(
name|SUnit
operator|*
name|SU
argument_list|)
block|;
name|private
operator|:
name|void
name|adjustPriorityOfUnscheduledPreds
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
block|;
name|unsigned
name|numberRCValPredInSU
argument_list|(
argument|SUnit *SU
argument_list|,
argument|unsigned RCId
argument_list|)
block|;
name|unsigned
name|numberRCValSuccInSU
argument_list|(
argument|SUnit *SU
argument_list|,
argument|unsigned RCId
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

