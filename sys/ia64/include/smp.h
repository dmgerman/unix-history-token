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
comment|/*  * Interprocessor interrupts for SMP. The following values are indices  * into the IPI vector table. The SAL gives us the vector used for AP  * wake-up. Keep the IPI_AP_WAKEUP at index 0.  */
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
name|IPI_AST
value|1
end_define

begin_define
define|#
directive|define
name|IPI_CHECKSTATE
value|2
end_define

begin_define
define|#
directive|define
name|IPI_INVLTLB
value|3
end_define

begin_define
define|#
directive|define
name|IPI_RENDEZVOUS
value|4
end_define

begin_define
define|#
directive|define
name|IPI_STOP
value|5
end_define

begin_define
define|#
directive|define
name|IPI_COUNT
value|6
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|mp_hardware
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mp_ipi_vector
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
name|u_int64_t
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

