begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// POSIX thread-related memory allocation -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2001 Free Software Foundation, Inc.
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
comment|/*  * Copyright (c) 1996  * Silicon Graphics Computer Systems, Inc.  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Silicon Graphics makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  */
end_comment

begin_comment
comment|/** @file pthread_allocimpl.h  *  This is an internal header file, included by other library headers.  *  You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CPP_BITS_PTHREAD_ALLOCIMPL_H
end_ifndef

begin_define
define|#
directive|define
name|_CPP_BITS_PTHREAD_ALLOCIMPL_H
value|1
end_define

begin_comment
comment|// Pthread-specific node allocator.
end_comment

begin_comment
comment|// This is similar to the default allocator, except that free-list
end_comment

begin_comment
comment|// information is kept separately for each thread, avoiding locking.
end_comment

begin_comment
comment|// This should be reasonably fast even in the presence of threads.
end_comment

begin_comment
comment|// The down side is that storage may not be well-utilized.
end_comment

begin_comment
comment|// It is not an error to allocate memory in thread A and deallocate
end_comment

begin_comment
comment|// it in thread B.  But this effectively transfers ownership of the memory,
end_comment

begin_comment
comment|// so that it can only be reallocated by thread B.  Thus this can effectively
end_comment

begin_comment
comment|// result in a storage leak if it's done on a regular basis.
end_comment

begin_comment
comment|// It can also result in frequent sharing of
end_comment

begin_comment
comment|// cache lines among processors, with potentially serious performance
end_comment

begin_comment
comment|// consequences.
end_comment

begin_include
include|#
directive|include
file|<bits/c++config.h>
end_include

begin_include
include|#
directive|include
file|<cerrno>
end_include

begin_include
include|#
directive|include
file|<bits/stl_alloc.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__RESTRICT
end_ifndef

begin_define
define|#
directive|define
name|__RESTRICT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<new>
end_include

begin_decl_stmt
name|namespace
name|std
block|{
define|#
directive|define
name|__STL_DATA_ALIGNMENT
value|8
union|union
name|_Pthread_alloc_obj
block|{
name|union
name|_Pthread_alloc_obj
modifier|*
name|__free_list_link
decl_stmt|;
name|char
name|__client_data
index|[
name|__STL_DATA_ALIGNMENT
index|]
decl_stmt|;
comment|/* The client sees this.    */
block|}
union|;
comment|// Pthread allocators don't appear to the client to have meaningful
comment|// instances.  We do in fact need to associate some state with each
comment|// thread.  That state is represented by
comment|// _Pthread_alloc_per_thread_state<_Max_size>.
name|template
operator|<
name|size_t
name|_Max_size
operator|>
expr|struct
name|_Pthread_alloc_per_thread_state
block|{
typedef|typedef
name|_Pthread_alloc_obj
name|__obj
typedef|;
block|enum
block|{
name|_S_NFREELISTS
operator|=
name|_Max_size
operator|/
name|__STL_DATA_ALIGNMENT
block|}
expr_stmt|;
name|_Pthread_alloc_obj
modifier|*
specifier|volatile
name|__free_list
index|[
name|_S_NFREELISTS
index|]
decl_stmt|;
name|_Pthread_alloc_per_thread_state
operator|<
name|_Max_size
operator|>
operator|*
name|__next
expr_stmt|;
comment|// Free list link for list of available per thread structures.
comment|// When one of these becomes available for reuse due to thread
comment|// termination, any objects in its free list remain associated
comment|// with it.  The whole structure may then be used by a newly
comment|// created thread.
name|_Pthread_alloc_per_thread_state
argument_list|()
operator|:
name|__next
argument_list|(
literal|0
argument_list|)
block|{
name|memset
argument_list|(
operator|(
name|void
operator|*
operator|)
name|__free_list
argument_list|,
literal|0
argument_list|,
operator|(
name|size_t
operator|)
name|_S_NFREELISTS
operator|*
sizeof|sizeof
argument_list|(
name|__obj
operator|*
argument_list|)
argument_list|)
block|;   }
comment|// Returns an object of size __n, and possibly adds to size n free list.
name|void
operator|*
name|_M_refill
argument_list|(
argument|size_t __n
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Pthread-specific allocator.
end_comment

begin_comment
comment|// The argument specifies the largest object size allocated from per-thread
end_comment

begin_comment
comment|// free lists.  Larger objects are allocated using malloc_alloc.
end_comment

begin_comment
comment|// Max_size must be a power of 2.
end_comment

begin_expr_stmt
name|template
operator|<
name|size_t
name|_Max_size
operator|=
literal|128
operator|>
name|class
name|_Pthread_alloc_template
block|{
name|public
operator|:
comment|// but only for internal use:
typedef|typedef
name|_Pthread_alloc_obj
name|__obj
typedef|;
comment|// Allocates a chunk for nobjs of size size.  nobjs may be reduced
comment|// if it is inconvenient to allocate the requested number.
specifier|static
name|char
operator|*
name|_S_chunk_alloc
argument_list|(
argument|size_t __size
argument_list|,
argument|int&__nobjs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_enum
enum|enum
block|{
name|_S_ALIGN
init|=
name|__STL_DATA_ALIGNMENT
block|}
enum|;
end_enum

begin_function
specifier|static
name|size_t
name|_S_round_up
parameter_list|(
name|size_t
name|__bytes
parameter_list|)
block|{
return|return
operator|(
operator|(
operator|(
name|__bytes
operator|)
operator|+
operator|(
name|int
operator|)
name|_S_ALIGN
operator|-
literal|1
operator|)
operator|&
operator|~
operator|(
operator|(
name|int
operator|)
name|_S_ALIGN
operator|-
literal|1
operator|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|size_t
name|_S_freelist_index
parameter_list|(
name|size_t
name|__bytes
parameter_list|)
block|{
return|return
operator|(
operator|(
operator|(
name|__bytes
operator|)
operator|+
operator|(
name|int
operator|)
name|_S_ALIGN
operator|-
literal|1
operator|)
operator|/
operator|(
name|int
operator|)
name|_S_ALIGN
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_comment
comment|// Chunk allocation state. And other shared state.
end_comment

begin_comment
comment|// Protected by _S_chunk_allocator_lock.
end_comment

begin_decl_stmt
specifier|static
name|pthread_mutex_t
name|_S_chunk_allocator_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|_S_start_free
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|_S_end_free
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|size_t
name|_S_heap_size
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|static
name|_Pthread_alloc_per_thread_state
operator|<
name|_Max_size
operator|>
operator|*
name|_S_free_per_thread_states
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|pthread_key_t
name|_S_key
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|bool
name|_S_key_initialized
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Pthread key under which per thread state is stored.
end_comment

begin_comment
comment|// Allocator instances that are currently unclaimed by any thread.
end_comment

begin_function_decl
specifier|static
name|void
name|_S_destructor
parameter_list|(
name|void
modifier|*
name|instance
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Function to be called on thread exit to reclaim per thread
end_comment

begin_comment
comment|// state.
end_comment

begin_expr_stmt
specifier|static
name|_Pthread_alloc_per_thread_state
operator|<
name|_Max_size
operator|>
operator|*
name|_S_new_per_thread_state
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Return a recycled or new per thread state.
end_comment

begin_expr_stmt
specifier|static
name|_Pthread_alloc_per_thread_state
operator|<
name|_Max_size
operator|>
operator|*
name|_S_get_per_thread_state
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|// ensure that the current thread has an associated
end_comment

begin_comment
comment|// per thread state.
end_comment

begin_decl_stmt
name|class
name|_M_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|_M_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|_M_lock
block|{
name|public
label|:
name|_M_lock
argument_list|()
block|{
name|pthread_mutex_lock
argument_list|(
operator|&
name|_S_chunk_allocator_lock
argument_list|)
expr_stmt|;
block|}
operator|~
name|_M_lock
argument_list|()
block|{
name|pthread_mutex_unlock
argument_list|(
operator|&
name|_S_chunk_allocator_lock
argument_list|)
block|; }
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|/* n must be> 0      */
end_comment

begin_function
specifier|static
name|void
modifier|*
name|allocate
parameter_list|(
name|size_t
name|__n
parameter_list|)
block|{
name|__obj
modifier|*
specifier|volatile
modifier|*
name|__my_free_list
decl_stmt|;
name|__obj
modifier|*
name|__RESTRICT
name|__result
decl_stmt|;
name|_Pthread_alloc_per_thread_state
operator|<
name|_Max_size
operator|>
operator|*
name|__a
expr_stmt|;
if|if
condition|(
name|__n
operator|>
name|_Max_size
condition|)
block|{
return|return
operator|(
name|malloc_alloc
operator|::
name|allocate
argument_list|(
name|__n
argument_list|)
operator|)
return|;
block|}
if|if
condition|(
operator|!
name|_S_key_initialized
operator|||
operator|!
operator|(
name|__a
operator|=
operator|(
name|_Pthread_alloc_per_thread_state
operator|<
name|_Max_size
operator|>
operator|*
operator|)
name|pthread_getspecific
argument_list|(
name|_S_key
argument_list|)
operator|)
condition|)
block|{
name|__a
operator|=
name|_S_get_per_thread_state
argument_list|()
expr_stmt|;
block|}
name|__my_free_list
operator|=
name|__a
operator|->
name|__free_list
operator|+
name|_S_freelist_index
argument_list|(
name|__n
argument_list|)
expr_stmt|;
name|__result
operator|=
operator|*
name|__my_free_list
expr_stmt|;
if|if
condition|(
name|__result
operator|==
literal|0
condition|)
block|{
name|void
modifier|*
name|__r
init|=
name|__a
operator|->
name|_M_refill
argument_list|(
name|_S_round_up
argument_list|(
name|__n
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|__r
return|;
block|}
operator|*
name|__my_free_list
operator|=
name|__result
operator|->
name|__free_list_link
expr_stmt|;
return|return
operator|(
name|__result
operator|)
return|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* p may not be 0 */
end_comment

begin_function
specifier|static
name|void
name|deallocate
parameter_list|(
name|void
modifier|*
name|__p
parameter_list|,
name|size_t
name|__n
parameter_list|)
block|{
name|__obj
modifier|*
name|__q
init|=
operator|(
name|__obj
operator|*
operator|)
name|__p
decl_stmt|;
name|__obj
modifier|*
specifier|volatile
modifier|*
name|__my_free_list
decl_stmt|;
name|_Pthread_alloc_per_thread_state
operator|<
name|_Max_size
operator|>
operator|*
name|__a
expr_stmt|;
if|if
condition|(
name|__n
operator|>
name|_Max_size
condition|)
block|{
name|malloc_alloc
operator|::
name|deallocate
argument_list|(
name|__p
argument_list|,
name|__n
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
operator|!
name|_S_key_initialized
operator|||
operator|!
operator|(
name|__a
operator|=
operator|(
name|_Pthread_alloc_per_thread_state
operator|<
name|_Max_size
operator|>
operator|*
operator|)
name|pthread_getspecific
argument_list|(
name|_S_key
argument_list|)
operator|)
condition|)
block|{
name|__a
operator|=
name|_S_get_per_thread_state
argument_list|()
expr_stmt|;
block|}
name|__my_free_list
operator|=
name|__a
operator|->
name|__free_list
operator|+
name|_S_freelist_index
argument_list|(
name|__n
argument_list|)
expr_stmt|;
name|__q
operator|->
name|__free_list_link
operator|=
operator|*
name|__my_free_list
expr_stmt|;
operator|*
name|__my_free_list
operator|=
name|__q
expr_stmt|;
block|}
end_function

begin_function_decl
specifier|static
name|void
modifier|*
name|reallocate
parameter_list|(
name|void
modifier|*
name|__p
parameter_list|,
name|size_t
name|__old_sz
parameter_list|,
name|size_t
name|__new_sz
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
unit|} ;
typedef|typedef
name|_Pthread_alloc_template
operator|<
operator|>
name|pthread_alloc
expr_stmt|;
end_typedef

begin_expr_stmt
name|template
operator|<
name|size_t
name|_Max_size
operator|>
name|void
name|_Pthread_alloc_template
operator|<
name|_Max_size
operator|>
operator|::
name|_S_destructor
argument_list|(
argument|void * __instance
argument_list|)
block|{
name|_M_lock
name|__lock_instance
block|;
comment|// Need to acquire lock here.
name|_Pthread_alloc_per_thread_state
operator|<
name|_Max_size
operator|>
operator|*
name|__s
operator|=
operator|(
name|_Pthread_alloc_per_thread_state
operator|<
name|_Max_size
operator|>
operator|*
operator|)
name|__instance
block|;
name|__s
operator|->
name|__next
operator|=
name|_S_free_per_thread_states
block|;
name|_S_free_per_thread_states
operator|=
name|__s
block|; }
name|template
operator|<
name|size_t
name|_Max_size
operator|>
name|_Pthread_alloc_per_thread_state
operator|<
name|_Max_size
operator|>
operator|*
name|_Pthread_alloc_template
operator|<
name|_Max_size
operator|>
operator|::
name|_S_new_per_thread_state
argument_list|()
block|{
comment|/* lock already held here.	*/
if|if
condition|(
literal|0
operator|!=
name|_S_free_per_thread_states
condition|)
block|{
name|_Pthread_alloc_per_thread_state
operator|<
name|_Max_size
operator|>
operator|*
name|__result
operator|=
name|_S_free_per_thread_states
expr_stmt|;
name|_S_free_per_thread_states
operator|=
name|_S_free_per_thread_states
operator|->
name|__next
expr_stmt|;
return|return
name|__result
return|;
block|}
end_expr_stmt

begin_else
else|else
block|{
return|return
name|new
name|_Pthread_alloc_per_thread_state
operator|<
name|_Max_size
operator|>
return|;
block|}
end_else

begin_expr_stmt
unit|}  template
operator|<
name|size_t
name|_Max_size
operator|>
name|_Pthread_alloc_per_thread_state
operator|<
name|_Max_size
operator|>
operator|*
name|_Pthread_alloc_template
operator|<
name|_Max_size
operator|>
operator|::
name|_S_get_per_thread_state
argument_list|()
block|{
comment|/*REFERENCED*/
name|_M_lock
name|__lock_instance
block|;
comment|// Need to acquire lock here.
name|int
name|__ret_code
block|;
name|_Pthread_alloc_per_thread_state
operator|<
name|_Max_size
operator|>
operator|*
name|__result
block|;
if|if
condition|(
operator|!
name|_S_key_initialized
condition|)
block|{
if|if
condition|(
name|pthread_key_create
argument_list|(
operator|&
name|_S_key
argument_list|,
name|_S_destructor
argument_list|)
condition|)
block|{
name|std
operator|::
name|__throw_bad_alloc
argument_list|()
expr_stmt|;
comment|// defined in funcexcept.h
block|}
name|_S_key_initialized
operator|=
name|true
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}     __result
operator|=
name|_S_new_per_thread_state
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__ret_code
operator|=
name|pthread_setspecific
argument_list|(
name|_S_key
argument_list|,
name|__result
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|__ret_code
condition|)
block|{
if|if
condition|(
name|__ret_code
operator|==
name|ENOMEM
condition|)
block|{
name|std
operator|::
name|__throw_bad_alloc
argument_list|()
expr_stmt|;
block|}
else|else
block|{
comment|// EINVAL
name|abort
argument_list|()
expr_stmt|;
block|}
block|}
end_if

begin_return
return|return
name|__result
return|;
end_return

begin_comment
unit|}
comment|/* We allocate memory in large chunks in order to avoid fragmenting     */
end_comment

begin_comment
comment|/* the malloc heap too much.                                            */
end_comment

begin_comment
comment|/* We assume that size is properly aligned.                             */
end_comment

begin_expr_stmt
unit|template
operator|<
name|size_t
name|_Max_size
operator|>
name|char
operator|*
name|_Pthread_alloc_template
operator|<
name|_Max_size
operator|>
operator|::
name|_S_chunk_alloc
argument_list|(
argument|size_t __size
argument_list|,
argument|int&__nobjs
argument_list|)
block|{
block|{
name|char
operator|*
name|__result
block|;
name|size_t
name|__total_bytes
block|;
name|size_t
name|__bytes_left
block|;
comment|/*REFERENCED*/
name|_M_lock
name|__lock_instance
block|;
comment|// Acquire lock for this routine
name|__total_bytes
operator|=
name|__size
operator|*
name|__nobjs
block|;
name|__bytes_left
operator|=
name|_S_end_free
operator|-
name|_S_start_free
block|;
if|if
condition|(
name|__bytes_left
operator|>=
name|__total_bytes
condition|)
block|{
name|__result
operator|=
name|_S_start_free
expr_stmt|;
name|_S_start_free
operator|+=
name|__total_bytes
expr_stmt|;
return|return
operator|(
name|__result
operator|)
return|;
block|}
elseif|else
if|if
condition|(
name|__bytes_left
operator|>=
name|__size
condition|)
block|{
name|__nobjs
operator|=
name|__bytes_left
operator|/
name|__size
expr_stmt|;
name|__total_bytes
operator|=
name|__size
operator|*
name|__nobjs
expr_stmt|;
name|__result
operator|=
name|_S_start_free
expr_stmt|;
name|_S_start_free
operator|+=
name|__total_bytes
expr_stmt|;
return|return
operator|(
name|__result
operator|)
return|;
block|}
end_expr_stmt

begin_else
else|else
block|{
name|size_t
name|__bytes_to_get
init|=
literal|2
operator|*
name|__total_bytes
operator|+
name|_S_round_up
argument_list|(
name|_S_heap_size
operator|>>
literal|4
argument_list|)
decl_stmt|;
comment|// Try to make use of the left-over piece.
if|if
condition|(
name|__bytes_left
operator|>
literal|0
condition|)
block|{
name|_Pthread_alloc_per_thread_state
operator|<
name|_Max_size
operator|>
operator|*
name|__a
operator|=
operator|(
name|_Pthread_alloc_per_thread_state
operator|<
name|_Max_size
operator|>
operator|*
operator|)
name|pthread_getspecific
argument_list|(
name|_S_key
argument_list|)
expr_stmt|;
name|__obj
modifier|*
specifier|volatile
modifier|*
name|__my_free_list
init|=
name|__a
operator|->
name|__free_list
operator|+
name|_S_freelist_index
argument_list|(
name|__bytes_left
argument_list|)
decl_stmt|;
operator|(
operator|(
name|__obj
operator|*
operator|)
name|_S_start_free
operator|)
operator|->
name|__free_list_link
operator|=
operator|*
name|__my_free_list
expr_stmt|;
operator|*
name|__my_free_list
operator|=
operator|(
name|__obj
operator|*
operator|)
name|_S_start_free
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|_SGI_SOURCE
comment|// Try to get memory that's aligned on something like a
comment|// cache line boundary, so as to avoid parceling out
comment|// parts of the same line to different threads and thus
comment|// possibly different processors.
block|{
specifier|const
name|int
name|__cache_line_size
init|=
literal|128
decl_stmt|;
comment|// probable upper bound
name|__bytes_to_get
operator|&=
operator|~
operator|(
name|__cache_line_size
operator|-
literal|1
operator|)
expr_stmt|;
name|_S_start_free
operator|=
operator|(
name|char
operator|*
operator|)
name|memalign
argument_list|(
name|__cache_line_size
argument_list|,
name|__bytes_to_get
argument_list|)
expr_stmt|;
if|if
condition|(
literal|0
operator|==
name|_S_start_free
condition|)
block|{
name|_S_start_free
operator|=
operator|(
name|char
operator|*
operator|)
name|malloc_alloc
operator|::
name|allocate
argument_list|(
name|__bytes_to_get
argument_list|)
expr_stmt|;
block|}
block|}
else|#
directive|else
comment|/* !SGI_SOURCE */
name|_S_start_free
operator|=
operator|(
name|char
operator|*
operator|)
name|malloc_alloc
operator|::
name|allocate
argument_list|(
name|__bytes_to_get
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|_S_heap_size
operator|+=
name|__bytes_to_get
expr_stmt|;
name|_S_end_free
operator|=
name|_S_start_free
operator|+
name|__bytes_to_get
expr_stmt|;
block|}
end_else

begin_comment
unit|}
comment|// lock is released here
end_comment

begin_expr_stmt
unit|return
operator|(
name|_S_chunk_alloc
argument_list|(
name|__size
argument_list|,
name|__nobjs
argument_list|)
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|/* Returns an object of size n, and optionally adds to size n free list.*/
end_comment

begin_comment
comment|/* We assume that n is properly aligned.                                */
end_comment

begin_comment
comment|/* We hold the allocation lock.                                         */
end_comment

begin_expr_stmt
unit|template
operator|<
name|size_t
name|_Max_size
operator|>
name|void
operator|*
name|_Pthread_alloc_per_thread_state
operator|<
name|_Max_size
operator|>
operator|::
name|_M_refill
argument_list|(
argument|size_t __n
argument_list|)
block|{
name|int
name|__nobjs
operator|=
literal|128
block|;
name|char
operator|*
name|__chunk
operator|=
name|_Pthread_alloc_template
operator|<
name|_Max_size
operator|>
operator|::
name|_S_chunk_alloc
argument_list|(
name|__n
argument_list|,
name|__nobjs
argument_list|)
block|;
name|__obj
operator|*
specifier|volatile
operator|*
name|__my_free_list
block|;
name|__obj
operator|*
name|__result
block|;
name|__obj
operator|*
name|__current_obj
block|,
operator|*
name|__next_obj
block|;
name|int
name|__i
block|;
if|if
condition|(
literal|1
operator|==
name|__nobjs
condition|)
block|{
return|return
operator|(
name|__chunk
operator|)
return|;
block|}
name|__my_free_list
operator|=
name|__free_list
operator|+
name|_Pthread_alloc_template
operator|<
name|_Max_size
operator|>
operator|::
name|_S_freelist_index
argument_list|(
name|__n
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Build free list in chunk */
end_comment

begin_expr_stmt
name|__result
operator|=
operator|(
name|__obj
operator|*
operator|)
name|__chunk
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|*
name|__my_free_list
operator|=
name|__next_obj
operator|=
operator|(
name|__obj
operator|*
operator|)
operator|(
name|__chunk
operator|+
name|__n
operator|)
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
name|__i
operator|=
literal|1
init|;
condition|;
name|__i
operator|++
control|)
block|{
name|__current_obj
operator|=
name|__next_obj
expr_stmt|;
name|__next_obj
operator|=
operator|(
name|__obj
operator|*
operator|)
operator|(
operator|(
name|char
operator|*
operator|)
name|__next_obj
operator|+
name|__n
operator|)
expr_stmt|;
if|if
condition|(
name|__nobjs
operator|-
literal|1
operator|==
name|__i
condition|)
block|{
name|__current_obj
operator|->
name|__free_list_link
operator|=
literal|0
expr_stmt|;
break|break;
block|}
else|else
block|{
name|__current_obj
operator|->
name|__free_list_link
operator|=
name|__next_obj
expr_stmt|;
block|}
block|}
end_for

begin_return
return|return
operator|(
name|__result
operator|)
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|size_t
name|_Max_size
operator|>
name|void
operator|*
name|_Pthread_alloc_template
operator|<
name|_Max_size
operator|>
operator|::
name|reallocate
argument_list|(
argument|void *__p
argument_list|,
argument|size_t __old_sz
argument_list|,
argument|size_t __new_sz
argument_list|)
block|{
name|void
operator|*
name|__result
block|;
name|size_t
name|__copy_sz
block|;
if|if
condition|(
name|__old_sz
operator|>
name|_Max_size
operator|&&
name|__new_sz
operator|>
name|_Max_size
condition|)
block|{
return|return
operator|(
name|realloc
argument_list|(
name|__p
argument_list|,
name|__new_sz
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_if
if|if
condition|(
name|_S_round_up
argument_list|(
name|__old_sz
argument_list|)
operator|==
name|_S_round_up
argument_list|(
name|__new_sz
argument_list|)
condition|)
return|return
operator|(
name|__p
operator|)
return|;
end_if

begin_expr_stmt
name|__result
operator|=
name|allocate
argument_list|(
name|__new_sz
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__copy_sz
operator|=
name|__new_sz
operator|>
name|__old_sz
condition|?
name|__old_sz
else|:
name|__new_sz
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|memcpy
argument_list|(
name|__result
argument_list|,
name|__p
argument_list|,
name|__copy_sz
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|deallocate
argument_list|(
name|__p
argument_list|,
name|__old_sz
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|(
name|__result
operator|)
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|size_t
name|_Max_size
operator|>
name|_Pthread_alloc_per_thread_state
operator|<
name|_Max_size
operator|>
operator|*
name|_Pthread_alloc_template
operator|<
name|_Max_size
operator|>
operator|::
name|_S_free_per_thread_states
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|size_t
name|_Max_size
operator|>
name|pthread_key_t
name|_Pthread_alloc_template
operator|<
name|_Max_size
operator|>
operator|::
name|_S_key
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|size_t
name|_Max_size
operator|>
name|bool
name|_Pthread_alloc_template
operator|<
name|_Max_size
operator|>
operator|::
name|_S_key_initialized
operator|=
name|false
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|size_t
name|_Max_size
operator|>
name|pthread_mutex_t
name|_Pthread_alloc_template
operator|<
name|_Max_size
operator|>
operator|::
name|_S_chunk_allocator_lock
operator|=
name|PTHREAD_MUTEX_INITIALIZER
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|size_t
name|_Max_size
operator|>
name|char
operator|*
name|_Pthread_alloc_template
operator|<
name|_Max_size
operator|>
operator|::
name|_S_start_free
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|size_t
name|_Max_size
operator|>
name|char
operator|*
name|_Pthread_alloc_template
operator|<
name|_Max_size
operator|>
operator|::
name|_S_end_free
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|size_t
name|_Max_size
operator|>
name|size_t
name|_Pthread_alloc_template
operator|<
name|_Max_size
operator|>
operator|::
name|_S_heap_size
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|>
name|class
name|pthread_allocator
block|{
typedef|typedef
name|pthread_alloc
name|_S_Alloc
typedef|;
comment|// The underlying allocator.
name|public
operator|:
end_expr_stmt

begin_typedef
typedef|typedef
name|size_t
name|size_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ptrdiff_t
name|difference_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Tp
modifier|*
name|pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|_Tp
modifier|*
name|const_pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Tp
modifier|&
name|reference
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|_Tp
modifier|&
name|const_reference
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|_Tp
name|value_type
typedef|;
end_typedef

begin_expr_stmt
name|template
operator|<
name|class
name|_NewType
operator|>
expr|struct
name|rebind
block|{
typedef|typedef
name|pthread_allocator
operator|<
name|_NewType
operator|>
name|other
expr_stmt|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|pthread_allocator
argument_list|()
end_macro

begin_macro
name|throw
argument_list|()
end_macro

begin_block
block|{}
end_block

begin_macro
name|pthread_allocator
argument_list|(
argument|const pthread_allocator& a
argument_list|)
end_macro

begin_macro
name|throw
argument_list|()
end_macro

begin_block
block|{}
end_block

begin_expr_stmt
name|template
operator|<
name|class
name|_OtherType
operator|>
name|pthread_allocator
argument_list|(
argument|const pthread_allocator<_OtherType>&
argument_list|)
name|throw
argument_list|()
block|{}
operator|~
name|pthread_allocator
argument_list|()
name|throw
argument_list|()
block|{}
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
end_expr_stmt

begin_decl_stmt
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
end_decl_stmt

begin_comment
comment|// __n is permitted to be 0.  The C++ standard says nothing about what
end_comment

begin_comment
comment|// the return value is when __n == 0.
end_comment

begin_function
name|_Tp
modifier|*
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
block|{
return|return
name|__n
operator|!=
literal|0
condition|?
name|static_cast
operator|<
name|_Tp
operator|*
operator|>
operator|(
name|_S_Alloc
operator|::
name|allocate
argument_list|(
name|__n
operator|*
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
argument_list|)
operator|)
else|:
literal|0
return|;
block|}
end_function

begin_comment
comment|// p is not permitted to be a null pointer.
end_comment

begin_function
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
name|_S_Alloc
operator|::
name|deallocate
argument_list|(
name|__p
argument_list|,
name|__n
operator|*
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
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
end_expr_stmt

begin_function
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
end_function

begin_function
name|void
name|destroy
parameter_list|(
name|pointer
name|_p
parameter_list|)
block|{
name|_p
operator|->
expr|~
name|_Tp
argument_list|()
expr_stmt|;
block|}
end_function

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
name|class
name|pthread_allocator
operator|<
name|void
operator|>
block|{
name|public
operator|:
typedef|typedef
name|size_t
name|size_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|ptrdiff_t
name|difference_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|void
modifier|*
name|const_pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|value_type
typedef|;
end_typedef

begin_expr_stmt
name|template
operator|<
name|class
name|_NewType
operator|>
expr|struct
name|rebind
block|{
typedef|typedef
name|pthread_allocator
operator|<
name|_NewType
operator|>
name|other
expr_stmt|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|size_t
name|_Max_size
operator|>
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|_Pthread_alloc_template
operator|<
name|_Max_size
operator|>
operator|&
operator|,
specifier|const
name|_Pthread_alloc_template
operator|<
name|_Max_size
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
name|class
name|_T1
operator|,
name|class
name|_T2
operator|>
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|pthread_allocator
operator|<
name|_T1
operator|>
operator|&
operator|,
specifier|const
name|pthread_allocator
operator|<
name|_T2
operator|>
operator|&
name|a2
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
name|class
name|_T1
operator|,
name|class
name|_T2
operator|>
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|pthread_allocator
operator|<
name|_T1
operator|>
operator|&
operator|,
specifier|const
name|pthread_allocator
operator|<
name|_T2
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
name|class
name|_Tp
operator|,
name|size_t
name|_Max_size
operator|>
expr|struct
name|_Alloc_traits
operator|<
name|_Tp
operator|,
name|_Pthread_alloc_template
operator|<
name|_Max_size
operator|>
expr|>
block|{
specifier|static
specifier|const
name|bool
name|_S_instanceless
operator|=
name|true
block|;
typedef|typedef
name|simple_alloc
operator|<
name|_Tp
operator|,
name|_Pthread_alloc_template
operator|<
name|_Max_size
operator|>
expr|>
name|_Alloc_type
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__allocator
operator|<
name|_Tp
operator|,
name|_Pthread_alloc_template
operator|<
name|_Max_size
operator|>
expr|>
name|allocator_type
expr_stmt|;
end_typedef

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|_Tp
operator|,
name|class
name|_Atype
operator|,
name|size_t
name|_Max
operator|>
expr|struct
name|_Alloc_traits
operator|<
name|_Tp
operator|,
name|__allocator
operator|<
name|_Atype
operator|,
name|_Pthread_alloc_template
operator|<
name|_Max
operator|>
expr|>
operator|>
block|{
specifier|static
specifier|const
name|bool
name|_S_instanceless
operator|=
name|true
block|;
typedef|typedef
name|simple_alloc
operator|<
name|_Tp
operator|,
name|_Pthread_alloc_template
operator|<
name|_Max
operator|>
expr|>
name|_Alloc_type
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__allocator
operator|<
name|_Tp
operator|,
name|_Pthread_alloc_template
operator|<
name|_Max
operator|>
expr|>
name|allocator_type
expr_stmt|;
end_typedef

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|_Tp
operator|,
name|class
name|_Atype
operator|>
expr|struct
name|_Alloc_traits
operator|<
name|_Tp
operator|,
name|pthread_allocator
operator|<
name|_Atype
operator|>
expr|>
block|{
specifier|static
specifier|const
name|bool
name|_S_instanceless
operator|=
name|true
block|;
typedef|typedef
name|simple_alloc
operator|<
name|_Tp
operator|,
name|_Pthread_alloc_template
operator|<
operator|>
expr|>
name|_Alloc_type
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|pthread_allocator
operator|<
name|_Tp
operator|>
name|allocator_type
expr_stmt|;
end_typedef

begin_comment
unit|};   }
comment|// namespace std
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CPP_BITS_PTHREAD_ALLOCIMPL_H */
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

