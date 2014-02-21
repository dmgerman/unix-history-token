begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Adrian Chadd<adrian@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AR934X_REG_H__
end_ifndef

begin_define
define|#
directive|define
name|__AR934X_REG_H__
end_define

begin_define
define|#
directive|define
name|AR934X_GMAC_BASE
value|(AR71XX_APB_BASE + 0x00070000)
end_define

begin_define
define|#
directive|define
name|AR934X_GMAC_SIZE
value|0x14
end_define

begin_define
define|#
directive|define
name|AR934X_WMAC_BASE
value|(AR71XX_APB_BASE + 0x00100000)
end_define

begin_define
define|#
directive|define
name|AR934X_WMAC_SIZE
value|0x20000
end_define

begin_define
define|#
directive|define
name|AR934X_EHCI_BASE
value|0x1b000000
end_define

begin_define
define|#
directive|define
name|AR934X_EHCI_SIZE
value|0x200
end_define

begin_define
define|#
directive|define
name|AR934X_SRIF_BASE
value|(AR71XX_APB_BASE + 0x00116000)
end_define

begin_define
define|#
directive|define
name|AR934X_SRIF_SIZE
value|0x1000
end_define

begin_comment
comment|/* AR934x GMAC configuration */
end_comment

begin_define
define|#
directive|define
name|AR934X_GMAC_REG_ETH_CFG
value|(AR934X_GMAC_BASE + 0x00)
end_define

begin_define
define|#
directive|define
name|AR934X_ETH_CFG_RGMII_GMAC0
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AR934X_ETH_CFG_MII_GMAC0
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AR934X_ETH_CFG_GMII_GMAC0
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AR934X_ETH_CFG_MII_GMAC0_MASTER
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|AR934X_ETH_CFG_MII_GMAC0_SLAVE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AR934X_ETH_CFG_MII_GMAC0_ERR_EN
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|AR934X_ETH_CFG_SW_ONLY_MODE
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|AR934X_ETH_CFG_SW_PHY_SWAP
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|AR934X_ETH_CFG_SW_APB_ACCESS
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|AR934X_ETH_CFG_RMII_GMAC0
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|AR933X_ETH_CFG_MII_CNTL_SPEED
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|AR934X_ETH_CFG_RMII_GMAC0_MASTER
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|AR934X_ETH_CFG_SW_ACC_MSB_FIRST
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|AR934X_DDR_REG_FLUSH_GE0
value|(AR71XX_APB_BASE + 0x9c)
end_define

begin_define
define|#
directive|define
name|AR934X_DDR_REG_FLUSH_GE1
value|(AR71XX_APB_BASE + 0xa0)
end_define

begin_define
define|#
directive|define
name|AR934X_DDR_REG_FLUSH_USB
value|(AR71XX_APB_BASE + 0xa4)
end_define

begin_define
define|#
directive|define
name|AR934X_DDR_REG_FLUSH_PCIE
value|(AR71XX_APB_BASE + 0xa8)
end_define

begin_define
define|#
directive|define
name|AR934X_DDR_REG_FLUSH_WMAC
value|(AR71XX_APB_BASE + 0xac)
end_define

begin_define
define|#
directive|define
name|AR934X_PLL_CPU_CONFIG_REG
value|(AR71XX_PLL_CPU_BASE + 0x00)
end_define

begin_define
define|#
directive|define
name|AR934X_PLL_DDR_CONFIG_REG
value|(AR71XX_PLL_CPU_BASE + 0x04)
end_define

begin_define
define|#
directive|define
name|AR934X_PLL_CPU_DDR_CLK_CTRL_REG
value|(AR71XX_PLL_CPU_BASE + 0x08)
end_define

begin_define
define|#
directive|define
name|AR934X_PLL_SWITCH_CLOCK_CONTROL_REG
value|(AR71XX_PLL_CPU_BASE + 0x24)
end_define

begin_define
define|#
directive|define
name|AR934X_PLL_SWITCH_CLOCK_CONTROL_MDIO_CLK_SEL
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|AR934X_PLL_ETH_XMII_CONTROL_REG
value|(AR71XX_PLL_CPU_BASE + 0x2c)
end_define

begin_define
define|#
directive|define
name|AR934X_PLL_CPU_CONFIG_NFRAC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|AR934X_PLL_CPU_CONFIG_NFRAC_MASK
value|0x3f
end_define

begin_define
define|#
directive|define
name|AR934X_PLL_CPU_CONFIG_NINT_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|AR934X_PLL_CPU_CONFIG_NINT_MASK
value|0x3f
end_define

