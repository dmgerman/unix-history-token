begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017 Rockchip Electronics Co. Ltd.  * Author: Elaine<zhangqing@rock-chips.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLK_ROCKCHIP_RK3128_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLK_ROCKCHIP_RK3128_H
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

begin_define
define|#
directive|define
name|PLL_GPLL_DIV2
value|6
end_define

begin_define
define|#
directive|define
name|PLL_GPLL_DIV3
value|7
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
name|SCLK_SARADC
value|91
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
name|SCLK_MAC_SRC
value|124
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
name|SCLK_HEVC_CORE
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
name|SCLK_OTGPHY0
value|142
end_define

begin_define
define|#
directive|define
name|SCLK_OTGPHY1
value|143
end_define

begin_define
define|#
directive|define
name|SCLK_DDRC
value|144
end_define

begin_define
define|#
directive|define
name|SCLK_PVTM_FUNC
value|145
end_define

begin_define
define|#
directive|define
name|SCLK_PVTM_CORE
value|146
end_define

begin_define
define|#
directive|define
name|SCLK_PVTM_GPU
value|147
end_define

begin_define
define|#
directive|define
name|SCLK_MIPI_24M
value|148
end_define

begin_define
define|#
directive|define
name|SCLK_PVTM
value|149
end_define

begin_define
define|#
directive|define
name|SCLK_CIF_SRC
value|150
end_define

begin_define
define|#
directive|define
name|SCLK_CIF_OUT_SRC
value|151
end_define

begin_define
define|#
directive|define
name|SCLK_CIF_OUT
value|152
end_define

begin_define
define|#
directive|define
name|SCLK_SFC
value|153
end_define

begin_define
define|#
directive|define
name|SCLK_USB480M
value|154
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
name|DCLK_EBC
value|191
end_define

begin_comment
comment|/* aclk gates */
end_comment

begin_define
define|#
directive|define
name|ACLK_VIO0
value|192
end_define

begin_define
define|#
directive|define
name|ACLK_VIO1
value|193
end_define

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
name|ACLK_VEPU
value|196
end_define

begin_define
define|#
directive|define
name|ACLK_VDPU
value|197
end_define

begin_define
define|#
directive|define
name|ACLK_CIF
value|198
end_define

begin_define
define|#
directive|define
name|ACLK_IEP
value|199
end_define

begin_define
define|#
directive|define
name|ACLK_LCDC0
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
name|PCLK_SARADC
value|318
end_define

begin_define
define|#
directive|define
name|PCLK_WDT
value|319
end_define

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
name|PCLK_MIPI
value|325
end_define

begin_define
define|#
directive|define
name|PCLK_EFUSE
value|326
end_define

begin_define
define|#
directive|define
name|PCLK_HDMI
value|327
end_define

begin_define
define|#
directive|define
name|PCLK_ACODEC
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
name|PCLK_GMAC
value|367
end_define

begin_define
define|#
directive|define
name|PCLK_PMU_PRE
value|368
end_define

begin_define
define|#
directive|define
name|PCLK_SIM_CARD
value|369
end_define

begin_comment
comment|/* hclk gates */
end_comment

begin_define
define|#
directive|define
name|HCLK_SPDIF
value|440
end_define

begin_define
define|#
directive|define
name|HCLK_GPS
value|441
end_define

begin_define
define|#
directive|define
name|HCLK_USBHOST
value|442
end_define

begin_define
define|#
directive|define
name|HCLK_I2S_8CH
value|443
end_define

begin_define
define|#
directive|define
name|HCLK_I2S_2CH
value|444
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
name|HCLK_VEPU
value|461
end_define

begin_define
define|#
directive|define
name|HCLK_VDPU
value|462
end_define

begin_define
define|#
directive|define
name|HCLK_LCDC0
value|463
end_define

