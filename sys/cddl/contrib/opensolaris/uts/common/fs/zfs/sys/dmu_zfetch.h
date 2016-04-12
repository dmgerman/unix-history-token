begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2009 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2014 by Delphix. All rights reserved.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DMU_ZFETCH_H
end_ifndef

begin_define
define|#
directive|define
name|_DMU_ZFETCH_H
end_define

begin_include
include|#
directive|include
file|<sys/zfs_context.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
specifier|extern
name|uint64_t
name|zfetch_array_rd_sz
decl_stmt|;
struct_decl|struct
name|dnode
struct_decl|;
comment|/* so we can reference dnode */
typedef|typedef
struct|struct
name|zstream
block|{
name|uint64_t
name|zs_blkid
decl_stmt|;
comment|/* expect next access at this blkid */
name|uint64_t
name|zs_pf_blkid
decl_stmt|;
comment|/* next block to prefetch */
comment|/* 	 * We will next prefetch the L1 indirect block of this level-0 	 * block id. 	 */
name|uint64_t
name|zs_ipf_blkid
decl_stmt|;
name|kmutex_t
name|zs_lock
decl_stmt|;
comment|/* protects stream */
name|hrtime_t
name|zs_atime
decl_stmt|;
comment|/* time last prefetch issued */
name|list_node_t
name|zs_node
decl_stmt|;
comment|/* link for zf_stream */
block|}
name|zstream_t
typedef|;
typedef|typedef
struct|struct
name|zfetch
block|{
name|krwlock_t
name|zf_rwlock
decl_stmt|;
comment|/* protects zfetch structure */
name|list_t
name|zf_stream
decl_stmt|;
comment|/* list of zstream_t's */
name|struct
name|dnode
modifier|*
name|zf_dnode
decl_stmt|;
comment|/* dnode that owns this zfetch */
block|}
name|zfetch_t
typedef|;
name|void
name|zfetch_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
name|zfetch_fini
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
name|dmu_zfetch_init
parameter_list|(
name|zfetch_t
modifier|*
parameter_list|,
name|struct
name|dnode
modifier|*
parameter_list|)
function_decl|;
name|void
name|dmu_zfetch_fini
parameter_list|(
name|zfetch_t
modifier|*
parameter_list|)
function_decl|;
name|void
name|dmu_zfetch
parameter_list|(
name|zfetch_t
modifier|*
parameter_list|,
name|uint64_t
parameter_list|,
name|uint64_t
parameter_list|,
name|boolean_t
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DMU_ZFETCH_H */
end_comment

end_unit

