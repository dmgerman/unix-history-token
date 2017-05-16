begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * xen_intr.h  *   * APIs for managing Xen event channel, virtual IRQ, and physical IRQ  * notifications.  *   * Copyright (c) 2004, K A Fraser  * Copyright (c) 2012, Spectra Logic Corporation  *  * This file may be distributed separately from the Linux kernel, or  * incorporated into other software packages, subject to the following license:  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this source file (the "Software"), to deal in the Software without  * restriction, including without limitation the rights to use, copy, modify,  * merge, publish, distribute, sublicense, and/or sell copies of the Software,  * and to permit persons to whom the Software is furnished to do so, subject to  * the following conditions:  *   * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *   * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS  * IN THE SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XEN_INTR_H_
end_ifndef

begin_define
define|#
directive|define
name|_XEN_INTR_H_
end_define

begin_include
include|#
directive|include
file|<xen/interface/event_channel.h>
end_include

begin_comment
comment|/** Registered Xen interrupt callback handle. */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|xen_intr_handle_t
typedef|;
end_typedef

begin_comment
comment|/** If non-zero, the hypervisor has been configured to use a direct vector */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|xen_vector_callback_enabled
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|xen_intr_handle_upcall
parameter_list|(
name|struct
name|trapframe
modifier|*
name|trap_frame
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Associate an already allocated local event channel port an interrupt  * handler.  *  * \param dev         The device making this bind request.  * \param local_port  The event channel to bind.  * \param filter      An interrupt filter handler.  Specify NULL  *                    to always dispatch to the ithread handler.  * \param handler     An interrupt ithread handler.  Optional (can  *                    specify NULL) if all necessary event actions  *                    are performed by filter.  * \param arg         Argument to present to both filter and handler.  * \param irqflags    Interrupt handler flags.  See sys/bus.h.  * \param handlep     Pointer to an opaque handle used to manage this  *                    registration.  *  * \returns  0 on success, otherwise an errno.  */
end_comment

begin_function_decl
name|int
name|xen_intr_bind_local_port
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|evtchn_port_t
name|local_port
parameter_list|,
name|driver_filter_t
name|filter
parameter_list|,
name|driver_intr_t
name|handler
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|enum
name|intr_type
name|irqflags
parameter_list|,
name|xen_intr_handle_t
modifier|*
name|handlep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Allocate a local event channel port, accessible by the specified  * remote/foreign domain and, if successful, associate the port with  * the specified interrupt handler.  *  * \param dev            The device making this bind request.  * \param remote_domain  Remote domain grant permission to signal the  *                       newly allocated local port.  * \param filter         An interrupt filter handler.  Specify NULL  *                       to always dispatch to the ithread handler.  * \param handler        An interrupt ithread handler.  Optional (can  *                       specify NULL) if all necessary event actions  *                       are performed by filter.  * \param arg            Argument to present to both filter and handler.  * \param irqflags       Interrupt handler flags.  See sys/bus.h.  * \param handlep        Pointer to an opaque handle used to manage this  *                       registration.  *  * \returns  0 on success, otherwise an errno.  */
end_comment

begin_function_decl
name|int
name|xen_intr_alloc_and_bind_local_port
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_int
name|remote_domain
parameter_list|,
name|driver_filter_t
name|filter
parameter_list|,
name|driver_intr_t
name|handler
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|enum
name|intr_type
name|irqflags
parameter_list|,
name|xen_intr_handle_t
modifier|*
name|handlep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Associate the specified interrupt handler with the remote event  * channel port specified by remote_domain and remote_port.  *  * \param dev            The device making this bind request.  * \param remote_domain  The domain peer for this event channel connection.  * \param remote_port    Remote domain's local port number for this event  *                       channel port.  * \param filter         An interrupt filter handler.  Specify NULL  *                       to always dispatch to the ithread handler.  * \param handler        An interrupt ithread handler.  Optional (can  *                       specify NULL) if all necessary event actions  *                       are performed by filter.  * \param arg            Argument to present to both filter and handler.  * \param irqflags       Interrupt handler flags.  See sys/bus.h.  * \param handlep        Pointer to an opaque handle used to manage this  *                       registration.  *  * \returns  0 on success, otherwise an errno.  */
end_comment

begin_function_decl
name|int
name|xen_intr_bind_remote_port
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_int
name|remote_domain
parameter_list|,
name|evtchn_port_t
name|remote_port
parameter_list|,
name|driver_filter_t
name|filter
parameter_list|,
name|driver_intr_t
name|handler
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|enum
name|intr_type
name|irqflags
parameter_list|,
name|xen_intr_handle_t
modifier|*
name|handlep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Associate the specified interrupt handler with the specified Xen  * virtual interrupt source.  *  * \param dev       The device making this bind request.  * \param virq      The Xen virtual IRQ number for the Xen interrupt  *                  source being hooked.  * \param cpu       The cpu on which interrupt events should be delivered.   * \param filter    An interrupt filter handler.  Specify NULL  *                  to always dispatch to the ithread handler.  * \param handler   An interrupt ithread handler.  Optional (can  *                  specify NULL) if all necessary event actions  *                  are performed by filter.  * \param arg       Argument to present to both filter and handler.  * \param irqflags  Interrupt handler flags.  See sys/bus.h.  * \param handlep   Pointer to an opaque handle used to manage this  *                  registration.  *  * \returns  0 on success, otherwise an errno.  */
end_comment

begin_function_decl
name|int
name|xen_intr_bind_virq
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_int
name|virq
parameter_list|,
name|u_int
name|cpu
parameter_list|,
name|driver_filter_t
name|filter
parameter_list|,
name|driver_intr_t
name|handler
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|enum
name|intr_type
name|irqflags
parameter_list|,
name|xen_intr_handle_t
modifier|*
name|handlep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Allocate a local event channel port for servicing interprocessor  * interupts and, if successful, associate the port with the specified  * interrupt handler.  *  * \param cpu       The cpu receiving the IPI.  * \param filter    The interrupt filter servicing this IPI.  * \param irqflags  Interrupt handler flags.  See sys/bus.h.  * \param handlep   Pointer to an opaque handle used to manage this  *                  registration.  *  * \returns  0 on success, otherwise an errno.  */
end_comment

begin_function_decl
name|int
name|xen_intr_alloc_and_bind_ipi
parameter_list|(
name|u_int
name|cpu
parameter_list|,
name|driver_filter_t
name|filter
parameter_list|,
name|enum
name|intr_type
name|irqflags
parameter_list|,
name|xen_intr_handle_t
modifier|*
name|handlep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Register a physical interrupt vector and setup the interrupt source.  *  * \param vector        The global vector to use.  * \param trig          Default trigger method.  * \param pol           Default polarity of the interrupt.  *  * \returns  0 on success, otherwise an errno.  */
end_comment

begin_function_decl
name|int
name|xen_register_pirq
parameter_list|(
name|int
name|vector
parameter_list|,
name|enum
name|intr_trigger
name|trig
parameter_list|,
name|enum
name|intr_polarity
name|pol
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Unbind an interrupt handler from its interrupt source.  *  * \param handlep  A pointer to the opaque handle that was initialized  *		   at the time the interrupt source was bound.  *  * \returns  0 on success, otherwise an errno.  *  * \note  The event channel, if any, that was allocated at bind time is  *        closed upon successful return of this method.  *  * \note  It is always safe to call xen_intr_unbind() on a handle that  *        has been initilized to NULL.  */
end_comment

begin_function_decl
name|void
name|xen_intr_unbind
parameter_list|(
name|xen_intr_handle_t
modifier|*
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Add a description to an interrupt handler.  *  * \param handle  The opaque handle that was initialized at the time  *		  the interrupt source was bound.  *  * \param fmt     The sprintf compatible format string for the description,  *                followed by optional sprintf arguments.  *  * \returns  0 on success, otherwise an errno.  */
end_comment

begin_function_decl
name|int
name|xen_intr_describe
parameter_list|(
name|xen_intr_handle_t
name|port_handle
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**  * Signal the remote peer of an interrupt source associated with an  * event channel port.  *  * \param handle  The opaque handle that was initialized at the time  *                the interrupt source was bound.  *  * \note  For xen interrupt sources other than event channel ports,  *        this method takes no action.  */
end_comment

begin_function_decl
name|void
name|xen_intr_signal
parameter_list|(
name|xen_intr_handle_t
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get the local event channel port number associated with this interrupt  * source.  *  * \param handle  The opaque handle that was initialized at the time  *                the interrupt source was bound.  *  * \returns  0 if the handle is invalid, otherwise positive port number.  */
end_comment

begin_function_decl
name|evtchn_port_t
name|xen_intr_port
parameter_list|(
name|xen_intr_handle_t
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Setup MSI vector interrupt(s).  *  * \param dev     The device that requests the binding.  *  * \param vector  Requested initial vector to bind the MSI interrupt(s) to.  *  * \param count   Number of vectors to allocate.  *  * \returns  0 on success, otherwise an errno.  */
end_comment

begin_function_decl
name|int
name|xen_register_msi
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|vector
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Teardown a MSI vector interrupt.  *  * \param vector  Requested vector to release.  *  * \returns  0 on success, otherwise an errno.  */
end_comment

begin_function_decl
name|int
name|xen_release_msi
parameter_list|(
name|int
name|vector
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Bind an event channel port with a handler  *  * \param dev       The device making this bind request.  * \param filter    An interrupt filter handler.  Specify NULL  *                  to always dispatch to the ithread handler.  * \param handler   An interrupt ithread handler.  Optional (can  *                  specify NULL) if all necessary event actions  *                  are performed by filter.  * \param arg       Argument to present to both filter and handler.  * \param irqflags  Interrupt handler flags.  See sys/bus.h.  * \param handle    Opaque handle used to manage this registration.  *  * \returns  0 on success, otherwise an errno.  */
end_comment

begin_function_decl
name|int
name|xen_intr_add_handler
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|driver_filter_t
name|filter
parameter_list|,
name|driver_intr_t
name|handler
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|enum
name|intr_type
name|flags
parameter_list|,
name|xen_intr_handle_t
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XEN_INTR_H_ */
end_comment

end_unit

