begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Adrian Chadd<adrian@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__QCA953XREG_H__
end_ifndef

begin_define
define|#
directive|define
name|__QCA953XREG_H__
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
name|REV_ID_MAJOR_QCA9533
value|0x0140
end_define

begin_define
define|#
directive|define
name|REV_ID_MAJOR_QCA9533_V2
value|0x0160
end_define

begin_define
define|#
directive|define
name|QCA953X_REV_ID_REVISION_MASK
value|0xf
end_define

begin_comment
comment|/* Big enough to cover APB and SPI, and most peripherals */
end_comment

begin_comment
comment|/*  * it needs to cover SPI because right now the if_ath_ahb  * code uses rman to map in the SPI address into memory  * to read data instead of us squirreling it away at early  * boot-time and using the firmware interface.  *  * if_ath_ahb.c should use the same firmware interface  * that if_ath_pci.c uses.  */
end_comment

begin_define
define|#
directive|define
name|QCA953X_GMAC_BASE
value|(AR71XX_APB_BASE + 0x00070000)
end_define

begin_define
define|#
directive|define
name|QCA953X_GMAC_SIZE
value|0x14
end_define

begin_define
define|#
directive|define
name|QCA953X_WMAC_BASE
value|(AR71XX_APB_BASE + 0x00100000)
end_define

begin_define
define|#
directive|define
name|QCA953X_WMAC_SIZE
value|0x20000
end_define

begin_define
define|#
directive|define
name|QCA953X_EHCI_BASE
value|0x1b000000
end_define

begin_define
define|#
directive|define
name|QCA953X_EHCI_SIZE
value|0x200
end_define

begin_define
define|#
directive|define
name|QCA953X_SRIF_BASE
value|(AR71XX_APB_BASE + 0x00116000)
end_define

begin_define
define|#
directive|define
name|QCA953X_SRIF_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|QCA953X_PCI_CFG_BASE0
value|0x14000000
end_define

begin_define
define|#
directive|define
name|QCA953X_PCI_CTRL_BASE0
value|(AR71XX_APB_BASE + 0x000f0000)
end_define

begin_define
define|#
directive|define
name|QCA953X_PCI_CRP_BASE0
value|(AR71XX_APB_BASE + 0x000c0000)
end_define

begin_define
define|#
directive|define
name|QCA953X_PCI_MEM_BASE0
value|0x10000000
end_define

begin_define
define|#
directive|define
name|QCA953X_PCI_MEM_SIZE
value|0x02000000
end_define

begin_comment
comment|/* PLL Block */
end_comment

begin_define
define|#
directive|define
name|QCA953X_PLL_CPU_CONFIG_REG
value|(AR71XX_PLL_CPU_BASE + 0x00)
end_define

begin_define
define|#
directive|define
name|QCA953X_PLL_DDR_CONFIG_REG
value|(AR71XX_PLL_CPU_BASE + 0x04)
end_define

begin_define
define|#
directive|define
name|QCA953X_PLL_CLK_CTRL_REG
value|(AR71XX_PLL_CPU_BASE + 0x08)
end_define

begin_define
define|#
directive|define
name|QCA953X_PLL_ETH_XMII_CONTROL_REG
value|(AR71XX_PLL_CPU_BASE + 0x2c)
end_define

begin_define
define|#
directive|define
name|QCA953X_PLL_ETH_SGMII_CONTROL_REG
value|(AR71XX_PLL_CPU_BASE + 0x48)
end_define

begin_define
define|#
directive|define
name|QCA953X_PLL_CPU_CONFIG_NFRAC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|QCA953X_PLL_CPU_CONFIG_NFRAC_MASK
value|0x3f
end_define

begin_define
define|#
directive|define
name|QCA953X_PLL_CPU_CONFIG_NINT_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|QCA953X_PLL_CPU_CONFIG_NINT_MASK
value|0x3f
end_define

