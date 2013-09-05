begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * event_channel.h  *  * Event channels between domains.  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Copyright (c) 2003-2004, K A Fraser.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_EVENT_CHANNEL_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_EVENT_CHANNEL_H__
end_define

begin_include
include|#
directive|include
file|"xen.h"
end_include

begin_comment
comment|/*  * `incontents 150 evtchn Event Channels  *  * Event channels are the basic primitive provided by Xen for event  * notifications. An event is the Xen equivalent of a hardware  * interrupt. They essentially store one bit of information, the event  * of interest is signalled by transitioning this bit from 0 to 1.  *  * Notifications are received by a guest via an upcall from Xen,  * indicating when an event arrives (setting the bit). Further  * notifications are masked until the bit is cleared again (therefore,  * guests must check the value of the bit after re-enabling event  * delivery to ensure no missed notifications).  *  * Event notifications can be masked by setting a flag; this is  * equivalent to disabling interrupts and can be used to ensure  * atomicity of certain operations in the guest kernel.  *  * Event channels are represented by the evtchn_* fields in  * struct shared_info and struct vcpu_info.  */
end_comment

begin_comment
comment|/*  * ` enum neg_errnoval  * ` HYPERVISOR_event_channel_op(enum event_channel_op cmd, void *args)  * `  * @cmd  == EVTCHNOP_* (event-channel operation).  * @args == struct evtchn_* Operation-specific extra arguments (NULL if none).  */
end_comment

begin_comment
comment|/* ` enum event_channel_op { // EVTCHNOP_* => struct evtchn_* */
end_comment

begin_define
define|#
directive|define
name|EVTCHNOP_bind_interdomain
value|0
end_define

begin_define
define|#
directive|define
name|EVTCHNOP_bind_virq
value|1
end_define

begin_define
define|#
directive|define
name|EVTCHNOP_bind_pirq
value|2
end_define

begin_define
define|#
directive|define
name|EVTCHNOP_close
value|3
end_define

begin_define
define|#
directive|define
name|EVTCHNOP_send
value|4
end_define

begin_define
define|#
directive|define
name|EVTCHNOP_status
value|5
end_define

begin_define
define|#
directive|define
name|EVTCHNOP_alloc_unbound
value|6
end_define

begin_define
define|#
directive|define
name|EVTCHNOP_bind_ipi
value|7
end_define

begin_define
define|#
directive|define
name|EVTCHNOP_bind_vcpu
value|8
end_define

begin_define
define|#
directive|define
name|EVTCHNOP_unmask
value|9
end_define

begin_define
define|#
directive|define
name|EVTCHNOP_reset
value|10
end_define

begin_comment
comment|/* ` } */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_EVTCHN_PORT_DEFINED__
end_ifndef

begin_typedef
typedef|typedef
name|uint32_t
name|evtchn_port_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|evtchn_port_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|__XEN_EVTCHN_PORT_DEFINED__
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * EVTCHNOP_alloc_unbound: Allocate a port in domain<dom> and mark as  * accepting interdomain bindings from domain<remote_dom>. A fresh port  * is allocated in<dom> and returned as<port>.  * NOTES:  *  1. If the caller is unprivileged then<dom> must be DOMID_SELF.  *  2.<rdom> may be DOMID_SELF, allowing loopback connections.  */
end_comment

