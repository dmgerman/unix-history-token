begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013, The Linux Foundation. All rights reserved.  * Copyright (c) BayLibre, SAS.  * Author : Neil Armstrong<narmstrong@baylibre.com>  *  * This software is licensed under the terms of the GNU General Public  * License version 2, as published by the Free Software Foundation, and  * may be copied, distributed, and modified under those terms.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLK_MDM_GCC_9615_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLK_MDM_GCC_9615_H
end_define

begin_define
define|#
directive|define
name|AFAB_CLK_SRC
value|0
end_define

begin_define
define|#
directive|define
name|AFAB_CORE_CLK
value|1
end_define

begin_define
define|#
directive|define
name|SFAB_MSS_Q6_SW_A_CLK
value|2
end_define

begin_define
define|#
directive|define
name|SFAB_MSS_Q6_FW_A_CLK
value|3
end_define

begin_define
define|#
directive|define
name|QDSS_STM_CLK
value|4
end_define

begin_define
define|#
directive|define
name|SCSS_A_CLK
value|5
end_define

begin_define
define|#
directive|define
name|SCSS_H_CLK
value|6
end_define

begin_define
define|#
directive|define
name|SCSS_XO_SRC_CLK
value|7
end_define

begin_define
define|#
directive|define
name|AFAB_EBI1_CH0_A_CLK
value|8
end_define

begin_define
define|#
directive|define
name|AFAB_EBI1_CH1_A_CLK
value|9
end_define

begin_define
define|#
directive|define
name|AFAB_AXI_S0_FCLK
value|10
end_define

begin_define
define|#
directive|define
name|AFAB_AXI_S1_FCLK
value|11
end_define

begin_define
define|#
directive|define
name|AFAB_AXI_S2_FCLK
value|12
end_define

begin_define
define|#
directive|define
name|AFAB_AXI_S3_FCLK
value|13
end_define

begin_define
define|#
directive|define
name|AFAB_AXI_S4_FCLK
value|14
end_define

begin_define
define|#
directive|define
name|SFAB_CORE_CLK
value|15
end_define

begin_define
define|#
directive|define
name|SFAB_AXI_S0_FCLK
value|16
end_define

begin_define
define|#
directive|define
name|SFAB_AXI_S1_FCLK
value|17
end_define

begin_define
define|#
directive|define
name|SFAB_AXI_S2_FCLK
value|18
end_define

begin_define
define|#
directive|define
name|SFAB_AXI_S3_FCLK
value|19
end_define

begin_define
define|#
directive|define
name|SFAB_AXI_S4_FCLK
value|20
end_define

begin_define
define|#
directive|define
name|SFAB_AHB_S0_FCLK
value|21
end_define

begin_define
define|#
directive|define
name|SFAB_AHB_S1_FCLK
value|22
end_define

begin_define
define|#
directive|define
name|SFAB_AHB_S2_FCLK
value|23
end_define

begin_define
define|#
directive|define
name|SFAB_AHB_S3_FCLK
value|24
end_define

begin_define
define|#
directive|define
name|SFAB_AHB_S4_FCLK
value|25
end_define

begin_define
define|#
directive|define
name|SFAB_AHB_S5_FCLK
value|26
end_define

begin_define
define|#
directive|define
name|SFAB_AHB_S6_FCLK
value|27
end_define

begin_define
define|#
directive|define
name|SFAB_AHB_S7_FCLK
value|28
end_define

begin_define
define|#
directive|define
name|QDSS_AT_CLK_SRC
value|29
end_define

begin_define
define|#
directive|define
name|QDSS_AT_CLK
value|30
end_define

begin_define
define|#
directive|define
name|QDSS_TRACECLKIN_CLK_SRC
value|31
end_define

begin_define
define|#
directive|define
name|QDSS_TRACECLKIN_CLK
value|32
end_define

begin_define
define|#
directive|define
name|QDSS_TSCTR_CLK_SRC
value|33
end_define

begin_define
define|#
directive|define
name|QDSS_TSCTR_CLK
value|34
end_define

begin_define
define|#
directive|define
name|SFAB_ADM0_M0_A_CLK
value|35
end_define

begin_define
define|#
directive|define
name|SFAB_ADM0_M1_A_CLK
value|36
end_define

