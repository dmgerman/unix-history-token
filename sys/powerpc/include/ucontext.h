begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 1995, 1996 Wolfgang Solfrank.  * Copyright (C) 1995, 1996 TooLs GmbH.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by TooLs GmbH.  * 4. The name of TooLs GmbH may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY TOOLS GMBH ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $NetBSD: signal.h,v 1.4 1998/09/14 02:48:34 thorpej Exp $  * $FreeBSD$  */
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
name|int
name|mc_vers
decl_stmt|;
name|int
name|mc_flags
decl_stmt|;
define|#
directive|define
name|_MC_FP_VALID
value|0x01
define|#
directive|define
name|_MC_AV_VALID
value|0x02
name|int
name|mc_onstack
decl_stmt|;
comment|/* saved onstack flag */
name|int
name|mc_len
decl_stmt|;
comment|/* sizeof(__mcontext) */
name|uint64_t
name|mc_avec
index|[
literal|32
operator|*
literal|2
index|]
decl_stmt|;
comment|/* vector register file */
name|uint32_t
name|mc_av
index|[
literal|2
index|]
decl_stmt|;
name|uint32_t
name|mc_frame
index|[
literal|41
index|]
decl_stmt|;
name|uint64_t
name|mc_fpreg
index|[
literal|33
index|]
decl_stmt|;
block|}
name|mcontext_t
name|__aligned
typedef|(16);
end_typedef

begin_comment
comment|/* GPRs and supervisor-level regs */
end_comment

begin_define
define|#
directive|define
name|mc_gpr
value|mc_frame
end_define

begin_define
define|#
directive|define
name|mc_lr
value|mc_frame[32]
end_define

begin_define
define|#
directive|define
name|mc_cr
value|mc_frame[33]
end_define

begin_define
define|#
directive|define
name|mc_xer
value|mc_frame[34]
end_define

begin_define
define|#
directive|define
name|mc_ctr
value|mc_frame[35]
end_define

begin_define
define|#
directive|define
name|mc_srr0
value|mc_frame[36]
end_define

begin_define
define|#
directive|define
name|mc_srr1
value|mc_frame[37]
end_define

begin_define
define|#
directive|define
name|mc_dar
value|mc_frame[38]
end_define

begin_define
define|#
directive|define
name|mc_dsisr
value|mc_frame[39]
end_define

begin_define
define|#
directive|define
name|mc_exc
value|mc_frame[40]
end_define

begin_comment
comment|/* floating-point state */
end_comment

begin_define
define|#
directive|define
name|mc_fpscr
value|mc_fpreg[32]
end_define

begin_comment
comment|/* altivec state */
end_comment

begin_define
define|#
directive|define
name|mc_vscr
value|mc_av[0]
end_define

begin_define
define|#
directive|define
name|mc_vrsave
value|mc_av[1]
end_define

begin_define
define|#
directive|define
name|_MC_VERSION
value|0x1
end_define

begin_define
define|#
directive|define
name|_MC_VERSION_KSE
value|0xee
end_define

begin_comment
comment|/* partial ucontext for libpthread */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_UCONTEXT_H_ */
end_comment

end_unit

