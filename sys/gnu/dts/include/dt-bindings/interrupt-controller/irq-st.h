begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  include/linux/irqchip/irq-st.h  *  *  Copyright (C) 2014 STMicroelectronics â All Rights Reserved  *  *  Author: Lee Jones<lee.jones@linaro.org>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_INTERRUPT_CONTROLLER_ST_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_INTERRUPT_CONTROLLER_ST_H
end_define

begin_define
define|#
directive|define
name|ST_IRQ_SYSCFG_EXT_0
value|0
end_define

begin_define
define|#
directive|define
name|ST_IRQ_SYSCFG_EXT_1
value|1
end_define

begin_define
define|#
directive|define
name|ST_IRQ_SYSCFG_EXT_2
value|2
end_define

begin_define
define|#
directive|define
name|ST_IRQ_SYSCFG_CTI_0
value|3
end_define

begin_define
define|#
directive|define
name|ST_IRQ_SYSCFG_CTI_1
value|4
end_define

begin_define
define|#
directive|define
name|ST_IRQ_SYSCFG_PMU_0
value|5
end_define

begin_define
define|#
directive|define
name|ST_IRQ_SYSCFG_PMU_1
value|6
end_define

begin_define
define|#
directive|define
name|ST_IRQ_SYSCFG_pl310_L2
value|7
end_define

begin_define
define|#
directive|define
name|ST_IRQ_SYSCFG_DISABLED
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|ST_IRQ_SYSCFG_EXT_1_INV
value|0x1
end_define

begin_define
define|#
directive|define
name|ST_IRQ_SYSCFG_EXT_2_INV
value|0x2
end_define

begin_define
define|#
directive|define
name|ST_IRQ_SYSCFG_EXT_3_INV
value|0x4
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

