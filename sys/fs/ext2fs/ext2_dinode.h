begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Aditya Sarawgi  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FS_EXT2FS_EXT2_DINODE_H_
end_ifndef

begin_define
define|#
directive|define
name|_FS_EXT2FS_EXT2_DINODE_H_
end_define

begin_comment
comment|/*  * Special inode numbers  * The root inode is the root of the file system.  Inode 0 can't be used for  * normal purposes and bad blocks are normally linked to inode 1, thus  * the root inode is 2.  * Inode 3 to 10 are reserved in ext2fs.  */
end_comment

begin_define
define|#
directive|define
name|EXT2_BADBLKINO
value|((ino_t)1)
end_define

begin_define
define|#
directive|define
name|EXT2_ROOTINO
value|((ino_t)2)
end_define

begin_define
define|#
directive|define
name|EXT2_ACLIDXINO
value|((ino_t)3)
end_define

begin_define
define|#
directive|define
name|EXT2_ACLDATAINO
value|((ino_t)4)
end_define

begin_define
define|#
directive|define
name|EXT2_BOOTLOADERINO
value|((ino_t)5)
end_define

begin_define
define|#
directive|define
name|EXT2_UNDELDIRINO
value|((ino_t)6)
end_define

begin_define
define|#
directive|define
name|EXT2_RESIZEINO
value|((ino_t)7)
end_define

begin_define
define|#
directive|define
name|EXT2_JOURNALINO
value|((ino_t)8)
end_define

begin_define
define|#
directive|define
name|EXT2_EXCLUDEINO
value|((ino_t)9)
end_define

begin_define
define|#
directive|define
name|EXT2_REPLICAINO
value|((ino_t)10)
end_define

begin_define
define|#
directive|define
name|EXT2_FIRSTINO
value|((ino_t)11)
end_define

begin_comment
comment|/*  * Inode flags  * The system supports EXT2_IMMUTABLE, EXT2_APPEND and EXT2_NODUMP flags.  * The current implementation also uses EXT4_INDEX, EXT4_EXTENTS and  * EXT4_HUGE_FILE with some restrictions, imposed the lack of write  * support.  */
end_comment

begin_define
define|#
directive|define
name|EXT2_SECRM
value|0x00000001
end_define

begin_comment
comment|/* Secure deletion */
end_comment

begin_define
define|#
directive|define
name|EXT2_UNRM
value|0x00000002
end_define

begin_comment
comment|/* Undelete */
end_comment

begin_define
define|#
directive|define
name|EXT2_COMPR
value|0x00000004
end_define

begin_comment
comment|/* Compress file */
end_comment

begin_define
define|#
directive|define
name|EXT2_SYNC
value|0x00000008
end_define

begin_comment
comment|/* Synchronous updates */
end_comment

begin_define
define|#
directive|define
name|EXT2_IMMUTABLE
value|0x00000010
end_define

begin_comment
comment|/* Immutable file */
end_comment

begin_define
define|#
directive|define
name|EXT2_APPEND
value|0x00000020
end_define

begin_comment
comment|/* Writes to file may only append */
end_comment

begin_define
define|#
directive|define
name|EXT2_NODUMP
value|0x00000040
end_define

begin_comment
comment|/* Do not dump file */
end_comment

begin_define
define|#
directive|define
name|EXT2_NOATIME
value|0x00000080
end_define

begin_comment
comment|/* Do not update atime */
end_comment

begin_define
define|#
directive|define
name|EXT4_INDEX
value|0x00001000
end_define

begin_comment
comment|/* Hash-indexed directory */
end_comment

begin_define
define|#
directive|define
name|EXT4_IMAGIC
value|0x00002000
end_define

begin_comment
comment|/* AFS directory */
end_comment

begin_define
define|#
directive|define
name|EXT4_JOURNAL_DATA
value|0x00004000
end_define

begin_comment
comment|/* File data should be journaled */
end_comment

begin_define
define|#
directive|define
name|EXT4_NOTAIL
value|0x00008000
end_define

begin_comment
comment|/* File tail should not be merged */
end_comment

begin_define
define|#
directive|define
name|EXT4_DIRSYNC
value|0x00010000
end_define

begin_comment
comment|/* Dirsync behaviour */
end_comment

begin_define
define|#
directive|define
name|EXT4_TOPDIR
value|0x00020000
end_define

begin_comment
comment|/* Top of directory hierarchies*/
end_comment

begin_define
define|#
directive|define
name|EXT4_HUGE_FILE
value|0x00040000
end_define

begin_comment
comment|/* Set to each huge file */
end_comment

begin_define
define|#
directive|define
name|EXT4_EXTENTS
value|0x00080000
end_define

begin_comment
comment|/* Inode uses extents */
end_comment

begin_define
define|#
directive|define
name|EXT4_EOFBLOCKS
value|0x00400000
end_define

begin_comment
comment|/* Blocks allocated beyond EOF */
end_comment

