begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)flags.c	8.1 (Berkeley) 6/4/93"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|"local.h"
end_include

begin_comment
comment|/*  * Return the (stdio) flags for a given mode.  Store the flags  * to be passed to an _open() syscall through *optr.  * Return 0 on error.  */
end_comment

begin_function
name|int
name|__sflags
parameter_list|(
name|mode
parameter_list|,
name|optr
parameter_list|)
specifier|const
name|char
modifier|*
name|mode
decl_stmt|;
name|int
modifier|*
name|optr
decl_stmt|;
block|{
name|int
name|ret
decl_stmt|,
name|m
decl_stmt|,
name|o
decl_stmt|;
switch|switch
condition|(
operator|*
name|mode
operator|++
condition|)
block|{
case|case
literal|'r'
case|:
comment|/* open for reading */
name|ret
operator|=
name|__SRD
expr_stmt|;
name|m
operator|=
name|O_RDONLY
expr_stmt|;
name|o
operator|=
literal|0
expr_stmt|;
break|break;
case|case
literal|'w'
case|:
comment|/* open for writing */
name|ret
operator|=
name|__SWR
expr_stmt|;
name|m
operator|=
name|O_WRONLY
expr_stmt|;
name|o
operator|=
name|O_CREAT
operator||
name|O_TRUNC
expr_stmt|;
break|break;
case|case
literal|'a'
case|:
comment|/* open for appending */
name|ret
operator|=
name|__SWR
expr_stmt|;
name|m
operator|=
name|O_WRONLY
expr_stmt|;
name|o
operator|=
name|O_CREAT
operator||
name|O_APPEND
expr_stmt|;
break|break;
default|default:
comment|/* illegal mode */
name|errno
operator|=
name|EINVAL
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
comment|/* [rwa]\+ or [rwa]b\+ means read and write */
if|if
condition|(
operator|*
name|mode
operator|==
literal|'+'
operator|||
operator|(
operator|*
name|mode
operator|==
literal|'b'
operator|&&
name|mode
index|[
literal|1
index|]
operator|==
literal|'+'
operator|)
condition|)
block|{
name|ret
operator|=
name|__SRW
expr_stmt|;
name|m
operator|=
name|O_RDWR
expr_stmt|;
block|}
operator|*
name|optr
operator|=
name|m
operator||
name|o
expr_stmt|;
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

end_unit

