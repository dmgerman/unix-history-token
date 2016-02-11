begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2014, The Linux Foundation. All rights reserved.  *  * This software is licensed under the terms of the GNU General Public  * License version 2, as published by the Free Software Foundation, and  * may be copied, distributed, and modified under those terms.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_RESET_IPQ_806X_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_RESET_IPQ_806X_H
end_define

begin_define
define|#
directive|define
name|QDSS_STM_RESET
value|0
end_define

begin_define
define|#
directive|define
name|AFAB_SMPSS_S_RESET
value|1
end_define

begin_define
define|#
directive|define
name|AFAB_SMPSS_M1_RESET
value|2
end_define

begin_define
define|#
directive|define
name|AFAB_SMPSS_M0_RESET
value|3
end_define

begin_define
define|#
directive|define
name|AFAB_EBI1_CH0_RESET
value|4
end_define

begin_define
define|#
directive|define
name|AFAB_EBI1_CH1_RESET
value|5
end_define

begin_define
define|#
directive|define
name|SFAB_ADM0_M0_RESET
value|6
end_define

begin_define
define|#
directive|define
name|SFAB_ADM0_M1_RESET
value|7
end_define

begin_define
define|#
directive|define
name|SFAB_ADM0_M2_RESET
value|8
end_define

begin_define
define|#
directive|define
name|ADM0_C2_RESET
value|9
end_define

begin_define
define|#
directive|define
name|ADM0_C1_RESET
value|10
end_define

begin_define
define|#
directive|define
name|ADM0_C0_RESET
value|11
end_define

begin_define
define|#
directive|define
name|ADM0_PBUS_RESET
value|12
end_define

begin_define
define|#
directive|define
name|ADM0_RESET
value|13
end_define

begin_define
define|#
directive|define
name|QDSS_CLKS_SW_RESET
value|14
end_define

begin_define
define|#
directive|define
name|QDSS_POR_RESET
value|15
end_define

begin_define
define|#
directive|define
name|QDSS_TSCTR_RESET
value|16
end_define

begin_define
define|#
directive|define
name|QDSS_HRESET_RESET
value|17
end_define

begin_define
define|#
directive|define
name|QDSS_AXI_RESET
value|18
end_define

begin_define
define|#
directive|define
name|QDSS_DBG_RESET
value|19
end_define

begin_define
define|#
directive|define
name|SFAB_PCIE_M_RESET
value|20
end_define

begin_define
define|#
directive|define
name|SFAB_PCIE_S_RESET
value|21
end_define

begin_define
define|#
directive|define
name|PCIE_EXT_RESET
value|22
end_define

begin_define
define|#
directive|define
name|PCIE_PHY_RESET
value|23
end_define

begin_define
define|#
directive|define
name|PCIE_PCI_RESET
value|24
end_define

begin_define
define|#
directive|define
name|PCIE_POR_RESET
value|25
end_define

begin_define
define|#
directive|define
name|PCIE_HCLK_RESET
value|26
end_define

begin_define
define|#
directive|define
name|PCIE_ACLK_RESET
value|27
end_define

begin_define
define|#
directive|define
name|SFAB_LPASS_RESET
value|28
end_define

begin_define
define|#
directive|define
name|SFAB_AFAB_M_RESET
value|29
end_define

begin_define
define|#
directive|define
name|AFAB_SFAB_M0_RESET
value|30
end_define

begin_define
define|#
directive|define
name|AFAB_SFAB_M1_RESET
value|31
end_define

begin_define
define|#
directive|define
name|SFAB_SATA_S_RESET
value|32
end_define

begin_define
define|#
directive|define
name|SFAB_DFAB_M_RESET
value|33
end_define

begin_define
define|#
directive|define
name|DFAB_SFAB_M_RESET
value|34
end_define

begin_define
define|#
directive|define
name|DFAB_SWAY0_RESET
value|35
end_define

begin_define
define|#
directive|define
name|DFAB_SWAY1_RESET
value|36
end_define

