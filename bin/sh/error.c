begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static char sccsid[] = "@(#)error.c	8.2 (Berkeley) 5/4/95";
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  * Errors and exceptions.  */
end_comment

begin_include
include|#
directive|include
file|"shell.h"
end_include

begin_include
include|#
directive|include
file|"main.h"
end_include

begin_include
include|#
directive|include
file|"options.h"
end_include

begin_include
include|#
directive|include
file|"output.h"
end_include

begin_include
include|#
directive|include
file|"error.h"
end_include

begin_include
include|#
directive|include
file|"nodes.h"
end_include

begin_comment
comment|/* show.h needs nodes.h */
end_comment

begin_include
include|#
directive|include
file|"show.h"
end_include

begin_include
include|#
directive|include
file|"trap.h"
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_comment
comment|/*  * Code to handle exceptions in C.  */
end_comment

begin_decl_stmt
name|struct
name|jmploc
modifier|*
name|handler
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|sig_atomic_t
name|exception
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|sig_atomic_t
name|suppressint
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|sig_atomic_t
name|intpending
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|commandname
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|void
name|exverror
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|__printf0like
parameter_list|(
function_decl|2
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*  * Called to raise an exception.  Since C doesn't include exceptions, we  * just do a longjmp to the exception handler.  The type of exception is  * stored in the global variable "exception".  */
end_comment

begin_function
name|void
name|exraise
parameter_list|(
name|int
name|e
parameter_list|)
block|{
if|if
condition|(
name|handler
operator|==
name|NULL
condition|)
name|abort
argument_list|()
expr_stmt|;
name|exception
operator|=
name|e
expr_stmt|;
name|longjmp
argument_list|(
name|handler
operator|->
name|loc
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Called from trap.c when a SIGINT is received.  (If the user specifies  * that SIGINT is to be trapped or ignored using the trap builtin, then  * this routine is not called.)  Suppressint is nonzero when interrupts  * are held using the INTOFF macro.  If SIGINTs are not suppressed and  * the shell is not a root shell, then we want to be terminated if we  * get here, as if we were terminated directly by a SIGINT.  Arrange for  * this here.  */
end_comment

begin_function
name|void
name|onint
parameter_list|(
name|void
parameter_list|)
block|{
name|sigset_t
name|sigset
decl_stmt|;
comment|/* 	 * The !in_dotrap here is safe.  The only way we can arrive here 	 * with in_dotrap set is that a trap handler set SIGINT to SIG_DFL 	 * and killed itself. 	 */
if|if
condition|(
name|suppressint
operator|&&
operator|!
name|in_dotrap
condition|)
block|{
name|intpending
operator|++
expr_stmt|;
return|return;
block|}
name|intpending
operator|=
literal|0
expr_stmt|;
name|sigemptyset
argument_list|(
operator|&
name|sigset
argument_list|)
expr_stmt|;
name|sigprocmask
argument_list|(
name|SIG_SETMASK
argument_list|,
operator|&
name|sigset
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
comment|/* 	 * This doesn't seem to be needed, since main() emits a newline. 	 */
if|#
directive|if
literal|0
block|if (tcgetpgrp(0) == getpid())	 		write(STDERR_FILENO, "\n", 1);
endif|#
directive|endif
if|if
condition|(
name|rootshell
operator|&&
name|iflag
condition|)
name|exraise
argument_list|(
name|EXINT
argument_list|)
expr_stmt|;
else|else
block|{
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
name|kill
argument_list|(
name|getpid
argument_list|()
argument_list|,
name|SIGINT
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * Exverror is called to raise the error exception.  If the first argument  * is not NULL then error prints an error message using printf style  * formatting.  It then raises the error exception.  */
end_comment

begin_function
specifier|static
name|void
name|exverror
parameter_list|(
name|int
name|cond
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
name|va_list
name|ap
parameter_list|)
block|{
name|CLEAR_PENDING_INT
expr_stmt|;
name|INTOFF
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|msg
condition|)
name|TRACE
argument_list|(
operator|(
literal|"exverror(%d, \"%s\") pid=%d\n"
operator|,
name|cond
operator|,
name|msg
operator|,
name|getpid
argument_list|()
operator|)
argument_list|)
expr_stmt|;
else|else
name|TRACE
argument_list|(
operator|(
literal|"exverror(%d, NULL) pid=%d\n"
operator|,
name|cond
operator|,
name|getpid
argument_list|()
operator|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|msg
condition|)
block|{
if|if
condition|(
name|commandname
condition|)
name|outfmt
argument_list|(
operator|&
name|errout
argument_list|,
literal|"%s: "
argument_list|,
name|commandname
argument_list|)
expr_stmt|;
name|doformat
argument_list|(
operator|&
name|errout
argument_list|,
name|msg
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|out2c
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
block|}
name|flushall
argument_list|()
expr_stmt|;
name|exraise
argument_list|(
name|cond
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|error
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|ap
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|msg
argument_list|)
expr_stmt|;
name|exverror
argument_list|(
name|EXERROR
argument_list|,
name|msg
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|exerror
parameter_list|(
name|int
name|cond
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|ap
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|msg
argument_list|)
expr_stmt|;
name|exverror
argument_list|(
name|cond
argument_list|,
name|msg
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Table of error messages.  */
end_comment

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

begin_define
define|#
directive|define
name|ALL
value|(E_OPEN|E_CREAT|E_EXEC)
end_define

begin_expr_stmt
name|STATIC
specifier|const
expr|struct
name|errname
name|errormsg
index|[]
operator|=
block|{
block|{
name|EINTR
block|,
name|ALL
block|,
literal|"interrupted"
block|}
block|,
block|{
name|EACCES
block|,
name|ALL
block|,
literal|"permission denied"
block|}
block|,
block|{
name|EIO
block|,
name|ALL
block|,
literal|"I/O error"
block|}
block|,
block|{
name|ENOENT
block|,
name|E_OPEN
block|,
literal|"no such file"
block|}
block|,
block|{
name|ENOENT
block|,
name|E_CREAT
block|,
literal|"directory nonexistent"
block|}
block|,
block|{
name|ENOENT
block|,
name|E_EXEC
block|,
literal|"not found"
block|}
block|,
block|{
name|ENOTDIR
block|,
name|E_OPEN
block|,
literal|"no such file"
block|}
block|,
block|{
name|ENOTDIR
block|,
name|E_CREAT
block|,
literal|"directory nonexistent"
block|}
block|,
block|{
name|ENOTDIR
block|,
name|E_EXEC
block|,
literal|"not found"
block|}
block|,
block|{
name|EISDIR
block|,
name|ALL
block|,
literal|"is a directory"
block|}
block|,
ifdef|#
directive|ifdef
name|notdef
block|{
name|EMFILE
block|,
name|ALL
block|,
literal|"too many open files"
block|}
block|,
endif|#
directive|endif
block|{
name|ENFILE
block|,
name|ALL
block|,
literal|"file table overflow"
block|}
block|,
block|{
name|ENOSPC
block|,
name|ALL
block|,
literal|"file system full"
block|}
block|,
ifdef|#
directive|ifdef
name|EDQUOT
block|{
name|EDQUOT
block|,
name|ALL
block|,
literal|"disk quota exceeded"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ENOSR
block|{
name|ENOSR
block|,
name|ALL
block|,
literal|"no streams resources"
block|}
block|,
endif|#
directive|endif
block|{
name|ENXIO
block|,
name|ALL
block|,
literal|"no such device or address"
block|}
block|,
block|{
name|EROFS
block|,
name|ALL
block|,
literal|"read-only file system"
block|}
block|,
block|{
name|ETXTBSY
block|,
name|ALL
block|,
literal|"text busy"
block|}
block|,
ifdef|#
directive|ifdef
name|SYSV
block|{
name|EAGAIN
block|,
name|E_EXEC
block|,
literal|"not enough memory"
block|}
block|,
endif|#
directive|endif
block|{
name|ENOMEM
block|,
name|ALL
block|,
literal|"not enough memory"
block|}
block|,
ifdef|#
directive|ifdef
name|ENOLINK
block|{
name|ENOLINK
block|,
name|ALL
block|,
literal|"remote access failed"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|EMULTIHOP
block|{
name|EMULTIHOP
block|,
name|ALL
block|,
literal|"remote access failed"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ECOMM
block|{
name|ECOMM
block|,
name|ALL
block|,
literal|"remote access failed"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ESTALE
block|{
name|ESTALE
block|,
name|ALL
block|,
literal|"remote access failed"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ETIMEDOUT
block|{
name|ETIMEDOUT
block|,
name|ALL
block|,
literal|"remote access failed"
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ELOOP
block|{
name|ELOOP
block|,
name|ALL
block|,
literal|"symbolic link loop"
block|}
block|,
endif|#
directive|endif
block|{
name|E2BIG
block|,
name|E_EXEC
block|,
literal|"argument list too long"
block|}
block|,
ifdef|#
directive|ifdef
name|ELIBACC
block|{
name|ELIBACC
block|,
name|E_EXEC
block|,
literal|"shared library missing"
block|}
block|,
endif|#
directive|endif
block|{
literal|0
block|,
literal|0
block|,
name|NULL
block|}
block|, }
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
name|int
name|e
parameter_list|,
name|int
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

