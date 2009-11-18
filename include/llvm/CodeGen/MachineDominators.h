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
file|"llvm/Analysis/Dominators.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/DominatorInternals.h"
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
name|public
operator|:
specifier|static
name|char
name|ID
block|;
comment|// Pass ID, replacement for typeid
name|DominatorTreeBase
operator|<
name|MachineBasicBlock
operator|>
operator|*
name|DT
block|;
name|MachineDominatorTree
argument_list|()
block|;
operator|~
name|MachineDominatorTree
argument_list|()
block|;
name|DominatorTreeBase
operator|<
name|MachineBasicBlock
operator|>
operator|&
name|getBase
argument_list|()
block|{
return|return
operator|*
name|DT
return|;
block|}
name|virtual
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
block|;
comment|/// getRoots -  Return the root blocks of the current CFG.  This may include
comment|/// multiple blocks if we are computing post dominators.  For forward
comment|/// dominators, this will always be a single block (the entry node).
comment|///
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
return|return
name|DT
operator|->
name|getRoots
argument_list|()
return|;
block|}
specifier|inline
name|MachineBasicBlock
operator|*
name|getRoot
argument_list|()
specifier|const
block|{
return|return
name|DT
operator|->
name|getRoot
argument_list|()
return|;
block|}
specifier|inline
name|MachineDomTreeNode
operator|*
name|getRootNode
argument_list|()
specifier|const
block|{
return|return
name|DT
operator|->
name|getRootNode
argument_list|()
return|;
block|}
name|virtual
name|bool
name|runOnMachineFunction
argument_list|(
name|MachineFunction
operator|&
name|F
argument_list|)
block|;
specifier|inline
name|bool
name|dominates
argument_list|(
argument|MachineDomTreeNode* A
argument_list|,
argument|MachineDomTreeNode* B
argument_list|)
specifier|const
block|{
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
specifier|inline
name|bool
name|dominates
argument_list|(
argument|MachineBasicBlock* A
argument_list|,
argument|MachineBasicBlock* B
argument_list|)
specifier|const
block|{
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
comment|// dominates - Return true if A dominates B. This performs the
comment|// special checks necessary if A and B are in the same basic block.
name|bool
name|dominates
argument_list|(
argument|MachineInstr *A
argument_list|,
argument|MachineInstr *B
argument_list|)
specifier|const
block|{
name|MachineBasicBlock
operator|*
name|BBA
operator|=
name|A
operator|->
name|getParent
argument_list|()
block|,
operator|*
name|BBB
operator|=
name|B
operator|->
name|getParent
argument_list|()
block|;
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
name|iterator
name|I
operator|=
name|BBA
operator|->
name|begin
argument_list|()
block|;
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
name|MachineDomTreeNode
operator|*
name|B
argument_list|)
decl|const
block|{
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
name|MachineBasicBlock
operator|*
name|A
argument_list|,
name|MachineBasicBlock
operator|*
name|B
argument_list|)
decl|const
block|{
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
comment|/// domiante any other blocks. Removes node from its immediate dominator's
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
name|DT
operator|->
name|splitBlock
argument_list|(
name|NewBB
argument_list|)
expr_stmt|;
block|}
end_function

begin_function_decl
name|virtual
name|void
name|releaseMemory
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|virtual
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
decl_stmt|;
end_decl_stmt

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

