begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2014 MediaTek Inc.  * Author: James Liao<jamesjj.liao@mediatek.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLK_MT8135_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLK_MT8135_H
end_define

begin_comment
comment|/* TOPCKGEN */
end_comment

begin_define
define|#
directive|define
name|CLK_TOP_DSI0_LNTC_DSICLK
value|1
end_define

begin_define
define|#
directive|define
name|CLK_TOP_HDMITX_CLKDIG_CTS
value|2
end_define

begin_define
define|#
directive|define
name|CLK_TOP_CLKPH_MCK
value|3
end_define

begin_define
define|#
directive|define
name|CLK_TOP_CPUM_TCK_IN
value|4
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MAINPLL_806M
value|5
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MAINPLL_537P3M
value|6
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MAINPLL_322P4M
value|7
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MAINPLL_230P3M
value|8
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL_624M
value|9
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL_416M
value|10
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL_249P6M
value|11
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL_178P3M
value|12
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL_48M
value|13
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MMPLL_D2
value|14
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MMPLL_D3
value|15
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MMPLL_D5
value|16
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MMPLL_D7
value|17
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MMPLL_D4
value|18
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MMPLL_D6
value|19
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL_D2
value|20
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL_D4
value|21
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL_D6
value|22
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL_D8
value|23
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL_D10
value|24
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL_D12
value|25
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL_D16
value|26
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL_D24
value|27
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL_D3
value|28
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL_D2P5
value|29
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL_D5
value|30
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL_D3P5
value|31
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL1_D2
value|32
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL1_D4
value|33
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL1_D6
value|34
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL1_D8
value|35
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL1_D10
value|36
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL2_D2
value|37
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL2_D4
value|38
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL2_D6
value|39
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL2_D8
value|40
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL_D3
value|41
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL_D5
value|42
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL_D7
value|43
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL_D10
value|44
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL_D26
value|45
end_define

begin_define
define|#
directive|define
name|CLK_TOP_APLL
value|46
end_define

begin_define
define|#
directive|define
name|CLK_TOP_APLL_D4
value|47
end_define

begin_define
define|#
directive|define
name|CLK_TOP_APLL_D8
value|48
end_define

begin_define
define|#
directive|define
name|CLK_TOP_APLL_D16
value|49
end_define

begin_define
define|#
directive|define
name|CLK_TOP_APLL_D24
value|50
end_define

begin_define
define|#
directive|define
name|CLK_TOP_LVDSPLL_D2
value|51
end_define

begin_define
define|#
directive|define
name|CLK_TOP_LVDSPLL_D4
value|52
end_define

begin_define
define|#
directive|define
name|CLK_TOP_LVDSPLL_D8
value|53
end_define

begin_define
define|#
directive|define
name|CLK_TOP_LVDSTX_CLKDIG_CT
value|54
end_define

begin_define
define|#
directive|define
name|CLK_TOP_VPLL_DPIX
value|55
end_define

begin_define
define|#
directive|define
name|CLK_TOP_TVHDMI_H
value|56
end_define

begin_define
define|#
directive|define
name|CLK_TOP_HDMITX_CLKDIG_D2
value|57
end_define

begin_define
define|#
directive|define
name|CLK_TOP_HDMITX_CLKDIG_D3
value|58
end_define

begin_define
define|#
directive|define
name|CLK_TOP_TVHDMI_D2
value|59
end_define

begin_define
define|#
directive|define
name|CLK_TOP_TVHDMI_D4
value|60
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MEMPLL_MCK_D4
value|61
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AXI_SEL
value|62
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SMI_SEL
value|63
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MFG_SEL
value|64
end_define

begin_define
define|#
directive|define
name|CLK_TOP_IRDA_SEL
value|65
end_define

begin_define
define|#
directive|define
name|CLK_TOP_CAM_SEL
value|66
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUD_INTBUS_SEL
value|67
end_define

begin_define
define|#
directive|define
name|CLK_TOP_JPG_SEL
value|68
end_define

begin_define
define|#
directive|define
name|CLK_TOP_DISP_SEL
value|69
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MSDC30_1_SEL
value|70
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MSDC30_2_SEL
value|71
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MSDC30_3_SEL
value|72
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MSDC30_4_SEL
value|73
end_define

begin_define
define|#
directive|define
name|CLK_TOP_USB20_SEL
value|74
end_define

begin_define
define|#
directive|define
name|CLK_TOP_VENC_SEL
value|75
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SPI_SEL
value|76
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UART_SEL
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
name|CLK_TOP_CAMTG_SEL
value|79
end_define

begin_define
define|#
directive|define
name|CLK_TOP_AUDIO_SEL
value|80
end_define

begin_define
define|#
directive|define
name|CLK_TOP_FIX_SEL
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
name|CLK_TOP_DDRPHYCFG_SEL
value|83
end_define

begin_define
define|#
directive|define
name|CLK_TOP_DPILVDS_SEL
value|84
end_define

begin_define
define|#
directive|define
name|CLK_TOP_PMICSPI_SEL
value|85
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MSDC30_0_SEL
value|86
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SMI_MFG_AS_SEL
value|87
end_define

begin_define
define|#
directive|define
name|CLK_TOP_GCPU_SEL
value|88
end_define

begin_define
define|#
directive|define
name|CLK_TOP_DPI1_SEL
value|89
end_define

begin_define
define|#
directive|define
name|CLK_TOP_CCI_SEL
value|90
end_define

begin_define
define|#
directive|define
name|CLK_TOP_APLL_SEL
value|91
end_define

begin_define
define|#
directive|define
name|CLK_TOP_HDMIPLL_SEL
value|92
end_define

