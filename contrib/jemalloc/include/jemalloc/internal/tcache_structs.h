begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_INTERNAL_TCACHE_STRUCTS_H
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_TCACHE_STRUCTS_H
end_define

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
file|"jemalloc/internal/stats_tsd.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/ticker.h"
end_include

begin_comment
comment|/*  * Read-only information associated with each element of tcache_t's tbins array  * is stored separately, mainly to reduce memory usage.  */
end_comment

begin_struct
struct|struct
name|tcache_bin_info_s
block|{
name|unsigned
name|ncached_max
decl_stmt|;
comment|/* Upper limit on ncached. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tcache_bin_s
block|{
name|low_water_t
name|low_water
decl_stmt|;
comment|/* Min # cached since last GC. */
name|uint32_t
name|ncached
decl_stmt|;
comment|/* # of cached objects. */
comment|/* 	 * ncached and stats are both modified frequently.  Let's keep them 	 * close so that they have a higher chance of being on the same 	 * cacheline, thus less write-backs. 	 */
name|tcache_bin_stats_t
name|tstats
decl_stmt|;
comment|/* 	 * To make use of adjacent cacheline prefetch, the items in the avail 	 * stack goes to higher address for newer allocations.  avail points 	 * just above the available space, which means that 	 * avail[-ncached, ... -1] are available items and the lowest item will 	 * be allocated first. 	 */
name|void
modifier|*
modifier|*
name|avail
decl_stmt|;
comment|/* Stack of available objects. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tcache_s
block|{
comment|/* Data accessed frequently first: prof, ticker and small bins. */
name|uint64_t
name|prof_accumbytes
decl_stmt|;
comment|/* Cleared after arena_prof_accum(). */
name|ticker_t
name|gc_ticker
decl_stmt|;
comment|/* Drives incremental GC. */
comment|/* 	 * The pointer stacks associated with tbins follow as a contiguous 	 * array.  During tcache initialization, the avail pointer in each 	 * element of tbins is initialized to point to the proper offset within 	 * this array. 	 */
name|tcache_bin_t
name|tbins_small
index|[
name|NBINS
index|]
decl_stmt|;
comment|/* Data accessed less often below. */
name|ql_elm
argument_list|(
argument|tcache_t
argument_list|)
name|link
expr_stmt|;
comment|/* Used for aggregating stats. */
name|arena_t
modifier|*
name|arena
decl_stmt|;
comment|/* Associated arena. */
name|szind_t
name|next_gc_bin
decl_stmt|;
comment|/* Next bin to GC. */
comment|/* For small bins, fill (ncached_max>> lg_fill_div). */
name|uint8_t
name|lg_fill_div
index|[
name|NBINS
index|]
decl_stmt|;
name|tcache_bin_t
name|tbins_large
index|[
name|NSIZES
operator|-
name|NBINS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Linkage for list of available (previously used) explicit tcache IDs. */
end_comment

begin_struct
struct|struct
name|tcaches_s
block|{
union|union
block|{
name|tcache_t
modifier|*
name|tcache
decl_stmt|;
name|tcaches_t
modifier|*
name|next
decl_stmt|;
block|}
union|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_INTERNAL_TCACHE_STRUCTS_H */
end_comment

end_unit

