begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: rpool.h,v 1.15 2001/09/04 22:41:55 ca Exp $  */
end_comment

begin_comment
comment|/* **  libsm resource pools **  See libsm/rpool.html for documentation. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_RPOOL_H
end_ifndef

begin_define
define|#
directive|define
name|SM_RPOOL_H
end_define

begin_include
include|#
directive|include
file|<sm/gen.h>
end_include

begin_include
include|#
directive|include
file|<sm/heap.h>
end_include

begin_include
include|#
directive|include
file|<sm/string.h>
end_include

begin_comment
comment|/* **  Each memory pool object consists of an SM_POOLLINK_T, **  followed by a platform specific amount of padding, **  followed by 'poolsize' bytes of pool data, **  where 'poolsize' is the value of rpool->sm_poolsize at the time **  the pool is allocated. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|sm_poollink
name|SM_POOLLINK_T
typedef|;
end_typedef

begin_struct
struct|struct
name|sm_poollink
block|{
name|SM_POOLLINK_T
modifier|*
name|sm_pnext
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*SM_RPOOL_RFREE_T
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
name|_rcontext
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|SM_RPOOL_RFREE_T
modifier|*
name|SM_RPOOL_ATTACH_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|sm_resource
name|SM_RESOURCE_T
typedef|;
end_typedef

begin_struct
struct|struct
name|sm_resource
block|{
comment|/* 	**  Function for freeing this resource.  It may be NULL, 	**  meaning that this resource has already been freed. 	*/
name|SM_RPOOL_RFREE_T
name|sm_rfree
decl_stmt|;
name|void
modifier|*
name|sm_rcontext
decl_stmt|;
comment|/* resource data */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SM_RLIST_MAX
value|511
end_define

begin_typedef
typedef|typedef
name|struct
name|sm_rlist
name|SM_RLIST_T
typedef|;
end_typedef

begin_struct
struct|struct
name|sm_rlist
block|{
name|SM_RESOURCE_T
name|sm_rvec
index|[
name|SM_RLIST_MAX
index|]
decl_stmt|;
name|SM_RLIST_T
modifier|*
name|sm_rnext
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Points to SmRpoolMagic, or is NULL if rpool is freed. */
specifier|const
name|char
modifier|*
name|sm_magic
decl_stmt|;
comment|/* 	**  If this rpool object has no parent, then sm_parentlink 	**  is NULL.  Otherwise, we set *sm_parentlink = NULL 	**  when this rpool is freed, so that it isn't freed a 	**  second time when the parent is freed. 	*/
name|SM_RPOOL_RFREE_T
modifier|*
name|sm_parentlink
decl_stmt|;
comment|/* 	**  Memory pools 	*/
comment|/* Size of the next pool to be allocated, not including the header. */
name|size_t
name|sm_poolsize
decl_stmt|;
comment|/* 	**  If an sm_rpool_malloc_x request is too big to fit 	**  in the current pool, and the request size> bigobjectsize, 	**  then the object will be given its own malloc'ed block. 	**  sm_bigobjectsize<= sm_poolsize.  The maximum wasted space 	**  at the end of a pool is maxpooledobjectsize - 1. 	*/
name|size_t
name|sm_bigobjectsize
decl_stmt|;
comment|/* Points to next free byte in the current pool. */
name|char
modifier|*
name|sm_poolptr
decl_stmt|;
comment|/* 	**  Number of bytes available in the current pool. 	**	Initially 0. Set to 0 by sm_rpool_free. 	*/
name|size_t
name|sm_poolavail
decl_stmt|;
comment|/* Linked list of memory pools.  Initially NULL. */
name|SM_POOLLINK_T
modifier|*
name|sm_pools
decl_stmt|;
comment|/* 	** Resource lists 	*/
name|SM_RESOURCE_T
modifier|*
name|sm_rptr
decl_stmt|;
comment|/* Points to next free resource slot. */
comment|/* 	**  Number of available resource slots in current list. 	**	Initially 0. Set to 0 by sm_rpool_free. 	*/
name|size_t
name|sm_ravail
decl_stmt|;
comment|/* Linked list of resource lists. Initially NULL. */
name|SM_RLIST_T
modifier|*
name|sm_rlists
decl_stmt|;
if|#
directive|if
name|_FFR_PERF_RPOOL
name|int
name|sm_nbigblocks
decl_stmt|;
name|int
name|sm_npools
decl_stmt|;
endif|#
directive|endif
comment|/* _FFR_PERF_RPOOL */
block|}
name|SM_RPOOL_T
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|SM_RPOOL_T
modifier|*
name|sm_rpool_new_x
name|__P
argument_list|(
operator|(
name|SM_RPOOL_T
operator|*
name|_parent
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sm_rpool_free
name|__P
argument_list|(
operator|(
name|SM_RPOOL_T
operator|*
name|_rpool
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|SM_HEAP_CHECK
end_if

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|sm_rpool_malloc_tagged_x
name|__P
argument_list|(
operator|(
name|SM_RPOOL_T
operator|*
name|_rpool
operator|,
name|size_t
name|_size
operator|,
name|char
operator|*
name|_file
operator|,
name|int
name|_line
operator|,
name|int
name|_group
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|sm_rpool_malloc_x
parameter_list|(
name|rpool
parameter_list|,
name|size
parameter_list|)
define|\
value|sm_rpool_malloc_tagged_x(rpool, size, __FILE__, __LINE__, SmHeapGroup)
end_define

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|sm_rpool_malloc_tagged
name|__P
argument_list|(
operator|(
name|SM_RPOOL_T
operator|*
name|_rpool
operator|,
name|size_t
name|_size
operator|,
name|char
operator|*
name|_file
operator|,
name|int
name|_line
operator|,
name|int
name|_group
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|sm_rpool_malloc
parameter_list|(
name|rpool
parameter_list|,
name|size
parameter_list|)
define|\
value|sm_rpool_malloc_tagged(rpool, size, __FILE__, __LINE__, SmHeapGroup)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SM_HEAP_CHECK */
end_comment

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|sm_rpool_malloc_x
name|__P
argument_list|(
operator|(
name|SM_RPOOL_T
operator|*
name|_rpool
operator|,
name|size_t
name|_size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|sm_rpool_malloc
name|__P
argument_list|(
operator|(
name|SM_RPOOL_T
operator|*
name|_rpool
operator|,
name|size_t
name|_size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_HEAP_CHECK */
end_comment

begin_define
define|#
directive|define
name|sm_rpool_strdup_x
parameter_list|(
name|rpool
parameter_list|,
name|str
parameter_list|)
define|\
value|strcpy(sm_rpool_malloc_x(rpool, strlen(str) + 1), str)
end_define

begin_decl_stmt
specifier|extern
name|SM_RPOOL_ATTACH_T
name|sm_rpool_attach_x
name|__P
argument_list|(
operator|(
name|SM_RPOOL_T
operator|*
name|_rpool
operator|,
name|SM_RPOOL_RFREE_T
name|_rfree
operator|,
name|void
operator|*
name|_rcontext
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|sm_rpool_detach
parameter_list|(
name|a
parameter_list|)
value|((void)(*(a) = NULL))
end_define

begin_decl_stmt
specifier|extern
name|void
name|sm_rpool_setsizes
name|__P
argument_list|(
operator|(
name|SM_RPOOL_T
operator|*
name|_rpool
operator|,
name|size_t
name|_poolsize
operator|,
name|size_t
name|_bigobjectsize
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_RPOOL_H */
end_comment

end_unit

