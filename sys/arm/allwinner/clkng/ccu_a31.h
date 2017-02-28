begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2017 Emmanuel Vadot<manu@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CCU_A31_H__
end_ifndef

begin_define
define|#
directive|define
name|__CCU_A31_H__
end_define

begin_define
define|#
directive|define
name|A31_RST_USB_PHY0
value|0
end_define

begin_define
define|#
directive|define
name|A31_RST_USB_PHY1
value|1
end_define

begin_define
define|#
directive|define
name|A31_RST_USB_PHY2
value|2
end_define

begin_define
define|#
directive|define
name|A31_RST_AHB1_MIPI_DSI
value|3
end_define

begin_define
define|#
directive|define
name|A31_RST_AHB1_SS
value|4
end_define

begin_define
define|#
directive|define
name|A31_RST_AHB1_DMA
value|5
end_define

begin_define
define|#
directive|define
name|A31_RST_AHB1_MMC0
value|6
end_define

begin_define
define|#
directive|define
name|A31_RST_AHB1_MMC1
value|7
end_define

begin_define
define|#
directive|define
name|A31_RST_AHB1_MMC2
value|8
end_define

begin_define
define|#
directive|define
name|A31_RST_AHB1_MMC3
value|9
end_define

begin_define
define|#
directive|define
name|A31_RST_AHB1_NAND1
value|10
end_define

begin_define
define|#
directive|define
name|A31_RST_AHB1_NAND0
value|11
end_define

begin_define
define|#
directive|define
name|A31_RST_AHB1_SDRAM
value|12
end_define

begin_define
define|#
directive|define
name|A31_RST_AHB1_EMAC
value|13
end_define

begin_define
define|#
directive|define
name|A31_RST_AHB1_TS
value|14
end_define

begin_define
define|#
directive|define
name|A31_RST_AHB1_HSTIMER
value|15
end_define

begin_define
define|#
directive|define
name|A31_RST_AHB1_SPI0
value|16
end_define

begin_define
define|#
directive|define
name|A31_RST_AHB1_SPI1
value|17
end_define

begin_define
define|#
directive|define
name|A31_RST_AHB1_SPI2
value|18
end_define

begin_define
define|#
directive|define
name|A31_RST_AHB1_SPI3
value|19
end_define

begin_define
define|#
directive|define
name|A31_RST_AHB1_OTG
value|20
end_define

begin_define
define|#
directive|define
name|A31_RST_AHB1_EHCI0
value|21
end_define

begin_define
define|#
directive|define
name|A31_RST_AHB1_EHCI1
value|22
end_define

begin_define
define|#
directive|define
name|A31_RST_AHB1_OHCI0
value|23
end_define

begin_define
define|#
directive|define
name|A31_RST_AHB1_OHCI1
value|24
end_define

begin_define
define|#
directive|define
name|A31_RST_AHB1_OHCI2
value|25
end_define

begin_define
define|#
directive|define
name|A31_RST_AHB1_VE
value|26
end_define

begin_define
define|#
directive|define
name|A31_RST_AHB1_LCD0
value|27
end_define

begin_define
define|#
directive|define
name|A31_RST_AHB1_LCD1
value|28
end_define

begin_define
define|#
directive|define
name|A31_RST_AHB1_CSI
value|29
end_define

begin_define
define|#
directive|define
name|A31_RST_AHB1_HDMI
value|30
end_define

begin_define
define|#
directive|define
name|A31_RST_AHB1_BE0
value|31
end_define

begin_define
define|#
directive|define
name|A31_RST_AHB1_BE1
value|32
end_define

begin_define
define|#
directive|define
name|A31_RST_AHB1_FE0
value|33
end_define

begin_define
define|#
directive|define
name|A31_RST_AHB1_FE1
value|34
end_define

begin_define
define|#
directive|define
name|A31_RST_AHB1_MP
value|35
end_define

begin_define
define|#
directive|define
name|A31_RST_AHB1_GPU
value|36
end_define

begin_define
define|#
directive|define
name|A31_RST_AHB1_DEU0
value|37
end_define

begin_define
define|#
directive|define
name|A31_RST_AHB1_DEU1
value|38
end_define

begin_define
define|#
directive|define
name|A31_RST_AHB1_DRC0
value|39
end_define

begin_define
define|#
directive|define
name|A31_RST_AHB1_DRC1
value|40
end_define

