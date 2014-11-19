begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013 Samsung Electronics Co., Ltd.  * Author: Mateusz Krawczuk<m.krawczuk@partner.samsung.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Device Tree binding constants for Samsung S5PV210 clock controller.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLOCK_S5PV210_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLOCK_S5PV210_H
end_define

begin_comment
comment|/* Core clocks. */
end_comment

begin_define
define|#
directive|define
name|FIN_PLL
value|1
end_define

begin_define
define|#
directive|define
name|FOUT_APLL
value|2
end_define

begin_define
define|#
directive|define
name|FOUT_MPLL
value|3
end_define

begin_define
define|#
directive|define
name|FOUT_EPLL
value|4
end_define

begin_define
define|#
directive|define
name|FOUT_VPLL
value|5
end_define

begin_comment
comment|/* Muxes. */
end_comment

begin_define
define|#
directive|define
name|MOUT_FLASH
value|6
end_define

begin_define
define|#
directive|define
name|MOUT_PSYS
value|7
end_define

begin_define
define|#
directive|define
name|MOUT_DSYS
value|8
end_define

begin_define
define|#
directive|define
name|MOUT_MSYS
value|9
end_define

begin_define
define|#
directive|define
name|MOUT_VPLL
value|10
end_define

begin_define
define|#
directive|define
name|MOUT_EPLL
value|11
end_define

begin_define
define|#
directive|define
name|MOUT_MPLL
value|12
end_define

begin_define
define|#
directive|define
name|MOUT_APLL
value|13
end_define

begin_define
define|#
directive|define
name|MOUT_VPLLSRC
value|14
end_define

begin_define
define|#
directive|define
name|MOUT_CSIS
value|15
end_define

begin_define
define|#
directive|define
name|MOUT_FIMD
value|16
end_define

begin_define
define|#
directive|define
name|MOUT_CAM1
value|17
end_define

begin_define
define|#
directive|define
name|MOUT_CAM0
value|18
end_define

begin_define
define|#
directive|define
name|MOUT_DAC
value|19
end_define

begin_define
define|#
directive|define
name|MOUT_MIXER
value|20
end_define

begin_define
define|#
directive|define
name|MOUT_HDMI
value|21
end_define

begin_define
define|#
directive|define
name|MOUT_G2D
value|22
end_define

begin_define
define|#
directive|define
name|MOUT_MFC
value|23
end_define

begin_define
define|#
directive|define
name|MOUT_G3D
value|24
end_define

begin_define
define|#
directive|define
name|MOUT_FIMC2
value|25
end_define

begin_define
define|#
directive|define
name|MOUT_FIMC1
value|26
end_define

begin_define
define|#
directive|define
name|MOUT_FIMC0
value|27
end_define

begin_define
define|#
directive|define
name|MOUT_UART3
value|28
end_define

begin_define
define|#
directive|define
name|MOUT_UART2
value|29
end_define

begin_define
define|#
directive|define
name|MOUT_UART1
value|30
end_define

begin_define
define|#
directive|define
name|MOUT_UART0
value|31
end_define

begin_define
define|#
directive|define
name|MOUT_MMC3
value|32
end_define

begin_define
define|#
directive|define
name|MOUT_MMC2
value|33
end_define

begin_define
define|#
directive|define
name|MOUT_MMC1
value|34
end_define

begin_define
define|#
directive|define
name|MOUT_MMC0
value|35
end_define

begin_define
define|#
directive|define
name|MOUT_PWM
value|36
end_define

begin_define
define|#
directive|define
name|MOUT_SPI0
value|37
end_define

begin_define
define|#
directive|define
name|MOUT_SPI1
value|38
end_define

begin_define
define|#
directive|define
name|MOUT_DMC0
value|39
end_define

begin_define
define|#
directive|define
name|MOUT_PWI
value|40
end_define

begin_define
define|#
directive|define
name|MOUT_HPM
value|41
end_define

begin_define
define|#
directive|define
name|MOUT_SPDIF
value|42
end_define

begin_define
define|#
directive|define
name|MOUT_AUDIO2
value|43
end_define

begin_define
define|#
directive|define
name|MOUT_AUDIO1
value|44
end_define

begin_define
define|#
directive|define
name|MOUT_AUDIO0
value|45
end_define

begin_comment
comment|/* Dividers. */
end_comment

begin_define
define|#
directive|define
name|DOUT_PCLKP
value|46
end_define

begin_define
define|#
directive|define
name|DOUT_HCLKP
value|47
end_define

begin_define
define|#
directive|define
name|DOUT_PCLKD
value|48
end_define

begin_define
define|#
directive|define
name|DOUT_HCLKD
value|49
end_define

