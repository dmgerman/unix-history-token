begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2016-2017, The Linux Foundation. All rights reserved.  *  * This software is licensed under the terms of the GNU General Public  * License version 2, as published by the Free Software Foundation, and  * may be copied, distributed, and modified under those terms.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLOCK_IPQ_GCC_8074_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLOCK_IPQ_GCC_8074_H
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
name|GPLL0_MAIN
value|1
end_define

begin_define
define|#
directive|define
name|GCC_SLEEP_CLK_SRC
value|2
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP1_I2C_APPS_CLK_SRC
value|3
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP1_SPI_APPS_CLK_SRC
value|4
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP2_I2C_APPS_CLK_SRC
value|5
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP2_SPI_APPS_CLK_SRC
value|6
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP3_I2C_APPS_CLK_SRC
value|7
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP3_SPI_APPS_CLK_SRC
value|8
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP4_I2C_APPS_CLK_SRC
value|9
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP4_SPI_APPS_CLK_SRC
value|10
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP5_I2C_APPS_CLK_SRC
value|11
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP5_SPI_APPS_CLK_SRC
value|12
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP6_I2C_APPS_CLK_SRC
value|13
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP6_SPI_APPS_CLK_SRC
value|14
end_define

begin_define
define|#
directive|define
name|BLSP1_UART1_APPS_CLK_SRC
value|15
end_define

begin_define
define|#
directive|define
name|BLSP1_UART2_APPS_CLK_SRC
value|16
end_define

begin_define
define|#
directive|define
name|BLSP1_UART3_APPS_CLK_SRC
value|17
end_define

begin_define
define|#
directive|define
name|BLSP1_UART4_APPS_CLK_SRC
value|18
end_define

begin_define
define|#
directive|define
name|BLSP1_UART5_APPS_CLK_SRC
value|19
end_define

begin_define
define|#
directive|define
name|BLSP1_UART6_APPS_CLK_SRC
value|20
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_AHB_CLK
value|21
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP1_I2C_APPS_CLK
value|22
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP1_SPI_APPS_CLK
value|23
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP2_I2C_APPS_CLK
value|24
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP2_SPI_APPS_CLK
value|25
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP3_I2C_APPS_CLK
value|26
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP3_SPI_APPS_CLK
value|27
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP4_I2C_APPS_CLK
value|28
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP4_SPI_APPS_CLK
value|29
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP5_I2C_APPS_CLK
value|30
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP5_SPI_APPS_CLK
value|31
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP6_I2C_APPS_CLK
value|32
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP6_SPI_APPS_CLK
value|33
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART1_APPS_CLK
value|34
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART2_APPS_CLK
value|35
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART3_APPS_CLK
value|36
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART4_APPS_CLK
value|37
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART5_APPS_CLK
value|38
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART6_APPS_CLK
value|39
end_define

begin_define
define|#
directive|define
name|GCC_PRNG_AHB_CLK
value|40
end_define

begin_define
define|#
directive|define
name|GCC_QPIC_AHB_CLK
value|41
end_define

begin_define
define|#
directive|define
name|GCC_QPIC_CLK
value|42
end_define

begin_define
define|#
directive|define
name|PCNOC_BFDCD_CLK_SRC
value|43
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_BCR
value|0
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP1_BCR
value|1
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART1_BCR
value|2
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP2_BCR
value|3
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART2_BCR
value|4
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP3_BCR
value|5
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART3_BCR
value|6
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP4_BCR
value|7
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART4_BCR
value|8
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP5_BCR
value|9
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART5_BCR
value|10
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP6_BCR
value|11
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART6_BCR
value|12
end_define

begin_define
define|#
directive|define
name|GCC_IMEM_BCR
value|13
end_define

begin_define
define|#
directive|define
name|GCC_SMMU_BCR
value|14
end_define

begin_define
define|#
directive|define
name|GCC_APSS_TCU_BCR
value|15
end_define

