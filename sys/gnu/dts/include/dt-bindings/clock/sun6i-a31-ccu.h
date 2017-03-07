begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2016 Chen-Yu Tsai<wens@csie.org>  *  * This file is dual-licensed: you can use it either under the terms  * of the GPL or the X11 license, at your option. Note that this dual  * licensing only applies to this file, and not this project as a  * whole.  *  *  a) This file is free software; you can redistribute it and/or  *     modify it under the terms of the GNU General Public License as  *     published by the Free Software Foundation; either version 2 of the  *     License, or (at your option) any later version.  *  *     This file is distributed in the hope that it will be useful,  *     but WITHOUT ANY WARRANTY; without even the implied warranty of  *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  *     GNU General Public License for more details.  *  * Or, alternatively,  *  *  b) Permission is hereby granted, free of charge, to any person  *     obtaining a copy of this software and associated documentation  *     files (the "Software"), to deal in the Software without  *     restriction, including without limitation the rights to use,  *     copy, modify, merge, publish, distribute, sublicense, and/or  *     sell copies of the Software, and to permit persons to whom the  *     Software is furnished to do so, subject to the following  *     conditions:  *  *     The above copyright notice and this permission notice shall be  *     included in all copies or substantial portions of the Software.  *  *     THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  *     EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES  *     OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  *     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT  *     HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,  *     WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  *     FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  *     OTHER DEALINGS IN THE SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLK_SUN6I_A31_H_
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLK_SUN6I_A31_H_
end_define

begin_define
define|#
directive|define
name|CLK_PLL_PERIPH
value|10
end_define

begin_define
define|#
directive|define
name|CLK_CPU
value|18
end_define

begin_define
define|#
directive|define
name|CLK_AHB1_MIPIDSI
value|23
end_define

begin_define
define|#
directive|define
name|CLK_AHB1_SS
value|24
end_define

begin_define
define|#
directive|define
name|CLK_AHB1_DMA
value|25
end_define

begin_define
define|#
directive|define
name|CLK_AHB1_MMC0
value|26
end_define

begin_define
define|#
directive|define
name|CLK_AHB1_MMC1
value|27
end_define

begin_define
define|#
directive|define
name|CLK_AHB1_MMC2
value|28
end_define

begin_define
define|#
directive|define
name|CLK_AHB1_MMC3
value|29
end_define

begin_define
define|#
directive|define
name|CLK_AHB1_NAND1
value|30
end_define

begin_define
define|#
directive|define
name|CLK_AHB1_NAND0
value|31
end_define

begin_define
define|#
directive|define
name|CLK_AHB1_SDRAM
value|32
end_define

begin_define
define|#
directive|define
name|CLK_AHB1_EMAC
value|33
end_define

begin_define
define|#
directive|define
name|CLK_AHB1_TS
value|34
end_define

begin_define
define|#
directive|define
name|CLK_AHB1_HSTIMER
value|35
end_define

begin_define
define|#
directive|define
name|CLK_AHB1_SPI0
value|36
end_define

begin_define
define|#
directive|define
name|CLK_AHB1_SPI1
value|37
end_define

begin_define
define|#
directive|define
name|CLK_AHB1_SPI2
value|38
end_define

begin_define
define|#
directive|define
name|CLK_AHB1_SPI3
value|39
end_define

begin_define
define|#
directive|define
name|CLK_AHB1_OTG
value|40
end_define

begin_define
define|#
directive|define
name|CLK_AHB1_EHCI0
value|41
end_define

begin_define
define|#
directive|define
name|CLK_AHB1_EHCI1
value|42
end_define

begin_define
define|#
directive|define
name|CLK_AHB1_OHCI0
value|43
end_define

begin_define
define|#
directive|define
name|CLK_AHB1_OHCI1
value|44
end_define

begin_define
define|#
directive|define
name|CLK_AHB1_OHCI2
value|45
end_define

begin_define
define|#
directive|define
name|CLK_AHB1_VE
value|46
end_define

begin_define
define|#
directive|define
name|CLK_AHB1_LCD0
value|47
end_define

begin_define
define|#
directive|define
name|CLK_AHB1_LCD1
value|48
end_define

begin_define
define|#
directive|define
name|CLK_AHB1_CSI
value|49
end_define

