begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2015 Rockchip Electronics Co. Ltd.  * Author: Jeffy Chen<jeffy.chen@rock-chips.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLK_ROCKCHIP_RK3228_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLK_ROCKCHIP_RK3228_H
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
name|ARMCLK
value|5
end_define

begin_comment
comment|/* sclk gates (special clocks) */
end_comment

begin_define
define|#
directive|define
name|SCLK_SPI0
value|65
end_define

begin_define
define|#
directive|define
name|SCLK_NANDC
value|67
end_define

begin_define
define|#
directive|define
name|SCLK_SDMMC
value|68
end_define

begin_define
define|#
directive|define
name|SCLK_SDIO
value|69
end_define

begin_define
define|#
directive|define
name|SCLK_EMMC
value|71
end_define

begin_define
define|#
directive|define
name|SCLK_TSADC
value|72
end_define

begin_define
define|#
directive|define
name|SCLK_UART0
value|77
end_define

begin_define
define|#
directive|define
name|SCLK_UART1
value|78
end_define

begin_define
define|#
directive|define
name|SCLK_UART2
value|79
end_define

begin_define
define|#
directive|define
name|SCLK_I2S0
value|80
end_define

begin_define
define|#
directive|define
name|SCLK_I2S1
value|81
end_define

begin_define
define|#
directive|define
name|SCLK_I2S2
value|82
end_define

begin_define
define|#
directive|define
name|SCLK_SPDIF
value|83
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER0
value|85
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER1
value|86
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER2
value|87
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER3
value|88
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER4
value|89
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER5
value|90
end_define

begin_define
define|#
directive|define
name|SCLK_I2S_OUT
value|113
end_define

begin_define
define|#
directive|define
name|SCLK_SDMMC_DRV
value|114
end_define

begin_define
define|#
directive|define
name|SCLK_SDIO_DRV
value|115
end_define

begin_define
define|#
directive|define
name|SCLK_EMMC_DRV
value|117
end_define

begin_define
define|#
directive|define
name|SCLK_SDMMC_SAMPLE
value|118
end_define

begin_define
define|#
directive|define
name|SCLK_SDIO_SAMPLE
value|119
end_define

begin_define
define|#
directive|define
name|SCLK_EMMC_SAMPLE
value|121
end_define

begin_define
define|#
directive|define
name|SCLK_VOP
value|122
end_define

begin_define
define|#
directive|define
name|SCLK_HDMI_HDCP
value|123
end_define

begin_define
define|#
directive|define
name|SCLK_MAC_SRC
value|124
end_define

begin_define
define|#
directive|define
name|SCLK_MAC_EXTCLK
value|125
end_define

begin_define
define|#
directive|define
name|SCLK_MAC
value|126
end_define

begin_define
define|#
directive|define
name|SCLK_MAC_REFOUT
value|127
end_define

begin_define
define|#
directive|define
name|SCLK_MAC_REF
value|128
end_define

begin_define
define|#
directive|define
name|SCLK_MAC_RX
value|129
end_define

begin_define
define|#
directive|define
name|SCLK_MAC_TX
value|130
end_define

begin_define
define|#
directive|define
name|SCLK_MAC_PHY
value|131
end_define

begin_define
define|#
directive|define
name|SCLK_MAC_OUT
value|132
end_define

begin_define
define|#
directive|define
name|SCLK_VDEC_CABAC
value|133
end_define

begin_define
define|#
directive|define
name|SCLK_VDEC_CORE
value|134
end_define

begin_define
define|#
directive|define
name|SCLK_RGA
value|135
end_define

begin_define
define|#
directive|define
name|SCLK_HDCP
value|136
end_define

begin_define
define|#
directive|define
name|SCLK_HDMI_CEC
value|137
end_define

begin_define
define|#
directive|define
name|SCLK_CRYPTO
value|138
end_define

begin_define
define|#
directive|define
name|SCLK_TSP
value|139
end_define

begin_define
define|#
directive|define
name|SCLK_HSADC
value|140
end_define

begin_define
define|#
directive|define
name|SCLK_WIFI
value|141
end_define

begin_define
define|#
directive|define
name|SCLK_OTGPHY0
value|142
end_define

