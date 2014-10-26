begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2013 Freescale Semiconductor, Inc.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_CLOCK_VF610_H
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_CLOCK_VF610_H
end_define

begin_define
define|#
directive|define
name|VF610_CLK_DUMMY
value|0
end_define

begin_define
define|#
directive|define
name|VF610_CLK_SIRC_128K
value|1
end_define

begin_define
define|#
directive|define
name|VF610_CLK_SIRC_32K
value|2
end_define

begin_define
define|#
directive|define
name|VF610_CLK_FIRC
value|3
end_define

begin_define
define|#
directive|define
name|VF610_CLK_SXOSC
value|4
end_define

begin_define
define|#
directive|define
name|VF610_CLK_FXOSC
value|5
end_define

begin_define
define|#
directive|define
name|VF610_CLK_FXOSC_HALF
value|6
end_define

begin_define
define|#
directive|define
name|VF610_CLK_SLOW_CLK_SEL
value|7
end_define

begin_define
define|#
directive|define
name|VF610_CLK_FASK_CLK_SEL
value|8
end_define

begin_define
define|#
directive|define
name|VF610_CLK_AUDIO_EXT
value|9
end_define

begin_define
define|#
directive|define
name|VF610_CLK_ENET_EXT
value|10
end_define

begin_define
define|#
directive|define
name|VF610_CLK_PLL1_MAIN
value|11
end_define

begin_define
define|#
directive|define
name|VF610_CLK_PLL1_PFD1
value|12
end_define

begin_define
define|#
directive|define
name|VF610_CLK_PLL1_PFD2
value|13
end_define

begin_define
define|#
directive|define
name|VF610_CLK_PLL1_PFD3
value|14
end_define

begin_define
define|#
directive|define
name|VF610_CLK_PLL1_PFD4
value|15
end_define

begin_define
define|#
directive|define
name|VF610_CLK_PLL2_MAIN
value|16
end_define

begin_define
define|#
directive|define
name|VF610_CLK_PLL2_PFD1
value|17
end_define

begin_define
define|#
directive|define
name|VF610_CLK_PLL2_PFD2
value|18
end_define

begin_define
define|#
directive|define
name|VF610_CLK_PLL2_PFD3
value|19
end_define

begin_define
define|#
directive|define
name|VF610_CLK_PLL2_PFD4
value|20
end_define

begin_define
define|#
directive|define
name|VF610_CLK_PLL3_MAIN
value|21
end_define

begin_define
define|#
directive|define
name|VF610_CLK_PLL3_PFD1
value|22
end_define

begin_define
define|#
directive|define
name|VF610_CLK_PLL3_PFD2
value|23
end_define

begin_define
define|#
directive|define
name|VF610_CLK_PLL3_PFD3
value|24
end_define

begin_define
define|#
directive|define
name|VF610_CLK_PLL3_PFD4
value|25
end_define

begin_define
define|#
directive|define
name|VF610_CLK_PLL4_MAIN
value|26
end_define

begin_define
define|#
directive|define
name|VF610_CLK_PLL5_MAIN
value|27
end_define

begin_define
define|#
directive|define
name|VF610_CLK_PLL6_MAIN
value|28
end_define

begin_define
define|#
directive|define
name|VF610_CLK_PLL3_MAIN_DIV
value|29
end_define

begin_define
define|#
directive|define
name|VF610_CLK_PLL4_MAIN_DIV
value|30
end_define

begin_define
define|#
directive|define
name|VF610_CLK_PLL6_MAIN_DIV
value|31
end_define

begin_define
define|#
directive|define
name|VF610_CLK_PLL1_PFD_SEL
value|32
end_define

begin_define
define|#
directive|define
name|VF610_CLK_PLL2_PFD_SEL
value|33
end_define

begin_define
define|#
directive|define
name|VF610_CLK_SYS_SEL
value|34
end_define

begin_define
define|#
directive|define
name|VF610_CLK_DDR_SEL
value|35
end_define

begin_define
define|#
directive|define
name|VF610_CLK_SYS_BUS
value|36
end_define