begin_define
define|#
directive|define
name|DFAB_ARB0_RESET
value|37
end_define

begin_define
define|#
directive|define
name|DFAB_ARB1_RESET
value|38
end_define

begin_define
define|#
directive|define
name|PPSS_PROC_RESET
value|39
end_define

begin_define
define|#
directive|define
name|PPSS_RESET
value|40
end_define

begin_define
define|#
directive|define
name|DMA_BAM_RESET
value|41
end_define

begin_define
define|#
directive|define
name|SPS_TIC_H_RESET
value|42
end_define

begin_define
define|#
directive|define
name|SFAB_CFPB_M_RESET
value|43
end_define

begin_define
define|#
directive|define
name|SFAB_CFPB_S_RESET
value|44
end_define

begin_define
define|#
directive|define
name|TSIF_H_RESET
value|45
end_define

begin_define
define|#
directive|define
name|CE1_H_RESET
value|46
end_define

begin_define
define|#
directive|define
name|CE1_CORE_RESET
value|47
end_define

begin_define
define|#
directive|define
name|CE1_SLEEP_RESET
value|48
end_define

begin_define
define|#
directive|define
name|CE2_H_RESET
value|49
end_define

begin_define
define|#
directive|define
name|CE2_CORE_RESET
value|50
end_define

begin_define
define|#
directive|define
name|SFAB_SFPB_M_RESET
value|51
end_define

begin_define
define|#
directive|define
name|SFAB_SFPB_S_RESET
value|52
end_define

begin_define
define|#
directive|define
name|RPM_PROC_RESET
value|53
end_define

begin_define
define|#
directive|define
name|PMIC_SSBI2_RESET
value|54
end_define

begin_define
define|#
directive|define
name|SDC1_RESET
value|55
end_define

begin_define
define|#
directive|define
name|SDC2_RESET
value|56
end_define

begin_define
define|#
directive|define
name|SDC3_RESET
value|57
end_define

begin_define
define|#
directive|define
name|SDC4_RESET
value|58
end_define

begin_define
define|#
directive|define
name|USB_HS1_RESET
value|59
end_define

begin_define
define|#
directive|define
name|USB_HSIC_RESET
value|60
end_define

begin_define
define|#
directive|define
name|USB_FS1_XCVR_RESET
value|61
end_define

begin_define
define|#
directive|define
name|USB_FS1_RESET
value|62
end_define

begin_define
define|#
directive|define
name|GSBI1_RESET
value|63
end_define

begin_define
define|#
directive|define
name|GSBI2_RESET
value|64
end_define

begin_define
define|#
directive|define
name|GSBI3_RESET
value|65
end_define

begin_define
define|#
directive|define
name|GSBI4_RESET
value|66
end_define

begin_define
define|#
directive|define
name|GSBI5_RESET
value|67
end_define

begin_define
define|#
directive|define
name|GSBI6_RESET
value|68
end_define

begin_define
define|#
directive|define
name|GSBI7_RESET
value|69
end_define

begin_define
define|#
directive|define
name|SPDM_RESET
value|70
end_define

begin_define
define|#
directive|define
name|SEC_CTRL_RESET
value|71
end_define

begin_define
define|#
directive|define
name|TLMM_H_RESET
value|72
end_define

begin_define
define|#
directive|define
name|SFAB_SATA_M_RESET
value|73
end_define

begin_define
define|#
directive|define
name|SATA_RESET
value|74
end_define

begin_define
define|#
directive|define
name|TSSC_RESET
value|75
end_define

begin_define
define|#
directive|define
name|PDM_RESET
value|76
end_define

begin_define
define|#
directive|define
name|MPM_H_RESET
value|77
end_define

begin_define
define|#
directive|define
name|MPM_RESET
value|78
end_define

begin_define
define|#
directive|define
name|SFAB_SMPSS_S_RESET
value|79
end_define

begin_define
define|#
directive|define
name|PRNG_RESET
value|80
end_define

begin_define
define|#
directive|define
name|SFAB_CE3_M_RESET
value|81
end_define

