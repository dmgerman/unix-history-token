begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_INTERNAL_MUTEX_PROF_H
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_MUTEX_PROF_H
end_define

begin_include
include|#
directive|include
file|"jemalloc/internal/atomic.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/nstime.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/tsd_types.h"
end_include

begin_define
define|#
directive|define
name|MUTEX_PROF_GLOBAL_MUTEXES
define|\
value|OP(background_thread)						\     OP(ctl)								\     OP(prof)
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
define|#
directive|define
name|OP
parameter_list|(
name|mtx
parameter_list|)
value|global_prof_mutex_##mtx,
name|MUTEX_PROF_GLOBAL_MUTEXES
undef|#
directive|undef
name|OP
name|mutex_prof_num_global_mutexes
block|}
name|mutex_prof_global_ind_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MUTEX_PROF_ARENA_MUTEXES
define|\
value|OP(large)								\     OP(extent_avail)							\     OP(extents_dirty)							\     OP(extents_muzzy)							\     OP(extents_retained)						\     OP(decay_dirty)							\     OP(decay_muzzy)							\     OP(base)								\     OP(tcache_list)
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
define|#
directive|define
name|OP
parameter_list|(
name|mtx
parameter_list|)
value|arena_prof_mutex_##mtx,
name|MUTEX_PROF_ARENA_MUTEXES
undef|#
directive|undef
name|OP
name|mutex_prof_num_arena_mutexes
block|}
name|mutex_prof_arena_ind_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MUTEX_PROF_COUNTERS
define|\
value|OP(num_ops, uint64_t)						\     OP(num_wait, uint64_t)						\     OP(num_spin_acq, uint64_t)						\     OP(num_owner_switch, uint64_t)					\     OP(total_wait_time, uint64_t)					\     OP(max_wait_time, uint64_t)						\     OP(max_num_thds, uint32_t)
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
define|#
directive|define
name|OP
parameter_list|(
name|counter
parameter_list|,
name|type
parameter_list|)
value|mutex_counter_##counter,
name|MUTEX_PROF_COUNTERS
undef|#
directive|undef
name|OP
name|mutex_prof_num_counters
block|}
name|mutex_prof_counter_ind_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* 	 * Counters touched on the slow path, i.e. when there is lock 	 * contention.  We update them once we have the lock. 	 */
comment|/* Total time (in nano seconds) spent waiting on this mutex. */
name|nstime_t
name|tot_wait_time
decl_stmt|;
comment|/* Max time (in nano seconds) spent on a single lock operation. */
name|nstime_t
name|max_wait_time
decl_stmt|;
comment|/* # of times have to wait for this mutex (after spinning). */
name|uint64_t
name|n_wait_times
decl_stmt|;
comment|/* # of times acquired the mutex through local spinning. */
name|uint64_t
name|n_spin_acquired
decl_stmt|;
comment|/* Max # of threads waiting for the mutex at the same time. */
name|uint32_t
name|max_n_thds
decl_stmt|;
comment|/* Current # of threads waiting on the lock.  Atomic synced. */
name|atomic_u32_t
name|n_waiting_thds
decl_stmt|;
comment|/* 	 * Data touched on the fast path.  These are modified right after we 	 * grab the lock, so it's placed closest to the end (i.e. right before 	 * the lock) so that we have a higher chance of them being on the same 	 * cacheline. 	 */
comment|/* # of times the mutex holder is different than the previous one. */
name|uint64_t
name|n_owner_switches
decl_stmt|;
comment|/* Previous mutex holder, to facilitate n_owner_switches. */
name|tsdn_t
modifier|*
name|prev_owner
decl_stmt|;
comment|/* # of lock() operations in total. */
name|uint64_t
name|n_lock_ops
decl_stmt|;
block|}
name|mutex_prof_data_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_INTERNAL_MUTEX_PROF_H */
end_comment

end_unit

