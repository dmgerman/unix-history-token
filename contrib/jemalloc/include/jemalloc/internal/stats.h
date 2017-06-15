begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_INTERNAL_STATS_H
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_STATS_H
end_define

begin_include
include|#
directive|include
file|"jemalloc/internal/atomic.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/mutex_prof.h"
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

begin_include
include|#
directive|include
file|"jemalloc/internal/stats_tsd.h"
end_include

begin_comment
comment|/*  OPTION(opt,		var_name,	default,	set_value_to) */
end_comment

begin_define
define|#
directive|define
name|STATS_PRINT_OPTIONS
define|\
value|OPTION('J',		json,		false,		true)		\     OPTION('g',		general,	true,		false)		\     OPTION('m',		merged,		config_stats,	false)		\     OPTION('d',		destroyed,	config_stats,	false)		\     OPTION('a',		unmerged,	config_stats,	false)		\     OPTION('b',		bins,		true,		false)		\     OPTION('l',		large,		true,		false)		\     OPTION('x',		mutex,		true,		false)
end_define

begin_enum
enum|enum
block|{
define|#
directive|define
name|OPTION
parameter_list|(
name|o
parameter_list|,
name|v
parameter_list|,
name|d
parameter_list|,
name|s
parameter_list|)
value|stats_print_option_num_##v,
name|STATS_PRINT_OPTIONS
undef|#
directive|undef
name|OPTION
name|stats_print_tot_num_options
block|}
enum|;
end_enum

begin_comment
comment|/* Options for stats_print. */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|opt_stats_print
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|opt_stats_print_opts
index|[
name|stats_print_tot_num_options
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Implements je_malloc_stats_print. */
end_comment

begin_function_decl
name|void
name|stats_print
parameter_list|(
name|void
function_decl|(
modifier|*
name|write_cb
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

begin_comment
comment|/*  * In those architectures that support 64-bit atomics, we use atomic updates for  * our 64-bit values.  Otherwise, we use a plain uint64_t and synchronize  * externally.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_ATOMIC_U64
end_ifdef

begin_typedef
typedef|typedef
name|atomic_u64_t
name|arena_stats_u64_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Must hold the arena stats mutex while reading atomically. */
end_comment

begin_typedef
typedef|typedef
name|uint64_t
name|arena_stats_u64_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|malloc_bin_stats_s
block|{
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
comment|/* 	 * Current number of regions of this size class, including regions 	 * currently cached by tcache. 	 */
name|size_t
name|curregs
decl_stmt|;
comment|/* Number of tcache fills from this bin. */
name|uint64_t
name|nfills
decl_stmt|;
comment|/* Number of tcache flushes to this bin. */
name|uint64_t
name|nflushes
decl_stmt|;
comment|/* Total number of slabs created for this bin's size class. */
name|uint64_t
name|nslabs
decl_stmt|;
comment|/* 	 * Total number of slabs reused by extracting them from the slabs heap 	 * for this bin's size class. 	 */
name|uint64_t
name|reslabs
decl_stmt|;
comment|/* Current number of slabs in this bin. */
name|size_t
name|curslabs
decl_stmt|;
name|mutex_prof_data_t
name|mutex_data
decl_stmt|;
block|}
name|malloc_bin_stats_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|malloc_large_stats_s
block|{
comment|/* 	 * Total number of allocation/deallocation requests served directly by 	 * the arena. 	 */
name|arena_stats_u64_t
name|nmalloc
decl_stmt|;
name|arena_stats_u64_t
name|ndalloc
decl_stmt|;
comment|/* 	 * Number of allocation requests that correspond to this size class. 	 * This includes requests served by tcache, though tcache only 	 * periodically merges into this counter. 	 */
name|arena_stats_u64_t
name|nrequests
decl_stmt|;
comment|/* Partially derived. */
comment|/* Current number of allocations of this size class. */
name|size_t
name|curlextents
decl_stmt|;
comment|/* Derived. */
block|}
name|malloc_large_stats_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|decay_stats_s
block|{
comment|/* Total number of purge sweeps. */
name|arena_stats_u64_t
name|npurge
decl_stmt|;
comment|/* Total number of madvise calls made. */
name|arena_stats_u64_t
name|nmadvise
decl_stmt|;
comment|/* Total number of pages purged. */
name|arena_stats_u64_t
name|purged
decl_stmt|;
block|}
name|decay_stats_t
typedef|;
end_typedef

begin_comment
comment|/*  * Arena stats.  Note that fields marked "derived" are not directly maintained  * within the arena code; rather their values are derived during stats merge  * requests.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|arena_stats_s
block|{
ifndef|#
directive|ifndef
name|JEMALLOC_ATOMIC_U64
name|malloc_mutex_t
name|mtx
decl_stmt|;
endif|#
directive|endif
comment|/* Number of bytes currently mapped, excluding retained memory. */
name|atomic_zu_t
name|mapped
decl_stmt|;
comment|/* Partially derived. */
comment|/* 	 * Number of unused virtual memory bytes currently retained.  Retained 	 * bytes are technically mapped (though always decommitted or purged), 	 * but they are excluded from the mapped statistic (above). 	 */
name|atomic_zu_t
name|retained
decl_stmt|;
comment|/* Derived. */
name|decay_stats_t
name|decay_dirty
decl_stmt|;
name|decay_stats_t
name|decay_muzzy
decl_stmt|;
name|atomic_zu_t
name|base
decl_stmt|;
comment|/* Derived. */
name|atomic_zu_t
name|internal
decl_stmt|;
name|atomic_zu_t
name|resident
decl_stmt|;
comment|/* Derived. */
name|atomic_zu_t
name|allocated_large
decl_stmt|;
comment|/* Derived. */
name|arena_stats_u64_t
name|nmalloc_large
decl_stmt|;
comment|/* Derived. */
name|arena_stats_u64_t
name|ndalloc_large
decl_stmt|;
comment|/* Derived. */
name|arena_stats_u64_t
name|nrequests_large
decl_stmt|;
comment|/* Derived. */
comment|/* Number of bytes cached in tcache associated with this arena. */
name|atomic_zu_t
name|tcache_bytes
decl_stmt|;
comment|/* Derived. */
name|mutex_prof_data_t
name|mutex_prof_data
index|[
name|mutex_prof_num_arena_mutexes
index|]
decl_stmt|;
comment|/* One element for each large size class. */
name|malloc_large_stats_t
name|lstats
index|[
name|NSIZES
operator|-
name|NBINS
index|]
decl_stmt|;
comment|/* Arena uptime. */
name|nstime_t
name|uptime
decl_stmt|;
block|}
name|arena_stats_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_INTERNAL_STATS_H */
end_comment

end_unit

