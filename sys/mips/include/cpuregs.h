begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: cpuregs.h,v 1.70 2006/05/15 02:26:54 simonb Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell and Rick Macklem.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)machConst.h 8.1 (Berkeley) 6/10/93  *  * machConst.h --  *  *	Machine dependent constants.  *  *	Copyright (C) 1989 Digital Equipment Corporation.  *	Permission to use, copy, modify, and distribute this software and  *	its documentation for any purpose and without fee is hereby granted,  *	provided that the above copyright notice appears in all copies.  *	Digital Equipment Corporation makes no representations about the  *	suitability of this software for any purpose.  It is provided "as is"  *	without express or implied warranty.  *  * from: Header: /sprite/src/kernel/mach/ds3100.md/RCS/machConst.h,  *	v 9.2 89/10/21 15:55:22 jhh Exp	 SPRITE (DECWRL)  * from: Header: /sprite/src/kernel/mach/ds3100.md/RCS/machAddrs.h,  *	v 1.2 89/08/15 18:28:21 rab Exp	 SPRITE (DECWRL)  * from: Header: /sprite/src/kernel/vm/ds3100.md/RCS/vmPmaxConst.h,  *	v 9.1 89/09/18 17:33:00 shirriff Exp  SPRITE (DECWRL)  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MIPS_CPUREGS_H_
end_ifndef

begin_define
define|#
directive|define
name|_MIPS_CPUREGS_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/* For __CONCAT() */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL_OPT
argument_list|)
end_if

begin_include
include|#
directive|include
file|"opt_cputype.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Address space.  * 32-bit mips CPUS partition their 32-bit address space into four segments:  *  * kuseg   0x00000000 - 0x7fffffff  User virtual mem,  mapped  * kseg0   0x80000000 - 0x9fffffff  Physical memory, cached, unmapped  * kseg1   0xa0000000 - 0xbfffffff  Physical memory, uncached, unmapped  * kseg2   0xc0000000 - 0xffffffff  kernel-virtual,  mapped  *  * mips1 physical memory is limited to 512Mbytes, which is  * doubly mapped in kseg0 (cached) and kseg1 (uncached.)  * Caching of mapped addresses is controlled by bits in the TLB entry.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_KUSEG_START
value|0x0
end_define

begin_define
define|#
directive|define
name|MIPS_KSEG0_START
value|0x80000000
end_define

begin_define
define|#
directive|define
name|MIPS_KSEG0_END
value|0x9fffffff
end_define

begin_define
define|#
directive|define
name|MIPS_KSEG1_START
value|0xa0000000
end_define

begin_define
define|#
directive|define
name|MIPS_KSEG1_END
value|0xbfffffff
end_define

begin_define
define|#
directive|define
name|MIPS_KSSEG_START
value|0xc0000000
end_define

begin_define
define|#
directive|define
name|MIPS_KSSEG_END
value|0xdfffffff
end_define

begin_define
define|#
directive|define
name|MIPS_KSEG2_START
value|MIPS_KSSEG_START
end_define

begin_define
define|#
directive|define
name|MIPS_KSEG2_END
value|MIPS_KSSEG_END
end_define

begin_define
define|#
directive|define
name|MIPS_KSEG3_START
value|0xe0000000
end_define

begin_define
define|#
directive|define
name|MIPS_KSEG3_END
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|MIPS_MAX_MEM_ADDR
value|0xbe000000
end_define

begin_define
define|#
directive|define
name|MIPS_RESERVED_ADDR
value|0xbfc80000
end_define

begin_comment
comment|/* Map virtual address to index in mips3 r4k virtually-indexed cache */
end_comment

begin_define
define|#
directive|define
name|MIPS3_VA_TO_CINDEX
parameter_list|(
name|x
parameter_list|)
define|\
value|((unsigned)(x)& 0xffffff | MIPS_KSEG0_START)
end_define

begin_define
define|#
directive|define
name|MIPS_PHYS_TO_XKPHYS
parameter_list|(
name|cca
parameter_list|,
name|x
parameter_list|)
define|\
value|((0x2ULL<< 62) | ((unsigned long long)(cca)<< 59) | (x))
end_define

begin_define
define|#
directive|define
name|MIPS_XKPHYS_TO_PHYS
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x0effffffffffffffULL)
end_define

begin_comment
comment|/* CPU dependent mtc0 hazard hook */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TARGET_OCTEON
end_ifdef

begin_define
define|#
directive|define
name|COP0_SYNC
value|nop; nop; nop; nop; nop;
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|CPU_SB1
argument_list|)
end_elif

begin_define
define|#
directive|define
name|COP0_SYNC
value|ssnop; ssnop; ssnop; ssnop; ssnop; ssnop; ssnop; ssnop; ssnop
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * Pick a reasonable default based on the "typical" spacing described in the  * "CP0 Hazards" chapter of MIPS Architecture Book Vol III.  */
end_comment

begin_define
define|#
directive|define
name|COP0_SYNC
value|ssnop; ssnop; ssnop; ssnop; ssnop
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|COP0_HAZARD_FPUENABLE
value|nop; nop; nop; nop;
end_define

begin_comment
comment|/*  * The bits in the cause register.  *  * Bits common to r3000 and r4000:  *  *	MIPS_CR_BR_DELAY	Exception happened in branch delay slot.  *	MIPS_CR_COP_ERR		Coprocessor error.  *	MIPS_CR_IP		Interrupt pending bits defined below.  *				(same meaning as in CAUSE register).  *	MIPS_CR_EXC_CODE	The exception type (see exception codes below).  *  * Differences:  *  r3k has 4 bits of execption type, r4k has 5 bits.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_CR_BR_DELAY
value|0x80000000
end_define

begin_define
define|#
directive|define
name|MIPS_CR_COP_ERR
value|0x30000000
end_define

begin_define
define|#
directive|define
name|MIPS1_CR_EXC_CODE
value|0x0000003C
end_define

begin_comment
comment|/* four bits */
end_comment

begin_define
define|#
directive|define
name|MIPS3_CR_EXC_CODE
value|0x0000007C
end_define

begin_comment
comment|/* five bits */
end_comment

begin_define
define|#
directive|define
name|MIPS_CR_IP
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|MIPS_CR_EXC_CODE_SHIFT
value|2
end_define

begin_comment
comment|/*  * The bits in the status register.  All bits are active when set to 1.  *  *	R3000 status register fields:  *	MIPS_SR_COP_USABILITY	Control the usability of the four coprocessors.  *	MIPS_SR_TS		TLB shutdown.  *  *	MIPS_SR_INT_IE		Master (current) interrupt enable bit.  *  * Differences:  *	r3k has cache control is via frobbing SR register bits, whereas the  *	r4k cache control is via explicit instructions.  *	r3k has a 3-entry stack of kernel/user bits, whereas the  *	r4k has kernel/supervisor/user.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_SR_COP_USABILITY
value|0xf0000000
end_define

begin_define
define|#
directive|define
name|MIPS_SR_COP_0_BIT
value|0x10000000
end_define

begin_define
define|#
directive|define
name|MIPS_SR_COP_1_BIT
value|0x20000000
end_define

begin_define
define|#
directive|define
name|MIPS_SR_COP_2_BIT
value|0x40000000
end_define

begin_comment
comment|/* r4k and r3k differences, see below */
end_comment

begin_define
define|#
directive|define
name|MIPS_SR_MX
value|0x01000000
end_define

begin_comment
comment|/* MIPS64 */
end_comment

begin_define
define|#
directive|define
name|MIPS_SR_PX
value|0x00800000
end_define

begin_comment
comment|/* MIPS64 */
end_comment

begin_define
define|#
directive|define
name|MIPS_SR_BEV
value|0x00400000
end_define

begin_comment
comment|/* Use boot exception vector */
end_comment

begin_define
define|#
directive|define
name|MIPS_SR_TS
value|0x00200000
end_define

begin_define
define|#
directive|define
name|MIPS_SR_DE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|MIPS_SR_INT_IE
value|0x00000001
end_define

begin_comment
comment|/*#define MIPS_SR_MBZ		0x0f8000c0*/
end_comment

begin_comment
comment|/* Never used, true for r3k */
end_comment

begin_comment
comment|/*#define MIPS_SR_INT_MASK	0x0000ff00*/
end_comment

begin_comment
comment|/*  * The R2000/R3000-specific status register bit definitions.  * all bits are active when set to 1.  *  *	MIPS_SR_PARITY_ERR	Parity error.  *	MIPS_SR_CACHE_MISS	Most recent D-cache load resulted in a miss.  *	MIPS_SR_PARITY_ZERO	Zero replaces outgoing parity bits.  *	MIPS_SR_SWAP_CACHES	Swap I-cache and D-cache.  *	MIPS_SR_ISOL_CACHES	Isolate D-cache from main memory.  *				Interrupt enable bits defined below.  *	MIPS_SR_KU_OLD		Old kernel/user mode bit. 1 => user mode.  *	MIPS_SR_INT_ENA_OLD	Old interrupt enable bit.  *	MIPS_SR_KU_PREV		Previous kernel/user mode bit. 1 => user mode.  *	MIPS_SR_INT_ENA_PREV	Previous interrupt enable bit.  *	MIPS_SR_KU_CUR		Current kernel/user mode bit. 1 => user mode.  */
end_comment

