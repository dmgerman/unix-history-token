begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LazyCallGraph.h - Analysis of a Module's call graph ------*- C++ -*-===//
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
comment|/// \file
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Implements a lazy call graph analysis and related passes for the new pass
end_comment

begin_comment
comment|/// manager.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// NB: This is *not* a traditional call graph! It is a graph which models both
end_comment

begin_comment
comment|/// the current calls and potential calls. As a consequence there are many
end_comment

begin_comment
comment|/// edges in this call graph that do not correspond to a 'call' or 'invoke'
end_comment

begin_comment
comment|/// instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The primary use cases of this graph analysis is to facilitate iterating
end_comment

begin_comment
comment|/// across the functions of a module in ways that ensure all callees are
end_comment

begin_comment
comment|/// visited prior to a caller (given any SCC constraints), or vice versa. As
end_comment

begin_comment
comment|/// such is it particularly well suited to organizing CGSCC optimizations such
end_comment

begin_comment
comment|/// as inlining, outlining, argument promotion, etc. That is its primary use
end_comment

begin_comment
comment|/// case and motivates the design. It may not be appropriate for other
end_comment

begin_comment
comment|/// purposes. The use graph of functions or some other conservative analysis of
end_comment

begin_comment
comment|/// call instructions may be interesting for optimizations and subsequent
end_comment

begin_comment
comment|/// analyses which don't work in the context of an overly specified
end_comment

begin_comment
comment|/// potential-call-edge graph.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// To understand the specific rules and nature of this call graph analysis,
end_comment

