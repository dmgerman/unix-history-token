begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001 David O'Brien.  * Copyright (c) 1994-1996 Mark Brinicombe.  * Copyright (c) 1994 Brini.  * All rights reserved.  *  * This code is derived from software written for Brini by Mark Brinicombe  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Brini.  * 4. The name of the company nor the name of the author may be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY BRINI ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL BRINI OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * RiscBSD kernel project  *  * signal.h  *  * Architecture dependant signal types and structures  *  * Created      : 30/09/94  *  *	$NetBSD: signal.h,v 1.8 1998/09/14 02:48:33 thorpej Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_UCONTEXT_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_UCONTEXT_H_
end_define

begin_typedef
typedef|typedef
struct|struct
name|__mcontext
block|{
comment|/* 	 * The first 20 fields must match the definition of 	 * sigcontext. So that we can support sigcontext 	 * and ucontext_t at the same time. 	 */
name|unsigned
name|int
name|mc_onstack
decl_stmt|;
comment|/* XXX - sigcontext compat. */
name|unsigned
name|int
name|mc_spsr
decl_stmt|;
name|unsigned
name|int
name|mc_r0
decl_stmt|;
name|unsigned
name|int
name|mc_r1
decl_stmt|;
name|unsigned
name|int
name|mc_r2
decl_stmt|;
name|unsigned
name|int
name|mc_r3
decl_stmt|;
name|unsigned
name|int
name|mc_r4
decl_stmt|;
name|unsigned
name|int
name|mc_r5
decl_stmt|;
name|unsigned
name|int
name|mc_r6
decl_stmt|;
name|unsigned
name|int
name|mc_r7
decl_stmt|;
name|unsigned
name|int
name|mc_r8
decl_stmt|;
name|unsigned
name|int
name|mc_r9
decl_stmt|;
name|unsigned
name|int
name|mc_r10
decl_stmt|;
name|unsigned
name|int
name|mc_r11
decl_stmt|;
name|unsigned
name|int
name|mc_r12
decl_stmt|;
name|unsigned
name|int
name|mc_usr_sp
decl_stmt|;
name|unsigned
name|int
name|mc_usr_lr
decl_stmt|;
name|unsigned
name|int
name|mc_svc_lr
decl_stmt|;
name|unsigned
name|int
name|mc_pc
decl_stmt|;
name|unsigned
name|int
name|__spare__
index|[
literal|1
index|]
decl_stmt|;
comment|/* XXX fix the size later */
block|}
name|mcontext_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_UCONTEXT_H_ */
end_comment

end_unit

