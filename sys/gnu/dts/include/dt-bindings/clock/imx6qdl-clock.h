begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2014 Freescale Semiconductor, Inc.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_CLOCK_IMX6QDL_H
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_CLOCK_IMX6QDL_H
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_DUMMY
value|0
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_CKIL
value|1
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_CKIH
value|2
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_OSC
value|3
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_PLL2_PFD0_352M
value|4
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_PLL2_PFD1_594M
value|5
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_PLL2_PFD2_396M
value|6
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_PLL3_PFD0_720M
value|7
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_PLL3_PFD1_540M
value|8
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_PLL3_PFD2_508M
value|9
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_PLL3_PFD3_454M
value|10
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_PLL2_198M
value|11
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_PLL3_120M
value|12
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_PLL3_80M
value|13
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_PLL3_60M
value|14
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_TWD
value|15
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_STEP
value|16
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_PLL1_SW
value|17
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_PERIPH_PRE
value|18
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_PERIPH2_PRE
value|19
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_PERIPH_CLK2_SEL
value|20
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_PERIPH2_CLK2_SEL
value|21
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_AXI_SEL
value|22
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_ESAI_SEL
value|23
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_ASRC_SEL
value|24
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_SPDIF_SEL
value|25
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_GPU2D_AXI
value|26
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_GPU3D_AXI
value|27
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_GPU2D_CORE_SEL
value|28
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_GPU3D_CORE_SEL
value|29
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_GPU3D_SHADER_SEL
value|30
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_IPU1_SEL
value|31
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_IPU2_SEL
value|32
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_LDB_DI0_SEL
value|33
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_LDB_DI1_SEL
value|34
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_IPU1_DI0_PRE_SEL
value|35
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_IPU1_DI1_PRE_SEL
value|36
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_IPU2_DI0_PRE_SEL
value|37
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_IPU2_DI1_PRE_SEL
value|38
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_IPU1_DI0_SEL
value|39
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_IPU1_DI1_SEL
value|40
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_IPU2_DI0_SEL
value|41
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_IPU2_DI1_SEL
value|42
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_HSI_TX_SEL
value|43
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_PCIE_AXI_SEL
value|44
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_SSI1_SEL
value|45
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_SSI2_SEL
value|46
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_SSI3_SEL
value|47
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_USDHC1_SEL
value|48
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_USDHC2_SEL
value|49
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_USDHC3_SEL
value|50
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_USDHC4_SEL
value|51
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_ENFC_SEL
value|52
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_EMI_SEL
value|53
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_EMI_SLOW_SEL
value|54
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_VDO_AXI_SEL
value|55
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_VPU_AXI_SEL
value|56
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_CKO1_SEL
value|57
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_PERIPH
value|58
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_PERIPH2
value|59
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_PERIPH_CLK2
value|60
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_PERIPH2_CLK2
value|61
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_IPG
value|62
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_IPG_PER
value|63
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_ESAI_PRED
value|64
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_ESAI_PODF
value|65
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_ASRC_PRED
value|66
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_ASRC_PODF
value|67
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_SPDIF_PRED
value|68
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_SPDIF_PODF
value|69
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_CAN_ROOT
value|70
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_ECSPI_ROOT
value|71
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_GPU2D_CORE_PODF
value|72
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_GPU3D_CORE_PODF
value|73
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_GPU3D_SHADER
value|74
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_IPU1_PODF
value|75
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_IPU2_PODF
value|76
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_LDB_DI0_PODF
value|77
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_LDB_DI1_PODF
value|78
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_IPU1_DI0_PRE
value|79
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_IPU1_DI1_PRE
value|80
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_IPU2_DI0_PRE
value|81
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_IPU2_DI1_PRE
value|82
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_HSI_TX_PODF
value|83
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_SSI1_PRED
value|84
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_SSI1_PODF
value|85
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_SSI2_PRED
value|86
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_SSI2_PODF
value|87
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_SSI3_PRED
value|88
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_SSI3_PODF
value|89
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_UART_SERIAL_PODF
value|90
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_USDHC1_PODF
value|91
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_USDHC2_PODF
value|92
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_USDHC3_PODF
value|93
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_USDHC4_PODF
value|94
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_ENFC_PRED
value|95
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_ENFC_PODF
value|96
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_EMI_PODF
value|97
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_EMI_SLOW_PODF
value|98
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_VPU_AXI_PODF
value|99
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_CKO1_PODF
value|100
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_AXI
value|101
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_MMDC_CH0_AXI_PODF
value|102
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_MMDC_CH1_AXI_PODF
value|103
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_ARM
value|104
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_AHB
value|105
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_APBH_DMA
value|106
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_ASRC
value|107
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_CAN1_IPG
value|108
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_CAN1_SERIAL
value|109
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_CAN2_IPG
value|110
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_CAN2_SERIAL
value|111
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_ECSPI1
value|112
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_ECSPI2
value|113
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_ECSPI3
value|114
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_ECSPI4
value|115
end_define