begin_define
define|#
directive|define
name|CLK_AHB1_HDMI
value|50
end_define

begin_define
define|#
directive|define
name|CLK_AHB1_BE0
value|51
end_define

begin_define
define|#
directive|define
name|CLK_AHB1_BE1
value|52
end_define

begin_define
define|#
directive|define
name|CLK_AHB1_FE0
value|53
end_define

begin_define
define|#
directive|define
name|CLK_AHB1_FE1
value|54
end_define

begin_define
define|#
directive|define
name|CLK_AHB1_MP
value|55
end_define

begin_define
define|#
directive|define
name|CLK_AHB1_GPU
value|56
end_define

begin_define
define|#
directive|define
name|CLK_AHB1_DEU0
value|57
end_define

begin_define
define|#
directive|define
name|CLK_AHB1_DEU1
value|58
end_define

begin_define
define|#
directive|define
name|CLK_AHB1_DRC0
value|59
end_define

begin_define
define|#
directive|define
name|CLK_AHB1_DRC1
value|60
end_define

begin_define
define|#
directive|define
name|CLK_APB1_CODEC
value|61
end_define

begin_define
define|#
directive|define
name|CLK_APB1_SPDIF
value|62
end_define

begin_define
define|#
directive|define
name|CLK_APB1_DIGITAL_MIC
value|63
end_define

begin_define
define|#
directive|define
name|CLK_APB1_PIO
value|64
end_define

begin_define
define|#
directive|define
name|CLK_APB1_DAUDIO0
value|65
end_define

begin_define
define|#
directive|define
name|CLK_APB1_DAUDIO1
value|66
end_define

begin_define
define|#
directive|define
name|CLK_APB2_I2C0
value|67
end_define

begin_define
define|#
directive|define
name|CLK_APB2_I2C1
value|68
end_define

begin_define
define|#
directive|define
name|CLK_APB2_I2C2
value|69
end_define

begin_define
define|#
directive|define
name|CLK_APB2_I2C3
value|70
end_define

begin_define
define|#
directive|define
name|CLK_APB2_UART0
value|71
end_define

begin_define
define|#
directive|define
name|CLK_APB2_UART1
value|72
end_define

begin_define
define|#
directive|define
name|CLK_APB2_UART2
value|73
end_define

begin_define
define|#
directive|define
name|CLK_APB2_UART3
value|74
end_define

begin_define
define|#
directive|define
name|CLK_APB2_UART4
value|75
end_define

begin_define
define|#
directive|define
name|CLK_APB2_UART5
value|76
end_define

begin_define
define|#
directive|define
name|CLK_NAND0
value|77
end_define

begin_define
define|#
directive|define
name|CLK_NAND1
value|78
end_define

begin_define
define|#
directive|define
name|CLK_MMC0
value|79
end_define

begin_define
define|#
directive|define
name|CLK_MMC0_SAMPLE
value|80
end_define

begin_define
define|#
directive|define
name|CLK_MMC0_OUTPUT
value|81
end_define

begin_define
define|#
directive|define
name|CLK_MMC1
value|82
end_define

begin_define
define|#
directive|define
name|CLK_MMC1_SAMPLE
value|83
end_define

begin_define
define|#
directive|define
name|CLK_MMC1_OUTPUT
value|84
end_define

begin_define
define|#
directive|define
name|CLK_MMC2
value|85
end_define

begin_define
define|#
directive|define
name|CLK_MMC2_SAMPLE
value|86
end_define

begin_define
define|#
directive|define
name|CLK_MMC2_OUTPUT
value|87
end_define

begin_define
define|#
directive|define
name|CLK_MMC3
value|88
end_define

begin_define
define|#
directive|define
name|CLK_MMC3_SAMPLE
value|89
end_define

begin_define
define|#
directive|define
name|CLK_MMC3_OUTPUT
value|90
end_define

begin_define
define|#
directive|define
name|CLK_TS
value|91
end_define

begin_define
define|#
directive|define
name|CLK_SS
value|92
end_define

begin_define
define|#
directive|define
name|CLK_SPI0
value|93
end_define

begin_define
define|#
directive|define
name|CLK_SPI1
value|94
end_define

begin_define
define|#
directive|define
name|CLK_SPI2
value|95
end_define

