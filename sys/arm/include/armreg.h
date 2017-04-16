begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: armreg.h,v 1.37 2007/01/06 00:50:54 christos Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1998, 2001 Ben Harris  * Copyright (c) 1994-1996 Mark Brinicombe.  * Copyright (c) 1994 Brini.  * All rights reserved.  *  * This code is derived from software written for Brini by Mark Brinicombe  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Brini.  * 4. The name of the company nor the name of the author may be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY BRINI ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL BRINI OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MACHINE_ARMREG_H
end_ifndef

begin_define
define|#
directive|define
name|MACHINE_ARMREG_H
end_define

begin_define
define|#
directive|define
name|INSN_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|INSN_COND_MASK
value|0xf0000000
end_define

begin_comment
comment|/* Condition mask */
end_comment

begin_define
define|#
directive|define
name|PSR_MODE
value|0x0000001f
end_define

begin_comment
comment|/* mode mask */
end_comment

begin_define
define|#
directive|define
name|PSR_USR32_MODE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|PSR_FIQ32_MODE
value|0x00000011
end_define

begin_define
define|#
directive|define
name|PSR_IRQ32_MODE
value|0x00000012
end_define

begin_define
define|#
directive|define
name|PSR_SVC32_MODE
value|0x00000013
end_define

begin_define
define|#
directive|define
name|PSR_MON32_MODE
value|0x00000016
end_define

begin_define
define|#
directive|define
name|PSR_ABT32_MODE
value|0x00000017
end_define

begin_define
define|#
directive|define
name|PSR_HYP32_MODE
value|0x0000001a
end_define

begin_define
define|#
directive|define
name|PSR_UND32_MODE
value|0x0000001b
end_define

begin_define
define|#
directive|define
name|PSR_SYS32_MODE
value|0x0000001f
end_define

begin_define
define|#
directive|define
name|PSR_32_MODE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|PSR_T
value|0x00000020
end_define

begin_comment
comment|/* Instruction set bit */
end_comment

begin_define
define|#
directive|define
name|PSR_F
value|0x00000040
end_define

begin_comment
comment|/* FIQ disable bit */
end_comment

begin_define
define|#
directive|define
name|PSR_I
value|0x00000080
end_define

begin_comment
comment|/* IRQ disable bit */
end_comment

begin_define
define|#
directive|define
name|PSR_A
value|0x00000100
end_define

begin_comment
comment|/* Imprecise abort bit */
end_comment

begin_define
define|#
directive|define
name|PSR_E
value|0x00000200
end_define

begin_comment
comment|/* Data endianess bit */
end_comment

begin_define
define|#
directive|define
name|PSR_GE
value|0x000f0000
end_define

begin_comment
comment|/* Greater than or equal to bits */
end_comment

begin_define
define|#
directive|define
name|PSR_J
value|0x01000000
end_define

begin_comment
comment|/* Java bit */
end_comment

begin_define
define|#
directive|define
name|PSR_Q
value|0x08000000
end_define

begin_comment
comment|/* Sticky overflow bit */
end_comment

begin_define
define|#
directive|define
name|PSR_V
value|0x10000000
end_define

begin_comment
comment|/* Overflow bit */
end_comment

begin_define
define|#
directive|define
name|PSR_C
value|0x20000000
end_define

begin_comment
comment|/* Carry bit */
end_comment

begin_define
define|#
directive|define
name|PSR_Z
value|0x40000000
end_define

begin_comment
comment|/* Zero bit */
end_comment

begin_define
define|#
directive|define
name|PSR_N
value|0x80000000
end_define

begin_comment
comment|/* Negative bit */
end_comment

begin_define
define|#
directive|define
name|PSR_FLAGS
value|0xf0000000
end_define

begin_comment
comment|/* Flags mask. */
end_comment

begin_comment
comment|/* The high-order byte is always the implementor */
end_comment

begin_define
define|#
directive|define
name|CPU_ID_IMPLEMENTOR_MASK
value|0xff000000
end_define

begin_define
define|#
directive|define
name|CPU_ID_ARM_LTD
value|0x41000000
end_define

begin_comment
comment|/* 'A' */
end_comment

begin_define
define|#
directive|define
name|CPU_ID_DEC
value|0x44000000
end_define

begin_comment
comment|/* 'D' */
end_comment

begin_define
define|#
directive|define
name|CPU_ID_MOTOROLA
value|0x4D000000
end_define

begin_comment
comment|/* 'M' */
end_comment

begin_define
define|#
directive|define
name|CPU_ID_QUALCOM
value|0x51000000
end_define

begin_comment
comment|/* 'Q' */
end_comment

begin_define
define|#
directive|define
name|CPU_ID_TI
value|0x54000000
end_define

begin_comment
comment|/* 'T' */
end_comment

begin_define
define|#
directive|define
name|CPU_ID_MARVELL
value|0x56000000
end_define

begin_comment
comment|/* 'V' */
end_comment

begin_define
define|#
directive|define
name|CPU_ID_INTEL
value|0x69000000
end_define

begin_comment
comment|/* 'i' */
end_comment

begin_define
define|#
directive|define
name|CPU_ID_FARADAY
value|0x66000000
end_define

begin_comment
comment|/* 'f' */
end_comment

begin_define
define|#
directive|define
name|CPU_ID_VARIANT_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|CPU_ID_VARIANT_MASK
value|0x00f00000
end_define

begin_comment
comment|/* How to decide what format the CPUID is in. */
end_comment

begin_define
define|#
directive|define
name|CPU_ID_ISOLD
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x0000f000) == 0x00000000)
end_define

begin_define
define|#
directive|define
name|CPU_ID_IS7
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x0000f000) == 0x00007000)
end_define

begin_define
define|#
directive|define
name|CPU_ID_ISNEW
parameter_list|(
name|x
parameter_list|)
value|(!CPU_ID_ISOLD(x)&& !CPU_ID_IS7(x))
end_define

begin_comment
comment|/* On recent ARMs this byte holds the architecture and variant (sub-model) */
end_comment

begin_define
define|#
directive|define
name|CPU_ID_ARCH_MASK
value|0x000f0000
end_define

