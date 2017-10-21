begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2014 MediaTek Inc.  * Author: James Liao<jamesjj.liao@mediatek.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLK_MT8173_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLK_MT8173_H
end_define

begin_comment
comment|/* TOPCKGEN */
end_comment

begin_define
define|#
directive|define
name|CLK_TOP_CLKPH_MCK_O
value|1
end_define

begin_define
define|#
directive|define
name|CLK_TOP_USB_SYSPLL_125M
value|3
end_define

begin_define
define|#
directive|define
name|CLK_TOP_HDMITX_DIG_CTS
value|4
end_define

begin_define
define|#
directive|define
name|CLK_TOP_ARMCA7PLL_754M
value|5
end_define

begin_define
define|#
directive|define
name|CLK_TOP_ARMCA7PLL_502M
value|6
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MAIN_H546M
value|7
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MAIN_H364M
value|8
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MAIN_H218P4M
value|9
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MAIN_H156M
value|10
end_define

begin_define
define|#
directive|define
name|CLK_TOP_TVDPLL_445P5M
value|11
end_define

begin_define
define|#
directive|define
name|CLK_TOP_TVDPLL_594M
value|12
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIV_624M
value|13
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIV_416M
value|14
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIV_249P6M
value|15
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIV_178P3M
value|16
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIV_48M
value|17
end_define

begin_define
define|#
directive|define
name|CLK_TOP_CLKRTC_EXT
value|18
end_define

begin_define
define|#
directive|define
name|CLK_TOP_CLKRTC_INT
value|19
end_define

begin_define
define|#
directive|define
name|CLK_TOP_FPC
value|20
end_define

begin_define
define|#
directive|define
name|CLK_TOP_HDMITXPLL_D2
value|21
end_define

begin_define
define|#
directive|define
name|CLK_TOP_HDMITXPLL_D3
value|22
end_define

begin_define
define|#
directive|define
name|CLK_TOP_ARMCA7PLL_D2
value|23
end_define

begin_define
define|#
directive|define
name|CLK_TOP_ARMCA7PLL_D3
value|24
end_define

begin_define
define|#
directive|define
name|CLK_TOP_APLL1
value|25
end_define

begin_define
define|#
directive|define
name|CLK_TOP_APLL2
value|26
end_define

begin_define
define|#
directive|define
name|CLK_TOP_DMPLL
value|27
end_define

begin_define
define|#
directive|define
name|CLK_TOP_DMPLL_D2
value|28
end_define

begin_define
define|#
directive|define
name|CLK_TOP_DMPLL_D4
value|29
end_define

begin_define
define|#
directive|define
name|CLK_TOP_DMPLL_D8
value|30
end_define

begin_define
define|#
directive|define
name|CLK_TOP_DMPLL_D16
value|31
end_define

begin_define
define|#
directive|define
name|CLK_TOP_LVDSPLL_D2
value|32
end_define

begin_define
define|#
directive|define
name|CLK_TOP_LVDSPLL_D4
value|33
end_define

begin_define
define|#
directive|define
name|CLK_TOP_LVDSPLL_D8
value|34
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MMPLL
value|35
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MMPLL_D2
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
name|CLK_TOP_MSDCPLL2
value|40
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MSDCPLL2_D2
value|41
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MSDCPLL2_D4
value|42
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL_D2
value|43
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL1_D2
value|44
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL1_D4
value|45
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL1_D8
value|46
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL1_D16
value|47
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL_D3
value|48
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL2_D2
value|49
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL2_D4
value|50
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL_D5
value|51
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL3_D2
value|52
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL3_D4
value|53
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL_D7
value|54
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL4_D2
value|55
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL4_D4
value|56
end_define

begin_define
define|#
directive|define
name|CLK_TOP_TVDPLL
value|57
end_define

begin_define
define|#
directive|define
name|CLK_TOP_TVDPLL_D2
value|58
end_define

begin_define
define|#
directive|define
name|CLK_TOP_TVDPLL_D4
value|59
end_define

