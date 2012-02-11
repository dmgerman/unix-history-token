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

begin_define
define|#
directive|define
name|e2di_size_high
value|e2di_dacl
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
name|EXT2_FIRSTINO
value|((ino_t)11)
end_define

begin_comment
comment|/*  * Inode flags  * The current implementation uses only EXT2_IMMUTABLE and EXT2_APPEND flags  */
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
comment|/* writes to file may only append */
end_comment

begin_define
define|#
directive|define
name|EXT2_NODUMP
value|0x00000040
end_define

begin_comment
comment|/* do not dump file */
end_comment

begin_define
define|#
directive|define
name|EXT2_NOATIME
value|0x00000080
end_define

begin_comment
comment|/* do not update atime */
end_comment

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
comment|/*	 4: Size (in bytes) */
name|uint32_t
name|e2di_atime
decl_stmt|;
comment|/*	 8: Access time */
name|uint32_t
name|e2di_ctime
decl_stmt|;
comment|/*	12: Change time */
name|uint32_t
name|e2di_mtime
decl_stmt|;
comment|/*	16: Modification time */
name|uint32_t
name|e2di_dtime
decl_stmt|;
comment|/*	20: Deletion time */
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
name|e2di_linux_reserved1
decl_stmt|;
comment|/* 36 */
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
comment|/* 104: file ACL (not implemented) */
name|uint32_t
name|e2di_dacl
decl_stmt|;
comment|/* 108: dir ACL (not implemented) */
name|uint32_t
name|e2di_faddr
decl_stmt|;
comment|/* 112: fragment address */
name|uint8_t
name|e2di_nfrag
decl_stmt|;
comment|/* 116: fragment number */
name|uint8_t
name|e2di_fsize
decl_stmt|;
comment|/* 117: fragment size */
name|uint16_t
name|e2di_linux_reserved2
decl_stmt|;
comment|/* 118 */
name|uint16_t
name|e2di_uid_high
decl_stmt|;
comment|/* 120: Owner UID top 16 bits */
name|uint16_t
name|e2di_gid_high
decl_stmt|;
comment|/* 122: Owner GID top 16 bits */
name|uint32_t
name|e2di_linux_reserved3
decl_stmt|;
comment|/* 124 */
name|uint16_t
name|e2di_extra_isize
decl_stmt|;
name|uint16_t
name|e2di_pad1
decl_stmt|;
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

