begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2017 Icenowy Zheng<icenowy@aosc.io>  *  * This file is dual-licensed: you can use it either under the terms  * of the GPL or the X11 license, at your option. Note that this dual  * licensing only applies to this file, and not this project as a  * whole.  *  *  a) This file is free software; you can redistribute it and/or  *     modify it under the terms of the GNU General Public License as  *     published by the Free Software Foundation; either version 2 of the  *     License, or (at your option) any later version.  *  *     This file is distributed in the hope that it will be useful,  *     but WITHOUT ANY WARRANTY; without even the implied warranty of  *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  *     GNU General Public License for more details.  *  * Or, alternatively,  *  *  b) Permission is hereby granted, free of charge, to any person  *     obtaining a copy of this software and associated documentation  *     files (the "Software"), to deal in the Software without  *     restriction, including without limitation the rights to use,  *     copy, modify, merge, publish, distribute, sublicense, and/or  *     sell copies of the Software, and to permit persons to whom the  *     Software is furnished to do so, subject to the following  *     conditions:  *  *     The above copyright notice and this permission notice shall be  *     included in all copies or substantial portions of the Software.  *  *     THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  *     EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES  *     OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  *     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT  *     HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,  *     WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  *     FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  *     OTHER DEALINGS IN THE SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLK_SUN8I_R40_H_
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLK_SUN8I_R40_H_
end_define

begin_define
define|#
directive|define
name|CLK_CPU
value|24
end_define

begin_define
define|#
directive|define
name|CLK_BUS_MIPI_DSI
value|29
end_define

begin_define
define|#
directive|define
name|CLK_BUS_CE
value|30
end_define

begin_define
define|#
directive|define
name|CLK_BUS_DMA
value|31
end_define

begin_define
define|#
directive|define
name|CLK_BUS_MMC0
value|32
end_define

begin_define
define|#
directive|define
name|CLK_BUS_MMC1
value|33
end_define

begin_define
define|#
directive|define
name|CLK_BUS_MMC2
value|34
end_define

begin_define
define|#
directive|define
name|CLK_BUS_MMC3
value|35
end_define

begin_define
define|#
directive|define
name|CLK_BUS_NAND
value|36
end_define

begin_define
define|#
directive|define
name|CLK_BUS_DRAM
value|37
end_define

begin_define
define|#
directive|define
name|CLK_BUS_EMAC
value|38
end_define

begin_define
define|#
directive|define
name|CLK_BUS_TS
value|39
end_define

begin_define
define|#
directive|define
name|CLK_BUS_HSTIMER
value|40
end_define

begin_define
define|#
directive|define
name|CLK_BUS_SPI0
value|41
end_define

begin_define
define|#
directive|define
name|CLK_BUS_SPI1
value|42
end_define

begin_define
define|#
directive|define
name|CLK_BUS_SPI2
value|43
end_define

begin_define
define|#
directive|define
name|CLK_BUS_SPI3
value|44
end_define

begin_define
define|#
directive|define
name|CLK_BUS_SATA
value|45
end_define

begin_define
define|#
directive|define
name|CLK_BUS_OTG
value|46
end_define

begin_define
define|#
directive|define
name|CLK_BUS_EHCI0
value|47
end_define

begin_define
define|#
directive|define
name|CLK_BUS_EHCI1
value|48
end_define

begin_define
define|#
directive|define
name|CLK_BUS_EHCI2
value|49
end_define

begin_define
define|#
directive|define
name|CLK_BUS_OHCI0
value|50
end_define

begin_define
define|#
directive|define
name|CLK_BUS_OHCI1
value|51
end_define

begin_define
define|#
directive|define
name|CLK_BUS_OHCI2
value|52
end_define

begin_define
define|#
directive|define
name|CLK_BUS_VE
value|53
end_define

begin_define
define|#
directive|define
name|CLK_BUS_MP
value|54
end_define

begin_define
define|#
directive|define
name|CLK_BUS_DEINTERLACE
value|55
end_define

begin_define
define|#
directive|define
name|CLK_BUS_CSI0
value|56
end_define

begin_define
define|#
directive|define
name|CLK_BUS_CSI1
value|57
end_define

begin_define
define|#
directive|define
name|CLK_BUS_HDMI1
value|58
end_define

begin_define
define|#
directive|define
name|CLK_BUS_HDMI0
value|59
end_define

begin_define
define|#
directive|define
name|CLK_BUS_DE
value|60
end_define

