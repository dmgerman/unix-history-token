begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)specialreg.h	7.1 (Berkeley) 5/9/91  * $FreeBSD$  */
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
comment|/* "Math" (fpu) Present */
end_comment

begin_define
define|#
directive|define
name|CR0_EM
value|0x00000004
end_define

begin_comment
comment|/* EMulate FPU instructions. (trap ESC only) */
end_comment

begin_define
define|#
directive|define
name|CR0_TS
value|0x00000008
end_define

begin_comment
comment|/* Task Switched (if MP, trap ESC and WAIT) */
end_comment

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
comment|/* Write Protect (honor page protect in 							   all modes) */
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

begin_define
define|#
directive|define
name|CR0_NW
value|0x20000000
end_define

begin_comment
comment|/* Not Write-through */
end_comment

begin_define
define|#
directive|define
name|CR0_CD
value|0x40000000
end_define

begin_comment
comment|/* Cache Disable */
end_comment

begin_comment
comment|/*  * Bits in PPro special registers  */
end_comment

begin_define
define|#
directive|define
name|CR4_VME
value|0x00000001
end_define

begin_comment
comment|/* Virtual 8086 mode extensions */
end_comment

begin_define
define|#
directive|define
name|CR4_PVI
value|0x00000002
end_define

begin_comment
comment|/* Protected-mode virtual interrupts */
end_comment

begin_define
define|#
directive|define
name|CR4_TSD
value|0x00000004
end_define

begin_comment
comment|/* Time stamp disable */
end_comment

begin_define
define|#
directive|define
name|CR4_DE
value|0x00000008
end_define

begin_comment
comment|/* Debugging extensions */
end_comment

begin_define
define|#
directive|define
name|CR4_PSE
value|0x00000010
end_define

begin_comment
comment|/* Page size extensions */
end_comment

begin_define
define|#
directive|define
name|CR4_PAE
value|0x00000020
end_define

begin_comment
comment|/* Physical address extension */
end_comment

begin_define
define|#
directive|define
name|CR4_MCE
value|0x00000040
end_define

begin_comment
comment|/* Machine check enable */
end_comment

begin_define
define|#
directive|define
name|CR4_PGE
value|0x00000080
end_define

begin_comment
comment|/* Page global enable */
end_comment

begin_define
define|#
directive|define
name|CR4_PCE
value|0x00000100
end_define

begin_comment
comment|/* Performance monitoring counter enable */
end_comment

begin_define
define|#
directive|define
name|CR4_FXSR
value|0x00000200
end_define

begin_comment
comment|/* Fast FPU save/restore used by OS */
end_comment

begin_define
define|#
directive|define
name|CR4_XMM
value|0x00000400
end_define

begin_comment
comment|/* enable SIMD/MMX2 to use except 16 */
end_comment

begin_comment
comment|/*  * Bits in AMD64 special registers.  EFER is 64 bits wide.  */
end_comment

begin_define
define|#
directive|define
name|EFER_SCE
value|0x000000001
end_define

begin_comment
comment|/* System Call Extensions (R/W) */
end_comment

begin_define
define|#
directive|define
name|EFER_LME
value|0x000000100
end_define

begin_comment
comment|/* Long mode enable (R/W) */
end_comment

begin_define
define|#
directive|define
name|EFER_LMA
value|0x000000400
end_define

begin_comment
comment|/* Long mode active (R) */
end_comment

begin_define
define|#
directive|define
name|EFER_NXE
value|0x000000800
end_define

begin_comment
comment|/* PTE No-Execute bit enable (R/W) */
end_comment

begin_comment
comment|/*  * CPUID instruction features register  */
end_comment

begin_define
define|#
directive|define
name|CPUID_FPU
value|0x00000001
end_define

begin_define
define|#
directive|define
name|CPUID_VME
value|0x00000002
end_define

begin_define
define|#
directive|define
name|CPUID_DE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|CPUID_PSE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|CPUID_TSC
value|0x00000010
end_define

begin_define
define|#
directive|define
name|CPUID_MSR
value|0x00000020
end_define

