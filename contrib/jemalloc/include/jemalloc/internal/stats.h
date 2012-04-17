begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_TYPES
end_ifdef

begin_typedef
typedef|typedef
name|struct
name|tcache_bin_stats_s
name|tcache_bin_stats_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|malloc_bin_stats_s
name|malloc_bin_stats_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|malloc_large_stats_s
name|malloc_large_stats_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|arena_stats_s
name|arena_stats_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|chunk_stats_s
name|chunk_stats_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_H_TYPES */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_STRUCTS
end_ifdef

begin_struct
struct|struct
name|tcache_bin_stats_s
block|{
comment|/* 	 * Number of allocation requests that corresponded to the size of this 	 * bin. 	 */
name|uint64_t
name|nrequests
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|malloc_bin_stats_s
block|{
comment|/* 	 * Current number of bytes allocated, including objects currently 	 * cached by tcache. 	 */
name|size_t
name|allocated
decl_stmt|;
comment|/* 	 * Total number of allocation/deallocation requests served directly by 	 * the bin.  Note that tcache may allocate an object, then recycle it 	 * many times, resulting many increments to nrequests, but only one 	 * each to nmalloc and ndalloc. 	 */
name|uint64_t
name|nmalloc
decl_stmt|;
name|uint64_t
name|ndalloc
decl_stmt|;
comment|/* 	 * Number of allocation requests that correspond to the size of this 	 * bin.  This includes requests served by tcache, though tcache only 	 * periodically merges into this counter. 	 */
name|uint64_t
name|nrequests
decl_stmt|;
comment|/* Number of tcache fills from this bin. */
name|uint64_t
name|nfills
decl_stmt|;
comment|/* Number of tcache flushes to this bin. */
name|uint64_t
name|nflushes
decl_stmt|;
comment|/* Total number of runs created for this bin's size class. */
name|uint64_t
name|nruns
decl_stmt|;
comment|/* 	 * Total number of runs reused by extracting them from the runs tree for 	 * this bin's size class. 	 */
name|uint64_t
name|reruns
decl_stmt|;
comment|/* Current number of runs in this bin. */
name|size_t
name|curruns
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|malloc_large_stats_s
block|{
comment|/* 	 * Total number of allocation/deallocation requests served directly by 	 * the arena.  Note that tcache may allocate an object, then recycle it 	 * many times, resulting many increments to nrequests, but only one 	 * each to nmalloc and ndalloc. 	 */
name|uint64_t
name|nmalloc
decl_stmt|;
name|uint64_t
name|ndalloc
decl_stmt|;
comment|/* 	 * Number of allocation requests that correspond to this size class. 	 * This includes requests served by tcache, though tcache only 	 * periodically merges into this counter. 	 */
name|uint64_t
name|nrequests
decl_stmt|;
comment|/* Current number of runs of this size class. */
name|size_t
name|curruns
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|arena_stats_s
block|{
comment|/* Number of bytes currently mapped. */
name|size_t
name|mapped
decl_stmt|;
comment|/* 	 * Total number of purge sweeps, total number of madvise calls made, 	 * and total pages purged in order to keep dirty unused memory under 	 * control. 	 */
name|uint64_t
name|npurge
decl_stmt|;
name|uint64_t
name|nmadvise
decl_stmt|;
name|uint64_t
name|purged
decl_stmt|;
comment|/* Per-size-category statistics. */
name|size_t
name|allocated_large
decl_stmt|;
name|uint64_t
name|nmalloc_large
decl_stmt|;
name|uint64_t
name|ndalloc_large
decl_stmt|;
name|uint64_t
name|nrequests_large
decl_stmt|;
comment|/* 	 * One element for each possible size class, including sizes that 	 * overlap with bin size classes.  This is necessary because ipalloc() 	 * sometimes has to use such large objects in order to assure proper 	 * alignment. 	 */
name|malloc_large_stats_t
modifier|*
name|lstats
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|chunk_stats_s
block|{
comment|/* Number of chunks that were allocated. */
name|uint64_t
name|nchunks
decl_stmt|;
comment|/* High-water mark for number of chunks allocated. */
name|size_t
name|highchunks
decl_stmt|;
comment|/* 	 * Current number of chunks allocated.  This value isn't maintained for 	 * any other purpose, so keep track of it in order to be able to set 	 * highchunks. 	 */
name|size_t
name|curchunks
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_H_STRUCTS */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_EXTERNS
end_ifdef

begin_decl_stmt
specifier|extern
name|bool
name|opt_stats_print
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|stats_cactive
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|stats_print
parameter_list|(
name|void
function_decl|(
modifier|*
name|write
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|cbopaque
parameter_list|,
specifier|const
name|char
modifier|*
name|opts
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_H_EXTERNS */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_INLINES
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_ENABLE_INLINE
end_ifndef

begin_function_decl
name|size_t
name|stats_cactive_get
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stats_cactive_add
parameter_list|(
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stats_cactive_sub
parameter_list|(
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|JEMALLOC_ENABLE_INLINE
argument_list|)
operator|||
name|defined
argument_list|(
name|JEMALLOC_STATS_C_
argument_list|)
operator|)
end_if

begin_function
name|JEMALLOC_INLINE
name|size_t
name|stats_cactive_get
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|atomic_read_z
argument_list|(
operator|&
name|stats_cactive
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|JEMALLOC_INLINE
name|void
name|stats_cactive_add
parameter_list|(
name|size_t
name|size
parameter_list|)
block|{
name|atomic_add_z
argument_list|(
operator|&
name|stats_cactive
argument_list|,
name|size
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|JEMALLOC_INLINE
name|void
name|stats_cactive_sub
parameter_list|(
name|size_t
name|size
parameter_list|)
block|{
name|atomic_sub_z
argument_list|(
operator|&
name|stats_cactive
argument_list|,
name|size
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_H_INLINES */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

end_unit