begin_define
define|#
directive|define
name|IMX6Q_CLK_ECSPI5
value|116
end_define

begin_define
define|#
directive|define
name|IMX6DL_CLK_I2C4
value|116
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_ENET
value|117
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_ESAI
value|118
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_GPT_IPG
value|119
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_GPT_IPG_PER
value|120
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_GPU2D_CORE
value|121
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_GPU3D_CORE
value|122
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_HDMI_IAHB
value|123
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_HDMI_ISFR
value|124
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_I2C1
value|125
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_I2C2
value|126
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_I2C3
value|127
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_IIM
value|128
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_ENFC
value|129
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_IPU1
value|130
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_IPU1_DI0
value|131
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_IPU1_DI1
value|132
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_IPU2
value|133
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_IPU2_DI0
value|134
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_LDB_DI0
value|135
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_LDB_DI1
value|136
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_IPU2_DI1
value|137
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_HSI_TX
value|138
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_MLB
value|139
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_MMDC_CH0_AXI
value|140
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_MMDC_CH1_AXI
value|141
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_OCRAM
value|142
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_OPENVG_AXI
value|143
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_PCIE_AXI
value|144
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_PWM1
value|145
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_PWM2
value|146
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_PWM3
value|147
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_PWM4
value|148
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_PER1_BCH
value|149
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_GPMI_BCH_APB
value|150
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_GPMI_BCH
value|151
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_GPMI_IO
value|152
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_GPMI_APB
value|153
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_SATA
value|154
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_SDMA
value|155
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_SPBA
value|156
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_SSI1
value|157
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_SSI2
value|158
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_SSI3
value|159
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_UART_IPG
value|160
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_UART_SERIAL
value|161
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_USBOH3
value|162
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_USDHC1
value|163
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_USDHC2
value|164
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_USDHC3
value|165
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_USDHC4
value|166
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_VDO_AXI
value|167
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_VPU_AXI
value|168
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_CKO1
value|169
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_PLL1_SYS
value|170
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_PLL2_BUS
value|171
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_PLL3_USB_OTG
value|172
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_PLL4_AUDIO
value|173
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_PLL5_VIDEO
value|174
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_PLL8_MLB
value|175
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_PLL7_USB_HOST
value|176
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_PLL6_ENET
value|177
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_SSI1_IPG
value|178
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_SSI2_IPG
value|179
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_SSI3_IPG
value|180
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_ROM
value|181
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_USBPHY1
value|182
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_USBPHY2
value|183
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_LDB_DI0_DIV_3_5
value|184
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_LDB_DI1_DIV_3_5
value|185
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_SATA_REF
value|186
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_SATA_REF_100M
value|187
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_PCIE_REF
value|188
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_PCIE_REF_125M
value|189
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_ENET_REF
value|190
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_USBPHY1_GATE
value|191
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_USBPHY2_GATE
value|192
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_PLL4_POST_DIV
value|193
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_PLL5_POST_DIV
value|194
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_PLL5_VIDEO_DIV
value|195
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_EIM_SLOW
value|196
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_SPDIF
value|197
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_CKO2_SEL
value|198
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_CKO2_PODF
value|199
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_CKO2
value|200
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_CKO
value|201
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_VDOA
value|202
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_PLL4_AUDIO_DIV
value|203
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_LVDS1_SEL
value|204
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_LVDS2_SEL
value|205
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_LVDS1_GATE
value|206
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_LVDS2_GATE
value|207
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_ESAI_AHB
value|208
end_define

begin_define
define|#
directive|define
name|IMX6QDL_CLK_END
value|209
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DT_BINDINGS_CLOCK_IMX6QDL_H */
end_comment

end_unit

