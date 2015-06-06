begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Inspired by original work from pxa2xx-regs.h by Nicolas Pitre  * Copyright (C) 2014 Robert Jarzmik  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_CLOCK_PXA2XX_H__
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_CLOCK_PXA2XX_H__
end_define

begin_define
define|#
directive|define
name|CLK_NONE
value|0
end_define

begin_define
define|#
directive|define
name|CLK_1WIRE
value|1
end_define

begin_define
define|#
directive|define
name|CLK_AC97
value|2
end_define

begin_define
define|#
directive|define
name|CLK_AC97CONF
value|3
end_define

begin_define
define|#
directive|define
name|CLK_ASSP
value|4
end_define

begin_define
define|#
directive|define
name|CLK_BOOT
value|5
end_define

begin_define
define|#
directive|define
name|CLK_BTUART
value|6
end_define

begin_define
define|#
directive|define
name|CLK_CAMERA
value|7
end_define

begin_define
define|#
directive|define
name|CLK_CIR
value|8
end_define

begin_define
define|#
directive|define
name|CLK_CORE
value|9
end_define

begin_define
define|#
directive|define
name|CLK_DMC
value|10
end_define

begin_define
define|#
directive|define
name|CLK_FFUART
value|11
end_define

begin_define
define|#
directive|define
name|CLK_FICP
value|12
end_define

begin_define
define|#
directive|define
name|CLK_GPIO
value|13
end_define

begin_define
define|#
directive|define
name|CLK_HSIO2
value|14
end_define

begin_define
define|#
directive|define
name|CLK_HWUART
value|15
end_define

begin_define
define|#
directive|define
name|CLK_I2C
value|16
end_define

begin_define
define|#
directive|define
name|CLK_I2S
value|17
end_define

begin_define
define|#
directive|define
name|CLK_IM
value|18
end_define

begin_define
define|#
directive|define
name|CLK_INC
value|19
end_define

begin_define
define|#
directive|define
name|CLK_ISC
value|20
end_define

begin_define
define|#
directive|define
name|CLK_KEYPAD
value|21
end_define

begin_define
define|#
directive|define
name|CLK_LCD
value|22
end_define

begin_define
define|#
directive|define
name|CLK_MEMC
value|23
end_define

begin_define
define|#
directive|define
name|CLK_MEMSTK
value|24
end_define

begin_define
define|#
directive|define
name|CLK_MINI_IM
value|25
end_define

begin_define
define|#
directive|define
name|CLK_MINI_LCD
value|26
end_define

begin_define
define|#
directive|define
name|CLK_MMC
value|27
end_define

begin_define
define|#
directive|define
name|CLK_MMC1
value|28
end_define

begin_define
define|#
directive|define
name|CLK_MMC2
value|29
end_define

begin_define
define|#
directive|define
name|CLK_MMC3
value|30
end_define

begin_define
define|#
directive|define
name|CLK_MSL
value|31
end_define

begin_define
define|#
directive|define
name|CLK_MSL0
value|32
end_define

begin_define
define|#
directive|define
name|CLK_MVED
value|33
end_define

begin_define
define|#
directive|define
name|CLK_NAND
value|34
end_define

begin_define
define|#
directive|define
name|CLK_NSSP
value|35
end_define

begin_define
define|#
directive|define
name|CLK_OSTIMER
value|36
end_define

begin_define
define|#
directive|define
name|CLK_PWM0
value|37
end_define

begin_define
define|#
directive|define
name|CLK_PWM1
value|38
end_define

begin_define
define|#
directive|define
name|CLK_PWM2
value|39
end_define

begin_define
define|#
directive|define
name|CLK_PWM3
value|40
end_define

begin_define
define|#
directive|define
name|CLK_PWRI2C
value|41
end_define

begin_define
define|#
directive|define
name|CLK_PXA300_GCU
value|42
end_define

begin_define
define|#
directive|define
name|CLK_PXA320_GCU
value|43
end_define

begin_define
define|#
directive|define
name|CLK_SMC
value|44
end_define

begin_define
define|#
directive|define
name|CLK_SSP
value|45
end_define

begin_define
define|#
directive|define
name|CLK_SSP1
value|46
end_define

begin_define
define|#
directive|define
name|CLK_SSP2
value|47
end_define

begin_define
define|#
directive|define
name|CLK_SSP3
value|48
end_define

begin_define
define|#
directive|define
name|CLK_SSP4
value|49
end_define

begin_define
define|#
directive|define
name|CLK_STUART
value|50
end_define

begin_define
define|#
directive|define
name|CLK_TOUCH
value|51
end_define

begin_define
define|#
directive|define
name|CLK_TPM
value|52
end_define

begin_define
define|#
directive|define
name|CLK_UDC
value|53
end_define

begin_define
define|#
directive|define
name|CLK_USB
value|54
end_define

begin_define
define|#
directive|define
name|CLK_USB2
value|55
end_define

begin_define
define|#
directive|define
name|CLK_USBH
value|56
end_define

begin_define
define|#
directive|define
name|CLK_USBHOST
value|57
end_define

begin_define
define|#
directive|define
name|CLK_USIM
value|58
end_define

begin_define
define|#
directive|define
name|CLK_USIM1
value|59
end_define

begin_define
define|#
directive|define
name|CLK_USMI0
value|60
end_define

begin_define
define|#
directive|define
name|CLK_MAX
value|61
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

