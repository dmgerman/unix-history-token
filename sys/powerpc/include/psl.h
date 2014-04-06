begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 1995, 1996 Wolfgang Solfrank.  * Copyright (C) 1995, 1996 TooLs GmbH.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by TooLs GmbH.  * 4. The name of TooLs GmbH may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY TOOLS GMBH ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$NetBSD: psl.h,v 1.5 2000/11/19 19:52:37 matt Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PSL_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PSL_H_
end_define

begin_comment
comment|/*  * Machine State Register (MSR) - All cores  */
end_comment

begin_define
define|#
directive|define
name|PSL_VEC
value|0x02000000UL
end_define

begin_comment
comment|/* AltiVec/SPE vector unit available */
end_comment

begin_define
define|#
directive|define
name|PSL_EE
value|0x00008000UL
end_define

begin_comment
comment|/* external interrupt enable */
end_comment

begin_define
define|#
directive|define
name|PSL_PR
value|0x00004000UL
end_define

begin_comment
comment|/* privilege mode (1 == user) */
end_comment

begin_define
define|#
directive|define
name|PSL_FP
value|0x00002000UL
end_define

begin_comment
comment|/* floating point enable */
end_comment

begin_define
define|#
directive|define
name|PSL_ME
value|0x00001000UL
end_define

begin_comment
comment|/* machine check enable */
end_comment

begin_define
define|#
directive|define
name|PSL_FE0
value|0x00000800UL
end_define

begin_comment
comment|/* floating point interrupt mode 0 */
end_comment

begin_define
define|#
directive|define
name|PSL_BE
value|0x00000200UL
end_define

begin_comment
comment|/* branch trace enable */
end_comment

begin_define
define|#
directive|define
name|PSL_FE1
value|0x00000100UL
end_define

begin_comment
comment|/* floating point interrupt mode 1 */
end_comment

begin_define
define|#
directive|define
name|PSL_PMM
value|0x00000004UL
end_define

begin_comment
comment|/* performance monitor mark */
end_comment

begin_comment
comment|/* Machine State Register - Book-E cores */
end_comment

begin_define
define|#
directive|define
name|PSL_UCLE
value|0x04000000UL
end_define

begin_comment
comment|/* User mode cache lock enable */
end_comment

begin_define
define|#
directive|define
name|PSL_WE
value|0x00040000UL
end_define

begin_comment
comment|/* Wait state enable */
end_comment

begin_define
define|#
directive|define
name|PSL_CE
value|0x00020000UL
end_define

begin_comment
comment|/* Critical interrupt enable */
end_comment

begin_define
define|#
directive|define
name|PSL_UBLE
value|0x00000400UL
end_define

begin_comment
comment|/* BTB lock enable - e500 only */
end_comment

begin_define
define|#
directive|define
name|PSL_DWE
value|0x00000400UL
end_define

begin_comment
comment|/* Debug Wait Enable - 440 only*/
end_comment

begin_define
define|#
directive|define
name|PSL_DE
value|0x00000200UL
end_define

begin_comment
comment|/* Debug interrupt enable */
end_comment

begin_define
define|#
directive|define
name|PSL_IS
value|0x00000020UL
end_define

begin_comment
comment|/* Instruction address space */
end_comment

begin_define
define|#
directive|define
name|PSL_DS
value|0x00000010UL
end_define

begin_comment
comment|/* Data address space */
end_comment

begin_comment
comment|/* Machine State Register (MSR) - AIM cores */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__powerpc64__
end_ifdef

begin_define
define|#
directive|define
name|PSL_SF
value|0x8000000000000000UL
end_define

begin_comment
comment|/* 64-bit addressing */
end_comment

begin_define
define|#
directive|define
name|PSL_HV
value|0x1000000000000000UL
end_define

begin_comment
comment|/* hyper-privileged mode */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PSL_POW
value|0x00040000UL
end_define

begin_comment
comment|/* power management */
end_comment