begin_define
define|#
directive|define
name|QCA953X_PLL_CPU_CONFIG_REFDIV_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|QCA953X_PLL_CPU_CONFIG_REFDIV_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|QCA953X_PLL_CPU_CONFIG_OUTDIV_SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|QCA953X_PLL_CPU_CONFIG_OUTDIV_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|QCA953X_PLL_DDR_CONFIG_NFRAC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|QCA953X_PLL_DDR_CONFIG_NFRAC_MASK
value|0x3ff
end_define

begin_define
define|#
directive|define
name|QCA953X_PLL_DDR_CONFIG_NINT_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|QCA953X_PLL_DDR_CONFIG_NINT_MASK
value|0x3f
end_define

begin_define
define|#
directive|define
name|QCA953X_PLL_DDR_CONFIG_REFDIV_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|QCA953X_PLL_DDR_CONFIG_REFDIV_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|QCA953X_PLL_DDR_CONFIG_OUTDIV_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|QCA953X_PLL_DDR_CONFIG_OUTDIV_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|QCA953X_PLL_CLK_CTRL_CPU_PLL_BYPASS
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|QCA953X_PLL_CLK_CTRL_DDR_PLL_BYPASS
value|BIT(3)
end_define

begin_define
define|#
directive|define
name|QCA953X_PLL_CLK_CTRL_AHB_PLL_BYPASS
value|BIT(4)
end_define

begin_define
define|#
directive|define
name|QCA953X_PLL_CLK_CTRL_CPU_POST_DIV_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|QCA953X_PLL_CLK_CTRL_CPU_POST_DIV_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|QCA953X_PLL_CLK_CTRL_DDR_POST_DIV_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|QCA953X_PLL_CLK_CTRL_DDR_POST_DIV_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|QCA953X_PLL_CLK_CTRL_AHB_POST_DIV_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|QCA953X_PLL_CLK_CTRL_AHB_POST_DIV_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|QCA953X_PLL_CLK_CTRL_CPUCLK_FROM_CPUPLL
value|BIT(20)
end_define

begin_define
define|#
directive|define
name|QCA953X_PLL_CLK_CTRL_DDRCLK_FROM_DDRPLL
value|BIT(21)
end_define

begin_define
define|#
directive|define
name|QCA953X_PLL_CLK_CTRL_AHBCLK_FROM_DDRPLL
value|BIT(24)
end_define

begin_define
define|#
directive|define
name|QCA953X_PLL_VAL_1000
value|0x16000000
end_define

begin_define
define|#
directive|define
name|QCA953X_PLL_VAL_100
value|0x00000101
end_define

begin_define
define|#
directive|define
name|QCA953X_PLL_VAL_10
value|0x00001616
end_define

begin_comment
comment|/* Reset block */
end_comment

begin_define
define|#
directive|define
name|QCA953X_RESET_REG_RESET_MODULE
value|(AR71XX_RST_BLOCK_BASE + 0x1c)
end_define

begin_define
define|#
directive|define
name|QCA953X_RESET_USB_EXT_PWR
value|BIT(29)
end_define

begin_define
define|#
directive|define
name|QCA953X_RESET_EXTERNAL
value|BIT(28)
end_define

begin_define
define|#
directive|define
name|QCA953X_RESET_RTC
value|BIT(27)
end_define

begin_define
define|#
directive|define
name|QCA953X_RESET_FULL_CHIP
value|BIT(24)
end_define

begin_define
define|#
directive|define
name|QCA953X_RESET_GE1_MDIO
value|BIT(23)
end_define

begin_define
define|#
directive|define
name|QCA953X_RESET_GE0_MDIO
value|BIT(22)
end_define

begin_define
define|#
directive|define
name|QCA953X_RESET_CPU_NMI
value|BIT(21)
end_define

begin_define
define|#
directive|define
name|QCA953X_RESET_CPU_COLD
value|BIT(20)
end_define

begin_define
define|#
directive|define
name|QCA953X_RESET_DDR
value|BIT(16)
end_define

begin_define
define|#
directive|define
name|QCA953X_RESET_USB_PHY_PLL_PWD_EXT
value|BIT(15)
end_define

