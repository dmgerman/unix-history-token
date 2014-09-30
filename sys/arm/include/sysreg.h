begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2014 Svatopluk Kraus<onwahe@gmail.com>  * Copyright 2014 Michal Meloun<meloun@miracle.cz>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Macros to make working with the System Control Registers simpler.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MACHINE_SYSREG_H
end_ifndef

begin_define
define|#
directive|define
name|MACHINE_SYSREG_H
end_define

begin_include
include|#
directive|include
file|<machine/acle-compat.h>
end_include

begin_comment
comment|/*  * CP15 C0 registers  */
end_comment

begin_define
define|#
directive|define
name|CP15_MIDR
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c0, c0,  0
end_define

begin_comment
comment|/* Main ID Register */
end_comment

begin_define
define|#
directive|define
name|CP15_CTR
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c0, c0,  1
end_define

begin_comment
comment|/* Cache Type Register */
end_comment

begin_define
define|#
directive|define
name|CP15_TCMTR
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c0, c0,  2
end_define

begin_comment
comment|/* TCM Type Register */
end_comment

begin_define
define|#
directive|define
name|CP15_TLBTR
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c0, c0,  3
end_define

begin_comment
comment|/* TLB Type Register */
end_comment

begin_define
define|#
directive|define
name|CP15_MPIDR
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c0, c0,  5
end_define

begin_comment
comment|/* Multiprocessor Affinity Register */
end_comment

begin_define
define|#
directive|define
name|CP15_REVIDR
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c0, c0,  6
end_define

begin_comment
comment|/* Revision ID Register */
end_comment

begin_define
define|#
directive|define
name|CP15_ID_PFR0
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c0, c1,  0
end_define

begin_comment
comment|/* Processor Feature Register 0 */
end_comment

begin_define
define|#
directive|define
name|CP15_ID_PFR1
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c0, c1,  1
end_define

begin_comment
comment|/* Processor Feature Register 1 */
end_comment

begin_define
define|#
directive|define
name|CP15_ID_DFR0
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c0, c1,  2
end_define

begin_comment
comment|/* Debug Feature Register 0 */
end_comment

begin_define
define|#
directive|define
name|CP15_ID_AFR0
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c0, c1,  3
end_define

begin_comment
comment|/* Auxiliary Feature Register  0 */
end_comment

begin_define
define|#
directive|define
name|CP15_ID_MMFR0
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c0, c1,  4
end_define

begin_comment
comment|/* Memory Model Feature Register 0 */
end_comment

begin_define
define|#
directive|define
name|CP15_ID_MMFR1
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c0, c1,  5
end_define

begin_comment
comment|/* Memory Model Feature Register 1 */
end_comment

begin_define
define|#
directive|define
name|CP15_ID_MMFR2
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c0, c1,  6
end_define

begin_comment
comment|/* Memory Model Feature Register 2 */
end_comment

begin_define
define|#
directive|define
name|CP15_ID_MMFR3
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c0, c1,  7
end_define

begin_comment
comment|/* Memory Model Feature Register 3 */
end_comment

begin_define
define|#
directive|define
name|CP15_ID_ISAR0
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c0, c2,  0
end_define

begin_comment
comment|/* Instruction Set Attribute Register 0 */
end_comment

begin_define
define|#
directive|define
name|CP15_ID_ISAR1
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c0, c2,  1
end_define

begin_comment
comment|/* Instruction Set Attribute Register 1 */
end_comment

begin_define
define|#
directive|define
name|CP15_ID_ISAR2
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c0, c2,  2
end_define

begin_comment
comment|/* Instruction Set Attribute Register 2 */
end_comment

begin_define
define|#
directive|define
name|CP15_ID_ISAR3
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c0, c2,  3
end_define

begin_comment
comment|/* Instruction Set Attribute Register 3 */
end_comment

begin_define
define|#
directive|define
name|CP15_ID_ISAR4
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c0, c2,  4
end_define

