begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2014 MediaTek Inc.  * Author: Shunli Wang<shunli.wang@mediatek.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLK_MT2701_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLK_MT2701_H
end_define

begin_comment
comment|/* TOPCKGEN */
end_comment

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL
value|1
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL_D2
value|2
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL_D3
value|3
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL_D5
value|4
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL_D7
value|5
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL1_D2
value|6
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL1_D4
value|7
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL1_D8
value|8
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL1_D16
value|9
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL2_D2
value|10
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL2_D4
value|11
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL2_D8
value|12
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL3_D2
value|13
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL3_D4
value|14
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL4_D2
value|15
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL4_D4
value|16
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL
value|17
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL_D2
value|18
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL_D3
value|19
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL_D5
value|20
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL_D7
value|21
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL_D26
value|22
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL_D52
value|23
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL_D108
value|24
end_define

begin_define
define|#
directive|define
name|CLK_TOP_USB_PHY48M
value|25
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL1_D2
value|26
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL1_D4
value|27
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL1_D8
value|28
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL2_D2
value|29
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL2_D4
value|30
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL2_D8
value|31
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL2_D16
value|32
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL2_D32
value|33
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL3_D2
value|34
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL3_D4
value|35
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL3_D8
value|36
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MSDCPLL
value|37
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MSDCPLL_D2
value|38
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MSDCPLL_D4
value|39
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MSDCPLL_D8
value|40
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MMPLL
value|41
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MMPLL_D2
value|42
end_define

begin_define
define|#
directive|define
name|CLK_TOP_DMPLL
value|43
end_define

begin_define
define|#
directive|define
name|CLK_TOP_DMPLL_D2
value|44
end_define

begin_define
define|#
directive|define
name|CLK_TOP_DMPLL_D4
value|45
end_define

begin_define
define|#
directive|define
name|CLK_TOP_DMPLL_X2
value|46
end_define

begin_define
define|#
directive|define
name|CLK_TOP_TVDPLL
value|47
end_define

begin_define
define|#
directive|define
name|CLK_TOP_TVDPLL_D2
value|48
end_define

begin_define
define|#
directive|define
name|CLK_TOP_TVDPLL_D4
value|49
end_define

begin_define
define|#
directive|define
name|CLK_TOP_TVD2PLL
value|50
end_define

begin_define
define|#
directive|define
name|CLK_TOP_TVD2PLL_D2
value|51
end_define

begin_define
define|#
directive|define
name|CLK_TOP_HADDS2PLL_98M
value|52
end_define

begin_define
define|#
directive|define
name|CLK_TOP_HADDS2PLL_294M
value|53
end_define

begin_define
define|#
directive|define
name|CLK_TOP_HADDS2_FB
value|54
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MIPIPLL_D2
value|55
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MIPIPLL_D4
value|56
end_define

begin_define
define|#
directive|define
name|CLK_TOP_HDMIPLL
value|57
end_define

begin_define
define|#
directive|define
name|CLK_TOP_HDMIPLL_D2
value|58
end_define

begin_define
define|#
directive|define
name|CLK_TOP_HDMIPLL_D3
value|59
end_define

begin_define
define|#
directive|define
name|CLK_TOP_HDMI_SCL_RX
value|60
end_define

begin_define
define|#
directive|define
name|CLK_TOP_HDMI_0_PIX340M
value|61
end_define

begin_define
define|#
directive|define
name|CLK_TOP_HDMI_0_DEEP340M
value|62
end_define

begin_define
define|#
directive|define
name|CLK_TOP_HDMI_0_PLL340M
value|63
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUD1PLL_98M
value|64
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUD2PLL_90M
value|65
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUDPLL
value|66
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUDPLL_D4
value|67
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUDPLL_D8
value|68
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUDPLL_D16
value|69
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUDPLL_D24
value|70
end_define

begin_define
define|#
directive|define
name|CLK_TOP_ETHPLL_500M
value|71
end_define

begin_define
define|#
directive|define
name|CLK_TOP_VDECPLL
value|72
end_define

begin_define
define|#
directive|define
name|CLK_TOP_VENCPLL
value|73
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MIPIPLL
value|74
end_define

begin_define
define|#
directive|define
name|CLK_TOP_ARMPLL_1P3G
value|75
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MM_SEL
value|76
end_define

begin_define
define|#
directive|define
name|CLK_TOP_DDRPHYCFG_SEL
value|77
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MEM_SEL
value|78
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AXI_SEL
value|79
end_define

