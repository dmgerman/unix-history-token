begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  modified for EXT2FS support in Lites 1.1  *  *  Aug 1995, Godmar Back (gback@cs.utah.edu)  *  University of Utah, Department of Computer Science  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *  linux/include/linux/ext2_fs.h  *  * Copyright (C) 1992, 1993, 1994, 1995  * Remy Card (card@masi.ibp.fr)  * Laboratoire MASI - Institut Blaise Pascal  * Universite Pierre et Marie Curie (Paris VI)  *  *  from  *  *  linux/include/linux/minix_fs.h  *  *  Copyright (C) 1991, 1992  Linus Torvalds  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_EXT2_FS_H
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_EXT2_FS_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_define
define|#
directive|define
name|__u32
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|u32
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|__u16
value|u_int16_t
end_define

begin_define
define|#
directive|define
name|__u8
value|u_int8_t
end_define

begin_define
define|#
directive|define
name|__s32
value|int32_t
end_define

begin_define
define|#
directive|define
name|__s16
value|int16_t
end_define

begin_define
define|#
directive|define
name|__s8
value|int8_t
end_define

begin_define
define|#
directive|define
name|umode_t
value|mode_t
end_define

begin_define
define|#
directive|define
name|loff_t
value|off_t
end_define

begin_comment
comment|/* the Linux implementation of EXT2 stores some information about  * an inode in a ext2_inode_info structure which is part of the incore  * inode in Linux  * I decided to use the "spare" fields instead - we'll see how this  * works out  */
end_comment

begin_define
define|#
directive|define
name|i_block_group
value|i_spare[0]
end_define

begin_define
define|#
directive|define
name|i_next_alloc_block
value|i_spare[1]
end_define

begin_define
define|#
directive|define
name|i_next_alloc_goal
value|i_spare[2]
end_define

begin_define
define|#
directive|define
name|i_prealloc_block
value|i_din.di_spare[0]
end_define

begin_define
define|#
directive|define
name|i_prealloc_count
value|i_din.di_spare[1]
end_define

begin_comment
comment|/*  * The second extended filesystem constants/structures  */
end_comment

begin_comment
comment|/*  * Define EXT2FS_DEBUG to produce debug messages  */
end_comment

begin_undef
undef|#
directive|undef
name|EXT2FS_DEBUG
end_undef

begin_comment
comment|/*  * Define EXT2_PREALLOCATE to preallocate data blocks for expanding files  */
end_comment

begin_define
define|#
directive|define
name|EXT2_PREALLOCATE
end_define

begin_define
define|#
directive|define
name|EXT2_DEFAULT_PREALLOC_BLOCKS
value|8
end_define

begin_comment
comment|/*  * The second extended file system version  */
end_comment

begin_define
define|#
directive|define
name|EXT2FS_DATE
value|"95/08/09"
end_define

begin_define
define|#
directive|define
name|EXT2FS_VERSION
value|"0.5b"
end_define

begin_comment
comment|/*  * Debug code  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|EXT2FS_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|ext2_debug
parameter_list|(
name|f
parameter_list|,
name|a
modifier|...
parameter_list|)
value|{ \ 					printf ("EXT2-fs DEBUG (%s, %d): %s:", \ 						__FILE__, __LINE__, __FUNCTION__); \ 				  	printf (f, ## a); \ 					}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ext2_debug
parameter_list|(
name|f
parameter_list|,
name|a
modifier|...
parameter_list|)
end_define

begin_comment
comment|/**/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Special inodes numbers  */
end_comment

begin_define
define|#
directive|define
name|EXT2_BAD_INO
value|1
end_define

begin_comment
comment|/* Bad blocks inode */
end_comment

begin_define
define|#
directive|define
name|EXT2_ROOT_INO
value|2
end_define

begin_comment
comment|/* Root inode */
end_comment

begin_define
define|#
directive|define
name|EXT2_ACL_IDX_INO
value|3
end_define

begin_comment
comment|/* ACL inode */
end_comment

begin_define
define|#
directive|define
name|EXT2_ACL_DATA_INO
value|4
end_define

begin_comment
comment|/* ACL inode */
end_comment

begin_define
define|#
directive|define
name|EXT2_BOOT_LOADER_INO
value|5
end_define

begin_comment
comment|/* Boot loader inode */
end_comment

begin_define
define|#
directive|define
name|EXT2_UNDEL_DIR_INO
value|6
end_define

begin_comment
comment|/* Undelete directory inode */
end_comment

