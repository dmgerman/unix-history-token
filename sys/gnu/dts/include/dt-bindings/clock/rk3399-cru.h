begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2016 Rockchip Electronics Co. Ltd.  * Author: Xing Zheng<zhengxing@rock-chips.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLK_ROCKCHIP_RK3399_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLK_ROCKCHIP_RK3399_H
end_define

begin_comment
comment|/* core clocks */
end_comment

begin_define
define|#
directive|define
name|PLL_APLLL
value|1
end_define

begin_define
define|#
directive|define
name|PLL_APLLB
value|2
end_define

begin_define
define|#
directive|define
name|PLL_DPLL
value|3
end_define

begin_define
define|#
directive|define
name|PLL_CPLL
value|4
end_define

begin_define
define|#
directive|define
name|PLL_GPLL
value|5
end_define

begin_define
define|#
directive|define
name|PLL_NPLL
value|6
end_define

begin_define
define|#
directive|define
name|PLL_VPLL
value|7
end_define

begin_define
define|#
directive|define
name|ARMCLKL
value|8
end_define

begin_define
define|#
directive|define
name|ARMCLKB
value|9
end_define

begin_comment
comment|/* sclk gates (special clocks) */
end_comment

begin_define
define|#
directive|define
name|SCLK_I2C1
value|65
end_define

begin_define
define|#
directive|define
name|SCLK_I2C2
value|66
end_define

begin_define
define|#
directive|define
name|SCLK_I2C3
value|67
end_define

begin_define
define|#
directive|define
name|SCLK_I2C5
value|68
end_define

begin_define
define|#
directive|define
name|SCLK_I2C6
value|69
end_define

begin_define
define|#
directive|define
name|SCLK_I2C7
value|70
end_define

begin_define
define|#
directive|define
name|SCLK_SPI0
value|71
end_define

begin_define
define|#
directive|define
name|SCLK_SPI1
value|72
end_define

begin_define
define|#
directive|define
name|SCLK_SPI2
value|73
end_define

begin_define
define|#
directive|define
name|SCLK_SPI4
value|74
end_define

begin_define
define|#
directive|define
name|SCLK_SPI5
value|75
end_define

begin_define
define|#
directive|define
name|SCLK_SDMMC
value|76
end_define

begin_define
define|#
directive|define
name|SCLK_SDIO
value|77
end_define

begin_define
define|#
directive|define
name|SCLK_EMMC
value|78
end_define

begin_define
define|#
directive|define
name|SCLK_TSADC
value|79
end_define

begin_define
define|#
directive|define
name|SCLK_SARADC
value|80
end_define

begin_define
define|#
directive|define
name|SCLK_UART0
value|81
end_define

begin_define
define|#
directive|define
name|SCLK_UART1
value|82
end_define

begin_define
define|#
directive|define
name|SCLK_UART2
value|83
end_define

begin_define
define|#
directive|define
name|SCLK_UART3
value|84
end_define

begin_define
define|#
directive|define
name|SCLK_SPDIF_8CH
value|85
end_define

begin_define
define|#
directive|define
name|SCLK_I2S0_8CH
value|86
end_define

begin_define
define|#
directive|define
name|SCLK_I2S1_8CH
value|87
end_define

begin_define
define|#
directive|define
name|SCLK_I2S2_8CH
value|88
end_define

begin_define
define|#
directive|define
name|SCLK_I2S_8CH_OUT
value|89
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER00
value|90
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER01
value|91
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER02
value|92
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER03
value|93
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER04
value|94
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER05
value|95
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER06
value|96
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER07
value|97
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER08
value|98
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER09
value|99
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER10
value|100
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER11
value|101
end_define

begin_define
define|#
directive|define
name|SCLK_MACREF
value|102
end_define

begin_define
define|#
directive|define
name|SCLK_MAC_RX
value|103
end_define

begin_define
define|#
directive|define
name|SCLK_MAC_TX
value|104
end_define

begin_define
define|#
directive|define
name|SCLK_MAC
value|105
end_define

begin_define
define|#
directive|define
name|SCLK_MACREF_OUT
value|106
end_define

begin_define
define|#
directive|define
name|SCLK_VOP0_PWM
value|107
end_define

begin_define
define|#
directive|define
name|SCLK_VOP1_PWM
value|108
end_define

begin_define
define|#
directive|define
name|SCLK_RGA_CORE
value|109
end_define

begin_define
define|#
directive|define
name|SCLK_ISP0
value|110
end_define

begin_define
define|#
directive|define
name|SCLK_ISP1
value|111
end_define

begin_define
define|#
directive|define
name|SCLK_HDMI_CEC
value|112
end_define

begin_define
define|#
directive|define
name|SCLK_HDMI_SFR
value|113
end_define

begin_define
define|#
directive|define
name|SCLK_DP_CORE
value|114
end_define

begin_define
define|#
directive|define
name|SCLK_PVTM_CORE_L
value|115
end_define

begin_define
define|#
directive|define
name|SCLK_PVTM_CORE_B
value|116
end_define

begin_define
define|#
directive|define
name|SCLK_PVTM_GPU
value|117
end_define

begin_define
define|#
directive|define
name|SCLK_PVTM_DDR
value|118
end_define

begin_define
define|#
directive|define
name|SCLK_MIPIDPHY_REF
value|119
end_define

begin_define
define|#
directive|define
name|SCLK_MIPIDPHY_CFG
value|120
end_define

begin_define
define|#
directive|define
name|SCLK_HSICPHY
value|121
end_define

begin_define
define|#
directive|define
name|SCLK_USBPHY480M
value|122
end_define

begin_define
define|#
directive|define
name|SCLK_USB2PHY0_REF
value|123
end_define

begin_define
define|#
directive|define
name|SCLK_USB2PHY1_REF
value|124
end_define

begin_define
define|#
directive|define
name|SCLK_UPHY0_TCPDPHY_REF
value|125
end_define

begin_define
define|#
directive|define
name|SCLK_UPHY0_TCPDCORE
value|126
end_define

begin_define
define|#
directive|define
name|SCLK_UPHY1_TCPDPHY_REF
value|127
end_define

begin_define
define|#
directive|define
name|SCLK_UPHY1_TCPDCORE
value|128
end_define

begin_define
define|#
directive|define
name|SCLK_USB3OTG0_REF
value|129
end_define

begin_define
define|#
directive|define
name|SCLK_USB3OTG1_REF
value|130
end_define

begin_define
define|#
directive|define
name|SCLK_USB3OTG0_SUSPEND
value|131
end_define

begin_define
define|#
directive|define
name|SCLK_USB3OTG1_SUSPEND
value|132
end_define

begin_define
define|#
directive|define
name|SCLK_CRYPTO0
value|133
end_define

begin_define
define|#
directive|define
name|SCLK_CRYPTO1
value|134
end_define

begin_define
define|#
directive|define
name|SCLK_CCI_TRACE
value|135
end_define

begin_define
define|#
directive|define
name|SCLK_CS
value|136
end_define

begin_define
define|#
directive|define
name|SCLK_CIF_OUT
value|137
end_define

begin_define
define|#
directive|define
name|SCLK_PCIEPHY_REF
value|138
end_define

begin_define
define|#
directive|define
name|SCLK_PCIE_CORE
value|139
end_define

begin_define
define|#
directive|define
name|SCLK_M0_PERILP
value|140
end_define

begin_define
define|#
directive|define
name|SCLK_M0_PERILP_DEC
value|141
end_define

begin_define
define|#
directive|define
name|SCLK_CM0S
value|142
end_define

begin_define
define|#
directive|define
name|SCLK_DBG_NOC
value|143
end_define

begin_define
define|#
directive|define
name|SCLK_DBG_PD_CORE_B
value|144
end_define

begin_define
define|#
directive|define
name|SCLK_DBG_PD_CORE_L
value|145
end_define

begin_define
define|#
directive|define
name|SCLK_DFIMON0_TIMER
value|146
end_define

