begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- ScheduleDAGInstrs.h - MachineInstr Scheduling --------------*- C++ -*-==//
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
comment|// This file implements the ScheduleDAGInstrs class, which implements
end_comment

begin_comment
comment|// scheduling for a MachineInstr-based dependency graph.
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
name|SCHEDULEDAGINSTRS_H
end_ifndef

begin_define
define|#
directive|define
name|SCHEDULEDAGINSTRS_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineDominators.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineLoopInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ScheduleDAG.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SparseSet.h"
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
name|class
name|MachineLoopInfo
decl_stmt|;
name|class
name|MachineDominatorTree
decl_stmt|;
name|class
name|LiveIntervals
decl_stmt|;
comment|/// LoopDependencies - This class analyzes loop-oriented register
comment|/// dependencies, which are used to guide scheduling decisions.
comment|/// For example, loop induction variable increments should be
comment|/// scheduled as soon as possible after the variable's last use.
comment|///
name|class
name|LoopDependencies
block|{
specifier|const
name|MachineLoopInfo
modifier|&
name|MLI
decl_stmt|;
specifier|const
name|MachineDominatorTree
modifier|&
name|MDT
decl_stmt|;
name|public
label|:
typedef|typedef
name|std
operator|::
name|map
operator|<
name|unsigned
operator|,
name|std
operator|::
name|pair
operator|<
specifier|const
name|MachineOperand
operator|*
operator|,
name|unsigned
operator|>
expr|>
name|LoopDeps
expr_stmt|;
name|LoopDeps
name|Deps
decl_stmt|;
name|LoopDependencies
argument_list|(
specifier|const
name|MachineLoopInfo
operator|&
name|mli
argument_list|,
specifier|const
name|MachineDominatorTree
operator|&
name|mdt
argument_list|)
operator|:
name|MLI
argument_list|(
name|mli
argument_list|)
operator|,
name|MDT
argument_list|(
argument|mdt
argument_list|)
block|{}
comment|/// VisitLoop - Clear out any previous state and analyze the given loop.
comment|///
name|void
name|VisitLoop
argument_list|(
argument|const MachineLoop *Loop
argument_list|)
block|{
name|assert
argument_list|(
name|Deps
operator|.
name|empty
argument_list|()
operator|&&
literal|"stale loop dependencies"
argument_list|)
block|;
name|MachineBasicBlock
operator|*
name|Header
operator|=
name|Loop
operator|->
name|getHeader
argument_list|()
block|;
name|SmallSet
operator|<
name|unsigned
block|,
literal|8
operator|>
name|LoopLiveIns
block|;
for|for
control|(
name|MachineBasicBlock
operator|::
name|livein_iterator
name|LI
operator|=
name|Header
operator|->
name|livein_begin
argument_list|()
operator|,
name|LE
operator|=
name|Header
operator|->
name|livein_end
argument_list|()
init|;
name|LI
operator|!=
name|LE
condition|;
operator|++
name|LI
control|)
name|LoopLiveIns
operator|.
name|insert
argument_list|(
operator|*
name|LI
argument_list|)
expr_stmt|;
specifier|const
name|MachineDomTreeNode
operator|*
name|Node
operator|=
name|MDT
operator|.
name|getNode
argument_list|(
name|Header
argument_list|)
expr_stmt|;
specifier|const
name|MachineBasicBlock
modifier|*
name|MBB
init|=
name|Node
operator|->
name|getBlock
argument_list|()
decl_stmt|;
name|assert
argument_list|(
name|Loop
operator|->
name|contains
argument_list|(
name|MBB
argument_list|)
operator|&&
literal|"Loop does not contain header!"
argument_list|)
expr_stmt|;
name|VisitRegion
argument_list|(
name|Node
argument_list|,
name|MBB
argument_list|,
name|Loop
argument_list|,
name|LoopLiveIns
argument_list|)
expr_stmt|;
block|}
name|private
label|:
name|void
name|VisitRegion
argument_list|(
specifier|const
name|MachineDomTreeNode
operator|*
name|Node
argument_list|,
specifier|const
name|MachineBasicBlock
operator|*
name|MBB
argument_list|,
specifier|const
name|MachineLoop
operator|*
name|Loop
argument_list|,
specifier|const
name|SmallSet
operator|<
name|unsigned
argument_list|,
literal|8
operator|>
operator|&
name|LoopLiveIns
argument_list|)
block|{
name|unsigned
name|Count
init|=
literal|0
decl_stmt|;
for|for
control|(
name|MachineBasicBlock
operator|::
name|const_iterator
name|I
operator|=
name|MBB
operator|->
name|begin
argument_list|()
operator|,
name|E
operator|=
name|MBB
operator|->
name|end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
block|{
specifier|const
name|MachineInstr
modifier|*
name|MI
init|=
name|I
decl_stmt|;
if|if
condition|(
name|MI
operator|->
name|isDebugValue
argument_list|()
condition|)
continue|continue;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|,
name|e
init|=
name|MI
operator|->
name|getNumOperands
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|MachineOperand
modifier|&
name|MO
init|=
name|MI
operator|->
name|getOperand
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|MO
operator|.
name|isReg
argument_list|()
operator|||
operator|!
name|MO
operator|.
name|isUse
argument_list|()
condition|)
continue|continue;
name|unsigned
name|MOReg
init|=
name|MO
operator|.
name|getReg
argument_list|()
decl_stmt|;
if|if
condition|(
name|LoopLiveIns
operator|.
name|count
argument_list|(
name|MOReg
argument_list|)
condition|)
name|Deps
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|MOReg
argument_list|,
name|std
operator|::
name|make_pair
argument_list|(
operator|&
name|MO
argument_list|,
name|Count
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
operator|++
name|Count
expr_stmt|;
comment|// Not every iteration due to dbg_value above.
block|}
specifier|const
name|std
operator|::
name|vector
operator|<
name|MachineDomTreeNode
operator|*
operator|>
operator|&
name|Children
operator|=
name|Node
operator|->
name|getChildren
argument_list|()
expr_stmt|;
for|for
control|(
name|std
operator|::
name|vector
operator|<
name|MachineDomTreeNode
operator|*
operator|>
operator|::
name|const_iterator
name|I
operator|=
name|Children
operator|.
name|begin
argument_list|()
operator|,
name|E
operator|=
name|Children
operator|.
name|end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
block|{
specifier|const
name|MachineDomTreeNode
modifier|*
name|ChildNode
init|=
operator|*
name|I
decl_stmt|;
name|MachineBasicBlock
modifier|*
name|ChildBlock
init|=
name|ChildNode
operator|->
name|getBlock
argument_list|()
decl_stmt|;
if|if
condition|(
name|Loop
operator|->
name|contains
argument_list|(
name|ChildBlock
argument_list|)
condition|)
name|VisitRegion
argument_list|(
name|ChildNode
argument_list|,
name|ChildBlock
argument_list|,
name|Loop
argument_list|,
name|LoopLiveIns
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// An individual mapping from virtual register number to SUnit.
end_comment

begin_struct
struct|struct
name|VReg2SUnit
block|{
name|unsigned
name|VirtReg
decl_stmt|;
name|SUnit
modifier|*
name|SU
decl_stmt|;
name|VReg2SUnit
argument_list|(
argument|unsigned reg
argument_list|,
argument|SUnit *su
argument_list|)
block|:
name|VirtReg
argument_list|(
name|reg
argument_list|)
operator|,
name|SU
argument_list|(
argument|su
argument_list|)
block|{}
name|unsigned
name|getSparseSetKey
argument_list|()
specifier|const
block|{
return|return
name|TargetRegisterInfo
operator|::
name|virtReg2Index
argument_list|(
name|VirtReg
argument_list|)
return|;
block|}
block|}
struct|;
end_struct

begin_comment
comment|/// Combine a SparseSet with a 1x1 vector to track physical registers.
end_comment

begin_comment
comment|/// The SparseSet allows iterating over the (few) live registers for quickly
end_comment

begin_comment
comment|/// comparing against a regmask or clearing the set.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Storage for the map is allocated once for the pass. The map can be
end_comment

begin_comment
comment|/// cleared between scheduling regions without freeing unused entries.
end_comment

begin_decl_stmt
name|class
name|Reg2SUnitsMap
block|{
name|SparseSet
operator|<
name|unsigned
operator|>
name|PhysRegSet
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|vector
operator|<
name|SUnit
operator|*
operator|>
expr|>
name|SUnits
expr_stmt|;
name|public
label|:
typedef|typedef
name|SparseSet
operator|<
name|unsigned
operator|>
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
comment|// Allow iteration over register numbers (keys) in the map. If needed, we
comment|// can provide an iterator over SUnits (values) as well.
name|const_iterator
name|reg_begin
argument_list|()
specifier|const
block|{
return|return
name|PhysRegSet
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_iterator
name|reg_end
argument_list|()
specifier|const
block|{
return|return
name|PhysRegSet
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// Initialize the map with the number of registers.
comment|/// If the map is already large enough, no allocation occurs.
comment|/// For simplicity we expect the map to be empty().
name|void
name|setRegLimit
parameter_list|(
name|unsigned
name|Limit
parameter_list|)
function_decl|;
comment|/// Returns true if the map is empty.
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|PhysRegSet
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// Clear the map without deallocating storage.
name|void
name|clear
parameter_list|()
function_decl|;
name|bool
name|contains
argument_list|(
name|unsigned
name|Reg
argument_list|)
decl|const
block|{
return|return
name|PhysRegSet
operator|.
name|count
argument_list|(
name|Reg
argument_list|)
return|;
block|}
comment|/// If this register is mapped, return its existing SUnits vector.
comment|/// Otherwise map the register and return an empty SUnits vector.
name|std
operator|::
name|vector
operator|<
name|SUnit
operator|*
operator|>
operator|&
name|operator
index|[]
operator|(
name|unsigned
name|Reg
operator|)
block|{
name|bool
name|New
operator|=
name|PhysRegSet
operator|.
name|insert
argument_list|(
name|Reg
argument_list|)
operator|.
name|second
block|;
name|assert
argument_list|(
operator|(
operator|!
name|New
operator|||
name|SUnits
index|[
name|Reg
index|]
operator|.
name|empty
argument_list|()
operator|)
operator|&&
literal|"stale SUnits vector"
argument_list|)
block|;
operator|(
name|void
operator|)
name|New
block|;
return|return
name|SUnits
index|[
name|Reg
index|]
return|;
block|}
comment|/// Erase an existing element without freeing memory.
name|void
name|erase
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
block|{
name|PhysRegSet
operator|.
name|erase
argument_list|(
name|Reg
argument_list|)
expr_stmt|;
name|SUnits
index|[
name|Reg
index|]
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// Use SparseSet as a SparseMap by relying on the fact that it never
end_comment

begin_comment
comment|/// compares ValueT's, only unsigned keys. This allows the set to be cleared
end_comment

begin_comment
comment|/// between scheduling regions in constant time as long as ValueT does not
end_comment

begin_comment
comment|/// require a destructor.
end_comment

begin_typedef
typedef|typedef
name|SparseSet
operator|<
name|VReg2SUnit
operator|>
name|VReg2SUnitMap
expr_stmt|;
end_typedef

begin_comment
comment|/// ScheduleDAGInstrs - A ScheduleDAG subclass for scheduling lists of
end_comment

begin_comment
comment|/// MachineInstrs.
end_comment

begin_decl_stmt
name|class
name|ScheduleDAGInstrs
range|:
name|public
name|ScheduleDAG
block|{
name|protected
operator|:
specifier|const
name|MachineLoopInfo
operator|&
name|MLI
block|;
specifier|const
name|MachineDominatorTree
operator|&
name|MDT
block|;
specifier|const
name|MachineFrameInfo
operator|*
name|MFI
block|;
specifier|const
name|InstrItineraryData
operator|*
name|InstrItins
block|;
comment|/// Live Intervals provides reaching defs in preRA scheduling.
name|LiveIntervals
operator|*
name|LIS
block|;
comment|/// isPostRA flag indicates vregs cannot be present.
name|bool
name|IsPostRA
block|;
comment|/// UnitLatencies (misnamed) flag avoids computing def-use latencies, using
comment|/// the def-side latency only.
name|bool
name|UnitLatencies
block|;
comment|/// The standard DAG builder does not normally include terminators as DAG
comment|/// nodes because it does not create the necessary dependencies to prevent
comment|/// reordering. A specialized scheduler can overide
comment|/// TargetInstrInfo::isSchedulingBoundary then enable this flag to indicate
comment|/// it has taken responsibility for scheduling the terminator correctly.
name|bool
name|CanHandleTerminators
block|;
comment|/// State specific to the current scheduling region.
comment|/// ------------------------------------------------
comment|/// The block in which to insert instructions
name|MachineBasicBlock
operator|*
name|BB
block|;
comment|/// The beginning of the range to be scheduled.
name|MachineBasicBlock
operator|::
name|iterator
name|RegionBegin
block|;
comment|/// The end of the range to be scheduled.
name|MachineBasicBlock
operator|::
name|iterator
name|RegionEnd
block|;
comment|/// The index in BB of RegionEnd.
name|unsigned
name|EndIndex
block|;
comment|/// After calling BuildSchedGraph, each machine instruction in the current
comment|/// scheduling region is mapped to an SUnit.
name|DenseMap
operator|<
name|MachineInstr
operator|*
block|,
name|SUnit
operator|*
operator|>
name|MISUnitMap
block|;
comment|/// State internal to DAG building.
comment|/// -------------------------------
comment|/// Defs, Uses - Remember where defs and uses of each register are as we
comment|/// iterate upward through the instructions. This is allocated here instead
comment|/// of inside BuildSchedGraph to avoid the need for it to be initialized and
comment|/// destructed for each block.
name|Reg2SUnitsMap
name|Defs
block|;
name|Reg2SUnitsMap
name|Uses
block|;
comment|/// Track the last instructon in this region defining each virtual register.
name|VReg2SUnitMap
name|VRegDefs
block|;
comment|/// PendingLoads - Remember where unknown loads are after the most recent
comment|/// unknown store, as we iterate. As with Defs and Uses, this is here
comment|/// to minimize construction/destruction.
name|std
operator|::
name|vector
operator|<
name|SUnit
operator|*
operator|>
name|PendingLoads
block|;
comment|/// LoopRegs - Track which registers are used for loop-carried dependencies.
comment|///
name|LoopDependencies
name|LoopRegs
block|;
comment|/// DbgValues - Remember instruction that preceeds DBG_VALUE.
comment|/// These are generated by buildSchedGraph but persist so they can be
comment|/// referenced when emitting the final schedule.
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|MachineInstr
operator|*
operator|,
name|MachineInstr
operator|*
operator|>
expr|>
name|DbgValueVector
expr_stmt|;
name|DbgValueVector
name|DbgValues
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MachineInstr
modifier|*
name|FirstDbgValue
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_function_decl
name|explicit
name|ScheduleDAGInstrs
parameter_list|(
name|MachineFunction
modifier|&
name|mf
parameter_list|,
specifier|const
name|MachineLoopInfo
modifier|&
name|mli
parameter_list|,
specifier|const
name|MachineDominatorTree
modifier|&
name|mdt
parameter_list|,
name|bool
name|IsPostRAFlag
parameter_list|,
name|LiveIntervals
modifier|*
name|LIS
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|virtual
operator|~
name|ScheduleDAGInstrs
argument_list|()
block|{}
comment|/// begin - Return an iterator to the top of the current scheduling region.
name|MachineBasicBlock
operator|::
name|iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|RegionBegin
return|;
block|}
end_expr_stmt

begin_comment
comment|/// end - Return an iterator to the bottom of the current scheduling region.
end_comment

begin_expr_stmt
name|MachineBasicBlock
operator|::
name|iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|RegionEnd
return|;
block|}
end_expr_stmt

begin_comment
comment|/// newSUnit - Creates a new SUnit and return a ptr to it.
end_comment

begin_function_decl
name|SUnit
modifier|*
name|newSUnit
parameter_list|(
name|MachineInstr
modifier|*
name|MI
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// getSUnit - Return an existing SUnit for this MI, or NULL.
end_comment

begin_decl_stmt
name|SUnit
modifier|*
name|getSUnit
argument_list|(
name|MachineInstr
operator|*
name|MI
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// startBlock - Prepare to perform scheduling in the given block.
end_comment

begin_function_decl
name|virtual
name|void
name|startBlock
parameter_list|(
name|MachineBasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// finishBlock - Clean up after scheduling in the given block.
end_comment

begin_function_decl
name|virtual
name|void
name|finishBlock
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Initialize the scheduler state for the next scheduling region.
end_comment

begin_decl_stmt
name|virtual
name|void
name|enterRegion
argument_list|(
name|MachineBasicBlock
operator|*
name|bb
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|begin
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|end
argument_list|,
name|unsigned
name|endcount
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Notify that the scheduler has finished scheduling the current region.
end_comment

begin_function_decl
name|virtual
name|void
name|exitRegion
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// buildSchedGraph - Build SUnits from the MachineBasicBlock that we are
end_comment

begin_comment
comment|/// input.
end_comment

begin_function_decl
name|void
name|buildSchedGraph
parameter_list|(
name|AliasAnalysis
modifier|*
name|AA
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// addSchedBarrierDeps - Add dependencies from instructions in the current
end_comment

begin_comment
comment|/// list of instructions being scheduled to scheduling barrier. We want to
end_comment

begin_comment
comment|/// make sure instructions which define registers that are either used by
end_comment

begin_comment
comment|/// the terminator or are live-out are properly scheduled. This is
end_comment

begin_comment
comment|/// especially important when the definition latency of the return value(s)
end_comment

begin_comment
comment|/// are too high to be hidden by the branch or when the liveout registers
end_comment

begin_comment
comment|/// used by instructions in the fallthrough block.
end_comment

begin_function_decl
name|void
name|addSchedBarrierDeps
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// computeLatency - Compute node latency.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
name|virtual
name|void
name|computeLatency
parameter_list|(
name|SUnit
modifier|*
name|SU
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// computeOperandLatency - Override dependence edge latency using
end_comment

begin_comment
comment|/// operand use/def information
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|virtual
name|void
name|computeOperandLatency
argument_list|(
name|SUnit
operator|*
name|Def
argument_list|,
name|SUnit
operator|*
name|Use
argument_list|,
name|SDep
operator|&
name|dep
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// schedule - Order nodes according to selected style, filling
end_comment

begin_comment
comment|/// in the Sequence member.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Typically, a scheduling algorithm will implement schedule() without
end_comment

begin_comment
comment|/// overriding enterRegion() or exitRegion().
end_comment

begin_function_decl
name|virtual
name|void
name|schedule
parameter_list|()
init|=
literal|0
function_decl|;
end_function_decl

begin_comment
comment|/// finalizeSchedule - Allow targets to perform final scheduling actions at
end_comment

begin_comment
comment|/// the level of the whole MachineFunction. By default does nothing.
end_comment

begin_function
name|virtual
name|void
name|finalizeSchedule
parameter_list|()
block|{}
end_function

begin_decl_stmt
name|virtual
name|void
name|dumpNode
argument_list|(
specifier|const
name|SUnit
operator|*
name|SU
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Return a label for a DAG node that points to an instruction.
end_comment

begin_expr_stmt
name|virtual
name|std
operator|::
name|string
name|getGraphNodeLabel
argument_list|(
argument|const SUnit *SU
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Return a label for the region of code covered by the DAG.
end_comment

begin_expr_stmt
name|virtual
name|std
operator|::
name|string
name|getDAGName
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_label
name|protected
label|:
end_label

begin_function_decl
name|void
name|initSUnits
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|addPhysRegDataDeps
parameter_list|(
name|SUnit
modifier|*
name|SU
parameter_list|,
specifier|const
name|MachineOperand
modifier|&
name|MO
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|addPhysRegDeps
parameter_list|(
name|SUnit
modifier|*
name|SU
parameter_list|,
name|unsigned
name|OperIdx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|addVRegDefDeps
parameter_list|(
name|SUnit
modifier|*
name|SU
parameter_list|,
name|unsigned
name|OperIdx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|addVRegUseDeps
parameter_list|(
name|SUnit
modifier|*
name|SU
parameter_list|,
name|unsigned
name|OperIdx
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|VReg2SUnitMap
operator|::
name|iterator
name|findVRegDef
argument_list|(
argument|unsigned VirtReg
argument_list|)
block|{
return|return
name|VRegDefs
operator|.
name|find
argument_list|(
name|TargetRegisterInfo
operator|::
name|virtReg2Index
argument_list|(
name|VirtReg
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// newSUnit - Creates a new SUnit and return a ptr to it.
end_comment

begin_expr_stmt
specifier|inline
name|SUnit
operator|*
name|ScheduleDAGInstrs
operator|::
name|newSUnit
argument_list|(
argument|MachineInstr *MI
argument_list|)
block|{
ifndef|#
directive|ifndef
name|NDEBUG
specifier|const
name|SUnit
operator|*
name|Addr
operator|=
name|SUnits
operator|.
name|empty
argument_list|()
operator|?
literal|0
operator|:
operator|&
name|SUnits
index|[
literal|0
index|]
block|;
endif|#
directive|endif
name|SUnits
operator|.
name|push_back
argument_list|(
name|SUnit
argument_list|(
name|MI
argument_list|,
operator|(
name|unsigned
operator|)
name|SUnits
operator|.
name|size
argument_list|()
argument_list|)
argument_list|)
block|;
name|assert
argument_list|(
operator|(
name|Addr
operator|==
literal|0
operator|||
name|Addr
operator|==
operator|&
name|SUnits
index|[
literal|0
index|]
operator|)
operator|&&
literal|"SUnits std::vector reallocated on the fly!"
argument_list|)
block|;
name|SUnits
operator|.
name|back
argument_list|()
operator|.
name|OrigNode
operator|=
operator|&
name|SUnits
operator|.
name|back
argument_list|()
block|;
return|return
operator|&
name|SUnits
operator|.
name|back
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getSUnit - Return an existing SUnit for this MI, or NULL.
end_comment

begin_expr_stmt
specifier|inline
name|SUnit
operator|*
name|ScheduleDAGInstrs
operator|::
name|getSUnit
argument_list|(
argument|MachineInstr *MI
argument_list|)
specifier|const
block|{
name|DenseMap
operator|<
name|MachineInstr
operator|*
block|,
name|SUnit
operator|*
operator|>
operator|::
name|const_iterator
name|I
operator|=
name|MISUnitMap
operator|.
name|find
argument_list|(
name|MI
argument_list|)
block|;
if|if
condition|(
name|I
operator|==
name|MISUnitMap
operator|.
name|end
argument_list|()
condition|)
return|return
literal|0
return|;
end_expr_stmt

begin_return
return|return
name|I
operator|->
name|second
return|;
end_return

begin_comment
unit|} }
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

