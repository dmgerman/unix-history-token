begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2016 Maxime Ripard<maxime.ripard@free-electrons.com>  *  * This file is dual-licensed: you can use it either under the terms  * of the GPL or the X11 license, at your option. Note that this dual  * licensing only applies to this file, and not this project as a  * whole.  *  *  a) This file is free software; you can redistribute it and/or  *     modify it under the terms of the GNU General Public License as  *     published by the Free Software Foundation; either version 2 of the  *     License, or (at your option) any later version.  *  *     This file is distributed in the hope that it will be useful,  *     but WITHOUT ANY WARRANTY; without even the implied warranty of  *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  *     GNU General Public License for more details.  *  * Or, alternatively,  *  *  b) Permission is hereby granted, free of charge, to any person  *     obtaining a copy of this software and associated documentation  *     files (the "Software"), to deal in the Software without  *     restriction, including without limitation the rights to use,  *     copy, modify, merge, publish, distribute, sublicense, and/or  *     sell copies of the Software, and to permit persons to whom the  *     Software is furnished to do so, subject to the following  *     conditions:  *  *     The above copyright notice and this permission notice shall be  *     included in all copies or substantial portions of the Software.  *  *     THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  *     EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES  *     OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  *     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT  *     HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,  *     WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  *     FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  *     OTHER DEALINGS IN THE SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLK_SUN50I_A64_H_
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLK_SUN50I_A64_H_
end_define

begin_define
define|#
directive|define
name|CLK_PLL_PERIPH0
value|11
end_define

begin_define
define|#
directive|define
name|CLK_BUS_MIPI_DSI
value|28
end_define

begin_define
define|#
directive|define
name|CLK_BUS_CE
value|29
end_define

begin_define
define|#
directive|define
name|CLK_BUS_DMA
value|30
end_define

begin_define
define|#
directive|define
name|CLK_BUS_MMC0
value|31
end_define

begin_define
define|#
directive|define
name|CLK_BUS_MMC1
value|32
end_define

begin_define
define|#
directive|define
name|CLK_BUS_MMC2
value|33
end_define

begin_define
define|#
directive|define
name|CLK_BUS_NAND
value|34
end_define

begin_define
define|#
directive|define
name|CLK_BUS_DRAM
value|35
end_define

begin_define
define|#
directive|define
name|CLK_BUS_EMAC
value|36
end_define

begin_define
define|#
directive|define
name|CLK_BUS_TS
value|37
end_define

begin_define
define|#
directive|define
name|CLK_BUS_HSTIMER
value|38
end_define

begin_define
define|#
directive|define
name|CLK_BUS_SPI0
value|39
end_define

begin_define
define|#
directive|define
name|CLK_BUS_SPI1
value|40
end_define

begin_define
define|#
directive|define
name|CLK_BUS_OTG
value|41
end_define

begin_define
define|#
directive|define
name|CLK_BUS_EHCI0
value|42
end_define

begin_define
define|#
directive|define
name|CLK_BUS_EHCI1
value|43
end_define

begin_define
define|#
directive|define
name|CLK_BUS_OHCI0
value|44
end_define

begin_define
define|#
directive|define
name|CLK_BUS_OHCI1
value|45
end_define

begin_define
define|#
directive|define
name|CLK_BUS_VE
value|46
end_define

begin_define
define|#
directive|define
name|CLK_BUS_TCON0
value|47
end_define

begin_define
define|#
directive|define
name|CLK_BUS_TCON1
value|48
end_define

begin_define
define|#
directive|define
name|CLK_BUS_DEINTERLACE
value|49
end_define

begin_define
define|#
directive|define
name|CLK_BUS_CSI
value|50
end_define

begin_define
define|#
directive|define
name|CLK_BUS_HDMI
value|51
end_define

begin_define
define|#
directive|define
name|CLK_BUS_DE
value|52
end_define

begin_define
define|#
directive|define
name|CLK_BUS_GPU
value|53
end_define

begin_define
define|#
directive|define
name|CLK_BUS_MSGBOX
value|54
end_define

begin_define
define|#
directive|define
name|CLK_BUS_SPINLOCK
value|55
end_define

begin_define
define|#
directive|define
name|CLK_BUS_CODEC
value|56
end_define

begin_define
define|#
directive|define
name|CLK_BUS_SPDIF
value|57
end_define

begin_define
define|#
directive|define
name|CLK_BUS_PIO
value|58
end_define

