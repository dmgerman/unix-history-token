begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- ADT/SCCIterator.h - Strongly Connected Comp. Iter. ----*- C++ -*-===//
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
comment|/// This builds on the llvm/ADT/GraphTraits.h file to find the strongly
end_comment

begin_comment
comment|/// connected components (SCCs) of a graph in O(N+E) time using Tarjan's DFS
end_comment

begin_comment
comment|/// algorithm.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The SCC iterator has the important property that if a node in SCC S1 has an
end_comment

begin_comment
comment|/// edge to a node in SCC S2, then it visits S1 *after* S2.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// To visit S1 *before* S2, use the scc_iterator on the Inverse graph. (NOTE:
end_comment

begin_comment
comment|/// This requires some simple wrappers and is not supported yet.)
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
name|LLVM_ADT_SCCITERATOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_SCCITERATOR_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/GraphTraits.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/iterator.h"
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
comment|/// \brief Enumerate the SCCs of a directed graph in reverse topological order
comment|/// of the SCC DAG.
comment|///
comment|/// This is implemented using Tarjan's DFS algorithm using an internal stack to
comment|/// build up a vector of nodes in a particular SCC. Note that it is a forward
comment|/// iterator and thus you cannot backtrack or re-visit nodes.
name|template
operator|<
name|class
name|GraphT
operator|,
name|class
name|GT
operator|=
name|GraphTraits
operator|<
name|GraphT
operator|>>
name|class
name|scc_iterator
operator|:
name|public
name|iterator_facade_base
operator|<
name|scc_iterator
operator|<
name|GraphT
operator|,
name|GT
operator|>
operator|,
name|std
operator|::
name|forward_iterator_tag
operator|,
specifier|const
name|std
operator|::
name|vector
operator|<
name|typename
name|GT
operator|::
name|NodeType
operator|*
operator|>
operator|,
name|ptrdiff_t
operator|>
block|{
typedef|typedef
name|typename
name|GT
operator|::
name|NodeType
name|NodeType
expr_stmt|;
typedef|typedef
name|typename
name|GT
operator|::
name|ChildIteratorType
name|ChildItTy
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|NodeType
operator|*
operator|>
name|SccTy
expr_stmt|;
typedef|typedef
name|typename
name|scc_iterator
operator|::
name|reference
name|reference
expr_stmt|;
comment|/// Element of VisitStack during DFS.
struct|struct
name|StackElement
block|{
name|NodeType
modifier|*
name|Node
decl_stmt|;
comment|///< The current node pointer.
name|ChildItTy
name|NextChild
decl_stmt|;
comment|///< The next child, modified inplace during DFS.
name|unsigned
name|MinVisited
decl_stmt|;
comment|///< Minimum uplink value of all children of Node.
name|StackElement
argument_list|(
argument|NodeType *Node
argument_list|,
argument|const ChildItTy&Child
argument_list|,
argument|unsigned Min
argument_list|)
block|:
name|Node
argument_list|(
name|Node
argument_list|)
operator|,
name|NextChild
argument_list|(
name|Child
argument_list|)
operator|,
name|MinVisited
argument_list|(
argument|Min
argument_list|)
block|{}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|StackElement
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|Node
operator|==
name|Other
operator|.
name|Node
operator|&&
name|NextChild
operator|==
name|Other
operator|.
name|NextChild
operator|&&
name|MinVisited
operator|==
name|Other
operator|.
name|MinVisited
return|;
block|}
block|}
struct|;
comment|/// The visit counters used to detect when a complete SCC is on the stack.
comment|/// visitNum is the global counter.
comment|///
comment|/// nodeVisitNumbers are per-node visit numbers, also used as DFS flags.
name|unsigned
name|visitNum
decl_stmt|;
name|DenseMap
operator|<
name|NodeType
operator|*
operator|,
name|unsigned
operator|>
name|nodeVisitNumbers
expr_stmt|;
comment|/// Stack holding nodes of the SCC.
name|std
operator|::
name|vector
operator|<
name|NodeType
operator|*
operator|>
name|SCCNodeStack
expr_stmt|;
comment|/// The current SCC, retrieved using operator*().
name|SccTy
name|CurrentSCC
decl_stmt|;
comment|/// DFS stack, Used to maintain the ordering.  The top contains the current
comment|/// node, the next child to visit, and the minimum uplink value of all child
name|std
operator|::
name|vector
operator|<
name|StackElement
operator|>
name|VisitStack
expr_stmt|;
comment|/// A single "visit" within the non-recursive DFS traversal.
name|void
name|DFSVisitOne
parameter_list|(
name|NodeType
modifier|*
name|N
parameter_list|)
function_decl|;
comment|/// The stack-based DFS traversal; defined below.
name|void
name|DFSVisitChildren
parameter_list|()
function_decl|;
comment|/// Compute the next SCC using the DFS traversal.
name|void
name|GetNextSCC
parameter_list|()
function_decl|;
name|scc_iterator
argument_list|(
name|NodeType
operator|*
name|entryN
argument_list|)
operator|:
name|visitNum
argument_list|(
literal|0
argument_list|)
block|{
name|DFSVisitOne
argument_list|(
name|entryN
argument_list|)
block|;
name|GetNextSCC
argument_list|()
block|;   }
comment|/// End is when the DFS stack is empty.
name|scc_iterator
argument_list|()
block|{}
name|public
operator|:
specifier|static
name|scc_iterator
name|begin
argument_list|(
argument|const GraphT&G
argument_list|)
block|{
return|return
name|scc_iterator
argument_list|(
name|GT
operator|::
name|getEntryNode
argument_list|(
name|G
argument_list|)
argument_list|)
return|;
block|}
specifier|static
name|scc_iterator
name|end
parameter_list|(
specifier|const
name|GraphT
modifier|&
parameter_list|)
block|{
return|return
name|scc_iterator
argument_list|()
return|;
block|}
comment|/// \brief Direct loop termination test which is more efficient than
comment|/// comparison with \c end().
name|bool
name|isAtEnd
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|CurrentSCC
operator|.
name|empty
argument_list|()
operator|||
name|VisitStack
operator|.
name|empty
argument_list|()
argument_list|)
block|;
return|return
name|CurrentSCC
operator|.
name|empty
argument_list|()
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|scc_iterator
operator|&
name|x
operator|)
specifier|const
block|{
return|return
name|VisitStack
operator|==
name|x
operator|.
name|VisitStack
operator|&&
name|CurrentSCC
operator|==
name|x
operator|.
name|CurrentSCC
return|;
block|}
name|scc_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
name|GetNextSCC
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
name|reference
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|CurrentSCC
operator|.
name|empty
argument_list|()
operator|&&
literal|"Dereferencing END SCC iterator!"
argument_list|)
block|;
return|return
name|CurrentSCC
return|;
block|}
comment|/// \brief Test if the current SCC has a loop.
comment|///
comment|/// If the SCC has more than one node, this is trivially true.  If not, it may
comment|/// still contain a loop if the node has an edge back to itself.
name|bool
name|hasLoop
argument_list|()
specifier|const
expr_stmt|;
comment|/// This informs the \c scc_iterator that the specified \c Old node
comment|/// has been deleted, and \c New is to be used in its place.
name|void
name|ReplaceNode
parameter_list|(
name|NodeType
modifier|*
name|Old
parameter_list|,
name|NodeType
modifier|*
name|New
parameter_list|)
block|{
name|assert
argument_list|(
name|nodeVisitNumbers
operator|.
name|count
argument_list|(
name|Old
argument_list|)
operator|&&
literal|"Old not in scc_iterator?"
argument_list|)
expr_stmt|;
name|nodeVisitNumbers
index|[
name|New
index|]
operator|=
name|nodeVisitNumbers
index|[
name|Old
index|]
expr_stmt|;
name|nodeVisitNumbers
operator|.
name|erase
argument_list|(
name|Old
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|GraphT
operator|,
name|class
name|GT
operator|>
name|void
name|scc_iterator
operator|<
name|GraphT
operator|,
name|GT
operator|>
operator|::
name|DFSVisitOne
argument_list|(
argument|NodeType *N
argument_list|)
block|{
operator|++
name|visitNum
block|;
name|nodeVisitNumbers
index|[
name|N
index|]
operator|=
name|visitNum
block|;
name|SCCNodeStack
operator|.
name|push_back
argument_list|(
name|N
argument_list|)
block|;
name|VisitStack
operator|.
name|push_back
argument_list|(
name|StackElement
argument_list|(
name|N
argument_list|,
name|GT
operator|::
name|child_begin
argument_list|(
name|N
argument_list|)
argument_list|,
name|visitNum
argument_list|)
argument_list|)
block|;
if|#
directive|if
literal|0
comment|// Enable if needed when debugging.
block|dbgs()<< "TarjanSCC: Node "<< N<<         " : visitNum = "<< visitNum<< "\n";
endif|#
directive|endif
block|}
name|template
operator|<
name|class
name|GraphT
operator|,
name|class
name|GT
operator|>
name|void
name|scc_iterator
operator|<
name|GraphT
operator|,
name|GT
operator|>
operator|::
name|DFSVisitChildren
argument_list|()
block|{
name|assert
argument_list|(
operator|!
name|VisitStack
operator|.
name|empty
argument_list|()
argument_list|)
block|;
while|while
condition|(
name|VisitStack
operator|.
name|back
argument_list|()
operator|.
name|NextChild
operator|!=
name|GT
operator|::
name|child_end
argument_list|(
name|VisitStack
operator|.
name|back
argument_list|()
operator|.
name|Node
argument_list|)
condition|)
block|{
comment|// TOS has at least one more child so continue DFS
name|NodeType
modifier|*
name|childN
init|=
operator|*
name|VisitStack
operator|.
name|back
argument_list|()
operator|.
name|NextChild
operator|++
decl_stmt|;
name|typename
name|DenseMap
operator|<
name|NodeType
operator|*
operator|,
name|unsigned
operator|>
operator|::
name|iterator
name|Visited
operator|=
name|nodeVisitNumbers
operator|.
name|find
argument_list|(
name|childN
argument_list|)
expr_stmt|;
if|if
condition|(
name|Visited
operator|==
name|nodeVisitNumbers
operator|.
name|end
argument_list|()
condition|)
block|{
comment|// this node has never been seen.
name|DFSVisitOne
argument_list|(
name|childN
argument_list|)
expr_stmt|;
continue|continue;
block|}
name|unsigned
name|childNum
operator|=
name|Visited
operator|->
name|second
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|VisitStack
operator|.
name|back
argument_list|()
operator|.
name|MinVisited
operator|>
name|childNum
condition|)
name|VisitStack
operator|.
name|back
argument_list|()
operator|.
name|MinVisited
operator|=
name|childNum
expr_stmt|;
end_if

begin_expr_stmt
unit|} }
name|template
operator|<
name|class
name|GraphT
operator|,
name|class
name|GT
operator|>
name|void
name|scc_iterator
operator|<
name|GraphT
operator|,
name|GT
operator|>
operator|::
name|GetNextSCC
argument_list|()
block|{
name|CurrentSCC
operator|.
name|clear
argument_list|()
block|;
comment|// Prepare to compute the next SCC
while|while
condition|(
operator|!
name|VisitStack
operator|.
name|empty
argument_list|()
condition|)
block|{
name|DFSVisitChildren
argument_list|()
expr_stmt|;
comment|// Pop the leaf on top of the VisitStack.
name|NodeType
modifier|*
name|visitingN
init|=
name|VisitStack
operator|.
name|back
argument_list|()
operator|.
name|Node
decl_stmt|;
name|unsigned
name|minVisitNum
init|=
name|VisitStack
operator|.
name|back
argument_list|()
operator|.
name|MinVisited
decl_stmt|;
name|assert
argument_list|(
name|VisitStack
operator|.
name|back
argument_list|()
operator|.
name|NextChild
operator|==
name|GT
operator|::
name|child_end
argument_list|(
name|visitingN
argument_list|)
argument_list|)
expr_stmt|;
name|VisitStack
operator|.
name|pop_back
argument_list|()
expr_stmt|;
comment|// Propagate MinVisitNum to parent so we can detect the SCC starting node.
if|if
condition|(
operator|!
name|VisitStack
operator|.
name|empty
argument_list|()
operator|&&
name|VisitStack
operator|.
name|back
argument_list|()
operator|.
name|MinVisited
operator|>
name|minVisitNum
condition|)
name|VisitStack
operator|.
name|back
argument_list|()
operator|.
name|MinVisited
operator|=
name|minVisitNum
expr_stmt|;
if|#
directive|if
literal|0
comment|// Enable if needed when debugging.
block|dbgs()<< "TarjanSCC: Popped node "<< visitingN<<           " : minVisitNum = "<< minVisitNum<< "; Node visit num = "<<           nodeVisitNumbers[visitingN]<< "\n";
endif|#
directive|endif
if|if
condition|(
name|minVisitNum
operator|!=
name|nodeVisitNumbers
index|[
name|visitingN
index|]
condition|)
continue|continue;
comment|// A full SCC is on the SCCNodeStack!  It includes all nodes below
comment|// visitingN on the stack.  Copy those nodes to CurrentSCC,
comment|// reset their minVisit values, and return (this suspends
comment|// the DFS traversal till the next ++).
do|do
block|{
name|CurrentSCC
operator|.
name|push_back
argument_list|(
name|SCCNodeStack
operator|.
name|back
argument_list|()
argument_list|)
expr_stmt|;
name|SCCNodeStack
operator|.
name|pop_back
argument_list|()
expr_stmt|;
name|nodeVisitNumbers
index|[
name|CurrentSCC
operator|.
name|back
argument_list|()
index|]
operator|=
operator|~
literal|0U
expr_stmt|;
block|}
end_expr_stmt

begin_while
while|while
condition|(
name|CurrentSCC
operator|.
name|back
argument_list|()
operator|!=
name|visitingN
condition|)
empty_stmt|;
end_while

begin_return
return|return;
end_return

begin_expr_stmt
unit|} }
name|template
operator|<
name|class
name|GraphT
operator|,
name|class
name|GT
operator|>
name|bool
name|scc_iterator
operator|<
name|GraphT
operator|,
name|GT
operator|>
operator|::
name|hasLoop
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|CurrentSCC
operator|.
name|empty
argument_list|()
operator|&&
literal|"Dereferencing END SCC iterator!"
argument_list|)
block|;
if|if
condition|(
name|CurrentSCC
operator|.
name|size
argument_list|()
operator|>
literal|1
condition|)
return|return
name|true
return|;
name|NodeType
operator|*
name|N
operator|=
name|CurrentSCC
operator|.
name|front
argument_list|()
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
name|ChildItTy
name|CI
init|=
name|GT
operator|::
name|child_begin
argument_list|(
name|N
argument_list|)
init|,
name|CE
init|=
name|GT
operator|::
name|child_end
argument_list|(
name|N
argument_list|)
init|;
name|CI
operator|!=
name|CE
condition|;
operator|++
name|CI
control|)
if|if
condition|(
operator|*
name|CI
operator|==
name|N
condition|)
return|return
name|true
return|;
end_for

