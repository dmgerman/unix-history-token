begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)dead_vnops.c	7.13 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"systm.h"
end_include

begin_include
include|#
directive|include
file|"time.h"
end_include

begin_include
include|#
directive|include
file|"vnode.h"
end_include

begin_include
include|#
directive|include
file|"errno.h"
end_include

begin_include
include|#
directive|include
file|"namei.h"
end_include

begin_include
include|#
directive|include
file|"buf.h"
end_include

begin_comment
comment|/*  * Prototypes for dead operations on vnodes.  */
end_comment

begin_decl_stmt
name|int
name|dead_badop
argument_list|()
decl_stmt|,
name|dead_ebadf
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dead_lookup
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
name|dead_create
value|((int (*) __P(( \ 		struct nameidata *ndp, \ 		struct vattr *vap, \ 		struct proc *p))) dead_badop)
end_define

begin_define
define|#
directive|define
name|dead_mknod
value|((int (*) __P(( \ 		struct nameidata *ndp, \ 		struct vattr *vap, \ 		struct ucred *cred, \ 		struct proc *p))) dead_badop)
end_define

begin_decl_stmt
name|int
name|dead_open
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

begin_define
define|#
directive|define
name|dead_close
value|((int (*) __P(( \ 		struct vnode *vp, \ 		int fflag, \ 		struct ucred *cred, \ 		struct proc *p))) nullop)
end_define

begin_define
define|#
directive|define
name|dead_access
value|((int (*) __P(( \ 		struct vnode *vp, \ 		int mode, \ 		struct ucred *cred, \ 		struct proc *p))) dead_ebadf)
end_define

begin_define
define|#
directive|define
name|dead_getattr
value|((int (*) __P(( \ 		struct vnode *vp, \ 		struct vattr *vap, \ 		struct ucred *cred, \ 		struct proc *p))) dead_ebadf)
end_define

begin_define
define|#
directive|define
name|dead_setattr
value|((int (*) __P(( \ 		struct vnode *vp, \ 		struct vattr *vap, \ 		struct ucred *cred, \ 		struct proc *p))) dead_ebadf)
end_define

begin_decl_stmt
name|int
name|dead_read
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
name|dead_write
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
name|dead_ioctl
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
name|dead_select
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
name|dead_mmap
value|((int (*) __P(( \ 		struct vnode *vp, \ 		int fflags, \ 		struct ucred *cred, \ 		struct proc *p))) dead_badop)
end_define

begin_define
define|#
directive|define
name|dead_fsync
value|((int (*) __P(( \ 		struct vnode *vp, \ 		int fflags, \ 		struct ucred *cred, \ 		int waitfor, \ 		struct proc *p))) nullop)
end_define

begin_define
define|#
directive|define
name|dead_seek
value|((int (*) __P(( \ 		struct vnode *vp, \ 		off_t oldoff, \ 		off_t newoff, \ 		struct ucred *cred))) nullop)
end_define

begin_define
define|#
directive|define
name|dead_remove
value|((int (*) __P(( \ 		struct nameidata *ndp, \ 		struct proc *p))) dead_badop)
end_define

begin_define
define|#
directive|define
name|dead_link
value|((int (*) __P(( \ 		struct vnode *vp, \ 		struct nameidata *ndp, \ 		struct proc *p))) dead_badop)
end_define

begin_define
define|#
directive|define
name|dead_rename
value|((int (*) __P(( \ 		struct nameidata *fndp, \ 		struct nameidata *tdnp, \ 		struct proc *p))) dead_badop)
end_define

begin_define
define|#
directive|define
name|dead_mkdir
value|((int (*) __P(( \ 		struct nameidata *ndp, \ 		struct vattr *vap, \ 		struct proc *p))) dead_badop)
end_define

begin_define
define|#
directive|define
name|dead_rmdir
value|((int (*) __P(( \ 		struct nameidata *ndp, \ 		struct proc *p))) dead_badop)
end_define

begin_define
define|#
directive|define
name|dead_symlink
value|((int (*) __P(( \ 		struct nameidata *ndp, \ 		struct vattr *vap, \ 		char *target, \ 		struct proc *p))) dead_badop)
end_define

begin_define
define|#
directive|define
name|dead_readdir
value|((int (*) __P(( \ 		struct vnode *vp, \ 		struct uio *uio, \ 		struct ucred *cred, \ 		int *eofflagp))) dead_ebadf)
end_define

begin_define
define|#
directive|define
name|dead_readlink
value|((int (*) __P(( \ 		struct vnode *vp, \ 		struct uio *uio, \ 		struct ucred *cred))) dead_ebadf)
end_define

begin_define
define|#
directive|define
name|dead_abortop
value|((int (*) __P(( \ 		struct nameidata *ndp))) dead_badop)
end_define

