begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2016 Chen-Yu Tsai<wens@csie.org>  *  * This file is dual-licensed: you can use it either under the terms  * of the GPL or the X11 license, at your option. Note that this dual  * licensing only applies to this file, and not this project as a  * whole.  *  *  a) This file is free software; you can redistribute it and/or  *     modify it under the terms of the GNU General Public License as  *     published by the Free Software Foundation; either version 2 of the  *     License, or (at your option) any later version.  *  *     This file is distributed in the hope that it will be useful,  *     but WITHOUT ANY WARRANTY; without even the implied warranty of  *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  *     GNU General Public License for more details.  *  * Or, alternatively,  *  *  b) Permission is hereby granted, free of charge, to any person  *     obtaining a copy of this software and associated documentation  *     files (the "Software"), to deal in the Software without  *     restriction, including without limitation the rights to use,  *     copy, modify, merge, publish, distribute, sublicense, and/or  *     sell copies of the Software, and to permit persons to whom the  *     Software is furnished to do so, subject to the following  *     conditions:  *  *     The above copyright notice and this permission notice shall be  *     included in all copies or substantial portions of the Software.  *  *     THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  *     EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES  *     OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  *     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT  *     HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,  *     WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  *     FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  *     OTHER DEALINGS IN THE SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_RESET_SUN9I_A80_CCU_H_
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_RESET_SUN9I_A80_CCU_H_
end_define

begin_define
define|#
directive|define
name|RST_BUS_FD
value|0
end_define

begin_define
define|#
directive|define
name|RST_BUS_VE
value|1
end_define

begin_define
define|#
directive|define
name|RST_BUS_GPU_CTRL
value|2
end_define

begin_define
define|#
directive|define
name|RST_BUS_SS
value|3
end_define

begin_define
define|#
directive|define
name|RST_BUS_MMC
value|4
end_define

begin_define
define|#
directive|define
name|RST_BUS_NAND0
value|5
end_define

begin_define
define|#
directive|define
name|RST_BUS_NAND1
value|6
end_define

begin_define
define|#
directive|define
name|RST_BUS_SDRAM
value|7
end_define

begin_define
define|#
directive|define
name|RST_BUS_SATA
value|8
end_define

begin_define
define|#
directive|define
name|RST_BUS_TS
value|9
end_define

begin_define
define|#
directive|define
name|RST_BUS_SPI0
value|10
end_define

begin_define
define|#
directive|define
name|RST_BUS_SPI1
value|11
end_define

begin_define
define|#
directive|define
name|RST_BUS_SPI2
value|12
end_define

begin_define
define|#
directive|define
name|RST_BUS_SPI3
value|13
end_define

begin_define
define|#
directive|define
name|RST_BUS_OTG
value|14
end_define

begin_define
define|#
directive|define
name|RST_BUS_OTG_PHY
value|15
end_define

begin_define
define|#
directive|define
name|RST_BUS_MIPI_HSI
value|16
end_define

begin_define
define|#
directive|define
name|RST_BUS_GMAC
value|17
end_define

begin_define
define|#
directive|define
name|RST_BUS_MSGBOX
value|18
end_define

begin_define
define|#
directive|define
name|RST_BUS_SPINLOCK
value|19
end_define

begin_define
define|#
directive|define
name|RST_BUS_HSTIMER
value|20
end_define

begin_define
define|#
directive|define
name|RST_BUS_DMA
value|21
end_define

begin_define
define|#
directive|define
name|RST_BUS_LCD0
value|22
end_define

begin_define
define|#
directive|define
name|RST_BUS_LCD1
value|23
end_define

begin_define
define|#
directive|define
name|RST_BUS_EDP
value|24
end_define

begin_define
define|#
directive|define
name|RST_BUS_LVDS
value|25
end_define

begin_define
define|#
directive|define
name|RST_BUS_CSI
value|26
end_define

begin_define
define|#
directive|define
name|RST_BUS_HDMI0
value|27
end_define

begin_define
define|#
directive|define
name|RST_BUS_HDMI1
value|28
end_define

begin_define
define|#
directive|define
name|RST_BUS_DE
value|29
end_define

begin_define
define|#
directive|define
name|RST_BUS_MP
value|30
end_define

begin_define
define|#
directive|define
name|RST_BUS_GPU
value|31
end_define

begin_define
define|#
directive|define
name|RST_BUS_MIPI_DSI
value|32
end_define

begin_define
define|#
directive|define
name|RST_BUS_SPDIF
value|33
end_define

begin_define
define|#
directive|define
name|RST_BUS_AC97
value|34
end_define

begin_define
define|#
directive|define
name|RST_BUS_I2S0
value|35
end_define

begin_define
define|#
directive|define
name|RST_BUS_I2S1
value|36
end_define

begin_define
define|#
directive|define
name|RST_BUS_LRADC
value|37
end_define

begin_define
define|#
directive|define
name|RST_BUS_GPADC
value|38
end_define

begin_define
define|#
directive|define
name|RST_BUS_CIR_TX
value|39
end_define

begin_define
define|#
directive|define
name|RST_BUS_I2C0
value|40
end_define

begin_define
define|#
directive|define
name|RST_BUS_I2C1
value|41
end_define

begin_define
define|#
directive|define
name|RST_BUS_I2C2
value|42
end_define

begin_define
define|#
directive|define
name|RST_BUS_I2C3
value|43
end_define

begin_define
define|#
directive|define
name|RST_BUS_I2C4
value|44
end_define

begin_define
define|#
directive|define
name|RST_BUS_UART0
value|45
end_define

begin_define
define|#
directive|define
name|RST_BUS_UART1
value|46
end_define

begin_define
define|#
directive|define
name|RST_BUS_UART2
value|47
end_define

begin_define
define|#
directive|define
name|RST_BUS_UART3
value|48
end_define

begin_define
define|#
directive|define
name|RST_BUS_UART4
value|49
end_define

begin_define
define|#
directive|define
name|RST_BUS_UART5
value|50
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_RESET_SUN9I_A80_CCU_H_ */
end_comment

end_unit

