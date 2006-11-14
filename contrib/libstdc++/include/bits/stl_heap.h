begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Heap implementation -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2001, 2004 Free Software Foundation, Inc.
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
comment|/*  *  * Copyright (c) 1994  * Hewlett-Packard Company  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Hewlett-Packard Company makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  *  * Copyright (c) 1997  * Silicon Graphics Computer Systems, Inc.  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Silicon Graphics makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  */
end_comment

begin_comment
comment|/** @file stl_heap.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STL_HEAP_H
end_ifndef

begin_define
define|#
directive|define
name|_STL_HEAP_H
value|1
end_define

begin_include
include|#
directive|include
file|<debug/debug.h>
end_include

begin_decl_stmt
name|namespace
name|std
block|{
comment|// is_heap, a predicate testing whether or not a range is
comment|// a heap.  This function is an extension, not part of the C++
comment|// standard.
name|template
operator|<
name|typename
name|_RandomAccessIterator
operator|,
name|typename
name|_Distance
operator|>
name|bool
name|__is_heap
argument_list|(
argument|_RandomAccessIterator __first
argument_list|,
argument|_Distance __n
argument_list|)
block|{
name|_Distance
name|__parent
operator|=
literal|0
block|;
for|for
control|(
name|_Distance
name|__child
init|=
literal|1
init|;
name|__child
operator|<
name|__n
condition|;
operator|++
name|__child
control|)
block|{
if|if
condition|(
name|__first
index|[
name|__parent
index|]
operator|<
name|__first
index|[
name|__child
index|]
condition|)
return|return
name|false
return|;
if|if
condition|(
operator|(
name|__child
operator|&
literal|1
operator|)
operator|==
literal|0
condition|)
operator|++
name|__parent
expr_stmt|;
block|}
return|return
name|true
return|;
block|}
name|template
operator|<
name|typename
name|_RandomAccessIterator
operator|,
name|typename
name|_Distance
operator|,
name|typename
name|_StrictWeakOrdering
operator|>
name|bool
name|__is_heap
argument_list|(
argument|_RandomAccessIterator __first
argument_list|,
argument|_StrictWeakOrdering __comp
argument_list|,
argument|_Distance __n
argument_list|)
block|{
name|_Distance
name|__parent
operator|=
literal|0
block|;
for|for
control|(
name|_Distance
name|__child
init|=
literal|1
init|;
name|__child
operator|<
name|__n
condition|;
operator|++
name|__child
control|)
block|{
if|if
condition|(
name|__comp
argument_list|(
name|__first
index|[
name|__parent
index|]
argument_list|,
name|__first
index|[
name|__child
index|]
argument_list|)
condition|)
return|return
name|false
return|;
if|if
condition|(
operator|(
name|__child
operator|&
literal|1
operator|)
operator|==
literal|0
condition|)
operator|++
name|__parent
expr_stmt|;
block|}
return|return
name|true
return|;
block|}
name|template
operator|<
name|typename
name|_RandomAccessIterator
operator|>
name|bool
name|__is_heap
argument_list|(
argument|_RandomAccessIterator __first
argument_list|,
argument|_RandomAccessIterator __last
argument_list|)
block|{
return|return
name|std
operator|::
name|__is_heap
argument_list|(
name|__first
argument_list|,
name|std
operator|::
name|distance
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|)
argument_list|)
return|;
block|}
name|template
operator|<
name|typename
name|_RandomAccessIterator
operator|,
name|typename
name|_StrictWeakOrdering
operator|>
name|bool
name|__is_heap
argument_list|(
argument|_RandomAccessIterator __first
argument_list|,
argument|_RandomAccessIterator __last
argument_list|,
argument|_StrictWeakOrdering __comp
argument_list|)
block|{
return|return
name|std
operator|::
name|__is_heap
argument_list|(
name|__first
argument_list|,
name|__comp
argument_list|,
name|std
operator|::
name|distance
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|)
argument_list|)
return|;
block|}
comment|// Heap-manipulation functions: push_heap, pop_heap, make_heap, sort_heap.
name|template
operator|<
name|typename
name|_RandomAccessIterator
operator|,
name|typename
name|_Distance
operator|,
name|typename
name|_Tp
operator|>
name|void
name|__push_heap
argument_list|(
argument|_RandomAccessIterator __first
argument_list|,
argument|_Distance __holeIndex
argument_list|,
argument|_Distance __topIndex
argument_list|,
argument|_Tp __value
argument_list|)
block|{
name|_Distance
name|__parent
operator|=
operator|(
name|__holeIndex
operator|-
literal|1
operator|)
operator|/
literal|2
block|;
while|while
condition|(
name|__holeIndex
operator|>
name|__topIndex
operator|&&
operator|*
operator|(
name|__first
operator|+
name|__parent
operator|)
operator|<
name|__value
condition|)
block|{
operator|*
operator|(
name|__first
operator|+
name|__holeIndex
operator|)
operator|=
operator|*
operator|(
name|__first
operator|+
name|__parent
operator|)
expr_stmt|;
name|__holeIndex
operator|=
name|__parent
expr_stmt|;
name|__parent
operator|=
operator|(
name|__holeIndex
operator|-
literal|1
operator|)
operator|/
literal|2
expr_stmt|;
block|}
operator|*
operator|(
name|__first
operator|+
name|__holeIndex
operator|)
operator|=
name|__value
expr_stmt|;
block|}
comment|/**    *  @brief  Push an element onto a heap.    *  @param  first  Start of heap.    *  @param  last   End of heap + element.    *  @ingroup heap    *    *  This operation pushes the element at last-1 onto the valid heap over the    *  range [first,last-1).  After completion, [first,last) is a valid heap.   */
name|template
operator|<
name|typename
name|_RandomAccessIterator
operator|>
specifier|inline
name|void
name|push_heap
argument_list|(
argument|_RandomAccessIterator __first
argument_list|,
argument|_RandomAccessIterator __last
argument_list|)
block|{
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_RandomAccessIterator
operator|>
operator|::
name|value_type
name|_ValueType
expr_stmt|;
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_RandomAccessIterator
operator|>
operator|::
name|difference_type
name|_DistanceType
expr_stmt|;
comment|// concept requirements
name|__glibcxx_function_requires
argument_list|(
argument|_Mutable_RandomAccessIteratorConcept< 	    _RandomAccessIterator>
argument_list|)
name|__glibcxx_function_requires
argument_list|(
argument|_LessThanComparableConcept<_ValueType>
argument_list|)
name|__glibcxx_requires_valid_range
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|)
expr_stmt|;
comment|//      __glibcxx_requires_heap(__first, __last - 1);
name|std
operator|::
name|__push_heap
argument_list|(
name|__first
argument_list|,
name|_DistanceType
argument_list|(
operator|(
name|__last
operator|-
name|__first
operator|)
operator|-
literal|1
argument_list|)
argument_list|,
name|_DistanceType
argument_list|(
literal|0
argument_list|)
argument_list|,
name|_ValueType
argument_list|(
operator|*
operator|(
name|__last
operator|-
literal|1
operator|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_RandomAccessIterator
operator|,
name|typename
name|_Distance
operator|,
name|typename
name|_Tp
operator|,
name|typename
name|_Compare
operator|>
name|void
name|__push_heap
argument_list|(
argument|_RandomAccessIterator __first
argument_list|,
argument|_Distance __holeIndex
argument_list|,
argument|_Distance __topIndex
argument_list|,
argument|_Tp __value
argument_list|,
argument|_Compare __comp
argument_list|)
block|{
name|_Distance
name|__parent
operator|=
operator|(
name|__holeIndex
operator|-
literal|1
operator|)
operator|/
literal|2
block|;
while|while
condition|(
name|__holeIndex
operator|>
name|__topIndex
operator|&&
name|__comp
argument_list|(
operator|*
operator|(
name|__first
operator|+
name|__parent
operator|)
argument_list|,
name|__value
argument_list|)
condition|)
block|{
operator|*
operator|(
name|__first
operator|+
name|__holeIndex
operator|)
operator|=
operator|*
operator|(
name|__first
operator|+
name|__parent
operator|)
expr_stmt|;
name|__holeIndex
operator|=
name|__parent
expr_stmt|;
name|__parent
operator|=
operator|(
name|__holeIndex
operator|-
literal|1
operator|)
operator|/
literal|2
expr_stmt|;
block|}
operator|*
operator|(
name|__first
operator|+
name|__holeIndex
operator|)
operator|=
name|__value
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|/**    *  @brief  Push an element onto a heap using comparison functor.    *  @param  first  Start of heap.    *  @param  last   End of heap + element.    *  @param  comp   Comparison functor.    *  @ingroup heap    *    *  This operation pushes the element at last-1 onto the valid heap over the    *  range [first,last-1).  After completion, [first,last) is a valid heap.    *  Compare operations are performed using comp.   */
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_RandomAccessIterator
operator|,
name|typename
name|_Compare
operator|>
specifier|inline
name|void
name|push_heap
argument_list|(
argument|_RandomAccessIterator __first
argument_list|,
argument|_RandomAccessIterator __last
argument_list|,
argument|_Compare __comp
argument_list|)
block|{
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_RandomAccessIterator
operator|>
operator|::
name|value_type
name|_ValueType
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_RandomAccessIterator
operator|>
operator|::
name|difference_type
name|_DistanceType
expr_stmt|;
end_typedef

begin_comment
comment|// concept requirements
end_comment

begin_macro
name|__glibcxx_function_requires
argument_list|(
argument|_Mutable_RandomAccessIteratorConcept< 	    _RandomAccessIterator>
argument_list|)
end_macro

begin_expr_stmt
name|__glibcxx_requires_valid_range
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__glibcxx_requires_heap_pred
argument_list|(
name|__first
argument_list|,
name|__last
operator|-
literal|1
argument_list|,
name|__comp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|__push_heap
argument_list|(
name|__first
argument_list|,
name|_DistanceType
argument_list|(
operator|(
name|__last
operator|-
name|__first
operator|)
operator|-
literal|1
argument_list|)
argument_list|,
name|_DistanceType
argument_list|(
literal|0
argument_list|)
argument_list|,
name|_ValueType
argument_list|(
operator|*
operator|(
name|__last
operator|-
literal|1
operator|)
argument_list|)
argument_list|,
name|__comp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}    template
operator|<
name|typename
name|_RandomAccessIterator
operator|,
name|typename
name|_Distance
operator|,
name|typename
name|_Tp
operator|>
name|void
name|__adjust_heap
argument_list|(
argument|_RandomAccessIterator __first
argument_list|,
argument|_Distance __holeIndex
argument_list|,
argument|_Distance __len
argument_list|,
argument|_Tp __value
argument_list|)
block|{
specifier|const
name|_Distance
name|__topIndex
operator|=
name|__holeIndex
block|;
name|_Distance
name|__secondChild
operator|=
literal|2
operator|*
name|__holeIndex
operator|+
literal|2
block|;
while|while
condition|(
name|__secondChild
operator|<
name|__len
condition|)
block|{
if|if
condition|(
operator|*
operator|(
name|__first
operator|+
name|__secondChild
operator|)
operator|<
operator|*
operator|(
name|__first
operator|+
operator|(
name|__secondChild
operator|-
literal|1
operator|)
operator|)
condition|)
name|__secondChild
operator|--
expr_stmt|;
operator|*
operator|(
name|__first
operator|+
name|__holeIndex
operator|)
operator|=
operator|*
operator|(
name|__first
operator|+
name|__secondChild
operator|)
expr_stmt|;
name|__holeIndex
operator|=
name|__secondChild
expr_stmt|;
name|__secondChild
operator|=
literal|2
operator|*
operator|(
name|__secondChild
operator|+
literal|1
operator|)
expr_stmt|;
block|}
end_expr_stmt

begin_if
if|if
condition|(
name|__secondChild
operator|==
name|__len
condition|)
block|{
operator|*
operator|(
name|__first
operator|+
name|__holeIndex
operator|)
operator|=
operator|*
operator|(
name|__first
operator|+
operator|(
name|__secondChild
operator|-
literal|1
operator|)
operator|)
expr_stmt|;
name|__holeIndex
operator|=
name|__secondChild
operator|-
literal|1
expr_stmt|;
block|}
end_if

begin_expr_stmt
name|std
operator|::
name|__push_heap
argument_list|(
name|__first
argument_list|,
name|__holeIndex
argument_list|,
name|__topIndex
argument_list|,
name|__value
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}    template
operator|<
name|typename
name|_RandomAccessIterator
operator|,
name|typename
name|_Tp
operator|>
specifier|inline
name|void
name|__pop_heap
argument_list|(
argument|_RandomAccessIterator __first
argument_list|,
argument|_RandomAccessIterator __last
argument_list|,
argument|_RandomAccessIterator __result
argument_list|,
argument|_Tp __value
argument_list|)
block|{
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_RandomAccessIterator
operator|>
operator|::
name|difference_type
name|_Distance
expr_stmt|;
operator|*
name|__result
operator|=
operator|*
name|__first
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|__adjust_heap
argument_list|(
name|__first
argument_list|,
name|_Distance
argument_list|(
literal|0
argument_list|)
argument_list|,
name|_Distance
argument_list|(
name|__last
operator|-
name|__first
argument_list|)
argument_list|,
name|__value
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|/**    *  @brief  Pop an element off a heap.    *  @param  first  Start of heap.    *  @param  last   End of heap.    *  @ingroup heap    *    *  This operation pops the top of the heap.  The elements first and last-1    *  are swapped and [first,last-1) is made into a heap.   */
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_RandomAccessIterator
operator|>
specifier|inline
name|void
name|pop_heap
argument_list|(
argument|_RandomAccessIterator __first
argument_list|,
argument|_RandomAccessIterator __last
argument_list|)
block|{
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_RandomAccessIterator
operator|>
operator|::
name|value_type
name|_ValueType
expr_stmt|;
comment|// concept requirements
name|__glibcxx_function_requires
argument_list|(
argument|_Mutable_RandomAccessIteratorConcept< 	    _RandomAccessIterator>
argument_list|)
name|__glibcxx_function_requires
argument_list|(
argument|_LessThanComparableConcept<_ValueType>
argument_list|)
name|__glibcxx_requires_valid_range
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__glibcxx_requires_heap
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|__pop_heap
argument_list|(
name|__first
argument_list|,
name|__last
operator|-
literal|1
argument_list|,
name|__last
operator|-
literal|1
argument_list|,
name|_ValueType
argument_list|(
operator|*
operator|(
name|__last
operator|-
literal|1
operator|)
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}    template
operator|<
name|typename
name|_RandomAccessIterator
operator|,
name|typename
name|_Distance
operator|,
name|typename
name|_Tp
operator|,
name|typename
name|_Compare
operator|>
name|void
name|__adjust_heap
argument_list|(
argument|_RandomAccessIterator __first
argument_list|,
argument|_Distance __holeIndex
argument_list|,
argument|_Distance __len
argument_list|,
argument|_Tp __value
argument_list|,
argument|_Compare __comp
argument_list|)
block|{
specifier|const
name|_Distance
name|__topIndex
operator|=
name|__holeIndex
block|;
name|_Distance
name|__secondChild
operator|=
literal|2
operator|*
name|__holeIndex
operator|+
literal|2
block|;
while|while
condition|(
name|__secondChild
operator|<
name|__len
condition|)
block|{
if|if
condition|(
name|__comp
argument_list|(
operator|*
operator|(
name|__first
operator|+
name|__secondChild
operator|)
argument_list|,
operator|*
operator|(
name|__first
operator|+
operator|(
name|__secondChild
operator|-
literal|1
operator|)
operator|)
argument_list|)
condition|)
name|__secondChild
operator|--
expr_stmt|;
operator|*
operator|(
name|__first
operator|+
name|__holeIndex
operator|)
operator|=
operator|*
operator|(
name|__first
operator|+
name|__secondChild
operator|)
expr_stmt|;
name|__holeIndex
operator|=
name|__secondChild
expr_stmt|;
name|__secondChild
operator|=
literal|2
operator|*
operator|(
name|__secondChild
operator|+
literal|1
operator|)
expr_stmt|;
block|}
end_expr_stmt

begin_if
if|if
condition|(
name|__secondChild
operator|==
name|__len
condition|)
block|{
operator|*
operator|(
name|__first
operator|+
name|__holeIndex
operator|)
operator|=
operator|*
operator|(
name|__first
operator|+
operator|(
name|__secondChild
operator|-
literal|1
operator|)
operator|)
expr_stmt|;
name|__holeIndex
operator|=
name|__secondChild
operator|-
literal|1
expr_stmt|;
block|}
end_if

begin_expr_stmt
name|std
operator|::
name|__push_heap
argument_list|(
name|__first
argument_list|,
name|__holeIndex
argument_list|,
name|__topIndex
argument_list|,
name|__value
argument_list|,
name|__comp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}    template
operator|<
name|typename
name|_RandomAccessIterator
operator|,
name|typename
name|_Tp
operator|,
name|typename
name|_Compare
operator|>
specifier|inline
name|void
name|__pop_heap
argument_list|(
argument|_RandomAccessIterator __first
argument_list|,
argument|_RandomAccessIterator __last
argument_list|,
argument|_RandomAccessIterator __result
argument_list|,
argument|_Tp __value
argument_list|,
argument|_Compare __comp
argument_list|)
block|{
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_RandomAccessIterator
operator|>
operator|::
name|difference_type
name|_Distance
expr_stmt|;
operator|*
name|__result
operator|=
operator|*
name|__first
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|__adjust_heap
argument_list|(
name|__first
argument_list|,
name|_Distance
argument_list|(
literal|0
argument_list|)
argument_list|,
name|_Distance
argument_list|(
name|__last
operator|-
name|__first
argument_list|)
argument_list|,
name|__value
argument_list|,
name|__comp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|/**    *  @brief  Pop an element off a heap using comparison functor.    *  @param  first  Start of heap.    *  @param  last   End of heap.    *  @param  comp   Comparison functor to use.    *  @ingroup heap    *    *  This operation pops the top of the heap.  The elements first and last-1    *  are swapped and [first,last-1) is made into a heap.  Comparisons are    *  made using comp.   */
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_RandomAccessIterator
operator|,
name|typename
name|_Compare
operator|>
specifier|inline
name|void
name|pop_heap
argument_list|(
argument|_RandomAccessIterator __first
argument_list|,
argument|_RandomAccessIterator __last
argument_list|,
argument|_Compare __comp
argument_list|)
block|{
comment|// concept requirements
name|__glibcxx_function_requires
argument_list|(
argument|_Mutable_RandomAccessIteratorConcept< 	    _RandomAccessIterator>
argument_list|)
name|__glibcxx_requires_valid_range
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|)
block|;
name|__glibcxx_requires_heap_pred
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__comp
argument_list|)
block|;
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_RandomAccessIterator
operator|>
operator|::
name|value_type
name|_ValueType
expr_stmt|;
name|std
operator|::
name|__pop_heap
argument_list|(
name|__first
argument_list|,
name|__last
operator|-
literal|1
argument_list|,
name|__last
operator|-
literal|1
argument_list|,
name|_ValueType
argument_list|(
operator|*
operator|(
name|__last
operator|-
literal|1
operator|)
argument_list|)
argument_list|,
name|__comp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|/**    *  @brief  Construct a heap over a range.    *  @param  first  Start of heap.    *  @param  last   End of heap.    *  @ingroup heap    *    *  This operation makes the elements in [first,last) into a heap.   */
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_RandomAccessIterator
operator|>
name|void
name|make_heap
argument_list|(
argument|_RandomAccessIterator __first
argument_list|,
argument|_RandomAccessIterator __last
argument_list|)
block|{
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_RandomAccessIterator
operator|>
operator|::
name|value_type
name|_ValueType
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_RandomAccessIterator
operator|>
operator|::
name|difference_type
name|_DistanceType
expr_stmt|;
end_typedef

begin_comment
comment|// concept requirements
end_comment

begin_macro
name|__glibcxx_function_requires
argument_list|(
argument|_Mutable_RandomAccessIteratorConcept< 	    _RandomAccessIterator>
argument_list|)
end_macro

begin_macro
name|__glibcxx_function_requires
argument_list|(
argument|_LessThanComparableConcept<_ValueType>
argument_list|)
end_macro

begin_expr_stmt
name|__glibcxx_requires_valid_range
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|__last
operator|-
name|__first
operator|<
literal|2
condition|)
return|return;
end_if

begin_decl_stmt
specifier|const
name|_DistanceType
name|__len
init|=
name|__last
operator|-
name|__first
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|_DistanceType
name|__parent
init|=
operator|(
name|__len
operator|-
literal|2
operator|)
operator|/
literal|2
decl_stmt|;
end_decl_stmt

begin_while
while|while
condition|(
name|true
condition|)
block|{
name|std
operator|::
name|__adjust_heap
argument_list|(
name|__first
argument_list|,
name|__parent
argument_list|,
name|__len
argument_list|,
name|_ValueType
argument_list|(
operator|*
operator|(
name|__first
operator|+
name|__parent
operator|)
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|__parent
operator|==
literal|0
condition|)
return|return;
name|__parent
operator|--
expr_stmt|;
block|}
end_while

begin_comment
unit|}
comment|/**    *  @brief  Construct a heap over a range using comparison functor.    *  @param  first  Start of heap.    *  @param  last   End of heap.    *  @param  comp   Comparison functor to use.    *  @ingroup heap    *    *  This operation makes the elements in [first,last) into a heap.    *  Comparisons are made using comp.   */
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_RandomAccessIterator
operator|,
name|typename
name|_Compare
operator|>
specifier|inline
name|void
name|make_heap
argument_list|(
argument|_RandomAccessIterator __first
argument_list|,
argument|_RandomAccessIterator __last
argument_list|,
argument|_Compare __comp
argument_list|)
block|{
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_RandomAccessIterator
operator|>
operator|::
name|value_type
name|_ValueType
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_RandomAccessIterator
operator|>
operator|::
name|difference_type
name|_DistanceType
expr_stmt|;
end_typedef

begin_comment
comment|// concept requirements
end_comment

begin_macro
name|__glibcxx_function_requires
argument_list|(
argument|_Mutable_RandomAccessIteratorConcept< 	    _RandomAccessIterator>
argument_list|)
end_macro

begin_expr_stmt
name|__glibcxx_requires_valid_range
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|__last
operator|-
name|__first
operator|<
literal|2
condition|)
return|return;
end_if

begin_decl_stmt
specifier|const
name|_DistanceType
name|__len
init|=
name|__last
operator|-
name|__first
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|_DistanceType
name|__parent
init|=
operator|(
name|__len
operator|-
literal|2
operator|)
operator|/
literal|2
decl_stmt|;
end_decl_stmt

begin_while
while|while
condition|(
name|true
condition|)
block|{
name|std
operator|::
name|__adjust_heap
argument_list|(
name|__first
argument_list|,
name|__parent
argument_list|,
name|__len
argument_list|,
name|_ValueType
argument_list|(
operator|*
operator|(
name|__first
operator|+
name|__parent
operator|)
argument_list|)
argument_list|,
name|__comp
argument_list|)
expr_stmt|;
if|if
condition|(
name|__parent
operator|==
literal|0
condition|)
return|return;
name|__parent
operator|--
expr_stmt|;
block|}
end_while

begin_comment
unit|}
comment|/**    *  @brief  Sort a heap.    *  @param  first  Start of heap.    *  @param  last   End of heap.    *  @ingroup heap    *    *  This operation sorts the valid heap in the range [first,last).   */
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_RandomAccessIterator
operator|>
name|void
name|sort_heap
argument_list|(
argument|_RandomAccessIterator __first
argument_list|,
argument|_RandomAccessIterator __last
argument_list|)
block|{
comment|// concept requirements
name|__glibcxx_function_requires
argument_list|(
argument|_Mutable_RandomAccessIteratorConcept< 	    _RandomAccessIterator>
argument_list|)
name|__glibcxx_function_requires
argument_list|(
argument|_LessThanComparableConcept< 	    typename iterator_traits<_RandomAccessIterator>::value_type>
argument_list|)
name|__glibcxx_requires_valid_range
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|)
block|;
comment|//      __glibcxx_requires_heap(__first, __last);
while|while
condition|(
name|__last
operator|-
name|__first
operator|>
literal|1
condition|)
name|std
operator|::
name|pop_heap
argument_list|(
name|__first
argument_list|,
name|__last
operator|--
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_comment
comment|/**    *  @brief  Sort a heap using comparison functor.    *  @param  first  Start of heap.    *  @param  last   End of heap.    *  @param  comp   Comparison functor to use.    *  @ingroup heap    *    *  This operation sorts the valid heap in the range [first,last).    *  Comparisons are made using comp.   */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_RandomAccessIterator
operator|,
name|typename
name|_Compare
operator|>
name|void
name|sort_heap
argument_list|(
argument|_RandomAccessIterator __first
argument_list|,
argument|_RandomAccessIterator __last
argument_list|,
argument|_Compare __comp
argument_list|)
block|{
comment|// concept requirements
name|__glibcxx_function_requires
argument_list|(
argument|_Mutable_RandomAccessIteratorConcept< 	    _RandomAccessIterator>
argument_list|)
name|__glibcxx_requires_valid_range
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|)
block|;
name|__glibcxx_requires_heap_pred
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__comp
argument_list|)
block|;
while|while
condition|(
name|__last
operator|-
name|__first
operator|>
literal|1
condition|)
name|std
operator|::
name|pop_heap
argument_list|(
name|__first
argument_list|,
name|__last
operator|--
argument_list|,
name|__comp
argument_list|)
expr_stmt|;
block|}
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
comment|/* _STL_HEAP_H */
end_comment

begin_comment
comment|// Local Variables:
end_comment

begin_comment
comment|// mode:C++
end_comment

begin_comment
comment|// End:
end_comment

end_unit

