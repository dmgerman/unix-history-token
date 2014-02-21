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
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/Dominators.h"
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
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|void
name|RemoveFromVector
argument_list|(
argument|std::vector<T*>&V
argument_list|,
argument|T *N
argument_list|)
block|{
name|typename
name|std
operator|::
name|vector
operator|<
name|T
operator|*
operator|>
operator|::
name|iterator
name|I
operator|=
name|std
operator|::
name|find
argument_list|(
name|V
operator|.
name|begin
argument_list|()
argument_list|,
name|V
operator|.
name|end
argument_list|()
argument_list|,
name|N
argument_list|)
block|;
name|assert
argument_list|(
name|I
operator|!=
name|V
operator|.
name|end
argument_list|()
operator|&&
literal|"N is not in this list!"
argument_list|)
block|;
name|V
operator|.
name|erase
argument_list|(
name|I
argument_list|)
block|; }
name|class
name|DominatorTree
expr_stmt|;
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
comment|/// LoopBase class - Instances of this class are used to represent loops that
comment|/// are detected in the flow graph
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
comment|// SubLoops - Loops contained entirely within this one.
name|std
operator|::
name|vector
operator|<
name|LoopT
operator|*
operator|>
name|SubLoops
block|;
comment|// Blocks - The list of blocks in this loop.  First entry is the header node.
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
name|LoopBase
argument_list|(
argument|const LoopBase<BlockT
argument_list|,
argument|LoopT>&
argument_list|)
name|LLVM_DELETED_FUNCTION
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
name|LLVM_DELETED_FUNCTION
block|;
name|public
operator|:
comment|/// Loop ctor - This creates an empty loop.
name|LoopBase
argument_list|()
operator|:
name|ParentLoop
argument_list|(
literal|0
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
comment|/// getLoopDepth - Return the nesting level of this loop.  An outer-most
comment|/// loop has depth 1, for consistency with loop depth values used for basic
comment|/// blocks, where depth 0 is used for blocks not inside any loops.
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
comment|/// setParentLoop is a raw interface for bypassing addChildLoop.
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
comment|/// contains - Return true if the specified loop is contained within in
comment|/// this loop.
comment|///
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
name|L
operator|==
literal|0
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
comment|/// contains - Return true if the specified basic block is in this loop.
comment|///
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
comment|/// contains - Return true if the specified instruction is in this loop.
comment|///
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
comment|/// iterator/begin/end - Return the loops contained entirely within this loop.
comment|///
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
comment|/// getBlocks - Get a list of the basic blocks which make up this loop.
comment|///
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
comment|/// getNumBlocks - Get the number of blocks in this loop in constant time.
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
comment|/// isLoopExiting - True if terminator in the block can branch to another
comment|/// block that is outside of the current loop.
comment|///
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
comment|/// getNumBackEdges - Calculate the number of back edges to the loop header
comment|///
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
comment|/// getExitingBlocks - Return all blocks inside the loop that have successors
end_comment

begin_comment
comment|/// outside of the loop.  These are the blocks _inside of the current loop_
end_comment

begin_comment
comment|/// which branch out.  The returned list is always unique.
end_comment

begin_comment
comment|///
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
comment|/// getExitingBlock - If getExitingBlocks would return exactly one block,
end_comment

begin_comment
comment|/// return that block. Otherwise return null.
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
comment|/// getExitBlocks - Return all of the successor blocks of this loop.  These
end_comment

begin_comment
comment|/// are the blocks _outside of the current loop_ which are branched to.
end_comment

begin_comment
comment|///
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
comment|/// getExitBlock - If getExitBlocks would return exactly one block,
end_comment

begin_comment
comment|/// return that block. Otherwise return null.
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
comment|/// getExitEdges - Return all pairs of (_inside_block_,_outside_block_).
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
name|BlockT
operator|*
name|getLoopPreheader
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
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
name|BlockT
operator|*
name|getLoopPredecessor
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// getLoopLatch - If there is a single latch block for this loop, return it.
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
comment|//===--------------------------------------------------------------------===//
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
comment|/// addChildLoop - Add the specified loop to be a child of this loop.  This
end_comment

begin_comment
comment|/// updates the loop depth of the new child.
end_comment

begin_comment
comment|///
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
name|NewChild
operator|->
name|ParentLoop
operator|==
literal|0
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
comment|/// removeChildLoop - This removes the specified child from being a subloop of
end_comment

begin_comment
comment|/// this loop.  The loop is not deleted, as it will presumably be inserted
end_comment

begin_comment
comment|/// into another loop.
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
literal|0
expr_stmt|;
return|return
name|Child
return|;
block|}
end_function

