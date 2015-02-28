begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2014 Samsung Electronics Co., Ltd.  * Author: Chanwoo Choi<cw00.choi@samsung.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Device Tree binding constants for Samsung Exynos4415 clock controllers.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLOCK_SAMSUNG_EXYNOS4415_CLOCK_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLOCK_SAMSUNG_EXYNOS4415_CLOCK_H
end_define

begin_comment
comment|/*  * Let each exported clock get a unique index, which is used on DT-enabled  * platforms to lookup the clock from a clock specifier. These indices are  * therefore considered an ABI and so must not be changed. This implies  * that new clocks should be added either in free spaces between clock groups  * or at the end.  */
end_comment

begin_comment
comment|/*  * Main CMU  */
end_comment

begin_define
define|#
directive|define
name|CLK_OSCSEL
value|1
end_define

begin_define
define|#
directive|define
name|CLK_FIN_PLL
value|2
end_define

begin_define
define|#
directive|define
name|CLK_FOUT_APLL
value|3
end_define

begin_define
define|#
directive|define
name|CLK_FOUT_MPLL
value|4
end_define

begin_define
define|#
directive|define
name|CLK_FOUT_EPLL
value|5
end_define

begin_define
define|#
directive|define
name|CLK_FOUT_G3D_PLL
value|6
end_define

begin_define
define|#
directive|define
name|CLK_FOUT_ISP_PLL
value|7
end_define

begin_define
define|#
directive|define
name|CLK_FOUT_DISP_PLL
value|8
end_define

begin_comment
comment|/* Muxes */
end_comment

begin_define
define|#
directive|define
name|CLK_MOUT_MPLL_USER_L
value|16
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_GDL
value|17
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_MPLL_USER_R
value|18
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_GDR
value|19
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_EBI
value|20
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_200
value|21
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_160
value|22
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_100
value|23
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_266
value|24
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_G3D_PLL
value|25
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_EPLL
value|26
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_EBI_1
value|27
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ISP_PLL
value|28
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_DISP_PLL
value|29
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_MPLL_USER_T
value|30
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_400_MCUISP
value|31
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_G3D_PLLSRC
value|32
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_CSIS1
value|33
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_CSIS0
value|34
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_CAM1
value|35
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_FIMC3_LCLK
value|36
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_FIMC2_LCLK
value|37
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_FIMC1_LCLK
value|38
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_FIMC0_LCLK
value|39
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_MFC
value|40
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_MFC_1
value|41
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_MFC_0
value|42
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_G3D
value|43
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_G3D_1
value|44
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_G3D_0
value|45
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_MIPI0
value|46
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_FIMD0
value|47
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_TSADC_ISP
value|48
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_UART_ISP
value|49
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SPI1_ISP
value|50
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SPI0_ISP
value|51
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_PWM_ISP
value|52
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_AUDIO0
value|53
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_TSADC
value|54
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_MMC2
value|55
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_MMC1
value|56
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_MMC0
value|57
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_UART3
value|58
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_UART2
value|59
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_UART1
value|60
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_UART0
value|61
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SPI2
value|62
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SPI1
value|63
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SPI0
value|64
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SPDIF
value|65
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_AUDIO2
value|66
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_AUDIO1
value|67
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_MPLL_USER_C
value|68
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_HPM
value|69
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_CORE
value|70
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_APLL
value|71
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_PXLASYNC_CSIS1_FIMC
value|72
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_PXLASYNC_CSIS0_FIMC
value|73
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_JPEG
value|74
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_JPEG1
value|75
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_JPEG0
value|76
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_ISP0_300
value|77
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_ISP0_400
value|78
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_ISP0_300_USER
value|79
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_ISP1_300
value|80
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_ISP1_300_USER
value|81
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_HDMI
value|82
end_define

begin_comment
comment|/* Dividers */
end_comment

begin_define
define|#
directive|define
name|CLK_DIV_GPL
value|90
end_define

begin_define
define|#
directive|define
name|CLK_DIV_GDL
value|91
end_define

begin_define
define|#
directive|define
name|CLK_DIV_GPR
value|92
end_define

begin_define
define|#
directive|define
name|CLK_DIV_GDR
value|93
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_400_MCUISP
value|94
end_define

begin_define
define|#
directive|define
name|CLK_DIV_EBI
value|95
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_200
value|96
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_160
value|97
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_100
value|98
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_266
value|99
end_define

begin_define
define|#
directive|define
name|CLK_DIV_CSIS1
value|100
end_define

