begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ufsmount.h	8.6 (Berkeley) 3/30/95  * $Id: ufsmount.h,v 1.7 1997/02/22 09:47:54 peter Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UFS_UFS_UFSMOUNT_H_
end_ifndef

begin_define
define|#
directive|define
name|_UFS_UFS_UFSMOUNT_H_
end_define

begin_comment
comment|/*  * Arguments to mount UFS-based filesystems  */
end_comment

begin_struct
struct|struct
name|ufs_args
block|{
name|char
modifier|*
name|fspec
decl_stmt|;
comment|/* block special device to mount */
name|struct
name|export_args
name|export
decl_stmt|;
comment|/* network export information */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Arguments to mount MFS  */
end_comment

begin_struct
struct|struct
name|mfs_args
block|{
name|char
modifier|*
name|fspec
decl_stmt|;
comment|/* name to export for statfs */
name|struct
name|export_args
name|export
decl_stmt|;
comment|/* if exported MFSes are supported */
name|caddr_t
name|base
decl_stmt|;
comment|/* base of file system in memory */
name|u_long
name|size
decl_stmt|;
comment|/* size of file system */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|buf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|inode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|nameidata
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|timeval
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ucred
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|uio
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vnode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|netexport
struct_decl|;
end_struct_decl

begin_comment
comment|/* This structure describes the UFS specific mount structure data. */
end_comment

begin_struct
struct|struct
name|ufsmount
block|{
name|struct
name|mount
modifier|*
name|um_mountp
decl_stmt|;
comment|/* filesystem vfs structure */
name|dev_t
name|um_dev
decl_stmt|;
comment|/* device mounted */
name|struct
name|vnode
modifier|*
name|um_devvp
decl_stmt|;
comment|/* block device mounted vnode */
union|union
block|{
comment|/* pointer to superblock */
name|struct
name|lfs
modifier|*
name|lfs
decl_stmt|;
comment|/* LFS */
name|struct
name|fs
modifier|*
name|fs
decl_stmt|;
comment|/* FFS */
name|struct
name|ext2_sb_info
modifier|*
name|e2fs
decl_stmt|;
comment|/* EXT2FS */
block|}
name|ufsmount_u
union|;
define|#
directive|define
name|um_fs
value|ufsmount_u.fs
define|#
directive|define
name|um_lfs
value|ufsmount_u.lfs
define|#
directive|define
name|um_e2fs
value|ufsmount_u.e2fs
define|#
directive|define
name|um_e2fsb
value|ufsmount_u.e2fs->s_es
name|struct
name|vnode
modifier|*
name|um_quotas
index|[
name|MAXQUOTAS
index|]
decl_stmt|;
comment|/* pointer to quota files */
name|struct
name|ucred
modifier|*
name|um_cred
index|[
name|MAXQUOTAS
index|]
decl_stmt|;
comment|/* quota file access cred */
name|u_long
name|um_nindir
decl_stmt|;
comment|/* indirect ptrs per block */
name|u_long
name|um_bptrtodb
decl_stmt|;
comment|/* indir ptr to disk block */
name|u_long
name|um_seqinc
decl_stmt|;
comment|/* inc between seq blocks */
name|time_t
name|um_btime
index|[
name|MAXQUOTAS
index|]
decl_stmt|;
comment|/* block quota time limit */
name|time_t
name|um_itime
index|[
name|MAXQUOTAS
index|]
decl_stmt|;
comment|/* inode quota time limit */
name|char
name|um_qflags
index|[
name|MAXQUOTAS
index|]
decl_stmt|;
comment|/* quota specific flags */
name|struct
name|netexport
name|um_export
decl_stmt|;
comment|/* export information */
name|int64_t
name|um_savedmaxfilesize
decl_stmt|;
comment|/* XXX - limit maxfilesize */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flags describing the state of quotas.  */
end_comment

begin_define
define|#
directive|define
name|QTF_OPENING
value|0x01
end_define

begin_comment
comment|/* Q_QUOTAON in progress */
end_comment

begin_define
define|#
directive|define
name|QTF_CLOSING
value|0x02
end_define

begin_comment
comment|/* Q_QUOTAOFF in progress */
end_comment

begin_comment
comment|/* Convert mount ptr to ufsmount ptr. */
end_comment

begin_define
define|#
directive|define
name|VFSTOUFS
parameter_list|(
name|mp
parameter_list|)
value|((struct ufsmount *)((mp)->mnt_data))
end_define

begin_comment
comment|/*  * Macros to access file system parameters in the ufsmount structure.  * Used by ufs_bmap.  */
end_comment

begin_define
define|#
directive|define
name|MNINDIR
parameter_list|(
name|ump
parameter_list|)
value|((ump)->um_nindir)
end_define

begin_define
define|#
directive|define
name|blkptrtodb
parameter_list|(
name|ump
parameter_list|,
name|b
parameter_list|)
value|((b)<< (ump)->um_bptrtodb)
end_define

begin_define
define|#
directive|define
name|is_sequential
parameter_list|(
name|ump
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|)
value|((b) == (a) + ump->um_seqinc)
end_define

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

end_unit

