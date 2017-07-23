begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Analysis/DominanceFrontier.h - Dominator Frontiers --*- C++ -*-===//
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
comment|// This file defines the DominanceFrontier class, which calculate and holds the
end_comment

begin_comment
comment|// dominance frontier for a function.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This should be considered deprecated, don't add any more uses of this data
end_comment

begin_comment
comment|// structure.
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
name|LLVM_ANALYSIS_DOMINANCEFRONTIER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_DOMINANCEFRONTIER_H
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

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<set>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|//===----------------------------------------------------------------------===//
comment|/// DominanceFrontierBase - Common base class for computing forward and inverse
comment|/// dominance frontiers for a function.
comment|///
name|template
operator|<
name|class
name|BlockT
operator|,
name|bool
name|IsPostDom
operator|>
name|class
name|DominanceFrontierBase
block|{
name|public
operator|:
typedef|typedef
name|std
operator|::
name|set
operator|<
name|BlockT
operator|*
operator|>
name|DomSetType
expr_stmt|;
comment|// Dom set for a bb
typedef|typedef
name|std
operator|::
name|map
operator|<
name|BlockT
operator|*
operator|,
name|DomSetType
operator|>
name|DomSetMapType
expr_stmt|;
comment|// Dom set map
name|protected
label|:
typedef|typedef
name|GraphTraits
operator|<
name|BlockT
operator|*
operator|>
name|BlockTraits
expr_stmt|;
name|DomSetMapType
name|Frontiers
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|BlockT
operator|*
operator|>
name|Roots
expr_stmt|;
specifier|static
name|constexpr
name|bool
name|IsPostDominators
init|=
name|IsPostDom
decl_stmt|;
name|public
label|:
name|DominanceFrontierBase
argument_list|()
block|{}
comment|/// getRoots - Return the root blocks of the current CFG.  This may include
comment|/// multiple blocks if we are computing post dominators.  For forward
comment|/// dominators, this will always be a single block (the entry node).
comment|///
specifier|inline
specifier|const
name|std
operator|::
name|vector
operator|<
name|BlockT
operator|*
operator|>
operator|&
name|getRoots
argument_list|()
specifier|const
block|{
return|return
name|Roots
return|;
block|}
name|BlockT
operator|*
name|getRoot
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Roots
operator|.
name|size
argument_list|()
operator|==
literal|1
operator|&&
literal|"Should always have entry node!"
argument_list|)
block|;
return|return
name|Roots
index|[
literal|0
index|]
return|;
block|}
comment|/// isPostDominator - Returns true if analysis based of postdoms
comment|///
name|bool
name|isPostDominator
argument_list|()
specifier|const
block|{
return|return
name|IsPostDominators
return|;
block|}
name|void
name|releaseMemory
parameter_list|()
block|{
name|Frontiers
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
comment|// Accessor interface:
typedef|typedef
name|typename
name|DomSetMapType
operator|::
name|iterator
name|iterator
expr_stmt|;
typedef|typedef
name|typename
name|DomSetMapType
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|Frontiers
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
name|Frontiers
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
name|Frontiers
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
name|Frontiers
operator|.
name|end
argument_list|()
return|;
block|}
name|iterator
name|find
parameter_list|(
name|BlockT
modifier|*
name|B
parameter_list|)
block|{
return|return
name|Frontiers
operator|.
name|find
argument_list|(
name|B
argument_list|)
return|;
block|}
name|const_iterator
name|find
argument_list|(
name|BlockT
operator|*
name|B
argument_list|)
decl|const
block|{
return|return
name|Frontiers
operator|.
name|find
argument_list|(
name|B
argument_list|)
return|;
block|}
name|iterator
name|addBasicBlock
parameter_list|(
name|BlockT
modifier|*
name|BB
parameter_list|,
specifier|const
name|DomSetType
modifier|&
name|frontier
parameter_list|)
block|{
name|assert
argument_list|(
name|find
argument_list|(
name|BB
argument_list|)
operator|==
name|end
argument_list|()
operator|&&
literal|"Block already in DominanceFrontier!"
argument_list|)
expr_stmt|;
return|return
name|Frontiers
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|BB
argument_list|,
name|frontier
argument_list|)
argument_list|)
operator|.
name|first
return|;
block|}
comment|/// removeBlock - Remove basic block BB's frontier.
name|void
name|removeBlock
parameter_list|(
name|BlockT
modifier|*
name|BB
parameter_list|)
function_decl|;
name|void
name|addToFrontier
parameter_list|(
name|iterator
name|I
parameter_list|,
name|BlockT
modifier|*
name|Node
parameter_list|)
function_decl|;
name|void
name|removeFromFrontier
parameter_list|(
name|iterator
name|I
parameter_list|,
name|BlockT
modifier|*
name|Node
parameter_list|)
function_decl|;
comment|/// compareDomSet - Return false if two domsets match. Otherwise
comment|/// return true;
name|bool
name|compareDomSet
argument_list|(
name|DomSetType
operator|&
name|DS1
argument_list|,
specifier|const
name|DomSetType
operator|&
name|DS2
argument_list|)
decl|const
decl_stmt|;
comment|/// compare - Return true if the other dominance frontier base matches
comment|/// this dominance frontier base. Otherwise return false.
name|bool
name|compare
argument_list|(
name|DominanceFrontierBase
operator|&
name|Other
argument_list|)
decl|const
decl_stmt|;
comment|/// print - Convert to human readable form
comment|///
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
comment|/// dump - Dump the dominance frontier to dbgs().
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NDEBUG
argument_list|)
operator|||
name|defined
argument_list|(
name|LLVM_ENABLE_DUMP
argument_list|)
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//===-------------------------------------
end_comment

