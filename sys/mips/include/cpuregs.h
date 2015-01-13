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

begin_comment
comment|/*  * Address space.  * 32-bit mips CPUS partition their 32-bit address space into four segments:  *  * kuseg   0x00000000 - 0x7fffffff  User virtual mem,  mapped  * kseg0   0x80000000 - 0x9fffffff  Physical memory, cached, unmapped  * kseg1   0xa0000000 - 0xbfffffff  Physical memory, uncached, unmapped  * kseg2   0xc0000000 - 0xffffffff  kernel-virtual,  mapped  *  * Caching of mapped addresses is controlled by bits in the TLB entry.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_KSEG0_LARGEST_PHYS
value|(0x20000000)
end_define

begin_define
define|#
directive|define
name|MIPS_KSEG0_PHYS_MASK
value|(0x1fffffff)
end_define

begin_define
define|#
directive|define
name|MIPS_XKPHYS_LARGEST_PHYS
value|(0x10000000000)
end_define

begin_comment
comment|/* 40 bit PA */
end_comment

begin_define
define|#
directive|define
name|MIPS_XKPHYS_PHYS_MASK
value|(0x0ffffffffff)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_define
define|#
directive|define
name|MIPS_KUSEG_START
value|0x00000000
end_define

begin_define
define|#
directive|define
name|MIPS_KSEG0_START
value|((intptr_t)(int32_t)0x80000000)
end_define

begin_define
define|#
directive|define
name|MIPS_KSEG0_END
value|((intptr_t)(int32_t)0x9fffffff)
end_define

begin_define
define|#
directive|define
name|MIPS_KSEG1_START
value|((intptr_t)(int32_t)0xa0000000)
end_define

begin_define
define|#
directive|define
name|MIPS_KSEG1_END
value|((intptr_t)(int32_t)0xbfffffff)
end_define

begin_define
define|#
directive|define
name|MIPS_KSSEG_START
value|((intptr_t)(int32_t)0xc0000000)
end_define

begin_define
define|#
directive|define
name|MIPS_KSSEG_END
value|((intptr_t)(int32_t)0xdfffffff)
end_define

begin_define
define|#
directive|define
name|MIPS_KSEG3_START
value|((intptr_t)(int32_t)0xe0000000)
end_define

begin_define
define|#
directive|define
name|MIPS_KSEG3_END
value|((intptr_t)(int32_t)0xffffffff)
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

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MIPS_PHYS_TO_KSEG0
parameter_list|(
name|x
parameter_list|)
value|((uintptr_t)(x) | MIPS_KSEG0_START)
end_define

begin_define
define|#
directive|define
name|MIPS_PHYS_TO_KSEG1
parameter_list|(
name|x
parameter_list|)
value|((uintptr_t)(x) | MIPS_KSEG1_START)
end_define

begin_define
define|#
directive|define
name|MIPS_KSEG0_TO_PHYS
parameter_list|(
name|x
parameter_list|)
value|((uintptr_t)(x)& MIPS_KSEG0_PHYS_MASK)
end_define

begin_define
define|#
directive|define
name|MIPS_KSEG1_TO_PHYS
parameter_list|(
name|x
parameter_list|)
value|((uintptr_t)(x)& MIPS_KSEG0_PHYS_MASK)
end_define

begin_define
define|#
directive|define
name|MIPS_IS_KSEG0_ADDR
parameter_list|(
name|x
parameter_list|)
define|\
value|(((vm_offset_t)(x)>= MIPS_KSEG0_START)&&		\ 	    ((vm_offset_t)(x)<= MIPS_KSEG0_END))
end_define

begin_define
define|#
directive|define
name|MIPS_IS_KSEG1_ADDR
parameter_list|(
name|x
parameter_list|)
define|\
value|(((vm_offset_t)(x)>= MIPS_KSEG1_START)&&		\ 	    ((vm_offset_t)(x)<= MIPS_KSEG1_END))
end_define

begin_define
define|#
directive|define
name|MIPS_IS_VALID_PTR
parameter_list|(
name|x
parameter_list|)
value|(MIPS_IS_KSEG0_ADDR(x) || \ 					    MIPS_IS_KSEG1_ADDR(x))
end_define

