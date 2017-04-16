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

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
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
name|DominatorTreeBase
operator|<
name|BasicBlock
operator|>
block|{
typedef|typedef
name|DominatorTreeBase
operator|<
name|BasicBlock
operator|>
name|Base
expr_stmt|;
name|PostDominatorTree
argument_list|()
operator|:
name|DominatorTreeBase
operator|<
name|BasicBlock
operator|>
operator|(
name|true
operator|)
block|{}
comment|/// Handle invalidation explicitly.
name|bool
name|invalidate
argument_list|(
name|Function
operator|&
name|F
argument_list|,
specifier|const
name|PreservedAnalyses
operator|&
name|PA
argument_list|,
name|FunctionAnalysisManager
operator|::
name|Invalidator
operator|&
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Analysis pass which computes a \c PostDominatorTree.
end_comment

begin_decl_stmt
name|class
name|PostDominatorTreeAnalysis
range|:
name|public
name|AnalysisInfoMixin
operator|<
name|PostDominatorTreeAnalysis
operator|>
block|{
name|friend
name|AnalysisInfoMixin
operator|<
name|PostDominatorTreeAnalysis
operator|>
block|;
specifier|static
name|AnalysisKey
name|Key
block|;
name|public
operator|:
comment|/// \brief Provide the result typedef for this analysis pass.
typedef|typedef
name|PostDominatorTree
name|Result
typedef|;
comment|/// \brief Run the analysis pass over a function and produce a post dominator
comment|///        tree.
name|PostDominatorTree
name|run
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|FunctionAnalysisManager
operator|&
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// \brief Printer pass for the \c PostDominatorTree.
end_comment

begin_decl_stmt
name|class
name|PostDominatorTreePrinterPass
range|:
name|public
name|PassInfoMixin
operator|<
name|PostDominatorTreePrinterPass
operator|>
block|{
name|raw_ostream
operator|&
name|OS
block|;
name|public
operator|:
name|explicit
name|PostDominatorTreePrinterPass
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
block|;
name|PreservedAnalyses
name|run
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|FunctionAnalysisManager
operator|&
name|AM
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|PostDominatorTreeWrapperPass
range|:
name|public
name|FunctionPass
block|{
specifier|static
name|char
name|ID
block|;
comment|// Pass identification, replacement for typeid
name|PostDominatorTree
name|DT
block|;
name|PostDominatorTreeWrapperPass
argument_list|()
operator|:
name|FunctionPass
argument_list|(
argument|ID
argument_list|)
block|{
name|initializePostDominatorTreeWrapperPassPass
argument_list|(
operator|*
name|PassRegistry
operator|::
name|getPassRegistry
argument_list|()
argument_list|)
block|;   }
name|PostDominatorTree
operator|&
name|getPostDomTree
argument_list|()
block|{
return|return
name|DT
return|;
block|}
specifier|const
name|PostDominatorTree
operator|&
name|getPostDomTree
argument_list|()
specifier|const
block|{
return|return
name|DT
return|;
block|}
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
name|void
name|releaseMemory
argument_list|()
name|override
block|{
name|DT
operator|.
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
end_decl_stmt

begin_function_decl
name|FunctionPass
modifier|*
name|createPostDomTree
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
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
name|NodeRef
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
end_expr_stmt

begin_function
specifier|static
name|nodes_iterator
name|nodes_end
parameter_list|(
name|PostDominatorTree
modifier|*
name|N
parameter_list|)
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
end_function

begin_comment
unit|};  }
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

