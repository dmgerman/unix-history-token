begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 Terrence R. Lambert.  * Copyright (c) 1982, 1987, 1990 The Regents of the University of California.  * Copyright (c) 1997 KATO Takenori.  * Copyright (c) 2001 Tamotsu Hattori.  * Copyright (c) 2001 Mitsuru IWASAKI.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: Id: machdep.c,v 1.193 1996/06/18 01:22:04 bde Exp  * $FreeBSD$  */
end_comment

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
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/power.h>
end_include

begin_include
include|#
directive|include
file|<machine/asmacros.h>
end_include

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_include
include|#
directive|include
file|<machine/cputypes.h>
end_include

begin_include
include|#
directive|include
file|<machine/segments.h>
end_include

begin_include
include|#
directive|include
file|<machine/specialreg.h>
end_include

begin_include
include|#
directive|include
file|<machine/md_var.h>
end_include

begin_include
include|#
directive|include
file|<amd64/isa/icu.h>
end_include

begin_include
include|#
directive|include
file|<amd64/isa/intr_machdep.h>
end_include

begin_comment
comment|/* XXX - should be in header file: */
end_comment

begin_function_decl
name|void
name|printcpuinfo
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
name|earlysetcpuclass
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|panicifcpuunsupported
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|print_AMD_features
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|print_AMD_info
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|print_AMD_assoc
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|cpu_class
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|cpu_exthigh
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Highest arg to extended CPUID */
end_comment

