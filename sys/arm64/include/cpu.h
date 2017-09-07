begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * Copyright (c) 2014-2016 The FreeBSD Foundation  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Portions of this software were developed by Andrew Turner  * under sponsorship from the FreeBSD Foundation  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)cpu.h 5.4 (Berkeley) 5/9/91  *	from: FreeBSD: src/sys/i386/include/cpu.h,v 1.62 2001/06/29  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_CPU_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_CPU_H_
end_define

begin_include
include|#
directive|include
file|<machine/atomic.h>
end_include

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_include
include|#
directive|include
file|<machine/armreg.h>
end_include

begin_define
define|#
directive|define
name|TRAPF_PC
parameter_list|(
name|tfp
parameter_list|)
value|((tfp)->tf_lr)
end_define

begin_define
define|#
directive|define
name|TRAPF_USERMODE
parameter_list|(
name|tfp
parameter_list|)
value|(((tfp)->tf_spsr& PSR_M_MASK) == PSR_M_EL0t)
end_define

begin_define
define|#
directive|define
name|cpu_getstack
parameter_list|(
name|td
parameter_list|)
value|((td)->td_frame->tf_sp)
end_define

begin_define
define|#
directive|define
name|cpu_setstack
parameter_list|(
name|td
parameter_list|,
name|sp
parameter_list|)
value|((td)->td_frame->tf_sp = (sp))
end_define

begin_define
define|#
directive|define
name|cpu_spinwait
parameter_list|()
value|__asm __volatile("yield" ::: "memory")
end_define

begin_comment
comment|/* Extract CPU affinity levels 0-3 */
end_comment

begin_define
define|#
directive|define
name|CPU_AFF0
parameter_list|(
name|mpidr
parameter_list|)
value|(u_int)(((mpidr)>> 0)& 0xff)
end_define

begin_define
define|#
directive|define
name|CPU_AFF1
parameter_list|(
name|mpidr
parameter_list|)
value|(u_int)(((mpidr)>> 8)& 0xff)
end_define

begin_define
define|#
directive|define
name|CPU_AFF2
parameter_list|(
name|mpidr
parameter_list|)
value|(u_int)(((mpidr)>> 16)& 0xff)
end_define

begin_define
define|#
directive|define
name|CPU_AFF3
parameter_list|(
name|mpidr
parameter_list|)
value|(u_int)(((mpidr)>> 32)& 0xff)
end_define

begin_define
define|#
directive|define
name|CPU_AFF0_MASK
value|0xffUL
end_define

begin_define
define|#
directive|define
name|CPU_AFF1_MASK
value|0xff00UL
end_define

begin_define
define|#
directive|define
name|CPU_AFF2_MASK
value|0xff0000UL
end_define

begin_define
define|#
directive|define
name|CPU_AFF3_MASK
value|0xff00000000UL
end_define

begin_define
define|#
directive|define
name|CPU_AFF_MASK
value|(CPU_AFF0_MASK | CPU_AFF1_MASK | \     CPU_AFF2_MASK| CPU_AFF3_MASK)
end_define

