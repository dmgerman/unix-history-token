begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2016 Cogent Embedded, Inc.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_CLOCK_R8A7792_H__
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_CLOCK_R8A7792_H__
end_define

begin_comment
comment|/* CPG */
end_comment

begin_define
define|#
directive|define
name|R8A7792_CLK_MAIN
value|0
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_PLL0
value|1
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_PLL1
value|2
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_PLL3
value|3
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_LB
value|4
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_QSPI
value|5
end_define

begin_comment
comment|/* MSTP0 */
end_comment

begin_define
define|#
directive|define
name|R8A7792_CLK_MSIOF0
value|0
end_define

begin_comment
comment|/* MSTP1 */
end_comment

begin_define
define|#
directive|define
name|R8A7792_CLK_JPU
value|6
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_TMU1
value|11
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_TMU3
value|21
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_TMU2
value|22
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_CMT0
value|24
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_TMU0
value|25
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_VSP1DU1
value|27
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_VSP1DU0
value|28
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_VSP1_SY
value|31
end_define

begin_comment
comment|/* MSTP2 */
end_comment

begin_define
define|#
directive|define
name|R8A7792_CLK_MSIOF1
value|8
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_SYS_DMAC1
value|18
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_SYS_DMAC0
value|19
end_define

begin_comment
comment|/* MSTP3 */
end_comment

begin_define
define|#
directive|define
name|R8A7792_CLK_TPU0
value|4
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_SDHI0
value|14
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_CMT1
value|29
end_define

begin_comment
comment|/* MSTP4 */
end_comment

begin_define
define|#
directive|define
name|R8A7792_CLK_IRQC
value|7
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_INTC_SYS
value|8
end_define

begin_comment
comment|/* MSTP5 */
end_comment

begin_define
define|#
directive|define
name|R8A7792_CLK_AUDIO_DMAC0
value|2
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_THERMAL
value|22
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_PWM
value|23
end_define

begin_comment
comment|/* MSTP7 */
end_comment

begin_define
define|#
directive|define
name|R8A7792_CLK_HSCIF1
value|16
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_HSCIF0
value|17
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_SCIF3
value|18
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_SCIF2
value|19
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_SCIF1
value|20
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_SCIF0
value|21
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_DU1
value|23
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_DU0
value|24
end_define

begin_comment
comment|/* MSTP8 */
end_comment

begin_define
define|#
directive|define
name|R8A7792_CLK_VIN5
value|4
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_VIN4
value|5
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_VIN3
value|8
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_VIN2
value|9
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_VIN1
value|10
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_VIN0
value|11
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_ETHERAVB
value|12
end_define

begin_comment
comment|/* MSTP9 */
end_comment

begin_define
define|#
directive|define
name|R8A7792_CLK_GPIO7
value|4
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_GPIO6
value|5
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_GPIO5
value|7
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_GPIO4
value|8
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_GPIO3
value|9
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_GPIO2
value|10
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_GPIO1
value|11
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_GPIO0
value|12
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_GPIO11
value|13
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_GPIO10
value|14
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_CAN1
value|15
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_CAN0
value|16
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_QSPI_MOD
value|17
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_GPIO9
value|19
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_GPIO8
value|21
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_I2C5
value|25
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_IICDVFS
value|26
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_I2C4
value|27
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_I2C3
value|28
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_I2C2
value|29
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_I2C1
value|30
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_I2C0
value|31
end_define

begin_comment
comment|/* MSTP10 */
end_comment

begin_define
define|#
directive|define
name|R8A7792_CLK_SSI_ALL
value|5
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_SSI4
value|11
end_define

begin_define
define|#
directive|define
name|R8A7792_CLK_SSI3
value|12
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DT_BINDINGS_CLOCK_R8A7792_H__ */
end_comment

end_unit

