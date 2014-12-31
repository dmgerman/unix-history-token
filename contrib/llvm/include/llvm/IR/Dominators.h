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
file|"llvm/ADT/DenseMap.h"
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
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
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
file|"llvm/IR/Function.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/GenericDomTree.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|EXTERN_TEMPLATE_INSTANTIATION
argument_list|(
argument|class DomTreeNodeBase<BasicBlock>
argument_list|)
empty_stmt|;
name|EXTERN_TEMPLATE_INSTANTIATION
argument_list|(
argument|class DominatorTreeBase<BasicBlock>
argument_list|)
empty_stmt|;
define|#
directive|define
name|LLVM_COMMA
value|,
name|EXTERN_TEMPLATE_INSTANTIATION
argument_list|(
argument|void Calculate<Function LLVM_COMMA BasicBlock *>(     DominatorTreeBase<GraphTraits<BasicBlock *>::NodeType>&DT LLVM_COMMA         Function&F)
argument_list|)
empty_stmt|;
name|EXTERN_TEMPLATE_INSTANTIATION
argument_list|(
argument|void Calculate<Function LLVM_COMMA Inverse<BasicBlock *>>(         DominatorTreeBase<GraphTraits<Inverse<BasicBlock *>>::NodeType>&DT             LLVM_COMMA Function&F)
argument_list|)
empty_stmt|;
undef|#
directive|undef
name|LLVM_COMMA
typedef|typedef
name|DomTreeNodeBase
operator|<
name|BasicBlock
operator|>
name|DomTreeNode
expr_stmt|;
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
block|{ }
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
name|bool
name|isSingleEdge
argument_list|()
specifier|const
expr_stmt|;
block|}
empty_stmt|;
comment|/// \brief Concrete subclass of DominatorTreeBase that is used to compute a
comment|/// normal dominator tree.
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
typedef|typedef
name|DominatorTreeBase
operator|<
name|BasicBlock
operator|>
name|Base
expr_stmt|;
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
name|Base
operator|::
name|compare
argument_list|(
name|Other
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
comment|// Ensure base-class overloads are visible.
end_comment

begin_expr_stmt
name|using
name|Base
operator|::
name|dominates
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Return true if Def dominates a use in User.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This performs the special checks necessary if Def and User are in the same
end_comment

begin_comment
comment|/// basic block. Note that Def doesn't dominate a use in Def itself!
end_comment

begin_decl_stmt
name|bool
name|dominates
argument_list|(
specifier|const
name|Instruction
operator|*
name|Def
argument_list|,
specifier|const
name|Use
operator|&
name|U
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|dominates
argument_list|(
specifier|const
name|Instruction
operator|*
name|Def
argument_list|,
specifier|const
name|Instruction
operator|*
name|User
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|dominates
argument_list|(
specifier|const
name|Instruction
operator|*
name|Def
argument_list|,
specifier|const
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|dominates
argument_list|(
specifier|const
name|BasicBlockEdge
operator|&
name|BBE
argument_list|,
specifier|const
name|Use
operator|&
name|U
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|dominates
argument_list|(
specifier|const
name|BasicBlockEdge
operator|&
name|BBE
argument_list|,
specifier|const
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Ensure base class overloads are visible.
end_comment

begin_expr_stmt
name|using
name|Base
operator|::
name|isReachableFromEntry
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Provide an overload for a Use.
end_comment

begin_decl_stmt
name|bool
name|isReachableFromEntry
argument_list|(
specifier|const
name|Use
operator|&
name|U
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Verify the correctness of the domtree by re-computing it.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This should only be used for debugging as it aborts the program if the
end_comment

begin_comment
comment|/// verification fails.
end_comment

begin_expr_stmt
name|void
name|verifyDomTree
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
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
operator|>
expr|struct
name|GraphTraits
operator|<
name|DomTreeNode
operator|*
operator|>
block|{
typedef|typedef
name|DomTreeNode
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

begin_typedef
typedef|typedef
name|df_iterator
operator|<
name|DomTreeNode
operator|*
operator|>
name|nodes_iterator
expr_stmt|;
end_typedef

begin_function
specifier|static
name|nodes_iterator
name|nodes_begin
parameter_list|(
name|DomTreeNode
modifier|*
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
name|DomTreeNode
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

begin_expr_stmt
unit|};
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
name|NodeType
operator|*
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
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

