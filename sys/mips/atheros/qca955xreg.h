begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Adrian Chadd<adrian@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__QCA955XREG_H__
end_ifndef

begin_define
define|#
directive|define
name|__QCA955XREG_H__
end_define

begin_define
define|#
directive|define
name|BIT
parameter_list|(
name|x
parameter_list|)
value|(1<< (x))
end_define

begin_comment
comment|/* Revision ID information */
end_comment

begin_define
define|#
directive|define
name|REV_ID_MAJOR_QCA9556
value|0x0130
end_define

begin_define
define|#
directive|define
name|REV_ID_MAJOR_QCA9558
value|0x1130
end_define

begin_define
define|#
directive|define
name|QCA955X_REV_ID_REVISION_MASK
value|0xf
end_define

begin_define
define|#
directive|define
name|QCA955X_PCI_MEM_BASE0
value|0x10000000
end_define

begin_define
define|#
directive|define
name|QCA955X_PCI_MEM_BASE1
value|0x12000000
end_define

begin_define
define|#
directive|define
name|QCA955X_PCI_MEM_SIZE
value|0x02000000
end_define

begin_define
define|#
directive|define
name|QCA955X_PCI_CFG_BASE0
value|0x14000000
end_define

begin_define
define|#
directive|define
name|QCA955X_PCI_CFG_BASE1
value|0x16000000
end_define

begin_define
define|#
directive|define
name|QCA955X_PCI_CFG_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|QCA955X_PCI_CRP_BASE0
value|(AR71XX_APB_BASE + 0x000c0000)
end_define

begin_define
define|#
directive|define
name|QCA955X_PCI_CRP_BASE1
value|(AR71XX_APB_BASE + 0x00250000)
end_define

begin_define
define|#
directive|define
name|QCA955X_PCI_CRP_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|QCA955X_PCI_CTRL_BASE0
value|(AR71XX_APB_BASE + 0x000f0000)
end_define

begin_define
define|#
directive|define
name|QCA955X_PCI_CTRL_BASE1
value|(AR71XX_APB_BASE + 0x00280000)
end_define

begin_define
define|#
directive|define
name|QCA955X_PCI_CTRL_SIZE
value|0x100
end_define

begin_define
define|#
directive|define
name|QCA955X_WMAC_BASE
value|(AR71XX_APB_BASE + 0x00100000)
end_define

begin_define
define|#
directive|define
name|QCA955X_WMAC_SIZE
value|0x20000
end_define

begin_define
define|#
directive|define
name|QCA955X_EHCI0_BASE
value|0x1b000000
end_define

begin_define
define|#
directive|define
name|QCA955X_EHCI1_BASE
value|0x1b400000
end_define

begin_define
define|#
directive|define
name|QCA955X_EHCI_SIZE
value|0x1000
end_define

begin_comment
comment|/* PLL block */
end_comment

begin_define
define|#
directive|define
name|QCA955X_PLL_CPU_CONFIG_REG
value|(AR71XX_PLL_CPU_BASE + 0x00)
end_define

begin_define
define|#
directive|define
name|QCA955X_PLL_DDR_CONFIG_REG
value|(AR71XX_PLL_CPU_BASE + 0x04)
end_define

begin_define
define|#
directive|define
name|QCA955X_PLL_CLK_CTRL_REG
value|(AR71XX_PLL_CPU_BASE + 0x08)
end_define

begin_define
define|#
directive|define
name|QCA955X_PLL_CPU_CONFIG_NFRAC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|QCA955X_PLL_CPU_CONFIG_NFRAC_MASK
value|0x3f
end_define

begin_define
define|#
directive|define
name|QCA955X_PLL_CPU_CONFIG_NINT_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|QCA955X_PLL_CPU_CONFIG_NINT_MASK
value|0x3f
end_define

begin_define
define|#
directive|define
name|QCA955X_PLL_CPU_CONFIG_REFDIV_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|QCA955X_PLL_CPU_CONFIG_REFDIV_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|QCA955X_PLL_CPU_CONFIG_OUTDIV_SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|QCA955X_PLL_CPU_CONFIG_OUTDIV_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|QCA955X_PLL_DDR_CONFIG_NFRAC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|QCA955X_PLL_DDR_CONFIG_NFRAC_MASK
value|0x3ff
end_define

begin_define
define|#
directive|define
name|QCA955X_PLL_DDR_CONFIG_NINT_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|QCA955X_PLL_DDR_CONFIG_NINT_MASK
value|0x3f
end_define

begin_define
define|#
directive|define
name|QCA955X_PLL_DDR_CONFIG_REFDIV_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|QCA955X_PLL_DDR_CONFIG_REFDIV_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|QCA955X_PLL_DDR_CONFIG_OUTDIV_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|QCA955X_PLL_DDR_CONFIG_OUTDIV_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|QCA955X_PLL_CLK_CTRL_CPU_PLL_BYPASS
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|QCA955X_PLL_CLK_CTRL_DDR_PLL_BYPASS
value|BIT(3)
end_define

