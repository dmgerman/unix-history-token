begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)fifo.h	7.3 (Berkeley) %G%  */
end_comment

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
name|dvp
operator|,
expr|struct
name|vnode
operator|*
operator|*
name|vpp
operator|,
expr|struct
name|componentname
operator|*
name|cnp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|fifo_create
value|((int (*) __P(( \ 		struct vnode *dvp, \  		struct vnode **vpp, \ 		struct componentname *cnp, \ 		struct vattr *vap))) fifo_badop)
end_define

begin_define
define|#
directive|define
name|fifo_mknod
value|((int (*) __P(( \ 		struct vnode *dvp, \ 		struct vnode **vpp, \ 		struct componentname *cnp, \ 		struct vattr *vap))) fifo_badop)
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
value|((int (*) __P(( \ 		struct vnode *dvp, \ 	        struct vnode *vp, \ 		struct componentname *cnp))) fifo_badop)
end_define

begin_define
define|#
directive|define
name|fifo_link
value|((int (*) __P(( \ 		register struct vnode *vp, \ 		struct vnode *tdvp, \ 		struct componentname *cnp))) fifo_badop)
end_define

begin_define
define|#
directive|define
name|fifo_rename
value|((int (*) __P(( \ 		struct vnode *fdvp, \ 	        struct vnode *fvp, \ 		struct componentname *fcnp, \ 		struct vnode *tdvp, \ 		struct vnode *tvp, \ 		struct componentname *tcnp))) fifo_badop)
end_define

begin_define
define|#
directive|define
name|fifo_mkdir
value|((int (*) __P(( \ 		struct vnode *dvp, \ 		struct vnode **vpp, \ 		struct componentname *cnp, \ 		struct vattr *vap))) fifo_badop)
end_define

begin_define
define|#
directive|define
name|fifo_rmdir
value|((int (*) __P(( \ 		struct vnode *dvp, \ 		struct vnode *vp, \ 		struct componentname *cnp))) fifo_badop)
end_define

begin_define
define|#
directive|define
name|fifo_symlink
value|((int (*) __P(( \ 		struct vnode *dvp, \ 		struct vnode **vpp, \ 		struct componentname *cnp, \ 		struct vattr *vap, \ 		char *target))) fifo_badop)
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
value|((int (*) __P(( \ 		struct vnode *dvp, \ 		struct componentname *cnp))) fifo_badop)
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
name|int
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

begin_define
define|#
directive|define
name|fifo_blkatoff
value|((int (*) __P(( \ 		struct vnode *vp, \ 		off_t offset, \ 		char **res, \ 		struct buf **bpp))) fifo_badop)
end_define

begin_define
define|#
directive|define
name|fifo_vget
value|((int (*) __P(( \ 		struct mount *mp, \ 		ino_t ino, \ 		struct vnode **vpp))) fifo_badop)
end_define

begin_define
define|#
directive|define
name|fifo_valloc
value|((int (*) __P(( \ 		struct vnode *pvp, \ 		int mode, \ 		struct ucred *cred, \ 		struct vnode **vpp))) fifo_badop)
end_define

begin_define
define|#
directive|define
name|fifo_vfree
value|((void (*) __P(( \ 		struct vnode *pvp, \ 		ino_t ino, \ 		int mode))) fifo_badop)
end_define

begin_define
define|#
directive|define
name|fifo_truncate
value|((int (*) __P(( \ 		struct vnode *vp, \ 		u_long length, \ 		int flags))) nullop)
end_define

begin_define
define|#
directive|define
name|fifo_update
value|((int (*) __P(( \ 		struct vnode *vp, \ 		struct timeval *ta, \ 		struct timeval *tm, \ 		int waitfor))) nullop)
end_define

begin_define
define|#
directive|define
name|fifo_bwrite
value|((int (*) __P(( \ 		struct buf *bp))) nullop)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FIFO */
end_comment

end_unit

