begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 Mark Newton  * Copyright (c) 1994 Christos Zoulas  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SVR4_UCONTEXT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SVR4_UCONTEXT_H_
end_define

begin_comment
comment|/*  * Machine context  */
end_comment

begin_define
define|#
directive|define
name|SVR4_UC_SIGMASK
value|0x01
end_define

begin_define
define|#
directive|define
name|SVR4_UC_STACK
value|0x02
end_define

begin_define
define|#
directive|define
name|SVR4_UC_CPU
value|0x04
end_define

begin_define
define|#
directive|define
name|SVR4_UC_FPU
value|0x08
end_define

begin_define
define|#
directive|define
name|SVR4_UC_WEITEK
value|0x10
end_define

begin_define
define|#
directive|define
name|SVR4_UC_MCONTEXT
value|(SVR4_UC_CPU|SVR4_UC_FPU|SVR4_UC_WEITEK)
end_define

begin_define
define|#
directive|define
name|SVR4_UC_ALL
value|(SVR4_UC_SIGMASK|SVR4_UC_STACK|SVR4_UC_MCONTEXT)
end_define

begin_typedef
typedef|typedef
struct|struct
name|svr4_ucontext
block|{
name|u_long
name|uc_flags
decl_stmt|;
comment|/*	struct svr4_ucontext	*uc_link;*/
name|void
modifier|*
name|uc_link
decl_stmt|;
name|svr4_sigset_t
name|uc_sigmask
decl_stmt|;
name|struct
name|svr4_sigaltstack
name|uc_stack
decl_stmt|;
name|svr4_mcontext_t
name|uc_mcontext
decl_stmt|;
name|long
name|uc_pad
index|[
literal|5
index|]
decl_stmt|;
block|}
name|svr4_ucontext_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SVR4_UC_GETREGSET
value|0
end_define

begin_define
define|#
directive|define
name|SVR4_UC_SETREGSET
value|1
end_define

begin_comment
comment|/*  * Signal frame  */
end_comment

begin_struct
struct|struct
name|svr4_sigframe
block|{
name|int
name|sf_signum
decl_stmt|;
name|union
name|svr4_siginfo
modifier|*
name|sf_sip
decl_stmt|;
name|struct
name|svr4_ucontext
modifier|*
name|sf_ucp
decl_stmt|;
name|sig_t
name|sf_handler
decl_stmt|;
name|struct
name|svr4_ucontext
name|sf_uc
decl_stmt|;
name|union
name|svr4_siginfo
name|sf_si
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SVR4_UCONTEXT_H_ */
end_comment

end_unit

