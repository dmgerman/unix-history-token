begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002, 2003, 2004, 2005 Jeffrey Roberson<jeff@FreeBSD.org>  * Copyright (c) 2004, 2005 Bosko Milekic<bmilekic@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/*   * This file includes definitions, structures, prototypes, and inlines that  * should not be used outside of the actual implementation of UMA.  */
end_comment

begin_comment
comment|/*   * Here's a quick description of the relationship between the objects:  *  * Kegs contain lists of slabs which are stored in either the full bin, empty  * bin, or partially allocated bin, to reduce fragmentation.  They also contain  * the user supplied value for size, which is adjusted for alignment purposes  * and rsize is the result of that.  The Keg also stores information for  * managing a hash of page addresses that maps pages to uma_slab_t structures  * for pages that don't have embedded uma_slab_t's.  *    * The uma_slab_t may be embedded in a UMA_SLAB_SIZE chunk of memory or it may  * be allocated off the page from a special slab zone.  The free list within a  * slab is managed with a linked list of indexes, which are 8 bit values.  If  * UMA_SLAB_SIZE is defined to be too large I will have to switch to 16bit  * values.  Currently on alpha you can get 250 or so 32 byte items and on x86  * you can get 250 or so 16byte items.  For item sizes that would yield more  * than 10% memory waste we potentially allocate a separate uma_slab_t if this  * will improve the number of items per slab that will fit.    *  * Other potential space optimizations are storing the 8bit of linkage in space  * wasted between items due to alignment problems.  This may yield a much better  * memory footprint for certain sizes of objects.  Another alternative is to  * increase the UMA_SLAB_SIZE, or allow for dynamic slab sizes.  I prefer  * dynamic slab sizes because we could stick with 8 bit indexes and only use  * large slab sizes for zones with a lot of waste per slab.  This may create  * ineffeciencies in the vm subsystem due to fragmentation in the address space.  *  * The only really gross cases, with regards to memory waste, are for those  * items that are just over half the page size.   You can get nearly 50% waste,  * so you fall back to the memory footprint of the power of two allocator. I  * have looked at memory allocation sizes on many of the machines available to  * me, and there does not seem to be an abundance of allocations at this range  * so at this time it may not make sense to optimize for it.  This can, of   * course, be solved with dynamic slab sizes.  *  * Kegs may serve multiple Zones but by far most of the time they only serve  * one.  When a Zone is created, a Keg is allocated and setup for it.  While  * the backing Keg stores slabs, the Zone caches Buckets of items allocated  * from the slabs.  Each Zone is equipped with an init/fini and ctor/dtor  * pair, as well as with its own set of small per-CPU caches, layered above  * the Zone's general Bucket cache.  *  * The PCPU caches are protected by critical sections, and may be accessed  * safely only from their associated CPU, while the Zones backed by the same  * Keg all share a common Keg lock (to coalesce contention on the backing  * slabs).  The backing Keg typically only serves one Zone but in the case of  * multiple Zones, one of the Zones is considered the Master Zone and all  * Zone-related stats from the Keg are done in the Master Zone.  For an  * example of a Multi-Zone setup, refer to the Mbuf allocation code.  */
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
value|48
end_define

begin_comment
comment|/* Pages allocated for startup */
end_comment

begin_comment
comment|/* Max waste before going to off page slab management */
end_comment

