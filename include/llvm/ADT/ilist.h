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
comment|// The ilist_traits trait class is used to gain access to the next and previous
end_comment

begin_comment
comment|// fields of the node type that the list is instantiated with.  If it is not
end_comment

begin_comment
comment|// specialized, the list defaults to using the getPrev(), getNext() method calls
end_comment

begin_comment
comment|// to get the next and previous pointers.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The ilist class itself, should be a plug in replacement for list, assuming
end_comment

begin_comment
comment|// that the nodes contain next/prev pointers.  This list replacement does not
end_comment

begin_comment
comment|// provide a constant time size() method, so be careful to use empty() when you
end_comment

begin_comment
comment|// really want to know if it's empty.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The ilist class is implemented by allocating a 'tail' node when the list is
end_comment

begin_comment
comment|// created (using ilist_traits<>::createSentinel()).  This tail node is
end_comment

begin_comment
comment|// absolutely required because the user must be able to compute end()-1. Because
end_comment

begin_comment
comment|// of this, users of the direct next/prev links will see an extra link on the
end_comment

begin_comment
comment|// end of the list, which should be ignored.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Requirements for a user of this list:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   1. The user must provide {g|s}et{Next|Prev} methods, or specialize
end_comment

begin_comment
comment|//      ilist_traits to provide an alternate way of getting and setting next and
end_comment

