begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=- llvm/CodeGen/MachineDominators.h - Machine Dom Calculation --*- C++ -*-==//
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
comment|// This file defines classes mirroring those in llvm/Analysis/Dominators.h,
end_comment

begin_comment
comment|// but for target-specific code rather than target-independent IR.
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
name|LLVM_CODEGEN_MACHINEDOMINATORS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_MACHINEDOMINATORS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineBasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunction.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunctionPass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/GenericDomTree.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/GenericDomTreeConstruction.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
operator|>
specifier|inline
name|void
name|DominatorTreeBase
operator|<
name|MachineBasicBlock
operator|>
operator|::
name|addRoot
argument_list|(
argument|MachineBasicBlock* MBB
argument_list|)
block|{
name|this
operator|->
name|Roots
operator|.
name|push_back
argument_list|(
name|MBB
argument_list|)
block|; }
name|EXTERN_TEMPLATE_INSTANTIATION
argument_list|(
argument|class DomTreeNodeBase<MachineBasicBlock>
argument_list|)
expr_stmt|;
name|EXTERN_TEMPLATE_INSTANTIATION
argument_list|(
argument|class DominatorTreeBase<MachineBasicBlock>
argument_list|)
empty_stmt|;
typedef|typedef
name|DomTreeNodeBase
operator|<
name|MachineBasicBlock
operator|>
name|MachineDomTreeNode
expr_stmt|;
comment|//===-------------------------------------
comment|/// DominatorTree Class - Concrete subclass of DominatorTreeBase that is used to
comment|/// compute a normal dominator tree.
comment|///
name|class
name|MachineDominatorTree
range|:
name|public
name|MachineFunctionPass
block|{
comment|/// \brief Helper structure used to hold all the basic blocks
comment|/// involved in the split of a critical edge.
block|struct
name|CriticalEdge
block|{
name|MachineBasicBlock
operator|*
name|FromBB
block|;
name|MachineBasicBlock
operator|*
name|ToBB
block|;
name|MachineBasicBlock
operator|*
name|NewBB
block|;
name|CriticalEdge
argument_list|(
name|MachineBasicBlock
operator|*
name|FromBB
argument_list|,
name|MachineBasicBlock
operator|*
name|ToBB
argument_list|,
name|MachineBasicBlock
operator|*
name|NewBB
argument_list|)
operator|:
name|FromBB
argument_list|(
name|FromBB
argument_list|)
block|,
name|ToBB
argument_list|(
name|ToBB
argument_list|)
block|,
name|NewBB
argument_list|(
argument|NewBB
argument_list|)
block|{}
block|}
block|;
comment|/// \brief Pile up all the critical edges to be split.
comment|/// The splitting of a critical edge is local and thus, it is possible
comment|/// to apply several of those changes at the same time.
name|mutable
name|SmallVector
operator|<
name|CriticalEdge
block|,
literal|32
operator|>
name|CriticalEdgesToSplit
block|;
comment|/// \brief Remember all the basic blocks that are inserted during
comment|/// edge splitting.
comment|/// Invariant: NewBBs == all the basic blocks contained in the NewBB
comment|/// field of all the elements of CriticalEdgesToSplit.
comment|/// I.e., forall elt in CriticalEdgesToSplit, it exists BB in NewBBs
comment|/// such as BB == elt.NewBB.
name|mutable
name|SmallSet
operator|<
name|MachineBasicBlock
operator|*
block|,
literal|32
operator|>
name|NewBBs
block|;
comment|/// \brief Apply all the recorded critical edges to the DT.
comment|/// This updates the underlying DT information in a way that uses
comment|/// the fast query path of DT as much as possible.
comment|///
comment|/// \post CriticalEdgesToSplit.empty().
name|void
name|applySplitCriticalEdges
argument_list|()
specifier|const
block|{
comment|// Bail out early if there is nothing to do.
if|if
condition|(
name|CriticalEdgesToSplit
operator|.
name|empty
argument_list|()
condition|)
return|return;
comment|// For each element in CriticalEdgesToSplit, remember whether or
comment|// not element is the new immediate domminator of its successor.
comment|// The mapping is done by index, i.e., the information for the ith
comment|// element of CriticalEdgesToSplit is the ith element of IsNewIDom.
name|SmallVector
operator|<
name|bool
block|,
literal|32
operator|>
name|IsNewIDom
block|;
name|IsNewIDom
operator|.
name|resize
argument_list|(
name|CriticalEdgesToSplit
operator|.
name|size
argument_list|()
argument_list|)
block|;
name|size_t
name|Idx
operator|=
literal|0
block|;
comment|// Collect all the dominance properties info, before invalidating
comment|// the underlying DT.
for|for
control|(
name|CriticalEdge
modifier|&
name|Edge
range|:
name|CriticalEdgesToSplit
control|)
block|{
comment|// Update dominator information.
name|MachineBasicBlock
modifier|*
name|Succ
init|=
name|Edge
operator|.
name|ToBB
decl_stmt|;
name|MachineDomTreeNode
modifier|*
name|SucccDTNode
init|=
name|DT
operator|->
name|getNode
argument_list|(
name|Succ
argument_list|)
decl_stmt|;
name|IsNewIDom
index|[
name|Idx
index|]
operator|=
name|true
expr_stmt|;
for|for
control|(
name|MachineBasicBlock
modifier|*
name|PredBB
range|:
name|Succ
operator|->
name|predecessors
argument_list|()
control|)
block|{
if|if
condition|(
name|PredBB
operator|==
name|Edge
operator|.
name|NewBB
condition|)
continue|continue;
comment|// If we are in this situation:
comment|// FromBB1        FromBB2
comment|//    +              +
comment|//   + +            + +
comment|//  +   +          +   +
comment|// ...  Split1  Split2 ...
comment|//           +   +
comment|//            + +
comment|//             +
comment|//            Succ
comment|// Instead of checking the domiance property with Split2, we
comment|// check it with FromBB2 since Split2 is still unknown of the
comment|// underlying DT structure.
if|if
condition|(
name|NewBBs
operator|.
name|count
argument_list|(
name|PredBB
argument_list|)
condition|)
block|{
name|assert
argument_list|(
name|PredBB
operator|->
name|pred_size
argument_list|()
operator|==
literal|1
operator|&&
literal|"A basic block resulting from a "
literal|"critical edge split has more "
literal|"than one predecessor!"
argument_list|)
expr_stmt|;
name|PredBB
operator|=
operator|*
name|PredBB
operator|->
name|pred_begin
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|DT
operator|->
name|dominates
argument_list|(
name|SucccDTNode
argument_list|,
name|DT
operator|->
name|getNode
argument_list|(
name|PredBB
argument_list|)
argument_list|)
condition|)
block|{
name|IsNewIDom
index|[
name|Idx
index|]
operator|=
name|false
expr_stmt|;
break|break;
block|}
block|}
operator|++
name|Idx
expr_stmt|;
block|}
comment|// Now, update DT with the collected dominance properties info.
name|Idx
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|CriticalEdge
modifier|&
name|Edge
range|:
name|CriticalEdgesToSplit
control|)
block|{
comment|// We know FromBB dominates NewBB.
name|MachineDomTreeNode
modifier|*
name|NewDTNode
init|=
name|DT
operator|->
name|addNewBlock
argument_list|(
name|Edge
operator|.
name|NewBB
argument_list|,
name|Edge
operator|.
name|FromBB
argument_list|)
decl_stmt|;
name|MachineDomTreeNode
modifier|*
name|SucccDTNode
init|=
name|DT
operator|->
name|getNode
argument_list|(
name|Edge
operator|.
name|ToBB
argument_list|)
decl_stmt|;
comment|// If all the other predecessors of "Succ" are dominated by "Succ" itself
comment|// then the new block is the new immediate dominator of "Succ". Otherwise,
comment|// the new block doesn't dominate anything.
if|if
condition|(
name|IsNewIDom
index|[
name|Idx
index|]
condition|)
name|DT
operator|->
name|changeImmediateDominator
argument_list|(
name|SucccDTNode
argument_list|,
name|NewDTNode
argument_list|)
expr_stmt|;
operator|++
name|Idx
expr_stmt|;
block|}
name|NewBBs
operator|.
name|clear
argument_list|()
expr_stmt|;
name|CriticalEdgesToSplit
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_decl_stmt
specifier|static
name|char
name|ID
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Pass ID, replacement for typeid
end_comment

begin_expr_stmt
name|DominatorTreeBase
operator|<
name|MachineBasicBlock
operator|>
operator|*
name|DT
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MachineDominatorTree
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|~
name|MachineDominatorTree
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DominatorTreeBase
operator|<
name|MachineBasicBlock
operator|>
operator|&
name|getBase
argument_list|()
block|{
name|applySplitCriticalEdges
argument_list|()
block|;
return|return
operator|*
name|DT
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|getAnalysisUsage
argument_list|(
name|AnalysisUsage
operator|&
name|AU
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getRoots -  Return the root blocks of the current CFG.  This may include
end_comment

begin_comment
comment|/// multiple blocks if we are computing post dominators.  For forward
end_comment

begin_comment
comment|/// dominators, this will always be a single block (the entry node).
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
specifier|inline
specifier|const
name|std
operator|::
name|vector
operator|<
name|MachineBasicBlock
operator|*
operator|>
operator|&
name|getRoots
argument_list|()
specifier|const
block|{
name|applySplitCriticalEdges
argument_list|()
block|;
return|return
name|DT
operator|->
name|getRoots
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|MachineBasicBlock
operator|*
name|getRoot
argument_list|()
specifier|const
block|{
name|applySplitCriticalEdges
argument_list|()
block|;
return|return
name|DT
operator|->
name|getRoot
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|MachineDomTreeNode
operator|*
name|getRootNode
argument_list|()
specifier|const
block|{
name|applySplitCriticalEdges
argument_list|()
block|;
return|return
name|DT
operator|->
name|getRootNode
argument_list|()
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|bool
name|runOnMachineFunction
argument_list|(
name|MachineFunction
operator|&
name|F
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|inline
name|bool
name|dominates
argument_list|(
specifier|const
name|MachineDomTreeNode
operator|*
name|A
argument_list|,
specifier|const
name|MachineDomTreeNode
operator|*
name|B
argument_list|)
decl|const
block|{
name|applySplitCriticalEdges
argument_list|()
expr_stmt|;
return|return
name|DT
operator|->
name|dominates
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|inline
name|bool
name|dominates
argument_list|(
specifier|const
name|MachineBasicBlock
operator|*
name|A
argument_list|,
specifier|const
name|MachineBasicBlock
operator|*
name|B
argument_list|)
decl|const
block|{
name|applySplitCriticalEdges
argument_list|()
expr_stmt|;
return|return
name|DT
operator|->
name|dominates
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|// dominates - Return true if A dominates B. This performs the
end_comment

begin_comment
comment|// special checks necessary if A and B are in the same basic block.
end_comment

begin_decl_stmt
name|bool
name|dominates
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|A
argument_list|,
specifier|const
name|MachineInstr
operator|*
name|B
argument_list|)
decl|const
block|{
name|applySplitCriticalEdges
argument_list|()
expr_stmt|;
specifier|const
name|MachineBasicBlock
modifier|*
name|BBA
init|=
name|A
operator|->
name|getParent
argument_list|()
decl_stmt|,
modifier|*
name|BBB
init|=
name|B
operator|->
name|getParent
argument_list|()
decl_stmt|;
if|if
condition|(
name|BBA
operator|!=
name|BBB
condition|)
return|return
name|DT
operator|->
name|dominates
argument_list|(
name|BBA
argument_list|,
name|BBB
argument_list|)
return|;
comment|// Loop through the basic block until we find A or B.
name|MachineBasicBlock
operator|::
name|const_iterator
name|I
operator|=
name|BBA
operator|->
name|begin
argument_list|()
expr_stmt|;
for|for
control|(
init|;
operator|&
operator|*
name|I
operator|!=
name|A
operator|&&
operator|&
operator|*
name|I
operator|!=
name|B
condition|;
operator|++
name|I
control|)
comment|/*empty*/
empty_stmt|;
comment|//if(!DT.IsPostDominators) {
comment|// A dominates B if it is found first in the basic block.
return|return
operator|&
operator|*
name|I
operator|==
name|A
return|;
comment|//} else {
comment|//  // A post-dominates B if B is found first in the basic block.
comment|//  return&*I == B;
comment|//}
block|}
end_decl_stmt

begin_decl_stmt
specifier|inline
name|bool
name|properlyDominates
argument_list|(
specifier|const
name|MachineDomTreeNode
operator|*
name|A
argument_list|,
specifier|const
name|MachineDomTreeNode
operator|*
name|B
argument_list|)
decl|const
block|{
name|applySplitCriticalEdges
argument_list|()
expr_stmt|;
return|return
name|DT
operator|->
name|properlyDominates
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|inline
name|bool
name|properlyDominates
argument_list|(
specifier|const
name|MachineBasicBlock
operator|*
name|A
argument_list|,
specifier|const
name|MachineBasicBlock
operator|*
name|B
argument_list|)
decl|const
block|{
name|applySplitCriticalEdges
argument_list|()
expr_stmt|;
return|return
name|DT
operator|->
name|properlyDominates
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// findNearestCommonDominator - Find nearest common dominator basic block
end_comment

begin_comment
comment|/// for basic block A and B. If there is no such block then return NULL.
end_comment

begin_function
specifier|inline
name|MachineBasicBlock
modifier|*
name|findNearestCommonDominator
parameter_list|(
name|MachineBasicBlock
modifier|*
name|A
parameter_list|,
name|MachineBasicBlock
modifier|*
name|B
parameter_list|)
block|{
name|applySplitCriticalEdges
argument_list|()
expr_stmt|;
return|return
name|DT
operator|->
name|findNearestCommonDominator
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_decl_stmt
specifier|inline
name|MachineDomTreeNode
modifier|*
name|operator
index|[]
argument_list|(
name|MachineBasicBlock
operator|*
name|BB
argument_list|)
decl|const
block|{
name|applySplitCriticalEdges
argument_list|()
expr_stmt|;
return|return
name|DT
operator|->
name|getNode
argument_list|(
name|BB
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// getNode - return the (Post)DominatorTree node for the specified basic
end_comment

begin_comment
comment|/// block.  This is the same as using operator[] on this class.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
specifier|inline
name|MachineDomTreeNode
modifier|*
name|getNode
argument_list|(
name|MachineBasicBlock
operator|*
name|BB
argument_list|)
decl|const
block|{
name|applySplitCriticalEdges
argument_list|()
expr_stmt|;
return|return
name|DT
operator|->
name|getNode
argument_list|(
name|BB
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// addNewBlock - Add a new node to the dominator tree information.  This
end_comment

begin_comment
comment|/// creates a new node as a child of DomBB dominator node,linking it into
end_comment

begin_comment
comment|/// the children list of the immediate dominator.
end_comment

begin_function
specifier|inline
name|MachineDomTreeNode
modifier|*
name|addNewBlock
parameter_list|(
name|MachineBasicBlock
modifier|*
name|BB
parameter_list|,
name|MachineBasicBlock
modifier|*
name|DomBB
parameter_list|)
block|{
name|applySplitCriticalEdges
argument_list|()
expr_stmt|;
return|return
name|DT
operator|->
name|addNewBlock
argument_list|(
name|BB
argument_list|,
name|DomBB
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// changeImmediateDominator - This method is used to update the dominator
end_comment

begin_comment
comment|/// tree information when a node's immediate dominator changes.
end_comment

begin_comment
comment|///
end_comment

begin_function
specifier|inline
name|void
name|changeImmediateDominator
parameter_list|(
name|MachineBasicBlock
modifier|*
name|N
parameter_list|,
name|MachineBasicBlock
modifier|*
name|NewIDom
parameter_list|)
block|{
name|applySplitCriticalEdges
argument_list|()
expr_stmt|;
name|DT
operator|->
name|changeImmediateDominator
argument_list|(
name|N
argument_list|,
name|NewIDom
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|inline
name|void
name|changeImmediateDominator
parameter_list|(
name|MachineDomTreeNode
modifier|*
name|N
parameter_list|,
name|MachineDomTreeNode
modifier|*
name|NewIDom
parameter_list|)
block|{
name|applySplitCriticalEdges
argument_list|()
expr_stmt|;
name|DT
operator|->
name|changeImmediateDominator
argument_list|(
name|N
argument_list|,
name|NewIDom
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// eraseNode - Removes a node from  the dominator tree. Block must not
end_comment

begin_comment
comment|/// dominate any other blocks. Removes node from its immediate dominator's
end_comment

begin_comment
comment|/// children list. Deletes dominator node associated with basic block BB.
end_comment

begin_function
specifier|inline
name|void
name|eraseNode
parameter_list|(
name|MachineBasicBlock
modifier|*
name|BB
parameter_list|)
block|{
name|applySplitCriticalEdges
argument_list|()
expr_stmt|;
name|DT
operator|->
name|eraseNode
argument_list|(
name|BB
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// splitBlock - BB is split and now it has one successor. Update dominator
end_comment

begin_comment
comment|/// tree to reflect this change.
end_comment

begin_function
specifier|inline
name|void
name|splitBlock
parameter_list|(
name|MachineBasicBlock
modifier|*
name|NewBB
parameter_list|)
block|{
name|applySplitCriticalEdges
argument_list|()
expr_stmt|;
name|DT
operator|->
name|splitBlock
argument_list|(
name|NewBB
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// isReachableFromEntry - Return true if A is dominated by the entry
end_comment

begin_comment
comment|/// block of the function containing it.
end_comment

begin_function
name|bool
name|isReachableFromEntry
parameter_list|(
specifier|const
name|MachineBasicBlock
modifier|*
name|A
parameter_list|)
block|{
name|applySplitCriticalEdges
argument_list|()
expr_stmt|;
return|return
name|DT
operator|->
name|isReachableFromEntry
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|void
name|releaseMemory
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|Module
operator|*
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Record that the critical edge (FromBB, ToBB) has been
end_comment

begin_comment
comment|/// split with NewBB.
end_comment

begin_comment
comment|/// This is best to use this method instead of directly update the
end_comment

begin_comment
comment|/// underlying information, because this helps mitigating the
end_comment

begin_comment
comment|/// number of time the DT information is invalidated.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \note Do not use this method with regular edges.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \note To benefit from the compile time improvement incurred by this
end_comment

begin_comment
comment|/// method, the users of this method have to limit the queries to the DT
end_comment

begin_comment
comment|/// interface between two edges splitting. In other words, they have to
end_comment

begin_comment
comment|/// pack the splitting of critical edges as much as possible.
end_comment

begin_function
name|void
name|recordSplitCriticalEdge
parameter_list|(
name|MachineBasicBlock
modifier|*
name|FromBB
parameter_list|,
name|MachineBasicBlock
modifier|*
name|ToBB
parameter_list|,
name|MachineBasicBlock
modifier|*
name|NewBB
parameter_list|)
block|{
name|bool
name|Inserted
init|=
name|NewBBs
operator|.
name|insert
argument_list|(
name|NewBB
argument_list|)
operator|.
name|second
decl_stmt|;
operator|(
name|void
operator|)
name|Inserted
expr_stmt|;
name|assert
argument_list|(
name|Inserted
operator|&&
literal|"A basic block inserted via edge splitting cannot appear twice"
argument_list|)
expr_stmt|;
name|CriticalEdgesToSplit
operator|.
name|push_back
argument_list|(
name|CriticalEdge
argument_list|(
name|FromBB
argument_list|,
name|ToBB
argument_list|,
name|NewBB
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
unit|};
comment|//===-------------------------------------
end_comment

begin_comment
comment|/// DominatorTree GraphTraits specialization so the DominatorTree can be
end_comment

begin_comment
comment|/// iterable by generic graph iterators.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
expr|struct
name|GraphTraits
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|GraphTraits
operator|<
name|MachineDomTreeNode
operator|*
operator|>
block|{
typedef|typedef
name|MachineDomTreeNode
name|NodeType
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|NodeType
operator|::
name|iterator
name|ChildIteratorType
expr_stmt|;
end_typedef

begin_function
specifier|static
name|NodeType
modifier|*
name|getEntryNode
parameter_list|(
name|NodeType
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
name|N
operator|->
name|begin
argument_list|()
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
name|N
operator|->
name|end
argument_list|()
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
name|MachineDominatorTree
operator|*
operator|>
operator|:
name|public
name|GraphTraits
operator|<
name|MachineDomTreeNode
operator|*
operator|>
block|{
specifier|static
name|NodeType
operator|*
name|getEntryNode
argument_list|(
argument|MachineDominatorTree *DT
argument_list|)
block|{
return|return
name|DT
operator|->
name|getRootNode
argument_list|()
return|;
block|}
end_expr_stmt

begin_endif
unit|};  }
endif|#
directive|endif
end_endif

end_unit

