begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// MT-optimized allocator -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2003, 2004, 2005, 2006 Free Software Foundation, Inc.
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
comment|/** @file ext/mt_allocator.h  *  This file is a GNU extension to the Standard C++ Library.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MT_ALLOCATOR_H
end_ifndef

begin_define
define|#
directive|define
name|_MT_ALLOCATOR_H
value|1
end_define

begin_include
include|#
directive|include
file|<new>
end_include

begin_include
include|#
directive|include
file|<cstdlib>
end_include

begin_include
include|#
directive|include
file|<bits/functexcept.h>
end_include

begin_include
include|#
directive|include
file|<ext/atomicity.h>
end_include

begin_macro
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
argument|__gnu_cxx
argument_list|)
end_macro

begin_expr_stmt
name|using
name|std
operator|::
name|size_t
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|ptrdiff_t
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|__destroy_handler
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/// @brief  Base class for pool object.
end_comment

begin_struct
struct|struct
name|__pool_base
block|{
comment|// Using short int as type for the binmap implies we are never
comment|// caching blocks larger than 32768 with this allocator.
typedef|typedef
name|unsigned
name|short
name|int
name|_Binmap_type
typedef|;
comment|// Variables used to configure the behavior of the allocator,
comment|// assigned and explained in detail below.
struct|struct
name|_Tune
block|{
comment|// Compile time constants for the default _Tune values.
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
name|_S_min_bin
init|=
literal|8
block|}
enum|;
enum|enum
block|{
name|_S_chunk_size
init|=
literal|4096
operator|-
literal|4
operator|*
expr|sizeof
operator|(
name|void
operator|*
operator|)
block|}
enum|;
enum|enum
block|{
name|_S_max_threads
init|=
literal|4096
block|}
enum|;
enum|enum
block|{
name|_S_freelist_headroom
init|=
literal|10
block|}
enum|;
comment|// Alignment needed.
comment|// NB: In any case must be>= sizeof(_Block_record), that
comment|// is 4 on 32 bit machines and 8 on 64 bit machines.
name|size_t
name|_M_align
decl_stmt|;
comment|// Allocation requests (after round-up to power of 2) below
comment|// this value will be handled by the allocator. A raw new/
comment|// call will be used for requests larger than this value.
comment|// NB: Must be much smaller than _M_chunk_size and in any
comment|// case<= 32768.
name|size_t
name|_M_max_bytes
decl_stmt|;
comment|// Size in bytes of the smallest bin.
comment|// NB: Must be a power of 2 and>= _M_align (and of course
comment|// much smaller than _M_max_bytes).
name|size_t
name|_M_min_bin
decl_stmt|;
comment|// In order to avoid fragmenting and minimize the number of
comment|// new() calls we always request new memory using this
comment|// value. Based on previous discussions on the libstdc++
comment|// mailing list we have choosen the value below.
comment|// See http://gcc.gnu.org/ml/libstdc++/2001-07/msg00077.html
comment|// NB: At least one order of magnitude> _M_max_bytes.
name|size_t
name|_M_chunk_size
decl_stmt|;
comment|// The maximum number of supported threads. For
comment|// single-threaded operation, use one. Maximum values will
comment|// vary depending on details of the underlying system. (For
comment|// instance, Linux 2.4.18 reports 4070 in
comment|// /proc/sys/kernel/threads-max, while Linux 2.6.6 reports
comment|// 65534)
name|size_t
name|_M_max_threads
decl_stmt|;
comment|// Each time a deallocation occurs in a threaded application
comment|// we make sure that there are no more than
comment|// _M_freelist_headroom % of used memory on the freelist. If
comment|// the number of additional records is more than
comment|// _M_freelist_headroom % of the freelist, we move these
comment|// records back to the global pool.
name|size_t
name|_M_freelist_headroom
decl_stmt|;
comment|// Set to true forces all allocations to use new().
name|bool
name|_M_force_new
decl_stmt|;
name|explicit
name|_Tune
argument_list|()
operator|:
name|_M_align
argument_list|(
name|_S_align
argument_list|)
operator|,
name|_M_max_bytes
argument_list|(
name|_S_max_bytes
argument_list|)
operator|,
name|_M_min_bin
argument_list|(
name|_S_min_bin
argument_list|)
operator|,
name|_M_chunk_size
argument_list|(
name|_S_chunk_size
argument_list|)
operator|,
name|_M_max_threads
argument_list|(
name|_S_max_threads
argument_list|)
operator|,
name|_M_freelist_headroom
argument_list|(
name|_S_freelist_headroom
argument_list|)
operator|,
name|_M_force_new
argument_list|(
argument|std::getenv(
literal|"GLIBCXX_FORCE_NEW"
argument|) ? true : false
argument_list|)
block|{ }
name|explicit
name|_Tune
argument_list|(
argument|size_t __align
argument_list|,
argument|size_t __maxb
argument_list|,
argument|size_t __minbin
argument_list|,
argument|size_t __chunk
argument_list|,
argument|size_t __maxthreads
argument_list|,
argument|size_t __headroom
argument_list|,
argument|bool __force
argument_list|)
operator|:
name|_M_align
argument_list|(
name|__align
argument_list|)
operator|,
name|_M_max_bytes
argument_list|(
name|__maxb
argument_list|)
operator|,
name|_M_min_bin
argument_list|(
name|__minbin
argument_list|)
operator|,
name|_M_chunk_size
argument_list|(
name|__chunk
argument_list|)
operator|,
name|_M_max_threads
argument_list|(
name|__maxthreads
argument_list|)
operator|,
name|_M_freelist_headroom
argument_list|(
name|__headroom
argument_list|)
operator|,
name|_M_force_new
argument_list|(
argument|__force
argument_list|)
block|{ }
block|}
struct|;
struct|struct
name|_Block_address
block|{
name|void
modifier|*
name|_M_initial
decl_stmt|;
name|_Block_address
modifier|*
name|_M_next
decl_stmt|;
block|}
struct|;
specifier|const
name|_Tune
operator|&
name|_M_get_options
argument_list|()
specifier|const
block|{
return|return
name|_M_options
return|;
block|}
name|void
name|_M_set_options
parameter_list|(
name|_Tune
name|__t
parameter_list|)
block|{
if|if
condition|(
operator|!
name|_M_init
condition|)
name|_M_options
operator|=
name|__t
expr_stmt|;
block|}
name|bool
name|_M_check_threshold
parameter_list|(
name|size_t
name|__bytes
parameter_list|)
block|{
return|return
name|__bytes
operator|>
name|_M_options
operator|.
name|_M_max_bytes
operator|||
name|_M_options
operator|.
name|_M_force_new
return|;
block|}
name|size_t
name|_M_get_binmap
parameter_list|(
name|size_t
name|__bytes
parameter_list|)
block|{
return|return
name|_M_binmap
index|[
name|__bytes
index|]
return|;
block|}
specifier|const
name|size_t
name|_M_get_align
parameter_list|()
block|{
return|return
name|_M_options
operator|.
name|_M_align
return|;
block|}
name|explicit
name|__pool_base
argument_list|()
operator|:
name|_M_options
argument_list|(
name|_Tune
argument_list|()
argument_list|)
operator|,
name|_M_binmap
argument_list|(
name|NULL
argument_list|)
operator|,
name|_M_init
argument_list|(
argument|false
argument_list|)
block|{ }
name|explicit
name|__pool_base
argument_list|(
specifier|const
name|_Tune
operator|&
name|__options
argument_list|)
operator|:
name|_M_options
argument_list|(
name|__options
argument_list|)
operator|,
name|_M_binmap
argument_list|(
name|NULL
argument_list|)
operator|,
name|_M_init
argument_list|(
argument|false
argument_list|)
block|{ }
name|private
operator|:
name|explicit
name|__pool_base
argument_list|(
specifier|const
name|__pool_base
operator|&
argument_list|)
expr_stmt|;
name|__pool_base
modifier|&
name|operator
init|=
operator|(
specifier|const
name|__pool_base
operator|&
operator|)
decl_stmt|;
name|protected
label|:
comment|// Configuration options.
name|_Tune
name|_M_options
decl_stmt|;
name|_Binmap_type
modifier|*
name|_M_binmap
decl_stmt|;
comment|// Configuration of the pool object via _M_options can happen
comment|// after construction but before initialization. After
comment|// initialization is complete, this variable is set to true.
name|bool
name|_M_init
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**    *  @brief  Data describing the underlying memory pool, parameterized on    *  threading support.    */
end_comment

