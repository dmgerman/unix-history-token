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
comment|// This file provides an interface for customizing the standard MachineScheduler
end_comment

begin_comment
comment|// pass. Note that the entire pass may be replaced as follows:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//<Target>TargetMachine::createPassConfig(PassManagerBase&PM) {
end_comment

begin_comment
comment|//   PM.substitutePass(&MachineSchedulerID,&CustomSchedulerPassID);
end_comment

begin_comment
comment|//   ...}
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The MachineScheduler pass is only responsible for choosing the regions to be
end_comment

begin_comment
comment|// scheduled. Targets can override the DAG builder and scheduler without
end_comment

begin_comment
comment|// replacing the pass as follows:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ScheduleDAGInstrs *<Target>PassConfig::
end_comment

begin_comment
comment|// createMachineScheduler(MachineSchedContext *C) {
end_comment

begin_comment
comment|//   return new CustomMachineScheduler(C);
end_comment

begin_comment
comment|// }
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The default scheduler, ScheduleDAGMILive, builds the DAG and drives list
end_comment

begin_comment
comment|// scheduling while updating the instruction stream, register pressure, and live
end_comment

begin_comment
comment|// intervals. Most targets don't need to override the DAG builder and list
end_comment

begin_comment
comment|// schedulier, but subtargets that require custom scheduling heuristics may
end_comment

begin_comment
comment|// plugin an alternate MachineSchedStrategy. The strategy is responsible for
end_comment

begin_comment
comment|// selecting the highest priority node from the list:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ScheduleDAGInstrs *<Target>PassConfig::
end_comment

begin_comment
comment|// createMachineScheduler(MachineSchedContext *C) {
end_comment

begin_comment
comment|//   return new ScheduleDAGMI(C, CustomStrategy(C));
end_comment

begin_comment
comment|// }
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The DAG builder can also be customized in a sense by adding DAG mutations
end_comment

begin_comment
comment|// that will run after DAG building and before list scheduling. DAG mutations
end_comment

begin_comment
comment|// can adjust dependencies based on target-specific knowledge or add weak edges
end_comment

begin_comment
comment|// to aid heuristics:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ScheduleDAGInstrs *<Target>PassConfig::
end_comment

begin_comment
comment|// createMachineScheduler(MachineSchedContext *C) {
end_comment

begin_comment
comment|//   ScheduleDAGMI *DAG = createGenericSchedLive(C);
end_comment

begin_comment
comment|//   DAG->addMutation(new CustomDAGMutation(...));
end_comment

begin_comment
comment|//   return DAG;
end_comment

begin_comment
comment|// }
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// A target that supports alternative schedulers can use the
end_comment

begin_comment
comment|// MachineSchedRegistry to allow command line selection. This can be done by
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
comment|//
end_comment

begin_comment
comment|// Finally, subtargets that don't need to implement custom heuristics but would
end_comment

begin_comment
comment|// like to configure the GenericScheduler's policy for a given scheduler region,
end_comment

begin_comment
comment|// including scheduling direction and register pressure tracking policy, can do
end_comment

begin_comment
comment|// this:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// void<SubTarget>Subtarget::
end_comment

begin_comment
comment|// overrideSchedPolicy(MachineSchedPolicy&Policy,
end_comment

begin_comment
comment|//                     unsigned NumRegionInstrs) const {
end_comment

begin_comment
comment|//   Policy.<Flag> = true;
end_comment

begin_comment
comment|// }
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
name|LLVM_CODEGEN_MACHINESCHEDULER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_MACHINESCHEDULER_H
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
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Twine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/AliasAnalysis.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineBasicBlock.h"
end_include

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
file|"llvm/CodeGen/ScheduleDAG.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ScheduleDAGInstrs.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ScheduleDAGMutation.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/TargetSchedule.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CommandLine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
extern|extern cl::opt<bool> ForceTopDown;
extern|extern cl::opt<bool> ForceBottomUp;
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
name|SchedDFSResult
decl_stmt|;
name|class
name|ScheduleHazardRecognizer
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
comment|/// Define a generic scheduling policy for targets that don't provide their own
end_comment

begin_comment
comment|/// MachineSchedStrategy. This can be overriden for each scheduling region
end_comment

begin_comment
comment|/// before building the DAG.
end_comment

begin_struct
struct|struct
name|MachineSchedPolicy
block|{
comment|// Allow the scheduler to disable register pressure tracking.
name|bool
name|ShouldTrackPressure
decl_stmt|;
comment|/// Track LaneMasks to allow reordering of independent subregister writes
comment|/// of the same vreg. \sa MachineSchedStrategy::shouldTrackLaneMasks()
name|bool
name|ShouldTrackLaneMasks
decl_stmt|;
comment|// Allow the scheduler to force top-down or bottom-up scheduling. If neither
comment|// is true, the scheduler runs in both directions and converges.
name|bool
name|OnlyTopDown
decl_stmt|;
name|bool
name|OnlyBottomUp
decl_stmt|;
comment|// Disable heuristic that tries to fetch nodes from long dependency chains
comment|// first.
name|bool
name|DisableLatencyHeuristic
decl_stmt|;
name|MachineSchedPolicy
argument_list|()
operator|:
name|ShouldTrackPressure
argument_list|(
name|false
argument_list|)
operator|,
name|ShouldTrackLaneMasks
argument_list|(
name|false
argument_list|)
operator|,
name|OnlyTopDown
argument_list|(
name|false
argument_list|)
operator|,
name|OnlyBottomUp
argument_list|(
name|false
argument_list|)
operator|,
name|DisableLatencyHeuristic
argument_list|(
argument|false
argument_list|)
block|{}
block|}
struct|;
end_struct

begin_comment
comment|/// MachineSchedStrategy - Interface to the scheduling algorithm used by
end_comment

begin_comment
comment|/// ScheduleDAGMI.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Initialization sequence:
end_comment