begin_define
define|#
directive|define
name|CPUID_PAE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|CPUID_MCE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|CPUID_CX8
value|0x00000100
end_define

begin_define
define|#
directive|define
name|CPUID_APIC
value|0x00000200
end_define

begin_define
define|#
directive|define
name|CPUID_B10
value|0x00000400
end_define

begin_define
define|#
directive|define
name|CPUID_SEP
value|0x00000800
end_define

begin_define
define|#
directive|define
name|CPUID_MTRR
value|0x00001000
end_define

begin_define
define|#
directive|define
name|CPUID_PGE
value|0x00002000
end_define

begin_define
define|#
directive|define
name|CPUID_MCA
value|0x00004000
end_define

begin_define
define|#
directive|define
name|CPUID_CMOV
value|0x00008000
end_define

begin_define
define|#
directive|define
name|CPUID_PAT
value|0x00010000
end_define

begin_define
define|#
directive|define
name|CPUID_PSE36
value|0x00020000
end_define

begin_define
define|#
directive|define
name|CPUID_PSN
value|0x00040000
end_define

begin_define
define|#
directive|define
name|CPUID_CLFSH
value|0x00080000
end_define

begin_define
define|#
directive|define
name|CPUID_B20
value|0x00100000
end_define

begin_define
define|#
directive|define
name|CPUID_DS
value|0x00200000
end_define

begin_define
define|#
directive|define
name|CPUID_ACPI
value|0x00400000
end_define

begin_define
define|#
directive|define
name|CPUID_MMX
value|0x00800000
end_define

begin_define
define|#
directive|define
name|CPUID_FXSR
value|0x01000000
end_define

begin_define
define|#
directive|define
name|CPUID_SSE
value|0x02000000
end_define

begin_define
define|#
directive|define
name|CPUID_XMM
value|0x02000000
end_define

begin_define
define|#
directive|define
name|CPUID_SSE2
value|0x04000000
end_define

begin_define
define|#
directive|define
name|CPUID_SS
value|0x08000000
end_define

begin_define
define|#
directive|define
name|CPUID_HTT
value|0x10000000
end_define

begin_define
define|#
directive|define
name|CPUID_TM
value|0x20000000
end_define

begin_define
define|#
directive|define
name|CPUID_IA64
value|0x40000000
end_define

begin_define
define|#
directive|define
name|CPUID_PBE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|CPUID2_SSE3
value|0x00000001
end_define

begin_define
define|#
directive|define
name|CPUID2_MON
value|0x00000008
end_define

begin_define
define|#
directive|define
name|CPUID2_DS_CPL
value|0x00000010
end_define

begin_define
define|#
directive|define
name|CPUID2_VMX
value|0x00000020
end_define

begin_define
define|#
directive|define
name|CPUID2_EST
value|0x00000080
end_define

begin_define
define|#
directive|define
name|CPUID2_TM2
value|0x00000100
end_define

begin_define
define|#
directive|define
name|CPUID2_SSSE3
value|0x00000200
end_define

begin_define
define|#
directive|define
name|CPUID2_CNXTID
value|0x00000400
end_define

begin_define
define|#
directive|define
name|CPUID2_CX16
value|0x00002000
end_define

begin_define
define|#
directive|define
name|CPUID2_XTPR
value|0x00004000
end_define

begin_comment
comment|/*  * Important bits in the AMD extended cpuid flags  */
end_comment

begin_define
define|#
directive|define
name|AMDID_SYSCALL
value|0x00000800
end_define

begin_define
define|#
directive|define
name|AMDID_MP
value|0x00080000
end_define

begin_define
define|#
directive|define
name|AMDID_NX
value|0x00100000
end_define

begin_define
define|#
directive|define
name|AMDID_EXT_MMX
value|0x00400000
end_define

begin_define
define|#
directive|define
name|AMDID_FFXSR
value|0x01000000
end_define

begin_define
define|#
directive|define
name|AMDID_RDTSCP
value|0x08000000
end_define

