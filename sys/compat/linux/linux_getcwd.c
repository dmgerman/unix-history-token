begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: linux_getcwd.c,v 1.2 2001/05/16 12:50:21 ho Exp $ */
end_comment

begin_comment
comment|/* $NetBSD: vfs_getcwd.c,v 1.3.2.3 1999/07/11 10:24:09 sommerfeld Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1999 The NetBSD Foundation, Inc.  * Copyright (c) 2015 The FreeBSD Foundation  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Bill Sommerfeld.  *  * Portions of this software were developed by Edward Tomasz Napierala  * under sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
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
file|"opt_compat.h"
end_include

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
file|<sys/syscallsubr.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|COMPAT_LINUX32
end_ifdef

begin_include
include|#
directive|include
file|<machine/../linux32/linux.h>
end_include

begin_include
include|#
directive|include
file|<machine/../linux32/linux32_proto.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<machine/../linux/linux.h>
end_include

begin_include
include|#
directive|include
file|<machine/../linux/linux_proto.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<compat/linux/linux_misc.h>
end_include

begin_include
include|#
directive|include
file|<compat/linux/linux_util.h>
end_include

begin_comment
comment|/*  * Find pathname of process's current directory.  */
end_comment

begin_function
name|int
name|linux_getcwd
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|linux_getcwd_args
modifier|*
name|args
parameter_list|)
block|{
name|char
modifier|*
name|path
decl_stmt|;
name|int
name|error
decl_stmt|,
name|lenused
decl_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|ldebug
argument_list|(
name|getcwd
argument_list|)
condition|)
name|printf
argument_list|(
name|ARGS
argument_list|(
name|getcwd
argument_list|,
literal|"%p, %ld"
argument_list|)
argument_list|,
name|args
operator|->
name|buf
argument_list|,
operator|(
name|long
operator|)
name|args
operator|->
name|bufsize
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* 	 * Linux returns ERANGE instead of EINVAL. 	 */
if|if
condition|(
name|args
operator|->
name|bufsize
operator|<
literal|2
condition|)
return|return
operator|(
name|ERANGE
operator|)
return|;
name|path
operator|=
name|malloc
argument_list|(
name|LINUX_PATH_MAX
argument_list|,
name|M_TEMP
argument_list|,
name|M_WAITOK
argument_list|)
expr_stmt|;
name|error
operator|=
name|kern___getcwd
argument_list|(
name|td
argument_list|,
name|path
argument_list|,
name|UIO_SYSSPACE
argument_list|,
name|args
operator|->
name|bufsize
argument_list|,
name|LINUX_PATH_MAX
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|==
literal|0
condition|)
block|{
name|lenused
operator|=
name|strlen
argument_list|(
name|path
argument_list|)
operator|+
literal|1
expr_stmt|;
name|error
operator|=
name|copyout
argument_list|(
name|path
argument_list|,
name|args
operator|->
name|buf
argument_list|,
name|lenused
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|==
literal|0
condition|)
name|td
operator|->
name|td_retval
index|[
literal|0
index|]
operator|=
name|lenused
expr_stmt|;
block|}
name|free
argument_list|(
name|path
argument_list|,
name|M_TEMP
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

