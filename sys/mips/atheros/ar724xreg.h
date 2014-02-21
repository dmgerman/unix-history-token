begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Adrian Chadd  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AR72XX_REG_H__
end_ifndef

begin_define
define|#
directive|define
name|__AR72XX_REG_H__
end_define

begin_define
define|#
directive|define
name|AR724X_PLL_REG_CPU_CONFIG
value|AR71XX_PLL_CPU_BASE + 0x00
end_define

begin_define
define|#
directive|define
name|AR724X_PLL_REG_PCIE_CONFIG
value|AR71XX_PLL_CPU_BASE + 0x18
end_define

begin_define
define|#
directive|define
name|AR724X_PLL_DIV_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|AR724X_PLL_DIV_MASK
value|0x3ff
end_define

begin_define
define|#
directive|define
name|AR724X_PLL_REF_DIV_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|AR724X_PLL_REF_DIV_MASK
value|0xf
end_define

begin_define
define|#
directive|define
name|AR724X_AHB_DIV_SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|AR724X_AHB_DIV_MASK
value|0x1
end_define

begin_define
define|#
directive|define
name|AR724X_DDR_DIV_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|AR724X_DDR_DIV_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|AR724X_PLL_VAL_1000
value|0x00110000
end_define

begin_define
define|#
directive|define
name|AR724X_PLL_VAL_100
value|0x00001099
end_define

begin_define
define|#
directive|define
name|AR724X_PLL_VAL_10
value|0x00991099
end_define

begin_define
define|#
directive|define
name|AR724X_BASE_FREQ
value|5000000
end_define

begin_define
define|#
directive|define
name|AR724X_DDR_REG_FLUSH_GE0
value|(AR71XX_DDR_CONFIG + 0x7c)
end_define

begin_define
define|#
directive|define
name|AR724X_DDR_REG_FLUSH_GE1
value|(AR71XX_DDR_CONFIG + 0x80)
end_define

begin_define
define|#
directive|define
name|AR724X_DDR_REG_FLUSH_USB
value|(AR71XX_DDR_CONFIG + 0x84)
end_define

begin_define
define|#
directive|define
name|AR724X_DDR_REG_FLUSH_PCIE
value|(AR71XX_DDR_CONFIG + 0x88)
end_define

begin_define
define|#
directive|define
name|AR724X_RESET_REG_RESET_MODULE
value|AR71XX_RST_BLOCK_BASE + 0x1c
end_define

begin_define
define|#
directive|define
name|AR724X_RESET_USB_HOST
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|AR724X_RESET_USB_PHY
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AR724X_RESET_MODULE_USB_OHCI_DLL
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|AR724X_RESET_GE1_MDIO
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|AR724X_RESET_GE0_MDIO
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|AR724X_RESET_PCIE_PHY_SERIAL
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|AR724X_RESET_PCIE_PHY
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|AR724X_RESET_PCIE
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|AR724X_RESET_USB_HOST
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|AR724X_RESET_USB_PHY
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AR724X_RESET_USBSUS_OVERRIDE
value|(1<< 3)
end_define

begin_comment
comment|/* XXX so USB requires different init code? -adrian */
end_comment

begin_define
define|#
directive|define
name|AR7240_OHCI_BASE
value|0x1b000000
end_define

begin_define
define|#
directive|define
name|AR7240_OHCI_SIZE
value|0x01000000
end_define

begin_define
define|#
directive|define
name|AR724X_PCI_CRP_BASE
value|(AR71XX_APB_BASE + 0x000C0000)
end_define

begin_define
define|#
directive|define
name|AR724X_PCI_CRP_SIZE
value|0x100
end_define

begin_define
define|#
directive|define
name|AR724X_PCI_CFG_BASE
value|0x14000000
end_define

begin_define
define|#
directive|define
name|AR724X_PCI_CFG_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|AR724X_PCI_CTRL_BASE
value|(AR71XX_APB_BASE + 0x000F0000)
end_define

begin_define
define|#
directive|define
name|AR724X_PCI_CTRL_SIZE
value|0x100
end_define

begin_comment
comment|/* PCI config registers */
end_comment

begin_define
define|#
directive|define
name|AR724X_PCI_APP
value|0x180f0000
end_define

begin_define
define|#
directive|define
name|AR724X_PCI_APP_LTSSM_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AR724X_PCI_RESET
value|0x180f0018
end_define

begin_define
define|#
directive|define
name|AR724X_PCI_RESET_LINK_UP
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AR724X_PCI_INTR_STATUS
value|0x180f004c
end_define

begin_define
define|#
directive|define
name|AR724X_PCI_INTR_MASK
value|0x180f0050
end_define

begin_define
define|#
directive|define
name|AR724X_PCI_INTR_DEV0
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|AR724X_GPIO_FUNC_GE0_MII_CLK_EN
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|AR724X_GPIO_FUNC_SPI_EN
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|AR724X_GPIO_FUNC_SPI_CS_EN2
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|AR724X_GPIO_FUNC_SPI_CS_EN1
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|AR724X_GPIO_FUNC_CLK_OBS5_EN
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|AR724X_GPIO_FUNC_CLK_OBS4_EN
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|AR724X_GPIO_FUNC_CLK_OBS3_EN
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|AR724X_GPIO_FUNC_CLK_OBS2_EN
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|AR724X_GPIO_FUNC_CLK_OBS1_EN
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AR724X_GPIO_FUNC_ETH_SWITCH_LED4_EN
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|AR724X_GPIO_FUNC_ETH_SWITCH_LED3_EN
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|AR724X_GPIO_FUNC_ETH_SWITCH_LED2_EN
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|AR724X_GPIO_FUNC_ETH_SWITCH_LED1_EN
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AR724X_GPIO_FUNC_ETH_SWITCH_LED0_EN
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|AR724X_GPIO_FUNC_UART_RTS_CTS_EN
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AR724X_GPIO_FUNC_UART_EN
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AR724X_GPIO_FUNC_JTAG_DISABLE
value|(1<< 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

