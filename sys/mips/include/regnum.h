begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: regnum.h,v 1.3 1999/01/27 04:46:06 imp Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department and Ralph Campbell.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: Utah Hdr: reg.h 1.1 90/07/09  *	@(#)reg.h	8.2 (Berkeley) 1/11/94  *	JNPR: regnum.h,v 1.6 2007/08/09 11:23:32 katta  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_REGNUM_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_REGNUM_H_
end_define

begin_comment
comment|/*  * Location of the saved registers relative to ZERO.  * This must match struct trapframe defined in frame.h exactly.  * This must also match regdef.h.  */
end_comment

begin_define
define|#
directive|define
name|ZERO
value|0
end_define

begin_define
define|#
directive|define
name|AST
value|1
end_define

begin_define
define|#
directive|define
name|V0
value|2
end_define

begin_define
define|#
directive|define
name|V1
value|3
end_define

begin_define
define|#
directive|define
name|A0
value|4
end_define

begin_define
define|#
directive|define
name|A1
value|5
end_define

begin_define
define|#
directive|define
name|A2
value|6
end_define

begin_define
define|#
directive|define
name|A3
value|7
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips_n32
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips_n64
argument_list|)
end_if

begin_define
define|#
directive|define
name|A4
value|8
end_define

begin_define
define|#
directive|define
name|A5
value|9
end_define

begin_define
define|#
directive|define
name|A6
value|10
end_define

begin_define
define|#
directive|define
name|A7
value|11
end_define

begin_define
define|#
directive|define
name|T0
value|12
end_define

begin_define
define|#
directive|define
name|T1
value|13
end_define

begin_define
define|#
directive|define
name|T2
value|14
end_define

begin_define
define|#
directive|define
name|T3
value|15
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|T0
value|8
end_define

begin_define
define|#
directive|define
name|T1
value|9
end_define

begin_define
define|#
directive|define
name|T2
value|10
end_define

begin_define
define|#
directive|define
name|T3
value|11
end_define

begin_define
define|#
directive|define
name|T4
value|12
end_define

begin_define
define|#
directive|define
name|T5
value|13
end_define

begin_define
define|#
directive|define
name|T6
value|14
end_define

begin_define
define|#
directive|define
name|T7
value|15
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|S0
value|16
end_define

begin_define
define|#
directive|define
name|S1
value|17
end_define

begin_define
define|#
directive|define
name|S2
value|18
end_define

begin_define
define|#
directive|define
name|S3
value|19
end_define

begin_define
define|#
directive|define
name|S4
value|20
end_define

begin_define
define|#
directive|define
name|S5
value|21
end_define

begin_define
define|#
directive|define
name|S6
value|22
end_define

begin_define
define|#
directive|define
name|S7
value|23
end_define

begin_define
define|#
directive|define
name|T8
value|24
end_define

begin_define
define|#
directive|define
name|T9
value|25
end_define

begin_define
define|#
directive|define
name|K0
value|26
end_define

begin_define
define|#
directive|define
name|K1
value|27
end_define

begin_define
define|#
directive|define
name|GP
value|28
end_define

begin_define
define|#
directive|define
name|SP
value|29
end_define

begin_define
define|#
directive|define
name|S8
value|30
end_define

begin_define
define|#
directive|define
name|RA
value|31
end_define

begin_define
define|#
directive|define
name|SR
value|32
end_define

begin_define
define|#
directive|define
name|PS
value|SR
end_define

begin_comment
comment|/* alias for SR */
end_comment

begin_define
define|#
directive|define
name|MULLO
value|33
end_define

begin_define
define|#
directive|define
name|MULHI
value|34
end_define

begin_define
define|#
directive|define
name|BADVADDR
value|35
end_define

begin_define
define|#
directive|define
name|CAUSE
value|36
end_define

begin_define
define|#
directive|define
name|PC
value|37
end_define

begin_comment
comment|/*  * IC is valid only on RM7K and RM9K processors. Access to this is  * controlled by IC_INT_REG which defined in kernel config  */
end_comment

begin_define
define|#
directive|define
name|IC
value|38
end_define

begin_define
define|#
directive|define
name|DUMMY
value|39
end_define

begin_comment
comment|/* for 8 byte alignment */
end_comment

begin_define
define|#
directive|define
name|NUMSAVEREGS
value|40
end_define

begin_comment
comment|/*  * Pseudo registers so we save a complete set of registers regardless of  * the ABI. See regdef.h for a more complete explanation.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips_n32
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips_n64
argument_list|)
end_if

begin_define
define|#
directive|define
name|TA0
value|8
end_define

begin_define
define|#
directive|define
name|TA1
value|9
end_define

begin_define
define|#
directive|define
name|TA2
value|10
end_define

begin_define
define|#
directive|define
name|TA3
value|11
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TA0
value|12
end_define

begin_define
define|#
directive|define
name|TA1
value|13
end_define

begin_define
define|#
directive|define
name|TA2
value|14
end_define

begin_define
define|#
directive|define
name|TA3
value|15
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Index of FP registers in 'struct frame', counting from the beginning  * of the frame (i.e., including the general registers).  */
end_comment

begin_define
define|#
directive|define
name|FPBASE
value|NUMSAVEREGS
end_define

begin_define
define|#
directive|define
name|F0
value|(FPBASE+0)
end_define

begin_define
define|#
directive|define
name|F1
value|(FPBASE+1)
end_define

begin_define
define|#
directive|define
name|F2
value|(FPBASE+2)
end_define

begin_define
define|#
directive|define
name|F3
value|(FPBASE+3)
end_define

begin_define
define|#
directive|define
name|F4
value|(FPBASE+4)
end_define

begin_define
define|#
directive|define
name|F5
value|(FPBASE+5)
end_define

