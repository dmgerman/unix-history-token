begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-2-Clause-FreeBSD  *  * Copyright (c) 2008 Ed Schouten<ed@FreeBSD.org>  * All rights reserved.  *  * Portions of this software were developed under sponsorship from Snow  * B.V., the Netherlands.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|"namespace.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|"un-namespace.h"
end_include

begin_comment
comment|/*  * __isptmaster():  return whether the file descriptor refers to a  *                  pseudo-terminal master device.  */
end_comment

begin_function
specifier|static
name|int
name|__isptmaster
parameter_list|(
name|int
name|fildes
parameter_list|)
block|{
if|if
condition|(
name|_ioctl
argument_list|(
name|fildes
argument_list|,
name|TIOCPTMASTER
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
if|if
condition|(
name|errno
operator|!=
name|EBADF
condition|)
name|errno
operator|=
name|EINVAL
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * In our implementation, grantpt() and unlockpt() don't actually have  * any use, because PTY's are created on the fly and already have proper  * permissions upon creation.  *  * Just make sure `fildes' actually points to a real PTY master device.  */
end_comment

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__isptmaster
argument_list|,
name|grantpt
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__isptmaster
argument_list|,
name|unlockpt
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * ptsname():  return the pathname of the slave pseudo-terminal device  *             associated with the specified master.  */
end_comment

begin_function
name|char
modifier|*
name|ptsname
parameter_list|(
name|int
name|fildes
parameter_list|)
block|{
specifier|static
name|char
name|pt_slave
index|[
sizeof|sizeof
name|_PATH_DEV
operator|+
name|SPECNAMELEN
index|]
init|=
name|_PATH_DEV
decl_stmt|;
name|char
modifier|*
name|ret
init|=
name|NULL
decl_stmt|;
comment|/* Make sure fildes points to a master device. */
if|if
condition|(
name|__isptmaster
argument_list|(
name|fildes
argument_list|)
operator|!=
literal|0
condition|)
goto|goto
name|done
goto|;
if|if
condition|(
name|fdevname_r
argument_list|(
name|fildes
argument_list|,
name|pt_slave
operator|+
operator|(
sizeof|sizeof
name|_PATH_DEV
operator|-
literal|1
operator|)
argument_list|,
sizeof|sizeof
name|pt_slave
operator|-
operator|(
sizeof|sizeof
name|_PATH_DEV
operator|-
literal|1
operator|)
argument_list|)
operator|!=
name|NULL
condition|)
name|ret
operator|=
name|pt_slave
expr_stmt|;
name|done
label|:
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

end_unit

