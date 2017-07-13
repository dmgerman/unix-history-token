begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017 MediaTek Inc.  * Author: Kevin Chen<kevin-cw.chen@mediatek.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLK_MT6797_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLK_MT6797_H
end_define

begin_comment
comment|/* TOPCKGEN */
end_comment

begin_define
define|#
directive|define
name|CLK_TOP_MUX_ULPOSC_AXI_CK_MUX_PRE
value|1
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MUX_ULPOSC_AXI_CK_MUX
value|2
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MUX_AXI
value|3
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MUX_MEM
value|4
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MUX_DDRPHYCFG
value|5
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MUX_MM
value|6
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MUX_PWM
value|7
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MUX_VDEC
value|8
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MUX_VENC
value|9
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MUX_MFG
value|10
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MUX_CAMTG
value|11
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MUX_UART
value|12
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MUX_SPI
value|13
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MUX_ULPOSC_SPI_CK_MUX
value|14
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MUX_USB20
value|15
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MUX_MSDC50_0_HCLK
value|16
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MUX_MSDC50_0
value|17
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MUX_MSDC30_1
value|18
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MUX_MSDC30_2
value|19
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MUX_AUDIO
value|20
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MUX_AUD_INTBUS
value|21
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MUX_PMICSPI
value|22
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MUX_SCP
value|23
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MUX_ATB
value|24
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MUX_MJC
value|25
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MUX_DPI0
value|26
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MUX_AUD_1
value|27
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MUX_AUD_2
value|28
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MUX_SSUSB_TOP_SYS
value|29
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MUX_SPM
value|30
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MUX_BSI_SPI
value|31
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MUX_AUDIO_H
value|32
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MUX_ANC_MD32
value|33
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MUX_MFG_52M
value|34
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL_CK
value|35
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL_D2
value|36
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL1_D2
value|37
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL1_D4
value|38
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL1_D8
value|39
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL1_D16
value|40
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL_D3
value|41
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL_D3_D3
value|42
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL2_D2
value|43
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL2_D4
value|44
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL2_D8
value|45
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL_D5
value|46
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL3_D2
value|47
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL3_D4
value|48
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL_D7
value|49
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL4_D2
value|50
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SYSPLL4_D4
value|51
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL_CK
value|52
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL_D7
value|53
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL_D26
value|54
end_define

begin_define
define|#
directive|define
name|CLK_TOP_SSUSB_PHY_48M_CK
value|55
end_define

begin_define
define|#
directive|define
name|CLK_TOP_USB_PHY48M_CK
value|56
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL_D2
value|57
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL1_D2
value|58
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL1_D4
value|59
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL1_D8
value|60
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL_D3
value|61
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL2_D2
value|62
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL2_D4
value|63
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL2_D8
value|64
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL_D5
value|65
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL3_D2
value|66
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL3_D4
value|67
end_define

begin_define
define|#
directive|define
name|CLK_TOP_UNIVPLL3_D8
value|68
end_define

begin_define
define|#
directive|define
name|CLK_TOP_ULPOSC_CK_ORG
value|69
end_define

begin_define
define|#
directive|define
name|CLK_TOP_ULPOSC_CK
value|70
end_define

begin_define
define|#
directive|define
name|CLK_TOP_ULPOSC_D2
value|71
end_define

begin_define
define|#
directive|define
name|CLK_TOP_ULPOSC_D3
value|72
end_define

begin_define
define|#
directive|define
name|CLK_TOP_ULPOSC_D4
value|73
end_define

begin_define
define|#
directive|define
name|CLK_TOP_ULPOSC_D8
value|74
end_define

begin_define
define|#
directive|define
name|CLK_TOP_ULPOSC_D10
value|75
end_define

begin_define
define|#
directive|define
name|CLK_TOP_APLL1_CK
value|76
end_define

begin_define
define|#
directive|define
name|CLK_TOP_APLL2_CK
value|77
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MFGPLL_CK
value|78
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MFGPLL_D2
value|79
end_define

begin_define
define|#
directive|define
name|CLK_TOP_IMGPLL_CK
value|80
end_define

begin_define
define|#
directive|define
name|CLK_TOP_IMGPLL_D2
value|81
end_define

begin_define
define|#
directive|define
name|CLK_TOP_IMGPLL_D4
value|82
end_define

begin_define
define|#
directive|define
name|CLK_TOP_CODECPLL_CK
value|83
end_define

begin_define
define|#
directive|define
name|CLK_TOP_CODECPLL_D2
value|84
end_define

begin_define
define|#
directive|define
name|CLK_TOP_VDECPLL_CK
value|85
end_define

