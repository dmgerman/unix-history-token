begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1995, 1996 Wolfgang Solfrank.  * Copyright (C) 1995, 1996 TooLs GmbH.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by TooLs GmbH.  * 4. The name of TooLs GmbH may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY TOOLS GMBH ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$NetBSD: trap.h,v 1.3 2000/05/25 21:10:14 is Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POWERPC_TRAP_H_
end_ifndef

begin_define
define|#
directive|define
name|_POWERPC_TRAP_H_
end_define

begin_define
define|#
directive|define
name|EXC_RSVD
value|0x0000
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|EXC_RST
value|0x0100
end_define

begin_comment
comment|/* Reset */
end_comment

begin_define
define|#
directive|define
name|EXC_MCHK
value|0x0200
end_define

begin_comment
comment|/* Machine Check */
end_comment

begin_define
define|#
directive|define
name|EXC_DSI
value|0x0300
end_define

begin_comment
comment|/* Data Storage Interrupt */
end_comment

begin_define
define|#
directive|define
name|EXC_ISI
value|0x0400
end_define

begin_comment
comment|/* Instruction Storage Interrupt */
end_comment

begin_define
define|#
directive|define
name|EXC_EXI
value|0x0500
end_define

begin_comment
comment|/* External Interrupt */
end_comment

begin_define
define|#
directive|define
name|EXC_ALI
value|0x0600
end_define

begin_comment
comment|/* Alignment Interrupt */
end_comment

begin_define
define|#
directive|define
name|EXC_PGM
value|0x0700
end_define

begin_comment
comment|/* Program Interrupt */
end_comment

begin_define
define|#
directive|define
name|EXC_FPU
value|0x0800
end_define

begin_comment
comment|/* Floating-point Unavailable */
end_comment

begin_define
define|#
directive|define
name|EXC_DECR
value|0x0900
end_define

begin_comment
comment|/* Decrementer Interrupt */
end_comment

begin_define
define|#
directive|define
name|EXC_SC
value|0x0c00
end_define

begin_comment
comment|/* System Call */
end_comment

begin_define
define|#
directive|define
name|EXC_TRC
value|0x0d00
end_define

begin_comment
comment|/* Trace */
end_comment

begin_define
define|#
directive|define
name|EXC_FPA
value|0x0e00
end_define

begin_comment
comment|/* Floating-point Assist */
end_comment

begin_comment
comment|/* The following are only available on 604: */
end_comment

begin_define
define|#
directive|define
name|EXC_PERF
value|0x0f00
end_define

begin_comment
comment|/* Performance Monitoring */
end_comment

begin_define
define|#
directive|define
name|EXC_BPT
value|0x1300
end_define

begin_comment
comment|/* Instruction Breakpoint */
end_comment

begin_define
define|#
directive|define
name|EXC_SMI
value|0x1400
end_define

begin_comment
comment|/* System Management Interrupt */
end_comment

begin_comment
comment|/* And these are only on the 603: */
end_comment

begin_define
define|#
directive|define
name|EXC_IMISS
value|0x1000
end_define

begin_comment
comment|/* Instruction translation miss */
end_comment

begin_define
define|#
directive|define
name|EXC_DLMISS
value|0x1100
end_define

begin_comment
comment|/* Data load translation miss */
end_comment

begin_define
define|#
directive|define
name|EXC_DSMISS
value|0x1200
end_define

begin_comment
comment|/* Data store translation miss */
end_comment

begin_define
define|#
directive|define
name|EXC_LAST
value|0x2f00
end_define

begin_comment
comment|/* Last possible exception vector */
end_comment

begin_comment
comment|/* Trap was in user mode */
end_comment

begin_define
define|#
directive|define
name|EXC_USER
value|0x10000
end_define

begin_comment
comment|/*  * EXC_ALI sets bits in the DSISR and DAR to provide enough  * information to recover from the unaligned access without needing to  * parse the offending instruction. This includes certain bits of the  * opcode, and information about what registers are used. The opcode  * indicator values below come from Appendix F of Book III of "The  * PowerPC Architecture".  */
end_comment

begin_define
define|#
directive|define
name|EXC_ALI_OPCODE_INDICATOR
parameter_list|(
name|dsisr
parameter_list|)
value|((dsisr>> 10)& 0x7f)
end_define

begin_define
define|#
directive|define
name|EXC_ALI_LFD
value|0x09
end_define

begin_define
define|#
directive|define
name|EXC_ALI_STFD
value|0x0b
end_define

begin_comment
comment|/* Macros to extract register information */
end_comment

begin_define
define|#
directive|define
name|EXC_ALI_RST
parameter_list|(
name|dsisr
parameter_list|)
value|((dsisr>> 5)& 0x1f)
end_define

begin_comment
comment|/* source or target */
end_comment

begin_define
define|#
directive|define
name|EXC_ALI_RA
parameter_list|(
name|dsisr
parameter_list|)
value|(dsisr& 0x1f)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_function_decl
name|void
name|trap
parameter_list|(
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|syscall
parameter_list|(
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POWERPC_TRAP_H_ */
end_comment

end_unit

