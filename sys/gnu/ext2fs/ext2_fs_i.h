begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  linux/include/linux/ext2_fs_i.h  *  * Copyright (C) 1992, 1993, 1994, 1995  * Remy Card (card@masi.ibp.fr)  * Laboratoire MASI - Institut Blaise Pascal  * Universite Pierre et Marie Curie (Paris VI)  *  *  from  *  *  linux/include/linux/minix_fs_i.h  *  *  Copyright (C) 1991, 1992  Linus Torvalds  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_EXT2_FS_I
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_EXT2_FS_I
end_define

begin_comment
comment|/*  * second extended file system inode data in memory  */
end_comment

begin_struct
struct|struct
name|ext2_inode_info
block|{
name|__u32
name|i_data
index|[
literal|15
index|]
decl_stmt|;
name|__u32
name|i_flags
decl_stmt|;
name|__u32
name|i_faddr
decl_stmt|;
name|__u8
name|i_frag_no
decl_stmt|;
name|__u8
name|i_frag_size
decl_stmt|;
name|__u16
name|i_osync
decl_stmt|;
name|__u32
name|i_file_acl
decl_stmt|;
name|__u32
name|i_dir_acl
decl_stmt|;
name|__u32
name|i_dtime
decl_stmt|;
name|__u32
name|i_version
decl_stmt|;
name|__u32
name|i_block_group
decl_stmt|;
name|__u32
name|i_next_alloc_block
decl_stmt|;
name|__u32
name|i_next_alloc_goal
decl_stmt|;
name|__u32
name|i_prealloc_block
decl_stmt|;
name|__u32
name|i_prealloc_count
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_EXT2_FS_I */
end_comment

end_unit