begin_define
define|#
directive|define
name|DOUT_PCLKM
value|50
end_define

begin_define
define|#
directive|define
name|DOUT_HCLKM
value|51
end_define

begin_define
define|#
directive|define
name|DOUT_A2M
value|52
end_define

begin_define
define|#
directive|define
name|DOUT_APLL
value|53
end_define

begin_define
define|#
directive|define
name|DOUT_CSIS
value|54
end_define

begin_define
define|#
directive|define
name|DOUT_FIMD
value|55
end_define

begin_define
define|#
directive|define
name|DOUT_CAM1
value|56
end_define

begin_define
define|#
directive|define
name|DOUT_CAM0
value|57
end_define

begin_define
define|#
directive|define
name|DOUT_TBLK
value|58
end_define

begin_define
define|#
directive|define
name|DOUT_G2D
value|59
end_define

begin_define
define|#
directive|define
name|DOUT_MFC
value|60
end_define

begin_define
define|#
directive|define
name|DOUT_G3D
value|61
end_define

begin_define
define|#
directive|define
name|DOUT_FIMC2
value|62
end_define

begin_define
define|#
directive|define
name|DOUT_FIMC1
value|63
end_define

begin_define
define|#
directive|define
name|DOUT_FIMC0
value|64
end_define

begin_define
define|#
directive|define
name|DOUT_UART3
value|65
end_define

begin_define
define|#
directive|define
name|DOUT_UART2
value|66
end_define

begin_define
define|#
directive|define
name|DOUT_UART1
value|67
end_define

begin_define
define|#
directive|define
name|DOUT_UART0
value|68
end_define

begin_define
define|#
directive|define
name|DOUT_MMC3
value|69
end_define

begin_define
define|#
directive|define
name|DOUT_MMC2
value|70
end_define

begin_define
define|#
directive|define
name|DOUT_MMC1
value|71
end_define

begin_define
define|#
directive|define
name|DOUT_MMC0
value|72
end_define

begin_define
define|#
directive|define
name|DOUT_PWM
value|73
end_define

begin_define
define|#
directive|define
name|DOUT_SPI1
value|74
end_define

begin_define
define|#
directive|define
name|DOUT_SPI0
value|75
end_define

begin_define
define|#
directive|define
name|DOUT_DMC0
value|76
end_define

begin_define
define|#
directive|define
name|DOUT_PWI
value|77
end_define

begin_define
define|#
directive|define
name|DOUT_HPM
value|78
end_define

begin_define
define|#
directive|define
name|DOUT_COPY
value|79
end_define

begin_define
define|#
directive|define
name|DOUT_FLASH
value|80
end_define

begin_define
define|#
directive|define
name|DOUT_AUDIO2
value|81
end_define

begin_define
define|#
directive|define
name|DOUT_AUDIO1
value|82
end_define

begin_define
define|#
directive|define
name|DOUT_AUDIO0
value|83
end_define

begin_define
define|#
directive|define
name|DOUT_DPM
value|84
end_define

begin_define
define|#
directive|define
name|DOUT_DVSEM
value|85
end_define

begin_comment
comment|/* Gates */
end_comment

begin_define
define|#
directive|define
name|SCLK_FIMC
value|86
end_define

begin_define
define|#
directive|define
name|CLK_CSIS
value|87
end_define

begin_define
define|#
directive|define
name|CLK_ROTATOR
value|88
end_define

begin_define
define|#
directive|define
name|CLK_FIMC2
value|89
end_define

begin_define
define|#
directive|define
name|CLK_FIMC1
value|90
end_define

begin_define
define|#
directive|define
name|CLK_FIMC0
value|91
end_define

begin_define
define|#
directive|define
name|CLK_MFC
value|92
end_define

begin_define
define|#
directive|define
name|CLK_G2D
value|93
end_define

begin_define
define|#
directive|define
name|CLK_G3D
value|94
end_define

begin_define
define|#
directive|define
name|CLK_IMEM
value|95
end_define

begin_define
define|#
directive|define
name|CLK_PDMA1
value|96
end_define

begin_define
define|#
directive|define
name|CLK_PDMA0
value|97
end_define

begin_define
define|#
directive|define
name|CLK_MDMA
value|98
end_define

begin_define
define|#
directive|define
name|CLK_DMC1
value|99
end_define

begin_define
define|#
directive|define
name|CLK_DMC0
value|100
end_define

begin_define
define|#
directive|define
name|CLK_NFCON
value|101
end_define

begin_define
define|#
directive|define
name|CLK_SROMC
value|102
end_define

begin_define
define|#
directive|define
name|CLK_CFCON
value|103
end_define