begin_define
define|#
directive|define
name|CPU_ID_ARCH_V3
value|0x00000000
end_define

begin_define
define|#
directive|define
name|CPU_ID_ARCH_V4
value|0x00010000
end_define

begin_define
define|#
directive|define
name|CPU_ID_ARCH_V4T
value|0x00020000
end_define

begin_define
define|#
directive|define
name|CPU_ID_ARCH_V5
value|0x00030000
end_define

begin_define
define|#
directive|define
name|CPU_ID_ARCH_V5T
value|0x00040000
end_define

begin_define
define|#
directive|define
name|CPU_ID_ARCH_V5TE
value|0x00050000
end_define

begin_define
define|#
directive|define
name|CPU_ID_ARCH_V5TEJ
value|0x00060000
end_define

begin_define
define|#
directive|define
name|CPU_ID_ARCH_V6
value|0x00070000
end_define

begin_define
define|#
directive|define
name|CPU_ID_CPUID_SCHEME
value|0x000f0000
end_define

begin_comment
comment|/* Next three nybbles are part number */
end_comment

begin_define
define|#
directive|define
name|CPU_ID_PARTNO_MASK
value|0x0000fff0
end_define

begin_comment
comment|/* Intel XScale has sub fields in part number */
end_comment

begin_define
define|#
directive|define
name|CPU_ID_XSCALE_COREGEN_MASK
value|0x0000e000
end_define

begin_comment
comment|/* core generation */
end_comment

begin_define
define|#
directive|define
name|CPU_ID_XSCALE_COREREV_MASK
value|0x00001c00
end_define

begin_comment
comment|/* core revision */
end_comment

begin_define
define|#
directive|define
name|CPU_ID_XSCALE_PRODUCT_MASK
value|0x000003f0
end_define

begin_comment
comment|/* product number */
end_comment

begin_comment
comment|/* And finally, the revision number. */
end_comment

begin_define
define|#
directive|define
name|CPU_ID_REVISION_MASK
value|0x0000000f
end_define

begin_comment
comment|/* Individual CPUs are probably best IDed by everything but the revision. */
end_comment

begin_define
define|#
directive|define
name|CPU_ID_CPU_MASK
value|0xfffffff0
end_define

begin_comment
comment|/* ARM9 and later CPUs */
end_comment

begin_define
define|#
directive|define
name|CPU_ID_ARM920T
value|0x41129200
end_define

begin_define
define|#
directive|define
name|CPU_ID_ARM920T_ALT
value|0x41009200
end_define

begin_define
define|#
directive|define
name|CPU_ID_ARM922T
value|0x41029220
end_define

begin_define
define|#
directive|define
name|CPU_ID_ARM926EJS
value|0x41069260
end_define

begin_define
define|#
directive|define
name|CPU_ID_ARM940T
value|0x41029400
end_define

begin_comment
comment|/* XXX no MMU */
end_comment

begin_define
define|#
directive|define
name|CPU_ID_ARM946ES
value|0x41049460
end_define

begin_comment
comment|/* XXX no MMU */
end_comment

begin_define
define|#
directive|define
name|CPU_ID_ARM966ES
value|0x41049660
end_define

begin_comment
comment|/* XXX no MMU */
end_comment

begin_define
define|#
directive|define
name|CPU_ID_ARM966ESR1
value|0x41059660
end_define

begin_comment
comment|/* XXX no MMU */
end_comment

begin_define
define|#
directive|define
name|CPU_ID_ARM1020E
value|0x4115a200
end_define

begin_comment
comment|/* (AKA arm10 rev 1) */
end_comment

begin_define
define|#
directive|define
name|CPU_ID_ARM1022ES
value|0x4105a220
end_define

begin_define
define|#
directive|define
name|CPU_ID_ARM1026EJS
value|0x4106a260
end_define

begin_define
define|#
directive|define
name|CPU_ID_ARM1136JS
value|0x4107b360
end_define

begin_define
define|#
directive|define
name|CPU_ID_ARM1136JSR1
value|0x4117b360
end_define

begin_define
define|#
directive|define
name|CPU_ID_ARM1176JZS
value|0x410fb760
end_define

begin_comment
comment|/* CPUs that follow the CPUID scheme */
end_comment

begin_define
define|#
directive|define
name|CPU_ID_SCHEME_MASK
define|\
value|(CPU_ID_IMPLEMENTOR_MASK | CPU_ID_ARCH_MASK | CPU_ID_PARTNO_MASK)
end_define

begin_define
define|#
directive|define
name|CPU_ID_CORTEXA5
value|(CPU_ID_ARM_LTD | CPU_ID_CPUID_SCHEME | 0xc050)
end_define

begin_define
define|#
directive|define
name|CPU_ID_CORTEXA7
value|(CPU_ID_ARM_LTD | CPU_ID_CPUID_SCHEME | 0xc070)
end_define

begin_define
define|#
directive|define
name|CPU_ID_CORTEXA8
value|(CPU_ID_ARM_LTD | CPU_ID_CPUID_SCHEME | 0xc080)
end_define

begin_define
define|#
directive|define
name|CPU_ID_CORTEXA8R1
value|(CPU_ID_CORTEXA8 | (1<< CPU_ID_VARIANT_SHIFT))
end_define

begin_define
define|#
directive|define
name|CPU_ID_CORTEXA8R2
value|(CPU_ID_CORTEXA8 | (2<< CPU_ID_VARIANT_SHIFT))
end_define

begin_define
define|#
directive|define
name|CPU_ID_CORTEXA8R3
value|(CPU_ID_CORTEXA8 | (3<< CPU_ID_VARIANT_SHIFT))
end_define

begin_define
define|#
directive|define
name|CPU_ID_CORTEXA9
value|(CPU_ID_ARM_LTD | CPU_ID_CPUID_SCHEME | 0xc090)
end_define

begin_define
define|#
directive|define
name|CPU_ID_CORTEXA9R1
value|(CPU_ID_CORTEXA9 | (1<< CPU_ID_VARIANT_SHIFT))
end_define

begin_define
define|#
directive|define
name|CPU_ID_CORTEXA9R2
value|(CPU_ID_CORTEXA9 | (2<< CPU_ID_VARIANT_SHIFT))
end_define

