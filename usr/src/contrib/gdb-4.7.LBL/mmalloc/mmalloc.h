begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Declarations for `mmalloc' and friends.    Copyright 1990, 1991, 1992 Free Software Foundation     Written May 1989 by Mike Haertel.    Heavily modified Mar 1992 by Fred Fish. (fnf@cygnus.com)  The GNU C Library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  The GNU C Library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with the GNU C Library; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.     The author may be reached (Email) at the address mike@ai.mit.edu,    or (US mail) as Mike Haertel c/o Free Software Foundation. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MMALLOC_H
end_ifndef

begin_define
define|#
directive|define
name|__MMALLOC_H
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_define
define|#
directive|define
name|PTR
value|void *
end_define

begin_define
define|#
directive|define
name|CONST
value|const
end_define

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|paramlist
parameter_list|)
value|paramlist
end_define

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|(void *) 0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PTR
value|char *
end_define

begin_define
define|#
directive|define
name|CONST
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|paramlist
parameter_list|)
value|()
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|size_t
end_ifndef

begin_define
define|#
directive|define
name|size_t
value|unsigned int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CHAR_BIT
end_ifndef

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

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MIN
end_ifndef

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|((A)< (B) ? (A) : (B))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MMALLOC_MAGIC
value|"mmalloc"
end_define

begin_comment
comment|/* Mapped file magic number */
end_comment

begin_define
define|#
directive|define
name|MMALLOC_MAGIC_SIZE
value|8
end_define

begin_comment
comment|/* Size of magic number buf */
end_comment

begin_define
define|#
directive|define
name|MMALLOC_VERSION
value|1
end_define

begin_comment
comment|/* Current mmalloc version */
end_comment

begin_define
define|#
directive|define
name|MMALLOC_KEYS
value|16
end_define

begin_comment
comment|/* Keys for application use */
end_comment

begin_comment
comment|/* The allocator divides the heap into blocks of fixed size; large    requests receive one or more whole blocks, and small requests    receive a fragment of a block.  Fragment sizes are powers of two,    and all fragments of a block are the same size.  When all the    fragments in a block have been freed, the block itself is freed.  */
end_comment

begin_define
define|#
directive|define
name|INT_BIT
value|(CHAR_BIT * sizeof(int))
end_define

begin_define
define|#
directive|define
name|BLOCKLOG
value|(INT_BIT> 16 ? 12 : 9)
end_define

begin_define
define|#
directive|define
name|BLOCKSIZE
value|((unsigned int) 1<< BLOCKLOG)
end_define

begin_define
define|#
directive|define
name|BLOCKIFY
parameter_list|(
name|SIZE
parameter_list|)
value|(((SIZE) + BLOCKSIZE - 1) / BLOCKSIZE)
end_define

begin_comment
comment|/* The difference between two pointers is a signed int.  On machines where    the data addresses have the high bit set, we need to ensure that the    difference becomes an unsigned int when we are using the address as an    integral value.  In addition, when using with the '%' operator, the    sign of the result is machine dependent for negative values, so force    it to be treated as an unsigned int. */
end_comment

begin_define
define|#
directive|define
name|ADDR2UINT
parameter_list|(
name|addr
parameter_list|)
value|((unsigned int) ((char *) (addr) - (char *) NULL))
end_define

begin_define
define|#
directive|define
name|RESIDUAL
parameter_list|(
name|addr
parameter_list|,
name|bsize
parameter_list|)
value|((unsigned int) (ADDR2UINT (addr) % (bsize)))
end_define

begin_comment
comment|/* Determine the amount of memory spanned by the initial heap table    (not an absolute limit).  */
end_comment

begin_define
define|#
directive|define
name|HEAP
value|(INT_BIT> 16 ? 4194304 : 65536)
end_define

begin_comment
comment|/* Number of contiguous free blocks allowed to build up at the end of    memory before they will be returned to the system.  */
end_comment

begin_define
define|#
directive|define
name|FINAL_FREE_BLOCKS
value|8
end_define

begin_comment
comment|/* Where to start searching the free list when looking for new memory.    The two possible values are 0 and heapindex.  Starting at 0 seems    to reduce total memory usage, while starting at heapindex seems to    run faster.  */
end_comment

begin_define
define|#
directive|define
name|MALLOC_SEARCH_START
value|mdp -> heapindex
end_define

begin_comment
comment|/* Address to block number and vice versa.  */
end_comment

begin_define
define|#
directive|define
name|BLOCK
parameter_list|(
name|A
parameter_list|)
value|(((char *) (A) - mdp -> heapbase) / BLOCKSIZE + 1)
end_define

begin_define
define|#
directive|define
name|ADDRESS
parameter_list|(
name|B
parameter_list|)
value|((PTR) (((B) - 1) * BLOCKSIZE + mdp -> heapbase))
end_define

begin_comment
comment|/* Data structure giving per-block information.  */
end_comment

begin_typedef
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
comment|/* Heap information for a free block (that may be the first of        a free cluster).  */
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
end_typedef

begin_comment
comment|/* List of blocks allocated with `mmemalign' (or `mvalloc').  */
end_comment