begin_define
define|#
directive|define
name|UMA_MAX_WASTE
value|(UMA_SLAB_SIZE / 10)
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
comment|/*   * I should investigate other hashing algorithms.  This should yield a low  * number of collisions if the pages are relatively contiguous.  *  * This is the same algorithm that most processor caches use.  *  * I'm shifting and masking instead of % because it should be faster.  */
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
value|((((unsigned long)s)>> UMA_SLAB_SHIFT)&	\     (h)->uh_hashmask)
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
value|SLIST_INSERT_HEAD(&(h)->uh_slab_hash[UMA_HASH((h),	\ 		    (mem))], (s), us_hlink);
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
value|SLIST_REMOVE(&(h)->uh_slab_hash[UMA_HASH((h),		\ 		    (mem))], (s), uma_slab, us_hlink);
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
name|u_int64_t
name|uc_allocs
decl_stmt|;
comment|/* Count of allocations */
name|u_int64_t
name|uc_frees
decl_stmt|;
comment|/* Count of frees */
block|}
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
name|LIST_ENTRY
argument_list|(
argument|uma_keg
argument_list|)
name|uk_link
expr_stmt|;
comment|/* List of all kegs */
name|struct
name|mtx
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
name|u_int32_t
name|uk_recurse
decl_stmt|;
comment|/* Allocation recursion count */
name|u_int32_t
name|uk_align
decl_stmt|;
comment|/* Alignment mask */
name|u_int32_t
name|uk_pages
decl_stmt|;
comment|/* Total page count */
name|u_int32_t
name|uk_free
decl_stmt|;
comment|/* Count of items free in slabs */
name|u_int32_t
name|uk_size
decl_stmt|;
comment|/* Requested size of each item */
name|u_int32_t
name|uk_rsize
decl_stmt|;
comment|/* Real size of each item */
name|u_int32_t
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
name|struct
name|vm_object
modifier|*
name|uk_obj
decl_stmt|;
comment|/* Zone specific object */
name|vm_offset_t
name|uk_kva
decl_stmt|;
comment|/* Base kva for zones with objs */
name|uma_zone_t
name|uk_slabzone
decl_stmt|;
comment|/* Slab zone backing us, if OFFPAGE */
name|u_int16_t
name|uk_pgoff
decl_stmt|;
comment|/* Offset to uma_slab struct */
name|u_int16_t
name|uk_ppera
decl_stmt|;
comment|/* pages per allocation from backend */
name|u_int16_t
name|uk_ipers
decl_stmt|;
comment|/* Items per slab */
name|u_int32_t
name|uk_flags
decl_stmt|;
comment|/* Internal flags */
block|}
struct|;
end_struct

begin_comment
comment|/* Simpler reference to uma_keg for internal use. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|uma_keg
modifier|*
name|uma_keg_t
typedef|;
end_typedef

begin_comment
comment|/* Page management structure */
end_comment

begin_comment
comment|/* Sorry for the union, but space efficiency is important */
end_comment

begin_struct
struct|struct
name|uma_slab_head
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
name|u_int8_t
modifier|*
name|us_data
decl_stmt|;
comment|/* First item */
name|u_int8_t
name|us_flags
decl_stmt|;
comment|/* Page flags see uma.h */
name|u_int8_t
name|us_freecount
decl_stmt|;
comment|/* How many are free? */
name|u_int8_t
name|us_firstfree
decl_stmt|;
comment|/* First free item index */
block|}
struct|;
end_struct

begin_comment
comment|/* The standard slab structure */
end_comment

