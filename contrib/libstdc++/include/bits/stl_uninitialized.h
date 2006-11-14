begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Raw memory manipulators -*- C++ -*-
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
comment|/** @file stl_uninitialized.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STL_UNINITIALIZED_H
end_ifndef

begin_define
define|#
directive|define
name|_STL_UNINITIALIZED_H
value|1
end_define

begin_include
include|#
directive|include
file|<cstring>
end_include

begin_decl_stmt
name|namespace
name|std
block|{
comment|// uninitialized_copy
name|template
operator|<
name|typename
name|_InputIterator
operator|,
name|typename
name|_ForwardIterator
operator|>
specifier|inline
name|_ForwardIterator
name|__uninitialized_copy_aux
argument_list|(
argument|_InputIterator __first
argument_list|,
argument|_InputIterator __last
argument_list|,
argument|_ForwardIterator __result
argument_list|,
argument|__true_type
argument_list|)
block|{
return|return
name|std
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
name|template
operator|<
name|typename
name|_InputIterator
operator|,
name|typename
name|_ForwardIterator
operator|>
specifier|inline
name|_ForwardIterator
name|__uninitialized_copy_aux
argument_list|(
argument|_InputIterator __first
argument_list|,
argument|_InputIterator __last
argument_list|,
argument|_ForwardIterator __result
argument_list|,
argument|__false_type
argument_list|)
block|{
name|_ForwardIterator
name|__cur
operator|=
name|__result
block|;
name|try
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
operator|,
operator|++
name|__cur
control|)
name|std
operator|::
name|_Construct
argument_list|(
operator|&
operator|*
name|__cur
argument_list|,
operator|*
name|__first
argument_list|)
expr_stmt|;
return|return
name|__cur
return|;
block|}
name|catch
argument_list|(
argument|...
argument_list|)
block|{
name|std
operator|::
name|_Destroy
argument_list|(
name|__result
argument_list|,
name|__cur
argument_list|)
expr_stmt|;
name|__throw_exception_again
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_comment
comment|/**    *  @brief Copies the range [first,last) into result.    *  @param  first  An input iterator.    *  @param  last   An input iterator.    *  @param  result An output iterator.    *  @return   result + (first - last)    *    *  Like copy(), but does not require an initialized output range.   */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_InputIterator
operator|,
name|typename
name|_ForwardIterator
operator|>
specifier|inline
name|_ForwardIterator
name|uninitialized_copy
argument_list|(
argument|_InputIterator __first
argument_list|,
argument|_InputIterator __last
argument_list|,
argument|_ForwardIterator __result
argument_list|)
block|{
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_ForwardIterator
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
name|is_POD_type
name|_Is_POD
expr_stmt|;
end_typedef

begin_return
return|return
name|std
operator|::
name|__uninitialized_copy_aux
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__result
argument_list|,
name|_Is_POD
argument_list|()
argument_list|)
return|;
end_return

begin_function
unit|}    inline
name|char
modifier|*
name|uninitialized_copy
parameter_list|(
specifier|const
name|char
modifier|*
name|__first
parameter_list|,
specifier|const
name|char
modifier|*
name|__last
parameter_list|,
name|char
modifier|*
name|__result
parameter_list|)
block|{
name|std
operator|::
name|memmove
argument_list|(
name|__result
argument_list|,
name|__first
argument_list|,
name|__last
operator|-
name|__first
argument_list|)
expr_stmt|;
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
end_function

begin_function
specifier|inline
name|wchar_t
modifier|*
name|uninitialized_copy
parameter_list|(
specifier|const
name|wchar_t
modifier|*
name|__first
parameter_list|,
specifier|const
name|wchar_t
modifier|*
name|__last
parameter_list|,
name|wchar_t
modifier|*
name|__result
parameter_list|)
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
name|wchar_t
argument_list|)
operator|*
operator|(
name|__last
operator|-
name|__first
operator|)
argument_list|)
expr_stmt|;
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
end_function

begin_comment
comment|// Valid if copy construction is equivalent to assignment, and if the
end_comment

