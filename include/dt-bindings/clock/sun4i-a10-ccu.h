begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2017 Priit Laes<plaes@plaes.org>  *  * This file is dual-licensed: you can use it either under the terms  * of the GPL or the X11 license, at your option. Note that this dual  * licensing only applies to this file, and not this project as a  * whole.  *  *  a) This file is free software; you can redistribute it and/or  *     modify it under the terms of the GNU General Public License as  *     published by the Free Software Foundation; either version 2 of the  *     License, or (at your option) any later version.  *  *     This file is distributed in the hope that it will be useful,  *     but WITHOUT ANY WARRANTY; without even the implied warranty of  *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  *     GNU General Public License for more details.  *  * Or, alternatively,  *  *  b) Permission is hereby granted, free of charge, to any person  *     obtaining a copy of this software and associated documentation  *     files (the "Software"), to deal in the Software without  *     restriction, including without limitation the rights to use,  *     copy, modify, merge, publish, distribute, sublicense, and/or  *     sell copies of the Software, and to permit persons to whom the  *     Software is furnished to do so, subject to the following  *     conditions:  *  *     The above copyright notice and this permission notice shall be  *     included in all copies or substantial portions of the Software.  *  *     THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  *     EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES  *     OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  *     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT  *     HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,  *     FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  *     OTHER DEALINGS IN THE SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLK_SUN4I_A10_H_
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLK_SUN4I_A10_H_
end_define

begin_define
define|#
directive|define
name|CLK_HOSC
value|1
end_define

begin_define
define|#
directive|define
name|CLK_CPU
value|20
end_define

begin_comment
comment|/* AHB Gates */
end_comment

begin_define
define|#
directive|define
name|CLK_AHB_OTG
value|26
end_define

begin_define
define|#
directive|define
name|CLK_AHB_EHCI0
value|27
end_define

begin_define
define|#
directive|define
name|CLK_AHB_OHCI0
value|28
end_define

begin_define
define|#
directive|define
name|CLK_AHB_EHCI1
value|29
end_define

begin_define
define|#
directive|define
name|CLK_AHB_OHCI1
value|30
end_define

begin_define
define|#
directive|define
name|CLK_AHB_SS
value|31
end_define

begin_define
define|#
directive|define
name|CLK_AHB_DMA
value|32
end_define

begin_define
define|#
directive|define
name|CLK_AHB_BIST
value|33
end_define

begin_define
define|#
directive|define
name|CLK_AHB_MMC0
value|34
end_define

begin_define
define|#
directive|define
name|CLK_AHB_MMC1
value|35
end_define

begin_define
define|#
directive|define
name|CLK_AHB_MMC2
value|36
end_define

begin_define
define|#
directive|define
name|CLK_AHB_MMC3
value|37
end_define

begin_define
define|#
directive|define
name|CLK_AHB_MS
value|38
end_define

begin_define
define|#
directive|define
name|CLK_AHB_NAND
value|39
end_define

begin_define
define|#
directive|define
name|CLK_AHB_SDRAM
value|40
end_define

begin_define
define|#
directive|define
name|CLK_AHB_ACE
value|41
end_define

begin_define
define|#
directive|define
name|CLK_AHB_EMAC
value|42
end_define

begin_define
define|#
directive|define
name|CLK_AHB_TS
value|43
end_define

begin_define
define|#
directive|define
name|CLK_AHB_SPI0
value|44
end_define

begin_define
define|#
directive|define
name|CLK_AHB_SPI1
value|45
end_define

begin_define
define|#
directive|define
name|CLK_AHB_SPI2
value|46
end_define

begin_define
define|#
directive|define
name|CLK_AHB_SPI3
value|47
end_define

begin_define
define|#
directive|define
name|CLK_AHB_PATA
value|48
end_define

begin_define
define|#
directive|define
name|CLK_AHB_SATA
value|49
end_define

begin_define
define|#
directive|define
name|CLK_AHB_GPS
value|50
end_define

begin_define
define|#
directive|define
name|CLK_AHB_HSTIMER
value|51
end_define

begin_define
define|#
directive|define
name|CLK_AHB_VE
value|52
end_define

begin_define
define|#
directive|define
name|CLK_AHB_TVD
value|53
end_define

begin_define
define|#
directive|define
name|CLK_AHB_TVE0
value|54
end_define

begin_define
define|#
directive|define
name|CLK_AHB_TVE1
value|55
end_define

begin_define
define|#
directive|define
name|CLK_AHB_LCD0
value|56
end_define

begin_define
define|#
directive|define
name|CLK_AHB_LCD1
value|57
end_define

