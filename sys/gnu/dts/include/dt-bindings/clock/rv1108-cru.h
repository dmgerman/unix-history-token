begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2016 Rockchip Electronics Co. Ltd.  * Author: Shawn Lin<shawn.lin@rock-chips.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLK_ROCKCHIP_RV1108_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLK_ROCKCHIP_RV1108_H
end_define

begin_comment
comment|/* pll id */
end_comment

begin_define
define|#
directive|define
name|PLL_APLL
value|0
end_define

begin_define
define|#
directive|define
name|PLL_DPLL
value|1
end_define

begin_define
define|#
directive|define
name|PLL_GPLL
value|2
end_define

begin_define
define|#
directive|define
name|ARMCLK
value|3
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
value|72
end_define

begin_define
define|#
directive|define
name|SCLK_UART1
value|73
end_define

begin_define
define|#
directive|define
name|SCLK_UART2
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
name|SCLK_TIMER0
value|78
end_define

begin_define
define|#
directive|define
name|SCLK_TIMER1
value|79
end_define

begin_define
define|#
directive|define
name|SCLK_SFC
value|80
end_define

begin_define
define|#
directive|define
name|SCLK_SDMMC_DRV
value|81
end_define

begin_define
define|#
directive|define
name|SCLK_SDIO_DRV
value|82
end_define

begin_define
define|#
directive|define
name|SCLK_EMMC_DRV
value|83
end_define

begin_define
define|#
directive|define
name|SCLK_SDMMC_SAMPLE
value|84
end_define

begin_define
define|#
directive|define
name|SCLK_SDIO_SAMPLE
value|85
end_define

begin_define
define|#
directive|define
name|SCLK_EMMC_SAMPLE
value|86
end_define

begin_comment
comment|/* aclk gates */
end_comment

begin_define
define|#
directive|define
name|ACLK_DMAC
value|192
end_define

begin_define
define|#
directive|define
name|ACLK_PRE
value|193
end_define

begin_define
define|#
directive|define
name|ACLK_CORE
value|194
end_define

begin_define
define|#
directive|define
name|ACLK_ENMCORE
value|195
end_define

begin_comment
comment|/* pclk gates */
end_comment

begin_define
define|#
directive|define
name|PCLK_GPIO1
value|256
end_define

begin_define
define|#
directive|define
name|PCLK_GPIO2
value|257
end_define

begin_define
define|#
directive|define
name|PCLK_GPIO3
value|258
end_define

begin_define
define|#
directive|define
name|PCLK_GRF
value|259
end_define

begin_define
define|#
directive|define
name|PCLK_I2C1
value|260
end_define

begin_define
define|#
directive|define
name|PCLK_I2C2
value|261
end_define

begin_define
define|#
directive|define
name|PCLK_I2C3
value|262
end_define

begin_define
define|#
directive|define
name|PCLK_SPI
value|263
end_define

begin_define
define|#
directive|define
name|PCLK_SFC
value|264
end_define

begin_define
define|#
directive|define
name|PCLK_UART0
value|265
end_define

begin_define
define|#
directive|define
name|PCLK_UART1
value|266
end_define

begin_define
define|#
directive|define
name|PCLK_UART2
value|267
end_define

begin_define
define|#
directive|define
name|PCLK_TSADC
value|268
end_define

begin_define
define|#
directive|define
name|PCLK_PWM
value|269
end_define

begin_define
define|#
directive|define
name|PCLK_TIMER
value|270
end_define

begin_define
define|#
directive|define
name|PCLK_PERI
value|271
end_define

begin_comment
comment|/* hclk gates */
end_comment

begin_define
define|#
directive|define
name|HCLK_I2S0_8CH
value|320
end_define

begin_define
define|#
directive|define
name|HCLK_I2S1_8CH
value|321
end_define

begin_define
define|#
directive|define
name|HCLK_I2S2_2CH
value|322
end_define

begin_define
define|#
directive|define
name|HCLK_NANDC
value|323
end_define

