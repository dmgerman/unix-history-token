begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Bits and pieces used in algorithms -*- C++ -*-
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
comment|/*  *  * Copyright (c) 1994  * Hewlett-Packard Company  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Hewlett-Packard Company makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  *  *  * Copyright (c) 1996-1998  * Silicon Graphics Computer Systems, Inc.  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Silicon Graphics makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  */
end_comment

begin_comment
comment|/** @file stl_algobase.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GLIBCPP_INTERNAL_ALGOBASE_H
end_ifndef

begin_define
define|#
directive|define
name|__GLIBCPP_INTERNAL_ALGOBASE_H
end_define

begin_include
include|#
directive|include
file|<bits/c++config.h>
end_include

begin_include
include|#
directive|include
file|<cstring>
end_include

begin_include
include|#
directive|include
file|<climits>
end_include

begin_include
include|#
directive|include
file|<cstdlib>
end_include

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<new>
end_include

begin_include
include|#
directive|include
file|<iosfwd>
end_include

begin_include
include|#
directive|include
file|<bits/stl_pair.h>
end_include

begin_include
include|#
directive|include
file|<bits/type_traits.h>
end_include

begin_include
include|#
directive|include
file|<bits/stl_iterator_base_types.h>
end_include

begin_include
include|#
directive|include
file|<bits/stl_iterator_base_funcs.h>
end_include

begin_include
include|#
directive|include
file|<bits/stl_iterator.h>
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
comment|// swap and iter_swap
comment|/**    *  @brief Swaps the contents of two iterators.    *  @param  a  An iterator.    *  @param  b  Another iterator.    *  @return   Nothing.    *    *  This function swaps the values pointed to by two iterators, not the    *  iterators themselves.   */
name|template
operator|<
name|typename
name|_ForwardIter1
operator|,
name|typename
name|_ForwardIter2
operator|>
specifier|inline
name|void
name|iter_swap
argument_list|(
argument|_ForwardIter1 __a
argument_list|,
argument|_ForwardIter2 __b
argument_list|)
block|{
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_ForwardIter1
operator|>
operator|::
name|value_type
name|_ValueType1
expr_stmt|;
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_ForwardIter2
operator|>
operator|::
name|value_type
name|_ValueType2
expr_stmt|;
comment|// concept requirements
name|__glibcpp_function_requires
argument_list|(
argument|_Mutable_ForwardIteratorConcept<_ForwardIter1>
argument_list|)
name|__glibcpp_function_requires
argument_list|(
argument|_Mutable_ForwardIteratorConcept<_ForwardIter2>
argument_list|)
name|__glibcpp_function_requires
argument_list|(
argument|_ConvertibleConcept<_ValueType1
argument_list|,
argument|_ValueType2>
argument_list|)
name|__glibcpp_function_requires
argument_list|(
argument|_ConvertibleConcept<_ValueType2
argument_list|,
argument|_ValueType1>
argument_list|)
name|_ValueType1
name|__tmp
init|=
operator|*
name|__a
decl_stmt|;
operator|*
name|__a
operator|=
operator|*
name|__b
expr_stmt|;
operator|*
name|__b
operator|=
name|__tmp
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/**    *  @brief Swaps two values.    *  @param  a  A thing of arbitrary type.    *  @param  b  Another thing of arbitrary type.    *  @return   Nothing.    *    *  This is the simple classic generic implementation.  It will work on    *  any type which has a copy constructor and an assignment operator.   */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|void
name|swap
argument_list|(
argument|_Tp& __a
argument_list|,
argument|_Tp& __b
argument_list|)
block|{
comment|// concept requirements
name|__glibcpp_function_requires
argument_list|(
argument|_SGIAssignableConcept<_Tp>
argument_list|)
name|_Tp
name|__tmp
operator|=
name|__a
block|;
name|__a
operator|=
name|__b
block|;
name|__b
operator|=
name|__tmp
block|;     }
comment|//--------------------------------------------------
comment|// min and max
undef|#
directive|undef
name|min
undef|#
directive|undef
name|max
comment|/**    *  @brief This does what you think it does.    *  @param  a  A thing of arbitrary type.    *  @param  b  Another thing of arbitrary type.    *  @return   The lesser of the parameters.    *    *  This is the simple classic generic implementation.  It will work on    *  temporary expressions, since they are only evaluated once, unlike a    *  preprocessor macro.   */
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
specifier|const
name|_Tp
operator|&
name|min
argument_list|(
argument|const _Tp& __a
argument_list|,
argument|const _Tp& __b
argument_list|)
block|{
comment|// concept requirements
name|__glibcpp_function_requires
argument_list|(
argument|_LessThanComparableConcept<_Tp>
argument_list|)
comment|//return __b< __a ? __b : __a;
if|if
condition|(
name|__b
operator|<
name|__a
condition|)
return|return
name|__b
return|;
end_expr_stmt

begin_return
return|return
name|__a
return|;
end_return

begin_comment
unit|}
comment|/**    *  @brief This does what you think it does.    *  @param  a  A thing of arbitrary type.    *  @param  b  Another thing of arbitrary type.    *  @return   The greater of the parameters.    *    *  This is the simple classic generic implementation.  It will work on    *  temporary expressions, since they are only evaluated once, unlike a    *  preprocessor macro.   */
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
specifier|const
name|_Tp
operator|&
name|max
argument_list|(
argument|const _Tp& __a
argument_list|,
argument|const _Tp& __b
argument_list|)
block|{
comment|// concept requirements
name|__glibcpp_function_requires
argument_list|(
argument|_LessThanComparableConcept<_Tp>
argument_list|)
comment|//return  __a< __b ? __b : __a;
if|if
condition|(
name|__a
operator|<
name|__b
condition|)
return|return
name|__b
return|;
end_expr_stmt

begin_return
return|return
name|__a
return|;
end_return

begin_comment
unit|}
comment|/**    *  @brief This does what you think it does.    *  @param  a  A thing of arbitrary type.    *  @param  b  Another thing of arbitrary type.    *  @param  comp  A @link s20_3_3_comparisons comparison functor@endlink.    *  @return   The lesser of the parameters.    *    *  This will work on temporary expressions, since they are only evaluated    *  once, unlike a preprocessor macro.   */
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_Tp
operator|,
name|typename
name|_Compare
operator|>
specifier|inline
specifier|const
name|_Tp
operator|&
name|min
argument_list|(
argument|const _Tp& __a
argument_list|,
argument|const _Tp& __b
argument_list|,
argument|_Compare __comp
argument_list|)
block|{
comment|//return __comp(__b, __a) ? __b : __a;
if|if
condition|(
name|__comp
argument_list|(
name|__b
argument_list|,
name|__a
argument_list|)
condition|)
return|return
name|__b
return|;
end_expr_stmt

begin_return
return|return
name|__a
return|;
end_return

begin_comment
unit|}
comment|/**    *  @brief This does what you think it does.    *  @param  a  A thing of arbitrary type.    *  @param  b  Another thing of arbitrary type.    *  @param  comp  A @link s20_3_3_comparisons comparison functor@endlink.    *  @return   The greater of the parameters.    *    *  This will work on temporary expressions, since they are only evaluated    *  once, unlike a preprocessor macro.   */
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_Tp
operator|,
name|typename
name|_Compare
operator|>
specifier|inline
specifier|const
name|_Tp
operator|&
name|max
argument_list|(
argument|const _Tp& __a
argument_list|,
argument|const _Tp& __b
argument_list|,
argument|_Compare __comp
argument_list|)
block|{
comment|//return __comp(__a, __b) ? __b : __a;
if|if
condition|(
name|__comp
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
condition|)
return|return
name|__b
return|;
end_expr_stmt

begin_return
return|return
name|__a
return|;
end_return

begin_comment
unit|}
comment|//--------------------------------------------------
end_comment

begin_comment
comment|// copy
end_comment

begin_comment
comment|// All of these auxiliary functions serve two purposes.  (1) Replace
end_comment

begin_comment
comment|// calls to copy with memmove whenever possible.  (Memmove, not memcpy,
end_comment

begin_comment
comment|// because the input and output ranges are permitted to overlap.)
end_comment

begin_comment
comment|// (2) If we're using random access iterators, then write the loop as
end_comment

begin_comment
comment|// a for loop with an explicit count.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_InputIter
operator|,
name|typename
name|_OutputIter
operator|>
specifier|inline
name|_OutputIter
name|__copy
argument_list|(
argument|_InputIter __first
argument_list|,
argument|_InputIter __last
argument_list|,
argument|_OutputIter __result
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
name|__result
operator|,
operator|++
name|__first
control|)
operator|*
name|__result
operator|=
operator|*
name|__first
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__result
return|;
end_return

begin_expr_stmt
unit|}    template
operator|<
name|typename
name|_RandomAccessIter
operator|,
name|typename
name|_OutputIter
operator|>
specifier|inline
name|_OutputIter
name|__copy
argument_list|(
argument|_RandomAccessIter __first
argument_list|,
argument|_RandomAccessIter __last
argument_list|,
argument|_OutputIter __result
argument_list|,
argument|random_access_iterator_tag
argument_list|)
block|{
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_RandomAccessIter
operator|>
operator|::
name|difference_type
name|_Distance
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
name|_Distance
name|__n
init|=
name|__last
operator|-
name|__first
init|;
name|__n
operator|>
literal|0
condition|;
operator|--
name|__n
control|)
block|{
operator|*
name|__result
operator|=
operator|*
name|__first
expr_stmt|;
operator|++
name|__first
expr_stmt|;
operator|++
name|__result
expr_stmt|;
block|}
end_for