begin_comment
comment|/* Instruction Set Attribute Register 4 */
end_comment

begin_define
define|#
directive|define
name|CP15_ID_ISAR5
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c0, c2,  5
end_define

begin_comment
comment|/* Instruction Set Attribute Register 5 */
end_comment

begin_define
define|#
directive|define
name|CP15_CCSIDR
parameter_list|(
name|rr
parameter_list|)
value|p15, 1, rr, c0, c0,  0
end_define

begin_comment
comment|/* Cache Size ID Registers */
end_comment

begin_define
define|#
directive|define
name|CP15_CLIDR
parameter_list|(
name|rr
parameter_list|)
value|p15, 1, rr, c0, c0,  1
end_define

begin_comment
comment|/* Cache Level ID Register */
end_comment

begin_define
define|#
directive|define
name|CP15_AIDR
parameter_list|(
name|rr
parameter_list|)
value|p15, 1, rr, c0, c0,  7
end_define

begin_comment
comment|/* Auxiliary ID Register */
end_comment

begin_define
define|#
directive|define
name|CP15_CSSELR
parameter_list|(
name|rr
parameter_list|)
value|p15, 2, rr, c0, c0,  0
end_define

begin_comment
comment|/* Cache Size Selection Register */
end_comment

begin_comment
comment|/*  * CP15 C1 registers  */
end_comment

begin_define
define|#
directive|define
name|CP15_SCTLR
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c1, c0,  0
end_define

begin_comment
comment|/* System Control Register */
end_comment

begin_define
define|#
directive|define
name|CP15_ACTLR
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c1, c0,  1
end_define

begin_comment
comment|/* IMPLEMENTATION DEFINED Auxiliary Control Register */
end_comment

begin_define
define|#
directive|define
name|CP15_CPACR
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c1, c0,  2
end_define

begin_comment
comment|/* Coprocessor Access Control Register */
end_comment

begin_define
define|#
directive|define
name|CP15_SCR
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c1, c1,  0
end_define

begin_comment
comment|/* Secure Configuration Register */
end_comment

begin_define
define|#
directive|define
name|CP15_SDER
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c1, c1,  1
end_define

begin_comment
comment|/* Secure Debug Enable Register */
end_comment

begin_define
define|#
directive|define
name|CP15_NSACR
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c1, c1,  2
end_define

begin_comment
comment|/* Non-Secure Access Control Register */
end_comment

begin_comment
comment|/*  * CP15 C2 registers  */
end_comment

begin_define
define|#
directive|define
name|CP15_TTBR0
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c2, c0,  0
end_define

begin_comment
comment|/* Translation Table Base Register 0 */
end_comment

begin_define
define|#
directive|define
name|CP15_TTBR1
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c2, c0,  1
end_define

begin_comment
comment|/* Translation Table Base Register 1 */
end_comment

begin_define
define|#
directive|define
name|CP15_TTBCR
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c2, c0,  2
end_define

begin_comment
comment|/* Translation Table Base Control Register */
end_comment

begin_comment
comment|/*  * CP15 C3 registers  */
end_comment

begin_define
define|#
directive|define
name|CP15_DACR
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c3, c0,  0
end_define

begin_comment
comment|/* Domain Access Control Register */
end_comment

begin_comment
comment|/*  * CP15 C5 registers  */
end_comment

begin_define
define|#
directive|define
name|CP15_DFSR
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c5, c0,  0
end_define

begin_comment
comment|/* Data Fault Status Register */
end_comment

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|>=
literal|6
end_if

begin_comment
comment|/* From ARMv6: */
end_comment

begin_define
define|#
directive|define
name|CP15_IFSR
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c5, c0,  1
end_define

begin_comment
comment|/* Instruction Fault Status Register */
end_comment

begin_comment
comment|/* From ARMv7: */
end_comment

