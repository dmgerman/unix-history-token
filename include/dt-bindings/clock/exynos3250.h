begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2014 Samsung Electronics Co., Ltd.  * 	Author: Tomasz Figa<t.figa@samsung.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Device Tree binding constants for Samsung Exynos3250 clock controllers.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLOCK_SAMSUNG_EXYNOS3250_CLOCK_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLOCK_SAMSUNG_EXYNOS3250_CLOCK_H
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
name|CLK_FOUT_VPLL
value|4
end_define

begin_define
define|#
directive|define
name|CLK_FOUT_UPLL
value|5
end_define

begin_define
define|#
directive|define
name|CLK_FOUT_MPLL
value|6
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
name|CLK_MOUT_ACLK_266_1
value|24
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_266_0
value|25
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_266
value|26
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_VPLL
value|27
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_EPLL_USER
value|28
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_EBI_1
value|29
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_UPLL
value|30
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_400_MCUISP_SUB
value|31
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_MPLL
value|32
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_400_MCUISP
value|33
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_VPLLSRC
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
name|CLK_MOUT_CAM_BLK
value|36
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_MFC
value|37
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_MFC_1
value|38
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_MFC_0
value|39
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_G3D
value|40
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_G3D_1
value|41
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_G3D_0
value|42
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_MIPI0
value|43
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_FIMD0
value|44
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_UART_ISP
value|45
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SPI1_ISP
value|46
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SPI0_ISP
value|47
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_TSADC
value|48
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_MMC1
value|49
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_MMC0
value|50
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_UART1
value|51
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_UART0
value|52
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SPI1
value|53
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SPI0
value|54
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_AUDIO
value|55
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_MPLL_USER_C
value|56
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_HPM
value|57
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_CORE
value|58
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_APLL
value|59
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_ACLK_266_SUB
value|60
end_define

begin_comment
comment|/* Dividers */
end_comment

begin_define
define|#
directive|define
name|CLK_DIV_GPL
value|64
end_define

begin_define
define|#
directive|define
name|CLK_DIV_GDL
value|65
end_define

begin_define
define|#
directive|define
name|CLK_DIV_GPR
value|66
end_define

begin_define
define|#
directive|define
name|CLK_DIV_GDR
value|67
end_define

begin_define
define|#
directive|define
name|CLK_DIV_MPLL_PRE
value|68
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_400_MCUISP
value|69
end_define

begin_define
define|#
directive|define
name|CLK_DIV_EBI
value|70
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_200
value|71
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_160
value|72
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_100
value|73
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ACLK_266
value|74
end_define

begin_define
define|#
directive|define
name|CLK_DIV_CAM1
value|75
end_define

begin_define
define|#
directive|define
name|CLK_DIV_CAM_BLK
value|76
end_define

begin_define
define|#
directive|define
name|CLK_DIV_MFC
value|77
end_define

begin_define
define|#
directive|define
name|CLK_DIV_G3D
value|78
end_define

begin_define
define|#
directive|define
name|CLK_DIV_MIPI0_PRE
value|79
end_define

begin_define
define|#
directive|define
name|CLK_DIV_MIPI0
value|80
end_define

begin_define
define|#
directive|define
name|CLK_DIV_FIMD0
value|81
end_define

begin_define
define|#
directive|define
name|CLK_DIV_UART_ISP
value|82
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SPI1_ISP_PRE
value|83
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SPI1_ISP
value|84
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SPI0_ISP_PRE
value|85
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SPI0_ISP
value|86
end_define

begin_define
define|#
directive|define
name|CLK_DIV_TSADC_PRE
value|87
end_define

begin_define
define|#
directive|define
name|CLK_DIV_TSADC
value|88
end_define

begin_define
define|#
directive|define
name|CLK_DIV_MMC1_PRE
value|89
end_define

begin_define
define|#
directive|define
name|CLK_DIV_MMC1
value|90
end_define

begin_define
define|#
directive|define
name|CLK_DIV_MMC0_PRE
value|91
end_define

begin_define
define|#
directive|define
name|CLK_DIV_MMC0
value|92
end_define

begin_define
define|#
directive|define
name|CLK_DIV_UART1
value|93
end_define

begin_define
define|#
directive|define
name|CLK_DIV_UART0
value|94
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SPI1_PRE
value|95
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SPI1
value|96
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SPI0_PRE
value|97
end_define

begin_define
define|#
directive|define
name|CLK_DIV_SPI0
value|98
end_define

begin_define
define|#
directive|define
name|CLK_DIV_PCM
value|99
end_define

begin_define
define|#
directive|define
name|CLK_DIV_AUDIO
value|100
end_define

begin_define
define|#
directive|define
name|CLK_DIV_I2S
value|101
end_define

begin_define
define|#
directive|define
name|CLK_DIV_CORE2
value|102
end_define

begin_define
define|#
directive|define
name|CLK_DIV_APLL
value|103
end_define

begin_define
define|#
directive|define
name|CLK_DIV_PCLK_DBG
value|104
end_define

