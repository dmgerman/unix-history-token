begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)dead_vnops.c	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
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
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/poll.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_comment
comment|/*  * Prototypes for dead operations on vnodes.  */
end_comment

begin_decl_stmt
specifier|static
name|vop_lookup_t
name|dead_lookup
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|vop_open_t
name|dead_open
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|vop_poll_t
name|dead_poll
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|vop_read_t
name|dead_read
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|vop_write_t
name|dead_write
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|vop_getwritemount_t
name|dead_getwritemount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|vop_rename_t
name|dead_rename
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|vop_vector
name|dead_vnodeops
init|=
block|{
operator|.
name|vop_default
operator|=
operator|&
name|default_vnodeops
block|,
operator|.
name|vop_access
operator|=
name|VOP_EBADF
block|,
operator|.
name|vop_advlock
operator|=
name|VOP_EBADF
block|,
operator|.
name|vop_bmap
operator|=
name|VOP_EBADF
block|,
operator|.
name|vop_create
operator|=
name|VOP_PANIC
block|,
operator|.
name|vop_getattr
operator|=
name|VOP_EBADF
block|,
operator|.
name|vop_getwritemount
operator|=
name|dead_getwritemount
block|,
operator|.
name|vop_inactive
operator|=
name|VOP_NULL
block|,
operator|.
name|vop_ioctl
operator|=
name|VOP_EBADF
block|,
operator|.
name|vop_link
operator|=
name|VOP_PANIC
block|,
operator|.
name|vop_lookup
operator|=
name|dead_lookup
block|,
operator|.
name|vop_mkdir
operator|=
name|VOP_PANIC
block|,
operator|.
name|vop_mknod
operator|=
name|VOP_PANIC
block|,
operator|.
name|vop_open
operator|=
name|dead_open
block|,
operator|.
name|vop_pathconf
operator|=
name|VOP_EBADF
block|,
comment|/* per pathconf(2) */
operator|.
name|vop_poll
operator|=
name|dead_poll
block|,
operator|.
name|vop_read
operator|=
name|dead_read
block|,
operator|.
name|vop_readdir
operator|=
name|VOP_EBADF
block|,
operator|.
name|vop_readlink
operator|=
name|VOP_EBADF
block|,
operator|.
name|vop_reclaim
operator|=
name|VOP_NULL
block|,
operator|.
name|vop_remove
operator|=
name|VOP_PANIC
block|,
operator|.
name|vop_rename
operator|=
name|dead_rename
block|,
operator|.
name|vop_rmdir
operator|=
name|VOP_PANIC
block|,
operator|.
name|vop_setattr
operator|=
name|VOP_EBADF
block|,
operator|.
name|vop_symlink
operator|=
name|VOP_PANIC
block|,
operator|.
name|vop_vptocnp
operator|=
name|VOP_EBADF
block|,
operator|.
name|vop_write
operator|=
name|dead_write
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
specifier|static
name|int
name|dead_getwritemount
parameter_list|(
name|ap
parameter_list|)
name|struct
name|vop_getwritemount_args
comment|/* { 		struct vnode *a_vp; 		struct mount **a_mpp; 	} */
modifier|*
name|ap
decl_stmt|;
block|{
operator|*
operator|(
name|ap
operator|->
name|a_mpp
operator|)
operator|=
name|NULL
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

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
comment|/* 	 * Return EOF for tty devices, EIO for others 	 */
if|if
condition|(
operator|(
name|ap
operator|->
name|a_vp
operator|->
name|v_vflag
operator|&
name|VV_ISTTY
operator|)
operator|==
literal|0
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
return|return
operator|(
name|EIO
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|dead_poll
parameter_list|(
name|ap
parameter_list|)
name|struct
name|vop_poll_args
modifier|*
name|ap
decl_stmt|;
block|{
if|if
condition|(
name|ap
operator|->
name|a_events
operator|&
operator|~
name|POLLSTANDARD
condition|)
return|return
operator|(
name|POLLNVAL
operator|)
return|;
comment|/* 	 * Let the user find out that the descriptor is gone. 	 */
return|return
operator|(
name|POLLHUP
operator||
operator|(
operator|(
name|POLLIN
operator||
name|POLLRDNORM
operator|)
operator|&
name|ap
operator|->
name|a_events
operator|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|dead_rename
parameter_list|(
name|ap
parameter_list|)
name|struct
name|vop_rename_args
comment|/* { 		struct vnode *a_fdvp; 		struct vnode *a_fvp; 		struct componentname *a_fcnp; 		struct vnode *a_tdvp; 		struct vnode *a_tvp; 		struct componentname *a_tcnp; 	} */
modifier|*
name|ap
decl_stmt|;
block|{
name|vop_rename_fail
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return
operator|(
name|EXDEV
operator|)
return|;
block|}
end_function

end_unit

