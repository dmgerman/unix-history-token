begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  *  modified for EXT2FS support in Lites 1.1  *  *  Aug 1995, Godmar Back (gback@cs.utah.edu)  *  University of Utah, Department of Computer Science  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2009 Aditya Sarawgi  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FS_EXT2FS_EXT2_FS_H
end_ifndef

begin_define
define|#
directive|define
name|_FS_EXT2FS_EXT2_FS_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/*  * Special inode numbers  */
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
name|E2FS_REV0_FIRST_INO
value|11
end_define

begin_comment
comment|/*  * The second extended file system magic number  */
end_comment

begin_define
define|#
directive|define
name|E2FS_MAGIC
value|0xEF53
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_comment
comment|/*  * FreeBSD passes the pointer to the in-core struct with relevant  * fields to EXT2_SB macro when accessing superblock fields.  */
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
comment|/*  * Maximal count of links to a file  */
end_comment

begin_define
define|#
directive|define
name|EXT2_LINK_MAX
value|32000
end_define

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
value|(EXT2_N_BLOCKS * sizeof (uint32_t))
end_define

begin_comment
comment|/*  * The path name on which the file system is mounted is maintained  * in fs_fsmnt. MAXMNTLEN defines the amount of space allocated in  * the super block for this name.  */
end_comment

begin_define
define|#
directive|define
name|MAXMNTLEN
value|512
end_define

begin_comment
comment|/*  * Super block for an ext2fs file system.  */
end_comment

begin_struct
struct|struct
name|ext2fs
block|{
name|u_int32_t
name|e2fs_icount
decl_stmt|;
comment|/* Inode count */
name|u_int32_t
name|e2fs_bcount
decl_stmt|;
comment|/* blocks count */
name|u_int32_t
name|e2fs_rbcount
decl_stmt|;
comment|/* reserved blocks count */
name|u_int32_t
name|e2fs_fbcount
decl_stmt|;
comment|/* free blocks count */
name|u_int32_t
name|e2fs_ficount
decl_stmt|;
comment|/* free inodes count */
name|u_int32_t
name|e2fs_first_dblock
decl_stmt|;
comment|/* first data block */
name|u_int32_t
name|e2fs_log_bsize
decl_stmt|;
comment|/* block size = 1024*(2^e2fs_log_bsize) */
name|u_int32_t
name|e2fs_log_fsize
decl_stmt|;
comment|/* fragment size */
name|u_int32_t
name|e2fs_bpg
decl_stmt|;
comment|/* blocks per group */
name|u_int32_t
name|e2fs_fpg
decl_stmt|;
comment|/* frags per group */
name|u_int32_t
name|e2fs_ipg
decl_stmt|;
comment|/* inodes per group */
name|u_int32_t
name|e2fs_mtime
decl_stmt|;
comment|/* mount time */
name|u_int32_t
name|e2fs_wtime
decl_stmt|;
comment|/* write time */
name|u_int16_t
name|e2fs_mnt_count
decl_stmt|;
comment|/* mount count */
name|u_int16_t
name|e2fs_max_mnt_count
decl_stmt|;
comment|/* max mount count */
name|u_int16_t
name|e2fs_magic
decl_stmt|;
comment|/* magic number */
name|u_int16_t
name|e2fs_state
decl_stmt|;
comment|/* file system state */
name|u_int16_t
name|e2fs_beh
decl_stmt|;
comment|/* behavior on errors */
name|u_int16_t
name|e2fs_minrev
decl_stmt|;
comment|/* minor revision level */
name|u_int32_t
name|e2fs_lastfsck
decl_stmt|;
comment|/* time of last fsck */
name|u_int32_t
name|e2fs_fsckintv
decl_stmt|;
comment|/* max time between fscks */
name|u_int32_t
name|e2fs_creator
decl_stmt|;
comment|/* creator OS */
name|u_int32_t
name|e2fs_rev
decl_stmt|;
comment|/* revision level */
name|u_int16_t
name|e2fs_ruid
decl_stmt|;
comment|/* default uid for reserved blocks */
name|u_int16_t
name|e2fs_rgid
decl_stmt|;
comment|/* default gid for reserved blocks */
comment|/* EXT2_DYNAMIC_REV superblocks */
name|u_int32_t
name|e2fs_first_ino
decl_stmt|;
comment|/* first non-reserved inode */
name|u_int16_t
name|e2fs_inode_size
decl_stmt|;
comment|/* size of inode structure */
name|u_int16_t
name|e2fs_block_group_nr
decl_stmt|;
comment|/* block grp number of this sblk*/
name|u_int32_t
name|e2fs_features_compat
decl_stmt|;
comment|/*  compatible feature set */
name|u_int32_t
name|e2fs_features_incompat
decl_stmt|;
comment|/* incompatible feature set */
name|u_int32_t
name|e2fs_features_rocompat
decl_stmt|;
comment|/* RO-compatible feature set */
name|u_int8_t
name|e2fs_uuid
index|[
literal|16
index|]
decl_stmt|;
comment|/* 128-bit uuid for volume */
name|char
name|e2fs_vname
index|[
literal|16
index|]
decl_stmt|;
comment|/* volume name */
name|char
name|e2fs_fsmnt
index|[
literal|64
index|]
decl_stmt|;
comment|/* name mounted on */
name|u_int32_t
name|e2fs_algo
decl_stmt|;
comment|/* For comcate for dir */
name|u_int16_t
name|e2fs_reserved_ngdb
decl_stmt|;
comment|/* # of reserved gd blocks for resize */
name|u_int32_t
name|reserved2
index|[
literal|204
index|]
decl_stmt|;
block|}
struct|;
end_struct

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

