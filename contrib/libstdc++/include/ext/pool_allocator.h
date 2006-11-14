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
comment|/** @file ext/pool_allocator.h  *  This file is a GNU extension to the Standard C++ Library.  *  You should only include this header if you are using GCC 3 or later.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POOL_ALLOCATOR_H
end_ifndef

begin_define
define|#
directive|define
name|_POOL_ALLOCATOR_H
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
file|<cstdlib>
end_include

begin_include
include|#
directive|include
file|<new>
end_include

begin_include
include|#
directive|include
file|<bits/functexcept.h>
end_include

begin_include
include|#
directive|include
file|<bits/atomicity.h>
end_include

begin_include
include|#
directive|include
file|<bits/concurrence.h>
end_include

begin_decl_stmt
name|namespace
name|__gnu_cxx
block|{
comment|/**    *  @if maint    *  Uses various allocators to fulfill underlying requests (and makes as    *  few requests as possible when in default high-speed pool mode).    *    *  Important implementation properties:    *  0. If globally mandated, then allocate objects from new    *  1. If the clients request an object of size> _S_max_bytes, the resulting    *     object will be obtained directly from new    *  2. In all other cases, we allocate an object of size exactly    *     _S_round_up(requested_size).  Thus the client has enough size    *     information that we can return the object to the proper free list    *     without permanently losing part of the object.    *    *  @endif    *  (See @link Allocators allocators info @endlink for more.)    */
name|class
name|__pool_alloc_base
block|{
name|protected
label|:
enum|enum
block|{
name|_S_align
init|=
literal|8
block|}
enum|;
enum|enum
block|{
name|_S_max_bytes
init|=
literal|128
block|}
enum|;
enum|enum
block|{
name|_S_free_list_size
init|=
name|_S_max_bytes
operator|/
name|_S_align
block|}
enum|;
union|union
name|_Obj
block|{
name|union
name|_Obj
modifier|*
name|_M_free_list_link
decl_stmt|;
name|char
name|_M_client_data
index|[
literal|1
index|]
decl_stmt|;
comment|// The client sees this.
block|}
union|;
specifier|static
name|_Obj
modifier|*
specifier|volatile
name|_S_free_list
index|[
name|_S_free_list_size
index|]
decl_stmt|;
comment|// Chunk allocation state.
specifier|static
name|char
modifier|*
name|_S_start_free
decl_stmt|;
specifier|static
name|char
modifier|*
name|_S_end_free
decl_stmt|;
specifier|static
name|size_t
name|_S_heap_size
decl_stmt|;
name|size_t
name|_M_round_up
parameter_list|(
name|size_t
name|__bytes
parameter_list|)
block|{
return|return
operator|(
operator|(
name|__bytes
operator|+
operator|(
name|size_t
operator|)
name|_S_align
operator|-
literal|1
operator|)
operator|&
operator|~
operator|(
operator|(
name|size_t
operator|)
name|_S_align
operator|-
literal|1
operator|)
operator|)
return|;
block|}
name|_Obj
modifier|*
specifier|volatile
modifier|*
name|_M_get_free_list
parameter_list|(
name|size_t
name|__bytes
parameter_list|)
function_decl|;
name|mutex_type
modifier|&
name|_M_get_mutex
parameter_list|()
function_decl|;
comment|// Returns an object of size __n, and optionally adds to size __n
comment|// free list.
name|void
modifier|*
name|_M_refill
parameter_list|(
name|size_t
name|__n
parameter_list|)
function_decl|;
comment|// Allocates a chunk for nobjs of size size.  nobjs may be reduced
comment|// if it is inconvenient to allocate the requested number.
name|char
modifier|*
name|_M_allocate_chunk
parameter_list|(
name|size_t
name|__n
parameter_list|,
name|int
modifier|&
name|__nobjs
parameter_list|)
function_decl|;
block|}
empty_stmt|;
name|template
operator|<
name|typename
name|_Tp
operator|>
name|class
name|__pool_alloc
operator|:
name|private
name|__pool_alloc_base
block|{
name|private
operator|:
specifier|static
name|_Atomic_word
name|_S_force_new
block|;
name|public
operator|:
typedef|typedef
name|size_t
name|size_type
typedef|;
typedef|typedef
name|ptrdiff_t
name|difference_type
typedef|;
typedef|typedef
name|_Tp
modifier|*
name|pointer
typedef|;
typedef|typedef
specifier|const
name|_Tp
modifier|*
name|const_pointer
typedef|;
typedef|typedef
name|_Tp
modifier|&
name|reference
typedef|;
typedef|typedef
specifier|const
name|_Tp
modifier|&
name|const_reference
typedef|;
typedef|typedef
name|_Tp
name|value_type
typedef|;
name|template
operator|<
name|typename
name|_Tp1
operator|>
expr|struct
name|rebind
block|{
typedef|typedef
name|__pool_alloc
operator|<
name|_Tp1
operator|>
name|other
expr_stmt|;
block|}
empty_stmt|;
name|__pool_alloc
argument_list|()
name|throw
argument_list|()
block|{ }
name|__pool_alloc
argument_list|(
argument|const __pool_alloc&
argument_list|)
name|throw
argument_list|()
block|{ }
name|template
operator|<
name|typename
name|_Tp1
operator|>
name|__pool_alloc
argument_list|(
argument|const __pool_alloc<_Tp1>&
argument_list|)
name|throw
argument_list|()
block|{ }
operator|~
name|__pool_alloc
argument_list|()
name|throw
argument_list|()
block|{ }
name|pointer
name|address
argument_list|(
argument|reference __x
argument_list|)
specifier|const
block|{
return|return
operator|&
name|__x
return|;
block|}
name|const_pointer
name|address
argument_list|(
name|const_reference
name|__x
argument_list|)
decl|const
block|{
return|return
operator|&
name|__x
return|;
block|}
name|size_type
name|max_size
argument_list|()
specifier|const
name|throw
argument_list|()
block|{
return|return
name|size_t
argument_list|(
operator|-
literal|1
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
return|;
block|}
comment|// _GLIBCXX_RESOLVE_LIB_DEFECTS
comment|// 402. wrong new expression in [some_] allocator::construct
name|void
name|construct
parameter_list|(
name|pointer
name|__p
parameter_list|,
specifier|const
name|_Tp
modifier|&
name|__val
parameter_list|)
block|{
operator|::
name|new
argument_list|(
argument|__p
argument_list|)
name|_Tp
argument_list|(
name|__val
argument_list|)
expr_stmt|;
block|}
name|void
name|destroy
parameter_list|(
name|pointer
name|__p
parameter_list|)
block|{
name|__p
operator|->
expr|~
name|_Tp
argument_list|()
expr_stmt|;
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
init|=
literal|0
parameter_list|)
function_decl|;
name|void
name|deallocate
parameter_list|(
name|pointer
name|__p
parameter_list|,
name|size_type
name|__n
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|>
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|__pool_alloc
operator|<
name|_Tp
operator|>
operator|&
operator|,
specifier|const
name|__pool_alloc
operator|<
name|_Tp
operator|>
operator|&
operator|)
block|{
return|return
name|true
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
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|__pool_alloc
operator|<
name|_Tp
operator|>
operator|&
operator|,
specifier|const
name|__pool_alloc
operator|<
name|_Tp
operator|>
operator|&
operator|)
block|{
return|return
name|false
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|>
name|_Atomic_word
name|__pool_alloc
operator|<
name|_Tp
operator|>
operator|::
name|_S_force_new
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|>
name|_Tp
operator|*
name|__pool_alloc
operator|<
name|_Tp
operator|>
operator|::
name|allocate
argument_list|(
argument|size_type __n
argument_list|,
argument|const void*
argument_list|)
block|{
name|pointer
name|__ret
operator|=
literal|0
block|;
if|if
condition|(
name|__n
condition|)
block|{
if|if
condition|(
name|__n
operator|<=
name|max_size
argument_list|()
condition|)
block|{
comment|// If there is a race through here, assume answer from getenv
comment|// will resolve in same direction.  Inspired by techniques
comment|// to efficiently support threading found in basic_string.h.
if|if
condition|(
name|_S_force_new
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|getenv
argument_list|(
literal|"GLIBCXX_FORCE_NEW"
argument_list|)
condition|)
name|__atomic_add
argument_list|(
operator|&
name|_S_force_new
argument_list|,
literal|1
argument_list|)
expr_stmt|;
else|else
name|__atomic_add
argument_list|(
operator|&
name|_S_force_new
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
specifier|const
name|size_t
name|__bytes
operator|=
name|__n
operator|*
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|__bytes
operator|>
name|size_t
argument_list|(
name|_S_max_bytes
argument_list|)
operator|||
name|_S_force_new
operator|==
literal|1
condition|)
name|__ret
operator|=
name|static_cast
operator|<
name|_Tp
operator|*
operator|>
operator|(
operator|::
name|operator
name|new
argument_list|(
name|__bytes
argument_list|)
operator|)
expr_stmt|;
else|else
block|{
name|_Obj
modifier|*
specifier|volatile
modifier|*
name|__free_list
init|=
name|_M_get_free_list
argument_list|(
name|__bytes
argument_list|)
decl_stmt|;
name|lock
name|sentry
argument_list|(
name|_M_get_mutex
argument_list|()
argument_list|)
decl_stmt|;
name|_Obj
modifier|*
name|__restrict__
name|__result
init|=
operator|*
name|__free_list
decl_stmt|;
if|if
condition|(
name|__builtin_expect
argument_list|(
name|__result
operator|==
literal|0
argument_list|,
literal|0
argument_list|)
condition|)
name|__ret
operator|=
name|static_cast
operator|<
name|_Tp
operator|*
operator|>
operator|(
name|_M_refill
argument_list|(
name|_M_round_up
argument_list|(
name|__bytes
argument_list|)
argument_list|)
operator|)
expr_stmt|;
else|else
block|{
operator|*
name|__free_list
operator|=
name|__result
operator|->
name|_M_free_list_link
expr_stmt|;
name|__ret
operator|=
name|reinterpret_cast
operator|<
name|_Tp
operator|*
operator|>
operator|(
name|__result
operator|)
expr_stmt|;
block|}
if|if
condition|(
name|__builtin_expect
argument_list|(
name|__ret
operator|==
literal|0
argument_list|,
literal|0
argument_list|)
condition|)
name|std
operator|::
name|__throw_bad_alloc
argument_list|()
expr_stmt|;
block|}
end_if

begin_expr_stmt
unit|} 	  else
name|std
operator|::
name|__throw_bad_alloc
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}       return
name|__ret
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}    template
operator|<
name|typename
name|_Tp
operator|>
name|void
name|__pool_alloc
operator|<
name|_Tp
operator|>
operator|::
name|deallocate
argument_list|(
argument|pointer __p
argument_list|,
argument|size_type __n
argument_list|)
block|{
if|if
condition|(
name|__n
condition|)
block|{
specifier|const
name|size_t
name|__bytes
init|=
name|__n
operator|*
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
decl_stmt|;
if|if
condition|(
name|__bytes
operator|>
name|static_cast
operator|<
name|size_t
operator|>
operator|(
name|_S_max_bytes
operator|)
operator|||
name|_S_force_new
operator|==
literal|1
condition|)
operator|::
name|operator
name|delete
argument_list|(
name|__p
argument_list|)
expr_stmt|;
else|else
block|{
name|_Obj
modifier|*
specifier|volatile
modifier|*
name|__free_list
init|=
name|_M_get_free_list
argument_list|(
name|__bytes
argument_list|)
decl_stmt|;
name|_Obj
modifier|*
name|__q
init|=
name|reinterpret_cast
operator|<
name|_Obj
operator|*
operator|>
operator|(
name|__p
operator|)
decl_stmt|;
name|lock
name|sentry
argument_list|(
name|_M_get_mutex
argument_list|()
argument_list|)
decl_stmt|;
name|__q
operator|->
name|_M_free_list_link
operator|=
operator|*
name|__free_list
expr_stmt|;
operator|*
name|__free_list
operator|=
name|__q
expr_stmt|;
block|}
end_expr_stmt

begin_comment
unit|}     } }
comment|// namespace __gnu_cxx
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

