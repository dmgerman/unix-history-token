begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// List implementation -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2001, 2002 Free Software Foundation, Inc.
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
name|__GLIBCPP_INTERNAL_LIST_H
end_ifndef

begin_define
define|#
directive|define
name|__GLIBCPP_INTERNAL_LIST_H
end_define

begin_include
include|#
directive|include
file|<bits/concept_check.h>
end_include

begin_decl_stmt
name|namespace
name|std
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
comment|/**    *  @if maint    *  @brief Common part of a list::iterator.    *    *  A simple type to walk a doubly-linked list.  All operations here should    *  be self-explanatory after taking any decent introductory data structures    *  course.    *  @endif   */
struct|struct
name|_List_iterator_base
block|{
typedef|typedef
name|size_t
name|size_type
typedef|;
typedef|typedef
name|ptrdiff_t
name|difference_type
typedef|;
typedef|typedef
name|bidirectional_iterator_tag
name|iterator_category
typedef|;
comment|/// The only member points to the %list element.
name|_List_node_base
modifier|*
name|_M_node
decl_stmt|;
name|_List_iterator_base
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
name|_List_iterator_base
argument_list|()
block|{ }
comment|/// Walk the %list forward.
name|void
name|_M_incr
argument_list|()
block|{
name|_M_node
operator|=
name|_M_node
operator|->
name|_M_next
block|; }
comment|/// Walk the %list backward.
name|void
name|_M_decr
argument_list|()
block|{
name|_M_node
operator|=
name|_M_node
operator|->
name|_M_prev
block|; }
name|bool
name|operator
operator|==
operator|(
specifier|const
name|_List_iterator_base
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
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|_List_iterator_base
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
block|}
struct|;
comment|/**    *  @brief A list::iterator.    *    *  In addition to being used externally, a list holds one of these    *  internally, pointing to the sequence of data.    *    *  @if maint    *  All the functions are op overloads.    *  @endif   */
name|template
operator|<
name|typename
name|_Tp
operator|,
name|typename
name|_Ref
operator|,
name|typename
name|_Ptr
operator|>
expr|struct
name|_List_iterator
operator|:
name|public
name|_List_iterator_base
block|{
typedef|typedef
name|_List_iterator
operator|<
name|_Tp
operator|,
name|_Tp
operator|&
operator|,
name|_Tp
operator|*
operator|>
name|iterator
expr_stmt|;
typedef|typedef
name|_List_iterator
operator|<
name|_Tp
operator|,
specifier|const
name|_Tp
operator|&
operator|,
specifier|const
name|_Tp
operator|*
operator|>
name|const_iterator
expr_stmt|;
typedef|typedef
name|_List_iterator
operator|<
name|_Tp
operator|,
name|_Ref
operator|,
name|_Ptr
operator|>
name|_Self
expr_stmt|;
typedef|typedef
name|_Tp
name|value_type
typedef|;
typedef|typedef
name|_Ptr
name|pointer
typedef|;
typedef|typedef
name|_Ref
name|reference
typedef|;
typedef|typedef
name|_List_node
operator|<
name|_Tp
operator|>
name|_Node
expr_stmt|;
name|_List_iterator
argument_list|(
name|_Node
operator|*
name|__x
argument_list|)
operator|:
name|_List_iterator_base
argument_list|(
argument|__x
argument_list|)
block|{ }
name|_List_iterator
argument_list|()
block|{ }
name|_List_iterator
argument_list|(
specifier|const
name|iterator
operator|&
name|__x
argument_list|)
operator|:
name|_List_iterator_base
argument_list|(
argument|__x._M_node
argument_list|)
block|{ }
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
comment|// Must downcast from List_node_base to _List_node to get to _M_data.
name|pointer
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
operator|&
operator|(
name|operator
operator|*
operator|(
operator|)
operator|)
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
name|this
operator|->
name|_M_incr
argument_list|()
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
name|this
operator|->
name|_M_incr
argument_list|()
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
name|this
operator|->
name|_M_decr
argument_list|()
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
name|this
operator|->
name|_M_decr
argument_list|()
block|;
return|return
name|__tmp
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// @if maint Primary default version.  @endif
end_comment

begin_comment
comment|/**    *  @if maint    *  See bits/stl_deque.h's _Deque_alloc_base for an explanation.    *  @endif   */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|,
name|typename
name|_Allocator
operator|,
name|bool
name|_IsStatic
operator|>
name|class
name|_List_alloc_base
block|{
name|public
operator|:
typedef|typedef
name|typename
name|_Alloc_traits
operator|<
name|_Tp
operator|,
name|_Allocator
operator|>
operator|::
name|allocator_type
name|allocator_type
expr_stmt|;
name|allocator_type
name|get_allocator
argument_list|()
specifier|const
block|{
return|return
name|_M_node_allocator
return|;
block|}
name|_List_alloc_base
argument_list|(
specifier|const
name|allocator_type
operator|&
name|__a
argument_list|)
operator|:
name|_M_node_allocator
argument_list|(
argument|__a
argument_list|)
block|{ }
name|protected
operator|:
name|_List_node
operator|<
name|_Tp
operator|>
operator|*
name|_M_get_node
argument_list|()
block|{
return|return
name|_M_node_allocator
operator|.
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
name|_M_node_allocator
operator|.
name|deallocate
argument_list|(
name|__p
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// NOTA BENE
end_comment

begin_comment
comment|// The stored instance is not actually of "allocator_type"'s type.  Instead
end_comment

begin_comment
comment|// we rebind the type to Allocator<List_node<Tp>>, which according to
end_comment

begin_comment
comment|// [20.1.5]/4 should probably be the same.  List_node<Tp> is not the same
end_comment

begin_comment
comment|// size as Tp (it's two pointers larger), and specializations on Tp may go
end_comment

begin_comment
comment|// unused because List_node<Tp> is being bound instead.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// We put this to the test in get_allocator above; if the two types are
end_comment

begin_comment
comment|// actually different, there had better be a conversion between them.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// None of the predefined allocators shipped with the library (as of 3.1)
end_comment

begin_comment
comment|// use this instantiation anyhow; they're all instanceless.
end_comment

begin_expr_stmt
name|typename
name|_Alloc_traits
operator|<
name|_List_node
operator|<
name|_Tp
operator|>
operator|,
name|_Allocator
operator|>
operator|::
name|allocator_type
name|_M_node_allocator
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|_List_node
operator|<
name|_Tp
operator|>
operator|*
name|_M_node
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// @if maint Specialization for instanceless allocators.  @endif
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|,
name|typename
name|_Allocator
operator|>
name|class
name|_List_alloc_base
operator|<
name|_Tp
operator|,
name|_Allocator
operator|,
name|true
operator|>
block|{
name|public
operator|:
typedef|typedef
name|typename
name|_Alloc_traits
operator|<
name|_Tp
operator|,
name|_Allocator
operator|>
operator|::
name|allocator_type
name|allocator_type
expr_stmt|;
name|allocator_type
name|get_allocator
argument_list|()
specifier|const
block|{
return|return
name|allocator_type
argument_list|()
return|;
block|}
name|_List_alloc_base
argument_list|(
argument|const allocator_type&
argument_list|)
block|{ }
name|protected
operator|:
end_expr_stmt

begin_comment
comment|// See comment in primary template class about why this is safe for the
end_comment

begin_comment
comment|// standard predefined classes.
end_comment

begin_typedef
typedef|typedef
name|typename
name|_Alloc_traits
operator|<
name|_List_node
operator|<
name|_Tp
operator|>
operator|,
name|_Allocator
operator|>
operator|::
name|_Alloc_type
name|_Alloc_type
expr_stmt|;
end_typedef

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
name|_Alloc_type
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
name|_Alloc_type
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

begin_expr_stmt
name|_List_node
operator|<
name|_Tp
operator|>
operator|*
name|_M_node
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
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
operator|:
name|public
name|_List_alloc_base
operator|<
name|_Tp
operator|,
name|_Alloc
operator|,
name|_Alloc_traits
operator|<
name|_Tp
operator|,
name|_Alloc
operator|>
operator|::
name|_S_instanceless
operator|>
block|{
name|public
operator|:
typedef|typedef
name|_List_alloc_base
operator|<
name|_Tp
operator|,
name|_Alloc
operator|,
name|_Alloc_traits
operator|<
name|_Tp
operator|,
name|_Alloc
operator|>
operator|::
name|_S_instanceless
operator|>
name|_Base
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|_Base
operator|::
name|allocator_type
name|allocator_type
expr_stmt|;
end_typedef

begin_expr_stmt
name|_List_base
argument_list|(
specifier|const
name|allocator_type
operator|&
name|__a
argument_list|)
operator|:
name|_Base
argument_list|(
argument|__a
argument_list|)
block|{
name|_M_node
operator|=
name|_M_get_node
argument_list|()
block|;
name|_M_node
operator|->
name|_M_next
operator|=
name|_M_node
block|;
name|_M_node
operator|->
name|_M_prev
operator|=
name|_M_node
block|;     }
comment|// This is what actually destroys the list.
operator|~
name|_List_base
argument_list|()
block|{
name|__clear
argument_list|()
block|;
name|_M_put_node
argument_list|(
name|_M_node
argument_list|)
block|;     }
name|void
name|__clear
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/**    *  @brief  A standard container with linear time access to elements, and    *  fixed time insertion/deletion at any point in the sequence.    *    *  @ingroup Containers    *  @ingroup Sequences    *    *  Meets the requirements of a<a href="tables.html#65">container</a>, a    *<a href="tables.html#66">reversible container</a>, and a    *<a href="tables.html#67">sequence</a>, including the    *<a href="tables.html#68">optional sequence requirements</a> with the    *  %exception of @c at and @c operator[].    *    *  This is a @e doubly @e linked %list.  Traversal up and down the %list    *  requires linear time, but adding and removing elements (or @e nodes) is    *  done in constant time, regardless of where the change takes place.    *  Unlike std::vector and std::deque, random-access iterators are not    *  provided, so subscripting ( @c [] ) access is not allowed.  For algorithms    *  which only need sequential access, this lack makes no difference.    *    *  Also unlike the other standard containers, std::list provides specialized     *  algorithms %unique to linked lists, such as splicing, sorting, and    *  in-place reversal.    *    *  @if maint    *  A couple points on memory allocation for list<Tp>:    *    *  First, we never actually allocate a Tp, we allocate List_node<Tp>'s    *  and trust [20.1.5]/4 to DTRT.  This is to ensure that after elements from    *  %list<X,Alloc1> are spliced into %list<X,Alloc2>, destroying the memory of    *  the second %list is a valid operation, i.e., Alloc1 giveth and Alloc2    *  taketh away.    *    *  Second, a %list conceptually represented as    *  @code    *    A<---> B<---> C<---> D    *  @endcode    *  is actually circular; a link exists between A and D.  The %list class    *  holds (as its only data member) a private list::iterator pointing to    *  @e D, not to @e A!  To get to the head of the %list, we start at the tail    *  and move forward by one.  When this member iterator's next/previous    *  pointers refer to itself, the %list is %empty.    *  @endif   */
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
name|__glibcpp_class_requires
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
name|value_type
modifier|*
name|pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|value_type
modifier|*
name|const_pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_List_iterator
operator|<
name|_Tp
operator|,
name|_Tp
operator|&
operator|,
name|_Tp
operator|*
operator|>
name|iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|_List_iterator
operator|<
name|_Tp
operator|,
specifier|const
name|_Tp
operator|&
operator|,
specifier|const
name|_Tp
operator|*
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
name|value_type
modifier|&
name|reference
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|value_type
modifier|&
name|const_reference
typedef|;
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
comment|// Note that pointers-to-_Node's can be ctor-converted to iterator types.
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
comment|/** @if maint      *  One data member plus two memory-handling functions.  If the _Alloc      *  type requires separate instances, then one of those will also be      *  included, accumulated from the topmost parent.      *  @endif     */
end_comment

begin_expr_stmt
name|using
name|_Base
operator|::
name|_M_node
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
comment|/**      *  @if maint      *  @param  x  An instance of user data.      *      *  Allocates space for a new node and constructs a copy of @a x in it.      *  @endif     */
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
name|_M_get_node
argument_list|()
decl_stmt|;
name|try
block|{
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
comment|/**      *  @if maint      *  Allocates space for a new node and default-constructs a new instance      *  of @c value_type in it.      *  @endif     */
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
name|_M_get_node
argument_list|()
decl_stmt|;
name|try
block|{
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
comment|/**      *  @brief  Default constructor creates no elements.     */
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
comment|/**      *  @brief  Create a %list with copies of an exemplar element.      *  @param  n  The number of elements to initially create.      *  @param  value  An element to copy.      *       *  This constructor fills the %list with @a n copies of @a value.     */
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
comment|/**      *  @brief  Create a %list with default elements.      *  @param  n  The number of elements to initially create.      *       *  This constructor fills the %list with @a n copies of a      *  default-constructed element.     */
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
comment|/**      *  @brief  %List copy constructor.      *  @param  x  A %list of identical element and allocator types.      *       *  The newly-created %list uses a copy of the allocation object used      *  by @a x.     */
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
comment|/**      *  @brief  Builds a %list from a range.      *  @param  first  An input iterator.      *  @param  last  An input iterator.      *       *  Create a %list consisting of copies of the elements from [first,last).      *  This is linear in N (where N is distance(first,last)).      *      *  @if maint      *  We don't need any dispatching tricks here, because insert does all of      *  that anyway.      *  @endif     */
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
comment|/**      *  The dtor only erases the elements, and note that if the elements      *  themselves are pointers, the pointed-to memory is not touched in any      *  way.  Managing the pointer is the user's responsibilty.     */
operator|~
name|list
argument_list|()
block|{ }
comment|/**      *  @brief  %List assignment operator.      *  @param  x  A %list of identical element and allocator types.      *       *  All the elements of @a x are copied, but unlike the copy constructor,      *  the allocator object is not copied.     */
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
comment|/**      *  @brief  Assigns a given value to a %list.      *  @param  n  Number of elements to be assigned.      *  @param  val  Value to be assigned.      *      *  This function fills a %list with @a n copies of the given value.      *  Note that the assignment completely changes the %list and that the      *  resulting %list's size is the same as the number of elements assigned.      *  Old data may be lost.     */
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
comment|/**      *  @brief  Assigns a range to a %list.      *  @param  first  An input iterator.      *  @param  last   An input iterator.      *      *  This function fills a %list with copies of the elements in the      *  range [first,last).      *      *  Note that the assignment completely changes the %list and that the      *  resulting %list's size is the same as the number of elements assigned.      *  Old data may be lost.     */
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
comment|/**      *  Returns a read/write iterator that points to the first element in the      *  %list.  Iteration is done in ordinary element order.     */
end_comment

begin_function
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|_Node
operator|*
operator|>
operator|(
name|_M_node
operator|->
name|_M_next
operator|)
return|;
block|}
end_function

begin_comment
comment|/**      *  Returns a read-only (constant) iterator that points to the first element      *  in the %list.  Iteration is done in ordinary element order.     */
end_comment

begin_expr_stmt
name|const_iterator
name|begin
argument_list|()
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
operator|->
name|_M_next
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/**      *  Returns a read/write iterator that points one past the last element in      *  the %list.  Iteration is done in ordinary element order.     */
end_comment

begin_function
name|iterator
name|end
parameter_list|()
block|{
return|return
name|_M_node
return|;
block|}
end_function

begin_comment
comment|/**      *  Returns a read-only (constant) iterator that points one past the last      *  element in the %list.  Iteration is done in ordinary element order.     */
end_comment

begin_expr_stmt
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|_M_node
return|;
block|}
end_expr_stmt

begin_comment
comment|/**      *  Returns a read/write reverse iterator that points to the last element in      *  the %list.  Iteration is done in reverse element order.     */
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
comment|/**      *  Returns a read-only (constant) reverse iterator that points to the last      *  element in the %list.  Iteration is done in reverse element order.     */
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
comment|/**      *  Returns a read/write reverse iterator that points to one before the      *  first element in the %list.  Iteration is done in reverse element      *  order.     */
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
comment|/**      *  Returns a read-only (constant) reverse iterator that points to one      *  before the first element in the %list.  Iteration is done in reverse      *  element order.     */
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
comment|/**      *  Returns true if the %list is empty.  (Thus begin() would equal end().)     */
end_comment

begin_expr_stmt
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|_M_node
operator|->
name|_M_next
operator|==
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
comment|/**      *  @brief  Resizes the %list to the specified number of elements.      *  @param  new_size  Number of elements the %list should contain.      *  @param  x  Data with which new elements should be populated.      *      *  This function will %resize the %list to the specified number of      *  elements.  If the number is smaller than the %list's current size the      *  %list is truncated, otherwise the %list is extended and new elements      *  are populated with given data.     */
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
comment|/**      *  @brief  Resizes the %list to the specified number of elements.      *  @param  new_size  Number of elements the %list should contain.      *      *  This function will resize the %list to the specified number of      *  elements.  If the number is smaller than the %list's current size the      *  %list is truncated, otherwise the %list is extended and new elements      *  are default-constructed.     */
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
comment|/**      *  Returns a read/write reference to the data at the first element of the      *  %list.     */
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
comment|/**      *  Returns a read-only (constant) reference to the data at the first      *  element of the %list.     */
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
comment|/**      *  Returns a read/write reference to the data at the last element of the      *  %list.     */
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
comment|/**      *  Returns a read-only (constant) reference to the data at the last      *  element of the %list.     */
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
comment|/**      *  @brief  Add data to the front of the %list.      *  @param  x  Data to be added.      *      *  This is a typical stack operation.  The function creates an element at      *  the front of the %list and assigns the given data to it.  Due to the      *  nature of a %list this operation can be done in constant time, and      *  does not invalidate iterators and references.     */
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
name|insert
argument_list|(
name|begin
argument_list|()
argument_list|,
name|__x
argument_list|)
expr_stmt|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCPP_DEPRECATED
end_ifdef

begin_comment
comment|/**      *  @brief  Add data to the front of the %list.      *      *  This is a typical stack operation.  The function creates a      *  default-constructed element at the front of the %list.  Due to the      *  nature of a %list this operation can be done in constant time.  You      *  should consider using push_front(value_type()) instead.      *      *  @note This was deprecated in 3.2 and will be removed in 3.4.  You must      *        define @c _GLIBCPP_DEPRECATED to make this visible in 3.2; see      *        c++config.h.     */
end_comment

begin_function
name|void
name|push_front
parameter_list|()
block|{
name|this
operator|->
name|insert
argument_list|(
name|begin
argument_list|()
argument_list|,
name|value_type
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**      *  @brief  Removes first element.      *      *  This is a typical stack operation.  It shrinks the %list by one.      *  Due to the nature of a %list this operation can be done in constant      *  time, and only invalidates iterators/references to the element being      *  removed.      *      *  Note that no data is returned, and if the first element's data is      *  needed, it should be retrieved before pop_front() is called.     */
end_comment

begin_function
name|void
name|pop_front
parameter_list|()
block|{
name|this
operator|->
name|erase
argument_list|(
name|begin
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**      *  @brief  Add data to the end of the %list.      *  @param  x  Data to be added.      *      *  This is a typical stack operation.  The function creates an element at      *  the end of the %list and assigns the given data to it.  Due to the      *  nature of a %list this operation can be done in constant time, and      *  does not invalidate iterators and references.     */
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
name|insert
argument_list|(
name|end
argument_list|()
argument_list|,
name|__x
argument_list|)
expr_stmt|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCPP_DEPRECATED
end_ifdef

begin_comment
comment|/**      *  @brief  Add data to the end of the %list.      *      *  This is a typical stack operation.  The function creates a      *  default-constructed element at the end of the %list.  Due to the nature      *  of a %list this operation can be done in constant time.  You should      *  consider using push_back(value_type()) instead.      *      *  @note This was deprecated in 3.2 and will be removed in 3.4.  You must      *        define @c _GLIBCPP_DEPRECATED to make this visible in 3.2; see      *        c++config.h.     */
end_comment

begin_function
name|void
name|push_back
parameter_list|()
block|{
name|this
operator|->
name|insert
argument_list|(
name|end
argument_list|()
argument_list|,
name|value_type
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**      *  @brief  Removes last element.      *      *  This is a typical stack operation.  It shrinks the %list by one.      *  Due to the nature of a %list this operation can be done in constant      *  time, and only invalidates iterators/references to the element being      *  removed.      *      *  Note that no data is returned, and if the last element's data is      *  needed, it should be retrieved before pop_back() is called.     */
end_comment

begin_function
name|void
name|pop_back
parameter_list|()
block|{
name|iterator
name|__tmp
init|=
name|end
argument_list|()
decl_stmt|;
name|this
operator|->
name|erase
argument_list|(
operator|--
name|__tmp
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**      *  @brief  Inserts given value into %list before specified iterator.      *  @param  position  An iterator into the %list.      *  @param  x  Data to be inserted.      *  @return  An iterator that points to the inserted data.      *      *  This function will insert a copy of the given value before the specified      *  location.      *  Due to the nature of a %list this operation can be done in constant      *  time, and does not invalidate iterators and references.     */
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

begin_ifdef
ifdef|#
directive|ifdef
name|_GLIBCPP_DEPRECATED
end_ifdef

begin_comment
comment|/**      *  @brief  Inserts an element into the %list.      *  @param  position  An iterator into the %list.      *  @return  An iterator that points to the inserted element.      *      *  This function will insert a default-constructed element before the      *  specified location.  You should consider using      *  insert(position,value_type()) instead.      *  Due to the nature of a %list this operation can be done in constant      *  time, and does not invalidate iterators and references.      *      *  @note This was deprecated in 3.2 and will be removed in 3.4.  You must      *        define @c _GLIBCPP_DEPRECATED to make this visible in 3.2; see      *        c++config.h.     */
end_comment

begin_function
name|iterator
name|insert
parameter_list|(
name|iterator
name|__position
parameter_list|)
block|{
return|return
name|insert
argument_list|(
name|__position
argument_list|,
name|value_type
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**      *  @brief  Inserts a number of copies of given data into the %list.      *  @param  position  An iterator into the %list.      *  @param  n  Number of elements to be inserted.      *  @param  x  Data to be inserted.      *      *  This function will insert a specified number of copies of the given data      *  before the location specified by @a position.      *      *  Due to the nature of a %list this operation can be done in constant      *  time, and does not invalidate iterators and references.     */
end_comment

begin_function
name|void
name|insert
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
name|_M_fill_insert
argument_list|(
name|__pos
argument_list|,
name|__n
argument_list|,
name|__x
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**      *  @brief  Inserts a range into the %list.      *  @param  pos  An iterator into the %list.      *  @param  first  An input iterator.      *  @param  last   An input iterator.      *      *  This function will insert copies of the data in the range [first,last)      *  into the %list before the location specified by @a pos.      *      *  Due to the nature of a %list this operation can be done in constant      *  time, and does not invalidate iterators and references.     */
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
argument|iterator __pos
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
name|__pos
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
comment|/**      *  @brief  Remove element at given position.      *  @param  position  Iterator pointing to element to be erased.      *  @return  An iterator pointing to the next element (or end()).      *      *  This function will erase the element at the given position and thus      *  shorten the %list by one.      *      *  Due to the nature of a %list this operation can be done in constant      *  time, and only invalidates iterators/references to the element being      *  removed.      *  The user is also cautioned that      *  this function only erases the element, and that if the element is itself      *  a pointer, the pointed-to memory is not touched in any way.  Managing      *  the pointer is the user's responsibilty.     */
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
comment|/**      *  @brief  Remove a range of elements.      *  @param  first  Iterator pointing to the first element to be erased.      *  @param  last  Iterator pointing to one past the last element to be      *                erased.      *  @return  An iterator pointing to the element pointed to by @a last      *           prior to erasing (or end()).      *      *  This function will erase the elements in the range [first,last) and      *  shorten the %list accordingly.      *      *  Due to the nature of a %list this operation can be done in constant      *  time, and only invalidates iterators/references to the element being      *  removed.      *  The user is also cautioned that      *  this function only erases the elements, and that if the elements      *  themselves are pointers, the pointed-to memory is not touched in any      *  way.  Managing the pointer is the user's responsibilty.     */
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
name|erase
argument_list|(
name|__first
operator|++
argument_list|)
expr_stmt|;
return|return
name|__last
return|;
block|}
end_function

begin_comment
comment|/**      *  @brief  Swaps data with another %list.      *  @param  x  A %list of the same element and allocator types.      *      *  This exchanges the elements between two lists in constant time.      *  (It is only swapping a single pointer, so it should be quite fast.)      *  Note that the global std::swap() function is specialized such that      *  std::swap(l1,l2) will feed to this function.     */
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
name|std
operator|::
name|swap
argument_list|(
name|_M_node
argument_list|,
name|__x
operator|.
name|_M_node
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**      *  Erases all the elements.  Note that this function only erases the      *  elements, and that if the elements themselves are pointers, the      *  pointed-to memory is not touched in any way.  Managing the pointer is      *  the user's responsibilty.     */
end_comment

begin_function
name|void
name|clear
parameter_list|()
block|{
name|_Base
operator|::
name|__clear
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// [23.2.2.4] list operations
end_comment

begin_comment
comment|/**      *  @doctodo     */
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
comment|/**      *  @doctodo     */
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
comment|/**      *  @doctodo     */
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
comment|/**      *  @doctodo     */
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
comment|/**      *  @doctodo     */
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
comment|/**      *  @doctodo     */
end_comment

begin_function_decl
name|void
name|unique
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/**      *  @doctodo     */
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
comment|/**      *  @doctodo     */
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
comment|/**      *  @doctodo     */
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
comment|/**      *  @doctodo     */
end_comment

begin_function
name|void
name|reverse
parameter_list|()
block|{
name|__List_base_reverse
argument_list|(
name|this
operator|->
name|_M_node
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**      *  @doctodo     */
end_comment

begin_function_decl
name|void
name|sort
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/**      *  @doctodo     */
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
comment|// called by the range assign to implement [23.1.1]/9
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
block|;       }
comment|// called by the range assign to implement [23.1.1]/9
name|template
operator|<
name|typename
name|_InputIter
operator|>
name|void
name|_M_assign_dispatch
argument_list|(
argument|_InputIter __first
argument_list|,
argument|_InputIter __last
argument_list|,
argument|__false_type
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Called by assign(n,t), and the range assign when it turns out to be the
end_comment

begin_comment
comment|// same thing.
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
comment|// called by the range insert to implement [23.1.1]/9
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
block|;       }
comment|// called by the range insert to implement [23.1.1]/9
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
name|insert
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
comment|// Called by insert(p,n,x), and the range insert when it turns out to be
end_comment

begin_comment
comment|// the same thing.
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
name|insert
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
if|if
condition|(
name|__position
operator|!=
name|__last
condition|)
block|{
comment|// Remove [first, last) from its old position.
name|__last
operator|.
name|_M_node
operator|->
name|_M_prev
operator|->
name|_M_next
operator|=
name|__position
operator|.
name|_M_node
expr_stmt|;
name|__first
operator|.
name|_M_node
operator|->
name|_M_prev
operator|->
name|_M_next
operator|=
name|__last
operator|.
name|_M_node
expr_stmt|;
name|__position
operator|.
name|_M_node
operator|->
name|_M_prev
operator|->
name|_M_next
operator|=
name|__first
operator|.
name|_M_node
expr_stmt|;
comment|// Splice [first, last) into its new position.
name|_List_node_base
modifier|*
name|__tmp
init|=
name|__position
operator|.
name|_M_node
operator|->
name|_M_prev
decl_stmt|;
name|__position
operator|.
name|_M_node
operator|->
name|_M_prev
operator|=
name|__last
operator|.
name|_M_node
operator|->
name|_M_prev
expr_stmt|;
name|__last
operator|.
name|_M_node
operator|->
name|_M_prev
operator|=
name|__first
operator|.
name|_M_node
operator|->
name|_M_prev
expr_stmt|;
name|__first
operator|.
name|_M_node
operator|->
name|_M_prev
operator|=
name|__tmp
expr_stmt|;
block|}
block|}
end_function

begin_comment
unit|};
comment|/**    *  @brief  List equality comparison.    *  @param  x  A %list.    *  @param  y  A %list of the same type as @a x.    *  @return  True iff the size and elements of the lists are equal.    *    *  This is an equivalence relation.  It is linear in the size of the    *  lists.  Lists are considered equivalent if their sizes are equal,    *  and if corresponding elements compare equal.   */
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
comment|/**    *  @brief  List ordering relation.    *  @param  x  A %list.    *  @param  y  A %list of the same type as @a x.    *  @return  True iff @a x is lexographically less than @a y.    *    *  This is a total ordering relation.  It is linear in the size of the    *  lists.  The elements must be comparable with @c<.    *    *  See std::lexographical_compare() for how the determination is made.   */
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
comment|/* __GLIBCPP_INTERNAL_LIST_H */
end_comment

end_unit