begin_struct
struct|struct
name|alignlist
block|{
name|struct
name|alignlist
modifier|*
name|next
decl_stmt|;
name|PTR
name|aligned
decl_stmt|;
comment|/* The address that mmemaligned returned.  */
name|PTR
name|exact
decl_stmt|;
comment|/* The address that malloc returned.  */
block|}
struct|;
end_struct

begin_comment
comment|/* Doubly linked lists of free fragments.  */
end_comment

begin_struct
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
end_struct

begin_comment
comment|/* Statistics available to the user.    FIXME:  By design, the internals of the malloc package are no longer    exported to the user via an include file, so access to this data needs    to be via some other mechanism, such as mmstat_<something> where the    return value is the<something> the user is interested in. */
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
comment|/* Internal structure that defines the format of the malloc-descriptor.    This gets written to the base address of the region that mmalloc is    managing, and thus also becomes the file header for the mapped file,    if such a file exists. */
end_comment

begin_struct
struct|struct
name|mdesc
block|{
comment|/* The "magic number" for an mmalloc file. */
name|char
name|magic
index|[
name|MMALLOC_MAGIC_SIZE
index|]
decl_stmt|;
comment|/* The size in bytes of this structure, used as a sanity check when reusing      a previously created mapped file. */
name|unsigned
name|int
name|headersize
decl_stmt|;
comment|/* The version number of the mmalloc package that created this file. */
name|unsigned
name|char
name|version
decl_stmt|;
comment|/* Some flag bits to keep track of various internal things. */
name|unsigned
name|int
name|flags
decl_stmt|;
comment|/* If a system call made by the mmalloc package fails, the errno is      preserved for future examination. */
name|int
name|saved_errno
decl_stmt|;
comment|/* Pointer to the function that is used to get more core, or return core      to the system, for requests using this malloc descriptor.  For memory      mapped regions, this is the mmap() based routine.  There may also be      a single malloc descriptor that points to an sbrk() based routine      for systems without mmap() or for applications that call the mmalloc()      package with a NULL malloc descriptor.       FIXME:  For mapped regions shared by more than one process, this      needs to be maintained on a per-process basis. */
name|PTR
argument_list|(
argument|*morecore
argument_list|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|mdesc
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* Pointer to the function that causes an abort when the memory checking      features are activated.  By default this is set to abort(), but can      be set to another function by the application using mmalloc().       FIXME:  For mapped regions shared by more than one process, this      needs to be maintained on a per-process basis. */
name|void
argument_list|(
argument|*abortfunc
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
comment|/* Debugging hook for free.       FIXME:  For mapped regions shared by more than one process, this      needs to be maintained on a per-process basis. */
name|void
argument_list|(
argument|*mfree_hook
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|PTR
operator|)
argument_list|)
expr_stmt|;
comment|/* Debugging hook for `malloc'.       FIXME:  For mapped regions shared by more than one process, this      needs to be maintained on a per-process basis. */
name|PTR
argument_list|(
argument|*mmalloc_hook
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|size_t
operator|)
argument_list|)
expr_stmt|;
comment|/* Debugging hook for realloc.       FIXME:  For mapped regions shared by more than one process, this      needs to be maintained on a per-process basis. */
name|PTR
argument_list|(
argument|*mrealloc_hook
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|PTR
operator|,
name|size_t
operator|)
argument_list|)
expr_stmt|;
comment|/* Number of info entries.  */
name|size_t
name|heapsize
decl_stmt|;
comment|/* Pointer to first block of the heap (base of the first block).  */
name|char
modifier|*
name|heapbase
decl_stmt|;
comment|/* Current search index for the heap table.  */
comment|/* Search index in the info table.  */
name|size_t
name|heapindex
decl_stmt|;
comment|/* Limit of valid info table indices.  */
name|size_t
name|heaplimit
decl_stmt|;
comment|/* Block information table.      Allocated with malign/__mmalloc_free (not mmalloc/mfree).  */
comment|/* Table indexed by block number giving per-block information.  */
name|malloc_info
modifier|*
name|heapinfo
decl_stmt|;
comment|/* Instrumentation.  */
name|struct
name|mstats
name|heapstats
decl_stmt|;
comment|/* Free list headers for each fragment size.  */
comment|/* Free lists for each fragment size.  */
name|struct
name|list
name|fraghead
index|[
name|BLOCKLOG
index|]
decl_stmt|;
comment|/* List of blocks allocated by memalign.  */
name|struct
name|alignlist
modifier|*
name|aligned_blocks
decl_stmt|;
comment|/* The base address of the memory region for this malloc heap.  This      is the location where the bookkeeping data for mmap and for malloc      begins. */
name|char
modifier|*
name|base
decl_stmt|;
comment|/* The current location in the memory region for this malloc heap which      represents the end of memory in use. */
name|char
modifier|*
name|breakval
decl_stmt|;
comment|/* The end of the current memory region for this malloc heap.  This is      the first location past the end of mapped memory. */
name|char
modifier|*
name|top
decl_stmt|;
comment|/* Open file descriptor for the file to which this malloc heap is mapped.      This will always be a valid file descriptor, since /dev/zero is used      by default if no open file is supplied by the client.  Also note that      it may change each time the region is mapped and unmapped. */
name|int
name|fd
decl_stmt|;
comment|/* An array of keys to data within the mapped region, for use by the      application.  */
name|PTR
name|keys
index|[
name|MMALLOC_KEYS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Bits to look at in the malloc descriptor flags word */
end_comment

begin_define
define|#
directive|define
name|MMALLOC_DEVZERO
value|(1<< 0)
end_define

begin_comment
comment|/* Have mapped to /dev/zero */
end_comment

begin_define
define|#
directive|define
name|MMALLOC_INITIALIZED
value|(1<< 1)
end_define

begin_comment
comment|/* Initialized mmalloc */
end_comment

begin_define
define|#
directive|define
name|MMALLOC_MMCHECK_USED
value|(1<< 2)
end_define

begin_comment
comment|/* mmcheck() called already */
end_comment

begin_comment
comment|/* Allocate SIZE bytes of memory.  */
end_comment

begin_decl_stmt
specifier|extern
name|PTR
name|mmalloc
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Re-allocate the previously allocated block in PTR, making the new block    SIZE bytes long.  */
end_comment

begin_decl_stmt
specifier|extern
name|PTR
name|mrealloc
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|PTR
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Allocate NMEMB elements of SIZE bytes each, all initialized to 0.  */
end_comment

begin_decl_stmt
specifier|extern
name|PTR
name|mcalloc
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|size_t
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Free a block allocated by `mmalloc', `mrealloc' or `mcalloc'.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|mfree
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Allocate SIZE bytes allocated to ALIGNMENT bytes.  */
end_comment

begin_decl_stmt
specifier|extern
name|PTR
name|mmemalign
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|size_t
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Allocate SIZE bytes on a page boundary.  */
end_comment

begin_decl_stmt
specifier|extern
name|PTR
name|mvalloc
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Activate a standard collection of debugging hooks.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mmcheck
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pick up the current statistics. (see FIXME elsewhere) */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|mstats
name|mmstats
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Internal version of `mfree' used in `morecore'. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|__mmalloc_free
name|PARAMS
argument_list|(
operator|(
expr|struct
name|mdesc
operator|*
operator|,
name|PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Hooks for debugging versions.  */
end_comment

begin_extern
extern|extern void (*__mfree_hook
end_extern

begin_expr_stmt
unit|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|PTR
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern PTR (*__mmalloc_hook
end_extern

begin_expr_stmt
unit|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|size_t
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern PTR (*__mrealloc_hook
end_extern

begin_expr_stmt
unit|)
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|PTR
operator|,
name|size_t
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* A default malloc descriptor for the single sbrk() managed region. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|mdesc
modifier|*
name|__mmalloc_default_mdp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Initialize the first use of the default malloc descriptor, which uses    an sbrk() region. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|mdesc
modifier|*
name|__mmalloc_sbrk_init
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Grow or shrink a contiguous mapped region using mmap().    Works much like sbrk() */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_MMAP
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|PTR
name|__mmalloc_mmap_morecore
name|PARAMS
argument_list|(
operator|(
expr|struct
name|mdesc
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Remap a mmalloc region that was previously mapped. */
end_comment

begin_decl_stmt
specifier|extern
name|PTR
name|__mmalloc_remap_core
name|PARAMS
argument_list|(
operator|(
expr|struct
name|mdesc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Macro to convert from a user supplied malloc descriptor to pointer to the    internal malloc descriptor.  If the user supplied descriptor is NULL, then    use the default internal version, initializing it if necessary.  Otherwise    just cast the user supplied version (which is void *) to the proper type    (struct mdesc *). */
end_comment

begin_define
define|#
directive|define
name|MD_TO_MDP
parameter_list|(
name|md
parameter_list|)
define|\
value|((md) == NULL \    ? (__mmalloc_default_mdp == NULL \       ? __mmalloc_sbrk_init () \       : __mmalloc_default_mdp) \    : (struct mdesc *) (md))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MMALLOC_H */
end_comment

end_unit

