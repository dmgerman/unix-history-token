begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// List implementation -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is part of the GNU ISO C++ Library.  This library is free
end_comment

begin_comment
comment|// software; you can redistribute it and/or modify it under the
end_comment

begin_comment
comment|// terms of the GNU General Public License as published by the
end_comment

begin_comment
comment|// Free Software Foundation; either version 2, or (at your option)
end_comment

begin_comment
comment|// any later version.
end_comment

begin_comment
comment|// This library is distributed in the hope that it will be useful,
end_comment

begin_comment
comment|// but WITHOUT ANY WARRANTY; without even the implied warranty of
end_comment

begin_comment
comment|// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
end_comment

begin_comment
comment|// GNU General Public License for more details.
end_comment

begin_comment
comment|// You should have received a copy of the GNU General Public License along
end_comment

begin_comment
comment|// with this library; see the file COPYING.  If not, write to the Free
end_comment

begin_comment
comment|// Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307,
end_comment

begin_comment
comment|// USA.
end_comment

begin_comment
comment|// As a special exception, you may use this file as part of a free software
end_comment

begin_comment
comment|// library without restriction.  Specifically, if other files instantiate
end_comment

begin_comment
comment|// templates or use macros or inline functions from this file, or you compile
end_comment

begin_comment
comment|// this file and link it with other files to produce an executable, this
end_comment

begin_comment
comment|// file does not by itself cause the resulting executable to be covered by
end_comment

begin_comment
comment|// the GNU General Public License.  This exception does not however
end_comment

begin_comment
comment|// invalidate any other reasons why the executable file might be covered by
end_comment

begin_comment
comment|// the GNU General Public License.
end_comment

begin_comment
comment|/*  *  * Copyright (c) 1994  * Hewlett-Packard Company  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Hewlett-Packard Company makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  *  *  * Copyright (c) 1996,1997  * Silicon Graphics Computer Systems, Inc.  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Silicon Graphics makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  */
end_comment