begin_define
define|#
directive|define
name|A31_RST_AHB1_LVDS
value|41
end_define

begin_define
define|#
directive|define
name|A31_RST_APB1_CODEC
value|42
end_define

begin_define
define|#
directive|define
name|A31_RST_APB1_SPDIF
value|43
end_define

begin_define
define|#
directive|define
name|A31_RST_APB1_DIGITAL_MIC
value|44
end_define

begin_define
define|#
directive|define
name|A31_RST_APB1_DAUDIO0
value|45
end_define

begin_define
define|#
directive|define
name|A31_RST_APB1_DAUDIO1
value|46
end_define

begin_define
define|#
directive|define
name|A31_RST_APB2_I2C0
value|47
end_define

begin_define
define|#
directive|define
name|A31_RST_APB2_I2C1
value|48
end_define

begin_define
define|#
directive|define
name|A31_RST_APB2_I2C2
value|49
end_define

begin_define
define|#
directive|define
name|A31_RST_APB2_I2C3
value|50
end_define

begin_define
define|#
directive|define
name|A31_RST_APB2_UART0
value|51
end_define

begin_define
define|#
directive|define
name|A31_RST_APB2_UART1
value|52
end_define

begin_define
define|#
directive|define
name|A31_RST_APB2_UART2
value|53
end_define

begin_define
define|#
directive|define
name|A31_RST_APB2_UART3
value|54
end_define

begin_define
define|#
directive|define
name|A31_RST_APB2_UART4
value|55
end_define

begin_define
define|#
directive|define
name|A31_RST_APB2_UART5
value|56
end_define

begin_define
define|#
directive|define
name|A31_CLK_PLL_CPU
value|0
end_define

begin_define
define|#
directive|define
name|A31_CLK_PLL_AUDIO_BASE
value|1
end_define

begin_define
define|#
directive|define
name|A31_CLK_PLL_AUDIO
value|2
end_define

begin_define
define|#
directive|define
name|A31_CLK_PLL_AUDIO_2X
value|3
end_define

begin_define
define|#
directive|define
name|A31_CLK_PLL_AUDIO_4X
value|4
end_define

begin_define
define|#
directive|define
name|A31_CLK_PLL_AUDIO_8X
value|5
end_define

begin_define
define|#
directive|define
name|A31_CLK_PLL_VIDEO0
value|6
end_define

begin_define
define|#
directive|define
name|A31_CLK_PLL_VIDEO0_2X
value|7
end_define

begin_define
define|#
directive|define
name|A31_CLK_PLL_VE
value|8
end_define

begin_define
define|#
directive|define
name|A31_CLK_PLL_DDR
value|9
end_define

begin_define
define|#
directive|define
name|A31_CLK_PLL_PERIPH
value|10
end_define

begin_define
define|#
directive|define
name|A31_CLK_PLL_PERIPH_2X
value|11
end_define

begin_define
define|#
directive|define
name|A31_CLK_PLL_VIDEO1
value|12
end_define

begin_define
define|#
directive|define
name|A31_CLK_PLL_VIDEO1_2X
value|13
end_define

begin_define
define|#
directive|define
name|A31_CLK_PLL_GPU
value|14
end_define

begin_define
define|#
directive|define
name|A31_CLK_PLL_MIPI
value|15
end_define

begin_define
define|#
directive|define
name|A31_CLK_PLL9
value|16
end_define

begin_define
define|#
directive|define
name|A31_CLK_PLL10
value|17
end_define

begin_define
define|#
directive|define
name|A31_CLK_CPU
value|18
end_define

begin_define
define|#
directive|define
name|A31_CLK_AXI
value|19
end_define

begin_define
define|#
directive|define
name|A31_CLK_AHB1
value|20
end_define

begin_define
define|#
directive|define
name|A31_CLK_APB1
value|21
end_define

begin_define
define|#
directive|define
name|A31_CLK_APB2
value|22
end_define

begin_define
define|#
directive|define
name|A31_CLK_AHB1_MIPIDSI
value|23
end_define

begin_define
define|#
directive|define
name|A31_CLK_AHB1_SS
value|24
end_define

begin_define
define|#
directive|define
name|A31_CLK_AHB1_DMA
value|25
end_define

begin_define
define|#
directive|define
name|A31_CLK_AHB1_MMC0
value|26
end_define

