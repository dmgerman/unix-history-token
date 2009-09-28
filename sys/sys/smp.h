begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * ----------------------------------------------------------------------------  * "THE BEER-WARE LICENSE" (Revision 42):  *<phk@FreeBSD.org> wrote this file.  As long as you retain this notice you  * can do whatever you want with this stuff. If we meet some day, and you think  * this stuff is worth it, you can buy me a beer in return.   Poul-Henning Kamp  * ----------------------------------------------------------------------------  *  * $FreeBSD$  */
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

begin_comment
comment|/*  * Topology of a NUMA or HTT system.  *  * The top level topology is an array of pointers to groups.  Each group  * contains a bitmask of cpus in its group or subgroups.  It may also  * contain a pointer to an array of child groups.  *  * The bitmasks at non leaf groups may be used by consumers who support  * a smaller depth than the hardware provides.  *  * The topology may be omitted by systems where all CPUs are equal.  */
end_comment

begin_struct
struct|struct
name|cpu_group
block|{
name|struct
name|cpu_group
modifier|*
name|cg_parent
decl_stmt|;
comment|/* Our parent group. */
name|struct
name|cpu_group
modifier|*
name|cg_child
decl_stmt|;
comment|/* Optional children groups. */
name|cpumask_t
name|cg_mask
decl_stmt|;
comment|/* Mask of cpus in this group. */
name|int8_t
name|cg_count
decl_stmt|;
comment|/* Count of cpus in this group. */
name|int8_t
name|cg_children
decl_stmt|;
comment|/* Number of children groups. */
name|int8_t
name|cg_level
decl_stmt|;
comment|/* Shared cache level. */
name|int8_t
name|cg_flags
decl_stmt|;
comment|/* Traversal modifiers. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Defines common resources for CPUs in the group.  The highest level  * resource should be used when multiple are shared.  */
end_comment

begin_define
define|#
directive|define
name|CG_SHARE_NONE
value|0
end_define

begin_define
define|#
directive|define
name|CG_SHARE_L1
value|1
end_define

begin_define
define|#
directive|define
name|CG_SHARE_L2
value|2
end_define

begin_define
define|#
directive|define
name|CG_SHARE_L3
value|3
end_define

begin_comment
comment|/*  * Behavior modifiers for load balancing and affinity.  */
end_comment

begin_define
define|#
directive|define
name|CG_FLAG_HTT
value|0x01
end_define

begin_comment
comment|/* Schedule the alternate core last. */
end_comment

begin_define
define|#
directive|define
name|CG_FLAG_SMT
value|0x02
end_define

begin_comment
comment|/* New age htt, less crippled. */
end_comment

begin_define
define|#
directive|define
name|CG_FLAG_THREAD
value|(CG_FLAG_HTT | CG_FLAG_SMT)
end_define

begin_comment
comment|/* Any threading. */
end_comment

begin_comment
comment|/*  * Convenience routines for building topologies.  */
end_comment

begin_function_decl
name|struct
name|cpu_group
modifier|*
name|smp_topo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|cpu_group
modifier|*
name|smp_topo_none
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|cpu_group
modifier|*
name|smp_topo_1level
parameter_list|(
name|int
name|l1share
parameter_list|,
name|int
name|l1count
parameter_list|,
name|int
name|l1flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|cpu_group
modifier|*
name|smp_topo_2level
parameter_list|(
name|int
name|l2share
parameter_list|,
name|int
name|l2count
parameter_list|,
name|int
name|l1share
parameter_list|,
name|int
name|l1count
parameter_list|,
name|int
name|l1flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|cpu_group
modifier|*
name|smp_topo_find
parameter_list|(
name|struct
name|cpu_group
modifier|*
name|top
parameter_list|,
name|int
name|cpu
parameter_list|)
function_decl|;
end_function_decl

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
name|smp_active
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
specifier|volatile
name|cpumask_t
name|started_cpus
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|volatile
name|cpumask_t
name|stopped_cpus
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|cpumask_t
name|idle_cpus_mask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|cpumask_t
name|hlt_cpus_mask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|cpumask_t
name|logical_cpus_mask
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SMP */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|mp_maxid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mp_maxcpus
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mp_ncpus
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
name|cpumask_t
name|all_cpus
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

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_comment
comment|/*  * Machine dependent functions used to initialize MP support.  *  * The cpu_mp_probe() should check to see if MP support is present and return  * zero if it is not or non-zero if it is.  If MP support is present, then  * cpu_mp_start() will be called so that MP can be enabled.  This function  * should do things such as startup secondary processors.  It should also  * setup mp_ncpus, all_cpus, and smp_cpus.  It should also ensure that  * smp_active and smp_started are initialized at the appropriate time.  * Once cpu_mp_start() returns, machine independent MP startup code will be  * executed and a simple message will be output to the console.  Finally,  * cpu_mp_announce() will be called so that machine dependent messages about  * the MP support may be output to the console if desired.  *  * The cpu_setmaxid() function is called very early during the boot process  * so that the MD code may set mp_maxid to provide an upper bound on CPU IDs  * that other subsystems may use.  If a platform is not able to determine  * the exact maximum ID that early, then it may set mp_maxid to MAXCPU - 1.  */
end_comment

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|cpu_group
modifier|*
name|cpu_topo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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
name|cpu_mp_setmaxid
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
name|int
name|restart_cpus
parameter_list|(
name|cpumask_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|stop_cpus
parameter_list|(
name|cpumask_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|stop_cpus_hard
parameter_list|(
name|cpumask_t
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__amd64__
argument_list|)
end_if

begin_function_decl
name|int
name|suspend_cpus
parameter_list|(
name|cpumask_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|smp_rendezvous_action
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|smp_ipi_mtx
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SMP */
end_comment

begin_function_decl
name|void
name|smp_no_rendevous_barrier
parameter_list|(
name|void
modifier|*
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

begin_function_decl
name|void
name|smp_rendezvous_cpus
parameter_list|(
name|cpumask_t
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

