begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2005, 2009, 2013 Jeffrey Roberson<jeff@FreeBSD.org>  * Copyright (c) 2004, 2005 Bosko Milekic<bmilekic@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/*   * This file includes definitions, structures, prototypes, and inlines that  * should not be used outside of the actual implementation of UMA.  */
end_comment

begin_comment
comment|/*   * Here's a quick description of the relationship between the objects:  *  * Kegs contain lists of slabs which are stored in either the full bin, empty  * bin, or partially allocated bin, to reduce fragmentation.  They also contain  * the user supplied value for size, which is adjusted for alignment purposes  * and rsize is the result of that.  The Keg also stores information for  * managing a hash of page addresses that maps pages to uma_slab_t structures  * for pages that don't have embedded uma_slab_t's.  *    * The uma_slab_t may be embedded in a UMA_SLAB_SIZE chunk of memory or it may  * be allocated off the page from a special slab zone.  The free list within a  * slab is managed with a bitmask.  For item sizes that would yield more than  * 10% memory waste we potentially allocate a separate uma_slab_t if this will  * improve the number of items per slab that will fit.    *  * The only really gross cases, with regards to memory waste, are for those  * items that are just over half the page size.   You can get nearly 50% waste,  * so you fall back to the memory footprint of the power of two allocator. I  * have looked at memory allocation sizes on many of the machines available to  * me, and there does not seem to be an abundance of allocations at this range  * so at this time it may not make sense to optimize for it.  This can, of   * course, be solved with dynamic slab sizes.  *  * Kegs may serve multiple Zones but by far most of the time they only serve  * one.  When a Zone is created, a Keg is allocated and setup for it.  While  * the backing Keg stores slabs, the Zone caches Buckets of items allocated  * from the slabs.  Each Zone is equipped with an init/fini and ctor/dtor  * pair, as well as with its own set of small per-CPU caches, layered above  * the Zone's general Bucket cache.  *  * The PCPU caches are protected by critical sections, and may be accessed  * safely only from their associated CPU, while the Zones backed by the same  * Keg all share a common Keg lock (to coalesce contention on the backing  * slabs).  The backing Keg typically only serves one Zone but in the case of  * multiple Zones, one of the Zones is considered the Master Zone and all  * Zone-related stats from the Keg are done in the Master Zone.  For an  * example of a Multi-Zone setup, refer to the Mbuf allocation code.  */
end_comment

begin_comment
comment|/*  *	This is the representation for normal (Non OFFPAGE slab)  *  *	i == item  *	s == slab pointer  *  *<----------------  Page (UMA_SLAB_SIZE) ------------------>  *	___________________________________________________________  *     | _  _  _  _  _  _  _  _  _  _  _  _  _  _  _   ___________ |  *     ||i||i||i||i||i||i||i||i||i||i||i||i||i||i||i| |slab header||  *     ||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_| |___________||   *     |___________________________________________________________|  *  *  *	This is an OFFPAGE slab. These can be larger than UMA_SLAB_SIZE.  *  *	___________________________________________________________  *     | _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _   |  *     ||i||i||i||i||i||i||i||i||i||i||i||i||i||i||i||i||i||i||i|  |  *     ||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_||_|  |  *     |___________________________________________________________|  *       ___________    ^  *	|slab header|   |  *	|___________|---*  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VM_UMA_INT_H
end_ifndef

begin_define
define|#
directive|define
name|VM_UMA_INT_H
end_define

begin_define
define|#
directive|define
name|UMA_SLAB_SIZE
value|PAGE_SIZE
end_define

begin_comment
comment|/* How big are our slabs? */
end_comment

begin_define
define|#
directive|define
name|UMA_SLAB_MASK
value|(PAGE_SIZE - 1)
end_define

begin_comment
comment|/* Mask to get back to the page */
end_comment

begin_define
define|#
directive|define
name|UMA_SLAB_SHIFT
value|PAGE_SHIFT
end_define

begin_comment
comment|/* Number of bits PAGE_MASK */
end_comment

begin_define
define|#
directive|define
name|UMA_BOOT_PAGES
value|64
end_define

begin_comment
comment|/* Pages allocated for startup */
end_comment

begin_comment
comment|/* Max waste percentage before going to off page slab management */
end_comment

