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
comment|/*  * Interprocessor interrupts for SMP. The following values are indices  * into the IPI vector table. The SAL gives us the vector used for AP  * wake-up. We base the other vectors on that. Keep IPI_AP_WAKEUP at  * index 0. See sal.c for details.  */
end_comment

begin_comment
comment|/* Architecture specific IPIs. */
end_comment

begin_define
define|#
directive|define
name|IPI_AP_WAKEUP
value|0
end_define

begin_define
define|#
directive|define
name|IPI_HIGH_FP
value|1
end_define

begin_define
define|#
directive|define
name|IPI_MCA_CMCV
value|2
end_define

begin_define
define|#
directive|define
name|IPI_MCA_RENDEZ
value|3
end_define

begin_define
define|#
directive|define
name|IPI_TEST
value|4
end_define

begin_comment
comment|/* Machine independent IPIs. */
end_comment

begin_define
define|#
directive|define
name|IPI_AST
value|5
end_define

begin_define
define|#
directive|define
name|IPI_RENDEZVOUS
value|6
end_define

begin_define
define|#
directive|define
name|IPI_STOP
value|7
end_define

begin_define
define|#
directive|define
name|IPI_PREEMPT
value|8
end_define

begin_define
define|#
directive|define
name|IPI_COUNT
value|9
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_struct_decl
struct_decl|struct
name|pcpu
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|int
name|ipi_vector
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|ipi_all
parameter_list|(
name|int
name|ipi
parameter_list|)
function_decl|;
end_function_decl

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
name|ipi_selected
parameter_list|(
name|cpumask_t
name|cpus
parameter_list|,
name|int
name|ipi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipi_self
parameter_list|(
name|int
name|ipi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipi_send
parameter_list|(
name|struct
name|pcpu
modifier|*
parameter_list|,
name|int
name|ipi
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

