begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Jake Burkholder.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_SMP_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_SMP_H_
end_define

begin_define
define|#
directive|define
name|CPU_CLKSYNC
value|1
end_define

begin_define
define|#
directive|define
name|CPU_INIT
value|2
end_define

begin_define
define|#
directive|define
name|CPU_BOOTSTRAP
value|3
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_include
include|#
directive|include
file|<machine/intr_machdep.h>
end_include

begin_include
include|#
directive|include
file|<machine/tte.h>
end_include

begin_define
define|#
directive|define
name|IDR_BUSY
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|IDR_NACK
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|IPI_AST
value|PIL_AST
end_define

begin_define
define|#
directive|define
name|IPI_RENDEZVOUS
value|PIL_RENDEZVOUS
end_define

begin_define
define|#
directive|define
name|IPI_STOP
value|PIL_STOP
end_define

begin_define
define|#
directive|define
name|IPI_PREEMPT
value|PIL_PREEMPT
end_define

begin_define
define|#
directive|define
name|IPI_RETRIES
value|5000
end_define

begin_struct
struct|struct
name|cpu_start_args
block|{
name|u_int
name|csa_count
decl_stmt|;
name|u_int
name|csa_state
decl_stmt|;
name|vm_offset_t
name|csa_pcpu
decl_stmt|;
name|u_int
name|csa_cpuid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ipi_cache_args
block|{
name|u_int
name|ica_mask
decl_stmt|;
name|vm_paddr_t
name|ica_pa
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ipi_tlb_args
block|{
name|u_int
name|ita_mask
decl_stmt|;
name|struct
name|pmap
modifier|*
name|ita_pmap
decl_stmt|;
name|u_long
name|ita_start
decl_stmt|;
name|u_long
name|ita_end
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ita_va
value|ita_start
end_define

begin_struct_decl
struct_decl|struct
name|pcpu
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|struct
name|pcb
name|stoppcbs
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|cpu_mp_bootstrap
parameter_list|(
name|struct
name|pcpu
modifier|*
name|pc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_mp_shutdown
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_ipi_selected
parameter_list|(
name|int
name|cpus
parameter_list|,
name|uint16_t
modifier|*
name|cpulist
parameter_list|,
name|u_long
name|d0
parameter_list|,
name|u_long
name|d1
parameter_list|,
name|u_long
name|d2
parameter_list|,
name|uint64_t
modifier|*
name|ackmask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_ipi_send
parameter_list|(
name|u_int
name|mid
parameter_list|,
name|u_long
name|d0
parameter_list|,
name|u_long
name|d1
parameter_list|,
name|u_long
name|d2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_ipi_ast
parameter_list|(
name|struct
name|trapframe
modifier|*
name|tf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_ipi_stop
parameter_list|(
name|struct
name|trapframe
modifier|*
name|tf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_ipi_preempt
parameter_list|(
name|struct
name|trapframe
modifier|*
name|tf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipi_selected
parameter_list|(
name|u_int
name|cpus
parameter_list|,
name|u_int
name|ipi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipi_all
parameter_list|(
name|u_int
name|ipi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipi_all_but_self
parameter_list|(
name|u_int
name|ipi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_offset_t
name|mp_tramp_alloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mp_set_tsb_desc_ra
parameter_list|(
name|vm_paddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mp_add_nucleus_mapping
parameter_list|(
name|vm_offset_t
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|ipi_mtx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ipi_cache_args
name|ipi_cache_args
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ipi_tlb_args
name|ipi_tlb_args
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|mp_tramp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|mp_tramp_code
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|mp_tramp_code_len
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|mp_tramp_tte_slots
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|mp_tramp_tsb_desc_ra
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|mp_tramp_func
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|mp_startup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
name|tl_ipi_level
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|tl_invltlb
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|tl_invlctx
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|tl_invlpg
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|tl_invlrng
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|tl_tsbupdate
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|tl_ttehashupdate
index|[]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MACHINE_PMAP_H_
argument_list|)
operator|&&
name|defined
argument_list|(
name|_SYS_MUTEX_H_
argument_list|)
end_if

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static __inline void * ipi_dcache_page_inval(void *func, vm_paddr_t pa) { 	struct ipi_cache_args *ica;  	if (smp_cpus == 1) 		return (NULL); 	ica =&ipi_cache_args; 	mtx_lock_spin(&ipi_mtx); 	ica->ica_mask = all_cpus; 	ica->ica_pa = pa; 	cpu_ipi_selected(PCPU_GET(other_cpus), 0, (u_long)func, (u_long)ica); 	return (&ica->ica_mask); }  static __inline void * ipi_icache_page_inval(void *func, vm_paddr_t pa) { 	struct ipi_cache_args *ica;  	if (smp_cpus == 1) 		return (NULL); 	ica =&ipi_cache_args; 	mtx_lock_spin(&ipi_mtx); 	ica->ica_mask = all_cpus; 	ica->ica_pa = pa; 	cpu_ipi_selected(PCPU_GET(other_cpus), 0, (u_long)func, (u_long)ica); 	return (&ica->ica_mask); }  static __inline void * ipi_tlb_context_demap(struct pmap *pm) { 	struct ipi_tlb_args *ita; 	u_int cpus;  	if (smp_cpus == 1) 		return (NULL); 	if ((cpus = (pm->pm_active& PCPU_GET(other_cpus))) == 0) 		return (NULL); 	ita =&ipi_tlb_args; 	mtx_lock_spin(&ipi_mtx); 	ita->ita_mask = cpus | PCPU_GET(cpumask); 	ita->ita_pmap = pm; 	cpu_ipi_selected(cpus, 0, (u_long)tl_ipi_tlb_context_demap, 	    (u_long)ita); 	return (&ita->ita_mask); }  static __inline void * ipi_tlb_page_demap(struct pmap *pm, vm_offset_t va) { 	struct ipi_tlb_args *ita; 	u_int cpus;  	if (smp_cpus == 1) 		return (NULL); 	if ((cpus = (pm->pm_active& PCPU_GET(other_cpus))) == 0) 		return (NULL); 	ita =&ipi_tlb_args; 	mtx_lock_spin(&ipi_mtx); 	ita->ita_mask = cpus | PCPU_GET(cpumask); 	ita->ita_pmap = pm; 	ita->ita_va = va; 	cpu_ipi_selected(cpus, 0, (u_long)tl_ipi_tlb_page_demap, (u_long)ita); 	return (&ita->ita_mask); }  static __inline void * ipi_tlb_range_demap(struct pmap *pm, vm_offset_t start, vm_offset_t end) { 	struct ipi_tlb_args *ita; 	u_int cpus;  	if (smp_cpus == 1) 		return (NULL); 	if ((cpus = (pm->pm_active& PCPU_GET(other_cpus))) == 0) 		return (NULL); 	ita =&ipi_tlb_args; 	mtx_lock_spin(&ipi_mtx); 	ita->ita_mask = cpus | PCPU_GET(cpumask); 	ita->ita_pmap = pm; 	ita->ita_start = start; 	ita->ita_end = end; 	cpu_ipi_selected(cpus, 0, (u_long)tl_ipi_tlb_range_demap, (u_long)ita); 	return (&ita->ita_mask); }
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|__inline
name|void
name|ipi_wait
parameter_list|(
name|void
modifier|*
name|cookie
parameter_list|)
block|{
specifier|volatile
name|u_int
modifier|*
name|mask
decl_stmt|;
if|if
condition|(
operator|(
name|mask
operator|=
name|cookie
operator|)
operator|!=
name|NULL
condition|)
block|{
name|atomic_clear_int
argument_list|(
name|mask
argument_list|,
name|PCPU_GET
argument_list|(
name|cpumask
argument_list|)
argument_list|)
expr_stmt|;
while|while
condition|(
operator|*
name|mask
operator|!=
literal|0
condition|)
empty_stmt|;
name|mtx_unlock_spin
argument_list|(
operator|&
name|ipi_mtx
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_PMAP_H_&& _SYS_MUTEX_H_ */
end_comment

begin_else
else|#
directive|else
end_else

begin_function
specifier|static
name|__inline
name|void
modifier|*
name|ipi_dcache_page_inval
parameter_list|(
name|void
modifier|*
name|func
parameter_list|,
name|vm_paddr_t
name|pa
parameter_list|)
block|{
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
modifier|*
name|ipi_icache_page_inval
parameter_list|(
name|void
modifier|*
name|func
parameter_list|,
name|vm_paddr_t
name|pa
parameter_list|)
block|{
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
modifier|*
name|ipi_tlb_context_demap
parameter_list|(
name|struct
name|pmap
modifier|*
name|pm
parameter_list|)
block|{
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
modifier|*
name|ipi_tlb_page_demap
parameter_list|(
name|struct
name|pmap
modifier|*
name|pm
parameter_list|,
name|vm_offset_t
name|va
parameter_list|)
block|{
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
modifier|*
name|ipi_tlb_range_demap
parameter_list|(
name|struct
name|pmap
modifier|*
name|pm
parameter_list|,
name|vm_offset_t
name|start
parameter_list|,
name|vm_offset_t
name|end
parameter_list|)
block|{
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|ipi_wait
parameter_list|(
name|void
modifier|*
name|cookie
parameter_list|)
block|{ }
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SMP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_SMP_H_ */
end_comment

end_unit