begin_define
define|#
directive|define
name|AR934X_PLL_CPU_CONFIG_REFDIV_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|AR934X_PLL_CPU_CONFIG_REFDIV_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|AR934X_PLL_CPU_CONFIG_OUTDIV_SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|AR934X_PLL_CPU_CONFIG_OUTDIV_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|AR934X_PLL_DDR_CONFIG_NFRAC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|AR934X_PLL_DDR_CONFIG_NFRAC_MASK
value|0x3ff
end_define

begin_define
define|#
directive|define
name|AR934X_PLL_DDR_CONFIG_NINT_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|AR934X_PLL_DDR_CONFIG_NINT_MASK
value|0x3f
end_define

begin_define
define|#
directive|define
name|AR934X_PLL_DDR_CONFIG_REFDIV_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|AR934X_PLL_DDR_CONFIG_REFDIV_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|AR934X_PLL_DDR_CONFIG_OUTDIV_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|AR934X_PLL_DDR_CONFIG_OUTDIV_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|AR934X_PLL_CPU_DDR_CLK_CTRL_CPU_PLL_BYPASS
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AR934X_PLL_CPU_DDR_CLK_CTRL_DDR_PLL_BYPASS
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|AR934X_PLL_CPU_DDR_CLK_CTRL_AHB_PLL_BYPASS
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AR934X_PLL_CPU_DDR_CLK_CTRL_CPU_POST_DIV_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|AR934X_PLL_CPU_DDR_CLK_CTRL_CPU_POST_DIV_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|AR934X_PLL_CPU_DDR_CLK_CTRL_DDR_POST_DIV_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|AR934X_PLL_CPU_DDR_CLK_CTRL_DDR_POST_DIV_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|AR934X_PLL_CPU_DDR_CLK_CTRL_AHB_POST_DIV_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|AR934X_PLL_CPU_DDR_CLK_CTRL_AHB_POST_DIV_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|AR934X_PLL_CPU_DDR_CLK_CTRL_CPUCLK_FROM_CPUPLL
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|AR934X_PLL_CPU_DDR_CLK_CTRL_DDRCLK_FROM_DDRPLL
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|AR934X_PLL_CPU_DDR_CLK_CTRL_AHBCLK_FROM_DDRPLL
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|AR934X_RESET_REG_RESET_MODULE
value|(AR71XX_RST_BLOCK_BASE + 0x1c)
end_define

begin_define
define|#
directive|define
name|AR934X_RESET_REG_BOOTSTRAP
value|(AR71XX_RST_BLOCK_BASE + 0xb0)
end_define

begin_define
define|#
directive|define
name|AR934X_RESET_REG_PCIE_WMAC_INT_STATUS
value|(AR71XX_RST_BLOCK_BASE + 0xac)
end_define

begin_define
define|#
directive|define
name|AR934X_RESET_HOST
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|AR934X_RESET_SLIC
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|AR934X_RESET_HDMA
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|AR934X_RESET_EXTERNAL
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|AR934X_RESET_RTC
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|AR934X_RESET_PCIE_EP_INT
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|AR934X_RESET_CHKSUM_ACC
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|AR934X_RESET_FULL_CHIP
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|AR934X_RESET_GE1_MDIO
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|AR934X_RESET_GE0_MDIO
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|AR934X_RESET_CPU_NMI
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|AR934X_RESET_CPU_COLD
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|AR934X_RESET_HOST_RESET_INT
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|AR934X_RESET_PCIE_EP
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|AR934X_RESET_UART1
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|AR934X_RESET_DDR
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|AR934X_RESET_USB_PHY_PLL_PWD_EXT
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|AR934X_RESET_NANDF
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|AR934X_RESET_GE1_MAC
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|AR934X_RESET_ETH_SWITCH_ANALOG
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|AR934X_RESET_USB_PHY_ANALOG
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|AR934X_RESET_HOST_DMA_INT
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|AR934X_RESET_GE0_MAC
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|AR934X_RESET_ETH_SWITCH
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AR934X_RESET_PCIE_PHY
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|AR934X_RESET_PCIE
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|AR934X_RESET_USB_HOST
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|AR934X_RESET_USB_PHY
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AR934X_RESET_USBSUS_OVERRIDE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|AR934X_RESET_LUT
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AR934X_RESET_MBOX
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AR934X_RESET_I2S
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AR934X_BOOTSTRAP_SW_OPTION8
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|AR934X_BOOTSTRAP_SW_OPTION7
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|AR934X_BOOTSTRAP_SW_OPTION6
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|AR934X_BOOTSTRAP_SW_OPTION5
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|AR934X_BOOTSTRAP_SW_OPTION4
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|AR934X_BOOTSTRAP_SW_OPTION3
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|AR934X_BOOTSTRAP_SW_OPTION2
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|AR934X_BOOTSTRAP_SW_OPTION1
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|AR934X_BOOTSTRAP_USB_MODE_DEVICE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|AR934X_BOOTSTRAP_PCIE_RC
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|AR934X_BOOTSTRAP_EJTAG_MODE
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|AR934X_BOOTSTRAP_REF_CLK_40
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AR934X_BOOTSTRAP_BOOT_FROM_SPI
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AR934X_BOOTSTRAP_SDRAM_DISABLED
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AR934X_BOOTSTRAP_DDR1
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AR934X_PCIE_WMAC_INT_WMAC_MISC
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AR934X_PCIE_WMAC_INT_WMAC_TX
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AR934X_PCIE_WMAC_INT_WMAC_RXLP
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AR934X_PCIE_WMAC_INT_WMAC_RXHP
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|AR934X_PCIE_WMAC_INT_PCIE_RC
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AR934X_PCIE_WMAC_INT_PCIE_RC0
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|AR934X_PCIE_WMAC_INT_PCIE_RC1
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|AR934X_PCIE_WMAC_INT_PCIE_RC2
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|AR934X_PCIE_WMAC_INT_PCIE_RC3
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AR934X_PCIE_WMAC_INT_WMAC_ALL
define|\
value|(AR934X_PCIE_WMAC_INT_WMAC_MISC | AR934X_PCIE_WMAC_INT_WMAC_TX | \          AR934X_PCIE_WMAC_INT_WMAC_RXLP | AR934X_PCIE_WMAC_INT_WMAC_RXHP)
end_define

