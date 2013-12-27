begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Debugging support implementation -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2003, 2005, 2006
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
comment|/** @file debug/functions.h  *  This file is a GNU debug extension to the Standard C++ Library.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GLIBCXX_DEBUG_FUNCTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|_GLIBCXX_DEBUG_FUNCTIONS_H
value|1
end_define

begin_include
include|#
directive|include
file|<bits/c++config.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|// for ptrdiff_t
end_comment

begin_include
include|#
directive|include
file|<bits/stl_iterator_base_types.h>
end_include

begin_comment
comment|// for iterator_traits, categories
end_comment

begin_include
include|#
directive|include
file|<bits/cpp_type_traits.h>
end_include

begin_comment
comment|// for __is_integer
end_comment

begin_decl_stmt
name|namespace
name|__gnu_debug
block|{
name|template
operator|<
name|typename
name|_Iterator
operator|,
name|typename
name|_Sequence
operator|>
name|class
name|_Safe_iterator
expr_stmt|;
comment|// An arbitrary iterator pointer is not singular.
specifier|inline
name|bool
name|__check_singular_aux
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|)
block|{
return|return
name|false
return|;
block|}
comment|// We may have an iterator that derives from _Safe_iterator_base but isn't
comment|// a _Safe_iterator.
name|template
operator|<
name|typename
name|_Iterator
operator|>
specifier|inline
name|bool
name|__check_singular
argument_list|(
argument|_Iterator& __x
argument_list|)
block|{
return|return
name|__check_singular_aux
argument_list|(
operator|&
name|__x
argument_list|)
return|;
block|}
comment|/** Non-NULL pointers are nonsingular. */
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|bool
name|__check_singular
argument_list|(
argument|const _Tp* __ptr
argument_list|)
block|{
return|return
name|__ptr
operator|==
literal|0
return|;
block|}
comment|/** Safe iterators know if they are singular. */
name|template
operator|<
name|typename
name|_Iterator
operator|,
name|typename
name|_Sequence
operator|>
specifier|inline
name|bool
name|__check_singular
argument_list|(
argument|const _Safe_iterator<_Iterator
argument_list|,
argument|_Sequence>& __x
argument_list|)
block|{
return|return
name|__x
operator|.
name|_M_singular
argument_list|()
return|;
block|}
comment|/** Assume that some arbitrary iterator is dereferenceable, because we       can't prove that it isn't. */
name|template
operator|<
name|typename
name|_Iterator
operator|>
specifier|inline
name|bool
name|__check_dereferenceable
argument_list|(
argument|_Iterator&
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|/** Non-NULL pointers are dereferenceable. */
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|bool
name|__check_dereferenceable
argument_list|(
argument|const _Tp* __ptr
argument_list|)
block|{
return|return
name|__ptr
return|;
block|}
comment|/** Safe iterators know if they are singular. */
name|template
operator|<
name|typename
name|_Iterator
operator|,
name|typename
name|_Sequence
operator|>
specifier|inline
name|bool
name|__check_dereferenceable
argument_list|(
argument|const _Safe_iterator<_Iterator
argument_list|,
argument|_Sequence>& __x
argument_list|)
block|{
return|return
name|__x
operator|.
name|_M_dereferenceable
argument_list|()
return|;
block|}
comment|/** If the distance between two random access iterators is    *  nonnegative, assume the range is valid.   */
name|template
operator|<
name|typename
name|_RandomAccessIterator
operator|>
specifier|inline
name|bool
name|__valid_range_aux2
argument_list|(
argument|const _RandomAccessIterator& __first
argument_list|,
argument|const _RandomAccessIterator& __last
argument_list|,
argument|std::random_access_iterator_tag
argument_list|)
block|{
return|return
name|__last
operator|-
name|__first
operator|>=
literal|0
return|;
block|}
comment|/** Can't test for a valid range with input iterators, because    *  iteration may be destructive. So we just assume that the range    *  is valid.   */
name|template
operator|<
name|typename
name|_InputIterator
operator|>
specifier|inline
name|bool
name|__valid_range_aux2
argument_list|(
argument|const _InputIterator&
argument_list|,
argument|const _InputIterator&
argument_list|,
argument|std::input_iterator_tag
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|/** We say that integral types for a valid range, and defer to other    *  routines to realize what to do with integral types instead of    *  iterators.   */
name|template
operator|<
name|typename
name|_Integral
operator|>
specifier|inline
name|bool
name|__valid_range_aux
argument_list|(
argument|const _Integral&
argument_list|,
argument|const _Integral&
argument_list|,
argument|std::__true_type
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|/** We have iterators, so figure out what kind of iterators that are    *  to see if we can check the range ahead of time.   */
name|template
operator|<
name|typename
name|_InputIterator
operator|>
specifier|inline
name|bool
name|__valid_range_aux
argument_list|(
argument|const _InputIterator& __first
argument_list|,
argument|const _InputIterator& __last
argument_list|,
argument|std::__false_type
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
name|_Category
expr_stmt|;
return|return
name|__valid_range_aux2
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|_Category
argument_list|()
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/** Don't know what these iterators are, or if they are even    *  iterators (we may get an integral type for InputIterator), so    *  see if they are integral and pass them on to the next phase    *  otherwise.   */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_InputIterator
operator|>
specifier|inline
name|bool
name|__valid_range
argument_list|(
argument|const _InputIterator& __first
argument_list|,
argument|const _InputIterator& __last
argument_list|)
block|{
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
end_expr_stmt

begin_return
return|return
name|__valid_range_aux
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|_Integral
argument_list|()
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|/** Safe iterators know how to check if they form a valid range. */
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_Iterator
operator|,
name|typename
name|_Sequence
operator|>
specifier|inline
name|bool
name|__valid_range
argument_list|(
argument|const _Safe_iterator<_Iterator
argument_list|,
argument|_Sequence>& __first
argument_list|,
argument|const _Safe_iterator<_Iterator
argument_list|,
argument|_Sequence>& __last
argument_list|)
block|{
return|return
name|__first
operator|.
name|_M_valid_range
argument_list|(
name|__last
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/* Checks that [first, last) is a valid range, and then returns    * __first. This routine is useful when we can't use a separate    * assertion statement because, e.g., we are in a constructor.   */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_InputIterator
operator|>
specifier|inline
name|_InputIterator
name|__check_valid_range
argument_list|(
argument|const _InputIterator& __first
argument_list|,
argument|const _InputIterator& __last 			__attribute__((__unused__))
argument_list|)
block|{
name|_GLIBCXX_DEBUG_ASSERT
argument_list|(
name|__valid_range
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|)
argument_list|)
block|;
return|return
name|__first
return|;
block|}
end_expr_stmt

begin_comment
comment|/** Checks that __s is non-NULL or __n == 0, and then returns __s. */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|,
name|typename
name|_Integer
operator|>
specifier|inline
specifier|const
name|_CharT
operator|*
name|__check_string
argument_list|(
argument|const _CharT* __s
argument_list|,
argument|const _Integer& __n __attribute__((__unused__))
argument_list|)
block|{
ifdef|#
directive|ifdef
name|_GLIBCXX_DEBUG_PEDANTIC
name|_GLIBCXX_DEBUG_ASSERT
argument_list|(
name|__s
operator|!=
literal|0
operator|||
name|__n
operator|==
literal|0
argument_list|)
block|;
endif|#
directive|endif
return|return
name|__s
return|;
block|}
end_expr_stmt

begin_comment
comment|/** Checks that __s is non-NULL and then returns __s. */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
specifier|inline
specifier|const
name|_CharT
operator|*
name|__check_string
argument_list|(
argument|const _CharT* __s
argument_list|)
block|{
ifdef|#
directive|ifdef
name|_GLIBCXX_DEBUG_PEDANTIC
name|_GLIBCXX_DEBUG_ASSERT
argument_list|(
name|__s
operator|!=
literal|0
argument_list|)
block|;
endif|#
directive|endif
return|return
name|__s
return|;
block|}
end_expr_stmt

begin_comment
comment|// Can't check if an input iterator sequence is sorted, because we
end_comment

begin_comment
comment|// can't step through the sequence.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_InputIterator
operator|>
specifier|inline
name|bool
name|__check_sorted_aux
argument_list|(
argument|const _InputIterator&
argument_list|,
argument|const _InputIterator&
argument_list|,
argument|std::input_iterator_tag
argument_list|)
block|{
return|return
name|true
return|;
block|}
end_expr_stmt

begin_comment
comment|// Can verify if a forward iterator sequence is in fact sorted using
end_comment

begin_comment
comment|// std::__is_sorted
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_ForwardIterator
operator|>
specifier|inline
name|bool
name|__check_sorted_aux
argument_list|(
argument|_ForwardIterator __first
argument_list|,
argument|_ForwardIterator __last
argument_list|,
argument|std::forward_iterator_tag
argument_list|)
block|{
if|if
condition|(
name|__first
operator|==
name|__last
condition|)
return|return
name|true
return|;
name|_ForwardIterator
name|__next
operator|=
name|__first
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
operator|++
name|__next
init|;
name|__next
operator|!=
name|__last
condition|;
name|__first
operator|=
name|__next
operator|,
operator|++
name|__next
control|)
block|{
if|if
condition|(
operator|*
name|__next
operator|<
operator|*
name|__first
condition|)
return|return
name|false
return|;
block|}
end_for

begin_return
return|return
name|true
return|;
end_return

begin_comment
unit|}
comment|// Can't check if an input iterator sequence is sorted, because we can't step
end_comment

begin_comment
comment|// through the sequence.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_InputIterator
operator|,
name|typename
name|_Predicate
operator|>
specifier|inline
name|bool
name|__check_sorted_aux
argument_list|(
argument|const _InputIterator&
argument_list|,
argument|const _InputIterator&
argument_list|,
argument|_Predicate
argument_list|,
argument|std::input_iterator_tag
argument_list|)
block|{
return|return
name|true
return|;
block|}
end_expr_stmt

begin_comment
comment|// Can verify if a forward iterator sequence is in fact sorted using
end_comment

begin_comment
comment|// std::__is_sorted
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_ForwardIterator
operator|,
name|typename
name|_Predicate
operator|>
specifier|inline
name|bool
name|__check_sorted_aux
argument_list|(
argument|_ForwardIterator __first
argument_list|,
argument|_ForwardIterator __last
argument_list|,
argument|_Predicate __pred
argument_list|,
argument|std::forward_iterator_tag
argument_list|)
block|{
if|if
condition|(
name|__first
operator|==
name|__last
condition|)
return|return
name|true
return|;
name|_ForwardIterator
name|__next
operator|=
name|__first
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
operator|++
name|__next
init|;
name|__next
operator|!=
name|__last
condition|;
name|__first
operator|=
name|__next
operator|,
operator|++
name|__next
control|)
block|{
if|if
condition|(
name|__pred
argument_list|(
operator|*
name|__next
argument_list|,
operator|*
name|__first
argument_list|)
condition|)
return|return
name|false
return|;
block|}
end_for

begin_return
return|return
name|true
return|;
end_return

begin_comment
unit|}
comment|// Determine if a sequence is sorted.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_InputIterator
operator|>
specifier|inline
name|bool
name|__check_sorted
argument_list|(
argument|const _InputIterator& __first
argument_list|,
argument|const _InputIterator& __last
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
name|_Category
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__check_sorted_aux
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|_Category
argument_list|()
argument_list|)
return|;
end_return

begin_expr_stmt
unit|}    template
operator|<
name|typename
name|_InputIterator
operator|,
name|typename
name|_Predicate
operator|>
specifier|inline
name|bool
name|__check_sorted
argument_list|(
argument|const _InputIterator& __first
argument_list|,
argument|const _InputIterator& __last
argument_list|,
argument|_Predicate __pred
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
name|_Category
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__check_sorted_aux
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__pred
argument_list|,
name|_Category
argument_list|()
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|// _GLIBCXX_RESOLVE_LIB_DEFECTS
end_comment

begin_comment
comment|// 270. Binary search requirements overly strict
end_comment

begin_comment
comment|// Determine if a sequence is partitioned w.r.t. this element.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_ForwardIterator
operator|,
name|typename
name|_Tp
operator|>
specifier|inline
name|bool
name|__check_partitioned
argument_list|(
argument|_ForwardIterator __first
argument_list|,
argument|_ForwardIterator __last
argument_list|,
argument|const _Tp& __value
argument_list|)
block|{
while|while
condition|(
name|__first
operator|!=
name|__last
operator|&&
operator|*
name|__first
operator|<
name|__value
condition|)
operator|++
name|__first
expr_stmt|;
end_expr_stmt

begin_while
while|while
condition|(
name|__first
operator|!=
name|__last
operator|&&
operator|!
operator|(
operator|*
name|__first
operator|<
name|__value
operator|)
condition|)
operator|++
name|__first
expr_stmt|;
end_while

begin_return
return|return
name|__first
operator|==
name|__last
return|;
end_return

begin_comment
unit|}
comment|// Determine if a sequence is partitioned w.r.t. this element.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_ForwardIterator
operator|,
name|typename
name|_Tp
operator|,
name|typename
name|_Pred
operator|>
specifier|inline
name|bool
name|__check_partitioned
argument_list|(
argument|_ForwardIterator __first
argument_list|,
argument|_ForwardIterator __last
argument_list|,
argument|const _Tp& __value
argument_list|,
argument|_Pred __pred
argument_list|)
block|{
while|while
condition|(
name|__first
operator|!=
name|__last
operator|&&
name|__pred
argument_list|(
operator|*
name|__first
argument_list|,
name|__value
argument_list|)
condition|)
operator|++
name|__first
expr_stmt|;
end_expr_stmt

begin_while
while|while
condition|(
name|__first
operator|!=
name|__last
operator|&&
operator|!
name|__pred
argument_list|(
operator|*
name|__first
argument_list|,
name|__value
argument_list|)
condition|)
operator|++
name|__first
expr_stmt|;
end_while

begin_return
return|return
name|__first
operator|==
name|__last
return|;
end_return

begin_comment
unit|} }
comment|// namespace __gnu_debug
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

