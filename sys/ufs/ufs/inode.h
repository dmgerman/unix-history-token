begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)inode.h	8.9 (Berkeley) 5/14/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UFS_UFS_INODE_H_
end_ifndef

begin_define
define|#
directive|define
name|_UFS_UFS_INODE_H_
end_define

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<ufs/ufs/dinode.h>
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

begin_comment
comment|/*  * The inode is used to describe each active (or recently active) file in the  * UFS filesystem. It is composed of two types of information. The first part  * is the information that is needed only while the file is active (such as  * the identity of the file and linkage to speed its lookup). The second part  * is the permanent meta-data associated with the file which is read in  * from the permanent dinode from long term storage when the file becomes  * active, and is put back when the file is no longer being used.  */
end_comment

begin_struct
struct|struct
name|inode
block|{
name|TAILQ_ENTRY
argument_list|(
argument|inode
argument_list|)
name|i_nextsnap
expr_stmt|;
comment|/* snapshot file list. */
name|struct
name|vnode
modifier|*
name|i_vnode
decl_stmt|;
comment|/* Vnode associated with this inode. */
name|struct
name|ufsmount
modifier|*
name|i_ump
decl_stmt|;
comment|/* Ufsmount point associated with this inode. */
name|u_int32_t
name|i_flag
decl_stmt|;
comment|/* flags, see below */
name|struct
name|cdev
modifier|*
name|i_dev
decl_stmt|;
comment|/* Device associated with the inode. */
name|ino_t
name|i_number
decl_stmt|;
comment|/* The identity of the inode. */
name|int
name|i_effnlink
decl_stmt|;
comment|/* i_nlink when I/O completes */
name|struct
name|fs
modifier|*
name|i_fs
decl_stmt|;
comment|/* Associated filesystem superblock. */
name|struct
name|dquot
modifier|*
name|i_dquot
index|[
name|MAXQUOTAS
index|]
decl_stmt|;
comment|/* Dquot structures. */
name|u_quad_t
name|i_modrev
decl_stmt|;
comment|/* Revision level for NFS lease. */
name|struct
name|lockf
modifier|*
name|i_lockf
decl_stmt|;
comment|/* Head of byte-level lock list. */
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
name|ino_t
name|i_ino
decl_stmt|;
comment|/* Inode number of found directory. */
name|u_int32_t
name|i_reclen
decl_stmt|;
comment|/* Size of found directory entry. */
union|union
block|{
name|struct
name|dirhash
modifier|*
name|dirhash
decl_stmt|;
comment|/* Hashing for large directories. */
name|daddr_t
modifier|*
name|snapblklist
decl_stmt|;
comment|/* Collect expunged snapshot blocks. */
block|}
name|i_un
union|;
comment|/* 	 * Data for extended attribute modification.  	 */
name|u_char
modifier|*
name|i_ea_area
decl_stmt|;
comment|/* Pointer to malloced copy of EA area */
name|unsigned
name|i_ea_len
decl_stmt|;
comment|/* Length of i_ea_area */
name|int
name|i_ea_error
decl_stmt|;
comment|/* First errno in transaction */
comment|/* 	 * Copies from the on-disk dinode itself. 	 */
name|u_int16_t
name|i_mode
decl_stmt|;
comment|/* IFMT, permissions; see below. */
name|int16_t
name|i_nlink
decl_stmt|;
comment|/* File link count. */
name|u_int64_t
name|i_size
decl_stmt|;
comment|/* File byte count. */
name|u_int32_t
name|i_flags
decl_stmt|;
comment|/* Status flags (chflags). */
name|int64_t
name|i_gen
decl_stmt|;
comment|/* Generation number. */
name|u_int32_t
name|i_uid
decl_stmt|;
comment|/* File owner. */
name|u_int32_t
name|i_gid
decl_stmt|;
comment|/* File group. */
comment|/* 	 * The real copy of the on-disk inode. 	 */
union|union
block|{
name|struct
name|ufs1_dinode
modifier|*
name|din1
decl_stmt|;
comment|/* UFS1 on-disk dinode. */
name|struct
name|ufs2_dinode
modifier|*
name|din2
decl_stmt|;
comment|/* UFS2 on-disk dinode. */
block|}
name|dinode_u
union|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * These flags are kept in i_flag.  */
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
name|i_devvp
value|i_ump->um_devvp
end_define

begin_define
define|#
directive|define
name|i_umbufobj
value|i_ump->um_bo
end_define

begin_define
define|#
directive|define
name|i_dirhash
value|i_un.dirhash
end_define

begin_define
define|#
directive|define
name|i_snapblklist
value|i_un.snapblklist
end_define

begin_define
define|#
directive|define
name|i_din1
value|dinode_u.din1
end_define

begin_define
define|#
directive|define
name|i_din2
value|dinode_u.din2
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * The DIP macro is used to access fields in the dinode that are  * not cached in the inode itself.  */
end_comment

begin_define
define|#
directive|define
name|DIP
parameter_list|(
name|ip
parameter_list|,
name|field
parameter_list|)
define|\
value|(((ip)->i_ump->um_fstype == UFS1) ? \ 	(ip)->i_din1->d##field : (ip)->i_din2->d##field)
end_define

begin_define
define|#
directive|define
name|DIP_SET
parameter_list|(
name|ip
parameter_list|,
name|field
parameter_list|,
name|val
parameter_list|)
value|do { \ 	if ((ip)->i_ump->um_fstype == UFS1) \ 		(ip)->i_din1->d##field = (val); \ 	else \ 		(ip)->i_din2->d##field = (val); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|MAXSYMLINKLEN
parameter_list|(
name|ip
parameter_list|)
define|\
value|((ip)->i_ump->um_fstype == UFS1) ? \ 	((NDADDR + NIADDR) * sizeof(ufs1_daddr_t)) : \ 	((NDADDR + NIADDR) * sizeof(ufs2_daddr_t))
end_define

begin_define
define|#
directive|define
name|SHORTLINK
parameter_list|(
name|ip
parameter_list|)
define|\
value|(((ip)->i_ump->um_fstype == UFS1) ? \ 	(caddr_t)(ip)->i_din1->di_db : (caddr_t)(ip)->i_din2->di_db)
end_define

begin_comment
comment|/*  * Structure used to pass around logical block paths generated by  * ufs_getlbns and used by truncate and bmap code.  */
end_comment

begin_struct
struct|struct
name|indir
block|{
name|ufs2_daddr_t
name|in_lbn
decl_stmt|;
comment|/* Logical block number. */
name|int
name|in_off
decl_stmt|;
comment|/* Offset in buffer. */
name|int
name|in_exists
decl_stmt|;
comment|/* Flag if the block exists. */
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
comment|/* Determine if soft dependencies are being done */
end_comment

begin_define
define|#
directive|define
name|DOINGSOFTDEP
parameter_list|(
name|vp
parameter_list|)
value|((vp)->v_mount->mnt_flag& MNT_SOFTDEP)
end_define

begin_define
define|#
directive|define
name|DOINGASYNC
parameter_list|(
name|vp
parameter_list|)
value|((vp)->v_mount->mnt_flag& MNT_ASYNC)
end_define

begin_comment
comment|/* This overlays the fid structure (see mount.h). */
end_comment

begin_struct
struct|struct
name|ufid
block|{
name|u_int16_t
name|ufid_len
decl_stmt|;
comment|/* Length of structure. */
name|u_int16_t
name|ufid_pad
decl_stmt|;
comment|/* Force 32-bit alignment. */
name|ino_t
name|ufid_ino
decl_stmt|;
comment|/* File number (ino). */
name|int32_t
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
comment|/* !_UFS_UFS_INODE_H_ */
end_comment

end_unit