begin_define
define|#
directive|define
name|SFAB_ADM0_M2_H_CLK
value|37
end_define

begin_define
define|#
directive|define
name|ADM0_CLK
value|38
end_define

begin_define
define|#
directive|define
name|ADM0_PBUS_CLK
value|39
end_define

begin_define
define|#
directive|define
name|MSS_XPU_CLK
value|40
end_define

begin_define
define|#
directive|define
name|IMEM0_A_CLK
value|41
end_define

begin_define
define|#
directive|define
name|QDSS_H_CLK
value|42
end_define

begin_define
define|#
directive|define
name|PCIE_A_CLK
value|43
end_define

begin_define
define|#
directive|define
name|PCIE_AUX_CLK
value|44
end_define

begin_define
define|#
directive|define
name|PCIE_PHY_REF_CLK
value|45
end_define

begin_define
define|#
directive|define
name|PCIE_H_CLK
value|46
end_define

begin_define
define|#
directive|define
name|SFAB_CLK_SRC
value|47
end_define

begin_define
define|#
directive|define
name|MAHB0_CLK
value|48
end_define

begin_define
define|#
directive|define
name|Q6SW_CLK_SRC
value|49
end_define

begin_define
define|#
directive|define
name|Q6SW_CLK
value|50
end_define

begin_define
define|#
directive|define
name|Q6FW_CLK_SRC
value|51
end_define

begin_define
define|#
directive|define
name|Q6FW_CLK
value|52
end_define

begin_define
define|#
directive|define
name|SFAB_MSS_M_A_CLK
value|53
end_define

begin_define
define|#
directive|define
name|SFAB_USB3_M_A_CLK
value|54
end_define

begin_define
define|#
directive|define
name|SFAB_LPASS_Q6_A_CLK
value|55
end_define

begin_define
define|#
directive|define
name|SFAB_AFAB_M_A_CLK
value|56
end_define

begin_define
define|#
directive|define
name|AFAB_SFAB_M0_A_CLK
value|57
end_define

begin_define
define|#
directive|define
name|AFAB_SFAB_M1_A_CLK
value|58
end_define

begin_define
define|#
directive|define
name|SFAB_SATA_S_H_CLK
value|59
end_define

begin_define
define|#
directive|define
name|DFAB_CLK_SRC
value|60
end_define

begin_define
define|#
directive|define
name|DFAB_CLK
value|61
end_define

begin_define
define|#
directive|define
name|SFAB_DFAB_M_A_CLK
value|62
end_define

begin_define
define|#
directive|define
name|DFAB_SFAB_M_A_CLK
value|63
end_define

begin_define
define|#
directive|define
name|DFAB_SWAY0_H_CLK
value|64
end_define

begin_define
define|#
directive|define
name|DFAB_SWAY1_H_CLK
value|65
end_define

begin_define
define|#
directive|define
name|DFAB_ARB0_H_CLK
value|66
end_define

begin_define
define|#
directive|define
name|DFAB_ARB1_H_CLK
value|67
end_define

begin_define
define|#
directive|define
name|PPSS_H_CLK
value|68
end_define

begin_define
define|#
directive|define
name|PPSS_PROC_CLK
value|69
end_define

begin_define
define|#
directive|define
name|PPSS_TIMER0_CLK
value|70
end_define

begin_define
define|#
directive|define
name|PPSS_TIMER1_CLK
value|71
end_define

begin_define
define|#
directive|define
name|PMEM_A_CLK
value|72
end_define

begin_define
define|#
directive|define
name|DMA_BAM_H_CLK
value|73
end_define

begin_define
define|#
directive|define
name|SIC_H_CLK
value|74
end_define

begin_define
define|#
directive|define
name|SPS_TIC_H_CLK
value|75
end_define

begin_define
define|#
directive|define
name|SLIMBUS_H_CLK
value|76
end_define

begin_define
define|#
directive|define
name|SLIMBUS_XO_SRC_CLK
value|77
end_define

begin_define
define|#
directive|define
name|CFPB_2X_CLK_SRC
value|78
end_define

begin_define
define|#
directive|define
name|CFPB_CLK
value|79
end_define

begin_define
define|#
directive|define
name|CFPB0_H_CLK
value|80
end_define

