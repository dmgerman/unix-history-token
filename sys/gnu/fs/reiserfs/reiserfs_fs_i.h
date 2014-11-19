begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2000 Hans Reiser  * See README for licensing and copyright details  *   * Ported to FreeBSD by Jean-SÃ©bastien PÃ©dron<jspedron@club-internet.fr>  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GNU_REISERFS_REISERFS_FS_I_H
end_ifndef

begin_define
define|#
directive|define
name|_GNU_REISERFS_REISERFS_FS_I_H
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_comment
comment|/* Bitmasks for i_flags field in reiserfs-specific part of inode */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/* 	 * This says what format of key do all items (but stat data) of 	 * an object have.  If this is set, that format is 3.6 otherwise 	 * - 3.5 	 */
name|i_item_key_version_mask
init|=
literal|0x0001
block|,
comment|/* If this is unset, object has 3.5 stat data, otherwise, it has 	 * 3.6 stat data with 64bit size, 32bit nlink etc. */
name|i_stat_data_version_mask
init|=
literal|0x0002
block|,
comment|/* File might need tail packing on close */
name|i_pack_on_close_mask
init|=
literal|0x0004
block|,
comment|/* Don't pack tail of file */
name|i_nopack_mask
init|=
literal|0x0008
block|,
comment|/* If those is set, "safe link" was created for this file during 	 * truncate or unlink. Safe link is used to avoid leakage of disk 	 * space on crash with some files open, but unlinked. */
name|i_link_saved_unlink_mask
init|=
literal|0x0010
block|,
name|i_link_saved_truncate_mask
init|=
literal|0x0020
block|,
name|i_priv_object
init|=
literal|0x0080
block|,
name|i_has_xattr_dir
init|=
literal|0x0100
block|, }
name|reiserfs_inode_flags
typedef|;
end_typedef

begin_struct
struct|struct
name|reiserfs_node
block|{
name|struct
name|vnode
modifier|*
name|i_vnode
decl_stmt|;
name|struct
name|vnode
modifier|*
name|i_devvp
decl_stmt|;
name|struct
name|cdev
modifier|*
name|i_dev
decl_stmt|;
name|ino_t
name|i_number
decl_stmt|;
name|ino_t
name|i_ino
decl_stmt|;
name|struct
name|reiserfs_sb_info
modifier|*
name|i_reiserfs
decl_stmt|;
name|uint32_t
name|i_flag
decl_stmt|;
comment|/* Flags, see below */
name|uint32_t
name|i_key
index|[
literal|4
index|]
decl_stmt|;
comment|/* Key is still 4 32 bit 						 integers */
name|uint32_t
name|i_flags
decl_stmt|;
comment|/* Transient inode flags that 						 are never stored on disk. 						 Bitmasks for this field 						 are defined above. */
name|uint32_t
name|i_first_direct_byte
decl_stmt|;
comment|/* Offset of first byte stored 						 in direct item. */
name|uint32_t
name|i_attrs
decl_stmt|;
comment|/* Copy of persistent inode 						 flags read from sd_attrs. */
name|uint16_t
name|i_mode
decl_stmt|;
comment|/* IFMT, permissions. */
name|int16_t
name|i_nlink
decl_stmt|;
comment|/* File link count. */
name|uint64_t
name|i_size
decl_stmt|;
comment|/* File byte count. */
name|uint32_t
name|i_bytes
decl_stmt|;
name|uid_t
name|i_uid
decl_stmt|;
comment|/* File owner. */
name|gid_t
name|i_gid
decl_stmt|;
comment|/* File group. */
name|struct
name|timespec
name|i_atime
decl_stmt|;
comment|/* Last access time. */
name|struct
name|timespec
name|i_mtime
decl_stmt|;
comment|/* Last modified time. */
name|struct
name|timespec
name|i_ctime
decl_stmt|;
comment|/* Last inode change time. */
name|uint32_t
name|i_blocks
decl_stmt|;
name|uint32_t
name|i_generation
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VTOI
parameter_list|(
name|vp
parameter_list|)
value|((struct reiserfs_node *)(vp)->v_data)
end_define

begin_define
define|#
directive|define
name|ITOV
parameter_list|(
name|ip
parameter_list|)
value|((ip)->i_vnode)
end_define

begin_comment
comment|/* These flags are kept in i_flag. */
end_comment

begin_define
define|#
directive|define
name|IN_HASHED
value|0x0020
end_define

begin_comment
comment|/* Inode is on hash list */
end_comment

begin_comment
comment|/* This overlays the fid structure (see mount.h) */
end_comment

begin_struct
struct|struct
name|rfid
block|{
name|uint16_t
name|rfid_len
decl_stmt|;
comment|/* Length of structure */
name|uint16_t
name|rfid_pad
decl_stmt|;
comment|/* Force 32-bit alignment */
name|ino_t
name|rfid_dirid
decl_stmt|;
comment|/* File key */
name|ino_t
name|rfid_objectid
decl_stmt|;
name|uint32_t
name|rfid_gen
decl_stmt|;
comment|/* Generation number */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined _GNU_REISERFS_REISERFS_FS_I_H */
end_comment

end_unit