begin_struct
struct|struct
name|evtchn_alloc_unbound
block|{
comment|/* IN parameters */
name|domid_t
name|dom
decl_stmt|,
name|remote_dom
decl_stmt|;
comment|/* OUT parameters */
name|evtchn_port_t
name|port
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|evtchn_alloc_unbound
name|evtchn_alloc_unbound_t
typedef|;
end_typedef

begin_comment
comment|/*  * EVTCHNOP_bind_interdomain: Construct an interdomain event channel between  * the calling domain and<remote_dom>.<remote_dom,remote_port> must identify  * a port that is unbound and marked as accepting bindings from the calling  * domain. A fresh port is allocated in the calling domain and returned as  *<local_port>.  * NOTES:  *  1.<remote_dom> may be DOMID_SELF, allowing loopback connections.  */
end_comment

begin_struct
struct|struct
name|evtchn_bind_interdomain
block|{
comment|/* IN parameters. */
name|domid_t
name|remote_dom
decl_stmt|;
name|evtchn_port_t
name|remote_port
decl_stmt|;
comment|/* OUT parameters. */
name|evtchn_port_t
name|local_port
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|evtchn_bind_interdomain
name|evtchn_bind_interdomain_t
typedef|;
end_typedef

begin_comment
comment|/*  * EVTCHNOP_bind_virq: Bind a local event channel to VIRQ<irq> on specified  * vcpu.  * NOTES:  *  1. Virtual IRQs are classified as per-vcpu or global. See the VIRQ list  *     in xen.h for the classification of each VIRQ.  *  2. Global VIRQs must be allocated on VCPU0 but can subsequently be  *     re-bound via EVTCHNOP_bind_vcpu.  *  3. Per-vcpu VIRQs may be bound to at most one event channel per vcpu.  *     The allocated event channel is bound to the specified vcpu and the  *     binding cannot be changed.  */
end_comment

begin_struct
struct|struct
name|evtchn_bind_virq
block|{
comment|/* IN parameters. */
name|uint32_t
name|virq
decl_stmt|;
comment|/* enum virq */
name|uint32_t
name|vcpu
decl_stmt|;
comment|/* OUT parameters. */
name|evtchn_port_t
name|port
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|evtchn_bind_virq
name|evtchn_bind_virq_t
typedef|;
end_typedef

begin_comment
comment|/*  * EVTCHNOP_bind_pirq: Bind a local event channel to a real IRQ (PIRQ<irq>).  * NOTES:  *  1. A physical IRQ may be bound to at most one event channel per domain.  *  2. Only a sufficiently-privileged domain may bind to a physical IRQ.  */
end_comment

begin_struct
struct|struct
name|evtchn_bind_pirq
block|{
comment|/* IN parameters. */
name|uint32_t
name|pirq
decl_stmt|;
define|#
directive|define
name|BIND_PIRQ__WILL_SHARE
value|1
name|uint32_t
name|flags
decl_stmt|;
comment|/* BIND_PIRQ__* */
comment|/* OUT parameters. */
name|evtchn_port_t
name|port
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|evtchn_bind_pirq
name|evtchn_bind_pirq_t
typedef|;
end_typedef

begin_comment
comment|/*  * EVTCHNOP_bind_ipi: Bind a local event channel to receive events.  * NOTES:  *  1. The allocated event channel is bound to the specified vcpu. The binding  *     may not be changed.  */
end_comment

begin_struct
struct|struct
name|evtchn_bind_ipi
block|{
name|uint32_t
name|vcpu
decl_stmt|;
comment|/* OUT parameters. */
name|evtchn_port_t
name|port
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|evtchn_bind_ipi
name|evtchn_bind_ipi_t
typedef|;
end_typedef

begin_comment
comment|/*  * EVTCHNOP_close: Close a local event channel<port>. If the channel is  * interdomain then the remote end is placed in the unbound state  * (EVTCHNSTAT_unbound), awaiting a new connection.  */
end_comment

begin_struct
struct|struct
name|evtchn_close
block|{
comment|/* IN parameters. */
name|evtchn_port_t
name|port
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|evtchn_close
name|evtchn_close_t
typedef|;
end_typedef

begin_comment
comment|/*  * EVTCHNOP_send: Send an event to the remote end of the channel whose local  * endpoint is<port>.  */
end_comment

begin_struct
struct|struct
name|evtchn_send
block|{
comment|/* IN parameters. */
name|evtchn_port_t
name|port
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|evtchn_send
name|evtchn_send_t
typedef|;
end_typedef

begin_comment
comment|/*  * EVTCHNOP_status: Get the current status of the communication channel which  * has an endpoint at<dom, port>.  * NOTES:  *  1.<dom> may be specified as DOMID_SELF.  *  2. Only a sufficiently-privileged domain may obtain the status of an event  *     channel for which<dom> is not DOMID_SELF.  */
end_comment

begin_struct
struct|struct
name|evtchn_status
block|{
comment|/* IN parameters */
name|domid_t
name|dom
decl_stmt|;
name|evtchn_port_t
name|port
decl_stmt|;
comment|/* OUT parameters */
define|#
directive|define
name|EVTCHNSTAT_closed
value|0
comment|/* Channel is not in use.                 */
define|#
directive|define
name|EVTCHNSTAT_unbound
value|1
comment|/* Channel is waiting interdom connection.*/
define|#
directive|define
name|EVTCHNSTAT_interdomain
value|2
comment|/* Channel is connected to remote domain. */
define|#
directive|define
name|EVTCHNSTAT_pirq
value|3
comment|/* Channel is bound to a phys IRQ line.   */
define|#
directive|define
name|EVTCHNSTAT_virq
value|4
comment|/* Channel is bound to a virtual IRQ line */
define|#
directive|define
name|EVTCHNSTAT_ipi
value|5
comment|/* Channel is bound to a virtual IPI line */
name|uint32_t
name|status
decl_stmt|;
name|uint32_t
name|vcpu
decl_stmt|;
comment|/* VCPU to which this channel is bound.   */
union|union
block|{
struct|struct
block|{
name|domid_t
name|dom
decl_stmt|;
block|}
name|unbound
struct|;
comment|/* EVTCHNSTAT_unbound */
struct|struct
block|{
name|domid_t
name|dom
decl_stmt|;
name|evtchn_port_t
name|port
decl_stmt|;
block|}
name|interdomain
struct|;
comment|/* EVTCHNSTAT_interdomain */
name|uint32_t
name|pirq
decl_stmt|;
comment|/* EVTCHNSTAT_pirq        */
name|uint32_t
name|virq
decl_stmt|;
comment|/* EVTCHNSTAT_virq        */
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|evtchn_status
name|evtchn_status_t
typedef|;
end_typedef

begin_comment
comment|/*  * EVTCHNOP_bind_vcpu: Specify which vcpu a channel should notify when an  * event is pending.  * NOTES:  *  1. IPI-bound channels always notify the vcpu specified at bind time.  *     This binding cannot be changed.  *  2. Per-VCPU VIRQ channels always notify the vcpu specified at bind time.  *     This binding cannot be changed.  *  3. All other channels notify vcpu0 by default. This default is set when  *     the channel is allocated (a port that is freed and subsequently reused  *     has its binding reset to vcpu0).  */
end_comment

begin_struct
struct|struct
name|evtchn_bind_vcpu
block|{
comment|/* IN parameters. */
name|evtchn_port_t
name|port
decl_stmt|;
name|uint32_t
name|vcpu
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|evtchn_bind_vcpu
name|evtchn_bind_vcpu_t
typedef|;
end_typedef

begin_comment
comment|/*  * EVTCHNOP_unmask: Unmask the specified local event-channel port and deliver  * a notification to the appropriate VCPU if an event is pending.  */
end_comment

begin_struct
struct|struct
name|evtchn_unmask
block|{
comment|/* IN parameters. */
name|evtchn_port_t
name|port
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|evtchn_unmask
name|evtchn_unmask_t
typedef|;
end_typedef

begin_comment
comment|/*  * EVTCHNOP_reset: Close all event channels associated with specified domain.  * NOTES:  *  1.<dom> may be specified as DOMID_SELF.  *  2. Only a sufficiently-privileged domain may specify other than DOMID_SELF.  */
end_comment

begin_struct
struct|struct
name|evtchn_reset
block|{
comment|/* IN parameters. */
name|domid_t
name|dom
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|evtchn_reset
name|evtchn_reset_t
typedef|;
end_typedef

begin_comment
comment|/*  * ` enum neg_errnoval  * ` HYPERVISOR_event_channel_op_compat(struct evtchn_op *op)  * `  * Superceded by new event_channel_op() hypercall since 0x00030202.  */
end_comment

begin_struct
struct|struct
name|evtchn_op
block|{
name|uint32_t
name|cmd
decl_stmt|;
comment|/* enum event_channel_op */
union|union
block|{
name|struct
name|evtchn_alloc_unbound
name|alloc_unbound
decl_stmt|;
name|struct
name|evtchn_bind_interdomain
name|bind_interdomain
decl_stmt|;
name|struct
name|evtchn_bind_virq
name|bind_virq
decl_stmt|;
name|struct
name|evtchn_bind_pirq
name|bind_pirq
decl_stmt|;
name|struct
name|evtchn_bind_ipi
name|bind_ipi
decl_stmt|;
name|struct
name|evtchn_close
name|close
decl_stmt|;
name|struct
name|evtchn_send
name|send
decl_stmt|;
name|struct
name|evtchn_status
name|status
decl_stmt|;
name|struct
name|evtchn_bind_vcpu
name|bind_vcpu
decl_stmt|;
name|struct
name|evtchn_unmask
name|unmask
decl_stmt|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|evtchn_op
name|evtchn_op_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|evtchn_op_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_EVENT_CHANNEL_H__ */
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

