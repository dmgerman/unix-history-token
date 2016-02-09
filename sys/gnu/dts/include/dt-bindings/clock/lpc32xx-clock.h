begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2015 Vladimir Zapolskiy<vz@mleia.com>  *  * This code is released using a dual license strategy: BSD/GPL  * You can choose the licence that better fits your requirements.  *  * Released under the terms of 3-clause BSD License  * Released under the terms of GNU General Public License Version 2.0  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_LPC32XX_CLOCK_H
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_LPC32XX_CLOCK_H
end_define

begin_comment
comment|/* LPC32XX System Control Block clocks */
end_comment

begin_define
define|#
directive|define
name|LPC32XX_CLK_RTC
value|1
end_define

begin_define
define|#
directive|define
name|LPC32XX_CLK_DMA
value|2
end_define

begin_define
define|#
directive|define
name|LPC32XX_CLK_MLC
value|3
end_define

begin_define
define|#
directive|define
name|LPC32XX_CLK_SLC
value|4
end_define

begin_define
define|#
directive|define
name|LPC32XX_CLK_LCD
value|5
end_define

begin_define
define|#
directive|define
name|LPC32XX_CLK_MAC
value|6
end_define

begin_define
define|#
directive|define
name|LPC32XX_CLK_SD
value|7
end_define

begin_define
define|#
directive|define
name|LPC32XX_CLK_DDRAM
value|8
end_define

begin_define
define|#
directive|define
name|LPC32XX_CLK_SSP0
value|9
end_define

begin_define
define|#
directive|define
name|LPC32XX_CLK_SSP1
value|10
end_define

begin_define
define|#
directive|define
name|LPC32XX_CLK_UART3
value|11
end_define

begin_define
define|#
directive|define
name|LPC32XX_CLK_UART4
value|12
end_define

begin_define
define|#
directive|define
name|LPC32XX_CLK_UART5
value|13
end_define

begin_define
define|#
directive|define
name|LPC32XX_CLK_UART6
value|14
end_define

begin_define
define|#
directive|define
name|LPC32XX_CLK_IRDA
value|15
end_define

begin_define
define|#
directive|define
name|LPC32XX_CLK_I2C1
value|16
end_define

begin_define
define|#
directive|define
name|LPC32XX_CLK_I2C2
value|17
end_define

begin_define
define|#
directive|define
name|LPC32XX_CLK_TIMER0
value|18
end_define

begin_define
define|#
directive|define
name|LPC32XX_CLK_TIMER1
value|19
end_define

begin_define
define|#
directive|define
name|LPC32XX_CLK_TIMER2
value|20
end_define

begin_define
define|#
directive|define
name|LPC32XX_CLK_TIMER3
value|21
end_define

begin_define
define|#
directive|define
name|LPC32XX_CLK_TIMER4
value|22
end_define

begin_define
define|#
directive|define
name|LPC32XX_CLK_TIMER5
value|23
end_define

begin_define
define|#
directive|define
name|LPC32XX_CLK_WDOG
value|24
end_define

begin_define
define|#
directive|define
name|LPC32XX_CLK_I2S0
value|25
end_define

begin_define
define|#
directive|define
name|LPC32XX_CLK_I2S1
value|26
end_define

begin_define
define|#
directive|define
name|LPC32XX_CLK_SPI1
value|27
end_define

begin_define
define|#
directive|define
name|LPC32XX_CLK_SPI2
value|28
end_define

begin_define
define|#
directive|define
name|LPC32XX_CLK_MCPWM
value|29
end_define

begin_define
define|#
directive|define
name|LPC32XX_CLK_HSTIMER
value|30
end_define

begin_define
define|#
directive|define
name|LPC32XX_CLK_KEY
value|31
end_define

begin_define
define|#
directive|define
name|LPC32XX_CLK_PWM1
value|32
end_define

begin_define
define|#
directive|define
name|LPC32XX_CLK_PWM2
value|33
end_define

begin_define
define|#
directive|define
name|LPC32XX_CLK_ADC
value|34
end_define

begin_comment
comment|/* LPC32XX USB clocks */
end_comment

begin_define
define|#
directive|define
name|LPC32XX_USB_CLK_I2C
value|1
end_define

begin_define
define|#
directive|define
name|LPC32XX_USB_CLK_DEVICE
value|2
end_define

begin_define
define|#
directive|define
name|LPC32XX_USB_CLK_HOST
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DT_BINDINGS_LPC32XX_CLOCK_H */
end_comment

end_unit