begin_decl_stmt
name|char
name|machine
index|[]
init|=
literal|"amd64"
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSCTL_STRING
argument_list|(
name|_hw
argument_list|,
name|HW_MACHINE
argument_list|,
name|machine
argument_list|,
name|CTLFLAG_RD
argument_list|,
name|machine
argument_list|,
literal|0
argument_list|,
literal|"Machine class"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|char
name|cpu_model
index|[
literal|128
index|]
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSCTL_STRING
argument_list|(
name|_hw
argument_list|,
name|HW_MODEL
argument_list|,
name|model
argument_list|,
name|CTLFLAG_RD
argument_list|,
name|cpu_model
argument_list|,
literal|0
argument_list|,
literal|"Machine model"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|int
name|hw_clockrate
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_hw
argument_list|,
name|OID_AUTO
argument_list|,
name|clockrate
argument_list|,
name|CTLFLAG_RD
argument_list|,
operator|&
name|hw_clockrate
argument_list|,
literal|0
argument_list|,
literal|"CPU instruction clock rate"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|char
name|cpu_brand
index|[
literal|48
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|cpu_nameclass
name|amd64_cpus
index|[]
init|=
block|{
block|{
literal|"Clawhammer"
block|,
name|CPUCLASS_K8
block|}
block|,
comment|/* CPU_CLAWHAMMER */
block|{
literal|"Sledgehammer"
block|,
name|CPUCLASS_K8
block|}
block|,
comment|/* CPU_SLEDGEHAMMER */
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|printcpuinfo
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
name|i
decl_stmt|;
name|char
modifier|*
name|brand
decl_stmt|;
name|cpu_class
operator|=
name|amd64_cpus
index|[
name|cpu
index|]
operator|.
name|cpu_class
expr_stmt|;
name|printf
argument_list|(
literal|"CPU: "
argument_list|)
expr_stmt|;
name|strncpy
argument_list|(
name|cpu_model
argument_list|,
name|amd64_cpus
index|[
name|cpu
index|]
operator|.
name|cpu_name
argument_list|,
sizeof|sizeof
argument_list|(
name|cpu_model
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Check for extended CPUID information and a processor name. */
if|if
condition|(
name|cpu_high
operator|>
literal|0
operator|&&
operator|(
name|strcmp
argument_list|(
name|cpu_vendor
argument_list|,
literal|"GenuineIntel"
argument_list|)
operator|==
literal|0
operator|||
name|strcmp
argument_list|(
name|cpu_vendor
argument_list|,
literal|"AuthenticAMD"
argument_list|)
operator|==
literal|0
operator|)
condition|)
block|{
name|do_cpuid
argument_list|(
literal|0x80000000
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
literal|0x80000000
condition|)
block|{
name|cpu_exthigh
operator|=
name|regs
index|[
literal|0
index|]
expr_stmt|;
if|if
condition|(
name|cpu_exthigh
operator|>=
literal|0x80000004
condition|)
block|{
name|brand
operator|=
name|cpu_brand
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0x80000002
init|;
name|i
operator|<
literal|0x80000005
condition|;
name|i
operator|++
control|)
block|{
name|do_cpuid
argument_list|(
name|i
argument_list|,
name|regs
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|brand
argument_list|,
name|regs
argument_list|,
sizeof|sizeof
argument_list|(
name|regs
argument_list|)
argument_list|)
expr_stmt|;
name|brand
operator|+=
sizeof|sizeof
argument_list|(
name|regs
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
if|if
condition|(
name|strcmp
argument_list|(
name|cpu_vendor
argument_list|,
literal|"GenuineIntel"
argument_list|)
operator|==
literal|0
condition|)
block|{
comment|/* How the hell did you get here?? */
name|strcat
argument_list|(
name|cpu_model
argument_list|,
literal|"Yamhill?"
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|strcmp
argument_list|(
name|cpu_vendor
argument_list|,
literal|"AuthenticAMD"
argument_list|)
operator|==
literal|0
condition|)
block|{
comment|/* 		 * Values taken from AMD Processor Recognition 		 * http://www.amd.com/K6/k6docs/pdf/20734g.pdf 		 * (also describes ``Features'' encodings. 		 */
name|strcpy
argument_list|(
name|cpu_model
argument_list|,
literal|"AMD "
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|cpu_id
operator|&
literal|0xF00
condition|)
block|{
case|case
literal|0xf00
case|:
name|strcat
argument_list|(
name|cpu_model
argument_list|,
literal|"AMD64 Processor"
argument_list|)
expr_stmt|;
break|break;
default|default:
name|strcat
argument_list|(
name|cpu_model
argument_list|,
literal|"Unknown"
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
comment|/* 	 * Replace cpu_model with cpu_brand minus leading spaces if 	 * we have one. 	 */
name|brand
operator|=
name|cpu_brand
expr_stmt|;
while|while
condition|(
operator|*
name|brand
operator|==
literal|' '
condition|)
operator|++
name|brand
expr_stmt|;
if|if
condition|(
operator|*
name|brand
operator|!=
literal|'\0'
condition|)
name|strcpy
argument_list|(
name|cpu_model
argument_list|,
name|brand
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%s ("
argument_list|,
name|cpu_model
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|cpu_class
condition|)
block|{
case|case
name|CPUCLASS_K8
case|:
name|hw_clockrate
operator|=
operator|(
name|tsc_freq
operator|+
literal|5000
operator|)
operator|/
literal|1000000
expr_stmt|;
name|printf
argument_list|(
literal|"%jd.%02d-MHz "
argument_list|,
call|(
name|intmax_t
call|)
argument_list|(
name|tsc_freq
operator|+
literal|4999
argument_list|)
operator|/
literal|1000000
argument_list|,
call|(
name|u_int
call|)
argument_list|(
operator|(
name|tsc_freq
operator|+
literal|4999
operator|)
operator|/
literal|10000
argument_list|)
operator|%
literal|100
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"K8"
argument_list|)
expr_stmt|;
break|break;
default|default:
name|printf
argument_list|(
literal|"Unknown"
argument_list|)
expr_stmt|;
comment|/* will panic below... */
block|}
name|printf
argument_list|(
literal|"-class CPU)\n"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|cpu_vendor
condition|)
name|printf
argument_list|(
literal|"  Origin = \"%s\""
argument_list|,
name|cpu_vendor
argument_list|)
expr_stmt|;
if|if
condition|(
name|cpu_id
condition|)
name|printf
argument_list|(
literal|"  Id = 0x%x"
argument_list|,
name|cpu_id
argument_list|)
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|cpu_vendor
argument_list|,
literal|"GenuineIntel"
argument_list|)
operator|==
literal|0
operator|||
name|strcmp
argument_list|(
name|cpu_vendor
argument_list|,
literal|"AuthenticAMD"
argument_list|)
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"  Stepping = %u"
argument_list|,
name|cpu_id
operator|&
literal|0xf
argument_list|)
expr_stmt|;
if|if
condition|(
name|cpu_high
operator|>
literal|0
condition|)
block|{
comment|/* 			 * Here we should probably set up flags indicating 			 * whether or not various features are available. 			 * The interesting ones are probably VME, PSE, PAE, 			 * and PGE.  The code already assumes without bothering 			 * to check that all CPUs>= Pentium have a TSC and 			 * MSRs. 			 */
name|printf
argument_list|(
literal|"\n  Features=0x%b"
argument_list|,
name|cpu_feature
argument_list|,
literal|"\020"
literal|"\001FPU"
comment|/* Integral FPU */
literal|"\002VME"
comment|/* Extended VM86 mode support */
literal|"\003DE"
comment|/* Debugging Extensions (CR4.DE) */
literal|"\004PSE"
comment|/* 4MByte page tables */
literal|"\005TSC"
comment|/* Timestamp counter */
literal|"\006MSR"
comment|/* Machine specific registers */
literal|"\007PAE"
comment|/* Physical address extension */
literal|"\010MCE"
comment|/* Machine Check support */
literal|"\011CX8"
comment|/* CMPEXCH8 instruction */
literal|"\012APIC"
comment|/* SMP local APIC */
literal|"\013oldMTRR"
comment|/* Previous implementation of MTRR */
literal|"\014SEP"
comment|/* Fast System Call */
literal|"\015MTRR"
comment|/* Memory Type Range Registers */
literal|"\016PGE"
comment|/* PG_G (global bit) support */
literal|"\017MCA"
comment|/* Machine Check Architecture */
literal|"\020CMOV"
comment|/* CMOV instruction */
literal|"\021PAT"
comment|/* Page attributes table */
literal|"\022PSE36"
comment|/* 36 bit address space support */
literal|"\023PN"
comment|/* Processor Serial number */
literal|"\024CLFLUSH"
comment|/* Has the CLFLUSH instruction */
literal|"\025<b20>"
literal|"\026DTS"
comment|/* Debug Trace Store */
literal|"\027ACPI"
comment|/* ACPI support */
literal|"\030MMX"
comment|/* MMX instructions */
literal|"\031FXSR"
comment|/* FXSAVE/FXRSTOR */
literal|"\032SSE"
comment|/* Streaming SIMD Extensions */
literal|"\033SSE2"
comment|/* Streaming SIMD Extensions #2 */
literal|"\034SS"
comment|/* Self snoop */
literal|"\035HTT"
comment|/* Hyperthreading (see EBX bit 16-23) */
literal|"\036TM"
comment|/* Thermal Monitor clock slowdown */
literal|"\037IA64"
comment|/* CPU can execute IA64 instructions */
literal|"\040PBE"
comment|/* Pending Break Enable */
argument_list|)
expr_stmt|;
comment|/* 			 * If this CPU supports hyperthreading then mention 			 * the number of logical CPU's it contains. 			 */
if|if
condition|(
name|cpu_feature
operator|&
name|CPUID_HTT
operator|&&
operator|(
name|cpu_procinfo
operator|&
name|CPUID_HTT_CORES
operator|)
operator|>>
literal|16
operator|>
literal|1
condition|)
name|printf
argument_list|(
literal|"\n  Hyperthreading: %d logical CPUs"
argument_list|,
operator|(
name|cpu_procinfo
operator|&
name|CPUID_HTT_CORES
operator|)
operator|>>
literal|16
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|strcmp
argument_list|(
name|cpu_vendor
argument_list|,
literal|"AuthenticAMD"
argument_list|)
operator|==
literal|0
operator|&&
name|cpu_exthigh
operator|>=
literal|0x80000001
condition|)
name|print_AMD_features
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|strcmp
argument_list|(
name|cpu_vendor
argument_list|,
literal|"CyrixInstead"
argument_list|)
operator|==
literal|0
condition|)
block|{ 	}
comment|/* Avoid ugly blank lines: only print newline when we have to. */
if|if
condition|(
operator|*
name|cpu_vendor
operator|||
name|cpu_id
condition|)
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|bootverbose
condition|)
return|return;
if|if
condition|(
name|strcmp
argument_list|(
name|cpu_vendor
argument_list|,
literal|"AuthenticAMD"
argument_list|)
operator|==
literal|0
condition|)
name|print_AMD_info
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|panicifcpuunsupported
parameter_list|(
name|void
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|HAMMER
error|#
directive|error
literal|"You need to specify a cpu type"
endif|#
directive|endif
comment|/* 	 * Now that we have told the user what they have, 	 * let them know if that machine type isn't configured. 	 */
switch|switch
condition|(
name|cpu_class
condition|)
block|{
case|case
name|CPUCLASS_X86
case|:
ifndef|#
directive|ifndef
name|HAMMER
case|case
name|CPUCLASS_K8
case|:
endif|#
directive|endif
name|panic
argument_list|(
literal|"CPU class not configured"
argument_list|)
expr_stmt|;
default|default:
break|break;
block|}
block|}
end_function

begin_comment
comment|/*  * Final stage of CPU identification. -- Should I check TI?  */
end_comment

begin_function
name|void
name|identify_cpu
parameter_list|(
name|void
parameter_list|)
block|{
name|u_int
name|regs
index|[
literal|4
index|]
decl_stmt|;
name|do_cpuid
argument_list|(
literal|0
argument_list|,
name|regs
argument_list|)
expr_stmt|;
name|cpu_high
operator|=
name|regs
index|[
literal|0
index|]
expr_stmt|;
operator|(
operator|(
name|u_int
operator|*
operator|)
operator|&
name|cpu_vendor
operator|)
index|[
literal|0
index|]
operator|=
name|regs
index|[
literal|1
index|]
expr_stmt|;
operator|(
operator|(
name|u_int
operator|*
operator|)
operator|&
name|cpu_vendor
operator|)
index|[
literal|1
index|]
operator|=
name|regs
index|[
literal|3
index|]
expr_stmt|;
operator|(
operator|(
name|u_int
operator|*
operator|)
operator|&
name|cpu_vendor
operator|)
index|[
literal|2
index|]
operator|=
name|regs
index|[
literal|2
index|]
expr_stmt|;
name|cpu_vendor
index|[
literal|12
index|]
operator|=
literal|'\0'
expr_stmt|;
name|do_cpuid
argument_list|(
literal|1
argument_list|,
name|regs
argument_list|)
expr_stmt|;
name|cpu_id
operator|=
name|regs
index|[
literal|0
index|]
expr_stmt|;
name|cpu_procinfo
operator|=
name|regs
index|[
literal|1
index|]
expr_stmt|;
name|cpu_feature
operator|=
name|regs
index|[
literal|3
index|]
expr_stmt|;
comment|/* XXX */
name|cpu
operator|=
name|CPU_CLAWHAMMER
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|print_AMD_assoc
parameter_list|(
name|int
name|i
parameter_list|)
block|{
if|if
condition|(
name|i
operator|==
literal|255
condition|)
name|printf
argument_list|(
literal|", fully associative\n"
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|", %d-way associative\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|print_AMD_info
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|cpu_exthigh
operator|>=
literal|0x80000005
condition|)
block|{
name|u_int
name|regs
index|[
literal|4
index|]
decl_stmt|;
name|do_cpuid
argument_list|(
literal|0x80000005
argument_list|,
name|regs
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Data TLB: %d entries"
argument_list|,
operator|(
name|regs
index|[
literal|1
index|]
operator|>>
literal|16
operator|)
operator|&
literal|0xff
argument_list|)
expr_stmt|;
name|print_AMD_assoc
argument_list|(
name|regs
index|[
literal|1
index|]
operator|>>
literal|24
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Instruction TLB: %d entries"
argument_list|,
name|regs
index|[
literal|1
index|]
operator|&
literal|0xff
argument_list|)
expr_stmt|;
name|print_AMD_assoc
argument_list|(
operator|(
name|regs
index|[
literal|1
index|]
operator|>>
literal|8
operator|)
operator|&
literal|0xff
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"L1 data cache: %d kbytes"
argument_list|,
name|regs
index|[
literal|2
index|]
operator|>>
literal|24
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|", %d bytes/line"
argument_list|,
name|regs
index|[
literal|2
index|]
operator|&
literal|0xff
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|", %d lines/tag"
argument_list|,
operator|(
name|regs
index|[
literal|2
index|]
operator|>>
literal|8
operator|)
operator|&
literal|0xff
argument_list|)
expr_stmt|;
name|print_AMD_assoc
argument_list|(
operator|(
name|regs
index|[
literal|2
index|]
operator|>>
literal|16
operator|)
operator|&
literal|0xff
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"L1 instruction cache: %d kbytes"
argument_list|,
name|regs
index|[
literal|3
index|]
operator|>>
literal|24
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|", %d bytes/line"
argument_list|,
name|regs
index|[
literal|3
index|]
operator|&
literal|0xff
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|", %d lines/tag"
argument_list|,
operator|(
name|regs
index|[
literal|3
index|]
operator|>>
literal|8
operator|)
operator|&
literal|0xff
argument_list|)
expr_stmt|;
name|print_AMD_assoc
argument_list|(
operator|(
name|regs
index|[
literal|3
index|]
operator|>>
literal|16
operator|)
operator|&
literal|0xff
argument_list|)
expr_stmt|;
if|if
condition|(
name|cpu_exthigh
operator|>=
literal|0x80000006
condition|)
block|{
comment|/* K6-III only */
name|do_cpuid
argument_list|(
literal|0x80000006
argument_list|,
name|regs
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"L2 internal cache: %d kbytes"
argument_list|,
name|regs
index|[
literal|2
index|]
operator|>>
literal|16
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|", %d bytes/line"
argument_list|,
name|regs
index|[
literal|2
index|]
operator|&
literal|0xff
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|", %d lines/tag"
argument_list|,
operator|(
name|regs
index|[
literal|2
index|]
operator|>>
literal|8
operator|)
operator|&
literal|0x0f
argument_list|)
expr_stmt|;
name|print_AMD_assoc
argument_list|(
operator|(
name|regs
index|[
literal|2
index|]
operator|>>
literal|12
operator|)
operator|&
literal|0x0f
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function

begin_function
specifier|static
name|void
name|print_AMD_features
parameter_list|(
name|void
parameter_list|)
block|{
name|u_int
name|regs
index|[
literal|4
index|]
decl_stmt|;
comment|/* 	 * Values taken from AMD Processor Recognition 	 * http://www.amd.com/products/cpg/athlon/techdocs/pdf/20734.pdf 	 */
name|do_cpuid
argument_list|(
literal|0x80000001
argument_list|,
name|regs
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n  AMD Features=0x%b"
argument_list|,
name|regs
index|[
literal|3
index|]
operator|&
operator|~
name|cpu_feature
argument_list|,
literal|"\020"
comment|/* in hex */
literal|"\001FPU"
comment|/* Integral FPU */
literal|"\002VME"
comment|/* Extended VM86 mode support */
literal|"\003DE"
comment|/* Debug extensions */
literal|"\004PSE"
comment|/* 4MByte page tables */
literal|"\005TSC"
comment|/* Timestamp counter */
literal|"\006MSR"
comment|/* Machine specific registers */
literal|"\007PAE"
comment|/* Physical address extension */
literal|"\010MCE"
comment|/* Machine Check support */
literal|"\011CX8"
comment|/* CMPEXCH8 instruction */
literal|"\012APIC"
comment|/* SMP local APIC */
literal|"\013<b10>"
literal|"\014SYSCALL"
comment|/* SYSENTER/SYSEXIT instructions */
literal|"\015MTRR"
comment|/* Memory Type Range Registers */
literal|"\016PGE"
comment|/* PG_G (global bit) support */
literal|"\017MCA"
comment|/* Machine Check Architecture */
literal|"\020ICMOV"
comment|/* CMOV instruction */
literal|"\021PAT"
comment|/* Page attributes table */
literal|"\022PGE36"
comment|/* 36 bit address space support */
literal|"\023RSVD"
comment|/* Reserved, unknown */
literal|"\024MP"
comment|/* Multiprocessor Capable */
literal|"\025<b20>"
literal|"\026<b21>"
literal|"\027AMIE"
comment|/* AMD MMX Instruction Extensions */
literal|"\030MMX"
literal|"\031FXSAVE"
comment|/* FXSAVE/FXRSTOR */
literal|"\032<b25>"
literal|"\033<b26>"
literal|"\034<b27>"
literal|"\035<b28>"
literal|"\036<b29>"
literal|"\037DSP"
comment|/* AMD 3DNow! Instruction Extensions */
literal|"\0403DNow!"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