begin_define
define|#
directive|define
name|CLK_NANDXL
value|104
end_define

begin_define
define|#
directive|define
name|CLK_USB_HOST
value|105
end_define

begin_define
define|#
directive|define
name|CLK_USB_OTG
value|106
end_define

begin_define
define|#
directive|define
name|CLK_HDMI
value|107
end_define

begin_define
define|#
directive|define
name|CLK_TVENC
value|108
end_define

begin_define
define|#
directive|define
name|CLK_MIXER
value|109
end_define

begin_define
define|#
directive|define
name|CLK_VP
value|110
end_define

begin_define
define|#
directive|define
name|CLK_DSIM
value|111
end_define

begin_define
define|#
directive|define
name|CLK_FIMD
value|112
end_define

begin_define
define|#
directive|define
name|CLK_TZIC3
value|113
end_define

begin_define
define|#
directive|define
name|CLK_TZIC2
value|114
end_define

begin_define
define|#
directive|define
name|CLK_TZIC1
value|115
end_define

begin_define
define|#
directive|define
name|CLK_TZIC0
value|116
end_define

begin_define
define|#
directive|define
name|CLK_VIC3
value|117
end_define

begin_define
define|#
directive|define
name|CLK_VIC2
value|118
end_define

begin_define
define|#
directive|define
name|CLK_VIC1
value|119
end_define

begin_define
define|#
directive|define
name|CLK_VIC0
value|120
end_define

begin_define
define|#
directive|define
name|CLK_TSI
value|121
end_define

begin_define
define|#
directive|define
name|CLK_HSMMC3
value|122
end_define

begin_define
define|#
directive|define
name|CLK_HSMMC2
value|123
end_define

begin_define
define|#
directive|define
name|CLK_HSMMC1
value|124
end_define

begin_define
define|#
directive|define
name|CLK_HSMMC0
value|125
end_define

begin_define
define|#
directive|define
name|CLK_JTAG
value|126
end_define

begin_define
define|#
directive|define
name|CLK_MODEMIF
value|127
end_define

begin_define
define|#
directive|define
name|CLK_CORESIGHT
value|128
end_define

begin_define
define|#
directive|define
name|CLK_SDM
value|129
end_define

begin_define
define|#
directive|define
name|CLK_SECSS
value|130
end_define

begin_define
define|#
directive|define
name|CLK_PCM2
value|131
end_define

begin_define
define|#
directive|define
name|CLK_PCM1
value|132
end_define

begin_define
define|#
directive|define
name|CLK_PCM0
value|133
end_define

begin_define
define|#
directive|define
name|CLK_SYSCON
value|134
end_define

begin_define
define|#
directive|define
name|CLK_GPIO
value|135
end_define

begin_define
define|#
directive|define
name|CLK_TSADC
value|136
end_define

begin_define
define|#
directive|define
name|CLK_PWM
value|137
end_define

begin_define
define|#
directive|define
name|CLK_WDT
value|138
end_define

begin_define
define|#
directive|define
name|CLK_KEYIF
value|139
end_define

begin_define
define|#
directive|define
name|CLK_UART3
value|140
end_define

begin_define
define|#
directive|define
name|CLK_UART2
value|141
end_define

begin_define
define|#
directive|define
name|CLK_UART1
value|142
end_define

begin_define
define|#
directive|define
name|CLK_UART0
value|143
end_define

begin_define
define|#
directive|define
name|CLK_SYSTIMER
value|144
end_define

begin_define
define|#
directive|define
name|CLK_RTC
value|145
end_define

begin_define
define|#
directive|define
name|CLK_SPI1
value|146
end_define

begin_define
define|#
directive|define
name|CLK_SPI0
value|147
end_define

begin_define
define|#
directive|define
name|CLK_I2C_HDMI_PHY
value|148
end_define

begin_define
define|#
directive|define
name|CLK_I2C1
value|149
end_define

begin_define
define|#
directive|define
name|CLK_I2C2
value|150
end_define

begin_define
define|#
directive|define
name|CLK_I2C0
value|151
end_define

begin_define
define|#
directive|define
name|CLK_I2S1
value|152
end_define

begin_define
define|#
directive|define
name|CLK_I2S2
value|153
end_define

begin_define
define|#
directive|define
name|CLK_I2S0
value|154
end_define

begin_define
define|#
directive|define
name|CLK_AC97
value|155
end_define

begin_define
define|#
directive|define
name|CLK_SPDIF
value|156
end_define

begin_define
define|#
directive|define
name|CLK_TZPC3
value|157
end_define

begin_define
define|#
directive|define
name|CLK_TZPC2
value|158
end_define

