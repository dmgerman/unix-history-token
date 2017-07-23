begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2016 Rockchip Electronics Co. Ltd.  * Author: Elaine<zhangqing@rock-chips.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLK_ROCKCHIP_RK3328_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLK_ROCKCHIP_RK3328_H
end_define

begin_comment
comment|/* core clocks */
end_comment

begin_define
define|#
directive|define
name|PLL_APLL
value|1
end_define

begin_define
define|#
directive|define
name|PLL_DPLL
value|2
end_define

begin_define
define|#
directive|define
name|PLL_CPLL
value|3
end_define

begin_define
define|#
directive|define
name|PLL_GPLL
value|4
end_define

begin_define
define|#
directive|define
name|PLL_NPLL
value|5
end_define

begin_define
define|#
directive|define
name|ARMCLK
value|6
end_define

begin_comment
comment|/* sclk gates (special clocks) */
end_comment

begin_define
define|#
directive|define
name|SCLK_RTC32K
value|30
end_define

begin_define
define|#
directive|define
name|SCLK_SDMMC_EXT
value|31
end_define

begin_define
define|#
directive|define
name|SCLK_SPI
value|32
end_define

begin_define
define|#
directive|define
name|SCLK_SDMMC
value|33
end_define

begin_define
define|#
directive|define
name|SCLK_SDIO
value|34
end_define

begin_define
define|#
directive|define
name|SCLK_EMMC
value|35
end_define

begin_define
define|#
directive|define
name|SCLK_TSADC
value|36
end_define

begin_define
define|#
directive|define
name|SCLK_SARADC
value|37
end_define

begin_define
define|#
directive|define
name|SCLK_UART0
value|38
end_define

begin_define
define|#
directive|define
name|SCLK_UART1
value|39
end_define

begin_define
define|#
directive|define
name|SCLK_UART2
value|40
end_define

begin_define
define|#
directive|define
name|SCLK_I2S0
value|41
end_define

begin_define
define|#
directive|define
name|SCLK_I2S1
value|42
end_define

begin_define
define|#
directive|define
name|SCLK_I2S2
value|43
end_define

begin_define
define|#
directive|define
name|SCLK_I2S1_OUT
value|44
end_define

begin_define
define|#
directive|define
name|SCLK_I2S2_OUT
value|45
end_define

begin_define
define|#
directive|define
name|SCLK_SPDIF
value|46
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER0
value|47
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER1
value|48
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER2
value|49
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER3
value|50
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER4
value|51
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER5
value|52
end_define

begin_define
define|#
directive|define
name|SCLK_WIFI
value|53
end_define

begin_define
define|#
directive|define
name|SCLK_CIF_OUT
value|54
end_define

begin_define
define|#
directive|define
name|SCLK_I2C0
value|55
end_define

begin_define
define|#
directive|define
name|SCLK_I2C1
value|56
end_define

begin_define
define|#
directive|define
name|SCLK_I2C2
value|57
end_define

begin_define
define|#
directive|define
name|SCLK_I2C3
value|58
end_define

begin_define
define|#
directive|define
name|SCLK_CRYPTO
value|59
end_define

begin_define
define|#
directive|define
name|SCLK_PWM
value|60
end_define

begin_define
define|#
directive|define
name|SCLK_PDM
value|61
end_define

begin_define
define|#
directive|define
name|SCLK_EFUSE
value|62
end_define

begin_define
define|#
directive|define
name|SCLK_OTP
value|63
end_define

begin_define
define|#
directive|define
name|SCLK_DDRCLK
value|64
end_define

begin_define
define|#
directive|define
name|SCLK_VDEC_CABAC
value|65
end_define

begin_define
define|#
directive|define
name|SCLK_VDEC_CORE
value|66
end_define

begin_define
define|#
directive|define
name|SCLK_VENC_DSP
value|67
end_define

begin_define
define|#
directive|define
name|SCLK_VENC_CORE
value|68
end_define

begin_define
define|#
directive|define
name|SCLK_RGA
value|69
end_define

