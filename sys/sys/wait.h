begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)wait.h	8.2 (Berkeley) 7/10/94  * $FreeBSD$  */
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

begin_comment
comment|/*  * This file holds definitions relevant to the wait4 system call  * and the alternate interfaces that use it (wait, wait3, waitpid).  */
end_comment

begin_comment
comment|/*  * Macros to test the exit status returned by wait  * and extract the relevant values.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_POSIX_SOURCE
end_ifdef

begin_define
define|#
directive|define
name|_W_INT
parameter_list|(
name|i
parameter_list|)
value|(i)
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
name|w
parameter_list|)
value|(*(int *)&(w))
end_define

begin_comment
comment|/* convert union wait to int */
end_comment

begin_define
define|#
directive|define
name|WCOREFLAG
value|0200
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

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

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
comment|/* don't hang in wait */
end_comment

begin_define
define|#
directive|define
name|WUNTRACED
value|2
end_define

begin_comment
comment|/* tell about stopped, untraced children */
end_comment

begin_define
define|#
directive|define
name|WLINUXCLONE
value|0x80000000
end_define

begin_comment
comment|/* wait for kthread spawned from linux_clone */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_comment
comment|/* POSIX extensions and 4.2/4.3 compatibility: */
end_comment

begin_comment
comment|/*  * Tokens for special values of the "pid" parameter to wait4.  */
end_comment

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

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_comment
comment|/*  * Deprecated:  * Structure of the information in the status word returned by wait4.  * If w_stopval==WSTOPPED, then the second structure describes  * the information returned, else the first.  */
end_comment

begin_union
union|union
name|wait
block|{
name|int
name|w_status
decl_stmt|;
comment|/* used in syscall */
comment|/* 	 * Terminated process status. 	 */
struct|struct
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
name|unsigned
name|int
name|w_Termsig
range|:
literal|7
decl_stmt|,
comment|/* termination signal */
name|w_Coredump
range|:
literal|1
decl_stmt|,
comment|/* core dump indicator */
name|w_Retcode
range|:
literal|8
decl_stmt|,
comment|/* exit code if w_termsig==0 */
name|w_Filler
range|:
literal|16
decl_stmt|;
comment|/* upper bits filler */
endif|#
directive|endif
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|unsigned
name|int
name|w_Filler
range|:
literal|16
decl_stmt|,
comment|/* upper bits filler */
name|w_Retcode
range|:
literal|8
decl_stmt|,
comment|/* exit code if w_termsig==0 */
name|w_Coredump
range|:
literal|1
decl_stmt|,
comment|/* core dump indicator */
name|w_Termsig
range|:
literal|7
decl_stmt|;
comment|/* termination signal */
endif|#
directive|endif
block|}
name|w_T
struct|;
comment|/* 	 * Stopped process status.  Returned 	 * only for traced children unless requested 	 * with the WUNTRACED option bit. 	 */
struct|struct
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
name|unsigned
name|int
name|w_Stopval
range|:
literal|8
decl_stmt|,
comment|/* == W_STOPPED if stopped */
name|w_Stopsig
range|:
literal|8
decl_stmt|,
comment|/* signal that stopped us */
name|w_Filler
range|:
literal|16
decl_stmt|;
comment|/* upper bits filler */
endif|#
directive|endif
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|unsigned
name|int
name|w_Filler
range|:
literal|16
decl_stmt|,
comment|/* upper bits filler */
name|w_Stopsig
range|:
literal|8
decl_stmt|,
comment|/* signal that stopped us */
name|w_Stopval
range|:
literal|8
decl_stmt|;
comment|/* == W_STOPPED if stopped */
endif|#
directive|endif
block|}
name|w_S
struct|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|w_termsig
value|w_T.w_Termsig
end_define

begin_define
define|#
directive|define
name|w_coredump
value|w_T.w_Coredump
end_define

begin_define
define|#
directive|define
name|w_retcode
value|w_T.w_Retcode
end_define

begin_define
define|#
directive|define
name|w_stopval
value|w_S.w_Stopval
end_define

begin_define
define|#
directive|define
name|w_stopsig
value|w_S.w_Stopsig
end_define

begin_define
define|#
directive|define
name|WSTOPPED
value|_WSTOPPED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIX_SOURCE */
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

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_macro
name|__BEGIN_DECLS
end_macro

begin_struct_decl
struct_decl|struct
name|rusage
struct_decl|;
end_struct_decl

begin_comment
comment|/* forward declaration */
end_comment

begin_decl_stmt
name|pid_t
name|wait
name|__P
argument_list|(
operator|(
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|pid_t
name|waitpid
name|__P
argument_list|(
operator|(
name|pid_t
operator|,
name|int
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_decl_stmt
name|pid_t
name|wait3
name|__P
argument_list|(
operator|(
name|int
operator|*
operator|,
name|int
operator|,
expr|struct
name|rusage
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|pid_t
name|wait4
name|__P
argument_list|(
operator|(
name|pid_t
operator|,
name|int
operator|*
operator|,
name|int
operator|,
expr|struct
name|rusage
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_endif
endif|#
directive|endif
end_endif

end_unit

