begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 Mark Newton  * Copyright (c) 1994 Christos Zoulas  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SVR4_SIGNAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SVR4_SIGNAL_H_
end_define

begin_include
include|#
directive|include
file|<i386/svr4/svr4_machdep.h>
end_include

begin_include
include|#
directive|include
file|<compat/svr4/svr4_siginfo.h>
end_include

begin_define
define|#
directive|define
name|SVR4_SIGHUP
value|1
end_define

begin_define
define|#
directive|define
name|SVR4_SIGINT
value|2
end_define

begin_define
define|#
directive|define
name|SVR4_SIGQUIT
value|3
end_define

begin_define
define|#
directive|define
name|SVR4_SIGILL
value|4
end_define

begin_define
define|#
directive|define
name|SVR4_SIGTRAP
value|5
end_define

begin_define
define|#
directive|define
name|SVR4_SIGIOT
value|6
end_define

begin_define
define|#
directive|define
name|SVR4_SIGABRT
value|6
end_define

begin_define
define|#
directive|define
name|SVR4_SIGEMT
value|7
end_define

begin_define
define|#
directive|define
name|SVR4_SIGFPE
value|8
end_define

begin_define
define|#
directive|define
name|SVR4_SIGKILL
value|9
end_define

begin_define
define|#
directive|define
name|SVR4_SIGBUS
value|10
end_define

begin_define
define|#
directive|define
name|SVR4_SIGSEGV
value|11
end_define

begin_define
define|#
directive|define
name|SVR4_SIGSYS
value|12
end_define

begin_define
define|#
directive|define
name|SVR4_SIGPIPE
value|13
end_define

begin_define
define|#
directive|define
name|SVR4_SIGALRM
value|14
end_define

begin_define
define|#
directive|define
name|SVR4_SIGTERM
value|15
end_define

begin_define
define|#
directive|define
name|SVR4_SIGUSR1
value|16
end_define

begin_define
define|#
directive|define
name|SVR4_SIGUSR2
value|17
end_define

begin_define
define|#
directive|define
name|SVR4_SIGCLD
value|18
end_define

begin_define
define|#
directive|define
name|SVR4_SIGCHLD
value|18
end_define

begin_define
define|#
directive|define
name|SVR4_SIGPWR
value|19
end_define

begin_define
define|#
directive|define
name|SVR4_SIGWINCH
value|20
end_define

begin_define
define|#
directive|define
name|SVR4_SIGURG
value|21
end_define

begin_define
define|#
directive|define
name|SVR4_SIGPOLL
value|22
end_define

begin_define
define|#
directive|define
name|SVR4_SIGIO
value|22
end_define

begin_define
define|#
directive|define
name|SVR4_SIGSTOP
value|23
end_define

begin_define
define|#
directive|define
name|SVR4_SIGTSTP
value|24
end_define

begin_define
define|#
directive|define
name|SVR4_SIGCONT
value|25
end_define

begin_define
define|#
directive|define
name|SVR4_SIGTTIN
value|26
end_define

begin_define
define|#
directive|define
name|SVR4_SIGTTOU
value|27
end_define

begin_define
define|#
directive|define
name|SVR4_SIGVTALRM
value|28
end_define

begin_define
define|#
directive|define
name|SVR4_SIGPROF
value|29
end_define

begin_define
define|#
directive|define
name|SVR4_SIGXCPU
value|30
end_define

begin_define
define|#
directive|define
name|SVR4_SIGXFSZ
value|31
end_define

begin_define
define|#
directive|define
name|SVR4_NSIG
value|32
end_define

begin_define
define|#
directive|define
name|SVR4_SIGTBLSZ
value|31
end_define

begin_define
define|#
directive|define
name|SVR4_SIGNO_MASK
value|0x00FF
end_define

begin_define
define|#
directive|define
name|SVR4_SIGNAL_MASK
value|0x0000
end_define

begin_define
define|#
directive|define
name|SVR4_SIGDEFER_MASK
value|0x0100
end_define

begin_define
define|#
directive|define
name|SVR4_SIGHOLD_MASK
value|0x0200
end_define

begin_define
define|#
directive|define
name|SVR4_SIGRELSE_MASK
value|0x0400
end_define

begin_define
define|#
directive|define
name|SVR4_SIGIGNORE_MASK
value|0x0800
end_define

begin_define
define|#
directive|define
name|SVR4_SIGPAUSE_MASK
value|0x1000
end_define

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|svr4_sig_t
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|svr4_siginfo_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|SVR4_SIG_DFL
value|(svr4_sig_t)	 0
end_define

