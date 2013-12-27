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
name|__AR91XX_REG_H__
end_ifndef

begin_define
define|#
directive|define
name|__AR91XX_REG_H__
end_define

begin_define
define|#
directive|define
name|AR91XX_BASE_FREQ
value|5000000
end_define

begin_comment
comment|/* reset block */
end_comment

begin_define
define|#
directive|define
name|AR91XX_RESET_REG_RESET_MODULE
value|AR71XX_RST_BLOCK_BASE + 0x1c
end_define

begin_define
define|#
directive|define
name|AR91XX_RST_RESET_MODULE_USBSUS_OVERRIDE
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|AR91XX_RST_RESET_MODULE_AMBA2WMAC
value|(1<< 22)
end_define

begin_comment
comment|/* PLL block */
end_comment

begin_define
define|#
directive|define
name|AR91XX_PLL_REG_CPU_CONFIG
value|AR71XX_PLL_CPU_BASE + 0x00
end_define

begin_define
define|#
directive|define
name|AR91XX_PLL_REG_ETH_CONFIG
value|AR71XX_PLL_CPU_BASE + 0x04
end_define

begin_define
define|#
directive|define
name|AR91XX_PLL_REG_ETH0_INT_CLOCK
value|AR71XX_PLL_CPU_BASE + 0x14
end_define

begin_define
define|#
directive|define
name|AR91XX_PLL_REG_ETH1_INT_CLOCK
value|AR71XX_PLL_CPU_BASE + 0x18
end_define

begin_define
define|#
directive|define
name|AR91XX_PLL_DIV_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|AR91XX_PLL_DIV_MASK
value|0x3ff
end_define

begin_define
define|#
directive|define
name|AR91XX_DDR_DIV_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|AR91XX_DDR_DIV_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|AR91XX_AHB_DIV_SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|AR91XX_AHB_DIV_MASK
value|0x1
end_define

begin_define
define|#
directive|define
name|AR91XX_ETH0_PLL_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|AR91XX_ETH1_PLL_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|AR91XX_PLL_VAL_1000
value|0x1a000000
end_define

begin_define
define|#
directive|define
name|AR91XX_PLL_VAL_100
value|0x13000a44
end_define

begin_define
define|#
directive|define
name|AR91XX_PLL_VAL_10
value|0x00441099
end_define

begin_comment
comment|/* DDR block */
end_comment

begin_define
define|#
directive|define
name|AR91XX_DDR_CTRLBASE
value|(AR71XX_APB_BASE + 0)
end_define

begin_define
define|#
directive|define
name|AR91XX_DDR_CTRL_SIZE
value|0x10000
end_define

begin_define
define|#
directive|define
name|AR91XX_DDR_REG_FLUSH_GE0
value|AR91XX_DDR_CTRLBASE + 0x7c
end_define

begin_define
define|#
directive|define
name|AR91XX_DDR_REG_FLUSH_GE1
value|AR91XX_DDR_CTRLBASE + 0x80
end_define

begin_define
define|#
directive|define
name|AR91XX_DDR_REG_FLUSH_USB
value|AR91XX_DDR_CTRLBASE + 0x84
end_define

begin_define
define|#
directive|define
name|AR91XX_DDR_REG_FLUSH_WMAC
value|AR91XX_DDR_CTRLBASE + 0x88
end_define

begin_comment
comment|/* WMAC stuff */
end_comment

begin_define
define|#
directive|define
name|AR91XX_WMAC_BASE
value|(AR71XX_APB_BASE + 0x000C0000)
end_define

begin_define
define|#
directive|define
name|AR91XX_WMAC_SIZE
value|0x30000
end_define

begin_comment
comment|/* GPIO stuff */
end_comment

begin_define
define|#
directive|define
name|AR91XX_GPIO_FUNC_WMAC_LED_EN
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|AR91XX_GPIO_FUNC_EXP_PORT_CS_EN
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|AR91XX_GPIO_FUNC_I2S_REFCLKEN
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|AR91XX_GPIO_FUNC_I2S_MCKEN
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|AR91XX_GPIO_FUNC_I2S1_EN
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|AR91XX_GPIO_FUNC_I2S0_EN
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|AR91XX_GPIO_FUNC_SLIC_EN
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|AR91XX_GPIO_FUNC_UART_RTSCTS_EN
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|AR91XX_GPIO_FUNC_UART_EN
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|AR91XX_GPIO_FUNC_USB_CLK_EN
value|(1<< 4)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

