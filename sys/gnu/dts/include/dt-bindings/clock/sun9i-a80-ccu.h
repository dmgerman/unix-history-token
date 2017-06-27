begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2016 Chen-Yu Tsai<wens@csie.org>  *  * This file is dual-licensed: you can use it either under the terms  * of the GPL or the X11 license, at your option. Note that this dual  * licensing only applies to this file, and not this project as a  * whole.  *  *  a) This file is free software; you can redistribute it and/or  *     modify it under the terms of the GNU General Public License as  *     published by the Free Software Foundation; either version 2 of the  *     License, or (at your option) any later version.  *  *     This file is distributed in the hope that it will be useful,  *     but WITHOUT ANY WARRANTY; without even the implied warranty of  *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  *     GNU General Public License for more details.  *  * Or, alternatively,  *  *  b) Permission is hereby granted, free of charge, to any person  *     obtaining a copy of this software and associated documentation  *     files (the "Software"), to deal in the Software without  *     restriction, including without limitation the rights to use,  *     copy, modify, merge, publish, distribute, sublicense, and/or  *     sell copies of the Software, and to permit persons to whom the  *     Software is furnished to do so, subject to the following  *     conditions:  *  *     The above copyright notice and this permission notice shall be  *     included in all copies or substantial portions of the Software.  *  *     THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  *     EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES  *     OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  *     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT  *     HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,  *     WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  *     FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  *     OTHER DEALINGS IN THE SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLOCK_SUN9I_A80_CCU_H_
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLOCK_SUN9I_A80_CCU_H_
end_define

begin_define
define|#
directive|define
name|CLK_PLL_AUDIO
value|2
end_define

begin_define
define|#
directive|define
name|CLK_PLL_PERIPH0
value|3
end_define

begin_define
define|#
directive|define
name|CLK_C0CPUX
value|12
end_define

begin_define
define|#
directive|define
name|CLK_C1CPUX
value|13
end_define

begin_define
define|#
directive|define
name|CLK_OUT_A
value|27
end_define

begin_define
define|#
directive|define
name|CLK_OUT_B
value|28
end_define

begin_define
define|#
directive|define
name|CLK_NAND0_0
value|29
end_define

begin_define
define|#
directive|define
name|CLK_NAND0_1
value|30
end_define

begin_define
define|#
directive|define
name|CLK_NAND1_0
value|31
end_define

begin_define
define|#
directive|define
name|CLK_NAND1_1
value|32
end_define

begin_define
define|#
directive|define
name|CLK_MMC0
value|33
end_define

begin_define
define|#
directive|define
name|CLK_MMC0_SAMPLE
value|34
end_define

begin_define
define|#
directive|define
name|CLK_MMC0_OUTPUT
value|35
end_define

begin_define
define|#
directive|define
name|CLK_MMC1
value|36
end_define

begin_define
define|#
directive|define
name|CLK_MMC1_SAMPLE
value|37
end_define

begin_define
define|#
directive|define
name|CLK_MMC1_OUTPUT
value|38
end_define

begin_define
define|#
directive|define
name|CLK_MMC2
value|39
end_define

begin_define
define|#
directive|define
name|CLK_MMC2_SAMPLE
value|40
end_define

begin_define
define|#
directive|define
name|CLK_MMC2_OUTPUT
value|41
end_define

begin_define
define|#
directive|define
name|CLK_MMC3
value|42
end_define

begin_define
define|#
directive|define
name|CLK_MMC3_SAMPLE
value|43
end_define

begin_define
define|#
directive|define
name|CLK_MMC3_OUTPUT
value|44
end_define

begin_define
define|#
directive|define
name|CLK_TS
value|45
end_define

begin_define
define|#
directive|define
name|CLK_SS
value|46
end_define

begin_define
define|#
directive|define
name|CLK_SPI0
value|47
end_define

begin_define
define|#
directive|define
name|CLK_SPI1
value|48
end_define

begin_define
define|#
directive|define
name|CLK_SPI2
value|49
end_define

begin_define
define|#
directive|define
name|CLK_SPI3
value|50
end_define

begin_define
define|#
directive|define
name|CLK_I2S0
value|51
end_define

begin_define
define|#
directive|define
name|CLK_I2S1
value|52
end_define

begin_define
define|#
directive|define
name|CLK_SPDIF
value|53
end_define

begin_define
define|#
directive|define
name|CLK_SDRAM
value|54
end_define

begin_define
define|#
directive|define
name|CLK_DE
value|55
end_define

begin_define
define|#
directive|define
name|CLK_EDP
value|56
end_define

begin_define
define|#
directive|define
name|CLK_MP
value|57
end_define

begin_define
define|#
directive|define
name|CLK_LCD0
value|58
end_define

begin_define
define|#
directive|define
name|CLK_LCD1
value|59
end_define

begin_define
define|#
directive|define
name|CLK_MIPI_DSI0
value|60
end_define

begin_define
define|#
directive|define
name|CLK_MIPI_DSI1
value|61
end_define

begin_define
define|#
directive|define
name|CLK_HDMI
value|62
end_define

begin_define
define|#
directive|define
name|CLK_HDMI_SLOW
value|63
end_define

begin_define
define|#
directive|define
name|CLK_MIPI_CSI
value|64
end_define

begin_define
define|#
directive|define
name|CLK_CSI_ISP
value|65
end_define

begin_define
define|#
directive|define
name|CLK_CSI_MISC
value|66
end_define

begin_define
define|#
directive|define
name|CLK_CSI0_MCLK
value|67
end_define

begin_define
define|#
directive|define
name|CLK_CSI1_MCLK
value|68
end_define