begin_define
define|#
directive|define
name|A31_CLK_AHB1_MMC1
value|27
end_define

begin_define
define|#
directive|define
name|A31_CLK_AHB1_MMC2
value|28
end_define

begin_define
define|#
directive|define
name|A31_CLK_AHB1_MMC3
value|29
end_define

begin_define
define|#
directive|define
name|A31_CLK_AHB1_NAND1
value|30
end_define

begin_define
define|#
directive|define
name|A31_CLK_AHB1_NAND0
value|31
end_define

begin_define
define|#
directive|define
name|A31_CLK_AHB1_SDRAM
value|32
end_define

begin_define
define|#
directive|define
name|A31_CLK_AHB1_EMAC
value|33
end_define

begin_define
define|#
directive|define
name|A31_CLK_AHB1_TS
value|34
end_define

begin_define
define|#
directive|define
name|A31_CLK_AHB1_HSTIMER
value|35
end_define

begin_define
define|#
directive|define
name|A31_CLK_AHB1_SPI0
value|36
end_define

begin_define
define|#
directive|define
name|A31_CLK_AHB1_SPI1
value|37
end_define

begin_define
define|#
directive|define
name|A31_CLK_AHB1_SPI2
value|38
end_define

begin_define
define|#
directive|define
name|A31_CLK_AHB1_SPI3
value|39
end_define

begin_define
define|#
directive|define
name|A31_CLK_AHB1_OTG
value|40
end_define

begin_define
define|#
directive|define
name|A31_CLK_AHB1_EHCI0
value|41
end_define

begin_define
define|#
directive|define
name|A31_CLK_AHB1_EHCI1
value|42
end_define

begin_define
define|#
directive|define
name|A31_CLK_AHB1_OHCI0
value|43
end_define

begin_define
define|#
directive|define
name|A31_CLK_AHB1_OHCI1
value|44
end_define

begin_define
define|#
directive|define
name|A31_CLK_AHB1_OHCI2
value|45
end_define

begin_define
define|#
directive|define
name|A31_CLK_AHB1_VE
value|46
end_define

begin_define
define|#
directive|define
name|A31_CLK_AHB1_LCD0
value|47
end_define

begin_define
define|#
directive|define
name|A31_CLK_AHB1_LCD1
value|48
end_define

begin_define
define|#
directive|define
name|A31_CLK_AHB1_CSI
value|49
end_define

begin_define
define|#
directive|define
name|A31_CLK_AHB1_HDMI
value|50
end_define

begin_define
define|#
directive|define
name|A31_CLK_AHB1_BE0
value|51
end_define

begin_define
define|#
directive|define
name|A31_CLK_AHB1_BE1
value|52
end_define

begin_define
define|#
directive|define
name|A31_CLK_AHB1_FE0
value|53
end_define

begin_define
define|#
directive|define
name|A31_CLK_AHB1_FE1
value|54
end_define

begin_define
define|#
directive|define
name|A31_CLK_AHB1_MP
value|55
end_define

begin_define
define|#
directive|define
name|A31_CLK_AHB1_GPU
value|56
end_define

begin_define
define|#
directive|define
name|A31_CLK_AHB1_DEU0
value|57
end_define

begin_define
define|#
directive|define
name|A31_CLK_AHB1_DEU1
value|58
end_define

begin_define
define|#
directive|define
name|A31_CLK_AHB1_DRC0
value|59
end_define

begin_define
define|#
directive|define
name|A31_CLK_AHB1_DRC1
value|60
end_define

begin_define
define|#
directive|define
name|A31_CLK_APB1_CODEC
value|61
end_define

begin_define
define|#
directive|define
name|A31_CLK_APB1_SPDIF
value|62
end_define

begin_define
define|#
directive|define
name|A31_CLK_APB1_DIGITAL_MIC
value|63
end_define

begin_define
define|#
directive|define
name|A31_CLK_APB1_PIO
value|64
end_define

begin_define
define|#
directive|define
name|A31_CLK_APB1_DAUDIO0
value|65
end_define

begin_define
define|#
directive|define
name|A31_CLK_APB1_DAUDIO1
value|66
end_define

begin_define
define|#
directive|define
name|A31_CLK_APB2_I2C0
value|67
end_define

begin_define
define|#
directive|define
name|A31_CLK_APB2_I2C1
value|68
end_define

begin_define
define|#
directive|define
name|A31_CLK_APB2_I2C2
value|69
end_define

