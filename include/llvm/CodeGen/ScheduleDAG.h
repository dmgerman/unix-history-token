begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===------- llvm/CodeGen/ScheduleDAG.h - Common Base Class------*- C++ -*-===//
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
comment|// This file implements the ScheduleDAG class, which is used as the common
end_comment

begin_comment
comment|// base class for instruction schedulers.
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
file|"llvm/CodeGen/MachineBasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

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
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PointerIntPair.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AliasAnalysis
decl_stmt|;
name|class
name|SUnit
decl_stmt|;
name|class
name|MachineConstantPool
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MachineModuleInfo
decl_stmt|;
name|class
name|MachineRegisterInfo
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|TargetRegisterInfo
decl_stmt|;
name|class
name|ScheduleDAG
decl_stmt|;
name|class
name|SDNode
decl_stmt|;
name|class
name|TargetInstrInfo
decl_stmt|;
name|class
name|TargetInstrDesc
decl_stmt|;
name|class
name|TargetLowering
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
name|class
name|TargetRegisterClass
decl_stmt|;
name|template
operator|<
name|class
name|Graph
operator|>
name|class
name|GraphWriter
expr_stmt|;
comment|/// SDep - Scheduling dependency. This represents one direction of an
comment|/// edge in the scheduling DAG.
name|class
name|SDep
block|{
name|public
label|:
comment|/// Kind - These are the different kinds of scheduling dependencies.
enum|enum
name|Kind
block|{
name|Data
block|,
comment|///< Regular data dependence (aka true-dependence).
name|Anti
block|,
comment|///< A register anti-dependedence (aka WAR).
name|Output
block|,
comment|///< A register output-dependence (aka WAW).
name|Order
comment|///< Any other ordering dependency.
block|}
enum|;
name|private
label|:
comment|/// Dep - A pointer to the depending/depended-on SUnit, and an enum
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
comment|/// Contents - A union discriminated by the dependence kind.
union|union
block|{
comment|/// Reg - For Data, Anti, and Output dependencies, the associated
comment|/// register. For Data dependencies that don't currently have a register
comment|/// assigned, this is set to zero.
name|unsigned
name|Reg
decl_stmt|;
comment|/// Order - Additional information about Order dependencies.
struct|struct
block|{
comment|/// isNormalMemory - True if both sides of the dependence
comment|/// access memory in non-volatile and fully modeled ways.
name|bool
name|isNormalMemory
range|:
literal|1
decl_stmt|;
comment|/// isMustAlias - True if both sides of the dependence are known to
comment|/// access the same memory.
name|bool
name|isMustAlias
range|:
literal|1
decl_stmt|;
comment|/// isArtificial - True if this is an artificial dependency, meaning
comment|/// it is not necessary for program correctness, and may be safely
comment|/// deleted if necessary.
name|bool
name|isArtificial
range|:
literal|1
decl_stmt|;
block|}
name|Order
struct|;
block|}
name|Contents
union|;
comment|/// Latency - The time associated with this edge. Often this is just
comment|/// the value of the Latency field of the predecessor, however advanced
comment|/// models may provide additional information about specific edges.
name|unsigned
name|Latency
decl_stmt|;
name|public
label|:
comment|/// SDep - Construct a null SDep. This is only for use by container
comment|/// classes which require default constructors. SUnits may not
comment|/// have null SDep edges.
name|SDep
argument_list|()
operator|:
name|Dep
argument_list|(
literal|0
argument_list|,
argument|Data
argument_list|)
block|{}
comment|/// SDep - Construct an SDep with the specified values.
name|SDep
argument_list|(
argument|SUnit *S
argument_list|,
argument|Kind kind
argument_list|,
argument|unsigned latency =
literal|1
argument_list|,
argument|unsigned Reg =
literal|0
argument_list|,
argument|bool isNormalMemory = false
argument_list|,
argument|bool isMustAlias = false
argument_list|,
argument|bool isArtificial = false
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
operator|,
name|Latency
argument_list|(
argument|latency
argument_list|)
block|{
switch|switch
condition|(
name|kind
condition|)
block|{
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
comment|// fall through
case|case
name|Data
case|:
name|assert
argument_list|(
operator|!
name|isMustAlias
operator|&&
literal|"isMustAlias only applies with SDep::Order!"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|!
name|isArtificial
operator|&&
literal|"isArtificial only applies with SDep::Order!"
argument_list|)
expr_stmt|;
name|Contents
operator|.
name|Reg
operator|=
name|Reg
expr_stmt|;
break|break;
case|case
name|Order
case|:
name|assert
argument_list|(
name|Reg
operator|==
literal|0
operator|&&
literal|"Reg given for non-register dependence!"
argument_list|)
expr_stmt|;
name|Contents
operator|.
name|Order
operator|.
name|isNormalMemory
operator|=
name|isNormalMemory
expr_stmt|;
name|Contents
operator|.
name|Order
operator|.
name|isMustAlias
operator|=
name|isMustAlias
expr_stmt|;
name|Contents
operator|.
name|Order
operator|.
name|isArtificial
operator|=
name|isArtificial
expr_stmt|;
break|break;
block|}
block|}
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
if|if
condition|(
name|Dep
operator|!=
name|Other
operator|.
name|Dep
operator|||
name|Latency
operator|!=
name|Other
operator|.
name|Latency
condition|)
return|return
name|false
return|;
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
name|Order
operator|.
name|isNormalMemory
operator|==
name|Other
operator|.
name|Contents
operator|.
name|Order
operator|.
name|isNormalMemory
operator|&&
name|Contents
operator|.
name|Order
operator|.
name|isMustAlias
operator|==
name|Other
operator|.
name|Contents
operator|.
name|Order
operator|.
name|isMustAlias
operator|&&
name|Contents
operator|.
name|Order
operator|.
name|isArtificial
operator|==
name|Other
operator|.
name|Contents
operator|.
name|Order
operator|.
name|isArtificial
return|;
block|}
name|assert
argument_list|(
literal|0
operator|&&
literal|"Invalid dependency kind!"
argument_list|)
expr_stmt|;
return|return
name|false
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
comment|/// getLatency - Return the latency value for this edge, which roughly
comment|/// means the minimum number of cycles that must elapse between the
comment|/// predecessor and the successor, given that they have this edge
comment|/// between them.
name|unsigned
name|getLatency
argument_list|()
specifier|const
block|{
return|return
name|Latency
return|;
block|}
comment|/// setLatency - Set the latency for this edge.
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
comment|//// getSUnit - Return the SUnit to which this edge points.
name|SUnit
operator|*
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
comment|//// setSUnit - Assign the SUnit to which this edge points.
name|void
name|setSUnit
parameter_list|(
name|SUnit
modifier|*
name|SU
parameter_list|)
block|{
name|Dep
operator|.
name|setPointer
argument_list|(
name|SU
argument_list|)
expr_stmt|;
block|}
comment|/// getKind - Return an enum value representing the kind of the dependence.
name|Kind
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
comment|/// isCtrl - Shorthand for getKind() != SDep::Data.
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
comment|/// isNormalMemory - Test if this is an Order dependence between two
comment|/// memory accesses where both sides of the dependence access memory
comment|/// in non-volatile and fully modeled ways.
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
name|Contents
operator|.
name|Order
operator|.
name|isNormalMemory
return|;
block|}
comment|/// isMustAlias - Test if this is an Order dependence that is marked
comment|/// as "must alias", meaning that the SUnits at either end of the edge
comment|/// have a memory dependence on a known memory location.
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
name|Order
operator|.
name|isMustAlias
return|;
block|}
comment|/// isArtificial - Test if this is an Order dependence that is marked
comment|/// as "artificial", meaning it isn't necessary for correctness.
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
name|Order
operator|.
name|isArtificial
return|;
block|}
comment|/// isAssignedRegDep - Test if this is a Data dependence that is
comment|/// associated with a register.
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
comment|/// getReg - Return the register associated with this edge. This is
comment|/// only valid on Data, Anti, and Output edges. On Data edges, this
comment|/// value may be zero, meaning there is no associated register.
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
comment|/// setReg - Assign the associated register for this edge. This is
comment|/// only valid on Data, Anti, and Output edges. On Anti and Output
comment|/// edges, this value must not be zero. On Data edges, the value may
comment|/// be zero, which would mean that no specific register is associated
comment|/// with this edge.
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
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// SUnit - Scheduling unit. This is a node in the scheduling DAG.
end_comment

