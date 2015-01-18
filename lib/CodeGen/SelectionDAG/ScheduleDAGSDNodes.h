begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- ScheduleDAGSDNodes.h - SDNode Scheduling --------------*- C++ -*-===//
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
comment|// This file implements the ScheduleDAGSDNodes class, which implements
end_comment

begin_comment
comment|// scheduling for an SDNode-based dependency graph.
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
name|LLVM_LIB_CODEGEN_SELECTIONDAG_SCHEDULEDAGSDNODES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_CODEGEN_SELECTIONDAG_SCHEDULEDAGSDNODES_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineBasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ScheduleDAG.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// ScheduleDAGSDNodes - A ScheduleDAG for scheduling SDNode-based DAGs.
comment|///
comment|/// Edges between SUnits are initially based on edges in the SelectionDAG,
comment|/// and additional edges can be added by the schedulers as heuristics.
comment|/// SDNodes such as Constants, Registers, and a few others that are not
comment|/// interesting to schedulers are not allocated SUnits.
comment|///
comment|/// SDNodes with MVT::Glue operands are grouped along with the flagged
comment|/// nodes into a single SUnit so that they are scheduled together.
comment|///
comment|/// SDNode-based scheduling graphs do not use SDep::Anti or SDep::Output
comment|/// edges.  Physical register dependence information is not carried in
comment|/// the DAG and must be handled explicitly by schedulers.
comment|///
name|class
name|ScheduleDAGSDNodes
range|:
name|public
name|ScheduleDAG
block|{
name|public
operator|:
name|MachineBasicBlock
operator|*
name|BB
block|;
name|SelectionDAG
operator|*
name|DAG
block|;
comment|// DAG of the current basic block
specifier|const
name|InstrItineraryData
operator|*
name|InstrItins
block|;
comment|/// The schedule. Null SUnit*'s represent noop instructions.
name|std
operator|::
name|vector
operator|<
name|SUnit
operator|*
operator|>
name|Sequence
block|;
name|explicit
name|ScheduleDAGSDNodes
argument_list|(
name|MachineFunction
operator|&
name|mf
argument_list|)
block|;
name|virtual
operator|~
name|ScheduleDAGSDNodes
argument_list|()
block|{}
comment|/// Run - perform scheduling.
comment|///
name|void
name|Run
argument_list|(
name|SelectionDAG
operator|*
name|dag
argument_list|,
name|MachineBasicBlock
operator|*
name|bb
argument_list|)
block|;
comment|/// isPassiveNode - Return true if the node is a non-scheduled leaf.
comment|///
specifier|static
name|bool
name|isPassiveNode
argument_list|(
argument|SDNode *Node
argument_list|)
block|{
if|if
condition|(
name|isa
operator|<
name|ConstantSDNode
operator|>
operator|(
name|Node
operator|)
condition|)
return|return
name|true
return|;
if|if
condition|(
name|isa
operator|<
name|ConstantFPSDNode
operator|>
operator|(
name|Node
operator|)
condition|)
return|return
name|true
return|;
if|if
condition|(
name|isa
operator|<
name|RegisterSDNode
operator|>
operator|(
name|Node
operator|)
condition|)
return|return
name|true
return|;
if|if
condition|(
name|isa
operator|<
name|RegisterMaskSDNode
operator|>
operator|(
name|Node
operator|)
condition|)
return|return
name|true
return|;
if|if
condition|(
name|isa
operator|<
name|GlobalAddressSDNode
operator|>
operator|(
name|Node
operator|)
condition|)
return|return
name|true
return|;
if|if
condition|(
name|isa
operator|<
name|BasicBlockSDNode
operator|>
operator|(
name|Node
operator|)
condition|)
return|return
name|true
return|;
if|if
condition|(
name|isa
operator|<
name|FrameIndexSDNode
operator|>
operator|(
name|Node
operator|)
condition|)
return|return
name|true
return|;
if|if
condition|(
name|isa
operator|<
name|ConstantPoolSDNode
operator|>
operator|(
name|Node
operator|)
condition|)
return|return
name|true
return|;
if|if
condition|(
name|isa
operator|<
name|TargetIndexSDNode
operator|>
operator|(
name|Node
operator|)
condition|)
return|return
name|true
return|;
if|if
condition|(
name|isa
operator|<
name|JumpTableSDNode
operator|>
operator|(
name|Node
operator|)
condition|)
return|return
name|true
return|;
if|if
condition|(
name|isa
operator|<
name|ExternalSymbolSDNode
operator|>
operator|(
name|Node
operator|)
condition|)
return|return
name|true
return|;
if|if
condition|(
name|isa
operator|<
name|BlockAddressSDNode
operator|>
operator|(
name|Node
operator|)
condition|)
return|return
name|true
return|;
if|if
condition|(
name|Node
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|EntryToken
operator|||
name|isa
operator|<
name|MDNodeSDNode
operator|>
operator|(
name|Node
operator|)
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
comment|/// NewSUnit - Creates a new SUnit and return a ptr to it.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
name|SUnit
modifier|*
name|newSUnit
parameter_list|(
name|SDNode
modifier|*
name|N
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Clone - Creates a clone of the specified SUnit. It does not copy the
end_comment

begin_comment
comment|/// predecessors / successors info nor the temporary scheduling states.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
name|SUnit
modifier|*
name|Clone
parameter_list|(
name|SUnit
modifier|*
name|N
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// BuildSchedGraph - Build the SUnit graph from the selection dag that we
end_comment

begin_comment
comment|/// are input.  This SUnit graph is similar to the SelectionDAG, but
end_comment

begin_comment
comment|/// excludes nodes that aren't interesting to scheduling, and represents
end_comment

begin_comment
comment|/// flagged together nodes with a single SUnit.
end_comment

begin_function_decl
name|void
name|BuildSchedGraph
parameter_list|(
name|AliasAnalysis
modifier|*
name|AA
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// InitVRegCycleFlag - Set isVRegCycle if this node's single use is
end_comment

begin_comment
comment|/// CopyToReg and its only active data operands are CopyFromReg within a
end_comment

begin_comment
comment|/// single block loop.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
name|void
name|InitVRegCycleFlag
parameter_list|(
name|SUnit
modifier|*
name|SU
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// InitNumRegDefsLeft - Determine the # of regs defined by this node.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
name|void
name|InitNumRegDefsLeft
parameter_list|(
name|SUnit
modifier|*
name|SU
parameter_list|)
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

begin_decl_stmt
name|virtual
name|void
name|computeOperandLatency
argument_list|(
name|SDNode
operator|*
name|Def
argument_list|,
name|SDNode
operator|*
name|Use
argument_list|,
name|unsigned
name|OpIdx
argument_list|,
name|SDep
operator|&
name|dep
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Schedule - Order nodes according to selected style, filling
end_comment

begin_comment
comment|/// in the Sequence member.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
name|virtual
name|void
name|Schedule
parameter_list|()
init|=
literal|0
function_decl|;
end_function_decl

begin_comment
comment|/// VerifyScheduledSequence - Verify that all SUnits are scheduled and
end_comment

begin_comment
comment|/// consistent with the Sequence of scheduled instructions.
end_comment

begin_function_decl
name|void
name|VerifyScheduledSequence
parameter_list|(
name|bool
name|isBottomUp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// EmitSchedule - Insert MachineInstrs into the MachineBasicBlock
end_comment

begin_comment
comment|/// according to the order specified in Sequence.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|virtual
name|MachineBasicBlock
modifier|*
name|EmitSchedule
argument_list|(
name|MachineBasicBlock
operator|::
name|iterator
operator|&
name|InsertPos
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
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
end_decl_stmt

begin_expr_stmt
name|void
name|dumpSchedule
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|string
name|getDAGName
argument_list|()
specifier|const
name|override
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|virtual
name|void
name|getCustomGraphFeatures
argument_list|(
name|GraphWriter
operator|<
name|ScheduleDAG
operator|*
operator|>
operator|&
name|GW
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// RegDefIter - In place iteration over the values defined by an
end_comment

begin_comment
comment|/// SUnit. This does not need copies of the iterator or any other STLisms.
end_comment

begin_comment
comment|/// The iterator creates itself, rather than being provided by the SchedDAG.
end_comment

begin_decl_stmt
name|class
name|RegDefIter
block|{
specifier|const
name|ScheduleDAGSDNodes
modifier|*
name|SchedDAG
decl_stmt|;
specifier|const
name|SDNode
modifier|*
name|Node
decl_stmt|;
name|unsigned
name|DefIdx
decl_stmt|;
name|unsigned
name|NodeNumDefs
decl_stmt|;
name|MVT
name|ValueType
decl_stmt|;
name|public
label|:
name|RegDefIter
argument_list|(
specifier|const
name|SUnit
operator|*
name|SU
argument_list|,
specifier|const
name|ScheduleDAGSDNodes
operator|*
name|SD
argument_list|)
expr_stmt|;
name|bool
name|IsValid
argument_list|()
specifier|const
block|{
return|return
name|Node
operator|!=
name|nullptr
return|;
block|}
name|MVT
name|GetValue
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|IsValid
argument_list|()
operator|&&
literal|"bad iterator"
argument_list|)
block|;
return|return
name|ValueType
return|;
block|}
specifier|const
name|SDNode
operator|*
name|GetNode
argument_list|()
specifier|const
block|{
return|return
name|Node
return|;
block|}
name|unsigned
name|GetIdx
argument_list|()
specifier|const
block|{
return|return
name|DefIdx
operator|-
literal|1
return|;
block|}
name|void
name|Advance
parameter_list|()
function_decl|;
name|private
label|:
name|void
name|InitNodeNumDefs
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_label
name|protected
label|:
end_label

begin_comment
comment|/// ForceUnitLatencies - Return true if all scheduling edges should be given
end_comment

begin_comment
comment|/// a latency value of one.  The default is to return false; schedulers may
end_comment

begin_comment
comment|/// override this as needed.
end_comment

begin_expr_stmt
name|virtual
name|bool
name|forceUnitLatencies
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|/// ClusterNeighboringLoads - Cluster loads from "near" addresses into
end_comment

begin_comment
comment|/// combined SUnits.
end_comment

begin_function_decl
name|void
name|ClusterNeighboringLoads
parameter_list|(
name|SDNode
modifier|*
name|Node
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ClusterNodes - Cluster certain nodes which should be scheduled together.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
name|void
name|ClusterNodes
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// BuildSchedUnits, AddSchedEdges - Helper functions for BuildSchedGraph.
end_comment

begin_function_decl
name|void
name|BuildSchedUnits
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AddSchedEdges
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
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
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|InsertPos
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
unit|}; }
endif|#
directive|endif
end_endif

end_unit

