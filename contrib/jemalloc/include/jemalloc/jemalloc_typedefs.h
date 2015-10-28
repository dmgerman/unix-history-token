begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * void *  * chunk_alloc(void *new_addr, size_t size, size_t alignment, bool *zero,  *     bool *commit, unsigned arena_ind);  */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
function_decl|(
name|chunk_alloc_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|,
name|bool
modifier|*
parameter_list|,
name|bool
modifier|*
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * bool  * chunk_dalloc(void *chunk, size_t size, bool committed, unsigned arena_ind);  */
end_comment

begin_typedef
typedef|typedef
name|bool
function_decl|(
name|chunk_dalloc_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|bool
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * bool  * chunk_commit(void *chunk, size_t size, size_t offset, size_t length,  *     unsigned arena_ind);  */
end_comment

begin_typedef
typedef|typedef
name|bool
function_decl|(
name|chunk_commit_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * bool  * chunk_decommit(void *chunk, size_t size, size_t offset, size_t length,  *     unsigned arena_ind);  */
end_comment

begin_typedef
typedef|typedef
name|bool
function_decl|(
name|chunk_decommit_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * bool  * chunk_purge(void *chunk, size_t size, size_t offset, size_t length,  *     unsigned arena_ind);  */
end_comment

begin_typedef
typedef|typedef
name|bool
function_decl|(
name|chunk_purge_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * bool  * chunk_split(void *chunk, size_t size, size_t size_a, size_t size_b,  *     bool committed, unsigned arena_ind);  */
end_comment

begin_typedef
typedef|typedef
name|bool
function_decl|(
name|chunk_split_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|,
name|bool
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * bool  * chunk_merge(void *chunk_a, size_t size_a, void *chunk_b, size_t size_b,  *     bool committed, unsigned arena_ind);  */
end_comment

begin_typedef
typedef|typedef
name|bool
function_decl|(
name|chunk_merge_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|bool
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|chunk_alloc_t
modifier|*
name|alloc
decl_stmt|;
name|chunk_dalloc_t
modifier|*
name|dalloc
decl_stmt|;
name|chunk_commit_t
modifier|*
name|commit
decl_stmt|;
name|chunk_decommit_t
modifier|*
name|decommit
decl_stmt|;
name|chunk_purge_t
modifier|*
name|purge
decl_stmt|;
name|chunk_split_t
modifier|*
name|split
decl_stmt|;
name|chunk_merge_t
modifier|*
name|merge
decl_stmt|;
block|}
name|chunk_hooks_t
typedef|;
end_typedef

end_unit

