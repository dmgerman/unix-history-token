begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2015, The Linux Foundation. All rights reserved.  *  * This software is licensed under the terms of the GNU General Public  * License version 2, as published by the Free Software Foundation, and  * may be copied, distributed, and modified under those terms.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLK_MSM_GCC_8996_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLK_MSM_GCC_8996_H
end_define

begin_define
define|#
directive|define
name|GPLL0_EARLY
value|0
end_define

begin_define
define|#
directive|define
name|GPLL0
value|1
end_define

begin_define
define|#
directive|define
name|GPLL1_EARLY
value|2
end_define

begin_define
define|#
directive|define
name|GPLL1
value|3
end_define

begin_define
define|#
directive|define
name|GPLL2_EARLY
value|4
end_define

begin_define
define|#
directive|define
name|GPLL2
value|5
end_define

begin_define
define|#
directive|define
name|GPLL3_EARLY
value|6
end_define

begin_define
define|#
directive|define
name|GPLL3
value|7
end_define

begin_define
define|#
directive|define
name|GPLL4_EARLY
value|8
end_define

begin_define
define|#
directive|define
name|GPLL4
value|9
end_define

begin_define
define|#
directive|define
name|SYSTEM_NOC_CLK_SRC
value|10
end_define

begin_define
define|#
directive|define
name|CONFIG_NOC_CLK_SRC
value|11
end_define

begin_define
define|#
directive|define
name|PERIPH_NOC_CLK_SRC
value|12
end_define

begin_define
define|#
directive|define
name|MMSS_BIMC_GFX_CLK_SRC
value|13
end_define

begin_define
define|#
directive|define
name|USB30_MASTER_CLK_SRC
value|14
end_define

begin_define
define|#
directive|define
name|USB30_MOCK_UTMI_CLK_SRC
value|15
end_define

begin_define
define|#
directive|define
name|USB3_PHY_AUX_CLK_SRC
value|16
end_define

begin_define
define|#
directive|define
name|USB20_MASTER_CLK_SRC
value|17
end_define

begin_define
define|#
directive|define
name|USB20_MOCK_UTMI_CLK_SRC
value|18
end_define

begin_define
define|#
directive|define
name|SDCC1_APPS_CLK_SRC
value|19
end_define

begin_define
define|#
directive|define
name|SDCC1_ICE_CORE_CLK_SRC
value|20
end_define

begin_define
define|#
directive|define
name|SDCC2_APPS_CLK_SRC
value|21
end_define

begin_define
define|#
directive|define
name|SDCC3_APPS_CLK_SRC
value|22
end_define

begin_define
define|#
directive|define
name|SDCC4_APPS_CLK_SRC
value|23
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP1_SPI_APPS_CLK_SRC
value|24
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP1_I2C_APPS_CLK_SRC
value|25
end_define

begin_define
define|#
directive|define
name|BLSP1_UART1_APPS_CLK_SRC
value|26
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP2_SPI_APPS_CLK_SRC
value|27
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP2_I2C_APPS_CLK_SRC
value|28
end_define

begin_define
define|#
directive|define
name|BLSP1_UART2_APPS_CLK_SRC
value|29
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP3_SPI_APPS_CLK_SRC
value|30
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP3_I2C_APPS_CLK_SRC
value|31
end_define

begin_define
define|#
directive|define
name|BLSP1_UART3_APPS_CLK_SRC
value|32
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP4_SPI_APPS_CLK_SRC
value|33
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP4_I2C_APPS_CLK_SRC
value|34
end_define

begin_define
define|#
directive|define
name|BLSP1_UART4_APPS_CLK_SRC
value|35
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP5_SPI_APPS_CLK_SRC
value|36
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP5_I2C_APPS_CLK_SRC
value|37
end_define

begin_define
define|#
directive|define
name|BLSP1_UART5_APPS_CLK_SRC
value|38
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP6_SPI_APPS_CLK_SRC
value|39
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP6_I2C_APPS_CLK_SRC
value|40
end_define

