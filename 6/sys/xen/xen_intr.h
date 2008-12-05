begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* -*-  Mode:C; c-basic-offset:4; tab-width:4 -*- */
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

begin_comment
comment|/* * The flat IRQ space is divided into two regions: *  1. A one-to-one mapping of real physical IRQs. This space is only used *     if we have physical device-access privilege. This region is at the  *     start of the IRQ space so that existing device drivers do not need *     to be modified to translate physical IRQ numbers into our IRQ space. *  3. A dynamic mapping of inter-domain and Xen-sourced virtual IRQs. These *     are bound using the provided bind/unbind functions. */
end_comment

begin_define
define|#
directive|define
name|PIRQ_BASE
value|0
end_define

begin_define
define|#
directive|define
name|NR_PIRQS
value|128
end_define

begin_define
define|#
directive|define
name|DYNIRQ_BASE
value|(PIRQ_BASE + NR_PIRQS)
end_define

begin_define
define|#
directive|define
name|NR_DYNIRQS
value|128
end_define

begin_define
define|#
directive|define
name|NR_IRQS
value|(NR_PIRQS + NR_DYNIRQS)
end_define

begin_define
define|#
directive|define
name|pirq_to_irq
parameter_list|(
name|_x
parameter_list|)
value|((_x) + PIRQ_BASE)
end_define

begin_define
define|#
directive|define
name|irq_to_pirq
parameter_list|(
name|_x
parameter_list|)
value|((_x) - PIRQ_BASE)
end_define

begin_define
define|#
directive|define
name|dynirq_to_irq
parameter_list|(
name|_x
parameter_list|)
value|((_x) + DYNIRQ_BASE)
end_define

begin_define
define|#
directive|define
name|irq_to_dynirq
parameter_list|(
name|_x
parameter_list|)
value|((_x) - DYNIRQ_BASE)
end_define

begin_comment
comment|/*  * Dynamic binding of event channels and VIRQ sources to guest IRQ space.  */
end_comment

begin_comment
comment|/*  * Bind a caller port event channel to an interrupt handler. If  * successful, the guest IRQ number is returned in *irqp. Return zero  * on success or errno otherwise.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|bind_caller_port_to_irqhandler
parameter_list|(
name|unsigned
name|int
name|caller_port
parameter_list|,
specifier|const
name|char
modifier|*
name|devname
parameter_list|,
name|driver_intr_t
name|handler
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|unsigned
name|long
name|irqflags
parameter_list|,
name|unsigned
name|int
modifier|*
name|irqp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Bind a listening port to an interrupt handler. If successful, the  * guest IRQ number is returned in *irqp. Return zero on success or  * errno otherwise.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|bind_listening_port_to_irqhandler
parameter_list|(
name|unsigned
name|int
name|remote_domain
parameter_list|,
specifier|const
name|char
modifier|*
name|devname
parameter_list|,
name|driver_intr_t
name|handler
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|unsigned
name|long
name|irqflags
parameter_list|,
name|unsigned
name|int
modifier|*
name|irqp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Bind a VIRQ to an interrupt handler. If successful, the guest IRQ  * number is returned in *irqp. Return zero on success or errno  * otherwise.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|bind_virq_to_irqhandler
parameter_list|(
name|unsigned
name|int
name|virq
parameter_list|,
name|unsigned
name|int
name|cpu
parameter_list|,
specifier|const
name|char
modifier|*
name|devname
parameter_list|,
name|driver_intr_t
name|handler
parameter_list|,
name|unsigned
name|long
name|irqflags
parameter_list|,
name|unsigned
name|int
modifier|*
name|irqp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Bind an IPI to an interrupt handler. If successful, the guest  * IRQ number is returned in *irqp. Return zero on success or errno  * otherwise.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|bind_ipi_to_irqhandler
parameter_list|(
name|unsigned
name|int
name|ipi
parameter_list|,
name|unsigned
name|int
name|cpu
parameter_list|,
specifier|const
name|char
modifier|*
name|devname
parameter_list|,
name|driver_intr_t
name|handler
parameter_list|,
name|unsigned
name|long
name|irqflags
parameter_list|,
name|unsigned
name|int
modifier|*
name|irqp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Bind an interdomain event channel to an interrupt handler. If  * successful, the guest IRQ number is returned in *irqp. Return zero  * on success or errno otherwise.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|bind_interdomain_evtchn_to_irqhandler
parameter_list|(
name|unsigned
name|int
name|remote_domain
parameter_list|,
name|unsigned
name|int
name|remote_port
parameter_list|,
specifier|const
name|char
modifier|*
name|devname
parameter_list|,
name|driver_intr_t
name|handler
parameter_list|,
name|unsigned
name|long
name|irqflags
parameter_list|,
name|unsigned
name|int
modifier|*
name|irqp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Unbind an interrupt handler using the guest IRQ number returned  * when it was bound.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|unbind_from_irqhandler
parameter_list|(
name|unsigned
name|int
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline__
name|int
name|irq_cannonicalize
parameter_list|(
name|unsigned
name|int
name|irq
parameter_list|)
block|{
return|return
operator|(
name|irq
operator|==
literal|2
operator|)
condition|?
literal|9
else|:
name|irq
return|;
block|}
end_function

begin_function_decl
specifier|extern
name|void
name|disable_irq
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|disable_irq_nosync
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|enable_irq
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|irq_suspend
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|irq_resume
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|idle_block
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ap_cpu_initclocks
parameter_list|(
name|int
name|cpu
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

