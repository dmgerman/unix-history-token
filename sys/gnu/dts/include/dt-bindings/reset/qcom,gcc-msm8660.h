begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013, The Linux Foundation. All rights reserved.  *  * This software is licensed under the terms of the GNU General Public  * License version 2, as published by the Free Software Foundation, and  * may be copied, distributed, and modified under those terms.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_RESET_MSM_GCC_8660_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_RESET_MSM_GCC_8660_H
end_define

begin_define
define|#
directive|define
name|AFAB_CORE_RESET
value|0
end_define

begin_define
define|#
directive|define
name|SCSS_SYS_RESET
value|1
end_define

begin_define
define|#
directive|define
name|SCSS_SYS_POR_RESET
value|2
end_define

begin_define
define|#
directive|define
name|AFAB_SMPSS_S_RESET
value|3
end_define

begin_define
define|#
directive|define
name|AFAB_SMPSS_M1_RESET
value|4
end_define

begin_define
define|#
directive|define
name|AFAB_SMPSS_M0_RESET
value|5
end_define

begin_define
define|#
directive|define
name|AFAB_EBI1_S_RESET
value|6
end_define

begin_define
define|#
directive|define
name|SFAB_CORE_RESET
value|7
end_define

begin_define
define|#
directive|define
name|SFAB_ADM0_M0_RESET
value|8
end_define

begin_define
define|#
directive|define
name|SFAB_ADM0_M1_RESET
value|9
end_define

begin_define
define|#
directive|define
name|SFAB_ADM0_M2_RESET
value|10
end_define

begin_define
define|#
directive|define
name|ADM0_C2_RESET
value|11
end_define

begin_define
define|#
directive|define
name|ADM0_C1_RESET
value|12
end_define

begin_define
define|#
directive|define
name|ADM0_C0_RESET
value|13
end_define

begin_define
define|#
directive|define
name|ADM0_PBUS_RESET
value|14
end_define

begin_define
define|#
directive|define
name|ADM0_RESET
value|15
end_define

begin_define
define|#
directive|define
name|SFAB_ADM1_M0_RESET
value|16
end_define

begin_define
define|#
directive|define
name|SFAB_ADM1_M1_RESET
value|17
end_define

begin_define
define|#
directive|define
name|SFAB_ADM1_M2_RESET
value|18
end_define

begin_define
define|#
directive|define
name|MMFAB_ADM1_M3_RESET
value|19
end_define

begin_define
define|#
directive|define
name|ADM1_C3_RESET
value|20
end_define

begin_define
define|#
directive|define
name|ADM1_C2_RESET
value|21
end_define

begin_define
define|#
directive|define
name|ADM1_C1_RESET
value|22
end_define

begin_define
define|#
directive|define
name|ADM1_C0_RESET
value|23
end_define

begin_define
define|#
directive|define
name|ADM1_PBUS_RESET
value|24
end_define

begin_define
define|#
directive|define
name|ADM1_RESET
value|25
end_define

begin_define
define|#
directive|define
name|IMEM0_RESET
value|26
end_define

begin_define
define|#
directive|define
name|SFAB_LPASS_Q6_RESET
value|27
end_define

begin_define
define|#
directive|define
name|SFAB_AFAB_M_RESET
value|28
end_define

begin_define
define|#
directive|define
name|AFAB_SFAB_M0_RESET
value|29
end_define

begin_define
define|#
directive|define
name|AFAB_SFAB_M1_RESET
value|30
end_define

begin_define
define|#
directive|define
name|DFAB_CORE_RESET
value|31
end_define

begin_define
define|#
directive|define
name|SFAB_DFAB_M_RESET
value|32
end_define

begin_define
define|#
directive|define
name|DFAB_SFAB_M_RESET
value|33
end_define

begin_define
define|#
directive|define
name|DFAB_SWAY0_RESET
value|34
end_define

begin_define
define|#
directive|define
name|DFAB_SWAY1_RESET
value|35
end_define

begin_define
define|#
directive|define
name|DFAB_ARB0_RESET
value|36
end_define

begin_define
define|#
directive|define
name|DFAB_ARB1_RESET
value|37
end_define

begin_define
define|#
directive|define
name|PPSS_PROC_RESET
value|38
end_define

begin_define
define|#
directive|define
name|PPSS_RESET
value|39
end_define

begin_define
define|#
directive|define
name|PMEM_RESET
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
name|SIC_RESET
value|42
end_define

begin_define
define|#
directive|define
name|SPS_TIC_RESET
value|43
end_define

begin_define
define|#
directive|define
name|CFBP0_RESET
value|44
end_define

begin_define
define|#
directive|define
name|CFBP1_RESET
value|45
end_define

begin_define
define|#
directive|define
name|CFBP2_RESET
value|46
end_define

begin_define
define|#
directive|define
name|EBI2_RESET
value|47
end_define

begin_define
define|#
directive|define
name|SFAB_CFPB_M_RESET
value|48
end_define

begin_define
define|#
directive|define
name|CFPB_MASTER_RESET
value|49
end_define

begin_define
define|#
directive|define
name|SFAB_CFPB_S_RESET
value|50
end_define

begin_define
define|#
directive|define
name|CFPB_SPLITTER_RESET
value|51
end_define

begin_define
define|#
directive|define
name|TSIF_RESET
value|52
end_define

begin_define
define|#
directive|define
name|CE1_RESET
value|53
end_define

begin_define
define|#
directive|define
name|CE2_RESET
value|54
end_define

