begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- IntervalIterator.h - Interval Iterator Declaration -------*- C++ -*-===//
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
comment|// This file defines an iterator that enumerates the intervals in a control flow
end_comment

begin_comment
comment|// graph of some sort.  This iterator is parametric, allowing iterator over the
end_comment

begin_comment
comment|// following types of graphs:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  1. A Function* object, composed of BasicBlock nodes.
end_comment

begin_comment
comment|//  2. An IntervalPartition& object, composed of Interval nodes.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This iterator is defined to walk the control flow graph, returning intervals
end_comment

begin_comment
comment|// in depth first order.  These intervals are completely filled in except for
end_comment

begin_comment
comment|// the predecessor fields (the successor information is filled in however).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// By default, the intervals created by this iterator are deleted after they
end_comment

begin_comment
comment|// are no longer any use to the iterator.  This behavior can be changed by
end_comment

begin_comment
comment|// passing a false value into the intervals_begin() function. This causes the
end_comment

begin_comment
comment|// IOwnMem member to be set, and the intervals to not be deleted.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// It is only safe to use this if all of the intervals are deleted by the caller
end_comment

begin_comment
comment|// and all of the intervals are processed.  However, the user of the iterator is
end_comment

begin_comment
comment|// not allowed to modify or delete the intervals until after the iterator has
end_comment

begin_comment
comment|// been used completely.  The IntervalPartition class uses this functionality.
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
name|LLVM_ANALYSIS_INTERVALITERATOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_INTERVALITERATOR_H
end_define