begin_comment
comment|/// DominanceFrontier Class - Concrete subclass of DominanceFrontierBase that is
end_comment

begin_comment
comment|/// used to compute a forward dominator frontiers.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|BlockT
operator|>
name|class
name|ForwardDominanceFrontierBase
operator|:
name|public
name|DominanceFrontierBase
operator|<
name|BlockT
operator|,
name|false
operator|>
block|{
name|private
operator|:
typedef|typedef
name|GraphTraits
operator|<
name|BlockT
operator|*
operator|>
name|BlockTraits
expr_stmt|;
name|public
operator|:
end_expr_stmt

begin_typedef
typedef|typedef
name|DomTreeBase
operator|<
name|BlockT
operator|>
name|DomTreeT
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|DomTreeNodeBase
operator|<
name|BlockT
operator|>
name|DomTreeNodeT
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|DominanceFrontierBase
operator|<
name|BlockT
operator|,
name|false
operator|>
operator|::
name|DomSetType
name|DomSetType
expr_stmt|;
end_typedef

begin_function
name|void
name|analyze
parameter_list|(
name|DomTreeT
modifier|&
name|DT
parameter_list|)
block|{
name|this
operator|->
name|Roots
operator|=
name|DT
operator|.
name|getRoots
argument_list|()
expr_stmt|;
name|assert
argument_list|(
name|this
operator|->
name|Roots
operator|.
name|size
argument_list|()
operator|==
literal|1
operator|&&
literal|"Only one entry block for forward domfronts!"
argument_list|)
expr_stmt|;
name|calculate
argument_list|(
name|DT
argument_list|,
name|DT
index|[
name|this
operator|->
name|Roots
index|[
literal|0
index|]
index|]
argument_list|)
expr_stmt|;
block|}
end_function

begin_function_decl
specifier|const
name|DomSetType
modifier|&
name|calculate
parameter_list|(
specifier|const
name|DomTreeT
modifier|&
name|DT
parameter_list|,
specifier|const
name|DomTreeNodeT
modifier|*
name|Node
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
unit|};
name|class
name|DominanceFrontier
range|:
name|public
name|ForwardDominanceFrontierBase
operator|<
name|BasicBlock
operator|>
block|{
name|public
operator|:
typedef|typedef
name|DomTreeBase
operator|<
name|BasicBlock
operator|>
name|DomTreeT
expr_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|DomTreeNodeBase
operator|<
name|BasicBlock
operator|>
name|DomTreeNodeT
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|DominanceFrontierBase
operator|<
name|BasicBlock
operator|,
name|false
operator|>
operator|::
name|DomSetType
name|DomSetType
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|DominanceFrontierBase
operator|<
name|BasicBlock
operator|,
name|false
operator|>
operator|::
name|iterator
name|iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|DominanceFrontierBase
operator|<
name|BasicBlock
operator|,
name|false
operator|>
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
end_typedef

begin_comment
comment|/// Handle invalidation explicitly.
end_comment

begin_decl_stmt
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
end_decl_stmt

begin_decl_stmt
unit|};
name|class
name|DominanceFrontierWrapperPass
range|:
name|public
name|FunctionPass
block|{
name|DominanceFrontier
name|DF
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
comment|// Pass ID, replacement for typeid
name|DominanceFrontierWrapperPass
argument_list|()
block|;
name|DominanceFrontier
operator|&
name|getDominanceFrontier
argument_list|()
block|{
return|return
name|DF
return|;
block|}
specifier|const
name|DominanceFrontier
operator|&
name|getDominanceFrontier
argument_list|()
specifier|const
block|{
return|return
name|DF
return|;
block|}
name|void
name|releaseMemory
argument_list|()
name|override
block|;
name|bool
name|runOnFunction
argument_list|(
argument|Function&
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
block|;
name|void
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|const Module * = nullptr
argument_list|)
specifier|const
name|override
block|;
name|void
name|dump
argument_list|()
specifier|const
block|; }
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern template class DominanceFrontierBase<BasicBlock
operator|,
extern|false>;
end_extern

begin_extern
extern|extern template class DominanceFrontierBase<BasicBlock
operator|,
extern|true>;
end_extern

begin_extern
extern|extern template class ForwardDominanceFrontierBase<BasicBlock>;
end_extern

begin_comment
comment|/// \brief Analysis pass which computes a \c DominanceFrontier.
end_comment

begin_decl_stmt
name|class
name|DominanceFrontierAnalysis
range|:
name|public
name|AnalysisInfoMixin
operator|<
name|DominanceFrontierAnalysis
operator|>
block|{
name|friend
name|AnalysisInfoMixin
operator|<
name|DominanceFrontierAnalysis
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
name|DominanceFrontier
name|Result
typedef|;
comment|/// \brief Run the analysis pass over a function and produce a dominator tree.
name|DominanceFrontier
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
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// \brief Printer pass for the \c DominanceFrontier.
end_comment

begin_decl_stmt
name|class
name|DominanceFrontierPrinterPass
range|:
name|public
name|PassInfoMixin
operator|<
name|DominanceFrontierPrinterPass
operator|>
block|{
name|raw_ostream
operator|&
name|OS
block|;
name|public
operator|:
name|explicit
name|DominanceFrontierPrinterPass
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

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

