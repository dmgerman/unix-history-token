begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_INTERNAL_BACKGROUND_THREAD_STRUCTS_H
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_BACKGROUND_THREAD_STRUCTS_H
end_define

begin_comment
comment|/* This file really combines "structs" and "types", but only transitionally. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|JEMALLOC_BACKGROUND_THREAD
argument_list|)
operator|||
name|defined
argument_list|(
name|JEMALLOC_LAZY_LOCK
argument_list|)
end_if

begin_define
define|#
directive|define
name|JEMALLOC_PTHREAD_CREATE_WRAPPER
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BACKGROUND_THREAD_INDEFINITE_SLEEP
value|UINT64_MAX
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|background_thread_stopped
block|,
name|background_thread_started
block|,
comment|/* Thread waits on the global lock when paused (for arena_reset). */
name|background_thread_paused
block|, }
name|background_thread_state_t
typedef|;
end_typedef

begin_struct
struct|struct
name|background_thread_info_s
block|{
ifdef|#
directive|ifdef
name|JEMALLOC_BACKGROUND_THREAD
comment|/* Background thread is pthread specific. */
name|pthread_t
name|thread
decl_stmt|;
name|pthread_cond_t
name|cond
decl_stmt|;
endif|#
directive|endif
name|malloc_mutex_t
name|mtx
decl_stmt|;
name|background_thread_state_t
name|state
decl_stmt|;
comment|/* When true, it means no wakeup scheduled. */
name|atomic_b_t
name|indefinite_sleep
decl_stmt|;
comment|/* Next scheduled wakeup time (absolute time in ns). */
name|nstime_t
name|next_wakeup
decl_stmt|;
comment|/* 	 *  Since the last background thread run, newly added number of pages 	 *  that need to be purged by the next wakeup.  This is adjusted on 	 *  epoch advance, and is used to determine whether we should signal the 	 *  background thread to wake up earlier. 	 */
name|size_t
name|npages_to_purge_new
decl_stmt|;
comment|/* Stats: total number of runs since started. */
name|uint64_t
name|tot_n_runs
decl_stmt|;
comment|/* Stats: total sleep time since started. */
name|nstime_t
name|tot_sleep_time
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|background_thread_info_s
name|background_thread_info_t
typedef|;
end_typedef

begin_struct
struct|struct
name|background_thread_stats_s
block|{
name|size_t
name|num_threads
decl_stmt|;
name|uint64_t
name|num_runs
decl_stmt|;
name|nstime_t
name|run_interval
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|background_thread_stats_s
name|background_thread_stats_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_INTERNAL_BACKGROUND_THREAD_STRUCTS_H */
end_comment

end_unit