begin_define
define|#
directive|define
name|CLK_TOP_CAMTG_SEL
value|80
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MFG_SEL
value|81
end_define

begin_define
define|#
directive|define
name|CLK_TOP_VDEC_SEL
value|82
end_define

begin_define
define|#
directive|define
name|CLK_TOP_PWM_SEL
value|83
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MSDC30_0_SEL
value|84
end_define

begin_define
define|#
directive|define
name|CLK_TOP_USB20_SEL
value|85
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SPI0_SEL
value|86
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UART_SEL
value|87
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUDINTBUS_SEL
value|88
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUDIO_SEL
value|89
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MSDC30_2_SEL
value|90
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MSDC30_1_SEL
value|91
end_define

begin_define
define|#
directive|define
name|CLK_TOP_DPI1_SEL
value|92
end_define

begin_define
define|#
directive|define
name|CLK_TOP_DPI0_SEL
value|93
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SCP_SEL
value|94
end_define

begin_define
define|#
directive|define
name|CLK_TOP_PMICSPI_SEL
value|95
end_define

begin_define
define|#
directive|define
name|CLK_TOP_APLL_SEL
value|96
end_define

begin_define
define|#
directive|define
name|CLK_TOP_HDMI_SEL
value|97
end_define

begin_define
define|#
directive|define
name|CLK_TOP_TVE_SEL
value|98
end_define

begin_define
define|#
directive|define
name|CLK_TOP_EMMC_HCLK_SEL
value|99
end_define

begin_define
define|#
directive|define
name|CLK_TOP_NFI2X_SEL
value|100
end_define

begin_define
define|#
directive|define
name|CLK_TOP_RTC_SEL
value|101
end_define

begin_define
define|#
directive|define
name|CLK_TOP_OSD_SEL
value|102
end_define

begin_define
define|#
directive|define
name|CLK_TOP_NR_SEL
value|103
end_define

begin_define
define|#
directive|define
name|CLK_TOP_DI_SEL
value|104
end_define

begin_define
define|#
directive|define
name|CLK_TOP_FLASH_SEL
value|105
end_define

begin_define
define|#
directive|define
name|CLK_TOP_ASM_M_SEL
value|106
end_define

begin_define
define|#
directive|define
name|CLK_TOP_ASM_I_SEL
value|107
end_define

begin_define
define|#
directive|define
name|CLK_TOP_INTDIR_SEL
value|108
end_define

begin_define
define|#
directive|define
name|CLK_TOP_HDMIRX_BIST_SEL
value|109
end_define

begin_define
define|#
directive|define
name|CLK_TOP_ETHIF_SEL
value|110
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MS_CARD_SEL
value|111
end_define

begin_define
define|#
directive|define
name|CLK_TOP_ASM_H_SEL
value|112
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SPI1_SEL
value|113
end_define

begin_define
define|#
directive|define
name|CLK_TOP_CMSYS_SEL
value|114
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MSDC30_3_SEL
value|115
end_define

begin_define
define|#
directive|define
name|CLK_TOP_HDMIRX26_24_SEL
value|116
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUD2DVD_SEL
value|117
end_define

begin_define
define|#
directive|define
name|CLK_TOP_8BDAC_SEL
value|118
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SPI2_SEL
value|119
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUD_MUX1_SEL
value|120
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUD_MUX2_SEL
value|121
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUDPLL_MUX_SEL
value|122
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUD_K1_SRC_SEL
value|123
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUD_K2_SRC_SEL
value|124
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUD_K3_SRC_SEL
value|125
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUD_K4_SRC_SEL
value|126
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUD_K5_SRC_SEL
value|127
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUD_K6_SRC_SEL
value|128
end_define

begin_define
define|#
directive|define
name|CLK_TOP_PADMCLK_SEL
value|129
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUD_EXTCK1_DIV
value|130
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUD_EXTCK2_DIV
value|131
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUD_MUX1_DIV
value|132
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUD_MUX2_DIV
value|133
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUD_K1_SRC_DIV
value|134
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUD_K2_SRC_DIV
value|135
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUD_K3_SRC_DIV
value|136
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUD_K4_SRC_DIV
value|137
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUD_K5_SRC_DIV
value|138
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUD_K6_SRC_DIV
value|139
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUD_I2S1_MCLK
value|140
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUD_I2S2_MCLK
value|141
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUD_I2S3_MCLK
value|142
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUD_I2S4_MCLK
value|143
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUD_I2S5_MCLK
value|144
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUD_I2S6_MCLK
value|145
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUD_48K_TIMING
value|146
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUD_44K_TIMING
value|147
end_define

