begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2016-2017 Linaro Ltd.  * Copyright (c) 2016-2017 HiSilicon Technologies Co., Ltd.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DTS_HI3660_CLOCK_H
end_ifndef

begin_define
define|#
directive|define
name|__DTS_HI3660_CLOCK_H
end_define

begin_comment
comment|/* fixed rate clocks */
end_comment

begin_define
define|#
directive|define
name|HI3660_CLKIN_SYS
value|0
end_define

begin_define
define|#
directive|define
name|HI3660_CLKIN_REF
value|1
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_FLL_SRC
value|2
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_PPLL0
value|3
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_PPLL1
value|4
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_PPLL2
value|5
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_PPLL3
value|6
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_SCPLL
value|7
end_define

begin_define
define|#
directive|define
name|HI3660_PCLK
value|8
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_UART0_DBG
value|9
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_UART6
value|10
end_define

begin_define
define|#
directive|define
name|HI3660_OSC32K
value|11
end_define

begin_define
define|#
directive|define
name|HI3660_OSC19M
value|12
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_480M
value|13
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_INV
value|14
end_define

begin_comment
comment|/* clk in crgctrl */
end_comment

begin_define
define|#
directive|define
name|HI3660_FACTOR_UART3
value|15
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_FACTOR_MMC
value|16
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_GATE_I2C0
value|17
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_GATE_I2C1
value|18
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_GATE_I2C2
value|19
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_GATE_I2C6
value|20
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_DIV_SYSBUS
value|21
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_DIV_320M
value|22
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_DIV_A53
value|23
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_GATE_SPI0
value|24
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_GATE_SPI2
value|25
end_define

begin_define
define|#
directive|define
name|HI3660_PCIEPHY_REF
value|26
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_ABB_USB
value|27
end_define

begin_define
define|#
directive|define
name|HI3660_HCLK_GATE_SDIO0
value|28
end_define

begin_define
define|#
directive|define
name|HI3660_HCLK_GATE_SD
value|29
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_GATE_AOMM
value|30
end_define

begin_define
define|#
directive|define
name|HI3660_PCLK_GPIO0
value|31
end_define

begin_define
define|#
directive|define
name|HI3660_PCLK_GPIO1
value|32
end_define

begin_define
define|#
directive|define
name|HI3660_PCLK_GPIO2
value|33
end_define

begin_define
define|#
directive|define
name|HI3660_PCLK_GPIO3
value|34
end_define

begin_define
define|#
directive|define
name|HI3660_PCLK_GPIO4
value|35
end_define

begin_define
define|#
directive|define
name|HI3660_PCLK_GPIO5
value|36
end_define

begin_define
define|#
directive|define
name|HI3660_PCLK_GPIO6
value|37
end_define

begin_define
define|#
directive|define
name|HI3660_PCLK_GPIO7
value|38
end_define

begin_define
define|#
directive|define
name|HI3660_PCLK_GPIO8
value|39
end_define

begin_define
define|#
directive|define
name|HI3660_PCLK_GPIO9
value|40
end_define

begin_define
define|#
directive|define
name|HI3660_PCLK_GPIO10
value|41
end_define

begin_define
define|#
directive|define
name|HI3660_PCLK_GPIO11
value|42
end_define

begin_define
define|#
directive|define
name|HI3660_PCLK_GPIO12
value|43
end_define

begin_define
define|#
directive|define
name|HI3660_PCLK_GPIO13
value|44
end_define

begin_define
define|#
directive|define
name|HI3660_PCLK_GPIO14
value|45
end_define

begin_define
define|#
directive|define
name|HI3660_PCLK_GPIO15
value|46
end_define

begin_define
define|#
directive|define
name|HI3660_PCLK_GPIO16
value|47
end_define

begin_define
define|#
directive|define
name|HI3660_PCLK_GPIO17
value|48
end_define

begin_define
define|#
directive|define
name|HI3660_PCLK_GPIO18
value|49
end_define

begin_define
define|#
directive|define
name|HI3660_PCLK_GPIO19
value|50
end_define

begin_define
define|#
directive|define
name|HI3660_PCLK_GPIO20
value|51
end_define

begin_define
define|#
directive|define
name|HI3660_PCLK_GPIO21
value|52
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_GATE_SPI3
value|53
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_GATE_I2C7
value|54
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_GATE_I2C3
value|55
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_GATE_SPI1
value|56
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_GATE_UART1
value|57
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_GATE_UART2
value|58
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_GATE_UART4
value|59
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_GATE_UART5
value|60
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_GATE_I2C4
value|61
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_GATE_DMAC
value|62
end_define

begin_define
define|#
directive|define
name|HI3660_PCLK_GATE_DSS
value|63
end_define

begin_define
define|#
directive|define
name|HI3660_ACLK_GATE_DSS
value|64
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_GATE_LDI1
value|65
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_GATE_LDI0
value|66
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_GATE_VIVOBUS
value|67
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_GATE_EDC0
value|68
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_GATE_TXDPHY0_CFG
value|69
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_GATE_TXDPHY0_REF
value|70
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_GATE_TXDPHY1_CFG
value|71
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_GATE_TXDPHY1_REF
value|72
end_define

begin_define
define|#
directive|define
name|HI3660_ACLK_GATE_USB3OTG
value|73
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_GATE_SPI4
value|74
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_GATE_SD
value|75
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_GATE_SDIO0
value|76
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_GATE_UFS_SUBSYS
value|77
end_define

begin_define
define|#
directive|define
name|HI3660_PCLK_GATE_DSI0
value|78
end_define