begin_define
define|#
directive|define
name|CPU_ID_CORTEXA9R3
value|(CPU_ID_CORTEXA9 | (3<< CPU_ID_VARIANT_SHIFT))
end_define

begin_define
define|#
directive|define
name|CPU_ID_CORTEXA9R4
value|(CPU_ID_CORTEXA9 | (4<< CPU_ID_VARIANT_SHIFT))
end_define

begin_comment
comment|/* XXX: Cortx-A12 is the old name for this part, it has been renamed the A17 */
end_comment

begin_define
define|#
directive|define
name|CPU_ID_CORTEXA12
value|(CPU_ID_ARM_LTD | CPU_ID_CPUID_SCHEME | 0xc0d0)
end_define

begin_define
define|#
directive|define
name|CPU_ID_CORTEXA12R0
value|(CPU_ID_CORTEXA12 | (0<< CPU_ID_VARIANT_SHIFT))
end_define

begin_define
define|#
directive|define
name|CPU_ID_CORTEXA15
value|(CPU_ID_ARM_LTD | CPU_ID_CPUID_SCHEME | 0xc0f0)
end_define

begin_define
define|#
directive|define
name|CPU_ID_CORTEXA15R0
value|(CPU_ID_CORTEXA15 | (0<< CPU_ID_VARIANT_SHIFT))
end_define

begin_define
define|#
directive|define
name|CPU_ID_CORTEXA15R1
value|(CPU_ID_CORTEXA15 | (1<< CPU_ID_VARIANT_SHIFT))
end_define

begin_define
define|#
directive|define
name|CPU_ID_CORTEXA15R2
value|(CPU_ID_CORTEXA15 | (2<< CPU_ID_VARIANT_SHIFT))
end_define

begin_define
define|#
directive|define
name|CPU_ID_CORTEXA15R3
value|(CPU_ID_CORTEXA15 | (3<< CPU_ID_VARIANT_SHIFT))
end_define

begin_define
define|#
directive|define
name|CPU_ID_CORTEXA53
value|(CPU_ID_ARM_LTD | CPU_ID_CPUID_SCHEME | 0xd030)
end_define

begin_define
define|#
directive|define
name|CPU_ID_CORTEXA57
value|(CPU_ID_ARM_LTD | CPU_ID_CPUID_SCHEME | 0xd070)
end_define

begin_define
define|#
directive|define
name|CPU_ID_CORTEXA72
value|(CPU_ID_ARM_LTD | CPU_ID_CPUID_SCHEME | 0xd080)
end_define

begin_define
define|#
directive|define
name|CPU_ID_KRAIT300
value|(CPU_ID_QUALCOM | CPU_ID_CPUID_SCHEME | 0x06f0)
end_define

begin_comment
comment|/* Snapdragon S4 Pro/APQ8064 */
end_comment

begin_define
define|#
directive|define
name|CPU_ID_KRAIT300R0
value|(CPU_ID_KRAIT300 | (0<< CPU_ID_VARIANT_SHIFT))
end_define

begin_define
define|#
directive|define
name|CPU_ID_KRAIT300R1
value|(CPU_ID_KRAIT300 | (1<< CPU_ID_VARIANT_SHIFT))
end_define

begin_define
define|#
directive|define
name|CPU_ID_TI925T
value|0x54029250
end_define

begin_define
define|#
directive|define
name|CPU_ID_MV88FR131
value|0x56251310
end_define

begin_comment
comment|/* Marvell Feroceon 88FR131 Core */
end_comment

begin_define
define|#
directive|define
name|CPU_ID_MV88FR331
value|0x56153310
end_define

begin_comment
comment|/* Marvell Feroceon 88FR331 Core */
end_comment

begin_define
define|#
directive|define
name|CPU_ID_MV88FR571_VD
value|0x56155710
end_define

begin_comment
comment|/* Marvell Feroceon 88FR571-VD Core (ID from datasheet) */
end_comment

begin_comment
comment|/*  * LokiPlus core has also ID set to 0x41159260 and this define cause execution of unsupported  * L2-cache instructions so need to disable it. 0x41159260 is a generic ARM926E-S ID.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SOC_MV_LOKIPLUS
end_ifdef

begin_define
define|#
directive|define
name|CPU_ID_MV88FR571_41
value|0x00000000
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CPU_ID_MV88FR571_41
value|0x41159260
end_define

begin_comment
comment|/* Marvell Feroceon 88FR571-VD Core (actual ID from CPU reg) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CPU_ID_MV88SV581X_V7
value|0x561F5810
end_define

begin_comment
comment|/* Marvell Sheeva 88SV581x v7 Core */
end_comment

begin_define
define|#
directive|define
name|CPU_ID_MV88SV584X_V7
value|0x562F5840
end_define

begin_comment
comment|/* Marvell Sheeva 88SV584x v7 Core */
end_comment

begin_comment
comment|/* Marvell's CPUIDs with ARM ID in implementor field */
end_comment

begin_define
define|#
directive|define
name|CPU_ID_ARM_88SV581X_V7
value|0x413FC080
end_define

begin_comment
comment|/* Marvell Sheeva 88SV581x v7 Core */
end_comment

begin_define
define|#
directive|define
name|CPU_ID_FA526
value|0x66015260
end_define

begin_define
define|#
directive|define
name|CPU_ID_FA626TE
value|0x66056260
end_define

begin_define
define|#
directive|define
name|CPU_ID_80200
value|0x69052000
end_define

begin_define
define|#
directive|define
name|CPU_ID_PXA250
value|0x69052100
end_define

begin_comment
comment|/* sans core revision */
end_comment

begin_define
define|#
directive|define
name|CPU_ID_PXA210
value|0x69052120
end_define

begin_define
define|#
directive|define
name|CPU_ID_PXA250A
value|0x69052100
end_define

begin_comment
comment|/* 1st version Core */
end_comment

begin_define
define|#
directive|define
name|CPU_ID_PXA210A
value|0x69052120
end_define

begin_comment
comment|/* 1st version Core */
end_comment

