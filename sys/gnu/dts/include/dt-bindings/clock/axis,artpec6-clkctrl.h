begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ARTPEC-6 clock controller indexes  *  * Copyright 2016 Axis Comunications AB.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DT_BINDINGS_CLK_ARTPEC6_CLKCTRL_H
end_ifndef

begin_define
define|#
directive|define
name|DT_BINDINGS_CLK_ARTPEC6_CLKCTRL_H
end_define

begin_define
define|#
directive|define
name|ARTPEC6_CLK_CPU
value|0
end_define

begin_define
define|#
directive|define
name|ARTPEC6_CLK_CPU_PERIPH
value|1
end_define

begin_define
define|#
directive|define
name|ARTPEC6_CLK_NAND_CLKA
value|2
end_define

begin_define
define|#
directive|define
name|ARTPEC6_CLK_NAND_CLKB
value|3
end_define

begin_define
define|#
directive|define
name|ARTPEC6_CLK_ETH_ACLK
value|4
end_define

begin_define
define|#
directive|define
name|ARTPEC6_CLK_DMA_ACLK
value|5
end_define

begin_define
define|#
directive|define
name|ARTPEC6_CLK_PTP_REF
value|6
end_define

begin_define
define|#
directive|define
name|ARTPEC6_CLK_SD_PCLK
value|7
end_define

begin_define
define|#
directive|define
name|ARTPEC6_CLK_SD_IMCLK
value|8
end_define

begin_define
define|#
directive|define
name|ARTPEC6_CLK_I2S_HST
value|9
end_define

begin_define
define|#
directive|define
name|ARTPEC6_CLK_I2S0_CLK
value|10
end_define

begin_define
define|#
directive|define
name|ARTPEC6_CLK_I2S1_CLK
value|11
end_define

begin_define
define|#
directive|define
name|ARTPEC6_CLK_UART_PCLK
value|12
end_define

begin_define
define|#
directive|define
name|ARTPEC6_CLK_UART_REFCLK
value|13
end_define

begin_define
define|#
directive|define
name|ARTPEC6_CLK_I2C
value|14
end_define

begin_define
define|#
directive|define
name|ARTPEC6_CLK_SPI_PCLK
value|15
end_define

begin_define
define|#
directive|define
name|ARTPEC6_CLK_SPI_SSPCLK
value|16
end_define

begin_define
define|#
directive|define
name|ARTPEC6_CLK_SYS_TIMER
value|17
end_define

begin_define
define|#
directive|define
name|ARTPEC6_CLK_FRACDIV_IN
value|18
end_define

begin_define
define|#
directive|define
name|ARTPEC6_CLK_DBG_PCLK
value|19
end_define

begin_comment
comment|/* This must be the highest clock index plus one. */
end_comment

begin_define
define|#
directive|define
name|ARTPEC6_CLK_NUMCLOCKS
value|20
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

