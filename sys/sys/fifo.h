begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)fifo.h	7.1 (Berkeley) 4/15/91  *	$Id: fifo.h,v 1.3 1993/11/07 17:52:34 wollman Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_FIFO_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_FIFO_H_
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|FIFO
end_ifdef

begin_comment
comment|/*  * Prototypes for fifo operations on vnodes.  */
end_comment

begin_decl_stmt
name|int
name|fifo_badop
argument_list|()
decl_stmt|,
name|fifo_ebadf
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fifo_lookup
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
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

begin_define
define|#
directive|define
name|fifo_create
value|((int (*) __P(( \ 		struct nameidata *ndp, \ 		struct vattr *vap, \ 		struct proc *p))) fifo_badop)
end_define

begin_define
define|#
directive|define
name|fifo_mknod
value|((int (*) __P(( \ 		struct nameidata *ndp, \ 		struct vattr *vap, \ 		struct ucred *cred, \ 		struct proc *p))) fifo_badop)
end_define

begin_decl_stmt
name|int
name|fifo_open
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
name|fifo_close
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
name|fifo_access
value|((int (*) __P(( \ 		struct vnode *vp, \ 		int mode, \ 		struct ucred *cred, \ 		struct proc *p))) fifo_ebadf)
end_define

begin_define
define|#
directive|define
name|fifo_getattr
value|((int (*) __P(( \ 		struct vnode *vp, \ 		struct vattr *vap, \ 		struct ucred *cred, \ 		struct proc *p))) fifo_ebadf)
end_define

begin_define
define|#
directive|define
name|fifo_setattr
value|((int (*) __P(( \ 		struct vnode *vp, \ 		struct vattr *vap, \ 		struct ucred *cred, \ 		struct proc *p))) fifo_ebadf)
end_define

begin_decl_stmt
name|int
name|fifo_read
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
expr|struct
name|uio
operator|*
name|uio
operator|,
name|int
name|ioflag
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fifo_write
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
expr|struct
name|uio
operator|*
name|uio
operator|,
name|int
name|ioflag
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fifo_ioctl
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

begin_decl_stmt
name|int
name|fifo_select
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|int
name|which
operator|,
name|int
name|fflags
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
name|fifo_mmap
value|((int (*) __P(( \ 		struct vnode *vp, \ 		int fflags, \ 		struct ucred *cred, \ 		struct proc *p))) fifo_badop)
end_define

begin_define
define|#
directive|define
name|fifo_fsync
value|((int (*) __P(( \ 		struct vnode *vp, \ 		int fflags, \ 		struct ucred *cred, \ 		int waitfor, \ 		struct proc *p))) nullop)
end_define

begin_define
define|#
directive|define
name|fifo_seek
value|((int (*) __P(( \ 		struct vnode *vp, \ 		off_t oldoff, \ 		off_t newoff, \ 		struct ucred *cred))) fifo_badop)
end_define

begin_define
define|#
directive|define
name|fifo_remove
value|((int (*) __P(( \ 		struct nameidata *ndp, \ 		struct proc *p))) fifo_badop)
end_define

begin_define
define|#
directive|define
name|fifo_link
value|((int (*) __P(( \ 		struct vnode *vp, \ 		struct nameidata *ndp, \ 		struct proc *p))) fifo_badop)
end_define

begin_define
define|#
directive|define
name|fifo_rename
value|((int (*) __P(( \ 		struct nameidata *fndp, \ 		struct nameidata *tdnp, \ 		struct proc *p))) fifo_badop)
end_define

begin_define
define|#
directive|define
name|fifo_mkdir
value|((int (*) __P(( \ 		struct nameidata *ndp, \ 		struct vattr *vap, \ 		struct proc *p))) fifo_badop)
end_define

begin_define
define|#
directive|define
name|fifo_rmdir
value|((int (*) __P(( \ 		struct nameidata *ndp, \ 		struct proc *p))) fifo_badop)
end_define

begin_define
define|#
directive|define
name|fifo_symlink
value|((int (*) __P(( \ 		struct nameidata *ndp, \ 		struct vattr *vap, \ 		char *target, \ 		struct proc *p))) fifo_badop)
end_define

begin_define
define|#
directive|define
name|fifo_readdir
value|((int (*) __P(( \ 		struct vnode *vp, \ 		struct uio *uio, \ 		struct ucred *cred, \ 		int *eofflagp))) fifo_badop)
end_define

begin_define
define|#
directive|define
name|fifo_readlink
value|((int (*) __P(( \ 		struct vnode *vp, \ 		struct uio *uio, \ 		struct ucred *cred))) fifo_badop)
end_define

begin_define
define|#
directive|define
name|fifo_abortop
value|((int (*) __P(( \ 		struct nameidata *ndp))) fifo_badop)
end_define

begin_define
define|#
directive|define
name|fifo_inactive
value|((int (*) __P(( \ 		struct vnode *vp, \ 		struct proc *p))) nullop)
end_define

begin_define
define|#
directive|define
name|fifo_reclaim
value|((int (*) __P(( \ 		struct vnode *vp))) nullop)
end_define

begin_decl_stmt
name|int
name|fifo_lock
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

begin_decl_stmt
name|int
name|fifo_unlock
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

begin_decl_stmt
name|int
name|fifo_bmap
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

begin_define
define|#
directive|define
name|fifo_strategy
value|((int (*) __P(( \ 		struct buf *bp))) fifo_badop)
end_define

begin_decl_stmt
name|void
name|fifo_print
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
name|fifo_islocked
value|((int (*) __P(( \ 		struct vnode *vp))) nullop)
end_define

begin_decl_stmt
name|int
name|fifo_advlock
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|caddr_t
name|id
operator|,
name|int
name|op
operator|,
expr|struct
name|flock
operator|*
name|fl
operator|,
name|int
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|fifo_printinfo
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FIFO */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_FIFO_H_ */
end_comment

end_unit