begin_return
return|return
name|false
return|;
end_return

begin_comment
unit|}
comment|/// \brief Construct the begin iterator for a deduced graph type T.
end_comment

begin_expr_stmt
unit|template
operator|<
name|class
name|T
operator|>
name|scc_iterator
operator|<
name|T
operator|>
name|scc_begin
argument_list|(
argument|const T&G
argument_list|)
block|{
return|return
name|scc_iterator
operator|<
name|T
operator|>
operator|::
name|begin
argument_list|(
name|G
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Construct the end iterator for a deduced graph type T.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|scc_iterator
operator|<
name|T
operator|>
name|scc_end
argument_list|(
argument|const T&G
argument_list|)
block|{
return|return
name|scc_iterator
operator|<
name|T
operator|>
operator|::
name|end
argument_list|(
name|G
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Construct the begin iterator for a deduced graph type T's Inverse<T>.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|scc_iterator
operator|<
name|Inverse
operator|<
name|T
operator|>
expr|>
name|scc_begin
argument_list|(
argument|const Inverse<T>&G
argument_list|)
block|{
return|return
name|scc_iterator
operator|<
name|Inverse
operator|<
name|T
operator|>
expr|>
operator|::
name|begin
argument_list|(
name|G
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Construct the end iterator for a deduced graph type T's Inverse<T>.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|scc_iterator
operator|<
name|Inverse
operator|<
name|T
operator|>
expr|>
name|scc_end
argument_list|(
argument|const Inverse<T>&G
argument_list|)
block|{
return|return
name|scc_iterator
operator|<
name|Inverse
operator|<
name|T
operator|>
expr|>
operator|::
name|end
argument_list|(
name|G
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