begin_define
define|#
directive|define
name|SCLK_HDMI_SFC
value|70
end_define

begin_define
define|#
directive|define
name|SCLK_HDMI_CEC
value|71
end_define

begin_define
define|#
directive|define
name|SCLK_USB3_REF
value|72
end_define

begin_define
define|#
directive|define
name|SCLK_USB3_SUSPEND
value|73
end_define

begin_define
define|#
directive|define
name|SCLK_SDMMC_DRV
value|74
end_define

begin_define
define|#
directive|define
name|SCLK_SDIO_DRV
value|75
end_define

begin_define
define|#
directive|define
name|SCLK_EMMC_DRV
value|76
end_define

begin_define
define|#
directive|define
name|SCLK_SDMMC_EXT_DRV
value|77
end_define

begin_define
define|#
directive|define
name|SCLK_SDMMC_SAMPLE
value|78
end_define

begin_define
define|#
directive|define
name|SCLK_SDIO_SAMPLE
value|79
end_define

begin_define
define|#
directive|define
name|SCLK_EMMC_SAMPLE
value|80
end_define

begin_define
define|#
directive|define
name|SCLK_SDMMC_EXT_SAMPLE
value|81
end_define

begin_define
define|#
directive|define
name|SCLK_VOP
value|82
end_define

begin_define
define|#
directive|define
name|SCLK_MAC2PHY_RXTX
value|83
end_define

begin_define
define|#
directive|define
name|SCLK_MAC2PHY_SRC
value|84
end_define

begin_define
define|#
directive|define
name|SCLK_MAC2PHY_REF
value|85
end_define

begin_define
define|#
directive|define
name|SCLK_MAC2PHY_OUT
value|86
end_define

begin_define
define|#
directive|define
name|SCLK_MAC2IO_RX
value|87
end_define

begin_define
define|#
directive|define
name|SCLK_MAC2IO_TX
value|88
end_define

begin_define
define|#
directive|define
name|SCLK_MAC2IO_REFOUT
value|89
end_define

begin_define
define|#
directive|define
name|SCLK_MAC2IO_REF
value|90
end_define

begin_define
define|#
directive|define
name|SCLK_MAC2IO_OUT
value|91
end_define

begin_define
define|#
directive|define
name|SCLK_TSP
value|92
end_define

begin_define
define|#
directive|define
name|SCLK_HSADC_TSP
value|93
end_define

begin_define
define|#
directive|define
name|SCLK_USB3PHY_REF
value|94
end_define

begin_define
define|#
directive|define
name|SCLK_REF_USB3OTG
value|95
end_define

begin_define
define|#
directive|define
name|SCLK_USB3OTG_REF
value|96
end_define

begin_define
define|#
directive|define
name|SCLK_USB3OTG_SUSPEND
value|97
end_define

begin_define
define|#
directive|define
name|SCLK_REF_USB3OTG_SRC
value|98
end_define

begin_define
define|#
directive|define
name|SCLK_MAC2IO_SRC
value|99
end_define

begin_define
define|#
directive|define
name|SCLK_MAC2IO
value|100
end_define

begin_define
define|#
directive|define
name|SCLK_MAC2PHY
value|101
end_define

begin_define
define|#
directive|define
name|SCLK_MAC2IO_EXT
value|102
end_define

begin_comment
comment|/* dclk gates */
end_comment

begin_define
define|#
directive|define
name|DCLK_LCDC
value|120
end_define

begin_define
define|#
directive|define
name|DCLK_HDMIPHY
value|121
end_define

begin_define
define|#
directive|define
name|HDMIPHY
value|122
end_define

begin_define
define|#
directive|define
name|USB480M
value|123
end_define

begin_define
define|#
directive|define
name|DCLK_LCDC_SRC
value|124
end_define

begin_comment
comment|/* aclk gates */
end_comment

begin_define
define|#
directive|define
name|ACLK_AXISRAM
value|130
end_define

begin_define
define|#
directive|define
name|ACLK_VOP_PRE
value|131
end_define

begin_define
define|#
directive|define
name|ACLK_USB3OTG
value|132
end_define

