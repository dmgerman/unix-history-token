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
name|_SYS_FS_ZFS_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_FS_ZFS_H
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioccom.h>
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
comment|/*  * Types and constants shared between userland and the kernel.  */
comment|/*  * Each dataset can be one of the following types.  These constants can be  * combined into masks that can be passed to various functions.  */
typedef|typedef
enum|enum
block|{
name|ZFS_TYPE_FILESYSTEM
init|=
literal|0x1
block|,
name|ZFS_TYPE_SNAPSHOT
init|=
literal|0x2
block|,
name|ZFS_TYPE_VOLUME
init|=
literal|0x4
block|,
name|ZFS_TYPE_POOL
init|=
literal|0x8
block|}
name|zfs_type_t
typedef|;
define|#
directive|define
name|ZFS_TYPE_ANY
define|\
value|(ZFS_TYPE_FILESYSTEM | ZFS_TYPE_VOLUME | ZFS_TYPE_SNAPSHOT)
comment|/*  * Properties are identified by these constants and must be added to the  * end of this list to ensure that external conumsers are not affected  * by the change. The property list also determines how 'zfs get' will  * display them.  If you make any changes to this list, be sure to update  * the property table in usr/src/common/zfs/zfs_prop.c.  */
typedef|typedef
enum|enum
block|{
name|ZFS_PROP_CONT
init|=
operator|-
literal|2
block|,
name|ZFS_PROP_INVAL
init|=
operator|-
literal|1
block|,
name|ZFS_PROP_TYPE
block|,
name|ZFS_PROP_CREATION
block|,
name|ZFS_PROP_USED
block|,
name|ZFS_PROP_AVAILABLE
block|,
name|ZFS_PROP_REFERENCED
block|,
name|ZFS_PROP_COMPRESSRATIO
block|,
name|ZFS_PROP_MOUNTED
block|,
name|ZFS_PROP_ORIGIN
block|,
name|ZFS_PROP_QUOTA
block|,
name|ZFS_PROP_RESERVATION
block|,
name|ZFS_PROP_VOLSIZE
block|,
name|ZFS_PROP_VOLBLOCKSIZE
block|,
name|ZFS_PROP_RECORDSIZE
block|,
name|ZFS_PROP_MOUNTPOINT
block|,
name|ZFS_PROP_SHARENFS
block|,
name|ZFS_PROP_CHECKSUM
block|,
name|ZFS_PROP_COMPRESSION
block|,
name|ZFS_PROP_ATIME
block|,
name|ZFS_PROP_DEVICES
block|,
name|ZFS_PROP_EXEC
block|,
name|ZFS_PROP_SETUID
block|,
name|ZFS_PROP_READONLY
block|,
name|ZFS_PROP_ZONED
block|,
name|ZFS_PROP_SNAPDIR
block|,
name|ZFS_PROP_ACLMODE
block|,
name|ZFS_PROP_ACLINHERIT
block|,
name|ZFS_PROP_CREATETXG
block|,
comment|/* not exposed to the user */
name|ZFS_PROP_NAME
block|,
comment|/* not exposed to the user */
name|ZFS_PROP_CANMOUNT
block|,
name|ZFS_PROP_SHAREISCSI
block|,
name|ZFS_PROP_ISCSIOPTIONS
block|,
comment|/* not exposed to the user */
name|ZFS_PROP_XATTR
block|,
name|ZFS_PROP_NUMCLONES
block|,
comment|/* not exposed to the user */
name|ZFS_PROP_COPIES
block|,
name|ZFS_PROP_BOOTFS
block|}
name|zfs_prop_t
typedef|;
typedef|typedef
name|zfs_prop_t
name|zpool_prop_t
typedef|;
define|#
directive|define
name|ZFS_PROP_VALUE
value|"value"
define|#
directive|define
name|ZFS_PROP_SOURCE
value|"source"
typedef|typedef
enum|enum
block|{
name|ZFS_SRC_NONE
init|=
literal|0x1
block|,
name|ZFS_SRC_DEFAULT
init|=
literal|0x2
block|,
name|ZFS_SRC_TEMPORARY
init|=
literal|0x4
block|,
name|ZFS_SRC_LOCAL
init|=
literal|0x8
block|,
name|ZFS_SRC_INHERITED
init|=
literal|0x10
block|}
name|zfs_source_t
typedef|;
define|#
directive|define
name|ZFS_SRC_ALL
value|0x1f
comment|/*  * The following functions are shared between libzfs and the kernel.  */
name|zfs_prop_t
name|zfs_name_to_prop
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
name|zpool_prop_t
name|zpool_name_to_prop
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
name|boolean_t
name|zfs_prop_user
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
name|int
name|zfs_prop_readonly
parameter_list|(
name|zfs_prop_t
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|zfs_prop_default_string
parameter_list|(
name|zfs_prop_t
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|zfs_prop_to_name
parameter_list|(
name|zfs_prop_t
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|zpool_prop_to_name
parameter_list|(
name|zfs_prop_t
parameter_list|)
function_decl|;
name|uint64_t
name|zfs_prop_default_numeric
parameter_list|(
name|zfs_prop_t
parameter_list|)
function_decl|;
name|int
name|zfs_prop_inheritable
parameter_list|(
name|zfs_prop_t
parameter_list|)
function_decl|;
name|int
name|zfs_prop_string_to_index
parameter_list|(
name|zfs_prop_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|)
function_decl|;
name|int
name|zfs_prop_index_to_string
parameter_list|(
name|zfs_prop_t
parameter_list|,
name|uint64_t
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
comment|/*  * Property Iterator  */
typedef|typedef
name|zfs_prop_t
function_decl|(
modifier|*
name|zfs_prop_f
function_decl|)
parameter_list|(
name|zfs_prop_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
typedef|typedef
name|zfs_prop_f
name|zpool_prop_f
typedef|;
specifier|extern
name|zfs_prop_t
name|zfs_prop_iter
parameter_list|(
name|zfs_prop_f
parameter_list|,
name|void
modifier|*
parameter_list|,
name|boolean_t
parameter_list|)
function_decl|;
specifier|extern
name|zpool_prop_t
name|zpool_prop_iter
parameter_list|(
name|zpool_prop_f
parameter_list|,
name|void
modifier|*
parameter_list|,
name|boolean_t
parameter_list|)
function_decl|;
comment|/*  * On-disk version number.  */
define|#
directive|define
name|ZFS_VERSION_1
value|1ULL
define|#
directive|define
name|ZFS_VERSION_2
value|2ULL
define|#
directive|define
name|ZFS_VERSION_3
value|3ULL
define|#
directive|define
name|ZFS_VERSION_4
value|4ULL
define|#
directive|define
name|ZFS_VERSION_5
value|5ULL
define|#
directive|define
name|ZFS_VERSION_6
value|6ULL
comment|/*  * When bumping up ZFS_VERSION, make sure GRUB ZFS understand the on-disk  * format change. Go to usr/src/grub/grub-0.95/stage2/{zfs-include/, fsys_zfs*},  * and do the appropriate changes.  */
define|#
directive|define
name|ZFS_VERSION
value|ZFS_VERSION_6
define|#
directive|define
name|ZFS_VERSION_STRING
value|"6"
comment|/*  * Symbolic names for the changes that caused a ZFS_VERSION switch.  * Used in the code when checking for presence or absence of a feature.  * Feel free to define multiple symbolic names for each version if there  * were multiple changes to on-disk structures during that version.  *  * NOTE: When checking the current ZFS_VERSION in your code, be sure  *       to use spa_version() since it reports the version of the  *       last synced uberblock.  Checking the in-flight version can  *       be dangerous in some cases.  */
define|#
directive|define
name|ZFS_VERSION_INITIAL
value|ZFS_VERSION_1
define|#
directive|define
name|ZFS_VERSION_DITTO_BLOCKS
value|ZFS_VERSION_2
define|#
directive|define
name|ZFS_VERSION_SPARES
value|ZFS_VERSION_3
define|#
directive|define
name|ZFS_VERSION_RAID6
value|ZFS_VERSION_3
define|#
directive|define
name|ZFS_VERSION_BPLIST_ACCOUNT
value|ZFS_VERSION_3
define|#
directive|define
name|ZFS_VERSION_RAIDZ_DEFLATE
value|ZFS_VERSION_3
define|#
directive|define
name|ZFS_VERSION_DNODE_BYTES
value|ZFS_VERSION_3
define|#
directive|define
name|ZFS_VERSION_ZPOOL_HISTORY
value|ZFS_VERSION_4
define|#
directive|define
name|ZFS_VERSION_GZIP_COMPRESSION
value|ZFS_VERSION_5
define|#
directive|define
name|ZFS_VERSION_BOOTFS
value|ZFS_VERSION_6
comment|/*  * The following are configuration names used in the nvlist describing a pool's  * configuration.  */
define|#
directive|define
name|ZPOOL_CONFIG_VERSION
value|"version"
define|#
directive|define
name|ZPOOL_CONFIG_POOL_NAME
value|"name"
define|#
directive|define
name|ZPOOL_CONFIG_POOL_STATE
value|"state"
define|#
directive|define
name|ZPOOL_CONFIG_POOL_TXG
value|"txg"
define|#
directive|define
name|ZPOOL_CONFIG_POOL_GUID
value|"pool_guid"
define|#
directive|define
name|ZPOOL_CONFIG_CREATE_TXG
value|"create_txg"
define|#
directive|define
name|ZPOOL_CONFIG_TOP_GUID
value|"top_guid"
define|#
directive|define
name|ZPOOL_CONFIG_VDEV_TREE
value|"vdev_tree"
define|#
directive|define
name|ZPOOL_CONFIG_TYPE
value|"type"
define|#
directive|define
name|ZPOOL_CONFIG_CHILDREN
value|"children"
define|#
directive|define
name|ZPOOL_CONFIG_ID
value|"id"
define|#
directive|define
name|ZPOOL_CONFIG_GUID
value|"guid"
define|#
directive|define
name|ZPOOL_CONFIG_PATH
value|"path"
define|#
directive|define
name|ZPOOL_CONFIG_DEVID
value|"devid"
define|#
directive|define
name|ZPOOL_CONFIG_METASLAB_ARRAY
value|"metaslab_array"
define|#
directive|define
name|ZPOOL_CONFIG_METASLAB_SHIFT
value|"metaslab_shift"
define|#
directive|define
name|ZPOOL_CONFIG_ASHIFT
value|"ashift"
define|#
directive|define
name|ZPOOL_CONFIG_ASIZE
value|"asize"
define|#
directive|define
name|ZPOOL_CONFIG_DTL
value|"DTL"
define|#
directive|define
name|ZPOOL_CONFIG_STATS
value|"stats"
define|#
directive|define
name|ZPOOL_CONFIG_WHOLE_DISK
value|"whole_disk"
define|#
directive|define
name|ZPOOL_CONFIG_OFFLINE
value|"offline"
define|#
directive|define
name|ZPOOL_CONFIG_ERRCOUNT
value|"error_count"
define|#
directive|define
name|ZPOOL_CONFIG_NOT_PRESENT
value|"not_present"
define|#
directive|define
name|ZPOOL_CONFIG_SPARES
value|"spares"
define|#
directive|define
name|ZPOOL_CONFIG_IS_SPARE
value|"is_spare"
define|#
directive|define
name|ZPOOL_CONFIG_NPARITY
value|"nparity"
define|#
directive|define
name|ZPOOL_CONFIG_HOSTID
value|"hostid"
define|#
directive|define
name|ZPOOL_CONFIG_HOSTNAME
value|"hostname"
define|#
directive|define
name|ZPOOL_CONFIG_TIMESTAMP
value|"timestamp"
comment|/* not stored on disk */
define|#
directive|define
name|VDEV_TYPE_ROOT
value|"root"
define|#
directive|define
name|VDEV_TYPE_MIRROR
value|"mirror"
define|#
directive|define
name|VDEV_TYPE_REPLACING
value|"replacing"
define|#
directive|define
name|VDEV_TYPE_RAIDZ
value|"raidz"
define|#
directive|define
name|VDEV_TYPE_DISK
value|"disk"
define|#
directive|define
name|VDEV_TYPE_FILE
value|"file"
define|#
directive|define
name|VDEV_TYPE_MISSING
value|"missing"
define|#
directive|define
name|VDEV_TYPE_SPARE
value|"spare"
comment|/*  * This is needed in userland to report the minimum necessary device size.  */
define|#
directive|define
name|SPA_MINDEVSIZE
value|(64ULL<< 20)
comment|/*  * The location of the pool configuration repository, shared between kernel and  * userland.  */
define|#
directive|define
name|ZPOOL_CACHE_DIR
value|"/etc/zfs"
define|#
directive|define
name|ZPOOL_CACHE_FILE
value|"zpool.cache"
define|#
directive|define
name|ZPOOL_CACHE_TMP
value|".zpool.cache"
define|#
directive|define
name|ZPOOL_CACHE
value|ZPOOL_CACHE_DIR "/" ZPOOL_CACHE_FILE
comment|/*  * vdev states are ordered from least to most healthy.  * A vdev that's CANT_OPEN or below is considered unusable.  */
typedef|typedef
enum|enum
name|vdev_state
block|{
name|VDEV_STATE_UNKNOWN
init|=
literal|0
block|,
comment|/* Uninitialized vdev			*/
name|VDEV_STATE_CLOSED
block|,
comment|/* Not currently open			*/
name|VDEV_STATE_OFFLINE
block|,
comment|/* Not allowed to open			*/
name|VDEV_STATE_CANT_OPEN
block|,
comment|/* Tried to open, but failed		*/
name|VDEV_STATE_DEGRADED
block|,
comment|/* Replicated vdev with unhealthy kids	*/
name|VDEV_STATE_HEALTHY
comment|/* Presumed good			*/
block|}
name|vdev_state_t
typedef|;
comment|/*  * vdev aux states.  When a vdev is in the CANT_OPEN state, the aux field  * of the vdev stats structure uses these constants to distinguish why.  */
typedef|typedef
enum|enum
name|vdev_aux
block|{
name|VDEV_AUX_NONE
block|,
comment|/* no error				*/
name|VDEV_AUX_OPEN_FAILED
block|,
comment|/* ldi_open_*() or vn_open() failed	*/
name|VDEV_AUX_CORRUPT_DATA
block|,
comment|/* bad label or disk contents		*/
name|VDEV_AUX_NO_REPLICAS
block|,
comment|/* insufficient number of replicas	*/
name|VDEV_AUX_BAD_GUID_SUM
block|,
comment|/* vdev guid sum doesn't match		*/
name|VDEV_AUX_TOO_SMALL
block|,
comment|/* vdev size is too small		*/
name|VDEV_AUX_BAD_LABEL
block|,
comment|/* the label is OK but invalid		*/
name|VDEV_AUX_VERSION_NEWER
block|,
comment|/* on-disk version is too new		*/
name|VDEV_AUX_VERSION_OLDER
block|,
comment|/* on-disk version is too old		*/
name|VDEV_AUX_SPARED
comment|/* hot spare used in another pool	*/
block|}
name|vdev_aux_t
typedef|;
comment|/*  * pool state.  The following states are written to disk as part of the normal  * SPA lifecycle: ACTIVE, EXPORTED, DESTROYED, SPARE.  The remaining states are  * software abstractions used at various levels to communicate pool state.  */
typedef|typedef
enum|enum
name|pool_state
block|{
name|POOL_STATE_ACTIVE
init|=
literal|0
block|,
comment|/* In active use		*/
name|POOL_STATE_EXPORTED
block|,
comment|/* Explicitly exported		*/
name|POOL_STATE_DESTROYED
block|,
comment|/* Explicitly destroyed		*/
name|POOL_STATE_SPARE
block|,
comment|/* Reserved for hot spare use	*/
name|POOL_STATE_UNINITIALIZED
block|,
comment|/* Internal spa_t state		*/
name|POOL_STATE_UNAVAIL
block|,
comment|/* Internal libzfs state	*/
name|POOL_STATE_POTENTIALLY_ACTIVE
comment|/* Internal libzfs state	*/
block|}
name|pool_state_t
typedef|;
comment|/*  * Scrub types.  */
typedef|typedef
enum|enum
name|pool_scrub_type
block|{
name|POOL_SCRUB_NONE
block|,
name|POOL_SCRUB_RESILVER
block|,
name|POOL_SCRUB_EVERYTHING
block|,
name|POOL_SCRUB_TYPES
block|}
name|pool_scrub_type_t
typedef|;
comment|/*  * ZIO types.  Needed to interpret vdev statistics below.  */
typedef|typedef
enum|enum
name|zio_type
block|{
name|ZIO_TYPE_NULL
init|=
literal|0
block|,
name|ZIO_TYPE_READ
block|,
name|ZIO_TYPE_WRITE
block|,
name|ZIO_TYPE_FREE
block|,
name|ZIO_TYPE_CLAIM
block|,
name|ZIO_TYPE_IOCTL
block|,
name|ZIO_TYPES
block|}
name|zio_type_t
typedef|;
comment|/*  * Vdev statistics.  Note: all fields should be 64-bit because this  * is passed between kernel and userland as an nvlist uint64 array.  */
typedef|typedef
struct|struct
name|vdev_stat
block|{
name|hrtime_t
name|vs_timestamp
decl_stmt|;
comment|/* time since vdev load	*/
name|uint64_t
name|vs_state
decl_stmt|;
comment|/* vdev state		*/
name|uint64_t
name|vs_aux
decl_stmt|;
comment|/* see vdev_aux_t	*/
name|uint64_t
name|vs_alloc
decl_stmt|;
comment|/* space allocated	*/
name|uint64_t
name|vs_space
decl_stmt|;
comment|/* total capacity	*/
name|uint64_t
name|vs_dspace
decl_stmt|;
comment|/* deflated capacity	*/
name|uint64_t
name|vs_rsize
decl_stmt|;
comment|/* replaceable dev size */
name|uint64_t
name|vs_ops
index|[
name|ZIO_TYPES
index|]
decl_stmt|;
comment|/* operation count	*/
name|uint64_t
name|vs_bytes
index|[
name|ZIO_TYPES
index|]
decl_stmt|;
comment|/* bytes read/written	*/
name|uint64_t
name|vs_read_errors
decl_stmt|;
comment|/* read errors		*/
name|uint64_t
name|vs_write_errors
decl_stmt|;
comment|/* write errors		*/
name|uint64_t
name|vs_checksum_errors
decl_stmt|;
comment|/* checksum errors	*/
name|uint64_t
name|vs_self_healed
decl_stmt|;
comment|/* self-healed bytes	*/
name|uint64_t
name|vs_scrub_type
decl_stmt|;
comment|/* pool_scrub_type_t	*/
name|uint64_t
name|vs_scrub_complete
decl_stmt|;
comment|/* completed?		*/
name|uint64_t
name|vs_scrub_examined
decl_stmt|;
comment|/* bytes examined; top	*/
name|uint64_t
name|vs_scrub_repaired
decl_stmt|;
comment|/* bytes repaired; leaf	*/
name|uint64_t
name|vs_scrub_errors
decl_stmt|;
comment|/* errors during scrub	*/
name|uint64_t
name|vs_scrub_start
decl_stmt|;
comment|/* UTC scrub start time	*/
name|uint64_t
name|vs_scrub_end
decl_stmt|;
comment|/* UTC scrub end time	*/
block|}
name|vdev_stat_t
typedef|;
define|#
directive|define
name|ZFS_DRIVER
value|"zfs"
define|#
directive|define
name|ZFS_DEV_NAME
value|"zfs"
define|#
directive|define
name|ZFS_DEV
value|"/dev/" ZFS_DEV_NAME
comment|/*  * zvol paths.  Irritatingly, the devfsadm interfaces want all these  * paths without the /dev prefix, but for some things, we want the  * /dev prefix.  Below are the names without /dev.  */
define|#
directive|define
name|ZVOL_DEV_DIR
value|"zvol"
comment|/*  * And here are the things we need with /dev, etc. in front of them.  */
define|#
directive|define
name|ZVOL_PSEUDO_DEV
value|"/devices/pseudo/zvol@0:"
define|#
directive|define
name|ZVOL_FULL_DEV_DIR
value|"/dev/" ZVOL_DEV_DIR
define|#
directive|define
name|ZVOL_PROP_NAME
value|"name"
comment|/*  * /dev/zfs ioctl numbers.  */
typedef|typedef
name|unsigned
name|long
name|zfs_ioc_t
typedef|;
define|#
directive|define
name|ZFS_IOC
parameter_list|(
name|ioreq
parameter_list|)
value|((ioreq)& 0xff)
define|#
directive|define
name|ZFS_IOC_POOL_CREATE
value|_IOWR('Z', 0, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_POOL_DESTROY
value|_IOWR('Z', 1, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_POOL_IMPORT
value|_IOWR('Z', 2, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_POOL_EXPORT
value|_IOWR('Z', 3, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_POOL_CONFIGS
value|_IOWR('Z', 4, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_POOL_STATS
value|_IOWR('Z', 5, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_POOL_TRYIMPORT
value|_IOWR('Z', 6, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_POOL_SCRUB
value|_IOWR('Z', 7, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_POOL_FREEZE
value|_IOWR('Z', 8, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_POOL_UPGRADE
value|_IOWR('Z', 9, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_POOL_GET_HISTORY
value|_IOWR('Z', 10, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_POOL_LOG_HISTORY
value|_IOWR('Z', 11, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_VDEV_ADD
value|_IOWR('Z', 12, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_VDEV_REMOVE
value|_IOWR('Z', 13, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_VDEV_ONLINE
value|_IOWR('Z', 14, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_VDEV_OFFLINE
value|_IOWR('Z', 15, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_VDEV_ATTACH
value|_IOWR('Z', 16, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_VDEV_DETACH
value|_IOWR('Z', 17, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_VDEV_SETPATH
value|_IOWR('Z', 18, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_OBJSET_STATS
value|_IOWR('Z', 19, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_DATASET_LIST_NEXT
value|_IOWR('Z', 20, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_SNAPSHOT_LIST_NEXT
value|_IOWR('Z', 21, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_SET_PROP
value|_IOWR('Z', 22, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_CREATE_MINOR
value|_IOWR('Z', 23, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_REMOVE_MINOR
value|_IOWR('Z', 24, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_CREATE
value|_IOWR('Z', 25, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_DESTROY
value|_IOWR('Z', 26, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_ROLLBACK
value|_IOWR('Z', 27, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_RENAME
value|_IOWR('Z', 28, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_RECVBACKUP
value|_IOWR('Z', 29, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_SENDBACKUP
value|_IOWR('Z', 30, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_INJECT_FAULT
value|_IOWR('Z', 31, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_CLEAR_FAULT
value|_IOWR('Z', 32, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_INJECT_LIST_NEXT
value|_IOWR('Z', 33, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_ERROR_LOG
value|_IOWR('Z', 34, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_CLEAR
value|_IOWR('Z', 35, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_PROMOTE
value|_IOWR('Z', 36, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_DESTROY_SNAPS
value|_IOWR('Z', 37, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_SNAPSHOT
value|_IOWR('Z', 38, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_DSOBJ_TO_DSNAME
value|_IOWR('Z', 39, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_OBJ_TO_PATH
value|_IOWR('Z', 40, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_POOL_SET_PROPS
value|_IOWR('Z', 41, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_POOL_GET_PROPS
value|_IOWR('Z', 42, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_JAIL
value|_IOWR('Z', 43, struct zfs_cmd)
define|#
directive|define
name|ZFS_IOC_UNJAIL
value|_IOWR('Z', 44, struct zfs_cmd)
comment|/*  * Internal SPA load state.  Used by FMA diagnosis engine.  */
typedef|typedef
enum|enum
block|{
name|SPA_LOAD_NONE
block|,
comment|/* no load in progress */
name|SPA_LOAD_OPEN
block|,
comment|/* normal open */
name|SPA_LOAD_IMPORT
block|,
comment|/* import in progress */
name|SPA_LOAD_TRYIMPORT
comment|/* tryimport in progress */
block|}
name|spa_load_state_t
typedef|;
comment|/*  * Bookmark name values.  */
define|#
directive|define
name|ZPOOL_ERR_LIST
value|"error list"
define|#
directive|define
name|ZPOOL_ERR_DATASET
value|"dataset"
define|#
directive|define
name|ZPOOL_ERR_OBJECT
value|"object"
define|#
directive|define
name|HIS_MAX_RECORD_LEN
value|(MAXPATHLEN + MAXPATHLEN + 1)
comment|/*  * The following are names used in the nvlist describing  * the pool's history log.  */
define|#
directive|define
name|ZPOOL_HIST_RECORD
value|"history record"
define|#
directive|define
name|ZPOOL_HIST_TIME
value|"history time"
define|#
directive|define
name|ZPOOL_HIST_CMD
value|"history command"
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
comment|/* _SYS_FS_ZFS_H */
end_comment

end_unit