begin_define
define|#
directive|define
name|CLK_TOP_TVDPLL_D8
value|60
end_define

begin_define
define|#
directive|define
name|CLK_TOP_TVDPLL_D16
value|61
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL_D2
value|62
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL1_D2
value|63
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL1_D4
value|64
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL1_D8
value|65
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL_D3
value|66
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL2_D2
value|67
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL2_D4
value|68
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL2_D8
value|69
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL_D5
value|70
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL3_D2
value|71
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL3_D4
value|72
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL3_D8
value|73
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL_D7
value|74
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL_D26
value|75
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL_D52
value|76
end_define

begin_define
define|#
directive|define
name|CLK_TOP_VCODECPLL
value|77
end_define

begin_define
define|#
directive|define
name|CLK_TOP_VCODECPLL_370P5
value|78
end_define

begin_define
define|#
directive|define
name|CLK_TOP_VENCPLL
value|79
end_define

begin_define
define|#
directive|define
name|CLK_TOP_VENCPLL_D2
value|80
end_define

begin_define
define|#
directive|define
name|CLK_TOP_VENCPLL_D4
value|81
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AXI_SEL
value|82
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MEM_SEL
value|83
end_define

begin_define
define|#
directive|define
name|CLK_TOP_DDRPHYCFG_SEL
value|84
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MM_SEL
value|85
end_define

begin_define
define|#
directive|define
name|CLK_TOP_PWM_SEL
value|86
end_define

begin_define
define|#
directive|define
name|CLK_TOP_VDEC_SEL
value|87
end_define

begin_define
define|#
directive|define
name|CLK_TOP_VENC_SEL
value|88
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MFG_SEL
value|89
end_define

begin_define
define|#
directive|define
name|CLK_TOP_CAMTG_SEL
value|90
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UART_SEL
value|91
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SPI_SEL
value|92
end_define

begin_define
define|#
directive|define
name|CLK_TOP_USB20_SEL
value|93
end_define

begin_define
define|#
directive|define
name|CLK_TOP_USB30_SEL
value|94
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MSDC50_0_H_SEL
value|95
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MSDC50_0_SEL
value|96
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MSDC30_1_SEL
value|97
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MSDC30_2_SEL
value|98
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MSDC30_3_SEL
value|99
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUDIO_SEL
value|100
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUD_INTBUS_SEL
value|101
end_define

begin_define
define|#
directive|define
name|CLK_TOP_PMICSPI_SEL
value|102
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SCP_SEL
value|103
end_define

begin_define
define|#
directive|define
name|CLK_TOP_ATB_SEL
value|104
end_define

begin_define
define|#
directive|define
name|CLK_TOP_VENC_LT_SEL
value|105
end_define

begin_define
define|#
directive|define
name|CLK_TOP_DPI0_SEL
value|106
end_define

begin_define
define|#
directive|define
name|CLK_TOP_IRDA_SEL
value|107
end_define

begin_define
define|#
directive|define
name|CLK_TOP_CCI400_SEL
value|108
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUD_1_SEL
value|109
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUD_2_SEL
value|110
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MEM_MFG_IN_SEL
value|111
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AXI_MFG_IN_SEL
value|112
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SCAM_SEL
value|113
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SPINFI_IFR_SEL
value|114
end_define

begin_define
define|#
directive|define
name|CLK_TOP_HDMI_SEL
value|115
end_define

begin_define
define|#
directive|define
name|CLK_TOP_DPILVDS_SEL
value|116
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MSDC50_2_H_SEL
value|117
end_define

begin_define
define|#
directive|define
name|CLK_TOP_HDCP_SEL
value|118
end_define

begin_define
define|#
directive|define
name|CLK_TOP_HDCP_24M_SEL
value|119
end_define

begin_define
define|#
directive|define
name|CLK_TOP_RTC_SEL
value|120
end_define

begin_define
define|#
directive|define
name|CLK_TOP_APLL1_DIV0
value|121
end_define

begin_define
define|#
directive|define
name|CLK_TOP_APLL1_DIV1
value|122
end_define

