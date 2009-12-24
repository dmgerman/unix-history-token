begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

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

begin_decl_stmt
specifier|static
name|void
name|exverror
argument_list|(
name|int
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
name|va_list
argument_list|)
name|__printf0like
argument_list|(
literal|2
argument_list|,
literal|0
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Called to raise an exception.  Since C doesn't include exceptions, we  * just do a longjmp to the exception handler.  The type of exception is  * stored in the global variable "exception".  *  * Interrupts are disabled; they should be reenabled when the exception is  * caught.  */
end_comment

begin_function
name|void
name|exraise
parameter_list|(
name|int
name|e
parameter_list|)
block|{
name|INTOFF
expr_stmt|;
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
block|if (tcgetpgrp(0) == getpid()) 		write(STDERR_FILENO, "\n", 1);
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
comment|/* 	 * An interrupt trumps an error.  Certain places catch error 	 * exceptions or transform them to a plain nonzero exit code 	 * in child processes, and if an error exception can be handled, 	 * an interrupt can be handled as well. 	 * 	 * exraise() will disable interrupts for the exception handler. 	 */
name|FORCEINTON
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

end_unit