begin_define
define|#
directive|define
name|AR934X_PCIE_WMAC_INT_PCIE_ALL
define|\
value|(AR934X_PCIE_WMAC_INT_PCIE_RC | AR934X_PCIE_WMAC_INT_PCIE_RC0 | \          AR934X_PCIE_WMAC_INT_PCIE_RC1 | AR934X_PCIE_WMAC_INT_PCIE_RC2 | \          AR934X_PCIE_WMAC_INT_PCIE_RC3)
end_define

begin_define
define|#
directive|define
name|REV_ID_MAJOR_AR9341
value|0x0120
end_define

begin_define
define|#
directive|define
name|REV_ID_MAJOR_AR9342
value|0x1120
end_define

begin_define
define|#
directive|define
name|REV_ID_MAJOR_AR9344
value|0x2120
end_define

begin_define
define|#
directive|define
name|AR934X_REV_ID_REVISION_MASK
value|0xf
end_define

begin_comment
comment|/*  * GPIO block  */
end_comment

begin_define
define|#
directive|define
name|AR934X_GPIO_REG_FUNC
value|0x6c
end_define

begin_define
define|#
directive|define
name|AR934X_GPIO_COUNT
value|23
end_define

begin_comment
comment|/*  * SRIF block  */
end_comment

begin_define
define|#
directive|define
name|AR934X_SRIF_CPU_DPLL1_REG
value|(AR934X_SRIF_BASE + 0x1c0)
end_define

begin_define
define|#
directive|define
name|AR934X_SRIF_CPU_DPLL2_REG
value|(AR934X_SRIF_BASE + 0x1c4)
end_define

begin_define
define|#
directive|define
name|AR934X_SRIF_CPU_DPLL3_REG
value|(AR934X_SRIF_BASE + 0x1c8)
end_define

begin_define
define|#
directive|define
name|AR934X_SRIF_DDR_DPLL1_REG
value|(AR934X_SRIF_BASE + 0x240)
end_define

begin_define
define|#
directive|define
name|AR934X_SRIF_DDR_DPLL2_REG
value|(AR934X_SRIF_BASE + 0x244)
end_define

begin_define
define|#
directive|define
name|AR934X_SRIF_DDR_DPLL3_REG
value|(AR934X_SRIF_BASE + 0x248)
end_define

begin_define
define|#
directive|define
name|AR934X_SRIF_DPLL1_REFDIV_SHIFT
value|27
end_define

begin_define
define|#
directive|define
name|AR934X_SRIF_DPLL1_REFDIV_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|AR934X_SRIF_DPLL1_NINT_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|AR934X_SRIF_DPLL1_NINT_MASK
value|0x1ff
end_define

begin_define
define|#
directive|define
name|AR934X_SRIF_DPLL1_NFRAC_MASK
value|0x0003ffff
end_define

begin_define
define|#
directive|define
name|AR934X_SRIF_DPLL2_LOCAL_PLL
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|AR934X_SRIF_DPLL2_OUTDIV_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|AR934X_SRIF_DPLL2_OUTDIV_MASK
value|0x7
end_define

begin_comment
comment|/* XXX verify! */
end_comment

begin_define
define|#
directive|define
name|AR934X_PLL_VAL_1000
value|0x16000000
end_define

begin_define
define|#
directive|define
name|AR934X_PLL_VAL_100
value|0x00000101
end_define

begin_define
define|#
directive|define
name|AR934X_PLL_VAL_10
value|0x00001616
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __AR934X_REG_H__ */
end_comment

end_unit

