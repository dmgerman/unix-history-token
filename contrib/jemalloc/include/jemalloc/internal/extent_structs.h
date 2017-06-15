begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_INTERNAL_EXTENT_STRUCTS_H
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_EXTENT_STRUCTS_H
end_define

begin_include
include|#
directive|include
file|"jemalloc/internal/atomic.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/bitmap.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/mutex.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/ql.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/rb.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/ph.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/size_classes.h"
end_include

begin_typedef
typedef|typedef
enum|enum
block|{
name|extent_state_active
init|=
literal|0
block|,
name|extent_state_dirty
init|=
literal|1
block|,
name|extent_state_muzzy
init|=
literal|2
block|,
name|extent_state_retained
init|=
literal|3
block|}
name|extent_state_t
typedef|;
end_typedef

begin_comment
comment|/* Extent (span of pages).  Use accessor functions for e_* fields. */
end_comment

begin_struct
struct|struct
name|extent_s
block|{
comment|/* 	 * Bitfield containing several fields: 	 * 	 * a: arena_ind 	 * b: slab 	 * c: committed 	 * z: zeroed 	 * t: state 	 * i: szind 	 * f: nfree 	 * n: sn 	 * 	 * nnnnnnnn ... nnnnnfff fffffffi iiiiiiit tzcbaaaa aaaaaaaa 	 * 	 * arena_ind: Arena from which this extent came, or all 1 bits if 	 *            unassociated. 	 * 	 * slab: The slab flag indicates whether the extent is used for a slab 	 *       of small regions.  This helps differentiate small size classes, 	 *       and it indicates whether interior pointers can be looked up via 	 *       iealloc(). 	 * 	 * committed: The committed flag indicates whether physical memory is 	 *            committed to the extent, whether explicitly or implicitly 	 *            as on a system that overcommits and satisfies physical 	 *            memory needs on demand via soft page faults. 	 * 	 * zeroed: The zeroed flag is used by extent recycling code to track 	 *         whether memory is zero-filled. 	 * 	 * state: The state flag is an extent_state_t. 	 * 	 * szind: The szind flag indicates usable size class index for 	 *        allocations residing in this extent, regardless of whether the 	 *        extent is a slab.  Extent size and usable size often differ 	 *        even for non-slabs, either due to sz_large_pad or promotion of 	 *        sampled small regions. 	 * 	 * nfree: Number of free regions in slab. 	 * 	 * sn: Serial number (potentially non-unique). 	 * 	 *     Serial numbers may wrap around if !opt_retain, but as long as 	 *     comparison functions fall back on address comparison for equal 	 *     serial numbers, stable (if imperfect) ordering is maintained. 	 * 	 *     Serial numbers may not be unique even in the absence of 	 *     wrap-around, e.g. when splitting an extent and assigning the same 	 *     serial number to both resulting adjacent extents. 	 */
name|uint64_t
name|e_bits
decl_stmt|;
define|#
directive|define
name|EXTENT_BITS_ARENA_SHIFT
value|0
define|#
directive|define
name|EXTENT_BITS_ARENA_MASK
define|\
value|(((uint64_t)(1U<< MALLOCX_ARENA_BITS) - 1)<< EXTENT_BITS_ARENA_SHIFT)
define|#
directive|define
name|EXTENT_BITS_SLAB_SHIFT
value|MALLOCX_ARENA_BITS
define|#
directive|define
name|EXTENT_BITS_SLAB_MASK
define|\
value|((uint64_t)0x1U<< EXTENT_BITS_SLAB_SHIFT)
define|#
directive|define
name|EXTENT_BITS_COMMITTED_SHIFT
value|(MALLOCX_ARENA_BITS + 1)
define|#
directive|define
name|EXTENT_BITS_COMMITTED_MASK
define|\
value|((uint64_t)0x1U<< EXTENT_BITS_COMMITTED_SHIFT)
define|#
directive|define
name|EXTENT_BITS_ZEROED_SHIFT
value|(MALLOCX_ARENA_BITS + 2)
define|#
directive|define
name|EXTENT_BITS_ZEROED_MASK
define|\
value|((uint64_t)0x1U<< EXTENT_BITS_ZEROED_SHIFT)
define|#
directive|define
name|EXTENT_BITS_STATE_SHIFT
value|(MALLOCX_ARENA_BITS + 3)
define|#
directive|define
name|EXTENT_BITS_STATE_MASK
define|\
value|((uint64_t)0x3U<< EXTENT_BITS_STATE_SHIFT)
define|#
directive|define
name|EXTENT_BITS_SZIND_SHIFT
value|(MALLOCX_ARENA_BITS + 5)
define|#
directive|define
name|EXTENT_BITS_SZIND_MASK
define|\
value|(((uint64_t)(1U<< LG_CEIL_NSIZES) - 1)<< EXTENT_BITS_SZIND_SHIFT)
define|#
directive|define
name|EXTENT_BITS_NFREE_SHIFT
define|\
value|(MALLOCX_ARENA_BITS + 5 + LG_CEIL_NSIZES)
define|#
directive|define
name|EXTENT_BITS_NFREE_MASK
define|\
value|((uint64_t)((1U<< (LG_SLAB_MAXREGS + 1)) - 1)<< EXTENT_BITS_NFREE_SHIFT)
define|#
directive|define
name|EXTENT_BITS_SN_SHIFT
define|\
value|(MALLOCX_ARENA_BITS + 5 + LG_CEIL_NSIZES + (LG_SLAB_MAXREGS + 1))
define|#
directive|define
name|EXTENT_BITS_SN_MASK
value|(UINT64_MAX<< EXTENT_BITS_SN_SHIFT)
comment|/* Pointer to the extent that this structure is responsible for. */
name|void
modifier|*
name|e_addr
decl_stmt|;
union|union
block|{
comment|/* 		 * Extent size and serial number associated with the extent 		 * structure (different than the serial number for the extent at 		 * e_addr). 		 * 		 * ssssssss [...] ssssssss ssssnnnn nnnnnnnn 		 */
name|size_t
name|e_size_esn
decl_stmt|;
define|#
directive|define
name|EXTENT_SIZE_MASK
value|((size_t)~(PAGE-1))
define|#
directive|define
name|EXTENT_ESN_MASK
value|((size_t)PAGE-1)
comment|/* Base extent size, which may not be a multiple of PAGE. */
name|size_t
name|e_bsize
decl_stmt|;
block|}
union|;
union|union
block|{
comment|/* 		 * List linkage, used by a variety of lists: 		 * - arena_bin_t's slabs_full 		 * - extents_t's LRU 		 * - stashed dirty extents 		 * - arena's large allocations 		 */
name|ql_elm
argument_list|(
argument|extent_t
argument_list|)
name|ql_link
expr_stmt|;
comment|/* Red-black tree linkage, used by arena's extent_avail. */
name|rb_node
argument_list|(
argument|extent_t
argument_list|)
name|rb_link
expr_stmt|;
block|}
union|;
comment|/* Linkage for per size class sn/address-ordered heaps. */
name|phn
argument_list|(
argument|extent_t
argument_list|)
name|ph_link
expr_stmt|;
union|union
block|{
comment|/* Small region slab metadata. */
name|arena_slab_data_t
name|e_slab_data
decl_stmt|;
comment|/* 		 * Profile counters, used for large objects.  Points to a 		 * prof_tctx_t. 		 */
name|atomic_p_t
name|e_prof_tctx
decl_stmt|;
block|}
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|ql_head
argument_list|(
argument|extent_t
argument_list|)
name|extent_list_t
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|rb_tree
argument_list|(
argument|extent_t
argument_list|)
name|extent_tree_t
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|ph
argument_list|(
argument|extent_t
argument_list|)
name|extent_heap_t
expr_stmt|;
end_typedef

begin_comment
comment|/* Quantized collection of extents, with built-in LRU queue. */
end_comment

begin_struct
struct|struct
name|extents_s
block|{
name|malloc_mutex_t
name|mtx
decl_stmt|;
comment|/* 	 * Quantized per size class heaps of extents. 	 * 	 * Synchronization: mtx. 	 */
name|extent_heap_t
name|heaps
index|[
name|NPSIZES
operator|+
literal|1
index|]
decl_stmt|;
comment|/* 	 * Bitmap for which set bits correspond to non-empty heaps. 	 * 	 * Synchronization: mtx. 	 */
name|bitmap_t
name|bitmap
index|[
name|BITMAP_GROUPS
argument_list|(
name|NPSIZES
operator|+
literal|1
argument_list|)
index|]
decl_stmt|;
comment|/* 	 * LRU of all extents in heaps. 	 * 	 * Synchronization: mtx. 	 */
name|extent_list_t
name|lru
decl_stmt|;
comment|/* 	 * Page sum for all extents in heaps. 	 * 	 * The synchronization here is a little tricky.  Modifications to npages 	 * must hold mtx, but reads need not (though, a reader who sees npages 	 * without holding the mutex can't assume anything about the rest of the 	 * state of the extents_t). 	 */
name|atomic_zu_t
name|npages
decl_stmt|;
comment|/* All stored extents must be in the same state. */
name|extent_state_t
name|state
decl_stmt|;
comment|/* 	 * If true, delay coalescing until eviction; otherwise coalesce during 	 * deallocation. 	 */
name|bool
name|delay_coalesce
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_INTERNAL_EXTENT_STRUCTS_H */
end_comment

end_unit

