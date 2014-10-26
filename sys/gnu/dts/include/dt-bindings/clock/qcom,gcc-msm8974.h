begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013, The Linux Foundation. All rights reserved.  *  * This software is licensed under the terms of the GNU General Public  * License version 2, as published by the Free Software Foundation, and  * may be copied, distributed, and modified under those terms.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLK_MSM_GCC_8974_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLK_MSM_GCC_8974_H
end_define

begin_define
define|#
directive|define
name|GPLL0
value|0
end_define

begin_define
define|#
directive|define
name|GPLL0_VOTE
value|1
end_define

begin_define
define|#
directive|define
name|CONFIG_NOC_CLK_SRC
value|2
end_define

begin_define
define|#
directive|define
name|GPLL2
value|3
end_define

begin_define
define|#
directive|define
name|GPLL2_VOTE
value|4
end_define

begin_define
define|#
directive|define
name|GPLL3
value|5
end_define

begin_define
define|#
directive|define
name|GPLL3_VOTE
value|6
end_define

begin_define
define|#
directive|define
name|PERIPH_NOC_CLK_SRC
value|7
end_define

begin_define
define|#
directive|define
name|BLSP_UART_SIM_CLK_SRC
value|8
end_define

begin_define
define|#
directive|define
name|QDSS_TSCTR_CLK_SRC
value|9
end_define

begin_define
define|#
directive|define
name|BIMC_DDR_CLK_SRC
value|10
end_define

begin_define
define|#
directive|define
name|SYSTEM_NOC_CLK_SRC
value|11
end_define

begin_define
define|#
directive|define
name|GPLL1
value|12
end_define

begin_define
define|#
directive|define
name|GPLL1_VOTE
value|13
end_define

begin_define
define|#
directive|define
name|RPM_CLK_SRC
value|14
end_define

begin_define
define|#
directive|define
name|GCC_BIMC_CLK
value|15
end_define

begin_define
define|#
directive|define
name|BIMC_DDR_CPLL0_ROOT_CLK_SRC
value|16
end_define

begin_define
define|#
directive|define
name|KPSS_AHB_CLK_SRC
value|17
end_define

begin_define
define|#
directive|define
name|QDSS_AT_CLK_SRC
value|18
end_define

begin_define
define|#
directive|define
name|USB30_MASTER_CLK_SRC
value|19
end_define

begin_define
define|#
directive|define
name|BIMC_DDR_CPLL1_ROOT_CLK_SRC
value|20
end_define

begin_define
define|#
directive|define
name|QDSS_STM_CLK_SRC
value|21
end_define

begin_define
define|#
directive|define
name|ACC_CLK_SRC
value|22
end_define

begin_define
define|#
directive|define
name|SEC_CTRL_CLK_SRC
value|23
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP1_I2C_APPS_CLK_SRC
value|24
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP1_SPI_APPS_CLK_SRC
value|25
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP2_I2C_APPS_CLK_SRC
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
name|BLSP1_QUP3_I2C_APPS_CLK_SRC
value|28
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP3_SPI_APPS_CLK_SRC
value|29
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP4_I2C_APPS_CLK_SRC
value|30
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP4_SPI_APPS_CLK_SRC
value|31
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP5_I2C_APPS_CLK_SRC
value|32
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP5_SPI_APPS_CLK_SRC
value|33
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP6_I2C_APPS_CLK_SRC
value|34
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP6_SPI_APPS_CLK_SRC
value|35
end_define

begin_define
define|#
directive|define
name|BLSP1_UART1_APPS_CLK_SRC
value|36
end_define

begin_define
define|#
directive|define
name|BLSP1_UART2_APPS_CLK_SRC
value|37
end_define

begin_define
define|#
directive|define
name|BLSP1_UART3_APPS_CLK_SRC
value|38
end_define

begin_define
define|#
directive|define
name|BLSP1_UART4_APPS_CLK_SRC
value|39
end_define

begin_define
define|#
directive|define
name|BLSP1_UART5_APPS_CLK_SRC
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
name|BLSP2_QUP1_I2C_APPS_CLK_SRC
value|42
end_define

begin_define
define|#
directive|define
name|BLSP2_QUP1_SPI_APPS_CLK_SRC
value|43
end_define