begin_define
define|#
directive|define
name|SCLK_DFIMON1_TIMER
value|147
end_define

begin_define
define|#
directive|define
name|SCLK_INTMEM0
value|148
end_define

begin_define
define|#
directive|define
name|SCLK_INTMEM1
value|149
end_define

begin_define
define|#
directive|define
name|SCLK_INTMEM2
value|150
end_define

begin_define
define|#
directive|define
name|SCLK_INTMEM3
value|151
end_define

begin_define
define|#
directive|define
name|SCLK_INTMEM4
value|152
end_define

begin_define
define|#
directive|define
name|SCLK_INTMEM5
value|153
end_define

begin_define
define|#
directive|define
name|SCLK_SDMMC_DRV
value|154
end_define

begin_define
define|#
directive|define
name|SCLK_SDMMC_SAMPLE
value|155
end_define

begin_define
define|#
directive|define
name|SCLK_SDIO_DRV
value|156
end_define

begin_define
define|#
directive|define
name|SCLK_SDIO_SAMPLE
value|157
end_define

begin_define
define|#
directive|define
name|SCLK_VDU_CORE
value|158
end_define

begin_define
define|#
directive|define
name|SCLK_VDU_CA
value|159
end_define

begin_define
define|#
directive|define
name|SCLK_PCIE_PM
value|160
end_define

begin_define
define|#
directive|define
name|SCLK_SPDIF_REC_DPTX
value|161
end_define

begin_define
define|#
directive|define
name|SCLK_DPHY_PLL
value|162
end_define

begin_define
define|#
directive|define
name|SCLK_DPHY_TX0_CFG
value|163
end_define

begin_define
define|#
directive|define
name|SCLK_DPHY_TX1RX1_CFG
value|164
end_define

begin_define
define|#
directive|define
name|SCLK_DPHY_RX0_CFG
value|165
end_define

begin_define
define|#
directive|define
name|SCLK_RMII_SRC
value|166
end_define

begin_define
define|#
directive|define
name|SCLK_PCIEPHY_REF100M
value|167
end_define

begin_define
define|#
directive|define
name|SCLK_DDRC
value|168
end_define

begin_define
define|#
directive|define
name|SCLK_TESTCLKOUT1
value|169
end_define

begin_define
define|#
directive|define
name|SCLK_TESTCLKOUT2
value|170
end_define

begin_define
define|#
directive|define
name|DCLK_VOP0
value|180
end_define

begin_define
define|#
directive|define
name|DCLK_VOP1
value|181
end_define

begin_define
define|#
directive|define
name|DCLK_VOP0_DIV
value|182
end_define

begin_define
define|#
directive|define
name|DCLK_VOP1_DIV
value|183
end_define

begin_define
define|#
directive|define
name|DCLK_M0_PERILP
value|184
end_define

begin_define
define|#
directive|define
name|DCLK_VOP0_FRAC
value|185
end_define

begin_define
define|#
directive|define
name|DCLK_VOP1_FRAC
value|186
end_define

begin_define
define|#
directive|define
name|FCLK_CM0S
value|190
end_define

begin_comment
comment|/* aclk gates */
end_comment

begin_define
define|#
directive|define
name|ACLK_PERIHP
value|192
end_define

begin_define
define|#
directive|define
name|ACLK_PERIHP_NOC
value|193
end_define

begin_define
define|#
directive|define
name|ACLK_PERILP0
value|194
end_define

begin_define
define|#
directive|define
name|ACLK_PERILP0_NOC
value|195
end_define

begin_define
define|#
directive|define
name|ACLK_PERF_PCIE
value|196
end_define

begin_define
define|#
directive|define
name|ACLK_PCIE
value|197
end_define

begin_define
define|#
directive|define
name|ACLK_INTMEM
value|198
end_define

begin_define
define|#
directive|define
name|ACLK_TZMA
value|199
end_define

begin_define
define|#
directive|define
name|ACLK_DCF
value|200
end_define

begin_define
define|#
directive|define
name|ACLK_CCI
value|201
end_define

begin_define
define|#
directive|define
name|ACLK_CCI_NOC0
value|202
end_define

begin_define
define|#
directive|define
name|ACLK_CCI_NOC1
value|203
end_define

begin_define
define|#
directive|define
name|ACLK_CCI_GRF
value|204
end_define

begin_define
define|#
directive|define
name|ACLK_CENTER
value|205
end_define

begin_define
define|#
directive|define
name|ACLK_CENTER_MAIN_NOC
value|206
end_define

begin_define
define|#
directive|define
name|ACLK_CENTER_PERI_NOC
value|207
end_define

begin_define
define|#
directive|define
name|ACLK_GPU
value|208
end_define

begin_define
define|#
directive|define
name|ACLK_PERF_GPU
value|209
end_define

begin_define
define|#
directive|define
name|ACLK_GPU_GRF
value|210
end_define

begin_define
define|#
directive|define
name|ACLK_DMAC0_PERILP
value|211
end_define

begin_define
define|#
directive|define
name|ACLK_DMAC1_PERILP
value|212
end_define

begin_define
define|#
directive|define
name|ACLK_GMAC
value|213
end_define

begin_define
define|#
directive|define
name|ACLK_GMAC_NOC
value|214
end_define

begin_define
define|#
directive|define
name|ACLK_PERF_GMAC
value|215
end_define

begin_define
define|#
directive|define
name|ACLK_VOP0_NOC
value|216
end_define

begin_define
define|#
directive|define
name|ACLK_VOP0
value|217
end_define

begin_define
define|#
directive|define
name|ACLK_VOP1_NOC
value|218
end_define

begin_define
define|#
directive|define
name|ACLK_VOP1
value|219
end_define

begin_define
define|#
directive|define
name|ACLK_RGA
value|220
end_define

begin_define
define|#
directive|define
name|ACLK_RGA_NOC
value|221
end_define

begin_define
define|#
directive|define
name|ACLK_HDCP
value|222
end_define

begin_define
define|#
directive|define
name|ACLK_HDCP_NOC
value|223
end_define

begin_define
define|#
directive|define
name|ACLK_HDCP22
value|224
end_define

begin_define
define|#
directive|define
name|ACLK_IEP
value|225
end_define

begin_define
define|#
directive|define
name|ACLK_IEP_NOC
value|226
end_define

begin_define
define|#
directive|define
name|ACLK_VIO
value|227
end_define

begin_define
define|#
directive|define
name|ACLK_VIO_NOC
value|228
end_define

begin_define
define|#
directive|define
name|ACLK_ISP0
value|229
end_define

begin_define
define|#
directive|define
name|ACLK_ISP1
value|230
end_define

begin_define
define|#
directive|define
name|ACLK_ISP0_NOC
value|231
end_define

begin_define
define|#
directive|define
name|ACLK_ISP1_NOC
value|232
end_define

begin_define
define|#
directive|define
name|ACLK_ISP0_WRAPPER
value|233
end_define

begin_define
define|#
directive|define
name|ACLK_ISP1_WRAPPER
value|234
end_define

begin_define
define|#
directive|define
name|ACLK_VCODEC
value|235
end_define

begin_define
define|#
directive|define
name|ACLK_VCODEC_NOC
value|236
end_define

begin_define
define|#
directive|define
name|ACLK_VDU
value|237
end_define

begin_define
define|#
directive|define
name|ACLK_VDU_NOC
value|238
end_define

begin_define
define|#
directive|define
name|ACLK_PERI
value|239
end_define

begin_define
define|#
directive|define
name|ACLK_EMMC
value|240
end_define

begin_define
define|#
directive|define
name|ACLK_EMMC_CORE
value|241
end_define

begin_define
define|#
directive|define
name|ACLK_EMMC_NOC
value|242
end_define

begin_define
define|#
directive|define
name|ACLK_EMMC_GRF
value|243
end_define

begin_define
define|#
directive|define
name|ACLK_USB3
value|244
end_define

