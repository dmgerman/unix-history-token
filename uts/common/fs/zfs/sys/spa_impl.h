begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2005, 2010, Oracle and/or its affiliates. All rights reserved.  * Copyright (c) 2011, 2015 by Delphix. All rights reserved.  * Copyright 2011 Nexenta Systems, Inc.  All rights reserved.  * Copyright (c) 2014 Spectra Logic Corporation, All rights reserved.  * Copyright 2013 Saso Kiselkov. All rights reserved.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SPA_IMPL_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SPA_IMPL_H
end_define

begin_include
include|#
directive|include
file|<sys/spa.h>
end_include

begin_include
include|#
directive|include
file|<sys/vdev.h>
end_include

begin_include
include|#
directive|include
file|<sys/metaslab.h>
end_include

begin_include
include|#
directive|include
file|<sys/dmu.h>
end_include

begin_include
include|#
directive|include
file|<sys/dsl_pool.h>
end_include

begin_include
include|#
directive|include
file|<sys/uberblock_impl.h>
end_include

begin_include
include|#
directive|include
file|<sys/zfs_context.h>
end_include

begin_include
include|#
directive|include
file|<sys/avl.h>
end_include

begin_include
include|#
directive|include
file|<sys/refcount.h>
end_include

begin_include
include|#
directive|include
file|<sys/bplist.h>
end_include

begin_include
include|#
directive|include
file|<sys/bpobj.h>
end_include

begin_include
include|#
directive|include
file|<sys/zfeature.h>
end_include

