begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)lfs_cksum.c	8.1 (Berkeley) 6/11/93  * $FreeBSD$  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_include
include|#
directive|include
file|<ufs/lfs/lfs.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<ufs/lfs/lfs_extern.h>
end_include

begin_comment
comment|/*  * Simple, general purpose, fast checksum.  Data must be short-aligned.  * Returns a u_long in case we ever want to do something more rigorous.  *  * XXX  * Use the TCP/IP checksum instead.  */
end_comment

begin_function
name|u_long
name|cksum
parameter_list|(
name|str
parameter_list|,
name|len
parameter_list|)
specifier|register
name|void
modifier|*
name|str
decl_stmt|;
specifier|register
name|size_t
name|len
decl_stmt|;
block|{
specifier|register
name|u_long
name|sum
decl_stmt|;
name|len
operator|&=
operator|~
operator|(
sizeof|sizeof
argument_list|(
name|u_short
argument_list|)
operator|-
literal|1
operator|)
expr_stmt|;
for|for
control|(
name|sum
operator|=
literal|0
init|;
name|len
condition|;
name|len
operator|-=
sizeof|sizeof
argument_list|(
name|u_short
argument_list|)
control|)
block|{
name|sum
operator|^=
operator|*
operator|(
name|u_short
operator|*
operator|)
name|str
expr_stmt|;
operator|++
operator|(
name|u_short
operator|*
operator|)
name|str
expr_stmt|;
block|}
return|return
operator|(
name|sum
operator|)
return|;
block|}
end_function

end_unit

