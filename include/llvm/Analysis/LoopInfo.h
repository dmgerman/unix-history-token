begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Analysis/LoopInfo.h - Natural Loop Calculator -------*- C++ -*-===//
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
comment|// This file defines the LoopInfo class that is used to identify natural loops
end_comment

begin_comment
comment|// and determine the loop depth of various nodes of the CFG.  A natural loop
end_comment

begin_comment
comment|// has exactly one entry-point, which is called the header. Note that natural
end_comment

begin_comment
comment|// loops may actually be several loops that share the same header node.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This analysis calculates the nesting structure of loops in a function.  For
end_comment

begin_comment
comment|// each natural loop identified, this analysis identifies natural loops
end_comment

begin_comment
comment|// contained entirely within the loop and the basic blocks the make up the loop.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// It can calculate on the fly various bits of information, for example:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  * whether there is a preheader for the loop
end_comment

begin_comment
comment|//  * the number of back edges to the header
end_comment

begin_comment
comment|//  * whether or not a particular block branches out of the loop
end_comment

begin_comment
comment|//  * the successor blocks of the loop
end_comment

begin_comment
comment|//  * the loop depth
end_comment

begin_comment
comment|//  * etc...
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Note that this analysis specifically identifies *Loops* not cycles or SCCs
end_comment

begin_comment
comment|// in the CFG.  There can be strongly connected components in the CFG which
end_comment

begin_comment
comment|// this analysis will not recognize and that will not be represented by a Loop
end_comment

begin_comment
comment|// instance.  In particular, a Loop might be inside such a non-loop SCC, or a
end_comment

