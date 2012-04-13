begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2001 Wolfram Gloger Copyright (c) 2006 Cavium networks  Permission to use, copy, modify, distribute, and sell this software and its documentation for any purpose is hereby granted without fee, provided that (i) the above copyright notices and this permission notice appear in all copies of the software and related documentation, and (ii) the name of Wolfram Gloger may not be used in any advertising or publicity relating to the software.  THE SOFTWARE IS PROVIDED "AS-IS" AND WITHOUT WARRANTY OF ANY KIND, EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.  IN NO EVENT SHALL WOLFRAM GLOGER BE LIABLE FOR ANY SPECIAL, INCIDENTAL, INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY KIND, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER OR NOT ADVISED OF THE POSSIBILITY OF DAMAGE, AND ON ANY THEORY OF LIABILITY, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. */
end_comment

begin_comment
comment|/* $Id: arena.c 30481 2007-12-05 21:46:59Z rfranz $ */
end_comment

begin_comment
comment|/* Compile-time constants.  */
end_comment

begin_define
define|#
directive|define
name|HEAP_MIN_SIZE
value|(4096)
end_define

begin_comment
comment|/* Must leave room for struct malloc_state, arena ptrs, etc., totals about 2400 bytes */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|THREAD_STATS
end_ifndef

begin_define
define|#
directive|define
name|THREAD_STATS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If THREAD_STATS is non-zero, some statistics on mutex locking are    computed.  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|// made static to avoid conflicts with newlib
end_comment