begin_define
define|#
directive|define
name|SFAB_CE3_S_RESET
value|82
end_define

begin_define
define|#
directive|define
name|CE3_SLEEP_RESET
value|83
end_define

begin_define
define|#
directive|define
name|PCIE_1_M_RESET
value|84
end_define

begin_define
define|#
directive|define
name|PCIE_1_S_RESET
value|85
end_define

begin_define
define|#
directive|define
name|PCIE_1_EXT_RESET
value|86
end_define

begin_define
define|#
directive|define
name|PCIE_1_PHY_RESET
value|87
end_define

begin_define
define|#
directive|define
name|PCIE_1_PCI_RESET
value|88
end_define

begin_define
define|#
directive|define
name|PCIE_1_POR_RESET
value|89
end_define

begin_define
define|#
directive|define
name|PCIE_1_HCLK_RESET
value|90
end_define

begin_define
define|#
directive|define
name|PCIE_1_ACLK_RESET
value|91
end_define

begin_define
define|#
directive|define
name|PCIE_2_M_RESET
value|92
end_define

begin_define
define|#
directive|define
name|PCIE_2_S_RESET
value|93
end_define

begin_define
define|#
directive|define
name|PCIE_2_EXT_RESET
value|94
end_define

begin_define
define|#
directive|define
name|PCIE_2_PHY_RESET
value|95
end_define

begin_define
define|#
directive|define
name|PCIE_2_PCI_RESET
value|96
end_define

begin_define
define|#
directive|define
name|PCIE_2_POR_RESET
value|97
end_define

begin_define
define|#
directive|define
name|PCIE_2_HCLK_RESET
value|98
end_define

begin_define
define|#
directive|define
name|PCIE_2_ACLK_RESET
value|99
end_define

begin_define
define|#
directive|define
name|SFAB_USB30_S_RESET
value|100
end_define

begin_define
define|#
directive|define
name|SFAB_USB30_M_RESET
value|101
end_define

begin_define
define|#
directive|define
name|USB30_0_PORT2_HS_PHY_RESET
value|102
end_define

begin_define
define|#
directive|define
name|USB30_0_MASTER_RESET
value|103
end_define

begin_define
define|#
directive|define
name|USB30_0_SLEEP_RESET
value|104
end_define

begin_define
define|#
directive|define
name|USB30_0_UTMI_PHY_RESET
value|105
end_define

begin_define
define|#
directive|define
name|USB30_0_POWERON_RESET
value|106
end_define

begin_define
define|#
directive|define
name|USB30_0_PHY_RESET
value|107
end_define

begin_define
define|#
directive|define
name|USB30_1_MASTER_RESET
value|108
end_define

begin_define
define|#
directive|define
name|USB30_1_SLEEP_RESET
value|109
end_define

begin_define
define|#
directive|define
name|USB30_1_UTMI_PHY_RESET
value|110
end_define

begin_define
define|#
directive|define
name|USB30_1_POWERON_RESET
value|111
end_define

begin_define
define|#
directive|define
name|USB30_1_PHY_RESET
value|112
end_define

begin_define
define|#
directive|define
name|NSSFB0_RESET
value|113
end_define

begin_define
define|#
directive|define
name|NSSFB1_RESET
value|114
end_define

begin_define
define|#
directive|define
name|UBI32_CORE1_CLKRST_CLAMP_RESET
value|115
end_define

begin_define
define|#
directive|define
name|UBI32_CORE1_CLAMP_RESET
value|116
end_define

begin_define
define|#
directive|define
name|UBI32_CORE1_AHB_RESET
value|117
end_define

begin_define
define|#
directive|define
name|UBI32_CORE1_AXI_RESET
value|118
end_define

begin_define
define|#
directive|define
name|UBI32_CORE2_CLKRST_CLAMP_RESET
value|119
end_define

begin_define
define|#
directive|define
name|UBI32_CORE2_CLAMP_RESET
value|120
end_define

begin_define
define|#
directive|define
name|UBI32_CORE2_AHB_RESET
value|121
end_define

