begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/ADT/simple_ilist.h - Simple Intrusive List ----------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_ADT_SIMPLE_ILIST_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_SIMPLE_ILIST_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ilist_base.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ilist_iterator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ilist_node.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ilist_node_options.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
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
file|<functional>
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
comment|/// A simple intrusive list implementation.
comment|///
comment|/// This is a simple intrusive list for a \c T that inherits from \c
comment|/// ilist_node<T>.  The list never takes ownership of anything inserted in it.
comment|///
comment|/// Unlike \a iplist<T> and \a ilist<T>, \a simple_ilist<T> never allocates or
comment|/// deletes values, and has no callback traits.
comment|///
comment|/// The API for adding nodes include \a push_front(), \a push_back(), and \a
comment|/// insert().  These all take values by reference (not by pointer), except for
comment|/// the range version of \a insert().
comment|///
comment|/// There are three sets of API for discarding nodes from the list: \a
comment|/// remove(), which takes a reference to the node to remove, \a erase(), which
comment|/// takes an iterator or iterator range and returns the next one, and \a
comment|/// clear(), which empties out the container.  All three are constant time
comment|/// operations.  None of these deletes any nodes; in particular, if there is a
comment|/// single node in the list, then these have identical semantics:
comment|/// \li \c L.remove(L.front());
comment|/// \li \c L.erase(L.begin());
comment|/// \li \c L.clear();
comment|///
comment|/// As a convenience for callers, there are parallel APIs that take a \c
comment|/// Disposer (such as \c std::default_delete<T>): \a removeAndDispose(), \a
comment|/// eraseAndDispose(), and \a clearAndDispose().  These have different names
comment|/// because the extra semantic is otherwise non-obvious.  They are equivalent
comment|/// to calling \a std::for_each() on the range to be discarded.
comment|///
comment|/// The currently available \p Options customize the nodes in the list.  The
comment|/// same options must be specified in the \a ilist_node instantation for
comment|/// compatibility (although the order is irrelevant).
comment|/// \li Use \a ilist_tag to designate which ilist_node for a given \p T this
comment|/// list should use.  This is useful if a type \p T is part of multiple,
comment|/// independent lists simultaneously.
comment|/// \li Use \a ilist_sentinel_tracking to always (or never) track whether a
comment|/// node is a sentinel.  Specifying \c true enables the \a
comment|/// ilist_node::isSentinel() API.  Unlike \a ilist_node::isKnownSentinel(),
comment|/// which is only appropriate for assertions, \a ilist_node::isSentinel() is
comment|/// appropriate for real logic.
comment|///
comment|/// Here are examples of \p Options usage:
comment|/// \li \c simple_ilist<T> gives the defaults.  \li \c
comment|/// simple_ilist<T,ilist_sentinel_tracking<true>> enables the \a
comment|/// ilist_node::isSentinel() API.
comment|/// \li \c simple_ilist<T,ilist_tag<A>,ilist_sentinel_tracking<false>>
comment|/// specifies a tag of A and that tracking should be off (even when
comment|/// LLVM_ENABLE_ABI_BREAKING_CHECKS are enabled).
comment|/// \li \c simple_ilist<T,ilist_sentinel_tracking<false>,ilist_tag<A>> is
comment|/// equivalent to the last.
comment|///
comment|/// See \a is_valid_option for steps on adding a new option.
name|template
operator|<
name|typename
name|T
operator|,
name|class
operator|...
name|Options
operator|>
name|class
name|simple_ilist
operator|:
name|ilist_detail
operator|::
name|compute_node_options
operator|<
name|T
operator|,
name|Options
operator|...
operator|>
operator|::
name|type
operator|::
name|list_base_type
operator|,
name|ilist_detail
operator|::
name|SpecificNodeAccess
operator|<
name|typename
name|ilist_detail
operator|::
name|compute_node_options
operator|<
name|T
operator|,
name|Options
operator|...
operator|>
operator|::
name|type
operator|>
block|{
name|static_assert
argument_list|(
name|ilist_detail
operator|::
name|check_options
operator|<
name|Options
operator|...
operator|>
operator|::
name|value
argument_list|,
literal|"Unrecognized node option!"
argument_list|)
block|;
name|using
name|OptionsT
operator|=
name|typename
name|ilist_detail
operator|::
name|compute_node_options
operator|<
name|T
block|,
name|Options
operator|...
operator|>
operator|::
name|type
block|;
name|using
name|list_base_type
operator|=
name|typename
name|OptionsT
operator|::
name|list_base_type
block|;
name|ilist_sentinel
operator|<
name|OptionsT
operator|>
name|Sentinel
block|;
name|public
operator|:
name|using
name|value_type
operator|=
name|typename
name|OptionsT
operator|::
name|value_type
block|;
name|using
name|pointer
operator|=
name|typename
name|OptionsT
operator|::
name|pointer
block|;
name|using
name|reference
operator|=
name|typename
name|OptionsT
operator|::
name|reference
block|;
name|using
name|const_pointer
operator|=
name|typename
name|OptionsT
operator|::
name|const_pointer
block|;
name|using
name|const_reference
operator|=
name|typename
name|OptionsT
operator|::
name|const_reference
block|;
name|using
name|iterator
operator|=
name|ilist_iterator
operator|<
name|OptionsT
block|,
name|false
block|,
name|false
operator|>
block|;
name|using
name|const_iterator
operator|=
name|ilist_iterator
operator|<
name|OptionsT
block|,
name|false
block|,
name|true
operator|>
block|;
name|using
name|reverse_iterator
operator|=
name|ilist_iterator
operator|<
name|OptionsT
block|,
name|true
block|,
name|false
operator|>
block|;
name|using
name|const_reverse_iterator
operator|=
name|ilist_iterator
operator|<
name|OptionsT
block|,
name|true
block|,
name|true
operator|>
block|;
name|using
name|size_type
operator|=
name|size_t
block|;
name|using
name|difference_type
operator|=
name|ptrdiff_t
block|;
name|simple_ilist
argument_list|()
operator|=
expr|default
block|;
operator|~
name|simple_ilist
argument_list|()
operator|=
expr|default
block|;
comment|// No copy constructors.
name|simple_ilist
argument_list|(
specifier|const
name|simple_ilist
operator|&
argument_list|)
operator|=
name|delete
block|;
name|simple_ilist
operator|&
name|operator
operator|=
operator|(
specifier|const
name|simple_ilist
operator|&
operator|)
operator|=
name|delete
block|;
comment|// Move constructors.
name|simple_ilist
argument_list|(
argument|simple_ilist&&X
argument_list|)
block|{
name|splice
argument_list|(
name|end
argument_list|()
argument_list|,
name|X
argument_list|)
block|; }
name|simple_ilist
operator|&
name|operator
operator|=
operator|(
name|simple_ilist
operator|&&
name|X
operator|)
block|{
name|clear
argument_list|()
block|;
name|splice
argument_list|(
name|end
argument_list|()
argument_list|,
name|X
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|iterator
name|begin
argument_list|()
block|{
return|return
operator|++
name|iterator
argument_list|(
name|Sentinel
argument_list|)
return|;
block|}
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
operator|++
name|const_iterator
argument_list|(
name|Sentinel
argument_list|)
return|;
block|}
name|iterator
name|end
argument_list|()
block|{
return|return
name|iterator
argument_list|(
name|Sentinel
argument_list|)
return|;
block|}
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|const_iterator
argument_list|(
name|Sentinel
argument_list|)
return|;
block|}
name|reverse_iterator
name|rbegin
argument_list|()
block|{
return|return
operator|++
name|reverse_iterator
argument_list|(
name|Sentinel
argument_list|)
return|;
block|}
name|const_reverse_iterator
name|rbegin
argument_list|()
specifier|const
block|{
return|return
operator|++
name|const_reverse_iterator
argument_list|(
name|Sentinel
argument_list|)
return|;
block|}
name|reverse_iterator
name|rend
argument_list|()
block|{
return|return
name|reverse_iterator
argument_list|(
name|Sentinel
argument_list|)
return|;
block|}
name|const_reverse_iterator
name|rend
argument_list|()
specifier|const
block|{
return|return
name|const_reverse_iterator
argument_list|(
name|Sentinel
argument_list|)
return|;
block|}
comment|/// Check if the list is empty in constant time.
name|LLVM_NODISCARD
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|Sentinel
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// Calculate the size of the list in linear time.
name|LLVM_NODISCARD
name|size_type
name|size
argument_list|()
specifier|const
block|{
return|return
name|std
operator|::
name|distance
argument_list|(
name|begin
argument_list|()
argument_list|,
name|end
argument_list|()
argument_list|)
return|;
block|}
name|reference
name|front
argument_list|()
block|{
return|return
operator|*
name|begin
argument_list|()
return|;
block|}
name|const_reference
name|front
argument_list|()
specifier|const
block|{
return|return
operator|*
name|begin
argument_list|()
return|;
block|}
name|reference
name|back
argument_list|()
block|{
return|return
operator|*
name|rbegin
argument_list|()
return|;
block|}
name|const_reference
name|back
argument_list|()
specifier|const
block|{
return|return
operator|*
name|rbegin
argument_list|()
return|;
block|}
comment|/// Insert a node at the front; never copies.
name|void
name|push_front
argument_list|(
argument|reference Node
argument_list|)
block|{
name|insert
argument_list|(
name|begin
argument_list|()
argument_list|,
name|Node
argument_list|)
block|; }
comment|/// Insert a node at the back; never copies.
name|void
name|push_back
argument_list|(
argument|reference Node
argument_list|)
block|{
name|insert
argument_list|(
name|end
argument_list|()
argument_list|,
name|Node
argument_list|)
block|; }
comment|/// Remove the node at the front; never deletes.
name|void
name|pop_front
argument_list|()
block|{
name|erase
argument_list|(
name|begin
argument_list|()
argument_list|)
block|; }
comment|/// Remove the node at the back; never deletes.
name|void
name|pop_back
argument_list|()
block|{
name|erase
argument_list|(
operator|--
name|end
argument_list|()
argument_list|)
block|; }
comment|/// Swap with another list in place using std::swap.
name|void
name|swap
argument_list|(
argument|simple_ilist&X
argument_list|)
block|{
name|std
operator|::
name|swap
argument_list|(
operator|*
name|this
argument_list|,
name|X
argument_list|)
block|; }
comment|/// Insert a node by reference; never copies.
name|iterator
name|insert
argument_list|(
argument|iterator I
argument_list|,
argument|reference Node
argument_list|)
block|{
name|list_base_type
operator|::
name|insertBefore
argument_list|(
operator|*
name|I
operator|.
name|getNodePtr
argument_list|()
argument_list|,
operator|*
name|this
operator|->
name|getNodePtr
argument_list|(
operator|&
name|Node
argument_list|)
argument_list|)
block|;
return|return
name|iterator
argument_list|(
operator|&
name|Node
argument_list|)
return|;
block|}
comment|/// Insert a range of nodes; never copies.
name|template
operator|<
name|class
name|Iterator
operator|>
name|void
name|insert
argument_list|(
argument|iterator I
argument_list|,
argument|Iterator First
argument_list|,
argument|Iterator Last
argument_list|)
block|{
for|for
control|(
init|;
name|First
operator|!=
name|Last
condition|;
operator|++
name|First
control|)
name|insert
argument_list|(
name|I
argument_list|,
operator|*
name|First
argument_list|)
expr_stmt|;
block|}
comment|/// Clone another list.
name|template
operator|<
name|class
name|Cloner
block|,
name|class
name|Disposer
operator|>
name|void
name|cloneFrom
argument_list|(
argument|const simple_ilist&L2
argument_list|,
argument|Cloner clone
argument_list|,
argument|Disposer dispose
argument_list|)
block|{
name|clearAndDispose
argument_list|(
name|dispose
argument_list|)
block|;
for|for
control|(
name|const_reference
name|V
range|:
name|L2
control|)
name|push_back
argument_list|(
operator|*
name|clone
argument_list|(
name|V
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// Remove a node by reference; never deletes.
comment|///
comment|/// \see \a erase() for removing by iterator.
comment|/// \see \a removeAndDispose() if the node should be deleted.
name|void
name|remove
argument_list|(
argument|reference N
argument_list|)
block|{
name|list_base_type
operator|::
name|remove
argument_list|(
operator|*
name|this
operator|->
name|getNodePtr
argument_list|(
operator|&
name|N
argument_list|)
argument_list|)
block|; }
comment|/// Remove a node by reference and dispose of it.
name|template
operator|<
name|class
name|Disposer
operator|>
name|void
name|removeAndDispose
argument_list|(
argument|reference N
argument_list|,
argument|Disposer dispose
argument_list|)
block|{
name|remove
argument_list|(
name|N
argument_list|)
block|;
name|dispose
argument_list|(
operator|&
name|N
argument_list|)
block|;   }
comment|/// Remove a node by iterator; never deletes.
comment|///
comment|/// \see \a remove() for removing by reference.
comment|/// \see \a eraseAndDispose() it the node should be deleted.
name|iterator
name|erase
argument_list|(
argument|iterator I
argument_list|)
block|{
name|assert
argument_list|(
name|I
operator|!=
name|end
argument_list|()
operator|&&
literal|"Cannot remove end of list!"
argument_list|)
block|;
name|remove
argument_list|(
operator|*
name|I
operator|++
argument_list|)
block|;
return|return
name|I
return|;
block|}
comment|/// Remove a range of nodes; never deletes.
comment|///
comment|/// \see \a eraseAndDispose() if the nodes should be deleted.
name|iterator
name|erase
argument_list|(
argument|iterator First
argument_list|,
argument|iterator Last
argument_list|)
block|{
name|list_base_type
operator|::
name|removeRange
argument_list|(
operator|*
name|First
operator|.
name|getNodePtr
argument_list|()
argument_list|,
operator|*
name|Last
operator|.
name|getNodePtr
argument_list|()
argument_list|)
block|;
return|return
name|Last
return|;
block|}
comment|/// Remove a node by iterator and dispose of it.
name|template
operator|<
name|class
name|Disposer
operator|>
name|iterator
name|eraseAndDispose
argument_list|(
argument|iterator I
argument_list|,
argument|Disposer dispose
argument_list|)
block|{
name|auto
name|Next
operator|=
name|std
operator|::
name|next
argument_list|(
name|I
argument_list|)
block|;
name|erase
argument_list|(
name|I
argument_list|)
block|;
name|dispose
argument_list|(
operator|&
operator|*
name|I
argument_list|)
block|;
return|return
name|Next
return|;
block|}
comment|/// Remove a range of nodes and dispose of them.
name|template
operator|<
name|class
name|Disposer
operator|>
name|iterator
name|eraseAndDispose
argument_list|(
argument|iterator First
argument_list|,
argument|iterator Last
argument_list|,
argument|Disposer dispose
argument_list|)
block|{
while|while
condition|(
name|First
operator|!=
name|Last
condition|)
name|First
operator|=
name|eraseAndDispose
argument_list|(
name|First
argument_list|,
name|dispose
argument_list|)
expr_stmt|;
return|return
name|Last
return|;
block|}
comment|/// Clear the list; never deletes.
comment|///
comment|/// \see \a clearAndDispose() if the nodes should be deleted.
name|void
name|clear
parameter_list|()
block|{
name|Sentinel
operator|.
name|reset
argument_list|()
expr_stmt|;
block|}
comment|/// Clear the list and dispose of the nodes.
name|template
operator|<
name|class
name|Disposer
operator|>
name|void
name|clearAndDispose
argument_list|(
argument|Disposer dispose
argument_list|)
block|{
name|eraseAndDispose
argument_list|(
name|begin
argument_list|()
argument_list|,
name|end
argument_list|()
argument_list|,
name|dispose
argument_list|)
block|;   }
comment|/// Splice in another list.
name|void
name|splice
argument_list|(
argument|iterator I
argument_list|,
argument|simple_ilist&L2
argument_list|)
block|{
name|splice
argument_list|(
name|I
argument_list|,
name|L2
argument_list|,
name|L2
operator|.
name|begin
argument_list|()
argument_list|,
name|L2
operator|.
name|end
argument_list|()
argument_list|)
block|;   }
comment|/// Splice in a node from another list.
name|void
name|splice
argument_list|(
argument|iterator I
argument_list|,
argument|simple_ilist&L2
argument_list|,
argument|iterator Node
argument_list|)
block|{
name|splice
argument_list|(
name|I
argument_list|,
name|L2
argument_list|,
name|Node
argument_list|,
name|std
operator|::
name|next
argument_list|(
name|Node
argument_list|)
argument_list|)
block|;   }
comment|/// Splice in a range of nodes from another list.
name|void
name|splice
argument_list|(
argument|iterator I
argument_list|,
argument|simple_ilist&
argument_list|,
argument|iterator First
argument_list|,
argument|iterator Last
argument_list|)
block|{
name|list_base_type
operator|::
name|transferBefore
argument_list|(
operator|*
name|I
operator|.
name|getNodePtr
argument_list|()
argument_list|,
operator|*
name|First
operator|.
name|getNodePtr
argument_list|()
argument_list|,
operator|*
name|Last
operator|.
name|getNodePtr
argument_list|()
argument_list|)
block|;   }
comment|/// Merge in another list.
comment|///
comment|/// \pre \c this and \p RHS are sorted.
comment|///@{
name|void
name|merge
argument_list|(
argument|simple_ilist&RHS
argument_list|)
block|{
name|merge
argument_list|(
name|RHS
argument_list|,
name|std
operator|::
name|less
operator|<
name|T
operator|>
operator|(
operator|)
argument_list|)
block|; }
name|template
operator|<
name|class
name|Compare
operator|>
name|void
name|merge
argument_list|(
argument|simple_ilist&RHS
argument_list|,
argument|Compare comp
argument_list|)
expr_stmt|;
comment|///@}
comment|/// Sort the list.
comment|///@{
name|void
name|sort
parameter_list|()
block|{
name|sort
argument_list|(
name|std
operator|::
name|less
operator|<
name|T
operator|>
operator|(
operator|)
argument_list|)
expr_stmt|;
block|}
name|template
operator|<
name|class
name|Compare
operator|>
name|void
name|sort
argument_list|(
argument|Compare comp
argument_list|)
expr_stmt|;
comment|///@}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|,
name|class
operator|...
name|Options
operator|>
name|template
operator|<
name|class
name|Compare
operator|>
name|void
name|simple_ilist
operator|<
name|T
operator|,
name|Options
operator|...
operator|>
operator|::
name|merge
argument_list|(
argument|simple_ilist&RHS
argument_list|,
argument|Compare comp
argument_list|)
block|{
if|if
condition|(
name|this
operator|==
operator|&
name|RHS
operator|||
name|RHS
operator|.
name|empty
argument_list|()
condition|)
return|return;
name|iterator
name|LI
operator|=
name|begin
argument_list|()
operator|,
name|LE
operator|=
name|end
argument_list|()
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|iterator
name|RI
init|=
name|RHS
operator|.
name|begin
argument_list|()
decl_stmt|,
name|RE
init|=
name|RHS
operator|.
name|end
argument_list|()
decl_stmt|;
end_decl_stmt

begin_while
while|while
condition|(
name|LI
operator|!=
name|LE
condition|)
block|{
if|if
condition|(
name|comp
argument_list|(
operator|*
name|RI
argument_list|,
operator|*
name|LI
argument_list|)
condition|)
block|{
comment|// Transfer a run of at least size 1 from RHS to LHS.
name|iterator
name|RunStart
init|=
name|RI
operator|++
decl_stmt|;
name|RI
operator|=
name|std
operator|::
name|find_if
argument_list|(
name|RI
argument_list|,
name|RE
argument_list|,
index|[
operator|&
index|]
operator|(
name|reference
name|RV
operator|)
block|{
return|return
operator|!
name|comp
argument_list|(
name|RV
argument_list|,
operator|*
name|LI
argument_list|)
return|;
block|}
block|)
empty_stmt|;
name|splice
argument_list|(
name|LI
argument_list|,
name|RHS
argument_list|,
name|RunStart
argument_list|,
name|RI
argument_list|)
expr_stmt|;
if|if
condition|(
name|RI
operator|==
name|RE
condition|)
return|return;
block|}
end_while

begin_expr_stmt
operator|++
name|LI
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// Transfer the remaining RHS nodes once LHS is finished.
end_comment

begin_expr_stmt
unit|splice
operator|(
name|LE
operator|,
name|RHS
operator|,
name|RI
operator|,
name|RE
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}  template
operator|<
name|class
name|T
operator|,
name|class
operator|...
name|Options
operator|>
name|template
operator|<
name|class
name|Compare
operator|>
name|void
name|simple_ilist
operator|<
name|T
operator|,
name|Options
operator|...
operator|>
operator|::
name|sort
argument_list|(
argument|Compare comp
argument_list|)
block|{
comment|// Vacuously sorted.
if|if
condition|(
name|empty
argument_list|()
operator|||
name|std
operator|::
name|next
argument_list|(
name|begin
argument_list|()
argument_list|)
operator|==
name|end
argument_list|()
condition|)
return|return;
comment|// Split the list in the middle.
name|iterator
name|Center
operator|=
name|begin
argument_list|()
operator|,
name|End
operator|=
name|begin
argument_list|()
expr_stmt|;
end_expr_stmt

begin_while
while|while
condition|(
name|End
operator|!=
name|end
argument_list|()
operator|&&
operator|++
name|End
operator|!=
name|end
argument_list|()
condition|)
block|{
operator|++
name|Center
expr_stmt|;
operator|++
name|End
expr_stmt|;
block|}
end_while

begin_decl_stmt
name|simple_ilist
name|RHS
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|RHS
operator|.
name|splice
argument_list|(
name|RHS
operator|.
name|end
argument_list|()
argument_list|,
operator|*
name|this
argument_list|,
name|Center
argument_list|,
name|end
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Sort the sublists and merge back together.
end_comment

begin_expr_stmt
name|sort
argument_list|(
name|comp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RHS
operator|.
name|sort
argument_list|(
name|comp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|merge
argument_list|(
name|RHS
argument_list|,
name|comp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}  }
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_ADT_SIMPLE_ILIST_H
end_comment

end_unit

