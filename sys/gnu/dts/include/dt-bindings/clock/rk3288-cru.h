begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2014 MundoReader S.L.  * Author: Heiko Stuebner<heiko@sntech.de>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLK_ROCKCHIP_RK3288_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLK_ROCKCHIP_RK3288_H
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
name|SCLK_GPU
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
name|SCLK_SDIO1
value|70
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
name|SCLK_PS2C
value|74
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
name|SCLK_NANDC1
value|76
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
name|SCLK_I2S0
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
name|SCLK_SPDIF8CH
value|84
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
name|SCLK_TIMER6
value|91
end_define

begin_define
define|#
directive|define
name|SCLK_HSADC
value|92
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
name|SCLK_OTGPHY1
value|94
end_define

begin_define
define|#
directive|define
name|SCLK_OTGPHY2
value|95
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
name|SCLK_LCDC_PWM0
value|100
end_define

begin_define
define|#
directive|define
name|SCLK_LCDC_PWM1
value|101
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
name|SCLK_ISP_JPE
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
name|SCLK_I2S0_OUT
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
name|SCLK_SDIO1_DRV
value|116
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
name|SCLK_SDIO1_SAMPLE
value|120
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
name|SCLK_USBPHY480M_SRC
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
name|SCLK_CRYPTO
value|125
end_define

begin_define
define|#
directive|define
name|SCLK_MIPIDSI_24M
value|126
end_define

begin_define
define|#
directive|define
name|SCLK_VIP_OUT
value|127
end_define

begin_define
define|#
directive|define
name|SCLK_MAC
value|151
end_define

begin_define
define|#
directive|define
name|SCLK_MACREF_OUT
value|152
end_define

begin_define
define|#
directive|define
name|DCLK_VOP0
value|190
end_define

begin_define
define|#
directive|define
name|DCLK_VOP1
value|191
end_define

begin_comment
comment|/* aclk gates */
end_comment

begin_define
define|#
directive|define
name|ACLK_GPU
value|192
end_define

begin_define
define|#
directive|define
name|ACLK_DMAC1
value|193
end_define

begin_define
define|#
directive|define
name|ACLK_DMAC2
value|194
end_define

begin_define
define|#
directive|define
name|ACLK_MMU
value|195
end_define

begin_define
define|#
directive|define
name|ACLK_GMAC
value|196
end_define

begin_define
define|#
directive|define
name|ACLK_VOP0
value|197
end_define

begin_define
define|#
directive|define
name|ACLK_VOP1
value|198
end_define

begin_define
define|#
directive|define
name|ACLK_CRYPTO
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
name|ACLK_RGA_NIU
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
name|ACLK_VIO0_NIU
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
name|ACLK_VIO1_NIU
value|206
end_define

begin_define
define|#
directive|define
name|ACLK_HEVC
value|207
end_define

begin_define
define|#
directive|define
name|ACLK_VCODEC
value|208
end_define

begin_define
define|#
directive|define
name|ACLK_CPU
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
name|PCLK_GPIO4
value|324
end_define

begin_define
define|#
directive|define
name|PCLK_GPIO5
value|325
end_define

begin_define
define|#
directive|define
name|PCLK_GPIO6
value|326
end_define

begin_define
define|#
directive|define
name|PCLK_GPIO7
value|327
end_define

begin_define
define|#
directive|define
name|PCLK_GPIO8
value|328
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
name|PCLK_PWM
value|350
end_define

begin_define
define|#
directive|define
name|PCLK_RKPWM
value|351
end_define

begin_define
define|#
directive|define
name|PCLK_PS2C
value|352
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
name|PCLK_TZPC
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
name|PCLK_MIPI_DSI1
value|357
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
name|PCLK_LVDS_PHY
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
name|PCLK_VIO2_H2P
value|361
end_define

begin_define
define|#
directive|define
name|PCLK_CPU
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
name|PCLK_DDRUPCTL0
value|364
end_define

begin_define
define|#
directive|define
name|PCLK_PUBL0
value|365
end_define

begin_define
define|#
directive|define
name|PCLK_DDRUPCTL1
value|366
end_define

begin_define
define|#
directive|define
name|PCLK_PUBL1
value|367
end_define

begin_define
define|#
directive|define
name|PCLK_WDT
value|368
end_define

begin_define
define|#
directive|define
name|PCLK_EFUSE256
value|369
end_define

begin_define
define|#
directive|define
name|PCLK_EFUSE1024
value|370
end_define

begin_define
define|#
directive|define
name|PCLK_ISP_IN
value|371
end_define

begin_comment
comment|/* hclk gates */
end_comment

begin_define
define|#
directive|define
name|HCLK_GPS
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
name|HCLK_USBHOST0
value|450
end_define

begin_define
define|#
directive|define
name|HCLK_USBHOST1
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
name|HCLK_NANDC1
value|454
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
name|HCLK_SDIO1
value|458
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
name|HCLK_I2S0
value|462
end_define

begin_define
define|#
directive|define
name|HCLK_SPDIF
value|463
end_define

begin_define
define|#
directive|define
name|HCLK_SPDIF8CH
value|464
end_define

begin_define
define|#
directive|define
name|HCLK_VOP0
value|465
end_define

begin_define
define|#
directive|define
name|HCLK_VOP1
value|466
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
name|HCLK_VIO_NIU
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
name|HCLK_VIO2_H2P
value|474
end_define

begin_define
define|#
directive|define
name|HCLK_HEVC
value|475
end_define

begin_define
define|#
directive|define
name|HCLK_VCODEC
value|476
end_define