begin_decl_stmt
specifier|static
name|mstate
name|_int_new_arena
name|__MALLOC_P
argument_list|(
operator|(
name|size_t
name|__ini_size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|top
parameter_list|(
name|ar_ptr
parameter_list|)
value|((ar_ptr)->top)
end_define

begin_comment
comment|/* A heap is a single contiguous memory region holding (coalesceable)    malloc_chunks.    Not used unless compiling with    USE_ARENAS. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_heap_info
block|{
name|mstate
name|ar_ptr
decl_stmt|;
comment|/* Arena for this heap. */
name|struct
name|_heap_info
modifier|*
name|prev
decl_stmt|;
comment|/* Previous heap. */
name|size_t
name|size
decl_stmt|;
comment|/* Current size in bytes. */
name|size_t
name|pad
decl_stmt|;
comment|/* Make sure the following data is properly aligned. */
block|}
name|heap_info
typedef|;
end_typedef

begin_comment
comment|/* Thread specific data */
end_comment

begin_decl_stmt
specifier|static
name|tsd_key_t
name|arena_key
decl_stmt|;
end_decl_stmt

begin_comment
comment|// one per PP (thread)
end_comment

begin_decl_stmt
specifier|static
name|CVMX_SHARED
name|mutex_t
name|list_lock
decl_stmt|;
end_decl_stmt

begin_comment
comment|// shared...
end_comment

begin_if
if|#
directive|if
name|THREAD_STATS
end_if

begin_decl_stmt
specifier|static
name|int
name|stat_n_heaps
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|THREAD_STAT
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|THREAD_STAT
parameter_list|(
name|x
parameter_list|)
value|do ; while(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Mapped memory in non-main arenas (reliable only for NO_THREADS). */
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|long
name|arena_mem
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Already initialized? */
end_comment

begin_decl_stmt
name|int
name|CVMX_SHARED
name|cvmx__malloc_initialized
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**************************************************************************/
end_comment

begin_if
if|#
directive|if
name|USE_ARENAS
end_if

begin_comment
comment|/* find the heap and corresponding arena for a given ptr */
end_comment

begin_define
define|#
directive|define
name|arena_for_chunk
parameter_list|(
name|ptr
parameter_list|)
value|((ptr)->arena_ptr)
end_define

begin_define
define|#
directive|define
name|set_arena_for_chunk
parameter_list|(
name|ptr
parameter_list|,
name|arena
parameter_list|)
value|(ptr)->arena_ptr = (arena)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_ARENAS */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_THREADS
end_ifndef

begin_comment
comment|/* atfork support.  */
end_comment

begin_expr_stmt
specifier|static
name|__malloc_ptr_t
argument_list|(
argument|*save_malloc_hook
argument_list|)
name|__MALLOC_P
argument_list|(
operator|(
name|size_t
name|__size
operator|,
name|__const
name|__malloc_ptr_t
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|static
name|void
argument_list|(
argument|*save_free_hook
argument_list|)
name|__MALLOC_P
argument_list|(
operator|(
name|__malloc_ptr_t
name|__ptr
operator|,
name|__const
name|__malloc_ptr_t
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|Void_t
modifier|*
name|save_arena
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Magic value for the thread-specific arena pointer when    malloc_atfork() is in use.  */
end_comment

begin_define
define|#
directive|define
name|ATFORK_ARENA_PTR
value|((Void_t*)-1)
end_define

begin_comment
comment|/* The following hooks are used while the `atfork' handling mechanism    is active. */
end_comment

begin_function
specifier|static
name|Void_t
modifier|*
name|malloc_atfork
parameter_list|(
name|size_t
name|sz
parameter_list|,
specifier|const
name|Void_t
modifier|*
name|caller
parameter_list|)
block|{
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|free_atfork
parameter_list|(
name|Void_t
modifier|*
name|mem
parameter_list|,
specifier|const
name|Void_t
modifier|*
name|caller
parameter_list|)
block|{
name|Void_t
modifier|*
name|vptr
init|=
name|NULL
decl_stmt|;
name|mstate
name|ar_ptr
decl_stmt|;
name|mchunkptr
name|p
decl_stmt|;
comment|/* chunk corresponding to mem */
if|if
condition|(
name|mem
operator|==
literal|0
condition|)
comment|/* free(0) has no effect */
return|return;
name|p
operator|=
name|mem2chunk
argument_list|(
name|mem
argument_list|)
expr_stmt|;
comment|/* do not bother to replicate free_check here */
if|#
directive|if
name|HAVE_MMAP
if|if
condition|(
name|chunk_is_mmapped
argument_list|(
name|p
argument_list|)
condition|)
comment|/* release mmapped memory. */
block|{
name|munmap_chunk
argument_list|(
name|p
argument_list|)
expr_stmt|;
return|return;
block|}
endif|#
directive|endif
name|ar_ptr
operator|=
name|arena_for_chunk
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|tsd_getspecific
argument_list|(
name|arena_key
argument_list|,
name|vptr
argument_list|)
expr_stmt|;
if|if
condition|(
name|vptr
operator|!=
name|ATFORK_ARENA_PTR
condition|)
operator|(
name|void
operator|)
name|mutex_lock
argument_list|(
operator|&
name|ar_ptr
operator|->
name|mutex
argument_list|)
expr_stmt|;
name|_int_free
argument_list|(
name|ar_ptr
argument_list|,
name|mem
argument_list|)
expr_stmt|;
if|if
condition|(
name|vptr
operator|!=
name|ATFORK_ARENA_PTR
condition|)
operator|(
name|void
operator|)
name|mutex_unlock
argument_list|(
operator|&
name|ar_ptr
operator|->
name|mutex
argument_list|)
expr_stmt|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__linux__
end_ifdef

begin_error
error|#
directive|error
error|__linux__defined!
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined NO_THREADS */
end_comment

begin_comment
comment|/* Initialization routine. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_LIBC
end_ifdef

begin_error
error|#
directive|error
error|_LIBC is defined, and should not be
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LIBC */
end_comment

begin_decl_stmt
specifier|static
name|CVMX_SHARED
name|cvmx_spinlock_t
name|malloc_init_spin_lock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Managing heaps and arenas (for concurrent threads) */
end_comment

begin_if
if|#
directive|if
name|USE_ARENAS
end_if

begin_if
if|#
directive|if
name|MALLOC_DEBUG
operator|>
literal|1
end_if

begin_comment
comment|/* Print the complete contents of a single heap to stderr. */
end_comment

begin_function
specifier|static
name|void
if|#
directive|if
name|__STD_C
name|dump_heap
parameter_list|(
name|heap_info
modifier|*
name|heap
parameter_list|)
else|#
directive|else
function|dump_heap
parameter_list|(
name|heap
parameter_list|)
name|heap_info
modifier|*
name|heap
decl_stmt|;
endif|#
directive|endif
block|{
name|char
modifier|*
name|ptr
decl_stmt|;
name|mchunkptr
name|p
decl_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Heap %p, size %10lx:\n"
argument_list|,
name|heap
argument_list|,
operator|(
name|long
operator|)
name|heap
operator|->
name|size
argument_list|)
expr_stmt|;
name|ptr
operator|=
operator|(
name|heap
operator|->
name|ar_ptr
operator|!=
call|(
name|mstate
call|)
argument_list|(
name|heap
operator|+
literal|1
argument_list|)
operator|)
condition|?
operator|(
name|char
operator|*
operator|)
operator|(
name|heap
operator|+
literal|1
operator|)
else|:
operator|(
name|char
operator|*
operator|)
operator|(
name|heap
operator|+
literal|1
operator|)
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|malloc_state
argument_list|)
expr_stmt|;
name|p
operator|=
call|(
name|mchunkptr
call|)
argument_list|(
operator|(
operator|(
name|unsigned
name|long
operator|)
name|ptr
operator|+
name|MALLOC_ALIGN_MASK
operator|)
operator|&
operator|~
name|MALLOC_ALIGN_MASK
argument_list|)
expr_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"chunk %p size %10lx"
argument_list|,
name|p
argument_list|,
operator|(
name|long
operator|)
name|p
operator|->
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|==
name|top
argument_list|(
name|heap
operator|->
name|ar_ptr
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|" (top)\n"
argument_list|)
expr_stmt|;
break|break;
block|}
elseif|else
if|if
condition|(
name|p
operator|->
name|size
operator|==
operator|(
literal|0
operator||
name|PREV_INUSE
operator|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|" (fence)\n"
argument_list|)
expr_stmt|;
break|break;
block|}
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
name|p
operator|=
name|next_chunk
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MALLOC_DEBUG> 1 */
end_comment

begin_comment
comment|/* Delete a heap. */
end_comment

begin_function
specifier|static
name|mstate
name|cvmx_new_arena
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|)
block|{
name|mstate
name|a
decl_stmt|;
name|heap_info
modifier|*
name|h
decl_stmt|;
name|char
modifier|*
name|ptr
decl_stmt|;
name|unsigned
name|long
name|misalign
decl_stmt|;
name|int
name|page_mask
init|=
name|malloc_getpagesize
operator|-
literal|1
decl_stmt|;
name|debug_printf
argument_list|(
literal|"cvmx_new_arena called, addr: %p, size %ld\n"
argument_list|,
name|addr
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|debug_printf
argument_list|(
literal|"heapinfo size: %ld, mstate size: %d\n"
argument_list|,
sizeof|sizeof
argument_list|(
name|heap_info
argument_list|)
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|malloc_state
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|addr
operator|||
operator|(
name|size
operator|<
name|HEAP_MIN_SIZE
operator|)
condition|)
block|{
return|return
operator|(
name|NULL
operator|)
return|;
block|}
comment|/* We must zero out the arena as the malloc code assumes this. */
name|memset
argument_list|(
name|addr
argument_list|,
literal|0
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|h
operator|=
operator|(
name|heap_info
operator|*
operator|)
name|addr
expr_stmt|;
name|h
operator|->
name|size
operator|=
name|size
expr_stmt|;
name|a
operator|=
name|h
operator|->
name|ar_ptr
operator|=
call|(
name|mstate
call|)
argument_list|(
name|h
operator|+
literal|1
argument_list|)
expr_stmt|;
name|malloc_init_state
argument_list|(
name|a
argument_list|)
expr_stmt|;
comment|/*a->next = NULL;*/
name|a
operator|->
name|system_mem
operator|=
name|a
operator|->
name|max_system_mem
operator|=
name|h
operator|->
name|size
expr_stmt|;
name|arena_mem
operator|+=
name|h
operator|->
name|size
expr_stmt|;
name|a
operator|->
name|next
operator|=
name|a
expr_stmt|;
comment|/* Set up the top chunk, with proper alignment. */
name|ptr
operator|=
operator|(
name|char
operator|*
operator|)
operator|(
name|a
operator|+
literal|1
operator|)
expr_stmt|;
name|misalign
operator|=
operator|(
name|unsigned
name|long
operator|)
name|chunk2mem
argument_list|(
name|ptr
argument_list|)
operator|&
name|MALLOC_ALIGN_MASK
expr_stmt|;
if|if
condition|(
name|misalign
operator|>
literal|0
condition|)
name|ptr
operator|+=
name|MALLOC_ALIGNMENT
operator|-
name|misalign
expr_stmt|;
name|top
argument_list|(
name|a
argument_list|)
operator|=
operator|(
name|mchunkptr
operator|)
name|ptr
expr_stmt|;
name|set_head
argument_list|(
name|top
argument_list|(
name|a
argument_list|)
argument_list|,
operator|(
operator|(
operator|(
name|char
operator|*
operator|)
name|h
operator|+
name|h
operator|->
name|size
operator|)
operator|-
name|ptr
operator|)
operator||
name|PREV_INUSE
argument_list|)
expr_stmt|;
return|return
name|a
return|;
block|}
end_function

begin_function
name|int
name|cvmx_add_arena
parameter_list|(
name|cvmx_arena_list_t
modifier|*
name|arena_list
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|size
parameter_list|)
block|{
name|mstate
name|a
decl_stmt|;
comment|/* Enforce required alignement, and adjust size */
name|int
name|misaligned
init|=
operator|(
operator|(
name|size_t
operator|)
name|ptr
operator|)
operator|&
operator|(
name|MALLOC_ALIGNMENT
operator|-
literal|1
operator|)
decl_stmt|;
if|if
condition|(
name|misaligned
condition|)
block|{
name|ptr
operator|=
operator|(
name|char
operator|*
operator|)
name|ptr
operator|+
name|MALLOC_ALIGNMENT
operator|-
name|misaligned
expr_stmt|;
name|size
operator|-=
name|MALLOC_ALIGNMENT
operator|-
name|misaligned
expr_stmt|;
block|}
name|debug_printf
argument_list|(
literal|"Adding arena at addr: %p, size %d\n"
argument_list|,
name|ptr
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|a
operator|=
name|cvmx_new_arena
argument_list|(
name|ptr
argument_list|,
name|size
argument_list|)
expr_stmt|;
comment|/* checks ptr and size */
if|if
condition|(
operator|!
name|a
condition|)
block|{
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|debug_printf
argument_list|(
literal|"cmvx_add_arena - arena_list: %p, *arena_list: %p\n"
argument_list|,
name|arena_list
argument_list|,
operator|*
name|arena_list
argument_list|)
expr_stmt|;
name|debug_printf
argument_list|(
literal|"cmvx_add_arena - list: %p, new: %p\n"
argument_list|,
operator|*
name|arena_list
argument_list|,
name|a
argument_list|)
expr_stmt|;
name|mutex_init
argument_list|(
operator|&
name|a
operator|->
name|mutex
argument_list|)
expr_stmt|;
name|mutex_lock
argument_list|(
operator|&
name|a
operator|->
name|mutex
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|arena_list
condition|)
block|{
name|mstate
name|ar_ptr
init|=
operator|*
name|arena_list
decl_stmt|;
operator|(
name|void
operator|)
name|mutex_lock
argument_list|(
operator|&
name|ar_ptr
operator|->
name|mutex
argument_list|)
expr_stmt|;
name|a
operator|->
name|next
operator|=
name|ar_ptr
operator|->
name|next
expr_stmt|;
comment|// lock held on a and ar_ptr
name|ar_ptr
operator|->
name|next
operator|=
name|a
expr_stmt|;
operator|(
name|void
operator|)
name|mutex_unlock
argument_list|(
operator|&
name|ar_ptr
operator|->
name|mutex
argument_list|)
expr_stmt|;
block|}
else|else
block|{
operator|*
name|arena_list
operator|=
name|a
expr_stmt|;
comment|//      a->next = a;
block|}
name|debug_printf
argument_list|(
literal|"cvmx_add_arena - list: %p, list->next: %p\n"
argument_list|,
operator|*
name|arena_list
argument_list|,
operator|(
operator|(
name|mstate
operator|)
operator|*
name|arena_list
operator|)
operator|->
name|next
argument_list|)
expr_stmt|;
comment|// unlock, since it is not going to be used immediately
operator|(
name|void
operator|)
name|mutex_unlock
argument_list|(
operator|&
name|a
operator|->
name|mutex
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_ARENAS */
end_comment

end_unit

