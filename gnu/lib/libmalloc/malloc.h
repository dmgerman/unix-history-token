begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Declarations for `malloc' and friends.    Copyright 1990, 1991, 1992, 1993 Free Software Foundation, Inc. 		  Written May 1989 by Mike Haertel.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with this library; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.     The author may be reached (Email) at the address mike@ai.mit.edu,    or (US mail) as Mike Haertel c/o Free Software Foundation.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MALLOC_H
end_ifndef

begin_define
define|#
directive|define
name|_MALLOC_H
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_MALLOC_INTERNAL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_LIBC
argument_list|)
operator|||
name|defined
argument_list|(
name|STDC_HEADERS
argument_list|)
operator|||
name|defined
argument_list|(
name|USG
argument_list|)
end_if

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|memset
end_ifndef

begin_define
define|#
directive|define
name|memset
parameter_list|(
name|s
parameter_list|,
name|zero
parameter_list|,
name|n
parameter_list|)
value|bzero ((s), (n))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|memcpy
end_ifndef

begin_define
define|#
directive|define
name|memcpy
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|bcopy ((s), (d), (n))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|memmove
end_ifndef

begin_define
define|#
directive|define
name|memmove
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|)
value|bcopy ((s), (d), (n))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNU_LIBRARY__
argument_list|)
operator|||
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CHAR_BIT
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MALLOC_INTERNAL.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|&&
name|__STDC__
operator|)
undef|#
directive|undef
name|__GNU_P
define|#
directive|define
name|__GNU_P
parameter_list|(
name|args
parameter_list|)
value|args
undef|#
directive|undef
name|__ptr_t
define|#
directive|define
name|__ptr_t
value|void *
else|#
directive|else
comment|/* Not C++ or ANSI C.  */
undef|#
directive|undef
name|__GNU_P
define|#
directive|define
name|__GNU_P
parameter_list|(
name|args
parameter_list|)
value|()
undef|#
directive|undef
name|const
define|#
directive|define
name|const
undef|#
directive|undef
name|__ptr_t
define|#
directive|define
name|__ptr_t
value|char *
endif|#
directive|endif
comment|/* C++ or ANSI C.  */
ifdef|#
directive|ifdef
name|__STDC__
include|#
directive|include
file|<stddef.h>
else|#
directive|else
undef|#
directive|undef
name|size_t
define|#
directive|define
name|size_t
value|unsigned int
undef|#
directive|undef
name|ptrdiff_t
define|#
directive|define
name|ptrdiff_t
value|int
endif|#
directive|endif
ifndef|#
directive|ifndef
name|NULL
define|#
directive|define
name|NULL
value|0
endif|#
directive|endif
comment|/* Allocate SIZE bytes of memory.  */
specifier|extern
name|__ptr_t
name|malloc
name|__GNU_P
argument_list|(
operator|(
name|size_t
name|__size
operator|)
argument_list|)
decl_stmt|;
comment|/* Re-allocate the previously allocated block    in __ptr_t, making the new block SIZE bytes long.  */
specifier|extern
name|__ptr_t
name|realloc
name|__GNU_P
argument_list|(
operator|(
name|__ptr_t
name|__ptr
operator|,
name|size_t
name|__size
operator|)
argument_list|)
decl_stmt|;
comment|/* Allocate NMEMB elements of SIZE bytes each, all initialized to 0.  */
specifier|extern
name|__ptr_t
name|calloc
name|__GNU_P
argument_list|(
operator|(
name|size_t
name|__nmemb
operator|,
name|size_t
name|__size
operator|)
argument_list|)
decl_stmt|;
comment|/* Free a block allocated by `malloc', `realloc' or `calloc'.  */
specifier|extern
name|void
name|free
name|__GNU_P
argument_list|(
operator|(
name|__ptr_t
name|__ptr
operator|)
argument_list|)
decl_stmt|;
comment|/* Allocate SIZE bytes allocated to ALIGNMENT bytes.  */
specifier|extern
name|__ptr_t
name|memalign
name|__GNU_P
argument_list|(
operator|(
name|size_t
name|__alignment
operator|,
name|size_t
name|__size
operator|)
argument_list|)
decl_stmt|;
comment|/* Allocate SIZE bytes on a page boundary.  */
specifier|extern
name|__ptr_t
name|valloc
name|__GNU_P
argument_list|(
operator|(
name|size_t
name|__size
operator|)
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|_MALLOC_INTERNAL
comment|/* The allocator divides the heap into blocks of fixed size; large    requests receive one or more whole blocks, and small requests    receive a fragment of a block.  Fragment sizes are powers of two,    and all fragments of a block are the same size.  When all the    fragments in a block have been freed, the block itself is freed.  */
define|#
directive|define
name|INT_BIT
value|(CHAR_BIT * sizeof(int))
define|#
directive|define
name|BLOCKLOG
value|(INT_BIT> 16 ? 12 : 9)
define|#
directive|define
name|BLOCKSIZE
value|(1<< BLOCKLOG)
define|#
directive|define
name|BLOCKIFY
parameter_list|(
name|SIZE
parameter_list|)
value|(((SIZE) + BLOCKSIZE - 1) / BLOCKSIZE)
comment|/* Determine the amount of memory spanned by the initial heap table    (not an absolute limit).  */
define|#
directive|define
name|HEAP
value|(INT_BIT> 16 ? 4194304 : 65536)
comment|/* Number of contiguous free blocks allowed to build up at the end of    memory before they will be returned to the system.  */
define|#
directive|define
name|FINAL_FREE_BLOCKS
value|8
comment|/* Data structure giving per-block information.  */
typedef|typedef
union|union
block|{
comment|/* Heap information for a busy block.  */
struct|struct
block|{
comment|/* Zero for a large block, or positive giving the 	   logarithm to the base two of the fragment size.  */
name|int
name|type
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|size_t
name|nfree
decl_stmt|;
comment|/* Free fragments in a fragmented block.  */
name|size_t
name|first
decl_stmt|;
comment|/* First free fragment of the block.  */
block|}
name|frag
struct|;
comment|/* Size (in blocks) of a large cluster.  */
name|size_t
name|size
decl_stmt|;
block|}
name|info
union|;
block|}
name|busy
struct|;
comment|/* Heap information for a free block        (that may be the first of a free cluster).  */
struct|struct
block|{
name|size_t
name|size
decl_stmt|;
comment|/* Size (in blocks) of a free cluster.  */
name|size_t
name|next
decl_stmt|;
comment|/* Index of next free cluster.  */
name|size_t
name|prev
decl_stmt|;
comment|/* Index of previous free cluster.  */
block|}
name|free
struct|;
block|}
name|malloc_info
typedef|;
comment|/* Pointer to first block of the heap.  */
specifier|extern
name|char
modifier|*
name|_heapbase
decl_stmt|;
comment|/* Table indexed by block number giving per-block information.  */
specifier|extern
name|malloc_info
modifier|*
name|_heapinfo
decl_stmt|;
comment|/* Address to block number and vice versa.  */
define|#
directive|define
name|BLOCK
parameter_list|(
name|A
parameter_list|)
value|(((char *) (A) - _heapbase) / BLOCKSIZE + 1)
define|#
directive|define
name|ADDRESS
parameter_list|(
name|B
parameter_list|)
value|((__ptr_t) (((B) - 1) * BLOCKSIZE + _heapbase))
comment|/* Current search index for the heap table.  */
specifier|extern
name|size_t
name|_heapindex
decl_stmt|;
comment|/* Limit of valid info table indices.  */
specifier|extern
name|size_t
name|_heaplimit
decl_stmt|;
comment|/* Doubly linked lists of free fragments.  */
struct|struct
name|list
block|{
name|struct
name|list
modifier|*
name|next
decl_stmt|;
name|struct
name|list
modifier|*
name|prev
decl_stmt|;
block|}
struct|;
comment|/* Free list headers for each fragment size.  */
specifier|extern
name|struct
name|list
name|_fraghead
index|[]
decl_stmt|;
comment|/* List of blocks allocated with `memalign' (or `valloc').  */
struct|struct
name|alignlist
block|{
name|struct
name|alignlist
modifier|*
name|next
decl_stmt|;
name|__ptr_t
name|aligned
decl_stmt|;
comment|/* The address that memaligned returned.  */
name|__ptr_t
name|exact
decl_stmt|;
comment|/* The address that malloc returned.  */
block|}
struct|;
specifier|extern
name|struct
name|alignlist
modifier|*
name|_aligned_blocks
decl_stmt|;
comment|/* Instrumentation.  */
specifier|extern
name|size_t
name|_chunks_used
decl_stmt|;
specifier|extern
name|size_t
name|_bytes_used
decl_stmt|;
specifier|extern
name|size_t
name|_chunks_free
decl_stmt|;
specifier|extern
name|size_t
name|_bytes_free
decl_stmt|;
comment|/* Internal version of `free' used in `morecore' (malloc.c). */
specifier|extern
name|void
name|_free_internal
name|__GNU_P
argument_list|(
operator|(
name|__ptr_t
name|__ptr
operator|)
argument_list|)
decl_stmt|;
endif|#
directive|endif
comment|/* _MALLOC_INTERNAL.  */
comment|/* Underlying allocation function; successive calls should    return contiguous pieces of memory.  */
extern|extern __ptr_t (*__morecore
block|)
name|__GNU_P
argument_list|(
operator|(
name|ptrdiff_t
name|__size
operator|)
argument_list|)
expr_stmt|;
end_extern

