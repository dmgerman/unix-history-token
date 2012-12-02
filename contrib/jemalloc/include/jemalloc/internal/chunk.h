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
value|22
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

begin_comment
comment|/* Protects stats_chunks; currently not used for any other purpose. */
end_comment

begin_decl_stmt
specifier|extern
name|malloc_mutex_t
name|chunks_mtx
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Chunk statistics. */
end_comment

begin_decl_stmt
specifier|extern
name|chunk_stats_t
name|stats_chunks
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtree_t
modifier|*
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
name|size_t
name|map_bias
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of arena chunk header pages. */
end_comment

begin_decl_stmt
specifier|extern
name|size_t
name|arena_maxclass
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Max size class for arenas. */
end_comment

begin_function_decl
name|void
modifier|*
name|chunk_alloc
parameter_list|(
name|size_t
name|size
parameter_list|,
name|size_t
name|alignment
parameter_list|,
name|bool
name|base
parameter_list|,
name|bool
modifier|*
name|zero
parameter_list|,
name|dss_prec_t
name|dss_prec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|chunk_unmap
parameter_list|(
name|void
modifier|*
name|chunk
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|chunk_dealloc
parameter_list|(
name|void
modifier|*
name|chunk
parameter_list|,
name|size_t
name|size
parameter_list|,
name|bool
name|unmap
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
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|chunk_postfork_parent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|chunk_postfork_child
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

