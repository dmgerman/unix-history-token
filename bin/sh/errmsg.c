begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)errmsg.c	8.1 (Berkeley) 5/31/93"
decl_stmt|;
end_decl_stmt

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
file|"shell.h"
end_include

begin_include
include|#
directive|include
file|"output.h"
end_include

begin_include
include|#
directive|include
file|"errmsg.h"
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_define
define|#
directive|define
name|ALL
value|(E_OPEN|E_CREAT|E_EXEC)
end_define

begin_struct
struct|struct
name|errname
block|{
name|short
name|errcode
decl_stmt|;
comment|/* error number */
name|short
name|action
decl_stmt|;
comment|/* operation which encountered the error */
name|char
modifier|*
name|msg
decl_stmt|;
comment|/* text describing the error */
block|}
struct|;
end_struct

begin_expr_stmt
name|STATIC
specifier|const
expr|struct
name|errname
name|errormsg
index|[]
operator|=
block|{
name|EINTR
block|,
name|ALL
block|,
literal|"interrupted"
block|,
name|EACCES
block|,
name|ALL
block|,
literal|"permission denied"
block|,
name|EIO
block|,
name|ALL
block|,
literal|"I/O error"
block|,
name|ENOENT
block|,
name|E_OPEN
block|,
literal|"no such file"
block|,
name|ENOENT
block|,
name|E_CREAT
block|,
literal|"directory nonexistent"
block|,
name|ENOENT
block|,
name|E_EXEC
block|,
literal|"not found"
block|,
name|ENOTDIR
block|,
name|E_OPEN
block|,
literal|"no such file"
block|,
name|ENOTDIR
block|,
name|E_CREAT
block|,
literal|"directory nonexistent"
block|,
name|ENOTDIR
block|,
name|E_EXEC
block|,
literal|"not found"
block|,
name|EISDIR
block|,
name|ALL
block|,
literal|"is a directory"
block|,
comment|/*    EMFILE, ALL,	"too many open files", */
name|ENFILE
block|,
name|ALL
block|,
literal|"file table overflow"
block|,
name|ENOSPC
block|,
name|ALL
block|,
literal|"file system full"
block|,
ifdef|#
directive|ifdef
name|EDQUOT
name|EDQUOT
block|,
name|ALL
block|,
literal|"disk quota exceeded"
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ENOSR
name|ENOSR
block|,
name|ALL
block|,
literal|"no streams resources"
block|,
endif|#
directive|endif
name|ENXIO
block|,
name|ALL
block|,
literal|"no such device or address"
block|,
name|EROFS
block|,
name|ALL
block|,
literal|"read-only file system"
block|,
name|ETXTBSY
block|,
name|ALL
block|,
literal|"text busy"
block|,
ifdef|#
directive|ifdef
name|SYSV
name|EAGAIN
block|,
name|E_EXEC
block|,
literal|"not enough memory"
block|,
endif|#
directive|endif
name|ENOMEM
block|,
name|ALL
block|,
literal|"not enough memory"
block|,
ifdef|#
directive|ifdef
name|ENOLINK
name|ENOLINK
block|,
name|ALL
block|,
literal|"remote access failed"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EMULTIHOP
name|EMULTIHOP
block|,
name|ALL
block|,
literal|"remote access failed"
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ECOMM
name|ECOMM
block|,
name|ALL
block|,
literal|"remote access failed"
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ESTALE
name|ESTALE
block|,
name|ALL
block|,
literal|"remote access failed"
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ETIMEDOUT
name|ETIMEDOUT
block|,
name|ALL
block|,
literal|"remote access failed"
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ELOOP
name|ELOOP
block|,
name|ALL
block|,
literal|"symbolic link loop"
block|,
endif|#
directive|endif
name|E2BIG
block|,
name|E_EXEC
block|,
literal|"argument list too long"
block|,
ifdef|#
directive|ifdef
name|ELIBACC
name|ELIBACC
block|,
name|E_EXEC
block|,
literal|"shared library missing"
block|,
endif|#
directive|endif
literal|0
block|,
literal|0
block|,
name|NULL
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Return a string describing an error.  The returned string may be a  * pointer to a static buffer that will be overwritten on the next call.  * Action describes the operation that got the error.  */
end_comment

begin_function
name|char
modifier|*
name|errmsg
parameter_list|(
name|e
parameter_list|,
name|action
parameter_list|)
block|{
name|struct
name|errname
specifier|const
modifier|*
name|ep
decl_stmt|;
specifier|static
name|char
name|buf
index|[
literal|12
index|]
decl_stmt|;
for|for
control|(
name|ep
operator|=
name|errormsg
init|;
name|ep
operator|->
name|errcode
condition|;
name|ep
operator|++
control|)
block|{
if|if
condition|(
name|ep
operator|->
name|errcode
operator|==
name|e
operator|&&
operator|(
name|ep
operator|->
name|action
operator|&
name|action
operator|)
operator|!=
literal|0
condition|)
return|return
name|ep
operator|->
name|msg
return|;
block|}
name|fmtstr
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
name|buf
argument_list|,
literal|"error %d"
argument_list|,
name|e
argument_list|)
expr_stmt|;
return|return
name|buf
return|;
block|}
end_function

end_unit

