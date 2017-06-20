begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * stm32fx-clock.h  *  * Copyright (C) 2016 STMicroelectronics  * Author: Gabriel Fernandez for STMicroelectronics.  * License terms:  GNU General Public License (GPL), version 2  */
end_comment

begin_comment
comment|/*  * List of clocks wich are not derived from system clock (SYSCLOCK)  *  * The index of these clocks is the secondary index of DT bindings  * (see Documentatoin/devicetree/bindings/clock/st,stm32-rcc.txt)  *  * e.g:<assigned-clocks =<&rcc 1 CLK_LSE>; */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLK_STMFX_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLK_STMFX_H
end_define

begin_define
define|#
directive|define
name|SYSTICK
value|0
end_define

begin_define
define|#
directive|define
name|FCLK
value|1
end_define

begin_define
define|#
directive|define
name|CLK_LSI
value|2
end_define

begin_define
define|#
directive|define
name|CLK_LSE
value|3
end_define

begin_define
define|#
directive|define
name|CLK_HSE_RTC
value|4
end_define

begin_define
define|#
directive|define
name|CLK_RTC
value|5
end_define

begin_define
define|#
directive|define
name|PLL_VCO_I2S
value|6
end_define

begin_define
define|#
directive|define
name|PLL_VCO_SAI
value|7
end_define

begin_define
define|#
directive|define
name|CLK_LCD
value|8
end_define

begin_define
define|#
directive|define
name|CLK_I2S
value|9
end_define

begin_define
define|#
directive|define
name|CLK_SAI1
value|10
end_define

begin_define
define|#
directive|define
name|CLK_SAI2
value|11
end_define

begin_define
define|#
directive|define
name|CLK_I2SQ_PDIV
value|12
end_define

begin_define
define|#
directive|define
name|CLK_SAIQ_PDIV
value|13
end_define

begin_define
define|#
directive|define
name|END_PRIMARY_CLK
value|14
end_define

begin_define
define|#
directive|define
name|CLK_HSI
value|14
end_define

begin_define
define|#
directive|define
name|CLK_SYSCLK
value|15
end_define

begin_define
define|#
directive|define
name|CLK_HDMI_CEC
value|16
end_define

begin_define
define|#
directive|define
name|CLK_SPDIF
value|17
end_define

begin_define
define|#
directive|define
name|CLK_USART1
value|18
end_define

begin_define
define|#
directive|define
name|CLK_USART2
value|19
end_define

begin_define
define|#
directive|define
name|CLK_USART3
value|20
end_define

begin_define
define|#
directive|define
name|CLK_UART4
value|21
end_define

begin_define
define|#
directive|define
name|CLK_UART5
value|22
end_define

begin_define
define|#
directive|define
name|CLK_USART6
value|23
end_define

begin_define
define|#
directive|define
name|CLK_UART7
value|24
end_define

begin_define
define|#
directive|define
name|CLK_UART8
value|25
end_define

begin_define
define|#
directive|define
name|CLK_I2C1
value|26
end_define

begin_define
define|#
directive|define
name|CLK_I2C2
value|27
end_define

begin_define
define|#
directive|define
name|CLK_I2C3
value|28
end_define

begin_define
define|#
directive|define
name|CLK_I2C4
value|29
end_define

begin_define
define|#
directive|define
name|CLK_LPTIMER
value|30
end_define

begin_define
define|#
directive|define
name|END_PRIMARY_CLK_F7
value|31
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

