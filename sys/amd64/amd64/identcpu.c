begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 Terrence R. Lambert.  * Copyright (c) 1982, 1987, 1990 The Regents of the University of California.  * Copyright (c) 1997 KATO Takenori.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: Id: machdep.c,v 1.193 1996/06/18 01:22:04 bde Exp  */
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
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/cpu.h>
end_include

begin_include
include|#
directive|include
file|<sys/eventhandler.h>
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
file|<machine/frame.h>
end_include

begin_include
include|#
directive|include
file|<machine/intr_machdep.h>
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
file|<amd64/vmm/intel/vmx_controls.h>
end_include

begin_include
include|#
directive|include
file|<x86/isa/icu.h>
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
name|u_int
name|find_cpu_vendor_id
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

begin_function_decl
specifier|static
name|void
name|print_via_padlock_info
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|print_vmx_info
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|cpu_class
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|machine
index|[]
init|=
literal|"amd64"
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SCTL_MASK32
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|adaptive_machine_arch
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|int
name|sysctl_hw_machine
parameter_list|(
name|SYSCTL_HANDLER_ARGS
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|SCTL_MASK32
specifier|static
specifier|const
name|char
name|machine32
index|[]
init|=
literal|"i386"
decl_stmt|;
endif|#
directive|endif
name|int
name|error
decl_stmt|;
ifdef|#
directive|ifdef
name|SCTL_MASK32
if|if
condition|(
operator|(
name|req
operator|->
name|flags
operator|&
name|SCTL_MASK32
operator|)
operator|!=
literal|0
operator|&&
name|adaptive_machine_arch
condition|)
name|error
operator|=
name|SYSCTL_OUT
argument_list|(
name|req
argument_list|,
name|machine32
argument_list|,
sizeof|sizeof
argument_list|(
name|machine32
argument_list|)
argument_list|)
expr_stmt|;
else|else
endif|#
directive|endif
name|error
operator|=
name|SYSCTL_OUT
argument_list|(
name|req
argument_list|,
name|machine
argument_list|,
sizeof|sizeof
argument_list|(
name|machine
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_expr_stmt
name|SYSCTL_PROC
argument_list|(
name|_hw
argument_list|,
name|HW_MACHINE
argument_list|,
name|machine
argument_list|,
name|CTLTYPE_STRING
operator||
name|CTLFLAG_RD
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|,
name|sysctl_hw_machine
argument_list|,
literal|"A"
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
name|eventhandler_tag
name|tsc_post_tag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|cpu_brand
index|[
literal|48
index|]
decl_stmt|;
end_decl_stmt

begin_struct
specifier|static
struct|struct
block|{
name|char
modifier|*
name|cpu_name
decl_stmt|;
name|int
name|cpu_class
decl_stmt|;
block|}
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
struct|;
end_struct

begin_struct
specifier|static
struct|struct
block|{
name|char
modifier|*
name|vendor
decl_stmt|;
name|u_int
name|vendor_id
decl_stmt|;
block|}
name|cpu_vendors
index|[]
init|=
block|{
block|{
name|INTEL_VENDOR_ID
block|,
name|CPU_VENDOR_INTEL
block|}
block|,
comment|/* GenuineIntel */
block|{
name|AMD_VENDOR_ID
block|,
name|CPU_VENDOR_AMD
block|}
block|,
comment|/* AuthenticAMD */
block|{
name|CENTAUR_VENDOR_ID
block|,
name|CPU_VENDOR_CENTAUR
block|}
block|,
comment|/* CentaurHauls */
block|}
struct|;
end_struct

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
switch|switch
condition|(
name|cpu_vendor_id
condition|)
block|{
case|case
name|CPU_VENDOR_INTEL
case|:
comment|/* Please make up your mind folks! */
name|strcat
argument_list|(
name|cpu_model
argument_list|,
literal|"EM64T"
argument_list|)
expr_stmt|;
break|break;
case|case
name|CPU_VENDOR_AMD
case|:
comment|/* 		 * Values taken from AMD Processor Recognition 		 * http://www.amd.com/K6/k6docs/pdf/20734g.pdf 		 * (also describes ``Features'' encodings. 		 */
name|strcpy
argument_list|(
name|cpu_model
argument_list|,
literal|"AMD "
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|cpu_id
operator|&
literal|0xf00
operator|)
operator|==
literal|0xf00
condition|)
name|strcat
argument_list|(
name|cpu_model
argument_list|,
literal|"AMD64 Processor"
argument_list|)
expr_stmt|;
else|else
name|strcat
argument_list|(
name|cpu_model
argument_list|,
literal|"Unknown"
argument_list|)
expr_stmt|;
break|break;
case|case
name|CPU_VENDOR_CENTAUR
case|:
name|strcpy
argument_list|(
name|cpu_model
argument_list|,
literal|"VIA "
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|cpu_id
operator|&
literal|0xff0
operator|)
operator|==
literal|0x6f0
condition|)
name|strcat
argument_list|(
name|cpu_model
argument_list|,
literal|"Nano Processor"
argument_list|)
expr_stmt|;
else|else
name|strcat
argument_list|(
name|cpu_model
argument_list|,
literal|"Unknown"
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
if|if
condition|(
name|tsc_freq
operator|!=
literal|0
condition|)
block|{
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
block|}
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
literal|"  Origin=\"%s\""
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
literal|"  Id=0x%x"
argument_list|,
name|cpu_id
argument_list|)
expr_stmt|;
if|if
condition|(
name|cpu_vendor_id
operator|==
name|CPU_VENDOR_INTEL
operator|||
name|cpu_vendor_id
operator|==
name|CPU_VENDOR_AMD
operator|||
name|cpu_vendor_id
operator|==
name|CPU_VENDOR_CENTAUR
condition|)
block|{
name|printf
argument_list|(
literal|"  Family=0x%x"
argument_list|,
name|CPUID_TO_FAMILY
argument_list|(
name|cpu_id
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"  Model=0x%x"
argument_list|,
name|CPUID_TO_MODEL
argument_list|(
name|cpu_id
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"  Stepping=%u"
argument_list|,
name|cpu_id
operator|&
name|CPUID_STEPPING
argument_list|)
expr_stmt|;
comment|/* 		 * AMD CPUID Specification 		 * http://support.amd.com/us/Embedded_TechDocs/25481.pdf 		 * 		 * Intel Processor Identification and CPUID Instruction 		 * http://www.intel.com/assets/pdf/appnote/241618.pdf 		 */
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
if|if
condition|(
name|cpu_feature2
operator|!=
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"\n  Features2=0x%b"
argument_list|,
name|cpu_feature2
argument_list|,
literal|"\020"
literal|"\001SSE3"
comment|/* SSE3 */
literal|"\002PCLMULQDQ"
comment|/* Carry-Less Mul Quadword */
literal|"\003DTES64"
comment|/* 64-bit Debug Trace */
literal|"\004MON"
comment|/* MONITOR/MWAIT Instructions */
literal|"\005DS_CPL"
comment|/* CPL Qualified Debug Store */
literal|"\006VMX"
comment|/* Virtual Machine Extensions */
literal|"\007SMX"
comment|/* Safer Mode Extensions */
literal|"\010EST"
comment|/* Enhanced SpeedStep */
literal|"\011TM2"
comment|/* Thermal Monitor 2 */
literal|"\012SSSE3"
comment|/* SSSE3 */
literal|"\013CNXT-ID"
comment|/* L1 context ID available */
literal|"\014<b11>"
literal|"\015FMA"
comment|/* Fused Multiply Add */
literal|"\016CX16"
comment|/* CMPXCHG16B Instruction */
literal|"\017xTPR"
comment|/* Send Task Priority Messages*/
literal|"\020PDCM"
comment|/* Perf/Debug Capability MSR */
literal|"\021<b16>"
literal|"\022PCID"
comment|/* Process-context Identifiers*/
literal|"\023DCA"
comment|/* Direct Cache Access */
literal|"\024SSE4.1"
comment|/* SSE 4.1 */
literal|"\025SSE4.2"
comment|/* SSE 4.2 */
literal|"\026x2APIC"
comment|/* xAPIC Extensions */
literal|"\027MOVBE"
comment|/* MOVBE Instruction */
literal|"\030POPCNT"
comment|/* POPCNT Instruction */
literal|"\031TSCDLT"
comment|/* TSC-Deadline Timer */
literal|"\032AESNI"
comment|/* AES Crypto */
literal|"\033XSAVE"
comment|/* XSAVE/XRSTOR States */
literal|"\034OSXSAVE"
comment|/* OS-Enabled State Management*/
literal|"\035AVX"
comment|/* Advanced Vector Extensions */
literal|"\036F16C"
comment|/* Half-precision conversions */
literal|"\037RDRAND"
comment|/* RDRAND Instruction */
literal|"\040HV"
comment|/* Hypervisor */
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|amd_feature
operator|!=
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"\n  AMD Features=0x%b"
argument_list|,
name|amd_feature
argument_list|,
literal|"\020"
comment|/* in hex */
literal|"\001<s0>"
comment|/* Same */
literal|"\002<s1>"
comment|/* Same */
literal|"\003<s2>"
comment|/* Same */
literal|"\004<s3>"
comment|/* Same */
literal|"\005<s4>"
comment|/* Same */
literal|"\006<s5>"
comment|/* Same */
literal|"\007<s6>"
comment|/* Same */
literal|"\010<s7>"
comment|/* Same */
literal|"\011<s8>"
comment|/* Same */
literal|"\012<s9>"
comment|/* Same */
literal|"\013<b10>"
comment|/* Undefined */
literal|"\014SYSCALL"
comment|/* Have SYSCALL/SYSRET */
literal|"\015<s12>"
comment|/* Same */
literal|"\016<s13>"
comment|/* Same */
literal|"\017<s14>"
comment|/* Same */
literal|"\020<s15>"
comment|/* Same */
literal|"\021<s16>"
comment|/* Same */
literal|"\022<s17>"
comment|/* Same */
literal|"\023<b18>"
comment|/* Reserved, unknown */
literal|"\024MP"
comment|/* Multiprocessor Capable */
literal|"\025NX"
comment|/* Has EFER.NXE, NX */
literal|"\026<b21>"
comment|/* Undefined */
literal|"\027MMX+"
comment|/* AMD MMX Extensions */
literal|"\030<s23>"
comment|/* Same */
literal|"\031<s24>"
comment|/* Same */
literal|"\032FFXSR"
comment|/* Fast FXSAVE/FXRSTOR */
literal|"\033Page1GB"
comment|/* 1-GB large page support */
literal|"\034RDTSCP"
comment|/* RDTSCP */
literal|"\035<b28>"
comment|/* Undefined */
literal|"\036LM"
comment|/* 64 bit long mode */
literal|"\0373DNow!+"
comment|/* AMD 3DNow! Extensions */
literal|"\0403DNow!"
comment|/* AMD 3DNow! */
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|amd_feature2
operator|!=
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"\n  AMD Features2=0x%b"
argument_list|,
name|amd_feature2
argument_list|,
literal|"\020"
literal|"\001LAHF"
comment|/* LAHF/SAHF in long mode */
literal|"\002CMP"
comment|/* CMP legacy */
literal|"\003SVM"
comment|/* Secure Virtual Mode */
literal|"\004ExtAPIC"
comment|/* Extended APIC register */
literal|"\005CR8"
comment|/* CR8 in legacy mode */
literal|"\006ABM"
comment|/* LZCNT instruction */
literal|"\007SSE4A"
comment|/* SSE4A */
literal|"\010MAS"
comment|/* Misaligned SSE mode */
literal|"\011Prefetch"
comment|/* 3DNow! Prefetch/PrefetchW */
literal|"\012OSVW"
comment|/* OS visible workaround */
literal|"\013IBS"
comment|/* Instruction based sampling */
literal|"\014XOP"
comment|/* XOP extended instructions */
literal|"\015SKINIT"
comment|/* SKINIT/STGI */
literal|"\016WDT"
comment|/* Watchdog timer */
literal|"\017<b14>"
literal|"\020LWP"
comment|/* Lightweight Profiling */
literal|"\021FMA4"
comment|/* 4-operand FMA instructions */
literal|"\022TCE"
comment|/* Translation Cache Extension */
literal|"\023<b18>"
literal|"\024NodeId"
comment|/* NodeId MSR support */
literal|"\025<b20>"
literal|"\026TBM"
comment|/* Trailing Bit Manipulation */
literal|"\027Topology"
comment|/* Topology Extensions */
literal|"\030PCXC"
comment|/* Core perf count */
literal|"\031PNXC"
comment|/* NB perf count */
literal|"\032<b25>"
literal|"\033DBE"
comment|/* Data Breakpoint extension */
literal|"\034PTSC"
comment|/* Performance TSC */
literal|"\035PL2I"
comment|/* L2I perf count */
literal|"\036<b29>"
literal|"\037<b30>"
literal|"\040<b31>"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|cpu_stdext_feature
operator|!=
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"\n  Structured Extended Features=0x%b"
argument_list|,
name|cpu_stdext_feature
argument_list|,
literal|"\020"
comment|/* RDFSBASE/RDGSBASE/WRFSBASE/WRGSBASE */
literal|"\001FSGSBASE"
literal|"\002TSCADJ"
comment|/* Bit Manipulation Instructions */
literal|"\004BMI1"
comment|/* Hardware Lock Elision */
literal|"\005HLE"
comment|/* Advanced Vector Instructions 2 */
literal|"\006AVX2"
comment|/* Supervisor Mode Execution Prot. */
literal|"\010SMEP"
comment|/* Bit Manipulation Instructions */
literal|"\011BMI2"
literal|"\012ERMS"
comment|/* Invalidate Processor Context ID */
literal|"\013INVPCID"
comment|/* Restricted Transactional Memory */
literal|"\014RTM"
comment|/* Intel Memory Protection Extensions */
literal|"\017MPX"
comment|/* AVX512 Foundation */
literal|"\021AVX512F"
comment|/* Enhanced NRBG */
literal|"\023RDSEED"
comment|/* ADCX + ADOX */
literal|"\024ADX"
comment|/* Supervisor Mode Access Prevention */
literal|"\025SMAP"
literal|"\030CLFLUSHOPT"
literal|"\032PROCTRACE"
literal|"\033AVX512PF"
literal|"\034AVX512ER"
literal|"\035AVX512CD"
literal|"\036SHA"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|via_feature_rng
operator|!=
literal|0
operator|||
name|via_feature_xcrypt
operator|!=
literal|0
condition|)
name|print_via_padlock_info
argument_list|()
expr_stmt|;
if|if
condition|(
name|cpu_feature2
operator|&
name|CPUID2_VMX
condition|)
name|print_vmx_info
argument_list|()
expr_stmt|;
if|if
condition|(
operator|(
name|cpu_feature
operator|&
name|CPUID_HTT
operator|)
operator|&&
name|cpu_vendor_id
operator|==
name|CPU_VENDOR_AMD
condition|)
name|cpu_feature
operator|&=
operator|~
name|CPUID_HTT
expr_stmt|;
comment|/* 			 * If this CPU supports P-state invariant TSC then 			 * mention the capability. 			 */
if|if
condition|(
name|tsc_is_invariant
condition|)
block|{
name|printf
argument_list|(
literal|"\n  TSC: P-state invariant"
argument_list|)
expr_stmt|;
if|if
condition|(
name|tsc_perf_stat
condition|)
name|printf
argument_list|(
literal|", performance statistics"
argument_list|)
expr_stmt|;
block|}
block|}
block|}
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
name|cpu_vendor_id
operator|==
name|CPU_VENDOR_AMD
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
comment|/* Update TSC freq with the value indicated by the caller. */
end_comment

begin_function
specifier|static
name|void
name|tsc_freq_changed
parameter_list|(
name|void
modifier|*
name|arg
name|__unused
parameter_list|,
specifier|const
name|struct
name|cf_level
modifier|*
name|level
parameter_list|,
name|int
name|status
parameter_list|)
block|{
comment|/* If there was an error during the transition, don't do anything. */
if|if
condition|(
name|status
operator|!=
literal|0
condition|)
return|return;
comment|/* Total setting for this level gives the new frequency in MHz. */
name|hw_clockrate
operator|=
name|level
operator|->
name|total_set
operator|.
name|freq
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|hook_tsc_freq
parameter_list|(
name|void
modifier|*
name|arg
name|__unused
parameter_list|)
block|{
if|if
condition|(
name|tsc_is_invariant
condition|)
return|return;
name|tsc_post_tag
operator|=
name|EVENTHANDLER_REGISTER
argument_list|(
name|cpufreq_post_change
argument_list|,
name|tsc_freq_changed
argument_list|,
name|NULL
argument_list|,
name|EVENTHANDLER_PRI_ANY
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|SYSINIT
argument_list|(
name|hook_tsc_freq
argument_list|,
name|SI_SUB_CONFIGURE
argument_list|,
name|SI_ORDER_ANY
argument_list|,
name|hook_tsc_freq
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Final stage of CPU identification.  */
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
decl_stmt|,
name|cpu_stdext_disable
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
name|cpu_vendor_id
operator|=
name|find_cpu_vendor_id
argument_list|()
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
name|cpu_feature2
operator|=
name|regs
index|[
literal|2
index|]
expr_stmt|;
comment|/* 	 * Clear "Limit CPUID Maxval" bit and get the largest standard CPUID 	 * function number again if it is set from BIOS.  It is necessary 	 * for probing correct CPU topology later. 	 * XXX This is only done on the BSP package. 	 */
if|if
condition|(
name|cpu_vendor_id
operator|==
name|CPU_VENDOR_INTEL
operator|&&
name|cpu_high
operator|>
literal|0
operator|&&
name|cpu_high
operator|<
literal|4
condition|)
block|{
name|uint64_t
name|msr
decl_stmt|;
name|msr
operator|=
name|rdmsr
argument_list|(
name|MSR_IA32_MISC_ENABLE
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|msr
operator|&
literal|0x400000ULL
operator|)
operator|!=
literal|0
condition|)
block|{
name|wrmsr
argument_list|(
name|MSR_IA32_MISC_ENABLE
argument_list|,
name|msr
operator|&
operator|~
literal|0x400000ULL
argument_list|)
expr_stmt|;
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
block|}
block|}
if|if
condition|(
name|cpu_high
operator|>=
literal|5
operator|&&
operator|(
name|cpu_feature2
operator|&
name|CPUID2_MON
operator|)
operator|!=
literal|0
condition|)
block|{
name|do_cpuid
argument_list|(
literal|5
argument_list|,
name|regs
argument_list|)
expr_stmt|;
name|cpu_mon_mwait_flags
operator|=
name|regs
index|[
literal|2
index|]
expr_stmt|;
name|cpu_mon_min_size
operator|=
name|regs
index|[
literal|0
index|]
operator|&
name|CPUID5_MON_MIN_SIZE
expr_stmt|;
name|cpu_mon_max_size
operator|=
name|regs
index|[
literal|1
index|]
operator|&
name|CPUID5_MON_MAX_SIZE
expr_stmt|;
block|}
if|if
condition|(
name|cpu_high
operator|>=
literal|7
condition|)
block|{
name|cpuid_count
argument_list|(
literal|7
argument_list|,
literal|0
argument_list|,
name|regs
argument_list|)
expr_stmt|;
name|cpu_stdext_feature
operator|=
name|regs
index|[
literal|1
index|]
expr_stmt|;
comment|/* 		 * Some hypervisors fail to filter out unsupported 		 * extended features.  For now, disable the 		 * extensions, activation of which requires setting a 		 * bit in CR4, and which VM monitors do not support. 		 */
if|if
condition|(
name|cpu_feature2
operator|&
name|CPUID2_HV
condition|)
block|{
name|cpu_stdext_disable
operator|=
name|CPUID_STDEXT_FSGSBASE
operator||
name|CPUID_STDEXT_SMEP
expr_stmt|;
block|}
else|else
name|cpu_stdext_disable
operator|=
literal|0
expr_stmt|;
name|TUNABLE_INT_FETCH
argument_list|(
literal|"hw.cpu_stdext_disable"
argument_list|,
operator|&
name|cpu_stdext_disable
argument_list|)
expr_stmt|;
name|cpu_stdext_feature
operator|&=
operator|~
name|cpu_stdext_disable
expr_stmt|;
block|}
if|if
condition|(
name|cpu_vendor_id
operator|==
name|CPU_VENDOR_INTEL
operator|||
name|cpu_vendor_id
operator|==
name|CPU_VENDOR_AMD
operator|||
name|cpu_vendor_id
operator|==
name|CPU_VENDOR_CENTAUR
condition|)
block|{
name|do_cpuid
argument_list|(
literal|0x80000000
argument_list|,
name|regs
argument_list|)
expr_stmt|;
name|cpu_exthigh
operator|=
name|regs
index|[
literal|0
index|]
expr_stmt|;
block|}
if|if
condition|(
name|cpu_exthigh
operator|>=
literal|0x80000001
condition|)
block|{
name|do_cpuid
argument_list|(
literal|0x80000001
argument_list|,
name|regs
argument_list|)
expr_stmt|;
name|amd_feature
operator|=
name|regs
index|[
literal|3
index|]
operator|&
operator|~
operator|(
name|cpu_feature
operator|&
literal|0x0183f3ff
operator|)
expr_stmt|;
name|amd_feature2
operator|=
name|regs
index|[
literal|2
index|]
expr_stmt|;
block|}
if|if
condition|(
name|cpu_exthigh
operator|>=
literal|0x80000007
condition|)
block|{
name|do_cpuid
argument_list|(
literal|0x80000007
argument_list|,
name|regs
argument_list|)
expr_stmt|;
name|amd_pminfo
operator|=
name|regs
index|[
literal|3
index|]
expr_stmt|;
block|}
if|if
condition|(
name|cpu_exthigh
operator|>=
literal|0x80000008
condition|)
block|{
name|do_cpuid
argument_list|(
literal|0x80000008
argument_list|,
name|regs
argument_list|)
expr_stmt|;
name|cpu_procinfo2
operator|=
name|regs
index|[
literal|2
index|]
expr_stmt|;
block|}
comment|/* XXX */
name|cpu
operator|=
name|CPU_CLAWHAMMER
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|u_int
name|find_cpu_vendor_id
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
argument_list|(
name|cpu_vendors
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|cpu_vendors
index|[
literal|0
index|]
argument_list|)
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|strcmp
argument_list|(
name|cpu_vendor
argument_list|,
name|cpu_vendors
index|[
name|i
index|]
operator|.
name|vendor
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
name|cpu_vendors
index|[
name|i
index|]
operator|.
name|vendor_id
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
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
name|print_AMD_l2_assoc
parameter_list|(
name|int
name|i
parameter_list|)
block|{
switch|switch
condition|(
name|i
operator|&
literal|0x0f
condition|)
block|{
case|case
literal|0
case|:
name|printf
argument_list|(
literal|", disabled/not present\n"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|1
case|:
name|printf
argument_list|(
literal|", direct mapped\n"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|2
case|:
name|printf
argument_list|(
literal|", 2-way associative\n"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|4
case|:
name|printf
argument_list|(
literal|", 4-way associative\n"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|6
case|:
name|printf
argument_list|(
literal|", 8-way associative\n"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|8
case|:
name|printf
argument_list|(
literal|", 16-way associative\n"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|15
case|:
name|printf
argument_list|(
literal|", fully associative\n"
argument_list|)
expr_stmt|;
break|break;
default|default:
name|printf
argument_list|(
literal|", reserved configuration\n"
argument_list|)
expr_stmt|;
break|break;
block|}
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
name|u_int
name|regs
index|[
literal|4
index|]
decl_stmt|;
if|if
condition|(
name|cpu_exthigh
operator|<
literal|0x80000005
condition|)
return|return;
name|do_cpuid
argument_list|(
literal|0x80000005
argument_list|,
name|regs
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"L1 2MB data TLB: %d entries"
argument_list|,
operator|(
name|regs
index|[
literal|0
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
literal|0
index|]
operator|>>
literal|24
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"L1 2MB instruction TLB: %d entries"
argument_list|,
name|regs
index|[
literal|0
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
literal|0
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
literal|"L1 4KB data TLB: %d entries"
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
literal|"L1 4KB instruction TLB: %d entries"
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
name|do_cpuid
argument_list|(
literal|0x80000006
argument_list|,
name|regs
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|regs
index|[
literal|0
index|]
operator|>>
literal|16
operator|)
operator|!=
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"L2 2MB data TLB: %d entries"
argument_list|,
operator|(
name|regs
index|[
literal|0
index|]
operator|>>
literal|16
operator|)
operator|&
literal|0xfff
argument_list|)
expr_stmt|;
name|print_AMD_l2_assoc
argument_list|(
name|regs
index|[
literal|0
index|]
operator|>>
literal|28
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"L2 2MB instruction TLB: %d entries"
argument_list|,
name|regs
index|[
literal|0
index|]
operator|&
literal|0xfff
argument_list|)
expr_stmt|;
name|print_AMD_l2_assoc
argument_list|(
operator|(
name|regs
index|[
literal|0
index|]
operator|>>
literal|28
operator|)
operator|&
literal|0xf
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|printf
argument_list|(
literal|"L2 2MB unified TLB: %d entries"
argument_list|,
name|regs
index|[
literal|0
index|]
operator|&
literal|0xfff
argument_list|)
expr_stmt|;
name|print_AMD_l2_assoc
argument_list|(
operator|(
name|regs
index|[
literal|0
index|]
operator|>>
literal|28
operator|)
operator|&
literal|0xf
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|regs
index|[
literal|1
index|]
operator|>>
literal|16
operator|)
operator|!=
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"L2 4KB data TLB: %d entries"
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
literal|0xfff
argument_list|)
expr_stmt|;
name|print_AMD_l2_assoc
argument_list|(
name|regs
index|[
literal|1
index|]
operator|>>
literal|28
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"L2 4KB instruction TLB: %d entries"
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
literal|0xfff
argument_list|)
expr_stmt|;
name|print_AMD_l2_assoc
argument_list|(
operator|(
name|regs
index|[
literal|1
index|]
operator|>>
literal|28
operator|)
operator|&
literal|0xf
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|printf
argument_list|(
literal|"L2 4KB unified TLB: %d entries"
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
literal|0xfff
argument_list|)
expr_stmt|;
name|print_AMD_l2_assoc
argument_list|(
operator|(
name|regs
index|[
literal|1
index|]
operator|>>
literal|28
operator|)
operator|&
literal|0xf
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"L2 unified cache: %d kbytes"
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
name|print_AMD_l2_assoc
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
comment|/* 	 * Opteron Rev E shows a bug as in very rare occasions a read memory  	 * barrier is not performed as expected if it is followed by a  	 * non-atomic read-modify-write instruction.   	 * As long as that bug pops up very rarely (intensive machine usage 	 * on other operating systems generally generates one unexplainable  	 * crash any 2 months) and as long as a model specific fix would be 	 * impratical at this stage, print out a warning string if the broken 	 * model and family are identified. 	 */
if|if
condition|(
name|CPUID_TO_FAMILY
argument_list|(
name|cpu_id
argument_list|)
operator|==
literal|0xf
operator|&&
name|CPUID_TO_MODEL
argument_list|(
name|cpu_id
argument_list|)
operator|>=
literal|0x20
operator|&&
name|CPUID_TO_MODEL
argument_list|(
name|cpu_id
argument_list|)
operator|<=
literal|0x3f
condition|)
name|printf
argument_list|(
literal|"WARNING: This architecture revision has known SMP "
literal|"hardware bugs which may cause random instability\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|print_via_padlock_info
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
literal|0xc0000001
argument_list|,
name|regs
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n  VIA Padlock Features=0x%b"
argument_list|,
name|regs
index|[
literal|3
index|]
argument_list|,
literal|"\020"
literal|"\003RNG"
comment|/* RNG */
literal|"\007AES"
comment|/* ACE */
literal|"\011AES-CTR"
comment|/* ACE2 */
literal|"\013SHA1,SHA256"
comment|/* PHE */
literal|"\015RSA"
comment|/* PMM */
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|uint32_t
name|vmx_settable
parameter_list|(
name|uint64_t
name|basic
parameter_list|,
name|int
name|msr
parameter_list|,
name|int
name|true_msr
parameter_list|)
block|{
name|uint64_t
name|val
decl_stmt|;
if|if
condition|(
name|basic
operator|&
operator|(
literal|1UL
operator|<<
literal|55
operator|)
condition|)
name|val
operator|=
name|rdmsr
argument_list|(
name|true_msr
argument_list|)
expr_stmt|;
else|else
name|val
operator|=
name|rdmsr
argument_list|(
name|msr
argument_list|)
expr_stmt|;
comment|/* Just report the controls that can be set to 1. */
return|return
operator|(
name|val
operator|>>
literal|32
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|print_vmx_info
parameter_list|(
name|void
parameter_list|)
block|{
name|uint64_t
name|basic
decl_stmt|,
name|msr
decl_stmt|;
name|uint32_t
name|entry
decl_stmt|,
name|exit
decl_stmt|,
name|mask
decl_stmt|,
name|pin
decl_stmt|,
name|proc
decl_stmt|,
name|proc2
decl_stmt|;
name|int
name|comma
decl_stmt|;
name|printf
argument_list|(
literal|"\n  VT-x: "
argument_list|)
expr_stmt|;
name|msr
operator|=
name|rdmsr
argument_list|(
name|MSR_IA32_FEATURE_CONTROL
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|msr
operator|&
name|IA32_FEATURE_CONTROL_VMX_EN
operator|)
condition|)
name|printf
argument_list|(
literal|"(disabled in BIOS) "
argument_list|)
expr_stmt|;
name|basic
operator|=
name|rdmsr
argument_list|(
name|MSR_VMX_BASIC
argument_list|)
expr_stmt|;
name|pin
operator|=
name|vmx_settable
argument_list|(
name|basic
argument_list|,
name|MSR_VMX_PINBASED_CTLS
argument_list|,
name|MSR_VMX_TRUE_PINBASED_CTLS
argument_list|)
expr_stmt|;
name|proc
operator|=
name|vmx_settable
argument_list|(
name|basic
argument_list|,
name|MSR_VMX_PROCBASED_CTLS
argument_list|,
name|MSR_VMX_TRUE_PROCBASED_CTLS
argument_list|)
expr_stmt|;
if|if
condition|(
name|proc
operator|&
name|PROCBASED_SECONDARY_CONTROLS
condition|)
name|proc2
operator|=
name|vmx_settable
argument_list|(
name|basic
argument_list|,
name|MSR_VMX_PROCBASED_CTLS2
argument_list|,
name|MSR_VMX_PROCBASED_CTLS2
argument_list|)
expr_stmt|;
else|else
name|proc2
operator|=
literal|0
expr_stmt|;
name|exit
operator|=
name|vmx_settable
argument_list|(
name|basic
argument_list|,
name|MSR_VMX_EXIT_CTLS
argument_list|,
name|MSR_VMX_TRUE_EXIT_CTLS
argument_list|)
expr_stmt|;
name|entry
operator|=
name|vmx_settable
argument_list|(
name|basic
argument_list|,
name|MSR_VMX_ENTRY_CTLS
argument_list|,
name|MSR_VMX_TRUE_ENTRY_CTLS
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|bootverbose
condition|)
block|{
name|comma
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|exit
operator|&
name|VM_EXIT_SAVE_PAT
operator|&&
name|exit
operator|&
name|VM_EXIT_LOAD_PAT
operator|&&
name|entry
operator|&
name|VM_ENTRY_LOAD_PAT
condition|)
block|{
name|printf
argument_list|(
literal|"%sPAT"
argument_list|,
name|comma
condition|?
literal|","
else|:
literal|""
argument_list|)
expr_stmt|;
name|comma
operator|=
literal|1
expr_stmt|;
block|}
if|if
condition|(
name|proc
operator|&
name|PROCBASED_HLT_EXITING
condition|)
block|{
name|printf
argument_list|(
literal|"%sHLT"
argument_list|,
name|comma
condition|?
literal|","
else|:
literal|""
argument_list|)
expr_stmt|;
name|comma
operator|=
literal|1
expr_stmt|;
block|}
if|if
condition|(
name|proc
operator|&
name|PROCBASED_MTF
condition|)
block|{
name|printf
argument_list|(
literal|"%sMTF"
argument_list|,
name|comma
condition|?
literal|","
else|:
literal|""
argument_list|)
expr_stmt|;
name|comma
operator|=
literal|1
expr_stmt|;
block|}
if|if
condition|(
name|proc
operator|&
name|PROCBASED_PAUSE_EXITING
condition|)
block|{
name|printf
argument_list|(
literal|"%sPAUSE"
argument_list|,
name|comma
condition|?
literal|","
else|:
literal|""
argument_list|)
expr_stmt|;
name|comma
operator|=
literal|1
expr_stmt|;
block|}
if|if
condition|(
name|proc2
operator|&
name|PROCBASED2_ENABLE_EPT
condition|)
block|{
name|printf
argument_list|(
literal|"%sEPT"
argument_list|,
name|comma
condition|?
literal|","
else|:
literal|""
argument_list|)
expr_stmt|;
name|comma
operator|=
literal|1
expr_stmt|;
block|}
if|if
condition|(
name|proc2
operator|&
name|PROCBASED2_UNRESTRICTED_GUEST
condition|)
block|{
name|printf
argument_list|(
literal|"%sUG"
argument_list|,
name|comma
condition|?
literal|","
else|:
literal|""
argument_list|)
expr_stmt|;
name|comma
operator|=
literal|1
expr_stmt|;
block|}
if|if
condition|(
name|proc2
operator|&
name|PROCBASED2_ENABLE_VPID
condition|)
block|{
name|printf
argument_list|(
literal|"%sVPID"
argument_list|,
name|comma
condition|?
literal|","
else|:
literal|""
argument_list|)
expr_stmt|;
name|comma
operator|=
literal|1
expr_stmt|;
block|}
if|if
condition|(
name|proc
operator|&
name|PROCBASED_USE_TPR_SHADOW
operator|&&
name|proc2
operator|&
name|PROCBASED2_VIRTUALIZE_APIC_ACCESSES
operator|&&
name|proc2
operator|&
name|PROCBASED2_VIRTUALIZE_X2APIC_MODE
operator|&&
name|proc2
operator|&
name|PROCBASED2_APIC_REGISTER_VIRTUALIZATION
operator|&&
name|proc2
operator|&
name|PROCBASED2_VIRTUAL_INTERRUPT_DELIVERY
condition|)
block|{
name|printf
argument_list|(
literal|"%sVID"
argument_list|,
name|comma
condition|?
literal|","
else|:
literal|""
argument_list|)
expr_stmt|;
name|comma
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|pin
operator|&
name|PINBASED_POSTED_INTERRUPT
condition|)
name|printf
argument_list|(
literal|",PostIntr"
argument_list|)
expr_stmt|;
block|}
return|return;
block|}
name|mask
operator|=
name|basic
operator|>>
literal|32
expr_stmt|;
name|printf
argument_list|(
literal|"Basic Features=0x%b"
argument_list|,
name|mask
argument_list|,
literal|"\020"
literal|"\02132PA"
comment|/* 32-bit physical addresses */
literal|"\022SMM"
comment|/* SMM dual-monitor */
literal|"\027INS/OUTS"
comment|/* VM-exit info for INS and OUTS */
literal|"\030TRUE"
comment|/* TRUE_CTLS MSRs */
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n        Pin-Based Controls=0x%b"
argument_list|,
name|pin
argument_list|,
literal|"\020"
literal|"\001ExtINT"
comment|/* External-interrupt exiting */
literal|"\004NMI"
comment|/* NMI exiting */
literal|"\006VNMI"
comment|/* Virtual NMIs */
literal|"\007PreTmr"
comment|/* Activate VMX-preemption timer */
literal|"\010PostIntr"
comment|/* Process posted interrupts */
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n        Primary Processor Controls=0x%b"
argument_list|,
name|proc
argument_list|,
literal|"\020"
literal|"\003INTWIN"
comment|/* Interrupt-window exiting */
literal|"\004TSCOff"
comment|/* Use TSC offsetting */
literal|"\010HLT"
comment|/* HLT exiting */
literal|"\012INVLPG"
comment|/* INVLPG exiting */
literal|"\013MWAIT"
comment|/* MWAIT exiting */
literal|"\014RDPMC"
comment|/* RDPMC exiting */
literal|"\015RDTSC"
comment|/* RDTSC exiting */
literal|"\020CR3-LD"
comment|/* CR3-load exiting */
literal|"\021CR3-ST"
comment|/* CR3-store exiting */
literal|"\024CR8-LD"
comment|/* CR8-load exiting */
literal|"\025CR8-ST"
comment|/* CR8-store exiting */
literal|"\026TPR"
comment|/* Use TPR shadow */
literal|"\027NMIWIN"
comment|/* NMI-window exiting */
literal|"\030MOV-DR"
comment|/* MOV-DR exiting */
literal|"\031IO"
comment|/* Unconditional I/O exiting */
literal|"\032IOmap"
comment|/* Use I/O bitmaps */
literal|"\034MTF"
comment|/* Monitor trap flag */
literal|"\035MSRmap"
comment|/* Use MSR bitmaps */
literal|"\036MONITOR"
comment|/* MONITOR exiting */
literal|"\037PAUSE"
comment|/* PAUSE exiting */
argument_list|)
expr_stmt|;
if|if
condition|(
name|proc
operator|&
name|PROCBASED_SECONDARY_CONTROLS
condition|)
name|printf
argument_list|(
literal|"\n        Secondary Processor Controls=0x%b"
argument_list|,
name|proc2
argument_list|,
literal|"\020"
literal|"\001APIC"
comment|/* Virtualize APIC accesses */
literal|"\002EPT"
comment|/* Enable EPT */
literal|"\003DT"
comment|/* Descriptor-table exiting */
literal|"\004RDTSCP"
comment|/* Enable RDTSCP */
literal|"\005x2APIC"
comment|/* Virtualize x2APIC mode */
literal|"\006VPID"
comment|/* Enable VPID */
literal|"\007WBINVD"
comment|/* WBINVD exiting */
literal|"\010UG"
comment|/* Unrestricted guest */
literal|"\011APIC-reg"
comment|/* APIC-register virtualization */
literal|"\012VID"
comment|/* Virtual-interrupt delivery */
literal|"\013PAUSE-loop"
comment|/* PAUSE-loop exiting */
literal|"\014RDRAND"
comment|/* RDRAND exiting */
literal|"\015INVPCID"
comment|/* Enable INVPCID */
literal|"\016VMFUNC"
comment|/* Enable VM functions */
literal|"\017VMCS"
comment|/* VMCS shadowing */
literal|"\020EPT#VE"
comment|/* EPT-violation #VE */
literal|"\021XSAVES"
comment|/* Enable XSAVES/XRSTORS */
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n        Exit Controls=0x%b"
argument_list|,
name|mask
argument_list|,
literal|"\020"
literal|"\003DR"
comment|/* Save debug controls */
comment|/* Ignore Host address-space size */
literal|"\015PERF"
comment|/* Load MSR_PERF_GLOBAL_CTRL */
literal|"\020AckInt"
comment|/* Acknowledge interrupt on exit */
literal|"\023PAT-SV"
comment|/* Save MSR_PAT */
literal|"\024PAT-LD"
comment|/* Load MSR_PAT */
literal|"\025EFER-SV"
comment|/* Save MSR_EFER */
literal|"\026EFER-LD"
comment|/* Load MSR_EFER */
literal|"\027PTMR-SV"
comment|/* Save VMX-preemption timer value */
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n        Entry Controls=0x%b"
argument_list|,
name|mask
argument_list|,
literal|"\020"
literal|"\003DR"
comment|/* Save debug controls */
comment|/* Ignore IA-32e mode guest */
comment|/* Ignore Entry to SMM */
comment|/* Ignore Deactivate dual-monitor treatment */
literal|"\016PERF"
comment|/* Load MSR_PERF_GLOBAL_CTRL */
literal|"\017PAT"
comment|/* Load MSR_PAT */
literal|"\020EFER"
comment|/* Load MSR_EFER */
argument_list|)
expr_stmt|;
if|if
condition|(
name|proc
operator|&
name|PROCBASED_SECONDARY_CONTROLS
operator|&&
operator|(
name|proc2
operator|&
operator|(
name|PROCBASED2_ENABLE_EPT
operator||
name|PROCBASED2_ENABLE_VPID
operator|)
operator|)
operator|!=
literal|0
condition|)
block|{
name|msr
operator|=
name|rdmsr
argument_list|(
name|MSR_VMX_EPT_VPID_CAP
argument_list|)
expr_stmt|;
name|mask
operator|=
name|msr
expr_stmt|;
name|printf
argument_list|(
literal|"\n        EPT Features=0x%b"
argument_list|,
name|mask
argument_list|,
literal|"\020"
literal|"\001XO"
comment|/* Execute-only translations */
literal|"\007PW4"
comment|/* Page-walk length of 4 */
literal|"\011UC"
comment|/* EPT paging-structure mem can be UC */
literal|"\017WB"
comment|/* EPT paging-structure mem can be WB */
literal|"\0212M"
comment|/* EPT PDE can map a 2-Mbyte page */
literal|"\0221G"
comment|/* EPT PDPTE can map a 1-Gbyte page */
literal|"\025INVEPT"
comment|/* INVEPT is supported */
literal|"\026AD"
comment|/* Accessed and dirty flags for EPT */
literal|"\032single"
comment|/* INVEPT single-context type */
literal|"\033all"
comment|/* INVEPT all-context type */
argument_list|)
expr_stmt|;
name|mask
operator|=
name|msr
operator|>>
literal|32
expr_stmt|;
name|printf
argument_list|(
literal|"\n        VPID Features=0x%b"
argument_list|,
name|mask
argument_list|,
literal|"\020"
literal|"\001INVVPID"
comment|/* INVVPID is supported */
literal|"\011individual"
comment|/* INVVPID individual-address type */
literal|"\012single"
comment|/* INVVPID single-context type */
literal|"\013all"
comment|/* INVVPID all-context type */
comment|/* INVVPID single-context-retaining-globals type */
literal|"\014single-globals"
argument_list|)
expr_stmt|;
block|}
block|}
end_function

end_unit

