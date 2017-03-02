begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==-- llvm/ADT/ilist.h - Intrusive Linked List Template ---------*- C++ -*-==//
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
comment|// This file defines classes to implement an intrusive doubly linked list class
end_comment

begin_comment
comment|// (i.e. each node of the list must contain a next and previous field for the
end_comment

begin_comment
comment|// list.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The ilist class itself should be a plug in replacement for list.  This list
end_comment

begin_comment
comment|// replacement does not provide a constant time size() method, so be careful to
end_comment

begin_comment
comment|// use empty() when you really want to know if it's empty.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The ilist class is implemented as a circular list.  The list itself contains
end_comment

begin_comment
comment|// a sentinel node, whose Next points at begin() and whose Prev points at
end_comment

begin_comment
comment|// rbegin().  The sentinel node itself serves as end() and rend().
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
name|LLVM_ADT_ILIST_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_ILIST_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/simple_ilist.h"
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

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Use delete by default for iplist and ilist.
comment|///
comment|/// Specialize this to get different behaviour for ownership-related API.  (If
comment|/// you really want ownership semantics, consider using std::list or building
comment|/// something like \a BumpPtrList.)
comment|///
comment|/// \see ilist_noalloc_traits
name|template
operator|<
name|typename
name|NodeTy
operator|>
expr|struct
name|ilist_alloc_traits
block|{
specifier|static
name|void
name|deleteNode
argument_list|(
argument|NodeTy *V
argument_list|)
block|{
name|delete
name|V
block|; }
block|}
expr_stmt|;
comment|/// Custom traits to do nothing on deletion.
comment|///
comment|/// Specialize ilist_alloc_traits to inherit from this to disable the
comment|/// non-intrusive deletion in iplist (which implies ownership).
comment|///
comment|/// If you want purely intrusive semantics with no callbacks, consider using \a
comment|/// simple_ilist instead.
comment|///
comment|/// \code
comment|/// template<>
comment|/// struct ilist_alloc_traits<MyType> : ilist_noalloc_traits<MyType> {};
comment|/// \endcode
name|template
operator|<
name|typename
name|NodeTy
operator|>
expr|struct
name|ilist_noalloc_traits
block|{
specifier|static
name|void
name|deleteNode
argument_list|(
argument|NodeTy *V
argument_list|)
block|{}
block|}
expr_stmt|;
comment|/// Callbacks do nothing by default in iplist and ilist.
comment|///
comment|/// Specialize this for to use callbacks for when nodes change their list
comment|/// membership.
name|template
operator|<
name|typename
name|NodeTy
operator|>
expr|struct
name|ilist_callback_traits
block|{
name|void
name|addNodeToList
argument_list|(
argument|NodeTy *
argument_list|)
block|{}
name|void
name|removeNodeFromList
argument_list|(
argument|NodeTy *
argument_list|)
block|{}
comment|/// Callback before transferring nodes to this list.
comment|///
comment|/// \pre \c this!=&OldList
name|template
operator|<
name|class
name|Iterator
operator|>
name|void
name|transferNodesFromList
argument_list|(
argument|ilist_callback_traits&OldList
argument_list|,
argument|Iterator
comment|/*first*/
argument_list|,
argument|Iterator
comment|/*last*/
argument_list|)
block|{
operator|(
name|void
operator|)
name|OldList
block|;   }
block|}
expr_stmt|;
comment|/// A fragment for template traits for intrusive list that provides default
comment|/// node related operations.
comment|///
comment|/// TODO: Remove this layer of indirection.  It's not necessary.
name|template
operator|<
name|typename
name|NodeTy
operator|>
expr|struct
name|ilist_node_traits
operator|:
name|ilist_alloc_traits
operator|<
name|NodeTy
operator|>
operator|,
name|ilist_callback_traits
operator|<
name|NodeTy
operator|>
block|{}
expr_stmt|;
comment|/// Default template traits for intrusive list.
comment|///
comment|/// By inheriting from this, you can easily use default implementations for all
comment|/// common operations.
comment|///
comment|/// TODO: Remove this customization point.  Specializing ilist_traits is
comment|/// already fully general.
name|template
operator|<
name|typename
name|NodeTy
operator|>
expr|struct
name|ilist_default_traits
operator|:
name|public
name|ilist_node_traits
operator|<
name|NodeTy
operator|>
block|{}
expr_stmt|;
comment|/// Template traits for intrusive list.
comment|///
comment|/// Customize callbacks and allocation semantics.
name|template
operator|<
name|typename
name|NodeTy
operator|>
expr|struct
name|ilist_traits
operator|:
name|public
name|ilist_default_traits
operator|<
name|NodeTy
operator|>
block|{}
expr_stmt|;
comment|/// Const traits should never be instantiated.
name|template
operator|<
name|typename
name|Ty
operator|>
expr|struct
name|ilist_traits
operator|<
specifier|const
name|Ty
operator|>
block|{}
expr_stmt|;
name|namespace
name|ilist_detail
block|{
name|template
operator|<
name|class
name|T
operator|>
name|T
operator|&
name|make
argument_list|()
expr_stmt|;
comment|/// Type trait to check for a traits class that has a getNext member (as a
comment|/// canary for any of the ilist_nextprev_traits API).
name|template
operator|<
name|class
name|TraitsT
operator|,
name|class
name|NodeT
operator|>
expr|struct
name|HasGetNext
block|{
typedef|typedef
name|char
name|Yes
index|[
literal|1
index|]
typedef|;
typedef|typedef
name|char
name|No
index|[
literal|2
index|]
typedef|;
name|template
operator|<
name|size_t
name|N
operator|>
expr|struct
name|SFINAE
block|{}
expr_stmt|;
name|template
operator|<
name|class
name|U
operator|>
specifier|static
name|Yes
operator|&
name|test
argument_list|(
name|U
operator|*
name|I
argument_list|,
name|decltype
argument_list|(
name|I
operator|->
name|getNext
argument_list|(
operator|&
name|make
operator|<
name|NodeT
operator|>
operator|(
operator|)
argument_list|)
argument_list|)
operator|*
operator|=
literal|0
argument_list|)
expr_stmt|;
name|template
operator|<
name|class
operator|>
specifier|static
name|No
operator|&
name|test
argument_list|(
operator|...
argument_list|)
expr_stmt|;
name|public
label|:
specifier|static
specifier|const
name|bool
name|value
init|=
sizeof|sizeof
argument_list|(
name|test
operator|<
name|TraitsT
operator|>
operator|(
name|nullptr
operator|)
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|Yes
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
comment|/// Type trait to check for a traits class that has a createSentinel member (as
comment|/// a canary for any of the ilist_sentinel_traits API).
name|template
operator|<
name|class
name|TraitsT
operator|>
expr|struct
name|HasCreateSentinel
block|{
typedef|typedef
name|char
name|Yes
index|[
literal|1
index|]
typedef|;
typedef|typedef
name|char
name|No
index|[
literal|2
index|]
typedef|;
name|template
operator|<
name|class
name|U
operator|>
specifier|static
name|Yes
operator|&
name|test
argument_list|(
name|U
operator|*
name|I
argument_list|,
name|decltype
argument_list|(
name|I
operator|->
name|createSentinel
argument_list|()
argument_list|)
operator|*
operator|=
literal|0
argument_list|)
expr_stmt|;
name|template
operator|<
name|class
operator|>
specifier|static
name|No
operator|&
name|test
argument_list|(
operator|...
argument_list|)
expr_stmt|;
name|public
label|:
specifier|static
specifier|const
name|bool
name|value
init|=
sizeof|sizeof
argument_list|(
name|test
operator|<
name|TraitsT
operator|>
operator|(
name|nullptr
operator|)
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|Yes
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// Type trait to check for a traits class that has a createNode member.
end_comment

begin_comment
comment|/// Allocation should be managed in a wrapper class, instead of in
end_comment

begin_comment
comment|/// ilist_traits.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|TraitsT
operator|,
name|class
name|NodeT
operator|>
expr|struct
name|HasCreateNode
block|{
typedef|typedef
name|char
name|Yes
index|[
literal|1
index|]
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|char
name|No
index|[
literal|2
index|]
typedef|;
end_typedef

begin_expr_stmt
name|template
operator|<
name|size_t
name|N
operator|>
expr|struct
name|SFINAE
block|{}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|U
operator|>
specifier|static
name|Yes
operator|&
name|test
argument_list|(
name|U
operator|*
name|I
argument_list|,
name|decltype
argument_list|(
name|I
operator|->
name|createNode
argument_list|(
name|make
operator|<
name|NodeT
operator|>
operator|(
operator|)
argument_list|)
argument_list|)
operator|*
operator|=
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
operator|>
specifier|static
name|No
operator|&
name|test
argument_list|(
operator|...
argument_list|)
expr_stmt|;
end_expr_stmt

begin_label
name|public
label|:
end_label

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|value
init|=
sizeof|sizeof
argument_list|(
name|test
operator|<
name|TraitsT
operator|>
operator|(
name|nullptr
operator|)
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|Yes
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|TraitsT
operator|,
name|class
name|NodeT
operator|>
expr|struct
name|HasObsoleteCustomization
block|{
specifier|static
specifier|const
name|bool
name|value
operator|=
name|HasGetNext
operator|<
name|TraitsT
block|,
name|NodeT
operator|>
operator|::
name|value
operator|||
name|HasCreateSentinel
operator|<
name|TraitsT
operator|>
operator|::
name|value
operator|||
name|HasCreateNode
operator|<
name|TraitsT
block|,
name|NodeT
operator|>
operator|::
name|value
block|; }
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// end namespace ilist_detail
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// A wrapper around an intrusive list with callbacks and non-intrusive
end_comment

begin_comment
comment|/// ownership.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This wraps a purely intrusive list (like simple_ilist) with a configurable
end_comment

begin_comment
comment|/// traits class.  The traits can implement callbacks and customize the
end_comment

begin_comment
comment|/// ownership semantics.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is a subset of ilist functionality that can safely be used on nodes of
end_comment

begin_comment
comment|/// polymorphic types, i.e. a heterogeneous list with a common base class that
end_comment

begin_comment
comment|/// holds the next/prev pointers.  The only state of the list itself is an
end_comment

begin_comment
comment|/// ilist_sentinel, which holds pointers to the first and last nodes in the
end_comment

begin_comment
comment|/// list.
end_comment

begin_expr_stmt
unit|template
operator|<
name|class
name|IntrusiveListT
operator|,
name|class
name|TraitsT
operator|>
name|class
name|iplist_impl
operator|:
name|public
name|TraitsT
operator|,
name|IntrusiveListT
block|{
typedef|typedef
name|IntrusiveListT
name|base_list_type
typedef|;
name|protected
operator|:
end_expr_stmt

begin_typedef
typedef|typedef
name|iplist_impl
name|iplist_impl_type
typedef|;
end_typedef

begin_label
name|public
label|:
end_label

begin_typedef
typedef|typedef
name|typename
name|base_list_type
operator|::
name|pointer
name|pointer
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|base_list_type
operator|::
name|const_pointer
name|const_pointer
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|base_list_type
operator|::
name|reference
name|reference
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|base_list_type
operator|::
name|const_reference
name|const_reference
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|base_list_type
operator|::
name|value_type
name|value_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|base_list_type
operator|::
name|size_type
name|size_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|base_list_type
operator|::
name|difference_type
name|difference_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|base_list_type
operator|::
name|iterator
name|iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|base_list_type
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|base_list_type
operator|::
name|reverse_iterator
name|reverse_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|base_list_type
operator|::
name|const_reverse_iterator
name|const_reverse_iterator
expr_stmt|;
end_typedef

begin_label
name|private
label|:
end_label

begin_comment
comment|// TODO: Drop this assertion and the transitive type traits anytime after
end_comment

begin_comment
comment|// v4.0 is branched (i.e,. keep them for one release to help out-of-tree code
end_comment

begin_comment
comment|// update).
end_comment

begin_expr_stmt
name|static_assert
argument_list|(
operator|!
name|ilist_detail
operator|::
name|HasObsoleteCustomization
operator|<
name|TraitsT
argument_list|,
name|value_type
operator|>
operator|::
name|value
argument_list|,
literal|"ilist customization points have changed!"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|bool
name|op_less
parameter_list|(
name|const_reference
name|L
parameter_list|,
name|const_reference
name|R
parameter_list|)
block|{
return|return
name|L
operator|<
name|R
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|op_equal
parameter_list|(
name|const_reference
name|L
parameter_list|,
name|const_reference
name|R
parameter_list|)
block|{
return|return
name|L
operator|==
name|R
return|;
block|}
end_function

begin_label
name|public
label|:
end_label

begin_expr_stmt
name|iplist_impl
argument_list|()
operator|=
expr|default
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|iplist_impl
argument_list|(
specifier|const
name|iplist_impl
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|iplist_impl
modifier|&
name|operator
init|=
operator|(
specifier|const
name|iplist_impl
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|iplist_impl
argument_list|(
name|iplist_impl
operator|&&
name|X
argument_list|)
operator|:
name|TraitsT
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|X
argument_list|)
argument_list|)
operator|,
name|IntrusiveListT
argument_list|(
argument|std::move(X)
argument_list|)
block|{}
name|iplist_impl
operator|&
name|operator
operator|=
operator|(
name|iplist_impl
operator|&&
name|X
operator|)
block|{
operator|*
name|static_cast
operator|<
name|TraitsT
operator|*
operator|>
operator|(
name|this
operator|)
operator|=
name|std
operator|::
name|move
argument_list|(
name|X
argument_list|)
block|;
operator|*
name|static_cast
operator|<
name|IntrusiveListT
operator|*
operator|>
operator|(
name|this
operator|)
operator|=
name|std
operator|::
name|move
argument_list|(
name|X
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
operator|~
name|iplist_impl
argument_list|()
block|{
name|clear
argument_list|()
block|; }
comment|// Miscellaneous inspection routines.
name|size_type
name|max_size
argument_list|()
specifier|const
block|{
return|return
name|size_type
argument_list|(
operator|-
literal|1
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|using
name|base_list_type
operator|::
name|begin
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|base_list_type
operator|::
name|end
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|base_list_type
operator|::
name|rbegin
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|base_list_type
operator|::
name|rend
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|base_list_type
operator|::
name|empty
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|base_list_type
operator|::
name|front
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|base_list_type
operator|::
name|back
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|swap
parameter_list|(
name|iplist_impl
modifier|&
name|RHS
parameter_list|)
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"Swap does not use list traits callback correctly yet!"
argument_list|)
expr_stmt|;
name|base_list_type
operator|::
name|swap
argument_list|(
name|RHS
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|iterator
name|insert
parameter_list|(
name|iterator
name|where
parameter_list|,
name|pointer
name|New
parameter_list|)
block|{
name|this
operator|->
name|addNodeToList
argument_list|(
name|New
argument_list|)
expr_stmt|;
comment|// Notify traits that we added a node...
return|return
name|base_list_type
operator|::
name|insert
argument_list|(
name|where
argument_list|,
operator|*
name|New
argument_list|)
return|;
block|}
end_function

begin_function
name|iterator
name|insert
parameter_list|(
name|iterator
name|where
parameter_list|,
name|const_reference
name|New
parameter_list|)
block|{
return|return
name|this
operator|->
name|insert
argument_list|(
argument|where
argument_list|,
argument|new value_type(New)
argument_list|)
return|;
block|}
end_function

begin_function
name|iterator
name|insertAfter
parameter_list|(
name|iterator
name|where
parameter_list|,
name|pointer
name|New
parameter_list|)
block|{
if|if
condition|(
name|empty
argument_list|()
condition|)
return|return
name|insert
argument_list|(
name|begin
argument_list|()
argument_list|,
name|New
argument_list|)
return|;
else|else
return|return
name|insert
argument_list|(
operator|++
name|where
argument_list|,
name|New
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// Clone another list.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|Cloner
operator|>
name|void
name|cloneFrom
argument_list|(
argument|const iplist_impl&L2
argument_list|,
argument|Cloner clone
argument_list|)
block|{
name|clear
argument_list|()
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
name|clone
argument_list|(
name|V
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_function
name|pointer
name|remove
parameter_list|(
name|iterator
modifier|&
name|IT
parameter_list|)
block|{
name|pointer
name|Node
init|=
operator|&
operator|*
name|IT
operator|++
decl_stmt|;
name|this
operator|->
name|removeNodeFromList
argument_list|(
name|Node
argument_list|)
expr_stmt|;
comment|// Notify traits that we removed a node...
name|base_list_type
operator|::
name|remove
argument_list|(
operator|*
name|Node
argument_list|)
expr_stmt|;
return|return
name|Node
return|;
block|}
end_function

begin_function
name|pointer
name|remove
parameter_list|(
specifier|const
name|iterator
modifier|&
name|IT
parameter_list|)
block|{
name|iterator
name|MutIt
init|=
name|IT
decl_stmt|;
return|return
name|remove
argument_list|(
name|MutIt
argument_list|)
return|;
block|}
end_function

begin_function
name|pointer
name|remove
parameter_list|(
name|pointer
name|IT
parameter_list|)
block|{
return|return
name|remove
argument_list|(
name|iterator
argument_list|(
name|IT
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
name|pointer
name|remove
parameter_list|(
name|reference
name|IT
parameter_list|)
block|{
return|return
name|remove
argument_list|(
name|iterator
argument_list|(
name|IT
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// erase - remove a node from the controlled sequence... and delete it.
end_comment

begin_function
name|iterator
name|erase
parameter_list|(
name|iterator
name|where
parameter_list|)
block|{
name|this
operator|->
name|deleteNode
argument_list|(
name|remove
argument_list|(
name|where
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|where
return|;
block|}
end_function

begin_function
name|iterator
name|erase
parameter_list|(
name|pointer
name|IT
parameter_list|)
block|{
return|return
name|erase
argument_list|(
name|iterator
argument_list|(
name|IT
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
name|iterator
name|erase
parameter_list|(
name|reference
name|IT
parameter_list|)
block|{
return|return
name|erase
argument_list|(
name|iterator
argument_list|(
name|IT
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// Remove all nodes from the list like clear(), but do not call
end_comment

begin_comment
comment|/// removeNodeFromList() or deleteNode().
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This should only be used immediately before freeing nodes in bulk to
end_comment

begin_comment
comment|/// avoid traversing the list and bringing all the nodes into cache.
end_comment

begin_function
name|void
name|clearAndLeakNodesUnsafely
parameter_list|()
block|{
name|base_list_type
operator|::
name|clear
argument_list|()
expr_stmt|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_comment
comment|// transfer - The heart of the splice function.  Move linked list nodes from
end_comment

begin_comment
comment|// [first, last) into position.
end_comment

begin_comment
comment|//
end_comment

begin_function
name|void
name|transfer
parameter_list|(
name|iterator
name|position
parameter_list|,
name|iplist_impl
modifier|&
name|L2
parameter_list|,
name|iterator
name|first
parameter_list|,
name|iterator
name|last
parameter_list|)
block|{
if|if
condition|(
name|position
operator|==
name|last
condition|)
return|return;
if|if
condition|(
name|this
operator|!=
operator|&
name|L2
condition|)
comment|// Notify traits we moved the nodes...
name|this
operator|->
name|transferNodesFromList
argument_list|(
name|L2
argument_list|,
name|first
argument_list|,
name|last
argument_list|)
expr_stmt|;
name|base_list_type
operator|::
name|splice
argument_list|(
name|position
argument_list|,
name|L2
argument_list|,
name|first
argument_list|,
name|last
argument_list|)
expr_stmt|;
block|}
end_function

begin_label
name|public
label|:
end_label

begin_comment
comment|//===----------------------------------------------------------------------===
end_comment

begin_comment
comment|// Functionality derived from other functions defined above...
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|using
name|base_list_type
operator|::
name|size
expr_stmt|;
end_expr_stmt

begin_function
name|iterator
name|erase
parameter_list|(
name|iterator
name|first
parameter_list|,
name|iterator
name|last
parameter_list|)
block|{
while|while
condition|(
name|first
operator|!=
name|last
condition|)
name|first
operator|=
name|erase
argument_list|(
name|first
argument_list|)
expr_stmt|;
return|return
name|last
return|;
block|}
end_function

begin_function
name|void
name|clear
parameter_list|()
block|{
name|erase
argument_list|(
name|begin
argument_list|()
argument_list|,
name|end
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Front and back inserters...
end_comment

begin_function
name|void
name|push_front
parameter_list|(
name|pointer
name|val
parameter_list|)
block|{
name|insert
argument_list|(
name|begin
argument_list|()
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|push_back
parameter_list|(
name|pointer
name|val
parameter_list|)
block|{
name|insert
argument_list|(
name|end
argument_list|()
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|pop_front
parameter_list|()
block|{
name|assert
argument_list|(
operator|!
name|empty
argument_list|()
operator|&&
literal|"pop_front() on empty list!"
argument_list|)
expr_stmt|;
name|erase
argument_list|(
name|begin
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|pop_back
parameter_list|()
block|{
name|assert
argument_list|(
operator|!
name|empty
argument_list|()
operator|&&
literal|"pop_back() on empty list!"
argument_list|)
expr_stmt|;
name|iterator
name|t
init|=
name|end
argument_list|()
decl_stmt|;
name|erase
argument_list|(
operator|--
name|t
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Special forms of insert...
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|InIt
operator|>
name|void
name|insert
argument_list|(
argument|iterator where
argument_list|,
argument|InIt first
argument_list|,
argument|InIt last
argument_list|)
block|{
for|for
control|(
init|;
name|first
operator|!=
name|last
condition|;
operator|++
name|first
control|)
name|insert
argument_list|(
name|where
argument_list|,
operator|*
name|first
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_comment
comment|// Splice members - defined in terms of transfer...
end_comment

begin_function
name|void
name|splice
parameter_list|(
name|iterator
name|where
parameter_list|,
name|iplist_impl
modifier|&
name|L2
parameter_list|)
block|{
if|if
condition|(
operator|!
name|L2
operator|.
name|empty
argument_list|()
condition|)
name|transfer
argument_list|(
name|where
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
expr_stmt|;
block|}
end_function

begin_function
name|void
name|splice
parameter_list|(
name|iterator
name|where
parameter_list|,
name|iplist_impl
modifier|&
name|L2
parameter_list|,
name|iterator
name|first
parameter_list|)
block|{
name|iterator
name|last
init|=
name|first
decl_stmt|;
operator|++
name|last
expr_stmt|;
if|if
condition|(
name|where
operator|==
name|first
operator|||
name|where
operator|==
name|last
condition|)
return|return;
comment|// No change
name|transfer
argument_list|(
name|where
argument_list|,
name|L2
argument_list|,
name|first
argument_list|,
name|last
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|splice
parameter_list|(
name|iterator
name|where
parameter_list|,
name|iplist_impl
modifier|&
name|L2
parameter_list|,
name|iterator
name|first
parameter_list|,
name|iterator
name|last
parameter_list|)
block|{
if|if
condition|(
name|first
operator|!=
name|last
condition|)
name|transfer
argument_list|(
name|where
argument_list|,
name|L2
argument_list|,
name|first
argument_list|,
name|last
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|splice
parameter_list|(
name|iterator
name|where
parameter_list|,
name|iplist_impl
modifier|&
name|L2
parameter_list|,
name|reference
name|N
parameter_list|)
block|{
name|splice
argument_list|(
name|where
argument_list|,
name|L2
argument_list|,
name|iterator
argument_list|(
name|N
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|splice
parameter_list|(
name|iterator
name|where
parameter_list|,
name|iplist_impl
modifier|&
name|L2
parameter_list|,
name|pointer
name|N
parameter_list|)
block|{
name|splice
argument_list|(
name|where
argument_list|,
name|L2
argument_list|,
name|iterator
argument_list|(
name|N
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|template
operator|<
name|class
name|Compare
operator|>
name|void
name|merge
argument_list|(
argument|iplist_impl&Right
argument_list|,
argument|Compare comp
argument_list|)
block|{
if|if
condition|(
name|this
operator|==
operator|&
name|Right
condition|)
return|return;
name|this
operator|->
name|transferNodesFromList
argument_list|(
name|Right
argument_list|,
name|Right
operator|.
name|begin
argument_list|()
argument_list|,
name|Right
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|base_list_type
operator|::
name|merge
argument_list|(
name|Right
argument_list|,
name|comp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
unit|}   void
name|merge
argument_list|(
argument|iplist_impl&Right
argument_list|)
end_macro

begin_block
block|{
return|return
name|merge
argument_list|(
name|Right
argument_list|,
name|op_less
argument_list|)
return|;
block|}
end_block

begin_expr_stmt
name|using
name|base_list_type
operator|::
name|sort
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Get the previous node, or \c nullptr for the list head.
end_comment

begin_decl_stmt
name|pointer
name|getPrevNode
argument_list|(
name|reference
name|N
argument_list|)
decl|const
block|{
name|auto
name|I
init|=
name|N
operator|.
name|getIterator
argument_list|()
decl_stmt|;
if|if
condition|(
name|I
operator|==
name|begin
argument_list|()
condition|)
return|return
name|nullptr
return|;
return|return
operator|&
operator|*
name|std
operator|::
name|prev
argument_list|(
name|I
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Get the previous node, or \c nullptr for the list head.
end_comment

begin_decl_stmt
name|const_pointer
name|getPrevNode
argument_list|(
name|const_reference
name|N
argument_list|)
decl|const
block|{
return|return
name|getPrevNode
argument_list|(
name|const_cast
operator|<
name|reference
operator|>
operator|(
name|N
operator|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Get the next node, or \c nullptr for the list tail.
end_comment

begin_decl_stmt
name|pointer
name|getNextNode
argument_list|(
name|reference
name|N
argument_list|)
decl|const
block|{
name|auto
name|Next
init|=
name|std
operator|::
name|next
argument_list|(
name|N
operator|.
name|getIterator
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|Next
operator|==
name|end
argument_list|()
condition|)
return|return
name|nullptr
return|;
return|return
operator|&
operator|*
name|Next
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Get the next node, or \c nullptr for the list tail.
end_comment

begin_decl_stmt
name|const_pointer
name|getNextNode
argument_list|(
name|const_reference
name|N
argument_list|)
decl|const
block|{
return|return
name|getNextNode
argument_list|(
name|const_cast
operator|<
name|reference
operator|>
operator|(
name|N
operator|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
unit|};
comment|/// An intrusive list with ownership and callbacks specified/controlled by
end_comment

begin_comment
comment|/// ilist_traits, only with API safe for polymorphic types.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The \p Options parameters are the same as those for \a simple_ilist.  See
end_comment

begin_comment
comment|/// there for a description of what's available.
end_comment

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
name|class
name|iplist
operator|:
name|public
name|iplist_impl
operator|<
name|simple_ilist
operator|<
name|T
operator|,
name|Options
operator|...
operator|>
operator|,
name|ilist_traits
operator|<
name|T
operator|>>
block|{
typedef|typedef
name|typename
name|iplist
operator|::
name|iplist_impl_type
name|iplist_impl_type
expr_stmt|;
name|public
operator|:
name|iplist
argument_list|()
operator|=
block|default
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|iplist
argument_list|(
specifier|const
name|iplist
operator|&
name|X
argument_list|)
operator|=
name|delete
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|iplist
modifier|&
name|operator
init|=
operator|(
specifier|const
name|iplist
operator|&
name|X
operator|)
operator|=
name|delete
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|iplist
argument_list|(
name|iplist
operator|&&
name|X
argument_list|)
operator|:
name|iplist_impl_type
argument_list|(
argument|std::move(X)
argument_list|)
block|{}
name|iplist
operator|&
name|operator
operator|=
operator|(
name|iplist
operator|&&
name|X
operator|)
block|{
operator|*
name|static_cast
operator|<
name|iplist_impl_type
operator|*
operator|>
operator|(
name|this
operator|)
operator|=
name|std
operator|::
name|move
argument_list|(
name|X
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|T
operator|,
name|class
operator|...
name|Options
operator|>
name|using
name|ilist
operator|=
name|iplist
operator|<
name|T
operator|,
name|Options
operator|...
operator|>
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_macro
unit|namespace
name|std
end_macro

begin_block
block|{
comment|// Ensure that swap uses the fast list swap...
name|template
operator|<
name|class
name|Ty
operator|>
name|void
name|swap
argument_list|(
argument|llvm::iplist<Ty>&Left
argument_list|,
argument|llvm::iplist<Ty>&Right
argument_list|)
block|{
name|Left
operator|.
name|swap
argument_list|(
name|Right
argument_list|)
block|;   }
block|}
end_block

begin_comment
comment|// end namespace std
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_ADT_ILIST_H
end_comment

end_unit

