begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2014 MundoReader S.L.  * Author: Heiko Stuebner<heiko@sntech.de>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLK_ROCKCHIP_RK3188_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLK_ROCKCHIP_RK3188_COMMON_H
end_define

begin_comment
comment|/* core clocks from */
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
name|CORE_PERI
value|5
end_define

begin_define
define|#
directive|define
name|CORE_L2C
value|6
end_define

begin_define
define|#
directive|define
name|ARMCLK
value|7
end_define

begin_comment
comment|/* sclk gates (special clocks) */
end_comment

begin_define
define|#
directive|define
name|SCLK_UART0
value|64
end_define

begin_define
define|#
directive|define
name|SCLK_UART1
value|65
end_define

begin_define
define|#
directive|define
name|SCLK_UART2
value|66
end_define

begin_define
define|#
directive|define
name|SCLK_UART3
value|67
end_define

begin_define
define|#
directive|define
name|SCLK_MAC
value|68
end_define

begin_define
define|#
directive|define
name|SCLK_SPI0
value|69
end_define

begin_define
define|#
directive|define
name|SCLK_SPI1
value|70
end_define

begin_define
define|#
directive|define
name|SCLK_SARADC
value|71
end_define

begin_define
define|#
directive|define
name|SCLK_SDMMC
value|72
end_define

begin_define
define|#
directive|define
name|SCLK_SDIO
value|73
end_define

begin_define
define|#
directive|define
name|SCLK_EMMC
value|74
end_define

begin_define
define|#
directive|define
name|SCLK_I2S0
value|75
end_define

begin_define
define|#
directive|define
name|SCLK_I2S1
value|76
end_define

begin_define
define|#
directive|define
name|SCLK_I2S2
value|77
end_define

begin_define
define|#
directive|define
name|SCLK_SPDIF
value|78
end_define

begin_define
define|#
directive|define
name|SCLK_CIF0
value|79
end_define

begin_define
define|#
directive|define
name|SCLK_CIF1
value|80
end_define

begin_define
define|#
directive|define
name|SCLK_OTGPHY0
value|81
end_define

begin_define
define|#
directive|define
name|SCLK_OTGPHY1
value|82
end_define

begin_define
define|#
directive|define
name|SCLK_HSADC
value|83
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER0
value|84
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER1
value|85
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER2
value|86
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER3
value|87
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER4
value|88
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER5
value|89
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER6
value|90
end_define

begin_define
define|#
directive|define
name|SCLK_JTAG
value|91
end_define

begin_define
define|#
directive|define
name|SCLK_SMC
value|92
end_define

begin_define
define|#
directive|define
name|SCLK_TSADC
value|93
end_define

begin_define
define|#
directive|define
name|DCLK_LCDC0
value|190
end_define

begin_define
define|#
directive|define
name|DCLK_LCDC1
value|191
end_define

begin_comment
comment|/* aclk gates */
end_comment

begin_define
define|#
directive|define
name|ACLK_DMA1
value|192
end_define

begin_define
define|#
directive|define
name|ACLK_DMA2
value|193
end_define

begin_define
define|#
directive|define
name|ACLK_GPS
value|194
end_define

begin_define
define|#
directive|define
name|ACLK_LCDC0
value|195
end_define

begin_define
define|#
directive|define
name|ACLK_LCDC1
value|196
end_define

begin_define
define|#
directive|define
name|ACLK_GPU
value|197
end_define

begin_define
define|#
directive|define
name|ACLK_SMC
value|198
end_define

begin_define
define|#
directive|define
name|ACLK_CIF
value|199
end_define

begin_define
define|#
directive|define
name|ACLK_IPP
value|200
end_define

begin_define
define|#
directive|define
name|ACLK_RGA
value|201
end_define

begin_define
define|#
directive|define
name|ACLK_CIF0
value|202
end_define

begin_define
define|#
directive|define
name|ACLK_CPU
value|203
end_define

begin_define
define|#
directive|define
name|ACLK_PERI
value|204
end_define

begin_comment
comment|/* pclk gates */
end_comment

begin_define
define|#
directive|define
name|PCLK_GRF
value|320
end_define

begin_define
define|#
directive|define
name|PCLK_PMU
value|321
end_define

begin_define
define|#
directive|define
name|PCLK_TIMER0
value|322
end_define

begin_define
define|#
directive|define
name|PCLK_TIMER1
value|323
end_define

begin_define
define|#
directive|define
name|PCLK_TIMER2
value|324
end_define

begin_define
define|#
directive|define
name|PCLK_TIMER3
value|325
end_define

begin_define
define|#
directive|define
name|PCLK_PWM01
value|326
end_define

