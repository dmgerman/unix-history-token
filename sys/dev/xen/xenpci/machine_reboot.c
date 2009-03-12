begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008 Citrix Systems, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/interrupt.h>
end_include

begin_include
include|#
directive|include
file|<machine/atomic.h>
end_include

begin_include
include|#
directive|include
file|<machine/xen/xen-os.h>
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
file|<dev/xen/xenpci/xenpcivar.h>
end_include

begin_function
name|void
name|xen_suspend
parameter_list|()
block|{
name|int
name|suspend_cancelled
decl_stmt|;
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
comment|/* 	 * Make sure we don't change cpus or switch to some other 	 * thread. for the duration. 	 */
name|critical_enter
argument_list|()
expr_stmt|;
comment|/* 	 * Prevent any races with evtchn_interrupt() handler. 	 */
name|irq_suspend
argument_list|()
expr_stmt|;
name|disable_intr
argument_list|()
expr_stmt|;
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
comment|/* 	 * Re-enable interrupts and put the scheduler back to normal. 	 */
name|enable_intr
argument_list|()
expr_stmt|;
name|critical_exit
argument_list|()
expr_stmt|;
comment|/* 	 * FreeBSD really needs to add DEVICE_SUSPEND_CANCEL or 	 * similar. 	 */
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
block|}
end_function

end_unit

