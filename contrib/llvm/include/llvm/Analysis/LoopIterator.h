begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--------- LoopIterator.h - Iterate over loop blocks --------*- C++ -*-===//
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
comment|// This file defines iterators to visit the basic blocks within a loop.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// These iterators currently visit blocks within subloops as well.
end_comment

begin_comment
comment|// Unfortunately we have no efficient way of summarizing loop exits which would
end_comment

begin_comment
comment|// allow skipping subloops during traversal.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// If you want to visit all blocks in a loop and don't need an ordered traveral,
end_comment

begin_comment
comment|// use Loop::block_begin() instead.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This is intentionally designed to work with ill-formed loops in which the
end_comment

begin_comment
comment|// backedge has been deleted. The only prerequisite is that all blocks
end_comment

begin_comment
comment|// contained within the loop according to the most recent LoopInfo analysis are
end_comment

begin_comment
comment|// reachable from the loop header.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_ANALYSIS_LOOPITERATOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_LOOPITERATOR_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/PostOrderIterator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/LoopInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|LoopBlocksTraversal
decl_stmt|;
comment|/// Store the result of a depth first search within basic blocks contained by a
comment|/// single loop.
comment|///
comment|/// TODO: This could be generalized for any CFG region, or the entire CFG.
name|class
name|LoopBlocksDFS
block|{
name|public
label|:
comment|/// Postorder list iterators.
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|BasicBlock
operator|*
operator|>
operator|::
name|const_iterator
name|POIterator
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|BasicBlock
operator|*
operator|>
operator|::
name|const_reverse_iterator
name|RPOIterator
expr_stmt|;
name|friend
name|class
name|LoopBlocksTraversal
decl_stmt|;
name|private
label|:
name|Loop
modifier|*
name|L
decl_stmt|;
comment|/// Map each block to its postorder number. A block is only mapped after it is
comment|/// preorder visited by DFS. It's postorder number is initially zero and set
comment|/// to nonzero after it is finished by postorder traversal.
name|DenseMap
operator|<
name|BasicBlock
operator|*
operator|,
name|unsigned
operator|>
name|PostNumbers
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|BasicBlock
operator|*
operator|>
name|PostBlocks
expr_stmt|;
name|public
label|:
name|LoopBlocksDFS
argument_list|(
name|Loop
operator|*
name|Container
argument_list|)
operator|:
name|L
argument_list|(
name|Container
argument_list|)
operator|,
name|PostNumbers
argument_list|(
argument|NextPowerOf2(Container->getNumBlocks())
argument_list|)
block|{
name|PostBlocks
operator|.
name|reserve
argument_list|(
name|Container
operator|->
name|getNumBlocks
argument_list|()
argument_list|)
block|;   }
name|Loop
operator|*
name|getLoop
argument_list|()
specifier|const
block|{
return|return
name|L
return|;
block|}
comment|/// Traverse the loop blocks and store the DFS result.
name|void
name|perform
parameter_list|(
name|LoopInfo
modifier|*
name|LI
parameter_list|)
function_decl|;
comment|/// Return true if postorder numbers are assigned to all loop blocks.
name|bool
name|isComplete
argument_list|()
specifier|const
block|{
return|return
name|PostBlocks
operator|.
name|size
argument_list|()
operator|==
name|L
operator|->
name|getNumBlocks
argument_list|()
return|;
block|}
comment|/// Iterate over the cached postorder blocks.
name|POIterator
name|beginPostorder
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isComplete
argument_list|()
operator|&&
literal|"bad loop DFS"
argument_list|)
block|;
return|return
name|PostBlocks
operator|.
name|begin
argument_list|()
return|;
block|}
name|POIterator
name|endPostorder
argument_list|()
specifier|const
block|{
return|return
name|PostBlocks
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// Reverse iterate over the cached postorder blocks.
name|RPOIterator
name|beginRPO
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isComplete
argument_list|()
operator|&&
literal|"bad loop DFS"
argument_list|)
block|;
return|return
name|PostBlocks
operator|.
name|rbegin
argument_list|()
return|;
block|}
name|RPOIterator
name|endRPO
argument_list|()
specifier|const
block|{
return|return
name|PostBlocks
operator|.
name|rend
argument_list|()
return|;
block|}
comment|/// Return true if this block has been preorder visited.
name|bool
name|hasPreorder
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
block|{
return|return
name|PostNumbers
operator|.
name|count
argument_list|(
name|BB
argument_list|)
return|;
block|}
comment|/// Return true if this block has a postorder number.
name|bool
name|hasPostorder
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
block|{
name|DenseMap
operator|<
name|BasicBlock
operator|*
operator|,
name|unsigned
operator|>
operator|::
name|const_iterator
name|I
operator|=
name|PostNumbers
operator|.
name|find
argument_list|(
name|BB
argument_list|)
expr_stmt|;
return|return
name|I
operator|!=
name|PostNumbers
operator|.
name|end
argument_list|()
operator|&&
name|I
operator|->
name|second
return|;
block|}
comment|/// Get a block's postorder number.
name|unsigned
name|getPostorder
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
block|{
name|DenseMap
operator|<
name|BasicBlock
operator|*
operator|,
name|unsigned
operator|>
operator|::
name|const_iterator
name|I
operator|=
name|PostNumbers
operator|.
name|find
argument_list|(
name|BB
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|I
operator|!=
name|PostNumbers
operator|.
name|end
argument_list|()
operator|&&
literal|"block not visited by DFS"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|I
operator|->
name|second
operator|&&
literal|"block not finished by DFS"
argument_list|)
expr_stmt|;
return|return
name|I
operator|->
name|second
return|;
block|}
comment|/// Get a block's reverse postorder number.
name|unsigned
name|getRPO
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
block|{
return|return
literal|1
operator|+
name|PostBlocks
operator|.
name|size
argument_list|()
operator|-
name|getPostorder
argument_list|(
name|BB
argument_list|)
return|;
block|}
name|void
name|clear
parameter_list|()
block|{
name|PostNumbers
operator|.
name|clear
argument_list|()
expr_stmt|;
name|PostBlocks
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
block|}
empty_stmt|;
comment|/// Specialize po_iterator_storage to record postorder numbers.
name|template
operator|<
operator|>
name|class
name|po_iterator_storage
operator|<
name|LoopBlocksTraversal
operator|,
name|true
operator|>
block|{
name|LoopBlocksTraversal
operator|&
name|LBT
block|;
name|public
operator|:
name|po_iterator_storage
argument_list|(
name|LoopBlocksTraversal
operator|&
name|lbs
argument_list|)
operator|:
name|LBT
argument_list|(
argument|lbs
argument_list|)
block|{}
comment|// These functions are defined below.
name|bool
name|insertEdge
argument_list|(
name|BasicBlock
operator|*
name|From
argument_list|,
name|BasicBlock
operator|*
name|To
argument_list|)
block|;
name|void
name|finishPostorder
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|)
block|; }
expr_stmt|;
comment|/// Traverse the blocks in a loop using a depth-first search.
name|class
name|LoopBlocksTraversal
block|{
name|public
label|:
comment|/// Graph traversal iterator.
typedef|typedef
name|po_iterator
operator|<
name|BasicBlock
operator|*
operator|,
name|LoopBlocksTraversal
operator|,
name|true
operator|>
name|POTIterator
expr_stmt|;
name|private
label|:
name|LoopBlocksDFS
modifier|&
name|DFS
decl_stmt|;
name|LoopInfo
modifier|*
name|LI
decl_stmt|;
name|public
label|:
name|LoopBlocksTraversal
argument_list|(
name|LoopBlocksDFS
operator|&
name|Storage
argument_list|,
name|LoopInfo
operator|*
name|LInfo
argument_list|)
operator|:
name|DFS
argument_list|(
name|Storage
argument_list|)
operator|,
name|LI
argument_list|(
argument|LInfo
argument_list|)
block|{}
comment|/// Postorder traversal over the graph. This only needs to be done once.
comment|/// po_iterator "automatically" calls back to visitPreorder and
comment|/// finishPostorder to record the DFS result.
name|POTIterator
name|begin
argument_list|()
block|{
name|assert
argument_list|(
name|DFS
operator|.
name|PostBlocks
operator|.
name|empty
argument_list|()
operator|&&
literal|"Need clear DFS result before traversing"
argument_list|)
block|;
name|assert
argument_list|(
name|DFS
operator|.
name|L
operator|->
name|getNumBlocks
argument_list|()
operator|&&
literal|"po_iterator cannot handle an empty graph"
argument_list|)
block|;
return|return
name|po_ext_begin
argument_list|(
name|DFS
operator|.
name|L
operator|->
name|getHeader
argument_list|()
argument_list|,
operator|*
name|this
argument_list|)
return|;
block|}
name|POTIterator
name|end
parameter_list|()
block|{
comment|// po_ext_end interface requires a basic block, but ignores its value.
return|return
name|po_ext_end
argument_list|(
name|DFS
operator|.
name|L
operator|->
name|getHeader
argument_list|()
argument_list|,
operator|*
name|this
argument_list|)
return|;
block|}
comment|/// Called by po_iterator upon reaching a block via a CFG edge. If this block
comment|/// is contained in the loop and has not been visited, then mark it preorder
comment|/// visited and return true.
comment|///
comment|/// TODO: If anyone is interested, we could record preorder numbers here.
name|bool
name|visitPreorder
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
block|{
if|if
condition|(
operator|!
name|DFS
operator|.
name|L
operator|->
name|contains
argument_list|(
name|LI
operator|->
name|getLoopFor
argument_list|(
name|BB
argument_list|)
argument_list|)
condition|)
return|return
name|false
return|;
return|return
name|DFS
operator|.
name|PostNumbers
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|BB
argument_list|,
literal|0
argument_list|)
argument_list|)
operator|.
name|second
return|;
block|}
comment|/// Called by po_iterator each time it advances, indicating a block's
comment|/// postorder.
name|void
name|finishPostorder
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
block|{
name|assert
argument_list|(
name|DFS
operator|.
name|PostNumbers
operator|.
name|count
argument_list|(
name|BB
argument_list|)
operator|&&
literal|"Loop DFS skipped preorder"
argument_list|)
expr_stmt|;
name|DFS
operator|.
name|PostBlocks
operator|.
name|push_back
argument_list|(
name|BB
argument_list|)
expr_stmt|;
name|DFS
operator|.
name|PostNumbers
index|[
name|BB
index|]
operator|=
name|DFS
operator|.
name|PostBlocks
operator|.
name|size
argument_list|()
expr_stmt|;
block|}
block|}
empty_stmt|;
specifier|inline
name|bool
name|po_iterator_storage
operator|<
name|LoopBlocksTraversal
operator|,
name|true
operator|>
operator|::
name|insertEdge
argument_list|(
argument|BasicBlock *From
argument_list|,
argument|BasicBlock *To
argument_list|)
block|{
return|return
name|LBT
operator|.
name|visitPreorder
argument_list|(
name|To
argument_list|)
return|;
block|}
specifier|inline
name|void
name|po_iterator_storage
operator|<
name|LoopBlocksTraversal
operator|,
name|true
operator|>
operator|::
name|finishPostorder
argument_list|(
argument|BasicBlock *BB
argument_list|)
block|{
name|LBT
operator|.
name|finishPostorder
argument_list|(
name|BB
argument_list|)
block|; }
block|}
end_decl_stmt

begin_comment
comment|// End namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