begin_comment
comment|/*  * In-Memory Superblock  */
end_comment

begin_struct
struct|struct
name|m_ext2fs
block|{
name|struct
name|ext2fs
modifier|*
name|e2fs
decl_stmt|;
name|char
name|e2fs_fsmnt
index|[
name|MAXMNTLEN
index|]
decl_stmt|;
comment|/* name mounted on */
name|char
name|e2fs_ronly
decl_stmt|;
comment|/* mounted read-only flag */
name|char
name|e2fs_fmod
decl_stmt|;
comment|/* super block modified flag */
name|uint32_t
name|e2fs_bsize
decl_stmt|;
comment|/* Block size */
name|uint32_t
name|e2fs_bshift
decl_stmt|;
comment|/* calc of logical block no */
name|int32_t
name|e2fs_bmask
decl_stmt|;
comment|/* calc of block offset */
name|int32_t
name|e2fs_bpg
decl_stmt|;
comment|/* Number of blocks per group */
name|int64_t
name|e2fs_qbmask
decl_stmt|;
comment|/* = s_blocksize -1 */
name|uint32_t
name|e2fs_fsbtodb
decl_stmt|;
comment|/* Shift to get disk block */
name|uint32_t
name|e2fs_ipg
decl_stmt|;
comment|/* Number of inodes per group */
name|uint32_t
name|e2fs_ipb
decl_stmt|;
comment|/* Number of inodes per block */
name|uint32_t
name|e2fs_itpg
decl_stmt|;
comment|/* Number of inode table per group */
name|uint32_t
name|e2fs_fsize
decl_stmt|;
comment|/* Size of fragments per block */
name|uint32_t
name|e2fs_fpb
decl_stmt|;
comment|/* Number of fragments per block */
name|uint32_t
name|e2fs_fpg
decl_stmt|;
comment|/* Number of fragments per group */
name|uint32_t
name|e2fs_dbpg
decl_stmt|;
comment|/* Number of descriptor blocks per group */
name|uint32_t
name|e2fs_descpb
decl_stmt|;
comment|/* Number of group descriptors per block */
name|uint32_t
name|e2fs_gdbcount
decl_stmt|;
comment|/* Number of group descriptors */
name|uint32_t
name|e2fs_gcount
decl_stmt|;
comment|/* Number of groups */
name|uint32_t
name|e2fs_first_inode
decl_stmt|;
comment|/* First inode on fs */
name|int32_t
name|e2fs_isize
decl_stmt|;
comment|/* Size of inode */
name|uint32_t
name|e2fs_mount_opt
decl_stmt|;
name|uint32_t
name|e2fs_blocksize_bits
decl_stmt|;
name|uint32_t
name|e2fs_total_dir
decl_stmt|;
comment|/* Total number of directories */
name|uint8_t
modifier|*
name|e2fs_contigdirs
decl_stmt|;
name|char
name|e2fs_wasvalid
decl_stmt|;
comment|/* valid at mount time */
name|off_t
name|e2fs_maxfilesize
decl_stmt|;
name|struct
name|ext2_gd
modifier|*
name|e2fs_gd
decl_stmt|;
comment|/* Group Descriptors */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The second extended file system version  */
end_comment

begin_define
define|#
directive|define
name|E2FS_DATE
value|"95/08/09"
end_define

begin_define
define|#
directive|define
name|E2FS_VERSION
value|"0.5b"
end_define

begin_comment
comment|/*  * Revision levels  */
end_comment

begin_define
define|#
directive|define
name|E2FS_REV0
value|0
end_define

begin_comment
comment|/* The good old (original) format */
end_comment

begin_define
define|#
directive|define
name|E2FS_REV1
value|1
end_define

begin_comment
comment|/* V2 format w/ dynamic inode sizes */
end_comment

begin_define
define|#
directive|define
name|E2FS_CURRENT_REV
value|E2FS_REV0
end_define

begin_define
define|#
directive|define
name|E2FS_MAX_SUPP_REV
value|E2FS_REV1
end_define

begin_define
define|#
directive|define
name|E2FS_REV0_INODE_SIZE
value|128
end_define

begin_comment
comment|/*  * compatible/incompatible features  */
end_comment

begin_define
define|#
directive|define
name|EXT2F_COMPAT_PREALLOC
value|0x0001
end_define

begin_define
define|#
directive|define
name|EXT2F_COMPAT_RESIZE
value|0x0010
end_define

begin_define
define|#
directive|define
name|EXT2F_ROCOMPAT_SPARSESUPER
value|0x0001
end_define

begin_define
define|#
directive|define
name|EXT2F_ROCOMPAT_LARGEFILE
value|0x0002
end_define

begin_define
define|#
directive|define
name|EXT2F_ROCOMPAT_BTREE_DIR
value|0x0004
end_define

begin_define
define|#
directive|define
name|EXT2F_INCOMPAT_COMP
value|0x0001
end_define

begin_define
define|#
directive|define
name|EXT2F_INCOMPAT_FTYPE
value|0x0002
end_define

begin_comment
comment|/*  * Features supported in this implementation  *  * We support the following REV1 features:  * - EXT2F_ROCOMPAT_SPARSESUPER  * - EXT2F_ROCOMPAT_LARGEFILE  * - EXT2F_INCOMPAT_FTYPE  */
end_comment

begin_define
define|#
directive|define
name|EXT2F_COMPAT_SUPP
value|0x0000
end_define

begin_define
define|#
directive|define
name|EXT2F_ROCOMPAT_SUPP
value|(EXT2F_ROCOMPAT_SPARSESUPER \ 					 | EXT2F_ROCOMPAT_LARGEFILE)
end_define

begin_define
define|#
directive|define
name|EXT2F_INCOMPAT_SUPP
value|EXT2F_INCOMPAT_FTYPE
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
value|( EXT2_SB(sb)->e2fs->e2fs_features_compat& htole32(mask) )
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
value|( EXT2_SB(sb)->e2fs->e2fs_features_rocompat& htole32(mask) )
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
value|( EXT2_SB(sb)->e2fs->e2fs_features_incompat& htole32(mask) )
end_define

begin_comment
comment|/*  * Definitions of behavior on errors  */
end_comment

begin_define
define|#
directive|define
name|E2FS_BEH_CONTINUE
value|1
end_define

begin_comment
comment|/* continue operation */
end_comment

begin_define
define|#
directive|define
name|E2FS_BEH_READONLY
value|2
end_define

begin_comment
comment|/* remount fs read only */
end_comment

begin_define
define|#
directive|define
name|E2FS_BEH_PANIC
value|3
end_define

begin_comment
comment|/* cause panic */
end_comment

begin_define
define|#
directive|define
name|E2FS_BEH_DEFAULT
value|E2FS_BEH_CONTINUE
end_define

begin_comment
comment|/*  * OS identification  */
end_comment

begin_define
define|#
directive|define
name|E2FS_OS_LINUX
value|0
end_define

begin_define
define|#
directive|define
name|E2FS_OS_HURD
value|1
end_define

begin_define
define|#
directive|define
name|E2FS_OS_MASIX
value|2
end_define

begin_define
define|#
directive|define
name|E2FS_OS_FREEBSD
value|3
end_define

begin_define
define|#
directive|define
name|E2FS_OS_LITES
value|4
end_define

begin_comment
comment|/*  * File clean flags  */
end_comment

begin_define
define|#
directive|define
name|E2FS_ISCLEAN
value|0x0001
end_define

begin_comment
comment|/* Unmounted cleanly */
end_comment

begin_define
define|#
directive|define
name|E2FS_ERRORS
value|0x0002
end_define

begin_comment
comment|/* Errors detected */
end_comment

begin_comment
comment|/* ext2 file system block group descriptor */
end_comment

begin_struct
struct|struct
name|ext2_gd
block|{
name|u_int32_t
name|ext2bgd_b_bitmap
decl_stmt|;
comment|/* blocks bitmap block */
name|u_int32_t
name|ext2bgd_i_bitmap
decl_stmt|;
comment|/* inodes bitmap block */
name|u_int32_t
name|ext2bgd_i_tables
decl_stmt|;
comment|/* inodes table block  */
name|u_int16_t
name|ext2bgd_nbfree
decl_stmt|;
comment|/* number of free blocks */
name|u_int16_t
name|ext2bgd_nifree
decl_stmt|;
comment|/* number of free inodes */
name|u_int16_t
name|ext2bgd_ndirs
decl_stmt|;
comment|/* number of directories */
name|u_int16_t
name|reserved
decl_stmt|;
name|u_int32_t
name|reserved2
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* EXT2FS metadatas are stored in little-endian byte order. These macros  * helps reading these metadatas  */
end_comment

begin_define
define|#
directive|define
name|e2fs_cgload
parameter_list|(
name|old
parameter_list|,
name|new
parameter_list|,
name|size
parameter_list|)
value|memcpy((new), (old), (size));
end_define

begin_define
define|#
directive|define
name|e2fs_cgsave
parameter_list|(
name|old
parameter_list|,
name|new
parameter_list|,
name|size
parameter_list|)
value|memcpy((new), (old), (size));
end_define

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
name|_KERNEL
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXT2_BLOCK_SIZE
parameter_list|(
name|s
parameter_list|)
value|((s)->e2fs_bsize)
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
value|(EXT2_MIN_BLOCK_SIZE<< (s)->e2fs_log_bsize)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|EXT2_ADDR_PER_BLOCK
parameter_list|(
name|s
parameter_list|)
value|(EXT2_BLOCK_SIZE(s) / sizeof (uint32_t))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXT2_BLOCK_SIZE_BITS
parameter_list|(
name|s
parameter_list|)
value|((s)->e2fs_blocksize_bits)
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
value|((s)->e2fs_log_bsize + 10)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXT2_ADDR_PER_BLOCK_BITS
parameter_list|(
name|s
parameter_list|)
value|(EXT2_SB(s)->s_addr_per_block_bits)
end_define

begin_define
define|#
directive|define
name|EXT2_INODE_SIZE
parameter_list|(
name|s
parameter_list|)
value|(EXT2_SB(s)->e2fs_isize)
end_define

begin_define
define|#
directive|define
name|EXT2_FIRST_INO
parameter_list|(
name|s
parameter_list|)
value|(EXT2_SB(s)->e2fs_first_inode)
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
value|(((s)->s_rev_level == E2FS_REV0) ? \ 				 E2FS_REV0 : (s)->s_inode_size)
end_define

begin_define
define|#
directive|define
name|EXT2_FIRST_INO
parameter_list|(
name|s
parameter_list|)
value|(((s)->s_rev_level == E2FS_REV0) ? \ 				 E2FS_REV0 : (s)->e2fs_first_ino)
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXT2_FRAG_SIZE
parameter_list|(
name|s
parameter_list|)
value|(EXT2_SB(s)->e2fs_fsize)
end_define

begin_define
define|#
directive|define
name|EXT2_FRAGS_PER_BLOCK
parameter_list|(
name|s
parameter_list|)
value|(EXT2_SB(s)->e2fs_fpb)
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
value|(EXT2_MIN_FRAG_SIZE<< (s)->e2fs_log_fsize)
end_define

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
comment|/*  * Macro-instructions used to manage group descriptors  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXT2_BLOCKS_PER_GROUP
parameter_list|(
name|s
parameter_list|)
value|(EXT2_SB(s)->e2fs_bpg)
end_define

begin_define
define|#
directive|define
name|EXT2_DESC_PER_BLOCK
parameter_list|(
name|s
parameter_list|)
value|(EXT2_SB(s)->e2fs_descpb)
end_define

begin_define
define|#
directive|define
name|EXT2_DESC_PER_BLOCK_BITS
parameter_list|(
name|s
parameter_list|)
value|(EXT2_SB(s)->s_desc_per_block_bits)
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
value|((s)->e2fs_bpg)
end_define

begin_define
define|#
directive|define
name|EXT2_DESC_PER_BLOCK
parameter_list|(
name|s
parameter_list|)
value|(EXT2_BLOCK_SIZE(s) / sizeof (struct ext2_gd))
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
comment|/* _LINUX_EXT2_FS_H */
end_comment

end_unit