begin_comment
comment|/*  * Cache Coherency Attributes:  *	UC:	Uncached.  *	UA:	Uncached accelerated.  *	C:	Cacheable, coherency unspecified.  *	CNC:	Cacheable non-coherent.  *	CC:	Cacheable coherent.  *	CCE:	Cacheable coherent, exclusive read.  *	CCEW:	Cacheable coherent, exclusive write.  *	CCUOW:	Cacheable coherent, update on write.  *  * Note that some bits vary in meaning across implementations (and that the  * listing here is no doubt incomplete) and that the optimal cached mode varies  * between implementations.  0x02 is required to be UC and 0x03 is required to  * be a least C.  *  * We define the following logical bits:  * 	UNCACHED:  * 		The optimal uncached mode for the target CPU type.  This must  * 		be suitable for use in accessing memory-mapped devices.  * 	CACHED:	The optional cached mode for the target CPU type.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_CCA_UC
value|0x02
end_define

begin_comment
comment|/* Uncached. */
end_comment

begin_define
define|#
directive|define
name|MIPS_CCA_C
value|0x03
end_define

begin_comment
comment|/* Cacheable, coherency unspecified. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_R4000
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_R10000
argument_list|)
end_if

begin_define
define|#
directive|define
name|MIPS_CCA_CNC
value|0x03
end_define

begin_define
define|#
directive|define
name|MIPS_CCA_CCE
value|0x04
end_define

begin_define
define|#
directive|define
name|MIPS_CCA_CCEW
value|0x05
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_R4000
end_ifdef

begin_define
define|#
directive|define
name|MIPS_CCA_CCUOW
value|0x06
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_R10000
end_ifdef

begin_define
define|#
directive|define
name|MIPS_CCA_UA
value|0x07
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MIPS_CCA_CACHED
value|MIPS_CCA_CCEW
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(CPU_R4000) || defined(CPU_R10000) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_SB1
argument_list|)
end_if

begin_define
define|#
directive|define
name|MIPS_CCA_CC
value|0x05
end_define

begin_comment
comment|/* Cacheable Coherent. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_MIPS74KC
argument_list|)
end_if

begin_define
define|#
directive|define
name|MIPS_CCA_UNCACHED
value|0x02
end_define

begin_define
define|#
directive|define
name|MIPS_CCA_CACHED
value|0x00
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MIPS_CCA_UNCACHED
end_ifndef

begin_define
define|#
directive|define
name|MIPS_CCA_UNCACHED
value|MIPS_CCA_UC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * If we don't know which cached mode to use and there is a cache coherent  * mode, use it.  If there is not a cache coherent mode, use the required  * cacheable mode.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MIPS_CCA_CACHED
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|MIPS_CCA_CC
end_ifdef

begin_define
define|#
directive|define
name|MIPS_CCA_CACHED
value|MIPS_CCA_CC
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MIPS_CCA_CACHED
value|MIPS_CCA_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

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
name|MIPS_PHYS_TO_XKPHYS_CACHED
parameter_list|(
name|x
parameter_list|)
define|\
value|((0x2ULL<< 62) | ((unsigned long long)(MIPS_CCA_CACHED)<< 59) | (x))
end_define

begin_define
define|#
directive|define
name|MIPS_PHYS_TO_XKPHYS_UNCACHED
parameter_list|(
name|x
parameter_list|)
define|\
value|((0x2ULL<< 62) | ((unsigned long long)(MIPS_CCA_UNCACHED)<< 59) | (x))
end_define

begin_define
define|#
directive|define
name|MIPS_XKPHYS_TO_PHYS
parameter_list|(
name|x
parameter_list|)
value|((uintptr_t)(x)& MIPS_XKPHYS_PHYS_MASK)
end_define

begin_define
define|#
directive|define
name|MIPS_XKPHYS_START
value|0x8000000000000000
end_define

begin_define
define|#
directive|define
name|MIPS_XKPHYS_END
value|0xbfffffffffffffff
end_define

begin_define
define|#
directive|define
name|MIPS_XUSEG_START
value|0x0000000000000000
end_define

begin_define
define|#
directive|define
name|MIPS_XUSEG_END
value|0x0000010000000000
end_define

begin_define
define|#
directive|define
name|MIPS_XKSEG_START
value|0xc000000000000000
end_define

begin_define
define|#
directive|define
name|MIPS_XKSEG_END
value|0xc00000ff80000000
end_define

begin_define
define|#
directive|define
name|MIPS_XKSEG_COMPAT32_START
value|0xffffffff80000000
end_define

begin_define
define|#
directive|define
name|MIPS_XKSEG_COMPAT32_END
value|0xffffffffffffffff
end_define

begin_define
define|#
directive|define
name|MIPS_XKSEG_TO_COMPAT32
parameter_list|(
name|va
parameter_list|)
value|((va)& 0xffffffff)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__mips_n64
end_ifdef

begin_define
define|#
directive|define
name|MIPS_DIRECT_MAPPABLE
parameter_list|(
name|pa
parameter_list|)
value|1
end_define

begin_define
define|#
directive|define
name|MIPS_PHYS_TO_DIRECT
parameter_list|(
name|pa
parameter_list|)
value|MIPS_PHYS_TO_XKPHYS_CACHED(pa)
end_define

begin_define
define|#
directive|define
name|MIPS_PHYS_TO_DIRECT_UNCACHED
parameter_list|(
name|pa
parameter_list|)
value|MIPS_PHYS_TO_XKPHYS_UNCACHED(pa)
end_define

begin_define
define|#
directive|define
name|MIPS_DIRECT_TO_PHYS
parameter_list|(
name|va
parameter_list|)
value|MIPS_XKPHYS_TO_PHYS(va)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MIPS_DIRECT_MAPPABLE
parameter_list|(
name|pa
parameter_list|)
value|((pa)< MIPS_KSEG0_LARGEST_PHYS)
end_define

begin_define
define|#
directive|define
name|MIPS_PHYS_TO_DIRECT
parameter_list|(
name|pa
parameter_list|)
value|MIPS_PHYS_TO_KSEG0(pa)
end_define

begin_define
define|#
directive|define
name|MIPS_PHYS_TO_DIRECT_UNCACHED
parameter_list|(
name|pa
parameter_list|)
value|MIPS_PHYS_TO_KSEG1(pa)
end_define

begin_define
define|#
directive|define
name|MIPS_DIRECT_TO_PHYS
parameter_list|(
name|va
parameter_list|)
value|MIPS_KSEG0_TO_PHYS(va)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU dependent mtc0 hazard hook */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CPU_CNMIPS
argument_list|)
operator|||
name|defined
argument_list|(
name|CPU_RMI
argument_list|)
end_if

