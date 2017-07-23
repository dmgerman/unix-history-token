begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2005, 2010, Oracle and/or its affiliates. All rights reserved.  * Copyright (c) 2011, 2015 by Delphix. All rights reserved.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_VDEV_IMPL_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_VDEV_IMPL_H
end_define

begin_include
include|#
directive|include
file|<sys/avl.h>
end_include

begin_include
include|#
directive|include
file|<sys/dmu.h>
end_include

begin_include
include|#
directive|include
file|<sys/metaslab.h>
end_include

begin_include
include|#
directive|include
file|<sys/nvpair.h>
end_include

begin_include
include|#
directive|include
file|<sys/space_map.h>
end_include

begin_include
include|#
directive|include
file|<sys/vdev.h>
end_include

begin_include
include|#
directive|include
file|<sys/dkio.h>
end_include

begin_include
include|#
directive|include
file|<sys/uberblock_impl.h>
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
comment|/*  * Virtual device descriptors.  *  * All storage pool operations go through the virtual device framework,  * which provides data replication and I/O scheduling.  */
comment|/*  * Forward declarations that lots of things need.  */
typedef|typedef
name|struct
name|vdev_queue
name|vdev_queue_t
typedef|;
typedef|typedef
name|struct
name|vdev_cache
name|vdev_cache_t
typedef|;
typedef|typedef
name|struct
name|vdev_cache_entry
name|vdev_cache_entry_t
typedef|;
struct_decl|struct
name|abd
struct_decl|;
specifier|extern
name|int
name|zfs_vdev_queue_depth_pct
decl_stmt|;
specifier|extern
name|uint32_t
name|zfs_vdev_async_write_max_active
decl_stmt|;
comment|/*  * Virtual device operations  */
typedef|typedef
name|int
name|vdev_open_func_t
parameter_list|(
name|vdev_t
modifier|*
name|vd
parameter_list|,
name|uint64_t
modifier|*
name|size
parameter_list|,
name|uint64_t
modifier|*
name|max_size
parameter_list|,
name|uint64_t
modifier|*
name|logical_ashift
parameter_list|,
name|uint64_t
modifier|*
name|physical_ashift
parameter_list|)
function_decl|;
typedef|typedef
name|void
name|vdev_close_func_t
parameter_list|(
name|vdev_t
modifier|*
name|vd
parameter_list|)
function_decl|;
typedef|typedef
name|uint64_t
name|vdev_asize_func_t
parameter_list|(
name|vdev_t
modifier|*
name|vd
parameter_list|,
name|uint64_t
name|psize
parameter_list|)
function_decl|;
typedef|typedef
name|void
name|vdev_io_start_func_t
parameter_list|(
name|zio_t
modifier|*
name|zio
parameter_list|)
function_decl|;
typedef|typedef
name|void
name|vdev_io_done_func_t
parameter_list|(
name|zio_t
modifier|*
name|zio
parameter_list|)
function_decl|;
typedef|typedef
name|void
name|vdev_state_change_func_t
parameter_list|(
name|vdev_t
modifier|*
name|vd
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
typedef|typedef
name|void
name|vdev_hold_func_t
parameter_list|(
name|vdev_t
modifier|*
name|vd
parameter_list|)
function_decl|;
typedef|typedef
name|void
name|vdev_rele_func_t
parameter_list|(
name|vdev_t
modifier|*
name|vd
parameter_list|)
function_decl|;
typedef|typedef
struct|struct
name|vdev_ops
block|{
name|vdev_open_func_t
modifier|*
name|vdev_op_open
decl_stmt|;
name|vdev_close_func_t
modifier|*
name|vdev_op_close
decl_stmt|;
name|vdev_asize_func_t
modifier|*
name|vdev_op_asize
decl_stmt|;
name|vdev_io_start_func_t
modifier|*
name|vdev_op_io_start
decl_stmt|;
name|vdev_io_done_func_t
modifier|*
name|vdev_op_io_done
decl_stmt|;
name|vdev_state_change_func_t
modifier|*
name|vdev_op_state_change
decl_stmt|;
name|vdev_hold_func_t
modifier|*
name|vdev_op_hold
decl_stmt|;
name|vdev_rele_func_t
modifier|*
name|vdev_op_rele
decl_stmt|;
name|char
name|vdev_op_type
index|[
literal|16
index|]
decl_stmt|;
name|boolean_t
name|vdev_op_leaf
decl_stmt|;
block|}
name|vdev_ops_t
typedef|;
comment|/*  * Virtual device properties  */
struct|struct
name|vdev_cache_entry
block|{
name|struct
name|abd
modifier|*
name|ve_abd
decl_stmt|;
name|uint64_t
name|ve_offset
decl_stmt|;
name|uint64_t
name|ve_lastused
decl_stmt|;
name|avl_node_t
name|ve_offset_node
decl_stmt|;
name|avl_node_t
name|ve_lastused_node
decl_stmt|;
name|uint32_t
name|ve_hits
decl_stmt|;
name|uint16_t
name|ve_missed_update
decl_stmt|;
name|zio_t
modifier|*
name|ve_fill_io
decl_stmt|;
block|}
struct|;
struct|struct
name|vdev_cache
block|{
name|avl_tree_t
name|vc_offset_tree
decl_stmt|;
name|avl_tree_t
name|vc_lastused_tree
decl_stmt|;
name|kmutex_t
name|vc_lock
decl_stmt|;
block|}
struct|;
typedef|typedef
struct|struct
name|vdev_queue_class
block|{
name|uint32_t
name|vqc_active
decl_stmt|;
comment|/* 	 * Sorted by offset or timestamp, depending on if the queue is 	 * LBA-ordered vs FIFO. 	 */
name|avl_tree_t
name|vqc_queued_tree
decl_stmt|;
block|}
name|vdev_queue_class_t
typedef|;
struct|struct
name|vdev_queue
block|{
name|vdev_t
modifier|*
name|vq_vdev
decl_stmt|;
name|vdev_queue_class_t
name|vq_class
index|[
name|ZIO_PRIORITY_NUM_QUEUEABLE
index|]
decl_stmt|;
name|avl_tree_t
name|vq_active_tree
decl_stmt|;
name|avl_tree_t
name|vq_read_offset_tree
decl_stmt|;
name|avl_tree_t
name|vq_write_offset_tree
decl_stmt|;
name|uint64_t
name|vq_last_offset
decl_stmt|;
name|hrtime_t
name|vq_io_complete_ts
decl_stmt|;
comment|/* time last i/o completed */
name|kmutex_t
name|vq_lock
decl_stmt|;
name|uint64_t
name|vq_lastoffset
decl_stmt|;
block|}
struct|;
comment|/*  * Virtual device descriptor  */
struct|struct
name|vdev
block|{
comment|/* 	 * Common to all vdev types. 	 */
name|uint64_t
name|vdev_id
decl_stmt|;
comment|/* child number in vdev parent	*/
name|uint64_t
name|vdev_guid
decl_stmt|;
comment|/* unique ID for this vdev	*/
name|uint64_t
name|vdev_guid_sum
decl_stmt|;
comment|/* self guid + all child guids	*/
name|uint64_t
name|vdev_orig_guid
decl_stmt|;
comment|/* orig. guid prior to remove	*/
name|uint64_t
name|vdev_asize
decl_stmt|;
comment|/* allocatable device capacity	*/
name|uint64_t
name|vdev_min_asize
decl_stmt|;
comment|/* min acceptable asize		*/
name|uint64_t
name|vdev_max_asize
decl_stmt|;
comment|/* max acceptable asize		*/
name|uint64_t
name|vdev_ashift
decl_stmt|;
comment|/* block alignment shift	*/
comment|/* 	 * Logical block alignment shift 	 * 	 * The smallest sized/aligned I/O supported by the device. 	 */
name|uint64_t
name|vdev_logical_ashift
decl_stmt|;
comment|/* 	 * Physical block alignment shift 	 * 	 * The device supports logical I/Os with vdev_logical_ashift 	 * size/alignment, but optimum performance will be achieved by 	 * aligning/sizing requests to vdev_physical_ashift.  Smaller 	 * requests may be inflated or incur device level read-modify-write 	 * operations. 	 * 	 * May be 0 to indicate no preference (i.e. use vdev_logical_ashift).          */
name|uint64_t
name|vdev_physical_ashift
decl_stmt|;
name|uint64_t
name|vdev_state
decl_stmt|;
comment|/* see VDEV_STATE_* #defines	*/
name|uint64_t
name|vdev_prevstate
decl_stmt|;
comment|/* used when reopening a vdev	*/
name|vdev_ops_t
modifier|*
name|vdev_ops
decl_stmt|;
comment|/* vdev operations		*/
name|spa_t
modifier|*
name|vdev_spa
decl_stmt|;
comment|/* spa for this vdev		*/
name|void
modifier|*
name|vdev_tsd
decl_stmt|;
comment|/* type-specific data		*/
name|vnode_t
modifier|*
name|vdev_name_vp
decl_stmt|;
comment|/* vnode for pathname		*/
name|vnode_t
modifier|*
name|vdev_devid_vp
decl_stmt|;
comment|/* vnode for devid		*/
name|vdev_t
modifier|*
name|vdev_top
decl_stmt|;
comment|/* top-level vdev		*/
name|vdev_t
modifier|*
name|vdev_parent
decl_stmt|;
comment|/* parent vdev			*/
name|vdev_t
modifier|*
modifier|*
name|vdev_child
decl_stmt|;
comment|/* array of children		*/
name|uint64_t
name|vdev_children
decl_stmt|;
comment|/* number of children		*/
name|vdev_stat_t
name|vdev_stat
decl_stmt|;
comment|/* virtual device statistics	*/
name|boolean_t
name|vdev_expanding
decl_stmt|;
comment|/* expand the vdev?		*/
name|boolean_t
name|vdev_reopening
decl_stmt|;
comment|/* reopen in progress?		*/
name|int
name|vdev_open_error
decl_stmt|;
comment|/* error on last open		*/
name|kthread_t
modifier|*
name|vdev_open_thread
decl_stmt|;
comment|/* thread opening children	*/
name|uint64_t
name|vdev_crtxg
decl_stmt|;
comment|/* txg when top-level was added */
comment|/* 	 * Top-level vdev state. 	 */
name|uint64_t
name|vdev_ms_array
decl_stmt|;
comment|/* metaslab array object	*/
name|uint64_t
name|vdev_ms_shift
decl_stmt|;
comment|/* metaslab size shift		*/
name|uint64_t
name|vdev_ms_count
decl_stmt|;
comment|/* number of metaslabs		*/
name|metaslab_group_t
modifier|*
name|vdev_mg
decl_stmt|;
comment|/* metaslab group		*/
name|metaslab_t
modifier|*
modifier|*
name|vdev_ms
decl_stmt|;
comment|/* metaslab array		*/
name|txg_list_t
name|vdev_ms_list
decl_stmt|;
comment|/* per-txg dirty metaslab lists	*/
name|txg_list_t
name|vdev_dtl_list
decl_stmt|;
comment|/* per-txg dirty DTL lists	*/
name|txg_node_t
name|vdev_txg_node
decl_stmt|;
comment|/* per-txg dirty vdev linkage	*/
name|boolean_t
name|vdev_remove_wanted
decl_stmt|;
comment|/* async remove wanted?	*/
name|boolean_t
name|vdev_probe_wanted
decl_stmt|;
comment|/* async probe wanted?	*/
name|list_node_t
name|vdev_config_dirty_node
decl_stmt|;
comment|/* config dirty list	*/
name|list_node_t
name|vdev_state_dirty_node
decl_stmt|;
comment|/* state dirty list	*/
name|uint64_t
name|vdev_deflate_ratio
decl_stmt|;
comment|/* deflation ratio (x512)	*/
name|uint64_t
name|vdev_islog
decl_stmt|;
comment|/* is an intent log device	*/
name|uint64_t
name|vdev_removing
decl_stmt|;
comment|/* device is being removed?	*/
name|boolean_t
name|vdev_ishole
decl_stmt|;
comment|/* is a hole in the namespace	*/
name|kmutex_t
name|vdev_queue_lock
decl_stmt|;
comment|/* protects vdev_queue_depth	*/
name|uint64_t
name|vdev_top_zap
decl_stmt|;
comment|/* 	 * The queue depth parameters determine how many async writes are 	 * still pending (i.e. allocated by net yet issued to disk) per 	 * top-level (vdev_async_write_queue_depth) and the maximum allowed 	 * (vdev_max_async_write_queue_depth). These values only apply to 	 * top-level vdevs. 	 */
name|uint64_t
name|vdev_async_write_queue_depth
decl_stmt|;
name|uint64_t
name|vdev_max_async_write_queue_depth
decl_stmt|;
comment|/* 	 * Leaf vdev state. 	 */
name|range_tree_t
modifier|*
name|vdev_dtl
index|[
name|DTL_TYPES
index|]
decl_stmt|;
comment|/* dirty time logs	*/
name|space_map_t
modifier|*
name|vdev_dtl_sm
decl_stmt|;
comment|/* dirty time log space map	*/
name|txg_node_t
name|vdev_dtl_node
decl_stmt|;
comment|/* per-txg dirty DTL linkage	*/
name|uint64_t
name|vdev_dtl_object
decl_stmt|;
comment|/* DTL object			*/
name|uint64_t
name|vdev_psize
decl_stmt|;
comment|/* physical device capacity	*/
name|uint64_t
name|vdev_wholedisk
decl_stmt|;
comment|/* true if this is a whole disk */
name|uint64_t
name|vdev_offline
decl_stmt|;
comment|/* persistent offline state	*/
name|uint64_t
name|vdev_faulted
decl_stmt|;
comment|/* persistent faulted state	*/
name|uint64_t
name|vdev_degraded
decl_stmt|;
comment|/* persistent degraded state	*/
name|uint64_t
name|vdev_removed
decl_stmt|;
comment|/* persistent removed state	*/
name|uint64_t
name|vdev_resilver_txg
decl_stmt|;
comment|/* persistent resilvering state */
name|uint64_t
name|vdev_nparity
decl_stmt|;
comment|/* number of parity devices for raidz */
name|char
modifier|*
name|vdev_path
decl_stmt|;
comment|/* vdev path (if any)		*/
name|char
modifier|*
name|vdev_devid
decl_stmt|;
comment|/* vdev devid (if any)		*/
name|char
modifier|*
name|vdev_physpath
decl_stmt|;
comment|/* vdev device path (if any)	*/
name|char
modifier|*
name|vdev_fru
decl_stmt|;
comment|/* physical FRU location	*/
name|uint64_t
name|vdev_not_present
decl_stmt|;
comment|/* not present during import	*/
name|uint64_t
name|vdev_unspare
decl_stmt|;
comment|/* unspare when resilvering done */
name|boolean_t
name|vdev_nowritecache
decl_stmt|;
comment|/* true if flushwritecache failed */
name|boolean_t
name|vdev_notrim
decl_stmt|;
comment|/* true if trim failed */
name|boolean_t
name|vdev_checkremove
decl_stmt|;
comment|/* temporary online test	*/
name|boolean_t
name|vdev_forcefault
decl_stmt|;
comment|/* force online fault		*/
name|boolean_t
name|vdev_splitting
decl_stmt|;
comment|/* split or repair in progress  */
name|boolean_t
name|vdev_delayed_close
decl_stmt|;
comment|/* delayed device close?	*/
name|boolean_t
name|vdev_tmpoffline
decl_stmt|;
comment|/* device taken offline temporarily? */
name|boolean_t
name|vdev_detached
decl_stmt|;
comment|/* device detached?		*/
name|boolean_t
name|vdev_cant_read
decl_stmt|;
comment|/* vdev is failing all reads	*/
name|boolean_t
name|vdev_cant_write
decl_stmt|;
comment|/* vdev is failing all writes	*/
name|boolean_t
name|vdev_isspare
decl_stmt|;
comment|/* was a hot spare		*/
name|boolean_t
name|vdev_isl2cache
decl_stmt|;
comment|/* was a l2cache device		*/
name|vdev_queue_t
name|vdev_queue
decl_stmt|;
comment|/* I/O deadline schedule queue	*/
name|vdev_cache_t
name|vdev_cache
decl_stmt|;
comment|/* physical block cache		*/
name|spa_aux_vdev_t
modifier|*
name|vdev_aux
decl_stmt|;
comment|/* for l2cache and spares vdevs	*/
name|zio_t
modifier|*
name|vdev_probe_zio
decl_stmt|;
comment|/* root of current probe	*/
name|vdev_aux_t
name|vdev_label_aux
decl_stmt|;
comment|/* on-disk aux state		*/
name|struct
name|trim_map
modifier|*
name|vdev_trimmap
decl_stmt|;
comment|/* map on outstanding trims	*/
name|uint16_t
name|vdev_rotation_rate
decl_stmt|;
comment|/* rotational rate of the media */
define|#
directive|define
name|VDEV_RATE_UNKNOWN
value|0
define|#
directive|define
name|VDEV_RATE_NON_ROTATING
value|1
name|uint64_t
name|vdev_leaf_zap
decl_stmt|;
comment|/* 	 * For DTrace to work in userland (libzpool) context, these fields must 	 * remain at the end of the structure.  DTrace will use the kernel's 	 * CTF definition for 'struct vdev', and since the size of a kmutex_t is 	 * larger in userland, the offsets for the rest of the fields would be 	 * incorrect. 	 */
name|kmutex_t
name|vdev_dtl_lock
decl_stmt|;
comment|/* vdev_dtl_{map,resilver}	*/
name|kmutex_t
name|vdev_stat_lock
decl_stmt|;
comment|/* vdev_stat			*/
name|kmutex_t
name|vdev_probe_lock
decl_stmt|;
comment|/* protects vdev_probe_zio	*/
block|}
struct|;
define|#
directive|define
name|VDEV_RAIDZ_MAXPARITY
value|3
define|#
directive|define
name|VDEV_PAD_SIZE
value|(8<< 10)
comment|/* 2 padding areas (vl_pad1 and vl_pad2) to skip */
define|#
directive|define
name|VDEV_SKIP_SIZE
value|VDEV_PAD_SIZE * 2
define|#
directive|define
name|VDEV_PHYS_SIZE
value|(112<< 10)
define|#
directive|define
name|VDEV_UBERBLOCK_RING
value|(128<< 10)
comment|/* The largest uberblock we support is 8k. */
define|#
directive|define
name|MAX_UBERBLOCK_SHIFT
value|(13)
define|#
directive|define
name|VDEV_UBERBLOCK_SHIFT
parameter_list|(
name|vd
parameter_list|)
define|\
value|MIN(MAX((vd)->vdev_top->vdev_ashift, UBERBLOCK_SHIFT), \ 	    MAX_UBERBLOCK_SHIFT)
define|#
directive|define
name|VDEV_UBERBLOCK_COUNT
parameter_list|(
name|vd
parameter_list|)
define|\
value|(VDEV_UBERBLOCK_RING>> VDEV_UBERBLOCK_SHIFT(vd))
define|#
directive|define
name|VDEV_UBERBLOCK_OFFSET
parameter_list|(
name|vd
parameter_list|,
name|n
parameter_list|)
define|\
value|offsetof(vdev_label_t, vl_uberblock[(n)<< VDEV_UBERBLOCK_SHIFT(vd)])
define|#
directive|define
name|VDEV_UBERBLOCK_SIZE
parameter_list|(
name|vd
parameter_list|)
value|(1ULL<< VDEV_UBERBLOCK_SHIFT(vd))
typedef|typedef
struct|struct
name|vdev_phys
block|{
name|char
name|vp_nvlist
index|[
name|VDEV_PHYS_SIZE
operator|-
sizeof|sizeof
argument_list|(
name|zio_eck_t
argument_list|)
index|]
decl_stmt|;
name|zio_eck_t
name|vp_zbt
decl_stmt|;
block|}
name|vdev_phys_t
typedef|;
typedef|typedef
struct|struct
name|vdev_label
block|{
name|char
name|vl_pad1
index|[
name|VDEV_PAD_SIZE
index|]
decl_stmt|;
comment|/*  8K */
name|char
name|vl_pad2
index|[
name|VDEV_PAD_SIZE
index|]
decl_stmt|;
comment|/*  8K */
name|vdev_phys_t
name|vl_vdev_phys
decl_stmt|;
comment|/* 112K	*/
name|char
name|vl_uberblock
index|[
name|VDEV_UBERBLOCK_RING
index|]
decl_stmt|;
comment|/* 128K	*/
block|}
name|vdev_label_t
typedef|;
comment|/* 256K total */
comment|/*  * vdev_dirty() flags  */
define|#
directive|define
name|VDD_METASLAB
value|0x01
define|#
directive|define
name|VDD_DTL
value|0x02
comment|/* Offset of embedded boot loader region on each label */
define|#
directive|define
name|VDEV_BOOT_OFFSET
value|(2 * sizeof (vdev_label_t))
comment|/*  * Size of embedded boot loader region on each label.  * The total size of the first two labels plus the boot area is 4MB.  */
define|#
directive|define
name|VDEV_BOOT_SIZE
value|(7ULL<< 19)
comment|/* 3.5M */
comment|/*  * Size of label regions at the start and end of each leaf device.  */
define|#
directive|define
name|VDEV_LABEL_START_SIZE
value|(2 * sizeof (vdev_label_t) + VDEV_BOOT_SIZE)
define|#
directive|define
name|VDEV_LABEL_END_SIZE
value|(2 * sizeof (vdev_label_t))
define|#
directive|define
name|VDEV_LABELS
value|4
define|#
directive|define
name|VDEV_BEST_LABEL
value|VDEV_LABELS
define|#
directive|define
name|VDEV_ALLOC_LOAD
value|0
define|#
directive|define
name|VDEV_ALLOC_ADD
value|1
define|#
directive|define
name|VDEV_ALLOC_SPARE
value|2
define|#
directive|define
name|VDEV_ALLOC_L2CACHE
value|3
define|#
directive|define
name|VDEV_ALLOC_ROOTPOOL
value|4
define|#
directive|define
name|VDEV_ALLOC_SPLIT
value|5
define|#
directive|define
name|VDEV_ALLOC_ATTACH
value|6
comment|/*  * Allocate or free a vdev  */
specifier|extern
name|vdev_t
modifier|*
name|vdev_alloc_common
parameter_list|(
name|spa_t
modifier|*
name|spa
parameter_list|,
name|uint_t
name|id
parameter_list|,
name|uint64_t
name|guid
parameter_list|,
name|vdev_ops_t
modifier|*
name|ops
parameter_list|)
function_decl|;
specifier|extern
name|int
name|vdev_alloc
parameter_list|(
name|spa_t
modifier|*
name|spa
parameter_list|,
name|vdev_t
modifier|*
modifier|*
name|vdp
parameter_list|,
name|nvlist_t
modifier|*
name|config
parameter_list|,
name|vdev_t
modifier|*
name|parent
parameter_list|,
name|uint_t
name|id
parameter_list|,
name|int
name|alloctype
parameter_list|)
function_decl|;
specifier|extern
name|void
name|vdev_free
parameter_list|(
name|vdev_t
modifier|*
name|vd
parameter_list|)
function_decl|;
comment|/*  * Add or remove children and parents  */
specifier|extern
name|void
name|vdev_add_child
parameter_list|(
name|vdev_t
modifier|*
name|pvd
parameter_list|,
name|vdev_t
modifier|*
name|cvd
parameter_list|)
function_decl|;
specifier|extern
name|void
name|vdev_remove_child
parameter_list|(
name|vdev_t
modifier|*
name|pvd
parameter_list|,
name|vdev_t
modifier|*
name|cvd
parameter_list|)
function_decl|;
specifier|extern
name|void
name|vdev_compact_children
parameter_list|(
name|vdev_t
modifier|*
name|pvd
parameter_list|)
function_decl|;
specifier|extern
name|vdev_t
modifier|*
name|vdev_add_parent
parameter_list|(
name|vdev_t
modifier|*
name|cvd
parameter_list|,
name|vdev_ops_t
modifier|*
name|ops
parameter_list|)
function_decl|;
specifier|extern
name|void
name|vdev_remove_parent
parameter_list|(
name|vdev_t
modifier|*
name|cvd
parameter_list|)
function_decl|;
comment|/*  * vdev sync load and sync  */
specifier|extern
name|void
name|vdev_load_log_state
parameter_list|(
name|vdev_t
modifier|*
name|nvd
parameter_list|,
name|vdev_t
modifier|*
name|ovd
parameter_list|)
function_decl|;
specifier|extern
name|boolean_t
name|vdev_log_state_valid
parameter_list|(
name|vdev_t
modifier|*
name|vd
parameter_list|)
function_decl|;
specifier|extern
name|void
name|vdev_load
parameter_list|(
name|vdev_t
modifier|*
name|vd
parameter_list|)
function_decl|;
specifier|extern
name|int
name|vdev_dtl_load
parameter_list|(
name|vdev_t
modifier|*
name|vd
parameter_list|)
function_decl|;
specifier|extern
name|void
name|vdev_sync
parameter_list|(
name|vdev_t
modifier|*
name|vd
parameter_list|,
name|uint64_t
name|txg
parameter_list|)
function_decl|;
specifier|extern
name|void
name|vdev_sync_done
parameter_list|(
name|vdev_t
modifier|*
name|vd
parameter_list|,
name|uint64_t
name|txg
parameter_list|)
function_decl|;
specifier|extern
name|void
name|vdev_dirty
parameter_list|(
name|vdev_t
modifier|*
name|vd
parameter_list|,
name|int
name|flags
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|uint64_t
name|txg
parameter_list|)
function_decl|;
specifier|extern
name|void
name|vdev_dirty_leaves
parameter_list|(
name|vdev_t
modifier|*
name|vd
parameter_list|,
name|int
name|flags
parameter_list|,
name|uint64_t
name|txg
parameter_list|)
function_decl|;
comment|/*  * Available vdev types.  */
specifier|extern
name|vdev_ops_t
name|vdev_root_ops
decl_stmt|;
specifier|extern
name|vdev_ops_t
name|vdev_mirror_ops
decl_stmt|;
specifier|extern
name|vdev_ops_t
name|vdev_replacing_ops
decl_stmt|;
specifier|extern
name|vdev_ops_t
name|vdev_raidz_ops
decl_stmt|;
ifdef|#
directive|ifdef
name|_KERNEL
specifier|extern
name|vdev_ops_t
name|vdev_geom_ops
decl_stmt|;
else|#
directive|else
specifier|extern
name|vdev_ops_t
name|vdev_disk_ops
decl_stmt|;
endif|#
directive|endif
specifier|extern
name|vdev_ops_t
name|vdev_file_ops
decl_stmt|;
specifier|extern
name|vdev_ops_t
name|vdev_missing_ops
decl_stmt|;
specifier|extern
name|vdev_ops_t
name|vdev_hole_ops
decl_stmt|;
specifier|extern
name|vdev_ops_t
name|vdev_spare_ops
decl_stmt|;
comment|/*  * Common size functions  */
specifier|extern
name|uint64_t
name|vdev_default_asize
parameter_list|(
name|vdev_t
modifier|*
name|vd
parameter_list|,
name|uint64_t
name|psize
parameter_list|)
function_decl|;
specifier|extern
name|uint64_t
name|vdev_get_min_asize
parameter_list|(
name|vdev_t
modifier|*
name|vd
parameter_list|)
function_decl|;
specifier|extern
name|void
name|vdev_set_min_asize
parameter_list|(
name|vdev_t
modifier|*
name|vd
parameter_list|)
function_decl|;
comment|/*  * Global variables  */
comment|/* zdb uses this tunable, so it must be declared here to make lint happy. */
specifier|extern
name|int
name|zfs_vdev_cache_size
decl_stmt|;
specifier|extern
name|uint_t
name|zfs_geom_probe_vdev_key
decl_stmt|;
ifdef|#
directive|ifdef
name|illumos
comment|/*  * The vdev_buf_t is used to translate between zio_t and buf_t, and back again.  */
typedef|typedef
struct|struct
name|vdev_buf
block|{
name|buf_t
name|vb_buf
decl_stmt|;
comment|/* buffer that describes the io */
name|zio_t
modifier|*
name|vb_io
decl_stmt|;
comment|/* pointer back to the original zio_t */
block|}
name|vdev_buf_t
typedef|;
endif|#
directive|endif
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
comment|/* _SYS_VDEV_IMPL_H */
end_comment

end_unit