begin_define
define|#
directive|define
name|SCLK_OTGPHY1
value|143
end_define

begin_comment
comment|/* dclk gates */
end_comment

begin_define
define|#
directive|define
name|DCLK_VOP
value|190
end_define

begin_define
define|#
directive|define
name|DCLK_HDMI_PHY
value|191
end_define

begin_comment
comment|/* aclk gates */
end_comment

begin_define
define|#
directive|define
name|ACLK_DMAC
value|194
end_define

begin_define
define|#
directive|define
name|ACLK_CPU
value|195
end_define

begin_define
define|#
directive|define
name|ACLK_VPU_PRE
value|196
end_define

begin_define
define|#
directive|define
name|ACLK_RKVDEC_PRE
value|197
end_define

begin_define
define|#
directive|define
name|ACLK_RGA_PRE
value|198
end_define

begin_define
define|#
directive|define
name|ACLK_IEP_PRE
value|199
end_define

begin_define
define|#
directive|define
name|ACLK_HDCP_PRE
value|200
end_define

begin_define
define|#
directive|define
name|ACLK_VOP_PRE
value|201
end_define

begin_define
define|#
directive|define
name|ACLK_VPU
value|202
end_define

begin_define
define|#
directive|define
name|ACLK_RKVDEC
value|203
end_define

begin_define
define|#
directive|define
name|ACLK_IEP
value|204
end_define

begin_define
define|#
directive|define
name|ACLK_RGA
value|205
end_define

begin_define
define|#
directive|define
name|ACLK_HDCP
value|206
end_define

begin_define
define|#
directive|define
name|ACLK_PERI
value|210
end_define

begin_define
define|#
directive|define
name|ACLK_VOP
value|211
end_define

begin_define
define|#
directive|define
name|ACLK_GMAC
value|212
end_define

begin_define
define|#
directive|define
name|ACLK_GPU
value|213
end_define

begin_comment
comment|/* pclk gates */
end_comment

begin_define
define|#
directive|define
name|PCLK_GPIO0
value|320
end_define

begin_define
define|#
directive|define
name|PCLK_GPIO1
value|321
end_define

begin_define
define|#
directive|define
name|PCLK_GPIO2
value|322
end_define

begin_define
define|#
directive|define
name|PCLK_GPIO3
value|323
end_define

begin_define
define|#
directive|define
name|PCLK_VIO_H2P
value|324
end_define

begin_define
define|#
directive|define
name|PCLK_HDCP
value|325
end_define

begin_define
define|#
directive|define
name|PCLK_EFUSE_1024
value|326
end_define

begin_define
define|#
directive|define
name|PCLK_EFUSE_256
value|327
end_define

begin_define
define|#
directive|define
name|PCLK_GRF
value|329
end_define

begin_define
define|#
directive|define
name|PCLK_I2C0
value|332
end_define

begin_define
define|#
directive|define
name|PCLK_I2C1
value|333
end_define

begin_define
define|#
directive|define
name|PCLK_I2C2
value|334
end_define

begin_define
define|#
directive|define
name|PCLK_I2C3
value|335
end_define

begin_define
define|#
directive|define
name|PCLK_SPI0
value|338
end_define

begin_define
define|#
directive|define
name|PCLK_UART0
value|341
end_define

begin_define
define|#
directive|define
name|PCLK_UART1
value|342
end_define

begin_define
define|#
directive|define
name|PCLK_UART2
value|343
end_define

begin_define
define|#
directive|define
name|PCLK_TSADC
value|344
end_define

begin_define
define|#
directive|define
name|PCLK_PWM
value|350
end_define

begin_define
define|#
directive|define
name|PCLK_TIMER
value|353
end_define

begin_define
define|#
directive|define
name|PCLK_CPU
value|354
end_define

begin_define
define|#
directive|define
name|PCLK_PERI
value|363
end_define

begin_define
define|#
directive|define
name|PCLK_HDMI_CTRL
value|364
end_define

begin_define
define|#
directive|define
name|PCLK_HDMI_PHY
value|365
end_define

begin_define
define|#
directive|define
name|PCLK_GMAC
value|367
end_define

