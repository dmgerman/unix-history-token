begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_TYPES
end_ifdef

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

begin_function_decl
name|void
modifier|*
name|huge_malloc
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|,
name|arena_t
modifier|*
name|arena
parameter_list|,
name|size_t
name|usize
parameter_list|,
name|bool
name|zero
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
name|huge_palloc
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|,
name|arena_t
modifier|*
name|arena
parameter_list|,
name|size_t
name|usize
parameter_list|,
name|size_t
name|alignment
parameter_list|,
name|bool
name|zero
parameter_list|,
name|tcache_t
modifier|*
name|tcache
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|huge_ralloc_no_move
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|oldsize
parameter_list|,
name|size_t
name|usize_min
parameter_list|,
name|size_t
name|usize_max
parameter_list|,
name|bool
name|zero
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|huge_ralloc
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|,
name|arena_t
modifier|*
name|arena
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|oldsize
parameter_list|,
name|size_t
name|usize
parameter_list|,
name|size_t
name|alignment
parameter_list|,
name|bool
name|zero
parameter_list|,
name|tcache_t
modifier|*
name|tcache
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_JET
end_ifdef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|huge_dalloc_junk_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|huge_dalloc_junk_t
modifier|*
name|huge_dalloc_junk
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|huge_dalloc
parameter_list|(
name|tsd_t
modifier|*
name|tsd
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|,
name|tcache_t
modifier|*
name|tcache
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|arena_t
modifier|*
name|huge_aalloc
parameter_list|(
specifier|const
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|huge_salloc
parameter_list|(
specifier|const
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|prof_tctx_t
modifier|*
name|huge_prof_tctx_get
parameter_list|(
specifier|const
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|huge_prof_tctx_set
parameter_list|(
specifier|const
name|void
modifier|*
name|ptr
parameter_list|,
name|prof_tctx_t
modifier|*
name|tctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|huge_prof_tctx_reset
parameter_list|(
specifier|const
name|void
modifier|*
name|ptr
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

