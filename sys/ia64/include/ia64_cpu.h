begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_IA64_CPU_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_IA64_CPU_H_
end_define

begin_comment
comment|/*  * Definition of PSR and IPSR bits.  */
end_comment

begin_define
define|#
directive|define
name|IA64_PSR_BE
value|0x0000000000000002
end_define

begin_define
define|#
directive|define
name|IA64_PSR_UP
value|0x0000000000000004
end_define

begin_define
define|#
directive|define
name|IA64_PSR_AC
value|0x0000000000000008
end_define

begin_define
define|#
directive|define
name|IA64_PSR_MFL
value|0x0000000000000010
end_define

begin_define
define|#
directive|define
name|IA64_PSR_MFH
value|0x0000000000000020
end_define

begin_define
define|#
directive|define
name|IA64_PSR_IC
value|0x0000000000002000
end_define

begin_define
define|#
directive|define
name|IA64_PSR_I
value|0x0000000000004000
end_define

begin_define
define|#
directive|define
name|IA64_PSR_PK
value|0x0000000000008000
end_define

begin_define
define|#
directive|define
name|IA64_PSR_DT
value|0x0000000000020000
end_define

begin_define
define|#
directive|define
name|IA64_PSR_DFL
value|0x0000000000040000
end_define

begin_define
define|#
directive|define
name|IA64_PSR_DFH
value|0x0000000000080000
end_define

begin_define
define|#
directive|define
name|IA64_PSR_SP
value|0x0000000000100000
end_define

begin_define
define|#
directive|define
name|IA64_PSR_PP
value|0x0000000000200000
end_define

begin_define
define|#
directive|define
name|IA64_PSR_DI
value|0x0000000000400000
end_define

begin_define
define|#
directive|define
name|IA64_PSR_SI
value|0x0000000000800000
end_define

begin_define
define|#
directive|define
name|IA64_PSR_DB
value|0x0000000001000000
end_define

begin_define
define|#
directive|define
name|IA64_PSR_LP
value|0x0000000002000000
end_define

begin_define
define|#
directive|define
name|IA64_PSR_TB
value|0x0000000004000000
end_define

begin_define
define|#
directive|define
name|IA64_PSR_RT
value|0x0000000008000000
end_define

begin_define
define|#
directive|define
name|IA64_PSR_CPL
value|0x0000000300000000
end_define

begin_define
define|#
directive|define
name|IA64_PSR_CPL_KERN
value|0x0000000000000000
end_define

begin_define
define|#
directive|define
name|IA64_PSR_CPL_1
value|0x0000000100000000
end_define

begin_define
define|#
directive|define
name|IA64_PSR_CPL_2
value|0x0000000200000000
end_define

begin_define
define|#
directive|define
name|IA64_PSR_CPL_USER
value|0x0000000300000000
end_define

begin_define
define|#
directive|define
name|IA64_PSR_IS
value|0x0000000400000000
end_define

begin_define
define|#
directive|define
name|IA64_PSR_MC
value|0x0000000800000000
end_define

begin_define
define|#
directive|define
name|IA64_PSR_IT
value|0x0000001000000000
end_define

begin_define
define|#
directive|define
name|IA64_PSR_ID
value|0x0000002000000000
end_define

begin_define
define|#
directive|define
name|IA64_PSR_DA
value|0x0000004000000000
end_define

begin_define
define|#
directive|define
name|IA64_PSR_DD
value|0x0000008000000000
end_define

begin_define
define|#
directive|define
name|IA64_PSR_SS
value|0x0000010000000000
end_define

begin_define
define|#
directive|define
name|IA64_PSR_RI
value|0x0000060000000000
end_define

begin_define
define|#
directive|define
name|IA64_PSR_RI_0
value|0x0000000000000000
end_define

begin_define
define|#
directive|define
name|IA64_PSR_RI_1
value|0x0000020000000000
end_define

begin_define
define|#
directive|define
name|IA64_PSR_RI_2
value|0x0000040000000000
end_define

begin_define
define|#
directive|define
name|IA64_PSR_ED
value|0x0000080000000000
end_define

begin_define
define|#
directive|define
name|IA64_PSR_BN
value|0x0000100000000000
end_define

begin_define
define|#
directive|define
name|IA64_PSR_IA
value|0x0000200000000000
end_define

begin_comment
comment|/*  * Definition of ISR bits.  */
end_comment

