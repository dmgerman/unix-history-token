begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1989, 2010, Oracle and/or its affiliates. All rights reserved.  * Copyright (c) 2012 by Delphix. All rights reserved.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_CPUVAR_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_CPUVAR_H
end_define

begin_include
include|#
directive|include
file|<sys/thread.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysinfo.h>
end_include

begin_comment
comment|/* has cpu_stat_t definition */
end_comment

begin_include
include|#
directive|include
file|<sys/disp.h>
end_include

begin_include
include|#
directive|include
file|<sys/processor.h>
end_include

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|_KMEMUSER
argument_list|)
operator|)
operator|&&
name|defined
argument_list|(
name|_MACHDEP
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/machcpuvar.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/bitmap.h>
end_include

begin_include
include|#
directive|include
file|<sys/rwlock.h>
end_include

begin_include
include|#
directive|include
file|<sys/msacct.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|defined
argument_list|(
name|_ASM_INLINES
argument_list|)
operator|&&
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
expr|\
operator|(
name|defined
argument_list|(
name|__i386
argument_list|)
operator|||
name|defined
argument_list|(
name|__amd64
argument_list|)
operator|)
end_if

begin_include
include|#
directive|include
file|<asm/cpuvar.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
struct_decl|struct
name|squeue_set_s
struct_decl|;
define|#
directive|define
name|CPU_CACHE_COHERENCE_SIZE
value|64
define|#
directive|define
name|S_LOADAVG_SZ
value|11
define|#
directive|define
name|S_MOVAVG_SZ
value|10
struct|struct
name|loadavg_s
block|{
name|int
name|lg_cur
decl_stmt|;
comment|/* current loadavg entry */
name|unsigned
name|int
name|lg_len
decl_stmt|;
comment|/* number entries recorded */
name|hrtime_t
name|lg_total
decl_stmt|;
comment|/* used to temporarily hold load totals */
name|hrtime_t
name|lg_loads
index|[
name|S_LOADAVG_SZ
index|]
decl_stmt|;
comment|/* table of recorded entries */
block|}
struct|;
comment|/*  * For fast event tracing.  */
struct_decl|struct
name|ftrace_record
struct_decl|;
typedef|typedef
struct|struct
name|ftrace_data
block|{
name|int
name|ftd_state
decl_stmt|;
comment|/* ftrace flags */
name|kmutex_t
name|ftd_unused
decl_stmt|;
comment|/* ftrace buffer lock, unused */
name|struct
name|ftrace_record
modifier|*
name|ftd_cur
decl_stmt|;
comment|/* current record */
name|struct
name|ftrace_record
modifier|*
name|ftd_first
decl_stmt|;
comment|/* first record */
name|struct
name|ftrace_record
modifier|*
name|ftd_last
decl_stmt|;
comment|/* last record */
block|}
name|ftrace_data_t
typedef|;
struct_decl|struct
name|cyc_cpu
struct_decl|;
struct_decl|struct
name|nvlist
struct_decl|;
comment|/*  * Per-CPU data.  *  * Be careful adding new members: if they are not the same in all modules (e.g.  * change size depending on a #define), CTF uniquification can fail to work  * properly.  Furthermore, this is transitive in that it applies recursively to  * all types pointed to by cpu_t.  */
typedef|typedef
struct|struct
name|cpu
block|{
name|processorid_t
name|cpu_id
decl_stmt|;
comment|/* CPU number */
name|processorid_t
name|cpu_seqid
decl_stmt|;
comment|/* sequential CPU id (0..ncpus-1) */
specifier|volatile
name|cpu_flag_t
name|cpu_flags
decl_stmt|;
comment|/* flags indicating CPU state */
name|struct
name|cpu
modifier|*
name|cpu_self
decl_stmt|;
comment|/* pointer to itself */
name|kthread_t
modifier|*
name|cpu_thread
decl_stmt|;
comment|/* current thread */
name|kthread_t
modifier|*
name|cpu_idle_thread
decl_stmt|;
comment|/* idle thread for this CPU */
name|kthread_t
modifier|*
name|cpu_pause_thread
decl_stmt|;
comment|/* pause thread for this CPU */
name|klwp_id_t
name|cpu_lwp
decl_stmt|;
comment|/* current lwp (if any) */
name|klwp_id_t
name|cpu_fpowner
decl_stmt|;
comment|/* currently loaded fpu owner */
name|struct
name|cpupart
modifier|*
name|cpu_part
decl_stmt|;
comment|/* partition with this CPU */
name|struct
name|lgrp_ld
modifier|*
name|cpu_lpl
decl_stmt|;
comment|/* pointer to this cpu's load */
name|int
name|cpu_cache_offset
decl_stmt|;
comment|/* see kmem.c for details */
comment|/* 	 * Links to other CPUs.  It is safe to walk these lists if 	 * one of the following is true: 	 * 	- cpu_lock held 	 * 	- preemption disabled via kpreempt_disable 	 * 	- PIL>= DISP_LEVEL 	 * 	- acting thread is an interrupt thread 	 * 	- all other CPUs are paused 	 */
name|struct
name|cpu
modifier|*
name|cpu_next
decl_stmt|;
comment|/* next existing CPU */
name|struct
name|cpu
modifier|*
name|cpu_prev
decl_stmt|;
comment|/* prev existing CPU */
name|struct
name|cpu
modifier|*
name|cpu_next_onln
decl_stmt|;
comment|/* next online (enabled) CPU */
name|struct
name|cpu
modifier|*
name|cpu_prev_onln
decl_stmt|;
comment|/* prev online (enabled) CPU */
name|struct
name|cpu
modifier|*
name|cpu_next_part
decl_stmt|;
comment|/* next CPU in partition */
name|struct
name|cpu
modifier|*
name|cpu_prev_part
decl_stmt|;
comment|/* prev CPU in partition */
name|struct
name|cpu
modifier|*
name|cpu_next_lgrp
decl_stmt|;
comment|/* next CPU in latency group */
name|struct
name|cpu
modifier|*
name|cpu_prev_lgrp
decl_stmt|;
comment|/* prev CPU in latency group */
name|struct
name|cpu
modifier|*
name|cpu_next_lpl
decl_stmt|;
comment|/* next CPU in lgrp partition */
name|struct
name|cpu
modifier|*
name|cpu_prev_lpl
decl_stmt|;
name|struct
name|cpu_pg
modifier|*
name|cpu_pg
decl_stmt|;
comment|/* cpu's processor groups */
name|void
modifier|*
name|cpu_reserved
index|[
literal|4
index|]
decl_stmt|;
comment|/* reserved for future use */
comment|/* 	 * Scheduling variables. 	 */
name|disp_t
modifier|*
name|cpu_disp
decl_stmt|;
comment|/* dispatch queue data */
comment|/* 	 * Note that cpu_disp is set before the CPU is added to the system 	 * and is never modified.  Hence, no additional locking is needed 	 * beyond what's necessary to access the cpu_t structure. 	 */
name|char
name|cpu_runrun
decl_stmt|;
comment|/* scheduling flag - set to preempt */
name|char
name|cpu_kprunrun
decl_stmt|;
comment|/* force kernel preemption */
name|pri_t
name|cpu_chosen_level
decl_stmt|;
comment|/* priority at which cpu */
comment|/* was chosen for scheduling */
name|kthread_t
modifier|*
name|cpu_dispthread
decl_stmt|;
comment|/* thread selected for dispatch */
name|disp_lock_t
name|cpu_thread_lock
decl_stmt|;
comment|/* dispatcher lock on current thread */
name|uint8_t
name|cpu_disp_flags
decl_stmt|;
comment|/* flags used by dispatcher */
comment|/* 	 * The following field is updated when ever the cpu_dispthread 	 * changes. Also in places, where the current thread(cpu_dispthread) 	 * priority changes. This is used in disp_lowpri_cpu() 	 */
name|pri_t
name|cpu_dispatch_pri
decl_stmt|;
comment|/* priority of cpu_dispthread */
name|clock_t
name|cpu_last_swtch
decl_stmt|;
comment|/* last time switched to new thread */
comment|/* 	 * Interrupt data. 	 */
name|caddr_t
name|cpu_intr_stack
decl_stmt|;
comment|/* interrupt stack */
name|kthread_t
modifier|*
name|cpu_intr_thread
decl_stmt|;
comment|/* interrupt thread list */
name|uint_t
name|cpu_intr_actv
decl_stmt|;
comment|/* interrupt levels active (bitmask) */
name|int
name|cpu_base_spl
decl_stmt|;
comment|/* priority for highest rupt active */
comment|/* 	 * Statistics. 	 */
name|cpu_stats_t
name|cpu_stats
decl_stmt|;
comment|/* per-CPU statistics */
name|struct
name|kstat
modifier|*
name|cpu_info_kstat
decl_stmt|;
comment|/* kstat for cpu info */
name|uintptr_t
name|cpu_profile_pc
decl_stmt|;
comment|/* kernel PC in profile interrupt */
name|uintptr_t
name|cpu_profile_upc
decl_stmt|;
comment|/* user PC in profile interrupt */
name|uintptr_t
name|cpu_profile_pil
decl_stmt|;
comment|/* PIL when profile interrupted */
name|ftrace_data_t
name|cpu_ftrace
decl_stmt|;
comment|/* per cpu ftrace data */
name|clock_t
name|cpu_deadman_counter
decl_stmt|;
comment|/* used by deadman() */
name|uint_t
name|cpu_deadman_countdown
decl_stmt|;
comment|/* used by deadman() */
name|kmutex_t
name|cpu_cpc_ctxlock
decl_stmt|;
comment|/* protects context for idle thread */
name|kcpc_ctx_t
modifier|*
name|cpu_cpc_ctx
decl_stmt|;
comment|/* performance counter context */
comment|/* 	 * Configuration information for the processor_info system call. 	 */
name|processor_info_t
name|cpu_type_info
decl_stmt|;
comment|/* config info */
name|time_t
name|cpu_state_begin
decl_stmt|;
comment|/* when CPU entered current state */
name|char
name|cpu_cpr_flags
decl_stmt|;
comment|/* CPR related info */
name|struct
name|cyc_cpu
modifier|*
name|cpu_cyclic
decl_stmt|;
comment|/* per cpu cyclic subsystem data */
name|struct
name|squeue_set_s
modifier|*
name|cpu_squeue_set
decl_stmt|;
comment|/* per cpu squeue set */
name|struct
name|nvlist
modifier|*
name|cpu_props
decl_stmt|;
comment|/* pool-related properties */
name|krwlock_t
name|cpu_ft_lock
decl_stmt|;
comment|/* DTrace: fasttrap lock */
name|uintptr_t
name|cpu_dtrace_caller
decl_stmt|;
comment|/* DTrace: caller, if any */
name|hrtime_t
name|cpu_dtrace_chillmark
decl_stmt|;
comment|/* DTrace: chill mark time */
name|hrtime_t
name|cpu_dtrace_chilled
decl_stmt|;
comment|/* DTrace: total chill time */
name|uint64_t
name|cpu_dtrace_probes
decl_stmt|;
comment|/* DTrace: total probes fired */
name|hrtime_t
name|cpu_dtrace_nsec
decl_stmt|;
comment|/* DTrace: ns in dtrace_probe */
specifier|volatile
name|uint16_t
name|cpu_mstate
decl_stmt|;
comment|/* cpu microstate */
specifier|volatile
name|uint16_t
name|cpu_mstate_gen
decl_stmt|;
comment|/* generation counter */
specifier|volatile
name|hrtime_t
name|cpu_mstate_start
decl_stmt|;
comment|/* cpu microstate start time */
specifier|volatile
name|hrtime_t
name|cpu_acct
index|[
name|NCMSTATES
index|]
decl_stmt|;
comment|/* cpu microstate data */
name|hrtime_t
name|cpu_intracct
index|[
name|NCMSTATES
index|]
decl_stmt|;
comment|/* interrupt mstate data */
name|hrtime_t
name|cpu_waitrq
decl_stmt|;
comment|/* cpu run-queue wait time */
name|struct
name|loadavg_s
name|cpu_loadavg
decl_stmt|;
comment|/* loadavg info for this cpu */
name|char
modifier|*
name|cpu_idstr
decl_stmt|;
comment|/* for printing and debugging */
name|char
modifier|*
name|cpu_brandstr
decl_stmt|;
comment|/* for printing */
comment|/* 	 * Sum of all device interrupt weights that are currently directed at 	 * this cpu. Cleared at start of interrupt redistribution. 	 */
name|int32_t
name|cpu_intr_weight
decl_stmt|;
name|void
modifier|*
name|cpu_vm_data
decl_stmt|;
name|struct
name|cpu_physid
modifier|*
name|cpu_physid
decl_stmt|;
comment|/* physical associations */
name|uint64_t
name|cpu_curr_clock
decl_stmt|;
comment|/* current clock freq in Hz */
name|char
modifier|*
name|cpu_supp_freqs
decl_stmt|;
comment|/* supported freqs in Hz */
name|uintptr_t
name|cpu_cpcprofile_pc
decl_stmt|;
comment|/* kernel PC in cpc interrupt */
name|uintptr_t
name|cpu_cpcprofile_upc
decl_stmt|;
comment|/* user PC in cpc interrupt */
comment|/* 	 * Interrupt load factor used by dispatcher& softcall 	 */
name|hrtime_t
name|cpu_intrlast
decl_stmt|;
comment|/* total interrupt time (nsec) */
name|int
name|cpu_intrload
decl_stmt|;
comment|/* interrupt load factor (0-99%) */
name|uint_t
name|cpu_rotor
decl_stmt|;
comment|/* for cheap pseudo-random numbers */
name|struct
name|cu_cpu_info
modifier|*
name|cpu_cu_info
decl_stmt|;
comment|/* capacity& util. info */
comment|/* 	 * cpu_generation is updated whenever CPU goes on-line or off-line. 	 * Updates to cpu_generation are protected by cpu_lock. 	 * 	 * See CPU_NEW_GENERATION() macro below. 	 */
specifier|volatile
name|uint_t
name|cpu_generation
decl_stmt|;
comment|/* tracking on/off-line */
comment|/* 	 * New members must be added /before/ this member, as the CTF tools 	 * rely on this being the last field before cpu_m, so they can 	 * correctly calculate the offset when synthetically adding the cpu_m 	 * member in objects that do not have it.  This fixup is required for 	 * uniquification to work correctly. 	 */
name|uintptr_t
name|cpu_m_pad
decl_stmt|;
if|#
directive|if
operator|(
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|_KMEMUSER
argument_list|)
operator|)
operator|&&
name|defined
argument_list|(
name|_MACHDEP
argument_list|)
name|struct
name|machcpu
name|cpu_m
decl_stmt|;
comment|/* per architecture info */
endif|#
directive|endif
block|}
name|cpu_t
typedef|;
comment|/*  * The cpu_core structure consists of per-CPU state available in any context.  * On some architectures, this may mean that the page(s) containing the  * NCPU-sized array of cpu_core structures must be locked in the TLB -- it  * is up to the platform to assure that this is performed properly.  Note that  * the structure is sized to avoid false sharing.  */
define|#
directive|define
name|CPUC_SIZE
value|(sizeof (uint16_t) + sizeof (uint8_t) + \ 				sizeof (uintptr_t) + sizeof (kmutex_t))
define|#
directive|define
name|CPUC_PADSIZE
value|CPU_CACHE_COHERENCE_SIZE - CPUC_SIZE
typedef|typedef
struct|struct
name|cpu_core
block|{
name|uint16_t
name|cpuc_dtrace_flags
decl_stmt|;
comment|/* DTrace flags */
name|uint8_t
name|cpuc_dcpc_intr_state
decl_stmt|;
comment|/* DCPC provider intr state */
name|uint8_t
name|cpuc_pad
index|[
name|CPUC_PADSIZE
index|]
decl_stmt|;
comment|/* padding */
name|uintptr_t
name|cpuc_dtrace_illval
decl_stmt|;
comment|/* DTrace illegal value */
name|kmutex_t
name|cpuc_pid_lock
decl_stmt|;
comment|/* DTrace pid provider lock */
block|}
name|cpu_core_t
typedef|;
ifdef|#
directive|ifdef
name|_KERNEL
specifier|extern
name|cpu_core_t
name|cpu_core
index|[]
decl_stmt|;
endif|#
directive|endif
comment|/* _KERNEL */
comment|/*  * CPU_ON_INTR() macro. Returns non-zero if currently on interrupt stack.  * Note that this isn't a test for a high PIL.  For example, cpu_intr_actv  * does not get updated when we go through sys_trap from TL>0 at high PIL.  * getpil() should be used instead to check for PIL levels.  */
define|#
directive|define
name|CPU_ON_INTR
parameter_list|(
name|cpup
parameter_list|)
value|((cpup)->cpu_intr_actv>> (LOCK_LEVEL + 1))
comment|/*  * Check to see if an interrupt thread might be active at a given ipl.  * If so return true.  * We must be conservative--it is ok to give a false yes, but a false no  * will cause disaster.  (But if the situation changes after we check it is  * ok--the caller is trying to ensure that an interrupt routine has been  * exited).  * This is used when trying to remove an interrupt handler from an autovector  * list in avintr.c.  */
define|#
directive|define
name|INTR_ACTIVE
parameter_list|(
name|cpup
parameter_list|,
name|level
parameter_list|)
define|\
value|((level)<= LOCK_LEVEL ? 	\ 	((cpup)->cpu_intr_actv& (1<< (level))) : (CPU_ON_INTR(cpup)))
comment|/*  * CPU_PSEUDO_RANDOM() returns a per CPU value that changes each time one  * looks at it. It's meant as a cheap mechanism to be incorporated in routines  * wanting to avoid biasing, but where true randomness isn't needed (just  * something that changes).  */
define|#
directive|define
name|CPU_PSEUDO_RANDOM
parameter_list|()
value|(CPU->cpu_rotor++)
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|_KMEMUSER
argument_list|)
define|#
directive|define
name|INTR_STACK_SIZE
value|MAX(DEFAULTSTKSZ, PAGESIZE)
comment|/* MEMBERS PROTECTED BY "atomicity": cpu_flags */
comment|/*  * Flags in the CPU structure.  *  * These are protected by cpu_lock (except during creation).  *  * Offlined-CPUs have three stages of being offline:  *  * CPU_ENABLE indicates that the CPU is participating in I/O interrupts  * that can be directed at a number of different CPUs.  If CPU_ENABLE  * is off, the CPU will not be given interrupts that can be sent elsewhere,  * but will still get interrupts from devices associated with that CPU only,  * and from other CPUs.  *  * CPU_OFFLINE indicates that the dispatcher should not allow any threads  * other than interrupt threads to run on that CPU.  A CPU will not have  * CPU_OFFLINE set if there are any bound threads (besides interrupts).  *  * CPU_QUIESCED is set if p_offline was able to completely turn idle the  * CPU and it will not have to run interrupt threads.  In this case it'll  * stay in the idle loop until CPU_QUIESCED is turned off.  *  * CPU_FROZEN is used only by CPR to mark CPUs that have been successfully  * suspended (in the suspend path), or have yet to be resumed (in the resume  * case).  *  * On some platforms CPUs can be individually powered off.  * The following flags are set for powered off CPUs: CPU_QUIESCED,  * CPU_OFFLINE, and CPU_POWEROFF.  The following flags are cleared:  * CPU_RUNNING, CPU_READY, CPU_EXISTS, and CPU_ENABLE.  */
define|#
directive|define
name|CPU_RUNNING
value|0x001
comment|/* CPU running */
define|#
directive|define
name|CPU_READY
value|0x002
comment|/* CPU ready for cross-calls */
define|#
directive|define
name|CPU_QUIESCED
value|0x004
comment|/* CPU will stay in idle */
define|#
directive|define
name|CPU_EXISTS
value|0x008
comment|/* CPU is configured */
define|#
directive|define
name|CPU_ENABLE
value|0x010
comment|/* CPU enabled for interrupts */
define|#
directive|define
name|CPU_OFFLINE
value|0x020
comment|/* CPU offline via p_online */
define|#
directive|define
name|CPU_POWEROFF
value|0x040
comment|/* CPU is powered off */
define|#
directive|define
name|CPU_FROZEN
value|0x080
comment|/* CPU is frozen via CPR suspend */
define|#
directive|define
name|CPU_SPARE
value|0x100
comment|/* CPU offline available for use */
define|#
directive|define
name|CPU_FAULTED
value|0x200
comment|/* CPU offline diagnosed faulty */
define|#
directive|define
name|FMT_CPU_FLAGS
define|\
value|"\20\12fault\11spare\10frozen"					\ 	"\7poweroff\6offline\5enable\4exist\3quiesced\2ready\1run"
define|#
directive|define
name|CPU_ACTIVE
parameter_list|(
name|cpu
parameter_list|)
value|(((cpu)->cpu_flags& CPU_OFFLINE) == 0)
comment|/*  * Flags for cpu_offline(), cpu_faulted(), and cpu_spare().  */
define|#
directive|define
name|CPU_FORCED
value|0x0001
comment|/* Force CPU offline */
comment|/*  * DTrace flags.  */
define|#
directive|define
name|CPU_DTRACE_NOFAULT
value|0x0001
comment|/* Don't fault */
define|#
directive|define
name|CPU_DTRACE_DROP
value|0x0002
comment|/* Drop this ECB */
define|#
directive|define
name|CPU_DTRACE_BADADDR
value|0x0004
comment|/* DTrace fault: bad address */
define|#
directive|define
name|CPU_DTRACE_BADALIGN
value|0x0008
comment|/* DTrace fault: bad alignment */
define|#
directive|define
name|CPU_DTRACE_DIVZERO
value|0x0010
comment|/* DTrace fault: divide by zero */
define|#
directive|define
name|CPU_DTRACE_ILLOP
value|0x0020
comment|/* DTrace fault: illegal operation */
define|#
directive|define
name|CPU_DTRACE_NOSCRATCH
value|0x0040
comment|/* DTrace fault: out of scratch */
define|#
directive|define
name|CPU_DTRACE_KPRIV
value|0x0080
comment|/* DTrace fault: bad kernel access */
define|#
directive|define
name|CPU_DTRACE_UPRIV
value|0x0100
comment|/* DTrace fault: bad user access */
define|#
directive|define
name|CPU_DTRACE_TUPOFLOW
value|0x0200
comment|/* DTrace fault: tuple stack overflow */
if|#
directive|if
name|defined
argument_list|(
name|__sparc
argument_list|)
define|#
directive|define
name|CPU_DTRACE_FAKERESTORE
value|0x0400
comment|/* pid provider hint to getreg */
endif|#
directive|endif
define|#
directive|define
name|CPU_DTRACE_ENTRY
value|0x0800
comment|/* pid provider hint to ustack() */
define|#
directive|define
name|CPU_DTRACE_BADSTACK
value|0x1000
comment|/* DTrace fault: bad stack */
define|#
directive|define
name|CPU_DTRACE_FAULT
value|(CPU_DTRACE_BADADDR | CPU_DTRACE_BADALIGN | \ 				CPU_DTRACE_DIVZERO | CPU_DTRACE_ILLOP | \ 				CPU_DTRACE_NOSCRATCH | CPU_DTRACE_KPRIV | \ 				CPU_DTRACE_UPRIV | CPU_DTRACE_TUPOFLOW | \ 				CPU_DTRACE_BADSTACK)
define|#
directive|define
name|CPU_DTRACE_ERROR
value|(CPU_DTRACE_FAULT | CPU_DTRACE_DROP)
comment|/*  * Dispatcher flags  * These flags must be changed only by the current CPU.  */
define|#
directive|define
name|CPU_DISP_DONTSTEAL
value|0x01
comment|/* CPU undergoing context swtch */
define|#
directive|define
name|CPU_DISP_HALTED
value|0x02
comment|/* CPU halted waiting for interrupt */
endif|#
directive|endif
comment|/* _KERNEL || _KMEMUSER */
if|#
directive|if
operator|(
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|_KMEMUSER
argument_list|)
operator|)
operator|&&
name|defined
argument_list|(
name|_MACHDEP
argument_list|)
comment|/*  * Macros for manipulating sets of CPUs as a bitmap.  Note that this  * bitmap may vary in size depending on the maximum CPU id a specific  * platform supports.  This may be different than the number of CPUs  * the platform supports, since CPU ids can be sparse.  We define two  * sets of macros; one for platforms where the maximum CPU id is less  * than the number of bits in a single word (32 in a 32-bit kernel,  * 64 in a 64-bit kernel), and one for platforms that require bitmaps  * of more than one word.  */
define|#
directive|define
name|CPUSET_WORDS
value|BT_BITOUL(NCPU)
define|#
directive|define
name|CPUSET_NOTINSET
value|((uint_t)-1)
if|#
directive|if
name|CPUSET_WORDS
operator|>
literal|1
typedef|typedef
struct|struct
name|cpuset
block|{
name|ulong_t
name|cpub
index|[
name|CPUSET_WORDS
index|]
decl_stmt|;
block|}
name|cpuset_t
typedef|;
comment|/*  * Private functions for manipulating cpusets that do not fit in a  * single word.  These should not be used directly; instead the  * CPUSET_* macros should be used so the code will be portable  * across different definitions of NCPU.  */
specifier|extern
name|void
name|cpuset_all
parameter_list|(
name|cpuset_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|cpuset_all_but
parameter_list|(
name|cpuset_t
modifier|*
parameter_list|,
name|uint_t
parameter_list|)
function_decl|;
specifier|extern
name|int
name|cpuset_isnull
parameter_list|(
name|cpuset_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|cpuset_cmp
parameter_list|(
name|cpuset_t
modifier|*
parameter_list|,
name|cpuset_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|cpuset_only
parameter_list|(
name|cpuset_t
modifier|*
parameter_list|,
name|uint_t
parameter_list|)
function_decl|;
specifier|extern
name|uint_t
name|cpuset_find
parameter_list|(
name|cpuset_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|cpuset_bounds
parameter_list|(
name|cpuset_t
modifier|*
parameter_list|,
name|uint_t
modifier|*
parameter_list|,
name|uint_t
modifier|*
parameter_list|)
function_decl|;
define|#
directive|define
name|CPUSET_ALL
parameter_list|(
name|set
parameter_list|)
value|cpuset_all(&(set))
define|#
directive|define
name|CPUSET_ALL_BUT
parameter_list|(
name|set
parameter_list|,
name|cpu
parameter_list|)
value|cpuset_all_but(&(set), cpu)
define|#
directive|define
name|CPUSET_ONLY
parameter_list|(
name|set
parameter_list|,
name|cpu
parameter_list|)
value|cpuset_only(&(set), cpu)
define|#
directive|define
name|CPU_IN_SET
parameter_list|(
name|set
parameter_list|,
name|cpu
parameter_list|)
value|BT_TEST((set).cpub, cpu)
define|#
directive|define
name|CPUSET_ADD
parameter_list|(
name|set
parameter_list|,
name|cpu
parameter_list|)
value|BT_SET((set).cpub, cpu)
define|#
directive|define
name|CPUSET_DEL
parameter_list|(
name|set
parameter_list|,
name|cpu
parameter_list|)
value|BT_CLEAR((set).cpub, cpu)
define|#
directive|define
name|CPUSET_ISNULL
parameter_list|(
name|set
parameter_list|)
value|cpuset_isnull(&(set))
define|#
directive|define
name|CPUSET_ISEQUAL
parameter_list|(
name|set1
parameter_list|,
name|set2
parameter_list|)
value|cpuset_cmp(&(set1),&(set2))
comment|/*  * Find one CPU in the cpuset.  * Sets "cpu" to the id of the found CPU, or CPUSET_NOTINSET if no cpu  * could be found. (i.e. empty set)  */
define|#
directive|define
name|CPUSET_FIND
parameter_list|(
name|set
parameter_list|,
name|cpu
parameter_list|)
value|{		\ 	cpu = cpuset_find(&(set));			\ }
comment|/*  * Determine the smallest and largest CPU id in the set. Returns  * CPUSET_NOTINSET in smallest and largest when set is empty.  */
define|#
directive|define
name|CPUSET_BOUNDS
parameter_list|(
name|set
parameter_list|,
name|smallest
parameter_list|,
name|largest
parameter_list|)
value|{		\ 	cpuset_bounds(&(set),&(smallest),&(largest));		\ }
comment|/*  * Atomic cpuset operations  * These are safe to use for concurrent cpuset manipulations.  * "xdel" and "xadd" are exclusive operations, that set "result" to "0"  * if the add or del was successful, or "-1" if not successful.  * (e.g. attempting to add a cpu to a cpuset that's already there, or  * deleting a cpu that's not in the cpuset)  */
define|#
directive|define
name|CPUSET_ATOMIC_DEL
parameter_list|(
name|set
parameter_list|,
name|cpu
parameter_list|)
value|BT_ATOMIC_CLEAR((set).cpub, (cpu))
define|#
directive|define
name|CPUSET_ATOMIC_ADD
parameter_list|(
name|set
parameter_list|,
name|cpu
parameter_list|)
value|BT_ATOMIC_SET((set).cpub, (cpu))
define|#
directive|define
name|CPUSET_ATOMIC_XADD
parameter_list|(
name|set
parameter_list|,
name|cpu
parameter_list|,
name|result
parameter_list|)
define|\
value|BT_ATOMIC_SET_EXCL((set).cpub, cpu, result)
define|#
directive|define
name|CPUSET_ATOMIC_XDEL
parameter_list|(
name|set
parameter_list|,
name|cpu
parameter_list|,
name|result
parameter_list|)
define|\
value|BT_ATOMIC_CLEAR_EXCL((set).cpub, cpu, result)
define|#
directive|define
name|CPUSET_OR
parameter_list|(
name|set1
parameter_list|,
name|set2
parameter_list|)
value|{		\ 	int _i;						\ 	for (_i = 0; _i< CPUSET_WORDS; _i++)		\ 		(set1).cpub[_i] |= (set2).cpub[_i];	\ }
define|#
directive|define
name|CPUSET_XOR
parameter_list|(
name|set1
parameter_list|,
name|set2
parameter_list|)
value|{		\ 	int _i;						\ 	for (_i = 0; _i< CPUSET_WORDS; _i++)		\ 		(set1).cpub[_i] ^= (set2).cpub[_i];	\ }
define|#
directive|define
name|CPUSET_AND
parameter_list|(
name|set1
parameter_list|,
name|set2
parameter_list|)
value|{		\ 	int _i;						\ 	for (_i = 0; _i< CPUSET_WORDS; _i++)		\ 		(set1).cpub[_i]&= (set2).cpub[_i];	\ }
define|#
directive|define
name|CPUSET_ZERO
parameter_list|(
name|set
parameter_list|)
value|{		\ 	int _i;						\ 	for (_i = 0; _i< CPUSET_WORDS; _i++)		\ 		(set).cpub[_i] = 0;			\ }
elif|#
directive|elif
name|CPUSET_WORDS
operator|==
literal|1
typedef|typedef
name|ulong_t
name|cpuset_t
typedef|;
comment|/* a set of CPUs */
define|#
directive|define
name|CPUSET
parameter_list|(
name|cpu
parameter_list|)
value|(1UL<< (cpu))
define|#
directive|define
name|CPUSET_ALL
parameter_list|(
name|set
parameter_list|)
value|((void)((set) = ~0UL))
define|#
directive|define
name|CPUSET_ALL_BUT
parameter_list|(
name|set
parameter_list|,
name|cpu
parameter_list|)
value|((void)((set) = ~CPUSET(cpu)))
define|#
directive|define
name|CPUSET_ONLY
parameter_list|(
name|set
parameter_list|,
name|cpu
parameter_list|)
value|((void)((set) = CPUSET(cpu)))
define|#
directive|define
name|CPU_IN_SET
parameter_list|(
name|set
parameter_list|,
name|cpu
parameter_list|)
value|((set)& CPUSET(cpu))
define|#
directive|define
name|CPUSET_ADD
parameter_list|(
name|set
parameter_list|,
name|cpu
parameter_list|)
value|((void)((set) |= CPUSET(cpu)))
define|#
directive|define
name|CPUSET_DEL
parameter_list|(
name|set
parameter_list|,
name|cpu
parameter_list|)
value|((void)((set)&= ~CPUSET(cpu)))
define|#
directive|define
name|CPUSET_ISNULL
parameter_list|(
name|set
parameter_list|)
value|((set) == 0)
define|#
directive|define
name|CPUSET_ISEQUAL
parameter_list|(
name|set1
parameter_list|,
name|set2
parameter_list|)
value|((set1) == (set2))
define|#
directive|define
name|CPUSET_OR
parameter_list|(
name|set1
parameter_list|,
name|set2
parameter_list|)
value|((void)((set1) |= (set2)))
define|#
directive|define
name|CPUSET_XOR
parameter_list|(
name|set1
parameter_list|,
name|set2
parameter_list|)
value|((void)((set1) ^= (set2)))
define|#
directive|define
name|CPUSET_AND
parameter_list|(
name|set1
parameter_list|,
name|set2
parameter_list|)
value|((void)((set1)&= (set2)))
define|#
directive|define
name|CPUSET_ZERO
parameter_list|(
name|set
parameter_list|)
value|((void)((set) = 0))
define|#
directive|define
name|CPUSET_FIND
parameter_list|(
name|set
parameter_list|,
name|cpu
parameter_list|)
value|{		\ 	cpu = (uint_t)(lowbit(set) - 1);				\ }
define|#
directive|define
name|CPUSET_BOUNDS
parameter_list|(
name|set
parameter_list|,
name|smallest
parameter_list|,
name|largest
parameter_list|)
value|{	\ 	smallest = (uint_t)(lowbit(set) - 1);		\ 	largest = (uint_t)(highbit(set) - 1);		\ }
define|#
directive|define
name|CPUSET_ATOMIC_DEL
parameter_list|(
name|set
parameter_list|,
name|cpu
parameter_list|)
value|atomic_and_ulong(&(set), ~CPUSET(cpu))
define|#
directive|define
name|CPUSET_ATOMIC_ADD
parameter_list|(
name|set
parameter_list|,
name|cpu
parameter_list|)
value|atomic_or_ulong(&(set), CPUSET(cpu))
define|#
directive|define
name|CPUSET_ATOMIC_XADD
parameter_list|(
name|set
parameter_list|,
name|cpu
parameter_list|,
name|result
parameter_list|)
define|\
value|{ result = atomic_set_long_excl(&(set), (cpu)); }
define|#
directive|define
name|CPUSET_ATOMIC_XDEL
parameter_list|(
name|set
parameter_list|,
name|cpu
parameter_list|,
name|result
parameter_list|)
define|\
value|{ result = atomic_clear_long_excl(&(set), (cpu)); }
else|#
directive|else
comment|/* CPUSET_WORDS<= 0 */
error|#
directive|error
error|NCPU is undefined or invalid
endif|#
directive|endif
comment|/* CPUSET_WORDS	*/
specifier|extern
name|cpuset_t
name|cpu_seqid_inuse
decl_stmt|;
endif|#
directive|endif
comment|/* (_KERNEL || _KMEMUSER)&& _MACHDEP */
define|#
directive|define
name|CPU_CPR_OFFLINE
value|0x0
define|#
directive|define
name|CPU_CPR_ONLINE
value|0x1
define|#
directive|define
name|CPU_CPR_IS_OFFLINE
parameter_list|(
name|cpu
parameter_list|)
value|(((cpu)->cpu_cpr_flags& CPU_CPR_ONLINE) == 0)
define|#
directive|define
name|CPU_CPR_IS_ONLINE
parameter_list|(
name|cpu
parameter_list|)
value|((cpu)->cpu_cpr_flags& CPU_CPR_ONLINE)
define|#
directive|define
name|CPU_SET_CPR_FLAGS
parameter_list|(
name|cpu
parameter_list|,
name|flag
parameter_list|)
value|((cpu)->cpu_cpr_flags |= flag)
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|_KMEMUSER
argument_list|)
specifier|extern
name|struct
name|cpu
modifier|*
name|cpu
index|[]
decl_stmt|;
comment|/* indexed by CPU number */
specifier|extern
name|struct
name|cpu
modifier|*
modifier|*
name|cpu_seq
decl_stmt|;
comment|/* indexed by sequential CPU id */
specifier|extern
name|cpu_t
modifier|*
name|cpu_list
decl_stmt|;
comment|/* list of CPUs */
specifier|extern
name|cpu_t
modifier|*
name|cpu_active
decl_stmt|;
comment|/* list of active CPUs */
specifier|extern
name|int
name|ncpus
decl_stmt|;
comment|/* number of CPUs present */
specifier|extern
name|int
name|ncpus_online
decl_stmt|;
comment|/* number of CPUs not quiesced */
specifier|extern
name|int
name|max_ncpus
decl_stmt|;
comment|/* max present before ncpus is known */
specifier|extern
name|int
name|boot_max_ncpus
decl_stmt|;
comment|/* like max_ncpus but for real */
specifier|extern
name|int
name|boot_ncpus
decl_stmt|;
comment|/* # cpus present @ boot */
specifier|extern
name|processorid_t
name|max_cpuid
decl_stmt|;
comment|/* maximum CPU number */
specifier|extern
name|struct
name|cpu
modifier|*
name|cpu_inmotion
decl_stmt|;
comment|/* offline or partition move target */
specifier|extern
name|cpu_t
modifier|*
name|clock_cpu_list
decl_stmt|;
specifier|extern
name|processorid_t
name|max_cpu_seqid_ever
decl_stmt|;
comment|/* maximum seqid ever given */
if|#
directive|if
name|defined
argument_list|(
name|__i386
argument_list|)
operator|||
name|defined
argument_list|(
name|__amd64
argument_list|)
specifier|extern
name|struct
name|cpu
modifier|*
name|curcpup
parameter_list|(
name|void
parameter_list|)
function_decl|;
define|#
directive|define
name|CPU
value|(curcpup())
comment|/* Pointer to current CPU */
else|#
directive|else
define|#
directive|define
name|CPU
value|(curthread->t_cpu)
comment|/* Pointer to current CPU */
endif|#
directive|endif
comment|/*  * CPU_CURRENT indicates to thread_affinity_set to use CPU->cpu_id  * as the target and to grab cpu_lock instead of requiring the caller  * to grab it.  */
define|#
directive|define
name|CPU_CURRENT
value|-3
comment|/*  * Per-CPU statistics  *  * cpu_stats_t contains numerous system and VM-related statistics, in the form  * of gauges or monotonically-increasing event occurrence counts.  */
define|#
directive|define
name|CPU_STATS_ENTER_K
parameter_list|()
value|kpreempt_disable()
define|#
directive|define
name|CPU_STATS_EXIT_K
parameter_list|()
value|kpreempt_enable()
define|#
directive|define
name|CPU_STATS_ADD_K
parameter_list|(
name|class
parameter_list|,
name|stat
parameter_list|,
name|amount
parameter_list|)
define|\
value|{	kpreempt_disable();
comment|/* keep from switching CPUs */
value|\ 		CPU_STATS_ADDQ(CPU, class, stat, amount); \ 		kpreempt_enable(); \ 	}
define|#
directive|define
name|CPU_STATS_ADDQ
parameter_list|(
name|cp
parameter_list|,
name|class
parameter_list|,
name|stat
parameter_list|,
name|amount
parameter_list|)
value|{			\ 	extern void __dtrace_probe___cpu_##class##info_##stat(uint_t,	\ 	    uint64_t *, cpu_t *);					\ 	uint64_t *stataddr =&((cp)->cpu_stats.class.stat);		\ 	__dtrace_probe___cpu_##class##info_##stat((amount),		\ 	    stataddr, cp);						\ 	*(stataddr) += (amount);					\ }
define|#
directive|define
name|CPU_STATS
parameter_list|(
name|cp
parameter_list|,
name|stat
parameter_list|)
define|\
value|((cp)->cpu_stats.stat)
comment|/*  * Increment CPU generation value.  * This macro should be called whenever CPU goes on-line or off-line.  * Updates to cpu_generation should be protected by cpu_lock.  */
define|#
directive|define
name|CPU_NEW_GENERATION
parameter_list|(
name|cp
parameter_list|)
value|((cp)->cpu_generation++)
endif|#
directive|endif
comment|/* _KERNEL || _KMEMUSER */
comment|/*  * CPU support routines.  */
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
name|defined
argument_list|(
name|__STDC__
argument_list|)
comment|/* not for genassym.c */
struct_decl|struct
name|zone
struct_decl|;
name|void
name|cpu_list_init
parameter_list|(
name|cpu_t
modifier|*
parameter_list|)
function_decl|;
name|void
name|cpu_add_unit
parameter_list|(
name|cpu_t
modifier|*
parameter_list|)
function_decl|;
name|void
name|cpu_del_unit
parameter_list|(
name|int
name|cpuid
parameter_list|)
function_decl|;
name|void
name|cpu_add_active
parameter_list|(
name|cpu_t
modifier|*
parameter_list|)
function_decl|;
name|void
name|cpu_kstat_init
parameter_list|(
name|cpu_t
modifier|*
parameter_list|)
function_decl|;
name|void
name|cpu_visibility_add
parameter_list|(
name|cpu_t
modifier|*
parameter_list|,
name|struct
name|zone
modifier|*
parameter_list|)
function_decl|;
name|void
name|cpu_visibility_remove
parameter_list|(
name|cpu_t
modifier|*
parameter_list|,
name|struct
name|zone
modifier|*
parameter_list|)
function_decl|;
name|void
name|cpu_visibility_configure
parameter_list|(
name|cpu_t
modifier|*
parameter_list|,
name|struct
name|zone
modifier|*
parameter_list|)
function_decl|;
name|void
name|cpu_visibility_unconfigure
parameter_list|(
name|cpu_t
modifier|*
parameter_list|,
name|struct
name|zone
modifier|*
parameter_list|)
function_decl|;
name|void
name|cpu_visibility_online
parameter_list|(
name|cpu_t
modifier|*
parameter_list|,
name|struct
name|zone
modifier|*
parameter_list|)
function_decl|;
name|void
name|cpu_visibility_offline
parameter_list|(
name|cpu_t
modifier|*
parameter_list|,
name|struct
name|zone
modifier|*
parameter_list|)
function_decl|;
name|void
name|cpu_create_intrstat
parameter_list|(
name|cpu_t
modifier|*
parameter_list|)
function_decl|;
name|void
name|cpu_delete_intrstat
parameter_list|(
name|cpu_t
modifier|*
parameter_list|)
function_decl|;
name|int
name|cpu_kstat_intrstat_update
parameter_list|(
name|kstat_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
name|cpu_intr_swtch_enter
parameter_list|(
name|kthread_t
modifier|*
parameter_list|)
function_decl|;
name|void
name|cpu_intr_swtch_exit
parameter_list|(
name|kthread_t
modifier|*
parameter_list|)
function_decl|;
name|void
name|mbox_lock_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* initialize cross-call locks */
name|void
name|mbox_init
parameter_list|(
name|int
name|cpun
parameter_list|)
function_decl|;
comment|/* initialize cross-calls */
name|void
name|poke_cpu
parameter_list|(
name|int
name|cpun
parameter_list|)
function_decl|;
comment|/* interrupt another CPU (to preempt) */
comment|/*  * values for safe_list.  Pause state that CPUs are in.  */
define|#
directive|define
name|PAUSE_IDLE
value|0
comment|/* normal state */
define|#
directive|define
name|PAUSE_READY
value|1
comment|/* paused thread ready to spl */
define|#
directive|define
name|PAUSE_WAIT
value|2
comment|/* paused thread is spl-ed high */
define|#
directive|define
name|PAUSE_DIE
value|3
comment|/* tell pause thread to leave */
define|#
directive|define
name|PAUSE_DEAD
value|4
comment|/* pause thread has left */
name|void
name|mach_cpu_pause
parameter_list|(
specifier|volatile
name|char
modifier|*
parameter_list|)
function_decl|;
name|void
name|pause_cpus
parameter_list|(
name|cpu_t
modifier|*
name|off_cp
parameter_list|)
function_decl|;
name|void
name|start_cpus
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|int
name|cpus_paused
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
name|cpu_pause_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|cpu_t
modifier|*
name|cpu_get
parameter_list|(
name|processorid_t
name|cpun
parameter_list|)
function_decl|;
comment|/* get the CPU struct associated */
name|int
name|cpu_online
parameter_list|(
name|cpu_t
modifier|*
name|cp
parameter_list|)
function_decl|;
comment|/* take cpu online */
name|int
name|cpu_offline
parameter_list|(
name|cpu_t
modifier|*
name|cp
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
comment|/* take cpu offline */
name|int
name|cpu_spare
parameter_list|(
name|cpu_t
modifier|*
name|cp
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
comment|/* take cpu to spare */
name|int
name|cpu_faulted
parameter_list|(
name|cpu_t
modifier|*
name|cp
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
comment|/* take cpu to faulted */
name|int
name|cpu_poweron
parameter_list|(
name|cpu_t
modifier|*
name|cp
parameter_list|)
function_decl|;
comment|/* take powered-off cpu to offline */
name|int
name|cpu_poweroff
parameter_list|(
name|cpu_t
modifier|*
name|cp
parameter_list|)
function_decl|;
comment|/* take offline cpu to powered-off */
name|cpu_t
modifier|*
name|cpu_intr_next
parameter_list|(
name|cpu_t
modifier|*
name|cp
parameter_list|)
function_decl|;
comment|/* get next online CPU taking intrs */
name|int
name|cpu_intr_count
parameter_list|(
name|cpu_t
modifier|*
name|cp
parameter_list|)
function_decl|;
comment|/* count # of CPUs handling intrs */
name|int
name|cpu_intr_on
parameter_list|(
name|cpu_t
modifier|*
name|cp
parameter_list|)
function_decl|;
comment|/* CPU taking I/O interrupts? */
name|void
name|cpu_intr_enable
parameter_list|(
name|cpu_t
modifier|*
name|cp
parameter_list|)
function_decl|;
comment|/* enable I/O interrupts */
name|int
name|cpu_intr_disable
parameter_list|(
name|cpu_t
modifier|*
name|cp
parameter_list|)
function_decl|;
comment|/* disable I/O interrupts */
name|void
name|cpu_intr_alloc
parameter_list|(
name|cpu_t
modifier|*
name|cp
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
comment|/* allocate interrupt threads */
comment|/*  * Routines for checking CPU states.  */
name|int
name|cpu_is_online
parameter_list|(
name|cpu_t
modifier|*
parameter_list|)
function_decl|;
comment|/* check if CPU is online */
name|int
name|cpu_is_nointr
parameter_list|(
name|cpu_t
modifier|*
parameter_list|)
function_decl|;
comment|/* check if CPU can service intrs */
name|int
name|cpu_is_active
parameter_list|(
name|cpu_t
modifier|*
parameter_list|)
function_decl|;
comment|/* check if CPU can run threads */
name|int
name|cpu_is_offline
parameter_list|(
name|cpu_t
modifier|*
parameter_list|)
function_decl|;
comment|/* check if CPU is offline */
name|int
name|cpu_is_poweredoff
parameter_list|(
name|cpu_t
modifier|*
parameter_list|)
function_decl|;
comment|/* check if CPU is powered off */
name|int
name|cpu_flagged_online
parameter_list|(
name|cpu_flag_t
parameter_list|)
function_decl|;
comment|/* flags show CPU is online */
name|int
name|cpu_flagged_nointr
parameter_list|(
name|cpu_flag_t
parameter_list|)
function_decl|;
comment|/* flags show CPU not handling intrs */
name|int
name|cpu_flagged_active
parameter_list|(
name|cpu_flag_t
parameter_list|)
function_decl|;
comment|/* flags show CPU scheduling threads */
name|int
name|cpu_flagged_offline
parameter_list|(
name|cpu_flag_t
parameter_list|)
function_decl|;
comment|/* flags show CPU is offline */
name|int
name|cpu_flagged_poweredoff
parameter_list|(
name|cpu_flag_t
parameter_list|)
function_decl|;
comment|/* flags show CPU is powered off */
comment|/*  * The processor_info(2) state of a CPU is a simplified representation suitable  * for use by an application program.  Kernel subsystems should utilize the  * internal per-CPU state as given by the cpu_flags member of the cpu structure,  * as this information may include platform- or architecture-specific state  * critical to a subsystem's disposition of a particular CPU.  */
name|void
name|cpu_set_state
parameter_list|(
name|cpu_t
modifier|*
parameter_list|)
function_decl|;
comment|/* record/timestamp current state */
name|int
name|cpu_get_state
parameter_list|(
name|cpu_t
modifier|*
parameter_list|)
function_decl|;
comment|/* get current cpu state */
specifier|const
name|char
modifier|*
name|cpu_get_state_str
parameter_list|(
name|cpu_t
modifier|*
parameter_list|)
function_decl|;
comment|/* get current cpu state as string */
name|void
name|cpu_set_curr_clock
parameter_list|(
name|uint64_t
parameter_list|)
function_decl|;
comment|/* indicate the current CPU's freq */
name|void
name|cpu_set_supp_freqs
parameter_list|(
name|cpu_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
comment|/* set the CPU supported */
comment|/* frequencies */
name|int
name|cpu_configure
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|int
name|cpu_unconfigure
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|void
name|cpu_destroy_bound_threads
parameter_list|(
name|cpu_t
modifier|*
name|cp
parameter_list|)
function_decl|;
specifier|extern
name|int
name|cpu_bind_thread
parameter_list|(
name|kthread_t
modifier|*
name|tp
parameter_list|,
name|processorid_t
name|bind
parameter_list|,
name|processorid_t
modifier|*
name|obind
parameter_list|,
name|int
modifier|*
name|error
parameter_list|)
function_decl|;
specifier|extern
name|int
name|cpu_unbind
parameter_list|(
name|processorid_t
name|cpu_id
parameter_list|,
name|boolean_t
name|force
parameter_list|)
function_decl|;
specifier|extern
name|void
name|thread_affinity_set
parameter_list|(
name|kthread_t
modifier|*
name|t
parameter_list|,
name|int
name|cpu_id
parameter_list|)
function_decl|;
specifier|extern
name|void
name|thread_affinity_clear
parameter_list|(
name|kthread_t
modifier|*
name|t
parameter_list|)
function_decl|;
specifier|extern
name|void
name|affinity_set
parameter_list|(
name|int
name|cpu_id
parameter_list|)
function_decl|;
specifier|extern
name|void
name|affinity_clear
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|void
name|init_cpu_mstate
parameter_list|(
name|struct
name|cpu
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|void
name|term_cpu_mstate
parameter_list|(
name|struct
name|cpu
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|new_cpu_mstate
parameter_list|(
name|int
parameter_list|,
name|hrtime_t
parameter_list|)
function_decl|;
specifier|extern
name|void
name|get_cpu_mstate
parameter_list|(
name|struct
name|cpu
modifier|*
parameter_list|,
name|hrtime_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|thread_nomigrate
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|void
name|thread_allowmigrate
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|void
name|weakbinding_stop
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|void
name|weakbinding_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/*  * The following routines affect the CPUs participation in interrupt processing,  * if that is applicable on the architecture.  This only affects interrupts  * which aren't directed at the processor (not cross calls).  *  * cpu_disable_intr returns non-zero if interrupts were previously enabled.  */
name|int
name|cpu_disable_intr
parameter_list|(
name|struct
name|cpu
modifier|*
name|cp
parameter_list|)
function_decl|;
comment|/* stop issuing interrupts to cpu */
name|void
name|cpu_enable_intr
parameter_list|(
name|struct
name|cpu
modifier|*
name|cp
parameter_list|)
function_decl|;
comment|/* start issuing interrupts to cpu */
comment|/*  * The mutex cpu_lock protects cpu_flags for all CPUs, as well as the ncpus  * and ncpus_online counts.  */
specifier|extern
name|kmutex_t
name|cpu_lock
decl_stmt|;
comment|/* lock protecting CPU data */
comment|/*  * CPU state change events  *  * Various subsystems need to know when CPUs change their state. They get this  * information by registering  CPU state change callbacks using  * register_cpu_setup_func(). Whenever any CPU changes its state, the callback  * function is called. The callback function is passed three arguments:  *  *   Event, described by cpu_setup_t  *   CPU ID  *   Transparent pointer passed when registering the callback  *  * The callback function is called with cpu_lock held. The return value from the  * callback function is usually ignored, except for CPU_CONFIG and CPU_UNCONFIG  * events. For these two events, non-zero return value indicates a failure and  * prevents successful completion of the operation.  *  * New events may be added in the future. Callback functions should ignore any  * events that they do not understand.  *  * The following events provide notification callbacks:  *  *  CPU_INIT	A new CPU is started and added to the list of active CPUs  *		  This event is only used during boot  *  *  CPU_CONFIG	A newly inserted CPU is prepared for starting running code  *		  This event is called by DR code  *  *  CPU_UNCONFIG CPU has been powered off and needs cleanup  *		  This event is called by DR code  *  *  CPU_ON	CPU is enabled but does not run anything yet  *  *  CPU_INTR_ON	CPU is enabled and has interrupts enabled  *  *  CPU_OFF	CPU is going offline but can still run threads  *  *  CPU_CPUPART_OUT	CPU is going to move out of its partition  *  *  CPU_CPUPART_IN	CPU is going to move to a new partition  *  *  CPU_SETUP	CPU is set up during boot and can run threads  */
typedef|typedef
enum|enum
block|{
name|CPU_INIT
block|,
name|CPU_CONFIG
block|,
name|CPU_UNCONFIG
block|,
name|CPU_ON
block|,
name|CPU_OFF
block|,
name|CPU_CPUPART_IN
block|,
name|CPU_CPUPART_OUT
block|,
name|CPU_SETUP
block|,
name|CPU_INTR_ON
block|}
name|cpu_setup_t
typedef|;
typedef|typedef
name|int
name|cpu_setup_func_t
parameter_list|(
name|cpu_setup_t
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/*  * Routines used to register interest in cpu's being added to or removed  * from the system.  */
specifier|extern
name|void
name|register_cpu_setup_func
parameter_list|(
name|cpu_setup_func_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|unregister_cpu_setup_func
parameter_list|(
name|cpu_setup_func_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|cpu_state_change_notify
parameter_list|(
name|int
parameter_list|,
name|cpu_setup_t
parameter_list|)
function_decl|;
comment|/*  * Call specified function on the given CPU  */
typedef|typedef
name|void
function_decl|(
modifier|*
name|cpu_call_func_t
function_decl|)
parameter_list|(
name|uintptr_t
parameter_list|,
name|uintptr_t
parameter_list|)
function_decl|;
specifier|extern
name|void
name|cpu_call
parameter_list|(
name|cpu_t
modifier|*
parameter_list|,
name|cpu_call_func_t
parameter_list|,
name|uintptr_t
parameter_list|,
name|uintptr_t
parameter_list|)
function_decl|;
comment|/*  * Create various strings that describe the given CPU for the  * processor_info system call and configuration-related kstats.  */
define|#
directive|define
name|CPU_IDSTRLEN
value|100
specifier|extern
name|void
name|init_cpu_info
parameter_list|(
name|struct
name|cpu
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|populate_idstr
parameter_list|(
name|struct
name|cpu
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|cpu_vm_data_init
parameter_list|(
name|struct
name|cpu
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|cpu_vm_data_destroy
parameter_list|(
name|struct
name|cpu
modifier|*
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* _KERNEL */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_CPUVAR_H */
end_comment

end_unit

