begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_INTERNAL_EXTENT_MMAP_EXTERNS_H
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_EXTENT_MMAP_EXTERNS_H
end_define

begin_decl_stmt
specifier|extern
name|bool
name|opt_retain
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
modifier|*
name|extent_alloc_mmap
parameter_list|(
name|void
modifier|*
name|new_addr
parameter_list|,
name|size_t
name|size
parameter_list|,
name|size_t
name|alignment
parameter_list|,
name|bool
modifier|*
name|zero
parameter_list|,
name|bool
modifier|*
name|commit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|extent_dalloc_mmap
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_INTERNAL_EXTENT_MMAP_EXTERNS_H */
end_comment

end_unit

