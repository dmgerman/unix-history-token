begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2014 Google, Inc.  *  * This program is free software; you can redistribute it and/or modify it  * under the terms and conditions of the GNU General Public License,  * version 2, as published by the Free Software Foundation.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLOCK_PISTACHIO_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLOCK_PISTACHIO_H
end_define

begin_comment
comment|/* PLLs */
end_comment

begin_define
define|#
directive|define
name|CLK_MIPS_PLL
value|0
end_define

begin_define
define|#
directive|define
name|CLK_AUDIO_PLL
value|1
end_define

begin_define
define|#
directive|define
name|CLK_RPU_V_PLL
value|2
end_define

begin_define
define|#
directive|define
name|CLK_RPU_L_PLL
value|3
end_define

begin_define
define|#
directive|define
name|CLK_SYS_PLL
value|4
end_define

begin_define
define|#
directive|define
name|CLK_WIFI_PLL
value|5
end_define

begin_define
define|#
directive|define
name|CLK_BT_PLL
value|6
end_define

begin_comment
comment|/* Fixed-factor clocks */
end_comment

begin_define
define|#
directive|define
name|CLK_WIFI_DIV4
value|16
end_define

begin_define
define|#
directive|define
name|CLK_WIFI_DIV8
value|17
end_define

begin_comment
comment|/* Gate clocks */
end_comment

begin_define
define|#
directive|define
name|CLK_MIPS
value|32
end_define

begin_define
define|#
directive|define
name|CLK_AUDIO_IN
value|33
end_define

begin_define
define|#
directive|define
name|CLK_AUDIO
value|34
end_define

begin_define
define|#
directive|define
name|CLK_I2S
value|35
end_define

begin_define
define|#
directive|define
name|CLK_SPDIF
value|36
end_define

begin_define
define|#
directive|define
name|CLK_AUDIO_DAC
value|37
end_define

begin_define
define|#
directive|define
name|CLK_RPU_V
value|38
end_define

begin_define
define|#
directive|define
name|CLK_RPU_L
value|39
end_define

begin_define
define|#
directive|define
name|CLK_RPU_SLEEP
value|40
end_define

begin_define
define|#
directive|define
name|CLK_WIFI_PLL_GATE
value|41
end_define

begin_define
define|#
directive|define
name|CLK_RPU_CORE
value|42
end_define

begin_define
define|#
directive|define
name|CLK_WIFI_ADC
value|43
end_define

begin_define
define|#
directive|define
name|CLK_WIFI_DAC
value|44
end_define

begin_define
define|#
directive|define
name|CLK_USB_PHY
value|45
end_define

begin_define
define|#
directive|define
name|CLK_ENET_IN
value|46
end_define

begin_define
define|#
directive|define
name|CLK_ENET
value|47
end_define

begin_define
define|#
directive|define
name|CLK_UART0
value|48
end_define

begin_define
define|#
directive|define
name|CLK_UART1
value|49
end_define

begin_define
define|#
directive|define
name|CLK_PERIPH_SYS
value|50
end_define

begin_define
define|#
directive|define
name|CLK_SPI0
value|51
end_define

begin_define
define|#
directive|define
name|CLK_SPI1
value|52
end_define

begin_define
define|#
directive|define
name|CLK_EVENT_TIMER
value|53
end_define

begin_define
define|#
directive|define
name|CLK_AUX_ADC_INTERNAL
value|54
end_define

begin_define
define|#
directive|define
name|CLK_AUX_ADC
value|55
end_define

begin_define
define|#
directive|define
name|CLK_SD_HOST
value|56
end_define

begin_define
define|#
directive|define
name|CLK_BT
value|57
end_define

begin_define
define|#
directive|define
name|CLK_BT_DIV4
value|58
end_define

begin_define
define|#
directive|define
name|CLK_BT_DIV8
value|59
end_define

begin_define
define|#
directive|define
name|CLK_BT_1MHZ
value|60
end_define