begin_define
define|#
directive|define
name|CLK_DIV_CSIS0
value|101
end_define

begin_define
define|#
directive|define
name|CLK_DIV_CAM1
value|102
end_define

begin_define
define|#
directive|define
name|CLK_DIV_FIMC3_LCLK
value|103
end_define

begin_define
define|#
directive|define
name|CLK_DIV_FIMC2_LCLK
value|104
end_define

begin_define
define|#
directive|define
name|CLK_DIV_FIMC1_LCLK
value|105
end_define

begin_define
define|#
directive|define
name|CLK_DIV_FIMC0_LCLK
value|106
end_define

begin_define
define|#
directive|define
name|CLK_DIV_TV_BLK
value|107
end_define

begin_define
define|#
directive|define
name|CLK_DIV_MFC
value|108
end_define

begin_define
define|#
directive|define
name|CLK_DIV_G3D
value|109
end_define

begin_define
define|#
directive|define
name|CLK_DIV_MIPI0_PRE
value|110
end_define

begin_define
define|#
directive|define
name|CLK_DIV_MIPI0
value|111
end_define

begin_define
define|#
directive|define
name|CLK_DIV_FIMD0
value|112
end_define

begin_define
define|#
directive|define
name|CLK_DIV_UART_ISP
value|113
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SPI1_ISP_PRE
value|114
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SPI1_ISP
value|115
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SPI0_ISP_PRE
value|116
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SPI0_ISP
value|117
end_define

begin_define
define|#
directive|define
name|CLK_DIV_PWM_ISP
value|118
end_define

begin_define
define|#
directive|define
name|CLK_DIV_PCM0
value|119
end_define

begin_define
define|#
directive|define
name|CLK_DIV_AUDIO0
value|120
end_define

begin_define
define|#
directive|define
name|CLK_DIV_TSADC_PRE
value|121
end_define

begin_define
define|#
directive|define
name|CLK_DIV_TSADC
value|122
end_define

begin_define
define|#
directive|define
name|CLK_DIV_MMC1_PRE
value|123
end_define

begin_define
define|#
directive|define
name|CLK_DIV_MMC1
value|124
end_define

begin_define
define|#
directive|define
name|CLK_DIV_MMC0_PRE
value|125
end_define

begin_define
define|#
directive|define
name|CLK_DIV_MMC0
value|126
end_define

begin_define
define|#
directive|define
name|CLK_DIV_MMC2_PRE
value|127
end_define

begin_define
define|#
directive|define
name|CLK_DIV_MMC2
value|128
end_define

begin_define
define|#
directive|define
name|CLK_DIV_UART3
value|129
end_define

begin_define
define|#
directive|define
name|CLK_DIV_UART2
value|130
end_define

begin_define
define|#
directive|define
name|CLK_DIV_UART1
value|131
end_define

begin_define
define|#
directive|define
name|CLK_DIV_UART0
value|132
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SPI1_PRE
value|133
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SPI1
value|134
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SPI0_PRE
value|135
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SPI0
value|136
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SPI2_PRE
value|137
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SPI2
value|138
end_define

begin_define
define|#
directive|define
name|CLK_DIV_PCM2
value|139
end_define

begin_define
define|#
directive|define
name|CLK_DIV_AUDIO2
value|140
end_define

begin_define
define|#
directive|define
name|CLK_DIV_PCM1
value|141
end_define

begin_define
define|#
directive|define
name|CLK_DIV_AUDIO1
value|142
end_define

begin_define
define|#
directive|define
name|CLK_DIV_I2S1
value|143
end_define

begin_define
define|#
directive|define
name|CLK_DIV_PXLASYNC_CSIS1_FIMC
value|144
end_define

begin_define
define|#
directive|define
name|CLK_DIV_PXLASYNC_CSIS0_FIMC
value|145
end_define

begin_define
define|#
directive|define
name|CLK_DIV_JPEG
value|146
end_define

begin_define
define|#
directive|define
name|CLK_DIV_CORE2
value|147
end_define

begin_define
define|#
directive|define
name|CLK_DIV_APLL
value|148
end_define

begin_define
define|#
directive|define
name|CLK_DIV_PCLK_DBG
value|149
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ATB
value|150
end_define

begin_define
define|#
directive|define
name|CLK_DIV_PERIPH
value|151
end_define

begin_define
define|#
directive|define
name|CLK_DIV_COREM1
value|152
end_define

begin_define
define|#
directive|define
name|CLK_DIV_COREM0
value|153
end_define

begin_define
define|#
directive|define
name|CLK_DIV_CORE
value|154
end_define

