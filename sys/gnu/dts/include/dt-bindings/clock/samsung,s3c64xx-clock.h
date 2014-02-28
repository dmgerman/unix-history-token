begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013 Tomasz Figa<tomasz.figa at gmail.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Device Tree binding constants for Samsung S3C64xx clock controller. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLOCK_SAMSUNG_S3C64XX_CLOCK_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLOCK_SAMSUNG_S3C64XX_CLOCK_H
end_define

begin_comment
comment|/*  * Let each exported clock get a unique index, which is used on DT-enabled  * platforms to lookup the clock from a clock specifier. These indices are  * therefore considered an ABI and so must not be changed. This implies  * that new clocks should be added either in free spaces between clock groups  * or at the end.  */
end_comment

begin_comment
comment|/* Core clocks. */
end_comment

begin_define
define|#
directive|define
name|CLK27M
value|1
end_define

begin_define
define|#
directive|define
name|CLK48M
value|2
end_define

begin_define
define|#
directive|define
name|FOUT_APLL
value|3
end_define

begin_define
define|#
directive|define
name|FOUT_MPLL
value|4
end_define

begin_define
define|#
directive|define
name|FOUT_EPLL
value|5
end_define

begin_define
define|#
directive|define
name|ARMCLK
value|6
end_define

begin_define
define|#
directive|define
name|HCLKX2
value|7
end_define

begin_define
define|#
directive|define
name|HCLK
value|8
end_define

begin_define
define|#
directive|define
name|PCLK
value|9
end_define

begin_comment
comment|/* HCLK bus clocks. */
end_comment

begin_define
define|#
directive|define
name|HCLK_3DSE
value|16
end_define

begin_define
define|#
directive|define
name|HCLK_UHOST
value|17
end_define

begin_define
define|#
directive|define
name|HCLK_SECUR
value|18
end_define

begin_define
define|#
directive|define
name|HCLK_SDMA1
value|19
end_define

begin_define
define|#
directive|define
name|HCLK_SDMA0
value|20
end_define

begin_define
define|#
directive|define
name|HCLK_IROM
value|21
end_define

begin_define
define|#
directive|define
name|HCLK_DDR1
value|22
end_define

begin_define
define|#
directive|define
name|HCLK_MEM1
value|23
end_define

begin_define
define|#
directive|define
name|HCLK_MEM0
value|24
end_define

begin_define
define|#
directive|define
name|HCLK_USB
value|25
end_define

begin_define
define|#
directive|define
name|HCLK_HSMMC2
value|26
end_define

begin_define
define|#
directive|define
name|HCLK_HSMMC1
value|27
end_define

begin_define
define|#
directive|define
name|HCLK_HSMMC0
value|28
end_define

begin_define
define|#
directive|define
name|HCLK_MDP
value|29
end_define

begin_define
define|#
directive|define
name|HCLK_DHOST
value|30
end_define

begin_define
define|#
directive|define
name|HCLK_IHOST
value|31
end_define

begin_define
define|#
directive|define
name|HCLK_DMA1
value|32
end_define

begin_define
define|#
directive|define
name|HCLK_DMA0
value|33
end_define

begin_define
define|#
directive|define
name|HCLK_JPEG
value|34
end_define

begin_define
define|#
directive|define
name|HCLK_CAMIF
value|35
end_define

begin_define
define|#
directive|define
name|HCLK_SCALER
value|36
end_define

begin_define
define|#
directive|define
name|HCLK_2D
value|37
end_define

begin_define
define|#
directive|define
name|HCLK_TV
value|38
end_define

begin_define
define|#
directive|define
name|HCLK_POST0
value|39
end_define

begin_define
define|#
directive|define
name|HCLK_ROT
value|40
end_define

begin_define
define|#
directive|define
name|HCLK_LCD
value|41
end_define

begin_define
define|#
directive|define
name|HCLK_TZIC
value|42
end_define

begin_define
define|#
directive|define
name|HCLK_INTC
value|43
end_define

begin_define
define|#
directive|define
name|HCLK_MFC
value|44
end_define

begin_define
define|#
directive|define
name|HCLK_DDR0
value|45
end_define

begin_comment
comment|/* PCLK bus clocks. */
end_comment

begin_define
define|#
directive|define
name|PCLK_IIC1
value|48
end_define

begin_define
define|#
directive|define
name|PCLK_IIS2
value|49
end_define

begin_define
define|#
directive|define
name|PCLK_SKEY
value|50
end_define