begin_define
define|#
directive|define
name|ACLK_USB3_NOC
value|245
end_define

begin_define
define|#
directive|define
name|ACLK_USB3OTG0
value|246
end_define

begin_define
define|#
directive|define
name|ACLK_USB3OTG1
value|247
end_define

begin_define
define|#
directive|define
name|ACLK_USB3_RKSOC_AXI_PERF
value|248
end_define

begin_define
define|#
directive|define
name|ACLK_USB3_GRF
value|249
end_define

begin_define
define|#
directive|define
name|ACLK_GIC
value|250
end_define

begin_define
define|#
directive|define
name|ACLK_GIC_NOC
value|251
end_define

begin_define
define|#
directive|define
name|ACLK_GIC_ADB400_CORE_L_2_GIC
value|252
end_define

begin_define
define|#
directive|define
name|ACLK_GIC_ADB400_CORE_B_2_GIC
value|253
end_define

begin_define
define|#
directive|define
name|ACLK_GIC_ADB400_GIC_2_CORE_L
value|254
end_define

begin_define
define|#
directive|define
name|ACLK_GIC_ADB400_GIC_2_CORE_B
value|255
end_define

begin_define
define|#
directive|define
name|ACLK_CORE_ADB400_CORE_L_2_CCI500
value|256
end_define

begin_define
define|#
directive|define
name|ACLK_CORE_ADB400_CORE_B_2_CCI500
value|257
end_define

begin_define
define|#
directive|define
name|ACLK_ADB400M_PD_CORE_L
value|258
end_define

begin_define
define|#
directive|define
name|ACLK_ADB400M_PD_CORE_B
value|259
end_define

begin_define
define|#
directive|define
name|ACLK_PERF_CORE_L
value|260
end_define

begin_define
define|#
directive|define
name|ACLK_PERF_CORE_B
value|261
end_define

begin_define
define|#
directive|define
name|ACLK_GIC_PRE
value|262
end_define

begin_define
define|#
directive|define
name|ACLK_VOP0_PRE
value|263
end_define

begin_define
define|#
directive|define
name|ACLK_VOP1_PRE
value|264
end_define

begin_comment
comment|/* pclk gates */
end_comment

begin_define
define|#
directive|define
name|PCLK_PERIHP
value|320
end_define

begin_define
define|#
directive|define
name|PCLK_PERIHP_NOC
value|321
end_define

begin_define
define|#
directive|define
name|PCLK_PERILP0
value|322
end_define

begin_define
define|#
directive|define
name|PCLK_PERILP1
value|323
end_define

begin_define
define|#
directive|define
name|PCLK_PERILP1_NOC
value|324
end_define

begin_define
define|#
directive|define
name|PCLK_PERILP_SGRF
value|325
end_define

begin_define
define|#
directive|define
name|PCLK_PERIHP_GRF
value|326
end_define

begin_define
define|#
directive|define
name|PCLK_PCIE
value|327
end_define

begin_define
define|#
directive|define
name|PCLK_SGRF
value|328
end_define

begin_define
define|#
directive|define
name|PCLK_INTR_ARB
value|329
end_define

begin_define
define|#
directive|define
name|PCLK_CENTER_MAIN_NOC
value|330
end_define

begin_define
define|#
directive|define
name|PCLK_CIC
value|331
end_define

begin_define
define|#
directive|define
name|PCLK_COREDBG_B
value|332
end_define

begin_define
define|#
directive|define
name|PCLK_COREDBG_L
value|333
end_define

begin_define
define|#
directive|define
name|PCLK_DBG_CXCS_PD_CORE_B
value|334
end_define

begin_define
define|#
directive|define
name|PCLK_DCF
value|335
end_define

begin_define
define|#
directive|define
name|PCLK_GPIO2
value|336
end_define

begin_define
define|#
directive|define
name|PCLK_GPIO3
value|337
end_define

begin_define
define|#
directive|define
name|PCLK_GPIO4
value|338
end_define

begin_define
define|#
directive|define
name|PCLK_GRF
value|339
end_define

begin_define
define|#
directive|define
name|PCLK_HSICPHY
value|340
end_define

begin_define
define|#
directive|define
name|PCLK_I2C1
value|341
end_define

begin_define
define|#
directive|define
name|PCLK_I2C2
value|342
end_define

begin_define
define|#
directive|define
name|PCLK_I2C3
value|343
end_define

begin_define
define|#
directive|define
name|PCLK_I2C5
value|344
end_define

begin_define
define|#
directive|define
name|PCLK_I2C6
value|345
end_define

begin_define
define|#
directive|define
name|PCLK_I2C7
value|346
end_define

begin_define
define|#
directive|define
name|PCLK_SPI0
value|347
end_define

begin_define
define|#
directive|define
name|PCLK_SPI1
value|348
end_define

begin_define
define|#
directive|define
name|PCLK_SPI2
value|349
end_define

begin_define
define|#
directive|define
name|PCLK_SPI4
value|350
end_define

begin_define
define|#
directive|define
name|PCLK_SPI5
value|351
end_define

begin_define
define|#
directive|define
name|PCLK_UART0
value|352
end_define

begin_define
define|#
directive|define
name|PCLK_UART1
value|353
end_define

begin_define
define|#
directive|define
name|PCLK_UART2
value|354
end_define

begin_define
define|#
directive|define
name|PCLK_UART3
value|355
end_define

begin_define
define|#
directive|define
name|PCLK_TSADC
value|356
end_define

begin_define
define|#
directive|define
name|PCLK_SARADC
value|357
end_define

begin_define
define|#
directive|define
name|PCLK_GMAC
value|358
end_define

begin_define
define|#
directive|define
name|PCLK_GMAC_NOC
value|359
end_define

begin_define
define|#
directive|define
name|PCLK_TIMER0
value|360
end_define

begin_define
define|#
directive|define
name|PCLK_TIMER1
value|361
end_define

begin_define
define|#
directive|define
name|PCLK_EDP
value|362
end_define

begin_define
define|#
directive|define
name|PCLK_EDP_NOC
value|363
end_define

begin_define
define|#
directive|define
name|PCLK_EDP_CTRL
value|364
end_define

begin_define
define|#
directive|define
name|PCLK_VIO
value|365
end_define

begin_define
define|#
directive|define
name|PCLK_VIO_NOC
value|366
end_define

begin_define
define|#
directive|define
name|PCLK_VIO_GRF
value|367
end_define

begin_define
define|#
directive|define
name|PCLK_MIPI_DSI0
value|368
end_define

begin_define
define|#
directive|define
name|PCLK_MIPI_DSI1
value|369
end_define

begin_define
define|#
directive|define
name|PCLK_HDCP
value|370
end_define

begin_define
define|#
directive|define
name|PCLK_HDCP_NOC
value|371
end_define

begin_define
define|#
directive|define
name|PCLK_HDMI_CTRL
value|372
end_define

begin_define
define|#
directive|define
name|PCLK_DP_CTRL
value|373
end_define

begin_define
define|#
directive|define
name|PCLK_HDCP22
value|374
end_define

begin_define
define|#
directive|define
name|PCLK_GASKET
value|375
end_define

begin_define
define|#
directive|define
name|PCLK_DDR
value|376
end_define

begin_define
define|#
directive|define
name|PCLK_DDR_MON
value|377
end_define

begin_define
define|#
directive|define
name|PCLK_DDR_SGRF
value|378
end_define

begin_define
define|#
directive|define
name|PCLK_ISP1_WRAPPER
value|379
end_define

begin_define
define|#
directive|define
name|PCLK_WDT
value|380
end_define

begin_define
define|#
directive|define
name|PCLK_EFUSE1024NS
value|381
end_define

begin_define
define|#
directive|define
name|PCLK_EFUSE1024S
value|382
end_define

begin_define
define|#
directive|define
name|PCLK_PMU_INTR_ARB
value|383
end_define

begin_define
define|#
directive|define
name|PCLK_MAILBOX0
value|384
end_define

