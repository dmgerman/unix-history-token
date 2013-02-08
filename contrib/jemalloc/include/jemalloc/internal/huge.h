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

begin_comment
comment|/* Huge allocation statistics. */
end_comment

begin_decl_stmt
specifier|extern
name|uint64_t
name|huge_nmalloc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint64_t
name|huge_ndalloc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|huge_allocated
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Protects chunk-related data structures. */
end_comment

begin_decl_stmt
specifier|extern
name|malloc_mutex_t
name|huge_mtx
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
modifier|*
name|huge_malloc
parameter_list|(
name|size_t
name|size
parameter_list|,
name|bool
name|zero
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|huge_palloc
parameter_list|(
name|size_t
name|size
parameter_list|,
name|size_t
name|alignment
parameter_list|,
name|bool
name|zero
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|huge_ralloc_no_move
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|oldsize
parameter_list|,
name|size_t
name|size
parameter_list|,
name|size_t
name|extra
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|huge_ralloc
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|oldsize
parameter_list|,
name|size_t
name|size
parameter_list|,
name|size_t
name|extra
parameter_list|,
name|size_t
name|alignment
parameter_list|,
name|bool
name|zero
parameter_list|,
name|bool
name|try_tcache_dalloc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|huge_dalloc
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|bool
name|unmap
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
name|prof_ctx_t
modifier|*
name|huge_prof_ctx_get
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
name|huge_prof_ctx_set
parameter_list|(
specifier|const
name|void
modifier|*
name|ptr
parameter_list|,
name|prof_ctx_t
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|huge_boot
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|huge_prefork
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|huge_postfork_parent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|huge_postfork_child
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