begin_define
define|#
directive|define
name|F6
value|(FPBASE+6)
end_define

begin_define
define|#
directive|define
name|F7
value|(FPBASE+7)
end_define

begin_define
define|#
directive|define
name|F8
value|(FPBASE+8)
end_define

begin_define
define|#
directive|define
name|F9
value|(FPBASE+9)
end_define

begin_define
define|#
directive|define
name|F10
value|(FPBASE+10)
end_define

begin_define
define|#
directive|define
name|F11
value|(FPBASE+11)
end_define

begin_define
define|#
directive|define
name|F12
value|(FPBASE+12)
end_define

begin_define
define|#
directive|define
name|F13
value|(FPBASE+13)
end_define

begin_define
define|#
directive|define
name|F14
value|(FPBASE+14)
end_define

begin_define
define|#
directive|define
name|F15
value|(FPBASE+15)
end_define

begin_define
define|#
directive|define
name|F16
value|(FPBASE+16)
end_define

begin_define
define|#
directive|define
name|F17
value|(FPBASE+17)
end_define

begin_define
define|#
directive|define
name|F18
value|(FPBASE+18)
end_define

begin_define
define|#
directive|define
name|F19
value|(FPBASE+19)
end_define

begin_define
define|#
directive|define
name|F20
value|(FPBASE+20)
end_define

begin_define
define|#
directive|define
name|F21
value|(FPBASE+21)
end_define

begin_define
define|#
directive|define
name|F22
value|(FPBASE+22)
end_define

begin_define
define|#
directive|define
name|F23
value|(FPBASE+23)
end_define

begin_define
define|#
directive|define
name|F24
value|(FPBASE+24)
end_define

begin_define
define|#
directive|define
name|F25
value|(FPBASE+25)
end_define

begin_define
define|#
directive|define
name|F26
value|(FPBASE+26)
end_define

begin_define
define|#
directive|define
name|F27
value|(FPBASE+27)
end_define

begin_define
define|#
directive|define
name|F28
value|(FPBASE+28)
end_define

begin_define
define|#
directive|define
name|F29
value|(FPBASE+29)
end_define

begin_define
define|#
directive|define
name|F30
value|(FPBASE+30)
end_define

begin_define
define|#
directive|define
name|F31
value|(FPBASE+31)
end_define

begin_define
define|#
directive|define
name|FSR
value|(FPBASE+32)
end_define

begin_define
define|#
directive|define
name|FIR
value|(FPBASE+33)
end_define

begin_define
define|#
directive|define
name|NUMFPREGS
value|34
end_define

begin_define
define|#
directive|define
name|NREGS
value|(NUMSAVEREGS + NUMFPREGS)
end_define

begin_comment
comment|/*  * Index of FP registers in 'struct frame', relative to the base  * of the FP registers in frame (i.e., *not* including the general  * registers).  */
end_comment

begin_define
define|#
directive|define
name|F0_NUM
value|(0)
end_define

begin_define
define|#
directive|define
name|F1_NUM
value|(1)
end_define

begin_define
define|#
directive|define
name|F2_NUM
value|(2)
end_define

begin_define
define|#
directive|define
name|F3_NUM
value|(3)
end_define

begin_define
define|#
directive|define
name|F4_NUM
value|(4)
end_define

begin_define
define|#
directive|define
name|F5_NUM
value|(5)
end_define

begin_define
define|#
directive|define
name|F6_NUM
value|(6)
end_define

begin_define
define|#
directive|define
name|F7_NUM
value|(7)
end_define

begin_define
define|#
directive|define
name|F8_NUM
value|(8)
end_define

begin_define
define|#
directive|define
name|F9_NUM
value|(9)
end_define

begin_define
define|#
directive|define
name|F10_NUM
value|(10)
end_define

begin_define
define|#
directive|define
name|F11_NUM
value|(11)
end_define

begin_define
define|#
directive|define
name|F12_NUM
value|(12)
end_define

begin_define
define|#
directive|define
name|F13_NUM
value|(13)
end_define

begin_define
define|#
directive|define
name|F14_NUM
value|(14)
end_define

begin_define
define|#
directive|define
name|F15_NUM
value|(15)
end_define

begin_define
define|#
directive|define
name|F16_NUM
value|(16)
end_define

begin_define
define|#
directive|define
name|F17_NUM
value|(17)
end_define

begin_define
define|#
directive|define
name|F18_NUM
value|(18)
end_define

begin_define
define|#
directive|define
name|F19_NUM
value|(19)
end_define

begin_define
define|#
directive|define
name|F20_NUM
value|(20)
end_define

begin_define
define|#
directive|define
name|F21_NUM
value|(21)
end_define

begin_define
define|#
directive|define
name|F22_NUM
value|(22)
end_define

begin_define
define|#
directive|define
name|F23_NUM
value|(23)
end_define

begin_define
define|#
directive|define
name|F24_NUM
value|(24)
end_define

begin_define
define|#
directive|define
name|F25_NUM
value|(25)
end_define

begin_define
define|#
directive|define
name|F26_NUM
value|(26)
end_define

begin_define
define|#
directive|define
name|F27_NUM
value|(27)
end_define

begin_define
define|#
directive|define
name|F28_NUM
value|(28)
end_define

begin_define
define|#
directive|define
name|F29_NUM
value|(29)
end_define

begin_define
define|#
directive|define
name|F30_NUM
value|(30)
end_define

begin_define
define|#
directive|define
name|F31_NUM
value|(31)
end_define

begin_define
define|#
directive|define
name|FSR_NUM
value|(32)
end_define

begin_define
define|#
directive|define
name|FIR_NUM
value|(33)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_REGNUM_H_ */
end_comment

end_unit