begin_define
define|#
directive|define
name|CLK_BUS_TVE0
value|61
end_define

begin_define
define|#
directive|define
name|CLK_BUS_TVE1
value|62
end_define

begin_define
define|#
directive|define
name|CLK_BUS_TVE_TOP
value|63
end_define

begin_define
define|#
directive|define
name|CLK_BUS_GMAC
value|64
end_define

begin_define
define|#
directive|define
name|CLK_BUS_GPU
value|65
end_define

begin_define
define|#
directive|define
name|CLK_BUS_TVD0
value|66
end_define

begin_define
define|#
directive|define
name|CLK_BUS_TVD1
value|67
end_define

begin_define
define|#
directive|define
name|CLK_BUS_TVD2
value|68
end_define

begin_define
define|#
directive|define
name|CLK_BUS_TVD3
value|69
end_define

begin_define
define|#
directive|define
name|CLK_BUS_TVD_TOP
value|70
end_define

begin_define
define|#
directive|define
name|CLK_BUS_TCON_LCD0
value|71
end_define

begin_define
define|#
directive|define
name|CLK_BUS_TCON_LCD1
value|72
end_define

begin_define
define|#
directive|define
name|CLK_BUS_TCON_TV0
value|73
end_define

begin_define
define|#
directive|define
name|CLK_BUS_TCON_TV1
value|74
end_define

begin_define
define|#
directive|define
name|CLK_BUS_TCON_TOP
value|75
end_define

begin_define
define|#
directive|define
name|CLK_BUS_CODEC
value|76
end_define

begin_define
define|#
directive|define
name|CLK_BUS_SPDIF
value|77
end_define

begin_define
define|#
directive|define
name|CLK_BUS_AC97
value|78
end_define

begin_define
define|#
directive|define
name|CLK_BUS_PIO
value|79
end_define

begin_define
define|#
directive|define
name|CLK_BUS_IR0
value|80
end_define

begin_define
define|#
directive|define
name|CLK_BUS_IR1
value|81
end_define

begin_define
define|#
directive|define
name|CLK_BUS_THS
value|82
end_define

begin_define
define|#
directive|define
name|CLK_BUS_KEYPAD
value|83
end_define

begin_define
define|#
directive|define
name|CLK_BUS_I2S0
value|84
end_define

begin_define
define|#
directive|define
name|CLK_BUS_I2S1
value|85
end_define

begin_define
define|#
directive|define
name|CLK_BUS_I2S2
value|86
end_define

begin_define
define|#
directive|define
name|CLK_BUS_I2C0
value|87
end_define

begin_define
define|#
directive|define
name|CLK_BUS_I2C1
value|88
end_define

begin_define
define|#
directive|define
name|CLK_BUS_I2C2
value|89
end_define

begin_define
define|#
directive|define
name|CLK_BUS_I2C3
value|90
end_define

begin_define
define|#
directive|define
name|CLK_BUS_CAN
value|91
end_define

begin_define
define|#
directive|define
name|CLK_BUS_SCR
value|92
end_define

begin_define
define|#
directive|define
name|CLK_BUS_PS20
value|93
end_define

begin_define
define|#
directive|define
name|CLK_BUS_PS21
value|94
end_define

begin_define
define|#
directive|define
name|CLK_BUS_I2C4
value|95
end_define

begin_define
define|#
directive|define
name|CLK_BUS_UART0
value|96
end_define

begin_define
define|#
directive|define
name|CLK_BUS_UART1
value|97
end_define

begin_define
define|#
directive|define
name|CLK_BUS_UART2
value|98
end_define

begin_define
define|#
directive|define
name|CLK_BUS_UART3
value|99
end_define

begin_define
define|#
directive|define
name|CLK_BUS_UART4
value|100
end_define

begin_define
define|#
directive|define
name|CLK_BUS_UART5
value|101
end_define

begin_define
define|#
directive|define
name|CLK_BUS_UART6
value|102
end_define

begin_define
define|#
directive|define
name|CLK_BUS_UART7
value|103
end_define

begin_define
define|#
directive|define
name|CLK_BUS_DBG
value|104
end_define

begin_define
define|#
directive|define
name|CLK_THS
value|105
end_define

begin_define
define|#
directive|define
name|CLK_NAND
value|106
end_define

begin_define
define|#
directive|define
name|CLK_MMC0
value|107
end_define