begin_define
define|#
directive|define
name|CLK_DIV_HPM
value|155
end_define

begin_define
define|#
directive|define
name|CLK_DIV_COPY
value|156
end_define

begin_comment
comment|/* Gates */
end_comment

begin_define
define|#
directive|define
name|CLK_ASYNC_G3D
value|180
end_define

begin_define
define|#
directive|define
name|CLK_ASYNC_MFCL
value|181
end_define

begin_define
define|#
directive|define
name|CLK_ASYNC_TVX
value|182
end_define

begin_define
define|#
directive|define
name|CLK_PPMULEFT
value|183
end_define

begin_define
define|#
directive|define
name|CLK_GPIO_LEFT
value|184
end_define

begin_define
define|#
directive|define
name|CLK_PPMUIMAGE
value|185
end_define

begin_define
define|#
directive|define
name|CLK_QEMDMA2
value|186
end_define

begin_define
define|#
directive|define
name|CLK_QEROTATOR
value|187
end_define

begin_define
define|#
directive|define
name|CLK_SMMUMDMA2
value|188
end_define

begin_define
define|#
directive|define
name|CLK_SMMUROTATOR
value|189
end_define

begin_define
define|#
directive|define
name|CLK_MDMA2
value|190
end_define

begin_define
define|#
directive|define
name|CLK_ROTATOR
value|191
end_define

begin_define
define|#
directive|define
name|CLK_ASYNC_ISPMX
value|192
end_define

begin_define
define|#
directive|define
name|CLK_ASYNC_MAUDIOX
value|193
end_define

begin_define
define|#
directive|define
name|CLK_ASYNC_MFCR
value|194
end_define

begin_define
define|#
directive|define
name|CLK_ASYNC_FSYSD
value|195
end_define

begin_define
define|#
directive|define
name|CLK_ASYNC_LCD0X
value|196
end_define

begin_define
define|#
directive|define
name|CLK_ASYNC_CAMX
value|197
end_define

begin_define
define|#
directive|define
name|CLK_PPMURIGHT
value|198
end_define

begin_define
define|#
directive|define
name|CLK_GPIO_RIGHT
value|199
end_define

begin_define
define|#
directive|define
name|CLK_ANTIRBK_APBIF
value|200
end_define

begin_define
define|#
directive|define
name|CLK_EFUSE_WRITER_APBIF
value|201
end_define

begin_define
define|#
directive|define
name|CLK_MONOCNT
value|202
end_define

begin_define
define|#
directive|define
name|CLK_TZPC6
value|203
end_define

begin_define
define|#
directive|define
name|CLK_PROVISIONKEY1
value|204
end_define

begin_define
define|#
directive|define
name|CLK_PROVISIONKEY0
value|205
end_define

begin_define
define|#
directive|define
name|CLK_CMU_ISPPART
value|206
end_define

begin_define
define|#
directive|define
name|CLK_TMU_APBIF
value|207
end_define

begin_define
define|#
directive|define
name|CLK_KEYIF
value|208
end_define

begin_define
define|#
directive|define
name|CLK_RTC
value|209
end_define

begin_define
define|#
directive|define
name|CLK_WDT
value|210
end_define

begin_define
define|#
directive|define
name|CLK_MCT
value|211
end_define

begin_define
define|#
directive|define
name|CLK_SECKEY
value|212
end_define

begin_define
define|#
directive|define
name|CLK_HDMI_CEC
value|213
end_define

begin_define
define|#
directive|define
name|CLK_TZPC5
value|214
end_define

begin_define
define|#
directive|define
name|CLK_TZPC4
value|215
end_define

begin_define
define|#
directive|define
name|CLK_TZPC3
value|216
end_define

begin_define
define|#
directive|define
name|CLK_TZPC2
value|217
end_define

begin_define
define|#
directive|define
name|CLK_TZPC1
value|218
end_define

begin_define
define|#
directive|define
name|CLK_TZPC0
value|219
end_define

begin_define
define|#
directive|define
name|CLK_CMU_COREPART
value|220
end_define

begin_define
define|#
directive|define
name|CLK_CMU_TOPPART
value|221
end_define

begin_define
define|#
directive|define
name|CLK_PMU_APBIF
value|222
end_define

begin_define
define|#
directive|define
name|CLK_SYSREG
value|223
end_define

begin_define
define|#
directive|define
name|CLK_CHIP_ID
value|224
end_define

begin_define
define|#
directive|define
name|CLK_SMMUFIMC_LITE2
value|225
end_define

