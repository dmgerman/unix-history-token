begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)dead_vnops.c	7.9 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|"param.h"
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

begin_decl_stmt
name|int
name|dead_lookup
argument_list|()
decl_stmt|,
name|dead_open
argument_list|()
decl_stmt|,
name|dead_read
argument_list|()
decl_stmt|,
name|dead_write
argument_list|()
decl_stmt|,
name|dead_strategy
argument_list|()
decl_stmt|,
name|dead_ioctl
argument_list|()
decl_stmt|,
name|dead_select
argument_list|()
decl_stmt|,
name|dead_lock
argument_list|()
decl_stmt|,
name|dead_bmap
argument_list|()
decl_stmt|,
name|dead_print
argument_list|()
decl_stmt|,
name|dead_ebadf
argument_list|()
decl_stmt|,
name|dead_badop
argument_list|()
decl_stmt|,
name|dead_nullop
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|vnodeops
name|dead_vnodeops
init|=
block|{
name|dead_lookup
block|,
comment|/* lookup */
name|dead_badop
block|,
comment|/* create */
name|dead_badop
block|,
comment|/* mknod */
name|dead_open
block|,
comment|/* open */
name|dead_nullop
block|,
comment|/* close */
name|dead_ebadf
block|,
comment|/* access */
name|dead_ebadf
block|,
comment|/* getattr */
name|dead_ebadf
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
name|dead_badop
block|,
comment|/* mmap */
name|dead_nullop
block|,
comment|/* fsync */
name|dead_nullop
block|,
comment|/* seek */
name|dead_badop
block|,
comment|/* remove */
name|dead_badop
block|,
comment|/* link */
name|dead_badop
block|,
comment|/* rename */
name|dead_badop
block|,
comment|/* mkdir */
name|dead_badop
block|,
comment|/* rmdir */
name|dead_badop
block|,
comment|/* symlink */
name|dead_ebadf
block|,
comment|/* readdir */
name|dead_ebadf
block|,
comment|/* readlink */
name|dead_badop
block|,
comment|/* abortop */
name|dead_nullop
block|,
comment|/* inactive */
name|dead_nullop
block|,
comment|/* reclaim */
name|dead_lock
block|,
comment|/* lock */
name|dead_nullop
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
name|dead_nullop
block|,
comment|/* islocked */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Trivial lookup routine that always fails.  */
end_comment

begin_macro
name|dead_lookup
argument_list|(
argument|vp
argument_list|,
argument|ndp
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