begin_comment
comment|/* hclk gates */
end_comment

begin_define
define|#
directive|define
name|HCLK_I2S0_8CH
value|442
end_define

begin_define
define|#
directive|define
name|HCLK_I2S1_8CH
value|443
end_define

begin_define
define|#
directive|define
name|HCLK_I2S2_2CH
value|444
end_define

begin_define
define|#
directive|define
name|HCLK_SPDIF_8CH
value|445
end_define

begin_define
define|#
directive|define
name|HCLK_VOP
value|452
end_define

begin_define
define|#
directive|define
name|HCLK_NANDC
value|453
end_define

begin_define
define|#
directive|define
name|HCLK_SDMMC
value|456
end_define

begin_define
define|#
directive|define
name|HCLK_SDIO
value|457
end_define

begin_define
define|#
directive|define
name|HCLK_EMMC
value|459
end_define

begin_define
define|#
directive|define
name|HCLK_CPU
value|460
end_define

begin_define
define|#
directive|define
name|HCLK_VPU_PRE
value|461
end_define

begin_define
define|#
directive|define
name|HCLK_RKVDEC_PRE
value|462
end_define

begin_define
define|#
directive|define
name|HCLK_VIO_PRE
value|463
end_define

begin_define
define|#
directive|define
name|HCLK_VPU
value|464
end_define

begin_define
define|#
directive|define
name|HCLK_RKVDEC
value|465
end_define

begin_define
define|#
directive|define
name|HCLK_VIO
value|466
end_define

begin_define
define|#
directive|define
name|HCLK_RGA
value|467
end_define

begin_define
define|#
directive|define
name|HCLK_IEP
value|468
end_define

begin_define
define|#
directive|define
name|HCLK_VIO_H2P
value|469
end_define

begin_define
define|#
directive|define
name|HCLK_HDCP_MMU
value|470
end_define

begin_define
define|#
directive|define
name|HCLK_HOST0
value|471
end_define

begin_define
define|#
directive|define
name|HCLK_HOST1
value|472
end_define

begin_define
define|#
directive|define
name|HCLK_HOST2
value|473
end_define

begin_define
define|#
directive|define
name|HCLK_OTG
value|474
end_define

begin_define
define|#
directive|define
name|HCLK_TSP
value|475
end_define

begin_define
define|#
directive|define
name|HCLK_M_CRYPTO
value|476
end_define

begin_define
define|#
directive|define
name|HCLK_S_CRYPTO
value|477
end_define

begin_define
define|#
directive|define
name|HCLK_PERI
value|478
end_define

begin_define
define|#
directive|define
name|CLK_NR_CLKS
value|(HCLK_PERI + 1)
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
name|SRST_ACLK_CORE
value|13
end_define

begin_define
define|#
directive|define
name|SRST_NOC
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
name|SRST_CPUSYS_H
value|18
end_define

begin_define
define|#
directive|define
name|SRST_BUSSYS_H
value|19
end_define

begin_define
define|#
directive|define
name|SRST_SPDIF
value|20
end_define

begin_define
define|#
directive|define
name|SRST_INTMEM
value|21
end_define

begin_define
define|#
directive|define
name|SRST_ROM
value|22
end_define

begin_define
define|#
directive|define
name|SRST_OTG_ADP
value|23
end_define

begin_define
define|#
directive|define
name|SRST_I2S0
value|24
end_define

begin_define
define|#
directive|define
name|SRST_I2S1
value|25
end_define

begin_define
define|#
directive|define
name|SRST_I2S2
value|26
end_define

begin_define
define|#
directive|define
name|SRST_ACODEC_P
value|27
end_define

begin_define
define|#
directive|define
name|SRST_DFIMON
value|28
end_define

begin_define
define|#
directive|define
name|SRST_MSCH
value|29
end_define

begin_define
define|#
directive|define
name|SRST_EFUSE1024
value|30
end_define

begin_define
define|#
directive|define
name|SRST_EFUSE256
value|31
end_define

begin_define
define|#
directive|define
name|SRST_GPIO0
value|32
end_define

begin_define
define|#
directive|define
name|SRST_GPIO1
value|33
end_define