begin_define
define|#
directive|define
name|CLK_TOP_APLL1_DIV2
value|123
end_define

begin_define
define|#
directive|define
name|CLK_TOP_APLL1_DIV3
value|124
end_define

begin_define
define|#
directive|define
name|CLK_TOP_APLL1_DIV4
value|125
end_define

begin_define
define|#
directive|define
name|CLK_TOP_APLL1_DIV5
value|126
end_define

begin_define
define|#
directive|define
name|CLK_TOP_APLL2_DIV0
value|127
end_define

begin_define
define|#
directive|define
name|CLK_TOP_APLL2_DIV1
value|128
end_define

begin_define
define|#
directive|define
name|CLK_TOP_APLL2_DIV2
value|129
end_define

begin_define
define|#
directive|define
name|CLK_TOP_APLL2_DIV3
value|130
end_define

begin_define
define|#
directive|define
name|CLK_TOP_APLL2_DIV4
value|131
end_define

begin_define
define|#
directive|define
name|CLK_TOP_APLL2_DIV5
value|132
end_define

begin_define
define|#
directive|define
name|CLK_TOP_I2S0_M_SEL
value|133
end_define

begin_define
define|#
directive|define
name|CLK_TOP_I2S1_M_SEL
value|134
end_define

begin_define
define|#
directive|define
name|CLK_TOP_I2S2_M_SEL
value|135
end_define

begin_define
define|#
directive|define
name|CLK_TOP_I2S3_M_SEL
value|136
end_define

begin_define
define|#
directive|define
name|CLK_TOP_I2S3_B_SEL
value|137
end_define

begin_define
define|#
directive|define
name|CLK_TOP_DSI0_DIG
value|138
end_define

begin_define
define|#
directive|define
name|CLK_TOP_DSI1_DIG
value|139
end_define

begin_define
define|#
directive|define
name|CLK_TOP_LVDS_PXL
value|140
end_define

begin_define
define|#
directive|define
name|CLK_TOP_LVDS_CTS
value|141
end_define

begin_define
define|#
directive|define
name|CLK_TOP_NR_CLK
value|142
end_define

begin_comment
comment|/* APMIXED_SYS */
end_comment

begin_define
define|#
directive|define
name|CLK_APMIXED_ARMCA15PLL
value|1
end_define

begin_define
define|#
directive|define
name|CLK_APMIXED_ARMCA7PLL
value|2
end_define

begin_define
define|#
directive|define
name|CLK_APMIXED_MAINPLL
value|3
end_define

begin_define
define|#
directive|define
name|CLK_APMIXED_UNIVPLL
value|4
end_define

begin_define
define|#
directive|define
name|CLK_APMIXED_MMPLL
value|5
end_define

begin_define
define|#
directive|define
name|CLK_APMIXED_MSDCPLL
value|6
end_define

begin_define
define|#
directive|define
name|CLK_APMIXED_VENCPLL
value|7
end_define

begin_define
define|#
directive|define
name|CLK_APMIXED_TVDPLL
value|8
end_define

begin_define
define|#
directive|define
name|CLK_APMIXED_MPLL
value|9
end_define

begin_define
define|#
directive|define
name|CLK_APMIXED_VCODECPLL
value|10
end_define

begin_define
define|#
directive|define
name|CLK_APMIXED_APLL1
value|11
end_define

begin_define
define|#
directive|define
name|CLK_APMIXED_APLL2
value|12
end_define

begin_define
define|#
directive|define
name|CLK_APMIXED_LVDSPLL
value|13
end_define

begin_define
define|#
directive|define
name|CLK_APMIXED_MSDCPLL2
value|14
end_define

begin_define
define|#
directive|define
name|CLK_APMIXED_REF2USB_TX
value|15
end_define

begin_define
define|#
directive|define
name|CLK_APMIXED_HDMI_REF
value|16
end_define

begin_define
define|#
directive|define
name|CLK_APMIXED_NR_CLK
value|17
end_define

begin_comment
comment|/* INFRA_SYS */
end_comment