begin_define
define|#
directive|define
name|HCLK_SDMMC
value|324
end_define

begin_define
define|#
directive|define
name|HCLK_SDIO
value|325
end_define

begin_define
define|#
directive|define
name|HCLK_EMMC
value|326
end_define

begin_define
define|#
directive|define
name|HCLK_PERI
value|327
end_define

begin_define
define|#
directive|define
name|HCLK_SFC
value|328
end_define

begin_define
define|#
directive|define
name|CLK_NR_CLKS
value|(HCLK_SFC + 1)
end_define

begin_comment
comment|/* reset id */
end_comment

begin_define
define|#
directive|define
name|SRST_CORE_PO_AD
value|0
end_define

begin_define
define|#
directive|define
name|SRST_CORE_AD
value|1
end_define

begin_define
define|#
directive|define
name|SRST_L2_AD
value|2
end_define

begin_define
define|#
directive|define
name|SRST_CPU_NIU_AD
value|3
end_define

begin_define
define|#
directive|define
name|SRST_CORE_PO
value|4
end_define

begin_define
define|#
directive|define
name|SRST_CORE
value|5
end_define

begin_define
define|#
directive|define
name|SRST_L2
value|6
end_define

begin_define
define|#
directive|define
name|SRST_CORE_DBG
value|8
end_define

begin_define
define|#
directive|define
name|PRST_DBG
value|9
end_define

begin_define
define|#
directive|define
name|RST_DAP
value|10
end_define

begin_define
define|#
directive|define
name|PRST_DBG_NIU
value|11
end_define

begin_define
define|#
directive|define
name|ARST_STRC_SYS_AD
value|15
end_define

begin_define
define|#
directive|define
name|SRST_DDRPHY_CLKDIV
value|16
end_define

begin_define
define|#
directive|define
name|SRST_DDRPHY
value|17
end_define

begin_define
define|#
directive|define
name|PRST_DDRPHY
value|18
end_define

begin_define
define|#
directive|define
name|PRST_HDMIPHY
value|19
end_define

begin_define
define|#
directive|define
name|PRST_VDACPHY
value|20
end_define

begin_define
define|#
directive|define
name|PRST_VADCPHY
value|21
end_define

begin_define
define|#
directive|define
name|PRST_MIPI_CSI_PHY
value|22
end_define

begin_define
define|#
directive|define
name|PRST_MIPI_DSI_PHY
value|23
end_define

begin_define
define|#
directive|define
name|PRST_ACODEC
value|24
end_define

begin_define
define|#
directive|define
name|ARST_BUS_NIU
value|25
end_define

begin_define
define|#
directive|define
name|PRST_TOP_NIU
value|26
end_define

begin_define
define|#
directive|define
name|ARST_INTMEM
value|27
end_define

begin_define
define|#
directive|define
name|HRST_ROM
value|28
end_define

begin_define
define|#
directive|define
name|ARST_DMAC
value|29
end_define

begin_define
define|#
directive|define
name|SRST_MSCH_NIU
value|30
end_define

begin_define
define|#
directive|define
name|PRST_MSCH_NIU
value|31
end_define

begin_define
define|#
directive|define
name|PRST_DDRUPCTL
value|32
end_define

begin_define
define|#
directive|define
name|NRST_DDRUPCTL
value|33
end_define

begin_define
define|#
directive|define
name|PRST_DDRMON
value|34
end_define

begin_define
define|#
directive|define
name|HRST_I2S0_8CH
value|35
end_define

begin_define
define|#
directive|define
name|MRST_I2S0_8CH
value|36
end_define

begin_define
define|#
directive|define
name|HRST_I2S1_2CH
value|37
end_define

begin_define
define|#
directive|define
name|MRST_IS21_2CH
value|38
end_define

begin_define
define|#
directive|define
name|HRST_I2S2_2CH
value|39
end_define

begin_define
define|#
directive|define
name|MRST_I2S2_2CH
value|40
end_define

