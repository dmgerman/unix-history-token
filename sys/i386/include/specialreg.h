begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)specialreg.h	7.1 (Berkeley) 5/9/91  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_SPECIALREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_SPECIALREG_H_
end_define

begin_comment
comment|/*  * Bits in 386 special registers:  */
end_comment

begin_define
define|#
directive|define
name|CR0_PE
value|0x00000001
end_define

begin_comment
comment|/* Protected mode Enable */
end_comment

begin_define
define|#
directive|define
name|CR0_MP
value|0x00000002
end_define

begin_comment
comment|/* "Math" Present (NPX or NPX emulator) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|notused
end_ifdef

begin_define
define|#
directive|define
name|CR0_EM
value|0x00000004
end_define

begin_comment
comment|/* EMulate non-NPX coproc. (trap ESC only) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CR0_TS
value|0x00000008
end_define

begin_comment
comment|/* Task Switched (if MP, trap ESC and WAIT) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|notused
end_ifdef

begin_define
define|#
directive|define
name|CR0_ET
value|0x00000010
end_define

begin_comment
comment|/* Extension Type (387 (if set) vs 287) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CR0_PG
value|0x80000000
end_define

begin_comment
comment|/* PaGing enable */
end_comment

begin_comment
comment|/*  * Bits in 486 special registers:  */
end_comment

begin_define
define|#
directive|define
name|CR0_NE
value|0x00000020
end_define

begin_comment
comment|/* Numeric Error enable (EX16 vs IRQ13) */
end_comment

begin_define
define|#
directive|define
name|CR0_WP
value|0x00010000
end_define

begin_comment
comment|/* Write Protect (honor page protect in all modes) */
end_comment

begin_define
define|#
directive|define
name|CR0_AM
value|0x00040000
end_define

begin_comment
comment|/* Alignment Mask (set to enable AC flag) */
end_comment

begin_comment
comment|/*  * Cyrix 486 DLC special registers, accessable as IO ports.  */
end_comment

begin_define
define|#
directive|define
name|CCR0
value|0xc0
end_define

begin_comment
comment|/* configuration control register 0 */
end_comment

begin_define
define|#
directive|define
name|CCR0_NC0
value|0x01
end_define

begin_comment
comment|/* first 64K of each 1M memory region is 				   non-cacheable */
end_comment

begin_define
define|#
directive|define
name|CCR0_NC1
value|0x02
end_define

begin_comment
comment|/* 640K-1M region is non-cacheable */
end_comment

begin_define
define|#
directive|define
name|CCR0_A20M
value|0x04
end_define

begin_comment
comment|/* enables A20M# input pin */
end_comment

begin_define
define|#
directive|define
name|CCR0_KEN
value|0x08
end_define

begin_comment
comment|/* enables KEN# input pin */
end_comment

begin_define
define|#
directive|define
name|CCR0_FLUSH
value|0x10
end_define

begin_comment
comment|/* enables FLUSH# input pin */
end_comment

begin_define
define|#
directive|define
name|CCR0_BARB
value|0x20
end_define

begin_comment
comment|/* flushes internal cache when entering hold 				   state */
end_comment

begin_define
define|#
directive|define
name|CCR0_CO
value|0x40
end_define

begin_comment
comment|/* cache org: 1=direct mapped, 0=2x set assoc */
end_comment

begin_define
define|#
directive|define
name|CCR0_SUSPEND
value|0x80
end_define

begin_comment
comment|/* enables SUSP# and SUSPA# pins */
end_comment

begin_define
define|#
directive|define
name|CCR1
value|0xc1
end_define

begin_comment
comment|/* configuration control register 1 */
end_comment

begin_define
define|#
directive|define
name|CCR1_RPL
value|0x01
end_define

begin_comment
comment|/* enables RPLSET and RPLVAL# pins */
end_comment

begin_comment
comment|/* the remaining 7 bits of this register are reserved */
end_comment

begin_comment
comment|/*  * the following four 3-byte registers control the non-cacheable regions.  * These registers must be written as three seperate bytes.  *  * NCRx+0: A31-A24 of starting address  * NCRx+1: A23-A16 of starting address  * NCRx+2: A15-A12 of starting address | NCR_SIZE_xx.  *  * The non-cacheable region's starting address must be aligned to the  * size indicated by the NCR_SIZE_xx field.  */
end_comment

begin_define
define|#
directive|define
name|NCR1
value|0xc4
end_define

begin_define
define|#
directive|define
name|NCR2
value|0xc7
end_define

begin_define
define|#
directive|define
name|NCR3
value|0xca
end_define

begin_define
define|#
directive|define
name|NCR4
value|0xcd
end_define

begin_define
define|#
directive|define
name|NCR_SIZE_0K
value|0
end_define

begin_define
define|#
directive|define
name|NCR_SIZE_4K
value|1
end_define

begin_define
define|#
directive|define
name|NCR_SIZE_8K
value|2
end_define

begin_define
define|#
directive|define
name|NCR_SIZE_16K
value|3
end_define

begin_define
define|#
directive|define
name|NCR_SIZE_32K
value|4
end_define

begin_define
define|#
directive|define
name|NCR_SIZE_64K
value|5
end_define

begin_define
define|#
directive|define
name|NCR_SIZE_128K
value|6
end_define

begin_define
define|#
directive|define
name|NCR_SIZE_256K
value|7
end_define

begin_define
define|#
directive|define
name|NCR_SIZE_512K
value|8
end_define

begin_define
define|#
directive|define
name|NCR_SIZE_1M
value|9
end_define

begin_define
define|#
directive|define
name|NCR_SIZE_2M
value|10
end_define

begin_define
define|#
directive|define
name|NCR_SIZE_4M
value|11
end_define

begin_define
define|#
directive|define
name|NCR_SIZE_8M
value|12
end_define

begin_define
define|#
directive|define
name|NCR_SIZE_16M
value|13
end_define

begin_define
define|#
directive|define
name|NCR_SIZE_32M
value|14
end_define

begin_define
define|#
directive|define
name|NCR_SIZE_4G
value|15
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_SPECIALREG_H_ */
end_comment

end_unit

