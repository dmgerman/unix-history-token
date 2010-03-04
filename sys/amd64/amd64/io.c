begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004 Mark R V Murray  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/fcntl.h>
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
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/priv.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/signalvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<machine/db_machdep.h>
end_include

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_include
include|#
directive|include
file|<machine/psl.h>
end_include

begin_include
include|#
directive|include
file|<machine/specialreg.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<machine/iodev.h>
end_include

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|ioopen
parameter_list|(
name|struct
name|cdev
modifier|*
name|dev
name|__unused
parameter_list|,
name|int
name|flags
name|__unused
parameter_list|,
name|int
name|fmt
name|__unused
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
block|{
name|int
name|error
decl_stmt|;
name|error
operator|=
name|priv_check
argument_list|(
name|td
argument_list|,
name|PRIV_IO
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|!=
literal|0
condition|)
return|return
operator|(
name|error
operator|)
return|;
name|error
operator|=
name|securelevel_gt
argument_list|(
name|td
operator|->
name|td_ucred
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|!=
literal|0
condition|)
return|return
operator|(
name|error
operator|)
return|;
name|td
operator|->
name|td_frame
operator|->
name|tf_rflags
operator||=
name|PSL_IOPL
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|ioclose
parameter_list|(
name|struct
name|cdev
modifier|*
name|dev
name|__unused
parameter_list|,
name|int
name|flags
name|__unused
parameter_list|,
name|int
name|fmt
name|__unused
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
block|{
name|td
operator|->
name|td_frame
operator|->
name|tf_rflags
operator|&=
operator|~
name|PSL_IOPL
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|ioioctl
parameter_list|(
name|struct
name|cdev
modifier|*
name|dev
name|__unused
parameter_list|,
name|u_long
name|cmd
name|__unused
parameter_list|,
name|caddr_t
name|data
name|__unused
parameter_list|,
name|int
name|fflag
name|__unused
parameter_list|,
name|struct
name|thread
modifier|*
name|td
name|__unused
parameter_list|)
block|{
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
end_function

end_unit