begin_define
define|#
directive|define
name|HRST_CRYPTO
value|41
end_define

begin_define
define|#
directive|define
name|SRST_CRYPTO
value|42
end_define

begin_define
define|#
directive|define
name|PRST_SPI
value|43
end_define

begin_define
define|#
directive|define
name|SRST_SPI
value|44
end_define

begin_define
define|#
directive|define
name|PRST_UART0
value|45
end_define

begin_define
define|#
directive|define
name|PRST_UART1
value|46
end_define

begin_define
define|#
directive|define
name|PRST_UART2
value|47
end_define

begin_define
define|#
directive|define
name|SRST_UART0
value|48
end_define

begin_define
define|#
directive|define
name|SRST_UART1
value|49
end_define

begin_define
define|#
directive|define
name|SRST_UART2
value|50
end_define

begin_define
define|#
directive|define
name|PRST_I2C1
value|51
end_define

begin_define
define|#
directive|define
name|PRST_I2C2
value|52
end_define

begin_define
define|#
directive|define
name|PRST_I2C3
value|53
end_define

begin_define
define|#
directive|define
name|SRST_I2C1
value|54
end_define

begin_define
define|#
directive|define
name|SRST_I2C2
value|55
end_define

begin_define
define|#
directive|define
name|SRST_I2C3
value|56
end_define

begin_define
define|#
directive|define
name|PRST_PWM1
value|58
end_define

begin_define
define|#
directive|define
name|SRST_PWM1
value|60
end_define

begin_define
define|#
directive|define
name|PRST_WDT
value|61
end_define

begin_define
define|#
directive|define
name|PRST_GPIO1
value|62
end_define

begin_define
define|#
directive|define
name|PRST_GPIO2
value|63
end_define

begin_define
define|#
directive|define
name|PRST_GPIO3
value|64
end_define

begin_define
define|#
directive|define
name|PRST_GRF
value|65
end_define

begin_define
define|#
directive|define
name|PRST_EFUSE
value|66
end_define

begin_define
define|#
directive|define
name|PRST_EFUSE512
value|67
end_define

begin_define
define|#
directive|define
name|PRST_TIMER0
value|68
end_define

begin_define
define|#
directive|define
name|SRST_TIMER0
value|69
end_define

begin_define
define|#
directive|define
name|SRST_TIMER1
value|70
end_define

begin_define
define|#
directive|define
name|PRST_TSADC
value|71
end_define

begin_define
define|#
directive|define
name|SRST_TSADC
value|72
end_define

begin_define
define|#
directive|define
name|PRST_SARADC
value|73
end_define

begin_define
define|#
directive|define
name|SRST_SARADC
value|74
end_define

begin_define
define|#
directive|define
name|HRST_SYSBUS
value|75
end_define

begin_define
define|#
directive|define
name|PRST_USBGRF
value|76
end_define

begin_define
define|#
directive|define
name|ARST_PERIPH_NIU
value|80
end_define

begin_define
define|#
directive|define
name|HRST_PERIPH_NIU
value|81
end_define

begin_define
define|#
directive|define
name|PRST_PERIPH_NIU
value|82
end_define

begin_define
define|#
directive|define
name|HRST_PERIPH
value|83
end_define

begin_define
define|#
directive|define
name|HRST_SDMMC
value|84
end_define

begin_define
define|#
directive|define
name|HRST_SDIO
value|85
end_define

begin_define
define|#
directive|define
name|HRST_EMMC
value|86
end_define

begin_define
define|#
directive|define
name|HRST_NANDC
value|87
end_define

begin_define
define|#
directive|define
name|NRST_NANDC
value|88
end_define

begin_define
define|#
directive|define
name|HRST_SFC
value|89
end_define

begin_define
define|#
directive|define
name|SRST_SFC
value|90
end_define

begin_define
define|#
directive|define
name|ARST_GMAC
value|91
end_define

begin_define
define|#
directive|define
name|HRST_OTG
value|92
end_define

