begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/limits.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/interrupt.h>
end_include

begin_include
include|#
directive|include
file|<sys/pcpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/xen/xen-os.h>
end_include

begin_include
include|#
directive|include
file|<machine/xen/xenvar.h>
end_include

begin_include
include|#
directive|include
file|<xen/hypervisor.h>
end_include

begin_include
include|#
directive|include
file|<xen/xen_intr.h>
end_include

begin_include
include|#
directive|include
file|<xen/evtchn.h>
end_include

begin_include
include|#
directive|include
file|<sys/smp.h>
end_include

begin_include
include|#
directive|include
file|<dev/xen/xenpci/xenpcivar.h>
end_include

begin_struct
struct|struct
name|ap_suspend_info
block|{
name|int
name|do_spin
decl_stmt|;
name|atomic_t
name|nr_spinning
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_SMP
end_ifdef

begin_comment
comment|/*  * Spinning prevents, for example, APs touching grant table entries while  * the shared grant table is not mapped into the address space imemdiately  * after resume.  */
end_comment

begin_function
specifier|static
name|void
name|ap_suspend
parameter_list|(
name|void
modifier|*
name|_info
parameter_list|)
block|{
name|struct
name|ap_suspend_info
modifier|*
name|info
init|=
name|_info
decl_stmt|;
name|BUG_ON
argument_list|(
operator|!
name|irqs_disabled
argument_list|()
argument_list|)
expr_stmt|;
name|atomic_inc
argument_list|(
operator|&
name|info
operator|->
name|nr_spinning
argument_list|)
expr_stmt|;
name|mb
argument_list|()
expr_stmt|;
while|while
condition|(
name|info
operator|->
name|do_spin
condition|)
name|cpu_relax
argument_list|()
expr_stmt|;
name|mb
argument_list|()
expr_stmt|;
name|atomic_dec
argument_list|(
operator|&
name|info
operator|->
name|nr_spinning
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|initiate_ap_suspend
parameter_list|(
name|i
parameter_list|)
value|smp_call_function(ap_suspend, i, 0, 0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !defined(CONFIG_SMP) */
end_comment

begin_define
define|#
directive|define
name|initiate_ap_suspend
parameter_list|(
name|i
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|int
name|bp_suspend
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|suspend_cancelled
decl_stmt|;
name|suspend_cancelled
operator|=
name|HYPERVISOR_suspend
argument_list|(
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|suspend_cancelled
condition|)
name|xenpci_resume
argument_list|()
expr_stmt|;
return|return
name|suspend_cancelled
return|;
block|}
end_function

begin_function
name|void
name|xen_suspend
parameter_list|()
block|{
name|int
name|suspend_cancelled
decl_stmt|;
comment|//struct ap_suspend_info info;
if|if
condition|(
name|DEVICE_SUSPEND
argument_list|(
name|root_bus
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"xen_suspend: device_suspend failed\n"
argument_list|)
expr_stmt|;
return|return;
block|}
name|critical_enter
argument_list|()
expr_stmt|;
comment|/* Prevent any races with evtchn_interrupt() handler. */
name|irq_suspend
argument_list|()
expr_stmt|;
if|#
directive|if
literal|0
block|info.do_spin = 1; 	atomic_set(&info.nr_spinning, 0); 	smp_mb();  	nr_cpus = num_online_cpus() - 1;  	err = initiate_ap_suspend(&info); 	if (err< 0) { 		critical_exit();
comment|//xenbus_suspend_cancel();
block|return err; 	}  	while (atomic_read(&info.nr_spinning) != nr_cpus) 		cpu_relax();
endif|#
directive|endif
name|disable_intr
argument_list|()
expr_stmt|;
name|suspend_cancelled
operator|=
name|bp_suspend
argument_list|()
expr_stmt|;
comment|//resume_notifier(suspend_cancelled);
name|enable_intr
argument_list|()
expr_stmt|;
if|#
directive|if
literal|0
block|smp_mb(); 	info.do_spin = 0; 	while (atomic_read(&info.nr_spinning) != 0) 		cpu_relax();
endif|#
directive|endif
name|critical_exit
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|suspend_cancelled
condition|)
name|DEVICE_RESUME
argument_list|(
name|root_bus
argument_list|)
expr_stmt|;
if|#
directive|if
literal|0
block|else 		xenbus_suspend_cancel();
endif|#
directive|endif
block|}
end_function

end_unit

