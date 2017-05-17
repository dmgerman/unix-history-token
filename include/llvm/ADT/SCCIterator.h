begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ADT/SCCIterator.h - Strongly Connected Comp. Iter. -------*- C++ -*-===//
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
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<iterator>
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
name|NodeRef
operator|>
operator|,
name|ptrdiff_t
operator|>
block|{
name|using
name|NodeRef
operator|=
name|typename
name|GT
operator|::
name|NodeRef
block|;
name|using
name|ChildItTy
operator|=
name|typename
name|GT
operator|::
name|ChildIteratorType
block|;
name|using
name|SccTy
operator|=
name|std
operator|::
name|vector
operator|<
name|NodeRef
operator|>
block|;
name|using
name|reference
operator|=
name|typename
name|scc_iterator
operator|::
name|reference
block|;
comment|/// Element of VisitStack during DFS.
block|struct
name|StackElement
block|{
name|NodeRef
name|Node
block|;
comment|///< The current node pointer.
name|ChildItTy
name|NextChild
block|;
comment|///< The next child, modified inplace during DFS.
name|unsigned
name|MinVisited
block|;
comment|///< Minimum uplink value of all children of Node.
name|StackElement
argument_list|(
argument|NodeRef Node
argument_list|,
argument|const ChildItTy&Child
argument_list|,
argument|unsigned Min
argument_list|)
operator|:
name|Node
argument_list|(
name|Node
argument_list|)
block|,
name|NextChild
argument_list|(
name|Child
argument_list|)
block|,
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
expr|}
block|;
comment|/// The visit counters used to detect when a complete SCC is on the stack.
comment|/// visitNum is the global counter.
comment|///
comment|/// nodeVisitNumbers are per-node visit numbers, also used as DFS flags.
name|unsigned
name|visitNum
block|;
name|DenseMap
operator|<
name|NodeRef
block|,
name|unsigned
operator|>
name|nodeVisitNumbers
block|;
comment|/// Stack holding nodes of the SCC.
name|std
operator|::
name|vector
operator|<
name|NodeRef
operator|>
name|SCCNodeStack
block|;
comment|/// The current SCC, retrieved using operator*().
name|SccTy
name|CurrentSCC
block|;
comment|/// DFS stack, Used to maintain the ordering.  The top contains the current
comment|/// node, the next child to visit, and the minimum uplink value of all child
name|std
operator|::
name|vector
operator|<
name|StackElement
operator|>
name|VisitStack
block|;
comment|/// A single "visit" within the non-recursive DFS traversal.
name|void
name|DFSVisitOne
argument_list|(
argument|NodeRef N
argument_list|)
block|;
comment|/// The stack-based DFS traversal; defined below.
name|void
name|DFSVisitChildren
argument_list|()
block|;
comment|/// Compute the next SCC using the DFS traversal.
name|void
name|GetNextSCC
argument_list|()
block|;
name|scc_iterator
argument_list|(
argument|NodeRef entryN
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
operator|=
expr|default
block|;
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
argument_list|(
argument|const GraphT&
argument_list|)
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
block|;
comment|/// This informs the \c scc_iterator that the specified \c Old node
comment|/// has been deleted, and \c New is to be used in its place.
name|void
name|ReplaceNode
argument_list|(
argument|NodeRef Old
argument_list|,
argument|NodeRef New
argument_list|)
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
block|;
name|nodeVisitNumbers
index|[
name|New
index|]
operator|=
name|nodeVisitNumbers
index|[
name|Old
index|]
block|;
name|nodeVisitNumbers
operator|.
name|erase
argument_list|(
name|Old
argument_list|)
block|;   }
block|}
block|;
name|template
operator|<
name|class
name|GraphT
block|,
name|class
name|GT
operator|>
name|void
name|scc_iterator
operator|<
name|GraphT
block|,
name|GT
operator|>
operator|::
name|DFSVisitOne
argument_list|(
argument|NodeRef N
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
block|,
name|class
name|GT
operator|>
name|void
name|scc_iterator
operator|<
name|GraphT
block|,
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
name|NodeRef
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
name|NodeRef
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
init|=
name|Visited
operator|->
name|second
decl_stmt|;
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
block|}
block|}
name|template
operator|<
name|class
name|GraphT
block|,
name|class
name|GT
operator|>
name|void
name|scc_iterator
operator|<
name|GraphT
block|,
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
name|NodeRef
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
do|return;   } }  template<class GraphT
operator|,
do|class GT> bool scc_iterator<GraphT
operator|,
do|GT>::hasLoop(
block|)
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
name|NodeRef
name|N
operator|=
name|CurrentSCC
operator|.
name|front
argument_list|()
expr_stmt|;
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
return|return
name|false
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Construct the begin iterator for a deduced graph type T.
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
operator|>>
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
operator|>>
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
operator|>>
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
operator|>>
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
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_ADT_SCCITERATOR_H
end_comment

end_unit

