begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)inode.h	8.4 (Berkeley) 1/21/94  * $Id: inode.h,v 1.4 1994/12/27 13:59:14 bde Exp $  */
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
file|<ufs/ufs/dinode.h>
end_include

begin_comment
comment|/*  * Theoretically, directories can be more than 2Gb in length, however, in  * practice this seems unlikely. So, we define the type doff_t as a long  * to keep down the cost of doing lookup on a 32-bit machine. If you are  * porting to a 64-bit architecture, you should make doff_t the same as off_t.  */
end_comment

begin_define
define|#
directive|define
name|doff_t
value|long
end_define

begin_comment
comment|/*  * The inode is used to describe each active (or recently active)  * file in the UFS filesystem. It is composed of two types of  * information. The first part is the information that is needed  * only while the file is active (such as the identity of the file  * and linkage to speed its lookup). The second part is the   * permannent meta-data associated with the file which is read  * in from the permanent dinode from long term storage when the  * file becomes active, and is put back when the file is no longer  * being used.  */
end_comment

begin_struct
struct|struct
name|inode
block|{
name|struct
name|inode
modifier|*
name|i_next
decl_stmt|;
comment|/* Hash chain forward. */
name|struct
name|inode
modifier|*
modifier|*
name|i_prev
decl_stmt|;
comment|/* Hash chain back. */
name|struct
name|vnode
modifier|*
name|i_vnode
decl_stmt|;
comment|/* Vnode associated with this inode. */
name|struct
name|vnode
modifier|*
name|i_devvp
decl_stmt|;
comment|/* Vnode for block I/O. */
name|u_long
name|i_flag
decl_stmt|;
comment|/* I* flags. */
name|dev_t
name|i_dev
decl_stmt|;
comment|/* Device associated with the inode. */
name|ino_t
name|i_number
decl_stmt|;
comment|/* The identity of the inode. */
union|union
block|{
comment|/* Associated filesystem. */
name|struct
name|fs
modifier|*
name|fs
decl_stmt|;
comment|/* FFS */
name|struct
name|lfs
modifier|*
name|lfs
decl_stmt|;
comment|/* LFS */
block|}
name|inode_u
union|;
define|#
directive|define
name|i_fs
value|inode_u.fs
define|#
directive|define
name|i_lfs
value|inode_u.lfs
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
comment|/* Revision level for lease. */
name|struct
name|lockf
modifier|*
name|i_lockf
decl_stmt|;
comment|/* Head of byte-level lock list. */
name|pid_t
name|i_lockholder
decl_stmt|;
comment|/* DEBUG: holder of inode lock. */
name|pid_t
name|i_lockwaiter
decl_stmt|;
comment|/* DEBUG: latest blocked for inode lock. */
comment|/* 	 * Side effects; used during directory lookup. 	 */
name|long
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
name|u_long
name|i_reclen
decl_stmt|;
comment|/* Size of found directory entry. */
name|int
name|i_lockcount
decl_stmt|;
comment|/* Process lock count (recursion) */
name|long
name|i_spare
index|[
literal|10
index|]
decl_stmt|;
comment|/* Spares to round up to 128 bytes. */
comment|/* 	 * The on-disk dinode itself. 	 */
name|struct
name|dinode
name|i_din
decl_stmt|;
comment|/* 128 bytes of the on-disk dinode. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|i_atime
value|i_din.di_atime
end_define

begin_define
define|#
directive|define
name|i_blocks
value|i_din.di_blocks
end_define

begin_define
define|#
directive|define
name|i_ctime
value|i_din.di_ctime
end_define

begin_define
define|#
directive|define
name|i_db
value|i_din.di_db
end_define

begin_define
define|#
directive|define
name|i_flags
value|i_din.di_flags
end_define

begin_define
define|#
directive|define
name|i_gen
value|i_din.di_gen
end_define

begin_define
define|#
directive|define
name|i_gid
value|i_din.di_gid
end_define

begin_define
define|#
directive|define
name|i_ib
value|i_din.di_ib
end_define

begin_define
define|#
directive|define
name|i_mode
value|i_din.di_mode
end_define

begin_define
define|#
directive|define
name|i_mtime
value|i_din.di_mtime
end_define

begin_define
define|#
directive|define
name|i_nlink
value|i_din.di_nlink
end_define

begin_define
define|#
directive|define
name|i_rdev
value|i_din.di_rdev
end_define

begin_define
define|#
directive|define
name|i_shortlink
value|i_din.di_shortlink
end_define

begin_define
define|#
directive|define
name|i_size
value|i_din.di_size
end_define

begin_define
define|#
directive|define
name|i_uid
value|i_din.di_uid
end_define

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
name|IN_EXLOCK
value|0x0004
end_define

begin_comment
comment|/* File has exclusive lock. */
end_comment

begin_define
define|#
directive|define
name|IN_LOCKED
value|0x0008
end_define

begin_comment
comment|/* Inode lock. */
end_comment

begin_define
define|#
directive|define
name|IN_LWAIT
value|0x0010
end_define

begin_comment
comment|/* Process waiting on file lock. */
end_comment

begin_define
define|#
directive|define
name|IN_MODIFIED
value|0x0020
end_define

begin_comment
comment|/* Inode has been modified. */
end_comment

begin_define
define|#
directive|define
name|IN_RENAME
value|0x0040
end_define

begin_comment
comment|/* Inode is being renamed. */
end_comment

begin_define
define|#
directive|define
name|IN_SHLOCK
value|0x0080
end_define

begin_comment
comment|/* File has shared lock. */
end_comment

begin_define
define|#
directive|define
name|IN_UPDATE
value|0x0100
end_define

begin_comment
comment|/* Modification time update request. */
end_comment

begin_define
define|#
directive|define
name|IN_WANTED
value|0x0200
end_define

begin_comment
comment|/* Inode is wanted by a process. */
end_comment

begin_define
define|#
directive|define
name|IN_RECURSE
value|0x0400
end_define

begin_comment
comment|/* Recursion expected */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * Structure used to pass around logical block paths generated by  * ufs_getlbns and used by truncate and bmap code.  */
end_comment

begin_struct
struct|struct
name|indir
block|{
name|daddr_t
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
comment|/*  * XXX this is too long to be a macro, and isn't used in any time-critical  * place; in fact it is only used in ufs_vnops.c so it shouldn't be in a  * header file.  */
end_comment

begin_define
define|#
directive|define
name|ITIMES
parameter_list|(
name|ip
parameter_list|,
name|t1
parameter_list|,
name|t2
parameter_list|)
value|{						\ 	long tv_sec = time.tv_sec;					\ 	if ((ip)->i_flag& (IN_ACCESS | IN_CHANGE | IN_UPDATE)) {	\ 		(ip)->i_flag |= IN_MODIFIED;				\ 		if ((ip)->i_flag& IN_ACCESS)				\ 			(ip)->i_atime.ts_sec				\ 			= ((t1) ==&time ? tv_sec : (t1)->tv_sec);	\ 		if ((ip)->i_flag& IN_UPDATE) {				\ 			(ip)->i_mtime.ts_sec				\ 			= ((t2) ==&time ? tv_sec : (t2)->tv_sec);	\ 			(ip)->i_modrev++;				\ 		}							\ 		if ((ip)->i_flag& IN_CHANGE)				\ 			(ip)->i_ctime.ts_sec = tv_sec;			\ 		(ip)->i_flag&= ~(IN_ACCESS | IN_CHANGE | IN_UPDATE);	\ 	}								\ }
end_define

begin_comment
comment|/* This overlays the fid structure (see mount.h). */
end_comment

begin_struct
struct|struct
name|ufid
block|{
name|u_short
name|ufid_len
decl_stmt|;
comment|/* Length of structure. */
name|u_short
name|ufid_pad
decl_stmt|;
comment|/* Force long alignment. */
name|ino_t
name|ufid_ino
decl_stmt|;
comment|/* File number (ino). */
name|long
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
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_UFS_UFS_INODE_H_ */
end_comment

end_unit

