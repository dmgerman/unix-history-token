begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2017 Icenowy Zheng<icenowy@aosc.io>  *  * This file is dual-licensed: you can use it either under the terms  * of the GPL or the X11 license, at your option. Note that this dual  * licensing only applies to this file, and not this project as a  * whole.  *  *  a) This file is free software; you can redistribute it and/or  *     modify it under the terms of the GNU General Public License as  *     published by the Free Software Foundation; either version 2 of the  *     License, or (at your option) any later version.  *  *     This file is distributed in the hope that it will be useful,  *     but WITHOUT ANY WARRANTY; without even the implied warranty of  *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  *     GNU General Public License for more details.  *  * Or, alternatively,  *  *  b) Permission is hereby granted, free of charge, to any person  *     obtaining a copy of this software and associated documentation  *     files (the "Software"), to deal in the Software without  *     restriction, including without limitation the rights to use,  *     copy, modify, merge, publish, distribute, sublicense, and/or  *     sell copies of the Software, and to permit persons to whom the  *     Software is furnished to do so, subject to the following  *     conditions:  *  *     The above copyright notice and this permission notice shall be  *     included in all copies or substantial portions of the Software.  *  *     THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  *     EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES  *     OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  *     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT  *     HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,  *     WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  *     FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  *     OTHER DEALINGS IN THE SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_RST_SUN8I_R40_H_
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_RST_SUN8I_R40_H_
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
name|RST_DRAM
value|3
end_define

begin_define
define|#
directive|define
name|RST_MBUS
value|4
end_define

begin_define
define|#
directive|define
name|RST_BUS_MIPI_DSI
value|5
end_define

begin_define
define|#
directive|define
name|RST_BUS_CE
value|6
end_define

begin_define
define|#
directive|define
name|RST_BUS_DMA
value|7
end_define

begin_define
define|#
directive|define
name|RST_BUS_MMC0
value|8
end_define

begin_define
define|#
directive|define
name|RST_BUS_MMC1
value|9
end_define

begin_define
define|#
directive|define
name|RST_BUS_MMC2
value|10
end_define

begin_define
define|#
directive|define
name|RST_BUS_MMC3
value|11
end_define

begin_define
define|#
directive|define
name|RST_BUS_NAND
value|12
end_define

begin_define
define|#
directive|define
name|RST_BUS_DRAM
value|13
end_define

begin_define
define|#
directive|define
name|RST_BUS_EMAC
value|14
end_define

begin_define
define|#
directive|define
name|RST_BUS_TS
value|15
end_define

begin_define
define|#
directive|define
name|RST_BUS_HSTIMER
value|16
end_define

begin_define
define|#
directive|define
name|RST_BUS_SPI0
value|17
end_define

begin_define
define|#
directive|define
name|RST_BUS_SPI1
value|18
end_define

begin_define
define|#
directive|define
name|RST_BUS_SPI2
value|19
end_define

begin_define
define|#
directive|define
name|RST_BUS_SPI3
value|20
end_define

begin_define
define|#
directive|define
name|RST_BUS_SATA
value|21
end_define

begin_define
define|#
directive|define
name|RST_BUS_OTG
value|22
end_define

begin_define
define|#
directive|define
name|RST_BUS_EHCI0
value|23
end_define

begin_define
define|#
directive|define
name|RST_BUS_EHCI1
value|24
end_define

begin_define
define|#
directive|define
name|RST_BUS_EHCI2
value|25
end_define

begin_define
define|#
directive|define
name|RST_BUS_OHCI0
value|26
end_define

begin_define
define|#
directive|define
name|RST_BUS_OHCI1
value|27
end_define

begin_define
define|#
directive|define
name|RST_BUS_OHCI2
value|28
end_define

begin_define
define|#
directive|define
name|RST_BUS_VE
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
name|RST_BUS_DEINTERLACE
value|31
end_define

begin_define
define|#
directive|define
name|RST_BUS_CSI0
value|32
end_define

begin_define
define|#
directive|define
name|RST_BUS_CSI1
value|33
end_define

begin_define
define|#
directive|define
name|RST_BUS_HDMI0
value|34
end_define

begin_define
define|#
directive|define
name|RST_BUS_HDMI1
value|35
end_define