begin_comment
comment|/* Divider clocks */
end_comment

begin_define
define|#
directive|define
name|CLK_MIPS_INTERNAL_DIV
value|64
end_define

begin_define
define|#
directive|define
name|CLK_MIPS_DIV
value|65
end_define

begin_define
define|#
directive|define
name|CLK_AUDIO_DIV
value|66
end_define

begin_define
define|#
directive|define
name|CLK_I2S_DIV
value|67
end_define

begin_define
define|#
directive|define
name|CLK_SPDIF_DIV
value|68
end_define

begin_define
define|#
directive|define
name|CLK_AUDIO_DAC_DIV
value|69
end_define

begin_define
define|#
directive|define
name|CLK_RPU_V_DIV
value|70
end_define

begin_define
define|#
directive|define
name|CLK_RPU_L_DIV
value|71
end_define

begin_define
define|#
directive|define
name|CLK_RPU_SLEEP_DIV
value|72
end_define

begin_define
define|#
directive|define
name|CLK_RPU_CORE_DIV
value|73
end_define

begin_define
define|#
directive|define
name|CLK_USB_PHY_DIV
value|74
end_define

begin_define
define|#
directive|define
name|CLK_ENET_DIV
value|75
end_define

begin_define
define|#
directive|define
name|CLK_UART0_INTERNAL_DIV
value|76
end_define

begin_define
define|#
directive|define
name|CLK_UART0_DIV
value|77
end_define

begin_define
define|#
directive|define
name|CLK_UART1_INTERNAL_DIV
value|78
end_define

begin_define
define|#
directive|define
name|CLK_UART1_DIV
value|79
end_define

begin_define
define|#
directive|define
name|CLK_SYS_INTERNAL_DIV
value|80
end_define

begin_define
define|#
directive|define
name|CLK_SPI0_INTERNAL_DIV
value|81
end_define

begin_define
define|#
directive|define
name|CLK_SPI0_DIV
value|82
end_define

begin_define
define|#
directive|define
name|CLK_SPI1_INTERNAL_DIV
value|83
end_define

begin_define
define|#
directive|define
name|CLK_SPI1_DIV
value|84
end_define

begin_define
define|#
directive|define
name|CLK_EVENT_TIMER_INTERNAL_DIV
value|85
end_define

begin_define
define|#
directive|define
name|CLK_EVENT_TIMER_DIV
value|86
end_define

begin_define
define|#
directive|define
name|CLK_AUX_ADC_INTERNAL_DIV
value|87
end_define

begin_define
define|#
directive|define
name|CLK_AUX_ADC_DIV
value|88
end_define

begin_define
define|#
directive|define
name|CLK_SD_HOST_DIV
value|89
end_define

begin_define
define|#
directive|define
name|CLK_BT_DIV
value|90
end_define

begin_define
define|#
directive|define
name|CLK_BT_DIV4_DIV
value|91
end_define

begin_define
define|#
directive|define
name|CLK_BT_DIV8_DIV
value|92
end_define

begin_define
define|#
directive|define
name|CLK_BT_1MHZ_INTERNAL_DIV
value|93
end_define

begin_define
define|#
directive|define
name|CLK_BT_1MHZ_DIV
value|94
end_define

begin_comment
comment|/* Mux clocks */
end_comment

begin_define
define|#
directive|define
name|CLK_AUDIO_REF_MUX
value|96
end_define

begin_define
define|#
directive|define
name|CLK_MIPS_PLL_MUX
value|97
end_define

begin_define
define|#
directive|define
name|CLK_AUDIO_PLL_MUX
value|98
end_define

begin_define
define|#
directive|define
name|CLK_AUDIO_MUX
value|99
end_define

begin_define
define|#
directive|define
name|CLK_RPU_V_PLL_MUX
value|100
end_define

begin_define
define|#
directive|define
name|CLK_RPU_L_PLL_MUX
value|101
end_define