begin_define
define|#
directive|define
name|BLSP1_UART6_APPS_CLK_SRC
value|41
end_define

begin_define
define|#
directive|define
name|BLSP2_QUP1_SPI_APPS_CLK_SRC
value|42
end_define

begin_define
define|#
directive|define
name|BLSP2_QUP1_I2C_APPS_CLK_SRC
value|43
end_define

begin_define
define|#
directive|define
name|BLSP2_UART1_APPS_CLK_SRC
value|44
end_define

begin_define
define|#
directive|define
name|BLSP2_QUP2_SPI_APPS_CLK_SRC
value|45
end_define

begin_define
define|#
directive|define
name|BLSP2_QUP2_I2C_APPS_CLK_SRC
value|46
end_define

begin_define
define|#
directive|define
name|BLSP2_UART2_APPS_CLK_SRC
value|47
end_define

begin_define
define|#
directive|define
name|BLSP2_QUP3_SPI_APPS_CLK_SRC
value|48
end_define

begin_define
define|#
directive|define
name|BLSP2_QUP3_I2C_APPS_CLK_SRC
value|49
end_define

begin_define
define|#
directive|define
name|BLSP2_UART3_APPS_CLK_SRC
value|50
end_define

begin_define
define|#
directive|define
name|BLSP2_QUP4_SPI_APPS_CLK_SRC
value|51
end_define

begin_define
define|#
directive|define
name|BLSP2_QUP4_I2C_APPS_CLK_SRC
value|52
end_define

begin_define
define|#
directive|define
name|BLSP2_UART4_APPS_CLK_SRC
value|53
end_define

begin_define
define|#
directive|define
name|BLSP2_QUP5_SPI_APPS_CLK_SRC
value|54
end_define

begin_define
define|#
directive|define
name|BLSP2_QUP5_I2C_APPS_CLK_SRC
value|55
end_define

begin_define
define|#
directive|define
name|BLSP2_UART5_APPS_CLK_SRC
value|56
end_define

begin_define
define|#
directive|define
name|BLSP2_QUP6_SPI_APPS_CLK_SRC
value|57
end_define

begin_define
define|#
directive|define
name|BLSP2_QUP6_I2C_APPS_CLK_SRC
value|58
end_define

begin_define
define|#
directive|define
name|BLSP2_UART6_APPS_CLK_SRC
value|59
end_define

begin_define
define|#
directive|define
name|PDM2_CLK_SRC
value|60
end_define

begin_define
define|#
directive|define
name|TSIF_REF_CLK_SRC
value|61
end_define

begin_define
define|#
directive|define
name|CE1_CLK_SRC
value|62
end_define

begin_define
define|#
directive|define
name|GCC_SLEEP_CLK_SRC
value|63
end_define

begin_define
define|#
directive|define
name|BIMC_CLK_SRC
value|64
end_define

begin_define
define|#
directive|define
name|HMSS_AHB_CLK_SRC
value|65
end_define

begin_define
define|#
directive|define
name|BIMC_HMSS_AXI_CLK_SRC
value|66
end_define

begin_define
define|#
directive|define
name|HMSS_RBCPR_CLK_SRC
value|67
end_define

begin_define
define|#
directive|define
name|HMSS_GPLL0_CLK_SRC
value|68
end_define

begin_define
define|#
directive|define
name|GP1_CLK_SRC
value|69
end_define

begin_define
define|#
directive|define
name|GP2_CLK_SRC
value|70
end_define

begin_define
define|#
directive|define
name|GP3_CLK_SRC
value|71
end_define

begin_define
define|#
directive|define
name|PCIE_AUX_CLK_SRC
value|72
end_define

begin_define
define|#
directive|define
name|UFS_AXI_CLK_SRC
value|73
end_define

begin_define
define|#
directive|define
name|UFS_ICE_CORE_CLK_SRC
value|74
end_define

begin_define
define|#
directive|define
name|QSPI_SER_CLK_SRC
value|75
end_define

