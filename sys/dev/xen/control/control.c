begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Justin T. Gibbs, Spectra Logic Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_comment
comment|/*-  * PV suspend/resume support:  *  * Copyright (c) 2004 Christian Limpach.  * Copyright (c) 2004-2006,2008 Kip Macy  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Christian Limpach.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*-  * HVM suspend/resume support:  *  * Copyright (c) 2008 Citrix Systems, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**  * \file control.c  *  * \brief Device driver to repond to control domain events that impact  *        this VM.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/bio.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/disk.h>
end_include

begin_include
include|#
directive|include
file|<sys/fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/filedesc.h>
end_include

begin_include
include|#
directive|include
file|<sys/kdb.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/namei.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/reboot.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<sys/sched.h>
end_include

begin_include
include|#
directive|include
file|<sys/taskqueue.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_include
include|#
directive|include
file|<sys/sched.h>
end_include

begin_include
include|#
directive|include
file|<sys/smp.h>
end_include

begin_include
include|#
directive|include
file|<sys/eventhandler.h>
end_include

begin_include
include|#
directive|include
file|<sys/timetc.h>
end_include

begin_include
include|#
directive|include
file|<geom/geom.h>
end_include

begin_include
include|#
directive|include
file|<machine/_inttypes.h>
end_include

begin_include
include|#
directive|include
file|<machine/intr_machdep.h>
end_include

begin_include
include|#
directive|include
file|<x86/apicvar.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_extern.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_kern.h>
end_include

begin_include
include|#
directive|include
file|<xen/xen-os.h>
end_include

begin_include
include|#
directive|include
file|<xen/blkif.h>
end_include

begin_include
include|#
directive|include
file|<xen/evtchn.h>
end_include

begin_include
include|#
directive|include
file|<xen/gnttab.h>
end_include

begin_include
include|#
directive|include
file|<xen/xen_intr.h>
end_include

begin_include
include|#
directive|include
file|<xen/hvm.h>
end_include

begin_include
include|#
directive|include
file|<xen/interface/event_channel.h>
end_include

begin_include
include|#
directive|include
file|<xen/interface/grant_table.h>
end_include

begin_include
include|#
directive|include
file|<xen/xenbus/xenbusvar.h>
end_include

begin_comment
comment|/*--------------------------- Forward Declarations --------------------------*/
end_comment

begin_comment
comment|/** Function signature for shutdown event handlers. */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|xctrl_shutdown_handler_t
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|static
name|xctrl_shutdown_handler_t
name|xctrl_poweroff
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|xctrl_shutdown_handler_t
name|xctrl_reboot
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|xctrl_shutdown_handler_t
name|xctrl_suspend
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|xctrl_shutdown_handler_t
name|xctrl_crash
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*-------------------------- Private Data Structures -------------------------*/
end_comment

begin_comment
comment|/** Element type for lookup table of event name to handler. */
end_comment

