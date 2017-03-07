begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * GPIO definitions for Amlogic Meson GXL SoCs  *  * Copyright (C) 2016 Endless Mobile, Inc.  * Author: Carlo Caione<carlo@endlessm.com>  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License  * version 2 as published by the Free Software Foundation.  *  * You should have received a copy of the GNU General Public License  * along with this program. If not, see<http://www.gnu.org/licenses/>.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_MESON_GXL_GPIO_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_MESON_GXL_GPIO_H
end_define

begin_define
define|#
directive|define
name|GPIOAO_0
value|0
end_define

begin_define
define|#
directive|define
name|GPIOAO_1
value|1
end_define

begin_define
define|#
directive|define
name|GPIOAO_2
value|2
end_define

begin_define
define|#
directive|define
name|GPIOAO_3
value|3
end_define

begin_define
define|#
directive|define
name|GPIOAO_4
value|4
end_define

begin_define
define|#
directive|define
name|GPIOAO_5
value|5
end_define

begin_define
define|#
directive|define
name|GPIOAO_6
value|6
end_define

begin_define
define|#
directive|define
name|GPIOAO_7
value|7
end_define

begin_define
define|#
directive|define
name|GPIOAO_8
value|8
end_define

begin_define
define|#
directive|define
name|GPIOAO_9
value|9
end_define

begin_define
define|#
directive|define
name|GPIOZ_0
value|0
end_define

begin_define
define|#
directive|define
name|GPIOZ_1
value|1
end_define

begin_define
define|#
directive|define
name|GPIOZ_2
value|2
end_define

begin_define
define|#
directive|define
name|GPIOZ_3
value|3
end_define

begin_define
define|#
directive|define
name|GPIOZ_4
value|4
end_define

begin_define
define|#
directive|define
name|GPIOZ_5
value|5
end_define

begin_define
define|#
directive|define
name|GPIOZ_6
value|6
end_define

begin_define
define|#
directive|define
name|GPIOZ_7
value|7
end_define

begin_define
define|#
directive|define
name|GPIOZ_8
value|8
end_define

begin_define
define|#
directive|define
name|GPIOZ_9
value|9
end_define

begin_define
define|#
directive|define
name|GPIOZ_10
value|10
end_define

begin_define
define|#
directive|define
name|GPIOZ_11
value|11
end_define

begin_define
define|#
directive|define
name|GPIOZ_12
value|12
end_define

begin_define
define|#
directive|define
name|GPIOZ_13
value|13
end_define

begin_define
define|#
directive|define
name|GPIOZ_14
value|14
end_define

begin_define
define|#
directive|define
name|GPIOZ_15
value|15
end_define

begin_define
define|#
directive|define
name|GPIOH_0
value|16
end_define

begin_define
define|#
directive|define
name|GPIOH_1
value|17
end_define

begin_define
define|#
directive|define
name|GPIOH_2
value|18
end_define

begin_define
define|#
directive|define
name|GPIOH_3
value|19
end_define

begin_define
define|#
directive|define
name|GPIOH_4
value|20
end_define

begin_define
define|#
directive|define
name|GPIOH_5
value|21
end_define

begin_define
define|#
directive|define
name|GPIOH_6
value|22
end_define

begin_define
define|#
directive|define
name|GPIOH_7
value|23
end_define

begin_define
define|#
directive|define
name|GPIOH_8
value|24
end_define

begin_define
define|#
directive|define
name|GPIOH_9
value|25
end_define

begin_define
define|#
directive|define
name|BOOT_0
value|26
end_define

begin_define
define|#
directive|define
name|BOOT_1
value|27
end_define

begin_define
define|#
directive|define
name|BOOT_2
value|28
end_define

begin_define
define|#
directive|define
name|BOOT_3
value|29
end_define

begin_define
define|#
directive|define
name|BOOT_4
value|30
end_define

begin_define
define|#
directive|define
name|BOOT_5
value|31
end_define

begin_define
define|#
directive|define
name|BOOT_6
value|32
end_define

begin_define
define|#
directive|define
name|BOOT_7
value|33
end_define

begin_define
define|#
directive|define
name|BOOT_8
value|34
end_define

begin_define
define|#
directive|define
name|BOOT_9
value|35
end_define

begin_define
define|#
directive|define
name|BOOT_10
value|36
end_define

begin_define
define|#
directive|define
name|BOOT_11
value|37
end_define

begin_define
define|#
directive|define
name|BOOT_12
value|38
end_define

begin_define
define|#
directive|define
name|BOOT_13
value|39
end_define

begin_define
define|#
directive|define
name|BOOT_14
value|40
end_define

begin_define
define|#
directive|define
name|BOOT_15
value|41
end_define

