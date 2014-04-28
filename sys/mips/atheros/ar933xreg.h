begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Adrian Chadd<adrian@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AR93XX_REG_H__
end_ifndef

begin_define
define|#
directive|define
name|__AR93XX_REG_H__
end_define

begin_define
define|#
directive|define
name|REV_ID_MAJOR_AR9330
value|0x0110
end_define

begin_define
define|#
directive|define
name|REV_ID_MAJOR_AR9331
value|0x1110
end_define

begin_define
define|#
directive|define
name|AR933X_REV_ID_REVISION_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|AR933X_GPIO_COUNT
value|30
end_define

begin_define
define|#
directive|define
name|AR933X_UART_BASE
value|(AR71XX_APB_BASE + 0x00020000)
end_define

begin_define
define|#
directive|define
name|AR933X_UART_SIZE
value|0x14
end_define

begin_define
define|#
directive|define
name|AR933X_GMAC_BASE
value|(AR71XX_APB_BASE + 0x00070000)
end_define

begin_define
define|#
directive|define
name|AR933X_GMAC_SIZE
value|0x04
end_define

begin_define
define|#
directive|define
name|AR933X_GMAC_REG_ETH_CFG
value|(AR933X_GMAC_BASE + 0x00)
end_define

begin_define
define|#
directive|define
name|AR933X_ETH_CFG_RGMII_GE0
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AR933X_ETH_CFG_MII_GE0
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AR933X_ETH_CFG_GMII_GE0
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AR933X_ETH_CFG_MII_GE0_MASTER
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|AR933X_ETH_CFG_MII_GE0_SLAVE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AR933X_ETH_CFG_MII_GE0_ERR_EN
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|AR933X_ETH_CFG_SW_PHY_SWAP
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|AR933X_ETH_CFG_SW_PHY_ADDR_SWAP
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AR933X_ETH_CFG_RMII_GE0
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|AR933X_ETH_CFG_RMII_GE0_SPD_10
value|0
end_define

begin_define
define|#
directive|define
name|AR933X_ETH_CFG_RMII_GE0_SPD_100
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|AR933X_WMAC_BASE
value|(AR71XX_APB_BASE + 0x00100000)
end_define

begin_define
define|#
directive|define
name|AR933X_WMAC_SIZE
value|0x20000
end_define

begin_define
define|#
directive|define
name|AR933X_EHCI_BASE
value|0x1b000000
end_define

begin_define
define|#
directive|define
name|AR933X_EHCI_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|AR933X_DDR_REG_FLUSH_GE0
value|(AR71XX_APB_BASE + 0x7c)
end_define

begin_define
define|#
directive|define
name|AR933X_DDR_REG_FLUSH_GE1
value|(AR71XX_APB_BASE + 0x80)
end_define

begin_define
define|#
directive|define
name|AR933X_DDR_REG_FLUSH_USB
value|(AR71XX_APB_BASE + 0x84)
end_define

begin_define
define|#
directive|define
name|AR933X_DDR_REG_FLUSH_WMAC
value|(AR71XX_APB_BASE + 0x88)
end_define

begin_define
define|#
directive|define
name|AR933X_PLL_CPU_CONFIG_REG
value|(AR71XX_PLL_CPU_BASE + 0x00)
end_define

begin_define
define|#
directive|define
name|AR933X_PLL_CLOCK_CTRL_REG
value|(AR71XX_PLL_CPU_BASE + 0x08)
end_define

begin_define
define|#
directive|define
name|AR933X_PLL_CPU_CONFIG_NINT_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|AR933X_PLL_CPU_CONFIG_NINT_MASK
value|0x3f
end_define

begin_define
define|#
directive|define
name|AR933X_PLL_CPU_CONFIG_REFDIV_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|AR933X_PLL_CPU_CONFIG_REFDIV_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|AR933X_PLL_CPU_CONFIG_OUTDIV_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|AR933X_PLL_CPU_CONFIG_OUTDIV_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|AR933X_PLL_CLOCK_CTRL_BYPASS
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AR933X_PLL_CLOCK_CTRL_CPU_DIV_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|AR933X_PLL_CLOCK_CTRL_CPU_DIV_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|AR933X_PLL_CLOCK_CTRL_DDR_DIV_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|AR933X_PLL_CLOCK_CTRL_DDR_DIV_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|AR933X_PLL_CLOCK_CTRL_AHB_DIV_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|AR933X_PLL_CLOCK_CTRL_AHB_DIV_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|AR933X_RESET_REG_RESET_MODULE
value|(AR71XX_RST_BLOCK_BASE + 0x1c)
end_define

begin_define
define|#
directive|define
name|AR933X_RESET_REG_BOOTSTRAP
value|(AR71XX_RST_BLOCK_BASE + 0xac)
end_define

begin_define
define|#
directive|define
name|AR933X_RESET_WMAC
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|AR933X_RESET_USB_HOST
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|AR933X_RESET_USB_PHY
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AR933X_RESET_USBSUS_OVERRIDE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|AR933X_BOOTSTRAP_REF_CLK_40
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AR933X_PLL_VAL_1000
value|0x00110000
end_define

begin_define
define|#
directive|define
name|AR933X_PLL_VAL_100
value|0x00001099
end_define

begin_define
define|#
directive|define
name|AR933X_PLL_VAL_10
value|0x00991099
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __AR93XX_REG_H__ */
end_comment

end_unit