begin_define
define|#
directive|define
name|CPU_ID_PXA250B
value|0x69052900
end_define

begin_comment
comment|/* 3rd version Core */
end_comment

begin_define
define|#
directive|define
name|CPU_ID_PXA210B
value|0x69052920
end_define

begin_comment
comment|/* 3rd version Core */
end_comment

begin_define
define|#
directive|define
name|CPU_ID_PXA250C
value|0x69052d00
end_define

begin_comment
comment|/* 4th version Core */
end_comment

begin_define
define|#
directive|define
name|CPU_ID_PXA210C
value|0x69052d20
end_define

begin_comment
comment|/* 4th version Core */
end_comment

begin_define
define|#
directive|define
name|CPU_ID_PXA27X
value|0x69054110
end_define

begin_define
define|#
directive|define
name|CPU_ID_80321_400
value|0x69052420
end_define

begin_define
define|#
directive|define
name|CPU_ID_80321_600
value|0x69052430
end_define

begin_define
define|#
directive|define
name|CPU_ID_80321_400_B0
value|0x69052c20
end_define

begin_define
define|#
directive|define
name|CPU_ID_80321_600_B0
value|0x69052c30
end_define

begin_define
define|#
directive|define
name|CPU_ID_80219_400
value|0x69052e20
end_define

begin_comment
comment|/* A0 stepping/revision. */
end_comment

begin_define
define|#
directive|define
name|CPU_ID_80219_600
value|0x69052e30
end_define

begin_comment
comment|/* A0 stepping/revision. */
end_comment

begin_define
define|#
directive|define
name|CPU_ID_81342
value|0x69056810
end_define

begin_define
define|#
directive|define
name|CPU_ID_IXP425
value|0x690541c0
end_define

begin_define
define|#
directive|define
name|CPU_ID_IXP425_533
value|0x690541c0
end_define

begin_define
define|#
directive|define
name|CPU_ID_IXP425_400
value|0x690541d0
end_define

begin_define
define|#
directive|define
name|CPU_ID_IXP425_266
value|0x690541f0
end_define

begin_define
define|#
directive|define
name|CPU_ID_IXP435
value|0x69054040
end_define

begin_define
define|#
directive|define
name|CPU_ID_IXP465
value|0x69054200
end_define

begin_comment
comment|/* CPUID registers */
end_comment

begin_define
define|#
directive|define
name|ARM_PFR0_ARM_ISA_MASK
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|ARM_PFR0_THUMB_MASK
value|0x000000f0
end_define

begin_define
define|#
directive|define
name|ARM_PFR0_THUMB
value|0x10
end_define

begin_define
define|#
directive|define
name|ARM_PFR0_THUMB2
value|0x30
end_define

begin_define
define|#
directive|define
name|ARM_PFR0_JAZELLE_MASK
value|0x00000f00
end_define

begin_define
define|#
directive|define
name|ARM_PFR0_THUMBEE_MASK
value|0x0000f000
end_define

begin_define
define|#
directive|define
name|ARM_PFR1_ARMV4_MASK
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|ARM_PFR1_SEC_EXT_MASK
value|0x000000f0
end_define

begin_define
define|#
directive|define
name|ARM_PFR1_MICROCTRL_MASK
value|0x00000f00
end_define

begin_comment
comment|/*  * Post-ARM3 CP15 registers:  *  *	1	Control register  *  *	2	Translation Table Base  *  *	3	Domain Access Control  *  *	4	Reserved  *  *	5	Fault Status  *  *	6	Fault Address  *  *	7	Cache/write-buffer Control  *  *	8	TLB Control  *  *	9	Cache Lockdown  *  *	10	TLB Lockdown  *  *	11	Reserved  *  *	12	Reserved  *  *	13	Process ID (for FCSE)  *  *	14	Reserved  *  *	15	Implementation Dependent  */
end_comment

begin_comment
comment|/* Some of the definitions below need cleaning up for V3/V4 architectures */
end_comment

begin_comment
comment|/* CPU control register (CP15 register 1) */
end_comment

begin_define
define|#
directive|define
name|CPU_CONTROL_MMU_ENABLE
value|0x00000001
end_define

begin_comment
comment|/* M: MMU/Protection unit enable */
end_comment

begin_define
define|#
directive|define
name|CPU_CONTROL_AFLT_ENABLE
value|0x00000002
end_define

begin_comment
comment|/* A: Alignment fault enable */
end_comment

begin_define
define|#
directive|define
name|CPU_CONTROL_DC_ENABLE
value|0x00000004
end_define

begin_comment
comment|/* C: IDC/DC enable */
end_comment

begin_define
define|#
directive|define
name|CPU_CONTROL_WBUF_ENABLE
value|0x00000008
end_define

begin_comment
comment|/* W: Write buffer enable */
end_comment

begin_define
define|#
directive|define
name|CPU_CONTROL_32BP_ENABLE
value|0x00000010
end_define

begin_comment
comment|/* P: 32-bit exception handlers */
end_comment

begin_define
define|#
directive|define
name|CPU_CONTROL_32BD_ENABLE
value|0x00000020
end_define

begin_comment
comment|/* D: 32-bit addressing */
end_comment

begin_define
define|#
directive|define
name|CPU_CONTROL_LABT_ENABLE
value|0x00000040
end_define

begin_comment
comment|/* L: Late abort enable */
end_comment

begin_define
define|#
directive|define
name|CPU_CONTROL_BEND_ENABLE
value|0x00000080
end_define

begin_comment
comment|/* B: Big-endian mode */
end_comment

begin_define
define|#
directive|define
name|CPU_CONTROL_SYST_ENABLE
value|0x00000100
end_define

begin_comment
comment|/* S: System protection bit */
end_comment

begin_define
define|#
directive|define
name|CPU_CONTROL_ROM_ENABLE
value|0x00000200
end_define

begin_comment
comment|/* R: ROM protection bit */
end_comment

begin_define
define|#
directive|define
name|CPU_CONTROL_CPCLK
value|0x00000400
end_define

begin_comment
comment|/* F: Implementation defined */
end_comment

begin_define
define|#
directive|define
name|CPU_CONTROL_SW_ENABLE
value|0x00000400
end_define