begin_define
define|#
directive|define
name|BLSP2_QUP2_I2C_APPS_CLK_SRC
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
name|BLSP2_QUP3_I2C_APPS_CLK_SRC
value|46
end_define

begin_define
define|#
directive|define
name|BLSP2_QUP3_SPI_APPS_CLK_SRC
value|47
end_define

begin_define
define|#
directive|define
name|BLSP2_QUP4_I2C_APPS_CLK_SRC
value|48
end_define

begin_define
define|#
directive|define
name|BLSP2_QUP4_SPI_APPS_CLK_SRC
value|49
end_define

begin_define
define|#
directive|define
name|BLSP2_QUP5_I2C_APPS_CLK_SRC
value|50
end_define

begin_define
define|#
directive|define
name|BLSP2_QUP5_SPI_APPS_CLK_SRC
value|51
end_define

begin_define
define|#
directive|define
name|BLSP2_QUP6_I2C_APPS_CLK_SRC
value|52
end_define

begin_define
define|#
directive|define
name|BLSP2_QUP6_SPI_APPS_CLK_SRC
value|53
end_define

begin_define
define|#
directive|define
name|BLSP2_UART1_APPS_CLK_SRC
value|54
end_define

begin_define
define|#
directive|define
name|BLSP2_UART2_APPS_CLK_SRC
value|55
end_define

begin_define
define|#
directive|define
name|BLSP2_UART3_APPS_CLK_SRC
value|56
end_define

begin_define
define|#
directive|define
name|BLSP2_UART4_APPS_CLK_SRC
value|57
end_define

begin_define
define|#
directive|define
name|BLSP2_UART5_APPS_CLK_SRC
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
name|CE1_CLK_SRC
value|60
end_define

begin_define
define|#
directive|define
name|CE2_CLK_SRC
value|61
end_define

begin_define
define|#
directive|define
name|GP1_CLK_SRC
value|62
end_define

begin_define
define|#
directive|define
name|GP2_CLK_SRC
value|63
end_define

begin_define
define|#
directive|define
name|GP3_CLK_SRC
value|64
end_define

begin_define
define|#
directive|define
name|PDM2_CLK_SRC
value|65
end_define

begin_define
define|#
directive|define
name|QDSS_TRACECLKIN_CLK_SRC
value|66
end_define

begin_define
define|#
directive|define
name|RBCPR_CLK_SRC
value|67
end_define

begin_define
define|#
directive|define
name|SDCC1_APPS_CLK_SRC
value|68
end_define

begin_define
define|#
directive|define
name|SDCC2_APPS_CLK_SRC
value|69
end_define

begin_define
define|#
directive|define
name|SDCC3_APPS_CLK_SRC
value|70
end_define

begin_define
define|#
directive|define
name|SDCC4_APPS_CLK_SRC
value|71
end_define

begin_define
define|#
directive|define
name|SPMI_AHB_CLK_SRC
value|72
end_define

begin_define
define|#
directive|define
name|SPMI_SER_CLK_SRC
value|73
end_define

begin_define
define|#
directive|define
name|TSIF_REF_CLK_SRC
value|74
end_define

begin_define
define|#
directive|define
name|USB30_MOCK_UTMI_CLK_SRC
value|75
end_define

begin_define
define|#
directive|define
name|USB_HS_SYSTEM_CLK_SRC
value|76
end_define

begin_define
define|#
directive|define
name|USB_HSIC_CLK_SRC
value|77
end_define

begin_define
define|#
directive|define
name|USB_HSIC_IO_CAL_CLK_SRC
value|78
end_define

begin_define
define|#
directive|define
name|USB_HSIC_SYSTEM_CLK_SRC
value|79
end_define

begin_define
define|#
directive|define
name|GCC_BAM_DMA_AHB_CLK
value|80
end_define

begin_define
define|#
directive|define
name|GCC_BAM_DMA_INACTIVITY_TIMERS_CLK
value|81
end_define

begin_define
define|#
directive|define
name|GCC_BIMC_CFG_AHB_CLK
value|82
end_define

begin_define
define|#
directive|define
name|GCC_BIMC_KPSS_AXI_CLK
value|83
end_define

begin_define
define|#
directive|define
name|GCC_BIMC_SLEEP_CLK
value|84
end_define

begin_define
define|#
directive|define
name|GCC_BIMC_SYSNOC_AXI_CLK
value|85
end_define

