begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  modified for EXT2FS support in Lites 1.1  *  *  Aug 1995, Godmar Back (gback@cs.utah.edu)  *  University of Utah, Department of Computer Science  */
end_comment

begin_comment
comment|/*  *  linux/include/linux/ext2_fs_sb.h  *  * Copyright (C) 1992, 1993, 1994, 1995  * Remy Card (card@masi.ibp.fr)  * Laboratoire MASI - Institut Blaise Pascal  * Universite Pierre et Marie Curie (Paris VI)  *  *  from  *  *  linux/include/linux/minix_fs_sb.h  *  *  Copyright (C) 1991, 1992  Linus Torvalds  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_EXT2_FS_SB
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_EXT2_FS_SB
end_define

begin_comment
comment|/*  * The following is not needed anymore since the descriptors buffer  * heads are now dynamically allocated  */
end_comment

begin_comment
comment|/* #define EXT2_MAX_GROUP_DESC	8 */
end_comment

begin_define
define|#
directive|define
name|EXT2_MAX_GROUP_LOADED
value|8
end_define

begin_define
define|#
directive|define
name|buffer_head
value|buf
end_define

begin_define
define|#
directive|define
name|MAXMNTLEN
value|512
end_define

begin_comment
comment|/*  * second extended-fs super-block data in memory  */
end_comment

begin_struct
struct|struct
name|ext2_sb_info
block|{
name|unsigned
name|long
name|s_frag_size
decl_stmt|;
comment|/* Size of a fragment in bytes */
name|unsigned
name|long
name|s_frags_per_block
decl_stmt|;
comment|/* Number of fragments per block */
name|unsigned
name|long
name|s_inodes_per_block
decl_stmt|;
comment|/* Number of inodes per block */
name|unsigned
name|long
name|s_frags_per_group
decl_stmt|;
comment|/* Number of fragments in a group */
name|unsigned
name|long
name|s_blocks_per_group
decl_stmt|;
comment|/* Number of blocks in a group */
name|unsigned
name|long
name|s_inodes_per_group
decl_stmt|;
comment|/* Number of inodes in a group */
name|unsigned
name|long
name|s_itb_per_group
decl_stmt|;
comment|/* Number of inode table blocks per group */
name|unsigned
name|long
name|s_db_per_group
decl_stmt|;
comment|/* Number of descriptor blocks per group */
name|unsigned
name|long
name|s_desc_per_block
decl_stmt|;
comment|/* Number of group descriptors per block */
name|unsigned
name|long
name|s_groups_count
decl_stmt|;
comment|/* Number of groups in the fs */
name|struct
name|buffer_head
modifier|*
name|s_sbh
decl_stmt|;
comment|/* Buffer containing the super block */
name|struct
name|ext2_super_block
modifier|*
name|s_es
decl_stmt|;
comment|/* Pointer to the super block in the buffer */
name|struct
name|buffer_head
modifier|*
modifier|*
name|s_group_desc
decl_stmt|;
name|unsigned
name|short
name|s_loaded_inode_bitmaps
decl_stmt|;
name|unsigned
name|short
name|s_loaded_block_bitmaps
decl_stmt|;
name|unsigned
name|long
name|s_inode_bitmap_number
index|[
name|EXT2_MAX_GROUP_LOADED
index|]
decl_stmt|;
name|struct
name|buffer_head
modifier|*
name|s_inode_bitmap
index|[
name|EXT2_MAX_GROUP_LOADED
index|]
decl_stmt|;
name|unsigned
name|long
name|s_block_bitmap_number
index|[
name|EXT2_MAX_GROUP_LOADED
index|]
decl_stmt|;
name|struct
name|buffer_head
modifier|*
name|s_block_bitmap
index|[
name|EXT2_MAX_GROUP_LOADED
index|]
decl_stmt|;
name|int
name|s_rename_lock
decl_stmt|;
name|unsigned
name|long
name|s_mount_opt
decl_stmt|;
name|unsigned
name|short
name|s_resuid
decl_stmt|;
name|unsigned
name|short
name|s_resgid
decl_stmt|;
name|unsigned
name|short
name|s_mount_state
decl_stmt|;
comment|/*  	   stuff that FFS keeps in its super block or that linux 	   has in its non-ext2 specific super block and which is 	   generally considered useful  	*/
name|unsigned
name|long
name|s_blocksize
decl_stmt|;
name|unsigned
name|long
name|s_blocksize_bits
decl_stmt|;
name|unsigned
name|int
name|s_bshift
decl_stmt|;
comment|/* = log2(s_blocksize) */
name|quad_t
name|s_qbmask
decl_stmt|;
comment|/* = s_blocksize - 1 */
name|unsigned
name|int
name|s_fsbtodb
decl_stmt|;
comment|/* shift to get disk block */
name|char
name|s_rd_only
decl_stmt|;
comment|/* read-only 		*/
name|char
name|s_dirt
decl_stmt|;
comment|/* fs modified flag */
name|char
name|s_wasvalid
decl_stmt|;
comment|/* valid at mount time */
name|char
name|fs_fsmnt
index|[
name|MAXMNTLEN
index|]
decl_stmt|;
comment|/* name mounted on */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_EXT2_FS_SB */
end_comment

end_unit