begin_define
define|#
directive|define
name|VF610_CLK_PLATFORM_BUS
value|37
end_define

begin_define
define|#
directive|define
name|VF610_CLK_IPG_BUS
value|38
end_define

begin_define
define|#
directive|define
name|VF610_CLK_UART0
value|39
end_define

begin_define
define|#
directive|define
name|VF610_CLK_UART1
value|40
end_define

begin_define
define|#
directive|define
name|VF610_CLK_UART2
value|41
end_define

begin_define
define|#
directive|define
name|VF610_CLK_UART3
value|42
end_define

begin_define
define|#
directive|define
name|VF610_CLK_UART4
value|43
end_define

begin_define
define|#
directive|define
name|VF610_CLK_UART5
value|44
end_define

begin_define
define|#
directive|define
name|VF610_CLK_PIT
value|45
end_define

begin_define
define|#
directive|define
name|VF610_CLK_I2C0
value|46
end_define

begin_define
define|#
directive|define
name|VF610_CLK_I2C1
value|47
end_define

begin_define
define|#
directive|define
name|VF610_CLK_I2C2
value|48
end_define

begin_define
define|#
directive|define
name|VF610_CLK_I2C3
value|49
end_define

begin_define
define|#
directive|define
name|VF610_CLK_FTM0_EXT_SEL
value|50
end_define

begin_define
define|#
directive|define
name|VF610_CLK_FTM0_FIX_SEL
value|51
end_define

begin_define
define|#
directive|define
name|VF610_CLK_FTM0_EXT_FIX_EN
value|52
end_define

begin_define
define|#
directive|define
name|VF610_CLK_FTM1_EXT_SEL
value|53
end_define

begin_define
define|#
directive|define
name|VF610_CLK_FTM1_FIX_SEL
value|54
end_define

begin_define
define|#
directive|define
name|VF610_CLK_FTM1_EXT_FIX_EN
value|55
end_define

begin_define
define|#
directive|define
name|VF610_CLK_FTM2_EXT_SEL
value|56
end_define

begin_define
define|#
directive|define
name|VF610_CLK_FTM2_FIX_SEL
value|57
end_define

begin_define
define|#
directive|define
name|VF610_CLK_FTM2_EXT_FIX_EN
value|58
end_define

begin_define
define|#
directive|define
name|VF610_CLK_FTM3_EXT_SEL
value|59
end_define

begin_define
define|#
directive|define
name|VF610_CLK_FTM3_FIX_SEL
value|60
end_define

begin_define
define|#
directive|define
name|VF610_CLK_FTM3_EXT_FIX_EN
value|61
end_define

begin_define
define|#
directive|define
name|VF610_CLK_FTM0
value|62
end_define

begin_define
define|#
directive|define
name|VF610_CLK_FTM1
value|63
end_define

begin_define
define|#
directive|define
name|VF610_CLK_FTM2
value|64
end_define

begin_define
define|#
directive|define
name|VF610_CLK_FTM3
value|65
end_define

begin_define
define|#
directive|define
name|VF610_CLK_ENET_50M
value|66
end_define

begin_define
define|#
directive|define
name|VF610_CLK_ENET_25M
value|67
end_define

begin_define
define|#
directive|define
name|VF610_CLK_ENET_SEL
value|68
end_define

begin_define
define|#
directive|define
name|VF610_CLK_ENET
value|69
end_define

begin_define
define|#
directive|define
name|VF610_CLK_ENET_TS_SEL
value|70
end_define

begin_define
define|#
directive|define
name|VF610_CLK_ENET_TS
value|71
end_define

begin_define
define|#
directive|define
name|VF610_CLK_DSPI0
value|72
end_define

begin_define
define|#
directive|define
name|VF610_CLK_DSPI1
value|73
end_define

begin_define
define|#
directive|define
name|VF610_CLK_DSPI2
value|74
end_define

begin_define
define|#
directive|define
name|VF610_CLK_DSPI3
value|75
end_define

begin_define
define|#
directive|define
name|VF610_CLK_WDT
value|76
end_define