begin_define
define|#
directive|define
name|PCLK_CHIPID
value|51
end_define

begin_define
define|#
directive|define
name|PCLK_SPI1
value|52
end_define

begin_define
define|#
directive|define
name|PCLK_SPI0
value|53
end_define

begin_define
define|#
directive|define
name|PCLK_HSIRX
value|54
end_define

begin_define
define|#
directive|define
name|PCLK_HSITX
value|55
end_define

begin_define
define|#
directive|define
name|PCLK_GPIO
value|56
end_define

begin_define
define|#
directive|define
name|PCLK_IIC0
value|57
end_define

begin_define
define|#
directive|define
name|PCLK_IIS1
value|58
end_define

begin_define
define|#
directive|define
name|PCLK_IIS0
value|59
end_define

begin_define
define|#
directive|define
name|PCLK_AC97
value|60
end_define

begin_define
define|#
directive|define
name|PCLK_TZPC
value|61
end_define

begin_define
define|#
directive|define
name|PCLK_TSADC
value|62
end_define

begin_define
define|#
directive|define
name|PCLK_KEYPAD
value|63
end_define

begin_define
define|#
directive|define
name|PCLK_IRDA
value|64
end_define

begin_define
define|#
directive|define
name|PCLK_PCM1
value|65
end_define

begin_define
define|#
directive|define
name|PCLK_PCM0
value|66
end_define

begin_define
define|#
directive|define
name|PCLK_PWM
value|67
end_define

begin_define
define|#
directive|define
name|PCLK_RTC
value|68
end_define

begin_define
define|#
directive|define
name|PCLK_WDT
value|69
end_define

begin_define
define|#
directive|define
name|PCLK_UART3
value|70
end_define

begin_define
define|#
directive|define
name|PCLK_UART2
value|71
end_define

begin_define
define|#
directive|define
name|PCLK_UART1
value|72
end_define

begin_define
define|#
directive|define
name|PCLK_UART0
value|73
end_define

begin_define
define|#
directive|define
name|PCLK_MFC
value|74
end_define

begin_comment
comment|/* Special clocks. */
end_comment

begin_define
define|#
directive|define
name|SCLK_UHOST
value|80
end_define

begin_define
define|#
directive|define
name|SCLK_MMC2_48
value|81
end_define

begin_define
define|#
directive|define
name|SCLK_MMC1_48
value|82
end_define

begin_define
define|#
directive|define
name|SCLK_MMC0_48
value|83
end_define

begin_define
define|#
directive|define
name|SCLK_MMC2
value|84
end_define

begin_define
define|#
directive|define
name|SCLK_MMC1
value|85
end_define

begin_define
define|#
directive|define
name|SCLK_MMC0
value|86
end_define

begin_define
define|#
directive|define
name|SCLK_SPI1_48
value|87
end_define

begin_define
define|#
directive|define
name|SCLK_SPI0_48
value|88
end_define

begin_define
define|#
directive|define
name|SCLK_SPI1
value|89
end_define

begin_define
define|#
directive|define
name|SCLK_SPI0
value|90
end_define

begin_define
define|#
directive|define
name|SCLK_DAC27
value|91
end_define

begin_define
define|#
directive|define
name|SCLK_TV27
value|92
end_define

begin_define
define|#
directive|define
name|SCLK_SCALER27
value|93
end_define

begin_define
define|#
directive|define
name|SCLK_SCALER
value|94
end_define

begin_define
define|#
directive|define
name|SCLK_LCD27
value|95
end_define

begin_define
define|#
directive|define
name|SCLK_LCD
value|96
end_define

begin_define
define|#
directive|define
name|SCLK_FIMC
value|97
end_define

begin_define
define|#
directive|define
name|SCLK_POST0_27
value|98
end_define

begin_define
define|#
directive|define
name|SCLK_AUDIO2
value|99
end_define

begin_define
define|#
directive|define
name|SCLK_POST0
value|100
end_define

begin_define
define|#
directive|define
name|SCLK_AUDIO1
value|101
end_define

begin_define
define|#
directive|define
name|SCLK_AUDIO0
value|102
end_define

begin_define
define|#
directive|define
name|SCLK_SECUR
value|103
end_define

begin_define
define|#
directive|define
name|SCLK_IRDA
value|104
end_define

begin_define
define|#
directive|define
name|SCLK_UART
value|105
end_define

begin_define
define|#
directive|define
name|SCLK_MFC
value|106
end_define

