begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2015 Joachim Eastwood<manabian@gmail.com>  *  * This code is released using a dual license strategy: BSD/GPL  * You can choose the licence that better fits your requirements.  *  * Released under the terms of 3-clause BSD License  * Released under the terms of GNU General Public License Version 2.0  *  */
end_comment

begin_comment
comment|/* Clock Control Unit 1 (CCU1) clock offsets */
end_comment

begin_define
define|#
directive|define
name|CLK_APB3_BUS
value|0x100
end_define

begin_define
define|#
directive|define
name|CLK_APB3_I2C1
value|0x108
end_define

begin_define
define|#
directive|define
name|CLK_APB3_DAC
value|0x110
end_define

begin_define
define|#
directive|define
name|CLK_APB3_ADC0
value|0x118
end_define

begin_define
define|#
directive|define
name|CLK_APB3_ADC1
value|0x120
end_define

begin_define
define|#
directive|define
name|CLK_APB3_CAN0
value|0x128
end_define

begin_define
define|#
directive|define
name|CLK_APB1_BUS
value|0x200
end_define

begin_define
define|#
directive|define
name|CLK_APB1_MOTOCON_PWM
value|0x208
end_define

begin_define
define|#
directive|define
name|CLK_APB1_I2C0
value|0x210
end_define

begin_define
define|#
directive|define
name|CLK_APB1_I2S
value|0x218
end_define

begin_define
define|#
directive|define
name|CLK_APB1_CAN1
value|0x220
end_define

begin_define
define|#
directive|define
name|CLK_SPIFI
value|0x300
end_define

begin_define
define|#
directive|define
name|CLK_CPU_BUS
value|0x400
end_define

begin_define
define|#
directive|define
name|CLK_CPU_SPIFI
value|0x408
end_define

begin_define
define|#
directive|define
name|CLK_CPU_GPIO
value|0x410
end_define

begin_define
define|#
directive|define
name|CLK_CPU_LCD
value|0x418
end_define

begin_define
define|#
directive|define
name|CLK_CPU_ETHERNET
value|0x420
end_define

begin_define
define|#
directive|define
name|CLK_CPU_USB0
value|0x428
end_define

begin_define
define|#
directive|define
name|CLK_CPU_EMC
value|0x430
end_define

begin_define
define|#
directive|define
name|CLK_CPU_SDIO
value|0x438
end_define

begin_define
define|#
directive|define
name|CLK_CPU_DMA
value|0x440
end_define

begin_define
define|#
directive|define
name|CLK_CPU_CORE
value|0x448
end_define

begin_define
define|#
directive|define
name|CLK_CPU_SCT
value|0x468
end_define

begin_define
define|#
directive|define
name|CLK_CPU_USB1
value|0x470
end_define

begin_define
define|#
directive|define
name|CLK_CPU_EMCDIV
value|0x478
end_define

begin_define
define|#
directive|define
name|CLK_CPU_FLASHA
value|0x480
end_define

begin_define
define|#
directive|define
name|CLK_CPU_FLASHB
value|0x488
end_define

begin_define
define|#
directive|define
name|CLK_CPU_M0APP
value|0x490
end_define

begin_define
define|#
directive|define
name|CLK_CPU_ADCHS
value|0x498
end_define

begin_define
define|#
directive|define
name|CLK_CPU_EEPROM
value|0x4a0
end_define

begin_define
define|#
directive|define
name|CLK_CPU_WWDT
value|0x500
end_define

begin_define
define|#
directive|define
name|CLK_CPU_UART0
value|0x508
end_define

begin_define
define|#
directive|define
name|CLK_CPU_UART1
value|0x510
end_define

begin_define
define|#
directive|define
name|CLK_CPU_SSP0
value|0x518
end_define

begin_define
define|#
directive|define
name|CLK_CPU_TIMER0
value|0x520
end_define

begin_define
define|#
directive|define
name|CLK_CPU_TIMER1
value|0x528
end_define

begin_define
define|#
directive|define
name|CLK_CPU_SCU
value|0x530
end_define

begin_define
define|#
directive|define
name|CLK_CPU_CREG
value|0x538
end_define

begin_define
define|#
directive|define
name|CLK_CPU_RITIMER
value|0x600
end_define

begin_define
define|#
directive|define
name|CLK_CPU_UART2
value|0x608
end_define

begin_define
define|#
directive|define
name|CLK_CPU_UART3
value|0x610
end_define

begin_define
define|#
directive|define
name|CLK_CPU_TIMER2
value|0x618
end_define

begin_define
define|#
directive|define
name|CLK_CPU_TIMER3
value|0x620
end_define

begin_define
define|#
directive|define
name|CLK_CPU_SSP1
value|0x628
end_define

begin_define
define|#
directive|define
name|CLK_CPU_QEI
value|0x630
end_define

begin_define
define|#
directive|define
name|CLK_PERIPH_BUS
value|0x700
end_define

begin_define
define|#
directive|define
name|CLK_PERIPH_CORE
value|0x710
end_define

begin_define
define|#
directive|define
name|CLK_PERIPH_SGPIO
value|0x718
end_define

begin_define
define|#
directive|define
name|CLK_USB0
value|0x800
end_define

begin_define
define|#
directive|define
name|CLK_USB1
value|0x900
end_define

begin_define
define|#
directive|define
name|CLK_SPI
value|0xA00
end_define

begin_define
define|#
directive|define
name|CLK_ADCHS
value|0xB00
end_define

begin_comment
comment|/* Clock Control Unit 2 (CCU2) clock offsets */
end_comment

begin_define
define|#
directive|define
name|CLK_AUDIO
value|0x100
end_define

begin_define
define|#
directive|define
name|CLK_APB2_UART3
value|0x200
end_define

begin_define
define|#
directive|define
name|CLK_APB2_UART2
value|0x300
end_define

begin_define
define|#
directive|define
name|CLK_APB0_UART1
value|0x400
end_define

begin_define
define|#
directive|define
name|CLK_APB0_UART0
value|0x500
end_define

begin_define
define|#
directive|define
name|CLK_APB2_SSP1
value|0x600
end_define

begin_define
define|#
directive|define
name|CLK_APB0_SSP0
value|0x700
end_define

begin_define
define|#
directive|define
name|CLK_SDIO
value|0x800
end_define

end_unit

