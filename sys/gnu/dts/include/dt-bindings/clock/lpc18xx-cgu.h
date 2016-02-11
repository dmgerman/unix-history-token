begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2015 Joachim Eastwood<manabian@gmail.com>  *  * This code is released using a dual license strategy: BSD/GPL  * You can choose the licence that better fits your requirements.  *  * Released under the terms of 3-clause BSD License  * Released under the terms of GNU General Public License Version 2.0  *  */
end_comment

begin_comment
comment|/* LPC18xx/43xx base clock ids */
end_comment

begin_define
define|#
directive|define
name|BASE_SAFE_CLK
value|0
end_define

begin_define
define|#
directive|define
name|BASE_USB0_CLK
value|1
end_define

begin_define
define|#
directive|define
name|BASE_PERIPH_CLK
value|2
end_define

begin_define
define|#
directive|define
name|BASE_USB1_CLK
value|3
end_define

begin_define
define|#
directive|define
name|BASE_CPU_CLK
value|4
end_define

begin_define
define|#
directive|define
name|BASE_SPIFI_CLK
value|5
end_define

begin_define
define|#
directive|define
name|BASE_SPI_CLK
value|6
end_define

begin_define
define|#
directive|define
name|BASE_PHY_RX_CLK
value|7
end_define

begin_define
define|#
directive|define
name|BASE_PHY_TX_CLK
value|8
end_define

begin_define
define|#
directive|define
name|BASE_APB1_CLK
value|9
end_define

begin_define
define|#
directive|define
name|BASE_APB3_CLK
value|10
end_define

begin_define
define|#
directive|define
name|BASE_LCD_CLK
value|11
end_define

begin_define
define|#
directive|define
name|BASE_ADCHS_CLK
value|12
end_define

begin_define
define|#
directive|define
name|BASE_SDIO_CLK
value|13
end_define

begin_define
define|#
directive|define
name|BASE_SSP0_CLK
value|14
end_define

begin_define
define|#
directive|define
name|BASE_SSP1_CLK
value|15
end_define

begin_define
define|#
directive|define
name|BASE_UART0_CLK
value|16
end_define

begin_define
define|#
directive|define
name|BASE_UART1_CLK
value|17
end_define

begin_define
define|#
directive|define
name|BASE_UART2_CLK
value|18
end_define

begin_define
define|#
directive|define
name|BASE_UART3_CLK
value|19
end_define

begin_define
define|#
directive|define
name|BASE_OUT_CLK
value|20
end_define

begin_define
define|#
directive|define
name|BASE_RES1_CLK
value|21
end_define

begin_define
define|#
directive|define
name|BASE_RES2_CLK
value|22
end_define

begin_define
define|#
directive|define
name|BASE_RES3_CLK
value|23
end_define

begin_define
define|#
directive|define
name|BASE_RES4_CLK
value|24
end_define

begin_define
define|#
directive|define
name|BASE_AUDIO_CLK
value|25
end_define

begin_define
define|#
directive|define
name|BASE_CGU_OUT0_CLK
value|26
end_define

begin_define
define|#
directive|define
name|BASE_CGU_OUT1_CLK
value|27
end_define

begin_define
define|#
directive|define
name|BASE_CLK_MAX
value|(BASE_CGU_OUT1_CLK + 1)
end_define

end_unit

