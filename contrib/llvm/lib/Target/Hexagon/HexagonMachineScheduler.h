begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- HexagonMachineScheduler.h - Custom Hexagon MI scheduler.      ----===//
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
comment|// Custom Hexagon MI scheduler.
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
name|LLVM_LIB_TARGET_HEXAGON_HEXAGONMACHINESCHEDULER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_HEXAGON_HEXAGONMACHINESCHEDULER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/PriorityQueue.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/AliasAnalysis.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/LiveIntervalAnalysis.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineScheduler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/Passes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/RegisterClassInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/RegisterPressure.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ResourcePriorityQueue.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ScheduleDAGInstrs.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ScheduleHazardRecognizer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Debug.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetInstrInfo.h"
end_include

begin_decl_stmt
name|using
name|namespace
name|llvm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|VLIWResourceModel
block|{
comment|/// ResourcesModel - Represents VLIW state.
comment|/// Not limited to VLIW targets per se, but assumes
comment|/// definition of DFA by a target.
name|DFAPacketizer
modifier|*
name|ResourcesModel
decl_stmt|;
specifier|const
name|TargetSchedModel
modifier|*
name|SchedModel
decl_stmt|;
comment|/// Local packet/bundle model. Purely
comment|/// internal to the MI schedulre at the time.
name|std
operator|::
name|vector
operator|<
name|SUnit
operator|*
operator|>
name|Packet
expr_stmt|;
comment|/// Total packets created.
name|unsigned
name|TotalPackets
decl_stmt|;
name|public
label|:
comment|/// Save the last formed packet.
name|std
operator|::
name|vector
operator|<
name|SUnit
operator|*
operator|>
name|OldPacket
expr_stmt|;
name|public
label|:
name|VLIWResourceModel
argument_list|(
specifier|const
name|TargetSubtargetInfo
operator|&
name|STI
argument_list|,
specifier|const
name|TargetSchedModel
operator|*
name|SM
argument_list|)
operator|:
name|SchedModel
argument_list|(
name|SM
argument_list|)
operator|,
name|TotalPackets
argument_list|(
literal|0
argument_list|)
block|{
name|ResourcesModel
operator|=
name|STI
operator|.
name|getInstrInfo
argument_list|()
operator|->
name|CreateTargetScheduleState
argument_list|(
name|STI
argument_list|)
block|;
comment|// This hard requirement could be relaxed,
comment|// but for now do not let it proceed.
name|assert
argument_list|(
name|ResourcesModel
operator|&&
literal|"Unimplemented CreateTargetScheduleState."
argument_list|)
block|;
name|Packet
operator|.
name|resize
argument_list|(
name|SchedModel
operator|->
name|getIssueWidth
argument_list|()
argument_list|)
block|;
name|Packet
operator|.
name|clear
argument_list|()
block|;
name|OldPacket
operator|.
name|resize
argument_list|(
name|SchedModel
operator|->
name|getIssueWidth
argument_list|()
argument_list|)
block|;
name|OldPacket
operator|.
name|clear
argument_list|()
block|;
name|ResourcesModel
operator|->
name|clearResources
argument_list|()
block|;   }
operator|~
name|VLIWResourceModel
argument_list|()
block|{
name|delete
name|ResourcesModel
block|;   }
name|void
name|resetPacketState
argument_list|()
block|{
name|Packet
operator|.
name|clear
argument_list|()
block|;   }
name|void
name|resetDFA
argument_list|()
block|{
name|ResourcesModel
operator|->
name|clearResources
argument_list|()
block|;   }
name|void
name|reset
argument_list|()
block|{
name|Packet
operator|.
name|clear
argument_list|()
block|;
name|ResourcesModel
operator|->
name|clearResources
argument_list|()
block|;   }
name|bool
name|isResourceAvailable
argument_list|(
name|SUnit
operator|*
name|SU
argument_list|)
expr_stmt|;
name|bool
name|reserveResources
parameter_list|(
name|SUnit
modifier|*
name|SU
parameter_list|)
function_decl|;
name|void
name|savePacket
parameter_list|()
function_decl|;
name|unsigned
name|getTotalPackets
argument_list|()
specifier|const
block|{
return|return
name|TotalPackets
return|;
block|}
name|bool
name|isInPacket
argument_list|(
name|SUnit
operator|*
name|SU
argument_list|)
decl|const
block|{
return|return
name|is_contained
argument_list|(
name|Packet
argument_list|,
name|SU
argument_list|)
return|;
block|}
block|}
empty_stmt|;
comment|/// Extend the standard ScheduleDAGMI to provide more context and override the
comment|/// top-level schedule() driver.
name|class
name|VLIWMachineScheduler
range|:
name|public
name|ScheduleDAGMILive
block|{
name|public
operator|:
name|VLIWMachineScheduler
argument_list|(
name|MachineSchedContext
operator|*
name|C
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|MachineSchedStrategy
operator|>
name|S
argument_list|)
operator|:
name|ScheduleDAGMILive
argument_list|(
argument|C
argument_list|,
argument|std::move(S)
argument_list|)
block|{}
comment|/// Schedule - This is called back from ScheduleDAGInstrs::Run() when it's
comment|/// time to do some work.
name|void
name|schedule
argument_list|()
name|override
block|; }
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|// ConvergingVLIWScheduler - Implementation of the standard
comment|// MachineSchedStrategy.
comment|//===----------------------------------------------------------------------===//
comment|/// ConvergingVLIWScheduler shrinks the unscheduled zone using heuristics
comment|/// to balance the schedule.
name|class
name|ConvergingVLIWScheduler
range|:
name|public
name|MachineSchedStrategy
block|{
comment|/// Store the state used by ConvergingVLIWScheduler heuristics, required
comment|///  for the lifetime of one invocation of pickNode().
block|struct
name|SchedCandidate
block|{
comment|// The best SUnit candidate.
name|SUnit
operator|*
name|SU
block|;
comment|// Register pressure values for the best candidate.
name|RegPressureDelta
name|RPDelta
block|;
comment|// Best scheduling cost.
name|int
name|SCost
block|;
name|SchedCandidate
argument_list|()
operator|:
name|SU
argument_list|(
name|nullptr
argument_list|)
block|,
name|SCost
argument_list|(
literal|0
argument_list|)
block|{}
block|}
block|;
comment|/// Represent the type of SchedCandidate found within a single queue.
block|enum
name|CandResult
block|{
name|NoCand
block|,
name|NodeOrder
block|,
name|SingleExcess
block|,
name|SingleCritical
block|,
name|SingleMax
block|,
name|MultiPressure
block|,
name|BestCost
block|}
block|;
comment|/// Each Scheduling boundary is associated with ready queues. It tracks the
comment|/// current cycle in whichever direction at has moved, and maintains the state
comment|/// of "hazards" and other interlocks at the current cycle.
block|struct
name|VLIWSchedBoundary
block|{
name|VLIWMachineScheduler
operator|*
name|DAG
block|;
specifier|const
name|TargetSchedModel
operator|*
name|SchedModel
block|;
name|ReadyQueue
name|Available
block|;
name|ReadyQueue
name|Pending
block|;
name|bool
name|CheckPending
block|;
name|ScheduleHazardRecognizer
operator|*
name|HazardRec
block|;
name|VLIWResourceModel
operator|*
name|ResourceModel
block|;
name|unsigned
name|CurrCycle
block|;
name|unsigned
name|IssueCount
block|;
comment|/// MinReadyCycle - Cycle of the soonest available instruction.
name|unsigned
name|MinReadyCycle
block|;
comment|// Remember the greatest min operand latency.
name|unsigned
name|MaxMinLatency
block|;
comment|/// Pending queues extend the ready queues with the same ID and the
comment|/// PendingFlag set.
name|VLIWSchedBoundary
argument_list|(
argument|unsigned ID
argument_list|,
argument|const Twine&Name
argument_list|)
operator|:
name|DAG
argument_list|(
name|nullptr
argument_list|)
block|,
name|SchedModel
argument_list|(
name|nullptr
argument_list|)
block|,
name|Available
argument_list|(
name|ID
argument_list|,
name|Name
operator|+
literal|".A"
argument_list|)
block|,
name|Pending
argument_list|(
name|ID
operator|<<
name|ConvergingVLIWScheduler
operator|::
name|LogMaxQID
argument_list|,
name|Name
operator|+
literal|".P"
argument_list|)
block|,
name|CheckPending
argument_list|(
name|false
argument_list|)
block|,
name|HazardRec
argument_list|(
name|nullptr
argument_list|)
block|,
name|ResourceModel
argument_list|(
name|nullptr
argument_list|)
block|,
name|CurrCycle
argument_list|(
literal|0
argument_list|)
block|,
name|IssueCount
argument_list|(
literal|0
argument_list|)
block|,
name|MinReadyCycle
argument_list|(
name|UINT_MAX
argument_list|)
block|,
name|MaxMinLatency
argument_list|(
literal|0
argument_list|)
block|{}
operator|~
name|VLIWSchedBoundary
argument_list|()
block|{
name|delete
name|ResourceModel
block|;
name|delete
name|HazardRec
block|;     }
name|void
name|init
argument_list|(
argument|VLIWMachineScheduler *dag
argument_list|,
argument|const TargetSchedModel *smodel
argument_list|)
block|{
name|DAG
operator|=
name|dag
block|;
name|SchedModel
operator|=
name|smodel
block|;
name|IssueCount
operator|=
literal|0
block|;     }
name|bool
name|isTop
argument_list|()
specifier|const
block|{
return|return
name|Available
operator|.
name|getID
argument_list|()
operator|==
name|ConvergingVLIWScheduler
operator|::
name|TopQID
return|;
block|}
name|bool
name|checkHazard
argument_list|(
name|SUnit
operator|*
name|SU
argument_list|)
block|;
name|void
name|releaseNode
argument_list|(
argument|SUnit *SU
argument_list|,
argument|unsigned ReadyCycle
argument_list|)
block|;
name|void
name|bumpCycle
argument_list|()
block|;
name|void
name|bumpNode
argument_list|(
name|SUnit
operator|*
name|SU
argument_list|)
block|;
name|void
name|releasePending
argument_list|()
block|;
name|void
name|removeReady
argument_list|(
name|SUnit
operator|*
name|SU
argument_list|)
block|;
name|SUnit
operator|*
name|pickOnlyChoice
argument_list|()
block|;   }
block|;
name|VLIWMachineScheduler
operator|*
name|DAG
block|;
specifier|const
name|TargetSchedModel
operator|*
name|SchedModel
block|;
comment|// State of the top and bottom scheduled instruction boundaries.
name|VLIWSchedBoundary
name|Top
block|;
name|VLIWSchedBoundary
name|Bot
block|;
name|public
operator|:
comment|/// SUnit::NodeQueueId: 0 (none), 1 (top), 2 (bot), 3 (both)
expr|enum
block|{
name|TopQID
operator|=
literal|1
block|,
name|BotQID
operator|=
literal|2
block|,
name|LogMaxQID
operator|=
literal|2
block|}
block|;
name|ConvergingVLIWScheduler
argument_list|()
operator|:
name|DAG
argument_list|(
name|nullptr
argument_list|)
block|,
name|SchedModel
argument_list|(
name|nullptr
argument_list|)
block|,
name|Top
argument_list|(
name|TopQID
argument_list|,
literal|"TopQ"
argument_list|)
block|,
name|Bot
argument_list|(
argument|BotQID
argument_list|,
literal|"BotQ"
argument_list|)
block|{}
name|void
name|initialize
argument_list|(
argument|ScheduleDAGMI *dag
argument_list|)
name|override
block|;
name|SUnit
operator|*
name|pickNode
argument_list|(
argument|bool&IsTopNode
argument_list|)
name|override
block|;
name|void
name|schedNode
argument_list|(
argument|SUnit *SU
argument_list|,
argument|bool IsTopNode
argument_list|)
name|override
block|;
name|void
name|releaseTopNode
argument_list|(
argument|SUnit *SU
argument_list|)
name|override
block|;
name|void
name|releaseBottomNode
argument_list|(
argument|SUnit *SU
argument_list|)
name|override
block|;
name|unsigned
name|ReportPackets
argument_list|()
block|{
return|return
name|Top
operator|.
name|ResourceModel
operator|->
name|getTotalPackets
argument_list|()
operator|+
name|Bot
operator|.
name|ResourceModel
operator|->
name|getTotalPackets
argument_list|()
return|;
block|}
name|protected
operator|:
name|SUnit
operator|*
name|pickNodeBidrectional
argument_list|(
name|bool
operator|&
name|IsTopNode
argument_list|)
block|;
name|int
name|SchedulingCost
argument_list|(
argument|ReadyQueue&Q
argument_list|,
argument|SUnit *SU
argument_list|,
argument|SchedCandidate&Candidate
argument_list|,
argument|RegPressureDelta&Delta
argument_list|,
argument|bool verbose
argument_list|)
block|;
name|CandResult
name|pickNodeFromQueue
argument_list|(
name|ReadyQueue
operator|&
name|Q
argument_list|,
specifier|const
name|RegPressureTracker
operator|&
name|RPTracker
argument_list|,
name|SchedCandidate
operator|&
name|Candidate
argument_list|)
block|;
ifndef|#
directive|ifndef
name|NDEBUG
name|void
name|traceCandidate
argument_list|(
argument|const char *Label
argument_list|,
argument|const ReadyQueue&Q
argument_list|,
argument|SUnit *SU
argument_list|,
argument|int Cost
argument_list|,
argument|PressureChange P = PressureChange()
argument_list|)
block|;
name|void
name|readyQueueVerboseDump
argument_list|(
specifier|const
name|RegPressureTracker
operator|&
name|RPTracker
argument_list|,
name|SchedCandidate
operator|&
name|Candidate
argument_list|,
name|ReadyQueue
operator|&
name|Q
argument_list|)
block|;
endif|#
directive|endif
block|}
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