begin_define
define|#
directive|define
name|IA64_ISR_CODE
value|0x000000000000ffff
end_define

begin_define
define|#
directive|define
name|IA64_ISR_VECTOR
value|0x0000000000ff0000
end_define

begin_define
define|#
directive|define
name|IA64_ISR_X
value|0x0000000100000000
end_define

begin_define
define|#
directive|define
name|IA64_ISR_W
value|0x0000000200000000
end_define

begin_define
define|#
directive|define
name|IA64_ISR_R
value|0x0000000400000000
end_define

begin_define
define|#
directive|define
name|IA64_ISR_NA
value|0x0000000800000000
end_define

begin_define
define|#
directive|define
name|IA64_ISR_SP
value|0x0000001000000000
end_define

begin_define
define|#
directive|define
name|IA64_ISR_RS
value|0x0000002000000000
end_define

begin_define
define|#
directive|define
name|IA64_ISR_IR
value|0x0000004000000000
end_define

begin_define
define|#
directive|define
name|IA64_ISR_NI
value|0x0000008000000000
end_define

begin_define
define|#
directive|define
name|IA64_ISR_SO
value|0x0000010000000000
end_define

begin_define
define|#
directive|define
name|IA64_ISR_EI
value|0x0000060000000000
end_define

begin_define
define|#
directive|define
name|IA64_ISR_EI_0
value|0x0000000000000000
end_define

begin_define
define|#
directive|define
name|IA64_ISR_EI_1
value|0x0000020000000000
end_define

begin_define
define|#
directive|define
name|IA64_ISR_EI_2
value|0x0000040000000000
end_define

begin_define
define|#
directive|define
name|IA64_ISR_ED
value|0x0000080000000000
end_define

begin_comment
comment|/*  * Vector numbers for various ia64 interrupts.  */
end_comment

begin_define
define|#
directive|define
name|IA64_VEC_VHPT
value|0
end_define

begin_define
define|#
directive|define
name|IA64_VEC_ITLB
value|1
end_define

begin_define
define|#
directive|define
name|IA64_VEC_DTLB
value|2
end_define

begin_define
define|#
directive|define
name|IA64_VEC_ALT_ITLB
value|3
end_define

begin_define
define|#
directive|define
name|IA64_VEC_ALT_DTLB
value|4
end_define

begin_define
define|#
directive|define
name|IA64_VEC_NESTED_DTLB
value|5
end_define

begin_define
define|#
directive|define
name|IA64_VEC_IKEY_MISS
value|6
end_define

begin_define
define|#
directive|define
name|IA64_VEC_DKEY_MISS
value|7
end_define

begin_define
define|#
directive|define
name|IA64_VEC_DIRTY_BIT
value|8
end_define

begin_define
define|#
directive|define
name|IA64_VEC_INST_ACCESS
value|9
end_define

begin_define
define|#
directive|define
name|IA64_VEC_DATA_ACCESS
value|10
end_define

begin_define
define|#
directive|define
name|IA64_VEC_BREAK
value|11
end_define

begin_define
define|#
directive|define
name|IA64_VEC_EXT_INTR
value|12
end_define

begin_define
define|#
directive|define
name|IA64_VEC_PAGE_NOT_PRESENT
value|20
end_define

begin_define
define|#
directive|define
name|IA64_VEC_KEY_PERMISSION
value|21
end_define

begin_define
define|#
directive|define
name|IA64_VEC_INST_ACCESS_RIGHTS
value|22
end_define

begin_define
define|#
directive|define
name|IA64_VEC_DATA_ACCESS_RIGHTS
value|23
end_define

begin_define
define|#
directive|define
name|IA64_VEC_GENERAL_EXCEPTION
value|24
end_define

begin_define
define|#
directive|define
name|IA64_VEC_DISABLED_FP
value|25
end_define

begin_define
define|#
directive|define
name|IA64_VEC_NAT_CONSUMPTION
value|26
end_define

begin_define
define|#
directive|define
name|IA64_VEC_SPECULATION
value|27
end_define

begin_define
define|#
directive|define
name|IA64_VEC_DEBUG
value|29
end_define

begin_define
define|#
directive|define
name|IA64_VEC_UNALIGNED_REFERENCE
value|30
end_define

begin_define
define|#
directive|define
name|IA64_VEC_UNSUPP_DATA_REFERENCE
value|31
end_define

begin_define
define|#
directive|define
name|IA64_VEC_FLOATING_POINT_FAULT
value|32
end_define

