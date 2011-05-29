begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2010 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_ZFS_SA_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_ZFS_SA_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/list.h>
end_include

begin_include
include|#
directive|include
file|<sys/dmu.h>
end_include

begin_include
include|#
directive|include
file|<sys/zfs_acl.h>
end_include

begin_include
include|#
directive|include
file|<sys/zfs_znode.h>
end_include

begin_include
include|#
directive|include
file|<sys/sa.h>
end_include

begin_include
include|#
directive|include
file|<sys/zil.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
comment|/*  * This is the list of known attributes  * to the ZPL.  The values of the actual  * attributes are not defined by the order  * the enums.  It is controlled by the attribute  * registration mechanism.  Two different file system  * could have different numeric values for the same  * attributes.  this list is only used for dereferencing  * into the table that will hold the actual numeric value.  */
typedef|typedef
enum|enum
name|zpl_attr
block|{
name|ZPL_ATIME
block|,
name|ZPL_MTIME
block|,
name|ZPL_CTIME
block|,
name|ZPL_CRTIME
block|,
name|ZPL_GEN
block|,
name|ZPL_MODE
block|,
name|ZPL_SIZE
block|,
name|ZPL_PARENT
block|,
name|ZPL_LINKS
block|,
name|ZPL_XATTR
block|,
name|ZPL_RDEV
block|,
name|ZPL_FLAGS
block|,
name|ZPL_UID
block|,
name|ZPL_GID
block|,
name|ZPL_PAD
block|,
name|ZPL_ZNODE_ACL
block|,
name|ZPL_DACL_COUNT
block|,
name|ZPL_SYMLINK
block|,
name|ZPL_SCANSTAMP
block|,
name|ZPL_DACL_ACES
block|,
name|ZPL_END
block|}
name|zpl_attr_t
typedef|;
define|#
directive|define
name|ZFS_OLD_ZNODE_PHYS_SIZE
value|0x108
define|#
directive|define
name|ZFS_SA_BASE_ATTR_SIZE
value|(ZFS_OLD_ZNODE_PHYS_SIZE - \     sizeof (zfs_acl_phys_t))
define|#
directive|define
name|SA_MODE_OFFSET
value|0
define|#
directive|define
name|SA_SIZE_OFFSET
value|8
define|#
directive|define
name|SA_GEN_OFFSET
value|16
define|#
directive|define
name|SA_UID_OFFSET
value|24
define|#
directive|define
name|SA_GID_OFFSET
value|32
define|#
directive|define
name|SA_PARENT_OFFSET
value|40
specifier|extern
name|sa_attr_reg_t
name|zfs_attr_table
index|[
name|ZPL_END
operator|+
literal|1
index|]
decl_stmt|;
specifier|extern
name|sa_attr_reg_t
name|zfs_legacy_attr_table
index|[
name|ZPL_END
operator|+
literal|1
index|]
decl_stmt|;
comment|/*  * This is a deprecated data structure that only exists for  * dealing with file systems create prior to ZPL version 5.  */
typedef|typedef
struct|struct
name|znode_phys
block|{
name|uint64_t
name|zp_atime
index|[
literal|2
index|]
decl_stmt|;
comment|/*  0 - last file access time */
name|uint64_t
name|zp_mtime
index|[
literal|2
index|]
decl_stmt|;
comment|/* 16 - last file modification time */
name|uint64_t
name|zp_ctime
index|[
literal|2
index|]
decl_stmt|;
comment|/* 32 - last file change time */
name|uint64_t
name|zp_crtime
index|[
literal|2
index|]
decl_stmt|;
comment|/* 48 - creation time */
name|uint64_t
name|zp_gen
decl_stmt|;
comment|/* 64 - generation (txg of creation) */
name|uint64_t
name|zp_mode
decl_stmt|;
comment|/* 72 - file mode bits */
name|uint64_t
name|zp_size
decl_stmt|;
comment|/* 80 - size of file */
name|uint64_t
name|zp_parent
decl_stmt|;
comment|/* 88 - directory parent (`..') */
name|uint64_t
name|zp_links
decl_stmt|;
comment|/* 96 - number of links to file */
name|uint64_t
name|zp_xattr
decl_stmt|;
comment|/* 104 - DMU object for xattrs */
name|uint64_t
name|zp_rdev
decl_stmt|;
comment|/* 112 - dev_t for VBLK& VCHR files */
name|uint64_t
name|zp_flags
decl_stmt|;
comment|/* 120 - persistent flags */
name|uint64_t
name|zp_uid
decl_stmt|;
comment|/* 128 - file owner */
name|uint64_t
name|zp_gid
decl_stmt|;
comment|/* 136 - owning group */
name|uint64_t
name|zp_zap
decl_stmt|;
comment|/* 144 - extra attributes */
name|uint64_t
name|zp_pad
index|[
literal|3
index|]
decl_stmt|;
comment|/* 152 - future */
name|zfs_acl_phys_t
name|zp_acl
decl_stmt|;
comment|/* 176 - 263 ACL */
comment|/* 	 * Data may pad out any remaining bytes in the znode buffer, eg: 	 * 	 * |<---------------------- dnode_phys (512) ------------------------>| 	 * |<-- dnode (192) --->|<----------- "bonus" buffer (320) ---------->| 	 *			|<---- znode (264) ---->|<---- data (56) ---->| 	 * 	 * At present, we use this space for the following: 	 *  - symbolic links 	 *  - 32-byte anti-virus scanstamp (regular files only) 	 */
block|}
name|znode_phys_t
typedef|;
ifdef|#
directive|ifdef
name|_KERNEL
name|int
name|zfs_sa_readlink
parameter_list|(
name|struct
name|znode
modifier|*
parameter_list|,
name|uio_t
modifier|*
parameter_list|)
function_decl|;
name|void
name|zfs_sa_symlink
parameter_list|(
name|struct
name|znode
modifier|*
parameter_list|,
name|char
modifier|*
name|link
parameter_list|,
name|int
name|len
parameter_list|,
name|dmu_tx_t
modifier|*
parameter_list|)
function_decl|;
name|void
name|zfs_sa_upgrade
parameter_list|(
name|struct
name|sa_handle
modifier|*
parameter_list|,
name|dmu_tx_t
modifier|*
parameter_list|)
function_decl|;
name|void
name|zfs_sa_get_scanstamp
parameter_list|(
name|struct
name|znode
modifier|*
parameter_list|,
name|xvattr_t
modifier|*
parameter_list|)
function_decl|;
name|void
name|zfs_sa_set_scanstamp
parameter_list|(
name|struct
name|znode
modifier|*
parameter_list|,
name|xvattr_t
modifier|*
parameter_list|,
name|dmu_tx_t
modifier|*
parameter_list|)
function_decl|;
name|void
name|zfs_sa_uprade_pre
parameter_list|(
name|struct
name|sa_handle
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|dmu_tx_t
modifier|*
parameter_list|)
function_decl|;
name|void
name|zfs_sa_upgrade_post
parameter_list|(
name|struct
name|sa_handle
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|dmu_tx_t
modifier|*
parameter_list|)
function_decl|;
name|void
name|zfs_sa_upgrade_txholds
parameter_list|(
name|dmu_tx_t
modifier|*
parameter_list|,
name|struct
name|znode
modifier|*
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
comment|/* _SYS_ZFS_SA_H */
end_comment

end_unit