begin_define
define|#
directive|define
name|GCC_SYS_NOC_AXI_CLK
value|76
end_define

begin_define
define|#
directive|define
name|GCC_SYS_NOC_HMSS_AHB_CLK
value|77
end_define

begin_define
define|#
directive|define
name|GCC_SNOC_CNOC_AHB_CLK
value|78
end_define

begin_define
define|#
directive|define
name|GCC_SNOC_PNOC_AHB_CLK
value|79
end_define

begin_define
define|#
directive|define
name|GCC_SYS_NOC_AT_CLK
value|80
end_define

begin_define
define|#
directive|define
name|GCC_SYS_NOC_USB3_AXI_CLK
value|81
end_define

begin_define
define|#
directive|define
name|GCC_SYS_NOC_UFS_AXI_CLK
value|82
end_define

begin_define
define|#
directive|define
name|GCC_CFG_NOC_AHB_CLK
value|83
end_define

begin_define
define|#
directive|define
name|GCC_PERIPH_NOC_AHB_CLK
value|84
end_define

begin_define
define|#
directive|define
name|GCC_PERIPH_NOC_USB20_AHB_CLK
value|85
end_define

begin_define
define|#
directive|define
name|GCC_TIC_CLK
value|86
end_define

begin_define
define|#
directive|define
name|GCC_IMEM_AXI_CLK
value|87
end_define

begin_define
define|#
directive|define
name|GCC_MMSS_SYS_NOC_AXI_CLK
value|88
end_define

begin_define
define|#
directive|define
name|GCC_MMSS_NOC_CFG_AHB_CLK
value|89
end_define

begin_define
define|#
directive|define
name|GCC_MMSS_BIMC_GFX_CLK
value|90
end_define

begin_define
define|#
directive|define
name|GCC_USB30_MASTER_CLK
value|91
end_define

begin_define
define|#
directive|define
name|GCC_USB30_SLEEP_CLK
value|92
end_define

begin_define
define|#
directive|define
name|GCC_USB30_MOCK_UTMI_CLK
value|93
end_define

begin_define
define|#
directive|define
name|GCC_USB3_PHY_AUX_CLK
value|94
end_define

begin_define
define|#
directive|define
name|GCC_USB3_PHY_PIPE_CLK
value|95
end_define

begin_define
define|#
directive|define
name|GCC_USB20_MASTER_CLK
value|96
end_define

begin_define
define|#
directive|define
name|GCC_USB20_SLEEP_CLK
value|97
end_define

begin_define
define|#
directive|define
name|GCC_USB20_MOCK_UTMI_CLK
value|98
end_define

begin_define
define|#
directive|define
name|GCC_USB_PHY_CFG_AHB2PHY_CLK
value|99
end_define

begin_define
define|#
directive|define
name|GCC_SDCC1_APPS_CLK
value|100
end_define

begin_define
define|#
directive|define
name|GCC_SDCC1_AHB_CLK
value|101
end_define

begin_define
define|#
directive|define
name|GCC_SDCC1_ICE_CORE_CLK
value|102
end_define

begin_define
define|#
directive|define
name|GCC_SDCC2_APPS_CLK
value|103
end_define

begin_define
define|#
directive|define
name|GCC_SDCC2_AHB_CLK
value|104
end_define

begin_define
define|#
directive|define
name|GCC_SDCC3_APPS_CLK
value|105
end_define

begin_define
define|#
directive|define
name|GCC_SDCC3_AHB_CLK
value|106
end_define

begin_define
define|#
directive|define
name|GCC_SDCC4_APPS_CLK
value|107
end_define