begin_define
define|#
directive|define
name|VF610_CLK_ESDHC0_SEL
value|77
end_define

begin_define
define|#
directive|define
name|VF610_CLK_ESDHC0_EN
value|78
end_define

begin_define
define|#
directive|define
name|VF610_CLK_ESDHC0_DIV
value|79
end_define

begin_define
define|#
directive|define
name|VF610_CLK_ESDHC0
value|80
end_define

begin_define
define|#
directive|define
name|VF610_CLK_ESDHC1_SEL
value|81
end_define

begin_define
define|#
directive|define
name|VF610_CLK_ESDHC1_EN
value|82
end_define

begin_define
define|#
directive|define
name|VF610_CLK_ESDHC1_DIV
value|83
end_define

begin_define
define|#
directive|define
name|VF610_CLK_ESDHC1
value|84
end_define

begin_define
define|#
directive|define
name|VF610_CLK_DCU0_SEL
value|85
end_define

begin_define
define|#
directive|define
name|VF610_CLK_DCU0_EN
value|86
end_define

begin_define
define|#
directive|define
name|VF610_CLK_DCU0_DIV
value|87
end_define

begin_define
define|#
directive|define
name|VF610_CLK_DCU0
value|88
end_define

begin_define
define|#
directive|define
name|VF610_CLK_DCU1_SEL
value|89
end_define

begin_define
define|#
directive|define
name|VF610_CLK_DCU1_EN
value|90
end_define

begin_define
define|#
directive|define
name|VF610_CLK_DCU1_DIV
value|91
end_define

begin_define
define|#
directive|define
name|VF610_CLK_DCU1
value|92
end_define

begin_define
define|#
directive|define
name|VF610_CLK_ESAI_SEL
value|93
end_define

begin_define
define|#
directive|define
name|VF610_CLK_ESAI_EN
value|94
end_define

begin_define
define|#
directive|define
name|VF610_CLK_ESAI_DIV
value|95
end_define

begin_define
define|#
directive|define
name|VF610_CLK_ESAI
value|96
end_define

begin_define
define|#
directive|define
name|VF610_CLK_SAI0_SEL
value|97
end_define

begin_define
define|#
directive|define
name|VF610_CLK_SAI0_EN
value|98
end_define

begin_define
define|#
directive|define
name|VF610_CLK_SAI0_DIV
value|99
end_define

begin_define
define|#
directive|define
name|VF610_CLK_SAI0
value|100
end_define

begin_define
define|#
directive|define
name|VF610_CLK_SAI1_SEL
value|101
end_define

begin_define
define|#
directive|define
name|VF610_CLK_SAI1_EN
value|102
end_define

begin_define
define|#
directive|define
name|VF610_CLK_SAI1_DIV
value|103
end_define

begin_define
define|#
directive|define
name|VF610_CLK_SAI1
value|104
end_define

begin_define
define|#
directive|define
name|VF610_CLK_SAI2_SEL
value|105
end_define

begin_define
define|#
directive|define
name|VF610_CLK_SAI2_EN
value|106
end_define

begin_define
define|#
directive|define
name|VF610_CLK_SAI2_DIV
value|107
end_define

begin_define
define|#
directive|define
name|VF610_CLK_SAI2
value|108
end_define

begin_define
define|#
directive|define
name|VF610_CLK_SAI3_SEL
value|109
end_define

begin_define
define|#
directive|define
name|VF610_CLK_SAI3_EN
value|110
end_define

begin_define
define|#
directive|define
name|VF610_CLK_SAI3_DIV
value|111
end_define

begin_define
define|#
directive|define
name|VF610_CLK_SAI3
value|112
end_define

begin_define
define|#
directive|define
name|VF610_CLK_USBC0
value|113
end_define

begin_define
define|#
directive|define
name|VF610_CLK_USBC1
value|114
end_define

begin_define
define|#
directive|define
name|VF610_CLK_QSPI0_SEL
value|115
end_define

begin_define
define|#
directive|define
name|VF610_CLK_QSPI0_EN
value|116
end_define

begin_define
define|#
directive|define
name|VF610_CLK_QSPI0_X4_DIV
value|117
end_define

