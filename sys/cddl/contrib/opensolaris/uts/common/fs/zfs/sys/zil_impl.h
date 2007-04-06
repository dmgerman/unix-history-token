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
name|_SYS_ZIL_IMPL_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_ZIL_IMPL_H
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
file|<sys/zil.h>
end_include

begin_include
include|#
directive|include
file|<sys/dmu_objset.h>
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
comment|/*  * Log write buffer.  */
typedef|typedef
struct|struct
name|lwb
block|{
name|zilog_t
modifier|*
name|lwb_zilog
decl_stmt|;
comment|/* back pointer to log struct */
name|blkptr_t
name|lwb_blk
decl_stmt|;
comment|/* on disk address of this log blk */
name|int
name|lwb_nused
decl_stmt|;
comment|/* # used bytes in buffer */
name|int
name|lwb_sz
decl_stmt|;
comment|/* size of block and buffer */
name|char
modifier|*
name|lwb_buf
decl_stmt|;
comment|/* log write buffer */
name|zio_t
modifier|*
name|lwb_zio
decl_stmt|;
comment|/* zio for this buffer */
name|uint64_t
name|lwb_max_txg
decl_stmt|;
comment|/* highest txg in this lwb */
name|txg_handle_t
name|lwb_txgh
decl_stmt|;
comment|/* txg handle for txg_exit() */
name|list_node_t
name|lwb_node
decl_stmt|;
comment|/* zilog->zl_lwb_list linkage */
block|}
name|lwb_t
typedef|;
comment|/*  * Vdev flushing: We use a bit map of size ZIL_VDEV_BMAP bytes.  * Any vdev numbers beyond that use a linked list of zil_vdev_t structures.  */
define|#
directive|define
name|ZIL_VDEV_BMSZ
value|16
comment|/* 16 * 8 = 128 vdevs */
typedef|typedef
struct|struct
name|zil_vdev
block|{
name|uint64_t
name|vdev
decl_stmt|;
comment|/* device written */
name|list_node_t
name|vdev_seq_node
decl_stmt|;
comment|/* zilog->zl_vdev_list linkage */
block|}
name|zil_vdev_t
typedef|;
comment|/*  * Stable storage intent log management structure.  One per dataset.  */
struct|struct
name|zilog
block|{
name|kmutex_t
name|zl_lock
decl_stmt|;
comment|/* protects most zilog_t fields */
name|struct
name|dsl_pool
modifier|*
name|zl_dmu_pool
decl_stmt|;
comment|/* DSL pool */
name|spa_t
modifier|*
name|zl_spa
decl_stmt|;
comment|/* handle for read/write log */
specifier|const
name|zil_header_t
modifier|*
name|zl_header
decl_stmt|;
comment|/* log header buffer */
name|objset_t
modifier|*
name|zl_os
decl_stmt|;
comment|/* object set we're logging */
name|zil_get_data_t
modifier|*
name|zl_get_data
decl_stmt|;
comment|/* callback to get object content */
name|zio_t
modifier|*
name|zl_root_zio
decl_stmt|;
comment|/* log writer root zio */
name|uint64_t
name|zl_itx_seq
decl_stmt|;
comment|/* next itx sequence number */
name|uint64_t
name|zl_commit_seq
decl_stmt|;
comment|/* committed upto this number */
name|uint64_t
name|zl_lr_seq
decl_stmt|;
comment|/* log record sequence number */
name|uint64_t
name|zl_destroy_txg
decl_stmt|;
comment|/* txg of last zil_destroy() */
name|uint64_t
name|zl_replay_seq
index|[
name|TXG_SIZE
index|]
decl_stmt|;
comment|/* seq of last replayed rec */
name|uint32_t
name|zl_suspend
decl_stmt|;
comment|/* log suspend count */
name|kcondvar_t
name|zl_cv_writer
decl_stmt|;
comment|/* log writer thread completion */
name|kcondvar_t
name|zl_cv_suspend
decl_stmt|;
comment|/* log suspend completion */
name|uint8_t
name|zl_suspending
decl_stmt|;
comment|/* log is currently suspending */
name|uint8_t
name|zl_keep_first
decl_stmt|;
comment|/* keep first log block in destroy */
name|uint8_t
name|zl_stop_replay
decl_stmt|;
comment|/* don't replay any further */
name|uint8_t
name|zl_stop_sync
decl_stmt|;
comment|/* for debugging */
name|uint8_t
name|zl_writer
decl_stmt|;
comment|/* boolean: write setup in progress */
name|uint8_t
name|zl_log_error
decl_stmt|;
comment|/* boolean: log write error */
name|list_t
name|zl_itx_list
decl_stmt|;
comment|/* in-memory itx list */
name|uint64_t
name|zl_itx_list_sz
decl_stmt|;
comment|/* total size of records on list */
name|uint64_t
name|zl_cur_used
decl_stmt|;
comment|/* current commit log size used */
name|uint64_t
name|zl_prev_used
decl_stmt|;
comment|/* previous commit log size used */
name|list_t
name|zl_lwb_list
decl_stmt|;
comment|/* in-flight log write list */
name|list_t
name|zl_vdev_list
decl_stmt|;
comment|/* list of [vdev, seq] pairs */
name|uint8_t
name|zl_vdev_bmap
index|[
name|ZIL_VDEV_BMSZ
index|]
decl_stmt|;
comment|/* bitmap of vdevs */
name|taskq_t
modifier|*
name|zl_clean_taskq
decl_stmt|;
comment|/* runs lwb and itx clean tasks */
name|avl_tree_t
name|zl_dva_tree
decl_stmt|;
comment|/* track DVAs during log parse */
name|clock_t
name|zl_replay_time
decl_stmt|;
comment|/* lbolt of when replay started */
name|uint64_t
name|zl_replay_blks
decl_stmt|;
comment|/* number of log blocks replayed */
block|}
struct|;
typedef|typedef
struct|struct
name|zil_dva_node
block|{
name|dva_t
name|zn_dva
decl_stmt|;
name|avl_node_t
name|zn_node
decl_stmt|;
block|}
name|zil_dva_node_t
typedef|;
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
comment|/* _SYS_ZIL_IMPL_H */
end_comment

end_unit

