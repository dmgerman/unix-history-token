begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  added for EXT2FS support in Lites 1.1  *  *  Aug 1995, Godmar Back (gback@cs.utah.edu)  *  University of Utah, Department of Computer Science  *  *  Note that this started out to be ext2_fs_i.h. In reality it  *  doesn't have anything to do with. I put the declaration of  *  the on disk ext2 format here from ext2_fs.h because this is  *  something that would name clash with other stuff.  *  This is used only in ext2_inode_cnv.c  */
end_comment

begin_comment
comment|/*  *  linux/include/linux/ext2_fs_i.h  *  * Copyright (C) 1992, 1993, 1994, 1995  * Remy Card (card@masi.ibp.fr)  * Laboratoire MASI - Institut Blaise Pascal  * Universite Pierre et Marie Curie (Paris VI)  *  *  from  *  *  linux/include/linux/minix_fs_i.h  *  *  Copyright (C) 1991, 1992  Linus Torvalds  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EXT2_FS_I
end_ifndef

begin_define
define|#
directive|define
name|_EXT2_FS_I
end_define

begin_comment
comment|/*  * Structure of an inode on the disk  */
end_comment

begin_struct
struct|struct
name|ext2_inode
block|{
name|__u16
name|i_mode
decl_stmt|;
comment|/* File mode */
name|__u16
name|i_uid
decl_stmt|;
comment|/* Owner Uid */
name|__u32
name|i_size
decl_stmt|;
comment|/* Size in bytes */
name|__u32
name|i_atime
decl_stmt|;
comment|/* Access time */
name|__u32
name|i_ctime
decl_stmt|;
comment|/* Creation time */
name|__u32
name|i_mtime
decl_stmt|;
comment|/* Modification time */
name|__u32
name|i_dtime
decl_stmt|;
comment|/* Deletion Time */
name|__u16
name|i_gid
decl_stmt|;
comment|/* Group Id */
name|__u16
name|i_links_count
decl_stmt|;
comment|/* Links count */
name|__u32
name|i_blocks
decl_stmt|;
comment|/* Blocks count */
name|__u32
name|i_flags
decl_stmt|;
comment|/* File flags */
union|union
block|{
struct|struct
block|{
name|__u32
name|l_i_reserved1
decl_stmt|;
block|}
name|linux1
struct|;
struct|struct
block|{
name|__u32
name|h_i_translator
decl_stmt|;
block|}
name|hurd1
struct|;
struct|struct
block|{
name|__u32
name|m_i_reserved1
decl_stmt|;
block|}
name|masix1
struct|;
block|}
name|osd1
union|;
comment|/* OS dependent 1 */
name|__u32
name|i_block
index|[
name|EXT2_N_BLOCKS
index|]
decl_stmt|;
comment|/* Pointers to blocks */
name|__u32
name|i_version
decl_stmt|;
comment|/* File version (for NFS) */
name|__u32
name|i_file_acl
decl_stmt|;
comment|/* File ACL */
name|__u32
name|i_dir_acl
decl_stmt|;
comment|/* Directory ACL */
name|__u32
name|i_faddr
decl_stmt|;
comment|/* Fragment address */
union|union
block|{
struct|struct
block|{
name|__u8
name|l_i_frag
decl_stmt|;
comment|/* Fragment number */
name|__u8
name|l_i_fsize
decl_stmt|;
comment|/* Fragment size */
name|__u16
name|i_pad1
decl_stmt|;
name|__u32
name|l_i_reserved2
index|[
literal|2
index|]
decl_stmt|;
block|}
name|linux2
struct|;
struct|struct
block|{
name|__u8
name|h_i_frag
decl_stmt|;
comment|/* Fragment number */
name|__u8
name|h_i_fsize
decl_stmt|;
comment|/* Fragment size */
name|__u16
name|h_i_mode_high
decl_stmt|;
name|__u16
name|h_i_uid_high
decl_stmt|;
name|__u16
name|h_i_gid_high
decl_stmt|;
name|__u32
name|h_i_author
decl_stmt|;
block|}
name|hurd2
struct|;
struct|struct
block|{
name|__u8
name|m_i_frag
decl_stmt|;
comment|/* Fragment number */
name|__u8
name|m_i_fsize
decl_stmt|;
comment|/* Fragment size */
name|__u16
name|m_pad1
decl_stmt|;
name|__u32
name|m_i_reserved2
index|[
literal|2
index|]
decl_stmt|;
block|}
name|masix2
struct|;
block|}
name|osd2
union|;
comment|/* OS dependent 2 */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _EXT2_FS_I */
end_comment

end_unit