begin_define
define|#
directive|define
name|MIPS1_PARITY_ERR
value|0x00100000
end_define

begin_define
define|#
directive|define
name|MIPS1_CACHE_MISS
value|0x00080000
end_define

begin_define
define|#
directive|define
name|MIPS1_PARITY_ZERO
value|0x00040000
end_define

begin_define
define|#
directive|define
name|MIPS1_SWAP_CACHES
value|0x00020000
end_define

begin_define
define|#
directive|define
name|MIPS1_ISOL_CACHES
value|0x00010000
end_define

begin_define
define|#
directive|define
name|MIPS1_SR_KU_OLD
value|0x00000020
end_define

begin_comment
comment|/* 2nd stacked KU/IE*/
end_comment

begin_define
define|#
directive|define
name|MIPS1_SR_INT_ENA_OLD
value|0x00000010
end_define

begin_comment
comment|/* 2nd stacked KU/IE*/
end_comment

begin_define
define|#
directive|define
name|MIPS1_SR_KU_PREV
value|0x00000008
end_define

begin_comment
comment|/* 1st stacked KU/IE*/
end_comment

begin_define
define|#
directive|define
name|MIPS1_SR_INT_ENA_PREV
value|0x00000004
end_define

begin_comment
comment|/* 1st stacked KU/IE*/
end_comment

begin_define
define|#
directive|define
name|MIPS1_SR_KU_CUR
value|0x00000002
end_define

begin_comment
comment|/* current KU */
end_comment

begin_comment
comment|/* backwards compatibility */
end_comment

begin_define
define|#
directive|define
name|MIPS_SR_PARITY_ERR
value|MIPS1_PARITY_ERR
end_define

begin_define
define|#
directive|define
name|MIPS_SR_CACHE_MISS
value|MIPS1_CACHE_MISS
end_define

begin_define
define|#
directive|define
name|MIPS_SR_PARITY_ZERO
value|MIPS1_PARITY_ZERO
end_define

begin_define
define|#
directive|define
name|MIPS_SR_SWAP_CACHES
value|MIPS1_SWAP_CACHES
end_define

begin_define
define|#
directive|define
name|MIPS_SR_ISOL_CACHES
value|MIPS1_ISOL_CACHES
end_define

begin_define
define|#
directive|define
name|MIPS_SR_KU_OLD
value|MIPS1_SR_KU_OLD
end_define

begin_define
define|#
directive|define
name|MIPS_SR_INT_ENA_OLD
value|MIPS1_SR_INT_ENA_OLD
end_define

begin_define
define|#
directive|define
name|MIPS_SR_KU_PREV
value|MIPS1_SR_KU_PREV
end_define

begin_define
define|#
directive|define
name|MIPS_SR_KU_CUR
value|MIPS1_SR_KU_CUR
end_define

begin_define
define|#
directive|define
name|MIPS_SR_INT_ENA_PREV
value|MIPS1_SR_INT_ENA_PREV
end_define

begin_comment
comment|/*  * R4000 status register bit definitons,  * where different from r2000/r3000.  */
end_comment

begin_define
define|#
directive|define
name|MIPS3_SR_XX
value|0x80000000
end_define

begin_define
define|#
directive|define
name|MIPS3_SR_RP
value|0x08000000
end_define

begin_define
define|#
directive|define
name|MIPS3_SR_FR
value|0x04000000
end_define

begin_define
define|#
directive|define
name|MIPS3_SR_RE
value|0x02000000
end_define

begin_define
define|#
directive|define
name|MIPS3_SR_DIAG_DL
value|0x01000000
end_define

begin_comment
comment|/* QED 52xx */
end_comment

begin_define
define|#
directive|define
name|MIPS3_SR_DIAG_IL
value|0x00800000
end_define

begin_comment
comment|/* QED 52xx */
end_comment

begin_define
define|#
directive|define
name|MIPS3_SR_SR
value|0x00100000
end_define

begin_define
define|#
directive|define
name|MIPS3_SR_NMI
value|0x00080000
end_define

begin_comment
comment|/* MIPS32/64 */
end_comment

begin_define
define|#
directive|define
name|MIPS3_SR_DIAG_CH
value|0x00040000
end_define

begin_define
define|#
directive|define
name|MIPS3_SR_DIAG_CE
value|0x00020000
end_define

begin_define
define|#
directive|define
name|MIPS3_SR_DIAG_PE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|MIPS3_SR_EIE
value|0x00010000
end_define

begin_comment
comment|/* TX79/R5900 */
end_comment

begin_define
define|#
directive|define
name|MIPS3_SR_KX
value|0x00000080
end_define

begin_define
define|#
directive|define
name|MIPS3_SR_SX
value|0x00000040
end_define

begin_define
define|#
directive|define
name|MIPS3_SR_UX
value|0x00000020
end_define

begin_define
define|#
directive|define
name|MIPS3_SR_KSU_MASK
value|0x00000018
end_define

begin_define
define|#
directive|define
name|MIPS3_SR_KSU_USER
value|0x00000010
end_define

begin_define
define|#
directive|define
name|MIPS3_SR_KSU_SUPER
value|0x00000008
end_define

begin_define
define|#
directive|define
name|MIPS3_SR_KSU_KERNEL
value|0x00000000
end_define

begin_define
define|#
directive|define
name|MIPS3_SR_ERL
value|0x00000004
end_define

begin_define
define|#
directive|define
name|MIPS3_SR_EXL
value|0x00000002
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|MIPS3_5900
end_ifdef

begin_undef
undef|#
directive|undef
name|MIPS_SR_INT_IE
end_undef

begin_define
define|#
directive|define
name|MIPS_SR_INT_IE
value|0x00010001
end_define

begin_comment
comment|/* XXX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * These definitions are for MIPS32 processors.  */
end_comment

begin_define
define|#
directive|define
name|MIPS32_SR_RP
value|0x08000000
end_define

begin_comment
comment|/* reduced power mode */
end_comment

begin_define
define|#
directive|define
name|MIPS32_SR_FR
value|0x04000000
end_define

begin_comment
comment|/* 64-bit capable fpu */
end_comment

begin_define
define|#
directive|define
name|MIPS32_SR_RE
value|0x02000000
end_define

begin_comment
comment|/* reverse user endian */
end_comment

begin_define
define|#
directive|define
name|MIPS32_SR_MX
value|0x01000000
end_define

begin_comment
comment|/* MIPS64 */
end_comment

begin_define
define|#
directive|define
name|MIPS32_SR_PX
value|0x00800000
end_define

begin_comment
comment|/* MIPS64 */
end_comment

begin_define
define|#
directive|define
name|MIPS32_SR_BEV
value|0x00400000
end_define

begin_comment
comment|/* Use boot exception vector */
end_comment

begin_define
define|#
directive|define
name|MIPS32_SR_TS
value|0x00200000
end_define

begin_comment
comment|/* TLB multiple match */
end_comment

begin_define
define|#
directive|define
name|MIPS32_SR_SOFT_RESET
value|0x00100000
end_define

begin_comment
comment|/* soft reset occurred */
end_comment

begin_define
define|#
directive|define
name|MIPS32_SR_NMI
value|0x00080000
end_define

begin_comment
comment|/* NMI occurred */
end_comment

begin_define
define|#
directive|define
name|MIPS32_SR_INT_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|MIPS32_SR_KX
value|0x00000080
end_define

begin_comment
comment|/* MIPS64 */
end_comment

begin_define
define|#
directive|define
name|MIPS32_SR_SX
value|0x00000040
end_define

begin_comment
comment|/* MIPS64 */
end_comment

begin_define
define|#
directive|define
name|MIPS32_SR_UX
value|0x00000020
end_define

begin_comment
comment|/* MIPS64 */
end_comment

begin_define
define|#
directive|define
name|MIPS32_SR_KSU_MASK
value|0x00000018
end_define

begin_comment
comment|/* privilege mode */
end_comment

begin_define
define|#
directive|define
name|MIPS32_SR_KSU_USER
value|0x00000010
end_define

begin_define
define|#
directive|define
name|MIPS32_SR_KSU_SUPER
value|0x00000008
end_define

begin_define
define|#
directive|define
name|MIPS32_SR_KSU_KERNEL
value|0x00000000
end_define

begin_define
define|#
directive|define
name|MIPS32_SR_ERL
value|0x00000004
end_define

begin_comment
comment|/* error level */
end_comment

begin_define
define|#
directive|define
name|MIPS32_SR_EXL
value|0x00000002
end_define

begin_comment
comment|/* exception level */
end_comment

begin_define
define|#
directive|define
name|MIPS_SR_SOFT_RESET
value|MIPS3_SR_SR
end_define

begin_define
define|#
directive|define
name|MIPS_SR_DIAG_CH
value|MIPS3_SR_DIAG_CH
end_define

begin_define
define|#
directive|define
name|MIPS_SR_DIAG_CE
value|MIPS3_SR_DIAG_CE
end_define

begin_define
define|#
directive|define
name|MIPS_SR_DIAG_PE
value|MIPS3_SR_DIAG_PE
end_define

