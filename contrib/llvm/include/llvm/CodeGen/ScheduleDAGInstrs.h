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
file|"llvm/ADT/MapVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SparseMultiSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SparseSet.h"
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

begin_include
include|#
directive|include
file|<list>
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
name|LaneBitmask
name|LaneMask
decl_stmt|;
name|SUnit
modifier|*
name|SU
decl_stmt|;
name|VReg2SUnit
argument_list|(
argument|unsigned VReg
argument_list|,
argument|LaneBitmask LaneMask
argument_list|,
argument|SUnit *SU
argument_list|)
block|:
name|VirtReg
argument_list|(
name|VReg
argument_list|)
operator|,
name|LaneMask
argument_list|(
name|LaneMask
argument_list|)
operator|,
name|SU
argument_list|(
argument|SU
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
comment|/// Mapping from virtual register to SUnit including an operand index.
name|struct
name|VReg2SUnitOperIdx
range|:
name|public
name|VReg2SUnit
block|{
name|unsigned
name|OperandIndex
block|;
name|VReg2SUnitOperIdx
argument_list|(
argument|unsigned VReg
argument_list|,
argument|LaneBitmask LaneMask
argument_list|,
argument|unsigned OperandIndex
argument_list|,
argument|SUnit *SU
argument_list|)
operator|:
name|VReg2SUnit
argument_list|(
name|VReg
argument_list|,
name|LaneMask
argument_list|,
name|SU
argument_list|)
block|,
name|OperandIndex
argument_list|(
argument|OperandIndex
argument_list|)
block|{}
block|}
decl_stmt|;
comment|/// Record a physical register access.
comment|/// For non-data-dependent uses, OpIdx == -1.
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
name|VReg2SUnitMultiMap
expr_stmt|;
typedef|typedef
name|SparseMultiSet
operator|<
name|VReg2SUnitOperIdx
operator|,
name|VirtReg2IndexFunctor
operator|>
name|VReg2SUnitOperIdxMultiMap
expr_stmt|;
typedef|typedef
name|PointerUnion
operator|<
specifier|const
name|Value
operator|*
operator|,
specifier|const
name|PseudoSourceValue
operator|*
operator|>
name|ValueType
expr_stmt|;
name|struct
name|UnderlyingObject
range|:
name|PointerIntPair
operator|<
name|ValueType
decl_stmt|, 1,
name|bool
decl|>
block|{
name|UnderlyingObject
argument_list|(
argument|ValueType V
argument_list|,
argument|bool MayAlias
argument_list|)
block|:
name|PointerIntPair
operator|<
name|ValueType
operator|,
literal|1
operator|,
name|bool
operator|>
operator|(
name|V
operator|,
name|MayAlias
operator|)
block|{}
name|ValueType
name|getValue
argument_list|()
specifier|const
block|{
return|return
name|getPointer
argument_list|()
return|;
block|}
name|bool
name|mayAlias
argument_list|()
specifier|const
block|{
return|return
name|getInt
argument_list|()
return|;
block|}
block|}
empty_stmt|;
typedef|typedef
name|SmallVector
operator|<
name|UnderlyingObject
operator|,
literal|4
operator|>
name|UnderlyingObjectsVector
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
operator|*
name|MLI
block|;
specifier|const
name|MachineFrameInfo
operator|&
name|MFI
block|;
comment|/// TargetSchedModel provides an interface to the machine model.
name|TargetSchedModel
name|SchedModel
block|;
comment|/// True if the DAG builder should remove kill flags (in preparation for
comment|/// rescheduling).
name|bool
name|RemoveKillFlags
block|;
comment|/// The standard DAG builder does not normally include terminators as DAG
comment|/// nodes because it does not create the necessary dependencies to prevent
comment|/// reordering. A specialized scheduler can override
comment|/// TargetInstrInfo::isSchedulingBoundary then enable this flag to indicate
comment|/// it has taken responsibility for scheduling the terminator correctly.
name|bool
name|CanHandleTerminators
block|;
comment|/// Whether lane masks should get tracked.
name|bool
name|TrackLaneMasks
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
comment|/// Tracks the last instruction(s) in this region defining each virtual
comment|/// register. There may be multiple current definitions for a register with
comment|/// disjunct lanemasks.
name|VReg2SUnitMultiMap
name|CurrentVRegDefs
block|;
comment|/// Tracks the last instructions in this region using each virtual register.
name|VReg2SUnitOperIdxMultiMap
name|CurrentVRegUses
block|;
name|AliasAnalysis
operator|*
name|AAForDep
block|;
comment|/// Remember a generic side-effecting instruction as we proceed.
comment|/// No other SU ever gets scheduled around it (except in the special
comment|/// case of a huge region that gets reduced).
name|SUnit
operator|*
name|BarrierChain
block|;
name|public
operator|:
comment|/// A list of SUnits, used in Value2SUsMap, during DAG construction.
comment|/// Note: to gain speed it might be worth investigating an optimized
comment|/// implementation of this data structure, such as a singly linked list
comment|/// with a memory pool (SmallVector was tried but slow and SparseSet is not
comment|/// applicable).
typedef|typedef
name|std
operator|::
name|list
operator|<
name|SUnit
operator|*
operator|>
name|SUList
expr_stmt|;
name|protected
operator|:
comment|/// A map from ValueType to SUList, used during DAG construction,
comment|/// as a means of remembering which SUs depend on which memory
comment|/// locations.
name|class
name|Value2SUsMap
decl_stmt|;
comment|/// Remove in FIFO order some SUs from huge maps.
name|void
name|reduceHugeMemNodeMaps
parameter_list|(
name|Value2SUsMap
modifier|&
name|stores
parameter_list|,
name|Value2SUsMap
modifier|&
name|loads
parameter_list|,
name|unsigned
name|N
parameter_list|)
function_decl|;
comment|/// Add a chain edge between SUa and SUb, but only if both AliasAnalysis
comment|/// and Target fail to deny the dependency.
name|void
name|addChainDependency
parameter_list|(
name|SUnit
modifier|*
name|SUa
parameter_list|,
name|SUnit
modifier|*
name|SUb
parameter_list|,
name|unsigned
name|Latency
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// Add dependencies as needed from all SUs in list to SU.
name|void
name|addChainDependencies
parameter_list|(
name|SUnit
modifier|*
name|SU
parameter_list|,
name|SUList
modifier|&
name|sus
parameter_list|,
name|unsigned
name|Latency
parameter_list|)
block|{
for|for
control|(
name|auto
operator|*
name|su
operator|:
name|sus
control|)
name|addChainDependency
argument_list|(
name|SU
argument_list|,
name|su
argument_list|,
name|Latency
argument_list|)
expr_stmt|;
block|}
comment|/// Add dependencies as needed from all SUs in map, to SU.
name|void
name|addChainDependencies
parameter_list|(
name|SUnit
modifier|*
name|SU
parameter_list|,
name|Value2SUsMap
modifier|&
name|Val2SUsMap
parameter_list|)
function_decl|;
comment|/// Add dependencies as needed to SU, from all SUs mapped to V.
name|void
name|addChainDependencies
parameter_list|(
name|SUnit
modifier|*
name|SU
parameter_list|,
name|Value2SUsMap
modifier|&
name|Val2SUsMap
parameter_list|,
name|ValueType
name|V
parameter_list|)
function_decl|;
comment|/// Add barrier chain edges from all SUs in map, and then clear
comment|/// the map. This is equivalent to insertBarrierChain(), but
comment|/// optimized for the common case where the new BarrierChain (a
comment|/// global memory object) has a higher NodeNum than all SUs in
comment|/// map. It is assumed BarrierChain has been set before calling
comment|/// this.
name|void
name|addBarrierChain
parameter_list|(
name|Value2SUsMap
modifier|&
name|map
parameter_list|)
function_decl|;
comment|/// Insert a barrier chain in a huge region, far below current
comment|/// SU. Add barrier chain edges from all SUs in map with higher
comment|/// NodeNums than this new BarrierChain, and remove them from
comment|/// map. It is assumed BarrierChain has been set before calling
comment|/// this.
name|void
name|insertBarrierChain
parameter_list|(
name|Value2SUsMap
modifier|&
name|map
parameter_list|)
function_decl|;
comment|/// For an unanalyzable memory access, this Value is used in maps.
name|UndefValue
modifier|*
name|UnknownValue
decl_stmt|;
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
comment|/// Set of live physical registers for updating kill flags.
name|BitVector
name|LiveRegs
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
modifier|*
name|mli
parameter_list|,
name|bool
name|RemoveKillFlags
init|=
name|false
parameter_list|)
function_decl|;
operator|~
name|ScheduleDAGInstrs
argument_list|()
name|override
block|{}
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
name|nullptr
parameter_list|,
name|PressureDiffs
modifier|*
name|PDiffs
init|=
name|nullptr
parameter_list|,
name|LiveIntervals
modifier|*
name|LIS
init|=
name|nullptr
parameter_list|,
name|bool
name|TrackLaneMasks
init|=
name|false
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
name|void
name|dumpNode
argument_list|(
specifier|const
name|SUnit
operator|*
name|SU
argument_list|)
decl|const
name|override
decl_stmt|;
comment|/// Return a label for a DAG node that points to an instruction.
name|std
operator|::
name|string
name|getGraphNodeLabel
argument_list|(
argument|const SUnit *SU
argument_list|)
specifier|const
name|override
expr_stmt|;
comment|/// Return a label for the region of code covered by the DAG.
name|std
operator|::
name|string
name|getDAGName
argument_list|()
specifier|const
name|override
expr_stmt|;
comment|/// \brief Fix register kill flags that scheduling has made invalid.
name|void
name|fixupKills
parameter_list|(
name|MachineBasicBlock
modifier|*
name|MBB
parameter_list|)
function_decl|;
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
comment|/// \brief PostRA helper for rewriting kill flags.
name|void
name|startBlockForKills
parameter_list|(
name|MachineBasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
comment|/// \brief Toggle a register operand kill flag.
comment|///
comment|/// Other adjustments may be made to the instruction if necessary. Return
comment|/// true if the operand has been deleted, false if not.
name|bool
name|toggleKillFlag
parameter_list|(
name|MachineInstr
modifier|*
name|MI
parameter_list|,
name|MachineOperand
modifier|&
name|MO
parameter_list|)
function_decl|;
comment|/// Returns a mask for which lanes get read/written by the given (register)
comment|/// machine operand.
name|LaneBitmask
name|getLaneMaskForMO
argument_list|(
specifier|const
name|MachineOperand
operator|&
name|MO
argument_list|)
decl|const
decl_stmt|;
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
name|nullptr
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
name|emplace_back
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
block|;
name|assert
argument_list|(
operator|(
name|Addr
operator|==
name|nullptr
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
name|nullptr
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

