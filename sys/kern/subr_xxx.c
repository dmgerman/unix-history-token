begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)subr_xxx.c	8.1 (Berkeley) 6/10/93  * $Id: subr_xxx.c,v 1.3 1994/08/02 07:42:36 davidg Exp $  */
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

begin_decl_stmt
specifier|extern
name|int
name|enosys
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_comment
comment|/*  * Specific `no' and `null' operations.  * XXX the general ones are bogus.  * XXX device functions may belong elsewhere.  */
end_comment

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_function
name|int
name|noreset
parameter_list|(
name|dummy
parameter_list|)
name|int
name|dummy
decl_stmt|;
block|{
return|return
operator|(
name|ENODEV
operator|)
return|;
block|}
end_function

begin_function
name|int
name|nommap
parameter_list|(
name|dev
parameter_list|,
name|offset
parameter_list|,
name|nprot
parameter_list|)
name|dev_t
name|dev
decl_stmt|;
name|int
name|offset
decl_stmt|;
name|int
name|nprot
decl_stmt|;
block|{
comment|/* Don't return ENODEV.  That would allow mapping address ENODEV! */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_function
name|void
name|nostrategy
parameter_list|(
name|bp
parameter_list|)
name|struct
name|buf
modifier|*
name|bp
decl_stmt|;
block|{  }
end_function

begin_comment
comment|/*  * XXX this is probably bogus.  Any device that uses it isn't checking the  * minor number.  */
end_comment

begin_function
name|int
name|nullopen
parameter_list|(
name|dev
parameter_list|,
name|flag
parameter_list|,
name|mode
parameter_list|,
name|p
parameter_list|)
name|dev_t
name|dev
decl_stmt|;
name|int
name|flag
decl_stmt|;
name|int
name|mode
decl_stmt|;
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|int
name|nullclose
parameter_list|(
name|dev
parameter_list|,
name|flag
parameter_list|,
name|mode
parameter_list|,
name|p
parameter_list|)
name|dev_t
name|dev
decl_stmt|;
name|int
name|flag
decl_stmt|;
name|int
name|mode
decl_stmt|;
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|void
name|nullstop
parameter_list|(
name|tp
parameter_list|,
name|rw
parameter_list|)
name|struct
name|tty
modifier|*
name|tp
decl_stmt|;
name|int
name|rw
decl_stmt|;
block|{  }
end_function

begin_function
name|int
name|nullreset
parameter_list|(
name|foo
parameter_list|)
name|int
name|foo
decl_stmt|;
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

