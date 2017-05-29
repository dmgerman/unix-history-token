begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/CodeGen/ScheduleDAG.h - Common Base Class -----------*- C++ -*-===//
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
comment|/// \file Implements the ScheduleDAG class, which is used as the common base
end_comment

begin_comment
comment|/// class for instruction schedulers. This encapsulates the scheduling DAG,
end_comment

begin_comment
comment|/// which is shared between SelectionDAG and MachineInstr scheduling.
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
name|LLVM_CODEGEN_SCHEDULEDAG_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_SCHEDULEDAG_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/BitVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/GraphTraits.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/iterator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PointerIntPair.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineInstr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetLowering.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<iterator>
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
name|template
operator|<
name|class
name|Graph
operator|>
name|class
name|GraphWriter
expr_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MachineRegisterInfo
decl_stmt|;
name|class
name|MCInstrDesc
decl_stmt|;
struct_decl|struct
name|MCSchedClassDesc
struct_decl|;
name|class
name|ScheduleDAG
decl_stmt|;
name|class
name|SDNode
decl_stmt|;
name|class
name|SUnit
decl_stmt|;
name|class
name|TargetInstrInfo
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
name|class
name|TargetRegisterClass
decl_stmt|;
name|class
name|TargetRegisterInfo
decl_stmt|;
comment|/// Scheduling dependency. This represents one direction of an edge in the
comment|/// scheduling DAG.
name|class
name|SDep
block|{
name|public
label|:
comment|/// These are the different kinds of scheduling dependencies.
enum|enum
name|Kind
block|{
name|Data
block|,
comment|///< Regular data dependence (aka true-dependence).
name|Anti
block|,
comment|///< A register anti-dependence (aka WAR).
name|Output
block|,
comment|///< A register output-dependence (aka WAW).
name|Order
comment|///< Any other ordering dependency.
block|}
enum|;
comment|// Strong dependencies must be respected by the scheduler. Artificial
comment|// dependencies may be removed only if they are redundant with another
comment|// strong dependence.
comment|//
comment|// Weak dependencies may be violated by the scheduling strategy, but only if
comment|// the strategy can prove it is correct to do so.
comment|//
comment|// Strong OrderKinds must occur before "Weak".
comment|// Weak OrderKinds must occur after "Weak".
enum|enum
name|OrderKind
block|{
name|Barrier
block|,
comment|///< An unknown scheduling barrier.
name|MayAliasMem
block|,
comment|///< Nonvolatile load/Store instructions that may alias.
name|MustAliasMem
block|,
comment|///< Nonvolatile load/Store instructions that must alias.
name|Artificial
block|,
comment|///< Arbitrary strong DAG edge (no real dependence).
name|Weak
block|,
comment|///< Arbitrary weak DAG edge.
name|Cluster
comment|///< Weak DAG edge linking a chain of clustered instrs.
block|}
enum|;
name|private
label|:
comment|/// \brief A pointer to the depending/depended-on SUnit, and an enum
comment|/// indicating the kind of the dependency.
name|PointerIntPair
operator|<
name|SUnit
operator|*
operator|,
literal|2
operator|,
name|Kind
operator|>
name|Dep
expr_stmt|;
comment|/// A union discriminated by the dependence kind.
union|union
block|{
comment|/// For Data, Anti, and Output dependencies, the associated register. For
comment|/// Data dependencies that don't currently have a register/ assigned, this
comment|/// is set to zero.
name|unsigned
name|Reg
decl_stmt|;
comment|/// Additional information about Order dependencies.
name|unsigned
name|OrdKind
decl_stmt|;
comment|// enum OrderKind
block|}
name|Contents
union|;
comment|/// The time associated with this edge. Often this is just the value of the
comment|/// Latency field of the predecessor, however advanced models may provide
comment|/// additional information about specific edges.
name|unsigned
name|Latency
decl_stmt|;
name|public
label|:
comment|/// Constructs a null SDep. This is only for use by container classes which
comment|/// require default constructors. SUnits may not/ have null SDep edges.
name|SDep
argument_list|()
operator|:
name|Dep
argument_list|(
argument|nullptr
argument_list|,
argument|Data
argument_list|)
block|{}
comment|/// Constructs an SDep with the specified values.
name|SDep
argument_list|(
argument|SUnit *S
argument_list|,
argument|Kind kind
argument_list|,
argument|unsigned Reg
argument_list|)
operator|:
name|Dep
argument_list|(
name|S
argument_list|,
name|kind
argument_list|)
operator|,
name|Contents
argument_list|()
block|{
switch|switch
condition|(
name|kind
condition|)
block|{
default|default:
name|llvm_unreachable
argument_list|(
literal|"Reg given for non-register dependence!"
argument_list|)
expr_stmt|;
case|case
name|Anti
case|:
case|case
name|Output
case|:
name|assert
argument_list|(
name|Reg
operator|!=
literal|0
operator|&&
literal|"SDep::Anti and SDep::Output must use a non-zero Reg!"
argument_list|)
expr_stmt|;
name|Contents
operator|.
name|Reg
operator|=
name|Reg
expr_stmt|;
name|Latency
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|Data
case|:
name|Contents
operator|.
name|Reg
operator|=
name|Reg
expr_stmt|;
name|Latency
operator|=
literal|1
expr_stmt|;
break|break;
block|}
block|}
name|SDep
argument_list|(
argument|SUnit *S
argument_list|,
argument|OrderKind kind
argument_list|)
operator|:
name|Dep
argument_list|(
name|S
argument_list|,
name|Order
argument_list|)
operator|,
name|Contents
argument_list|()
operator|,
name|Latency
argument_list|(
literal|0
argument_list|)
block|{
name|Contents
operator|.
name|OrdKind
operator|=
name|kind
block|;     }
comment|/// Returns true if the specified SDep is equivalent except for latency.
name|bool
name|overlaps
argument_list|(
argument|const SDep&Other
argument_list|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|SDep
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|overlaps
argument_list|(
name|Other
argument_list|)
operator|&&
name|Latency
operator|==
name|Other
operator|.
name|Latency
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|SDep
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|Other
operator|)
return|;
block|}
comment|/// \brief Returns the latency value for this edge, which roughly means the
comment|/// minimum number of cycles that must elapse between the predecessor and
comment|/// the successor, given that they have this edge between them.
name|unsigned
name|getLatency
argument_list|()
specifier|const
block|{
return|return
name|Latency
return|;
block|}
comment|/// Sets the latency for this edge.
name|void
name|setLatency
parameter_list|(
name|unsigned
name|Lat
parameter_list|)
block|{
name|Latency
operator|=
name|Lat
expr_stmt|;
block|}
comment|//// Returns the SUnit to which this edge points.
name|SUnit
operator|*
name|getSUnit
argument_list|()
specifier|const
expr_stmt|;
comment|//// Assigns the SUnit to which this edge points.
name|void
name|setSUnit
parameter_list|(
name|SUnit
modifier|*
name|SU
parameter_list|)
function_decl|;
comment|/// Returns an enum value representing the kind of the dependence.
name|Kind
name|getKind
argument_list|()
specifier|const
expr_stmt|;
comment|/// Shorthand for getKind() != SDep::Data.
name|bool
name|isCtrl
argument_list|()
specifier|const
block|{
return|return
name|getKind
argument_list|()
operator|!=
name|Data
return|;
block|}
comment|/// \brief Tests if this is an Order dependence between two memory accesses
comment|/// where both sides of the dependence access memory in non-volatile and
comment|/// fully modeled ways.
name|bool
name|isNormalMemory
argument_list|()
specifier|const
block|{
return|return
name|getKind
argument_list|()
operator|==
name|Order
operator|&&
operator|(
name|Contents
operator|.
name|OrdKind
operator|==
name|MayAliasMem
operator|||
name|Contents
operator|.
name|OrdKind
operator|==
name|MustAliasMem
operator|)
return|;
block|}
comment|/// Tests if this is an Order dependence that is marked as a barrier.
name|bool
name|isBarrier
argument_list|()
specifier|const
block|{
return|return
name|getKind
argument_list|()
operator|==
name|Order
operator|&&
name|Contents
operator|.
name|OrdKind
operator|==
name|Barrier
return|;
block|}
comment|/// Tests if this is could be any kind of memory dependence.
name|bool
name|isNormalMemoryOrBarrier
argument_list|()
specifier|const
block|{
return|return
operator|(
name|isNormalMemory
argument_list|()
operator|||
name|isBarrier
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Tests if this is an Order dependence that is marked as
comment|/// "must alias", meaning that the SUnits at either end of the edge have a
comment|/// memory dependence on a known memory location.
name|bool
name|isMustAlias
argument_list|()
specifier|const
block|{
return|return
name|getKind
argument_list|()
operator|==
name|Order
operator|&&
name|Contents
operator|.
name|OrdKind
operator|==
name|MustAliasMem
return|;
block|}
comment|/// Tests if this a weak dependence. Weak dependencies are considered DAG
comment|/// edges for height computation and other heuristics, but do not force
comment|/// ordering. Breaking a weak edge may require the scheduler to compensate,
comment|/// for example by inserting a copy.
name|bool
name|isWeak
argument_list|()
specifier|const
block|{
return|return
name|getKind
argument_list|()
operator|==
name|Order
operator|&&
name|Contents
operator|.
name|OrdKind
operator|>=
name|Weak
return|;
block|}
comment|/// \brief Tests if this is an Order dependence that is marked as
comment|/// "artificial", meaning it isn't necessary for correctness.
name|bool
name|isArtificial
argument_list|()
specifier|const
block|{
return|return
name|getKind
argument_list|()
operator|==
name|Order
operator|&&
name|Contents
operator|.
name|OrdKind
operator|==
name|Artificial
return|;
block|}
comment|/// \brief Tests if this is an Order dependence that is marked as "cluster",
comment|/// meaning it is artificial and wants to be adjacent.
name|bool
name|isCluster
argument_list|()
specifier|const
block|{
return|return
name|getKind
argument_list|()
operator|==
name|Order
operator|&&
name|Contents
operator|.
name|OrdKind
operator|==
name|Cluster
return|;
block|}
comment|/// Tests if this is a Data dependence that is associated with a register.
name|bool
name|isAssignedRegDep
argument_list|()
specifier|const
block|{
return|return
name|getKind
argument_list|()
operator|==
name|Data
operator|&&
name|Contents
operator|.
name|Reg
operator|!=
literal|0
return|;
block|}
comment|/// Returns the register associated with this edge. This is only valid on
comment|/// Data, Anti, and Output edges. On Data edges, this value may be zero,
comment|/// meaning there is no associated register.
name|unsigned
name|getReg
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|(
name|getKind
argument_list|()
operator|==
name|Data
operator|||
name|getKind
argument_list|()
operator|==
name|Anti
operator|||
name|getKind
argument_list|()
operator|==
name|Output
operator|)
operator|&&
literal|"getReg called on non-register dependence edge!"
argument_list|)
block|;
return|return
name|Contents
operator|.
name|Reg
return|;
block|}
comment|/// Assigns the associated register for this edge. This is only valid on
comment|/// Data, Anti, and Output edges. On Anti and Output edges, this value must
comment|/// not be zero. On Data edges, the value may be zero, which would mean that
comment|/// no specific register is associated with this edge.
name|void
name|setReg
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
block|{
name|assert
argument_list|(
operator|(
name|getKind
argument_list|()
operator|==
name|Data
operator|||
name|getKind
argument_list|()
operator|==
name|Anti
operator|||
name|getKind
argument_list|()
operator|==
name|Output
operator|)
operator|&&
literal|"setReg called on non-register dependence edge!"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|(
name|getKind
argument_list|()
operator|!=
name|Anti
operator|||
name|Reg
operator|!=
literal|0
operator|)
operator|&&
literal|"SDep::Anti edge cannot use the zero register!"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|(
name|getKind
argument_list|()
operator|!=
name|Output
operator|||
name|Reg
operator|!=
literal|0
operator|)
operator|&&
literal|"SDep::Output edge cannot use the zero register!"
argument_list|)
expr_stmt|;
name|Contents
operator|.
name|Reg
operator|=
name|Reg
expr_stmt|;
block|}
block|}
empty_stmt|;
name|template
operator|<
operator|>
expr|struct
name|isPodLike
operator|<
name|SDep
operator|>
block|{
specifier|static
specifier|const
name|bool
name|value
operator|=
name|true
block|; }
expr_stmt|;
comment|/// Scheduling unit. This is a node in the scheduling DAG.
name|class
name|SUnit
block|{
name|private
label|:
enum_decl|enum :
name|unsigned
block|{
name|BoundaryID
init|=
operator|~
literal|0u
block|}
enum_decl|;
name|SDNode
modifier|*
name|Node
init|=
name|nullptr
decl_stmt|;
comment|///< Representative node.
name|MachineInstr
modifier|*
name|Instr
init|=
name|nullptr
decl_stmt|;
comment|///< Alternatively, a MachineInstr.
name|public
label|:
name|SUnit
modifier|*
name|OrigNode
init|=
name|nullptr
decl_stmt|;
comment|///< If not this, the node from which this node
comment|/// was cloned. (SD scheduling only)
specifier|const
name|MCSchedClassDesc
modifier|*
name|SchedClass
init|=
name|nullptr
decl_stmt|;
comment|///< nullptr or resolved SchedClass.
name|SmallVector
operator|<
name|SDep
operator|,
literal|4
operator|>
name|Preds
expr_stmt|;
comment|///< All sunit predecessors.
name|SmallVector
operator|<
name|SDep
operator|,
literal|4
operator|>
name|Succs
expr_stmt|;
comment|///< All sunit successors.
typedef|typedef
name|SmallVectorImpl
operator|<
name|SDep
operator|>
operator|::
name|iterator
name|pred_iterator
expr_stmt|;
typedef|typedef
name|SmallVectorImpl
operator|<
name|SDep
operator|>
operator|::
name|iterator
name|succ_iterator
expr_stmt|;
typedef|typedef
name|SmallVectorImpl
operator|<
name|SDep
operator|>
operator|::
name|const_iterator
name|const_pred_iterator
expr_stmt|;
typedef|typedef
name|SmallVectorImpl
operator|<
name|SDep
operator|>
operator|::
name|const_iterator
name|const_succ_iterator
expr_stmt|;
name|unsigned
name|NodeNum
init|=
name|BoundaryID
decl_stmt|;
comment|///< Entry # of node in the node vector.
name|unsigned
name|NodeQueueId
init|=
literal|0
decl_stmt|;
comment|///< Queue id of node.
name|unsigned
name|NumPreds
init|=
literal|0
decl_stmt|;
comment|///< # of SDep::Data preds.
name|unsigned
name|NumSuccs
init|=
literal|0
decl_stmt|;
comment|///< # of SDep::Data sucss.
name|unsigned
name|NumPredsLeft
init|=
literal|0
decl_stmt|;
comment|///< # of preds not scheduled.
name|unsigned
name|NumSuccsLeft
init|=
literal|0
decl_stmt|;
comment|///< # of succs not scheduled.
name|unsigned
name|WeakPredsLeft
init|=
literal|0
decl_stmt|;
comment|///< # of weak preds not scheduled.
name|unsigned
name|WeakSuccsLeft
init|=
literal|0
decl_stmt|;
comment|///< # of weak succs not scheduled.
name|unsigned
name|short
name|NumRegDefsLeft
init|=
literal|0
decl_stmt|;
comment|///< # of reg defs with no scheduled use.
name|unsigned
name|short
name|Latency
init|=
literal|0
decl_stmt|;
comment|///< Node latency.
name|bool
name|isVRegCycle
range|:
literal|1
decl_stmt|;
comment|///< May use and def the same vreg.
name|bool
name|isCall
range|:
literal|1
decl_stmt|;
comment|///< Is a function call.
name|bool
name|isCallOp
range|:
literal|1
decl_stmt|;
comment|///< Is a function call operand.
name|bool
name|isTwoAddress
range|:
literal|1
decl_stmt|;
comment|///< Is a two-address instruction.
name|bool
name|isCommutable
range|:
literal|1
decl_stmt|;
comment|///< Is a commutable instruction.
name|bool
name|hasPhysRegUses
range|:
literal|1
decl_stmt|;
comment|///< Has physreg uses.
name|bool
name|hasPhysRegDefs
range|:
literal|1
decl_stmt|;
comment|///< Has physreg defs that are being used.
name|bool
name|hasPhysRegClobbers
range|:
literal|1
decl_stmt|;
comment|///< Has any physreg defs, used or not.
name|bool
name|isPending
range|:
literal|1
decl_stmt|;
comment|///< True once pending.
name|bool
name|isAvailable
range|:
literal|1
decl_stmt|;
comment|///< True once available.
name|bool
name|isScheduled
range|:
literal|1
decl_stmt|;
comment|///< True once scheduled.
name|bool
name|isScheduleHigh
range|:
literal|1
decl_stmt|;
comment|///< True if preferable to schedule high.
name|bool
name|isScheduleLow
range|:
literal|1
decl_stmt|;
comment|///< True if preferable to schedule low.
name|bool
name|isCloned
range|:
literal|1
decl_stmt|;
comment|///< True if this node has been cloned.
name|bool
name|isUnbuffered
range|:
literal|1
decl_stmt|;
comment|///< Uses an unbuffered resource.
name|bool
name|hasReservedResource
range|:
literal|1
decl_stmt|;
comment|///< Uses a reserved resource.
name|Sched
operator|::
name|Preference
name|SchedulingPref
operator|=
name|Sched
operator|::
name|None
expr_stmt|;
comment|///< Scheduling preference.
name|private
label|:
name|bool
name|isDepthCurrent
range|:
literal|1
decl_stmt|;
comment|///< True if Depth is current.
name|bool
name|isHeightCurrent
range|:
literal|1
decl_stmt|;
comment|///< True if Height is current.
name|unsigned
name|Depth
init|=
literal|0
decl_stmt|;
comment|///< Node depth.
name|unsigned
name|Height
init|=
literal|0
decl_stmt|;
comment|///< Node height.
name|public
label|:
name|unsigned
name|TopReadyCycle
init|=
literal|0
decl_stmt|;
comment|///< Cycle relative to start when node is ready.
name|unsigned
name|BotReadyCycle
init|=
literal|0
decl_stmt|;
comment|///< Cycle relative to end when node is ready.
specifier|const
name|TargetRegisterClass
modifier|*
name|CopyDstRC
init|=
name|nullptr
decl_stmt|;
comment|///< Is a special copy node if != nullptr.
specifier|const
name|TargetRegisterClass
modifier|*
name|CopySrcRC
init|=
name|nullptr
decl_stmt|;
comment|/// \brief Constructs an SUnit for pre-regalloc scheduling to represent an
comment|/// SDNode and any nodes flagged to it.
name|SUnit
argument_list|(
argument|SDNode *node
argument_list|,
argument|unsigned nodenum
argument_list|)
block|:
name|Node
argument_list|(
name|node
argument_list|)
operator|,
name|NodeNum
argument_list|(
name|nodenum
argument_list|)
operator|,
name|isVRegCycle
argument_list|(
name|false
argument_list|)
operator|,
name|isCall
argument_list|(
name|false
argument_list|)
operator|,
name|isCallOp
argument_list|(
name|false
argument_list|)
operator|,
name|isTwoAddress
argument_list|(
name|false
argument_list|)
operator|,
name|isCommutable
argument_list|(
name|false
argument_list|)
operator|,
name|hasPhysRegUses
argument_list|(
name|false
argument_list|)
operator|,
name|hasPhysRegDefs
argument_list|(
name|false
argument_list|)
operator|,
name|hasPhysRegClobbers
argument_list|(
name|false
argument_list|)
operator|,
name|isPending
argument_list|(
name|false
argument_list|)
operator|,
name|isAvailable
argument_list|(
name|false
argument_list|)
operator|,
name|isScheduled
argument_list|(
name|false
argument_list|)
operator|,
name|isScheduleHigh
argument_list|(
name|false
argument_list|)
operator|,
name|isScheduleLow
argument_list|(
name|false
argument_list|)
operator|,
name|isCloned
argument_list|(
name|false
argument_list|)
operator|,
name|isUnbuffered
argument_list|(
name|false
argument_list|)
operator|,
name|hasReservedResource
argument_list|(
name|false
argument_list|)
operator|,
name|isDepthCurrent
argument_list|(
name|false
argument_list|)
operator|,
name|isHeightCurrent
argument_list|(
argument|false
argument_list|)
block|{}
comment|/// \brief Constructs an SUnit for post-regalloc scheduling to represent a
comment|/// MachineInstr.
name|SUnit
argument_list|(
argument|MachineInstr *instr
argument_list|,
argument|unsigned nodenum
argument_list|)
operator|:
name|Instr
argument_list|(
name|instr
argument_list|)
operator|,
name|NodeNum
argument_list|(
name|nodenum
argument_list|)
operator|,
name|isVRegCycle
argument_list|(
name|false
argument_list|)
operator|,
name|isCall
argument_list|(
name|false
argument_list|)
operator|,
name|isCallOp
argument_list|(
name|false
argument_list|)
operator|,
name|isTwoAddress
argument_list|(
name|false
argument_list|)
operator|,
name|isCommutable
argument_list|(
name|false
argument_list|)
operator|,
name|hasPhysRegUses
argument_list|(
name|false
argument_list|)
operator|,
name|hasPhysRegDefs
argument_list|(
name|false
argument_list|)
operator|,
name|hasPhysRegClobbers
argument_list|(
name|false
argument_list|)
operator|,
name|isPending
argument_list|(
name|false
argument_list|)
operator|,
name|isAvailable
argument_list|(
name|false
argument_list|)
operator|,
name|isScheduled
argument_list|(
name|false
argument_list|)
operator|,
name|isScheduleHigh
argument_list|(
name|false
argument_list|)
operator|,
name|isScheduleLow
argument_list|(
name|false
argument_list|)
operator|,
name|isCloned
argument_list|(
name|false
argument_list|)
operator|,
name|isUnbuffered
argument_list|(
name|false
argument_list|)
operator|,
name|hasReservedResource
argument_list|(
name|false
argument_list|)
operator|,
name|isDepthCurrent
argument_list|(
name|false
argument_list|)
operator|,
name|isHeightCurrent
argument_list|(
argument|false
argument_list|)
block|{}
comment|/// \brief Constructs a placeholder SUnit.
name|SUnit
argument_list|()
operator|:
name|isVRegCycle
argument_list|(
name|false
argument_list|)
operator|,
name|isCall
argument_list|(
name|false
argument_list|)
operator|,
name|isCallOp
argument_list|(
name|false
argument_list|)
operator|,
name|isTwoAddress
argument_list|(
name|false
argument_list|)
operator|,
name|isCommutable
argument_list|(
name|false
argument_list|)
operator|,
name|hasPhysRegUses
argument_list|(
name|false
argument_list|)
operator|,
name|hasPhysRegDefs
argument_list|(
name|false
argument_list|)
operator|,
name|hasPhysRegClobbers
argument_list|(
name|false
argument_list|)
operator|,
name|isPending
argument_list|(
name|false
argument_list|)
operator|,
name|isAvailable
argument_list|(
name|false
argument_list|)
operator|,
name|isScheduled
argument_list|(
name|false
argument_list|)
operator|,
name|isScheduleHigh
argument_list|(
name|false
argument_list|)
operator|,
name|isScheduleLow
argument_list|(
name|false
argument_list|)
operator|,
name|isCloned
argument_list|(
name|false
argument_list|)
operator|,
name|isUnbuffered
argument_list|(
name|false
argument_list|)
operator|,
name|hasReservedResource
argument_list|(
name|false
argument_list|)
operator|,
name|isDepthCurrent
argument_list|(
name|false
argument_list|)
operator|,
name|isHeightCurrent
argument_list|(
argument|false
argument_list|)
block|{}
comment|/// \brief Boundary nodes are placeholders for the boundary of the
comment|/// scheduling region.
comment|///
comment|/// BoundaryNodes can have DAG edges, including Data edges, but they do not
comment|/// correspond to schedulable entities (e.g. instructions) and do not have a
comment|/// valid ID. Consequently, always check for boundary nodes before accessing
comment|/// an associative data structure keyed on node ID.
name|bool
name|isBoundaryNode
argument_list|()
specifier|const
block|{
return|return
name|NodeNum
operator|==
name|BoundaryID
return|;
block|}
comment|/// Assigns the representative SDNode for this SUnit. This may be used
comment|/// during pre-regalloc scheduling.
name|void
name|setNode
parameter_list|(
name|SDNode
modifier|*
name|N
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|Instr
operator|&&
literal|"Setting SDNode of SUnit with MachineInstr!"
argument_list|)
expr_stmt|;
name|Node
operator|=
name|N
expr_stmt|;
block|}
comment|/// Returns the representative SDNode for this SUnit. This may be used
comment|/// during pre-regalloc scheduling.
name|SDNode
operator|*
name|getNode
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|Instr
operator|&&
literal|"Reading SDNode of SUnit with MachineInstr!"
argument_list|)
block|;
return|return
name|Node
return|;
block|}
comment|/// \brief Returns true if this SUnit refers to a machine instruction as
comment|/// opposed to an SDNode.
name|bool
name|isInstr
argument_list|()
specifier|const
block|{
return|return
name|Instr
return|;
block|}
comment|/// Assigns the instruction for the SUnit. This may be used during
comment|/// post-regalloc scheduling.
name|void
name|setInstr
parameter_list|(
name|MachineInstr
modifier|*
name|MI
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|Node
operator|&&
literal|"Setting MachineInstr of SUnit with SDNode!"
argument_list|)
expr_stmt|;
name|Instr
operator|=
name|MI
expr_stmt|;
block|}
comment|/// Returns the representative MachineInstr for this SUnit. This may be used
comment|/// during post-regalloc scheduling.
name|MachineInstr
operator|*
name|getInstr
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|Node
operator|&&
literal|"Reading MachineInstr of SUnit with SDNode!"
argument_list|)
block|;
return|return
name|Instr
return|;
block|}
comment|/// Adds the specified edge as a pred of the current node if not already.
comment|/// It also adds the current node as a successor of the specified node.
name|bool
name|addPred
parameter_list|(
specifier|const
name|SDep
modifier|&
name|D
parameter_list|,
name|bool
name|Required
init|=
name|true
parameter_list|)
function_decl|;
comment|/// \brief Adds a barrier edge to SU by calling addPred(), with latency 0
comment|/// generally or latency 1 for a store followed by a load.
name|bool
name|addPredBarrier
parameter_list|(
name|SUnit
modifier|*
name|SU
parameter_list|)
block|{
name|SDep
name|Dep
argument_list|(
name|SU
argument_list|,
name|SDep
operator|::
name|Barrier
argument_list|)
decl_stmt|;
name|unsigned
name|TrueMemOrderLatency
init|=
operator|(
operator|(
name|SU
operator|->
name|getInstr
argument_list|()
operator|->
name|mayStore
argument_list|()
operator|&&
name|this
operator|->
name|getInstr
argument_list|()
operator|->
name|mayLoad
argument_list|()
operator|)
condition|?
literal|1
else|:
literal|0
operator|)
decl_stmt|;
name|Dep
operator|.
name|setLatency
argument_list|(
name|TrueMemOrderLatency
argument_list|)
expr_stmt|;
return|return
name|addPred
argument_list|(
name|Dep
argument_list|)
return|;
block|}
comment|/// Removes the specified edge as a pred of the current node if it exists.
comment|/// It also removes the current node as a successor of the specified node.
name|void
name|removePred
parameter_list|(
specifier|const
name|SDep
modifier|&
name|D
parameter_list|)
function_decl|;
comment|/// Returns the depth of this node, which is the length of the maximum path
comment|/// up to any node which has no predecessors.
name|unsigned
name|getDepth
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|isDepthCurrent
condition|)
name|const_cast
operator|<
name|SUnit
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|ComputeDepth
argument_list|()
expr_stmt|;
return|return
name|Depth
return|;
block|}
comment|/// \brief Returns the height of this node, which is the length of the
comment|/// maximum path down to any node which has no successors.
name|unsigned
name|getHeight
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|isHeightCurrent
condition|)
name|const_cast
operator|<
name|SUnit
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|ComputeHeight
argument_list|()
expr_stmt|;
return|return
name|Height
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief If NewDepth is greater than this node's depth value, sets it to
end_comment