begin_comment
comment|/// addBlockEntry - This adds a basic block directly to the basic block list.
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
comment|/// reverseBlocks - interface to reverse Blocks[from, end of loop] in this loop
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
comment|/// reserveBlocks- interface to do reserve() for Blocks
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
comment|/// moveToHeader - This method is used to move BB (which must be part of this
end_comment

begin_comment
comment|/// loop) to be the loop header of the loop (the block that dominates all
end_comment

begin_comment
comment|/// others).
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
comment|/// removeBlockFromLoop - This removes the specified basic block from the
end_comment

begin_comment
comment|/// current loop, updating the Blocks as appropriate.  This does not update
end_comment

begin_comment
comment|/// the mapping in the LoopInfo class.
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
name|RemoveFromVector
argument_list|(
name|Blocks
argument_list|,
name|BB
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
comment|/// verifyLoop - Verify loop structure
end_comment

begin_expr_stmt
name|void
name|verifyLoop
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// verifyLoop - Verify loop structure of this loop and all nested loops.
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
literal|0
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

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_expr_stmt
name|__extension__
specifier|extern
name|template
name|class
name|LoopBase
operator|<
name|BasicBlock
operator|,
name|Loop
operator|>
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

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
name|Loop
argument_list|()
block|{}
comment|/// isLoopInvariant - Return true if the specified value is loop invariant
comment|///
name|bool
name|isLoopInvariant
argument_list|(
name|Value
operator|*
name|V
argument_list|)
decl|const
decl_stmt|;
comment|/// hasLoopInvariantOperands - Return true if all the operands of the
comment|/// specified instruction are loop invariant.
name|bool
name|hasLoopInvariantOperands
argument_list|(
name|Instruction
operator|*
name|I
argument_list|)
decl|const
decl_stmt|;
comment|/// makeLoopInvariant - If the given value is an instruction inside of the
comment|/// loop and it can be hoisted, do so to make it trivially loop-invariant.
comment|/// Return true if the value after any hoisting is loop invariant. This
comment|/// function can be used as a slightly more aggressive replacement for
comment|/// isLoopInvariant.
comment|///
comment|/// If InsertPt is specified, it is the point to hoist instructions to.
comment|/// If null, the terminator of the loop preheader is used.
comment|///
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
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// makeLoopInvariant - If the given instruction is inside of the
comment|/// loop and it can be hoisted, do so to make it trivially loop-invariant.
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
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// getCanonicalInductionVariable - Check to see if the loop has a canonical
comment|/// induction variable: an integer recurrence that starts at 0 and increments
comment|/// by one each time through the loop.  If so, return the phi node that
comment|/// corresponds to it.
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
comment|/// isLCSSAForm - Return true if the Loop is in LCSSA form
name|bool
name|isLCSSAForm
argument_list|(
name|DominatorTree
operator|&
name|DT
argument_list|)
decl|const
decl_stmt|;
comment|/// isLoopSimplifyForm - Return true if the Loop is in the form that
comment|/// the LoopSimplify form transforms loops to, which is sometimes called
comment|/// normal form.
name|bool
name|isLoopSimplifyForm
argument_list|()
specifier|const
expr_stmt|;
comment|/// isSafeToClone - Return true if the loop body is safe to clone in practice.
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
comment|/// operand should should be the node itself.
name|void
name|setLoopID
argument_list|(
name|MDNode
operator|*
name|LoopID
argument_list|)
decl|const
decl_stmt|;
comment|/// hasDedicatedExits - Return true if no exit block for the loop
comment|/// has a predecessor that is outside the loop.
name|bool
name|hasDedicatedExits
argument_list|()
specifier|const
expr_stmt|;
comment|/// getUniqueExitBlocks - Return all unique successor blocks of this loop.
comment|/// These are the blocks _outside of the current loop_ which are branched to.
comment|/// This assumes that loop exits are in canonical form.
comment|///
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
comment|/// getUniqueExitBlock - If getUniqueExitBlocks would return exactly one
comment|/// block, return that block. Otherwise return null.
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
name|private
label|:
name|friend
name|class
name|LoopInfoBase
operator|<
name|BasicBlock
operator|,
name|Loop
operator|>
expr_stmt|;
name|explicit
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
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// LoopInfo - This class builds and contains all of the top level loop
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
name|LLVM_DELETED_FUNCTION
block|;
name|LoopInfoBase
argument_list|(
argument|const LoopInfo&
argument_list|)
name|LLVM_DELETED_FUNCTION
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
name|void
name|releaseMemory
argument_list|()
block|{
for|for
control|(
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
name|TopLevelLoops
operator|.
name|begin
argument_list|()
operator|,
name|E
operator|=
name|TopLevelLoops
operator|.
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
name|delete
modifier|*
name|I
decl_stmt|;
comment|// Delete all of the loops...
name|BBMap
operator|.
name|clear
argument_list|()
block|;
comment|// Reset internal state of analysis
name|TopLevelLoops
operator|.
name|clear
argument_list|()
block|;   }
end_expr_stmt

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
comment|/// getLoopFor - Return the inner most loop that BB lives in.  If a basic
end_comment

begin_comment
comment|/// block is in no loop (for example the entry node), null is returned.
end_comment

begin_comment
comment|///
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
name|const_cast
operator|<
name|BlockT
operator|*
operator|>
operator|(
name|BB
operator|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// operator[] - same as getLoopFor...
end_comment

begin_comment
comment|///
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
comment|/// getLoopDepth - Return the loop nesting level of the specified block.  A
end_comment

begin_comment
comment|/// depth of 0 means the block is not inside any loop.
end_comment

begin_comment
comment|///
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
comment|// isLoopHeader - True if the block is a loop header node
end_comment

begin_decl_stmt
name|bool
name|isLoopHeader
argument_list|(
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
comment|/// removeLoop - This removes the specified top-level loop from this loop info
end_comment

begin_comment
comment|/// object.  The loop is not deleted, as it will presumably be inserted into
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
name|L
operator|->
name|getParentLoop
argument_list|()
operator|==
literal|0
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
comment|/// changeLoopFor - Change the top-level loop that contains BB to the
end_comment

begin_comment
comment|/// specified loop.  This should be used by transformations that restructure
end_comment

begin_comment
comment|/// the loop hierarchy tree.
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
comment|/// changeTopLevelLoop - Replace the specified loop in the top-level loops
end_comment

begin_comment
comment|/// list with the indicated loop.
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
name|std
operator|::
name|find
argument_list|(
name|TopLevelLoops
operator|.
name|begin
argument_list|()
argument_list|,
name|TopLevelLoops
operator|.
name|end
argument_list|()
argument_list|,
name|OldLoop
argument_list|)
expr_stmt|;
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
name|NewLoop
operator|->
name|ParentLoop
operator|==
literal|0
operator|&&
name|OldLoop
operator|->
name|ParentLoop
operator|==
literal|0
operator|&&
literal|"Loops already embedded into a subloop!"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// addTopLevelLoop - This adds the specified loop to the collection of
end_comment

begin_comment
comment|/// top-level loops.
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
name|New
operator|->
name|getParentLoop
argument_list|()
operator|==
literal|0
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
comment|/// removeBlock - This method completely removes BB from all data structures,
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
name|typename
name|DenseMap
operator|<
name|BlockT
operator|*
operator|,
name|LoopT
operator|*
operator|>
operator|::
name|iterator
name|I
operator|=
name|BBMap
operator|.
name|find
argument_list|(
name|BB
argument_list|)
expr_stmt|;
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
name|SubLoop
operator|==
literal|0
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
name|Analyze
argument_list|(
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

begin_comment
unit|};
comment|// Implementation in LoopInfoImpl.h
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_expr_stmt
name|__extension__
specifier|extern
name|template
name|class
name|LoopInfoBase
operator|<
name|BasicBlock
operator|,
name|Loop
operator|>
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|class
name|LoopInfo
range|:
name|public
name|FunctionPass
block|{
name|LoopInfoBase
operator|<
name|BasicBlock
block|,
name|Loop
operator|>
name|LI
block|;
name|friend
name|class
name|LoopBase
operator|<
name|BasicBlock
block|,
name|Loop
operator|>
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|LoopInfo
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
block|;
name|LoopInfo
argument_list|(
argument|const LoopInfo&
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
comment|// Pass identification, replacement for typeid
name|LoopInfo
argument_list|()
operator|:
name|FunctionPass
argument_list|(
argument|ID
argument_list|)
block|{
name|initializeLoopInfoPass
argument_list|(
operator|*
name|PassRegistry
operator|::
name|getPassRegistry
argument_list|()
argument_list|)
block|;   }
name|LoopInfoBase
operator|<
name|BasicBlock
block|,
name|Loop
operator|>
operator|&
name|getBase
argument_list|()
block|{
return|return
name|LI
return|;
block|}
comment|/// iterator/begin/end - The interface to the top-level loops in the current
comment|/// function.
comment|///
typedef|typedef
name|LoopInfoBase
operator|<
name|BasicBlock
operator|,
name|Loop
operator|>
operator|::
name|iterator
name|iterator
expr_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|LoopInfoBase
operator|<
name|BasicBlock
operator|,
name|Loop
operator|>
operator|::
name|reverse_iterator
name|reverse_iterator
expr_stmt|;
end_typedef

begin_expr_stmt
specifier|inline
name|iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|LI
operator|.
name|begin
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|LI
operator|.
name|end
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|reverse_iterator
name|rbegin
argument_list|()
specifier|const
block|{
return|return
name|LI
operator|.
name|rbegin
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|reverse_iterator
name|rend
argument_list|()
specifier|const
block|{
return|return
name|LI
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
name|LI
operator|.
name|empty
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getLoopFor - Return the inner most loop that BB lives in.  If a basic
end_comment

begin_comment
comment|/// block is in no loop (for example the entry node), null is returned.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
specifier|inline
name|Loop
modifier|*
name|getLoopFor
argument_list|(
specifier|const
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
block|{
return|return
name|LI
operator|.
name|getLoopFor
argument_list|(
name|BB
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// operator[] - same as getLoopFor...
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
specifier|inline
specifier|const
name|Loop
modifier|*
name|operator
index|[]
argument_list|(
specifier|const
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
block|{
return|return
name|LI
operator|.
name|getLoopFor
argument_list|(
name|BB
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// getLoopDepth - Return the loop nesting level of the specified block.  A
end_comment

begin_comment
comment|/// depth of 0 means the block is not inside any loop.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
specifier|inline
name|unsigned
name|getLoopDepth
argument_list|(
specifier|const
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
block|{
return|return
name|LI
operator|.
name|getLoopDepth
argument_list|(
name|BB
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|// isLoopHeader - True if the block is a loop header node
end_comment

begin_decl_stmt
specifier|inline
name|bool
name|isLoopHeader
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
block|{
return|return
name|LI
operator|.
name|isLoopHeader
argument_list|(
name|BB
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// runOnFunction - Calculate the natural loop information.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
name|virtual
name|bool
name|runOnFunction
parameter_list|(
name|Function
modifier|&
name|F
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|virtual
name|void
name|verifyAnalysis
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_function
name|virtual
name|void
name|releaseMemory
parameter_list|()
block|{
name|LI
operator|.
name|releaseMemory
argument_list|()
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|virtual
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|O
argument_list|,
specifier|const
name|Module
operator|*
name|M
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|void
name|getAnalysisUsage
argument_list|(
name|AnalysisUsage
operator|&
name|AU
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// removeLoop - This removes the specified top-level loop from this loop info
end_comment

begin_comment
comment|/// object.  The loop is not deleted, as it will presumably be inserted into
end_comment

begin_comment
comment|/// another loop.
end_comment

begin_function
specifier|inline
name|Loop
modifier|*
name|removeLoop
parameter_list|(
name|iterator
name|I
parameter_list|)
block|{
return|return
name|LI
operator|.
name|removeLoop
argument_list|(
name|I
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// changeLoopFor - Change the top-level loop that contains BB to the
end_comment

begin_comment
comment|/// specified loop.  This should be used by transformations that restructure
end_comment

begin_comment
comment|/// the loop hierarchy tree.
end_comment

begin_function
specifier|inline
name|void
name|changeLoopFor
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|,
name|Loop
modifier|*
name|L
parameter_list|)
block|{
name|LI
operator|.
name|changeLoopFor
argument_list|(
name|BB
argument_list|,
name|L
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// changeTopLevelLoop - Replace the specified loop in the top-level loops
end_comment

begin_comment
comment|/// list with the indicated loop.
end_comment

begin_function
specifier|inline
name|void
name|changeTopLevelLoop
parameter_list|(
name|Loop
modifier|*
name|OldLoop
parameter_list|,
name|Loop
modifier|*
name|NewLoop
parameter_list|)
block|{
name|LI
operator|.
name|changeTopLevelLoop
argument_list|(
name|OldLoop
argument_list|,
name|NewLoop
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// addTopLevelLoop - This adds the specified loop to the collection of
end_comment

begin_comment
comment|/// top-level loops.
end_comment

begin_function
specifier|inline
name|void
name|addTopLevelLoop
parameter_list|(
name|Loop
modifier|*
name|New
parameter_list|)
block|{
name|LI
operator|.
name|addTopLevelLoop
argument_list|(
name|New
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// removeBlock - This method completely removes BB from all data structures,
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
name|BasicBlock
modifier|*
name|BB
parameter_list|)
block|{
name|LI
operator|.
name|removeBlock
argument_list|(
name|BB
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// updateUnloop - Update LoopInfo after removing the last backedge from a
end_comment

begin_comment
comment|/// loop--now the "unloop". This updates the loop forest and parent loops for
end_comment

begin_comment
comment|/// each block so that Unloop is no longer referenced, but the caller must
end_comment

begin_comment
comment|/// actually delete the Unloop object.
end_comment

begin_function_decl
name|void
name|updateUnloop
parameter_list|(
name|Loop
modifier|*
name|Unloop
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// replacementPreservesLCSSAForm - Returns true if replacing From with To
end_comment

begin_comment
comment|/// everywhere is guaranteed to preserve LCSSA form.
end_comment

begin_function
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
end_function

begin_comment
unit|};
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
name|NodeType
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
name|NodeType
modifier|*
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
name|Loop
operator|*
operator|>
block|{
typedef|typedef
name|Loop
name|NodeType
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
name|NodeType
modifier|*
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

begin_comment
unit|};  }
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

