begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/unittest/ADT/TestGraph.h - Graph for testing ------------------===//
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
comment|// Common graph data structure for testing.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_include
include|#
directive|include
file|"llvm/ADT/GraphTraits.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<climits>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_UNITTESTS_ADT_TEST_GRAPH_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_UNITTESTS_ADT_TEST_GRAPH_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Graph<N> - A graph with N nodes.  Note that N can be at most 8.
name|template
operator|<
name|unsigned
name|N
operator|>
name|class
name|Graph
block|{
name|private
operator|:
comment|// Disable copying.
name|Graph
argument_list|(
specifier|const
name|Graph
operator|&
argument_list|)
block|;
name|Graph
operator|&
name|operator
operator|=
operator|(
specifier|const
name|Graph
operator|&
operator|)
block|;
specifier|static
name|void
name|ValidateIndex
argument_list|(
argument|unsigned Idx
argument_list|)
block|{
name|assert
argument_list|(
name|Idx
operator|<
name|N
operator|&&
literal|"Invalid node index!"
argument_list|)
block|;   }
name|public
operator|:
comment|/// NodeSubset - A subset of the graph's nodes.
name|class
name|NodeSubset
block|{
typedef|typedef
name|unsigned
name|char
name|BitVector
typedef|;
comment|// Where the limitation N<= 8 comes from.
name|BitVector
name|Elements
block|;
name|NodeSubset
argument_list|(
argument|BitVector e
argument_list|)
operator|:
name|Elements
argument_list|(
argument|e
argument_list|)
block|{}
name|public
operator|:
comment|/// NodeSubset - Default constructor, creates an empty subset.
name|NodeSubset
argument_list|()
operator|:
name|Elements
argument_list|(
literal|0
argument_list|)
block|{
name|assert
argument_list|(
name|N
operator|<=
sizeof|sizeof
argument_list|(
name|BitVector
argument_list|)
operator|*
name|CHAR_BIT
operator|&&
literal|"Graph too big!"
argument_list|)
block|;     }
comment|/// Comparison operators.
name|bool
name|operator
operator|==
operator|(
specifier|const
name|NodeSubset
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|other
operator|.
name|Elements
operator|==
name|this
operator|->
name|Elements
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|NodeSubset
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|other
operator|)
return|;
block|}
comment|/// AddNode - Add the node with the given index to the subset.
name|void
name|AddNode
argument_list|(
argument|unsigned Idx
argument_list|)
block|{
name|ValidateIndex
argument_list|(
name|Idx
argument_list|)
block|;
name|Elements
operator||=
literal|1U
operator|<<
name|Idx
block|;     }
comment|/// DeleteNode - Remove the node with the given index from the subset.
name|void
name|DeleteNode
argument_list|(
argument|unsigned Idx
argument_list|)
block|{
name|ValidateIndex
argument_list|(
name|Idx
argument_list|)
block|;
name|Elements
operator|&=
operator|~
operator|(
literal|1U
operator|<<
name|Idx
operator|)
block|;     }
comment|/// count - Return true if the node with the given index is in the subset.
name|bool
name|count
argument_list|(
argument|unsigned Idx
argument_list|)
block|{
name|ValidateIndex
argument_list|(
name|Idx
argument_list|)
block|;
return|return
operator|(
name|Elements
operator|&
operator|(
literal|1U
operator|<<
name|Idx
operator|)
operator|)
operator|!=
literal|0
return|;
block|}
comment|/// isEmpty - Return true if this is the empty set.
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|Elements
operator|==
literal|0
return|;
block|}
comment|/// isSubsetOf - Return true if this set is a subset of the given one.
name|bool
name|isSubsetOf
argument_list|(
argument|const NodeSubset&other
argument_list|)
specifier|const
block|{
return|return
operator|(
name|this
operator|->
name|Elements
operator||
name|other
operator|.
name|Elements
operator|)
operator|==
name|other
operator|.
name|Elements
return|;
block|}
comment|/// Complement - Return the complement of this subset.
name|NodeSubset
name|Complement
argument_list|()
specifier|const
block|{
return|return
operator|~
operator|(
name|unsigned
operator|)
name|this
operator|->
name|Elements
operator|&
operator|(
operator|(
literal|1U
operator|<<
name|N
operator|)
operator|-
literal|1
operator|)
return|;
block|}
comment|/// Join - Return the union of this subset and the given one.
name|NodeSubset
name|Join
argument_list|(
argument|const NodeSubset&other
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|Elements
operator||
name|other
operator|.
name|Elements
return|;
block|}
comment|/// Meet - Return the intersection of this subset and the given one.
name|NodeSubset
name|Meet
argument_list|(
argument|const NodeSubset&other
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|Elements
operator|&
name|other
operator|.
name|Elements
return|;
block|}
expr|}
block|;
comment|/// NodeType - Node index and set of children of the node.
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|NodeSubset
operator|>
name|NodeType
expr_stmt|;
name|private
operator|:
comment|/// Nodes - The list of nodes for this graph.
name|NodeType
name|Nodes
index|[
name|N
index|]
expr_stmt|;
name|public
label|:
comment|/// Graph - Default constructor.  Creates an empty graph.
name|Graph
argument_list|()
block|{
comment|// Let each node know which node it is.  This allows us to find the start of
comment|// the Nodes array given a pointer to any element of it.
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|N
condition|;
operator|++
name|i
control|)
name|Nodes
index|[
name|i
index|]
operator|.
name|first
operator|=
name|i
expr_stmt|;
block|}
comment|/// AddEdge - Add an edge from the node with index FromIdx to the node with
comment|/// index ToIdx.
name|void
name|AddEdge
parameter_list|(
name|unsigned
name|FromIdx
parameter_list|,
name|unsigned
name|ToIdx
parameter_list|)
block|{
name|ValidateIndex
argument_list|(
name|FromIdx
argument_list|)
expr_stmt|;
name|Nodes
index|[
name|FromIdx
index|]
operator|.
name|second
operator|.
name|AddNode
argument_list|(
name|ToIdx
argument_list|)
expr_stmt|;
block|}
comment|/// DeleteEdge - Remove the edge (if any) from the node with index FromIdx to
comment|/// the node with index ToIdx.
name|void
name|DeleteEdge
parameter_list|(
name|unsigned
name|FromIdx
parameter_list|,
name|unsigned
name|ToIdx
parameter_list|)
block|{
name|ValidateIndex
argument_list|(
name|FromIdx
argument_list|)
expr_stmt|;
name|Nodes
index|[
name|FromIdx
index|]
operator|.
name|second
operator|.
name|DeleteNode
argument_list|(
name|ToIdx
argument_list|)
expr_stmt|;
block|}
comment|/// AccessNode - Get a pointer to the node with the given index.
name|NodeType
modifier|*
name|AccessNode
argument_list|(
name|unsigned
name|Idx
argument_list|)
decl|const
block|{
name|ValidateIndex
argument_list|(
name|Idx
argument_list|)
expr_stmt|;
comment|// The constant cast is needed when working with GraphTraits, which insists
comment|// on taking a constant Graph.
return|return
name|const_cast
operator|<
name|NodeType
operator|*
operator|>
operator|(
operator|&
name|Nodes
index|[
name|Idx
index|]
operator|)
return|;
block|}
comment|/// NodesReachableFrom - Return the set of all nodes reachable from the given
comment|/// node.
name|NodeSubset
name|NodesReachableFrom
argument_list|(
name|unsigned
name|Idx
argument_list|)
decl|const
block|{
comment|// This algorithm doesn't scale, but that doesn't matter given the small
comment|// size of our graphs.
name|NodeSubset
name|Reachable
decl_stmt|;
comment|// The initial node is reachable.
name|Reachable
operator|.
name|AddNode
argument_list|(
name|Idx
argument_list|)
expr_stmt|;
do|do
block|{
name|NodeSubset
name|Previous
parameter_list|(
name|Reachable
parameter_list|)
function_decl|;
comment|// Add in all nodes which are children of a reachable node.
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|N
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|Previous
operator|.
name|count
argument_list|(
name|i
argument_list|)
condition|)
name|Reachable
operator|=
name|Reachable
operator|.
name|Join
argument_list|(
name|Nodes
index|[
name|i
index|]
operator|.
name|second
argument_list|)
expr_stmt|;
comment|// If nothing changed then we have found all reachable nodes.
if|if
condition|(
name|Reachable
operator|==
name|Previous
condition|)
return|return
name|Reachable
return|;
comment|// Rinse and repeat.
block|}
do|while
condition|(
literal|1
condition|)
do|;
block|}
comment|/// ChildIterator - Visit all children of a node.
name|class
name|ChildIterator
block|{
name|friend
name|class
name|Graph
decl_stmt|;
comment|/// FirstNode - Pointer to first node in the graph's Nodes array.
name|NodeType
modifier|*
name|FirstNode
decl_stmt|;
comment|/// Children - Set of nodes which are children of this one and that haven't
comment|/// yet been visited.
name|NodeSubset
name|Children
decl_stmt|;
name|ChildIterator
argument_list|()
expr_stmt|;
comment|// Disable default constructor.
name|protected
label|:
name|ChildIterator
argument_list|(
argument|NodeType *F
argument_list|,
argument|NodeSubset C
argument_list|)
block|:
name|FirstNode
argument_list|(
name|F
argument_list|)
operator|,
name|Children
argument_list|(
argument|C
argument_list|)
block|{}
name|public
operator|:
comment|/// ChildIterator - Copy constructor.
name|ChildIterator
argument_list|(
specifier|const
name|ChildIterator
operator|&
name|other
argument_list|)
operator|:
name|FirstNode
argument_list|(
name|other
operator|.
name|FirstNode
argument_list|)
operator|,
name|Children
argument_list|(
argument|other.Children
argument_list|)
block|{}
comment|/// Comparison operators.
name|bool
name|operator
operator|==
operator|(
specifier|const
name|ChildIterator
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|other
operator|.
name|FirstNode
operator|==
name|this
operator|->
name|FirstNode
operator|&&
name|other
operator|.
name|Children
operator|==
name|this
operator|->
name|Children
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|ChildIterator
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|other
operator|)
return|;
block|}
comment|/// Prefix increment operator.
name|ChildIterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
comment|// Find the next unvisited child node.
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|N
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|Children
operator|.
name|count
argument_list|(
name|i
argument_list|)
condition|)
block|{
comment|// Remove that child - it has been visited.  This is the increment!
name|Children
operator|.
name|DeleteNode
argument_list|(
name|i
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
name|assert
argument_list|(
name|false
operator|&&
literal|"Incrementing end iterator!"
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
comment|// Avoid compiler warnings.
block|}
comment|/// Postfix increment operator.
name|ChildIterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|ChildIterator
name|Result
argument_list|(
operator|*
name|this
argument_list|)
block|;
operator|++
operator|(
operator|*
name|this
operator|)
block|;
return|return
name|Result
return|;
block|}
comment|/// Dereference operator.
name|NodeType
modifier|*
name|operator
modifier|*
parameter_list|()
block|{
comment|// Find the next unvisited child node.
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|N
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|Children
operator|.
name|count
argument_list|(
name|i
argument_list|)
condition|)
comment|// Return a pointer to it.
return|return
name|FirstNode
operator|+
name|i
return|;
name|assert
argument_list|(
name|false
operator|&&
literal|"Dereferencing end iterator!"
argument_list|)
expr_stmt|;
return|return
name|nullptr
return|;
comment|// Avoid compiler warning.
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// child_begin - Return an iterator pointing to the first child of the given
end_comment

begin_comment
comment|/// node.
end_comment

begin_function
specifier|static
name|ChildIterator
name|child_begin
parameter_list|(
name|NodeType
modifier|*
name|Parent
parameter_list|)
block|{
return|return
name|ChildIterator
argument_list|(
name|Parent
operator|-
name|Parent
operator|->
name|first
argument_list|,
name|Parent
operator|->
name|second
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// child_end - Return the end iterator for children of the given node.
end_comment

begin_function
specifier|static
name|ChildIterator
name|child_end
parameter_list|(
name|NodeType
modifier|*
name|Parent
parameter_list|)
block|{
return|return
name|ChildIterator
argument_list|(
name|Parent
operator|-
name|Parent
operator|->
name|first
argument_list|,
name|NodeSubset
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
unit|};
name|template
operator|<
name|unsigned
name|N
operator|>
expr|struct
name|GraphTraits
operator|<
name|Graph
operator|<
name|N
operator|>
expr|>
block|{
typedef|typedef
name|typename
name|Graph
operator|<
name|N
operator|>
operator|::
name|NodeType
operator|*
name|NodeRef
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|Graph
operator|<
name|N
operator|>
operator|::
name|ChildIterator
name|ChildIteratorType
expr_stmt|;
end_typedef

begin_decl_stmt
specifier|static
name|NodeRef
name|getEntryNode
argument_list|(
specifier|const
name|Graph
operator|<
name|N
operator|>
operator|&
name|G
argument_list|)
block|{
return|return
name|G
operator|.
name|AccessNode
argument_list|(
literal|0
argument_list|)
return|;
block|}
end_decl_stmt

begin_function
specifier|static
name|ChildIteratorType
name|child_begin
parameter_list|(
name|NodeRef
name|Node
parameter_list|)
block|{
return|return
name|Graph
operator|<
name|N
operator|>
operator|::
name|child_begin
argument_list|(
name|Node
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|ChildIteratorType
name|child_end
parameter_list|(
name|NodeRef
name|Node
parameter_list|)
block|{
return|return
name|Graph
operator|<
name|N
operator|>
operator|::
name|child_end
argument_list|(
name|Node
argument_list|)
return|;
block|}
end_function

begin_comment
unit|};  }
comment|// End namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

