begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2014 Ulrich Hecht  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_CLOCK_R8A7740_H__
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_CLOCK_R8A7740_H__
end_define

begin_comment
comment|/* CPG */
end_comment

begin_define
define|#
directive|define
name|R8A7740_CLK_SYSTEM
value|0
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_PLLC0
value|1
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_PLLC1
value|2
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_PLLC2
value|3
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_R
value|4
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_USB24S
value|5
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_I
value|6
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_ZG
value|7
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_B
value|8
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_M1
value|9
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_HP
value|10
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_HPP
value|11
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_USBP
value|12
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_S
value|13
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_ZB
value|14
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_M3
value|15
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_CP
value|16
end_define

begin_comment
comment|/* MSTP1 */
end_comment

begin_define
define|#
directive|define
name|R8A7740_CLK_CEU21
value|28
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_CEU20
value|27
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_TMU0
value|25
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_LCDC1
value|17
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_IIC0
value|16
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_TMU1
value|11
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_LCDC0
value|0
end_define

begin_comment
comment|/* MSTP2 */
end_comment

begin_define
define|#
directive|define
name|R8A7740_CLK_SCIFA6
value|30
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_INTCA
value|29
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_SCIFA7
value|22
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_DMAC1
value|18
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_DMAC2
value|17
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_DMAC3
value|16
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_USBDMAC
value|14
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_SCIFA5
value|7
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_SCIFB
value|6
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_SCIFA0
value|4
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_SCIFA1
value|3
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_SCIFA2
value|2
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_SCIFA3
value|1
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_SCIFA4
value|0
end_define

begin_comment
comment|/* MSTP3 */
end_comment

begin_define
define|#
directive|define
name|R8A7740_CLK_CMT1
value|29
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_FSI
value|28
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_IIC1
value|23
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_USBF
value|20
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_SDHI0
value|14
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_SDHI1
value|13
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_MMC
value|12
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_GETHER
value|9
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_TPU0
value|4
end_define

begin_comment
comment|/* MSTP4 */
end_comment

begin_define
define|#
directive|define
name|R8A7740_CLK_USBH
value|16
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_SDHI2
value|15
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_USBFUNC
value|7
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_USBPHY
value|6
end_define

begin_comment
comment|/* SUBCK* */
end_comment

begin_define
define|#
directive|define
name|R8A7740_CLK_SUBCK
value|9
end_define

begin_define
define|#
directive|define
name|R8A7740_CLK_SUBCK2
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DT_BINDINGS_CLOCK_R8A7740_H__ */
end_comment

end_unit

