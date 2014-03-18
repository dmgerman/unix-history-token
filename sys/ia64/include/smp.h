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

begin_define
define|#
directive|define
name|IPI_AST
value|ia64_ipi_ast
end_define

begin_define
define|#
directive|define
name|IPI_HARDCLOCK
value|ia64_ipi_hardclock
end_define

begin_define
define|#
directive|define
name|IPI_PREEMPT
value|ia64_ipi_preempt
end_define

begin_define
define|#
directive|define
name|IPI_RENDEZVOUS
value|ia64_ipi_rndzvs
end_define

begin_define
define|#
directive|define
name|IPI_STOP
value|ia64_ipi_stop
end_define

begin_define
define|#
directive|define
name|IPI_STOP_HARD
value|ia64_ipi_nmi
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_include
include|#
directive|include
file|<sys/_cpuset.h>
end_include

begin_struct_decl
struct_decl|struct
name|pcpu
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|ia64_ap_state
block|{
name|uint64_t
name|as_trace
decl_stmt|;
name|uint64_t
name|as_pgtbl_pte
decl_stmt|;
name|uint64_t
name|as_pgtbl_itir
decl_stmt|;
name|uint64_t
name|as_text_va
decl_stmt|;
name|uint64_t
name|as_text_pte
decl_stmt|;
name|uint64_t
name|as_text_itir
decl_stmt|;
name|uint64_t
name|as_data_va
decl_stmt|;
name|uint64_t
name|as_data_pte
decl_stmt|;
name|uint64_t
name|as_data_itir
decl_stmt|;
name|void
modifier|*
name|as_kstack
decl_stmt|;
name|void
modifier|*
name|as_kstack_top
decl_stmt|;
name|struct
name|pcpu
modifier|*
name|as_pcpu
decl_stmt|;
name|void
modifier|*
name|as_xtrace_buffer
decl_stmt|;
specifier|volatile
name|int
name|as_delay
decl_stmt|;
specifier|volatile
name|u_int
name|as_awake
decl_stmt|;
specifier|volatile
name|u_int
name|as_spin
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|ia64_ipi_ast
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ia64_ipi_hardclock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ia64_ipi_highfp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ia64_ipi_nmi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ia64_ipi_preempt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ia64_ipi_rndzvs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ia64_ipi_stop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ia64_ipi_wakeup
decl_stmt|;
end_decl_stmt

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

