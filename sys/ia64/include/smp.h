begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $FreeBSD$  */
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

begin_comment
comment|/*  * Interprocessor interrupts for SMP.  */
end_comment

begin_define
define|#
directive|define
name|IPI_INVLTLB
value|0x0001
end_define

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
name|IPI_CHECKSTATE
value|0x0008
end_define

begin_define
define|#
directive|define
name|IPI_STOP
value|0x0010
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_comment
comment|/* global data in mp_machdep.c */
end_comment

begin_decl_stmt
specifier|extern
specifier|volatile
name|u_int
name|checkstate_probed_cpus
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|volatile
name|u_int
name|checkstate_need_ast
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|volatile
name|u_int
name|resched_cpus
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|ipi_all
parameter_list|(
name|u_int64_t
name|ipi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipi_all_but_self
parameter_list|(
name|u_int64_t
name|ipi
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
name|u_int64_t
name|ipi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipi_self
parameter_list|(
name|u_int64_t
name|ipi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|smp_init_secondary
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
comment|/* !_MACHINE_SMP_H */
end_comment

end_unit