begin_define
define|#
directive|define
name|CLK_TZPC1
value|159
end_define

begin_define
define|#
directive|define
name|CLK_TZPC0
value|160
end_define

begin_define
define|#
directive|define
name|CLK_SECKEY
value|161
end_define

begin_define
define|#
directive|define
name|CLK_IEM_APC
value|162
end_define

begin_define
define|#
directive|define
name|CLK_IEM_IEC
value|163
end_define

begin_define
define|#
directive|define
name|CLK_CHIPID
value|164
end_define

begin_define
define|#
directive|define
name|CLK_JPEG
value|163
end_define

begin_comment
comment|/* Special clocks*/
end_comment

begin_define
define|#
directive|define
name|SCLK_PWI
value|164
end_define

begin_define
define|#
directive|define
name|SCLK_SPDIF
value|165
end_define

begin_define
define|#
directive|define
name|SCLK_AUDIO2
value|166
end_define

begin_define
define|#
directive|define
name|SCLK_AUDIO1
value|167
end_define

begin_define
define|#
directive|define
name|SCLK_AUDIO0
value|168
end_define

begin_define
define|#
directive|define
name|SCLK_PWM
value|169
end_define

begin_define
define|#
directive|define
name|SCLK_SPI1
value|170
end_define

begin_define
define|#
directive|define
name|SCLK_SPI0
value|171
end_define

begin_define
define|#
directive|define
name|SCLK_UART3
value|172
end_define

begin_define
define|#
directive|define
name|SCLK_UART2
value|173
end_define

begin_define
define|#
directive|define
name|SCLK_UART1
value|174
end_define

begin_define
define|#
directive|define
name|SCLK_UART0
value|175
end_define

begin_define
define|#
directive|define
name|SCLK_MMC3
value|176
end_define

begin_define
define|#
directive|define
name|SCLK_MMC2
value|177
end_define

begin_define
define|#
directive|define
name|SCLK_MMC1
value|178
end_define

begin_define
define|#
directive|define
name|SCLK_MMC0
value|179
end_define

begin_define
define|#
directive|define
name|SCLK_FINVPLL
value|180
end_define

begin_define
define|#
directive|define
name|SCLK_CSIS
value|181
end_define

begin_define
define|#
directive|define
name|SCLK_FIMD
value|182
end_define

begin_define
define|#
directive|define
name|SCLK_CAM1
value|183
end_define

begin_define
define|#
directive|define
name|SCLK_CAM0
value|184
end_define

begin_define
define|#
directive|define
name|SCLK_DAC
value|185
end_define

begin_define
define|#
directive|define
name|SCLK_MIXER
value|186
end_define

begin_define
define|#
directive|define
name|SCLK_HDMI
value|187
end_define

begin_define
define|#
directive|define
name|SCLK_FIMC2
value|188
end_define

begin_define
define|#
directive|define
name|SCLK_FIMC1
value|189
end_define

begin_define
define|#
directive|define
name|SCLK_FIMC0
value|190
end_define

begin_define
define|#
directive|define
name|SCLK_HDMI27M
value|191
end_define

begin_define
define|#
directive|define
name|SCLK_HDMIPHY
value|192
end_define

begin_define
define|#
directive|define
name|SCLK_USBPHY0
value|193
end_define

begin_define
define|#
directive|define
name|SCLK_USBPHY1
value|194
end_define

begin_comment
comment|/* S5P6442-specific clocks */
end_comment

begin_define
define|#
directive|define
name|MOUT_D0SYNC
value|195
end_define

begin_define
define|#
directive|define
name|MOUT_D1SYNC
value|196
end_define

begin_define
define|#
directive|define
name|DOUT_MIXER
value|197
end_define

begin_define
define|#
directive|define
name|CLK_ETB
value|198
end_define

begin_define
define|#
directive|define
name|CLK_ETM
value|199
end_define

begin_comment
comment|/* CLKOUT */
end_comment

begin_define
define|#
directive|define
name|FOUT_APLL_CLKOUT
value|200
end_define

begin_define
define|#
directive|define
name|FOUT_MPLL_CLKOUT
value|201
end_define

begin_define
define|#
directive|define
name|DOUT_APLL_CLKOUT
value|202
end_define

begin_define
define|#
directive|define
name|MOUT_CLKSEL
value|203
end_define

begin_define
define|#
directive|define
name|DOUT_CLKOUT
value|204
end_define

begin_define
define|#
directive|define
name|MOUT_CLKOUT
value|205
end_define

begin_comment
comment|/* Total number of clocks. */
end_comment

begin_define
define|#
directive|define
name|NR_CLKS
value|206
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_CLOCK_S5PV210_H */
end_comment

end_unit

