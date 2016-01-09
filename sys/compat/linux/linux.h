begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Dmitry Chagin  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_MI_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_MI_H_
end_define

begin_comment
comment|/* sigaltstack */
end_comment

begin_define
define|#
directive|define
name|LINUX_SS_ONSTACK
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_SS_DISABLE
value|2
end_define

begin_function_decl
name|int
name|linux_to_bsd_sigaltstack
parameter_list|(
name|int
name|lsa
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bsd_to_linux_sigaltstack
parameter_list|(
name|int
name|bsa
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* sigset */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint64_t
name|__mask
decl_stmt|;
block|}
name|l_sigset_t
typedef|;
end_typedef

begin_comment
comment|/* primitives to manipulate sigset_t */
end_comment

begin_define
define|#
directive|define
name|LINUX_SIGEMPTYSET
parameter_list|(
name|set
parameter_list|)
value|(set).__mask = 0
end_define

begin_define
define|#
directive|define
name|LINUX_SIGISMEMBER
parameter_list|(
name|set
parameter_list|,
name|sig
parameter_list|)
value|(1UL& ((set).__mask>> _SIG_IDX(sig)))
end_define

begin_define
define|#
directive|define
name|LINUX_SIGADDSET
parameter_list|(
name|set
parameter_list|,
name|sig
parameter_list|)
value|(set).__mask |= 1UL<< _SIG_IDX(sig)
end_define

begin_function_decl
name|void
name|linux_to_bsd_sigset
parameter_list|(
name|l_sigset_t
modifier|*
parameter_list|,
name|sigset_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bsd_to_linux_sigset
parameter_list|(
name|sigset_t
modifier|*
parameter_list|,
name|l_sigset_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* signaling */
end_comment

begin_define
define|#
directive|define
name|LINUX_SIGHUP
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_SIGINT
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_SIGQUIT
value|3
end_define

begin_define
define|#
directive|define
name|LINUX_SIGILL
value|4
end_define

begin_define
define|#
directive|define
name|LINUX_SIGTRAP
value|5
end_define

begin_define
define|#
directive|define
name|LINUX_SIGABRT
value|6
end_define

begin_define
define|#
directive|define
name|LINUX_SIGIOT
value|LINUX_SIGABRT
end_define

begin_define
define|#
directive|define
name|LINUX_SIGBUS
value|7
end_define

begin_define
define|#
directive|define
name|LINUX_SIGFPE
value|8
end_define

begin_define
define|#
directive|define
name|LINUX_SIGKILL
value|9
end_define

begin_define
define|#
directive|define
name|LINUX_SIGUSR1
value|10
end_define

begin_define
define|#
directive|define
name|LINUX_SIGSEGV
value|11
end_define

begin_define
define|#
directive|define
name|LINUX_SIGUSR2
value|12
end_define

begin_define
define|#
directive|define
name|LINUX_SIGPIPE
value|13
end_define

begin_define
define|#
directive|define
name|LINUX_SIGALRM
value|14
end_define

begin_define
define|#
directive|define
name|LINUX_SIGTERM
value|15
end_define

begin_define
define|#
directive|define
name|LINUX_SIGSTKFLT
value|16
end_define

begin_define
define|#
directive|define
name|LINUX_SIGCHLD
value|17
end_define

begin_define
define|#
directive|define
name|LINUX_SIGCONT
value|18
end_define

begin_define
define|#
directive|define
name|LINUX_SIGSTOP
value|19
end_define

begin_define
define|#
directive|define
name|LINUX_SIGTSTP
value|20
end_define

begin_define
define|#
directive|define
name|LINUX_SIGTTIN
value|21
end_define

begin_define
define|#
directive|define
name|LINUX_SIGTTOU
value|22
end_define

begin_define
define|#
directive|define
name|LINUX_SIGURG
value|23
end_define

begin_define
define|#
directive|define
name|LINUX_SIGXCPU
value|24
end_define

begin_define
define|#
directive|define
name|LINUX_SIGXFSZ
value|25
end_define

begin_define
define|#
directive|define
name|LINUX_SIGVTALRM
value|26
end_define

begin_define
define|#
directive|define
name|LINUX_SIGPROF
value|27
end_define

begin_define
define|#
directive|define
name|LINUX_SIGWINCH
value|28
end_define

begin_define
define|#
directive|define
name|LINUX_SIGIO
value|29
end_define

begin_define
define|#
directive|define
name|LINUX_SIGPOLL
value|LINUX_SIGIO
end_define

begin_define
define|#
directive|define
name|LINUX_SIGPWR
value|30
end_define

begin_define
define|#
directive|define
name|LINUX_SIGSYS
value|31
end_define

begin_define
define|#
directive|define
name|LINUX_SIGTBLSZ
value|31
end_define

begin_define
define|#
directive|define
name|LINUX_SIGRTMIN
value|32
end_define

begin_define
define|#
directive|define
name|LINUX_SIGRTMAX
value|64
end_define

begin_define
define|#
directive|define
name|LINUX_SIG_VALID
parameter_list|(
name|sig
parameter_list|)
value|((sig)<= LINUX_SIGRTMAX&& (sig)> 0)
end_define

begin_function_decl
name|int
name|linux_to_bsd_signal
parameter_list|(
name|int
name|sig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bsd_to_linux_signal
parameter_list|(
name|int
name|sig
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_MI_H_ */
end_comment

end_unit

