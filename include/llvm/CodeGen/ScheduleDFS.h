begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ScheduleDAGILP.h - ILP metric for ScheduleDAGInstrs ------*- C++ -*-===//
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
comment|// Definition of an ILP metric for machine level instruction scheduling.
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
name|LLVM_CODEGEN_SCHEDULEDFS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_SCHEDULEDFS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ScheduleDAG.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
comment|/// \brief Represent the ILP of the subDAG rooted at a DAG node.
comment|///
comment|/// ILPValues summarize the DAG subtree rooted at each node. ILPValues are
comment|/// valid for all nodes regardless of their subtree membership.
comment|///
comment|/// When computed using bottom-up DFS, this metric assumes that the DAG is a
comment|/// forest of trees with roots at the bottom of the schedule branching upward.
struct|struct
name|ILPValue
block|{
name|unsigned
name|InstrCount
decl_stmt|;
comment|/// Length may either correspond to depth or height, depending on direction,
comment|/// and cycles or nodes depending on context.
name|unsigned
name|Length
decl_stmt|;
name|ILPValue
argument_list|(
argument|unsigned count
argument_list|,
argument|unsigned length
argument_list|)
block|:
name|InstrCount
argument_list|(
name|count
argument_list|)
operator|,
name|Length
argument_list|(
argument|length
argument_list|)
block|{}
comment|// Order by the ILP metric's value.
name|bool
name|operator
operator|<
operator|(
name|ILPValue
name|RHS
operator|)
specifier|const
block|{
return|return
operator|(
name|uint64_t
operator|)
name|InstrCount
operator|*
name|RHS
operator|.
name|Length
operator|<
operator|(
name|uint64_t
operator|)
name|Length
operator|*
name|RHS
operator|.
name|InstrCount
return|;
block|}
name|bool
name|operator
operator|>
operator|(
name|ILPValue
name|RHS
operator|)
specifier|const
block|{
return|return
name|RHS
operator|<
operator|*
name|this
return|;
block|}
name|bool
name|operator
operator|<=
operator|(
name|ILPValue
name|RHS
operator|)
specifier|const
block|{
return|return
operator|(
name|uint64_t
operator|)
name|InstrCount
operator|*
name|RHS
operator|.
name|Length
operator|<=
operator|(
name|uint64_t
operator|)
name|Length
operator|*
name|RHS
operator|.
name|InstrCount
return|;
block|}
name|bool
name|operator
operator|>=
operator|(
name|ILPValue
name|RHS
operator|)
specifier|const
block|{
return|return
name|RHS
operator|<=
operator|*
name|this
return|;
block|}
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
block|}
struct|;
comment|/// \brief Compute the values of each DAG node for various metrics during DFS.
name|class
name|SchedDFSResult
block|{
name|friend
name|class
name|SchedDFSImpl
decl_stmt|;
specifier|static
specifier|const
name|unsigned
name|InvalidSubtreeID
init|=
operator|~
literal|0u
decl_stmt|;
comment|/// \brief Per-SUnit data computed during DFS for various metrics.
comment|///
comment|/// A node's SubtreeID is set to itself when it is visited to indicate that it
comment|/// is the root of a subtree. Later it is set to its parent to indicate an
comment|/// interior node. Finally, it is set to a representative subtree ID during
comment|/// finalization.
struct|struct
name|NodeData
block|{
name|unsigned
name|InstrCount
init|=
literal|0
decl_stmt|;
name|unsigned
name|SubtreeID
init|=
name|InvalidSubtreeID
decl_stmt|;
name|NodeData
argument_list|()
operator|=
expr|default
expr_stmt|;
block|}
struct|;
comment|/// \brief Per-Subtree data computed during DFS.
struct|struct
name|TreeData
block|{
name|unsigned
name|ParentTreeID
init|=
name|InvalidSubtreeID
decl_stmt|;
name|unsigned
name|SubInstrCount
init|=
literal|0
decl_stmt|;
name|TreeData
argument_list|()
operator|=
expr|default
expr_stmt|;
block|}
struct|;
comment|/// \brief Record a connection between subtrees and the connection level.
struct|struct
name|Connection
block|{
name|unsigned
name|TreeID
decl_stmt|;
name|unsigned
name|Level
decl_stmt|;
name|Connection
argument_list|(
argument|unsigned tree
argument_list|,
argument|unsigned level
argument_list|)
block|:
name|TreeID
argument_list|(
name|tree
argument_list|)
operator|,
name|Level
argument_list|(
argument|level
argument_list|)
block|{}
block|}
struct|;
name|bool
name|IsBottomUp
decl_stmt|;
name|unsigned
name|SubtreeLimit
decl_stmt|;
comment|/// DFS results for each SUnit in this DAG.
name|std
operator|::
name|vector
operator|<
name|NodeData
operator|>
name|DFSNodeData
expr_stmt|;
comment|// Store per-tree data indexed on tree ID,
name|SmallVector
operator|<
name|TreeData
operator|,
literal|16
operator|>
name|DFSTreeData
expr_stmt|;
comment|// For each subtree discovered during DFS, record its connections to other
comment|// subtrees.
name|std
operator|::
name|vector
operator|<
name|SmallVector
operator|<
name|Connection
operator|,
literal|4
operator|>>
name|SubtreeConnections
expr_stmt|;
comment|/// Cache the current connection level of each subtree.
comment|/// This mutable array is updated during scheduling.
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|SubtreeConnectLevels
expr_stmt|;
name|public
label|:
name|SchedDFSResult
argument_list|(
argument|bool IsBU
argument_list|,
argument|unsigned lim
argument_list|)
block|:
name|IsBottomUp
argument_list|(
name|IsBU
argument_list|)
operator|,
name|SubtreeLimit
argument_list|(
argument|lim
argument_list|)
block|{}
comment|/// \brief Get the node cutoff before subtrees are considered significant.
name|unsigned
name|getSubtreeLimit
argument_list|()
specifier|const
block|{
return|return
name|SubtreeLimit
return|;
block|}
comment|/// \brief Return true if this DFSResult is uninitialized.
comment|///
comment|/// resize() initializes DFSResult, while compute() populates it.
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|DFSNodeData
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// \brief Clear the results.
name|void
name|clear
parameter_list|()
block|{
name|DFSNodeData
operator|.
name|clear
argument_list|()
expr_stmt|;
name|DFSTreeData
operator|.
name|clear
argument_list|()
expr_stmt|;
name|SubtreeConnections
operator|.
name|clear
argument_list|()
expr_stmt|;
name|SubtreeConnectLevels
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
comment|/// \brief Initialize the result data with the size of the DAG.
name|void
name|resize
parameter_list|(
name|unsigned
name|NumSUnits
parameter_list|)
block|{
name|DFSNodeData
operator|.
name|resize
argument_list|(
name|NumSUnits
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Compute various metrics for the DAG with given roots.
name|void
name|compute
argument_list|(
name|ArrayRef
operator|<
name|SUnit
operator|>
name|SUnits
argument_list|)
decl_stmt|;
comment|/// \brief Get the number of instructions in the given subtree and its
comment|/// children.
name|unsigned
name|getNumInstrs
argument_list|(
specifier|const
name|SUnit
operator|*
name|SU
argument_list|)
decl|const
block|{
return|return
name|DFSNodeData
index|[
name|SU
operator|->
name|NodeNum
index|]
operator|.
name|InstrCount
return|;
block|}
comment|/// \brief Get the number of instructions in the given subtree not including
comment|/// children.
name|unsigned
name|getNumSubInstrs
argument_list|(
name|unsigned
name|SubtreeID
argument_list|)
decl|const
block|{
return|return
name|DFSTreeData
index|[
name|SubtreeID
index|]
operator|.
name|SubInstrCount
return|;
block|}
comment|/// \brief Get the ILP value for a DAG node.
comment|///
comment|/// A leaf node has an ILP of 1/1.
name|ILPValue
name|getILP
argument_list|(
specifier|const
name|SUnit
operator|*
name|SU
argument_list|)
decl|const
block|{
return|return
name|ILPValue
argument_list|(
name|DFSNodeData
index|[
name|SU
operator|->
name|NodeNum
index|]
operator|.
name|InstrCount
argument_list|,
literal|1
operator|+
name|SU
operator|->
name|getDepth
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief The number of subtrees detected in this DAG.
name|unsigned
name|getNumSubtrees
argument_list|()
specifier|const
block|{
return|return
name|SubtreeConnectLevels
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// \brief Get the ID of the subtree the given DAG node belongs to.
comment|///
comment|/// For convenience, if DFSResults have not been computed yet, give everything
comment|/// tree ID 0.
name|unsigned
name|getSubtreeID
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
name|empty
argument_list|()
condition|)
return|return
literal|0
return|;
name|assert
argument_list|(
name|SU
operator|->
name|NodeNum
operator|<
name|DFSNodeData
operator|.
name|size
argument_list|()
operator|&&
literal|"New Node"
argument_list|)
expr_stmt|;
return|return
name|DFSNodeData
index|[
name|SU
operator|->
name|NodeNum
index|]
operator|.
name|SubtreeID
return|;
block|}
comment|/// \brief Get the connection level of a subtree.
comment|///
comment|/// For bottom-up trees, the connection level is the latency depth (in cycles)
comment|/// of the deepest connection to another subtree.
name|unsigned
name|getSubtreeLevel
argument_list|(
name|unsigned
name|SubtreeID
argument_list|)
decl|const
block|{
return|return
name|SubtreeConnectLevels
index|[
name|SubtreeID
index|]
return|;
block|}
comment|/// \brief Scheduler callback to update SubtreeConnectLevels when a tree is
comment|/// initially scheduled.
name|void
name|scheduleTree
parameter_list|(
name|unsigned
name|SubtreeID
parameter_list|)
function_decl|;
block|}
empty_stmt|;
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
specifier|const
name|ILPValue
operator|&
name|Val
operator|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CODEGEN_SCHEDULEDFS_H
end_comment

end_unit

