begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2015 Freescale Semiconductor, Inc.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_CLOCK_IMX6UL_H
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_CLOCK_IMX6UL_H
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_DUMMY
value|0
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_CKIL
value|1
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_CKIH
value|2
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_OSC
value|3
end_define

begin_define
define|#
directive|define
name|IMX6UL_PLL1_BYPASS_SRC
value|4
end_define

begin_define
define|#
directive|define
name|IMX6UL_PLL2_BYPASS_SRC
value|5
end_define

begin_define
define|#
directive|define
name|IMX6UL_PLL3_BYPASS_SRC
value|6
end_define

begin_define
define|#
directive|define
name|IMX6UL_PLL4_BYPASS_SRC
value|7
end_define

begin_define
define|#
directive|define
name|IMX6UL_PLL5_BYPASS_SRC
value|8
end_define

begin_define
define|#
directive|define
name|IMX6UL_PLL6_BYPASS_SRC
value|9
end_define

begin_define
define|#
directive|define
name|IMX6UL_PLL7_BYPASS_SRC
value|10
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PLL1
value|11
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PLL2
value|12
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PLL3
value|13
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PLL4
value|14
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PLL5
value|15
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PLL6
value|16
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PLL7
value|17
end_define

begin_define
define|#
directive|define
name|IMX6UL_PLL1_BYPASS
value|18
end_define

begin_define
define|#
directive|define
name|IMX6UL_PLL2_BYPASS
value|19
end_define

begin_define
define|#
directive|define
name|IMX6UL_PLL3_BYPASS
value|20
end_define

begin_define
define|#
directive|define
name|IMX6UL_PLL4_BYPASS
value|21
end_define

begin_define
define|#
directive|define
name|IMX6UL_PLL5_BYPASS
value|22
end_define

begin_define
define|#
directive|define
name|IMX6UL_PLL6_BYPASS
value|23
end_define