begin_define
define|#
directive|define
name|GCC_SDCC4_AHB_CLK
value|108
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_AHB_CLK
value|109
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_SLEEP_CLK
value|110
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP1_SPI_APPS_CLK
value|111
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP1_I2C_APPS_CLK
value|112
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART1_APPS_CLK
value|113
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP2_SPI_APPS_CLK
value|114
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP2_I2C_APPS_CLK
value|115
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART2_APPS_CLK
value|116
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP3_SPI_APPS_CLK
value|117
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP3_I2C_APPS_CLK
value|118
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART3_APPS_CLK
value|119
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP4_SPI_APPS_CLK
value|120
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP4_I2C_APPS_CLK
value|121
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART4_APPS_CLK
value|122
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP5_SPI_APPS_CLK
value|123
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP5_I2C_APPS_CLK
value|124
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART5_APPS_CLK
value|125
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP6_SPI_APPS_CLK
value|126
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP6_I2C_APPS_CLK
value|127
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART6_APPS_CLK
value|128
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_AHB_CLK
value|129
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_SLEEP_CLK
value|130
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP1_SPI_APPS_CLK
value|131
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP1_I2C_APPS_CLK
value|132
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_UART1_APPS_CLK
value|133
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP2_SPI_APPS_CLK
value|134
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP2_I2C_APPS_CLK
value|135
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_UART2_APPS_CLK
value|136
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP3_SPI_APPS_CLK
value|137
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP3_I2C_APPS_CLK
value|138
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_UART3_APPS_CLK
value|139
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP4_SPI_APPS_CLK
value|140
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP4_I2C_APPS_CLK
value|141
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_UART4_APPS_CLK
value|142
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP5_SPI_APPS_CLK
value|143
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP5_I2C_APPS_CLK
value|144
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_UART5_APPS_CLK
value|145
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP6_SPI_APPS_CLK
value|146
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP6_I2C_APPS_CLK
value|147
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_UART6_APPS_CLK
value|148
end_define

begin_define
define|#
directive|define
name|GCC_PDM_AHB_CLK
value|149
end_define

begin_define
define|#
directive|define
name|GCC_PDM_XO4_CLK
value|150
end_define

begin_define
define|#
directive|define
name|GCC_PDM2_CLK
value|151
end_define

begin_define
define|#
directive|define
name|GCC_PRNG_AHB_CLK
value|152
end_define

begin_define
define|#
directive|define
name|GCC_TSIF_AHB_CLK
value|153
end_define

begin_define
define|#
directive|define
name|GCC_TSIF_REF_CLK
value|154
end_define

begin_define
define|#
directive|define
name|GCC_TSIF_INACTIVITY_TIMERS_CLK
value|155
end_define

begin_define
define|#
directive|define
name|GCC_TCSR_AHB_CLK
value|156
end_define

begin_define
define|#
directive|define
name|GCC_BOOT_ROM_AHB_CLK
value|157
end_define

begin_define
define|#
directive|define
name|GCC_MSG_RAM_AHB_CLK
value|158
end_define

begin_define
define|#
directive|define
name|GCC_TLMM_AHB_CLK
value|159
end_define

begin_define
define|#
directive|define
name|GCC_TLMM_CLK
value|160
end_define

begin_define
define|#
directive|define
name|GCC_MPM_AHB_CLK
value|161
end_define

begin_define
define|#
directive|define
name|GCC_SPMI_SER_CLK
value|162
end_define

begin_define
define|#
directive|define
name|GCC_SPMI_CNOC_AHB_CLK
value|163
end_define

begin_define
define|#
directive|define
name|GCC_CE1_CLK
value|164
end_define

begin_define
define|#
directive|define
name|GCC_CE1_AXI_CLK
value|165
end_define

begin_define
define|#
directive|define
name|GCC_CE1_AHB_CLK
value|166
end_define

begin_define
define|#
directive|define
name|GCC_BIMC_HMSS_AXI_CLK
value|167
end_define

begin_define
define|#
directive|define
name|GCC_BIMC_GFX_CLK
value|168
end_define

begin_define
define|#
directive|define
name|GCC_HMSS_AHB_CLK
value|169
end_define

begin_define
define|#
directive|define
name|GCC_HMSS_SLV_AXI_CLK
value|170
end_define