begin_define
define|#
directive|define
name|SRST_GPIO2
value|34
end_define

begin_define
define|#
directive|define
name|SRST_GPIO3
value|35
end_define

begin_define
define|#
directive|define
name|SRST_PERIPH_NOC_A
value|36
end_define

begin_define
define|#
directive|define
name|SRST_PERIPH_NOC_BUS_H
value|37
end_define

begin_define
define|#
directive|define
name|SRST_PERIPH_NOC_P
value|38
end_define

begin_define
define|#
directive|define
name|SRST_UART0
value|39
end_define

begin_define
define|#
directive|define
name|SRST_UART1
value|40
end_define

begin_define
define|#
directive|define
name|SRST_UART2
value|41
end_define

begin_define
define|#
directive|define
name|SRST_PHYNOC
value|42
end_define

begin_define
define|#
directive|define
name|SRST_I2C0
value|43
end_define

begin_define
define|#
directive|define
name|SRST_I2C1
value|44
end_define

begin_define
define|#
directive|define
name|SRST_I2C2
value|45
end_define

begin_define
define|#
directive|define
name|SRST_I2C3
value|46
end_define

begin_define
define|#
directive|define
name|SRST_PWM
value|48
end_define

begin_define
define|#
directive|define
name|SRST_A53_GIC
value|49
end_define

begin_define
define|#
directive|define
name|SRST_DAP
value|51
end_define

begin_define
define|#
directive|define
name|SRST_DAP_NOC
value|52
end_define

begin_define
define|#
directive|define
name|SRST_CRYPTO
value|53
end_define

begin_define
define|#
directive|define
name|SRST_SGRF
value|54
end_define

begin_define
define|#
directive|define
name|SRST_GRF
value|55
end_define

begin_define
define|#
directive|define
name|SRST_GMAC
value|56
end_define

begin_define
define|#
directive|define
name|SRST_PERIPH_NOC_H
value|58
end_define

begin_define
define|#
directive|define
name|SRST_MACPHY
value|63
end_define

begin_define
define|#
directive|define
name|SRST_DMA
value|64
end_define

begin_define
define|#
directive|define
name|SRST_NANDC
value|68
end_define

begin_define
define|#
directive|define
name|SRST_USBOTG
value|69
end_define

begin_define
define|#
directive|define
name|SRST_OTGC
value|70
end_define

begin_define
define|#
directive|define
name|SRST_USBHOST0
value|71
end_define

begin_define
define|#
directive|define
name|SRST_HOST_CTRL0
value|72
end_define

begin_define
define|#
directive|define
name|SRST_USBHOST1
value|73
end_define

begin_define
define|#
directive|define
name|SRST_HOST_CTRL1
value|74
end_define

begin_define
define|#
directive|define
name|SRST_USBHOST2
value|75
end_define

begin_define
define|#
directive|define
name|SRST_HOST_CTRL2
value|76
end_define

begin_define
define|#
directive|define
name|SRST_USBPOR0
value|77
end_define

begin_define
define|#
directive|define
name|SRST_USBPOR1
value|78
end_define

begin_define
define|#
directive|define
name|SRST_DDRMSCH
value|79
end_define

begin_define
define|#
directive|define
name|SRST_SMART_CARD
value|80
end_define

begin_define
define|#
directive|define
name|SRST_SDMMC
value|81
end_define

begin_define
define|#
directive|define
name|SRST_SDIO
value|82
end_define

begin_define
define|#
directive|define
name|SRST_EMMC
value|83
end_define

begin_define
define|#
directive|define
name|SRST_SPI
value|84
end_define

begin_define
define|#
directive|define
name|SRST_TSP_H
value|85
end_define

begin_define
define|#
directive|define
name|SRST_TSP
value|86
end_define

begin_define
define|#
directive|define
name|SRST_TSADC
value|87
end_define

begin_define
define|#
directive|define
name|SRST_DDRPHY
value|88
end_define

begin_define
define|#
directive|define
name|SRST_DDRPHY_P
value|89
end_define

begin_define
define|#
directive|define
name|SRST_DDRCTRL
value|90
end_define

begin_define
define|#
directive|define
name|SRST_DDRCTRL_P
value|91
end_define