begin_define
define|#
directive|define
name|CLK_TOP_32K_INTERNAL
value|148
end_define

begin_define
define|#
directive|define
name|CLK_TOP_32K_EXTERNAL
value|149
end_define

begin_define
define|#
directive|define
name|CLK_TOP_CLK26M_D8
value|150
end_define

begin_define
define|#
directive|define
name|CLK_TOP_8BDAC
value|151
end_define

begin_define
define|#
directive|define
name|CLK_TOP_WBG_DIG_416M
value|152
end_define

begin_define
define|#
directive|define
name|CLK_TOP_DPI
value|153
end_define

begin_define
define|#
directive|define
name|CLK_TOP_HDMITX_CLKDIG_CTS
value|154
end_define

begin_define
define|#
directive|define
name|CLK_TOP_DSI0_LNTC_DSI
value|155
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUD_EXT1
value|156
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUD_EXT2
value|157
end_define

begin_define
define|#
directive|define
name|CLK_TOP_NFI1X_PAD
value|158
end_define

begin_define
define|#
directive|define
name|CLK_TOP_NR
value|159
end_define

begin_comment
comment|/* APMIXEDSYS */
end_comment

begin_define
define|#
directive|define
name|CLK_APMIXED_ARMPLL
value|1
end_define

begin_define
define|#
directive|define
name|CLK_APMIXED_MAINPLL
value|2
end_define

begin_define
define|#
directive|define
name|CLK_APMIXED_UNIVPLL
value|3
end_define

begin_define
define|#
directive|define
name|CLK_APMIXED_MMPLL
value|4
end_define

begin_define
define|#
directive|define
name|CLK_APMIXED_MSDCPLL
value|5
end_define

begin_define
define|#
directive|define
name|CLK_APMIXED_TVDPLL
value|6
end_define

begin_define
define|#
directive|define
name|CLK_APMIXED_AUD1PLL
value|7
end_define

begin_define
define|#
directive|define
name|CLK_APMIXED_TRGPLL
value|8
end_define

begin_define
define|#
directive|define
name|CLK_APMIXED_ETHPLL
value|9
end_define

begin_define
define|#
directive|define
name|CLK_APMIXED_VDECPLL
value|10
end_define

begin_define
define|#
directive|define
name|CLK_APMIXED_HADDS2PLL
value|11
end_define

begin_define
define|#
directive|define
name|CLK_APMIXED_AUD2PLL
value|12
end_define

begin_define
define|#
directive|define
name|CLK_APMIXED_TVD2PLL
value|13
end_define

begin_define
define|#
directive|define
name|CLK_APMIXED_NR
value|14
end_define

begin_comment
comment|/* DDRPHY */
end_comment

begin_define
define|#
directive|define
name|CLK_DDRPHY_VENCPLL
value|1
end_define

begin_define
define|#
directive|define
name|CLK_DDRPHY_NR
value|2
end_define

begin_comment
comment|/* INFRACFG */
end_comment

begin_define
define|#
directive|define
name|CLK_INFRA_DBG
value|1
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_SMI
value|2
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_QAXI_CM4
value|3
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_AUD_SPLIN_B
value|4
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_AUDIO
value|5
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_EFUSE
value|6
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_L2C_SRAM
value|7
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_M4U
value|8
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_CONNMCU
value|9
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_TRNG
value|10
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_RAMBUFIF
value|11
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_CPUM
value|12
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_KP
value|13
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_CEC
value|14
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_IRRX
value|15
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_PMICSPI
value|16
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_PMICWRAP
value|17
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_DDCCI
value|18
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_CLK_13M
value|19
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_CPUSEL
value|20
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_NR
value|21
end_define

begin_comment
comment|/* PERICFG */
end_comment

begin_define
define|#
directive|define
name|CLK_PERI_NFI
value|1
end_define

begin_define
define|#
directive|define
name|CLK_PERI_THERM
value|2
end_define

begin_define
define|#
directive|define
name|CLK_PERI_PWM1
value|3
end_define

begin_define
define|#
directive|define
name|CLK_PERI_PWM2
value|4
end_define

begin_define
define|#
directive|define
name|CLK_PERI_PWM3
value|5
end_define

begin_define
define|#
directive|define
name|CLK_PERI_PWM4
value|6
end_define