begin_comment
comment|/* First non-reserved inode for old ext2 filesystems */
end_comment

begin_define
define|#
directive|define
name|EXT2_GOOD_OLD_FIRST_INO
value|11
end_define

begin_comment
comment|/*  * The second extended file system magic number  */
end_comment

begin_define
define|#
directive|define
name|EXT2_SUPER_MAGIC
value|0xEF53
end_define

begin_comment
comment|/*  * Maximal count of links to a file  */
end_comment

begin_define
define|#
directive|define
name|EXT2_LINK_MAX
value|32000
end_define

begin_comment
comment|/*  * Note: under FreeBSD, the "user" versions of the following macros are  * used (and must be used) in most cases, because ((s)->u.ext2_sb.s_es is  * not accessible.  This depends on __KERNEL__ not being defined for  * kernel builds under FreeBSD.  */
end_comment

begin_comment
comment|/*  * Macro-instructions used to manage several block sizes  */
end_comment

begin_define
define|#
directive|define
name|EXT2_MIN_BLOCK_SIZE
value|1024
end_define

begin_define
define|#
directive|define
name|EXT2_MAX_BLOCK_SIZE
value|4096
end_define

begin_define
define|#
directive|define
name|EXT2_MIN_BLOCK_LOG_SIZE
value|10
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__KERNEL__
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|EXT2_BLOCK_SIZE
parameter_list|(
name|s
parameter_list|)
value|((s)->s_blocksize)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EXT2_BLOCK_SIZE
parameter_list|(
name|s
parameter_list|)
value|(EXT2_MIN_BLOCK_SIZE<< (s)->s_log_block_size)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|EXT2_ACLE_PER_BLOCK
parameter_list|(
name|s
parameter_list|)
value|(EXT2_BLOCK_SIZE(s) / sizeof (struct ext2_acl_entry))
end_define

begin_define
define|#
directive|define
name|EXT2_ADDR_PER_BLOCK
parameter_list|(
name|s
parameter_list|)
value|(EXT2_BLOCK_SIZE(s) / sizeof (__u32))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_define
define|#
directive|define
name|EXT2_BLOCK_SIZE_BITS
parameter_list|(
name|s
parameter_list|)
value|((s)->s_blocksize_bits)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EXT2_BLOCK_SIZE_BITS
parameter_list|(
name|s
parameter_list|)
value|((s)->s_log_block_size + 10)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_define
define|#
directive|define
name|EXT2_ADDR_PER_BLOCK_BITS
parameter_list|(
name|s
parameter_list|)
value|((s)->u.ext2_sb.s_addr_per_block_bits)
end_define

begin_define
define|#
directive|define
name|EXT2_INODE_SIZE
parameter_list|(
name|s
parameter_list|)
value|((s)->u.ext2_sb.s_inode_size)
end_define

begin_define
define|#
directive|define
name|EXT2_FIRST_INO
parameter_list|(
name|s
parameter_list|)
value|((s)->u.ext2_sb.s_first_ino)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EXT2_INODE_SIZE
parameter_list|(
name|s
parameter_list|)
value|(((s)->s_rev_level == EXT2_GOOD_OLD_REV) ? \ 				 EXT2_GOOD_OLD_INODE_SIZE : \ 				 (s)->s_inode_size)
end_define

begin_define
define|#
directive|define
name|EXT2_FIRST_INO
parameter_list|(
name|s
parameter_list|)
value|(((s)->s_rev_level == EXT2_GOOD_OLD_REV) ? \ 				 EXT2_GOOD_OLD_FIRST_INO : \ 				 (s)->s_first_ino)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !notyet */
end_comment

begin_define
define|#
directive|define
name|EXT2_INODES_PER_BLOCK
parameter_list|(
name|s
parameter_list|)
value|((s)->s_inodes_per_block)
end_define

begin_comment
comment|/* Should be sizeof(struct ext2_inode): */
end_comment

begin_define
define|#
directive|define
name|EXT2_INODE_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|EXT2_FIRST_INO
value|11
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* notyet */
end_comment

begin_comment
comment|/*  * Macro-instructions used to manage fragments  */
end_comment

begin_define
define|#
directive|define
name|EXT2_MIN_FRAG_SIZE
value|1024
end_define

begin_define
define|#
directive|define
name|EXT2_MAX_FRAG_SIZE
value|4096
end_define

