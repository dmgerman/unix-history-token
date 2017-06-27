begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)inode.h	8.9 (Berkeley) 5/14/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FS_EXT2FS_INODE_H_
end_ifndef

begin_define
define|#
directive|define
name|_FS_EXT2FS_INODE_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<fs/ext2fs/ext2_extents.h>
end_include

begin_comment
comment|/*  * This must agree with the definition in<ufs/ufs/dir.h>.  */
end_comment

begin_define
define|#
directive|define
name|doff_t
value|int32_t
end_define

begin_define
define|#
directive|define
name|EXT2_NDADDR
value|12
end_define

begin_comment
comment|/* Direct addresses in inode. */
end_comment

begin_define
define|#
directive|define
name|EXT2_NIADDR
value|3
end_define

begin_comment
comment|/* Indirect addresses in inode. */
end_comment

begin_comment
comment|/*  * The size of physical and logical block numbers in EXT2FS.  */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|e2fs_daddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int64_t
name|e2fs_lbn_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int64_t
name|e4fs_daddr_t
typedef|;
end_typedef

begin_comment
comment|/*  * The inode is used to describe each active (or recently active) file in the  * EXT2FS filesystem. It is composed of two types of information. The first  * part is the information that is needed only while the file is active (such  * as the identity of the file and linkage to speed its lookup). The second  * part is the permanent meta-data associated with the file which is read in  * from the permanent dinode from long term storage when the file becomes  * active, and is put back when the file is no longer being used.  */
end_comment