begin_define
define|#
directive|define
name|CLK_TOP_NR_CLK
value|93
end_define

begin_comment
comment|/* APMIXED_SYS */
end_comment

begin_define
define|#
directive|define
name|CLK_APMIXED_ARMPLL1
value|1
end_define

begin_define
define|#
directive|define
name|CLK_APMIXED_ARMPLL2
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
name|CLK_APMIXED_TVDPLL
value|7
end_define

begin_define
define|#
directive|define
name|CLK_APMIXED_LVDSPLL
value|8
end_define

begin_define
define|#
directive|define
name|CLK_APMIXED_AUDPLL
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
name|CLK_APMIXED_NR_CLK
value|11
end_define

begin_comment
comment|/* INFRA_SYS */
end_comment

begin_define
define|#
directive|define
name|CLK_INFRA_PMIC_WRAP
value|1
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_PMICSPI
value|2
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_CCIF1_AP_CTRL
value|3
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_CCIF0_AP_CTRL
value|4
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_KP
value|5
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_CPUM
value|6
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_M4U
value|7
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_MFGAXI
value|8
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_DEVAPC
value|9
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_AUDIO
value|10
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_MFG_BUS
value|11
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_SMI
value|12
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_DBGCLK
value|13
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_NR_CLK
value|14
end_define

begin_comment
comment|/* PERI_SYS */
end_comment

begin_define
define|#
directive|define
name|CLK_PERI_I2C5
value|1
end_define

begin_define
define|#
directive|define
name|CLK_PERI_I2C4
value|2
end_define

begin_define
define|#
directive|define
name|CLK_PERI_I2C3
value|3
end_define

begin_define
define|#
directive|define
name|CLK_PERI_I2C2
value|4
end_define

begin_define
define|#
directive|define
name|CLK_PERI_I2C1
value|5
end_define

begin_define
define|#
directive|define
name|CLK_PERI_I2C0
value|6
end_define

begin_define
define|#
directive|define
name|CLK_PERI_UART3
value|7
end_define

begin_define
define|#
directive|define
name|CLK_PERI_UART2
value|8
end_define

begin_define
define|#
directive|define
name|CLK_PERI_UART1
value|9
end_define

begin_define
define|#
directive|define
name|CLK_PERI_UART0
value|10
end_define

begin_define
define|#
directive|define
name|CLK_PERI_IRDA
value|11
end_define

begin_define
define|#
directive|define
name|CLK_PERI_NLI
value|12
end_define

begin_define
define|#
directive|define
name|CLK_PERI_MD_HIF
value|13
end_define

begin_define
define|#
directive|define
name|CLK_PERI_AP_HIF
value|14
end_define

begin_define
define|#
directive|define
name|CLK_PERI_MSDC30_3
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
name|CLK_PERI_MSDC30_1
value|17
end_define

begin_define
define|#
directive|define
name|CLK_PERI_MSDC20_2
value|18
end_define

begin_define
define|#
directive|define
name|CLK_PERI_MSDC20_1
value|19
end_define

begin_define
define|#
directive|define
name|CLK_PERI_AP_DMA
value|20
end_define

begin_define
define|#
directive|define
name|CLK_PERI_USB1
value|21
end_define

begin_define
define|#
directive|define
name|CLK_PERI_USB0
value|22
end_define

begin_define
define|#
directive|define
name|CLK_PERI_PWM
value|23
end_define

begin_define
define|#
directive|define
name|CLK_PERI_PWM7
value|24
end_define

begin_define
define|#
directive|define
name|CLK_PERI_PWM6
value|25
end_define

begin_define
define|#
directive|define
name|CLK_PERI_PWM5
value|26
end_define

begin_define
define|#
directive|define
name|CLK_PERI_PWM4
value|27
end_define

begin_define
define|#
directive|define
name|CLK_PERI_PWM3
value|28
end_define

begin_define
define|#
directive|define
name|CLK_PERI_PWM2
value|29
end_define

begin_define
define|#
directive|define
name|CLK_PERI_PWM1
value|30
end_define

begin_define
define|#
directive|define
name|CLK_PERI_THERM
value|31
end_define

begin_define
define|#
directive|define
name|CLK_PERI_NFI
value|32
end_define

begin_define
define|#
directive|define
name|CLK_PERI_USBSLV
value|33
end_define

begin_define
define|#
directive|define
name|CLK_PERI_USB1_MCU
value|34
end_define

begin_define
define|#
directive|define
name|CLK_PERI_USB0_MCU
value|35
end_define

begin_define
define|#
directive|define
name|CLK_PERI_GCPU
value|36
end_define

begin_define
define|#
directive|define
name|CLK_PERI_FHCTL
value|37
end_define

begin_define
define|#
directive|define
name|CLK_PERI_SPI1
value|38
end_define

begin_define
define|#
directive|define
name|CLK_PERI_AUXADC
value|39
end_define

begin_define
define|#
directive|define
name|CLK_PERI_PERI_PWRAP
value|40
end_define

begin_define
define|#
directive|define
name|CLK_PERI_I2C6
value|41
end_define

begin_define
define|#
directive|define
name|CLK_PERI_UART0_SEL
value|42
end_define

begin_define
define|#
directive|define
name|CLK_PERI_UART1_SEL
value|43
end_define

begin_define
define|#
directive|define
name|CLK_PERI_UART2_SEL
value|44
end_define

begin_define
define|#
directive|define
name|CLK_PERI_UART3_SEL
value|45
end_define

begin_define
define|#
directive|define
name|CLK_PERI_NR_CLK
value|46
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_CLK_MT8135_H */
end_comment

end_unit