begin_comment
comment|/* SW: SWP instruction enable */
end_comment

begin_define
define|#
directive|define
name|CPU_CONTROL_BPRD_ENABLE
value|0x00000800
end_define

begin_comment
comment|/* Z: Branch prediction enable */
end_comment

begin_define
define|#
directive|define
name|CPU_CONTROL_IC_ENABLE
value|0x00001000
end_define

begin_comment
comment|/* I: IC enable */
end_comment

begin_define
define|#
directive|define
name|CPU_CONTROL_VECRELOC
value|0x00002000
end_define

begin_comment
comment|/* V: Vector relocation */
end_comment

begin_define
define|#
directive|define
name|CPU_CONTROL_ROUNDROBIN
value|0x00004000
end_define

begin_comment
comment|/* RR: Predictable replacement */
end_comment

begin_define
define|#
directive|define
name|CPU_CONTROL_V4COMPAT
value|0x00008000
end_define

begin_comment
comment|/* L4: ARMv4 compat LDR R15 etc */
end_comment

begin_define
define|#
directive|define
name|CPU_CONTROL_HAF_ENABLE
value|0x00020000
end_define

begin_comment
comment|/* HA: Hardware Access Flag Enable */
end_comment

begin_define
define|#
directive|define
name|CPU_CONTROL_FI_ENABLE
value|0x00200000
end_define

begin_comment
comment|/* FI: Low interrupt latency */
end_comment

begin_define
define|#
directive|define
name|CPU_CONTROL_UNAL_ENABLE
value|0x00400000
end_define

begin_comment
comment|/* U: unaligned data access */
end_comment

begin_define
define|#
directive|define
name|CPU_CONTROL_V6_EXTPAGE
value|0x00800000
end_define

begin_comment
comment|/* XP: ARMv6 extended page tables */
end_comment

begin_define
define|#
directive|define
name|CPU_CONTROL_V_ENABLE
value|0x01000000
end_define

begin_comment
comment|/* VE: Interrupt vectors enable */
end_comment

begin_define
define|#
directive|define
name|CPU_CONTROL_EX_BEND
value|0x02000000
end_define

begin_comment
comment|/* EE: exception endianness */
end_comment

begin_define
define|#
directive|define
name|CPU_CONTROL_L2_ENABLE
value|0x04000000
end_define

begin_comment
comment|/* L2 Cache enabled */
end_comment

begin_define
define|#
directive|define
name|CPU_CONTROL_NMFI
value|0x08000000
end_define

begin_comment
comment|/* NMFI: Non maskable FIQ */
end_comment

begin_define
define|#
directive|define
name|CPU_CONTROL_TR_ENABLE
value|0x10000000
end_define

begin_comment
comment|/* TRE: TEX Remap*/
end_comment

begin_define
define|#
directive|define
name|CPU_CONTROL_AF_ENABLE
value|0x20000000
end_define

begin_comment
comment|/* AFE: Access Flag enable */
end_comment

begin_define
define|#
directive|define
name|CPU_CONTROL_TE_ENABLE
value|0x40000000
end_define

begin_comment
comment|/* TE: Thumb Exception enable */
end_comment

begin_define
define|#
directive|define
name|CPU_CONTROL_IDC_ENABLE
value|CPU_CONTROL_DC_ENABLE
end_define

begin_comment
comment|/* ARM11x6 Auxiliary Control Register (CP15 register 1, opcode2 1) */
end_comment

begin_define
define|#
directive|define
name|ARM11X6_AUXCTL_RS
value|0x00000001
end_define

begin_comment
comment|/* return stack */
end_comment

begin_define
define|#
directive|define
name|ARM11X6_AUXCTL_DB
value|0x00000002
end_define

begin_comment
comment|/* dynamic branch prediction */
end_comment

begin_define
define|#
directive|define
name|ARM11X6_AUXCTL_SB
value|0x00000004
end_define

begin_comment
comment|/* static branch prediction */
end_comment

begin_define
define|#
directive|define
name|ARM11X6_AUXCTL_TR
value|0x00000008
end_define

begin_comment
comment|/* MicroTLB replacement strat. */
end_comment

begin_define
define|#
directive|define
name|ARM11X6_AUXCTL_EX
value|0x00000010
end_define

begin_comment
comment|/* exclusive L1/L2 cache */
end_comment

begin_define
define|#
directive|define
name|ARM11X6_AUXCTL_RA
value|0x00000020
end_define

begin_comment
comment|/* clean entire cache disable */
end_comment

begin_define
define|#
directive|define
name|ARM11X6_AUXCTL_RV
value|0x00000040
end_define

begin_comment
comment|/* block transfer cache disable */
end_comment

begin_define
define|#
directive|define
name|ARM11X6_AUXCTL_CZ
value|0x00000080
end_define

begin_comment
comment|/* restrict cache size */
end_comment

begin_comment
comment|/* ARM1136 Auxiliary Control Register (CP15 register 1, opcode2 1) */
end_comment

begin_define
define|#
directive|define
name|ARM1136_AUXCTL_PFI
value|0x80000000
end_define

begin_comment
comment|/* PFI: partial FI mode. */
end_comment

begin_comment
comment|/* This is an undocumented flag 					    * used to work around a cache bug 					    * in r0 steppings. See errata 					    * 364296. 					    */
end_comment

begin_comment
comment|/* ARM1176 Auxiliary Control Register (CP15 register 1, opcode2 1) */
end_comment

begin_define
define|#
directive|define
name|ARM1176_AUXCTL_PHD
value|0x10000000
end_define

begin_comment
comment|/* inst. prefetch halting disable */
end_comment

begin_define
define|#
directive|define
name|ARM1176_AUXCTL_BFD
value|0x20000000
end_define

begin_comment
comment|/* branch folding disable */
end_comment

begin_define
define|#
directive|define
name|ARM1176_AUXCTL_FSD
value|0x40000000
end_define

begin_comment
comment|/* force speculative ops disable */
end_comment

begin_define
define|#
directive|define
name|ARM1176_AUXCTL_FIO
value|0x80000000
end_define

begin_comment
comment|/* low intr latency override */
end_comment