begin_define
define|#
directive|define
name|GCC_SMMU_XPU_BCR
value|16
end_define

begin_define
define|#
directive|define
name|GCC_PCNOC_TBU_BCR
value|17
end_define

begin_define
define|#
directive|define
name|GCC_SMMU_CFG_BCR
value|18
end_define

begin_define
define|#
directive|define
name|GCC_PRNG_BCR
value|19
end_define

begin_define
define|#
directive|define
name|GCC_BOOT_ROM_BCR
value|20
end_define

begin_define
define|#
directive|define
name|GCC_CRYPTO_BCR
value|21
end_define

begin_define
define|#
directive|define
name|GCC_WCSS_BCR
value|22
end_define

begin_define
define|#
directive|define
name|GCC_WCSS_Q6_BCR
value|23
end_define

begin_define
define|#
directive|define
name|GCC_NSS_BCR
value|24
end_define

begin_define
define|#
directive|define
name|GCC_SEC_CTRL_BCR
value|25
end_define

begin_define
define|#
directive|define
name|GCC_ADSS_BCR
value|26
end_define

begin_define
define|#
directive|define
name|GCC_DDRSS_BCR
value|27
end_define

begin_define
define|#
directive|define
name|GCC_SYSTEM_NOC_BCR
value|28
end_define

begin_define
define|#
directive|define
name|GCC_PCNOC_BCR
value|29
end_define

begin_define
define|#
directive|define
name|GCC_TCSR_BCR
value|30
end_define

begin_define
define|#
directive|define
name|GCC_QDSS_BCR
value|31
end_define

begin_define
define|#
directive|define
name|GCC_DCD_BCR
value|32
end_define

begin_define
define|#
directive|define
name|GCC_MSG_RAM_BCR
value|33
end_define

begin_define
define|#
directive|define
name|GCC_MPM_BCR
value|34
end_define

begin_define
define|#
directive|define
name|GCC_SPMI_BCR
value|35
end_define

begin_define
define|#
directive|define
name|GCC_SPDM_BCR
value|36
end_define

begin_define
define|#
directive|define
name|GCC_RBCPR_BCR
value|37
end_define

begin_define
define|#
directive|define
name|GCC_RBCPR_MX_BCR
value|38
end_define

begin_define
define|#
directive|define
name|GCC_TLMM_BCR
value|39
end_define

begin_define
define|#
directive|define
name|GCC_RBCPR_WCSS_BCR
value|40
end_define

begin_define
define|#
directive|define
name|GCC_USB0_PHY_BCR
value|41
end_define

begin_define
define|#
directive|define
name|GCC_USB3PHY_0_PHY_BCR
value|42
end_define

begin_define
define|#
directive|define
name|GCC_USB0_BCR
value|43
end_define

begin_define
define|#
directive|define
name|GCC_USB1_PHY_BCR
value|44
end_define

begin_define
define|#
directive|define
name|GCC_USB3PHY_1_PHY_BCR
value|45
end_define

begin_define
define|#
directive|define
name|GCC_USB1_BCR
value|46
end_define

begin_define
define|#
directive|define
name|GCC_QUSB2_0_PHY_BCR
value|47
end_define

begin_define
define|#
directive|define
name|GCC_QUSB2_1_PHY_BCR
value|48
end_define

begin_define
define|#
directive|define
name|GCC_SDCC1_BCR
value|49
end_define

begin_define
define|#
directive|define
name|GCC_SDCC2_BCR
value|50
end_define

begin_define
define|#
directive|define
name|GCC_SNOC_BUS_TIMEOUT0_BCR
value|51
end_define

begin_define
define|#
directive|define
name|GCC_SNOC_BUS_TIMEOUT2_BCR
value|52
end_define

begin_define
define|#
directive|define
name|GCC_SNOC_BUS_TIMEOUT3_BCR
value|53
end_define

