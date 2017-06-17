begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2008, Joseph Koshy  * Copyright (c) 2007 The FreeBSD Foundation  * All rights reserved.  *  * Portions of this software were developed by A. Joseph Koshy under  * sponsorship from the FreeBSD Foundation and Google, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_PMC_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_PMC_H_
end_define

begin_include
include|#
directive|include
file|<dev/hwpmc/pmc_events.h>
end_include

begin_include
include|#
directive|include
file|<machine/pmc_mdep.h>
end_include

begin_include
include|#
directive|include
file|<machine/profile.h>
end_include

begin_define
define|#
directive|define
name|PMC_MODULE_NAME
value|"hwpmc"
end_define

begin_define
define|#
directive|define
name|PMC_NAME_MAX
value|64
end_define

begin_comment
comment|/* HW counter name size */
end_comment

begin_define
define|#
directive|define
name|PMC_CLASS_MAX
value|8
end_define

begin_comment
comment|/* max #classes of PMCs per-system */
end_comment

begin_comment
comment|/*  * Kernel<->userland API version number [MMmmpppp]  *  * Major numbers are to be incremented when an incompatible change to  * the ABI occurs that older clients will not be able to handle.  *  * Minor numbers are incremented when a backwards compatible change  * occurs that allows older correct programs to run unchanged.  For  * example, when support for a new PMC type is added.  *  * The patch version is incremented for every bug fix.  */
end_comment

begin_define
define|#
directive|define
name|PMC_VERSION_MAJOR
value|0x03
end_define

begin_define
define|#
directive|define
name|PMC_VERSION_MINOR
value|0x01
end_define

begin_define
define|#
directive|define
name|PMC_VERSION_PATCH
value|0x0000
end_define

begin_define
define|#
directive|define
name|PMC_VERSION
value|(PMC_VERSION_MAJOR<< 24 |		\ 	PMC_VERSION_MINOR<< 16 | PMC_VERSION_PATCH)
end_define

begin_comment
comment|/*  * Kinds of CPUs known.  *  * We keep track of CPU variants that need to be distinguished in  * some way for PMC operations.  CPU names are grouped by manufacturer  * and numbered sparsely in order to minimize changes to the ABI involved  * when new CPUs are added.  */
end_comment

begin_define
define|#
directive|define
name|__PMC_CPUS
parameter_list|()
define|\
value|__PMC_CPU(AMD_K7,	0x00,	"AMD K7")		\ 	__PMC_CPU(AMD_K8,	0x01,	"AMD K8")		\ 	__PMC_CPU(INTEL_P5,	0x80,	"Intel Pentium")	\ 	__PMC_CPU(INTEL_P6,	0x81,	"Intel Pentium Pro")	\ 	__PMC_CPU(INTEL_CL,	0x82,	"Intel Celeron")	\ 	__PMC_CPU(INTEL_PII,	0x83,	"Intel Pentium II")	\ 	__PMC_CPU(INTEL_PIII,	0x84,	"Intel Pentium III")	\ 	__PMC_CPU(INTEL_PM,	0x85,	"Intel Pentium M")	\ 	__PMC_CPU(INTEL_PIV,	0x86,	"Intel Pentium IV")	\ 	__PMC_CPU(INTEL_CORE,	0x87,	"Intel Core Solo/Duo")	\ 	__PMC_CPU(INTEL_CORE2,	0x88,	"Intel Core2")		\ 	__PMC_CPU(INTEL_CORE2EXTREME,	0x89,	"Intel Core2 Extreme")	\ 	__PMC_CPU(INTEL_ATOM,	0x8A,	"Intel Atom")		\ 	__PMC_CPU(INTEL_COREI7, 0x8B,   "Intel Core i7")	\ 	__PMC_CPU(INTEL_WESTMERE, 0x8C,   "Intel Westmere")	\ 	__PMC_CPU(INTEL_SANDYBRIDGE, 0x8D,   "Intel Sandy Bridge")	\ 	__PMC_CPU(INTEL_IVYBRIDGE, 0x8E,   "Intel Ivy Bridge")	\ 	__PMC_CPU(INTEL_SANDYBRIDGE_XEON, 0x8F,   "Intel Sandy Bridge Xeon")	\ 	__PMC_CPU(INTEL_IVYBRIDGE_XEON, 0x90,   "Intel Ivy Bridge Xeon")	\ 	__PMC_CPU(INTEL_HASWELL, 0x91,   "Intel Haswell")	\ 	__PMC_CPU(INTEL_ATOM_SILVERMONT, 0x92,	"Intel Atom Silvermont")    \ 	__PMC_CPU(INTEL_NEHALEM_EX, 0x93,   "Intel Nehalem Xeon 7500")	\ 	__PMC_CPU(INTEL_WESTMERE_EX, 0x94,   "Intel Westmere Xeon E7")	\ 	__PMC_CPU(INTEL_HASWELL_XEON, 0x95,   "Intel Haswell Xeon E5 v3") \ 	__PMC_CPU(INTEL_BROADWELL, 0x96,   "Intel Broadwell") \ 	__PMC_CPU(INTEL_BROADWELL_XEON, 0x97,   "Intel Broadwell Xeon") \ 	__PMC_CPU(INTEL_SKYLAKE, 0x98,   "Intel Skylake")		\ 	__PMC_CPU(INTEL_SKYLAKE_XEON, 0x99,   "Intel Skylake Xeon")	\ 	__PMC_CPU(INTEL_XSCALE,	0x100,	"Intel XScale")		\ 	__PMC_CPU(MIPS_24K,     0x200,  "MIPS 24K")		\ 	__PMC_CPU(MIPS_OCTEON,  0x201,  "Cavium Octeon")	\ 	__PMC_CPU(MIPS_74K,     0x202,  "MIPS 74K")		\ 	__PMC_CPU(PPC_7450,     0x300,  "PowerPC MPC7450")	\ 	__PMC_CPU(PPC_E500,     0x340,  "PowerPC e500 Core")	\ 	__PMC_CPU(PPC_970,      0x380,  "IBM PowerPC 970")	\ 	__PMC_CPU(GENERIC, 	0x400,  "Generic")		\ 	__PMC_CPU(ARMV7_CORTEX_A5,	0x500,	"ARMv7 Cortex A5")	\ 	__PMC_CPU(ARMV7_CORTEX_A7,	0x501,	"ARMv7 Cortex A7")	\ 	__PMC_CPU(ARMV7_CORTEX_A8,	0x502,	"ARMv7 Cortex A8")	\ 	__PMC_CPU(ARMV7_CORTEX_A9,	0x503,	"ARMv7 Cortex A9")	\ 	__PMC_CPU(ARMV7_CORTEX_A15,	0x504,	"ARMv7 Cortex A15")	\ 	__PMC_CPU(ARMV7_CORTEX_A17,	0x505,	"ARMv7 Cortex A17")	\ 	__PMC_CPU(ARMV8_CORTEX_A53,	0x600,	"ARMv8 Cortex A53")	\ 	__PMC_CPU(ARMV8_CORTEX_A57,	0x601,	"ARMv8 Cortex A57")
end_define

