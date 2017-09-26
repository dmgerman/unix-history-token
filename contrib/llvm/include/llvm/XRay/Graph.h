begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Graph.h - XRay Graph Class ------------------------------*- C++ -*-===//
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
comment|// A Graph Datatype for XRay.
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
name|LLVM_XRAY_GRAPH_T_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_XRAY_GRAPH_T_H
end_define

begin_include
include|#
directive|include
file|<initializer_list>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<type_traits>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

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
file|"llvm/ADT/iterator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|xray
block|{
comment|/// A Graph object represents a Directed Graph and is used in XRay to compute
comment|/// and store function call graphs and associated statistical information.
comment|///
comment|/// The graph takes in four template parameters, these are:
comment|///  - VertexAttribute, this is a structure which is stored for each vertex.
comment|///    Must be DefaultConstructible, CopyConstructible, CopyAssignable and
comment|///    Destructible.
comment|///  - EdgeAttribute, this is a structure which is stored for each edge
comment|///    Must be DefaultConstructible, CopyConstructible, CopyAssignable and
comment|///    Destructible.
comment|///  - EdgeAttribute, this is a structure which is stored for each variable
comment|///  - VI, this is a type over which DenseMapInfo is defined and is the type
comment|///    used look up strings, available as VertexIdentifier.
comment|///  - If the built in DenseMapInfo is not defined, provide a specialization
comment|///    class type here.
comment|///
comment|/// Graph is CopyConstructible, CopyAssignable, MoveConstructible and
comment|/// MoveAssignable but is not EqualityComparible or LessThanComparible.
comment|///
comment|/// Usage Example Graph with weighted edges and vertices:
comment|///   Graph<int, int, int> G;
comment|///
comment|///   G[1] = 0;
comment|///   G[2] = 2;
comment|///   G[{1,2}] = 1;
comment|///   G[{2,1}] = -1;
comment|///   for(const auto&v : G.vertices()){
comment|///     // Do something with the vertices in the graph;
comment|///   }
comment|///   for(const auto&e : G.edges()){
comment|///     // Do something with the edges in the graph;
comment|///   }
comment|///
comment|/// Usage Example with StrRef keys.
comment|///   Graph<int, double, StrRef> StrG;
comment|///    char va[] = "Vertex A";
comment|///    char vaa[] = "Vertex A";
comment|///    char vb[] = "Vertex B"; // Vertices are referenced by String Refs.
comment|///    G[va] = 0;
comment|///    G[vb] = 1;
comment|///    G[{va, vb}] = 1.0;
comment|///    cout()<< G[vaa]<< " "<< G[{vaa, vb}]; //prints "0 1.0".
comment|///
name|template
operator|<
name|typename
name|VertexAttribute
operator|,
name|typename
name|EdgeAttribute
operator|,
name|typename
name|VI
operator|=
name|int32_t
operator|>
name|class
name|Graph
block|{
name|public
operator|:
comment|/// These objects are used to name edges and vertices in the graph.
typedef|typedef
name|VI
name|VertexIdentifier
typedef|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|VI
operator|,
name|VI
operator|>
name|EdgeIdentifier
expr_stmt|;
comment|/// This type is the value_type of all iterators which range over vertices,
comment|/// Determined by the Vertices DenseMap
name|using
name|VertexValueType
init|=
name|detail
operator|::
name|DenseMapPair
operator|<
name|VertexIdentifier
decl_stmt|,
name|VertexAttribute
decl|>
decl_stmt|;
comment|/// This type is the value_type of all iterators which range over edges,
comment|/// Determined by the Edges DenseMap.
name|using
name|EdgeValueType
init|=
name|detail
operator|::
name|DenseMapPair
operator|<
name|EdgeIdentifier
decl_stmt|,
name|EdgeAttribute
decl|>
decl_stmt|;
name|using
name|size_type
init|=
name|std
operator|::
name|size_t
decl_stmt|;
name|private
label|:
comment|/// The type used for storing the EdgeAttribute for each edge in the graph
name|using
name|EdgeMapT
init|=
name|DenseMap
operator|<
name|EdgeIdentifier
decl_stmt|,
name|EdgeAttribute
decl|>
decl_stmt|;
comment|/// The type used for storing the VertexAttribute for each vertex in
comment|/// the graph.
name|using
name|VertexMapT
init|=
name|DenseMap
operator|<
name|VertexIdentifier
decl_stmt|,
name|VertexAttribute
decl|>
decl_stmt|;
comment|/// The type used for storing the edges entering a vertex. Indexed by
comment|/// the VertexIdentifier of the start of the edge. Only used to determine
comment|/// where the incoming edges are, the EdgeIdentifiers are stored in an
comment|/// InnerEdgeMapT.
name|using
name|NeighborSetT
init|=
name|DenseSet
operator|<
name|VertexIdentifier
operator|>
decl_stmt|;
comment|/// The type storing the InnerInvGraphT corresponding to each vertex in
comment|/// the graph (When a vertex has an incoming edge incident to it)
name|using
name|NeighborLookupT
init|=
name|DenseMap
operator|<
name|VertexIdentifier
decl_stmt|,
name|NeighborSetT
decl|>
decl_stmt|;
name|private
label|:
comment|/// Stores the map from the start and end vertex of an edge to it's
comment|/// EdgeAttribute
name|EdgeMapT
name|Edges
decl_stmt|;
comment|/// Stores the map from VertexIdentifier to VertexAttribute
name|VertexMapT
name|Vertices
decl_stmt|;
comment|/// Allows fast lookup for the incoming edge set of any given vertex.
name|NeighborLookupT
name|InNeighbors
decl_stmt|;
comment|/// Allows fast lookup for the outgoing edge set of any given vertex.
name|NeighborLookupT
name|OutNeighbors
decl_stmt|;
comment|/// An Iterator adapter using an InnerInvGraphT::iterator as a base iterator,
comment|/// and storing the VertexIdentifier the iterator range comes from. The
comment|/// dereference operator is then performed using a pointer to the graph's edge
comment|/// set.
name|template
operator|<
name|bool
name|IsConst
operator|,
name|bool
name|IsOut
operator|,
name|typename
name|BaseIt
operator|=
name|typename
name|NeighborSetT
operator|::
name|const_iterator
operator|,
name|typename
name|T
operator|=
name|typename
name|std
operator|::
name|conditional
operator|<
name|IsConst
operator|,
specifier|const
name|EdgeValueType
operator|,
name|EdgeValueType
operator|>
operator|::
name|type
operator|>
name|class
name|NeighborEdgeIteratorT
operator|:
name|public
name|iterator_adaptor_base
operator|<
name|NeighborEdgeIteratorT
operator|<
name|IsConst
operator|,
name|IsOut
operator|>
operator|,
name|BaseIt
operator|,
name|typename
name|std
operator|::
name|iterator_traits
operator|<
name|BaseIt
operator|>
operator|::
name|iterator_category
operator|,
name|T
operator|>
block|{
name|using
name|InternalEdgeMapT
operator|=
name|typename
name|std
operator|::
name|conditional
operator|<
name|IsConst
block|,
specifier|const
name|EdgeMapT
block|,
name|EdgeMapT
operator|>
operator|::
name|type
block|;
name|friend
name|class
name|NeighborEdgeIteratorT
operator|<
name|false
block|,
name|IsOut
block|,
name|BaseIt
block|,
name|EdgeValueType
operator|>
block|;
name|friend
name|class
name|NeighborEdgeIteratorT
operator|<
name|true
block|,
name|IsOut
block|,
name|BaseIt
block|,
specifier|const
name|EdgeValueType
operator|>
block|;
name|InternalEdgeMapT
operator|*
name|MP
block|;
name|VertexIdentifier
name|SI
block|;
name|public
operator|:
name|template
operator|<
name|bool
name|IsConstDest
block|,
name|typename
operator|=
name|typename
name|std
operator|::
name|enable_if
operator|<
name|IsConstDest
operator|&&
operator|!
name|IsConst
operator|>
operator|::
name|type
operator|>
name|operator
name|NeighborEdgeIteratorT
operator|<
name|IsConstDest
block|,
name|IsOut
block|,
name|BaseIt
block|,
specifier|const
name|EdgeValueType
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|NeighborEdgeIteratorT
operator|<
name|IsConstDest
operator|,
name|IsOut
operator|,
name|BaseIt
operator|,
specifier|const
name|EdgeValueType
operator|>
operator|(
name|this
operator|->
name|I
operator|,
name|MP
operator|,
name|SI
operator|)
return|;
block|}
name|NeighborEdgeIteratorT
argument_list|()
operator|=
expr|default
block|;
name|NeighborEdgeIteratorT
argument_list|(
argument|BaseIt _I
argument_list|,
argument|InternalEdgeMapT *_MP
argument_list|,
argument|VertexIdentifier _SI
argument_list|)
operator|:
name|iterator_adaptor_base
operator|<
name|NeighborEdgeIteratorT
operator|<
name|IsConst
block|,
name|IsOut
operator|>
block|,
name|BaseIt
block|,
name|typename
name|std
operator|::
name|iterator_traits
operator|<
name|BaseIt
operator|>
operator|::
name|iterator_category
block|,
name|T
operator|>
operator|(
name|_I
operator|)
block|,
name|MP
argument_list|(
name|_MP
argument_list|)
block|,
name|SI
argument_list|(
argument|_SI
argument_list|)
block|{}
name|T
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
if|if
condition|(
operator|!
name|IsOut
condition|)
return|return
operator|*
operator|(
name|MP
operator|->
name|find
argument_list|(
block|{
operator|*
operator|(
name|this
operator|->
name|I
operator|)
block|,
name|SI
block|}
argument_list|)
operator|)
return|;
else|else
return|return
operator|*
operator|(
name|MP
operator|->
name|find
argument_list|(
block|{
name|SI
block|,
operator|*
operator|(
name|this
operator|->
name|I
operator|)
block|}
argument_list|)
operator|)
return|;
block|}
expr|}
block|;
name|public
operator|:
comment|/// A const iterator type for iterating through the set of edges entering a
comment|/// vertex.
comment|///
comment|/// Has a const EdgeValueType as its value_type
name|using
name|ConstInEdgeIterator
operator|=
name|NeighborEdgeIteratorT
operator|<
name|true
block|,
name|false
operator|>
block|;
comment|/// An iterator type for iterating through the set of edges leaving a vertex.
comment|///
comment|/// Has an EdgeValueType as its value_type
name|using
name|InEdgeIterator
operator|=
name|NeighborEdgeIteratorT
operator|<
name|false
block|,
name|false
operator|>
block|;
comment|/// A const iterator type for iterating through the set of edges entering a
comment|/// vertex.
comment|///
comment|/// Has a const EdgeValueType as its value_type
name|using
name|ConstOutEdgeIterator
operator|=
name|NeighborEdgeIteratorT
operator|<
name|true
block|,
name|true
operator|>
block|;
comment|/// An iterator type for iterating through the set of edges leaving a vertex.
comment|///
comment|/// Has an EdgeValueType as its value_type
name|using
name|OutEdgeIterator
operator|=
name|NeighborEdgeIteratorT
operator|<
name|false
block|,
name|true
operator|>
block|;
comment|/// A class for ranging over the incoming edges incident to a vertex.
comment|///
comment|/// Like all views in this class it provides methods to get the beginning and
comment|/// past the range iterators for the range, as well as methods to determine
comment|/// the number of elements in the range and whether the range is empty.
name|template
operator|<
name|bool
name|isConst
block|,
name|bool
name|isOut
operator|>
name|class
name|InOutEdgeView
block|{
name|public
operator|:
name|using
name|iterator
operator|=
name|NeighborEdgeIteratorT
operator|<
name|isConst
block|,
name|isOut
operator|>
block|;
name|using
name|const_iterator
operator|=
name|NeighborEdgeIteratorT
operator|<
name|true
block|,
name|isOut
operator|>
block|;
name|using
name|GraphT
operator|=
name|typename
name|std
operator|::
name|conditional
operator|<
name|isConst
block|,
specifier|const
name|Graph
block|,
name|Graph
operator|>
operator|::
name|type
block|;
name|using
name|InternalEdgeMapT
operator|=
name|typename
name|std
operator|::
name|conditional
operator|<
name|isConst
block|,
specifier|const
name|EdgeMapT
block|,
name|EdgeMapT
operator|>
operator|::
name|type
block|;
name|private
operator|:
name|InternalEdgeMapT
operator|&
name|M
block|;
specifier|const
name|VertexIdentifier
name|A
block|;
specifier|const
name|NeighborLookupT
operator|&
name|NL
block|;
name|public
operator|:
name|iterator
name|begin
argument_list|()
block|{
name|auto
name|It
operator|=
name|NL
operator|.
name|find
argument_list|(
name|A
argument_list|)
block|;
if|if
condition|(
name|It
operator|==
name|NL
operator|.
name|end
argument_list|()
condition|)
return|return
name|iterator
argument_list|()
return|;
return|return
name|iterator
argument_list|(
name|It
operator|->
name|second
operator|.
name|begin
argument_list|()
argument_list|,
operator|&
name|M
argument_list|,
name|A
argument_list|)
return|;
block|}
name|const_iterator
name|cbegin
argument_list|()
specifier|const
block|{
name|auto
name|It
operator|=
name|NL
operator|.
name|find
argument_list|(
name|A
argument_list|)
block|;
if|if
condition|(
name|It
operator|==
name|NL
operator|.
name|end
argument_list|()
condition|)
return|return
name|const_iterator
argument_list|()
return|;
return|return
name|const_iterator
argument_list|(
name|It
operator|->
name|second
operator|.
name|begin
argument_list|()
argument_list|,
operator|&
name|M
argument_list|,
name|A
argument_list|)
return|;
block|}
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|cbegin
argument_list|()
return|;
block|}
name|iterator
name|end
parameter_list|()
block|{
name|auto
name|It
init|=
name|NL
operator|.
name|find
argument_list|(
name|A
argument_list|)
decl_stmt|;
if|if
condition|(
name|It
operator|==
name|NL
operator|.
name|end
argument_list|()
condition|)
return|return
name|iterator
argument_list|()
return|;
return|return
name|iterator
argument_list|(
name|It
operator|->
name|second
operator|.
name|end
argument_list|()
argument_list|,
operator|&
name|M
argument_list|,
name|A
argument_list|)
return|;
block|}
name|const_iterator
name|cend
argument_list|()
specifier|const
block|{
name|auto
name|It
operator|=
name|NL
operator|.
name|find
argument_list|(
name|A
argument_list|)
block|;
if|if
condition|(
name|It
operator|==
name|NL
operator|.
name|end
argument_list|()
condition|)
return|return
name|const_iterator
argument_list|()
return|;
return|return
name|const_iterator
argument_list|(
name|It
operator|->
name|second
operator|.
name|end
argument_list|()
argument_list|,
operator|&
name|M
argument_list|,
name|A
argument_list|)
return|;
block|}
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|cend
argument_list|()
return|;
block|}
name|size_type
name|size
argument_list|()
specifier|const
block|{
name|auto
name|I
operator|=
name|NL
operator|.
name|find
argument_list|(
name|A
argument_list|)
block|;
if|if
condition|(
name|I
operator|==
name|NL
operator|.
name|end
argument_list|()
condition|)
return|return
literal|0
return|;
else|else
return|return
name|I
operator|->
name|second
operator|.
name|size
argument_list|()
return|;
block|}
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|NL
operator|.
name|count
argument_list|(
name|A
argument_list|)
operator|==
literal|0
return|;
block|}
empty_stmt|;
name|InOutEdgeView
argument_list|(
argument|GraphT&G
argument_list|,
argument|VertexIdentifier A
argument_list|)
block|:
name|M
argument_list|(
name|G
operator|.
name|Edges
argument_list|)
operator|,
name|A
argument_list|(
name|A
argument_list|)
operator|,
name|NL
argument_list|(
argument|isOut ? G.OutNeighbors : G.InNeighbors
argument_list|)
block|{}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// A const iterator type for iterating through the whole vertex set of the
end_comment

