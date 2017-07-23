begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2015 Heiko Stuebner<heiko@sntech.de>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLK_ROCKCHIP_RK3368_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLK_ROCKCHIP_RK3368_H
end_define

begin_comment
comment|/* core clocks */
end_comment

begin_define
define|#
directive|define
name|PLL_APLLB
value|1
end_define

begin_define
define|#
directive|define
name|PLL_APLLL
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
name|ARMCLKB
value|7
end_define

begin_define
define|#
directive|define
name|ARMCLKL
value|8
end_define

begin_comment
comment|/* sclk gates (special clocks) */
end_comment

begin_define
define|#
directive|define
name|SCLK_GPU_CORE
value|64
end_define

begin_define
define|#
directive|define
name|SCLK_SPI0
value|65
end_define

begin_define
define|#
directive|define
name|SCLK_SPI1
value|66
end_define

begin_define
define|#
directive|define
name|SCLK_SPI2
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
name|SCLK_SDIO0
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
name|SCLK_SARADC
value|73
end_define

begin_define
define|#
directive|define
name|SCLK_NANDC0
value|75
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
name|SCLK_UART3
value|80
end_define

begin_define
define|#
directive|define
name|SCLK_UART4
value|81
end_define

begin_define
define|#
directive|define
name|SCLK_I2S_8CH
value|82
end_define

begin_define
define|#
directive|define
name|SCLK_SPDIF_8CH
value|83
end_define

begin_define
define|#
directive|define
name|SCLK_I2S_2CH
value|84
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER00
value|85
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER01
value|86
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER02
value|87
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER03
value|88
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER04
value|89
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER05
value|90
end_define

begin_define
define|#
directive|define
name|SCLK_OTGPHY0
value|93
end_define

begin_define
define|#
directive|define
name|SCLK_OTG_ADP
value|96
end_define

begin_define
define|#
directive|define
name|SCLK_HSICPHY480M
value|97
end_define

begin_define
define|#
directive|define
name|SCLK_HSICPHY12M
value|98
end_define

begin_define
define|#
directive|define
name|SCLK_MACREF
value|99
end_define

begin_define
define|#
directive|define
name|SCLK_VOP0_PWM
value|100
end_define

begin_define
define|#
directive|define
name|SCLK_MAC_RX
value|102
end_define

begin_define
define|#
directive|define
name|SCLK_MAC_TX
value|103
end_define

begin_define
define|#
directive|define
name|SCLK_EDP_24M
value|104
end_define

begin_define
define|#
directive|define
name|SCLK_EDP
value|105
end_define

begin_define
define|#
directive|define
name|SCLK_RGA
value|106
end_define

begin_define
define|#
directive|define
name|SCLK_ISP
value|107
end_define

begin_define
define|#
directive|define
name|SCLK_HDCP
value|108
end_define

begin_define
define|#
directive|define
name|SCLK_HDMI_HDCP
value|109
end_define

begin_define
define|#
directive|define
name|SCLK_HDMI_CEC
value|110
end_define

begin_define
define|#
directive|define
name|SCLK_HEVC_CABAC
value|111
end_define

begin_define
define|#
directive|define
name|SCLK_HEVC_CORE
value|112
end_define

begin_define
define|#
directive|define
name|SCLK_I2S_8CH_OUT
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
name|SCLK_SDIO0_DRV
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
name|SCLK_SDIO0_SAMPLE
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
name|SCLK_USBPHY480M
value|122
end_define

begin_define
define|#
directive|define
name|SCLK_PVTM_CORE
value|123
end_define

begin_define
define|#
directive|define
name|SCLK_PVTM_GPU
value|124
end_define

begin_define
define|#
directive|define
name|SCLK_PVTM_PMU
value|125
end_define

begin_define
define|#
directive|define
name|SCLK_SFC
value|126
end_define

begin_define
define|#
directive|define
name|SCLK_MAC
value|127
end_define

begin_define
define|#
directive|define
name|SCLK_MACREF_OUT
value|128
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER10
value|133
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER11
value|134
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER12
value|135
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER13
value|136
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER14
value|137
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER15
value|138
end_define

begin_define
define|#
directive|define
name|DCLK_VOP
value|190
end_define

begin_define
define|#
directive|define
name|MCLK_CRYPTO
value|191
end_define

begin_comment
comment|/* aclk gates */
end_comment