begin_define
define|#
directive|define
name|CLK_INFRA_DBGCLK
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
name|CLK_INFRA_AUDIO
value|3
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_GCE
value|4
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_L2C_SRAM
value|5
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_M4U
value|6
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_CPUM
value|7
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_KP
value|8
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_CEC
value|9
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_PMICSPI
value|10
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_PMICWRAP
value|11
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_CLK_13M
value|12
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_CA53SEL
value|13
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_CA57SEL
value|14
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_NR_CLK
value|15
end_define

begin_comment
comment|/* PERI_SYS */
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
name|CLK_PERI_NLI_ARB
value|18
end_define

begin_define
define|#
directive|define
name|CLK_PERI_IRDA
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
name|CLK_PERI_I2C0
value|24
end_define

begin_define
define|#
directive|define
name|CLK_PERI_I2C1
value|25
end_define

begin_define
define|#
directive|define
name|CLK_PERI_I2C2
value|26
end_define

begin_define
define|#
directive|define
name|CLK_PERI_I2C3
value|27
end_define

begin_define
define|#
directive|define
name|CLK_PERI_I2C4
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
name|CLK_PERI_I2C5
value|31
end_define

begin_define
define|#
directive|define
name|CLK_PERI_NFIECC
value|32
end_define

begin_define
define|#
directive|define
name|CLK_PERI_SPI
value|33
end_define

begin_define
define|#
directive|define
name|CLK_PERI_IRRX
value|34
end_define

begin_define
define|#
directive|define
name|CLK_PERI_I2C6
value|35
end_define

begin_define
define|#
directive|define
name|CLK_PERI_UART0_SEL
value|36
end_define

begin_define
define|#
directive|define
name|CLK_PERI_UART1_SEL
value|37
end_define

begin_define
define|#
directive|define
name|CLK_PERI_UART2_SEL
value|38
end_define

begin_define
define|#
directive|define
name|CLK_PERI_UART3_SEL
value|39
end_define

begin_define
define|#
directive|define
name|CLK_PERI_NR_CLK
value|40
end_define

begin_comment
comment|/* IMG_SYS */
end_comment

begin_define
define|#
directive|define
name|CLK_IMG_LARB2_SMI
value|1
end_define

begin_define
define|#
directive|define
name|CLK_IMG_CAM_SMI
value|2
end_define

begin_define
define|#
directive|define
name|CLK_IMG_CAM_CAM
value|3
end_define

begin_define
define|#
directive|define
name|CLK_IMG_SEN_TG
value|4
end_define

begin_define
define|#
directive|define
name|CLK_IMG_SEN_CAM
value|5
end_define

begin_define
define|#
directive|define
name|CLK_IMG_CAM_SV
value|6
end_define

begin_define
define|#
directive|define
name|CLK_IMG_FD
value|7
end_define

begin_define
define|#
directive|define
name|CLK_IMG_NR_CLK
value|8
end_define

begin_comment
comment|/* MM_SYS */
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
name|CLK_MM_CAM_MDP
value|3
end_define

begin_define
define|#
directive|define
name|CLK_MM_MDP_RDMA0
value|4
end_define

begin_define
define|#
directive|define
name|CLK_MM_MDP_RDMA1
value|5
end_define

begin_define
define|#
directive|define
name|CLK_MM_MDP_RSZ0
value|6
end_define

begin_define
define|#
directive|define
name|CLK_MM_MDP_RSZ1
value|7
end_define

begin_define
define|#
directive|define
name|CLK_MM_MDP_RSZ2
value|8
end_define

begin_define
define|#
directive|define
name|CLK_MM_MDP_TDSHP0
value|9
end_define

begin_define
define|#
directive|define
name|CLK_MM_MDP_TDSHP1
value|10
end_define

begin_define
define|#
directive|define
name|CLK_MM_MDP_WDMA
value|11
end_define

begin_define
define|#
directive|define
name|CLK_MM_MDP_WROT0
value|12
end_define

begin_define
define|#
directive|define
name|CLK_MM_MDP_WROT1
value|13
end_define