begin_comment
comment|/* XScale Auxillary Control Register (CP15 register 1, opcode2 1) */
end_comment

begin_define
define|#
directive|define
name|XSCALE_AUXCTL_K
value|0x00000001
end_define

begin_comment
comment|/* dis. write buffer coalescing */
end_comment

begin_define
define|#
directive|define
name|XSCALE_AUXCTL_P
value|0x00000002
end_define

begin_comment
comment|/* ECC protect page table access */
end_comment

begin_comment
comment|/* Note: XSCale core 3 uses those for LLR DCcahce attributes */
end_comment

begin_define
define|#
directive|define
name|XSCALE_AUXCTL_MD_WB_RA
value|0x00000000
end_define

begin_comment
comment|/* mini-D$ wb, read-allocate */
end_comment

begin_define
define|#
directive|define
name|XSCALE_AUXCTL_MD_WB_RWA
value|0x00000010
end_define

begin_comment
comment|/* mini-D$ wb, read/write-allocate */
end_comment

begin_define
define|#
directive|define
name|XSCALE_AUXCTL_MD_WT
value|0x00000020
end_define

begin_comment
comment|/* mini-D$ wt, read-allocate */
end_comment

begin_define
define|#
directive|define
name|XSCALE_AUXCTL_MD_MASK
value|0x00000030
end_define

begin_comment
comment|/* Xscale Core 3 only */
end_comment

begin_define
define|#
directive|define
name|XSCALE_AUXCTL_LLR
value|0x00000400
end_define

begin_comment
comment|/* Enable L2 for LLR Cache */
end_comment

begin_comment
comment|/* Marvell Extra Features Register (CP15 register 1, opcode2 0) */
end_comment

begin_define
define|#
directive|define
name|MV_DC_REPLACE_LOCK
value|0x80000000
end_define

begin_comment
comment|/* Replace DCache Lock */
end_comment

begin_define
define|#
directive|define
name|MV_DC_STREAM_ENABLE
value|0x20000000
end_define

begin_comment
comment|/* DCache Streaming Switch */
end_comment

begin_define
define|#
directive|define
name|MV_WA_ENABLE
value|0x10000000
end_define

begin_comment
comment|/* Enable Write Allocate */
end_comment

begin_define
define|#
directive|define
name|MV_L2_PREFETCH_DISABLE
value|0x01000000
end_define

begin_comment
comment|/* L2 Cache Prefetch Disable */
end_comment

begin_define
define|#
directive|define
name|MV_L2_INV_EVICT_ERR
value|0x00800000
end_define

begin_comment
comment|/* L2 Invalidates Uncorrectable Error Line Eviction */
end_comment

begin_define
define|#
directive|define
name|MV_L2_ENABLE
value|0x00400000
end_define

begin_comment
comment|/* L2 Cache enable */
end_comment

begin_define
define|#
directive|define
name|MV_IC_REPLACE_LOCK
value|0x00080000
end_define

begin_comment
comment|/* Replace ICache Lock */
end_comment

begin_define
define|#
directive|define
name|MV_BGH_ENABLE
value|0x00040000
end_define

begin_comment
comment|/* Branch Global History Register Enable */
end_comment

begin_define
define|#
directive|define
name|MV_BTB_DISABLE
value|0x00020000
end_define

begin_comment
comment|/* Branch Target Buffer Disable */
end_comment

begin_define
define|#
directive|define
name|MV_L1_PARERR_ENABLE
value|0x00010000
end_define

begin_comment
comment|/* L1 Parity Error Enable */
end_comment

begin_comment
comment|/* Cache type register definitions */
end_comment

begin_define
define|#
directive|define
name|CPU_CT_ISIZE
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xfff)
end_define

begin_comment
comment|/* I$ info */
end_comment

begin_define
define|#
directive|define
name|CPU_CT_DSIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0xfff)
end_define

begin_comment
comment|/* D$ info */
end_comment

begin_define
define|#
directive|define
name|CPU_CT_S
value|(1U<< 24)
end_define

begin_comment
comment|/* split cache */
end_comment

begin_define
define|#
directive|define
name|CPU_CT_CTYPE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 25)& 0xf)
end_define

begin_comment
comment|/* cache type */
end_comment

begin_define
define|#
directive|define
name|CPU_CT_FORMAT
parameter_list|(
name|x
parameter_list|)
value|((x)>> 29)
end_define

begin_comment
comment|/* Cache type register definitions for ARM v7 */
end_comment

begin_define
define|#
directive|define
name|CPU_CT_IMINLINE
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xf)
end_define

begin_comment
comment|/* I$ min line size */
end_comment

begin_define
define|#
directive|define
name|CPU_CT_DMINLINE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xf)
end_define

begin_comment
comment|/* D$ min line size */
end_comment

begin_define
define|#
directive|define
name|CPU_CT_CTYPE_WT
value|0
end_define

begin_comment
comment|/* write-through */
end_comment

begin_define
define|#
directive|define
name|CPU_CT_CTYPE_WB1
value|1
end_define

begin_comment
comment|/* write-back, clean w/ read */
end_comment

begin_define
define|#
directive|define
name|CPU_CT_CTYPE_WB2
value|2
end_define

begin_comment
comment|/* w/b, clean w/ cp15,7 */
end_comment

begin_define
define|#
directive|define
name|CPU_CT_CTYPE_WB6
value|6
end_define

begin_comment
comment|/* w/b, cp15,7, lockdown fmt A */
end_comment

begin_define
define|#
directive|define
name|CPU_CT_CTYPE_WB7
value|7
end_define

begin_comment
comment|/* w/b, cp15,7, lockdown fmt B */
end_comment

begin_define
define|#
directive|define
name|CPU_CT_xSIZE_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x3)
end_define

begin_comment
comment|/* line size */
end_comment

begin_define
define|#
directive|define
name|CPU_CT_xSIZE_M
value|(1U<< 2)
end_define

begin_comment
comment|/* multiplier */
end_comment

begin_define
define|#
directive|define
name|CPU_CT_xSIZE_ASSOC
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 3)& 0x7)
end_define

begin_comment
comment|/* associativity */
end_comment

