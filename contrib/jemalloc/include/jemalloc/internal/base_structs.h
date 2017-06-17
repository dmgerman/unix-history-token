begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_INTERNAL_BASE_STRUCTS_H
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_BASE_STRUCTS_H
end_define

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
file|"jemalloc/internal/size_classes.h"
end_include

begin_comment
comment|/* Embedded at the beginning of every block of base-managed virtual memory. */
end_comment

begin_struct
struct|struct
name|base_block_s
block|{
comment|/* Total size of block's virtual memory mapping. */
name|size_t
name|size
decl_stmt|;
comment|/* Next block in list of base's blocks. */
name|base_block_t
modifier|*
name|next
decl_stmt|;
comment|/* Tracks unused trailing space. */
name|extent_t
name|extent
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|base_s
block|{
comment|/* Associated arena's index within the arenas array. */
name|unsigned
name|ind
decl_stmt|;
comment|/* 	 * User-configurable extent hook functions.  Points to an 	 * extent_hooks_t. 	 */
name|atomic_p_t
name|extent_hooks
decl_stmt|;
comment|/* Protects base_alloc() and base_stats_get() operations. */
name|malloc_mutex_t
name|mtx
decl_stmt|;
comment|/* 	 * Most recent size class in the series of increasingly large base 	 * extents.  Logarithmic spacing between subsequent allocations ensures 	 * that the total number of distinct mappings remains small. 	 */
name|pszind_t
name|pind_last
decl_stmt|;
comment|/* Serial number generation state. */
name|size_t
name|extent_sn_next
decl_stmt|;
comment|/* Chain of all blocks associated with base. */
name|base_block_t
modifier|*
name|blocks
decl_stmt|;
comment|/* Heap of extents that track unused trailing space within blocks. */
name|extent_heap_t
name|avail
index|[
name|NSIZES
index|]
decl_stmt|;
comment|/* Stats, only maintained if config_stats. */
name|size_t
name|allocated
decl_stmt|;
name|size_t
name|resident
decl_stmt|;
name|size_t
name|mapped
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_INTERNAL_BASE_STRUCTS_H */
end_comment

end_unit