begin_define
define|#
directive|define
name|SFAB_SFPB_M_RESET
value|55
end_define

begin_define
define|#
directive|define
name|SFAB_SFPB_S_RESET
value|56
end_define

begin_define
define|#
directive|define
name|RPM_PROC_RESET
value|57
end_define

begin_define
define|#
directive|define
name|RPM_BUS_RESET
value|58
end_define

begin_define
define|#
directive|define
name|RPM_MSG_RAM_RESET
value|59
end_define

begin_define
define|#
directive|define
name|PMIC_ARB0_RESET
value|60
end_define

begin_define
define|#
directive|define
name|PMIC_ARB1_RESET
value|61
end_define

begin_define
define|#
directive|define
name|PMIC_SSBI2_RESET
value|62
end_define

begin_define
define|#
directive|define
name|SDC1_RESET
value|63
end_define

begin_define
define|#
directive|define
name|SDC2_RESET
value|64
end_define

begin_define
define|#
directive|define
name|SDC3_RESET
value|65
end_define

begin_define
define|#
directive|define
name|SDC4_RESET
value|66
end_define

begin_define
define|#
directive|define
name|SDC5_RESET
value|67
end_define

begin_define
define|#
directive|define
name|USB_HS1_RESET
value|68
end_define

begin_define
define|#
directive|define
name|USB_HS2_XCVR_RESET
value|69
end_define

begin_define
define|#
directive|define
name|USB_HS2_RESET
value|70
end_define

begin_define
define|#
directive|define
name|USB_FS1_XCVR_RESET
value|71
end_define

begin_define
define|#
directive|define
name|USB_FS1_RESET
value|72
end_define

begin_define
define|#
directive|define
name|USB_FS2_XCVR_RESET
value|73
end_define

begin_define
define|#
directive|define
name|USB_FS2_RESET
value|74
end_define

begin_define
define|#
directive|define
name|GSBI1_RESET
value|75
end_define

begin_define
define|#
directive|define
name|GSBI2_RESET
value|76
end_define

begin_define
define|#
directive|define
name|GSBI3_RESET
value|77
end_define

begin_define
define|#
directive|define
name|GSBI4_RESET
value|78
end_define

begin_define
define|#
directive|define
name|GSBI5_RESET
value|79
end_define

begin_define
define|#
directive|define
name|GSBI6_RESET
value|80
end_define

begin_define
define|#
directive|define
name|GSBI7_RESET
value|81
end_define

begin_define
define|#
directive|define
name|GSBI8_RESET
value|82
end_define

begin_define
define|#
directive|define
name|GSBI9_RESET
value|83
end_define

begin_define
define|#
directive|define
name|GSBI10_RESET
value|84
end_define

begin_define
define|#
directive|define
name|GSBI11_RESET
value|85
end_define

begin_define
define|#
directive|define
name|GSBI12_RESET
value|86
end_define

begin_define
define|#
directive|define
name|SPDM_RESET
value|87
end_define

begin_define
define|#
directive|define
name|SEC_CTRL_RESET
value|88
end_define

begin_define
define|#
directive|define
name|TLMM_H_RESET
value|89
end_define

begin_define
define|#
directive|define
name|TLMM_RESET
value|90
end_define

begin_define
define|#
directive|define
name|MARRM_PWRON_RESET
value|91
end_define

begin_define
define|#
directive|define
name|MARM_RESET
value|92
end_define

begin_define
define|#
directive|define
name|MAHB1_RESET
value|93
end_define

begin_define
define|#
directive|define
name|SFAB_MSS_S_RESET
value|94
end_define

begin_define
define|#
directive|define
name|MAHB2_RESET
value|95
end_define

begin_define
define|#
directive|define
name|MODEM_SW_AHB_RESET
value|96
end_define

begin_define
define|#
directive|define
name|MODEM_RESET
value|97
end_define

begin_define
define|#
directive|define
name|SFAB_MSS_MDM1_RESET
value|98
end_define

begin_define
define|#
directive|define
name|SFAB_MSS_MDM0_RESET
value|99
end_define

begin_define
define|#
directive|define
name|MSS_SLP_RESET
value|100
end_define

begin_define
define|#
directive|define
name|MSS_MARM_SAW_RESET
value|101
end_define

begin_define
define|#
directive|define
name|MSS_WDOG_RESET
value|102
end_define

begin_define
define|#
directive|define
name|TSSC_RESET
value|103
end_define

begin_define
define|#
directive|define
name|PDM_RESET
value|104
end_define

begin_define
define|#
directive|define
name|SCSS_CORE0_RESET
value|105
end_define

begin_define
define|#
directive|define
name|SCSS_CORE0_POR_RESET
value|106
end_define

begin_define
define|#
directive|define
name|SCSS_CORE1_RESET
value|107
end_define

begin_define
define|#
directive|define
name|SCSS_CORE1_POR_RESET
value|108
end_define

begin_define
define|#
directive|define
name|MPM_RESET
value|109
end_define

begin_define
define|#
directive|define
name|EBI1_1X_DIV_RESET
value|110
end_define

begin_define
define|#
directive|define
name|EBI1_RESET
value|111
end_define

begin_define
define|#
directive|define
name|SFAB_SMPSS_S_RESET
value|112
end_define

begin_define
define|#
directive|define
name|USB_PHY0_RESET
value|113
end_define

begin_define
define|#
directive|define
name|USB_PHY1_RESET
value|114
end_define

begin_define
define|#
directive|define
name|PRNG_RESET
value|115
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

