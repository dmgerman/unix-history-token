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

begin_function
specifier|static
name|__inline
name|uint64_t
name|get_cyclecount
parameter_list|(
name|void
parameter_list|)
block|{
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
name|bt
operator|.
name|frac
operator|^
name|bt
operator|.
name|sec
operator|)
return|;
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
name|void
modifier|*
parameter_list|,
name|void
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