begin_define
define|#
directive|define
name|SRST_OTG
value|93
end_define

begin_define
define|#
directive|define
name|SRST_OTG_ADP
value|94
end_define

begin_define
define|#
directive|define
name|HRST_HOST0
value|95
end_define

begin_define
define|#
directive|define
name|HRST_HOST0_AUX
value|96
end_define

begin_define
define|#
directive|define
name|HRST_HOST0_ARB
value|97
end_define

begin_define
define|#
directive|define
name|SRST_HOST0_EHCIPHY
value|98
end_define

begin_define
define|#
directive|define
name|SRST_HOST0_UTMI
value|99
end_define

begin_define
define|#
directive|define
name|SRST_USBPOR
value|100
end_define

begin_define
define|#
directive|define
name|SRST_UTMI0
value|101
end_define

begin_define
define|#
directive|define
name|SRST_UTMI1
value|102
end_define

begin_define
define|#
directive|define
name|ARST_VIO0_NIU
value|102
end_define

begin_define
define|#
directive|define
name|ARST_VIO1_NIU
value|103
end_define

begin_define
define|#
directive|define
name|HRST_VIO_NIU
value|104
end_define

begin_define
define|#
directive|define
name|PRST_VIO_NIU
value|105
end_define

begin_define
define|#
directive|define
name|ARST_VOP
value|106
end_define

begin_define
define|#
directive|define
name|HRST_VOP
value|107
end_define

begin_define
define|#
directive|define
name|DRST_VOP
value|108
end_define

begin_define
define|#
directive|define
name|ARST_IEP
value|109
end_define

begin_define
define|#
directive|define
name|HRST_IEP
value|110
end_define

begin_define
define|#
directive|define
name|ARST_RGA
value|111
end_define

begin_define
define|#
directive|define
name|HRST_RGA
value|112
end_define

begin_define
define|#
directive|define
name|SRST_RGA
value|113
end_define

begin_define
define|#
directive|define
name|PRST_CVBS
value|114
end_define

begin_define
define|#
directive|define
name|PRST_HDMI
value|115
end_define

begin_define
define|#
directive|define
name|SRST_HDMI
value|116
end_define

begin_define
define|#
directive|define
name|PRST_MIPI_DSI
value|117
end_define

begin_define
define|#
directive|define
name|ARST_ISP_NIU
value|118
end_define

begin_define
define|#
directive|define
name|HRST_ISP_NIU
value|119
end_define

begin_define
define|#
directive|define
name|HRST_ISP
value|120
end_define

begin_define
define|#
directive|define
name|SRST_ISP
value|121
end_define

begin_define
define|#
directive|define
name|ARST_VIP0
value|122
end_define

begin_define
define|#
directive|define
name|HRST_VIP0
value|123
end_define

begin_define
define|#
directive|define
name|PRST_VIP0
value|124
end_define

begin_define
define|#
directive|define
name|ARST_VIP1
value|125
end_define

begin_define
define|#
directive|define
name|HRST_VIP1
value|126
end_define

begin_define
define|#
directive|define
name|PRST_VIP1
value|127
end_define

begin_define
define|#
directive|define
name|ARST_VIP2
value|128
end_define

begin_define
define|#
directive|define
name|HRST_VIP2
value|129
end_define

begin_define
define|#
directive|define
name|PRST_VIP2
value|120
end_define

begin_define
define|#
directive|define
name|ARST_VIP3
value|121
end_define

begin_define
define|#
directive|define
name|HRST_VIP3
value|122
end_define

begin_define
define|#
directive|define
name|PRST_VIP4
value|123
end_define

begin_define
define|#
directive|define
name|PRST_CIF1TO4
value|124
end_define

begin_define
define|#
directive|define
name|SRST_CVBS_CLK
value|125
end_define

begin_define
define|#
directive|define
name|HRST_CVBS
value|126
end_define

begin_define
define|#
directive|define
name|ARST_VPU_NIU
value|140
end_define

