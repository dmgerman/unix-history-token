begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2015 Rockchip Electronics Co. Ltd.  * Author: Xing Zheng<zhengxing@rock-chips.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLK_ROCKCHIP_RK3036_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLK_ROCKCHIP_RK3036_H
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
name|PLL_GPLL
value|3
end_define

begin_define
define|#
directive|define
name|ARMCLK
value|4
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
name|SCLK_SPI
value|65
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
name|SCLK_NANDC
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
name|SCLK_I2S
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
name|SCLK_OTGPHY0
value|93
end_define

begin_define
define|#
directive|define
name|SCLK_LCDC
value|100
end_define

begin_define
define|#
directive|define
name|SCLK_HDMI
value|109
end_define

begin_define
define|#
directive|define
name|SCLK_HEVC
value|111
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
name|SCLK_PVTM_VIDEO
value|125
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
name|SCLK_MACREF
value|152
end_define

begin_define
define|#
directive|define
name|SCLK_SFC
value|160
end_define

begin_comment
comment|/* aclk gates */
end_comment

begin_define
define|#
directive|define
name|ACLK_DMAC2
value|194
end_define

begin_define
define|#
directive|define
name|ACLK_LCDC
value|197
end_define

begin_define
define|#
directive|define
name|ACLK_VIO
value|203
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
name|PCLK_SPI
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
name|PCLK_HDMI
value|360
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
name|PCLK_DDRUPCTL
value|364
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
name|PCLK_ACODEC
value|369
end_define

begin_comment
comment|/* hclk gates */
end_comment

begin_define
define|#
directive|define
name|HCLK_OTG0
value|449
end_define

begin_define
define|#
directive|define
name|HCLK_OTG1
value|450
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
name|HCLK_I2S
value|462
end_define

begin_define
define|#
directive|define
name|HCLK_LCDC
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
name|HCLK_VIO_BUS
value|472
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
name|SRST_CORE0_DBG
value|4
end_define

begin_define
define|#
directive|define
name|SRST_CORE1_DBG
value|5
end_define

begin_define
define|#
directive|define
name|SRST_CORE0_POR
value|8
end_define

begin_define
define|#
directive|define
name|SRST_CORE1_POR
value|9
end_define

begin_define
define|#
directive|define
name|SRST_L2C
value|12
end_define

begin_define
define|#
directive|define
name|SRST_TOPDBG
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
name|SRST_PD_CORE_NIU
value|15
end_define

begin_define
define|#
directive|define
name|SRST_TIMER2
value|16
end_define

begin_define
define|#
directive|define
name|SRST_CPUSYS_H
value|17
end_define

begin_define
define|#
directive|define
name|SRST_AHB2APB_H
value|19
end_define

begin_define
define|#
directive|define
name|SRST_TIMER3
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
name|SRST_I2S
value|24
end_define

begin_define
define|#
directive|define
name|SRST_DDR_PLL
value|25
end_define

begin_define
define|#
directive|define
name|SRST_GPU_DLL
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
name|SRST_CORE_DLL
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
name|SRST_SFC
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
name|SRST_GRF
value|55
end_define

begin_define
define|#
directive|define
name|SRST_PERIPHSYS_A
value|57
end_define

begin_define
define|#
directive|define
name|SRST_PERIPHSYS_H
value|58
end_define

begin_define
define|#
directive|define
name|SRST_PERIPHSYS_P
value|59
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
name|SRST_MAC
value|66
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
name|SRST_MMC0
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
name|SRST_WDT
value|86
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
name|SRST_HDMI_P
value|96
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
name|SRST_HEVC
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
name|SRST_LCDC1_A
value|117
end_define

begin_define
define|#
directive|define
name|SRST_LCDC1_H
value|118
end_define

begin_define
define|#
directive|define
name|SRST_LCDC1_D
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
name|SRST_DBG_P
value|131
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