begin_define
define|#
directive|define
name|SVR4_SIG_ERR
value|(svr4_sig_t)	-1
end_define

begin_define
define|#
directive|define
name|SVR4_SIG_IGN
value|(svr4_sig_t)	 1
end_define

begin_define
define|#
directive|define
name|SVR4_SIG_HOLD
value|(svr4_sig_t)	 2
end_define

begin_define
define|#
directive|define
name|SVR4_SIGNO
parameter_list|(
name|a
parameter_list|)
value|((a)& SVR4_SIGNO_MASK)
end_define

begin_define
define|#
directive|define
name|SVR4_SIGCALL
parameter_list|(
name|a
parameter_list|)
value|((a)& ~SVR4_SIGNO_MASK)
end_define

begin_define
define|#
directive|define
name|SVR4_SIG_BLOCK
value|1
end_define

begin_define
define|#
directive|define
name|SVR4_SIG_UNBLOCK
value|2
end_define

begin_define
define|#
directive|define
name|SVR4_SIG_SETMASK
value|3
end_define

begin_decl_stmt
specifier|extern
name|int
name|bsd_to_svr4_sig
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|svr4_to_bsd_sig
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SVR4_BSD2SVR4_SIG
parameter_list|(
name|sig
parameter_list|)
define|\
value|(((sig)<= SVR4_SIGTBLSZ) ? bsd_to_svr4_sig[_SIG_IDX(sig)] : sig)
end_define

begin_define
define|#
directive|define
name|SVR4_SVR42BSD_SIG
parameter_list|(
name|sig
parameter_list|)
define|\
value|(((sig)<= SVR4_SIGTBLSZ) ? svr4_to_bsd_sig[_SIG_IDX(sig)] : sig)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_long
name|bits
index|[
literal|4
index|]
decl_stmt|;
block|}
name|svr4_sigset_t
typedef|;
end_typedef

begin_struct
struct|struct
name|svr4_sigaction
block|{
name|int
name|ssa_flags
decl_stmt|;
name|svr4_sig_t
name|ssa_handler
decl_stmt|;
name|svr4_sigset_t
name|ssa_mask
decl_stmt|;
name|int
name|ssa_reserved
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|svr4_sigaltstack
block|{
name|char
modifier|*
name|ss_sp
decl_stmt|;
name|int
name|ss_size
decl_stmt|;
name|int
name|ss_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* sa_flags */
end_comment

begin_define
define|#
directive|define
name|SVR4_SA_ONSTACK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SVR4_SA_RESETHAND
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SVR4_SA_RESTART
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SVR4_SA_SIGINFO
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SVR4_SA_NODEFER
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SVR4_SA_NOCLDWAIT
value|0x00010000
end_define

begin_comment
comment|/* No zombies 	*/
end_comment

begin_define
define|#
directive|define
name|SVR4_SA_NOCLDSTOP
value|0x00020000
end_define

begin_comment
comment|/* No jcl	*/
end_comment

begin_define
define|#
directive|define
name|SVR4_SA_ALLBITS
value|0x0003001f
end_define

begin_comment
comment|/* ss_flags */
end_comment

begin_define
define|#
directive|define
name|SVR4_SS_ONSTACK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SVR4_SS_DISABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SVR4_SS_ALLBITS
value|0x00000003
end_define

begin_define
define|#
directive|define
name|SVR4_MINSIGSTKSZ
value|8192
end_define

begin_function_decl
name|void
name|bsd_to_svr4_sigaltstack
parameter_list|(
specifier|const
name|struct
name|sigaltstack
modifier|*
parameter_list|,
name|struct
name|svr4_sigaltstack
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bsd_to_svr4_sigset
parameter_list|(
specifier|const
name|sigset_t
modifier|*
parameter_list|,
name|svr4_sigset_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|svr4_to_bsd_sigaltstack
parameter_list|(
specifier|const
name|struct
name|svr4_sigaltstack
modifier|*
parameter_list|,
name|struct
name|sigaltstack
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|svr4_to_bsd_sigset
parameter_list|(
specifier|const
name|svr4_sigset_t
modifier|*
parameter_list|,
name|sigset_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|svr4_sendsig
parameter_list|(
name|sig_t
parameter_list|,
name|int
parameter_list|,
name|sigset_t
modifier|*
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SVR4_SIGNAL_H_ */
end_comment

end_unit