begin_define
define|#
directive|define
name|CPU_CT_xSIZE_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 6)& 0x7)
end_define

begin_comment
comment|/* size */
end_comment

begin_define
define|#
directive|define
name|CPU_CT_ARMV7
value|0x4
end_define

begin_comment
comment|/* ARM v7 Cache type definitions */
end_comment

begin_define
define|#
directive|define
name|CPUV7_CT_CTYPE_WT
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|CPUV7_CT_CTYPE_WB
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|CPUV7_CT_CTYPE_RA
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|CPUV7_CT_CTYPE_WA
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|CPUV7_CT_xSIZE_LEN
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x7)
end_define

begin_comment
comment|/* line size */
end_comment

begin_define
define|#
directive|define
name|CPUV7_CT_xSIZE_ASSOC
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 3)& 0x3ff)
end_define

begin_comment
comment|/* associativity */
end_comment

begin_define
define|#
directive|define
name|CPUV7_CT_xSIZE_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 13)& 0x7fff)
end_define

begin_comment
comment|/* num sets */
end_comment

begin_define
define|#
directive|define
name|CPUV7_L2CTLR_NPROC_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|CPUV7_L2CTLR_NPROC
parameter_list|(
name|r
parameter_list|)
value|((((r)>> CPUV7_L2CTLR_NPROC_SHIFT)& 3) + 1)
end_define

begin_define
define|#
directive|define
name|CPU_CLIDR_CTYPE
parameter_list|(
name|reg
parameter_list|,
name|x
parameter_list|)
value|(((reg)>> ((x) * 3))& 0x7)
end_define

begin_define
define|#
directive|define
name|CPU_CLIDR_LOUIS
parameter_list|(
name|reg
parameter_list|)
value|(((reg)>> 21)& 0x7)
end_define

begin_define
define|#
directive|define
name|CPU_CLIDR_LOC
parameter_list|(
name|reg
parameter_list|)
value|(((reg)>> 24)& 0x7)
end_define

begin_define
define|#
directive|define
name|CPU_CLIDR_LOUU
parameter_list|(
name|reg
parameter_list|)
value|(((reg)>> 27)& 0x7)
end_define

begin_define
define|#
directive|define
name|CACHE_ICACHE
value|1
end_define

begin_define
define|#
directive|define
name|CACHE_DCACHE
value|2
end_define

begin_define
define|#
directive|define
name|CACHE_SEP_CACHE
value|3
end_define

begin_define
define|#
directive|define
name|CACHE_UNI_CACHE
value|4
end_define

begin_comment
comment|/* Fault status register definitions */
end_comment

begin_define
define|#
directive|define
name|FAULT_USER
value|0x10
end_define

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|<
literal|6
end_if

begin_define
define|#
directive|define
name|FAULT_TYPE_MASK
value|0x0f
end_define

begin_define
define|#
directive|define
name|FAULT_WRTBUF_0
value|0x00
end_define

begin_comment
comment|/* Vector Exception */
end_comment

begin_define
define|#
directive|define
name|FAULT_WRTBUF_1
value|0x02
end_define

begin_comment
comment|/* Terminal Exception */
end_comment

begin_define
define|#
directive|define
name|FAULT_BUSERR_0
value|0x04
end_define

begin_comment
comment|/* External Abort on Linefetch -- Section */
end_comment

begin_define
define|#
directive|define
name|FAULT_BUSERR_1
value|0x06
end_define

begin_comment
comment|/* External Abort on Linefetch -- Page */
end_comment

begin_define
define|#
directive|define
name|FAULT_BUSERR_2
value|0x08
end_define

begin_comment
comment|/* External Abort on Non-linefetch -- Section */
end_comment

begin_define
define|#
directive|define
name|FAULT_BUSERR_3
value|0x0a
end_define

begin_comment
comment|/* External Abort on Non-linefetch -- Page */
end_comment

begin_define
define|#
directive|define
name|FAULT_BUSTRNL1
value|0x0c
end_define

begin_comment
comment|/* External abort on Translation -- Level 1 */
end_comment

begin_define
define|#
directive|define
name|FAULT_BUSTRNL2
value|0x0e
end_define

begin_comment
comment|/* External abort on Translation -- Level 2 */
end_comment

begin_define
define|#
directive|define
name|FAULT_ALIGN_0
value|0x01
end_define

begin_comment
comment|/* Alignment */
end_comment

begin_define
define|#
directive|define
name|FAULT_ALIGN_1
value|0x03
end_define

begin_comment
comment|/* Alignment */
end_comment

begin_define
define|#
directive|define
name|FAULT_TRANS_S
value|0x05
end_define

begin_comment
comment|/* Translation -- Section */
end_comment

begin_define
define|#
directive|define
name|FAULT_TRANS_F
value|0x06
end_define

begin_comment
comment|/* Translation -- Flag */
end_comment

begin_define
define|#
directive|define
name|FAULT_TRANS_P
value|0x07
end_define

begin_comment
comment|/* Translation -- Page */
end_comment

begin_define
define|#
directive|define
name|FAULT_DOMAIN_S
value|0x09
end_define

begin_comment
comment|/* Domain -- Section */
end_comment

begin_define
define|#
directive|define
name|FAULT_DOMAIN_P
value|0x0b
end_define

begin_comment
comment|/* Domain -- Page */
end_comment

begin_define
define|#
directive|define
name|FAULT_PERM_S
value|0x0d
end_define

begin_comment
comment|/* Permission -- Section */
end_comment

begin_define
define|#
directive|define
name|FAULT_PERM_P
value|0x0f
end_define

begin_comment
comment|/* Permission -- Page */
end_comment

begin_define
define|#
directive|define
name|FAULT_IMPRECISE
value|0x400
end_define

begin_comment
comment|/* Imprecise exception (XSCALE) */
end_comment

begin_define
define|#
directive|define
name|FAULT_EXTERNAL
value|0x400
end_define

begin_comment
comment|/* External abort (armv6+) */
end_comment

begin_define
define|#
directive|define
name|FAULT_WNR
value|0x800
end_define

begin_comment
comment|/* Write-not-Read access (armv6+) */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __ARM_ARCH< 6 */
end_comment