begin_define
define|#
directive|define
name|HCLK_EBC
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
name|HCLK_CIF
value|470
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
name|HCLK_CRYPTO
value|476
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
name|SRST_STRC_SYS_A
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
name|SRST_AHB2APBSYS_H
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
name|SRST_PERI_NIU
value|23
end_define

begin_define
define|#
directive|define
name|SRST_I2S_2CH
value|24
end_define

begin_define
define|#
directive|define
name|SRST_I2S_8CH
value|25
end_define

begin_define
define|#
directive|define
name|SRST_GPU_PVTM
value|26
end_define

begin_define
define|#
directive|define
name|SRST_FUNC_PVTM
value|27
end_define

begin_define
define|#
directive|define
name|SRST_CORE_PVTM
value|29
end_define

begin_define
define|#
directive|define
name|SRST_EFUSE_P
value|30
end_define

begin_define
define|#
directive|define
name|SRST_ACODEC_P
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
name|SRST_MIPIPHY_P
value|36
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
name|SRST_SFC
value|47
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
name|SRST_DAP_PO
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
name|SRST_CRYPTO
value|53
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
name|SRST_PERIPH_SYS_A
value|57
end_define

begin_define
define|#
directive|define
name|SRST_PERIPH_SYS_H
value|58
end_define

begin_define
define|#
directive|define
name|SRST_PERIPH_SYS_P
value|59
end_define

begin_define
define|#
directive|define
name|SRST_SMART_CARD
value|60
end_define

begin_define
define|#
directive|define
name|SRST_CPU_PERI
value|61
end_define

begin_define
define|#
directive|define
name|SRST_EMEM_PERI
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
name|SRST_DMA
value|64
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
name|SRST_NANDC
value|68
end_define

begin_define
define|#
directive|define
name|SRST_USBOTG0
value|69
end_define

begin_define
define|#
directive|define
name|SRST_OTGC0
value|71
end_define

begin_define
define|#
directive|define
name|SRST_USBOTG1
value|72
end_define

begin_define
define|#
directive|define
name|SRST_OTGC1
value|74
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
name|SRST_WDT
value|86
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
name|SRST_TSP
value|92
end_define

begin_define
define|#
directive|define
name|SRST_TSP_CLKIN
value|93
end_define

begin_define
define|#
directive|define
name|SRST_HOST0_ECHI
value|94
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
name|SRST_VIO0_A
value|98
end_define

begin_define
define|#
directive|define
name|SRST_VIO_BUS_H
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
name|SRST_USBPOR
value|105
end_define

begin_define
define|#
directive|define
name|SRST_IEP_A
value|106
end_define

begin_define
define|#
directive|define
name|SRST_IEP_H
value|107
end_define

begin_define
define|#
directive|define
name|SRST_RGA_A
value|108
end_define

begin_define
define|#
directive|define
name|SRST_RGA_H
value|109
end_define

begin_define
define|#
directive|define
name|SRST_CIF0
value|110
end_define

begin_define
define|#
directive|define
name|SRST_PMU
value|111
end_define

begin_define
define|#
directive|define
name|SRST_VCODEC_A
value|112
end_define

begin_define
define|#
directive|define
name|SRST_VCODEC_H
value|113
end_define

begin_define
define|#
directive|define
name|SRST_VIO1_A
value|114
end_define

begin_define
define|#
directive|define
name|SRST_HEVC_CORE
value|115
end_define

begin_define
define|#
directive|define
name|SRST_VCODEC_NIU_A
value|116
end_define

begin_define
define|#
directive|define
name|SRST_PMU_NIU_P
value|117
end_define

begin_define
define|#
directive|define
name|SRST_LCDC0_S
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
name|SRST_GPU_NIU_A
value|122
end_define

begin_define
define|#
directive|define
name|SRST_EBC_A
value|123
end_define

begin_define
define|#
directive|define
name|SRST_EBC_H
value|124
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
name|SRST_VIO_MIPI_DSI
value|137
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