begin_define
define|#
directive|define
name|COP0_SYNC
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|CPU_NLM
argument_list|)
end_elif

begin_define
define|#
directive|define
name|COP0_SYNC
value|.word 0xc0
end_define

begin_comment
comment|/* ehb */
end_comment

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

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|CPU_MIPS74KC
argument_list|)
end_elif

begin_define
define|#
directive|define
name|COP0_SYNC
value|.word 0xc0
end_define

begin_comment
comment|/* ehb */
end_comment

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
value|ssnop; ssnop; ssnop; ssnop; .word 0xc0;
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
name|MIPS_CR_EXC_CODE
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

begin_define
define|#
directive|define
name|MIPS_CR_COP_ERR_SHIFT
value|28
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

begin_define
define|#
directive|define
name|MIPS_SR_INT_MASK
value|0x0000ff00
end_define

begin_comment
comment|/*  * R4000 status register bit definitons,  * where different from r2000/r3000.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_SR_XX
value|0x80000000
end_define

begin_define
define|#
directive|define
name|MIPS_SR_RP
value|0x08000000
end_define

begin_define
define|#
directive|define
name|MIPS_SR_FR
value|0x04000000
end_define

begin_define
define|#
directive|define
name|MIPS_SR_RE
value|0x02000000
end_define

begin_define
define|#
directive|define
name|MIPS_SR_DIAG_DL
value|0x01000000
end_define

begin_comment
comment|/* QED 52xx */
end_comment

begin_define
define|#
directive|define
name|MIPS_SR_DIAG_IL
value|0x00800000
end_define

begin_comment
comment|/* QED 52xx */
end_comment

begin_define
define|#
directive|define
name|MIPS_SR_SR
value|0x00100000
end_define

begin_define
define|#
directive|define
name|MIPS_SR_NMI
value|0x00080000
end_define

begin_comment
comment|/* MIPS32/64 */
end_comment

begin_define
define|#
directive|define
name|MIPS_SR_DIAG_CH
value|0x00040000
end_define

begin_define
define|#
directive|define
name|MIPS_SR_DIAG_CE
value|0x00020000
end_define

begin_define
define|#
directive|define
name|MIPS_SR_DIAG_PE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|MIPS_SR_EIE
value|0x00010000
end_define

