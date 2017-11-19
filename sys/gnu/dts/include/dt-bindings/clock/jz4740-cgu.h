begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SPDX-License-Identifier: GPL-2.0 */
end_comment

begin_comment
comment|/*  * This header provides clock numbers for the ingenic,jz4740-cgu DT binding.  *  * They are roughly ordered as:  *   - external clocks  *   - PLLs  *   - muxes/dividers in the order they appear in the jz4740 programmers manual  *   - gates in order of their bit in the CLKGR* registers  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_CLOCK_JZ4740_CGU_H__
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_CLOCK_JZ4740_CGU_H__
end_define

begin_define
define|#
directive|define
name|JZ4740_CLK_EXT
value|0
end_define

begin_define
define|#
directive|define
name|JZ4740_CLK_RTC
value|1
end_define

begin_define
define|#
directive|define
name|JZ4740_CLK_PLL
value|2
end_define

begin_define
define|#
directive|define
name|JZ4740_CLK_PLL_HALF
value|3
end_define

begin_define
define|#
directive|define
name|JZ4740_CLK_CCLK
value|4
end_define

begin_define
define|#
directive|define
name|JZ4740_CLK_HCLK
value|5
end_define

begin_define
define|#
directive|define
name|JZ4740_CLK_PCLK
value|6
end_define

begin_define
define|#
directive|define
name|JZ4740_CLK_MCLK
value|7
end_define

begin_define
define|#
directive|define
name|JZ4740_CLK_LCD
value|8
end_define

begin_define
define|#
directive|define
name|JZ4740_CLK_LCD_PCLK
value|9
end_define

begin_define
define|#
directive|define
name|JZ4740_CLK_I2S
value|10
end_define

begin_define
define|#
directive|define
name|JZ4740_CLK_SPI
value|11
end_define

begin_define
define|#
directive|define
name|JZ4740_CLK_MMC
value|12
end_define

begin_define
define|#
directive|define
name|JZ4740_CLK_UHC
value|13
end_define

begin_define
define|#
directive|define
name|JZ4740_CLK_UDC
value|14
end_define

begin_define
define|#
directive|define
name|JZ4740_CLK_UART0
value|15
end_define

begin_define
define|#
directive|define
name|JZ4740_CLK_UART1
value|16
end_define

begin_define
define|#
directive|define
name|JZ4740_CLK_DMA
value|17
end_define

begin_define
define|#
directive|define
name|JZ4740_CLK_IPU
value|18
end_define

begin_define
define|#
directive|define
name|JZ4740_CLK_ADC
value|19
end_define

begin_define
define|#
directive|define
name|JZ4740_CLK_I2C
value|20
end_define

begin_define
define|#
directive|define
name|JZ4740_CLK_AIC
value|21
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DT_BINDINGS_CLOCK_JZ4740_CGU_H__ */
end_comment

end_unit