begin_define
define|#
directive|define
name|RST_BUS_DE
value|36
end_define

begin_define
define|#
directive|define
name|RST_BUS_TVE0
value|37
end_define

begin_define
define|#
directive|define
name|RST_BUS_TVE1
value|38
end_define

begin_define
define|#
directive|define
name|RST_BUS_TVE_TOP
value|39
end_define

begin_define
define|#
directive|define
name|RST_BUS_GMAC
value|40
end_define

begin_define
define|#
directive|define
name|RST_BUS_GPU
value|41
end_define

begin_define
define|#
directive|define
name|RST_BUS_TVD0
value|42
end_define

begin_define
define|#
directive|define
name|RST_BUS_TVD1
value|43
end_define

begin_define
define|#
directive|define
name|RST_BUS_TVD2
value|44
end_define

begin_define
define|#
directive|define
name|RST_BUS_TVD3
value|45
end_define

begin_define
define|#
directive|define
name|RST_BUS_TVD_TOP
value|46
end_define

begin_define
define|#
directive|define
name|RST_BUS_TCON_LCD0
value|47
end_define

begin_define
define|#
directive|define
name|RST_BUS_TCON_LCD1
value|48
end_define

begin_define
define|#
directive|define
name|RST_BUS_TCON_TV0
value|49
end_define

begin_define
define|#
directive|define
name|RST_BUS_TCON_TV1
value|50
end_define

begin_define
define|#
directive|define
name|RST_BUS_TCON_TOP
value|51
end_define

begin_define
define|#
directive|define
name|RST_BUS_DBG
value|52
end_define

begin_define
define|#
directive|define
name|RST_BUS_LVDS
value|53
end_define

begin_define
define|#
directive|define
name|RST_BUS_CODEC
value|54
end_define

begin_define
define|#
directive|define
name|RST_BUS_SPDIF
value|55
end_define

begin_define
define|#
directive|define
name|RST_BUS_AC97
value|56
end_define

begin_define
define|#
directive|define
name|RST_BUS_IR0
value|57
end_define

begin_define
define|#
directive|define
name|RST_BUS_IR1
value|58
end_define

begin_define
define|#
directive|define
name|RST_BUS_THS
value|59
end_define

begin_define
define|#
directive|define
name|RST_BUS_KEYPAD
value|60
end_define

begin_define
define|#
directive|define
name|RST_BUS_I2S0
value|61
end_define

begin_define
define|#
directive|define
name|RST_BUS_I2S1
value|62
end_define

begin_define
define|#
directive|define
name|RST_BUS_I2S2
value|63
end_define

begin_define
define|#
directive|define
name|RST_BUS_I2C0
value|64
end_define

begin_define
define|#
directive|define
name|RST_BUS_I2C1
value|65
end_define

begin_define
define|#
directive|define
name|RST_BUS_I2C2
value|66
end_define

begin_define
define|#
directive|define
name|RST_BUS_I2C3
value|67
end_define

begin_define
define|#
directive|define
name|RST_BUS_CAN
value|68
end_define

begin_define
define|#
directive|define
name|RST_BUS_SCR
value|69
end_define

begin_define
define|#
directive|define
name|RST_BUS_PS20
value|70
end_define

begin_define
define|#
directive|define
name|RST_BUS_PS21
value|71
end_define

begin_define
define|#
directive|define
name|RST_BUS_I2C4
value|72
end_define

begin_define
define|#
directive|define
name|RST_BUS_UART0
value|73
end_define

begin_define
define|#
directive|define
name|RST_BUS_UART1
value|74
end_define

begin_define
define|#
directive|define
name|RST_BUS_UART2
value|75
end_define

begin_define
define|#
directive|define
name|RST_BUS_UART3
value|76
end_define

begin_define
define|#
directive|define
name|RST_BUS_UART4
value|77
end_define

begin_define
define|#
directive|define
name|RST_BUS_UART5
value|78
end_define

begin_define
define|#
directive|define
name|RST_BUS_UART6
value|79
end_define

begin_define
define|#
directive|define
name|RST_BUS_UART7
value|80
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_RST_SUN8I_R40_H_ */
end_comment

end_unit