begin_define
define|#
directive|define
name|UBI32_CORE2_AXI_RESET
value|122
end_define

begin_define
define|#
directive|define
name|GMAC_CORE1_RESET
value|123
end_define

begin_define
define|#
directive|define
name|GMAC_CORE2_RESET
value|124
end_define

begin_define
define|#
directive|define
name|GMAC_CORE3_RESET
value|125
end_define

begin_define
define|#
directive|define
name|GMAC_CORE4_RESET
value|126
end_define

begin_define
define|#
directive|define
name|GMAC_AHB_RESET
value|127
end_define

begin_define
define|#
directive|define
name|NSS_CH0_RST_RX_CLK_N_RESET
value|128
end_define

begin_define
define|#
directive|define
name|NSS_CH0_RST_TX_CLK_N_RESET
value|129
end_define

begin_define
define|#
directive|define
name|NSS_CH0_RST_RX_125M_N_RESET
value|130
end_define

begin_define
define|#
directive|define
name|NSS_CH0_HW_RST_RX_125M_N_RESET
value|131
end_define

begin_define
define|#
directive|define
name|NSS_CH0_RST_TX_125M_N_RESET
value|132
end_define

begin_define
define|#
directive|define
name|NSS_CH1_RST_RX_CLK_N_RESET
value|133
end_define

begin_define
define|#
directive|define
name|NSS_CH1_RST_TX_CLK_N_RESET
value|134
end_define

begin_define
define|#
directive|define
name|NSS_CH1_RST_RX_125M_N_RESET
value|135
end_define

begin_define
define|#
directive|define
name|NSS_CH1_HW_RST_RX_125M_N_RESET
value|136
end_define

begin_define
define|#
directive|define
name|NSS_CH1_RST_TX_125M_N_RESET
value|137
end_define

begin_define
define|#
directive|define
name|NSS_CH2_RST_RX_CLK_N_RESET
value|138
end_define

begin_define
define|#
directive|define
name|NSS_CH2_RST_TX_CLK_N_RESET
value|139
end_define

begin_define
define|#
directive|define
name|NSS_CH2_RST_RX_125M_N_RESET
value|140
end_define

begin_define
define|#
directive|define
name|NSS_CH2_HW_RST_RX_125M_N_RESET
value|141
end_define

begin_define
define|#
directive|define
name|NSS_CH2_RST_TX_125M_N_RESET
value|142
end_define

begin_define
define|#
directive|define
name|NSS_CH3_RST_RX_CLK_N_RESET
value|143
end_define

begin_define
define|#
directive|define
name|NSS_CH3_RST_TX_CLK_N_RESET
value|144
end_define

begin_define
define|#
directive|define
name|NSS_CH3_RST_RX_125M_N_RESET
value|145
end_define

begin_define
define|#
directive|define
name|NSS_CH3_HW_RST_RX_125M_N_RESET
value|146
end_define

begin_define
define|#
directive|define
name|NSS_CH3_RST_TX_125M_N_RESET
value|147
end_define

begin_define
define|#
directive|define
name|NSS_RST_RX_250M_125M_N_RESET
value|148
end_define

begin_define
define|#
directive|define
name|NSS_RST_TX_250M_125M_N_RESET
value|149
end_define

begin_define
define|#
directive|define
name|NSS_QSGMII_TXPI_RST_N_RESET
value|150
end_define

begin_define
define|#
directive|define
name|NSS_QSGMII_CDR_RST_N_RESET
value|151
end_define

begin_define
define|#
directive|define
name|NSS_SGMII2_CDR_RST_N_RESET
value|152
end_define

begin_define
define|#
directive|define
name|NSS_SGMII3_CDR_RST_N_RESET
value|153
end_define

begin_define
define|#
directive|define
name|NSS_CAL_PRBS_RST_N_RESET
value|154
end_define

begin_define
define|#
directive|define
name|NSS_LCKDT_RST_N_RESET
value|155
end_define

begin_define
define|#
directive|define
name|NSS_SRDS_N_RESET
value|156
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