begin_comment
comment|//      prev links.
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
file|<cassert>
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
name|template
operator|<
name|typename
name|NodeTy
operator|,
name|typename
name|Traits
operator|>
name|class
name|iplist
expr_stmt|;
name|template
operator|<
name|typename
name|NodeTy
operator|>
name|class
name|ilist_iterator
expr_stmt|;
comment|/// ilist_nextprev_traits - A fragment for template traits for intrusive list
comment|/// that provides default next/prev implementations for common operations.
comment|///
name|template
operator|<
name|typename
name|NodeTy
operator|>
expr|struct
name|ilist_nextprev_traits
block|{
specifier|static
name|NodeTy
operator|*
name|getPrev
argument_list|(
argument|NodeTy *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getPrev
argument_list|()
return|;
block|}
specifier|static
name|NodeTy
operator|*
name|getNext
argument_list|(
argument|NodeTy *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getNext
argument_list|()
return|;
block|}
specifier|static
specifier|const
name|NodeTy
operator|*
name|getPrev
argument_list|(
argument|const NodeTy *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getPrev
argument_list|()
return|;
block|}
specifier|static
specifier|const
name|NodeTy
operator|*
name|getNext
argument_list|(
argument|const NodeTy *N
argument_list|)
block|{
return|return
name|N
operator|->
name|getNext
argument_list|()
return|;
block|}
specifier|static
name|void
name|setPrev
argument_list|(
argument|NodeTy *N
argument_list|,
argument|NodeTy *Prev
argument_list|)
block|{
name|N
operator|->
name|setPrev
argument_list|(
name|Prev
argument_list|)
block|; }
specifier|static
name|void
name|setNext
argument_list|(
argument|NodeTy *N
argument_list|,
argument|NodeTy *Next
argument_list|)
block|{
name|N
operator|->
name|setNext
argument_list|(
name|Next
argument_list|)
block|; }
expr|}
block|;
name|template
operator|<
name|typename
name|NodeTy
operator|>
expr|struct
name|ilist_traits
block|;
comment|/// ilist_sentinel_traits - A fragment for template traits for intrusive list
comment|/// that provides default sentinel implementations for common operations.
comment|///
comment|/// ilist_sentinel_traits implements a lazy dynamic sentinel allocation
comment|/// strategy. The sentinel is stored in the prev field of ilist's Head.
comment|///
name|template
operator|<
name|typename
name|NodeTy
operator|>
expr|struct
name|ilist_sentinel_traits
block|{
comment|/// createSentinel - create the dynamic sentinel
specifier|static
name|NodeTy
operator|*
name|createSentinel
argument_list|()
block|{
return|return
name|new
name|NodeTy
argument_list|()
return|;
block|}
comment|/// destroySentinel - deallocate the dynamic sentinel
specifier|static
name|void
name|destroySentinel
argument_list|(
argument|NodeTy *N
argument_list|)
block|{
name|delete
name|N
block|; }
comment|/// provideInitialHead - when constructing an ilist, provide a starting
comment|/// value for its Head
comment|/// @return null node to indicate that it needs to be allocated later
specifier|static
name|NodeTy
operator|*
name|provideInitialHead
argument_list|()
block|{
return|return
literal|0
return|;
block|}
comment|/// ensureHead - make sure that Head is either already
comment|/// initialized or assigned a fresh sentinel
comment|/// @return the sentinel
specifier|static
name|NodeTy
operator|*
name|ensureHead
argument_list|(
argument|NodeTy *&Head
argument_list|)
block|{
if|if
condition|(
operator|!
name|Head
condition|)
block|{
name|Head
operator|=
name|ilist_traits
operator|<
name|NodeTy
operator|>
operator|::
name|createSentinel
argument_list|()
expr_stmt|;
name|ilist_traits
operator|<
name|NodeTy
operator|>
operator|::
name|noteHead
argument_list|(
name|Head
argument_list|,
name|Head
argument_list|)
expr_stmt|;
name|ilist_traits
operator|<
name|NodeTy
operator|>
operator|::
name|setNext
argument_list|(
name|Head
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
name|Head
return|;
block|}
return|return
name|ilist_traits
operator|<
name|NodeTy
operator|>
operator|::
name|getPrev
argument_list|(
name|Head
argument_list|)
return|;
block|}
comment|/// noteHead - stash the sentinel into its default location
specifier|static
name|void
name|noteHead
argument_list|(
argument|NodeTy *NewHead
argument_list|,
argument|NodeTy *Sentinel
argument_list|)
block|{
name|ilist_traits
operator|<
name|NodeTy
operator|>
operator|::
name|setPrev
argument_list|(
name|NewHead
argument_list|,
name|Sentinel
argument_list|)
block|;   }
expr|}
block|;
comment|/// ilist_node_traits - A fragment for template traits for intrusive list
comment|/// that provides default node related operations.
comment|///
name|template
operator|<
name|typename
name|NodeTy
operator|>
expr|struct
name|ilist_node_traits
block|{
specifier|static
name|NodeTy
operator|*
name|createNode
argument_list|(
argument|const NodeTy&V
argument_list|)
block|{
return|return
name|new
name|NodeTy
argument_list|(
name|V
argument_list|)
return|;
block|}
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
name|void
name|transferNodesFromList
argument_list|(
argument|ilist_node_traits&
comment|/*SrcTraits*/
argument_list|,
argument|ilist_iterator<NodeTy>
comment|/*first*/
argument_list|,
argument|ilist_iterator<NodeTy>
comment|/*last*/
argument_list|)
block|{}
expr|}
block|;
comment|/// ilist_default_traits - Default template traits for intrusive list.
comment|/// By inheriting from this, you can easily use default implementations
comment|/// for all common operations.
comment|///
name|template
operator|<
name|typename
name|NodeTy
operator|>
expr|struct
name|ilist_default_traits
operator|:
name|public
name|ilist_nextprev_traits
operator|<
name|NodeTy
operator|>
block|,
name|public
name|ilist_sentinel_traits
operator|<
name|NodeTy
operator|>
block|,
name|public
name|ilist_node_traits
operator|<
name|NodeTy
operator|>
block|{ }
block|;
comment|// Template traits for intrusive list.  By specializing this template class, you
comment|// can change what next/prev fields are used to store the links...
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
block|;
comment|// Const traits are the same as nonconst traits...
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
operator|:
name|public
name|ilist_traits
operator|<
name|Ty
operator|>
block|{}
block|;
comment|//===----------------------------------------------------------------------===//
comment|// ilist_iterator<Node> - Iterator for intrusive list.
comment|//
name|template
operator|<
name|typename
name|NodeTy
operator|>
name|class
name|ilist_iterator
operator|:
name|public
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|bidirectional_iterator_tag
block|,
name|NodeTy
block|,
name|ptrdiff_t
operator|>
block|{
name|public
operator|:
typedef|typedef
name|ilist_traits
operator|<
name|NodeTy
operator|>
name|Traits
expr_stmt|;
typedef|typedef
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|bidirectional_iterator_tag
operator|,
name|NodeTy
operator|,
name|ptrdiff_t
operator|>
name|super
expr_stmt|;
typedef|typedef
name|typename
name|super
operator|::
name|value_type
name|value_type
expr_stmt|;
typedef|typedef
name|typename
name|super
operator|::
name|difference_type
name|difference_type
expr_stmt|;
typedef|typedef
name|typename
name|super
operator|::
name|pointer
name|pointer
expr_stmt|;
typedef|typedef
name|typename
name|super
operator|::
name|reference
name|reference
expr_stmt|;
name|private
label|:
name|pointer
name|NodePtr
decl_stmt|;
comment|// ilist_iterator is not a random-access iterator, but it has an
comment|// implicit conversion to pointer-type, which is. Declare (but
comment|// don't define) these functions as private to help catch
comment|// accidental misuse.
name|void
name|operator
index|[]
argument_list|(
name|difference_type
argument_list|)
decl|const
decl_stmt|;
name|void
name|operator
operator|+
operator|(
name|difference_type
operator|)
specifier|const
expr_stmt|;
name|void
name|operator
operator|-
operator|(
name|difference_type
operator|)
specifier|const
expr_stmt|;
name|void
name|operator
operator|+=
operator|(
name|difference_type
operator|)
specifier|const
expr_stmt|;
name|void
name|operator
operator|-=
operator|(
name|difference_type
operator|)
specifier|const
expr_stmt|;
name|template
operator|<
name|class
name|T
operator|>
name|void
name|operator
operator|<
operator|(
name|T
operator|)
specifier|const
expr_stmt|;
name|template
operator|<
name|class
name|T
operator|>
name|void
name|operator
operator|<=
operator|(
name|T
operator|)
specifier|const
expr_stmt|;
name|template
operator|<
name|class
name|T
operator|>
name|void
name|operator
operator|>
operator|(
name|T
operator|)
specifier|const
expr_stmt|;
name|template
operator|<
name|class
name|T
operator|>
name|void
name|operator
operator|>=
operator|(
name|T
operator|)
specifier|const
expr_stmt|;
name|template
operator|<
name|class
name|T
operator|>
name|void
name|operator
operator|-
operator|(
name|T
operator|)
specifier|const
expr_stmt|;
name|public
label|:
name|ilist_iterator
argument_list|(
argument|pointer NP
argument_list|)
block|:
name|NodePtr
argument_list|(
argument|NP
argument_list|)
block|{}
name|ilist_iterator
argument_list|(
argument|reference NR
argument_list|)
block|:
name|NodePtr
argument_list|(
argument|&NR
argument_list|)
block|{}
name|ilist_iterator
argument_list|()
operator|:
name|NodePtr
argument_list|(
literal|0
argument_list|)
block|{}
comment|// This is templated so that we can allow constructing a const iterator from
comment|// a nonconst iterator...
name|template
operator|<
name|class
name|node_ty
operator|>
name|ilist_iterator
argument_list|(
specifier|const
name|ilist_iterator
operator|<
name|node_ty
operator|>
operator|&
name|RHS
argument_list|)
operator|:
name|NodePtr
argument_list|(
argument|RHS.getNodePtrUnchecked()
argument_list|)
block|{}
comment|// This is templated so that we can allow assigning to a const iterator from
comment|// a nonconst iterator...
name|template
operator|<
name|class
name|node_ty
operator|>
specifier|const
name|ilist_iterator
operator|&
name|operator
operator|=
operator|(
specifier|const
name|ilist_iterator
operator|<
name|node_ty
operator|>
operator|&
name|RHS
operator|)
block|{
name|NodePtr
operator|=
name|RHS
operator|.
name|getNodePtrUnchecked
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
comment|// Accessors...
name|operator
name|pointer
argument_list|()
specifier|const
block|{
return|return
name|NodePtr
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
name|NodePtr
return|;
block|}
name|pointer
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
operator|&
name|operator
operator|*
operator|(
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|// Comparison operators
end_comment

begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|ilist_iterator
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|NodePtr
operator|==
name|RHS
operator|.
name|NodePtr
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|ilist_iterator
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|NodePtr
operator|!=
name|RHS
operator|.
name|NodePtr
return|;
block|}
end_expr_stmt

begin_comment
comment|// Increment and decrement operators...
end_comment

begin_expr_stmt
name|ilist_iterator
operator|&
name|operator
operator|--
operator|(
operator|)
block|{
comment|// predecrement - Back up
name|NodePtr
operator|=
name|Traits
operator|::
name|getPrev
argument_list|(
name|NodePtr
argument_list|)
block|;
name|assert
argument_list|(
name|NodePtr
operator|&&
literal|"--'d off the beginning of an ilist!"
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|ilist_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
comment|// preincrement - Advance
name|NodePtr
operator|=
name|Traits
operator|::
name|getNext
argument_list|(
name|NodePtr
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|ilist_iterator
name|operator
operator|--
operator|(
name|int
operator|)
block|{
comment|// postdecrement operators...
name|ilist_iterator
name|tmp
operator|=
operator|*
name|this
block|;
operator|--
operator|*
name|this
block|;
return|return
name|tmp
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|ilist_iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
comment|// postincrement operators...
name|ilist_iterator
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

begin_comment
comment|// Internal interface, do not use...
end_comment

begin_expr_stmt
name|pointer
name|getNodePtrUnchecked
argument_list|()
specifier|const
block|{
return|return
name|NodePtr
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|// do not implement. this is to catch errors when people try to use
end_comment

begin_comment
comment|// them as random access iterators
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|operator
operator|-
operator|(
name|int
operator|,
name|ilist_iterator
operator|<
name|T
operator|>
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|operator
operator|-
operator|(
name|ilist_iterator
operator|<
name|T
operator|>
operator|,
name|int
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|operator
operator|+
operator|(
name|int
operator|,
name|ilist_iterator
operator|<
name|T
operator|>
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|operator
operator|+
operator|(
name|ilist_iterator
operator|<
name|T
operator|>
operator|,
name|int
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// operator!=/operator== - Allow mixed comparisons without dereferencing
end_comment

begin_comment
comment|// the iterator, which could very likely be pointing to end().
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|T
operator|*
name|LHS
operator|,
specifier|const
name|ilist_iterator
operator|<
specifier|const
name|T
operator|>
operator|&
name|RHS
operator|)
block|{
return|return
name|LHS
operator|!=
name|RHS
operator|.
name|getNodePtrUnchecked
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|bool
name|operator
operator|==
operator|(
specifier|const
name|T
operator|*
name|LHS
operator|,
specifier|const
name|ilist_iterator
operator|<
specifier|const
name|T
operator|>
operator|&
name|RHS
operator|)
block|{
return|return
name|LHS
operator|==
name|RHS
operator|.
name|getNodePtrUnchecked
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|bool
name|operator
operator|!=
operator|(
name|T
operator|*
name|LHS
operator|,
specifier|const
name|ilist_iterator
operator|<
name|T
operator|>
operator|&
name|RHS
operator|)
block|{
return|return
name|LHS
operator|!=
name|RHS
operator|.
name|getNodePtrUnchecked
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|bool
name|operator
operator|==
operator|(
name|T
operator|*
name|LHS
operator|,
specifier|const
name|ilist_iterator
operator|<
name|T
operator|>
operator|&
name|RHS
operator|)
block|{
return|return
name|LHS
operator|==
name|RHS
operator|.
name|getNodePtrUnchecked
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|// Allow ilist_iterators to convert into pointers to a node automatically when
end_comment

begin_comment
comment|// used by the dyn_cast, cast, isa mechanisms...
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|From
operator|>
expr|struct
name|simplify_type
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|NodeTy
operator|>
expr|struct
name|simplify_type
operator|<
name|ilist_iterator
operator|<
name|NodeTy
operator|>
expr|>
block|{
typedef|typedef
name|NodeTy
modifier|*
name|SimpleType
typedef|;
specifier|static
name|SimpleType
name|getSimplifiedValue
argument_list|(
argument|const ilist_iterator<NodeTy>&Node
argument_list|)
block|{
return|return
operator|&
operator|*
name|Node
return|;
block|}
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|NodeTy
operator|>
expr|struct
name|simplify_type
operator|<
specifier|const
name|ilist_iterator
operator|<
name|NodeTy
operator|>
expr|>
block|{
typedef|typedef
name|NodeTy
modifier|*
name|SimpleType
typedef|;
specifier|static
name|SimpleType
name|getSimplifiedValue
argument_list|(
argument|const ilist_iterator<NodeTy>&Node
argument_list|)
block|{
return|return
operator|&
operator|*
name|Node
return|;
block|}
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// iplist - The subset of list functionality that can safely be used on nodes
end_comment

begin_comment
comment|/// of polymorphic types, i.e. a heterogenous list with a common base class that
end_comment

begin_comment
comment|/// holds the next/prev pointers.  The only state of the list itself is a single
end_comment

begin_comment
comment|/// pointer to the head of the list.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This list can be in one of three interesting states:
end_comment

begin_comment
comment|/// 1. The list may be completely unconstructed.  In this case, the head
end_comment

begin_comment
comment|///    pointer is null.  When in this form, any query for an iterator (e.g.
end_comment

begin_comment
comment|///    begin() or end()) causes the list to transparently change to state #2.
end_comment

begin_comment
comment|/// 2. The list may be empty, but contain a sentinel for the end iterator. This
end_comment

begin_comment
comment|///    sentinel is created by the Traits::createSentinel method and is a link
end_comment

begin_comment
comment|///    in the list.  When the list is empty, the pointer in the iplist points
end_comment

begin_comment
comment|///    to the sentinel.  Once the sentinel is constructed, it
end_comment

begin_comment
comment|///    is not destroyed until the list is.
end_comment

begin_comment
comment|/// 3. The list may contain actual objects in it, which are stored as a doubly
end_comment

begin_comment
comment|///    linked list of nodes.  One invariant of the list is that the predecessor
end_comment

begin_comment
comment|///    of the first node in the list always points to the last node in the list,
end_comment

begin_comment
comment|///    and the successor pointer for the sentinel (which always stays at the
end_comment

begin_comment
comment|///    end of the list) is always null.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|NodeTy
operator|,
name|typename
name|Traits
operator|=
name|ilist_traits
operator|<
name|NodeTy
operator|>
expr|>
name|class
name|iplist
operator|:
name|public
name|Traits
block|{
name|mutable
name|NodeTy
operator|*
name|Head
block|;
comment|// Use the prev node pointer of 'head' as the tail pointer.  This is really a
comment|// circularly linked list where we snip the 'next' link from the sentinel node
comment|// back to the first node in the list (to preserve assertions about going off
comment|// the end of the list).
name|NodeTy
operator|*
name|getTail
argument_list|()
block|{
return|return
name|this
operator|->
name|ensureHead
argument_list|(
name|Head
argument_list|)
return|;
block|}
specifier|const
name|NodeTy
operator|*
name|getTail
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|ensureHead
argument_list|(
name|Head
argument_list|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|setTail
argument_list|(
name|NodeTy
operator|*
name|N
argument_list|)
decl|const
block|{
name|this
operator|->
name|noteHead
argument_list|(
name|Head
argument_list|,
name|N
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// CreateLazySentinel - This method verifies whether the sentinel for the
end_comment

begin_comment
comment|/// list has been created and lazily makes it if not.
end_comment

begin_expr_stmt
name|void
name|CreateLazySentinel
argument_list|()
specifier|const
block|{
name|this
operator|->
name|ensureHead
argument_list|(
name|Head
argument_list|)
block|;   }
specifier|static
name|bool
name|op_less
argument_list|(
argument|NodeTy&L
argument_list|,
argument|NodeTy&R
argument_list|)
block|{
return|return
name|L
operator|<
name|R
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|bool
name|op_equal
parameter_list|(
name|NodeTy
modifier|&
name|L
parameter_list|,
name|NodeTy
modifier|&
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

begin_comment
comment|// No fundamental reason why iplist can't be copyable, but the default
end_comment

begin_comment
comment|// copy/copy-assign won't do.
end_comment

begin_expr_stmt
name|iplist
argument_list|(
specifier|const
name|iplist
operator|&
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// do not implement
end_comment

begin_decl_stmt
name|void
name|operator
init|=
operator|(
specifier|const
name|iplist
operator|&
operator|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// do not implement
end_comment

begin_label
name|public
label|:
end_label

begin_typedef
typedef|typedef
name|NodeTy
modifier|*
name|pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|NodeTy
modifier|*
name|const_pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|NodeTy
modifier|&
name|reference
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|NodeTy
modifier|&
name|const_reference
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|NodeTy
name|value_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ilist_iterator
operator|<
name|NodeTy
operator|>
name|iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|ilist_iterator
operator|<
specifier|const
name|NodeTy
operator|>
name|const_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|size_t
name|size_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ptrdiff_t
name|difference_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|reverse_iterator
operator|<
name|const_iterator
operator|>
name|const_reverse_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|reverse_iterator
operator|<
name|iterator
operator|>
name|reverse_iterator
expr_stmt|;
end_typedef

begin_expr_stmt
name|iplist
argument_list|()
operator|:
name|Head
argument_list|(
argument|this->provideInitialHead()
argument_list|)
block|{}
operator|~
name|iplist
argument_list|()
block|{
if|if
condition|(
operator|!
name|Head
condition|)
return|return;
name|clear
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|Traits
operator|::
name|destroySentinel
argument_list|(
name|getTail
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// Iterator creation methods.
end_comment

begin_macro
unit|iterator
name|begin
argument_list|()
end_macro

begin_block
block|{
name|CreateLazySentinel
argument_list|()
expr_stmt|;
return|return
name|iterator
argument_list|(
name|Head
argument_list|)
return|;
block|}
end_block

begin_expr_stmt
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
name|CreateLazySentinel
argument_list|()
block|;
return|return
name|const_iterator
argument_list|(
name|Head
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
name|iterator
name|end
parameter_list|()
block|{
name|CreateLazySentinel
argument_list|()
expr_stmt|;
return|return
name|iterator
argument_list|(
name|getTail
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
name|CreateLazySentinel
argument_list|()
block|;
return|return
name|const_iterator
argument_list|(
name|getTail
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// reverse iterator creation methods.
end_comment

begin_function
name|reverse_iterator
name|rbegin
parameter_list|()
block|{
return|return
name|reverse_iterator
argument_list|(
name|end
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|const_reverse_iterator
name|rbegin
argument_list|()
specifier|const
block|{
return|return
name|const_reverse_iterator
argument_list|(
name|end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
name|reverse_iterator
name|rend
parameter_list|()
block|{
return|return
name|reverse_iterator
argument_list|(
name|begin
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|const_reverse_iterator
name|rend
argument_list|()
specifier|const
block|{
return|return
name|const_reverse_iterator
argument_list|(
name|begin
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Miscellaneous inspection routines.
end_comment

begin_expr_stmt
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
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|Head
operator|==
literal|0
operator|||
name|Head
operator|==
name|getTail
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|// Front and back accessor functions...
end_comment

begin_function
name|reference
name|front
parameter_list|()
block|{
name|assert
argument_list|(
operator|!
name|empty
argument_list|()
operator|&&
literal|"Called front() on empty list!"
argument_list|)
expr_stmt|;
return|return
operator|*
name|Head
return|;
block|}
end_function

begin_expr_stmt
name|const_reference
name|front
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|empty
argument_list|()
operator|&&
literal|"Called front() on empty list!"
argument_list|)
block|;
return|return
operator|*
name|Head
return|;
block|}
end_expr_stmt

begin_function
name|reference
name|back
parameter_list|()
block|{
name|assert
argument_list|(
operator|!
name|empty
argument_list|()
operator|&&
literal|"Called back() on empty list!"
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
operator|->
name|getPrev
argument_list|(
name|getTail
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|const_reference
name|back
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|empty
argument_list|()
operator|&&
literal|"Called back() on empty list!"
argument_list|)
block|;
return|return
operator|*
name|this
operator|->
name|getPrev
argument_list|(
name|getTail
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
name|void
name|swap
parameter_list|(
name|iplist
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
name|std
operator|::
name|swap
argument_list|(
name|Head
argument_list|,
name|RHS
operator|.
name|Head
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
name|NodeTy
modifier|*
name|New
parameter_list|)
block|{
name|NodeTy
modifier|*
name|CurNode
init|=
name|where
operator|.
name|getNodePtrUnchecked
argument_list|()
decl_stmt|;
name|NodeTy
modifier|*
name|PrevNode
init|=
name|this
operator|->
name|getPrev
argument_list|(
name|CurNode
argument_list|)
decl_stmt|;
name|this
operator|->
name|setNext
argument_list|(
name|New
argument_list|,
name|CurNode
argument_list|)
expr_stmt|;
name|this
operator|->
name|setPrev
argument_list|(
name|New
argument_list|,
name|PrevNode
argument_list|)
expr_stmt|;
if|if
condition|(
name|CurNode
operator|!=
name|Head
condition|)
comment|// Is PrevNode off the beginning of the list?
name|this
operator|->
name|setNext
argument_list|(
name|PrevNode
argument_list|,
name|New
argument_list|)
expr_stmt|;
else|else
name|Head
operator|=
name|New
expr_stmt|;
name|this
operator|->
name|setPrev
argument_list|(
name|CurNode
argument_list|,
name|New
argument_list|)
expr_stmt|;
name|this
operator|->
name|addNodeToList
argument_list|(
name|New
argument_list|)
expr_stmt|;
comment|// Notify traits that we added a node...
return|return
name|New
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
name|NodeTy
modifier|*
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

begin_function
name|NodeTy
modifier|*
name|remove
parameter_list|(
name|iterator
modifier|&
name|IT
parameter_list|)
block|{
name|assert
argument_list|(
name|IT
operator|!=
name|end
argument_list|()
operator|&&
literal|"Cannot remove end of list!"
argument_list|)
expr_stmt|;
name|NodeTy
modifier|*
name|Node
init|=
operator|&
operator|*
name|IT
decl_stmt|;
name|NodeTy
modifier|*
name|NextNode
init|=
name|this
operator|->
name|getNext
argument_list|(
name|Node
argument_list|)
decl_stmt|;
name|NodeTy
modifier|*
name|PrevNode
init|=
name|this
operator|->
name|getPrev
argument_list|(
name|Node
argument_list|)
decl_stmt|;
if|if
condition|(
name|Node
operator|!=
name|Head
condition|)
comment|// Is PrevNode off the beginning of the list?
name|this
operator|->
name|setNext
argument_list|(
name|PrevNode
argument_list|,
name|NextNode
argument_list|)
expr_stmt|;
else|else
name|Head
operator|=
name|NextNode
expr_stmt|;
name|this
operator|->
name|setPrev
argument_list|(
name|NextNode
argument_list|,
name|PrevNode
argument_list|)
expr_stmt|;
name|IT
operator|=
name|NextNode
expr_stmt|;
name|this
operator|->
name|removeNodeFromList
argument_list|(
name|Node
argument_list|)
expr_stmt|;
comment|// Notify traits that we removed a node...
comment|// Set the next/prev pointers of the current node to null.  This isn't
comment|// strictly required, but this catches errors where a node is removed from
comment|// an ilist (and potentially deleted) with iterators still pointing at it.
comment|// When those iterators are incremented or decremented, they will assert on
comment|// the null next/prev pointer instead of "usually working".
name|this
operator|->
name|setNext
argument_list|(
name|Node
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|this
operator|->
name|setPrev
argument_list|(
name|Node
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
name|Node
return|;
block|}
end_function

begin_function
name|NodeTy
modifier|*
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
name|iplist
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
name|assert
argument_list|(
name|first
operator|!=
name|last
operator|&&
literal|"Should be checked by callers"
argument_list|)
expr_stmt|;
if|if
condition|(
name|position
operator|!=
name|last
condition|)
block|{
comment|// Note: we have to be careful about the case when we move the first node
comment|// in the list.  This node is the list sentinel node and we can't move it.
name|NodeTy
modifier|*
name|ThisSentinel
init|=
name|getTail
argument_list|()
decl_stmt|;
name|setTail
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|NodeTy
modifier|*
name|L2Sentinel
init|=
name|L2
operator|.
name|getTail
argument_list|()
decl_stmt|;
name|L2
operator|.
name|setTail
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// Remove [first, last) from its old position.
name|NodeTy
modifier|*
name|First
init|=
operator|&
operator|*
name|first
decl_stmt|,
modifier|*
name|Prev
init|=
name|this
operator|->
name|getPrev
argument_list|(
name|First
argument_list|)
decl_stmt|;
name|NodeTy
modifier|*
name|Next
init|=
name|last
operator|.
name|getNodePtrUnchecked
argument_list|()
decl_stmt|,
modifier|*
name|Last
init|=
name|this
operator|->
name|getPrev
argument_list|(
name|Next
argument_list|)
decl_stmt|;
if|if
condition|(
name|Prev
condition|)
name|this
operator|->
name|setNext
argument_list|(
name|Prev
argument_list|,
name|Next
argument_list|)
expr_stmt|;
else|else
name|L2
operator|.
name|Head
operator|=
name|Next
expr_stmt|;
name|this
operator|->
name|setPrev
argument_list|(
name|Next
argument_list|,
name|Prev
argument_list|)
expr_stmt|;
comment|// Splice [first, last) into its new position.
name|NodeTy
modifier|*
name|PosNext
init|=
name|position
operator|.
name|getNodePtrUnchecked
argument_list|()
decl_stmt|;
name|NodeTy
modifier|*
name|PosPrev
init|=
name|this
operator|->
name|getPrev
argument_list|(
name|PosNext
argument_list|)
decl_stmt|;
comment|// Fix head of list...
if|if
condition|(
name|PosPrev
condition|)
name|this
operator|->
name|setNext
argument_list|(
name|PosPrev
argument_list|,
name|First
argument_list|)
expr_stmt|;
else|else
name|Head
operator|=
name|First
expr_stmt|;
name|this
operator|->
name|setPrev
argument_list|(
name|First
argument_list|,
name|PosPrev
argument_list|)
expr_stmt|;
comment|// Fix end of list...
name|this
operator|->
name|setNext
argument_list|(
name|Last
argument_list|,
name|PosNext
argument_list|)
expr_stmt|;
name|this
operator|->
name|setPrev
argument_list|(
name|PosNext
argument_list|,
name|Last
argument_list|)
expr_stmt|;
name|this
operator|->
name|transferNodesFromList
argument_list|(
name|L2
argument_list|,
name|First
argument_list|,
name|PosNext
argument_list|)
expr_stmt|;
comment|// Now that everything is set, restore the pointers to the list sentinels.
name|L2
operator|.
name|setTail
argument_list|(
name|L2Sentinel
argument_list|)
expr_stmt|;
name|setTail
argument_list|(
name|ThisSentinel
argument_list|)
expr_stmt|;
block|}
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
name|size_type
name|size
argument_list|()
specifier|const
block|{
if|if
condition|(
name|Head
operator|==
literal|0
condition|)
return|return
literal|0
return|;
end_expr_stmt

begin_comment
comment|// Don't require construction of sentinel if empty.
end_comment

begin_return
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
end_return

begin_macro
unit|}    iterator
name|erase
argument_list|(
argument|iterator first
argument_list|,
argument|iterator last
argument_list|)
end_macro

begin_block
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
end_block

begin_function
name|void
name|clear
parameter_list|()
block|{
if|if
condition|(
name|Head
condition|)
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
name|NodeTy
modifier|*
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
name|NodeTy
modifier|*
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
name|iplist
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
name|iplist
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
name|iplist
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

begin_comment
comment|//===----------------------------------------------------------------------===
end_comment

begin_comment
comment|// High-Level Functionality that shouldn't really be here, but is part of list
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// These two functions are actually called remove/remove_if in list<>, but
end_comment

begin_comment
comment|// they actually do the job of erase, rename them accordingly.
end_comment

begin_comment
comment|//
end_comment

begin_function
name|void
name|erase
parameter_list|(
specifier|const
name|NodeTy
modifier|&
name|val
parameter_list|)
block|{
for|for
control|(
name|iterator
name|I
init|=
name|begin
argument_list|()
init|,
name|E
init|=
name|end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
control|)
block|{
name|iterator
name|next
init|=
name|I
decl_stmt|;
operator|++
name|next
expr_stmt|;
if|if
condition|(
operator|*
name|I
operator|==
name|val
condition|)
name|erase
argument_list|(
name|I
argument_list|)
expr_stmt|;
name|I
operator|=
name|next
expr_stmt|;
block|}
block|}
end_function

begin_expr_stmt
name|template
operator|<
name|class
name|Pr1
operator|>
name|void
name|erase_if
argument_list|(
argument|Pr1 pred
argument_list|)
block|{
for|for
control|(
name|iterator
name|I
init|=
name|begin
argument_list|()
init|,
name|E
init|=
name|end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
control|)
block|{
name|iterator
name|next
init|=
name|I
decl_stmt|;
operator|++
name|next
expr_stmt|;
if|if
condition|(
name|pred
argument_list|(
operator|*
name|I
argument_list|)
condition|)
name|erase
argument_list|(
name|I
argument_list|)
expr_stmt|;
name|I
operator|=
name|next
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
unit|}    template
operator|<
name|class
name|Pr2
operator|>
name|void
name|unique
argument_list|(
argument|Pr2 pred
argument_list|)
block|{
if|if
condition|(
name|empty
argument_list|()
condition|)
return|return;
end_expr_stmt

begin_for
for|for
control|(
name|iterator
name|I
init|=
name|begin
argument_list|()
init|,
name|E
init|=
name|end
argument_list|()
init|,
name|Next
init|=
name|begin
argument_list|()
init|;
operator|++
name|Next
operator|!=
name|E
condition|;
control|)
block|{
if|if
condition|(
name|pred
argument_list|(
operator|*
name|I
argument_list|)
condition|)
name|erase
argument_list|(
name|Next
argument_list|)
expr_stmt|;
else|else
name|I
operator|=
name|Next
expr_stmt|;
name|Next
operator|=
name|I
expr_stmt|;
block|}
end_for

begin_macro
unit|}   void
name|unique
argument_list|()
end_macro

begin_block
block|{
name|unique
argument_list|(
name|op_equal
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|template
operator|<
name|class
name|Pr3
operator|>
name|void
name|merge
argument_list|(
argument|iplist&right
argument_list|,
argument|Pr3 pred
argument_list|)
block|{
name|iterator
name|first1
operator|=
name|begin
argument_list|()
block|,
name|last1
operator|=
name|end
argument_list|()
block|;
name|iterator
name|first2
operator|=
name|right
operator|.
name|begin
argument_list|()
block|,
name|last2
operator|=
name|right
operator|.
name|end
argument_list|()
block|;
while|while
condition|(
name|first1
operator|!=
name|last1
operator|&&
name|first2
operator|!=
name|last2
condition|)
if|if
condition|(
name|pred
argument_list|(
operator|*
name|first2
argument_list|,
operator|*
name|first1
argument_list|)
condition|)
block|{
name|iterator
name|next
init|=
name|first2
decl_stmt|;
name|transfer
argument_list|(
name|first1
argument_list|,
name|right
argument_list|,
name|first2
argument_list|,
operator|++
name|next
argument_list|)
expr_stmt|;
name|first2
operator|=
name|next
expr_stmt|;
block|}
end_expr_stmt

begin_else
else|else
block|{
operator|++
name|first1
expr_stmt|;
block|}
end_else

begin_if
if|if
condition|(
name|first2
operator|!=
name|last2
condition|)
name|transfer
argument_list|(
name|last1
argument_list|,
name|right
argument_list|,
name|first2
argument_list|,
name|last2
argument_list|)
expr_stmt|;
end_if

begin_macro
unit|}   void
name|merge
argument_list|(
argument|iplist&right
argument_list|)
end_macro

begin_block
block|{
return|return
name|merge
argument_list|(
name|right
argument_list|,
name|op_less
argument_list|)
return|;
block|}
end_block

begin_expr_stmt
name|template
operator|<
name|class
name|Pr3
operator|>
name|void
name|sort
argument_list|(
argument|Pr3 pred
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|sort
parameter_list|()
block|{
name|sort
argument_list|(
name|op_less
argument_list|)
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
name|reverse
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|NodeTy
operator|>
expr|struct
name|ilist
operator|:
name|public
name|iplist
operator|<
name|NodeTy
operator|>
block|{
typedef|typedef
name|typename
name|iplist
operator|<
name|NodeTy
operator|>
operator|::
name|size_type
name|size_type
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|iplist
operator|<
name|NodeTy
operator|>
operator|::
name|iterator
name|iterator
expr_stmt|;
end_typedef

begin_macro
name|ilist
argument_list|()
end_macro

begin_block
block|{}
end_block

begin_macro
name|ilist
argument_list|(
argument|const ilist&right
argument_list|)
end_macro

begin_block
block|{
name|insert
argument_list|(
name|this
operator|->
name|begin
argument_list|()
argument_list|,
name|right
operator|.
name|begin
argument_list|()
argument_list|,
name|right
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_block

begin_function
name|explicit
name|ilist
parameter_list|(
name|size_type
name|count
parameter_list|)
block|{
name|insert
argument_list|(
name|this
operator|->
name|begin
argument_list|()
argument_list|,
name|count
argument_list|,
name|NodeTy
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_macro
name|ilist
argument_list|(
argument|size_type count
argument_list|,
argument|const NodeTy&val
argument_list|)
end_macro

begin_block
block|{
name|insert
argument_list|(
name|this
operator|->
name|begin
argument_list|()
argument_list|,
name|count
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|template
operator|<
name|class
name|InIt
operator|>
name|ilist
argument_list|(
argument|InIt first
argument_list|,
argument|InIt last
argument_list|)
block|{
name|insert
argument_list|(
name|this
operator|->
name|begin
argument_list|()
argument_list|,
name|first
argument_list|,
name|last
argument_list|)
block|;   }
comment|// bring hidden functions into scope
name|using
name|iplist
operator|<
name|NodeTy
operator|>
operator|::
name|insert
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|iplist
operator|<
name|NodeTy
operator|>
operator|::
name|push_front
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|iplist
operator|<
name|NodeTy
operator|>
operator|::
name|push_back
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Main implementation here - Insert for a node passed by value...
end_comment

begin_function
name|iterator
name|insert
parameter_list|(
name|iterator
name|where
parameter_list|,
specifier|const
name|NodeTy
modifier|&
name|val
parameter_list|)
block|{
return|return
name|insert
argument_list|(
name|where
argument_list|,
name|createNode
argument_list|(
name|val
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Front and back inserters...
end_comment

begin_function
name|void
name|push_front
parameter_list|(
specifier|const
name|NodeTy
modifier|&
name|val
parameter_list|)
block|{
name|insert
argument_list|(
name|this
operator|->
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
specifier|const
name|NodeTy
modifier|&
name|val
parameter_list|)
block|{
name|insert
argument_list|(
name|this
operator|->
name|end
argument_list|()
argument_list|,
name|val
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

begin_function
name|void
name|insert
parameter_list|(
name|iterator
name|where
parameter_list|,
name|size_type
name|count
parameter_list|,
specifier|const
name|NodeTy
modifier|&
name|val
parameter_list|)
block|{
for|for
control|(
init|;
name|count
operator|!=
literal|0
condition|;
operator|--
name|count
control|)
name|insert
argument_list|(
name|where
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Assign special forms...
end_comment

begin_function
name|void
name|assign
parameter_list|(
name|size_type
name|count
parameter_list|,
specifier|const
name|NodeTy
modifier|&
name|val
parameter_list|)
block|{
name|iterator
name|I
init|=
name|this
operator|->
name|begin
argument_list|()
decl_stmt|;
for|for
control|(
init|;
name|I
operator|!=
name|this
operator|->
name|end
argument_list|()
operator|&&
name|count
operator|!=
literal|0
condition|;
operator|++
name|I
operator|,
operator|--
name|count
control|)
operator|*
name|I
operator|=
name|val
expr_stmt|;
if|if
condition|(
name|count
operator|!=
literal|0
condition|)
name|insert
argument_list|(
name|this
operator|->
name|end
argument_list|()
argument_list|,
name|val
argument_list|,
name|val
argument_list|)
expr_stmt|;
else|else
name|erase
argument_list|(
name|I
argument_list|,
name|this
operator|->
name|end
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|template
operator|<
name|class
name|InIt
operator|>
name|void
name|assign
argument_list|(
argument|InIt first1
argument_list|,
argument|InIt last1
argument_list|)
block|{
name|iterator
name|first2
operator|=
name|this
operator|->
name|begin
argument_list|()
block|,
name|last2
operator|=
name|this
operator|->
name|end
argument_list|()
block|;
for|for
control|(
init|;
name|first1
operator|!=
name|last1
operator|&&
name|first2
operator|!=
name|last2
condition|;
operator|++
name|first1
operator|,
operator|++
name|first2
control|)
operator|*
name|first1
operator|=
operator|*
name|first2
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|first2
operator|==
name|last2
condition|)
name|erase
argument_list|(
name|first1
argument_list|,
name|last1
argument_list|)
expr_stmt|;
else|else
name|insert
argument_list|(
name|last1
argument_list|,
name|first2
argument_list|,
name|last2
argument_list|)
expr_stmt|;
end_if

begin_comment
unit|}
comment|// Resize members...
end_comment

begin_macro
unit|void
name|resize
argument_list|(
argument|size_type newsize
argument_list|,
argument|NodeTy val
argument_list|)
end_macro

begin_block
block|{
name|iterator
name|i
init|=
name|this
operator|->
name|begin
argument_list|()
decl_stmt|;
name|size_type
name|len
init|=
literal|0
decl_stmt|;
for|for
control|(
init|;
name|i
operator|!=
name|this
operator|->
name|end
argument_list|()
operator|&&
name|len
operator|<
name|newsize
condition|;
operator|++
name|i
operator|,
operator|++
name|len
control|)
comment|/* empty*/
empty_stmt|;
if|if
condition|(
name|len
operator|==
name|newsize
condition|)
name|erase
argument_list|(
name|i
argument_list|,
name|this
operator|->
name|end
argument_list|()
argument_list|)
expr_stmt|;
else|else
comment|// i == end()
name|insert
argument_list|(
name|this
operator|->
name|end
argument_list|()
argument_list|,
name|newsize
operator|-
name|len
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_block

begin_function
name|void
name|resize
parameter_list|(
name|size_type
name|newsize
parameter_list|)
block|{
name|resize
argument_list|(
name|newsize
argument_list|,
name|NodeTy
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
unit|};  }
comment|// End llvm namespace
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
comment|// End 'std' extensions...
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_ADT_ILIST_H
end_comment

end_unit

