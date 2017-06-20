begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2015 The Linux Foundation. All rights reserved.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__QCOM_CLK_IPQ4019_H__
end_ifndef

begin_define
define|#
directive|define
name|__QCOM_CLK_IPQ4019_H__
end_define

begin_define
define|#
directive|define
name|GCC_DUMMY_CLK
value|0
end_define

begin_define
define|#
directive|define
name|AUDIO_CLK_SRC
value|1
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP1_I2C_APPS_CLK_SRC
value|2
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP1_SPI_APPS_CLK_SRC
value|3
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP2_I2C_APPS_CLK_SRC
value|4
end_define

begin_define
define|#
directive|define
name|BLSP1_QUP2_SPI_APPS_CLK_SRC
value|5
end_define

begin_define
define|#
directive|define
name|BLSP1_UART1_APPS_CLK_SRC
value|6
end_define

begin_define
define|#
directive|define
name|BLSP1_UART2_APPS_CLK_SRC
value|7
end_define

begin_define
define|#
directive|define
name|GCC_USB3_MOCK_UTMI_CLK_SRC
value|8
end_define

begin_define
define|#
directive|define
name|GCC_APPS_CLK_SRC
value|9
end_define

begin_define
define|#
directive|define
name|GCC_APPS_AHB_CLK_SRC
value|10
end_define

begin_define
define|#
directive|define
name|GP1_CLK_SRC
value|11
end_define

begin_define
define|#
directive|define
name|GP2_CLK_SRC
value|12
end_define

begin_define
define|#
directive|define
name|GP3_CLK_SRC
value|13
end_define

begin_define
define|#
directive|define
name|SDCC1_APPS_CLK_SRC
value|14
end_define

begin_define
define|#
directive|define
name|FEPHY_125M_DLY_CLK_SRC
value|15
end_define

begin_define
define|#
directive|define
name|WCSS2G_CLK_SRC
value|16
end_define

begin_define
define|#
directive|define
name|WCSS5G_CLK_SRC
value|17
end_define

begin_define
define|#
directive|define
name|GCC_APSS_AHB_CLK
value|18
end_define

begin_define
define|#
directive|define
name|GCC_AUDIO_AHB_CLK
value|19
end_define

begin_define
define|#
directive|define
name|GCC_AUDIO_PWM_CLK
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
name|GCC_BLSP1_UART1_APPS_CLK
value|26
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART2_APPS_CLK
value|27
end_define

begin_define
define|#
directive|define
name|GCC_DCD_XO_CLK
value|28
end_define

begin_define
define|#
directive|define
name|GCC_GP1_CLK
value|29
end_define

begin_define
define|#
directive|define
name|GCC_GP2_CLK
value|30
end_define

begin_define
define|#
directive|define
name|GCC_GP3_CLK
value|31
end_define

begin_define
define|#
directive|define
name|GCC_BOOT_ROM_AHB_CLK
value|32
end_define

begin_define
define|#
directive|define
name|GCC_CRYPTO_AHB_CLK
value|33
end_define

begin_define
define|#
directive|define
name|GCC_CRYPTO_AXI_CLK
value|34
end_define

begin_define
define|#
directive|define
name|GCC_CRYPTO_CLK
value|35
end_define

begin_define
define|#
directive|define
name|GCC_ESS_CLK
value|36
end_define

begin_define
define|#
directive|define
name|GCC_IMEM_AXI_CLK
value|37
end_define

begin_define
define|#
directive|define
name|GCC_IMEM_CFG_AHB_CLK
value|38
end_define

begin_define
define|#
directive|define
name|GCC_PCIE_AHB_CLK
value|39
end_define

begin_define
define|#
directive|define
name|GCC_PCIE_AXI_M_CLK
value|40
end_define

begin_define
define|#
directive|define
name|GCC_PCIE_AXI_S_CLK
value|41
end_define

begin_define
define|#
directive|define
name|GCC_PCNOC_AHB_CLK
value|42
end_define

begin_define
define|#
directive|define
name|GCC_PRNG_AHB_CLK
value|43
end_define

begin_define
define|#
directive|define
name|GCC_QPIC_AHB_CLK
value|44
end_define

begin_define
define|#
directive|define
name|GCC_QPIC_CLK
value|45
end_define

begin_define
define|#
directive|define
name|GCC_SDCC1_AHB_CLK
value|46
end_define

begin_define
define|#
directive|define
name|GCC_SDCC1_APPS_CLK
value|47
end_define

begin_define
define|#
directive|define
name|GCC_SNOC_PCNOC_AHB_CLK
value|48
end_define

begin_define
define|#
directive|define
name|GCC_SYS_NOC_125M_CLK
value|49
end_define

begin_define
define|#
directive|define
name|GCC_SYS_NOC_AXI_CLK
value|50
end_define

begin_define
define|#
directive|define
name|GCC_TCSR_AHB_CLK
value|51
end_define

