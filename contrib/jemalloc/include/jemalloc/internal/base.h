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
name|base_alloc
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|base_stats_get
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|,
name|size_t
modifier|*
name|allocated
parameter_list|,
name|size_t
modifier|*
name|resident
parameter_list|,
name|size_t
modifier|*
name|mapped
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|base_boot
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|base_prefork
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|base_postfork_parent
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|base_postfork_child
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

