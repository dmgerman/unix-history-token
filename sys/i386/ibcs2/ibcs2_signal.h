begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: ibcs2_signal.h,v 1.7 1995/08/14 02:26:01 mycroft Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1994, 1995 Scott Bartram  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Scott Bartram.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IBCS2_SIGNAL_H
end_ifndef

begin_define
define|#
directive|define
name|_IBCS2_SIGNAL_H
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGHUP
value|1
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGINT
value|2
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGQUIT
value|3
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGILL
value|4
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGTRAP
value|5
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGIOT
value|6
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGABRT
value|6
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGEMT
value|7
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGFPE
value|8
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGKILL
value|9
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGBUS
value|10
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGSEGV
value|11
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGSYS
value|12
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGPIPE
value|13
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGALRM
value|14
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGTERM
value|15
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGUSR1
value|16
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGUSR2
value|17
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGCLD
value|18
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGPWR
value|19
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGWINCH
value|20
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGPOLL
value|22
end_define

begin_define
define|#
directive|define
name|IBCS2_NSIG
value|32
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGTBLSZ
value|32
end_define

begin_comment
comment|/*  * SCO-specific  */
end_comment

begin_define
define|#
directive|define
name|IBCS2_SIGSTOP
value|23
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGTSTP
value|24
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGCONT
value|25
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGTTIN
value|26
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGTTOU
value|27
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGVTALRM
value|28
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGPROF
value|29
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGNO_MASK
value|0x00FF
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGNAL_MASK
value|0x0000
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGSET_MASK
value|0x0100
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGHOLD_MASK
value|0x0200
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGRELSE_MASK
value|0x0400
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGIGNORE_MASK
value|0x0800
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGPAUSE_MASK
value|0x1000
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGNO
parameter_list|(
name|x
parameter_list|)
value|((x)& IBCS2_SIGNO_MASK)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGCALL
parameter_list|(
name|x
parameter_list|)
value|((x)& ~IBCS2_SIGNO_MASK)
end_define

begin_typedef
typedef|typedef
name|long
name|ibcs2_sigset_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*ibcs2_sig_t
argument_list|)
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_struct
struct|struct
name|ibcs2_sigaction
block|{
name|ibcs2_sig_t
name|isa_handler
decl_stmt|;
name|ibcs2_sigset_t
name|isa_mask
decl_stmt|;
name|int
name|isa_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IBCS2_SIG_DFL
value|((ibcs2_sig_t)0)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIG_ERR
value|((ibcs2_sig_t)-1)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIG_IGN
value|((ibcs2_sig_t)1)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIG_HOLD
value|((ibcs2_sig_t)2)
end_define

begin_define
define|#
directive|define
name|IBCS2_SIG_SETMASK
value|0
end_define

begin_define
define|#
directive|define
name|IBCS2_SIG_BLOCK
value|1
end_define

begin_define
define|#
directive|define
name|IBCS2_SIG_UNBLOCK
value|2
end_define

begin_comment
comment|/* sa_flags */
end_comment

begin_define
define|#
directive|define
name|IBCS2_SA_NOCLDSTOP
value|1
end_define

begin_define
define|#
directive|define
name|IBCS2_MINSIGSTKSZ
value|8192
end_define

begin_decl_stmt
specifier|extern
name|int
name|bsd_to_ibcs2_sig
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IBCS2_SIGNAL_H */
end_comment

end_unit