begin_comment
comment|///   initPolicy -> shouldTrackPressure -> initialize(DAG) -> registerRoots
end_comment

begin_decl_stmt
name|class
name|MachineSchedStrategy
block|{
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
name|public
label|:
name|virtual
operator|~
name|MachineSchedStrategy
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// Optionally override the per-region scheduling policy.
name|virtual
name|void
name|initPolicy
argument_list|(
name|MachineBasicBlock
operator|::
name|iterator
name|Begin
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|End
argument_list|,
name|unsigned
name|NumRegionInstrs
argument_list|)
block|{}
name|virtual
name|void
name|dumpPolicy
parameter_list|()
block|{}
comment|/// Check if pressure tracking is needed before building the DAG and
comment|/// initializing this strategy. Called after initPolicy.
name|virtual
name|bool
name|shouldTrackPressure
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
comment|/// Returns true if lanemasks should be tracked. LaneMask tracking is
comment|/// necessary to reorder independent subregister defs for the same vreg.
comment|/// This has to be enabled in combination with shouldTrackPressure().
name|virtual
name|bool
name|shouldTrackLaneMasks
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// Initialize the strategy after building the DAG for a new region.
name|virtual
name|void
name|initialize
parameter_list|(
name|ScheduleDAGMI
modifier|*
name|DAG
parameter_list|)
init|=
literal|0
function_decl|;
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
comment|/// \brief Scheduler callback to notify that a new subtree is scheduled.
name|virtual
name|void
name|scheduleTree
parameter_list|(
name|unsigned
name|SubtreeID
parameter_list|)
block|{}
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
comment|/// ScheduleDAGMI is an implementation of ScheduleDAGInstrs that simply
end_comment

begin_comment
comment|/// schedules machine instructions according to the given MachineSchedStrategy
end_comment

begin_comment
comment|/// without much extra book-keeping. This is the common functionality between
end_comment

begin_comment
comment|/// PreRA and PostRA MachineScheduler.
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
name|LiveIntervals
operator|*
name|LIS
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|MachineSchedStrategy
operator|>
name|SchedImpl
block|;
comment|/// Topo - A topological ordering for SUnits which permits fast IsReachable
comment|/// and similar queries.
name|ScheduleDAGTopologicalSort
name|Topo
block|;
comment|/// Ordered list of DAG postprocessing steps.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|ScheduleDAGMutation
operator|>>
name|Mutations
block|;
comment|/// The top of the unscheduled zone.
name|MachineBasicBlock
operator|::
name|iterator
name|CurrentTop
block|;
comment|/// The bottom of the unscheduled zone.
name|MachineBasicBlock
operator|::
name|iterator
name|CurrentBottom
block|;
comment|/// Record the next node in a scheduled cluster.
specifier|const
name|SUnit
operator|*
name|NextClusterPred
block|;
specifier|const
name|SUnit
operator|*
name|NextClusterSucc
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
argument|MachineSchedContext *C
argument_list|,
argument|std::unique_ptr<MachineSchedStrategy> S
argument_list|,
argument|bool RemoveKillFlags
argument_list|)
operator|:
name|ScheduleDAGInstrs
argument_list|(
operator|*
name|C
operator|->
name|MF
argument_list|,
name|C
operator|->
name|MLI
argument_list|,
name|RemoveKillFlags
argument_list|)
block|,
name|AA
argument_list|(
name|C
operator|->
name|AA
argument_list|)
block|,
name|LIS
argument_list|(
name|C
operator|->
name|LIS
argument_list|)
block|,
name|SchedImpl
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|S
argument_list|)
argument_list|)
block|,
name|Topo
argument_list|(
name|SUnits
argument_list|,
operator|&
name|ExitSU
argument_list|)
block|,
name|NextClusterPred
argument_list|(
name|nullptr
argument_list|)
block|,
name|NextClusterSucc
argument_list|(
argument|nullptr
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
comment|// Provide a vtable anchor
operator|~
name|ScheduleDAGMI
argument_list|()
name|override
block|;
comment|// Returns LiveIntervals instance for use in DAG mutators and such.
name|LiveIntervals
operator|*
name|getLIS
argument_list|()
specifier|const
block|{
return|return
name|LIS
return|;
block|}
comment|/// Return true if this DAG supports VReg liveness and RegPressure.
name|virtual
name|bool
name|hasVRegLiveness
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// Add a postprocessing step to the DAG builder.
comment|/// Mutations are applied in the order that they are added after normal DAG
comment|/// building and before MachineSchedStrategy initialization.
comment|///
comment|/// ScheduleDAGMI takes ownership of the Mutation object.
name|void
name|addMutation
argument_list|(
argument|std::unique_ptr<ScheduleDAGMutation> Mutation
argument_list|)
block|{
if|if
condition|(
name|Mutation
condition|)
name|Mutations
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Mutation
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// \brief True if an edge can be added from PredSU to SuccSU without creating
comment|/// a cycle.
name|bool
name|canAddEdge
argument_list|(
name|SUnit
operator|*
name|SuccSU
argument_list|,
name|SUnit
operator|*
name|PredSU
argument_list|)
block|;
comment|/// \brief Add a DAG edge to the given SU with the given predecessor
comment|/// dependence data.
comment|///
comment|/// \returns true if the edge may be added without creating a cycle OR if an
comment|/// equivalent edge already existed (false indicates failure).
name|bool
name|addEdge
argument_list|(
name|SUnit
operator|*
name|SuccSU
argument_list|,
specifier|const
name|SDep
operator|&
name|PredDep
argument_list|)
block|;
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
argument|unsigned regioninstrs
argument_list|)
name|override
block|;
comment|/// Implement ScheduleDAGInstrs interface for scheduling a sequence of
comment|/// reorderable instructions.
name|void
name|schedule
argument_list|()
name|override
block|;
comment|/// Change the position of an instruction within the basic block and update
comment|/// live ranges and region boundary iterators.
name|void
name|moveInstruction
argument_list|(
argument|MachineInstr *MI
argument_list|,
argument|MachineBasicBlock::iterator InsertPos
argument_list|)
block|;
specifier|const
name|SUnit
operator|*
name|getNextClusterPred
argument_list|()
specifier|const
block|{
return|return
name|NextClusterPred
return|;
block|}
specifier|const
name|SUnit
operator|*
name|getNextClusterSucc
argument_list|()
specifier|const
block|{
return|return
name|NextClusterSucc
return|;
block|}
name|void
name|viewGraph
argument_list|(
argument|const Twine&Name
argument_list|,
argument|const Twine&Title
argument_list|)
name|override
block|;
name|void
name|viewGraph
argument_list|()
name|override
block|;
name|protected
operator|:
comment|// Top-Level entry points for the schedule() driver...
comment|/// Apply each ScheduleDAGMutation step in order. This allows different
comment|/// instances of ScheduleDAGMI to perform custom DAG postprocessing.
name|void
name|postprocessDAG
argument_list|()
block|;
comment|/// Release ExitSU predecessors and setup scheduler queues.
name|void
name|initQueues
argument_list|(
name|ArrayRef
operator|<
name|SUnit
operator|*
operator|>
name|TopRoots
argument_list|,
name|ArrayRef
operator|<
name|SUnit
operator|*
operator|>
name|BotRoots
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
name|bool
name|checkSchedLimit
argument_list|()
block|;
name|void
name|findRootsAndBiasEdges
argument_list|(
name|SmallVectorImpl
operator|<
name|SUnit
operator|*
operator|>
operator|&
name|TopRoots
argument_list|,
name|SmallVectorImpl
operator|<
name|SUnit
operator|*
operator|>
operator|&
name|BotRoots
argument_list|)
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
comment|/// ScheduleDAGMILive is an implementation of ScheduleDAGInstrs that schedules
end_comment

begin_comment
comment|/// machine instructions while updating LiveIntervals and tracking regpressure.
end_comment

begin_decl_stmt
name|class
name|ScheduleDAGMILive
range|:
name|public
name|ScheduleDAGMI
block|{
name|protected
operator|:
name|RegisterClassInfo
operator|*
name|RegClassInfo
block|;
comment|/// Information about DAG subtrees. If DFSResult is NULL, then SchedulerTrees
comment|/// will be empty.
name|SchedDFSResult
operator|*
name|DFSResult
block|;
name|BitVector
name|ScheduledTrees
block|;
name|MachineBasicBlock
operator|::
name|iterator
name|LiveRegionEnd
block|;
comment|/// Maps vregs to the SUnits of their uses in the current scheduling region.
name|VReg2SUnitMultiMap
name|VRegUses
block|;
comment|// Map each SU to its summary of pressure changes. This array is updated for
comment|// liveness during bottom-up scheduling. Top-down scheduling may proceed but
comment|// has no affect on the pressure diffs.
name|PressureDiffs
name|SUPressureDiffs
block|;
comment|/// Register pressure in this region computed by initRegPressure.
name|bool
name|ShouldTrackPressure
block|;
name|bool
name|ShouldTrackLaneMasks
block|;
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
name|PressureChange
operator|>
name|RegionCriticalPSets
block|;
comment|/// The top of the unscheduled zone.
name|IntervalPressure
name|TopPressure
block|;
name|RegPressureTracker
name|TopRPTracker
block|;
comment|/// The bottom of the unscheduled zone.
name|IntervalPressure
name|BotPressure
block|;
name|RegPressureTracker
name|BotRPTracker
block|;
comment|/// True if disconnected subregister components are already renamed.
comment|/// The renaming is only done on demand if lane masks are tracked.
name|bool
name|DisconnectedComponentsRenamed
block|;
name|public
operator|:
name|ScheduleDAGMILive
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
name|ScheduleDAGMI
argument_list|(
name|C
argument_list|,
name|std
operator|::
name|move
argument_list|(
name|S
argument_list|)
argument_list|,
comment|/*RemoveKillFlags=*/
name|false
argument_list|)
block|,
name|RegClassInfo
argument_list|(
name|C
operator|->
name|RegClassInfo
argument_list|)
block|,
name|DFSResult
argument_list|(
name|nullptr
argument_list|)
block|,
name|ShouldTrackPressure
argument_list|(
name|false
argument_list|)
block|,
name|ShouldTrackLaneMasks
argument_list|(
name|false
argument_list|)
block|,
name|RPTracker
argument_list|(
name|RegPressure
argument_list|)
block|,
name|TopRPTracker
argument_list|(
name|TopPressure
argument_list|)
block|,
name|BotRPTracker
argument_list|(
name|BotPressure
argument_list|)
block|,
name|DisconnectedComponentsRenamed
argument_list|(
argument|false
argument_list|)
block|{}
operator|~
name|ScheduleDAGMILive
argument_list|()
name|override
block|;
comment|/// Return true if this DAG supports VReg liveness and RegPressure.
name|bool
name|hasVRegLiveness
argument_list|()
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
comment|/// \brief Return true if register pressure tracking is enabled.
name|bool
name|isTrackingPressure
argument_list|()
specifier|const
block|{
return|return
name|ShouldTrackPressure
return|;
block|}
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
name|PressureChange
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
name|PressureDiff
operator|&
name|getPressureDiff
argument_list|(
argument|const SUnit *SU
argument_list|)
block|{
return|return
name|SUPressureDiffs
index|[
name|SU
operator|->
name|NodeNum
index|]
return|;
block|}
comment|/// Compute a DFSResult after DAG building is complete, and before any
comment|/// queue comparisons.
name|void
name|computeDFSResult
argument_list|()
block|;
comment|/// Return a non-null DFS result if the scheduling strategy initialized it.
specifier|const
name|SchedDFSResult
operator|*
name|getDFSResult
argument_list|()
specifier|const
block|{
return|return
name|DFSResult
return|;
block|}
name|BitVector
operator|&
name|getScheduledTrees
argument_list|()
block|{
return|return
name|ScheduledTrees
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
argument|unsigned regioninstrs
argument_list|)
name|override
block|;
comment|/// Implement ScheduleDAGInstrs interface for scheduling a sequence of
comment|/// reorderable instructions.
name|void
name|schedule
argument_list|()
name|override
block|;
comment|/// Compute the cyclic critical path through the DAG.
name|unsigned
name|computeCyclicCriticalPath
argument_list|()
block|;
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
comment|/// Release ExitSU predecessors and setup scheduler queues. Re-position
comment|/// the Top RP tracker in case the region beginning has changed.
name|void
name|initQueues
argument_list|(
name|ArrayRef
operator|<
name|SUnit
operator|*
operator|>
name|TopRoots
argument_list|,
name|ArrayRef
operator|<
name|SUnit
operator|*
operator|>
name|BotRoots
argument_list|)
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
comment|// Lesser helpers...
name|void
name|initRegPressure
argument_list|()
block|;
name|void
name|updatePressureDiffs
argument_list|(
name|ArrayRef
operator|<
name|RegisterMaskPair
operator|>
name|LiveUses
argument_list|)
block|;
name|void
name|updateScheduledPressure
argument_list|(
specifier|const
name|SUnit
operator|*
name|SU
argument_list|,
specifier|const
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
operator|&
name|NewMaxPressure
argument_list|)
block|;
name|void
name|collectVRegUses
argument_list|(
name|SUnit
operator|&
name|SU
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Helpers for implementing custom MachineSchedStrategy classes. These take
end_comment

begin_comment
comment|/// care of the book-keeping associated with list scheduling heuristics.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

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
name|ArrayRef
operator|<
name|SUnit
operator|*
operator|>
name|elements
argument_list|()
block|{
return|return
name|Queue
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
name|llvm
operator|::
name|find
argument_list|(
name|Queue
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
name|void
name|dump
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// Summarize the unscheduled region.
end_comment

begin_struct
struct|struct
name|SchedRemainder
block|{
comment|// Critical path through the DAG in expected latency.
name|unsigned
name|CriticalPath
decl_stmt|;
name|unsigned
name|CyclicCritPath
decl_stmt|;
comment|// Scaled count of micro-ops left to schedule.
name|unsigned
name|RemIssueCount
decl_stmt|;
name|bool
name|IsAcyclicLatencyLimited
decl_stmt|;
comment|// Unscheduled resources
name|SmallVector
operator|<
name|unsigned
operator|,
literal|16
operator|>
name|RemainingCounts
expr_stmt|;
name|void
name|reset
parameter_list|()
block|{
name|CriticalPath
operator|=
literal|0
expr_stmt|;
name|CyclicCritPath
operator|=
literal|0
expr_stmt|;
name|RemIssueCount
operator|=
literal|0
expr_stmt|;
name|IsAcyclicLatencyLimited
operator|=
name|false
expr_stmt|;
name|RemainingCounts
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
name|SchedRemainder
argument_list|()
block|{
name|reset
argument_list|()
expr_stmt|;
block|}
name|void
name|init
parameter_list|(
name|ScheduleDAGMI
modifier|*
name|DAG
parameter_list|,
specifier|const
name|TargetSchedModel
modifier|*
name|SchedModel
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/// Each Scheduling boundary is associated with ready queues. It tracks the
end_comment

begin_comment
comment|/// current cycle in the direction of movement, and maintains the state
end_comment

begin_comment
comment|/// of "hazards" and other interlocks at the current cycle.
end_comment

begin_decl_stmt
name|class
name|SchedBoundary
block|{
name|public
label|:
comment|/// SUnit::NodeQueueId: 0 (none), 1 (top), 2 (bot), 3 (both)
enum|enum
block|{
name|TopQID
init|=
literal|1
block|,
name|BotQID
init|=
literal|2
block|,
name|LogMaxQID
init|=
literal|2
block|}
enum|;
name|ScheduleDAGMI
modifier|*
name|DAG
decl_stmt|;
specifier|const
name|TargetSchedModel
modifier|*
name|SchedModel
decl_stmt|;
name|SchedRemainder
modifier|*
name|Rem
decl_stmt|;
name|ReadyQueue
name|Available
decl_stmt|;
name|ReadyQueue
name|Pending
decl_stmt|;
name|ScheduleHazardRecognizer
modifier|*
name|HazardRec
decl_stmt|;
name|private
label|:
comment|/// True if the pending Q should be checked/updated before scheduling another
comment|/// instruction.
name|bool
name|CheckPending
decl_stmt|;
comment|/// Number of cycles it takes to issue the instructions scheduled in this
comment|/// zone. It is defined as: scheduled-micro-ops / issue-width + stalls.
comment|/// See getStalls().
name|unsigned
name|CurrCycle
decl_stmt|;
comment|/// Micro-ops issued in the current cycle
name|unsigned
name|CurrMOps
decl_stmt|;
comment|/// MinReadyCycle - Cycle of the soonest available instruction.
name|unsigned
name|MinReadyCycle
decl_stmt|;
comment|// The expected latency of the critical path in this scheduled zone.
name|unsigned
name|ExpectedLatency
decl_stmt|;
comment|// The latency of dependence chains leading into this zone.
comment|// For each node scheduled bottom-up: DLat = max DLat, N.Depth.
comment|// For each cycle scheduled: DLat -= 1.
name|unsigned
name|DependentLatency
decl_stmt|;
comment|/// Count the scheduled (issued) micro-ops that can be retired by
comment|/// time=CurrCycle assuming the first scheduled instr is retired at time=0.
name|unsigned
name|RetiredMOps
decl_stmt|;
comment|// Count scheduled resources that have been executed. Resources are
comment|// considered executed if they become ready in the time that it takes to
comment|// saturate any resource including the one in question. Counts are scaled
comment|// for direct comparison with other resources. Counts can be compared with
comment|// MOps * getMicroOpFactor and Latency * getLatencyFactor.
name|SmallVector
operator|<
name|unsigned
operator|,
literal|16
operator|>
name|ExecutedResCounts
expr_stmt|;
comment|/// Cache the max count for a single resource.
name|unsigned
name|MaxExecutedResCount
decl_stmt|;
comment|// Cache the critical resources ID in this scheduled zone.
name|unsigned
name|ZoneCritResIdx
decl_stmt|;
comment|// Is the scheduled region resource limited vs. latency limited.
name|bool
name|IsResourceLimited
decl_stmt|;
comment|// Record the highest cycle at which each resource has been reserved by a
comment|// scheduled instruction.
name|SmallVector
operator|<
name|unsigned
operator|,
literal|16
operator|>
name|ReservedCycles
expr_stmt|;
ifndef|#
directive|ifndef
name|NDEBUG
comment|// Remember the greatest possible stall as an upper bound on the number of
comment|// times we should retry the pending queue because of a hazard.
name|unsigned
name|MaxObservedStall
decl_stmt|;
endif|#
directive|endif
name|public
label|:
comment|/// Pending queues extend the ready queues with the same ID and the
comment|/// PendingFlag set.
name|SchedBoundary
argument_list|(
argument|unsigned ID
argument_list|,
argument|const Twine&Name
argument_list|)
block|:
name|DAG
argument_list|(
name|nullptr
argument_list|)
operator|,
name|SchedModel
argument_list|(
name|nullptr
argument_list|)
operator|,
name|Rem
argument_list|(
name|nullptr
argument_list|)
operator|,
name|Available
argument_list|(
name|ID
argument_list|,
name|Name
operator|+
literal|".A"
argument_list|)
operator|,
name|Pending
argument_list|(
name|ID
operator|<<
name|LogMaxQID
argument_list|,
name|Name
operator|+
literal|".P"
argument_list|)
operator|,
name|HazardRec
argument_list|(
argument|nullptr
argument_list|)
block|{
name|reset
argument_list|()
block|;   }
operator|~
name|SchedBoundary
argument_list|()
expr_stmt|;
name|void
name|reset
parameter_list|()
function_decl|;
name|void
name|init
parameter_list|(
name|ScheduleDAGMI
modifier|*
name|dag
parameter_list|,
specifier|const
name|TargetSchedModel
modifier|*
name|smodel
parameter_list|,
name|SchedRemainder
modifier|*
name|rem
parameter_list|)
function_decl|;
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
name|TopQID
return|;
block|}
comment|/// Number of cycles to issue the instructions scheduled in this zone.
name|unsigned
name|getCurrCycle
argument_list|()
specifier|const
block|{
return|return
name|CurrCycle
return|;
block|}
comment|/// Micro-ops issued in the current cycle
name|unsigned
name|getCurrMOps
argument_list|()
specifier|const
block|{
return|return
name|CurrMOps
return|;
block|}
comment|// The latency of dependence chains leading into this zone.
name|unsigned
name|getDependentLatency
argument_list|()
specifier|const
block|{
return|return
name|DependentLatency
return|;
block|}
comment|/// Get the number of latency cycles "covered" by the scheduled
comment|/// instructions. This is the larger of the critical path within the zone
comment|/// and the number of cycles required to issue the instructions.
name|unsigned
name|getScheduledLatency
argument_list|()
specifier|const
block|{
return|return
name|std
operator|::
name|max
argument_list|(
name|ExpectedLatency
argument_list|,
name|CurrCycle
argument_list|)
return|;
block|}
name|unsigned
name|getUnscheduledLatency
argument_list|(
name|SUnit
operator|*
name|SU
argument_list|)
decl|const
block|{
return|return
name|isTop
argument_list|()
condition|?
name|SU
operator|->
name|getHeight
argument_list|()
else|:
name|SU
operator|->
name|getDepth
argument_list|()
return|;
block|}
name|unsigned
name|getResourceCount
argument_list|(
name|unsigned
name|ResIdx
argument_list|)
decl|const
block|{
return|return
name|ExecutedResCounts
index|[
name|ResIdx
index|]
return|;
block|}
comment|/// Get the scaled count of scheduled micro-ops and resources, including
comment|/// executed resources.
name|unsigned
name|getCriticalCount
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|ZoneCritResIdx
condition|)
return|return
name|RetiredMOps
operator|*
name|SchedModel
operator|->
name|getMicroOpFactor
argument_list|()
return|;
return|return
name|getResourceCount
argument_list|(
name|ZoneCritResIdx
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Get a scaled count for the minimum execution time of the scheduled
end_comment

begin_comment
comment|/// micro-ops that are ready to execute by getExecutedCount. Notice the
end_comment

begin_comment
comment|/// feedback loop.
end_comment

begin_expr_stmt
name|unsigned
name|getExecutedCount
argument_list|()
specifier|const
block|{
return|return
name|std
operator|::
name|max
argument_list|(
name|CurrCycle
operator|*
name|SchedModel
operator|->
name|getLatencyFactor
argument_list|()
argument_list|,
name|MaxExecutedResCount
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|unsigned
name|getZoneCritResIdx
argument_list|()
specifier|const
block|{
return|return
name|ZoneCritResIdx
return|;
block|}
end_expr_stmt

begin_comment
comment|// Is the scheduled region resource limited vs. latency limited.
end_comment

begin_expr_stmt
name|bool
name|isResourceLimited
argument_list|()
specifier|const
block|{
return|return
name|IsResourceLimited
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Get the difference between the given SUnit's ready time and the current
end_comment

begin_comment
comment|/// cycle.
end_comment

begin_function_decl
name|unsigned
name|getLatencyStallCycles
parameter_list|(
name|SUnit
modifier|*
name|SU
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|getNextResourceCycle
parameter_list|(
name|unsigned
name|PIdx
parameter_list|,
name|unsigned
name|Cycles
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|checkHazard
parameter_list|(
name|SUnit
modifier|*
name|SU
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|unsigned
name|findMaxLatency
argument_list|(
name|ArrayRef
operator|<
name|SUnit
operator|*
operator|>
name|ReadySUs
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|unsigned
name|getOtherResourceCount
parameter_list|(
name|unsigned
modifier|&
name|OtherCritIdx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|releaseNode
parameter_list|(
name|SUnit
modifier|*
name|SU
parameter_list|,
name|unsigned
name|ReadyCycle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bumpCycle
parameter_list|(
name|unsigned
name|NextCycle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|incExecutedResources
parameter_list|(
name|unsigned
name|PIdx
parameter_list|,
name|unsigned
name|Count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|countResource
parameter_list|(
name|unsigned
name|PIdx
parameter_list|,
name|unsigned
name|Cycles
parameter_list|,
name|unsigned
name|ReadyCycle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bumpNode
parameter_list|(
name|SUnit
modifier|*
name|SU
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|releasePending
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|removeReady
parameter_list|(
name|SUnit
modifier|*
name|SU
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Call this before applying any other heuristics to the Available queue.
end_comment

begin_comment
comment|/// Updates the Available/Pending Q's if necessary and returns the single
end_comment

begin_comment
comment|/// available instruction, or NULL if there are multiple candidates.
end_comment

begin_function_decl
name|SUnit
modifier|*
name|pickOnlyChoice
parameter_list|()
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|NDEBUG
end_ifndef

begin_function_decl
name|void
name|dumpScheduledState
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
unit|};
comment|/// Base class for GenericScheduler. This class maintains information about
end_comment

begin_comment
comment|/// scheduling candidates based on TargetSchedModel making it easy to implement
end_comment

begin_comment
comment|/// heuristics for either preRA or postRA scheduling.
end_comment

begin_decl_stmt
name|class
name|GenericSchedulerBase
range|:
name|public
name|MachineSchedStrategy
block|{
name|public
operator|:
comment|/// Represent the type of SchedCandidate found within a single queue.
comment|/// pickNodeBidirectional depends on these listed by decreasing priority.
expr|enum
name|CandReason
operator|:
name|uint8_t
block|{
name|NoCand
block|,
name|Only1
block|,
name|PhysRegCopy
block|,
name|RegExcess
block|,
name|RegCritical
block|,
name|Stall
block|,
name|Cluster
block|,
name|Weak
block|,
name|RegMax
block|,
name|ResourceReduce
block|,
name|ResourceDemand
block|,
name|BotHeightReduce
block|,
name|BotPathReduce
block|,
name|TopDepthReduce
block|,
name|TopPathReduce
block|,
name|NextDefUse
block|,
name|NodeOrder
block|}
block|;
ifndef|#
directive|ifndef
name|NDEBUG
specifier|static
specifier|const
name|char
operator|*
name|getReasonStr
argument_list|(
argument|GenericSchedulerBase::CandReason Reason
argument_list|)
block|;
endif|#
directive|endif
comment|/// Policy for scheduling the next instruction in the candidate's zone.
block|struct
name|CandPolicy
block|{
name|bool
name|ReduceLatency
block|;
name|unsigned
name|ReduceResIdx
block|;
name|unsigned
name|DemandResIdx
block|;
name|CandPolicy
argument_list|()
operator|:
name|ReduceLatency
argument_list|(
name|false
argument_list|)
block|,
name|ReduceResIdx
argument_list|(
literal|0
argument_list|)
block|,
name|DemandResIdx
argument_list|(
literal|0
argument_list|)
block|{}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|CandPolicy
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|ReduceLatency
operator|==
name|RHS
operator|.
name|ReduceLatency
operator|&&
name|ReduceResIdx
operator|==
name|RHS
operator|.
name|ReduceResIdx
operator|&&
name|DemandResIdx
operator|==
name|RHS
operator|.
name|DemandResIdx
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|CandPolicy
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|RHS
operator|)
return|;
block|}
expr|}
block|;
comment|/// Status of an instruction's critical resource consumption.
block|struct
name|SchedResourceDelta
block|{
comment|// Count critical resources in the scheduled region required by SU.
name|unsigned
name|CritResources
block|;
comment|// Count critical resources from another region consumed by SU.
name|unsigned
name|DemandedResources
block|;
name|SchedResourceDelta
argument_list|()
operator|:
name|CritResources
argument_list|(
literal|0
argument_list|)
block|,
name|DemandedResources
argument_list|(
literal|0
argument_list|)
block|{}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|SchedResourceDelta
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|CritResources
operator|==
name|RHS
operator|.
name|CritResources
operator|&&
name|DemandedResources
operator|==
name|RHS
operator|.
name|DemandedResources
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|SchedResourceDelta
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|RHS
operator|)
return|;
block|}
expr|}
block|;
comment|/// Store the state used by GenericScheduler heuristics, required for the
comment|/// lifetime of one invocation of pickNode().
block|struct
name|SchedCandidate
block|{
name|CandPolicy
name|Policy
block|;
comment|// The best SUnit candidate.
name|SUnit
operator|*
name|SU
block|;
comment|// The reason for this candidate.
name|CandReason
name|Reason
block|;
comment|// Whether this candidate should be scheduled at top/bottom.
name|bool
name|AtTop
block|;
comment|// Register pressure values for the best candidate.
name|RegPressureDelta
name|RPDelta
block|;
comment|// Critical resource consumption of the best candidate.
name|SchedResourceDelta
name|ResDelta
block|;
name|SchedCandidate
argument_list|()
block|{
name|reset
argument_list|(
name|CandPolicy
argument_list|()
argument_list|)
block|; }
name|SchedCandidate
argument_list|(
argument|const CandPolicy&Policy
argument_list|)
block|{
name|reset
argument_list|(
name|Policy
argument_list|)
block|; }
name|void
name|reset
argument_list|(
argument|const CandPolicy&NewPolicy
argument_list|)
block|{
name|Policy
operator|=
name|NewPolicy
block|;
name|SU
operator|=
name|nullptr
block|;
name|Reason
operator|=
name|NoCand
block|;
name|AtTop
operator|=
name|false
block|;
name|RPDelta
operator|=
name|RegPressureDelta
argument_list|()
block|;
name|ResDelta
operator|=
name|SchedResourceDelta
argument_list|()
block|;     }
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|SU
return|;
block|}
comment|// Copy the status of another candidate without changing policy.
name|void
name|setBest
argument_list|(
argument|SchedCandidate&Best
argument_list|)
block|{
name|assert
argument_list|(
name|Best
operator|.
name|Reason
operator|!=
name|NoCand
operator|&&
literal|"uninitialized Sched candidate"
argument_list|)
block|;
name|SU
operator|=
name|Best
operator|.
name|SU
block|;
name|Reason
operator|=
name|Best
operator|.
name|Reason
block|;
name|AtTop
operator|=
name|Best
operator|.
name|AtTop
block|;
name|RPDelta
operator|=
name|Best
operator|.
name|RPDelta
block|;
name|ResDelta
operator|=
name|Best
operator|.
name|ResDelta
block|;     }
name|void
name|initResourceDelta
argument_list|(
specifier|const
name|ScheduleDAGMI
operator|*
name|DAG
argument_list|,
specifier|const
name|TargetSchedModel
operator|*
name|SchedModel
argument_list|)
block|;   }
block|;
name|protected
operator|:
specifier|const
name|MachineSchedContext
operator|*
name|Context
block|;
specifier|const
name|TargetSchedModel
operator|*
name|SchedModel
block|;
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
block|;
name|SchedRemainder
name|Rem
block|;
name|GenericSchedulerBase
argument_list|(
specifier|const
name|MachineSchedContext
operator|*
name|C
argument_list|)
operator|:
name|Context
argument_list|(
name|C
argument_list|)
block|,
name|SchedModel
argument_list|(
name|nullptr
argument_list|)
block|,
name|TRI
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|void
name|setPolicy
argument_list|(
argument|CandPolicy&Policy
argument_list|,
argument|bool IsPostRA
argument_list|,
argument|SchedBoundary&CurrZone
argument_list|,
argument|SchedBoundary *OtherZone
argument_list|)
block|;
ifndef|#
directive|ifndef
name|NDEBUG
name|void
name|traceCandidate
argument_list|(
specifier|const
name|SchedCandidate
operator|&
name|Cand
argument_list|)
block|;
endif|#
directive|endif
block|}
block|;
comment|/// GenericScheduler shrinks the unscheduled zone using heuristics to balance
comment|/// the schedule.
name|class
name|GenericScheduler
operator|:
name|public
name|GenericSchedulerBase
block|{
name|public
operator|:
name|GenericScheduler
argument_list|(
specifier|const
name|MachineSchedContext
operator|*
name|C
argument_list|)
operator|:
name|GenericSchedulerBase
argument_list|(
name|C
argument_list|)
block|,
name|DAG
argument_list|(
name|nullptr
argument_list|)
block|,
name|Top
argument_list|(
name|SchedBoundary
operator|::
name|TopQID
argument_list|,
literal|"TopQ"
argument_list|)
block|,
name|Bot
argument_list|(
argument|SchedBoundary::BotQID
argument_list|,
literal|"BotQ"
argument_list|)
block|{}
name|void
name|initPolicy
argument_list|(
argument|MachineBasicBlock::iterator Begin
argument_list|,
argument|MachineBasicBlock::iterator End
argument_list|,
argument|unsigned NumRegionInstrs
argument_list|)
name|override
block|;
name|void
name|dumpPolicy
argument_list|()
name|override
block|;
name|bool
name|shouldTrackPressure
argument_list|()
specifier|const
name|override
block|{
return|return
name|RegionPolicy
operator|.
name|ShouldTrackPressure
return|;
block|}
name|bool
name|shouldTrackLaneMasks
argument_list|()
specifier|const
name|override
block|{
return|return
name|RegionPolicy
operator|.
name|ShouldTrackLaneMasks
return|;
block|}
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
block|{
if|if
condition|(
name|SU
operator|->
name|isScheduled
condition|)
return|return;
name|Top
operator|.
name|releaseNode
argument_list|(
name|SU
argument_list|,
name|SU
operator|->
name|TopReadyCycle
argument_list|)
block|;
name|TopCand
operator|.
name|SU
operator|=
name|nullptr
block|;   }
name|void
name|releaseBottomNode
argument_list|(
argument|SUnit *SU
argument_list|)
name|override
block|{
if|if
condition|(
name|SU
operator|->
name|isScheduled
condition|)
return|return;
name|Bot
operator|.
name|releaseNode
argument_list|(
name|SU
argument_list|,
name|SU
operator|->
name|BotReadyCycle
argument_list|)
block|;
name|BotCand
operator|.
name|SU
operator|=
name|nullptr
block|;   }
name|void
name|registerRoots
argument_list|()
name|override
block|;
name|protected
operator|:
name|ScheduleDAGMILive
operator|*
name|DAG
block|;
name|MachineSchedPolicy
name|RegionPolicy
block|;
comment|// State of the top and bottom scheduled instruction boundaries.
name|SchedBoundary
name|Top
block|;
name|SchedBoundary
name|Bot
block|;
comment|/// Candidate last picked from Top boundary.
name|SchedCandidate
name|TopCand
block|;
comment|/// Candidate last picked from Bot boundary.
name|SchedCandidate
name|BotCand
block|;
name|void
name|checkAcyclicLatency
argument_list|()
block|;
name|void
name|initCandidate
argument_list|(
argument|SchedCandidate&Cand
argument_list|,
argument|SUnit *SU
argument_list|,
argument|bool AtTop
argument_list|,
argument|const RegPressureTracker&RPTracker
argument_list|,
argument|RegPressureTracker&TempTracker
argument_list|)
block|;
name|void
name|tryCandidate
argument_list|(
name|SchedCandidate
operator|&
name|Cand
argument_list|,
name|SchedCandidate
operator|&
name|TryCand
argument_list|,
name|SchedBoundary
operator|*
name|Zone
argument_list|)
block|;
name|SUnit
operator|*
name|pickNodeBidirectional
argument_list|(
name|bool
operator|&
name|IsTopNode
argument_list|)
block|;
name|void
name|pickNodeFromQueue
argument_list|(
name|SchedBoundary
operator|&
name|Zone
argument_list|,
specifier|const
name|CandPolicy
operator|&
name|ZonePolicy
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
name|void
name|reschedulePhysRegCopies
argument_list|(
argument|SUnit *SU
argument_list|,
argument|bool isTop
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// PostGenericScheduler - Interface to the scheduling algorithm used by
end_comment

begin_comment
comment|/// ScheduleDAGMI.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Callbacks from ScheduleDAGMI:
end_comment

begin_comment
comment|///   initPolicy -> initialize(DAG) -> registerRoots -> pickNode ...
end_comment

begin_decl_stmt
name|class
name|PostGenericScheduler
range|:
name|public
name|GenericSchedulerBase
block|{
name|ScheduleDAGMI
operator|*
name|DAG
block|;
name|SchedBoundary
name|Top
block|;
name|SmallVector
operator|<
name|SUnit
operator|*
block|,
literal|8
operator|>
name|BotRoots
block|;
name|public
operator|:
name|PostGenericScheduler
argument_list|(
specifier|const
name|MachineSchedContext
operator|*
name|C
argument_list|)
operator|:
name|GenericSchedulerBase
argument_list|(
name|C
argument_list|)
block|,
name|Top
argument_list|(
argument|SchedBoundary::TopQID
argument_list|,
literal|"TopQ"
argument_list|)
block|{}
operator|~
name|PostGenericScheduler
argument_list|()
name|override
operator|=
expr|default
block|;
name|void
name|initPolicy
argument_list|(
argument|MachineBasicBlock::iterator Begin
argument_list|,
argument|MachineBasicBlock::iterator End
argument_list|,
argument|unsigned NumRegionInstrs
argument_list|)
name|override
block|{
comment|/* no configurable policy */
block|}
comment|/// PostRA scheduling does not track pressure.
name|bool
name|shouldTrackPressure
argument_list|()
specifier|const
name|override
block|{
return|return
name|false
return|;
block|}
name|void
name|initialize
argument_list|(
argument|ScheduleDAGMI *Dag
argument_list|)
name|override
block|;
name|void
name|registerRoots
argument_list|()
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
name|scheduleTree
argument_list|(
argument|unsigned SubtreeID
argument_list|)
name|override
block|{
name|llvm_unreachable
argument_list|(
literal|"PostRA scheduler does not support subtree analysis."
argument_list|)
block|;   }
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
block|{
if|if
condition|(
name|SU
operator|->
name|isScheduled
condition|)
return|return;
name|Top
operator|.
name|releaseNode
argument_list|(
name|SU
argument_list|,
name|SU
operator|->
name|TopReadyCycle
argument_list|)
block|;   }
comment|// Only called for roots.
name|void
name|releaseBottomNode
argument_list|(
argument|SUnit *SU
argument_list|)
name|override
block|{
name|BotRoots
operator|.
name|push_back
argument_list|(
name|SU
argument_list|)
block|;   }
name|protected
operator|:
name|void
name|tryCandidate
argument_list|(
name|SchedCandidate
operator|&
name|Cand
argument_list|,
name|SchedCandidate
operator|&
name|TryCand
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|pickNodeFromQueue
parameter_list|(
name|SchedCandidate
modifier|&
name|Cand
parameter_list|)
function_decl|;
end_function_decl

begin_comment
unit|};
comment|/// Create the standard converging machine scheduler. This will be used as the
end_comment

begin_comment
comment|/// default scheduler if the target does not set a default.
end_comment

begin_comment
comment|/// Adds default DAG mutations.
end_comment

begin_function_decl
name|ScheduleDAGMILive
modifier|*
name|createGenericSchedLive
parameter_list|(
name|MachineSchedContext
modifier|*
name|C
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Create a generic scheduler with no vreg liveness or DAG mutation passes.
end_comment

begin_function_decl
name|ScheduleDAGMI
modifier|*
name|createGenericSchedPostRA
parameter_list|(
name|MachineSchedContext
modifier|*
name|C
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|ScheduleDAGMutation
operator|>
name|createLoadClusterDAGMutation
argument_list|(
specifier|const
name|TargetInstrInfo
operator|*
name|TII
argument_list|,
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|ScheduleDAGMutation
operator|>
name|createStoreClusterDAGMutation
argument_list|(
specifier|const
name|TargetInstrInfo
operator|*
name|TII
argument_list|,
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|ScheduleDAGMutation
operator|>
name|createMacroFusionDAGMutation
argument_list|(
specifier|const
name|TargetInstrInfo
operator|*
name|TII
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|ScheduleDAGMutation
operator|>
name|createCopyConstrainDAGMutation
argument_list|(
specifier|const
name|TargetInstrInfo
operator|*
name|TII
argument_list|,
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CODEGEN_MACHINESCHEDULER_H
end_comment

end_unit