begin_define
define|#
directive|define
name|PCLK_USBPHY_MUX_G
value|385
end_define

begin_define
define|#
directive|define
name|PCLK_UPHY0_TCPHY_G
value|386
end_define

begin_define
define|#
directive|define
name|PCLK_UPHY0_TCPD_G
value|387
end_define

begin_define
define|#
directive|define
name|PCLK_UPHY1_TCPHY_G
value|388
end_define

begin_define
define|#
directive|define
name|PCLK_UPHY1_TCPD_G
value|389
end_define

begin_define
define|#
directive|define
name|PCLK_ALIVE
value|390
end_define

begin_comment
comment|/* hclk gates */
end_comment

begin_define
define|#
directive|define
name|HCLK_PERIHP
value|448
end_define

begin_define
define|#
directive|define
name|HCLK_PERILP0
value|449
end_define

begin_define
define|#
directive|define
name|HCLK_PERILP1
value|450
end_define

begin_define
define|#
directive|define
name|HCLK_PERILP0_NOC
value|451
end_define

begin_define
define|#
directive|define
name|HCLK_PERILP1_NOC
value|452
end_define

begin_define
define|#
directive|define
name|HCLK_M0_PERILP
value|453
end_define

begin_define
define|#
directive|define
name|HCLK_M0_PERILP_NOC
value|454
end_define

begin_define
define|#
directive|define
name|HCLK_AHB1TOM
value|455
end_define

begin_define
define|#
directive|define
name|HCLK_HOST0
value|456
end_define

begin_define
define|#
directive|define
name|HCLK_HOST0_ARB
value|457
end_define

begin_define
define|#
directive|define
name|HCLK_HOST1
value|458
end_define

begin_define
define|#
directive|define
name|HCLK_HOST1_ARB
value|459
end_define

begin_define
define|#
directive|define
name|HCLK_HSIC
value|460
end_define

begin_define
define|#
directive|define
name|HCLK_SD
value|461
end_define

begin_define
define|#
directive|define
name|HCLK_SDMMC
value|462
end_define

begin_define
define|#
directive|define
name|HCLK_SDMMC_NOC
value|463
end_define

begin_define
define|#
directive|define
name|HCLK_M_CRYPTO0
value|464
end_define

begin_define
define|#
directive|define
name|HCLK_M_CRYPTO1
value|465
end_define

begin_define
define|#
directive|define
name|HCLK_S_CRYPTO0
value|466
end_define

begin_define
define|#
directive|define
name|HCLK_S_CRYPTO1
value|467
end_define

begin_define
define|#
directive|define
name|HCLK_I2S0_8CH
value|468
end_define

begin_define
define|#
directive|define
name|HCLK_I2S1_8CH
value|469
end_define

begin_define
define|#
directive|define
name|HCLK_I2S2_8CH
value|470
end_define

begin_define
define|#
directive|define
name|HCLK_SPDIF
value|471
end_define

begin_define
define|#
directive|define
name|HCLK_VOP0_NOC
value|472
end_define

begin_define
define|#
directive|define
name|HCLK_VOP0
value|473
end_define

begin_define
define|#
directive|define
name|HCLK_VOP1_NOC
value|474
end_define

begin_define
define|#
directive|define
name|HCLK_VOP1
value|475
end_define

begin_define
define|#
directive|define
name|HCLK_ROM
value|476
end_define

begin_define
define|#
directive|define
name|HCLK_IEP
value|477
end_define

begin_define
define|#
directive|define
name|HCLK_IEP_NOC
value|478
end_define

begin_define
define|#
directive|define
name|HCLK_ISP0
value|479
end_define

begin_define
define|#
directive|define
name|HCLK_ISP1
value|480
end_define

begin_define
define|#
directive|define
name|HCLK_ISP0_NOC
value|481
end_define

begin_define
define|#
directive|define
name|HCLK_ISP1_NOC
value|482
end_define

begin_define
define|#
directive|define
name|HCLK_ISP0_WRAPPER
value|483
end_define

begin_define
define|#
directive|define
name|HCLK_ISP1_WRAPPER
value|484
end_define

begin_define
define|#
directive|define
name|HCLK_RGA
value|485
end_define

begin_define
define|#
directive|define
name|HCLK_RGA_NOC
value|486
end_define

begin_define
define|#
directive|define
name|HCLK_HDCP
value|487
end_define

begin_define
define|#
directive|define
name|HCLK_HDCP_NOC
value|488
end_define

begin_define
define|#
directive|define
name|HCLK_HDCP22
value|489
end_define

begin_define
define|#
directive|define
name|HCLK_VCODEC
value|490
end_define

begin_define
define|#
directive|define
name|HCLK_VCODEC_NOC
value|491
end_define

begin_define
define|#
directive|define
name|HCLK_VDU
value|492
end_define

begin_define
define|#
directive|define
name|HCLK_VDU_NOC
value|493
end_define

begin_define
define|#
directive|define
name|HCLK_SDIO
value|494
end_define

begin_define
define|#
directive|define
name|HCLK_SDIO_NOC
value|495
end_define

begin_define
define|#
directive|define
name|HCLK_SDIOAUDIO_NOC
value|496
end_define

begin_define
define|#
directive|define
name|CLK_NR_CLKS
value|(HCLK_SDIOAUDIO_NOC + 1)
end_define

begin_comment
comment|/* pmu-clocks indices */
end_comment

begin_define
define|#
directive|define
name|PLL_PPLL
value|1
end_define

begin_define
define|#
directive|define
name|SCLK_32K_SUSPEND_PMU
value|2
end_define

begin_define
define|#
directive|define
name|SCLK_SPI3_PMU
value|3
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER12_PMU
value|4
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER13_PMU
value|5
end_define

begin_define
define|#
directive|define
name|SCLK_UART4_PMU
value|6
end_define

begin_define
define|#
directive|define
name|SCLK_PVTM_PMU
value|7
end_define

begin_define
define|#
directive|define
name|SCLK_WIFI_PMU
value|8
end_define

begin_define
define|#
directive|define
name|SCLK_I2C0_PMU
value|9
end_define

begin_define
define|#
directive|define
name|SCLK_I2C4_PMU
value|10
end_define

begin_define
define|#
directive|define
name|SCLK_I2C8_PMU
value|11
end_define

begin_define
define|#
directive|define
name|PCLK_SRC_PMU
value|19
end_define

begin_define
define|#
directive|define
name|PCLK_PMU
value|20
end_define

begin_define
define|#
directive|define
name|PCLK_PMUGRF_PMU
value|21
end_define

begin_define
define|#
directive|define
name|PCLK_INTMEM1_PMU
value|22
end_define

begin_define
define|#
directive|define
name|PCLK_GPIO0_PMU
value|23
end_define

begin_define
define|#
directive|define
name|PCLK_GPIO1_PMU
value|24
end_define

begin_define
define|#
directive|define
name|PCLK_SGRF_PMU
value|25
end_define

begin_define
define|#
directive|define
name|PCLK_NOC_PMU
value|26
end_define

begin_define
define|#
directive|define
name|PCLK_I2C0_PMU
value|27
end_define

begin_define
define|#
directive|define
name|PCLK_I2C4_PMU
value|28
end_define

begin_define
define|#
directive|define
name|PCLK_I2C8_PMU
value|29
end_define

begin_define
define|#
directive|define
name|PCLK_RKPWM_PMU
value|30
end_define

begin_define
define|#
directive|define
name|PCLK_SPI3_PMU
value|31
end_define

begin_define
define|#
directive|define
name|PCLK_TIMER_PMU
value|32
end_define

begin_define
define|#
directive|define
name|PCLK_MAILBOX_PMU
value|33
end_define

begin_define
define|#
directive|define
name|PCLK_UART4_PMU
value|34
end_define

begin_define
define|#
directive|define
name|PCLK_WDT_M0_PMU
value|35
end_define

