begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) KATO Takenori, 1997, 1998.  *   * All rights reserved.  Unpublished rights reserved under the copyright  * laws of Japan.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer as  *    the first lines of this file unmodified.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"opt_cpu.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<machine/cputypes.h>
end_include

begin_include
include|#
directive|include
file|<machine/md_var.h>
end_include

begin_include
include|#
directive|include
file|<machine/specialreg.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_decl_stmt
specifier|static
name|int
name|hw_instruction_sse
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_hw
argument_list|,
name|OID_AUTO
argument_list|,
name|instruction_sse
argument_list|,
name|CTLFLAG_RD
argument_list|,
operator|&
name|hw_instruction_sse
argument_list|,
literal|0
argument_list|,
literal|"SIMD/MMX2 instructions available in CPU"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * -1: automatic (default)  *  0: keep enable CLFLUSH  *  1: force disable CLFLUSH  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|hw_clflush_disable
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cpu
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Are we 386, 386sx, 486, etc? */
end_comment

begin_decl_stmt
name|u_int
name|cpu_feature
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Feature flags */
end_comment

begin_decl_stmt
name|u_int
name|cpu_feature2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Feature flags */
end_comment

begin_decl_stmt
name|u_int
name|amd_feature
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* AMD feature flags */
end_comment

begin_decl_stmt
name|u_int
name|amd_feature2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* AMD feature flags */
end_comment

begin_decl_stmt
name|u_int
name|amd_pminfo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* AMD advanced power management info */
end_comment

begin_decl_stmt
name|u_int
name|via_feature_rng
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* VIA RNG features */
end_comment

begin_decl_stmt
name|u_int
name|via_feature_xcrypt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* VIA ACE features */
end_comment

begin_decl_stmt
name|u_int
name|cpu_high
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Highest arg to CPUID */
end_comment

begin_decl_stmt
name|u_int
name|cpu_exthigh
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Highest arg to extended CPUID */
end_comment

begin_decl_stmt
name|u_int
name|cpu_id
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Stepping ID */
end_comment

begin_decl_stmt
name|u_int
name|cpu_procinfo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* HyperThreading Info / Brand Index / CLFUSH */
end_comment

begin_decl_stmt
name|u_int
name|cpu_procinfo2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Multicore info */
end_comment