begin_define
define|#
directive|define
name|AMDID_LM
value|0x20000000
end_define

begin_define
define|#
directive|define
name|AMDID_EXT_3DNOW
value|0x40000000
end_define

begin_define
define|#
directive|define
name|AMDID_3DNOW
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AMDID2_LAHF
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AMDID2_CMP
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AMDID2_SVM
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AMDID2_EXT_APIC
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AMDID2_CR8
value|0x00000010
end_define

begin_define
define|#
directive|define
name|AMDID2_PREFETCH
value|0x00000100
end_define

begin_comment
comment|/*  * CPUID instruction 1 ebx info  */
end_comment

begin_define
define|#
directive|define
name|CPUID_BRAND_INDEX
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|CPUID_CLFUSH_SIZE
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|CPUID_HTT_CORES
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|CPUID_LOCAL_APIC_ID
value|0xff000000
end_define

begin_comment
comment|/*  * AMD extended function 8000_0008h ecx info  */
end_comment

begin_define
define|#
directive|define
name|AMDID_CMP_CORES
value|0x000000ff
end_define

begin_comment
comment|/*  * Model-specific registers for the i386 family  */
end_comment

begin_define
define|#
directive|define
name|MSR_P5_MC_ADDR
value|0x000
end_define

begin_define
define|#
directive|define
name|MSR_P5_MC_TYPE
value|0x001
end_define

begin_define
define|#
directive|define
name|MSR_TSC
value|0x010
end_define

begin_define
define|#
directive|define
name|MSR_P5_CESR
value|0x011
end_define

begin_define
define|#
directive|define
name|MSR_P5_CTR0
value|0x012
end_define

begin_define
define|#
directive|define
name|MSR_P5_CTR1
value|0x013
end_define

begin_define
define|#
directive|define
name|MSR_IA32_PLATFORM_ID
value|0x017
end_define

begin_define
define|#
directive|define
name|MSR_APICBASE
value|0x01b
end_define

begin_define
define|#
directive|define
name|MSR_EBL_CR_POWERON
value|0x02a
end_define

begin_define
define|#
directive|define
name|MSR_TEST_CTL
value|0x033
end_define

begin_define
define|#
directive|define
name|MSR_BIOS_UPDT_TRIG
value|0x079
end_define

begin_define
define|#
directive|define
name|MSR_BBL_CR_D0
value|0x088
end_define

begin_define
define|#
directive|define
name|MSR_BBL_CR_D1
value|0x089
end_define

begin_define
define|#
directive|define
name|MSR_BBL_CR_D2
value|0x08a
end_define

begin_define
define|#
directive|define
name|MSR_BIOS_SIGN
value|0x08b
end_define

begin_define
define|#
directive|define
name|MSR_PERFCTR0
value|0x0c1
end_define

begin_define
define|#
directive|define
name|MSR_PERFCTR1
value|0x0c2
end_define

begin_define
define|#
directive|define
name|MSR_MTRRcap
value|0x0fe
end_define

begin_define
define|#
directive|define
name|MSR_BBL_CR_ADDR
value|0x116
end_define

begin_define
define|#
directive|define
name|MSR_BBL_CR_DECC
value|0x118
end_define

begin_define
define|#
directive|define
name|MSR_BBL_CR_CTL
value|0x119
end_define

begin_define
define|#
directive|define
name|MSR_BBL_CR_TRIG
value|0x11a
end_define

begin_define
define|#
directive|define
name|MSR_BBL_CR_BUSY
value|0x11b
end_define

begin_define
define|#
directive|define
name|MSR_BBL_CR_CTL3
value|0x11e
end_define

begin_define
define|#
directive|define
name|MSR_SYSENTER_CS_MSR
value|0x174
end_define

begin_define
define|#
directive|define
name|MSR_SYSENTER_ESP_MSR
value|0x175
end_define

begin_define
define|#
directive|define
name|MSR_SYSENTER_EIP_MSR
value|0x176
end_define

begin_define
define|#
directive|define
name|MSR_MCG_CAP
value|0x179
end_define