begin_define
define|#
directive|define
name|UMA_MAX_WASTE
value|10
end_define

begin_comment
comment|/*  * I doubt there will be many cases where this is exceeded. This is the initial  * size of the hash table for uma_slabs that are managed off page. This hash  * does expand by powers of two.  Currently it doesn't get smaller.  */
end_comment

begin_define
define|#
directive|define
name|UMA_HASH_SIZE_INIT
value|32
end_define

begin_comment
comment|/*   * I should investigate other hashing algorithms.  This should yield a low  * number of collisions if the pages are relatively contiguous.  */
end_comment

begin_define
define|#
directive|define
name|UMA_HASH
parameter_list|(
name|h
parameter_list|,
name|s
parameter_list|)
value|((((uintptr_t)s)>> UMA_SLAB_SHIFT)& (h)->uh_hashmask)
end_define

begin_define
define|#
directive|define
name|UMA_HASH_INSERT
parameter_list|(
name|h
parameter_list|,
name|s
parameter_list|,
name|mem
parameter_list|)
define|\
value|SLIST_INSERT_HEAD(&(h)->uh_slab_hash[UMA_HASH((h),	\ 		    (mem))], (s), us_hlink)
end_define

begin_define
define|#
directive|define
name|UMA_HASH_REMOVE
parameter_list|(
name|h
parameter_list|,
name|s
parameter_list|,
name|mem
parameter_list|)
define|\
value|SLIST_REMOVE(&(h)->uh_slab_hash[UMA_HASH((h),		\ 		    (mem))], (s), uma_slab, us_hlink)
end_define

begin_comment
comment|/* Hash table for freed address -> slab translation */
end_comment

