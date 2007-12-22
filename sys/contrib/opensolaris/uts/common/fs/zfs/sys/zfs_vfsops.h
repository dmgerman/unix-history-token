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
name|_SYS_FS_ZFS_VFSOPS_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_FS_ZFS_VFSOPS_H
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
name|z_assign
decl_stmt|;
comment|/* TXG_NOWAIT or set by zil_replay() */
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
name|boolean_t
name|z_atime
decl_stmt|;
comment|/* enable atimes mount option */
name|boolean_t
name|z_unmounted1
decl_stmt|;
comment|/* unmounted phase 1 */
name|boolean_t
name|z_unmounted2
decl_stmt|;
comment|/* unmounted phase 2 */
name|uint32_t
name|z_op_cnt
decl_stmt|;
comment|/* vnode/vfs operations ref count */
name|krwlock_t
name|z_um_lock
decl_stmt|;
comment|/* rw lock for umount phase 2 */
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
comment|/*  * The total file ID size is limited to 12 bytes (including the length  * field) in the NFSv2 protocol.  For historical reasons, this same limit  * is currently being imposed by the Solaris NFSv3 implementation...  * although the protocol actually permits a maximum of 64 bytes.  It will  * not be possible to expand beyond 12 bytes without abandoning support  * of NFSv2 and making some changes to the Solaris NFSv3 implementation.  *  * For the time being, we will partition up the available space as follows:  *	2 bytes		fid length (required)  *	6 bytes		object number (48 bits)  *	4 bytes		generation number (32 bits)  * We reserve only 48 bits for the object number, as this is the limit  * currently defined and imposed by the DMU.  */
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