begin_define
define|#
directive|define
name|ACLK_RGA_PRE
value|133
end_define

begin_define
define|#
directive|define
name|ACLK_DMAC
value|134
end_define

begin_define
define|#
directive|define
name|ACLK_GPU
value|135
end_define

begin_define
define|#
directive|define
name|ACLK_BUS_PRE
value|136
end_define

begin_define
define|#
directive|define
name|ACLK_PERI_PRE
value|137
end_define

begin_define
define|#
directive|define
name|ACLK_RKVDEC_PRE
value|138
end_define

begin_define
define|#
directive|define
name|ACLK_RKVDEC
value|139
end_define

begin_define
define|#
directive|define
name|ACLK_RKVENC
value|140
end_define

begin_define
define|#
directive|define
name|ACLK_VPU_PRE
value|141
end_define

begin_define
define|#
directive|define
name|ACLK_VIO_PRE
value|142
end_define

begin_define
define|#
directive|define
name|ACLK_VPU
value|143
end_define

begin_define
define|#
directive|define
name|ACLK_VIO
value|144
end_define

begin_define
define|#
directive|define
name|ACLK_VOP
value|145
end_define

begin_define
define|#
directive|define
name|ACLK_GMAC
value|146
end_define

begin_define
define|#
directive|define
name|ACLK_H265
value|147
end_define

begin_define
define|#
directive|define
name|ACLK_H264
value|148
end_define

begin_define
define|#
directive|define
name|ACLK_MAC2PHY
value|149
end_define

begin_define
define|#
directive|define
name|ACLK_MAC2IO
value|150
end_define

begin_define
define|#
directive|define
name|ACLK_DCF
value|151
end_define

begin_define
define|#
directive|define
name|ACLK_TSP
value|152
end_define

begin_define
define|#
directive|define
name|ACLK_PERI
value|153
end_define

begin_define
define|#
directive|define
name|ACLK_RGA
value|154
end_define

begin_define
define|#
directive|define
name|ACLK_IEP
value|155
end_define

begin_define
define|#
directive|define
name|ACLK_CIF
value|156
end_define

begin_define
define|#
directive|define
name|ACLK_HDCP
value|157
end_define

begin_comment
comment|/* pclk gates */
end_comment

begin_define
define|#
directive|define
name|PCLK_GPIO0
value|200
end_define

begin_define
define|#
directive|define
name|PCLK_GPIO1
value|201
end_define

begin_define
define|#
directive|define
name|PCLK_GPIO2
value|202
end_define

begin_define
define|#
directive|define
name|PCLK_GPIO3
value|203
end_define

begin_define
define|#
directive|define
name|PCLK_GRF
value|204
end_define

begin_define
define|#
directive|define
name|PCLK_I2C0
value|205
end_define

begin_define
define|#
directive|define
name|PCLK_I2C1
value|206
end_define

begin_define
define|#
directive|define
name|PCLK_I2C2
value|207
end_define

begin_define
define|#
directive|define
name|PCLK_I2C3
value|208
end_define

begin_define
define|#
directive|define
name|PCLK_SPI
value|209
end_define

begin_define
define|#
directive|define
name|PCLK_UART0
value|210
end_define

begin_define
define|#
directive|define
name|PCLK_UART1
value|211
end_define

begin_define
define|#
directive|define
name|PCLK_UART2
value|212
end_define

begin_define
define|#
directive|define
name|PCLK_TSADC
value|213
end_define

begin_define
define|#
directive|define
name|PCLK_PWM
value|214
end_define

begin_define
define|#
directive|define
name|PCLK_TIMER
value|215
end_define

begin_define
define|#
directive|define
name|PCLK_BUS_PRE
value|216
end_define

begin_define
define|#
directive|define
name|PCLK_PERI_PRE
value|217
end_define

begin_define
define|#
directive|define
name|PCLK_HDMI_CTRL
value|218
end_define

begin_define
define|#
directive|define
name|PCLK_HDMI_PHY
value|219
end_define