begin_decl_stmt
name|class
name|SUnit
block|{
name|private
label|:
name|SDNode
modifier|*
name|Node
decl_stmt|;
comment|// Representative node.
name|MachineInstr
modifier|*
name|Instr
decl_stmt|;
comment|// Alternatively, a MachineInstr.
name|MachineInstr
modifier|*
name|DbgInstr
decl_stmt|;
comment|// A dbg_value referencing this.
name|public
label|:
name|SUnit
modifier|*
name|OrigNode
decl_stmt|;
comment|// If not this, the node from which
comment|// this node was cloned.
comment|// Preds/Succs - The SUnits before/after us in the graph.  The boolean value
comment|// is true if the edge is a token chain edge, false if it is a value edge.
name|SmallVector
operator|<
name|SDep
operator|,
literal|4
operator|>
name|Preds
expr_stmt|;
comment|// All sunit predecessors.
name|SmallVector
operator|<
name|SDep
operator|,
literal|4
operator|>
name|Succs
expr_stmt|;
comment|// All sunit successors.
typedef|typedef
name|SmallVector
operator|<
name|SDep
operator|,
literal|4
operator|>
operator|::
name|iterator
name|pred_iterator
expr_stmt|;
typedef|typedef
name|SmallVector
operator|<
name|SDep
operator|,
literal|4
operator|>
operator|::
name|iterator
name|succ_iterator
expr_stmt|;
typedef|typedef
name|SmallVector
operator|<
name|SDep
operator|,
literal|4
operator|>
operator|::
name|const_iterator
name|const_pred_iterator
expr_stmt|;
typedef|typedef
name|SmallVector
operator|<
name|SDep
operator|,
literal|4
operator|>
operator|::
name|const_iterator
name|const_succ_iterator
expr_stmt|;
name|unsigned
name|NodeNum
decl_stmt|;
comment|// Entry # of node in the node vector.
name|unsigned
name|NodeQueueId
decl_stmt|;
comment|// Queue id of node.
name|unsigned
name|short
name|Latency
decl_stmt|;
comment|// Node latency.
name|unsigned
name|NumPreds
decl_stmt|;
comment|// # of SDep::Data preds.
name|unsigned
name|NumSuccs
decl_stmt|;
comment|// # of SDep::Data sucss.
name|unsigned
name|NumPredsLeft
decl_stmt|;
comment|// # of preds not scheduled.
name|unsigned
name|NumSuccsLeft
decl_stmt|;
comment|// # of succs not scheduled.
name|bool
name|isTwoAddress
range|:
literal|1
decl_stmt|;
comment|// Is a two-address instruction.
name|bool
name|isCommutable
range|:
literal|1
decl_stmt|;
comment|// Is a commutable instruction.
name|bool
name|hasPhysRegDefs
range|:
literal|1
decl_stmt|;
comment|// Has physreg defs that are being used.
name|bool
name|hasPhysRegClobbers
range|:
literal|1
decl_stmt|;
comment|// Has any physreg defs, used or not.
name|bool
name|isPending
range|:
literal|1
decl_stmt|;
comment|// True once pending.
name|bool
name|isAvailable
range|:
literal|1
decl_stmt|;
comment|// True once available.
name|bool
name|isScheduled
range|:
literal|1
decl_stmt|;
comment|// True once scheduled.
name|bool
name|isScheduleHigh
range|:
literal|1
decl_stmt|;
comment|// True if preferable to schedule high.
name|bool
name|isCloned
range|:
literal|1
decl_stmt|;
comment|// True if this node has been cloned.
name|private
label|:
name|bool
name|isDepthCurrent
range|:
literal|1
decl_stmt|;
comment|// True if Depth is current.
name|bool
name|isHeightCurrent
range|:
literal|1
decl_stmt|;
comment|// True if Height is current.
name|unsigned
name|Depth
decl_stmt|;
comment|// Node depth.
name|unsigned
name|Height
decl_stmt|;
comment|// Node height.
name|public
label|:
specifier|const
name|TargetRegisterClass
modifier|*
name|CopyDstRC
decl_stmt|;
comment|// Is a special copy node if not null.
specifier|const
name|TargetRegisterClass
modifier|*
name|CopySrcRC
decl_stmt|;
comment|/// SUnit - Construct an SUnit for pre-regalloc scheduling to represent
comment|/// an SDNode and any nodes flagged to it.
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
name|Instr
argument_list|(
literal|0
argument_list|)
operator|,
name|DbgInstr
argument_list|(
literal|0
argument_list|)
operator|,
name|OrigNode
argument_list|(
literal|0
argument_list|)
operator|,
name|NodeNum
argument_list|(
name|nodenum
argument_list|)
operator|,
name|NodeQueueId
argument_list|(
literal|0
argument_list|)
operator|,
name|Latency
argument_list|(
literal|0
argument_list|)
operator|,
name|NumPreds
argument_list|(
literal|0
argument_list|)
operator|,
name|NumSuccs
argument_list|(
literal|0
argument_list|)
operator|,
name|NumPredsLeft
argument_list|(
literal|0
argument_list|)
operator|,
name|NumSuccsLeft
argument_list|(
literal|0
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
name|isCloned
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
name|false
argument_list|)
operator|,
name|Depth
argument_list|(
literal|0
argument_list|)
operator|,
name|Height
argument_list|(
literal|0
argument_list|)
operator|,
name|CopyDstRC
argument_list|(
name|NULL
argument_list|)
operator|,
name|CopySrcRC
argument_list|(
argument|NULL
argument_list|)
block|{}
comment|/// SUnit - Construct an SUnit for post-regalloc scheduling to represent
comment|/// a MachineInstr.
name|SUnit
argument_list|(
argument|MachineInstr *instr
argument_list|,
argument|unsigned nodenum
argument_list|)
operator|:
name|Node
argument_list|(
literal|0
argument_list|)
operator|,
name|Instr
argument_list|(
name|instr
argument_list|)
operator|,
name|DbgInstr
argument_list|(
literal|0
argument_list|)
operator|,
name|OrigNode
argument_list|(
literal|0
argument_list|)
operator|,
name|NodeNum
argument_list|(
name|nodenum
argument_list|)
operator|,
name|NodeQueueId
argument_list|(
literal|0
argument_list|)
operator|,
name|Latency
argument_list|(
literal|0
argument_list|)
operator|,
name|NumPreds
argument_list|(
literal|0
argument_list|)
operator|,
name|NumSuccs
argument_list|(
literal|0
argument_list|)
operator|,
name|NumPredsLeft
argument_list|(
literal|0
argument_list|)
operator|,
name|NumSuccsLeft
argument_list|(
literal|0
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
name|isCloned
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
name|false
argument_list|)
operator|,
name|Depth
argument_list|(
literal|0
argument_list|)
operator|,
name|Height
argument_list|(
literal|0
argument_list|)
operator|,
name|CopyDstRC
argument_list|(
name|NULL
argument_list|)
operator|,
name|CopySrcRC
argument_list|(
argument|NULL
argument_list|)
block|{}
comment|/// SUnit - Construct a placeholder SUnit.
name|SUnit
argument_list|()
operator|:
name|Node
argument_list|(
literal|0
argument_list|)
operator|,
name|Instr
argument_list|(
literal|0
argument_list|)
operator|,
name|DbgInstr
argument_list|(
literal|0
argument_list|)
operator|,
name|OrigNode
argument_list|(
literal|0
argument_list|)
operator|,
name|NodeNum
argument_list|(
operator|~
literal|0u
argument_list|)
operator|,
name|NodeQueueId
argument_list|(
literal|0
argument_list|)
operator|,
name|Latency
argument_list|(
literal|0
argument_list|)
operator|,
name|NumPreds
argument_list|(
literal|0
argument_list|)
operator|,
name|NumSuccs
argument_list|(
literal|0
argument_list|)
operator|,
name|NumPredsLeft
argument_list|(
literal|0
argument_list|)
operator|,
name|NumSuccsLeft
argument_list|(
literal|0
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
name|isCloned
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
name|false
argument_list|)
operator|,
name|Depth
argument_list|(
literal|0
argument_list|)
operator|,
name|Height
argument_list|(
literal|0
argument_list|)
operator|,
name|CopyDstRC
argument_list|(
name|NULL
argument_list|)
operator|,
name|CopySrcRC
argument_list|(
argument|NULL
argument_list|)
block|{}
comment|/// setNode - Assign the representative SDNode for this SUnit.
comment|/// This may be used during pre-regalloc scheduling.
name|void
name|setNode
argument_list|(
argument|SDNode *N
argument_list|)
block|{
name|assert
argument_list|(
operator|!
name|Instr
operator|&&
literal|"Setting SDNode of SUnit with MachineInstr!"
argument_list|)
block|;
name|Node
operator|=
name|N
block|;     }
comment|/// getNode - Return the representative SDNode for this SUnit.
comment|/// This may be used during pre-regalloc scheduling.
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
comment|/// setInstr - Assign the instruction for the SUnit.
comment|/// This may be used during post-regalloc scheduling.
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
comment|/// getInstr - Return the representative MachineInstr for this SUnit.
comment|/// This may be used during post-regalloc scheduling.
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
comment|/// setDbgInstr - Assign the debug instruction for the SUnit.
comment|/// This may be used during post-regalloc scheduling.
name|void
name|setDbgInstr
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
literal|"Setting debug MachineInstr of SUnit with SDNode!"
argument_list|)
expr_stmt|;
name|DbgInstr
operator|=
name|MI
expr_stmt|;
block|}
comment|/// getDbgInstr - Return the debug MachineInstr for this SUnit.
comment|/// This may be used during post-regalloc scheduling.
name|MachineInstr
operator|*
name|getDbgInstr
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|Node
operator|&&
literal|"Reading debug MachineInstr of SUnit with SDNode!"
argument_list|)
block|;
return|return
name|DbgInstr
return|;
block|}
comment|/// addPred - This adds the specified edge as a pred of the current node if
comment|/// not already.  It also adds the current node as a successor of the
comment|/// specified node.
name|void
name|addPred
parameter_list|(
specifier|const
name|SDep
modifier|&
name|D
parameter_list|)
function_decl|;
comment|/// removePred - This removes the specified edge as a pred of the current
comment|/// node if it exists.  It also removes the current node as a successor of
comment|/// the specified node.
name|void
name|removePred
parameter_list|(
specifier|const
name|SDep
modifier|&
name|D
parameter_list|)
function_decl|;
comment|/// getDepth - Return the depth of this node, which is the length of the
comment|/// maximum path up to any node with has no predecessors.
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
end_decl_stmt