begin_define
define|#
directive|define
name|CFPB1_H_CLK
value|81
end_define

begin_define
define|#
directive|define
name|CFPB2_H_CLK
value|82
end_define

begin_define
define|#
directive|define
name|SFAB_CFPB_M_H_CLK
value|83
end_define

begin_define
define|#
directive|define
name|CFPB_MASTER_H_CLK
value|84
end_define

begin_define
define|#
directive|define
name|SFAB_CFPB_S_H_CLK
value|85
end_define

begin_define
define|#
directive|define
name|CFPB_SPLITTER_H_CLK
value|86
end_define

begin_define
define|#
directive|define
name|TSIF_H_CLK
value|87
end_define

begin_define
define|#
directive|define
name|TSIF_INACTIVITY_TIMERS_CLK
value|88
end_define

begin_define
define|#
directive|define
name|TSIF_REF_SRC
value|89
end_define

begin_define
define|#
directive|define
name|TSIF_REF_CLK
value|90
end_define

begin_define
define|#
directive|define
name|CE1_H_CLK
value|91
end_define

begin_define
define|#
directive|define
name|CE1_CORE_CLK
value|92
end_define

begin_define
define|#
directive|define
name|CE1_SLEEP_CLK
value|93
end_define

begin_define
define|#
directive|define
name|CE2_H_CLK
value|94
end_define

begin_define
define|#
directive|define
name|CE2_CORE_CLK
value|95
end_define

begin_define
define|#
directive|define
name|SFPB_H_CLK_SRC
value|97
end_define

begin_define
define|#
directive|define
name|SFPB_H_CLK
value|98
end_define

begin_define
define|#
directive|define
name|SFAB_SFPB_M_H_CLK
value|99
end_define

begin_define
define|#
directive|define
name|SFAB_SFPB_S_H_CLK
value|100
end_define

begin_define
define|#
directive|define
name|RPM_PROC_CLK
value|101
end_define

begin_define
define|#
directive|define
name|RPM_BUS_H_CLK
value|102
end_define

begin_define
define|#
directive|define
name|RPM_SLEEP_CLK
value|103
end_define

begin_define
define|#
directive|define
name|RPM_TIMER_CLK
value|104
end_define

begin_define
define|#
directive|define
name|RPM_MSG_RAM_H_CLK
value|105
end_define

begin_define
define|#
directive|define
name|PMIC_ARB0_H_CLK
value|106
end_define

begin_define
define|#
directive|define
name|PMIC_ARB1_H_CLK
value|107
end_define

begin_define
define|#
directive|define
name|PMIC_SSBI2_SRC
value|108
end_define

begin_define
define|#
directive|define
name|PMIC_SSBI2_CLK
value|109
end_define

begin_define
define|#
directive|define
name|SDC1_H_CLK
value|110
end_define

begin_define
define|#
directive|define
name|SDC2_H_CLK
value|111
end_define

begin_define
define|#
directive|define
name|SDC3_H_CLK
value|112
end_define

begin_define
define|#
directive|define
name|SDC4_H_CLK
value|113
end_define

begin_define
define|#
directive|define
name|SDC5_H_CLK
value|114
end_define

begin_define
define|#
directive|define
name|SDC1_SRC
value|115
end_define

begin_define
define|#
directive|define
name|SDC2_SRC
value|116
end_define

begin_define
define|#
directive|define
name|SDC3_SRC
value|117
end_define

begin_define
define|#
directive|define
name|SDC4_SRC
value|118
end_define

begin_define
define|#
directive|define
name|SDC5_SRC
value|119
end_define

begin_define
define|#
directive|define
name|SDC1_CLK
value|120
end_define

begin_define
define|#
directive|define
name|SDC2_CLK
value|121
end_define

begin_define
define|#
directive|define
name|SDC3_CLK
value|122
end_define

begin_define
define|#
directive|define
name|SDC4_CLK
value|123
end_define

begin_define
define|#
directive|define
name|SDC5_CLK
value|124
end_define

begin_define
define|#
directive|define
name|DFAB_A2_H_CLK
value|125
end_define

begin_define
define|#
directive|define
name|USB_HS1_H_CLK
value|126
end_define

begin_define
define|#
directive|define
name|USB_HS1_XCVR_SRC
value|127
end_define