begin_define
define|#
directive|define
name|CLK_MMC1
value|108
end_define

begin_define
define|#
directive|define
name|CLK_MMC2
value|109
end_define

begin_define
define|#
directive|define
name|CLK_MMC3
value|110
end_define

begin_define
define|#
directive|define
name|CLK_TS
value|111
end_define

begin_define
define|#
directive|define
name|CLK_CE
value|112
end_define

begin_define
define|#
directive|define
name|CLK_SPI0
value|113
end_define

begin_define
define|#
directive|define
name|CLK_SPI1
value|114
end_define

begin_define
define|#
directive|define
name|CLK_SPI2
value|115
end_define

begin_define
define|#
directive|define
name|CLK_SPI3
value|116
end_define

begin_define
define|#
directive|define
name|CLK_I2S0
value|117
end_define

begin_define
define|#
directive|define
name|CLK_I2S1
value|118
end_define

begin_define
define|#
directive|define
name|CLK_I2S2
value|119
end_define

begin_define
define|#
directive|define
name|CLK_AC97
value|120
end_define

begin_define
define|#
directive|define
name|CLK_SPDIF
value|121
end_define

begin_define
define|#
directive|define
name|CLK_KEYPAD
value|122
end_define

begin_define
define|#
directive|define
name|CLK_SATA
value|123
end_define

begin_define
define|#
directive|define
name|CLK_USB_PHY0
value|124
end_define

begin_define
define|#
directive|define
name|CLK_USB_PHY1
value|125
end_define

begin_define
define|#
directive|define
name|CLK_USB_PHY2
value|126
end_define

begin_define
define|#
directive|define
name|CLK_USB_OHCI0
value|127
end_define

begin_define
define|#
directive|define
name|CLK_USB_OHCI1
value|128
end_define

begin_define
define|#
directive|define
name|CLK_USB_OHCI2
value|129
end_define

begin_define
define|#
directive|define
name|CLK_IR0
value|130
end_define

begin_define
define|#
directive|define
name|CLK_IR1
value|131
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_VE
value|133
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_CSI0
value|134
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_CSI1
value|135
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_TS
value|136
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_TVD
value|137
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_MP
value|138
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_DEINTERLACE
value|139
end_define

begin_define
define|#
directive|define
name|CLK_DE
value|140
end_define

begin_define
define|#
directive|define
name|CLK_MP
value|141
end_define

begin_define
define|#
directive|define
name|CLK_TCON_LCD0
value|142
end_define

begin_define
define|#
directive|define
name|CLK_TCON_LCD1
value|143
end_define

begin_define
define|#
directive|define
name|CLK_TCON_TV0
value|144
end_define

begin_define
define|#
directive|define
name|CLK_TCON_TV1
value|145
end_define

begin_define
define|#
directive|define
name|CLK_DEINTERLACE
value|146
end_define

begin_define
define|#
directive|define
name|CLK_CSI1_MCLK
value|147
end_define

begin_define
define|#
directive|define
name|CLK_CSI_SCLK
value|148
end_define

begin_define
define|#
directive|define
name|CLK_CSI0_MCLK
value|149
end_define

begin_define
define|#
directive|define
name|CLK_VE
value|150
end_define

begin_define
define|#
directive|define
name|CLK_CODEC
value|151
end_define

begin_define
define|#
directive|define
name|CLK_AVS
value|152
end_define

begin_define
define|#
directive|define
name|CLK_HDMI
value|153
end_define

begin_define
define|#
directive|define
name|CLK_HDMI_SLOW
value|154
end_define

begin_define
define|#
directive|define
name|CLK_DSI_DPHY
value|156
end_define

begin_define
define|#
directive|define
name|CLK_TVE0
value|157
end_define

begin_define
define|#
directive|define
name|CLK_TVE1
value|158
end_define

begin_define
define|#
directive|define
name|CLK_TVD0
value|159
end_define

begin_define
define|#
directive|define
name|CLK_TVD1
value|160
end_define

begin_define
define|#
directive|define
name|CLK_TVD2
value|161
end_define

begin_define
define|#
directive|define
name|CLK_TVD3
value|162
end_define

begin_define
define|#
directive|define
name|CLK_GPU
value|163
end_define

begin_define
define|#
directive|define
name|CLK_OUTA
value|164
end_define

begin_define
define|#
directive|define
name|CLK_OUTB
value|165
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_CLK_SUN8I_R40_H_ */
end_comment

end_unit