begin_expr_stmt
name|SLIST_HEAD
argument_list|(
name|slabhead
argument_list|,
name|uma_slab
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|uma_hash
block|{
name|struct
name|slabhead
modifier|*
name|uh_slab_hash
decl_stmt|;
comment|/* Hash table for slabs */
name|int
name|uh_hashsize
decl_stmt|;
comment|/* Current size of the hash table */
name|int
name|uh_hashmask
decl_stmt|;
comment|/* Mask used during hashing */
block|}
struct|;
end_struct

begin_comment
comment|/*  * align field or structure to cache line  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__amd64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|UMA_ALIGN
value|__aligned(CACHE_LINE_SIZE)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UMA_ALIGN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Structures for per cpu queues.  */
end_comment

begin_struct
struct|struct
name|uma_bucket
block|{
name|LIST_ENTRY
argument_list|(
argument|uma_bucket
argument_list|)
name|ub_link
expr_stmt|;
comment|/* Link into the zone */
name|int16_t
name|ub_cnt
decl_stmt|;
comment|/* Count of free items. */
name|int16_t
name|ub_entries
decl_stmt|;
comment|/* Max items. */
name|void
modifier|*
name|ub_bucket
index|[]
decl_stmt|;
comment|/* actual allocation storage */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|uma_bucket
modifier|*
name|uma_bucket_t
typedef|;
end_typedef

begin_struct
struct|struct
name|uma_cache
block|{
name|uma_bucket_t
name|uc_freebucket
decl_stmt|;
comment|/* Bucket we're freeing to */
name|uma_bucket_t
name|uc_allocbucket
decl_stmt|;
comment|/* Bucket to allocate from */
name|uint64_t
name|uc_allocs
decl_stmt|;
comment|/* Count of allocations */
name|uint64_t
name|uc_frees
decl_stmt|;
comment|/* Count of frees */
block|}
name|UMA_ALIGN
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|uma_cache
modifier|*
name|uma_cache_t
typedef|;
end_typedef

begin_comment
comment|/*  * Keg management structure  *  * TODO: Optimize for cache line size  *  */
end_comment

begin_struct
struct|struct
name|uma_keg
block|{
name|struct
name|mtx_padalign
name|uk_lock
decl_stmt|;
comment|/* Lock for the keg */
name|struct
name|uma_hash
name|uk_hash
decl_stmt|;
name|LIST_HEAD
argument_list|(
argument_list|,
argument|uma_zone
argument_list|)
name|uk_zones
expr_stmt|;
comment|/* Keg's zones */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|uma_slab
argument_list|)
name|uk_part_slab
expr_stmt|;
comment|/* partially allocated slabs */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|uma_slab
argument_list|)
name|uk_free_slab
expr_stmt|;
comment|/* empty slab list */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|uma_slab
argument_list|)
name|uk_full_slab
expr_stmt|;
comment|/* full slabs */
name|uint32_t
name|uk_align
decl_stmt|;
comment|/* Alignment mask */
name|uint32_t
name|uk_pages
decl_stmt|;
comment|/* Total page count */
name|uint32_t
name|uk_free
decl_stmt|;
comment|/* Count of items free in slabs */
name|uint32_t
name|uk_reserve
decl_stmt|;
comment|/* Number of reserved items. */
name|uint32_t
name|uk_size
decl_stmt|;
comment|/* Requested size of each item */
name|uint32_t
name|uk_rsize
decl_stmt|;
comment|/* Real size of each item */
name|uint32_t
name|uk_maxpages
decl_stmt|;
comment|/* Maximum number of pages to alloc */
name|uma_init
name|uk_init
decl_stmt|;
comment|/* Keg's init routine */
name|uma_fini
name|uk_fini
decl_stmt|;
comment|/* Keg's fini routine */
name|uma_alloc
name|uk_allocf
decl_stmt|;
comment|/* Allocation function */
name|uma_free
name|uk_freef
decl_stmt|;
comment|/* Free routine */
name|u_long
name|uk_offset
decl_stmt|;
comment|/* Next free offset from base KVA */
name|vm_offset_t
name|uk_kva
decl_stmt|;
comment|/* Zone base KVA */
name|uma_zone_t
name|uk_slabzone
decl_stmt|;
comment|/* Slab zone backing us, if OFFPAGE */
name|uint16_t
name|uk_slabsize
decl_stmt|;
comment|/* Slab size for this keg */
name|uint16_t
name|uk_pgoff
decl_stmt|;
comment|/* Offset to uma_slab struct */
name|uint16_t
name|uk_ppera
decl_stmt|;
comment|/* pages per allocation from backend */
name|uint16_t
name|uk_ipers
decl_stmt|;
comment|/* Items per slab */
name|uint32_t
name|uk_flags
decl_stmt|;
comment|/* Internal flags */
comment|/* Least used fields go to the last cache line. */
specifier|const
name|char
modifier|*
name|uk_name
decl_stmt|;
comment|/* Name of creating zone. */
name|LIST_ENTRY
argument_list|(
argument|uma_keg
argument_list|)
name|uk_link
expr_stmt|;
comment|/* List of all kegs */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|uma_keg
modifier|*
name|uma_keg_t
typedef|;
end_typedef

begin_comment
comment|/*  * Free bits per-slab.  */
end_comment

begin_define
define|#
directive|define
name|SLAB_SETSIZE
value|(PAGE_SIZE / UMA_SMALLEST_UNIT)
end_define