begin_define
define|#
directive|define
name|IA64_VEC_FLOATING_POINT_TRAP
value|33
end_define

begin_define
define|#
directive|define
name|IA64_VEC_LOWER_PRIVILEGE_TRANSFER
value|34
end_define

begin_define
define|#
directive|define
name|IA64_VEC_TAKEN_BRANCH_TRAP
value|35
end_define

begin_define
define|#
directive|define
name|IA64_VEC_SINGLE_STEP_TRAP
value|36
end_define

begin_define
define|#
directive|define
name|IA64_VEC_IA32_EXCEPTION
value|45
end_define

begin_define
define|#
directive|define
name|IA64_VEC_IA32_INTERCEPT
value|46
end_define

begin_define
define|#
directive|define
name|IA64_VEC_IA32_INTERRUPT
value|47
end_define

begin_comment
comment|/*  * Manipulating region bits of an address.  */
end_comment

begin_define
define|#
directive|define
name|IA64_RR_BASE
parameter_list|(
name|n
parameter_list|)
value|(((u_int64_t) (n))<< 61)
end_define

begin_define
define|#
directive|define
name|IA64_RR_MASK
parameter_list|(
name|x
parameter_list|)
value|((x)& ((1L<< 61) - 1))
end_define

begin_define
define|#
directive|define
name|IA64_PHYS_TO_RR6
parameter_list|(
name|x
parameter_list|)
value|((x) | IA64_RR_BASE(6))
end_define

begin_define
define|#
directive|define
name|IA64_PHYS_TO_RR7
parameter_list|(
name|x
parameter_list|)
value|((x) | IA64_RR_BASE(7))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_comment
comment|/*  * Various special ia64 instructions.  */
end_comment

begin_comment
comment|/*  * Memory Fence.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|ia64_mf
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm __volatile("mf");
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|ia64_mf_a
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm __volatile("mf.a");
block|}
end_function

begin_comment
comment|/*  * Flush Cache.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|ia64_fc
parameter_list|(
name|u_int64_t
name|va
parameter_list|)
block|{
asm|__asm __volatile("fc %0" :: "r"(va));
block|}
end_function

begin_comment
comment|/*  * Sync instruction stream.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|ia64_sync_i
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm __volatile("sync.i");
block|}
end_function

begin_comment
comment|/*  * Calculate address in VHPT for va.  */
end_comment

begin_function
specifier|static
name|__inline
name|u_int64_t
name|ia64_thash
parameter_list|(
name|u_int64_t
name|va
parameter_list|)
block|{
name|u_int64_t
name|result
decl_stmt|;
asm|__asm __volatile("thash %0=%1" : "=r" (result) : "r" (va));
return|return
name|result
return|;
block|}
end_function

begin_comment
comment|/*  * Calculate VHPT tag for va.  */
end_comment

begin_function
specifier|static
name|__inline
name|u_int64_t
name|ia64_ttag
parameter_list|(
name|u_int64_t
name|va
parameter_list|)
block|{
name|u_int64_t
name|result
decl_stmt|;
asm|__asm __volatile("ttag %0=%1" : "=r" (result) : "r" (va));
return|return
name|result
return|;
block|}
end_function

begin_comment
comment|/*  * Convert virtual address to physical.  */
end_comment

begin_function
specifier|static
name|__inline
name|u_int64_t
name|ia64_tpa
parameter_list|(
name|u_int64_t
name|va
parameter_list|)
block|{
name|u_int64_t
name|result
decl_stmt|;
asm|__asm __volatile("tpa %0=%1" : "=r" (result) : "r" (va));
return|return
name|result
return|;
block|}
end_function

begin_comment
comment|/*  * Generate a ptc.e instruction.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|ia64_ptc_e
parameter_list|(
name|u_int64_t
name|v
parameter_list|)
block|{
asm|__asm __volatile("ptc.e %0;; srlz.d;;" :: "r"(v));
block|}
end_function

begin_comment
comment|/*  * Generate a ptc.g instruction.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|ia64_ptc_g
parameter_list|(
name|u_int64_t
name|va
parameter_list|,
name|u_int64_t
name|log2size
parameter_list|)
block|{
asm|__asm __volatile("ptc.g %0,%1;; srlz.d;;" :: "r"(va), "r"(log2size));
block|}
end_function

begin_comment
comment|/*  * Generate a ptc.ga instruction.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|ia64_ptc_ga
parameter_list|(
name|u_int64_t
name|va
parameter_list|,
name|u_int64_t
name|log2size
parameter_list|)
block|{
asm|__asm __volatile("ptc.ga %0,%1;; srlz.d;;" :: "r"(va), "r"(log2size));
block|}
end_function

begin_comment
comment|/*  * Generate a ptc.l instruction.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|ia64_ptc_l
parameter_list|(
name|u_int64_t
name|va
parameter_list|,
name|u_int64_t
name|log2size
parameter_list|)
block|{
asm|__asm __volatile("ptc.l %0,%1;; srlz.d;;" :: "r"(va), "r"(log2size));
block|}
end_function

begin_comment
comment|/*  * Read the value of psr.  */
end_comment