begin_define
define|#
directive|define
name|IMX6UL_PLL7_BYPASS
value|24
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PLL1_SYS
value|25
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PLL2_BUS
value|26
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PLL3_USB_OTG
value|27
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PLL4_AUDIO
value|28
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PLL5_VIDEO
value|29
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PLL6_ENET
value|30
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PLL7_USB_HOST
value|31
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_USBPHY1
value|32
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_USBPHY2
value|33
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_USBPHY1_GATE
value|34
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_USBPHY2_GATE
value|35
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PLL2_PFD0
value|36
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PLL2_PFD1
value|37
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PLL2_PFD2
value|38
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PLL2_PFD3
value|39
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PLL3_PFD0
value|40
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PLL3_PFD1
value|41
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PLL3_PFD2
value|42
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PLL3_PFD3
value|43
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_ENET_REF
value|44
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_ENET2_REF
value|45
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_ENET2_REF_125M
value|46
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_ENET_PTP_REF
value|47
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_ENET_PTP
value|48
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PLL4_POST_DIV
value|49
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PLL4_AUDIO_DIV
value|50
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PLL5_POST_DIV
value|51
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PLL5_VIDEO_DIV
value|52
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PLL2_198M
value|53
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PLL3_80M
value|54
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PLL3_60M
value|55
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_STEP
value|56
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PLL1_SW
value|57
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_AXI_ALT_SEL
value|58
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_AXI_SEL
value|59
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PERIPH_PRE
value|60
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PERIPH2_PRE
value|61
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PERIPH_CLK2_SEL
value|62
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PERIPH2_CLK2_SEL
value|63
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_USDHC1_SEL
value|64
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_USDHC2_SEL
value|65
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_BCH_SEL
value|66
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_GPMI_SEL
value|67
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_EIM_SLOW_SEL
value|68
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_SPDIF_SEL
value|69
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_SAI1_SEL
value|70
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_SAI2_SEL
value|71
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_SAI3_SEL
value|72
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_LCDIF_PRE_SEL
value|73
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_SIM_PRE_SEL
value|74
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_LDB_DI0_SEL
value|75
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_LDB_DI1_SEL
value|76
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_ENFC_SEL
value|77
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_CAN_SEL
value|78
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_ECSPI_SEL
value|79
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_UART_SEL
value|80
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_QSPI1_SEL
value|81
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PERCLK_SEL
value|82
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_LCDIF_SEL
value|83
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_SIM_SEL
value|84
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PERIPH
value|85
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PERIPH2
value|86
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_LDB_DI0_DIV_3_5
value|87
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_LDB_DI0_DIV_7
value|88
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_LDB_DI1_DIV_3_5
value|89
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_LDB_DI1_DIV_7
value|90
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_LDB_DI0_DIV_SEL
value|91
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_LDB_DI1_DIV_SEL
value|92
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_ARM
value|93
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PERIPH_CLK2
value|94
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PERIPH2_CLK2
value|95
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_AHB
value|96
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_MMDC_PODF
value|97
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_AXI_PODF
value|98
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PERCLK
value|99
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_IPG
value|100
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_USDHC1_PODF
value|101
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_USDHC2_PODF
value|102
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_BCH_PODF
value|103
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_GPMI_PODF
value|104
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_EIM_SLOW_PODF
value|105
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_SPDIF_PRED
value|106
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_SPDIF_PODF
value|107
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_SAI1_PRED
value|108
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_SAI1_PODF
value|109
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_SAI2_PRED
value|110
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_SAI2_PODF
value|111
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_SAI3_PRED
value|112
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_SAI3_PODF
value|113
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_LCDIF_PRED
value|114
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_LCDIF_PODF
value|115
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_SIM_PODF
value|116
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_QSPI1_PDOF
value|117
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_ENFC_PRED
value|118
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_ENFC_PODF
value|119
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_CAN_PODF
value|120
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_ECSPI_PODF
value|121
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_UART_PODF
value|122
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_ADC1
value|123
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_ADC2
value|124
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_AIPSTZ1
value|125
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_AIPSTZ2
value|126
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_AIPSTZ3
value|127
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_APBHDMA
value|128
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_ASRC_IPG
value|129
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_ASRC_MEM
value|130
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_GPMI_BCH_APB
value|131
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_GPMI_BCH
value|132
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_GPMI_IO
value|133
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_GPMI_APB
value|134
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_CAAM_MEM
value|135
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_CAAM_ACLK
value|136
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_CAAM_IPG
value|137
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_CSI
value|138
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_ECSPI1
value|139
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_ECSPI2
value|140
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_ECSPI3
value|141
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_ECSPI4
value|142
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_EIM
value|143
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_ENET
value|144
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_ENET_AHB
value|145
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_EPIT1
value|146
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_EPIT2
value|147
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_CAN1_IPG
value|148
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_CAN1_SERIAL
value|149
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_CAN2_IPG
value|150
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_CAN2_SERIAL
value|151
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_GPT1_BUS
value|152
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_GPT1_SERIAL
value|153
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_GPT2_BUS
value|154
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_GPT2_SERIAL
value|155
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_I2C1
value|156
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_I2C2
value|157
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_I2C3
value|158
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_I2C4
value|159
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_IOMUXC
value|160
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_LCDIF_APB
value|161
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_LCDIF_PIX
value|162
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_MMDC_P0_FAST
value|163
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_MMDC_P0_IPG
value|164
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_OCOTP
value|165
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_OCRAM
value|166
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PWM1
value|167
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PWM2
value|168
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PWM3
value|169
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PWM4
value|170
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PWM5
value|171
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PWM6
value|172
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PWM7
value|173
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PWM8
value|174
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PXP
value|175
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_QSPI
value|176
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_ROM
value|177
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_SAI1
value|178
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_SAI1_IPG
value|179
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_SAI2
value|180
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_SAI2_IPG
value|181
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_SAI3
value|182
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_SAI3_IPG
value|183
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_SDMA
value|184
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_SIM
value|185
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_SIM_S
value|186
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_SPBA
value|187
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_SPDIF
value|188
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_UART1_IPG
value|189
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_UART1_SERIAL
value|190
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_UART2_IPG
value|191
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_UART2_SERIAL
value|192
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_UART3_IPG
value|193
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_UART3_SERIAL
value|194
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_UART4_IPG
value|195
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_UART4_SERIAL
value|196
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_UART5_IPG
value|197
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_UART5_SERIAL
value|198
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_UART6_IPG
value|199
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_UART6_SERIAL
value|200
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_UART7_IPG
value|201
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_UART7_SERIAL
value|202
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_UART8_IPG
value|203
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_UART8_SERIAL
value|204
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_USBOH3
value|205
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_USDHC1
value|206
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_USDHC2
value|207
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_WDOG1
value|208
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_WDOG2
value|209
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_WDOG3
value|210
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_LDB_DI0
value|211
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_AXI
value|212
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_SPDIF_GCLK
value|213
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_GPT_3M
value|214
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_SIM2
value|215
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_SIM1
value|216
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_IPP_DI0
value|217
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_IPP_DI1
value|218
end_define

begin_define
define|#
directive|define
name|IMX6UL_CA7_SECONDARY_SEL
value|219
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PER_BCH
value|220
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_CSI_SEL
value|221
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_CSI_PODF
value|222
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_PLL3_120M
value|223
end_define

begin_define
define|#
directive|define
name|IMX6UL_CLK_END
value|224
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DT_BINDINGS_CLOCK_IMX6UL_H */
end_comment

end_unit