begin_define
define|#
directive|define
name|USB_HS1_XCVR_CLK
value|128
end_define

begin_define
define|#
directive|define
name|USB_HSIC_H_CLK
value|129
end_define

begin_define
define|#
directive|define
name|USB_HSIC_XCVR_FS_SRC
value|130
end_define

begin_define
define|#
directive|define
name|USB_HSIC_XCVR_FS_CLK
value|131
end_define

begin_define
define|#
directive|define
name|USB_HSIC_SYSTEM_CLK_SRC
value|132
end_define

begin_define
define|#
directive|define
name|USB_HSIC_SYSTEM_CLK
value|133
end_define

begin_define
define|#
directive|define
name|CFPB0_C0_H_CLK
value|134
end_define

begin_define
define|#
directive|define
name|CFPB0_C1_H_CLK
value|135
end_define

begin_define
define|#
directive|define
name|CFPB0_D0_H_CLK
value|136
end_define

begin_define
define|#
directive|define
name|CFPB0_D1_H_CLK
value|137
end_define

begin_define
define|#
directive|define
name|USB_FS1_H_CLK
value|138
end_define

begin_define
define|#
directive|define
name|USB_FS1_XCVR_FS_SRC
value|139
end_define

begin_define
define|#
directive|define
name|USB_FS1_XCVR_FS_CLK
value|140
end_define

begin_define
define|#
directive|define
name|USB_FS1_SYSTEM_CLK
value|141
end_define

begin_define
define|#
directive|define
name|USB_FS2_H_CLK
value|142
end_define

begin_define
define|#
directive|define
name|USB_FS2_XCVR_FS_SRC
value|143
end_define

begin_define
define|#
directive|define
name|USB_FS2_XCVR_FS_CLK
value|144
end_define

begin_define
define|#
directive|define
name|USB_FS2_SYSTEM_CLK
value|145
end_define

begin_define
define|#
directive|define
name|GSBI_COMMON_SIM_SRC
value|146
end_define

begin_define
define|#
directive|define
name|GSBI1_H_CLK
value|147
end_define

begin_define
define|#
directive|define
name|GSBI2_H_CLK
value|148
end_define

begin_define
define|#
directive|define
name|GSBI3_H_CLK
value|149
end_define

begin_define
define|#
directive|define
name|GSBI4_H_CLK
value|150
end_define

begin_define
define|#
directive|define
name|GSBI5_H_CLK
value|151
end_define

begin_define
define|#
directive|define
name|GSBI6_H_CLK
value|152
end_define

begin_define
define|#
directive|define
name|GSBI7_H_CLK
value|153
end_define

begin_define
define|#
directive|define
name|GSBI8_H_CLK
value|154
end_define

begin_define
define|#
directive|define
name|GSBI9_H_CLK
value|155
end_define

begin_define
define|#
directive|define
name|GSBI10_H_CLK
value|156
end_define

begin_define
define|#
directive|define
name|GSBI11_H_CLK
value|157
end_define

begin_define
define|#
directive|define
name|GSBI12_H_CLK
value|158
end_define

begin_define
define|#
directive|define
name|GSBI1_UART_SRC
value|159
end_define

begin_define
define|#
directive|define
name|GSBI1_UART_CLK
value|160
end_define

begin_define
define|#
directive|define
name|GSBI2_UART_SRC
value|161
end_define

begin_define
define|#
directive|define
name|GSBI2_UART_CLK
value|162
end_define

begin_define
define|#
directive|define
name|GSBI3_UART_SRC
value|163
end_define

begin_define
define|#
directive|define
name|GSBI3_UART_CLK
value|164
end_define

begin_define
define|#
directive|define
name|GSBI4_UART_SRC
value|165
end_define

begin_define
define|#
directive|define
name|GSBI4_UART_CLK
value|166
end_define

begin_define
define|#
directive|define
name|GSBI5_UART_SRC
value|167
end_define

begin_define
define|#
directive|define
name|GSBI5_UART_CLK
value|168
end_define

begin_define
define|#
directive|define
name|GSBI6_UART_SRC
value|169
end_define

begin_define
define|#
directive|define
name|GSBI6_UART_CLK
value|170
end_define

begin_define
define|#
directive|define
name|GSBI7_UART_SRC
value|171
end_define

