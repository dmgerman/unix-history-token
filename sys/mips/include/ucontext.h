begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ucontext.h	8.1 (Berkeley) 6/10/93  *	JNPR: ucontext.h,v 1.2 2007/08/09 11:23:32 katta  * $FreeBSD$  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|_LOCORE
end_ifndef

begin_typedef
typedef|typedef
struct|struct
name|__mcontext
block|{
comment|/* 	 * These fields must match the corresponding fields in struct  	 * sigcontext which follow 'sc_mask'. That way we can support 	 * struct sigcontext and ucontext_t at the same time. 	 */
name|int
name|mc_onstack
decl_stmt|;
comment|/* sigstack state to restore */
name|register_t
name|mc_pc
decl_stmt|;
comment|/* pc at time of signal */
name|register_t
name|mc_regs
index|[
literal|32
index|]
decl_stmt|;
comment|/* processor regs 0 to 31 */
name|register_t
name|sr
decl_stmt|;
comment|/* status register */
name|register_t
name|mullo
decl_stmt|,
name|mulhi
decl_stmt|;
comment|/* mullo and mulhi registers... */
name|int
name|mc_fpused
decl_stmt|;
comment|/* fp has been used */
name|f_register_t
name|mc_fpregs
index|[
literal|33
index|]
decl_stmt|;
comment|/* fp regs 0 to 31 and csr */
name|register_t
name|mc_fpc_eir
decl_stmt|;
comment|/* fp exception instruction reg */
name|void
modifier|*
name|mc_tls
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
name|mcontext_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips_n64
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips_n32
argument_list|)
end_if

begin_define
define|#
directive|define
name|SZREG
value|8
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SZREG
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* offsets into mcontext_t */
end_comment

begin_define
define|#
directive|define
name|UCTX_REG
parameter_list|(
name|x
parameter_list|)
value|(4 + SZREG + (x)*SZREG)
end_define

begin_define
define|#
directive|define
name|UCR_ZERO
value|UCTX_REG(0)
end_define

begin_define
define|#
directive|define
name|UCR_AT
value|UCTX_REG(1)
end_define

begin_define
define|#
directive|define
name|UCR_V0
value|UCTX_REG(2)
end_define

begin_define
define|#
directive|define
name|UCR_V1
value|UCTX_REG(3)
end_define

begin_define
define|#
directive|define
name|UCR_A0
value|UCTX_REG(4)
end_define

begin_define
define|#
directive|define
name|UCR_A1
value|UCTX_REG(5)
end_define

begin_define
define|#
directive|define
name|UCR_A2
value|UCTX_REG(6)
end_define

begin_define
define|#
directive|define
name|UCR_A3
value|UCTX_REG(7)
end_define

begin_define
define|#
directive|define
name|UCR_T0
value|UCTX_REG(8)
end_define

begin_define
define|#
directive|define
name|UCR_T1
value|UCTX_REG(9)
end_define

begin_define
define|#
directive|define
name|UCR_T2
value|UCTX_REG(10)
end_define

begin_define
define|#
directive|define
name|UCR_T3
value|UCTX_REG(11)
end_define

begin_define
define|#
directive|define
name|UCR_T4
value|UCTX_REG(12)
end_define

begin_define
define|#
directive|define
name|UCR_T5
value|UCTX_REG(13)
end_define

begin_define
define|#
directive|define
name|UCR_T6
value|UCTX_REG(14)
end_define

begin_define
define|#
directive|define
name|UCR_T7
value|UCTX_REG(15)
end_define

begin_define
define|#
directive|define
name|UCR_S0
value|UCTX_REG(16)
end_define

begin_define
define|#
directive|define
name|UCR_S1
value|UCTX_REG(17)
end_define

begin_define
define|#
directive|define
name|UCR_S2
value|UCTX_REG(18)
end_define

begin_define
define|#
directive|define
name|UCR_S3
value|UCTX_REG(19)
end_define

begin_define
define|#
directive|define
name|UCR_S4
value|UCTX_REG(20)
end_define

begin_define
define|#
directive|define
name|UCR_S5
value|UCTX_REG(21)
end_define

begin_define
define|#
directive|define
name|UCR_S6
value|UCTX_REG(22)
end_define

begin_define
define|#
directive|define
name|UCR_S7
value|UCTX_REG(23)
end_define

begin_define
define|#
directive|define
name|UCR_T8
value|UCTX_REG(24)
end_define

begin_define
define|#
directive|define
name|UCR_T9
value|UCTX_REG(25)
end_define

begin_define
define|#
directive|define
name|UCR_K0
value|UCTX_REG(26)
end_define

begin_define
define|#
directive|define
name|UCR_K1
value|UCTX_REG(27)
end_define

begin_define
define|#
directive|define
name|UCR_GP
value|UCTX_REG(28)
end_define

begin_define
define|#
directive|define
name|UCR_SP
value|UCTX_REG(29)
end_define

begin_define
define|#
directive|define
name|UCR_S8
value|UCTX_REG(30)
end_define

begin_define
define|#
directive|define
name|UCR_RA
value|UCTX_REG(31)
end_define

begin_define
define|#
directive|define
name|UCR_SR
value|UCTX_REG(32)
end_define

begin_define
define|#
directive|define
name|UCR_MDLO
value|UCTX_REG(33)
end_define

begin_define
define|#
directive|define
name|UCR_MDHI
value|UCTX_REG(34)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_UCONTEXT_H_ */
end_comment

end_unit

