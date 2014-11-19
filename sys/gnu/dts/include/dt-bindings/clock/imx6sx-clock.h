begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2014 Freescale Semiconductor, Inc.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_CLOCK_IMX6SX_H
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_CLOCK_IMX6SX_H
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_DUMMY
value|0
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_CKIL
value|1
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_CKIH
value|2
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_OSC
value|3
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PLL1_SYS
value|4
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PLL2_BUS
value|5
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PLL3_USB_OTG
value|6
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PLL4_AUDIO
value|7
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PLL5_VIDEO
value|8
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PLL6_ENET
value|9
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PLL7_USB_HOST
value|10
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_USBPHY1
value|11
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_USBPHY2
value|12
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_USBPHY1_GATE
value|13
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_USBPHY2_GATE
value|14
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PCIE_REF
value|15
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PCIE_REF_125M
value|16
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_ENET_REF
value|17
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PLL2_PFD0
value|18
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PLL2_PFD1
value|19
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PLL2_PFD2
value|20
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PLL2_PFD3
value|21
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PLL3_PFD0
value|22
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PLL3_PFD1
value|23
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PLL3_PFD2
value|24
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PLL3_PFD3
value|25
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PLL2_198M
value|26
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PLL3_120M
value|27
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PLL3_80M
value|28
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PLL3_60M
value|29
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_TWD
value|30
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PLL4_POST_DIV
value|31
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PLL4_AUDIO_DIV
value|32
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PLL5_POST_DIV
value|33
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PLL5_VIDEO_DIV
value|34
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_STEP
value|35
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PLL1_SW
value|36
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_OCRAM_SEL
value|37
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PERIPH_PRE
value|38
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PERIPH2_PRE
value|39
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PERIPH_CLK2_SEL
value|40
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PERIPH2_CLK2_SEL
value|41
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PCIE_AXI_SEL
value|42
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_GPU_AXI_SEL
value|43
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_GPU_CORE_SEL
value|44
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_EIM_SLOW_SEL
value|45
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_USDHC1_SEL
value|46
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_USDHC2_SEL
value|47
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_USDHC3_SEL
value|48
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_USDHC4_SEL
value|49
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_SSI1_SEL
value|50
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_SSI2_SEL
value|51
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_SSI3_SEL
value|52
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_QSPI1_SEL
value|53
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PERCLK_SEL
value|54
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_VID_SEL
value|55
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_ESAI_SEL
value|56
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_LDB_DI0_DIV_SEL
value|57
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_LDB_DI1_DIV_SEL
value|58
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_CAN_SEL
value|59
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_UART_SEL
value|60
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_QSPI2_SEL
value|61
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_LDB_DI1_SEL
value|62
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_LDB_DI0_SEL
value|63
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_SPDIF_SEL
value|64
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_AUDIO_SEL
value|65
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_ENET_PRE_SEL
value|66
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_ENET_SEL
value|67
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_M4_PRE_SEL
value|68
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_M4_SEL
value|69
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_ECSPI_SEL
value|70
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_LCDIF1_PRE_SEL
value|71
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_LCDIF2_PRE_SEL
value|72
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_LCDIF1_SEL
value|73
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_LCDIF2_SEL
value|74
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_DISPLAY_SEL
value|75
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_CSI_SEL
value|76
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_CKO1_SEL
value|77
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_CKO2_SEL
value|78
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_CKO
value|79
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PERIPH_CLK2
value|80
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PERIPH2_CLK2
value|81
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_IPG
value|82
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_GPU_CORE_PODF
value|83
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_GPU_AXI_PODF
value|84
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_LCDIF1_PODF
value|85
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_QSPI1_PODF
value|86
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_EIM_SLOW_PODF
value|87
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_LCDIF2_PODF
value|88
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PERCLK
value|89
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_VID_PODF
value|90
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_CAN_PODF
value|91
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_USDHC1_PODF
value|92
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_USDHC2_PODF
value|93
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_USDHC3_PODF
value|94
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_USDHC4_PODF
value|95
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_UART_PODF
value|96
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_ESAI_PRED
value|97
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_ESAI_PODF
value|98
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_SSI3_PRED
value|99
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_SSI3_PODF
value|100
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_SSI1_PRED
value|101
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_SSI1_PODF
value|102
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_QSPI2_PRED
value|103
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_QSPI2_PODF
value|104
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_SSI2_PRED
value|105
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_SSI2_PODF
value|106
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_SPDIF_PRED
value|107
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_SPDIF_PODF
value|108
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_AUDIO_PRED
value|109
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_AUDIO_PODF
value|110
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_ENET_PODF
value|111
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_M4_PODF
value|112
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_ECSPI_PODF
value|113
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_LCDIF1_PRED
value|114
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_LCDIF2_PRED
value|115
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_DISPLAY_PODF
value|116
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_CSI_PODF
value|117
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_LDB_DI0_DIV_3_5
value|118
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_LDB_DI0_DIV_7
value|119
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_LDB_DI1_DIV_3_5
value|120
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_LDB_DI1_DIV_7
value|121
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_CKO1_PODF
value|122
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_CKO2_PODF
value|123
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PERIPH
value|124
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PERIPH2
value|125
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_OCRAM
value|126
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_AHB
value|127
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_MMDC_PODF
value|128
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_ARM
value|129
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_AIPS_TZ1
value|130
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_AIPS_TZ2
value|131
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_APBH_DMA
value|132
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_ASRC_GATE
value|133
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_CAAM_MEM
value|134
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_CAAM_ACLK
value|135
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_CAAM_IPG
value|136
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_CAN1_IPG
value|137
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_CAN1_SERIAL
value|138
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_CAN2_IPG
value|139
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_CAN2_SERIAL
value|140
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_CPU_DEBUG
value|141
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_DCIC1
value|142
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_DCIC2
value|143
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_AIPS_TZ3
value|144
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_ECSPI1
value|145
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_ECSPI2
value|146
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_ECSPI3
value|147
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_ECSPI4
value|148
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_ECSPI5
value|149
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_EPIT1
value|150
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_EPIT2
value|151
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_ESAI_EXTAL
value|152
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_WAKEUP
value|153
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_GPT_BUS
value|154
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_GPT_SERIAL
value|155
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_GPU
value|156
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_OCRAM_S
value|157
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_CANFD
value|158
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_CSI
value|159
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_I2C1
value|160
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_I2C2
value|161
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_I2C3
value|162
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_OCOTP
value|163
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_IOMUXC
value|164
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_IPMUX1
value|165
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_IPMUX2
value|166
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_IPMUX3
value|167
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_TZASC1
value|168
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_LCDIF_APB
value|169
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PXP_AXI
value|170
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_M4
value|171
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_ENET
value|172
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_DISPLAY_AXI
value|173
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_LCDIF2_PIX
value|174
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_LCDIF1_PIX
value|175
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_LDB_DI0
value|176
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_QSPI1
value|177
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_MLB
value|178
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_MMDC_P0_FAST
value|179
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_MMDC_P0_IPG
value|180
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_AXI
value|181
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PCIE_AXI
value|182
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_QSPI2
value|183
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PER1_BCH
value|184
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PER2_MAIN
value|185
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PWM1
value|186
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PWM2
value|187
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PWM3
value|188
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PWM4
value|189
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_GPMI_BCH_APB
value|190
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_GPMI_BCH
value|191
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_GPMI_IO
value|192
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_GPMI_APB
value|193
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_ROM
value|194
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_SDMA
value|195
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_SPBA
value|196
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_SPDIF
value|197
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_SSI1_IPG
value|198
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_SSI2_IPG
value|199
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_SSI3_IPG
value|200
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_SSI1
value|201
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_SSI2
value|202
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_SSI3
value|203
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_UART_IPG
value|204
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_UART_SERIAL
value|205
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_SAI1
value|206
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_SAI2
value|207
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_USBOH3
value|208
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_USDHC1
value|209
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_USDHC2
value|210
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_USDHC3
value|211
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_USDHC4
value|212
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_EIM_SLOW
value|213
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PWM8
value|214
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_VADC
value|215
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_GIS
value|216
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_I2C4
value|217
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PWM5
value|218
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PWM6
value|219
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_PWM7
value|220
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_CKO1
value|221
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_CKO2
value|222
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_IPP_DI0
value|223
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_IPP_DI1
value|224
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_ENET_AHB
value|225
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_OCRAM_PODF
value|226
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_GPT_3M
value|227
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_ENET_PTP
value|228
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_ENET_PTP_REF
value|229
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_ENET2_REF
value|230
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_ENET2_REF_125M
value|231
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_AUDIO
value|232
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_LVDS1_SEL
value|233
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_LVDS1_OUT
value|234
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_ASRC_IPG
value|235
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_ASRC_MEM
value|236
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_SAI1_IPG
value|237
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_SAI2_IPG
value|238
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_ESAI_IPG
value|239
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_ESAI_MEM
value|240
end_define

begin_define
define|#
directive|define
name|IMX6SX_CLK_CLK_END
value|241
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DT_BINDINGS_CLOCK_IMX6SX_H */
end_comment

end_unit

