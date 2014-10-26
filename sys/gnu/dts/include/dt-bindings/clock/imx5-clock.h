begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2013 Lucas Stach, Pengutronix<l.stach@pengutronix.de>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_CLOCK_IMX5_H
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_CLOCK_IMX5_H
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_DUMMY
value|0
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_CKIL
value|1
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_OSC
value|2
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_CKIH1
value|3
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_CKIH2
value|4
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_AHB
value|5
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_IPG
value|6
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_AXI_A
value|7
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_AXI_B
value|8
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_UART_PRED
value|9
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_UART_ROOT
value|10
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_ESDHC_A_PRED
value|11
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_ESDHC_B_PRED
value|12
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_ESDHC_C_SEL
value|13
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_ESDHC_D_SEL
value|14
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_EMI_SEL
value|15
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_EMI_SLOW_PODF
value|16
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_NFC_PODF
value|17
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_ECSPI_PRED
value|18
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_ECSPI_PODF
value|19
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_USBOH3_PRED
value|20
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_USBOH3_PODF
value|21
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_USB_PHY_PRED
value|22
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_USB_PHY_PODF
value|23
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_CPU_PODF
value|24
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_DI_PRED
value|25
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_TVE_SEL
value|27
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_UART1_IPG_GATE
value|28
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_UART1_PER_GATE
value|29
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_UART2_IPG_GATE
value|30
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_UART2_PER_GATE
value|31
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_UART3_IPG_GATE
value|32
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_UART3_PER_GATE
value|33
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_I2C1_GATE
value|34
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_I2C2_GATE
value|35
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_GPT_IPG_GATE
value|36
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_PWM1_IPG_GATE
value|37
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_PWM1_HF_GATE
value|38
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_PWM2_IPG_GATE
value|39
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_PWM2_HF_GATE
value|40
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_GPT_HF_GATE
value|41
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_FEC_GATE
value|42
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_USBOH3_PER_GATE
value|43
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_ESDHC1_IPG_GATE
value|44
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_ESDHC2_IPG_GATE
value|45
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_ESDHC3_IPG_GATE
value|46
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_ESDHC4_IPG_GATE
value|47
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SSI1_IPG_GATE
value|48
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SSI2_IPG_GATE
value|49
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SSI3_IPG_GATE
value|50
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_ECSPI1_IPG_GATE
value|51
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_ECSPI1_PER_GATE
value|52
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_ECSPI2_IPG_GATE
value|53
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_ECSPI2_PER_GATE
value|54
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_CSPI_IPG_GATE
value|55
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SDMA_GATE
value|56
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_EMI_SLOW_GATE
value|57
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_IPU_SEL
value|58
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_IPU_GATE
value|59
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_NFC_GATE
value|60
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_IPU_DI1_GATE
value|61
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_VPU_SEL
value|62
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_VPU_GATE
value|63
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_VPU_REFERENCE_GATE
value|64
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_UART4_IPG_GATE
value|65
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_UART4_PER_GATE
value|66
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_UART5_IPG_GATE
value|67
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_UART5_PER_GATE
value|68
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_TVE_GATE
value|69
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_TVE_PRED
value|70
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_ESDHC1_PER_GATE
value|71
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_ESDHC2_PER_GATE
value|72
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_ESDHC3_PER_GATE
value|73
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_ESDHC4_PER_GATE
value|74
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_USB_PHY_GATE
value|75
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_HSI2C_GATE
value|76
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_MIPI_HSC1_GATE
value|77
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_MIPI_HSC2_GATE
value|78
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_MIPI_ESC_GATE
value|79
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_MIPI_HSP_GATE
value|80
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_LDB_DI1_DIV_3_5
value|81
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_LDB_DI1_DIV
value|82
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_LDB_DI0_DIV_3_5
value|83
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_LDB_DI0_DIV
value|84
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_LDB_DI1_GATE
value|85
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_CAN2_SERIAL_GATE
value|86
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_CAN2_IPG_GATE
value|87
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_I2C3_GATE
value|88
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_LP_APM
value|89
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_PERIPH_APM
value|90
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_MAIN_BUS
value|91
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_AHB_MAX
value|92
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_AIPS_TZ1
value|93
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_AIPS_TZ2
value|94
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_TMAX1
value|95
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_TMAX2
value|96
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_TMAX3
value|97
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SPBA
value|98
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_UART_SEL
value|99
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_ESDHC_A_SEL
value|100
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_ESDHC_B_SEL
value|101
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_ESDHC_A_PODF
value|102
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_ESDHC_B_PODF
value|103
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_ECSPI_SEL
value|104
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_USBOH3_SEL
value|105
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_USB_PHY_SEL
value|106
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_IIM_GATE
value|107
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_USBOH3_GATE
value|108
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_EMI_FAST_GATE
value|109
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_IPU_DI0_GATE
value|110
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_GPC_DVFS
value|111
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_PLL1_SW
value|112
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_PLL2_SW
value|113
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_PLL3_SW
value|114
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_IPU_DI0_SEL
value|115
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_IPU_DI1_SEL
value|116
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_TVE_EXT_SEL
value|117
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_MX51_MIPI
value|118
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_PLL4_SW
value|119
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_LDB_DI1_SEL
value|120
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_DI_PLL4_PODF
value|121
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_LDB_DI0_SEL
value|122
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_LDB_DI0_GATE
value|123
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_USB_PHY1_GATE
value|124
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_USB_PHY2_GATE
value|125
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_PER_LP_APM
value|126
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_PER_PRED1
value|127
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_PER_PRED2
value|128
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_PER_PODF
value|129
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_PER_ROOT
value|130
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SSI_APM
value|131
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SSI1_ROOT_SEL
value|132
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SSI2_ROOT_SEL
value|133
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SSI3_ROOT_SEL
value|134
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SSI_EXT1_SEL
value|135
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SSI_EXT2_SEL
value|136
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SSI_EXT1_COM_SEL
value|137
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SSI_EXT2_COM_SEL
value|138
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SSI1_ROOT_PRED
value|139
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SSI1_ROOT_PODF
value|140
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SSI2_ROOT_PRED
value|141
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SSI2_ROOT_PODF
value|142
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SSI_EXT1_PRED
value|143
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SSI_EXT1_PODF
value|144
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SSI_EXT2_PRED
value|145
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SSI_EXT2_PODF
value|146
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SSI1_ROOT_GATE
value|147
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SSI2_ROOT_GATE
value|148
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SSI3_ROOT_GATE
value|149
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SSI_EXT1_GATE
value|150
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SSI_EXT2_GATE
value|151
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_EPIT1_IPG_GATE
value|152
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_EPIT1_HF_GATE
value|153
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_EPIT2_IPG_GATE
value|154
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_EPIT2_HF_GATE
value|155
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_CAN_SEL
value|156
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_CAN1_SERIAL_GATE
value|157
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_CAN1_IPG_GATE
value|158
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_OWIRE_GATE
value|159
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_GPU3D_SEL
value|160
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_GPU2D_SEL
value|161
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_GPU3D_GATE
value|162
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_GPU2D_GATE
value|163
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_GARB_GATE
value|164
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_CKO1_SEL
value|165
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_CKO1_PODF
value|166
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_CKO1
value|167
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_CKO2_SEL
value|168
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_CKO2_PODF
value|169
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_CKO2
value|170
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SRTC_GATE
value|171
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_PATA_GATE
value|172
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SATA_GATE
value|173
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SPDIF_XTAL_SEL
value|174
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SPDIF0_SEL
value|175
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SPDIF1_SEL
value|176
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SPDIF0_PRED
value|177
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SPDIF0_PODF
value|178
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SPDIF1_PRED
value|179
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SPDIF1_PODF
value|180
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SPDIF0_COM_SEL
value|181
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SPDIF1_COM_SEL
value|182
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SPDIF0_GATE
value|183
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SPDIF1_GATE
value|184
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SPDIF_IPG_GATE
value|185
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_OCRAM
value|186
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SAHARA_IPG_GATE
value|187
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_SATA_REF
value|188
end_define

begin_define
define|#
directive|define
name|IMX5_CLK_END
value|189
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DT_BINDINGS_CLOCK_IMX5_H */
end_comment

end_unit

