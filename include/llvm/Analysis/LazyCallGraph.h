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
name|LLVM_ANALYSIS_LAZY_CALL_GRAPH
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_LAZY_CALL_GRAPH
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
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|<iterator>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ModuleAnalysisManager
decl_stmt|;
name|class
name|PreservedAnalyses
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// \brief A lazily constructed view of the call graph of a module.
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
name|SCC
decl_stmt|;
typedef|typedef
name|SmallVector
operator|<
name|PointerUnion
operator|<
name|Function
operator|*
operator|,
name|Node
operator|*
operator|>
operator|,
literal|4
operator|>
name|NodeVectorT
expr_stmt|;
typedef|typedef
name|SmallVectorImpl
operator|<
name|PointerUnion
operator|<
name|Function
operator|*
operator|,
name|Node
operator|*
operator|>>
name|NodeVectorImplT
expr_stmt|;
comment|/// \brief A lazy iterator used for both the entry nodes and child nodes.
comment|///
comment|/// When this iterator is dereferenced, if not yet available, a function will
comment|/// be scanned for "calls" or uses of functions and its child information
comment|/// will be constructed. All of these results are accumulated and cached in
comment|/// the graph.
name|class
name|iterator
range|:
name|public
name|iterator_adaptor_base
operator|<
name|iterator
decl_stmt|,
name|NodeVectorImplT
decl|::
name|iterator
decl_stmt|,
name|std
decl|::
name|forward_iterator_tag
decl_stmt|,
name|Node
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
name|LazyCallGraph
modifier|*
name|G
decl_stmt|;
name|NodeVectorImplT
operator|::
name|iterator
name|E
expr_stmt|;
comment|// Build the iterator for a specific position in a node list.
name|iterator
argument_list|(
argument|LazyCallGraph&G
argument_list|,
argument|NodeVectorImplT::iterator NI
argument_list|,
argument|NodeVectorImplT::iterator E
argument_list|)
block|:
name|iterator_adaptor_base
argument_list|(
name|NI
argument_list|)
operator|,
name|G
argument_list|(
operator|&
name|G
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
name|I
operator|->
name|isNull
argument_list|()
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
name|I
operator|->
name|isNull
argument_list|()
condition|)
empty_stmt|;
do|return *this;     }      reference operator*(
block|)
specifier|const
block|{
if|if
condition|(
name|I
operator|->
name|is
operator|<
name|Node
operator|*
operator|>
operator|(
operator|)
condition|)
return|return
operator|*
name|I
operator|->
name|get
operator|<
name|Node
operator|*
operator|>
operator|(
operator|)
return|;
name|Function
operator|*
name|F
operator|=
name|I
operator|->
name|get
operator|<
name|Function
operator|*
operator|>
operator|(
operator|)
expr_stmt|;
name|Node
modifier|&
name|ChildN
init|=
name|G
operator|->
name|get
argument_list|(
operator|*
name|F
argument_list|)
decl_stmt|;
operator|*
name|I
operator|=
operator|&
name|ChildN
expr_stmt|;
return|return
name|ChildN
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief A node in the call graph.
comment|///
comment|/// This represents a single node. It's primary roles are to cache the list of
comment|/// callees, de-duplicate and provide fast testing of whether a function is
comment|/// a callee, and facilitate iteration of child nodes in the graph.
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
name|SCC
expr_stmt|;
name|LazyCallGraph
modifier|*
name|G
decl_stmt|;
name|Function
modifier|&
name|F
decl_stmt|;
comment|// We provide for the DFS numbering and Tarjan walk lowlink numbers to be
comment|// stored directly within the node.
name|int
name|DFSNumber
decl_stmt|;
name|int
name|LowLink
decl_stmt|;
name|mutable
name|NodeVectorT
name|Callees
decl_stmt|;
name|DenseMap
operator|<
name|Function
operator|*
operator|,
name|size_t
operator|>
name|CalleeIndexMap
expr_stmt|;
comment|/// \brief Basic constructor implements the scanning of F into Callees and
comment|/// CalleeIndexMap.
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
expr_stmt|;
comment|/// \brief Internal helper to insert a callee.
name|void
name|insertEdgeInternal
parameter_list|(
name|Function
modifier|&
name|Callee
parameter_list|)
function_decl|;
comment|/// \brief Internal helper to insert a callee.
name|void
name|insertEdgeInternal
parameter_list|(
name|Node
modifier|&
name|CalleeN
parameter_list|)
function_decl|;
comment|/// \brief Internal helper to remove a callee from this node.
name|void
name|removeEdgeInternal
parameter_list|(
name|Function
modifier|&
name|Callee
parameter_list|)
function_decl|;
name|public
label|:
typedef|typedef
name|LazyCallGraph
operator|::
name|iterator
name|iterator
expr_stmt|;
name|Function
operator|&
name|getFunction
argument_list|()
specifier|const
block|{
return|return
name|F
return|;
block|}
empty_stmt|;
name|iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|iterator
argument_list|(
operator|*
name|G
argument_list|,
name|Callees
operator|.
name|begin
argument_list|()
argument_list|,
name|Callees
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
name|iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|iterator
argument_list|(
operator|*
name|G
argument_list|,
name|Callees
operator|.
name|end
argument_list|()
argument_list|,
name|Callees
operator|.
name|end
argument_list|()
argument_list|)
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
block|}
empty_stmt|;
comment|/// \brief An SCC of the call graph.
comment|///
comment|/// This represents a Strongly Connected Component of the call graph as
comment|/// a collection of call graph nodes. While the order of nodes in the SCC is
comment|/// stable, it is not any particular order.
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
name|LazyCallGraph
modifier|*
name|G
decl_stmt|;
name|SmallPtrSet
operator|<
name|SCC
operator|*
operator|,
literal|1
operator|>
name|ParentSCCs
expr_stmt|;
name|SmallVector
operator|<
name|Node
operator|*
operator|,
literal|1
operator|>
name|Nodes
expr_stmt|;
name|SCC
argument_list|(
name|LazyCallGraph
operator|&
name|G
argument_list|)
operator|:
name|G
argument_list|(
argument|&G
argument_list|)
block|{}
name|void
name|insert
argument_list|(
name|Node
operator|&
name|N
argument_list|)
expr_stmt|;
name|void
name|internalDFS
argument_list|(
name|SmallVectorImpl
operator|<
name|std
operator|::
name|pair
operator|<
name|Node
operator|*
argument_list|,
name|Node
operator|::
name|iterator
operator|>>
operator|&
name|DFSStack
argument_list|,
name|SmallVectorImpl
operator|<
name|Node
operator|*
operator|>
operator|&
name|PendingSCCStack
argument_list|,
name|Node
operator|*
name|N
argument_list|,
name|SmallVectorImpl
operator|<
name|SCC
operator|*
operator|>
operator|&
name|ResultSCCs
argument_list|)
decl_stmt|;
name|public
label|:
typedef|typedef
name|SmallVectorImpl
operator|<
name|Node
operator|*
operator|>
operator|::
name|const_iterator
name|iterator
expr_stmt|;
typedef|typedef
name|pointee_iterator
operator|<
name|SmallPtrSet
operator|<
name|SCC
operator|*
operator|,
literal|1
operator|>
operator|::
name|const_iterator
operator|>
name|parent_iterator
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
name|parent_iterator
name|parent_begin
argument_list|()
specifier|const
block|{
return|return
name|ParentSCCs
operator|.
name|begin
argument_list|()
return|;
block|}
name|parent_iterator
name|parent_end
argument_list|()
specifier|const
block|{
return|return
name|ParentSCCs
operator|.
name|end
argument_list|()
return|;
block|}
name|iterator_range
operator|<
name|parent_iterator
operator|>
name|parents
argument_list|()
specifier|const
block|{
return|return
name|iterator_range
operator|<
name|parent_iterator
operator|>
operator|(
name|parent_begin
argument_list|()
operator|,
name|parent_end
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Test if this SCC is a parent of \a C.
name|bool
name|isParentOf
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
name|isChildOf
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
comment|/// \brief Test if this SCC is an ancestor of \a C.
name|bool
name|isAncestorOf
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
name|isDescendantOf
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
comment|/// \brief Test if this SCC is a child of \a C.
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
name|ParentSCCs
operator|.
name|count
argument_list|(
name|const_cast
operator|<
name|SCC
operator|*
operator|>
operator|(
operator|&
name|C
operator|)
argument_list|)
return|;
block|}
comment|/// \brief Test if this SCC is a descendant of \a C.
name|bool
name|isDescendantOf
argument_list|(
specifier|const
name|SCC
operator|&
name|C
argument_list|)
decl|const
decl_stmt|;
comment|///@{
comment|/// \name Mutation API
comment|///
comment|/// These methods provide the core API for updating the call graph in the
comment|/// presence of a (potentially still in-flight) DFS-found SCCs.
comment|///
comment|/// Note that these methods sometimes have complex runtimes, so be careful
comment|/// how you call them.
comment|/// \brief Insert an edge from one node in this SCC to another in this SCC.
comment|///
comment|/// By the definition of an SCC, this does not change the nature or make-up
comment|/// of any SCCs.
name|void
name|insertIntraSCCEdge
parameter_list|(
name|Node
modifier|&
name|CallerN
parameter_list|,
name|Node
modifier|&
name|CalleeN
parameter_list|)
function_decl|;
comment|/// \brief Insert an edge whose tail is in this SCC and head is in some
comment|/// child SCC.
comment|///
comment|/// There must be an existing path from the caller to the callee. This
comment|/// operation is inexpensive and does not change the set of SCCs in the
comment|/// graph.
name|void
name|insertOutgoingEdge
parameter_list|(
name|Node
modifier|&
name|CallerN
parameter_list|,
name|Node
modifier|&
name|CalleeN
parameter_list|)
function_decl|;
comment|/// \brief Insert an edge whose tail is in a descendant SCC and head is in
comment|/// this SCC.
comment|///
comment|/// There must be an existing path from the callee to the caller in this
comment|/// case. NB! This is has the potential to be a very expensive function. It
comment|/// inherently forms a cycle in the prior SCC DAG and we have to merge SCCs
comment|/// to resolve that cycle. But finding all of the SCCs which participate in
comment|/// the cycle can in the worst case require traversing every SCC in the
comment|/// graph. Every attempt is made to avoid that, but passes must still
comment|/// exercise caution calling this routine repeatedly.
comment|///
comment|/// FIXME: We could possibly optimize this quite a bit for cases where the
comment|/// caller and callee are very nearby in the graph. See comments in the
comment|/// implementation for details, but that use case might impact users.
name|SmallVector
operator|<
name|SCC
operator|*
operator|,
literal|1
operator|>
name|insertIncomingEdge
argument_list|(
name|Node
operator|&
name|CallerN
argument_list|,
name|Node
operator|&
name|CalleeN
argument_list|)
expr_stmt|;
comment|/// \brief Remove an edge whose source is in this SCC and target is *not*.
comment|///
comment|/// This removes an inter-SCC edge. All inter-SCC edges originating from
comment|/// this SCC have been fully explored by any in-flight DFS SCC formation,
comment|/// so this is always safe to call once you have the source SCC.
comment|///
comment|/// This operation does not change the set of SCCs or the members of the
comment|/// SCCs and so is very inexpensive. It may change the connectivity graph
comment|/// of the SCCs though, so be careful calling this while iterating over
comment|/// them.
name|void
name|removeInterSCCEdge
parameter_list|(
name|Node
modifier|&
name|CallerN
parameter_list|,
name|Node
modifier|&
name|CalleeN
parameter_list|)
function_decl|;
comment|/// \brief Remove an edge which is entirely within this SCC.
comment|///
comment|/// Both the \a Caller and the \a Callee must be within this SCC. Removing
comment|/// such an edge make break cycles that form this SCC and thus this
comment|/// operation may change the SCC graph significantly. In particular, this
comment|/// operation will re-form new SCCs based on the remaining connectivity of
comment|/// the graph. The following invariants are guaranteed to hold after
comment|/// calling this method:
comment|///
comment|/// 1) This SCC is still an SCC in the graph.
comment|/// 2) This SCC will be the parent of any new SCCs. Thus, this SCC is
comment|///    preserved as the root of any new SCC directed graph formed.
comment|/// 3) No SCC other than this SCC has its member set changed (this is
comment|///    inherent in the definition of removing such an edge).
comment|/// 4) All of the parent links of the SCC graph will be updated to reflect
comment|///    the new SCC structure.
comment|/// 5) All SCCs formed out of this SCC, excluding this SCC, will be
comment|///    returned in a vector.
comment|/// 6) The order of the SCCs in the vector will be a valid postorder
comment|///    traversal of the new SCCs.
comment|///
comment|/// These invariants are very important to ensure that we can build
comment|/// optimization pipeliens on top of the CGSCC pass manager which
comment|/// intelligently update the SCC graph without invalidating other parts of
comment|/// the SCC graph.
comment|///
comment|/// The runtime complexity of this method is, in the worst case, O(V+E)
comment|/// where V is the number of nodes in this SCC and E is the number of edges
comment|/// leaving the nodes in this SCC. Note that E includes both edges within
comment|/// this SCC and edges from this SCC to child SCCs. Some effort has been
comment|/// made to minimize the overhead of common cases such as self-edges and
comment|/// edge removals which result in a spanning tree with no more cycles.
name|SmallVector
operator|<
name|SCC
operator|*
operator|,
literal|1
operator|>
name|removeIntraSCCEdge
argument_list|(
name|Node
operator|&
name|CallerN
argument_list|,
name|Node
operator|&
name|CalleeN
argument_list|)
expr_stmt|;
comment|///@}
block|}
empty_stmt|;
comment|/// \brief A post-order depth-first SCC iterator over the call graph.
comment|///
comment|/// This iterator triggers the Tarjan DFS-based formation of the SCC DAG for
comment|/// the call graph, walking it lazily in depth-first post-order. That is, it
comment|/// always visits SCCs for a callee prior to visiting the SCC for a caller
comment|/// (when they are in different SCCs).
name|class
name|postorder_scc_iterator
range|:
name|public
name|iterator_facade_base
operator|<
name|postorder_scc_iterator
decl_stmt|,
name|std
decl|::
name|forward_iterator_tag
decl_stmt|,
name|SCC
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
comment|/// \brief Nonce type to select the constructor for the end iterator.
struct|struct
name|IsAtEndT
block|{}
struct|;
name|LazyCallGraph
modifier|*
name|G
decl_stmt|;
name|SCC
modifier|*
name|C
decl_stmt|;
comment|// Build the begin iterator for a node.
name|postorder_scc_iterator
argument_list|(
name|LazyCallGraph
operator|&
name|G
argument_list|)
operator|:
name|G
argument_list|(
argument|&G
argument_list|)
block|{
name|C
operator|=
name|G
operator|.
name|getNextSCCInPostOrder
argument_list|()
block|;     }
comment|// Build the end iterator for a node. This is selected purely by overload.
name|postorder_scc_iterator
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
name|C
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|public
operator|:
name|bool
name|operator
operator|==
operator|(
specifier|const
name|postorder_scc_iterator
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
name|C
operator|==
name|Arg
operator|.
name|C
return|;
block|}
name|reference
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
operator|*
name|C
return|;
block|}
name|using
name|iterator_facade_base
operator|::
name|operator
operator|++
expr_stmt|;
name|postorder_scc_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
name|C
operator|=
name|G
operator|->
name|getNextSCCInPostOrder
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief Construct a graph for the given module.
comment|///
comment|/// This sets up the graph and computes all of the entry points of the graph.
comment|/// No function definitions are scanned until their nodes in the graph are
comment|/// requested during traversal.
name|LazyCallGraph
argument_list|(
name|Module
operator|&
name|M
argument_list|)
expr_stmt|;
name|LazyCallGraph
argument_list|(
name|LazyCallGraph
operator|&&
name|G
argument_list|)
expr_stmt|;
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
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|iterator
argument_list|(
operator|*
name|this
argument_list|,
name|EntryNodes
operator|.
name|begin
argument_list|()
argument_list|,
name|EntryNodes
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
operator|*
name|this
argument_list|,
name|EntryNodes
operator|.
name|end
argument_list|()
argument_list|,
name|EntryNodes
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
name|postorder_scc_iterator
name|postorder_scc_begin
parameter_list|()
block|{
return|return
name|postorder_scc_iterator
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
name|postorder_scc_iterator
name|postorder_scc_end
parameter_list|()
block|{
return|return
name|postorder_scc_iterator
argument_list|(
operator|*
name|this
argument_list|,
name|postorder_scc_iterator
operator|::
name|IsAtEndT
argument_list|()
argument_list|)
return|;
block|}
name|iterator_range
operator|<
name|postorder_scc_iterator
operator|>
name|postorder_sccs
argument_list|()
block|{
return|return
name|iterator_range
operator|<
name|postorder_scc_iterator
operator|>
operator|(
name|postorder_scc_begin
argument_list|()
operator|,
name|postorder_scc_end
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Lookup a function in the graph which has already been scanned and
comment|/// added.
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
comment|/// \brief Lookup a function's SCC in the graph.
comment|///
comment|/// \returns null if the function hasn't been assigned an SCC via the SCC
comment|/// iterator walk.
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
comment|/// \brief Get a graph node for a given function, scanning it to populate the
comment|/// graph data as necessary.
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
comment|///@{
comment|/// \name Pre-SCC Mutation API
comment|///
comment|/// These methods are only valid to call prior to forming any SCCs for this
comment|/// call graph. They can be used to update the core node-graph during
comment|/// a node-based inorder traversal that precedes any SCC-based traversal.
comment|///
comment|/// Once you begin manipulating a call graph's SCCs, you must perform all
comment|/// mutation of the graph via the SCC methods.
comment|/// \brief Update the call graph after inserting a new edge.
name|void
name|insertEdge
parameter_list|(
name|Node
modifier|&
name|Caller
parameter_list|,
name|Function
modifier|&
name|Callee
parameter_list|)
function_decl|;
comment|/// \brief Update the call graph after inserting a new edge.
name|void
name|insertEdge
parameter_list|(
name|Function
modifier|&
name|Caller
parameter_list|,
name|Function
modifier|&
name|Callee
parameter_list|)
block|{
return|return
name|insertEdge
argument_list|(
name|get
argument_list|(
name|Caller
argument_list|)
argument_list|,
name|Callee
argument_list|)
return|;
block|}
comment|/// \brief Update the call graph after deleting an edge.
name|void
name|removeEdge
parameter_list|(
name|Node
modifier|&
name|Caller
parameter_list|,
name|Function
modifier|&
name|Callee
parameter_list|)
function_decl|;
comment|/// \brief Update the call graph after deleting an edge.
name|void
name|removeEdge
parameter_list|(
name|Function
modifier|&
name|Caller
parameter_list|,
name|Function
modifier|&
name|Callee
parameter_list|)
block|{
return|return
name|removeEdge
argument_list|(
name|get
argument_list|(
name|Caller
argument_list|)
argument_list|,
name|Callee
argument_list|)
return|;
block|}
comment|///@}
name|private
label|:
comment|/// \brief Allocator that holds all the call graph nodes.
name|SpecificBumpPtrAllocator
operator|<
name|Node
operator|>
name|BPA
expr_stmt|;
comment|/// \brief Maps function->node for fast lookup.
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
comment|/// \brief The entry nodes to the graph.
comment|///
comment|/// These nodes are reachable through "external" means. Put another way, they
comment|/// escape at the module scope.
name|NodeVectorT
name|EntryNodes
decl_stmt|;
comment|/// \brief Map of the entry nodes in the graph to their indices in
comment|/// \c EntryNodes.
name|DenseMap
operator|<
name|Function
operator|*
operator|,
name|size_t
operator|>
name|EntryIndexMap
expr_stmt|;
comment|/// \brief Allocator that holds all the call graph SCCs.
name|SpecificBumpPtrAllocator
operator|<
name|SCC
operator|>
name|SCCBPA
expr_stmt|;
comment|/// \brief Maps Function -> SCC for fast lookup.
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
comment|/// \brief The leaf SCCs of the graph.
comment|///
comment|/// These are all of the SCCs which have no children.
name|SmallVector
operator|<
name|SCC
operator|*
operator|,
literal|4
operator|>
name|LeafSCCs
expr_stmt|;
comment|/// \brief Stack of nodes in the DFS walk.
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|Node
operator|*
operator|,
name|iterator
operator|>
operator|,
literal|4
operator|>
name|DFSStack
expr_stmt|;
comment|/// \brief Set of entry nodes not-yet-processed into SCCs.
name|SmallVector
operator|<
name|Function
operator|*
operator|,
literal|4
operator|>
name|SCCEntryNodes
expr_stmt|;
comment|/// \brief Stack of nodes the DFS has walked but not yet put into a SCC.
name|SmallVector
operator|<
name|Node
operator|*
operator|,
literal|4
operator|>
name|PendingSCCStack
expr_stmt|;
comment|/// \brief Counter for the next DFS number to assign.
name|int
name|NextDFSNumber
decl_stmt|;
comment|/// \brief Helper to insert a new function, with an already looked-up entry in
comment|/// the NodeMap.
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
comment|/// \brief Helper to update pointers back to the graph object during moves.
name|void
name|updateGraphPtrs
parameter_list|()
function_decl|;
comment|/// \brief Helper to form a new SCC out of the top of a DFSStack-like
comment|/// structure.
name|SCC
modifier|*
name|formSCC
argument_list|(
name|Node
operator|*
name|RootN
argument_list|,
name|SmallVectorImpl
operator|<
name|Node
operator|*
operator|>
operator|&
name|NodeStack
argument_list|)
decl_stmt|;
comment|/// \brief Retrieve the next node in the post-order SCC walk of the call graph.
name|SCC
modifier|*
name|getNextSCCInPostOrder
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

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
name|NodeType
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|LazyCallGraph
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
name|LazyCallGraph
operator|*
operator|>
block|{
typedef|typedef
name|LazyCallGraph
operator|::
name|Node
name|NodeType
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|LazyCallGraph
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
unit|};
comment|/// \brief An analysis pass which computes the call graph for a module.
end_comment

begin_decl_stmt
name|class
name|LazyCallGraphAnalysis
block|{
name|public
label|:
comment|/// \brief Inform generic clients of the result type.
typedef|typedef
name|LazyCallGraph
name|Result
typedef|;
specifier|static
name|void
modifier|*
name|ID
parameter_list|()
block|{
return|return
operator|(
name|void
operator|*
operator|)
operator|&
name|PassID
return|;
block|}
comment|/// \brief Compute the \c LazyCallGraph for a the module \c M.
comment|///
comment|/// This just builds the set of entry points to the call graph. The rest is
comment|/// built lazily as it is walked.
name|LazyCallGraph
name|run
parameter_list|(
name|Module
modifier|*
name|M
parameter_list|)
block|{
return|return
name|LazyCallGraph
argument_list|(
operator|*
name|M
argument_list|)
return|;
block|}
name|private
label|:
specifier|static
name|char
name|PassID
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief A pass which prints the call graph to a \c raw_ostream.
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
block|{
name|raw_ostream
modifier|&
name|OS
decl_stmt|;
name|public
label|:
name|explicit
name|LazyCallGraphPrinterPass
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
name|PreservedAnalyses
name|run
parameter_list|(
name|Module
modifier|*
name|M
parameter_list|,
name|ModuleAnalysisManager
modifier|*
name|AM
parameter_list|)
function_decl|;
specifier|static
name|StringRef
name|name
parameter_list|()
block|{
return|return
literal|"LazyCallGraphPrinterPass"
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