begin_define
define|#
directive|define
name|MSR_MCG_STATUS
value|0x17a
end_define

begin_define
define|#
directive|define
name|MSR_MCG_CTL
value|0x17b
end_define

begin_define
define|#
directive|define
name|MSR_EVNTSEL0
value|0x186
end_define

begin_define
define|#
directive|define
name|MSR_EVNTSEL1
value|0x187
end_define

begin_define
define|#
directive|define
name|MSR_THERM_CONTROL
value|0x19a
end_define

begin_define
define|#
directive|define
name|MSR_THERM_INTERRUPT
value|0x19b
end_define

begin_define
define|#
directive|define
name|MSR_THERM_STATUS
value|0x19c
end_define

begin_define
define|#
directive|define
name|MSR_IA32_MISC_ENABLE
value|0x1a0
end_define

begin_define
define|#
directive|define
name|MSR_DEBUGCTLMSR
value|0x1d9
end_define

begin_define
define|#
directive|define
name|MSR_LASTBRANCHFROMIP
value|0x1db
end_define

begin_define
define|#
directive|define
name|MSR_LASTBRANCHTOIP
value|0x1dc
end_define

begin_define
define|#
directive|define
name|MSR_LASTINTFROMIP
value|0x1dd
end_define

begin_define
define|#
directive|define
name|MSR_LASTINTTOIP
value|0x1de
end_define

begin_define
define|#
directive|define
name|MSR_ROB_CR_BKUPTMPDR6
value|0x1e0
end_define

begin_define
define|#
directive|define
name|MSR_MTRRVarBase
value|0x200
end_define

begin_define
define|#
directive|define
name|MSR_MTRR64kBase
value|0x250
end_define

begin_define
define|#
directive|define
name|MSR_MTRR16kBase
value|0x258
end_define

begin_define
define|#
directive|define
name|MSR_MTRR4kBase
value|0x268
end_define

begin_define
define|#
directive|define
name|MSR_PAT
value|0x277
end_define

begin_define
define|#
directive|define
name|MSR_MTRRdefType
value|0x2ff
end_define

begin_define
define|#
directive|define
name|MSR_MC0_CTL
value|0x400
end_define

begin_define
define|#
directive|define
name|MSR_MC0_STATUS
value|0x401
end_define

begin_define
define|#
directive|define
name|MSR_MC0_ADDR
value|0x402
end_define

begin_define
define|#
directive|define
name|MSR_MC0_MISC
value|0x403
end_define

begin_define
define|#
directive|define
name|MSR_MC1_CTL
value|0x404
end_define

begin_define
define|#
directive|define
name|MSR_MC1_STATUS
value|0x405
end_define

begin_define
define|#
directive|define
name|MSR_MC1_ADDR
value|0x406
end_define

begin_define
define|#
directive|define
name|MSR_MC1_MISC
value|0x407
end_define

begin_define
define|#
directive|define
name|MSR_MC2_CTL
value|0x408
end_define

begin_define
define|#
directive|define
name|MSR_MC2_STATUS
value|0x409
end_define

begin_define
define|#
directive|define
name|MSR_MC2_ADDR
value|0x40a
end_define

begin_define
define|#
directive|define
name|MSR_MC2_MISC
value|0x40b
end_define

begin_define
define|#
directive|define
name|MSR_MC3_CTL
value|0x40c
end_define

begin_define
define|#
directive|define
name|MSR_MC3_STATUS
value|0x40d
end_define

begin_define
define|#
directive|define
name|MSR_MC3_ADDR
value|0x40e
end_define

begin_define
define|#
directive|define
name|MSR_MC3_MISC
value|0x40f
end_define

begin_define
define|#
directive|define
name|MSR_MC4_CTL
value|0x410
end_define

begin_define
define|#
directive|define
name|MSR_MC4_STATUS
value|0x411
end_define

begin_define
define|#
directive|define
name|MSR_MC4_ADDR
value|0x412
end_define

begin_define
define|#
directive|define
name|MSR_MC4_MISC
value|0x413
end_define

