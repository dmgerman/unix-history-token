begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1994 David S. Miller, davem@nadzieja.rutgers.edu  * Copyright (c) 1995 Paul Kranenburg  * Copyright (c) 2001 Thomas Moestl<tmm@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by David Miller.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	from: NetBSD: db_disasm.c,v 1.9 2000/08/16 11:29:42 pk Exp  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_INSTR_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_INSTR_H_
end_define

begin_comment
comment|/*  * Definitions for all instruction formats  */
end_comment

begin_define
define|#
directive|define
name|IF_OP_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|IF_OP_BITS
value|2
end_define

begin_define
define|#
directive|define
name|IF_IMM_SHIFT
value|0
end_define

begin_comment
comment|/* Immediate/Displacement */
end_comment

begin_comment
comment|/*  * Definitions for format 2  */
end_comment

begin_define
define|#
directive|define
name|IF_F2_RD_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|IF_F2_RD_BITS
value|5
end_define

begin_define
define|#
directive|define
name|IF_F2_A_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|IF_F2_A_BITS
value|1
end_define

begin_define
define|#
directive|define
name|IF_F2_COND_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|IF_F2_COND_BITS
value|4
end_define

begin_define
define|#
directive|define
name|IF_F2_RCOND_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|IF_F2_RCOND_BITS
value|3
end_define

begin_define
define|#
directive|define
name|IF_F2_OP2_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|IF_F2_OP2_BITS
value|3
end_define

begin_define
define|#
directive|define
name|IF_F2_CC1_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|IF_F2_CC1_BITS
value|1
end_define

begin_define
define|#
directive|define
name|IF_F2_CC0_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|IF_F2_CC0_BITS
value|1
end_define

begin_define
define|#
directive|define
name|IF_F2_CC_SHIFT
value|20
end_define

begin_comment
comment|/* CC0 and CC1 combined. */
end_comment

begin_define
define|#
directive|define
name|IF_F2_CC_BITS
value|2
end_define

begin_define
define|#
directive|define
name|IF_F2_D16HI_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|IF_F2_D16HI_BITS
value|2
end_define

begin_define
define|#
directive|define
name|IF_F2_P_SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|IF_F2_P_BITS
value|1
end_define

begin_define
define|#
directive|define
name|IF_F2_RS1_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|IF_F2_RS1_BITS
value|5
end_define

begin_comment
comment|/*  * Definitions for format 3  */
end_comment

begin_define
define|#
directive|define
name|IF_F3_OP3_SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|IF_F3_OP3_BITS
value|6
end_define

begin_define
define|#
directive|define
name|IF_F3_RD_SHIFT
value|IF_F2_RD_SHIFT
end_define

begin_define
define|#
directive|define
name|IF_F3_RD_BITS
value|IF_F2_RD_BITS
end_define

begin_define
define|#
directive|define
name|IF_F3_FCN_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|IF_F3_FCN_BITS
value|5
end_define

begin_define
define|#
directive|define
name|IF_F3_CC1_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|IF_F3_CC1_BITS
value|1
end_define

begin_define
define|#
directive|define
name|IF_F3_CC0_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|IF_F3_CC0_BITS
value|1
end_define

begin_define
define|#
directive|define
name|IF_F3_CC_SHIFT
value|25
end_define

begin_comment
comment|/* CC0 and CC1 combined. */
end_comment

begin_define
define|#
directive|define
name|IF_F3_CC_BITS
value|2
end_define

begin_define
define|#
directive|define
name|IF_F3_RS1_SHIFT
value|IF_F2_RS1_SHIFT
end_define

begin_define
define|#
directive|define
name|IF_F3_RS1_BITS
value|IF_F2_RS1_BITS
end_define

begin_define
define|#
directive|define
name|IF_F3_I_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|IF_F3_I_BITS
value|1
end_define

begin_define
define|#
directive|define
name|IF_F3_X_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|IF_F3_X_BITS
value|1
end_define

begin_define
define|#
directive|define
name|IF_F3_RCOND_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|IF_F3_RCOND_BITS
value|3
end_define

begin_define
define|#
directive|define
name|IF_F3_IMM_ASI_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|IF_F3_IMM_ASI_BITS
value|8
end_define

begin_define
define|#
directive|define
name|IF_F3_OPF_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|IF_F3_OPF_BITS
value|9
end_define

begin_define
define|#
directive|define
name|IF_F3_CMASK_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|IF_F3_CMASK_BITS
value|3
end_define

begin_define
define|#
directive|define
name|IF_F3_RS2_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|IF_F3_RS2_BITS
value|5
end_define

begin_define
define|#
directive|define
name|IF_F3_SHCNT32_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|IF_F3_SHCNT32_BITS
value|5
end_define

begin_define
define|#
directive|define
name|IF_F3_SHCNT64_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|IF_F3_SHCNT64_BITS
value|6
end_define

begin_comment
comment|/*  * Definitions for format 4  */
end_comment

begin_define
define|#
directive|define
name|IF_F4_OP3_SHIFT
value|IF_F3_OP3_SHIFT
end_define

begin_define
define|#
directive|define
name|IF_F4_OP3_BITS
value|IF_F3_OP3_BITS
end_define

begin_define
define|#
directive|define
name|IF_F4_RD_SHIFT
value|IF_F2_RD_SHIFT
end_define

begin_define
define|#
directive|define
name|IF_F4_RD_BITS
value|IF_F2_RD_BITS
end_define

begin_define
define|#
directive|define
name|IF_F4_RS1_SHIFT
value|IF_F2_RS1_SHIFT
end_define

begin_define
define|#
directive|define
name|IF_F4_RS1_BITS
value|IF_F2_RS1_BITS
end_define

begin_define
define|#
directive|define
name|IF_F4_TCOND_SHIFT
value|IF_F2_COND_SHIFT
end_define

begin_comment
comment|/* cond for Tcc */
end_comment

begin_define
define|#
directive|define
name|IF_F4_TCOND_BITS
value|IF_F2_COND_BITS
end_define

begin_define
define|#
directive|define
name|IF_F4_CC2_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|IF_F4_CC2_BITS
value|1
end_define

begin_define
define|#
directive|define
name|IF_F4_COND_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|IF_F4_COND_BITS
value|4
end_define

begin_define
define|#
directive|define
name|IF_F4_I_SHIFT
value|IF_F3_I_SHIFT
end_define

begin_define
define|#
directive|define
name|IF_F4_I_BITS
value|IF_F3_I_BITS
end_define

begin_define
define|#
directive|define
name|IF_F4_OPF_CC_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|IF_F4_OPF_CC_BITS
value|3
end_define

begin_define
define|#
directive|define
name|IF_F4_CC1_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|IF_F4_CC1_BITS
value|1
end_define

begin_define
define|#
directive|define
name|IF_F4_CC0_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|IF_F4_CC0_BITS
value|1
end_define

begin_define
define|#
directive|define
name|IF_F4_RCOND_SHIFT
value|IF_F3_RCOND_SHIFT
end_define