begin_define
define|#
directive|define
name|CLK_SPI3
value|96
end_define

begin_define
define|#
directive|define
name|CLK_DAUDIO0
value|97
end_define

begin_define
define|#
directive|define
name|CLK_DAUDIO1
value|98
end_define

begin_define
define|#
directive|define
name|CLK_SPDIF
value|99
end_define

begin_define
define|#
directive|define
name|CLK_USB_PHY0
value|100
end_define

begin_define
define|#
directive|define
name|CLK_USB_PHY1
value|101
end_define

begin_define
define|#
directive|define
name|CLK_USB_PHY2
value|102
end_define

begin_define
define|#
directive|define
name|CLK_USB_OHCI0
value|103
end_define

begin_define
define|#
directive|define
name|CLK_USB_OHCI1
value|104
end_define

begin_define
define|#
directive|define
name|CLK_USB_OHCI2
value|105
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_VE
value|110
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_CSI_ISP
value|111
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_TS
value|112
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_DRC0
value|113
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_DRC1
value|114
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_DEU0
value|115
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_DEU1
value|116
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_FE0
value|117
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_FE1
value|118
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_BE0
value|119
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_BE1
value|120
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_MP
value|121
end_define

begin_define
define|#
directive|define
name|CLK_BE0
value|122
end_define

begin_define
define|#
directive|define
name|CLK_BE1
value|123
end_define

begin_define
define|#
directive|define
name|CLK_FE0
value|124
end_define

begin_define
define|#
directive|define
name|CLK_FE1
value|125
end_define

begin_define
define|#
directive|define
name|CLK_MP
value|126
end_define

begin_define
define|#
directive|define
name|CLK_LCD0_CH0
value|127
end_define

begin_define
define|#
directive|define
name|CLK_LCD1_CH0
value|128
end_define

begin_define
define|#
directive|define
name|CLK_LCD0_CH1
value|129
end_define

begin_define
define|#
directive|define
name|CLK_LCD1_CH1
value|130
end_define

begin_define
define|#
directive|define
name|CLK_CSI0_SCLK
value|131
end_define

begin_define
define|#
directive|define
name|CLK_CSI0_MCLK
value|132
end_define

begin_define
define|#
directive|define
name|CLK_CSI1_MCLK
value|133
end_define

begin_define
define|#
directive|define
name|CLK_VE
value|134
end_define

begin_define
define|#
directive|define
name|CLK_CODEC
value|135
end_define

begin_define
define|#
directive|define
name|CLK_AVS
value|136
end_define

begin_define
define|#
directive|define
name|CLK_DIGITAL_MIC
value|137
end_define

begin_define
define|#
directive|define
name|CLK_HDMI
value|138
end_define

begin_define
define|#
directive|define
name|CLK_HDMI_DDC
value|139
end_define

begin_define
define|#
directive|define
name|CLK_PS
value|140
end_define

begin_define
define|#
directive|define
name|CLK_MIPI_DSI
value|143
end_define

begin_define
define|#
directive|define
name|CLK_MIPI_DSI_DPHY
value|144
end_define

begin_define
define|#
directive|define
name|CLK_MIPI_CSI_DPHY
value|145
end_define

begin_define
define|#
directive|define
name|CLK_IEP_DRC0
value|146
end_define

begin_define
define|#
directive|define
name|CLK_IEP_DRC1
value|147
end_define

begin_define
define|#
directive|define
name|CLK_IEP_DEU0
value|148
end_define

begin_define
define|#
directive|define
name|CLK_IEP_DEU1
value|149
end_define

begin_define
define|#
directive|define
name|CLK_GPU_CORE
value|150
end_define

begin_define
define|#
directive|define
name|CLK_GPU_MEMORY
value|151
end_define

begin_define
define|#
directive|define
name|CLK_GPU_HYD
value|152
end_define

begin_define
define|#
directive|define
name|CLK_ATS
value|153
end_define

begin_define
define|#
directive|define
name|CLK_TRACE
value|154
end_define

begin_define
define|#
directive|define
name|CLK_OUT_A
value|155
end_define

begin_define
define|#
directive|define
name|CLK_OUT_B
value|156
end_define

begin_define
define|#
directive|define
name|CLK_OUT_C
value|157
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_CLK_SUN6I_A31_H_ */
end_comment

end_unit

