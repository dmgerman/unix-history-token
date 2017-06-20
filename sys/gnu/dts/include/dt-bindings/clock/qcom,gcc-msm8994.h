begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2016, The Linux Foundation. All rights reserved.  *  * This software is licensed under the terms of the GNU General Public  * License version 2, as published by the Free Software Foundation, and  * may be copied, distributed, and modified under those terms.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLK_MSM_GCC_8994_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLK_MSM_GCC_8994_H
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
name|GPLL4_EARLY
value|2
end_define

begin_define
define|#
directive|define
name|GPLL4
value|3
end_define

begin_define
define|#
directive|define
name|UFS_AXI_CLK_SRC
value|4
end_define

begin_define
define|#
directive|define
name|USB30_MASTER_CLK_SRC
value|5
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP1_I2C_APPS_CLK_SRC
value|6
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP1_SPI_APPS_CLK_SRC
value|7
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP2_I2C_APPS_CLK_SRC
value|8
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP2_SPI_APPS_CLK_SRC
value|9
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP3_I2C_APPS_CLK_SRC
value|10
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP3_SPI_APPS_CLK_SRC
value|11
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP4_I2C_APPS_CLK_SRC
value|12
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP4_SPI_APPS_CLK_SRC
value|13
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP5_I2C_APPS_CLK_SRC
value|14
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP5_SPI_APPS_CLK_SRC
value|15
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP6_I2C_APPS_CLK_SRC
value|16
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP6_SPI_APPS_CLK_SRC
value|17
end_define

begin_define
define|#
directive|define
name|BLSP1_UART1_APPS_CLK_SRC
value|18
end_define

begin_define
define|#
directive|define
name|BLSP1_UART2_APPS_CLK_SRC
value|19
end_define

begin_define
define|#
directive|define
name|BLSP1_UART3_APPS_CLK_SRC
value|20
end_define

begin_define
define|#
directive|define
name|BLSP1_UART4_APPS_CLK_SRC
value|21
end_define

begin_define
define|#
directive|define
name|BLSP1_UART5_APPS_CLK_SRC
value|22
end_define

begin_define
define|#
directive|define
name|BLSP1_UART6_APPS_CLK_SRC
value|23
end_define

begin_define
define|#
directive|define
name|BLSP2_QUP1_I2C_APPS_CLK_SRC
value|24
end_define

begin_define
define|#
directive|define
name|BLSP2_QUP1_SPI_APPS_CLK_SRC
value|25
end_define

begin_define
define|#
directive|define
name|BLSP2_QUP2_I2C_APPS_CLK_SRC
value|26
end_define

begin_define
define|#
directive|define
name|BLSP2_QUP2_SPI_APPS_CLK_SRC
value|27
end_define

begin_define
define|#
directive|define
name|BLSP2_QUP3_I2C_APPS_CLK_SRC
value|28
end_define

begin_define
define|#
directive|define
name|BLSP2_QUP3_SPI_APPS_CLK_SRC
value|29
end_define

begin_define
define|#
directive|define
name|BLSP2_QUP4_I2C_APPS_CLK_SRC
value|30
end_define

begin_define
define|#
directive|define
name|BLSP2_QUP4_SPI_APPS_CLK_SRC
value|31
end_define

begin_define
define|#
directive|define
name|BLSP2_QUP5_I2C_APPS_CLK_SRC
value|32
end_define

begin_define
define|#
directive|define
name|BLSP2_QUP5_SPI_APPS_CLK_SRC
value|33
end_define

begin_define
define|#
directive|define
name|BLSP2_QUP6_I2C_APPS_CLK_SRC
value|34
end_define

begin_define
define|#
directive|define
name|BLSP2_QUP6_SPI_APPS_CLK_SRC
value|35
end_define

begin_define
define|#
directive|define
name|BLSP2_UART1_APPS_CLK_SRC
value|36
end_define

begin_define
define|#
directive|define
name|BLSP2_UART2_APPS_CLK_SRC
value|37
end_define

begin_define
define|#
directive|define
name|BLSP2_UART3_APPS_CLK_SRC
value|38
end_define

begin_define
define|#
directive|define
name|BLSP2_UART4_APPS_CLK_SRC
value|39
end_define

begin_define
define|#
directive|define
name|BLSP2_UART5_APPS_CLK_SRC
value|40
end_define

begin_define
define|#
directive|define
name|BLSP2_UART6_APPS_CLK_SRC
value|41
end_define

begin_define
define|#
directive|define
name|GP1_CLK_SRC
value|42
end_define

begin_define
define|#
directive|define
name|GP2_CLK_SRC
value|43
end_define

begin_define
define|#
directive|define
name|GP3_CLK_SRC
value|44
end_define

begin_define
define|#
directive|define
name|PCIE_0_AUX_CLK_SRC
value|45
end_define

begin_define
define|#
directive|define
name|PCIE_0_PIPE_CLK_SRC
value|46
end_define

begin_define
define|#
directive|define
name|PCIE_1_AUX_CLK_SRC
value|47
end_define

begin_define
define|#
directive|define
name|PCIE_1_PIPE_CLK_SRC
value|48
end_define

