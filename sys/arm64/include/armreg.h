begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013, 2014 Andrew Turner  * Copyright (c) 2015 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Andrew Turner under  * sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_ARMREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_ARMREG_H_
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
name|READ_SPECIALREG
parameter_list|(
name|reg
parameter_list|)
define|\
value|({	uint64_t val;							\ 	__asm __volatile("mrs	%0, " __STRING(reg) : "=&r" (val));	\ 	val;								\ })
end_define

begin_define
define|#
directive|define
name|WRITE_SPECIALREG
parameter_list|(
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|__asm __volatile("msr	" __STRING(reg) ", %0" : : "r"((uint64_t)val))
end_define

begin_comment
comment|/* CNTHCTL_EL2 - Counter-timer Hypervisor Control register */
end_comment

begin_define
define|#
directive|define
name|CNTHCTL_EVNTI_MASK
value|(0xf<< 4)
end_define

begin_comment
comment|/* Bit to trigger event stream */
end_comment

begin_define
define|#
directive|define
name|CNTHCTL_EVNTDIR
value|(1<< 3)
end_define

begin_comment
comment|/* Control transition trigger bit */
end_comment

begin_define
define|#
directive|define
name|CNTHCTL_EVNTEN
value|(1<< 2)
end_define

begin_comment
comment|/* Enable event stream */
end_comment

begin_define
define|#
directive|define
name|CNTHCTL_EL1PCEN
value|(1<< 1)
end_define

begin_comment
comment|/* Allow EL0/1 physical timer access */
end_comment

begin_define
define|#
directive|define
name|CNTHCTL_EL1PCTEN
value|(1<< 0)
end_define

begin_comment
comment|/*Allow EL0/1 physical counter access*/
end_comment

begin_comment
comment|/* CPACR_EL1 */
end_comment

begin_define
define|#
directive|define
name|CPACR_FPEN_MASK
value|(0x3<< 20)
end_define

begin_define
define|#
directive|define
name|CPACR_FPEN_TRAP_ALL1
value|(0x0<< 20)
end_define

begin_comment
comment|/* Traps from EL0 and EL1 */
end_comment

begin_define
define|#
directive|define
name|CPACR_FPEN_TRAP_EL0
value|(0x1<< 20)
end_define

begin_comment
comment|/* Traps from EL0 */
end_comment

begin_define
define|#
directive|define
name|CPACR_FPEN_TRAP_ALL2
value|(0x2<< 20)
end_define

begin_comment
comment|/* Traps from EL0 and EL1 */
end_comment

begin_define
define|#
directive|define
name|CPACR_FPEN_TRAP_NONE
value|(0x3<< 20)
end_define

begin_comment
comment|/* No traps */
end_comment

begin_define
define|#
directive|define
name|CPACR_TTA
value|(0x1<< 28)
end_define

begin_comment
comment|/* CTR_EL0 - Cache Type Register */
end_comment

begin_define
define|#
directive|define
name|CTR_DLINE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|CTR_DLINE_MASK
value|(0xf<< CTR_DLINE_SHIFT)
end_define

begin_define
define|#
directive|define
name|CTR_DLINE_SIZE
parameter_list|(
name|reg
parameter_list|)
value|(((reg)& CTR_DLINE_MASK)>> CTR_DLINE_SHIFT)
end_define

begin_define
define|#
directive|define
name|CTR_ILINE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|CTR_ILINE_MASK
value|(0xf<< CTR_ILINE_SHIFT)
end_define

begin_define
define|#
directive|define
name|CTR_ILINE_SIZE
parameter_list|(
name|reg
parameter_list|)
value|(((reg)& CTR_ILINE_MASK)>> CTR_ILINE_SHIFT)
end_define

begin_comment
comment|/* DCZID_EL0 - Data Cache Zero ID register */
end_comment

begin_define
define|#
directive|define
name|DCZID_DZP
value|(1<< 4)
end_define

begin_comment
comment|/* DC ZVA prohibited if non-0 */
end_comment

begin_define
define|#
directive|define
name|DCZID_BS_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|DCZID_BS_MASK
value|(0xf<< DCZID_BS_SHIFT)
end_define

begin_define
define|#
directive|define
name|DCZID_BS_SIZE
parameter_list|(
name|reg
parameter_list|)
value|(((reg)& DCZID_BS_MASK)>> DCZID_BS_SHIFT)
end_define

begin_comment
comment|/* ESR_ELx */
end_comment

begin_define
define|#
directive|define
name|ESR_ELx_ISS_MASK
value|0x00ffffff
end_define

begin_define
define|#
directive|define
name|ISS_INSN_FnV
value|(0x01<< 10)
end_define

begin_define
define|#
directive|define
name|ISS_INSN_EA
value|(0x01<< 9)
end_define

begin_define
define|#
directive|define
name|ISS_INSN_S1PTW
value|(0x01<< 7)
end_define

begin_define
define|#
directive|define
name|ISS_INSN_IFSC_MASK
value|(0x1f<< 0)
end_define

begin_define
define|#
directive|define
name|ISS_DATA_ISV
value|(0x01<< 24)
end_define

begin_define
define|#
directive|define
name|ISS_DATA_SAS_MASK
value|(0x03<< 22)
end_define

begin_define
define|#
directive|define
name|ISS_DATA_SSE
value|(0x01<< 21)
end_define

begin_define
define|#
directive|define
name|ISS_DATA_SRT_MASK
value|(0x1f<< 16)
end_define

begin_define
define|#
directive|define
name|ISS_DATA_SF
value|(0x01<< 15)
end_define

begin_define
define|#
directive|define
name|ISS_DATA_AR
value|(0x01<< 14)
end_define

begin_define
define|#
directive|define
name|ISS_DATA_FnV
value|(0x01<< 10)
end_define

begin_define
define|#
directive|define
name|ISS_DATa_EA
value|(0x01<< 9)
end_define

begin_define
define|#
directive|define
name|ISS_DATa_CM
value|(0x01<< 8)
end_define

begin_define
define|#
directive|define
name|ISS_INSN_S1PTW
value|(0x01<< 7)
end_define

begin_define
define|#
directive|define
name|ISS_DATa_WnR
value|(0x01<< 6)
end_define

begin_define
define|#
directive|define
name|ISS_DATA_DFSC_MASK
value|(0x1f<< 0)
end_define

begin_define
define|#
directive|define
name|ISS_DATA_DFSC_ASF_L0
value|(0x00<< 0)
end_define

begin_define
define|#
directive|define
name|ISS_DATA_DFSC_ASF_L1
value|(0x01<< 0)
end_define

begin_define
define|#
directive|define
name|ISS_DATA_DFSC_ASF_L2
value|(0x02<< 0)
end_define

begin_define
define|#
directive|define
name|ISS_DATA_DFSC_ASF_L3
value|(0x03<< 0)
end_define

begin_define
define|#
directive|define
name|ISS_DATA_DFSC_TF_L0
value|(0x04<< 0)
end_define

begin_define
define|#
directive|define
name|ISS_DATA_DFSC_TF_L1
value|(0x05<< 0)
end_define

begin_define
define|#
directive|define
name|ISS_DATA_DFSC_TF_L2
value|(0x06<< 0)
end_define

begin_define
define|#
directive|define
name|ISS_DATA_DFSC_TF_L3
value|(0x07<< 0)
end_define

begin_define
define|#
directive|define
name|ISS_DATA_DFSC_AFF_L1
value|(0x09<< 0)
end_define

begin_define
define|#
directive|define
name|ISS_DATA_DFSC_AFF_L2
value|(0x0a<< 0)
end_define

begin_define
define|#
directive|define
name|ISS_DATA_DFSC_AFF_L3
value|(0x0b<< 0)
end_define

begin_define
define|#
directive|define
name|ISS_DATA_DFSC_PF_L1
value|(0x0d<< 0)
end_define

begin_define
define|#
directive|define
name|ISS_DATA_DFSC_PF_L2
value|(0x0e<< 0)
end_define

begin_define
define|#
directive|define
name|ISS_DATA_DFSC_PF_L3
value|(0x0f<< 0)
end_define

begin_define
define|#
directive|define
name|ISS_DATA_DFSC_EXT
value|(0x10<< 0)
end_define

begin_define
define|#
directive|define
name|ISS_DATA_DFSC_EXT_L0
value|(0x14<< 0)
end_define

begin_define
define|#
directive|define
name|ISS_DATA_DFSC_EXT_L1
value|(0x15<< 0)
end_define

begin_define
define|#
directive|define
name|ISS_DATA_DFSC_EXT_L2
value|(0x16<< 0)
end_define

begin_define
define|#
directive|define
name|ISS_DATA_DFSC_EXT_L3
value|(0x17<< 0)
end_define

begin_define
define|#
directive|define
name|ISS_DATA_DFSC_ECC
value|(0x18<< 0)
end_define

begin_define
define|#
directive|define
name|ISS_DATA_DFSC_ECC_L0
value|(0x1c<< 0)
end_define

begin_define
define|#
directive|define
name|ISS_DATA_DFSC_ECC_L1
value|(0x1d<< 0)
end_define

begin_define
define|#
directive|define
name|ISS_DATA_DFSC_ECC_L2
value|(0x1e<< 0)
end_define

begin_define
define|#
directive|define
name|ISS_DATA_DFSC_ECC_L3
value|(0x1f<< 0)
end_define

begin_define
define|#
directive|define
name|ISS_DATA_DFSC_ALIGN
value|(0x21<< 0)
end_define

begin_define
define|#
directive|define
name|ISS_DATA_DFSC_TLB_CONFLICT
value|(0x28<< 0)
end_define

begin_define
define|#
directive|define
name|ESR_ELx_IL
value|(0x01<< 25)
end_define

begin_define
define|#
directive|define
name|ESR_ELx_EC_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|ESR_ELx_EC_MASK
value|(0x3f<< 26)
end_define

begin_define
define|#
directive|define
name|ESR_ELx_EXCEPTION
parameter_list|(
name|esr
parameter_list|)
value|(((esr)& ESR_ELx_EC_MASK)>> ESR_ELx_EC_SHIFT)
end_define

begin_define
define|#
directive|define
name|EXCP_UNKNOWN
value|0x00
end_define

begin_comment
comment|/* Unkwn exception */
end_comment

begin_define
define|#
directive|define
name|EXCP_FP_SIMD
value|0x07
end_define

begin_comment
comment|/* VFP/SIMD trap */
end_comment

begin_define
define|#
directive|define
name|EXCP_ILL_STATE
value|0x0e
end_define

begin_comment
comment|/* Illegal execution state */
end_comment

begin_define
define|#
directive|define
name|EXCP_SVC
value|0x15
end_define

begin_comment
comment|/* SVC trap */
end_comment

begin_define
define|#
directive|define
name|EXCP_MSR
value|0x18
end_define

begin_comment
comment|/* MSR/MRS trap */
end_comment

begin_define
define|#
directive|define
name|EXCP_INSN_ABORT_L
value|0x20
end_define

begin_comment
comment|/* Instruction abort, from lower EL */
end_comment

begin_define
define|#
directive|define
name|EXCP_INSN_ABORT
value|0x21
end_define

begin_comment
comment|/* Instruction abort, from same EL */
end_comment

begin_define
define|#
directive|define
name|EXCP_PC_ALIGN
value|0x22
end_define

begin_comment
comment|/* PC alignment fault */
end_comment

begin_define
define|#
directive|define
name|EXCP_DATA_ABORT_L
value|0x24
end_define

begin_comment
comment|/* Data abort, from lower EL */
end_comment

begin_define
define|#
directive|define
name|EXCP_DATA_ABORT
value|0x25
end_define

begin_comment
comment|/* Data abort, from same EL */
end_comment

begin_define
define|#
directive|define
name|EXCP_SP_ALIGN
value|0x26
end_define

begin_comment
comment|/* SP slignment fault */
end_comment

begin_define
define|#
directive|define
name|EXCP_TRAP_FP
value|0x2c
end_define

begin_comment
comment|/* Trapped FP exception */
end_comment

begin_define
define|#
directive|define
name|EXCP_SERROR
value|0x2f
end_define

begin_comment
comment|/* SError interrupt */
end_comment

begin_define
define|#
directive|define
name|EXCP_SOFTSTP_EL0
value|0x32
end_define

begin_comment
comment|/* Software Step, from lower EL */
end_comment

begin_define
define|#
directive|define
name|EXCP_SOFTSTP_EL1
value|0x33
end_define

begin_comment
comment|/* Software Step, from same EL */
end_comment

begin_define
define|#
directive|define
name|EXCP_WATCHPT_EL1
value|0x35
end_define

begin_comment
comment|/* Watchpoint, from same EL */
end_comment

begin_define
define|#
directive|define
name|EXCP_BRK
value|0x3c
end_define

begin_comment
comment|/* Breakpoint */
end_comment

begin_comment
comment|/* ICC_CTLR_EL1 */
end_comment

begin_define
define|#
directive|define
name|ICC_CTLR_EL1_EOIMODE
value|(1U<< 1)
end_define

begin_comment
comment|/* ICC_IAR1_EL1 */
end_comment

begin_define
define|#
directive|define
name|ICC_IAR1_EL1_SPUR
value|(0x03ff)
end_define

begin_comment
comment|/* ICC_IGRPEN0_EL1 */
end_comment

begin_define
define|#
directive|define
name|ICC_IGRPEN0_EL1_EN
value|(1U<< 0)
end_define

begin_comment
comment|/* ICC_PMR_EL1 */
end_comment

begin_define
define|#
directive|define
name|ICC_PMR_EL1_PRIO_MASK
value|(0xFFUL)
end_define

begin_comment
comment|/* ICC_SGI1R_EL1 */
end_comment

begin_define
define|#
directive|define
name|ICC_SGI1R_EL1_TL_MASK
value|0xffffUL
end_define

begin_define
define|#
directive|define
name|ICC_SGI1R_EL1_AFF1_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ICC_SGI1R_EL1_SGIID_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|ICC_SGI1R_EL1_AFF2_SHIFT
value|32
end_define

begin_define
define|#
directive|define
name|ICC_SGI1R_EL1_AFF3_SHIFT
value|48
end_define

begin_define
define|#
directive|define
name|ICC_SGI1R_EL1_SGIID_MASK
value|0xfUL
end_define

begin_define
define|#
directive|define
name|ICC_SGI1R_EL1_IRM
value|(0x1UL<< 40)
end_define

begin_comment
comment|/* ICC_SRE_EL1 */
end_comment

begin_define
define|#
directive|define
name|ICC_SRE_EL1_SRE
value|(1U<< 0)
end_define

begin_comment
comment|/* ICC_SRE_EL2 */
end_comment

begin_define
define|#
directive|define
name|ICC_SRE_EL2_SRE
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|ICC_SRE_EL2_EN
value|(1U<< 3)
end_define

begin_comment
comment|/* ID_AA64DFR0_EL1 */
end_comment

begin_define
define|#
directive|define
name|ID_AA64DFR0_MASK
value|0xf0f0ffff
end_define

begin_define
define|#
directive|define
name|ID_AA64DFR0_DEBUG_VER_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|ID_AA64DFR0_DEBUG_VER_MASK
value|(0xf<< ID_AA64DFR0_DEBUG_VER_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64DFR0_DEBUG_VER
parameter_list|(
name|x
parameter_list|)
value|((x)& ID_AA64DFR0_DEBUG_VER_MASK)
end_define

begin_define
define|#
directive|define
name|ID_AA64DFR0_DEBUG_VER_8
value|(0x6<< ID_AA64DFR0_DEBUG_VER_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64DFR0_DEBUG_VER_8_VHE
value|(0x7<< ID_AA64DFR0_DEBUG_VER_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64DFR0_TRACE_VER_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|ID_AA64DFR0_TRACE_VER_MASK
value|(0xf<< ID_AA64DFR0_TRACE_VER_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64DFR0_TRACE_VER
parameter_list|(
name|x
parameter_list|)
value|((x)& ID_AA64DFR0_TRACE_VER_MASK)
end_define

begin_define
define|#
directive|define
name|ID_AA64DFR0_TRACE_VER_NONE
value|(0x0<< ID_AA64DFR0_TRACE_VER_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64DFR0_TRACE_VER_IMPL
value|(0x1<< ID_AA64DFR0_TRACE_VER_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64DFR0_PMU_VER_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|ID_AA64DFR0_PMU_VER_MASK
value|(0xf<< ID_AA64DFR0_PMU_VER_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64DFR0_PMU_VER
parameter_list|(
name|x
parameter_list|)
value|((x)& ID_AA64DFR0_PMU_VER_MASK)
end_define

begin_define
define|#
directive|define
name|ID_AA64DFR0_PMU_VER_NONE
value|(0x0<< ID_AA64DFR0_PMU_VER_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64DFR0_PMU_VER_3
value|(0x1<< ID_AA64DFR0_PMU_VER_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64DFR0_PMU_VER_3_1
value|(0x4<< ID_AA64DFR0_PMU_VER_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64DFR0_PMU_VER_IMPL
value|(0xf<< ID_AA64DFR0_PMU_VER_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64DFR0_BRPS_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|ID_AA64DFR0_BRPS_MASK
value|(0xf<< ID_AA64DFR0_BRPS_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64DFR0_BRPS
parameter_list|(
name|x
parameter_list|)
define|\
value|((((x)>> ID_AA64DFR0_BRPS_SHIFT)& 0xf) + 1)
end_define

begin_define
define|#
directive|define
name|ID_AA64DFR0_WRPS_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|ID_AA64DFR0_WRPS_MASK
value|(0xf<< ID_AA64DFR0_WRPS_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64DFR0_WRPS
parameter_list|(
name|x
parameter_list|)
define|\
value|((((x)>> ID_AA64DFR0_WRPS_SHIFT)& 0xf) + 1)
end_define

begin_define
define|#
directive|define
name|ID_AA64DFR0_CTX_CMPS_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|ID_AA64DFR0_CTX_CMPS_MASK
value|(0xf<< ID_AA64DFR0_CTX_CMPS_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64DFR0_CTX_CMPS
parameter_list|(
name|x
parameter_list|)
define|\
value|((((x)>> ID_AA64DFR0_CTX_CMPS_SHIFT)& 0xf) + 1)
end_define

begin_comment
comment|/* ID_AA64ISAR0_EL1 */
end_comment

begin_define
define|#
directive|define
name|ID_AA64ISAR0_MASK
value|0xf0fffff0
end_define

begin_define
define|#
directive|define
name|ID_AA64ISAR0_AES_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|ID_AA64ISAR0_AES_MASK
value|(0xf<< ID_AA64ISAR0_AES_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64ISAR0_AES
parameter_list|(
name|x
parameter_list|)
value|((x)& ID_AA64ISAR0_AES_MASK)
end_define

begin_define
define|#
directive|define
name|ID_AA64ISAR0_AES_NONE
value|(0x0<< ID_AA64ISAR0_AES_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64ISAR0_AES_BASE
value|(0x1<< ID_AA64ISAR0_AES_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64ISAR0_AES_PMULL
value|(0x2<< ID_AA64ISAR0_AES_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64ISAR0_SHA1_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|ID_AA64ISAR0_SHA1_MASK
value|(0xf<< ID_AA64ISAR0_SHA1_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64ISAR0_SHA1
parameter_list|(
name|x
parameter_list|)
value|((x)& ID_AA64ISAR0_SHA1_MASK)
end_define

begin_define
define|#
directive|define
name|ID_AA64ISAR0_SHA1_NONE
value|(0x0<< ID_AA64ISAR0_SHA1_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64ISAR0_SHA1_BASE
value|(0x1<< ID_AA64ISAR0_SHA1_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64ISAR0_SHA2_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|ID_AA64ISAR0_SHA2_MASK
value|(0xf<< ID_AA64ISAR0_SHA2_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64ISAR0_SHA2
parameter_list|(
name|x
parameter_list|)
value|((x)& ID_AA64ISAR0_SHA2_MASK)
end_define

begin_define
define|#
directive|define
name|ID_AA64ISAR0_SHA2_NONE
value|(0x0<< ID_AA64ISAR0_SHA2_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64ISAR0_SHA2_BASE
value|(0x1<< ID_AA64ISAR0_SHA2_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64ISAR0_CRC32_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ID_AA64ISAR0_CRC32_MASK
value|(0xf<< ID_AA64ISAR0_CRC32_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64ISAR0_CRC32
parameter_list|(
name|x
parameter_list|)
value|((x)& ID_AA64ISAR0_CRC32_MASK)
end_define

begin_define
define|#
directive|define
name|ID_AA64ISAR0_CRC32_NONE
value|(0x0<< ID_AA64ISAR0_CRC32_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64ISAR0_CRC32_BASE
value|(0x1<< ID_AA64ISAR0_CRC32_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64ISAR0_ATOMIC_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|ID_AA64ISAR0_ATOMIC_MASK
value|(0xf<< ID_AA64ISAR0_ATOMIC_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64ISAR0_ATOMIC
parameter_list|(
name|x
parameter_list|)
value|((x)& ID_AA64ISAR0_ATOMIC_MASK)
end_define

begin_define
define|#
directive|define
name|ID_AA64ISAR0_ATOMIC_NONE
value|(0x0<< ID_AA64ISAR0_ATOMIC_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64ISAR0_ATOMIC_IMPL
value|(0x2<< ID_AA64ISAR0_ATOMIC_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64ISAR0_RDM_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|ID_AA64ISAR0_RDM_MASK
value|(0xf<< ID_AA64ISAR0_RDM_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64ISAR0_RDM
parameter_list|(
name|x
parameter_list|)
value|((x)& ID_AA64ISAR0_RDM_MASK)
end_define

begin_define
define|#
directive|define
name|ID_AA64ISAR0_RDM_NONE
value|(0x0<< ID_AA64ISAR0_RDM_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64ISAR0_RDM_IMPL
value|(0x1<< ID_AA64ISAR0_RDM_SHIFT)
end_define

begin_comment
comment|/* ID_AA64MMFR0_EL1 */
end_comment

begin_define
define|#
directive|define
name|ID_AA64MMFR0_MASK
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_PA_RANGE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_PA_RANGE_MASK
value|(0xf<< ID_AA64MMFR0_PA_RANGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_PA_RANGE
parameter_list|(
name|x
parameter_list|)
value|((x)& ID_AA64MMFR0_PA_RANGE_MASK)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_PA_RANGE_4G
value|(0x0<< ID_AA64MMFR0_PA_RANGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_PA_RANGE_64G
value|(0x1<< ID_AA64MMFR0_PA_RANGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_PA_RANGE_1T
value|(0x2<< ID_AA64MMFR0_PA_RANGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_PA_RANGE_4T
value|(0x3<< ID_AA64MMFR0_PA_RANGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_PA_RANGE_16T
value|(0x4<< ID_AA64MMFR0_PA_RANGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_PA_RANGE_256T
value|(0x5<< ID_AA64MMFR0_PA_RANGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_ASID_BITS_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_ASID_BITS_MASK
value|(0xf<< ID_AA64MMFR0_ASID_BITS_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_ASID_BITS
parameter_list|(
name|x
parameter_list|)
value|((x)& ID_AA64MMFR0_ASID_BITS_MASK)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_ASID_BITS_8
value|(0x0<< ID_AA64MMFR0_ASID_BITS_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_ASID_BITS_16
value|(0x2<< ID_AA64MMFR0_ASID_BITS_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_BIGEND_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_BIGEND_MASK
value|(0xf<< ID_AA64MMFR0_BIGEND_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_BIGEND
parameter_list|(
name|x
parameter_list|)
value|((x)& ID_AA64MMFR0_BIGEND_MASK)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_BIGEND_FIXED
value|(0x0<< ID_AA64MMFR0_BIGEND_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_BIGEND_MIXED
value|(0x1<< ID_AA64MMFR0_BIGEND_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_S_NS_MEM_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_S_NS_MEM_MASK
value|(0xf<< ID_AA64MMFR0_S_NS_MEM_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_S_NS_MEM
parameter_list|(
name|x
parameter_list|)
value|((x)& ID_AA64MMFR0_S_NS_MEM_MASK)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_S_NS_MEM_NONE
value|(0x0<< ID_AA64MMFR0_S_NS_MEM_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_S_NS_MEM_DISTINCT
value|(0x1<< ID_AA64MMFR0_S_NS_MEM_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_BIGEND_EL0_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_BIGEND_EL0_MASK
value|(0xf<< ID_AA64MMFR0_BIGEND_EL0_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_BIGEND_EL0
parameter_list|(
name|x
parameter_list|)
value|((x)& ID_AA64MMFR0_BIGEND_EL0_MASK)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_BIGEND_EL0_FIXED
value|(0x0<< ID_AA64MMFR0_BIGEND_EL0_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_BIGEND_EL0_MIXED
value|(0x1<< ID_AA64MMFR0_BIGEND_EL0_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_TGRAN16_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_TGRAN16_MASK
value|(0xf<< ID_AA64MMFR0_TGRAN16_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_TGRAN16
parameter_list|(
name|x
parameter_list|)
value|((x)& ID_AA64MMFR0_TGRAN16_MASK)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_TGRAN16_NONE
value|(0x0<< ID_AA64MMFR0_TGRAN16_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_TGRAN16_IMPL
value|(0x1<< ID_AA64MMFR0_TGRAN16_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_TGRAN64_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_TGRAN64_MASK
value|(0xf<< ID_AA64MMFR0_TGRAN64_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_TGRAN64
parameter_list|(
name|x
parameter_list|)
value|((x)& ID_AA64MMFR0_TGRAN64_MASK)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_TGRAN64_IMPL
value|(0x0<< ID_AA64MMFR0_TGRAN64_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_TGRAN64_NONE
value|(0xf<< ID_AA64MMFR0_TGRAN64_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_TGRAN4_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_TGRAN4_MASK
value|(0xf<< ID_AA64MMFR0_TGRAN4_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_TGRAN4
parameter_list|(
name|x
parameter_list|)
value|((x)& ID_AA64MMFR0_TGRAN4_MASK)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_TGRAN4_IMPL
value|(0x0<< ID_AA64MMFR0_TGRAN4_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR0_TGRAN4_NONE
value|(0xf<< ID_AA64MMFR0_TGRAN4_SHIFT)
end_define

begin_comment
comment|/* ID_AA64MMFR1_EL1 */
end_comment

begin_define
define|#
directive|define
name|ID_AA64MMFR1_MASK
value|0x00ffffff
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR1_HAFDBS_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR1_HAFDBS_MASK
value|(0xf<< ID_AA64MMFR1_HAFDBS_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR1_HAFDBS
parameter_list|(
name|x
parameter_list|)
value|((x)& ID_AA64MMFR1_HAFDBS_MASK)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR1_HAFDBS_NONE
value|(0x0<< ID_AA64MMFR1_HAFDBS_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR1_HAFDBS_AF
value|(0x1<< ID_AA64MMFR1_HAFDBS_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR1_HAFDBS_AF_DBS
value|(0x2<< ID_AA64MMFR1_HAFDBS_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR1_VMIDBITS_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR1_VMIDBITS_MASK
value|(0xf<< ID_AA64MMFR1_VMIDBITS_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR1_VMIDBITS
parameter_list|(
name|x
parameter_list|)
value|((x)& ID_AA64MMFR1_VMIDBITS_MASK)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR1_VMIDBITS_8
value|(0x0<< ID_AA64MMFR1_VMIDBITS_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR1_VMIDBITS_16
value|(0x2<< ID_AA64MMFR1_VMIDBITS_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR1_VH_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR1_VH_MASK
value|(0xf<< ID_AA64MMFR1_VH_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR1_VH
parameter_list|(
name|x
parameter_list|)
value|((x)& ID_AA64MMFR1_VH_MASK)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR1_VH_NONE
value|(0x0<< ID_AA64MMFR1_VH_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR1_VH_IMPL
value|(0x1<< ID_AA64MMFR1_VH_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR1_HPDS_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR1_HPDS_MASK
value|(0xf<< ID_AA64MMFR1_HPDS_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR1_HPDS
parameter_list|(
name|x
parameter_list|)
value|((x)& ID_AA64MMFR1_HPDS_MASK)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR1_HPDS_NONE
value|(0x0<< ID_AA64MMFR1_HPDS_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR1_HPDS_IMPL
value|(0x1<< ID_AA64MMFR1_HPDS_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR1_LO_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR1_LO_MASK
value|(0xf<< ID_AA64MMFR1_LO_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR1_LO
parameter_list|(
name|x
parameter_list|)
value|((x)& ID_AA64MMFR1_LO_MASK)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR1_LO_NONE
value|(0x0<< ID_AA64MMFR1_LO_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR1_LO_IMPL
value|(0x1<< ID_AA64MMFR1_LO_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR1_PAN_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR1_PAN_MASK
value|(0xf<< ID_AA64MMFR1_PAN_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR1_PAN
parameter_list|(
name|x
parameter_list|)
value|((x)& ID_AA64MMFR1_PAN_MASK)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR1_PAN_NONE
value|(0x0<< ID_AA64MMFR1_PAN_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR1_PAN_IMPL
value|(0x1<< ID_AA64MMFR1_PAN_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64MMFR1_PAN_ATS1E1
value|(0x2<< ID_AA64MMFR1_PAN_SHIFT)
end_define

begin_comment
comment|/* ID_AA64PFR0_EL1 */
end_comment

begin_define
define|#
directive|define
name|ID_AA64PFR0_MASK
value|0x0fffffff
end_define

begin_define
define|#
directive|define
name|ID_AA64PFR0_EL0_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|ID_AA64PFR0_EL0_MASK
value|(0xf<< ID_AA64PFR0_EL0_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64PFR0_EL0
parameter_list|(
name|x
parameter_list|)
value|((x)& ID_AA64PFR0_EL0_MASK)
end_define

begin_define
define|#
directive|define
name|ID_AA64PFR0_EL0_64
value|(1<< ID_AA64PFR0_EL0_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64PFR0_EL0_64_32
value|(2<< ID_AA64PFR0_EL0_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64PFR0_EL1_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|ID_AA64PFR0_EL1_MASK
value|(0xf<< ID_AA64PFR0_EL1_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64PFR0_EL1
parameter_list|(
name|x
parameter_list|)
value|((x)& ID_AA64PFR0_EL1_MASK)
end_define

begin_define
define|#
directive|define
name|ID_AA64PFR0_EL1_64
value|(1<< ID_AA64PFR0_EL1_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64PFR0_EL1_64_32
value|(2<< ID_AA64PFR0_EL1_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64PFR0_EL2_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|ID_AA64PFR0_EL2_MASK
value|(0xf<< ID_AA64PFR0_EL2_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64PFR0_EL2
parameter_list|(
name|x
parameter_list|)
value|((x)& ID_AA64PFR0_EL2_MASK)
end_define

begin_define
define|#
directive|define
name|ID_AA64PFR0_EL2_NONE
value|(0<< ID_AA64PFR0_EL2_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64PFR0_EL2_64
value|(1<< ID_AA64PFR0_EL2_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64PFR0_EL2_64_32
value|(2<< ID_AA64PFR0_EL2_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64PFR0_EL3_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|ID_AA64PFR0_EL3_MASK
value|(0xf<< ID_AA64PFR0_EL3_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64PFR0_EL3
parameter_list|(
name|x
parameter_list|)
value|((x)& ID_AA64PFR0_EL3_MASK)
end_define

begin_define
define|#
directive|define
name|ID_AA64PFR0_EL3_NONE
value|(0<< ID_AA64PFR0_EL3_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64PFR0_EL3_64
value|(1<< ID_AA64PFR0_EL3_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64PFR0_EL3_64_32
value|(2<< ID_AA64PFR0_EL3_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64PFR0_FP_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ID_AA64PFR0_FP_MASK
value|(0xf<< ID_AA64PFR0_FP_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64PFR0_FP
parameter_list|(
name|x
parameter_list|)
value|((x)& ID_AA64PFR0_FP_MASK)
end_define

begin_define
define|#
directive|define
name|ID_AA64PFR0_FP_IMPL
value|(0x0<< ID_AA64PFR0_FP_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64PFR0_FP_NONE
value|(0xf<< ID_AA64PFR0_FP_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64PFR0_ADV_SIMD_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|ID_AA64PFR0_ADV_SIMD_MASK
value|(0xf<< ID_AA64PFR0_ADV_SIMD_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64PFR0_ADV_SIMD
parameter_list|(
name|x
parameter_list|)
value|((x)& ID_AA64PFR0_ADV_SIMD_MASK)
end_define

begin_define
define|#
directive|define
name|ID_AA64PFR0_ADV_SIMD_IMPL
value|(0x0<< ID_AA64PFR0_ADV_SIMD_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64PFR0_ADV_SIMD_NONE
value|(0xf<< ID_AA64PFR0_ADV_SIMD_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64PFR0_GIC_BITS
value|0x4
end_define

begin_comment
comment|/* Number of bits in GIC field */
end_comment

begin_define
define|#
directive|define
name|ID_AA64PFR0_GIC_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|ID_AA64PFR0_GIC_MASK
value|(0xf<< ID_AA64PFR0_GIC_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64PFR0_GIC
parameter_list|(
name|x
parameter_list|)
value|((x)& ID_AA64PFR0_GIC_MASK)
end_define

begin_define
define|#
directive|define
name|ID_AA64PFR0_GIC_CPUIF_NONE
value|(0x0<< ID_AA64PFR0_GIC_SHIFT)
end_define

begin_define
define|#
directive|define
name|ID_AA64PFR0_GIC_CPUIF_EN
value|(0x1<< ID_AA64PFR0_GIC_SHIFT)
end_define

begin_comment
comment|/* MAIR_EL1 - Memory Attribute Indirection Register */
end_comment

begin_define
define|#
directive|define
name|MAIR_ATTR_MASK
parameter_list|(
name|idx
parameter_list|)
value|(0xff<< ((n)* 8))
end_define

begin_define
define|#
directive|define
name|MAIR_ATTR
parameter_list|(
name|attr
parameter_list|,
name|idx
parameter_list|)
value|((attr)<< ((idx) * 8))
end_define

begin_comment
comment|/* PAR_EL1 - Physical Address Register */
end_comment

begin_define
define|#
directive|define
name|PAR_F_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PAR_F
value|(0x1<< PAR_F_SHIFT)
end_define

begin_define
define|#
directive|define
name|PAR_SUCCESS
parameter_list|(
name|x
parameter_list|)
value|(((x)& PAR_F) == 0)
end_define

begin_comment
comment|/* When PAR_F == 0 (success) */
end_comment

begin_define
define|#
directive|define
name|PAR_SH_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|PAR_SH_MASK
value|(0x3<< PAR_SH_SHIFT)
end_define

begin_define
define|#
directive|define
name|PAR_NS_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|PAR_NS_MASK
value|(0x3<< PAR_NS_SHIFT)
end_define

begin_define
define|#
directive|define
name|PAR_PA_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|PAR_PA_MASK
value|0x0000fffffffff000
end_define

begin_define
define|#
directive|define
name|PAR_ATTR_SHIFT
value|56
end_define

begin_define
define|#
directive|define
name|PAR_ATTR_MASK
value|(0xff<< PAR_ATTR_SHIFT)
end_define

begin_comment
comment|/* When PAR_F == 1 (aborted) */
end_comment

begin_define
define|#
directive|define
name|PAR_FST_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|PAR_FST_MASK
value|(0x3f<< PAR_FST_SHIFT)
end_define

begin_define
define|#
directive|define
name|PAR_PTW_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|PAR_PTW_MASK
value|(0x1<< PAR_PTW_SHIFT)
end_define

begin_define
define|#
directive|define
name|PAR_S_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|PAR_S_MASK
value|(0x1<< PAR_S_SHIFT)
end_define

begin_comment
comment|/* SCTLR_EL1 - System Control Register */
end_comment

begin_define
define|#
directive|define
name|SCTLR_RES0
value|0xc8222400
end_define

begin_comment
comment|/* Reserved ARMv8.0, write 0 */
end_comment

begin_define
define|#
directive|define
name|SCTLR_RES1
value|0x30d00800
end_define

begin_comment
comment|/* Reserved ARMv8.0, write 1 */
end_comment

begin_define
define|#
directive|define
name|SCTLR_M
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SCTLR_A
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SCTLR_C
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SCTLR_SA
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SCTLR_SA0
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SCTLR_CP15BEN
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SCTLR_THEE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SCTLR_ITD
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SCTLR_SED
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SCTLR_UMA
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SCTLR_I
value|0x00001000
end_define

begin_define
define|#
directive|define
name|SCTLR_DZE
value|0x00004000
end_define

begin_define
define|#
directive|define
name|SCTLR_UCT
value|0x00008000
end_define

begin_define
define|#
directive|define
name|SCTLR_nTWI
value|0x00010000
end_define

begin_define
define|#
directive|define
name|SCTLR_nTWE
value|0x00040000
end_define

begin_define
define|#
directive|define
name|SCTLR_WXN
value|0x00080000
end_define

begin_define
define|#
directive|define
name|SCTLR_IESB
value|0x00200000
end_define

begin_define
define|#
directive|define
name|SCTLR_SPAN
value|0x00800000
end_define

begin_define
define|#
directive|define
name|SCTLR_EOE
value|0x01000000
end_define

begin_define
define|#
directive|define
name|SCTLR_EE
value|0x02000000
end_define

begin_define
define|#
directive|define
name|SCTLR_UCI
value|0x04000000
end_define

begin_define
define|#
directive|define
name|SCTLR_nTLSMD
value|0x10000000
end_define

begin_define
define|#
directive|define
name|SCTLR_LSMAOE
value|0x20000000
end_define

begin_comment
comment|/* SPSR_EL1 */
end_comment

begin_comment
comment|/*  * When the exception is taken in AArch64:  * M[4]   is 0 for AArch64 mode  * M[3:2] is the exception level  * M[1]   is unused  * M[0]   is the SP select:  *         0: always SP0  *         1: current ELs SP  */
end_comment

begin_define
define|#
directive|define
name|PSR_M_EL0t
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PSR_M_EL1t
value|0x00000004
end_define

begin_define
define|#
directive|define
name|PSR_M_EL1h
value|0x00000005
end_define

begin_define
define|#
directive|define
name|PSR_M_EL2t
value|0x00000008
end_define

begin_define
define|#
directive|define
name|PSR_M_EL2h
value|0x00000009
end_define

begin_define
define|#
directive|define
name|PSR_M_MASK
value|0x0000001f
end_define

begin_define
define|#
directive|define
name|PSR_F
value|0x00000040
end_define

begin_define
define|#
directive|define
name|PSR_I
value|0x00000080
end_define

begin_define
define|#
directive|define
name|PSR_A
value|0x00000100
end_define

begin_define
define|#
directive|define
name|PSR_D
value|0x00000200
end_define

begin_define
define|#
directive|define
name|PSR_IL
value|0x00100000
end_define

begin_define
define|#
directive|define
name|PSR_SS
value|0x00200000
end_define

begin_define
define|#
directive|define
name|PSR_V
value|0x10000000
end_define

begin_define
define|#
directive|define
name|PSR_C
value|0x20000000
end_define

begin_define
define|#
directive|define
name|PSR_Z
value|0x40000000
end_define

begin_define
define|#
directive|define
name|PSR_N
value|0x80000000
end_define

begin_comment
comment|/* TCR_EL1 - Translation Control Register */
end_comment

begin_define
define|#
directive|define
name|TCR_ASID_16
value|(1<< 36)
end_define

begin_define
define|#
directive|define
name|TCR_IPS_SHIFT
value|32
end_define

begin_define
define|#
directive|define
name|TCR_IPS_32BIT
value|(0<< TCR_IPS_SHIFT)
end_define

begin_define
define|#
directive|define
name|TCR_IPS_36BIT
value|(1<< TCR_IPS_SHIFT)
end_define

begin_define
define|#
directive|define
name|TCR_IPS_40BIT
value|(2<< TCR_IPS_SHIFT)
end_define

begin_define
define|#
directive|define
name|TCR_IPS_42BIT
value|(3<< TCR_IPS_SHIFT)
end_define

begin_define
define|#
directive|define
name|TCR_IPS_44BIT
value|(4<< TCR_IPS_SHIFT)
end_define

begin_define
define|#
directive|define
name|TCR_IPS_48BIT
value|(5<< TCR_IPS_SHIFT)
end_define

begin_define
define|#
directive|define
name|TCR_TG1_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|TCR_TG1_16K
value|(1<< TCR_TG1_SHIFT)
end_define

begin_define
define|#
directive|define
name|TCR_TG1_4K
value|(2<< TCR_TG1_SHIFT)
end_define

begin_define
define|#
directive|define
name|TCR_TG1_64K
value|(3<< TCR_TG1_SHIFT)
end_define

begin_define
define|#
directive|define
name|TCR_SH1_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|TCR_SH1_IS
value|(0x3UL<< TCR_SH1_SHIFT)
end_define

begin_define
define|#
directive|define
name|TCR_ORGN1_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|TCR_ORGN1_WBWA
value|(0x1UL<< TCR_ORGN1_SHIFT)
end_define

begin_define
define|#
directive|define
name|TCR_IRGN1_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|TCR_IRGN1_WBWA
value|(0x1UL<< TCR_IRGN1_SHIFT)
end_define

begin_define
define|#
directive|define
name|TCR_SH0_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|TCR_SH0_IS
value|(0x3UL<< TCR_SH0_SHIFT)
end_define

begin_define
define|#
directive|define
name|TCR_ORGN0_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|TCR_ORGN0_WBWA
value|(0x1UL<< TCR_ORGN0_SHIFT)
end_define

begin_define
define|#
directive|define
name|TCR_IRGN0_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|TCR_IRGN0_WBWA
value|(0x1UL<< TCR_IRGN0_SHIFT)
end_define

begin_define
define|#
directive|define
name|TCR_CACHE_ATTRS
value|((TCR_IRGN0_WBWA | TCR_IRGN1_WBWA) |\ 				(TCR_ORGN0_WBWA | TCR_ORGN1_WBWA))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_define
define|#
directive|define
name|TCR_SMP_ATTRS
value|(TCR_SH0_IS | TCR_SH1_IS)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TCR_SMP_ATTRS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TCR_T1SZ_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|TCR_T0SZ_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TCR_T1SZ
parameter_list|(
name|x
parameter_list|)
value|((x)<< TCR_T1SZ_SHIFT)
end_define

begin_define
define|#
directive|define
name|TCR_T0SZ
parameter_list|(
name|x
parameter_list|)
value|((x)<< TCR_T0SZ_SHIFT)
end_define

begin_define
define|#
directive|define
name|TCR_TxSZ
parameter_list|(
name|x
parameter_list|)
value|(TCR_T1SZ(x) | TCR_T0SZ(x))
end_define

begin_comment
comment|/* Saved Program Status Register */
end_comment

begin_define
define|#
directive|define
name|DBG_SPSR_SS
value|(0x1<< 21)
end_define

begin_comment
comment|/* Monitor Debug System Control Register */
end_comment

begin_define
define|#
directive|define
name|DBG_MDSCR_SS
value|(0x1<< 0)
end_define

begin_define
define|#
directive|define
name|DBG_MDSCR_KDE
value|(0x1<< 13)
end_define

begin_define
define|#
directive|define
name|DBG_MDSCR_MDE
value|(0x1<< 15)
end_define

begin_comment
comment|/* Perfomance Monitoring Counters */
end_comment

begin_define
define|#
directive|define
name|PMCR_E
value|(1<< 0)
end_define

begin_comment
comment|/* Enable all counters */
end_comment

begin_define
define|#
directive|define
name|PMCR_P
value|(1<< 1)
end_define

begin_comment
comment|/* Reset all counters */
end_comment

begin_define
define|#
directive|define
name|PMCR_C
value|(1<< 2)
end_define

begin_comment
comment|/* Clock counter reset */
end_comment

begin_define
define|#
directive|define
name|PMCR_D
value|(1<< 3)
end_define

begin_comment
comment|/* CNTR counts every 64 clk cycles */
end_comment

begin_define
define|#
directive|define
name|PMCR_X
value|(1<< 4)
end_define

begin_comment
comment|/* Export to ext. monitoring (ETM) */
end_comment

begin_define
define|#
directive|define
name|PMCR_DP
value|(1<< 5)
end_define

begin_comment
comment|/* Disable CCNT if non-invasive debug*/
end_comment

begin_define
define|#
directive|define
name|PMCR_LC
value|(1<< 6)
end_define

begin_comment
comment|/* Long cycle count enable */
end_comment

begin_define
define|#
directive|define
name|PMCR_IMP_SHIFT
value|24
end_define

begin_comment
comment|/* Implementer code */
end_comment

begin_define
define|#
directive|define
name|PMCR_IMP_MASK
value|(0xff<< PMCR_IMP_SHIFT)
end_define

begin_define
define|#
directive|define
name|PMCR_IDCODE_SHIFT
value|16
end_define

begin_comment
comment|/* Identification code */
end_comment

begin_define
define|#
directive|define
name|PMCR_IDCODE_MASK
value|(0xff<< PMCR_IDCODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|PMCR_IDCODE_CORTEX_A57
value|0x01
end_define

begin_define
define|#
directive|define
name|PMCR_IDCODE_CORTEX_A72
value|0x02
end_define

begin_define
define|#
directive|define
name|PMCR_IDCODE_CORTEX_A53
value|0x03
end_define

begin_define
define|#
directive|define
name|PMCR_N_SHIFT
value|11
end_define

begin_comment
comment|/* Number of counters implemented */
end_comment

begin_define
define|#
directive|define
name|PMCR_N_MASK
value|(0x1f<< PMCR_N_SHIFT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_ARMREG_H_ */
end_comment

end_unit