begin_define
define|#
directive|define
name|FCLK_CM0S_SRC_PMU
value|44
end_define

begin_define
define|#
directive|define
name|FCLK_CM0S_PMU
value|45
end_define

begin_define
define|#
directive|define
name|SCLK_CM0S_PMU
value|46
end_define

begin_define
define|#
directive|define
name|HCLK_CM0S_PMU
value|47
end_define

begin_define
define|#
directive|define
name|DCLK_CM0S_PMU
value|48
end_define

begin_define
define|#
directive|define
name|PCLK_INTR_ARB_PMU
value|49
end_define

begin_define
define|#
directive|define
name|HCLK_NOC_PMU
value|50
end_define

begin_define
define|#
directive|define
name|CLKPMU_NR_CLKS
value|(HCLK_NOC_PMU + 1)
end_define

begin_comment
comment|/* soft-reset indices */
end_comment

begin_comment
comment|/* cru_softrst_con0 */
end_comment

begin_define
define|#
directive|define
name|SRST_CORE_L0
value|0
end_define

begin_define
define|#
directive|define
name|SRST_CORE_B0
value|1
end_define

begin_define
define|#
directive|define
name|SRST_CORE_PO_L0
value|2
end_define

begin_define
define|#
directive|define
name|SRST_CORE_PO_B0
value|3
end_define

begin_define
define|#
directive|define
name|SRST_L2_L
value|4
end_define

begin_define
define|#
directive|define
name|SRST_L2_B
value|5
end_define

begin_define
define|#
directive|define
name|SRST_ADB_L
value|6
end_define

begin_define
define|#
directive|define
name|SRST_ADB_B
value|7
end_define

begin_define
define|#
directive|define
name|SRST_A_CCI
value|8
end_define

begin_define
define|#
directive|define
name|SRST_A_CCIM0_NOC
value|9
end_define

begin_define
define|#
directive|define
name|SRST_A_CCIM1_NOC
value|10
end_define

begin_define
define|#
directive|define
name|SRST_DBG_NOC
value|11
end_define

begin_comment
comment|/* cru_softrst_con1 */
end_comment

begin_define
define|#
directive|define
name|SRST_CORE_L0_T
value|16
end_define

begin_define
define|#
directive|define
name|SRST_CORE_L1
value|17
end_define

begin_define
define|#
directive|define
name|SRST_CORE_L2
value|18
end_define

begin_define
define|#
directive|define
name|SRST_CORE_L3
value|19
end_define

begin_define
define|#
directive|define
name|SRST_CORE_PO_L0_T
value|20
end_define

begin_define
define|#
directive|define
name|SRST_CORE_PO_L1
value|21
end_define

begin_define
define|#
directive|define
name|SRST_CORE_PO_L2
value|22
end_define

begin_define
define|#
directive|define
name|SRST_CORE_PO_L3
value|23
end_define

begin_define
define|#
directive|define
name|SRST_A_ADB400_GIC2COREL
value|24
end_define

begin_define
define|#
directive|define
name|SRST_A_ADB400_COREL2GIC
value|25
end_define

begin_define
define|#
directive|define
name|SRST_P_DBG_L
value|26
end_define

begin_define
define|#
directive|define
name|SRST_L2_L_T
value|28
end_define

begin_define
define|#
directive|define
name|SRST_ADB_L_T
value|29
end_define

begin_define
define|#
directive|define
name|SRST_A_RKPERF_L
value|30
end_define

begin_define
define|#
directive|define
name|SRST_PVTM_CORE_L
value|31
end_define

begin_comment
comment|/* cru_softrst_con2 */
end_comment

begin_define
define|#
directive|define
name|SRST_CORE_B0_T
value|32
end_define

begin_define
define|#
directive|define
name|SRST_CORE_B1
value|33
end_define

begin_define
define|#
directive|define
name|SRST_CORE_PO_B0_T
value|36
end_define

begin_define
define|#
directive|define
name|SRST_CORE_PO_B1
value|37
end_define

begin_define
define|#
directive|define
name|SRST_A_ADB400_GIC2COREB
value|40
end_define

begin_define
define|#
directive|define
name|SRST_A_ADB400_COREB2GIC
value|41
end_define

begin_define
define|#
directive|define
name|SRST_P_DBG_B
value|42
end_define

begin_define
define|#
directive|define
name|SRST_L2_B_T
value|43
end_define

begin_define
define|#
directive|define
name|SRST_ADB_B_T
value|45
end_define

begin_define
define|#
directive|define
name|SRST_A_RKPERF_B
value|46
end_define

begin_define
define|#
directive|define
name|SRST_PVTM_CORE_B
value|47
end_define

begin_comment
comment|/* cru_softrst_con3 */
end_comment

begin_define
define|#
directive|define
name|SRST_A_CCI_T
value|50
end_define

begin_define
define|#
directive|define
name|SRST_A_CCIM0_NOC_T
value|51
end_define

begin_define
define|#
directive|define
name|SRST_A_CCIM1_NOC_T
value|52
end_define

begin_define
define|#
directive|define
name|SRST_A_ADB400M_PD_CORE_B_T
value|53
end_define

begin_define
define|#
directive|define
name|SRST_A_ADB400M_PD_CORE_L_T
value|54
end_define

begin_define
define|#
directive|define
name|SRST_DBG_NOC_T
value|55
end_define

begin_define
define|#
directive|define
name|SRST_DBG_CXCS
value|56
end_define

begin_define
define|#
directive|define
name|SRST_CCI_TRACE
value|57
end_define

begin_define
define|#
directive|define
name|SRST_P_CCI_GRF
value|58
end_define

begin_comment
comment|/* cru_softrst_con4 */
end_comment

begin_define
define|#
directive|define
name|SRST_A_CENTER_MAIN_NOC
value|64
end_define

begin_define
define|#
directive|define
name|SRST_A_CENTER_PERI_NOC
value|65
end_define

begin_define
define|#
directive|define
name|SRST_P_CENTER_MAIN
value|66
end_define

begin_define
define|#
directive|define
name|SRST_P_DDRMON
value|67
end_define

begin_define
define|#
directive|define
name|SRST_P_CIC
value|68
end_define

begin_define
define|#
directive|define
name|SRST_P_CENTER_SGRF
value|69
end_define

begin_define
define|#
directive|define
name|SRST_DDR0_MSCH
value|70
end_define

begin_define
define|#
directive|define
name|SRST_DDRCFG0_MSCH
value|71
end_define

begin_define
define|#
directive|define
name|SRST_DDR0
value|72
end_define

begin_define
define|#
directive|define
name|SRST_DDRPHY0
value|73
end_define

begin_define
define|#
directive|define
name|SRST_DDR1_MSCH
value|74
end_define

begin_define
define|#
directive|define
name|SRST_DDRCFG1_MSCH
value|75
end_define

begin_define
define|#
directive|define
name|SRST_DDR1
value|76
end_define

begin_define
define|#
directive|define
name|SRST_DDRPHY1
value|77
end_define

begin_define
define|#
directive|define
name|SRST_DDR_CIC
value|78
end_define

begin_define
define|#
directive|define
name|SRST_PVTM_DDR
value|79
end_define

begin_comment
comment|/* cru_softrst_con5 */
end_comment

begin_define
define|#
directive|define
name|SRST_A_VCODEC_NOC
value|80
end_define

begin_define
define|#
directive|define
name|SRST_A_VCODEC
value|81
end_define

begin_define
define|#
directive|define
name|SRST_H_VCODEC_NOC
value|82
end_define

begin_define
define|#
directive|define
name|SRST_H_VCODEC
value|83
end_define

begin_define
define|#
directive|define
name|SRST_A_VDU_NOC
value|88
end_define

begin_define
define|#
directive|define
name|SRST_A_VDU
value|89
end_define

begin_define
define|#
directive|define
name|SRST_H_VDU_NOC
value|90
end_define

begin_define
define|#
directive|define
name|SRST_H_VDU
value|91
end_define

