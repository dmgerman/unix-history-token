begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- Dominators.h - Implementation of dominators tree for Clang CFG C++ -*-==//
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
comment|// This file implements the dominators tree functionality for Clang CFGs.
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
name|LLVM_CLANG_ANALYSIS_ANALYSES_DOMINATORS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_ANALYSIS_ANALYSES_DOMINATORS_H
end_define

begin_include
include|#
directive|include
file|"clang/Analysis/AnalysisContext.h"
end_include

begin_include
include|#
directive|include
file|"clang/Analysis/CFG.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/GraphTraits.h"
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

begin_comment
comment|// FIXME: There is no good reason for the domtree to require a print method
end_comment

begin_comment
comment|// which accepts an LLVM Module, so remove this (and the method's argument that
end_comment

begin_comment
comment|// needs it) when that is fixed.
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Module
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|CFGBlock
decl_stmt|;
typedef|typedef
name|llvm
operator|::
name|DomTreeNodeBase
operator|<
name|CFGBlock
operator|>
name|DomTreeNode
expr_stmt|;
comment|/// \brief Concrete subclass of DominatorTreeBase for Clang
comment|/// This class implements the dominators tree functionality given a Clang CFG.
comment|///
name|class
name|DominatorTree
range|:
name|public
name|ManagedAnalysis
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
name|llvm
operator|::
name|DomTreeBase
operator|<
name|CFGBlock
operator|>
operator|*
name|DT
block|;
name|DominatorTree
argument_list|()
block|{
name|DT
operator|=
name|new
name|llvm
operator|::
name|DomTreeBase
operator|<
name|CFGBlock
operator|>
operator|(
operator|)
block|;   }
operator|~
name|DominatorTree
argument_list|()
name|override
block|{
name|delete
name|DT
block|; }
name|llvm
operator|::
name|DomTreeBase
operator|<
name|CFGBlock
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
comment|/// \brief This method returns the root CFGBlock of the dominators tree.
comment|///
specifier|inline
name|CFGBlock
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
comment|/// \brief This method returns the root DomTreeNode, which is the wrapper
comment|/// for CFGBlock.
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
comment|/// \brief This method compares two dominator trees.
comment|/// The method returns false if the other dominator tree matches this
comment|/// dominator tree, otherwise returns true.
comment|///
specifier|inline
name|bool
name|compare
argument_list|(
argument|DominatorTree&Other
argument_list|)
specifier|const
block|{
name|DomTreeNode
operator|*
name|R
operator|=
name|getRootNode
argument_list|()
block|;
name|DomTreeNode
operator|*
name|OtherR
operator|=
name|Other
operator|.
name|getRootNode
argument_list|()
block|;
if|if
condition|(
operator|!
name|R
operator|||
operator|!
name|OtherR
operator|||
name|R
operator|->
name|getBlock
argument_list|()
operator|!=
name|OtherR
operator|->
name|getBlock
argument_list|()
condition|)
return|return
name|true
return|;
if|if
condition|(
name|DT
operator|->
name|compare
argument_list|(
name|Other
operator|.
name|getBase
argument_list|()
argument_list|)
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
comment|/// \brief This method builds the dominator tree for a given CFG
end_comment

begin_comment
comment|/// The CFG information is passed via AnalysisDeclContext
end_comment

begin_comment
comment|///
end_comment

begin_function
name|void
name|buildDominatorTree
parameter_list|(
name|AnalysisDeclContext
modifier|&
name|AC
parameter_list|)
block|{
name|cfg
operator|=
name|AC
operator|.
name|getCFG
argument_list|()
expr_stmt|;
name|DT
operator|->
name|recalculate
argument_list|(
operator|*
name|cfg
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief This method dumps immediate dominators for each block,
end_comment

begin_comment
comment|/// mainly used for debug purposes.
end_comment

begin_comment
comment|///
end_comment

begin_function
name|void
name|dump
parameter_list|()
block|{
name|llvm
operator|::
name|errs
argument_list|()
operator|<<
literal|"Immediate dominance tree (Node#,IDom#):\n"
expr_stmt|;
for|for
control|(
name|CFG
operator|::
name|const_iterator
name|I
operator|=
name|cfg
operator|->
name|begin
argument_list|()
operator|,
name|E
operator|=
name|cfg
operator|->
name|end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
block|{
if|if
condition|(
name|DT
operator|->
name|getNode
argument_list|(
operator|*
name|I
argument_list|)
operator|->
name|getIDom
argument_list|()
condition|)
name|llvm
operator|::
name|errs
argument_list|()
operator|<<
literal|"("
operator|<<
operator|(
operator|*
name|I
operator|)
operator|->
name|getBlockID
argument_list|()
operator|<<
literal|","
operator|<<
name|DT
operator|->
name|getNode
argument_list|(
operator|*
name|I
argument_list|)
operator|->
name|getIDom
argument_list|()
operator|->
name|getBlock
argument_list|()
operator|->
name|getBlockID
argument_list|()
operator|<<
literal|")\n"
expr_stmt|;
else|else
name|llvm
operator|::
name|errs
argument_list|()
operator|<<
literal|"("
operator|<<
operator|(
operator|*
name|I
operator|)
operator|->
name|getBlockID
argument_list|()
operator|<<
literal|","
operator|<<
operator|(
operator|*
name|I
operator|)
operator|->
name|getBlockID
argument_list|()
operator|<<
literal|")\n"
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/// \brief This method tests if one CFGBlock dominates the other.
end_comment

begin_comment
comment|/// The method return true if A dominates B, false otherwise.
end_comment

begin_comment
comment|/// Note a block always dominates itself.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
specifier|inline
name|bool
name|dominates
argument_list|(
specifier|const
name|CFGBlock
operator|*
name|A
argument_list|,
specifier|const
name|CFGBlock
operator|*
name|B
argument_list|)
decl|const
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
end_decl_stmt

begin_comment
comment|/// \brief This method tests if one CFGBlock properly dominates the other.
end_comment

begin_comment
comment|/// The method return true if A properly dominates B, false otherwise.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|bool
name|properlyDominates
argument_list|(
specifier|const
name|CFGBlock
operator|*
name|A
argument_list|,
specifier|const
name|CFGBlock
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
comment|/// \brief This method finds the nearest common dominator CFG block
end_comment

begin_comment
comment|/// for CFG block A and B. If there is no such block then return NULL.
end_comment

begin_comment
comment|///
end_comment

begin_function
specifier|inline
name|CFGBlock
modifier|*
name|findNearestCommonDominator
parameter_list|(
name|CFGBlock
modifier|*
name|A
parameter_list|,
name|CFGBlock
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

begin_function
specifier|inline
specifier|const
name|CFGBlock
modifier|*
name|findNearestCommonDominator
parameter_list|(
specifier|const
name|CFGBlock
modifier|*
name|A
parameter_list|,
specifier|const
name|CFGBlock
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

begin_comment
comment|/// \brief This method is used to update the dominator
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
name|CFGBlock
modifier|*
name|N
parameter_list|,
name|CFGBlock
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
comment|/// \brief This method tests if the given CFGBlock can be reachable from root.
end_comment

begin_comment
comment|/// Returns true if reachable, false otherwise.
end_comment

begin_comment
comment|///
end_comment

begin_function
name|bool
name|isReachableFromEntry
parameter_list|(
specifier|const
name|CFGBlock
modifier|*
name|A
parameter_list|)
block|{
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

begin_comment
comment|/// \brief This method releases the memory held by the dominator tree.
end_comment

begin_comment
comment|///
end_comment

begin_function
name|virtual
name|void
name|releaseMemory
parameter_list|()
block|{
name|DT
operator|->
name|releaseMemory
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief This method converts the dominator tree to human readable form.
end_comment

begin_comment
comment|///
end_comment

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
name|llvm
operator|::
name|Module
operator|*
name|M
operator|=
name|nullptr
argument_list|)
decl|const
block|{
name|DT
operator|->
name|print
argument_list|(
name|OS
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|CFG
modifier|*
name|cfg
decl_stmt|;
end_decl_stmt

begin_comment
unit|};  }
comment|// end namespace clang
end_comment

begin_comment
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

begin_macro
unit|namespace
name|llvm
end_macro

begin_block
block|{
name|template
operator|<
operator|>
expr|struct
name|GraphTraits
operator|<
operator|::
name|clang
operator|::
name|DomTreeNode
operator|*
operator|>
block|{
typedef|typedef
operator|::
name|clang
operator|::
name|DomTreeNode
operator|*
name|NodeRef
expr_stmt|;
typedef|typedef
operator|::
name|clang
operator|::
name|DomTreeNode
operator|::
name|iterator
name|ChildIteratorType
expr_stmt|;
specifier|static
name|NodeRef
name|getEntryNode
parameter_list|(
name|NodeRef
name|N
parameter_list|)
block|{
return|return
name|N
return|;
block|}
specifier|static
name|ChildIteratorType
name|child_begin
parameter_list|(
name|NodeRef
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
specifier|static
name|ChildIteratorType
name|child_end
parameter_list|(
name|NodeRef
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
typedef|typedef
name|llvm
operator|::
name|pointer_iterator
operator|<
name|df_iterator
operator|<
operator|::
name|clang
operator|::
name|DomTreeNode
operator|*
operator|>>
name|nodes_iterator
expr_stmt|;
specifier|static
name|nodes_iterator
name|nodes_begin
argument_list|(
operator|::
name|clang
operator|::
name|DomTreeNode
operator|*
name|N
argument_list|)
block|{
return|return
name|nodes_iterator
argument_list|(
name|df_begin
argument_list|(
name|getEntryNode
argument_list|(
name|N
argument_list|)
argument_list|)
argument_list|)
return|;
block|}
specifier|static
name|nodes_iterator
name|nodes_end
argument_list|(
operator|::
name|clang
operator|::
name|DomTreeNode
operator|*
name|N
argument_list|)
block|{
return|return
name|nodes_iterator
argument_list|(
name|df_end
argument_list|(
name|getEntryNode
argument_list|(
name|N
argument_list|)
argument_list|)
argument_list|)
return|;
block|}
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|GraphTraits
operator|<
operator|::
name|clang
operator|::
name|DominatorTree
operator|*
operator|>
operator|:
name|public
name|GraphTraits
operator|<
operator|::
name|clang
operator|::
name|DomTreeNode
operator|*
operator|>
block|{
specifier|static
name|NodeRef
name|getEntryNode
argument_list|(
argument|::clang::DominatorTree *DT
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
argument|::clang::DominatorTree *N
argument_list|)
block|{
return|return
name|nodes_iterator
argument_list|(
name|df_begin
argument_list|(
name|getEntryNode
argument_list|(
name|N
argument_list|)
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
specifier|static
name|nodes_iterator
name|nodes_end
argument_list|(
operator|::
name|clang
operator|::
name|DominatorTree
operator|*
name|N
argument_list|)
block|{
return|return
name|nodes_iterator
argument_list|(
name|df_end
argument_list|(
name|getEntryNode
argument_list|(
name|N
argument_list|)
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
unit|}; }
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

