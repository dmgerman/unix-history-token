begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2013 Freescale Semiconductor, Inc.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_CLOCK_IMX6SL_H
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_CLOCK_IMX6SL_H
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_DUMMY
value|0
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_CKIL
value|1
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_OSC
value|2
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_PLL1_SYS
value|3
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_PLL2_BUS
value|4
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_PLL3_USB_OTG
value|5
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_PLL4_AUDIO
value|6
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_PLL5_VIDEO
value|7
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_PLL6_ENET
value|8
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_PLL7_USB_HOST
value|9
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_USBPHY1
value|10
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_USBPHY2
value|11
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_USBPHY1_GATE
value|12
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_USBPHY2_GATE
value|13
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_PLL4_POST_DIV
value|14
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_PLL5_POST_DIV
value|15
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_PLL5_VIDEO_DIV
value|16
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_ENET_REF
value|17
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_PLL2_PFD0
value|18
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_PLL2_PFD1
value|19
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_PLL2_PFD2
value|20
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_PLL3_PFD0
value|21
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_PLL3_PFD1
value|22
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_PLL3_PFD2
value|23
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_PLL3_PFD3
value|24
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_PLL2_198M
value|25
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_PLL3_120M
value|26
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_PLL3_80M
value|27
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_PLL3_60M
value|28
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_STEP
value|29
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_PLL1_SW
value|30
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_OCRAM_ALT_SEL
value|31
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_OCRAM_SEL
value|32
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_PRE_PERIPH2_SEL
value|33
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_PRE_PERIPH_SEL
value|34
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_PERIPH2_CLK2_SEL
value|35
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_PERIPH_CLK2_SEL
value|36
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_CSI_SEL
value|37
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_LCDIF_AXI_SEL
value|38
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_USDHC1_SEL
value|39
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_USDHC2_SEL
value|40
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_USDHC3_SEL
value|41
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_USDHC4_SEL
value|42
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_SSI1_SEL
value|43
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_SSI2_SEL
value|44
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_SSI3_SEL
value|45
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_PERCLK_SEL
value|46
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_PXP_AXI_SEL
value|47
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_EPDC_AXI_SEL
value|48
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_GPU2D_OVG_SEL
value|49
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_GPU2D_SEL
value|50
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_LCDIF_PIX_SEL
value|51
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_EPDC_PIX_SEL
value|52
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_SPDIF0_SEL
value|53
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_SPDIF1_SEL
value|54
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_EXTERN_AUDIO_SEL
value|55
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_ECSPI_SEL
value|56
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_UART_SEL
value|57
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_PERIPH
value|58
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_PERIPH2
value|59
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_OCRAM_PODF
value|60
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_PERIPH_CLK2_PODF
value|61
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_PERIPH2_CLK2_PODF
value|62
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_IPG
value|63
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_CSI_PODF
value|64
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_LCDIF_AXI_PODF
value|65
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_USDHC1_PODF
value|66
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_USDHC2_PODF
value|67
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_USDHC3_PODF
value|68
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_USDHC4_PODF
value|69
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_SSI1_PRED
value|70
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_SSI1_PODF
value|71
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_SSI2_PRED
value|72
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_SSI2_PODF
value|73
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_SSI3_PRED
value|74
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_SSI3_PODF
value|75
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_PERCLK
value|76
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_PXP_AXI_PODF
value|77
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_EPDC_AXI_PODF
value|78
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_GPU2D_OVG_PODF
value|79
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_GPU2D_PODF
value|80
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_LCDIF_PIX_PRED
value|81
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_EPDC_PIX_PRED
value|82
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_LCDIF_PIX_PODF
value|83
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_EPDC_PIX_PODF
value|84
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_SPDIF0_PRED
value|85
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_SPDIF0_PODF
value|86
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_SPDIF1_PRED
value|87
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_SPDIF1_PODF
value|88
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_EXTERN_AUDIO_PRED
value|89
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_EXTERN_AUDIO_PODF
value|90
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_ECSPI_ROOT
value|91
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_UART_ROOT
value|92
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_AHB
value|93
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_MMDC_ROOT
value|94
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_ARM
value|95
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_ECSPI1
value|96
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_ECSPI2
value|97
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_ECSPI3
value|98
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_ECSPI4
value|99
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_EPIT1
value|100
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_EPIT2
value|101
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_EXTERN_AUDIO
value|102
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_GPT
value|103
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_GPT_SERIAL
value|104
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_GPU2D_OVG
value|105
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_I2C1
value|106
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_I2C2
value|107
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_I2C3
value|108
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_OCOTP
value|109
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_CSI
value|110
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_PXP_AXI
value|111
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_EPDC_AXI
value|112
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_LCDIF_AXI
value|113
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_LCDIF_PIX
value|114
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_EPDC_PIX
value|115
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_OCRAM
value|116
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_PWM1
value|117
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_PWM2
value|118
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_PWM3
value|119
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_PWM4
value|120
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_SDMA
value|121
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_SPDIF
value|122
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_SSI1
value|123
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_SSI2
value|124
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_SSI3
value|125
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_UART
value|126
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_UART_SERIAL
value|127
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_USBOH3
value|128
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_USDHC1
value|129
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_USDHC2
value|130
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_USDHC3
value|131
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_USDHC4
value|132
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_PLL4_AUDIO_DIV
value|133
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_SPBA
value|134
end_define

begin_define
define|#
directive|define
name|IMX6SL_CLK_END
value|135
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DT_BINDINGS_CLOCK_IMX6SL_H */
end_comment

end_unit