begin_define
define|#
directive|define
name|HI3660_PCLK_GATE_DSI1
value|79
end_define

begin_define
define|#
directive|define
name|HI3660_ACLK_GATE_PCIE
value|80
end_define

begin_define
define|#
directive|define
name|HI3660_PCLK_GATE_PCIE_SYS
value|81
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_GATE_PCIEAUX
value|82
end_define

begin_define
define|#
directive|define
name|HI3660_PCLK_GATE_PCIE_PHY
value|83
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_ANDGT_LDI0
value|84
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_ANDGT_LDI1
value|85
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_ANDGT_EDC0
value|86
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_GATE_UFSPHY_GT
value|87
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_ANDGT_MMC
value|88
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_ANDGT_SD
value|89
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_A53HPM_ANDGT
value|90
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_ANDGT_SDIO
value|91
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_ANDGT_UART0
value|92
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_ANDGT_UART1
value|93
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_ANDGT_UARTH
value|94
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_ANDGT_SPI
value|95
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_VIVOBUS_ANDGT
value|96
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_AOMM_ANDGT
value|97
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_320M_PLL_GT
value|98
end_define

begin_define
define|#
directive|define
name|HI3660_AUTODIV_EMMC0BUS
value|99
end_define

begin_define
define|#
directive|define
name|HI3660_AUTODIV_SYSBUS
value|100
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_GATE_UFSPHY_CFG
value|101
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_GATE_UFSIO_REF
value|102
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_MUX_SYSBUS
value|103
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_MUX_UART0
value|104
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_MUX_UART1
value|105
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_MUX_UARTH
value|106
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_MUX_SPI
value|107
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_MUX_I2C
value|108
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_MUX_MMC_PLL
value|109
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_MUX_LDI1
value|110
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_MUX_LDI0
value|111
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_MUX_SD_PLL
value|112
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_MUX_SD_SYS
value|113
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_MUX_EDC0
value|114
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_MUX_SDIO_SYS
value|115
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_MUX_SDIO_PLL
value|116
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_MUX_VIVOBUS
value|117
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_MUX_A53HPM
value|118
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_MUX_320M
value|119
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_MUX_IOPERI
value|120
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_DIV_UART0
value|121
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_DIV_UART1
value|122
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_DIV_UARTH
value|123
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_DIV_MMC
value|124
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_DIV_SD
value|125
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_DIV_EDC0
value|126
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_DIV_LDI0
value|127
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_DIV_SDIO
value|128
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_DIV_LDI1
value|129
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_DIV_SPI
value|130
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_DIV_VIVOBUS
value|131
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_DIV_I2C
value|132
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_DIV_UFSPHY
value|133
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_DIV_CFGBUS
value|134
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_DIV_MMC0BUS
value|135
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_DIV_MMC1BUS
value|136
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_DIV_UFSPERI
value|137
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_DIV_AOMM
value|138
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_DIV_IOPERI
value|139
end_define

begin_comment
comment|/* clk in pmuctrl */
end_comment

begin_define
define|#
directive|define
name|HI3660_GATE_ABB_192
value|0
end_define

begin_comment
comment|/* clk in pctrl */
end_comment

begin_define
define|#
directive|define
name|HI3660_GATE_UFS_TCXO_EN
value|0
end_define

begin_define
define|#
directive|define
name|HI3660_GATE_USB_TCXO_EN
value|1
end_define

begin_comment
comment|/* clk in sctrl */
end_comment

begin_define
define|#
directive|define
name|HI3660_PCLK_AO_GPIO0
value|0
end_define

begin_define
define|#
directive|define
name|HI3660_PCLK_AO_GPIO1
value|1
end_define

begin_define
define|#
directive|define
name|HI3660_PCLK_AO_GPIO2
value|2
end_define

begin_define
define|#
directive|define
name|HI3660_PCLK_AO_GPIO3
value|3
end_define

begin_define
define|#
directive|define
name|HI3660_PCLK_AO_GPIO4
value|4
end_define

begin_define
define|#
directive|define
name|HI3660_PCLK_AO_GPIO5
value|5
end_define

begin_define
define|#
directive|define
name|HI3660_PCLK_AO_GPIO6
value|6
end_define

begin_define
define|#
directive|define
name|HI3660_PCLK_GATE_MMBUF
value|7
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_GATE_DSS_AXI_MM
value|8
end_define

begin_define
define|#
directive|define
name|HI3660_PCLK_MMBUF_ANDGT
value|9
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_MMBUF_PLL_ANDGT
value|10
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_FLL_MMBUF_ANDGT
value|11
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_SYS_MMBUF_ANDGT
value|12
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_GATE_PCIEPHY_GT
value|13
end_define

begin_define
define|#
directive|define
name|HI3660_ACLK_MUX_MMBUF
value|14
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_SW_MMBUF
value|15
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_DIV_AOBUS
value|16
end_define

begin_define
define|#
directive|define
name|HI3660_PCLK_DIV_MMBUF
value|17
end_define

begin_define
define|#
directive|define
name|HI3660_ACLK_DIV_MMBUF
value|18
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_DIV_PCIEPHY
value|19
end_define

begin_comment
comment|/* clk in iomcu */
end_comment

begin_define
define|#
directive|define
name|HI3660_CLK_I2C0_IOMCU
value|0
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_I2C1_IOMCU
value|1
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_I2C2_IOMCU
value|2
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_I2C6_IOMCU
value|3
end_define

begin_define
define|#
directive|define
name|HI3660_CLK_IOMCU_PERI0
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DTS_HI3660_CLOCK_H */
end_comment

end_unit

