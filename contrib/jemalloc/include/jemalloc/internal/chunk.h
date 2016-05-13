begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_TYPES
end_ifdef

begin_comment
comment|/*  * Size and alignment of memory chunks that are allocated by the OS's virtual  * memory system.  */
end_comment

begin_define
define|#
directive|define
name|LG_CHUNK_DEFAULT
value|21
end_define

begin_comment
comment|/* Return the chunk address for allocation address a. */
end_comment

begin_define
define|#
directive|define
name|CHUNK_ADDR2BASE
parameter_list|(
name|a
parameter_list|)
define|\
value|((void *)((uintptr_t)(a)& ~chunksize_mask))
end_define

begin_comment
comment|/* Return the chunk offset of address a. */
end_comment

begin_define
define|#
directive|define
name|CHUNK_ADDR2OFFSET
parameter_list|(
name|a
parameter_list|)
define|\
value|((size_t)((uintptr_t)(a)& chunksize_mask))
end_define

begin_comment
comment|/* Return the smallest chunk multiple that is>= s. */
end_comment

begin_define
define|#
directive|define
name|CHUNK_CEILING
parameter_list|(
name|s
parameter_list|)
define|\
value|(((s) + chunksize_mask)& ~chunksize_mask)
end_define

begin_define
define|#
directive|define
name|CHUNK_HOOKS_INITIALIZER
value|{					\     NULL,								\     NULL,								\     NULL,								\     NULL,								\     NULL,								\     NULL,								\     NULL								\ }
end_define

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

begin_decl_stmt
specifier|extern
name|size_t
name|opt_lg_chunk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|opt_dss
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtree_t
name|chunks_rtree
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|chunksize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|size_t
name|chunksize_mask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* (chunksize - 1). */
end_comment

begin_decl_stmt
specifier|extern
name|size_t
name|chunk_npages
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|chunk_hooks_t
name|chunk_hooks_default
decl_stmt|;
end_decl_stmt

begin_function_decl
name|chunk_hooks_t
name|chunk_hooks_get
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|,
name|arena_t
modifier|*
name|arena
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|chunk_hooks_t
name|chunk_hooks_set
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|,
name|arena_t
modifier|*
name|arena
parameter_list|,
specifier|const
name|chunk_hooks_t
modifier|*
name|chunk_hooks
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|chunk_register
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|,
specifier|const
name|void
modifier|*
name|chunk
parameter_list|,
specifier|const
name|extent_node_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|chunk_deregister
parameter_list|(
specifier|const
name|void
modifier|*
name|chunk
parameter_list|,
specifier|const
name|extent_node_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|chunk_alloc_base
parameter_list|(
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|chunk_alloc_cache
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|,
name|arena_t
modifier|*
name|arena
parameter_list|,
name|chunk_hooks_t
modifier|*
name|chunk_hooks
parameter_list|,
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
name|dalloc_node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|chunk_alloc_wrapper
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|,
name|arena_t
modifier|*
name|arena
parameter_list|,
name|chunk_hooks_t
modifier|*
name|chunk_hooks
parameter_list|,
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
name|void
name|chunk_dalloc_cache
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|,
name|arena_t
modifier|*
name|arena
parameter_list|,
name|chunk_hooks_t
modifier|*
name|chunk_hooks
parameter_list|,
name|void
modifier|*
name|chunk
parameter_list|,
name|size_t
name|size
parameter_list|,
name|bool
name|committed
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|chunk_dalloc_wrapper
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|,
name|arena_t
modifier|*
name|arena
parameter_list|,
name|chunk_hooks_t
modifier|*
name|chunk_hooks
parameter_list|,
name|void
modifier|*
name|chunk
parameter_list|,
name|size_t
name|size
parameter_list|,
name|bool
name|zeroed
parameter_list|,
name|bool
name|committed
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|chunk_purge_wrapper
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|,
name|arena_t
modifier|*
name|arena
parameter_list|,
name|chunk_hooks_t
modifier|*
name|chunk_hooks
parameter_list|,
name|void
modifier|*
name|chunk
parameter_list|,
name|size_t
name|size
parameter_list|,
name|size_t
name|offset
parameter_list|,
name|size_t
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|chunk_boot
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|chunk_prefork
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|chunk_postfork_parent
parameter_list|(
name|tsdn_t
modifier|*
name|tsdn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|chunk_postfork_child
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

begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_ENABLE_INLINE
end_ifndef

begin_function_decl
name|extent_node_t
modifier|*
name|chunk_lookup
parameter_list|(
specifier|const
name|void
modifier|*
name|chunk
parameter_list|,
name|bool
name|dependent
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|JEMALLOC_ENABLE_INLINE
argument_list|)
operator|||
name|defined
argument_list|(
name|JEMALLOC_CHUNK_C_
argument_list|)
operator|)
end_if

begin_function
name|JEMALLOC_INLINE
name|extent_node_t
modifier|*
name|chunk_lookup
parameter_list|(
specifier|const
name|void
modifier|*
name|ptr
parameter_list|,
name|bool
name|dependent
parameter_list|)
block|{
return|return
operator|(
name|rtree_get
argument_list|(
operator|&
name|chunks_rtree
argument_list|,
operator|(
name|uintptr_t
operator|)
name|ptr
argument_list|,
name|dependent
argument_list|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

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

begin_include
include|#
directive|include
file|"jemalloc/internal/chunk_dss.h"
end_include

begin_include
include|#
directive|include
file|"jemalloc/internal/chunk_mmap.h"
end_include

end_unit