begin_decl_stmt
name|char
name|cpu_vendor
index|[
literal|20
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* CPU Origin code */
end_comment

begin_decl_stmt
name|u_int
name|cpu_vendor_id
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* CPU vendor ID */
end_comment

begin_decl_stmt
name|u_int
name|cpu_fxsr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SSE enabled */
end_comment

begin_decl_stmt
name|u_int
name|cpu_mxcsr_mask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Valid bits in mxcsr */
end_comment

begin_decl_stmt
name|u_int
name|cpu_clflush_line_size
init|=
literal|32
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSCTL_UINT
argument_list|(
name|_hw
argument_list|,
name|OID_AUTO
argument_list|,
name|via_feature_rng
argument_list|,
name|CTLFLAG_RD
argument_list|,
operator|&
name|via_feature_rng
argument_list|,
literal|0
argument_list|,
literal|"VIA C3/C7 RNG feature available in CPU"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_UINT
argument_list|(
name|_hw
argument_list|,
name|OID_AUTO
argument_list|,
name|via_feature_xcrypt
argument_list|,
name|CTLFLAG_RD
argument_list|,
operator|&
name|via_feature_xcrypt
argument_list|,
literal|0
argument_list|,
literal|"VIA C3/C7 xcrypt feature available in CPU"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Initialize special VIA C3/C7 features  */
end_comment

begin_function
specifier|static
name|void
name|init_via
parameter_list|(
name|void
parameter_list|)
block|{
name|u_int
name|regs
index|[
literal|4
index|]
decl_stmt|,
name|val
decl_stmt|;
name|u_int64_t
name|msreg
decl_stmt|;
name|do_cpuid
argument_list|(
literal|0xc0000000
argument_list|,
name|regs
argument_list|)
expr_stmt|;
name|val
operator|=
name|regs
index|[
literal|0
index|]
expr_stmt|;
if|if
condition|(
name|val
operator|>=
literal|0xc0000001
condition|)
block|{
name|do_cpuid
argument_list|(
literal|0xc0000001
argument_list|,
name|regs
argument_list|)
expr_stmt|;
name|val
operator|=
name|regs
index|[
literal|3
index|]
expr_stmt|;
block|}
else|else
name|val
operator|=
literal|0
expr_stmt|;
comment|/* Enable RNG if present and disabled */
if|if
condition|(
name|val
operator|&
name|VIA_CPUID_HAS_RNG
condition|)
block|{
if|if
condition|(
operator|!
operator|(
name|val
operator|&
name|VIA_CPUID_DO_RNG
operator|)
condition|)
block|{
name|msreg
operator|=
name|rdmsr
argument_list|(
literal|0x110B
argument_list|)
expr_stmt|;
name|msreg
operator||=
literal|0x40
expr_stmt|;
name|wrmsr
argument_list|(
literal|0x110B
argument_list|,
name|msreg
argument_list|)
expr_stmt|;
block|}
name|via_feature_rng
operator|=
name|VIA_HAS_RNG
expr_stmt|;
block|}
comment|/* Enable AES engine if present and disabled */
if|if
condition|(
name|val
operator|&
name|VIA_CPUID_HAS_ACE
condition|)
block|{
if|if
condition|(
operator|!
operator|(
name|val
operator|&
name|VIA_CPUID_DO_ACE
operator|)
condition|)
block|{
name|msreg
operator|=
name|rdmsr
argument_list|(
literal|0x1107
argument_list|)
expr_stmt|;
name|msreg
operator||=
operator|(
literal|0x01
operator|<<
literal|28
operator|)
expr_stmt|;
name|wrmsr
argument_list|(
literal|0x1107
argument_list|,
name|msreg
argument_list|)
expr_stmt|;
block|}
name|via_feature_xcrypt
operator||=
name|VIA_HAS_AES
expr_stmt|;
block|}
comment|/* Enable ACE2 engine if present and disabled */
if|if
condition|(
name|val
operator|&
name|VIA_CPUID_HAS_ACE2
condition|)
block|{
if|if
condition|(
operator|!
operator|(
name|val
operator|&
name|VIA_CPUID_DO_ACE2
operator|)
condition|)
block|{
name|msreg
operator|=
name|rdmsr
argument_list|(
literal|0x1107
argument_list|)
expr_stmt|;
name|msreg
operator||=
operator|(
literal|0x01
operator|<<
literal|28
operator|)
expr_stmt|;
name|wrmsr
argument_list|(
literal|0x1107
argument_list|,
name|msreg
argument_list|)
expr_stmt|;
block|}
name|via_feature_xcrypt
operator||=
name|VIA_HAS_AESCTR
expr_stmt|;
block|}
comment|/* Enable SHA engine if present and disabled */
if|if
condition|(
name|val
operator|&
name|VIA_CPUID_HAS_PHE
condition|)
block|{
if|if
condition|(
operator|!
operator|(
name|val
operator|&
name|VIA_CPUID_DO_PHE
operator|)
condition|)
block|{
name|msreg
operator|=
name|rdmsr
argument_list|(
literal|0x1107
argument_list|)
expr_stmt|;
name|msreg
operator||=
operator|(
literal|0x01
operator|<<
literal|28
comment|/**/
operator|)
expr_stmt|;
name|wrmsr
argument_list|(
literal|0x1107
argument_list|,
name|msreg
argument_list|)
expr_stmt|;
block|}
name|via_feature_xcrypt
operator||=
name|VIA_HAS_SHA
expr_stmt|;
block|}
comment|/* Enable MM engine if present and disabled */
if|if
condition|(
name|val
operator|&
name|VIA_CPUID_HAS_PMM
condition|)
block|{
if|if
condition|(
operator|!
operator|(
name|val
operator|&
name|VIA_CPUID_DO_PMM
operator|)
condition|)
block|{
name|msreg
operator|=
name|rdmsr
argument_list|(
literal|0x1107
argument_list|)
expr_stmt|;
name|msreg
operator||=
operator|(
literal|0x01
operator|<<
literal|28
comment|/**/
operator|)
expr_stmt|;
name|wrmsr
argument_list|(
literal|0x1107
argument_list|,
name|msreg
argument_list|)
expr_stmt|;
block|}
name|via_feature_xcrypt
operator||=
name|VIA_HAS_MM
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * Initialize CPU control registers  */
end_comment

begin_function
name|void
name|initializecpu
parameter_list|(
name|void
parameter_list|)
block|{
name|uint64_t
name|msr
decl_stmt|;
if|if
condition|(
operator|(
name|cpu_feature
operator|&
name|CPUID_XMM
operator|)
operator|&&
operator|(
name|cpu_feature
operator|&
name|CPUID_FXSR
operator|)
condition|)
block|{
name|load_cr4
argument_list|(
name|rcr4
argument_list|()
operator||
name|CR4_FXSR
operator||
name|CR4_XMM
argument_list|)
expr_stmt|;
name|cpu_fxsr
operator|=
name|hw_instruction_sse
operator|=
literal|1
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|amd_feature
operator|&
name|AMDID_NX
operator|)
operator|!=
literal|0
condition|)
block|{
name|msr
operator|=
name|rdmsr
argument_list|(
name|MSR_EFER
argument_list|)
operator||
name|EFER_NXE
expr_stmt|;
name|wrmsr
argument_list|(
name|MSR_EFER
argument_list|,
name|msr
argument_list|)
expr_stmt|;
name|pg_nx
operator|=
name|PG_NX
expr_stmt|;
block|}
if|if
condition|(
name|cpu_vendor_id
operator|==
name|CPU_VENDOR_CENTAUR
operator|&&
name|CPUID_TO_FAMILY
argument_list|(
name|cpu_id
argument_list|)
operator|==
literal|0x6
operator|&&
name|CPUID_TO_MODEL
argument_list|(
name|cpu_id
argument_list|)
operator|>=
literal|0xf
condition|)
name|init_via
argument_list|()
expr_stmt|;
comment|/* 	 * CPUID with %eax = 1, %ebx returns 	 * Bits 15-8: CLFLUSH line size 	 * 	(Value * 8 = cache line size in bytes) 	 */
if|if
condition|(
operator|(
name|cpu_feature
operator|&
name|CPUID_CLFSH
operator|)
operator|!=
literal|0
condition|)
name|cpu_clflush_line_size
operator|=
operator|(
operator|(
name|cpu_procinfo
operator|>>
literal|8
operator|)
operator|&
literal|0xff
operator|)
operator|*
literal|8
expr_stmt|;
comment|/* 	 * XXXKIB: (temporary) hack to work around traps generated when 	 * CLFLUSHing APIC registers window. 	 */
name|TUNABLE_INT_FETCH
argument_list|(
literal|"hw.clflush_disable"
argument_list|,
operator|&
name|hw_clflush_disable
argument_list|)
expr_stmt|;
if|if
condition|(
name|cpu_vendor_id
operator|==
name|CPU_VENDOR_INTEL
operator|&&
operator|!
operator|(
name|cpu_feature
operator|&
name|CPUID_SS
operator|)
operator|&&
name|hw_clflush_disable
operator|==
operator|-
literal|1
condition|)
name|cpu_feature
operator|&=
operator|~
name|CPUID_CLFSH
expr_stmt|;
comment|/* 	 * Allow to disable CLFLUSH feature manually by 	 * hw.clflush_disable tunable.  This may help Xen guest on some AMD 	 * CPUs. 	 */
if|if
condition|(
name|hw_clflush_disable
operator|==
literal|1
condition|)
name|cpu_feature
operator|&=
operator|~
name|CPUID_CLFSH
expr_stmt|;
block|}
end_function

end_unit