begin_define
define|#
directive|define
name|GCC_TLMM_AHB_CLK
value|52
end_define

begin_define
define|#
directive|define
name|GCC_USB2_MASTER_CLK
value|53
end_define

begin_define
define|#
directive|define
name|GCC_USB2_SLEEP_CLK
value|54
end_define

begin_define
define|#
directive|define
name|GCC_USB2_MOCK_UTMI_CLK
value|55
end_define

begin_define
define|#
directive|define
name|GCC_USB3_MASTER_CLK
value|56
end_define

begin_define
define|#
directive|define
name|GCC_USB3_SLEEP_CLK
value|57
end_define

begin_define
define|#
directive|define
name|GCC_USB3_MOCK_UTMI_CLK
value|58
end_define

begin_define
define|#
directive|define
name|GCC_WCSS2G_CLK
value|59
end_define

begin_define
define|#
directive|define
name|GCC_WCSS2G_REF_CLK
value|60
end_define

begin_define
define|#
directive|define
name|GCC_WCSS2G_RTC_CLK
value|61
end_define

begin_define
define|#
directive|define
name|GCC_WCSS5G_CLK
value|62
end_define

begin_define
define|#
directive|define
name|GCC_WCSS5G_REF_CLK
value|63
end_define

begin_define
define|#
directive|define
name|GCC_WCSS5G_RTC_CLK
value|64
end_define

begin_define
define|#
directive|define
name|GCC_APSS_DDRPLL_VCO
value|65
end_define

begin_define
define|#
directive|define
name|GCC_SDCC_PLLDIV_CLK
value|66
end_define

begin_define
define|#
directive|define
name|GCC_FEPLL_VCO
value|67
end_define

begin_define
define|#
directive|define
name|GCC_FEPLL125_CLK
value|68
end_define

begin_define
define|#
directive|define
name|GCC_FEPLL125DLY_CLK
value|69
end_define

begin_define
define|#
directive|define
name|GCC_FEPLL200_CLK
value|70
end_define

begin_define
define|#
directive|define
name|GCC_FEPLL500_CLK
value|71
end_define

begin_define
define|#
directive|define
name|GCC_FEPLL_WCSS2G_CLK
value|72
end_define

begin_define
define|#
directive|define
name|GCC_FEPLL_WCSS5G_CLK
value|73
end_define

begin_define
define|#
directive|define
name|GCC_APSS_CPU_PLLDIV_CLK
value|74
end_define

begin_define
define|#
directive|define
name|GCC_PCNOC_AHB_CLK_SRC
value|75
end_define

begin_define
define|#
directive|define
name|WIFI0_CPU_INIT_RESET
value|0
end_define

begin_define
define|#
directive|define
name|WIFI0_RADIO_SRIF_RESET
value|1
end_define

begin_define
define|#
directive|define
name|WIFI0_RADIO_WARM_RESET
value|2
end_define

begin_define
define|#
directive|define
name|WIFI0_RADIO_COLD_RESET
value|3
end_define

begin_define
define|#
directive|define
name|WIFI0_CORE_WARM_RESET
value|4
end_define

begin_define
define|#
directive|define
name|WIFI0_CORE_COLD_RESET
value|5
end_define

begin_define
define|#
directive|define
name|WIFI1_CPU_INIT_RESET
value|6
end_define

begin_define
define|#
directive|define
name|WIFI1_RADIO_SRIF_RESET
value|7
end_define

begin_define
define|#
directive|define
name|WIFI1_RADIO_WARM_RESET
value|8
end_define

begin_define
define|#
directive|define
name|WIFI1_RADIO_COLD_RESET
value|9
end_define

begin_define
define|#
directive|define
name|WIFI1_CORE_WARM_RESET
value|10
end_define

begin_define
define|#
directive|define
name|WIFI1_CORE_COLD_RESET
value|11
end_define

begin_define
define|#
directive|define
name|USB3_UNIPHY_PHY_ARES
value|12
end_define

begin_define
define|#
directive|define
name|USB3_HSPHY_POR_ARES
value|13
end_define

begin_define
define|#
directive|define
name|USB3_HSPHY_S_ARES
value|14
end_define

begin_define
define|#
directive|define
name|USB2_HSPHY_POR_ARES
value|15
end_define

begin_define
define|#
directive|define
name|USB2_HSPHY_S_ARES
value|16
end_define

begin_define
define|#
directive|define
name|PCIE_PHY_AHB_ARES
value|17
end_define

begin_define
define|#
directive|define
name|PCIE_AHB_ARES
value|18
end_define

begin_define
define|#
directive|define
name|PCIE_PWR_ARES
value|19
end_define

begin_define
define|#
directive|define
name|PCIE_PIPE_STICKY_ARES
value|20
end_define

begin_define
define|#
directive|define
name|PCIE_AXI_M_STICKY_ARES
value|21
end_define