begin_define
define|#
directive|define
name|PCLK_GMAC
value|220
end_define

begin_define
define|#
directive|define
name|PCLK_H265
value|221
end_define

begin_define
define|#
directive|define
name|PCLK_MAC2PHY
value|222
end_define

begin_define
define|#
directive|define
name|PCLK_MAC2IO
value|223
end_define

begin_define
define|#
directive|define
name|PCLK_USB3PHY_OTG
value|224
end_define

begin_define
define|#
directive|define
name|PCLK_USB3PHY_PIPE
value|225
end_define

begin_define
define|#
directive|define
name|PCLK_USB3_GRF
value|226
end_define

begin_define
define|#
directive|define
name|PCLK_USB2_GRF
value|227
end_define

begin_define
define|#
directive|define
name|PCLK_HDMIPHY
value|228
end_define

begin_define
define|#
directive|define
name|PCLK_DDR
value|229
end_define

begin_define
define|#
directive|define
name|PCLK_PERI
value|230
end_define

begin_define
define|#
directive|define
name|PCLK_HDMI
value|231
end_define

begin_define
define|#
directive|define
name|PCLK_HDCP
value|232
end_define

begin_define
define|#
directive|define
name|PCLK_DCF
value|233
end_define

begin_define
define|#
directive|define
name|PCLK_SARADC
value|234
end_define

begin_comment
comment|/* hclk gates */
end_comment

begin_define
define|#
directive|define
name|HCLK_PERI
value|308
end_define

begin_define
define|#
directive|define
name|HCLK_TSP
value|309
end_define

begin_define
define|#
directive|define
name|HCLK_GMAC
value|310
end_define

begin_define
define|#
directive|define
name|HCLK_I2S0_8CH
value|311
end_define

begin_define
define|#
directive|define
name|HCLK_I2S1_8CH
value|313
end_define

begin_define
define|#
directive|define
name|HCLK_I2S2_2CH
value|313
end_define

begin_define
define|#
directive|define
name|HCLK_SPDIF_8CH
value|314
end_define

begin_define
define|#
directive|define
name|HCLK_VOP
value|315
end_define

begin_define
define|#
directive|define
name|HCLK_NANDC
value|316
end_define

begin_define
define|#
directive|define
name|HCLK_SDMMC
value|317
end_define

begin_define
define|#
directive|define
name|HCLK_SDIO
value|318
end_define

begin_define
define|#
directive|define
name|HCLK_EMMC
value|319
end_define

begin_define
define|#
directive|define
name|HCLK_SDMMC_EXT
value|320
end_define

begin_define
define|#
directive|define
name|HCLK_RKVDEC_PRE
value|321
end_define

begin_define
define|#
directive|define
name|HCLK_RKVDEC
value|322
end_define

begin_define
define|#
directive|define
name|HCLK_RKVENC
value|323
end_define

begin_define
define|#
directive|define
name|HCLK_VPU_PRE
value|324
end_define

begin_define
define|#
directive|define
name|HCLK_VIO_PRE
value|325
end_define

begin_define
define|#
directive|define
name|HCLK_VPU
value|326
end_define

begin_define
define|#
directive|define
name|HCLK_VIO
value|327
end_define

begin_define
define|#
directive|define
name|HCLK_BUS_PRE
value|328
end_define

begin_define
define|#
directive|define
name|HCLK_PERI_PRE
value|329
end_define

begin_define
define|#
directive|define
name|HCLK_H264
value|330
end_define

begin_define
define|#
directive|define
name|HCLK_CIF
value|331
end_define

begin_define
define|#
directive|define
name|HCLK_OTG_PMU
value|332
end_define

begin_define
define|#
directive|define
name|HCLK_OTG
value|333
end_define

begin_define
define|#
directive|define
name|HCLK_HOST0
value|334
end_define

begin_define
define|#
directive|define
name|HCLK_HOST0_ARB
value|335
end_define

begin_define
define|#
directive|define
name|HCLK_CRYPTO_MST
value|336
end_define

begin_define
define|#
directive|define
name|HCLK_CRYPTO_SLV
value|337
end_define