begin_define
define|#
directive|define
name|A31_CLK_APB2_I2C3
value|70
end_define

begin_define
define|#
directive|define
name|A31_CLK_APB2_UART0
value|71
end_define

begin_define
define|#
directive|define
name|A31_CLK_APB2_UART1
value|72
end_define

begin_define
define|#
directive|define
name|A31_CLK_APB2_UART2
value|73
end_define

begin_define
define|#
directive|define
name|A31_CLK_APB2_UART3
value|74
end_define

begin_define
define|#
directive|define
name|A31_CLK_APB2_UART4
value|75
end_define

begin_define
define|#
directive|define
name|A31_CLK_APB2_UART5
value|76
end_define

begin_define
define|#
directive|define
name|A31_CLK_NAND0
value|77
end_define

begin_define
define|#
directive|define
name|A31_CLK_NAND1
value|78
end_define

begin_define
define|#
directive|define
name|A31_CLK_MMC0
value|79
end_define

begin_define
define|#
directive|define
name|A31_CLK_MMC0_SAMPLE
value|80
end_define

begin_define
define|#
directive|define
name|A31_CLK_MMC0_OUTPUT
value|81
end_define

begin_define
define|#
directive|define
name|A31_CLK_MMC1
value|82
end_define

begin_define
define|#
directive|define
name|A31_CLK_MMC1_SAMPLE
value|83
end_define

begin_define
define|#
directive|define
name|A31_CLK_MMC1_OUTPUT
value|84
end_define

begin_define
define|#
directive|define
name|A31_CLK_MMC2
value|85
end_define

begin_define
define|#
directive|define
name|A31_CLK_MMC2_SAMPLE
value|86
end_define

begin_define
define|#
directive|define
name|A31_CLK_MMC2_OUTPUT
value|87
end_define

begin_define
define|#
directive|define
name|A31_CLK_MMC3
value|88
end_define

begin_define
define|#
directive|define
name|A31_CLK_MMC3_SAMPLE
value|89
end_define

begin_define
define|#
directive|define
name|A31_CLK_MMC3_OUTPUT
value|90
end_define

begin_define
define|#
directive|define
name|A31_CLK_TS
value|91
end_define

begin_define
define|#
directive|define
name|A31_CLK_SS
value|92
end_define

begin_define
define|#
directive|define
name|A31_CLK_SPI0
value|93
end_define

begin_define
define|#
directive|define
name|A31_CLK_SPI1
value|94
end_define

begin_define
define|#
directive|define
name|A31_CLK_SPI2
value|95
end_define

begin_define
define|#
directive|define
name|A31_CLK_SPI3
value|96
end_define

begin_define
define|#
directive|define
name|A31_CLK_DAUDIO0
value|97
end_define

begin_define
define|#
directive|define
name|A31_CLK_DAUDIO1
value|98
end_define

begin_define
define|#
directive|define
name|A31_CLK_SPDIF
value|99
end_define

begin_define
define|#
directive|define
name|A31_CLK_USB_PHY0
value|100
end_define

begin_define
define|#
directive|define
name|A31_CLK_USB_PHY1
value|101
end_define

begin_define
define|#
directive|define
name|A31_CLK_USB_PHY2
value|102
end_define

begin_define
define|#
directive|define
name|A31_CLK_USB_OHCI0
value|103
end_define

begin_define
define|#
directive|define
name|A31_CLK_USB_OHCI1
value|104
end_define

begin_define
define|#
directive|define
name|A31_CLK_USB_OHCI2
value|105
end_define

begin_define
define|#
directive|define
name|A31_CLK_MDFS
value|107
end_define

begin_define
define|#
directive|define
name|A31_CLK_SDRAM0
value|108
end_define

begin_define
define|#
directive|define
name|A31_CLK_SDRAM1
value|109
end_define

begin_define
define|#
directive|define
name|A31_CLK_DRAM_VE
value|110
end_define

begin_define
define|#
directive|define
name|A31_CLK_DRAM_CSI_ISP
value|111
end_define

begin_define
define|#
directive|define
name|A31_CLK_DRAM_TS
value|112
end_define

begin_define
define|#
directive|define
name|A31_CLK_DRAM_DRC0
value|113
end_define

begin_define
define|#
directive|define
name|A31_CLK_DRAM_DRC1
value|114
end_define