begin_define
define|#
directive|define
name|GCC_BIMC_XO_CLK
value|86
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_AHB_CLK
value|87
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_SLEEP_CLK
value|88
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP1_I2C_APPS_CLK
value|89
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP1_SPI_APPS_CLK
value|90
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP2_I2C_APPS_CLK
value|91
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP2_SPI_APPS_CLK
value|92
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP3_I2C_APPS_CLK
value|93
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP3_SPI_APPS_CLK
value|94
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP4_I2C_APPS_CLK
value|95
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP4_SPI_APPS_CLK
value|96
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP5_I2C_APPS_CLK
value|97
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP5_SPI_APPS_CLK
value|98
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP6_I2C_APPS_CLK
value|99
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP6_SPI_APPS_CLK
value|100
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART1_APPS_CLK
value|101
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART1_SIM_CLK
value|102
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART2_APPS_CLK
value|103
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART2_SIM_CLK
value|104
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART3_APPS_CLK
value|105
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART3_SIM_CLK
value|106
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART4_APPS_CLK
value|107
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART4_SIM_CLK
value|108
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART5_APPS_CLK
value|109
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART5_SIM_CLK
value|110
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART6_APPS_CLK
value|111
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART6_SIM_CLK
value|112
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_AHB_CLK
value|113
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_SLEEP_CLK
value|114
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP1_I2C_APPS_CLK
value|115
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP1_SPI_APPS_CLK
value|116
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP2_I2C_APPS_CLK
value|117
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP2_SPI_APPS_CLK
value|118
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP3_I2C_APPS_CLK
value|119
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP3_SPI_APPS_CLK
value|120
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP4_I2C_APPS_CLK
value|121
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP4_SPI_APPS_CLK
value|122
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP5_I2C_APPS_CLK
value|123
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP5_SPI_APPS_CLK
value|124
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP6_I2C_APPS_CLK
value|125
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP6_SPI_APPS_CLK
value|126
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_UART1_APPS_CLK
value|127
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_UART1_SIM_CLK
value|128
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_UART2_APPS_CLK
value|129
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_UART2_SIM_CLK
value|130
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_UART3_APPS_CLK
value|131
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_UART3_SIM_CLK
value|132
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_UART4_APPS_CLK
value|133
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_UART4_SIM_CLK
value|134
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_UART5_APPS_CLK
value|135
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_UART5_SIM_CLK
value|136
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_UART6_APPS_CLK
value|137
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_UART6_SIM_CLK
value|138
end_define

begin_define
define|#
directive|define
name|GCC_BOOT_ROM_AHB_CLK
value|139
end_define

begin_define
define|#
directive|define
name|GCC_CE1_AHB_CLK
value|140
end_define

begin_define
define|#
directive|define
name|GCC_CE1_AXI_CLK
value|141
end_define

begin_define
define|#
directive|define
name|GCC_CE1_CLK
value|142
end_define

begin_define
define|#
directive|define
name|GCC_CE2_AHB_CLK
value|143
end_define

begin_define
define|#
directive|define
name|GCC_CE2_AXI_CLK
value|144
end_define

begin_define
define|#
directive|define
name|GCC_CE2_CLK
value|145
end_define

begin_define
define|#
directive|define
name|GCC_CNOC_BUS_TIMEOUT0_AHB_CLK
value|146
end_define

begin_define
define|#
directive|define
name|GCC_CNOC_BUS_TIMEOUT1_AHB_CLK
value|147
end_define

begin_define
define|#
directive|define
name|GCC_CNOC_BUS_TIMEOUT2_AHB_CLK
value|148
end_define

begin_define
define|#
directive|define
name|GCC_CNOC_BUS_TIMEOUT3_AHB_CLK
value|149
end_define

begin_define
define|#
directive|define
name|GCC_CNOC_BUS_TIMEOUT4_AHB_CLK
value|150
end_define

begin_define
define|#
directive|define
name|GCC_CNOC_BUS_TIMEOUT5_AHB_CLK
value|151
end_define

begin_define
define|#
directive|define
name|GCC_CNOC_BUS_TIMEOUT6_AHB_CLK
value|152
end_define

begin_define
define|#
directive|define
name|GCC_CFG_NOC_AHB_CLK
value|153
end_define

begin_define
define|#
directive|define
name|GCC_CFG_NOC_DDR_CFG_CLK
value|154
end_define