begin_define
define|#
directive|define
name|HCLK_PDM
value|338
end_define

begin_define
define|#
directive|define
name|HCLK_IEP
value|339
end_define

begin_define
define|#
directive|define
name|HCLK_RGA
value|340
end_define

begin_define
define|#
directive|define
name|HCLK_HDCP
value|341
end_define

begin_define
define|#
directive|define
name|CLK_NR_CLKS
value|(HCLK_HDCP + 1)
end_define

begin_comment
comment|/* soft-reset indices */
end_comment

begin_define
define|#
directive|define
name|SRST_CORE0_PO
value|0
end_define

begin_define
define|#
directive|define
name|SRST_CORE1_PO
value|1
end_define

begin_define
define|#
directive|define
name|SRST_CORE2_PO
value|2
end_define

begin_define
define|#
directive|define
name|SRST_CORE3_PO
value|3
end_define

begin_define
define|#
directive|define
name|SRST_CORE0
value|4
end_define

begin_define
define|#
directive|define
name|SRST_CORE1
value|5
end_define

begin_define
define|#
directive|define
name|SRST_CORE2
value|6
end_define

begin_define
define|#
directive|define
name|SRST_CORE3
value|7
end_define

begin_define
define|#
directive|define
name|SRST_CORE0_DBG
value|8
end_define

begin_define
define|#
directive|define
name|SRST_CORE1_DBG
value|9
end_define

begin_define
define|#
directive|define
name|SRST_CORE2_DBG
value|10
end_define

begin_define
define|#
directive|define
name|SRST_CORE3_DBG
value|11
end_define

begin_define
define|#
directive|define
name|SRST_TOPDBG
value|12
end_define

begin_define
define|#
directive|define
name|SRST_CORE_NIU
value|13
end_define

begin_define
define|#
directive|define
name|SRST_STRC_A
value|14
end_define

begin_define
define|#
directive|define
name|SRST_L2C
value|15
end_define

begin_define
define|#
directive|define
name|SRST_A53_GIC
value|18
end_define

begin_define
define|#
directive|define
name|SRST_DAP
value|19
end_define

begin_define
define|#
directive|define
name|SRST_PMU_P
value|21
end_define

begin_define
define|#
directive|define
name|SRST_EFUSE
value|22
end_define

begin_define
define|#
directive|define
name|SRST_BUSSYS_H
value|23
end_define

begin_define
define|#
directive|define
name|SRST_BUSSYS_P
value|24
end_define

begin_define
define|#
directive|define
name|SRST_SPDIF
value|25
end_define

begin_define
define|#
directive|define
name|SRST_INTMEM
value|26
end_define

begin_define
define|#
directive|define
name|SRST_ROM
value|27
end_define

begin_define
define|#
directive|define
name|SRST_GPIO0
value|28
end_define

begin_define
define|#
directive|define
name|SRST_GPIO1
value|29
end_define

begin_define
define|#
directive|define
name|SRST_GPIO2
value|30
end_define

begin_define
define|#
directive|define
name|SRST_GPIO3
value|31
end_define

begin_define
define|#
directive|define
name|SRST_I2S0
value|32
end_define

begin_define
define|#
directive|define
name|SRST_I2S1
value|33
end_define

begin_define
define|#
directive|define
name|SRST_I2S2
value|34
end_define

begin_define
define|#
directive|define
name|SRST_I2S0_H
value|35
end_define

begin_define
define|#
directive|define
name|SRST_I2S1_H
value|36
end_define

begin_define
define|#
directive|define
name|SRST_I2S2_H
value|37
end_define

begin_define
define|#
directive|define
name|SRST_UART0
value|38
end_define

begin_define
define|#
directive|define
name|SRST_UART1
value|39
end_define

begin_define
define|#
directive|define
name|SRST_UART2
value|40
end_define

begin_define
define|#
directive|define
name|SRST_UART0_P
value|41
end_define

begin_define
define|#
directive|define
name|SRST_UART1_P
value|42
end_define