begin_comment
comment|/*  * Constants related to MSR's.  */
end_comment

begin_define
define|#
directive|define
name|APICBASE_RESERVED
value|0x000006ff
end_define

begin_define
define|#
directive|define
name|APICBASE_BSP
value|0x00000100
end_define

begin_define
define|#
directive|define
name|APICBASE_ENABLED
value|0x00000800
end_define

begin_define
define|#
directive|define
name|APICBASE_ADDRESS
value|0xfffff000
end_define

begin_comment
comment|/*  * PAT modes.  */
end_comment

begin_define
define|#
directive|define
name|PAT_UNCACHEABLE
value|0x00
end_define

begin_define
define|#
directive|define
name|PAT_WRITE_COMBINING
value|0x01
end_define

begin_define
define|#
directive|define
name|PAT_WRITE_THROUGH
value|0x04
end_define

begin_define
define|#
directive|define
name|PAT_WRITE_PROTECTED
value|0x05
end_define

begin_define
define|#
directive|define
name|PAT_WRITE_BACK
value|0x06
end_define

begin_define
define|#
directive|define
name|PAT_UNCACHED
value|0x07
end_define

begin_define
define|#
directive|define
name|PAT_VALUE
parameter_list|(
name|i
parameter_list|,
name|m
parameter_list|)
value|((long)(m)<< (8 * (i)))
end_define

begin_define
define|#
directive|define
name|PAT_MASK
parameter_list|(
name|i
parameter_list|)
value|PAT_VALUE(i, 0xff)
end_define

begin_comment
comment|/*  * Constants related to MTRRs  */
end_comment

begin_define
define|#
directive|define
name|MTRR_N64K
value|8
end_define

begin_comment
comment|/* numbers of fixed-size entries */
end_comment

begin_define
define|#
directive|define
name|MTRR_N16K
value|16
end_define

begin_define
define|#
directive|define
name|MTRR_N4K
value|64
end_define

begin_comment
comment|/* Performance Control Register (5x86 only). */
end_comment

begin_define
define|#
directive|define
name|PCR0
value|0x20
end_define

begin_define
define|#
directive|define
name|PCR0_RSTK
value|0x01
end_define

begin_comment
comment|/* Enables return stack */
end_comment

begin_define
define|#
directive|define
name|PCR0_BTB
value|0x02
end_define

begin_comment
comment|/* Enables branch target buffer */
end_comment

begin_define
define|#
directive|define
name|PCR0_LOOP
value|0x04
end_define

begin_comment
comment|/* Enables loop */
end_comment

begin_define
define|#
directive|define
name|PCR0_AIS
value|0x08
end_define

begin_comment
comment|/* Enables all instrcutions stalled to 								   serialize pipe. */
end_comment

begin_define
define|#
directive|define
name|PCR0_MLR
value|0x10
end_define

begin_comment
comment|/* Enables reordering of misaligned loads */
end_comment

begin_define
define|#
directive|define
name|PCR0_BTBRT
value|0x40
end_define

begin_comment
comment|/* Enables BTB test register. */
end_comment

begin_define
define|#
directive|define
name|PCR0_LSSER
value|0x80
end_define

begin_comment
comment|/* Disable reorder */
end_comment

begin_comment
comment|/* Device Identification Registers */
end_comment

begin_define
define|#
directive|define
name|DIR0
value|0xfe
end_define

begin_define
define|#
directive|define
name|DIR1
value|0xff
end_define

begin_comment
comment|/*  * The following four 3-byte registers control the non-cacheable regions.  * These registers must be written as three separate bytes.  *  * NCRx+0: A31-A24 of starting address  * NCRx+1: A23-A16 of starting address  * NCRx+2: A15-A12 of starting address | NCR_SIZE_xx.  *  * The non-cacheable region's starting address must be aligned to the  * size indicated by the NCR_SIZE_xx field.  */
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

begin_comment
comment|/*  * The address region registers are used to specify the location and  * size for the eight address regions.  *  * ARRx + 0: A31-A24 of start address  * ARRx + 1: A23-A16 of start address  * ARRx + 2: A15-A12 of start address | ARR_SIZE_xx  */
end_comment