begin_enum
enum|enum
name|pmc_cputype
block|{
undef|#
directive|undef
name|__PMC_CPU
define|#
directive|define
name|__PMC_CPU
parameter_list|(
name|S
parameter_list|,
name|V
parameter_list|,
name|D
parameter_list|)
value|PMC_CPU_##S = V,
name|__PMC_CPUS
argument_list|()
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|PMC_CPU_FIRST
value|PMC_CPU_AMD_K7
end_define

begin_define
define|#
directive|define
name|PMC_CPU_LAST
value|PMC_CPU_GENERIC
end_define

begin_comment
comment|/*  * Classes of PMCs  */
end_comment

begin_define
define|#
directive|define
name|__PMC_CLASSES
parameter_list|()
define|\
value|__PMC_CLASS(TSC,	0x00,	"CPU Timestamp counter")	\ 	__PMC_CLASS(K7,		0x01,	"AMD K7 performance counters")	\ 	__PMC_CLASS(K8,		0x02,	"AMD K8 performance counters")	\ 	__PMC_CLASS(P5,		0x03,	"Intel Pentium counters")	\ 	__PMC_CLASS(P6,		0x04,	"Intel Pentium Pro counters")	\ 	__PMC_CLASS(P4,		0x05,	"Intel Pentium-IV counters")	\ 	__PMC_CLASS(IAF,	0x06,	"Intel Core2/Atom, fixed function") \ 	__PMC_CLASS(IAP,	0x07,	"Intel Core...Atom, programmable") \ 	__PMC_CLASS(UCF,	0x08,	"Intel Uncore fixed function")	\ 	__PMC_CLASS(UCP,	0x09,	"Intel Uncore programmable")	\ 	__PMC_CLASS(XSCALE,	0x0A,	"Intel XScale counters")	\ 	__PMC_CLASS(MIPS24K,	0x0B,	"MIPS 24K")			\ 	__PMC_CLASS(OCTEON,	0x0C,	"Cavium Octeon")		\ 	__PMC_CLASS(PPC7450,	0x0D,	"Motorola MPC7450 class")	\ 	__PMC_CLASS(PPC970,	0x0E,	"IBM PowerPC 970 class")	\ 	__PMC_CLASS(SOFT,	0x0F,	"Software events")		\ 	__PMC_CLASS(ARMV7,	0x10,	"ARMv7")			\ 	__PMC_CLASS(ARMV8,	0x11,	"ARMv8")			\ 	__PMC_CLASS(MIPS74K,	0x12,	"MIPS 74K")			\ 	__PMC_CLASS(E500,	0x13,	"Freescale e500 class")
end_define

begin_enum
enum|enum
name|pmc_class
block|{
undef|#
directive|undef
name|__PMC_CLASS
define|#
directive|define
name|__PMC_CLASS
parameter_list|(
name|S
parameter_list|,
name|V
parameter_list|,
name|D
parameter_list|)
value|PMC_CLASS_##S = V,
name|__PMC_CLASSES
argument_list|()
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|PMC_CLASS_FIRST
value|PMC_CLASS_TSC
end_define

begin_define
define|#
directive|define
name|PMC_CLASS_LAST
value|PMC_CLASS_E500
end_define

begin_comment
comment|/*  * A PMC can be in the following states:  *  * Hardware states:  *   DISABLED   -- administratively prohibited from being used.  *   FREE       -- HW available for use  * Software states:  *   ALLOCATED  -- allocated  *   STOPPED    -- allocated, but not counting events  *   RUNNING    -- allocated, and in operation; 'pm_runcount'  *                 holds the number of CPUs using this PMC at  *                 a given instant  *   DELETED    -- being destroyed  */
end_comment

begin_define
define|#
directive|define
name|__PMC_HWSTATES
parameter_list|()
define|\
value|__PMC_STATE(DISABLED)			\ 	__PMC_STATE(FREE)
end_define

begin_define
define|#
directive|define
name|__PMC_SWSTATES
parameter_list|()
define|\
value|__PMC_STATE(ALLOCATED)			\ 	__PMC_STATE(STOPPED)			\ 	__PMC_STATE(RUNNING)			\ 	__PMC_STATE(DELETED)
end_define

begin_define
define|#
directive|define
name|__PMC_STATES
parameter_list|()
define|\
value|__PMC_HWSTATES()			\ 	__PMC_SWSTATES()
end_define

begin_enum
enum|enum
name|pmc_state
block|{
undef|#
directive|undef
name|__PMC_STATE
define|#
directive|define
name|__PMC_STATE
parameter_list|(
name|S
parameter_list|)
value|PMC_STATE_##S,
name|__PMC_STATES
argument_list|()
name|__PMC_STATE
argument_list|(
argument|MAX
argument_list|)
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|PMC_STATE_FIRST
value|PMC_STATE_DISABLED
end_define

begin_define
define|#
directive|define
name|PMC_STATE_LAST
value|PMC_STATE_DELETED
end_define

begin_comment
comment|/*  * An allocated PMC may used as a 'global' counter or as a  * 'thread-private' one.  Each such mode of use can be in either  * statistical sampling mode or in counting mode.  Thus a PMC in use  *  * SS i.e., SYSTEM STATISTICAL  -- system-wide statistical profiling  * SC i.e., SYSTEM COUNTER      -- system-wide counting mode  * TS i.e., THREAD STATISTICAL  -- thread virtual, statistical profiling  * TC i.e., THREAD COUNTER      -- thread virtual, counting mode  *  * Statistical profiling modes rely on the PMC periodically delivering  * a interrupt to the CPU (when the configured number of events have  * been measured), so the PMC must have the ability to generate  * interrupts.  *  * In counting modes, the PMC counts its configured events, with the  * value of the PMC being read whenever needed by its owner process.  *  * The thread specific modes "virtualize" the PMCs -- the PMCs appear  * to be thread private and count events only when the profiled thread  * actually executes on the CPU.  *  * The system-wide "global" modes keep the PMCs running all the time  * and are used to measure the behaviour of the whole system.  */
end_comment

begin_define
define|#
directive|define
name|__PMC_MODES
parameter_list|()
define|\
value|__PMC_MODE(SS,	0)			\ 	__PMC_MODE(SC,	1)			\ 	__PMC_MODE(TS,	2)			\ 	__PMC_MODE(TC,	3)
end_define

begin_enum
enum|enum
name|pmc_mode
block|{
undef|#
directive|undef
name|__PMC_MODE
define|#
directive|define
name|__PMC_MODE
parameter_list|(
name|M
parameter_list|,
name|N
parameter_list|)
value|PMC_MODE_##M = N,
name|__PMC_MODES
argument_list|()
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|PMC_MODE_FIRST
value|PMC_MODE_SS
end_define

begin_define
define|#
directive|define
name|PMC_MODE_LAST
value|PMC_MODE_TC
end_define

begin_define
define|#
directive|define
name|PMC_IS_COUNTING_MODE
parameter_list|(
name|mode
parameter_list|)
define|\
value|((mode) == PMC_MODE_SC || (mode) == PMC_MODE_TC)
end_define

begin_define
define|#
directive|define
name|PMC_IS_SYSTEM_MODE
parameter_list|(
name|mode
parameter_list|)
define|\
value|((mode) == PMC_MODE_SS || (mode) == PMC_MODE_SC)
end_define

begin_define
define|#
directive|define
name|PMC_IS_SAMPLING_MODE
parameter_list|(
name|mode
parameter_list|)
define|\
value|((mode) == PMC_MODE_SS || (mode) == PMC_MODE_TS)
end_define

begin_define
define|#
directive|define
name|PMC_IS_VIRTUAL_MODE
parameter_list|(
name|mode
parameter_list|)
define|\
value|((mode) == PMC_MODE_TS || (mode) == PMC_MODE_TC)
end_define

begin_comment
comment|/*  * PMC row disposition  */
end_comment

begin_define
define|#
directive|define
name|__PMC_DISPOSITIONS
parameter_list|(
name|N
parameter_list|)
define|\
value|__PMC_DISP(STANDALONE)
comment|/* global/disabled counters */
value|\ 	__PMC_DISP(FREE)
comment|/* free/available */
value|\ 	__PMC_DISP(THREAD)
comment|/* thread-virtual PMCs */
value|\ 	__PMC_DISP(UNKNOWN)
end_define

begin_comment
comment|/* sentinel */
end_comment

begin_enum
enum|enum
name|pmc_disp
block|{
undef|#
directive|undef
name|__PMC_DISP
define|#
directive|define
name|__PMC_DISP
parameter_list|(
name|D
parameter_list|)
value|PMC_DISP_##D ,
name|__PMC_DISPOSITIONS
argument_list|()
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|PMC_DISP_FIRST
value|PMC_DISP_STANDALONE
end_define

begin_define
define|#
directive|define
name|PMC_DISP_LAST
value|PMC_DISP_THREAD
end_define

begin_comment
comment|/*  * Counter capabilities  *  * __PMC_CAPS(NAME, VALUE, DESCRIPTION)  */
end_comment

begin_define
define|#
directive|define
name|__PMC_CAPS
parameter_list|()
define|\
value|__PMC_CAP(INTERRUPT,	0, "generate interrupts")		\ 	__PMC_CAP(USER,		1, "count user-mode events")		\ 	__PMC_CAP(SYSTEM,	2, "count system-mode events")		\ 	__PMC_CAP(EDGE,		3, "do edge detection of events")	\ 	__PMC_CAP(THRESHOLD,	4, "ignore events below a threshold")	\ 	__PMC_CAP(READ,		5, "read PMC counter")			\ 	__PMC_CAP(WRITE,	6, "reprogram PMC counter")		\ 	__PMC_CAP(INVERT,	7, "invert comparison sense")		\ 	__PMC_CAP(QUALIFIER,	8, "further qualify monitored events")	\ 	__PMC_CAP(PRECISE,	9, "perform precise sampling")		\ 	__PMC_CAP(TAGGING,	10, "tag upstream events")		\ 	__PMC_CAP(CASCADE,	11, "cascade counters")
end_define

begin_enum
enum|enum
name|pmc_caps
block|{
undef|#
directive|undef
name|__PMC_CAP
define|#
directive|define
name|__PMC_CAP
parameter_list|(
name|NAME
parameter_list|,
name|VALUE
parameter_list|,
name|DESCR
parameter_list|)
value|PMC_CAP_##NAME = (1<< VALUE) ,
name|__PMC_CAPS
argument_list|()
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|PMC_CAP_FIRST
value|PMC_CAP_INTERRUPT
end_define

begin_define
define|#
directive|define
name|PMC_CAP_LAST
value|PMC_CAP_CASCADE
end_define

begin_comment
comment|/*  * PMC Event Numbers  *  * These are generated from the definitions in "dev/hwpmc/pmc_events.h".  */
end_comment

begin_enum
enum|enum
name|pmc_event
block|{
undef|#
directive|undef
name|__PMC_EV
undef|#
directive|undef
name|__PMC_EV_BLOCK
define|#
directive|define
name|__PMC_EV_BLOCK
parameter_list|(
name|C
parameter_list|,
name|V
parameter_list|)
value|PMC_EV_ ## C ## __BLOCK_START = (V) - 1 ,
define|#
directive|define
name|__PMC_EV
parameter_list|(
name|C
parameter_list|,
name|N
parameter_list|)
value|PMC_EV_ ## C ## _ ## N ,
name|__PMC_EVENTS
argument_list|()
block|}
enum|;
end_enum

begin_comment
comment|/*  * PMC SYSCALL INTERFACE  */
end_comment

begin_comment
comment|/*  * "PMC_OPS" -- these are the commands recognized by the kernel  * module, and are used when performing a system call from userland.  */
end_comment

begin_define
define|#
directive|define
name|__PMC_OPS
parameter_list|()
define|\
value|__PMC_OP(CONFIGURELOG, "Set log file")				\ 	__PMC_OP(FLUSHLOG, "Flush log file")				\ 	__PMC_OP(GETCPUINFO, "Get system CPU information")		\ 	__PMC_OP(GETDRIVERSTATS, "Get driver statistics")		\ 	__PMC_OP(GETMODULEVERSION, "Get module version")		\ 	__PMC_OP(GETPMCINFO, "Get per-cpu PMC information")		\ 	__PMC_OP(PMCADMIN, "Set PMC state")				\ 	__PMC_OP(PMCALLOCATE, "Allocate and configure a PMC")		\ 	__PMC_OP(PMCATTACH, "Attach a PMC to a process")		\ 	__PMC_OP(PMCDETACH, "Detach a PMC from a process")		\ 	__PMC_OP(PMCGETMSR, "Get a PMC's hardware address")		\ 	__PMC_OP(PMCRELEASE, "Release a PMC")				\ 	__PMC_OP(PMCRW, "Read/Set a PMC")				\ 	__PMC_OP(PMCSETCOUNT, "Set initial count/sampling rate")	\ 	__PMC_OP(PMCSTART, "Start a PMC")				\ 	__PMC_OP(PMCSTOP, "Stop a PMC")					\ 	__PMC_OP(WRITELOG, "Write a cookie to the log file")		\ 	__PMC_OP(CLOSELOG, "Close log file")				\ 	__PMC_OP(GETDYNEVENTINFO, "Get dynamic events list")
end_define

begin_enum
enum|enum
name|pmc_ops
block|{
undef|#
directive|undef
name|__PMC_OP
define|#
directive|define
name|__PMC_OP
parameter_list|(
name|N
parameter_list|,
name|D
parameter_list|)
value|PMC_OP_##N,
name|__PMC_OPS
argument_list|()
block|}
enum|;
end_enum

begin_comment
comment|/*  * Flags used in operations on PMCs.  */
end_comment

begin_define
define|#
directive|define
name|PMC_F_FORCE
value|0x00000001
end_define

begin_comment
comment|/*OP ADMIN force operation */
end_comment

begin_define
define|#
directive|define
name|PMC_F_DESCENDANTS
value|0x00000002
end_define

begin_comment
comment|/*OP ALLOCATE track descendants */
end_comment

begin_define
define|#
directive|define
name|PMC_F_LOG_PROCCSW
value|0x00000004
end_define

begin_comment
comment|/*OP ALLOCATE track ctx switches */
end_comment

begin_define
define|#
directive|define
name|PMC_F_LOG_PROCEXIT
value|0x00000008
end_define

begin_comment
comment|/*OP ALLOCATE log proc exits */
end_comment

begin_define
define|#
directive|define
name|PMC_F_NEWVALUE
value|0x00000010
end_define

begin_comment
comment|/*OP RW write new value */
end_comment

begin_define
define|#
directive|define
name|PMC_F_OLDVALUE
value|0x00000020
end_define

begin_comment
comment|/*OP RW get old value */
end_comment

begin_define
define|#
directive|define
name|PMC_F_KGMON
value|0x00000040
end_define

begin_comment
comment|/*OP ALLOCATE kgmon(8) profiling */
end_comment

begin_comment
comment|/* V2 API */
end_comment

begin_define
define|#
directive|define
name|PMC_F_CALLCHAIN
value|0x00000080
end_define

begin_comment
comment|/*OP ALLOCATE capture callchains */
end_comment

begin_comment
comment|/* internal flags */
end_comment

begin_define
define|#
directive|define
name|PMC_F_ATTACHED_TO_OWNER
value|0x00010000
end_define

begin_comment
comment|/*attached to owner*/
end_comment

begin_define
define|#
directive|define
name|PMC_F_NEEDS_LOGFILE
value|0x00020000
end_define

begin_comment
comment|/*needs log file */
end_comment

begin_define
define|#
directive|define
name|PMC_F_ATTACH_DONE
value|0x00040000
end_define

begin_comment
comment|/*attached at least once */
end_comment

begin_define
define|#
directive|define
name|PMC_CALLCHAIN_DEPTH_MAX
value|128
end_define

begin_define
define|#
directive|define
name|PMC_CC_F_USERSPACE
value|0x01
end_define

begin_comment
comment|/*userspace callchain*/
end_comment

begin_comment
comment|/*  * Cookies used to denote allocated PMCs, and the values of PMCs.  */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|pmc_id_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|pmc_value_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PMC_ID_INVALID
value|(~ (pmc_id_t) 0)
end_define

begin_comment
comment|/*  * PMC IDs have the following format:  *  * +--------+----------+-----------+-----------+  * |   CPU  | PMC MODE | PMC CLASS | ROW INDEX |  * +--------+----------+-----------+-----------+  *  * where each field is 8 bits wide.  Field 'CPU' is set to the  * requested CPU for system-wide PMCs or PMC_CPU_ANY for process-mode  * PMCs.  Field 'PMC MODE' is the allocated PMC mode.  Field 'PMC  * CLASS' is the class of the PMC.  Field 'ROW INDEX' is the row index  * for the PMC.  *  * The 'ROW INDEX' ranges over 0..NWPMCS where NHWPMCS is the total  * number of hardware PMCs on this cpu.  */
end_comment

begin_define
define|#
directive|define
name|PMC_ID_TO_ROWINDEX
parameter_list|(
name|ID
parameter_list|)
value|((ID)& 0xFF)
end_define

begin_define
define|#
directive|define
name|PMC_ID_TO_CLASS
parameter_list|(
name|ID
parameter_list|)
value|(((ID)& 0xFF00)>> 8)
end_define

begin_define
define|#
directive|define
name|PMC_ID_TO_MODE
parameter_list|(
name|ID
parameter_list|)
value|(((ID)& 0xFF0000)>> 16)
end_define

begin_define
define|#
directive|define
name|PMC_ID_TO_CPU
parameter_list|(
name|ID
parameter_list|)
value|(((ID)& 0xFF000000)>> 24)
end_define

begin_define
define|#
directive|define
name|PMC_ID_MAKE_ID
parameter_list|(
name|CPU
parameter_list|,
name|MODE
parameter_list|,
name|CLASS
parameter_list|,
name|ROWINDEX
parameter_list|)
define|\
value|((((CPU)& 0xFF)<< 24) | (((MODE)& 0xFF)<< 16) |	\ 	(((CLASS)& 0xFF)<< 8) | ((ROWINDEX)& 0xFF))
end_define

begin_comment
comment|/*  * Data structures for system calls supported by the pmc driver.  */
end_comment

begin_comment
comment|/*  * OP PMCALLOCATE  *  * Allocate a PMC on the named CPU.  */
end_comment

begin_define
define|#
directive|define
name|PMC_CPU_ANY
value|~0
end_define

begin_struct
struct|struct
name|pmc_op_pmcallocate
block|{
name|uint32_t
name|pm_caps
decl_stmt|;
comment|/* PMC_CAP_* */
name|uint32_t
name|pm_cpu
decl_stmt|;
comment|/* CPU number or PMC_CPU_ANY */
name|enum
name|pmc_class
name|pm_class
decl_stmt|;
comment|/* class of PMC desired */
name|enum
name|pmc_event
name|pm_ev
decl_stmt|;
comment|/* [enum pmc_event] desired */
name|uint32_t
name|pm_flags
decl_stmt|;
comment|/* additional modifiers PMC_F_* */
name|enum
name|pmc_mode
name|pm_mode
decl_stmt|;
comment|/* desired mode */
name|pmc_id_t
name|pm_pmcid
decl_stmt|;
comment|/* [return] process pmc id */
name|union
name|pmc_md_op_pmcallocate
name|pm_md
decl_stmt|;
comment|/* MD layer extensions */
block|}
struct|;
end_struct

begin_comment
comment|/*  * OP PMCADMIN  *  * Set the administrative state (i.e., whether enabled or disabled) of  * a PMC 'pm_pmc' on CPU 'pm_cpu'.  Note that 'pm_pmc' specifies an  * absolute PMC number and need not have been first allocated by the  * calling process.  */
end_comment

begin_struct
struct|struct
name|pmc_op_pmcadmin
block|{
name|int
name|pm_cpu
decl_stmt|;
comment|/* CPU# */
name|uint32_t
name|pm_flags
decl_stmt|;
comment|/* flags */
name|int
name|pm_pmc
decl_stmt|;
comment|/* PMC# */
name|enum
name|pmc_state
name|pm_state
decl_stmt|;
comment|/* desired state */
block|}
struct|;
end_struct

begin_comment
comment|/*  * OP PMCATTACH / OP PMCDETACH  *  * Attach/detach a PMC and a process.  */
end_comment

begin_struct
struct|struct
name|pmc_op_pmcattach
block|{
name|pmc_id_t
name|pm_pmc
decl_stmt|;
comment|/* PMC to attach to */
name|pid_t
name|pm_pid
decl_stmt|;
comment|/* target process */
block|}
struct|;
end_struct

begin_comment
comment|/*  * OP PMCSETCOUNT  *  * Set the sampling rate (i.e., the reload count) for statistical counters.  * 'pm_pmcid' need to have been previously allocated using PMCALLOCATE.  */
end_comment

begin_struct
struct|struct
name|pmc_op_pmcsetcount
block|{
name|pmc_value_t
name|pm_count
decl_stmt|;
comment|/* initial/sample count */
name|pmc_id_t
name|pm_pmcid
decl_stmt|;
comment|/* PMC id to set */
block|}
struct|;
end_struct

begin_comment
comment|/*  * OP PMCRW  *  * Read the value of a PMC named by 'pm_pmcid'.  'pm_pmcid' needs  * to have been previously allocated using PMCALLOCATE.  */
end_comment

begin_struct
struct|struct
name|pmc_op_pmcrw
block|{
name|uint32_t
name|pm_flags
decl_stmt|;
comment|/* PMC_F_{OLD,NEW}VALUE*/
name|pmc_id_t
name|pm_pmcid
decl_stmt|;
comment|/* pmc id */
name|pmc_value_t
name|pm_value
decl_stmt|;
comment|/* new&returned value */
block|}
struct|;
end_struct

begin_comment
comment|/*  * OP GETPMCINFO  *  * retrieve PMC state for a named CPU.  The caller is expected to  * allocate 'npmc' * 'struct pmc_info' bytes of space for the return  * values.  */
end_comment

begin_struct
struct|struct
name|pmc_info
block|{
name|char
name|pm_name
index|[
name|PMC_NAME_MAX
index|]
decl_stmt|;
comment|/* pmc name */
name|enum
name|pmc_class
name|pm_class
decl_stmt|;
comment|/* enum pmc_class */
name|int
name|pm_enabled
decl_stmt|;
comment|/* whether enabled */
name|enum
name|pmc_disp
name|pm_rowdisp
decl_stmt|;
comment|/* FREE, THREAD or STANDLONE */
name|pid_t
name|pm_ownerpid
decl_stmt|;
comment|/* owner, or -1 */
name|enum
name|pmc_mode
name|pm_mode
decl_stmt|;
comment|/* current mode [enum pmc_mode] */
name|enum
name|pmc_event
name|pm_event
decl_stmt|;
comment|/* current event */
name|uint32_t
name|pm_flags
decl_stmt|;
comment|/* current flags */
name|pmc_value_t
name|pm_reloadcount
decl_stmt|;
comment|/* sampling counters only */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pmc_op_getpmcinfo
block|{
name|int32_t
name|pm_cpu
decl_stmt|;
comment|/* 0<= cpu< mp_maxid */
name|struct
name|pmc_info
name|pm_pmcs
index|[]
decl_stmt|;
comment|/* space for 'npmc' structures */
block|}
struct|;
end_struct

begin_comment
comment|/*  * OP GETCPUINFO  *  * Retrieve system CPU information.  */
end_comment

begin_struct
struct|struct
name|pmc_classinfo
block|{
name|enum
name|pmc_class
name|pm_class
decl_stmt|;
comment|/* class id */
name|uint32_t
name|pm_caps
decl_stmt|;
comment|/* counter capabilities */
name|uint32_t
name|pm_width
decl_stmt|;
comment|/* width of the PMC */
name|uint32_t
name|pm_num
decl_stmt|;
comment|/* number of PMCs in class */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pmc_op_getcpuinfo
block|{
name|enum
name|pmc_cputype
name|pm_cputype
decl_stmt|;
comment|/* what kind of CPU */
name|uint32_t
name|pm_ncpu
decl_stmt|;
comment|/* max CPU number */
name|uint32_t
name|pm_npmc
decl_stmt|;
comment|/* #PMCs per CPU */
name|uint32_t
name|pm_nclass
decl_stmt|;
comment|/* #classes of PMCs */
name|struct
name|pmc_classinfo
name|pm_classes
index|[
name|PMC_CLASS_MAX
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * OP CONFIGURELOG  *  * Configure a log file for writing system-wide statistics to.  */
end_comment

begin_struct
struct|struct
name|pmc_op_configurelog
block|{
name|int
name|pm_flags
decl_stmt|;
name|int
name|pm_logfd
decl_stmt|;
comment|/* logfile fd (or -1) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * OP GETDRIVERSTATS  *  * Retrieve pmc(4) driver-wide statistics.  */
end_comment

begin_struct
struct|struct
name|pmc_op_getdriverstats
block|{
name|unsigned
name|int
name|pm_intr_ignored
decl_stmt|;
comment|/* #interrupts ignored */
name|unsigned
name|int
name|pm_intr_processed
decl_stmt|;
comment|/* #interrupts processed */
name|unsigned
name|int
name|pm_intr_bufferfull
decl_stmt|;
comment|/* #interrupts with ENOSPC */
name|unsigned
name|int
name|pm_syscalls
decl_stmt|;
comment|/* #syscalls */
name|unsigned
name|int
name|pm_syscall_errors
decl_stmt|;
comment|/* #syscalls with errors */
name|unsigned
name|int
name|pm_buffer_requests
decl_stmt|;
comment|/* #buffer requests */
name|unsigned
name|int
name|pm_buffer_requests_failed
decl_stmt|;
comment|/* #failed buffer requests */
name|unsigned
name|int
name|pm_log_sweeps
decl_stmt|;
comment|/* #sample buffer processing 						   passes */
block|}
struct|;
end_struct

begin_comment
comment|/*  * OP RELEASE / OP START / OP STOP  *  * Simple operations on a PMC id.  */
end_comment

begin_struct
struct|struct
name|pmc_op_simple
block|{
name|pmc_id_t
name|pm_pmcid
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * OP WRITELOG  *  * Flush the current log buffer and write 4 bytes of user data to it.  */
end_comment

begin_struct
struct|struct
name|pmc_op_writelog
block|{
name|uint32_t
name|pm_userdata
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * OP GETMSR  *  * Retrieve the machine specific address associated with the allocated  * PMC.  This number can be used subsequently with a read-performance-counter  * instruction.  */
end_comment

begin_struct
struct|struct
name|pmc_op_getmsr
block|{
name|uint32_t
name|pm_msr
decl_stmt|;
comment|/* machine specific address */
name|pmc_id_t
name|pm_pmcid
decl_stmt|;
comment|/* allocated pmc id */
block|}
struct|;
end_struct

begin_comment
comment|/*  * OP GETDYNEVENTINFO  *  * Retrieve a PMC dynamic class events list.  */
end_comment

begin_struct
struct|struct
name|pmc_dyn_event_descr
block|{
name|char
name|pm_ev_name
index|[
name|PMC_NAME_MAX
index|]
decl_stmt|;
name|enum
name|pmc_event
name|pm_ev_code
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pmc_op_getdyneventinfo
block|{
name|enum
name|pmc_class
name|pm_class
decl_stmt|;
name|unsigned
name|int
name|pm_nevent
decl_stmt|;
name|struct
name|pmc_dyn_event_descr
name|pm_events
index|[
name|PMC_EV_DYN_COUNT
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/_cpuset.h>
end_include

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_define
define|#
directive|define
name|PMC_HASH_SIZE
value|1024
end_define

begin_define
define|#
directive|define
name|PMC_MTXPOOL_SIZE
value|2048
end_define

begin_define
define|#
directive|define
name|PMC_LOG_BUFFER_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|PMC_NLOGBUFFERS
value|1024
end_define

begin_define
define|#
directive|define
name|PMC_NSAMPLES
value|1024
end_define

begin_define
define|#
directive|define
name|PMC_CALLCHAIN_DEPTH
value|32
end_define

begin_define
define|#
directive|define
name|PMC_SYSCTL_NAME_PREFIX
value|"kern." PMC_MODULE_NAME "."
end_define

begin_comment
comment|/*  * Locking keys  *  * (b) - pmc_bufferlist_mtx (spin lock)  * (k) - pmc_kthread_mtx (sleep lock)  * (o) - po->po_mtx (spin lock)  */
end_comment

begin_comment
comment|/*  * PMC commands  */
end_comment

begin_struct
struct|struct
name|pmc_syscall_args
block|{
name|register_t
name|pmop_code
decl_stmt|;
comment|/* one of PMC_OP_* */
name|void
modifier|*
name|pmop_data
decl_stmt|;
comment|/* syscall parameter */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Interface to processor specific s1tuff  */
end_comment

begin_comment
comment|/*  * struct pmc_descr  *  * Machine independent (i.e., the common parts) of a human readable  * PMC description.  */
end_comment

begin_struct
struct|struct
name|pmc_descr
block|{
name|char
name|pd_name
index|[
name|PMC_NAME_MAX
index|]
decl_stmt|;
comment|/* name */
name|uint32_t
name|pd_caps
decl_stmt|;
comment|/* capabilities */
name|enum
name|pmc_class
name|pd_class
decl_stmt|;
comment|/* class of the PMC */
name|uint32_t
name|pd_width
decl_stmt|;
comment|/* width in bits */
block|}
struct|;
end_struct

begin_comment
comment|/*  * struct pmc_target  *  * This structure records all the target processes associated with a  * PMC.  */
end_comment

begin_struct
struct|struct
name|pmc_target
block|{
name|LIST_ENTRY
argument_list|(
argument|pmc_target
argument_list|)
name|pt_next
expr_stmt|;
name|struct
name|pmc_process
modifier|*
name|pt_process
decl_stmt|;
comment|/* target descriptor */
block|}
struct|;
end_struct

begin_comment
comment|/*  * struct pmc  *  * Describes each allocated PMC.  *  * Each PMC has precisely one owner, namely the process that allocated  * the PMC.  *  * A PMC may be attached to multiple target processes.  The  * 'pm_targets' field links all the target processes being monitored  * by this PMC.  *  * The 'pm_savedvalue' field is protected by a mutex.  *  * On a multi-cpu machine, multiple target threads associated with a  * process-virtual PMC could be concurrently executing on different  * CPUs.  The 'pm_runcount' field is atomically incremented every time  * the PMC gets scheduled on a CPU and atomically decremented when it  * get descheduled.  Deletion of a PMC is only permitted when this  * field is '0'.  *  */
end_comment

begin_struct
struct|struct
name|pmc
block|{
name|LIST_HEAD
argument_list|(
argument_list|,
argument|pmc_target
argument_list|)
name|pm_targets
expr_stmt|;
comment|/* list of target processes */
name|LIST_ENTRY
argument_list|(
argument|pmc
argument_list|)
name|pm_next
expr_stmt|;
comment|/* owner's list */
comment|/* 	 * System-wide PMCs are allocated on a CPU and are not moved 	 * around.  For system-wide PMCs we record the CPU the PMC was 	 * allocated on in the 'CPU' field of the pmc ID. 	 * 	 * Virtual PMCs run on whichever CPU is currently executing 	 * their targets' threads.  For these PMCs we need to save 	 * their current PMC counter values when they are taken off 	 * CPU. 	 */
union|union
block|{
name|pmc_value_t
name|pm_savedvalue
decl_stmt|;
comment|/* Virtual PMCS */
block|}
name|pm_gv
union|;
comment|/* 	 * For sampling mode PMCs, we keep track of the PMC's "reload 	 * count", which is the counter value to be loaded in when 	 * arming the PMC for the next counting session.  For counting 	 * modes on PMCs that are read-only (e.g., the x86 TSC), we 	 * keep track of the initial value at the start of 	 * counting-mode operation. 	 */
union|union
block|{
name|pmc_value_t
name|pm_reloadcount
decl_stmt|;
comment|/* sampling PMC modes */
name|pmc_value_t
name|pm_initial
decl_stmt|;
comment|/* counting PMC modes */
block|}
name|pm_sc
union|;
specifier|volatile
name|cpuset_t
name|pm_stalled
decl_stmt|;
comment|/* marks stalled sampling PMCs */
specifier|volatile
name|cpuset_t
name|pm_cpustate
decl_stmt|;
comment|/* CPUs where PMC should be active */
name|uint32_t
name|pm_caps
decl_stmt|;
comment|/* PMC capabilities */
name|enum
name|pmc_event
name|pm_event
decl_stmt|;
comment|/* event being measured */
name|uint32_t
name|pm_flags
decl_stmt|;
comment|/* additional flags PMC_F_... */
name|struct
name|pmc_owner
modifier|*
name|pm_owner
decl_stmt|;
comment|/* owner thread state */
name|int
name|pm_runcount
decl_stmt|;
comment|/* #cpus currently on */
name|enum
name|pmc_state
name|pm_state
decl_stmt|;
comment|/* current PMC state */
name|uint32_t
name|pm_overflowcnt
decl_stmt|;
comment|/* count overflow interrupts */
comment|/* 	 * The PMC ID field encodes the row-index for the PMC, its 	 * mode, class and the CPU# associated with the PMC. 	 */
name|pmc_id_t
name|pm_id
decl_stmt|;
comment|/* allocated PMC id */
comment|/* md extensions */
name|union
name|pmc_md_pmc
name|pm_md
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Accessor macros for 'struct pmc'  */
end_comment

begin_define
define|#
directive|define
name|PMC_TO_MODE
parameter_list|(
name|P
parameter_list|)
value|PMC_ID_TO_MODE((P)->pm_id)
end_define

begin_define
define|#
directive|define
name|PMC_TO_CLASS
parameter_list|(
name|P
parameter_list|)
value|PMC_ID_TO_CLASS((P)->pm_id)
end_define

begin_define
define|#
directive|define
name|PMC_TO_ROWINDEX
parameter_list|(
name|P
parameter_list|)
value|PMC_ID_TO_ROWINDEX((P)->pm_id)
end_define

begin_define
define|#
directive|define
name|PMC_TO_CPU
parameter_list|(
name|P
parameter_list|)
value|PMC_ID_TO_CPU((P)->pm_id)
end_define

begin_comment
comment|/*  * struct pmc_process  *  * Record a 'target' process being profiled.  *  * The target process being profiled could be different from the owner  * process which allocated the PMCs.  Each target process descriptor  * is associated with NHWPMC 'struct pmc *' pointers.  Each PMC at a  * given hardware row-index 'n' will use slot 'n' of the 'pp_pmcs[]'  * array.  The size of this structure is thus PMC architecture  * dependent.  *  */
end_comment

begin_struct
struct|struct
name|pmc_targetstate
block|{
name|struct
name|pmc
modifier|*
name|pp_pmc
decl_stmt|;
comment|/* target PMC */
name|pmc_value_t
name|pp_pmcval
decl_stmt|;
comment|/* per-process value */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pmc_process
block|{
name|LIST_ENTRY
argument_list|(
argument|pmc_process
argument_list|)
name|pp_next
expr_stmt|;
comment|/* hash chain */
name|int
name|pp_refcnt
decl_stmt|;
comment|/* reference count */
name|uint32_t
name|pp_flags
decl_stmt|;
comment|/* flags PMC_PP_* */
name|struct
name|proc
modifier|*
name|pp_proc
decl_stmt|;
comment|/* target thread */
name|struct
name|pmc_targetstate
name|pp_pmcs
index|[]
decl_stmt|;
comment|/* NHWPMCs */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PMC_PP_ENABLE_MSR_ACCESS
value|0x00000001
end_define

begin_comment
comment|/*  * struct pmc_owner  *  * We associate a PMC with an 'owner' process.  *  * A process can be associated with 0..NCPUS*NHWPMC PMCs during its  * lifetime, where NCPUS is the numbers of CPUS in the system and  * NHWPMC is the number of hardware PMCs per CPU.  These are  * maintained in the list headed by the 'po_pmcs' to save on space.  *  */
end_comment

begin_struct
struct|struct
name|pmc_owner
block|{
name|LIST_ENTRY
argument_list|(
argument|pmc_owner
argument_list|)
name|po_next
expr_stmt|;
comment|/* hash chain */
name|LIST_ENTRY
argument_list|(
argument|pmc_owner
argument_list|)
name|po_ssnext
expr_stmt|;
comment|/* list of SS PMC owners */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|pmc
argument_list|)
name|po_pmcs
expr_stmt|;
comment|/* owned PMC list */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|pmclog_buffer
argument_list|)
name|po_logbuffers
expr_stmt|;
comment|/* (o) logbuffer list */
name|struct
name|mtx
name|po_mtx
decl_stmt|;
comment|/* spin lock for (o) */
name|struct
name|proc
modifier|*
name|po_owner
decl_stmt|;
comment|/* owner proc */
name|uint32_t
name|po_flags
decl_stmt|;
comment|/* (k) flags PMC_PO_* */
name|struct
name|proc
modifier|*
name|po_kthread
decl_stmt|;
comment|/* (k) helper kthread */
name|struct
name|pmclog_buffer
modifier|*
name|po_curbuf
decl_stmt|;
comment|/* current log buffer */
name|struct
name|file
modifier|*
name|po_file
decl_stmt|;
comment|/* file reference */
name|int
name|po_error
decl_stmt|;
comment|/* recorded error */
name|short
name|po_sscount
decl_stmt|;
comment|/* # SS PMCs owned */
name|short
name|po_logprocmaps
decl_stmt|;
comment|/* global mappings done */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PMC_PO_OWNS_LOGFILE
value|0x00000001
end_define

begin_comment
comment|/* has a log file */
end_comment

begin_define
define|#
directive|define
name|PMC_PO_SHUTDOWN
value|0x00000010
end_define

begin_comment
comment|/* in the process of shutdown */
end_comment

begin_define
define|#
directive|define
name|PMC_PO_INITIAL_MAPPINGS_DONE
value|0x00000020
end_define

begin_comment
comment|/*  * struct pmc_hw -- describe the state of the PMC hardware  *  * When in use, a HW PMC is associated with one allocated 'struct pmc'  * pointed to by field 'phw_pmc'.  When inactive, this field is NULL.  *  * On an SMP box, one or more HW PMC's in process virtual mode with  * the same 'phw_pmc' could be executing on different CPUs.  In order  * to handle this case correctly, we need to ensure that only  * incremental counts get added to the saved value in the associated  * 'struct pmc'.  The 'phw_save' field is used to keep the saved PMC  * value at the time the hardware is started during this context  * switch (i.e., the difference between the new (hardware) count and  * the saved count is atomically added to the count field in 'struct  * pmc' at context switch time).  *  */
end_comment

begin_struct
struct|struct
name|pmc_hw
block|{
name|uint32_t
name|phw_state
decl_stmt|;
comment|/* see PHW_* macros below */
name|struct
name|pmc
modifier|*
name|phw_pmc
decl_stmt|;
comment|/* current thread PMC */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PMC_PHW_RI_MASK
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|PMC_PHW_CPU_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|PMC_PHW_CPU_MASK
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|PMC_PHW_FLAGS_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|PMC_PHW_FLAGS_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|PMC_PHW_INDEX_TO_STATE
parameter_list|(
name|ri
parameter_list|)
value|((ri)& PMC_PHW_RI_MASK)
end_define

begin_define
define|#
directive|define
name|PMC_PHW_STATE_TO_INDEX
parameter_list|(
name|state
parameter_list|)
value|((state)& PMC_PHW_RI_MASK)
end_define

begin_define
define|#
directive|define
name|PMC_PHW_CPU_TO_STATE
parameter_list|(
name|cpu
parameter_list|)
value|(((cpu)<< PMC_PHW_CPU_SHIFT)& \ 	PMC_PHW_CPU_MASK)
end_define

begin_define
define|#
directive|define
name|PMC_PHW_STATE_TO_CPU
parameter_list|(
name|state
parameter_list|)
value|(((state)& PMC_PHW_CPU_MASK)>> \ 	PMC_PHW_CPU_SHIFT)
end_define

begin_define
define|#
directive|define
name|PMC_PHW_FLAGS_TO_STATE
parameter_list|(
name|flags
parameter_list|)
value|(((flags)<< PMC_PHW_FLAGS_SHIFT)& \ 	PMC_PHW_FLAGS_MASK)
end_define

begin_define
define|#
directive|define
name|PMC_PHW_STATE_TO_FLAGS
parameter_list|(
name|state
parameter_list|)
value|(((state)& PMC_PHW_FLAGS_MASK)>> \ 	PMC_PHW_FLAGS_SHIFT)
end_define

begin_define
define|#
directive|define
name|PMC_PHW_FLAG_IS_ENABLED
value|(PMC_PHW_FLAGS_TO_STATE(0x01))
end_define

begin_define
define|#
directive|define
name|PMC_PHW_FLAG_IS_SHAREABLE
value|(PMC_PHW_FLAGS_TO_STATE(0x02))
end_define

begin_comment
comment|/*  * struct pmc_sample  *  * Space for N (tunable) PC samples and associated control data.  */
end_comment

begin_struct
struct|struct
name|pmc_sample
block|{
name|uint16_t
name|ps_nsamples
decl_stmt|;
comment|/* callchain depth */
name|uint8_t
name|ps_cpu
decl_stmt|;
comment|/* cpu number */
name|uint8_t
name|ps_flags
decl_stmt|;
comment|/* other flags */
name|pid_t
name|ps_pid
decl_stmt|;
comment|/* process PID or -1 */
name|struct
name|thread
modifier|*
name|ps_td
decl_stmt|;
comment|/* which thread */
name|struct
name|pmc
modifier|*
name|ps_pmc
decl_stmt|;
comment|/* interrupting PMC */
name|uintptr_t
modifier|*
name|ps_pc
decl_stmt|;
comment|/* (const) callchain start */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PMC_SAMPLE_FREE
value|((uint16_t) 0)
end_define

begin_define
define|#
directive|define
name|PMC_SAMPLE_INUSE
value|((uint16_t) 0xFFFF)
end_define

begin_struct
struct|struct
name|pmc_samplebuffer
block|{
name|struct
name|pmc_sample
modifier|*
specifier|volatile
name|ps_read
decl_stmt|;
comment|/* read pointer */
name|struct
name|pmc_sample
modifier|*
specifier|volatile
name|ps_write
decl_stmt|;
comment|/* write pointer */
name|uintptr_t
modifier|*
name|ps_callchains
decl_stmt|;
comment|/* all saved call chains */
name|struct
name|pmc_sample
modifier|*
name|ps_fence
decl_stmt|;
comment|/* one beyond ps_samples[] */
name|struct
name|pmc_sample
name|ps_samples
index|[]
decl_stmt|;
comment|/* array of sample entries */
block|}
struct|;
end_struct

begin_comment
comment|/*  * struct pmc_cpustate  *  * A CPU is modelled as a collection of HW PMCs with space for additional  * flags.  */
end_comment

begin_struct
struct|struct
name|pmc_cpu
block|{
name|uint32_t
name|pc_state
decl_stmt|;
comment|/* physical cpu number + flags */
name|struct
name|pmc_samplebuffer
modifier|*
name|pc_sb
index|[
literal|2
index|]
decl_stmt|;
comment|/* space for samples */
name|struct
name|pmc_hw
modifier|*
name|pc_hwpmcs
index|[]
decl_stmt|;
comment|/* 'npmc' pointers */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PMC_PCPU_CPU_MASK
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|PMC_PCPU_FLAGS_MASK
value|0xFFFFFF00
end_define

begin_define
define|#
directive|define
name|PMC_PCPU_FLAGS_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|PMC_PCPU_STATE_TO_CPU
parameter_list|(
name|S
parameter_list|)
value|((S)& PMC_PCPU_CPU_MASK)
end_define

begin_define
define|#
directive|define
name|PMC_PCPU_STATE_TO_FLAGS
parameter_list|(
name|S
parameter_list|)
value|(((S)& PMC_PCPU_FLAGS_MASK)>> PMC_PCPU_FLAGS_SHIFT)
end_define

begin_define
define|#
directive|define
name|PMC_PCPU_FLAGS_TO_STATE
parameter_list|(
name|F
parameter_list|)
value|(((F)<< PMC_PCPU_FLAGS_SHIFT)& PMC_PCPU_FLAGS_MASK)
end_define

begin_define
define|#
directive|define
name|PMC_PCPU_CPU_TO_STATE
parameter_list|(
name|C
parameter_list|)
value|((C)& PMC_PCPU_CPU_MASK)
end_define

begin_define
define|#
directive|define
name|PMC_PCPU_FLAG_HTT
value|(PMC_PCPU_FLAGS_TO_STATE(0x1))
end_define

begin_comment
comment|/*  * struct pmc_binding  *  * CPU binding information.  */
end_comment

begin_struct
struct|struct
name|pmc_binding
block|{
name|int
name|pb_bound
decl_stmt|;
comment|/* is bound? */
name|int
name|pb_cpu
decl_stmt|;
comment|/* if so, to which CPU */
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|pmc_mdep
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * struct pmc_classdep  *  * PMC class-dependent operations.  */
end_comment

begin_struct
struct|struct
name|pmc_classdep
block|{
name|uint32_t
name|pcd_caps
decl_stmt|;
comment|/* class capabilities */
name|enum
name|pmc_class
name|pcd_class
decl_stmt|;
comment|/* class id */
name|int
name|pcd_num
decl_stmt|;
comment|/* number of PMCs */
name|int
name|pcd_ri
decl_stmt|;
comment|/* row index of the first PMC in class */
name|int
name|pcd_width
decl_stmt|;
comment|/* width of the PMC */
comment|/* configuring/reading/writing the hardware PMCs */
name|int
function_decl|(
modifier|*
name|pcd_config_pmc
function_decl|)
parameter_list|(
name|int
name|_cpu
parameter_list|,
name|int
name|_ri
parameter_list|,
name|struct
name|pmc
modifier|*
name|_pm
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pcd_get_config
function_decl|)
parameter_list|(
name|int
name|_cpu
parameter_list|,
name|int
name|_ri
parameter_list|,
name|struct
name|pmc
modifier|*
modifier|*
name|_ppm
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pcd_read_pmc
function_decl|)
parameter_list|(
name|int
name|_cpu
parameter_list|,
name|int
name|_ri
parameter_list|,
name|pmc_value_t
modifier|*
name|_value
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pcd_write_pmc
function_decl|)
parameter_list|(
name|int
name|_cpu
parameter_list|,
name|int
name|_ri
parameter_list|,
name|pmc_value_t
name|_value
parameter_list|)
function_decl|;
comment|/* pmc allocation/release */
name|int
function_decl|(
modifier|*
name|pcd_allocate_pmc
function_decl|)
parameter_list|(
name|int
name|_cpu
parameter_list|,
name|int
name|_ri
parameter_list|,
name|struct
name|pmc
modifier|*
name|_t
parameter_list|,
specifier|const
name|struct
name|pmc_op_pmcallocate
modifier|*
name|_a
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pcd_release_pmc
function_decl|)
parameter_list|(
name|int
name|_cpu
parameter_list|,
name|int
name|_ri
parameter_list|,
name|struct
name|pmc
modifier|*
name|_pm
parameter_list|)
function_decl|;
comment|/* starting and stopping PMCs */
name|int
function_decl|(
modifier|*
name|pcd_start_pmc
function_decl|)
parameter_list|(
name|int
name|_cpu
parameter_list|,
name|int
name|_ri
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pcd_stop_pmc
function_decl|)
parameter_list|(
name|int
name|_cpu
parameter_list|,
name|int
name|_ri
parameter_list|)
function_decl|;
comment|/* description */
name|int
function_decl|(
modifier|*
name|pcd_describe
function_decl|)
parameter_list|(
name|int
name|_cpu
parameter_list|,
name|int
name|_ri
parameter_list|,
name|struct
name|pmc_info
modifier|*
name|_pi
parameter_list|,
name|struct
name|pmc
modifier|*
modifier|*
name|_ppmc
parameter_list|)
function_decl|;
comment|/* class-dependent initialization& finalization */
name|int
function_decl|(
modifier|*
name|pcd_pcpu_init
function_decl|)
parameter_list|(
name|struct
name|pmc_mdep
modifier|*
name|_md
parameter_list|,
name|int
name|_cpu
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pcd_pcpu_fini
function_decl|)
parameter_list|(
name|struct
name|pmc_mdep
modifier|*
name|_md
parameter_list|,
name|int
name|_cpu
parameter_list|)
function_decl|;
comment|/* machine-specific interface */
name|int
function_decl|(
modifier|*
name|pcd_get_msr
function_decl|)
parameter_list|(
name|int
name|_ri
parameter_list|,
name|uint32_t
modifier|*
name|_msr
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * struct pmc_mdep  *  * Machine dependent bits needed per CPU type.  */
end_comment

begin_struct
struct|struct
name|pmc_mdep
block|{
name|uint32_t
name|pmd_cputype
decl_stmt|;
comment|/* from enum pmc_cputype */
name|uint32_t
name|pmd_npmc
decl_stmt|;
comment|/* number of PMCs per CPU */
name|uint32_t
name|pmd_nclass
decl_stmt|;
comment|/* number of PMC classes present */
comment|/* 	 * Machine dependent methods. 	 */
comment|/* per-cpu initialization and finalization */
name|int
function_decl|(
modifier|*
name|pmd_pcpu_init
function_decl|)
parameter_list|(
name|struct
name|pmc_mdep
modifier|*
name|_md
parameter_list|,
name|int
name|_cpu
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pmd_pcpu_fini
function_decl|)
parameter_list|(
name|struct
name|pmc_mdep
modifier|*
name|_md
parameter_list|,
name|int
name|_cpu
parameter_list|)
function_decl|;
comment|/* thread context switch in/out */
name|int
function_decl|(
modifier|*
name|pmd_switch_in
function_decl|)
parameter_list|(
name|struct
name|pmc_cpu
modifier|*
name|_p
parameter_list|,
name|struct
name|pmc_process
modifier|*
name|_pp
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|pmd_switch_out
function_decl|)
parameter_list|(
name|struct
name|pmc_cpu
modifier|*
name|_p
parameter_list|,
name|struct
name|pmc_process
modifier|*
name|_pp
parameter_list|)
function_decl|;
comment|/* handle a PMC interrupt */
name|int
function_decl|(
modifier|*
name|pmd_intr
function_decl|)
parameter_list|(
name|int
name|_cpu
parameter_list|,
name|struct
name|trapframe
modifier|*
name|_tf
parameter_list|)
function_decl|;
comment|/* 	 * PMC class dependent information. 	 */
name|struct
name|pmc_classdep
name|pmd_classdep
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per-CPU state.  This is an array of 'mp_ncpu' pointers  * to struct pmc_cpu descriptors.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pmc_cpu
modifier|*
modifier|*
name|pmc_pcpu
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* driver statistics */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pmc_op_getdriverstats
name|pmc_stats
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HWPMC_DEBUG
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/ktr.h>
end_include

begin_comment
comment|/* debug flags, major flag groups */
end_comment

begin_struct
struct|struct
name|pmc_debugflags
block|{
name|int
name|pdb_CPU
decl_stmt|;
name|int
name|pdb_CSW
decl_stmt|;
name|int
name|pdb_LOG
decl_stmt|;
name|int
name|pdb_MDP
decl_stmt|;
name|int
name|pdb_MOD
decl_stmt|;
name|int
name|pdb_OWN
decl_stmt|;
name|int
name|pdb_PMC
decl_stmt|;
name|int
name|pdb_PRC
decl_stmt|;
name|int
name|pdb_SAM
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|pmc_debugflags
name|pmc_debugflags
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|KTR_PMC
value|KTR_SUBSYS
end_define

begin_define
define|#
directive|define
name|PMC_DEBUG_STRSIZE
value|128
end_define

begin_define
define|#
directive|define
name|PMC_DEBUG_DEFAULT_FLAGS
value|{ 0, 0, 0, 0, 0, 0, 0, 0, 0 }
end_define

begin_define
define|#
directive|define
name|PMCDBG0
parameter_list|(
name|M
parameter_list|,
name|N
parameter_list|,
name|L
parameter_list|,
name|F
parameter_list|)
value|do {					\ 	if (pmc_debugflags.pdb_ ## M& (1<< PMC_DEBUG_MIN_ ## N))	\ 		CTR0(KTR_PMC, #M ":" #N ":" #L  ": " F);		\ } while (0)
end_define

begin_define
define|#
directive|define
name|PMCDBG1
parameter_list|(
name|M
parameter_list|,
name|N
parameter_list|,
name|L
parameter_list|,
name|F
parameter_list|,
name|p1
parameter_list|)
value|do {					\ 	if (pmc_debugflags.pdb_ ## M& (1<< PMC_DEBUG_MIN_ ## N))	\ 		CTR1(KTR_PMC, #M ":" #N ":" #L  ": " F, p1);		\ } while (0)
end_define

begin_define
define|#
directive|define
name|PMCDBG2
parameter_list|(
name|M
parameter_list|,
name|N
parameter_list|,
name|L
parameter_list|,
name|F
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|)
value|do {				\ 	if (pmc_debugflags.pdb_ ## M& (1<< PMC_DEBUG_MIN_ ## N))	\ 		CTR2(KTR_PMC, #M ":" #N ":" #L  ": " F, p1, p2);	\ } while (0)
end_define

begin_define
define|#
directive|define
name|PMCDBG3
parameter_list|(
name|M
parameter_list|,
name|N
parameter_list|,
name|L
parameter_list|,
name|F
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|)
value|do {				\ 	if (pmc_debugflags.pdb_ ## M& (1<< PMC_DEBUG_MIN_ ## N))	\ 		CTR3(KTR_PMC, #M ":" #N ":" #L  ": " F, p1, p2, p3);	\ } while (0)
end_define

begin_define
define|#
directive|define
name|PMCDBG4
parameter_list|(
name|M
parameter_list|,
name|N
parameter_list|,
name|L
parameter_list|,
name|F
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|)
value|do {			\ 	if (pmc_debugflags.pdb_ ## M& (1<< PMC_DEBUG_MIN_ ## N))	\ 		CTR4(KTR_PMC, #M ":" #N ":" #L  ": " F, p1, p2, p3, p4);\ } while (0)
end_define

begin_define
define|#
directive|define
name|PMCDBG5
parameter_list|(
name|M
parameter_list|,
name|N
parameter_list|,
name|L
parameter_list|,
name|F
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|,
name|p5
parameter_list|)
value|do {			\ 	if (pmc_debugflags.pdb_ ## M& (1<< PMC_DEBUG_MIN_ ## N))	\ 		CTR5(KTR_PMC, #M ":" #N ":" #L  ": " F, p1, p2, p3, p4,	\ 		    p5);						\ } while (0)
end_define

begin_define
define|#
directive|define
name|PMCDBG6
parameter_list|(
name|M
parameter_list|,
name|N
parameter_list|,
name|L
parameter_list|,
name|F
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|,
name|p5
parameter_list|,
name|p6
parameter_list|)
value|do {		\ 	if (pmc_debugflags.pdb_ ## M& (1<< PMC_DEBUG_MIN_ ## N))	\ 		CTR6(KTR_PMC, #M ":" #N ":" #L  ": " F, p1, p2, p3, p4,	\ 		    p5, p6);						\ } while (0)
end_define

begin_comment
comment|/* Major numbers */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MAJ_CPU
value|0
end_define

begin_comment
comment|/* cpu switches */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MAJ_CSW
value|1
end_define

begin_comment
comment|/* context switches */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MAJ_LOG
value|2
end_define

begin_comment
comment|/* logging */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MAJ_MDP
value|3
end_define

begin_comment
comment|/* machine dependent */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MAJ_MOD
value|4
end_define

begin_comment
comment|/* misc module infrastructure */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MAJ_OWN
value|5
end_define

begin_comment
comment|/* owner */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MAJ_PMC
value|6
end_define

begin_comment
comment|/* pmc management */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MAJ_PRC
value|7
end_define

begin_comment
comment|/* processes */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MAJ_SAM
value|8
end_define

begin_comment
comment|/* sampling */
end_comment

begin_comment
comment|/* Minor numbers */
end_comment

begin_comment
comment|/* Common (8 bits) */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_ALL
value|0
end_define

begin_comment
comment|/* allocation */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_REL
value|1
end_define

begin_comment
comment|/* release */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_OPS
value|2
end_define

begin_comment
comment|/* ops: start, stop, ... */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_INI
value|3
end_define

begin_comment
comment|/* init */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_FND
value|4
end_define

begin_comment
comment|/* find */
end_comment

begin_comment
comment|/* MODULE */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_PMH
value|14
end_define

begin_comment
comment|/* pmc_hook */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_PMS
value|15
end_define

begin_comment
comment|/* pmc_syscall */
end_comment

begin_comment
comment|/* OWN */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_ORM
value|8
end_define

begin_comment
comment|/* owner remove */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_OMR
value|9
end_define

begin_comment
comment|/* owner maybe remove */
end_comment

begin_comment
comment|/* PROCESSES */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_TLK
value|8
end_define

begin_comment
comment|/* link target */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_TUL
value|9
end_define

begin_comment
comment|/* unlink target */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_EXT
value|10
end_define

begin_comment
comment|/* process exit */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_EXC
value|11
end_define

begin_comment
comment|/* process exec */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_FRK
value|12
end_define

begin_comment
comment|/* process fork */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_ATT
value|13
end_define

begin_comment
comment|/* attach/detach */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_SIG
value|14
end_define

begin_comment
comment|/* signalling */
end_comment

begin_comment
comment|/* CONTEXT SWITCHES */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_SWI
value|8
end_define

begin_comment
comment|/* switch in */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_SWO
value|9
end_define

begin_comment
comment|/* switch out */
end_comment

begin_comment
comment|/* PMC */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_REG
value|8
end_define

begin_comment
comment|/* pmc register */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_ALR
value|9
end_define

begin_comment
comment|/* allocate row */
end_comment

begin_comment
comment|/* MACHINE DEPENDENT LAYER */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_REA
value|8
end_define

begin_comment
comment|/* read */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_WRI
value|9
end_define

begin_comment
comment|/* write */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_CFG
value|10
end_define

begin_comment
comment|/* config */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_STA
value|11
end_define

begin_comment
comment|/* start */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_STO
value|12
end_define

begin_comment
comment|/* stop */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_INT
value|13
end_define

begin_comment
comment|/* interrupts */
end_comment

begin_comment
comment|/* CPU */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_BND
value|8
end_define

begin_comment
comment|/* bind */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_SEL
value|9
end_define

begin_comment
comment|/* select */
end_comment

begin_comment
comment|/* LOG */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_GTB
value|8
end_define

begin_comment
comment|/* get buf */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_SIO
value|9
end_define

begin_comment
comment|/* schedule i/o */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_FLS
value|10
end_define

begin_comment
comment|/* flush */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_SAM
value|11
end_define

begin_comment
comment|/* sample */
end_comment

begin_define
define|#
directive|define
name|PMC_DEBUG_MIN_CLO
value|12
end_define

begin_comment
comment|/* close */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PMCDBG0
parameter_list|(
name|M
parameter_list|,
name|N
parameter_list|,
name|L
parameter_list|,
name|F
parameter_list|)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|PMCDBG1
parameter_list|(
name|M
parameter_list|,
name|N
parameter_list|,
name|L
parameter_list|,
name|F
parameter_list|,
name|p1
parameter_list|)
end_define

begin_define
define|#
directive|define
name|PMCDBG2
parameter_list|(
name|M
parameter_list|,
name|N
parameter_list|,
name|L
parameter_list|,
name|F
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|)
end_define

begin_define
define|#
directive|define
name|PMCDBG3
parameter_list|(
name|M
parameter_list|,
name|N
parameter_list|,
name|L
parameter_list|,
name|F
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|)
end_define

begin_define
define|#
directive|define
name|PMCDBG4
parameter_list|(
name|M
parameter_list|,
name|N
parameter_list|,
name|L
parameter_list|,
name|F
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|)
end_define

begin_define
define|#
directive|define
name|PMCDBG5
parameter_list|(
name|M
parameter_list|,
name|N
parameter_list|,
name|L
parameter_list|,
name|F
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|,
name|p5
parameter_list|)
end_define

begin_define
define|#
directive|define
name|PMCDBG6
parameter_list|(
name|M
parameter_list|,
name|N
parameter_list|,
name|L
parameter_list|,
name|F
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|,
name|p5
parameter_list|,
name|p6
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* declare a dedicated memory pool */
end_comment

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_PMC
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Functions  */
end_comment

begin_function_decl
name|struct
name|pmc_mdep
modifier|*
name|pmc_md_initialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* MD init function */
end_comment

begin_function_decl
name|void
name|pmc_md_finalize
parameter_list|(
name|struct
name|pmc_mdep
modifier|*
name|_md
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* MD fini function */
end_comment

begin_function_decl
name|int
name|pmc_getrowdisp
parameter_list|(
name|int
name|_ri
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmc_process_interrupt
parameter_list|(
name|int
name|_cpu
parameter_list|,
name|int
name|_soft
parameter_list|,
name|struct
name|pmc
modifier|*
name|_pm
parameter_list|,
name|struct
name|trapframe
modifier|*
name|_tf
parameter_list|,
name|int
name|_inuserspace
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmc_save_kernel_callchain
parameter_list|(
name|uintptr_t
modifier|*
name|_cc
parameter_list|,
name|int
name|_maxsamples
parameter_list|,
name|struct
name|trapframe
modifier|*
name|_tf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmc_save_user_callchain
parameter_list|(
name|uintptr_t
modifier|*
name|_cc
parameter_list|,
name|int
name|_maxsamples
parameter_list|,
name|struct
name|trapframe
modifier|*
name|_tf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|pmc_mdep
modifier|*
name|pmc_mdep_alloc
parameter_list|(
name|int
name|nclasses
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmc_mdep_free
parameter_list|(
name|struct
name|pmc_mdep
modifier|*
name|md
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_PMC_H_ */
end_comment

end_unit

