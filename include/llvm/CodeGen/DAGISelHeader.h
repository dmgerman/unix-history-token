begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==-llvm/CodeGen/DAGISelHeader.h - Common DAG ISel definitions  -*- C++ -*-==//
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
comment|// This file provides definitions of the common, target-independent methods and
end_comment

begin_comment
comment|// data, which is used by SelectionDAG-based instruction selectors.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// *** NOTE: This file is #included into the middle of the target
end_comment

begin_comment
comment|// instruction selector class.  These functions are really methods.
end_comment

begin_comment
comment|// This is a little awkward, but it allows this code to be shared
end_comment

begin_comment
comment|// by all the targets while still being able to call into
end_comment

begin_comment
comment|// target-specific code without using a virtual function call.
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
name|LLVM_CODEGEN_DAGISEL_HEADER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_DAGISEL_HEADER_H
end_define

begin_comment
comment|/// ISelPosition - Node iterator marking the current position of
end_comment

begin_comment
comment|/// instruction selection as it procedes through the topologically-sorted
end_comment

begin_comment
comment|/// node list.
end_comment

begin_expr_stmt
name|SelectionDAG
operator|::
name|allnodes_iterator
name|ISelPosition
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// IsChainCompatible - Returns true if Chain is Op or Chain does
end_comment

begin_comment
comment|/// not reach Op.
end_comment