begin_define
define|#
directive|define
name|ARR0
value|0xc4
end_define

begin_define
define|#
directive|define
name|ARR1
value|0xc7
end_define

begin_define
define|#
directive|define
name|ARR2
value|0xca
end_define

begin_define
define|#
directive|define
name|ARR3
value|0xcd
end_define

begin_define
define|#
directive|define
name|ARR4
value|0xd0
end_define

begin_define
define|#
directive|define
name|ARR5
value|0xd3
end_define

begin_define
define|#
directive|define
name|ARR6
value|0xd6
end_define

begin_define
define|#
directive|define
name|ARR7
value|0xd9
end_define

begin_define
define|#
directive|define
name|ARR_SIZE_0K
value|0
end_define

begin_define
define|#
directive|define
name|ARR_SIZE_4K
value|1
end_define

begin_define
define|#
directive|define
name|ARR_SIZE_8K
value|2
end_define

begin_define
define|#
directive|define
name|ARR_SIZE_16K
value|3
end_define

begin_define
define|#
directive|define
name|ARR_SIZE_32K
value|4
end_define

begin_define
define|#
directive|define
name|ARR_SIZE_64K
value|5
end_define

begin_define
define|#
directive|define
name|ARR_SIZE_128K
value|6
end_define

begin_define
define|#
directive|define
name|ARR_SIZE_256K
value|7
end_define

begin_define
define|#
directive|define
name|ARR_SIZE_512K
value|8
end_define

begin_define
define|#
directive|define
name|ARR_SIZE_1M
value|9
end_define

begin_define
define|#
directive|define
name|ARR_SIZE_2M
value|10
end_define

begin_define
define|#
directive|define
name|ARR_SIZE_4M
value|11
end_define

begin_define
define|#
directive|define
name|ARR_SIZE_8M
value|12
end_define

begin_define
define|#
directive|define
name|ARR_SIZE_16M
value|13
end_define

begin_define
define|#
directive|define
name|ARR_SIZE_32M
value|14
end_define

begin_define
define|#
directive|define
name|ARR_SIZE_4G
value|15
end_define

begin_comment
comment|/*  * The region control registers specify the attributes associated with  * the ARRx addres regions.  */
end_comment

begin_define
define|#
directive|define
name|RCR0
value|0xdc
end_define

begin_define
define|#
directive|define
name|RCR1
value|0xdd
end_define

begin_define
define|#
directive|define
name|RCR2
value|0xde
end_define

begin_define
define|#
directive|define
name|RCR3
value|0xdf
end_define

begin_define
define|#
directive|define
name|RCR4
value|0xe0
end_define

begin_define
define|#
directive|define
name|RCR5
value|0xe1
end_define

begin_define
define|#
directive|define
name|RCR6
value|0xe2
end_define

begin_define
define|#
directive|define
name|RCR7
value|0xe3
end_define

begin_define
define|#
directive|define
name|RCR_RCD
value|0x01
end_define

begin_comment
comment|/* Disables caching for ARRx (x = 0-6). */
end_comment

begin_define
define|#
directive|define
name|RCR_RCE
value|0x01
end_define

begin_comment
comment|/* Enables caching for ARR7. */
end_comment

begin_define
define|#
directive|define
name|RCR_WWO
value|0x02
end_define

begin_comment
comment|/* Weak write ordering. */
end_comment

begin_define
define|#
directive|define
name|RCR_WL
value|0x04
end_define

begin_comment
comment|/* Weak locking. */
end_comment

begin_define
define|#
directive|define
name|RCR_WG
value|0x08
end_define

begin_comment
comment|/* Write gathering. */
end_comment

begin_define
define|#
directive|define
name|RCR_WT
value|0x10
end_define

begin_comment
comment|/* Write-through. */
end_comment

begin_define
define|#
directive|define
name|RCR_NLB
value|0x20
end_define

begin_comment
comment|/* LBA# pin is not asserted. */
end_comment

