begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: signal.h,v 1.2 1999/01/27 04:10:03 imp Exp $	*/
end_comment

begin_comment
comment|/*  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)signal.h	8.1 (Berkeley) 6/10/93  *	JNPR: signal.h,v 1.4 2007/01/08 04:58:37 katta  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_SIGNAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_SIGNAL_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/_sigset.h>
end_include

begin_comment
comment|/*  * Machine-dependent signal definitions  */
end_comment

begin_typedef
typedef|typedef
name|int
name|sig_atomic_t
typedef|;
end_typedef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_ANSI_SOURCE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_POSIX_SOURCE
argument_list|)
end_if

begin_comment
comment|/*  * Information pushed on stack when a signal is delivered.  * This is used by the kernel to restore state following  * execution of the signal handler.  It is also made available  * to the handler to allow it to restore state properly if  * a non-standard exit is performed.  */
end_comment

begin_struct
struct|struct
name|sigcontext
block|{
comment|/* 	 * The fields following 'sc_mask' must match the definition 	 * of struct __mcontext. That way we can support 	 * struct sigcontext and ucontext_t at the same 	 * time. 	 */
name|__sigset_t
name|sc_mask
decl_stmt|;
comment|/* signal mask to restore */
name|int
name|sc_onstack
decl_stmt|;
comment|/* sigstack state to restore */
name|__register_t
name|sc_pc
decl_stmt|;
comment|/* pc at time of signal */
name|__register_t
name|sc_regs
index|[
literal|32
index|]
decl_stmt|;
comment|/* processor regs 0 to 31 */
name|__register_t
name|sr
decl_stmt|;
comment|/* status register */
name|__register_t
name|mullo
decl_stmt|,
name|mulhi
decl_stmt|;
comment|/* mullo and mulhi registers... */
name|int
name|sc_fpused
decl_stmt|;
comment|/* fp has been used */
name|f_register_t
name|sc_fpregs
index|[
literal|33
index|]
decl_stmt|;
comment|/* fp regs 0 to 31 and csr */
name|__register_t
name|sc_fpc_eir
decl_stmt|;
comment|/* fp exception instruction reg */
name|void
modifier|*
name|sc_tls
decl_stmt|;
comment|/* pointer to TLS area */
name|int
name|__spare__
index|[
literal|8
index|]
decl_stmt|;
comment|/* XXX reserved */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_ANSI_SOURCE&& !_POSIX_SOURCE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_SIGNAL_H_ */
end_comment

end_unit