begin_define
define|#
directive|define
name|GCC_HMSS_MSTR_AXI_CLK
value|171
end_define

begin_define
define|#
directive|define
name|GCC_HMSS_RBCPR_CLK
value|172
end_define

begin_define
define|#
directive|define
name|GCC_GP1_CLK
value|173
end_define

begin_define
define|#
directive|define
name|GCC_GP2_CLK
value|174
end_define

begin_define
define|#
directive|define
name|GCC_GP3_CLK
value|175
end_define

begin_define
define|#
directive|define
name|GCC_PCIE_0_SLV_AXI_CLK
value|176
end_define

begin_define
define|#
directive|define
name|GCC_PCIE_0_MSTR_AXI_CLK
value|177
end_define

begin_define
define|#
directive|define
name|GCC_PCIE_0_CFG_AHB_CLK
value|178
end_define

begin_define
define|#
directive|define
name|GCC_PCIE_0_AUX_CLK
value|179
end_define

begin_define
define|#
directive|define
name|GCC_PCIE_0_PIPE_CLK
value|180
end_define

begin_define
define|#
directive|define
name|GCC_PCIE_1_SLV_AXI_CLK
value|181
end_define

begin_define
define|#
directive|define
name|GCC_PCIE_1_MSTR_AXI_CLK
value|182
end_define

begin_define
define|#
directive|define
name|GCC_PCIE_1_CFG_AHB_CLK
value|183
end_define

begin_define
define|#
directive|define
name|GCC_PCIE_1_AUX_CLK
value|184
end_define

begin_define
define|#
directive|define
name|GCC_PCIE_1_PIPE_CLK
value|185
end_define

begin_define
define|#
directive|define
name|GCC_PCIE_2_SLV_AXI_CLK
value|186
end_define

begin_define
define|#
directive|define
name|GCC_PCIE_2_MSTR_AXI_CLK
value|187
end_define

begin_define
define|#
directive|define
name|GCC_PCIE_2_CFG_AHB_CLK
value|188
end_define

begin_define
define|#
directive|define
name|GCC_PCIE_2_AUX_CLK
value|189
end_define

begin_define
define|#
directive|define
name|GCC_PCIE_2_PIPE_CLK
value|190
end_define

begin_define
define|#
directive|define
name|GCC_PCIE_PHY_CFG_AHB_CLK
value|191
end_define

begin_define
define|#
directive|define
name|GCC_PCIE_PHY_AUX_CLK
value|192
end_define

begin_define
define|#
directive|define
name|GCC_UFS_AXI_CLK
value|193
end_define

begin_define
define|#
directive|define
name|GCC_UFS_AHB_CLK
value|194
end_define

begin_define
define|#
directive|define
name|GCC_UFS_TX_CFG_CLK
value|195
end_define

begin_define
define|#
directive|define
name|GCC_UFS_RX_CFG_CLK
value|196
end_define

begin_define
define|#
directive|define
name|GCC_UFS_TX_SYMBOL_0_CLK
value|197
end_define

begin_define
define|#
directive|define
name|GCC_UFS_RX_SYMBOL_0_CLK
value|198
end_define

begin_define
define|#
directive|define
name|GCC_UFS_RX_SYMBOL_1_CLK
value|199
end_define

begin_define
define|#
directive|define
name|GCC_UFS_UNIPRO_CORE_CLK
value|200
end_define

begin_define
define|#
directive|define
name|GCC_UFS_ICE_CORE_CLK
value|201
end_define

begin_define
define|#
directive|define
name|GCC_UFS_SYS_CLK_CORE_CLK
value|202
end_define

begin_define
define|#
directive|define
name|GCC_UFS_TX_SYMBOL_CLK_CORE_CLK
value|203
end_define

begin_define
define|#
directive|define
name|GCC_AGGRE0_SNOC_AXI_CLK
value|204
end_define

begin_define
define|#
directive|define
name|GCC_AGGRE0_CNOC_AHB_CLK
value|205
end_define