begin_define
define|#
directive|define
name|CLK_PERI_PWM5
value|7
end_define

begin_define
define|#
directive|define
name|CLK_PERI_PWM6
value|8
end_define

begin_define
define|#
directive|define
name|CLK_PERI_PWM7
value|9
end_define

begin_define
define|#
directive|define
name|CLK_PERI_PWM
value|10
end_define

begin_define
define|#
directive|define
name|CLK_PERI_USB0
value|11
end_define

begin_define
define|#
directive|define
name|CLK_PERI_USB1
value|12
end_define

begin_define
define|#
directive|define
name|CLK_PERI_AP_DMA
value|13
end_define

begin_define
define|#
directive|define
name|CLK_PERI_MSDC30_0
value|14
end_define

begin_define
define|#
directive|define
name|CLK_PERI_MSDC30_1
value|15
end_define

begin_define
define|#
directive|define
name|CLK_PERI_MSDC30_2
value|16
end_define

begin_define
define|#
directive|define
name|CLK_PERI_MSDC30_3
value|17
end_define

begin_define
define|#
directive|define
name|CLK_PERI_MSDC50_3
value|18
end_define

begin_define
define|#
directive|define
name|CLK_PERI_NLI
value|19
end_define

begin_define
define|#
directive|define
name|CLK_PERI_UART0
value|20
end_define

begin_define
define|#
directive|define
name|CLK_PERI_UART1
value|21
end_define

begin_define
define|#
directive|define
name|CLK_PERI_UART2
value|22
end_define

begin_define
define|#
directive|define
name|CLK_PERI_UART3
value|23
end_define

begin_define
define|#
directive|define
name|CLK_PERI_BTIF
value|24
end_define

begin_define
define|#
directive|define
name|CLK_PERI_I2C0
value|25
end_define

begin_define
define|#
directive|define
name|CLK_PERI_I2C1
value|26
end_define

begin_define
define|#
directive|define
name|CLK_PERI_I2C2
value|27
end_define

begin_define
define|#
directive|define
name|CLK_PERI_I2C3
value|28
end_define

begin_define
define|#
directive|define
name|CLK_PERI_AUXADC
value|29
end_define

begin_define
define|#
directive|define
name|CLK_PERI_SPI0
value|30
end_define

begin_define
define|#
directive|define
name|CLK_PERI_ETH
value|31
end_define

begin_define
define|#
directive|define
name|CLK_PERI_USB0_MCU
value|32
end_define

begin_define
define|#
directive|define
name|CLK_PERI_USB1_MCU
value|33
end_define

begin_define
define|#
directive|define
name|CLK_PERI_USB_SLV
value|34
end_define

begin_define
define|#
directive|define
name|CLK_PERI_GCPU
value|35
end_define

begin_define
define|#
directive|define
name|CLK_PERI_NFI_ECC
value|36
end_define

begin_define
define|#
directive|define
name|CLK_PERI_NFI_PAD
value|37
end_define

begin_define
define|#
directive|define
name|CLK_PERI_FLASH
value|38
end_define

begin_define
define|#
directive|define
name|CLK_PERI_HOST89_INT
value|39
end_define

begin_define
define|#
directive|define
name|CLK_PERI_HOST89_SPI
value|40
end_define

begin_define
define|#
directive|define
name|CLK_PERI_HOST89_DVD
value|41
end_define

begin_define
define|#
directive|define
name|CLK_PERI_SPI1
value|42
end_define

begin_define
define|#
directive|define
name|CLK_PERI_SPI2
value|43
end_define

begin_define
define|#
directive|define
name|CLK_PERI_FCI
value|44
end_define

begin_define
define|#
directive|define
name|CLK_PERI_UART0_SEL
value|45
end_define

begin_define
define|#
directive|define
name|CLK_PERI_UART1_SEL
value|46
end_define

begin_define
define|#
directive|define
name|CLK_PERI_UART2_SEL
value|47
end_define

begin_define
define|#
directive|define
name|CLK_PERI_UART3_SEL
value|48
end_define

begin_define
define|#
directive|define
name|CLK_PERI_NR
value|49
end_define

begin_comment
comment|/* AUDIO */
end_comment

begin_define
define|#
directive|define
name|CLK_AUD_AFE
value|1
end_define

begin_define
define|#
directive|define
name|CLK_AUD_LRCK_DETECT
value|2
end_define