begin_define
define|#
directive|define
name|SRST_VDU_CORE
value|92
end_define

begin_define
define|#
directive|define
name|SRST_VDU_CA
value|93
end_define

begin_comment
comment|/* cru_softrst_con6 */
end_comment

begin_define
define|#
directive|define
name|SRST_A_IEP_NOC
value|96
end_define

begin_define
define|#
directive|define
name|SRST_A_VOP_IEP
value|97
end_define

begin_define
define|#
directive|define
name|SRST_A_IEP
value|98
end_define

begin_define
define|#
directive|define
name|SRST_H_IEP_NOC
value|99
end_define

begin_define
define|#
directive|define
name|SRST_H_IEP
value|100
end_define

begin_define
define|#
directive|define
name|SRST_A_RGA_NOC
value|102
end_define

begin_define
define|#
directive|define
name|SRST_A_RGA
value|103
end_define

begin_define
define|#
directive|define
name|SRST_H_RGA_NOC
value|104
end_define

begin_define
define|#
directive|define
name|SRST_H_RGA
value|105
end_define

begin_define
define|#
directive|define
name|SRST_RGA_CORE
value|106
end_define

begin_define
define|#
directive|define
name|SRST_EMMC_NOC
value|108
end_define

begin_define
define|#
directive|define
name|SRST_EMMC
value|109
end_define

begin_define
define|#
directive|define
name|SRST_EMMC_GRF
value|110
end_define

begin_comment
comment|/* cru_softrst_con7 */
end_comment

begin_define
define|#
directive|define
name|SRST_A_PERIHP_NOC
value|112
end_define

begin_define
define|#
directive|define
name|SRST_P_PERIHP_GRF
value|113
end_define

begin_define
define|#
directive|define
name|SRST_H_PERIHP_NOC
value|114
end_define

begin_define
define|#
directive|define
name|SRST_USBHOST0
value|115
end_define

begin_define
define|#
directive|define
name|SRST_HOSTC0_AUX
value|116
end_define

begin_define
define|#
directive|define
name|SRST_HOST0_ARB
value|117
end_define

begin_define
define|#
directive|define
name|SRST_USBHOST1
value|118
end_define

begin_define
define|#
directive|define
name|SRST_HOSTC1_AUX
value|119
end_define

begin_define
define|#
directive|define
name|SRST_HOST1_ARB
value|120
end_define

begin_define
define|#
directive|define
name|SRST_SDIO0
value|121
end_define

begin_define
define|#
directive|define
name|SRST_SDMMC
value|122
end_define

begin_define
define|#
directive|define
name|SRST_HSIC
value|123
end_define

begin_define
define|#
directive|define
name|SRST_HSIC_AUX
value|124
end_define

begin_define
define|#
directive|define
name|SRST_AHB1TOM
value|125
end_define

begin_define
define|#
directive|define
name|SRST_P_PERIHP_NOC
value|126
end_define

begin_define
define|#
directive|define
name|SRST_HSICPHY
value|127
end_define

begin_comment
comment|/* cru_softrst_con8 */
end_comment

begin_define
define|#
directive|define
name|SRST_A_PCIE
value|128
end_define

begin_define
define|#
directive|define
name|SRST_P_PCIE
value|129
end_define

begin_define
define|#
directive|define
name|SRST_PCIE_CORE
value|130
end_define

begin_define
define|#
directive|define
name|SRST_PCIE_MGMT
value|131
end_define

begin_define
define|#
directive|define
name|SRST_PCIE_MGMT_STICKY
value|132
end_define

begin_define
define|#
directive|define
name|SRST_PCIE_PIPE
value|133
end_define

begin_define
define|#
directive|define
name|SRST_PCIE_PM
value|134
end_define

begin_define
define|#
directive|define
name|SRST_PCIEPHY
value|135
end_define

begin_define
define|#
directive|define
name|SRST_A_GMAC_NOC
value|136
end_define

begin_define
define|#
directive|define
name|SRST_A_GMAC
value|137
end_define

begin_define
define|#
directive|define
name|SRST_P_GMAC_NOC
value|138
end_define

begin_define
define|#
directive|define
name|SRST_P_GMAC_GRF
value|140
end_define

begin_define
define|#
directive|define
name|SRST_HSICPHY_POR
value|142
end_define

begin_define
define|#
directive|define
name|SRST_HSICPHY_UTMI
value|143
end_define

begin_comment
comment|/* cru_softrst_con9 */
end_comment

begin_define
define|#
directive|define
name|SRST_USB2PHY0_POR
value|144
end_define

begin_define
define|#
directive|define
name|SRST_USB2PHY0_UTMI_PORT0
value|145
end_define

begin_define
define|#
directive|define
name|SRST_USB2PHY0_UTMI_PORT1
value|146
end_define

begin_define
define|#
directive|define
name|SRST_USB2PHY0_EHCIPHY
value|147
end_define

begin_define
define|#
directive|define
name|SRST_UPHY0_PIPE_L00
value|148
end_define

begin_define
define|#
directive|define
name|SRST_UPHY0
value|149
end_define

begin_define
define|#
directive|define
name|SRST_UPHY0_TCPDPWRUP
value|150
end_define

begin_define
define|#
directive|define
name|SRST_USB2PHY1_POR
value|152
end_define

begin_define
define|#
directive|define
name|SRST_USB2PHY1_UTMI_PORT0
value|153
end_define

begin_define
define|#
directive|define
name|SRST_USB2PHY1_UTMI_PORT1
value|154
end_define

begin_define
define|#
directive|define
name|SRST_USB2PHY1_EHCIPHY
value|155
end_define

begin_define
define|#
directive|define
name|SRST_UPHY1_PIPE_L00
value|156
end_define

begin_define
define|#
directive|define
name|SRST_UPHY1
value|157
end_define

begin_define
define|#
directive|define
name|SRST_UPHY1_TCPDPWRUP
value|158
end_define

begin_comment
comment|/* cru_softrst_con10 */
end_comment

begin_define
define|#
directive|define
name|SRST_A_PERILP0_NOC
value|160
end_define

begin_define
define|#
directive|define
name|SRST_A_DCF
value|161
end_define

begin_define
define|#
directive|define
name|SRST_GIC500
value|162
end_define

begin_define
define|#
directive|define
name|SRST_DMAC0_PERILP0
value|163
end_define

begin_define
define|#
directive|define
name|SRST_DMAC1_PERILP0
value|164
end_define

begin_define
define|#
directive|define
name|SRST_TZMA
value|165
end_define

begin_define
define|#
directive|define
name|SRST_INTMEM
value|166
end_define

begin_define
define|#
directive|define
name|SRST_ADB400_MST0
value|167
end_define

begin_define
define|#
directive|define
name|SRST_ADB400_MST1
value|168
end_define

begin_define
define|#
directive|define
name|SRST_ADB400_SLV0
value|169
end_define

begin_define
define|#
directive|define
name|SRST_ADB400_SLV1
value|170
end_define

begin_define
define|#
directive|define
name|SRST_H_PERILP0
value|171
end_define

begin_define
define|#
directive|define
name|SRST_H_PERILP0_NOC
value|172
end_define

begin_define
define|#
directive|define
name|SRST_ROM
value|173
end_define

begin_define
define|#
directive|define
name|SRST_CRYPTO_S
value|174
end_define

begin_define
define|#
directive|define
name|SRST_CRYPTO_M
value|175
end_define

begin_comment
comment|/* cru_softrst_con11 */
end_comment

begin_define
define|#
directive|define
name|SRST_P_DCF
value|176
end_define

begin_define
define|#
directive|define
name|SRST_CM0S_NOC
value|177
end_define

begin_define
define|#
directive|define
name|SRST_CM0S
value|178
end_define

begin_define
define|#
directive|define
name|SRST_CM0S_DBG
value|179
end_define

begin_define
define|#
directive|define
name|SRST_CM0S_PO
value|180
end_define

begin_define
define|#
directive|define
name|SRST_CRYPTO
value|181
end_define

