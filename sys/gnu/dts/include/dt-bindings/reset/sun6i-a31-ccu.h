begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2016 Chen-Yu Tsai<wens@csie.org>  *  * This file is dual-licensed: you can use it either under the terms  * of the GPL or the X11 license, at your option. Note that this dual  * licensing only applies to this file, and not this project as a  * whole.  *  *  a) This file is free software; you can redistribute it and/or  *     modify it under the terms of the GNU General Public License as  *     published by the Free Software Foundation; either version 2 of the  *     License, or (at your option) any later version.  *  *     This file is distributed in the hope that it will be useful,  *     but WITHOUT ANY WARRANTY; without even the implied warranty of  *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  *     GNU General Public License for more details.  *  * Or, alternatively,  *  *  b) Permission is hereby granted, free of charge, to any person  *     obtaining a copy of this software and associated documentation  *     files (the "Software"), to deal in the Software without  *     restriction, including without limitation the rights to use,  *     copy, modify, merge, publish, distribute, sublicense, and/or  *     sell copies of the Software, and to permit persons to whom the  *     Software is furnished to do so, subject to the following  *     conditions:  *  *     The above copyright notice and this permission notice shall be  *     included in all copies or substantial portions of the Software.  *  *     THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  *     EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES  *     OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  *     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT  *     HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,  *     WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  *     FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  *     OTHER DEALINGS IN THE SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_RST_SUN6I_A31_H_
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_RST_SUN6I_A31_H_
end_define

begin_define
define|#
directive|define
name|RST_USB_PHY0
value|0
end_define

begin_define
define|#
directive|define
name|RST_USB_PHY1
value|1
end_define

begin_define
define|#
directive|define
name|RST_USB_PHY2
value|2
end_define

begin_define
define|#
directive|define
name|RST_AHB1_MIPI_DSI
value|3
end_define

begin_define
define|#
directive|define
name|RST_AHB1_SS
value|4
end_define

begin_define
define|#
directive|define
name|RST_AHB1_DMA
value|5
end_define

begin_define
define|#
directive|define
name|RST_AHB1_MMC0
value|6
end_define

begin_define
define|#
directive|define
name|RST_AHB1_MMC1
value|7
end_define

begin_define
define|#
directive|define
name|RST_AHB1_MMC2
value|8
end_define

begin_define
define|#
directive|define
name|RST_AHB1_MMC3
value|9
end_define

begin_define
define|#
directive|define
name|RST_AHB1_NAND1
value|10
end_define

begin_define
define|#
directive|define
name|RST_AHB1_NAND0
value|11
end_define

begin_define
define|#
directive|define
name|RST_AHB1_SDRAM
value|12
end_define

begin_define
define|#
directive|define
name|RST_AHB1_EMAC
value|13
end_define

begin_define
define|#
directive|define
name|RST_AHB1_TS
value|14
end_define

begin_define
define|#
directive|define
name|RST_AHB1_HSTIMER
value|15
end_define

begin_define
define|#
directive|define
name|RST_AHB1_SPI0
value|16
end_define

begin_define
define|#
directive|define
name|RST_AHB1_SPI1
value|17
end_define

begin_define
define|#
directive|define
name|RST_AHB1_SPI2
value|18
end_define

begin_define
define|#
directive|define
name|RST_AHB1_SPI3
value|19
end_define

begin_define
define|#
directive|define
name|RST_AHB1_OTG
value|20
end_define

begin_define
define|#
directive|define
name|RST_AHB1_EHCI0
value|21
end_define

begin_define
define|#
directive|define
name|RST_AHB1_EHCI1
value|22
end_define

begin_define
define|#
directive|define
name|RST_AHB1_OHCI0
value|23
end_define

begin_define
define|#
directive|define
name|RST_AHB1_OHCI1
value|24
end_define

begin_define
define|#
directive|define
name|RST_AHB1_OHCI2
value|25
end_define

begin_define
define|#
directive|define
name|RST_AHB1_VE
value|26
end_define

begin_define
define|#
directive|define
name|RST_AHB1_LCD0
value|27
end_define

begin_define
define|#
directive|define
name|RST_AHB1_LCD1
value|28
end_define

begin_define
define|#
directive|define
name|RST_AHB1_CSI
value|29
end_define

begin_define
define|#
directive|define
name|RST_AHB1_HDMI
value|30
end_define

begin_define
define|#
directive|define
name|RST_AHB1_BE0
value|31
end_define

begin_define
define|#
directive|define
name|RST_AHB1_BE1
value|32
end_define

begin_define
define|#
directive|define
name|RST_AHB1_FE0
value|33
end_define

begin_define
define|#
directive|define
name|RST_AHB1_FE1
value|34
end_define

begin_define
define|#
directive|define
name|RST_AHB1_MP
value|35
end_define

begin_define
define|#
directive|define
name|RST_AHB1_GPU
value|36
end_define

begin_define
define|#
directive|define
name|RST_AHB1_DEU0
value|37
end_define

begin_define
define|#
directive|define
name|RST_AHB1_DEU1
value|38
end_define

begin_define
define|#
directive|define
name|RST_AHB1_DRC0
value|39
end_define

begin_define
define|#
directive|define
name|RST_AHB1_DRC1
value|40
end_define

begin_define
define|#
directive|define
name|RST_AHB1_LVDS
value|41
end_define

begin_define
define|#
directive|define
name|RST_APB1_CODEC
value|42
end_define

begin_define
define|#
directive|define
name|RST_APB1_SPDIF
value|43
end_define

begin_define
define|#
directive|define
name|RST_APB1_DIGITAL_MIC
value|44
end_define

begin_define
define|#
directive|define
name|RST_APB1_DAUDIO0
value|45
end_define

begin_define
define|#
directive|define
name|RST_APB1_DAUDIO1
value|46
end_define

begin_define
define|#
directive|define
name|RST_APB2_I2C0
value|47
end_define

begin_define
define|#
directive|define
name|RST_APB2_I2C1
value|48
end_define

begin_define
define|#
directive|define
name|RST_APB2_I2C2
value|49
end_define

begin_define
define|#
directive|define
name|RST_APB2_I2C3
value|50
end_define

begin_define
define|#
directive|define
name|RST_APB2_UART0
value|51
end_define

begin_define
define|#
directive|define
name|RST_APB2_UART1
value|52
end_define

begin_define
define|#
directive|define
name|RST_APB2_UART2
value|53
end_define

begin_define
define|#
directive|define
name|RST_APB2_UART3
value|54
end_define

begin_define
define|#
directive|define
name|RST_APB2_UART4
value|55
end_define

begin_define
define|#
directive|define
name|RST_APB2_UART5
value|56
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_RST_SUN6I_A31_H_ */
end_comment

end_unit