begin_define
define|#
directive|define
name|GCC_CFG_NOC_RPM_AHB_CLK
value|155
end_define

begin_define
define|#
directive|define
name|GCC_BIMC_DDR_CPLL0_CLK
value|156
end_define

begin_define
define|#
directive|define
name|GCC_BIMC_DDR_CPLL1_CLK
value|157
end_define

begin_define
define|#
directive|define
name|GCC_DDR_DIM_CFG_CLK
value|158
end_define

begin_define
define|#
directive|define
name|GCC_DDR_DIM_SLEEP_CLK
value|159
end_define

begin_define
define|#
directive|define
name|GCC_DEHR_CLK
value|160
end_define

begin_define
define|#
directive|define
name|GCC_AHB_CLK
value|161
end_define

begin_define
define|#
directive|define
name|GCC_IM_SLEEP_CLK
value|162
end_define

begin_define
define|#
directive|define
name|GCC_XO_CLK
value|163
end_define

begin_define
define|#
directive|define
name|GCC_XO_DIV4_CLK
value|164
end_define

begin_define
define|#
directive|define
name|GCC_GP1_CLK
value|165
end_define

begin_define
define|#
directive|define
name|GCC_GP2_CLK
value|166
end_define

begin_define
define|#
directive|define
name|GCC_GP3_CLK
value|167
end_define

begin_define
define|#
directive|define
name|GCC_IMEM_AXI_CLK
value|168
end_define

begin_define
define|#
directive|define
name|GCC_IMEM_CFG_AHB_CLK
value|169
end_define

begin_define
define|#
directive|define
name|GCC_KPSS_AHB_CLK
value|170
end_define

begin_define
define|#
directive|define
name|GCC_KPSS_AXI_CLK
value|171
end_define

begin_define
define|#
directive|define
name|GCC_LPASS_Q6_AXI_CLK
value|172
end_define

begin_define
define|#
directive|define
name|GCC_MMSS_NOC_AT_CLK
value|173
end_define

begin_define
define|#
directive|define
name|GCC_MMSS_NOC_CFG_AHB_CLK
value|174
end_define

begin_define
define|#
directive|define
name|GCC_OCMEM_NOC_CFG_AHB_CLK
value|175
end_define

begin_define
define|#
directive|define
name|GCC_OCMEM_SYS_NOC_AXI_CLK
value|176
end_define

begin_define
define|#
directive|define
name|GCC_MPM_AHB_CLK
value|177
end_define

begin_define
define|#
directive|define
name|GCC_MSG_RAM_AHB_CLK
value|178
end_define

begin_define
define|#
directive|define
name|GCC_MSS_CFG_AHB_CLK
value|179
end_define

begin_define
define|#
directive|define
name|GCC_MSS_Q6_BIMC_AXI_CLK
value|180
end_define

begin_define
define|#
directive|define
name|GCC_NOC_CONF_XPU_AHB_CLK
value|181
end_define

begin_define
define|#
directive|define
name|GCC_PDM2_CLK
value|182
end_define

begin_define
define|#
directive|define
name|GCC_PDM_AHB_CLK
value|183
end_define

begin_define
define|#
directive|define
name|GCC_PDM_XO4_CLK
value|184
end_define

begin_define
define|#
directive|define
name|GCC_PERIPH_NOC_AHB_CLK
value|185
end_define

begin_define
define|#
directive|define
name|GCC_PERIPH_NOC_AT_CLK
value|186
end_define

begin_define
define|#
directive|define
name|GCC_PERIPH_NOC_CFG_AHB_CLK
value|187
end_define

begin_define
define|#
directive|define
name|GCC_PERIPH_NOC_MPU_CFG_AHB_CLK
value|188
end_define

begin_define
define|#
directive|define
name|GCC_PERIPH_XPU_AHB_CLK
value|189
end_define

begin_define
define|#
directive|define
name|GCC_PNOC_BUS_TIMEOUT0_AHB_CLK
value|190
end_define

begin_define
define|#
directive|define
name|GCC_PNOC_BUS_TIMEOUT1_AHB_CLK
value|191
end_define

begin_define
define|#
directive|define
name|GCC_PNOC_BUS_TIMEOUT2_AHB_CLK
value|192
end_define

begin_define
define|#
directive|define
name|GCC_PNOC_BUS_TIMEOUT3_AHB_CLK
value|193
end_define