begin_define
define|#
directive|define
name|ACLK_GPU_MEM
value|192
end_define

begin_define
define|#
directive|define
name|ACLK_GPU_CFG
value|193
end_define

begin_define
define|#
directive|define
name|ACLK_DMAC_BUS
value|194
end_define

begin_define
define|#
directive|define
name|ACLK_DMAC_PERI
value|195
end_define

begin_define
define|#
directive|define
name|ACLK_PERI_MMU
value|196
end_define

begin_define
define|#
directive|define
name|ACLK_GMAC
value|197
end_define

begin_define
define|#
directive|define
name|ACLK_VOP
value|198
end_define

begin_define
define|#
directive|define
name|ACLK_VOP_IEP
value|199
end_define

begin_define
define|#
directive|define
name|ACLK_RGA
value|200
end_define

begin_define
define|#
directive|define
name|ACLK_HDCP
value|201
end_define

begin_define
define|#
directive|define
name|ACLK_IEP
value|202
end_define

begin_define
define|#
directive|define
name|ACLK_VIO0_NOC
value|203
end_define

begin_define
define|#
directive|define
name|ACLK_VIP
value|204
end_define

begin_define
define|#
directive|define
name|ACLK_ISP
value|205
end_define

begin_define
define|#
directive|define
name|ACLK_VIO1_NOC
value|206
end_define

begin_define
define|#
directive|define
name|ACLK_VIDEO
value|208
end_define

begin_define
define|#
directive|define
name|ACLK_BUS
value|209
end_define

begin_define
define|#
directive|define
name|ACLK_PERI
value|210
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
name|PCLK_PMUGRF
value|324
end_define

begin_define
define|#
directive|define
name|PCLK_MAILBOX
value|325
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
name|PCLK_SGRF
value|330
end_define

begin_define
define|#
directive|define
name|PCLK_PMU
value|331
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
name|PCLK_I2C4
value|336
end_define

begin_define
define|#
directive|define
name|PCLK_I2C5
value|337
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
name|PCLK_SPI1
value|339
end_define

begin_define
define|#
directive|define
name|PCLK_SPI2
value|340
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
name|PCLK_UART3
value|344
end_define

begin_define
define|#
directive|define
name|PCLK_UART4
value|345
end_define

begin_define
define|#
directive|define
name|PCLK_TSADC
value|346
end_define

begin_define
define|#
directive|define
name|PCLK_SARADC
value|347
end_define

begin_define
define|#
directive|define
name|PCLK_SIM
value|348
end_define

begin_define
define|#
directive|define
name|PCLK_GMAC
value|349
end_define

begin_define
define|#
directive|define
name|PCLK_PWM0
value|350
end_define

begin_define
define|#
directive|define
name|PCLK_PWM1
value|351
end_define

begin_define
define|#
directive|define
name|PCLK_TIMER0
value|353
end_define

begin_define
define|#
directive|define
name|PCLK_TIMER1
value|354
end_define

begin_define
define|#
directive|define
name|PCLK_EDP_CTRL
value|355
end_define

begin_define
define|#
directive|define
name|PCLK_MIPI_DSI0
value|356
end_define

begin_define
define|#
directive|define
name|PCLK_MIPI_CSI
value|358
end_define

begin_define
define|#
directive|define
name|PCLK_HDCP
value|359
end_define

begin_define
define|#
directive|define
name|PCLK_HDMI_CTRL
value|360
end_define

begin_define
define|#
directive|define
name|PCLK_VIO_H2P
value|361
end_define

begin_define
define|#
directive|define
name|PCLK_BUS
value|362
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
name|PCLK_DDRUPCTL
value|364
end_define

begin_define
define|#
directive|define
name|PCLK_DDRPHY
value|365
end_define

begin_define
define|#
directive|define
name|PCLK_ISP
value|366
end_define

begin_define
define|#
directive|define
name|PCLK_VIP
value|367
end_define

begin_define
define|#
directive|define
name|PCLK_WDT
value|368
end_define

begin_comment
comment|/* hclk gates */
end_comment

begin_define
define|#
directive|define
name|HCLK_SFC
value|448
end_define

begin_define
define|#
directive|define
name|HCLK_OTG0
value|449
end_define

begin_define
define|#
directive|define
name|HCLK_HOST0
value|450
end_define

begin_define
define|#
directive|define
name|HCLK_HOST1
value|451
end_define