begin_define
define|#
directive|define
name|CP15_ADFSR
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c5, c1,  0
end_define

begin_comment
comment|/* Auxiliary Data Fault Status Register */
end_comment

begin_define
define|#
directive|define
name|CP15_AIFSR
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c5, c1,  1
end_define

begin_comment
comment|/* Auxiliary Instruction Fault Status Register */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * CP15 C6 registers  */
end_comment

begin_define
define|#
directive|define
name|CP15_DFAR
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c6, c0,  0
end_define

begin_comment
comment|/* Data Fault Address Register */
end_comment

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|>=
literal|6
end_if

begin_comment
comment|/* From ARMv6k: */
end_comment

begin_define
define|#
directive|define
name|CP15_IFAR
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c6, c0,  2
end_define

begin_comment
comment|/* Instruction Fault Address Register */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * CP15 C7 registers  */
end_comment

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|>=
literal|6
end_if

begin_comment
comment|/* From ARMv7: */
end_comment

begin_define
define|#
directive|define
name|CP15_ICIALLUIS
value|p15, 0, r0, c7, c1,  0
end_define

begin_comment
comment|/* Instruction cache invalidate all PoU, IS */
end_comment

begin_define
define|#
directive|define
name|CP15_BPIALLIS
value|p15, 0, r0, c7, c1,  6
end_define

begin_comment
comment|/* Branch predictor invalidate all IS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CP15_PAR
value|p15, 0, r0, c7, c4,  0
end_define

begin_comment
comment|/* Physical Address Register */
end_comment

begin_define
define|#
directive|define
name|CP15_ICIALLU
value|p15, 0, r0, c7, c5,  0
end_define

begin_comment
comment|/* Instruction cache invalidate all PoU */
end_comment

begin_define
define|#
directive|define
name|CP15_ICIMVAU
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c7, c5,  1
end_define

begin_comment
comment|/* Instruction cache invalidate */
end_comment

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|>=
literal|6
end_if

begin_comment
comment|/* Deprecated in ARMv7 */
end_comment

begin_define
define|#
directive|define
name|CP15_CP15ISB
value|p15, 0, r0, c7, c5,  4
end_define

begin_comment
comment|/* ISB */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CP15_BPIALL
value|p15, 0, r0, c7, c5,  6
end_define

begin_comment
comment|/* Branch predictor invalidate all */
end_comment

begin_define
define|#
directive|define
name|CP15_BPIMVA
value|p15, 0, rr, c7, c5,  7
end_define

begin_comment
comment|/* Branch predictor invalidate by MVA */
end_comment

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|>=
literal|6
end_if

begin_comment
comment|/* Only ARMv6: */
end_comment

begin_define
define|#
directive|define
name|CP15_DCIALL
value|p15, 0, r0, c7, c6,  0
end_define

begin_comment
comment|/* Data cache invalidate all */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CP15_DCIMVAC
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c7, c6,  1
end_define

begin_comment
comment|/* Data cache invalidate by MVA PoC */
end_comment

begin_define
define|#
directive|define
name|CP15_DCISW
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c7, c6,  2
end_define

begin_comment
comment|/* Data cache invalidate by set/way */
end_comment

begin_define
define|#
directive|define
name|CP15_ATS1CPR
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c7, c8,  0
end_define

begin_comment
comment|/* Stage 1 Current state PL1 read */
end_comment

begin_define
define|#
directive|define
name|CP15_ATS1CPW
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c7, c8,  1
end_define

begin_comment
comment|/* Stage 1 Current state PL1 write */
end_comment

begin_define
define|#
directive|define
name|CP15_ATS1CUR
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c7, c8,  2
end_define

begin_comment
comment|/* Stage 1 Current state unprivileged read */
end_comment

begin_define
define|#
directive|define
name|CP15_ATS1CUW
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c7, c8,  3
end_define

begin_comment
comment|/* Stage 1 Current state unprivileged write */
end_comment

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|>=
literal|6
end_if

