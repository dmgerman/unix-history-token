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
file|<sys/pcpu.h>
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

begin_decl_stmt
name|u_int
name|cpu_stdext_feature
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|cpu_max_ext_state_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|cpu_mon_mwait_flags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MONITOR/MWAIT flags (CPUID.05H.ECX) */
end_comment

begin_decl_stmt
name|u_int
name|cpu_mon_min_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MONITOR minimum range size, bytes */
end_comment

begin_decl_stmt
name|u_int
name|cpu_mon_max_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MONITOR minimum range size, bytes */
end_comment

begin_decl_stmt
name|u_int
name|cpu_maxphyaddr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Max phys addr width in bits */
end_comment

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
literal|"VIA RNG feature available in CPU"
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
literal|"VIA xcrypt feature available in CPU"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|void
name|init_amd
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* 	 * Work around Erratum 721 for Family 10h and 12h processors. 	 * These processors may incorrectly update the stack pointer 	 * after a long series of push and/or near-call instructions, 	 * or a long series of pop and/or near-return instructions. 	 * 	 * http://support.amd.com/us/Processor_TechDocs/41322_10h_Rev_Gd.pdf 	 * http://support.amd.com/us/Processor_TechDocs/44739_12h_Rev_Gd.pdf 	 * 	 * Hypervisors do not provide access to the errata MSR, 	 * causing #GP exception on attempt to apply the errata.  The 	 * MSR write shall be done on host and persist globally 	 * anyway, so do not try to do it when under virtualization. 	 */
switch|switch
condition|(
name|CPUID_TO_FAMILY
argument_list|(
name|cpu_id
argument_list|)
condition|)
block|{
case|case
literal|0x10
case|:
case|case
literal|0x12
case|:
if|if
condition|(
operator|(
name|cpu_feature2
operator|&
name|CPUID2_HV
operator|)
operator|==
literal|0
condition|)
name|wrmsr
argument_list|(
literal|0xc0011029
argument_list|,
name|rdmsr
argument_list|(
literal|0xc0011029
argument_list|)
operator||
literal|1
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
end_function

begin_comment
comment|/*  * Initialize special VIA features  */
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
comment|/* 	 * Check extended CPUID for PadLock features. 	 * 	 * http://www.via.com.tw/en/downloads/whitepapers/initiatives/padlock/programming_guide.pdf 	 */
name|do_cpuid
argument_list|(
literal|0xc0000000
argument_list|,
name|regs
argument_list|)
expr_stmt|;
if|if
condition|(
name|regs
index|[
literal|0
index|]
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
return|return;
comment|/* Enable RNG if present. */
if|if
condition|(
operator|(
name|val
operator|&
name|VIA_CPUID_HAS_RNG
operator|)
operator|!=
literal|0
condition|)
block|{
name|via_feature_rng
operator|=
name|VIA_HAS_RNG
expr_stmt|;
name|wrmsr
argument_list|(
literal|0x110B
argument_list|,
name|rdmsr
argument_list|(
literal|0x110B
argument_list|)
operator||
name|VIA_CPUID_DO_RNG
argument_list|)
expr_stmt|;
block|}
comment|/* Enable PadLock if present. */
if|if
condition|(
operator|(
name|val
operator|&
name|VIA_CPUID_HAS_ACE
operator|)
operator|!=
literal|0
condition|)
name|via_feature_xcrypt
operator||=
name|VIA_HAS_AES
expr_stmt|;
if|if
condition|(
operator|(
name|val
operator|&
name|VIA_CPUID_HAS_ACE2
operator|)
operator|!=
literal|0
condition|)
name|via_feature_xcrypt
operator||=
name|VIA_HAS_AESCTR
expr_stmt|;
if|if
condition|(
operator|(
name|val
operator|&
name|VIA_CPUID_HAS_PHE
operator|)
operator|!=
literal|0
condition|)
name|via_feature_xcrypt
operator||=
name|VIA_HAS_SHA
expr_stmt|;
if|if
condition|(
operator|(
name|val
operator|&
name|VIA_CPUID_HAS_PMM
operator|)
operator|!=
literal|0
condition|)
name|via_feature_xcrypt
operator||=
name|VIA_HAS_MM
expr_stmt|;
if|if
condition|(
name|via_feature_xcrypt
operator|!=
literal|0
condition|)
name|wrmsr
argument_list|(
literal|0x1107
argument_list|,
name|rdmsr
argument_list|(
literal|0x1107
argument_list|)
operator||
operator|(
literal|1
operator|<<
literal|28
operator|)
argument_list|)
expr_stmt|;
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
name|uint32_t
name|cr4
decl_stmt|;
name|cr4
operator|=
name|rcr4
argument_list|()
expr_stmt|;
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
name|cr4
operator||=
name|CR4_FXSR
operator||
name|CR4_XMM
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
name|cpu_stdext_feature
operator|&
name|CPUID_STDEXT_FSGSBASE
condition|)
name|cr4
operator||=
name|CR4_FSGSBASE
expr_stmt|;
comment|/* 	 * Postpone enabling the SMEP on the boot CPU until the page 	 * tables are switched from the boot loader identity mapping 	 * to the kernel tables.  The boot loader enables the U bit in 	 * its tables. 	 */
if|if
condition|(
operator|!
name|IS_BSP
argument_list|()
operator|&&
operator|(
name|cpu_stdext_feature
operator|&
name|CPUID_STDEXT_SMEP
operator|)
condition|)
name|cr4
operator||=
name|CR4_SMEP
expr_stmt|;
name|load_cr4
argument_list|(
name|cr4
argument_list|)
expr_stmt|;
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
switch|switch
condition|(
name|cpu_vendor_id
condition|)
block|{
case|case
name|CPU_VENDOR_AMD
case|:
name|init_amd
argument_list|()
expr_stmt|;
break|break;
case|case
name|CPU_VENDOR_CENTAUR
case|:
name|init_via
argument_list|()
expr_stmt|;
break|break;
block|}
block|}
end_function

begin_function
name|void
name|initializecpucache
parameter_list|(
name|void
parameter_list|)
block|{
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
comment|/* 	 * XXXKIB: (temporary) hack to work around traps generated 	 * when CLFLUSHing APIC register window under virtualization 	 * environments.  These environments tend to disable the 	 * CPUID_SS feature even though the native CPU supports it. 	 */
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
name|vm_guest
operator|!=
name|VM_GUEST_NO
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
comment|/* 	 * Allow to disable CLFLUSH feature manually by 	 * hw.clflush_disable tunable. 	 */
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