begin_define
define|#
directive|define
name|CLK_AUD_I2S
value|3
end_define

begin_define
define|#
directive|define
name|CLK_AUD_APLL_TUNER
value|4
end_define

begin_define
define|#
directive|define
name|CLK_AUD_HDMI
value|5
end_define

begin_define
define|#
directive|define
name|CLK_AUD_SPDF
value|6
end_define

begin_define
define|#
directive|define
name|CLK_AUD_SPDF2
value|7
end_define

begin_define
define|#
directive|define
name|CLK_AUD_APLL
value|8
end_define

begin_define
define|#
directive|define
name|CLK_AUD_TML
value|9
end_define

begin_define
define|#
directive|define
name|CLK_AUD_AHB_IDLE_EXT
value|10
end_define

begin_define
define|#
directive|define
name|CLK_AUD_AHB_IDLE_INT
value|11
end_define

begin_define
define|#
directive|define
name|CLK_AUD_I2SIN1
value|12
end_define

begin_define
define|#
directive|define
name|CLK_AUD_I2SIN2
value|13
end_define

begin_define
define|#
directive|define
name|CLK_AUD_I2SIN3
value|14
end_define

begin_define
define|#
directive|define
name|CLK_AUD_I2SIN4
value|15
end_define

begin_define
define|#
directive|define
name|CLK_AUD_I2SIN5
value|16
end_define

begin_define
define|#
directive|define
name|CLK_AUD_I2SIN6
value|17
end_define

begin_define
define|#
directive|define
name|CLK_AUD_I2SO1
value|18
end_define

begin_define
define|#
directive|define
name|CLK_AUD_I2SO2
value|19
end_define

begin_define
define|#
directive|define
name|CLK_AUD_I2SO3
value|20
end_define

begin_define
define|#
directive|define
name|CLK_AUD_I2SO4
value|21
end_define

begin_define
define|#
directive|define
name|CLK_AUD_I2SO5
value|22
end_define

begin_define
define|#
directive|define
name|CLK_AUD_I2SO6
value|23
end_define

begin_define
define|#
directive|define
name|CLK_AUD_ASRCI1
value|24
end_define

begin_define
define|#
directive|define
name|CLK_AUD_ASRCI2
value|25
end_define

begin_define
define|#
directive|define
name|CLK_AUD_ASRCO1
value|26
end_define

begin_define
define|#
directive|define
name|CLK_AUD_ASRCO2
value|27
end_define

begin_define
define|#
directive|define
name|CLK_AUD_ASRC11
value|28
end_define

begin_define
define|#
directive|define
name|CLK_AUD_ASRC12
value|29
end_define

begin_define
define|#
directive|define
name|CLK_AUD_HDMIRX
value|30
end_define

begin_define
define|#
directive|define
name|CLK_AUD_INTDIR
value|31
end_define

begin_define
define|#
directive|define
name|CLK_AUD_A1SYS
value|32
end_define

begin_define
define|#
directive|define
name|CLK_AUD_A2SYS
value|33
end_define

begin_define
define|#
directive|define
name|CLK_AUD_AFE_CONN
value|34
end_define

begin_define
define|#
directive|define
name|CLK_AUD_AFE_PCMIF
value|35
end_define

begin_define
define|#
directive|define
name|CLK_AUD_AFE_MRGIF
value|36
end_define

begin_define
define|#
directive|define
name|CLK_AUD_MMIF_UL1
value|37
end_define

begin_define
define|#
directive|define
name|CLK_AUD_MMIF_UL2
value|38
end_define

begin_define
define|#
directive|define
name|CLK_AUD_MMIF_UL3
value|39
end_define

begin_define
define|#
directive|define
name|CLK_AUD_MMIF_UL4
value|40
end_define

begin_define
define|#
directive|define
name|CLK_AUD_MMIF_UL5
value|41
end_define

begin_define
define|#
directive|define
name|CLK_AUD_MMIF_UL6
value|42
end_define

begin_define
define|#
directive|define
name|CLK_AUD_MMIF_DL1
value|43
end_define

begin_define
define|#
directive|define
name|CLK_AUD_MMIF_DL2
value|44
end_define

begin_define
define|#
directive|define
name|CLK_AUD_MMIF_DL3
value|45
end_define

begin_define
define|#
directive|define
name|CLK_AUD_MMIF_DL4
value|46
end_define

begin_define
define|#
directive|define
name|CLK_AUD_MMIF_DL5
value|47
end_define