begin_define
define|#
directive|define
name|PCIE_PHY_ARES
value|22
end_define

begin_define
define|#
directive|define
name|PCIE_PARF_XPU_ARES
value|23
end_define

begin_define
define|#
directive|define
name|PCIE_AXI_S_XPU_ARES
value|24
end_define

begin_define
define|#
directive|define
name|PCIE_AXI_M_VMIDMT_ARES
value|25
end_define

begin_define
define|#
directive|define
name|PCIE_PIPE_ARES
value|26
end_define

begin_define
define|#
directive|define
name|PCIE_AXI_S_ARES
value|27
end_define

begin_define
define|#
directive|define
name|PCIE_AXI_M_ARES
value|28
end_define

begin_define
define|#
directive|define
name|ESS_RESET
value|29
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_BCR
value|30
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP1_BCR
value|31
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART1_BCR
value|32
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_QUP2_BCR
value|33
end_define

begin_define
define|#
directive|define
name|GCC_BLSP1_UART2_BCR
value|34
end_define

begin_define
define|#
directive|define
name|GCC_BIMC_BCR
value|35
end_define

begin_define
define|#
directive|define
name|GCC_TLMM_BCR
value|36
end_define

begin_define
define|#
directive|define
name|GCC_IMEM_BCR
value|37
end_define

begin_define
define|#
directive|define
name|GCC_ESS_BCR
value|38
end_define

begin_define
define|#
directive|define
name|GCC_PRNG_BCR
value|39
end_define

begin_define
define|#
directive|define
name|GCC_BOOT_ROM_BCR
value|40
end_define

begin_define
define|#
directive|define
name|GCC_CRYPTO_BCR
value|41
end_define

begin_define
define|#
directive|define
name|GCC_SDCC1_BCR
value|42
end_define

begin_define
define|#
directive|define
name|GCC_SEC_CTRL_BCR
value|43
end_define

begin_define
define|#
directive|define
name|GCC_AUDIO_BCR
value|44
end_define

begin_define
define|#
directive|define
name|GCC_QPIC_BCR
value|45
end_define

begin_define
define|#
directive|define
name|GCC_PCIE_BCR
value|46
end_define

begin_define
define|#
directive|define
name|GCC_USB2_BCR
value|47
end_define

begin_define
define|#
directive|define
name|GCC_USB2_PHY_BCR
value|48
end_define

begin_define
define|#
directive|define
name|GCC_USB3_BCR
value|49
end_define

begin_define
define|#
directive|define
name|GCC_USB3_PHY_BCR
value|50
end_define

begin_define
define|#
directive|define
name|GCC_SYSTEM_NOC_BCR
value|51
end_define

begin_define
define|#
directive|define
name|GCC_PCNOC_BCR
value|52
end_define

begin_define
define|#
directive|define
name|GCC_DCD_BCR
value|53
end_define

begin_define
define|#
directive|define
name|GCC_SNOC_BUS_TIMEOUT0_BCR
value|54
end_define

begin_define
define|#
directive|define
name|GCC_SNOC_BUS_TIMEOUT1_BCR
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
name|GCC_SNOC_BUS_TIMEOUT3_BCR
value|57
end_define

begin_define
define|#
directive|define
name|GCC_PCNOC_BUS_TIMEOUT0_BCR
value|58
end_define

begin_define
define|#
directive|define
name|GCC_PCNOC_BUS_TIMEOUT1_BCR
value|59
end_define

begin_define
define|#
directive|define
name|GCC_PCNOC_BUS_TIMEOUT2_BCR
value|60
end_define

begin_define
define|#
directive|define
name|GCC_PCNOC_BUS_TIMEOUT3_BCR
value|61
end_define

begin_define
define|#
directive|define
name|GCC_PCNOC_BUS_TIMEOUT4_BCR
value|62
end_define

begin_define
define|#
directive|define
name|GCC_PCNOC_BUS_TIMEOUT5_BCR
value|63
end_define

begin_define
define|#
directive|define
name|GCC_PCNOC_BUS_TIMEOUT6_BCR
value|64
end_define

begin_define
define|#
directive|define
name|GCC_PCNOC_BUS_TIMEOUT7_BCR
value|65
end_define

begin_define
define|#
directive|define
name|GCC_PCNOC_BUS_TIMEOUT8_BCR
value|66
end_define

begin_define
define|#
directive|define
name|GCC_PCNOC_BUS_TIMEOUT9_BCR
value|67
end_define

begin_define
define|#
directive|define
name|GCC_TCSR_BCR
value|68
end_define

begin_define
define|#
directive|define
name|GCC_QDSS_BCR
value|69
end_define

begin_define
define|#
directive|define
name|GCC_MPM_BCR
value|70
end_define

begin_define
define|#
directive|define
name|GCC_SPDM_BCR
value|71
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

