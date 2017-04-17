begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Wind River Systems, Inc.  * All rights reserved.  * Written by: John Baldwin<jhb@FreeBSD.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_PCPU_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_PCPU_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|LOCORE
end_ifdef

begin_error
error|#
directive|error
literal|"no assembler-serviceable parts inside"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/_cpuset.h>
end_include

begin_include
include|#
directive|include
file|<sys/_lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/_mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/_sx.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/_rmlock.h>
end_include

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_include
include|#
directive|include
file|<machine/pcpu.h>
end_include

begin_define
define|#
directive|define
name|DPCPU_SETNAME
value|"set_pcpu"
end_define

begin_define
define|#
directive|define
name|DPCPU_SYMPREFIX
value|"pcpu_entry_"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Define a set for pcpu data.  */
end_comment

begin_decl_stmt
specifier|extern
name|uintptr_t
modifier|*
name|__start_set_pcpu
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|__GLOBL
argument_list|(
name|__start_set_pcpu
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|uintptr_t
modifier|*
name|__stop_set_pcpu
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|__GLOBL
argument_list|(
name|__stop_set_pcpu
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Array of dynamic pcpu base offsets.  Indexed by id.  */
end_comment

begin_decl_stmt
specifier|extern
name|uintptr_t
name|dpcpu_off
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Convenience defines.  */
end_comment

begin_define
define|#
directive|define
name|DPCPU_START
value|((uintptr_t)&__start_set_pcpu)
end_define

begin_define
define|#
directive|define
name|DPCPU_STOP
value|((uintptr_t)&__stop_set_pcpu)
end_define

begin_define
define|#
directive|define
name|DPCPU_BYTES
value|(DPCPU_STOP - DPCPU_START)
end_define

begin_define
define|#
directive|define
name|DPCPU_MODMIN
value|2048
end_define

begin_define
define|#
directive|define
name|DPCPU_SIZE
value|roundup2(DPCPU_BYTES, PAGE_SIZE)
end_define

begin_define
define|#
directive|define
name|DPCPU_MODSIZE
value|(DPCPU_SIZE - (DPCPU_BYTES - DPCPU_MODMIN))
end_define

begin_comment
comment|/*  * Declaration and definition.  */
end_comment

begin_define
define|#
directive|define
name|DPCPU_NAME
parameter_list|(
name|n
parameter_list|)
value|pcpu_entry_##n
end_define

begin_define
define|#
directive|define
name|DPCPU_DECLARE
parameter_list|(
name|t
parameter_list|,
name|n
parameter_list|)
value|extern t DPCPU_NAME(n)
end_define

begin_define
define|#
directive|define
name|DPCPU_DEFINE
parameter_list|(
name|t
parameter_list|,
name|n
parameter_list|)
value|t DPCPU_NAME(n) __section(DPCPU_SETNAME) __used
end_define

begin_comment
comment|/*  * Accessors with a given base.  */
end_comment

begin_define
define|#
directive|define
name|_DPCPU_PTR
parameter_list|(
name|b
parameter_list|,
name|n
parameter_list|)
define|\
value|(__typeof(DPCPU_NAME(n))*)((b) + (uintptr_t)&DPCPU_NAME(n))
end_define

begin_define
define|#
directive|define
name|_DPCPU_GET
parameter_list|(
name|b
parameter_list|,
name|n
parameter_list|)
value|(*_DPCPU_PTR(b, n))
end_define

begin_define
define|#
directive|define
name|_DPCPU_SET
parameter_list|(
name|b
parameter_list|,
name|n
parameter_list|,
name|v
parameter_list|)
value|(*_DPCPU_PTR(b, n) = v)
end_define

begin_comment
comment|/*  * Accessors for the current cpu.  */
end_comment

begin_define
define|#
directive|define
name|DPCPU_PTR
parameter_list|(
name|n
parameter_list|)
value|_DPCPU_PTR(PCPU_GET(dynamic), n)
end_define

begin_define
define|#
directive|define
name|DPCPU_GET
parameter_list|(
name|n
parameter_list|)
value|(*DPCPU_PTR(n))
end_define

begin_define
define|#
directive|define
name|DPCPU_SET
parameter_list|(
name|n
parameter_list|,
name|v
parameter_list|)
value|(*DPCPU_PTR(n) = v)
end_define

begin_comment
comment|/*  * Accessors for remote cpus.  */
end_comment

begin_define
define|#
directive|define
name|DPCPU_ID_PTR
parameter_list|(
name|i
parameter_list|,
name|n
parameter_list|)
value|_DPCPU_PTR(dpcpu_off[(i)], n)
end_define

begin_define
define|#
directive|define
name|DPCPU_ID_GET
parameter_list|(
name|i
parameter_list|,
name|n
parameter_list|)
value|(*DPCPU_ID_PTR(i, n))
end_define

begin_define
define|#
directive|define
name|DPCPU_ID_SET
parameter_list|(
name|i
parameter_list|,
name|n
parameter_list|,
name|v
parameter_list|)
value|(*DPCPU_ID_PTR(i, n) = v)
end_define

begin_comment
comment|/*  * Utility macros.  */
end_comment

begin_define
define|#
directive|define
name|DPCPU_SUM
parameter_list|(
name|n
parameter_list|)
value|__extension__					\ ({									\ 	u_int _i;							\ 	__typeof(*DPCPU_PTR(n)) sum;					\ 									\ 	sum = 0;							\ 	CPU_FOREACH(_i) {						\ 		sum += *DPCPU_ID_PTR(_i, n);				\ 	}								\ 	sum;								\ })
end_define

begin_define
define|#
directive|define
name|DPCPU_VARSUM
parameter_list|(
name|n
parameter_list|,
name|var
parameter_list|)
value|__extension__				\ ({									\ 	u_int _i;							\ 	__typeof((DPCPU_PTR(n))->var) sum;				\ 									\ 	sum = 0;							\ 	CPU_FOREACH(_i) {						\ 		sum += (DPCPU_ID_PTR(_i, n))->var;			\ 	}								\ 	sum;								\ })
end_define

begin_define
define|#
directive|define
name|DPCPU_ZERO
parameter_list|(
name|n
parameter_list|)
value|do {						\ 	u_int _i;							\ 									\ 	CPU_FOREACH(_i) {						\ 		bzero(DPCPU_ID_PTR(_i, n), sizeof(*DPCPU_PTR(n)));	\ 	}								\ } while(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/*  * This structure maps out the global data that needs to be kept on a  * per-cpu basis.  The members are accessed via the PCPU_GET/SET/PTR  * macros defined in<machine/pcpu.h>.  Machine dependent fields are  * defined in the PCPU_MD_FIELDS macro defined in<machine/pcpu.h>.  */
end_comment

begin_struct
struct|struct
name|pcpu
block|{
name|struct
name|thread
modifier|*
name|pc_curthread
decl_stmt|;
comment|/* Current thread */
name|struct
name|thread
modifier|*
name|pc_idlethread
decl_stmt|;
comment|/* Idle thread */
name|struct
name|thread
modifier|*
name|pc_fpcurthread
decl_stmt|;
comment|/* Fp state owner */
name|struct
name|thread
modifier|*
name|pc_deadthread
decl_stmt|;
comment|/* Zombie thread or NULL */
name|struct
name|pcb
modifier|*
name|pc_curpcb
decl_stmt|;
comment|/* Current pcb */
name|uint64_t
name|pc_switchtime
decl_stmt|;
comment|/* cpu_ticks() at last csw */
name|int
name|pc_switchticks
decl_stmt|;
comment|/* `ticks' at last csw */
name|u_int
name|pc_cpuid
decl_stmt|;
comment|/* This cpu number */
name|STAILQ_ENTRY
argument_list|(
argument|pcpu
argument_list|)
name|pc_allcpu
expr_stmt|;
name|struct
name|lock_list_entry
modifier|*
name|pc_spinlocks
decl_stmt|;
name|long
name|pc_cp_time
index|[
name|CPUSTATES
index|]
decl_stmt|;
comment|/* statclock ticks */
name|struct
name|device
modifier|*
name|pc_device
decl_stmt|;
name|void
modifier|*
name|pc_netisr
decl_stmt|;
comment|/* netisr SWI cookie */
name|int
name|pc_unused1
decl_stmt|;
comment|/* unused field */
name|int
name|pc_domain
decl_stmt|;
comment|/* Memory domain. */
name|struct
name|rm_queue
name|pc_rm_queue
decl_stmt|;
comment|/* rmlock list of trackers */
name|uintptr_t
name|pc_dynamic
decl_stmt|;
comment|/* Dynamic per-cpu data area */
name|uint64_t
name|pc_early_dummy_counter
decl_stmt|;
comment|/* Startup time counter(9) */
comment|/* 	 * Keep MD fields last, so that CPU-specific variations on a 	 * single architecture don't result in offset variations of 	 * the machine-independent fields of the pcpu.  Even though 	 * the pcpu structure is private to the kernel, some ports 	 * (e.g., lsof, part of gtop) define _KERNEL and include this 	 * header.  While strictly speaking this is wrong, there's no 	 * reason not to keep the offsets of the MI fields constant 	 * if only to make kernel debugging easier. 	 */
name|PCPU_MD_FIELDS
expr_stmt|;
block|}
name|__aligned
argument_list|(
name|CACHE_LINE_SIZE
argument_list|)
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|CTASSERT
end_ifdef

begin_comment
comment|/*  * To minimize memory waste in per-cpu UMA zones, size of struct pcpu  * should be denominator of PAGE_SIZE.  */
end_comment

begin_expr_stmt
name|CTASSERT
argument_list|(
operator|(
name|PAGE_SIZE
operator|/
sizeof|sizeof
argument_list|(
expr|struct
name|pcpu
argument_list|)
operator|)
operator|*
sizeof|sizeof
argument_list|(
expr|struct
name|pcpu
argument_list|)
operator|==
name|PAGE_SIZE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_expr_stmt
name|STAILQ_HEAD
argument_list|(
name|cpuhead
argument_list|,
name|pcpu
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|cpuhead
name|cpuhead
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pcpu
modifier|*
name|cpuid_to_pcpu
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|curcpu
value|PCPU_GET(cpuid)
end_define

begin_define
define|#
directive|define
name|curproc
value|(curthread->td_proc)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|curthread
end_ifndef

begin_define
define|#
directive|define
name|curthread
value|PCPU_GET(curthread)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|curvidata
value|PCPU_GET(vidata)
end_define

begin_comment
comment|/* Accessor to elements allocated via UMA_ZONE_PCPU zone. */
end_comment

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|zpcpu_get
parameter_list|(
name|void
modifier|*
name|base
parameter_list|)
block|{
return|return
operator|(
operator|(
name|char
operator|*
operator|)
operator|(
name|base
operator|)
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|pcpu
argument_list|)
operator|*
name|curcpu
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|zpcpu_get_cpu
parameter_list|(
name|void
modifier|*
name|base
parameter_list|,
name|int
name|cpu
parameter_list|)
block|{
return|return
operator|(
operator|(
name|char
operator|*
operator|)
operator|(
name|base
operator|)
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|pcpu
argument_list|)
operator|*
name|cpu
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Machine dependent callouts.  cpu_pcpu_init() is responsible for  * initializing machine dependent fields of struct pcpu, and  * db_show_mdpcpu() is responsible for handling machine dependent  * fields for the DDB 'show pcpu' command.  */
end_comment

begin_function_decl
name|void
name|cpu_pcpu_init
parameter_list|(
name|struct
name|pcpu
modifier|*
name|pcpu
parameter_list|,
name|int
name|cpuid
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|db_show_mdpcpu
parameter_list|(
name|struct
name|pcpu
modifier|*
name|pcpu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|dpcpu_alloc
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dpcpu_copy
parameter_list|(
name|void
modifier|*
name|s
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dpcpu_free
parameter_list|(
name|void
modifier|*
name|s
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dpcpu_init
parameter_list|(
name|void
modifier|*
name|dpcpu
parameter_list|,
name|int
name|cpuid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pcpu_destroy
parameter_list|(
name|struct
name|pcpu
modifier|*
name|pcpu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|pcpu
modifier|*
name|pcpu_find
parameter_list|(
name|u_int
name|cpuid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pcpu_init
parameter_list|(
name|struct
name|pcpu
modifier|*
name|pcpu
parameter_list|,
name|int
name|cpuid
parameter_list|,
name|size_t
name|size
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
comment|/* !_SYS_PCPU_H_ */
end_comment

end_unit

