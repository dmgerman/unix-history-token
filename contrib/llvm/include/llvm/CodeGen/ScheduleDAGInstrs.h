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
name|LLVM_CODEGEN_SCHEDULEDAGINSTRS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_SCHEDULEDAGINSTRS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SparseSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SparseMultiSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ScheduleDAG.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/TargetSchedule.h"
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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineFrameInfo
decl_stmt|;
name|class
name|MachineLoopInfo
decl_stmt|;
name|class
name|MachineDominatorTree
decl_stmt|;
name|class
name|LiveIntervals
decl_stmt|;
name|class
name|RegPressureTracker
decl_stmt|;
name|class
name|PressureDiffs
decl_stmt|;
comment|/// An individual mapping from virtual register number to SUnit.
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
name|getSparseSetIndex
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
comment|/// Record a physical register access.
comment|/// For non data-dependent uses, OpIdx == -1.
struct|struct
name|PhysRegSUOper
block|{
name|SUnit
modifier|*
name|SU
decl_stmt|;
name|int
name|OpIdx
decl_stmt|;
name|unsigned
name|Reg
decl_stmt|;
name|PhysRegSUOper
argument_list|(
argument|SUnit *su
argument_list|,
argument|int op
argument_list|,
argument|unsigned R
argument_list|)
block|:
name|SU
argument_list|(
name|su
argument_list|)
operator|,
name|OpIdx
argument_list|(
name|op
argument_list|)
operator|,
name|Reg
argument_list|(
argument|R
argument_list|)
block|{}
name|unsigned
name|getSparseSetIndex
argument_list|()
specifier|const
block|{
return|return
name|Reg
return|;
block|}
block|}
struct|;
comment|/// Use a SparseMultiSet to track physical registers. Storage is only
comment|/// allocated once for the pass. It can be cleared in constant time and reused
comment|/// without any frees.
typedef|typedef
name|SparseMultiSet
operator|<
name|PhysRegSUOper
operator|,
name|llvm
operator|::
name|identity
operator|<
name|unsigned
operator|>
operator|,
name|uint16_t
operator|>
name|Reg2SUnitsMap
expr_stmt|;
comment|/// Use SparseSet as a SparseMap by relying on the fact that it never
comment|/// compares ValueT's, only unsigned keys. This allows the set to be cleared
comment|/// between scheduling regions in constant time as long as ValueT does not
comment|/// require a destructor.
typedef|typedef
name|SparseSet
operator|<
name|VReg2SUnit
operator|,
name|VirtReg2IndexFunctor
operator|>
name|VReg2SUnitMap
expr_stmt|;
comment|/// Track local uses of virtual registers. These uses are gathered by the DAG
comment|/// builder and may be consulted by the scheduler to avoid iterating an entire
comment|/// vreg use list.
typedef|typedef
name|SparseMultiSet
operator|<
name|VReg2SUnit
operator|,
name|VirtReg2IndexFunctor
operator|>
name|VReg2UseMap
expr_stmt|;
comment|/// ScheduleDAGInstrs - A ScheduleDAG subclass for scheduling lists of
comment|/// MachineInstrs.
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
comment|/// Live Intervals provides reaching defs in preRA scheduling.
name|LiveIntervals
operator|*
name|LIS
block|;
comment|/// TargetSchedModel provides an interface to the machine model.
name|TargetSchedModel
name|SchedModel
block|;
comment|/// isPostRA flag indicates vregs cannot be present.
name|bool
name|IsPostRA
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
comment|/// Instructions in this region (distance(RegionBegin, RegionEnd)).
name|unsigned
name|NumRegionInstrs
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
comment|/// After calling BuildSchedGraph, each vreg used in the scheduling region
comment|/// is mapped to a set of SUnits. These include all local vreg uses, not
comment|/// just the uses for a singly defined vreg.
name|VReg2UseMap
name|VRegUses
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
comment|/// Track the last instruction in this region defining each virtual register.
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
comment|/// DbgValues - Remember instruction that precedes DBG_VALUE.
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
name|MachineInstr
modifier|*
name|FirstDbgValue
decl_stmt|;
name|public
label|:
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
name|virtual
operator|~
name|ScheduleDAGInstrs
argument_list|()
block|{}
comment|/// \brief Expose LiveIntervals for use in DAG mutators and such.
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
comment|/// \brief Get the machine model for instruction scheduling.
specifier|const
name|TargetSchedModel
operator|*
name|getSchedModel
argument_list|()
specifier|const
block|{
return|return
operator|&
name|SchedModel
return|;
block|}
comment|/// \brief Resolve and cache a resolved scheduling class for an SUnit.
specifier|const
name|MCSchedClassDesc
modifier|*
name|getSchedClass
argument_list|(
name|SUnit
operator|*
name|SU
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|SU
operator|->
name|SchedClass
operator|&&
name|SchedModel
operator|.
name|hasInstrSchedModel
argument_list|()
condition|)
name|SU
operator|->
name|SchedClass
operator|=
name|SchedModel
operator|.
name|resolveSchedClass
argument_list|(
name|SU
operator|->
name|getInstr
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|SU
operator|->
name|SchedClass
return|;
block|}
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
comment|/// end - Return an iterator to the bottom of the current scheduling region.
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
comment|/// newSUnit - Creates a new SUnit and return a ptr to it.
name|SUnit
modifier|*
name|newSUnit
parameter_list|(
name|MachineInstr
modifier|*
name|MI
parameter_list|)
function_decl|;
comment|/// getSUnit - Return an existing SUnit for this MI, or NULL.
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
comment|/// startBlock - Prepare to perform scheduling in the given block.
name|virtual
name|void
name|startBlock
parameter_list|(
name|MachineBasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
comment|/// finishBlock - Clean up after scheduling in the given block.
name|virtual
name|void
name|finishBlock
parameter_list|()
function_decl|;
comment|/// Initialize the scheduler state for the next scheduling region.
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
name|regioninstrs
argument_list|)
decl_stmt|;
comment|/// Notify that the scheduler has finished scheduling the current region.
name|virtual
name|void
name|exitRegion
parameter_list|()
function_decl|;
comment|/// buildSchedGraph - Build SUnits from the MachineBasicBlock that we are
comment|/// input.
name|void
name|buildSchedGraph
parameter_list|(
name|AliasAnalysis
modifier|*
name|AA
parameter_list|,
name|RegPressureTracker
modifier|*
name|RPTracker
init|=
literal|0
parameter_list|,
name|PressureDiffs
modifier|*
name|PDiffs
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// addSchedBarrierDeps - Add dependencies from instructions in the current
comment|/// list of instructions being scheduled to scheduling barrier. We want to
comment|/// make sure instructions which define registers that are either used by
comment|/// the terminator or are live-out are properly scheduled. This is
comment|/// especially important when the definition latency of the return value(s)
comment|/// are too high to be hidden by the branch or when the liveout registers
comment|/// used by instructions in the fallthrough block.
name|void
name|addSchedBarrierDeps
parameter_list|()
function_decl|;
comment|/// schedule - Order nodes according to selected style, filling
comment|/// in the Sequence member.
comment|///
comment|/// Typically, a scheduling algorithm will implement schedule() without
comment|/// overriding enterRegion() or exitRegion().
name|virtual
name|void
name|schedule
parameter_list|()
init|=
literal|0
function_decl|;
comment|/// finalizeSchedule - Allow targets to perform final scheduling actions at
comment|/// the level of the whole MachineFunction. By default does nothing.
name|virtual
name|void
name|finalizeSchedule
parameter_list|()
block|{}
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
comment|/// Return a label for a DAG node that points to an instruction.
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
comment|/// Return a label for the region of code covered by the DAG.
name|virtual
name|std
operator|::
name|string
name|getDAGName
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
name|void
name|initSUnits
parameter_list|()
function_decl|;
name|void
name|addPhysRegDataDeps
parameter_list|(
name|SUnit
modifier|*
name|SU
parameter_list|,
name|unsigned
name|OperIdx
parameter_list|)
function_decl|;
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
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
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