begin_comment
comment|/* Mask affinity fields in MPIDR_EL1 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|CPU_IMPL_ARM
value|0x41
end_define

begin_define
define|#
directive|define
name|CPU_IMPL_BROADCOM
value|0x42
end_define

begin_define
define|#
directive|define
name|CPU_IMPL_CAVIUM
value|0x43
end_define

begin_define
define|#
directive|define
name|CPU_IMPL_DEC
value|0x44
end_define

begin_define
define|#
directive|define
name|CPU_IMPL_INFINEON
value|0x49
end_define

begin_define
define|#
directive|define
name|CPU_IMPL_FREESCALE
value|0x4D
end_define

begin_define
define|#
directive|define
name|CPU_IMPL_NVIDIA
value|0x4E
end_define

begin_define
define|#
directive|define
name|CPU_IMPL_APM
value|0x50
end_define

begin_define
define|#
directive|define
name|CPU_IMPL_QUALCOMM
value|0x51
end_define

begin_define
define|#
directive|define
name|CPU_IMPL_MARVELL
value|0x56
end_define

begin_define
define|#
directive|define
name|CPU_IMPL_INTEL
value|0x69
end_define

begin_define
define|#
directive|define
name|CPU_PART_THUNDER
value|0x0A1
end_define

begin_define
define|#
directive|define
name|CPU_PART_FOUNDATION
value|0xD00
end_define

begin_define
define|#
directive|define
name|CPU_PART_CORTEX_A35
value|0xD04
end_define

begin_define
define|#
directive|define
name|CPU_PART_CORTEX_A53
value|0xD03
end_define

begin_define
define|#
directive|define
name|CPU_PART_CORTEX_A55
value|0xD05
end_define

begin_define
define|#
directive|define
name|CPU_PART_CORTEX_A57
value|0xD07
end_define

begin_define
define|#
directive|define
name|CPU_PART_CORTEX_A72
value|0xD08
end_define

begin_define
define|#
directive|define
name|CPU_PART_CORTEX_A73
value|0xD09
end_define

begin_define
define|#
directive|define
name|CPU_PART_CORTEX_A75
value|0xD0A
end_define

begin_define
define|#
directive|define
name|CPU_REV_THUNDER_1_0
value|0x00
end_define

begin_define
define|#
directive|define
name|CPU_REV_THUNDER_1_1
value|0x01
end_define

begin_define
define|#
directive|define
name|CPU_IMPL
parameter_list|(
name|midr
parameter_list|)
value|(((midr)>> 24)& 0xff)
end_define

begin_define
define|#
directive|define
name|CPU_PART
parameter_list|(
name|midr
parameter_list|)
value|(((midr)>> 4)& 0xfff)
end_define

begin_define
define|#
directive|define
name|CPU_VAR
parameter_list|(
name|midr
parameter_list|)
value|(((midr)>> 20)& 0xf)
end_define

begin_define
define|#
directive|define
name|CPU_REV
parameter_list|(
name|midr
parameter_list|)
value|(((midr)>> 0)& 0xf)
end_define

begin_define
define|#
directive|define
name|CPU_IMPL_TO_MIDR
parameter_list|(
name|val
parameter_list|)
value|(((val)& 0xff)<< 24)
end_define

begin_define
define|#
directive|define
name|CPU_PART_TO_MIDR
parameter_list|(
name|val
parameter_list|)
value|(((val)& 0xfff)<< 4)
end_define

begin_define
define|#
directive|define
name|CPU_VAR_TO_MIDR
parameter_list|(
name|val
parameter_list|)
value|(((val)& 0xf)<< 20)
end_define

begin_define
define|#
directive|define
name|CPU_REV_TO_MIDR
parameter_list|(
name|val
parameter_list|)
value|(((val)& 0xf)<< 0)
end_define

begin_define
define|#
directive|define
name|CPU_IMPL_MASK
value|(0xff<< 24)
end_define

begin_define
define|#
directive|define
name|CPU_PART_MASK
value|(0xfff<< 4)
end_define

begin_define
define|#
directive|define
name|CPU_VAR_MASK
value|(0xf<< 20)
end_define

begin_define
define|#
directive|define
name|CPU_REV_MASK
value|(0xf<< 0)
end_define

begin_define
define|#
directive|define
name|CPU_ID_RAW
parameter_list|(
name|impl
parameter_list|,
name|part
parameter_list|,
name|var
parameter_list|,
name|rev
parameter_list|)
define|\
value|(CPU_IMPL_TO_MIDR((impl)) |				\     CPU_PART_TO_MIDR((part)) | CPU_VAR_TO_MIDR((var)) |	\     CPU_REV_TO_MIDR((rev)))
end_define

begin_define
define|#
directive|define
name|CPU_MATCH
parameter_list|(
name|mask
parameter_list|,
name|impl
parameter_list|,
name|part
parameter_list|,
name|var
parameter_list|,
name|rev
parameter_list|)
define|\
value|(((mask)& PCPU_GET(midr)) ==			\     ((mask)& CPU_ID_RAW((impl), (part), (var), (rev))))
end_define

begin_define
define|#
directive|define
name|CPU_MATCH_RAW
parameter_list|(
name|mask
parameter_list|,
name|devid
parameter_list|)
define|\
value|(((mask)& PCPU_GET(midr)) == ((mask)& (devid)))
end_define

begin_comment
comment|/*  * Chip-specific errata. This defines are intended to be  * booleans used within if statements. When an appropriate  * kernel option is disabled, these defines must be defined  * as 0 to allow the compiler to remove a dead code thus  * produce better optimized kernel image.  */
end_comment