begin_struct
struct|struct
name|uma_slab
block|{
name|struct
name|uma_slab_head
name|us_head
decl_stmt|;
comment|/* slab header data */
struct|struct
block|{
name|u_int8_t
name|us_item
decl_stmt|;
block|}
name|us_freelist
index|[
literal|1
index|]
struct|;
comment|/* actual number bigger */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The slab structure for UMA_ZONE_REFCNT zones for whose items we  * maintain reference counters in the slab for.  */
end_comment

begin_struct
struct|struct
name|uma_slab_refcnt
block|{
name|struct
name|uma_slab_head
name|us_head
decl_stmt|;
comment|/* slab header data */
struct|struct
block|{
name|u_int8_t
name|us_item
decl_stmt|;
name|u_int32_t
name|us_refcnt
decl_stmt|;
block|}
name|us_freelist
index|[
literal|1
index|]
struct|;
comment|/* actual number bigger */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|us_keg
value|us_head.us_keg
end_define

begin_define
define|#
directive|define
name|us_link
value|us_head.us_type._us_link
end_define

begin_define
define|#
directive|define
name|us_size
value|us_head.us_type._us_size
end_define

begin_define
define|#
directive|define
name|us_hlink
value|us_head.us_hlink
end_define

begin_define
define|#
directive|define
name|us_data
value|us_head.us_data
end_define

begin_define
define|#
directive|define
name|us_flags
value|us_head.us_flags
end_define

begin_define
define|#
directive|define
name|us_freecount
value|us_head.us_freecount
end_define

begin_define
define|#
directive|define
name|us_firstfree
value|us_head.us_firstfree
end_define

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

begin_comment
comment|/*  * These give us the size of one free item reference within our corresponding  * uma_slab structures, so that our calculations during zone setup are correct  * regardless of what the compiler decides to do with padding the structure  * arrays within uma_slab.  */
end_comment

begin_define
define|#
directive|define
name|UMA_FRITM_SZ
value|(sizeof(struct uma_slab) - sizeof(struct uma_slab_head))
end_define

begin_define
define|#
directive|define
name|UMA_FRITMREF_SZ
value|(sizeof(struct uma_slab_refcnt) -	\     sizeof(struct uma_slab_head))
end_define

begin_comment
comment|/*  * Zone management structure   *  * TODO: Optimize for cache line size  *  */
end_comment

begin_struct
struct|struct
name|uma_zone
block|{
name|char
modifier|*
name|uz_name
decl_stmt|;
comment|/* Text name of the zone */
name|struct
name|mtx
modifier|*
name|uz_lock
decl_stmt|;
comment|/* Lock for the zone (keg's lock) */
name|uma_keg_t
name|uz_keg
decl_stmt|;
comment|/* Our underlying Keg */
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
name|uz_full_bucket
expr_stmt|;
comment|/* full buckets */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|uma_bucket
argument_list|)
name|uz_free_bucket
expr_stmt|;
comment|/* Buckets for frees */
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
comment|/* Discards memory */
name|u_int64_t
name|uz_allocs
decl_stmt|;
comment|/* Total number of allocations */
name|u_int64_t
name|uz_frees
decl_stmt|;
comment|/* Total number of frees */
name|u_int64_t
name|uz_fails
decl_stmt|;
comment|/* Total number of alloc failures */
name|uint16_t
name|uz_fills
decl_stmt|;
comment|/* Outstanding bucket fills */
name|uint16_t
name|uz_count
decl_stmt|;
comment|/* Highest value ub_ptr can have */
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
name|UMA_ZFLAG_PRIVALLOC
value|0x10000000
end_define

begin_comment
comment|/* Use uz_allocf. */
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
name|u_int8_t
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
name|ZONE_LOCK_INIT
parameter_list|(
name|z
parameter_list|,
name|lc
parameter_list|)
define|\
value|do {							\ 		if ((lc))					\ 			mtx_init((z)->uz_lock, (z)->uz_name,	\ 			    (z)->uz_name, MTX_DEF | MTX_DUPOK);	\ 		else						\ 			mtx_init((z)->uz_lock, (z)->uz_name,	\ 			    "UMA zone", MTX_DEF | MTX_DUPOK);	\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ZONE_LOCK_FINI
parameter_list|(
name|z
parameter_list|)
value|mtx_destroy((z)->uz_lock)
end_define

begin_define
define|#
directive|define
name|ZONE_LOCK
parameter_list|(
name|z
parameter_list|)
value|mtx_lock((z)->uz_lock)
end_define

begin_define
define|#
directive|define
name|ZONE_UNLOCK
parameter_list|(
name|z
parameter_list|)
value|mtx_unlock((z)->uz_lock)
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
name|u_int8_t
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
name|u_int8_t
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
name|uma_slab_t
name|slab
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
name|slab
operator|=
operator|(
name|uma_slab_t
operator|)
name|p
operator|->
name|object
expr_stmt|;
if|if
condition|(
name|p
operator|->
name|flags
operator|&
name|PG_SLAB
condition|)
return|return
operator|(
name|slab
operator|)
return|;
else|else
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
name|object
operator|=
operator|(
name|vm_object_t
operator|)
name|slab
expr_stmt|;
name|p
operator|->
name|flags
operator||=
name|PG_SLAB
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|vsetobj
parameter_list|(
name|vm_offset_t
name|va
parameter_list|,
name|vm_object_t
name|obj
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
name|object
operator|=
name|obj
expr_stmt|;
name|p
operator|->
name|flags
operator|&=
operator|~
name|PG_SLAB
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
name|u_int8_t
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
name|u_int8_t
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