begin_expr_stmt
name|BITSET_DEFINE
argument_list|(
name|slabbits
argument_list|,
name|SLAB_SETSIZE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * The slab structure manages a single contiguous allocation from backing  * store and subdivides it into individually allocatable items.  */
end_comment

begin_struct
struct|struct
name|uma_slab
block|{
name|uma_keg_t
name|us_keg
decl_stmt|;
comment|/* Keg we live in */
union|union
block|{
name|LIST_ENTRY
argument_list|(
argument|uma_slab
argument_list|)
name|_us_link
expr_stmt|;
comment|/* slabs in zone */
name|unsigned
name|long
name|_us_size
decl_stmt|;
comment|/* Size of allocation */
block|}
name|us_type
union|;
name|SLIST_ENTRY
argument_list|(
argument|uma_slab
argument_list|)
name|us_hlink
expr_stmt|;
comment|/* Link for hash table */
name|uint8_t
modifier|*
name|us_data
decl_stmt|;
comment|/* First item */
name|struct
name|slabbits
name|us_free
decl_stmt|;
comment|/* Free bitmask. */
ifdef|#
directive|ifdef
name|INVARIANTS
name|struct
name|slabbits
name|us_debugfree
decl_stmt|;
comment|/* Debug bitmask. */
endif|#
directive|endif
name|uint16_t
name|us_freecount
decl_stmt|;
comment|/* How many are free? */
name|uint8_t
name|us_flags
decl_stmt|;
comment|/* Page flags see uma.h */
name|uint8_t
name|us_pad
decl_stmt|;
comment|/* Pad to 32bits, unused. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|us_link
value|us_type._us_link
end_define

begin_define
define|#
directive|define
name|us_size
value|us_type._us_size
end_define

begin_comment
comment|/*  * The slab structure for UMA_ZONE_REFCNT zones for whose items we  * maintain reference counters in the slab for.  */
end_comment

begin_struct
struct|struct
name|uma_slab_refcnt
block|{
name|struct
name|uma_slab
name|us_head
decl_stmt|;
comment|/* slab header data */
name|uint32_t
name|us_refcnt
index|[
literal|0
index|]
decl_stmt|;
comment|/* Actually larger. */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|uma_slab
modifier|*
name|uma_slab_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|uma_slab_refcnt
modifier|*
name|uma_slabrefcnt_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uma_slab_t
function_decl|(
modifier|*
name|uma_slaballoc
function_decl|)
parameter_list|(
name|uma_zone_t
parameter_list|,
name|uma_keg_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|uma_klink
block|{
name|LIST_ENTRY
argument_list|(
argument|uma_klink
argument_list|)
name|kl_link
expr_stmt|;
name|uma_keg_t
name|kl_keg
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|uma_klink
modifier|*
name|uma_klink_t
typedef|;
end_typedef

begin_comment
comment|/*  * Zone management structure   *  * TODO: Optimize for cache line size  *  */
end_comment

begin_struct
struct|struct
name|uma_zone
block|{
name|struct
name|mtx_padalign
name|uz_lock
decl_stmt|;
comment|/* Lock for the zone */
name|struct
name|mtx_padalign
modifier|*
name|uz_lockptr
decl_stmt|;
specifier|const
name|char
modifier|*
name|uz_name
decl_stmt|;
comment|/* Text name of the zone */
name|LIST_ENTRY
argument_list|(
argument|uma_zone
argument_list|)
name|uz_link
expr_stmt|;
comment|/* List of all zones in keg */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|uma_bucket
argument_list|)
name|uz_buckets
expr_stmt|;
comment|/* full buckets */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|uma_klink
argument_list|)
name|uz_kegs
expr_stmt|;
comment|/* List of kegs. */
name|struct
name|uma_klink
name|uz_klink
decl_stmt|;
comment|/* klink for first keg. */
name|uma_slaballoc
name|uz_slab
decl_stmt|;
comment|/* Allocate a slab from the backend. */
name|uma_ctor
name|uz_ctor
decl_stmt|;
comment|/* Constructor for each allocation */
name|uma_dtor
name|uz_dtor
decl_stmt|;
comment|/* Destructor */
name|uma_init
name|uz_init
decl_stmt|;
comment|/* Initializer for each item */
name|uma_fini
name|uz_fini
decl_stmt|;
comment|/* Finalizer for each item. */
name|uma_import
name|uz_import
decl_stmt|;
comment|/* Import new memory to cache. */
name|uma_release
name|uz_release
decl_stmt|;
comment|/* Release memory from cache. */
name|void
modifier|*
name|uz_arg
decl_stmt|;
comment|/* Import/release argument. */
name|uint32_t
name|uz_flags
decl_stmt|;
comment|/* Flags inherited from kegs */
name|uint32_t
name|uz_size
decl_stmt|;
comment|/* Size inherited from kegs */
specifier|volatile
name|u_long
name|uz_allocs
name|UMA_ALIGN
decl_stmt|;
comment|/* Total number of allocations */
specifier|volatile
name|u_long
name|uz_fails
decl_stmt|;
comment|/* Total number of alloc failures */
specifier|volatile
name|u_long
name|uz_frees
decl_stmt|;
comment|/* Total number of frees */
name|uint64_t
name|uz_sleeps
decl_stmt|;
comment|/* Total number of alloc sleeps */
name|uint16_t
name|uz_count
decl_stmt|;
comment|/* Amount of items in full bucket */
name|uint16_t
name|uz_count_min
decl_stmt|;
comment|/* Minimal amount of items there */
comment|/* The next three fields are used to print a rate-limited warnings. */
specifier|const
name|char
modifier|*
name|uz_warning
decl_stmt|;
comment|/* Warning to print on failure */
name|struct
name|timeval
name|uz_ratecheck
decl_stmt|;
comment|/* Warnings rate-limiting */
comment|/* 	 * This HAS to be the last item because we adjust the zone size 	 * based on NCPU and then allocate the space for the zones. 	 */
name|struct
name|uma_cache
name|uz_cpu
index|[
literal|1
index|]
decl_stmt|;
comment|/* Per cpu caches */
block|}
struct|;
end_struct

begin_comment
comment|/*  * These flags must not overlap with the UMA_ZONE flags specified in uma.h.  */
end_comment

begin_define
define|#
directive|define
name|UMA_ZFLAG_MULTI
value|0x04000000
end_define

begin_comment
comment|/* Multiple kegs in the zone. */
end_comment

begin_define
define|#
directive|define
name|UMA_ZFLAG_DRAINING
value|0x08000000
end_define

begin_comment
comment|/* Running zone_drain. */
end_comment

begin_define
define|#
directive|define
name|UMA_ZFLAG_BUCKET
value|0x10000000
end_define

begin_comment
comment|/* Bucket zone. */
end_comment

begin_define
define|#
directive|define
name|UMA_ZFLAG_INTERNAL
value|0x20000000
end_define

begin_comment
comment|/* No offpage no PCPU. */
end_comment

begin_define
define|#
directive|define
name|UMA_ZFLAG_FULL
value|0x40000000
end_define

begin_comment
comment|/* Reached uz_maxpages */
end_comment

begin_define
define|#
directive|define
name|UMA_ZFLAG_CACHEONLY
value|0x80000000
end_define

begin_comment
comment|/* Don't ask VM for buckets. */
end_comment

begin_define
define|#
directive|define
name|UMA_ZFLAG_INHERIT
define|\
value|(UMA_ZFLAG_INTERNAL | UMA_ZFLAG_CACHEONLY | UMA_ZFLAG_BUCKET)
end_define

begin_function
specifier|static
specifier|inline
name|uma_keg_t
name|zone_first_keg
parameter_list|(
name|uma_zone_t
name|zone
parameter_list|)
block|{
name|uma_klink_t
name|klink
decl_stmt|;
name|klink
operator|=
name|LIST_FIRST
argument_list|(
operator|&
name|zone
operator|->
name|uz_kegs
argument_list|)
expr_stmt|;
return|return
operator|(
name|klink
operator|!=
name|NULL
operator|)
condition|?
name|klink
operator|->
name|kl_keg
else|:
name|NULL
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|UMA_ALIGN
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* Internal prototypes */
end_comment

begin_function_decl
specifier|static
name|__inline
name|uma_slab_t
name|hash_sfind
parameter_list|(
name|struct
name|uma_hash
modifier|*
name|hash
parameter_list|,
name|uint8_t
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|uma_large_malloc
parameter_list|(
name|int
name|size
parameter_list|,
name|int
name|wait
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uma_large_free
parameter_list|(
name|uma_slab_t
name|slab
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Lock Macros */
end_comment

begin_define
define|#
directive|define
name|KEG_LOCK_INIT
parameter_list|(
name|k
parameter_list|,
name|lc
parameter_list|)
define|\
value|do {							\ 		if ((lc))					\ 			mtx_init(&(k)->uk_lock, (k)->uk_name,	\ 			    (k)->uk_name, MTX_DEF | MTX_DUPOK);	\ 		else						\ 			mtx_init(&(k)->uk_lock, (k)->uk_name,	\ 			    "UMA zone", MTX_DEF | MTX_DUPOK);	\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|KEG_LOCK_FINI
parameter_list|(
name|k
parameter_list|)
value|mtx_destroy(&(k)->uk_lock)
end_define

begin_define
define|#
directive|define
name|KEG_LOCK
parameter_list|(
name|k
parameter_list|)
value|mtx_lock(&(k)->uk_lock)
end_define

begin_define
define|#
directive|define
name|KEG_UNLOCK
parameter_list|(
name|k
parameter_list|)
value|mtx_unlock(&(k)->uk_lock)
end_define

begin_define
define|#
directive|define
name|ZONE_LOCK_INIT
parameter_list|(
name|z
parameter_list|,
name|lc
parameter_list|)
define|\
value|do {							\ 		if ((lc))					\ 			mtx_init(&(z)->uz_lock, (z)->uz_name,	\ 			    (z)->uz_name, MTX_DEF | MTX_DUPOK);	\ 		else						\ 			mtx_init(&(z)->uz_lock, (z)->uz_name,	\ 			    "UMA zone", MTX_DEF | MTX_DUPOK);	\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ZONE_LOCK
parameter_list|(
name|z
parameter_list|)
value|mtx_lock((z)->uz_lockptr)
end_define

begin_define
define|#
directive|define
name|ZONE_TRYLOCK
parameter_list|(
name|z
parameter_list|)
value|mtx_trylock((z)->uz_lockptr)
end_define

begin_define
define|#
directive|define
name|ZONE_UNLOCK
parameter_list|(
name|z
parameter_list|)
value|mtx_unlock((z)->uz_lockptr)
end_define

begin_define
define|#
directive|define
name|ZONE_LOCK_FINI
parameter_list|(
name|z
parameter_list|)
value|mtx_destroy(&(z)->uz_lock)
end_define

begin_comment
comment|/*  * Find a slab within a hash table.  This is used for OFFPAGE zones to lookup  * the slab structure.  *  * Arguments:  *	hash  The hash table to search.  *	data  The base page of the item.  *  * Returns:  *	A pointer to a slab if successful, else NULL.  */
end_comment

begin_function
specifier|static
name|__inline
name|uma_slab_t
name|hash_sfind
parameter_list|(
name|struct
name|uma_hash
modifier|*
name|hash
parameter_list|,
name|uint8_t
modifier|*
name|data
parameter_list|)
block|{
name|uma_slab_t
name|slab
decl_stmt|;
name|int
name|hval
decl_stmt|;
name|hval
operator|=
name|UMA_HASH
argument_list|(
name|hash
argument_list|,
name|data
argument_list|)
expr_stmt|;
name|SLIST_FOREACH
argument_list|(
argument|slab
argument_list|,
argument|&hash->uh_slab_hash[hval]
argument_list|,
argument|us_hlink
argument_list|)
block|{
if|if
condition|(
operator|(
name|uint8_t
operator|*
operator|)
name|slab
operator|->
name|us_data
operator|==
name|data
condition|)
return|return
operator|(
name|slab
operator|)
return|;
block|}
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|uma_slab_t
name|vtoslab
parameter_list|(
name|vm_offset_t
name|va
parameter_list|)
block|{
name|vm_page_t
name|p
decl_stmt|;
name|p
operator|=
name|PHYS_TO_VM_PAGE
argument_list|(
name|pmap_kextract
argument_list|(
name|va
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|uma_slab_t
operator|)
name|p
operator|->
name|plinks
operator|.
name|s
operator|.
name|pv
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|vsetslab
parameter_list|(
name|vm_offset_t
name|va
parameter_list|,
name|uma_slab_t
name|slab
parameter_list|)
block|{
name|vm_page_t
name|p
decl_stmt|;
name|p
operator|=
name|PHYS_TO_VM_PAGE
argument_list|(
name|pmap_kextract
argument_list|(
name|va
argument_list|)
argument_list|)
expr_stmt|;
name|p
operator|->
name|plinks
operator|.
name|s
operator|.
name|pv
operator|=
name|slab
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * The following two functions may be defined by architecture specific code  * if they can provide more effecient allocation functions.  This is useful  * for using direct mapped addresses.  */
end_comment

begin_function_decl
name|void
modifier|*
name|uma_small_alloc
parameter_list|(
name|uma_zone_t
name|zone
parameter_list|,
name|int
name|bytes
parameter_list|,
name|uint8_t
modifier|*
name|pflag
parameter_list|,
name|int
name|wait
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uma_small_free
parameter_list|(
name|void
modifier|*
name|mem
parameter_list|,
name|int
name|size
parameter_list|,
name|uint8_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VM_UMA_INT_H */
end_comment

end_unit