begin_comment
comment|/*  * Vendor:	Cavium  * Chip:	ThunderX  * Revision(s):	Pass 1.0, Pass 1.1  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|THUNDERX_PASS_1_1_ERRATA
end_ifdef

begin_define
define|#
directive|define
name|CPU_MATCH_ERRATA_CAVIUM_THUNDER_1_1
define|\
value|(CPU_MATCH(CPU_IMPL_MASK | CPU_PART_MASK | CPU_REV_MASK,		\     CPU_IMPL_CAVIUM, CPU_PART_THUNDER, 0, CPU_REV_THUNDER_1_0) ||	\     CPU_MATCH(CPU_IMPL_MASK | CPU_PART_MASK | CPU_REV_MASK,		\     CPU_IMPL_CAVIUM, CPU_PART_THUNDER, 0, CPU_REV_THUNDER_1_1))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CPU_MATCH_ERRATA_CAVIUM_THUNDER_1_1
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
name|btext
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|etext
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint64_t
name|__cpu_affinity
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cpu_halt
argument_list|(
name|void
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cpu_reset
argument_list|(
name|void
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|fork_trampoline
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|identify_cpu
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_cpu_features
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|swi_vm
parameter_list|(
name|void
modifier|*
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|CPU_AFFINITY
parameter_list|(
name|cpu
parameter_list|)
value|__cpu_affinity[(cpu)]
end_define

begin_define
define|#
directive|define
name|CPU_CURRENT_SOCKET
define|\
value|(CPU_AFF2(CPU_AFFINITY(PCPU_GET(cpuid))))
end_define

begin_function
specifier|static
name|__inline
name|uint64_t
name|get_cyclecount
parameter_list|(
name|void
parameter_list|)
block|{
name|uint64_t
name|ret
decl_stmt|;
name|ret
operator|=
name|READ_SPECIALREG
argument_list|(
name|cntvct_el0
argument_list|)
expr_stmt|;
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|ADDRESS_TRANSLATE_FUNC
parameter_list|(
name|stage
parameter_list|)
define|\
value|static inline uint64_t						\ arm64_address_translate_ ##stage (uint64_t addr)		\ {								\ 	uint64_t ret;						\ 								\ 	__asm __volatile(					\ 	    "at " __STRING(stage) ", %1 \n"					\ 	    "mrs %0, par_el1" : "=r"(ret) : "r"(addr));		\ 								\ 	return (ret);						\ }
end_define

begin_macro
name|ADDRESS_TRANSLATE_FUNC
argument_list|(
argument|s1e0r
argument_list|)
end_macro

begin_macro
name|ADDRESS_TRANSLATE_FUNC
argument_list|(
argument|s1e0w
argument_list|)
end_macro

begin_macro
name|ADDRESS_TRANSLATE_FUNC
argument_list|(
argument|s1e1r
argument_list|)
end_macro

begin_macro
name|ADDRESS_TRANSLATE_FUNC
argument_list|(
argument|s1e1w
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_CPU_H_ */
end_comment

end_unit

