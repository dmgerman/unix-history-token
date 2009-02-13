begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2007 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
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
name|spa_config_lock
block|{
name|kmutex_t
name|scl_lock
decl_stmt|;
name|refcount_t
name|scl_count
decl_stmt|;
name|kthread_t
modifier|*
name|scl_writer
decl_stmt|;
name|kcondvar_t
name|scl_cv
decl_stmt|;
block|}
name|spa_config_lock_t
typedef|;
typedef|typedef
struct|struct
name|spa_error_entry
block|{
name|zbookmark_t
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
typedef|typedef
struct|struct
name|spa_props
block|{
name|nvlist_t
modifier|*
name|spa_props_nvp
decl_stmt|;
name|list_node_t
name|spa_list_node
decl_stmt|;
block|}
name|spa_props_t
typedef|;
struct|struct
name|spa
block|{
comment|/* 	 * Fields protected by spa_namespace_lock. 	 */
name|char
modifier|*
name|spa_name
decl_stmt|;
comment|/* pool name */
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
name|uint64_t
name|spa_config_txg
decl_stmt|;
comment|/* txg of last config change */
name|kmutex_t
name|spa_config_cache_lock
decl_stmt|;
comment|/* for spa_config RW_READER */
name|int
name|spa_sync_pass
decl_stmt|;
comment|/* iterate-to-convergence */
name|int
name|spa_state
decl_stmt|;
comment|/* pool state */
name|int
name|spa_inject_ref
decl_stmt|;
comment|/* injection references */
name|uint8_t
name|spa_traverse_wanted
decl_stmt|;
comment|/* traverse lock wanted */
name|uint8_t
name|spa_sync_on
decl_stmt|;
comment|/* sync threads are running */
name|spa_load_state_t
name|spa_load_state
decl_stmt|;
comment|/* current load operation */
name|taskq_t
modifier|*
name|spa_zio_issue_taskq
index|[
name|ZIO_TYPES
index|]
decl_stmt|;
name|taskq_t
modifier|*
name|spa_zio_intr_taskq
index|[
name|ZIO_TYPES
index|]
decl_stmt|;
name|dsl_pool_t
modifier|*
name|spa_dsl_pool
decl_stmt|;
name|metaslab_class_t
modifier|*
name|spa_normal_class
decl_stmt|;
comment|/* normal data class */
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
name|objset_t
modifier|*
name|spa_meta_objset
decl_stmt|;
comment|/* copy of dp->dp_meta_objset */
name|txg_list_t
name|spa_vdev_txg_list
decl_stmt|;
comment|/* per-txg dirty vdev list */
name|vdev_t
modifier|*
name|spa_root_vdev
decl_stmt|;
comment|/* top-level vdev container */
name|uint64_t
name|spa_load_guid
decl_stmt|;
comment|/* initial guid for spa_load */
name|list_t
name|spa_dirty_list
decl_stmt|;
comment|/* vdevs with dirty labels */
name|uint64_t
name|spa_spares_object
decl_stmt|;
comment|/* MOS object for spare list */
name|nvlist_t
modifier|*
name|spa_sparelist
decl_stmt|;
comment|/* cached spare config */
name|vdev_t
modifier|*
modifier|*
name|spa_spares
decl_stmt|;
comment|/* available hot spares */
name|int
name|spa_nspares
decl_stmt|;
comment|/* number of hot spares */
name|boolean_t
name|spa_sync_spares
decl_stmt|;
comment|/* sync the spares list */
name|uint64_t
name|spa_config_object
decl_stmt|;
comment|/* MOS object for pool config */
name|uint64_t
name|spa_syncing_txg
decl_stmt|;
comment|/* txg currently syncing */
name|uint64_t
name|spa_sync_bplist_obj
decl_stmt|;
comment|/* object for deferred frees */
name|bplist_t
name|spa_sync_bplist
decl_stmt|;
comment|/* deferred-free bplist */
name|krwlock_t
name|spa_traverse_lock
decl_stmt|;
comment|/* traverse vs. spa_sync() */
name|uberblock_t
name|spa_ubsync
decl_stmt|;
comment|/* last synced uberblock */
name|uberblock_t
name|spa_uberblock
decl_stmt|;
comment|/* current uberblock */
name|kmutex_t
name|spa_scrub_lock
decl_stmt|;
comment|/* resilver/scrub lock */
name|kthread_t
modifier|*
name|spa_scrub_thread
decl_stmt|;
comment|/* scrub/resilver thread */
name|traverse_handle_t
modifier|*
name|spa_scrub_th
decl_stmt|;
comment|/* scrub traverse handle */
name|uint64_t
name|spa_scrub_restart_txg
decl_stmt|;
comment|/* need to restart */
name|uint64_t
name|spa_scrub_mintxg
decl_stmt|;
comment|/* min txg we'll scrub */
name|uint64_t
name|spa_scrub_maxtxg
decl_stmt|;
comment|/* max txg we'll scrub */
name|uint64_t
name|spa_scrub_inflight
decl_stmt|;
comment|/* in-flight scrub I/Os */
name|uint64_t
name|spa_scrub_maxinflight
decl_stmt|;
comment|/* max in-flight scrub I/Os */
name|uint64_t
name|spa_scrub_errors
decl_stmt|;
comment|/* scrub I/O error count */
name|int
name|spa_scrub_suspended
decl_stmt|;
comment|/* tell scrubber to suspend */
name|kcondvar_t
name|spa_scrub_cv
decl_stmt|;
comment|/* scrub thread state change */
name|kcondvar_t
name|spa_scrub_io_cv
decl_stmt|;
comment|/* scrub I/O completion */
name|uint8_t
name|spa_scrub_stop
decl_stmt|;
comment|/* tell scrubber to stop */
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
name|kmutex_t
name|spa_uberblock_lock
decl_stmt|;
comment|/* vdev_uberblock_load_done() */
name|uint64_t
name|spa_ena
decl_stmt|;
comment|/* spa-wide ereport ENA */
name|boolean_t
name|spa_last_open_failed
decl_stmt|;
comment|/* true if last open faled */
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
name|nvlist_t
modifier|*
modifier|*
name|spa_pending_spares
decl_stmt|;
comment|/* pending spare additions */
name|uint_t
name|spa_pending_nspares
decl_stmt|;
comment|/* # pending spares */
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
comment|/* 	 * spa_refcnt must be the last element because it changes size based on 	 * compilation options.  In order for the MDB module to function 	 * correctly, the other fields must remain in the same location. 	 */
name|spa_config_lock_t
name|spa_config_lock
decl_stmt|;
comment|/* configuration changes */
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
name|spa_config_dir
decl_stmt|;
specifier|extern
name|kmutex_t
name|spa_namespace_lock
decl_stmt|;
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

