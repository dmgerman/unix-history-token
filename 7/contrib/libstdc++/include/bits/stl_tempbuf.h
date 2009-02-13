begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Temporary buffer implementation -*- C++ -*-
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
comment|/*  *  * Copyright (c) 1994  * Hewlett-Packard Company  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Hewlett-Packard Company makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  *  *  * Copyright (c) 1996,1997  * Silicon Graphics Computer Systems, Inc.  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Silicon Graphics makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  */
end_comment

begin_comment
comment|/** @file stl_tempbuf.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TEMPBUF_H
end_ifndef

begin_define
define|#
directive|define
name|_TEMPBUF_H
value|1
end_define

begin_include
include|#
directive|include
file|<memory>
end_include

begin_macro
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
argument|std
argument_list|)
end_macro

begin_comment
comment|/**    *  @if maint    *  This class is used in two places: stl_algo.h and ext/memory,    *  where it is wrapped as the temporary_buffer class.  See    *  temporary_buffer docs for more notes.    *  @endif    */
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
name|class
name|_Temporary_buffer
block|{
comment|// concept requirements
name|__glibcxx_class_requires
argument_list|(
argument|_ForwardIterator
argument_list|,
argument|_ForwardIteratorConcept
argument_list|)
name|public
operator|:
typedef|typedef
name|_Tp
name|value_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|value_type
modifier|*
name|pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|pointer
name|iterator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ptrdiff_t
name|size_type
typedef|;
end_typedef

begin_label
name|protected
label|:
end_label

begin_decl_stmt
name|size_type
name|_M_original_len
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_type
name|_M_len
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|pointer
name|_M_buffer
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|_M_initialize_buffer
parameter_list|(
specifier|const
name|_Tp
modifier|&
parameter_list|,
name|__true_type
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|_M_initialize_buffer
parameter_list|(
specifier|const
name|_Tp
modifier|&
name|__val
parameter_list|,
name|__false_type
parameter_list|)
block|{
name|std
operator|::
name|uninitialized_fill_n
argument_list|(
name|_M_buffer
argument_list|,
name|_M_len
argument_list|,
name|__val
argument_list|)
expr_stmt|;
block|}
end_function

begin_label
name|public
label|:
end_label

begin_comment
comment|/// As per Table mumble.
end_comment

begin_expr_stmt
name|size_type
name|size
argument_list|()
specifier|const
block|{
return|return
name|_M_len
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Returns the size requested by the constructor; may be>size().
end_comment

begin_expr_stmt
name|size_type
name|requested_size
argument_list|()
specifier|const
block|{
return|return
name|_M_original_len
return|;
block|}
end_expr_stmt

begin_comment
comment|/// As per Table mumble.
end_comment

begin_function
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|_M_buffer
return|;
block|}
end_function

begin_comment
comment|/// As per Table mumble.
end_comment

begin_function
name|iterator
name|end
parameter_list|()
block|{
return|return
name|_M_buffer
operator|+
name|_M_len
return|;
block|}
end_function

begin_comment
comment|/**        * Constructs a temporary buffer of a size somewhere between        * zero and the size of the given range.        */
end_comment

begin_macro
name|_Temporary_buffer
argument_list|(
argument|_ForwardIterator __first
argument_list|,
argument|_ForwardIterator __last
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
operator|~
name|_Temporary_buffer
argument_list|()
block|{
name|std
operator|::
name|_Destroy
argument_list|(
name|_M_buffer
argument_list|,
name|_M_buffer
operator|+
name|_M_len
argument_list|)
block|;
name|std
operator|::
name|return_temporary_buffer
argument_list|(
name|_M_buffer
argument_list|)
block|;       }
name|private
operator|:
comment|// Disable copy constructor and assignment operator.
name|_Temporary_buffer
argument_list|(
specifier|const
name|_Temporary_buffer
operator|&
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|operator
init|=
operator|(
specifier|const
name|_Temporary_buffer
operator|&
operator|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_ForwardIterator
operator|,
name|typename
name|_Tp
operator|>
name|_Temporary_buffer
operator|<
name|_ForwardIterator
operator|,
name|_Tp
operator|>
operator|::
name|_Temporary_buffer
argument_list|(
argument|_ForwardIterator __first
argument_list|,
argument|_ForwardIterator __last
argument_list|)
operator|:
name|_M_original_len
argument_list|(
name|std
operator|::
name|distance
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|)
argument_list|)
operator|,
name|_M_len
argument_list|(
literal|0
argument_list|)
operator|,
name|_M_buffer
argument_list|(
literal|0
argument_list|)
block|{
comment|// Workaround for a __type_traits bug in the pre-7.3 compiler.
typedef|typedef
name|typename
name|std
operator|::
name|__is_scalar
operator|<
name|_Tp
operator|>
operator|::
name|__type
name|_Trivial
expr_stmt|;
name|try
block|{
name|pair
operator|<
name|pointer
block|,
name|size_type
operator|>
name|__p
argument_list|(
name|get_temporary_buffer
operator|<
name|value_type
operator|>
operator|(
name|_M_original_len
operator|)
argument_list|)
block|;
name|_M_buffer
operator|=
name|__p
operator|.
name|first
block|;
name|_M_len
operator|=
name|__p
operator|.
name|second
block|;
if|if
condition|(
name|_M_len
operator|>
literal|0
condition|)
name|_M_initialize_buffer
argument_list|(
operator|*
name|__first
argument_list|,
name|_Trivial
argument_list|()
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
name|return_temporary_buffer
argument_list|(
name|_M_buffer
argument_list|)
block|;
name|_M_buffer
operator|=
literal|0
block|;
name|_M_len
operator|=
literal|0
block|;
name|__throw_exception_again
block|; 	}
end_expr_stmt

begin_endif
unit|}  _GLIBCXX_END_NAMESPACE
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TEMPBUF_H */
end_comment

end_unit

