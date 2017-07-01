begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Dominators.h - Dominator Info Calculation ----------------*- C++ -*-===//
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
comment|// This file defines the DominatorTree class, which provides fast and efficient
end_comment

begin_comment
comment|// dominance queries.
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
name|LLVM_IR_DOMINATORS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_DOMINATORS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMapInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DepthFirstIterator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/GraphTraits.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Hashing.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/BasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/CFG.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/GenericDomTree.h"
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Function
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
extern|extern template class DomTreeNodeBase<BasicBlock>;
extern|extern template class DominatorTreeBase<BasicBlock>;
name|namespace
name|DomTreeBuilder
block|{
extern|extern template void Calculate<Function
operator|,
extern|BasicBlock *>(     DominatorTreeBaseByGraphTraits<GraphTraits<BasicBlock *>>&DT
operator|,
extern|Function&F
block|)
decl_stmt|;
extern|extern template void Calculate<Function
operator|,
extern|Inverse<BasicBlock *>>(     DominatorTreeBaseByGraphTraits<GraphTraits<Inverse<BasicBlock *>>>&DT
operator|,
extern|Function&F
block|)
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern template bool Verify<BasicBlock *>(     const DominatorTreeBaseByGraphTraits<GraphTraits<BasicBlock *>>&DT
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern template bool Verify<Inverse<BasicBlock *>>(     const DominatorTreeBaseByGraphTraits<GraphTraits<Inverse<BasicBlock *>>>&DT
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace DomTreeBuilder
end_comment

begin_expr_stmt
unit|using
name|DomTreeNode
operator|=
name|DomTreeNodeBase
operator|<
name|BasicBlock
operator|>
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|class
name|BasicBlockEdge
block|{
specifier|const
name|BasicBlock
modifier|*
name|Start
decl_stmt|;
specifier|const
name|BasicBlock
modifier|*
name|End
decl_stmt|;
name|public
label|:
name|BasicBlockEdge
argument_list|(
specifier|const
name|BasicBlock
operator|*
name|Start_
argument_list|,
specifier|const
name|BasicBlock
operator|*
name|End_
argument_list|)
operator|:
name|Start
argument_list|(
name|Start_
argument_list|)
operator|,
name|End
argument_list|(
argument|End_
argument_list|)
block|{}
name|BasicBlockEdge
argument_list|(
specifier|const
name|std
operator|::
name|pair
operator|<
name|BasicBlock
operator|*
argument_list|,
name|BasicBlock
operator|*
operator|>
operator|&
name|Pair
argument_list|)
operator|:
name|Start
argument_list|(
name|Pair
operator|.
name|first
argument_list|)
operator|,
name|End
argument_list|(
argument|Pair.second
argument_list|)
block|{}
name|BasicBlockEdge
argument_list|(
specifier|const
name|std
operator|::
name|pair
operator|<
specifier|const
name|BasicBlock
operator|*
argument_list|,
specifier|const
name|BasicBlock
operator|*
operator|>
operator|&
name|Pair
argument_list|)
operator|:
name|Start
argument_list|(
name|Pair
operator|.
name|first
argument_list|)
operator|,
name|End
argument_list|(
argument|Pair.second
argument_list|)
block|{}
specifier|const
name|BasicBlock
operator|*
name|getStart
argument_list|()
specifier|const
block|{
return|return
name|Start
return|;
block|}
specifier|const
name|BasicBlock
operator|*
name|getEnd
argument_list|()
specifier|const
block|{
return|return
name|End
return|;
block|}
comment|/// Check if this is the only edge between Start and End.
name|bool
name|isSingleEdge
argument_list|()
specifier|const
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|DenseMapInfo
operator|<
name|BasicBlockEdge
operator|>
block|{
name|using
name|BBInfo
operator|=
name|DenseMapInfo
operator|<
specifier|const
name|BasicBlock
operator|*
operator|>
block|;
specifier|static
name|unsigned
name|getHashValue
argument_list|(
specifier|const
name|BasicBlockEdge
operator|*
name|V
argument_list|)
block|;
specifier|static
specifier|inline
name|BasicBlockEdge
name|getEmptyKey
argument_list|()
block|{
return|return
name|BasicBlockEdge
argument_list|(
name|BBInfo
operator|::
name|getEmptyKey
argument_list|()
argument_list|,
name|BBInfo
operator|::
name|getEmptyKey
argument_list|()
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|BasicBlockEdge
name|getTombstoneKey
argument_list|()
block|{
return|return
name|BasicBlockEdge
argument_list|(
name|BBInfo
operator|::
name|getTombstoneKey
argument_list|()
argument_list|,
name|BBInfo
operator|::
name|getTombstoneKey
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|unsigned
name|getHashValue
parameter_list|(
specifier|const
name|BasicBlockEdge
modifier|&
name|Edge
parameter_list|)
block|{
return|return
name|hash_combine
argument_list|(
name|BBInfo
operator|::
name|getHashValue
argument_list|(
name|Edge
operator|.
name|getStart
argument_list|()
argument_list|)
argument_list|,
name|BBInfo
operator|::
name|getHashValue
argument_list|(
name|Edge
operator|.
name|getEnd
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|isEqual
parameter_list|(
specifier|const
name|BasicBlockEdge
modifier|&
name|LHS
parameter_list|,
specifier|const
name|BasicBlockEdge
modifier|&
name|RHS
parameter_list|)
block|{
return|return
name|BBInfo
operator|::
name|isEqual
argument_list|(
name|LHS
operator|.
name|getStart
argument_list|()
argument_list|,
name|RHS
operator|.
name|getStart
argument_list|()
argument_list|)
operator|&&
name|BBInfo
operator|::
name|isEqual
argument_list|(
name|LHS
operator|.
name|getEnd
argument_list|()
argument_list|,
name|RHS
operator|.
name|getEnd
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_comment
unit|};
comment|/// \brief Concrete subclass of DominatorTreeBase that is used to compute a
end_comment

begin_comment
comment|/// normal dominator tree.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Definition: A block is said to be forward statically reachable if there is
end_comment

begin_comment
comment|/// a path from the entry of the function to the block.  A statically reachable
end_comment

begin_comment
comment|/// block may become statically unreachable during optimization.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// A forward unreachable block may appear in the dominator tree, or it may
end_comment

begin_comment
comment|/// not.  If it does, dominance queries will return results as if all reachable
end_comment

begin_comment
comment|/// blocks dominate it.  When asking for a Node corresponding to a potentially
end_comment

begin_comment
comment|/// unreachable block, calling code must handle the case where the block was
end_comment

begin_comment
comment|/// unreachable and the result of getNode() is nullptr.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Generally, a block known to be unreachable when the dominator tree is
end_comment

begin_comment
comment|/// constructed will not be in the tree.  One which becomes unreachable after
end_comment

begin_comment
comment|/// the dominator tree is initially constructed may still exist in the tree,
end_comment

begin_comment
comment|/// even if the tree is properly updated. Calling code should not rely on the
end_comment

begin_comment
comment|/// preceding statements; this is stated only to assist human understanding.
end_comment

begin_decl_stmt
name|class
name|DominatorTree
range|:
name|public
name|DominatorTreeBase
operator|<
name|BasicBlock
operator|>
block|{
name|public
operator|:
name|using
name|Base
operator|=
name|DominatorTreeBase
operator|<
name|BasicBlock
operator|>
block|;
name|DominatorTree
argument_list|()
operator|:
name|DominatorTreeBase
operator|<
name|BasicBlock
operator|>
operator|(
name|false
operator|)
block|{}
name|explicit
name|DominatorTree
argument_list|(
name|Function
operator|&
name|F
argument_list|)
operator|:
name|DominatorTreeBase
operator|<
name|BasicBlock
operator|>
operator|(
name|false
operator|)
block|{
name|recalculate
argument_list|(
name|F
argument_list|)
block|;   }
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
block|;
comment|/// \brief Returns *false* if the other dominator tree matches this dominator
comment|/// tree.
specifier|inline
name|bool
name|compare
argument_list|(
argument|const DominatorTree&Other
argument_list|)
specifier|const
block|{
specifier|const
name|DomTreeNode
operator|*
name|R
operator|=
name|getRootNode
argument_list|()
block|;
specifier|const
name|DomTreeNode
operator|*
name|OtherR
operator|=
name|Other
operator|.
name|getRootNode
argument_list|()
block|;
return|return
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
operator|||
name|Base
operator|::
name|compare
argument_list|(
name|Other
argument_list|)
return|;
block|}
comment|// Ensure base-class overloads are visible.
name|using
name|Base
operator|::
name|dominates
block|;
comment|/// \brief Return true if Def dominates a use in User.
comment|///
comment|/// This performs the special checks necessary if Def and User are in the same
comment|/// basic block. Note that Def doesn't dominate a use in Def itself!
name|bool
name|dominates
argument_list|(
argument|const Instruction *Def
argument_list|,
argument|const Use&U
argument_list|)
specifier|const
block|;
name|bool
name|dominates
argument_list|(
argument|const Instruction *Def
argument_list|,
argument|const Instruction *User
argument_list|)
specifier|const
block|;
name|bool
name|dominates
argument_list|(
argument|const Instruction *Def
argument_list|,
argument|const BasicBlock *BB
argument_list|)
specifier|const
block|;
comment|/// Return true if an edge dominates a use.
comment|///
comment|/// If BBE is not a unique edge between start and end of the edge, it can
comment|/// never dominate the use.
name|bool
name|dominates
argument_list|(
argument|const BasicBlockEdge&BBE
argument_list|,
argument|const Use&U
argument_list|)
specifier|const
block|;
name|bool
name|dominates
argument_list|(
argument|const BasicBlockEdge&BBE
argument_list|,
argument|const BasicBlock *BB
argument_list|)
specifier|const
block|;
comment|// Ensure base class overloads are visible.
name|using
name|Base
operator|::
name|isReachableFromEntry
block|;
comment|/// \brief Provide an overload for a Use.
name|bool
name|isReachableFromEntry
argument_list|(
argument|const Use&U
argument_list|)
specifier|const
block|;
comment|/// \brief Verify the correctness of the domtree by re-computing it.
comment|///
comment|/// This should only be used for debugging as it aborts the program if the
comment|/// verification fails.
name|void
name|verifyDomTree
argument_list|()
specifier|const
block|;
comment|// Pop up a GraphViz/gv window with the Dominator Tree rendered using `dot`.
name|void
name|viewGraph
argument_list|(
specifier|const
name|Twine
operator|&
name|Name
argument_list|,
specifier|const
name|Twine
operator|&
name|Title
argument_list|)
block|;
name|void
name|viewGraph
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|//===-------------------------------------
end_comment

begin_comment
comment|// DominatorTree GraphTraits specializations so the DominatorTree can be
end_comment

begin_comment
comment|// iterable by generic graph iterators.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|Node
operator|,
name|class
name|ChildIterator
operator|>
expr|struct
name|DomTreeGraphTraitsBase
block|{
name|using
name|NodeRef
operator|=
name|Node
operator|*
block|;
name|using
name|ChildIteratorType
operator|=
name|ChildIterator
block|;
name|using
name|nodes_iterator
operator|=
name|df_iterator
operator|<
name|Node
operator|*
block|,
name|df_iterator_default_set
operator|<
name|Node
operator|*
operator|>>
block|;
specifier|static
name|NodeRef
name|getEntryNode
argument_list|(
argument|NodeRef N
argument_list|)
block|{
return|return
name|N
return|;
block|}
specifier|static
name|ChildIteratorType
name|child_begin
argument_list|(
argument|NodeRef N
argument_list|)
block|{
return|return
name|N
operator|->
name|begin
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
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
end_function

begin_function
specifier|static
name|nodes_iterator
name|nodes_begin
parameter_list|(
name|NodeRef
name|N
parameter_list|)
block|{
return|return
name|df_begin
argument_list|(
name|getEntryNode
argument_list|(
name|N
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|nodes_iterator
name|nodes_end
parameter_list|(
name|NodeRef
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

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|GraphTraits
operator|<
name|DomTreeNode
operator|*
operator|>
operator|:
name|public
name|DomTreeGraphTraitsBase
operator|<
name|DomTreeNode
operator|,
name|DomTreeNode
operator|::
name|iterator
operator|>
block|{}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|GraphTraits
operator|<
specifier|const
name|DomTreeNode
operator|*
operator|>
operator|:
name|public
name|DomTreeGraphTraitsBase
operator|<
specifier|const
name|DomTreeNode
operator|,
name|DomTreeNode
operator|::
name|const_iterator
operator|>
block|{}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|GraphTraits
operator|<
name|DominatorTree
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
argument|DominatorTree *DT
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
argument|DominatorTree *N
argument_list|)
block|{
return|return
name|df_begin
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
name|DominatorTree
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
unit|};
comment|/// \brief Analysis pass which computes a \c DominatorTree.
end_comment

begin_decl_stmt
name|class
name|DominatorTreeAnalysis
range|:
name|public
name|AnalysisInfoMixin
operator|<
name|DominatorTreeAnalysis
operator|>
block|{
name|friend
name|AnalysisInfoMixin
operator|<
name|DominatorTreeAnalysis
operator|>
block|;
specifier|static
name|AnalysisKey
name|Key
block|;
name|public
operator|:
comment|/// \brief Provide the result typedef for this analysis pass.
name|using
name|Result
operator|=
name|DominatorTree
block|;
comment|/// \brief Run the analysis pass over a function and produce a dominator tree.
name|DominatorTree
name|run
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|FunctionAnalysisManager
operator|&
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Printer pass for the \c DominatorTree.
end_comment

begin_decl_stmt
name|class
name|DominatorTreePrinterPass
range|:
name|public
name|PassInfoMixin
operator|<
name|DominatorTreePrinterPass
operator|>
block|{
name|raw_ostream
operator|&
name|OS
block|;
name|public
operator|:
name|explicit
name|DominatorTreePrinterPass
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
comment|/// \brief Verifier pass for the \c DominatorTree.
end_comment

begin_decl_stmt
name|struct
name|DominatorTreeVerifierPass
range|:
name|PassInfoMixin
operator|<
name|DominatorTreeVerifierPass
operator|>
block|{
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
comment|/// \brief Legacy analysis pass which computes a \c DominatorTree.
end_comment

begin_decl_stmt
name|class
name|DominatorTreeWrapperPass
range|:
name|public
name|FunctionPass
block|{
name|DominatorTree
name|DT
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|DominatorTreeWrapperPass
argument_list|()
operator|:
name|FunctionPass
argument_list|(
argument|ID
argument_list|)
block|{
name|initializeDominatorTreeWrapperPassPass
argument_list|(
operator|*
name|PassRegistry
operator|::
name|getPassRegistry
argument_list|()
argument_list|)
block|;   }
name|DominatorTree
operator|&
name|getDomTree
argument_list|()
block|{
return|return
name|DT
return|;
block|}
specifier|const
name|DominatorTree
operator|&
name|getDomTree
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
name|verifyAnalysis
argument_list|()
specifier|const
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
block|; }
name|void
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|const Module *M = nullptr
argument_list|)
specifier|const
name|override
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_IR_DOMINATORS_H
end_comment

end_unit

