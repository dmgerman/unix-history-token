begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Functions used by iterators -*- C++ -*-
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
comment|/** @file stl_iterator_base_funcs.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  *  *  This file contains all of the general iterator-related utility  *  functions, such as distance() and advance().  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GLIBCPP_INTERNAL_ITERATOR_BASE_FUNCS_H
end_ifndef

begin_define
define|#
directive|define
name|__GLIBCPP_INTERNAL_ITERATOR_BASE_FUNCS_H
end_define

begin_pragma
pragma|#
directive|pragma
name|GCC
name|system_header
end_pragma

begin_include
include|#
directive|include
file|<bits/concept_check.h>
end_include

begin_decl_stmt
name|namespace
name|std
block|{
name|template
operator|<
name|typename
name|_InputIterator
operator|>
specifier|inline
name|typename
name|iterator_traits
operator|<
name|_InputIterator
operator|>
operator|::
name|difference_type
name|__distance
argument_list|(
argument|_InputIterator __first
argument_list|,
argument|_InputIterator __last
argument_list|,
argument|input_iterator_tag
argument_list|)
block|{
comment|// concept requirements
name|__glibcpp_function_requires
argument_list|(
argument|_InputIteratorConcept<_InputIterator>
argument_list|)
name|typename
name|iterator_traits
operator|<
name|_InputIterator
operator|>
operator|::
name|difference_type
name|__n
operator|=
literal|0
block|;
while|while
condition|(
name|__first
operator|!=
name|__last
condition|)
block|{
operator|++
name|__first
expr_stmt|;
operator|++
name|__n
expr_stmt|;
block|}
return|return
name|__n
return|;
block|}
name|template
operator|<
name|typename
name|_RandomAccessIterator
operator|>
specifier|inline
name|typename
name|iterator_traits
operator|<
name|_RandomAccessIterator
operator|>
operator|::
name|difference_type
name|__distance
argument_list|(
argument|_RandomAccessIterator __first
argument_list|,
argument|_RandomAccessIterator __last
argument_list|,
argument|random_access_iterator_tag
argument_list|)
block|{
comment|// concept requirements
name|__glibcpp_function_requires
argument_list|(
argument|_RandomAccessIteratorConcept<_RandomAccessIterator>
argument_list|)
return|return
name|__last
operator|-
name|__first
return|;
block|}
comment|/**    *  @brief A generalization of pointer arithmetic.    *  @param  first  An input iterator.    *  @param  last  An input iterator.    *  @return  The distance between them.    *    *  Returns @c n such that first + n == last.  This requires that @p last    *  must be reachable from @p first.  Note that @c n may be negative.    *    *  For random access iterators, this uses their @c + and @c - operations    *  and are constant time.  For other %iterator classes they are linear time.   */
name|template
operator|<
name|typename
name|_InputIterator
operator|>
specifier|inline
name|typename
name|iterator_traits
operator|<
name|_InputIterator
operator|>
operator|::
name|difference_type
name|distance
argument_list|(
argument|_InputIterator __first
argument_list|,
argument|_InputIterator __last
argument_list|)
block|{
comment|// concept requirements -- taken care of in __distance
return|return
name|__distance
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__iterator_category
argument_list|(
name|__first
argument_list|)
argument_list|)
return|;
block|}
name|template
operator|<
name|typename
name|_InputIter
operator|,
name|typename
name|_Distance
operator|>
specifier|inline
name|void
name|__advance
argument_list|(
argument|_InputIter& __i
argument_list|,
argument|_Distance __n
argument_list|,
argument|input_iterator_tag
argument_list|)
block|{
comment|// concept requirements
name|__glibcpp_function_requires
argument_list|(
argument|_InputIteratorConcept<_InputIter>
argument_list|)
while|while
condition|(
name|__n
operator|--
condition|)
operator|++
name|__i
expr_stmt|;
block|}
name|template
operator|<
name|typename
name|_BidirectionalIterator
operator|,
name|typename
name|_Distance
operator|>
specifier|inline
name|void
name|__advance
argument_list|(
argument|_BidirectionalIterator& __i
argument_list|,
argument|_Distance __n
argument_list|,
argument|bidirectional_iterator_tag
argument_list|)
block|{
comment|// concept requirements
name|__glibcpp_function_requires
argument_list|(
argument|_BidirectionalIteratorConcept<_BidirectionalIterator>
argument_list|)
if|if
condition|(
name|__n
operator|>
literal|0
condition|)
while|while
condition|(
name|__n
operator|--
condition|)
operator|++
name|__i
expr_stmt|;
else|else
while|while
condition|(
name|__n
operator|++
condition|)
operator|--
name|__i
expr_stmt|;
block|}
name|template
operator|<
name|typename
name|_RandomAccessIterator
operator|,
name|typename
name|_Distance
operator|>
specifier|inline
name|void
name|__advance
argument_list|(
argument|_RandomAccessIterator& __i
argument_list|,
argument|_Distance __n
argument_list|,
argument|random_access_iterator_tag
argument_list|)
block|{
comment|// concept requirements
name|__glibcpp_function_requires
argument_list|(
argument|_RandomAccessIteratorConcept<_RandomAccessIterator>
argument_list|)
name|__i
operator|+=
name|__n
block|;     }
comment|/**    *  @brief A generalization of pointer arithmetic.    *  @param  i  An input iterator.    *  @param  n  The "delta" by which to change @p i.    *  @return  Nothing.    *    *  This increments @p i by @p n.  For bidirectional and random access    *  iterators, @p n may be negative, in which case @p i is decremented.    *    *  For random access iterators, this uses their @c + and @c - operations    *  and are constant time.  For other %iterator classes they are linear time.   */
name|template
operator|<
name|typename
name|_InputIterator
operator|,
name|typename
name|_Distance
operator|>
specifier|inline
name|void
name|advance
argument_list|(
argument|_InputIterator& __i
argument_list|,
argument|_Distance __n
argument_list|)
block|{
comment|// concept requirements -- taken care of in __advance
name|__advance
argument_list|(
name|__i
argument_list|,
name|__n
argument_list|,
name|__iterator_category
argument_list|(
name|__i
argument_list|)
argument_list|)
block|;     }
block|}
end_decl_stmt

begin_comment
comment|// namespace std
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GLIBCPP_INTERNAL_ITERATOR_BASE_FUNCS_H */
end_comment

end_unit

