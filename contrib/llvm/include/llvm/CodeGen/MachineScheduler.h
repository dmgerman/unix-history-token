begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- MachineScheduler.h - MachineInstr Scheduling Pass ----------*- C++ -*-==//
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
comment|// This file provides a MachineSchedRegistry for registering alternative machine
end_comment

begin_comment
comment|// schedulers. A Target may provide an alternative scheduler implementation by
end_comment

begin_comment
comment|// implementing the following boilerplate:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// static ScheduleDAGInstrs *createCustomMachineSched(MachineSchedContext *C) {
end_comment

begin_comment
comment|//  return new CustomMachineScheduler(C);
end_comment

begin_comment
comment|// }
end_comment

begin_comment
comment|// static MachineSchedRegistry
end_comment

begin_comment
comment|// SchedCustomRegistry("custom", "Run my target's custom scheduler",
end_comment

begin_comment
comment|//                     createCustomMachineSched);
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Inside<Target>PassConfig:
end_comment

begin_comment
comment|//   enablePass(&MachineSchedulerID);
end_comment

begin_comment
comment|//   MachineSchedRegistry::setDefault(createCustomMachineSched);
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
name|MACHINESCHEDULER_H
end_ifndef

begin_define
define|#
directive|define
name|MACHINESCHEDULER_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachinePassRegistry.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/RegisterPressure.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ScheduleDAGInstrs.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetInstrInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
extern|extern cl::opt<bool> ForceTopDown;
extern|extern cl::opt<bool> ForceBottomUp;
name|class
name|AliasAnalysis
decl_stmt|;
name|class
name|LiveIntervals
decl_stmt|;
name|class
name|MachineDominatorTree
decl_stmt|;
name|class
name|MachineLoopInfo
decl_stmt|;
name|class
name|RegisterClassInfo
decl_stmt|;
name|class
name|ScheduleDAGInstrs
decl_stmt|;
comment|/// MachineSchedContext provides enough context from the MachineScheduler pass
comment|/// for the target to instantiate a scheduler.
struct|struct
name|MachineSchedContext
block|{
name|MachineFunction
modifier|*
name|MF
decl_stmt|;
specifier|const
name|MachineLoopInfo
modifier|*
name|MLI
decl_stmt|;
specifier|const
name|MachineDominatorTree
modifier|*
name|MDT
decl_stmt|;
specifier|const
name|TargetPassConfig
modifier|*
name|PassConfig
decl_stmt|;
name|AliasAnalysis
modifier|*
name|AA
decl_stmt|;
name|LiveIntervals
modifier|*
name|LIS
decl_stmt|;
name|RegisterClassInfo
modifier|*
name|RegClassInfo
decl_stmt|;
name|MachineSchedContext
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|MachineSchedContext
argument_list|()
expr_stmt|;
block|}
struct|;
comment|/// MachineSchedRegistry provides a selection of available machine instruction
comment|/// schedulers.
name|class
name|MachineSchedRegistry
range|:
name|public
name|MachinePassRegistryNode
block|{
name|public
operator|:
typedef|typedef
name|ScheduleDAGInstrs
modifier|*
function_decl|(
modifier|*
name|ScheduleDAGCtor
function_decl|)
parameter_list|(
name|MachineSchedContext
modifier|*
parameter_list|)
function_decl|;
comment|// RegisterPassParser requires a (misnamed) FunctionPassCtor type.
typedef|typedef
name|ScheduleDAGCtor
name|FunctionPassCtor
typedef|;
specifier|static
name|MachinePassRegistry
name|Registry
decl_stmt|;
name|MachineSchedRegistry
argument_list|(
argument|const char *N
argument_list|,
argument|const char *D
argument_list|,
argument|ScheduleDAGCtor C
argument_list|)
block|:
name|MachinePassRegistryNode
argument_list|(
argument|N
argument_list|,
argument|D
argument_list|,
argument|(MachinePassCtor)C
argument_list|)
block|{
name|Registry
operator|.
name|Add
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
operator|~
name|MachineSchedRegistry
argument_list|()
block|{
name|Registry
operator|.
name|Remove
argument_list|(
name|this
argument_list|)
block|; }
comment|// Accessors.
comment|//
name|MachineSchedRegistry
operator|*
name|getNext
argument_list|()
specifier|const
block|{
return|return
operator|(
name|MachineSchedRegistry
operator|*
operator|)
name|MachinePassRegistryNode
operator|::
name|getNext
argument_list|()
return|;
block|}
specifier|static
name|MachineSchedRegistry
modifier|*
name|getList
parameter_list|()
block|{
return|return
operator|(
name|MachineSchedRegistry
operator|*
operator|)
name|Registry
operator|.
name|getList
argument_list|()
return|;
block|}
specifier|static
name|ScheduleDAGCtor
name|getDefault
parameter_list|()
block|{
return|return
operator|(
name|ScheduleDAGCtor
operator|)
name|Registry
operator|.
name|getDefault
argument_list|()
return|;
block|}
specifier|static
name|void
name|setDefault
parameter_list|(
name|ScheduleDAGCtor
name|C
parameter_list|)
block|{
name|Registry
operator|.
name|setDefault
argument_list|(
operator|(
name|MachinePassCtor
operator|)
name|C
argument_list|)
expr_stmt|;
block|}
specifier|static
name|void
name|setDefault
parameter_list|(
name|StringRef
name|Name
parameter_list|)
block|{
name|Registry
operator|.
name|setDefault
argument_list|(
name|Name
argument_list|)
expr_stmt|;
block|}
specifier|static
name|void
name|setListener
parameter_list|(
name|MachinePassRegistryListener
modifier|*
name|L
parameter_list|)
block|{
name|Registry
operator|.
name|setListener
argument_list|(
name|L
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|ScheduleDAGMI
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// MachineSchedStrategy - Interface to the scheduling algorithm used by
end_comment

begin_comment
comment|/// ScheduleDAGMI.
end_comment

begin_decl_stmt
name|class
name|MachineSchedStrategy
block|{
name|public
label|:
name|virtual
operator|~
name|MachineSchedStrategy
argument_list|()
block|{}
comment|/// Initialize the strategy after building the DAG for a new region.
name|virtual
name|void
name|initialize
argument_list|(
name|ScheduleDAGMI
operator|*
name|DAG
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|/// Notify this strategy that all roots have been released (including those
comment|/// that depend on EntrySU or ExitSU).
name|virtual
name|void
name|registerRoots
parameter_list|()
block|{}
comment|/// Pick the next node to schedule, or return NULL. Set IsTopNode to true to
comment|/// schedule the node at the top of the unscheduled region. Otherwise it will
comment|/// be scheduled at the bottom.
name|virtual
name|SUnit
modifier|*
name|pickNode
parameter_list|(
name|bool
modifier|&
name|IsTopNode
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Notify MachineSchedStrategy that ScheduleDAGMI has scheduled an
comment|/// instruction and updated scheduled/remaining flags in the DAG nodes.
name|virtual
name|void
name|schedNode
parameter_list|(
name|SUnit
modifier|*
name|SU
parameter_list|,
name|bool
name|IsTopNode
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// When all predecessor dependencies have been resolved, free this node for
comment|/// top-down scheduling.
name|virtual
name|void
name|releaseTopNode
parameter_list|(
name|SUnit
modifier|*
name|SU
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// When all successor dependencies have been resolved, free this node for
comment|/// bottom-up scheduling.
name|virtual
name|void
name|releaseBottomNode
parameter_list|(
name|SUnit
modifier|*
name|SU
parameter_list|)
init|=
literal|0
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// ReadyQueue encapsulates vector of "ready" SUnits with basic convenience
end_comment

begin_comment
comment|/// methods for pushing and removing nodes. ReadyQueue's are uniquely identified
end_comment

begin_comment
comment|/// by an ID. SUnit::NodeQueueId is a mask of the ReadyQueues the SUnit is in.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is a convenience class that may be used by implementations of
end_comment

begin_comment
comment|/// MachineSchedStrategy.
end_comment

begin_decl_stmt
name|class
name|ReadyQueue
block|{
name|unsigned
name|ID
decl_stmt|;
name|std
operator|::
name|string
name|Name
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|SUnit
operator|*
operator|>
name|Queue
expr_stmt|;
name|public
label|:
name|ReadyQueue
argument_list|(
argument|unsigned id
argument_list|,
argument|const Twine&name
argument_list|)
block|:
name|ID
argument_list|(
name|id
argument_list|)
operator|,
name|Name
argument_list|(
argument|name.str()
argument_list|)
block|{}
name|unsigned
name|getID
argument_list|()
specifier|const
block|{
return|return
name|ID
return|;
block|}
name|StringRef
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
comment|// SU is in this queue if it's NodeQueueID is a superset of this ID.
name|bool
name|isInQueue
argument_list|(
name|SUnit
operator|*
name|SU
argument_list|)
decl|const
block|{
return|return
operator|(
name|SU
operator|->
name|NodeQueueId
operator|&
name|ID
operator|)
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
name|void
name|clear
parameter_list|()
block|{
name|Queue
operator|.
name|clear
argument_list|()
expr_stmt|;
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
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|SUnit
operator|*
operator|>
operator|::
name|iterator
name|iterator
expr_stmt|;
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|Queue
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|end
parameter_list|()
block|{
return|return
name|Queue
operator|.
name|end
argument_list|()
return|;
block|}
name|iterator
name|find
parameter_list|(
name|SUnit
modifier|*
name|SU
parameter_list|)
block|{
return|return
name|std
operator|::
name|find
argument_list|(
name|Queue
operator|.
name|begin
argument_list|()
argument_list|,
name|Queue
operator|.
name|end
argument_list|()
argument_list|,
name|SU
argument_list|)
return|;
block|}
name|void
name|push
parameter_list|(
name|SUnit
modifier|*
name|SU
parameter_list|)
block|{
name|Queue
operator|.
name|push_back
argument_list|(
name|SU
argument_list|)
expr_stmt|;
name|SU
operator|->
name|NodeQueueId
operator||=
name|ID
expr_stmt|;
block|}
name|iterator
name|remove
parameter_list|(
name|iterator
name|I
parameter_list|)
block|{
operator|(
operator|*
name|I
operator|)
operator|->
name|NodeQueueId
operator|&=
operator|~
name|ID
expr_stmt|;
operator|*
name|I
operator|=
name|Queue
operator|.
name|back
argument_list|()
expr_stmt|;
name|unsigned
name|idx
init|=
name|I
operator|-
name|Queue
operator|.
name|begin
argument_list|()
decl_stmt|;
name|Queue
operator|.
name|pop_back
argument_list|()
expr_stmt|;
return|return
name|Queue
operator|.
name|begin
argument_list|()
operator|+
name|idx
return|;
block|}
ifndef|#
directive|ifndef
name|NDEBUG
name|void
name|dump
parameter_list|()
function_decl|;
endif|#
directive|endif
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// Mutate the DAG as a postpass after normal DAG building.
end_comment

begin_decl_stmt
name|class
name|ScheduleDAGMutation
block|{
name|public
label|:
name|virtual
operator|~
name|ScheduleDAGMutation
argument_list|()
block|{}
name|virtual
name|void
name|apply
argument_list|(
name|ScheduleDAGMI
operator|*
name|DAG
argument_list|)
operator|=
literal|0
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// ScheduleDAGMI is an implementation of ScheduleDAGInstrs that schedules
end_comment

begin_comment
comment|/// machine instructions while updating LiveIntervals and tracking regpressure.
end_comment

begin_decl_stmt
name|class
name|ScheduleDAGMI
range|:
name|public
name|ScheduleDAGInstrs
block|{
name|protected
operator|:
name|AliasAnalysis
operator|*
name|AA
block|;
name|RegisterClassInfo
operator|*
name|RegClassInfo
block|;
name|MachineSchedStrategy
operator|*
name|SchedImpl
block|;
comment|/// Ordered list of DAG postprocessing steps.
name|std
operator|::
name|vector
operator|<
name|ScheduleDAGMutation
operator|*
operator|>
name|Mutations
block|;
name|MachineBasicBlock
operator|::
name|iterator
name|LiveRegionEnd
block|;
comment|/// Register pressure in this region computed by buildSchedGraph.
name|IntervalPressure
name|RegPressure
block|;
name|RegPressureTracker
name|RPTracker
block|;
comment|/// List of pressure sets that exceed the target's pressure limit before
comment|/// scheduling, listed in increasing set ID order. Each pressure set is paired
comment|/// with its max pressure in the currently scheduled regions.
name|std
operator|::
name|vector
operator|<
name|PressureElement
operator|>
name|RegionCriticalPSets
block|;
comment|/// The top of the unscheduled zone.
name|MachineBasicBlock
operator|::
name|iterator
name|CurrentTop
block|;
name|IntervalPressure
name|TopPressure
block|;
name|RegPressureTracker
name|TopRPTracker
block|;
comment|/// The bottom of the unscheduled zone.
name|MachineBasicBlock
operator|::
name|iterator
name|CurrentBottom
block|;
name|IntervalPressure
name|BotPressure
block|;
name|RegPressureTracker
name|BotRPTracker
block|;
ifndef|#
directive|ifndef
name|NDEBUG
comment|/// The number of instructions scheduled so far. Used to cut off the
comment|/// scheduler at the point determined by misched-cutoff.
name|unsigned
name|NumInstrsScheduled
block|;
endif|#
directive|endif
name|public
operator|:
name|ScheduleDAGMI
argument_list|(
name|MachineSchedContext
operator|*
name|C
argument_list|,
name|MachineSchedStrategy
operator|*
name|S
argument_list|)
operator|:
name|ScheduleDAGInstrs
argument_list|(
operator|*
name|C
operator|->
name|MF
argument_list|,
operator|*
name|C
operator|->
name|MLI
argument_list|,
operator|*
name|C
operator|->
name|MDT
argument_list|,
comment|/*IsPostRA=*/
name|false
argument_list|,
name|C
operator|->
name|LIS
argument_list|)
block|,
name|AA
argument_list|(
name|C
operator|->
name|AA
argument_list|)
block|,
name|RegClassInfo
argument_list|(
name|C
operator|->
name|RegClassInfo
argument_list|)
block|,
name|SchedImpl
argument_list|(
name|S
argument_list|)
block|,
name|RPTracker
argument_list|(
name|RegPressure
argument_list|)
block|,
name|CurrentTop
argument_list|()
block|,
name|TopRPTracker
argument_list|(
name|TopPressure
argument_list|)
block|,
name|CurrentBottom
argument_list|()
block|,
name|BotRPTracker
argument_list|(
argument|BotPressure
argument_list|)
block|{
ifndef|#
directive|ifndef
name|NDEBUG
name|NumInstrsScheduled
operator|=
literal|0
block|;
endif|#
directive|endif
block|}
name|virtual
operator|~
name|ScheduleDAGMI
argument_list|()
block|{
name|delete
name|SchedImpl
block|;   }
comment|/// Add a postprocessing step to the DAG builder.
comment|/// Mutations are applied in the order that they are added after normal DAG
comment|/// building and before MachineSchedStrategy initialization.
name|void
name|addMutation
argument_list|(
argument|ScheduleDAGMutation *Mutation
argument_list|)
block|{
name|Mutations
operator|.
name|push_back
argument_list|(
name|Mutation
argument_list|)
block|;   }
name|MachineBasicBlock
operator|::
name|iterator
name|top
argument_list|()
specifier|const
block|{
return|return
name|CurrentTop
return|;
block|}
name|MachineBasicBlock
operator|::
name|iterator
name|bottom
argument_list|()
specifier|const
block|{
return|return
name|CurrentBottom
return|;
block|}
comment|/// Implement the ScheduleDAGInstrs interface for handling the next scheduling
comment|/// region. This covers all instructions in a block, while schedule() may only
comment|/// cover a subset.
name|void
name|enterRegion
argument_list|(
argument|MachineBasicBlock *bb
argument_list|,
argument|MachineBasicBlock::iterator begin
argument_list|,
argument|MachineBasicBlock::iterator end
argument_list|,
argument|unsigned endcount
argument_list|)
block|;
comment|/// Implement ScheduleDAGInstrs interface for scheduling a sequence of
comment|/// reorderable instructions.
name|virtual
name|void
name|schedule
argument_list|()
block|;
comment|/// Get current register pressure for the top scheduled instructions.
specifier|const
name|IntervalPressure
operator|&
name|getTopPressure
argument_list|()
specifier|const
block|{
return|return
name|TopPressure
return|;
block|}
specifier|const
name|RegPressureTracker
operator|&
name|getTopRPTracker
argument_list|()
specifier|const
block|{
return|return
name|TopRPTracker
return|;
block|}
comment|/// Get current register pressure for the bottom scheduled instructions.
specifier|const
name|IntervalPressure
operator|&
name|getBotPressure
argument_list|()
specifier|const
block|{
return|return
name|BotPressure
return|;
block|}
specifier|const
name|RegPressureTracker
operator|&
name|getBotRPTracker
argument_list|()
specifier|const
block|{
return|return
name|BotRPTracker
return|;
block|}
comment|/// Get register pressure for the entire scheduling region before scheduling.
specifier|const
name|IntervalPressure
operator|&
name|getRegPressure
argument_list|()
specifier|const
block|{
return|return
name|RegPressure
return|;
block|}
specifier|const
name|std
operator|::
name|vector
operator|<
name|PressureElement
operator|>
operator|&
name|getRegionCriticalPSets
argument_list|()
specifier|const
block|{
return|return
name|RegionCriticalPSets
return|;
block|}
name|protected
operator|:
comment|// Top-Level entry points for the schedule() driver...
comment|/// Call ScheduleDAGInstrs::buildSchedGraph with register pressure tracking
comment|/// enabled. This sets up three trackers. RPTracker will cover the entire DAG
comment|/// region, TopTracker and BottomTracker will be initialized to the top and
comment|/// bottom of the DAG region without covereing any unscheduled instruction.
name|void
name|buildDAGWithRegPressure
argument_list|()
block|;
comment|/// Apply each ScheduleDAGMutation step in order. This allows different
comment|/// instances of ScheduleDAGMI to perform custom DAG postprocessing.
name|void
name|postprocessDAG
argument_list|()
block|;
comment|/// Identify DAG roots and setup scheduler queues.
name|void
name|initQueues
argument_list|()
block|;
comment|/// Move an instruction and update register pressure.
name|void
name|scheduleMI
argument_list|(
argument|SUnit *SU
argument_list|,
argument|bool IsTopNode
argument_list|)
block|;
comment|/// Update scheduler DAG and queues after scheduling an instruction.
name|void
name|updateQueues
argument_list|(
argument|SUnit *SU
argument_list|,
argument|bool IsTopNode
argument_list|)
block|;
comment|/// Reinsert debug_values recorded in ScheduleDAGInstrs::DbgValues.
name|void
name|placeDebugValues
argument_list|()
block|;
comment|/// \brief dump the scheduled Sequence.
name|void
name|dumpSchedule
argument_list|()
specifier|const
block|;
comment|// Lesser helpers...
name|void
name|initRegPressure
argument_list|()
block|;
name|void
name|updateScheduledPressure
argument_list|(
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|NewMaxPressure
argument_list|)
block|;
name|void
name|moveInstruction
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock::iterator InsertPos
argument_list|)
block|;
name|bool
name|checkSchedLimit
argument_list|()
block|;
name|void
name|releaseRoots
argument_list|()
block|;
name|void
name|releaseSucc
argument_list|(
name|SUnit
operator|*
name|SU
argument_list|,
name|SDep
operator|*
name|SuccEdge
argument_list|)
block|;
name|void
name|releaseSuccessors
argument_list|(
name|SUnit
operator|*
name|SU
argument_list|)
block|;
name|void
name|releasePred
argument_list|(
name|SUnit
operator|*
name|SU
argument_list|,
name|SDep
operator|*
name|PredEdge
argument_list|)
block|;
name|void
name|releasePredecessors
argument_list|(
name|SUnit
operator|*
name|SU
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
unit|}
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

