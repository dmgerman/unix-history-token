begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Numeric functions implementation -*- C++ -*-
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
comment|/*  *  * Copyright (c) 1994  * Hewlett-Packard Company  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Hewlett-Packard Company makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  *  *  * Copyright (c) 1996,1997  * Silicon Graphics Computer Systems, Inc.  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Silicon Graphics makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  */
end_comment

begin_comment
comment|/** @file stl_numeric.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STL_NUMERIC_H
end_ifndef

begin_define
define|#
directive|define
name|_STL_NUMERIC_H
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
comment|/**    *  @brief  Accumulate values in a range.    *    *  Accumulates the values in the range [first,last) using operator+().  The    *  initial value is @a init.  The values are processed in order.    *    *  @param  first  Start of range.    *  @param  last  End of range.    *  @param  init  Starting value to add other values to.    *  @return  The final sum.    */
name|template
operator|<
name|typename
name|_InputIterator
operator|,
name|typename
name|_Tp
operator|>
name|_Tp
name|accumulate
argument_list|(
argument|_InputIterator __first
argument_list|,
argument|_InputIterator __last
argument_list|,
argument|_Tp __init
argument_list|)
block|{
comment|// concept requirements
name|__glibcxx_function_requires
argument_list|(
argument|_InputIteratorConcept<_InputIterator>
argument_list|)
name|__glibcxx_requires_valid_range
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|)
block|;
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
name|__init
operator|=
name|__init
operator|+
operator|*
name|__first
expr_stmt|;
return|return
name|__init
return|;
block|}
end_decl_stmt