begin_define
define|#
directive|define
name|PCLK_PWM23
value|327
end_define

begin_define
define|#
directive|define
name|PCLK_SPI0
value|328
end_define

begin_define
define|#
directive|define
name|PCLK_SPI1
value|329
end_define

begin_define
define|#
directive|define
name|PCLK_SARADC
value|330
end_define

begin_define
define|#
directive|define
name|PCLK_WDT
value|331
end_define

begin_define
define|#
directive|define
name|PCLK_UART0
value|332
end_define

begin_define
define|#
directive|define
name|PCLK_UART1
value|333
end_define

begin_define
define|#
directive|define
name|PCLK_UART2
value|334
end_define

begin_define
define|#
directive|define
name|PCLK_UART3
value|335
end_define

begin_define
define|#
directive|define
name|PCLK_I2C0
value|336
end_define

begin_define
define|#
directive|define
name|PCLK_I2C1
value|337
end_define

begin_define
define|#
directive|define
name|PCLK_I2C2
value|338
end_define

begin_define
define|#
directive|define
name|PCLK_I2C3
value|339
end_define

begin_define
define|#
directive|define
name|PCLK_I2C4
value|340
end_define

begin_define
define|#
directive|define
name|PCLK_GPIO0
value|341
end_define

begin_define
define|#
directive|define
name|PCLK_GPIO1
value|342
end_define

begin_define
define|#
directive|define
name|PCLK_GPIO2
value|343
end_define

begin_define
define|#
directive|define
name|PCLK_GPIO3
value|344
end_define

begin_define
define|#
directive|define
name|PCLK_GPIO4
value|345
end_define

begin_define
define|#
directive|define
name|PCLK_GPIO6
value|346
end_define

begin_define
define|#
directive|define
name|PCLK_EFUSE
value|347
end_define

begin_define
define|#
directive|define
name|PCLK_TZPC
value|348
end_define

begin_define
define|#
directive|define
name|PCLK_TSADC
value|349
end_define

begin_define
define|#
directive|define
name|PCLK_CPU
value|350
end_define

begin_define
define|#
directive|define
name|PCLK_PERI
value|351
end_define

begin_define
define|#
directive|define
name|PCLK_DDRUPCTL
value|352
end_define

begin_define
define|#
directive|define
name|PCLK_PUBL
value|353
end_define

begin_comment
comment|/* hclk gates */
end_comment

begin_define
define|#
directive|define
name|HCLK_SDMMC
value|448
end_define

begin_define
define|#
directive|define
name|HCLK_SDIO
value|449
end_define

begin_define
define|#
directive|define
name|HCLK_EMMC
value|450
end_define

begin_define
define|#
directive|define
name|HCLK_OTG0
value|451
end_define

begin_define
define|#
directive|define
name|HCLK_EMAC
value|452
end_define

begin_define
define|#
directive|define
name|HCLK_SPDIF
value|453
end_define

begin_define
define|#
directive|define
name|HCLK_I2S0
value|454
end_define

begin_define
define|#
directive|define
name|HCLK_I2S1
value|455
end_define

begin_define
define|#
directive|define
name|HCLK_I2S2
value|456
end_define

begin_define
define|#
directive|define
name|HCLK_OTG1
value|457
end_define

begin_define
define|#
directive|define
name|HCLK_HSIC
value|458
end_define

begin_define
define|#
directive|define
name|HCLK_HSADC
value|459
end_define

begin_define
define|#
directive|define
name|HCLK_PIDF
value|460
end_define

begin_define
define|#
directive|define
name|HCLK_LCDC0
value|461
end_define

begin_define
define|#
directive|define
name|HCLK_LCDC1
value|462
end_define

begin_define
define|#
directive|define
name|HCLK_ROM
value|463
end_define

begin_define
define|#
directive|define
name|HCLK_CIF0
value|464
end_define

begin_define
define|#
directive|define
name|HCLK_IPP
value|465
end_define

begin_define
define|#
directive|define
name|HCLK_RGA
value|466
end_define

begin_define
define|#
directive|define
name|HCLK_NANDC0
value|467
end_define

begin_define
define|#
directive|define
name|HCLK_CPU
value|468
end_define

begin_define
define|#
directive|define
name|HCLK_PERI
value|469
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
name|SRST_MCORE
value|2
end_define

begin_define
define|#
directive|define
name|SRST_CORE0
value|3
end_define

begin_define
define|#
directive|define
name|SRST_CORE1
value|4
end_define

begin_define
define|#
directive|define
name|SRST_MCORE_DBG
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
name|SRST_CORE0_WDT
value|12
end_define

begin_define
define|#
directive|define
name|SRST_CORE1_WDT
value|13
end_define

