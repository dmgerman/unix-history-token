begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2005, 2010, Oracle and/or its affiliates. All rights reserved.  * Copyright (c) 2012, 2017 by Delphix. All rights reserved.  * Copyright (c) 2014 Integros [integros.com]  */
end_comment

begin_comment
comment|/* Portions Copyright 2010 Robert Milkowski */
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
comment|/*  * Possbile states for a given lwb structure. An lwb will start out in  * the "closed" state, and then transition to the "opened" state via a  * call to zil_lwb_write_open(). After the lwb is "open", it can  * transition into the "issued" state via zil_lwb_write_issue(). After  * the lwb's zio completes, and the vdev's are flushed, the lwb will  * transition into the "done" state via zil_lwb_write_done(), and the  * structure eventually freed.  */
typedef|typedef
enum|enum
block|{
name|LWB_STATE_CLOSED
block|,
name|LWB_STATE_OPENED
block|,
name|LWB_STATE_ISSUED
block|,
name|LWB_STATE_DONE
block|,
name|LWB_NUM_STATES
block|}
name|lwb_state_t
typedef|;
comment|/*  * Log write block (lwb)  *  * Prior to an lwb being issued to disk via zil_lwb_write_issue(), it  * will be protected by the zilog's "zl_writer_lock". Basically, prior  * to it being issued, it will only be accessed by the thread that's  * holding the "zl_writer_lock". After the lwb is issued, the zilog's  * "zl_lock" is used to protect the lwb against concurrent access.  */
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
name|boolean_t
name|lwb_slog
decl_stmt|;
comment|/* lwb_blk is on SLOG device */
name|int
name|lwb_nused
decl_stmt|;
comment|/* # used bytes in buffer */
name|int
name|lwb_sz
decl_stmt|;
comment|/* size of block and buffer */
name|lwb_state_t
name|lwb_state
decl_stmt|;
comment|/* the state of this lwb */
name|char
modifier|*
name|lwb_buf
decl_stmt|;
comment|/* log write buffer */
name|zio_t
modifier|*
name|lwb_write_zio
decl_stmt|;
comment|/* zio for the lwb buffer */
name|zio_t
modifier|*
name|lwb_root_zio
decl_stmt|;
comment|/* root zio for lwb write and flushes */
name|dmu_tx_t
modifier|*
name|lwb_tx
decl_stmt|;
comment|/* tx for log block allocation */
name|uint64_t
name|lwb_max_txg
decl_stmt|;
comment|/* highest txg in this lwb */
name|list_node_t
name|lwb_node
decl_stmt|;
comment|/* zilog->zl_lwb_list linkage */
name|list_t
name|lwb_waiters
decl_stmt|;
comment|/* list of zil_commit_waiter's */
name|avl_tree_t
name|lwb_vdev_tree
decl_stmt|;
comment|/* vdevs to flush after lwb write */
name|kmutex_t
name|lwb_vdev_lock
decl_stmt|;
comment|/* protects lwb_vdev_tree */
name|hrtime_t
name|lwb_issued_timestamp
decl_stmt|;
comment|/* when was the lwb issued? */
block|}
name|lwb_t
typedef|;
comment|/*  * ZIL commit waiter.  *  * This structure is allocated each time zil_commit() is called, and is  * used by zil_commit() to communicate with other parts of the ZIL, such  * that zil_commit() can know when it safe for it return. For more  * details, see the comment above zil_commit().  *  * The "zcw_lock" field is used to protect the commit waiter against  * concurrent access. This lock is often acquired while already holding  * the zilog's "zl_writer_lock" or "zl_lock"; see the functions  * zil_process_commit_list() and zil_lwb_flush_vdevs_done() as examples  * of this. Thus, one must be careful not to acquire the  * "zl_writer_lock" or "zl_lock" when already holding the "zcw_lock";  * e.g. see the zil_commit_waiter_timeout() function.  */
typedef|typedef
struct|struct
name|zil_commit_waiter
block|{
name|kcondvar_t
name|zcw_cv
decl_stmt|;
comment|/* signalled when "done" */
name|kmutex_t
name|zcw_lock
decl_stmt|;
comment|/* protects fields of this struct */
name|list_node_t
name|zcw_node
decl_stmt|;
comment|/* linkage in lwb_t:lwb_waiter list */
name|lwb_t
modifier|*
name|zcw_lwb
decl_stmt|;
comment|/* back pointer to lwb when linked */
name|boolean_t
name|zcw_done
decl_stmt|;
comment|/* B_TRUE when "done", else B_FALSE */
name|int
name|zcw_zio_error
decl_stmt|;
comment|/* contains the zio io_error value */
block|}
name|zil_commit_waiter_t
typedef|;
comment|/*  * Intent log transaction lists  */
typedef|typedef
struct|struct
name|itxs
block|{
name|list_t
name|i_sync_list
decl_stmt|;
comment|/* list of synchronous itxs */
name|avl_tree_t
name|i_async_tree
decl_stmt|;
comment|/* tree of foids for async itxs */
block|}
name|itxs_t
typedef|;
typedef|typedef
struct|struct
name|itxg
block|{
name|kmutex_t
name|itxg_lock
decl_stmt|;
comment|/* lock for this structure */
name|uint64_t
name|itxg_txg
decl_stmt|;
comment|/* txg for this chain */
name|itxs_t
modifier|*
name|itxg_itxs
decl_stmt|;
comment|/* sync and async itxs */
block|}
name|itxg_t
typedef|;
comment|/* for async nodes we build up an AVL tree of lists of async itxs per file */
typedef|typedef
struct|struct
name|itx_async_node
block|{
name|uint64_t
name|ia_foid
decl_stmt|;
comment|/* file object id */
name|list_t
name|ia_list
decl_stmt|;
comment|/* list of async itxs for this foid */
name|avl_node_t
name|ia_node
decl_stmt|;
comment|/* AVL tree linkage */
block|}
name|itx_async_node_t
typedef|;
comment|/*  * Vdev flushing: during a zil_commit(), we build up an AVL tree of the vdevs  * we've touched so we know which ones need a write cache flush at the end.  */
typedef|typedef
struct|struct
name|zil_vdev_node
block|{
name|uint64_t
name|zv_vdev
decl_stmt|;
comment|/* vdev to be flushed */
name|avl_node_t
name|zv_node
decl_stmt|;
comment|/* AVL tree linkage */
block|}
name|zil_vdev_node_t
typedef|;
define|#
directive|define
name|ZIL_PREV_BLKS
value|16
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
name|lwb_t
modifier|*
name|zl_last_lwb_opened
decl_stmt|;
comment|/* most recent lwb opened */
name|hrtime_t
name|zl_last_lwb_latency
decl_stmt|;
comment|/* zio latency of last lwb done */
name|uint64_t
name|zl_lr_seq
decl_stmt|;
comment|/* on-disk log record sequence number */
name|uint64_t
name|zl_commit_lr_seq
decl_stmt|;
comment|/* last committed on-disk lr seq */
name|uint64_t
name|zl_destroy_txg
decl_stmt|;
comment|/* txg of last zil_destroy() */
name|uint64_t
name|zl_replayed_seq
index|[
name|TXG_SIZE
index|]
decl_stmt|;
comment|/* last replayed rec seq */
name|uint64_t
name|zl_replaying_seq
decl_stmt|;
comment|/* current replay seq number */
name|uint32_t
name|zl_suspend
decl_stmt|;
comment|/* log suspend count */
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
name|zl_replay
decl_stmt|;
comment|/* replaying records while set */
name|uint8_t
name|zl_stop_sync
decl_stmt|;
comment|/* for debugging */
name|kmutex_t
name|zl_writer_lock
decl_stmt|;
comment|/* single writer, per ZIL, at a time */
name|uint8_t
name|zl_logbias
decl_stmt|;
comment|/* latency or throughput */
name|uint8_t
name|zl_sync
decl_stmt|;
comment|/* synchronous or asynchronous */
name|int
name|zl_parse_error
decl_stmt|;
comment|/* last zil_parse() error */
name|uint64_t
name|zl_parse_blk_seq
decl_stmt|;
comment|/* highest blk seq on last parse */
name|uint64_t
name|zl_parse_lr_seq
decl_stmt|;
comment|/* highest lr seq on last parse */
name|uint64_t
name|zl_parse_blk_count
decl_stmt|;
comment|/* number of blocks parsed */
name|uint64_t
name|zl_parse_lr_count
decl_stmt|;
comment|/* number of log records parsed */
name|itxg_t
name|zl_itxg
index|[
name|TXG_SIZE
index|]
decl_stmt|;
comment|/* intent log txg chains */
name|list_t
name|zl_itx_commit_list
decl_stmt|;
comment|/* itx list to be committed */
name|uint64_t
name|zl_cur_used
decl_stmt|;
comment|/* current commit log size used */
name|list_t
name|zl_lwb_list
decl_stmt|;
comment|/* in-flight log write list */
name|avl_tree_t
name|zl_bp_tree
decl_stmt|;
comment|/* track bps during log parse */
name|clock_t
name|zl_replay_time
decl_stmt|;
comment|/* lbolt of when replay started */
name|uint64_t
name|zl_replay_blks
decl_stmt|;
comment|/* number of log blocks replayed */
name|zil_header_t
name|zl_old_header
decl_stmt|;
comment|/* debugging aid */
name|uint_t
name|zl_prev_blks
index|[
name|ZIL_PREV_BLKS
index|]
decl_stmt|;
comment|/* size - sector rounded */
name|uint_t
name|zl_prev_rotor
decl_stmt|;
comment|/* rotor for zl_prev[] */
name|txg_node_t
name|zl_dirty_link
decl_stmt|;
comment|/* protected by dp_dirty_zilogs list */
name|uint64_t
name|zl_dirty_max_txg
decl_stmt|;
comment|/* highest txg used to dirty zilog */
block|}
struct|;
typedef|typedef
struct|struct
name|zil_bp_node
block|{
name|dva_t
name|zn_dva
decl_stmt|;
name|avl_node_t
name|zn_node
decl_stmt|;
block|}
name|zil_bp_node_t
typedef|;
comment|/*  * Maximum amount of write data that can be put into single log block.  */
define|#
directive|define
name|ZIL_MAX_LOG_DATA
value|(SPA_OLD_MAXBLOCKSIZE - sizeof (zil_chain_t) - \     sizeof (lr_write_t))
define|#
directive|define
name|ZIL_MAX_COPIED_DATA
define|\
value|((SPA_OLD_MAXBLOCKSIZE - sizeof (zil_chain_t)) / 2 - sizeof (lr_write_t))
comment|/*  * Maximum amount of log space we agree to waste to reduce number of  * WR_NEED_COPY chunks to reduce zl_get_data() overhead (~12%).  */
define|#
directive|define
name|ZIL_MAX_WASTE_SPACE
value|(ZIL_MAX_LOG_DATA / 8)
comment|/*  * Maximum amount of write data for WR_COPIED.  Fall back to WR_NEED_COPY  * as more space efficient if we can't fit at least two log records into  * maximum sized log block.  */
define|#
directive|define
name|ZIL_MAX_COPIED_DATA
value|((SPA_OLD_MAXBLOCKSIZE - \     sizeof (zil_chain_t)) / 2 - sizeof (lr_write_t))
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

