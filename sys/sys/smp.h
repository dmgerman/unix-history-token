begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ----------------------------------------------------------------------------  * "THE BEER-WARE LICENSE" (Revision 42):  *<phk@FreeBSD.org> wrote this file.  As long as you retain this notice you  * can do whatever you want with this stuff. If we meet some day, and you think  * this stuff is worth it, you can buy me a beer in return.   Poul-Henning Kamp  * ----------------------------------------------------------------------------  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SMP_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SMP_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|cpustop_restartfunc
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|mp_ncpus
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|smp_active
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|volatile
name|int
name|smp_started
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|smp_cpus
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|all_cpus
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|volatile
name|u_int
name|started_cpus
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|volatile
name|u_int
name|stopped_cpus
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|mp_maxid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Macro allowing us to determine whether a CPU is absent at any given  * time, thus permitting us to configure sparse maps of cpuid-dependent  * (per-CPU) structures.  */
end_comment

begin_define
define|#
directive|define
name|CPU_ABSENT
parameter_list|(
name|x_cpu
parameter_list|)
value|((all_cpus& (1<< (x_cpu))) == 0)
end_define

begin_comment
comment|/*  * Machine dependent functions used to initialize MP support.  *  * The cpu_mp_probe() should check to see if MP support is present and return  * zero if it is not or non-zero if it is.  If MP support is present, then  * cpu_mp_start() will be called so that MP can be enabled.  This function  * should do things such as startup secondary processors.  It should also  * setup mp_ncpus, all_cpus, and smp_cpus.  It should also ensure that  * smp_active and smp_started are initialized at the appropriate time.  * Once cpu_mp_start() returns, machine independent MP startup code will be  * executed and a simple message will be output to the console.  Finally,  * cpu_mp_announce() will be called so that machine dependent messages about  * the MP support may be output to the console if desired.  */
end_comment

begin_function_decl
name|void
name|cpu_mp_announce
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cpu_mp_probe
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_mp_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|forward_signal
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|forward_roundrobin
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|restart_cpus
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|stop_cpus
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|smp_rendezvous_action
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|smp_rendezvous
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SMP */
end_comment

begin_define
define|#
directive|define
name|CPU_ABSENT
parameter_list|(
name|x_cpu
parameter_list|)
value|(0)
end_define

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
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_SMP_H_ */
end_comment

end_unit

