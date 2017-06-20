begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2015 Broadcom Corporation  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation version 2.  *  * This program is distributed "as is" WITHOUT ANY WARRANTY of any  * kind, whether express or implied; without even the implied warranty  * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_define
define|#
directive|define
name|BCM2835_PLLA
value|0
end_define

begin_define
define|#
directive|define
name|BCM2835_PLLB
value|1
end_define

begin_define
define|#
directive|define
name|BCM2835_PLLC
value|2
end_define

begin_define
define|#
directive|define
name|BCM2835_PLLD
value|3
end_define

begin_define
define|#
directive|define
name|BCM2835_PLLH
value|4
end_define

begin_define
define|#
directive|define
name|BCM2835_PLLA_CORE
value|5
end_define

begin_define
define|#
directive|define
name|BCM2835_PLLA_PER
value|6
end_define

begin_define
define|#
directive|define
name|BCM2835_PLLB_ARM
value|7
end_define

begin_define
define|#
directive|define
name|BCM2835_PLLC_CORE0
value|8
end_define

begin_define
define|#
directive|define
name|BCM2835_PLLC_CORE1
value|9
end_define

begin_define
define|#
directive|define
name|BCM2835_PLLC_CORE2
value|10
end_define

begin_define
define|#
directive|define
name|BCM2835_PLLC_PER
value|11
end_define

begin_define
define|#
directive|define
name|BCM2835_PLLD_CORE
value|12
end_define

begin_define
define|#
directive|define
name|BCM2835_PLLD_PER
value|13
end_define

begin_define
define|#
directive|define
name|BCM2835_PLLH_RCAL
value|14
end_define

begin_define
define|#
directive|define
name|BCM2835_PLLH_AUX
value|15
end_define

begin_define
define|#
directive|define
name|BCM2835_PLLH_PIX
value|16
end_define

begin_define
define|#
directive|define
name|BCM2835_CLOCK_TIMER
value|17
end_define

begin_define
define|#
directive|define
name|BCM2835_CLOCK_OTP
value|18
end_define

begin_define
define|#
directive|define
name|BCM2835_CLOCK_UART
value|19
end_define

begin_define
define|#
directive|define
name|BCM2835_CLOCK_VPU
value|20
end_define

begin_define
define|#
directive|define
name|BCM2835_CLOCK_V3D
value|21
end_define

begin_define
define|#
directive|define
name|BCM2835_CLOCK_ISP
value|22
end_define

begin_define
define|#
directive|define
name|BCM2835_CLOCK_H264
value|23
end_define

begin_define
define|#
directive|define
name|BCM2835_CLOCK_VEC
value|24
end_define

begin_define
define|#
directive|define
name|BCM2835_CLOCK_HSM
value|25
end_define

begin_define
define|#
directive|define
name|BCM2835_CLOCK_SDRAM
value|26
end_define

begin_define
define|#
directive|define
name|BCM2835_CLOCK_TSENS
value|27
end_define

begin_define
define|#
directive|define
name|BCM2835_CLOCK_EMMC
value|28
end_define

begin_define
define|#
directive|define
name|BCM2835_CLOCK_PERI_IMAGE
value|29
end_define

begin_define
define|#
directive|define
name|BCM2835_CLOCK_PWM
value|30
end_define

begin_define
define|#
directive|define
name|BCM2835_CLOCK_PCM
value|31
end_define

begin_define
define|#
directive|define
name|BCM2835_PLLA_DSI0
value|32
end_define

begin_define
define|#
directive|define
name|BCM2835_PLLA_CCP2
value|33
end_define

begin_define
define|#
directive|define
name|BCM2835_PLLD_DSI0
value|34
end_define

begin_define
define|#
directive|define
name|BCM2835_PLLD_DSI1
value|35
end_define

begin_define
define|#
directive|define
name|BCM2835_CLOCK_AVEO
value|36
end_define

begin_define
define|#
directive|define
name|BCM2835_CLOCK_DFT
value|37
end_define

begin_define
define|#
directive|define
name|BCM2835_CLOCK_GP0
value|38
end_define

begin_define
define|#
directive|define
name|BCM2835_CLOCK_GP1
value|39
end_define

begin_define
define|#
directive|define
name|BCM2835_CLOCK_GP2
value|40
end_define

begin_define
define|#
directive|define
name|BCM2835_CLOCK_SLIM
value|41
end_define

begin_define
define|#
directive|define
name|BCM2835_CLOCK_SMI
value|42
end_define

begin_define
define|#
directive|define
name|BCM2835_CLOCK_TEC
value|43
end_define

begin_define
define|#
directive|define
name|BCM2835_CLOCK_DPI
value|44
end_define

begin_define
define|#
directive|define
name|BCM2835_CLOCK_CAM0
value|45
end_define

begin_define
define|#
directive|define
name|BCM2835_CLOCK_CAM1
value|46
end_define

begin_define
define|#
directive|define
name|BCM2835_CLOCK_DSI0E
value|47
end_define

begin_define
define|#
directive|define
name|BCM2835_CLOCK_DSI1E
value|48
end_define

begin_define
define|#
directive|define
name|BCM2835_CLOCK_DSI0P
value|49
end_define

begin_define
define|#
directive|define
name|BCM2835_CLOCK_DSI1P
value|50
end_define

end_unit