begin_comment
comment|/// graph.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Has a const VertexValueType as its value_type
end_comment

begin_decl_stmt
name|using
name|ConstVertexIterator
init|=
name|typename
name|VertexMapT
operator|::
name|const_iterator
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// An iterator type for iterating through the whole vertex set of the graph.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Has a VertexValueType as its value_type
end_comment

begin_decl_stmt
name|using
name|VertexIterator
init|=
name|typename
name|VertexMapT
operator|::
name|iterator
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// A class for ranging over the vertices in the graph.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Like all views in this class it provides methods to get the beginning and
end_comment

begin_comment
comment|/// past the range iterators for the range, as well as methods to determine
end_comment

begin_comment
comment|/// the number of elements in the range and whether the range is empty.
end_comment

begin_expr_stmt
name|template
operator|<
name|bool
name|isConst
operator|>
name|class
name|VertexView
block|{
name|public
operator|:
name|using
name|iterator
operator|=
name|typename
name|std
operator|::
name|conditional
operator|<
name|isConst
block|,
name|ConstVertexIterator
block|,
name|VertexIterator
operator|>
operator|::
name|type
block|;
name|using
name|const_iterator
operator|=
name|ConstVertexIterator
block|;
name|using
name|GraphT
operator|=
name|typename
name|std
operator|::
name|conditional
operator|<
name|isConst
block|,
specifier|const
name|Graph
block|,
name|Graph
operator|>
operator|::
name|type
block|;
name|private
operator|:
name|GraphT
operator|&
name|G
block|;
name|public
operator|:
name|iterator
name|begin
argument_list|()
block|{
return|return
name|G
operator|.
name|Vertices
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|end
argument_list|()
block|{
return|return
name|G
operator|.
name|Vertices
operator|.
name|end
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|const_iterator
name|cbegin
argument_list|()
specifier|const
block|{
return|return
name|G
operator|.
name|Vertices
operator|.
name|cbegin
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|const_iterator
name|cend
argument_list|()
specifier|const
block|{
return|return
name|G
operator|.
name|Vertices
operator|.
name|cend
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|G
operator|.
name|Vertices
operator|.
name|begin
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|G
operator|.
name|Vertices
operator|.
name|end
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|size_type
name|size
argument_list|()
specifier|const
block|{
return|return
name|G
operator|.
name|Vertices
operator|.
name|size
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
name|G
operator|.
name|Vertices
operator|.
name|empty
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|VertexView
argument_list|(
name|GraphT
operator|&
name|_G
argument_list|)
operator|:
name|G
argument_list|(
argument|_G
argument_list|)
block|{}
end_expr_stmt

begin_comment
unit|};
comment|/// A const iterator for iterating through the entire edge set of the graph.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Has a const EdgeValueType as its value_type
end_comment

begin_decl_stmt
name|using
name|ConstEdgeIterator
init|=
name|typename
name|EdgeMapT
operator|::
name|const_iterator
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// An iterator for iterating through the entire edge set of the graph.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Has an EdgeValueType as its value_type
end_comment

begin_decl_stmt
name|using
name|EdgeIterator
init|=
name|typename
name|EdgeMapT
operator|::
name|iterator
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// A class for ranging over all the edges in the graph.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Like all views in this class it provides methods to get the beginning and
end_comment

begin_comment
comment|/// past the range iterators for the range, as well as methods to determine
end_comment

begin_comment
comment|/// the number of elements in the range and whether the range is empty.
end_comment

begin_expr_stmt
name|template
operator|<
name|bool
name|isConst
operator|>
name|class
name|EdgeView
block|{
name|public
operator|:
name|using
name|iterator
operator|=
name|typename
name|std
operator|::
name|conditional
operator|<
name|isConst
block|,
name|ConstEdgeIterator
block|,
name|EdgeIterator
operator|>
operator|::
name|type
block|;
name|using
name|const_iterator
operator|=
name|ConstEdgeIterator
block|;
name|using
name|GraphT
operator|=
name|typename
name|std
operator|::
name|conditional
operator|<
name|isConst
block|,
specifier|const
name|Graph
block|,
name|Graph
operator|>
operator|::
name|type
block|;
name|private
operator|:
name|GraphT
operator|&
name|G
block|;
name|public
operator|:
name|iterator
name|begin
argument_list|()
block|{
return|return
name|G
operator|.
name|Edges
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|end
argument_list|()
block|{
return|return
name|G
operator|.
name|Edges
operator|.
name|end
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|const_iterator
name|cbegin
argument_list|()
specifier|const
block|{
return|return
name|G
operator|.
name|Edges
operator|.
name|cbegin
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|const_iterator
name|cend
argument_list|()
specifier|const
block|{
return|return
name|G
operator|.
name|Edges
operator|.
name|cend
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|G
operator|.
name|Edges
operator|.
name|begin
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|G
operator|.
name|Edges
operator|.
name|end
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|size_type
name|size
argument_list|()
specifier|const
block|{
return|return
name|G
operator|.
name|Edges
operator|.
name|size
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
name|G
operator|.
name|Edges
operator|.
name|empty
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|EdgeView
argument_list|(
name|GraphT
operator|&
name|_G
argument_list|)
operator|:
name|G
argument_list|(
argument|_G
argument_list|)
block|{}
end_expr_stmt

begin_label
unit|};
name|public
label|:
end_label

begin_comment
comment|// TODO: implement constructor to enable Graph Initialisation.\
end_comment

begin_comment
comment|// Something like:
end_comment

begin_comment
comment|//   Graph<int, int, int> G(
end_comment

begin_comment
comment|//   {1, 2, 3, 4, 5},
end_comment

begin_comment
comment|//   {{1, 2}, {2, 3}, {3, 4}});
end_comment

begin_comment
comment|/// Empty the Graph
end_comment

begin_function
name|void
name|clear
parameter_list|()
block|{
name|Edges
operator|.
name|clear
argument_list|()
expr_stmt|;
name|Vertices
operator|.
name|clear
argument_list|()
expr_stmt|;
name|InNeighbors
operator|.
name|clear
argument_list|()
expr_stmt|;
name|OutNeighbors
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Returns a view object allowing iteration over the vertices of the graph.
end_comment

begin_comment
comment|/// also allows access to the size of the vertex set.
end_comment

begin_expr_stmt
name|VertexView
operator|<
name|false
operator|>
name|vertices
argument_list|()
block|{
return|return
name|VertexView
operator|<
name|false
operator|>
operator|(
operator|*
name|this
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|VertexView
operator|<
name|true
operator|>
name|vertices
argument_list|()
specifier|const
block|{
return|return
name|VertexView
operator|<
name|true
operator|>
operator|(
operator|*
name|this
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Returns a view object allowing iteration over the edges of the graph.
end_comment

begin_comment
comment|/// also allows access to the size of the edge set.
end_comment

begin_expr_stmt
name|EdgeView
operator|<
name|false
operator|>
name|edges
argument_list|()
block|{
return|return
name|EdgeView
operator|<
name|false
operator|>
operator|(
operator|*
name|this
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|EdgeView
operator|<
name|true
operator|>
name|edges
argument_list|()
specifier|const
block|{
return|return
name|EdgeView
operator|<
name|true
operator|>
operator|(
operator|*
name|this
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Returns a view object allowing iteration over the edges which start at
end_comment

begin_comment
comment|/// a vertex I.
end_comment

begin_expr_stmt
name|InOutEdgeView
operator|<
name|false
operator|,
name|true
operator|>
name|outEdges
argument_list|(
argument|const VertexIdentifier I
argument_list|)
block|{
return|return
name|InOutEdgeView
operator|<
name|false
operator|,
name|true
operator|>
operator|(
operator|*
name|this
operator|,
name|I
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|InOutEdgeView
operator|<
name|true
operator|,
name|true
operator|>
name|outEdges
argument_list|(
argument|const VertexIdentifier I
argument_list|)
specifier|const
block|{
return|return
name|InOutEdgeView
operator|<
name|true
operator|,
name|true
operator|>
operator|(
operator|*
name|this
operator|,
name|I
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Returns a view object allowing iteration over the edges which point to
end_comment

begin_comment
comment|/// a vertex I.
end_comment

begin_expr_stmt
name|InOutEdgeView
operator|<
name|false
operator|,
name|false
operator|>
name|inEdges
argument_list|(
argument|const VertexIdentifier I
argument_list|)
block|{
return|return
name|InOutEdgeView
operator|<
name|false
operator|,
name|false
operator|>
operator|(
operator|*
name|this
operator|,
name|I
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|InOutEdgeView
operator|<
name|true
operator|,
name|false
operator|>
name|inEdges
argument_list|(
argument|const VertexIdentifier I
argument_list|)
specifier|const
block|{
return|return
name|InOutEdgeView
operator|<
name|true
operator|,
name|false
operator|>
operator|(
operator|*
name|this
operator|,
name|I
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Looks up the vertex with identifier I, if it does not exist it default
end_comment

begin_comment
comment|/// constructs it.
end_comment

begin_function
name|VertexAttribute
modifier|&
name|operator
function|[]
parameter_list|(
specifier|const
name|VertexIdentifier
modifier|&
name|I
parameter_list|)
block|{
return|return
name|Vertices
operator|.
name|FindAndConstruct
argument_list|(
name|I
argument_list|)
operator|.
name|second
return|;
block|}
end_function

begin_comment
comment|/// Looks up the edge with identifier I, if it does not exist it default
end_comment

begin_comment
comment|/// constructs it, if it's endpoints do not exist it also default constructs
end_comment

begin_comment
comment|/// them.
end_comment

begin_function
name|EdgeAttribute
modifier|&
name|operator
function|[]
parameter_list|(
specifier|const
name|EdgeIdentifier
modifier|&
name|I
parameter_list|)
block|{
name|auto
operator|&
name|P
operator|=
name|Edges
operator|.
name|FindAndConstruct
argument_list|(
name|I
argument_list|)
expr_stmt|;
name|Vertices
operator|.
name|FindAndConstruct
argument_list|(
name|I
operator|.
name|first
argument_list|)
expr_stmt|;
name|Vertices
operator|.
name|FindAndConstruct
argument_list|(
name|I
operator|.
name|second
argument_list|)
expr_stmt|;
name|InNeighbors
index|[
name|I
operator|.
name|second
index|]
operator|.
name|insert
argument_list|(
name|I
operator|.
name|first
argument_list|)
expr_stmt|;
name|OutNeighbors
index|[
name|I
operator|.
name|first
index|]
operator|.
name|insert
argument_list|(
name|I
operator|.
name|second
argument_list|)
expr_stmt|;
return|return
name|P
operator|.
name|second
return|;
block|}
end_function

begin_comment
comment|/// Looks up a vertex with Identifier I, or an error if it does not exist.
end_comment

begin_expr_stmt
name|Expected
operator|<
name|VertexAttribute
operator|&
operator|>
name|at
argument_list|(
argument|const VertexIdentifier&I
argument_list|)
block|{
name|auto
name|It
operator|=
name|Vertices
operator|.
name|find
argument_list|(
name|I
argument_list|)
block|;
if|if
condition|(
name|It
operator|==
name|Vertices
operator|.
name|end
argument_list|()
condition|)
return|return
name|make_error
operator|<
name|StringError
operator|>
operator|(
literal|"Vertex Identifier Does Not Exist"
operator|,
name|std
operator|::
name|make_error_code
argument_list|(
name|std
operator|::
name|errc
operator|::
name|invalid_argument
argument_list|)
operator|)
return|;
end_expr_stmt

begin_return
return|return
name|It
operator|->
name|second
return|;
end_return

begin_expr_stmt
unit|}    Expected
operator|<
specifier|const
name|VertexAttribute
operator|&
operator|>
name|at
argument_list|(
argument|const VertexIdentifier&I
argument_list|)
specifier|const
block|{
name|auto
name|It
operator|=
name|Vertices
operator|.
name|find
argument_list|(
name|I
argument_list|)
block|;
if|if
condition|(
name|It
operator|==
name|Vertices
operator|.
name|end
argument_list|()
condition|)
return|return
name|make_error
operator|<
name|StringError
operator|>
operator|(
literal|"Vertex Identifier Does Not Exist"
operator|,
name|std
operator|::
name|make_error_code
argument_list|(
name|std
operator|::
name|errc
operator|::
name|invalid_argument
argument_list|)
operator|)
return|;
end_expr_stmt

begin_return
return|return
name|It
operator|->
name|second
return|;
end_return

begin_comment
unit|}
comment|/// Looks up an edge with Identifier I, or an error if it does not exist.
end_comment

begin_expr_stmt
unit|Expected
operator|<
name|EdgeAttribute
operator|&
operator|>
name|at
argument_list|(
argument|const EdgeIdentifier&I
argument_list|)
block|{
name|auto
name|It
operator|=
name|Edges
operator|.
name|find
argument_list|(
name|I
argument_list|)
block|;
if|if
condition|(
name|It
operator|==
name|Edges
operator|.
name|end
argument_list|()
condition|)
return|return
name|make_error
operator|<
name|StringError
operator|>
operator|(
literal|"Edge Identifier Does Not Exist"
operator|,
name|std
operator|::
name|make_error_code
argument_list|(
name|std
operator|::
name|errc
operator|::
name|invalid_argument
argument_list|)
operator|)
return|;
end_expr_stmt

begin_return
return|return
name|It
operator|->
name|second
return|;
end_return

begin_expr_stmt
unit|}    Expected
operator|<
specifier|const
name|EdgeAttribute
operator|&
operator|>
name|at
argument_list|(
argument|const EdgeIdentifier&I
argument_list|)
specifier|const
block|{
name|auto
name|It
operator|=
name|Edges
operator|.
name|find
argument_list|(
name|I
argument_list|)
block|;
if|if
condition|(
name|It
operator|==
name|Edges
operator|.
name|end
argument_list|()
condition|)
return|return
name|make_error
operator|<
name|StringError
operator|>
operator|(
literal|"Edge Identifier Does Not Exist"
operator|,
name|std
operator|::
name|make_error_code
argument_list|(
name|std
operator|::
name|errc
operator|::
name|invalid_argument
argument_list|)
operator|)
return|;
end_expr_stmt

begin_return
return|return
name|It
operator|->
name|second
return|;
end_return

begin_comment
unit|}
comment|/// Looks for a vertex with identifier I, returns 1 if one exists, and
end_comment

begin_comment
comment|/// 0 otherwise
end_comment

begin_macro
unit|size_type
name|count
argument_list|(
argument|const VertexIdentifier&I
argument_list|)
end_macro

begin_expr_stmt
specifier|const
block|{
return|return
name|Vertices
operator|.
name|count
argument_list|(
name|I
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Looks for an edge with Identifier I, returns 1 if one exists and 0
end_comment

begin_comment
comment|/// otherwise
end_comment

begin_decl_stmt
name|size_type
name|count
argument_list|(
specifier|const
name|EdgeIdentifier
operator|&
name|I
argument_list|)
decl|const
block|{
return|return
name|Edges
operator|.
name|count
argument_list|(
name|I
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Inserts a vertex into the graph with Identifier Val.first, and
end_comment

begin_comment
comment|/// Attribute Val.second.
end_comment

begin_expr_stmt
name|std
operator|::
name|pair
operator|<
name|VertexIterator
operator|,
name|bool
operator|>
name|insert
argument_list|(
argument|const std::pair<VertexIdentifier
argument_list|,
argument|VertexAttribute>&Val
argument_list|)
block|{
return|return
name|Vertices
operator|.
name|insert
argument_list|(
name|Val
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|pair
operator|<
name|VertexIterator
operator|,
name|bool
operator|>
name|insert
argument_list|(
argument|std::pair<VertexIdentifier
argument_list|,
argument|VertexAttribute>&&Val
argument_list|)
block|{
return|return
name|Vertices
operator|.
name|insert
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Val
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Inserts an edge into the graph with Identifier Val.first, and
end_comment

begin_comment
comment|/// Attribute Val.second. If the key is already in the map, it returns false
end_comment

begin_comment
comment|/// and doesn't update the value.
end_comment

begin_expr_stmt
name|std
operator|::
name|pair
operator|<
name|EdgeIterator
operator|,
name|bool
operator|>
name|insert
argument_list|(
argument|const std::pair<EdgeIdentifier
argument_list|,
argument|EdgeAttribute>&Val
argument_list|)
block|{
specifier|const
name|auto
operator|&
name|p
operator|=
name|Edges
operator|.
name|insert
argument_list|(
name|Val
argument_list|)
block|;
if|if
condition|(
name|p
operator|.
name|second
condition|)
block|{
specifier|const
specifier|auto
modifier|&
name|EI
init|=
name|Val
operator|.
name|first
decl_stmt|;
name|Vertices
operator|.
name|FindAndConstruct
argument_list|(
name|EI
operator|.
name|first
argument_list|)
expr_stmt|;
name|Vertices
operator|.
name|FindAndConstruct
argument_list|(
name|EI
operator|.
name|second
argument_list|)
expr_stmt|;
name|InNeighbors
index|[
name|EI
operator|.
name|second
index|]
operator|.
name|insert
argument_list|(
name|EI
operator|.
name|first
argument_list|)
expr_stmt|;
name|OutNeighbors
index|[
name|EI
operator|.
name|first
index|]
operator|.
name|insert
argument_list|(
name|EI
operator|.
name|second
argument_list|)
expr_stmt|;
block|}
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|p
return|;
end_return

begin_comment
unit|}
comment|/// Inserts an edge into the graph with Identifier Val.first, and
end_comment

begin_comment
comment|/// Attribute Val.second. If the key is already in the map, it returns false
end_comment

begin_comment
comment|/// and doesn't update the value.
end_comment

begin_expr_stmt
unit|std
operator|::
name|pair
operator|<
name|EdgeIterator
operator|,
name|bool
operator|>
name|insert
argument_list|(
argument|std::pair<EdgeIdentifier
argument_list|,
argument|EdgeAttribute>&&Val
argument_list|)
block|{
name|auto
name|EI
operator|=
name|Val
operator|.
name|first
block|;
specifier|const
name|auto
operator|&
name|p
operator|=
name|Edges
operator|.
name|insert
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Val
argument_list|)
argument_list|)
block|;
if|if
condition|(
name|p
operator|.
name|second
condition|)
block|{
name|Vertices
operator|.
name|FindAndConstruct
argument_list|(
name|EI
operator|.
name|first
argument_list|)
expr_stmt|;
name|Vertices
operator|.
name|FindAndConstruct
argument_list|(
name|EI
operator|.
name|second
argument_list|)
expr_stmt|;
name|InNeighbors
index|[
name|EI
operator|.
name|second
index|]
operator|.
name|insert
argument_list|(
name|EI
operator|.
name|first
argument_list|)
expr_stmt|;
name|OutNeighbors
index|[
name|EI
operator|.
name|first
index|]
operator|.
name|insert
argument_list|(
name|EI
operator|.
name|second
argument_list|)
expr_stmt|;
block|}
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|p
return|;
end_return

begin_empty_stmt
unit|} }
empty_stmt|;
end_empty_stmt

begin_endif
unit|} }
endif|#
directive|endif
end_endif

end_unit