begin_comment
comment|/**    *  @brief  Accumulate values in a range with operation.    *    *  Accumulates the values in the range [first,last) using the function    *  object @a binary_op.  The initial value is @a init.  The values are    *  processed in order.    *    *  @param  first  Start of range.    *  @param  last  End of range.    *  @param  init  Starting value to add other values to.    *  @param  binary_op  Function object to accumulate with.    *  @return  The final sum.    */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_InputIterator
operator|,
name|typename
name|_Tp
operator|,
name|typename
name|_BinaryOperation
operator|>
name|_Tp
name|accumulate
argument_list|(
argument|_InputIterator __first
argument_list|,
argument|_InputIterator __last
argument_list|,
argument|_Tp __init
argument_list|,
argument|_BinaryOperation __binary_op
argument_list|)
block|{
comment|// concept requirements
name|__glibcxx_function_requires
argument_list|(
argument|_InputIteratorConcept<_InputIterator>
argument_list|)
name|__glibcxx_requires_valid_range
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|)
block|;
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
name|__init
operator|=
name|__binary_op
argument_list|(
name|__init
argument_list|,
operator|*
name|__first
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__init
return|;
end_return

begin_comment
unit|}
comment|/**    *  @brief  Compute inner product of two ranges.    *    *  Starting with an initial value of @a init, multiplies successive    *  elements from the two ranges and adds each product into the accumulated    *  value using operator+().  The values in the ranges are processed in    *  order.    *    *  @param  first1  Start of range 1.    *  @param  last1  End of range 1.    *  @param  first2  Start of range 2.    *  @param  init  Starting value to add other values to.    *  @return  The final inner product.    */
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_InputIterator1
operator|,
name|typename
name|_InputIterator2
operator|,
name|typename
name|_Tp
operator|>
name|_Tp
name|inner_product
argument_list|(
argument|_InputIterator1 __first1
argument_list|,
argument|_InputIterator1 __last1
argument_list|,
argument|_InputIterator2 __first2
argument_list|,
argument|_Tp __init
argument_list|)
block|{
comment|// concept requirements
name|__glibcxx_function_requires
argument_list|(
argument|_InputIteratorConcept<_InputIterator1>
argument_list|)
name|__glibcxx_function_requires
argument_list|(
argument|_InputIteratorConcept<_InputIterator2>
argument_list|)
name|__glibcxx_requires_valid_range
argument_list|(
name|__first1
argument_list|,
name|__last1
argument_list|)
block|;
for|for
control|(
init|;
name|__first1
operator|!=
name|__last1
condition|;
operator|++
name|__first1
operator|,
operator|++
name|__first2
control|)
name|__init
operator|=
name|__init
operator|+
operator|(
operator|*
name|__first1
operator|*
operator|*
name|__first2
operator|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__init
return|;
end_return

begin_comment
unit|}
comment|/**    *  @brief  Compute inner product of two ranges.    *    *  Starting with an initial value of @a init, applies @a binary_op2 to    *  successive elements from the two ranges and accumulates each result into    *  the accumulated value using @a binary_op1.  The values in the ranges are    *  processed in order.    *    *  @param  first1  Start of range 1.    *  @param  last1  End of range 1.    *  @param  first2  Start of range 2.    *  @param  init  Starting value to add other values to.    *  @param  binary_op1  Function object to accumulate with.    *  @param  binary_op2  Function object to apply to pairs of input values.    *  @return  The final inner product.    */
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_InputIterator1
operator|,
name|typename
name|_InputIterator2
operator|,
name|typename
name|_Tp
operator|,
name|typename
name|_BinaryOperation1
operator|,
name|typename
name|_BinaryOperation2
operator|>
name|_Tp
name|inner_product
argument_list|(
argument|_InputIterator1 __first1
argument_list|,
argument|_InputIterator1 __last1
argument_list|,
argument|_InputIterator2 __first2
argument_list|,
argument|_Tp __init
argument_list|,
argument|_BinaryOperation1 __binary_op1
argument_list|,
argument|_BinaryOperation2 __binary_op2
argument_list|)
block|{
comment|// concept requirements
name|__glibcxx_function_requires
argument_list|(
argument|_InputIteratorConcept<_InputIterator1>
argument_list|)
name|__glibcxx_function_requires
argument_list|(
argument|_InputIteratorConcept<_InputIterator2>
argument_list|)
name|__glibcxx_requires_valid_range
argument_list|(
name|__first1
argument_list|,
name|__last1
argument_list|)
block|;
for|for
control|(
init|;
name|__first1
operator|!=
name|__last1
condition|;
operator|++
name|__first1
operator|,
operator|++
name|__first2
control|)
name|__init
operator|=
name|__binary_op1
argument_list|(
name|__init
argument_list|,
name|__binary_op2
argument_list|(
operator|*
name|__first1
argument_list|,
operator|*
name|__first2
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__init
return|;
end_return

begin_comment
unit|}
comment|/**    *  @brief  Return list of partial sums    *    *  Accumulates the values in the range [first,last) using operator+().    *  As each successive input value is added into the total, that partial sum    *  is written to @a result.  Therefore, the first value in result is the    *  first value of the input, the second value in result is the sum of the    *  first and second input values, and so on.    *    *  @param  first  Start of input range.    *  @param  last  End of input range.    *  @param  result  Output to write sums to.    *  @return  Iterator pointing just beyond the values written to result.    */
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_InputIterator
operator|,
name|typename
name|_OutputIterator
operator|>
name|_OutputIterator
name|partial_sum
argument_list|(
argument|_InputIterator __first
argument_list|,
argument|_InputIterator __last
argument_list|,
argument|_OutputIterator __result
argument_list|)
block|{
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_InputIterator
operator|>
operator|::
name|value_type
name|_ValueType
expr_stmt|;
comment|// concept requirements
name|__glibcxx_function_requires
argument_list|(
argument|_InputIteratorConcept<_InputIterator>
argument_list|)
name|__glibcxx_function_requires
argument_list|(
argument|_OutputIteratorConcept<_OutputIterator
argument_list|,
argument|_ValueType>
argument_list|)
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
name|__first
operator|==
name|__last
condition|)
return|return
name|__result
return|;
end_if

begin_expr_stmt
operator|*
name|__result
operator|=
operator|*
name|__first
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|_ValueType
name|__value
init|=
operator|*
name|__first
decl_stmt|;
end_decl_stmt

begin_while
while|while
condition|(
operator|++
name|__first
operator|!=
name|__last
condition|)
block|{
name|__value
operator|=
name|__value
operator|+
operator|*
name|__first
expr_stmt|;
operator|*
operator|++
name|__result
operator|=
name|__value
expr_stmt|;
block|}
end_while

begin_return
return|return
operator|++
name|__result
return|;
end_return

begin_comment
unit|}
comment|/**    *  @brief  Return list of partial sums    *    *  Accumulates the values in the range [first,last) using operator+().    *  As each successive input value is added into the total, that partial sum    *  is written to @a result.  Therefore, the first value in result is the    *  first value of the input, the second value in result is the sum of the    *  first and second input values, and so on.    *    *  @param  first  Start of input range.    *  @param  last  End of input range.    *  @param  result  Output to write sums to.    *  @return  Iterator pointing just beyond the values written to result.    */
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_InputIterator
operator|,
name|typename
name|_OutputIterator
operator|,
name|typename
name|_BinaryOperation
operator|>
name|_OutputIterator
name|partial_sum
argument_list|(
argument|_InputIterator __first
argument_list|,
argument|_InputIterator __last
argument_list|,
argument|_OutputIterator __result
argument_list|,
argument|_BinaryOperation __binary_op
argument_list|)
block|{
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_InputIterator
operator|>
operator|::
name|value_type
name|_ValueType
expr_stmt|;
comment|// concept requirements
name|__glibcxx_function_requires
argument_list|(
argument|_InputIteratorConcept<_InputIterator>
argument_list|)
name|__glibcxx_function_requires
argument_list|(
argument|_OutputIteratorConcept<_OutputIterator
argument_list|,
argument|_ValueType>
argument_list|)
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
name|__first
operator|==
name|__last
condition|)
return|return
name|__result
return|;
end_if

begin_expr_stmt
operator|*
name|__result
operator|=
operator|*
name|__first
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|_ValueType
name|__value
init|=
operator|*
name|__first
decl_stmt|;
end_decl_stmt

begin_while
while|while
condition|(
operator|++
name|__first
operator|!=
name|__last
condition|)
block|{
name|__value
operator|=
name|__binary_op
argument_list|(
name|__value
argument_list|,
operator|*
name|__first
argument_list|)
expr_stmt|;
operator|*
operator|++
name|__result
operator|=
name|__value
expr_stmt|;
block|}
end_while

begin_return
return|return
operator|++
name|__result
return|;
end_return

begin_comment
unit|}
comment|/**    *  @brief  Return differences between adjacent values.    *    *  Computes the difference between adjacent values in the range    *  [first,last) using operator-() and writes the result to @a result.    *    *  @param  first  Start of input range.    *  @param  last  End of input range.    *  @param  result  Output to write sums to.    *  @return  Iterator pointing just beyond the values written to result.    */
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_InputIterator
operator|,
name|typename
name|_OutputIterator
operator|>
name|_OutputIterator
name|adjacent_difference
argument_list|(
argument|_InputIterator __first
argument_list|,
argument|_InputIterator __last
argument_list|,
argument|_OutputIterator __result
argument_list|)
block|{
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_InputIterator
operator|>
operator|::
name|value_type
name|_ValueType
expr_stmt|;
comment|// concept requirements
name|__glibcxx_function_requires
argument_list|(
argument|_InputIteratorConcept<_InputIterator>
argument_list|)
name|__glibcxx_function_requires
argument_list|(
argument|_OutputIteratorConcept<_OutputIterator
argument_list|,
argument|_ValueType>
argument_list|)
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
name|__first
operator|==
name|__last
condition|)
return|return
name|__result
return|;
end_if

begin_expr_stmt
operator|*
name|__result
operator|=
operator|*
name|__first
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|_ValueType
name|__value
init|=
operator|*
name|__first
decl_stmt|;
end_decl_stmt

begin_while
while|while
condition|(
operator|++
name|__first
operator|!=
name|__last
condition|)
block|{
name|_ValueType
name|__tmp
init|=
operator|*
name|__first
decl_stmt|;
operator|*
operator|++
name|__result
operator|=
name|__tmp
operator|-
name|__value
expr_stmt|;
name|__value
operator|=
name|__tmp
expr_stmt|;
block|}
end_while

begin_return
return|return
operator|++
name|__result
return|;
end_return

begin_comment
unit|}
comment|/**    *  @brief  Return differences between adjacent values.    *    *  Computes the difference between adjacent values in the range    *  [first,last) using the function object @a binary_op and writes the    *  result to @a result.    *    *  @param  first  Start of input range.    *  @param  last  End of input range.    *  @param  result  Output to write sums to.    *  @return  Iterator pointing just beyond the values written to result.    */
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_InputIterator
operator|,
name|typename
name|_OutputIterator
operator|,
name|typename
name|_BinaryOperation
operator|>
name|_OutputIterator
name|adjacent_difference
argument_list|(
argument|_InputIterator __first
argument_list|,
argument|_InputIterator __last
argument_list|,
argument|_OutputIterator __result
argument_list|,
argument|_BinaryOperation __binary_op
argument_list|)
block|{
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_InputIterator
operator|>
operator|::
name|value_type
name|_ValueType
expr_stmt|;
comment|// concept requirements
name|__glibcxx_function_requires
argument_list|(
argument|_InputIteratorConcept<_InputIterator>
argument_list|)
name|__glibcxx_function_requires
argument_list|(
argument|_OutputIteratorConcept<_OutputIterator
argument_list|,
argument|_ValueType>
argument_list|)
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
name|__first
operator|==
name|__last
condition|)
return|return
name|__result
return|;
end_if

begin_expr_stmt
operator|*
name|__result
operator|=
operator|*
name|__first
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|_ValueType
name|__value
init|=
operator|*
name|__first
decl_stmt|;
end_decl_stmt

begin_while
while|while
condition|(
operator|++
name|__first
operator|!=
name|__last
condition|)
block|{
name|_ValueType
name|__tmp
init|=
operator|*
name|__first
decl_stmt|;
operator|*
operator|++
name|__result
operator|=
name|__binary_op
argument_list|(
name|__tmp
argument_list|,
name|__value
argument_list|)
expr_stmt|;
name|__value
operator|=
name|__tmp
expr_stmt|;
block|}
end_while

begin_return
return|return
operator|++
name|__result
return|;
end_return

begin_comment
unit|}  }
comment|// namespace std
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _STL_NUMERIC_H */
end_comment

end_unit