begin_define
define|#
directive|define
name|CLK_AHB_CSI0
value|58
end_define

begin_define
define|#
directive|define
name|CLK_AHB_CSI1
value|59
end_define

begin_define
define|#
directive|define
name|CLK_AHB_HDMI0
value|60
end_define

begin_define
define|#
directive|define
name|CLK_AHB_HDMI1
value|61
end_define

begin_define
define|#
directive|define
name|CLK_AHB_DE_BE0
value|62
end_define

begin_define
define|#
directive|define
name|CLK_AHB_DE_BE1
value|63
end_define

begin_define
define|#
directive|define
name|CLK_AHB_DE_FE0
value|64
end_define

begin_define
define|#
directive|define
name|CLK_AHB_DE_FE1
value|65
end_define

begin_define
define|#
directive|define
name|CLK_AHB_GMAC
value|66
end_define

begin_define
define|#
directive|define
name|CLK_AHB_MP
value|67
end_define

begin_define
define|#
directive|define
name|CLK_AHB_GPU
value|68
end_define

begin_comment
comment|/* APB0 Gates */
end_comment

begin_define
define|#
directive|define
name|CLK_APB0_CODEC
value|69
end_define

begin_define
define|#
directive|define
name|CLK_APB0_SPDIF
value|70
end_define

begin_define
define|#
directive|define
name|CLK_APB0_I2S0
value|71
end_define

begin_define
define|#
directive|define
name|CLK_APB0_AC97
value|72
end_define

begin_define
define|#
directive|define
name|CLK_APB0_I2S1
value|73
end_define

begin_define
define|#
directive|define
name|CLK_APB0_PIO
value|74
end_define

begin_define
define|#
directive|define
name|CLK_APB0_IR0
value|75
end_define

begin_define
define|#
directive|define
name|CLK_APB0_IR1
value|76
end_define

begin_define
define|#
directive|define
name|CLK_APB0_I2S2
value|77
end_define

begin_define
define|#
directive|define
name|CLK_APB0_KEYPAD
value|78
end_define

begin_comment
comment|/* APB1 Gates */
end_comment

begin_define
define|#
directive|define
name|CLK_APB1_I2C0
value|79
end_define

begin_define
define|#
directive|define
name|CLK_APB1_I2C1
value|80
end_define

begin_define
define|#
directive|define
name|CLK_APB1_I2C2
value|81
end_define

begin_define
define|#
directive|define
name|CLK_APB1_I2C3
value|82
end_define

begin_define
define|#
directive|define
name|CLK_APB1_CAN
value|83
end_define

begin_define
define|#
directive|define
name|CLK_APB1_SCR
value|84
end_define

begin_define
define|#
directive|define
name|CLK_APB1_PS20
value|85
end_define

begin_define
define|#
directive|define
name|CLK_APB1_PS21
value|86
end_define

begin_define
define|#
directive|define
name|CLK_APB1_I2C4
value|87
end_define

begin_define
define|#
directive|define
name|CLK_APB1_UART0
value|88
end_define

begin_define
define|#
directive|define
name|CLK_APB1_UART1
value|89
end_define

begin_define
define|#
directive|define
name|CLK_APB1_UART2
value|90
end_define

begin_define
define|#
directive|define
name|CLK_APB1_UART3
value|91
end_define

begin_define
define|#
directive|define
name|CLK_APB1_UART4
value|92
end_define

begin_define
define|#
directive|define
name|CLK_APB1_UART5
value|93
end_define

begin_define
define|#
directive|define
name|CLK_APB1_UART6
value|94
end_define

begin_define
define|#
directive|define
name|CLK_APB1_UART7
value|95
end_define

begin_comment
comment|/* IP clocks */
end_comment

begin_define
define|#
directive|define
name|CLK_NAND
value|96
end_define

begin_define
define|#
directive|define
name|CLK_MS
value|97
end_define

begin_define
define|#
directive|define
name|CLK_MMC0
value|98
end_define

begin_define
define|#
directive|define
name|CLK_MMC0_OUTPUT
value|99
end_define

begin_define
define|#
directive|define
name|CLK_MMC0_SAMPLE
value|100
end_define

begin_define
define|#
directive|define
name|CLK_MMC1
value|101
end_define

begin_define
define|#
directive|define
name|CLK_MMC1_OUTPUT
value|102
end_define

begin_define
define|#
directive|define
name|CLK_MMC1_SAMPLE
value|103
end_define

begin_define
define|#
directive|define
name|CLK_MMC2
value|104
end_define

begin_define
define|#
directive|define
name|CLK_MMC2_OUTPUT
value|105
end_define