begin_define
define|#
directive|define
name|CLK_AUD_MMIF_DL6
value|48
end_define

begin_define
define|#
directive|define
name|CLK_AUD_MMIF_DLMCH
value|49
end_define

begin_define
define|#
directive|define
name|CLK_AUD_MMIF_ARB1
value|50
end_define

begin_define
define|#
directive|define
name|CLK_AUD_MMIF_AWB1
value|51
end_define

begin_define
define|#
directive|define
name|CLK_AUD_MMIF_AWB2
value|52
end_define

begin_define
define|#
directive|define
name|CLK_AUD_MMIF_DAI
value|53
end_define

begin_define
define|#
directive|define
name|CLK_AUD_DMIC1
value|54
end_define

begin_define
define|#
directive|define
name|CLK_AUD_DMIC2
value|55
end_define

begin_define
define|#
directive|define
name|CLK_AUD_ASRCI3
value|56
end_define

begin_define
define|#
directive|define
name|CLK_AUD_ASRCI4
value|57
end_define

begin_define
define|#
directive|define
name|CLK_AUD_ASRCI5
value|58
end_define

begin_define
define|#
directive|define
name|CLK_AUD_ASRCI6
value|59
end_define

begin_define
define|#
directive|define
name|CLK_AUD_ASRCO3
value|60
end_define

begin_define
define|#
directive|define
name|CLK_AUD_ASRCO4
value|61
end_define

begin_define
define|#
directive|define
name|CLK_AUD_ASRCO5
value|62
end_define

begin_define
define|#
directive|define
name|CLK_AUD_ASRCO6
value|63
end_define

begin_define
define|#
directive|define
name|CLK_AUD_MEM_ASRC1
value|64
end_define

begin_define
define|#
directive|define
name|CLK_AUD_MEM_ASRC2
value|65
end_define

begin_define
define|#
directive|define
name|CLK_AUD_MEM_ASRC3
value|66
end_define

begin_define
define|#
directive|define
name|CLK_AUD_MEM_ASRC4
value|67
end_define

begin_define
define|#
directive|define
name|CLK_AUD_MEM_ASRC5
value|68
end_define

begin_define
define|#
directive|define
name|CLK_AUD_DSD_ENC
value|69
end_define

begin_define
define|#
directive|define
name|CLK_AUD_ASRC_BRG
value|70
end_define

begin_define
define|#
directive|define
name|CLK_AUD_NR
value|71
end_define

begin_comment
comment|/* MMSYS */
end_comment

begin_define
define|#
directive|define
name|CLK_MM_SMI_COMMON
value|1
end_define

begin_define
define|#
directive|define
name|CLK_MM_SMI_LARB0
value|2
end_define

begin_define
define|#
directive|define
name|CLK_MM_CMDQ
value|3
end_define

begin_define
define|#
directive|define
name|CLK_MM_MUTEX
value|4
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_COLOR
value|5
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_BLS
value|6
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_WDMA
value|7
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_RDMA
value|8
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_OVL
value|9
end_define

begin_define
define|#
directive|define
name|CLK_MM_MDP_TDSHP
value|10
end_define

begin_define
define|#
directive|define
name|CLK_MM_MDP_WROT
value|11
end_define

begin_define
define|#
directive|define
name|CLK_MM_MDP_WDMA
value|12
end_define

begin_define
define|#
directive|define
name|CLK_MM_MDP_RSZ1
value|13
end_define

begin_define
define|#
directive|define
name|CLK_MM_MDP_RSZ0
value|14
end_define

begin_define
define|#
directive|define
name|CLK_MM_MDP_RDMA
value|15
end_define

begin_define
define|#
directive|define
name|CLK_MM_MDP_BLS_26M
value|16
end_define

begin_define
define|#
directive|define
name|CLK_MM_CAM_MDP
value|17
end_define

begin_define
define|#
directive|define
name|CLK_MM_FAKE_ENG
value|18
end_define

begin_define
define|#
directive|define
name|CLK_MM_MUTEX_32K
value|19
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_RDMA1
value|20
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_UFOE
value|21
end_define

begin_define
define|#
directive|define
name|CLK_MM_DSI_ENGINE
value|22
end_define

begin_define
define|#
directive|define
name|CLK_MM_DSI_DIG
value|23
end_define

begin_define
define|#
directive|define
name|CLK_MM_DPI_DIGL
value|24
end_define

begin_define
define|#
directive|define
name|CLK_MM_DPI_ENGINE
value|25
end_define

