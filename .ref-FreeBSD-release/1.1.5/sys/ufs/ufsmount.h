begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)ufsmount.h	7.9 (Berkeley) 5/8/91  *	$Id: ufsmount.h,v 1.3 1993/11/07 17:53:47 wollman Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UFS_UFSMOUNT_H_
end_ifndef

begin_define
define|#
directive|define
name|_UFS_UFSMOUNT_H_
value|1
end_define

begin_comment
comment|/*  * This structure describes the UFS specific mount structure data.  */
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
comment|/* vfs structure for this filesystem */
name|dev_t
name|um_dev
decl_stmt|;
comment|/* device mounted */
name|struct
name|vnode
modifier|*
name|um_devvp
decl_stmt|;
comment|/* vnode for block device mounted */
name|struct
name|fs
modifier|*
name|um_fs
decl_stmt|;
comment|/* pointer to superblock */
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
comment|/* cred for access to quota file */
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
comment|/* quota specific flags, see below */
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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * Convert mount ptr to ufsmount ptr.  */
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
comment|/*  * Prototypes for UFS mount operations  */
end_comment

begin_decl_stmt
name|int
name|ufs_mount
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
name|mp
operator|,
name|char
operator|*
name|path
operator|,
name|caddr_t
name|data
operator|,
expr|struct
name|nameidata
operator|*
name|ndp
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ufs_start
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
name|mp
operator|,
name|int
name|flags
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ufs_unmount
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
name|mp
operator|,
name|int
name|mntflags
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ufs_root
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
name|mp
operator|,
expr|struct
name|vnode
operator|*
operator|*
name|vpp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ufs_quotactl
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
name|mp
operator|,
name|int
name|cmds
operator|,
name|int
name|uid
operator|,
comment|/* should be uid_t */
name|caddr_t
name|arg
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ufs_statfs
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
name|mp
operator|,
expr|struct
name|statfs
operator|*
name|sbp
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ufs_sync
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
name|mp
operator|,
name|int
name|waitfor
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ufs_fhtovp
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
name|mp
operator|,
expr|struct
name|fid
operator|*
name|fhp
operator|,
expr|struct
name|vnode
operator|*
operator|*
name|vpp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ufs_vptofh
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
expr|struct
name|fid
operator|*
name|fhp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ufs_init
name|__P
argument_list|(
operator|(
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
comment|/* _UFS_UFSMOUNT_H_ */
end_comment

end_unit