begin_define
define|#
directive|define
name|QCA953X_RESET_GE1_MAC
value|BIT(13)
end_define

begin_define
define|#
directive|define
name|QCA953X_RESET_ETH_SWITCH_ANALOG
value|BIT(12)
end_define

begin_define
define|#
directive|define
name|QCA953X_RESET_USB_PHY_ANALOG
value|BIT(11)
end_define

begin_define
define|#
directive|define
name|QCA953X_RESET_GE0_MAC
value|BIT(9)
end_define

begin_define
define|#
directive|define
name|QCA953X_RESET_ETH_SWITCH
value|BIT(8)
end_define

begin_define
define|#
directive|define
name|QCA953X_RESET_PCIE_PHY
value|BIT(7)
end_define

begin_define
define|#
directive|define
name|QCA953X_RESET_PCIE
value|BIT(6)
end_define

begin_define
define|#
directive|define
name|QCA953X_RESET_USB_HOST
value|BIT(5)
end_define

begin_define
define|#
directive|define
name|QCA953X_RESET_USB_PHY
value|BIT(4)
end_define

begin_define
define|#
directive|define
name|QCA953X_RESET_USBSUS_OVERRIDE
value|BIT(3)
end_define

begin_define
define|#
directive|define
name|QCA953X_RESET_REG_BOOTSTRAP
value|(AR71XX_RST_BLOCK_BASE + 0xb0)
end_define

begin_define
define|#
directive|define
name|QCA953X_BOOTSTRAP_SW_OPTION2
value|BIT(12)
end_define

begin_define
define|#
directive|define
name|QCA953X_BOOTSTRAP_SW_OPTION1
value|BIT(11)
end_define

begin_define
define|#
directive|define
name|QCA953X_BOOTSTRAP_EJTAG_MODE
value|BIT(5)
end_define

begin_define
define|#
directive|define
name|QCA953X_BOOTSTRAP_REF_CLK_40
value|BIT(4)
end_define

begin_define
define|#
directive|define
name|QCA953X_BOOTSTRAP_SDRAM_DISABLED
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|QCA953X_BOOTSTRAP_DDR1
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|QCA953X_RESET_REG_EXT_INT_STATUS
value|(AR71XX_RST_BLOCK_BASE + 0xac)
end_define

begin_define
define|#
directive|define
name|QCA953X_DDR_REG_FLUSH_GE0
value|(AR71XX_APB_BASE + 0x9c)
end_define

begin_define
define|#
directive|define
name|QCA953X_DDR_REG_FLUSH_GE1
value|(AR71XX_APB_BASE + 0xa0)
end_define

begin_define
define|#
directive|define
name|QCA953X_DDR_REG_FLUSH_USB
value|(AR71XX_APB_BASE + 0xa4)
end_define

begin_define
define|#
directive|define
name|QCA953X_DDR_REG_FLUSH_PCIE
value|(AR71XX_APB_BASE + 0xa8)
end_define

begin_define
define|#
directive|define
name|QCA953X_DDR_REG_FLUSH_WMAC
value|(AR71XX_APB_BASE + 0xac)
end_define

begin_comment
comment|/* GPIO block */
end_comment

begin_define
define|#
directive|define
name|QCA953X_GPIO_REG_OUT_FUNC0
value|0x2c
end_define

begin_define
define|#
directive|define
name|QCA953X_GPIO_REG_OUT_FUNC1
value|0x30
end_define

begin_define
define|#
directive|define
name|QCA953X_GPIO_REG_OUT_FUNC2
value|0x34
end_define

begin_define
define|#
directive|define
name|QCA953X_GPIO_REG_OUT_FUNC3
value|0x38
end_define

begin_define
define|#
directive|define
name|QCA953X_GPIO_REG_OUT_FUNC4
value|0x3c
end_define

begin_define
define|#
directive|define
name|QCA953X_GPIO_REG_IN_ENABLE0
value|0x44
end_define

