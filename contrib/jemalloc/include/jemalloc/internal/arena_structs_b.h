begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_INTERNAL_ARENA_STRUCTS_B_H
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_ARENA_STRUCTS_B_H
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
file|"jemalloc/internal/extent_dss.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/jemalloc_internal_types.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/mutex.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/nstime.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/ql.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/size_classes.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/smoothstep.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/stats.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/ticker.h"
end_include

begin_comment
comment|/*  * Read-only information associated with each element of arena_t's bins array  * is stored separately, partly to reduce memory usage (only one copy, rather  * than one per arena), but mainly to avoid false cacheline sharing.  *  * Each slab has the following layout:  *  *   /--------------------\  *   | region 0           |  *   |--------------------|  *   | region 1           |  *   |--------------------|  *   | ...                |  *   | ...                |  *   | ...                |  *   |--------------------|  *   | region nregs-1     |  *   \--------------------/  */
end_comment

begin_struct
struct|struct
name|arena_bin_info_s
block|{
comment|/* Size of regions in a slab for this bin's size class. */
name|size_t
name|reg_size
decl_stmt|;
comment|/* Total size of a slab for this bin's size class. */
name|size_t
name|slab_size
decl_stmt|;
comment|/* Total number of regions in a slab for this bin's size class. */
name|uint32_t
name|nregs
decl_stmt|;
comment|/* 	 * Metadata used to manipulate bitmaps for slabs associated with this 	 * bin. 	 */
name|bitmap_info_t
name|bitmap_info
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|arena_decay_s
block|{
comment|/* Synchronizes all non-atomic fields. */
name|malloc_mutex_t
name|mtx
decl_stmt|;
comment|/* 	 * True if a thread is currently purging the extents associated with 	 * this decay structure. 	 */
name|bool
name|purging
decl_stmt|;
comment|/* 	 * Approximate time in milliseconds from the creation of a set of unused 	 * dirty pages until an equivalent set of unused dirty pages is purged 	 * and/or reused. 	 */
name|atomic_zd_t
name|time_ms
decl_stmt|;
comment|/* time / SMOOTHSTEP_NSTEPS. */
name|nstime_t
name|interval
decl_stmt|;
comment|/* 	 * Time at which the current decay interval logically started.  We do 	 * not actually advance to a new epoch until sometime after it starts 	 * because of scheduling and computation delays, and it is even possible 	 * to completely skip epochs.  In all cases, during epoch advancement we 	 * merge all relevant activity into the most recently recorded epoch. 	 */
name|nstime_t
name|epoch
decl_stmt|;
comment|/* Deadline randomness generator. */
name|uint64_t
name|jitter_state
decl_stmt|;
comment|/* 	 * Deadline for current epoch.  This is the sum of interval and per 	 * epoch jitter which is a uniform random variable in [0..interval). 	 * Epochs always advance by precise multiples of interval, but we 	 * randomize the deadline to reduce the likelihood of arenas purging in 	 * lockstep. 	 */
name|nstime_t
name|deadline
decl_stmt|;
comment|/* 	 * Number of unpurged pages at beginning of current epoch.  During epoch 	 * advancement we use the delta between arena->decay_*.nunpurged and 	 * extents_npages_get(&arena->extents_*) to determine how many dirty 	 * pages, if any, were generated. 	 */
name|size_t
name|nunpurged
decl_stmt|;
comment|/* 	 * Trailing log of how many unused dirty pages were generated during 	 * each of the past SMOOTHSTEP_NSTEPS decay epochs, where the last 	 * element is the most recent epoch.  Corresponding epoch times are 	 * relative to epoch. 	 */
name|size_t
name|backlog
index|[
name|SMOOTHSTEP_NSTEPS
index|]
decl_stmt|;
comment|/* 	 * Pointer to associated stats.  These stats are embedded directly in 	 * the arena's stats due to how stats structures are shared between the 	 * arena and ctl code. 	 * 	 * Synchronization: Same as associated arena's stats field. */
name|decay_stats_t
modifier|*
name|stats
decl_stmt|;
comment|/* Peak number of pages in associated extents.  Used for debug only. */
name|uint64_t
name|ceil_npages
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|arena_bin_s
block|{
comment|/* All operations on arena_bin_t fields require lock ownership. */
name|malloc_mutex_t
name|lock
decl_stmt|;
comment|/* 	 * Current slab being used to service allocations of this bin's size 	 * class.  slabcur is independent of slabs_{nonfull,full}; whenever 	 * slabcur is reassigned, the previous slab must be deallocated or 	 * inserted into slabs_{nonfull,full}. 	 */
name|extent_t
modifier|*
name|slabcur
decl_stmt|;
comment|/* 	 * Heap of non-full slabs.  This heap is used to assure that new 	 * allocations come from the non-full slab that is oldest/lowest in 	 * memory. 	 */
name|extent_heap_t
name|slabs_nonfull
decl_stmt|;
comment|/* List used to track full slabs. */
name|extent_list_t
name|slabs_full
decl_stmt|;
comment|/* Bin statistics. */
name|malloc_bin_stats_t
name|stats
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|arena_s
block|{
comment|/* 	 * Number of threads currently assigned to this arena.  Each thread has 	 * two distinct assignments, one for application-serving allocation, and 	 * the other for internal metadata allocation.  Internal metadata must 	 * not be allocated from arenas explicitly created via the arenas.create 	 * mallctl, because the arena.<i>.reset mallctl indiscriminately 	 * discards all allocations for the affected arena. 	 * 	 *   0: Application allocation. 	 *   1: Internal metadata allocation. 	 * 	 * Synchronization: atomic. 	 */
name|atomic_u_t
name|nthreads
index|[
literal|2
index|]
decl_stmt|;
comment|/* 	 * When percpu_arena is enabled, to amortize the cost of reading / 	 * updating the current CPU id, track the most recent thread accessing 	 * this arena, and only read CPU if there is a mismatch. 	 */
name|tsdn_t
modifier|*
name|last_thd
decl_stmt|;
comment|/* Synchronization: internal. */
name|arena_stats_t
name|stats
decl_stmt|;
comment|/* 	 * List of tcaches for extant threads associated with this arena. 	 * Stats from these are merged incrementally, and at exit if 	 * opt_stats_print is enabled. 	 * 	 * Synchronization: tcache_ql_mtx. 	 */
name|ql_head
argument_list|(
argument|tcache_t
argument_list|)
name|tcache_ql
expr_stmt|;
name|malloc_mutex_t
name|tcache_ql_mtx
decl_stmt|;
comment|/* Synchronization: internal. */
name|prof_accum_t
name|prof_accum
decl_stmt|;
name|uint64_t
name|prof_accumbytes
decl_stmt|;
comment|/* 	 * PRNG state for cache index randomization of large allocation base 	 * pointers. 	 * 	 * Synchronization: atomic. 	 */
name|atomic_zu_t
name|offset_state
decl_stmt|;
comment|/* 	 * Extent serial number generator state. 	 * 	 * Synchronization: atomic. 	 */
name|atomic_zu_t
name|extent_sn_next
decl_stmt|;
comment|/* 	 * Represents a dss_prec_t, but atomically. 	 * 	 * Synchronization: atomic. 	 */
name|atomic_u_t
name|dss_prec
decl_stmt|;
comment|/* 	 * Number of pages in active extents. 	 * 	 * Synchronization: atomic. 	 */
name|atomic_zu_t
name|nactive
decl_stmt|;
comment|/* 	 * Extant large allocations. 	 * 	 * Synchronization: large_mtx. 	 */
name|extent_list_t
name|large
decl_stmt|;
comment|/* Synchronizes all large allocation/update/deallocation. */
name|malloc_mutex_t
name|large_mtx
decl_stmt|;
comment|/* 	 * Collections of extents that were previously allocated.  These are 	 * used when allocating extents, in an attempt to re-use address space. 	 * 	 * Synchronization: internal. 	 */
name|extents_t
name|extents_dirty
decl_stmt|;
name|extents_t
name|extents_muzzy
decl_stmt|;
name|extents_t
name|extents_retained
decl_stmt|;
comment|/* 	 * Decay-based purging state, responsible for scheduling extent state 	 * transitions. 	 * 	 * Synchronization: internal. 	 */
name|arena_decay_t
name|decay_dirty
decl_stmt|;
comment|/* dirty --> muzzy */
name|arena_decay_t
name|decay_muzzy
decl_stmt|;
comment|/* muzzy --> retained */
comment|/* 	 * Next extent size class in a growing series to use when satisfying a 	 * request via the extent hooks (only if opt_retain).  This limits the 	 * number of disjoint virtual memory ranges so that extent merging can 	 * be effective even if multiple arenas' extent allocation requests are 	 * highly interleaved. 	 * 	 * Synchronization: extent_grow_mtx 	 */
name|pszind_t
name|extent_grow_next
decl_stmt|;
name|malloc_mutex_t
name|extent_grow_mtx
decl_stmt|;
comment|/* 	 * Available extent structures that were allocated via 	 * base_alloc_extent(). 	 * 	 * Synchronization: extent_avail_mtx. 	 */
name|extent_tree_t
name|extent_avail
decl_stmt|;
name|malloc_mutex_t
name|extent_avail_mtx
decl_stmt|;
comment|/* 	 * bins is used to store heaps of free regions. 	 * 	 * Synchronization: internal. 	 */
name|arena_bin_t
name|bins
index|[
name|NBINS
index|]
decl_stmt|;
comment|/* 	 * Base allocator, from which arena metadata are allocated. 	 * 	 * Synchronization: internal. 	 */
name|base_t
modifier|*
name|base
decl_stmt|;
comment|/* Used to determine uptime.  Read-only after initialization. */
name|nstime_t
name|create_time
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Used in conjunction with tsd for fast arena-related context lookup. */
end_comment

begin_struct
struct|struct
name|arena_tdata_s
block|{
name|ticker_t
name|decay_ticker
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Used to pass rtree lookup context down the path. */
end_comment

begin_struct
struct|struct
name|alloc_ctx_s
block|{
name|szind_t
name|szind
decl_stmt|;
name|bool
name|slab
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_INTERNAL_ARENA_STRUCTS_B_H */
end_comment

end_unit