begin_comment
comment|// non-loop SCC might contain a sub-SCC which is a Loop.
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
name|LLVM_ANALYSIS_LOOPINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_LOOPINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
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
file|"llvm/IR/CFG.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Instruction.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Instructions.h"
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
file|<algorithm>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|DominatorTree
decl_stmt|;
name|class
name|LoopInfo
decl_stmt|;
name|class
name|Loop
decl_stmt|;
name|class
name|MDNode
decl_stmt|;
name|class
name|PHINode
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|template
operator|<
name|class
name|N
operator|>
name|class
name|DominatorTreeBase
expr_stmt|;
name|template
operator|<
name|class
name|N
operator|,
name|class
name|M
operator|>
name|class
name|LoopInfoBase
expr_stmt|;
name|template
operator|<
name|class
name|N
operator|,
name|class
name|M
operator|>
name|class
name|LoopBase
expr_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// Instances of this class are used to represent loops that are detected in the
comment|/// flow graph.
comment|///
name|template
operator|<
name|class
name|BlockT
operator|,
name|class
name|LoopT
operator|>
name|class
name|LoopBase
block|{
name|LoopT
operator|*
name|ParentLoop
block|;
comment|// Loops contained entirely within this one.
name|std
operator|::
name|vector
operator|<
name|LoopT
operator|*
operator|>
name|SubLoops
block|;
comment|// The list of blocks in this loop. First entry is the header node.
name|std
operator|::
name|vector
operator|<
name|BlockT
operator|*
operator|>
name|Blocks
block|;
name|SmallPtrSet
operator|<
specifier|const
name|BlockT
operator|*
block|,
literal|8
operator|>
name|DenseBlockSet
block|;
comment|/// Indicator that this loop is no longer a valid loop.
name|bool
name|IsInvalid
operator|=
name|false
block|;
name|LoopBase
argument_list|(
specifier|const
name|LoopBase
operator|<
name|BlockT
argument_list|,
name|LoopT
operator|>
operator|&
argument_list|)
operator|=
name|delete
block|;
specifier|const
name|LoopBase
operator|<
name|BlockT
block|,
name|LoopT
operator|>
operator|&
name|operator
operator|=
operator|(
specifier|const
name|LoopBase
operator|<
name|BlockT
operator|,
name|LoopT
operator|>
operator|&
operator|)
operator|=
name|delete
block|;
name|public
operator|:
comment|/// This creates an empty loop.
name|LoopBase
argument_list|()
operator|:
name|ParentLoop
argument_list|(
argument|nullptr
argument_list|)
block|{}
operator|~
name|LoopBase
argument_list|()
block|{
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|,
name|e
init|=
name|SubLoops
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
name|delete
name|SubLoops
index|[
name|i
index|]
decl_stmt|;
block|}
comment|/// Return the nesting level of this loop.  An outer-most loop has depth 1,
comment|/// for consistency with loop depth values used for basic blocks, where depth
comment|/// 0 is used for blocks not inside any loops.
name|unsigned
name|getLoopDepth
argument_list|()
specifier|const
block|{
name|unsigned
name|D
operator|=
literal|1
block|;
for|for
control|(
specifier|const
name|LoopT
modifier|*
name|CurLoop
init|=
name|ParentLoop
init|;
name|CurLoop
condition|;
name|CurLoop
operator|=
name|CurLoop
operator|->
name|ParentLoop
control|)
operator|++
name|D
expr_stmt|;
return|return
name|D
return|;
block|}
name|BlockT
operator|*
name|getHeader
argument_list|()
specifier|const
block|{
return|return
name|Blocks
operator|.
name|front
argument_list|()
return|;
block|}
name|LoopT
operator|*
name|getParentLoop
argument_list|()
specifier|const
block|{
return|return
name|ParentLoop
return|;
block|}
comment|/// This is a raw interface for bypassing addChildLoop.
name|void
name|setParentLoop
parameter_list|(
name|LoopT
modifier|*
name|L
parameter_list|)
block|{
name|ParentLoop
operator|=
name|L
expr_stmt|;
block|}
comment|/// Return true if the specified loop is contained within in this loop.
name|bool
name|contains
argument_list|(
specifier|const
name|LoopT
operator|*
name|L
argument_list|)
decl|const
block|{
if|if
condition|(
name|L
operator|==
name|this
condition|)
return|return
name|true
return|;
if|if
condition|(
operator|!
name|L
condition|)
return|return
name|false
return|;
return|return
name|contains
argument_list|(
name|L
operator|->
name|getParentLoop
argument_list|()
argument_list|)
return|;
block|}
comment|/// Return true if the specified basic block is in this loop.
name|bool
name|contains
argument_list|(
specifier|const
name|BlockT
operator|*
name|BB
argument_list|)
decl|const
block|{
return|return
name|DenseBlockSet
operator|.
name|count
argument_list|(
name|BB
argument_list|)
return|;
block|}
comment|/// Return true if the specified instruction is in this loop.
name|template
operator|<
name|class
name|InstT
operator|>
name|bool
name|contains
argument_list|(
argument|const InstT *Inst
argument_list|)
specifier|const
block|{
return|return
name|contains
argument_list|(
name|Inst
operator|->
name|getParent
argument_list|()
argument_list|)
return|;
block|}
comment|/// Return the loops contained entirely within this loop.
specifier|const
name|std
operator|::
name|vector
operator|<
name|LoopT
operator|*
operator|>
operator|&
name|getSubLoops
argument_list|()
specifier|const
block|{
return|return
name|SubLoops
return|;
block|}
name|std
operator|::
name|vector
operator|<
name|LoopT
operator|*
operator|>
operator|&
name|getSubLoopsVector
argument_list|()
block|{
return|return
name|SubLoops
return|;
block|}
typedef|typedef
name|typename
name|std
operator|::
name|vector
operator|<
name|LoopT
operator|*
operator|>
operator|::
name|const_iterator
name|iterator
expr_stmt|;
typedef|typedef
name|typename
name|std
operator|::
name|vector
operator|<
name|LoopT
operator|*
operator|>
operator|::
name|const_reverse_iterator
name|reverse_iterator
expr_stmt|;
name|iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|SubLoops
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|SubLoops
operator|.
name|end
argument_list|()
return|;
block|}
name|reverse_iterator
name|rbegin
argument_list|()
specifier|const
block|{
return|return
name|SubLoops
operator|.
name|rbegin
argument_list|()
return|;
block|}
name|reverse_iterator
name|rend
argument_list|()
specifier|const
block|{
return|return
name|SubLoops
operator|.
name|rend
argument_list|()
return|;
block|}
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|SubLoops
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// Get a list of the basic blocks which make up this loop.
specifier|const
name|std
operator|::
name|vector
operator|<
name|BlockT
operator|*
operator|>
operator|&
name|getBlocks
argument_list|()
specifier|const
block|{
return|return
name|Blocks
return|;
block|}
typedef|typedef
name|typename
name|std
operator|::
name|vector
operator|<
name|BlockT
operator|*
operator|>
operator|::
name|const_iterator
name|block_iterator
expr_stmt|;
name|block_iterator
name|block_begin
argument_list|()
specifier|const
block|{
return|return
name|Blocks
operator|.
name|begin
argument_list|()
return|;
block|}
name|block_iterator
name|block_end
argument_list|()
specifier|const
block|{
return|return
name|Blocks
operator|.
name|end
argument_list|()
return|;
block|}
specifier|inline
name|iterator_range
operator|<
name|block_iterator
operator|>
name|blocks
argument_list|()
specifier|const
block|{
return|return
name|make_range
argument_list|(
name|block_begin
argument_list|()
argument_list|,
name|block_end
argument_list|()
argument_list|)
return|;
block|}
comment|/// Get the number of blocks in this loop in constant time.
name|unsigned
name|getNumBlocks
argument_list|()
specifier|const
block|{
return|return
name|Blocks
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// Invalidate the loop, indicating that it is no longer a loop.
name|void
name|invalidate
parameter_list|()
block|{
name|IsInvalid
operator|=
name|true
expr_stmt|;
block|}
comment|/// Return true if this loop is no longer valid.
name|bool
name|isInvalid
parameter_list|()
block|{
return|return
name|IsInvalid
return|;
block|}
comment|/// True if terminator in the block can branch to another block that is
comment|/// outside of the current loop.
name|bool
name|isLoopExiting
argument_list|(
specifier|const
name|BlockT
operator|*
name|BB
argument_list|)
decl|const
block|{
typedef|typedef
name|GraphTraits
operator|<
specifier|const
name|BlockT
operator|*
operator|>
name|BlockTraits
expr_stmt|;
for|for
control|(
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
name|BB
argument_list|)
operator|,
name|SE
operator|=
name|BlockTraits
operator|::
name|child_end
argument_list|(
name|BB
argument_list|)
init|;
name|SI
operator|!=
name|SE
condition|;
operator|++
name|SI
control|)
block|{
if|if
condition|(
operator|!
name|contains
argument_list|(
operator|*
name|SI
argument_list|)
condition|)
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
comment|/// Returns true if \p BB is a loop-latch.
comment|/// A latch block is a block that contains a branch back to the header.
comment|/// This function is useful when there are multiple latches in a loop
comment|/// because \fn getLoopLatch will return nullptr in that case.
name|bool
name|isLoopLatch
argument_list|(
specifier|const
name|BlockT
operator|*
name|BB
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|contains
argument_list|(
name|BB
argument_list|)
operator|&&
literal|"block does not belong to the loop"
argument_list|)
expr_stmt|;
name|BlockT
modifier|*
name|Header
init|=
name|getHeader
argument_list|()
decl_stmt|;
name|auto
name|PredBegin
init|=
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
name|Header
argument_list|)
decl_stmt|;
name|auto
name|PredEnd
init|=
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
name|Header
argument_list|)
decl_stmt|;
return|return
name|std
operator|::
name|find
argument_list|(
name|PredBegin
argument_list|,
name|PredEnd
argument_list|,
name|BB
argument_list|)
operator|!=
name|PredEnd
return|;
block|}
comment|/// Calculate the number of back edges to the loop header.
name|unsigned
name|getNumBackEdges
argument_list|()
specifier|const
block|{
name|unsigned
name|NumBackEdges
operator|=
literal|0
block|;
name|BlockT
operator|*
name|H
operator|=
name|getHeader
argument_list|()
block|;
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
for|for
control|(
name|typename
name|InvBlockTraits
operator|::
name|ChildIteratorType
name|I
operator|=
name|InvBlockTraits
operator|::
name|child_begin
argument_list|(
name|H
argument_list|)
operator|,
name|E
operator|=
name|InvBlockTraits
operator|::
name|child_end
argument_list|(
name|H
argument_list|)
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
if|if
condition|(
name|contains
argument_list|(
operator|*
name|I
argument_list|)
condition|)
operator|++
name|NumBackEdges
expr_stmt|;
return|return
name|NumBackEdges
return|;
block|}
end_decl_stmt

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// APIs for simple analysis of the loop.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Note that all of these methods can fail on general loops (ie, there may not
end_comment

begin_comment
comment|// be a preheader, etc).  For best success, the loop simplification and
end_comment

begin_comment
comment|// induction variable canonicalization pass should be used to normalize loops
end_comment

begin_comment
comment|// for easy analysis.  These methods assume canonical loops.
end_comment

begin_comment
comment|/// Return all blocks inside the loop that have successors outside of the
end_comment

begin_comment
comment|/// loop. These are the blocks _inside of the current loop_ which branch out.
end_comment

begin_comment
comment|/// The returned list is always unique.
end_comment

begin_decl_stmt
name|void
name|getExitingBlocks
argument_list|(
name|SmallVectorImpl
operator|<
name|BlockT
operator|*
operator|>
operator|&
name|ExitingBlocks
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// If getExitingBlocks would return exactly one block, return that block.
end_comment

begin_comment
comment|/// Otherwise return null.
end_comment

begin_expr_stmt
name|BlockT
operator|*
name|getExitingBlock
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Return all of the successor blocks of this loop. These are the blocks
end_comment

begin_comment
comment|/// _outside of the current loop_ which are branched to.
end_comment

begin_decl_stmt
name|void
name|getExitBlocks
argument_list|(
name|SmallVectorImpl
operator|<
name|BlockT
operator|*
operator|>
operator|&
name|ExitBlocks
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// If getExitBlocks would return exactly one block, return that block.
end_comment

begin_comment
comment|/// Otherwise return null.
end_comment

begin_expr_stmt
name|BlockT
operator|*
name|getExitBlock
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Edge type.
end_comment

begin_typedef
typedef|typedef
name|std
operator|::
name|pair
operator|<
specifier|const
name|BlockT
operator|*
operator|,
specifier|const
name|BlockT
operator|*
operator|>
name|Edge
expr_stmt|;
end_typedef

begin_comment
comment|/// Return all pairs of (_inside_block_,_outside_block_).
end_comment

begin_decl_stmt
name|void
name|getExitEdges
argument_list|(
name|SmallVectorImpl
operator|<
name|Edge
operator|>
operator|&
name|ExitEdges
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// If there is a preheader for this loop, return it. A loop has a preheader
end_comment

begin_comment
comment|/// if there is only one edge to the header of the loop from outside of the
end_comment

begin_comment
comment|/// loop. If this is the case, the block branching to the header of the loop
end_comment

begin_comment
comment|/// is the preheader node.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This method returns null if there is no preheader for the loop.
end_comment

begin_expr_stmt
name|BlockT
operator|*
name|getLoopPreheader
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// If the given loop's header has exactly one unique predecessor outside the
end_comment

begin_comment
comment|/// loop, return it. Otherwise return null.
end_comment

begin_comment
comment|///  This is less strict that the loop "preheader" concept, which requires
end_comment

begin_comment
comment|/// the predecessor to have exactly one successor.
end_comment

begin_expr_stmt
name|BlockT
operator|*
name|getLoopPredecessor
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// If there is a single latch block for this loop, return it.
end_comment

begin_comment
comment|/// A latch block is a block that contains a branch back to the header.
end_comment

begin_expr_stmt
name|BlockT
operator|*
name|getLoopLatch
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Return all loop latch blocks of this loop. A latch block is a block that
end_comment

begin_comment
comment|/// contains a branch back to the header.
end_comment

begin_decl_stmt
name|void
name|getLoopLatches
argument_list|(
name|SmallVectorImpl
operator|<
name|BlockT
operator|*
operator|>
operator|&
name|LoopLatches
argument_list|)
decl|const
block|{
name|BlockT
modifier|*
name|H
init|=
name|getHeader
argument_list|()
decl_stmt|;
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
for|for
control|(
name|typename
name|InvBlockTraits
operator|::
name|ChildIteratorType
name|I
operator|=
name|InvBlockTraits
operator|::
name|child_begin
argument_list|(
name|H
argument_list|)
operator|,
name|E
operator|=
name|InvBlockTraits
operator|::
name|child_end
argument_list|(
name|H
argument_list|)
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
if|if
condition|(
name|contains
argument_list|(
operator|*
name|I
argument_list|)
condition|)
name|LoopLatches
operator|.
name|push_back
argument_list|(
operator|*
name|I
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// APIs for updating loop information after changing the CFG
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// This method is used by other analyses to update loop information.
end_comment

begin_comment
comment|/// NewBB is set to be a new member of the current loop.
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

begin_decl_stmt
name|void
name|addBasicBlockToLoop
argument_list|(
name|BlockT
operator|*
name|NewBB
argument_list|,
name|LoopInfoBase
operator|<
name|BlockT
argument_list|,
name|LoopT
operator|>
operator|&
name|LI
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// This is used when splitting loops up. It replaces the OldChild entry in
end_comment

begin_comment
comment|/// our children list with NewChild, and updates the parent pointer of
end_comment

begin_comment
comment|/// OldChild to be null and the NewChild to be this loop.
end_comment

begin_comment
comment|/// This updates the loop depth of the new child.
end_comment

begin_function_decl
name|void
name|replaceChildLoopWith
parameter_list|(
name|LoopT
modifier|*
name|OldChild
parameter_list|,
name|LoopT
modifier|*
name|NewChild
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Add the specified loop to be a child of this loop.
end_comment

begin_comment
comment|/// This updates the loop depth of the new child.
end_comment

begin_function
name|void
name|addChildLoop
parameter_list|(
name|LoopT
modifier|*
name|NewChild
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|NewChild
operator|->
name|ParentLoop
operator|&&
literal|"NewChild already has a parent!"
argument_list|)
expr_stmt|;
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
expr_stmt|;
name|SubLoops
operator|.
name|push_back
argument_list|(
name|NewChild
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// This removes the specified child from being a subloop of this loop. The
end_comment

begin_comment
comment|/// loop is not deleted, as it will presumably be inserted into another loop.
end_comment

begin_function
name|LoopT
modifier|*
name|removeChildLoop
parameter_list|(
name|iterator
name|I
parameter_list|)
block|{
name|assert
argument_list|(
name|I
operator|!=
name|SubLoops
operator|.
name|end
argument_list|()
operator|&&
literal|"Cannot remove end iterator!"
argument_list|)
expr_stmt|;
name|LoopT
modifier|*
name|Child
init|=
operator|*
name|I
decl_stmt|;
name|assert
argument_list|(
name|Child
operator|->
name|ParentLoop
operator|==
name|this
operator|&&
literal|"Child is not a child of this loop!"
argument_list|)
expr_stmt|;
name|SubLoops
operator|.
name|erase
argument_list|(
name|SubLoops
operator|.
name|begin
argument_list|()
operator|+
operator|(
name|I
operator|-
name|begin
argument_list|()
operator|)
argument_list|)
expr_stmt|;
name|Child
operator|->
name|ParentLoop
operator|=
name|nullptr
expr_stmt|;
return|return
name|Child
return|;
block|}
end_function

begin_comment
comment|/// This adds a basic block directly to the basic block list.
end_comment

begin_comment
comment|/// This should only be used by transformations that create new loops.  Other
end_comment

begin_comment
comment|/// transformations should use addBasicBlockToLoop.
end_comment

begin_function
name|void
name|addBlockEntry
parameter_list|(
name|BlockT
modifier|*
name|BB
parameter_list|)
block|{
name|Blocks
operator|.
name|push_back
argument_list|(
name|BB
argument_list|)
expr_stmt|;
name|DenseBlockSet
operator|.
name|insert
argument_list|(
name|BB
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// interface to reverse Blocks[from, end of loop] in this loop
end_comment

begin_function
name|void
name|reverseBlock
parameter_list|(
name|unsigned
name|from
parameter_list|)
block|{
name|std
operator|::
name|reverse
argument_list|(
name|Blocks
operator|.
name|begin
argument_list|()
operator|+
name|from
argument_list|,
name|Blocks
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// interface to do reserve() for Blocks
end_comment

begin_function
name|void
name|reserveBlocks
parameter_list|(
name|unsigned
name|size
parameter_list|)
block|{
name|Blocks
operator|.
name|reserve
argument_list|(
name|size
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// This method is used to move BB (which must be part of this loop) to be the
end_comment

begin_comment
comment|/// loop header of the loop (the block that dominates all others).
end_comment

begin_function
name|void
name|moveToHeader
parameter_list|(
name|BlockT
modifier|*
name|BB
parameter_list|)
block|{
if|if
condition|(
name|Blocks
index|[
literal|0
index|]
operator|==
name|BB
condition|)
return|return;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
condition|;
operator|++
name|i
control|)
block|{
name|assert
argument_list|(
name|i
operator|!=
name|Blocks
operator|.
name|size
argument_list|()
operator|&&
literal|"Loop does not contain BB!"
argument_list|)
expr_stmt|;
if|if
condition|(
name|Blocks
index|[
name|i
index|]
operator|==
name|BB
condition|)
block|{
name|Blocks
index|[
name|i
index|]
operator|=
name|Blocks
index|[
literal|0
index|]
expr_stmt|;
name|Blocks
index|[
literal|0
index|]
operator|=
name|BB
expr_stmt|;
return|return;
block|}
block|}
block|}
end_function

begin_comment
comment|/// This removes the specified basic block from the current loop, updating the
end_comment

begin_comment
comment|/// Blocks as appropriate. This does not update the mapping in the LoopInfo
end_comment

begin_comment
comment|/// class.
end_comment

begin_function
name|void
name|removeBlockFromLoop
parameter_list|(
name|BlockT
modifier|*
name|BB
parameter_list|)
block|{
name|auto
name|I
init|=
name|find
argument_list|(
name|Blocks
argument_list|,
name|BB
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|I
operator|!=
name|Blocks
operator|.
name|end
argument_list|()
operator|&&
literal|"N is not in this list!"
argument_list|)
expr_stmt|;
name|Blocks
operator|.
name|erase
argument_list|(
name|I
argument_list|)
expr_stmt|;
name|DenseBlockSet
operator|.
name|erase
argument_list|(
name|BB
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Verify loop structure
end_comment

begin_expr_stmt
name|void
name|verifyLoop
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Verify loop structure of this loop and all nested loops.
end_comment

begin_decl_stmt
name|void
name|verifyLoopNest
argument_list|(
name|DenseSet
operator|<
specifier|const
name|LoopT
operator|*
operator|>
operator|*
name|Loops
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Print loop with all the BBs inside it.
end_comment

begin_decl_stmt
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
name|unsigned
name|Depth
operator|=
literal|0
argument_list|,
name|bool
name|Verbose
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_label
name|protected
label|:
end_label

begin_expr_stmt
name|friend
name|class
name|LoopInfoBase
operator|<
name|BlockT
operator|,
name|LoopT
operator|>
expr_stmt|;
end_expr_stmt

begin_macro
name|explicit
end_macro

begin_expr_stmt
name|LoopBase
argument_list|(
name|BlockT
operator|*
name|BB
argument_list|)
operator|:
name|ParentLoop
argument_list|(
argument|nullptr
argument_list|)
block|{
name|Blocks
operator|.
name|push_back
argument_list|(
name|BB
argument_list|)
block|;
name|DenseBlockSet
operator|.
name|insert
argument_list|(
name|BB
argument_list|)
block|;   }
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|BlockT
operator|,
name|class
name|LoopT
operator|>
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
specifier|const
name|LoopBase
operator|<
name|BlockT
operator|,
name|LoopT
operator|>
operator|&
name|Loop
operator|)
block|{
name|Loop
operator|.
name|print
argument_list|(
name|OS
argument_list|)
block|;
return|return
name|OS
return|;
block|}
end_expr_stmt

begin_comment
comment|// Implementation in LoopInfoImpl.h
end_comment

begin_extern
extern|extern template class LoopBase<BasicBlock
operator|,
extern|Loop>;
end_extern

begin_comment
comment|/// Represents a single loop in the control flow graph.  Note that not all SCCs
end_comment

begin_comment
comment|/// in the CFG are necessarily loops.
end_comment

begin_decl_stmt
name|class
name|Loop
range|:
name|public
name|LoopBase
operator|<
name|BasicBlock
decl_stmt|,
name|Loop
decl|>
block|{
name|public
label|:
comment|/// \brief A range representing the start and end location of a loop.
name|class
name|LocRange
block|{
name|DebugLoc
name|Start
decl_stmt|;
name|DebugLoc
name|End
decl_stmt|;
name|public
label|:
name|LocRange
argument_list|()
block|{}
name|LocRange
argument_list|(
argument|DebugLoc Start
argument_list|)
block|:
name|Start
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Start
argument_list|)
argument_list|)
operator|,
name|End
argument_list|(
argument|std::move(Start)
argument_list|)
block|{}
name|LocRange
argument_list|(
argument|DebugLoc Start
argument_list|,
argument|DebugLoc End
argument_list|)
operator|:
name|Start
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Start
argument_list|)
argument_list|)
operator|,
name|End
argument_list|(
argument|std::move(End)
argument_list|)
block|{}
specifier|const
name|DebugLoc
operator|&
name|getStart
argument_list|()
specifier|const
block|{
return|return
name|Start
return|;
block|}
specifier|const
name|DebugLoc
operator|&
name|getEnd
argument_list|()
specifier|const
block|{
return|return
name|End
return|;
block|}
comment|/// \brief Check for null.
comment|///
name|explicit
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|Start
operator|&&
name|End
return|;
block|}
block|}
empty_stmt|;
name|Loop
argument_list|()
block|{}
comment|/// Return true if the specified value is loop invariant.
name|bool
name|isLoopInvariant
argument_list|(
specifier|const
name|Value
operator|*
name|V
argument_list|)
decl|const
decl_stmt|;
comment|/// Return true if all the operands of the specified instruction are loop
comment|/// invariant.
name|bool
name|hasLoopInvariantOperands
argument_list|(
specifier|const
name|Instruction
operator|*
name|I
argument_list|)
decl|const
decl_stmt|;
comment|/// If the given value is an instruction inside of the loop and it can be
comment|/// hoisted, do so to make it trivially loop-invariant.
comment|/// Return true if the value after any hoisting is loop invariant. This
comment|/// function can be used as a slightly more aggressive replacement for
comment|/// isLoopInvariant.
comment|///
comment|/// If InsertPt is specified, it is the point to hoist instructions to.
comment|/// If null, the terminator of the loop preheader is used.
name|bool
name|makeLoopInvariant
argument_list|(
name|Value
operator|*
name|V
argument_list|,
name|bool
operator|&
name|Changed
argument_list|,
name|Instruction
operator|*
name|InsertPt
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
comment|/// If the given instruction is inside of the loop and it can be hoisted, do
comment|/// so to make it trivially loop-invariant.
comment|/// Return true if the instruction after any hoisting is loop invariant. This
comment|/// function can be used as a slightly more aggressive replacement for
comment|/// isLoopInvariant.
comment|///
comment|/// If InsertPt is specified, it is the point to hoist instructions to.
comment|/// If null, the terminator of the loop preheader is used.
comment|///
name|bool
name|makeLoopInvariant
argument_list|(
name|Instruction
operator|*
name|I
argument_list|,
name|bool
operator|&
name|Changed
argument_list|,
name|Instruction
operator|*
name|InsertPt
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
comment|/// Check to see if the loop has a canonical induction variable: an integer
comment|/// recurrence that starts at 0 and increments by one each time through the
comment|/// loop. If so, return the phi node that corresponds to it.
comment|///
comment|/// The IndVarSimplify pass transforms loops to have a canonical induction
comment|/// variable.
comment|///
name|PHINode
operator|*
name|getCanonicalInductionVariable
argument_list|()
specifier|const
expr_stmt|;
comment|/// Return true if the Loop is in LCSSA form.
name|bool
name|isLCSSAForm
argument_list|(
name|DominatorTree
operator|&
name|DT
argument_list|)
decl|const
decl_stmt|;
comment|/// Return true if this Loop and all inner subloops are in LCSSA form.
name|bool
name|isRecursivelyLCSSAForm
argument_list|(
name|DominatorTree
operator|&
name|DT
argument_list|,
specifier|const
name|LoopInfo
operator|&
name|LI
argument_list|)
decl|const
decl_stmt|;
comment|/// Return true if the Loop is in the form that the LoopSimplify form
comment|/// transforms loops to, which is sometimes called normal form.
name|bool
name|isLoopSimplifyForm
argument_list|()
specifier|const
expr_stmt|;
comment|/// Return true if the loop body is safe to clone in practice.
name|bool
name|isSafeToClone
argument_list|()
specifier|const
expr_stmt|;
comment|/// Returns true if the loop is annotated parallel.
comment|///
comment|/// A parallel loop can be assumed to not contain any dependencies between
comment|/// iterations by the compiler. That is, any loop-carried dependency checking
comment|/// can be skipped completely when parallelizing the loop on the target
comment|/// machine. Thus, if the parallel loop information originates from the
comment|/// programmer, e.g. via the OpenMP parallel for pragma, it is the
comment|/// programmer's responsibility to ensure there are no loop-carried
comment|/// dependencies. The final execution order of the instructions across
comment|/// iterations is not guaranteed, thus, the end result might or might not
comment|/// implement actual concurrent execution of instructions across multiple
comment|/// iterations.
name|bool
name|isAnnotatedParallel
argument_list|()
specifier|const
expr_stmt|;
comment|/// Return the llvm.loop loop id metadata node for this loop if it is present.
comment|///
comment|/// If this loop contains the same llvm.loop metadata on each branch to the
comment|/// header then the node is returned. If any latch instruction does not
comment|/// contain llvm.loop or or if multiple latches contain different nodes then
comment|/// 0 is returned.
name|MDNode
operator|*
name|getLoopID
argument_list|()
specifier|const
expr_stmt|;
comment|/// Set the llvm.loop loop id metadata for this loop.
comment|///
comment|/// The LoopID metadata node will be added to each terminator instruction in
comment|/// the loop that branches to the loop header.
comment|///
comment|/// The LoopID metadata node should have one or more operands and the first
comment|/// operand should be the node itself.
name|void
name|setLoopID
argument_list|(
name|MDNode
operator|*
name|LoopID
argument_list|)
decl|const
decl_stmt|;
comment|/// Return true if no exit block for the loop has a predecessor that is
comment|/// outside the loop.
name|bool
name|hasDedicatedExits
argument_list|()
specifier|const
expr_stmt|;
comment|/// Return all unique successor blocks of this loop.
comment|/// These are the blocks _outside of the current loop_ which are branched to.
comment|/// This assumes that loop exits are in canonical form, i.e. all exits are
comment|/// dedicated exits.
name|void
name|getUniqueExitBlocks
argument_list|(
name|SmallVectorImpl
operator|<
name|BasicBlock
operator|*
operator|>
operator|&
name|ExitBlocks
argument_list|)
decl|const
decl_stmt|;
comment|/// If getUniqueExitBlocks would return exactly one block, return that block.
comment|/// Otherwise return null.
name|BasicBlock
operator|*
name|getUniqueExitBlock
argument_list|()
specifier|const
expr_stmt|;
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
name|void
name|dumpVerbose
argument_list|()
specifier|const
expr_stmt|;
comment|/// Return the debug location of the start of this loop.
comment|/// This looks for a BB terminating instruction with a known debug
comment|/// location by looking at the preheader and header blocks. If it
comment|/// cannot find a terminating instruction with location information,
comment|/// it returns an unknown location.
name|DebugLoc
name|getStartLoc
argument_list|()
specifier|const
expr_stmt|;
comment|/// Return the source code span of the loop.
name|LocRange
name|getLocRange
argument_list|()
specifier|const
expr_stmt|;
name|StringRef
name|getName
argument_list|()
specifier|const
block|{
if|if
condition|(
name|BasicBlock
modifier|*
name|Header
init|=
name|getHeader
argument_list|()
condition|)
if|if
condition|(
name|Header
operator|->
name|hasName
argument_list|()
condition|)
return|return
name|Header
operator|->
name|getName
argument_list|()
return|;
return|return
literal|"<unnamed loop>"
return|;
block|}
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|friend
name|class
name|LoopInfoBase
operator|<
name|BasicBlock
operator|,
name|Loop
operator|>
expr_stmt|;
end_expr_stmt

begin_macro
name|explicit
end_macro

begin_expr_stmt
name|Loop
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|)
operator|:
name|LoopBase
operator|<
name|BasicBlock
operator|,
name|Loop
operator|>
operator|(
name|BB
operator|)
block|{}
end_expr_stmt

begin_comment
unit|};
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// This class builds and contains all of the top-level loop
end_comment

begin_comment
comment|/// structures in the specified function.
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
name|class
name|LoopInfoBase
block|{
comment|// BBMap - Mapping of basic blocks to the inner most loop they occur in
name|DenseMap
operator|<
specifier|const
name|BlockT
operator|*
block|,
name|LoopT
operator|*
operator|>
name|BBMap
block|;
name|std
operator|::
name|vector
operator|<
name|LoopT
operator|*
operator|>
name|TopLevelLoops
block|;
name|std
operator|::
name|vector
operator|<
name|LoopT
operator|*
operator|>
name|RemovedLoops
block|;
name|friend
name|class
name|LoopBase
operator|<
name|BlockT
block|,
name|LoopT
operator|>
block|;
name|friend
name|class
name|LoopInfo
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|LoopInfoBase
operator|&
operator|)
operator|=
name|delete
block|;
name|LoopInfoBase
argument_list|(
specifier|const
name|LoopInfoBase
operator|&
argument_list|)
operator|=
name|delete
block|;
name|public
operator|:
name|LoopInfoBase
argument_list|()
block|{ }
operator|~
name|LoopInfoBase
argument_list|()
block|{
name|releaseMemory
argument_list|()
block|; }
name|LoopInfoBase
argument_list|(
name|LoopInfoBase
operator|&&
name|Arg
argument_list|)
operator|:
name|BBMap
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Arg
operator|.
name|BBMap
argument_list|)
argument_list|)
block|,
name|TopLevelLoops
argument_list|(
argument|std::move(Arg.TopLevelLoops)
argument_list|)
block|{
comment|// We have to clear the arguments top level loops as we've taken ownership.
name|Arg
operator|.
name|TopLevelLoops
operator|.
name|clear
argument_list|()
block|;   }
name|LoopInfoBase
operator|&
name|operator
operator|=
operator|(
name|LoopInfoBase
operator|&&
name|RHS
operator|)
block|{
name|BBMap
operator|=
name|std
operator|::
name|move
argument_list|(
name|RHS
operator|.
name|BBMap
argument_list|)
block|;
for|for
control|(
name|auto
operator|*
name|L
operator|:
name|TopLevelLoops
control|)
name|delete
name|L
decl_stmt|;
name|TopLevelLoops
operator|=
name|std
operator|::
name|move
argument_list|(
name|RHS
operator|.
name|TopLevelLoops
argument_list|)
block|;
name|RHS
operator|.
name|TopLevelLoops
operator|.
name|clear
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_function
name|void
name|releaseMemory
parameter_list|()
block|{
name|BBMap
operator|.
name|clear
argument_list|()
expr_stmt|;
for|for
control|(
name|auto
operator|*
name|L
operator|:
name|TopLevelLoops
control|)
name|delete
name|L
decl_stmt|;
name|TopLevelLoops
operator|.
name|clear
argument_list|()
expr_stmt|;
for|for
control|(
name|auto
operator|*
name|L
operator|:
name|RemovedLoops
control|)
name|delete
name|L
decl_stmt|;
name|RemovedLoops
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/// iterator/begin/end - The interface to the top-level loops in the current
end_comment

begin_comment
comment|/// function.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|typename
name|std
operator|::
name|vector
operator|<
name|LoopT
operator|*
operator|>
operator|::
name|const_iterator
name|iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|std
operator|::
name|vector
operator|<
name|LoopT
operator|*
operator|>
operator|::
name|const_reverse_iterator
name|reverse_iterator
expr_stmt|;
end_typedef

begin_expr_stmt
name|iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|TopLevelLoops
operator|.
name|begin
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|TopLevelLoops
operator|.
name|end
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|reverse_iterator
name|rbegin
argument_list|()
specifier|const
block|{
return|return
name|TopLevelLoops
operator|.
name|rbegin
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|reverse_iterator
name|rend
argument_list|()
specifier|const
block|{
return|return
name|TopLevelLoops
operator|.
name|rend
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|TopLevelLoops
operator|.
name|empty
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Return all of the loops in the function in preorder across the loop
end_comment

begin_comment
comment|/// nests, with siblings in forward program order.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that because loops form a forest of trees, preorder is equivalent to
end_comment

begin_comment
comment|/// reverse postorder.
end_comment

begin_expr_stmt
name|SmallVector
operator|<
name|LoopT
operator|*
operator|,
literal|4
operator|>
name|getLoopsInPreorder
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Return all of the loops in the function in preorder across the loop
end_comment

begin_comment
comment|/// nests, with siblings in *reverse* program order.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that because loops form a forest of trees, preorder is equivalent to
end_comment

begin_comment
comment|/// reverse postorder.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Also note that this is *not* a reverse preorder. Only the siblings are in
end_comment

begin_comment
comment|/// reverse program order.
end_comment

begin_expr_stmt
name|SmallVector
operator|<
name|LoopT
operator|*
operator|,
literal|4
operator|>
name|getLoopsInReverseSiblingPreorder
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Return the inner most loop that BB lives in. If a basic block is in no
end_comment

begin_comment
comment|/// loop (for example the entry node), null is returned.
end_comment

begin_decl_stmt
name|LoopT
modifier|*
name|getLoopFor
argument_list|(
specifier|const
name|BlockT
operator|*
name|BB
argument_list|)
decl|const
block|{
return|return
name|BBMap
operator|.
name|lookup
argument_list|(
name|BB
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Same as getLoopFor.
end_comment

begin_decl_stmt
specifier|const
name|LoopT
modifier|*
name|operator
index|[]
argument_list|(
specifier|const
name|BlockT
operator|*
name|BB
argument_list|)
decl|const
block|{
return|return
name|getLoopFor
argument_list|(
name|BB
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Return the loop nesting level of the specified block. A depth of 0 means
end_comment

begin_comment
comment|/// the block is not inside any loop.
end_comment

begin_decl_stmt
name|unsigned
name|getLoopDepth
argument_list|(
specifier|const
name|BlockT
operator|*
name|BB
argument_list|)
decl|const
block|{
specifier|const
name|LoopT
modifier|*
name|L
init|=
name|getLoopFor
argument_list|(
name|BB
argument_list|)
decl_stmt|;
return|return
name|L
condition|?
name|L
operator|->
name|getLoopDepth
argument_list|()
else|:
literal|0
return|;
block|}
end_decl_stmt

begin_comment
comment|// True if the block is a loop header node
end_comment

begin_decl_stmt
name|bool
name|isLoopHeader
argument_list|(
specifier|const
name|BlockT
operator|*
name|BB
argument_list|)
decl|const
block|{
specifier|const
name|LoopT
modifier|*
name|L
init|=
name|getLoopFor
argument_list|(
name|BB
argument_list|)
decl_stmt|;
return|return
name|L
operator|&&
name|L
operator|->
name|getHeader
argument_list|()
operator|==
name|BB
return|;
block|}
end_decl_stmt

begin_comment
comment|/// This removes the specified top-level loop from this loop info object.
end_comment

begin_comment
comment|/// The loop is not deleted, as it will presumably be inserted into
end_comment

begin_comment
comment|/// another loop.
end_comment

begin_function
name|LoopT
modifier|*
name|removeLoop
parameter_list|(
name|iterator
name|I
parameter_list|)
block|{
name|assert
argument_list|(
name|I
operator|!=
name|end
argument_list|()
operator|&&
literal|"Cannot remove end iterator!"
argument_list|)
expr_stmt|;
name|LoopT
modifier|*
name|L
init|=
operator|*
name|I
decl_stmt|;
name|assert
argument_list|(
operator|!
name|L
operator|->
name|getParentLoop
argument_list|()
operator|&&
literal|"Not a top-level loop!"
argument_list|)
expr_stmt|;
name|TopLevelLoops
operator|.
name|erase
argument_list|(
name|TopLevelLoops
operator|.
name|begin
argument_list|()
operator|+
operator|(
name|I
operator|-
name|begin
argument_list|()
operator|)
argument_list|)
expr_stmt|;
return|return
name|L
return|;
block|}
end_function

begin_comment
comment|/// Change the top-level loop that contains BB to the specified loop.
end_comment

begin_comment
comment|/// This should be used by transformations that restructure the loop hierarchy
end_comment

begin_comment
comment|/// tree.
end_comment

begin_function
name|void
name|changeLoopFor
parameter_list|(
name|BlockT
modifier|*
name|BB
parameter_list|,
name|LoopT
modifier|*
name|L
parameter_list|)
block|{
if|if
condition|(
operator|!
name|L
condition|)
block|{
name|BBMap
operator|.
name|erase
argument_list|(
name|BB
argument_list|)
expr_stmt|;
return|return;
block|}
name|BBMap
index|[
name|BB
index|]
operator|=
name|L
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Replace the specified loop in the top-level loops list with the indicated
end_comment

begin_comment
comment|/// loop.
end_comment

begin_function
name|void
name|changeTopLevelLoop
parameter_list|(
name|LoopT
modifier|*
name|OldLoop
parameter_list|,
name|LoopT
modifier|*
name|NewLoop
parameter_list|)
block|{
name|auto
name|I
init|=
name|find
argument_list|(
name|TopLevelLoops
argument_list|,
name|OldLoop
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|I
operator|!=
name|TopLevelLoops
operator|.
name|end
argument_list|()
operator|&&
literal|"Old loop not at top level!"
argument_list|)
expr_stmt|;
operator|*
name|I
operator|=
name|NewLoop
expr_stmt|;
name|assert
argument_list|(
operator|!
name|NewLoop
operator|->
name|ParentLoop
operator|&&
operator|!
name|OldLoop
operator|->
name|ParentLoop
operator|&&
literal|"Loops already embedded into a subloop!"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// This adds the specified loop to the collection of top-level loops.
end_comment

begin_function
name|void
name|addTopLevelLoop
parameter_list|(
name|LoopT
modifier|*
name|New
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|New
operator|->
name|getParentLoop
argument_list|()
operator|&&
literal|"Loop already in subloop!"
argument_list|)
expr_stmt|;
name|TopLevelLoops
operator|.
name|push_back
argument_list|(
name|New
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// This method completely removes BB from all data structures,
end_comment

begin_comment
comment|/// including all of the Loop objects it is nested in and our mapping from
end_comment

begin_comment
comment|/// BasicBlocks to loops.
end_comment

begin_function
name|void
name|removeBlock
parameter_list|(
name|BlockT
modifier|*
name|BB
parameter_list|)
block|{
name|auto
name|I
init|=
name|BBMap
operator|.
name|find
argument_list|(
name|BB
argument_list|)
decl_stmt|;
if|if
condition|(
name|I
operator|!=
name|BBMap
operator|.
name|end
argument_list|()
condition|)
block|{
for|for
control|(
name|LoopT
modifier|*
name|L
init|=
name|I
operator|->
name|second
init|;
name|L
condition|;
name|L
operator|=
name|L
operator|->
name|getParentLoop
argument_list|()
control|)
name|L
operator|->
name|removeBlockFromLoop
argument_list|(
name|BB
argument_list|)
expr_stmt|;
name|BBMap
operator|.
name|erase
argument_list|(
name|I
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|// Internals
end_comment

begin_function
specifier|static
name|bool
name|isNotAlreadyContainedIn
parameter_list|(
specifier|const
name|LoopT
modifier|*
name|SubLoop
parameter_list|,
specifier|const
name|LoopT
modifier|*
name|ParentLoop
parameter_list|)
block|{
if|if
condition|(
operator|!
name|SubLoop
condition|)
return|return
name|true
return|;
if|if
condition|(
name|SubLoop
operator|==
name|ParentLoop
condition|)
return|return
name|false
return|;
return|return
name|isNotAlreadyContainedIn
argument_list|(
name|SubLoop
operator|->
name|getParentLoop
argument_list|()
argument_list|,
name|ParentLoop
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// Create the loop forest using a stable algorithm.
end_comment

begin_decl_stmt
name|void
name|analyze
argument_list|(
specifier|const
name|DominatorTreeBase
operator|<
name|BlockT
operator|>
operator|&
name|DomTree
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Debugging
end_comment

begin_decl_stmt
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|verify
argument_list|(
specifier|const
name|DominatorTreeBase
operator|<
name|BlockT
operator|>
operator|&
name|DomTree
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|// Implementation in LoopInfoImpl.h
end_comment

begin_extern
extern|extern template class LoopInfoBase<BasicBlock
operator|,
extern|Loop>;
end_extern

begin_decl_stmt
name|class
name|LoopInfo
range|:
name|public
name|LoopInfoBase
operator|<
name|BasicBlock
decl_stmt|,
name|Loop
decl|>
block|{
typedef|typedef
name|LoopInfoBase
operator|<
name|BasicBlock
operator|,
name|Loop
operator|>
name|BaseT
expr_stmt|;
name|friend
name|class
name|LoopBase
operator|<
name|BasicBlock
operator|,
name|Loop
operator|>
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|LoopInfo
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|LoopInfo
argument_list|(
specifier|const
name|LoopInfo
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|public
label|:
name|LoopInfo
argument_list|()
block|{}
name|explicit
name|LoopInfo
argument_list|(
specifier|const
name|DominatorTreeBase
operator|<
name|BasicBlock
operator|>
operator|&
name|DomTree
argument_list|)
decl_stmt|;
name|LoopInfo
argument_list|(
name|LoopInfo
operator|&&
name|Arg
argument_list|)
operator|:
name|BaseT
argument_list|(
argument|std::move(static_cast<BaseT&>(Arg))
argument_list|)
block|{}
name|LoopInfo
operator|&
name|operator
operator|=
operator|(
name|LoopInfo
operator|&&
name|RHS
operator|)
block|{
name|BaseT
operator|::
name|operator
operator|=
operator|(
name|std
operator|::
name|move
argument_list|(
name|static_cast
operator|<
name|BaseT
operator|&
operator|>
operator|(
name|RHS
operator|)
argument_list|)
operator|)
block|;
return|return
operator|*
name|this
return|;
block|}
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
comment|// Most of the public interface is provided via LoopInfoBase.
comment|/// Update LoopInfo after removing the last backedge from a loop. This updates
comment|/// the loop forest and parent loops for each block so that \c L is no longer
comment|/// referenced, but does not actually delete \c L immediately. The pointer
comment|/// will remain valid until this LoopInfo's memory is released.
name|void
name|markAsRemoved
parameter_list|(
name|Loop
modifier|*
name|L
parameter_list|)
function_decl|;
comment|/// Returns true if replacing From with To everywhere is guaranteed to
comment|/// preserve LCSSA form.
name|bool
name|replacementPreservesLCSSAForm
parameter_list|(
name|Instruction
modifier|*
name|From
parameter_list|,
name|Value
modifier|*
name|To
parameter_list|)
block|{
comment|// Preserving LCSSA form is only problematic if the replacing value is an
comment|// instruction.
name|Instruction
modifier|*
name|I
init|=
name|dyn_cast
operator|<
name|Instruction
operator|>
operator|(
name|To
operator|)
decl_stmt|;
if|if
condition|(
operator|!
name|I
condition|)
return|return
name|true
return|;
comment|// If both instructions are defined in the same basic block then replacement
comment|// cannot break LCSSA form.
if|if
condition|(
name|I
operator|->
name|getParent
argument_list|()
operator|==
name|From
operator|->
name|getParent
argument_list|()
condition|)
return|return
name|true
return|;
comment|// If the instruction is not defined in a loop then it can safely replace
comment|// anything.
name|Loop
modifier|*
name|ToLoop
init|=
name|getLoopFor
argument_list|(
name|I
operator|->
name|getParent
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ToLoop
condition|)
return|return
name|true
return|;
comment|// If the replacing instruction is defined in the same loop as the original
comment|// instruction, or in a loop that contains it as an inner loop, then using
comment|// it as a replacement will not break LCSSA form.
return|return
name|ToLoop
operator|->
name|contains
argument_list|(
name|getLoopFor
argument_list|(
name|From
operator|->
name|getParent
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
comment|/// Checks if moving a specific instruction can break LCSSA in any loop.
comment|///
comment|/// Return true if moving \p Inst to before \p NewLoc will break LCSSA,
comment|/// assuming that the function containing \p Inst and \p NewLoc is currently
comment|/// in LCSSA form.
name|bool
name|movementPreservesLCSSAForm
parameter_list|(
name|Instruction
modifier|*
name|Inst
parameter_list|,
name|Instruction
modifier|*
name|NewLoc
parameter_list|)
block|{
name|assert
argument_list|(
name|Inst
operator|->
name|getFunction
argument_list|()
operator|==
name|NewLoc
operator|->
name|getFunction
argument_list|()
operator|&&
literal|"Can't reason about IPO!"
argument_list|)
expr_stmt|;
name|auto
operator|*
name|OldBB
operator|=
name|Inst
operator|->
name|getParent
argument_list|()
expr_stmt|;
name|auto
operator|*
name|NewBB
operator|=
name|NewLoc
operator|->
name|getParent
argument_list|()
expr_stmt|;
comment|// Movement within the same loop does not break LCSSA (the equality check is
comment|// to avoid doing a hashtable lookup in case of intra-block movement).
if|if
condition|(
name|OldBB
operator|==
name|NewBB
condition|)
return|return
name|true
return|;
name|auto
operator|*
name|OldLoop
operator|=
name|getLoopFor
argument_list|(
name|OldBB
argument_list|)
expr_stmt|;
name|auto
operator|*
name|NewLoop
operator|=
name|getLoopFor
argument_list|(
name|NewBB
argument_list|)
expr_stmt|;
if|if
condition|(
name|OldLoop
operator|==
name|NewLoop
condition|)
return|return
name|true
return|;
comment|// Check if Outer contains Inner; with the null loop counting as the
comment|// "outermost" loop.
name|auto
name|Contains
init|=
index|[]
operator|(
specifier|const
name|Loop
operator|*
name|Outer
expr|,
specifier|const
name|Loop
operator|*
name|Inner
operator|)
block|{
return|return
operator|!
name|Outer
operator|||
name|Outer
operator|->
name|contains
argument_list|(
name|Inner
argument_list|)
return|;
block|}
empty_stmt|;
comment|// To check that the movement of Inst to before NewLoc does not break LCSSA,
comment|// we need to check two sets of uses for possible LCSSA violations at
comment|// NewLoc: the users of NewInst, and the operands of NewInst.
comment|// If we know we're hoisting Inst out of an inner loop to an outer loop,
comment|// then the uses *of* Inst don't need to be checked.
if|if
condition|(
operator|!
name|Contains
argument_list|(
name|NewLoop
argument_list|,
name|OldLoop
argument_list|)
condition|)
block|{
for|for
control|(
name|Use
modifier|&
name|U
range|:
name|Inst
operator|->
name|uses
argument_list|()
control|)
block|{
name|auto
operator|*
name|UI
operator|=
name|cast
operator|<
name|Instruction
operator|>
operator|(
name|U
operator|.
name|getUser
argument_list|()
operator|)
expr_stmt|;
name|auto
operator|*
name|UBB
operator|=
name|isa
operator|<
name|PHINode
operator|>
operator|(
name|UI
operator|)
condition|?
name|cast
operator|<
name|PHINode
operator|>
operator|(
name|UI
operator|)
operator|->
name|getIncomingBlock
argument_list|(
name|U
argument_list|)
else|:
name|UI
operator|->
name|getParent
argument_list|()
expr_stmt|;
if|if
condition|(
name|UBB
operator|!=
name|NewBB
operator|&&
name|getLoopFor
argument_list|(
name|UBB
argument_list|)
operator|!=
name|NewLoop
condition|)
return|return
name|false
return|;
block|}
block|}
comment|// If we know we're sinking Inst from an outer loop into an inner loop, then
comment|// the *operands* of Inst don't need to be checked.
if|if
condition|(
operator|!
name|Contains
argument_list|(
name|OldLoop
argument_list|,
name|NewLoop
argument_list|)
condition|)
block|{
comment|// See below on why we can't handle phi nodes here.
if|if
condition|(
name|isa
operator|<
name|PHINode
operator|>
operator|(
name|Inst
operator|)
condition|)
return|return
name|false
return|;
for|for
control|(
name|Use
modifier|&
name|U
range|:
name|Inst
operator|->
name|operands
argument_list|()
control|)
block|{
name|auto
operator|*
name|DefI
operator|=
name|dyn_cast
operator|<
name|Instruction
operator|>
operator|(
name|U
operator|.
name|get
argument_list|()
operator|)
expr_stmt|;
if|if
condition|(
operator|!
name|DefI
condition|)
return|return
name|false
return|;
comment|// This would need adjustment if we allow Inst to be a phi node -- the
comment|// new use block won't simply be NewBB.
name|auto
operator|*
name|DefBlock
operator|=
name|DefI
operator|->
name|getParent
argument_list|()
expr_stmt|;
if|if
condition|(
name|DefBlock
operator|!=
name|NewBB
operator|&&
name|getLoopFor
argument_list|(
name|DefBlock
argument_list|)
operator|!=
name|NewLoop
condition|)
return|return
name|false
return|;
block|}
block|}
return|return
name|true
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Allow clients to walk the list of nested loops...
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|GraphTraits
operator|<
specifier|const
name|Loop
operator|*
operator|>
block|{
typedef|typedef
specifier|const
name|Loop
modifier|*
name|NodeRef
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|LoopInfo
operator|::
name|iterator
name|ChildIteratorType
expr_stmt|;
end_typedef

begin_function
specifier|static
name|NodeRef
name|getEntryNode
parameter_list|(
specifier|const
name|Loop
modifier|*
name|L
parameter_list|)
block|{
return|return
name|L
return|;
block|}
end_function

begin_function
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
end_function

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

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|GraphTraits
operator|<
name|Loop
operator|*
operator|>
block|{
typedef|typedef
name|Loop
modifier|*
name|NodeRef
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|LoopInfo
operator|::
name|iterator
name|ChildIteratorType
expr_stmt|;
end_typedef

begin_function
specifier|static
name|NodeRef
name|getEntryNode
parameter_list|(
name|Loop
modifier|*
name|L
parameter_list|)
block|{
return|return
name|L
return|;
block|}
end_function

begin_function
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
end_function

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

begin_comment
unit|};
comment|/// \brief Analysis pass that exposes the \c LoopInfo for a function.
end_comment

begin_decl_stmt
name|class
name|LoopAnalysis
range|:
name|public
name|AnalysisInfoMixin
operator|<
name|LoopAnalysis
operator|>
block|{
name|friend
name|AnalysisInfoMixin
operator|<
name|LoopAnalysis
operator|>
block|;
specifier|static
name|AnalysisKey
name|Key
block|;
name|public
operator|:
typedef|typedef
name|LoopInfo
name|Result
typedef|;
name|LoopInfo
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
comment|/// \brief Printer pass for the \c LoopAnalysis results.
end_comment

begin_decl_stmt
name|class
name|LoopPrinterPass
range|:
name|public
name|PassInfoMixin
operator|<
name|LoopPrinterPass
operator|>
block|{
name|raw_ostream
operator|&
name|OS
block|;
name|public
operator|:
name|explicit
name|LoopPrinterPass
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
operator|:
name|OS
argument_list|(
argument|OS
argument_list|)
block|{}
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
comment|/// \brief Verifier pass for the \c LoopAnalysis results.
end_comment

begin_decl_stmt
name|struct
name|LoopVerifierPass
range|:
name|public
name|PassInfoMixin
operator|<
name|LoopVerifierPass
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
comment|/// \brief The legacy pass manager's analysis pass to compute loop information.
end_comment

begin_decl_stmt
name|class
name|LoopInfoWrapperPass
range|:
name|public
name|FunctionPass
block|{
name|LoopInfo
name|LI
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
comment|// Pass identification, replacement for typeid
name|LoopInfoWrapperPass
argument_list|()
operator|:
name|FunctionPass
argument_list|(
argument|ID
argument_list|)
block|{
name|initializeLoopInfoWrapperPassPass
argument_list|(
operator|*
name|PassRegistry
operator|::
name|getPassRegistry
argument_list|()
argument_list|)
block|;   }
name|LoopInfo
operator|&
name|getLoopInfo
argument_list|()
block|{
return|return
name|LI
return|;
block|}
specifier|const
name|LoopInfo
operator|&
name|getLoopInfo
argument_list|()
specifier|const
block|{
return|return
name|LI
return|;
block|}
comment|/// \brief Calculate the natural loop information for a given function.
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
name|releaseMemory
argument_list|()
name|override
block|{
name|LI
operator|.
name|releaseMemory
argument_list|()
block|; }
name|void
name|print
argument_list|(
argument|raw_ostream&O
argument_list|,
argument|const Module *M = nullptr
argument_list|)
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
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Function to print a loop's contents as LLVM's text IR assembly.
end_comment

begin_decl_stmt
name|void
name|printLoop
argument_list|(
name|Loop
operator|&
name|L
argument_list|,
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|Banner
operator|=
literal|""
argument_list|)
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

