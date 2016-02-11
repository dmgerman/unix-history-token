begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2014 Oleksij Rempel<linux@rempel-privat.de>  *  * This software is licensed under the terms of the GNU General Public  * License version 2, as published by the Free Software Foundation, and  * may be copied, distributed, and modified under those terms.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLK_ASM9260_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLK_ASM9260_H
end_define

begin_comment
comment|/* ahb gate */
end_comment

begin_define
define|#
directive|define
name|CLKID_AHB_ROM
value|0
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_RAM
value|1
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_GPIO
value|2
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_MAC
value|3
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_EMI
value|4
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_USB0
value|5
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_USB1
value|6
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_DMA0
value|7
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_DMA1
value|8
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_UART0
value|9
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_UART1
value|10
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_UART2
value|11
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_UART3
value|12
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_UART4
value|13
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_UART5
value|14
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_UART6
value|15
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_UART7
value|16
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_UART8
value|17
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_UART9
value|18
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_I2S0
value|19
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_I2C0
value|20
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_I2C1
value|21
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_SSP0
value|22
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_IOCONFIG
value|23
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_WDT
value|24
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_CAN0
value|25
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_CAN1
value|26
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_MPWM
value|27
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_SPI0
value|28
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_SPI1
value|29
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_QEI
value|30
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_QUADSPI0
value|31
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_CAMIF
value|32
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_LCDIF
value|33
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_TIMER0
value|34
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_TIMER1
value|35
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_TIMER2
value|36
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_TIMER3
value|37
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_IRQ
value|38
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_RTC
value|39
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_NAND
value|40
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_ADC0
value|41
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_LED
value|42
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_DAC0
value|43
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_LCD
value|44
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_I2S1
value|45
end_define

begin_define
define|#
directive|define
name|CLKID_AHB_MAC1
value|46
end_define

begin_comment
comment|/* devider */
end_comment

begin_define
define|#
directive|define
name|CLKID_SYS_CPU
value|47
end_define

begin_define
define|#
directive|define
name|CLKID_SYS_AHB
value|48
end_define

begin_define
define|#
directive|define
name|CLKID_SYS_I2S0M
value|49
end_define

begin_define
define|#
directive|define
name|CLKID_SYS_I2S0S
value|50
end_define

begin_define
define|#
directive|define
name|CLKID_SYS_I2S1M
value|51
end_define

begin_define
define|#
directive|define
name|CLKID_SYS_I2S1S
value|52
end_define

begin_define
define|#
directive|define
name|CLKID_SYS_UART0
value|53
end_define

begin_define
define|#
directive|define
name|CLKID_SYS_UART1
value|54
end_define

begin_define
define|#
directive|define
name|CLKID_SYS_UART2
value|55
end_define

begin_define
define|#
directive|define
name|CLKID_SYS_UART3
value|56
end_define

begin_define
define|#
directive|define
name|CLKID_SYS_UART4
value|56
end_define

begin_define
define|#
directive|define
name|CLKID_SYS_UART5
value|57
end_define

begin_define
define|#
directive|define
name|CLKID_SYS_UART6
value|58
end_define

begin_define
define|#
directive|define
name|CLKID_SYS_UART7
value|59
end_define

begin_define
define|#
directive|define
name|CLKID_SYS_UART8
value|60
end_define

begin_define
define|#
directive|define
name|CLKID_SYS_UART9
value|61
end_define

begin_define
define|#
directive|define
name|CLKID_SYS_SPI0
value|62
end_define

begin_define
define|#
directive|define
name|CLKID_SYS_SPI1
value|63
end_define

begin_define
define|#
directive|define
name|CLKID_SYS_QUADSPI
value|64
end_define

begin_define
define|#
directive|define
name|CLKID_SYS_SSP0
value|65
end_define

begin_define
define|#
directive|define
name|CLKID_SYS_NAND
value|66
end_define

begin_define
define|#
directive|define
name|CLKID_SYS_TRACE
value|67
end_define

begin_define
define|#
directive|define
name|CLKID_SYS_CAMM
value|68
end_define

begin_define
define|#
directive|define
name|CLKID_SYS_WDT
value|69
end_define

begin_define
define|#
directive|define
name|CLKID_SYS_CLKOUT
value|70
end_define

begin_define
define|#
directive|define
name|CLKID_SYS_MAC
value|71
end_define

begin_define
define|#
directive|define
name|CLKID_SYS_LCD
value|72
end_define

begin_define
define|#
directive|define
name|CLKID_SYS_ADCANA
value|73
end_define

begin_define
define|#
directive|define
name|MAX_CLKS
value|74
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