begin_define
define|#
directive|define
name|HCLK_HSIC
value|452
end_define

begin_define
define|#
directive|define
name|HCLK_NANDC0
value|453
end_define

begin_define
define|#
directive|define
name|HCLK_TSP
value|455
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
name|HCLK_SDIO0
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
name|HCLK_HSADC
value|460
end_define

begin_define
define|#
directive|define
name|HCLK_CRYPTO
value|461
end_define

begin_define
define|#
directive|define
name|HCLK_I2S_2CH
value|462
end_define

begin_define
define|#
directive|define
name|HCLK_I2S_8CH
value|463
end_define

begin_define
define|#
directive|define
name|HCLK_SPDIF
value|464
end_define

begin_define
define|#
directive|define
name|HCLK_VOP
value|465
end_define

begin_define
define|#
directive|define
name|HCLK_ROM
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
name|HCLK_ISP
value|469
end_define

begin_define
define|#
directive|define
name|HCLK_RGA
value|470
end_define

begin_define
define|#
directive|define
name|HCLK_VIO_AHB_ARBI
value|471
end_define

begin_define
define|#
directive|define
name|HCLK_VIO_NOC
value|472
end_define

begin_define
define|#
directive|define
name|HCLK_VIP
value|473
end_define

begin_define
define|#
directive|define
name|HCLK_VIO_H2P
value|474
end_define

begin_define
define|#
directive|define
name|HCLK_VIO_HDCPMMU
value|475
end_define

begin_define
define|#
directive|define
name|HCLK_VIDEO
value|476
end_define

begin_define
define|#
directive|define
name|HCLK_BUS
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
name|SRST_CORE_B0
value|0
end_define

begin_define
define|#
directive|define
name|SRST_CORE_B1
value|1
end_define

begin_define
define|#
directive|define
name|SRST_CORE_B2
value|2
end_define

begin_define
define|#
directive|define
name|SRST_CORE_B3
value|3
end_define

begin_define
define|#
directive|define
name|SRST_CORE_B0_PO
value|4
end_define

begin_define
define|#
directive|define
name|SRST_CORE_B1_PO
value|5
end_define

begin_define
define|#
directive|define
name|SRST_CORE_B2_PO
value|6
end_define

begin_define
define|#
directive|define
name|SRST_CORE_B3_PO
value|7
end_define

begin_define
define|#
directive|define
name|SRST_L2_B
value|8
end_define

begin_define
define|#
directive|define
name|SRST_ADB_B
value|9
end_define

begin_define
define|#
directive|define
name|SRST_PD_CORE_B_NIU
value|10
end_define

begin_define
define|#
directive|define
name|SRST_PDBUS_STRSYS
value|11
end_define

begin_define
define|#
directive|define
name|SRST_SOCDBG_B
value|14
end_define

begin_define
define|#
directive|define
name|SRST_CORE_B_DBG
value|15
end_define

begin_define
define|#
directive|define
name|SRST_DMAC1
value|18
end_define

begin_define
define|#
directive|define
name|SRST_INTMEM
value|19
end_define

begin_define
define|#
directive|define
name|SRST_ROM
value|20
end_define

begin_define
define|#
directive|define
name|SRST_SPDIF8CH
value|21
end_define

begin_define
define|#
directive|define
name|SRST_I2S8CH
value|23
end_define

begin_define
define|#
directive|define
name|SRST_MAILBOX
value|24
end_define

begin_define
define|#
directive|define
name|SRST_I2S2CH
value|25
end_define

begin_define
define|#
directive|define
name|SRST_EFUSE_256
value|26
end_define

begin_define
define|#
directive|define
name|SRST_MCU_SYS
value|28
end_define

begin_define
define|#
directive|define
name|SRST_MCU_PO
value|29
end_define

begin_define
define|#
directive|define
name|SRST_MCU_NOC
value|30
end_define

begin_define
define|#
directive|define
name|SRST_EFUSE
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
name|SRST_GPIO4
value|36
end_define

begin_define
define|#
directive|define
name|SRST_PMUGRF
value|41
end_define

begin_define
define|#
directive|define
name|SRST_I2C0
value|42
end_define

begin_define
define|#
directive|define
name|SRST_I2C1
value|43
end_define

begin_define
define|#
directive|define
name|SRST_I2C2
value|44
end_define

begin_define
define|#
directive|define
name|SRST_I2C3
value|45
end_define