begin_comment
comment|/// see the documentation of the \c LazyCallGraph below.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_ANALYSIS_LAZYCALLGRAPH_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_LAZYCALLGRAPH_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PointerUnion.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SetVector.h"
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
file|"llvm/ADT/iterator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/iterator_range.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/BasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Constants.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Function.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Module.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|<iterator>
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
name|PreservedAnalyses
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// A lazily constructed view of the call graph of a module.
comment|///
comment|/// With the edges of this graph, the motivating constraint that we are
comment|/// attempting to maintain is that function-local optimization, CGSCC-local
comment|/// optimizations, and optimizations transforming a pair of functions connected
comment|/// by an edge in the graph, do not invalidate a bottom-up traversal of the SCC
comment|/// DAG. That is, no optimizations will delete, remove, or add an edge such
comment|/// that functions already visited in a bottom-up order of the SCC DAG are no
comment|/// longer valid to have visited, or such that functions not yet visited in
comment|/// a bottom-up order of the SCC DAG are not required to have already been
comment|/// visited.
comment|///
comment|/// Within this constraint, the desire is to minimize the merge points of the
comment|/// SCC DAG. The greater the fanout of the SCC DAG and the fewer merge points
comment|/// in the SCC DAG, the more independence there is in optimizing within it.
comment|/// There is a strong desire to enable parallelization of optimizations over
comment|/// the call graph, and both limited fanout and merge points will (artificially
comment|/// in some cases) limit the scaling of such an effort.
comment|///
comment|/// To this end, graph represents both direct and any potential resolution to
comment|/// an indirect call edge. Another way to think about it is that it represents
comment|/// both the direct call edges and any direct call edges that might be formed
comment|/// through static optimizations. Specifically, it considers taking the address
comment|/// of a function to be an edge in the call graph because this might be
comment|/// forwarded to become a direct call by some subsequent function-local
comment|/// optimization. The result is that the graph closely follows the use-def
comment|/// edges for functions. Walking "up" the graph can be done by looking at all
comment|/// of the uses of a function.
comment|///
comment|/// The roots of the call graph are the external functions and functions
comment|/// escaped into global variables. Those functions can be called from outside
comment|/// of the module or via unknowable means in the IR -- we may not be able to
comment|/// form even a potential call edge from a function body which may dynamically
comment|/// load the function and call it.
comment|///
comment|/// This analysis still requires updates to remain valid after optimizations
comment|/// which could potentially change the set of potential callees. The
comment|/// constraints it operates under only make the traversal order remain valid.
comment|///
comment|/// The entire analysis must be re-computed if full interprocedural
comment|/// optimizations run at any point. For example, globalopt completely
comment|/// invalidates the information in this analysis.
comment|///
comment|/// FIXME: This class is named LazyCallGraph in a lame attempt to distinguish
comment|/// it from the existing CallGraph. At some point, it is expected that this
comment|/// will be the only call graph and it will be renamed accordingly.
name|class
name|LazyCallGraph
block|{
name|public
label|:
name|class
name|Node
decl_stmt|;
name|class
name|EdgeSequence
decl_stmt|;
name|class
name|SCC
decl_stmt|;
name|class
name|RefSCC
decl_stmt|;
name|class
name|edge_iterator
decl_stmt|;
name|class
name|call_edge_iterator
decl_stmt|;
comment|/// A class used to represent edges in the call graph.
comment|///
comment|/// The lazy call graph models both *call* edges and *reference* edges. Call
comment|/// edges are much what you would expect, and exist when there is a 'call' or
comment|/// 'invoke' instruction of some function. Reference edges are also tracked
comment|/// along side these, and exist whenever any instruction (transitively
comment|/// through its operands) references a function. All call edges are
comment|/// inherently reference edges, and so the reference graph forms a superset
comment|/// of the formal call graph.
comment|///
comment|/// All of these forms of edges are fundamentally represented as outgoing
comment|/// edges. The edges are stored in the source node and point at the target
comment|/// node. This allows the edge structure itself to be a very compact data
comment|/// structure: essentially a tagged pointer.
name|class
name|Edge
block|{
name|public
label|:
comment|/// The kind of edge in the graph.
enum|enum
name|Kind
enum|:
name|bool
block|{
name|Ref
init|=
name|false
block|,
name|Call
init|=
name|true
block|}
enum|;
name|Edge
argument_list|()
expr_stmt|;
name|explicit
name|Edge
parameter_list|(
name|Node
modifier|&
name|N
parameter_list|,
name|Kind
name|K
parameter_list|)
function_decl|;
comment|/// Test whether the edge is null.
comment|///
comment|/// This happens when an edge has been deleted. We leave the edge objects
comment|/// around but clear them.
name|explicit
name|operator
name|bool
argument_list|()
specifier|const
expr_stmt|;
comment|/// Returnss the \c Kind of the edge.
name|Kind
name|getKind
argument_list|()
specifier|const
expr_stmt|;
comment|/// Test whether the edge represents a direct call to a function.
comment|///
comment|/// This requires that the edge is not null.
name|bool
name|isCall
argument_list|()
specifier|const
expr_stmt|;
comment|/// Get the call graph node referenced by this edge.
comment|///
comment|/// This requires that the edge is not null.
name|Node
operator|&
name|getNode
argument_list|()
specifier|const
expr_stmt|;
comment|/// Get the function referenced by this edge.
comment|///
comment|/// This requires that the edge is not null.
name|Function
operator|&
name|getFunction
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|friend
name|class
name|LazyCallGraph
operator|::
name|EdgeSequence
expr_stmt|;
name|friend
name|class
name|LazyCallGraph
operator|::
name|RefSCC
expr_stmt|;
name|PointerIntPair
operator|<
name|Node
operator|*
operator|,
literal|1
operator|,
name|Kind
operator|>
name|Value
expr_stmt|;
name|void
name|setKind
parameter_list|(
name|Kind
name|K
parameter_list|)
block|{
name|Value
operator|.
name|setInt
argument_list|(
name|K
argument_list|)
expr_stmt|;
block|}
block|}
empty_stmt|;
comment|/// The edge sequence object.
comment|///
comment|/// This typically exists entirely within the node but is exposed as
comment|/// a separate type because a node doesn't initially have edges. An explicit
comment|/// population step is required to produce this sequence at first and it is
comment|/// then cached in the node. It is also used to represent edges entering the
comment|/// graph from outside the module to model the graph's roots.
comment|///
comment|/// The sequence itself both iterable and indexable. The indexes remain
comment|/// stable even as the sequence mutates (including removal).
name|class
name|EdgeSequence
block|{
name|friend
name|class
name|LazyCallGraph
decl_stmt|;
name|friend
name|class
name|LazyCallGraph
operator|::
name|Node
expr_stmt|;
name|friend
name|class
name|LazyCallGraph
operator|::
name|RefSCC
expr_stmt|;
typedef|typedef
name|SmallVector
operator|<
name|Edge
operator|,
literal|4
operator|>
name|VectorT
expr_stmt|;
typedef|typedef
name|SmallVectorImpl
operator|<
name|Edge
operator|>
name|VectorImplT
expr_stmt|;
name|public
label|:
comment|/// An iterator used for the edges to both entry nodes and child nodes.
name|class
name|iterator
range|:
name|public
name|iterator_adaptor_base
operator|<
name|iterator
decl_stmt|,
name|VectorImplT
decl|::
name|iterator
decl_stmt|,
name|std
decl|::
name|forward_iterator_tag
decl|>
block|{
name|friend
name|class
name|LazyCallGraph
decl_stmt|;
name|friend
name|class
name|LazyCallGraph
operator|::
name|Node
expr_stmt|;
name|VectorImplT
operator|::
name|iterator
name|E
expr_stmt|;
comment|// Build the iterator for a specific position in the edge list.
name|iterator
argument_list|(
argument|VectorImplT::iterator BaseI
argument_list|,
argument|VectorImplT::iterator E
argument_list|)
block|:
name|iterator_adaptor_base
argument_list|(
name|BaseI
argument_list|)
operator|,
name|E
argument_list|(
argument|E
argument_list|)
block|{
while|while
condition|(
name|I
operator|!=
name|E
operator|&&
operator|!
operator|*
name|I
condition|)
operator|++
name|I
expr_stmt|;
block|}
name|public
label|:
name|iterator
argument_list|()
block|{}
name|using
name|iterator_adaptor_base
operator|::
name|operator
operator|++
expr_stmt|;
name|iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
do|do
block|{
operator|++
name|I
expr_stmt|;
block|}
while|while
condition|(
name|I
operator|!=
name|E
operator|&&
operator|!
operator|*
name|I
condition|)
empty_stmt|;
do|return *this;       }     };
comment|/// An iterator over specifically call edges.
comment|///
comment|/// This has the same iteration properties as the \c iterator, but
comment|/// restricts itself to edges which represent actual calls.
do|class call_iterator         : public iterator_adaptor_base<call_iterator
operator|,
do|VectorImplT::iterator
operator|,
do|std::forward_iterator_tag>
block|{
name|friend
name|class
name|LazyCallGraph
decl_stmt|;
name|friend
name|class
name|LazyCallGraph
operator|::
name|Node
expr_stmt|;
name|VectorImplT
operator|::
name|iterator
name|E
expr_stmt|;
comment|/// Advance the iterator to the next valid, call edge.
name|void
name|advanceToNextEdge
parameter_list|()
block|{
while|while
condition|(
name|I
operator|!=
name|E
operator|&&
operator|(
operator|!
operator|*
name|I
operator|||
operator|!
name|I
operator|->
name|isCall
argument_list|()
operator|)
condition|)
operator|++
name|I
expr_stmt|;
block|}
comment|// Build the iterator for a specific position in the edge list.
function|call_iterator
parameter_list|(
function|VectorImplT::
name|iterator
name|BaseI
decl_stmt|,
name|VectorImplT
decl_stmt|::iterator E
block|)
do|: iterator_adaptor_base(BaseI
block|)
operator|,
name|E
argument_list|(
argument|E
argument_list|)
block|{
name|advanceToNextEdge
argument_list|()
block|;       }
name|public
operator|:
name|call_iterator
argument_list|()
block|{}
name|using
name|iterator_adaptor_base
operator|::
name|operator
operator|++
expr_stmt|;
name|call_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
operator|++
name|I
block|;
name|advanceToNextEdge
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
block|}
empty_stmt|;
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|iterator
argument_list|(
name|Edges
operator|.
name|begin
argument_list|()
argument_list|,
name|Edges
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
name|iterator
name|end
parameter_list|()
block|{
return|return
name|iterator
argument_list|(
name|Edges
operator|.
name|end
argument_list|()
argument_list|,
name|Edges
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
name|Edge
modifier|&
name|operator
function|[]
parameter_list|(
name|int
name|i
parameter_list|)
block|{
return|return
name|Edges
index|[
name|i
index|]
return|;
block|}
name|Edge
modifier|&
name|operator
function|[]
parameter_list|(
name|Node
modifier|&
name|N
parameter_list|)
block|{
name|assert
argument_list|(
name|EdgeIndexMap
operator|.
name|find
argument_list|(
operator|&
name|N
argument_list|)
operator|!=
name|EdgeIndexMap
operator|.
name|end
argument_list|()
operator|&&
literal|"No such edge!"
argument_list|)
expr_stmt|;
return|return
name|Edges
index|[
name|EdgeIndexMap
operator|.
name|find
argument_list|(
operator|&
name|N
argument_list|)
operator|->
name|second
index|]
return|;
block|}
name|Edge
modifier|*
name|lookup
parameter_list|(
name|Node
modifier|&
name|N
parameter_list|)
block|{
name|auto
name|EI
init|=
name|EdgeIndexMap
operator|.
name|find
argument_list|(
operator|&
name|N
argument_list|)
decl_stmt|;
return|return
name|EI
operator|!=
name|EdgeIndexMap
operator|.
name|end
argument_list|()
condition|?
operator|&
name|Edges
index|[
name|EI
operator|->
name|second
index|]
else|:
name|nullptr
return|;
block|}
name|call_iterator
name|call_begin
parameter_list|()
block|{
return|return
name|call_iterator
argument_list|(
name|Edges
operator|.
name|begin
argument_list|()
argument_list|,
name|Edges
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
name|call_iterator
name|call_end
parameter_list|()
block|{
return|return
name|call_iterator
argument_list|(
name|Edges
operator|.
name|end
argument_list|()
argument_list|,
name|Edges
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
name|iterator_range
operator|<
name|call_iterator
operator|>
name|calls
argument_list|()
block|{
return|return
name|make_range
argument_list|(
name|call_begin
argument_list|()
argument_list|,
name|call_end
argument_list|()
argument_list|)
return|;
block|}
name|bool
name|empty
parameter_list|()
block|{
for|for
control|(
name|auto
operator|&
name|E
operator|:
name|Edges
control|)
if|if
condition|(
name|E
condition|)
return|return
name|false
return|;
return|return
name|true
return|;
block|}
name|private
label|:
name|VectorT
name|Edges
decl_stmt|;
name|DenseMap
operator|<
name|Node
operator|*
operator|,
name|int
operator|>
name|EdgeIndexMap
expr_stmt|;
name|EdgeSequence
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// Internal helper to insert an edge to a node.
name|void
name|insertEdgeInternal
argument_list|(
name|Node
operator|&
name|ChildN
argument_list|,
name|Edge
operator|::
name|Kind
name|EK
argument_list|)
decl_stmt|;
comment|/// Internal helper to change an edge kind.
name|void
name|setEdgeKind
argument_list|(
name|Node
operator|&
name|ChildN
argument_list|,
name|Edge
operator|::
name|Kind
name|EK
argument_list|)
decl_stmt|;
comment|/// Internal helper to remove the edge to the given function.
name|bool
name|removeEdgeInternal
parameter_list|(
name|Node
modifier|&
name|ChildN
parameter_list|)
function_decl|;
comment|/// Internal helper to replace an edge key with a new one.
comment|///
comment|/// This should be used when the function for a particular node in the
comment|/// graph gets replaced and we are updating all of the edges to that node
comment|/// to use the new function as the key.
name|void
name|replaceEdgeKey
parameter_list|(
name|Function
modifier|&
name|OldTarget
parameter_list|,
name|Function
modifier|&
name|NewTarget
parameter_list|)
function_decl|;
block|}
empty_stmt|;
comment|/// A node in the call graph.
comment|///
comment|/// This represents a single node. It's primary roles are to cache the list of
comment|/// callees, de-duplicate and provide fast testing of whether a function is
comment|/// a callee, and facilitate iteration of child nodes in the graph.
comment|///
comment|/// The node works much like an optional in order to lazily populate the
comment|/// edges of each node. Until populated, there are no edges. Once populated,
comment|/// you can access the edges by dereferencing the node or using the `->`
comment|/// operator as if the node was an `Optional<EdgeSequence>`.
name|class
name|Node
block|{
name|friend
name|class
name|LazyCallGraph
decl_stmt|;
name|friend
name|class
name|LazyCallGraph
operator|::
name|RefSCC
expr_stmt|;
name|public
label|:
name|LazyCallGraph
operator|&
name|getGraph
argument_list|()
specifier|const
block|{
return|return
operator|*
name|G
return|;
block|}
name|Function
operator|&
name|getFunction
argument_list|()
specifier|const
block|{
return|return
operator|*
name|F
return|;
block|}
name|StringRef
name|getName
argument_list|()
specifier|const
block|{
return|return
name|F
operator|->
name|getName
argument_list|()
return|;
block|}
comment|/// Equality is defined as address equality.
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Node
operator|&
name|N
operator|)
specifier|const
block|{
return|return
name|this
operator|==
operator|&
name|N
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|Node
operator|&
name|N
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|N
operator|)
return|;
block|}
comment|/// Tests whether the node has been populated with edges.
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|Edges
operator|.
name|hasValue
argument_list|()
return|;
block|}
comment|// We allow accessing the edges by dereferencing or using the arrow
comment|// operator, essentially wrapping the internal optional.
name|EdgeSequence
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
comment|// Rip const off because the node itself isn't changing here.
return|return
name|const_cast
operator|<
name|EdgeSequence
operator|&
operator|>
operator|(
operator|*
name|Edges
operator|)
return|;
block|}
name|EdgeSequence
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
operator|&
operator|*
operator|*
name|this
return|;
block|}
comment|/// Populate the edges of this node if necessary.
comment|///
comment|/// The first time this is called it will populate the edges for this node
comment|/// in the graph. It does this by scanning the underlying function, so once
comment|/// this is done, any changes to that function must be explicitly reflected
comment|/// in updates to the graph.
comment|///
comment|/// \returns the populated \c EdgeSequence to simplify walking it.
comment|///
comment|/// This will not update or re-scan anything if called repeatedly. Instead,
comment|/// the edge sequence is cached and returned immediately on subsequent
comment|/// calls.
name|EdgeSequence
modifier|&
name|populate
parameter_list|()
block|{
if|if
condition|(
name|Edges
condition|)
return|return
operator|*
name|Edges
return|;
return|return
name|populateSlow
argument_list|()
return|;
block|}
name|private
label|:
name|LazyCallGraph
modifier|*
name|G
decl_stmt|;
name|Function
modifier|*
name|F
decl_stmt|;
comment|// We provide for the DFS numbering and Tarjan walk lowlink numbers to be
comment|// stored directly within the node. These are both '-1' when nodes are part
comment|// of an SCC (or RefSCC), or '0' when not yet reached in a DFS walk.
name|int
name|DFSNumber
decl_stmt|;
name|int
name|LowLink
decl_stmt|;
name|Optional
operator|<
name|EdgeSequence
operator|>
name|Edges
expr_stmt|;
comment|/// Basic constructor implements the scanning of F into Edges and
comment|/// EdgeIndexMap.
name|Node
argument_list|(
name|LazyCallGraph
operator|&
name|G
argument_list|,
name|Function
operator|&
name|F
argument_list|)
operator|:
name|G
argument_list|(
operator|&
name|G
argument_list|)
operator|,
name|F
argument_list|(
operator|&
name|F
argument_list|)
operator|,
name|DFSNumber
argument_list|(
literal|0
argument_list|)
operator|,
name|LowLink
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// Implementation of the scan when populating.
name|EdgeSequence
operator|&
name|populateSlow
argument_list|()
expr_stmt|;
comment|/// Internal helper to directly replace the function with a new one.
comment|///
comment|/// This is used to facilitate tranfsormations which need to replace the
comment|/// formal Function object but directly move the body and users from one to
comment|/// the other.
name|void
name|replaceFunction
parameter_list|(
name|Function
modifier|&
name|NewF
parameter_list|)
function_decl|;
name|void
name|clear
parameter_list|()
block|{
name|Edges
operator|.
name|reset
argument_list|()
expr_stmt|;
block|}
comment|/// Print the name of this node's function.
name|friend
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
name|Node
operator|&
name|N
operator|)
block|{
return|return
name|OS
operator|<<
name|N
operator|.
name|F
operator|->
name|getName
argument_list|()
return|;
block|}
comment|/// Dump the name of this node's function to stderr.
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
block|}
empty_stmt|;
comment|/// An SCC of the call graph.
comment|///
comment|/// This represents a Strongly Connected Component of the direct call graph
comment|/// -- ignoring indirect calls and function references. It stores this as
comment|/// a collection of call graph nodes. While the order of nodes in the SCC is
comment|/// stable, it is not any particular order.
comment|///
comment|/// The SCCs are nested within a \c RefSCC, see below for details about that
comment|/// outer structure. SCCs do not support mutation of the call graph, that
comment|/// must be done through the containing \c RefSCC in order to fully reason
comment|/// about the ordering and connections of the graph.
name|class
name|SCC
block|{
name|friend
name|class
name|LazyCallGraph
decl_stmt|;
name|friend
name|class
name|LazyCallGraph
operator|::
name|Node
expr_stmt|;
name|RefSCC
modifier|*
name|OuterRefSCC
decl_stmt|;
name|SmallVector
operator|<
name|Node
operator|*
operator|,
literal|1
operator|>
name|Nodes
expr_stmt|;
name|template
operator|<
name|typename
name|NodeRangeT
operator|>
name|SCC
argument_list|(
name|RefSCC
operator|&
name|OuterRefSCC
argument_list|,
name|NodeRangeT
operator|&&
name|Nodes
argument_list|)
operator|:
name|OuterRefSCC
argument_list|(
operator|&
name|OuterRefSCC
argument_list|)
operator|,
name|Nodes
argument_list|(
argument|std::forward<NodeRangeT>(Nodes)
argument_list|)
block|{}
name|void
name|clear
argument_list|()
block|{
name|OuterRefSCC
operator|=
name|nullptr
block|;
name|Nodes
operator|.
name|clear
argument_list|()
block|;     }
comment|/// Print a short descrtiption useful for debugging or logging.
comment|///
comment|/// We print the function names in the SCC wrapped in '()'s and skipping
comment|/// the middle functions if there are a large number.
comment|//
comment|// Note: this is defined inline to dodge issues with GCC's interpretation
comment|// of enclosing namespaces for friend function declarations.
name|friend
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
name|SCC
operator|&
name|C
operator|)
block|{
name|OS
operator|<<
literal|'('
block|;
name|int
name|i
operator|=
literal|0
block|;
for|for
control|(
name|LazyCallGraph
operator|::
name|Node
operator|&
name|N
operator|:
name|C
control|)
block|{
if|if
condition|(
name|i
operator|>
literal|0
condition|)
name|OS
operator|<<
literal|", "
expr_stmt|;
comment|// Elide the inner elements if there are too many.
if|if
condition|(
name|i
operator|>
literal|8
condition|)
block|{
name|OS
operator|<<
literal|"..., "
operator|<<
operator|*
name|C
operator|.
name|Nodes
operator|.
name|back
argument_list|()
expr_stmt|;
break|break;
block|}
name|OS
operator|<<
name|N
expr_stmt|;
operator|++
name|i
expr_stmt|;
block|}
name|OS
operator|<<
literal|')'
expr_stmt|;
return|return
name|OS
return|;
block|}
comment|/// Dump a short description of this SCC to stderr.
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
ifndef|#
directive|ifndef
name|NDEBUG
comment|/// Verify invariants about the SCC.
comment|///
comment|/// This will attempt to validate all of the basic invariants within an
comment|/// SCC, but not that it is a strongly connected componet per-se. Primarily
comment|/// useful while building and updating the graph to check that basic
comment|/// properties are in place rather than having inexplicable crashes later.
name|void
name|verify
parameter_list|()
function_decl|;
endif|#
directive|endif
name|public
label|:
typedef|typedef
name|pointee_iterator
operator|<
name|SmallVectorImpl
operator|<
name|Node
operator|*
operator|>
operator|::
name|const_iterator
operator|>
name|iterator
expr_stmt|;
name|iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|Nodes
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
name|Nodes
operator|.
name|end
argument_list|()
return|;
block|}
name|int
name|size
argument_list|()
specifier|const
block|{
return|return
name|Nodes
operator|.
name|size
argument_list|()
return|;
block|}
name|RefSCC
operator|&
name|getOuterRefSCC
argument_list|()
specifier|const
block|{
return|return
operator|*
name|OuterRefSCC
return|;
block|}
comment|/// Test if this SCC is a parent of \a C.
comment|///
comment|/// Note that this is linear in the number of edges departing the current
comment|/// SCC.
name|bool
name|isParentOf
argument_list|(
specifier|const
name|SCC
operator|&
name|C
argument_list|)
decl|const
decl_stmt|;
comment|/// Test if this SCC is an ancestor of \a C.
comment|///
comment|/// Note that in the worst case this is linear in the number of edges
comment|/// departing the current SCC and every SCC in the entire graph reachable
comment|/// from this SCC. Thus this very well may walk every edge in the entire
comment|/// call graph! Do not call this in a tight loop!
name|bool
name|isAncestorOf
argument_list|(
specifier|const
name|SCC
operator|&
name|C
argument_list|)
decl|const
decl_stmt|;
comment|/// Test if this SCC is a child of \a C.
comment|///
comment|/// See the comments for \c isParentOf for detailed notes about the
comment|/// complexity of this routine.
name|bool
name|isChildOf
argument_list|(
specifier|const
name|SCC
operator|&
name|C
argument_list|)
decl|const
block|{
return|return
name|C
operator|.
name|isParentOf
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
comment|/// Test if this SCC is a descendant of \a C.
comment|///
comment|/// See the comments for \c isParentOf for detailed notes about the
comment|/// complexity of this routine.
name|bool
name|isDescendantOf
argument_list|(
specifier|const
name|SCC
operator|&
name|C
argument_list|)
decl|const
block|{
return|return
name|C
operator|.
name|isAncestorOf
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
comment|/// Provide a short name by printing this SCC to a std::string.
comment|///
comment|/// This copes with the fact that we don't have a name per-se for an SCC
comment|/// while still making the use of this in debugging and logging useful.
name|std
operator|::
name|string
name|getName
argument_list|()
specifier|const
block|{
name|std
operator|::
name|string
name|Name
block|;
name|raw_string_ostream
name|OS
argument_list|(
name|Name
argument_list|)
block|;
name|OS
operator|<<
operator|*
name|this
block|;
name|OS
operator|.
name|flush
argument_list|()
block|;
return|return
name|Name
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// A RefSCC of the call graph.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This models a Strongly Connected Component of function reference edges in
end_comment

begin_comment
comment|/// the call graph. As opposed to actual SCCs, these can be used to scope
end_comment

begin_comment
comment|/// subgraphs of the module which are independent from other subgraphs of the
end_comment

begin_comment
comment|/// module because they do not reference it in any way. This is also the unit
end_comment

begin_comment
comment|/// where we do mutation of the graph in order to restrict mutations to those
end_comment

begin_comment
comment|/// which don't violate this independence.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// A RefSCC contains a DAG of actual SCCs. All the nodes within the RefSCC
end_comment

begin_comment
comment|/// are necessarily within some actual SCC that nests within it. Since
end_comment

begin_comment
comment|/// a direct call *is* a reference, there will always be at least one RefSCC
end_comment

begin_comment
comment|/// around any SCC.
end_comment

begin_decl_stmt
name|class
name|RefSCC
block|{
name|friend
name|class
name|LazyCallGraph
decl_stmt|;
name|friend
name|class
name|LazyCallGraph
operator|::
name|Node
expr_stmt|;
name|LazyCallGraph
modifier|*
name|G
decl_stmt|;
name|SmallPtrSet
operator|<
name|RefSCC
operator|*
operator|,
literal|1
operator|>
name|Parents
expr_stmt|;
comment|/// A postorder list of the inner SCCs.
name|SmallVector
operator|<
name|SCC
operator|*
operator|,
literal|4
operator|>
name|SCCs
expr_stmt|;
comment|/// A map from SCC to index in the postorder list.
name|SmallDenseMap
operator|<
name|SCC
operator|*
operator|,
name|int
operator|,
literal|4
operator|>
name|SCCIndices
expr_stmt|;
comment|/// Fast-path constructor. RefSCCs should instead be constructed by calling
comment|/// formRefSCCFast on the graph itself.
name|RefSCC
argument_list|(
name|LazyCallGraph
operator|&
name|G
argument_list|)
expr_stmt|;
name|void
name|clear
parameter_list|()
block|{
name|Parents
operator|.
name|clear
argument_list|()
expr_stmt|;
name|SCCs
operator|.
name|clear
argument_list|()
expr_stmt|;
name|SCCIndices
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
comment|/// Print a short description useful for debugging or logging.
comment|///
comment|/// We print the SCCs wrapped in '[]'s and skipping the middle SCCs if
comment|/// there are a large number.
comment|//
comment|// Note: this is defined inline to dodge issues with GCC's interpretation
comment|// of enclosing namespaces for friend function declarations.
name|friend
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
name|RefSCC
operator|&
name|RC
operator|)
block|{
name|OS
operator|<<
literal|'['
block|;
name|int
name|i
operator|=
literal|0
block|;
for|for
control|(
name|LazyCallGraph
operator|::
name|SCC
operator|&
name|C
operator|:
name|RC
control|)
block|{
if|if
condition|(
name|i
operator|>
literal|0
condition|)
name|OS
operator|<<
literal|", "
expr_stmt|;
comment|// Elide the inner elements if there are too many.
if|if
condition|(
name|i
operator|>
literal|4
condition|)
block|{
name|OS
operator|<<
literal|"..., "
operator|<<
operator|*
name|RC
operator|.
name|SCCs
operator|.
name|back
argument_list|()
expr_stmt|;
break|break;
block|}
name|OS
operator|<<
name|C
expr_stmt|;
operator|++
name|i
expr_stmt|;
block|}
name|OS
operator|<<
literal|']'
expr_stmt|;
return|return
name|OS
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Dump a short description of this RefSCC to stderr.
end_comment

begin_expr_stmt
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|NDEBUG
end_ifndef

begin_comment
comment|/// Verify invariants about the RefSCC and all its SCCs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This will attempt to validate all of the invariants *within* the
end_comment

begin_comment
comment|/// RefSCC, but not that it is a strongly connected component of the larger
end_comment

begin_comment
comment|/// graph. This makes it useful even when partially through an update.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Invariants checked:
end_comment

begin_comment
comment|/// - SCCs and their indices match.
end_comment

begin_comment
comment|/// - The SCCs list is in fact in post-order.
end_comment

begin_function_decl
name|void
name|verify
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// Handle any necessary parent set updates after inserting a trivial ref
end_comment

begin_comment
comment|/// or call edge.
end_comment

begin_function_decl
name|void
name|handleTrivialEdgeInsertion
parameter_list|(
name|Node
modifier|&
name|SourceN
parameter_list|,
name|Node
modifier|&
name|TargetN
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|public
label|:
end_label

begin_typedef
typedef|typedef
name|pointee_iterator
operator|<
name|SmallVectorImpl
operator|<
name|SCC
operator|*
operator|>
operator|::
name|const_iterator
operator|>
name|iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|iterator_range
operator|<
name|iterator
operator|>
name|range
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|pointee_iterator
operator|<
name|SmallPtrSetImpl
operator|<
name|RefSCC
operator|*
operator|>
operator|::
name|const_iterator
operator|>
name|parent_iterator
expr_stmt|;
end_typedef

begin_expr_stmt
name|iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|SCCs
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
name|SCCs
operator|.
name|end
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|ssize_t
name|size
argument_list|()
specifier|const
block|{
return|return
name|SCCs
operator|.
name|size
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
name|SCC
modifier|&
name|operator
function|[]
parameter_list|(
name|int
name|Idx
parameter_list|)
block|{
return|return
operator|*
name|SCCs
index|[
name|Idx
index|]
return|;
block|}
end_function

begin_decl_stmt
name|iterator
name|find
argument_list|(
name|SCC
operator|&
name|C
argument_list|)
decl|const
block|{
return|return
name|SCCs
operator|.
name|begin
argument_list|()
operator|+
name|SCCIndices
operator|.
name|find
argument_list|(
operator|&
name|C
argument_list|)
operator|->
name|second
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|parent_iterator
name|parent_begin
argument_list|()
specifier|const
block|{
return|return
name|Parents
operator|.
name|begin
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|parent_iterator
name|parent_end
argument_list|()
specifier|const
block|{
return|return
name|Parents
operator|.
name|end
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|iterator_range
operator|<
name|parent_iterator
operator|>
name|parents
argument_list|()
specifier|const
block|{
return|return
name|make_range
argument_list|(
name|parent_begin
argument_list|()
argument_list|,
name|parent_end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Test if this RefSCC is a parent of \a C.
end_comment

begin_decl_stmt
name|bool
name|isParentOf
argument_list|(
specifier|const
name|RefSCC
operator|&
name|C
argument_list|)
decl|const
block|{
return|return
name|C
operator|.
name|isChildOf
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Test if this RefSCC is an ancestor of \a C.
end_comment

begin_decl_stmt
name|bool
name|isAncestorOf
argument_list|(
specifier|const
name|RefSCC
operator|&
name|C
argument_list|)
decl|const
block|{
return|return
name|C
operator|.
name|isDescendantOf
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Test if this RefSCC is a child of \a C.
end_comment

begin_decl_stmt
name|bool
name|isChildOf
argument_list|(
specifier|const
name|RefSCC
operator|&
name|C
argument_list|)
decl|const
block|{
return|return
name|Parents
operator|.
name|count
argument_list|(
name|const_cast
operator|<
name|RefSCC
operator|*
operator|>
operator|(
operator|&
name|C
operator|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Test if this RefSCC is a descendant of \a C.
end_comment

begin_decl_stmt
name|bool
name|isDescendantOf
argument_list|(
specifier|const
name|RefSCC
operator|&
name|C
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Provide a short name by printing this RefSCC to a std::string.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This copes with the fact that we don't have a name per-se for an RefSCC
end_comment

begin_comment
comment|/// while still making the use of this in debugging and logging useful.
end_comment

begin_expr_stmt
name|std
operator|::
name|string
name|getName
argument_list|()
specifier|const
block|{
name|std
operator|::
name|string
name|Name
block|;
name|raw_string_ostream
name|OS
argument_list|(
name|Name
argument_list|)
block|;
name|OS
operator|<<
operator|*
name|this
block|;
name|OS
operator|.
name|flush
argument_list|()
block|;
return|return
name|Name
return|;
block|}
end_expr_stmt

begin_comment
comment|///@{
end_comment

begin_comment
comment|/// \name Mutation API
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// These methods provide the core API for updating the call graph in the
end_comment

begin_comment
comment|/// presence of (potentially still in-flight) DFS-found RefSCCs and SCCs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that these methods sometimes have complex runtimes, so be careful
end_comment

begin_comment
comment|/// how you call them.
end_comment

begin_comment
comment|/// Make an existing internal ref edge into a call edge.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This may form a larger cycle and thus collapse SCCs into TargetN's SCC.
end_comment

begin_comment
comment|/// If that happens, the optional callback \p MergedCB will be invoked (if
end_comment

begin_comment
comment|/// provided) on the SCCs being merged away prior to actually performing
end_comment

begin_comment
comment|/// the merge. Note that this will never include the target SCC as that
end_comment

begin_comment
comment|/// will be the SCC functions are merged into to resolve the cycle. Once
end_comment

begin_comment
comment|/// this function returns, these merged SCCs are not in a valid state but
end_comment

begin_comment
comment|/// the pointers will remain valid until destruction of the parent graph
end_comment

begin_comment
comment|/// instance for the purpose of clearing cached information. This function
end_comment

begin_comment
comment|/// also returns 'true' if a cycle was formed and some SCCs merged away as
end_comment

begin_comment
comment|/// a convenience.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// After this operation, both SourceN's SCC and TargetN's SCC may move
end_comment

begin_comment
comment|/// position within this RefSCC's postorder list. Any SCCs merged are
end_comment

begin_comment
comment|/// merged into the TargetN's SCC in order to preserve reachability analyses
end_comment

begin_comment
comment|/// which took place on that SCC.
end_comment

begin_decl_stmt
name|bool
name|switchInternalEdgeToCall
argument_list|(
name|Node
operator|&
name|SourceN
argument_list|,
name|Node
operator|&
name|TargetN
argument_list|,
name|function_ref
operator|<
name|void
argument_list|(
name|ArrayRef
operator|<
name|SCC
operator|*
operator|>
name|MergedSCCs
argument_list|)
operator|>
name|MergeCB
operator|=
block|{}
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Make an existing internal call edge between separate SCCs into a ref
end_comment

begin_comment
comment|/// edge.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If SourceN and TargetN in separate SCCs within this RefSCC, changing
end_comment

begin_comment
comment|/// the call edge between them to a ref edge is a trivial operation that
end_comment

begin_comment
comment|/// does not require any structural changes to the call graph.
end_comment

begin_function_decl
name|void
name|switchTrivialInternalEdgeToRef
parameter_list|(
name|Node
modifier|&
name|SourceN
parameter_list|,
name|Node
modifier|&
name|TargetN
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Make an existing internal call edge within a single SCC into a ref
end_comment

begin_comment
comment|/// edge.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Since SourceN and TargetN are part of a single SCC, this SCC may be
end_comment

begin_comment
comment|/// split up due to breaking a cycle in the call edges that formed it. If
end_comment

begin_comment
comment|/// that happens, then this routine will insert new SCCs into the postorder
end_comment

begin_comment
comment|/// list *before* the SCC of TargetN (previously the SCC of both). This
end_comment

begin_comment
comment|/// preserves postorder as the TargetN can reach all of the other nodes by
end_comment

begin_comment
comment|/// definition of previously being in a single SCC formed by the cycle from
end_comment

begin_comment
comment|/// SourceN to TargetN.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The newly added SCCs are added *immediately* and contiguously
end_comment

begin_comment
comment|/// prior to the TargetN SCC and return the range covering the new SCCs in
end_comment

begin_comment
comment|/// the RefSCC's postorder sequence. You can directly iterate the returned
end_comment

begin_comment
comment|/// range to observe all of the new SCCs in postorder.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that if SourceN and TargetN are in separate SCCs, the simpler
end_comment

begin_comment
comment|/// routine `switchTrivialInternalEdgeToRef` should be used instead.
end_comment

begin_expr_stmt
name|iterator_range
operator|<
name|iterator
operator|>
name|switchInternalEdgeToRef
argument_list|(
name|Node
operator|&
name|SourceN
argument_list|,
name|Node
operator|&
name|TargetN
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Make an existing outgoing ref edge into a call edge.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that this is trivial as there are no cyclic impacts and there
end_comment

begin_comment
comment|/// remains a reference edge.
end_comment

begin_function_decl
name|void
name|switchOutgoingEdgeToCall
parameter_list|(
name|Node
modifier|&
name|SourceN
parameter_list|,
name|Node
modifier|&
name|TargetN
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Make an existing outgoing call edge into a ref edge.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is trivial as there are no cyclic impacts and there remains
end_comment

begin_comment
comment|/// a reference edge.
end_comment

begin_function_decl
name|void
name|switchOutgoingEdgeToRef
parameter_list|(
name|Node
modifier|&
name|SourceN
parameter_list|,
name|Node
modifier|&
name|TargetN
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Insert a ref edge from one node in this RefSCC to another in this
end_comment

begin_comment
comment|/// RefSCC.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is always a trivial operation as it doesn't change any part of the
end_comment

begin_comment
comment|/// graph structure besides connecting the two nodes.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that we don't support directly inserting internal *call* edges
end_comment

begin_comment
comment|/// because that could change the graph structure and requires returning
end_comment

begin_comment
comment|/// information about what became invalid. As a consequence, the pattern
end_comment

begin_comment
comment|/// should be to first insert the necessary ref edge, and then to switch it
end_comment

begin_comment
comment|/// to a call edge if needed and handle any invalidation that results. See
end_comment

begin_comment
comment|/// the \c switchInternalEdgeToCall routine for details.
end_comment

begin_function_decl
name|void
name|insertInternalRefEdge
parameter_list|(
name|Node
modifier|&
name|SourceN
parameter_list|,
name|Node
modifier|&
name|TargetN
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Insert an edge whose parent is in this RefSCC and child is in some
end_comment

begin_comment
comment|/// child RefSCC.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// There must be an existing path from the \p SourceN to the \p TargetN.
end_comment

begin_comment
comment|/// This operation is inexpensive and does not change the set of SCCs and
end_comment

begin_comment
comment|/// RefSCCs in the graph.
end_comment

begin_decl_stmt
name|void
name|insertOutgoingEdge
argument_list|(
name|Node
operator|&
name|SourceN
argument_list|,
name|Node
operator|&
name|TargetN
argument_list|,
name|Edge
operator|::
name|Kind
name|EK
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Insert an edge whose source is in a descendant RefSCC and target is in
end_comment

begin_comment
comment|/// this RefSCC.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// There must be an existing path from the target to the source in this
end_comment

begin_comment
comment|/// case.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// NB! This is has the potential to be a very expensive function. It
end_comment

begin_comment
comment|/// inherently forms a cycle in the prior RefSCC DAG and we have to merge
end_comment

begin_comment
comment|/// RefSCCs to resolve that cycle. But finding all of the RefSCCs which
end_comment

begin_comment
comment|/// participate in the cycle can in the worst case require traversing every
end_comment

begin_comment
comment|/// RefSCC in the graph. Every attempt is made to avoid that, but passes
end_comment

begin_comment
comment|/// must still exercise caution calling this routine repeatedly.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Also note that this can only insert ref edges. In order to insert
end_comment

begin_comment
comment|/// a call edge, first insert a ref edge and then switch it to a call edge.
end_comment

begin_comment
comment|/// These are intentionally kept as separate interfaces because each step
end_comment

begin_comment
comment|/// of the operation invalidates a different set of data structures.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This returns all the RefSCCs which were merged into the this RefSCC
end_comment

begin_comment
comment|/// (the target's). This allows callers to invalidate any cached
end_comment

begin_comment
comment|/// information.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// FIXME: We could possibly optimize this quite a bit for cases where the
end_comment

begin_comment
comment|/// caller and callee are very nearby in the graph. See comments in the
end_comment

begin_comment
comment|/// implementation for details, but that use case might impact users.
end_comment

begin_expr_stmt
name|SmallVector
operator|<
name|RefSCC
operator|*
operator|,
literal|1
operator|>
name|insertIncomingRefEdge
argument_list|(
name|Node
operator|&
name|SourceN
argument_list|,
name|Node
operator|&
name|TargetN
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Remove an edge whose source is in this RefSCC and target is *not*.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This removes an inter-RefSCC edge. All inter-RefSCC edges originating
end_comment

begin_comment
comment|/// from this SCC have been fully explored by any in-flight DFS graph
end_comment

begin_comment
comment|/// formation, so this is always safe to call once you have the source
end_comment

begin_comment
comment|/// RefSCC.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This operation does not change the cyclic structure of the graph and so
end_comment

begin_comment
comment|/// is very inexpensive. It may change the connectivity graph of the SCCs
end_comment

begin_comment
comment|/// though, so be careful calling this while iterating over them.
end_comment

begin_function_decl
name|void
name|removeOutgoingEdge
parameter_list|(
name|Node
modifier|&
name|SourceN
parameter_list|,
name|Node
modifier|&
name|TargetN
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Remove a ref edge which is entirely within this RefSCC.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Both the \a SourceN and the \a TargetN must be within this RefSCC.
end_comment

begin_comment
comment|/// Removing such an edge may break cycles that form this RefSCC and thus
end_comment

begin_comment
comment|/// this operation may change the RefSCC graph significantly. In
end_comment

begin_comment
comment|/// particular, this operation will re-form new RefSCCs based on the
end_comment

begin_comment
comment|/// remaining connectivity of the graph. The following invariants are
end_comment

begin_comment
comment|/// guaranteed to hold after calling this method:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// 1) This RefSCC is still a RefSCC in the graph.
end_comment

begin_comment
comment|/// 2) This RefSCC will be the parent of any new RefSCCs. Thus, this RefSCC
end_comment

begin_comment
comment|///    is preserved as the root of any new RefSCC DAG formed.
end_comment

begin_comment
comment|/// 3) No RefSCC other than this RefSCC has its member set changed (this is
end_comment

begin_comment
comment|///    inherent in the definition of removing such an edge).
end_comment

begin_comment
comment|/// 4) All of the parent links of the RefSCC graph will be updated to
end_comment

begin_comment
comment|///    reflect the new RefSCC structure.
end_comment

begin_comment
comment|/// 5) All RefSCCs formed out of this RefSCC, excluding this RefSCC, will
end_comment

begin_comment
comment|///    be returned in post-order.
end_comment

begin_comment
comment|/// 6) The order of the RefSCCs in the vector will be a valid postorder
end_comment

begin_comment
comment|///    traversal of the new RefSCCs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// These invariants are very important to ensure that we can build
end_comment

begin_comment
comment|/// optimization pipelines on top of the CGSCC pass manager which
end_comment

begin_comment
comment|/// intelligently update the RefSCC graph without invalidating other parts
end_comment

begin_comment
comment|/// of the RefSCC graph.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that we provide no routine to remove a *call* edge. Instead, you
end_comment

begin_comment
comment|/// must first switch it to a ref edge using \c switchInternalEdgeToRef.
end_comment

begin_comment
comment|/// This split API is intentional as each of these two steps can invalidate
end_comment

begin_comment
comment|/// a different aspect of the graph structure and needs to have the
end_comment

begin_comment
comment|/// invalidation handled independently.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The runtime complexity of this method is, in the worst case, O(V+E)
end_comment

begin_comment
comment|/// where V is the number of nodes in this RefSCC and E is the number of
end_comment

begin_comment
comment|/// edges leaving the nodes in this RefSCC. Note that E includes both edges
end_comment

begin_comment
comment|/// within this RefSCC and edges from this RefSCC to child RefSCCs. Some
end_comment

begin_comment
comment|/// effort has been made to minimize the overhead of common cases such as
end_comment

begin_comment
comment|/// self-edges and edge removals which result in a spanning tree with no
end_comment

begin_comment
comment|/// more cycles. There are also detailed comments within the implementation
end_comment

begin_comment
comment|/// on techniques which could substantially improve this routine's
end_comment

begin_comment
comment|/// efficiency.
end_comment

begin_expr_stmt
name|SmallVector
operator|<
name|RefSCC
operator|*
operator|,
literal|1
operator|>
name|removeInternalRefEdge
argument_list|(
name|Node
operator|&
name|SourceN
argument_list|,
name|Node
operator|&
name|TargetN
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// A convenience wrapper around the above to handle trivial cases of
end_comment

begin_comment
comment|/// inserting a new call edge.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is trivial whenever the target is in the same SCC as the source or
end_comment

begin_comment
comment|/// the edge is an outgoing edge to some descendant SCC. In these cases
end_comment

begin_comment
comment|/// there is no change to the cyclic structure of SCCs or RefSCCs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// To further make calling this convenient, it also handles inserting
end_comment

begin_comment
comment|/// already existing edges.
end_comment

begin_function_decl
name|void
name|insertTrivialCallEdge
parameter_list|(
name|Node
modifier|&
name|SourceN
parameter_list|,
name|Node
modifier|&
name|TargetN
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// A convenience wrapper around the above to handle trivial cases of
end_comment

begin_comment
comment|/// inserting a new ref edge.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is trivial whenever the target is in the same RefSCC as the source
end_comment

begin_comment
comment|/// or the edge is an outgoing edge to some descendant RefSCC. In these
end_comment

begin_comment
comment|/// cases there is no change to the cyclic structure of the RefSCCs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// To further make calling this convenient, it also handles inserting
end_comment

begin_comment
comment|/// already existing edges.
end_comment

begin_function_decl
name|void
name|insertTrivialRefEdge
parameter_list|(
name|Node
modifier|&
name|SourceN
parameter_list|,
name|Node
modifier|&
name|TargetN
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Directly replace a node's function with a new function.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This should be used when moving the body and users of a function to
end_comment

begin_comment
comment|/// a new formal function object but not otherwise changing the call graph
end_comment

begin_comment
comment|/// structure in any way.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// It requires that the old function in the provided node have zero uses
end_comment

begin_comment
comment|/// and the new function must have calls and references to it establishing
end_comment

begin_comment
comment|/// an equivalent graph.
end_comment

begin_function_decl
name|void
name|replaceNodeFunction
parameter_list|(
name|Node
modifier|&
name|N
parameter_list|,
name|Function
modifier|&
name|NewF
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|///@}
end_comment

begin_comment
unit|};
comment|/// A post-order depth-first RefSCC iterator over the call graph.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This iterator walks the cached post-order sequence of RefSCCs. However,
end_comment

begin_comment
comment|/// it trades stability for flexibility. It is restricted to a forward
end_comment

begin_comment
comment|/// iterator but will survive mutations which insert new RefSCCs and continue
end_comment

begin_comment
comment|/// to point to the same RefSCC even if it moves in the post-order sequence.
end_comment

begin_decl_stmt
name|class
name|postorder_ref_scc_iterator
range|:
name|public
name|iterator_facade_base
operator|<
name|postorder_ref_scc_iterator
decl_stmt|,
name|std
decl|::
name|forward_iterator_tag
decl_stmt|,
name|RefSCC
decl|>
block|{
name|friend
name|class
name|LazyCallGraph
decl_stmt|;
name|friend
name|class
name|LazyCallGraph
operator|::
name|Node
expr_stmt|;
comment|/// Nonce type to select the constructor for the end iterator.
struct|struct
name|IsAtEndT
block|{}
struct|;
name|LazyCallGraph
modifier|*
name|G
decl_stmt|;
name|RefSCC
modifier|*
name|RC
decl_stmt|;
comment|/// Build the begin iterator for a node.
name|postorder_ref_scc_iterator
argument_list|(
name|LazyCallGraph
operator|&
name|G
argument_list|)
operator|:
name|G
argument_list|(
operator|&
name|G
argument_list|)
operator|,
name|RC
argument_list|(
argument|getRC(G,
literal|0
argument|)
argument_list|)
block|{}
comment|/// Build the end iterator for a node. This is selected purely by overload.
name|postorder_ref_scc_iterator
argument_list|(
name|LazyCallGraph
operator|&
name|G
argument_list|,
name|IsAtEndT
comment|/*Nonce*/
argument_list|)
operator|:
name|G
argument_list|(
operator|&
name|G
argument_list|)
operator|,
name|RC
argument_list|(
argument|nullptr
argument_list|)
block|{}
comment|/// Get the post-order RefSCC at the given index of the postorder walk,
comment|/// populating it if necessary.
specifier|static
name|RefSCC
operator|*
name|getRC
argument_list|(
argument|LazyCallGraph&G
argument_list|,
argument|int Index
argument_list|)
block|{
if|if
condition|(
name|Index
operator|==
operator|(
name|int
operator|)
name|G
operator|.
name|PostOrderRefSCCs
operator|.
name|size
argument_list|()
condition|)
comment|// We're at the end.
return|return
name|nullptr
return|;
return|return
name|G
operator|.
name|PostOrderRefSCCs
index|[
name|Index
index|]
return|;
block|}
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|postorder_ref_scc_iterator
operator|&
name|Arg
operator|)
specifier|const
block|{
return|return
name|G
operator|==
name|Arg
operator|.
name|G
operator|&&
name|RC
operator|==
name|Arg
operator|.
name|RC
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|reference
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
operator|*
name|RC
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|using
name|iterator_facade_base
operator|::
name|operator
operator|++
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|postorder_ref_scc_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
name|assert
argument_list|(
name|RC
operator|&&
literal|"Cannot increment the end iterator!"
argument_list|)
block|;
name|RC
operator|=
name|getRC
argument_list|(
operator|*
name|G
argument_list|,
name|G
operator|->
name|RefSCCIndices
operator|.
name|find
argument_list|(
name|RC
argument_list|)
operator|->
name|second
operator|+
literal|1
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// Construct a graph for the given module.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This sets up the graph and computes all of the entry points of the graph.
end_comment

begin_comment
comment|/// No function definitions are scanned until their nodes in the graph are
end_comment

begin_comment
comment|/// requested during traversal.
end_comment

begin_expr_stmt
name|LazyCallGraph
argument_list|(
name|Module
operator|&
name|M
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LazyCallGraph
argument_list|(
name|LazyCallGraph
operator|&&
name|G
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|LazyCallGraph
modifier|&
name|operator
init|=
operator|(
name|LazyCallGraph
operator|&&
name|RHS
operator|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|EdgeSequence
operator|::
name|iterator
name|begin
argument_list|()
block|{
return|return
name|EntryEdges
operator|.
name|begin
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|EdgeSequence
operator|::
name|iterator
name|end
argument_list|()
block|{
return|return
name|EntryEdges
operator|.
name|end
argument_list|()
return|;
block|}
end_expr_stmt

begin_function_decl
name|void
name|buildRefSCCs
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|postorder_ref_scc_iterator
name|postorder_ref_scc_begin
parameter_list|()
block|{
if|if
condition|(
operator|!
name|EntryEdges
operator|.
name|empty
argument_list|()
condition|)
name|assert
argument_list|(
operator|!
name|PostOrderRefSCCs
operator|.
name|empty
argument_list|()
operator|&&
literal|"Must form RefSCCs before iterating them!"
argument_list|)
expr_stmt|;
return|return
name|postorder_ref_scc_iterator
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
end_function

begin_function
name|postorder_ref_scc_iterator
name|postorder_ref_scc_end
parameter_list|()
block|{
if|if
condition|(
operator|!
name|EntryEdges
operator|.
name|empty
argument_list|()
condition|)
name|assert
argument_list|(
operator|!
name|PostOrderRefSCCs
operator|.
name|empty
argument_list|()
operator|&&
literal|"Must form RefSCCs before iterating them!"
argument_list|)
expr_stmt|;
return|return
name|postorder_ref_scc_iterator
argument_list|(
operator|*
name|this
argument_list|,
name|postorder_ref_scc_iterator
operator|::
name|IsAtEndT
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|iterator_range
operator|<
name|postorder_ref_scc_iterator
operator|>
name|postorder_ref_sccs
argument_list|()
block|{
return|return
name|make_range
argument_list|(
name|postorder_ref_scc_begin
argument_list|()
argument_list|,
name|postorder_ref_scc_end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Lookup a function in the graph which has already been scanned and added.
end_comment

begin_decl_stmt
name|Node
modifier|*
name|lookup
argument_list|(
specifier|const
name|Function
operator|&
name|F
argument_list|)
decl|const
block|{
return|return
name|NodeMap
operator|.
name|lookup
argument_list|(
operator|&
name|F
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Lookup a function's SCC in the graph.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns null if the function hasn't been assigned an SCC via the RefSCC
end_comment

begin_comment
comment|/// iterator walk.
end_comment

begin_decl_stmt
name|SCC
modifier|*
name|lookupSCC
argument_list|(
name|Node
operator|&
name|N
argument_list|)
decl|const
block|{
return|return
name|SCCMap
operator|.
name|lookup
argument_list|(
operator|&
name|N
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Lookup a function's RefSCC in the graph.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns null if the function hasn't been assigned a RefSCC via the
end_comment

begin_comment
comment|/// RefSCC iterator walk.
end_comment

begin_decl_stmt
name|RefSCC
modifier|*
name|lookupRefSCC
argument_list|(
name|Node
operator|&
name|N
argument_list|)
decl|const
block|{
if|if
condition|(
name|SCC
modifier|*
name|C
init|=
name|lookupSCC
argument_list|(
name|N
argument_list|)
condition|)
return|return
operator|&
name|C
operator|->
name|getOuterRefSCC
argument_list|()
return|;
return|return
name|nullptr
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Get a graph node for a given function, scanning it to populate the graph
end_comment

begin_comment
comment|/// data as necessary.
end_comment

begin_function
name|Node
modifier|&
name|get
parameter_list|(
name|Function
modifier|&
name|F
parameter_list|)
block|{
name|Node
modifier|*
modifier|&
name|N
init|=
name|NodeMap
index|[
operator|&
name|F
index|]
decl_stmt|;
if|if
condition|(
name|N
condition|)
return|return
operator|*
name|N
return|;
return|return
name|insertInto
argument_list|(
name|F
argument_list|,
name|N
argument_list|)
return|;
block|}
end_function

begin_comment
comment|///@{
end_comment

begin_comment
comment|/// \name Pre-SCC Mutation API
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// These methods are only valid to call prior to forming any SCCs for this
end_comment

begin_comment
comment|/// call graph. They can be used to update the core node-graph during
end_comment

begin_comment
comment|/// a node-based inorder traversal that precedes any SCC-based traversal.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Once you begin manipulating a call graph's SCCs, most mutation of the
end_comment

begin_comment
comment|/// graph must be performed via a RefSCC method. There are some exceptions
end_comment

begin_comment
comment|/// below.
end_comment

begin_comment
comment|/// Update the call graph after inserting a new edge.
end_comment

begin_decl_stmt
name|void
name|insertEdge
argument_list|(
name|Node
operator|&
name|SourceN
argument_list|,
name|Node
operator|&
name|TargetN
argument_list|,
name|Edge
operator|::
name|Kind
name|EK
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Update the call graph after inserting a new edge.
end_comment

begin_decl_stmt
name|void
name|insertEdge
argument_list|(
name|Function
operator|&
name|Source
argument_list|,
name|Function
operator|&
name|Target
argument_list|,
name|Edge
operator|::
name|Kind
name|EK
argument_list|)
block|{
return|return
name|insertEdge
argument_list|(
name|get
argument_list|(
name|Source
argument_list|)
argument_list|,
name|get
argument_list|(
name|Target
argument_list|)
argument_list|,
name|EK
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Update the call graph after deleting an edge.
end_comment

begin_function_decl
name|void
name|removeEdge
parameter_list|(
name|Node
modifier|&
name|SourceN
parameter_list|,
name|Node
modifier|&
name|TargetN
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Update the call graph after deleting an edge.
end_comment

begin_function
name|void
name|removeEdge
parameter_list|(
name|Function
modifier|&
name|Source
parameter_list|,
name|Function
modifier|&
name|Target
parameter_list|)
block|{
return|return
name|removeEdge
argument_list|(
name|get
argument_list|(
name|Source
argument_list|)
argument_list|,
name|get
argument_list|(
name|Target
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|///@}
end_comment

begin_comment
comment|///@{
end_comment

begin_comment
comment|/// \name General Mutation API
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// There are a very limited set of mutations allowed on the graph as a whole
end_comment

begin_comment
comment|/// once SCCs have started to be formed. These routines have strict contracts
end_comment

begin_comment
comment|/// but may be called at any point.
end_comment

begin_comment
comment|/// Remove a dead function from the call graph (typically to delete it).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that the function must have an empty use list, and the call graph
end_comment

begin_comment
comment|/// must be up-to-date prior to calling this. That means it is by itself in
end_comment

begin_comment
comment|/// a maximal SCC which is by itself in a maximal RefSCC, etc. No structural
end_comment

begin_comment
comment|/// changes result from calling this routine other than potentially removing
end_comment

begin_comment
comment|/// entry points into the call graph.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If SCC formation has begun, this function must not be part of the current
end_comment

begin_comment
comment|/// DFS in order to call this safely. Typically, the function will have been
end_comment

begin_comment
comment|/// fully visited by the DFS prior to calling this routine.
end_comment

begin_function_decl
name|void
name|removeDeadFunction
parameter_list|(
name|Function
modifier|&
name|F
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|///@}
end_comment

begin_comment
comment|///@{
end_comment

begin_comment
comment|/// \name Static helpers for code doing updates to the call graph.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// These helpers are used to implement parts of the call graph but are also
end_comment

begin_comment
comment|/// useful to code doing updates or otherwise wanting to walk the IR in the
end_comment

begin_comment
comment|/// same patterns as when we build the call graph.
end_comment

begin_comment
comment|/// Recursively visits the defined functions whose address is reachable from
end_comment

begin_comment
comment|/// every constant in the \p Worklist.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Doesn't recurse through any constants already in the \p Visited set, and
end_comment

begin_comment
comment|/// updates that set with every constant visited.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// For each defined function, calls \p Callback with that function.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|CallbackT
operator|>
specifier|static
name|void
name|visitReferences
argument_list|(
argument|SmallVectorImpl<Constant *>&Worklist
argument_list|,
argument|SmallPtrSetImpl<Constant *>&Visited
argument_list|,
argument|CallbackT Callback
argument_list|)
block|{
while|while
condition|(
operator|!
name|Worklist
operator|.
name|empty
argument_list|()
condition|)
block|{
name|Constant
modifier|*
name|C
init|=
name|Worklist
operator|.
name|pop_back_val
argument_list|()
decl_stmt|;
if|if
condition|(
name|Function
modifier|*
name|F
init|=
name|dyn_cast
operator|<
name|Function
operator|>
operator|(
name|C
operator|)
condition|)
block|{
if|if
condition|(
operator|!
name|F
operator|->
name|isDeclaration
argument_list|()
condition|)
name|Callback
argument_list|(
operator|*
name|F
argument_list|)
expr_stmt|;
continue|continue;
block|}
end_expr_stmt

begin_if
if|if
condition|(
name|BlockAddress
modifier|*
name|BA
init|=
name|dyn_cast
operator|<
name|BlockAddress
operator|>
operator|(
name|C
operator|)
condition|)
block|{
comment|// The blockaddress constant expression is a weird special case, we
comment|// can't generically walk its operands the way we do for all other
comment|// constants.
if|if
condition|(
name|Visited
operator|.
name|insert
argument_list|(
name|BA
operator|->
name|getFunction
argument_list|()
argument_list|)
operator|.
name|second
condition|)
name|Worklist
operator|.
name|push_back
argument_list|(
name|BA
operator|->
name|getFunction
argument_list|()
argument_list|)
expr_stmt|;
continue|continue;
block|}
end_if

begin_for
for|for
control|(
name|Value
modifier|*
name|Op
range|:
name|C
operator|->
name|operand_values
argument_list|()
control|)
if|if
condition|(
name|Visited
operator|.
name|insert
argument_list|(
name|cast
operator|<
name|Constant
operator|>
operator|(
name|Op
operator|)
argument_list|)
operator|.
name|second
condition|)
name|Worklist
operator|.
name|push_back
argument_list|(
name|cast
operator|<
name|Constant
operator|>
operator|(
name|Op
operator|)
argument_list|)
expr_stmt|;
end_for

begin_comment
unit|}   }
comment|///@}
end_comment

begin_label
name|private
label|:
end_label

begin_typedef
typedef|typedef
name|SmallVectorImpl
operator|<
name|Node
operator|*
operator|>
operator|::
name|reverse_iterator
name|node_stack_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|iterator_range
operator|<
name|node_stack_iterator
operator|>
name|node_stack_range
expr_stmt|;
end_typedef

begin_comment
comment|/// Allocator that holds all the call graph nodes.
end_comment

begin_expr_stmt
name|SpecificBumpPtrAllocator
operator|<
name|Node
operator|>
name|BPA
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Maps function->node for fast lookup.
end_comment

begin_expr_stmt
name|DenseMap
operator|<
specifier|const
name|Function
operator|*
operator|,
name|Node
operator|*
operator|>
name|NodeMap
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// The entry edges into the graph.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// These edges are from "external" sources. Put another way, they
end_comment

begin_comment
comment|/// escape at the module scope.
end_comment

begin_decl_stmt
name|EdgeSequence
name|EntryEdges
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Allocator that holds all the call graph SCCs.
end_comment

begin_expr_stmt
name|SpecificBumpPtrAllocator
operator|<
name|SCC
operator|>
name|SCCBPA
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Maps Function -> SCC for fast lookup.
end_comment

begin_expr_stmt
name|DenseMap
operator|<
name|Node
operator|*
operator|,
name|SCC
operator|*
operator|>
name|SCCMap
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Allocator that holds all the call graph RefSCCs.
end_comment

begin_expr_stmt
name|SpecificBumpPtrAllocator
operator|<
name|RefSCC
operator|>
name|RefSCCBPA
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// The post-order sequence of RefSCCs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This list is lazily formed the first time we walk the graph.
end_comment

begin_expr_stmt
name|SmallVector
operator|<
name|RefSCC
operator|*
operator|,
literal|16
operator|>
name|PostOrderRefSCCs
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// A map from RefSCC to the index for it in the postorder sequence of
end_comment

begin_comment
comment|/// RefSCCs.
end_comment

begin_expr_stmt
name|DenseMap
operator|<
name|RefSCC
operator|*
operator|,
name|int
operator|>
name|RefSCCIndices
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// The leaf RefSCCs of the graph.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// These are all of the RefSCCs which have no children.
end_comment

begin_expr_stmt
name|SmallVector
operator|<
name|RefSCC
operator|*
operator|,
literal|4
operator|>
name|LeafRefSCCs
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Helper to insert a new function, with an already looked-up entry in
end_comment

begin_comment
comment|/// the NodeMap.
end_comment

begin_function_decl
name|Node
modifier|&
name|insertInto
parameter_list|(
name|Function
modifier|&
name|F
parameter_list|,
name|Node
modifier|*
modifier|&
name|MappedN
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Helper to update pointers back to the graph object during moves.
end_comment

begin_function_decl
name|void
name|updateGraphPtrs
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Allocates an SCC and constructs it using the graph allocator.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The arguments are forwarded to the constructor.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
operator|...
name|Ts
operator|>
name|SCC
operator|*
name|createSCC
argument_list|(
argument|Ts&&... Args
argument_list|)
block|{
return|return
name|new
argument_list|(
argument|SCCBPA.Allocate()
argument_list|)
name|SCC
argument_list|(
name|std
operator|::
name|forward
operator|<
name|Ts
operator|>
operator|(
name|Args
operator|)
operator|...
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Allocates a RefSCC and constructs it using the graph allocator.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The arguments are forwarded to the constructor.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
operator|...
name|Ts
operator|>
name|RefSCC
operator|*
name|createRefSCC
argument_list|(
argument|Ts&&... Args
argument_list|)
block|{
return|return
name|new
argument_list|(
argument|RefSCCBPA.Allocate()
argument_list|)
name|RefSCC
argument_list|(
name|std
operator|::
name|forward
operator|<
name|Ts
operator|>
operator|(
name|Args
operator|)
operator|...
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Common logic for building SCCs from a sequence of roots.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is a very generic implementation of the depth-first walk and SCC
end_comment

begin_comment
comment|/// formation algorithm. It uses a generic sequence of roots and generic
end_comment

begin_comment
comment|/// callbacks for each step. This is designed to be used to implement both
end_comment

begin_comment
comment|/// the RefSCC formation and SCC formation with shared logic.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Currently this is a relatively naive implementation of Tarjan's DFS
end_comment

begin_comment
comment|/// algorithm to form the SCCs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// FIXME: We should consider newer variants such as Nuutila.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|RootsT
operator|,
name|typename
name|GetBeginT
operator|,
name|typename
name|GetEndT
operator|,
name|typename
name|GetNodeT
operator|,
name|typename
name|FormSCCCallbackT
operator|>
specifier|static
name|void
name|buildGenericSCCs
argument_list|(
name|RootsT
operator|&&
name|Roots
argument_list|,
name|GetBeginT
operator|&&
name|GetBegin
argument_list|,
name|GetEndT
operator|&&
name|GetEnd
argument_list|,
name|GetNodeT
operator|&&
name|GetNode
argument_list|,
name|FormSCCCallbackT
operator|&&
name|FormSCC
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Build the SCCs for a RefSCC out of a list of nodes.
end_comment

begin_function_decl
name|void
name|buildSCCs
parameter_list|(
name|RefSCC
modifier|&
name|RC
parameter_list|,
name|node_stack_range
name|Nodes
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Connect a RefSCC into the larger graph.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This walks the edges to connect the RefSCC to its children's parent set,
end_comment

begin_comment
comment|/// and updates the root leaf list.
end_comment

begin_function_decl
name|void
name|connectRefSCC
parameter_list|(
name|RefSCC
modifier|&
name|RC
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Get the index of a RefSCC within the postorder traversal.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Requires that this RefSCC is a valid one in the (perhaps partial)
end_comment

begin_comment
comment|/// postorder traversed part of the graph.
end_comment

begin_function
name|int
name|getRefSCCIndex
parameter_list|(
name|RefSCC
modifier|&
name|RC
parameter_list|)
block|{
name|auto
name|IndexIt
init|=
name|RefSCCIndices
operator|.
name|find
argument_list|(
operator|&
name|RC
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|IndexIt
operator|!=
name|RefSCCIndices
operator|.
name|end
argument_list|()
operator|&&
literal|"RefSCC doesn't have an index!"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|PostOrderRefSCCs
index|[
name|IndexIt
operator|->
name|second
index|]
operator|==
operator|&
name|RC
operator|&&
literal|"Index does not point back at RC!"
argument_list|)
expr_stmt|;
return|return
name|IndexIt
operator|->
name|second
return|;
block|}
end_function

begin_expr_stmt
unit|};
specifier|inline
name|LazyCallGraph
operator|::
name|Edge
operator|::
name|Edge
argument_list|()
operator|:
name|Value
argument_list|()
block|{}
specifier|inline
name|LazyCallGraph
operator|::
name|Edge
operator|::
name|Edge
argument_list|(
argument|Node&N
argument_list|,
argument|Kind K
argument_list|)
operator|:
name|Value
argument_list|(
argument|&N
argument_list|,
argument|K
argument_list|)
block|{}
specifier|inline
name|LazyCallGraph
operator|::
name|Edge
operator|::
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|.
name|getPointer
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|LazyCallGraph
operator|::
name|Edge
operator|::
name|Kind
name|LazyCallGraph
operator|::
name|Edge
operator|::
name|getKind
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|*
name|this
operator|&&
literal|"Queried a null edge!"
argument_list|)
block|;
return|return
name|Value
operator|.
name|getInt
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|bool
name|LazyCallGraph
operator|::
name|Edge
operator|::
name|isCall
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|*
name|this
operator|&&
literal|"Queried a null edge!"
argument_list|)
block|;
return|return
name|getKind
argument_list|()
operator|==
name|Call
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|LazyCallGraph
operator|::
name|Node
operator|&
name|LazyCallGraph
operator|::
name|Edge
operator|::
name|getNode
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|*
name|this
operator|&&
literal|"Queried a null edge!"
argument_list|)
block|;
return|return
operator|*
name|Value
operator|.
name|getPointer
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|Function
operator|&
name|LazyCallGraph
operator|::
name|Edge
operator|::
name|getFunction
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|*
name|this
operator|&&
literal|"Queried a null edge!"
argument_list|)
block|;
return|return
name|getNode
argument_list|()
operator|.
name|getFunction
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|// Provide GraphTraits specializations for call graphs.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|GraphTraits
operator|<
name|LazyCallGraph
operator|::
name|Node
operator|*
operator|>
block|{
typedef|typedef
name|LazyCallGraph
operator|::
name|Node
operator|*
name|NodeRef
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|LazyCallGraph
operator|::
name|EdgeSequence
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
name|NodeRef
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
name|ChildIteratorType
name|child_begin
parameter_list|(
name|NodeRef
name|N
parameter_list|)
block|{
return|return
operator|(
operator|*
name|N
operator|)
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
operator|(
operator|*
name|N
operator|)
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
name|LazyCallGraph
operator|*
operator|>
block|{
typedef|typedef
name|LazyCallGraph
operator|::
name|Node
operator|*
name|NodeRef
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|LazyCallGraph
operator|::
name|EdgeSequence
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
name|NodeRef
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
name|ChildIteratorType
name|child_begin
parameter_list|(
name|NodeRef
name|N
parameter_list|)
block|{
return|return
operator|(
operator|*
name|N
operator|)
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
operator|(
operator|*
name|N
operator|)
operator|->
name|end
argument_list|()
return|;
block|}
end_function

begin_comment
unit|};
comment|/// An analysis pass which computes the call graph for a module.
end_comment

begin_decl_stmt
name|class
name|LazyCallGraphAnalysis
range|:
name|public
name|AnalysisInfoMixin
operator|<
name|LazyCallGraphAnalysis
operator|>
block|{
name|friend
name|AnalysisInfoMixin
operator|<
name|LazyCallGraphAnalysis
operator|>
block|;
specifier|static
name|AnalysisKey
name|Key
block|;
name|public
operator|:
comment|/// Inform generic clients of the result type.
typedef|typedef
name|LazyCallGraph
name|Result
typedef|;
comment|/// Compute the \c LazyCallGraph for the module \c M.
comment|///
comment|/// This just builds the set of entry points to the call graph. The rest is
comment|/// built lazily as it is walked.
name|LazyCallGraph
name|run
argument_list|(
argument|Module&M
argument_list|,
argument|ModuleAnalysisManager&
argument_list|)
block|{
return|return
name|LazyCallGraph
argument_list|(
name|M
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// A pass which prints the call graph to a \c raw_ostream.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is primarily useful for testing the analysis.
end_comment

begin_decl_stmt
name|class
name|LazyCallGraphPrinterPass
range|:
name|public
name|PassInfoMixin
operator|<
name|LazyCallGraphPrinterPass
operator|>
block|{
name|raw_ostream
operator|&
name|OS
block|;
name|public
operator|:
name|explicit
name|LazyCallGraphPrinterPass
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
block|;
name|PreservedAnalyses
name|run
argument_list|(
name|Module
operator|&
name|M
argument_list|,
name|ModuleAnalysisManager
operator|&
name|AM
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// A pass which prints the call graph as a DOT file to a \c raw_ostream.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is primarily useful for visualization purposes.
end_comment

begin_decl_stmt
name|class
name|LazyCallGraphDOTPrinterPass
range|:
name|public
name|PassInfoMixin
operator|<
name|LazyCallGraphDOTPrinterPass
operator|>
block|{
name|raw_ostream
operator|&
name|OS
block|;
name|public
operator|:
name|explicit
name|LazyCallGraphDOTPrinterPass
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
block|;
name|PreservedAnalyses
name|run
argument_list|(
name|Module
operator|&
name|M
argument_list|,
name|ModuleAnalysisManager
operator|&
name|AM
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

