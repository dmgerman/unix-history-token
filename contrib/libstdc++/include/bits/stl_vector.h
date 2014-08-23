begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Vector implementation -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2001, 2002, 2003, 2004, 2005, 2006
end_comment

begin_comment
comment|// Free Software Foundation, Inc.
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
comment|// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,
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
name|_VECTOR_H
end_ifndef

begin_define
define|#
directive|define
name|_VECTOR_H
value|1
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

begin_macro
name|_GLIBCXX_BEGIN_NESTED_NAMESPACE
argument_list|(
argument|std
argument_list|,
argument|_GLIBCXX_STD
argument_list|)
end_macro

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
expr|struct
name|_Vector_base
block|{
typedef|typedef
name|typename
name|_Alloc
operator|::
name|template
name|rebind
operator|<
name|_Tp
operator|>
operator|::
name|other
name|_Tp_alloc_type
expr_stmt|;
block|struct
name|_Vector_impl
operator|:
name|public
name|_Tp_alloc_type
block|{
name|_Tp
operator|*
name|_M_start
block|;
name|_Tp
operator|*
name|_M_finish
block|;
name|_Tp
operator|*
name|_M_end_of_storage
block|;
name|_Vector_impl
argument_list|()
operator|:
name|_Tp_alloc_type
argument_list|()
block|,
name|_M_start
argument_list|(
literal|0
argument_list|)
block|,
name|_M_finish
argument_list|(
literal|0
argument_list|)
block|,
name|_M_end_of_storage
argument_list|(
literal|0
argument_list|)
block|{ }
name|_Vector_impl
argument_list|(
name|_Tp_alloc_type
specifier|const
operator|&
name|__a
argument_list|)
operator|:
name|_Tp_alloc_type
argument_list|(
name|__a
argument_list|)
block|,
name|_M_start
argument_list|(
literal|0
argument_list|)
block|,
name|_M_finish
argument_list|(
literal|0
argument_list|)
block|,
name|_M_end_of_storage
argument_list|(
literal|0
argument_list|)
block|{ }
block|}
expr_stmt|;
end_expr_stmt

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

begin_function
name|_Tp_alloc_type
modifier|&
name|_M_get_Tp_allocator
parameter_list|()
block|{
return|return
operator|*
name|static_cast
operator|<
name|_Tp_alloc_type
operator|*
operator|>
operator|(
operator|&
name|this
operator|->
name|_M_impl
operator|)
return|;
block|}
end_function

begin_expr_stmt
specifier|const
name|_Tp_alloc_type
operator|&
name|_M_get_Tp_allocator
argument_list|()
specifier|const
block|{
return|return
operator|*
name|static_cast
operator|<
specifier|const
name|_Tp_alloc_type
operator|*
operator|>
operator|(
operator|&
name|this
operator|->
name|_M_impl
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|allocator_type
name|get_allocator
argument_list|()
specifier|const
block|{
return|return
name|allocator_type
argument_list|(
name|_M_get_Tp_allocator
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|_Vector_base
argument_list|()
operator|:
name|_M_impl
argument_list|()
block|{ }
name|_Vector_base
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
block|{ }
name|_Vector_base
argument_list|(
argument|size_t __n
argument_list|,
argument|const allocator_type& __a
argument_list|)
operator|:
name|_M_impl
argument_list|(
argument|__a
argument_list|)
block|{
if|if
condition|(
name|__n
condition|)
block|{
name|this
operator|->
name|_M_impl
operator|.
name|_M_start
operator|=
name|this
operator|->
name|_M_allocate
argument_list|(
name|__n
argument_list|)
expr_stmt|;
name|this
operator|->
name|_M_impl
operator|.
name|_M_finish
operator|=
name|this
operator|->
name|_M_impl
operator|.
name|_M_start
expr_stmt|;
name|this
operator|->
name|_M_impl
operator|.
name|_M_end_of_storage
operator|=
name|this
operator|->
name|_M_impl
operator|.
name|_M_start
operator|+
name|__n
expr_stmt|;
block|}
end_expr_stmt

begin_macro
unit|}        ~
name|_Vector_base
argument_list|()
end_macro

begin_block
block|{
name|_M_deallocate
argument_list|(
name|this
operator|->
name|_M_impl
operator|.
name|_M_start
argument_list|,
name|this
operator|->
name|_M_impl
operator|.
name|_M_end_of_storage
operator|-
name|this
operator|->
name|_M_impl
operator|.
name|_M_start
argument_list|)
expr_stmt|;
block|}
end_block

begin_label
name|public
label|:
end_label

begin_decl_stmt
name|_Vector_impl
name|_M_impl
decl_stmt|;
end_decl_stmt

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
name|_M_impl
operator|.
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
if|if
condition|(
name|__p
condition|)
name|_M_impl
operator|.
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
comment|/**    *  @brief A standard container which offers fixed time access to    *  individual elements in any order.    *    *  @ingroup Containers    *  @ingroup Sequences    *    *  Meets the requirements of a<a href="tables.html#65">container</a>, a    *<a href="tables.html#66">reversible container</a>, and a    *<a href="tables.html#67">sequence</a>, including the    *<a href="tables.html#68">optional sequence requirements</a> with the    *  %exception of @c push_front and @c pop_front.    *    *  In some terminology a %vector can be described as a dynamic    *  C-style array, it offers fast and efficient access to individual    *  elements in any order and saves the user from worrying about    *  memory and size allocation.  Subscripting ( @c [] ) access is    *  also provided as with C-style arrays.   */
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
name|std
operator|::
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
typedef|typedef
name|typename
name|_Alloc
operator|::
name|value_type
name|_Alloc_value_type
expr_stmt|;
name|__glibcxx_class_requires
argument_list|(
argument|_Tp
argument_list|,
argument|_SGIAssignableConcept
argument_list|)
name|__glibcxx_class_requires2
argument_list|(
argument|_Tp
argument_list|,
argument|_Alloc_value_type
argument_list|,
argument|_SameTypeConcept
argument_list|)
end_expr_stmt

begin_typedef
typedef|typedef
name|_Vector_base
operator|<
name|_Tp
operator|,
name|_Alloc
operator|>
name|_Base
expr_stmt|;
end_typedef

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

begin_typedef
typedef|typedef
name|typename
name|_Base
operator|::
name|_Tp_alloc_type
name|_Tp_alloc_type
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
name|typename
name|_Tp_alloc_type
operator|::
name|pointer
name|pointer
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|_Tp_alloc_type
operator|::
name|const_pointer
name|const_pointer
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|_Tp_alloc_type
operator|::
name|reference
name|reference
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|_Tp_alloc_type
operator|::
name|const_reference
name|const_reference
expr_stmt|;
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
name|_Alloc
name|allocator_type
typedef|;
end_typedef

begin_label
name|protected
label|:
end_label

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
name|_M_impl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|_Base
operator|::
name|_M_get_Tp_allocator
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

begin_expr_stmt
name|vector
argument_list|()
operator|:
name|_Base
argument_list|()
block|{ }
name|explicit
name|vector
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
comment|/**        *  @brief  Create a %vector with copies of an exemplar element.        *  @param  n  The number of elements to initially create.        *  @param  value  An element to copy.        *        *  This constructor fills the %vector with @a n copies of @a value.        */
name|explicit
name|vector
argument_list|(
argument|size_type __n
argument_list|,
argument|const value_type& __value = value_type()
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
name|std
operator|::
name|__uninitialized_fill_n_a
argument_list|(
name|this
operator|->
name|_M_impl
operator|.
name|_M_start
argument_list|,
name|__n
argument_list|,
name|__value
argument_list|,
name|_M_get_Tp_allocator
argument_list|()
argument_list|)
block|;
name|this
operator|->
name|_M_impl
operator|.
name|_M_finish
operator|=
name|this
operator|->
name|_M_impl
operator|.
name|_M_start
operator|+
name|__n
block|;       }
comment|/**        *  @brief  %Vector copy constructor.        *  @param  x  A %vector of identical element and allocator types.        *        *  The newly-created %vector uses a copy of the allocation        *  object used by @a x.  All the elements of @a x are copied,        *  but any extra memory in        *  @a x (for fast expansion) will not be copied.        */
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
argument|__x._M_get_Tp_allocator()
argument_list|)
block|{
name|this
operator|->
name|_M_impl
operator|.
name|_M_finish
operator|=
name|std
operator|::
name|__uninitialized_copy_a
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
name|this
operator|->
name|_M_impl
operator|.
name|_M_start
argument_list|,
name|_M_get_Tp_allocator
argument_list|()
argument_list|)
block|;       }
comment|/**        *  @brief  Builds a %vector from a range.        *  @param  first  An input iterator.        *  @param  last  An input iterator.        *        *  Create a %vector consisting of copies of the elements from        *  [first,last).        *        *  If the iterators are forward, bidirectional, or        *  random-access, then this will call the elements' copy        *  constructor N times (where N is distance(first,last)) and do        *  no memory reallocation.  But if only input iterators are        *  used, then this will do at most 2N calls to the copy        *  constructor, and logN memory reallocations.        */
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
name|std
operator|::
name|__is_integer
operator|<
name|_InputIterator
operator|>
operator|::
name|__type
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
comment|/**        *  The dtor only erases the elements, and note that if the        *  elements themselves are pointers, the pointed-to memory is        *  not touched in any way.  Managing the pointer is the user's        *  responsibilty.        */
end_comment

begin_macro
unit|~
name|vector
argument_list|()
end_macro

begin_block
block|{
name|std
operator|::
name|_Destroy
argument_list|(
name|this
operator|->
name|_M_impl
operator|.
name|_M_start
argument_list|,
name|this
operator|->
name|_M_impl
operator|.
name|_M_finish
argument_list|,
name|_M_get_Tp_allocator
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/**        *  @brief  %Vector assignment operator.        *  @param  x  A %vector of identical element and allocator types.        *        *  All the elements of @a x are copied, but any extra memory in        *  @a x (for fast expansion) will not be copied.  Unlike the        *  copy constructor, the allocator object is not copied.        */
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
name|std
operator|::
name|__is_integer
operator|<
name|_InputIterator
operator|>
operator|::
name|__type
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

begin_expr_stmt
unit|using
name|_Base
operator|::
name|get_allocator
expr_stmt|;
end_expr_stmt

begin_comment
comment|// iterators
end_comment

begin_comment
comment|/**        *  Returns a read/write iterator that points to the first        *  element in the %vector.  Iteration is done in ordinary        *  element order.        */
end_comment

begin_function
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|iterator
argument_list|(
name|this
operator|->
name|_M_impl
operator|.
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
name|this
operator|->
name|_M_impl
operator|.
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
name|this
operator|->
name|_M_impl
operator|.
name|_M_finish
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**        *  Returns a read-only (constant) iterator that points one past        *  the last element in the %vector.  Iteration is done in        *  ordinary element order.        */
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
name|this
operator|->
name|_M_impl
operator|.
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
comment|/**        *  Returns a read/write reverse iterator that points to one        *  before the first element in the %vector.  Iteration is done        *  in reverse element order.        */
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
name|this
operator|->
name|_M_impl
operator|.
name|_M_finish
operator|-
name|this
operator|->
name|_M_impl
operator|.
name|_M_start
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
name|_M_get_Tp_allocator
argument_list|()
operator|.
name|max_size
argument_list|()
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
name|value_type
name|__x
init|=
name|value_type
argument_list|()
parameter_list|)
block|{
if|if
condition|(
name|__new_size
operator|<
name|size
argument_list|()
condition|)
name|_M_erase_at_end
argument_list|(
name|this
operator|->
name|_M_impl
operator|.
name|_M_start
operator|+
name|__new_size
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
comment|/**        *  Returns the total number of elements that the %vector can        *  hold before needing to allocate more memory.        */
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
name|this
operator|->
name|_M_impl
operator|.
name|_M_end_of_storage
operator|-
name|this
operator|->
name|_M_impl
operator|.
name|_M_start
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
comment|/**        *  @brief  Subscript access to the data contained in the %vector.        *  @param n The index of the element for which data should be        *  accessed.        *  @return  Read/write reference to data.        *        *  This operator allows for easy, array-style, data access.        *  Note that data access with this operator is unchecked and        *  out_of_range lookups are not defined. (For checked lookups        *  see at().)        */
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
name|this
operator|->
name|_M_impl
operator|.
name|_M_start
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
name|this
operator|->
name|_M_impl
operator|.
name|_M_start
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
name|__N
argument_list|(
literal|"vector::_M_range_check"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|/**        *  @brief  Provides access to the data contained in the %vector.        *  @param n The index of the element for which data should be        *  accessed.        *  @return  Read/write reference to data.        *  @throw  std::out_of_range  If @a n is an invalid index.        *        *  This function provides for safer data access.  The parameter        *  is first checked that it is in the range of the vector.  The        *  function throws out_of_range if the check fails.        */
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
comment|/**        *  Returns a read/write reference to the data at the last        *  element of the %vector.        */
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
comment|/**        *  Returns a read-only (constant) reference to the data at the        *  last element of the %vector.        */
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
comment|// _GLIBCXX_RESOLVE_LIB_DEFECTS
end_comment

begin_comment
comment|// DR 464. Suggestion for new member functions in standard containers.
end_comment

begin_comment
comment|// data access
end_comment

begin_comment
comment|/**        *   Returns a pointer such that [data(), data() + size()) is a valid        *   range.  For a non-empty %vector, data() ==&front().        */
end_comment

begin_function
name|pointer
name|data
parameter_list|()
block|{
return|return
name|pointer
argument_list|(
name|this
operator|->
name|_M_impl
operator|.
name|_M_start
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|const_pointer
name|data
argument_list|()
specifier|const
block|{
return|return
name|const_pointer
argument_list|(
name|this
operator|->
name|_M_impl
operator|.
name|_M_start
argument_list|)
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
name|this
operator|->
name|_M_impl
operator|.
name|_M_finish
operator|!=
name|this
operator|->
name|_M_impl
operator|.
name|_M_end_of_storage
condition|)
block|{
name|this
operator|->
name|_M_impl
operator|.
name|construct
argument_list|(
name|this
operator|->
name|_M_impl
operator|.
name|_M_finish
argument_list|,
name|__x
argument_list|)
expr_stmt|;
operator|++
name|this
operator|->
name|_M_impl
operator|.
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
comment|/**        *  @brief  Removes last element.        *        *  This is a typical stack operation. It shrinks the %vector by one.        *        *  Note that no data is returned, and if the last element's        *  data is needed, it should be retrieved before pop_back() is        *  called.        */
end_comment

begin_function
name|void
name|pop_back
parameter_list|()
block|{
operator|--
name|this
operator|->
name|_M_impl
operator|.
name|_M_finish
expr_stmt|;
name|this
operator|->
name|_M_impl
operator|.
name|destroy
argument_list|(
name|this
operator|->
name|_M_impl
operator|.
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

begin_comment
comment|/**        *  @brief  Inserts a number of copies of given data into the %vector.        *  @param  position  An iterator into the %vector.        *  @param  n  Number of elements to be inserted.        *  @param  x  Data to be inserted.        *        *  This function will insert a specified number of copies of        *  the given data before the location specified by @a position.        *        *  Note that this kind of operation could be expensive for a        *  %vector and if it is frequently used the user should        *  consider using std::list.        */
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
comment|/**        *  @brief  Inserts a range into the %vector.        *  @param  position  An iterator into the %vector.        *  @param  first  An input iterator.        *  @param  last   An input iterator.        *        *  This function will insert copies of the data in the range        *  [first,last) into the %vector before the location specified        *  by @a pos.        *        *  Note that this kind of operation could be expensive for a        *  %vector and if it is frequently used the user should        *  consider using std::list.        */
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
name|std
operator|::
name|__is_integer
operator|<
name|_InputIterator
operator|>
operator|::
name|__type
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
name|this
operator|->
name|_M_impl
operator|.
name|_M_start
argument_list|,
name|__x
operator|.
name|_M_impl
operator|.
name|_M_start
argument_list|)
expr_stmt|;
name|std
operator|::
name|swap
argument_list|(
name|this
operator|->
name|_M_impl
operator|.
name|_M_finish
argument_list|,
name|__x
operator|.
name|_M_impl
operator|.
name|_M_finish
argument_list|)
expr_stmt|;
name|std
operator|::
name|swap
argument_list|(
name|this
operator|->
name|_M_impl
operator|.
name|_M_end_of_storage
argument_list|,
name|__x
operator|.
name|_M_impl
operator|.
name|_M_end_of_storage
argument_list|)
expr_stmt|;
comment|// _GLIBCXX_RESOLVE_LIB_DEFECTS
comment|// 431. Swapping containers with unequal allocators.
name|std
operator|::
name|__alloc_swap
operator|<
name|_Tp_alloc_type
operator|>
operator|::
name|_S_do_it
argument_list|(
name|_M_get_Tp_allocator
argument_list|()
argument_list|,
name|__x
operator|.
name|_M_get_Tp_allocator
argument_list|()
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
name|_M_erase_at_end
argument_list|(
name|this
operator|->
name|_M_impl
operator|.
name|_M_start
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
name|this
operator|->
name|_M_allocate
argument_list|(
name|__n
argument_list|)
block|;
name|try
block|{
name|std
operator|::
name|__uninitialized_copy_a
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__result
argument_list|,
name|_M_get_Tp_allocator
argument_list|()
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
name|this
operator|->
name|_M_impl
operator|.
name|_M_start
operator|=
name|_M_allocate
argument_list|(
name|__n
argument_list|)
block|;
name|this
operator|->
name|_M_impl
operator|.
name|_M_end_of_storage
operator|=
name|this
operator|->
name|_M_impl
operator|.
name|_M_start
operator|+
name|__n
block|;
name|std
operator|::
name|__uninitialized_fill_n_a
argument_list|(
name|this
operator|->
name|_M_impl
operator|.
name|_M_start
argument_list|,
name|__n
argument_list|,
name|__value
argument_list|,
name|_M_get_Tp_allocator
argument_list|()
argument_list|)
block|;
name|this
operator|->
name|_M_impl
operator|.
name|_M_finish
operator|=
name|this
operator|->
name|_M_impl
operator|.
name|_M_end_of_storage
block|; 	}
comment|// Called by the range constructor to implement [23.1.1]/9
name|template
operator|<
name|typename
name|_InputIterator
operator|>
name|void
name|_M_initialize_dispatch
argument_list|(
argument|_InputIterator __first
argument_list|,
argument|_InputIterator __last
argument_list|,
argument|__false_type
argument_list|)
block|{
typedef|typedef
name|typename
name|std
operator|::
name|iterator_traits
operator|<
name|_InputIterator
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
argument|std::input_iterator_tag
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
argument|std::forward_iterator_tag
argument_list|)
block|{
specifier|const
name|size_type
name|__n
operator|=
name|std
operator|::
name|distance
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|)
block|;
name|this
operator|->
name|_M_impl
operator|.
name|_M_start
operator|=
name|this
operator|->
name|_M_allocate
argument_list|(
name|__n
argument_list|)
block|;
name|this
operator|->
name|_M_impl
operator|.
name|_M_end_of_storage
operator|=
name|this
operator|->
name|_M_impl
operator|.
name|_M_start
operator|+
name|__n
block|;
name|this
operator|->
name|_M_impl
operator|.
name|_M_finish
operator|=
name|std
operator|::
name|__uninitialized_copy_a
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|this
operator|->
name|_M_impl
operator|.
name|_M_start
argument_list|,
name|_M_get_Tp_allocator
argument_list|()
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
block|{
typedef|typedef
name|typename
name|std
operator|::
name|iterator_traits
operator|<
name|_InputIterator
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
argument|std::input_iterator_tag
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
argument|std::forward_iterator_tag
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
name|std
operator|::
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
argument|std::input_iterator_tag
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
argument|std::forward_iterator_tag
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

begin_comment
comment|// Internal erase functions follow.
end_comment

begin_comment
comment|// Called by erase(q1,q2), clear(), resize(), _M_fill_assign,
end_comment

begin_comment
comment|// _M_assign_aux.
end_comment

begin_function
name|void
name|_M_erase_at_end
parameter_list|(
name|pointer
name|__pos
parameter_list|)
block|{
name|std
operator|::
name|_Destroy
argument_list|(
name|__pos
argument_list|,
name|this
operator|->
name|_M_impl
operator|.
name|_M_finish
argument_list|,
name|_M_get_Tp_allocator
argument_list|()
argument_list|)
expr_stmt|;
name|this
operator|->
name|_M_impl
operator|.
name|_M_finish
operator|=
name|__pos
expr_stmt|;
block|}
end_function

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
operator|(
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
name|std
operator|::
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
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/**    *  @brief  Vector ordering relation.    *  @param  x  A %vector.    *  @param  y  A %vector of the same type as @a x.    *  @return  True iff @a x is lexicographically less than @a y.    *    *  This is a total ordering relation.  It is linear in the size of the    *  vectors.  The elements must be comparable with @c<.    *    *  See std::lexicographical_compare() for how the determination is made.   */
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
name|_GLIBCXX_END_NESTED_NAMESPACE
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VECTOR_H */
end_comment

end_unit

