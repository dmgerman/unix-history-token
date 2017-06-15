begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_INTERNAL_EXTERNS_H
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_EXTERNS_H
end_define

begin_include
include|#
directive|include
file|"jemalloc/internal/atomic.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/size_classes.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/tsd_types.h"
end_include

begin_comment
comment|/* TSD checks this to set thread local slow state accordingly. */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|malloc_slow
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Run-time options. */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|opt_abort
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|opt_abort_conf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|opt_junk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|opt_junk_alloc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|opt_junk_free
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|opt_utrace
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|opt_xmalloc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|opt_zero
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|opt_narenas
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of CPUs. */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|ncpus
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of arenas used for automatic multiplexing of threads and arenas. */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|narenas_auto
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Arenas that are used to service external requests.  Not all elements of the  * arenas array are necessarily used; arenas are created lazily as needed.  */
end_comment

begin_decl_stmt
specifier|extern
name|atomic_p_t
name|arenas
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
modifier|*
name|a0malloc
parameter_list|(
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|a0dalloc
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|bootstrap_malloc
parameter_list|(
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|bootstrap_calloc
parameter_list|(
name|size_t
name|num
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bootstrap_free
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arena_set
parameter_list|(
name|unsigned
name|ind
parameter_list|,
name|arena_t
modifier|*
name|arena
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|narenas_total_get
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|arena_t
modifier|*
name|arena_init
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|,
name|unsigned
name|ind
parameter_list|,
name|extent_hooks_t
modifier|*
name|extent_hooks
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|arena_tdata_t
modifier|*
name|arena_tdata_get_hard
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|,
name|unsigned
name|ind
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|arena_t
modifier|*
name|arena_choose_hard
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|,
name|bool
name|internal
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arena_migrate
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|,
name|unsigned
name|oldind
parameter_list|,
name|unsigned
name|newind
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|iarena_cleanup
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arena_cleanup
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arenas_tdata_cleanup
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|jemalloc_prefork
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|jemalloc_postfork_parent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|jemalloc_postfork_child
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|malloc_initialized
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_INTERNAL_EXTERNS_H */
end_comment

end_unit

