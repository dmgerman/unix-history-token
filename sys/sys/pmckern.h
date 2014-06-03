begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2007, Joseph Koshy  * Copyright (c) 2007 The FreeBSD Foundation  * All rights reserved.  *  * Portions of this software were developed by A. Joseph Koshy under  * sponsorship from the FreeBSD Foundation and Google, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * PMC interface used by the base kernel.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_PMCKERN_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_PMCKERN_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
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
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/sx.h>
end_include

begin_include
include|#
directive|include
file|<sys/pmc.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_define
define|#
directive|define
name|PMC_FN_PROCESS_EXEC
value|1
end_define

begin_define
define|#
directive|define
name|PMC_FN_CSW_IN
value|2
end_define

begin_define
define|#
directive|define
name|PMC_FN_CSW_OUT
value|3
end_define

begin_define
define|#
directive|define
name|PMC_FN_DO_SAMPLES
value|4
end_define

begin_define
define|#
directive|define
name|PMC_FN_UNUSED1
value|5
end_define

begin_define
define|#
directive|define
name|PMC_FN_UNUSED2
value|6
end_define

begin_define
define|#
directive|define
name|PMC_FN_MMAP
value|7
end_define

begin_define
define|#
directive|define
name|PMC_FN_MUNMAP
value|8
end_define

begin_define
define|#
directive|define
name|PMC_FN_USER_CALLCHAIN
value|9
end_define

begin_define
define|#
directive|define
name|PMC_FN_USER_CALLCHAIN_SOFT
value|10
end_define

begin_define
define|#
directive|define
name|PMC_FN_SOFT_SAMPLING
value|11
end_define

begin_define
define|#
directive|define
name|PMC_HR
value|0
end_define

begin_comment
comment|/* Hardware ring buffer */
end_comment

begin_define
define|#
directive|define
name|PMC_SR
value|1
end_define

begin_comment
comment|/* Software ring buffer */
end_comment

