begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * vcpu.h  *   * VCPU initialisation, query, and hotplug.  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Copyright (c) 2005, Keir Fraser<keir@xensource.com>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_VCPU_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_VCPU_H__
end_define

begin_comment
comment|/*  * Prototype for this hypercall is:  *  int vcpu_op(int cmd, int vcpuid, void *extra_args)  * @cmd        == VCPUOP_??? (VCPU operation).  * @vcpuid     == VCPU to operate on.  * @extra_args == Operation-specific extra arguments (NULL if none).  */
end_comment

begin_comment
comment|/*  * Initialise a VCPU. Each VCPU can be initialised only once. A   * newly-initialised VCPU will not run until it is brought up by VCPUOP_up.  *   * @extra_arg == pointer to vcpu_guest_context structure containing initial  *               state for the VCPU.  */
end_comment

begin_define
define|#
directive|define
name|VCPUOP_initialise
value|0
end_define

begin_comment
comment|/*  * Bring up a VCPU. This makes the VCPU runnable. This operation will fail  * if the VCPU has not been initialised (VCPUOP_initialise).  */
end_comment

begin_define
define|#
directive|define
name|VCPUOP_up
value|1
end_define

begin_comment
comment|/*  * Bring down a VCPU (i.e., make it non-runnable).  * There are a few caveats that callers should observe:  *  1. This operation may return, and VCPU_is_up may return false, before the  *     VCPU stops running (i.e., the command is asynchronous). It is a good  *     idea to ensure that the VCPU has entered a non-critical loop before  *     bringing it down. Alternatively, this operation is guaranteed  *     synchronous if invoked by the VCPU itself.  *  2. After a VCPU is initialised, there is currently no way to drop all its  *     references to domain memory. Even a VCPU that is down still holds  *     memory references via its pagetable base pointer and GDT. It is good  *     practise to move a VCPU onto an 'idle' or default page table, LDT and  *     GDT before bringing it down.  */
end_comment

begin_define
define|#
directive|define
name|VCPUOP_down
value|2
end_define

begin_comment
comment|/* Returns 1 if the given VCPU is up. */
end_comment

begin_define
define|#
directive|define
name|VCPUOP_is_up
value|3
end_define

begin_comment
comment|/*  * Return information about the state and running time of a VCPU.  * @extra_arg == pointer to vcpu_runstate_info structure.  */
end_comment

begin_define
define|#
directive|define
name|VCPUOP_get_runstate_info
value|4
end_define