begin_comment
comment|/* TX79/R5900 */
end_comment

begin_define
define|#
directive|define
name|MIPS_SR_KX
value|0x00000080
end_define

begin_define
define|#
directive|define
name|MIPS_SR_SX
value|0x00000040
end_define

begin_define
define|#
directive|define
name|MIPS_SR_UX
value|0x00000020
end_define

begin_define
define|#
directive|define
name|MIPS_SR_KSU_MASK
value|0x00000018
end_define

begin_define
define|#
directive|define
name|MIPS_SR_KSU_USER
value|0x00000010
end_define

begin_define
define|#
directive|define
name|MIPS_SR_KSU_SUPER
value|0x00000008
end_define

begin_define
define|#
directive|define
name|MIPS_SR_KSU_KERNEL
value|0x00000000
end_define

begin_define
define|#
directive|define
name|MIPS_SR_ERL
value|0x00000004
end_define

begin_define
define|#
directive|define
name|MIPS_SR_EXL
value|0x00000002
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
comment|/*  * The bits in the MIPS3 config register.  *  *	bit 0..5: R/W, Bit 6..31: R/O  */
end_comment

begin_comment
comment|/* kseg0 coherency algorithm - see MIPS3_TLB_ATTR values */
end_comment

begin_define
define|#
directive|define
name|MIPS_CONFIG_K0_MASK
value|0x00000007
end_define

begin_comment
comment|/*  * R/W Update on Store Conditional  *	0: Store Conditional uses coherency algorithm specified by TLB  *	1: Store Conditional uses cacheable coherent update on write  */
end_comment

begin_define
define|#
directive|define
name|MIPS_CONFIG_CU
value|0x00000008
end_define

begin_define
define|#
directive|define
name|MIPS_CONFIG_DB
value|0x00000010
end_define

begin_comment
comment|/* Primary D-cache line size */
end_comment

begin_define
define|#
directive|define
name|MIPS_CONFIG_IB
value|0x00000020
end_define

begin_comment
comment|/* Primary I-cache line size */
end_comment

begin_define
define|#
directive|define
name|MIPS_CONFIG_CACHE_L1_LSIZE
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
name|MIPS_CONFIG_DC_MASK
value|0x000001c0
end_define

begin_comment
comment|/* Primary D-cache size */
end_comment

begin_define
define|#
directive|define
name|MIPS_CONFIG_DC_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|MIPS_CONFIG_IC_MASK
value|0x00000e00
end_define

begin_comment
comment|/* Primary I-cache size */
end_comment

begin_define
define|#
directive|define
name|MIPS_CONFIG_IC_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|MIPS_CONFIG_C_DEFBASE
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
name|MIPS_CONFIG_CS
value|0x00001000
end_define

begin_define
define|#
directive|define
name|MIPS_CONFIG_C_4100BASE
value|0x0400
end_define

begin_comment
comment|/* base is 2^10 if CS=1 */
end_comment

begin_define
define|#
directive|define
name|MIPS_CONFIG_CACHE_SIZE
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
name|MIPS_CONFIG_SE
value|0x00001000
end_define

begin_comment
comment|/* Block ordering: 0: sequential, 1: sub-block */
end_comment

begin_define
define|#
directive|define
name|MIPS_CONFIG_EB
value|0x00002000
end_define

begin_comment
comment|/* ECC mode - 0: ECC mode, 1: parity mode */
end_comment

begin_define
define|#
directive|define
name|MIPS_CONFIG_EM
value|0x00004000
end_define

begin_comment
comment|/* BigEndianMem - 0: kernel and memory are little endian, 1: big endian */
end_comment

begin_define
define|#
directive|define
name|MIPS_CONFIG_BE
value|0x00008000
end_define

begin_comment
comment|/* Dirty Shared coherency state - 0: enabled, 1: disabled */
end_comment

begin_define
define|#
directive|define
name|MIPS_CONFIG_SM
value|0x00010000
end_define

begin_comment
comment|/* Secondary Cache - 0: present, 1: not present */
end_comment

begin_define
define|#
directive|define
name|MIPS_CONFIG_SC
value|0x00020000
end_define

begin_comment
comment|/* System Port width - 0: 64-bit, 1: 32-bit (QED RM523x), 2,3: reserved */
end_comment

begin_define
define|#
directive|define
name|MIPS_CONFIG_EW_MASK
value|0x000c0000
end_define