begin_include
include|#
directive|include
file|<zfeature_common.h>
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
typedef|typedef
struct|struct
name|spa_error_entry
block|{
name|zbookmark_phys_t
name|se_bookmark
decl_stmt|;
name|char
modifier|*
name|se_name
decl_stmt|;
name|avl_node_t
name|se_avl
decl_stmt|;
block|}
name|spa_error_entry_t
typedef|;
typedef|typedef
struct|struct
name|spa_history_phys
block|{
name|uint64_t
name|sh_pool_create_len
decl_stmt|;
comment|/* ending offset of zpool create */
name|uint64_t
name|sh_phys_max_off
decl_stmt|;
comment|/* physical EOF */
name|uint64_t
name|sh_bof
decl_stmt|;
comment|/* logical BOF */
name|uint64_t
name|sh_eof
decl_stmt|;
comment|/* logical EOF */
name|uint64_t
name|sh_records_lost
decl_stmt|;
comment|/* num of records overwritten */
block|}
name|spa_history_phys_t
typedef|;
struct|struct
name|spa_aux_vdev
block|{
name|uint64_t
name|sav_object
decl_stmt|;
comment|/* MOS object for device list */
name|nvlist_t
modifier|*
name|sav_config
decl_stmt|;
comment|/* cached device config */
name|vdev_t
modifier|*
modifier|*
name|sav_vdevs
decl_stmt|;
comment|/* devices */
name|int
name|sav_count
decl_stmt|;
comment|/* number devices */
name|boolean_t
name|sav_sync
decl_stmt|;
comment|/* sync the device list */
name|nvlist_t
modifier|*
modifier|*
name|sav_pending
decl_stmt|;
comment|/* pending device additions */
name|uint_t
name|sav_npending
decl_stmt|;
comment|/* # pending devices */
block|}
struct|;
typedef|typedef
struct|struct
name|spa_config_lock
block|{
name|kmutex_t
name|scl_lock
decl_stmt|;
name|kthread_t
modifier|*
name|scl_writer
decl_stmt|;
name|int
name|scl_write_wanted
decl_stmt|;
name|kcondvar_t
name|scl_cv
decl_stmt|;
name|refcount_t
name|scl_count
decl_stmt|;
block|}
name|spa_config_lock_t
typedef|;
typedef|typedef
struct|struct
name|spa_config_dirent
block|{
name|list_node_t
name|scd_link
decl_stmt|;
name|char
modifier|*
name|scd_path
decl_stmt|;
block|}
name|spa_config_dirent_t
typedef|;
typedef|typedef
enum|enum
name|zio_taskq_type
block|{
name|ZIO_TASKQ_ISSUE
init|=
literal|0
block|,
name|ZIO_TASKQ_ISSUE_HIGH
block|,
name|ZIO_TASKQ_INTERRUPT
block|,
name|ZIO_TASKQ_INTERRUPT_HIGH
block|,
name|ZIO_TASKQ_TYPES
block|}
name|zio_taskq_type_t
typedef|;
comment|/*  * State machine for the zpool-poolname process.  The states transitions  * are done as follows:  *  *	From		   To			Routine  *	PROC_NONE	-> PROC_CREATED		spa_activate()  *	PROC_CREATED	-> PROC_ACTIVE		spa_thread()  *	PROC_ACTIVE	-> PROC_DEACTIVATE	spa_deactivate()  *	PROC_DEACTIVATE	-> PROC_GONE		spa_thread()  *	PROC_GONE	-> PROC_NONE		spa_deactivate()  */
typedef|typedef
enum|enum
name|spa_proc_state
block|{
name|SPA_PROC_NONE
block|,
comment|/* spa_proc =&p0, no process created */
name|SPA_PROC_CREATED
block|,
comment|/* spa_activate() has proc, is waiting */
name|SPA_PROC_ACTIVE
block|,
comment|/* taskqs created, spa_proc set */
name|SPA_PROC_DEACTIVATE
block|,
comment|/* spa_deactivate() requests process exit */
name|SPA_PROC_GONE
comment|/* spa_thread() is exiting, spa_proc =&p0 */
block|}
name|spa_proc_state_t
typedef|;
typedef|typedef
struct|struct
name|spa_taskqs
block|{
name|uint_t
name|stqs_count
decl_stmt|;
name|taskq_t
modifier|*
modifier|*
name|stqs_taskq
decl_stmt|;
block|}
name|spa_taskqs_t
typedef|;
typedef|typedef
enum|enum
name|spa_all_vdev_zap_action
block|{
name|AVZ_ACTION_NONE
init|=
literal|0
block|,
name|AVZ_ACTION_DESTROY
block|,
comment|/* Destroy all per-vdev ZAPs and the AVZ. */
name|AVZ_ACTION_REBUILD
block|,
comment|/* Populate the new AVZ, see spa_avz_rebuild */
name|AVZ_ACTION_INITIALIZE
block|}
name|spa_avz_action_t
typedef|;
struct|struct
name|spa
block|{
comment|/* 	 * Fields protected by spa_namespace_lock. 	 */
name|char
name|spa_name
index|[
name|ZFS_MAX_DATASET_NAME_LEN
index|]
decl_stmt|;
comment|/* pool name */
name|char
modifier|*
name|spa_comment
decl_stmt|;
comment|/* comment */
name|avl_node_t
name|spa_avl
decl_stmt|;
comment|/* node in spa_namespace_avl */
name|nvlist_t
modifier|*
name|spa_config
decl_stmt|;
comment|/* last synced config */
name|nvlist_t
modifier|*
name|spa_config_syncing
decl_stmt|;
comment|/* currently syncing config */
name|nvlist_t
modifier|*
name|spa_config_splitting
decl_stmt|;
comment|/* config for splitting */
name|nvlist_t
modifier|*
name|spa_load_info
decl_stmt|;
comment|/* info and errors from load */
name|uint64_t
name|spa_config_txg
decl_stmt|;
comment|/* txg of last config change */
name|int
name|spa_sync_pass
decl_stmt|;
comment|/* iterate-to-convergence */
name|pool_state_t
name|spa_state
decl_stmt|;
comment|/* pool state */
name|int
name|spa_inject_ref
decl_stmt|;
comment|/* injection references */
name|uint8_t
name|spa_sync_on
decl_stmt|;
comment|/* sync threads are running */
name|spa_load_state_t
name|spa_load_state
decl_stmt|;
comment|/* current load operation */
name|uint64_t
name|spa_import_flags
decl_stmt|;
comment|/* import specific flags */
name|spa_taskqs_t
name|spa_zio_taskq
index|[
name|ZIO_TYPES
index|]
index|[
name|ZIO_TASKQ_TYPES
index|]
decl_stmt|;
name|dsl_pool_t
modifier|*
name|spa_dsl_pool
decl_stmt|;
name|boolean_t
name|spa_is_initializing
decl_stmt|;
comment|/* true while opening pool */
name|metaslab_class_t
modifier|*
name|spa_normal_class
decl_stmt|;
comment|/* normal data class */
name|metaslab_class_t
modifier|*
name|spa_log_class
decl_stmt|;
comment|/* intent log data class */
name|uint64_t
name|spa_first_txg
decl_stmt|;
comment|/* first txg after spa_open() */
name|uint64_t
name|spa_final_txg
decl_stmt|;
comment|/* txg of export/destroy */
name|uint64_t
name|spa_freeze_txg
decl_stmt|;
comment|/* freeze pool at this txg */
name|uint64_t
name|spa_load_max_txg
decl_stmt|;
comment|/* best initial ub_txg */
name|uint64_t
name|spa_claim_max_txg
decl_stmt|;
comment|/* highest claimed birth txg */
name|timespec_t
name|spa_loaded_ts
decl_stmt|;
comment|/* 1st successful open time */
name|objset_t
modifier|*
name|spa_meta_objset
decl_stmt|;
comment|/* copy of dp->dp_meta_objset */
name|kmutex_t
name|spa_evicting_os_lock
decl_stmt|;
comment|/* Evicting objset list lock */
name|list_t
name|spa_evicting_os_list
decl_stmt|;
comment|/* Objsets being evicted. */
name|kcondvar_t
name|spa_evicting_os_cv
decl_stmt|;
comment|/* Objset Eviction Completion */
name|txg_list_t
name|spa_vdev_txg_list
decl_stmt|;
comment|/* per-txg dirty vdev list */
name|vdev_t
modifier|*
name|spa_root_vdev
decl_stmt|;
comment|/* top-level vdev container */
name|int
name|spa_min_ashift
decl_stmt|;
comment|/* of vdevs in normal class */
name|int
name|spa_max_ashift
decl_stmt|;
comment|/* of vdevs in normal class */
name|uint64_t
name|spa_config_guid
decl_stmt|;
comment|/* config pool guid */
name|uint64_t
name|spa_load_guid
decl_stmt|;
comment|/* spa_load initialized guid */
name|uint64_t
name|spa_last_synced_guid
decl_stmt|;
comment|/* last synced guid */
name|list_t
name|spa_config_dirty_list
decl_stmt|;
comment|/* vdevs with dirty config */
name|list_t
name|spa_state_dirty_list
decl_stmt|;
comment|/* vdevs with dirty state */
name|kmutex_t
name|spa_alloc_lock
decl_stmt|;
name|avl_tree_t
name|spa_alloc_tree
decl_stmt|;
name|spa_aux_vdev_t
name|spa_spares
decl_stmt|;
comment|/* hot spares */
name|spa_aux_vdev_t
name|spa_l2cache
decl_stmt|;
comment|/* L2ARC cache devices */
name|nvlist_t
modifier|*
name|spa_label_features
decl_stmt|;
comment|/* Features for reading MOS */
name|uint64_t
name|spa_config_object
decl_stmt|;
comment|/* MOS object for pool config */
name|uint64_t
name|spa_config_generation
decl_stmt|;
comment|/* config generation number */
name|uint64_t
name|spa_syncing_txg
decl_stmt|;
comment|/* txg currently syncing */
name|bpobj_t
name|spa_deferred_bpobj
decl_stmt|;
comment|/* deferred-free bplist */
name|bplist_t
name|spa_free_bplist
index|[
name|TXG_SIZE
index|]
decl_stmt|;
comment|/* bplist of stuff to free */
name|zio_cksum_salt_t
name|spa_cksum_salt
decl_stmt|;
comment|/* secret salt for cksum */
comment|/* checksum context templates */
name|kmutex_t
name|spa_cksum_tmpls_lock
decl_stmt|;
name|void
modifier|*
name|spa_cksum_tmpls
index|[
name|ZIO_CHECKSUM_FUNCTIONS
index|]
decl_stmt|;
name|uberblock_t
name|spa_ubsync
decl_stmt|;
comment|/* last synced uberblock */
name|uberblock_t
name|spa_uberblock
decl_stmt|;
comment|/* current uberblock */
name|boolean_t
name|spa_extreme_rewind
decl_stmt|;
comment|/* rewind past deferred frees */
name|uint64_t
name|spa_last_io
decl_stmt|;
comment|/* lbolt of last non-scan I/O */
name|kmutex_t
name|spa_scrub_lock
decl_stmt|;
comment|/* resilver/scrub lock */
name|uint64_t
name|spa_scrub_inflight
decl_stmt|;
comment|/* in-flight scrub I/Os */
name|kcondvar_t
name|spa_scrub_io_cv
decl_stmt|;
comment|/* scrub I/O completion */
name|uint8_t
name|spa_scrub_active
decl_stmt|;
comment|/* active or suspended? */
name|uint8_t
name|spa_scrub_type
decl_stmt|;
comment|/* type of scrub we're doing */
name|uint8_t
name|spa_scrub_finished
decl_stmt|;
comment|/* indicator to rotate logs */
name|uint8_t
name|spa_scrub_started
decl_stmt|;
comment|/* started since last boot */
name|uint8_t
name|spa_scrub_reopen
decl_stmt|;
comment|/* scrub doing vdev_reopen */
name|uint64_t
name|spa_scan_pass_start
decl_stmt|;
comment|/* start time per pass/reboot */
name|uint64_t
name|spa_scan_pass_exam
decl_stmt|;
comment|/* examined bytes per pass */
name|kmutex_t
name|spa_async_lock
decl_stmt|;
comment|/* protect async state */
name|kthread_t
modifier|*
name|spa_async_thread
decl_stmt|;
comment|/* thread doing async task */
name|int
name|spa_async_suspended
decl_stmt|;
comment|/* async tasks suspended */
name|kcondvar_t
name|spa_async_cv
decl_stmt|;
comment|/* wait for thread_exit() */
name|uint16_t
name|spa_async_tasks
decl_stmt|;
comment|/* async task mask */
name|char
modifier|*
name|spa_root
decl_stmt|;
comment|/* alternate root directory */
name|uint64_t
name|spa_ena
decl_stmt|;
comment|/* spa-wide ereport ENA */
name|int
name|spa_last_open_failed
decl_stmt|;
comment|/* error if last open failed */
name|uint64_t
name|spa_last_ubsync_txg
decl_stmt|;
comment|/* "best" uberblock txg */
name|uint64_t
name|spa_last_ubsync_txg_ts
decl_stmt|;
comment|/* timestamp from that ub */
name|uint64_t
name|spa_load_txg
decl_stmt|;
comment|/* ub txg that loaded */
name|uint64_t
name|spa_load_txg_ts
decl_stmt|;
comment|/* timestamp from that ub */
name|uint64_t
name|spa_load_meta_errors
decl_stmt|;
comment|/* verify metadata err count */
name|uint64_t
name|spa_load_data_errors
decl_stmt|;
comment|/* verify data err count */
name|uint64_t
name|spa_verify_min_txg
decl_stmt|;
comment|/* start txg of verify scrub */
name|kmutex_t
name|spa_errlog_lock
decl_stmt|;
comment|/* error log lock */
name|uint64_t
name|spa_errlog_last
decl_stmt|;
comment|/* last error log object */
name|uint64_t
name|spa_errlog_scrub
decl_stmt|;
comment|/* scrub error log object */
name|kmutex_t
name|spa_errlist_lock
decl_stmt|;
comment|/* error list/ereport lock */
name|avl_tree_t
name|spa_errlist_last
decl_stmt|;
comment|/* last error list */
name|avl_tree_t
name|spa_errlist_scrub
decl_stmt|;
comment|/* scrub error list */
name|uint64_t
name|spa_deflate
decl_stmt|;
comment|/* should we deflate? */
name|uint64_t
name|spa_history
decl_stmt|;
comment|/* history object */
name|kmutex_t
name|spa_history_lock
decl_stmt|;
comment|/* history lock */
name|vdev_t
modifier|*
name|spa_pending_vdev
decl_stmt|;
comment|/* pending vdev additions */
name|kmutex_t
name|spa_props_lock
decl_stmt|;
comment|/* property lock */
name|uint64_t
name|spa_pool_props_object
decl_stmt|;
comment|/* object for properties */
name|uint64_t
name|spa_bootfs
decl_stmt|;
comment|/* default boot filesystem */
name|uint64_t
name|spa_failmode
decl_stmt|;
comment|/* failure mode for the pool */
name|uint64_t
name|spa_delegation
decl_stmt|;
comment|/* delegation on/off */
name|list_t
name|spa_config_list
decl_stmt|;
comment|/* previous cache file(s) */
comment|/* per-CPU array of root of async I/O: */
name|zio_t
modifier|*
modifier|*
name|spa_async_zio_root
decl_stmt|;
name|zio_t
modifier|*
name|spa_suspend_zio_root
decl_stmt|;
comment|/* root of all suspended I/O */
name|kmutex_t
name|spa_suspend_lock
decl_stmt|;
comment|/* protects suspend_zio_root */
name|kcondvar_t
name|spa_suspend_cv
decl_stmt|;
comment|/* notification of resume */
name|uint8_t
name|spa_suspended
decl_stmt|;
comment|/* pool is suspended */
name|uint8_t
name|spa_claiming
decl_stmt|;
comment|/* pool is doing zil_claim() */
name|boolean_t
name|spa_debug
decl_stmt|;
comment|/* debug enabled? */
name|boolean_t
name|spa_is_root
decl_stmt|;
comment|/* pool is root */
name|int
name|spa_minref
decl_stmt|;
comment|/* num refs when first opened */
name|int
name|spa_mode
decl_stmt|;
comment|/* FREAD | FWRITE */
name|spa_log_state_t
name|spa_log_state
decl_stmt|;
comment|/* log state */
name|uint64_t
name|spa_autoexpand
decl_stmt|;
comment|/* lun expansion on/off */
name|ddt_t
modifier|*
name|spa_ddt
index|[
name|ZIO_CHECKSUM_FUNCTIONS
index|]
decl_stmt|;
comment|/* in-core DDTs */
name|uint64_t
name|spa_ddt_stat_object
decl_stmt|;
comment|/* DDT statistics */
name|uint64_t
name|spa_dedup_ditto
decl_stmt|;
comment|/* dedup ditto threshold */
name|uint64_t
name|spa_dedup_checksum
decl_stmt|;
comment|/* default dedup checksum */
name|uint64_t
name|spa_dspace
decl_stmt|;
comment|/* dspace in normal class */
name|kmutex_t
name|spa_vdev_top_lock
decl_stmt|;
comment|/* dueling offline/remove */
name|kmutex_t
name|spa_proc_lock
decl_stmt|;
comment|/* protects spa_proc* */
name|kcondvar_t
name|spa_proc_cv
decl_stmt|;
comment|/* spa_proc_state transitions */
name|spa_proc_state_t
name|spa_proc_state
decl_stmt|;
comment|/* see definition */
name|struct
name|proc
modifier|*
name|spa_proc
decl_stmt|;
comment|/* "zpool-poolname" process */
name|uint64_t
name|spa_did
decl_stmt|;
comment|/* if procp != p0, did of t1 */
name|boolean_t
name|spa_autoreplace
decl_stmt|;
comment|/* autoreplace set in open */
name|int
name|spa_vdev_locks
decl_stmt|;
comment|/* locks grabbed */
name|uint64_t
name|spa_creation_version
decl_stmt|;
comment|/* version at pool creation */
name|uint64_t
name|spa_prev_software_version
decl_stmt|;
comment|/* See ub_software_version */
name|uint64_t
name|spa_feat_for_write_obj
decl_stmt|;
comment|/* required to write to pool */
name|uint64_t
name|spa_feat_for_read_obj
decl_stmt|;
comment|/* required to read from pool */
name|uint64_t
name|spa_feat_desc_obj
decl_stmt|;
comment|/* Feature descriptions */
name|uint64_t
name|spa_feat_enabled_txg_obj
decl_stmt|;
comment|/* Feature enabled txg */
comment|/* cache feature refcounts */
name|uint64_t
name|spa_feat_refcount_cache
index|[
name|SPA_FEATURES
index|]
decl_stmt|;
name|cyclic_id_t
name|spa_deadman_cycid
decl_stmt|;
comment|/* cyclic id */
name|uint64_t
name|spa_deadman_calls
decl_stmt|;
comment|/* number of deadman calls */
name|hrtime_t
name|spa_sync_starttime
decl_stmt|;
comment|/* starting time fo spa_sync */
name|uint64_t
name|spa_deadman_synctime
decl_stmt|;
comment|/* deadman expiration timer */
name|uint64_t
name|spa_all_vdev_zaps
decl_stmt|;
comment|/* ZAP of per-vd ZAP obj #s */
name|spa_avz_action_t
name|spa_avz_action
decl_stmt|;
comment|/* destroy/rebuild AVZ? */
comment|/* 	 * spa_iokstat_lock protects spa_iokstat and 	 * spa_queue_stats[]. 	 */
name|kmutex_t
name|spa_iokstat_lock
decl_stmt|;
name|struct
name|kstat
modifier|*
name|spa_iokstat
decl_stmt|;
comment|/* kstat of io to this pool */
struct|struct
block|{
name|int
name|spa_active
decl_stmt|;
name|int
name|spa_queued
decl_stmt|;
block|}
name|spa_queue_stats
index|[
name|ZIO_PRIORITY_NUM_QUEUEABLE
index|]
struct|;
name|hrtime_t
name|spa_ccw_fail_time
decl_stmt|;
comment|/* Conf cache write fail time */
comment|/* 	 * spa_refcount& spa_config_lock must be the last elements 	 * because refcount_t changes size based on compilation options. 	 * In order for the MDB module to function correctly, the other 	 * fields must remain in the same location. 	 */
name|spa_config_lock_t
name|spa_config_lock
index|[
name|SCL_LOCKS
index|]
decl_stmt|;
comment|/* config changes */
name|refcount_t
name|spa_refcount
decl_stmt|;
comment|/* number of opens */
block|}
struct|;
specifier|extern
specifier|const
name|char
modifier|*
name|spa_config_path
decl_stmt|;
specifier|extern
name|void
name|spa_taskq_dispatch_ent
parameter_list|(
name|spa_t
modifier|*
name|spa
parameter_list|,
name|zio_type_t
name|t
parameter_list|,
name|zio_taskq_type_t
name|q
parameter_list|,
name|task_func_t
modifier|*
name|func
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|uint_t
name|flags
parameter_list|,
name|taskq_ent_t
modifier|*
name|ent
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
comment|/* _SYS_SPA_IMPL_H */
end_comment

end_unit

