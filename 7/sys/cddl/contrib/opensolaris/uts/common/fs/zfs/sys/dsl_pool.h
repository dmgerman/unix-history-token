begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_DSL_POOL_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_DSL_POOL_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_include
include|#
directive|include
file|<sys/spa.h>
end_include

begin_include
include|#
directive|include
file|<sys/txg.h>
end_include

begin_include
include|#
directive|include
file|<sys/txg_impl.h>
end_include

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
struct_decl|struct
name|objset
struct_decl|;
struct_decl|struct
name|dsl_dir
struct_decl|;
typedef|typedef
struct|struct
name|dsl_pool
block|{
comment|/* Immutable */
name|spa_t
modifier|*
name|dp_spa
decl_stmt|;
name|struct
name|objset
modifier|*
name|dp_meta_objset
decl_stmt|;
name|struct
name|dsl_dir
modifier|*
name|dp_root_dir
decl_stmt|;
name|struct
name|dsl_dir
modifier|*
name|dp_mos_dir
decl_stmt|;
name|uint64_t
name|dp_root_dir_obj
decl_stmt|;
comment|/* No lock needed - sync context only */
name|blkptr_t
name|dp_meta_rootbp
decl_stmt|;
name|list_t
name|dp_synced_objsets
decl_stmt|;
comment|/* Has its own locking */
name|tx_state_t
name|dp_tx
decl_stmt|;
name|txg_list_t
name|dp_dirty_datasets
decl_stmt|;
name|txg_list_t
name|dp_dirty_dirs
decl_stmt|;
name|txg_list_t
name|dp_sync_tasks
decl_stmt|;
comment|/* 	 * Protects administrative changes (properties, namespace) 	 * It is only held for write in syncing context.  Therefore 	 * syncing context does not need to ever have it for read, since 	 * nobody else could possibly have it for write. 	 */
name|krwlock_t
name|dp_config_rwlock
decl_stmt|;
block|}
name|dsl_pool_t
typedef|;
name|int
name|dsl_pool_open
parameter_list|(
name|spa_t
modifier|*
name|spa
parameter_list|,
name|uint64_t
name|txg
parameter_list|,
name|dsl_pool_t
modifier|*
modifier|*
name|dpp
parameter_list|)
function_decl|;
name|void
name|dsl_pool_close
parameter_list|(
name|dsl_pool_t
modifier|*
name|dp
parameter_list|)
function_decl|;
name|dsl_pool_t
modifier|*
name|dsl_pool_create
parameter_list|(
name|spa_t
modifier|*
name|spa
parameter_list|,
name|uint64_t
name|txg
parameter_list|)
function_decl|;
name|void
name|dsl_pool_sync
parameter_list|(
name|dsl_pool_t
modifier|*
name|dp
parameter_list|,
name|uint64_t
name|txg
parameter_list|)
function_decl|;
name|void
name|dsl_pool_zil_clean
parameter_list|(
name|dsl_pool_t
modifier|*
name|dp
parameter_list|)
function_decl|;
name|int
name|dsl_pool_sync_context
parameter_list|(
name|dsl_pool_t
modifier|*
name|dp
parameter_list|)
function_decl|;
name|uint64_t
name|dsl_pool_adjustedsize
parameter_list|(
name|dsl_pool_t
modifier|*
name|dp
parameter_list|,
name|boolean_t
name|netfree
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
comment|/* _SYS_DSL_POOL_H */
end_comment

end_unit