begin_define
define|#
directive|define
name|MIPS_CONFIG_EW_SHIFT
value|18
end_define

begin_comment
comment|/* Secondary Cache port width - 0: 128-bit data path to S-cache, 1: reserved */
end_comment

begin_define
define|#
directive|define
name|MIPS_CONFIG_SW
value|0x00100000
end_define

begin_comment
comment|/* Split Secondary Cache Mode - 0: I/D mixed, 1: I/D separated by SCAddr(17) */
end_comment

begin_define
define|#
directive|define
name|MIPS_CONFIG_SS
value|0x00200000
end_define

begin_comment
comment|/* Secondary Cache line size */
end_comment

begin_define
define|#
directive|define
name|MIPS_CONFIG_SB_MASK
value|0x00c00000
end_define

begin_define
define|#
directive|define
name|MIPS_CONFIG_SB_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|MIPS_CONFIG_CACHE_L2_LSIZE
parameter_list|(
name|config
parameter_list|)
define|\
value|(0x10<< (((config)& MIPS_CONFIG_SB_MASK)>> MIPS_CONFIG_SB_SHIFT))
end_define

begin_comment
comment|/* Write back data rate */
end_comment

begin_define
define|#
directive|define
name|MIPS_CONFIG_EP_MASK
value|0x0f000000
end_define

begin_define
define|#
directive|define
name|MIPS_CONFIG_EP_SHIFT
value|24
end_define

begin_comment
comment|/* System clock ratio - this value is CPU dependent */
end_comment

begin_define
define|#
directive|define
name|MIPS_CONFIG_EC_MASK
value|0x70000000
end_define

begin_define
define|#
directive|define
name|MIPS_CONFIG_EC_SHIFT
value|28
end_define

begin_comment
comment|/* Master-Checker Mode - 1: enabled */
end_comment

begin_define
define|#
directive|define
name|MIPS_CONFIG_CM
value|0x80000000
end_define

begin_comment
comment|/*  * The bits in the MIPS4 config register.  */
end_comment

begin_comment
comment|/*  * Location of exception vectors.  *  * Common vectors:  reset and UTLB miss.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_RESET_EXC_VEC
value|((intptr_t)(int32_t)0xBFC00000)
end_define

begin_define
define|#
directive|define
name|MIPS_UTLB_MISS_EXC_VEC
value|((intptr_t)(int32_t)0x80000000)
end_define

begin_comment
comment|/*  * MIPS-III exception vectors  */
end_comment

begin_define
define|#
directive|define
name|MIPS_XTLB_MISS_EXC_VEC
value|((intptr_t)(int32_t)0x80000080)
end_define

begin_define
define|#
directive|define
name|MIPS_CACHE_ERR_EXC_VEC
value|((intptr_t)(int32_t)0x80000100)
end_define

begin_define
define|#
directive|define
name|MIPS_GEN_EXC_VEC
value|((intptr_t)(int32_t)0x80000180)
end_define