begin_define
define|#
directive|define
name|CLK_RPU_L_MUX
value|102
end_define

begin_define
define|#
directive|define
name|CLK_WIFI_PLL_MUX
value|103
end_define

begin_define
define|#
directive|define
name|CLK_WIFI_DIV4_MUX
value|104
end_define

begin_define
define|#
directive|define
name|CLK_WIFI_DIV8_MUX
value|105
end_define

begin_define
define|#
directive|define
name|CLK_RPU_CORE_MUX
value|106
end_define

begin_define
define|#
directive|define
name|CLK_SYS_PLL_MUX
value|107
end_define

begin_define
define|#
directive|define
name|CLK_ENET_MUX
value|108
end_define

begin_define
define|#
directive|define
name|CLK_EVENT_TIMER_MUX
value|109
end_define

begin_define
define|#
directive|define
name|CLK_SD_HOST_MUX
value|110
end_define

begin_define
define|#
directive|define
name|CLK_BT_PLL_MUX
value|111
end_define

begin_define
define|#
directive|define
name|CLK_DEBUG_MUX
value|112
end_define

begin_define
define|#
directive|define
name|CLK_NR_CLKS
value|113
end_define

begin_comment
comment|/* Peripheral gate clocks */
end_comment

begin_define
define|#
directive|define
name|PERIPH_CLK_SYS
value|0
end_define

begin_define
define|#
directive|define
name|PERIPH_CLK_SYS_BUS
value|1
end_define

begin_define
define|#
directive|define
name|PERIPH_CLK_DDR
value|2
end_define

begin_define
define|#
directive|define
name|PERIPH_CLK_ROM
value|3
end_define

begin_define
define|#
directive|define
name|PERIPH_CLK_COUNTER_FAST
value|4
end_define

begin_define
define|#
directive|define
name|PERIPH_CLK_COUNTER_SLOW
value|5
end_define

begin_define
define|#
directive|define
name|PERIPH_CLK_IR
value|6
end_define

begin_define
define|#
directive|define
name|PERIPH_CLK_WD
value|7
end_define

begin_define
define|#
directive|define
name|PERIPH_CLK_PDM
value|8
end_define

begin_define
define|#
directive|define
name|PERIPH_CLK_PWM
value|9
end_define

begin_define
define|#
directive|define
name|PERIPH_CLK_I2C0
value|10
end_define

begin_define
define|#
directive|define
name|PERIPH_CLK_I2C1
value|11
end_define

begin_define
define|#
directive|define
name|PERIPH_CLK_I2C2
value|12
end_define

begin_define
define|#
directive|define
name|PERIPH_CLK_I2C3
value|13
end_define

begin_comment
comment|/* Peripheral divider clocks */
end_comment

begin_define
define|#
directive|define
name|PERIPH_CLK_ROM_DIV
value|32
end_define

begin_define
define|#
directive|define
name|PERIPH_CLK_COUNTER_FAST_DIV
value|33
end_define

begin_define
define|#
directive|define
name|PERIPH_CLK_COUNTER_SLOW_PRE_DIV
value|34
end_define

begin_define
define|#
directive|define
name|PERIPH_CLK_COUNTER_SLOW_DIV
value|35
end_define

begin_define
define|#
directive|define
name|PERIPH_CLK_IR_PRE_DIV
value|36
end_define

begin_define
define|#
directive|define
name|PERIPH_CLK_IR_DIV
value|37
end_define

begin_define
define|#
directive|define
name|PERIPH_CLK_WD_PRE_DIV
value|38
end_define

begin_define
define|#
directive|define
name|PERIPH_CLK_WD_DIV
value|39
end_define

begin_define
define|#
directive|define
name|PERIPH_CLK_PDM_PRE_DIV
value|40
end_define

begin_define
define|#
directive|define
name|PERIPH_CLK_PDM_DIV
value|41
end_define

begin_define
define|#
directive|define
name|PERIPH_CLK_PWM_PRE_DIV
value|42
end_define