begin_define
define|#
directive|define
name|SRST_UART2_P
value|43
end_define

begin_define
define|#
directive|define
name|SRST_I2C0
value|44
end_define

begin_define
define|#
directive|define
name|SRST_I2C1
value|45
end_define

begin_define
define|#
directive|define
name|SRST_I2C2
value|46
end_define

begin_define
define|#
directive|define
name|SRST_I2C3
value|47
end_define

begin_define
define|#
directive|define
name|SRST_I2C0_P
value|48
end_define

begin_define
define|#
directive|define
name|SRST_I2C1_P
value|49
end_define

begin_define
define|#
directive|define
name|SRST_I2C2_P
value|50
end_define

begin_define
define|#
directive|define
name|SRST_I2C3_P
value|51
end_define

begin_define
define|#
directive|define
name|SRST_EFUSE_SE_P
value|52
end_define

begin_define
define|#
directive|define
name|SRST_EFUSE_NS_P
value|53
end_define

begin_define
define|#
directive|define
name|SRST_PWM0
value|54
end_define

begin_define
define|#
directive|define
name|SRST_PWM0_P
value|55
end_define

begin_define
define|#
directive|define
name|SRST_DMA
value|56
end_define

begin_define
define|#
directive|define
name|SRST_TSP_A
value|57
end_define

begin_define
define|#
directive|define
name|SRST_TSP_H
value|58
end_define

begin_define
define|#
directive|define
name|SRST_TSP
value|59
end_define

begin_define
define|#
directive|define
name|SRST_TSP_HSADC
value|60
end_define

begin_define
define|#
directive|define
name|SRST_DCF_A
value|61
end_define

begin_define
define|#
directive|define
name|SRST_DCF_P
value|62
end_define

begin_define
define|#
directive|define
name|SRST_SCR
value|64
end_define

begin_define
define|#
directive|define
name|SRST_SPI
value|65
end_define

begin_define
define|#
directive|define
name|SRST_TSADC
value|66
end_define

begin_define
define|#
directive|define
name|SRST_TSADC_P
value|67
end_define

begin_define
define|#
directive|define
name|SRST_CRYPTO
value|68
end_define

begin_define
define|#
directive|define
name|SRST_SGRF
value|69
end_define

begin_define
define|#
directive|define
name|SRST_GRF
value|70
end_define

begin_define
define|#
directive|define
name|SRST_USB_GRF
value|71
end_define

begin_define
define|#
directive|define
name|SRST_TIMER_6CH_P
value|72
end_define

begin_define
define|#
directive|define
name|SRST_TIMER0
value|73
end_define

begin_define
define|#
directive|define
name|SRST_TIMER1
value|74
end_define

begin_define
define|#
directive|define
name|SRST_TIMER2
value|75
end_define

begin_define
define|#
directive|define
name|SRST_TIMER3
value|76
end_define

begin_define
define|#
directive|define
name|SRST_TIMER4
value|77
end_define

begin_define
define|#
directive|define
name|SRST_TIMER5
value|78
end_define

begin_define
define|#
directive|define
name|SRST_USB3GRF
value|79
end_define

begin_define
define|#
directive|define
name|SRST_PHYNIU
value|80
end_define

begin_define
define|#
directive|define
name|SRST_HDMIPHY
value|81
end_define

begin_define
define|#
directive|define
name|SRST_VDAC
value|82
end_define

begin_define
define|#
directive|define
name|SRST_ACODEC_p
value|83
end_define

begin_define
define|#
directive|define
name|SRST_SARADC
value|85
end_define

begin_define
define|#
directive|define
name|SRST_SARADC_P
value|86
end_define

begin_define
define|#
directive|define
name|SRST_GRF_DDR
value|87
end_define

begin_define
define|#
directive|define
name|SRST_DFIMON
value|88
end_define

begin_define
define|#
directive|define
name|SRST_MSCH
value|89
end_define

begin_define
define|#
directive|define
name|SRST_DDRMSCH
value|91
end_define

begin_define
define|#
directive|define
name|SRST_DDRCTRL
value|92
end_define