begin_include
include|#
directive|include
file|"llvm/Analysis/IntervalPartition.h"
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
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<set>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// getNodeHeader - Given a source graph node and the source graph, return the
comment|// BasicBlock that is the header node.  This is the opposite of
comment|// getSourceGraphNode.
comment|//
specifier|inline
name|BasicBlock
modifier|*
name|getNodeHeader
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
block|{
return|return
name|BB
return|;
block|}
specifier|inline
name|BasicBlock
modifier|*
name|getNodeHeader
parameter_list|(
name|Interval
modifier|*
name|I
parameter_list|)
block|{
return|return
name|I
operator|->
name|getHeaderNode
argument_list|()
return|;
block|}
comment|// getSourceGraphNode - Given a BasicBlock and the source graph, return the
comment|// source graph node that corresponds to the BasicBlock.  This is the opposite
comment|// of getNodeHeader.
comment|//
specifier|inline
name|BasicBlock
modifier|*
name|getSourceGraphNode
parameter_list|(
name|Function
modifier|*
parameter_list|,
name|BasicBlock
modifier|*
name|BB
parameter_list|)
block|{
return|return
name|BB
return|;
block|}
specifier|inline
name|Interval
modifier|*
name|getSourceGraphNode
parameter_list|(
name|IntervalPartition
modifier|*
name|IP
parameter_list|,
name|BasicBlock
modifier|*
name|BB
parameter_list|)
block|{
return|return
name|IP
operator|->
name|getBlockInterval
argument_list|(
name|BB
argument_list|)
return|;
block|}
comment|// addNodeToInterval - This method exists to assist the generic ProcessNode
comment|// with the task of adding a node to the new interval, depending on the
comment|// type of the source node.  In the case of a CFG source graph (BasicBlock
comment|// case), the BasicBlock itself is added to the interval.
comment|//
specifier|inline
name|void
name|addNodeToInterval
parameter_list|(
name|Interval
modifier|*
name|Int
parameter_list|,
name|BasicBlock
modifier|*
name|BB
parameter_list|)
block|{
name|Int
operator|->
name|Nodes
operator|.
name|push_back
argument_list|(
name|BB
argument_list|)
expr_stmt|;
block|}
comment|// addNodeToInterval - This method exists to assist the generic ProcessNode
comment|// with the task of adding a node to the new interval, depending on the
comment|// type of the source node.  In the case of a CFG source graph (BasicBlock
comment|// case), the BasicBlock itself is added to the interval.  In the case of
comment|// an IntervalPartition source graph (Interval case), all of the member
comment|// BasicBlocks are added to the interval.
comment|//
specifier|inline
name|void
name|addNodeToInterval
parameter_list|(
name|Interval
modifier|*
name|Int
parameter_list|,
name|Interval
modifier|*
name|I
parameter_list|)
block|{
comment|// Add all of the nodes in I as new nodes in Int.
name|copy
argument_list|(
name|I
operator|->
name|Nodes
operator|.
name|begin
argument_list|()
argument_list|,
name|I
operator|->
name|Nodes
operator|.
name|end
argument_list|()
argument_list|,
name|back_inserter
argument_list|(
name|Int
operator|->
name|Nodes
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|template
operator|<
name|class
name|NodeTy
operator|,
name|class
name|OrigContainer_t
operator|,
name|class
name|GT
operator|=
name|GraphTraits
operator|<
name|NodeTy
operator|*
operator|>
operator|,
name|class
name|IGT
operator|=
name|GraphTraits
operator|<
name|Inverse
operator|<
name|NodeTy
operator|*
operator|>
expr|>
operator|>
name|class
name|IntervalIterator
block|{
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|Interval
operator|*
block|,
name|typename
name|Interval
operator|::
name|succ_iterator
operator|>
expr|>
name|IntStack
block|;
name|std
operator|::
name|set
operator|<
name|BasicBlock
operator|*
operator|>
name|Visited
block|;
name|OrigContainer_t
operator|*
name|OrigContainer
block|;
name|bool
name|IOwnMem
block|;
comment|// If True, delete intervals when done with them
comment|// See file header for conditions of use
name|public
operator|:
typedef|typedef
name|IntervalIterator
operator|<
name|NodeTy
operator|,
name|OrigContainer_t
operator|>
name|_Self
expr_stmt|;
typedef|typedef
name|std
operator|::
name|forward_iterator_tag
name|iterator_category
expr_stmt|;
name|IntervalIterator
argument_list|()
block|{}
comment|// End iterator, empty stack
name|IntervalIterator
argument_list|(
argument|Function *M
argument_list|,
argument|bool OwnMemory
argument_list|)
block|:
name|IOwnMem
argument_list|(
argument|OwnMemory
argument_list|)
block|{
name|OrigContainer
operator|=
name|M
expr_stmt|;
if|if
condition|(
operator|!
name|ProcessInterval
argument_list|(
operator|&
name|M
operator|->
name|front
argument_list|()
argument_list|)
condition|)
block|{
name|llvm_unreachable
argument_list|(
literal|"ProcessInterval should never fail for first interval!"
argument_list|)
expr_stmt|;
block|}
block|}
name|IntervalIterator
argument_list|(
argument|IntervalPartition&IP
argument_list|,
argument|bool OwnMemory
argument_list|)
block|:
name|IOwnMem
argument_list|(
argument|OwnMemory
argument_list|)
block|{
name|OrigContainer
operator|=
operator|&
name|IP
expr_stmt|;
if|if
condition|(
operator|!
name|ProcessInterval
argument_list|(
name|IP
operator|.
name|getRootInterval
argument_list|()
argument_list|)
condition|)
block|{
name|llvm_unreachable
argument_list|(
literal|"ProcessInterval should never fail for first interval!"
argument_list|)
expr_stmt|;
block|}
block|}
specifier|inline
operator|~
name|IntervalIterator
argument_list|()
block|{
if|if
condition|(
name|IOwnMem
condition|)
while|while
condition|(
operator|!
name|IntStack
operator|.
name|empty
argument_list|()
condition|)
block|{
name|delete
name|operator
function_decl|*();
name|IntStack
operator|.
name|pop_back
argument_list|()
expr_stmt|;
block|}
block|}
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|_Self
operator|&
name|x
operator|)
specifier|const
block|{
return|return
name|IntStack
operator|==
name|x
operator|.
name|IntStack
return|;
block|}
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|_Self
operator|&
name|x
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|x
operator|)
return|;
block|}
specifier|inline
specifier|const
name|Interval
operator|*
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|IntStack
operator|.
name|back
argument_list|()
operator|.
name|first
return|;
block|}
specifier|inline
name|Interval
modifier|*
name|operator
modifier|*
parameter_list|()
block|{
return|return
name|IntStack
operator|.
name|back
argument_list|()
operator|.
name|first
return|;
block|}
specifier|inline
specifier|const
name|Interval
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
name|operator
operator|*
operator|(
operator|)
return|;
block|}
end_decl_stmt

begin_expr_stmt
specifier|inline
name|Interval
operator|*
name|operator
operator|->
expr|(
end_expr_stmt

begin_block
unit|)
block|{
return|return
name|operator
operator|*
operator|(
operator|)
return|;
block|}
end_block

