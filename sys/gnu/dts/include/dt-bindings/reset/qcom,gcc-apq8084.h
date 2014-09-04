begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2014, The Linux Foundation. All rights reserved.  *  * This software is licensed under the terms of the GNU General Public  * License version 2, as published by the Free Software Foundation, and  * may be copied, distributed, and modified under those terms.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_RESET_APQ_GCC_8084_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_RESET_APQ_GCC_8084_H
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
name|GCC_QDSS_BCR
value|5
end_define

begin_define
define|#
directive|define
name|GCC_USB_30_BCR
value|6
end_define

begin_define
define|#
directive|define
name|GCC_USB3_PHY_BCR
value|7
end_define

begin_define
define|#
directive|define
name|GCC_USB_HS_HSIC_BCR
value|8
end_define

begin_define
define|#
directive|define
name|GCC_USB_HS_BCR
value|9
end_define

begin_define
define|#
directive|define
name|GCC_USB2A_PHY_BCR
value|10
end_define

begin_define
define|#
directive|define
name|GCC_USB2B_PHY_BCR
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
name|GCC_BAM_DMA_BCR
value|44
end_define

begin_define
define|#
directive|define
name|GCC_TSIF_BCR
value|45
end_define

begin_define
define|#
directive|define
name|GCC_TCSR_BCR
value|46
end_define

begin_define
define|#
directive|define
name|GCC_BOOT_ROM_BCR
value|47
end_define

begin_define
define|#
directive|define
name|GCC_MSG_RAM_BCR
value|48
end_define

begin_define
define|#
directive|define
name|GCC_TLMM_BCR
value|49
end_define

begin_define
define|#
directive|define
name|GCC_MPM_BCR
value|50
end_define

begin_define
define|#
directive|define
name|GCC_MPM_AHB_RESET
value|51
end_define

begin_define
define|#
directive|define
name|GCC_MPM_NON_AHB_RESET
value|52
end_define

begin_define
define|#
directive|define
name|GCC_SEC_CTRL_BCR
value|53
end_define

begin_define
define|#
directive|define
name|GCC_SPMI_BCR
value|54
end_define

begin_define
define|#
directive|define
name|GCC_SPDM_BCR
value|55
end_define

begin_define
define|#
directive|define
name|GCC_CE1_BCR
value|56
end_define

begin_define
define|#
directive|define
name|GCC_CE2_BCR
value|57
end_define

begin_define
define|#
directive|define
name|GCC_BIMC_BCR
value|58
end_define

begin_define
define|#
directive|define
name|GCC_SNOC_BUS_TIMEOUT0_BCR
value|59
end_define

begin_define
define|#
directive|define
name|GCC_SNOC_BUS_TIMEOUT2_BCR
value|60
end_define

begin_define
define|#
directive|define
name|GCC_PNOC_BUS_TIMEOUT0_BCR
value|61
end_define

begin_define
define|#
directive|define
name|GCC_PNOC_BUS_TIMEOUT1_BCR
value|62
end_define

begin_define
define|#
directive|define
name|GCC_PNOC_BUS_TIMEOUT2_BCR
value|63
end_define

begin_define
define|#
directive|define
name|GCC_PNOC_BUS_TIMEOUT3_BCR
value|64
end_define

begin_define
define|#
directive|define
name|GCC_PNOC_BUS_TIMEOUT4_BCR
value|65
end_define

begin_define
define|#
directive|define
name|GCC_CNOC_BUS_TIMEOUT0_BCR
value|66
end_define

begin_define
define|#
directive|define
name|GCC_CNOC_BUS_TIMEOUT1_BCR
value|67
end_define

begin_define
define|#
directive|define
name|GCC_CNOC_BUS_TIMEOUT2_BCR
value|68
end_define

begin_define
define|#
directive|define
name|GCC_CNOC_BUS_TIMEOUT3_BCR
value|69
end_define

begin_define
define|#
directive|define
name|GCC_CNOC_BUS_TIMEOUT4_BCR
value|70
end_define

begin_define
define|#
directive|define
name|GCC_CNOC_BUS_TIMEOUT5_BCR
value|71
end_define

begin_define
define|#
directive|define
name|GCC_CNOC_BUS_TIMEOUT6_BCR
value|72
end_define

begin_define
define|#
directive|define
name|GCC_DEHR_BCR
value|73
end_define

begin_define
define|#
directive|define
name|GCC_RBCPR_BCR
value|74
end_define

begin_define
define|#
directive|define
name|GCC_MSS_RESTART
value|75
end_define

begin_define
define|#
directive|define
name|GCC_LPASS_RESTART
value|76
end_define

begin_define
define|#
directive|define
name|GCC_WCSS_RESTART
value|77
end_define

begin_define
define|#
directive|define
name|GCC_VENUS_RESTART
value|78
end_define

begin_define
define|#
directive|define
name|GCC_COPSS_SMMU_BCR
value|79
end_define

begin_define
define|#
directive|define
name|GCC_SPSS_BCR
value|80
end_define

begin_define
define|#
directive|define
name|GCC_PCIE_0_BCR
value|81
end_define

begin_define
define|#
directive|define
name|GCC_PCIE_0_PHY_BCR
value|82
end_define

begin_define
define|#
directive|define
name|GCC_PCIE_1_BCR
value|83
end_define

begin_define
define|#
directive|define
name|GCC_PCIE_1_PHY_BCR
value|84
end_define

begin_define
define|#
directive|define
name|GCC_USB_30_SEC_BCR
value|85
end_define

begin_define
define|#
directive|define
name|GCC_USB3_SEC_PHY_BCR
value|86
end_define

begin_define
define|#
directive|define
name|GCC_SATA_BCR
value|87
end_define

begin_define
define|#
directive|define
name|GCC_CE3_BCR
value|88
end_define

begin_define
define|#
directive|define
name|GCC_UFS_BCR
value|89
end_define

begin_define
define|#
directive|define
name|GCC_USB30_PHY_COM_BCR
value|90
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