begin_define
define|#
directive|define
name|SRST_DDRCTRL_P
value|93
end_define

begin_define
define|#
directive|define
name|SRST_DDRPHY
value|94
end_define

begin_define
define|#
directive|define
name|SRST_DDRPHY_P
value|95
end_define

begin_define
define|#
directive|define
name|SRST_GMAC_NIU_A
value|96
end_define

begin_define
define|#
directive|define
name|SRST_GMAC_NIU_P
value|97
end_define

begin_define
define|#
directive|define
name|SRST_GMAC2PHY_A
value|98
end_define

begin_define
define|#
directive|define
name|SRST_GMAC2IO_A
value|99
end_define

begin_define
define|#
directive|define
name|SRST_MACPHY
value|100
end_define

begin_define
define|#
directive|define
name|SRST_OTP_PHY
value|101
end_define

begin_define
define|#
directive|define
name|SRST_GPU_A
value|102
end_define

begin_define
define|#
directive|define
name|SRST_GPU_NIU_A
value|103
end_define

begin_define
define|#
directive|define
name|SRST_SDMMCEXT
value|104
end_define

begin_define
define|#
directive|define
name|SRST_PERIPH_NIU_A
value|105
end_define

begin_define
define|#
directive|define
name|SRST_PERIHP_NIU_H
value|106
end_define

begin_define
define|#
directive|define
name|SRST_PERIHP_P
value|107
end_define

begin_define
define|#
directive|define
name|SRST_PERIPHSYS_H
value|108
end_define

begin_define
define|#
directive|define
name|SRST_MMC0
value|109
end_define

begin_define
define|#
directive|define
name|SRST_SDIO
value|110
end_define

begin_define
define|#
directive|define
name|SRST_EMMC
value|111
end_define

begin_define
define|#
directive|define
name|SRST_USB2OTG_H
value|112
end_define

begin_define
define|#
directive|define
name|SRST_USB2OTG
value|113
end_define

begin_define
define|#
directive|define
name|SRST_USB2OTG_ADP
value|114
end_define

begin_define
define|#
directive|define
name|SRST_USB2HOST_H
value|115
end_define

begin_define
define|#
directive|define
name|SRST_USB2HOST_ARB
value|116
end_define

begin_define
define|#
directive|define
name|SRST_USB2HOST_AUX
value|117
end_define

begin_define
define|#
directive|define
name|SRST_USB2HOST_EHCIPHY
value|118
end_define

begin_define
define|#
directive|define
name|SRST_USB2HOST_UTMI
value|119
end_define

begin_define
define|#
directive|define
name|SRST_USB3OTG
value|120
end_define

begin_define
define|#
directive|define
name|SRST_USBPOR
value|121
end_define

begin_define
define|#
directive|define
name|SRST_USB2OTG_UTMI
value|122
end_define

begin_define
define|#
directive|define
name|SRST_USB2HOST_PHY_UTMI
value|123
end_define

begin_define
define|#
directive|define
name|SRST_USB3OTG_UTMI
value|124
end_define

begin_define
define|#
directive|define
name|SRST_USB3PHY_U2
value|125
end_define

begin_define
define|#
directive|define
name|SRST_USB3PHY_U3
value|126
end_define

begin_define
define|#
directive|define
name|SRST_USB3PHY_PIPE
value|127
end_define

begin_define
define|#
directive|define
name|SRST_VIO_A
value|128
end_define

begin_define
define|#
directive|define
name|SRST_VIO_BUS_H
value|129
end_define

begin_define
define|#
directive|define
name|SRST_VIO_H2P_H
value|130
end_define

begin_define
define|#
directive|define
name|SRST_VIO_ARBI_H
value|131
end_define

begin_define
define|#
directive|define
name|SRST_VOP_NIU_A
value|132
end_define

begin_define
define|#
directive|define
name|SRST_VOP_A
value|133
end_define

begin_define
define|#
directive|define
name|SRST_VOP_H
value|134
end_define

begin_define
define|#
directive|define
name|SRST_VOP_D
value|135
end_define

