begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)trap.h	5.4 (Berkeley) 5/9/91  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_TRAP_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_TRAP_H_
end_define

begin_comment
comment|/*  * Trap type values  * also known in trap.c for name strings  */
end_comment

begin_define
define|#
directive|define
name|T_PRIVINFLT
value|1
end_define

begin_comment
comment|/* privileged instruction */
end_comment

begin_define
define|#
directive|define
name|T_BPTFLT
value|3
end_define

begin_comment
comment|/* breakpoint instruction */
end_comment

begin_define
define|#
directive|define
name|T_ARITHTRAP
value|6
end_define

begin_comment
comment|/* arithmetic trap */
end_comment

begin_define
define|#
directive|define
name|T_ASTFLT
value|7
end_define

begin_comment
comment|/* system forced exception */
end_comment

begin_define
define|#
directive|define
name|T_PROTFLT
value|9
end_define

begin_comment
comment|/* protection fault */
end_comment

begin_define
define|#
directive|define
name|T_TRCTRAP
value|10
end_define

begin_comment
comment|/* debug exception (sic) */
end_comment

begin_define
define|#
directive|define
name|T_PAGEFLT
value|12
end_define

begin_comment
comment|/* page fault */
end_comment

begin_define
define|#
directive|define
name|T_ALIGNFLT
value|14
end_define

begin_comment
comment|/* alignment fault */
end_comment

begin_define
define|#
directive|define
name|T_DIVIDE
value|18
end_define

begin_comment
comment|/* integer divide fault */
end_comment

begin_define
define|#
directive|define
name|T_NMI
value|19
end_define

begin_comment
comment|/* non-maskable trap */
end_comment

begin_define
define|#
directive|define
name|T_OFLOW
value|20
end_define

begin_comment
comment|/* overflow trap */
end_comment

begin_define
define|#
directive|define
name|T_BOUND
value|21
end_define

begin_comment
comment|/* bound instruction fault */
end_comment

begin_define
define|#
directive|define
name|T_DNA
value|22
end_define

begin_comment
comment|/* device not available fault */
end_comment

begin_define
define|#
directive|define
name|T_DOUBLEFLT
value|23
end_define

begin_comment
comment|/* double fault */
end_comment

begin_define
define|#
directive|define
name|T_FPOPFLT
value|24
end_define

begin_comment
comment|/* fp coprocessor operand fetch fault */
end_comment

begin_define
define|#
directive|define
name|T_TSSFLT
value|25
end_define

begin_comment
comment|/* invalid tss fault */
end_comment

begin_define
define|#
directive|define
name|T_SEGNPFLT
value|26
end_define

begin_comment
comment|/* segment not present fault */
end_comment

begin_define
define|#
directive|define
name|T_STKFLT
value|27
end_define

begin_comment
comment|/* stack fault */
end_comment

begin_define
define|#
directive|define
name|T_MCHK
value|28
end_define

begin_comment
comment|/* machine check trap */
end_comment

begin_define
define|#
directive|define
name|T_XMMFLT
value|29
end_define

begin_comment
comment|/* SIMD floating-point exception */
end_comment

begin_define
define|#
directive|define
name|T_RESERVED
value|30
end_define

begin_comment
comment|/* reserved (unknown) */
end_comment

begin_comment
comment|/* XXX most of the following codes aren't used, but could be. */
end_comment

begin_comment
comment|/* definitions for<sys/signal.h> */
end_comment

begin_define
define|#
directive|define
name|ILL_RESAD_FAULT
value|T_RESADFLT
end_define

begin_define
define|#
directive|define
name|ILL_PRIVIN_FAULT
value|T_PRIVINFLT
end_define

begin_define
define|#
directive|define
name|ILL_RESOP_FAULT
value|T_RESOPFLT
end_define

begin_define
define|#
directive|define
name|ILL_ALIGN_FAULT
value|T_ALIGNFLT
end_define

begin_define
define|#
directive|define
name|ILL_FPOP_FAULT
value|T_FPOPFLT
end_define

begin_comment
comment|/* coprocessor operand fault */
end_comment

begin_comment
comment|/* portable macros for SIGFPE/ARITHTRAP */
end_comment

begin_define
define|#
directive|define
name|FPE_INTOVF
value|1
end_define

begin_comment
comment|/* integer overflow */
end_comment

begin_define
define|#
directive|define
name|FPE_INTDIV
value|2
end_define

begin_comment
comment|/* integer divide by zero */
end_comment

begin_define
define|#
directive|define
name|FPE_FLTDIV
value|3
end_define

begin_comment
comment|/* floating point divide by zero */
end_comment

begin_define
define|#
directive|define
name|FPE_FLTOVF
value|4
end_define

begin_comment
comment|/* floating point overflow */
end_comment

begin_define
define|#
directive|define
name|FPE_FLTUND
value|5
end_define

begin_comment
comment|/* floating point underflow */
end_comment

begin_define
define|#
directive|define
name|FPE_FLTRES
value|6
end_define

begin_comment
comment|/* floating point inexact result */
end_comment

begin_define
define|#
directive|define
name|FPE_FLTINV
value|7
end_define

begin_comment
comment|/* invalid floating point operation */
end_comment

begin_define
define|#
directive|define
name|FPE_FLTSUB
value|8
end_define

begin_comment
comment|/* subscript out of range */
end_comment

begin_comment
comment|/* old FreeBSD macros, deprecated */
end_comment

begin_define
define|#
directive|define
name|FPE_INTOVF_TRAP
value|0x1
end_define

begin_comment
comment|/* integer overflow */
end_comment

begin_define
define|#
directive|define
name|FPE_INTDIV_TRAP
value|0x2
end_define

begin_comment
comment|/* integer divide by zero */
end_comment

begin_define
define|#
directive|define
name|FPE_FLTDIV_TRAP
value|0x3
end_define

begin_comment
comment|/* floating/decimal divide by zero */
end_comment

begin_define
define|#
directive|define
name|FPE_FLTOVF_TRAP
value|0x4
end_define

begin_comment
comment|/* floating overflow */
end_comment

begin_define
define|#
directive|define
name|FPE_FLTUND_TRAP
value|0x5
end_define

begin_comment
comment|/* floating underflow */
end_comment

begin_define
define|#
directive|define
name|FPE_FPU_NP_TRAP
value|0x6
end_define

begin_comment
comment|/* floating point unit not present  */
end_comment

begin_define
define|#
directive|define
name|FPE_SUBRNG_TRAP
value|0x7
end_define

begin_comment
comment|/* subrange out of bounds */
end_comment

begin_comment
comment|/* codes for SIGBUS */
end_comment

begin_define
define|#
directive|define
name|BUS_PAGE_FAULT
value|T_PAGEFLT
end_define

begin_comment
comment|/* page fault protection base */
end_comment

begin_define
define|#
directive|define
name|BUS_SEGNP_FAULT
value|T_SEGNPFLT
end_define

begin_comment
comment|/* segment not present */
end_comment

begin_define
define|#
directive|define
name|BUS_STK_FAULT
value|T_STKFLT
end_define

begin_comment
comment|/* stack segment */
end_comment

begin_define
define|#
directive|define
name|BUS_SEGM_FAULT
value|T_RESERVED
end_define

begin_comment
comment|/* segment protection base */
end_comment

begin_comment
comment|/* Trap's coming from user mode */
end_comment

begin_define
define|#
directive|define
name|T_USER
value|0x100
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_TRAP_H_ */
end_comment

end_unit