begin_define
define|#
directive|define
name|MIPS_SR_KX
value|MIPS3_SR_KX
end_define

begin_define
define|#
directive|define
name|MIPS_SR_SX
value|MIPS3_SR_SX
end_define

begin_define
define|#
directive|define
name|MIPS_SR_UX
value|MIPS3_SR_UX
end_define

begin_define
define|#
directive|define
name|MIPS_SR_KSU_MASK
value|MIPS3_SR_KSU_MASK
end_define

begin_define
define|#
directive|define
name|MIPS_SR_KSU_USER
value|MIPS3_SR_KSU_USER
end_define

begin_define
define|#
directive|define
name|MIPS_SR_KSU_SUPER
value|MIPS3_SR_KSU_SUPER
end_define

begin_define
define|#
directive|define
name|MIPS_SR_KSU_KERNEL
value|MIPS3_SR_KSU_KERNEL
end_define

begin_define
define|#
directive|define
name|MIPS_SR_ERL
value|MIPS3_SR_ERL
end_define

begin_define
define|#
directive|define
name|MIPS_SR_EXL
value|MIPS3_SR_EXL
end_define

begin_comment
comment|/*  * The interrupt masks.  * If a bit in the mask is 1 then the interrupt is enabled (or pending).  */
end_comment

begin_define
define|#
directive|define
name|MIPS_INT_MASK
value|0xff00
end_define

begin_define
define|#
directive|define
name|MIPS_INT_MASK_5
value|0x8000
end_define

begin_define
define|#
directive|define
name|MIPS_INT_MASK_4
value|0x4000
end_define

begin_define
define|#
directive|define
name|MIPS_INT_MASK_3
value|0x2000
end_define

begin_define
define|#
directive|define
name|MIPS_INT_MASK_2
value|0x1000
end_define

begin_define
define|#
directive|define
name|MIPS_INT_MASK_1
value|0x0800
end_define

begin_define
define|#
directive|define
name|MIPS_INT_MASK_0
value|0x0400
end_define

begin_define
define|#
directive|define
name|MIPS_HARD_INT_MASK
value|0xfc00
end_define

begin_define
define|#
directive|define
name|MIPS_SOFT_INT_MASK_1
value|0x0200
end_define

begin_define
define|#
directive|define
name|MIPS_SOFT_INT_MASK_0
value|0x0100
end_define

begin_comment
comment|/*  * mips3 CPUs have on-chip timer at INT_MASK_5.  Each platform can  * choose to enable this interrupt.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MIPS3_ENABLE_CLOCK_INTR
argument_list|)
end_if

begin_define
define|#
directive|define
name|MIPS3_INT_MASK
value|MIPS_INT_MASK
end_define

begin_define
define|#
directive|define
name|MIPS3_HARD_INT_MASK
value|MIPS_HARD_INT_MASK
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MIPS3_INT_MASK
value|(MIPS_INT_MASK&  ~MIPS_INT_MASK_5)
end_define

begin_define
define|#
directive|define
name|MIPS3_HARD_INT_MASK
value|(MIPS_HARD_INT_MASK& ~MIPS_INT_MASK_5)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The bits in the context register.  */
end_comment

begin_define
define|#
directive|define
name|MIPS1_CNTXT_PTE_BASE
value|0xFFE00000
end_define

begin_define
define|#
directive|define
name|MIPS1_CNTXT_BAD_VPN
value|0x001FFFFC
end_define

begin_define
define|#
directive|define
name|MIPS3_CNTXT_PTE_BASE
value|0xFF800000
end_define

begin_define
define|#
directive|define
name|MIPS3_CNTXT_BAD_VPN2
value|0x007FFFF0
end_define

begin_comment
comment|/*  * Location of MIPS32 exception vectors. Most are multiplexed in  * the sense that further decoding is necessary (e.g. reading the  * CAUSE register or NMI bits in STATUS).  * Most interrupts go via the   * The INT vector is dedicated for hardware interrupts; it is  * only referenced if the IV bit in CAUSE is set to 1.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_VEC_RESET
value|0xBFC00000
end_define

begin_comment
comment|/* Hard, soft, or NMI */
end_comment

begin_define
define|#
directive|define
name|MIPS_VEC_EJTAG
value|0xBFC00480
end_define

begin_define
define|#
directive|define
name|MIPS_VEC_TLB
value|0x80000000
end_define

begin_define
define|#
directive|define
name|MIPS_VEC_XTLB
value|0x80000080
end_define

begin_define
define|#
directive|define
name|MIPS_VEC_CACHE
value|0x80000100
end_define

begin_define
define|#
directive|define
name|MIPS_VEC_GENERIC
value|0x80000180
end_define

begin_comment
comment|/* Most exceptions */
end_comment

begin_define
define|#
directive|define
name|MIPS_VEC_INTERRUPT
value|0x80000200
end_define

begin_comment
comment|/*  * The bits in the MIPS3 config register.  *  *	bit 0..5: R/W, Bit 6..31: R/O  */
end_comment

begin_comment
comment|/* kseg0 coherency algorithm - see MIPS3_TLB_ATTR values */
end_comment

begin_define
define|#
directive|define
name|MIPS3_CONFIG_K0_MASK
value|0x00000007
end_define

begin_comment
comment|/*  * R/W Update on Store Conditional  *	0: Store Conditional uses coherency algorithm specified by TLB  *	1: Store Conditional uses cacheable coherent update on write  */
end_comment

begin_define
define|#
directive|define
name|MIPS3_CONFIG_CU
value|0x00000008
end_define

begin_define
define|#
directive|define
name|MIPS3_CONFIG_DB
value|0x00000010
end_define

begin_comment
comment|/* Primary D-cache line size */
end_comment

begin_define
define|#
directive|define
name|MIPS3_CONFIG_IB
value|0x00000020
end_define

begin_comment
comment|/* Primary I-cache line size */
end_comment

begin_define
define|#
directive|define
name|MIPS3_CONFIG_CACHE_L1_LSIZE
parameter_list|(
name|config
parameter_list|,
name|bit
parameter_list|)
define|\
value|(((config)& (bit)) ? 32 : 16)
end_define

begin_define
define|#
directive|define
name|MIPS3_CONFIG_DC_MASK
value|0x000001c0
end_define

begin_comment
comment|/* Primary D-cache size */
end_comment

begin_define
define|#
directive|define
name|MIPS3_CONFIG_DC_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|MIPS3_CONFIG_IC_MASK
value|0x00000e00
end_define

begin_comment
comment|/* Primary I-cache size */
end_comment

begin_define
define|#
directive|define
name|MIPS3_CONFIG_IC_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|MIPS3_CONFIG_C_DEFBASE
value|0x1000
end_define

begin_comment
comment|/* default base 2^12 */
end_comment

begin_comment
comment|/* Cache size mode indication: available only on Vr41xx CPUs */
end_comment

begin_define
define|#
directive|define
name|MIPS3_CONFIG_CS
value|0x00001000
end_define

begin_define
define|#
directive|define
name|MIPS3_CONFIG_C_4100BASE
value|0x0400
end_define

begin_comment
comment|/* base is 2^10 if CS=1 */
end_comment

begin_define
define|#
directive|define
name|MIPS3_CONFIG_CACHE_SIZE
parameter_list|(
name|config
parameter_list|,
name|mask
parameter_list|,
name|base
parameter_list|,
name|shift
parameter_list|)
define|\
value|((base)<< (((config)& (mask))>> (shift)))
end_define

begin_comment
comment|/* External cache enable: Controls L2 for R5000/Rm527x and L3 for Rm7000 */
end_comment

begin_define
define|#
directive|define
name|MIPS3_CONFIG_SE
value|0x00001000
end_define

begin_comment
comment|/* Block ordering: 0: sequential, 1: sub-block */
end_comment

begin_define
define|#
directive|define
name|MIPS3_CONFIG_EB
value|0x00002000
end_define

begin_comment
comment|/* ECC mode - 0: ECC mode, 1: parity mode */
end_comment

begin_define
define|#
directive|define
name|MIPS3_CONFIG_EM
value|0x00004000
end_define

begin_comment
comment|/* BigEndianMem - 0: kernel and memory are little endian, 1: big endian */
end_comment

begin_define
define|#
directive|define
name|MIPS3_CONFIG_BE
value|0x00008000
end_define

begin_comment
comment|/* Dirty Shared coherency state - 0: enabled, 1: disabled */
end_comment

begin_define
define|#
directive|define
name|MIPS3_CONFIG_SM
value|0x00010000
end_define

begin_comment
comment|/* Secondary Cache - 0: present, 1: not present */
end_comment

begin_define
define|#
directive|define
name|MIPS3_CONFIG_SC
value|0x00020000
end_define

begin_comment
comment|/* System Port width - 0: 64-bit, 1: 32-bit (QED RM523x), 2,3: reserved */
end_comment

begin_define
define|#
directive|define
name|MIPS3_CONFIG_EW_MASK
value|0x000c0000
end_define

begin_define
define|#
directive|define
name|MIPS3_CONFIG_EW_SHIFT
value|18
end_define

begin_comment
comment|/* Secondary Cache port width - 0: 128-bit data path to S-cache, 1: reserved */
end_comment

