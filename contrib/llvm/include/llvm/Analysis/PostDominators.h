begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=- llvm/Analysis/PostDominators.h - Post Dominator Calculation-*- C++ -*-===//
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
comment|// This file exposes interfaces to post dominance information.
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
name|LLVM_ANALYSIS_POSTDOMINATORS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_POSTDOMINATORS_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/Dominators.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// PostDominatorTree Class - Concrete subclass of DominatorTree that is used to
comment|/// compute the post-dominator tree.
comment|///
name|struct
name|PostDominatorTree
range|:
name|public
name|FunctionPass
block|{
specifier|static
name|char
name|ID
block|;
comment|// Pass identification, replacement for typeid
name|DominatorTreeBase
operator|<
name|BasicBlock
operator|>
operator|*
name|DT
block|;
name|PostDominatorTree
argument_list|()
operator|:
name|FunctionPass
argument_list|(
argument|ID
argument_list|)
block|{
name|initializePostDominatorTreePass
argument_list|(
operator|*
name|PassRegistry
operator|::
name|getPassRegistry
argument_list|()
argument_list|)
block|;
name|DT
operator|=
name|new
name|DominatorTreeBase
operator|<
name|BasicBlock
operator|>
operator|(
name|true
operator|)
block|;   }
operator|~
name|PostDominatorTree
argument_list|()
name|override
block|;
name|bool
name|runOnFunction
argument_list|(
argument|Function&F
argument_list|)
name|override
block|;
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
name|override
block|{
name|AU
operator|.
name|setPreservesAll
argument_list|()
block|;   }
specifier|inline
specifier|const
name|std
operator|::
name|vector
operator|<
name|BasicBlock
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
name|DomTreeNode
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
specifier|inline
name|DomTreeNode
operator|*
name|operator
index|[]
operator|(
name|BasicBlock
operator|*
name|BB
operator|)
specifier|const
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
specifier|inline
name|DomTreeNode
operator|*
name|getNode
argument_list|(
argument|BasicBlock *BB
argument_list|)
specifier|const
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
specifier|inline
name|bool
name|dominates
argument_list|(
argument|DomTreeNode* A
argument_list|,
argument|DomTreeNode* B
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
argument|const BasicBlock* A
argument_list|,
argument|const BasicBlock* B
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
name|properlyDominates
argument_list|(
argument|const DomTreeNode* A
argument_list|,
argument|DomTreeNode* B
argument_list|)
specifier|const
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
specifier|inline
name|bool
name|properlyDominates
argument_list|(
argument|BasicBlock* A
argument_list|,
argument|BasicBlock* B
argument_list|)
specifier|const
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
specifier|inline
name|BasicBlock
operator|*
name|findNearestCommonDominator
argument_list|(
argument|BasicBlock *A
argument_list|,
argument|BasicBlock *B
argument_list|)
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
specifier|inline
specifier|const
name|BasicBlock
operator|*
name|findNearestCommonDominator
argument_list|(
argument|const BasicBlock *A
argument_list|,
argument|const BasicBlock *B
argument_list|)
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
comment|/// Get all nodes post-dominated by R, including R itself.
name|void
name|getDescendants
argument_list|(
argument|BasicBlock *R
argument_list|,
argument|SmallVectorImpl<BasicBlock *>&Result
argument_list|)
specifier|const
block|{
name|DT
operator|->
name|getDescendants
argument_list|(
name|R
argument_list|,
name|Result
argument_list|)
block|;   }
name|void
name|releaseMemory
argument_list|()
name|override
block|{
name|DT
operator|->
name|releaseMemory
argument_list|()
block|;   }
name|void
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|const Module*
argument_list|)
specifier|const
name|override
block|; }
decl_stmt|;
name|FunctionPass
modifier|*
name|createPostDomTree
parameter_list|()
function_decl|;
name|template
operator|<
operator|>
expr|struct
name|GraphTraits
operator|<
name|PostDominatorTree
operator|*
operator|>
operator|:
name|public
name|GraphTraits
operator|<
name|DomTreeNode
operator|*
operator|>
block|{
specifier|static
name|NodeType
operator|*
name|getEntryNode
argument_list|(
argument|PostDominatorTree *DT
argument_list|)
block|{
return|return
name|DT
operator|->
name|getRootNode
argument_list|()
return|;
block|}
specifier|static
name|nodes_iterator
name|nodes_begin
argument_list|(
argument|PostDominatorTree *N
argument_list|)
block|{
if|if
condition|(
name|getEntryNode
argument_list|(
name|N
argument_list|)
condition|)
return|return
name|df_begin
argument_list|(
name|getEntryNode
argument_list|(
name|N
argument_list|)
argument_list|)
return|;
else|else
return|return
name|df_end
argument_list|(
name|getEntryNode
argument_list|(
name|N
argument_list|)
argument_list|)
return|;
block|}
specifier|static
name|nodes_iterator
name|nodes_end
argument_list|(
argument|PostDominatorTree *N
argument_list|)
block|{
return|return
name|df_end
argument_list|(
name|getEntryNode
argument_list|(
name|N
argument_list|)
argument_list|)
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