begin_define
define|#
directive|define
name|SRST_STRC_SYS
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
name|SRST_CPU_AHB
value|17
end_define

begin_define
define|#
directive|define
name|SRST_AHB2APB
value|19
end_define

begin_define
define|#
directive|define
name|SRST_DMA1
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
name|SRST_SPDIF
value|26
end_define

begin_define
define|#
directive|define
name|SRST_TIMER0
value|27
end_define

begin_define
define|#
directive|define
name|SRST_TIMER1
value|28
end_define

begin_define
define|#
directive|define
name|SRST_EFUSE
value|30
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
name|SRST_UART3
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
name|SRST_I2C4
value|47
end_define

begin_define
define|#
directive|define
name|SRST_PWM0
value|48
end_define

begin_define
define|#
directive|define
name|SRST_PWM1
value|49
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
name|SRST_TPIU_ATB
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
name|SRST_PERI_AXI
value|57
end_define

begin_define
define|#
directive|define
name|SRST_PERI_AHB
value|58
end_define

begin_define
define|#
directive|define
name|SRST_PERI_APB
value|59
end_define

begin_define
define|#
directive|define
name|SRST_PERI_NIU
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
name|SRST_DMA2
value|64
end_define

begin_define
define|#
directive|define
name|SRST_SMC
value|65
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
name|SRST_NANC0
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
name|SRST_USBPHY0
value|70
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
name|SRST_USBPHY1
value|73
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
name|SRST_HSADC
value|76
end_define

begin_define
define|#
directive|define
name|SRST_PIDFILTER
value|77
end_define

begin_define
define|#
directive|define
name|SRST_DDR_MSCH
value|79
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
name|SRST_SPI0
value|84
end_define

begin_define
define|#
directive|define
name|SRST_SPI1
value|85
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
name|SRST_DDRPHY_APB
value|89
end_define

begin_define
define|#
directive|define
name|SRST_DDRCTL
value|90
end_define

begin_define
define|#
directive|define
name|SRST_DDRCTL_APB
value|91
end_define

begin_define
define|#
directive|define
name|SRST_DDRPUB
value|93
end_define

begin_define
define|#
directive|define
name|SRST_VIO0_AXI
value|98
end_define

begin_define
define|#
directive|define
name|SRST_VIO0_AHB
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
name|SRST_LCDC1_AXI
value|103
end_define

begin_define
define|#
directive|define
name|SRST_LCDC1_AHB
value|104
end_define

begin_define
define|#
directive|define
name|SRST_LCDC1_DCLK
value|105
end_define

begin_define
define|#
directive|define
name|SRST_IPP_AXI
value|106
end_define

begin_define
define|#
directive|define
name|SRST_IPP_AHB
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
name|SRST_CIF0
value|110
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
name|SRST_VIO1_AXI
value|114
end_define

begin_define
define|#
directive|define
name|SRST_VCODEC_CPU
value|115
end_define

begin_define
define|#
directive|define
name|SRST_VCODEC_NIU
value|116
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
name|SRST_GPU_NIU
value|122
end_define

begin_define
define|#
directive|define
name|SRST_TFUN_ATB
value|125
end_define

begin_define
define|#
directive|define
name|SRST_TFUN_APB
value|126
end_define

begin_define
define|#
directive|define
name|SRST_CTI4_APB
value|127
end_define

begin_define
define|#
directive|define
name|SRST_TPIU_APB
value|128
end_define

begin_define
define|#
directive|define
name|SRST_TRACE
value|129
end_define

begin_define
define|#
directive|define
name|SRST_CORE_DBG
value|130
end_define

begin_define
define|#
directive|define
name|SRST_DBG_APB
value|131
end_define

begin_define
define|#
directive|define
name|SRST_CTI0
value|132
end_define

begin_define
define|#
directive|define
name|SRST_CTI0_APB
value|133
end_define

begin_define
define|#
directive|define
name|SRST_CTI1
value|134
end_define

begin_define
define|#
directive|define
name|SRST_CTI1_APB
value|135
end_define

begin_define
define|#
directive|define
name|SRST_PTM_CORE0
value|136
end_define

begin_define
define|#
directive|define
name|SRST_PTM_CORE1
value|137
end_define

begin_define
define|#
directive|define
name|SRST_PTM0
value|138
end_define

begin_define
define|#
directive|define
name|SRST_PTM0_ATB
value|139
end_define

begin_define
define|#
directive|define
name|SRST_PTM1
value|140
end_define

begin_define
define|#
directive|define
name|SRST_PTM1_ATB
value|141
end_define

begin_define
define|#
directive|define
name|SRST_CTM
value|142
end_define

begin_define
define|#
directive|define
name|SRST_TS
value|143
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

