begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_INTERNAL_RTREE_CTX_H
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_RTREE_CTX_H
end_define

begin_comment
comment|/*  * Number of leafkey/leaf pairs to cache in L1 and L2 level respectively.  Each  * entry supports an entire leaf, so the cache hit rate is typically high even  * with a small number of entries.  In rare cases extent activity will straddle  * the boundary between two leaf nodes.  Furthermore, an arena may use a  * combination of dss and mmap.  Note that as memory usage grows past the amount  * that this cache can directly cover, the cache will become less effective if  * locality of reference is low, but the consequence is merely cache misses  * while traversing the tree nodes.  *  * The L1 direct mapped cache offers consistent and low cost on cache hit.  * However collision could affect hit rate negatively.  This is resolved by  * combining with a L2 LRU cache, which requires linear search and re-ordering  * on access but suffers no collision.  Note that, the cache will itself suffer  * cache misses if made overly large, plus the cost of linear search in the LRU  * cache.  */
end_comment

begin_define
define|#
directive|define
name|RTREE_CTX_LG_NCACHE
value|4
end_define

begin_define
define|#
directive|define
name|RTREE_CTX_NCACHE
value|(1<< RTREE_CTX_LG_NCACHE)
end_define

begin_define
define|#
directive|define
name|RTREE_CTX_NCACHE_L2
value|8
end_define

begin_comment
comment|/*  * Zero initializer required for tsd initialization only.  Proper initialization  * done via rtree_ctx_data_init().  */
end_comment

begin_define
define|#
directive|define
name|RTREE_CTX_ZERO_INITIALIZER
value|{{{0}}}
end_define

begin_typedef
typedef|typedef
name|struct
name|rtree_leaf_elm_s
name|rtree_leaf_elm_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|rtree_ctx_cache_elm_s
name|rtree_ctx_cache_elm_t
typedef|;
end_typedef

begin_struct
struct|struct
name|rtree_ctx_cache_elm_s
block|{
name|uintptr_t
name|leafkey
decl_stmt|;
name|rtree_leaf_elm_t
modifier|*
name|leaf
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|rtree_ctx_s
name|rtree_ctx_t
typedef|;
end_typedef

begin_struct
struct|struct
name|rtree_ctx_s
block|{
comment|/* Direct mapped cache. */
name|rtree_ctx_cache_elm_t
name|cache
index|[
name|RTREE_CTX_NCACHE
index|]
decl_stmt|;
comment|/* L2 LRU cache. */
name|rtree_ctx_cache_elm_t
name|l2_cache
index|[
name|RTREE_CTX_NCACHE_L2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|rtree_ctx_data_init
parameter_list|(
name|rtree_ctx_t
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_INTERNAL_RTREE_CTX_H */
end_comment

end_unit