begin_define
define|#
directive|define
name|CLK_MM_FAKE_ENG
value|14
end_define

begin_define
define|#
directive|define
name|CLK_MM_MUTEX_32K
value|15
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_OVL0
value|16
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_OVL1
value|17
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_RDMA0
value|18
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_RDMA1
value|19
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_RDMA2
value|20
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_WDMA0
value|21
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_WDMA1
value|22
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_COLOR0
value|23
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_COLOR1
value|24
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_AAL
value|25
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_GAMMA
value|26
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_UFOE
value|27
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_SPLIT0
value|28
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_SPLIT1
value|29
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_MERGE
value|30
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_OD
value|31
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_PWM0MM
value|32
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_PWM026M
value|33
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_PWM1MM
value|34
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_PWM126M
value|35
end_define

begin_define
define|#
directive|define
name|CLK_MM_DSI0_ENGINE
value|36
end_define

begin_define
define|#
directive|define
name|CLK_MM_DSI0_DIGITAL
value|37
end_define

begin_define
define|#
directive|define
name|CLK_MM_DSI1_ENGINE
value|38
end_define

begin_define
define|#
directive|define
name|CLK_MM_DSI1_DIGITAL
value|39
end_define

begin_define
define|#
directive|define
name|CLK_MM_DPI_PIXEL
value|40
end_define

begin_define
define|#
directive|define
name|CLK_MM_DPI_ENGINE
value|41
end_define

begin_define
define|#
directive|define
name|CLK_MM_DPI1_PIXEL
value|42
end_define

begin_define
define|#
directive|define
name|CLK_MM_DPI1_ENGINE
value|43
end_define

begin_define
define|#
directive|define
name|CLK_MM_HDMI_PIXEL
value|44
end_define

begin_define
define|#
directive|define
name|CLK_MM_HDMI_PLLCK
value|45
end_define

begin_define
define|#
directive|define
name|CLK_MM_HDMI_AUDIO
value|46
end_define

begin_define
define|#
directive|define
name|CLK_MM_HDMI_SPDIF
value|47
end_define

begin_define
define|#
directive|define
name|CLK_MM_LVDS_PIXEL
value|48
end_define

begin_define
define|#
directive|define
name|CLK_MM_LVDS_CTS
value|49
end_define

begin_define
define|#
directive|define
name|CLK_MM_SMI_LARB4
value|50
end_define

begin_define
define|#
directive|define
name|CLK_MM_HDMI_HDCP
value|51
end_define

begin_define
define|#
directive|define
name|CLK_MM_HDMI_HDCP24M
value|52
end_define

begin_define
define|#
directive|define
name|CLK_MM_NR_CLK
value|53
end_define

begin_comment
comment|/* VDEC_SYS */
end_comment

begin_define
define|#
directive|define
name|CLK_VDEC_CKEN
value|1
end_define

begin_define
define|#
directive|define
name|CLK_VDEC_LARB_CKEN
value|2
end_define

begin_define
define|#
directive|define
name|CLK_VDEC_NR_CLK
value|3
end_define

begin_comment
comment|/* VENC_SYS */
end_comment

begin_define
define|#
directive|define
name|CLK_VENC_CKE0
value|1
end_define

begin_define
define|#
directive|define
name|CLK_VENC_CKE1
value|2
end_define

begin_define
define|#
directive|define
name|CLK_VENC_CKE2
value|3
end_define

begin_define
define|#
directive|define
name|CLK_VENC_CKE3
value|4
end_define

begin_define
define|#
directive|define
name|CLK_VENC_NR_CLK
value|5
end_define

begin_comment
comment|/* VENCLT_SYS */
end_comment

begin_define
define|#
directive|define
name|CLK_VENCLT_CKE0
value|1
end_define

begin_define
define|#
directive|define
name|CLK_VENCLT_CKE1
value|2
end_define

begin_define
define|#
directive|define
name|CLK_VENCLT_NR_CLK
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_CLK_MT8173_H */
end_comment

end_unit

