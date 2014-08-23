begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Bits and pieces used in algorithms -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2001, 2002, 2003, 2004, 2005, 2006, 2007
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
comment|/*  *  * Copyright (c) 1994  * Hewlett-Packard Company  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Hewlett-Packard Company makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  *  *  * Copyright (c) 1996-1998  * Silicon Graphics Computer Systems, Inc.  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Silicon Graphics makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  */
end_comment

begin_comment
comment|/** @file stl_algobase.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALGOBASE_H
end_ifndef

begin_define
define|#
directive|define
name|_ALGOBASE_H
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
file|<bits/cpp_type_traits.h>
end_include

begin_include
include|#
directive|include
file|<ext/type_traits.h>
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

begin_include
include|#
directive|include
file|<debug/debug.h>
end_include

begin_macro
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
argument|std
argument_list|)
end_macro

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
name|__glibcxx_function_requires
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
comment|// See http://gcc.gnu.org/ml/libstdc++/2004-08/msg00167.html: in a
comment|// nutshell, we are partially implementing the resolution of DR 187,
comment|// when it's safe, i.e., the value_types are equal.
name|template
operator|<
name|bool
name|_BoolType
operator|>
expr|struct
name|__iter_swap
block|{
name|template
operator|<
name|typename
name|_ForwardIterator1
block|,
name|typename
name|_ForwardIterator2
operator|>
specifier|static
name|void
name|iter_swap
argument_list|(
argument|_ForwardIterator1 __a
argument_list|,
argument|_ForwardIterator2 __b
argument_list|)
block|{
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_ForwardIterator1
operator|>
operator|::
name|value_type
name|_ValueType1
expr_stmt|;
name|_ValueType1
name|__tmp
operator|=
operator|*
name|__a
block|;
operator|*
name|__a
operator|=
operator|*
name|__b
block|;
operator|*
name|__b
operator|=
name|__tmp
block|;  	}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|__iter_swap
operator|<
name|true
operator|>
block|{
name|template
operator|<
name|typename
name|_ForwardIterator1
block|,
name|typename
name|_ForwardIterator2
operator|>
specifier|static
name|void
name|iter_swap
argument_list|(
argument|_ForwardIterator1 __a
argument_list|,
argument|_ForwardIterator2 __b
argument_list|)
block|{
name|swap
argument_list|(
operator|*
name|__a
argument_list|,
operator|*
name|__b
argument_list|)
block|;         }
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**    *  @brief Swaps the contents of two iterators.    *  @param  a  An iterator.    *  @param  b  Another iterator.    *  @return   Nothing.    *    *  This function swaps the values pointed to by two iterators, not the    *  iterators themselves.   */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_ForwardIterator1
operator|,
name|typename
name|_ForwardIterator2
operator|>
specifier|inline
name|void
name|iter_swap
argument_list|(
argument|_ForwardIterator1 __a
argument_list|,
argument|_ForwardIterator2 __b
argument_list|)
block|{
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_ForwardIterator1
operator|>
operator|::
name|value_type
name|_ValueType1
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_ForwardIterator2
operator|>
operator|::
name|value_type
name|_ValueType2
expr_stmt|;
end_typedef

begin_comment
comment|// concept requirements
end_comment

begin_macro
name|__glibcxx_function_requires
argument_list|(
argument|_Mutable_ForwardIteratorConcept< 				  _ForwardIterator1>
argument_list|)
end_macro

begin_macro
name|__glibcxx_function_requires
argument_list|(
argument|_Mutable_ForwardIteratorConcept< 				  _ForwardIterator2>
argument_list|)
end_macro

begin_macro
name|__glibcxx_function_requires
argument_list|(
argument|_ConvertibleConcept<_ValueType1
argument_list|,
argument|_ValueType2>
argument_list|)
end_macro

begin_macro
name|__glibcxx_function_requires
argument_list|(
argument|_ConvertibleConcept<_ValueType2
argument_list|,
argument|_ValueType1>
argument_list|)
end_macro

begin_typedef
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_ForwardIterator1
operator|>
operator|::
name|reference
name|_ReferenceType1
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_ForwardIterator2
operator|>
operator|::
name|reference
name|_ReferenceType2
expr_stmt|;
end_typedef

begin_expr_stmt
name|std
operator|::
name|__iter_swap
operator|<
name|__are_same
operator|<
name|_ValueType1
operator|,
name|_ValueType2
operator|>
operator|::
name|__value
operator|&&
name|__are_same
operator|<
name|_ValueType1
operator|&
operator|,
name|_ReferenceType1
operator|>
operator|::
name|__value
operator|&&
name|__are_same
operator|<
name|_ValueType2
operator|&
operator|,
name|_ReferenceType2
operator|>
operator|::
name|__value
operator|>
operator|::
name|iter_swap
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|/**    *  @brief This does what you think it does.    *  @param  a  A thing of arbitrary type.    *  @param  b  Another thing of arbitrary type.    *  @return   The lesser of the parameters.    *    *  This is the simple classic generic implementation.  It will work on    *  temporary expressions, since they are only evaluated once, unlike a    *  preprocessor macro.   */
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
name|min
argument_list|(
argument|const _Tp& __a
argument_list|,
argument|const _Tp& __b
argument_list|)
block|{
comment|// concept requirements
name|__glibcxx_function_requires
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
name|__glibcxx_function_requires
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
comment|// All of these auxiliary structs serve two purposes.  (1) Replace
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
name|bool
operator|,
name|typename
operator|>
expr|struct
name|__copy
block|{
name|template
operator|<
name|typename
name|_II
block|,
name|typename
name|_OI
operator|>
specifier|static
name|_OI
name|copy
argument_list|(
argument|_II __first
argument_list|,
argument|_II __last
argument_list|,
argument|_OI __result
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
return|return
name|__result
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|bool
name|_BoolType
operator|>
expr|struct
name|__copy
operator|<
name|_BoolType
operator|,
name|random_access_iterator_tag
operator|>
block|{
name|template
operator|<
name|typename
name|_II
block|,
name|typename
name|_OI
operator|>
specifier|static
name|_OI
name|copy
argument_list|(
argument|_II __first
argument_list|,
argument|_II __last
argument_list|,
argument|_OI __result
argument_list|)
block|{
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_II
operator|>
operator|::
name|difference_type
name|_Distance
expr_stmt|;
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
end_expr_stmt

begin_return
return|return
name|__result
return|;
end_return

begin_empty_stmt
unit|}     }
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|__copy
operator|<
name|true
operator|,
name|random_access_iterator_tag
operator|>
block|{
name|template
operator|<
name|typename
name|_Tp
operator|>
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
name|std
operator|::
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
unit|};
name|template
operator|<
name|typename
name|_II
operator|,
name|typename
name|_OI
operator|>
specifier|inline
name|_OI
name|__copy_aux
argument_list|(
argument|_II __first
argument_list|,
argument|_II __last
argument_list|,
argument|_OI __result
argument_list|)
block|{
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_II
operator|>
operator|::
name|value_type
name|_ValueTypeI
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_OI
operator|>
operator|::
name|value_type
name|_ValueTypeO
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_II
operator|>
operator|::
name|iterator_category
name|_Category
expr_stmt|;
end_typedef

begin_decl_stmt
specifier|const
name|bool
name|__simple
init|=
operator|(
name|__is_scalar
operator|<
name|_ValueTypeI
operator|>
operator|::
name|__value
operator|&&
name|__is_pointer
operator|<
name|_II
operator|>
operator|::
name|__value
operator|&&
name|__is_pointer
operator|<
name|_OI
operator|>
operator|::
name|__value
operator|&&
name|__are_same
operator|<
name|_ValueTypeI
expr|,
name|_ValueTypeO
operator|>
operator|::
name|__value
operator|)
decl_stmt|;
end_decl_stmt

begin_return
return|return
name|std
operator|::
name|__copy
operator|<
name|__simple
operator|,
name|_Category
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

begin_comment
unit|}
comment|// Helpers for streambuf iterators (either istream or ostream).
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_CharT
operator|>
name|typename
name|__gnu_cxx
operator|::
name|__enable_if
operator|<
name|__is_char
operator|<
name|_CharT
operator|>
operator|::
name|__value
operator|,
name|ostreambuf_iterator
operator|<
name|_CharT
operator|>
expr|>
operator|::
name|__type
name|__copy_aux
argument_list|(
name|_CharT
operator|*
argument_list|,
name|_CharT
operator|*
argument_list|,
name|ostreambuf_iterator
operator|<
name|_CharT
operator|>
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
name|typename
name|__gnu_cxx
operator|::
name|__enable_if
operator|<
name|__is_char
operator|<
name|_CharT
operator|>
operator|::
name|__value
operator|,
name|ostreambuf_iterator
operator|<
name|_CharT
operator|>
expr|>
operator|::
name|__type
name|__copy_aux
argument_list|(
specifier|const
name|_CharT
operator|*
argument_list|,
specifier|const
name|_CharT
operator|*
argument_list|,
name|ostreambuf_iterator
operator|<
name|_CharT
operator|>
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
name|typename
name|__gnu_cxx
operator|::
name|__enable_if
operator|<
name|__is_char
operator|<
name|_CharT
operator|>
operator|::
name|__value
operator|,
name|_CharT
operator|*
operator|>
operator|::
name|__type
name|__copy_aux
argument_list|(
name|istreambuf_iterator
operator|<
name|_CharT
operator|>
argument_list|,
name|istreambuf_iterator
operator|<
name|_CharT
operator|>
argument_list|,
name|_CharT
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|bool
operator|,
name|bool
operator|>
expr|struct
name|__copy_normal
block|{
name|template
operator|<
name|typename
name|_II
block|,
name|typename
name|_OI
operator|>
specifier|static
name|_OI
name|__copy_n
argument_list|(
argument|_II __first
argument_list|,
argument|_II __last
argument_list|,
argument|_OI __result
argument_list|)
block|{
return|return
name|std
operator|::
name|__copy_aux
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
operator|>
expr|struct
name|__copy_normal
operator|<
name|true
operator|,
name|false
operator|>
block|{
name|template
operator|<
name|typename
name|_II
block|,
name|typename
name|_OI
operator|>
specifier|static
name|_OI
name|__copy_n
argument_list|(
argument|_II __first
argument_list|,
argument|_II __last
argument_list|,
argument|_OI __result
argument_list|)
block|{
return|return
name|std
operator|::
name|__copy_aux
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
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|__copy_normal
operator|<
name|false
operator|,
name|true
operator|>
block|{
name|template
operator|<
name|typename
name|_II
block|,
name|typename
name|_OI
operator|>
specifier|static
name|_OI
name|__copy_n
argument_list|(
argument|_II __first
argument_list|,
argument|_II __last
argument_list|,
argument|_OI __result
argument_list|)
block|{
return|return
name|_OI
argument_list|(
name|std
operator|::
name|__copy_aux
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
unit|};
name|template
operator|<
operator|>
expr|struct
name|__copy_normal
operator|<
name|true
operator|,
name|true
operator|>
block|{
name|template
operator|<
name|typename
name|_II
block|,
name|typename
name|_OI
operator|>
specifier|static
name|_OI
name|__copy_n
argument_list|(
argument|_II __first
argument_list|,
argument|_II __last
argument_list|,
argument|_OI __result
argument_list|)
block|{
return|return
name|_OI
argument_list|(
name|std
operator|::
name|__copy_aux
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
operator|.
name|base
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/**    *  @brief Copies the range [first,last) into result.    *  @param  first  An input iterator.    *  @param  last   An input iterator.    *  @param  result An output iterator.    *  @return   result + (last - first)    *    *  This inline function will boil down to a call to @c memmove whenever    *  possible.  Failing that, if random access iterators are passed, then the    *  loop count will be known (and therefore a candidate for compiler    *  optimizations such as unrolling).  Result may not be contained within    *  [first,last); the copy_backward function should be used instead.    *    *  Note that the end of the output range is permitted to be contained    *  within [first,last).   */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_InputIterator
operator|,
name|typename
name|_OutputIterator
operator|>
specifier|inline
name|_OutputIterator
name|copy
argument_list|(
argument|_InputIterator __first
argument_list|,
argument|_InputIterator __last
argument_list|,
argument|_OutputIterator __result
argument_list|)
block|{
comment|// concept requirements
name|__glibcxx_function_requires
argument_list|(
argument|_InputIteratorConcept<_InputIterator>
argument_list|)
name|__glibcxx_function_requires
argument_list|(
argument|_OutputIteratorConcept<_OutputIterator
argument_list|,
argument|typename iterator_traits<_InputIterator>::value_type>
argument_list|)
name|__glibcxx_requires_valid_range
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|)
block|;
specifier|const
name|bool
name|__in
operator|=
name|__is_normal_iterator
operator|<
name|_InputIterator
operator|>
operator|::
name|__value
block|;
specifier|const
name|bool
name|__out
operator|=
name|__is_normal_iterator
operator|<
name|_OutputIterator
operator|>
operator|::
name|__value
block|;
return|return
name|std
operator|::
name|__copy_normal
operator|<
name|__in
operator|,
name|__out
operator|>
operator|::
name|__copy_n
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

begin_comment
comment|// Overload for streambuf iterators.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_CharT
operator|>
name|typename
name|__gnu_cxx
operator|::
name|__enable_if
operator|<
name|__is_char
operator|<
name|_CharT
operator|>
operator|::
name|__value
operator|,
name|ostreambuf_iterator
operator|<
name|_CharT
operator|>
expr|>
operator|::
name|__type
name|copy
argument_list|(
name|istreambuf_iterator
operator|<
name|_CharT
operator|>
argument_list|,
name|istreambuf_iterator
operator|<
name|_CharT
operator|>
argument_list|,
name|ostreambuf_iterator
operator|<
name|_CharT
operator|>
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|bool
operator|,
name|typename
operator|>
expr|struct
name|__copy_backward
block|{
name|template
operator|<
name|typename
name|_BI1
block|,
name|typename
name|_BI2
operator|>
specifier|static
name|_BI2
name|__copy_b
argument_list|(
argument|_BI1 __first
argument_list|,
argument|_BI1 __last
argument_list|,
argument|_BI2 __result
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
return|return
name|__result
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|bool
name|_BoolType
operator|>
expr|struct
name|__copy_backward
operator|<
name|_BoolType
operator|,
name|random_access_iterator_tag
operator|>
block|{
name|template
operator|<
name|typename
name|_BI1
block|,
name|typename
name|_BI2
operator|>
specifier|static
name|_BI2
name|__copy_b
argument_list|(
argument|_BI1 __first
argument_list|,
argument|_BI1 __last
argument_list|,
argument|_BI2 __result
argument_list|)
block|{
name|typename
name|iterator_traits
operator|<
name|_BI1
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
return|return
name|__result
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|__copy_backward
operator|<
name|true
operator|,
name|random_access_iterator_tag
operator|>
block|{
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|static
name|_Tp
operator|*
name|__copy_b
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
name|std
operator|::
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
name|iterator_traits
operator|<
name|_BI1
operator|>
operator|::
name|value_type
name|_ValueType1
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_BI2
operator|>
operator|::
name|value_type
name|_ValueType2
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_BI1
operator|>
operator|::
name|iterator_category
name|_Category
expr_stmt|;
end_typedef

begin_decl_stmt
specifier|const
name|bool
name|__simple
init|=
operator|(
name|__is_scalar
operator|<
name|_ValueType1
operator|>
operator|::
name|__value
operator|&&
name|__is_pointer
operator|<
name|_BI1
operator|>
operator|::
name|__value
operator|&&
name|__is_pointer
operator|<
name|_BI2
operator|>
operator|::
name|__value
operator|&&
name|__are_same
operator|<
name|_ValueType1
expr|,
name|_ValueType2
operator|>
operator|::
name|__value
operator|)
decl_stmt|;
end_decl_stmt

begin_return
return|return
name|std
operator|::
name|__copy_backward
operator|<
name|__simple
operator|,
name|_Category
operator|>
operator|::
name|__copy_b
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
name|bool
operator|,
name|bool
operator|>
expr|struct
name|__copy_backward_normal
block|{
name|template
operator|<
name|typename
name|_BI1
block|,
name|typename
name|_BI2
operator|>
specifier|static
name|_BI2
name|__copy_b_n
argument_list|(
argument|_BI1 __first
argument_list|,
argument|_BI1 __last
argument_list|,
argument|_BI2 __result
argument_list|)
block|{
return|return
name|std
operator|::
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
unit|};
name|template
operator|<
operator|>
expr|struct
name|__copy_backward_normal
operator|<
name|true
operator|,
name|false
operator|>
block|{
name|template
operator|<
name|typename
name|_BI1
block|,
name|typename
name|_BI2
operator|>
specifier|static
name|_BI2
name|__copy_b_n
argument_list|(
argument|_BI1 __first
argument_list|,
argument|_BI1 __last
argument_list|,
argument|_BI2 __result
argument_list|)
block|{
return|return
name|std
operator|::
name|__copy_backward_aux
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
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|__copy_backward_normal
operator|<
name|false
operator|,
name|true
operator|>
block|{
name|template
operator|<
name|typename
name|_BI1
block|,
name|typename
name|_BI2
operator|>
specifier|static
name|_BI2
name|__copy_b_n
argument_list|(
argument|_BI1 __first
argument_list|,
argument|_BI1 __last
argument_list|,
argument|_BI2 __result
argument_list|)
block|{
return|return
name|_BI2
argument_list|(
name|std
operator|::
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
unit|};
name|template
operator|<
operator|>
expr|struct
name|__copy_backward_normal
operator|<
name|true
operator|,
name|true
operator|>
block|{
name|template
operator|<
name|typename
name|_BI1
block|,
name|typename
name|_BI2
operator|>
specifier|static
name|_BI2
name|__copy_b_n
argument_list|(
argument|_BI1 __first
argument_list|,
argument|_BI1 __last
argument_list|,
argument|_BI2 __result
argument_list|)
block|{
return|return
name|_BI2
argument_list|(
name|std
operator|::
name|__copy_backward_aux
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
operator|.
name|base
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/**    *  @brief Copies the range [first,last) into result.    *  @param  first  A bidirectional iterator.    *  @param  last   A bidirectional iterator.    *  @param  result A bidirectional iterator.    *  @return   result - (first - last)    *    *  The function has the same effect as copy, but starts at the end of the    *  range and works its way to the start, returning the start of the result.    *  This inline function will boil down to a call to @c memmove whenever    *  possible.  Failing that, if random access iterators are passed, then the    *  loop count will be known (and therefore a candidate for compiler    *  optimizations such as unrolling).    *    *  Result may not be in the range [first,last).  Use copy instead.  Note    *  that the start of the output range may overlap [first,last).   */
end_comment

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
name|__glibcxx_function_requires
argument_list|(
argument|_BidirectionalIteratorConcept<_BI1>
argument_list|)
name|__glibcxx_function_requires
argument_list|(
argument|_Mutable_BidirectionalIteratorConcept<_BI2>
argument_list|)
name|__glibcxx_function_requires
argument_list|(
argument|_ConvertibleConcept< 	    typename iterator_traits<_BI1>::value_type
argument_list|,
argument|typename iterator_traits<_BI2>::value_type>
argument_list|)
name|__glibcxx_requires_valid_range
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|)
block|;
specifier|const
name|bool
name|__bi1
operator|=
name|__is_normal_iterator
operator|<
name|_BI1
operator|>
operator|::
name|__value
block|;
specifier|const
name|bool
name|__bi2
operator|=
name|__is_normal_iterator
operator|<
name|_BI2
operator|>
operator|::
name|__value
block|;
return|return
name|std
operator|::
name|__copy_backward_normal
operator|<
name|__bi1
operator|,
name|__bi2
operator|>
operator|::
name|__copy_b_n
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
name|bool
operator|>
expr|struct
name|__fill
block|{
name|template
operator|<
name|typename
name|_ForwardIterator
block|,
name|typename
name|_Tp
operator|>
specifier|static
name|void
name|fill
argument_list|(
argument|_ForwardIterator __first
argument_list|,
argument|_ForwardIterator __last
argument_list|,
argument|const _Tp& __value
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
operator|*
name|__first
operator|=
name|__value
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|__fill
operator|<
name|true
operator|>
block|{
name|template
operator|<
name|typename
name|_ForwardIterator
block|,
name|typename
name|_Tp
operator|>
specifier|static
name|void
name|fill
argument_list|(
argument|_ForwardIterator __first
argument_list|,
argument|_ForwardIterator __last
argument_list|,
argument|const _Tp& __value
argument_list|)
block|{
specifier|const
name|_Tp
name|__tmp
operator|=
name|__value
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
operator|*
name|__first
operator|=
name|__tmp
expr_stmt|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/**    *  @brief Fills the range [first,last) with copies of value.    *  @param  first  A forward iterator.    *  @param  last   A forward iterator.    *  @param  value  A reference-to-const of arbitrary type.    *  @return   Nothing.    *    *  This function fills a range with copies of the same value.  For one-byte    *  types filling contiguous areas of memory, this becomes an inline call to    *  @c memset.   */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_ForwardIterator
operator|,
name|typename
name|_Tp
operator|>
name|void
name|fill
argument_list|(
argument|_ForwardIterator __first
argument_list|,
argument|_ForwardIterator __last
argument_list|,
argument|const _Tp& __value
argument_list|)
block|{
comment|// concept requirements
name|__glibcxx_function_requires
argument_list|(
argument|_Mutable_ForwardIteratorConcept< 				  _ForwardIterator>
argument_list|)
name|__glibcxx_requires_valid_range
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|)
block|;
specifier|const
name|bool
name|__scalar
operator|=
name|__is_scalar
operator|<
name|_Tp
operator|>
operator|::
name|__value
block|;
name|std
operator|::
name|__fill
operator|<
name|__scalar
operator|>
operator|::
name|fill
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__value
argument_list|)
block|;     }
comment|// Specialization: for one-byte types we can use memset.
specifier|inline
name|void
name|fill
argument_list|(
argument|unsigned char* __first
argument_list|,
argument|unsigned char* __last
argument_list|,
argument|const unsigned char& __c
argument_list|)
block|{
name|__glibcxx_requires_valid_range
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|)
block|;
specifier|const
name|unsigned
name|char
name|__tmp
operator|=
name|__c
block|;
name|std
operator|::
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
block|;   }
specifier|inline
name|void
name|fill
argument_list|(
argument|signed char* __first
argument_list|,
argument|signed char* __last
argument_list|,
argument|const signed char& __c
argument_list|)
block|{
name|__glibcxx_requires_valid_range
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|)
block|;
specifier|const
name|signed
name|char
name|__tmp
operator|=
name|__c
block|;
name|std
operator|::
name|memset
argument_list|(
argument|__first
argument_list|,
argument|static_cast<unsigned char>(__tmp)
argument_list|,
argument|__last - __first
argument_list|)
block|;   }
specifier|inline
name|void
name|fill
argument_list|(
argument|char* __first
argument_list|,
argument|char* __last
argument_list|,
argument|const char& __c
argument_list|)
block|{
name|__glibcxx_requires_valid_range
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|)
block|;
specifier|const
name|char
name|__tmp
operator|=
name|__c
block|;
name|std
operator|::
name|memset
argument_list|(
argument|__first
argument_list|,
argument|static_cast<unsigned char>(__tmp)
argument_list|,
argument|__last - __first
argument_list|)
block|;   }
name|template
operator|<
name|bool
operator|>
expr|struct
name|__fill_n
block|{
name|template
operator|<
name|typename
name|_OutputIterator
block|,
name|typename
name|_Size
block|,
name|typename
name|_Tp
operator|>
specifier|static
name|_OutputIterator
name|fill_n
argument_list|(
argument|_OutputIterator __first
argument_list|,
argument|_Size __n
argument_list|,
argument|const _Tp& __value
argument_list|)
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
operator|,
operator|++
name|__first
control|)
operator|*
name|__first
operator|=
name|__value
expr_stmt|;
return|return
name|__first
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|__fill_n
operator|<
name|true
operator|>
block|{
name|template
operator|<
name|typename
name|_OutputIterator
block|,
name|typename
name|_Size
block|,
name|typename
name|_Tp
operator|>
specifier|static
name|_OutputIterator
name|fill_n
argument_list|(
argument|_OutputIterator __first
argument_list|,
argument|_Size __n
argument_list|,
argument|const _Tp& __value
argument_list|)
block|{
specifier|const
name|_Tp
name|__tmp
operator|=
name|__value
block|;
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
name|__tmp
expr_stmt|;
return|return
name|__first
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/**    *  @brief Fills the range [first,first+n) with copies of value.    *  @param  first  An output iterator.    *  @param  n      The count of copies to perform.    *  @param  value  A reference-to-const of arbitrary type.    *  @return   The iterator at first+n.    *    *  This function fills a range with copies of the same value.  For one-byte    *  types filling contiguous areas of memory, this becomes an inline call to    *  @c memset.   */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_OutputIterator
operator|,
name|typename
name|_Size
operator|,
name|typename
name|_Tp
operator|>
name|_OutputIterator
name|fill_n
argument_list|(
argument|_OutputIterator __first
argument_list|,
argument|_Size __n
argument_list|,
argument|const _Tp& __value
argument_list|)
block|{
comment|// concept requirements
name|__glibcxx_function_requires
argument_list|(
argument|_OutputIteratorConcept<_OutputIterator
argument_list|,
argument|_Tp>
argument_list|)
specifier|const
name|bool
name|__scalar
operator|=
name|__is_scalar
operator|<
name|_Tp
operator|>
operator|::
name|__value
block|;
return|return
name|std
operator|::
name|__fill_n
operator|<
name|__scalar
operator|>
operator|::
name|fill_n
argument_list|(
name|__first
argument_list|,
name|__n
argument_list|,
name|__value
argument_list|)
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
name|std
operator|::
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
argument|signed char* __first
argument_list|,
argument|_Size __n
argument_list|,
argument|const signed char& __c
argument_list|)
block|{
name|std
operator|::
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
name|std
operator|::
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
comment|/**    *  @brief Finds the places in ranges which don't match.    *  @param  first1  An input iterator.    *  @param  last1   An input iterator.    *  @param  first2  An input iterator.    *  @return   A pair of iterators pointing to the first mismatch.    *    *  This compares the elements of two ranges using @c == and returns a pair    *  of iterators.  The first iterator points into the first range, the    *  second iterator points into the second range, and the elements pointed    *  to by the iterators are not equal.   */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_InputIterator1
operator|,
name|typename
name|_InputIterator2
operator|>
name|pair
operator|<
name|_InputIterator1
operator|,
name|_InputIterator2
operator|>
name|mismatch
argument_list|(
argument|_InputIterator1 __first1
argument_list|,
argument|_InputIterator1 __last1
argument_list|,
argument|_InputIterator2 __first2
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
name|__glibcxx_function_requires
argument_list|(
argument|_EqualOpConcept< 	    typename iterator_traits<_InputIterator1>::value_type
argument_list|,
argument|typename iterator_traits<_InputIterator2>::value_type>
argument_list|)
name|__glibcxx_requires_valid_range
argument_list|(
name|__first1
argument_list|,
name|__last1
argument_list|)
block|;
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
name|_InputIterator1
operator|,
name|_InputIterator2
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
name|_InputIterator1
operator|,
name|typename
name|_InputIterator2
operator|,
name|typename
name|_BinaryPredicate
operator|>
name|pair
operator|<
name|_InputIterator1
operator|,
name|_InputIterator2
operator|>
name|mismatch
argument_list|(
argument|_InputIterator1 __first1
argument_list|,
argument|_InputIterator1 __last1
argument_list|,
argument|_InputIterator2 __first2
argument_list|,
argument|_BinaryPredicate __binary_pred
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
name|_InputIterator1
operator|,
name|_InputIterator2
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
name|_InputIterator1
operator|,
name|typename
name|_InputIterator2
operator|>
specifier|inline
name|bool
name|equal
argument_list|(
argument|_InputIterator1 __first1
argument_list|,
argument|_InputIterator1 __last1
argument_list|,
argument|_InputIterator2 __first2
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
name|__glibcxx_function_requires
argument_list|(
argument|_EqualOpConcept< 	    typename iterator_traits<_InputIterator1>::value_type
argument_list|,
argument|typename iterator_traits<_InputIterator2>::value_type>
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
name|_InputIterator1
operator|,
name|typename
name|_InputIterator2
operator|,
name|typename
name|_BinaryPredicate
operator|>
specifier|inline
name|bool
name|equal
argument_list|(
argument|_InputIterator1 __first1
argument_list|,
argument|_InputIterator1 __last1
argument_list|,
argument|_InputIterator2 __first2
argument_list|,
argument|_BinaryPredicate __binary_pred
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
comment|/**    *  @brief Performs "dictionary" comparison on ranges.    *  @param  first1  An input iterator.    *  @param  last1   An input iterator.    *  @param  first2  An input iterator.    *  @param  last2   An input iterator.    *  @return   A boolean true or false.    *    *  "Returns true if the sequence of elements defined by the range    *  [first1,last1) is lexicographically less than the sequence of elements    *  defined by the range [first2,last2).  Returns false otherwise."    *  (Quoted from [25.3.8]/1.)  If the iterators are all character pointers,    *  then this is an inline call to @c memcmp.   */
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_InputIterator1
operator|,
name|typename
name|_InputIterator2
operator|>
name|bool
name|lexicographical_compare
argument_list|(
argument|_InputIterator1 __first1
argument_list|,
argument|_InputIterator1 __last1
argument_list|,
argument|_InputIterator2 __first2
argument_list|,
argument|_InputIterator2 __last2
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
name|__glibcxx_function_requires
argument_list|(
argument|_LessThanOpConcept< 	    typename iterator_traits<_InputIterator1>::value_type
argument_list|,
argument|typename iterator_traits<_InputIterator2>::value_type>
argument_list|)
name|__glibcxx_function_requires
argument_list|(
argument|_LessThanOpConcept< 	    typename iterator_traits<_InputIterator2>::value_type
argument_list|,
argument|typename iterator_traits<_InputIterator1>::value_type>
argument_list|)
name|__glibcxx_requires_valid_range
argument_list|(
name|__first1
argument_list|,
name|__last1
argument_list|)
block|;
name|__glibcxx_requires_valid_range
argument_list|(
name|__first2
argument_list|,
name|__last2
argument_list|)
block|;
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
name|_InputIterator1
operator|,
name|typename
name|_InputIterator2
operator|,
name|typename
name|_Compare
operator|>
name|bool
name|lexicographical_compare
argument_list|(
argument|_InputIterator1 __first1
argument_list|,
argument|_InputIterator1 __last1
argument_list|,
argument|_InputIterator2 __first2
argument_list|,
argument|_InputIterator2 __last2
argument_list|,
argument|_Compare __comp
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
name|__glibcxx_requires_valid_range
argument_list|(
name|__first2
argument_list|,
name|__last2
argument_list|)
block|;
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
name|__glibcxx_requires_valid_range
argument_list|(
name|__first1
argument_list|,
name|__last1
argument_list|)
expr_stmt|;
name|__glibcxx_requires_valid_range
argument_list|(
name|__first2
argument_list|,
name|__last2
argument_list|)
expr_stmt|;
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
name|std
operator|::
name|memcmp
argument_list|(
name|__first1
argument_list|,
name|__first2
argument_list|,
name|std
operator|::
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
name|__glibcxx_requires_valid_range
argument_list|(
name|__first1
argument_list|,
name|__last1
argument_list|)
expr_stmt|;
name|__glibcxx_requires_valid_range
argument_list|(
name|__first2
argument_list|,
name|__last2
argument_list|)
expr_stmt|;
if|#
directive|if
name|CHAR_MAX
operator|==
name|SCHAR_MAX
return|return
name|std
operator|::
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
name|std
operator|::
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

begin_macro
name|_GLIBCXX_END_NAMESPACE
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

