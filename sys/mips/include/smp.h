begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * ----------------------------------------------------------------------------  * "THE BEER-WARE LICENSE" (Revision 42):  *<phk@FreeBSD.org> wrote this file.  As long as you retain this notice you  * can do whatever you want with this stuff. If we meet some day, and you think  * this stuff is worth it, you can buy me a beer in return.   Poul-Henning Kamp  * ----------------------------------------------------------------------------  *  *	from: src/sys/alpha/include/smp.h,v 1.8 2005/01/05 20:05:50 imp  *	JNPR: smp.h,v 1.3 2006/12/02 09:53:41 katta  * $FreeBSD$  *  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/_cpuset.h>
end_include

begin_include
include|#
directive|include
file|<machine/pcb.h>
end_include

begin_comment
comment|/*  * Interprocessor interrupts for SMP.  */
end_comment

begin_define
define|#
directive|define
name|IPI_RENDEZVOUS
value|0x0002
end_define

begin_define
define|#
directive|define
name|IPI_AST
value|0x0004
end_define

begin_define
define|#
directive|define
name|IPI_STOP
value|0x0008
end_define

begin_define
define|#
directive|define
name|IPI_STOP_HARD
value|0x0008
end_define

begin_define
define|#
directive|define
name|IPI_PREEMPT
value|0x0010
end_define

begin_define
define|#
directive|define
name|IPI_HARDCLOCK
value|0x0020
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_function_decl
name|void
name|ipi_all_but_self
parameter_list|(
name|int
name|ipi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipi_cpu
parameter_list|(
name|int
name|cpu
parameter_list|,
name|u_int
name|ipi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipi_selected
parameter_list|(
name|cpuset_t
name|cpus
parameter_list|,
name|int
name|ipi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|smp_init_secondary
parameter_list|(
name|u_int32_t
name|cpuid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mpentry
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|pcb
name|stoppcbs
index|[]
decl_stmt|;
end_decl_stmt

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
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_SMP_H_ */
end_comment

end_unit