begin_define
define|#
directive|define
name|MIPS3_CONFIG_SW
value|0x00100000
end_define

begin_comment
comment|/* Split Secondary Cache Mode - 0: I/D mixed, 1: I/D separated by SCAddr(17) */
end_comment

begin_define
define|#
directive|define
name|MIPS3_CONFIG_SS
value|0x00200000
end_define

begin_comment
comment|/* Secondary Cache line size */
end_comment

begin_define
define|#
directive|define
name|MIPS3_CONFIG_SB_MASK
value|0x00c00000
end_define

begin_define
define|#
directive|define
name|MIPS3_CONFIG_SB_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|MIPS3_CONFIG_CACHE_L2_LSIZE
parameter_list|(
name|config
parameter_list|)
define|\
value|(0x10<< (((config)& MIPS3_CONFIG_SB_MASK)>> MIPS3_CONFIG_SB_SHIFT))
end_define

begin_comment
comment|/* Write back data rate */
end_comment

begin_define
define|#
directive|define
name|MIPS3_CONFIG_EP_MASK
value|0x0f000000
end_define

begin_define
define|#
directive|define
name|MIPS3_CONFIG_EP_SHIFT
value|24
end_define

begin_comment
comment|/* System clock ratio - this value is CPU dependent */
end_comment

begin_define
define|#
directive|define
name|MIPS3_CONFIG_EC_MASK
value|0x70000000
end_define

begin_define
define|#
directive|define
name|MIPS3_CONFIG_EC_SHIFT
value|28
end_define

begin_comment
comment|/* Master-Checker Mode - 1: enabled */
end_comment

begin_define
define|#
directive|define
name|MIPS3_CONFIG_CM
value|0x80000000
end_define

begin_comment
comment|/*  * The bits in the MIPS4 config register.  */
end_comment

begin_comment
comment|/* kseg0 coherency algorithm - see MIPS3_TLB_ATTR values */
end_comment

begin_define
define|#
directive|define
name|MIPS4_CONFIG_K0_MASK
value|MIPS3_CONFIG_K0_MASK
end_define

begin_define
define|#
directive|define
name|MIPS4_CONFIG_DN_MASK
value|0x00000018
end_define

begin_comment
comment|/* Device number */
end_comment

begin_define
define|#
directive|define
name|MIPS4_CONFIG_CT
value|0x00000020
end_define

begin_comment
comment|/* CohPrcReqTar */
end_comment

begin_define
define|#
directive|define
name|MIPS4_CONFIG_PE
value|0x00000040
end_define

begin_comment
comment|/* PreElmReq */
end_comment

begin_define
define|#
directive|define
name|MIPS4_CONFIG_PM_MASK
value|0x00000180
end_define

begin_comment
comment|/* PreReqMax */
end_comment

begin_define
define|#
directive|define
name|MIPS4_CONFIG_EC_MASK
value|0x00001e00
end_define

begin_comment
comment|/* SysClkDiv */
end_comment

begin_define
define|#
directive|define
name|MIPS4_CONFIG_SB
value|0x00002000
end_define

begin_comment
comment|/* SCBlkSize */
end_comment

begin_define
define|#
directive|define
name|MIPS4_CONFIG_SK
value|0x00004000
end_define

begin_comment
comment|/* SCColEn */
end_comment

begin_define
define|#
directive|define
name|MIPS4_CONFIG_BE
value|0x00008000
end_define

begin_comment
comment|/* MemEnd */
end_comment

begin_define
define|#
directive|define
name|MIPS4_CONFIG_SS_MASK
value|0x00070000
end_define

begin_comment
comment|/* SCSize */
end_comment

begin_define
define|#
directive|define
name|MIPS4_CONFIG_SC_MASK
value|0x00380000
end_define

begin_comment
comment|/* SCClkDiv */
end_comment

begin_define
define|#
directive|define
name|MIPS4_CONFIG_RESERVED
value|0x03c00000
end_define

begin_comment
comment|/* Reserved wired 0 */
end_comment

begin_define
define|#
directive|define
name|MIPS4_CONFIG_DC_MASK
value|0x1c000000
end_define

begin_comment
comment|/* Primary D-Cache size */
end_comment

begin_define
define|#
directive|define
name|MIPS4_CONFIG_IC_MASK
value|0xe0000000
end_define

begin_comment
comment|/* Primary I-Cache size */
end_comment

begin_define
define|#
directive|define
name|MIPS4_CONFIG_DC_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|MIPS4_CONFIG_IC_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|MIPS4_CONFIG_CACHE_SIZE
parameter_list|(
name|config
parameter_list|,
name|mask
parameter_list|,
name|base
parameter_list|,
name|shift
parameter_list|)
define|\
value|((base)<< (((config)& (mask))>> (shift)))
end_define

begin_define
define|#
directive|define
name|MIPS4_CONFIG_CACHE_L2_LSIZE
parameter_list|(
name|config
parameter_list|)
define|\
value|(((config)& MIPS4_CONFIG_SB) ? 128 : 64)
end_define

begin_comment
comment|/*  * Location of exception vectors.  *  * Common vectors:  reset and UTLB miss.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_RESET_EXC_VEC
value|0xBFC00000
end_define

begin_define
define|#
directive|define
name|MIPS_UTLB_MISS_EXC_VEC
value|0x80000000
end_define

begin_comment
comment|/*  * MIPS-1 general exception vector (everything else)  */
end_comment

begin_define
define|#
directive|define
name|MIPS1_GEN_EXC_VEC
value|0x80000080
end_define

begin_comment
comment|/*  * MIPS-III exception vectors  */
end_comment

begin_define
define|#
directive|define
name|MIPS3_XTLB_MISS_EXC_VEC
value|0x80000080
end_define

begin_define
define|#
directive|define
name|MIPS3_CACHE_ERR_EXC_VEC
value|0x80000100
end_define

begin_define
define|#
directive|define
name|MIPS3_GEN_EXC_VEC
value|0x80000180
end_define

begin_comment
comment|/*  * TX79 (R5900) exception vectors  */
end_comment

begin_define
define|#
directive|define
name|MIPS_R5900_COUNTER_EXC_VEC
value|0x80000080
end_define

begin_define
define|#
directive|define
name|MIPS_R5900_DEBUG_EXC_VEC
value|0x80000100
end_define

begin_comment
comment|/*  * MIPS32/MIPS64 (and some MIPS3) dedicated interrupt vector.  */
end_comment

begin_define
define|#
directive|define
name|MIPS3_INTR_EXC_VEC
value|0x80000200
end_define

begin_comment
comment|/*  * Coprocessor 0 registers:  *  *				v--- width for mips I,III,32,64  *				     (3=32bit, 6=64bit, i=impl dep)  *  0	MIPS_COP_0_TLB_INDEX	3333 TLB Index.  *  1	MIPS_COP_0_TLB_RANDOM	3333 TLB Random.  *  2	MIPS_COP_0_TLB_LOW	3... r3k TLB entry low.  *  2	MIPS_COP_0_TLB_LO0	.636 r4k TLB entry low.  *  3	MIPS_COP_0_TLB_LO1	.636 r4k TLB entry low, extended.  *  4	MIPS_COP_0_TLB_CONTEXT	3636 TLB Context.  *  5	MIPS_COP_0_TLB_PG_MASK	.333 TLB Page Mask register.  *  6	MIPS_COP_0_TLB_WIRED	.333 Wired TLB number.  *  8	MIPS_COP_0_BAD_VADDR	3636 Bad virtual address.  *  9	MIPS_COP_0_COUNT	.333 Count register.  * 10	MIPS_COP_0_TLB_HI	3636 TLB entry high.  * 11	MIPS_COP_0_COMPARE	.333 Compare (against Count).  * 12	MIPS_COP_0_STATUS	3333 Status register.  * 13	MIPS_COP_0_CAUSE	3333 Exception cause register.  * 14	MIPS_COP_0_EXC_PC	3636 Exception PC.  * 15	MIPS_COP_0_PRID		3333 Processor revision identifier.  * 16	MIPS_COP_0_CONFIG	3333 Configuration register.  * 16/1	MIPS_COP_0_CONFIG1	..33 Configuration register 1.  * 16/2	MIPS_COP_0_CONFIG2	..33 Configuration register 2.  * 16/3	MIPS_COP_0_CONFIG3	..33 Configuration register 3.  * 17	MIPS_COP_0_LLADDR	.336 Load Linked Address.  * 18	MIPS_COP_0_WATCH_LO	.336 WatchLo register.  * 19	MIPS_COP_0_WATCH_HI	.333 WatchHi register.  * 20	MIPS_COP_0_TLB_XCONTEXT .6.6 TLB XContext register.  * 23	MIPS_COP_0_DEBUG	.... Debug JTAG register.  * 24	MIPS_COP_0_DEPC		.... DEPC JTAG register.  * 25	MIPS_COP_0_PERFCNT	..36 Performance Counter register.  * 26	MIPS_COP_0_ECC		.3ii ECC / Error Control register.  * 27	MIPS_COP_0_CACHE_ERR	.3ii Cache Error register.  * 28/0	MIPS_COP_0_TAG_LO	.3ii Cache TagLo register (instr).  * 28/1	MIPS_COP_0_DATA_LO	..ii Cache DataLo register (instr).  * 28/2	MIPS_COP_0_TAG_LO	..ii Cache TagLo register (data).  * 28/3	MIPS_COP_0_DATA_LO	..ii Cache DataLo register (data).  * 29/0	MIPS_COP_0_TAG_HI	.3ii Cache TagHi register (instr).  * 29/1	MIPS_COP_0_DATA_HI	..ii Cache DataHi register (instr).  * 29/2	MIPS_COP_0_TAG_HI	..ii Cache TagHi register (data).  * 29/3	MIPS_COP_0_DATA_HI	..ii Cache DataHi register (data).  * 30	MIPS_COP_0_ERROR_PC	.636 Error EPC register.  * 31	MIPS_COP_0_DESAVE	.... DESAVE JTAG register.  */
end_comment