begin_define
define|#
directive|define
name|SRST_I2C4
value|46
end_define

begin_define
define|#
directive|define
name|SRST_I2C5
value|47
end_define

begin_define
define|#
directive|define
name|SRST_DWPWM
value|48
end_define

begin_define
define|#
directive|define
name|SRST_MMC_PERI
value|49
end_define

begin_define
define|#
directive|define
name|SRST_PERIPH_MMU
value|50
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
name|SRST_PMU
value|56
end_define

begin_define
define|#
directive|define
name|SRST_PERIPH_AXI
value|57
end_define

begin_define
define|#
directive|define
name|SRST_PERIPH_AHB
value|58
end_define

begin_define
define|#
directive|define
name|SRST_PERIPH_APB
value|59
end_define

begin_define
define|#
directive|define
name|SRST_PERIPH_NIU
value|60
end_define

begin_define
define|#
directive|define
name|SRST_PDPERI_AHB_ARBI
value|61
end_define

begin_define
define|#
directive|define
name|SRST_EMEM
value|62
end_define

begin_define
define|#
directive|define
name|SRST_USB_PERI
value|63
end_define

begin_define
define|#
directive|define
name|SRST_DMAC2
value|64
end_define

begin_define
define|#
directive|define
name|SRST_MAC
value|66
end_define

begin_define
define|#
directive|define
name|SRST_GPS
value|67
end_define

begin_define
define|#
directive|define
name|SRST_RKPWM
value|69
end_define

begin_define
define|#
directive|define
name|SRST_USBHOST0
value|72
end_define

begin_define
define|#
directive|define
name|SRST_HSIC
value|73
end_define

begin_define
define|#
directive|define
name|SRST_HSIC_AUX
value|74
end_define

begin_define
define|#
directive|define
name|SRST_HSIC_PHY
value|75
end_define

begin_define
define|#
directive|define
name|SRST_HSADC
value|76
end_define

begin_define
define|#
directive|define
name|SRST_NANDC0
value|77
end_define

begin_define
define|#
directive|define
name|SRST_SFC
value|79
end_define

begin_define
define|#
directive|define
name|SRST_SPI0
value|83
end_define

begin_define
define|#
directive|define
name|SRST_SPI1
value|84
end_define

begin_define
define|#
directive|define
name|SRST_SPI2
value|85
end_define

begin_define
define|#
directive|define
name|SRST_SARADC
value|87
end_define

begin_define
define|#
directive|define
name|SRST_PDALIVE_NIU
value|88
end_define

begin_define
define|#
directive|define
name|SRST_PDPMU_INTMEM
value|89
end_define

begin_define
define|#
directive|define
name|SRST_PDPMU_NIU
value|90
end_define

begin_define
define|#
directive|define
name|SRST_SGRF
value|91
end_define

begin_define
define|#
directive|define
name|SRST_VIO_ARBI
value|96
end_define

begin_define
define|#
directive|define
name|SRST_RGA_NIU
value|97
end_define

begin_define
define|#
directive|define
name|SRST_VIO0_NIU_AXI
value|98
end_define

begin_define
define|#
directive|define
name|SRST_VIO_NIU_AHB
value|99
end_define

begin_define
define|#
directive|define
name|SRST_LCDC0_AXI
value|100
end_define

begin_define
define|#
directive|define
name|SRST_LCDC0_AHB
value|101
end_define

begin_define
define|#
directive|define
name|SRST_LCDC0_DCLK
value|102
end_define

begin_define
define|#
directive|define
name|SRST_VIP
value|104
end_define

begin_define
define|#
directive|define
name|SRST_RGA_CORE
value|105
end_define

begin_define
define|#
directive|define
name|SRST_IEP_AXI
value|106
end_define

begin_define
define|#
directive|define
name|SRST_IEP_AHB
value|107
end_define

begin_define
define|#
directive|define
name|SRST_RGA_AXI
value|108
end_define

begin_define
define|#
directive|define
name|SRST_RGA_AHB
value|109
end_define

begin_define
define|#
directive|define
name|SRST_ISP
value|110
end_define

begin_define
define|#
directive|define
name|SRST_EDP_24M
value|111
end_define

begin_define
define|#
directive|define
name|SRST_VIDEO_AXI
value|112
end_define

begin_define
define|#
directive|define
name|SRST_VIDEO_AHB
value|113
end_define