begin_define
define|#
directive|define
name|CLK_TOP_TVDPLL_CK
value|86
end_define

begin_define
define|#
directive|define
name|CLK_TOP_TVDPLL_D2
value|87
end_define

begin_define
define|#
directive|define
name|CLK_TOP_TVDPLL_D4
value|88
end_define

begin_define
define|#
directive|define
name|CLK_TOP_TVDPLL_D8
value|89
end_define

begin_define
define|#
directive|define
name|CLK_TOP_TVDPLL_D16
value|90
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MSDCPLL_CK
value|91
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MSDCPLL_D2
value|92
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MSDCPLL_D4
value|93
end_define

begin_define
define|#
directive|define
name|CLK_TOP_MSDCPLL_D8
value|94
end_define

begin_define
define|#
directive|define
name|CLK_TOP_NR
value|95
end_define

begin_comment
comment|/* APMIXED_SYS */
end_comment

begin_define
define|#
directive|define
name|CLK_APMIXED_MAINPLL
value|1
end_define

begin_define
define|#
directive|define
name|CLK_APMIXED_UNIVPLL
value|2
end_define

begin_define
define|#
directive|define
name|CLK_APMIXED_MFGPLL
value|3
end_define

begin_define
define|#
directive|define
name|CLK_APMIXED_MSDCPLL
value|4
end_define

begin_define
define|#
directive|define
name|CLK_APMIXED_IMGPLL
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
name|CLK_APMIXED_CODECPLL
value|7
end_define

begin_define
define|#
directive|define
name|CLK_APMIXED_VDECPLL
value|8
end_define

begin_define
define|#
directive|define
name|CLK_APMIXED_APLL1
value|9
end_define

begin_define
define|#
directive|define
name|CLK_APMIXED_APLL2
value|10
end_define

begin_define
define|#
directive|define
name|CLK_APMIXED_NR
value|11
end_define

begin_comment
comment|/* INFRA_SYS */
end_comment

begin_define
define|#
directive|define
name|CLK_INFRA_PMIC_TMR
value|1
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_PMIC_AP
value|2
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_PMIC_MD
value|3
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_PMIC_CONN
value|4
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_SCP
value|5
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_SEJ
value|6
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_APXGPT
value|7
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_SEJ_13M
value|8
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_ICUSB
value|9
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_GCE
value|10
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_THERM
value|11
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_I2C0
value|12
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_I2C1
value|13
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_I2C2
value|14
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_I2C3
value|15
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_PWM_HCLK
value|16
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_PWM1
value|17
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_PWM2
value|18
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_PWM3
value|19
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_PWM4
value|20
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_PWM
value|21
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_UART0
value|22
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_UART1
value|23
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_UART2
value|24
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_UART3
value|25
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_MD2MD_CCIF_0
value|26
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_MD2MD_CCIF_1
value|27
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_MD2MD_CCIF_2
value|28
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_FHCTL
value|29
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_BTIF
value|30
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_MD2MD_CCIF_3
value|31
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_SPI
value|32
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_MSDC0
value|33
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_MD2MD_CCIF_4
value|34
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_MSDC1
value|35
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_MSDC2
value|36
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_MD2MD_CCIF_5
value|37
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_GCPU
value|38
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_TRNG
value|39
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_AUXADC
value|40
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_CPUM
value|41
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_AP_C2K_CCIF_0
value|42
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_AP_C2K_CCIF_1
value|43
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_CLDMA
value|44
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_DISP_PWM
value|45
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_AP_DMA
value|46
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_DEVICE_APC
value|47
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_L2C_SRAM
value|48
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_CCIF_AP
value|49
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_AUDIO
value|50
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_CCIF_MD
value|51
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_DRAMC_F26M
value|52
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_I2C4
value|53
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_I2C_APPM
value|54
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_I2C_GPUPM
value|55
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_I2C2_IMM
value|56
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_I2C2_ARB
value|57
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_I2C3_IMM
value|58
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_I2C3_ARB
value|59
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_I2C5
value|60
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_SYS_CIRQ
value|61
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_SPI1
value|62
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_DRAMC_B_F26M
value|63
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_ANC_MD32
value|64
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_ANC_MD32_32K
value|65
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_DVFS_SPM1
value|66
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_AES_TOP0
value|67
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_AES_TOP1
value|68
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_SSUSB_BUS
value|69
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_SPI2
value|70
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_SPI3
value|71
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_SPI4
value|72
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_SPI5
value|73
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_IRTX
value|74
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_SSUSB_SYS
value|75
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_SSUSB_REF
value|76
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_AUDIO_26M
value|77
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_AUDIO_26M_PAD_TOP
value|78
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_MODEM_TEMP_SHARE
value|79
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_VAD_WRAP_SOC
value|80
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_DRAMC_CONF
value|81
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_DRAMC_B_CONF
value|82
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_MFG_VCG
value|83
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_13M
value|84
end_define