begin_define
define|#
directive|define
name|SRST_P_PERILP1_SGRF
value|182
end_define

begin_define
define|#
directive|define
name|SRST_P_PERILP1_GRF
value|183
end_define

begin_define
define|#
directive|define
name|SRST_CRYPTO1_S
value|184
end_define

begin_define
define|#
directive|define
name|SRST_CRYPTO1_M
value|185
end_define

begin_define
define|#
directive|define
name|SRST_CRYPTO1
value|186
end_define

begin_define
define|#
directive|define
name|SRST_GIC_NOC
value|188
end_define

begin_define
define|#
directive|define
name|SRST_SD_NOC
value|189
end_define

begin_define
define|#
directive|define
name|SRST_SDIOAUDIO_BRG
value|190
end_define

begin_comment
comment|/* cru_softrst_con12 */
end_comment

begin_define
define|#
directive|define
name|SRST_H_PERILP1
value|192
end_define

begin_define
define|#
directive|define
name|SRST_H_PERILP1_NOC
value|193
end_define

begin_define
define|#
directive|define
name|SRST_H_I2S0_8CH
value|194
end_define

begin_define
define|#
directive|define
name|SRST_H_I2S1_8CH
value|195
end_define

begin_define
define|#
directive|define
name|SRST_H_I2S2_8CH
value|196
end_define

begin_define
define|#
directive|define
name|SRST_H_SPDIF_8CH
value|197
end_define

begin_define
define|#
directive|define
name|SRST_P_PERILP1_NOC
value|198
end_define

begin_define
define|#
directive|define
name|SRST_P_EFUSE_1024
value|199
end_define

begin_define
define|#
directive|define
name|SRST_P_EFUSE_1024S
value|200
end_define

begin_define
define|#
directive|define
name|SRST_P_I2C0
value|201
end_define

begin_define
define|#
directive|define
name|SRST_P_I2C1
value|202
end_define

begin_define
define|#
directive|define
name|SRST_P_I2C2
value|203
end_define

begin_define
define|#
directive|define
name|SRST_P_I2C3
value|204
end_define

begin_define
define|#
directive|define
name|SRST_P_I2C4
value|205
end_define

begin_define
define|#
directive|define
name|SRST_P_I2C5
value|206
end_define

begin_define
define|#
directive|define
name|SRST_P_MAILBOX0
value|207
end_define

begin_comment
comment|/* cru_softrst_con13 */
end_comment

begin_define
define|#
directive|define
name|SRST_P_UART0
value|208
end_define

begin_define
define|#
directive|define
name|SRST_P_UART1
value|209
end_define

begin_define
define|#
directive|define
name|SRST_P_UART2
value|210
end_define

begin_define
define|#
directive|define
name|SRST_P_UART3
value|211
end_define

begin_define
define|#
directive|define
name|SRST_P_SARADC
value|212
end_define

begin_define
define|#
directive|define
name|SRST_P_TSADC
value|213
end_define

begin_define
define|#
directive|define
name|SRST_P_SPI0
value|214
end_define

begin_define
define|#
directive|define
name|SRST_P_SPI1
value|215
end_define

begin_define
define|#
directive|define
name|SRST_P_SPI2
value|216
end_define

begin_define
define|#
directive|define
name|SRST_P_SPI3
value|217
end_define

begin_define
define|#
directive|define
name|SRST_P_SPI4
value|218
end_define

begin_define
define|#
directive|define
name|SRST_SPI0
value|219
end_define

begin_define
define|#
directive|define
name|SRST_SPI1
value|220
end_define

begin_define
define|#
directive|define
name|SRST_SPI2
value|221
end_define

begin_define
define|#
directive|define
name|SRST_SPI3
value|222
end_define

begin_define
define|#
directive|define
name|SRST_SPI4
value|223
end_define

begin_comment
comment|/* cru_softrst_con14 */
end_comment

begin_define
define|#
directive|define
name|SRST_I2S0_8CH
value|224
end_define

begin_define
define|#
directive|define
name|SRST_I2S1_8CH
value|225
end_define

begin_define
define|#
directive|define
name|SRST_I2S2_8CH
value|226
end_define

begin_define
define|#
directive|define
name|SRST_SPDIF_8CH
value|227
end_define

begin_define
define|#
directive|define
name|SRST_UART0
value|228
end_define

begin_define
define|#
directive|define
name|SRST_UART1
value|229
end_define

begin_define
define|#
directive|define
name|SRST_UART2
value|230
end_define

begin_define
define|#
directive|define
name|SRST_UART3
value|231
end_define

begin_define
define|#
directive|define
name|SRST_TSADC
value|232
end_define

begin_define
define|#
directive|define
name|SRST_I2C0
value|233
end_define

begin_define
define|#
directive|define
name|SRST_I2C1
value|234
end_define

begin_define
define|#
directive|define
name|SRST_I2C2
value|235
end_define

begin_define
define|#
directive|define
name|SRST_I2C3
value|236
end_define

begin_define
define|#
directive|define
name|SRST_I2C4
value|237
end_define

begin_define
define|#
directive|define
name|SRST_I2C5
value|238
end_define

begin_define
define|#
directive|define
name|SRST_SDIOAUDIO_NOC
value|239
end_define

begin_comment
comment|/* cru_softrst_con15 */
end_comment

begin_define
define|#
directive|define
name|SRST_A_VIO_NOC
value|240
end_define

begin_define
define|#
directive|define
name|SRST_A_HDCP_NOC
value|241
end_define

begin_define
define|#
directive|define
name|SRST_A_HDCP
value|242
end_define

begin_define
define|#
directive|define
name|SRST_H_HDCP_NOC
value|243
end_define

begin_define
define|#
directive|define
name|SRST_H_HDCP
value|244
end_define

begin_define
define|#
directive|define
name|SRST_P_HDCP_NOC
value|245
end_define

begin_define
define|#
directive|define
name|SRST_P_HDCP
value|246
end_define

begin_define
define|#
directive|define
name|SRST_P_HDMI_CTRL
value|247
end_define

begin_define
define|#
directive|define
name|SRST_P_DP_CTRL
value|248
end_define

begin_define
define|#
directive|define
name|SRST_S_DP_CTRL
value|249
end_define

begin_define
define|#
directive|define
name|SRST_C_DP_CTRL
value|250
end_define

begin_define
define|#
directive|define
name|SRST_P_MIPI_DSI0
value|251
end_define

begin_define
define|#
directive|define
name|SRST_P_MIPI_DSI1
value|252
end_define

begin_define
define|#
directive|define
name|SRST_DP_CORE
value|253
end_define

begin_define
define|#
directive|define
name|SRST_DP_I2S
value|254
end_define

begin_comment
comment|/* cru_softrst_con16 */
end_comment

begin_define
define|#
directive|define
name|SRST_GASKET
value|256
end_define

begin_define
define|#
directive|define
name|SRST_VIO_GRF
value|258
end_define

begin_define
define|#
directive|define
name|SRST_DPTX_SPDIF_REC
value|259
end_define

begin_define
define|#
directive|define
name|SRST_HDMI_CTRL
value|260
end_define

begin_define
define|#
directive|define
name|SRST_HDCP_CTRL
value|261
end_define

begin_define
define|#
directive|define
name|SRST_A_ISP0_NOC
value|262
end_define

begin_define
define|#
directive|define
name|SRST_A_ISP1_NOC
value|263
end_define

begin_define
define|#
directive|define
name|SRST_H_ISP0_NOC
value|266
end_define

begin_define
define|#
directive|define
name|SRST_H_ISP1_NOC
value|267
end_define

begin_define
define|#
directive|define
name|SRST_H_ISP0
value|268
end_define

begin_define
define|#
directive|define
name|SRST_H_ISP1
value|269
end_define

begin_define
define|#
directive|define
name|SRST_ISP0
value|270
end_define

begin_define
define|#
directive|define
name|SRST_ISP1
value|271
end_define

