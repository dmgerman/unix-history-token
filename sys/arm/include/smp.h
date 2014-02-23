begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
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

begin_define
define|#
directive|define
name|IPI_AST
value|0
end_define

begin_define
define|#
directive|define
name|IPI_PREEMPT
value|2
end_define

begin_define
define|#
directive|define
name|IPI_RENDEZVOUS
value|3
end_define

begin_define
define|#
directive|define
name|IPI_STOP
value|4
end_define

begin_define
define|#
directive|define
name|IPI_STOP_HARD
value|5
end_define

begin_define
define|#
directive|define
name|IPI_HARDCLOCK
value|6
end_define

begin_define
define|#
directive|define
name|IPI_TLB
value|7
end_define

begin_function_decl
name|void
name|init_secondary
parameter_list|(
name|int
name|cpu
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
name|u_int
name|ipi
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* PIC interface */
end_comment

begin_function_decl
name|void
name|pic_ipi_send
parameter_list|(
name|cpuset_t
name|cpus
parameter_list|,
name|u_int
name|ipi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pic_ipi_clear
parameter_list|(
name|int
name|ipi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pic_ipi_get
parameter_list|(
name|int
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Platform interface */
end_comment

begin_function_decl
name|void
name|platform_mp_setmaxid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|platform_mp_probe
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|platform_mp_start_ap
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|platform_mp_init_secondary
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|platform_ipi_send
parameter_list|(
name|cpuset_t
name|cpus
parameter_list|,
name|u_int
name|ipi
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* global data in mp_machdep.c */
end_comment

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
comment|/* !_MACHINE_SMP_H_ */
end_comment

end_unit