begin_define
define|#
directive|define
name|SRST_MIPIDPHYTX
value|114
end_define

begin_define
define|#
directive|define
name|SRST_MIPIDSI0
value|115
end_define

begin_define
define|#
directive|define
name|SRST_MIPIDPHYRX
value|116
end_define

begin_define
define|#
directive|define
name|SRST_MIPICSI
value|117
end_define

begin_define
define|#
directive|define
name|SRST_GPU
value|120
end_define

begin_define
define|#
directive|define
name|SRST_HDMI
value|121
end_define

begin_define
define|#
directive|define
name|SRST_EDP
value|122
end_define

begin_define
define|#
directive|define
name|SRST_PMU_PVTM
value|123
end_define

begin_define
define|#
directive|define
name|SRST_CORE_PVTM
value|124
end_define

begin_define
define|#
directive|define
name|SRST_GPU_PVTM
value|125
end_define

begin_define
define|#
directive|define
name|SRST_GPU_SYS
value|126
end_define

begin_define
define|#
directive|define
name|SRST_GPU_MEM_NIU
value|127
end_define

begin_define
define|#
directive|define
name|SRST_MMC0
value|128
end_define

begin_define
define|#
directive|define
name|SRST_SDIO0
value|129
end_define

begin_define
define|#
directive|define
name|SRST_EMMC
value|131
end_define

begin_define
define|#
directive|define
name|SRST_USBOTG_AHB
value|132
end_define

begin_define
define|#
directive|define
name|SRST_USBOTG_PHY
value|133
end_define

begin_define
define|#
directive|define
name|SRST_USBOTG_CON
value|134
end_define

begin_define
define|#
directive|define
name|SRST_USBHOST0_AHB
value|135
end_define

begin_define
define|#
directive|define
name|SRST_USBHOST0_PHY
value|136
end_define

begin_define
define|#
directive|define
name|SRST_USBHOST0_CON
value|137
end_define

begin_define
define|#
directive|define
name|SRST_USBOTG_UTMI
value|138
end_define

begin_define
define|#
directive|define
name|SRST_USBHOST1_UTMI
value|139
end_define

begin_define
define|#
directive|define
name|SRST_USB_ADP
value|141
end_define

begin_define
define|#
directive|define
name|SRST_CORESIGHT
value|144
end_define

begin_define
define|#
directive|define
name|SRST_PD_CORE_AHB_NOC
value|145
end_define

begin_define
define|#
directive|define
name|SRST_PD_CORE_APB_NOC
value|146
end_define

begin_define
define|#
directive|define
name|SRST_GIC
value|148
end_define

begin_define
define|#
directive|define
name|SRST_LCDC_PWM0
value|149
end_define

begin_define
define|#
directive|define
name|SRST_RGA_H2P_BRG
value|153
end_define

begin_define
define|#
directive|define
name|SRST_VIDEO
value|154
end_define

begin_define
define|#
directive|define
name|SRST_GPU_CFG_NIU
value|157
end_define

begin_define
define|#
directive|define
name|SRST_TSADC
value|159
end_define

begin_define
define|#
directive|define
name|SRST_DDRPHY0
value|160
end_define

begin_define
define|#
directive|define
name|SRST_DDRPHY0_APB
value|161
end_define

begin_define
define|#
directive|define
name|SRST_DDRCTRL0
value|162
end_define

begin_define
define|#
directive|define
name|SRST_DDRCTRL0_APB
value|163
end_define

begin_define
define|#
directive|define
name|SRST_VIDEO_NIU
value|165
end_define

begin_define
define|#
directive|define
name|SRST_VIDEO_NIU_AHB
value|167
end_define

begin_define
define|#
directive|define
name|SRST_DDRMSCH0
value|170
end_define

begin_define
define|#
directive|define
name|SRST_PDBUS_AHB
value|173
end_define

begin_define
define|#
directive|define
name|SRST_CRYPTO
value|174
end_define

begin_define
define|#
directive|define
name|SRST_UART0
value|179
end_define

begin_define
define|#
directive|define
name|SRST_UART1
value|180
end_define

begin_define
define|#
directive|define
name|SRST_UART2
value|181
end_define

begin_define
define|#
directive|define
name|SRST_UART3
value|182
end_define

begin_define
define|#
directive|define
name|SRST_UART4
value|183
end_define