begin_function
specifier|static
name|bool
name|IsChainCompatible
parameter_list|(
name|SDNode
modifier|*
name|Chain
parameter_list|,
name|SDNode
modifier|*
name|Op
parameter_list|)
block|{
if|if
condition|(
name|Chain
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
if|if
condition|(
name|Chain
operator|->
name|getOpcode
argument_list|()
operator|==
name|ISD
operator|::
name|TokenFactor
condition|)
return|return
name|false
return|;
if|if
condition|(
name|Chain
operator|->
name|getNumOperands
argument_list|()
operator|>
literal|0
condition|)
block|{
name|SDValue
name|C0
init|=
name|Chain
operator|->
name|getOperand
argument_list|(
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|C0
operator|.
name|getValueType
argument_list|()
operator|==
name|MVT
operator|::
name|Other
condition|)
return|return
name|C0
operator|.
name|getNode
argument_list|()
operator|!=
name|Op
operator|&&
name|IsChainCompatible
argument_list|(
name|C0
operator|.
name|getNode
argument_list|()
argument_list|,
name|Op
argument_list|)
return|;
block|}
return|return
name|true
return|;
block|}
end_function

begin_comment
comment|/// ISelUpdater - helper class to handle updates of the
end_comment

begin_comment
comment|/// instruciton selection graph.
end_comment

begin_decl_stmt
name|class
name|VISIBILITY_HIDDEN
name|ISelUpdater
range|:
name|public
name|SelectionDAG
operator|::
name|DAGUpdateListener
block|{
name|SelectionDAG
operator|::
name|allnodes_iterator
operator|&
name|ISelPosition
block|;
name|public
operator|:
name|explicit
name|ISelUpdater
argument_list|(
name|SelectionDAG
operator|::
name|allnodes_iterator
operator|&
name|isp
argument_list|)
operator|:
name|ISelPosition
argument_list|(
argument|isp
argument_list|)
block|{}
comment|/// NodeDeleted - Handle nodes deleted from the graph. If the
comment|/// node being deleted is the current ISelPosition node, update
comment|/// ISelPosition.
comment|///
name|virtual
name|void
name|NodeDeleted
argument_list|(
argument|SDNode *N
argument_list|,
argument|SDNode *E
argument_list|)
block|{
if|if
condition|(
name|ISelPosition
operator|==
name|SelectionDAG
operator|::
name|allnodes_iterator
argument_list|(
name|N
argument_list|)
condition|)
operator|++
name|ISelPosition
expr_stmt|;
block|}
comment|/// NodeUpdated - Ignore updates for now.
name|virtual
name|void
name|NodeUpdated
argument_list|(
argument|SDNode *N
argument_list|)
block|{}
expr|}
block|;
comment|/// ReplaceUses - replace all uses of the old node F with the use
comment|/// of the new node T.
name|DISABLE_INLINE
name|void
name|ReplaceUses
argument_list|(
argument|SDValue F
argument_list|,
argument|SDValue T
argument_list|)
block|{
name|ISelUpdater
name|ISU
argument_list|(
name|ISelPosition
argument_list|)
block|;
name|CurDAG
operator|->
name|ReplaceAllUsesOfValueWith
argument_list|(
name|F
argument_list|,
name|T
argument_list|,
operator|&
name|ISU
argument_list|)
block|; }
comment|/// ReplaceUses - replace all uses of the old nodes F with the use
comment|/// of the new nodes T.
name|DISABLE_INLINE
name|void
name|ReplaceUses
argument_list|(
argument|const SDValue *F
argument_list|,
argument|const SDValue *T
argument_list|,
argument|unsigned Num
argument_list|)
block|{
name|ISelUpdater
name|ISU
argument_list|(
name|ISelPosition
argument_list|)
block|;
name|CurDAG
operator|->
name|ReplaceAllUsesOfValuesWith
argument_list|(
name|F
argument_list|,
name|T
argument_list|,
name|Num
argument_list|,
operator|&
name|ISU
argument_list|)
block|; }
comment|/// ReplaceUses - replace all uses of the old node F with the use
comment|/// of the new node T.
name|DISABLE_INLINE
name|void
name|ReplaceUses
argument_list|(
argument|SDNode *F
argument_list|,
argument|SDNode *T
argument_list|)
block|{
name|ISelUpdater
name|ISU
argument_list|(
name|ISelPosition
argument_list|)
block|;
name|CurDAG
operator|->
name|ReplaceAllUsesWith
argument_list|(
name|F
argument_list|,
name|T
argument_list|,
operator|&
name|ISU
argument_list|)
block|; }
comment|/// SelectRoot - Top level entry to DAG instruction selector.
comment|/// Selects instructions starting at the root of the current DAG.
name|void
name|SelectRoot
argument_list|(
argument|SelectionDAG&DAG
argument_list|)
block|{
name|SelectRootInit
argument_list|()
block|;
comment|// Create a dummy node (which is not added to allnodes), that adds
comment|// a reference to the root node, preventing it from being deleted,
comment|// and tracking any changes of the root.
name|HandleSDNode
name|Dummy
argument_list|(
name|CurDAG
operator|->
name|getRoot
argument_list|()
argument_list|)
block|;
name|ISelPosition
operator|=
name|llvm
operator|::
name|next
argument_list|(
name|SelectionDAG
operator|::
name|allnodes_iterator
argument_list|(
name|CurDAG
operator|->
name|getRoot
argument_list|()
operator|.
name|getNode
argument_list|()
argument_list|)
argument_list|)
block|;
comment|// The AllNodes list is now topological-sorted. Visit the
comment|// nodes by starting at the end of the list (the root of the
comment|// graph) and preceding back toward the beginning (the entry
comment|// node).
while|while
condition|(
name|ISelPosition
operator|!=
name|CurDAG
operator|->
name|allnodes_begin
argument_list|()
condition|)
block|{
name|SDNode
modifier|*
name|Node
init|=
operator|--
name|ISelPosition
decl_stmt|;
comment|// Skip dead nodes. DAGCombiner is expected to eliminate all dead nodes,
comment|// but there are currently some corner cases that it misses. Also, this
comment|// makes it theoretically possible to disable the DAGCombiner.
if|if
condition|(
name|Node
operator|->
name|use_empty
argument_list|()
condition|)
continue|continue;
if|#
directive|if
literal|0
block|DAG.setSubgraphColor(Node, "red");
endif|#
directive|endif
name|SDNode
modifier|*
name|ResNode
init|=
name|Select
argument_list|(
name|Node
argument_list|)
decl_stmt|;
comment|// If node should not be replaced, continue with the next one.
if|if
condition|(
name|ResNode
operator|==
name|Node
condition|)
continue|continue;
comment|// Replace node.
if|if
condition|(
name|ResNode
condition|)
block|{
if|#
directive|if
literal|0
block|DAG.setSubgraphColor(ResNode, "yellow");       DAG.setSubgraphColor(ResNode, "black");
endif|#
directive|endif
name|ReplaceUses
argument_list|(
name|Node
argument_list|,
name|ResNode
argument_list|)
expr_stmt|;
block|}
comment|// If after the replacement this node is not used any more,
comment|// remove this dead node.
if|if
condition|(
name|Node
operator|->
name|use_empty
argument_list|()
condition|)
block|{
comment|// Don't delete EntryToken, etc.
name|ISelUpdater
name|ISU
parameter_list|(
name|ISelPosition
parameter_list|)
function_decl|;
name|CurDAG
operator|->
name|RemoveDeadNode
argument_list|(
name|Node
argument_list|,
operator|&
name|ISU
argument_list|)
expr_stmt|;
block|}
block|}
name|CurDAG
operator|->
name|setRoot
argument_list|(
name|Dummy
operator|.
name|getValue
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LLVM_CODEGEN_DAGISEL_HEADER_H */
end_comment

end_unit

