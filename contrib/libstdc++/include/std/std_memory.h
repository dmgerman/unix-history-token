begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//<memory> -*- C++ -*-
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
comment|/*  * Copyright (c) 1997-1999  * Silicon Graphics Computer Systems, Inc.  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Silicon Graphics makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  *  */
end_comment

begin_comment
comment|/** @file memory  *  This is a Standard C++ Library header.  You should @c #include this header  *  in your programs, rather than any of the "st[dl]_*.h" implementation files.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CPP_MEMORY
end_ifndef

begin_define
define|#
directive|define
name|_CPP_MEMORY
value|1
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
file|<bits/stl_algobase.h>
end_include

begin_include
include|#
directive|include
file|<bits/stl_alloc.h>
end_include

begin_include
include|#
directive|include
file|<bits/stl_construct.h>
end_include

begin_include
include|#
directive|include
file|<bits/stl_iterator_base_types.h>
end_include

begin_comment
comment|//for iterator_traits
end_comment

begin_include
include|#
directive|include
file|<bits/stl_uninitialized.h>
end_include

begin_include
include|#
directive|include
file|<bits/stl_raw_storage_iter.h>
end_include

begin_decl_stmt
name|namespace
name|std
block|{
comment|/**    *  @if maint    *  This is a helper function.  The unused second parameter exists to    *  permit the real get_temporary_buffer to use template parameter deduction.    *  @endif   */
name|template
operator|<
name|class
name|_Tp
operator|>
name|pair
operator|<
name|_Tp
operator|*
operator|,
name|ptrdiff_t
operator|>
name|__get_temporary_buffer
argument_list|(
argument|ptrdiff_t __len
argument_list|,
argument|_Tp*
argument_list|)
block|{
if|if
condition|(
name|__len
operator|>
name|ptrdiff_t
argument_list|(
name|INT_MAX
operator|/
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
argument_list|)
condition|)
name|__len
operator|=
name|INT_MAX
operator|/
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
expr_stmt|;
while|while
condition|(
name|__len
operator|>
literal|0
condition|)
block|{
name|_Tp
modifier|*
name|__tmp
init|=
operator|(
name|_Tp
operator|*
operator|)
name|std
operator|::
name|malloc
argument_list|(
operator|(
name|std
operator|::
name|size_t
operator|)
name|__len
operator|*
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|__tmp
operator|!=
literal|0
condition|)
return|return
name|pair
operator|<
name|_Tp
operator|*
operator|,
name|ptrdiff_t
operator|>
operator|(
name|__tmp
operator|,
name|__len
operator|)
return|;
name|__len
operator|/=
literal|2
expr_stmt|;
block|}
return|return
name|pair
operator|<
name|_Tp
operator|*
operator|,
name|ptrdiff_t
operator|>
operator|(
operator|(
name|_Tp
operator|*
operator|)
literal|0
operator|,
literal|0
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/**    *  @brief This is a mostly-useless wrapper around malloc().    *  @param  len  The number of objects of type Tp.    *  @return   See full description.    *    *  Reinventing the wheel, but this time with prettier spokes!    *    *  This function tries to obtain storage for @c len adjacent Tp objects.    *  The objects themselves are not constructed, of course.  A pair<> is    *  returned containing "the buffer s address and capacity (in the units of    *  sizeof(Tp)), or a pair of 0 values if no storage can be obtained."    *  Note that the capacity obtained may be less than that requested if the    *  memory is unavailable; you should compare len with the .second return    *  value.   */
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|>
specifier|inline
name|pair
operator|<
name|_Tp
operator|*
operator|,
name|ptrdiff_t
operator|>
name|get_temporary_buffer
argument_list|(
argument|ptrdiff_t __len
argument_list|)
block|{
return|return
name|__get_temporary_buffer
argument_list|(
name|__len
argument_list|,
operator|(
name|_Tp
operator|*
operator|)
literal|0
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/**    *  @brief The companion to get_temporary_buffer().    *  @param  p  A buffer previously allocated by get_temporary_buffer.    *  @return   None.    *    *  Frees the memory pointed to by p.    */
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|>
name|void
name|return_temporary_buffer
argument_list|(
argument|_Tp* __p
argument_list|)
block|{
name|std
operator|::
name|free
argument_list|(
name|__p
argument_list|)
block|;   }
name|template
operator|<
name|class
name|_Tp1
operator|>
expr|struct
name|auto_ptr_ref
block|{
name|_Tp1
operator|*
name|_M_ptr
block|;
name|auto_ptr_ref
argument_list|(
name|_Tp1
operator|*
name|__p
argument_list|)
operator|:
name|_M_ptr
argument_list|(
argument|__p
argument_list|)
block|{}
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**  *  A simple smart pointer providing strict ownership semantics.  (More later.) */
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|>
name|class
name|auto_ptr
block|{
name|private
operator|:
name|_Tp
operator|*
name|_M_ptr
block|;
name|public
operator|:
typedef|typedef
name|_Tp
name|element_type
typedef|;
name|explicit
name|auto_ptr
argument_list|(
argument|_Tp* __p =
literal|0
argument_list|)
name|throw
argument_list|()
operator|:
name|_M_ptr
argument_list|(
argument|__p
argument_list|)
block|{}
name|auto_ptr
argument_list|(
argument|auto_ptr& __a
argument_list|)
name|throw
argument_list|()
operator|:
name|_M_ptr
argument_list|(
argument|__a.release()
argument_list|)
block|{}
name|template
operator|<
name|class
name|_Tp1
operator|>
name|auto_ptr
argument_list|(
argument|auto_ptr<_Tp1>& __a
argument_list|)
name|throw
argument_list|()
operator|:
name|_M_ptr
argument_list|(
argument|__a.release()
argument_list|)
block|{}
name|auto_ptr
operator|&
name|operator
operator|=
operator|(
name|auto_ptr
operator|&
name|__a
operator|)
name|throw
argument_list|()
block|{
name|reset
argument_list|(
name|__a
operator|.
name|release
argument_list|()
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp1
operator|>
name|auto_ptr
operator|&
name|operator
operator|=
operator|(
name|auto_ptr
operator|<
name|_Tp1
operator|>
operator|&
name|__a
operator|)
name|throw
argument_list|()
block|{
name|reset
argument_list|(
name|__a
operator|.
name|release
argument_list|()
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_comment
comment|// Note: The C++ standard says there is supposed to be an empty throw
end_comment

begin_comment
comment|// specification here, but omitting it is standard conforming.  Its
end_comment

begin_comment
comment|// presence can be detected only if _Tp::~_Tp() throws, but (17.4.3.6/2)
end_comment

begin_comment
comment|// this is prohibited.
end_comment

begin_expr_stmt
operator|~
name|auto_ptr
argument_list|()
block|{
name|delete
name|_M_ptr
block|; }
name|_Tp
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
name|throw
argument_list|()
block|{
return|return
operator|*
name|_M_ptr
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|_Tp
operator|*
name|operator
operator|->
expr|(
end_expr_stmt

begin_expr_stmt
unit|)
specifier|const
name|throw
argument_list|()
block|{
return|return
name|_M_ptr
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|_Tp
operator|*
name|get
argument_list|()
specifier|const
name|throw
argument_list|()
block|{
return|return
name|_M_ptr
return|;
block|}
end_expr_stmt

begin_function
name|_Tp
modifier|*
name|release
parameter_list|()
function|throw
parameter_list|()
block|{
name|_Tp
modifier|*
name|__tmp
init|=
name|_M_ptr
decl_stmt|;
name|_M_ptr
operator|=
literal|0
expr_stmt|;
return|return
name|__tmp
return|;
block|}
end_function

begin_function
name|void
name|reset
parameter_list|(
name|_Tp
modifier|*
name|__p
init|=
literal|0
parameter_list|)
function|throw
parameter_list|()
block|{
if|if
condition|(
name|__p
operator|!=
name|_M_ptr
condition|)
block|{
name|delete
name|_M_ptr
decl_stmt|;
name|_M_ptr
operator|=
name|__p
expr_stmt|;
block|}
block|}
end_function

begin_label
name|public
label|:
end_label

begin_macro
name|auto_ptr
argument_list|(
argument|auto_ptr_ref<_Tp> __ref
argument_list|)
end_macro

begin_expr_stmt
name|throw
argument_list|()
operator|:
name|_M_ptr
argument_list|(
argument|__ref._M_ptr
argument_list|)
block|{}
name|auto_ptr
operator|&
name|operator
operator|=
operator|(
name|auto_ptr_ref
operator|<
name|_Tp
operator|>
name|__ref
operator|)
name|throw
argument_list|()
block|{
if|if
condition|(
name|__ref
operator|.
name|_M_ptr
operator|!=
name|this
operator|->
name|get
argument_list|()
condition|)
block|{
name|delete
name|_M_ptr
decl_stmt|;
name|_M_ptr
operator|=
name|__ref
operator|.
name|_M_ptr
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
operator|*
name|this
return|;
end_return

begin_expr_stmt
unit|}    template
operator|<
name|class
name|_Tp1
operator|>
name|operator
name|auto_ptr_ref
operator|<
name|_Tp1
operator|>
operator|(
operator|)
name|throw
argument_list|()
block|{
return|return
name|auto_ptr_ref
operator|<
name|_Tp
operator|>
operator|(
name|this
operator|->
name|release
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp1
operator|>
name|operator
name|auto_ptr
operator|<
name|_Tp1
operator|>
operator|(
operator|)
name|throw
argument_list|()
block|{
return|return
name|auto_ptr
operator|<
name|_Tp1
operator|>
operator|(
name|this
operator|->
name|release
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};  }
comment|// namespace std
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CPP_MEMORY */
end_comment

end_unit