begin_comment
comment|/** @file stl_list.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIST_H
end_ifndef

begin_define
define|#
directive|define
name|_LIST_H
value|1
end_define

begin_include
include|#
directive|include
file|<bits/concept_check.h>
end_include

begin_decl_stmt
name|namespace
name|_GLIBCXX_STD
block|{
comment|// Supporting structures are split into common and templated types; the
comment|// latter publicly inherits from the former in an effort to reduce code
comment|// duplication.  This results in some "needless" static_cast'ing later on,
comment|// but it's all safe downcasting.
comment|/// @if maint Common part of a node in the %list.  @endif
struct|struct
name|_List_node_base
block|{
name|_List_node_base
modifier|*
name|_M_next
decl_stmt|;
comment|///< Self-explanatory
name|_List_node_base
modifier|*
name|_M_prev
decl_stmt|;
comment|///< Self-explanatory
specifier|static
name|void
name|swap
parameter_list|(
name|_List_node_base
modifier|&
name|__x
parameter_list|,
name|_List_node_base
modifier|&
name|__y
parameter_list|)
function_decl|;
name|void
name|transfer
parameter_list|(
name|_List_node_base
modifier|*
specifier|const
name|__first
parameter_list|,
name|_List_node_base
modifier|*
specifier|const
name|__last
parameter_list|)
function_decl|;
name|void
name|reverse
parameter_list|()
function_decl|;
name|void
name|hook
parameter_list|(
name|_List_node_base
modifier|*
specifier|const
name|__position
parameter_list|)
function_decl|;
name|void
name|unhook
parameter_list|()
function_decl|;
block|}
struct|;
comment|/// @if maint An actual node in the %list.  @endif
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|_List_node
operator|:
name|public
name|_List_node_base
block|{
name|_Tp
name|_M_data
block|;
comment|///< User's data.
block|}
expr_stmt|;
comment|/**    *  @brief A list::iterator.    *    *  @if maint    *  All the functions are op overloads.    *  @endif   */
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|_List_iterator
block|{
typedef|typedef
name|_List_iterator
operator|<
name|_Tp
operator|>
name|_Self
expr_stmt|;
typedef|typedef
name|_List_node
operator|<
name|_Tp
operator|>
name|_Node
expr_stmt|;
typedef|typedef
name|ptrdiff_t
name|difference_type
typedef|;
typedef|typedef
name|bidirectional_iterator_tag
name|iterator_category
typedef|;
typedef|typedef
name|_Tp
name|value_type
typedef|;
typedef|typedef
name|_Tp
modifier|*
name|pointer
typedef|;
typedef|typedef
name|_Tp
modifier|&
name|reference
typedef|;
name|_List_iterator
argument_list|()
operator|:
name|_M_node
argument_list|()
block|{ }
name|_List_iterator
argument_list|(
name|_List_node_base
operator|*
name|__x
argument_list|)
operator|:
name|_M_node
argument_list|(
argument|__x
argument_list|)
block|{ }
comment|// Must downcast from List_node_base to _List_node to get to _M_data.
name|reference
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|static_cast
operator|<
name|_Node
operator|*
operator|>
operator|(
name|_M_node
operator|)
operator|->
name|_M_data
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
name|static_cast
operator|<
name|_Node
operator|*
operator|>
operator|(
name|_M_node
operator|)
operator|->
name|_M_data
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|_Self
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
name|_M_node
operator|=
name|_M_node
operator|->
name|_M_next
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|_Self
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|_Self
name|__tmp
operator|=
operator|*
name|this
block|;
name|_M_node
operator|=
name|_M_node
operator|->
name|_M_next
block|;
return|return
name|__tmp
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|_Self
operator|&
name|operator
operator|--
operator|(
operator|)
block|{
name|_M_node
operator|=
name|_M_node
operator|->
name|_M_prev
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|_Self
name|operator
operator|--
operator|(
name|int
operator|)
block|{
name|_Self
name|__tmp
operator|=
operator|*
name|this
block|;
name|_M_node
operator|=
name|_M_node
operator|->
name|_M_prev
block|;
return|return
name|__tmp
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|_Self
operator|&
name|__x
operator|)
specifier|const
block|{
return|return
name|_M_node
operator|==
name|__x
operator|.
name|_M_node
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|_Self
operator|&
name|__x
operator|)
specifier|const
block|{
return|return
name|_M_node
operator|!=
name|__x
operator|.
name|_M_node
return|;
block|}
end_expr_stmt

begin_comment
comment|// The only member points to the %list element.
end_comment

begin_decl_stmt
name|_List_node_base
modifier|*
name|_M_node
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/**    *  @brief A list::const_iterator.    *    *  @if maint    *  All the functions are op overloads.    *  @endif   */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|_List_const_iterator
block|{
typedef|typedef
name|_List_const_iterator
operator|<
name|_Tp
operator|>
name|_Self
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
specifier|const
name|_List_node
operator|<
name|_Tp
operator|>
name|_Node
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|_List_iterator
operator|<
name|_Tp
operator|>
name|iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|ptrdiff_t
name|difference_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|bidirectional_iterator_tag
name|iterator_category
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Tp
name|value_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|_Tp
modifier|*
name|pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|_Tp
modifier|&
name|reference
typedef|;
end_typedef

begin_expr_stmt
name|_List_const_iterator
argument_list|()
operator|:
name|_M_node
argument_list|()
block|{ }
name|_List_const_iterator
argument_list|(
specifier|const
name|_List_node_base
operator|*
name|__x
argument_list|)
operator|:
name|_M_node
argument_list|(
argument|__x
argument_list|)
block|{ }
name|_List_const_iterator
argument_list|(
specifier|const
name|iterator
operator|&
name|__x
argument_list|)
operator|:
name|_M_node
argument_list|(
argument|__x._M_node
argument_list|)
block|{ }
comment|// Must downcast from List_node_base to _List_node to get to
comment|// _M_data.
name|reference
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|static_cast
operator|<
name|_Node
operator|*
operator|>
operator|(
name|_M_node
operator|)
operator|->
name|_M_data
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|pointer
name|operator
operator|->
expr|(
end_expr_stmt

begin_expr_stmt
unit|)
specifier|const
block|{
return|return
operator|&
name|static_cast
operator|<
name|_Node
operator|*
operator|>
operator|(
name|_M_node
operator|)
operator|->
name|_M_data
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|_Self
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
name|_M_node
operator|=
name|_M_node
operator|->
name|_M_next
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|_Self
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|_Self
name|__tmp
operator|=
operator|*
name|this
block|;
name|_M_node
operator|=
name|_M_node
operator|->
name|_M_next
block|;
return|return
name|__tmp
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|_Self
operator|&
name|operator
operator|--
operator|(
operator|)
block|{
name|_M_node
operator|=
name|_M_node
operator|->
name|_M_prev
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|_Self
name|operator
operator|--
operator|(
name|int
operator|)
block|{
name|_Self
name|__tmp
operator|=
operator|*
name|this
block|;
name|_M_node
operator|=
name|_M_node
operator|->
name|_M_prev
block|;
return|return
name|__tmp
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|_Self
operator|&
name|__x
operator|)
specifier|const
block|{
return|return
name|_M_node
operator|==
name|__x
operator|.
name|_M_node
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|_Self
operator|&
name|__x
operator|)
specifier|const
block|{
return|return
name|_M_node
operator|!=
name|__x
operator|.
name|_M_node
return|;
block|}
end_expr_stmt

begin_comment
comment|// The only member points to the %list element.
end_comment

begin_decl_stmt
specifier|const
name|_List_node_base
modifier|*
name|_M_node
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_Val
operator|>
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|_List_iterator
operator|<
name|_Val
operator|>
operator|&
name|__x
operator|,
specifier|const
name|_List_const_iterator
operator|<
name|_Val
operator|>
operator|&
name|__y
operator|)
block|{
return|return
name|__x
operator|.
name|_M_node
operator|==
name|__y
operator|.
name|_M_node
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_Val
operator|>
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|_List_iterator
operator|<
name|_Val
operator|>
operator|&
name|__x
operator|,
specifier|const
name|_List_const_iterator
operator|<
name|_Val
operator|>
operator|&
name|__y
operator|)
block|{
return|return
name|__x
operator|.
name|_M_node
operator|!=
name|__y
operator|.
name|_M_node
return|;
block|}
end_expr_stmt

begin_comment
comment|/**    *  @if maint    *  See bits/stl_deque.h's _Deque_base for an explanation.    *  @endif   */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|,
name|typename
name|_Alloc
operator|>
name|class
name|_List_base
block|{
name|protected
operator|:
comment|// NOTA BENE
comment|// The stored instance is not actually of "allocator_type"'s
comment|// type.  Instead we rebind the type to
comment|// Allocator<List_node<Tp>>, which according to [20.1.5]/4
comment|// should probably be the same.  List_node<Tp> is not the same
comment|// size as Tp (it's two pointers larger), and specializations on
comment|// Tp may go unused because List_node<Tp> is being bound
comment|// instead.
comment|//
comment|// We put this to the test in the constructors and in
comment|// get_allocator, where we use conversions between
comment|// allocator_type and _Node_Alloc_type. The conversion is
comment|// required by table 32 in [20.1.5].
typedef|typedef
name|typename
name|_Alloc
operator|::
name|template
name|rebind
operator|<
name|_List_node
operator|<
name|_Tp
operator|>
expr|>
operator|::
name|other
name|_Node_Alloc_type
expr_stmt|;
block|struct
name|_List_impl
operator|:
name|public
name|_Node_Alloc_type
block|{
name|_List_node_base
name|_M_node
block|;
name|_List_impl
argument_list|(
specifier|const
name|_Node_Alloc_type
operator|&
name|__a
argument_list|)
operator|:
name|_Node_Alloc_type
argument_list|(
argument|__a
argument_list|)
block|{ }
block|}
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|_List_impl
name|_M_impl
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|_List_node
operator|<
name|_Tp
operator|>
operator|*
name|_M_get_node
argument_list|()
block|{
return|return
name|_M_impl
operator|.
name|_Node_Alloc_type
operator|::
name|allocate
argument_list|(
literal|1
argument_list|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|_M_put_node
argument_list|(
name|_List_node
operator|<
name|_Tp
operator|>
operator|*
name|__p
argument_list|)
block|{
name|_M_impl
operator|.
name|_Node_Alloc_type
operator|::
name|deallocate
argument_list|(
name|__p
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_typedef
typedef|typedef
name|_Alloc
name|allocator_type
typedef|;
end_typedef

begin_expr_stmt
name|allocator_type
name|get_allocator
argument_list|()
specifier|const
block|{
return|return
name|allocator_type
argument_list|(
operator|*
name|static_cast
operator|<
specifier|const
name|_Node_Alloc_type
operator|*
operator|>
operator|(
operator|&
name|this
operator|->
name|_M_impl
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|_List_base
argument_list|(
specifier|const
name|allocator_type
operator|&
name|__a
argument_list|)
operator|:
name|_M_impl
argument_list|(
argument|__a
argument_list|)
block|{
name|_M_init
argument_list|()
block|; }
comment|// This is what actually destroys the list.
operator|~
name|_List_base
argument_list|()
block|{
name|_M_clear
argument_list|()
block|; }
name|void
name|_M_clear
argument_list|()
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|_M_init
parameter_list|()
block|{
name|this
operator|->
name|_M_impl
operator|.
name|_M_node
operator|.
name|_M_next
operator|=
operator|&
name|this
operator|->
name|_M_impl
operator|.
name|_M_node
expr_stmt|;
name|this
operator|->
name|_M_impl
operator|.
name|_M_node
operator|.
name|_M_prev
operator|=
operator|&
name|this
operator|->
name|_M_impl
operator|.
name|_M_node
expr_stmt|;
block|}
end_function

begin_comment
unit|};
comment|/**    *  @brief A standard container with linear time access to elements,    *  and fixed time insertion/deletion at any point in the sequence.    *    *  @ingroup Containers    *  @ingroup Sequences    *    *  Meets the requirements of a<a href="tables.html#65">container</a>, a    *<a href="tables.html#66">reversible container</a>, and a    *<a href="tables.html#67">sequence</a>, including the    *<a href="tables.html#68">optional sequence requirements</a> with the    *  %exception of @c at and @c operator[].    *    *  This is a @e doubly @e linked %list.  Traversal up and down the    *  %list requires linear time, but adding and removing elements (or    *  @e nodes) is done in constant time, regardless of where the    *  change takes place.  Unlike std::vector and std::deque,    *  random-access iterators are not provided, so subscripting ( @c    *  [] ) access is not allowed.  For algorithms which only need    *  sequential access, this lack makes no difference.    *    *  Also unlike the other standard containers, std::list provides    *  specialized algorithms %unique to linked lists, such as    *  splicing, sorting, and in-place reversal.    *    *  @if maint    *  A couple points on memory allocation for list<Tp>:    *    *  First, we never actually allocate a Tp, we allocate    *  List_node<Tp>'s and trust [20.1.5]/4 to DTRT.  This is to ensure    *  that after elements from %list<X,Alloc1> are spliced into    *  %list<X,Alloc2>, destroying the memory of the second %list is a    *  valid operation, i.e., Alloc1 giveth and Alloc2 taketh away.    *    *  Second, a %list conceptually represented as    *  @code    *    A<---> B<---> C<---> D    *  @endcode    *  is actually circular; a link exists between A and D.  The %list    *  class holds (as its only data member) a private list::iterator    *  pointing to @e D, not to @e A!  To get to the head of the %list,    *  we start at the tail and move forward by one.  When this member    *  iterator's next/previous pointers refer to itself, the %list is    *  %empty.  @endif   */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|,
name|typename
name|_Alloc
operator|=
name|allocator
operator|<
name|_Tp
operator|>
expr|>
name|class
name|list
operator|:
name|protected
name|_List_base
operator|<
name|_Tp
operator|,
name|_Alloc
operator|>
block|{
comment|// concept requirements
name|__glibcxx_class_requires
argument_list|(
argument|_Tp
argument_list|,
argument|_SGIAssignableConcept
argument_list|)
typedef|typedef
name|_List_base
operator|<
name|_Tp
operator|,
name|_Alloc
operator|>
name|_Base
expr_stmt|;
name|public
operator|:
end_expr_stmt

begin_typedef
typedef|typedef
name|_Tp
name|value_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|_Alloc
operator|::
name|pointer
name|pointer
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|_Alloc
operator|::
name|const_pointer
name|const_pointer
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|_Alloc
operator|::
name|reference
name|reference
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|_Alloc
operator|::
name|const_reference
name|const_reference
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|_List_iterator
operator|<
name|_Tp
operator|>
name|iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|_List_const_iterator
operator|<
name|_Tp
operator|>
name|const_iterator
expr_stmt|;
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
name|typename
name|_Base
operator|::
name|allocator_type
name|allocator_type
expr_stmt|;
end_typedef

begin_label
name|protected
label|:
end_label

begin_comment
comment|// Note that pointers-to-_Node's can be ctor-converted to
end_comment

begin_comment
comment|// iterator types.
end_comment

begin_typedef
typedef|typedef
name|_List_node
operator|<
name|_Tp
operator|>
name|_Node
expr_stmt|;
end_typedef

begin_comment
comment|/** @if maint        *  One data member plus two memory-handling functions.  If the        *  _Alloc type requires separate instances, then one of those        *  will also be included, accumulated from the topmost parent.        *  @endif        */
end_comment

begin_expr_stmt
name|using
name|_Base
operator|::
name|_M_impl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|_Base
operator|::
name|_M_put_node
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|_Base
operator|::
name|_M_get_node
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**        *  @if maint        *  @param  x  An instance of user data.        *        *  Allocates space for a new node and constructs a copy of @a x in it.        *  @endif        */
end_comment

begin_function
name|_Node
modifier|*
name|_M_create_node
parameter_list|(
specifier|const
name|value_type
modifier|&
name|__x
parameter_list|)
block|{
name|_Node
modifier|*
name|__p
init|=
name|this
operator|->
name|_M_get_node
argument_list|()
decl_stmt|;
name|try
block|{
name|std
operator|::
name|_Construct
argument_list|(
operator|&
name|__p
operator|->
name|_M_data
argument_list|,
name|__x
argument_list|)
expr_stmt|;
block|}
name|catch
argument_list|(
argument|...
argument_list|)
block|{
name|_M_put_node
argument_list|(
name|__p
argument_list|)
expr_stmt|;
name|__throw_exception_again
expr_stmt|;
block|}
return|return
name|__p
return|;
block|}
end_function

begin_comment
comment|/**        *  @if maint        *  Allocates space for a new node and default-constructs a new        *  instance of @c value_type in it.        *  @endif        */
end_comment

begin_function
name|_Node
modifier|*
name|_M_create_node
parameter_list|()
block|{
name|_Node
modifier|*
name|__p
init|=
name|this
operator|->
name|_M_get_node
argument_list|()
decl_stmt|;
name|try
block|{
name|std
operator|::
name|_Construct
argument_list|(
operator|&
name|__p
operator|->
name|_M_data
argument_list|)
expr_stmt|;
block|}
name|catch
argument_list|(
argument|...
argument_list|)
block|{
name|_M_put_node
argument_list|(
name|__p
argument_list|)
expr_stmt|;
name|__throw_exception_again
expr_stmt|;
block|}
return|return
name|__p
return|;
block|}
end_function

begin_label
name|public
label|:
end_label

begin_comment
comment|// [23.2.2.1] construct/copy/destroy
end_comment

begin_comment
comment|// (assign() and get_allocator() are also listed in this section)
end_comment

begin_comment
comment|/**        *  @brief  Default constructor creates no elements.        */
end_comment

begin_macro
name|explicit
end_macro

begin_expr_stmt
name|list
argument_list|(
specifier|const
name|allocator_type
operator|&
name|__a
operator|=
name|allocator_type
argument_list|()
argument_list|)
operator|:
name|_Base
argument_list|(
argument|__a
argument_list|)
block|{ }
comment|/**        *  @brief  Create a %list with copies of an exemplar element.        *  @param  n  The number of elements to initially create.        *  @param  value  An element to copy.        *        *  This constructor fills the %list with @a n copies of @a value.        */
name|list
argument_list|(
argument|size_type __n
argument_list|,
argument|const value_type& __value
argument_list|,
argument|const allocator_type& __a = allocator_type()
argument_list|)
operator|:
name|_Base
argument_list|(
argument|__a
argument_list|)
block|{
name|this
operator|->
name|insert
argument_list|(
name|begin
argument_list|()
argument_list|,
name|__n
argument_list|,
name|__value
argument_list|)
block|; }
comment|/**        *  @brief  Create a %list with default elements.        *  @param  n  The number of elements to initially create.        *        *  This constructor fills the %list with @a n copies of a        *  default-constructed element.        */
name|explicit
name|list
argument_list|(
argument|size_type __n
argument_list|)
operator|:
name|_Base
argument_list|(
argument|allocator_type()
argument_list|)
block|{
name|this
operator|->
name|insert
argument_list|(
name|begin
argument_list|()
argument_list|,
name|__n
argument_list|,
name|value_type
argument_list|()
argument_list|)
block|; }
comment|/**        *  @brief  %List copy constructor.        *  @param  x  A %list of identical element and allocator types.        *        *  The newly-created %list uses a copy of the allocation object used        *  by @a x.        */
name|list
argument_list|(
specifier|const
name|list
operator|&
name|__x
argument_list|)
operator|:
name|_Base
argument_list|(
argument|__x.get_allocator()
argument_list|)
block|{
name|this
operator|->
name|insert
argument_list|(
name|begin
argument_list|()
argument_list|,
name|__x
operator|.
name|begin
argument_list|()
argument_list|,
name|__x
operator|.
name|end
argument_list|()
argument_list|)
block|; }
comment|/**        *  @brief  Builds a %list from a range.        *  @param  first  An input iterator.        *  @param  last  An input iterator.        *        *  Create a %list consisting of copies of the elements from        *  [@a first,@a last).  This is linear in N (where N is        *  distance(@a first,@a last)).        *        *  @if maint        *  We don't need any dispatching tricks here, because insert does all of        *  that anyway.        *  @endif        */
name|template
operator|<
name|typename
name|_InputIterator
operator|>
name|list
argument_list|(
argument|_InputIterator __first
argument_list|,
argument|_InputIterator __last
argument_list|,
argument|const allocator_type& __a = allocator_type()
argument_list|)
operator|:
name|_Base
argument_list|(
argument|__a
argument_list|)
block|{
name|this
operator|->
name|insert
argument_list|(
name|begin
argument_list|()
argument_list|,
name|__first
argument_list|,
name|__last
argument_list|)
block|; }
comment|/**        *  No explicit dtor needed as the _Base dtor takes care of        *  things.  The _Base dtor only erases the elements, and note        *  that if the elements themselves are pointers, the pointed-to        *  memory is not touched in any way.  Managing the pointer is        *  the user's responsibilty.        */
comment|/**        *  @brief  %List assignment operator.        *  @param  x  A %list of identical element and allocator types.        *        *  All the elements of @a x are copied, but unlike the copy        *  constructor, the allocator object is not copied.        */
name|list
operator|&
name|operator
operator|=
operator|(
specifier|const
name|list
operator|&
name|__x
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**        *  @brief  Assigns a given value to a %list.        *  @param  n  Number of elements to be assigned.        *  @param  val  Value to be assigned.        *        *  This function fills a %list with @a n copies of the given        *  value.  Note that the assignment completely changes the %list        *  and that the resulting %list's size is the same as the number        *  of elements assigned.  Old data may be lost.        */
end_comment

begin_function
name|void
name|assign
parameter_list|(
name|size_type
name|__n
parameter_list|,
specifier|const
name|value_type
modifier|&
name|__val
parameter_list|)
block|{
name|_M_fill_assign
argument_list|(
name|__n
argument_list|,
name|__val
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**        *  @brief  Assigns a range to a %list.        *  @param  first  An input iterator.        *  @param  last   An input iterator.        *        *  This function fills a %list with copies of the elements in the        *  range [@a first,@a last).        *        *  Note that the assignment completely changes the %list and        *  that the resulting %list's size is the same as the number of        *  elements assigned.  Old data may be lost.        */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_InputIterator
operator|>
name|void
name|assign
argument_list|(
argument|_InputIterator __first
argument_list|,
argument|_InputIterator __last
argument_list|)
block|{
comment|// Check whether it's an integral type.  If so, it's not an iterator.
typedef|typedef
name|typename
name|_Is_integer
operator|<
name|_InputIterator
operator|>
operator|::
name|_Integral
name|_Integral
expr_stmt|;
name|_M_assign_dispatch
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|_Integral
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|/// Get a copy of the memory allocation object.
end_comment

begin_macro
unit|allocator_type
name|get_allocator
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
return|return
name|_Base
operator|::
name|get_allocator
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|// iterators
end_comment

begin_comment
comment|/**        *  Returns a read/write iterator that points to the first element in the        *  %list.  Iteration is done in ordinary element order.        */
end_comment

begin_function
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|this
operator|->
name|_M_impl
operator|.
name|_M_node
operator|.
name|_M_next
return|;
block|}
end_function

begin_comment
comment|/**        *  Returns a read-only (constant) iterator that points to the        *  first element in the %list.  Iteration is done in ordinary        *  element order.        */
end_comment

begin_expr_stmt
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|_M_impl
operator|.
name|_M_node
operator|.
name|_M_next
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  Returns a read/write iterator that points one past the last        *  element in the %list.  Iteration is done in ordinary element        *  order.        */
end_comment

begin_function
name|iterator
name|end
parameter_list|()
block|{
return|return
operator|&
name|this
operator|->
name|_M_impl
operator|.
name|_M_node
return|;
block|}
end_function

begin_comment
comment|/**        *  Returns a read-only (constant) iterator that points one past        *  the last element in the %list.  Iteration is done in ordinary        *  element order.        */
end_comment

begin_expr_stmt
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
operator|&
name|this
operator|->
name|_M_impl
operator|.
name|_M_node
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  Returns a read/write reverse iterator that points to the last        *  element in the %list.  Iteration is done in reverse element        *  order.        */
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

begin_comment
comment|/**        *  Returns a read-only (constant) reverse iterator that points to        *  the last element in the %list.  Iteration is done in reverse        *  element order.        */
end_comment

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

begin_comment
comment|/**        *  Returns a read/write reverse iterator that points to one        *  before the first element in the %list.  Iteration is done in        *  reverse element order.        */
end_comment

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

begin_comment
comment|/**        *  Returns a read-only (constant) reverse iterator that points to one        *  before the first element in the %list.  Iteration is done in reverse        *  element order.        */
end_comment

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
comment|// [23.2.2.2] capacity
end_comment

begin_comment
comment|/**        *  Returns true if the %list is empty.  (Thus begin() would equal        *  end().)        */
end_comment

begin_expr_stmt
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|_M_impl
operator|.
name|_M_node
operator|.
name|_M_next
operator|==
operator|&
name|this
operator|->
name|_M_impl
operator|.
name|_M_node
return|;
block|}
end_expr_stmt

begin_comment
comment|/**  Returns the number of elements in the %list.  */
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/**  Returns the size() of the largest possible %list.  */
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

begin_comment
comment|/**        *  @brief Resizes the %list to the specified number of elements.        *  @param new_size Number of elements the %list should contain.        *  @param x Data with which new elements should be populated.        *        *  This function will %resize the %list to the specified number        *  of elements.  If the number is smaller than the %list's        *  current size the %list is truncated, otherwise the %list is        *  extended and new elements are populated with given data.        */
end_comment

begin_function_decl
name|void
name|resize
parameter_list|(
name|size_type
name|__new_size
parameter_list|,
specifier|const
name|value_type
modifier|&
name|__x
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**        *  @brief  Resizes the %list to the specified number of elements.        *  @param  new_size  Number of elements the %list should contain.        *        *  This function will resize the %list to the specified number of        *  elements.  If the number is smaller than the %list's current        *  size the %list is truncated, otherwise the %list is extended        *  and new elements are default-constructed.        */
end_comment

begin_function
name|void
name|resize
parameter_list|(
name|size_type
name|__new_size
parameter_list|)
block|{
name|this
operator|->
name|resize
argument_list|(
name|__new_size
argument_list|,
name|value_type
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// element access
end_comment

begin_comment
comment|/**        *  Returns a read/write reference to the data at the first        *  element of the %list.        */
end_comment

begin_function
name|reference
name|front
parameter_list|()
block|{
return|return
operator|*
name|begin
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/**        *  Returns a read-only (constant) reference to the data at the first        *  element of the %list.        */
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/**        *  Returns a read/write reference to the data at the last element        *  of the %list.        */
end_comment

begin_function
name|reference
name|back
parameter_list|()
block|{
return|return
operator|*
operator|(
operator|--
name|end
argument_list|()
operator|)
return|;
block|}
end_function

begin_comment
comment|/**        *  Returns a read-only (constant) reference to the data at the last        *  element of the %list.        */
end_comment

begin_expr_stmt
name|const_reference
name|back
argument_list|()
specifier|const
block|{
return|return
operator|*
operator|(
operator|--
name|end
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// [23.2.2.3] modifiers
end_comment

begin_comment
comment|/**        *  @brief  Add data to the front of the %list.        *  @param  x  Data to be added.        *        *  This is a typical stack operation.  The function creates an        *  element at the front of the %list and assigns the given data        *  to it.  Due to the nature of a %list this operation can be        *  done in constant time, and does not invalidate iterators and        *  references.        */
end_comment

begin_function
name|void
name|push_front
parameter_list|(
specifier|const
name|value_type
modifier|&
name|__x
parameter_list|)
block|{
name|this
operator|->
name|_M_insert
argument_list|(
name|begin
argument_list|()
argument_list|,
name|__x
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**        *  @brief  Removes first element.        *        *  This is a typical stack operation.  It shrinks the %list by        *  one.  Due to the nature of a %list this operation can be done        *  in constant time, and only invalidates iterators/references to        *  the element being removed.        *        *  Note that no data is returned, and if the first element's data        *  is needed, it should be retrieved before pop_front() is        *  called.        */
end_comment

begin_function
name|void
name|pop_front
parameter_list|()
block|{
name|this
operator|->
name|_M_erase
argument_list|(
name|begin
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**        *  @brief  Add data to the end of the %list.        *  @param  x  Data to be added.        *        *  This is a typical stack operation.  The function creates an        *  element at the end of the %list and assigns the given data to        *  it.  Due to the nature of a %list this operation can be done        *  in constant time, and does not invalidate iterators and        *  references.        */
end_comment

begin_function
name|void
name|push_back
parameter_list|(
specifier|const
name|value_type
modifier|&
name|__x
parameter_list|)
block|{
name|this
operator|->
name|_M_insert
argument_list|(
name|end
argument_list|()
argument_list|,
name|__x
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**        *  @brief  Removes last element.        *        *  This is a typical stack operation.  It shrinks the %list by        *  one.  Due to the nature of a %list this operation can be done        *  in constant time, and only invalidates iterators/references to        *  the element being removed.        *        *  Note that no data is returned, and if the last element's data        *  is needed, it should be retrieved before pop_back() is called.        */
end_comment

begin_function
name|void
name|pop_back
parameter_list|()
block|{
name|this
operator|->
name|_M_erase
argument_list|(
name|this
operator|->
name|_M_impl
operator|.
name|_M_node
operator|.
name|_M_prev
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**        *  @brief  Inserts given value into %list before specified iterator.        *  @param  position  An iterator into the %list.        *  @param  x  Data to be inserted.        *  @return  An iterator that points to the inserted data.        *        *  This function will insert a copy of the given value before        *  the specified location.  Due to the nature of a %list this        *  operation can be done in constant time, and does not        *  invalidate iterators and references.        */
end_comment

begin_function_decl
name|iterator
name|insert
parameter_list|(
name|iterator
name|__position
parameter_list|,
specifier|const
name|value_type
modifier|&
name|__x
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**        *  @brief  Inserts a number of copies of given data into the %list.        *  @param  position  An iterator into the %list.        *  @param  n  Number of elements to be inserted.        *  @param  x  Data to be inserted.        *        *  This function will insert a specified number of copies of the        *  given data before the location specified by @a position.        *        *  Due to the nature of a %list this operation can be done in        *  constant time, and does not invalidate iterators and        *  references.        */
end_comment

begin_function
name|void
name|insert
parameter_list|(
name|iterator
name|__position
parameter_list|,
name|size_type
name|__n
parameter_list|,
specifier|const
name|value_type
modifier|&
name|__x
parameter_list|)
block|{
name|_M_fill_insert
argument_list|(
name|__position
argument_list|,
name|__n
argument_list|,
name|__x
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**        *  @brief  Inserts a range into the %list.        *  @param  position  An iterator into the %list.        *  @param  first  An input iterator.        *  @param  last   An input iterator.        *        *  This function will insert copies of the data in the range [@a        *  first,@a last) into the %list before the location specified by        *  @a position.        *        *  Due to the nature of a %list this operation can be done in        *  constant time, and does not invalidate iterators and        *  references.        */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_InputIterator
operator|>
name|void
name|insert
argument_list|(
argument|iterator __position
argument_list|,
argument|_InputIterator __first
argument_list|,
argument|_InputIterator __last
argument_list|)
block|{
comment|// Check whether it's an integral type.  If so, it's not an iterator.
typedef|typedef
name|typename
name|_Is_integer
operator|<
name|_InputIterator
operator|>
operator|::
name|_Integral
name|_Integral
expr_stmt|;
name|_M_insert_dispatch
argument_list|(
name|__position
argument_list|,
name|__first
argument_list|,
name|__last
argument_list|,
name|_Integral
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|/**        *  @brief  Remove element at given position.        *  @param  position  Iterator pointing to element to be erased.        *  @return  An iterator pointing to the next element (or end()).        *        *  This function will erase the element at the given position and thus        *  shorten the %list by one.        *        *  Due to the nature of a %list this operation can be done in        *  constant time, and only invalidates iterators/references to        *  the element being removed.  The user is also cautioned that        *  this function only erases the element, and that if the element        *  is itself a pointer, the pointed-to memory is not touched in        *  any way.  Managing the pointer is the user's responsibilty.        */
end_comment

begin_macro
unit|iterator
name|erase
argument_list|(
argument|iterator __position
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**        *  @brief  Remove a range of elements.        *  @param  first  Iterator pointing to the first element to be erased.        *  @param  last  Iterator pointing to one past the last element to be        *                erased.        *  @return  An iterator pointing to the element pointed to by @a last        *           prior to erasing (or end()).        *        *  This function will erase the elements in the range @a        *  [first,last) and shorten the %list accordingly.        *        *  Due to the nature of a %list this operation can be done in        *  constant time, and only invalidates iterators/references to        *  the element being removed.  The user is also cautioned that        *  this function only erases the elements, and that if the        *  elements themselves are pointers, the pointed-to memory is not        *  touched in any way.  Managing the pointer is the user's        *  responsibilty.        */
end_comment

begin_function
name|iterator
name|erase
parameter_list|(
name|iterator
name|__first
parameter_list|,
name|iterator
name|__last
parameter_list|)
block|{
while|while
condition|(
name|__first
operator|!=
name|__last
condition|)
name|__first
operator|=
name|erase
argument_list|(
name|__first
argument_list|)
expr_stmt|;
return|return
name|__last
return|;
block|}
end_function

begin_comment
comment|/**        *  @brief  Swaps data with another %list.        *  @param  x  A %list of the same element and allocator types.        *        *  This exchanges the elements between two lists in constant        *  time.  Note that the global std::swap() function is        *  specialized such that std::swap(l1,l2) will feed to this        *  function.        */
end_comment

begin_function
name|void
name|swap
parameter_list|(
name|list
modifier|&
name|__x
parameter_list|)
block|{
name|_List_node_base
operator|::
name|swap
argument_list|(
name|this
operator|->
name|_M_impl
operator|.
name|_M_node
argument_list|,
name|__x
operator|.
name|_M_impl
operator|.
name|_M_node
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**        *  Erases all the elements.  Note that this function only erases        *  the elements, and that if the elements themselves are        *  pointers, the pointed-to memory is not touched in any way.        *  Managing the pointer is the user's responsibilty.        */
end_comment

begin_function
name|void
name|clear
parameter_list|()
block|{
name|_Base
operator|::
name|_M_clear
argument_list|()
expr_stmt|;
name|_Base
operator|::
name|_M_init
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// [23.2.2.4] list operations
end_comment

begin_comment
comment|/**        *  @brief  Insert contents of another %list.        *  @param  position  Iterator referencing the element to insert before.        *  @param  x  Source list.        *        *  The elements of @a x are inserted in constant time in front of        *  the element referenced by @a position.  @a x becomes an empty        *  list.        */
end_comment

begin_function
name|void
name|splice
parameter_list|(
name|iterator
name|__position
parameter_list|,
name|list
modifier|&
name|__x
parameter_list|)
block|{
if|if
condition|(
operator|!
name|__x
operator|.
name|empty
argument_list|()
condition|)
name|this
operator|->
name|_M_transfer
argument_list|(
name|__position
argument_list|,
name|__x
operator|.
name|begin
argument_list|()
argument_list|,
name|__x
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**        *  @brief  Insert element from another %list.        *  @param  position  Iterator referencing the element to insert before.        *  @param  x  Source list.        *  @param  i  Iterator referencing the element to move.        *        *  Removes the element in list @a x referenced by @a i and        *  inserts it into the current list before @a position.        */
end_comment

begin_function
name|void
name|splice
parameter_list|(
name|iterator
name|__position
parameter_list|,
name|list
modifier|&
parameter_list|,
name|iterator
name|__i
parameter_list|)
block|{
name|iterator
name|__j
init|=
name|__i
decl_stmt|;
operator|++
name|__j
expr_stmt|;
if|if
condition|(
name|__position
operator|==
name|__i
operator|||
name|__position
operator|==
name|__j
condition|)
return|return;
name|this
operator|->
name|_M_transfer
argument_list|(
name|__position
argument_list|,
name|__i
argument_list|,
name|__j
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**        *  @brief  Insert range from another %list.        *  @param  position  Iterator referencing the element to insert before.        *  @param  x  Source list.        *  @param  first  Iterator referencing the start of range in x.        *  @param  last  Iterator referencing the end of range in x.        *        *  Removes elements in the range [first,last) and inserts them        *  before @a position in constant time.        *        *  Undefined if @a position is in [first,last).        */
end_comment

begin_function
name|void
name|splice
parameter_list|(
name|iterator
name|__position
parameter_list|,
name|list
modifier|&
parameter_list|,
name|iterator
name|__first
parameter_list|,
name|iterator
name|__last
parameter_list|)
block|{
if|if
condition|(
name|__first
operator|!=
name|__last
condition|)
name|this
operator|->
name|_M_transfer
argument_list|(
name|__position
argument_list|,
name|__first
argument_list|,
name|__last
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**        *  @brief  Remove all elements equal to value.        *  @param  value  The value to remove.        *        *  Removes every element in the list equal to @a value.        *  Remaining elements stay in list order.  Note that this        *  function only erases the elements, and that if the elements        *  themselves are pointers, the pointed-to memory is not        *  touched in any way.  Managing the pointer is the user's        *  responsibilty.        */
end_comment

begin_function_decl
name|void
name|remove
parameter_list|(
specifier|const
name|_Tp
modifier|&
name|__value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**        *  @brief  Remove all elements satisfying a predicate.        *  @param  Predicate  Unary predicate function or object.        *        *  Removes every element in the list for which the predicate        *  returns true.  Remaining elements stay in list order.  Note        *  that this function only erases the elements, and that if the        *  elements themselves are pointers, the pointed-to memory is        *  not touched in any way.  Managing the pointer is the user's        *  responsibilty.        */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Predicate
operator|>
name|void
name|remove_if
argument_list|(
name|_Predicate
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**        *  @brief  Remove consecutive duplicate elements.        *        *  For each consecutive set of elements with the same value,        *  remove all but the first one.  Remaining elements stay in        *  list order.  Note that this function only erases the        *  elements, and that if the elements themselves are pointers,        *  the pointed-to memory is not touched in any way.  Managing        *  the pointer is the user's responsibilty.        */
end_comment

begin_function_decl
name|void
name|unique
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/**        *  @brief  Remove consecutive elements satisfying a predicate.        *  @param  BinaryPredicate  Binary predicate function or object.        *        *  For each consecutive set of elements [first,last) that        *  satisfy predicate(first,i) where i is an iterator in        *  [first,last), remove all but the first one.  Remaining        *  elements stay in list order.  Note that this function only        *  erases the elements, and that if the elements themselves are        *  pointers, the pointed-to memory is not touched in any way.        *  Managing the pointer is the user's responsibilty.        */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_BinaryPredicate
operator|>
name|void
name|unique
argument_list|(
name|_BinaryPredicate
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**        *  @brief  Merge sorted lists.        *  @param  x  Sorted list to merge.        *        *  Assumes that both @a x and this list are sorted according to        *  operator<().  Merges elements of @a x into this list in        *  sorted order, leaving @a x empty when complete.  Elements in        *  this list precede elements in @a x that are equal.        */
end_comment

begin_function_decl
name|void
name|merge
parameter_list|(
name|list
modifier|&
name|__x
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**        *  @brief  Merge sorted lists according to comparison function.        *  @param  x  Sorted list to merge.        *  @param StrictWeakOrdering Comparison function definining        *  sort order.        *        *  Assumes that both @a x and this list are sorted according to        *  StrictWeakOrdering.  Merges elements of @a x into this list        *  in sorted order, leaving @a x empty when complete.  Elements        *  in this list precede elements in @a x that are equivalent        *  according to StrictWeakOrdering().        */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_StrictWeakOrdering
operator|>
name|void
name|merge
argument_list|(
name|list
operator|&
argument_list|,
name|_StrictWeakOrdering
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**        *  @brief  Reverse the elements in list.        *        *  Reverse the order of elements in the list in linear time.        */
end_comment

begin_function
name|void
name|reverse
parameter_list|()
block|{
name|this
operator|->
name|_M_impl
operator|.
name|_M_node
operator|.
name|reverse
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/**        *  @brief  Sort the elements.        *        *  Sorts the elements of this list in NlogN time.  Equivalent        *  elements remain in list order.        */
end_comment

begin_function_decl
name|void
name|sort
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/**        *  @brief  Sort the elements according to comparison function.        *        *  Sorts the elements of this list in NlogN time.  Equivalent        *  elements remain in list order.        */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_StrictWeakOrdering
operator|>
name|void
name|sort
argument_list|(
name|_StrictWeakOrdering
argument_list|)
expr_stmt|;
end_expr_stmt

begin_label
name|protected
label|:
end_label

begin_comment
comment|// Internal assign functions follow.
end_comment

begin_comment
comment|// Called by the range assign to implement [23.1.1]/9
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Integer
operator|>
name|void
name|_M_assign_dispatch
argument_list|(
argument|_Integer __n
argument_list|,
argument|_Integer __val
argument_list|,
argument|__true_type
argument_list|)
block|{
name|_M_fill_assign
argument_list|(
name|static_cast
operator|<
name|size_type
operator|>
operator|(
name|__n
operator|)
argument_list|,
name|static_cast
operator|<
name|value_type
operator|>
operator|(
name|__val
operator|)
argument_list|)
block|; 	}
comment|// Called by the range assign to implement [23.1.1]/9
name|template
operator|<
name|typename
name|_InputIterator
operator|>
name|void
name|_M_assign_dispatch
argument_list|(
argument|_InputIterator __first
argument_list|,
argument|_InputIterator __last
argument_list|,
argument|__false_type
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Called by assign(n,t), and the range assign when it turns out
end_comment

begin_comment
comment|// to be the same thing.
end_comment

begin_function_decl
name|void
name|_M_fill_assign
parameter_list|(
name|size_type
name|__n
parameter_list|,
specifier|const
name|value_type
modifier|&
name|__val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Internal insert functions follow.
end_comment

begin_comment
comment|// Called by the range insert to implement [23.1.1]/9
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Integer
operator|>
name|void
name|_M_insert_dispatch
argument_list|(
argument|iterator __pos
argument_list|,
argument|_Integer __n
argument_list|,
argument|_Integer __x
argument_list|,
argument|__true_type
argument_list|)
block|{
name|_M_fill_insert
argument_list|(
name|__pos
argument_list|,
name|static_cast
operator|<
name|size_type
operator|>
operator|(
name|__n
operator|)
argument_list|,
name|static_cast
operator|<
name|value_type
operator|>
operator|(
name|__x
operator|)
argument_list|)
block|; 	}
comment|// Called by the range insert to implement [23.1.1]/9
name|template
operator|<
name|typename
name|_InputIterator
operator|>
name|void
name|_M_insert_dispatch
argument_list|(
argument|iterator __pos
argument_list|,
argument|_InputIterator __first
argument_list|,
argument|_InputIterator __last
argument_list|,
argument|__false_type
argument_list|)
block|{
for|for
control|(
init|;
name|__first
operator|!=
name|__last
condition|;
operator|++
name|__first
control|)
name|_M_insert
argument_list|(
name|__pos
argument_list|,
operator|*
name|__first
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_comment
comment|// Called by insert(p,n,x), and the range insert when it turns out
end_comment

begin_comment
comment|// to be the same thing.
end_comment

begin_function
name|void
name|_M_fill_insert
parameter_list|(
name|iterator
name|__pos
parameter_list|,
name|size_type
name|__n
parameter_list|,
specifier|const
name|value_type
modifier|&
name|__x
parameter_list|)
block|{
for|for
control|(
init|;
name|__n
operator|>
literal|0
condition|;
operator|--
name|__n
control|)
name|_M_insert
argument_list|(
name|__pos
argument_list|,
name|__x
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Moves the elements from [first,last) before position.
end_comment

begin_function
name|void
name|_M_transfer
parameter_list|(
name|iterator
name|__position
parameter_list|,
name|iterator
name|__first
parameter_list|,
name|iterator
name|__last
parameter_list|)
block|{
name|__position
operator|.
name|_M_node
operator|->
name|transfer
argument_list|(
name|__first
operator|.
name|_M_node
argument_list|,
name|__last
operator|.
name|_M_node
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Inserts new element at position given and with value given.
end_comment

begin_function
name|void
name|_M_insert
parameter_list|(
name|iterator
name|__position
parameter_list|,
specifier|const
name|value_type
modifier|&
name|__x
parameter_list|)
block|{
name|_Node
modifier|*
name|__tmp
init|=
name|_M_create_node
argument_list|(
name|__x
argument_list|)
decl_stmt|;
name|__tmp
operator|->
name|hook
argument_list|(
name|__position
operator|.
name|_M_node
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Erases element at position given.
end_comment

begin_function
name|void
name|_M_erase
parameter_list|(
name|iterator
name|__position
parameter_list|)
block|{
name|__position
operator|.
name|_M_node
operator|->
name|unhook
argument_list|()
expr_stmt|;
name|_Node
modifier|*
name|__n
init|=
name|static_cast
operator|<
name|_Node
operator|*
operator|>
operator|(
name|__position
operator|.
name|_M_node
operator|)
decl_stmt|;
name|std
operator|::
name|_Destroy
argument_list|(
operator|&
name|__n
operator|->
name|_M_data
argument_list|)
expr_stmt|;
name|_M_put_node
argument_list|(
name|__n
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
unit|};
comment|/**    *  @brief  List equality comparison.    *  @param  x  A %list.    *  @param  y  A %list of the same type as @a x.    *  @return  True iff the size and elements of the lists are equal.    *    *  This is an equivalence relation.  It is linear in the size of    *  the lists.  Lists are considered equivalent if their sizes are    *  equal, and if corresponding elements compare equal.   */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|,
name|typename
name|_Alloc
operator|>
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|list
operator|<
name|_Tp
operator|,
name|_Alloc
operator|>
operator|&
name|__x
operator|,
specifier|const
name|list
operator|<
name|_Tp
operator|,
name|_Alloc
operator|>
operator|&
name|__y
operator|)
block|{
typedef|typedef
name|typename
name|list
operator|<
name|_Tp
operator|,
name|_Alloc
operator|>
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
name|const_iterator
name|__end1
operator|=
name|__x
operator|.
name|end
argument_list|()
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|const_iterator
name|__end2
init|=
name|__y
operator|.
name|end
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|const_iterator
name|__i1
init|=
name|__x
operator|.
name|begin
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|const_iterator
name|__i2
init|=
name|__y
operator|.
name|begin
argument_list|()
decl_stmt|;
end_decl_stmt

begin_while
while|while
condition|(
name|__i1
operator|!=
name|__end1
operator|&&
name|__i2
operator|!=
name|__end2
operator|&&
operator|*
name|__i1
operator|==
operator|*
name|__i2
condition|)
block|{
operator|++
name|__i1
expr_stmt|;
operator|++
name|__i2
expr_stmt|;
block|}
end_while

begin_return
return|return
name|__i1
operator|==
name|__end1
operator|&&
name|__i2
operator|==
name|__end2
return|;
end_return

begin_comment
unit|}
comment|/**    *  @brief  List ordering relation.    *  @param  x  A %list.    *  @param  y  A %list of the same type as @a x.    *  @return  True iff @a x is lexicographically less than @a y.    *    *  This is a total ordering relation.  It is linear in the size of the    *  lists.  The elements must be comparable with @c<.    *    *  See std::lexicographical_compare() for how the determination is made.   */
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_Tp
operator|,
name|typename
name|_Alloc
operator|>
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|list
operator|<
name|_Tp
operator|,
name|_Alloc
operator|>
operator|&
name|__x
operator|,
specifier|const
name|list
operator|<
name|_Tp
operator|,
name|_Alloc
operator|>
operator|&
name|__y
operator|)
block|{
return|return
name|std
operator|::
name|lexicographical_compare
argument_list|(
name|__x
operator|.
name|begin
argument_list|()
argument_list|,
name|__x
operator|.
name|end
argument_list|()
argument_list|,
name|__y
operator|.
name|begin
argument_list|()
argument_list|,
name|__y
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Based on operator==
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|,
name|typename
name|_Alloc
operator|>
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|list
operator|<
name|_Tp
operator|,
name|_Alloc
operator|>
operator|&
name|__x
operator|,
specifier|const
name|list
operator|<
name|_Tp
operator|,
name|_Alloc
operator|>
operator|&
name|__y
operator|)
block|{
return|return
operator|!
operator|(
name|__x
operator|==
name|__y
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Based on operator<
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|,
name|typename
name|_Alloc
operator|>
specifier|inline
name|bool
name|operator
operator|>
operator|(
specifier|const
name|list
operator|<
name|_Tp
operator|,
name|_Alloc
operator|>
operator|&
name|__x
operator|,
specifier|const
name|list
operator|<
name|_Tp
operator|,
name|_Alloc
operator|>
operator|&
name|__y
operator|)
block|{
return|return
name|__y
operator|<
name|__x
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Based on operator<
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|,
name|typename
name|_Alloc
operator|>
specifier|inline
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|list
operator|<
name|_Tp
operator|,
name|_Alloc
operator|>
operator|&
name|__x
operator|,
specifier|const
name|list
operator|<
name|_Tp
operator|,
name|_Alloc
operator|>
operator|&
name|__y
operator|)
block|{
return|return
operator|!
operator|(
name|__y
operator|<
name|__x
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Based on operator<
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|,
name|typename
name|_Alloc
operator|>
specifier|inline
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|list
operator|<
name|_Tp
operator|,
name|_Alloc
operator|>
operator|&
name|__x
operator|,
specifier|const
name|list
operator|<
name|_Tp
operator|,
name|_Alloc
operator|>
operator|&
name|__y
operator|)
block|{
return|return
operator|!
operator|(
name|__x
operator|<
name|__y
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// See std::list::swap().
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|,
name|typename
name|_Alloc
operator|>
specifier|inline
name|void
name|swap
argument_list|(
argument|list<_Tp
argument_list|,
argument|_Alloc>& __x
argument_list|,
argument|list<_Tp
argument_list|,
argument|_Alloc>& __y
argument_list|)
block|{
name|__x
operator|.
name|swap
argument_list|(
name|__y
argument_list|)
block|; }
end_expr_stmt

begin_comment
unit|}
comment|// namespace std
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LIST_H */
end_comment

end_unit