begin_define
define|#
directive|define
name|GSBI7_UART_CLK
value|172
end_define

begin_define
define|#
directive|define
name|GSBI8_UART_SRC
value|173
end_define

begin_define
define|#
directive|define
name|GSBI8_UART_CLK
value|174
end_define

begin_define
define|#
directive|define
name|GSBI9_UART_SRC
value|175
end_define

begin_define
define|#
directive|define
name|GSBI9_UART_CLK
value|176
end_define

begin_define
define|#
directive|define
name|GSBI10_UART_SRC
value|177
end_define

begin_define
define|#
directive|define
name|GSBI10_UART_CLK
value|178
end_define

begin_define
define|#
directive|define
name|GSBI11_UART_SRC
value|179
end_define

begin_define
define|#
directive|define
name|GSBI11_UART_CLK
value|180
end_define

begin_define
define|#
directive|define
name|GSBI12_UART_SRC
value|181
end_define

begin_define
define|#
directive|define
name|GSBI12_UART_CLK
value|182
end_define

begin_define
define|#
directive|define
name|GSBI1_QUP_SRC
value|183
end_define

begin_define
define|#
directive|define
name|GSBI1_QUP_CLK
value|184
end_define

begin_define
define|#
directive|define
name|GSBI2_QUP_SRC
value|185
end_define

begin_define
define|#
directive|define
name|GSBI2_QUP_CLK
value|186
end_define

begin_define
define|#
directive|define
name|GSBI3_QUP_SRC
value|187
end_define

begin_define
define|#
directive|define
name|GSBI3_QUP_CLK
value|188
end_define

begin_define
define|#
directive|define
name|GSBI4_QUP_SRC
value|189
end_define

begin_define
define|#
directive|define
name|GSBI4_QUP_CLK
value|190
end_define

begin_define
define|#
directive|define
name|GSBI5_QUP_SRC
value|191
end_define

begin_define
define|#
directive|define
name|GSBI5_QUP_CLK
value|192
end_define

begin_define
define|#
directive|define
name|GSBI6_QUP_SRC
value|193
end_define

begin_define
define|#
directive|define
name|GSBI6_QUP_CLK
value|194
end_define

begin_define
define|#
directive|define
name|GSBI7_QUP_SRC
value|195
end_define

begin_define
define|#
directive|define
name|GSBI7_QUP_CLK
value|196
end_define

begin_define
define|#
directive|define
name|GSBI8_QUP_SRC
value|197
end_define

begin_define
define|#
directive|define
name|GSBI8_QUP_CLK
value|198
end_define

begin_define
define|#
directive|define
name|GSBI9_QUP_SRC
value|199
end_define

begin_define
define|#
directive|define
name|GSBI9_QUP_CLK
value|200
end_define

begin_define
define|#
directive|define
name|GSBI10_QUP_SRC
value|201
end_define

begin_define
define|#
directive|define
name|GSBI10_QUP_CLK
value|202
end_define

begin_define
define|#
directive|define
name|GSBI11_QUP_SRC
value|203
end_define

begin_define
define|#
directive|define
name|GSBI11_QUP_CLK
value|204
end_define

begin_define
define|#
directive|define
name|GSBI12_QUP_SRC
value|205
end_define

begin_define
define|#
directive|define
name|GSBI12_QUP_CLK
value|206
end_define

begin_define
define|#
directive|define
name|GSBI1_SIM_CLK
value|207
end_define

begin_define
define|#
directive|define
name|GSBI2_SIM_CLK
value|208
end_define

begin_define
define|#
directive|define
name|GSBI3_SIM_CLK
value|209
end_define

begin_define
define|#
directive|define
name|GSBI4_SIM_CLK
value|210
end_define

begin_define
define|#
directive|define
name|GSBI5_SIM_CLK
value|211
end_define

begin_define
define|#
directive|define
name|GSBI6_SIM_CLK
value|212
end_define

begin_define
define|#
directive|define
name|GSBI7_SIM_CLK
value|213
end_define

begin_define
define|#
directive|define
name|GSBI8_SIM_CLK
value|214
end_define

begin_define
define|#
directive|define
name|GSBI9_SIM_CLK
value|215
end_define

begin_define
define|#
directive|define
name|GSBI10_SIM_CLK
value|216
end_define

