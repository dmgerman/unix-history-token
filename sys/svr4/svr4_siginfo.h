begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 Mark Newton  * Copyright (c) 1994 Christos Zoulas  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SVR4_SIGINFO_H_
end_ifndef

begin_define
define|#
directive|define
name|_SVR4_SIGINFO_H_
end_define

begin_define
define|#
directive|define
name|SVR4_ILL_ILLOPC
value|1
end_define

begin_define
define|#
directive|define
name|SVR4_ILL_ILLOPN
value|2
end_define

begin_define
define|#
directive|define
name|SVR4_ILL_ILLADR
value|3
end_define

begin_define
define|#
directive|define
name|SVR4_ILL_ILLTRP
value|4
end_define

begin_define
define|#
directive|define
name|SVR4_ILL_PRVOPC
value|5
end_define

begin_define
define|#
directive|define
name|SVR4_ILL_PRVREG
value|6
end_define

begin_define
define|#
directive|define
name|SVR4_ILL_COPROC
value|7
end_define

begin_define
define|#
directive|define
name|SVR4_ILL_BADSTK
value|8
end_define

begin_define
define|#
directive|define
name|SVR4_FPE_INTDIV
value|1
end_define

begin_define
define|#
directive|define
name|SVR4_FPE_INTOVF
value|2
end_define

begin_define
define|#
directive|define
name|SVR4_FPE_FLTDIV
value|3
end_define

begin_define
define|#
directive|define
name|SVR4_FPE_FLTOVF
value|4
end_define

begin_define
define|#
directive|define
name|SVR4_FPE_FLTUND
value|5
end_define

begin_define
define|#
directive|define
name|SVR4_FPE_FLTRES
value|6
end_define

begin_define
define|#
directive|define
name|SVR4_FPE_FLTINV
value|7
end_define

begin_define
define|#
directive|define
name|SVR4_FPE_FLTSUB
value|8
end_define

begin_define
define|#
directive|define
name|SVR4_SEGV_MAPERR
value|1
end_define

begin_define
define|#
directive|define
name|SVR4_SEGV_ACCERR
value|2
end_define

begin_define
define|#
directive|define
name|SVR4_BUS_ADRALN
value|1
end_define

begin_define
define|#
directive|define
name|SVR4_BUS_ADRERR
value|2
end_define

begin_define
define|#
directive|define
name|SVR4_BUS_OBJERR
value|3
end_define

begin_define
define|#
directive|define
name|SVR4_TRAP_BRKPT
value|1
end_define

begin_define
define|#
directive|define
name|SVR4_TRAP_TRACE
value|2
end_define

begin_define
define|#
directive|define
name|SVR4_POLL_IN
value|1
end_define

begin_define
define|#
directive|define
name|SVR4_POLL_OUT
value|2
end_define

begin_define
define|#
directive|define
name|SVR4_POLL_MSG
value|3
end_define

begin_define
define|#
directive|define
name|SVR4_POLL_ERR
value|4
end_define

begin_define
define|#
directive|define
name|SVR4_POLL_PRI
value|5
end_define

begin_define
define|#
directive|define
name|SVR4_CLD_EXITED
value|1
end_define

begin_define
define|#
directive|define
name|SVR4_CLD_KILLED
value|2
end_define

begin_define
define|#
directive|define
name|SVR4_CLD_DUMPED
value|3
end_define

begin_define
define|#
directive|define
name|SVR4_CLD_TRAPPED
value|4
end_define

begin_define
define|#
directive|define
name|SVR4_CLD_STOPPED
value|5
end_define

begin_define
define|#
directive|define
name|SVR4_CLD_CONTINUED
value|6
end_define

begin_define
define|#
directive|define
name|SVR4_EMT_TAGOVF
value|1
end_define

begin_typedef
typedef|typedef
union|union
name|svr4_siginfo
block|{
name|char
name|si_pad
index|[
literal|128
index|]
decl_stmt|;
comment|/* Total size; for future expansion */
struct|struct
block|{
name|int
name|_signo
decl_stmt|;
name|int
name|_code
decl_stmt|;
name|int
name|_errno
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|svr4_pid_t
name|_pid
decl_stmt|;
name|svr4_clock_t
name|_utime
decl_stmt|;
name|int
name|_status
decl_stmt|;
name|svr4_clock_t
name|_stime
decl_stmt|;
block|}
name|_child
struct|;
struct|struct
block|{
name|caddr_t
name|_addr
decl_stmt|;
name|int
name|_trap
decl_stmt|;
block|}
name|_fault
struct|;
block|}
name|_reason
union|;
block|}
name|_info
struct|;
block|}
name|svr4_siginfo_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|si_signo
value|_info._signo
end_define

begin_define
define|#
directive|define
name|si_code
value|_info._code
end_define

begin_define
define|#
directive|define
name|si_errno
value|_info._errno
end_define

begin_define
define|#
directive|define
name|si_pid
value|_info._reason._child._pid
end_define

begin_define
define|#
directive|define
name|si_stime
value|_info._reason._child._stime
end_define

begin_define
define|#
directive|define
name|si_status
value|_info._reason._child._status
end_define

begin_define
define|#
directive|define
name|si_utime
value|_info._reason._child._utime
end_define

begin_define
define|#
directive|define
name|si_addr
value|_info._reason._fault._addr
end_define

begin_define
define|#
directive|define
name|si_trap
value|_info._reason._fault._trap
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SVR4_SIGINFO_H_ */
end_comment

end_unit