begin_define
define|#
directive|define
name|A31_CLK_DRAM_DEU0
value|115
end_define

begin_define
define|#
directive|define
name|A31_CLK_DRAM_DEU1
value|116
end_define

begin_define
define|#
directive|define
name|A31_CLK_DRAM_FE0
value|117
end_define

begin_define
define|#
directive|define
name|A31_CLK_DRAM_FE1
value|118
end_define

begin_define
define|#
directive|define
name|A31_CLK_DRAM_BE0
value|119
end_define

begin_define
define|#
directive|define
name|A31_CLK_DRAM_BE1
value|120
end_define

begin_define
define|#
directive|define
name|A31_CLK_DRAM_MP
value|121
end_define

begin_define
define|#
directive|define
name|A31_CLK_BE0
value|122
end_define

begin_define
define|#
directive|define
name|A31_CLK_BE1
value|123
end_define

begin_define
define|#
directive|define
name|A31_CLK_FE0
value|124
end_define

begin_define
define|#
directive|define
name|A31_CLK_FE1
value|125
end_define

begin_define
define|#
directive|define
name|A31_CLK_MP
value|126
end_define

begin_define
define|#
directive|define
name|A31_CLK_LCD0_CH0
value|127
end_define

begin_define
define|#
directive|define
name|A31_CLK_LCD1_CH0
value|128
end_define

begin_define
define|#
directive|define
name|A31_CLK_LCD0_CH1
value|129
end_define

begin_define
define|#
directive|define
name|A31_CLK_LCD1_CH1
value|130
end_define

begin_define
define|#
directive|define
name|A31_CLK_CSI0_SCLK
value|131
end_define

begin_define
define|#
directive|define
name|A31_CLK_CSI0_MCLK
value|132
end_define

begin_define
define|#
directive|define
name|A31_CLK_CSI1_MCLK
value|133
end_define

begin_define
define|#
directive|define
name|A31_CLK_VE
value|134
end_define

begin_define
define|#
directive|define
name|A31_CLK_CODEC
value|135
end_define

begin_define
define|#
directive|define
name|A31_CLK_AVS
value|136
end_define

begin_define
define|#
directive|define
name|A31_CLK_DIGITAL_MIC
value|137
end_define

begin_define
define|#
directive|define
name|A31_CLK_HDMI
value|138
end_define

begin_define
define|#
directive|define
name|A31_CLK_HDMI_DDC
value|139
end_define

begin_define
define|#
directive|define
name|A31_CLK_PS
value|140
end_define

begin_define
define|#
directive|define
name|A31_CLK_MBUS0
value|141
end_define

begin_define
define|#
directive|define
name|A31_CLK_MBUS1
value|142
end_define

begin_define
define|#
directive|define
name|A31_CLK_MIPI_DSI
value|143
end_define

begin_define
define|#
directive|define
name|A31_CLK_MIPI_DSI_DPHY
value|144
end_define

begin_define
define|#
directive|define
name|A31_CLK_MIPI_CSI_DPHY
value|145
end_define

begin_define
define|#
directive|define
name|A31_CLK_IEP_DRC0
value|146
end_define

begin_define
define|#
directive|define
name|A31_CLK_IEP_DRC1
value|147
end_define

begin_define
define|#
directive|define
name|A31_CLK_IEP_DEU0
value|148
end_define

begin_define
define|#
directive|define
name|A31_CLK_IEP_DEU1
value|149
end_define

begin_define
define|#
directive|define
name|A31_CLK_GPU_CORE
value|150
end_define

begin_define
define|#
directive|define
name|A31_CLK_GPU_MEMORY
value|151
end_define

begin_define
define|#
directive|define
name|A31_CLK_GPU_HYD
value|152
end_define

begin_define
define|#
directive|define
name|A31_CLK_ATS
value|153
end_define

begin_define
define|#
directive|define
name|A31_CLK_TRACE
value|154
end_define

begin_define
define|#
directive|define
name|A31_CLK_OUT_A
value|155
end_define

begin_define
define|#
directive|define
name|A31_CLK_OUT_B
value|156
end_define

begin_define
define|#
directive|define
name|A31_CLK_OUT_C
value|157
end_define

begin_function_decl
name|void
name|ccu_a31_register_clocks
parameter_list|(
name|struct
name|aw_ccung_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __CCU_A31		H__ */
end_comment

end_unit

