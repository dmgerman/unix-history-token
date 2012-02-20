begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|// signal.h: signal emulation things
end_comment

begin_comment
comment|// -amol
end_comment

begin_comment
comment|//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIGNAL_H
end_ifndef

begin_define
define|#
directive|define
name|SIGNAL_H
end_define

begin_define
define|#
directive|define
name|NSIG
value|23
end_define

begin_comment
comment|// These must be CTRL_xxx_EVENT+1 (in wincon.h)
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|SIGINT
value|1
end_define

begin_define
define|#
directive|define
name|SIGBREAK
value|2
end_define

begin_define
define|#
directive|define
name|SIGHUP
value|3
end_define

begin_comment
comment|//CTRL_CLOSE_EVENT
end_comment

begin_comment
comment|// 3 and 4 are reserved. hence we can't use 4 and 5
end_comment

begin_define
define|#
directive|define
name|SIGTERM
value|6
end_define

begin_comment
comment|// ctrl_logoff
end_comment

begin_define
define|#
directive|define
name|SIGKILL
value|7
end_define

begin_comment
comment|// ctrl_shutdown
end_comment

begin_define
define|#
directive|define
name|SIGILL
value|8
end_define

begin_define
define|#
directive|define
name|SIGFPE
value|9
end_define

begin_define
define|#
directive|define
name|SIGALRM
value|10
end_define

begin_comment
comment|//#define SIGWINCH	11
end_comment

begin_define
define|#
directive|define
name|SIGSEGV
value|12
end_define

begin_define
define|#
directive|define
name|SIGSTOP
value|13
end_define

begin_define
define|#
directive|define
name|SIGPIPE
value|14
end_define

begin_define
define|#
directive|define
name|SIGCHLD
value|15
end_define

begin_define
define|#
directive|define
name|SIGCONT
value|16
end_define

begin_define
define|#
directive|define
name|SIGTSTP
value|18
end_define

begin_define
define|#
directive|define
name|SIGTTOU
value|19
end_define

begin_define
define|#
directive|define
name|SIGTTIN
value|20
end_define

begin_define
define|#
directive|define
name|SIGABRT
value|22
end_define

begin_define
define|#
directive|define
name|SIGQUIT
value|SIGBREAK
end_define

begin_comment
comment|/* signal action codes */
end_comment

begin_define
define|#
directive|define
name|SIG_DFL
value|(void (*)(int))IntToPtr(0)
end_define

begin_comment
comment|/* default signal action */
end_comment

begin_define
define|#
directive|define
name|SIG_IGN
value|(void (*)(int))IntToPtr(1)
end_define

begin_comment
comment|/* ignore signal */
end_comment

begin_define
define|#
directive|define
name|SIG_SGE
value|(void (*)(int))IntToPtr(3)
end_define

begin_comment
comment|/* signal gets error */
end_comment

begin_define
define|#
directive|define
name|SIG_ACK
value|(void (*)(int))IntToPtr(4)
end_define

begin_comment
comment|/* acknowledge */
end_comment

begin_comment
comment|/* signal error value (returned by signal call on error) */
end_comment

begin_define
define|#
directive|define
name|SIG_ERR
value|(void (*)(int))IntToPtr(-1)
end_define

begin_comment
comment|/* signal error value */
end_comment

begin_define
define|#
directive|define
name|SIG_BLOCK
value|0
end_define

begin_define
define|#
directive|define
name|SIG_UNBLOCK
value|1
end_define

begin_define
define|#
directive|define
name|SIG_SETMASK
value|2
end_define

begin_undef
undef|#
directive|undef
name|signal
end_undef

begin_define
define|#
directive|define
name|signal
value|_nt_signal
end_define

begin_typedef
typedef|typedef
name|unsigned
name|long
name|sigset_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|Sigfunc
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|sigaction
block|{
name|Sigfunc
modifier|*
name|sa_handler
decl_stmt|;
name|sigset_t
name|sa_mask
decl_stmt|;
name|int
name|sa_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|sigemptyset
parameter_list|(
name|ptr
parameter_list|)
value|(*(ptr) = 0)
end_define

begin_define
define|#
directive|define
name|sigfillset
parameter_list|(
name|ptr
parameter_list|)
value|( *(ptr) = ~(sigset_t)0,0)
end_define

begin_comment
comment|/* Function prototypes */
end_comment

begin_expr_stmt
name|void
argument_list|(
operator|*
name|_nt_signal
argument_list|(
name|int
argument_list|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
argument_list|(
name|int
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|int
name|sigaddset
parameter_list|(
name|sigset_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigdelset
parameter_list|(
name|sigset_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|alarm
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigismember
parameter_list|(
specifier|const
name|sigset_t
modifier|*
name|set
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigprocmask
parameter_list|(
name|int
parameter_list|,
specifier|const
name|sigset_t
modifier|*
parameter_list|,
name|sigset_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigaction
parameter_list|(
name|int
parameter_list|,
specifier|const
name|struct
name|sigaction
modifier|*
parameter_list|,
name|struct
name|sigaction
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigsuspend
parameter_list|(
specifier|const
name|sigset_t
modifier|*
name|sigmask
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|WNOHANG
value|0
end_define

begin_define
define|#
directive|define
name|WUNTRACED
value|1
end_define

begin_define
define|#
directive|define
name|WIFEXITED
parameter_list|(
name|a
parameter_list|)
value|1
end_define

begin_define
define|#
directive|define
name|WEXITSTATUS
parameter_list|(
name|a
parameter_list|)
value|(a)
end_define

begin_comment
comment|//#define WIFSIGNALED(a) ((a!= -1)&&(((((unsigned long)(a))>>24)& 0xC0)!=0))
end_comment

begin_define
define|#
directive|define
name|WIFSIGNALED
parameter_list|(
name|a
parameter_list|)
value|((a !=-1)&&((((unsigned long)(a))& 0xC0000000 ) != 0))
end_define

begin_define
define|#
directive|define
name|WTERMSIG
parameter_list|(
name|a
parameter_list|)
value|(((unsigned long)(a))==0xC000013AL?SIGINT:SIGSEGV)
end_define

begin_define
define|#
directive|define
name|WCOREDUMP
parameter_list|(
name|a
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|WIFSTOPPED
parameter_list|(
name|a
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|WSTOPSIG
parameter_list|(
name|a
parameter_list|)
value|0
end_define

begin_function_decl
name|int
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

begin_function_decl
name|int
name|times
parameter_list|(
name|struct
name|tms
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
endif|SIGNAL_H
end_endif

end_unit

