begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)dead_vnops.c	8.1 (Berkeley) 6/10/93  * $Id: dead_vnops.c,v 1.15 1997/09/14 02:57:46 peter Exp $  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_decl_stmt
specifier|static
name|int
name|chkvnlock
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Prototypes for dead operations on vnodes.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|dead_badop
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|dead_ebadf
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|dead_lookup
name|__P
argument_list|(
operator|(
expr|struct
name|vop_lookup_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|dead_create
value|((int (*) __P((struct  vop_create_args *)))dead_badop)
end_define

begin_define
define|#
directive|define
name|dead_mknod
value|((int (*) __P((struct  vop_mknod_args *)))dead_badop)
end_define

begin_decl_stmt
specifier|static
name|int
name|dead_open
name|__P
argument_list|(
operator|(
expr|struct
name|vop_open_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|dead_close
value|((int (*) __P((struct  vop_close_args *)))nullop)
end_define

begin_define
define|#
directive|define
name|dead_access
value|((int (*) __P((struct  vop_access_args *)))dead_ebadf)
end_define

begin_define
define|#
directive|define
name|dead_getattr
value|((int (*) __P((struct  vop_getattr_args *)))dead_ebadf)
end_define

begin_define
define|#
directive|define
name|dead_setattr
value|((int (*) __P((struct  vop_setattr_args *)))dead_ebadf)
end_define

begin_decl_stmt
specifier|static
name|int
name|dead_read
name|__P
argument_list|(
operator|(
expr|struct
name|vop_read_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|dead_write
name|__P
argument_list|(
operator|(
expr|struct
name|vop_write_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|dead_ioctl
name|__P
argument_list|(
operator|(
expr|struct
name|vop_ioctl_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|dead_poll
value|vop_nopoll
end_define

begin_define
define|#
directive|define
name|dead_mmap
value|((int (*) __P((struct  vop_mmap_args *)))dead_badop)
end_define

begin_define
define|#
directive|define
name|dead_fsync
value|((int (*) __P((struct  vop_fsync_args *)))nullop)
end_define

begin_define
define|#
directive|define
name|dead_seek
value|((int (*) __P((struct  vop_seek_args *)))nullop)
end_define

begin_define
define|#
directive|define
name|dead_remove
value|((int (*) __P((struct  vop_remove_args *)))dead_badop)
end_define

begin_define
define|#
directive|define
name|dead_link
value|((int (*) __P((struct  vop_link_args *)))dead_badop)
end_define

begin_define
define|#
directive|define
name|dead_rename
value|((int (*) __P((struct  vop_rename_args *)))dead_badop)
end_define

begin_define
define|#
directive|define
name|dead_mkdir
value|((int (*) __P((struct  vop_mkdir_args *)))dead_badop)
end_define

begin_define
define|#
directive|define
name|dead_rmdir
value|((int (*) __P((struct  vop_rmdir_args *)))dead_badop)
end_define

begin_define
define|#
directive|define
name|dead_symlink
value|((int (*) __P((struct  vop_symlink_args *)))dead_badop)
end_define

begin_define
define|#
directive|define
name|dead_readdir
value|((int (*) __P((struct  vop_readdir_args *)))dead_ebadf)
end_define

begin_define
define|#
directive|define
name|dead_readlink
value|((int (*) __P((struct  vop_readlink_args *)))dead_ebadf)
end_define

begin_define
define|#
directive|define
name|dead_abortop
value|((int (*) __P((struct  vop_abortop_args *)))dead_badop)
end_define

begin_define
define|#
directive|define
name|dead_inactive
value|((int (*) __P((struct  vop_inactive_args *)))nullop)
end_define

begin_define
define|#
directive|define
name|dead_reclaim
value|((int (*) __P((struct  vop_reclaim_args *)))nullop)
end_define

begin_decl_stmt
specifier|static
name|int
name|dead_lock
name|__P
argument_list|(
operator|(
expr|struct
name|vop_lock_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|dead_unlock
value|((int (*) __P((struct vop_unlock_args *)))vop_nounlock)
end_define

begin_decl_stmt
specifier|static
name|int
name|dead_bmap
name|__P
argument_list|(
operator|(
expr|struct
name|vop_bmap_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|dead_strategy
name|__P
argument_list|(
operator|(
expr|struct
name|vop_strategy_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|dead_print
name|__P
argument_list|(
operator|(
expr|struct
name|vop_print_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|dead_islocked
value|((int(*) __P((struct vop_islocked_args *)))vop_noislocked)
end_define

begin_define
define|#
directive|define
name|dead_pathconf
value|((int (*) __P((struct  vop_pathconf_args *)))dead_ebadf)
end_define

begin_define
define|#
directive|define
name|dead_advlock
value|((int (*) __P((struct  vop_advlock_args *)))dead_ebadf)
end_define

begin_define
define|#
directive|define
name|dead_blkatoff
value|((int (*) __P((struct  vop_blkatoff_args *)))dead_badop)
end_define

begin_define
define|#
directive|define
name|dead_valloc
value|((int (*) __P((struct  vop_valloc_args *)))dead_badop)
end_define

begin_define
define|#
directive|define
name|dead_vfree
value|((int (*) __P((struct  vop_vfree_args *)))dead_badop)
end_define

begin_define
define|#
directive|define
name|dead_truncate
value|((int (*) __P((struct  vop_truncate_args *)))nullop)
end_define

begin_define
define|#
directive|define
name|dead_update
value|((int (*) __P((struct  vop_update_args *)))nullop)
end_define

begin_define
define|#
directive|define
name|dead_bwrite
value|((int (*) __P((struct  vop_bwrite_args *)))nullop)
end_define

begin_decl_stmt
name|vop_t
modifier|*
modifier|*
name|dead_vnodeop_p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|vnodeopv_entry_desc
name|dead_vnodeop_entries
index|[]
init|=
block|{
block|{
operator|&
name|vop_default_desc
block|,
operator|(
name|vop_t
operator|*
operator|)
name|vn_default_error
block|}
block|,
block|{
operator|&
name|vop_abortop_desc
block|,
operator|(
name|vop_t
operator|*
operator|)
name|dead_abortop
block|}
block|,
block|{
operator|&
name|vop_access_desc
block|,
operator|(
name|vop_t
operator|*
operator|)
name|dead_access
block|}
block|,
block|{
operator|&
name|vop_advlock_desc
block|,
operator|(
name|vop_t
operator|*
operator|)
name|dead_advlock
block|}
block|,
block|{
operator|&
name|vop_blkatoff_desc
block|,
operator|(
name|vop_t
operator|*
operator|)
name|dead_blkatoff
block|}
block|,
block|{
operator|&
name|vop_bmap_desc
block|,
operator|(
name|vop_t
operator|*
operator|)
name|dead_bmap
block|}
block|,
block|{
operator|&
name|vop_bwrite_desc
block|,
operator|(
name|vop_t
operator|*
operator|)
name|dead_bwrite
block|}
block|,
block|{
operator|&
name|vop_close_desc
block|,
operator|(
name|vop_t
operator|*
operator|)
name|dead_close
block|}
block|,
block|{
operator|&
name|vop_create_desc
block|,
operator|(
name|vop_t
operator|*
operator|)
name|dead_create
block|}
block|,
block|{
operator|&
name|vop_fsync_desc
block|,
operator|(
name|vop_t
operator|*
operator|)
name|dead_fsync
block|}
block|,
block|{
operator|&
name|vop_getattr_desc
block|,
operator|(
name|vop_t
operator|*
operator|)
name|dead_getattr
block|}
block|,
block|{
operator|&
name|vop_inactive_desc
block|,
operator|(
name|vop_t
operator|*
operator|)
name|dead_inactive
block|}
block|,
block|{
operator|&
name|vop_ioctl_desc
block|,
operator|(
name|vop_t
operator|*
operator|)
name|dead_ioctl
block|}
block|,
block|{
operator|&
name|vop_islocked_desc
block|,
operator|(
name|vop_t
operator|*
operator|)
name|dead_islocked
block|}
block|,
block|{
operator|&
name|vop_link_desc
block|,
operator|(
name|vop_t
operator|*
operator|)
name|dead_link
block|}
block|,
block|{
operator|&
name|vop_lock_desc
block|,
operator|(
name|vop_t
operator|*
operator|)
name|dead_lock
block|}
block|,
block|{
operator|&
name|vop_lookup_desc
block|,
operator|(
name|vop_t
operator|*
operator|)
name|dead_lookup
block|}
block|,
block|{
operator|&
name|vop_mkdir_desc
block|,
operator|(
name|vop_t
operator|*
operator|)
name|dead_mkdir
block|}
block|,
block|{
operator|&
name|vop_mknod_desc
block|,
operator|(
name|vop_t
operator|*
operator|)
name|dead_mknod
block|}
block|,
block|{
operator|&
name|vop_mmap_desc
block|,
operator|(
name|vop_t
operator|*
operator|)
name|dead_mmap
block|}
block|,
block|{
operator|&
name|vop_open_desc
block|,
operator|(
name|vop_t
operator|*
operator|)
name|dead_open
block|}
block|,
block|{
operator|&
name|vop_pathconf_desc
block|,
operator|(
name|vop_t
operator|*
operator|)
name|dead_pathconf
block|}
block|,
block|{
operator|&
name|vop_poll_desc
block|,
operator|(
name|vop_t
operator|*
operator|)
name|dead_poll
block|}
block|,
block|{
operator|&
name|vop_print_desc
block|,
operator|(
name|vop_t
operator|*
operator|)
name|dead_print
block|}
block|,
block|{
operator|&
name|vop_read_desc
block|,
operator|(
name|vop_t
operator|*
operator|)
name|dead_read
block|}
block|,
block|{
operator|&
name|vop_readdir_desc
block|,
operator|(
name|vop_t
operator|*
operator|)
name|dead_readdir
block|}
block|,
block|{
operator|&
name|vop_readlink_desc
block|,
operator|(
name|vop_t
operator|*
operator|)
name|dead_readlink
block|}
block|,
block|{
operator|&
name|vop_reclaim_desc
block|,
operator|(
name|vop_t
operator|*
operator|)
name|dead_reclaim
block|}
block|,
block|{
operator|&
name|vop_remove_desc
block|,
operator|(
name|vop_t
operator|*
operator|)
name|dead_remove
block|}
block|,
block|{
operator|&
name|vop_rename_desc
block|,
operator|(
name|vop_t
operator|*
operator|)
name|dead_rename
block|}
block|,
block|{
operator|&
name|vop_rmdir_desc
block|,
operator|(
name|vop_t
operator|*
operator|)
name|dead_rmdir
block|}
block|,
block|{
operator|&
name|vop_seek_desc
block|,
operator|(
name|vop_t
operator|*
operator|)
name|dead_seek
block|}
block|,
block|{
operator|&
name|vop_setattr_desc
block|,
operator|(
name|vop_t
operator|*
operator|)
name|dead_setattr
block|}
block|,
block|{
operator|&
name|vop_strategy_desc
block|,
operator|(
name|vop_t
operator|*
operator|)
name|dead_strategy
block|}
block|,
block|{
operator|&
name|vop_symlink_desc
block|,
operator|(
name|vop_t
operator|*
operator|)
name|dead_symlink
block|}
block|,
block|{
operator|&
name|vop_truncate_desc
block|,
operator|(
name|vop_t
operator|*
operator|)
name|dead_truncate
block|}
block|,
block|{
operator|&
name|vop_unlock_desc
block|,
operator|(
name|vop_t
operator|*
operator|)
name|dead_unlock
block|}
block|,
block|{
operator|&
name|vop_update_desc
block|,
operator|(
name|vop_t
operator|*
operator|)
name|dead_update
block|}
block|,
block|{
operator|&
name|vop_valloc_desc
block|,
operator|(
name|vop_t
operator|*
operator|)
name|dead_valloc
block|}
block|,
block|{
operator|&
name|vop_vfree_desc
block|,
operator|(
name|vop_t
operator|*
operator|)
name|dead_vfree
block|}
block|,
block|{
operator|&
name|vop_write_desc
block|,
operator|(
name|vop_t
operator|*
operator|)
name|dead_write
block|}
block|,
block|{
name|NULL
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|vnodeopv_desc
name|dead_vnodeop_opv_desc
init|=
block|{
operator|&
name|dead_vnodeop_p
block|,
name|dead_vnodeop_entries
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|VNODEOP_SET
argument_list|(
name|dead_vnodeop_opv_desc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Trivial lookup routine that always fails.  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
specifier|static
name|int
name|dead_lookup
parameter_list|(
name|ap
parameter_list|)
name|struct
name|vop_lookup_args
comment|/* { 		struct vnode * a_dvp; 		struct vnode ** a_vpp; 		struct componentname * a_cnp; 	} */
modifier|*
name|ap
decl_stmt|;
block|{
operator|*
name|ap
operator|->
name|a_vpp
operator|=
name|NULL
expr_stmt|;
return|return
operator|(
name|ENOTDIR
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Open always fails as if device did not exist.  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
specifier|static
name|int
name|dead_open
parameter_list|(
name|ap
parameter_list|)
name|struct
name|vop_open_args
comment|/* { 		struct vnode *a_vp; 		int  a_mode; 		struct ucred *a_cred; 		struct proc *a_p; 	} */
modifier|*
name|ap
decl_stmt|;
block|{
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Vnode op for read  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
specifier|static
name|int
name|dead_read
parameter_list|(
name|ap
parameter_list|)
name|struct
name|vop_read_args
comment|/* { 		struct vnode *a_vp; 		struct uio *a_uio; 		int  a_ioflag; 		struct ucred *a_cred; 	} */
modifier|*
name|ap
decl_stmt|;
block|{
if|if
condition|(
name|chkvnlock
argument_list|(
name|ap
operator|->
name|a_vp
argument_list|)
condition|)
name|panic
argument_list|(
literal|"dead_read: lock"
argument_list|)
expr_stmt|;
if|#
directive|if
literal|0
comment|/* Lite2 behaviour */
comment|/* 	 * Return EOF for tty devices, EIO for others 	 */
block|if ((ap->a_vp->v_flag& VISTTY) == 0) 		return (EIO);
else|#
directive|else
comment|/* 	 * Return EOF for character devices, EIO for others 	 */
if|if
condition|(
name|ap
operator|->
name|a_vp
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
endif|#
directive|endif
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Vnode op for write  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
specifier|static
name|int
name|dead_write
parameter_list|(
name|ap
parameter_list|)
name|struct
name|vop_write_args
comment|/* { 		struct vnode *a_vp; 		struct uio *a_uio; 		int  a_ioflag; 		struct ucred *a_cred; 	} */
modifier|*
name|ap
decl_stmt|;
block|{
if|if
condition|(
name|chkvnlock
argument_list|(
name|ap
operator|->
name|a_vp
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
end_function

begin_comment
comment|/*  * Device ioctl operation.  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
specifier|static
name|int
name|dead_ioctl
parameter_list|(
name|ap
parameter_list|)
name|struct
name|vop_ioctl_args
comment|/* { 		struct vnode *a_vp; 		int  a_command; 		caddr_t  a_data; 		int  a_fflag; 		struct ucred *a_cred; 		struct proc *a_p; 	} */
modifier|*
name|ap
decl_stmt|;
block|{
if|if
condition|(
operator|!
name|chkvnlock
argument_list|(
name|ap
operator|->
name|a_vp
argument_list|)
condition|)
return|return
operator|(
name|EBADF
operator|)
return|;
return|return
operator|(
name|VCALL
argument_list|(
name|ap
operator|->
name|a_vp
argument_list|,
name|VOFFSET
argument_list|(
name|vop_ioctl
argument_list|)
argument_list|,
name|ap
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Just call the device strategy routine  */
end_comment

begin_function
specifier|static
name|int
name|dead_strategy
parameter_list|(
name|ap
parameter_list|)
name|struct
name|vop_strategy_args
comment|/* { 		struct buf *a_bp; 	} */
modifier|*
name|ap
decl_stmt|;
block|{
if|if
condition|(
name|ap
operator|->
name|a_bp
operator|->
name|b_vp
operator|==
name|NULL
operator|||
operator|!
name|chkvnlock
argument_list|(
name|ap
operator|->
name|a_bp
operator|->
name|b_vp
argument_list|)
condition|)
block|{
name|ap
operator|->
name|a_bp
operator|->
name|b_flags
operator||=
name|B_ERROR
expr_stmt|;
name|biodone
argument_list|(
name|ap
operator|->
name|a_bp
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
name|ap
operator|->
name|a_bp
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Wait until the vnode has finished changing state.  */
end_comment

begin_function
specifier|static
name|int
name|dead_lock
parameter_list|(
name|ap
parameter_list|)
name|struct
name|vop_lock_args
comment|/* { 		struct vnode *a_vp; 		int a_flags; 		struct proc *a_p; 	} */
modifier|*
name|ap
decl_stmt|;
block|{
name|struct
name|vnode
modifier|*
name|vp
init|=
name|ap
operator|->
name|a_vp
decl_stmt|;
comment|/* 	 * Since we are not using the lock manager, we must clear 	 * the interlock here. 	 */
if|if
condition|(
name|ap
operator|->
name|a_flags
operator|&
name|LK_INTERLOCK
condition|)
block|{
name|simple_unlock
argument_list|(
operator|&
name|vp
operator|->
name|v_interlock
argument_list|)
expr_stmt|;
name|ap
operator|->
name|a_flags
operator|&=
operator|~
name|LK_INTERLOCK
expr_stmt|;
block|}
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
name|VCALL
argument_list|(
name|vp
argument_list|,
name|VOFFSET
argument_list|(
name|vop_lock
argument_list|)
argument_list|,
name|ap
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Wait until the vnode has finished changing state.  */
end_comment

begin_function
specifier|static
name|int
name|dead_bmap
parameter_list|(
name|ap
parameter_list|)
name|struct
name|vop_bmap_args
comment|/* { 		struct vnode *a_vp; 		daddr_t  a_bn; 		struct vnode **a_vpp; 		daddr_t *a_bnp; 		int *a_runp; 		int *a_runb; 	} */
modifier|*
name|ap
decl_stmt|;
block|{
if|if
condition|(
operator|!
name|chkvnlock
argument_list|(
name|ap
operator|->
name|a_vp
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
name|ap
operator|->
name|a_vp
argument_list|,
name|ap
operator|->
name|a_bn
argument_list|,
name|ap
operator|->
name|a_vpp
argument_list|,
name|ap
operator|->
name|a_bnp
argument_list|,
name|ap
operator|->
name|a_runp
argument_list|,
name|ap
operator|->
name|a_runb
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Print out the contents of a dead vnode.  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
specifier|static
name|int
name|dead_print
parameter_list|(
name|ap
parameter_list|)
name|struct
name|vop_print_args
comment|/* { 		struct vnode *a_vp; 	} */
modifier|*
name|ap
decl_stmt|;
block|{
name|printf
argument_list|(
literal|"tag VT_NON, dead vnode\n"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Empty vnode failed operation  */
end_comment

begin_function
specifier|static
name|int
name|dead_ebadf
parameter_list|()
block|{
return|return
operator|(
name|EBADF
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Empty vnode bad operation  */
end_comment

begin_function
specifier|static
name|int
name|dead_badop
parameter_list|()
block|{
name|panic
argument_list|(
literal|"dead_badop called"
argument_list|)
expr_stmt|;
comment|/* NOTREACHED */
block|}
end_function

begin_comment
comment|/*  * We have to wait during times when the vnode is  * in a state of change.  */
end_comment

begin_function
name|int
name|chkvnlock
parameter_list|(
name|vp
parameter_list|)
specifier|register
name|struct
name|vnode
modifier|*
name|vp
decl_stmt|;
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
operator|(
name|void
operator|)
name|tsleep
argument_list|(
operator|(
name|caddr_t
operator|)
name|vp
argument_list|,
name|PINOD
argument_list|,
literal|"ckvnlk"
argument_list|,
literal|0
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
end_function

end_unit

