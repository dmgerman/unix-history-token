begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Allocators -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2001, 2002, 2003, 2004 Free Software Foundation, Inc.
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
comment|/*  * Copyright (c) 1996-1997  * Silicon Graphics Computer Systems, Inc.  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Silicon Graphics makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  */
end_comment

begin_comment
comment|/** @file ext/debug_allocator.h  *  This file is a GNU extension to the Standard C++ Library.  *  You should only include this header if you are using GCC 3 or later.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEBUG_ALLOCATOR_H
end_ifndef

begin_define
define|#
directive|define
name|_DEBUG_ALLOCATOR_H
value|1
end_define

begin_include
include|#
directive|include
file|<cstdlib>
end_include

begin_decl_stmt
name|namespace
name|__gnu_cxx
block|{
comment|/**    *  @brief  A meta-allocator with debugging bits, as per [20.4].    *    *  This is precisely the allocator defined in the C++ Standard.     *    - all allocation calls operator new    *    - all deallocation calls operator delete    *    *  (See @link Allocators allocators info @endlink for more.)    */
name|template
operator|<
name|typename
name|_Alloc
operator|>
name|class
name|debug_allocator
block|{
name|public
operator|:
typedef|typedef
name|typename
name|_Alloc
operator|::
name|size_type
name|size_type
expr_stmt|;
typedef|typedef
name|typename
name|_Alloc
operator|::
name|difference_type
name|difference_type
expr_stmt|;
typedef|typedef
name|typename
name|_Alloc
operator|::
name|pointer
name|pointer
expr_stmt|;
typedef|typedef
name|typename
name|_Alloc
operator|::
name|const_pointer
name|const_pointer
expr_stmt|;
typedef|typedef
name|typename
name|_Alloc
operator|::
name|reference
name|reference
expr_stmt|;
typedef|typedef
name|typename
name|_Alloc
operator|::
name|const_reference
name|const_reference
expr_stmt|;
typedef|typedef
name|typename
name|_Alloc
operator|::
name|value_type
name|value_type
expr_stmt|;
name|private
label|:
comment|// _M_extra is the number of objects that correspond to the
comment|// extra space where debug information is stored.
name|size_type
name|_M_extra
decl_stmt|;
name|_Alloc
name|_M_allocator
decl_stmt|;
name|public
label|:
name|debug_allocator
argument_list|()
block|{
specifier|const
name|size_t
name|__obj_size
init|=
sizeof|sizeof
argument_list|(
name|value_type
argument_list|)
decl_stmt|;
name|_M_extra
operator|=
operator|(
sizeof|sizeof
argument_list|(
name|size_type
argument_list|)
operator|+
name|__obj_size
operator|-
literal|1
operator|)
operator|/
name|__obj_size
expr_stmt|;
block|}
name|pointer
name|allocate
parameter_list|(
name|size_type
name|__n
parameter_list|)
block|{
name|pointer
name|__res
init|=
name|_M_allocator
operator|.
name|allocate
argument_list|(
name|__n
operator|+
name|_M_extra
argument_list|)
decl_stmt|;
name|size_type
modifier|*
name|__ps
init|=
name|reinterpret_cast
operator|<
name|size_type
operator|*
operator|>
operator|(
name|__res
operator|)
decl_stmt|;
operator|*
name|__ps
operator|=
name|__n
expr_stmt|;
return|return
name|__res
operator|+
name|_M_extra
return|;
block|}
name|pointer
name|allocate
parameter_list|(
name|size_type
name|__n
parameter_list|,
specifier|const
name|void
modifier|*
name|__hint
parameter_list|)
block|{
name|pointer
name|__res
init|=
name|_M_allocator
operator|.
name|allocate
argument_list|(
name|__n
operator|+
name|_M_extra
argument_list|,
name|__hint
argument_list|)
decl_stmt|;
name|size_type
modifier|*
name|__ps
init|=
name|reinterpret_cast
operator|<
name|size_type
operator|*
operator|>
operator|(
name|__res
operator|)
decl_stmt|;
operator|*
name|__ps
operator|=
name|__n
expr_stmt|;
return|return
name|__res
operator|+
name|_M_extra
return|;
block|}
name|void
name|deallocate
parameter_list|(
name|pointer
name|__p
parameter_list|,
name|size_type
name|__n
parameter_list|)
block|{
if|if
condition|(
operator|!
name|__p
condition|)
name|abort
argument_list|()
expr_stmt|;
name|pointer
name|__real_p
init|=
name|__p
operator|-
name|_M_extra
decl_stmt|;
if|if
condition|(
operator|*
name|reinterpret_cast
operator|<
name|size_type
operator|*
operator|>
operator|(
name|__real_p
operator|)
operator|!=
name|__n
condition|)
name|abort
argument_list|()
expr_stmt|;
name|_M_allocator
operator|.
name|deallocate
argument_list|(
name|__real_p
argument_list|,
name|__n
operator|+
name|_M_extra
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace __gnu_cxx
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

