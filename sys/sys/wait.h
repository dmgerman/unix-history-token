begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1989, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)wait.h	8.2 (Berkeley) 7/10/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_WAIT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_WAIT_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/*  * This file holds definitions relevant to the wait4 system call and the  * alternate interfaces that use it (wait, wait3, waitpid).  */
end_comment

begin_comment
comment|/*  * Macros to test the exit status returned by wait and extract the relevant  * values.  */
end_comment

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|_W_INT
parameter_list|(
name|w
parameter_list|)
value|(*(int *)&(w))
end_define

begin_comment
comment|/* Convert union wait to int. */
end_comment

begin_define
define|#
directive|define
name|WCOREFLAG
value|0200
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_W_INT
parameter_list|(
name|i
parameter_list|)
value|(i)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_WSTATUS
parameter_list|(
name|x
parameter_list|)
value|(_W_INT(x)& 0177)
end_define

begin_define
define|#
directive|define
name|_WSTOPPED
value|0177
end_define

begin_comment
comment|/* _WSTATUS if process is stopped */
end_comment

begin_define
define|#
directive|define
name|WIFSTOPPED
parameter_list|(
name|x
parameter_list|)
value|(_WSTATUS(x) == _WSTOPPED)
end_define

begin_define
define|#
directive|define
name|WSTOPSIG
parameter_list|(
name|x
parameter_list|)
value|(_W_INT(x)>> 8)
end_define

begin_define
define|#
directive|define
name|WIFSIGNALED
parameter_list|(
name|x
parameter_list|)
value|(_WSTATUS(x) != _WSTOPPED&& _WSTATUS(x) != 0)
end_define

begin_define
define|#
directive|define
name|WTERMSIG
parameter_list|(
name|x
parameter_list|)
value|(_WSTATUS(x))
end_define

begin_define
define|#
directive|define
name|WIFEXITED
parameter_list|(
name|x
parameter_list|)
value|(_WSTATUS(x) == 0)
end_define

begin_define
define|#
directive|define
name|WEXITSTATUS
parameter_list|(
name|x
parameter_list|)
value|(_W_INT(x)>> 8)
end_define

begin_define
define|#
directive|define
name|WIFCONTINUED
parameter_list|(
name|x
parameter_list|)
value|(x == 0x13)
end_define

begin_comment
comment|/* 0x13 == SIGCONT */
end_comment

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|WCOREDUMP
parameter_list|(
name|x
parameter_list|)
value|(_W_INT(x)& WCOREFLAG)
end_define

begin_define
define|#
directive|define
name|W_EXITCODE
parameter_list|(
name|ret
parameter_list|,
name|sig
parameter_list|)
value|((ret)<< 8 | (sig))
end_define

begin_define
define|#
directive|define
name|W_STOPCODE
parameter_list|(
name|sig
parameter_list|)
value|((sig)<< 8 | _WSTOPPED)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Option bits for the third argument of wait4.  WNOHANG causes the  * wait to not hang if there are no stopped or terminated processes, rather  * returning an error indication in this case (pid==0).  WUNTRACED  * indicates that the caller should receive status about untraced children  * which stop due to signals.  If children are stopped and a wait without  * this option is done, it is as though they were still running... nothing  * about them is returned.  */
end_comment

begin_define
define|#
directive|define
name|WNOHANG
value|1
end_define

begin_comment
comment|/* Don't hang in wait. */
end_comment

begin_define
define|#
directive|define
name|WUNTRACED
value|2
end_define

begin_comment
comment|/* Tell about stopped, untraced children. */
end_comment

begin_define
define|#
directive|define
name|WCONTINUED
value|4
end_define

begin_comment
comment|/* Report a job control continued process. */
end_comment

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|WLINUXCLONE
value|0x80000000
end_define

begin_comment
comment|/* Wait for kthread spawned from linux_clone. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Tokens for special values of the "pid" parameter to wait4.  */
end_comment

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|WAIT_ANY
value|(-1)
end_define

begin_comment
comment|/* any process */
end_comment

begin_define
define|#
directive|define
name|WAIT_MYPGRP
value|0
end_define

begin_comment
comment|/* any process in my process group */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BSD_VISIBLE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_function_decl
name|__BEGIN_DECLS
name|pid_t
name|wait
parameter_list|(
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pid_t
name|waitpid
parameter_list|(
name|pid_t
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_struct_decl
struct_decl|struct
name|rusage
struct_decl|;
end_struct_decl

begin_function_decl
name|pid_t
name|wait3
parameter_list|(
name|int
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|rusage
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pid_t
name|wait4
parameter_list|(
name|pid_t
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|rusage
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_WAIT_H_ */
end_comment

end_unit

