begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)subr_xxx.c	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Miscellaneous trivial functions, including many  * that are often inline-expanded or done in assembler.  */
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
file|<machine/cpu.h>
end_include

begin_comment
comment|/*  * Unsupported device function (e.g. writing to read-only device).  */
end_comment

begin_function
name|int
name|enodev
parameter_list|()
block|{
return|return
operator|(
name|ENODEV
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Unconfigured device function; driver not configured.  */
end_comment

begin_function
name|int
name|enxio
parameter_list|()
block|{
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Unsupported ioctl function.  */
end_comment

begin_function
name|int
name|enoioctl
parameter_list|()
block|{
return|return
operator|(
name|ENOTTY
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Unsupported system function.  * This is used for an otherwise-reasonable operation  * that is not supported by the current system binary.  */
end_comment

begin_function
name|int
name|enosys
parameter_list|()
block|{
return|return
operator|(
name|ENOSYS
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Return error for operation not supported  * on a specific object or file type.  */
end_comment

begin_function
name|int
name|eopnotsupp
parameter_list|()
block|{
return|return
operator|(
name|EOPNOTSUPP
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Generic null operation, always returns success.  */
end_comment

begin_function
name|int
name|nullop
parameter_list|()
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