begin_comment
comment|/* Deal with inclusion from an assembly file. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_LOCORE
argument_list|)
operator|||
name|defined
argument_list|(
name|LOCORE
argument_list|)
end_if

begin_define
define|#
directive|define
name|_
parameter_list|(
name|n
parameter_list|)
value|$n
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_
parameter_list|(
name|n
parameter_list|)
value|n
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MIPS_COP_0_TLB_INDEX
value|_(0)
end_define

begin_define
define|#
directive|define
name|MIPS_COP_0_TLB_RANDOM
value|_(1)
end_define

begin_comment
comment|/* Name and meaning of	TLB bits for $2 differ on r3k and r4k. */
end_comment

begin_define
define|#
directive|define
name|MIPS_COP_0_TLB_CONTEXT
value|_(4)
end_define

begin_comment
comment|/* $5 and $6 new with MIPS-III */
end_comment

begin_define
define|#
directive|define
name|MIPS_COP_0_BAD_VADDR
value|_(8)
end_define

begin_define
define|#
directive|define
name|MIPS_COP_0_TLB_HI
value|_(10)
end_define

begin_define
define|#
directive|define
name|MIPS_COP_0_STATUS
value|_(12)
end_define

begin_define
define|#
directive|define
name|MIPS_COP_0_CAUSE
value|_(13)
end_define

begin_define
define|#
directive|define
name|MIPS_COP_0_EXC_PC
value|_(14)
end_define

begin_define
define|#
directive|define
name|MIPS_COP_0_PRID
value|_(15)
end_define

begin_comment
comment|/* MIPS-I */
end_comment

begin_define
define|#
directive|define
name|MIPS_COP_0_TLB_LOW
value|_(2)
end_define

begin_comment
comment|/* MIPS-III */
end_comment

begin_define
define|#
directive|define
name|MIPS_COP_0_TLB_LO0
value|_(2)
end_define

begin_define
define|#
directive|define
name|MIPS_COP_0_TLB_LO1
value|_(3)
end_define

begin_define
define|#
directive|define
name|MIPS_COP_0_TLB_PG_MASK
value|_(5)
end_define

begin_define
define|#
directive|define
name|MIPS_COP_0_TLB_WIRED
value|_(6)
end_define

begin_define
define|#
directive|define
name|MIPS_COP_0_COUNT
value|_(9)
end_define

begin_define
define|#
directive|define
name|MIPS_COP_0_COMPARE
value|_(11)
end_define

begin_define
define|#
directive|define
name|MIPS_COP_0_CONFIG
value|_(16)
end_define

begin_define
define|#
directive|define
name|MIPS_COP_0_LLADDR
value|_(17)
end_define

begin_define
define|#
directive|define
name|MIPS_COP_0_WATCH_LO
value|_(18)
end_define

begin_define
define|#
directive|define
name|MIPS_COP_0_WATCH_HI
value|_(19)
end_define

begin_define
define|#
directive|define
name|MIPS_COP_0_TLB_XCONTEXT
value|_(20)
end_define

begin_define
define|#
directive|define
name|MIPS_COP_0_ECC
value|_(26)
end_define

begin_define
define|#
directive|define
name|MIPS_COP_0_CACHE_ERR
value|_(27)
end_define

begin_define
define|#
directive|define
name|MIPS_COP_0_TAG_LO
value|_(28)
end_define

begin_define
define|#
directive|define
name|MIPS_COP_0_TAG_HI
value|_(29)
end_define

begin_define
define|#
directive|define
name|MIPS_COP_0_ERROR_PC
value|_(30)
end_define

begin_comment
comment|/* MIPS32/64 */
end_comment

begin_define
define|#
directive|define
name|MIPS_COP_0_DEBUG
value|_(23)
end_define

begin_define
define|#
directive|define
name|MIPS_COP_0_DEPC
value|_(24)
end_define

begin_define
define|#
directive|define
name|MIPS_COP_0_PERFCNT
value|_(25)
end_define

begin_define
define|#
directive|define
name|MIPS_COP_0_DATA_LO
value|_(28)
end_define

begin_define
define|#
directive|define
name|MIPS_COP_0_DATA_HI
value|_(29)
end_define

begin_define
define|#
directive|define
name|MIPS_COP_0_DESAVE
value|_(31)
end_define

begin_comment
comment|/* MIPS32 Config register definitions */
end_comment

begin_define
define|#
directive|define
name|MIPS_MMU_NONE
value|0x00
end_define

begin_comment
comment|/* No MMU present */
end_comment

begin_define
define|#
directive|define
name|MIPS_MMU_TLB
value|0x01
end_define

begin_comment
comment|/* Standard TLB */
end_comment

begin_define
define|#
directive|define
name|MIPS_MMU_BAT
value|0x02
end_define

begin_comment
comment|/* Standard BAT */
end_comment

begin_define
define|#
directive|define
name|MIPS_MMU_FIXED
value|0x03
end_define

begin_comment
comment|/* Standard fixed mapping */
end_comment

begin_define
define|#
directive|define
name|MIPS_CONFIG0_MT_MASK
value|0x00000380
end_define

begin_comment
comment|/* bits 9..7 MMU Type */
end_comment

begin_define
define|#
directive|define
name|MIPS_CONFIG0_MT_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|MIPS_CONFIG0_BE
value|0x00008000
end_define

begin_comment
comment|/* data is big-endian */
end_comment

begin_define
define|#
directive|define
name|MIPS_CONFIG0_VI
value|0x00000004
end_define

begin_comment
comment|/* instruction cache is virtual */
end_comment

begin_define
define|#
directive|define
name|MIPS_CONFIG1_TLBSZ_MASK
value|0x7E000000
end_define

begin_comment
comment|/* bits 30..25 # tlb entries minus one */
end_comment

begin_define
define|#
directive|define
name|MIPS_CONFIG1_TLBSZ_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|MIPS_CONFIG1_IS_MASK
value|0x01C00000
end_define

begin_comment
comment|/* bits 24..22 icache sets per way */
end_comment

begin_define
define|#
directive|define
name|MIPS_CONFIG1_IS_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|MIPS_CONFIG1_IL_MASK
value|0x00380000
end_define

begin_comment
comment|/* bits 21..19 icache line size */
end_comment

begin_define
define|#
directive|define
name|MIPS_CONFIG1_IL_SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|MIPS_CONFIG1_IA_MASK
value|0x00070000
end_define

begin_comment
comment|/* bits 18..16 icache associativity */
end_comment

begin_define
define|#
directive|define
name|MIPS_CONFIG1_IA_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|MIPS_CONFIG1_DS_MASK
value|0x0000E000
end_define

begin_comment
comment|/* bits 15..13 dcache sets per way */
end_comment

begin_define
define|#
directive|define
name|MIPS_CONFIG1_DS_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|MIPS_CONFIG1_DL_MASK
value|0x00001C00
end_define

begin_comment
comment|/* bits 12..10 dcache line size */
end_comment

begin_define
define|#
directive|define
name|MIPS_CONFIG1_DL_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|MIPS_CONFIG1_DA_MASK
value|0x00000380
end_define

begin_comment
comment|/* bits  9.. 7 dcache associativity */
end_comment

begin_define
define|#
directive|define
name|MIPS_CONFIG1_DA_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|MIPS_CONFIG1_LOWBITS
value|0x0000007F
end_define

begin_define
define|#
directive|define
name|MIPS_CONFIG1_C2
value|0x00000040
end_define

begin_comment
comment|/* Coprocessor 2 implemented */
end_comment

begin_define
define|#
directive|define
name|MIPS_CONFIG1_MD
value|0x00000020
end_define

begin_comment
comment|/* MDMX ASE implemented (MIPS64) */
end_comment

begin_define
define|#
directive|define
name|MIPS_CONFIG1_PC
value|0x00000010
end_define

begin_comment
comment|/* Performance counters implemented */
end_comment

begin_define
define|#
directive|define
name|MIPS_CONFIG1_WR
value|0x00000008
end_define

begin_comment
comment|/* Watch registers implemented */
end_comment

begin_define
define|#
directive|define
name|MIPS_CONFIG1_CA
value|0x00000004
end_define

begin_comment
comment|/* MIPS16e ISA implemented */
end_comment

begin_define
define|#
directive|define
name|MIPS_CONFIG1_EP
value|0x00000002
end_define

begin_comment
comment|/* EJTAG implemented */
end_comment