begin_define
define|#
directive|define
name|PSL_ILE
value|0x00010000UL
end_define

begin_comment
comment|/* interrupt endian mode (1 == le) */
end_comment

begin_define
define|#
directive|define
name|PSL_SE
value|0x00000400UL
end_define

begin_comment
comment|/* single-step trace enable */
end_comment

begin_define
define|#
directive|define
name|PSL_IP
value|0x00000040UL
end_define

begin_comment
comment|/* interrupt prefix - 601 only */
end_comment

begin_define
define|#
directive|define
name|PSL_IR
value|0x00000020UL
end_define

begin_comment
comment|/* instruction address relocation */
end_comment

begin_define
define|#
directive|define
name|PSL_DR
value|0x00000010UL
end_define

begin_comment
comment|/* data address relocation */
end_comment

begin_define
define|#
directive|define
name|PSL_RI
value|0x00000002UL
end_define

begin_comment
comment|/* recoverable interrupt */
end_comment

begin_define
define|#
directive|define
name|PSL_LE
value|0x00000001UL
end_define

begin_comment
comment|/* endian mode (1 == le) */
end_comment

begin_comment
comment|/*  * Floating-point exception modes:  */
end_comment

begin_define
define|#
directive|define
name|PSL_FE_DIS
value|0
end_define

begin_comment
comment|/* none */
end_comment

begin_define
define|#
directive|define
name|PSL_FE_NONREC
value|PSL_FE1
end_define

begin_comment
comment|/* imprecise non-recoverable */
end_comment

begin_define
define|#
directive|define
name|PSL_FE_REC
value|PSL_FE0
end_define

begin_comment
comment|/* imprecise recoverable */
end_comment

begin_define
define|#
directive|define
name|PSL_FE_PREC
value|(PSL_FE0 | PSL_FE1)
end_define

begin_comment
comment|/* precise */
end_comment

begin_define
define|#
directive|define
name|PSL_FE_DFLT
value|PSL_FE_DIS
end_define

begin_comment
comment|/* default == none */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BOOKE_E500
argument_list|)
end_if

begin_comment
comment|/* Initial kernel MSR, use IS=1 ad DS=1. */
end_comment

begin_define
define|#
directive|define
name|PSL_KERNSET_INIT
value|(PSL_IS | PSL_DS)
end_define

begin_define
define|#
directive|define
name|PSL_KERNSET
value|(PSL_CE | PSL_ME | PSL_EE)
end_define

begin_define
define|#
directive|define
name|PSL_SRR1_MASK
value|0x00000000UL
end_define

begin_comment
comment|/* No mask on Book-E */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|BOOKE_PPC4XX
argument_list|)
end_elif

begin_define
define|#
directive|define
name|PSL_KERNSET
value|(PSL_CE | PSL_ME | PSL_EE | PSL_FP)
end_define

begin_define
define|#
directive|define
name|PSL_SRR1_MASK
value|0x00000000UL
end_define

begin_comment
comment|/* No mask on Book-E */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|AIM
argument_list|)
end_elif

begin_ifdef
ifdef|#
directive|ifdef
name|__powerpc64__
end_ifdef

begin_define
define|#
directive|define
name|PSL_KERNSET
value|(PSL_SF | PSL_EE | PSL_ME | PSL_IR | PSL_DR | PSL_RI)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PSL_KERNSET
value|(PSL_EE | PSL_ME | PSL_IR | PSL_DR | PSL_RI)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PSL_SRR1_MASK
value|0x783f0000UL
end_define

begin_comment
comment|/* Bits 1-4, 10-15 (ppc32), 33-36, 42-47 (ppc64) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PSL_USERSET
value|(PSL_KERNSET | PSL_PR)
end_define

begin_define
define|#
directive|define
name|PSL_USERSTATIC
value|(~(PSL_VEC | PSL_FP | PSL_FE0 | PSL_FE1)& ~PSL_SRR1_MASK)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_PSL_H_ */
end_comment

end_unit