begin_comment
comment|/* Default value of `__morecore'.  */
end_comment

begin_decl_stmt
specifier|extern
name|__ptr_t
name|__default_morecore
name|__GNU_P
argument_list|(
operator|(
name|ptrdiff_t
name|__size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If not NULL, this function is called after each time    `__morecore' is called to increase the data size.  */
end_comment

begin_extern
extern|extern void (*__after_morecore_hook
end_extern

begin_expr_stmt
unit|)
name|__GNU_P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Nonzero if `malloc' has been called and done its initialization.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|__malloc_initialized
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Hooks for debugging versions.  */
end_comment

begin_extern
extern|extern void (*__free_hook
end_extern

begin_expr_stmt
unit|)
name|__GNU_P
argument_list|(
operator|(
name|__ptr_t
name|__ptr
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern __ptr_t (*__malloc_hook
end_extern

begin_expr_stmt
unit|)
name|__GNU_P
argument_list|(
operator|(
name|size_t
name|__size
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern __ptr_t (*__realloc_hook
end_extern

begin_expr_stmt
unit|)
name|__GNU_P
argument_list|(
operator|(
name|__ptr_t
name|__ptr
operator|,
name|size_t
name|__size
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Activate a standard collection of debugging hooks.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mcheck
name|__GNU_P
argument_list|(
operator|(
name|void
argument_list|(
argument|*__func
argument_list|)
name|__GNU_P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Activate a standard collection of tracing hooks.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|mtrace
name|__GNU_P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Statistics available to the user.  */
end_comment

begin_struct
struct|struct
name|mstats
block|{
name|size_t
name|bytes_total
decl_stmt|;
comment|/* Total size of the heap. */
name|size_t
name|chunks_used
decl_stmt|;
comment|/* Chunks allocated by the user. */
name|size_t
name|bytes_used
decl_stmt|;
comment|/* Byte total of user-allocated chunks. */
name|size_t
name|chunks_free
decl_stmt|;
comment|/* Chunks in the free list. */
name|size_t
name|bytes_free
decl_stmt|;
comment|/* Byte total of chunks in the free list. */
block|}
struct|;
end_struct

begin_comment
comment|/* Pick up the current statistics. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|mstats
name|mstats
name|__GNU_P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Call WARNFUN with a warning message when memory usage is high.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|memory_warnings
name|__GNU_P
argument_list|(
operator|(
name|__ptr_t
name|__start
operator|,
name|void
argument_list|(
argument|*__warnfun
argument_list|)
name|__GNU_P
argument_list|(
operator|(
name|__const
name|char
operator|*
operator|)
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Relocating allocator.  */
end_comment

begin_comment
comment|/* Allocate SIZE bytes, and store the address in *HANDLEPTR.  */
end_comment

begin_decl_stmt
specifier|extern
name|__ptr_t
name|r_alloc
name|__GNU_P
argument_list|(
operator|(
name|__ptr_t
operator|*
name|__handleptr
operator|,
name|size_t
name|__size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Free the storage allocated in HANDLEPTR.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|r_alloc_free
name|__GNU_P
argument_list|(
operator|(
name|__ptr_t
operator|*
name|__handleptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Adjust the block at HANDLEPTR to be SIZE bytes long.  */
end_comment

begin_decl_stmt
specifier|extern
name|__ptr_t
name|r_re_alloc
name|__GNU_P
argument_list|(
operator|(
name|__ptr_t
operator|*
name|__handleptr
operator|,
name|size_t
name|__size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* malloc.h  */
end_comment

end_unit