begin_define
define|#
directive|define
name|EXT2_MIN_FRAG_LOG_SIZE
value|10
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_define
define|#
directive|define
name|EXT2_FRAG_SIZE
parameter_list|(
name|s
parameter_list|)
value|((s)->u.ext2_sb.s_frag_size)
end_define

begin_define
define|#
directive|define
name|EXT2_FRAGS_PER_BLOCK
parameter_list|(
name|s
parameter_list|)
value|((s)->u.ext2_sb.s_frags_per_block)
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXT2_FRAG_SIZE
parameter_list|(
name|s
parameter_list|)
value|((s)->s_frag_size)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EXT2_FRAG_SIZE
parameter_list|(
name|s
parameter_list|)
value|(EXT2_MIN_FRAG_SIZE<< (s)->s_log_frag_size)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|EXT2_FRAGS_PER_BLOCK
parameter_list|(
name|s
parameter_list|)
value|(EXT2_BLOCK_SIZE(s) / EXT2_FRAG_SIZE(s))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * ACL structures  */
end_comment

begin_struct
struct|struct
name|ext2_acl_header
comment|/* Header of Access Control Lists */
block|{
name|__u32
name|aclh_size
decl_stmt|;
name|__u32
name|aclh_file_count
decl_stmt|;
name|__u32
name|aclh_acle_count
decl_stmt|;
name|__u32
name|aclh_first_acle
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ext2_acl_entry
comment|/* Access Control List Entry */
block|{
name|__u32
name|acle_size
decl_stmt|;
name|__u16
name|acle_perms
decl_stmt|;
comment|/* Access permissions */
name|__u16
name|acle_type
decl_stmt|;
comment|/* Type of entry */
name|__u16
name|acle_tag
decl_stmt|;
comment|/* User or group identity */
name|__u16
name|acle_pad1
decl_stmt|;
name|__u32
name|acle_next
decl_stmt|;
comment|/* Pointer on next entry for the */
comment|/* same inode or on next free entry */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure of a blocks group descriptor  */
end_comment

begin_struct
struct|struct
name|ext2_group_desc
block|{
name|__u32
name|bg_block_bitmap
decl_stmt|;
comment|/* Blocks bitmap block */
name|__u32
name|bg_inode_bitmap
decl_stmt|;
comment|/* Inodes bitmap block */
name|__u32
name|bg_inode_table
decl_stmt|;
comment|/* Inodes table block */
name|__u16
name|bg_free_blocks_count
decl_stmt|;
comment|/* Free blocks count */
name|__u16
name|bg_free_inodes_count
decl_stmt|;
comment|/* Free inodes count */
name|__u16
name|bg_used_dirs_count
decl_stmt|;
comment|/* Directories count */
name|__u16
name|bg_pad
decl_stmt|;
name|__u32
name|bg_reserved
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Macro-instructions used to manage group descriptors  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_define
define|#
directive|define
name|EXT2_BLOCKS_PER_GROUP
parameter_list|(
name|s
parameter_list|)
value|((s)->u.ext2_sb.s_blocks_per_group)
end_define

begin_define
define|#
directive|define
name|EXT2_DESC_PER_BLOCK
parameter_list|(
name|s
parameter_list|)
value|((s)->u.ext2_sb.s_desc_per_block)
end_define

begin_define
define|#
directive|define
name|EXT2_INODES_PER_GROUP
parameter_list|(
name|s
parameter_list|)
value|((s)->u.ext2_sb.s_inodes_per_group)
end_define

begin_define
define|#
directive|define
name|EXT2_DESC_PER_BLOCK_BITS
parameter_list|(
name|s
parameter_list|)
value|((s)->u.ext2_sb.s_desc_per_block_bits)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EXT2_BLOCKS_PER_GROUP
parameter_list|(
name|s
parameter_list|)
value|((s)->s_blocks_per_group)
end_define

begin_define
define|#
directive|define
name|EXT2_DESC_PER_BLOCK
parameter_list|(
name|s
parameter_list|)
value|(EXT2_BLOCK_SIZE(s) / sizeof (struct ext2_group_desc))
end_define

begin_define
define|#
directive|define
name|EXT2_INODES_PER_GROUP
parameter_list|(
name|s
parameter_list|)
value|((s)->s_inodes_per_group)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Constants relative to the data blocks  */
end_comment

begin_define
define|#
directive|define
name|EXT2_NDIR_BLOCKS
value|12
end_define

begin_define
define|#
directive|define
name|EXT2_IND_BLOCK
value|EXT2_NDIR_BLOCKS
end_define

begin_define
define|#
directive|define
name|EXT2_DIND_BLOCK
value|(EXT2_IND_BLOCK + 1)
end_define

begin_define
define|#
directive|define
name|EXT2_TIND_BLOCK
value|(EXT2_DIND_BLOCK + 1)
end_define

begin_define
define|#
directive|define
name|EXT2_N_BLOCKS
value|(EXT2_TIND_BLOCK + 1)
end_define

begin_define
define|#
directive|define
name|EXT2_MAXSYMLINKLEN
value|(EXT2_N_BLOCKS * sizeof (__u32))
end_define

begin_comment
comment|/*  * Inode flags  */
end_comment

begin_define
define|#
directive|define
name|EXT2_SECRM_FL
value|0x00000001
end_define

begin_comment
comment|/* Secure deletion */
end_comment

begin_define
define|#
directive|define
name|EXT2_UNRM_FL
value|0x00000002
end_define

begin_comment
comment|/* Undelete */
end_comment

begin_define
define|#
directive|define
name|EXT2_COMPR_FL
value|0x00000004
end_define

begin_comment
comment|/* Compress file */
end_comment

begin_define
define|#
directive|define
name|EXT2_SYNC_FL
value|0x00000008
end_define

begin_comment
comment|/* Synchronous updates */
end_comment

begin_define
define|#
directive|define
name|EXT2_IMMUTABLE_FL
value|0x00000010
end_define

begin_comment
comment|/* Immutable file */
end_comment

begin_define
define|#
directive|define
name|EXT2_APPEND_FL
value|0x00000020
end_define

begin_comment
comment|/* writes to file may only append */
end_comment

begin_define
define|#
directive|define
name|EXT2_NODUMP_FL
value|0x00000040
end_define

begin_comment
comment|/* do not dump file */
end_comment

begin_define
define|#
directive|define
name|EXT2_NOATIME_FL
value|0x00000080
end_define

begin_comment
comment|/* do not update atime */
end_comment

begin_comment
comment|/* Reserved for compression usage... */
end_comment

begin_define
define|#
directive|define
name|EXT2_DIRTY_FL
value|0x00000100
end_define

begin_define
define|#
directive|define
name|EXT2_COMPRBLK_FL
value|0x00000200
end_define

begin_comment
comment|/* One or more compressed clusters */
end_comment

begin_define
define|#
directive|define
name|EXT2_NOCOMP_FL
value|0x00000400
end_define

begin_comment
comment|/* Don't compress */
end_comment

begin_define
define|#
directive|define
name|EXT2_ECOMPR_FL
value|0x00000800
end_define

begin_comment
comment|/* Compression error */
end_comment

begin_comment
comment|/* End compression flags --- maybe not all used */
end_comment

begin_define
define|#
directive|define
name|EXT2_BTREE_FL
value|0x00001000
end_define

begin_comment
comment|/* btree format dir */
end_comment

begin_define
define|#
directive|define
name|EXT2_RESERVED_FL
value|0x80000000
end_define

begin_comment
comment|/* reserved for ext2 lib */
end_comment

begin_define
define|#
directive|define
name|EXT2_FL_USER_VISIBLE
value|0x00001FFF
end_define

begin_comment
comment|/* User visible flags */
end_comment

begin_define
define|#
directive|define
name|EXT2_FL_USER_MODIFIABLE
value|0x000000FF
end_define

begin_comment
comment|/* User modifiable flags */
end_comment

begin_comment
comment|/*  * ioctl commands  */
end_comment

begin_define
define|#
directive|define
name|EXT2_IOC_GETFLAGS
value|_IOR('f', 1, long)
end_define

begin_define
define|#
directive|define
name|EXT2_IOC_SETFLAGS
value|_IOW('f', 2, long)
end_define

begin_define
define|#
directive|define
name|EXT2_IOC_GETVERSION
value|_IOR('v', 1, long)
end_define

begin_define
define|#
directive|define
name|EXT2_IOC_SETVERSION
value|_IOW('v', 2, long)
end_define

begin_comment
comment|/*  * Only declare `struct ext2_inode' if<ufs/ufs/inode.h> hasn't made things  * difficult by #defining i_mode and other struct members.  The details of  * the struct are only needed in ext2_inode_cnv.c where the ext2fs on-disk  * inode is converted to a ufs in-core inode.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|i_mode
end_ifndef

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
name|i_generation
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

begin_define
define|#
directive|define
name|i_size_high
value|i_dir_acl
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__KERNEL__
argument_list|)
operator|||
name|defined
argument_list|(
name|__linux__
argument_list|)
end_if

begin_define
define|#
directive|define
name|i_reserved1
value|osd1.linux1.l_i_reserved1
end_define

begin_define
define|#
directive|define
name|i_frag
value|osd2.linux2.l_i_frag
end_define

begin_define
define|#
directive|define
name|i_fsize
value|osd2.linux2.l_i_fsize
end_define

begin_define
define|#
directive|define
name|i_reserved2
value|osd2.linux2.l_i_reserved2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__hurd__
end_ifdef

begin_define
define|#
directive|define
name|i_translator
value|osd1.hurd1.h_i_translator
end_define

begin_define
define|#
directive|define
name|i_frag
value|osd2.hurd2.h_i_frag;
end_define

begin_define
define|#
directive|define
name|i_fsize
value|osd2.hurd2.h_i_fsize;
end_define

begin_define
define|#
directive|define
name|i_uid_high
value|osd2.hurd2.h_i_uid_high
end_define

begin_define
define|#
directive|define
name|i_gid_high
value|osd2.hurd2.h_i_gid_high
end_define

begin_define
define|#
directive|define
name|i_author
value|osd2.hurd2.h_i_author
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__masix__
end_ifdef

begin_define
define|#
directive|define
name|i_reserved1
value|osd1.masix1.m_i_reserved1
end_define

begin_define
define|#
directive|define
name|i_frag
value|osd2.masix2.m_i_frag
end_define

begin_define
define|#
directive|define
name|i_fsize
value|osd2.masix2.m_i_fsize
end_define

begin_define
define|#
directive|define
name|i_reserved2
value|osd2.masix2.m_i_reserved2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* i_mode */
end_comment

begin_comment
comment|/*  * File system states  */
end_comment

begin_define
define|#
directive|define
name|EXT2_VALID_FS
value|0x0001
end_define

begin_comment
comment|/* Unmounted cleanly */
end_comment

begin_define
define|#
directive|define
name|EXT2_ERROR_FS
value|0x0002
end_define

begin_comment
comment|/* Errors detected */
end_comment

begin_comment
comment|/*  * Mount flags  */
end_comment

begin_define
define|#
directive|define
name|EXT2_MOUNT_CHECK_NORMAL
value|0x0001
end_define

begin_comment
comment|/* Do some more checks */
end_comment

begin_define
define|#
directive|define
name|EXT2_MOUNT_CHECK_STRICT
value|0x0002
end_define

begin_comment
comment|/* Do again more checks */
end_comment

begin_define
define|#
directive|define
name|EXT2_MOUNT_CHECK
value|(EXT2_MOUNT_CHECK_NORMAL | \ 					 EXT2_MOUNT_CHECK_STRICT)
end_define

begin_define
define|#
directive|define
name|EXT2_MOUNT_GRPID
value|0x0004
end_define

begin_comment
comment|/* Create files with directory's group */
end_comment

begin_define
define|#
directive|define
name|EXT2_MOUNT_DEBUG
value|0x0008
end_define

begin_comment
comment|/* Some debugging messages */
end_comment

begin_define
define|#
directive|define
name|EXT2_MOUNT_ERRORS_CONT
value|0x0010
end_define

begin_comment
comment|/* Continue on errors */
end_comment

begin_define
define|#
directive|define
name|EXT2_MOUNT_ERRORS_RO
value|0x0020
end_define

begin_comment
comment|/* Remount fs ro on errors */
end_comment

begin_define
define|#
directive|define
name|EXT2_MOUNT_ERRORS_PANIC
value|0x0040
end_define

begin_comment
comment|/* Panic on errors */
end_comment

begin_define
define|#
directive|define
name|EXT2_MOUNT_MINIX_DF
value|0x0080
end_define

begin_comment
comment|/* Mimics the Minix statfs */
end_comment

begin_define
define|#
directive|define
name|clear_opt
parameter_list|(
name|o
parameter_list|,
name|opt
parameter_list|)
value|o&= ~EXT2_MOUNT_##opt
end_define

begin_define
define|#
directive|define
name|set_opt
parameter_list|(
name|o
parameter_list|,
name|opt
parameter_list|)
value|o |= EXT2_MOUNT_##opt
end_define

begin_define
define|#
directive|define
name|test_opt
parameter_list|(
name|sb
parameter_list|,
name|opt
parameter_list|)
value|((sb)->u.ext2_sb.s_mount_opt& \ 					 EXT2_MOUNT_##opt)
end_define

begin_comment
comment|/*  * Maximal mount counts between two filesystem checks  */
end_comment

begin_define
define|#
directive|define
name|EXT2_DFL_MAX_MNT_COUNT
value|20
end_define

begin_comment
comment|/* Allow 20 mounts */
end_comment

begin_define
define|#
directive|define
name|EXT2_DFL_CHECKINTERVAL
value|0
end_define

begin_comment
comment|/* Don't use interval check */
end_comment

begin_comment
comment|/*  * Behaviour when detecting errors  */
end_comment

begin_define
define|#
directive|define
name|EXT2_ERRORS_CONTINUE
value|1
end_define

begin_comment
comment|/* Continue execution */
end_comment

begin_define
define|#
directive|define
name|EXT2_ERRORS_RO
value|2
end_define

begin_comment
comment|/* Remount fs read-only */
end_comment

begin_define
define|#
directive|define
name|EXT2_ERRORS_PANIC
value|3
end_define

begin_comment
comment|/* Panic */
end_comment

begin_define
define|#
directive|define
name|EXT2_ERRORS_DEFAULT
value|EXT2_ERRORS_CONTINUE
end_define

begin_comment
comment|/*  * Structure of the super block  */
end_comment

begin_struct
struct|struct
name|ext2_super_block
block|{
name|__u32
name|s_inodes_count
decl_stmt|;
comment|/* Inodes count */
name|__u32
name|s_blocks_count
decl_stmt|;
comment|/* Blocks count */
name|__u32
name|s_r_blocks_count
decl_stmt|;
comment|/* Reserved blocks count */
name|__u32
name|s_free_blocks_count
decl_stmt|;
comment|/* Free blocks count */
name|__u32
name|s_free_inodes_count
decl_stmt|;
comment|/* Free inodes count */
name|__u32
name|s_first_data_block
decl_stmt|;
comment|/* First Data Block */
name|__u32
name|s_log_block_size
decl_stmt|;
comment|/* Block size */
name|__s32
name|s_log_frag_size
decl_stmt|;
comment|/* Fragment size */
name|__u32
name|s_blocks_per_group
decl_stmt|;
comment|/* # Blocks per group */
name|__u32
name|s_frags_per_group
decl_stmt|;
comment|/* # Fragments per group */
name|__u32
name|s_inodes_per_group
decl_stmt|;
comment|/* # Inodes per group */
name|__u32
name|s_mtime
decl_stmt|;
comment|/* Mount time */
name|__u32
name|s_wtime
decl_stmt|;
comment|/* Write time */
name|__u16
name|s_mnt_count
decl_stmt|;
comment|/* Mount count */
name|__s16
name|s_max_mnt_count
decl_stmt|;
comment|/* Maximal mount count */
name|__u16
name|s_magic
decl_stmt|;
comment|/* Magic signature */
name|__u16
name|s_state
decl_stmt|;
comment|/* File system state */
name|__u16
name|s_errors
decl_stmt|;
comment|/* Behaviour when detecting errors */
name|__u16
name|s_minor_rev_level
decl_stmt|;
comment|/* minor revision level */
name|__u32
name|s_lastcheck
decl_stmt|;
comment|/* time of last check */
name|__u32
name|s_checkinterval
decl_stmt|;
comment|/* max. time between checks */
name|__u32
name|s_creator_os
decl_stmt|;
comment|/* OS */
name|__u32
name|s_rev_level
decl_stmt|;
comment|/* Revision level */
name|__u16
name|s_def_resuid
decl_stmt|;
comment|/* Default uid for reserved blocks */
name|__u16
name|s_def_resgid
decl_stmt|;
comment|/* Default gid for reserved blocks */
comment|/* 	 * These fields are for EXT2_DYNAMIC_REV superblocks only. 	 * 	 * Note: the difference between the compatible feature set and 	 * the incompatible feature set is that if there is a bit set 	 * in the incompatible feature set that the kernel doesn't 	 * know about, it should refuse to mount the filesystem. 	 *  	 * e2fsck's requirements are more strict; if it doesn't know 	 * about a feature in either the compatible or incompatible 	 * feature set, it must abort and not try to meddle with 	 * things it doesn't understand... 	 */
name|__u32
name|s_first_ino
decl_stmt|;
comment|/* First non-reserved inode */
name|__u16
name|s_inode_size
decl_stmt|;
comment|/* size of inode structure */
name|__u16
name|s_block_group_nr
decl_stmt|;
comment|/* block group # of this superblock */
name|__u32
name|s_feature_compat
decl_stmt|;
comment|/* compatible feature set */
name|__u32
name|s_feature_incompat
decl_stmt|;
comment|/* incompatible feature set */
name|__u32
name|s_feature_ro_compat
decl_stmt|;
comment|/* readonly-compatible feature set */
name|__u8
name|s_uuid
index|[
literal|16
index|]
decl_stmt|;
comment|/* 128-bit uuid for volume */
name|char
name|s_volume_name
index|[
literal|16
index|]
decl_stmt|;
comment|/* volume name */
name|char
name|s_last_mounted
index|[
literal|64
index|]
decl_stmt|;
comment|/* directory where last mounted */
name|__u32
name|s_algorithm_usage_bitmap
decl_stmt|;
comment|/* For compression */
comment|/* 	 * Performance hints.  Directory preallocation should only 	 * happen if the EXT2_COMPAT_PREALLOC flag is on. 	 */
name|__u8
name|s_prealloc_blocks
decl_stmt|;
comment|/* Nr of blocks to try to preallocate*/
name|__u8
name|s_prealloc_dir_blocks
decl_stmt|;
comment|/* Nr to preallocate for dirs */
name|__u16
name|s_padding1
decl_stmt|;
name|__u32
name|s_reserved
index|[
literal|204
index|]
decl_stmt|;
comment|/* Padding to the end of the block */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_define
define|#
directive|define
name|EXT2_SB
parameter_list|(
name|sb
parameter_list|)
value|(&((sb)->u.ext2_sb))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Assume that user mode programs are passing in an ext2fs superblock, not  * a kernel struct super_block.  This will allow us to call the feature-test  * macros from user land. */
end_comment

begin_define
define|#
directive|define
name|EXT2_SB
parameter_list|(
name|sb
parameter_list|)
value|(sb)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Codes for operating systems  */
end_comment

begin_define
define|#
directive|define
name|EXT2_OS_LINUX
value|0
end_define

begin_define
define|#
directive|define
name|EXT2_OS_HURD
value|1
end_define

begin_define
define|#
directive|define
name|EXT2_OS_MASIX
value|2
end_define

begin_define
define|#
directive|define
name|EXT2_OS_FREEBSD
value|3
end_define

begin_define
define|#
directive|define
name|EXT2_OS_LITES
value|4
end_define

begin_comment
comment|/*  * Revision levels  */
end_comment

begin_define
define|#
directive|define
name|EXT2_GOOD_OLD_REV
value|0
end_define

begin_comment
comment|/* The good old (original) format */
end_comment

begin_define
define|#
directive|define
name|EXT2_DYNAMIC_REV
value|1
end_define

begin_comment
comment|/* V2 format w/ dynamic inode sizes */
end_comment

begin_define
define|#
directive|define
name|EXT2_CURRENT_REV
value|EXT2_GOOD_OLD_REV
end_define

begin_define
define|#
directive|define
name|EXT2_MAX_SUPP_REV
value|EXT2_DYNAMIC_REV
end_define

begin_define
define|#
directive|define
name|EXT2_GOOD_OLD_INODE_SIZE
value|128
end_define

begin_comment
comment|/*  * Feature set definitions  */
end_comment

begin_define
define|#
directive|define
name|EXT2_HAS_COMPAT_FEATURE
parameter_list|(
name|sb
parameter_list|,
name|mask
parameter_list|)
define|\
value|( EXT2_SB(sb)->s_feature_compat& (mask) )
end_define

begin_define
define|#
directive|define
name|EXT2_HAS_RO_COMPAT_FEATURE
parameter_list|(
name|sb
parameter_list|,
name|mask
parameter_list|)
define|\
value|( EXT2_SB(sb)->s_feature_ro_compat& (mask) )
end_define

begin_define
define|#
directive|define
name|EXT2_HAS_INCOMPAT_FEATURE
parameter_list|(
name|sb
parameter_list|,
name|mask
parameter_list|)
define|\
value|( EXT2_SB(sb)->s_feature_incompat& (mask) )
end_define

begin_define
define|#
directive|define
name|EXT2_FEATURE_COMPAT_DIR_PREALLOC
value|0x0001
end_define

begin_define
define|#
directive|define
name|EXT2_FEATURE_RO_COMPAT_SPARSE_SUPER
value|0x0001
end_define

begin_define
define|#
directive|define
name|EXT2_FEATURE_RO_COMPAT_LARGE_FILE
value|0x0002
end_define

begin_define
define|#
directive|define
name|EXT2_FEATURE_RO_COMPAT_BTREE_DIR
value|0x0004
end_define

begin_define
define|#
directive|define
name|EXT2_FEATURE_INCOMPAT_COMPRESSION
value|0x0001
end_define

begin_define
define|#
directive|define
name|EXT2_FEATURE_INCOMPAT_FILETYPE
value|0x0002
end_define

begin_define
define|#
directive|define
name|EXT2_FEATURE_COMPAT_SUPP
value|0
end_define

begin_define
define|#
directive|define
name|EXT2_FEATURE_INCOMPAT_SUPP
value|EXT2_FEATURE_INCOMPAT_FILETYPE
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_define
define|#
directive|define
name|EXT2_FEATURE_RO_COMPAT_SUPP
value|(EXT2_FEATURE_RO_COMPAT_SPARSE_SUPER| \ 					 EXT2_FEATURE_RO_COMPAT_LARGE_FILE| \ 					 EXT2_FEATURE_RO_COMPAT_BTREE_DIR)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EXT2_FEATURE_RO_COMPAT_SUPP
value|EXT2_FEATURE_RO_COMPAT_SPARSE_SUPER
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Default values for user and/or group using reserved blocks  */
end_comment

begin_define
define|#
directive|define
name|EXT2_DEF_RESUID
value|0
end_define

begin_define
define|#
directive|define
name|EXT2_DEF_RESGID
value|0
end_define

begin_comment
comment|/*  * Structure of a directory entry  */
end_comment

begin_define
define|#
directive|define
name|EXT2_NAME_LEN
value|255
end_define

begin_struct
struct|struct
name|ext2_dir_entry
block|{
name|__u32
name|inode
decl_stmt|;
comment|/* Inode number */
name|__u16
name|rec_len
decl_stmt|;
comment|/* Directory entry length */
name|__u16
name|name_len
decl_stmt|;
comment|/* Name length */
name|char
name|name
index|[
name|EXT2_NAME_LEN
index|]
decl_stmt|;
comment|/* File name */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The new version of the directory entry.  Since EXT2 structures are  * stored in intel byte order, and the name_len field could never be  * bigger than 255 chars, it's safe to reclaim the extra byte for the  * file_type field.  */
end_comment

begin_struct
struct|struct
name|ext2_dir_entry_2
block|{
name|__u32
name|inode
decl_stmt|;
comment|/* Inode number */
name|__u16
name|rec_len
decl_stmt|;
comment|/* Directory entry length */
name|__u8
name|name_len
decl_stmt|;
comment|/* Name length */
name|__u8
name|file_type
decl_stmt|;
name|char
name|name
index|[
name|EXT2_NAME_LEN
index|]
decl_stmt|;
comment|/* File name */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ext2 directory file types.  Only the low 3 bits are used.  The  * other bits are reserved for now.  */
end_comment

begin_define
define|#
directive|define
name|EXT2_FT_UNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|EXT2_FT_REG_FILE
value|1
end_define

begin_define
define|#
directive|define
name|EXT2_FT_DIR
value|2
end_define

begin_define
define|#
directive|define
name|EXT2_FT_CHRDEV
value|3
end_define

begin_define
define|#
directive|define
name|EXT2_FT_BLKDEV
value|4
end_define

begin_define
define|#
directive|define
name|EXT2_FT_FIFO
value|5
end_define

begin_define
define|#
directive|define
name|EXT2_FT_SOCK
value|6
end_define

begin_define
define|#
directive|define
name|EXT2_FT_SYMLINK
value|7
end_define

begin_define
define|#
directive|define
name|EXT2_FT_MAX
value|8
end_define

begin_comment
comment|/*  * EXT2_DIR_PAD defines the directory entries boundaries  *  * NOTE: It must be a multiple of 4  */
end_comment

begin_define
define|#
directive|define
name|EXT2_DIR_PAD
value|4
end_define

begin_define
define|#
directive|define
name|EXT2_DIR_ROUND
value|(EXT2_DIR_PAD - 1)
end_define

begin_define
define|#
directive|define
name|EXT2_DIR_REC_LEN
parameter_list|(
name|name_len
parameter_list|)
value|(((name_len) + 8 + EXT2_DIR_ROUND)& \ 					 ~EXT2_DIR_ROUND)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_EXT2_FS_H */
end_comment

end_unit

