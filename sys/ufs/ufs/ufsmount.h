begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ufsmount.h	8.6 (Berkeley) 3/30/95  * $FreeBSD$  */
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
name|oexport_args
name|export
decl_stmt|;
comment|/* network export information */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_DECLARE
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_UFSMNT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

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
name|taskqueue
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
name|ufs_extattr_per_mount
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|jblocks
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|inodedep
struct_decl|;
end_struct_decl

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|inodedeplst
argument_list|,
name|inodedep
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|bmsafemaphd
argument_list|,
name|bmsafemap
argument_list|)
expr_stmt|;
end_expr_stmt

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
name|struct
name|cdev
modifier|*
name|um_dev
decl_stmt|;
comment|/* device mounted */
name|struct
name|g_consumer
modifier|*
name|um_cp
decl_stmt|;
name|struct
name|bufobj
modifier|*
name|um_bo
decl_stmt|;
comment|/* Buffer cache object */
name|struct
name|vnode
modifier|*
name|um_devvp
decl_stmt|;
comment|/* block device mounted vnode */
name|u_long
name|um_fstype
decl_stmt|;
comment|/* type of filesystem */
name|struct
name|fs
modifier|*
name|um_fs
decl_stmt|;
comment|/* pointer to superblock */
name|struct
name|ufs_extattr_per_mount
name|um_extattr
decl_stmt|;
comment|/* extended attrs */
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
name|struct
name|mtx
name|um_lock
decl_stmt|;
comment|/* Protects ufsmount& fs */
name|pid_t
name|um_fsckpid
decl_stmt|;
comment|/* PID permitted fsck sysctls */
name|struct
name|mount_softdeps
modifier|*
name|um_softdep
decl_stmt|;
comment|/* softdep mgmt structure */
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
name|int64_t
name|um_savedmaxfilesize
decl_stmt|;
comment|/* XXX - limit maxfilesize */
name|int
name|um_candelete
decl_stmt|;
comment|/* devvp supports TRIM */
name|int
name|um_writesuspended
decl_stmt|;
comment|/* suspension in progress */
name|u_int
name|um_trim_inflight
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|um_trim_tq
decl_stmt|;
name|int
function_decl|(
modifier|*
name|um_balloc
function_decl|)
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|off_t
parameter_list|,
name|int
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|buf
modifier|*
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|um_blkatoff
function_decl|)
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|off_t
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|struct
name|buf
modifier|*
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|um_truncate
function_decl|)
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|off_t
parameter_list|,
name|int
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|um_update
function_decl|)
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|um_valloc
function_decl|)
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|um_vfree
function_decl|)
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|ino_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|um_ifree
function_decl|)
parameter_list|(
name|struct
name|ufsmount
modifier|*
parameter_list|,
name|struct
name|inode
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|um_rdonly
function_decl|)
parameter_list|(
name|struct
name|inode
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|um_snapgone
function_decl|)
parameter_list|(
name|struct
name|inode
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UFS_BALLOC
parameter_list|(
name|aa
parameter_list|,
name|bb
parameter_list|,
name|cc
parameter_list|,
name|dd
parameter_list|,
name|ee
parameter_list|,
name|ff
parameter_list|)
value|VFSTOUFS((aa)->v_mount)->um_balloc(aa, bb, cc, dd, ee, ff)
end_define

begin_define
define|#
directive|define
name|UFS_BLKATOFF
parameter_list|(
name|aa
parameter_list|,
name|bb
parameter_list|,
name|cc
parameter_list|,
name|dd
parameter_list|)
value|VFSTOUFS((aa)->v_mount)->um_blkatoff(aa, bb, cc, dd)
end_define

begin_define
define|#
directive|define
name|UFS_TRUNCATE
parameter_list|(
name|aa
parameter_list|,
name|bb
parameter_list|,
name|cc
parameter_list|,
name|dd
parameter_list|)
value|VFSTOUFS((aa)->v_mount)->um_truncate(aa, bb, cc, dd)
end_define

begin_define
define|#
directive|define
name|UFS_UPDATE
parameter_list|(
name|aa
parameter_list|,
name|bb
parameter_list|)
value|VFSTOUFS((aa)->v_mount)->um_update(aa, bb)
end_define

begin_define
define|#
directive|define
name|UFS_VALLOC
parameter_list|(
name|aa
parameter_list|,
name|bb
parameter_list|,
name|cc
parameter_list|,
name|dd
parameter_list|)
value|VFSTOUFS((aa)->v_mount)->um_valloc(aa, bb, cc, dd)
end_define

begin_define
define|#
directive|define
name|UFS_VFREE
parameter_list|(
name|aa
parameter_list|,
name|bb
parameter_list|,
name|cc
parameter_list|)
value|VFSTOUFS((aa)->v_mount)->um_vfree(aa, bb, cc)
end_define

begin_define
define|#
directive|define
name|UFS_IFREE
parameter_list|(
name|aa
parameter_list|,
name|bb
parameter_list|)
value|((aa)->um_ifree(aa, bb))
end_define

begin_define
define|#
directive|define
name|UFS_RDONLY
parameter_list|(
name|aa
parameter_list|)
value|(ITOUMP(aa)->um_rdonly(aa))
end_define

begin_define
define|#
directive|define
name|UFS_SNAPGONE
parameter_list|(
name|aa
parameter_list|)
value|(ITOUMP(aa)->um_snapgone(aa))
end_define

begin_define
define|#
directive|define
name|UFS_LOCK
parameter_list|(
name|aa
parameter_list|)
value|mtx_lock(&(aa)->um_lock)
end_define

begin_define
define|#
directive|define
name|UFS_UNLOCK
parameter_list|(
name|aa
parameter_list|)
value|mtx_unlock(&(aa)->um_lock)
end_define

begin_define
define|#
directive|define
name|UFS_MTX
parameter_list|(
name|aa
parameter_list|)
value|(&(aa)->um_lock)
end_define

begin_comment
comment|/*  * Filesystem types  */
end_comment

begin_define
define|#
directive|define
name|UFS1
value|1
end_define

begin_define
define|#
directive|define
name|UFS2
value|2
end_define

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

begin_define
define|#
directive|define
name|QTF_64BIT
value|0x04
end_define

begin_comment
comment|/* 64-bit quota file */
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

begin_define
define|#
directive|define
name|UFSTOVFS
parameter_list|(
name|ump
parameter_list|)
value|(ump)->um_mountp
end_define

begin_comment
comment|/*  * Macros to access filesystem parameters in the ufsmount structure.  * Used by ufs_bmap.  */
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
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