begin_define
define|#
directive|define
name|CLK_FIMC_LITE2
value|226
end_define

begin_define
define|#
directive|define
name|CLK_PIXELASYNCM1
value|227
end_define

begin_define
define|#
directive|define
name|CLK_PIXELASYNCM0
value|228
end_define

begin_define
define|#
directive|define
name|CLK_PPMUCAMIF
value|229
end_define

begin_define
define|#
directive|define
name|CLK_SMMUJPEG
value|230
end_define

begin_define
define|#
directive|define
name|CLK_SMMUFIMC3
value|231
end_define

begin_define
define|#
directive|define
name|CLK_SMMUFIMC2
value|232
end_define

begin_define
define|#
directive|define
name|CLK_SMMUFIMC1
value|233
end_define

begin_define
define|#
directive|define
name|CLK_SMMUFIMC0
value|234
end_define

begin_define
define|#
directive|define
name|CLK_JPEG
value|235
end_define

begin_define
define|#
directive|define
name|CLK_CSIS1
value|236
end_define

begin_define
define|#
directive|define
name|CLK_CSIS0
value|237
end_define

begin_define
define|#
directive|define
name|CLK_FIMC3
value|238
end_define

begin_define
define|#
directive|define
name|CLK_FIMC2
value|239
end_define

begin_define
define|#
directive|define
name|CLK_FIMC1
value|240
end_define

begin_define
define|#
directive|define
name|CLK_FIMC0
value|241
end_define

begin_define
define|#
directive|define
name|CLK_PPMUTV
value|242
end_define

begin_define
define|#
directive|define
name|CLK_SMMUTV
value|243
end_define

begin_define
define|#
directive|define
name|CLK_HDMI
value|244
end_define

begin_define
define|#
directive|define
name|CLK_MIXER
value|245
end_define

begin_define
define|#
directive|define
name|CLK_VP
value|246
end_define

begin_define
define|#
directive|define
name|CLK_PPMUMFC_R
value|247
end_define

begin_define
define|#
directive|define
name|CLK_PPMUMFC_L
value|248
end_define

begin_define
define|#
directive|define
name|CLK_SMMUMFC_R
value|249
end_define

begin_define
define|#
directive|define
name|CLK_SMMUMFC_L
value|250
end_define

begin_define
define|#
directive|define
name|CLK_MFC
value|251
end_define

begin_define
define|#
directive|define
name|CLK_PPMUG3D
value|252
end_define

begin_define
define|#
directive|define
name|CLK_G3D
value|253
end_define

begin_define
define|#
directive|define
name|CLK_PPMULCD0
value|254
end_define

begin_define
define|#
directive|define
name|CLK_SMMUFIMD0
value|255
end_define

begin_define
define|#
directive|define
name|CLK_DSIM0
value|256
end_define

begin_define
define|#
directive|define
name|CLK_SMIES
value|257
end_define

begin_define
define|#
directive|define
name|CLK_MIE0
value|258
end_define

begin_define
define|#
directive|define
name|CLK_FIMD0
value|259
end_define

begin_define
define|#
directive|define
name|CLK_TSADC
value|260
end_define

begin_define
define|#
directive|define
name|CLK_PPMUFILE
value|261
end_define

begin_define
define|#
directive|define
name|CLK_NFCON
value|262
end_define

begin_define
define|#
directive|define
name|CLK_USBDEVICE
value|263
end_define

begin_define
define|#
directive|define
name|CLK_USBHOST
value|264
end_define

begin_define
define|#
directive|define
name|CLK_SROMC
value|265
end_define

begin_define
define|#
directive|define
name|CLK_SDMMC2
value|266
end_define

begin_define
define|#
directive|define
name|CLK_SDMMC1
value|267
end_define

begin_define
define|#
directive|define
name|CLK_SDMMC0
value|268
end_define

begin_define
define|#
directive|define
name|CLK_PDMA1
value|269
end_define

begin_define
define|#
directive|define
name|CLK_PDMA0
value|270
end_define

begin_define
define|#
directive|define
name|CLK_SPDIF
value|271
end_define

begin_define
define|#
directive|define
name|CLK_PWM
value|272
end_define

begin_define
define|#
directive|define
name|CLK_PCM2
value|273
end_define

begin_define
define|#
directive|define
name|CLK_PCM1
value|274
end_define

begin_define
define|#
directive|define
name|CLK_I2S1
value|275
end_define

begin_define
define|#
directive|define
name|CLK_SPI2
value|276
end_define