begin_define
define|#
directive|define
name|QCA953X_GPIO_REG_FUNC
value|0x6c
end_define

begin_define
define|#
directive|define
name|QCA953X_GPIO_OUT_MUX_SPI_CS1
value|10
end_define

begin_define
define|#
directive|define
name|QCA953X_GPIO_OUT_MUX_SPI_CS2
value|11
end_define

begin_define
define|#
directive|define
name|QCA953X_GPIO_OUT_MUX_SPI_CS0
value|9
end_define

begin_define
define|#
directive|define
name|QCA953X_GPIO_OUT_MUX_SPI_CLK
value|8
end_define

begin_define
define|#
directive|define
name|QCA953X_GPIO_OUT_MUX_SPI_MOSI
value|12
end_define

begin_define
define|#
directive|define
name|QCA953X_GPIO_OUT_MUX_LED_LINK1
value|41
end_define

begin_define
define|#
directive|define
name|QCA953X_GPIO_OUT_MUX_LED_LINK2
value|42
end_define

begin_define
define|#
directive|define
name|QCA953X_GPIO_OUT_MUX_LED_LINK3
value|43
end_define

begin_define
define|#
directive|define
name|QCA953X_GPIO_OUT_MUX_LED_LINK4
value|44
end_define

begin_define
define|#
directive|define
name|QCA953X_GPIO_OUT_MUX_LED_LINK5
value|45
end_define

begin_define
define|#
directive|define
name|QCA953X_GPIO_COUNT
value|18
end_define

begin_comment
comment|/* GMAC block */
end_comment

begin_define
define|#
directive|define
name|QCA953X_GMAC_REG_ETH_CFG
value|(QCA953X_GMAC_BASE + 0x00)
end_define

begin_define
define|#
directive|define
name|QCA953X_ETH_CFG_SW_ONLY_MODE
value|BIT(6)
end_define

begin_define
define|#
directive|define
name|QCA953X_ETH_CFG_SW_PHY_SWAP
value|BIT(7)
end_define

begin_define
define|#
directive|define
name|QCA953X_ETH_CFG_SW_APB_ACCESS
value|BIT(9)
end_define

begin_define
define|#
directive|define
name|QCA953X_ETH_CFG_SW_ACC_MSB_FIRST
value|BIT(13)
end_define

begin_comment
comment|/* SRIF block */
end_comment

begin_define
define|#
directive|define
name|QCA953X_SRIF_CPU_DPLL1_REG
value|0x1c0
end_define

begin_define
define|#
directive|define
name|QCA953X_SRIF_CPU_DPLL2_REG
value|0x1c4
end_define

begin_define
define|#
directive|define
name|QCA953X_SRIF_CPU_DPLL3_REG
value|0x1c8
end_define

begin_define
define|#
directive|define
name|QCA953X_SRIF_DDR_DPLL1_REG
value|0x240
end_define

begin_define
define|#
directive|define
name|QCA953X_SRIF_DDR_DPLL2_REG
value|0x244
end_define

begin_define
define|#
directive|define
name|QCA953X_SRIF_DDR_DPLL3_REG
value|0x248
end_define

begin_define
define|#
directive|define
name|QCA953X_SRIF_DPLL1_REFDIV_SHIFT
value|27
end_define

begin_define
define|#
directive|define
name|QCA953X_SRIF_DPLL1_REFDIV_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|QCA953X_SRIF_DPLL1_NINT_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|QCA953X_SRIF_DPLL1_NINT_MASK
value|0x1ff
end_define

begin_define
define|#
directive|define
name|QCA953X_SRIF_DPLL1_NFRAC_MASK
value|0x0003ffff
end_define

begin_define
define|#
directive|define
name|QCA953X_SRIF_DPLL2_LOCAL_PLL
value|BIT(30)
end_define

begin_define
define|#
directive|define
name|QCA953X_SRIF_DPLL2_OUTDIV_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|QCA953X_SRIF_DPLL2_OUTDIV_MASK
value|0x7
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __QCA953XREG_H__ */
end_comment

end_unit