begin_define
define|#
directive|define
name|GCC_PNOC_BUS_TIMEOUT4_AHB_CLK
value|194
end_define

begin_define
define|#
directive|define
name|GCC_PRNG_AHB_CLK
value|195
end_define

begin_define
define|#
directive|define
name|GCC_QDSS_AT_CLK
value|196
end_define

begin_define
define|#
directive|define
name|GCC_QDSS_CFG_AHB_CLK
value|197
end_define

begin_define
define|#
directive|define
name|GCC_QDSS_DAP_AHB_CLK
value|198
end_define

begin_define
define|#
directive|define
name|GCC_QDSS_DAP_CLK
value|199
end_define

begin_define
define|#
directive|define
name|GCC_QDSS_ETR_USB_CLK
value|200
end_define

begin_define
define|#
directive|define
name|GCC_QDSS_STM_CLK
value|201
end_define

begin_define
define|#
directive|define
name|GCC_QDSS_TRACECLKIN_CLK
value|202
end_define

begin_define
define|#
directive|define
name|GCC_QDSS_TSCTR_DIV16_CLK
value|203
end_define

begin_define
define|#
directive|define
name|GCC_QDSS_TSCTR_DIV2_CLK
value|204
end_define

begin_define
define|#
directive|define
name|GCC_QDSS_TSCTR_DIV3_CLK
value|205
end_define

begin_define
define|#
directive|define
name|GCC_QDSS_TSCTR_DIV4_CLK
value|206
end_define

begin_define
define|#
directive|define
name|GCC_QDSS_TSCTR_DIV8_CLK
value|207
end_define

begin_define
define|#
directive|define
name|GCC_QDSS_RBCPR_XPU_AHB_CLK
value|208
end_define

begin_define
define|#
directive|define
name|GCC_RBCPR_AHB_CLK
value|209
end_define

begin_define
define|#
directive|define
name|GCC_RBCPR_CLK
value|210
end_define

begin_define
define|#
directive|define
name|GCC_RPM_BUS_AHB_CLK
value|211
end_define

begin_define
define|#
directive|define
name|GCC_RPM_PROC_HCLK
value|212
end_define

begin_define
define|#
directive|define
name|GCC_RPM_SLEEP_CLK
value|213
end_define

begin_define
define|#
directive|define
name|GCC_RPM_TIMER_CLK
value|214
end_define

begin_define
define|#
directive|define
name|GCC_SDCC1_AHB_CLK
value|215
end_define

begin_define
define|#
directive|define
name|GCC_SDCC1_APPS_CLK
value|216
end_define

begin_define
define|#
directive|define
name|GCC_SDCC1_INACTIVITY_TIMERS_CLK
value|217
end_define

begin_define
define|#
directive|define
name|GCC_SDCC2_AHB_CLK
value|218
end_define

begin_define
define|#
directive|define
name|GCC_SDCC2_APPS_CLK
value|219
end_define

begin_define
define|#
directive|define
name|GCC_SDCC2_INACTIVITY_TIMERS_CLK
value|220
end_define

begin_define
define|#
directive|define
name|GCC_SDCC3_AHB_CLK
value|221
end_define

begin_define
define|#
directive|define
name|GCC_SDCC3_APPS_CLK
value|222
end_define

begin_define
define|#
directive|define
name|GCC_SDCC3_INACTIVITY_TIMERS_CLK
value|223
end_define

begin_define
define|#
directive|define
name|GCC_SDCC4_AHB_CLK
value|224
end_define

begin_define
define|#
directive|define
name|GCC_SDCC4_APPS_CLK
value|225
end_define

begin_define
define|#
directive|define
name|GCC_SDCC4_INACTIVITY_TIMERS_CLK
value|226
end_define

begin_define
define|#
directive|define
name|GCC_SEC_CTRL_ACC_CLK
value|227
end_define

begin_define
define|#
directive|define
name|GCC_SEC_CTRL_AHB_CLK
value|228
end_define

begin_define
define|#
directive|define
name|GCC_SEC_CTRL_BOOT_ROM_PATCH_CLK
value|229
end_define

begin_define
define|#
directive|define
name|GCC_SEC_CTRL_CLK
value|230
end_define

begin_define
define|#
directive|define
name|GCC_SEC_CTRL_SENSE_CLK
value|231
end_define

