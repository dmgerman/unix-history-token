begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)error.c	5.2 (Berkeley) %G%"
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
file|<signal.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_include
include|#
directive|include
file|"stdarg.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
name|int
name|exception
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|int
name|suppressint
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|int
name|intpending
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|commandname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Called to raise an exception.  Since C doesn't include exceptions, we  * just do a longjmp to the exception handler.  The type of exception is  * stored in the global variable "exception".  */
end_comment

begin_function
name|void
name|exraise
parameter_list|(
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
comment|/*  * Called from trap.c when a SIGINT is received.  (If the user specifies  * that SIGINT is to be trapped or ignored using the trap builtin, then  * this routine is not called.)  Suppressint is nonzero when interrupts  * are held using the INTOFF macro.  The call to _exit is necessary because  * there is a short period after a fork before the signal handlers are  * set to the appropriate value for the child.  (The test for iflag is  * just defensive programming.)  */
end_comment

begin_function
name|void
name|onint
parameter_list|()
block|{
if|if
condition|(
name|suppressint
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
ifdef|#
directive|ifdef
name|BSD
name|sigsetmask
argument_list|(
literal|0
argument_list|)
expr_stmt|;
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
name|_exit
argument_list|(
literal|128
operator|+
name|SIGINT
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|error2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|char
modifier|*
name|a
decl_stmt|,
decl|*
name|b
decl_stmt|;
end_function

begin_block
block|{
name|error
argument_list|(
literal|"%s: %s"
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Error is called to raise the error exception.  If the first argument  * is not NULL then error prints an error message using printf style  * formatting.  It then raises the error exception.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function
name|void
name|error
parameter_list|(
name|char
modifier|*
name|msg
parameter_list|,
modifier|...
parameter_list|)
block|{
else|#
directive|else
name|void
name|error
parameter_list|(
name|va_alist
parameter_list|)
function|va_dcl
block|{
name|char
modifier|*
name|msg
decl_stmt|;
endif|#
directive|endif
name|va_list
name|ap
decl_stmt|;
name|CLEAR_PENDING_INT
expr_stmt|;
name|INTOFF
expr_stmt|;
ifdef|#
directive|ifdef
name|__STDC__
name|va_start
argument_list|(
name|ap
argument_list|,
name|msg
argument_list|)
expr_stmt|;
else|#
directive|else
name|va_start
argument_list|(
name|ap
argument_list|)
expr_stmt|;
name|msg
operator|=
name|va_arg
argument_list|(
name|ap
argument_list|,
name|char
operator|*
argument_list|)
expr_stmt|;
endif|#
directive|endif
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
literal|"error(\"%s\") pid=%d\n"
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
literal|"error(NULL) pid=%d\n"
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
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
name|flushall
argument_list|()
expr_stmt|;
name|exraise
argument_list|(
name|EXERROR
argument_list|)
expr_stmt|;
block|}
comment|/*  * Table of error messages.  */
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
define|#
directive|define
name|ALL
value|(E_OPEN|E_CREAT|E_EXEC)
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
block|,
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
comment|/*  * Return a string describing an error.  The returned string may be a  * pointer to a static buffer that will be overwritten on the next call.  * Action describes the operation that got the error.  */
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