begin_define
define|#
directive|define
name|QCA955X_PLL_CLK_CTRL_AHB_PLL_BYPASS
value|BIT(4)
end_define

begin_define
define|#
directive|define
name|QCA955X_PLL_CLK_CTRL_CPU_POST_DIV_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|QCA955X_PLL_CLK_CTRL_CPU_POST_DIV_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|QCA955X_PLL_CLK_CTRL_DDR_POST_DIV_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|QCA955X_PLL_CLK_CTRL_DDR_POST_DIV_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|QCA955X_PLL_CLK_CTRL_AHB_POST_DIV_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|QCA955X_PLL_CLK_CTRL_AHB_POST_DIV_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|QCA955X_PLL_CLK_CTRL_CPUCLK_FROM_CPUPLL
value|BIT(20)
end_define

begin_define
define|#
directive|define
name|QCA955X_PLL_CLK_CTRL_DDRCLK_FROM_DDRPLL
value|BIT(21)
end_define

begin_define
define|#
directive|define
name|QCA955X_PLL_CLK_CTRL_AHBCLK_FROM_DDRPLL
value|BIT(24)
end_define

begin_define
define|#
directive|define
name|QCA955X_PLL_ETH_XMII_CONTROL_REG
value|(AR71XX_PLL_CPU_BASE + 0x28)
end_define

begin_define
define|#
directive|define
name|QCA955X_PLL_ETH_SGMII_CONTROL_REG
value|(AR71XX_PLL_CPU_BASE + 0x48)
end_define

begin_comment
comment|/* Reset block */
end_comment

begin_define
define|#
directive|define
name|QCA955X_RESET_REG_RESET_MODULE
value|(AR71XX_RST_BLOCK_BASE + 0x1c)
end_define

begin_define
define|#
directive|define
name|QCA955X_RESET_REG_BOOTSTRAP
value|(AR71XX_RST_BLOCK_BASE + 0xb0)
end_define

begin_define
define|#
directive|define
name|QCA955X_RESET_REG_EXT_INT_STATUS
value|(AR71XX_RST_BLOCK_BASE + 0xac)
end_define

begin_define
define|#
directive|define
name|QCA955X_BOOTSTRAP_REF_CLK_40
value|BIT(4)
end_define

begin_define
define|#
directive|define
name|QCA955X_EXT_INT_WMAC_MISC
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|QCA955X_EXT_INT_WMAC_TX
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|QCA955X_EXT_INT_WMAC_RXLP
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|QCA955X_EXT_INT_WMAC_RXHP
value|BIT(3)
end_define

begin_define
define|#
directive|define
name|QCA955X_EXT_INT_PCIE_RC1
value|BIT(4)
end_define

begin_define
define|#
directive|define
name|QCA955X_EXT_INT_PCIE_RC1_INT0
value|BIT(5)
end_define

begin_define
define|#
directive|define
name|QCA955X_EXT_INT_PCIE_RC1_INT1
value|BIT(6)
end_define

begin_define
define|#
directive|define
name|QCA955X_EXT_INT_PCIE_RC1_INT2
value|BIT(7)
end_define

begin_define
define|#
directive|define
name|QCA955X_EXT_INT_PCIE_RC1_INT3
value|BIT(8)
end_define

begin_define
define|#
directive|define
name|QCA955X_EXT_INT_PCIE_RC2
value|BIT(12)
end_define

begin_define
define|#
directive|define
name|QCA955X_EXT_INT_PCIE_RC2_INT0
value|BIT(13)
end_define

begin_define
define|#
directive|define
name|QCA955X_EXT_INT_PCIE_RC2_INT1
value|BIT(14)
end_define

begin_define
define|#
directive|define
name|QCA955X_EXT_INT_PCIE_RC2_INT2
value|BIT(15)
end_define

begin_define
define|#
directive|define
name|QCA955X_EXT_INT_PCIE_RC2_INT3
value|BIT(16)
end_define

begin_define
define|#
directive|define
name|QCA955X_EXT_INT_USB1
value|BIT(24)
end_define

begin_define
define|#
directive|define
name|QCA955X_EXT_INT_USB2
value|BIT(28)
end_define

begin_define
define|#
directive|define
name|QCA955X_EXT_INT_WMAC_ALL
define|\
value|(QCA955X_EXT_INT_WMAC_MISC | QCA955X_EXT_INT_WMAC_TX | \          QCA955X_EXT_INT_WMAC_RXLP | QCA955X_EXT_INT_WMAC_RXHP)
end_define

begin_define
define|#
directive|define
name|QCA955X_EXT_INT_PCIE_RC1_ALL
define|\
value|(QCA955X_EXT_INT_PCIE_RC1 | QCA955X_EXT_INT_PCIE_RC1_INT0 | \          QCA955X_EXT_INT_PCIE_RC1_INT1 | QCA955X_EXT_INT_PCIE_RC1_INT2 | \          QCA955X_EXT_INT_PCIE_RC1_INT3)
end_define