begin_define
define|#
directive|define
name|CLK_SPI1
value|277
end_define

begin_define
define|#
directive|define
name|CLK_SPI0
value|278
end_define

begin_define
define|#
directive|define
name|CLK_I2CHDMI
value|279
end_define

begin_define
define|#
directive|define
name|CLK_I2C7
value|280
end_define

begin_define
define|#
directive|define
name|CLK_I2C6
value|281
end_define

begin_define
define|#
directive|define
name|CLK_I2C5
value|282
end_define

begin_define
define|#
directive|define
name|CLK_I2C4
value|283
end_define

begin_define
define|#
directive|define
name|CLK_I2C3
value|284
end_define

begin_define
define|#
directive|define
name|CLK_I2C2
value|285
end_define

begin_define
define|#
directive|define
name|CLK_I2C1
value|286
end_define

begin_define
define|#
directive|define
name|CLK_I2C0
value|287
end_define

begin_define
define|#
directive|define
name|CLK_UART3
value|288
end_define

begin_define
define|#
directive|define
name|CLK_UART2
value|289
end_define

begin_define
define|#
directive|define
name|CLK_UART1
value|290
end_define

begin_define
define|#
directive|define
name|CLK_UART0
value|291
end_define

begin_comment
comment|/* Special clocks */
end_comment

begin_define
define|#
directive|define
name|CLK_SCLK_PXLAYSNC_CSIS1_FIMC
value|330
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_PXLAYSNC_CSIS0_FIMC
value|331
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_JPEG
value|332
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_CSIS1
value|333
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_CSIS0
value|334
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_CAM1
value|335
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_FIMC3_LCLK
value|336
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_FIMC2_LCLK
value|337
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_FIMC1_LCLK
value|338
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_FIMC0_LCLK
value|339
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_PIXEL
value|340
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_HDMI
value|341
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MIXER
value|342
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MFC
value|343
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_G3D
value|344
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MIPIDPHY4L
value|345
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MIPI0
value|346
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MDNIE0
value|347
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_FIMD0
value|348
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_PCM0
value|349
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_AUDIO0
value|350
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_TSADC
value|351
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_EBI
value|352
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MMC2
value|353
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MMC1
value|354
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MMC0
value|355
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_I2S
value|356
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_PCM2
value|357
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_PCM1
value|358
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_AUDIO2
value|359
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_AUDIO1
value|360
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SPDIF
value|361
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SPI2
value|362
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SPI1
value|363
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SPI0
value|364
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_UART3
value|365
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_UART2
value|366
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_UART1
value|367
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_UART0
value|368
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_HDMIPHY
value|369
end_define

begin_comment
comment|/*  * Total number of clocks of main CMU.  * NOTE: Must be equal to last clock ID increased by one.  */
end_comment

begin_define
define|#
directive|define
name|CLK_NR_CLKS
value|370
end_define

begin_comment
comment|/*  * CMU DMC  */
end_comment

begin_define
define|#
directive|define
name|CLK_DMC_FOUT_MPLL
value|1
end_define

begin_define
define|#
directive|define
name|CLK_DMC_FOUT_BPLL
value|2
end_define

begin_define
define|#
directive|define
name|CLK_DMC_MOUT_MPLL
value|3
end_define

begin_define
define|#
directive|define
name|CLK_DMC_MOUT_BPLL
value|4
end_define

begin_define
define|#
directive|define
name|CLK_DMC_MOUT_DPHY
value|5
end_define

begin_define
define|#
directive|define
name|CLK_DMC_MOUT_DMC_BUS
value|6
end_define

begin_define
define|#
directive|define
name|CLK_DMC_DIV_DMC
value|7
end_define

begin_define
define|#
directive|define
name|CLK_DMC_DIV_DPHY
value|8
end_define

begin_define
define|#
directive|define
name|CLK_DMC_DIV_DMC_PRE
value|9
end_define

begin_define
define|#
directive|define
name|CLK_DMC_DIV_DMCP
value|10
end_define

begin_define
define|#
directive|define
name|CLK_DMC_DIV_DMCD
value|11
end_define

begin_define
define|#
directive|define
name|CLK_DMC_DIV_MPLL_PRE
value|12
end_define

begin_comment
comment|/*  * Total number of clocks of CMU_DMC.  * NOTE: Must be equal to highest clock ID increased by one.  */
end_comment

begin_define
define|#
directive|define
name|NR_CLKS_DMC
value|13
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_CLOCK_SAMSUNG_EXYNOS4415_CLOCK_H */
end_comment

end_unit