begin_comment
comment|// destructor is trivial.
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
specifier|inline
name|void
name|__uninitialized_fill_aux
argument_list|(
argument|_ForwardIterator __first
argument_list|,
argument|_ForwardIterator __last
argument_list|,
argument|const _Tp& __x
argument_list|,
argument|__true_type
argument_list|)
block|{
name|std
operator|::
name|fill
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__x
argument_list|)
block|; }
name|template
operator|<
name|typename
name|_ForwardIterator
operator|,
name|typename
name|_Tp
operator|>
name|void
name|__uninitialized_fill_aux
argument_list|(
argument|_ForwardIterator __first
argument_list|,
argument|_ForwardIterator __last
argument_list|,
argument|const _Tp& __x
argument_list|,
argument|__false_type
argument_list|)
block|{
name|_ForwardIterator
name|__cur
operator|=
name|__first
block|;
name|try
block|{
for|for
control|(
init|;
name|__cur
operator|!=
name|__last
condition|;
operator|++
name|__cur
control|)
name|std
operator|::
name|_Construct
argument_list|(
operator|&
operator|*
name|__cur
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
name|std
operator|::
name|_Destroy
argument_list|(
name|__first
argument_list|,
name|__cur
argument_list|)
block|;
name|__throw_exception_again
block|; 	}
end_expr_stmt

begin_comment
unit|}
comment|/**    *  @brief Copies the value x into the range [first,last).    *  @param  first  An input iterator.    *  @param  last   An input iterator.    *  @param  x      The source value.    *  @return   Nothing.    *    *  Like fill(), but does not require an initialized output range.   */
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
name|void
name|uninitialized_fill
argument_list|(
argument|_ForwardIterator __first
argument_list|,
argument|_ForwardIterator __last
argument_list|,
argument|const _Tp& __x
argument_list|)
block|{
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_ForwardIterator
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
name|is_POD_type
name|_Is_POD
expr_stmt|;
end_typedef

begin_expr_stmt
name|std
operator|::
name|__uninitialized_fill_aux
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__x
argument_list|,
name|_Is_POD
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// Valid if copy construction is equivalent to assignment, and if the
end_comment

begin_comment
comment|//  destructor is trivial.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_ForwardIterator
operator|,
name|typename
name|_Size
operator|,
name|typename
name|_Tp
operator|>
specifier|inline
name|_ForwardIterator
name|__uninitialized_fill_n_aux
argument_list|(
argument|_ForwardIterator __first
argument_list|,
argument|_Size __n
argument_list|,
argument|const _Tp& __x
argument_list|,
argument|__true_type
argument_list|)
block|{
return|return
name|std
operator|::
name|fill_n
argument_list|(
name|__first
argument_list|,
name|__n
argument_list|,
name|__x
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_ForwardIterator
operator|,
name|typename
name|_Size
operator|,
name|typename
name|_Tp
operator|>
name|_ForwardIterator
name|__uninitialized_fill_n_aux
argument_list|(
argument|_ForwardIterator __first
argument_list|,
argument|_Size __n
argument_list|,
argument|const _Tp& __x
argument_list|,
argument|__false_type
argument_list|)
block|{
name|_ForwardIterator
name|__cur
operator|=
name|__first
block|;
name|try
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
name|__cur
control|)
name|std
operator|::
name|_Construct
argument_list|(
operator|&
operator|*
name|__cur
argument_list|,
name|__x
argument_list|)
expr_stmt|;
return|return
name|__cur
return|;
block|}
end_expr_stmt

begin_macro
name|catch
argument_list|(
argument|...
argument_list|)
end_macro

begin_block
block|{
name|std
operator|::
name|_Destroy
argument_list|(
name|__first
argument_list|,
name|__cur
argument_list|)
expr_stmt|;
name|__throw_exception_again
expr_stmt|;
block|}
end_block

begin_comment
unit|}
comment|/**    *  @brief Copies the value x into the range [first,first+n).    *  @param  first  An input iterator.    *  @param  n      The number of copies to make.    *  @param  x      The source value.    *  @return   first+n    *    *  Like fill_n(), but does not require an initialized output range.   */
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_ForwardIterator
operator|,
name|typename
name|_Size
operator|,
name|typename
name|_Tp
operator|>
specifier|inline
name|_ForwardIterator
name|uninitialized_fill_n
argument_list|(
argument|_ForwardIterator __first
argument_list|,
argument|_Size __n
argument_list|,
argument|const _Tp& __x
argument_list|)
block|{
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_ForwardIterator
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
name|is_POD_type
name|_Is_POD
expr_stmt|;
end_typedef

begin_return
return|return
name|std
operator|::
name|__uninitialized_fill_n_aux
argument_list|(
name|__first
argument_list|,
name|__n
argument_list|,
name|__x
argument_list|,
name|_Is_POD
argument_list|()
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|// Extensions: __uninitialized_copy_copy, __uninitialized_copy_fill,
end_comment

begin_comment
comment|// __uninitialized_fill_copy.
end_comment

begin_comment
comment|// __uninitialized_copy_copy
end_comment

begin_comment
comment|// Copies [first1, last1) into [result, result + (last1 - first1)), and
end_comment

begin_comment
comment|//  copies [first2, last2) into
end_comment

begin_comment
comment|//  [result, result + (last1 - first1) + (last2 - first2)).
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
name|_ForwardIterator
operator|>
specifier|inline
name|_ForwardIterator
name|__uninitialized_copy_copy
argument_list|(
argument|_InputIterator1 __first1
argument_list|,
argument|_InputIterator1 __last1
argument_list|,
argument|_InputIterator2 __first2
argument_list|,
argument|_InputIterator2 __last2
argument_list|,
argument|_ForwardIterator __result
argument_list|)
block|{
name|_ForwardIterator
name|__mid
operator|=
name|std
operator|::
name|uninitialized_copy
argument_list|(
name|__first1
argument_list|,
name|__last1
argument_list|,
name|__result
argument_list|)
block|;
name|try
block|{
return|return
name|std
operator|::
name|uninitialized_copy
argument_list|(
name|__first2
argument_list|,
name|__last2
argument_list|,
name|__mid
argument_list|)
return|;
block|}
name|catch
argument_list|(
argument|...
argument_list|)
block|{
name|std
operator|::
name|_Destroy
argument_list|(
name|__result
argument_list|,
name|__mid
argument_list|)
block|;
name|__throw_exception_again
block|; 	}
end_expr_stmt

begin_comment
unit|}
comment|// __uninitialized_fill_copy
end_comment

begin_comment
comment|// Fills [result, mid) with x, and copies [first, last) into
end_comment

begin_comment
comment|//  [mid, mid + (last - first)).
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
name|_InputIterator
operator|>
specifier|inline
name|_ForwardIterator
name|__uninitialized_fill_copy
argument_list|(
argument|_ForwardIterator __result
argument_list|,
argument|_ForwardIterator __mid
argument_list|,
argument|const _Tp& __x
argument_list|,
argument|_InputIterator __first
argument_list|,
argument|_InputIterator __last
argument_list|)
block|{
name|std
operator|::
name|uninitialized_fill
argument_list|(
name|__result
argument_list|,
name|__mid
argument_list|,
name|__x
argument_list|)
block|;
name|try
block|{
return|return
name|std
operator|::
name|uninitialized_copy
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__mid
argument_list|)
return|;
block|}
name|catch
argument_list|(
argument|...
argument_list|)
block|{
name|std
operator|::
name|_Destroy
argument_list|(
name|__result
argument_list|,
name|__mid
argument_list|)
block|;
name|__throw_exception_again
block|; 	}
end_expr_stmt

begin_comment
unit|}
comment|// __uninitialized_copy_fill
end_comment

begin_comment
comment|// Copies [first1, last1) into [first2, first2 + (last1 - first1)), and
end_comment

begin_comment
comment|//  fills [first2 + (last1 - first1), last2) with x.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|_InputIterator
operator|,
name|typename
name|_ForwardIterator
operator|,
name|typename
name|_Tp
operator|>
specifier|inline
name|void
name|__uninitialized_copy_fill
argument_list|(
argument|_InputIterator __first1
argument_list|,
argument|_InputIterator __last1
argument_list|,
argument|_ForwardIterator __first2
argument_list|,
argument|_ForwardIterator __last2
argument_list|,
argument|const _Tp& __x
argument_list|)
block|{
name|_ForwardIterator
name|__mid2
operator|=
name|std
operator|::
name|uninitialized_copy
argument_list|(
name|__first1
argument_list|,
name|__last1
argument_list|,
name|__first2
argument_list|)
block|;
name|try
block|{
name|std
operator|::
name|uninitialized_fill
argument_list|(
name|__mid2
argument_list|,
name|__last2
argument_list|,
name|__x
argument_list|)
block|; 	}
name|catch
argument_list|(
argument|...
argument_list|)
block|{
name|std
operator|::
name|_Destroy
argument_list|(
name|__first2
argument_list|,
name|__mid2
argument_list|)
block|;
name|__throw_exception_again
block|; 	}
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
comment|/* _STL_UNINITIALIZED_H */
end_comment

end_unit