begin_define
define|#
directive|define
name|FAULT_ALIGN
value|0x001
end_define

begin_comment
comment|/* Alignment Fault */
end_comment

begin_define
define|#
directive|define
name|FAULT_DEBUG
value|0x002
end_define

begin_comment
comment|/* Debug Event */
end_comment

begin_define
define|#
directive|define
name|FAULT_ACCESS_L1
value|0x003
end_define

begin_comment
comment|/* Access Bit (L1) */
end_comment

begin_define
define|#
directive|define
name|FAULT_ICACHE
value|0x004
end_define

begin_comment
comment|/* Instruction cache maintenance */
end_comment

begin_define
define|#
directive|define
name|FAULT_TRAN_L1
value|0x005
end_define

begin_comment
comment|/* Translation Fault (L1) */
end_comment

begin_define
define|#
directive|define
name|FAULT_ACCESS_L2
value|0x006
end_define

begin_comment
comment|/* Access Bit (L2) */
end_comment

begin_define
define|#
directive|define
name|FAULT_TRAN_L2
value|0x007
end_define

begin_comment
comment|/* Translation Fault (L2) */
end_comment

begin_define
define|#
directive|define
name|FAULT_EA_PREC
value|0x008
end_define

begin_comment
comment|/* External Abort */
end_comment

begin_define
define|#
directive|define
name|FAULT_DOMAIN_L1
value|0x009
end_define

begin_comment
comment|/* Domain Fault (L1) */
end_comment

begin_define
define|#
directive|define
name|FAULT_DOMAIN_L2
value|0x00B
end_define

begin_comment
comment|/* Domain Fault (L2) */
end_comment

begin_define
define|#
directive|define
name|FAULT_EA_TRAN_L1
value|0x00C
end_define

begin_comment
comment|/* External Translation Abort (L1) */
end_comment

begin_define
define|#
directive|define
name|FAULT_PERM_L1
value|0x00D
end_define

begin_comment
comment|/* Permission Fault (L1) */
end_comment

begin_define
define|#
directive|define
name|FAULT_EA_TRAN_L2
value|0x00E
end_define

begin_comment
comment|/* External Translation Abort (L2) */
end_comment

begin_define
define|#
directive|define
name|FAULT_PERM_L2
value|0x00F
end_define

begin_comment
comment|/* Permission Fault (L2) */
end_comment

begin_define
define|#
directive|define
name|FAULT_TLB_CONFLICT
value|0x010
end_define

begin_comment
comment|/* TLB Conflict Abort */
end_comment

begin_define
define|#
directive|define
name|FAULT_EA_IMPREC
value|0x016
end_define

begin_comment
comment|/* Asynchronous External Abort */
end_comment

begin_define
define|#
directive|define
name|FAULT_PE_IMPREC
value|0x018
end_define

begin_comment
comment|/* Asynchronous Parity Error */
end_comment

begin_define
define|#
directive|define
name|FAULT_PARITY
value|0x019
end_define

begin_comment
comment|/* Parity Error */
end_comment

begin_define
define|#
directive|define
name|FAULT_PE_TRAN_L1
value|0x01C
end_define

begin_comment
comment|/* Parity Error on Translation (L1) */
end_comment

begin_define
define|#
directive|define
name|FAULT_PE_TRAN_L2
value|0x01E
end_define

begin_comment
comment|/* Parity Error on Translation (L2) */
end_comment

begin_define
define|#
directive|define
name|FSR_TO_FAULT
parameter_list|(
name|fsr
parameter_list|)
value|(((fsr)& 0xF) | 			\ 				 ((((fsr)& (1<< 10))>> (10 - 4))))
end_define

begin_define
define|#
directive|define
name|FSR_LPAE
value|(1<<  9)
end_define

begin_comment
comment|/* LPAE indicator */
end_comment

begin_define
define|#
directive|define
name|FSR_WNR
value|(1<< 11)
end_define

begin_comment
comment|/* Write-not-Read access */
end_comment

begin_define
define|#
directive|define
name|FSR_EXT
value|(1<< 12)
end_define

begin_comment
comment|/* DECERR/SLVERR for external*/
end_comment

begin_define
define|#
directive|define
name|FSR_CM
value|(1<< 13)
end_define

begin_comment
comment|/* Cache maintenance fault */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__ARM_ARCH< 6 */
end_comment

begin_comment
comment|/*  * Address of the vector page, low and high versions.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ASSEMBLER__
end_ifndef

begin_define
define|#
directive|define
name|ARM_VECTORS_LOW
value|0x00000000U
end_define

begin_define
define|#
directive|define
name|ARM_VECTORS_HIGH
value|0xffff0000U
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ARM_VECTORS_LOW
value|0
end_define

begin_define
define|#
directive|define
name|ARM_VECTORS_HIGH
value|0xffff0000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * ARM Instructions  *  *       3 3 2 2 2  *       1 0 9 8 7                                                     0  *      +-------+-------------------------------------------------------+  *      | cond  |              instruction dependant                    |  *      |c c c c|                                                       |  *      +-------+-------------------------------------------------------+  */
end_comment

begin_define
define|#
directive|define
name|INSN_SIZE
value|4
end_define

begin_comment
comment|/* Always 4 bytes */
end_comment

begin_define
define|#
directive|define
name|INSN_COND_MASK
value|0xf0000000
end_define

begin_comment
comment|/* Condition mask */
end_comment

begin_define
define|#
directive|define
name|INSN_COND_AL
value|0xe0000000
end_define

begin_comment
comment|/* Always condition */
end_comment

begin_comment
comment|/* ARM register defines */
end_comment

begin_define
define|#
directive|define
name|ARM_REG_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|ARM_REG_NUM_PC
value|15
end_define

begin_define
define|#
directive|define
name|ARM_REG_NUM_LR
value|14
end_define

begin_define
define|#
directive|define
name|ARM_REG_NUM_SP
value|13
end_define

begin_define
define|#
directive|define
name|THUMB_INSN_SIZE
value|2
end_define

begin_comment
comment|/* Some are 4 bytes.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !MACHINE_ARMREG_H */
end_comment

end_unit