begin_define
define|#
directive|define
name|GCC_SMMU_AGGRE0_AXI_CLK
value|206
end_define

begin_define
define|#
directive|define
name|GCC_SMMU_AGGRE0_AHB_CLK
value|207
end_define

begin_define
define|#
directive|define
name|GCC_AGGRE1_PNOC_AHB_CLK
value|208
end_define

begin_define
define|#
directive|define
name|GCC_AGGRE2_UFS_AXI_CLK
value|209
end_define

begin_define
define|#
directive|define
name|GCC_AGGRE2_USB3_AXI_CLK
value|210
end_define

begin_define
define|#
directive|define
name|GCC_QSPI_AHB_CLK
value|211
end_define

begin_define
define|#
directive|define
name|GCC_QSPI_SER_CLK
value|212
end_define

begin_define
define|#
directive|define
name|GCC_USB3_CLKREF_CLK
value|213
end_define

begin_define
define|#
directive|define
name|GCC_HDMI_CLKREF_CLK
value|214
end_define

begin_define
define|#
directive|define
name|GCC_UFS_CLKREF_CLK
value|215
end_define

begin_define
define|#
directive|define
name|GCC_PCIE_CLKREF_CLK
value|216
end_define

begin_define
define|#
directive|define
name|GCC_RX2_USB2_CLKREF_CLK
value|217
end_define

begin_define
define|#
directive|define
name|GCC_RX1_USB2_CLKREF_CLK
value|218
end_define

begin_define
define|#
directive|define
name|GCC_SYSTEM_NOC_BCR
value|0
end_define

begin_define
define|#
directive|define
name|GCC_CONFIG_NOC_BCR
value|1
end_define

begin_define
define|#
directive|define
name|GCC_PERIPH_NOC_BCR
value|2
end_define

begin_define
define|#
directive|define
name|GCC_IMEM_BCR
value|3
end_define

begin_define
define|#
directive|define
name|GCC_MMSS_BCR
value|4
end_define

begin_define
define|#
directive|define
name|GCC_PIMEM_BCR
value|5
end_define

begin_define
define|#
directive|define
name|GCC_QDSS_BCR
value|6
end_define

begin_define
define|#
directive|define
name|GCC_USB_30_BCR
value|7
end_define

begin_define
define|#
directive|define
name|GCC_USB_20_BCR
value|8
end_define

begin_define
define|#
directive|define
name|GCC_QUSB2PHY_PRIM_BCR
value|9
end_define

begin_define
define|#
directive|define
name|GCC_QUSB2PHY_SEC_BCR
value|10
end_define

begin_define
define|#
directive|define
name|GCC_USB_PHY_CFG_AHB2PHY_BCR
value|11
end_define

begin_define
define|#
directive|define
name|GCC_SDCC1_BCR
value|12
end_define

begin_define
define|#
directive|define
name|GCC_SDCC2_BCR
value|13
end_define

begin_define
define|#
directive|define
name|GCC_SDCC3_BCR
value|14
end_define

begin_define
define|#
directive|define
name|GCC_SDCC4_BCR
value|15
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_BCR
value|16
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP1_BCR
value|17
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART1_BCR
value|18
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP2_BCR
value|19
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART2_BCR
value|20
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP3_BCR
value|21
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART3_BCR
value|22
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP4_BCR
value|23
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART4_BCR
value|24
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP5_BCR
value|25
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART5_BCR
value|26
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP6_BCR
value|27
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART6_BCR
value|28
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_BCR
value|29
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP1_BCR
value|30
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_UART1_BCR
value|31
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP2_BCR
value|32
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_UART2_BCR
value|33
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP3_BCR
value|34
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_UART3_BCR
value|35
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP4_BCR
value|36
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_UART4_BCR
value|37
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP5_BCR
value|38
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_UART5_BCR
value|39
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP6_BCR
value|40
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_UART6_BCR
value|41
end_define