begin_comment
comment|/* cru_softrst_con17 */
end_comment

begin_define
define|#
directive|define
name|SRST_A_VOP0_NOC
value|272
end_define

begin_define
define|#
directive|define
name|SRST_A_VOP1_NOC
value|273
end_define

begin_define
define|#
directive|define
name|SRST_A_VOP0
value|274
end_define

begin_define
define|#
directive|define
name|SRST_A_VOP1
value|275
end_define

begin_define
define|#
directive|define
name|SRST_H_VOP0_NOC
value|276
end_define

begin_define
define|#
directive|define
name|SRST_H_VOP1_NOC
value|277
end_define

begin_define
define|#
directive|define
name|SRST_H_VOP0
value|278
end_define

begin_define
define|#
directive|define
name|SRST_H_VOP1
value|279
end_define

begin_define
define|#
directive|define
name|SRST_D_VOP0
value|280
end_define

begin_define
define|#
directive|define
name|SRST_D_VOP1
value|281
end_define

begin_define
define|#
directive|define
name|SRST_VOP0_PWM
value|282
end_define

begin_define
define|#
directive|define
name|SRST_VOP1_PWM
value|283
end_define

begin_define
define|#
directive|define
name|SRST_P_EDP_NOC
value|284
end_define

begin_define
define|#
directive|define
name|SRST_P_EDP_CTRL
value|285
end_define

begin_comment
comment|/* cru_softrst_con18 */
end_comment

begin_define
define|#
directive|define
name|SRST_A_GPU
value|288
end_define

begin_define
define|#
directive|define
name|SRST_A_GPU_NOC
value|289
end_define

begin_define
define|#
directive|define
name|SRST_A_GPU_GRF
value|290
end_define

begin_define
define|#
directive|define
name|SRST_PVTM_GPU
value|291
end_define

begin_define
define|#
directive|define
name|SRST_A_USB3_NOC
value|292
end_define

begin_define
define|#
directive|define
name|SRST_A_USB3_OTG0
value|293
end_define

begin_define
define|#
directive|define
name|SRST_A_USB3_OTG1
value|294
end_define

begin_define
define|#
directive|define
name|SRST_A_USB3_GRF
value|295
end_define

begin_define
define|#
directive|define
name|SRST_PMU
value|296
end_define

begin_comment
comment|/* cru_softrst_con19 */
end_comment

begin_define
define|#
directive|define
name|SRST_P_TIMER0_5
value|304
end_define

begin_define
define|#
directive|define
name|SRST_TIMER0
value|305
end_define

begin_define
define|#
directive|define
name|SRST_TIMER1
value|306
end_define

begin_define
define|#
directive|define
name|SRST_TIMER2
value|307
end_define

begin_define
define|#
directive|define
name|SRST_TIMER3
value|308
end_define

begin_define
define|#
directive|define
name|SRST_TIMER4
value|309
end_define

begin_define
define|#
directive|define
name|SRST_TIMER5
value|310
end_define

begin_define
define|#
directive|define
name|SRST_P_TIMER6_11
value|311
end_define

begin_define
define|#
directive|define
name|SRST_TIMER6
value|312
end_define

begin_define
define|#
directive|define
name|SRST_TIMER7
value|313
end_define

begin_define
define|#
directive|define
name|SRST_TIMER8
value|314
end_define

begin_define
define|#
directive|define
name|SRST_TIMER9
value|315
end_define

begin_define
define|#
directive|define
name|SRST_TIMER10
value|316
end_define

begin_define
define|#
directive|define
name|SRST_TIMER11
value|317
end_define

begin_define
define|#
directive|define
name|SRST_P_INTR_ARB_PMU
value|318
end_define

begin_define
define|#
directive|define
name|SRST_P_ALIVE_SGRF
value|319
end_define

begin_comment
comment|/* cru_softrst_con20 */
end_comment

begin_define
define|#
directive|define
name|SRST_P_GPIO2
value|320
end_define

begin_define
define|#
directive|define
name|SRST_P_GPIO3
value|321
end_define

begin_define
define|#
directive|define
name|SRST_P_GPIO4
value|322
end_define

begin_define
define|#
directive|define
name|SRST_P_GRF
value|323
end_define

begin_define
define|#
directive|define
name|SRST_P_ALIVE_NOC
value|324
end_define

begin_define
define|#
directive|define
name|SRST_P_WDT0
value|325
end_define

begin_define
define|#
directive|define
name|SRST_P_WDT1
value|326
end_define

begin_define
define|#
directive|define
name|SRST_P_INTR_ARB
value|327
end_define

begin_define
define|#
directive|define
name|SRST_P_UPHY0_DPTX
value|328
end_define

begin_define
define|#
directive|define
name|SRST_P_UPHY0_APB
value|330
end_define

begin_define
define|#
directive|define
name|SRST_P_UPHY0_TCPHY
value|332
end_define

begin_define
define|#
directive|define
name|SRST_P_UPHY1_TCPHY
value|333
end_define

begin_define
define|#
directive|define
name|SRST_P_UPHY0_TCPDCTRL
value|334
end_define

begin_define
define|#
directive|define
name|SRST_P_UPHY1_TCPDCTRL
value|335
end_define

begin_comment
comment|/* pmu soft-reset indices */
end_comment

begin_comment
comment|/* pmu_cru_softrst_con0 */
end_comment

begin_define
define|#
directive|define
name|SRST_P_NOC
value|0
end_define

begin_define
define|#
directive|define
name|SRST_P_INTMEM
value|1
end_define

begin_define
define|#
directive|define
name|SRST_H_CM0S
value|2
end_define

begin_define
define|#
directive|define
name|SRST_H_CM0S_NOC
value|3
end_define

begin_define
define|#
directive|define
name|SRST_DBG_CM0S
value|4
end_define

begin_define
define|#
directive|define
name|SRST_PO_CM0S
value|5
end_define

begin_define
define|#
directive|define
name|SRST_P_SPI6
value|6
end_define

begin_define
define|#
directive|define
name|SRST_SPI6
value|7
end_define

begin_define
define|#
directive|define
name|SRST_P_TIMER_0_1
value|8
end_define

begin_define
define|#
directive|define
name|SRST_P_TIMER_0
value|9
end_define

begin_define
define|#
directive|define
name|SRST_P_TIMER_1
value|10
end_define

begin_define
define|#
directive|define
name|SRST_P_UART4
value|11
end_define

begin_define
define|#
directive|define
name|SRST_UART4
value|12
end_define

begin_define
define|#
directive|define
name|SRST_P_WDT
value|13
end_define

begin_comment
comment|/* pmu_cru_softrst_con1 */
end_comment

begin_define
define|#
directive|define
name|SRST_P_I2C6
value|16
end_define

begin_define
define|#
directive|define
name|SRST_P_I2C7
value|17
end_define

begin_define
define|#
directive|define
name|SRST_P_I2C8
value|18
end_define

begin_define
define|#
directive|define
name|SRST_P_MAILBOX
value|19
end_define

begin_define
define|#
directive|define
name|SRST_P_RKPWM
value|20
end_define

begin_define
define|#
directive|define
name|SRST_P_PMUGRF
value|21
end_define

begin_define
define|#
directive|define
name|SRST_P_SGRF
value|22
end_define

begin_define
define|#
directive|define
name|SRST_P_GPIO0
value|23
end_define

begin_define
define|#
directive|define
name|SRST_P_GPIO1
value|24
end_define

begin_define
define|#
directive|define
name|SRST_P_CRU
value|25
end_define

begin_define
define|#
directive|define
name|SRST_P_INTR
value|26
end_define

begin_define
define|#
directive|define
name|SRST_PVTM
value|27
end_define

begin_define
define|#
directive|define
name|SRST_I2C6
value|28
end_define

begin_define
define|#
directive|define
name|SRST_I2C7
value|29
end_define

begin_define
define|#
directive|define
name|SRST_I2C8
value|30
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