begin_define
define|#
directive|define
name|CLK_INFRA_NR
value|85
end_define

begin_comment
comment|/* IMG_SYS */
end_comment

begin_define
define|#
directive|define
name|CLK_IMG_FDVT
value|1
end_define

begin_define
define|#
directive|define
name|CLK_IMG_DPE
value|2
end_define

begin_define
define|#
directive|define
name|CLK_IMG_DIP
value|3
end_define

begin_define
define|#
directive|define
name|CLK_IMG_LARB6
value|4
end_define

begin_define
define|#
directive|define
name|CLK_IMG_NR
value|5
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
name|CLK_MM_SMI_LARB5
value|3
end_define

begin_define
define|#
directive|define
name|CLK_MM_CAM_MDP
value|4
end_define

begin_define
define|#
directive|define
name|CLK_MM_MDP_RDMA0
value|5
end_define

begin_define
define|#
directive|define
name|CLK_MM_MDP_RDMA1
value|6
end_define

begin_define
define|#
directive|define
name|CLK_MM_MDP_RSZ0
value|7
end_define

begin_define
define|#
directive|define
name|CLK_MM_MDP_RSZ1
value|8
end_define

begin_define
define|#
directive|define
name|CLK_MM_MDP_RSZ2
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
name|CLK_MM_MDP_COLOR
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
name|CLK_MM_MDP_WROT0
value|13
end_define

begin_define
define|#
directive|define
name|CLK_MM_MDP_WROT1
value|14
end_define

begin_define
define|#
directive|define
name|CLK_MM_FAKE_ENG
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
name|CLK_MM_DISP_OVL0_2L
value|18
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_OVL1_2L
value|19
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_RDMA0
value|20
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_RDMA1
value|21
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_WDMA0
value|22
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_WDMA1
value|23
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_COLOR
value|24
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_CCORR
value|25
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_AAL
value|26
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_GAMMA
value|27
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_OD
value|28
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_DITHER
value|29
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_UFOE
value|30
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_DSC
value|31
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_SPLIT
value|32
end_define

begin_define
define|#
directive|define
name|CLK_MM_DSI0_MM_CLOCK
value|33
end_define

begin_define
define|#
directive|define
name|CLK_MM_DSI1_MM_CLOCK
value|34
end_define

begin_define
define|#
directive|define
name|CLK_MM_DPI_MM_CLOCK
value|35
end_define

begin_define
define|#
directive|define
name|CLK_MM_DPI_INTERFACE_CLOCK
value|36
end_define

begin_define
define|#
directive|define
name|CLK_MM_LARB4_AXI_ASIF_MM_CLOCK
value|37
end_define

begin_define
define|#
directive|define
name|CLK_MM_LARB4_AXI_ASIF_MJC_CLOCK
value|38
end_define

begin_define
define|#
directive|define
name|CLK_MM_DISP_OVL0_MOUT_CLOCK
value|39
end_define

begin_define
define|#
directive|define
name|CLK_MM_FAKE_ENG2
value|40
end_define

begin_define
define|#
directive|define
name|CLK_MM_DSI0_INTERFACE_CLOCK
value|41
end_define

begin_define
define|#
directive|define
name|CLK_MM_DSI1_INTERFACE_CLOCK
value|42
end_define

begin_define
define|#
directive|define
name|CLK_MM_NR
value|43
end_define

begin_comment
comment|/* VDEC_SYS */
end_comment

begin_define
define|#
directive|define
name|CLK_VDEC_CKEN_ENG
value|1
end_define

begin_define
define|#
directive|define
name|CLK_VDEC_ACTIVE
value|2
end_define

begin_define
define|#
directive|define
name|CLK_VDEC_CKEN
value|3
end_define

begin_define
define|#
directive|define
name|CLK_VDEC_LARB1_CKEN
value|4
end_define

begin_define
define|#
directive|define
name|CLK_VDEC_NR
value|5
end_define

begin_comment
comment|/* VENC_SYS */
end_comment

begin_define
define|#
directive|define
name|CLK_VENC_0
value|1
end_define

begin_define
define|#
directive|define
name|CLK_VENC_1
value|2
end_define

begin_define
define|#
directive|define
name|CLK_VENC_2
value|3
end_define

begin_define
define|#
directive|define
name|CLK_VENC_3
value|4
end_define

begin_define
define|#
directive|define
name|CLK_VENC_NR
value|5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_CLK_MT6797_H */
end_comment

end_unit