begin_define
define|#
directive|define
name|dead_inactive
value|((int (*) __P(( \ 		struct vnode *vp, \ 		struct proc *p))) nullop)
end_define

begin_define
define|#
directive|define
name|dead_reclaim
value|((int (*) __P(( \ 		struct vnode *vp))) nullop)
end_define

begin_decl_stmt
name|int
name|dead_lock
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
name|dead_unlock
value|((int (*) __P(( \ 		struct vnode *vp))) nullop)
end_define

begin_decl_stmt
name|int
name|dead_bmap
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
name|dead_strategy
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
name|int
name|dead_print
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
name|dead_islocked
value|((int (*) __P(( \ 		struct vnode *vp))) nullop)
end_define

begin_define
define|#
directive|define
name|dead_advlock
value|((int (*) __P(( \ 		struct vnode *vp, \ 		caddr_t id, \ 		int op, \ 		struct flock *fl, \ 		int flags))) dead_ebadf)
end_define

begin_decl_stmt
name|struct
name|vnodeops
name|dead_vnodeops
init|=
block|{
name|dead_lookup
block|,
comment|/* lookup */
name|dead_create
block|,
comment|/* create */
name|dead_mknod
block|,
comment|/* mknod */
name|dead_open
block|,
comment|/* open */
name|dead_close
block|,
comment|/* close */
name|dead_access
block|,
comment|/* access */
name|dead_getattr
block|,
comment|/* getattr */
name|dead_setattr
block|,
comment|/* setattr */
name|dead_read
block|,
comment|/* read */
name|dead_write
block|,
comment|/* write */
name|dead_ioctl
block|,
comment|/* ioctl */
name|dead_select
block|,
comment|/* select */
name|dead_mmap
block|,
comment|/* mmap */
name|dead_fsync
block|,
comment|/* fsync */
name|dead_seek
block|,
comment|/* seek */
name|dead_remove
block|,
comment|/* remove */
name|dead_link
block|,
comment|/* link */
name|dead_rename
block|,
comment|/* rename */
name|dead_mkdir
block|,
comment|/* mkdir */
name|dead_rmdir
block|,
comment|/* rmdir */
name|dead_symlink
block|,
comment|/* symlink */
name|dead_readdir
block|,
comment|/* readdir */
name|dead_readlink
block|,
comment|/* readlink */
name|dead_abortop
block|,
comment|/* abortop */
name|dead_inactive
block|,
comment|/* inactive */
name|dead_reclaim
block|,
comment|/* reclaim */
name|dead_lock
block|,
comment|/* lock */
name|dead_unlock
block|,
comment|/* unlock */
name|dead_bmap
block|,
comment|/* bmap */
name|dead_strategy
block|,
comment|/* strategy */
name|dead_print
block|,
comment|/* print */
name|dead_islocked
block|,
comment|/* islocked */
name|dead_advlock
block|,
comment|/* advlock */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Trivial lookup routine that always fails.  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|dead_lookup
argument_list|(
argument|vp
argument_list|,
argument|ndp
argument_list|,
argument|p
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|vnode
modifier|*
name|vp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|nameidata
modifier|*
name|ndp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|ndp
operator|->
name|ni_dvp
operator|=
name|vp
expr_stmt|;
name|ndp
operator|->
name|ni_vp
operator|=
name|NULL
expr_stmt|;
return|return
operator|(
name|ENOTDIR
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Open always fails as if device did not exist.  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|dead_open
argument_list|(
argument|vp
argument_list|,
argument|mode
argument_list|,
argument|cred
argument_list|,
argument|p
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|vnode
modifier|*
name|vp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ucred
modifier|*
name|cred
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Vnode op for read  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|dead_read
argument_list|(
argument|vp
argument_list|,
argument|uio
argument_list|,
argument|ioflag
argument_list|,
argument|cred
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|vnode
modifier|*
name|vp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|uio
modifier|*
name|uio
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ioflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ucred
modifier|*
name|cred
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|chkvnlock
argument_list|(
name|vp
argument_list|)
condition|)
name|panic
argument_list|(
literal|"dead_read: lock"
argument_list|)
expr_stmt|;
comment|/* 	 * Return EOF for character devices, EIO for others 	 */
if|if
condition|(
name|vp
operator|->
name|v_type
operator|!=
name|VCHR
condition|)
return|return
operator|(
name|EIO
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Vnode op for write  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_expr_stmt
name|dead_write
argument_list|(
name|vp
argument_list|,
name|uio
argument_list|,
name|ioflag
argument_list|,
name|cred
argument_list|)
specifier|register
expr|struct
name|vnode
operator|*
name|vp
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|struct
name|uio
modifier|*
name|uio
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ioflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ucred
modifier|*
name|cred
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|chkvnlock
argument_list|(
name|vp
argument_list|)
condition|)
name|panic
argument_list|(
literal|"dead_write: lock"
argument_list|)
expr_stmt|;
return|return
operator|(
name|EIO
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Device ioctl operation.  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|dead_ioctl
argument_list|(
argument|vp
argument_list|,
argument|com
argument_list|,
argument|data
argument_list|,
argument|fflag
argument_list|,
argument|cred
argument_list|,
argument|p
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|vnode
modifier|*
name|vp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|int
name|com
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|caddr_t
name|data
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ucred
modifier|*
name|cred
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
operator|!
name|chkvnlock
argument_list|(
name|vp
argument_list|)
condition|)
return|return
operator|(
name|EBADF
operator|)
return|;
return|return
operator|(
name|VOP_IOCTL
argument_list|(
name|vp
argument_list|,
name|com
argument_list|,
name|data
argument_list|,
name|fflag
argument_list|,
name|cred
argument_list|,
name|p
argument_list|)
operator|)
return|;
block|}
end_block

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|dead_select
argument_list|(
argument|vp
argument_list|,
argument|which
argument_list|,
argument|fflags
argument_list|,
argument|cred
argument_list|,
argument|p
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|vnode
modifier|*
name|vp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|which
decl_stmt|,
name|fflags
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ucred
modifier|*
name|cred
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* 	 * Let the user find out that the descriptor is gone. 	 */
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Just call the device strategy routine  */
end_comment

begin_expr_stmt
name|dead_strategy
argument_list|(
name|bp
argument_list|)
specifier|register
expr|struct
name|buf
operator|*
name|bp
expr_stmt|;
end_expr_stmt

begin_block
block|{
if|if
condition|(
name|bp
operator|->
name|b_vp
operator|==
name|NULL
operator|||
operator|!
name|chkvnlock
argument_list|(
name|bp
operator|->
name|b_vp
argument_list|)
condition|)
block|{
name|bp
operator|->
name|b_flags
operator||=
name|B_ERROR
expr_stmt|;
name|biodone
argument_list|(
name|bp
argument_list|)
expr_stmt|;
return|return
operator|(
name|EIO
operator|)
return|;
block|}
return|return
operator|(
name|VOP_STRATEGY
argument_list|(
name|bp
argument_list|)
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Wait until the vnode has finished changing state.  */
end_comment

begin_macro
name|dead_lock
argument_list|(
argument|vp
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|vnode
modifier|*
name|vp
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
operator|!
name|chkvnlock
argument_list|(
name|vp
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
return|return
operator|(
name|VOP_LOCK
argument_list|(
name|vp
argument_list|)
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Wait until the vnode has finished changing state.  */
end_comment

begin_macro
name|dead_bmap
argument_list|(
argument|vp
argument_list|,
argument|bn
argument_list|,
argument|vpp
argument_list|,
argument|bnp
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|vnode
modifier|*
name|vp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|daddr_t
name|bn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|vnode
modifier|*
modifier|*
name|vpp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|daddr_t
modifier|*
name|bnp
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
operator|!
name|chkvnlock
argument_list|(
name|vp
argument_list|)
condition|)
return|return
operator|(
name|EIO
operator|)
return|;
return|return
operator|(
name|VOP_BMAP
argument_list|(
name|vp
argument_list|,
name|bn
argument_list|,
name|vpp
argument_list|,
name|bnp
argument_list|)
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Print out the contents of a dead vnode.  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|dead_print
argument_list|(
argument|vp
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|vnode
modifier|*
name|vp
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"tag VT_NON, dead vnode\n"
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Empty vnode failed operation  */
end_comment

begin_macro
name|dead_ebadf
argument_list|()
end_macro

begin_block
block|{
return|return
operator|(
name|EBADF
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Empty vnode bad operation  */
end_comment

begin_macro
name|dead_badop
argument_list|()
end_macro

begin_block
block|{
name|panic
argument_list|(
literal|"dead_badop called"
argument_list|)
expr_stmt|;
comment|/* NOTREACHED */
block|}
end_block

begin_comment
comment|/*  * Empty vnode null operation  */
end_comment

begin_macro
name|dead_nullop
argument_list|()
end_macro

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * We have to wait during times when the vnode is  * in a state of change.  */
end_comment

begin_expr_stmt
name|chkvnlock
argument_list|(
name|vp
argument_list|)
specifier|register
expr|struct
name|vnode
operator|*
name|vp
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|int
name|locked
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|vp
operator|->
name|v_flag
operator|&
name|VXLOCK
condition|)
block|{
name|vp
operator|->
name|v_flag
operator||=
name|VXWANT
expr_stmt|;
name|sleep
argument_list|(
operator|(
name|caddr_t
operator|)
name|vp
argument_list|,
name|PINOD
argument_list|)
expr_stmt|;
name|locked
operator|=
literal|1
expr_stmt|;
block|}
return|return
operator|(
name|locked
operator|)
return|;
block|}
end_block

end_unit