begin_define
define|#
directive|define
name|GCC_SNOC_BUS_TIMEOUT0_AHB_CLK
value|232
end_define

begin_define
define|#
directive|define
name|GCC_SNOC_BUS_TIMEOUT2_AHB_CLK
value|233
end_define

begin_define
define|#
directive|define
name|GCC_SPDM_BIMC_CY_CLK
value|234
end_define

begin_define
define|#
directive|define
name|GCC_SPDM_CFG_AHB_CLK
value|235
end_define

begin_define
define|#
directive|define
name|GCC_SPDM_DEBUG_CY_CLK
value|236
end_define

begin_define
define|#
directive|define
name|GCC_SPDM_FF_CLK
value|237
end_define

begin_define
define|#
directive|define
name|GCC_SPDM_MSTR_AHB_CLK
value|238
end_define

begin_define
define|#
directive|define
name|GCC_SPDM_PNOC_CY_CLK
value|239
end_define

begin_define
define|#
directive|define
name|GCC_SPDM_RPM_CY_CLK
value|240
end_define

begin_define
define|#
directive|define
name|GCC_SPDM_SNOC_CY_CLK
value|241
end_define

begin_define
define|#
directive|define
name|GCC_SPMI_AHB_CLK
value|242
end_define

begin_define
define|#
directive|define
name|GCC_SPMI_CNOC_AHB_CLK
value|243
end_define

begin_define
define|#
directive|define
name|GCC_SPMI_SER_CLK
value|244
end_define

begin_define
define|#
directive|define
name|GCC_SNOC_CNOC_AHB_CLK
value|245
end_define

begin_define
define|#
directive|define
name|GCC_SNOC_PNOC_AHB_CLK
value|246
end_define

begin_define
define|#
directive|define
name|GCC_SYS_NOC_AT_CLK
value|247
end_define

begin_define
define|#
directive|define
name|GCC_SYS_NOC_AXI_CLK
value|248
end_define

begin_define
define|#
directive|define
name|GCC_SYS_NOC_KPSS_AHB_CLK
value|249
end_define

begin_define
define|#
directive|define
name|GCC_SYS_NOC_QDSS_STM_AXI_CLK
value|250
end_define

begin_define
define|#
directive|define
name|GCC_SYS_NOC_USB3_AXI_CLK
value|251
end_define

begin_define
define|#
directive|define
name|GCC_TCSR_AHB_CLK
value|252
end_define

begin_define
define|#
directive|define
name|GCC_TLMM_AHB_CLK
value|253
end_define

begin_define
define|#
directive|define
name|GCC_TLMM_CLK
value|254
end_define

begin_define
define|#
directive|define
name|GCC_TSIF_AHB_CLK
value|255
end_define

begin_define
define|#
directive|define
name|GCC_TSIF_INACTIVITY_TIMERS_CLK
value|256
end_define

begin_define
define|#
directive|define
name|GCC_TSIF_REF_CLK
value|257
end_define

begin_define
define|#
directive|define
name|GCC_USB2A_PHY_SLEEP_CLK
value|258
end_define

begin_define
define|#
directive|define
name|GCC_USB2B_PHY_SLEEP_CLK
value|259
end_define

begin_define
define|#
directive|define
name|GCC_USB30_MASTER_CLK
value|260
end_define

begin_define
define|#
directive|define
name|GCC_USB30_MOCK_UTMI_CLK
value|261
end_define

begin_define
define|#
directive|define
name|GCC_USB30_SLEEP_CLK
value|262
end_define

begin_define
define|#
directive|define
name|GCC_USB_HS_AHB_CLK
value|263
end_define

begin_define
define|#
directive|define
name|GCC_USB_HS_INACTIVITY_TIMERS_CLK
value|264
end_define

begin_define
define|#
directive|define
name|GCC_USB_HS_SYSTEM_CLK
value|265
end_define

begin_define
define|#
directive|define
name|GCC_USB_HSIC_AHB_CLK
value|266
end_define

begin_define
define|#
directive|define
name|GCC_USB_HSIC_CLK
value|267
end_define

begin_define
define|#
directive|define
name|GCC_USB_HSIC_IO_CAL_CLK
value|268
end_define

begin_define
define|#
directive|define
name|GCC_USB_HSIC_IO_CAL_SLEEP_CLK
value|269
end_define