begin_define
define|#
directive|define
name|GCC_PDM_BCR
value|42
end_define

begin_define
define|#
directive|define
name|GCC_PRNG_BCR
value|43
end_define

begin_define
define|#
directive|define
name|GCC_TSIF_BCR
value|44
end_define

begin_define
define|#
directive|define
name|GCC_TCSR_BCR
value|45
end_define

begin_define
define|#
directive|define
name|GCC_BOOT_ROM_BCR
value|46
end_define

begin_define
define|#
directive|define
name|GCC_MSG_RAM_BCR
value|47
end_define

begin_define
define|#
directive|define
name|GCC_TLMM_BCR
value|48
end_define

begin_define
define|#
directive|define
name|GCC_MPM_BCR
value|49
end_define

begin_define
define|#
directive|define
name|GCC_SEC_CTRL_BCR
value|50
end_define

begin_define
define|#
directive|define
name|GCC_SPMI_BCR
value|51
end_define

begin_define
define|#
directive|define
name|GCC_SPDM_BCR
value|52
end_define

begin_define
define|#
directive|define
name|GCC_CE1_BCR
value|53
end_define

begin_define
define|#
directive|define
name|GCC_BIMC_BCR
value|54
end_define

begin_define
define|#
directive|define
name|GCC_SNOC_BUS_TIMEOUT0_BCR
value|55
end_define

begin_define
define|#
directive|define
name|GCC_SNOC_BUS_TIMEOUT2_BCR
value|56
end_define

begin_define
define|#
directive|define
name|GCC_SNOC_BUS_TIMEOUT1_BCR
value|57
end_define

begin_define
define|#
directive|define
name|GCC_SNOC_BUS_TIMEOUT3_BCR
value|58
end_define

begin_define
define|#
directive|define
name|GCC_SNOC_BUS_TIMEOUT_EXTREF_BCR
value|59
end_define

begin_define
define|#
directive|define
name|GCC_PNOC_BUS_TIMEOUT0_BCR
value|60
end_define

begin_define
define|#
directive|define
name|GCC_PNOC_BUS_TIMEOUT1_BCR
value|61
end_define

begin_define
define|#
directive|define
name|GCC_PNOC_BUS_TIMEOUT2_BCR
value|62
end_define

begin_define
define|#
directive|define
name|GCC_PNOC_BUS_TIMEOUT3_BCR
value|63
end_define

begin_define
define|#
directive|define
name|GCC_PNOC_BUS_TIMEOUT4_BCR
value|64
end_define

begin_define
define|#
directive|define
name|GCC_CNOC_BUS_TIMEOUT0_BCR
value|65
end_define

begin_define
define|#
directive|define
name|GCC_CNOC_BUS_TIMEOUT1_BCR
value|66
end_define

begin_define
define|#
directive|define
name|GCC_CNOC_BUS_TIMEOUT2_BCR
value|67
end_define

begin_define
define|#
directive|define
name|GCC_CNOC_BUS_TIMEOUT3_BCR
value|68
end_define

begin_define
define|#
directive|define
name|GCC_CNOC_BUS_TIMEOUT4_BCR
value|69
end_define

begin_define
define|#
directive|define
name|GCC_CNOC_BUS_TIMEOUT5_BCR
value|70
end_define

begin_define
define|#
directive|define
name|GCC_CNOC_BUS_TIMEOUT6_BCR
value|71
end_define

begin_define
define|#
directive|define
name|GCC_CNOC_BUS_TIMEOUT7_BCR
value|72
end_define

begin_define
define|#
directive|define
name|GCC_CNOC_BUS_TIMEOUT8_BCR
value|73
end_define

begin_define
define|#
directive|define
name|GCC_CNOC_BUS_TIMEOUT9_BCR
value|74
end_define

begin_define
define|#
directive|define
name|GCC_CNOC_BUS_TIMEOUT_EXTREF_BCR
value|75
end_define

