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
name|SCHEDULEDAGSDNODES_H
end_ifndef

begin_define
define|#
directive|define
name|SCHEDULEDAGSDNODES_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/ScheduleDAG.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/SelectionDAG.h"
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
comment|/// SDNodes with MVT::Flag operands are grouped along with the flagged
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
name|SelectionDAG
operator|*
name|DAG
block|;
comment|// DAG of the current basic block
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
argument|SelectionDAG *dag
argument_list|,
argument|MachineBasicBlock *bb
argument_list|,
argument|MachineBasicBlock::iterator insertPos
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
name|Node
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|EntryToken
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

begin_function
name|SUnit
modifier|*
name|NewSUnit
parameter_list|(
name|SDNode
modifier|*
name|N
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|NDEBUG
specifier|const
name|SUnit
modifier|*
name|Addr
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|!
name|SUnits
operator|.
name|empty
argument_list|()
condition|)
name|Addr
operator|=
operator|&
name|SUnits
index|[
literal|0
index|]
expr_stmt|;
endif|#
directive|endif
name|SUnits
operator|.
name|push_back
argument_list|(
name|SUnit
argument_list|(
name|N
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
expr_stmt|;
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
expr_stmt|;
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
expr_stmt|;
return|return
operator|&
name|SUnits
operator|.
name|back
argument_list|()
return|;
block|}
end_function

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
name|virtual
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
comment|/// ComputeLatency - Compute node latency.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
name|virtual
name|void
name|ComputeLatency
parameter_list|(
name|SUnit
modifier|*
name|SU
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
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
name|EM
argument_list|)
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

begin_label
name|private
label|:
end_label

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

begin_endif
unit|}; }
endif|#
directive|endif
end_endif

end_unit

