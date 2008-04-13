begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2000 Opsycon Open System Consulting AB	 (www.opsycon.se)  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Opsycon Open System  *	Consulting AB, Sweden under contract to QED, Inc.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS  * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	JNPR: rm7000.h,v 1.2.4.1 2007/08/29 12:06:30 girish  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_RM7000_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_RM7000_H_
end_define

begin_comment
comment|/*  *  QED RM7000 specific defines.  */
end_comment

begin_comment
comment|/*  *  Performance counters.  */
end_comment

begin_define
define|#
directive|define
name|PCNT_SRC_CLOCKS
value|0x00
end_define

begin_comment
comment|/* Clock cycles */
end_comment

begin_define
define|#
directive|define
name|PCNT_SRC_INSTR
value|0x01
end_define

begin_comment
comment|/* Total instructions issued */
end_comment

begin_define
define|#
directive|define
name|PCNT_SRC_FPINSTR
value|0x02
end_define

begin_comment
comment|/* Float instructions issued */
end_comment

begin_define
define|#
directive|define
name|PCNT_SRC_IINSTR
value|0x03
end_define

begin_comment
comment|/* Integer instructions issued */
end_comment

begin_define
define|#
directive|define
name|PCNT_SRC_LOAD
value|0x04
end_define

begin_comment
comment|/* Load instructions issued */
end_comment

begin_define
define|#
directive|define
name|PCNT_SRC_STORE
value|0x05
end_define

begin_comment
comment|/* Store instructions issued */
end_comment

begin_define
define|#
directive|define
name|PCNT_SRC_DUAL
value|0x06
end_define

begin_comment
comment|/* Dual issued pairs */
end_comment

begin_define
define|#
directive|define
name|PCNT_SRC_BRPREF
value|0x07
end_define

begin_comment
comment|/* Branch prefetches */
end_comment

begin_define
define|#
directive|define
name|PCNT_SRC_EXTMISS
value|0x08
end_define

begin_comment
comment|/* External cache misses */
end_comment

begin_define
define|#
directive|define
name|PCNT_SRC_STALL
value|0x09
end_define

begin_comment
comment|/* Stall cycles */
end_comment

begin_define
define|#
directive|define
name|PCNT_SRC_SECMISS
value|0x0a
end_define

begin_comment
comment|/* Secondary cache misses */
end_comment

begin_define
define|#
directive|define
name|PCNT_SRC_INSMISS
value|0x0b
end_define

begin_comment
comment|/* Instruction cache misses */
end_comment

begin_define
define|#
directive|define
name|PCNT_SRC_DTAMISS
value|0x0c
end_define

begin_comment
comment|/* Data cache misses */
end_comment

begin_define
define|#
directive|define
name|PCNT_SRC_DTLBMISS
value|0x0d
end_define

begin_comment
comment|/* Data TLB misses */
end_comment

begin_define
define|#
directive|define
name|PCNT_SRC_ITLBMISS
value|0x0e
end_define

begin_comment
comment|/* Instruction TLB misses */
end_comment

begin_define
define|#
directive|define
name|PCNT_SRC_JTLBIMISS
value|0x0f
end_define

begin_comment
comment|/* Joint TLB instruction misses */
end_comment

begin_define
define|#
directive|define
name|PCNT_SRC_JTLBDMISS
value|0x10
end_define

begin_comment
comment|/* Joint TLB data misses */
end_comment

begin_define
define|#
directive|define
name|PCNT_SRC_BRTAKEN
value|0x11
end_define

begin_comment
comment|/* Branches taken */
end_comment

begin_define
define|#
directive|define
name|PCNT_SRC_BRISSUED
value|0x12
end_define

begin_comment
comment|/* Branches issued */
end_comment

begin_define
define|#
directive|define
name|PCNT_SRC_SECWBACK
value|0x13
end_define

begin_comment
comment|/* Secondary cache writebacks */
end_comment

begin_define
define|#
directive|define
name|PCNT_SRC_PRIWBACK
value|0x14
end_define

begin_comment
comment|/* Primary cache writebacks */
end_comment

begin_define
define|#
directive|define
name|PCNT_SRC_DCSTALL
value|0x15
end_define

begin_comment
comment|/* Dcache miss stall cycles */
end_comment

begin_define
define|#
directive|define
name|PCNT_SRC_MISS
value|0x16
end_define

begin_comment
comment|/* Cache misses */
end_comment

begin_define
define|#
directive|define
name|PCNT_SRC_FPEXC
value|0x17
end_define

begin_comment
comment|/* FP possible execption cycles */
end_comment

begin_define
define|#
directive|define
name|PCNT_SRC_MULSLIP
value|0x18
end_define

begin_comment
comment|/* Slip cycles due to mult. busy */
end_comment

begin_define
define|#
directive|define
name|PCNT_SRC_CP0SLIP
value|0x19
end_define

begin_comment
comment|/* CP0 Slip cycles */
end_comment

begin_define
define|#
directive|define
name|PCNT_SRC_LDSLIP
value|0x1a
end_define

begin_comment
comment|/* Slip cycles	due to pend. non-b ld */
end_comment

begin_define
define|#
directive|define
name|PCNT_SRC_WBFULL
value|0x1b
end_define

begin_comment
comment|/* Write buffer full stall cycles  */
end_comment

begin_define
define|#
directive|define
name|PCNT_SRC_CISTALL
value|0x1c
end_define

begin_comment
comment|/* Cache instruction stall cycles  */
end_comment

begin_define
define|#
directive|define
name|PCNT_SRC_MULSTALL
value|0x1d
end_define

begin_comment
comment|/* Multiplier stall cycles  */
end_comment

begin_define
define|#
directive|define
name|PCNT_SRC_ELDSTALL
value|0x1d
end_define

begin_comment
comment|/* Excepion stall due to non-b ld */
end_comment

begin_define
define|#
directive|define
name|PCNT_SRC_MAX
value|0x1d
end_define

begin_comment
comment|/* Maximum PCNT select code */
end_comment

begin_comment
comment|/*  *  Counter control bits.  */
end_comment

begin_define
define|#
directive|define
name|PCNT_CE
value|0x0400
end_define

begin_comment
comment|/* Count enable */
end_comment

begin_define
define|#
directive|define
name|PCNT_UM
value|0x0200
end_define

begin_comment
comment|/* Count in User mode */
end_comment

begin_define
define|#
directive|define
name|PCNT_KM
value|0x0100
end_define

begin_comment
comment|/* Count in kernel mode */
end_comment

begin_comment
comment|/*  *  Performance counter system call function codes.  */
end_comment

begin_define
define|#
directive|define
name|PCNT_FNC_SELECT
value|0x0001
end_define

begin_comment
comment|/* Select counter source */
end_comment

begin_define
define|#
directive|define
name|PCNT_FNC_READ
value|0x0002
end_define

begin_comment
comment|/* Read current value of counter */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_RM7000_H_ */
end_comment

end_unit