begin_comment
comment|/* From ARMv7: */
end_comment

begin_define
define|#
directive|define
name|CP15_ATS12NSOPR
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c7, c8,  4
end_define

begin_comment
comment|/* Stages 1 and 2 Non-secure only PL1 read */
end_comment

begin_define
define|#
directive|define
name|CP15_ATS12NSOPW
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c7, c8,  5
end_define

begin_comment
comment|/* Stages 1 and 2 Non-secure only PL1 write */
end_comment

begin_define
define|#
directive|define
name|CP15_ATS12NSOUR
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c7, c8,  6
end_define

begin_comment
comment|/* Stages 1 and 2 Non-secure only unprivileged read */
end_comment

begin_define
define|#
directive|define
name|CP15_ATS12NSOUW
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c7, c8,  7
end_define

begin_comment
comment|/* Stages 1 and 2 Non-secure only unprivileged write */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|>=
literal|6
end_if

begin_comment
comment|/* Only ARMv6: */
end_comment

begin_define
define|#
directive|define
name|CP15_DCCALL
value|p15, 0, r0, c7, c10, 0
end_define

begin_comment
comment|/* Data cache clean all */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CP15_DCCMVAC
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c7, c10, 1
end_define

begin_comment
comment|/* Data cache clean by MVA PoC */
end_comment

begin_define
define|#
directive|define
name|CP15_DCCSW
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c7, c10, 2
end_define

begin_comment
comment|/* Data cache clean by set/way */
end_comment

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|>=
literal|6
end_if

begin_comment
comment|/* Only ARMv6: */
end_comment

begin_define
define|#
directive|define
name|CP15_CP15DSB
value|p15, 0, r0, c7, c10, 4
end_define

begin_comment
comment|/* DSB */
end_comment

begin_define
define|#
directive|define
name|CP15_CP15DMB
value|p15, 0, r0, c7, c10, 5
end_define

begin_comment
comment|/* DMB */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|>=
literal|6
end_if

begin_comment
comment|/* From ARMv7: */
end_comment

begin_define
define|#
directive|define
name|CP15_DCCMVAU
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c7, c11, 1
end_define

begin_comment
comment|/* Data cache clean by MVA PoU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|>=
literal|6
end_if

begin_comment
comment|/* Only ARMv6: */
end_comment

begin_define
define|#
directive|define
name|CP15_DCCIALL
value|p15, 0, r0, c7, c14, 0
end_define

begin_comment
comment|/* Data cache clean and invalidate all */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CP15_DCCIMVAC
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c7, c14, 1
end_define

begin_comment
comment|/* Data cache clean and invalidate by MVA PoC */
end_comment

begin_define
define|#
directive|define
name|CP15_DCCISW
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c7, c14, 2
end_define

begin_comment
comment|/* Data cache clean and invalidate by set/way */
end_comment

begin_comment
comment|/*  * CP15 C8 registers  */
end_comment

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|>=
literal|6
end_if

begin_comment
comment|/* From ARMv7: */
end_comment

begin_define
define|#
directive|define
name|CP15_TLBIALLIS
value|p15, 0, r0, c8, c3, 0
end_define

begin_comment
comment|/* Invalidate entire unified TLB IS */
end_comment

begin_define
define|#
directive|define
name|CP15_TLBIMVAIS
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c8, c3, 1
end_define

begin_comment
comment|/* Invalidate unified TLB by MVA IS */
end_comment

begin_define
define|#
directive|define
name|CP15_TLBIASIDIS
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c8, c3, 2
end_define

begin_comment
comment|/* Invalidate unified TLB by ASID IS */
end_comment

begin_define
define|#
directive|define
name|CP15_TLBIMVAAIS
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c8, c3, 3
end_define