begin_expr_stmt
name|_Self
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
comment|// Preincrement
name|assert
argument_list|(
operator|!
name|IntStack
operator|.
name|empty
argument_list|()
operator|&&
literal|"Attempting to use interval iterator at end!"
argument_list|)
block|;
do|do
block|{
comment|// All of the intervals on the stack have been visited.  Try visiting
comment|// their successors now.
name|Interval
operator|::
name|succ_iterator
operator|&
name|SuccIt
operator|=
name|IntStack
operator|.
name|back
argument_list|()
operator|.
name|second
operator|,
name|EndIt
operator|=
name|succ_end
argument_list|(
name|IntStack
operator|.
name|back
argument_list|()
operator|.
name|first
argument_list|)
expr_stmt|;
while|while
condition|(
name|SuccIt
operator|!=
name|EndIt
condition|)
block|{
comment|// Loop over all interval succs
name|bool
name|Done
init|=
name|ProcessInterval
argument_list|(
name|getSourceGraphNode
argument_list|(
name|OrigContainer
argument_list|,
operator|*
name|SuccIt
argument_list|)
argument_list|)
decl_stmt|;
operator|++
name|SuccIt
expr_stmt|;
comment|// Increment iterator
if|if
condition|(
name|Done
condition|)
return|return
operator|*
name|this
return|;
comment|// Found a new interval! Use it!
block|}
end_expr_stmt

begin_comment
comment|// Free interval memory... if necessary
end_comment

begin_if
if|if
condition|(
name|IOwnMem
condition|)
name|delete
name|IntStack
operator|.
name|back
argument_list|()
operator|.
name|first
expr_stmt|;
end_if

begin_comment
comment|// We ran out of successors for this interval... pop off the stack
end_comment

begin_expr_stmt
name|IntStack
operator|.
name|pop_back
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|} while
operator|(
operator|!
name|IntStack
operator|.
name|empty
argument_list|()
operator|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|*
name|this
return|;
end_return

begin_expr_stmt
unit|}   inline
name|_Self
name|operator
operator|++
operator|(
name|int
operator|)
block|{
comment|// Postincrement
name|_Self
name|tmp
operator|=
operator|*
name|this
block|;
operator|++
operator|*
name|this
block|;
return|return
name|tmp
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|// ProcessInterval - This method is used during the construction of the
end_comment

begin_comment
comment|// interval graph.  It walks through the source graph, recursively creating
end_comment

begin_comment
comment|// an interval per invocation until the entire graph is covered.  This uses
end_comment

begin_comment
comment|// the ProcessNode method to add all of the nodes to the interval.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This method is templated because it may operate on two different source
end_comment

begin_comment
comment|// graphs: a basic block graph, or a preexisting interval graph.
end_comment

begin_comment
comment|//
end_comment

begin_function
name|bool
name|ProcessInterval
parameter_list|(
name|NodeTy
modifier|*
name|Node
parameter_list|)
block|{
name|BasicBlock
modifier|*
name|Header
init|=
name|getNodeHeader
argument_list|(
name|Node
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|Visited
operator|.
name|insert
argument_list|(
name|Header
argument_list|)
operator|.
name|second
condition|)
return|return
name|false
return|;
name|Interval
modifier|*
name|Int
init|=
name|new
name|Interval
argument_list|(
name|Header
argument_list|)
decl_stmt|;
comment|// Check all of our successors to see if they are in the interval...
for|for
control|(
name|typename
name|GT
operator|::
name|ChildIteratorType
name|I
operator|=
name|GT
operator|::
name|child_begin
argument_list|(
name|Node
argument_list|)
operator|,
name|E
operator|=
name|GT
operator|::
name|child_end
argument_list|(
name|Node
argument_list|)
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
name|ProcessNode
argument_list|(
name|Int
argument_list|,
name|getSourceGraphNode
argument_list|(
name|OrigContainer
argument_list|,
operator|*
name|I
argument_list|)
argument_list|)
expr_stmt|;
name|IntStack
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|Int
argument_list|,
name|succ_begin
argument_list|(
name|Int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
end_function

begin_comment
comment|// ProcessNode - This method is called by ProcessInterval to add nodes to the
end_comment

begin_comment
comment|// interval being constructed, and it is also called recursively as it walks
end_comment

begin_comment
comment|// the source graph.  A node is added to the current interval only if all of
end_comment

begin_comment
comment|// its predecessors are already in the graph.  This also takes care of keeping
end_comment

begin_comment
comment|// the successor set of an interval up to date.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This method is templated because it may operate on two different source
end_comment

begin_comment
comment|// graphs: a basic block graph, or a preexisting interval graph.
end_comment

begin_comment
comment|//
end_comment

begin_function
name|void
name|ProcessNode
parameter_list|(
name|Interval
modifier|*
name|Int
parameter_list|,
name|NodeTy
modifier|*
name|Node
parameter_list|)
block|{
name|assert
argument_list|(
name|Int
operator|&&
literal|"Null interval == bad!"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|Node
operator|&&
literal|"Null Node == bad!"
argument_list|)
expr_stmt|;
name|BasicBlock
modifier|*
name|NodeHeader
init|=
name|getNodeHeader
argument_list|(
name|Node
argument_list|)
decl_stmt|;
if|if
condition|(
name|Visited
operator|.
name|count
argument_list|(
name|NodeHeader
argument_list|)
condition|)
block|{
comment|// Node already been visited?
if|if
condition|(
name|Int
operator|->
name|contains
argument_list|(
name|NodeHeader
argument_list|)
condition|)
block|{
comment|// Already in this interval...
return|return;
block|}
else|else
block|{
comment|// In other interval, add as successor
if|if
condition|(
operator|!
name|Int
operator|->
name|isSuccessor
argument_list|(
name|NodeHeader
argument_list|)
condition|)
comment|// Add only if not already in set
name|Int
operator|->
name|Successors
operator|.
name|push_back
argument_list|(
name|NodeHeader
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
comment|// Otherwise, not in interval yet
for|for
control|(
name|typename
name|IGT
operator|::
name|ChildIteratorType
name|I
operator|=
name|IGT
operator|::
name|child_begin
argument_list|(
name|Node
argument_list|)
operator|,
name|E
operator|=
name|IGT
operator|::
name|child_end
argument_list|(
name|Node
argument_list|)
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
operator|!
name|Int
operator|->
name|contains
argument_list|(
operator|*
name|I
argument_list|)
condition|)
block|{
comment|// If pred not in interval, we can't be
if|if
condition|(
operator|!
name|Int
operator|->
name|isSuccessor
argument_list|(
name|NodeHeader
argument_list|)
condition|)
comment|// Add only if not already in set
name|Int
operator|->
name|Successors
operator|.
name|push_back
argument_list|(
name|NodeHeader
argument_list|)
expr_stmt|;
return|return;
comment|// See you later
block|}
block|}
comment|// If we get here, then all of the predecessors of BB are in the interval
comment|// already.  In this case, we must add BB to the interval!
name|addNodeToInterval
argument_list|(
name|Int
argument_list|,
name|Node
argument_list|)
expr_stmt|;
name|Visited
operator|.
name|insert
argument_list|(
name|NodeHeader
argument_list|)
expr_stmt|;
comment|// The node has now been visited!
if|if
condition|(
name|Int
operator|->
name|isSuccessor
argument_list|(
name|NodeHeader
argument_list|)
condition|)
block|{
comment|// If we were in the successor list from before... remove from succ list
name|Int
operator|->
name|Successors
operator|.
name|erase
argument_list|(
name|std
operator|::
name|remove
argument_list|(
name|Int
operator|->
name|Successors
operator|.
name|begin
argument_list|()
argument_list|,
name|Int
operator|->
name|Successors
operator|.
name|end
argument_list|()
argument_list|,
name|NodeHeader
argument_list|)
argument_list|,
name|Int
operator|->
name|Successors
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|// Now that we have discovered that Node is in the interval, perhaps some
comment|// of its successors are as well?
for|for
control|(
name|typename
name|GT
operator|::
name|ChildIteratorType
name|It
operator|=
name|GT
operator|::
name|child_begin
argument_list|(
name|Node
argument_list|)
operator|,
name|End
operator|=
name|GT
operator|::
name|child_end
argument_list|(
name|Node
argument_list|)
init|;
name|It
operator|!=
name|End
condition|;
operator|++
name|It
control|)
name|ProcessNode
argument_list|(
name|Int
argument_list|,
name|getSourceGraphNode
argument_list|(
name|OrigContainer
argument_list|,
operator|*
name|It
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_typedef
unit|};
typedef|typedef
name|IntervalIterator
operator|<
name|BasicBlock
operator|,
name|Function
operator|>
name|function_interval_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|IntervalIterator
operator|<
name|Interval
operator|,
name|IntervalPartition
operator|>
name|interval_part_interval_iterator
expr_stmt|;
end_typedef

begin_function
specifier|inline
name|function_interval_iterator
name|intervals_begin
parameter_list|(
name|Function
modifier|*
name|F
parameter_list|,
name|bool
name|DeleteInts
init|=
name|true
parameter_list|)
block|{
return|return
name|function_interval_iterator
argument_list|(
name|F
argument_list|,
name|DeleteInts
argument_list|)
return|;
block|}
end_function

begin_function
specifier|inline
name|function_interval_iterator
name|intervals_end
parameter_list|(
name|Function
modifier|*
parameter_list|)
block|{
return|return
name|function_interval_iterator
argument_list|()
return|;
block|}
end_function

begin_function
specifier|inline
name|interval_part_interval_iterator
name|intervals_begin
parameter_list|(
name|IntervalPartition
modifier|&
name|IP
parameter_list|,
name|bool
name|DeleteIntervals
init|=
name|true
parameter_list|)
block|{
return|return
name|interval_part_interval_iterator
argument_list|(
name|IP
argument_list|,
name|DeleteIntervals
argument_list|)
return|;
block|}
end_function

begin_function
specifier|inline
name|interval_part_interval_iterator
name|intervals_end
parameter_list|(
name|IntervalPartition
modifier|&
name|IP
parameter_list|)
block|{
return|return
name|interval_part_interval_iterator
argument_list|()
return|;
block|}
end_function

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