begin_define
define|#
directive|define
name|CLK_FD
value|69
end_define

begin_define
define|#
directive|define
name|CLK_VE
value|70
end_define

begin_define
define|#
directive|define
name|CLK_AVS
value|71
end_define

begin_define
define|#
directive|define
name|CLK_GPU_CORE
value|72
end_define

begin_define
define|#
directive|define
name|CLK_GPU_MEMORY
value|73
end_define

begin_define
define|#
directive|define
name|CLK_GPU_AXI
value|74
end_define

begin_define
define|#
directive|define
name|CLK_SATA
value|75
end_define

begin_define
define|#
directive|define
name|CLK_AC97
value|76
end_define

begin_define
define|#
directive|define
name|CLK_MIPI_HSI
value|77
end_define

begin_define
define|#
directive|define
name|CLK_GPADC
value|78
end_define

begin_define
define|#
directive|define
name|CLK_CIR_TX
value|79
end_define

begin_define
define|#
directive|define
name|CLK_BUS_FD
value|80
end_define

begin_define
define|#
directive|define
name|CLK_BUS_VE
value|81
end_define

begin_define
define|#
directive|define
name|CLK_BUS_GPU_CTRL
value|82
end_define

begin_define
define|#
directive|define
name|CLK_BUS_SS
value|83
end_define

begin_define
define|#
directive|define
name|CLK_BUS_MMC
value|84
end_define

begin_define
define|#
directive|define
name|CLK_BUS_NAND0
value|85
end_define

begin_define
define|#
directive|define
name|CLK_BUS_NAND1
value|86
end_define

begin_define
define|#
directive|define
name|CLK_BUS_SDRAM
value|87
end_define

begin_define
define|#
directive|define
name|CLK_BUS_MIPI_HSI
value|88
end_define

begin_define
define|#
directive|define
name|CLK_BUS_SATA
value|89
end_define

begin_define
define|#
directive|define
name|CLK_BUS_TS
value|90
end_define

begin_define
define|#
directive|define
name|CLK_BUS_SPI0
value|91
end_define

begin_define
define|#
directive|define
name|CLK_BUS_SPI1
value|92
end_define

begin_define
define|#
directive|define
name|CLK_BUS_SPI2
value|93
end_define

begin_define
define|#
directive|define
name|CLK_BUS_SPI3
value|94
end_define

begin_define
define|#
directive|define
name|CLK_BUS_OTG
value|95
end_define

begin_define
define|#
directive|define
name|CLK_BUS_USB
value|96
end_define

begin_define
define|#
directive|define
name|CLK_BUS_GMAC
value|97
end_define

begin_define
define|#
directive|define
name|CLK_BUS_MSGBOX
value|98
end_define

begin_define
define|#
directive|define
name|CLK_BUS_SPINLOCK
value|99
end_define

begin_define
define|#
directive|define
name|CLK_BUS_HSTIMER
value|100
end_define

begin_define
define|#
directive|define
name|CLK_BUS_DMA
value|101
end_define

begin_define
define|#
directive|define
name|CLK_BUS_LCD0
value|102
end_define

begin_define
define|#
directive|define
name|CLK_BUS_LCD1
value|103
end_define

begin_define
define|#
directive|define
name|CLK_BUS_EDP
value|104
end_define

begin_define
define|#
directive|define
name|CLK_BUS_CSI
value|105
end_define

begin_define
define|#
directive|define
name|CLK_BUS_HDMI
value|106
end_define

begin_define
define|#
directive|define
name|CLK_BUS_DE
value|107
end_define

begin_define
define|#
directive|define
name|CLK_BUS_MP
value|108
end_define

begin_define
define|#
directive|define
name|CLK_BUS_MIPI_DSI
value|109
end_define

begin_define
define|#
directive|define
name|CLK_BUS_SPDIF
value|110
end_define

begin_define
define|#
directive|define
name|CLK_BUS_PIO
value|111
end_define

begin_define
define|#
directive|define
name|CLK_BUS_AC97
value|112
end_define

begin_define
define|#
directive|define
name|CLK_BUS_I2S0
value|113
end_define

begin_define
define|#
directive|define
name|CLK_BUS_I2S1
value|114
end_define

begin_define
define|#
directive|define
name|CLK_BUS_LRADC
value|115
end_define

begin_define
define|#
directive|define
name|CLK_BUS_GPADC
value|116
end_define

begin_define
define|#
directive|define
name|CLK_BUS_TWD
value|117
end_define

begin_define
define|#
directive|define
name|CLK_BUS_CIR_TX
value|118
end_define

begin_define
define|#
directive|define
name|CLK_BUS_I2C0
value|119
end_define

begin_define
define|#
directive|define
name|CLK_BUS_I2C1
value|120
end_define

begin_define
define|#
directive|define
name|CLK_BUS_I2C2
value|121
end_define

begin_define
define|#
directive|define
name|CLK_BUS_I2C3
value|122
end_define

begin_define
define|#
directive|define
name|CLK_BUS_I2C4
value|123
end_define

begin_define
define|#
directive|define
name|CLK_BUS_UART0
value|124
end_define

begin_define
define|#
directive|define
name|CLK_BUS_UART1
value|125
end_define

begin_define
define|#
directive|define
name|CLK_BUS_UART2
value|126
end_define

begin_define
define|#
directive|define
name|CLK_BUS_UART3
value|127
end_define

begin_define
define|#
directive|define
name|CLK_BUS_UART4
value|128
end_define

begin_define
define|#
directive|define
name|CLK_BUS_UART5
value|129
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_CLOCK_SUN9I_A80_CCU_H_ */
end_comment

end_unit