begin_comment
comment|/* AMD Write Allocate Top-Of-Memory and Control Register */
end_comment

begin_define
define|#
directive|define
name|AMD_WT_ALLOC_TME
value|0x40000
end_define

begin_comment
comment|/* top-of-memory enable */
end_comment

begin_define
define|#
directive|define
name|AMD_WT_ALLOC_PRE
value|0x20000
end_define

begin_comment
comment|/* programmable range enable */
end_comment

begin_define
define|#
directive|define
name|AMD_WT_ALLOC_FRE
value|0x10000
end_define

begin_comment
comment|/* fixed (A0000-FFFFF) range enable */
end_comment

begin_comment
comment|/* AMD64 MSR's */
end_comment

begin_define
define|#
directive|define
name|MSR_EFER
value|0xc0000080
end_define

begin_comment
comment|/* extended features */
end_comment

begin_define
define|#
directive|define
name|MSR_STAR
value|0xc0000081
end_define

begin_comment
comment|/* legacy mode SYSCALL target/cs/ss */
end_comment

begin_define
define|#
directive|define
name|MSR_LSTAR
value|0xc0000082
end_define

begin_comment
comment|/* long mode SYSCALL target rip */
end_comment

begin_define
define|#
directive|define
name|MSR_CSTAR
value|0xc0000083
end_define

begin_comment
comment|/* compat mode SYSCALL target rip */
end_comment

begin_define
define|#
directive|define
name|MSR_SF_MASK
value|0xc0000084
end_define

begin_comment
comment|/* syscall flags mask */
end_comment

begin_define
define|#
directive|define
name|MSR_FSBASE
value|0xc0000100
end_define

begin_comment
comment|/* base address of the %fs "segment" */
end_comment

begin_define
define|#
directive|define
name|MSR_GSBASE
value|0xc0000101
end_define

begin_comment
comment|/* base address of the %gs "segment" */
end_comment

begin_define
define|#
directive|define
name|MSR_KGSBASE
value|0xc0000102
end_define

begin_comment
comment|/* base address of the kernel %gs */
end_comment

begin_define
define|#
directive|define
name|MSR_PERFEVSEL0
value|0xc0010000
end_define

begin_define
define|#
directive|define
name|MSR_PERFEVSEL1
value|0xc0010001
end_define

begin_define
define|#
directive|define
name|MSR_PERFEVSEL2
value|0xc0010002
end_define

begin_define
define|#
directive|define
name|MSR_PERFEVSEL3
value|0xc0010003
end_define

begin_undef
undef|#
directive|undef
name|MSR_PERFCTR0
end_undef

begin_undef
undef|#
directive|undef
name|MSR_PERFCTR1
end_undef

begin_define
define|#
directive|define
name|MSR_PERFCTR0
value|0xc0010004
end_define

begin_define
define|#
directive|define
name|MSR_PERFCTR1
value|0xc0010005
end_define

begin_define
define|#
directive|define
name|MSR_PERFCTR2
value|0xc0010006
end_define

begin_define
define|#
directive|define
name|MSR_PERFCTR3
value|0xc0010007
end_define

begin_define
define|#
directive|define
name|MSR_SYSCFG
value|0xc0010010
end_define

begin_define
define|#
directive|define
name|MSR_IORRBASE0
value|0xc0010016
end_define

begin_define
define|#
directive|define
name|MSR_IORRMASK0
value|0xc0010017
end_define

begin_define
define|#
directive|define
name|MSR_IORRBASE1
value|0xc0010018
end_define

begin_define
define|#
directive|define
name|MSR_IORRMASK1
value|0xc0010019
end_define

begin_define
define|#
directive|define
name|MSR_TOP_MEM
value|0xc001001a
end_define

begin_comment
comment|/* boundary for ram below 4G */
end_comment

begin_define
define|#
directive|define
name|MSR_TOP_MEM2
value|0xc001001d
end_define

begin_comment
comment|/* boundary for ram above 4G */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_SPECIALREG_H_ */
end_comment

end_unit

