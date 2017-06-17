begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_INTERNAL_STATS_TSD_H
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_STATS_TSD_H
end_define

begin_typedef
typedef|typedef
struct|struct
name|tcache_bin_stats_s
block|{
comment|/* 	 * Number of allocation requests that corresponded to the size of this 	 * bin. 	 */
name|uint64_t
name|nrequests
decl_stmt|;
block|}
name|tcache_bin_stats_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_INTERNAL_STATS_TSD_H */
end_comment

end_unit

