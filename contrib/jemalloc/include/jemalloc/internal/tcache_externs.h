begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_INTERNAL_TCACHE_EXTERNS_H
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_TCACHE_EXTERNS_H
end_define

begin_include
include|#
directive|include
file|"jemalloc/internal/size_classes.h"
end_include

begin_decl_stmt
specifier|extern
name|bool
name|opt_tcache
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ssize_t
name|opt_lg_tcache_max
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tcache_bin_info_t
modifier|*
name|tcache_bin_info
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Number of tcache bins.  There are NBINS small-object bins, plus 0 or more  * large-object bins.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|nhbins
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Maximum cached size class. */
end_comment

begin_decl_stmt
specifier|extern
name|size_t
name|tcache_maxclass
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Explicit tcaches, managed via the tcache.{create,flush,destroy} mallctls and  * usable via the MALLOCX_TCACHE() flag.  The automatic per thread tcaches are  * completely disjoint from this data structure.  tcaches starts off as a sparse  * array, so it has no physical memory footprint until individual pages are  * touched.  This allows the entire array to be allocated the first time an  * explicit tcache is created without a disproportionate impact on memory usage.  */
end_comment

begin_decl_stmt
specifier|extern
name|tcaches_t
modifier|*
name|tcaches
decl_stmt|;
end_decl_stmt

begin_function_decl
name|size_t
name|tcache_salloc
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|,
specifier|const
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcache_event_hard
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|,
name|tcache_t
modifier|*
name|tcache
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|tcache_alloc_small_hard
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|,
name|arena_t
modifier|*
name|arena
parameter_list|,
name|tcache_t
modifier|*
name|tcache
parameter_list|,
name|tcache_bin_t
modifier|*
name|tbin
parameter_list|,
name|szind_t
name|binind
parameter_list|,
name|bool
modifier|*
name|tcache_success
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcache_bin_flush_small
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|,
name|tcache_t
modifier|*
name|tcache
parameter_list|,
name|tcache_bin_t
modifier|*
name|tbin
parameter_list|,
name|szind_t
name|binind
parameter_list|,
name|unsigned
name|rem
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcache_bin_flush_large
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|,
name|tcache_bin_t
modifier|*
name|tbin
parameter_list|,
name|szind_t
name|binind
parameter_list|,
name|unsigned
name|rem
parameter_list|,
name|tcache_t
modifier|*
name|tcache
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcache_arena_reassociate
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|,
name|tcache_t
modifier|*
name|tcache
parameter_list|,
name|arena_t
modifier|*
name|arena
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tcache_t
modifier|*
name|tcache_create_explicit
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcache_cleanup
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcache_stats_merge
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|,
name|tcache_t
modifier|*
name|tcache
parameter_list|,
name|arena_t
modifier|*
name|arena
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|tcaches_create
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|,
name|unsigned
modifier|*
name|r_ind
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcaches_flush
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
name|void
name|tcaches_destroy
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
name|bool
name|tcache_boot
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcache_arena_associate
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|,
name|tcache_t
modifier|*
name|tcache
parameter_list|,
name|arena_t
modifier|*
name|arena
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcache_prefork
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcache_postfork_parent
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcache_postfork_child
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tcache_flush
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|tsd_tcache_data_init
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|tsd_tcache_enabled_data_init
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_INTERNAL_TCACHE_EXTERNS_H */
end_comment

end_unit

