begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Vector implementation -*- C++ -*-
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
comment|/*  *  * Copyright (c) 1994  * Hewlett-Packard Company  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Hewlett-Packard Company makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  *  *  * Copyright (c) 1996  * Silicon Graphics Computer Systems, Inc.  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Silicon Graphics makes no  * representations about the suitability of this  software for any  * purpose.  It is provided "as is" without express or implied warranty.  */
end_comment

begin_comment
comment|/** @file stl_vector.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GLIBCPP_INTERNAL_VECTOR_H
end_ifndef

begin_define
define|#
directive|define
name|__GLIBCPP_INTERNAL_VECTOR_H
end_define

begin_include
include|#
directive|include
file|<bits/stl_iterator_base_funcs.h>
end_include

begin_include
include|#
directive|include
file|<bits/functexcept.h>
end_include

begin_include
include|#
directive|include
file|<bits/concept_check.h>
end_include

begin_decl_stmt
name|namespace
name|std
block|{
comment|/// @if maint Primary default version.  @endif
comment|/**    *  @if maint    *  See bits/stl_deque.h's _Deque_alloc_base for an explanation.    *  @endif   */
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
name|_Vector_alloc_base
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
name|_M_data_allocator
return|;
block|}
name|_Vector_alloc_base
argument_list|(
specifier|const
name|allocator_type
operator|&
name|__a
argument_list|)
operator|:
name|_M_data_allocator
argument_list|(
name|__a
argument_list|)
operator|,
name|_M_start
argument_list|(
literal|0
argument_list|)
operator|,
name|_M_finish
argument_list|(
literal|0
argument_list|)
operator|,
name|_M_end_of_storage
argument_list|(
literal|0
argument_list|)
block|{ }
name|protected
operator|:
name|allocator_type
name|_M_data_allocator
expr_stmt|;
name|_Tp
modifier|*
name|_M_start
decl_stmt|;
name|_Tp
modifier|*
name|_M_finish
decl_stmt|;
name|_Tp
modifier|*
name|_M_end_of_storage
decl_stmt|;
name|_Tp
modifier|*
name|_M_allocate
parameter_list|(
name|size_t
name|__n
parameter_list|)
block|{
return|return
name|_M_data_allocator
operator|.
name|allocate
argument_list|(
name|__n
argument_list|)
return|;
block|}
name|void
name|_M_deallocate
parameter_list|(
name|_Tp
modifier|*
name|__p
parameter_list|,
name|size_t
name|__n
parameter_list|)
block|{
if|if
condition|(
name|__p
condition|)
name|_M_data_allocator
operator|.
name|deallocate
argument_list|(
name|__p
argument_list|,
name|__n
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
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
name|_Vector_alloc_base
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
name|_Vector_alloc_base
argument_list|(
specifier|const
name|allocator_type
operator|&
argument_list|)
operator|:
name|_M_start
argument_list|(
literal|0
argument_list|)
operator|,
name|_M_finish
argument_list|(
literal|0
argument_list|)
operator|,
name|_M_end_of_storage
argument_list|(
literal|0
argument_list|)
block|{ }
name|protected
operator|:
name|_Tp
operator|*
name|_M_start
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|_Tp
modifier|*
name|_M_finish
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|_Tp
modifier|*
name|_M_end_of_storage
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|typename
name|_Alloc_traits
operator|<
name|_Tp
operator|,
name|_Allocator
operator|>
operator|::
name|_Alloc_type
name|_Alloc_type
expr_stmt|;
end_typedef

begin_function
name|_Tp
modifier|*
name|_M_allocate
parameter_list|(
name|size_t
name|__n
parameter_list|)
block|{
return|return
name|_Alloc_type
operator|::
name|allocate
argument_list|(
name|__n
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|_M_deallocate
parameter_list|(
name|_Tp
modifier|*
name|__p
parameter_list|,
name|size_t
name|__n
parameter_list|)
block|{
name|_Alloc_type
operator|::
name|deallocate
argument_list|(
name|__p
argument_list|,
name|__n
argument_list|)
expr_stmt|;
block|}
end_function

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
expr|struct
name|_Vector_base
operator|:
name|public
name|_Vector_alloc_base
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
name|_Vector_alloc_base
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
name|_Vector_base
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
block|{ }
name|_Vector_base
argument_list|(
argument|size_t __n
argument_list|,
argument|const allocator_type& __a
argument_list|)
operator|:
name|_Base
argument_list|(
argument|__a
argument_list|)
block|{
name|_M_start
operator|=
name|_M_allocate
argument_list|(
name|__n
argument_list|)
block|;
name|_M_finish
operator|=
name|_M_start
block|;
name|_M_end_of_storage
operator|=
name|_M_start
operator|+
name|__n
block|;       }
operator|~
name|_Vector_base
argument_list|()
block|{
name|_M_deallocate
argument_list|(
name|_M_start
argument_list|,
name|_M_end_of_storage
operator|-
name|_M_start
argument_list|)
block|; }
end_expr_stmt

begin_comment
unit|};
comment|/**    *  @brief  A standard container which offers fixed time access to individual    *  elements in any order.    *    *  @ingroup Containers    *  @ingroup Sequences    *    *  Meets the requirements of a<a href="tables.html#65">container</a>, a    *<a href="tables.html#66">reversible container</a>, and a    *<a href="tables.html#67">sequence</a>, including the    *<a href="tables.html#68">optional sequence requirements</a> with the    *  %exception of @c push_front and @c pop_front.    *    *  In some terminology a %vector can be described as a dynamic C-style array,    *  it offers fast and efficient access to individual elements in any order    *  and saves the user from worrying about memory and size allocation.    *  Subscripting ( @c [] ) access is also provided as with C-style arrays.   */
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
name|vector
operator|:
name|protected
name|_Vector_base
operator|<
name|_Tp
operator|,
name|_Alloc
operator|>
block|{
comment|// Concept requirements.
name|__glibcpp_class_requires
argument_list|(
argument|_Tp
argument_list|,
argument|_SGIAssignableConcept
argument_list|)
typedef|typedef
name|_Vector_base
operator|<
name|_Tp
operator|,
name|_Alloc
operator|>
name|_Base
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|vector
operator|<
name|_Tp
operator|,
name|_Alloc
operator|>
name|vector_type
expr_stmt|;
end_typedef

begin_label
name|public
label|:
end_label

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
name|__gnu_cxx
operator|::
name|__normal_iterator
operator|<
name|pointer
operator|,
name|vector_type
operator|>
name|iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|__gnu_cxx
operator|::
name|__normal_iterator
operator|<
name|const_pointer
operator|,
name|vector_type
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
comment|/** @if maint        *  These two functions and three data members are all from the        *  top-most base class, which varies depending on the type of        *  %allocator.  They should be pretty self-explanatory, as        *  %vector uses a simple contiguous allocation scheme.  @endif        */
end_comment

begin_expr_stmt
name|using
name|_Base
operator|::
name|_M_allocate
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|_Base
operator|::
name|_M_deallocate
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|_Base
operator|::
name|_M_start
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|_Base
operator|::
name|_M_finish
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|_Base
operator|::
name|_M_end_of_storage
expr_stmt|;
end_expr_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|// [23.2.4.1] construct/copy/destroy
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
name|vector
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
comment|/**        *  @brief  Create a %vector with copies of an exemplar element.        *  @param  n  The number of elements to initially create.        *  @param  value  An element to copy.        *         *  This constructor fills the %vector with @a n copies of @a value.        */
name|vector
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
argument|__n
argument_list|,
argument|__a
argument_list|)
block|{
name|_M_finish
operator|=
name|uninitialized_fill_n
argument_list|(
name|_M_start
argument_list|,
name|__n
argument_list|,
name|__value
argument_list|)
block|; }
comment|/**        *  @brief  Create a %vector with default elements.        *  @param  n  The number of elements to initially create.        *         *  This constructor fills the %vector with @a n copies of a        *  default-constructed element.        */
name|explicit
name|vector
argument_list|(
argument|size_type __n
argument_list|)
operator|:
name|_Base
argument_list|(
argument|__n
argument_list|,
argument|allocator_type()
argument_list|)
block|{
name|_M_finish
operator|=
name|uninitialized_fill_n
argument_list|(
name|_M_start
argument_list|,
name|__n
argument_list|,
name|value_type
argument_list|()
argument_list|)
block|; }
comment|/**        *  @brief  %Vector copy constructor.        *  @param  x  A %vector of identical element and allocator types.        *         *  The newly-created %vector uses a copy of the allocation        *  object used by @a x.  All the elements of @a x are copied,        *  but any extra memory in        *  @a x (for fast expansion) will not be copied.        */
name|vector
argument_list|(
specifier|const
name|vector
operator|&
name|__x
argument_list|)
operator|:
name|_Base
argument_list|(
argument|__x.size()
argument_list|,
argument|__x.get_allocator()
argument_list|)
block|{
name|_M_finish
operator|=
name|uninitialized_copy
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
name|_M_start
argument_list|)
block|; }
comment|/**        *  @brief  Builds a %vector from a range.        *  @param  first  An input iterator.        *  @param  last  An input iterator.        *         *  Create a %vector consisting of copies of the elements from        *  [first,last).        *        *  If the iterators are forward, bidirectional, or random-access, then        *  this will call the elements' copy constructor N times (where N is        *  distance(first,last)) and do no memory reallocation.  But if only        *  input iterators are used, then this will do at most 2N calls to the        *  copy constructor, and logN memory reallocations.        */
name|template
operator|<
name|typename
name|_InputIterator
operator|>
name|vector
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
name|_M_initialize_dispatch
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
comment|/**        *  The dtor only erases the elements, and note that if the elements        *  themselves are pointers, the pointed-to memory is not touched in any        *  way.  Managing the pointer is the user's responsibilty.        */
end_comment

begin_macro
unit|~
name|vector
argument_list|()
end_macro

begin_block
block|{
name|_Destroy
argument_list|(
name|_M_start
argument_list|,
name|_M_finish
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/**        *  @brief  %Vector assignment operator.        *  @param  x  A %vector of identical element and allocator types.        *         *  All the elements of @a x are copied, but any extra memory in        *  @a x (for fast expansion) will not be copied.  Unlike the        *  copy constructor, the allocator object is not copied.        */
end_comment

begin_decl_stmt
name|vector
modifier|&
name|operator
init|=
operator|(
specifier|const
name|vector
operator|&
name|__x
operator|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**        *  @brief  Assigns a given value to a %vector.        *  @param  n  Number of elements to be assigned.        *  @param  val  Value to be assigned.        *        *  This function fills a %vector with @a n copies of the given        *  value.  Note that the assignment completely changes the        *  %vector and that the resulting %vector's size is the same as        *  the number of elements assigned.  Old data may be lost.        */
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
comment|/**        *  @brief  Assigns a range to a %vector.        *  @param  first  An input iterator.        *  @param  last   An input iterator.        *        *  This function fills a %vector with copies of the elements in the        *  range [first,last).        *        *  Note that the assignment completely changes the %vector and        *  that the resulting %vector's size is the same as the number        *  of elements assigned.  Old data may be lost.        */
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
comment|/**        *  Returns a read/write iterator that points to the first element in the        *  %vector.  Iteration is done in ordinary element order.        */
end_comment

begin_function
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|iterator
argument_list|(
name|_M_start
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**        *  Returns a read-only (constant) iterator that points to the        *  first element in the %vector.  Iteration is done in ordinary        *  element order.        */
end_comment

begin_expr_stmt
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|const_iterator
argument_list|(
name|_M_start
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  Returns a read/write iterator that points one past the last        *  element in the %vector.  Iteration is done in ordinary        *  element order.        */
end_comment

begin_function
name|iterator
name|end
parameter_list|()
block|{
return|return
name|iterator
argument_list|(
name|_M_finish
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**        *  Returns a read-only (constant) iterator that points one past the last        *  element in the %vector.  Iteration is done in ordinary element order.        */
end_comment

begin_expr_stmt
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|const_iterator
argument_list|(
name|_M_finish
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  Returns a read/write reverse iterator that points to the        *  last element in the %vector.  Iteration is done in reverse        *  element order.        */
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
comment|/**        *  Returns a read-only (constant) reverse iterator that points        *  to the last element in the %vector.  Iteration is done in        *  reverse element order.        */
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
comment|/**        *  Returns a read/write reverse iterator that points to one before the        *  first element in the %vector.  Iteration is done in reverse element        *  order.        */
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
comment|/**        *  Returns a read-only (constant) reverse iterator that points        *  to one before the first element in the %vector.  Iteration        *  is done in reverse element order.        */
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
comment|// [23.2.4.2] capacity
end_comment

begin_comment
comment|/**  Returns the number of elements in the %vector.  */
end_comment

begin_expr_stmt
name|size_type
name|size
argument_list|()
specifier|const
block|{
return|return
name|size_type
argument_list|(
name|end
argument_list|()
operator|-
name|begin
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/**  Returns the size() of the largest possible %vector.  */
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
operator|/
sizeof|sizeof
argument_list|(
name|value_type
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Resizes the %vector to the specified number of elements.        *  @param  new_size  Number of elements the %vector should contain.        *  @param  x  Data with which new elements should be populated.        *        *  This function will %resize the %vector to the specified        *  number of elements.  If the number is smaller than the        *  %vector's current size the %vector is truncated, otherwise        *  the %vector is extended and new elements are populated with        *  given data.        */
end_comment

begin_function
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
block|{
if|if
condition|(
name|__new_size
operator|<
name|size
argument_list|()
condition|)
name|erase
argument_list|(
name|begin
argument_list|()
operator|+
name|__new_size
argument_list|,
name|end
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|insert
argument_list|(
name|end
argument_list|()
argument_list|,
name|__new_size
operator|-
name|size
argument_list|()
argument_list|,
name|__x
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**        *  @brief  Resizes the %vector to the specified number of elements.        *  @param  new_size  Number of elements the %vector should contain.        *        *  This function will resize the %vector to the specified        *  number of elements.  If the number is smaller than the        *  %vector's current size the %vector is truncated, otherwise        *  the %vector is extended and new elements are        *  default-constructed.        */
end_comment

begin_function
name|void
name|resize
parameter_list|(
name|size_type
name|__new_size
parameter_list|)
block|{
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
comment|/**        *  Returns the total number of elements that the %vector can hold before        *  needing to allocate more memory.        */
end_comment

begin_expr_stmt
name|size_type
name|capacity
argument_list|()
specifier|const
block|{
return|return
name|size_type
argument_list|(
name|const_iterator
argument_list|(
name|_M_end_of_storage
argument_list|)
operator|-
name|begin
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  Returns true if the %vector is empty.  (Thus begin() would        *  equal end().)        */
end_comment

begin_expr_stmt
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|begin
argument_list|()
operator|==
name|end
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/**        *  @brief  Attempt to preallocate enough memory for specified number of        *          elements.        *  @param  n  Number of elements required.        *  @throw  std::length_error  If @a n exceeds @c max_size().        *        *  This function attempts to reserve enough memory for the        *  %vector to hold the specified number of elements.  If the        *  number requested is more than max_size(), length_error is        *  thrown.        *        *  The advantage of this function is that if optimal code is a        *  necessity and the user can determine the number of elements        *  that will be required, the user can reserve the memory in        *  %advance, and thus prevent a possible reallocation of memory        *  and copying of %vector data.        */
end_comment

begin_function_decl
name|void
name|reserve
parameter_list|(
name|size_type
name|__n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// element access
end_comment

begin_comment
comment|/**        *  @brief  Subscript access to the data contained in the %vector.        *  @param  n  The index of the element for which data should be accessed.        *  @return  Read/write reference to data.        *        *  This operator allows for easy, array-style, data access.        *  Note that data access with this operator is unchecked and        *  out_of_range lookups are not defined. (For checked lookups        *  see at().)        */
end_comment

begin_function
name|reference
name|operator
function|[]
parameter_list|(
name|size_type
name|__n
parameter_list|)
block|{
return|return
operator|*
operator|(
name|begin
argument_list|()
operator|+
name|__n
operator|)
return|;
block|}
end_function

begin_comment
comment|/**        *  @brief  Subscript access to the data contained in the %vector.        *  @param n The index of the element for which data should be        *  accessed.        *  @return  Read-only (constant) reference to data.        *        *  This operator allows for easy, array-style, data access.        *  Note that data access with this operator is unchecked and        *  out_of_range lookups are not defined. (For checked lookups        *  see at().)        */
end_comment

begin_decl_stmt
name|const_reference
name|operator
index|[]
argument_list|(
name|size_type
name|__n
argument_list|)
decl|const
block|{
return|return
operator|*
operator|(
name|begin
argument_list|()
operator|+
name|__n
operator|)
return|;
block|}
end_decl_stmt

begin_label
name|protected
label|:
end_label

begin_comment
comment|/// @if maint Safety check used only from at().  @endif
end_comment

begin_decl_stmt
name|void
name|_M_range_check
argument_list|(
name|size_type
name|__n
argument_list|)
decl|const
block|{
if|if
condition|(
name|__n
operator|>=
name|this
operator|->
name|size
argument_list|()
condition|)
name|__throw_out_of_range
argument_list|(
literal|"vector [] access out of range"
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|/**        *  @brief  Provides access to the data contained in the %vector.        *  @param n The index of the element for which data should be        *  accessed.        *  @return  Read/write reference to data.        *  @throw  std::out_of_range  If @a n is an invalid index.        *        *  This function provides for safer data access.  The parameter is first        *  checked that it is in the range of the vector.  The function throws        *  out_of_range if the check fails.        */
end_comment

begin_function
name|reference
name|at
parameter_list|(
name|size_type
name|__n
parameter_list|)
block|{
name|_M_range_check
argument_list|(
name|__n
argument_list|)
expr_stmt|;
return|return
operator|(
operator|*
name|this
operator|)
index|[
name|__n
index|]
return|;
block|}
end_function

begin_comment
comment|/**        *  @brief  Provides access to the data contained in the %vector.        *  @param n The index of the element for which data should be        *  accessed.        *  @return  Read-only (constant) reference to data.        *  @throw  std::out_of_range  If @a n is an invalid index.        *        *  This function provides for safer data access.  The parameter        *  is first checked that it is in the range of the vector.  The        *  function throws out_of_range if the check fails.        */
end_comment

begin_decl_stmt
name|const_reference
name|at
argument_list|(
name|size_type
name|__n
argument_list|)
decl|const
block|{
name|_M_range_check
argument_list|(
name|__n
argument_list|)
expr_stmt|;
return|return
operator|(
operator|*
name|this
operator|)
index|[
name|__n
index|]
return|;
block|}
end_decl_stmt

begin_comment
comment|/**        *  Returns a read/write reference to the data at the first        *  element of the %vector.        */
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
comment|/**        *  Returns a read-only (constant) reference to the data at the first        *  element of the %vector.        */
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
comment|/**        *  Returns a read/write reference to the data at the last element of the        *  %vector.        */
end_comment

begin_function
name|reference
name|back
parameter_list|()
block|{
return|return
operator|*
operator|(
name|end
argument_list|()
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/**        *  Returns a read-only (constant) reference to the data at the last        *  element of the %vector.        */
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
name|end
argument_list|()
operator|-
literal|1
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// [23.2.4.3] modifiers
end_comment

begin_comment
comment|/**        *  @brief  Add data to the end of the %vector.        *  @param  x  Data to be added.        *        *  This is a typical stack operation.  The function creates an        *  element at the end of the %vector and assigns the given data        *  to it.  Due to the nature of a %vector this operation can be        *  done in constant time if the %vector has preallocated space        *  available.        */
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
if|if
condition|(
name|_M_finish
operator|!=
name|_M_end_of_storage
condition|)
block|{
name|_Construct
argument_list|(
name|_M_finish
argument_list|,
name|__x
argument_list|)
expr_stmt|;
operator|++
name|_M_finish
expr_stmt|;
block|}
else|else
name|_M_insert_aux
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
comment|/**        *  @brief  Removes last element.        *        *  This is a typical stack operation. It shrinks the %vector by one.        *        *  Note that no data is returned, and if the last element's data is        *  needed, it should be retrieved before pop_back() is called.        */
end_comment

begin_function
name|void
name|pop_back
parameter_list|()
block|{
operator|--
name|_M_finish
expr_stmt|;
name|_Destroy
argument_list|(
name|_M_finish
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**        *  @brief  Inserts given value into %vector before specified iterator.        *  @param  position  An iterator into the %vector.        *  @param  x  Data to be inserted.        *  @return  An iterator that points to the inserted data.        *        *  This function will insert a copy of the given value before        *  the specified location.  Note that this kind of operation        *  could be expensive for a %vector and if it is frequently        *  used the user should consider using std::list.        */
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
comment|/**        *  @brief  Inserts an element into the %vector.        *  @param  position  An iterator into the %vector.        *  @return  An iterator that points to the inserted element.        *        *  This function will insert a default-constructed element        *  before the specified location.  You should consider using        *  insert(position,value_type()) instead.  Note that this kind        *  of operation could be expensive for a vector and if it is        *  frequently used the user should consider using std::list.        *        *  @note This was deprecated in 3.2 and will be removed in 3.4.        *  You must define @c _GLIBCPP_DEPRECATED to make this visible        *  in 3.2; see c++config.h.        */
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
comment|/**        *  @brief  Inserts a number of copies of given data into the %vector.        *  @param  position  An iterator into the %vector.        *  @param  n  Number of elements to be inserted.        *  @param  x  Data to be inserted.        *        *  This function will insert a specified number of copies of        *  the given data before the location specified by @a position.        *        *  Note that this kind of operation could be expensive for a        *  %vector and if it is frequently used the user should        *  consider using std::list.        */
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
comment|/**        *  @brief  Inserts a range into the %vector.        *  @param  pos  An iterator into the %vector.        *  @param  first  An input iterator.        *  @param  last   An input iterator.        *        *  This function will insert copies of the data in the range        *  [first,last) into the %vector before the location specified        *  by @a pos.        *        *  Note that this kind of operation could be expensive for a        *  %vector and if it is frequently used the user should        *  consider using std::list.        */
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
comment|/**        *  @brief  Remove element at given position.        *  @param  position  Iterator pointing to element to be erased.        *  @return  An iterator pointing to the next element (or end()).        *        *  This function will erase the element at the given position and thus        *  shorten the %vector by one.        *        *  Note This operation could be expensive and if it is        *  frequently used the user should consider using std::list.        *  The user is also cautioned that this function only erases        *  the element, and that if the element is itself a pointer,        *  the pointed-to memory is not touched in any way.  Managing        *  the pointer is the user's responsibilty.        */
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
comment|/**        *  @brief  Remove a range of elements.        *  @param  first  Iterator pointing to the first element to be erased.        *  @param  last  Iterator pointing to one past the last element to be        *                erased.        *  @return  An iterator pointing to the element pointed to by @a last        *           prior to erasing (or end()).        *        *  This function will erase the elements in the range [first,last) and        *  shorten the %vector accordingly.        *        *  Note This operation could be expensive and if it is        *  frequently used the user should consider using std::list.        *  The user is also cautioned that this function only erases        *  the elements, and that if the elements themselves are        *  pointers, the pointed-to memory is not touched in any way.        *  Managing the pointer is the user's responsibilty.        */
end_comment

begin_function_decl
name|iterator
name|erase
parameter_list|(
name|iterator
name|__first
parameter_list|,
name|iterator
name|__last
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**        *  @brief  Swaps data with another %vector.        *  @param  x  A %vector of the same element and allocator types.        *        *  This exchanges the elements between two vectors in constant time.        *  (Three pointers, so it should be quite fast.)        *  Note that the global std::swap() function is specialized such that        *  std::swap(v1,v2) will feed to this function.        */
end_comment

begin_function
name|void
name|swap
parameter_list|(
name|vector
modifier|&
name|__x
parameter_list|)
block|{
name|std
operator|::
name|swap
argument_list|(
name|_M_start
argument_list|,
name|__x
operator|.
name|_M_start
argument_list|)
expr_stmt|;
name|std
operator|::
name|swap
argument_list|(
name|_M_finish
argument_list|,
name|__x
operator|.
name|_M_finish
argument_list|)
expr_stmt|;
name|std
operator|::
name|swap
argument_list|(
name|_M_end_of_storage
argument_list|,
name|__x
operator|.
name|_M_end_of_storage
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**        *  Erases all the elements.  Note that this function only erases the        *  elements, and that if the elements themselves are pointers, the        *  pointed-to memory is not touched in any way.  Managing the pointer is        *  the user's responsibilty.        */
end_comment

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

begin_label
name|protected
label|:
end_label

begin_comment
comment|/**        *  @if maint        *  Memory expansion handler.  Uses the member allocation function to        *  obtain @a n bytes of memory, and then copies [first,last) into it.        *  @endif        */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_ForwardIterator
operator|>
name|pointer
name|_M_allocate_and_copy
argument_list|(
argument|size_type __n
argument_list|,
argument|_ForwardIterator __first
argument_list|,
argument|_ForwardIterator __last
argument_list|)
block|{
name|pointer
name|__result
operator|=
name|_M_allocate
argument_list|(
name|__n
argument_list|)
block|;
name|try
block|{
name|uninitialized_copy
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__result
argument_list|)
block|;
return|return
name|__result
return|;
block|}
name|catch
argument_list|(
argument|...
argument_list|)
block|{
name|_M_deallocate
argument_list|(
name|__result
argument_list|,
name|__n
argument_list|)
block|;
name|__throw_exception_again
block|; 	    }
end_expr_stmt

begin_comment
unit|}
comment|// Internal constructor functions follow.
end_comment

begin_comment
comment|// Called by the range constructor to implement [23.1.1]/9
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_Integer
operator|>
name|void
name|_M_initialize_dispatch
argument_list|(
argument|_Integer __n
argument_list|,
argument|_Integer __value
argument_list|,
argument|__true_type
argument_list|)
block|{
name|_M_start
operator|=
name|_M_allocate
argument_list|(
name|__n
argument_list|)
block|;
name|_M_end_of_storage
operator|=
name|_M_start
operator|+
name|__n
block|;
name|_M_finish
operator|=
name|uninitialized_fill_n
argument_list|(
name|_M_start
argument_list|,
name|__n
argument_list|,
name|__value
argument_list|)
block|; 	}
comment|// Called by the range constructor to implement [23.1.1]/9
name|template
operator|<
name|typename
name|_InputIter
operator|>
name|void
name|_M_initialize_dispatch
argument_list|(
argument|_InputIter __first
argument_list|,
argument|_InputIter __last
argument_list|,
argument|__false_type
argument_list|)
block|{
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_InputIter
operator|>
operator|::
name|iterator_category
name|_IterCategory
expr_stmt|;
name|_M_range_initialize
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|_IterCategory
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// Called by the second initialize_dispatch above
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_InputIterator
operator|>
name|void
name|_M_range_initialize
argument_list|(
argument|_InputIterator __first
argument_list|,
argument|_InputIterator __last
argument_list|,
argument|input_iterator_tag
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
name|push_back
argument_list|(
operator|*
name|__first
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_comment
comment|// Called by the second initialize_dispatch above
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_ForwardIterator
operator|>
name|void
name|_M_range_initialize
argument_list|(
argument|_ForwardIterator __first
argument_list|,
argument|_ForwardIterator __last
argument_list|,
argument|forward_iterator_tag
argument_list|)
block|{
name|size_type
name|__n
operator|=
name|distance
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|)
block|;
name|_M_start
operator|=
name|_M_allocate
argument_list|(
name|__n
argument_list|)
block|;
name|_M_end_of_storage
operator|=
name|_M_start
operator|+
name|__n
block|;
name|_M_finish
operator|=
name|uninitialized_copy
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|_M_start
argument_list|)
block|; 	}
comment|// Internal assign functions follow.  The *_aux functions do the actual
comment|// assignment work for the range versions.
comment|// Called by the range assign to implement [23.1.1]/9
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
block|{
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_InputIter
operator|>
operator|::
name|iterator_category
name|_IterCategory
expr_stmt|;
name|_M_assign_aux
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|_IterCategory
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// Called by the second assign_dispatch above
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_InputIterator
operator|>
name|void
name|_M_assign_aux
argument_list|(
argument|_InputIterator __first
argument_list|,
argument|_InputIterator __last
argument_list|,
argument|input_iterator_tag
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Called by the second assign_dispatch above
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_ForwardIterator
operator|>
name|void
name|_M_assign_aux
argument_list|(
argument|_ForwardIterator __first
argument_list|,
argument|_ForwardIterator __last
argument_list|,
argument|forward_iterator_tag
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
argument|_Integer __val
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
name|__val
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
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_InputIterator
operator|>
operator|::
name|iterator_category
name|_IterCategory
expr_stmt|;
name|_M_range_insert
argument_list|(
name|__pos
argument_list|,
name|__first
argument_list|,
name|__last
argument_list|,
name|_IterCategory
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// Called by the second insert_dispatch above
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_InputIterator
operator|>
name|void
name|_M_range_insert
argument_list|(
argument|iterator __pos
argument_list|,
argument|_InputIterator __first
argument_list|,
argument|_InputIterator __last
argument_list|,
argument|input_iterator_tag
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Called by the second insert_dispatch above
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_ForwardIterator
operator|>
name|void
name|_M_range_insert
argument_list|(
argument|iterator __pos
argument_list|,
argument|_ForwardIterator __first
argument_list|,
argument|_ForwardIterator __last
argument_list|,
argument|forward_iterator_tag
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Called by insert(p,n,x), and the range insert when it turns out to be
end_comment

begin_comment
comment|// the same thing.
end_comment

begin_function_decl
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
function_decl|;
end_function_decl

begin_comment
comment|// Called by insert(p,x)
end_comment

begin_function_decl
name|void
name|_M_insert_aux
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
comment|// Unused now (same situation as in deque)
end_comment

begin_function_decl
name|void
name|_M_insert_aux
parameter_list|(
name|iterator
name|__position
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
unit|};
comment|/**    *  @brief  Vector equality comparison.    *  @param  x  A %vector.    *  @param  y  A %vector of the same type as @a x.    *  @return  True iff the size and elements of the vectors are equal.    *    *  This is an equivalence relation.  It is linear in the size of the    *  vectors.  Vectors are considered equivalent if their sizes are equal,    *  and if corresponding elements compare equal.   */
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
name|vector
operator|<
name|_Tp
operator|,
name|_Alloc
operator|>
operator|&
name|__x
operator|,
specifier|const
name|vector
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
name|__x
operator|.
name|size
argument_list|()
operator|==
name|__y
operator|.
name|size
argument_list|()
operator|&&
name|equal
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
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/**    *  @brief  Vector ordering relation.    *  @param  x  A %vector.    *  @param  y  A %vector of the same type as @a x.    *  @return  True iff @a x is lexographically less than @a y.    *    *  This is a total ordering relation.  It is linear in the size of the    *  vectors.  The elements must be comparable with @c<.    *    *  See std::lexographical_compare() for how the determination is made.   */
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
operator|<
operator|(
specifier|const
name|vector
operator|<
name|_Tp
operator|,
name|_Alloc
operator|>
operator|&
name|__x
operator|,
specifier|const
name|vector
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
name|vector
operator|<
name|_Tp
operator|,
name|_Alloc
operator|>
operator|&
name|__x
operator|,
specifier|const
name|vector
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
name|vector
operator|<
name|_Tp
operator|,
name|_Alloc
operator|>
operator|&
name|__x
operator|,
specifier|const
name|vector
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
name|vector
operator|<
name|_Tp
operator|,
name|_Alloc
operator|>
operator|&
name|__x
operator|,
specifier|const
name|vector
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
name|vector
operator|<
name|_Tp
operator|,
name|_Alloc
operator|>
operator|&
name|__x
operator|,
specifier|const
name|vector
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
comment|/// See std::vector::swap().
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
argument|vector<_Tp
argument_list|,
argument|_Alloc>& __x
argument_list|,
argument|vector<_Tp
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
comment|/* __GLIBCPP_INTERNAL_VECTOR_H */
end_comment

end_unit