begin_comment
comment|/*  * Definitions for nanosecond timestamps.  * Ext3 inode versioning, 2006-12-13.  */
end_comment

begin_define
define|#
directive|define
name|EXT3_EPOCH_BITS
value|2
end_define

begin_define
define|#
directive|define
name|EXT3_EPOCH_MASK
value|((1<< EXT3_EPOCH_BITS) - 1)
end_define

begin_define
define|#
directive|define
name|EXT3_NSEC_MASK
value|(~0UL<< EXT3_EPOCH_BITS)
end_define

begin_define
define|#
directive|define
name|E2DI_HAS_XTIME
parameter_list|(
name|ip
parameter_list|)
value|(EXT2_HAS_RO_COMPAT_FEATURE(ip->i_e2fs,	\ 				    EXT2F_ROCOMPAT_EXTRA_ISIZE))
end_define

begin_define
define|#
directive|define
name|E2DI_HAS_HUGE_FILE
parameter_list|(
name|ip
parameter_list|)
value|(EXT2_HAS_RO_COMPAT_FEATURE(ip->i_e2fs,	\ 				    EXT2F_ROCOMPAT_HUGE_FILE))
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
value|(EXT2_N_BLOCKS * sizeof(uint32_t))
end_define

begin_comment
comment|/*  * Structure of an inode on the disk  */
end_comment

begin_struct
struct|struct
name|ext2fs_dinode
block|{
name|uint16_t
name|e2di_mode
decl_stmt|;
comment|/*   0: IFMT, permissions; see below. */
name|uint16_t
name|e2di_uid
decl_stmt|;
comment|/*   2: Owner UID */
name|uint32_t
name|e2di_size
decl_stmt|;
comment|/*   4: Size (in bytes) */
name|uint32_t
name|e2di_atime
decl_stmt|;
comment|/*   8: Access time */
name|uint32_t
name|e2di_ctime
decl_stmt|;
comment|/*  12: Change time */
name|uint32_t
name|e2di_mtime
decl_stmt|;
comment|/*  16: Modification time */
name|uint32_t
name|e2di_dtime
decl_stmt|;
comment|/*  20: Deletion time */
name|uint16_t
name|e2di_gid
decl_stmt|;
comment|/*  24: Owner GID */
name|uint16_t
name|e2di_nlink
decl_stmt|;
comment|/*  26: File link count */
name|uint32_t
name|e2di_nblock
decl_stmt|;
comment|/*  28: Blocks count */
name|uint32_t
name|e2di_flags
decl_stmt|;
comment|/*  32: Status flags (chflags) */
name|uint32_t
name|e2di_version
decl_stmt|;
comment|/*  36: Low 32 bits inode version */
name|uint32_t
name|e2di_blocks
index|[
name|EXT2_N_BLOCKS
index|]
decl_stmt|;
comment|/* 40: disk blocks */
name|uint32_t
name|e2di_gen
decl_stmt|;
comment|/* 100: generation number */
name|uint32_t
name|e2di_facl
decl_stmt|;
comment|/* 104: Low EA block */
name|uint32_t
name|e2di_size_high
decl_stmt|;
comment|/* 108: Upper bits of file size */
name|uint32_t
name|e2di_faddr
decl_stmt|;
comment|/* 112: Fragment address (obsolete) */
name|uint16_t
name|e2di_nblock_high
decl_stmt|;
comment|/* 116: Blocks count bits 47:32 */
name|uint16_t
name|e2di_facl_high
decl_stmt|;
comment|/* 118: File EA bits 47:32 */
name|uint16_t
name|e2di_uid_high
decl_stmt|;
comment|/* 120: Owner UID top 16 bits */
name|uint16_t
name|e2di_gid_high
decl_stmt|;
comment|/* 122: Owner GID top 16 bits */
name|uint16_t
name|e2di_chksum_lo
decl_stmt|;
comment|/* 124: Lower inode checksum */
name|uint16_t
name|e2di_lx_reserved
decl_stmt|;
comment|/* 126: Unused */
name|uint16_t
name|e2di_extra_isize
decl_stmt|;
comment|/* 128: Size of this inode */
name|uint16_t
name|e2di_chksum_hi
decl_stmt|;
comment|/* 130: High inode checksum */
name|uint32_t
name|e2di_ctime_extra
decl_stmt|;
comment|/* 132: Extra change time */
name|uint32_t
name|e2di_mtime_extra
decl_stmt|;
comment|/* 136: Extra modification time */
name|uint32_t
name|e2di_atime_extra
decl_stmt|;
comment|/* 140: Extra access time */
name|uint32_t
name|e2di_crtime
decl_stmt|;
comment|/* 144: Creation (birth)time */
name|uint32_t
name|e2di_crtime_extra
decl_stmt|;
comment|/* 148: Extra creation (birth)time */
name|uint32_t
name|e2di_version_hi
decl_stmt|;
comment|/* 152: High bits of inode version */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_FS_EXT2FS_EXT2_DINODE_H_ */
end_comment

end_unit