begin_function
specifier|static
name|__inline
name|u_int64_t
name|ia64_get_psr
parameter_list|(
name|void
parameter_list|)
block|{
name|u_int64_t
name|result
decl_stmt|;
asm|__asm __volatile("mov %0=psr;;" : "=r" (result));
return|return
name|result
return|;
block|}
end_function

begin_comment
comment|/*  * Define accessors for application registers.  */
end_comment

begin_define
define|#
directive|define
name|IA64_AR
parameter_list|(
name|name
parameter_list|)
define|\ 								\
value|static __inline u_int64_t					\ ia64_get_##name(void)						\ {								\ 	u_int64_t result;					\ 	__asm __volatile("mov %0=ar." #name : "=r" (result));	\ 	return result;						\ }								\ 								\ static __inline void						\ ia64_set_##name(u_int64_t v)					\ {								\ 	__asm __volatile("mov ar." #name "=%0" :: "r" (v));	\ }
end_define

begin_macro
name|IA64_AR
argument_list|(
argument|k0
argument_list|)
end_macro

begin_macro
name|IA64_AR
argument_list|(
argument|k1
argument_list|)
end_macro

begin_macro
name|IA64_AR
argument_list|(
argument|k2
argument_list|)
end_macro

begin_macro
name|IA64_AR
argument_list|(
argument|k3
argument_list|)
end_macro

begin_macro
name|IA64_AR
argument_list|(
argument|k4
argument_list|)
end_macro

begin_macro
name|IA64_AR
argument_list|(
argument|k5
argument_list|)
end_macro

begin_macro
name|IA64_AR
argument_list|(
argument|k6
argument_list|)
end_macro

begin_macro
name|IA64_AR
argument_list|(
argument|k7
argument_list|)
end_macro

begin_macro
name|IA64_AR
argument_list|(
argument|rsc
argument_list|)
end_macro

begin_macro
name|IA64_AR
argument_list|(
argument|bsp
argument_list|)
end_macro

begin_macro
name|IA64_AR
argument_list|(
argument|bspstore
argument_list|)
end_macro

begin_macro
name|IA64_AR
argument_list|(
argument|rnat
argument_list|)
end_macro

begin_macro
name|IA64_AR
argument_list|(
argument|fcr
argument_list|)
end_macro

begin_macro
name|IA64_AR
argument_list|(
argument|eflag
argument_list|)
end_macro

begin_macro
name|IA64_AR
argument_list|(
argument|csd
argument_list|)
end_macro

begin_macro
name|IA64_AR
argument_list|(
argument|ssd
argument_list|)
end_macro

begin_macro
name|IA64_AR
argument_list|(
argument|cflg
argument_list|)
end_macro

begin_macro
name|IA64_AR
argument_list|(
argument|fsr
argument_list|)
end_macro

begin_macro
name|IA64_AR
argument_list|(
argument|fir
argument_list|)
end_macro

begin_macro
name|IA64_AR
argument_list|(
argument|fdr
argument_list|)
end_macro

begin_macro
name|IA64_AR
argument_list|(
argument|ccv
argument_list|)
end_macro

begin_macro
name|IA64_AR
argument_list|(
argument|unat
argument_list|)
end_macro

begin_macro
name|IA64_AR
argument_list|(
argument|fpsr
argument_list|)
end_macro

begin_macro
name|IA64_AR
argument_list|(
argument|itc
argument_list|)
end_macro

begin_macro
name|IA64_AR
argument_list|(
argument|pfs
argument_list|)
end_macro

begin_macro
name|IA64_AR
argument_list|(
argument|lc
argument_list|)
end_macro

begin_macro
name|IA64_AR
argument_list|(
argument|ec
argument_list|)
end_macro