begin_comment
comment|/// getHeight - Return the height of this node, which is the length of the
end_comment

begin_comment
comment|/// maximum path down to any node with has no successors.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_return
return|return
name|Height
return|;
end_return

begin_comment
unit|}
comment|/// setDepthToAtLeast - If NewDepth is greater than this node's
end_comment

begin_comment
comment|/// depth value, set it to be the new depth value. This also
end_comment

begin_comment
comment|/// recursively marks successor nodes dirty.
end_comment

begin_macro
unit|void
name|setDepthToAtLeast
argument_list|(
argument|unsigned NewDepth
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// setDepthToAtLeast - If NewDepth is greater than this node's
end_comment

begin_comment
comment|/// depth value, set it to be the new height value. This also
end_comment

begin_comment
comment|/// recursively marks predecessor nodes dirty.
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
comment|/// setDepthDirty - Set a flag in this node to indicate that its
end_comment

begin_comment
comment|/// stored Depth value will require recomputation the next time
end_comment

begin_comment
comment|/// getDepth() is called.
end_comment

begin_function_decl
name|void
name|setDepthDirty
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// setHeightDirty - Set a flag in this node to indicate that its
end_comment

begin_comment
comment|/// stored Height value will require recomputation the next time
end_comment

begin_comment
comment|/// getHeight() is called.
end_comment

begin_function_decl
name|void
name|setHeightDirty
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// isPred - Test if node N is a predecessor of this node.
end_comment

begin_function
name|bool
name|isPred
parameter_list|(
name|SUnit
modifier|*
name|N
parameter_list|)
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
operator|(
name|unsigned
operator|)
name|Preds
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
if|if
condition|(
name|Preds
index|[
name|i
index|]
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
end_function

begin_comment
comment|/// isSucc - Test if node N is a successor of this node.
end_comment

begin_function
name|bool
name|isSucc
parameter_list|(
name|SUnit
modifier|*
name|N
parameter_list|)
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
operator|(
name|unsigned
operator|)
name|Succs
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
if|if
condition|(
name|Succs
index|[
name|i
index|]
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
end_function

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
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// SchedulingPriorityQueue - This interface is used to plug different
end_comment

begin_comment
comment|/// priorities computation algorithms into the list scheduler. It implements
end_comment

begin_comment
comment|/// the interface of a standard priority queue, where nodes are inserted in
end_comment

begin_comment
comment|/// arbitrary order and returned in priority order.  The computation of the
end_comment

begin_comment
comment|/// priority and the representation of the queue are totally up to the
end_comment

begin_comment
comment|/// implementation to decide.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|SchedulingPriorityQueue
block|{
name|public
label|:
name|virtual
operator|~
name|SchedulingPriorityQueue
argument_list|()
block|{}
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
operator|=
literal|0
expr_stmt|;
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
name|unsigned
name|size
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|bool
name|empty
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
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
name|virtual
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
init|=
literal|0
decl_stmt|;
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
comment|/// ScheduledNode - As each node is scheduled, this method is invoked.  This
comment|/// allows the priority function to adjust the priority of related
comment|/// unscheduled nodes, for example.
comment|///
name|virtual
name|void
name|ScheduledNode
parameter_list|(
name|SUnit
modifier|*
parameter_list|)
block|{}
name|virtual
name|void
name|UnscheduledNode
parameter_list|(
name|SUnit
modifier|*
parameter_list|)
block|{}
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
name|MachineBasicBlock
modifier|*
name|BB
decl_stmt|;
comment|// The block in which to insert instructions
name|MachineBasicBlock
operator|::
name|iterator
name|InsertPos
expr_stmt|;
comment|// The position to insert instructions
specifier|const
name|TargetMachine
modifier|&
name|TM
decl_stmt|;
comment|// Target processor
specifier|const
name|TargetInstrInfo
modifier|*
name|TII
decl_stmt|;
comment|// Target instruction information
specifier|const
name|TargetRegisterInfo
modifier|*
name|TRI
decl_stmt|;
comment|// Target processor register info
specifier|const
name|TargetLowering
modifier|*
name|TLI
decl_stmt|;
comment|// Target lowering info
name|MachineFunction
modifier|&
name|MF
decl_stmt|;
comment|// Machine function
name|MachineRegisterInfo
modifier|&
name|MRI
decl_stmt|;
comment|// Virtual/real register map
name|MachineConstantPool
modifier|*
name|ConstPool
decl_stmt|;
comment|// Target constant pool
name|std
operator|::
name|vector
operator|<
name|SUnit
operator|*
operator|>
name|Sequence
expr_stmt|;
comment|// The schedule. Null SUnit*'s
comment|// represent noop instructions.
name|std
operator|::
name|vector
operator|<
name|SUnit
operator|>
name|SUnits
expr_stmt|;
comment|// The scheduling units.
name|SUnit
name|EntrySU
decl_stmt|;
comment|// Special node for the region entry.
name|SUnit
name|ExitSU
decl_stmt|;
comment|// Special node for the region exit.
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
comment|/// viewGraph - Pop up a GraphViz/gv window with the ScheduleDAG rendered
comment|/// using 'dot'.
comment|///
name|void
name|viewGraph
parameter_list|()
function_decl|;
comment|/// EmitSchedule - Insert MachineInstrs into the MachineBasicBlock
comment|/// according to the order specified in Sequence.
comment|///
name|virtual
name|MachineBasicBlock
modifier|*
name|EmitSchedule
argument_list|(
name|DenseMap
operator|<
name|MachineBasicBlock
operator|*
argument_list|,
name|MachineBasicBlock
operator|*
operator|>
operator|*
argument_list|)
init|=
literal|0
decl_stmt|;
name|void
name|dumpSchedule
argument_list|()
specifier|const
expr_stmt|;
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
comment|/// getGraphNodeLabel - Return a label for an SUnit node in a visualization
comment|/// of the ScheduleDAG.
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
comment|/// addCustomGraphFeatures - Add custom features for a visualization of
comment|/// the ScheduleDAG.
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
comment|/// VerifySchedule - Verify that all SUnits were scheduled and that
comment|/// their state is consistent.
name|void
name|VerifySchedule
parameter_list|(
name|bool
name|isBottomUp
parameter_list|)
function_decl|;
endif|#
directive|endif
name|protected
label|:
comment|/// Run - perform scheduling.
comment|///
name|void
name|Run
argument_list|(
name|MachineBasicBlock
operator|*
name|bb
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|insertPos
argument_list|)
decl_stmt|;
comment|/// BuildSchedGraph - Build SUnits and set up their Preds and Succs
comment|/// to form the scheduling dependency graph.
comment|///
name|virtual
name|void
name|BuildSchedGraph
parameter_list|(
name|AliasAnalysis
modifier|*
name|AA
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// ComputeLatency - Compute node latency.
comment|///
name|virtual
name|void
name|ComputeLatency
parameter_list|(
name|SUnit
modifier|*
name|SU
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// ComputeOperandLatency - Override dependence edge latency using
comment|/// operand use/def information
comment|///
name|virtual
name|void
name|ComputeOperandLatency
argument_list|(
name|SUnit
operator|*
argument_list|,
name|SUnit
operator|*
argument_list|,
name|SDep
operator|&
argument_list|)
decl|const
block|{ }
comment|/// Schedule - Order nodes according to selected style, filling
comment|/// in the Sequence member.
comment|///
name|virtual
name|void
name|Schedule
parameter_list|()
init|=
literal|0
function_decl|;
comment|/// ForceUnitLatencies - Return true if all scheduling edges should be given
comment|/// a latency value of one.  The default is to return false; schedulers may
comment|/// override this as needed.
name|virtual
name|bool
name|ForceUnitLatencies
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// EmitNoop - Emit a noop instruction.
comment|///
name|void
name|EmitNoop
parameter_list|()
function_decl|;
name|void
name|EmitPhysRegCopy
argument_list|(
name|SUnit
operator|*
name|SU
argument_list|,
name|DenseMap
operator|<
name|SUnit
operator|*
argument_list|,
name|unsigned
operator|>
operator|&
name|VRBaseMap
argument_list|)
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
specifier|const
name|SUnitIterator
modifier|&
name|operator
init|=
operator|(
specifier|const
name|SUnitIterator
operator|&
name|I
operator|)
block|{
name|assert
argument_list|(
name|I
operator|.
name|Node
operator|==
name|Node
operator|&&
literal|"Cannot assign iterators to two different nodes!"
argument_list|)
block|;
name|Operand
operator|=
name|I
operator|.
name|Operand
block|;
return|return
operator|*
name|this
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
comment|/// isCtrlDep - Test if this is not an SDep::Data dependence.
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
name|NodeType
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
specifier|inline
name|NodeType
modifier|*
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
specifier|inline
name|ChildIteratorType
name|child_begin
parameter_list|(
name|NodeType
modifier|*
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
specifier|inline
name|ChildIteratorType
name|child_end
parameter_list|(
name|NodeType
modifier|*
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
name|std
operator|::
name|vector
operator|<
name|SUnit
operator|>
operator|::
name|iterator
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
name|G
operator|->
name|SUnits
operator|.
name|begin
argument_list|()
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
name|G
operator|->
name|SUnits
operator|.
name|end
argument_list|()
return|;
block|}
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// ScheduleDAGTopologicalSort is a class that computes a topological
end_comment

begin_comment
comment|/// ordering for SUnits and provides methods for dynamically updating
end_comment

begin_comment
comment|/// the ordering as new edges are added.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This allows a very fast implementation of IsReachable, for example.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|ScheduleDAGTopologicalSort
block|{
comment|/// SUnits - A reference to the ScheduleDAG's SUnits.
name|std
operator|::
name|vector
operator|<
name|SUnit
operator|>
operator|&
name|SUnits
expr_stmt|;
comment|/// Index2Node - Maps topological index to the node number.
name|std
operator|::
name|vector
operator|<
name|int
operator|>
name|Index2Node
expr_stmt|;
comment|/// Node2Index - Maps the node number to its topological index.
name|std
operator|::
name|vector
operator|<
name|int
operator|>
name|Node2Index
expr_stmt|;
comment|/// Visited - a set of nodes visited during a DFS traversal.
name|BitVector
name|Visited
decl_stmt|;
comment|/// DFS - make a DFS traversal and mark all nodes affected by the
comment|/// edge insertion. These nodes will later get new topological indexes
comment|/// by means of the Shift method.
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
comment|/// Shift - reassign topological indexes for the nodes in the DAG
comment|/// to preserve the topological ordering.
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
comment|/// Allocate - assign the topological index to the node n.
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
name|explicit
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
argument_list|)
decl_stmt|;
comment|/// InitDAGTopologicalSorting - create the initial topological
comment|/// ordering from the DAG to be scheduled.
name|void
name|InitDAGTopologicalSorting
parameter_list|()
function_decl|;
comment|/// IsReachable - Checks if SU is reachable from TargetSU.
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
comment|/// WillCreateCycle - Returns true if adding an edge from SU to TargetSU
comment|/// will create a cycle.
name|bool
name|WillCreateCycle
parameter_list|(
name|SUnit
modifier|*
name|SU
parameter_list|,
name|SUnit
modifier|*
name|TargetSU
parameter_list|)
function_decl|;
comment|/// AddPred - Updates the topological ordering to accomodate an edge
comment|/// to be added from SUnit X to SUnit Y.
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
comment|/// RemovePred - Updates the topological ordering to accomodate an
comment|/// an edge to be removed from the specified node N from the predecessors
comment|/// of the current node M.
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

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

