begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Analysis/LoopInfoImpl.h - Natural Loop Calculator ---*- C++ -*-===//
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
comment|// This is the generic implementation of LoopInfo used for both Loops and
end_comment

begin_comment
comment|// MachineLoops.
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
name|LLVM_ANALYSIS_LOOPINFOIMPL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_LOOPINFOIMPL_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DepthFirstIterator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PostOrderIterator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SetVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/LoopInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Dominators.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|//===----------------------------------------------------------------------===//
comment|// APIs for simple analysis of the loop. See header notes.
comment|/// getExitingBlocks - Return all blocks inside the loop that have successors
comment|/// outside of the loop.  These are the blocks _inside of the current loop_
comment|/// which branch out.  The returned list is always unique.
comment|///
name|template
operator|<
name|class
name|BlockT
operator|,
name|class
name|LoopT
operator|>
name|void
name|LoopBase
operator|<
name|BlockT
operator|,
name|LoopT
operator|>
operator|::
name|getExitingBlocks
argument_list|(
argument|SmallVectorImpl<BlockT *>&ExitingBlocks
argument_list|)
specifier|const
block|{
for|for
control|(
specifier|const
specifier|auto
name|BB
range|:
name|blocks
argument_list|()
control|)
for|for
control|(
specifier|const
specifier|auto
modifier|&
name|Succ
range|:
name|children
operator|<
name|BlockT
operator|*
operator|>
operator|(
name|BB
operator|)
control|)
if|if
condition|(
operator|!
name|contains
argument_list|(
name|Succ
argument_list|)
condition|)
block|{
comment|// Not in current loop? It must be an exit block.
name|ExitingBlocks
operator|.
name|push_back
argument_list|(
name|BB
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
comment|/// getExitingBlock - If getExitingBlocks would return exactly one block,
comment|/// return that block. Otherwise return null.
name|template
operator|<
name|class
name|BlockT
operator|,
name|class
name|LoopT
operator|>
name|BlockT
operator|*
name|LoopBase
operator|<
name|BlockT
operator|,
name|LoopT
operator|>
operator|::
name|getExitingBlock
argument_list|()
specifier|const
block|{
name|SmallVector
operator|<
name|BlockT
operator|*
block|,
literal|8
operator|>
name|ExitingBlocks
block|;
name|getExitingBlocks
argument_list|(
name|ExitingBlocks
argument_list|)
block|;
if|if
condition|(
name|ExitingBlocks
operator|.
name|size
argument_list|()
operator|==
literal|1
condition|)
return|return
name|ExitingBlocks
index|[
literal|0
index|]
return|;
return|return
name|nullptr
return|;
block|}
end_decl_stmt

begin_comment
comment|/// getExitBlocks - Return all of the successor blocks of this loop.  These
end_comment

begin_comment
comment|/// are the blocks _outside of the current loop_ which are branched to.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|BlockT
operator|,
name|class
name|LoopT
operator|>
name|void
name|LoopBase
operator|<
name|BlockT
operator|,
name|LoopT
operator|>
operator|::
name|getExitBlocks
argument_list|(
argument|SmallVectorImpl<BlockT*>&ExitBlocks
argument_list|)
specifier|const
block|{
for|for
control|(
specifier|const
specifier|auto
name|BB
range|:
name|blocks
argument_list|()
control|)
for|for
control|(
specifier|const
specifier|auto
modifier|&
name|Succ
range|:
name|children
operator|<
name|BlockT
operator|*
operator|>
operator|(
name|BB
operator|)
control|)
if|if
condition|(
operator|!
name|contains
argument_list|(
name|Succ
argument_list|)
condition|)
comment|// Not in current loop? It must be an exit block.
name|ExitBlocks
operator|.
name|push_back
argument_list|(
name|Succ
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_comment
comment|/// getExitBlock - If getExitBlocks would return exactly one block,
end_comment

begin_comment
comment|/// return that block. Otherwise return null.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|BlockT
operator|,
name|class
name|LoopT
operator|>
name|BlockT
operator|*
name|LoopBase
operator|<
name|BlockT
operator|,
name|LoopT
operator|>
operator|::
name|getExitBlock
argument_list|()
specifier|const
block|{
name|SmallVector
operator|<
name|BlockT
operator|*
block|,
literal|8
operator|>
name|ExitBlocks
block|;
name|getExitBlocks
argument_list|(
name|ExitBlocks
argument_list|)
block|;
if|if
condition|(
name|ExitBlocks
operator|.
name|size
argument_list|()
operator|==
literal|1
condition|)
return|return
name|ExitBlocks
index|[
literal|0
index|]
return|;
end_expr_stmt

begin_return
return|return
name|nullptr
return|;
end_return

begin_comment
unit|}
comment|/// getExitEdges - Return all pairs of (_inside_block_,_outside_block_).
end_comment

begin_expr_stmt
unit|template
operator|<
name|class
name|BlockT
operator|,
name|class
name|LoopT
operator|>
name|void
name|LoopBase
operator|<
name|BlockT
operator|,
name|LoopT
operator|>
operator|::
name|getExitEdges
argument_list|(
argument|SmallVectorImpl<Edge>&ExitEdges
argument_list|)
specifier|const
block|{
for|for
control|(
specifier|const
specifier|auto
name|BB
range|:
name|blocks
argument_list|()
control|)
for|for
control|(
specifier|const
specifier|auto
modifier|&
name|Succ
range|:
name|children
operator|<
name|BlockT
operator|*
operator|>
operator|(
name|BB
operator|)
control|)
if|if
condition|(
operator|!
name|contains
argument_list|(
name|Succ
argument_list|)
condition|)
comment|// Not in current loop? It must be an exit block.
name|ExitEdges
operator|.
name|emplace_back
argument_list|(
name|BB
argument_list|,
name|Succ
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_comment
comment|/// getLoopPreheader - If there is a preheader for this loop, return it.  A
end_comment

begin_comment
comment|/// loop has a preheader if there is only one edge to the header of the loop
end_comment

begin_comment
comment|/// from outside of the loop.  If this is the case, the block branching to the
end_comment

begin_comment
comment|/// header of the loop is the preheader node.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This method returns null if there is no preheader for the loop.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|BlockT
operator|,
name|class
name|LoopT
operator|>
name|BlockT
operator|*
name|LoopBase
operator|<
name|BlockT
operator|,
name|LoopT
operator|>
operator|::
name|getLoopPreheader
argument_list|()
specifier|const
block|{
comment|// Keep track of nodes outside the loop branching to the header...
name|BlockT
operator|*
name|Out
operator|=
name|getLoopPredecessor
argument_list|()
block|;
if|if
condition|(
operator|!
name|Out
condition|)
return|return
name|nullptr
return|;
end_expr_stmt

begin_comment
comment|// Make sure there is only one exit out of the preheader.
end_comment

begin_typedef
typedef|typedef
name|GraphTraits
operator|<
name|BlockT
operator|*
operator|>
name|BlockTraits
expr_stmt|;
end_typedef

begin_expr_stmt
name|typename
name|BlockTraits
operator|::
name|ChildIteratorType
name|SI
operator|=
name|BlockTraits
operator|::
name|child_begin
argument_list|(
name|Out
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|++
name|SI
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|SI
operator|!=
name|BlockTraits
operator|::
name|child_end
argument_list|(
name|Out
argument_list|)
condition|)
return|return
name|nullptr
return|;
end_if

begin_comment
comment|// Multiple exits from the block, must not be a preheader.
end_comment

begin_comment
comment|// The predecessor has exactly one successor, so it is a preheader.
end_comment

begin_return
return|return
name|Out
return|;
end_return

begin_comment
unit|}
comment|/// getLoopPredecessor - If the given loop's header has exactly one unique
end_comment

begin_comment
comment|/// predecessor outside the loop, return it. Otherwise return null.
end_comment

begin_comment
comment|/// This is less strict that the loop "preheader" concept, which requires
end_comment

begin_comment
comment|/// the predecessor to have exactly one successor.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
unit|template
operator|<
name|class
name|BlockT
operator|,
name|class
name|LoopT
operator|>
name|BlockT
operator|*
name|LoopBase
operator|<
name|BlockT
operator|,
name|LoopT
operator|>
operator|::
name|getLoopPredecessor
argument_list|()
specifier|const
block|{
comment|// Keep track of nodes outside the loop branching to the header...
name|BlockT
operator|*
name|Out
operator|=
name|nullptr
block|;
comment|// Loop over the predecessors of the header node...
name|BlockT
operator|*
name|Header
operator|=
name|getHeader
argument_list|()
block|;
for|for
control|(
specifier|const
specifier|auto
name|Pred
range|:
name|children
operator|<
name|Inverse
operator|<
name|BlockT
operator|*
operator|>>
operator|(
name|Header
operator|)
control|)
block|{
if|if
condition|(
operator|!
name|contains
argument_list|(
name|Pred
argument_list|)
condition|)
block|{
comment|// If the block is not in the loop...
if|if
condition|(
name|Out
operator|&&
name|Out
operator|!=
name|Pred
condition|)
return|return
name|nullptr
return|;
comment|// Multiple predecessors outside the loop
name|Out
operator|=
name|Pred
expr_stmt|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// Make sure there is only one exit out of the preheader.
end_comment

begin_expr_stmt
unit|assert
operator|(
name|Out
operator|&&
literal|"Header of loop has no predecessors from outside loop?"
operator|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|Out
return|;
end_return

begin_comment
unit|}
comment|/// getLoopLatch - If there is a single latch block for this loop, return it.
end_comment

begin_comment
comment|/// A latch block is a block that contains a branch back to the header.
end_comment

begin_expr_stmt
unit|template
operator|<
name|class
name|BlockT
operator|,
name|class
name|LoopT
operator|>
name|BlockT
operator|*
name|LoopBase
operator|<
name|BlockT
operator|,
name|LoopT
operator|>
operator|::
name|getLoopLatch
argument_list|()
specifier|const
block|{
name|BlockT
operator|*
name|Header
operator|=
name|getHeader
argument_list|()
block|;
name|BlockT
operator|*
name|Latch
operator|=
name|nullptr
block|;
for|for
control|(
specifier|const
specifier|auto
name|Pred
range|:
name|children
operator|<
name|Inverse
operator|<
name|BlockT
operator|*
operator|>>
operator|(
name|Header
operator|)
control|)
block|{
if|if
condition|(
name|contains
argument_list|(
name|Pred
argument_list|)
condition|)
block|{
if|if
condition|(
name|Latch
condition|)
return|return
name|nullptr
return|;
name|Latch
operator|=
name|Pred
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
unit|}    return
name|Latch
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// APIs for updating loop information after changing the CFG
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// addBasicBlockToLoop - This method is used by other analyses to update loop
end_comment

begin_comment
comment|/// information.  NewBB is set to be a new member of the current loop.
end_comment

begin_comment
comment|/// Because of this, it is added as a member of all parent loops, and is added
end_comment

begin_comment
comment|/// to the specified LoopInfo object as being in the current basic block.  It
end_comment

begin_comment
comment|/// is not valid to replace the loop header with this method.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
unit|template
operator|<
name|class
name|BlockT
operator|,
name|class
name|LoopT
operator|>
name|void
name|LoopBase
operator|<
name|BlockT
operator|,
name|LoopT
operator|>
operator|::
name|addBasicBlockToLoop
argument_list|(
argument|BlockT *NewBB
argument_list|,
argument|LoopInfoBase<BlockT
argument_list|,
argument|LoopT>&LIB
argument_list|)
block|{
ifndef|#
directive|ifndef
name|NDEBUG
if|if
condition|(
operator|!
name|Blocks
operator|.
name|empty
argument_list|()
condition|)
block|{
name|auto
name|SameHeader
init|=
name|LIB
index|[
name|getHeader
argument_list|()
index|]
decl_stmt|;
name|assert
argument_list|(
name|contains
argument_list|(
name|SameHeader
argument_list|)
operator|&&
name|getHeader
argument_list|()
operator|==
name|SameHeader
operator|->
name|getHeader
argument_list|()
operator|&&
literal|"Incorrect LI specified for this loop!"
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|assert
argument_list|(
name|NewBB
operator|&&
literal|"Cannot add a null basic block to the loop!"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|assert
argument_list|(
operator|!
name|LIB
index|[
name|NewBB
index|]
operator|&&
literal|"BasicBlock already in the loop!"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|LoopT
modifier|*
name|L
init|=
name|static_cast
operator|<
name|LoopT
operator|*
operator|>
operator|(
name|this
operator|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Add the loop mapping to the LoopInfo object...
end_comment

begin_expr_stmt
name|LIB
operator|.
name|BBMap
index|[
name|NewBB
index|]
operator|=
name|L
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Add the basic block to this loop and all parent loops...
end_comment

begin_while
while|while
condition|(
name|L
condition|)
block|{
name|L
operator|->
name|addBlockEntry
argument_list|(
name|NewBB
argument_list|)
expr_stmt|;
name|L
operator|=
name|L
operator|->
name|getParentLoop
argument_list|()
expr_stmt|;
block|}
end_while

begin_comment
unit|}
comment|/// replaceChildLoopWith - This is used when splitting loops up.  It replaces
end_comment

begin_comment
comment|/// the OldChild entry in our children list with NewChild, and updates the
end_comment

begin_comment
comment|/// parent pointer of OldChild to be null and the NewChild to be this loop.
end_comment

begin_comment
comment|/// This updates the loop depth of the new child.
end_comment

begin_expr_stmt
unit|template
operator|<
name|class
name|BlockT
operator|,
name|class
name|LoopT
operator|>
name|void
name|LoopBase
operator|<
name|BlockT
operator|,
name|LoopT
operator|>
operator|::
name|replaceChildLoopWith
argument_list|(
argument|LoopT *OldChild
argument_list|,
argument|LoopT *NewChild
argument_list|)
block|{
name|assert
argument_list|(
name|OldChild
operator|->
name|ParentLoop
operator|==
name|this
operator|&&
literal|"This loop is already broken!"
argument_list|)
block|;
name|assert
argument_list|(
operator|!
name|NewChild
operator|->
name|ParentLoop
operator|&&
literal|"NewChild already has a parent!"
argument_list|)
block|;
name|typename
name|std
operator|::
name|vector
operator|<
name|LoopT
operator|*
operator|>
operator|::
name|iterator
name|I
operator|=
name|find
argument_list|(
name|SubLoops
argument_list|,
name|OldChild
argument_list|)
block|;
name|assert
argument_list|(
name|I
operator|!=
name|SubLoops
operator|.
name|end
argument_list|()
operator|&&
literal|"OldChild not in loop!"
argument_list|)
block|;
operator|*
name|I
operator|=
name|NewChild
block|;
name|OldChild
operator|->
name|ParentLoop
operator|=
name|nullptr
block|;
name|NewChild
operator|->
name|ParentLoop
operator|=
name|static_cast
operator|<
name|LoopT
operator|*
operator|>
operator|(
name|this
operator|)
block|; }
comment|/// verifyLoop - Verify loop structure
name|template
operator|<
name|class
name|BlockT
operator|,
name|class
name|LoopT
operator|>
name|void
name|LoopBase
operator|<
name|BlockT
operator|,
name|LoopT
operator|>
operator|::
name|verifyLoop
argument_list|()
specifier|const
block|{
ifndef|#
directive|ifndef
name|NDEBUG
name|assert
argument_list|(
operator|!
name|Blocks
operator|.
name|empty
argument_list|()
operator|&&
literal|"Loop header is missing"
argument_list|)
block|;
comment|// Setup for using a depth-first iterator to visit every block in the loop.
name|SmallVector
operator|<
name|BlockT
operator|*
block|,
literal|8
operator|>
name|ExitBBs
block|;
name|getExitBlocks
argument_list|(
name|ExitBBs
argument_list|)
block|;
name|df_iterator_default_set
operator|<
name|BlockT
operator|*
operator|>
name|VisitSet
block|;
name|VisitSet
operator|.
name|insert
argument_list|(
name|ExitBBs
operator|.
name|begin
argument_list|()
argument_list|,
name|ExitBBs
operator|.
name|end
argument_list|()
argument_list|)
block|;
name|df_ext_iterator
operator|<
name|BlockT
operator|*
block|,
name|df_iterator_default_set
operator|<
name|BlockT
operator|*
operator|>>
name|BI
operator|=
name|df_ext_begin
argument_list|(
name|getHeader
argument_list|()
argument_list|,
name|VisitSet
argument_list|)
block|,
name|BE
operator|=
name|df_ext_end
argument_list|(
name|getHeader
argument_list|()
argument_list|,
name|VisitSet
argument_list|)
block|;
comment|// Keep track of the number of BBs visited.
name|unsigned
name|NumVisited
operator|=
literal|0
block|;
comment|// Check the individual blocks.
for|for
control|(
init|;
name|BI
operator|!=
name|BE
condition|;
operator|++
name|BI
control|)
block|{
name|BlockT
modifier|*
name|BB
init|=
operator|*
name|BI
decl_stmt|;
name|assert
argument_list|(
name|std
operator|::
name|any_of
argument_list|(
name|GraphTraits
operator|<
name|BlockT
operator|*
operator|>
operator|::
name|child_begin
argument_list|(
name|BB
argument_list|)
argument_list|,
name|GraphTraits
operator|<
name|BlockT
operator|*
operator|>
operator|::
name|child_end
argument_list|(
name|BB
argument_list|)
argument_list|,
index|[
operator|&
index|]
operator|(
name|BlockT
operator|*
name|B
operator|)
block|{
return|return
name|contains
argument_list|(
name|B
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|)
operator|&&
literal|"Loop block has no in-loop successors!"
end_expr_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|assert
argument_list|(
name|std
operator|::
name|any_of
argument_list|(
name|GraphTraits
operator|<
name|Inverse
operator|<
name|BlockT
operator|*
operator|>
expr|>
operator|::
name|child_begin
argument_list|(
name|BB
argument_list|)
argument_list|,
name|GraphTraits
operator|<
name|Inverse
operator|<
name|BlockT
operator|*
operator|>
expr|>
operator|::
name|child_end
argument_list|(
name|BB
argument_list|)
argument_list|,
index|[
operator|&
index|]
operator|(
name|BlockT
operator|*
name|B
operator|)
block|{
return|return
name|contains
argument_list|(
name|B
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|)
operator|&&
literal|"Loop block has no in-loop predecessors!"
end_expr_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|SmallVector
operator|<
name|BlockT
operator|*
operator|,
literal|2
operator|>
name|OutsideLoopPreds
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|for_each
argument_list|(
name|GraphTraits
operator|<
name|Inverse
operator|<
name|BlockT
operator|*
operator|>
expr|>
operator|::
name|child_begin
argument_list|(
name|BB
argument_list|)
argument_list|,
name|GraphTraits
operator|<
name|Inverse
operator|<
name|BlockT
operator|*
operator|>
expr|>
operator|::
name|child_end
argument_list|(
name|BB
argument_list|)
argument_list|,
index|[
operator|&
index|]
operator|(
name|BlockT
operator|*
name|B
operator|)
block|{
if|if
condition|(
operator|!
name|contains
argument_list|(
name|B
argument_list|)
condition|)
name|OutsideLoopPreds
operator|.
name|push_back
argument_list|(
name|B
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_if
if|if
condition|(
name|BB
operator|==
name|getHeader
argument_list|()
condition|)
block|{
name|assert
argument_list|(
operator|!
name|OutsideLoopPreds
operator|.
name|empty
argument_list|()
operator|&&
literal|"Loop is unreachable!"
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
name|OutsideLoopPreds
operator|.
name|empty
argument_list|()
condition|)
block|{
comment|// A non-header loop shouldn't be reachable from outside the loop,
comment|// though it is permitted if the predecessor is not itself actually
comment|// reachable.
name|BlockT
modifier|*
name|EntryBB
init|=
operator|&
name|BB
operator|->
name|getParent
argument_list|()
operator|->
name|front
argument_list|()
decl_stmt|;
for|for
control|(
name|BlockT
modifier|*
name|CB
range|:
name|depth_first
argument_list|(
name|EntryBB
argument_list|)
control|)
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|,
name|e
init|=
name|OutsideLoopPreds
operator|.
name|size
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
name|assert
argument_list|(
name|CB
operator|!=
name|OutsideLoopPreds
index|[
name|i
index|]
operator|&&
literal|"Loop has multiple entry points!"
argument_list|)
expr_stmt|;
block|}
end_if

begin_expr_stmt
name|assert
argument_list|(
name|BB
operator|!=
operator|&
name|getHeader
argument_list|()
operator|->
name|getParent
argument_list|()
operator|->
name|front
argument_list|()
operator|&&
literal|"Loop contains function entry block!"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|NumVisited
operator|++
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}    assert
operator|(
name|NumVisited
operator|==
name|getNumBlocks
argument_list|()
operator|&&
literal|"Unreachable block in loop"
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Check the subloops.
end_comment

begin_for
for|for
control|(
name|iterator
name|I
init|=
name|begin
argument_list|()
init|,
name|E
init|=
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
comment|// Each block in each subloop should be contained within this loop.
for|for
control|(
name|block_iterator
name|BI
init|=
operator|(
operator|*
name|I
operator|)
operator|->
name|block_begin
argument_list|()
init|,
name|BE
init|=
operator|(
operator|*
name|I
operator|)
operator|->
name|block_end
argument_list|()
init|;
name|BI
operator|!=
name|BE
condition|;
operator|++
name|BI
control|)
block|{
name|assert
argument_list|(
name|contains
argument_list|(
operator|*
name|BI
argument_list|)
operator|&&
literal|"Loop does not contain all the blocks of a subloop!"
argument_list|)
expr_stmt|;
block|}
end_for

begin_comment
comment|// Check the parent loop pointer.
end_comment

begin_if
if|if
condition|(
name|ParentLoop
condition|)
block|{
name|assert
argument_list|(
name|is_contained
argument_list|(
operator|*
name|ParentLoop
argument_list|,
name|this
argument_list|)
operator|&&
literal|"Loop is not a subloop of its parent!"
argument_list|)
expr_stmt|;
block|}
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_comment
unit|}
comment|/// verifyLoop - Verify loop structure of this loop and all nested loops.
end_comment

begin_expr_stmt
unit|template
operator|<
name|class
name|BlockT
operator|,
name|class
name|LoopT
operator|>
name|void
name|LoopBase
operator|<
name|BlockT
operator|,
name|LoopT
operator|>
operator|::
name|verifyLoopNest
argument_list|(
argument|DenseSet<const LoopT*> *Loops
argument_list|)
specifier|const
block|{
name|Loops
operator|->
name|insert
argument_list|(
name|static_cast
operator|<
specifier|const
name|LoopT
operator|*
operator|>
operator|(
name|this
operator|)
argument_list|)
block|;
comment|// Verify this loop.
name|verifyLoop
argument_list|()
block|;
comment|// Verify the subloops.
for|for
control|(
name|iterator
name|I
init|=
name|begin
argument_list|()
init|,
name|E
init|=
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
operator|(
operator|*
name|I
operator|)
operator|->
name|verifyLoopNest
argument_list|(
name|Loops
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|BlockT
operator|,
name|class
name|LoopT
operator|>
name|void
name|LoopBase
operator|<
name|BlockT
operator|,
name|LoopT
operator|>
operator|::
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|unsigned Depth
argument_list|,
argument|bool Verbose
argument_list|)
specifier|const
block|{
name|OS
operator|.
name|indent
argument_list|(
name|Depth
operator|*
literal|2
argument_list|)
operator|<<
literal|"Loop at depth "
operator|<<
name|getLoopDepth
argument_list|()
operator|<<
literal|" containing: "
block|;
name|BlockT
operator|*
name|H
operator|=
name|getHeader
argument_list|()
block|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|<
name|getBlocks
argument_list|()
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|BlockT
modifier|*
name|BB
init|=
name|getBlocks
argument_list|()
index|[
name|i
index|]
decl_stmt|;
if|if
condition|(
operator|!
name|Verbose
condition|)
block|{
if|if
condition|(
name|i
condition|)
name|OS
operator|<<
literal|","
expr_stmt|;
name|BB
operator|->
name|printAsOperand
argument_list|(
name|OS
argument_list|,
name|false
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_else
else|else
name|OS
operator|<<
literal|"\n"
expr_stmt|;
end_else

begin_if
if|if
condition|(
name|BB
operator|==
name|H
condition|)
name|OS
operator|<<
literal|"<header>"
expr_stmt|;
end_if

begin_if
if|if
condition|(
name|isLoopLatch
argument_list|(
name|BB
argument_list|)
condition|)
name|OS
operator|<<
literal|"<latch>"
expr_stmt|;
end_if

begin_if
if|if
condition|(
name|isLoopExiting
argument_list|(
name|BB
argument_list|)
condition|)
name|OS
operator|<<
literal|"<exiting>"
expr_stmt|;
end_if

begin_if
if|if
condition|(
name|Verbose
condition|)
name|BB
operator|->
name|print
argument_list|(
name|OS
argument_list|)
expr_stmt|;
end_if

begin_expr_stmt
unit|}   OS
operator|<<
literal|"\n"
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
name|iterator
name|I
init|=
name|begin
argument_list|()
init|,
name|E
init|=
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
operator|(
operator|*
name|I
operator|)
operator|->
name|print
argument_list|(
name|OS
argument_list|,
name|Depth
operator|+
literal|2
argument_list|)
expr_stmt|;
end_for

begin_comment
unit|}
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// Stable LoopInfo Analysis - Build a loop tree using stable iterators so the
end_comment

begin_comment
comment|/// result does / not depend on use list (block predecessor) order.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Discover a subloop with the specified backedges such that: All blocks within
end_comment

begin_comment
comment|/// this loop are mapped to this loop or a subloop. And all subloops within this
end_comment

begin_comment
comment|/// loop have their parent loop set to this loop or a subloop.
end_comment

begin_expr_stmt
unit|template
operator|<
name|class
name|BlockT
operator|,
name|class
name|LoopT
operator|>
specifier|static
name|void
name|discoverAndMapSubloop
argument_list|(
argument|LoopT *L
argument_list|,
argument|ArrayRef<BlockT*> Backedges
argument_list|,
argument|LoopInfoBase<BlockT
argument_list|,
argument|LoopT> *LI
argument_list|,
argument|const DominatorTreeBase<BlockT>&DomTree
argument_list|)
block|{
typedef|typedef
name|GraphTraits
operator|<
name|Inverse
operator|<
name|BlockT
operator|*
operator|>
expr|>
name|InvBlockTraits
expr_stmt|;
name|unsigned
name|NumBlocks
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|unsigned
name|NumSubloops
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Perform a backward CFG traversal using a worklist.
end_comment

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|BlockT
operator|*
operator|>
name|ReverseCFGWorklist
argument_list|(
name|Backedges
operator|.
name|begin
argument_list|()
argument_list|,
name|Backedges
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_while
while|while
condition|(
operator|!
name|ReverseCFGWorklist
operator|.
name|empty
argument_list|()
condition|)
block|{
name|BlockT
modifier|*
name|PredBB
init|=
name|ReverseCFGWorklist
operator|.
name|back
argument_list|()
decl_stmt|;
name|ReverseCFGWorklist
operator|.
name|pop_back
argument_list|()
expr_stmt|;
name|LoopT
modifier|*
name|Subloop
init|=
name|LI
operator|->
name|getLoopFor
argument_list|(
name|PredBB
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|Subloop
condition|)
block|{
if|if
condition|(
operator|!
name|DomTree
operator|.
name|isReachableFromEntry
argument_list|(
name|PredBB
argument_list|)
condition|)
continue|continue;
comment|// This is an undiscovered block. Map it to the current loop.
name|LI
operator|->
name|changeLoopFor
argument_list|(
name|PredBB
argument_list|,
name|L
argument_list|)
expr_stmt|;
operator|++
name|NumBlocks
expr_stmt|;
if|if
condition|(
name|PredBB
operator|==
name|L
operator|->
name|getHeader
argument_list|()
condition|)
continue|continue;
comment|// Push all block predecessors on the worklist.
name|ReverseCFGWorklist
operator|.
name|insert
argument_list|(
name|ReverseCFGWorklist
operator|.
name|end
argument_list|()
argument_list|,
name|InvBlockTraits
operator|::
name|child_begin
argument_list|(
name|PredBB
argument_list|)
argument_list|,
name|InvBlockTraits
operator|::
name|child_end
argument_list|(
name|PredBB
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// This is a discovered block. Find its outermost discovered loop.
while|while
condition|(
name|LoopT
modifier|*
name|Parent
init|=
name|Subloop
operator|->
name|getParentLoop
argument_list|()
condition|)
name|Subloop
operator|=
name|Parent
expr_stmt|;
comment|// If it is already discovered to be a subloop of this loop, continue.
if|if
condition|(
name|Subloop
operator|==
name|L
condition|)
continue|continue;
comment|// Discover a subloop of this loop.
name|Subloop
operator|->
name|setParentLoop
argument_list|(
name|L
argument_list|)
expr_stmt|;
operator|++
name|NumSubloops
expr_stmt|;
name|NumBlocks
operator|+=
name|Subloop
operator|->
name|getBlocks
argument_list|()
operator|.
name|capacity
argument_list|()
expr_stmt|;
name|PredBB
operator|=
name|Subloop
operator|->
name|getHeader
argument_list|()
expr_stmt|;
comment|// Continue traversal along predecessors that are not loop-back edges from
comment|// within this subloop tree itself. Note that a predecessor may directly
comment|// reach another subloop that is not yet discovered to be a subloop of
comment|// this loop, which we must traverse.
for|for
control|(
specifier|const
specifier|auto
name|Pred
range|:
name|children
operator|<
name|Inverse
operator|<
name|BlockT
operator|*
operator|>>
operator|(
name|PredBB
operator|)
control|)
block|{
if|if
condition|(
name|LI
operator|->
name|getLoopFor
argument_list|(
name|Pred
argument_list|)
operator|!=
name|Subloop
condition|)
name|ReverseCFGWorklist
operator|.
name|push_back
argument_list|(
name|Pred
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_while

begin_expr_stmt
name|L
operator|->
name|getSubLoopsVector
argument_list|()
operator|.
name|reserve
argument_list|(
name|NumSubloops
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|L
operator|->
name|reserveBlocks
argument_list|(
name|NumBlocks
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|/// Populate all loop data in a stable order during a single forward DFS.
end_comment

begin_expr_stmt
unit|template
operator|<
name|class
name|BlockT
operator|,
name|class
name|LoopT
operator|>
name|class
name|PopulateLoopsDFS
block|{
typedef|typedef
name|GraphTraits
operator|<
name|BlockT
operator|*
operator|>
name|BlockTraits
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|BlockTraits
operator|::
name|ChildIteratorType
name|SuccIterTy
expr_stmt|;
end_typedef

begin_expr_stmt
name|LoopInfoBase
operator|<
name|BlockT
operator|,
name|LoopT
operator|>
operator|*
name|LI
expr_stmt|;
end_expr_stmt

begin_label
name|public
label|:
end_label

begin_expr_stmt
name|PopulateLoopsDFS
argument_list|(
name|LoopInfoBase
operator|<
name|BlockT
argument_list|,
name|LoopT
operator|>
operator|*
name|li
argument_list|)
operator|:
name|LI
argument_list|(
argument|li
argument_list|)
block|{}
name|void
name|traverse
argument_list|(
name|BlockT
operator|*
name|EntryBlock
argument_list|)
expr_stmt|;
end_expr_stmt

begin_label
name|protected
label|:
end_label

begin_function_decl
name|void
name|insertIntoLoop
parameter_list|(
name|BlockT
modifier|*
name|Block
parameter_list|)
function_decl|;
end_function_decl

begin_comment
unit|};
comment|/// Top-level driver for the forward DFS within the loop.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|BlockT
operator|,
name|class
name|LoopT
operator|>
name|void
name|PopulateLoopsDFS
operator|<
name|BlockT
operator|,
name|LoopT
operator|>
operator|::
name|traverse
argument_list|(
argument|BlockT *EntryBlock
argument_list|)
block|{
for|for
control|(
name|BlockT
modifier|*
name|BB
range|:
name|post_order
argument_list|(
name|EntryBlock
argument_list|)
control|)
name|insertIntoLoop
argument_list|(
name|BB
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_comment
comment|/// Add a single Block to its ancestor loops in PostOrder. If the block is a
end_comment

begin_comment
comment|/// subloop header, add the subloop to its parent in PostOrder, then reverse the
end_comment

begin_comment
comment|/// Block and Subloop vectors of the now complete subloop to achieve RPO.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|BlockT
operator|,
name|class
name|LoopT
operator|>
name|void
name|PopulateLoopsDFS
operator|<
name|BlockT
operator|,
name|LoopT
operator|>
operator|::
name|insertIntoLoop
argument_list|(
argument|BlockT *Block
argument_list|)
block|{
name|LoopT
operator|*
name|Subloop
operator|=
name|LI
operator|->
name|getLoopFor
argument_list|(
name|Block
argument_list|)
block|;
if|if
condition|(
name|Subloop
operator|&&
name|Block
operator|==
name|Subloop
operator|->
name|getHeader
argument_list|()
condition|)
block|{
comment|// We reach this point once per subloop after processing all the blocks in
comment|// the subloop.
if|if
condition|(
name|Subloop
operator|->
name|getParentLoop
argument_list|()
condition|)
name|Subloop
operator|->
name|getParentLoop
argument_list|()
operator|->
name|getSubLoopsVector
argument_list|()
operator|.
name|push_back
argument_list|(
name|Subloop
argument_list|)
expr_stmt|;
else|else
name|LI
operator|->
name|addTopLevelLoop
argument_list|(
name|Subloop
argument_list|)
expr_stmt|;
comment|// For convenience, Blocks and Subloops are inserted in postorder. Reverse
comment|// the lists, except for the loop header, which is always at the beginning.
name|Subloop
operator|->
name|reverseBlock
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|std
operator|::
name|reverse
argument_list|(
name|Subloop
operator|->
name|getSubLoopsVector
argument_list|()
operator|.
name|begin
argument_list|()
argument_list|,
name|Subloop
operator|->
name|getSubLoopsVector
argument_list|()
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
name|Subloop
operator|=
name|Subloop
operator|->
name|getParentLoop
argument_list|()
expr_stmt|;
block|}
end_expr_stmt

begin_for
for|for
control|(
init|;
name|Subloop
condition|;
name|Subloop
operator|=
name|Subloop
operator|->
name|getParentLoop
argument_list|()
control|)
name|Subloop
operator|->
name|addBlockEntry
argument_list|(
name|Block
argument_list|)
expr_stmt|;
end_for

begin_comment
unit|}
comment|/// Analyze LoopInfo discovers loops during a postorder DominatorTree traversal
end_comment

begin_comment
comment|/// interleaved with backward CFG traversals within each subloop
end_comment

begin_comment
comment|/// (discoverAndMapSubloop). The backward traversal skips inner subloops, so
end_comment

begin_comment
comment|/// this part of the algorithm is linear in the number of CFG edges. Subloop and
end_comment

begin_comment
comment|/// Block vectors are then populated during a single forward CFG traversal
end_comment

begin_comment
comment|/// (PopulateLoopDFS).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// During the two CFG traversals each block is seen three times:
end_comment

begin_comment
comment|/// 1) Discovered and mapped by a reverse CFG traversal.
end_comment

begin_comment
comment|/// 2) Visited during a forward DFS CFG traversal.
end_comment

begin_comment
comment|/// 3) Reverse-inserted in the loop in postorder following forward DFS.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The Block vectors are inclusive, so step 3 requires loop-depth number of
end_comment

begin_comment
comment|/// insertions per block.
end_comment

begin_expr_stmt
unit|template
operator|<
name|class
name|BlockT
operator|,
name|class
name|LoopT
operator|>
name|void
name|LoopInfoBase
operator|<
name|BlockT
operator|,
name|LoopT
operator|>
operator|::
name|analyze
argument_list|(
argument|const DominatorTreeBase<BlockT>&DomTree
argument_list|)
block|{
comment|// Postorder traversal of the dominator tree.
specifier|const
name|DomTreeNodeBase
operator|<
name|BlockT
operator|>
operator|*
name|DomRoot
operator|=
name|DomTree
operator|.
name|getRootNode
argument_list|()
block|;
for|for
control|(
name|auto
name|DomNode
range|:
name|post_order
argument_list|(
name|DomRoot
argument_list|)
control|)
block|{
name|BlockT
modifier|*
name|Header
init|=
name|DomNode
operator|->
name|getBlock
argument_list|()
decl_stmt|;
name|SmallVector
operator|<
name|BlockT
operator|*
operator|,
literal|4
operator|>
name|Backedges
expr_stmt|;
comment|// Check each predecessor of the potential loop header.
for|for
control|(
specifier|const
specifier|auto
name|Backedge
range|:
name|children
operator|<
name|Inverse
operator|<
name|BlockT
operator|*
operator|>>
operator|(
name|Header
operator|)
control|)
block|{
comment|// If Header dominates predBB, this is a new loop. Collect the backedges.
if|if
condition|(
name|DomTree
operator|.
name|dominates
argument_list|(
name|Header
argument_list|,
name|Backedge
argument_list|)
operator|&&
name|DomTree
operator|.
name|isReachableFromEntry
argument_list|(
name|Backedge
argument_list|)
condition|)
block|{
name|Backedges
operator|.
name|push_back
argument_list|(
name|Backedge
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// Perform a backward CFG traversal to discover and map blocks in this loop.
end_comment

begin_expr_stmt
unit|if
operator|(
operator|!
name|Backedges
operator|.
name|empty
argument_list|()
operator|)
block|{
name|LoopT
operator|*
name|L
operator|=
name|new
name|LoopT
argument_list|(
name|Header
argument_list|)
block|;
name|discoverAndMapSubloop
argument_list|(
name|L
argument_list|,
name|ArrayRef
operator|<
name|BlockT
operator|*
operator|>
operator|(
name|Backedges
operator|)
argument_list|,
name|this
argument_list|,
name|DomTree
argument_list|)
block|;     }
end_expr_stmt

begin_comment
unit|}
comment|// Perform a single forward CFG traversal to populate block and subloop
end_comment

begin_comment
comment|// vectors for all loops.
end_comment

begin_expr_stmt
unit|PopulateLoopsDFS
operator|<
name|BlockT
operator|,
name|LoopT
operator|>
name|DFS
argument_list|(
name|this
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DFS
operator|.
name|traverse
argument_list|(
name|DomRoot
operator|->
name|getBlock
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}  template
operator|<
name|class
name|BlockT
operator|,
name|class
name|LoopT
operator|>
name|SmallVector
operator|<
name|LoopT
operator|*
operator|,
literal|4
operator|>
name|LoopInfoBase
operator|<
name|BlockT
operator|,
name|LoopT
operator|>
operator|::
name|getLoopsInPreorder
argument_list|()
block|{
name|SmallVector
operator|<
name|LoopT
operator|*
block|,
literal|4
operator|>
name|PreOrderLoops
block|,
name|PreOrderWorklist
block|;
comment|// The outer-most loop actually goes into the result in the same relative
comment|// order as we walk it. But LoopInfo stores the top level loops in reverse
comment|// program order so for here we reverse it to get forward program order.
comment|// FIXME: If we change the order of LoopInfo we will want to remove the
comment|// reverse here.
for|for
control|(
name|LoopT
modifier|*
name|RootL
range|:
name|reverse
argument_list|(
operator|*
name|this
argument_list|)
control|)
block|{
name|assert
argument_list|(
name|PreOrderWorklist
operator|.
name|empty
argument_list|()
operator|&&
literal|"Must start with an empty preorder walk worklist."
argument_list|)
expr_stmt|;
name|PreOrderWorklist
operator|.
name|push_back
argument_list|(
name|RootL
argument_list|)
expr_stmt|;
do|do
block|{
name|LoopT
modifier|*
name|L
init|=
name|PreOrderWorklist
operator|.
name|pop_back_val
argument_list|()
decl_stmt|;
comment|// Sub-loops are stored in forward program order, but will process the
comment|// worklist backwards so append them in reverse order.
name|PreOrderWorklist
operator|.
name|append
argument_list|(
name|L
operator|->
name|rbegin
argument_list|()
argument_list|,
name|L
operator|->
name|rend
argument_list|()
argument_list|)
expr_stmt|;
name|PreOrderLoops
operator|.
name|push_back
argument_list|(
name|L
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_while
while|while
condition|(
operator|!
name|PreOrderWorklist
operator|.
name|empty
argument_list|()
condition|)
empty_stmt|;
end_while

begin_expr_stmt
unit|}    return
name|PreOrderLoops
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}  template
operator|<
name|class
name|BlockT
operator|,
name|class
name|LoopT
operator|>
name|SmallVector
operator|<
name|LoopT
operator|*
operator|,
literal|4
operator|>
name|LoopInfoBase
operator|<
name|BlockT
operator|,
name|LoopT
operator|>
operator|::
name|getLoopsInReverseSiblingPreorder
argument_list|()
block|{
name|SmallVector
operator|<
name|LoopT
operator|*
block|,
literal|4
operator|>
name|PreOrderLoops
block|,
name|PreOrderWorklist
block|;
comment|// The outer-most loop actually goes into the result in the same relative
comment|// order as we walk it. LoopInfo stores the top level loops in reverse
comment|// program order so we walk in order here.
comment|// FIXME: If we change the order of LoopInfo we will want to add a reverse
comment|// here.
for|for
control|(
name|LoopT
modifier|*
name|RootL
range|:
operator|*
name|this
control|)
block|{
name|assert
argument_list|(
name|PreOrderWorklist
operator|.
name|empty
argument_list|()
operator|&&
literal|"Must start with an empty preorder walk worklist."
argument_list|)
expr_stmt|;
name|PreOrderWorklist
operator|.
name|push_back
argument_list|(
name|RootL
argument_list|)
expr_stmt|;
do|do
block|{
name|LoopT
modifier|*
name|L
init|=
name|PreOrderWorklist
operator|.
name|pop_back_val
argument_list|()
decl_stmt|;
comment|// Sub-loops are stored in forward program order, but will process the
comment|// worklist backwards so we can just append them in order.
name|PreOrderWorklist
operator|.
name|append
argument_list|(
name|L
operator|->
name|begin
argument_list|()
argument_list|,
name|L
operator|->
name|end
argument_list|()
argument_list|)
expr_stmt|;
name|PreOrderLoops
operator|.
name|push_back
argument_list|(
name|L
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_while
while|while
condition|(
operator|!
name|PreOrderWorklist
operator|.
name|empty
argument_list|()
condition|)
empty_stmt|;
end_while

begin_expr_stmt
unit|}    return
name|PreOrderLoops
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// Debugging
end_comment

begin_expr_stmt
unit|template
operator|<
name|class
name|BlockT
operator|,
name|class
name|LoopT
operator|>
name|void
name|LoopInfoBase
operator|<
name|BlockT
operator|,
name|LoopT
operator|>
operator|::
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|)
specifier|const
block|{
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|<
name|TopLevelLoops
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|TopLevelLoops
index|[
name|i
index|]
operator|->
name|print
argument_list|(
name|OS
argument_list|)
expr_stmt|;
if|#
directive|if
literal|0
block|for (DenseMap<BasicBlock*, LoopT*>::const_iterator I = BBMap.begin(),          E = BBMap.end(); I != E; ++I)     OS<< "BB '"<< I->first->getName()<< "' level = "<< I->second->getLoopDepth()<< "\n";
endif|#
directive|endif
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|bool
name|compareVectors
argument_list|(
argument|std::vector<T>&BB1
argument_list|,
argument|std::vector<T>&BB2
argument_list|)
block|{
name|std
operator|::
name|sort
argument_list|(
name|BB1
operator|.
name|begin
argument_list|()
argument_list|,
name|BB1
operator|.
name|end
argument_list|()
argument_list|)
block|;
name|std
operator|::
name|sort
argument_list|(
name|BB2
operator|.
name|begin
argument_list|()
argument_list|,
name|BB2
operator|.
name|end
argument_list|()
argument_list|)
block|;
return|return
name|BB1
operator|==
name|BB2
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|BlockT
operator|,
name|class
name|LoopT
operator|>
name|void
name|addInnerLoopsToHeadersMap
argument_list|(
argument|DenseMap<BlockT *
argument_list|,
argument|const LoopT *>&LoopHeaders
argument_list|,
argument|const LoopInfoBase<BlockT
argument_list|,
argument|LoopT>&LI
argument_list|,
argument|const LoopT&L
argument_list|)
block|{
name|LoopHeaders
index|[
name|L
operator|.
name|getHeader
argument_list|()
index|]
operator|=
operator|&
name|L
block|;
for|for
control|(
name|LoopT
modifier|*
name|SL
range|:
name|L
control|)
name|addInnerLoopsToHeadersMap
argument_list|(
name|LoopHeaders
argument_list|,
name|LI
argument_list|,
operator|*
name|SL
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|NDEBUG
end_ifndef

begin_expr_stmt
name|template
operator|<
name|class
name|BlockT
operator|,
name|class
name|LoopT
operator|>
specifier|static
name|void
name|compareLoops
argument_list|(
argument|const LoopT *L
argument_list|,
argument|const LoopT *OtherL
argument_list|,
argument|DenseMap<BlockT *
argument_list|,
argument|const LoopT *>&OtherLoopHeaders
argument_list|)
block|{
name|BlockT
operator|*
name|H
operator|=
name|L
operator|->
name|getHeader
argument_list|()
block|;
name|BlockT
operator|*
name|OtherH
operator|=
name|OtherL
operator|->
name|getHeader
argument_list|()
block|;
name|assert
argument_list|(
name|H
operator|==
name|OtherH
operator|&&
literal|"Mismatched headers even though found in the same map entry!"
argument_list|)
block|;
name|assert
argument_list|(
name|L
operator|->
name|getLoopDepth
argument_list|()
operator|==
name|OtherL
operator|->
name|getLoopDepth
argument_list|()
operator|&&
literal|"Mismatched loop depth!"
argument_list|)
block|;
specifier|const
name|LoopT
operator|*
name|ParentL
operator|=
name|L
block|,
operator|*
name|OtherParentL
operator|=
name|OtherL
block|;
do|do
block|{
name|assert
argument_list|(
name|ParentL
operator|->
name|getHeader
argument_list|()
operator|==
name|OtherParentL
operator|->
name|getHeader
argument_list|()
operator|&&
literal|"Mismatched parent loop headers!"
argument_list|)
expr_stmt|;
name|ParentL
operator|=
name|ParentL
operator|->
name|getParentLoop
argument_list|()
expr_stmt|;
name|OtherParentL
operator|=
name|OtherParentL
operator|->
name|getParentLoop
argument_list|()
expr_stmt|;
block|}
end_expr_stmt

begin_while
while|while
condition|(
name|ParentL
condition|)
empty_stmt|;
end_while

begin_for
for|for
control|(
specifier|const
name|LoopT
modifier|*
name|SubL
range|:
operator|*
name|L
control|)
block|{
name|BlockT
modifier|*
name|SubH
init|=
name|SubL
operator|->
name|getHeader
argument_list|()
decl_stmt|;
specifier|const
name|LoopT
modifier|*
name|OtherSubL
init|=
name|OtherLoopHeaders
operator|.
name|lookup
argument_list|(
name|SubH
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|OtherSubL
operator|&&
literal|"Inner loop is missing in computed loop info!"
argument_list|)
expr_stmt|;
name|OtherLoopHeaders
operator|.
name|erase
argument_list|(
name|SubH
argument_list|)
expr_stmt|;
name|compareLoops
argument_list|(
name|SubL
argument_list|,
name|OtherSubL
argument_list|,
name|OtherLoopHeaders
argument_list|)
expr_stmt|;
block|}
end_for

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|BlockT
operator|*
operator|>
name|BBs
operator|=
name|L
operator|->
name|getBlocks
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|BlockT
operator|*
operator|>
name|OtherBBs
operator|=
name|OtherL
operator|->
name|getBlocks
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|assert
argument_list|(
name|compareVectors
argument_list|(
name|BBs
argument_list|,
name|OtherBBs
argument_list|)
operator|&&
literal|"Mismatched basic blocks in the loops!"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_expr_stmt
unit|template
operator|<
name|class
name|BlockT
operator|,
name|class
name|LoopT
operator|>
name|void
name|LoopInfoBase
operator|<
name|BlockT
operator|,
name|LoopT
operator|>
operator|::
name|verify
argument_list|(
argument|const DominatorTreeBase<BlockT>&DomTree
argument_list|)
specifier|const
block|{
name|DenseSet
operator|<
specifier|const
name|LoopT
operator|*
operator|>
name|Loops
block|;
for|for
control|(
name|iterator
name|I
init|=
name|begin
argument_list|()
init|,
name|E
init|=
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
name|assert
argument_list|(
operator|!
operator|(
operator|*
name|I
operator|)
operator|->
name|getParentLoop
argument_list|()
operator|&&
literal|"Top-level loop has a parent!"
argument_list|)
expr_stmt|;
operator|(
operator|*
name|I
operator|)
operator|->
name|verifyLoopNest
argument_list|(
operator|&
name|Loops
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_comment
comment|// Verify that blocks are mapped to valid loops.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NDEBUG
end_ifndef

begin_for
for|for
control|(
name|auto
operator|&
name|Entry
operator|:
name|BBMap
control|)
block|{
specifier|const
name|BlockT
modifier|*
name|BB
init|=
name|Entry
operator|.
name|first
decl_stmt|;
name|LoopT
modifier|*
name|L
init|=
name|Entry
operator|.
name|second
decl_stmt|;
name|assert
argument_list|(
name|Loops
operator|.
name|count
argument_list|(
name|L
argument_list|)
operator|&&
literal|"orphaned loop"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|L
operator|->
name|contains
argument_list|(
name|BB
argument_list|)
operator|&&
literal|"orphaned block"
argument_list|)
expr_stmt|;
block|}
end_for

begin_comment
comment|// Recompute LoopInfo to verify loops structure.
end_comment

begin_expr_stmt
name|LoopInfoBase
operator|<
name|BlockT
operator|,
name|LoopT
operator|>
name|OtherLI
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|OtherLI
operator|.
name|analyze
argument_list|(
name|DomTree
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Build a map we can use to move from our LI to the computed one. This
end_comment

begin_comment
comment|// allows us to ignore the particular order in any layer of the loop forest
end_comment

begin_comment
comment|// while still comparing the structure.
end_comment

begin_expr_stmt
name|DenseMap
operator|<
name|BlockT
operator|*
operator|,
specifier|const
name|LoopT
operator|*
operator|>
name|OtherLoopHeaders
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
name|LoopT
modifier|*
name|L
range|:
name|OtherLI
control|)
name|addInnerLoopsToHeadersMap
argument_list|(
name|OtherLoopHeaders
argument_list|,
name|OtherLI
argument_list|,
operator|*
name|L
argument_list|)
expr_stmt|;
end_for

begin_comment
comment|// Walk the top level loops and ensure there is a corresponding top-level
end_comment

begin_comment
comment|// loop in the computed version and then recursively compare those loop
end_comment

begin_comment
comment|// nests.
end_comment

begin_for
for|for
control|(
name|LoopT
modifier|*
name|L
range|:
operator|*
name|this
control|)
block|{
name|BlockT
modifier|*
name|Header
init|=
name|L
operator|->
name|getHeader
argument_list|()
decl_stmt|;
specifier|const
name|LoopT
modifier|*
name|OtherL
init|=
name|OtherLoopHeaders
operator|.
name|lookup
argument_list|(
name|Header
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|OtherL
operator|&&
literal|"Top level loop is missing in computed loop info!"
argument_list|)
expr_stmt|;
comment|// Now that we've matched this loop, erase its header from the map.
name|OtherLoopHeaders
operator|.
name|erase
argument_list|(
name|Header
argument_list|)
expr_stmt|;
comment|// And recursively compare these loops.
name|compareLoops
argument_list|(
name|L
argument_list|,
name|OtherL
argument_list|,
name|OtherLoopHeaders
argument_list|)
expr_stmt|;
block|}
end_for

begin_comment
comment|// Any remaining entries in the map are loops which were found when computing
end_comment

begin_comment
comment|// a fresh LoopInfo but not present in the current one.
end_comment

begin_if
if|if
condition|(
operator|!
name|OtherLoopHeaders
operator|.
name|empty
argument_list|()
condition|)
block|{
for|for
control|(
specifier|const
specifier|auto
modifier|&
name|HeaderAndLoop
range|:
name|OtherLoopHeaders
control|)
name|dbgs
argument_list|()
operator|<<
literal|"Found new loop: "
operator|<<
operator|*
name|HeaderAndLoop
operator|.
name|second
operator|<<
literal|"\n"
expr_stmt|;
name|llvm_unreachable
argument_list|(
literal|"Found new loops when recomputing LoopInfo!"
argument_list|)
expr_stmt|;
block|}
end_if

begin_endif
endif|#
directive|endif
end_endif

begin_comment
unit|}  }
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