begin_define
define|#
directive|define
name|CLK_MMC2_SAMPLE
value|106
end_define

begin_define
define|#
directive|define
name|CLK_MMC3
value|107
end_define

begin_define
define|#
directive|define
name|CLK_MMC3_OUTPUT
value|108
end_define

begin_define
define|#
directive|define
name|CLK_MMC3_SAMPLE
value|109
end_define

begin_define
define|#
directive|define
name|CLK_TS
value|110
end_define

begin_define
define|#
directive|define
name|CLK_SS
value|111
end_define

begin_define
define|#
directive|define
name|CLK_SPI0
value|112
end_define

begin_define
define|#
directive|define
name|CLK_SPI1
value|113
end_define

begin_define
define|#
directive|define
name|CLK_SPI2
value|114
end_define

begin_define
define|#
directive|define
name|CLK_PATA
value|115
end_define

begin_define
define|#
directive|define
name|CLK_IR0
value|116
end_define

begin_define
define|#
directive|define
name|CLK_IR1
value|117
end_define

begin_define
define|#
directive|define
name|CLK_I2S0
value|118
end_define

begin_define
define|#
directive|define
name|CLK_AC97
value|119
end_define

begin_define
define|#
directive|define
name|CLK_SPDIF
value|120
end_define

begin_define
define|#
directive|define
name|CLK_KEYPAD
value|121
end_define

begin_define
define|#
directive|define
name|CLK_SATA
value|122
end_define

begin_define
define|#
directive|define
name|CLK_USB_OHCI0
value|123
end_define

begin_define
define|#
directive|define
name|CLK_USB_OHCI1
value|124
end_define

begin_define
define|#
directive|define
name|CLK_USB_PHY
value|125
end_define

begin_define
define|#
directive|define
name|CLK_GPS
value|126
end_define

begin_define
define|#
directive|define
name|CLK_SPI3
value|127
end_define

begin_define
define|#
directive|define
name|CLK_I2S1
value|128
end_define

begin_define
define|#
directive|define
name|CLK_I2S2
value|129
end_define

begin_comment
comment|/* DRAM Gates */
end_comment

begin_define
define|#
directive|define
name|CLK_DRAM_VE
value|130
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_CSI0
value|131
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_CSI1
value|132
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_TS
value|133
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_TVD
value|134
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_TVE0
value|135
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_TVE1
value|136
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_OUT
value|137
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_DE_FE1
value|138
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_DE_FE0
value|139
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_DE_BE0
value|140
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_DE_BE1
value|141
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_MP
value|142
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_ACE
value|143
end_define

begin_comment
comment|/* Display Engine Clocks */
end_comment

begin_define
define|#
directive|define
name|CLK_DE_BE0
value|144
end_define

begin_define
define|#
directive|define
name|CLK_DE_BE1
value|145
end_define

begin_define
define|#
directive|define
name|CLK_DE_FE0
value|146
end_define

begin_define
define|#
directive|define
name|CLK_DE_FE1
value|147
end_define

begin_define
define|#
directive|define
name|CLK_DE_MP
value|148
end_define

begin_define
define|#
directive|define
name|CLK_TCON0_CH0
value|149
end_define

begin_define
define|#
directive|define
name|CLK_TCON1_CH0
value|150
end_define

begin_define
define|#
directive|define
name|CLK_CSI_SCLK
value|151
end_define

begin_define
define|#
directive|define
name|CLK_TVD_SCLK2
value|152
end_define

begin_define
define|#
directive|define
name|CLK_TVD
value|153
end_define

begin_define
define|#
directive|define
name|CLK_TCON0_CH1_SCLK2
value|154
end_define

begin_define
define|#
directive|define
name|CLK_TCON0_CH1
value|155
end_define

begin_define
define|#
directive|define
name|CLK_TCON1_CH1_SCLK2
value|156
end_define

begin_define
define|#
directive|define
name|CLK_TCON1_CH1
value|157
end_define

begin_define
define|#
directive|define
name|CLK_CSI0
value|158
end_define

begin_define
define|#
directive|define
name|CLK_CSI1
value|159
end_define

begin_define
define|#
directive|define
name|CLK_CODEC
value|160
end_define

begin_define
define|#
directive|define
name|CLK_VE
value|161
end_define

begin_define
define|#
directive|define
name|CLK_AVS
value|162
end_define

begin_define
define|#
directive|define
name|CLK_ACE
value|163
end_define

begin_define
define|#
directive|define
name|CLK_HDMI
value|164
end_define

begin_define
define|#
directive|define
name|CLK_GPU
value|165
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_CLK_SUN4I_A10_H_ */
end_comment

end_unit