begin_define
define|#
directive|define
name|CLK_DIV_ATB
value|105
end_define

begin_define
define|#
directive|define
name|CLK_DIV_COREM
value|106
end_define

begin_define
define|#
directive|define
name|CLK_DIV_CORE
value|107
end_define

begin_define
define|#
directive|define
name|CLK_DIV_HPM
value|108
end_define

begin_define
define|#
directive|define
name|CLK_DIV_COPY
value|109
end_define

begin_comment
comment|/* Gates */
end_comment

begin_define
define|#
directive|define
name|CLK_ASYNC_G3D
value|128
end_define

begin_define
define|#
directive|define
name|CLK_ASYNC_MFCL
value|129
end_define

begin_define
define|#
directive|define
name|CLK_PPMULEFT
value|130
end_define

begin_define
define|#
directive|define
name|CLK_GPIO_LEFT
value|131
end_define

begin_define
define|#
directive|define
name|CLK_ASYNC_ISPMX
value|132
end_define

begin_define
define|#
directive|define
name|CLK_ASYNC_FSYSD
value|133
end_define

begin_define
define|#
directive|define
name|CLK_ASYNC_LCD0X
value|134
end_define

begin_define
define|#
directive|define
name|CLK_ASYNC_CAMX
value|135
end_define

begin_define
define|#
directive|define
name|CLK_PPMURIGHT
value|136
end_define

begin_define
define|#
directive|define
name|CLK_GPIO_RIGHT
value|137
end_define

begin_define
define|#
directive|define
name|CLK_MONOCNT
value|138
end_define

begin_define
define|#
directive|define
name|CLK_TZPC6
value|139
end_define

begin_define
define|#
directive|define
name|CLK_PROVISIONKEY1
value|140
end_define

begin_define
define|#
directive|define
name|CLK_PROVISIONKEY0
value|141
end_define

begin_define
define|#
directive|define
name|CLK_CMU_ISPPART
value|142
end_define

begin_define
define|#
directive|define
name|CLK_TMU_APBIF
value|143
end_define

begin_define
define|#
directive|define
name|CLK_KEYIF
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
name|CLK_WDT
value|146
end_define

begin_define
define|#
directive|define
name|CLK_MCT
value|147
end_define

begin_define
define|#
directive|define
name|CLK_SECKEY
value|148
end_define

begin_define
define|#
directive|define
name|CLK_TZPC5
value|149
end_define

begin_define
define|#
directive|define
name|CLK_TZPC4
value|150
end_define

begin_define
define|#
directive|define
name|CLK_TZPC3
value|151
end_define

begin_define
define|#
directive|define
name|CLK_TZPC2
value|152
end_define

begin_define
define|#
directive|define
name|CLK_TZPC1
value|153
end_define

begin_define
define|#
directive|define
name|CLK_TZPC0
value|154
end_define

begin_define
define|#
directive|define
name|CLK_CMU_COREPART
value|155
end_define

begin_define
define|#
directive|define
name|CLK_CMU_TOPPART
value|156
end_define

begin_define
define|#
directive|define
name|CLK_PMU_APBIF
value|157
end_define

begin_define
define|#
directive|define
name|CLK_SYSREG
value|158
end_define

begin_define
define|#
directive|define
name|CLK_CHIP_ID
value|159
end_define

begin_define
define|#
directive|define
name|CLK_QEJPEG
value|160
end_define

begin_define
define|#
directive|define
name|CLK_PIXELASYNCM1
value|161
end_define

begin_define
define|#
directive|define
name|CLK_PIXELASYNCM0
value|162
end_define

begin_define
define|#
directive|define
name|CLK_PPMUCAMIF
value|163
end_define

begin_define
define|#
directive|define
name|CLK_QEM2MSCALER
value|164
end_define

begin_define
define|#
directive|define
name|CLK_QEGSCALER1
value|165
end_define

begin_define
define|#
directive|define
name|CLK_QEGSCALER0
value|166
end_define

begin_define
define|#
directive|define
name|CLK_SMMUJPEG
value|167
end_define

begin_define
define|#
directive|define
name|CLK_SMMUM2M2SCALER
value|168
end_define

begin_define
define|#
directive|define
name|CLK_SMMUGSCALER1
value|169
end_define

begin_define
define|#
directive|define
name|CLK_SMMUGSCALER0
value|170
end_define

begin_define
define|#
directive|define
name|CLK_JPEG
value|171
end_define

begin_define
define|#
directive|define
name|CLK_M2MSCALER
value|172
end_define

begin_define
define|#
directive|define
name|CLK_GSCALER1
value|173
end_define

begin_define
define|#
directive|define
name|CLK_GSCALER0
value|174
end_define

begin_define
define|#
directive|define
name|CLK_QEMFC
value|175
end_define

begin_define
define|#
directive|define
name|CLK_PPMUMFC_L
value|176
end_define

begin_define
define|#
directive|define
name|CLK_SMMUMFC_L
value|177
end_define