begin_define
define|#
directive|define
name|GSBI11_SIM_CLK
value|217
end_define

begin_define
define|#
directive|define
name|GSBI12_SIM_CLK
value|218
end_define

begin_define
define|#
directive|define
name|USB_HSIC_HSIC_CLK_SRC
value|219
end_define

begin_define
define|#
directive|define
name|USB_HSIC_HSIC_CLK
value|220
end_define

begin_define
define|#
directive|define
name|USB_HSIC_HSIO_CAL_CLK
value|221
end_define

begin_define
define|#
directive|define
name|SPDM_CFG_H_CLK
value|222
end_define

begin_define
define|#
directive|define
name|SPDM_MSTR_H_CLK
value|223
end_define

begin_define
define|#
directive|define
name|SPDM_FF_CLK_SRC
value|224
end_define

begin_define
define|#
directive|define
name|SPDM_FF_CLK
value|225
end_define

begin_define
define|#
directive|define
name|SEC_CTRL_CLK
value|226
end_define

begin_define
define|#
directive|define
name|SEC_CTRL_ACC_CLK_SRC
value|227
end_define

begin_define
define|#
directive|define
name|SEC_CTRL_ACC_CLK
value|228
end_define

begin_define
define|#
directive|define
name|TLMM_H_CLK
value|229
end_define

begin_define
define|#
directive|define
name|TLMM_CLK
value|230
end_define

begin_define
define|#
directive|define
name|SFAB_MSS_S_H_CLK
value|231
end_define

begin_define
define|#
directive|define
name|MSS_SLP_CLK
value|232
end_define

begin_define
define|#
directive|define
name|MSS_Q6SW_JTAG_CLK
value|233
end_define

begin_define
define|#
directive|define
name|MSS_Q6FW_JTAG_CLK
value|234
end_define

begin_define
define|#
directive|define
name|MSS_S_H_CLK
value|235
end_define

begin_define
define|#
directive|define
name|MSS_CXO_SRC_CLK
value|236
end_define

begin_define
define|#
directive|define
name|SATA_H_CLK
value|237
end_define

begin_define
define|#
directive|define
name|SATA_CLK_SRC
value|238
end_define

begin_define
define|#
directive|define
name|SATA_RXOOB_CLK
value|239
end_define

begin_define
define|#
directive|define
name|SATA_PMALIVE_CLK
value|240
end_define

begin_define
define|#
directive|define
name|SATA_PHY_REF_CLK
value|241
end_define

begin_define
define|#
directive|define
name|TSSC_CLK_SRC
value|242
end_define

begin_define
define|#
directive|define
name|TSSC_CLK
value|243
end_define

begin_define
define|#
directive|define
name|PDM_SRC
value|244
end_define

begin_define
define|#
directive|define
name|PDM_CLK
value|245
end_define

begin_define
define|#
directive|define
name|GP0_SRC
value|246
end_define

begin_define
define|#
directive|define
name|GP0_CLK
value|247
end_define

begin_define
define|#
directive|define
name|GP1_SRC
value|248
end_define

begin_define
define|#
directive|define
name|GP1_CLK
value|249
end_define

begin_define
define|#
directive|define
name|GP2_SRC
value|250
end_define

begin_define
define|#
directive|define
name|GP2_CLK
value|251
end_define

begin_define
define|#
directive|define
name|MPM_CLK
value|252
end_define

begin_define
define|#
directive|define
name|EBI1_CLK_SRC
value|253
end_define

begin_define
define|#
directive|define
name|EBI1_CH0_CLK
value|254
end_define

begin_define
define|#
directive|define
name|EBI1_CH1_CLK
value|255
end_define

begin_define
define|#
directive|define
name|EBI1_2X_CLK
value|256
end_define

begin_define
define|#
directive|define
name|EBI1_CH0_DQ_CLK
value|257
end_define

begin_define
define|#
directive|define
name|EBI1_CH1_DQ_CLK
value|258
end_define

begin_define
define|#
directive|define
name|EBI1_CH0_CA_CLK
value|259
end_define

begin_define
define|#
directive|define
name|EBI1_CH1_CA_CLK
value|260
end_define

begin_define
define|#
directive|define
name|EBI1_XO_CLK
value|261
end_define

