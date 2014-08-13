begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2005, 2010, Oracle and/or its affiliates. All rights reserved.  * Copyright (c) 2011 Pawel Jakub Dawidek<pawel@dawidek.net>.  * All rights reserved.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_FS_ZFS_VFSOPS_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_FS_ZFS_VFSOPS_H
end_define

begin_include
include|#
directive|include
file|<sys/list.h>
end_include

begin_include
include|#
directive|include
file|<sys/vfs.h>
end_include

begin_include
include|#
directive|include
file|<sys/zil.h>
end_include

begin_include
include|#
directive|include
file|<sys/sa.h>
end_include

begin_include
include|#
directive|include
file|<sys/rrwlock.h>
end_include

begin_include
include|#
directive|include
file|<sys/zfs_ioctl.h>
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
name|struct
name|zfsvfs
name|zfsvfs_t
typedef|;
struct_decl|struct
name|znode
struct_decl|;
struct|struct
name|zfsvfs
block|{
name|vfs_t
modifier|*
name|z_vfs
decl_stmt|;
comment|/* generic fs struct */
name|zfsvfs_t
modifier|*
name|z_parent
decl_stmt|;
comment|/* parent fs */
name|objset_t
modifier|*
name|z_os
decl_stmt|;
comment|/* objset reference */
name|uint64_t
name|z_root
decl_stmt|;
comment|/* id of root znode */
name|uint64_t
name|z_unlinkedobj
decl_stmt|;
comment|/* id of unlinked zapobj */
name|uint64_t
name|z_max_blksz
decl_stmt|;
comment|/* maximum block size for files */
name|uint64_t
name|z_fuid_obj
decl_stmt|;
comment|/* fuid table object number */
name|uint64_t
name|z_fuid_size
decl_stmt|;
comment|/* fuid table size */
name|avl_tree_t
name|z_fuid_idx
decl_stmt|;
comment|/* fuid tree keyed by index */
name|avl_tree_t
name|z_fuid_domain
decl_stmt|;
comment|/* fuid tree keyed by domain */
name|krwlock_t
name|z_fuid_lock
decl_stmt|;
comment|/* fuid lock */
name|boolean_t
name|z_fuid_loaded
decl_stmt|;
comment|/* fuid tables are loaded */
name|boolean_t
name|z_fuid_dirty
decl_stmt|;
comment|/* need to sync fuid table ? */
name|struct
name|zfs_fuid_info
modifier|*
name|z_fuid_replay
decl_stmt|;
comment|/* fuid info for replay */
name|zilog_t
modifier|*
name|z_log
decl_stmt|;
comment|/* intent log pointer */
name|uint_t
name|z_acl_mode
decl_stmt|;
comment|/* acl chmod/mode behavior */
name|uint_t
name|z_acl_inherit
decl_stmt|;
comment|/* acl inheritance behavior */
name|zfs_case_t
name|z_case
decl_stmt|;
comment|/* case-sense */
name|boolean_t
name|z_utf8
decl_stmt|;
comment|/* utf8-only */
name|int
name|z_norm
decl_stmt|;
comment|/* normalization flags */
name|boolean_t
name|z_atime
decl_stmt|;
comment|/* enable atimes mount option */
name|boolean_t
name|z_unmounted
decl_stmt|;
comment|/* unmounted */
name|rrmlock_t
name|z_teardown_lock
decl_stmt|;
name|krwlock_t
name|z_teardown_inactive_lock
decl_stmt|;
name|list_t
name|z_all_znodes
decl_stmt|;
comment|/* all vnodes in the fs */
name|kmutex_t
name|z_znodes_lock
decl_stmt|;
comment|/* lock for z_all_znodes */
name|vnode_t
modifier|*
name|z_ctldir
decl_stmt|;
comment|/* .zfs directory pointer */
name|boolean_t
name|z_show_ctldir
decl_stmt|;
comment|/* expose .zfs in the root dir */
name|boolean_t
name|z_issnap
decl_stmt|;
comment|/* true if this is a snapshot */
name|boolean_t
name|z_vscan
decl_stmt|;
comment|/* virus scan on/off */
name|boolean_t
name|z_use_fuids
decl_stmt|;
comment|/* version allows fuids */
name|boolean_t
name|z_replay
decl_stmt|;
comment|/* set during ZIL replay */
name|boolean_t
name|z_use_sa
decl_stmt|;
comment|/* version allow system attributes */
name|uint64_t
name|z_version
decl_stmt|;
comment|/* ZPL version */
name|uint64_t
name|z_shares_dir
decl_stmt|;
comment|/* hidden shares dir */
name|kmutex_t
name|z_lock
decl_stmt|;
name|uint64_t
name|z_userquota_obj
decl_stmt|;
name|uint64_t
name|z_groupquota_obj
decl_stmt|;
name|uint64_t
name|z_replay_eof
decl_stmt|;
comment|/* New end of file - replay only */
name|sa_attr_type_t
modifier|*
name|z_attr_table
decl_stmt|;
comment|/* SA attr mapping->id */
define|#
directive|define
name|ZFS_OBJ_MTX_SZ
value|64
name|kmutex_t
name|z_hold_mtx
index|[
name|ZFS_OBJ_MTX_SZ
index|]
decl_stmt|;
comment|/* znode hold locks */
block|}
struct|;
comment|/*  * Normal filesystems (those not under .zfs/snapshot) have a total  * file ID size limited to 12 bytes (including the length field) due to  * NFSv2 protocol's limitation of 32 bytes for a filehandle.  For historical  * reasons, this same limit is being imposed by the Solaris NFSv3 implementation  * (although the NFSv3 protocol actually permits a maximum of 64 bytes).  It  * is not possible to expand beyond 12 bytes without abandoning support  * of NFSv2.  *  * For normal filesystems, we partition up the available space as follows:  *	2 bytes		fid length (required)  *	6 bytes		object number (48 bits)  *	4 bytes		generation number (32 bits)  *  * We reserve only 48 bits for the object number, as this is the limit  * currently defined and imposed by the DMU.  */
typedef|typedef
struct|struct
name|zfid_short
block|{
name|uint16_t
name|zf_len
decl_stmt|;
name|uint8_t
name|zf_object
index|[
literal|6
index|]
decl_stmt|;
comment|/* obj[i] = obj>> (8 * i) */
name|uint8_t
name|zf_gen
index|[
literal|4
index|]
decl_stmt|;
comment|/* gen[i] = gen>> (8 * i) */
block|}
name|zfid_short_t
typedef|;
comment|/*  * Filesystems under .zfs/snapshot have a total file ID size of 22[*] bytes  * (including the length field).  This makes files under .zfs/snapshot  * accessible by NFSv3 and NFSv4, but not NFSv2.  *  * For files under .zfs/snapshot, we partition up the available space  * as follows:  *	2 bytes		fid length (required)  *	6 bytes		object number (48 bits)  *	4 bytes		generation number (32 bits)  *	6 bytes		objset id (48 bits)  *	4 bytes[**]	currently just zero (32 bits)  *  * We reserve only 48 bits for the object number and objset id, as these are  * the limits currently defined and imposed by the DMU.  *  * [*] 20 bytes on FreeBSD to fit into the size of struct fid.  * [**] 2 bytes on FreeBSD for the above reason.  */
typedef|typedef
struct|struct
name|zfid_long
block|{
name|zfid_short_t
name|z_fid
decl_stmt|;
name|uint8_t
name|zf_setid
index|[
literal|6
index|]
decl_stmt|;
comment|/* obj[i] = obj>> (8 * i) */
name|uint8_t
name|zf_setgen
index|[
literal|2
index|]
decl_stmt|;
comment|/* gen[i] = gen>> (8 * i) */
block|}
name|zfid_long_t
typedef|;
define|#
directive|define
name|SHORT_FID_LEN
value|(sizeof (zfid_short_t) - sizeof (uint16_t))
define|#
directive|define
name|LONG_FID_LEN
value|(sizeof (zfid_long_t) - sizeof (uint16_t))
specifier|extern
name|uint_t
name|zfs_fsyncer_key
decl_stmt|;
specifier|extern
name|int
name|zfs_super_owner
decl_stmt|;
specifier|extern
name|int
name|zfs_suspend_fs
parameter_list|(
name|zfsvfs_t
modifier|*
name|zfsvfs
parameter_list|)
function_decl|;
specifier|extern
name|int
name|zfs_resume_fs
parameter_list|(
name|zfsvfs_t
modifier|*
name|zfsvfs
parameter_list|,
specifier|const
name|char
modifier|*
name|osname
parameter_list|)
function_decl|;
specifier|extern
name|int
name|zfs_userspace_one
parameter_list|(
name|zfsvfs_t
modifier|*
name|zfsvfs
parameter_list|,
name|zfs_userquota_prop_t
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|domain
parameter_list|,
name|uint64_t
name|rid
parameter_list|,
name|uint64_t
modifier|*
name|valuep
parameter_list|)
function_decl|;
specifier|extern
name|int
name|zfs_userspace_many
parameter_list|(
name|zfsvfs_t
modifier|*
name|zfsvfs
parameter_list|,
name|zfs_userquota_prop_t
name|type
parameter_list|,
name|uint64_t
modifier|*
name|cookiep
parameter_list|,
name|void
modifier|*
name|vbuf
parameter_list|,
name|uint64_t
modifier|*
name|bufsizep
parameter_list|)
function_decl|;
specifier|extern
name|int
name|zfs_set_userquota
parameter_list|(
name|zfsvfs_t
modifier|*
name|zfsvfs
parameter_list|,
name|zfs_userquota_prop_t
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|domain
parameter_list|,
name|uint64_t
name|rid
parameter_list|,
name|uint64_t
name|quota
parameter_list|)
function_decl|;
specifier|extern
name|boolean_t
name|zfs_owner_overquota
parameter_list|(
name|zfsvfs_t
modifier|*
name|zfsvfs
parameter_list|,
name|struct
name|znode
modifier|*
parameter_list|,
name|boolean_t
name|isgroup
parameter_list|)
function_decl|;
specifier|extern
name|boolean_t
name|zfs_fuid_overquota
parameter_list|(
name|zfsvfs_t
modifier|*
name|zfsvfs
parameter_list|,
name|boolean_t
name|isgroup
parameter_list|,
name|uint64_t
name|fuid
parameter_list|)
function_decl|;
specifier|extern
name|int
name|zfs_set_version
parameter_list|(
name|zfsvfs_t
modifier|*
name|zfsvfs
parameter_list|,
name|uint64_t
name|newvers
parameter_list|)
function_decl|;
specifier|extern
name|int
name|zfsvfs_create
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|zfsvfs_t
modifier|*
modifier|*
name|zfvp
parameter_list|)
function_decl|;
specifier|extern
name|void
name|zfsvfs_free
parameter_list|(
name|zfsvfs_t
modifier|*
name|zfsvfs
parameter_list|)
function_decl|;
specifier|extern
name|int
name|zfs_check_global_label
parameter_list|(
specifier|const
name|char
modifier|*
name|dsname
parameter_list|,
specifier|const
name|char
modifier|*
name|hexsl
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|_KERNEL
specifier|extern
name|void
name|zfsvfs_update_fromname
parameter_list|(
specifier|const
name|char
modifier|*
name|oldname
parameter_list|,
specifier|const
name|char
modifier|*
name|newname
parameter_list|)
function_decl|;
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
comment|/* _SYS_FS_ZFS_VFSOPS_H */
end_comment

end_unit