begin_define
define|#
directive|define
name|MIPS_CONFIG1_FP
value|0x00000001
end_define

begin_comment
comment|/* FPU implemented */
end_comment

begin_comment
comment|/*  * Values for the code field in a break instruction.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_BREAK_INSTR
value|0x0000000d
end_define

begin_define
define|#
directive|define
name|MIPS_BREAK_VAL_MASK
value|0x03ff0000
end_define

begin_define
define|#
directive|define
name|MIPS_BREAK_VAL_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|MIPS_BREAK_KDB_VAL
value|512
end_define

begin_define
define|#
directive|define
name|MIPS_BREAK_SSTEP_VAL
value|513
end_define

begin_define
define|#
directive|define
name|MIPS_BREAK_BRKPT_VAL
value|514
end_define

begin_define
define|#
directive|define
name|MIPS_BREAK_SOVER_VAL
value|515
end_define

begin_define
define|#
directive|define
name|MIPS_BREAK_KDB
value|(MIPS_BREAK_INSTR | \ 				(MIPS_BREAK_KDB_VAL<< MIPS_BREAK_VAL_SHIFT))
end_define

begin_define
define|#
directive|define
name|MIPS_BREAK_SSTEP
value|(MIPS_BREAK_INSTR | \ 				(MIPS_BREAK_SSTEP_VAL<< MIPS_BREAK_VAL_SHIFT))
end_define

begin_define
define|#
directive|define
name|MIPS_BREAK_BRKPT
value|(MIPS_BREAK_INSTR | \ 				(MIPS_BREAK_BRKPT_VAL<< MIPS_BREAK_VAL_SHIFT))
end_define

begin_define
define|#
directive|define
name|MIPS_BREAK_SOVER
value|(MIPS_BREAK_INSTR | \ 				(MIPS_BREAK_SOVER_VAL<< MIPS_BREAK_VAL_SHIFT))
end_define

begin_comment
comment|/*  * Mininum and maximum cache sizes.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_MIN_CACHE_SIZE
value|(16 * 1024)
end_define

begin_define
define|#
directive|define
name|MIPS_MAX_CACHE_SIZE
value|(256 * 1024)
end_define

begin_define
define|#
directive|define
name|MIPS3_MAX_PCACHE_SIZE
value|(32 * 1024)
end_define

begin_comment
comment|/* max. primary cache size */
end_comment

begin_comment
comment|/*  * The floating point version and status registers.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_FPU_ID
value|$0
end_define

begin_define
define|#
directive|define
name|MIPS_FPU_CSR
value|$31
end_define

begin_comment
comment|/*  * The floating point coprocessor status register bits.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_FPU_ROUNDING_BITS
value|0x00000003
end_define

begin_define
define|#
directive|define
name|MIPS_FPU_ROUND_RN
value|0x00000000
end_define

begin_define
define|#
directive|define
name|MIPS_FPU_ROUND_RZ
value|0x00000001
end_define

begin_define
define|#
directive|define
name|MIPS_FPU_ROUND_RP
value|0x00000002
end_define

begin_define
define|#
directive|define
name|MIPS_FPU_ROUND_RM
value|0x00000003
end_define

begin_define
define|#
directive|define
name|MIPS_FPU_STICKY_BITS
value|0x0000007c
end_define

begin_define
define|#
directive|define
name|MIPS_FPU_STICKY_INEXACT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|MIPS_FPU_STICKY_UNDERFLOW
value|0x00000008
end_define

begin_define
define|#
directive|define
name|MIPS_FPU_STICKY_OVERFLOW
value|0x00000010
end_define

begin_define
define|#
directive|define
name|MIPS_FPU_STICKY_DIV0
value|0x00000020
end_define

begin_define
define|#
directive|define
name|MIPS_FPU_STICKY_INVALID
value|0x00000040
end_define

begin_define
define|#
directive|define
name|MIPS_FPU_ENABLE_BITS
value|0x00000f80
end_define

begin_define
define|#
directive|define
name|MIPS_FPU_ENABLE_INEXACT
value|0x00000080
end_define

begin_define
define|#
directive|define
name|MIPS_FPU_ENABLE_UNDERFLOW
value|0x00000100
end_define

begin_define
define|#
directive|define
name|MIPS_FPU_ENABLE_OVERFLOW
value|0x00000200
end_define

begin_define
define|#
directive|define
name|MIPS_FPU_ENABLE_DIV0
value|0x00000400
end_define

begin_define
define|#
directive|define
name|MIPS_FPU_ENABLE_INVALID
value|0x00000800
end_define

begin_define
define|#
directive|define
name|MIPS_FPU_EXCEPTION_BITS
value|0x0003f000
end_define

begin_define
define|#
directive|define
name|MIPS_FPU_EXCEPTION_INEXACT
value|0x00001000
end_define

begin_define
define|#
directive|define
name|MIPS_FPU_EXCEPTION_UNDERFLOW
value|0x00002000
end_define

begin_define
define|#
directive|define
name|MIPS_FPU_EXCEPTION_OVERFLOW
value|0x00004000
end_define

begin_define
define|#
directive|define
name|MIPS_FPU_EXCEPTION_DIV0
value|0x00008000
end_define

begin_define
define|#
directive|define
name|MIPS_FPU_EXCEPTION_INVALID
value|0x00010000
end_define

begin_define
define|#
directive|define
name|MIPS_FPU_EXCEPTION_UNIMPL
value|0x00020000
end_define

begin_define
define|#
directive|define
name|MIPS_FPU_COND_BIT
value|0x00800000
end_define

begin_define
define|#
directive|define
name|MIPS_FPU_FLUSH_BIT
value|0x01000000
end_define

begin_comment
comment|/* r4k,	 MBZ on r3k */
end_comment

begin_define
define|#
directive|define
name|MIPS1_FPC_MBZ_BITS
value|0xff7c0000
end_define

begin_define
define|#
directive|define
name|MIPS3_FPC_MBZ_BITS
value|0xfe7c0000
end_define

begin_comment
comment|/*  * Constants to determine if have a floating point instruction.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_OPCODE_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|MIPS_OPCODE_C1
value|0x11
end_define

begin_comment
comment|/*  * The low part of the TLB entry.  */
end_comment

begin_define
define|#
directive|define
name|MIPS1_TLB_PFN
value|0xfffff000
end_define

begin_define
define|#
directive|define
name|MIPS1_TLB_NON_CACHEABLE_BIT
value|0x00000800
end_define

begin_define
define|#
directive|define
name|MIPS1_TLB_DIRTY_BIT
value|0x00000400
end_define

begin_define
define|#
directive|define
name|MIPS1_TLB_VALID_BIT
value|0x00000200
end_define

begin_define
define|#
directive|define
name|MIPS1_TLB_GLOBAL_BIT
value|0x00000100
end_define

begin_define
define|#
directive|define
name|MIPS3_TLB_PFN
value|0x3fffffc0
end_define

begin_define
define|#
directive|define
name|MIPS3_TLB_ATTR_MASK
value|0x00000038
end_define

begin_define
define|#
directive|define
name|MIPS3_TLB_ATTR_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|MIPS3_TLB_DIRTY_BIT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|MIPS3_TLB_VALID_BIT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|MIPS3_TLB_GLOBAL_BIT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|MIPS1_TLB_PHYS_PAGE_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|MIPS3_TLB_PHYS_PAGE_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|MIPS1_TLB_PF_NUM
value|MIPS1_TLB_PFN
end_define

begin_define
define|#
directive|define
name|MIPS3_TLB_PF_NUM
value|MIPS3_TLB_PFN
end_define

begin_define
define|#
directive|define
name|MIPS1_TLB_MOD_BIT
value|MIPS1_TLB_DIRTY_BIT
end_define

begin_define
define|#
directive|define
name|MIPS3_TLB_MOD_BIT
value|MIPS3_TLB_DIRTY_BIT
end_define

begin_comment
comment|/*  * MIPS3_TLB_ATTR values - coherency algorithm:  * 0: cacheable, noncoherent, write-through, no write allocate  * 1: cacheable, noncoherent, write-through, write allocate  * 2: uncached  * 3: cacheable, noncoherent, write-back (noncoherent)  * 4: cacheable, coherent, write-back, exclusive (exclusive)  * 5: cacheable, coherent, write-back, exclusive on write (sharable)  * 6: cacheable, coherent, write-back, update on write (update)  * 7: uncached, accelerated (gather STORE operations)  */
end_comment

begin_define
define|#
directive|define
name|MIPS3_TLB_ATTR_WT
value|0
end_define

begin_comment
comment|/* IDT */
end_comment

begin_define
define|#
directive|define
name|MIPS3_TLB_ATTR_WT_WRITEALLOCATE
value|1
end_define

begin_comment
comment|/* IDT */
end_comment

begin_define
define|#
directive|define
name|MIPS3_TLB_ATTR_UNCACHED
value|2
end_define

begin_comment
comment|/* R4000/R4400, IDT */
end_comment

begin_define
define|#
directive|define
name|MIPS3_TLB_ATTR_WB_NONCOHERENT
value|3
end_define

begin_comment
comment|/* R4000/R4400, IDT */
end_comment

begin_define
define|#
directive|define
name|MIPS3_TLB_ATTR_WB_EXCLUSIVE
value|4
end_define

