begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)mfs_vnops.c	7.22 (Berkeley) 4/16/91  *	$Id: mfs_vnops.c,v 1.2 1993/10/16 18:17:44 rgrimes Exp $  */
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
file|"kernel.h"
end_include

begin_include
include|#
directive|include
file|"proc.h"
end_include

begin_include
include|#
directive|include
file|"buf.h"
end_include

begin_include
include|#
directive|include
file|"vnode.h"
end_include

begin_include
include|#
directive|include
file|"mfsnode.h"
end_include

begin_include
include|#
directive|include
file|"mfsiom.h"
end_include

begin_include
include|#
directive|include
file|"machine/vmparam.h"
end_include

begin_comment
comment|/*  * mfs vnode operations.  */
end_comment

begin_decl_stmt
name|struct
name|vnodeops
name|mfs_vnodeops
init|=
block|{
name|mfs_lookup
block|,
comment|/* lookup */
name|mfs_create
block|,
comment|/* create */
name|mfs_mknod
block|,
comment|/* mknod */
name|mfs_open
block|,
comment|/* open */
name|mfs_close
block|,
comment|/* close */
name|mfs_access
block|,
comment|/* access */
name|mfs_getattr
block|,
comment|/* getattr */
name|mfs_setattr
block|,
comment|/* setattr */
name|mfs_read
block|,
comment|/* read */
name|mfs_write
block|,
comment|/* write */
name|mfs_ioctl
block|,
comment|/* ioctl */
name|mfs_select
block|,
comment|/* select */
name|mfs_mmap
block|,
comment|/* mmap */
name|mfs_fsync
block|,
comment|/* fsync */
name|mfs_seek
block|,
comment|/* seek */
name|mfs_remove
block|,
comment|/* remove */
name|mfs_link
block|,
comment|/* link */
name|mfs_rename
block|,
comment|/* rename */
name|mfs_mkdir
block|,
comment|/* mkdir */
name|mfs_rmdir
block|,
comment|/* rmdir */
name|mfs_symlink
block|,
comment|/* symlink */
name|mfs_readdir
block|,
comment|/* readdir */
name|mfs_readlink
block|,
comment|/* readlink */
name|mfs_abortop
block|,
comment|/* abortop */
name|mfs_inactive
block|,
comment|/* inactive */
name|mfs_reclaim
block|,
comment|/* reclaim */
name|mfs_lock
block|,
comment|/* lock */
name|mfs_unlock
block|,
comment|/* unlock */
name|mfs_bmap
block|,
comment|/* bmap */
name|mfs_strategy
block|,
comment|/* strategy */
name|mfs_print
block|,
comment|/* print */
name|mfs_islocked
block|,
comment|/* islocked */
name|mfs_advlock
block|,
comment|/* advlock */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Vnode Operations.  *  * Open called to allow memory filesystem to initialize and  * validate before actual IO. Record our process identifier  * so we can tell when we are doing I/O to ourself.  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|mfs_open
parameter_list|(
name|vp
parameter_list|,
name|mode
parameter_list|,
name|cred
parameter_list|,
name|p
parameter_list|)
specifier|register
name|struct
name|vnode
modifier|*
name|vp
decl_stmt|;
name|int
name|mode
decl_stmt|;
name|struct
name|ucred
modifier|*
name|cred
decl_stmt|;
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
block|{
if|if
condition|(
name|vp
operator|->
name|v_type
operator|!=
name|VBLK
condition|)
block|{
name|panic
argument_list|(
literal|"mfs_ioctl not VBLK"
argument_list|)
expr_stmt|;
comment|/* NOTREACHED */
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Ioctl operation.  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|mfs_ioctl
parameter_list|(
name|vp
parameter_list|,
name|com
parameter_list|,
name|data
parameter_list|,
name|fflag
parameter_list|,
name|cred
parameter_list|,
name|p
parameter_list|)
name|struct
name|vnode
modifier|*
name|vp
decl_stmt|;
name|int
name|com
decl_stmt|;
name|caddr_t
name|data
decl_stmt|;
name|int
name|fflag
decl_stmt|;
name|struct
name|ucred
modifier|*
name|cred
decl_stmt|;
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
block|{
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Pass I/O requests to the memory filesystem process.  */
end_comment

begin_function
name|int
name|mfs_strategy
parameter_list|(
name|bp
parameter_list|)
specifier|register
name|struct
name|buf
modifier|*
name|bp
decl_stmt|;
block|{
specifier|register
name|struct
name|mfsnode
modifier|*
name|mfsp
decl_stmt|;
name|struct
name|vnode
modifier|*
name|vp
decl_stmt|;
name|struct
name|proc
modifier|*
name|p
init|=
name|curproc
decl_stmt|;
comment|/* XXX */
if|if
condition|(
name|vfinddev
argument_list|(
name|bp
operator|->
name|b_dev
argument_list|,
name|VBLK
argument_list|,
operator|&
name|vp
argument_list|)
operator|||
name|vp
operator|->
name|v_usecount
operator|==
literal|0
condition|)
name|panic
argument_list|(
literal|"mfs_strategy: bad dev"
argument_list|)
expr_stmt|;
name|mfsp
operator|=
name|VTOMFS
argument_list|(
name|vp
argument_list|)
expr_stmt|;
if|if
condition|(
name|mfsp
operator|->
name|mfs_pid
operator|==
name|p
operator|->
name|p_pid
condition|)
block|{
name|mfs_doio
argument_list|(
name|bp
argument_list|,
name|mfsp
operator|->
name|mfs_baseoff
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|bp
operator|->
name|av_forw
operator|=
name|mfsp
operator|->
name|mfs_buflist
expr_stmt|;
name|mfsp
operator|->
name|mfs_buflist
operator|=
name|bp
expr_stmt|;
name|wakeup
argument_list|(
operator|(
name|caddr_t
operator|)
name|vp
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Memory file system I/O.  *  * Trivial since buffer has already been mapping into KVA space.  */
end_comment

begin_function
name|void
name|mfs_doio
parameter_list|(
name|bp
parameter_list|,
name|base
parameter_list|)
specifier|register
name|struct
name|buf
modifier|*
name|bp
decl_stmt|;
name|caddr_t
name|base
decl_stmt|;
block|{
name|base
operator|+=
operator|(
name|bp
operator|->
name|b_blkno
operator|<<
name|DEV_BSHIFT
operator|)
expr_stmt|;
if|if
condition|(
name|bp
operator|->
name|b_flags
operator|&
name|B_READ
condition|)
name|bp
operator|->
name|b_error
operator|=
name|copyin
argument_list|(
name|base
argument_list|,
name|bp
operator|->
name|b_un
operator|.
name|b_addr
argument_list|,
name|bp
operator|->
name|b_bcount
argument_list|)
expr_stmt|;
else|else
name|bp
operator|->
name|b_error
operator|=
name|copyout
argument_list|(
name|bp
operator|->
name|b_un
operator|.
name|b_addr
argument_list|,
name|base
argument_list|,
name|bp
operator|->
name|b_bcount
argument_list|)
expr_stmt|;
if|if
condition|(
name|bp
operator|->
name|b_error
condition|)
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
block|}
end_function

begin_comment
comment|/*  * This is a noop, simply returning what one has been given.  */
end_comment

begin_function
name|int
name|mfs_bmap
parameter_list|(
name|vp
parameter_list|,
name|bn
parameter_list|,
name|vpp
parameter_list|,
name|bnp
parameter_list|)
name|struct
name|vnode
modifier|*
name|vp
decl_stmt|;
name|daddr_t
name|bn
decl_stmt|;
name|struct
name|vnode
modifier|*
modifier|*
name|vpp
decl_stmt|;
name|daddr_t
modifier|*
name|bnp
decl_stmt|;
block|{
if|if
condition|(
name|vpp
operator|!=
name|NULL
condition|)
operator|*
name|vpp
operator|=
name|vp
expr_stmt|;
if|if
condition|(
name|bnp
operator|!=
name|NULL
condition|)
operator|*
name|bnp
operator|=
name|bn
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Memory filesystem close routine  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|mfs_close
parameter_list|(
name|vp
parameter_list|,
name|flag
parameter_list|,
name|cred
parameter_list|,
name|p
parameter_list|)
specifier|register
name|struct
name|vnode
modifier|*
name|vp
decl_stmt|;
name|int
name|flag
decl_stmt|;
name|struct
name|ucred
modifier|*
name|cred
decl_stmt|;
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
block|{
specifier|register
name|struct
name|mfsnode
modifier|*
name|mfsp
init|=
name|VTOMFS
argument_list|(
name|vp
argument_list|)
decl_stmt|;
specifier|register
name|struct
name|buf
modifier|*
name|bp
decl_stmt|;
comment|/* 	 * Finish any pending I/O requests. 	 */
while|while
condition|(
name|bp
operator|=
name|mfsp
operator|->
name|mfs_buflist
condition|)
block|{
name|mfsp
operator|->
name|mfs_buflist
operator|=
name|bp
operator|->
name|av_forw
expr_stmt|;
name|mfs_doio
argument_list|(
name|bp
argument_list|,
name|mfsp
operator|->
name|mfs_baseoff
argument_list|)
expr_stmt|;
name|wakeup
argument_list|(
operator|(
name|caddr_t
operator|)
name|bp
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * On last close of a memory filesystem 	 * we must invalidate any in core blocks, so that 	 * we can, free up its vnode. 	 */
name|vflushbuf
argument_list|(
name|vp
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|vinvalbuf
argument_list|(
name|vp
argument_list|,
literal|1
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
comment|/* 	 * There should be no way to have any more uses of this 	 * vnode, so if we find any other uses, it is a panic. 	 */
if|if
condition|(
name|vp
operator|->
name|v_usecount
operator|>
literal|1
condition|)
name|printf
argument_list|(
literal|"mfs_close: ref count %d> 1\n"
argument_list|,
name|vp
operator|->
name|v_usecount
argument_list|)
expr_stmt|;
if|if
condition|(
name|vp
operator|->
name|v_usecount
operator|>
literal|1
operator|||
name|mfsp
operator|->
name|mfs_buflist
condition|)
name|panic
argument_list|(
literal|"mfs_close"
argument_list|)
expr_stmt|;
comment|/* 	 * Send a request to the filesystem server to exit. 	 */
name|mfsp
operator|->
name|mfs_buflist
operator|=
operator|(
expr|struct
name|buf
operator|*
operator|)
operator|(
operator|-
literal|1
operator|)
expr_stmt|;
name|wakeup
argument_list|(
operator|(
name|caddr_t
operator|)
name|vp
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
comment|/*  * Memory filesystem inactive routine  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|mfs_inactive
parameter_list|(
name|vp
parameter_list|,
name|p
parameter_list|)
name|struct
name|vnode
modifier|*
name|vp
decl_stmt|;
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
block|{
if|if
condition|(
name|VTOMFS
argument_list|(
name|vp
argument_list|)
operator|->
name|mfs_buflist
operator|!=
operator|(
expr|struct
name|buf
operator|*
operator|)
operator|(
operator|-
literal|1
operator|)
condition|)
name|panic
argument_list|(
literal|"mfs_inactive: not inactive"
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
comment|/*  * Print out the contents of an mfsnode.  */
end_comment

begin_function
name|void
name|mfs_print
parameter_list|(
name|vp
parameter_list|)
name|struct
name|vnode
modifier|*
name|vp
decl_stmt|;
block|{
specifier|register
name|struct
name|mfsnode
modifier|*
name|mfsp
init|=
name|VTOMFS
argument_list|(
name|vp
argument_list|)
decl_stmt|;
name|printf
argument_list|(
literal|"tag VT_MFS, pid %d, base %d, size %d\n"
argument_list|,
name|mfsp
operator|->
name|mfs_pid
argument_list|,
name|mfsp
operator|->
name|mfs_baseoff
argument_list|,
name|mfsp
operator|->
name|mfs_size
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Block device bad operation  */
end_comment

begin_function
name|int
name|mfs_badop
parameter_list|()
block|{
name|panic
argument_list|(
literal|"mfs_badop called\n"
argument_list|)
expr_stmt|;
comment|/* NOTREACHED */
block|}
end_function

begin_comment
comment|/*  * Memory based filesystem initialization.  */
end_comment

begin_function
name|void
name|mfs_init
parameter_list|()
block|{  }
end_function

end_unit