begin_define
define|#
directive|define
name|PDM2_CLK_SRC
value|49
end_define

begin_define
define|#
directive|define
name|SDCC1_APPS_CLK_SRC
value|50
end_define

begin_define
define|#
directive|define
name|SDCC2_APPS_CLK_SRC
value|51
end_define

begin_define
define|#
directive|define
name|SDCC3_APPS_CLK_SRC
value|52
end_define

begin_define
define|#
directive|define
name|SDCC4_APPS_CLK_SRC
value|53
end_define

begin_define
define|#
directive|define
name|TSIF_REF_CLK_SRC
value|54
end_define

begin_define
define|#
directive|define
name|USB30_MOCK_UTMI_CLK_SRC
value|55
end_define

begin_define
define|#
directive|define
name|USB3_PHY_AUX_CLK_SRC
value|56
end_define

begin_define
define|#
directive|define
name|USB_HS_SYSTEM_CLK_SRC
value|57
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_AHB_CLK
value|58
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP1_I2C_APPS_CLK
value|59
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP1_SPI_APPS_CLK
value|60
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP2_I2C_APPS_CLK
value|61
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP2_SPI_APPS_CLK
value|62
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP3_I2C_APPS_CLK
value|63
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP3_SPI_APPS_CLK
value|64
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP4_I2C_APPS_CLK
value|65
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP4_SPI_APPS_CLK
value|66
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP5_I2C_APPS_CLK
value|67
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP5_SPI_APPS_CLK
value|68
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP6_I2C_APPS_CLK
value|69
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP6_SPI_APPS_CLK
value|70
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART1_APPS_CLK
value|71
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART2_APPS_CLK
value|72
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART3_APPS_CLK
value|73
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART4_APPS_CLK
value|74
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART5_APPS_CLK
value|75
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART6_APPS_CLK
value|76
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_AHB_CLK
value|77
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP1_I2C_APPS_CLK
value|78
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP1_SPI_APPS_CLK
value|79
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP2_I2C_APPS_CLK
value|80
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP2_SPI_APPS_CLK
value|81
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP3_I2C_APPS_CLK
value|82
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP3_SPI_APPS_CLK
value|83
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP4_I2C_APPS_CLK
value|84
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP4_SPI_APPS_CLK
value|85
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP5_I2C_APPS_CLK
value|86
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP5_SPI_APPS_CLK
value|87
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP6_I2C_APPS_CLK
value|88
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_QUP6_SPI_APPS_CLK
value|89
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_UART1_APPS_CLK
value|90
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_UART2_APPS_CLK
value|91
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_UART3_APPS_CLK
value|92
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_UART4_APPS_CLK
value|93
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_UART5_APPS_CLK
value|94
end_define

begin_define
define|#
directive|define
name|GCC_BLSP2_UART6_APPS_CLK
value|95
end_define

begin_define
define|#
directive|define
name|GCC_GP1_CLK
value|96
end_define

begin_define
define|#
directive|define
name|GCC_GP2_CLK
value|97
end_define

begin_define
define|#
directive|define
name|GCC_GP3_CLK
value|98
end_define

begin_define
define|#
directive|define
name|GCC_PCIE_0_AUX_CLK
value|99
end_define

begin_define
define|#
directive|define
name|GCC_PCIE_0_PIPE_CLK
value|100
end_define

begin_define
define|#
directive|define
name|GCC_PCIE_1_AUX_CLK
value|101
end_define

begin_define
define|#
directive|define
name|GCC_PCIE_1_PIPE_CLK
value|102
end_define

begin_define
define|#
directive|define
name|GCC_PDM2_CLK
value|103
end_define

begin_define
define|#
directive|define
name|GCC_SDCC1_APPS_CLK
value|104
end_define

begin_define
define|#
directive|define
name|GCC_SDCC2_APPS_CLK
value|105
end_define

begin_define
define|#
directive|define
name|GCC_SDCC3_APPS_CLK
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
name|GCC_SYS_NOC_UFS_AXI_CLK
value|108
end_define

begin_define
define|#
directive|define
name|GCC_SYS_NOC_USB3_AXI_CLK
value|109
end_define

begin_define
define|#
directive|define
name|GCC_TSIF_REF_CLK
value|110
end_define

begin_define
define|#
directive|define
name|GCC_UFS_AXI_CLK
value|111
end_define

begin_define
define|#
directive|define
name|GCC_UFS_RX_CFG_CLK
value|112
end_define

begin_define
define|#
directive|define
name|GCC_UFS_TX_CFG_CLK
value|113
end_define

begin_define
define|#
directive|define
name|GCC_USB30_MASTER_CLK
value|114
end_define

begin_define
define|#
directive|define
name|GCC_USB30_MOCK_UTMI_CLK
value|115
end_define

begin_define
define|#
directive|define
name|GCC_USB3_PHY_AUX_CLK
value|116
end_define

begin_define
define|#
directive|define
name|GCC_USB_HS_SYSTEM_CLK
value|117
end_define

begin_define
define|#
directive|define
name|GCC_SDCC1_AHB_CLK
value|118
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

