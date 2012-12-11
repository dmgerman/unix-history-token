begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_TYPES
end_ifdef

begin_typedef
typedef|typedef
name|struct
name|ctl_node_s
name|ctl_node_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ctl_named_node_s
name|ctl_named_node_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ctl_indexed_node_s
name|ctl_indexed_node_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ctl_arena_stats_s
name|ctl_arena_stats_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ctl_stats_s
name|ctl_stats_t
typedef|;
end_typedef

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

begin_struct
struct|struct
name|ctl_node_s
block|{
name|bool
name|named
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ctl_named_node_s
block|{
name|struct
name|ctl_node_s
name|node
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* If (nchildren == 0), this is a terminal node. */
name|unsigned
name|nchildren
decl_stmt|;
specifier|const
name|ctl_node_t
modifier|*
name|children
decl_stmt|;
name|int
function_decl|(
modifier|*
name|ctl
function_decl|)
parameter_list|(
specifier|const
name|size_t
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ctl_indexed_node_s
block|{
name|struct
name|ctl_node_s
name|node
decl_stmt|;
specifier|const
name|ctl_named_node_t
modifier|*
function_decl|(
modifier|*
name|index
function_decl|)
parameter_list|(
specifier|const
name|size_t
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ctl_arena_stats_s
block|{
name|bool
name|initialized
decl_stmt|;
name|unsigned
name|nthreads
decl_stmt|;
specifier|const
name|char
modifier|*
name|dss
decl_stmt|;
name|size_t
name|pactive
decl_stmt|;
name|size_t
name|pdirty
decl_stmt|;
name|arena_stats_t
name|astats
decl_stmt|;
comment|/* Aggregate stats for small size classes, based on bin stats. */
name|size_t
name|allocated_small
decl_stmt|;
name|uint64_t
name|nmalloc_small
decl_stmt|;
name|uint64_t
name|ndalloc_small
decl_stmt|;
name|uint64_t
name|nrequests_small
decl_stmt|;
name|malloc_bin_stats_t
name|bstats
index|[
name|NBINS
index|]
decl_stmt|;
name|malloc_large_stats_t
modifier|*
name|lstats
decl_stmt|;
comment|/* nlclasses elements. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ctl_stats_s
block|{
name|size_t
name|allocated
decl_stmt|;
name|size_t
name|active
decl_stmt|;
name|size_t
name|mapped
decl_stmt|;
struct|struct
block|{
name|size_t
name|current
decl_stmt|;
comment|/* stats_chunks.curchunks */
name|uint64_t
name|total
decl_stmt|;
comment|/* stats_chunks.nchunks */
name|size_t
name|high
decl_stmt|;
comment|/* stats_chunks.highchunks */
block|}
name|chunks
struct|;
struct|struct
block|{
name|size_t
name|allocated
decl_stmt|;
comment|/* huge_allocated */
name|uint64_t
name|nmalloc
decl_stmt|;
comment|/* huge_nmalloc */
name|uint64_t
name|ndalloc
decl_stmt|;
comment|/* huge_ndalloc */
block|}
name|huge
struct|;
name|unsigned
name|narenas
decl_stmt|;
name|ctl_arena_stats_t
modifier|*
name|arenas
decl_stmt|;
comment|/* (narenas + 1) elements. */
block|}
struct|;
end_struct

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
name|int
name|ctl_byname
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|void
modifier|*
name|oldp
parameter_list|,
name|size_t
modifier|*
name|oldlenp
parameter_list|,
name|void
modifier|*
name|newp
parameter_list|,
name|size_t
name|newlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ctl_nametomib
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|size_t
modifier|*
name|mibp
parameter_list|,
name|size_t
modifier|*
name|miblenp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ctl_bymib
parameter_list|(
specifier|const
name|size_t
modifier|*
name|mib
parameter_list|,
name|size_t
name|miblen
parameter_list|,
name|void
modifier|*
name|oldp
parameter_list|,
name|size_t
modifier|*
name|oldlenp
parameter_list|,
name|void
modifier|*
name|newp
parameter_list|,
name|size_t
name|newlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ctl_boot
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ctl_prefork
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ctl_postfork_parent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ctl_postfork_child
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|xmallctl
parameter_list|(
name|name
parameter_list|,
name|oldp
parameter_list|,
name|oldlenp
parameter_list|,
name|newp
parameter_list|,
name|newlen
parameter_list|)
value|do {		\ 	if (je_mallctl(name, oldp, oldlenp, newp, newlen)		\ 	    != 0) {							\ 		malloc_printf(						\ 		    "<jemalloc>: Failure in xmallctl(\"%s\", ...)\n",	\ 		    name);						\ 		abort();						\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|xmallctlnametomib
parameter_list|(
name|name
parameter_list|,
name|mibp
parameter_list|,
name|miblenp
parameter_list|)
value|do {			\ 	if (je_mallctlnametomib(name, mibp, miblenp) != 0) {		\ 		malloc_printf("<jemalloc>: Failure in "			\ 		    "xmallctlnametomib(\"%s\", ...)\n", name);		\ 		abort();						\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|xmallctlbymib
parameter_list|(
name|mib
parameter_list|,
name|miblen
parameter_list|,
name|oldp
parameter_list|,
name|oldlenp
parameter_list|,
name|newp
parameter_list|,
name|newlen
parameter_list|)
value|do {	\ 	if (je_mallctlbymib(mib, miblen, oldp, oldlenp, newp,		\ 	    newlen) != 0) {						\ 		malloc_write(						\ 		    "<jemalloc>: Failure in xmallctlbymib()\n");	\ 		abort();						\ 	}								\ } while (0)
end_define

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