begin_struct
struct|struct
name|inode
block|{
name|struct
name|vnode
modifier|*
name|i_vnode
decl_stmt|;
comment|/* Vnode associated with this inode. */
name|struct
name|ext2mount
modifier|*
name|i_ump
decl_stmt|;
name|uint32_t
name|i_flag
decl_stmt|;
comment|/* flags, see below */
name|ino_t
name|i_number
decl_stmt|;
comment|/* The identity of the inode. */
name|struct
name|m_ext2fs
modifier|*
name|i_e2fs
decl_stmt|;
comment|/* EXT2FS */
name|u_quad_t
name|i_modrev
decl_stmt|;
comment|/* Revision level for NFS lease. */
comment|/* 	 * Side effects; used during directory lookup. 	 */
name|int32_t
name|i_count
decl_stmt|;
comment|/* Size of free slot in directory. */
name|doff_t
name|i_endoff
decl_stmt|;
comment|/* End of useful stuff in directory. */
name|doff_t
name|i_diroff
decl_stmt|;
comment|/* Offset in dir, where we found last entry. */
name|doff_t
name|i_offset
decl_stmt|;
comment|/* Offset of free space in directory. */
name|uint32_t
name|i_block_group
decl_stmt|;
name|uint32_t
name|i_next_alloc_block
decl_stmt|;
name|uint32_t
name|i_next_alloc_goal
decl_stmt|;
comment|/* Fields from struct dinode in UFS. */
name|uint16_t
name|i_mode
decl_stmt|;
comment|/* IFMT, permissions; see below. */
name|int32_t
name|i_nlink
decl_stmt|;
comment|/* File link count. */
name|uint32_t
name|i_uid
decl_stmt|;
comment|/* File owner. */
name|uint32_t
name|i_gid
decl_stmt|;
comment|/* File group. */
name|uint64_t
name|i_size
decl_stmt|;
comment|/* File byte count. */
name|uint64_t
name|i_blocks
decl_stmt|;
comment|/* Blocks actually held. */
name|int32_t
name|i_atime
decl_stmt|;
comment|/* Last access time. */
name|int32_t
name|i_mtime
decl_stmt|;
comment|/* Last modified time. */
name|int32_t
name|i_ctime
decl_stmt|;
comment|/* Last inode change time. */
name|int32_t
name|i_birthtime
decl_stmt|;
comment|/* Inode creation time. */
name|int32_t
name|i_mtimensec
decl_stmt|;
comment|/* Last modified time. */
name|int32_t
name|i_atimensec
decl_stmt|;
comment|/* Last access time. */
name|int32_t
name|i_ctimensec
decl_stmt|;
comment|/* Last inode change time. */
name|int32_t
name|i_birthnsec
decl_stmt|;
comment|/* Inode creation time. */
name|uint32_t
name|i_gen
decl_stmt|;
comment|/* Generation number. */
name|uint64_t
name|i_facl
decl_stmt|;
comment|/* EA block number. */
name|uint32_t
name|i_flags
decl_stmt|;
comment|/* Status flags (chflags). */
name|uint32_t
name|i_db
index|[
name|EXT2_NDADDR
index|]
decl_stmt|;
comment|/* Direct disk blocks. */
name|uint32_t
name|i_ib
index|[
name|EXT2_NIADDR
index|]
decl_stmt|;
comment|/* Indirect disk blocks. */
name|struct
name|ext4_extent_cache
name|i_ext_cache
decl_stmt|;
comment|/* cache for ext4 extent */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The di_db fields may be overlaid with other information for  * file types that do not have associated disk storage. Block  * and character devices overlay the first data block with their  * dev_t value. Short symbolic links place their path in the  * di_db area.  */
end_comment

begin_define
define|#
directive|define
name|i_shortlink
value|i_db
end_define

begin_define
define|#
directive|define
name|i_rdev
value|i_db[0]
end_define

begin_comment
comment|/* File permissions. */
end_comment

begin_define
define|#
directive|define
name|IEXEC
value|0000100
end_define

begin_comment
comment|/* Executable. */
end_comment

begin_define
define|#
directive|define
name|IWRITE
value|0000200
end_define

begin_comment
comment|/* Writeable. */
end_comment

begin_define
define|#
directive|define
name|IREAD
value|0000400
end_define

begin_comment
comment|/* Readable. */
end_comment

begin_define
define|#
directive|define
name|ISVTX
value|0001000
end_define

begin_comment
comment|/* Sticky bit. */
end_comment

begin_define
define|#
directive|define
name|ISGID
value|0002000
end_define

begin_comment
comment|/* Set-gid. */
end_comment

begin_define
define|#
directive|define
name|ISUID
value|0004000
end_define

begin_comment
comment|/* Set-uid. */
end_comment

begin_comment
comment|/* File types. */
end_comment

begin_define
define|#
directive|define
name|IFMT
value|0170000
end_define

begin_comment
comment|/* Mask of file type. */
end_comment

begin_define
define|#
directive|define
name|IFIFO
value|0010000
end_define

begin_comment
comment|/* Named pipe (fifo). */
end_comment

begin_define
define|#
directive|define
name|IFCHR
value|0020000
end_define

begin_comment
comment|/* Character device. */
end_comment

begin_define
define|#
directive|define
name|IFDIR
value|0040000
end_define

begin_comment
comment|/* Directory file. */
end_comment

begin_define
define|#
directive|define
name|IFBLK
value|0060000
end_define

begin_comment
comment|/* Block device. */
end_comment

begin_define
define|#
directive|define
name|IFREG
value|0100000
end_define

begin_comment
comment|/* Regular file. */
end_comment

begin_define
define|#
directive|define
name|IFLNK
value|0120000
end_define

begin_comment
comment|/* Symbolic link. */
end_comment

begin_define
define|#
directive|define
name|IFSOCK
value|0140000
end_define

begin_comment
comment|/* UNIX domain socket. */
end_comment

begin_define
define|#
directive|define
name|IFWHT
value|0160000
end_define

begin_comment
comment|/* Whiteout. */
end_comment

begin_comment
comment|/* These flags are kept in i_flag. */
end_comment

begin_define
define|#
directive|define
name|IN_ACCESS
value|0x0001
end_define

begin_comment
comment|/* Access time update request. */
end_comment

begin_define
define|#
directive|define
name|IN_CHANGE
value|0x0002
end_define

begin_comment
comment|/* Inode change time update request. */
end_comment

begin_define
define|#
directive|define
name|IN_UPDATE
value|0x0004
end_define

begin_comment
comment|/* Modification time update request. */
end_comment

begin_define
define|#
directive|define
name|IN_MODIFIED
value|0x0008
end_define

begin_comment
comment|/* Inode has been modified. */
end_comment

begin_define
define|#
directive|define
name|IN_RENAME
value|0x0010
end_define

begin_comment
comment|/* Inode is being renamed. */
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

begin_define
define|#
directive|define
name|IN_LAZYMOD
value|0x0040
end_define

begin_comment
comment|/* Modified, but don't write yet. */
end_comment

begin_define
define|#
directive|define
name|IN_SPACECOUNTED
value|0x0080
end_define

begin_comment
comment|/* Blocks to be freed in free count. */
end_comment

begin_define
define|#
directive|define
name|IN_LAZYACCESS
value|0x0100
end_define

begin_comment
comment|/* Process IN_ACCESS after the 					    suspension finished */
end_comment

begin_comment
comment|/*  * These are translation flags for some attributes that Ext4  * passes as inode flags but that we cannot pass directly.  */
end_comment

begin_define
define|#
directive|define
name|IN_E3INDEX
value|0x010000
end_define

begin_define
define|#
directive|define
name|IN_E4EXTENTS
value|0x020000
end_define

begin_define
define|#
directive|define
name|i_devvp
value|i_ump->um_devvp
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Structure used to pass around logical block paths generated by  * ext2_getlbns and used by truncate and bmap code.  */
end_comment

begin_struct
struct|struct
name|indir
block|{
name|e2fs_lbn_t
name|in_lbn
decl_stmt|;
comment|/* Logical block number. */
name|int
name|in_off
decl_stmt|;
comment|/* Offset in buffer. */
block|}
struct|;
end_struct

begin_comment
comment|/* Convert between inode pointers and vnode pointers. */
end_comment

begin_define
define|#
directive|define
name|VTOI
parameter_list|(
name|vp
parameter_list|)
value|((struct inode *)(vp)->v_data)
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
comment|/* This overlays the fid structure (see mount.h). */
end_comment

begin_struct
struct|struct
name|ufid
block|{
name|uint16_t
name|ufid_len
decl_stmt|;
comment|/* Length of structure. */
name|uint16_t
name|ufid_pad
decl_stmt|;
comment|/* Force 32-bit alignment. */
name|ino_t
name|ufid_ino
decl_stmt|;
comment|/* File number (ino). */
name|uint32_t
name|ufid_gen
decl_stmt|;
comment|/* Generation number. */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_FS_EXT2FS_INODE_H_ */
end_comment

end_unit