begin_struct
struct|struct
name|xctrl_shutdown_reason
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|xctrl_shutdown_handler_t
modifier|*
name|handler
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** Lookup table for shutdown event name to handler. */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|xctrl_shutdown_reason
name|xctrl_shutdown_reasons
index|[]
init|=
block|{
block|{
literal|"poweroff"
block|,
name|xctrl_poweroff
block|}
block|,
block|{
literal|"reboot"
block|,
name|xctrl_reboot
block|}
block|,
block|{
literal|"suspend"
block|,
name|xctrl_suspend
block|}
block|,
block|{
literal|"crash"
block|,
name|xctrl_crash
block|}
block|,
block|{
literal|"halt"
block|,
name|xctrl_poweroff
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|xctrl_softc
block|{
name|struct
name|xs_watch
name|xctrl_watch
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*------------------------------ Event Handlers ------------------------------*/
end_comment

begin_function
specifier|static
name|void
name|xctrl_poweroff
parameter_list|()
block|{
name|shutdown_nice
argument_list|(
name|RB_POWEROFF
operator||
name|RB_HALT
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|xctrl_reboot
parameter_list|()
block|{
name|shutdown_nice
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|xctrl_suspend
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|SMP
name|cpuset_t
name|cpu_suspend_map
decl_stmt|;
endif|#
directive|endif
name|int
name|suspend_cancelled
decl_stmt|;
name|EVENTHANDLER_INVOKE
argument_list|(
name|power_suspend_early
argument_list|)
expr_stmt|;
name|stop_all_proc
argument_list|()
expr_stmt|;
name|EVENTHANDLER_INVOKE
argument_list|(
name|power_suspend
argument_list|)
expr_stmt|;
if|if
condition|(
name|smp_started
condition|)
block|{
name|thread_lock
argument_list|(
name|curthread
argument_list|)
expr_stmt|;
name|sched_bind
argument_list|(
name|curthread
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|thread_unlock
argument_list|(
name|curthread
argument_list|)
expr_stmt|;
block|}
name|KASSERT
argument_list|(
operator|(
name|PCPU_GET
argument_list|(
name|cpuid
argument_list|)
operator|==
literal|0
operator|)
argument_list|,
operator|(
literal|"Not running on CPU#0"
operator|)
argument_list|)
expr_stmt|;
comment|/* 	 * Clear our XenStore node so the toolstack knows we are 	 * responding to the suspend request. 	 */
name|xs_write
argument_list|(
name|XST_NIL
argument_list|,
literal|"control"
argument_list|,
literal|"shutdown"
argument_list|,
literal|""
argument_list|)
expr_stmt|;
comment|/* 	 * Be sure to hold Giant across DEVICE_SUSPEND/RESUME since non-MPSAFE 	 * drivers need this. 	 */
name|mtx_lock
argument_list|(
operator|&
name|Giant
argument_list|)
expr_stmt|;
if|if
condition|(
name|DEVICE_SUSPEND
argument_list|(
name|root_bus
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|mtx_unlock
argument_list|(
operator|&
name|Giant
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%s: device_suspend failed\n"
argument_list|,
name|__func__
argument_list|)
expr_stmt|;
return|return;
block|}
ifdef|#
directive|ifdef
name|SMP
name|CPU_ZERO
argument_list|(
operator|&
name|cpu_suspend_map
argument_list|)
expr_stmt|;
comment|/* silence gcc */
if|if
condition|(
name|smp_started
condition|)
block|{
comment|/* 		 * Suspend other CPUs. This prevents IPIs while we 		 * are resuming, and will allow us to reset per-cpu 		 * vcpu_info on resume. 		 */
name|cpu_suspend_map
operator|=
name|all_cpus
expr_stmt|;
name|CPU_CLR
argument_list|(
name|PCPU_GET
argument_list|(
name|cpuid
argument_list|)
argument_list|,
operator|&
name|cpu_suspend_map
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|CPU_EMPTY
argument_list|(
operator|&
name|cpu_suspend_map
argument_list|)
condition|)
name|suspend_cpus
argument_list|(
name|cpu_suspend_map
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* 	 * Prevent any races with evtchn_interrupt() handler. 	 */
name|disable_intr
argument_list|()
expr_stmt|;
name|intr_suspend
argument_list|()
expr_stmt|;
name|xen_hvm_suspend
argument_list|()
expr_stmt|;
name|suspend_cancelled
operator|=
name|HYPERVISOR_suspend
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|xen_hvm_resume
argument_list|(
name|suspend_cancelled
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|intr_resume
argument_list|(
name|suspend_cancelled
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|enable_intr
argument_list|()
expr_stmt|;
comment|/* 	 * Reset grant table info. 	 */
name|gnttab_resume
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|SMP
comment|/* Send an IPI_BITMAP in case there are pending bitmap IPIs. */
name|lapic_ipi_vectored
argument_list|(
name|IPI_BITMAP_VECTOR
argument_list|,
name|APIC_IPI_DEST_ALL
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|CPU_EMPTY
argument_list|(
operator|&
name|cpu_suspend_map
argument_list|)
condition|)
block|{
comment|/* 		 * Now that event channels have been initialized, 		 * resume CPUs. 		 */
name|resume_cpus
argument_list|(
name|cpu_suspend_map
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* 	 * FreeBSD really needs to add DEVICE_SUSPEND_CANCEL or 	 * similar. 	 */
name|DEVICE_RESUME
argument_list|(
name|root_bus
argument_list|)
expr_stmt|;
name|mtx_unlock
argument_list|(
operator|&
name|Giant
argument_list|)
expr_stmt|;
comment|/* 	 * Warm up timecounter again and reset system clock. 	 */
name|timecounter
operator|->
name|tc_get_timecount
argument_list|(
name|timecounter
argument_list|)
expr_stmt|;
name|timecounter
operator|->
name|tc_get_timecount
argument_list|(
name|timecounter
argument_list|)
expr_stmt|;
name|inittodr
argument_list|(
name|time_second
argument_list|)
expr_stmt|;
if|if
condition|(
name|smp_started
condition|)
block|{
name|thread_lock
argument_list|(
name|curthread
argument_list|)
expr_stmt|;
name|sched_unbind
argument_list|(
name|curthread
argument_list|)
expr_stmt|;
name|thread_unlock
argument_list|(
name|curthread
argument_list|)
expr_stmt|;
block|}
name|resume_all_proc
argument_list|()
expr_stmt|;
name|EVENTHANDLER_INVOKE
argument_list|(
name|power_resume
argument_list|)
expr_stmt|;
if|if
condition|(
name|bootverbose
condition|)
name|printf
argument_list|(
literal|"System resumed after suspension\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|xctrl_crash
parameter_list|()
block|{
name|panic
argument_list|(
literal|"Xen directed crash"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|xen_pv_shutdown_final
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|howto
parameter_list|)
block|{
comment|/* 	 * Inform the hypervisor that shutdown is complete. 	 * This is not necessary in HVM domains since Xen 	 * emulates ACPI in that mode and FreeBSD's ACPI 	 * support will request this transition. 	 */
if|if
condition|(
name|howto
operator|&
operator|(
name|RB_HALT
operator||
name|RB_POWEROFF
operator|)
condition|)
name|HYPERVISOR_shutdown
argument_list|(
name|SHUTDOWN_poweroff
argument_list|)
expr_stmt|;
else|else
name|HYPERVISOR_shutdown
argument_list|(
name|SHUTDOWN_reboot
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*------------------------------ Event Reception -----------------------------*/
end_comment

begin_function
specifier|static
name|void
name|xctrl_on_watch_event
parameter_list|(
name|struct
name|xs_watch
modifier|*
name|watch
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|vec
parameter_list|,
name|unsigned
name|int
name|len
parameter_list|)
block|{
specifier|const
name|struct
name|xctrl_shutdown_reason
modifier|*
name|reason
decl_stmt|;
specifier|const
name|struct
name|xctrl_shutdown_reason
modifier|*
name|last_reason
decl_stmt|;
name|char
modifier|*
name|result
decl_stmt|;
name|int
name|error
decl_stmt|;
name|int
name|result_len
decl_stmt|;
name|error
operator|=
name|xs_read
argument_list|(
name|XST_NIL
argument_list|,
literal|"control"
argument_list|,
literal|"shutdown"
argument_list|,
operator|&
name|result_len
argument_list|,
operator|(
name|void
operator|*
operator|*
operator|)
operator|&
name|result
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|!=
literal|0
condition|)
return|return;
name|reason
operator|=
name|xctrl_shutdown_reasons
expr_stmt|;
name|last_reason
operator|=
name|reason
operator|+
name|nitems
argument_list|(
name|xctrl_shutdown_reasons
argument_list|)
expr_stmt|;
while|while
condition|(
name|reason
operator|<
name|last_reason
condition|)
block|{
if|if
condition|(
operator|!
name|strcmp
argument_list|(
name|result
argument_list|,
name|reason
operator|->
name|name
argument_list|)
condition|)
block|{
name|reason
operator|->
name|handler
argument_list|()
expr_stmt|;
break|break;
block|}
name|reason
operator|++
expr_stmt|;
block|}
name|free
argument_list|(
name|result
argument_list|,
name|M_XENSTORE
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*------------------ Private Device Attachment Functions  --------------------*/
end_comment

begin_comment
comment|/**  * \brief Identify instances of this device type in the system.  *  * \param driver  The driver performing this identify action.  * \param parent  The NewBus parent device for any devices this method adds.  */
end_comment

begin_function
specifier|static
name|void
name|xctrl_identify
parameter_list|(
name|driver_t
modifier|*
name|driver
name|__unused
parameter_list|,
name|device_t
name|parent
parameter_list|)
block|{
comment|/* 	 * A single device instance for our driver is always present 	 * in a system operating under Xen. 	 */
name|BUS_ADD_CHILD
argument_list|(
name|parent
argument_list|,
literal|0
argument_list|,
name|driver
operator|->
name|name
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**  * \brief Probe for the existance of the Xen Control device  *  * \param dev  NewBus device_t for this Xen control instance.  *  * \return  Always returns 0 indicating success.  */
end_comment

begin_function
specifier|static
name|int
name|xctrl_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|device_set_desc
argument_list|(
name|dev
argument_list|,
literal|"Xen Control Device"
argument_list|)
expr_stmt|;
return|return
operator|(
name|BUS_PROBE_NOWILDCARD
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * \brief Attach the Xen control device.  *  * \param dev  NewBus device_t for this Xen control instance.  *  * \return  On success, 0. Otherwise an errno value indicating the  *          type of failure.  */
end_comment

begin_function
specifier|static
name|int
name|xctrl_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|xctrl_softc
modifier|*
name|xctrl
decl_stmt|;
name|xctrl
operator|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
comment|/* Activate watch */
name|xctrl
operator|->
name|xctrl_watch
operator|.
name|node
operator|=
literal|"control/shutdown"
expr_stmt|;
name|xctrl
operator|->
name|xctrl_watch
operator|.
name|callback
operator|=
name|xctrl_on_watch_event
expr_stmt|;
name|xctrl
operator|->
name|xctrl_watch
operator|.
name|callback_data
operator|=
operator|(
name|uintptr_t
operator|)
name|xctrl
expr_stmt|;
name|xs_register_watch
argument_list|(
operator|&
name|xctrl
operator|->
name|xctrl_watch
argument_list|)
expr_stmt|;
if|if
condition|(
name|xen_pv_domain
argument_list|()
condition|)
name|EVENTHANDLER_REGISTER
argument_list|(
name|shutdown_final
argument_list|,
name|xen_pv_shutdown_final
argument_list|,
name|NULL
argument_list|,
name|SHUTDOWN_PRI_LAST
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * \brief Detach the Xen control device.  *  * \param dev  NewBus device_t for this Xen control device instance.  *  * \return  On success, 0. Otherwise an errno value indicating the  *          type of failure.  */
end_comment

begin_function
specifier|static
name|int
name|xctrl_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|xctrl_softc
modifier|*
name|xctrl
decl_stmt|;
name|xctrl
operator|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
comment|/* Release watch */
name|xs_unregister_watch
argument_list|(
operator|&
name|xctrl
operator|->
name|xctrl_watch
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*-------------------- Private Device Attachment Data  -----------------------*/
end_comment

begin_decl_stmt
specifier|static
name|device_method_t
name|xctrl_methods
index|[]
init|=
block|{
comment|/* Device interface */
name|DEVMETHOD
argument_list|(
name|device_identify
argument_list|,
name|xctrl_identify
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|xctrl_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|xctrl_attach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_detach
argument_list|,
name|xctrl_detach
argument_list|)
block|,
name|DEVMETHOD_END
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DEFINE_CLASS_0
argument_list|(
name|xctrl
argument_list|,
name|xctrl_driver
argument_list|,
name|xctrl_methods
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|xctrl_softc
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|devclass_t
name|xctrl_devclass
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|xctrl
argument_list|,
name|xenstore
argument_list|,
name|xctrl_driver
argument_list|,
name|xctrl_devclass
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