begin_define
define|#
directive|define
name|HCLK_CPU
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
name|SRST_CORE0
value|0
end_define

begin_define
define|#
directive|define
name|SRST_CORE1
value|1
end_define

begin_define
define|#
directive|define
name|SRST_CORE2
value|2
end_define

begin_define
define|#
directive|define
name|SRST_CORE3
value|3
end_define

begin_define
define|#
directive|define
name|SRST_CORE0_PO
value|4
end_define

begin_define
define|#
directive|define
name|SRST_CORE1_PO
value|5
end_define

begin_define
define|#
directive|define
name|SRST_CORE2_PO
value|6
end_define

begin_define
define|#
directive|define
name|SRST_CORE3_PO
value|7
end_define

begin_define
define|#
directive|define
name|SRST_PDCORE_STRSYS
value|8
end_define

begin_define
define|#
directive|define
name|SRST_PDBUS_STRSYS
value|9
end_define

begin_define
define|#
directive|define
name|SRST_L2C
value|10
end_define

begin_define
define|#
directive|define
name|SRST_TOPDBG
value|11
end_define

begin_define
define|#
directive|define
name|SRST_CORE0_DBG
value|12
end_define

begin_define
define|#
directive|define
name|SRST_CORE1_DBG
value|13
end_define

begin_define
define|#
directive|define
name|SRST_CORE2_DBG
value|14
end_define

begin_define
define|#
directive|define
name|SRST_CORE3_DBG
value|15
end_define

begin_define
define|#
directive|define
name|SRST_PDBUG_AHB_ARBITOR
value|16
end_define

begin_define
define|#
directive|define
name|SRST_EFUSE256
value|17
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
name|SRST_TIMER
value|22
end_define

begin_define
define|#
directive|define
name|SRST_I2S0
value|23
end_define

begin_define
define|#
directive|define
name|SRST_SPDIF
value|24
end_define

begin_define
define|#
directive|define
name|SRST_TIMER0
value|25
end_define

begin_define
define|#
directive|define
name|SRST_TIMER1
value|26
end_define

begin_define
define|#
directive|define
name|SRST_TIMER2
value|27
end_define

begin_define
define|#
directive|define
name|SRST_TIMER3
value|28
end_define

begin_define
define|#
directive|define
name|SRST_TIMER4
value|29
end_define

begin_define
define|#
directive|define
name|SRST_TIMER5
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
name|SRST_GPIO5
value|37
end_define

begin_define
define|#
directive|define
name|SRST_GPIO6
value|38
end_define

begin_define
define|#
directive|define
name|SRST_GPIO7
value|39
end_define

begin_define
define|#
directive|define
name|SRST_GPIO8
value|40
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
name|SRST_DAP
value|51
end_define

begin_define
define|#
directive|define
name|SRST_DAP_SYS
value|52
end_define

begin_define
define|#
directive|define
name|SRST_TPIU
value|53
end_define

begin_define
define|#
directive|define
name|SRST_PMU_APB
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
name|SRST_CCP
value|71
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
name|SRST_NANDC1
value|78
end_define

begin_define
define|#
directive|define
name|SRST_TZPC
value|80
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
name|SRST_VIO1_NIU_AXI
value|103
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
name|SRST_EDP
value|111
end_define

begin_define
define|#
directive|define
name|SRST_VCODEC_AXI
value|112
end_define

begin_define
define|#
directive|define
name|SRST_VCODEC_AHB
value|113
end_define

begin_define
define|#
directive|define
name|SRST_VIO_H2P
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
name|SRST_MIPIDSI1
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
name|SRST_LVDS_PHY
value|118
end_define

begin_define
define|#
directive|define
name|SRST_LVDS_CON
value|119
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
name|SRST_SDIO1
value|130
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
name|SRST_USBHOST1_AHB
value|138
end_define

begin_define
define|#
directive|define
name|SRST_USBHOST1_PHY
value|139
end_define

begin_define
define|#
directive|define
name|SRST_USBHOST1_CON
value|140
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
name|SRST_ACC_EFUSE
value|142
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
name|SRST_PD_CORE_MP_AXI
value|147
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
name|SRST_LCDC_PWM1
value|150
end_define

begin_define
define|#
directive|define
name|SRST_VIO0_H2P_BRG
value|151
end_define

begin_define
define|#
directive|define
name|SRST_VIO1_H2P_BRG
value|152
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
name|SRST_HEVC
value|154
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
name|SRST_DDRPHY0_CTRL
value|164
end_define

begin_define
define|#
directive|define
name|SRST_DDRPHY1
value|165
end_define

begin_define
define|#
directive|define
name|SRST_DDRPHY1_APB
value|166
end_define

begin_define
define|#
directive|define
name|SRST_DDRCTRL1
value|167
end_define

begin_define
define|#
directive|define
name|SRST_DDRCTRL1_APB
value|168
end_define

begin_define
define|#
directive|define
name|SRST_DDRPHY1_CTRL
value|169
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
name|SRST_DDRMSCH1
value|171
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
name|SRST_C2C_HOST
value|175
end_define

begin_define
define|#
directive|define
name|SRST_LCDC1_AXI
value|176
end_define

begin_define
define|#
directive|define
name|SRST_LCDC1_AHB
value|177
end_define

begin_define
define|#
directive|define
name|SRST_LCDC1_DCLK
value|178
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
name|SRST_PS2C
value|187
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
name|SRST_TSP_CLKIN1
value|190
end_define

begin_define
define|#
directive|define
name|SRST_TSP_27M
value|191
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

