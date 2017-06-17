begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_INTERNAL_PROF_EXTERNS_H
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_PROF_EXTERNS_H
end_define

begin_include
include|#
directive|include
file|"jemalloc/internal/mutex.h"
end_include

begin_decl_stmt
specifier|extern
name|malloc_mutex_t
name|bt2gctx_mtx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|opt_prof
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|opt_prof_active
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|opt_prof_thread_active_init
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|opt_lg_prof_sample
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Mean bytes between samples. */
end_comment

begin_decl_stmt
specifier|extern
name|ssize_t
name|opt_lg_prof_interval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lg(prof_interval). */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|opt_prof_gdump
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* High-water memory dumping. */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|opt_prof_final
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Final profile dumping. */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|opt_prof_leak
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Dump leak summary at exit. */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|opt_prof_accum
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Report cumulative bytes. */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|opt_prof_prefix
index|[
comment|/* Minimize memory bloat for non-prof builds. */
ifdef|#
directive|ifdef
name|JEMALLOC_PROF
name|PATH_MAX
operator|+
endif|#
directive|endif
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Accessed via prof_active_[gs]et{_unlocked,}(). */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|prof_active
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Accessed via prof_gdump_[gs]et{_unlocked,}(). */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|prof_gdump_val
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Profile dump interval, measured in bytes allocated.  Each arena triggers a  * profile dump when it reaches this threshold.  The effect is that the  * interval between profile dumps averages prof_interval, though the actual  * interval between dumps will tend to be sporadic, and the interval will be a  * maximum of approximately (prof_interval * narenas).  */
end_comment

begin_decl_stmt
specifier|extern
name|uint64_t
name|prof_interval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Initialized as opt_lg_prof_sample, and potentially modified during profiling  * resets.  */
end_comment

begin_decl_stmt
specifier|extern
name|size_t
name|lg_prof_sample
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|prof_alloc_rollback
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|,
name|prof_tctx_t
modifier|*
name|tctx
parameter_list|,
name|bool
name|updated
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prof_malloc_sample_object
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|,
specifier|const
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|usize
parameter_list|,
name|prof_tctx_t
modifier|*
name|tctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prof_free_sampled_object
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|,
name|size_t
name|usize
parameter_list|,
name|prof_tctx_t
modifier|*
name|tctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bt_init
parameter_list|(
name|prof_bt_t
modifier|*
name|bt
parameter_list|,
name|void
modifier|*
modifier|*
name|vec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prof_backtrace
parameter_list|(
name|prof_bt_t
modifier|*
name|bt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|prof_tctx_t
modifier|*
name|prof_lookup
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|,
name|prof_bt_t
modifier|*
name|bt
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_JET
end_ifdef

begin_function_decl
name|size_t
name|prof_tdata_count
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|prof_bt_count
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
function_decl|(
name|prof_dump_open_t
function_decl|)
parameter_list|(
name|bool
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|prof_dump_open_t
modifier|*
name|JET_MUTABLE
name|prof_dump_open
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|bool
function_decl|(
name|prof_dump_header_t
function_decl|)
parameter_list|(
name|tsdn_t
modifier|*
parameter_list|,
name|bool
parameter_list|,
specifier|const
name|prof_cnt_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|prof_dump_header_t
modifier|*
name|JET_MUTABLE
name|prof_dump_header
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_JET
end_ifdef

begin_function_decl
name|void
name|prof_cnt_all
parameter_list|(
name|uint64_t
modifier|*
name|curobjs
parameter_list|,
name|uint64_t
modifier|*
name|curbytes
parameter_list|,
name|uint64_t
modifier|*
name|accumobjs
parameter_list|,
name|uint64_t
modifier|*
name|accumbytes
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|bool
name|prof_accum_init
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|,
name|prof_accum_t
modifier|*
name|prof_accum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prof_idump
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|prof_mdump
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prof_gdump
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|prof_tdata_t
modifier|*
name|prof_tdata_init
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|prof_tdata_t
modifier|*
name|prof_tdata_reinit
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|,
name|prof_tdata_t
modifier|*
name|tdata
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prof_reset
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|,
name|size_t
name|lg_sample
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prof_tdata_cleanup
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|prof_active_get
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|prof_active_set
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|,
name|bool
name|active
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|prof_thread_name_get
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|prof_thread_name_set
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|,
specifier|const
name|char
modifier|*
name|thread_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|prof_thread_active_get
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|prof_thread_active_set
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|,
name|bool
name|active
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|prof_thread_active_init_get
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|prof_thread_active_init_set
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|,
name|bool
name|active_init
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|prof_gdump_get
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|prof_gdump_set
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|,
name|bool
name|active
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prof_boot0
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prof_boot1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|prof_boot2
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prof_prefork0
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prof_prefork1
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prof_postfork_parent
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prof_postfork_child
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prof_sample_threshold_update
parameter_list|(
name|prof_tdata_t
modifier|*
name|tdata
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_INTERNAL_PROF_EXTERNS_H */
end_comment

end_unit