begin_define
define|#
directive|define
name|CARD_0
value|42
end_define

begin_define
define|#
directive|define
name|CARD_1
value|43
end_define

begin_define
define|#
directive|define
name|CARD_2
value|44
end_define

begin_define
define|#
directive|define
name|CARD_3
value|45
end_define

begin_define
define|#
directive|define
name|CARD_4
value|46
end_define

begin_define
define|#
directive|define
name|CARD_5
value|47
end_define

begin_define
define|#
directive|define
name|CARD_6
value|48
end_define

begin_define
define|#
directive|define
name|GPIODV_0
value|49
end_define

begin_define
define|#
directive|define
name|GPIODV_1
value|50
end_define

begin_define
define|#
directive|define
name|GPIODV_2
value|51
end_define

begin_define
define|#
directive|define
name|GPIODV_3
value|52
end_define

begin_define
define|#
directive|define
name|GPIODV_4
value|53
end_define

begin_define
define|#
directive|define
name|GPIODV_5
value|54
end_define

begin_define
define|#
directive|define
name|GPIODV_6
value|55
end_define

begin_define
define|#
directive|define
name|GPIODV_7
value|56
end_define

begin_define
define|#
directive|define
name|GPIODV_8
value|57
end_define

begin_define
define|#
directive|define
name|GPIODV_9
value|58
end_define

begin_define
define|#
directive|define
name|GPIODV_10
value|59
end_define

begin_define
define|#
directive|define
name|GPIODV_11
value|60
end_define

begin_define
define|#
directive|define
name|GPIODV_12
value|61
end_define

begin_define
define|#
directive|define
name|GPIODV_13
value|62
end_define

begin_define
define|#
directive|define
name|GPIODV_14
value|63
end_define

begin_define
define|#
directive|define
name|GPIODV_15
value|64
end_define

begin_define
define|#
directive|define
name|GPIODV_16
value|65
end_define

begin_define
define|#
directive|define
name|GPIODV_17
value|66
end_define

begin_define
define|#
directive|define
name|GPIODV_18
value|67
end_define

begin_define
define|#
directive|define
name|GPIODV_19
value|68
end_define

begin_define
define|#
directive|define
name|GPIODV_20
value|69
end_define

begin_define
define|#
directive|define
name|GPIODV_21
value|70
end_define

begin_define
define|#
directive|define
name|GPIODV_22
value|71
end_define

begin_define
define|#
directive|define
name|GPIODV_23
value|72
end_define

begin_define
define|#
directive|define
name|GPIODV_24
value|73
end_define

begin_define
define|#
directive|define
name|GPIODV_25
value|74
end_define

begin_define
define|#
directive|define
name|GPIODV_26
value|75
end_define

begin_define
define|#
directive|define
name|GPIODV_27
value|76
end_define

begin_define
define|#
directive|define
name|GPIODV_28
value|77
end_define

begin_define
define|#
directive|define
name|GPIODV_29
value|78
end_define

begin_define
define|#
directive|define
name|GPIOX_0
value|79
end_define

begin_define
define|#
directive|define
name|GPIOX_1
value|80
end_define

begin_define
define|#
directive|define
name|GPIOX_2
value|81
end_define

begin_define
define|#
directive|define
name|GPIOX_3
value|82
end_define

begin_define
define|#
directive|define
name|GPIOX_4
value|83
end_define

begin_define
define|#
directive|define
name|GPIOX_5
value|84
end_define

begin_define
define|#
directive|define
name|GPIOX_6
value|85
end_define

begin_define
define|#
directive|define
name|GPIOX_7
value|86
end_define

begin_define
define|#
directive|define
name|GPIOX_8
value|87
end_define

begin_define
define|#
directive|define
name|GPIOX_9
value|88
end_define

begin_define
define|#
directive|define
name|GPIOX_10
value|89
end_define

begin_define
define|#
directive|define
name|GPIOX_11
value|90
end_define

begin_define
define|#
directive|define
name|GPIOX_12
value|91
end_define

begin_define
define|#
directive|define
name|GPIOX_13
value|92
end_define

begin_define
define|#
directive|define
name|GPIOX_14
value|93
end_define

begin_define
define|#
directive|define
name|GPIOX_15
value|94
end_define

begin_define
define|#
directive|define
name|GPIOX_16
value|95
end_define

begin_define
define|#
directive|define
name|GPIOX_17
value|96
end_define

begin_define
define|#
directive|define
name|GPIOX_18
value|97
end_define

begin_define
define|#
directive|define
name|GPIOCLK_0
value|98
end_define

begin_define
define|#
directive|define
name|GPIOCLK_1
value|99
end_define

begin_define
define|#
directive|define
name|GPIO_TEST_N
value|100
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