begin_define
define|#
directive|define
name|VF610_CLK_QSPI0_X2_DIV
value|118
end_define

begin_define
define|#
directive|define
name|VF610_CLK_QSPI0_X1_DIV
value|119
end_define

begin_define
define|#
directive|define
name|VF610_CLK_QSPI1_SEL
value|120
end_define

begin_define
define|#
directive|define
name|VF610_CLK_QSPI1_EN
value|121
end_define

begin_define
define|#
directive|define
name|VF610_CLK_QSPI1_X4_DIV
value|122
end_define

begin_define
define|#
directive|define
name|VF610_CLK_QSPI1_X2_DIV
value|123
end_define

begin_define
define|#
directive|define
name|VF610_CLK_QSPI1_X1_DIV
value|124
end_define

begin_define
define|#
directive|define
name|VF610_CLK_QSPI0
value|125
end_define

begin_define
define|#
directive|define
name|VF610_CLK_QSPI1
value|126
end_define

begin_define
define|#
directive|define
name|VF610_CLK_NFC_SEL
value|127
end_define

begin_define
define|#
directive|define
name|VF610_CLK_NFC_EN
value|128
end_define

begin_define
define|#
directive|define
name|VF610_CLK_NFC_PRE_DIV
value|129
end_define

begin_define
define|#
directive|define
name|VF610_CLK_NFC_FRAC_DIV
value|130
end_define

begin_define
define|#
directive|define
name|VF610_CLK_NFC_INV
value|131
end_define

begin_define
define|#
directive|define
name|VF610_CLK_NFC
value|132
end_define

begin_define
define|#
directive|define
name|VF610_CLK_VADC_SEL
value|133
end_define

begin_define
define|#
directive|define
name|VF610_CLK_VADC_EN
value|134
end_define

begin_define
define|#
directive|define
name|VF610_CLK_VADC_DIV
value|135
end_define

begin_define
define|#
directive|define
name|VF610_CLK_VADC_DIV_HALF
value|136
end_define

begin_define
define|#
directive|define
name|VF610_CLK_VADC
value|137
end_define

begin_define
define|#
directive|define
name|VF610_CLK_ADC0
value|138
end_define

begin_define
define|#
directive|define
name|VF610_CLK_ADC1
value|139
end_define

begin_define
define|#
directive|define
name|VF610_CLK_DAC0
value|140
end_define

begin_define
define|#
directive|define
name|VF610_CLK_DAC1
value|141
end_define

begin_define
define|#
directive|define
name|VF610_CLK_FLEXCAN0
value|142
end_define

begin_define
define|#
directive|define
name|VF610_CLK_FLEXCAN1
value|143
end_define

begin_define
define|#
directive|define
name|VF610_CLK_ASRC
value|144
end_define

begin_define
define|#
directive|define
name|VF610_CLK_GPU_SEL
value|145
end_define

begin_define
define|#
directive|define
name|VF610_CLK_GPU_EN
value|146
end_define

begin_define
define|#
directive|define
name|VF610_CLK_GPU2D
value|147
end_define

begin_define
define|#
directive|define
name|VF610_CLK_ENET0
value|148
end_define

begin_define
define|#
directive|define
name|VF610_CLK_ENET1
value|149
end_define

begin_define
define|#
directive|define
name|VF610_CLK_DMAMUX0
value|150
end_define

begin_define
define|#
directive|define
name|VF610_CLK_DMAMUX1
value|151
end_define

begin_define
define|#
directive|define
name|VF610_CLK_DMAMUX2
value|152
end_define

begin_define
define|#
directive|define
name|VF610_CLK_DMAMUX3
value|153
end_define

begin_define
define|#
directive|define
name|VF610_CLK_FLEXCAN0_EN
value|154
end_define

begin_define
define|#
directive|define
name|VF610_CLK_FLEXCAN1_EN
value|155
end_define

begin_define
define|#
directive|define
name|VF610_CLK_END
value|156
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DT_BINDINGS_CLOCK_VF610_H */
end_comment

end_unit