begin_define
define|#
directive|define
name|SRST_HOST0_ECHI
value|92
end_define

begin_define
define|#
directive|define
name|SRST_HOST1_ECHI
value|93
end_define

begin_define
define|#
directive|define
name|SRST_HOST2_ECHI
value|94
end_define

begin_define
define|#
directive|define
name|SRST_VOP_NOC_A
value|95
end_define

begin_define
define|#
directive|define
name|SRST_HDMI_P
value|96
end_define

begin_define
define|#
directive|define
name|SRST_VIO_ARBI_H
value|97
end_define

begin_define
define|#
directive|define
name|SRST_IEP_NOC_A
value|98
end_define

begin_define
define|#
directive|define
name|SRST_VIO_NOC_H
value|99
end_define

begin_define
define|#
directive|define
name|SRST_VOP_A
value|100
end_define

begin_define
define|#
directive|define
name|SRST_VOP_H
value|101
end_define

begin_define
define|#
directive|define
name|SRST_VOP_D
value|102
end_define

begin_define
define|#
directive|define
name|SRST_UTMI0
value|103
end_define

begin_define
define|#
directive|define
name|SRST_UTMI1
value|104
end_define

begin_define
define|#
directive|define
name|SRST_UTMI2
value|105
end_define

begin_define
define|#
directive|define
name|SRST_UTMI3
value|106
end_define

begin_define
define|#
directive|define
name|SRST_RGA
value|107
end_define

begin_define
define|#
directive|define
name|SRST_RGA_NOC_A
value|108
end_define

begin_define
define|#
directive|define
name|SRST_RGA_A
value|109
end_define

begin_define
define|#
directive|define
name|SRST_RGA_H
value|110
end_define

begin_define
define|#
directive|define
name|SRST_HDCP_A
value|111
end_define

begin_define
define|#
directive|define
name|SRST_VPU_A
value|112
end_define

begin_define
define|#
directive|define
name|SRST_VPU_H
value|113
end_define

begin_define
define|#
directive|define
name|SRST_VPU_NOC_A
value|116
end_define

begin_define
define|#
directive|define
name|SRST_VPU_NOC_H
value|117
end_define

begin_define
define|#
directive|define
name|SRST_RKVDEC_A
value|118
end_define

begin_define
define|#
directive|define
name|SRST_RKVDEC_NOC_A
value|119
end_define

begin_define
define|#
directive|define
name|SRST_RKVDEC_H
value|120
end_define

begin_define
define|#
directive|define
name|SRST_RKVDEC_NOC_H
value|121
end_define

begin_define
define|#
directive|define
name|SRST_RKVDEC_CORE
value|122
end_define

begin_define
define|#
directive|define
name|SRST_RKVDEC_CABAC
value|123
end_define

begin_define
define|#
directive|define
name|SRST_IEP_A
value|124
end_define

begin_define
define|#
directive|define
name|SRST_IEP_H
value|125
end_define

begin_define
define|#
directive|define
name|SRST_GPU_A
value|126
end_define

begin_define
define|#
directive|define
name|SRST_GPU_NOC_A
value|127
end_define

begin_define
define|#
directive|define
name|SRST_CORE_DBG
value|128
end_define

begin_define
define|#
directive|define
name|SRST_DBG_P
value|129
end_define

begin_define
define|#
directive|define
name|SRST_TIMER0
value|130
end_define

begin_define
define|#
directive|define
name|SRST_TIMER1
value|131
end_define

begin_define
define|#
directive|define
name|SRST_TIMER2
value|132
end_define

begin_define
define|#
directive|define
name|SRST_TIMER3
value|133
end_define

begin_define
define|#
directive|define
name|SRST_TIMER4
value|134
end_define

begin_define
define|#
directive|define
name|SRST_TIMER5
value|135
end_define

begin_define
define|#
directive|define
name|SRST_VIO_H2P
value|136
end_define

begin_define
define|#
directive|define
name|SRST_HDMIPHY
value|139
end_define

begin_define
define|#
directive|define
name|SRST_VDAC
value|140
end_define

begin_define
define|#
directive|define
name|SRST_TIMER_6CH_P
value|141
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