begin_define
define|#
directive|define
name|CLK_MM_DPI1_DIGL
value|26
end_define

begin_define
define|#
directive|define
name|CLK_MM_DPI1_ENGINE
value|27
end_define

begin_define
define|#
directive|define
name|CLK_MM_TVE_OUTPUT
value|28
end_define

begin_define
define|#
directive|define
name|CLK_MM_TVE_INPUT
value|29
end_define

begin_define
define|#
directive|define
name|CLK_MM_HDMI_PIXEL
value|30
end_define

begin_define
define|#
directive|define
name|CLK_MM_HDMI_PLL
value|31
end_define

begin_define
define|#
directive|define
name|CLK_MM_HDMI_AUDIO
value|32
end_define

begin_define
define|#
directive|define
name|CLK_MM_HDMI_SPDIF
value|33
end_define

begin_define
define|#
directive|define
name|CLK_MM_TVE_FMM
value|34
end_define

begin_define
define|#
directive|define
name|CLK_MM_NR
value|35
end_define

begin_comment
comment|/* IMGSYS */
end_comment

begin_define
define|#
directive|define
name|CLK_IMG_SMI_COMM
value|1
end_define

begin_define
define|#
directive|define
name|CLK_IMG_RESZ
value|2
end_define

begin_define
define|#
directive|define
name|CLK_IMG_JPGDEC_SMI
value|3
end_define

begin_define
define|#
directive|define
name|CLK_IMG_JPGDEC
value|4
end_define

begin_define
define|#
directive|define
name|CLK_IMG_VENC_LT
value|5
end_define

begin_define
define|#
directive|define
name|CLK_IMG_VENC
value|6
end_define

begin_define
define|#
directive|define
name|CLK_IMG_NR
value|7
end_define

begin_comment
comment|/* VDEC */
end_comment

begin_define
define|#
directive|define
name|CLK_VDEC_CKGEN
value|1
end_define

begin_define
define|#
directive|define
name|CLK_VDEC_LARB
value|2
end_define

begin_define
define|#
directive|define
name|CLK_VDEC_NR
value|3
end_define

begin_comment
comment|/* HIFSYS */
end_comment

begin_define
define|#
directive|define
name|CLK_HIFSYS_USB0PHY
value|1
end_define

begin_define
define|#
directive|define
name|CLK_HIFSYS_USB1PHY
value|2
end_define

begin_define
define|#
directive|define
name|CLK_HIFSYS_PCIE0
value|3
end_define

begin_define
define|#
directive|define
name|CLK_HIFSYS_PCIE1
value|4
end_define

begin_define
define|#
directive|define
name|CLK_HIFSYS_PCIE2
value|5
end_define

begin_define
define|#
directive|define
name|CLK_HIFSYS_NR
value|6
end_define

begin_comment
comment|/* ETHSYS */
end_comment

begin_define
define|#
directive|define
name|CLK_ETHSYS_HSDMA
value|1
end_define

begin_define
define|#
directive|define
name|CLK_ETHSYS_ESW
value|2
end_define

begin_define
define|#
directive|define
name|CLK_ETHSYS_GP2
value|3
end_define

begin_define
define|#
directive|define
name|CLK_ETHSYS_GP1
value|4
end_define

begin_define
define|#
directive|define
name|CLK_ETHSYS_PCM
value|5
end_define

begin_define
define|#
directive|define
name|CLK_ETHSYS_GDMA
value|6
end_define

begin_define
define|#
directive|define
name|CLK_ETHSYS_I2S
value|7
end_define

begin_define
define|#
directive|define
name|CLK_ETHSYS_CRYPTO
value|8
end_define

begin_define
define|#
directive|define
name|CLK_ETHSYS_NR
value|9
end_define

begin_comment
comment|/* BDP */
end_comment

begin_define
define|#
directive|define
name|CLK_BDP_BRG_BA
value|1
end_define

begin_define
define|#
directive|define
name|CLK_BDP_BRG_DRAM
value|2
end_define

begin_define
define|#
directive|define
name|CLK_BDP_LARB_DRAM
value|3
end_define

begin_define
define|#
directive|define
name|CLK_BDP_WR_VDI_PXL
value|4
end_define

begin_define
define|#
directive|define
name|CLK_BDP_WR_VDI_DRAM
value|5
end_define

begin_define
define|#
directive|define
name|CLK_BDP_WR_B
value|6
end_define