begin_define
define|#
directive|define
name|GCC_PCNOC_BUS_TIMEOUT0_BCR
value|54
end_define

begin_define
define|#
directive|define
name|GCC_PCNOC_BUS_TIMEOUT1_BCR
value|55
end_define

begin_define
define|#
directive|define
name|GCC_PCNOC_BUS_TIMEOUT2_BCR
value|56
end_define

begin_define
define|#
directive|define
name|GCC_PCNOC_BUS_TIMEOUT3_BCR
value|57
end_define

begin_define
define|#
directive|define
name|GCC_PCNOC_BUS_TIMEOUT4_BCR
value|58
end_define

begin_define
define|#
directive|define
name|GCC_PCNOC_BUS_TIMEOUT5_BCR
value|59
end_define

begin_define
define|#
directive|define
name|GCC_PCNOC_BUS_TIMEOUT6_BCR
value|60
end_define

begin_define
define|#
directive|define
name|GCC_PCNOC_BUS_TIMEOUT7_BCR
value|61
end_define

begin_define
define|#
directive|define
name|GCC_PCNOC_BUS_TIMEOUT8_BCR
value|62
end_define

begin_define
define|#
directive|define
name|GCC_PCNOC_BUS_TIMEOUT9_BCR
value|63
end_define

begin_define
define|#
directive|define
name|GCC_UNIPHY0_BCR
value|64
end_define

begin_define
define|#
directive|define
name|GCC_UNIPHY1_BCR
value|65
end_define

begin_define
define|#
directive|define
name|GCC_UNIPHY2_BCR
value|66
end_define

begin_define
define|#
directive|define
name|GCC_CMN_12GPLL_BCR
value|67
end_define

begin_define
define|#
directive|define
name|GCC_QPIC_BCR
value|68
end_define

begin_define
define|#
directive|define
name|GCC_MDIO_BCR
value|69
end_define

begin_define
define|#
directive|define
name|GCC_PCIE1_TBU_BCR
value|70
end_define

begin_define
define|#
directive|define
name|GCC_WCSS_CORE_TBU_BCR
value|71
end_define

begin_define
define|#
directive|define
name|GCC_WCSS_Q6_TBU_BCR
value|72
end_define

begin_define
define|#
directive|define
name|GCC_USB0_TBU_BCR
value|73
end_define

begin_define
define|#
directive|define
name|GCC_USB1_TBU_BCR
value|74
end_define

begin_define
define|#
directive|define
name|GCC_PCIE0_TBU_BCR
value|75
end_define

begin_define
define|#
directive|define
name|GCC_NSS_NOC_TBU_BCR
value|76
end_define

begin_define
define|#
directive|define
name|GCC_PCIE0_BCR
value|77
end_define

begin_define
define|#
directive|define
name|GCC_PCIE0_PHY_BCR
value|78
end_define

begin_define
define|#
directive|define
name|GCC_PCIE0PHY_PHY_BCR
value|79
end_define

begin_define
define|#
directive|define
name|GCC_PCIE0_LINK_DOWN_BCR
value|80
end_define

begin_define
define|#
directive|define
name|GCC_PCIE1_BCR
value|81
end_define

begin_define
define|#
directive|define
name|GCC_PCIE1_PHY_BCR
value|82
end_define

begin_define
define|#
directive|define
name|GCC_PCIE1PHY_PHY_BCR
value|83
end_define

begin_define
define|#
directive|define
name|GCC_PCIE1_LINK_DOWN_BCR
value|84
end_define

begin_define
define|#
directive|define
name|GCC_DCC_BCR
value|85
end_define

begin_define
define|#
directive|define
name|GCC_APC0_VOLTAGE_DROOP_DETECTOR_BCR
value|86
end_define

begin_define
define|#
directive|define
name|GCC_APC1_VOLTAGE_DROOP_DETECTOR_BCR
value|87
end_define

begin_define
define|#
directive|define
name|GCC_SMMU_CATS_BCR
value|88
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

