begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: cpu.h,v 1.2 2001/02/23 21:23:52 reinoud Exp $ */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MACHINE_CPU_H
end_ifndef

begin_define
define|#
directive|define
name|MACHINE_CPU_H
end_define

begin_include
include|#
directive|include
file|<machine/armreg.h>
end_include

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_function_decl
name|void
name|cpu_halt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|swi_vm
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|>=
literal|6
end_if

begin_include
include|#
directive|include
file|<machine/cpu-v6.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<machine/cpu-v4.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ARM_ARCH>= 6 */
end_comment

begin_function
specifier|static
name|__inline
name|uint64_t
name|get_cyclecount
parameter_list|(
name|void
parameter_list|)
block|{
if|#
directive|if
name|__ARM_ARCH
operator|>=
literal|6
if|#
directive|if
operator|(
name|__ARM_ARCH
operator|>
literal|6
operator|)
operator|&&
name|defined
argument_list|(
name|DEV_PMU
argument_list|)
if|if
condition|(
name|pmu_attched
condition|)
block|{
name|u_int
name|cpu
decl_stmt|;
name|uint64_t
name|h
decl_stmt|,
name|h2
decl_stmt|;
name|uint32_t
name|l
decl_stmt|,
name|r
decl_stmt|;
name|cpu
operator|=
name|PCPU_GET
argument_list|(
name|cpuid
argument_list|)
expr_stmt|;
name|h
operator|=
operator|(
name|uint64_t
operator|)
name|atomic_load_acq_32
argument_list|(
operator|&
name|ccnt_hi
index|[
name|cpu
index|]
argument_list|)
expr_stmt|;
name|l
operator|=
name|cp15_pmccntr_get
argument_list|()
expr_stmt|;
comment|/* In case interrupts are disabled we need to check for overflow. */
name|r
operator|=
name|cp15_pmovsr_get
argument_list|()
expr_stmt|;
if|if
condition|(
name|r
operator|&
name|PMU_OVSR_C
condition|)
block|{
name|atomic_add_32
argument_list|(
operator|&
name|ccnt_hi
index|[
name|cpu
index|]
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* Clear the event. */
name|cp15_pmovsr_set
argument_list|(
name|PMU_OVSR_C
argument_list|)
expr_stmt|;
block|}
comment|/* Make sure there was no wrap-around while we read the lo half. */
name|h2
operator|=
operator|(
name|uint64_t
operator|)
name|atomic_load_acq_32
argument_list|(
operator|&
name|ccnt_hi
index|[
name|cpu
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|h
operator|!=
name|h2
condition|)
name|l
operator|=
name|cp15_pmccntr_get
argument_list|()
expr_stmt|;
return|return
operator|(
name|h2
operator|<<
literal|32
operator||
name|l
operator|)
return|;
block|}
else|else
endif|#
directive|endif
return|return
name|cp15_pmccntr_get
argument_list|()
return|;
else|#
directive|else
comment|/* No performance counters, so use binuptime(9). This is slooooow */
name|struct
name|bintime
name|bt
decl_stmt|;
name|binuptime
argument_list|(
operator|&
name|bt
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|uint64_t
operator|)
name|bt
operator|.
name|sec
operator|<<
literal|56
operator||
name|bt
operator|.
name|frac
operator|>>
literal|8
operator|)
return|;
endif|#
directive|endif
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TRAPF_USERMODE
parameter_list|(
name|frame
parameter_list|)
value|((frame->tf_spsr& PSR_MODE) == PSR_USR32_MODE)
end_define

begin_define
define|#
directive|define
name|TRAPF_PC
parameter_list|(
name|tfp
parameter_list|)
value|((tfp)->tf_pc)
end_define

begin_define
define|#
directive|define
name|cpu_getstack
parameter_list|(
name|td
parameter_list|)
value|((td)->td_frame->tf_usr_sp)
end_define

begin_define
define|#
directive|define
name|cpu_setstack
parameter_list|(
name|td
parameter_list|,
name|sp
parameter_list|)
value|((td)->td_frame->tf_usr_sp = (sp))
end_define

begin_define
define|#
directive|define
name|cpu_spinwait
parameter_list|()
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|ARM_NVEC
value|8
end_define

begin_define
define|#
directive|define
name|ARM_VEC_ALL
value|0xffffffff
end_define

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|vector_page
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Params passed into initarm. If you change the size of this you will  * need to update locore.S to allocate more memory on the stack before  * it calls initarm.  */
end_comment

begin_struct
struct|struct
name|arm_boot_params
block|{
name|register_t
name|abp_size
decl_stmt|;
comment|/* Size of this structure */
name|register_t
name|abp_r0
decl_stmt|;
comment|/* r0 from the boot loader */
name|register_t
name|abp_r1
decl_stmt|;
comment|/* r1 from the boot loader */
name|register_t
name|abp_r2
decl_stmt|;
comment|/* r2 from the boot loader */
name|register_t
name|abp_r3
decl_stmt|;
comment|/* r3 from the boot loader */
name|vm_offset_t
name|abp_physaddr
decl_stmt|;
comment|/* The kernel physical address */
name|vm_offset_t
name|abp_pagetable
decl_stmt|;
comment|/* The early page table */
block|}
struct|;
end_struct

begin_function_decl
name|void
name|arm_vector_init
parameter_list|(
name|vm_offset_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fork_trampoline
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|identify_arm_cpu
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|initarm
parameter_list|(
name|struct
name|arm_boot_params
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
name|btext
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|etext
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|badaddr_read
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !MACHINE_CPU_H */
end_comment

end_unit

