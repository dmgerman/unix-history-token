begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010-2012 Semihalf.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

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
file|<sys/conf.h>
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
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<sys/namei.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_include
include|#
directive|include
file|<sys/bio.h>
end_include

begin_include
include|#
directive|include
file|<fs/nandfs/nandfs_mount.h>
end_include

begin_include
include|#
directive|include
file|<fs/nandfs/nandfs.h>
end_include

begin_include
include|#
directive|include
file|<fs/nandfs/nandfs_subr.h>
end_include

begin_function
name|struct
name|buf
modifier|*
name|nandfs_geteblk
parameter_list|(
name|int
name|size
parameter_list|,
name|int
name|flags
parameter_list|)
block|{
name|struct
name|buf
modifier|*
name|bp
decl_stmt|;
comment|/* 	 * XXX 	 * Right now we can call geteblk with GB_NOWAIT_BD flag, which means 	 * it can return NULL. But we cannot afford to get NULL, hence this panic. 	 */
name|bp
operator|=
name|geteblk
argument_list|(
name|size
argument_list|,
name|flags
argument_list|)
expr_stmt|;
if|if
condition|(
name|bp
operator|==
name|NULL
condition|)
name|panic
argument_list|(
literal|"geteblk returned NULL"
argument_list|)
expr_stmt|;
return|return
operator|(
name|bp
operator|)
return|;
block|}
end_function

begin_function
name|void
name|nandfs_dirty_bufs_increment
parameter_list|(
name|struct
name|nandfs_device
modifier|*
name|fsdev
parameter_list|)
block|{
name|mtx_lock
argument_list|(
operator|&
name|fsdev
operator|->
name|nd_mutex
argument_list|)
expr_stmt|;
name|KASSERT
argument_list|(
name|fsdev
operator|->
name|nd_dirty_bufs
operator|>=
literal|0
argument_list|,
operator|(
literal|"negative nd_dirty_bufs"
operator|)
argument_list|)
expr_stmt|;
name|fsdev
operator|->
name|nd_dirty_bufs
operator|++
expr_stmt|;
name|mtx_unlock
argument_list|(
operator|&
name|fsdev
operator|->
name|nd_mutex
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|nandfs_dirty_bufs_decrement
parameter_list|(
name|struct
name|nandfs_device
modifier|*
name|fsdev
parameter_list|)
block|{
name|mtx_lock
argument_list|(
operator|&
name|fsdev
operator|->
name|nd_mutex
argument_list|)
expr_stmt|;
name|KASSERT
argument_list|(
name|fsdev
operator|->
name|nd_dirty_bufs
operator|>
literal|0
argument_list|,
operator|(
literal|"decrementing not-positive nd_dirty_bufs"
operator|)
argument_list|)
expr_stmt|;
name|fsdev
operator|->
name|nd_dirty_bufs
operator|--
expr_stmt|;
name|mtx_unlock
argument_list|(
operator|&
name|fsdev
operator|->
name|nd_mutex
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