begin_define
define|#
directive|define
name|GCC_APB2JTAG_BCR
value|76
end_define

begin_define
define|#
directive|define
name|GCC_RBCPR_CX_BCR
value|77
end_define

begin_define
define|#
directive|define
name|GCC_RBCPR_MX_BCR
value|78
end_define

begin_define
define|#
directive|define
name|GCC_PCIE_0_BCR
value|79
end_define

begin_define
define|#
directive|define
name|GCC_PCIE_0_PHY_BCR
value|80
end_define

begin_define
define|#
directive|define
name|GCC_PCIE_1_BCR
value|81
end_define

begin_define
define|#
directive|define
name|GCC_PCIE_1_PHY_BCR
value|82
end_define

begin_define
define|#
directive|define
name|GCC_PCIE_2_BCR
value|83
end_define

begin_define
define|#
directive|define
name|GCC_PCIE_2_PHY_BCR
value|84
end_define

begin_define
define|#
directive|define
name|GCC_PCIE_PHY_BCR
value|85
end_define

begin_define
define|#
directive|define
name|GCC_DCD_BCR
value|86
end_define

begin_define
define|#
directive|define
name|GCC_OBT_ODT_BCR
value|87
end_define

begin_define
define|#
directive|define
name|GCC_UFS_BCR
value|88
end_define

begin_define
define|#
directive|define
name|GCC_SSC_BCR
value|89
end_define

begin_define
define|#
directive|define
name|GCC_VS_BCR
value|90
end_define

begin_define
define|#
directive|define
name|GCC_AGGRE0_NOC_BCR
value|91
end_define

begin_define
define|#
directive|define
name|GCC_AGGRE1_NOC_BCR
value|92
end_define

begin_define
define|#
directive|define
name|GCC_AGGRE2_NOC_BCR
value|93
end_define

begin_define
define|#
directive|define
name|GCC_DCC_BCR
value|94
end_define

begin_define
define|#
directive|define
name|GCC_IPA_BCR
value|95
end_define

begin_define
define|#
directive|define
name|GCC_QSPI_BCR
value|96
end_define

begin_define
define|#
directive|define
name|GCC_SKL_BCR
value|97
end_define

begin_define
define|#
directive|define
name|GCC_MSMPU_BCR
value|98
end_define

begin_define
define|#
directive|define
name|GCC_MSS_Q6_BCR
value|99
end_define

begin_define
define|#
directive|define
name|GCC_QREFS_VBG_CAL_BCR
value|100
end_define

begin_define
define|#
directive|define
name|GCC_PCIE_PHY_COM_BCR
value|101
end_define

begin_define
define|#
directive|define
name|GCC_PCIE_PHY_COM_NOCSR_BCR
value|102
end_define

begin_define
define|#
directive|define
name|GCC_USB3_PHY_BCR
value|103
end_define

begin_define
define|#
directive|define
name|GCC_USB3PHY_PHY_BCR
value|104
end_define

begin_define
define|#
directive|define
name|GCC_MSS_RESTART
value|105
end_define

begin_comment
comment|/* Indexes for GDSCs */
end_comment

begin_define
define|#
directive|define
name|AGGRE0_NOC_GDSC
value|0
end_define

begin_define
define|#
directive|define
name|HLOS1_VOTE_AGGRE0_NOC_GDSC
value|1
end_define

begin_define
define|#
directive|define
name|HLOS1_VOTE_LPASS_ADSP_GDSC
value|2
end_define

begin_define
define|#
directive|define
name|HLOS1_VOTE_LPASS_CORE_GDSC
value|3
end_define

begin_define
define|#
directive|define
name|USB30_GDSC
value|4
end_define

begin_define
define|#
directive|define
name|PCIE0_GDSC
value|5
end_define

begin_define
define|#
directive|define
name|PCIE1_GDSC
value|6
end_define

begin_define
define|#
directive|define
name|PCIE2_GDSC
value|7
end_define

begin_define
define|#
directive|define
name|UFS_GDSC
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