begin_define
define|#
directive|define
name|SRST_RGA
value|136
end_define

begin_define
define|#
directive|define
name|SRST_RGA_NIU_A
value|137
end_define

begin_define
define|#
directive|define
name|SRST_RGA_A
value|138
end_define

begin_define
define|#
directive|define
name|SRST_RGA_H
value|139
end_define

begin_define
define|#
directive|define
name|SRST_IEP_A
value|140
end_define

begin_define
define|#
directive|define
name|SRST_IEP_H
value|141
end_define

begin_define
define|#
directive|define
name|SRST_HDMI
value|142
end_define

begin_define
define|#
directive|define
name|SRST_HDMI_P
value|143
end_define

begin_define
define|#
directive|define
name|SRST_HDCP_A
value|144
end_define

begin_define
define|#
directive|define
name|SRST_HDCP
value|145
end_define

begin_define
define|#
directive|define
name|SRST_HDCP_H
value|146
end_define

begin_define
define|#
directive|define
name|SRST_CIF_A
value|147
end_define

begin_define
define|#
directive|define
name|SRST_CIF_H
value|148
end_define

begin_define
define|#
directive|define
name|SRST_CIF_P
value|149
end_define

begin_define
define|#
directive|define
name|SRST_OTP_P
value|150
end_define

begin_define
define|#
directive|define
name|SRST_OTP_SBPI
value|151
end_define

begin_define
define|#
directive|define
name|SRST_OTP_USER
value|152
end_define

begin_define
define|#
directive|define
name|SRST_DDRCTRL_A
value|153
end_define

begin_define
define|#
directive|define
name|SRST_DDRSTDY_P
value|154
end_define

begin_define
define|#
directive|define
name|SRST_DDRSTDY
value|155
end_define

begin_define
define|#
directive|define
name|SRST_PDM_H
value|156
end_define

begin_define
define|#
directive|define
name|SRST_PDM
value|157
end_define

begin_define
define|#
directive|define
name|SRST_USB3PHY_OTG_P
value|158
end_define

begin_define
define|#
directive|define
name|SRST_USB3PHY_PIPE_P
value|159
end_define

begin_define
define|#
directive|define
name|SRST_VCODEC_A
value|160
end_define

begin_define
define|#
directive|define
name|SRST_VCODEC_NIU_A
value|161
end_define

begin_define
define|#
directive|define
name|SRST_VCODEC_H
value|162
end_define

begin_define
define|#
directive|define
name|SRST_VCODEC_NIU_H
value|163
end_define

begin_define
define|#
directive|define
name|SRST_VDEC_A
value|164
end_define

begin_define
define|#
directive|define
name|SRST_VDEC_NIU_A
value|165
end_define

begin_define
define|#
directive|define
name|SRST_VDEC_H
value|166
end_define

begin_define
define|#
directive|define
name|SRST_VDEC_NIU_H
value|167
end_define

begin_define
define|#
directive|define
name|SRST_VDEC_CORE
value|168
end_define

begin_define
define|#
directive|define
name|SRST_VDEC_CABAC
value|169
end_define

begin_define
define|#
directive|define
name|SRST_DDRPHYDIV
value|175
end_define

begin_define
define|#
directive|define
name|SRST_RKVENC_NIU_A
value|176
end_define

begin_define
define|#
directive|define
name|SRST_RKVENC_NIU_H
value|177
end_define

begin_define
define|#
directive|define
name|SRST_RKVENC_H265_A
value|178
end_define

begin_define
define|#
directive|define
name|SRST_RKVENC_H265_P
value|179
end_define

begin_define
define|#
directive|define
name|SRST_RKVENC_H265_CORE
value|180
end_define

begin_define
define|#
directive|define
name|SRST_RKVENC_H265_DSP
value|181
end_define

begin_define
define|#
directive|define
name|SRST_RKVENC_H264_A
value|182
end_define

begin_define
define|#
directive|define
name|SRST_RKVENC_H264_H
value|183
end_define

begin_define
define|#
directive|define
name|SRST_RKVENC_INTMEM
value|184
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