begin_comment
comment|/* R4000/R4400 */
end_comment

begin_define
define|#
directive|define
name|MIPS3_TLB_ATTR_WB_SHARABLE
value|5
end_define

begin_comment
comment|/* R4000/R4400 */
end_comment

begin_define
define|#
directive|define
name|MIPS3_TLB_ATTR_WB_UPDATE
value|6
end_define

begin_comment
comment|/* R4000/R4400 */
end_comment

begin_define
define|#
directive|define
name|MIPS4_TLB_ATTR_UNCACHED_ACCELERATED
value|7
end_define

begin_comment
comment|/* R10000 */
end_comment

begin_comment
comment|/*  * The high part of the TLB entry.  */
end_comment

begin_define
define|#
directive|define
name|MIPS1_TLB_VPN
value|0xfffff000
end_define

begin_define
define|#
directive|define
name|MIPS1_TLB_PID
value|0x00000fc0
end_define

begin_define
define|#
directive|define
name|MIPS1_TLB_PID_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|MIPS3_TLB_VPN2
value|0xffffe000
end_define

begin_define
define|#
directive|define
name|MIPS3_TLB_ASID
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|MIPS1_TLB_VIRT_PAGE_NUM
value|MIPS1_TLB_VPN
end_define

begin_define
define|#
directive|define
name|MIPS3_TLB_VIRT_PAGE_NUM
value|MIPS3_TLB_VPN2
end_define

begin_define
define|#
directive|define
name|MIPS3_TLB_PID
value|MIPS3_TLB_ASID
end_define

begin_define
define|#
directive|define
name|MIPS_TLB_VIRT_PAGE_SHIFT
value|12
end_define

begin_comment
comment|/*  * r3000: shift count to put the index in the right spot.  */
end_comment

begin_define
define|#
directive|define
name|MIPS1_TLB_INDEX_SHIFT
value|8
end_define

begin_comment
comment|/*  * The first TLB that write random hits.  */
end_comment

begin_define
define|#
directive|define
name|MIPS1_TLB_FIRST_RAND_ENTRY
value|8
end_define

begin_define
define|#
directive|define
name|MIPS3_TLB_WIRED_UPAGES
value|1
end_define

begin_comment
comment|/*  * The number of process id entries.  */
end_comment

begin_define
define|#
directive|define
name|MIPS1_TLB_NUM_PIDS
value|64
end_define

begin_define
define|#
directive|define
name|MIPS3_TLB_NUM_ASIDS
value|256
end_define

begin_comment
comment|/*  * Patch codes to hide CPU design differences between MIPS1 and MIPS3.  */
end_comment

begin_comment
comment|/* XXX simonb: this is before MIPS3_PLUS is defined (and is ugly!) */
end_comment

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|MIPS3
argument_list|)
operator|||
name|defined
argument_list|(
name|MIPS4
argument_list|)
operator|||
name|defined
argument_list|(
name|MIPS32
argument_list|)
operator|||
name|defined
argument_list|(
name|MIPS64
argument_list|)
operator|)
expr|\
operator|&&
name|defined
argument_list|(
name|MIPS1
argument_list|)
end_if

begin_comment
comment|/* XXX simonb must be neater! */
end_comment

begin_define
define|#
directive|define
name|MIPS_TLB_PID_SHIFT
value|MIPS1_TLB_PID_SHIFT
end_define

begin_define
define|#
directive|define
name|MIPS_TLB_NUM_PIDS
value|MIPS1_TLB_NUM_PIDS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|MIPS3
argument_list|)
operator|||
name|defined
argument_list|(
name|MIPS4
argument_list|)
operator|||
name|defined
argument_list|(
name|MIPS32
argument_list|)
operator|||
name|defined
argument_list|(
name|MIPS64
argument_list|)
operator|)
expr|\
operator|&&
operator|!
name|defined
argument_list|(
name|MIPS1
argument_list|)
end_if

begin_comment
comment|/* XXX simonb must be neater! */
end_comment

begin_define
define|#
directive|define
name|MIPS_TLB_PID_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|MIPS_TLB_NUM_PIDS
value|MIPS3_TLB_NUM_ASIDS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MIPS_TLB_PID_SHIFT
argument_list|)
end_if

begin_define
define|#
directive|define
name|MIPS_TLB_PID_SHIFT
define|\
value|((MIPS_HAS_R4K_MMU) ? 0 : MIPS1_TLB_PID_SHIFT)
end_define

begin_define
define|#
directive|define
name|MIPS_TLB_NUM_PIDS
define|\
value|((MIPS_HAS_R4K_MMU) ? MIPS3_TLB_NUM_ASIDS : MIPS1_TLB_NUM_PIDS)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * CPU processor revision IDs for company ID == 0 (non mips32/64 chips)  */
end_comment

begin_define
define|#
directive|define
name|MIPS_R2000
value|0x01
end_define

begin_comment
comment|/* MIPS R2000 			ISA I	*/
end_comment

begin_define
define|#
directive|define
name|MIPS_R3000
value|0x02
end_define

begin_comment
comment|/* MIPS R3000 			ISA I	*/
end_comment

begin_define
define|#
directive|define
name|MIPS_R6000
value|0x03
end_define

begin_comment
comment|/* MIPS R6000 			ISA II	*/
end_comment

begin_define
define|#
directive|define
name|MIPS_R4000
value|0x04
end_define

begin_comment
comment|/* MIPS R4000/R4400 		ISA III */
end_comment

begin_define
define|#
directive|define
name|MIPS_R3LSI
value|0x05
end_define

begin_comment
comment|/* LSI Logic R3000 derivative	ISA I	*/
end_comment

begin_define
define|#
directive|define
name|MIPS_R6000A
value|0x06
end_define

begin_comment
comment|/* MIPS R6000A 			ISA II	*/
end_comment

begin_define
define|#
directive|define
name|MIPS_R3IDT
value|0x07
end_define

begin_comment
comment|/* IDT R3041 or RC36100 	ISA I	*/
end_comment

begin_define
define|#
directive|define
name|MIPS_R10000
value|0x09
end_define

begin_comment
comment|/* MIPS R10000			ISA IV	*/
end_comment

begin_define
define|#
directive|define
name|MIPS_R4200
value|0x0a
end_define

begin_comment
comment|/* NEC VR4200 			ISA III */
end_comment

begin_define
define|#
directive|define
name|MIPS_R4300
value|0x0b
end_define

begin_comment
comment|/* NEC VR4300 			ISA III */
end_comment

begin_define
define|#
directive|define
name|MIPS_R4100
value|0x0c
end_define

begin_comment
comment|/* NEC VR4100 			ISA III */
end_comment

begin_define
define|#
directive|define
name|MIPS_R12000
value|0x0e
end_define

begin_comment
comment|/* MIPS R12000			ISA IV	*/
end_comment

begin_define
define|#
directive|define
name|MIPS_R14000
value|0x0f
end_define

begin_comment
comment|/* MIPS R14000			ISA IV	*/
end_comment

begin_define
define|#
directive|define
name|MIPS_R8000
value|0x10
end_define

begin_comment
comment|/* MIPS R8000 Blackbird/TFP	ISA IV	*/
end_comment

begin_define
define|#
directive|define
name|MIPS_RC32300
value|0x18
end_define

begin_comment
comment|/* IDT RC32334,332,355		ISA 32  */
end_comment

begin_define
define|#
directive|define
name|MIPS_R4600
value|0x20
end_define

begin_comment
comment|/* QED R4600 Orion		ISA III */
end_comment

begin_define
define|#
directive|define
name|MIPS_R4700
value|0x21
end_define

begin_comment
comment|/* QED R4700 Orion		ISA III */
end_comment

begin_define
define|#
directive|define
name|MIPS_R3SONY
value|0x21
end_define

begin_comment
comment|/* Sony R3000 based 		ISA I	*/
end_comment

begin_define
define|#
directive|define
name|MIPS_R4650
value|0x22
end_define

begin_comment
comment|/* QED R4650 			ISA III */
end_comment

begin_define
define|#
directive|define
name|MIPS_TX3900
value|0x22
end_define

begin_comment
comment|/* Toshiba TX39 family		ISA I	*/
end_comment

begin_define
define|#
directive|define
name|MIPS_R5000
value|0x23
end_define

begin_comment
comment|/* MIPS R5000 			ISA IV	*/
end_comment

begin_define
define|#
directive|define
name|MIPS_R3NKK
value|0x23
end_define

begin_comment
comment|/* NKK R3000 based 		ISA I	*/
end_comment

begin_define
define|#
directive|define
name|MIPS_RC32364
value|0x26
end_define

begin_comment
comment|/* IDT RC32364 			ISA 32	*/
end_comment

begin_define
define|#
directive|define
name|MIPS_RM7000
value|0x27
end_define

begin_comment
comment|/* QED RM7000			ISA IV  */
end_comment

begin_define
define|#
directive|define
name|MIPS_RM5200
value|0x28
end_define

begin_comment
comment|/* QED RM5200s 			ISA IV	*/
end_comment

begin_define
define|#
directive|define
name|MIPS_TX4900
value|0x2d
end_define

begin_comment
comment|/* Toshiba TX49 family		ISA III */
end_comment

