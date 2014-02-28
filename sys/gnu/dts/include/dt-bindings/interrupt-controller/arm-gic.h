begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides constants for the ARM GIC.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_INTERRUPT_CONTROLLER_ARM_GIC_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_INTERRUPT_CONTROLLER_ARM_GIC_H
end_define

begin_include
include|#
directive|include
file|<dt-bindings/interrupt-controller/irq.h>
end_include

begin_comment
comment|/* interrupt specific cell 0 */
end_comment

begin_define
define|#
directive|define
name|GIC_SPI
value|0
end_define

begin_define
define|#
directive|define
name|GIC_PPI
value|1
end_define

begin_comment
comment|/*  * Interrupt specifier cell 2.  * The flaggs in irq.h are valid, plus those below.  */
end_comment

begin_define
define|#
directive|define
name|GIC_CPU_MASK_RAW
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|GIC_CPU_MASK_SIMPLE
parameter_list|(
name|num
parameter_list|)
value|GIC_CPU_MASK_RAW((1<< (num)) - 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

