begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2014 Ulrich Hecht  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_CLOCK_SH73A0_H__
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_CLOCK_SH73A0_H__
end_define

begin_comment
comment|/* CPG */
end_comment

begin_define
define|#
directive|define
name|SH73A0_CLK_MAIN
value|0
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_PLL0
value|1
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_PLL1
value|2
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_PLL2
value|3
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_PLL3
value|4
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_DSI0PHY
value|5
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_DSI1PHY
value|6
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_ZG
value|7
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_M3
value|8
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_B
value|9
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_M1
value|10
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_M2
value|11
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_Z
value|12
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_ZX
value|13
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_HP
value|14
end_define

begin_comment
comment|/* MSTP0 */
end_comment

begin_define
define|#
directive|define
name|SH73A0_CLK_IIC2
value|1
end_define

begin_comment
comment|/* MSTP1 */
end_comment

begin_define
define|#
directive|define
name|SH73A0_CLK_CEU1
value|29
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_CSI2_RX1
value|28
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_CEU0
value|27
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_CSI2_RX0
value|26
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_TMU0
value|25
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_DSITX0
value|18
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_IIC0
value|16
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_SGX
value|12
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_LCDC0
value|0
end_define

begin_comment
comment|/* MSTP2 */
end_comment

begin_define
define|#
directive|define
name|SH73A0_CLK_SCIFA7
value|19
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_SY_DMAC
value|18
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_MP_DMAC
value|17
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_SCIFA5
value|7
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_SCIFB
value|6
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_SCIFA0
value|4
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_SCIFA1
value|3
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_SCIFA2
value|2
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_SCIFA3
value|1
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_SCIFA4
value|0
end_define

begin_comment
comment|/* MSTP3 */
end_comment

begin_define
define|#
directive|define
name|SH73A0_CLK_SCIFA6
value|31
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_CMT1
value|29
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_FSI
value|28
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_IRDA
value|25
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_IIC1
value|23
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_USB
value|22
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_FLCTL
value|15
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_SDHI0
value|14
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_SDHI1
value|13
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_MMCIF0
value|12
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_SDHI2
value|11
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_TPU0
value|4
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_TPU1
value|3
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_TPU2
value|2
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_TPU3
value|1
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_TPU4
value|0
end_define

begin_comment
comment|/* MSTP4 */
end_comment

begin_define
define|#
directive|define
name|SH73A0_CLK_IIC3
value|11
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_IIC4
value|10
end_define

begin_define
define|#
directive|define
name|SH73A0_CLK_KEYSC
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