begin_define
define|#
directive|define
name|PERIPH_CLK_PWM_DIV
value|43
end_define

begin_define
define|#
directive|define
name|PERIPH_CLK_I2C0_PRE_DIV
value|44
end_define

begin_define
define|#
directive|define
name|PERIPH_CLK_I2C0_DIV
value|45
end_define

begin_define
define|#
directive|define
name|PERIPH_CLK_I2C1_PRE_DIV
value|46
end_define

begin_define
define|#
directive|define
name|PERIPH_CLK_I2C1_DIV
value|47
end_define

begin_define
define|#
directive|define
name|PERIPH_CLK_I2C2_PRE_DIV
value|48
end_define

begin_define
define|#
directive|define
name|PERIPH_CLK_I2C2_DIV
value|49
end_define

begin_define
define|#
directive|define
name|PERIPH_CLK_I2C3_PRE_DIV
value|50
end_define

begin_define
define|#
directive|define
name|PERIPH_CLK_I2C3_DIV
value|51
end_define

begin_define
define|#
directive|define
name|PERIPH_CLK_NR_CLKS
value|52
end_define

begin_comment
comment|/* System gate clocks */
end_comment

begin_define
define|#
directive|define
name|SYS_CLK_I2C0
value|0
end_define

begin_define
define|#
directive|define
name|SYS_CLK_I2C1
value|1
end_define

begin_define
define|#
directive|define
name|SYS_CLK_I2C2
value|2
end_define

begin_define
define|#
directive|define
name|SYS_CLK_I2C3
value|3
end_define

begin_define
define|#
directive|define
name|SYS_CLK_I2S_IN
value|4
end_define

begin_define
define|#
directive|define
name|SYS_CLK_PAUD_OUT
value|5
end_define

begin_define
define|#
directive|define
name|SYS_CLK_SPDIF_OUT
value|6
end_define

begin_define
define|#
directive|define
name|SYS_CLK_SPI0_MASTER
value|7
end_define

begin_define
define|#
directive|define
name|SYS_CLK_SPI0_SLAVE
value|8
end_define

begin_define
define|#
directive|define
name|SYS_CLK_PWM
value|9
end_define

begin_define
define|#
directive|define
name|SYS_CLK_UART0
value|10
end_define

begin_define
define|#
directive|define
name|SYS_CLK_UART1
value|11
end_define

begin_define
define|#
directive|define
name|SYS_CLK_SPI1
value|12
end_define

begin_define
define|#
directive|define
name|SYS_CLK_MDC
value|13
end_define

begin_define
define|#
directive|define
name|SYS_CLK_SD_HOST
value|14
end_define

begin_define
define|#
directive|define
name|SYS_CLK_ENET
value|15
end_define

begin_define
define|#
directive|define
name|SYS_CLK_IR
value|16
end_define

begin_define
define|#
directive|define
name|SYS_CLK_WD
value|17
end_define

begin_define
define|#
directive|define
name|SYS_CLK_TIMER
value|18
end_define

begin_define
define|#
directive|define
name|SYS_CLK_I2S_OUT
value|24
end_define

begin_define
define|#
directive|define
name|SYS_CLK_SPDIF_IN
value|25
end_define

begin_define
define|#
directive|define
name|SYS_CLK_EVENT_TIMER
value|26
end_define

begin_define
define|#
directive|define
name|SYS_CLK_HASH
value|27
end_define

begin_define
define|#
directive|define
name|SYS_CLK_NR_CLKS
value|28
end_define

begin_comment
comment|/* Gates for external input clocks */
end_comment

begin_define
define|#
directive|define
name|EXT_CLK_AUDIO_IN
value|0
end_define

begin_define
define|#
directive|define
name|EXT_CLK_ENET_IN
value|1
end_define

begin_define
define|#
directive|define
name|EXT_CLK_NR_CLKS
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_CLOCK_PISTACHIO_H */
end_comment

end_unit