begin_define
define|#
directive|define
name|SRST_SIMC
value|186
end_define

begin_define
define|#
directive|define
name|SRST_TSP
value|188
end_define

begin_define
define|#
directive|define
name|SRST_TSP_CLKIN0
value|189
end_define

begin_define
define|#
directive|define
name|SRST_CORE_L0
value|192
end_define

begin_define
define|#
directive|define
name|SRST_CORE_L1
value|193
end_define

begin_define
define|#
directive|define
name|SRST_CORE_L2
value|194
end_define

begin_define
define|#
directive|define
name|SRST_CORE_L3
value|195
end_define

begin_define
define|#
directive|define
name|SRST_CORE_L0_PO
value|195
end_define

begin_define
define|#
directive|define
name|SRST_CORE_L1_PO
value|197
end_define

begin_define
define|#
directive|define
name|SRST_CORE_L2_PO
value|198
end_define

begin_define
define|#
directive|define
name|SRST_CORE_L3_PO
value|199
end_define

begin_define
define|#
directive|define
name|SRST_L2_L
value|200
end_define

begin_define
define|#
directive|define
name|SRST_ADB_L
value|201
end_define

begin_define
define|#
directive|define
name|SRST_PD_CORE_L_NIU
value|202
end_define

begin_define
define|#
directive|define
name|SRST_CCI_SYS
value|203
end_define

begin_define
define|#
directive|define
name|SRST_CCI_DDR
value|204
end_define

begin_define
define|#
directive|define
name|SRST_CCI
value|205
end_define

begin_define
define|#
directive|define
name|SRST_SOCDBG_L
value|206
end_define

begin_define
define|#
directive|define
name|SRST_CORE_L_DBG
value|207
end_define

begin_define
define|#
directive|define
name|SRST_CORE_B0_NC
value|208
end_define

begin_define
define|#
directive|define
name|SRST_CORE_B0_PO_NC
value|209
end_define

begin_define
define|#
directive|define
name|SRST_L2_B_NC
value|210
end_define

begin_define
define|#
directive|define
name|SRST_ADB_B_NC
value|211
end_define

begin_define
define|#
directive|define
name|SRST_PD_CORE_B_NIU_NC
value|212
end_define

begin_define
define|#
directive|define
name|SRST_PDBUS_STRSYS_NC
value|213
end_define

begin_define
define|#
directive|define
name|SRST_CORE_L0_NC
value|214
end_define

begin_define
define|#
directive|define
name|SRST_CORE_L0_PO_NC
value|215
end_define

begin_define
define|#
directive|define
name|SRST_L2_L_NC
value|216
end_define

begin_define
define|#
directive|define
name|SRST_ADB_L_NC
value|217
end_define

begin_define
define|#
directive|define
name|SRST_PD_CORE_L_NIU_NC
value|218
end_define

begin_define
define|#
directive|define
name|SRST_CCI_SYS_NC
value|219
end_define

begin_define
define|#
directive|define
name|SRST_CCI_DDR_NC
value|220
end_define

begin_define
define|#
directive|define
name|SRST_CCI_NC
value|221
end_define

begin_define
define|#
directive|define
name|SRST_TRACE_NC
value|222
end_define

begin_define
define|#
directive|define
name|SRST_TIMER00
value|224
end_define

begin_define
define|#
directive|define
name|SRST_TIMER01
value|225
end_define

begin_define
define|#
directive|define
name|SRST_TIMER02
value|226
end_define

begin_define
define|#
directive|define
name|SRST_TIMER03
value|227
end_define

begin_define
define|#
directive|define
name|SRST_TIMER04
value|228
end_define

begin_define
define|#
directive|define
name|SRST_TIMER05
value|229
end_define

begin_define
define|#
directive|define
name|SRST_TIMER10
value|230
end_define

begin_define
define|#
directive|define
name|SRST_TIMER11
value|231
end_define

begin_define
define|#
directive|define
name|SRST_TIMER12
value|232
end_define

begin_define
define|#
directive|define
name|SRST_TIMER13
value|233
end_define

begin_define
define|#
directive|define
name|SRST_TIMER14
value|234
end_define

begin_define
define|#
directive|define
name|SRST_TIMER15
value|235
end_define

begin_define
define|#
directive|define
name|SRST_TIMER0_APB
value|236
end_define

begin_define
define|#
directive|define
name|SRST_TIMER1_APB
value|237
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