begin_struct
struct|struct
name|pmckern_procexec
block|{
name|int
name|pm_credentialschanged
decl_stmt|;
name|uintfptr_t
name|pm_entryaddr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pmckern_map_in
block|{
name|void
modifier|*
name|pm_file
decl_stmt|;
comment|/* filename or vnode pointer */
name|uintfptr_t
name|pm_address
decl_stmt|;
comment|/* address object is loaded at */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pmckern_map_out
block|{
name|uintfptr_t
name|pm_address
decl_stmt|;
comment|/* start address of region */
name|size_t
name|pm_size
decl_stmt|;
comment|/* size of unmapped region */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pmckern_soft
block|{
name|enum
name|pmc_event
name|pm_ev
decl_stmt|;
name|int
name|pm_cpu
decl_stmt|;
name|struct
name|trapframe
modifier|*
name|pm_tf
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Soft PMC.  */
end_comment

begin_define
define|#
directive|define
name|PMC_SOFT_DEFINE_EX
parameter_list|(
name|prov
parameter_list|,
name|mod
parameter_list|,
name|func
parameter_list|,
name|name
parameter_list|,
name|alloc
parameter_list|,
name|release
parameter_list|)
define|\
value|struct pmc_soft pmc_##prov##_##mod##_##func##_##name =			\ 	    { 0, alloc, release, { #prov "_" #mod "_" #func "." #name, 0 } };	\ 	SYSINIT(pmc_##prov##_##mod##_##func##_##name##_init, SI_SUB_KDTRACE, 	\ 	    SI_ORDER_SECOND + 1, pmc_soft_ev_register, 				\&pmc_##prov##_##mod##_##func##_##name );				\ 	SYSUNINIT(pmc_##prov##_##mod##_##func##_##name##_uninit, 		\ 	    SI_SUB_KDTRACE, SI_ORDER_SECOND + 1, pmc_soft_ev_deregister,	\&pmc_##prov##_##mod##_##func##_##name )
end_define

begin_define
define|#
directive|define
name|PMC_SOFT_DEFINE
parameter_list|(
name|prov
parameter_list|,
name|mod
parameter_list|,
name|func
parameter_list|,
name|name
parameter_list|)
define|\
value|PMC_SOFT_DEFINE_EX(prov, mod, func, name, NULL, NULL)
end_define

begin_define
define|#
directive|define
name|PMC_SOFT_DECLARE
parameter_list|(
name|prov
parameter_list|,
name|mod
parameter_list|,
name|func
parameter_list|,
name|name
parameter_list|)
define|\
value|extern struct pmc_soft pmc_##prov##_##mod##_##func##_##name
end_define

begin_comment
comment|/*  * PMC_SOFT_CALL can be used anywhere in the kernel.  * Require md defined PMC_FAKE_TRAPFRAME.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PMC_FAKE_TRAPFRAME
end_ifdef

begin_define
define|#
directive|define
name|PMC_SOFT_CALL
parameter_list|(
name|pr
parameter_list|,
name|mo
parameter_list|,
name|fu
parameter_list|,
name|na
parameter_list|)
define|\
value|do {										\ 	if (__predict_false(pmc_##pr##_##mo##_##fu##_##na.ps_running)) {	\ 		struct pmckern_soft ks;						\ 		register_t intr;						\ 		intr = intr_disable();						\ 		PMC_FAKE_TRAPFRAME(&pmc_tf[curcpu]);				\ 		ks.pm_ev = pmc_##pr##_##mo##_##fu##_##na.ps_ev.pm_ev_code;	\ 		ks.pm_cpu = PCPU_GET(cpuid);					\ 		ks.pm_tf =&pmc_tf[curcpu];					\ 		PMC_CALL_HOOK_UNLOCKED(curthread,				\ 		    PMC_FN_SOFT_SAMPLING, (void *)&ks);			\ 		intr_restore(intr);						\ 	}									\ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PMC_SOFT_CALL
parameter_list|(
name|pr
parameter_list|,
name|mo
parameter_list|,
name|fu
parameter_list|,
name|na
parameter_list|)
define|\
value|do {										\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * PMC_SOFT_CALL_TF need to be used carefully.  * Userland capture will be done during AST processing.  */
end_comment

begin_define
define|#
directive|define
name|PMC_SOFT_CALL_TF
parameter_list|(
name|pr
parameter_list|,
name|mo
parameter_list|,
name|fu
parameter_list|,
name|na
parameter_list|,
name|tf
parameter_list|)
define|\
value|do {										\ 	if (__predict_false(pmc_##pr##_##mo##_##fu##_##na.ps_running)) {	\ 		struct pmckern_soft ks;						\ 		register_t intr;						\ 		intr = intr_disable();						\ 		ks.pm_ev = pmc_##pr##_##mo##_##fu##_##na.ps_ev.pm_ev_code;	\ 		ks.pm_cpu = PCPU_GET(cpuid);					\ 		ks.pm_tf = tf;							\ 		PMC_CALL_HOOK_UNLOCKED(curthread,				\ 		    PMC_FN_SOFT_SAMPLING, (void *)&ks);			\ 		intr_restore(intr);						\ 	}									\ } while (0)
end_define

begin_struct
struct|struct
name|pmc_soft
block|{
name|int
name|ps_running
decl_stmt|;
name|void
function_decl|(
modifier|*
name|ps_alloc
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ps_release
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|struct
name|pmc_dyn_event_descr
name|ps_ev
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* hook */
end_comment

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|pmc_hook
function_decl|)
parameter_list|(
name|struct
name|thread
modifier|*
name|_td
parameter_list|,
name|int
name|_function
parameter_list|,
name|void
modifier|*
name|_arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|pmc_intr
function_decl|)
parameter_list|(
name|int
name|_cpu
parameter_list|,
name|struct
name|trapframe
modifier|*
name|_frame
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* SX lock protecting the hook */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|sx
name|pmc_sx
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Per-cpu flags indicating availability of sampling data */
end_comment

begin_decl_stmt
specifier|extern
specifier|volatile
name|cpuset_t
name|pmc_cpumask
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Count of system-wide sampling PMCs in existence */
end_comment

begin_decl_stmt
specifier|extern
specifier|volatile
name|int
name|pmc_ss_count
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* kernel version number */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|pmc_kernel_version
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PMC soft per cpu trapframe */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|trapframe
name|pmc_tf
index|[
name|MAXCPU
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Hook invocation; for use within the kernel */
end_comment

begin_define
define|#
directive|define
name|PMC_CALL_HOOK
parameter_list|(
name|t
parameter_list|,
name|cmd
parameter_list|,
name|arg
parameter_list|)
define|\
value|do {						\ 	sx_slock(&pmc_sx);			\ 	if (pmc_hook != NULL)			\ 		(pmc_hook)((t), (cmd), (arg));	\ 	sx_sunlock(&pmc_sx);			\ } while (0)
end_define

begin_comment
comment|/* Hook invocation that needs an exclusive lock */
end_comment

begin_define
define|#
directive|define
name|PMC_CALL_HOOK_X
parameter_list|(
name|t
parameter_list|,
name|cmd
parameter_list|,
name|arg
parameter_list|)
define|\
value|do {						\ 	sx_xlock(&pmc_sx);			\ 	if (pmc_hook != NULL)			\ 		(pmc_hook)((t), (cmd), (arg));	\ 	sx_xunlock(&pmc_sx);			\ } while (0)
end_define

begin_comment
comment|/*  * Some hook invocations (e.g., from context switch and clock handling  * code) need to be lock-free.  */
end_comment

begin_define
define|#
directive|define
name|PMC_CALL_HOOK_UNLOCKED
parameter_list|(
name|t
parameter_list|,
name|cmd
parameter_list|,
name|arg
parameter_list|)
define|\
value|do {						\ 	if (pmc_hook != NULL)			\ 		(pmc_hook)((t), (cmd), (arg));	\ } while (0)
end_define

begin_define
define|#
directive|define
name|PMC_SWITCH_CONTEXT
parameter_list|(
name|t
parameter_list|,
name|cmd
parameter_list|)
value|PMC_CALL_HOOK_UNLOCKED(t,cmd,NULL)
end_define

begin_comment
comment|/* Check if a process is using HWPMCs.*/
end_comment

begin_define
define|#
directive|define
name|PMC_PROC_IS_USING_PMCS
parameter_list|(
name|p
parameter_list|)
define|\
value|(__predict_false(p->p_flag& P_HWPMC))
end_define

begin_comment
comment|/* Check if a thread have pending user capture. */
end_comment

begin_define
define|#
directive|define
name|PMC_IS_PENDING_CALLCHAIN
parameter_list|(
name|p
parameter_list|)
define|\
value|(__predict_false((p)->td_pflags& TDP_CALLCHAIN))
end_define

begin_define
define|#
directive|define
name|PMC_SYSTEM_SAMPLING_ACTIVE
parameter_list|()
value|(pmc_ss_count> 0)
end_define

begin_comment
comment|/* Check if a CPU has recorded samples. */
end_comment

begin_define
define|#
directive|define
name|PMC_CPU_HAS_SAMPLES
parameter_list|(
name|C
parameter_list|)
value|(__predict_false(CPU_ISSET(C,&pmc_cpumask)))
end_define

begin_comment
comment|/*  * Helper functions.  */
end_comment

begin_function_decl
name|int
name|pmc_cpu_is_disabled
parameter_list|(
name|int
name|_cpu
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* deprecated */
end_comment

begin_function_decl
name|int
name|pmc_cpu_is_active
parameter_list|(
name|int
name|_cpu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmc_cpu_is_present
parameter_list|(
name|int
name|_cpu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmc_cpu_is_primary
parameter_list|(
name|int
name|_cpu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|pmc_cpu_max
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|INVARIANTS
end_ifdef

begin_function_decl
name|int
name|pmc_cpu_max_active
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Soft events functions.  */
end_comment

begin_function_decl
name|void
name|pmc_soft_ev_register
parameter_list|(
name|struct
name|pmc_soft
modifier|*
name|ps
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmc_soft_ev_deregister
parameter_list|(
name|struct
name|pmc_soft
modifier|*
name|ps
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|pmc_soft
modifier|*
name|pmc_soft_ev_acquire
parameter_list|(
name|enum
name|pmc_event
name|ev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmc_soft_ev_release
parameter_list|(
name|struct
name|pmc_soft
modifier|*
name|ps
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_PMCKERN_H_ */
end_comment

end_unit