begin_comment
comment|/// be the new depth value. This also recursively marks successor nodes
end_comment

begin_comment
comment|/// dirty.
end_comment

begin_function_decl
name|void
name|setDepthToAtLeast
parameter_list|(
name|unsigned
name|NewDepth
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief If NewDepth is greater than this node's depth value, set it to be
end_comment

begin_comment
comment|/// the new height value. This also recursively marks predecessor nodes
end_comment

begin_comment
comment|/// dirty.
end_comment

begin_function_decl
name|void
name|setHeightToAtLeast
parameter_list|(
name|unsigned
name|NewHeight
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Sets a flag in this node to indicate that its stored Depth value
end_comment

begin_comment
comment|/// will require recomputation the next time getDepth() is called.
end_comment

begin_function_decl
name|void
name|setDepthDirty
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Sets a flag in this node to indicate that its stored Height value
end_comment

begin_comment
comment|/// will require recomputation the next time getHeight() is called.
end_comment

begin_function_decl
name|void
name|setHeightDirty
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Tests if node N is a predecessor of this node.
end_comment

begin_decl_stmt
name|bool
name|isPred
argument_list|(
specifier|const
name|SUnit
operator|*
name|N
argument_list|)
decl|const
block|{
for|for
control|(
specifier|const
name|SDep
modifier|&
name|Pred
range|:
name|Preds
control|)
if|if
condition|(
name|Pred
operator|.
name|getSUnit
argument_list|()
operator|==
name|N
condition|)
return|return
name|true
return|;
return|return
name|false
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Tests if node N is a successor of this node.
end_comment

begin_decl_stmt
name|bool
name|isSucc
argument_list|(
specifier|const
name|SUnit
operator|*
name|N
argument_list|)
decl|const
block|{
for|for
control|(
specifier|const
name|SDep
modifier|&
name|Succ
range|:
name|Succs
control|)
if|if
condition|(
name|Succ
operator|.
name|getSUnit
argument_list|()
operator|==
name|N
condition|)
return|return
name|true
return|;
return|return
name|false
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|bool
name|isTopReady
argument_list|()
specifier|const
block|{
return|return
name|NumPredsLeft
operator|==
literal|0
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|isBottomReady
argument_list|()
specifier|const
block|{
return|return
name|NumSuccsLeft
operator|==
literal|0
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Orders this node's predecessor edges such that the critical path
end_comment

begin_comment
comment|/// edge occurs first.
end_comment

begin_function_decl
name|void
name|biasCriticalPath
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|dump
argument_list|(
specifier|const
name|ScheduleDAG
operator|*
name|G
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|dumpAll
argument_list|(
specifier|const
name|ScheduleDAG
operator|*
name|G
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|O
argument_list|,
specifier|const
name|ScheduleDAG
operator|*
name|G
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_function_decl
name|void
name|ComputeDepth
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ComputeHeight
parameter_list|()
function_decl|;
end_function_decl

begin_comment
unit|};
comment|/// Returns true if the specified SDep is equivalent except for latency.
end_comment

begin_expr_stmt
specifier|inline
name|bool
name|SDep
operator|::
name|overlaps
argument_list|(
argument|const SDep&Other
argument_list|)
specifier|const
block|{
if|if
condition|(
name|Dep
operator|!=
name|Other
operator|.
name|Dep
condition|)
return|return
name|false
return|;
end_expr_stmt

begin_switch
switch|switch
condition|(
name|Dep
operator|.
name|getInt
argument_list|()
condition|)
block|{
case|case
name|Data
case|:
case|case
name|Anti
case|:
case|case
name|Output
case|:
return|return
name|Contents
operator|.
name|Reg
operator|==
name|Other
operator|.
name|Contents
operator|.
name|Reg
return|;
case|case
name|Order
case|:
return|return
name|Contents
operator|.
name|OrdKind
operator|==
name|Other
operator|.
name|Contents
operator|.
name|OrdKind
return|;
block|}
end_switch

begin_expr_stmt
name|llvm_unreachable
argument_list|(
literal|"Invalid dependency kind!"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|//// Returns the SUnit to which this edge points.
end_comment

begin_expr_stmt
unit|inline
name|SUnit
operator|*
name|SDep
operator|::
name|getSUnit
argument_list|()
specifier|const
block|{
return|return
name|Dep
operator|.
name|getPointer
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|//// Assigns the SUnit to which this edge points.
end_comment

begin_expr_stmt
specifier|inline
name|void
name|SDep
operator|::
name|setSUnit
argument_list|(
argument|SUnit *SU
argument_list|)
block|{
name|Dep
operator|.
name|setPointer
argument_list|(
name|SU
argument_list|)
block|; }
comment|/// Returns an enum value representing the kind of the dependence.
specifier|inline
name|SDep
operator|::
name|Kind
name|SDep
operator|::
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|Dep
operator|.
name|getInt
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// \brief This interface is used to plug different priorities computation
end_comment

begin_comment
comment|/// algorithms into the list scheduler. It implements the interface of a
end_comment

begin_comment
comment|/// standard priority queue, where nodes are inserted in arbitrary order and
end_comment

begin_comment
comment|/// returned in priority order.  The computation of the priority and the
end_comment

begin_comment
comment|/// representation of the queue are totally up to the implementation to
end_comment

begin_comment
comment|/// decide.
end_comment

begin_decl_stmt
name|class
name|SchedulingPriorityQueue
block|{
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
name|unsigned
name|CurCycle
init|=
literal|0
decl_stmt|;
name|bool
name|HasReadyFilter
decl_stmt|;
name|public
label|:
name|SchedulingPriorityQueue
argument_list|(
argument|bool rf = false
argument_list|)
block|:
name|HasReadyFilter
argument_list|(
argument|rf
argument_list|)
block|{}
name|virtual
operator|~
name|SchedulingPriorityQueue
argument_list|()
operator|=
expr|default
expr_stmt|;
name|virtual
name|bool
name|isBottomUp
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|initNodes
argument_list|(
name|std
operator|::
name|vector
operator|<
name|SUnit
operator|>
operator|&
name|SUnits
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|addNode
parameter_list|(
specifier|const
name|SUnit
modifier|*
name|SU
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|updateNode
parameter_list|(
specifier|const
name|SUnit
modifier|*
name|SU
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|releaseState
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|empty
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|bool
name|hasReadyFilter
argument_list|()
specifier|const
block|{
return|return
name|HasReadyFilter
return|;
block|}
name|virtual
name|bool
name|tracksRegPressure
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|isReady
argument_list|(
name|SUnit
operator|*
argument_list|)
decl|const
block|{
name|assert
argument_list|(
operator|!
name|HasReadyFilter
operator|&&
literal|"The ready filter must override isReady()"
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
name|virtual
name|void
name|push
parameter_list|(
name|SUnit
modifier|*
name|U
parameter_list|)
init|=
literal|0
function_decl|;
name|void
name|push_all
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|SUnit
operator|*
operator|>
operator|&
name|Nodes
argument_list|)
block|{
for|for
control|(
name|std
operator|::
name|vector
operator|<
name|SUnit
operator|*
operator|>
operator|::
name|const_iterator
name|I
operator|=
name|Nodes
operator|.
name|begin
argument_list|()
operator|,
name|E
operator|=
name|Nodes
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
name|push
argument_list|(
operator|*
name|I
argument_list|)
expr_stmt|;
block|}
name|virtual
name|SUnit
modifier|*
name|pop
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|void
name|remove
parameter_list|(
name|SUnit
modifier|*
name|SU
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|dump
argument_list|(
name|ScheduleDAG
operator|*
argument_list|)
decl|const
block|{}
comment|/// As each node is scheduled, this method is invoked.  This allows the
comment|/// priority function to adjust the priority of related unscheduled nodes,
comment|/// for example.
name|virtual
name|void
name|scheduledNode
parameter_list|(
name|SUnit
modifier|*
parameter_list|)
block|{}
name|virtual
name|void
name|unscheduledNode
parameter_list|(
name|SUnit
modifier|*
parameter_list|)
block|{}
name|void
name|setCurCycle
parameter_list|(
name|unsigned
name|Cycle
parameter_list|)
block|{
name|CurCycle
operator|=
name|Cycle
expr_stmt|;
block|}
name|unsigned
name|getCurCycle
argument_list|()
specifier|const
block|{
return|return
name|CurCycle
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|ScheduleDAG
block|{
name|public
label|:
specifier|const
name|TargetMachine
modifier|&
name|TM
decl_stmt|;
comment|///< Target processor
specifier|const
name|TargetInstrInfo
modifier|*
name|TII
decl_stmt|;
comment|///< Target instruction information
specifier|const
name|TargetRegisterInfo
modifier|*
name|TRI
decl_stmt|;
comment|///< Target processor register info
name|MachineFunction
modifier|&
name|MF
decl_stmt|;
comment|///< Machine function
name|MachineRegisterInfo
modifier|&
name|MRI
decl_stmt|;
comment|///< Virtual/real register map
name|std
operator|::
name|vector
operator|<
name|SUnit
operator|>
name|SUnits
expr_stmt|;
comment|///< The scheduling units.
name|SUnit
name|EntrySU
decl_stmt|;
comment|///< Special node for the region entry.
name|SUnit
name|ExitSU
decl_stmt|;
comment|///< Special node for the region exit.
ifdef|#
directive|ifdef
name|NDEBUG
specifier|static
specifier|const
name|bool
name|StressSched
init|=
name|false
decl_stmt|;
else|#
directive|else
name|bool
name|StressSched
decl_stmt|;
endif|#
directive|endif
name|explicit
name|ScheduleDAG
parameter_list|(
name|MachineFunction
modifier|&
name|mf
parameter_list|)
function_decl|;
name|virtual
operator|~
name|ScheduleDAG
argument_list|()
expr_stmt|;
comment|/// Clears the DAG state (between regions).
name|void
name|clearDAG
parameter_list|()
function_decl|;
comment|/// Returns the MCInstrDesc of this SUnit.
comment|/// Returns NULL for SDNodes without a machine opcode.
specifier|const
name|MCInstrDesc
modifier|*
name|getInstrDesc
argument_list|(
specifier|const
name|SUnit
operator|*
name|SU
argument_list|)
decl|const
block|{
if|if
condition|(
name|SU
operator|->
name|isInstr
argument_list|()
condition|)
return|return
operator|&
name|SU
operator|->
name|getInstr
argument_list|()
operator|->
name|getDesc
argument_list|()
return|;
return|return
name|getNodeDesc
argument_list|(
name|SU
operator|->
name|getNode
argument_list|()
argument_list|)
return|;
block|}
comment|/// Pops up a GraphViz/gv window with the ScheduleDAG rendered using 'dot'.
name|virtual
name|void
name|viewGraph
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Name
parameter_list|,
specifier|const
name|Twine
modifier|&
name|Title
parameter_list|)
function_decl|;
name|virtual
name|void
name|viewGraph
parameter_list|()
function_decl|;
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
init|=
literal|0
decl_stmt|;
comment|/// Returns a label for an SUnit node in a visualization of the ScheduleDAG.
name|virtual
name|std
operator|::
name|string
name|getGraphNodeLabel
argument_list|(
argument|const SUnit *SU
argument_list|)
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// Returns a label for the region of code covered by the DAG.
name|virtual
name|std
operator|::
name|string
name|getDAGName
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// Adds custom features for a visualization of the ScheduleDAG.
name|virtual
name|void
name|addCustomGraphFeatures
argument_list|(
name|GraphWriter
operator|<
name|ScheduleDAG
operator|*
operator|>
operator|&
argument_list|)
decl|const
block|{}
ifndef|#
directive|ifndef
name|NDEBUG
comment|/// \brief Verifies that all SUnits were scheduled and that their state is
comment|/// consistent. Returns the number of scheduled SUnits.
name|unsigned
name|VerifyScheduledDAG
parameter_list|(
name|bool
name|isBottomUp
parameter_list|)
function_decl|;
endif|#
directive|endif
name|private
label|:
comment|/// Returns the MCInstrDesc of this SDNode or NULL.
specifier|const
name|MCInstrDesc
modifier|*
name|getNodeDesc
argument_list|(
specifier|const
name|SDNode
operator|*
name|Node
argument_list|)
decl|const
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|SUnitIterator
range|:
name|public
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|forward_iterator_tag
decl_stmt|,
name|SUnit
decl_stmt|,
name|ptrdiff_t
decl|>
block|{
name|SUnit
modifier|*
name|Node
decl_stmt|;
name|unsigned
name|Operand
decl_stmt|;
name|SUnitIterator
argument_list|(
argument|SUnit *N
argument_list|,
argument|unsigned Op
argument_list|)
block|:
name|Node
argument_list|(
name|N
argument_list|)
operator|,
name|Operand
argument_list|(
argument|Op
argument_list|)
block|{}
name|public
operator|:
name|bool
name|operator
operator|==
operator|(
specifier|const
name|SUnitIterator
operator|&
name|x
operator|)
specifier|const
block|{
return|return
name|Operand
operator|==
name|x
operator|.
name|Operand
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|SUnitIterator
operator|&
name|x
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|x
operator|)
return|;
block|}
name|pointer
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|Node
operator|->
name|Preds
index|[
name|Operand
index|]
operator|.
name|getSUnit
argument_list|()
return|;
block|}
name|pointer
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
name|operator
operator|*
operator|(
operator|)
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|SUnitIterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
comment|// Preincrement
operator|++
name|Operand
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|SUnitIterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
comment|// Postincrement
name|SUnitIterator
name|tmp
operator|=
operator|*
name|this
block|;
operator|++
operator|*
name|this
block|;
return|return
name|tmp
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|SUnitIterator
name|begin
parameter_list|(
name|SUnit
modifier|*
name|N
parameter_list|)
block|{
return|return
name|SUnitIterator
argument_list|(
name|N
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|SUnitIterator
name|end
parameter_list|(
name|SUnit
modifier|*
name|N
parameter_list|)
block|{
return|return
name|SUnitIterator
argument_list|(
name|N
argument_list|,
operator|(
name|unsigned
operator|)
name|N
operator|->
name|Preds
operator|.
name|size
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|unsigned
name|getOperand
argument_list|()
specifier|const
block|{
return|return
name|Operand
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|SUnit
operator|*
name|getNode
argument_list|()
specifier|const
block|{
return|return
name|Node
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Tests if this is not an SDep::Data dependence.
end_comment

begin_expr_stmt
name|bool
name|isCtrlDep
argument_list|()
specifier|const
block|{
return|return
name|getSDep
argument_list|()
operator|.
name|isCtrl
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|isArtificialDep
argument_list|()
specifier|const
block|{
return|return
name|getSDep
argument_list|()
operator|.
name|isArtificial
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|SDep
operator|&
name|getSDep
argument_list|()
specifier|const
block|{
return|return
name|Node
operator|->
name|Preds
index|[
name|Operand
index|]
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|GraphTraits
operator|<
name|SUnit
operator|*
operator|>
block|{
typedef|typedef
name|SUnit
modifier|*
name|NodeRef
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|SUnitIterator
name|ChildIteratorType
typedef|;
end_typedef

begin_function
specifier|static
name|NodeRef
name|getEntryNode
parameter_list|(
name|SUnit
modifier|*
name|N
parameter_list|)
block|{
return|return
name|N
return|;
block|}
end_function

begin_function
specifier|static
name|ChildIteratorType
name|child_begin
parameter_list|(
name|NodeRef
name|N
parameter_list|)
block|{
return|return
name|SUnitIterator
operator|::
name|begin
argument_list|(
name|N
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|ChildIteratorType
name|child_end
parameter_list|(
name|NodeRef
name|N
parameter_list|)
block|{
return|return
name|SUnitIterator
operator|::
name|end
argument_list|(
name|N
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|GraphTraits
operator|<
name|ScheduleDAG
operator|*
operator|>
operator|:
name|public
name|GraphTraits
operator|<
name|SUnit
operator|*
operator|>
block|{
typedef|typedef
name|pointer_iterator
operator|<
name|std
operator|::
name|vector
operator|<
name|SUnit
operator|>
operator|::
name|iterator
operator|>
name|nodes_iterator
expr_stmt|;
specifier|static
name|nodes_iterator
name|nodes_begin
argument_list|(
argument|ScheduleDAG *G
argument_list|)
block|{
return|return
name|nodes_iterator
argument_list|(
name|G
operator|->
name|SUnits
operator|.
name|begin
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|nodes_iterator
name|nodes_end
argument_list|(
argument|ScheduleDAG *G
argument_list|)
block|{
return|return
name|nodes_iterator
argument_list|(
name|G
operator|->
name|SUnits
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// This class can compute a topological ordering for SUnits and provides
end_comment

begin_comment
comment|/// methods for dynamically updating the ordering as new edges are added.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This allows a very fast implementation of IsReachable, for example.
end_comment

begin_decl_stmt
name|class
name|ScheduleDAGTopologicalSort
block|{
comment|/// A reference to the ScheduleDAG's SUnits.
name|std
operator|::
name|vector
operator|<
name|SUnit
operator|>
operator|&
name|SUnits
expr_stmt|;
name|SUnit
modifier|*
name|ExitSU
decl_stmt|;
comment|/// Maps topological index to the node number.
name|std
operator|::
name|vector
operator|<
name|int
operator|>
name|Index2Node
expr_stmt|;
comment|/// Maps the node number to its topological index.
name|std
operator|::
name|vector
operator|<
name|int
operator|>
name|Node2Index
expr_stmt|;
comment|/// a set of nodes visited during a DFS traversal.
name|BitVector
name|Visited
decl_stmt|;
comment|/// Makes a DFS traversal and mark all nodes affected by the edge insertion.
comment|/// These nodes will later get new topological indexes by means of the Shift
comment|/// method.
name|void
name|DFS
parameter_list|(
specifier|const
name|SUnit
modifier|*
name|SU
parameter_list|,
name|int
name|UpperBound
parameter_list|,
name|bool
modifier|&
name|HasLoop
parameter_list|)
function_decl|;
comment|/// \brief Reassigns topological indexes for the nodes in the DAG to
comment|/// preserve the topological ordering.
name|void
name|Shift
parameter_list|(
name|BitVector
modifier|&
name|Visited
parameter_list|,
name|int
name|LowerBound
parameter_list|,
name|int
name|UpperBound
parameter_list|)
function_decl|;
comment|/// Assigns the topological index to the node n.
name|void
name|Allocate
parameter_list|(
name|int
name|n
parameter_list|,
name|int
name|index
parameter_list|)
function_decl|;
name|public
label|:
name|ScheduleDAGTopologicalSort
argument_list|(
name|std
operator|::
name|vector
operator|<
name|SUnit
operator|>
operator|&
name|SUnits
argument_list|,
name|SUnit
operator|*
name|ExitSU
argument_list|)
expr_stmt|;
comment|/// Creates the initial topological ordering from the DAG to be scheduled.
name|void
name|InitDAGTopologicalSorting
parameter_list|()
function_decl|;
comment|/// Returns an array of SUs that are both in the successor
comment|/// subtree of StartSU and in the predecessor subtree of TargetSU.
comment|/// StartSU and TargetSU are not in the array.
comment|/// Success is false if TargetSU is not in the successor subtree of
comment|/// StartSU, else it is true.
name|std
operator|::
name|vector
operator|<
name|int
operator|>
name|GetSubGraph
argument_list|(
specifier|const
name|SUnit
operator|&
name|StartSU
argument_list|,
specifier|const
name|SUnit
operator|&
name|TargetSU
argument_list|,
name|bool
operator|&
name|Success
argument_list|)
expr_stmt|;
comment|/// Checks if \p SU is reachable from \p TargetSU.
name|bool
name|IsReachable
parameter_list|(
specifier|const
name|SUnit
modifier|*
name|SU
parameter_list|,
specifier|const
name|SUnit
modifier|*
name|TargetSU
parameter_list|)
function_decl|;
comment|/// Returns true if addPred(TargetSU, SU) creates a cycle.
name|bool
name|WillCreateCycle
parameter_list|(
name|SUnit
modifier|*
name|TargetSU
parameter_list|,
name|SUnit
modifier|*
name|SU
parameter_list|)
function_decl|;
comment|/// \brief Updates the topological ordering to accommodate an edge to be
comment|/// added from SUnit \p X to SUnit \p Y.
name|void
name|AddPred
parameter_list|(
name|SUnit
modifier|*
name|Y
parameter_list|,
name|SUnit
modifier|*
name|X
parameter_list|)
function_decl|;
comment|/// \brief Updates the topological ordering to accommodate an an edge to be
comment|/// removed from the specified node \p N from the predecessors of the
comment|/// current node \p M.
name|void
name|RemovePred
parameter_list|(
name|SUnit
modifier|*
name|M
parameter_list|,
name|SUnit
modifier|*
name|N
parameter_list|)
function_decl|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|int
operator|>
operator|::
name|iterator
name|iterator
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|int
operator|>
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|Index2Node
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|Index2Node
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
name|Index2Node
operator|.
name|end
argument_list|()
return|;
block|}
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|Index2Node
operator|.
name|end
argument_list|()
return|;
block|}
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|int
operator|>
operator|::
name|reverse_iterator
name|reverse_iterator
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|int
operator|>
operator|::
name|const_reverse_iterator
name|const_reverse_iterator
expr_stmt|;
name|reverse_iterator
name|rbegin
parameter_list|()
block|{
return|return
name|Index2Node
operator|.
name|rbegin
argument_list|()
return|;
block|}
name|const_reverse_iterator
name|rbegin
argument_list|()
specifier|const
block|{
return|return
name|Index2Node
operator|.
name|rbegin
argument_list|()
return|;
block|}
name|reverse_iterator
name|rend
parameter_list|()
block|{
return|return
name|Index2Node
operator|.
name|rend
argument_list|()
return|;
block|}
name|const_reverse_iterator
name|rend
argument_list|()
specifier|const
block|{
return|return
name|Index2Node
operator|.
name|rend
argument_list|()
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CODEGEN_SCHEDULEDAG_H
end_comment

end_unit