begin_struct
struct|struct
name|vcpu_runstate_info
block|{
comment|/* VCPU's current state (RUNSTATE_*). */
name|int
name|state
decl_stmt|;
comment|/* When was current state entered (system time, ns)? */
name|uint64_t
name|state_entry_time
decl_stmt|;
comment|/*      * Time spent in each RUNSTATE_* (ns). The sum of these times is      * guaranteed not to drift from system time.      */
name|uint64_t
name|time
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|vcpu_runstate_info
name|vcpu_runstate_info_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|vcpu_runstate_info_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* VCPU is currently running on a physical CPU. */
end_comment

begin_define
define|#
directive|define
name|RUNSTATE_running
value|0
end_define

begin_comment
comment|/* VCPU is runnable, but not currently scheduled on any physical CPU. */
end_comment

begin_define
define|#
directive|define
name|RUNSTATE_runnable
value|1
end_define

begin_comment
comment|/* VCPU is blocked (a.k.a. idle). It is therefore not runnable. */
end_comment

begin_define
define|#
directive|define
name|RUNSTATE_blocked
value|2
end_define

begin_comment
comment|/*  * VCPU is not runnable, but it is not blocked.  * This is a 'catch all' state for things like hotplug and pauses by the  * system administrator (or for critical sections in the hypervisor).  * RUNSTATE_blocked dominates this state (it is the preferred state).  */
end_comment

begin_define
define|#
directive|define
name|RUNSTATE_offline
value|3
end_define

begin_comment
comment|/*  * Register a shared memory area from which the guest may obtain its own  * runstate information without needing to execute a hypercall.  * Notes:  *  1. The registered address may be virtual or physical or guest handle,  *     depending on the platform. Virtual address or guest handle should be  *     registered on x86 systems.  *  2. Only one shared area may be registered per VCPU. The shared area is  *     updated by the hypervisor each time the VCPU is scheduled. Thus  *     runstate.state will always be RUNSTATE_running and  *     runstate.state_entry_time will indicate the system time at which the  *     VCPU was last scheduled to run.  * @extra_arg == pointer to vcpu_register_runstate_memory_area structure.  */
end_comment

begin_define
define|#
directive|define
name|VCPUOP_register_runstate_memory_area
value|5
end_define

begin_struct
struct|struct
name|vcpu_register_runstate_memory_area
block|{
union|union
block|{
name|XEN_GUEST_HANDLE
argument_list|(
argument|vcpu_runstate_info_t
argument_list|)
name|h
expr_stmt|;
name|struct
name|vcpu_runstate_info
modifier|*
name|v
decl_stmt|;
name|uint64_t
name|p
decl_stmt|;
block|}
name|addr
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|vcpu_register_runstate_memory_area
name|vcpu_register_runstate_memory_area_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|vcpu_register_runstate_memory_area_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Set or stop a VCPU's periodic timer. Every VCPU has one periodic timer  * which can be set via these commands. Periods smaller than one millisecond  * may not be supported.  */
end_comment

begin_define
define|#
directive|define
name|VCPUOP_set_periodic_timer
value|6
end_define

begin_comment
comment|/* arg == vcpu_set_periodic_timer_t */
end_comment

begin_define
define|#
directive|define
name|VCPUOP_stop_periodic_timer
value|7
end_define

begin_comment
comment|/* arg == NULL */
end_comment

begin_struct
struct|struct
name|vcpu_set_periodic_timer
block|{
name|uint64_t
name|period_ns
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|vcpu_set_periodic_timer
name|vcpu_set_periodic_timer_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|vcpu_set_periodic_timer_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Set or stop a VCPU's single-shot timer. Every VCPU has one single-shot  * timer which can be set via these commands.  */
end_comment

begin_define
define|#
directive|define
name|VCPUOP_set_singleshot_timer
value|8
end_define

begin_comment
comment|/* arg == vcpu_set_singleshot_timer_t */
end_comment

begin_define
define|#
directive|define
name|VCPUOP_stop_singleshot_timer
value|9
end_define

begin_comment
comment|/* arg == NULL */
end_comment

begin_struct
struct|struct
name|vcpu_set_singleshot_timer
block|{
name|uint64_t
name|timeout_abs_ns
decl_stmt|;
comment|/* Absolute system time value in nanoseconds. */
name|uint32_t
name|flags
decl_stmt|;
comment|/* VCPU_SSHOTTMR_??? */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|vcpu_set_singleshot_timer
name|vcpu_set_singleshot_timer_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|vcpu_set_singleshot_timer_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Flags to VCPUOP_set_singleshot_timer. */
end_comment

begin_comment
comment|/* Require the timeout to be in the future (return -ETIME if it's passed). */
end_comment

begin_define
define|#
directive|define
name|_VCPU_SSHOTTMR_future
value|(0)
end_define

begin_define
define|#
directive|define
name|VCPU_SSHOTTMR_future
value|(1U<< _VCPU_SSHOTTMR_future)
end_define

begin_comment
comment|/*   * Register a memory location in the guest address space for the  * vcpu_info structure.  This allows the guest to place the vcpu_info  * structure in a convenient place, such as in a per-cpu data area.  * The pointer need not be page aligned, but the structure must not  * cross a page boundary.  *  * This may be called only once per vcpu.  */
end_comment

begin_define
define|#
directive|define
name|VCPUOP_register_vcpu_info
value|10
end_define

begin_comment
comment|/* arg == vcpu_register_vcpu_info_t */
end_comment

begin_struct
struct|struct
name|vcpu_register_vcpu_info
block|{
name|uint64_t
name|mfn
decl_stmt|;
comment|/* mfn of page to place vcpu_info */
name|uint32_t
name|offset
decl_stmt|;
comment|/* offset within page */
name|uint32_t
name|rsvd
decl_stmt|;
comment|/* unused */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|vcpu_register_vcpu_info
name|vcpu_register_vcpu_info_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|vcpu_register_vcpu_info_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Send an NMI to the specified VCPU. @extra_arg == NULL. */
end_comment

begin_define
define|#
directive|define
name|VCPUOP_send_nmi
value|11
end_define

begin_comment
comment|/*   * Get the physical ID information for a pinned vcpu's underlying physical  * processor.  The physical ID informmation is architecture-specific.  * On x86: id[31:0]=apic_id, id[63:32]=acpi_id, and all values 0xff and  *         greater are reserved.  * This command returns -EINVAL if it is not a valid operation for this VCPU.  */
end_comment

begin_define
define|#
directive|define
name|VCPUOP_get_physid
value|12
end_define

begin_comment
comment|/* arg == vcpu_get_physid_t */
end_comment

begin_struct
struct|struct
name|vcpu_get_physid
block|{
name|uint64_t
name|phys_id
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|vcpu_get_physid
name|vcpu_get_physid_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|vcpu_get_physid_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|xen_vcpu_physid_to_x86_apicid
parameter_list|(
name|physid
parameter_list|)
define|\
value|((((uint32_t)(physid))>= 0xff) ? 0xff : ((uint8_t)(physid)))
end_define

begin_define
define|#
directive|define
name|xen_vcpu_physid_to_x86_acpiid
parameter_list|(
name|physid
parameter_list|)
define|\
value|((((uint32_t)((physid)>>32))>= 0xff) ? 0xff : ((uint8_t)((physid)>>32)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_VCPU_H__ */
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