begin_return
return|return
name|__result
return|;
end_return

begin_expr_stmt
unit|}    template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|_Tp
operator|*
name|__copy_trivial
argument_list|(
argument|const _Tp* __first
argument_list|,
argument|const _Tp* __last
argument_list|,
argument|_Tp* __result
argument_list|)
block|{
name|memmove
argument_list|(
name|__result
argument_list|,
name|__first
argument_list|,
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
operator|*
operator|(
name|__last
operator|-
name|__first
operator|)
argument_list|)
block|;
return|return
name|__result
operator|+
operator|(
name|__last
operator|-
name|__first
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_InputIter
operator|,
name|typename
name|_OutputIter
operator|>
specifier|inline
name|_OutputIter
name|__copy_aux2
argument_list|(
argument|_InputIter __first
argument_list|,
argument|_InputIter __last
argument_list|,
argument|_OutputIter __result
argument_list|,
argument|__false_type
argument_list|)
block|{
return|return
name|__copy
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__result
argument_list|,
name|__iterator_category
argument_list|(
name|__first
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_InputIter
operator|,
name|typename
name|_OutputIter
operator|>
specifier|inline
name|_OutputIter
name|__copy_aux2
argument_list|(
argument|_InputIter __first
argument_list|,
argument|_InputIter __last
argument_list|,
argument|_OutputIter __result
argument_list|,
argument|__true_type
argument_list|)
block|{
return|return
name|__copy
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__result
argument_list|,
name|__iterator_category
argument_list|(
name|__first
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|_Tp
operator|*
name|__copy_aux2
argument_list|(
argument|_Tp* __first
argument_list|,
argument|_Tp* __last
argument_list|,
argument|_Tp* __result
argument_list|,
argument|__true_type
argument_list|)
block|{
return|return
name|__copy_trivial
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__result
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|_Tp
operator|*
name|__copy_aux2
argument_list|(
argument|const _Tp* __first
argument_list|,
argument|const _Tp* __last
argument_list|,
argument|_Tp* __result
argument_list|,
argument|__true_type
argument_list|)
block|{
return|return
name|__copy_trivial
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__result
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_InputIter
operator|,
name|typename
name|_OutputIter
operator|>
specifier|inline
name|_OutputIter
name|__copy_ni2
argument_list|(
argument|_InputIter __first
argument_list|,
argument|_InputIter __last
argument_list|,
argument|_OutputIter __result
argument_list|,
argument|__true_type
argument_list|)
block|{
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_InputIter
operator|>
operator|::
name|value_type
name|_ValueType
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|__type_traits
operator|<
name|_ValueType
operator|>
operator|::
name|has_trivial_assignment_operator
name|_Trivial
expr_stmt|;
end_typedef

begin_return
return|return
name|_OutputIter
argument_list|(
name|__copy_aux2
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__result
operator|.
name|base
argument_list|()
argument_list|,
name|_Trivial
argument_list|()
argument_list|)
argument_list|)
return|;
end_return

begin_expr_stmt
unit|}    template
operator|<
name|typename
name|_InputIter
operator|,
name|typename
name|_OutputIter
operator|>
specifier|inline
name|_OutputIter
name|__copy_ni2
argument_list|(
argument|_InputIter __first
argument_list|,
argument|_InputIter __last
argument_list|,
argument|_OutputIter __result
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
name|value_type
name|_ValueType
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|__type_traits
operator|<
name|_ValueType
operator|>
operator|::
name|has_trivial_assignment_operator
name|_Trivial
expr_stmt|;
end_typedef

begin_return
return|return
name|__copy_aux2
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__result
argument_list|,
name|_Trivial
argument_list|()
argument_list|)
return|;
end_return

begin_expr_stmt
unit|}    template
operator|<
name|typename
name|_InputIter
operator|,
name|typename
name|_OutputIter
operator|>
specifier|inline
name|_OutputIter
name|__copy_ni1
argument_list|(
argument|_InputIter __first
argument_list|,
argument|_InputIter __last
argument_list|,
argument|_OutputIter __result
argument_list|,
argument|__true_type
argument_list|)
block|{
typedef|typedef
name|typename
name|_Is_normal_iterator
operator|<
name|_OutputIter
operator|>
operator|::
name|_Normal
name|__Normal
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__copy_ni2
argument_list|(
name|__first
operator|.
name|base
argument_list|()
argument_list|,
name|__last
operator|.
name|base
argument_list|()
argument_list|,
name|__result
argument_list|,
name|__Normal
argument_list|()
argument_list|)
return|;
end_return

begin_expr_stmt
unit|}    template
operator|<
name|typename
name|_InputIter
operator|,
name|typename
name|_OutputIter
operator|>
specifier|inline
name|_OutputIter
name|__copy_ni1
argument_list|(
argument|_InputIter __first
argument_list|,
argument|_InputIter __last
argument_list|,
argument|_OutputIter __result
argument_list|,
argument|__false_type
argument_list|)
block|{
typedef|typedef
name|typename
name|_Is_normal_iterator
operator|<
name|_OutputIter
operator|>
operator|::
name|_Normal
name|__Normal
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__copy_ni2
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__result
argument_list|,
name|__Normal
argument_list|()
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|/**    *  @brief Copies the range [first,last) into result.    *  @param  first  An input iterator.    *  @param  last   An input iterator.    *  @param  result An output iterator.    *  @return   result + (first - last)    *    *  This inline function will boil down to a call to @c memmove whenever    *  possible.  Failing that, if random access iterators are passed, then the    *  loop count will be known (and therefore a candidate for compiler    *  optimizations such as unrolling).  If the input range and the output    *  range overlap, then the copy_backward function should be used instead.   */
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_InputIter
operator|,
name|typename
name|_OutputIter
operator|>
specifier|inline
name|_OutputIter
name|copy
argument_list|(
argument|_InputIter __first
argument_list|,
argument|_InputIter __last
argument_list|,
argument|_OutputIter __result
argument_list|)
block|{
comment|// concept requirements
name|__glibcpp_function_requires
argument_list|(
argument|_InputIteratorConcept<_InputIter>
argument_list|)
name|__glibcpp_function_requires
argument_list|(
argument|_OutputIteratorConcept<_OutputIter
argument_list|,
argument|typename iterator_traits<_InputIter>::value_type>
argument_list|)
typedef|typedef
name|typename
name|_Is_normal_iterator
operator|<
name|_InputIter
operator|>
operator|::
name|_Normal
name|__Normal
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__copy_ni1
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__result
argument_list|,
name|__Normal
argument_list|()
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|//--------------------------------------------------
end_comment

begin_comment
comment|// copy_backward
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_BidirectionalIter1
operator|,
name|typename
name|_BidirectionalIter2
operator|>
specifier|inline
name|_BidirectionalIter2
name|__copy_backward
argument_list|(
argument|_BidirectionalIter1 __first
argument_list|,
argument|_BidirectionalIter1 __last
argument_list|,
argument|_BidirectionalIter2 __result
argument_list|,
argument|bidirectional_iterator_tag
argument_list|)
block|{
while|while
condition|(
name|__first
operator|!=
name|__last
condition|)
operator|*
operator|--
name|__result
operator|=
operator|*
operator|--
name|__last
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__result
return|;
end_return

begin_expr_stmt
unit|}    template
operator|<
name|typename
name|_RandomAccessIter
operator|,
name|typename
name|_BidirectionalIter
operator|>
specifier|inline
name|_BidirectionalIter
name|__copy_backward
argument_list|(
argument|_RandomAccessIter __first
argument_list|,
argument|_RandomAccessIter __last
argument_list|,
argument|_BidirectionalIter __result
argument_list|,
argument|random_access_iterator_tag
argument_list|)
block|{
name|typename
name|iterator_traits
operator|<
name|_RandomAccessIter
operator|>
operator|::
name|difference_type
name|__n
block|;
for|for
control|(
name|__n
operator|=
name|__last
operator|-
name|__first
init|;
name|__n
operator|>
literal|0
condition|;
operator|--
name|__n
control|)
operator|*
operator|--
name|__result
operator|=
operator|*
operator|--
name|__last
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__result
return|;
end_return

begin_comment
unit|}
comment|// This dispatch class is a workaround for compilers that do not
end_comment

begin_comment
comment|// have partial ordering of function templates.  All we're doing is
end_comment

begin_comment
comment|// creating a specialization so that we can turn a call to copy_backward
end_comment

begin_comment
comment|// into a memmove whenever possible.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_BidirectionalIter1
operator|,
name|typename
name|_BidirectionalIter2
operator|,
name|typename
name|_BoolType
operator|>
expr|struct
name|__copy_backward_dispatch
block|{
specifier|static
name|_BidirectionalIter2
name|copy
argument_list|(
argument|_BidirectionalIter1 __first
argument_list|,
argument|_BidirectionalIter1 __last
argument_list|,
argument|_BidirectionalIter2 __result
argument_list|)
block|{
return|return
name|__copy_backward
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__result
argument_list|,
name|__iterator_category
argument_list|(
name|__first
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|__copy_backward_dispatch
operator|<
name|_Tp
operator|*
operator|,
name|_Tp
operator|*
operator|,
name|__true_type
operator|>
block|{
specifier|static
name|_Tp
operator|*
name|copy
argument_list|(
argument|const _Tp* __first
argument_list|,
argument|const _Tp* __last
argument_list|,
argument|_Tp* __result
argument_list|)
block|{
specifier|const
name|ptrdiff_t
name|_Num
operator|=
name|__last
operator|-
name|__first
block|;
name|memmove
argument_list|(
name|__result
operator|-
name|_Num
argument_list|,
name|__first
argument_list|,
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
operator|*
name|_Num
argument_list|)
block|;
return|return
name|__result
operator|-
name|_Num
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|__copy_backward_dispatch
operator|<
specifier|const
name|_Tp
operator|*
operator|,
name|_Tp
operator|*
operator|,
name|__true_type
operator|>
block|{
specifier|static
name|_Tp
operator|*
name|copy
argument_list|(
argument|const _Tp* __first
argument_list|,
argument|const _Tp* __last
argument_list|,
argument|_Tp* __result
argument_list|)
block|{
return|return
name|__copy_backward_dispatch
operator|<
name|_Tp
operator|*
operator|,
name|_Tp
operator|*
operator|,
name|__true_type
operator|>
operator|::
name|copy
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__result
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_BI1
operator|,
name|typename
name|_BI2
operator|>
specifier|inline
name|_BI2
name|__copy_backward_aux
argument_list|(
argument|_BI1 __first
argument_list|,
argument|_BI1 __last
argument_list|,
argument|_BI2 __result
argument_list|)
block|{
typedef|typedef
name|typename
name|__type_traits
operator|<
name|typename
name|iterator_traits
operator|<
name|_BI2
operator|>
operator|::
name|value_type
operator|>
operator|::
name|has_trivial_assignment_operator
name|_Trivial
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__copy_backward_dispatch
operator|<
name|_BI1
operator|,
name|_BI2
operator|,
name|_Trivial
operator|>
operator|::
name|copy
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__result
argument_list|)
return|;
end_return

begin_expr_stmt
unit|}    template
operator|<
name|typename
name|_BI1
operator|,
name|typename
name|_BI2
operator|>
specifier|inline
name|_BI2
name|__copy_backward_output_normal_iterator
argument_list|(
argument|_BI1 __first
argument_list|,
argument|_BI1 __last
argument_list|,
argument|_BI2 __result
argument_list|,
argument|__true_type
argument_list|)
block|{
return|return
name|_BI2
argument_list|(
name|__copy_backward_aux
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__result
operator|.
name|base
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_BI1
operator|,
name|typename
name|_BI2
operator|>
specifier|inline
name|_BI2
name|__copy_backward_output_normal_iterator
argument_list|(
argument|_BI1 __first
argument_list|,
argument|_BI1 __last
argument_list|,
argument|_BI2 __result
argument_list|,
argument|__false_type
argument_list|)
block|{
return|return
name|__copy_backward_aux
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__result
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_BI1
operator|,
name|typename
name|_BI2
operator|>
specifier|inline
name|_BI2
name|__copy_backward_input_normal_iterator
argument_list|(
argument|_BI1 __first
argument_list|,
argument|_BI1 __last
argument_list|,
argument|_BI2 __result
argument_list|,
argument|__true_type
argument_list|)
block|{
typedef|typedef
name|typename
name|_Is_normal_iterator
operator|<
name|_BI2
operator|>
operator|::
name|_Normal
name|__Normal
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__copy_backward_output_normal_iterator
argument_list|(
name|__first
operator|.
name|base
argument_list|()
argument_list|,
name|__last
operator|.
name|base
argument_list|()
argument_list|,
name|__result
argument_list|,
name|__Normal
argument_list|()
argument_list|)
return|;
end_return

begin_expr_stmt
unit|}    template
operator|<
name|typename
name|_BI1
operator|,
name|typename
name|_BI2
operator|>
specifier|inline
name|_BI2
name|__copy_backward_input_normal_iterator
argument_list|(
argument|_BI1 __first
argument_list|,
argument|_BI1 __last
argument_list|,
argument|_BI2 __result
argument_list|,
argument|__false_type
argument_list|)
block|{
typedef|typedef
name|typename
name|_Is_normal_iterator
operator|<
name|_BI2
operator|>
operator|::
name|_Normal
name|__Normal
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__copy_backward_output_normal_iterator
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__result
argument_list|,
name|__Normal
argument_list|()
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|/**    *  @brief Copies the range [first,last) into result.    *  @param  first  An input iterator.    *  @param  last   An input iterator.    *  @param  result An output iterator.    *  @return   result - (first - last)    *    *  The function has the same effect as copy, but starts at the end of the    *  range and works its way to the start, returning the start of the result.    *  This inline function will boil down to a call to @c memmove whenever    *  possible.  Failing that, if random access iterators are passed, then the    *  loop count will be known (and therefore a candidate for compiler    *  optimizations such as unrolling).   */
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_BI1
operator|,
name|typename
name|_BI2
operator|>
specifier|inline
name|_BI2
name|copy_backward
argument_list|(
argument|_BI1 __first
argument_list|,
argument|_BI1 __last
argument_list|,
argument|_BI2 __result
argument_list|)
block|{
comment|// concept requirements
name|__glibcpp_function_requires
argument_list|(
argument|_BidirectionalIteratorConcept<_BI1>
argument_list|)
name|__glibcpp_function_requires
argument_list|(
argument|_Mutable_BidirectionalIteratorConcept<_BI2>
argument_list|)
name|__glibcpp_function_requires
argument_list|(
argument|_ConvertibleConcept< 	    typename iterator_traits<_BI1>::value_type
argument_list|,
argument|typename iterator_traits<_BI2>::value_type>
argument_list|)
typedef|typedef
name|typename
name|_Is_normal_iterator
operator|<
name|_BI1
operator|>
operator|::
name|_Normal
name|__Normal
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__copy_backward_input_normal_iterator
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__result
argument_list|,
name|__Normal
argument_list|()
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|//--------------------------------------------------
end_comment

begin_comment
comment|// fill and fill_n
end_comment

begin_comment
comment|/**    *  @brief Fills the range [first,last) with copies of value.    *  @param  first  A forward iterator.    *  @param  last   A forward iterator.    *  @param  value  A reference-to-const of arbitrary type.    *  @return   Nothing.    *    *  This function fills a range with copies of the same value.  For one-byte    *  types filling contiguous areas of memory, this becomes an inline call to    *  @c memset.   */
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_ForwardIter
operator|,
name|typename
name|_Tp
operator|>
name|void
name|fill
argument_list|(
argument|_ForwardIter __first
argument_list|,
argument|_ForwardIter __last
argument_list|,
argument|const _Tp& __value
argument_list|)
block|{
comment|// concept requirements
name|__glibcpp_function_requires
argument_list|(
argument|_Mutable_ForwardIteratorConcept<_ForwardIter>
argument_list|)
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
operator|*
name|__first
operator|=
name|__value
expr_stmt|;
block|}
end_expr_stmt

begin_comment
comment|/**    *  @brief Fills the range [first,first+n) with copies of value.    *  @param  first  An output iterator.    *  @param  n      The count of copies to perform.    *  @param  value  A reference-to-const of arbitrary type.    *  @return   The iterator at first+n.    *    *  This function fills a range with copies of the same value.  For one-byte    *  types filling contiguous areas of memory, this becomes an inline call to    *  @c memset.   */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_OutputIter
operator|,
name|typename
name|_Size
operator|,
name|typename
name|_Tp
operator|>
name|_OutputIter
name|fill_n
argument_list|(
argument|_OutputIter __first
argument_list|,
argument|_Size __n
argument_list|,
argument|const _Tp& __value
argument_list|)
block|{
comment|// concept requirements
name|__glibcpp_function_requires
argument_list|(
argument|_OutputIteratorConcept<_OutputIter
argument_list|,
argument|_Tp>
argument_list|)
for|for
control|(
init|;
name|__n
operator|>
literal|0
condition|;
operator|--
name|__n
operator|,
operator|++
name|__first
control|)
operator|*
name|__first
operator|=
name|__value
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__first
return|;
end_return

begin_comment
unit|}
comment|// Specialization: for one-byte types we can use memset.
end_comment

begin_function
unit|inline
name|void
name|fill
parameter_list|(
name|unsigned
name|char
modifier|*
name|__first
parameter_list|,
name|unsigned
name|char
modifier|*
name|__last
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|&
name|__c
parameter_list|)
block|{
name|unsigned
name|char
name|__tmp
init|=
name|__c
decl_stmt|;
name|memset
argument_list|(
name|__first
argument_list|,
name|__tmp
argument_list|,
name|__last
operator|-
name|__first
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|inline
name|void
name|fill
parameter_list|(
name|signed
name|char
modifier|*
name|__first
parameter_list|,
name|signed
name|char
modifier|*
name|__last
parameter_list|,
specifier|const
name|signed
name|char
modifier|&
name|__c
parameter_list|)
block|{
name|signed
name|char
name|__tmp
init|=
name|__c
decl_stmt|;
name|memset
argument_list|(
argument|__first
argument_list|,
argument|static_cast<unsigned char>(__tmp)
argument_list|,
argument|__last - __first
argument_list|)
empty_stmt|;
block|}
end_function

begin_function
specifier|inline
name|void
name|fill
parameter_list|(
name|char
modifier|*
name|__first
parameter_list|,
name|char
modifier|*
name|__last
parameter_list|,
specifier|const
name|char
modifier|&
name|__c
parameter_list|)
block|{
name|char
name|__tmp
init|=
name|__c
decl_stmt|;
name|memset
argument_list|(
argument|__first
argument_list|,
argument|static_cast<unsigned char>(__tmp)
argument_list|,
argument|__last - __first
argument_list|)
empty_stmt|;
block|}
end_function

begin_expr_stmt
name|template
operator|<
name|typename
name|_Size
operator|>
specifier|inline
name|unsigned
name|char
operator|*
name|fill_n
argument_list|(
argument|unsigned char* __first
argument_list|,
argument|_Size __n
argument_list|,
argument|const unsigned char& __c
argument_list|)
block|{
name|fill
argument_list|(
name|__first
argument_list|,
name|__first
operator|+
name|__n
argument_list|,
name|__c
argument_list|)
block|;
return|return
name|__first
operator|+
name|__n
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_Size
operator|>
specifier|inline
name|signed
name|char
operator|*
name|fill_n
argument_list|(
argument|char* __first
argument_list|,
argument|_Size __n
argument_list|,
argument|const signed char& __c
argument_list|)
block|{
name|fill
argument_list|(
name|__first
argument_list|,
name|__first
operator|+
name|__n
argument_list|,
name|__c
argument_list|)
block|;
return|return
name|__first
operator|+
name|__n
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_Size
operator|>
specifier|inline
name|char
operator|*
name|fill_n
argument_list|(
argument|char* __first
argument_list|,
argument|_Size __n
argument_list|,
argument|const char& __c
argument_list|)
block|{
name|fill
argument_list|(
name|__first
argument_list|,
name|__first
operator|+
name|__n
argument_list|,
name|__c
argument_list|)
block|;
return|return
name|__first
operator|+
name|__n
return|;
block|}
end_expr_stmt

begin_comment
comment|//--------------------------------------------------
end_comment

begin_comment
comment|// equal and mismatch
end_comment

begin_comment
comment|/**    *  @brief Finds the places in ranges which don't match.    *  @param  first1  An input iterator.    *  @param  last1   An input iterator.    *  @param  first2  An input iterator.    *  @return   A pair of iterators pointing to the first mismatch.    *    *  This compares the elements of two ranges using @c == and returns a pair    *  of iterators.  The first iterator points into the first range, the    *  second iterator points into the second range, and the elements pointed    *  to by the iterators are not equal.   */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_InputIter1
operator|,
name|typename
name|_InputIter2
operator|>
name|pair
operator|<
name|_InputIter1
operator|,
name|_InputIter2
operator|>
name|mismatch
argument_list|(
argument|_InputIter1 __first1
argument_list|,
argument|_InputIter1 __last1
argument_list|,
argument|_InputIter2 __first2
argument_list|)
block|{
comment|// concept requirements
name|__glibcpp_function_requires
argument_list|(
argument|_InputIteratorConcept<_InputIter1>
argument_list|)
name|__glibcpp_function_requires
argument_list|(
argument|_InputIteratorConcept<_InputIter2>
argument_list|)
name|__glibcpp_function_requires
argument_list|(
argument|_EqualityComparableConcept< 	    typename iterator_traits<_InputIter1>::value_type>
argument_list|)
name|__glibcpp_function_requires
argument_list|(
argument|_EqualityComparableConcept< 	    typename iterator_traits<_InputIter2>::value_type>
argument_list|)
while|while
condition|(
name|__first1
operator|!=
name|__last1
operator|&&
operator|*
name|__first1
operator|==
operator|*
name|__first2
condition|)
block|{
operator|++
name|__first1
expr_stmt|;
operator|++
name|__first2
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
name|pair
operator|<
name|_InputIter1
operator|,
name|_InputIter2
operator|>
operator|(
name|__first1
operator|,
name|__first2
operator|)
return|;
end_return

begin_comment
unit|}
comment|/**    *  @brief Finds the places in ranges which don't match.    *  @param  first1  An input iterator.    *  @param  last1   An input iterator.    *  @param  first2  An input iterator.    *  @param  binary_pred  A binary predicate @link s20_3_1_base functor@endlink.    *  @return   A pair of iterators pointing to the first mismatch.    *    *  This compares the elements of two ranges using the binary_pred    *  parameter, and returns a pair    *  of iterators.  The first iterator points into the first range, the    *  second iterator points into the second range, and the elements pointed    *  to by the iterators are not equal.   */
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_InputIter1
operator|,
name|typename
name|_InputIter2
operator|,
name|typename
name|_BinaryPredicate
operator|>
name|pair
operator|<
name|_InputIter1
operator|,
name|_InputIter2
operator|>
name|mismatch
argument_list|(
argument|_InputIter1 __first1
argument_list|,
argument|_InputIter1 __last1
argument_list|,
argument|_InputIter2 __first2
argument_list|,
argument|_BinaryPredicate __binary_pred
argument_list|)
block|{
comment|// concept requirements
name|__glibcpp_function_requires
argument_list|(
argument|_InputIteratorConcept<_InputIter1>
argument_list|)
name|__glibcpp_function_requires
argument_list|(
argument|_InputIteratorConcept<_InputIter2>
argument_list|)
while|while
condition|(
name|__first1
operator|!=
name|__last1
operator|&&
name|__binary_pred
argument_list|(
operator|*
name|__first1
argument_list|,
operator|*
name|__first2
argument_list|)
condition|)
block|{
operator|++
name|__first1
expr_stmt|;
operator|++
name|__first2
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
name|pair
operator|<
name|_InputIter1
operator|,
name|_InputIter2
operator|>
operator|(
name|__first1
operator|,
name|__first2
operator|)
return|;
end_return

begin_comment
unit|}
comment|/**    *  @brief Tests a range for element-wise equality.    *  @param  first1  An input iterator.    *  @param  last1   An input iterator.    *  @param  first2  An input iterator.    *  @return   A boolean true or false.    *    *  This compares the elements of two ranges using @c == and returns true or    *  false depending on whether all of the corresponding elements of the    *  ranges are equal.   */
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_InputIter1
operator|,
name|typename
name|_InputIter2
operator|>
specifier|inline
name|bool
name|equal
argument_list|(
argument|_InputIter1 __first1
argument_list|,
argument|_InputIter1 __last1
argument_list|,
argument|_InputIter2 __first2
argument_list|)
block|{
comment|// concept requirements
name|__glibcpp_function_requires
argument_list|(
argument|_InputIteratorConcept<_InputIter1>
argument_list|)
name|__glibcpp_function_requires
argument_list|(
argument|_InputIteratorConcept<_InputIter2>
argument_list|)
name|__glibcpp_function_requires
argument_list|(
argument|_EqualOpConcept< 	    typename iterator_traits<_InputIter1>::value_type
argument_list|,
argument|typename iterator_traits<_InputIter2>::value_type>
argument_list|)
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
if|if
condition|(
operator|!
operator|(
operator|*
name|__first1
operator|==
operator|*
name|__first2
operator|)
condition|)
return|return
name|false
return|;
end_expr_stmt

begin_return
return|return
name|true
return|;
end_return

begin_comment
unit|}
comment|/**    *  @brief Tests a range for element-wise equality.    *  @param  first1  An input iterator.    *  @param  last1   An input iterator.    *  @param  first2  An input iterator.    *  @param  binary_pred  A binary predicate @link s20_3_1_base functor@endlink.    *  @return   A boolean true or false.    *    *  This compares the elements of two ranges using the binary_pred    *  parameter, and returns true or    *  false depending on whether all of the corresponding elements of the    *  ranges are equal.   */
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_InputIter1
operator|,
name|typename
name|_InputIter2
operator|,
name|typename
name|_BinaryPredicate
operator|>
specifier|inline
name|bool
name|equal
argument_list|(
argument|_InputIter1 __first1
argument_list|,
argument|_InputIter1 __last1
argument_list|,
argument|_InputIter2 __first2
argument_list|,
argument|_BinaryPredicate __binary_pred
argument_list|)
block|{
comment|// concept requirements
name|__glibcpp_function_requires
argument_list|(
argument|_InputIteratorConcept<_InputIter1>
argument_list|)
name|__glibcpp_function_requires
argument_list|(
argument|_InputIteratorConcept<_InputIter2>
argument_list|)
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
if|if
condition|(
operator|!
name|__binary_pred
argument_list|(
operator|*
name|__first1
argument_list|,
operator|*
name|__first2
argument_list|)
condition|)
return|return
name|false
return|;
end_expr_stmt

begin_return
return|return
name|true
return|;
end_return

begin_comment
unit|}
comment|//--------------------------------------------------
end_comment

begin_comment
comment|// lexicographical_compare
end_comment

begin_comment
comment|/**    *  @brief Performs "dictionary" comparison on ranges.    *  @param  first1  An input iterator.    *  @param  last1   An input iterator.    *  @param  first2  An input iterator.    *  @param  last2   An input iterator.    *  @return   A boolean true or false.    *    *  "Returns true if the sequence of elements defined by the range    *  [first1,last1) is lexicographically less than the sequence of elements    *  defined by the range [first2,last2).  Returns false otherwise."    *  (Quoted from [25.3.8]/1.)  If the iterators are all character pointers,    *  then this is an inline call to @c memcmp.   */
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_InputIter1
operator|,
name|typename
name|_InputIter2
operator|>
name|bool
name|lexicographical_compare
argument_list|(
argument|_InputIter1 __first1
argument_list|,
argument|_InputIter1 __last1
argument_list|,
argument|_InputIter2 __first2
argument_list|,
argument|_InputIter2 __last2
argument_list|)
block|{
comment|// concept requirements
name|__glibcpp_function_requires
argument_list|(
argument|_InputIteratorConcept<_InputIter1>
argument_list|)
name|__glibcpp_function_requires
argument_list|(
argument|_InputIteratorConcept<_InputIter2>
argument_list|)
name|__glibcpp_function_requires
argument_list|(
argument|_LessThanComparableConcept< 	    typename iterator_traits<_InputIter1>::value_type>
argument_list|)
name|__glibcpp_function_requires
argument_list|(
argument|_LessThanComparableConcept< 	    typename iterator_traits<_InputIter2>::value_type>
argument_list|)
for|for
control|(
init|;
name|__first1
operator|!=
name|__last1
operator|&&
name|__first2
operator|!=
name|__last2
condition|;
operator|++
name|__first1
operator|,
operator|++
name|__first2
control|)
block|{
if|if
condition|(
operator|*
name|__first1
operator|<
operator|*
name|__first2
condition|)
return|return
name|true
return|;
if|if
condition|(
operator|*
name|__first2
operator|<
operator|*
name|__first1
condition|)
return|return
name|false
return|;
block|}
end_expr_stmt

begin_return
return|return
name|__first1
operator|==
name|__last1
operator|&&
name|__first2
operator|!=
name|__last2
return|;
end_return

begin_comment
unit|}
comment|/**    *  @brief Performs "dictionary" comparison on ranges.    *  @param  first1  An input iterator.    *  @param  last1   An input iterator.    *  @param  first2  An input iterator.    *  @param  last2   An input iterator.    *  @param  comp  A @link s20_3_3_comparisons comparison functor@endlink.    *  @return   A boolean true or false.    *    *  The same as the four-parameter @c lexigraphical_compare, but uses the    *  comp parameter instead of @c<.   */
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_InputIter1
operator|,
name|typename
name|_InputIter2
operator|,
name|typename
name|_Compare
operator|>
name|bool
name|lexicographical_compare
argument_list|(
argument|_InputIter1 __first1
argument_list|,
argument|_InputIter1 __last1
argument_list|,
argument|_InputIter2 __first2
argument_list|,
argument|_InputIter2 __last2
argument_list|,
argument|_Compare __comp
argument_list|)
block|{
comment|// concept requirements
name|__glibcpp_function_requires
argument_list|(
argument|_InputIteratorConcept<_InputIter1>
argument_list|)
name|__glibcpp_function_requires
argument_list|(
argument|_InputIteratorConcept<_InputIter2>
argument_list|)
for|for
control|(
init|;
name|__first1
operator|!=
name|__last1
operator|&&
name|__first2
operator|!=
name|__last2
condition|;
operator|++
name|__first1
operator|,
operator|++
name|__first2
control|)
block|{
if|if
condition|(
name|__comp
argument_list|(
operator|*
name|__first1
argument_list|,
operator|*
name|__first2
argument_list|)
condition|)
return|return
name|true
return|;
if|if
condition|(
name|__comp
argument_list|(
operator|*
name|__first2
argument_list|,
operator|*
name|__first1
argument_list|)
condition|)
return|return
name|false
return|;
block|}
end_expr_stmt

begin_return
return|return
name|__first1
operator|==
name|__last1
operator|&&
name|__first2
operator|!=
name|__last2
return|;
end_return

begin_function
unit|}    inline
name|bool
name|lexicographical_compare
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|__first1
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|__last1
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|__first2
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|__last2
parameter_list|)
block|{
specifier|const
name|size_t
name|__len1
init|=
name|__last1
operator|-
name|__first1
decl_stmt|;
specifier|const
name|size_t
name|__len2
init|=
name|__last2
operator|-
name|__first2
decl_stmt|;
specifier|const
name|int
name|__result
init|=
name|memcmp
argument_list|(
name|__first1
argument_list|,
name|__first2
argument_list|,
name|min
argument_list|(
name|__len1
argument_list|,
name|__len2
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|__result
operator|!=
literal|0
condition|?
name|__result
operator|<
literal|0
else|:
name|__len1
operator|<
name|__len2
return|;
block|}
end_function

begin_function
specifier|inline
name|bool
name|lexicographical_compare
parameter_list|(
specifier|const
name|char
modifier|*
name|__first1
parameter_list|,
specifier|const
name|char
modifier|*
name|__last1
parameter_list|,
specifier|const
name|char
modifier|*
name|__first2
parameter_list|,
specifier|const
name|char
modifier|*
name|__last2
parameter_list|)
block|{
if|#
directive|if
name|CHAR_MAX
operator|==
name|SCHAR_MAX
return|return
name|lexicographical_compare
argument_list|(
operator|(
specifier|const
name|signed
name|char
operator|*
operator|)
name|__first1
argument_list|,
operator|(
specifier|const
name|signed
name|char
operator|*
operator|)
name|__last1
argument_list|,
operator|(
specifier|const
name|signed
name|char
operator|*
operator|)
name|__first2
argument_list|,
operator|(
specifier|const
name|signed
name|char
operator|*
operator|)
name|__last2
argument_list|)
return|;
else|#
directive|else
comment|/* CHAR_MAX == SCHAR_MAX */
return|return
name|lexicographical_compare
argument_list|(
operator|(
specifier|const
name|unsigned
name|char
operator|*
operator|)
name|__first1
argument_list|,
operator|(
specifier|const
name|unsigned
name|char
operator|*
operator|)
name|__last1
argument_list|,
operator|(
specifier|const
name|unsigned
name|char
operator|*
operator|)
name|__first2
argument_list|,
operator|(
specifier|const
name|unsigned
name|char
operator|*
operator|)
name|__last2
argument_list|)
return|;
endif|#
directive|endif
comment|/* CHAR_MAX == SCHAR_MAX */
block|}
end_function

begin_comment
unit|}
comment|// namespace std
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GLIBCPP_INTERNAL_ALGOBASE_H */
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

