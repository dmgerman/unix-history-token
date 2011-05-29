begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Analysis/Interval.h - Interval Class Declaration ----*- C++ -*-===//
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
comment|// This file contains the declaration of the Interval class, which
end_comment

begin_comment
comment|// represents a set of CFG nodes and is a portion of an interval partition.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Intervals have some interesting and useful properties, including the
end_comment

begin_comment
comment|// following:
end_comment

begin_comment
comment|//    1. The header node of an interval dominates all of the elements of the
end_comment

begin_comment
comment|//       interval
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
name|LLVM_INTERVAL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_INTERVAL_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/GraphTraits.h"
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
name|class
name|BasicBlock
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|/// Interval Class - An Interval is a set of nodes defined such that every node
comment|/// in the interval has all of its predecessors in the interval (except for the
comment|/// header)
comment|///
name|class
name|Interval
block|{
comment|/// HeaderNode - The header BasicBlock, which dominates all BasicBlocks in this
comment|/// interval.  Also, any loops in this interval must go through the HeaderNode.
comment|///
name|BasicBlock
modifier|*
name|HeaderNode
decl_stmt|;
name|public
label|:
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|BasicBlock
operator|*
operator|>
operator|::
name|iterator
name|succ_iterator
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
name|iterator
name|pred_iterator
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
name|iterator
name|node_iterator
expr_stmt|;
specifier|inline
name|Interval
argument_list|(
name|BasicBlock
operator|*
name|Header
argument_list|)
operator|:
name|HeaderNode
argument_list|(
argument|Header
argument_list|)
block|{
name|Nodes
operator|.
name|push_back
argument_list|(
name|Header
argument_list|)
block|;   }
specifier|inline
name|Interval
argument_list|(
specifier|const
name|Interval
operator|&
name|I
argument_list|)
comment|// copy ctor
operator|:
name|HeaderNode
argument_list|(
name|I
operator|.
name|HeaderNode
argument_list|)
operator|,
name|Nodes
argument_list|(
name|I
operator|.
name|Nodes
argument_list|)
operator|,
name|Successors
argument_list|(
argument|I.Successors
argument_list|)
block|{}
specifier|inline
name|BasicBlock
operator|*
name|getHeaderNode
argument_list|()
specifier|const
block|{
return|return
name|HeaderNode
return|;
block|}
comment|/// Nodes - The basic blocks in this interval.
comment|///
name|std
operator|::
name|vector
operator|<
name|BasicBlock
operator|*
operator|>
name|Nodes
expr_stmt|;
comment|/// Successors - List of BasicBlocks that are reachable directly from nodes in
comment|/// this interval, but are not in the interval themselves.
comment|/// These nodes necessarily must be header nodes for other intervals.
comment|///
name|std
operator|::
name|vector
operator|<
name|BasicBlock
operator|*
operator|>
name|Successors
expr_stmt|;
comment|/// Predecessors - List of BasicBlocks that have this Interval's header block
comment|/// as one of their successors.
comment|///
name|std
operator|::
name|vector
operator|<
name|BasicBlock
operator|*
operator|>
name|Predecessors
expr_stmt|;
comment|/// contains - Find out if a basic block is in this interval
specifier|inline
name|bool
name|contains
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
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
name|Nodes
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|Nodes
index|[
name|i
index|]
operator|==
name|BB
condition|)
return|return
name|true
return|;
return|return
name|false
return|;
comment|// I don't want the dependency on<algorithm>
comment|//return find(Nodes.begin(), Nodes.end(), BB) != Nodes.end();
block|}
comment|/// isSuccessor - find out if a basic block is a successor of this Interval
specifier|inline
name|bool
name|isSuccessor
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
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
name|Successors
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|Successors
index|[
name|i
index|]
operator|==
name|BB
condition|)
return|return
name|true
return|;
return|return
name|false
return|;
comment|// I don't want the dependency on<algorithm>
comment|//return find(Successors.begin(), Successors.end(), BB) != Successors.end();
block|}
comment|/// Equality operator.  It is only valid to compare two intervals from the
comment|/// same partition, because of this, all we have to check is the header node
comment|/// for equality.
comment|///
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Interval
operator|&
name|I
operator|)
specifier|const
block|{
return|return
name|HeaderNode
operator|==
name|I
operator|.
name|HeaderNode
return|;
block|}
comment|/// isLoop - Find out if there is a back edge in this interval...
name|bool
name|isLoop
argument_list|()
specifier|const
expr_stmt|;
comment|/// print - Show contents in human readable format...
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|O
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
comment|/// succ_begin/succ_end - define methods so that Intervals may be used
comment|/// just like BasicBlocks can with the succ_* functions, and *::succ_iterator.
comment|///
specifier|inline
name|Interval
operator|::
name|succ_iterator
name|succ_begin
argument_list|(
argument|Interval *I
argument_list|)
block|{
return|return
name|I
operator|->
name|Successors
operator|.
name|begin
argument_list|()
return|;
block|}
specifier|inline
name|Interval
operator|::
name|succ_iterator
name|succ_end
argument_list|(
argument|Interval *I
argument_list|)
block|{
return|return
name|I
operator|->
name|Successors
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// pred_begin/pred_end - define methods so that Intervals may be used
comment|/// just like BasicBlocks can with the pred_* functions, and *::pred_iterator.
comment|///
specifier|inline
name|Interval
operator|::
name|pred_iterator
name|pred_begin
argument_list|(
argument|Interval *I
argument_list|)
block|{
return|return
name|I
operator|->
name|Predecessors
operator|.
name|begin
argument_list|()
return|;
block|}
specifier|inline
name|Interval
operator|::
name|pred_iterator
name|pred_end
argument_list|(
argument|Interval *I
argument_list|)
block|{
return|return
name|I
operator|->
name|Predecessors
operator|.
name|end
argument_list|()
return|;
block|}
name|template
operator|<
operator|>
expr|struct
name|GraphTraits
operator|<
name|Interval
operator|*
operator|>
block|{
typedef|typedef
name|Interval
name|NodeType
typedef|;
typedef|typedef
name|Interval
operator|::
name|succ_iterator
name|ChildIteratorType
expr_stmt|;
specifier|static
name|NodeType
modifier|*
name|getEntryNode
parameter_list|(
name|Interval
modifier|*
name|I
parameter_list|)
block|{
return|return
name|I
return|;
block|}
comment|/// nodes_iterator/begin/end - Allow iteration over all nodes in the graph
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
name|succ_begin
argument_list|(
name|N
argument_list|)
return|;
block|}
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
name|succ_end
argument_list|(
name|N
argument_list|)
return|;
block|}
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
name|GraphTraits
operator|<
name|Inverse
operator|<
name|Interval
operator|*
operator|>
expr|>
block|{
typedef|typedef
name|Interval
name|NodeType
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|Interval
operator|::
name|pred_iterator
name|ChildIteratorType
expr_stmt|;
end_typedef

begin_decl_stmt
specifier|static
name|NodeType
modifier|*
name|getEntryNode
argument_list|(
name|Inverse
operator|<
name|Interval
operator|*
operator|>
name|G
argument_list|)
block|{
return|return
name|G
operator|.
name|Graph
return|;
block|}
end_decl_stmt

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
name|pred_begin
argument_list|(
name|N
argument_list|)
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
name|pred_end
argument_list|(
name|N
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

