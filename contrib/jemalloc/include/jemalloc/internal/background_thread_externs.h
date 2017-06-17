begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_INTERNAL_BACKGROUND_THREAD_EXTERNS_H
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_BACKGROUND_THREAD_EXTERNS_H
end_define

begin_decl_stmt
specifier|extern
name|bool
name|opt_background_thread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|malloc_mutex_t
name|background_thread_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|atomic_b_t
name|background_thread_enabled_state
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|n_background_threads
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|background_thread_info_t
modifier|*
name|background_thread_info
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|can_enable_background_thread
decl_stmt|;
end_decl_stmt

begin_function_decl
name|bool
name|background_thread_create
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|,
name|unsigned
name|arena_ind
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|background_threads_enable
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|background_threads_disable
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|background_thread_interval_check
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|,
name|arena_t
modifier|*
name|arena
parameter_list|,
name|arena_decay_t
modifier|*
name|decay
parameter_list|,
name|size_t
name|npages_new
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|background_thread_prefork0
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|background_thread_prefork1
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|background_thread_postfork_parent
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|background_thread_postfork_child
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|background_thread_stats_read
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|,
name|background_thread_stats_t
modifier|*
name|stats
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|background_thread_ctl_init
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_PTHREAD_CREATE_WRAPPER
end_ifdef

begin_function_decl
specifier|extern
name|int
name|pthread_create_wrapper
parameter_list|(
name|pthread_t
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|pthread_attr_t
modifier|*
parameter_list|,
name|void
modifier|*
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|bool
name|background_thread_boot0
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|background_thread_boot1
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_INTERNAL_BACKGROUND_THREAD_EXTERNS_H */
end_comment

end_unit

