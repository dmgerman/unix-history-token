begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)mfsnode.h	7.3 (Berkeley) 4/16/91  *	$Id: mfsnode.h,v 1.3 1993/11/07 17:53:42 wollman Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UFS_MFSNODE_H_
end_ifndef

begin_define
define|#
directive|define
name|_UFS_MFSNODE_H_
value|1
end_define

begin_comment
comment|/*  * This structure defines the control data for the memory  * based file system.  */
end_comment

begin_struct
struct|struct
name|mfsnode
block|{
name|struct
name|vnode
modifier|*
name|mfs_vnode
decl_stmt|;
comment|/* vnode associated with this mfsnode */
name|caddr_t
name|mfs_baseoff
decl_stmt|;
comment|/* base of file system in memory */
name|long
name|mfs_size
decl_stmt|;
comment|/* size of memory file system */
name|pid_t
name|mfs_pid
decl_stmt|;
comment|/* supporting process pid */
name|struct
name|buf
modifier|*
name|mfs_buflist
decl_stmt|;
comment|/* list of I/O requests */
name|long
name|mfs_spare
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Convert between mfsnode pointers and vnode pointers  */
end_comment

begin_define
define|#
directive|define
name|VTOMFS
parameter_list|(
name|vp
parameter_list|)
value|((struct mfsnode *)(vp)->v_data)
end_define

begin_define
define|#
directive|define
name|MFSTOV
parameter_list|(
name|mfsp
parameter_list|)
value|((mfsp)->mfs_vnode)
end_define

begin_comment
comment|/*  * Prototypes for MFS operations on vnodes.  */
end_comment

begin_function_decl
name|int
name|mfs_badop
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|mfs_lookup
value|((int (*) __P(( \ 		struct vnode *vp, \ 		struct nameidata *ndp, \ 		struct proc *p))) mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_create
value|((int (*) __P(( \ 		struct nameidata *ndp, \ 		struct vattr *vap, \ 		struct proc *p))) mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_mknod
value|((int (*) __P(( \ 		struct nameidata *ndp, \ 		struct vattr *vap, \ 		struct ucred *cred, \ 		struct proc *p))) mfs_badop)
end_define

begin_decl_stmt
name|int
name|mfs_open
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|int
name|mode
operator|,
expr|struct
name|ucred
operator|*
name|cred
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
name|mfs_close
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|int
name|fflag
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|mfs_access
value|((int (*) __P(( \ 		struct vnode *vp, \ 		int mode, \ 		struct ucred *cred, \ 		struct proc *p))) mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_getattr
value|((int (*) __P(( \ 		struct vnode *vp, \ 		struct vattr *vap, \ 		struct ucred *cred, \ 		struct proc *p))) mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_setattr
value|((int (*) __P(( \ 		struct vnode *vp, \ 		struct vattr *vap, \ 		struct ucred *cred, \ 		struct proc *p))) mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_read
value|((int (*) __P(( \ 		struct vnode *vp, \ 		struct uio *uio, \ 		int ioflag, \ 		struct ucred *cred))) mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_write
value|((int (*) __P(( \ 		struct vnode *vp, \ 		struct uio *uio, \ 		int ioflag, \ 		struct ucred *cred))) mfs_badop)
end_define

begin_decl_stmt
name|int
name|mfs_ioctl
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|int
name|command
operator|,
name|caddr_t
name|data
operator|,
name|int
name|fflag
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|mfs_select
value|((int (*) __P(( \ 		struct vnode *vp, \ 		int which, \ 		int fflags, \ 		struct ucred *cred, \ 		struct proc *p))) mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_mmap
value|((int (*) __P(( \ 		struct vnode *vp, \ 		int fflags, \ 		struct ucred *cred, \ 		struct proc *p))) mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_fsync
value|((int (*) __P(( \ 		struct vnode *vp, \ 		int fflags, \ 		struct ucred *cred, \ 		int waitfor, \ 		struct proc *p))) mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_seek
value|((int (*) __P(( \ 		struct vnode *vp, \ 		off_t oldoff, \ 		off_t newoff, \ 		struct ucred *cred))) mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_remove
value|((int (*) __P(( \ 		struct nameidata *ndp, \ 		struct proc *p))) mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_link
value|((int (*) __P(( \ 		struct vnode *vp, \ 		struct nameidata *ndp, \ 		struct proc *p))) mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_rename
value|((int (*) __P(( \ 		struct nameidata *fndp, \ 		struct nameidata *tdnp, \ 		struct proc *p))) mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_mkdir
value|((int (*) __P(( \ 		struct nameidata *ndp, \ 		struct vattr *vap, \ 		struct proc *p))) mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_rmdir
value|((int (*) __P(( \ 		struct nameidata *ndp, \ 		struct proc *p))) mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_symlink
value|((int (*) __P(( \ 		struct nameidata *ndp, \ 		struct vattr *vap, \ 		char *target, \ 		struct proc *p))) mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_readdir
value|((int (*) __P(( \ 		struct vnode *vp, \ 		struct uio *uio, \ 		struct ucred *cred, \ 		int *eofflagp))) mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_readlink
value|((int (*) __P(( \ 		struct vnode *vp, \ 		struct uio *uio, \ 		struct ucred *cred))) mfs_badop)
end_define

begin_define
define|#
directive|define
name|mfs_abortop
value|((int (*) __P(( \ 		struct nameidata *ndp))) mfs_badop)
end_define

begin_decl_stmt
name|int
name|mfs_inactive
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|mfs_reclaim
value|((int (*) __P(( \ 		struct vnode *vp))) nullop)
end_define

begin_define
define|#
directive|define
name|mfs_lock
value|((int (*) __P(( \ 		struct vnode *vp))) nullop)
end_define

begin_define
define|#
directive|define
name|mfs_unlock
value|((int (*) __P(( \ 		struct vnode *vp))) nullop)
end_define

begin_decl_stmt
name|int
name|mfs_bmap
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|daddr_t
name|bn
operator|,
expr|struct
name|vnode
operator|*
operator|*
name|vpp
operator|,
name|daddr_t
operator|*
name|bnp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mfs_strategy
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
name|bp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|mfs_print
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|mfs_islocked
value|((int (*) __P(( \ 		struct vnode *vp))) nullop)
end_define

begin_define
define|#
directive|define
name|mfs_advlock
value|((int (*) __P(( \ 		struct vnode *vp, \ 		caddr_t id, \ 		int op, \ 		struct flock *fl, \ 		int flags))) mfs_badop)
end_define

begin_function_decl
name|void
name|mfs_doio
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _UFS_MFSNODE_H_ */
end_comment

end_unit