begin_define
define|#
directive|define
name|CLK_BDP_DGI_IN
value|7
end_define

begin_define
define|#
directive|define
name|CLK_BDP_DGI_OUT
value|8
end_define

begin_define
define|#
directive|define
name|CLK_BDP_FMT_MAST_27
value|9
end_define

begin_define
define|#
directive|define
name|CLK_BDP_FMT_B
value|10
end_define

begin_define
define|#
directive|define
name|CLK_BDP_OSD_B
value|11
end_define

begin_define
define|#
directive|define
name|CLK_BDP_OSD_DRAM
value|12
end_define

begin_define
define|#
directive|define
name|CLK_BDP_OSD_AGENT
value|13
end_define

begin_define
define|#
directive|define
name|CLK_BDP_OSD_PXL
value|14
end_define

begin_define
define|#
directive|define
name|CLK_BDP_RLE_B
value|15
end_define

begin_define
define|#
directive|define
name|CLK_BDP_RLE_AGENT
value|16
end_define

begin_define
define|#
directive|define
name|CLK_BDP_RLE_DRAM
value|17
end_define

begin_define
define|#
directive|define
name|CLK_BDP_F27M
value|18
end_define

begin_define
define|#
directive|define
name|CLK_BDP_F27M_VDOUT
value|19
end_define

begin_define
define|#
directive|define
name|CLK_BDP_F27_74_74
value|20
end_define

begin_define
define|#
directive|define
name|CLK_BDP_F2FS
value|21
end_define

begin_define
define|#
directive|define
name|CLK_BDP_F2FS74_148
value|22
end_define

begin_define
define|#
directive|define
name|CLK_BDP_FB
value|23
end_define

begin_define
define|#
directive|define
name|CLK_BDP_VDO_DRAM
value|24
end_define

begin_define
define|#
directive|define
name|CLK_BDP_VDO_2FS
value|25
end_define

begin_define
define|#
directive|define
name|CLK_BDP_VDO_B
value|26
end_define

begin_define
define|#
directive|define
name|CLK_BDP_WR_DI_PXL
value|27
end_define

begin_define
define|#
directive|define
name|CLK_BDP_WR_DI_DRAM
value|28
end_define

begin_define
define|#
directive|define
name|CLK_BDP_WR_DI_B
value|29
end_define

begin_define
define|#
directive|define
name|CLK_BDP_NR_PXL
value|30
end_define

begin_define
define|#
directive|define
name|CLK_BDP_NR_DRAM
value|31
end_define

begin_define
define|#
directive|define
name|CLK_BDP_NR_B
value|32
end_define

begin_define
define|#
directive|define
name|CLK_BDP_RX_F
value|33
end_define

begin_define
define|#
directive|define
name|CLK_BDP_RX_X
value|34
end_define

begin_define
define|#
directive|define
name|CLK_BDP_RXPDT
value|35
end_define

begin_define
define|#
directive|define
name|CLK_BDP_RX_CSCL_N
value|36
end_define

begin_define
define|#
directive|define
name|CLK_BDP_RX_CSCL
value|37
end_define

begin_define
define|#
directive|define
name|CLK_BDP_RX_DDCSCL_N
value|38
end_define

begin_define
define|#
directive|define
name|CLK_BDP_RX_DDCSCL
value|39
end_define

begin_define
define|#
directive|define
name|CLK_BDP_RX_VCO
value|40
end_define

begin_define
define|#
directive|define
name|CLK_BDP_RX_DP
value|41
end_define

begin_define
define|#
directive|define
name|CLK_BDP_RX_P
value|42
end_define

begin_define
define|#
directive|define
name|CLK_BDP_RX_M
value|43
end_define

begin_define
define|#
directive|define
name|CLK_BDP_RX_PLL
value|44
end_define

begin_define
define|#
directive|define
name|CLK_BDP_BRG_RT_B
value|45
end_define

begin_define
define|#
directive|define
name|CLK_BDP_BRG_RT_DRAM
value|46
end_define

begin_define
define|#
directive|define
name|CLK_BDP_LARBRT_DRAM
value|47
end_define

begin_define
define|#
directive|define
name|CLK_BDP_TMDS_SYN
value|48
end_define

begin_define
define|#
directive|define
name|CLK_BDP_HDMI_MON
value|49
end_define

begin_define
define|#
directive|define
name|CLK_BDP_NR
value|50
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_CLK_MT2701_H */
end_comment

end_unit

