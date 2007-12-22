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
name|_SYS_VDEV_IMPL_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_VDEV_IMPL_H
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
name|ashift
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
name|char
modifier|*
name|ve_data
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
struct|struct
name|vdev_queue
block|{
name|avl_tree_t
name|vq_deadline_tree
decl_stmt|;
name|avl_tree_t
name|vq_read_tree
decl_stmt|;
name|avl_tree_t
name|vq_write_tree
decl_stmt|;
name|avl_tree_t
name|vq_pending_tree
decl_stmt|;
name|kmutex_t
name|vq_lock
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
name|vdev_asize
decl_stmt|;
comment|/* allocatable device capacity	*/
name|uint64_t
name|vdev_ashift
decl_stmt|;
comment|/* block alignment shift	*/
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
name|space_map_t
name|vdev_dtl_map
decl_stmt|;
comment|/* dirty time log in-core state	*/
name|space_map_t
name|vdev_dtl_scrub
decl_stmt|;
comment|/* DTL for scrub repair writes	*/
name|vdev_stat_t
name|vdev_stat
decl_stmt|;
comment|/* virtual device statistics	*/
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
name|uint8_t
name|vdev_reopen_wanted
decl_stmt|;
comment|/* async reopen wanted?	*/
name|list_node_t
name|vdev_dirty_node
decl_stmt|;
comment|/* config dirty list		*/
name|uint64_t
name|vdev_deflate_ratio
decl_stmt|;
comment|/* deflation ratio (x512)	*/
comment|/* 	 * Leaf vdev state. 	 */
name|uint64_t
name|vdev_psize
decl_stmt|;
comment|/* physical device capacity	*/
name|space_map_obj_t
name|vdev_dtl
decl_stmt|;
comment|/* dirty time log on-disk state	*/
name|txg_node_t
name|vdev_dtl_node
decl_stmt|;
comment|/* per-txg dirty DTL linkage	*/
name|uint64_t
name|vdev_wholedisk
decl_stmt|;
comment|/* true if this is a whole disk */
name|uint64_t
name|vdev_offline
decl_stmt|;
comment|/* device taken offline?	*/
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
name|uint64_t
name|vdev_fault_arg
decl_stmt|;
comment|/* fault injection paramater	*/
name|int
name|vdev_fault_mask
decl_stmt|;
comment|/* zio types to fault		*/
name|uint8_t
name|vdev_fault_mode
decl_stmt|;
comment|/* fault injection mode	*/
name|uint8_t
name|vdev_cache_active
decl_stmt|;
comment|/* vdev_cache and vdev_queue	*/
name|uint8_t
name|vdev_tmpoffline
decl_stmt|;
comment|/* device taken offline temporarily? */
name|uint8_t
name|vdev_detached
decl_stmt|;
comment|/* device detached?		*/
name|uint64_t
name|vdev_isspare
decl_stmt|;
comment|/* was a hot spare */
name|vdev_queue_t
name|vdev_queue
decl_stmt|;
comment|/* I/O deadline schedule queue	*/
name|vdev_cache_t
name|vdev_cache
decl_stmt|;
comment|/* physical block cache		*/
name|uint64_t
name|vdev_not_present
decl_stmt|;
comment|/* not present during import	*/
name|hrtime_t
name|vdev_last_try
decl_stmt|;
comment|/* last reopen time		*/
name|boolean_t
name|vdev_nowritecache
decl_stmt|;
comment|/* true if flushwritecache failed */
comment|/* 	 * For DTrace to work in userland (libzpool) context, these fields must 	 * remain at the end of the structure.  DTrace will use the kernel's 	 * CTF definition for 'struct vdev', and since the size of a kmutex_t is 	 * larger in userland, the offsets for the rest fields would be 	 * incorrect. 	 */
name|kmutex_t
name|vdev_dtl_lock
decl_stmt|;
comment|/* vdev_dtl_{map,resilver}	*/
name|kmutex_t
name|vdev_stat_lock
decl_stmt|;
comment|/* vdev_stat			*/
block|}
struct|;
define|#
directive|define
name|VDEV_SKIP_SIZE
value|(8<< 10)
define|#
directive|define
name|VDEV_BOOT_HEADER_SIZE
value|(8<< 10)
define|#
directive|define
name|VDEV_PHYS_SIZE
value|(112<< 10)
define|#
directive|define
name|VDEV_UBERBLOCK_RING
value|(128<< 10)
define|#
directive|define
name|VDEV_UBERBLOCK_SHIFT
parameter_list|(
name|vd
parameter_list|)
define|\
value|MAX((vd)->vdev_top->vdev_ashift, UBERBLOCK_SHIFT)
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
comment|/* ZFS boot block */
define|#
directive|define
name|VDEV_BOOT_MAGIC
value|0x2f5b007b10cULL
define|#
directive|define
name|VDEV_BOOT_VERSION
value|1
comment|/* version number	*/
typedef|typedef
struct|struct
name|vdev_boot_header
block|{
name|uint64_t
name|vb_magic
decl_stmt|;
comment|/* VDEV_BOOT_MAGIC	*/
name|uint64_t
name|vb_version
decl_stmt|;
comment|/* VDEV_BOOT_VERSION	*/
name|uint64_t
name|vb_offset
decl_stmt|;
comment|/* start offset	(bytes) */
name|uint64_t
name|vb_size
decl_stmt|;
comment|/* size (bytes)		*/
name|char
name|vb_pad
index|[
name|VDEV_BOOT_HEADER_SIZE
operator|-
literal|4
operator|*
sizeof|sizeof
argument_list|(
name|uint64_t
argument_list|)
index|]
decl_stmt|;
block|}
name|vdev_boot_header_t
typedef|;
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
name|zio_block_tail_t
argument_list|)
index|]
decl_stmt|;
name|zio_block_tail_t
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
name|vl_pad
index|[
name|VDEV_SKIP_SIZE
index|]
decl_stmt|;
comment|/*   8K	*/
name|vdev_boot_header_t
name|vl_boot_header
decl_stmt|;
comment|/*   8K	*/
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
comment|/*  * Size and offset of embedded boot loader region on each label.  * The total size of the first two labels plus the boot area is 4MB.  */
define|#
directive|define
name|VDEV_BOOT_OFFSET
value|(2 * sizeof (vdev_label_t))
define|#
directive|define
name|VDEV_BOOT_SIZE
value|(7ULL<< 19)
comment|/* 3.5M	*/
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
comment|/*  * Allocate or free a vdev  */
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
name|vdev_load
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
specifier|extern
name|vdev_ops_t
name|vdev_file_ops
decl_stmt|;
endif|#
directive|endif
specifier|extern
name|vdev_ops_t
name|vdev_missing_ops
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
name|vdev_get_rsize
parameter_list|(
name|vdev_t
modifier|*
name|vd
parameter_list|)
function_decl|;
comment|/*  * zdb uses this tunable, so it must be declared here to make lint happy.  */
specifier|extern
name|int
name|zfs_vdev_cache_size
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
comment|/* _SYS_VDEV_IMPL_H */
end_comment

end_unit