begin_define
define|#
directive|define
name|CLK_MFC
value|178
end_define

begin_define
define|#
directive|define
name|CLK_SMMUG3D
value|179
end_define

begin_define
define|#
directive|define
name|CLK_QEG3D
value|180
end_define

begin_define
define|#
directive|define
name|CLK_PPMUG3D
value|181
end_define

begin_define
define|#
directive|define
name|CLK_G3D
value|182
end_define

begin_define
define|#
directive|define
name|CLK_QE_CH1_LCD
value|183
end_define

begin_define
define|#
directive|define
name|CLK_QE_CH0_LCD
value|184
end_define

begin_define
define|#
directive|define
name|CLK_PPMULCD0
value|185
end_define

begin_define
define|#
directive|define
name|CLK_SMMUFIMD0
value|186
end_define

begin_define
define|#
directive|define
name|CLK_DSIM0
value|187
end_define

begin_define
define|#
directive|define
name|CLK_FIMD0
value|188
end_define

begin_define
define|#
directive|define
name|CLK_CAM1
value|189
end_define

begin_define
define|#
directive|define
name|CLK_UART_ISP_TOP
value|190
end_define

begin_define
define|#
directive|define
name|CLK_SPI1_ISP_TOP
value|191
end_define

begin_define
define|#
directive|define
name|CLK_SPI0_ISP_TOP
value|192
end_define

begin_define
define|#
directive|define
name|CLK_TSADC
value|193
end_define

begin_define
define|#
directive|define
name|CLK_PPMUFILE
value|194
end_define

begin_define
define|#
directive|define
name|CLK_USBOTG
value|195
end_define

begin_define
define|#
directive|define
name|CLK_USBHOST
value|196
end_define

begin_define
define|#
directive|define
name|CLK_SROMC
value|197
end_define

begin_define
define|#
directive|define
name|CLK_SDMMC1
value|198
end_define

begin_define
define|#
directive|define
name|CLK_SDMMC0
value|199
end_define

begin_define
define|#
directive|define
name|CLK_PDMA1
value|200
end_define

begin_define
define|#
directive|define
name|CLK_PDMA0
value|201
end_define

begin_define
define|#
directive|define
name|CLK_PWM
value|202
end_define

begin_define
define|#
directive|define
name|CLK_PCM
value|203
end_define

begin_define
define|#
directive|define
name|CLK_I2S
value|204
end_define

begin_define
define|#
directive|define
name|CLK_SPI1
value|205
end_define

begin_define
define|#
directive|define
name|CLK_SPI0
value|206
end_define

begin_define
define|#
directive|define
name|CLK_I2C7
value|207
end_define

begin_define
define|#
directive|define
name|CLK_I2C6
value|208
end_define

begin_define
define|#
directive|define
name|CLK_I2C5
value|209
end_define

begin_define
define|#
directive|define
name|CLK_I2C4
value|210
end_define

begin_define
define|#
directive|define
name|CLK_I2C3
value|211
end_define

begin_define
define|#
directive|define
name|CLK_I2C2
value|212
end_define

begin_define
define|#
directive|define
name|CLK_I2C1
value|213
end_define

begin_define
define|#
directive|define
name|CLK_I2C0
value|214
end_define

begin_define
define|#
directive|define
name|CLK_UART1
value|215
end_define

begin_define
define|#
directive|define
name|CLK_UART0
value|216
end_define

begin_define
define|#
directive|define
name|CLK_BLOCK_LCD
value|217
end_define

begin_define
define|#
directive|define
name|CLK_BLOCK_G3D
value|218
end_define

begin_define
define|#
directive|define
name|CLK_BLOCK_MFC
value|219
end_define

begin_define
define|#
directive|define
name|CLK_BLOCK_CAM
value|220
end_define

begin_define
define|#
directive|define
name|CLK_SMIES
value|221
end_define

begin_comment
comment|/* Special clocks */
end_comment

begin_define
define|#
directive|define
name|CLK_SCLK_JPEG
value|224
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_M2MSCALER
value|225
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_GSCALER1
value|226
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_GSCALER0
value|227
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MFC
value|228
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_G3D
value|229
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MIPIDPHY2L
value|230
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MIPI0
value|231
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_FIMD0
value|232
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_CAM1
value|233
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_UART_ISP
value|234
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SPI1_ISP
value|235
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SPI0_ISP
value|236
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_UPLL
value|237
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_TSADC
value|238
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_EBI
value|239
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MMC1
value|240
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MMC0
value|241
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_I2S
value|242
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_PCM
value|243
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SPI1
value|244
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SPI0
value|245
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_UART1
value|246
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_UART0
value|247
end_define

begin_comment
comment|/*  * Total number of clocks of main CMU.  * NOTE: Must be equal to last clock ID increased by one.  */
end_comment

begin_define
define|#
directive|define
name|CLK_NR_CLKS
value|248
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_CLOCK_SAMSUNG_EXYNOS3250_CLOCK_H */
end_comment

end_unit