begin_define
define|#
directive|define
name|IF_F4_RCOND_BITS
value|IF_F3_RCOND_BITS
end_define

begin_define
define|#
directive|define
name|IF_F4_OPF_LOW_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|IF_F4_RS2_SHIFT
value|IF_F3_RS2_SHIFT
end_define

begin_define
define|#
directive|define
name|IF_F4_RS2_BITS
value|IF_F3_RS2_BITS
end_define

begin_define
define|#
directive|define
name|IF_F4_SW_TRAP_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|IF_F4_SW_TRAP_BITS
value|7
end_define

begin_comment
comment|/*  * Macros to decode instructions  */
end_comment

begin_comment
comment|/* Extract a field */
end_comment

begin_define
define|#
directive|define
name|IF_MASK
parameter_list|(
name|s
parameter_list|,
name|w
parameter_list|)
value|(((1<< (w)) - 1)<< (s))
end_define

begin_define
define|#
directive|define
name|IF_EXTRACT
parameter_list|(
name|x
parameter_list|,
name|s
parameter_list|,
name|w
parameter_list|)
value|(((x)& IF_MASK((s), (w)))>> (s))
end_define

begin_define
define|#
directive|define
name|IF_DECODE
parameter_list|(
name|x
parameter_list|,
name|f
parameter_list|)
define|\
value|IF_EXTRACT((x), IF_ ## f ## _SHIFT, IF_ ## f ## _BITS)
end_define

begin_comment
comment|/* Sign-extend a field of width W */
end_comment

begin_define
define|#
directive|define
name|IF_SEXT
parameter_list|(
name|x
parameter_list|,
name|w
parameter_list|)
define|\
value|(((x)& (1<< ((w) - 1))) != 0 ? (-1L - ((x) ^ ((1<< (w)) - 1))) : (x))
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*  * The following C variant is from db_disassemble.c, and surely faster, but it  * relies on behaviour that is undefined by the C standard (>> in conjunction  * with signed negative arguments).  */
end_comment

begin_define
define|#
directive|define
name|IF_SEXT
parameter_list|(
name|v
parameter_list|,
name|w
parameter_list|)
value|((((long long)(v))<< (64 - w))>> (64 - w))
end_define

begin_comment
comment|/* Assembler version of the above */
end_comment

begin_define
define|#
directive|define
name|IF_SEXT
parameter_list|(
name|v
parameter_list|,
name|w
parameter_list|)
define|\
value|{ u_long t; ( __asm __volatile("sllx %1, %2, %0; srax %0, %2, %0" :
end_define

begin_endif
unit|"=r" (t) : "r" (v) : "i" (64 - w)); t)}
endif|#
directive|endif
end_endif

begin_comment
comment|/* All instruction formats */
end_comment

begin_define
define|#
directive|define
name|IF_OP
parameter_list|(
name|i
parameter_list|)
value|IF_DECODE(i, OP)
end_define

begin_comment
comment|/* Instruction format 2 */
end_comment

begin_define
define|#
directive|define
name|IF_F2_RD
parameter_list|(
name|i
parameter_list|)
value|IF_DECODE((i), F2_RD)
end_define

begin_define
define|#
directive|define
name|IF_F2_A
parameter_list|(
name|i
parameter_list|)
value|IF_DECODE((i), F2_A)
end_define

begin_define
define|#
directive|define
name|IF_F2_COND
parameter_list|(
name|i
parameter_list|)
value|IF_DECODE((i), F2_COND)
end_define

begin_define
define|#
directive|define
name|IF_F2_RCOND
parameter_list|(
name|i
parameter_list|)
value|IF_DECODE((i), F2_RCOND)
end_define

begin_define
define|#
directive|define
name|IF_F2_OP2
parameter_list|(
name|i
parameter_list|)
value|IF_DECODE((i), F2_OP2)
end_define

begin_define
define|#
directive|define
name|IF_F2_CC1
parameter_list|(
name|i
parameter_list|)
value|IF_DECODE((i), F2_CC1)
end_define

begin_define
define|#
directive|define
name|IF_F2_CC0
parameter_list|(
name|i
parameter_list|)
value|IF_DECODE((i), F2_CC0)
end_define

begin_define
define|#
directive|define
name|IF_F2_CC
parameter_list|(
name|i
parameter_list|)
value|IF_DECODE((i), F2_CC)
end_define

begin_define
define|#
directive|define
name|IF_F2_D16HI
parameter_list|(
name|i
parameter_list|)
value|IF_DECODE((i), F2_D16HI)
end_define

begin_define
define|#
directive|define
name|IF_F2_P
parameter_list|(
name|i
parameter_list|)
value|IF_DECODE((i), F2_P)
end_define

begin_define
define|#
directive|define
name|IF_F2_RS1
parameter_list|(
name|i
parameter_list|)
value|IF_DECODE((i), F2_RS1)
end_define

begin_comment
comment|/* Instruction format 3 */
end_comment

begin_define
define|#
directive|define
name|IF_F3_OP3
parameter_list|(
name|i
parameter_list|)
value|IF_DECODE((i), F3_OP3)
end_define

begin_define
define|#
directive|define
name|IF_F3_RD
parameter_list|(
name|i
parameter_list|)
value|IF_F2_RD((i))
end_define

begin_define
define|#
directive|define
name|IF_F3_FCN
parameter_list|(
name|i
parameter_list|)
value|IF_DECODE((i), F3_FCN)
end_define

begin_define
define|#
directive|define
name|IF_F3_CC1
parameter_list|(
name|i
parameter_list|)
value|IF_DECODE((i), F3_CC1)
end_define

begin_define
define|#
directive|define
name|IF_F3_CC0
parameter_list|(
name|i
parameter_list|)
value|IF_DECODE((i), F3_CC0)
end_define

begin_define
define|#
directive|define
name|IF_F3_CC
parameter_list|(
name|i
parameter_list|)
value|IF_DECODE((i), F3_CC)
end_define

begin_define
define|#
directive|define
name|IF_F3_RS1
parameter_list|(
name|i
parameter_list|)
value|IF_F2_RS1((i))
end_define

begin_define
define|#
directive|define
name|IF_F3_I
parameter_list|(
name|i
parameter_list|)
value|IF_DECODE((i), F3_I)
end_define

begin_define
define|#
directive|define
name|IF_F3_X
parameter_list|(
name|i
parameter_list|)
value|IF_DECODE((i), F3_X)
end_define

begin_define
define|#
directive|define
name|IF_F3_RCOND
parameter_list|(
name|i
parameter_list|)
value|IF_DECODE((i), F3_RCOND)
end_define

begin_define
define|#
directive|define
name|IF_F3_IMM_ASI
parameter_list|(
name|i
parameter_list|)
value|IF_DECODE((i), F3_IMM_ASI)
end_define

begin_define
define|#
directive|define
name|IF_F3_OPF
parameter_list|(
name|i
parameter_list|)
value|IF_DECODE((i), F3_OPF)
end_define

begin_define
define|#
directive|define
name|IF_F3_CMASK
parameter_list|(
name|i
parameter_list|)
value|IF_DECODE((i), F3_CMASK)
end_define

begin_define
define|#
directive|define
name|IF_F3_RS2
parameter_list|(
name|i
parameter_list|)
value|IF_DECODE((i), F3_RS2)
end_define

begin_define
define|#
directive|define
name|IF_F3_SHCNT32
parameter_list|(
name|i
parameter_list|)
value|IF_DECODE((i), F3_SHCNT32)
end_define

begin_define
define|#
directive|define
name|IF_F3_SHCNT64
parameter_list|(
name|i
parameter_list|)
value|IF_DECODE((i), F3_SHCNT64)
end_define

begin_comment
comment|/* Instruction format 4 */
end_comment

begin_define
define|#
directive|define
name|IF_F4_OP3
parameter_list|(
name|i
parameter_list|)
value|IF_F3_OP3((i))
end_define

begin_define
define|#
directive|define
name|IF_F4_RD
parameter_list|(
name|i
parameter_list|)
value|IF_F3_RD((i))
end_define

begin_define
define|#
directive|define
name|IF_F4_TCOND
parameter_list|(
name|i
parameter_list|)
value|IF_DECODE((i), F4_TCOND)
end_define

begin_define
define|#
directive|define
name|IF_F4_RS1
parameter_list|(
name|i
parameter_list|)
value|IF_F3_RS1((i))
end_define

begin_define
define|#
directive|define
name|IF_F4_CC2
parameter_list|(
name|i
parameter_list|)
value|IF_DECODE((i), F4_CC2)
end_define

begin_define
define|#
directive|define
name|IF_F4_COND
parameter_list|(
name|i
parameter_list|)
value|IF_DECODE((i), F4_COND)
end_define

begin_define
define|#
directive|define
name|IF_F4_I
parameter_list|(
name|i
parameter_list|)
value|IF_F3_I((i))
end_define

begin_define
define|#
directive|define
name|IF_F4_OPF_CC
parameter_list|(
name|i
parameter_list|)
value|IF_DECODE((i), F4_OPF_CC)
end_define

begin_define
define|#
directive|define
name|IF_F4_RCOND
parameter_list|(
name|i
parameter_list|)
value|IF_F3_RCOND((i))
end_define

begin_define
define|#
directive|define
name|IF_F4_OPF_LOW
parameter_list|(
name|i
parameter_list|,
name|w
parameter_list|)
value|IF_EXTRACT((i), IF_F4_OPF_LOW_SHIFT, (w))
end_define

begin_define
define|#
directive|define
name|IF_F4_RS2
parameter_list|(
name|i
parameter_list|)
value|IF_F3_RS2((i))
end_define

begin_define
define|#
directive|define
name|IF_F4_SW_TRAP
parameter_list|(
name|i
parameter_list|)
value|IF_DECODE((i), F4_SW_TRAP)
end_define

begin_comment
comment|/* Extract an immediate from an instruction, with an without sign extension */
end_comment

begin_define
define|#
directive|define
name|IF_IMM
parameter_list|(
name|i
parameter_list|,
name|w
parameter_list|)
value|IF_EXTRACT((i), IF_IMM_SHIFT, (w))
end_define

begin_define
define|#
directive|define
name|IF_SIMM
parameter_list|(
name|i
parameter_list|,
name|w
parameter_list|)
value|({ u_long b = (w), x = IF_IMM((i), b); IF_SEXT((x), b); })
end_define

begin_comment
comment|/*  * Macros to encode instructions  */
end_comment

begin_define
define|#
directive|define
name|IF_INSERT
parameter_list|(
name|x
parameter_list|,
name|s
parameter_list|,
name|w
parameter_list|)
value|(((x)& ((1<< (w)) - 1))<< (s))
end_define

begin_define
define|#
directive|define
name|IF_ENCODE
parameter_list|(
name|x
parameter_list|,
name|f
parameter_list|)
define|\
value|IF_INSERT((x), IF_ ## f ## _SHIFT, IF_ ## f ## _BITS)
end_define

begin_comment
comment|/* All instruction formats */
end_comment

begin_define
define|#
directive|define
name|EIF_OP
parameter_list|(
name|x
parameter_list|)
value|IF_ENCODE((x), OP)
end_define

begin_comment
comment|/* Instruction format 2 */
end_comment

begin_define
define|#
directive|define
name|EIF_F2_RD
parameter_list|(
name|x
parameter_list|)
value|IF_ENCODE((x), F2_RD)
end_define

begin_define
define|#
directive|define
name|EIF_F2_A
parameter_list|(
name|x
parameter_list|)
value|IF_ENCODE((x), F2_A)
end_define

begin_define
define|#
directive|define
name|EIF_F2_COND
parameter_list|(
name|x
parameter_list|)
value|IF_ENCODE((x), F2_COND)
end_define

begin_define
define|#
directive|define
name|EIF_F2_RCOND
parameter_list|(
name|x
parameter_list|)
value|IF_ENCODE((x), F2_RCOND)
end_define

begin_define
define|#
directive|define
name|EIF_F2_OP2
parameter_list|(
name|x
parameter_list|)
value|IF_ENCODE((x), F2_OP2)
end_define

begin_define
define|#
directive|define
name|EIF_F2_CC1
parameter_list|(
name|x
parameter_list|)
value|IF_ENCODE((x), F2_CC1)
end_define

begin_define
define|#
directive|define
name|EIF_F2_CC0
parameter_list|(
name|x
parameter_list|)
value|IF_ENCODE((x), F2_CC0)
end_define

begin_define
define|#
directive|define
name|EIF_F2_D16HI
parameter_list|(
name|x
parameter_list|)
value|IF_ENCODE((x), F2_D16HI)
end_define

begin_define
define|#
directive|define
name|EIF_F2_P
parameter_list|(
name|x
parameter_list|)
value|IF_ENCODE((x), F2_P)
end_define

begin_define
define|#
directive|define
name|EIF_F2_RS1
parameter_list|(
name|x
parameter_list|)
value|IF_ENCODE((x), F2_RS1)
end_define

begin_comment
comment|/* Instruction format 3 */
end_comment

begin_define
define|#
directive|define
name|EIF_F3_OP3
parameter_list|(
name|x
parameter_list|)
value|IF_ENCODE((x), F3_OP3)
end_define

begin_define
define|#
directive|define
name|EIF_F3_RD
parameter_list|(
name|x
parameter_list|)
value|EIF_F2_RD((x))
end_define

begin_define
define|#
directive|define
name|EIF_F3_FCN
parameter_list|(
name|x
parameter_list|)
value|IF_ENCODE((x), F3_FCN)
end_define

begin_define
define|#
directive|define
name|EIF_F3_CC1
parameter_list|(
name|x
parameter_list|)
value|IF_ENCODE((x), F3_CC1)
end_define

begin_define
define|#
directive|define
name|EIF_F3_CC0
parameter_list|(
name|x
parameter_list|)
value|IF_ENCODE((x), F3_CC0)
end_define

begin_define
define|#
directive|define
name|EIF_F3_RS1
parameter_list|(
name|x
parameter_list|)
value|EIF_F2_RS1((x))
end_define

begin_define
define|#
directive|define
name|EIF_F3_I
parameter_list|(
name|x
parameter_list|)
value|IF_ENCODE((x), F3_I)
end_define

begin_define
define|#
directive|define
name|EIF_F3_X
parameter_list|(
name|x
parameter_list|)
value|IF_ENCODE((x), F3_X)
end_define

begin_define
define|#
directive|define
name|EIF_F3_RCOND
parameter_list|(
name|x
parameter_list|)
value|IF_ENCODE((x), F3_RCOND)
end_define

begin_define
define|#
directive|define
name|EIF_F3_IMM_ASI
parameter_list|(
name|x
parameter_list|)
value|IF_ENCODE((x), F3_IMM_ASI)
end_define

begin_define
define|#
directive|define
name|EIF_F3_OPF
parameter_list|(
name|x
parameter_list|)
value|IF_ENCODE((x), F3_OPF)
end_define

begin_define
define|#
directive|define
name|EIF_F3_CMASK
parameter_list|(
name|x
parameter_list|)
value|IF_ENCODE((x), F3_CMASK)
end_define

begin_define
define|#
directive|define
name|EIF_F3_RS2
parameter_list|(
name|x
parameter_list|)
value|IF_ENCODE((x), F3_RS2)
end_define

begin_define
define|#
directive|define
name|EIF_F3_SHCNT32
parameter_list|(
name|x
parameter_list|)
value|IF_ENCODE((x), F3_SHCNT32)
end_define

begin_define
define|#
directive|define
name|EIF_F3_SHCNT64
parameter_list|(
name|x
parameter_list|)
value|IF_ENCODE((x), F3_SHCNT64)
end_define

begin_comment
comment|/* Instruction format 4 */
end_comment

begin_define
define|#
directive|define
name|EIF_F4_OP3
parameter_list|(
name|x
parameter_list|)
value|EIF_F3_OP3((x))
end_define

begin_define
define|#
directive|define
name|EIF_F4_RD
parameter_list|(
name|x
parameter_list|)
value|EIF_F2_RD((x))
end_define

begin_define
define|#
directive|define
name|EIF_F4_TCOND
parameter_list|(
name|x
parameter_list|)
value|IF_ENCODE((x), F4_TCOND)
end_define

begin_define
define|#
directive|define
name|EIF_F4_RS1
parameter_list|(
name|x
parameter_list|)
value|EIF_F2_RS1((x))
end_define

begin_define
define|#
directive|define
name|EIF_F4_CC2
parameter_list|(
name|x
parameter_list|)
value|IF_ENCODE((x), F4_CC2)
end_define

begin_define
define|#
directive|define
name|EIF_F4_COND
parameter_list|(
name|x
parameter_list|)
value|IF_ENCODE((x), F4_COND)
end_define

begin_define
define|#
directive|define
name|EIF_F4_I
parameter_list|(
name|x
parameter_list|)
value|EIF_F3_I((x))
end_define

begin_define
define|#
directive|define
name|EIF_F4_OPF_CC
parameter_list|(
name|x
parameter_list|)
value|IF_ENCODE((x), F4_OPF_CC)
end_define

begin_define
define|#
directive|define
name|EIF_F4_RCOND
parameter_list|(
name|x
parameter_list|)
value|EIF_F3_RCOND((x))
end_define

begin_define
define|#
directive|define
name|EIF_F4_OPF_LOW
parameter_list|(
name|i
parameter_list|,
name|w
parameter_list|)
value|IF_INSERT((x), IF_F4_OPF_CC_SHIFT, (w))
end_define

begin_define
define|#
directive|define
name|EIF_F4_RS2
parameter_list|(
name|x
parameter_list|)
value|EIF_F3_RS2((x))
end_define

begin_define
define|#
directive|define
name|EIF_F4_SW_TRAP
parameter_list|(
name|x
parameter_list|)
value|IF_ENCODE((x), F4_SW_TRAP)
end_define

begin_comment
comment|/* Immediates */
end_comment

begin_define
define|#
directive|define
name|EIF_IMM
parameter_list|(
name|x
parameter_list|,
name|w
parameter_list|)
value|IF_INSERT((x), IF_IMM_SHIFT, (w))
end_define

begin_define
define|#
directive|define
name|EIF_SIMM
parameter_list|(
name|x
parameter_list|,
name|w
parameter_list|)
value|IF_EIMM((x), (w))
end_define

begin_comment
comment|/*  * OP field values (specifying the instruction format)  */
end_comment

begin_define
define|#
directive|define
name|IOP_FORM2
value|0x00
end_define

begin_comment
comment|/* Format 2: sethi, branches */
end_comment

begin_define
define|#
directive|define
name|IOP_CALL
value|0x01
end_define

begin_comment
comment|/* Format 1: call */
end_comment

begin_define
define|#
directive|define
name|IOP_MISC
value|0x02
end_define

begin_comment
comment|/* Format 3 or 4: arith& misc */
end_comment

begin_define
define|#
directive|define
name|IOP_LDST
value|0x03
end_define

begin_comment
comment|/* Format 4: loads and stores */
end_comment

begin_comment
comment|/*  * OP2/OP3 values (specifying the actual instruction)  */
end_comment

begin_comment
comment|/* OP2 values for format 2 (OP = 0) */
end_comment

begin_define
define|#
directive|define
name|INS0_ILLTRAP
value|0x00
end_define

begin_define
define|#
directive|define
name|INS0_BPcc
value|0x01
end_define

begin_define
define|#
directive|define
name|INS0_Bicc
value|0x02
end_define

begin_define
define|#
directive|define
name|INS0_BPr
value|0x03
end_define

begin_define
define|#
directive|define
name|INS0_SETHI
value|0x04
end_define

begin_comment
comment|/* with rd = 0 and imm22 = 0, nop */
end_comment

begin_define
define|#
directive|define
name|INS0_FBPfcc
value|0x05
end_define

begin_define
define|#
directive|define
name|INS0_FBfcc
value|0x06
end_define

begin_comment
comment|/* undefined			0x07 */
end_comment

begin_comment
comment|/* OP3 values for Format 3 and 4 (OP = 2) */
end_comment

begin_define
define|#
directive|define
name|INS2_ADD
value|0x00
end_define

begin_define
define|#
directive|define
name|INS2_AND
value|0x01
end_define

begin_define
define|#
directive|define
name|INS2_OR
value|0x02
end_define

begin_define
define|#
directive|define
name|INS2_XOR
value|0x03
end_define

begin_define
define|#
directive|define
name|INS2_SUB
value|0x04
end_define

begin_define
define|#
directive|define
name|INS2_ANDN
value|0x05
end_define

begin_define
define|#
directive|define
name|INS2_ORN
value|0x06
end_define

begin_define
define|#
directive|define
name|INS2_XNOR
value|0x07
end_define

begin_define
define|#
directive|define
name|INS2_ADDC
value|0x08
end_define

begin_define
define|#
directive|define
name|INS2_MULX
value|0x09
end_define

begin_define
define|#
directive|define
name|INS2_UMUL
value|0x0a
end_define

begin_define
define|#
directive|define
name|INS2_SMUL
value|0x0b
end_define

begin_define
define|#
directive|define
name|INS2_SUBC
value|0x0c
end_define

begin_define
define|#
directive|define
name|INS2_UDIVX
value|0x0d
end_define

begin_define
define|#
directive|define
name|INS2_UDIV
value|0x0e
end_define

begin_define
define|#
directive|define
name|INS2_SDIV
value|0x0f
end_define

begin_define
define|#
directive|define
name|INS2_ADDcc
value|0x10
end_define

begin_define
define|#
directive|define
name|INS2_ANDcc
value|0x11
end_define

begin_define
define|#
directive|define
name|INS2_ORcc
value|0x12
end_define

begin_define
define|#
directive|define
name|INS2_XORcc
value|0x13
end_define

begin_define
define|#
directive|define
name|INS2_SUBcc
value|0x14
end_define

begin_define
define|#
directive|define
name|INS2_ANDNcc
value|0x15
end_define

begin_define
define|#
directive|define
name|INS2_ORNcc
value|0x16
end_define

begin_define
define|#
directive|define
name|INS2_XNORcc
value|0x17
end_define

begin_define
define|#
directive|define
name|INS2_ADDCcc
value|0x18
end_define

begin_comment
comment|/* undefined			0x19 */
end_comment

begin_define
define|#
directive|define
name|INS2_UMULcc
value|0x1a
end_define

begin_define
define|#
directive|define
name|INS2_SMULcc
value|0x1b
end_define

begin_define
define|#
directive|define
name|INS2_SUBCcc
value|0x1c
end_define

begin_comment
comment|/* undefined			0x1d */
end_comment

begin_define
define|#
directive|define
name|INS2_UDIVcc
value|0x1e
end_define

begin_define
define|#
directive|define
name|INS2_SDIVcc
value|0x1f
end_define

begin_define
define|#
directive|define
name|INS2_TADDcc
value|0x20
end_define

begin_define
define|#
directive|define
name|INS2_TSUBcc
value|0x21
end_define

begin_define
define|#
directive|define
name|INS2_TADDccTV
value|0x22
end_define

begin_define
define|#
directive|define
name|INS2_TSUBccTV
value|0x23
end_define

begin_define
define|#
directive|define
name|INS2_MULScc
value|0x24
end_define

begin_define
define|#
directive|define
name|INS2_SSL
value|0x25
end_define

begin_comment
comment|/* SLLX when IF_X(i) == 1 */
end_comment

begin_define
define|#
directive|define
name|INS2_SRL
value|0x26
end_define

begin_comment
comment|/* SRLX when IF_X(i) == 1 */
end_comment

begin_define
define|#
directive|define
name|INS2_SRA
value|0x27
end_define

begin_comment
comment|/* SRAX when IF_X(i) == 1 */
end_comment

begin_define
define|#
directive|define
name|INS2_RD
value|0x28
end_define

begin_comment
comment|/* and MEMBAR, STBAR */
end_comment

begin_comment
comment|/* undefined			0x29 */
end_comment

begin_define
define|#
directive|define
name|INS2_RDPR
value|0x2a
end_define

begin_define
define|#
directive|define
name|INS2_FLUSHW
value|0x2b
end_define

begin_define
define|#
directive|define
name|INS2_MOVcc
value|0x2c
end_define

begin_define
define|#
directive|define
name|INS2_SDIVX
value|0x2d
end_define

begin_define
define|#
directive|define
name|INS2_POPC
value|0x2e
end_define

begin_comment
comment|/* undefined if IF_RS1(i) != 0 */
end_comment

begin_define
define|#
directive|define
name|INS2_MOVr
value|0x2f
end_define

begin_define
define|#
directive|define
name|INS2_WR
value|0x30
end_define

begin_comment
comment|/* and SIR */
end_comment

begin_define
define|#
directive|define
name|INS2_SV_RSTR
value|0x31
end_define

begin_comment
comment|/* saved, restored */
end_comment

begin_define
define|#
directive|define
name|INS2_WRPR
value|0x32
end_define

begin_comment
comment|/* undefined			0x33 */
end_comment

begin_define
define|#
directive|define
name|INS2_FPop1
value|0x34
end_define

begin_comment
comment|/* further encoded in opf field */
end_comment

begin_define
define|#
directive|define
name|INS2_FPop2
value|0x35
end_define

begin_comment
comment|/* further encoded in opf field */
end_comment

begin_define
define|#
directive|define
name|INS2_IMPLDEP1
value|0x36
end_define

begin_define
define|#
directive|define
name|INS2_IMPLDEP2
value|0x37
end_define

begin_define
define|#
directive|define
name|INS2_JMPL
value|0x38
end_define

begin_define
define|#
directive|define
name|INS2_RETURN
value|0x39
end_define

begin_define
define|#
directive|define
name|INS2_Tcc
value|0x3a
end_define

begin_define
define|#
directive|define
name|INS2_FLUSH
value|0x3b
end_define

begin_define
define|#
directive|define
name|INS2_SAVE
value|0x3c
end_define

begin_define
define|#
directive|define
name|INS2_RESTORE
value|0x3d
end_define

begin_define
define|#
directive|define
name|INS2_DONE_RETR
value|0x3e
end_define

begin_comment
comment|/* done, retry */
end_comment

begin_comment
comment|/* undefined			0x3f */
end_comment

begin_comment
comment|/* OP3 values for format 3 (OP = 3) */
end_comment

begin_define
define|#
directive|define
name|INS3_LDUW
value|0x00
end_define

begin_define
define|#
directive|define
name|INS3_LDUB
value|0x01
end_define

begin_define
define|#
directive|define
name|INS3_LDUH
value|0x02
end_define

begin_define
define|#
directive|define
name|INS3_LDD
value|0x03
end_define

begin_define
define|#
directive|define
name|INS3_STW
value|0x04
end_define

begin_define
define|#
directive|define
name|INS3_STB
value|0x05
end_define

begin_define
define|#
directive|define
name|INS3_STH
value|0x06
end_define

begin_define
define|#
directive|define
name|INS3_STD
value|0x07
end_define

begin_define
define|#
directive|define
name|INS3_LDSW
value|0x08
end_define

begin_define
define|#
directive|define
name|INS3_LDSB
value|0x09
end_define

begin_define
define|#
directive|define
name|INS3_LDSH
value|0x0a
end_define

begin_define
define|#
directive|define
name|INS3_LDX
value|0x0b
end_define

begin_comment
comment|/* undefined			0x0c */
end_comment

begin_define
define|#
directive|define
name|INS3_LDSTUB
value|0x0d
end_define

begin_define
define|#
directive|define
name|INS3_STX
value|0x0e
end_define

begin_define
define|#
directive|define
name|INS3_SWAP
value|0x0f
end_define

begin_define
define|#
directive|define
name|INS3_LDUWA
value|0x10
end_define

begin_define
define|#
directive|define
name|INS3_LDUBA
value|0x11
end_define

begin_define
define|#
directive|define
name|INS3_LDUHA
value|0x12
end_define

begin_define
define|#
directive|define
name|INS3_LDDA
value|0x13
end_define

begin_define
define|#
directive|define
name|INS3_STWA
value|0x14
end_define

begin_define
define|#
directive|define
name|INS3_STBA
value|0x15
end_define

begin_define
define|#
directive|define
name|INS3_STHA
value|0x16
end_define

begin_define
define|#
directive|define
name|INS3_STDA
value|0x17
end_define

begin_define
define|#
directive|define
name|INS3_LDSWA
value|0x18
end_define

begin_define
define|#
directive|define
name|INS3_LDSBA
value|0x19
end_define

begin_define
define|#
directive|define
name|INS3_LDSHA
value|0x1a
end_define

begin_define
define|#
directive|define
name|INS3_LDXA
value|0x1b
end_define

begin_comment
comment|/* undefined			0x1c */
end_comment

begin_define
define|#
directive|define
name|INS3_LDSTUBA
value|0x1d
end_define

begin_define
define|#
directive|define
name|INS3_STXA
value|0x1e
end_define

begin_define
define|#
directive|define
name|INS3_SWAPA
value|0x1f
end_define

begin_define
define|#
directive|define
name|INS3_LDF
value|0x20
end_define

begin_define
define|#
directive|define
name|INS3_LDFSR
value|0x21
end_define

begin_comment
comment|/* and LDXFSR */
end_comment

begin_define
define|#
directive|define
name|INS3_LDQF
value|0x22
end_define

begin_define
define|#
directive|define
name|INS3_LDDF
value|0x23
end_define

begin_define
define|#
directive|define
name|INS3_STF
value|0x24
end_define

begin_define
define|#
directive|define
name|INS3_STFSR
value|0x25
end_define

begin_comment
comment|/* and STXFSR */
end_comment

begin_define
define|#
directive|define
name|INS3_STQF
value|0x26
end_define

begin_define
define|#
directive|define
name|INS3_STDF
value|0x27
end_define

begin_comment
comment|/* undefined			0x28 - 0x2c */
end_comment

begin_define
define|#
directive|define
name|INS3_PREFETCH
value|0x2d
end_define

begin_comment
comment|/* undefined			0x2e - 0x2f */
end_comment

begin_define
define|#
directive|define
name|INS3_LDFA
value|0x30
end_define

begin_comment
comment|/* undefined			0x31 */
end_comment

begin_define
define|#
directive|define
name|INS3_LDQFA
value|0x32
end_define

begin_define
define|#
directive|define
name|INS3_LDDFA
value|0x33
end_define

begin_define
define|#
directive|define
name|INS3_STFA
value|0x34
end_define

begin_comment
comment|/* undefined			0x35 */
end_comment

begin_define
define|#
directive|define
name|INS3_STQFA
value|0x36
end_define

begin_define
define|#
directive|define
name|INS3_STDFA
value|0x37
end_define

begin_comment
comment|/* undefined			0x38 - 0x3b */
end_comment

begin_define
define|#
directive|define
name|INS3_CASA
value|0x39
end_define

begin_define
define|#
directive|define
name|INS3_PREFETCHA
value|0x3a
end_define

begin_define
define|#
directive|define
name|INS3_CASXA
value|0x3b
end_define

begin_comment
comment|/*  * OPF values (floating point instructions, IMPLDEP)  */
end_comment

begin_comment
comment|/*  * These values are or'ed to the FPop values to get the instructions.  * They describe the operand type(s).  */
end_comment

begin_define
define|#
directive|define
name|INSFP_i
value|0x000
end_define

begin_comment
comment|/* 32-bit int */
end_comment

begin_define
define|#
directive|define
name|INSFP_s
value|0x001
end_define

begin_comment
comment|/* 32-bit single */
end_comment

begin_define
define|#
directive|define
name|INSFP_d
value|0x002
end_define

begin_comment
comment|/* 64-bit double */
end_comment

begin_define
define|#
directive|define
name|INSFP_q
value|0x003
end_define

begin_comment
comment|/* 128-bit quad */
end_comment

begin_comment
comment|/* FPop1. The comments give the types for which this instruction is defined. */
end_comment

begin_define
define|#
directive|define
name|INSFP1_FMOV
value|0x000
end_define

begin_comment
comment|/* s, d, q */
end_comment

begin_define
define|#
directive|define
name|INSFP1_FNEG
value|0x004
end_define

begin_comment
comment|/* s, d, q */
end_comment

begin_define
define|#
directive|define
name|INSFP1_FABS
value|0x008
end_define

begin_comment
comment|/* s, d, q */
end_comment

begin_define
define|#
directive|define
name|INSFP1_FSQRT
value|0x028
end_define

begin_comment
comment|/* s, d, q */
end_comment

begin_define
define|#
directive|define
name|INSFP1_FADD
value|0x040
end_define

begin_comment
comment|/* s, d, q */
end_comment

begin_define
define|#
directive|define
name|INSFP1_FSUB
value|0x044
end_define

begin_comment
comment|/* s, d, q */
end_comment

begin_define
define|#
directive|define
name|INSFP1_FMUL
value|0x048
end_define

begin_comment
comment|/* s, d, q */
end_comment

begin_define
define|#
directive|define
name|INSFP1_FDIV
value|0x04c
end_define

begin_comment
comment|/* s, d, q */
end_comment

begin_define
define|#
directive|define
name|INSFP1_FsMULd
value|0x068
end_define

begin_comment
comment|/* s */
end_comment

begin_define
define|#
directive|define
name|INSFP1_FdMULq
value|0x06c
end_define

begin_comment
comment|/* d */
end_comment

begin_define
define|#
directive|define
name|INSFP1_FTOx
value|0x080
end_define

begin_comment
comment|/* s, d, q */
end_comment

begin_define
define|#
directive|define
name|INSFP1_FxTOs
value|0x084
end_define

begin_comment
comment|/* special: i only */
end_comment

begin_define
define|#
directive|define
name|INSFP1_FxTOd
value|0x088
end_define

begin_comment
comment|/* special: i only */
end_comment

begin_define
define|#
directive|define
name|INSFP1_FxTOq
value|0x08c
end_define

begin_comment
comment|/* special: i only */
end_comment

begin_define
define|#
directive|define
name|INSFP1_FTOs
value|0x0c4
end_define

begin_comment
comment|/* i, d, q */
end_comment

begin_define
define|#
directive|define
name|INSFP1_FTOd
value|0x0c8
end_define

begin_comment
comment|/* i, s, q */
end_comment

begin_define
define|#
directive|define
name|INSFP1_FTOq
value|0x0cc
end_define

begin_comment
comment|/* i, s, d */
end_comment

begin_define
define|#
directive|define
name|INSFP1_FTOi
value|0x0d0
end_define

begin_comment
comment|/* i, s, d */
end_comment

begin_comment
comment|/* FPop2 */
end_comment

begin_define
define|#
directive|define
name|INSFP2_FMOV_CCMUL
value|0x40
end_define

begin_define
define|#
directive|define
name|INSFP2_FMOV_CCOFFS
value|0x00
end_define

begin_comment
comment|/* Use the IFCC_* constants for cc. Operand types: s, d, q */
end_comment

begin_define
define|#
directive|define
name|INSFP2_FMOV_CC
parameter_list|(
name|cc
parameter_list|)
value|((cc) * INSFP2_FMOV_CCMUL + INSFP2_FMOV_CCOFFS)
end_define

begin_define
define|#
directive|define
name|INSFP2_FMOV_RCMUL
value|0x20
end_define

begin_define
define|#
directive|define
name|INSFP2_FMOV_RCOFFS
value|0x04
end_define

begin_comment
comment|/* Use the IRCOND_* constants for rc. Operand types: s, d, q */
end_comment

begin_define
define|#
directive|define
name|INSFP2_FMOV_RC
parameter_list|(
name|rc
parameter_list|)
value|((rc) * INSFP2_FMOV_RCMUL + INSFP2_FMOV_RCOFFS)
end_define

begin_define
define|#
directive|define
name|INSFP2_FCMP
value|0x050
end_define

begin_comment
comment|/* s, d, q */
end_comment

begin_define
define|#
directive|define
name|INSFP2_FCMPE
value|0x054
end_define

begin_comment
comment|/* s, d, q */
end_comment

begin_comment
comment|/* IMPLDEP1 for Sun UltraSparc */
end_comment

begin_define
define|#
directive|define
name|IIDP1_EDGE8
value|0x00
end_define

begin_define
define|#
directive|define
name|IIDP1_EDGE8L
value|0x02
end_define

begin_define
define|#
directive|define
name|IIDP1_EDGE16
value|0x04
end_define

begin_define
define|#
directive|define
name|IIDP1_EDGE16L
value|0x06
end_define

begin_define
define|#
directive|define
name|IIDP1_EDGE32
value|0x08
end_define

begin_define
define|#
directive|define
name|IIDP1_EDGE32L
value|0x0a
end_define

begin_define
define|#
directive|define
name|IIDP1_ARRAY8
value|0x10
end_define

begin_define
define|#
directive|define
name|IIDP1_ARRAY16
value|0x12
end_define

begin_define
define|#
directive|define
name|IIDP1_ARRAY32
value|0x14
end_define

begin_define
define|#
directive|define
name|IIDP1_ALIGNADDRESS
value|0x18
end_define

begin_define
define|#
directive|define
name|IIDP1_ALIGNADDRESS_L
value|0x1a
end_define

begin_define
define|#
directive|define
name|IIDP1_FCMPLE16
value|0x20
end_define

begin_define
define|#
directive|define
name|IIDP1_FCMPNE16
value|0x22
end_define

begin_define
define|#
directive|define
name|IIDP1_FCMPLE32
value|0x24
end_define

begin_define
define|#
directive|define
name|IIDP1_FCMPNE32
value|0x26
end_define

begin_define
define|#
directive|define
name|IIDP1_FCMPGT16
value|0x28
end_define

begin_define
define|#
directive|define
name|IIDP1_FCMPEQ16
value|0x2a
end_define

begin_define
define|#
directive|define
name|IIDP1_FCMPGT32
value|0x2c
end_define

begin_define
define|#
directive|define
name|IIDP1_FCMPEQ32
value|0x2e
end_define

begin_define
define|#
directive|define
name|IIDP1_FMUL8x16
value|0x31
end_define

begin_define
define|#
directive|define
name|IIDP1_FMUL8x16AU
value|0x33
end_define

begin_define
define|#
directive|define
name|IIDP1_FMUL8X16AL
value|0x35
end_define

begin_define
define|#
directive|define
name|IIDP1_FMUL8SUx16
value|0x36
end_define

begin_define
define|#
directive|define
name|IIDP1_FMUL8ULx16
value|0x37
end_define

begin_define
define|#
directive|define
name|IIDP1_FMULD8SUx16
value|0x38
end_define

begin_define
define|#
directive|define
name|IIDP1_FMULD8ULx16
value|0x39
end_define

begin_define
define|#
directive|define
name|IIDP1_FPACK32
value|0x3a
end_define

begin_define
define|#
directive|define
name|IIDP1_FPACK16
value|0x3b
end_define

begin_define
define|#
directive|define
name|IIDP1_FPACKFIX
value|0x3d
end_define

begin_define
define|#
directive|define
name|IIDP1_PDIST
value|0x3e
end_define

begin_define
define|#
directive|define
name|IIDP1_FALIGNDATA
value|0x48
end_define

begin_define
define|#
directive|define
name|IIDP1_FPMERGE
value|0x4b
end_define

begin_define
define|#
directive|define
name|IIDP1_FEXPAND
value|0x4d
end_define

begin_define
define|#
directive|define
name|IIDP1_FPADD16
value|0x50
end_define

begin_define
define|#
directive|define
name|IIDP1_FPADD16S
value|0x51
end_define

begin_define
define|#
directive|define
name|IIDP1_FPADD32
value|0x52
end_define

begin_define
define|#
directive|define
name|IIDP1_FPADD32S
value|0x53
end_define

begin_define
define|#
directive|define
name|IIDP1_SUB16
value|0x54
end_define

begin_define
define|#
directive|define
name|IIDP1_SUB16S
value|0x55
end_define

begin_define
define|#
directive|define
name|IIDP1_SUB32
value|0x56
end_define

begin_define
define|#
directive|define
name|IIDP1_SUB32S
value|0x57
end_define

begin_define
define|#
directive|define
name|IIDP1_FZERO
value|0x60
end_define

begin_define
define|#
directive|define
name|IIDP1_FZEROS
value|0x61
end_define

begin_define
define|#
directive|define
name|IIDP1_FNOR
value|0x62
end_define

begin_define
define|#
directive|define
name|IIDP1_FNORS
value|0x63
end_define

begin_define
define|#
directive|define
name|IIDP1_FANDNOT2
value|0x64
end_define

begin_define
define|#
directive|define
name|IIDP1_FANDNOT2S
value|0x65
end_define

begin_define
define|#
directive|define
name|IIDP1_NOT2
value|0x66
end_define

begin_define
define|#
directive|define
name|IIDP1_NOT2S
value|0x67
end_define

begin_define
define|#
directive|define
name|IIDP1_FANDNOT1
value|0x68
end_define

begin_define
define|#
directive|define
name|IIDP1_FANDNOT1S
value|0x69
end_define

begin_define
define|#
directive|define
name|IIDP1_FNOT1
value|0x6a
end_define

begin_define
define|#
directive|define
name|IIDP1_FNOT1S
value|0x6b
end_define

begin_define
define|#
directive|define
name|IIDP1_FXOR
value|0x6c
end_define

begin_define
define|#
directive|define
name|IIDP1_FXORS
value|0x6d
end_define

begin_define
define|#
directive|define
name|IIDP1_FNAND
value|0x6e
end_define

begin_define
define|#
directive|define
name|IIDP1_FNANDS
value|0x6f
end_define

begin_define
define|#
directive|define
name|IIDP1_FAND
value|0x70
end_define

begin_define
define|#
directive|define
name|IIDP1_FANDS
value|0x71
end_define

begin_define
define|#
directive|define
name|IIDP1_FXNOR
value|0x72
end_define

begin_define
define|#
directive|define
name|IIDP1_FXNORS
value|0x73
end_define

begin_define
define|#
directive|define
name|IIDP1_FSRC1
value|0x74
end_define

begin_define
define|#
directive|define
name|IIDP1_FSRC1S
value|0x75
end_define

begin_define
define|#
directive|define
name|IIDP1_FORNOT2
value|0x76
end_define

begin_define
define|#
directive|define
name|IIDP1_FORNOT2S
value|0x77
end_define

begin_define
define|#
directive|define
name|IIDP1_FSRC2
value|0x78
end_define

begin_define
define|#
directive|define
name|IIDP1_FSRC2S
value|0x79
end_define

begin_define
define|#
directive|define
name|IIDP1_FORNOT1
value|0x7a
end_define

begin_define
define|#
directive|define
name|IIDP1_FORNOT1S
value|0x7b
end_define

begin_define
define|#
directive|define
name|IIDP1_FOR
value|0x7c
end_define

begin_define
define|#
directive|define
name|IIDP1_FORS
value|0x7d
end_define

begin_define
define|#
directive|define
name|IIDP1_FONE
value|0x7e
end_define

begin_define
define|#
directive|define
name|IIDP1_FONES
value|0x7f
end_define

begin_define
define|#
directive|define
name|IIDP1_SHUTDOWN
value|0x80
end_define

begin_comment
comment|/*  * Instruction modifiers  */
end_comment

begin_comment
comment|/* cond values for integer ccr's */
end_comment

begin_define
define|#
directive|define
name|IICOND_N
value|0x00
end_define

begin_define
define|#
directive|define
name|IICOND_E
value|0x01
end_define

begin_define
define|#
directive|define
name|IICOND_LE
value|0x02
end_define

begin_define
define|#
directive|define
name|IICOND_L
value|0x03
end_define

begin_define
define|#
directive|define
name|IICOND_LEU
value|0x04
end_define

begin_define
define|#
directive|define
name|IICOND_CS
value|0x05
end_define

begin_define
define|#
directive|define
name|IICOND_NEG
value|0x06
end_define

begin_define
define|#
directive|define
name|IICOND_VS
value|0x07
end_define

begin_define
define|#
directive|define
name|IICOND_A
value|0x08
end_define

begin_define
define|#
directive|define
name|IICOND_NE
value|0x09
end_define

begin_define
define|#
directive|define
name|IICOND_G
value|0x0a
end_define

begin_define
define|#
directive|define
name|IICOND_GE
value|0x0b
end_define

begin_define
define|#
directive|define
name|IICOND_GU
value|0x0c
end_define

begin_define
define|#
directive|define
name|IICOND_CC
value|0x0d
end_define

begin_define
define|#
directive|define
name|IICOND_POS
value|0x0e
end_define

begin_define
define|#
directive|define
name|IICOND_VC
value|0x0f
end_define

begin_comment
comment|/* cond values for fp ccr's */
end_comment

begin_define
define|#
directive|define
name|IFCOND_N
value|0x00
end_define

begin_define
define|#
directive|define
name|IFCOND_NE
value|0x01
end_define

begin_define
define|#
directive|define
name|IFCOND_LG
value|0x02
end_define

begin_define
define|#
directive|define
name|IFCOND_UL
value|0x03
end_define

begin_define
define|#
directive|define
name|IFCOND_L
value|0x04
end_define

begin_define
define|#
directive|define
name|IFCOND_UG
value|0x05
end_define

begin_define
define|#
directive|define
name|IFCOND_G
value|0x06
end_define

begin_define
define|#
directive|define
name|IFCOND_U
value|0x07
end_define

begin_define
define|#
directive|define
name|IFCOND_A
value|0x08
end_define

begin_define
define|#
directive|define
name|IFCOND_E
value|0x09
end_define

begin_define
define|#
directive|define
name|IFCOND_UE
value|0x0a
end_define

begin_define
define|#
directive|define
name|IFCOND_GE
value|0x0b
end_define

begin_define
define|#
directive|define
name|IFCOND_UGE
value|0x0c
end_define

begin_define
define|#
directive|define
name|IFCOND_LE
value|0x0d
end_define

begin_define
define|#
directive|define
name|IFCOND_ULE
value|0x0e
end_define

begin_define
define|#
directive|define
name|IFCOND_O
value|0x0f
end_define

begin_comment
comment|/* rcond values for BPr, MOVr, FMOVr */
end_comment

begin_define
define|#
directive|define
name|IRCOND_Z
value|0x01
end_define

begin_define
define|#
directive|define
name|IRCOND_LEZ
value|0x02
end_define

begin_define
define|#
directive|define
name|IRCOND_LZ
value|0x03
end_define

begin_define
define|#
directive|define
name|IRCOND_NZ
value|0x05
end_define

begin_define
define|#
directive|define
name|IRCOND_GZ
value|0x06
end_define

begin_define
define|#
directive|define
name|IRCOND_GEZ
value|0x07
end_define

begin_comment
comment|/* cc values for MOVcc and FMOVcc */
end_comment

begin_define
define|#
directive|define
name|IFCC_ICC
value|0x04
end_define

begin_define
define|#
directive|define
name|IFCC_XCC
value|0x06
end_define

begin_comment
comment|/* if true, the lower 2 bits are the fcc number */
end_comment

begin_define
define|#
directive|define
name|IFCC_FCC
parameter_list|(
name|c
parameter_list|)
value|((c)& 3)
end_define

begin_define
define|#
directive|define
name|IFCC_GET_FCC
parameter_list|(
name|c
parameter_list|)
value|((c)& 3)
end_define

begin_define
define|#
directive|define
name|IFCC_ISFCC
parameter_list|(
name|c
parameter_list|)
value|(((c)& 4) == 0)
end_define

begin_comment
comment|/* cc values for BPc and Tcc */
end_comment

begin_define
define|#
directive|define
name|IBCC_ICC
value|0x00
end_define

begin_define
define|#
directive|define
name|IBCC_XCC
value|0x02
end_define

begin_comment
comment|/*  * Integer registers  */
end_comment

begin_define
define|#
directive|define
name|IREG_G0
value|0x00
end_define

begin_define
define|#
directive|define
name|IREG_O0
value|0x08
end_define

begin_define
define|#
directive|define
name|IREG_L0
value|0x10
end_define

begin_define
define|#
directive|define
name|IREQ_I0
value|0x18
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_INSTR_H_ */
end_comment

end_unit

