begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Copyright 2007 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_COMPAT_OPENSOLARIS_SYS_CPUVAR_H
end_ifndef

begin_define
define|#
directive|define
name|_COMPAT_OPENSOLARIS_SYS_CPUVAR_H
end_define

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/cpuvar_defs.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|cyc_cpu
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|cpuid
decl_stmt|;
name|uint32_t
name|cpu_flags
decl_stmt|;
name|uint_t
name|cpu_intr_actv
decl_stmt|;
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
block|}
name|solaris_cpu_t
typedef|;
end_typedef

begin_comment
comment|/* Some code may choose to redefine this if pcpu_t would be more useful. */
end_comment

begin_define
define|#
directive|define
name|cpu_t
value|solaris_cpu_t
end_define

begin_define
define|#
directive|define
name|cpu_id
value|cpuid
end_define

begin_decl_stmt
specifier|extern
name|solaris_cpu_t
name|solaris_cpu
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CPU_CACHE_COHERENCE_SIZE
value|64
end_define

begin_comment
comment|/*  * The cpu_core structure consists of per-CPU state available in any context.  * On some architectures, this may mean that the page(s) containing the  * NCPU-sized array of cpu_core structures must be locked in the TLB -- it  * is up to the platform to assure that this is performed properly.  Note that  * the structure is sized to avoid false sharing.  */
end_comment

begin_define
define|#
directive|define
name|CPUC_SIZE
value|(sizeof (uint16_t) + sizeof (uintptr_t) + \ 				sizeof (kmutex_t))
end_define

begin_define
define|#
directive|define
name|CPUC_SIZE1
value|roundup(CPUC_SIZE, CPU_CACHE_COHERENCE_SIZE)
end_define

begin_define
define|#
directive|define
name|CPUC_PADSIZE
value|CPUC_SIZE1 - CPUC_SIZE
end_define

begin_typedef
typedef|typedef
struct|struct
name|cpu_core
block|{
name|uint16_t
name|cpuc_dtrace_flags
decl_stmt|;
comment|/* DTrace flags */
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
end_typedef

begin_decl_stmt
specifier|extern
name|cpu_core_t
name|cpu_core
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|kmutex_t
name|cpu_lock
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/*  * Flags in the CPU structure.  *  * These are protected by cpu_lock (except during creation).  *  * Offlined-CPUs have three stages of being offline:  *  * CPU_ENABLE indicates that the CPU is participating in I/O interrupts  * that can be directed at a number of different CPUs.  If CPU_ENABLE  * is off, the CPU will not be given interrupts that can be sent elsewhere,  * but will still get interrupts from devices associated with that CPU only,  * and from other CPUs.  *  * CPU_OFFLINE indicates that the dispatcher should not allow any threads  * other than interrupt threads to run on that CPU.  A CPU will not have  * CPU_OFFLINE set if there are any bound threads (besides interrupts).  *  * CPU_QUIESCED is set if p_offline was able to completely turn idle the  * CPU and it will not have to run interrupt threads.  In this case it'll  * stay in the idle loop until CPU_QUIESCED is turned off.  *  * CPU_FROZEN is used only by CPR to mark CPUs that have been successfully  * suspended (in the suspend path), or have yet to be resumed (in the resume  * case).  *  * On some platforms CPUs can be individually powered off.  * The following flags are set for powered off CPUs: CPU_QUIESCED,  * CPU_OFFLINE, and CPU_POWEROFF.  The following flags are cleared:  * CPU_RUNNING, CPU_READY, CPU_EXISTS, and CPU_ENABLE.  */
end_comment

begin_define
define|#
directive|define
name|CPU_RUNNING
value|0x001
end_define

begin_comment
comment|/* CPU running */
end_comment

begin_define
define|#
directive|define
name|CPU_READY
value|0x002
end_define

begin_comment
comment|/* CPU ready for cross-calls */
end_comment

begin_define
define|#
directive|define
name|CPU_QUIESCED
value|0x004
end_define

begin_comment
comment|/* CPU will stay in idle */
end_comment

begin_define
define|#
directive|define
name|CPU_EXISTS
value|0x008
end_define

begin_comment
comment|/* CPU is configured */
end_comment

begin_define
define|#
directive|define
name|CPU_ENABLE
value|0x010
end_define

begin_comment
comment|/* CPU enabled for interrupts */
end_comment

begin_define
define|#
directive|define
name|CPU_OFFLINE
value|0x020
end_define

begin_comment
comment|/* CPU offline via p_online */
end_comment

begin_define
define|#
directive|define
name|CPU_POWEROFF
value|0x040
end_define

begin_comment
comment|/* CPU is powered off */
end_comment

begin_define
define|#
directive|define
name|CPU_FROZEN
value|0x080
end_define

begin_comment
comment|/* CPU is frozen via CPR suspend */
end_comment

begin_define
define|#
directive|define
name|CPU_SPARE
value|0x100
end_define

begin_comment
comment|/* CPU offline available for use */
end_comment

begin_define
define|#
directive|define
name|CPU_FAULTED
value|0x200
end_define

begin_comment
comment|/* CPU offline diagnosed faulty */
end_comment

begin_typedef
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
block|}
name|cpu_setup_t
typedef|;
end_typedef

begin_typedef
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
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _COMPAT_OPENSOLARIS_SYS_CPUVAR_H */
end_comment

end_unit