begin_define
define|#
directive|define
name|SCLK_CAM
value|107
end_define

begin_define
define|#
directive|define
name|SCLK_JPEG
value|108
end_define

begin_define
define|#
directive|define
name|SCLK_ONENAND
value|109
end_define

begin_comment
comment|/* MEM0 bus clocks - S3C6410-specific. */
end_comment

begin_define
define|#
directive|define
name|MEM0_CFCON
value|112
end_define

begin_define
define|#
directive|define
name|MEM0_ONENAND1
value|113
end_define

begin_define
define|#
directive|define
name|MEM0_ONENAND0
value|114
end_define

begin_define
define|#
directive|define
name|MEM0_NFCON
value|115
end_define

begin_define
define|#
directive|define
name|MEM0_SROM
value|116
end_define

begin_comment
comment|/* Muxes. */
end_comment

begin_define
define|#
directive|define
name|MOUT_APLL
value|128
end_define

begin_define
define|#
directive|define
name|MOUT_MPLL
value|129
end_define

begin_define
define|#
directive|define
name|MOUT_EPLL
value|130
end_define

begin_define
define|#
directive|define
name|MOUT_MFC
value|131
end_define

begin_define
define|#
directive|define
name|MOUT_AUDIO0
value|132
end_define

begin_define
define|#
directive|define
name|MOUT_AUDIO1
value|133
end_define

begin_define
define|#
directive|define
name|MOUT_UART
value|134
end_define

begin_define
define|#
directive|define
name|MOUT_SPI0
value|135
end_define

begin_define
define|#
directive|define
name|MOUT_SPI1
value|136
end_define

begin_define
define|#
directive|define
name|MOUT_MMC0
value|137
end_define

begin_define
define|#
directive|define
name|MOUT_MMC1
value|138
end_define

begin_define
define|#
directive|define
name|MOUT_MMC2
value|139
end_define

begin_define
define|#
directive|define
name|MOUT_UHOST
value|140
end_define

begin_define
define|#
directive|define
name|MOUT_IRDA
value|141
end_define

begin_define
define|#
directive|define
name|MOUT_LCD
value|142
end_define

begin_define
define|#
directive|define
name|MOUT_SCALER
value|143
end_define

begin_define
define|#
directive|define
name|MOUT_DAC27
value|144
end_define

begin_define
define|#
directive|define
name|MOUT_TV27
value|145
end_define

begin_define
define|#
directive|define
name|MOUT_AUDIO2
value|146
end_define

begin_comment
comment|/* Dividers. */
end_comment

begin_define
define|#
directive|define
name|DOUT_MPLL
value|160
end_define

begin_define
define|#
directive|define
name|DOUT_SECUR
value|161
end_define

begin_define
define|#
directive|define
name|DOUT_CAM
value|162
end_define

begin_define
define|#
directive|define
name|DOUT_JPEG
value|163
end_define

begin_define
define|#
directive|define
name|DOUT_MFC
value|164
end_define

begin_define
define|#
directive|define
name|DOUT_MMC0
value|165
end_define

begin_define
define|#
directive|define
name|DOUT_MMC1
value|166
end_define

begin_define
define|#
directive|define
name|DOUT_MMC2
value|167
end_define

begin_define
define|#
directive|define
name|DOUT_LCD
value|168
end_define

begin_define
define|#
directive|define
name|DOUT_SCALER
value|169
end_define

begin_define
define|#
directive|define
name|DOUT_UHOST
value|170
end_define

begin_define
define|#
directive|define
name|DOUT_SPI0
value|171
end_define

begin_define
define|#
directive|define
name|DOUT_SPI1
value|172
end_define

begin_define
define|#
directive|define
name|DOUT_AUDIO0
value|173
end_define

begin_define
define|#
directive|define
name|DOUT_AUDIO1
value|174
end_define

begin_define
define|#
directive|define
name|DOUT_UART
value|175
end_define

begin_define
define|#
directive|define
name|DOUT_IRDA
value|176
end_define

begin_define
define|#
directive|define
name|DOUT_FIMC
value|177
end_define

begin_define
define|#
directive|define
name|DOUT_AUDIO2
value|178
end_define

begin_comment
comment|/* Total number of clocks. */
end_comment

begin_define
define|#
directive|define
name|NR_CLKS
value|(DOUT_AUDIO2 + 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_CLOCK_SAMSUNG_S3C64XX_CLOCK_H */
end_comment

end_unit