begin_define
define|#
directive|define
name|GCC_USB_HSIC_SYSTEM_CLK
value|270
end_define

begin_define
define|#
directive|define
name|GCC_WCSS_GPLL1_CLK_SRC
value|271
end_define

begin_define
define|#
directive|define
name|GCC_MMSS_GPLL0_CLK_SRC
value|272
end_define

begin_define
define|#
directive|define
name|GCC_LPASS_GPLL0_CLK_SRC
value|273
end_define

begin_define
define|#
directive|define
name|GCC_WCSS_GPLL1_CLK_SRC_SLEEP_ENA
value|274
end_define

begin_define
define|#
directive|define
name|GCC_MMSS_GPLL0_CLK_SRC_SLEEP_ENA
value|275
end_define

begin_define
define|#
directive|define
name|GCC_LPASS_GPLL0_CLK_SRC_SLEEP_ENA
value|276
end_define

begin_define
define|#
directive|define
name|GCC_IMEM_AXI_CLK_SLEEP_ENA
value|277
end_define

begin_define
define|#
directive|define
name|GCC_SYS_NOC_KPSS_AHB_CLK_SLEEP_ENA
value|278
end_define

begin_define
define|#
directive|define
name|GCC_BIMC_KPSS_AXI_CLK_SLEEP_ENA
value|279
end_define

begin_define
define|#
directive|define
name|GCC_KPSS_AHB_CLK_SLEEP_ENA
value|280
end_define

begin_define
define|#
directive|define
name|GCC_KPSS_AXI_CLK_SLEEP_ENA
value|281
end_define

begin_define
define|#
directive|define
name|GCC_MPM_AHB_CLK_SLEEP_ENA
value|282
end_define

begin_define
define|#
directive|define
name|GCC_OCMEM_SYS_NOC_AXI_CLK_SLEEP_ENA
value|283
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_AHB_CLK_SLEEP_ENA
value|284
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_SLEEP_CLK_SLEEP_ENA
value|285
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_AHB_CLK_SLEEP_ENA
value|286
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_SLEEP_CLK_SLEEP_ENA
value|287
end_define

begin_define
define|#
directive|define
name|GCC_PRNG_AHB_CLK_SLEEP_ENA
value|288
end_define

begin_define
define|#
directive|define
name|GCC_BAM_DMA_AHB_CLK_SLEEP_ENA
value|289
end_define

begin_define
define|#
directive|define
name|GCC_BAM_DMA_INACTIVITY_TIMERS_CLK_SLEEP_ENA
value|290
end_define

begin_define
define|#
directive|define
name|GCC_BOOT_ROM_AHB_CLK_SLEEP_ENA
value|291
end_define

begin_define
define|#
directive|define
name|GCC_MSG_RAM_AHB_CLK_SLEEP_ENA
value|292
end_define

begin_define
define|#
directive|define
name|GCC_TLMM_AHB_CLK_SLEEP_ENA
value|293
end_define

begin_define
define|#
directive|define
name|GCC_TLMM_CLK_SLEEP_ENA
value|294
end_define

begin_define
define|#
directive|define
name|GCC_SPMI_CNOC_AHB_CLK_SLEEP_ENA
value|295
end_define

begin_define
define|#
directive|define
name|GCC_CE1_CLK_SLEEP_ENA
value|296
end_define

begin_define
define|#
directive|define
name|GCC_CE1_AXI_CLK_SLEEP_ENA
value|297
end_define

begin_define
define|#
directive|define
name|GCC_CE1_AHB_CLK_SLEEP_ENA
value|298
end_define

begin_define
define|#
directive|define
name|GCC_CE2_CLK_SLEEP_ENA
value|299
end_define

begin_define
define|#
directive|define
name|GCC_CE2_AXI_CLK_SLEEP_ENA
value|300
end_define

begin_define
define|#
directive|define
name|GCC_CE2_AHB_CLK_SLEEP_ENA
value|301
end_define

begin_define
define|#
directive|define
name|GPLL4
value|302
end_define

begin_define
define|#
directive|define
name|GPLL4_VOTE
value|303
end_define

begin_define
define|#
directive|define
name|GCC_SDCC1_CDCCAL_SLEEP_CLK
value|304
end_define

begin_define
define|#
directive|define
name|GCC_SDCC1_CDCCAL_FF_CLK
value|305
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