begin_define
define|#
directive|define
name|HRST_VPU_NIU
value|141
end_define

begin_define
define|#
directive|define
name|ARST_VPU
value|142
end_define

begin_define
define|#
directive|define
name|HRST_VPU
value|143
end_define

begin_define
define|#
directive|define
name|ARST_RKVDEC_NIU
value|144
end_define

begin_define
define|#
directive|define
name|HRST_RKVDEC_NIU
value|145
end_define

begin_define
define|#
directive|define
name|ARST_RKVDEC
value|146
end_define

begin_define
define|#
directive|define
name|HRST_RKVDEC
value|147
end_define

begin_define
define|#
directive|define
name|SRST_RKVDEC_CABAC
value|148
end_define

begin_define
define|#
directive|define
name|SRST_RKVDEC_CORE
value|149
end_define

begin_define
define|#
directive|define
name|ARST_RKVENC_NIU
value|150
end_define

begin_define
define|#
directive|define
name|HRST_RKVENC_NIU
value|151
end_define

begin_define
define|#
directive|define
name|ARST_RKVENC
value|152
end_define

begin_define
define|#
directive|define
name|HRST_RKVENC
value|153
end_define

begin_define
define|#
directive|define
name|SRST_RKVENC_CORE
value|154
end_define

begin_define
define|#
directive|define
name|SRST_DSP_CORE
value|156
end_define

begin_define
define|#
directive|define
name|SRST_DSP_SYS
value|157
end_define

begin_define
define|#
directive|define
name|SRST_DSP_GLOBAL
value|158
end_define

begin_define
define|#
directive|define
name|SRST_DSP_OECM
value|159
end_define

begin_define
define|#
directive|define
name|PRST_DSP_IOP_NIU
value|160
end_define

begin_define
define|#
directive|define
name|ARST_DSP_EPP_NIU
value|161
end_define

begin_define
define|#
directive|define
name|ARST_DSP_EDP_NIU
value|162
end_define

begin_define
define|#
directive|define
name|PRST_DSP_DBG_NIU
value|163
end_define

begin_define
define|#
directive|define
name|PRST_DSP_CFG_NIU
value|164
end_define

begin_define
define|#
directive|define
name|PRST_DSP_GRF
value|165
end_define

begin_define
define|#
directive|define
name|PRST_DSP_MAILBOX
value|166
end_define

begin_define
define|#
directive|define
name|PRST_DSP_INTC
value|167
end_define

begin_define
define|#
directive|define
name|PRST_DSP_PFM_MON
value|169
end_define

begin_define
define|#
directive|define
name|SRST_DSP_PFM_MON
value|170
end_define

begin_define
define|#
directive|define
name|ARST_DSP_EDAP_NIU
value|171
end_define

begin_define
define|#
directive|define
name|SRST_PMU
value|172
end_define

begin_define
define|#
directive|define
name|SRST_PMU_I2C0
value|173
end_define

begin_define
define|#
directive|define
name|PRST_PMU_I2C0
value|174
end_define

begin_define
define|#
directive|define
name|PRST_PMU_GPIO0
value|175
end_define

begin_define
define|#
directive|define
name|PRST_PMU_INTMEM
value|176
end_define

begin_define
define|#
directive|define
name|PRST_PMU_PWM0
value|177
end_define

begin_define
define|#
directive|define
name|SRST_PMU_PWM0
value|178
end_define

begin_define
define|#
directive|define
name|PRST_PMU_GRF
value|179
end_define

begin_define
define|#
directive|define
name|SRST_PMU_NIU
value|180
end_define

begin_define
define|#
directive|define
name|SRST_PMU_PVTM
value|181
end_define

begin_define
define|#
directive|define
name|ARST_DSP_EDP_PERF
value|184
end_define

begin_define
define|#
directive|define
name|ARST_DSP_EPP_PERF
value|185
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_CLK_ROCKCHIP_RV1108_H */
end_comment

end_unit