begin_define
define|#
directive|define
name|QCA955X_EXT_INT_PCIE_RC2_ALL
define|\
value|(QCA955X_EXT_INT_PCIE_RC2 | QCA955X_EXT_INT_PCIE_RC2_INT0 | \          QCA955X_EXT_INT_PCIE_RC2_INT1 | QCA955X_EXT_INT_PCIE_RC2_INT2 | \          QCA955X_EXT_INT_PCIE_RC2_INT3)
end_define

begin_define
define|#
directive|define
name|QCA955X_RESET_HOST
value|BIT(31)
end_define

begin_define
define|#
directive|define
name|QCA955X_RESET_SLIC
value|BIT(30)
end_define

begin_define
define|#
directive|define
name|QCA955X_RESET_HDMA
value|BIT(29)
end_define

begin_define
define|#
directive|define
name|QCA955X_RESET_EXTERNAL
value|BIT(28)
end_define

begin_define
define|#
directive|define
name|QCA955X_RESET_RTC
value|BIT(27)
end_define

begin_define
define|#
directive|define
name|QCA955X_RESET_PCIE_EP_INT
value|BIT(26)
end_define

begin_define
define|#
directive|define
name|QCA955X_RESET_CHKSUM_ACC
value|BIT(25)
end_define

begin_define
define|#
directive|define
name|QCA955X_RESET_FULL_CHIP
value|BIT(24)
end_define

begin_define
define|#
directive|define
name|QCA955X_RESET_GE1_MDIO
value|BIT(23)
end_define

begin_define
define|#
directive|define
name|QCA955X_RESET_GE0_MDIO
value|BIT(22)
end_define

begin_define
define|#
directive|define
name|QCA955X_RESET_CPU_NMI
value|BIT(21)
end_define

begin_define
define|#
directive|define
name|QCA955X_RESET_CPU_COLD
value|BIT(20)
end_define

begin_define
define|#
directive|define
name|QCA955X_RESET_HOST_RESET_INT
value|BIT(19)
end_define

begin_define
define|#
directive|define
name|QCA955X_RESET_PCIE_EP
value|BIT(18)
end_define

begin_define
define|#
directive|define
name|QCA955X_RESET_UART1
value|BIT(17)
end_define

begin_define
define|#
directive|define
name|QCA955X_RESET_DDR
value|BIT(16)
end_define

begin_define
define|#
directive|define
name|QCA955X_RESET_USB_PHY_PLL_PWD_EXT
value|BIT(15)
end_define

begin_define
define|#
directive|define
name|QCA955X_RESET_NANDF
value|BIT(14)
end_define

begin_define
define|#
directive|define
name|QCA955X_RESET_GE1_MAC
value|BIT(13)
end_define

begin_define
define|#
directive|define
name|QCA955X_RESET_SGMII_ANALOG
value|BIT(12)
end_define

begin_define
define|#
directive|define
name|QCA955X_RESET_USB_PHY_ANALOG
value|BIT(11)
end_define

begin_define
define|#
directive|define
name|QCA955X_RESET_HOST_DMA_INT
value|BIT(10)
end_define

begin_define
define|#
directive|define
name|QCA955X_RESET_GE0_MAC
value|BIT(9)
end_define

begin_define
define|#
directive|define
name|QCA955X_RESET_SGMII
value|BIT(8)
end_define

begin_define
define|#
directive|define
name|QCA955X_RESET_PCIE_PHY
value|BIT(7)
end_define

begin_define
define|#
directive|define
name|QCA955X_RESET_PCIE
value|BIT(6)
end_define

begin_define
define|#
directive|define
name|QCA955X_RESET_USB_HOST
value|BIT(5)
end_define

begin_define
define|#
directive|define
name|QCA955X_RESET_USB_PHY
value|BIT(4)
end_define

begin_define
define|#
directive|define
name|QCA955X_RESET_USBSUS_OVERRIDE
value|BIT(3)
end_define

begin_define
define|#
directive|define
name|QCA955X_RESET_LUT
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|QCA955X_RESET_MBOX
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|QCA955X_RESET_I2S
value|BIT(0)
end_define

begin_comment
comment|/* GPIO block */
end_comment

begin_define
define|#
directive|define
name|QCA955X_GPIO_COUNT
value|24
end_define

begin_define
define|#
directive|define
name|QCA955X_GMAC_BASE
value|(AR71XX_APB_BASE + 0x00070000)
end_define

begin_define
define|#
directive|define
name|QCA955X_GMAC_SIZE
value|0x40
end_define

begin_define
define|#
directive|define
name|QCA955X_NFC_BASE
value|0x1b800200
end_define

begin_define
define|#
directive|define
name|QCA955X_NFC_SIZE
value|0xb8
end_define

begin_comment
comment|/* GMAC Interface */
end_comment

begin_define
define|#
directive|define
name|QCA955X_GMAC_REG_ETH_CFG
value|0x00
end_define

begin_comment
comment|/* XXX register base? */
end_comment

begin_define
define|#
directive|define
name|QCA955X_ETH_CFG_RGMII_EN
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|QCA955X_ETH_CFG_GE0_SGMII
value|BIT(6)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __QCA955XREG_H__ */
end_comment

end_unit