begin_expr_stmt
name|template
operator|<
name|bool
name|_Thread
operator|>
name|class
name|__pool
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Specialization for single thread.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|__pool
operator|<
name|false
operator|>
operator|:
name|public
name|__pool_base
block|{
name|public
operator|:
expr|union
name|_Block_record
block|{
comment|// Points to the block_record of the next free block.
name|_Block_record
operator|*
name|_M_next
block|;       }
block|;        struct
name|_Bin_record
block|{
comment|// An "array" of pointers to the first free block.
name|_Block_record
operator|*
operator|*
name|_M_first
block|;
comment|// A list of the initial addresses of all allocated blocks.
name|_Block_address
operator|*
name|_M_address
block|;       }
block|;
name|void
name|_M_initialize_once
argument_list|()
block|{
if|if
condition|(
name|__builtin_expect
argument_list|(
name|_M_init
operator|==
name|false
argument_list|,
name|false
argument_list|)
condition|)
name|_M_initialize
argument_list|()
expr_stmt|;
block|}
name|void
name|_M_destroy
argument_list|()
name|throw
argument_list|()
expr_stmt|;
end_expr_stmt

begin_function_decl
name|char
modifier|*
name|_M_reserve_block
parameter_list|(
name|size_t
name|__bytes
parameter_list|,
specifier|const
name|size_t
name|__thread_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_M_reclaim_block
parameter_list|(
name|char
modifier|*
name|__p
parameter_list|,
name|size_t
name|__bytes
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|size_t
name|_M_get_thread_id
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|const
name|_Bin_record
modifier|&
name|_M_get_bin
parameter_list|(
name|size_t
name|__which
parameter_list|)
block|{
return|return
name|_M_bin
index|[
name|__which
index|]
return|;
block|}
end_function

begin_function
name|void
name|_M_adjust_freelist
parameter_list|(
specifier|const
name|_Bin_record
modifier|&
parameter_list|,
name|_Block_record
modifier|*
parameter_list|,
name|size_t
parameter_list|)
block|{ }
end_function

begin_macro
name|explicit
end_macro

begin_expr_stmt
name|__pool
argument_list|()
operator|:
name|_M_bin
argument_list|(
name|NULL
argument_list|)
operator|,
name|_M_bin_size
argument_list|(
literal|1
argument_list|)
block|{ }
name|explicit
name|__pool
argument_list|(
specifier|const
name|__pool_base
operator|::
name|_Tune
operator|&
name|__tune
argument_list|)
operator|:
name|__pool_base
argument_list|(
name|__tune
argument_list|)
operator|,
name|_M_bin
argument_list|(
name|NULL
argument_list|)
operator|,
name|_M_bin_size
argument_list|(
literal|1
argument_list|)
block|{ }
name|private
operator|:
comment|// An "array" of bin_records each of which represents a specific
comment|// power of 2 size. Memory to this "array" is allocated in
comment|// _M_initialize().
name|_Bin_record
operator|*
name|_M_bin
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Actual value calculated in _M_initialize().
end_comment

begin_decl_stmt
name|size_t
name|_M_bin_size
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|_M_initialize
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
unit|};
ifdef|#
directive|ifdef
name|__GTHREADS
end_ifdef

begin_comment
comment|/// Specialization for thread enabled, via gthreads.h.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|__pool
operator|<
name|true
operator|>
operator|:
name|public
name|__pool_base
block|{
name|public
operator|:
comment|// Each requesting thread is assigned an id ranging from 1 to
comment|// _S_max_threads. Thread id 0 is used as a global memory pool.
comment|// In order to get constant performance on the thread assignment
comment|// routine, we keep a list of free ids. When a thread first
comment|// requests memory we remove the first record in this list and
comment|// stores the address in a __gthread_key. When initializing the
comment|// __gthread_key we specify a destructor. When this destructor
comment|// (i.e. the thread dies) is called, we return the thread id to
comment|// the front of this list.
expr|struct
name|_Thread_record
block|{
comment|// Points to next free thread id record. NULL if last record in list.
name|_Thread_record
operator|*
name|_M_next
block|;
comment|// Thread id ranging from 1 to _S_max_threads.
name|size_t
name|_M_id
block|;       }
block|;
expr|union
name|_Block_record
block|{
comment|// Points to the block_record of the next free block.
name|_Block_record
operator|*
name|_M_next
block|;
comment|// The thread id of the thread which has requested this block.
name|size_t
name|_M_thread_id
block|;       }
block|;              struct
name|_Bin_record
block|{
comment|// An "array" of pointers to the first free block for each
comment|// thread id. Memory to this "array" is allocated in
comment|// _S_initialize() for _S_max_threads + global pool 0.
name|_Block_record
operator|*
operator|*
name|_M_first
block|;
comment|// A list of the initial addresses of all allocated blocks.
name|_Block_address
operator|*
name|_M_address
block|;
comment|// An "array" of counters used to keep track of the amount of
comment|// blocks that are on the freelist/used for each thread id.
comment|// - Note that the second part of the allocated _M_used "array"
comment|//   actually hosts (atomic) counters of reclaimed blocks:  in
comment|//   _M_reserve_block and in _M_reclaim_block those numbers are
comment|//   subtracted from the first ones to obtain the actual size
comment|//   of the "working set" of the given thread.
comment|// - Memory to these "arrays" is allocated in _S_initialize()
comment|//   for _S_max_threads + global pool 0.
name|size_t
operator|*
name|_M_free
block|;
name|size_t
operator|*
name|_M_used
block|;
comment|// Each bin has its own mutex which is used to ensure data
comment|// integrity while changing "ownership" on a block.  The mutex
comment|// is initialized in _S_initialize().
name|__gthread_mutex_t
operator|*
name|_M_mutex
block|;       }
block|;
comment|// XXX GLIBCXX_ABI Deprecated
name|void
name|_M_initialize
argument_list|(
name|__destroy_handler
argument_list|)
block|;
name|void
name|_M_initialize_once
argument_list|()
block|{
if|if
condition|(
name|__builtin_expect
argument_list|(
name|_M_init
operator|==
name|false
argument_list|,
name|false
argument_list|)
condition|)
name|_M_initialize
argument_list|()
expr_stmt|;
block|}
name|void
name|_M_destroy
argument_list|()
name|throw
argument_list|()
expr_stmt|;
end_expr_stmt

begin_function_decl
name|char
modifier|*
name|_M_reserve_block
parameter_list|(
name|size_t
name|__bytes
parameter_list|,
specifier|const
name|size_t
name|__thread_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_M_reclaim_block
parameter_list|(
name|char
modifier|*
name|__p
parameter_list|,
name|size_t
name|__bytes
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|const
name|_Bin_record
modifier|&
name|_M_get_bin
parameter_list|(
name|size_t
name|__which
parameter_list|)
block|{
return|return
name|_M_bin
index|[
name|__which
index|]
return|;
block|}
end_function

begin_function
name|void
name|_M_adjust_freelist
parameter_list|(
specifier|const
name|_Bin_record
modifier|&
name|__bin
parameter_list|,
name|_Block_record
modifier|*
name|__block_record
parameter_list|,
name|size_t
name|__thread_id
parameter_list|)
block|{
if|if
condition|(
name|__gthread_active_p
argument_list|()
condition|)
block|{
name|__block_record
operator|->
name|_M_thread_id
operator|=
name|__thread_id
expr_stmt|;
operator|--
name|__bin
operator|.
name|_M_free
index|[
name|__thread_id
index|]
expr_stmt|;
operator|++
name|__bin
operator|.
name|_M_used
index|[
name|__thread_id
index|]
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|// XXX GLIBCXX_ABI Deprecated
end_comment

begin_function_decl
name|void
name|_M_destroy_thread_key
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|_M_get_thread_id
parameter_list|()
function_decl|;
end_function_decl

begin_macro
name|explicit
end_macro

begin_expr_stmt
name|__pool
argument_list|()
operator|:
name|_M_bin
argument_list|(
name|NULL
argument_list|)
operator|,
name|_M_bin_size
argument_list|(
literal|1
argument_list|)
operator|,
name|_M_thread_freelist
argument_list|(
argument|NULL
argument_list|)
block|{ }
name|explicit
name|__pool
argument_list|(
specifier|const
name|__pool_base
operator|::
name|_Tune
operator|&
name|__tune
argument_list|)
operator|:
name|__pool_base
argument_list|(
name|__tune
argument_list|)
operator|,
name|_M_bin
argument_list|(
name|NULL
argument_list|)
operator|,
name|_M_bin_size
argument_list|(
literal|1
argument_list|)
operator|,
name|_M_thread_freelist
argument_list|(
argument|NULL
argument_list|)
block|{ }
name|private
operator|:
comment|// An "array" of bin_records each of which represents a specific
comment|// power of 2 size. Memory to this "array" is allocated in
comment|// _M_initialize().
name|_Bin_record
operator|*
name|_M_bin
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Actual value calculated in _M_initialize().
end_comment

begin_decl_stmt
name|size_t
name|_M_bin_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|_Thread_record
modifier|*
name|_M_thread_freelist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|_M_thread_freelist_initial
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|_M_initialize
parameter_list|()
function_decl|;
end_function_decl

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_expr_stmt
name|template
operator|<
name|template
operator|<
name|bool
operator|>
name|class
name|_PoolTp
operator|,
name|bool
name|_Thread
operator|>
expr|struct
name|__common_pool
block|{
typedef|typedef
name|_PoolTp
operator|<
name|_Thread
operator|>
name|pool_type
expr_stmt|;
specifier|static
name|pool_type
operator|&
name|_S_get_pool
argument_list|()
block|{
specifier|static
name|pool_type
name|_S_pool
block|;
return|return
name|_S_pool
return|;
block|}
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|template
operator|<
name|bool
operator|>
name|class
name|_PoolTp
operator|,
name|bool
name|_Thread
operator|>
expr|struct
name|__common_pool_base
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|template
operator|<
name|bool
operator|>
name|class
name|_PoolTp
operator|>
expr|struct
name|__common_pool_base
operator|<
name|_PoolTp
operator|,
name|false
operator|>
operator|:
name|public
name|__common_pool
operator|<
name|_PoolTp
operator|,
name|false
operator|>
block|{
name|using
name|__common_pool
operator|<
name|_PoolTp
block|,
name|false
operator|>
operator|::
name|_S_get_pool
block|;
specifier|static
name|void
name|_S_initialize_once
argument_list|()
block|{
specifier|static
name|bool
name|__init
block|;
if|if
condition|(
name|__builtin_expect
argument_list|(
name|__init
operator|==
name|false
argument_list|,
name|false
argument_list|)
condition|)
block|{
name|_S_get_pool
argument_list|()
operator|.
name|_M_initialize_once
argument_list|()
expr_stmt|;
name|__init
operator|=
name|true
expr_stmt|;
block|}
block|}
end_expr_stmt

begin_ifdef
unit|};
ifdef|#
directive|ifdef
name|__GTHREADS
end_ifdef

begin_expr_stmt
name|template
operator|<
name|template
operator|<
name|bool
operator|>
name|class
name|_PoolTp
operator|>
expr|struct
name|__common_pool_base
operator|<
name|_PoolTp
operator|,
name|true
operator|>
operator|:
name|public
name|__common_pool
operator|<
name|_PoolTp
operator|,
name|true
operator|>
block|{
name|using
name|__common_pool
operator|<
name|_PoolTp
block|,
name|true
operator|>
operator|::
name|_S_get_pool
block|;
specifier|static
name|void
name|_S_initialize
argument_list|()
block|{
name|_S_get_pool
argument_list|()
operator|.
name|_M_initialize_once
argument_list|()
block|; }
specifier|static
name|void
name|_S_initialize_once
argument_list|()
block|{
specifier|static
name|bool
name|__init
block|;
if|if
condition|(
name|__builtin_expect
argument_list|(
name|__init
operator|==
name|false
argument_list|,
name|false
argument_list|)
condition|)
block|{
if|if
condition|(
name|__gthread_active_p
argument_list|()
condition|)
block|{
comment|// On some platforms, __gthread_once_t is an aggregate.
specifier|static
name|__gthread_once_t
name|__once
init|=
name|__GTHREAD_ONCE_INIT
decl_stmt|;
name|__gthread_once
argument_list|(
operator|&
name|__once
argument_list|,
name|_S_initialize
argument_list|)
expr_stmt|;
block|}
comment|// Double check initialization. May be necessary on some
comment|// systems for proper construction when not compiling with
comment|// thread flags.
name|_S_get_pool
argument_list|()
operator|.
name|_M_initialize_once
argument_list|()
block|;
name|__init
operator|=
name|true
block|; 	  }
end_expr_stmt

begin_empty_stmt
unit|}     }
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// @brief  Policy for shared __pool objects.
end_comment

begin_expr_stmt
name|template
operator|<
name|template
operator|<
name|bool
operator|>
name|class
name|_PoolTp
operator|,
name|bool
name|_Thread
operator|>
expr|struct
name|__common_pool_policy
operator|:
name|public
name|__common_pool_base
operator|<
name|_PoolTp
operator|,
name|_Thread
operator|>
block|{
name|template
operator|<
name|typename
name|_Tp1
block|,
name|template
operator|<
name|bool
operator|>
name|class
name|_PoolTp1
operator|=
name|_PoolTp
block|,
name|bool
name|_Thread1
operator|=
name|_Thread
operator|>
expr|struct
name|_M_rebind
block|{
typedef|typedef
name|__common_pool_policy
operator|<
name|_PoolTp1
operator|,
name|_Thread1
operator|>
name|other
expr_stmt|;
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__common_pool_base
operator|<
name|_PoolTp
operator|,
name|_Thread
operator|>
operator|::
name|_S_get_pool
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__common_pool_base
operator|<
name|_PoolTp
operator|,
name|_Thread
operator|>
operator|::
name|_S_initialize_once
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_Tp
operator|,
name|template
operator|<
name|bool
operator|>
name|class
name|_PoolTp
operator|,
name|bool
name|_Thread
operator|>
expr|struct
name|__per_type_pool
block|{
typedef|typedef
name|_Tp
name|value_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|_PoolTp
operator|<
name|_Thread
operator|>
name|pool_type
expr_stmt|;
end_typedef

begin_function
specifier|static
name|pool_type
modifier|&
name|_S_get_pool
parameter_list|()
block|{
comment|// Sane defaults for the _PoolTp.
typedef|typedef
name|typename
name|pool_type
operator|::
name|_Block_record
name|_Block_record
expr_stmt|;
specifier|const
specifier|static
name|size_t
name|__a
init|=
operator|(
name|__alignof__
argument_list|(
name|_Tp
argument_list|)
operator|>=
sizeof|sizeof
argument_list|(
name|_Block_record
argument_list|)
condition|?
name|__alignof__
argument_list|(
name|_Tp
argument_list|)
else|:
sizeof|sizeof
argument_list|(
name|_Block_record
argument_list|)
operator|)
decl_stmt|;
typedef|typedef
name|typename
name|__pool_base
operator|::
name|_Tune
name|_Tune
expr_stmt|;
specifier|static
name|_Tune
name|_S_tune
argument_list|(
name|__a
argument_list|,
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
operator|*
literal|64
argument_list|,
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
operator|*
literal|2
operator|>=
name|__a
condition|?
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
operator|*
literal|2
else|:
name|__a
argument_list|,
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
operator|*
name|size_t
argument_list|(
name|_Tune
operator|::
name|_S_chunk_size
argument_list|)
argument_list|,
name|_Tune
operator|::
name|_S_max_threads
argument_list|,
name|_Tune
operator|::
name|_S_freelist_headroom
argument_list|,
name|std
operator|::
name|getenv
argument_list|(
literal|"GLIBCXX_FORCE_NEW"
argument_list|)
condition|?
name|true
else|:
name|false
argument_list|)
decl_stmt|;
specifier|static
name|pool_type
name|_S_pool
argument_list|(
name|_S_tune
argument_list|)
decl_stmt|;
return|return
name|_S_pool
return|;
block|}
end_function

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_Tp
operator|,
name|template
operator|<
name|bool
operator|>
name|class
name|_PoolTp
operator|,
name|bool
name|_Thread
operator|>
expr|struct
name|__per_type_pool_base
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|,
name|template
operator|<
name|bool
operator|>
name|class
name|_PoolTp
operator|>
expr|struct
name|__per_type_pool_base
operator|<
name|_Tp
operator|,
name|_PoolTp
operator|,
name|false
operator|>
operator|:
name|public
name|__per_type_pool
operator|<
name|_Tp
operator|,
name|_PoolTp
operator|,
name|false
operator|>
block|{
name|using
name|__per_type_pool
operator|<
name|_Tp
block|,
name|_PoolTp
block|,
name|false
operator|>
operator|::
name|_S_get_pool
block|;
specifier|static
name|void
name|_S_initialize_once
argument_list|()
block|{
specifier|static
name|bool
name|__init
block|;
if|if
condition|(
name|__builtin_expect
argument_list|(
name|__init
operator|==
name|false
argument_list|,
name|false
argument_list|)
condition|)
block|{
name|_S_get_pool
argument_list|()
operator|.
name|_M_initialize_once
argument_list|()
expr_stmt|;
name|__init
operator|=
name|true
expr_stmt|;
block|}
block|}
end_expr_stmt

begin_ifdef
unit|};
ifdef|#
directive|ifdef
name|__GTHREADS
end_ifdef

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|,
name|template
operator|<
name|bool
operator|>
name|class
name|_PoolTp
operator|>
expr|struct
name|__per_type_pool_base
operator|<
name|_Tp
operator|,
name|_PoolTp
operator|,
name|true
operator|>
operator|:
name|public
name|__per_type_pool
operator|<
name|_Tp
operator|,
name|_PoolTp
operator|,
name|true
operator|>
block|{
name|using
name|__per_type_pool
operator|<
name|_Tp
block|,
name|_PoolTp
block|,
name|true
operator|>
operator|::
name|_S_get_pool
block|;
specifier|static
name|void
name|_S_initialize
argument_list|()
block|{
name|_S_get_pool
argument_list|()
operator|.
name|_M_initialize_once
argument_list|()
block|; }
specifier|static
name|void
name|_S_initialize_once
argument_list|()
block|{
specifier|static
name|bool
name|__init
block|;
if|if
condition|(
name|__builtin_expect
argument_list|(
name|__init
operator|==
name|false
argument_list|,
name|false
argument_list|)
condition|)
block|{
if|if
condition|(
name|__gthread_active_p
argument_list|()
condition|)
block|{
comment|// On some platforms, __gthread_once_t is an aggregate.
specifier|static
name|__gthread_once_t
name|__once
init|=
name|__GTHREAD_ONCE_INIT
decl_stmt|;
name|__gthread_once
argument_list|(
operator|&
name|__once
argument_list|,
name|_S_initialize
argument_list|)
expr_stmt|;
block|}
comment|// Double check initialization. May be necessary on some
comment|// systems for proper construction when not compiling with
comment|// thread flags.
name|_S_get_pool
argument_list|()
operator|.
name|_M_initialize_once
argument_list|()
block|;
name|__init
operator|=
name|true
block|; 	  }
end_expr_stmt

begin_empty_stmt
unit|}     }
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// @brief  Policy for individual __pool objects.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|,
name|template
operator|<
name|bool
operator|>
name|class
name|_PoolTp
operator|,
name|bool
name|_Thread
operator|>
expr|struct
name|__per_type_pool_policy
operator|:
name|public
name|__per_type_pool_base
operator|<
name|_Tp
operator|,
name|_PoolTp
operator|,
name|_Thread
operator|>
block|{
name|template
operator|<
name|typename
name|_Tp1
block|,
name|template
operator|<
name|bool
operator|>
name|class
name|_PoolTp1
operator|=
name|_PoolTp
block|,
name|bool
name|_Thread1
operator|=
name|_Thread
operator|>
expr|struct
name|_M_rebind
block|{
typedef|typedef
name|__per_type_pool_policy
operator|<
name|_Tp1
operator|,
name|_PoolTp1
operator|,
name|_Thread1
operator|>
name|other
expr_stmt|;
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__per_type_pool_base
operator|<
name|_Tp
operator|,
name|_PoolTp
operator|,
name|_Thread
operator|>
operator|::
name|_S_get_pool
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|__per_type_pool_base
operator|<
name|_Tp
operator|,
name|_PoolTp
operator|,
name|_Thread
operator|>
operator|::
name|_S_initialize_once
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// @brief  Base class for _Tp dependent member functions.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|>
name|class
name|__mt_alloc_base
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

begin_decl_stmt
name|pointer
name|address
argument_list|(
name|reference
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

begin_comment
comment|// _GLIBCXX_RESOLVE_LIB_DEFECTS
end_comment

begin_comment
comment|// 402. wrong new expression in [some_] allocator::construct
end_comment

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
end_function

begin_function
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
end_function

begin_ifdef
unit|};
ifdef|#
directive|ifdef
name|__GTHREADS
end_ifdef

begin_define
define|#
directive|define
name|__thread_default
value|true
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__thread_default
value|false
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**    *  @brief  This is a fixed size (power of 2) allocator which - when    *  compiled with thread support - will maintain one freelist per    *  size per thread plus a "global" one. Steps are taken to limit    *  the per thread freelist sizes (by returning excess back to    *  the "global" list).    *    *  Further details:    *  http://gcc.gnu.org/onlinedocs/libstdc++/ext/mt_allocator.html    */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|,
name|typename
name|_Poolp
operator|=
name|__common_pool_policy
operator|<
name|__pool
operator|,
name|__thread_default
operator|>
expr|>
name|class
name|__mt_alloc
operator|:
name|public
name|__mt_alloc_base
operator|<
name|_Tp
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

begin_typedef
typedef|typedef
name|_Poolp
name|__policy_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|_Poolp
operator|::
name|pool_type
name|__pool_type
expr_stmt|;
end_typedef

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp1
operator|,
name|typename
name|_Poolp1
operator|=
name|_Poolp
operator|>
expr|struct
name|rebind
block|{
typedef|typedef
name|typename
name|_Poolp1
operator|::
name|template
name|_M_rebind
operator|<
name|_Tp1
operator|>
operator|::
name|other
name|pol_type
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__mt_alloc
operator|<
name|_Tp1
operator|,
name|pol_type
operator|>
name|other
expr_stmt|;
end_typedef

begin_macro
unit|};
name|__mt_alloc
argument_list|()
end_macro

begin_macro
name|throw
argument_list|()
end_macro

begin_block
block|{ }
end_block

begin_macro
name|__mt_alloc
argument_list|(
argument|const __mt_alloc&
argument_list|)
end_macro

begin_macro
name|throw
argument_list|()
end_macro

begin_block
block|{ }
end_block

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp1
operator|,
name|typename
name|_Poolp1
operator|>
name|__mt_alloc
argument_list|(
argument|const __mt_alloc<_Tp1
argument_list|,
argument|_Poolp1>&
argument_list|)
name|throw
argument_list|()
block|{ }
operator|~
name|__mt_alloc
argument_list|()
name|throw
argument_list|()
block|{ }
name|pointer
name|allocate
argument_list|(
argument|size_type __n
argument_list|,
argument|const void* =
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
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
end_function_decl

begin_expr_stmt
specifier|const
name|__pool_base
operator|::
name|_Tune
name|_M_get_options
argument_list|()
block|{
comment|// Return a copy, not a reference, for external consumption.
return|return
name|__policy_type
operator|::
name|_S_get_pool
argument_list|()
operator|.
name|_M_get_options
argument_list|()
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|_M_set_options
argument_list|(
name|__pool_base
operator|::
name|_Tune
name|__t
argument_list|)
block|{
name|__policy_type
operator|::
name|_S_get_pool
argument_list|()
operator|.
name|_M_set_options
argument_list|(
name|__t
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|_Tp
operator|,
name|typename
name|_Poolp
operator|>
name|typename
name|__mt_alloc
operator|<
name|_Tp
operator|,
name|_Poolp
operator|>
operator|::
name|pointer
name|__mt_alloc
operator|<
name|_Tp
operator|,
name|_Poolp
operator|>
operator|::
name|allocate
argument_list|(
argument|size_type __n
argument_list|,
argument|const void*
argument_list|)
block|{
if|if
condition|(
name|__builtin_expect
argument_list|(
name|__n
operator|>
name|this
operator|->
name|max_size
argument_list|()
argument_list|,
name|false
argument_list|)
condition|)
name|std
operator|::
name|__throw_bad_alloc
argument_list|()
expr_stmt|;
name|__policy_type
operator|::
name|_S_initialize_once
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Requests larger than _M_max_bytes are handled by operator
end_comment

begin_comment
comment|// new/delete directly.
end_comment

begin_decl_stmt
name|__pool_type
modifier|&
name|__pool
init|=
name|__policy_type
operator|::
name|_S_get_pool
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
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
end_decl_stmt

begin_if
if|if
condition|(
name|__pool
operator|.
name|_M_check_threshold
argument_list|(
name|__bytes
argument_list|)
condition|)
block|{
name|void
modifier|*
name|__ret
init|=
operator|::
name|operator
name|new
argument_list|(
name|__bytes
argument_list|)
decl_stmt|;
return|return
name|static_cast
operator|<
name|_Tp
operator|*
operator|>
operator|(
name|__ret
operator|)
return|;
block|}
end_if

begin_comment
comment|// Round up to power of 2 and figure out which bin to use.
end_comment

begin_decl_stmt
specifier|const
name|size_t
name|__which
init|=
name|__pool
operator|.
name|_M_get_binmap
argument_list|(
name|__bytes
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|size_t
name|__thread_id
init|=
name|__pool
operator|.
name|_M_get_thread_id
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Find out if we have blocks on our freelist.  If so, go ahead
end_comment

begin_comment
comment|// and use them directly without having to lock anything.
end_comment

begin_decl_stmt
name|char
modifier|*
name|__c
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|typename
name|__pool_type
operator|::
name|_Bin_record
name|_Bin_record
expr_stmt|;
end_typedef

begin_decl_stmt
specifier|const
name|_Bin_record
modifier|&
name|__bin
init|=
name|__pool
operator|.
name|_M_get_bin
argument_list|(
name|__which
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|if
condition|(
name|__bin
operator|.
name|_M_first
index|[
name|__thread_id
index|]
condition|)
block|{
comment|// Already reserved.
typedef|typedef
name|typename
name|__pool_type
operator|::
name|_Block_record
name|_Block_record
expr_stmt|;
name|_Block_record
modifier|*
name|__block_record
init|=
name|__bin
operator|.
name|_M_first
index|[
name|__thread_id
index|]
decl_stmt|;
name|__bin
operator|.
name|_M_first
index|[
name|__thread_id
index|]
operator|=
name|__block_record
operator|->
name|_M_next
expr_stmt|;
name|__pool
operator|.
name|_M_adjust_freelist
argument_list|(
name|__bin
argument_list|,
name|__block_record
argument_list|,
name|__thread_id
argument_list|)
expr_stmt|;
name|__c
operator|=
name|reinterpret_cast
operator|<
name|char
operator|*
operator|>
operator|(
name|__block_record
operator|)
operator|+
name|__pool
operator|.
name|_M_get_align
argument_list|()
expr_stmt|;
block|}
else|else
block|{
comment|// Null, reserve.
name|__c
operator|=
name|__pool
operator|.
name|_M_reserve_block
argument_list|(
name|__bytes
argument_list|,
name|__thread_id
argument_list|)
expr_stmt|;
block|}
end_if

begin_return
return|return
name|static_cast
operator|<
name|_Tp
operator|*
operator|>
operator|(
name|static_cast
operator|<
name|void
operator|*
operator|>
operator|(
name|__c
operator|)
operator|)
return|;
end_return

begin_expr_stmt
unit|}      template
operator|<
name|typename
name|_Tp
operator|,
name|typename
name|_Poolp
operator|>
name|void
name|__mt_alloc
operator|<
name|_Tp
operator|,
name|_Poolp
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
name|__builtin_expect
argument_list|(
name|__p
operator|!=
literal|0
argument_list|,
name|true
argument_list|)
condition|)
block|{
comment|// Requests larger than _M_max_bytes are handled by
comment|// operators new/delete directly.
name|__pool_type
modifier|&
name|__pool
init|=
name|__policy_type
operator|::
name|_S_get_pool
argument_list|()
decl_stmt|;
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
name|__pool
operator|.
name|_M_check_threshold
argument_list|(
name|__bytes
argument_list|)
condition|)
operator|::
name|operator
name|delete
argument_list|(
name|__p
argument_list|)
expr_stmt|;
else|else
name|__pool
operator|.
name|_M_reclaim_block
argument_list|(
name|reinterpret_cast
operator|<
name|char
operator|*
operator|>
operator|(
name|__p
operator|)
argument_list|,
name|__bytes
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
unit|}      template
operator|<
name|typename
name|_Tp
operator|,
name|typename
name|_Poolp
operator|>
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|__mt_alloc
operator|<
name|_Tp
operator|,
name|_Poolp
operator|>
operator|&
operator|,
specifier|const
name|__mt_alloc
operator|<
name|_Tp
operator|,
name|_Poolp
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
operator|,
name|typename
name|_Poolp
operator|>
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|__mt_alloc
operator|<
name|_Tp
operator|,
name|_Poolp
operator|>
operator|&
operator|,
specifier|const
name|__mt_alloc
operator|<
name|_Tp
operator|,
name|_Poolp
operator|>
operator|&
operator|)
block|{
return|return
name|false
return|;
block|}
end_expr_stmt

begin_undef
undef|#
directive|undef
name|__thread_default
end_undef

begin_macro
name|_GLIBCXX_END_NAMESPACE
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