begin_define
define|#
directive|define
name|MIPS_R5900
value|0x2e
end_define

begin_comment
comment|/* Toshiba R5900 (EECore)	ISA --- */
end_comment

begin_define
define|#
directive|define
name|MIPS_RC64470
value|0x30
end_define

begin_comment
comment|/* IDT RC64474/RC64475 		ISA III */
end_comment

begin_define
define|#
directive|define
name|MIPS_TX7900
value|0x38
end_define

begin_comment
comment|/* Toshiba TX79			ISA III+*/
end_comment

begin_define
define|#
directive|define
name|MIPS_R5400
value|0x54
end_define

begin_comment
comment|/* NEC VR5400 			ISA IV	*/
end_comment

begin_define
define|#
directive|define
name|MIPS_R5500
value|0x55
end_define

begin_comment
comment|/* NEC VR5500 			ISA IV	*/
end_comment

begin_comment
comment|/*  * CPU revision IDs for some prehistoric processors.  */
end_comment

begin_comment
comment|/* For MIPS_R3000 */
end_comment

begin_define
define|#
directive|define
name|MIPS_REV_R3000
value|0x20
end_define

begin_define
define|#
directive|define
name|MIPS_REV_R3000A
value|0x30
end_define

begin_comment
comment|/* For MIPS_TX3900 */
end_comment

begin_define
define|#
directive|define
name|MIPS_REV_TX3912
value|0x10
end_define

begin_define
define|#
directive|define
name|MIPS_REV_TX3922
value|0x30
end_define

begin_define
define|#
directive|define
name|MIPS_REV_TX3927
value|0x40
end_define

begin_comment
comment|/* For MIPS_R4000 */
end_comment

begin_define
define|#
directive|define
name|MIPS_REV_R4000_A
value|0x00
end_define

begin_define
define|#
directive|define
name|MIPS_REV_R4000_B
value|0x22
end_define

begin_define
define|#
directive|define
name|MIPS_REV_R4000_C
value|0x30
end_define

begin_define
define|#
directive|define
name|MIPS_REV_R4400_A
value|0x40
end_define

begin_define
define|#
directive|define
name|MIPS_REV_R4400_B
value|0x50
end_define

begin_define
define|#
directive|define
name|MIPS_REV_R4400_C
value|0x60
end_define

begin_comment
comment|/* For MIPS_TX4900 */
end_comment

begin_define
define|#
directive|define
name|MIPS_REV_TX4927
value|0x22
end_define

begin_comment
comment|/*  * CPU processor revision IDs for company ID == 1 (MIPS)  */
end_comment

begin_define
define|#
directive|define
name|MIPS_4Kc
value|0x80
end_define

begin_comment
comment|/* MIPS 4Kc			ISA 32  */
end_comment

begin_define
define|#
directive|define
name|MIPS_5Kc
value|0x81
end_define

begin_comment
comment|/* MIPS 5Kc			ISA 64  */
end_comment

begin_define
define|#
directive|define
name|MIPS_20Kc
value|0x82
end_define

begin_comment
comment|/* MIPS 20Kc			ISA 64  */
end_comment

begin_define
define|#
directive|define
name|MIPS_4Kmp
value|0x83
end_define

begin_comment
comment|/* MIPS 4Km/4Kp			ISA 32  */
end_comment

begin_define
define|#
directive|define
name|MIPS_4KEc
value|0x84
end_define

begin_comment
comment|/* MIPS 4KEc			ISA 32  */
end_comment

begin_define
define|#
directive|define
name|MIPS_4KEmp
value|0x85
end_define

begin_comment
comment|/* MIPS 4KEm/4KEp		ISA 32  */
end_comment

begin_define
define|#
directive|define
name|MIPS_4KSc
value|0x86
end_define

begin_comment
comment|/* MIPS 4KSc			ISA 32  */
end_comment

begin_define
define|#
directive|define
name|MIPS_M4K
value|0x87
end_define

begin_comment
comment|/* MIPS M4K			ISA 32  Rel 2 */
end_comment

begin_define
define|#
directive|define
name|MIPS_25Kf
value|0x88
end_define

begin_comment
comment|/* MIPS 25Kf			ISA 64  */
end_comment

begin_define
define|#
directive|define
name|MIPS_5KE
value|0x89
end_define

begin_comment
comment|/* MIPS 5KE			ISA 64  Rel 2 */
end_comment

begin_define
define|#
directive|define
name|MIPS_4KEc_R2
value|0x90
end_define

begin_comment
comment|/* MIPS 4KEc_R2			ISA 32  Rel 2 */
end_comment

begin_define
define|#
directive|define
name|MIPS_4KEmp_R2
value|0x91
end_define

begin_comment
comment|/* MIPS 4KEm/4KEp_R2		ISA 32  Rel 2 */
end_comment

begin_define
define|#
directive|define
name|MIPS_4KSd
value|0x92
end_define

begin_comment
comment|/* MIPS 4KSd			ISA 32  Rel 2 */
end_comment

begin_define
define|#
directive|define
name|MIPS_24K
value|0x93
end_define

begin_comment
comment|/* MIPS 24Kc/24Kf		ISA 32  Rel 2 */
end_comment

begin_define
define|#
directive|define
name|MIPS_34K
value|0x95
end_define

begin_comment
comment|/* MIPS 34K			ISA 32  R2 MT */
end_comment

begin_define
define|#
directive|define
name|MIPS_24KE
value|0x96
end_define

begin_comment
comment|/* MIPS 24KEc			ISA 32  Rel 2 */
end_comment

begin_define
define|#
directive|define
name|MIPS_74K
value|0x97
end_define

begin_comment
comment|/* MIPS 74Kc/74Kf		ISA 32  Rel 2 */
end_comment

begin_comment
comment|/*  * AMD (company ID 3) use the processor ID field to donote the CPU core  * revision and the company options field do donate the SOC chip type.  */
end_comment

begin_comment
comment|/* CPU processor revision IDs */
end_comment

begin_define
define|#
directive|define
name|MIPS_AU_REV1
value|0x01
end_define

begin_comment
comment|/* Alchemy Au1000 (Rev 1)	ISA 32  */
end_comment

begin_define
define|#
directive|define
name|MIPS_AU_REV2
value|0x02
end_define

begin_comment
comment|/* Alchemy Au1000 (Rev 2)	ISA 32  */
end_comment

begin_comment
comment|/* CPU company options IDs */
end_comment

begin_define
define|#
directive|define
name|MIPS_AU1000
value|0x00
end_define

begin_define
define|#
directive|define
name|MIPS_AU1500
value|0x01
end_define

begin_define
define|#
directive|define
name|MIPS_AU1100
value|0x02
end_define

begin_define
define|#
directive|define
name|MIPS_AU1550
value|0x03
end_define

begin_comment
comment|/*  * CPU processor revision IDs for company ID == 4 (Broadcom)  */
end_comment

begin_define
define|#
directive|define
name|MIPS_SB1
value|0x01
end_define

begin_comment
comment|/* SiByte SB1	 		ISA 64  */
end_comment

begin_comment
comment|/*  * CPU processor revision IDs for company ID == 5 (SandCraft)  */
end_comment

begin_define
define|#
directive|define
name|MIPS_SR7100
value|0x04
end_define

begin_comment
comment|/* SandCraft SR7100 		ISA 64  */
end_comment

begin_comment
comment|/*  * FPU processor revision ID  */
end_comment

begin_define
define|#
directive|define
name|MIPS_SOFT
value|0x00
end_define

begin_comment
comment|/* Software emulation		ISA I	*/
end_comment

begin_define
define|#
directive|define
name|MIPS_R2360
value|0x01
end_define

begin_comment
comment|/* MIPS R2360 FPC		ISA I	*/
end_comment

begin_define
define|#
directive|define
name|MIPS_R2010
value|0x02
end_define

begin_comment
comment|/* MIPS R2010 FPC		ISA I	*/
end_comment

begin_define
define|#
directive|define
name|MIPS_R3010
value|0x03
end_define

begin_comment
comment|/* MIPS R3010 FPC		ISA I	*/
end_comment

begin_define
define|#
directive|define
name|MIPS_R6010
value|0x04
end_define

begin_comment
comment|/* MIPS R6010 FPC		ISA II	*/
end_comment

begin_define
define|#
directive|define
name|MIPS_R4010
value|0x05
end_define

begin_comment
comment|/* MIPS R4010 FPC		ISA II	*/
end_comment

begin_define
define|#
directive|define
name|MIPS_R31LSI
value|0x06
end_define

begin_comment
comment|/* LSI Logic derivate		ISA I	*/
end_comment

begin_define
define|#
directive|define
name|MIPS_R3TOSH
value|0x22
end_define

begin_comment
comment|/* Toshiba R3000 based FPU	ISA I	*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ENABLE_MIPS_TX3900
end_ifdef

begin_include
include|#
directive|include
file|<mips/r3900regs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MIPS3_5900
end_ifdef

begin_include
include|#
directive|include
file|<mips/r5900regs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MIPS64_SB1
end_ifdef

begin_include
include|#
directive|include
file|<mips/sb1regs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MIPS_CPUREGS_H_ */
end_comment

end_unit