begin_define
define|#
directive|define
name|SFAB_SMPSS_S_H_CLK
value|262
end_define

begin_define
define|#
directive|define
name|PRNG_SRC
value|263
end_define

begin_define
define|#
directive|define
name|PRNG_CLK
value|264
end_define

begin_define
define|#
directive|define
name|PXO_SRC
value|265
end_define

begin_define
define|#
directive|define
name|LPASS_CXO_CLK
value|266
end_define

begin_define
define|#
directive|define
name|LPASS_PXO_CLK
value|267
end_define

begin_define
define|#
directive|define
name|SPDM_CY_PORT0_CLK
value|268
end_define

begin_define
define|#
directive|define
name|SPDM_CY_PORT1_CLK
value|269
end_define

begin_define
define|#
directive|define
name|SPDM_CY_PORT2_CLK
value|270
end_define

begin_define
define|#
directive|define
name|SPDM_CY_PORT3_CLK
value|271
end_define

begin_define
define|#
directive|define
name|SPDM_CY_PORT4_CLK
value|272
end_define

begin_define
define|#
directive|define
name|SPDM_CY_PORT5_CLK
value|273
end_define

begin_define
define|#
directive|define
name|SPDM_CY_PORT6_CLK
value|274
end_define

begin_define
define|#
directive|define
name|SPDM_CY_PORT7_CLK
value|275
end_define

begin_define
define|#
directive|define
name|PLL0
value|276
end_define

begin_define
define|#
directive|define
name|PLL0_VOTE
value|277
end_define

begin_define
define|#
directive|define
name|PLL3
value|278
end_define

begin_define
define|#
directive|define
name|PLL3_VOTE
value|279
end_define

begin_define
define|#
directive|define
name|PLL4_VOTE
value|280
end_define

begin_define
define|#
directive|define
name|PLL5
value|281
end_define

begin_define
define|#
directive|define
name|PLL5_VOTE
value|282
end_define

begin_define
define|#
directive|define
name|PLL6
value|283
end_define

begin_define
define|#
directive|define
name|PLL6_VOTE
value|284
end_define

begin_define
define|#
directive|define
name|PLL7_VOTE
value|285
end_define

begin_define
define|#
directive|define
name|PLL8
value|286
end_define

begin_define
define|#
directive|define
name|PLL8_VOTE
value|287
end_define

begin_define
define|#
directive|define
name|PLL9
value|288
end_define

begin_define
define|#
directive|define
name|PLL10
value|289
end_define

begin_define
define|#
directive|define
name|PLL11
value|290
end_define

begin_define
define|#
directive|define
name|PLL12
value|291
end_define

begin_define
define|#
directive|define
name|PLL13
value|292
end_define

begin_define
define|#
directive|define
name|PLL14
value|293
end_define

begin_define
define|#
directive|define
name|PLL14_VOTE
value|294
end_define

begin_define
define|#
directive|define
name|USB_HS3_H_CLK
value|295
end_define

begin_define
define|#
directive|define
name|USB_HS3_XCVR_SRC
value|296
end_define

begin_define
define|#
directive|define
name|USB_HS3_XCVR_CLK
value|297
end_define

begin_define
define|#
directive|define
name|USB_HS4_H_CLK
value|298
end_define

begin_define
define|#
directive|define
name|USB_HS4_XCVR_SRC
value|299
end_define

begin_define
define|#
directive|define
name|USB_HS4_XCVR_CLK
value|300
end_define

begin_define
define|#
directive|define
name|SATA_PHY_CFG_CLK
value|301
end_define

begin_define
define|#
directive|define
name|SATA_A_CLK
value|302
end_define

begin_define
define|#
directive|define
name|CE3_SRC
value|303
end_define

begin_define
define|#
directive|define
name|CE3_CORE_CLK
value|304
end_define

begin_define
define|#
directive|define
name|CE3_H_CLK
value|305
end_define

begin_define
define|#
directive|define
name|USB_HS1_SYSTEM_CLK_SRC
value|306
end_define

begin_define
define|#
directive|define
name|USB_HS1_SYSTEM_CLK
value|307
end_define

begin_define
define|#
directive|define
name|EBI2_CLK
value|308
end_define

begin_define
define|#
directive|define
name|EBI2_AON_CLK
value|309
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