begin_comment
comment|/*  * Define accessors for control registers.  */
end_comment

begin_define
define|#
directive|define
name|IA64_CR
parameter_list|(
name|name
parameter_list|)
define|\ 								\
value|static __inline u_int64_t					\ ia64_get_##name(void)						\ {								\ 	u_int64_t result;					\ 	__asm __volatile("mov %0=cr." #name : "=r" (result));	\ 	return result;						\ }								\ 								\ static __inline void						\ ia64_set_##name(u_int64_t v)					\ {								\ 	__asm __volatile("mov cr." #name "=%0" :: "r" (v));	\ }
end_define

begin_macro
name|IA64_CR
argument_list|(
argument|dcr
argument_list|)
end_macro

begin_macro
name|IA64_CR
argument_list|(
argument|itm
argument_list|)
end_macro

begin_macro
name|IA64_CR
argument_list|(
argument|iva
argument_list|)
end_macro

begin_macro
name|IA64_CR
argument_list|(
argument|pta
argument_list|)
end_macro

begin_macro
name|IA64_CR
argument_list|(
argument|ipsr
argument_list|)
end_macro

begin_macro
name|IA64_CR
argument_list|(
argument|isr
argument_list|)
end_macro

begin_macro
name|IA64_CR
argument_list|(
argument|iip
argument_list|)
end_macro

begin_macro
name|IA64_CR
argument_list|(
argument|ifa
argument_list|)
end_macro

begin_macro
name|IA64_CR
argument_list|(
argument|itir
argument_list|)
end_macro

begin_macro
name|IA64_CR
argument_list|(
argument|iipa
argument_list|)
end_macro

begin_macro
name|IA64_CR
argument_list|(
argument|ifs
argument_list|)
end_macro

begin_macro
name|IA64_CR
argument_list|(
argument|iim
argument_list|)
end_macro

begin_macro
name|IA64_CR
argument_list|(
argument|iha
argument_list|)
end_macro

begin_macro
name|IA64_CR
argument_list|(
argument|lid
argument_list|)
end_macro

begin_macro
name|IA64_CR
argument_list|(
argument|ivr
argument_list|)
end_macro

begin_macro
name|IA64_CR
argument_list|(
argument|tpr
argument_list|)
end_macro

begin_macro
name|IA64_CR
argument_list|(
argument|eoi
argument_list|)
end_macro

begin_macro
name|IA64_CR
argument_list|(
argument|irr0
argument_list|)
end_macro

begin_macro
name|IA64_CR
argument_list|(
argument|irr1
argument_list|)
end_macro

begin_macro
name|IA64_CR
argument_list|(
argument|irr2
argument_list|)
end_macro

begin_macro
name|IA64_CR
argument_list|(
argument|irr3
argument_list|)
end_macro

begin_macro
name|IA64_CR
argument_list|(
argument|itv
argument_list|)
end_macro

begin_macro
name|IA64_CR
argument_list|(
argument|pmv
argument_list|)
end_macro

begin_macro
name|IA64_CR
argument_list|(
argument|cmcv
argument_list|)
end_macro

begin_macro
name|IA64_CR
argument_list|(
argument|lrr0
argument_list|)
end_macro

begin_macro
name|IA64_CR
argument_list|(
argument|lrr1
argument_list|)
end_macro

begin_comment
comment|/*  * Write a region register.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|ia64_set_rr
parameter_list|(
name|u_int64_t
name|rrbase
parameter_list|,
name|u_int64_t
name|v
parameter_list|)
block|{
asm|__asm __volatile("mov rr[%0]=%1;; srlz.d;;"
operator|::
literal|"r"
operator|(
name|rrbase
operator|)
operator|,
literal|"r"
operator|(
name|v
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_comment
unit|}
comment|/*  * Read a CPUID register.  */
end_comment

begin_function
unit|static
name|__inline
name|u_int64_t
name|ia64_get_cpuid
parameter_list|(
name|int
name|i
parameter_list|)
block|{
name|u_int64_t
name|result
decl_stmt|;
asm|__asm __volatile("mov %0=cpuid[%1]"
block|:
literal|"=r"
operator|(
name|result
operator|)
operator|:
literal|"r"
operator|(
name|i
operator|)
block|)
function|;
end_function

begin_return
return|return
name|result
return|;
end_return

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_IA64_CPU_H_ */
end_comment

end_unit