begin_comment
comment|/* Invalidate unified TLB by MVA, all ASID IS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CP15_TLBIALL
value|p15, 0, r0, c8, c7, 0
end_define

begin_comment
comment|/* Invalidate entire unified TLB */
end_comment

begin_define
define|#
directive|define
name|CP15_TLBIMVA
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c8, c7, 1
end_define

begin_comment
comment|/* Invalidate unified TLB by MVA */
end_comment

begin_define
define|#
directive|define
name|CP15_TLBIASID
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c8, c7, 2
end_define

begin_comment
comment|/* Invalidate unified TLB by ASID */
end_comment

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|>=
literal|6
end_if

begin_comment
comment|/* From ARMv6: */
end_comment

begin_define
define|#
directive|define
name|CP15_TLBIMVAA
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c8, c7, 3
end_define

begin_comment
comment|/* Invalidate unified TLB by MVA, all ASID */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * CP15 C10 registers  */
end_comment

begin_comment
comment|/* Without LPAE this is PRRR, with LPAE it's MAIR0 */
end_comment

begin_define
define|#
directive|define
name|CP15_PRRR
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c10, c2, 0
end_define

begin_comment
comment|/* Primary Region Remap Register */
end_comment

begin_define
define|#
directive|define
name|CP15_MAIR0
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c10, c2, 0
end_define

begin_comment
comment|/* Memory Attribute Indirection Register 0 */
end_comment

begin_comment
comment|/* Without LPAE this is NMRR, with LPAE it's MAIR1 */
end_comment

begin_define
define|#
directive|define
name|CP15_NMRR
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c10, c2, 1
end_define

begin_comment
comment|/* Normal Memory Remap Register */
end_comment

begin_define
define|#
directive|define
name|CP15_MAIR1
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c10, c2, 1
end_define

begin_comment
comment|/* Memory Attribute Indirection Register 1 */
end_comment

begin_define
define|#
directive|define
name|CP15_AMAIR0
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c10, c3, 0
end_define

begin_comment
comment|/* Auxiliary Memory Attribute Indirection Register 0 */
end_comment

begin_define
define|#
directive|define
name|CP15_AMAIR1
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c10, c3, 1
end_define

begin_comment
comment|/* Auxiliary Memory Attribute Indirection Register 1 */
end_comment

begin_comment
comment|/*  * CP15 C12 registers  */
end_comment

begin_define
define|#
directive|define
name|CP15_VBAR
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c12, c0, 0
end_define

begin_comment
comment|/* Vector Base Address Register */
end_comment

begin_define
define|#
directive|define
name|CP15_MVBAR
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c12, c0, 1
end_define

begin_comment
comment|/* Monitor Vector Base Address Register */
end_comment

begin_define
define|#
directive|define
name|CP15_ISR
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c12, c1, 0
end_define

begin_comment
comment|/* Interrupt Status Register */
end_comment

begin_comment
comment|/*  * CP15 C13 registers  */
end_comment

begin_define
define|#
directive|define
name|CP15_FCSEIDR
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c13, c0, 0
end_define

begin_comment
comment|/* FCSE Process ID Register */
end_comment

begin_define
define|#
directive|define
name|CP15_CONTEXTIDR
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c13, c0, 1
end_define

begin_comment
comment|/* Context ID Register */
end_comment

begin_define
define|#
directive|define
name|CP15_TPIDRURW
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c13, c0, 2
end_define

begin_comment
comment|/* User Read/Write Thread ID Register */
end_comment

begin_define
define|#
directive|define
name|CP15_TPIDRURO
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c13, c0, 3
end_define

begin_comment
comment|/* User Read-Only Thread ID Register */
end_comment

begin_define
define|#
directive|define
name|CP15_TPIDRPRW
parameter_list|(
name|rr
parameter_list|)
value|p15, 0, rr, c13, c0, 4
end_define

begin_comment
comment|/* PL1 only Thread ID Register */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !MACHINE_SYSREG_H */
end_comment

end_unit