begin_define
define|#
directive|define
name|CLK_BUS_THS
value|59
end_define

begin_define
define|#
directive|define
name|CLK_BUS_I2S0
value|60
end_define

begin_define
define|#
directive|define
name|CLK_BUS_I2S1
value|61
end_define

begin_define
define|#
directive|define
name|CLK_BUS_I2S2
value|62
end_define

begin_define
define|#
directive|define
name|CLK_BUS_I2C0
value|63
end_define

begin_define
define|#
directive|define
name|CLK_BUS_I2C1
value|64
end_define

begin_define
define|#
directive|define
name|CLK_BUS_I2C2
value|65
end_define

begin_define
define|#
directive|define
name|CLK_BUS_SCR
value|66
end_define

begin_define
define|#
directive|define
name|CLK_BUS_UART0
value|67
end_define

begin_define
define|#
directive|define
name|CLK_BUS_UART1
value|68
end_define

begin_define
define|#
directive|define
name|CLK_BUS_UART2
value|69
end_define

begin_define
define|#
directive|define
name|CLK_BUS_UART3
value|70
end_define

begin_define
define|#
directive|define
name|CLK_BUS_UART4
value|71
end_define

begin_define
define|#
directive|define
name|CLK_BUS_DBG
value|72
end_define

begin_define
define|#
directive|define
name|CLK_THS
value|73
end_define

begin_define
define|#
directive|define
name|CLK_NAND
value|74
end_define

begin_define
define|#
directive|define
name|CLK_MMC0
value|75
end_define

begin_define
define|#
directive|define
name|CLK_MMC1
value|76
end_define

begin_define
define|#
directive|define
name|CLK_MMC2
value|77
end_define

begin_define
define|#
directive|define
name|CLK_TS
value|78
end_define

begin_define
define|#
directive|define
name|CLK_CE
value|79
end_define

begin_define
define|#
directive|define
name|CLK_SPI0
value|80
end_define

begin_define
define|#
directive|define
name|CLK_SPI1
value|81
end_define

begin_define
define|#
directive|define
name|CLK_I2S0
value|82
end_define

begin_define
define|#
directive|define
name|CLK_I2S1
value|83
end_define

begin_define
define|#
directive|define
name|CLK_I2S2
value|84
end_define

begin_define
define|#
directive|define
name|CLK_SPDIF
value|85
end_define

begin_define
define|#
directive|define
name|CLK_USB_PHY0
value|86
end_define

begin_define
define|#
directive|define
name|CLK_USB_PHY1
value|87
end_define

begin_define
define|#
directive|define
name|CLK_USB_HSIC
value|88
end_define

begin_define
define|#
directive|define
name|CLK_USB_HSIC_12M
value|89
end_define

begin_define
define|#
directive|define
name|CLK_USB_OHCI0
value|91
end_define

begin_define
define|#
directive|define
name|CLK_USB_OHCI1
value|93
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_VE
value|95
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_CSI
value|96
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_DEINTERLACE
value|97
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_TS
value|98
end_define

begin_define
define|#
directive|define
name|CLK_DE
value|99
end_define

begin_define
define|#
directive|define
name|CLK_TCON0
value|100
end_define

begin_define
define|#
directive|define
name|CLK_TCON1
value|101
end_define

begin_define
define|#
directive|define
name|CLK_DEINTERLACE
value|102
end_define

begin_define
define|#
directive|define
name|CLK_CSI_MISC
value|103
end_define

begin_define
define|#
directive|define
name|CLK_CSI_SCLK
value|104
end_define

begin_define
define|#
directive|define
name|CLK_CSI_MCLK
value|105
end_define

begin_define
define|#
directive|define
name|CLK_VE
value|106
end_define

begin_define
define|#
directive|define
name|CLK_AC_DIG
value|107
end_define

begin_define
define|#
directive|define
name|CLK_AC_DIG_4X
value|108
end_define

begin_define
define|#
directive|define
name|CLK_AVS
value|109
end_define

begin_define
define|#
directive|define
name|CLK_HDMI
value|110
end_define

begin_define
define|#
directive|define
name|CLK_HDMI_DDC
value|111
end_define

begin_define
define|#
directive|define
name|CLK_DSI_DPHY
value|113
end_define

begin_define
define|#
directive|define
name|CLK_GPU
value|114
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_CLK_SUN50I_H_ */
end_comment

end_unit

