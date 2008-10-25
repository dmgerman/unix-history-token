begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * evtchn.h  *   * Communication via Xen event channels.  * Also definitions for the device that demuxes notifications to userspace.  *   * Copyright (c) 2004, K A Fraser  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ASM_EVTCHN_H__
end_ifndef

begin_define
define|#
directive|define
name|__ASM_EVTCHN_H__
end_define

begin_include
include|#
directive|include
file|<machine/pcpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/xen/hypervisor.h>
end_include

begin_include
include|#
directive|include
file|<machine/xen/synch_bitops.h>
end_include

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_comment
comment|/*  * LOW-LEVEL DEFINITIONS  */
end_comment

begin_comment
comment|/*  * Unlike notify_remote_via_evtchn(), this is safe to use across  * save/restore. Notifications on a broken connection are silently dropped.  */
end_comment

begin_function_decl
name|void
name|notify_remote_via_irq
parameter_list|(
name|int
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Entry point for notifications into Linux subsystems. */
end_comment

begin_function_decl
name|void
name|evtchn_do_upcall
parameter_list|(
name|struct
name|intrframe
modifier|*
name|frame
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Entry point for notifications into the userland character device. */
end_comment

begin_function_decl
name|void
name|evtchn_device_upcall
parameter_list|(
name|int
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mask_evtchn
parameter_list|(
name|int
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|unmask_evtchn
parameter_list|(
name|int
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_function_decl
name|void
name|rebind_evtchn_to_cpu
parameter_list|(
name|int
name|port
parameter_list|,
name|unsigned
name|int
name|cpu
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|rebind_evtchn_to_cpu
parameter_list|(
name|port
parameter_list|,
name|cpu
parameter_list|)
value|((void)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
specifier|inline
name|int
name|test_and_set_evtchn_mask
parameter_list|(
name|int
name|port
parameter_list|)
block|{
name|shared_info_t
modifier|*
name|s
init|=
name|HYPERVISOR_shared_info
decl_stmt|;
return|return
name|synch_test_and_set_bit
argument_list|(
name|port
argument_list|,
name|s
operator|->
name|evtchn_mask
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|clear_evtchn
parameter_list|(
name|int
name|port
parameter_list|)
block|{
name|shared_info_t
modifier|*
name|s
init|=
name|HYPERVISOR_shared_info
decl_stmt|;
name|synch_clear_bit
argument_list|(
name|port
argument_list|,
operator|&
name|s
operator|->
name|evtchn_pending
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|notify_remote_via_evtchn
parameter_list|(
name|int
name|port
parameter_list|)
block|{
name|struct
name|evtchn_send
name|send
init|=
block|{
operator|.
name|port
operator|=
name|port
block|}
decl_stmt|;
operator|(
name|void
operator|)
name|HYPERVISOR_event_channel_op
argument_list|(
name|EVTCHNOP_send
argument_list|,
operator|&
name|send
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Use these to access the event channel underlying the IRQ handle returned  * by bind_*_to_irqhandler().  */
end_comment

begin_function_decl
name|int
name|irq_to_evtchn_port
parameter_list|(
name|int
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipi_pcpu
parameter_list|(
name|unsigned
name|int
name|cpu
parameter_list|,
name|int
name|vector
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * CHARACTER-DEVICE DEFINITIONS  */
end_comment

begin_define
define|#
directive|define
name|PORT_NORMAL
value|0x0000
end_define

begin_define
define|#
directive|define
name|PORT_EXCEPTION
value|0x8000
end_define

begin_define
define|#
directive|define
name|PORTIDX_MASK
value|0x7fff
end_define

begin_comment
comment|/* /dev/xen/evtchn resides at device number major=10, minor=200 */
end_comment

begin_define
define|#
directive|define
name|EVTCHN_MINOR
value|200
end_define

begin_comment
comment|/* /dev/xen/evtchn ioctls: */
end_comment

begin_comment
comment|/* EVTCHN_RESET: Clear and reinit the event buffer. Clear error condition. */
end_comment

begin_define
define|#
directive|define
name|EVTCHN_RESET
value|_IO('E', 1)
end_define

begin_comment
comment|/* EVTCHN_BIND: Bind to the specified event-channel port. */
end_comment

begin_define
define|#
directive|define
name|EVTCHN_BIND
value|_IO('E', 2)
end_define

begin_comment
comment|/* EVTCHN_UNBIND: Unbind from the specified event-channel port. */
end_comment

begin_define
define|#
directive|define
name|EVTCHN_UNBIND
value|_IO('E', 3)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ASM_EVTCHN_H__ */
end_comment

end_unit

