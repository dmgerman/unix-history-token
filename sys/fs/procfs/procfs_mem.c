begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 Jan-Simon Pendry  * Copyright (c) 1993 Sean Eric Fagan  * Copyright (c) 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry and Sean Eric Fagan.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)procfs_mem.c	8.5 (Berkeley) 6/15/94  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
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
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/ptrace.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<fs/pseudofs/pseudofs.h>
end_include

begin_include
include|#
directive|include
file|<fs/procfs/procfs.h>
end_include

begin_comment
comment|/*  * Copy data in and out of the target process.  * We do this by mapping the process's page into  * the kernel and then doing a uiomove direct  * from the kernel address space.  */
end_comment

begin_function
name|int
name|procfs_doprocmem
parameter_list|(
name|PFS_FILL_ARGS
parameter_list|)
block|{
name|int
name|error
decl_stmt|;
if|if
condition|(
name|uio
operator|->
name|uio_resid
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|PROC_LOCK
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|error
operator|=
name|p_candebug
argument_list|(
name|td
operator|->
name|td_proc
argument_list|,
name|p
argument_list|)
expr_stmt|;
name|PROC_UNLOCK
argument_list|(
name|p
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|==
literal|0
condition|)
name|error
operator|=
name|proc_rwmem
argument_list|(
name|p
argument_list|,
name|uio
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

end_unit