begin_comment
comment|/*  * MIPS32/MIPS64 (and some MIPS3) dedicated interrupt vector.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_INTR_EXC_VEC
value|0x80000200
end_define

begin_comment
comment|/*  * Coprocessor 0 registers:  *  *				v--- width for mips I,III,32,64  *				     (3=32bit, 6=64bit, i=impl dep)  *  0	MIPS_COP_0_TLB_INDEX	3333 TLB Index.  *  1	MIPS_COP_0_TLB_RANDOM	3333 TLB Random.  *  2	MIPS_COP_0_TLB_LO0	.636 r4k TLB entry low.  *  3	MIPS_COP_0_TLB_LO1	.636 r4k TLB entry low, extended.  *  4	MIPS_COP_0_TLB_CONTEXT	3636 TLB Context.  *  5	MIPS_COP_0_TLB_PG_MASK	.333 TLB Page Mask register.  *  6	MIPS_COP_0_TLB_WIRED	.333 Wired TLB number.  *  7	MIPS_COP_0_INFO		..33 Info registers  *  8	MIPS_COP_0_BAD_VADDR	3636 Bad virtual address.  *  9	MIPS_COP_0_COUNT	.333 Count register.  * 10	MIPS_COP_0_TLB_HI	3636 TLB entry high.  * 11	MIPS_COP_0_COMPARE	.333 Compare (against Count).  * 12	MIPS_COP_0_STATUS	3333 Status register.  * 13	MIPS_COP_0_CAUSE	3333 Exception cause register.  * 14	MIPS_COP_0_EXC_PC	3636 Exception PC.  * 15	MIPS_COP_0_PRID		3333 Processor revision identifier.  * 16	MIPS_COP_0_CONFIG	3333 Configuration register.  * 16/1	MIPS_COP_0_CONFIG1	..33 Configuration register 1.  * 16/2	MIPS_COP_0_CONFIG2	..33 Configuration register 2.  * 16/3	MIPS_COP_0_CONFIG3	..33 Configuration register 3.  * 16/4 MIPS_COP_0_CONFIG4	..33 Configuration register 4.  * 17	MIPS_COP_0_LLADDR	.336 Load Linked Address.  * 18	MIPS_COP_0_WATCH_LO	.336 WatchLo register.  * 19	MIPS_COP_0_WATCH_HI	.333 WatchHi register.  * 20	MIPS_COP_0_TLB_XCONTEXT .6.6 TLB XContext register.  * 23	MIPS_COP_0_DEBUG	.... Debug JTAG register.  * 24	MIPS_COP_0_DEPC		.... DEPC JTAG register.  * 25	MIPS_COP_0_PERFCNT	..36 Performance Counter register.  * 26	MIPS_COP_0_ECC		.3ii ECC / Error Control register.  * 27	MIPS_COP_0_CACHE_ERR	.3ii Cache Error register.  * 28/0	MIPS_COP_0_TAG_LO	.3ii Cache TagLo register (instr).  * 28/1	MIPS_COP_0_DATA_LO	..ii Cache DataLo register (instr).  * 28/2	MIPS_COP_0_TAG_LO	..ii Cache TagLo register (data).  * 28/3	MIPS_COP_0_DATA_LO	..ii Cache DataLo register (data).  * 29/0	MIPS_COP_0_TAG_HI	.3ii Cache TagHi register (instr).  * 29/1	MIPS_COP_0_DATA_HI	..ii Cache DataHi register (instr).  * 29/2	MIPS_COP_0_TAG_HI	..ii Cache TagHi register (data).  * 29/3	MIPS_COP_0_DATA_HI	..ii Cache DataHi register (data).  * 30	MIPS_COP_0_ERROR_PC	.636 Error EPC register.  * 31	MIPS_COP_0_DESAVE	.... DESAVE JTAG register.  */
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
name|MIPS_COP_0_INFO
value|_(7)
end_define

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

begin_define
define|#
directive|define
name|MIPS_CONFIG2_SA_SHIFT
value|0
end_define

begin_comment
comment|/* Secondary cache associativity */
end_comment

begin_define
define|#
directive|define
name|MIPS_CONFIG2_SA_MASK
value|0xf
end_define

begin_define
define|#
directive|define
name|MIPS_CONFIG2_SL_SHIFT
value|4
end_define

begin_comment
comment|/* Secondary cache line size */
end_comment

begin_define
define|#
directive|define
name|MIPS_CONFIG2_SL_MASK
value|0xf
end_define

begin_define
define|#
directive|define
name|MIPS_CONFIG2_SS_SHIFT
value|8
end_define

begin_comment
comment|/* Secondary cache sets per way */
end_comment

begin_define
define|#
directive|define
name|MIPS_CONFIG2_SS_MASK
value|0xf
end_define

begin_define
define|#
directive|define
name|MIPS_CONFIG4_MMUSIZEEXT
value|0x000000FF
end_define

begin_comment
comment|/* bits 7.. 0 MMU Size Extension */
end_comment

begin_define
define|#
directive|define
name|MIPS_CONFIG4_MMUEXTDEF
value|0x0000C000
end_define

begin_comment
comment|/* bits 15.14 MMU Extension Definition */
end_comment

begin_define
define|#
directive|define
name|MIPS_CONFIG4_MMUEXTDEF_MMUSIZEEXT
value|0x00004000
end_define

begin_comment
comment|/* This values denotes CONFIG4 bits  */
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
name|MIPS_BREAK_DDB_VAL
value|516
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

begin_define
define|#
directive|define
name|MIPS_BREAK_DDB
value|(MIPS_BREAK_INSTR | \ 				(MIPS_BREAK_DDB_VAL<< MIPS_BREAK_VAL_SHIFT))
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
name|MIPS_MAX_PCACHE_SIZE
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
name|MIPS_FPC_MBZ_BITS
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MIPS_CPUREGS_H_ */
end_comment

end_unit

