begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013 Samsung Electronics Co., Ltd.  * Author: Andrzej Hajda<a.hajda@samsung.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Device Tree binding constants for Exynos4 clock controller. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLOCK_EXYNOS_4_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLOCK_EXYNOS_4_H
end_define

begin_comment
comment|/* core clocks */
end_comment

begin_define
define|#
directive|define
name|CLK_XXTI
value|1
end_define

begin_define
define|#
directive|define
name|CLK_XUSBXTI
value|2
end_define

begin_define
define|#
directive|define
name|CLK_FIN_PLL
value|3
end_define

begin_define
define|#
directive|define
name|CLK_FOUT_APLL
value|4
end_define

begin_define
define|#
directive|define
name|CLK_FOUT_MPLL
value|5
end_define

begin_define
define|#
directive|define
name|CLK_FOUT_EPLL
value|6
end_define

begin_define
define|#
directive|define
name|CLK_FOUT_VPLL
value|7
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_APLL
value|8
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MPLL
value|9
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_EPLL
value|10
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_VPLL
value|11
end_define

begin_define
define|#
directive|define
name|CLK_ARM_CLK
value|12
end_define

begin_define
define|#
directive|define
name|CLK_ACLK200
value|13
end_define

begin_define
define|#
directive|define
name|CLK_ACLK100
value|14
end_define

begin_define
define|#
directive|define
name|CLK_ACLK160
value|15
end_define

begin_define
define|#
directive|define
name|CLK_ACLK133
value|16
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_MPLL_USER_T
value|17
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_define
define|#
directive|define
name|CLK_MOUT_MPLL_USER_C
value|18
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_define
define|#
directive|define
name|CLK_MOUT_CORE
value|19
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_APLL
value|20
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_HDMIPHY
value|22
end_define

begin_define
define|#
directive|define
name|CLK_OUT_DMC
value|23
end_define

begin_define
define|#
directive|define
name|CLK_OUT_TOP
value|24
end_define

begin_define
define|#
directive|define
name|CLK_OUT_LEFTBUS
value|25
end_define

begin_define
define|#
directive|define
name|CLK_OUT_RIGHTBUS
value|26
end_define

begin_define
define|#
directive|define
name|CLK_OUT_CPU
value|27
end_define

begin_comment
comment|/* gate for special clocks (sclk) */
end_comment

begin_define
define|#
directive|define
name|CLK_SCLK_FIMC0
value|128
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_FIMC1
value|129
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_FIMC2
value|130
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_FIMC3
value|131
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_CAM0
value|132
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_CAM1
value|133
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_CSIS0
value|134
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_CSIS1
value|135
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_HDMI
value|136
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MIXER
value|137
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_DAC
value|138
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_PIXEL
value|139
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_FIMD0
value|140
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MDNIE0
value|141
end_define

begin_comment
comment|/* Exynos4412 only */
end_comment

begin_define
define|#
directive|define
name|CLK_SCLK_MDNIE_PWM0
value|142
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MIPI0
value|143
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_AUDIO0
value|144
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MMC0
value|145
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MMC1
value|146
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MMC2
value|147
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MMC3
value|148
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MMC4
value|149
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SATA
value|150
end_define

begin_comment
comment|/* Exynos4210 only */
end_comment

begin_define
define|#
directive|define
name|CLK_SCLK_UART0
value|151
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_UART1
value|152
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_UART2
value|153
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_UART3
value|154
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_UART4
value|155
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_AUDIO1
value|156
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_AUDIO2
value|157
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SPDIF
value|158
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SPI0
value|159
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SPI1
value|160
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SPI2
value|161
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SLIMBUS
value|162
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_FIMD1
value|163
end_define

begin_comment
comment|/* Exynos4210 only */
end_comment

begin_define
define|#
directive|define
name|CLK_SCLK_MIPI1
value|164
end_define

begin_comment
comment|/* Exynos4210 only */
end_comment

begin_define
define|#
directive|define
name|CLK_SCLK_PCM1
value|165
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_PCM2
value|166
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_I2S1
value|167
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_I2S2
value|168
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MIPIHSI
value|169
end_define

begin_comment
comment|/* Exynos4412 only */
end_comment

begin_define
define|#
directive|define
name|CLK_SCLK_MFC
value|170
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_PCM0
value|171
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_G3D
value|172
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_PWM_ISP
value|173
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_define
define|#
directive|define
name|CLK_SCLK_SPI0_ISP
value|174
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_define
define|#
directive|define
name|CLK_SCLK_SPI1_ISP
value|175
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_define
define|#
directive|define
name|CLK_SCLK_UART_ISP
value|176
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_define
define|#
directive|define
name|CLK_SCLK_FIMG2D
value|177
end_define

begin_comment
comment|/* gate clocks */
end_comment

begin_define
define|#
directive|define
name|CLK_FIMC0
value|256
end_define

begin_define
define|#
directive|define
name|CLK_FIMC1
value|257
end_define

begin_define
define|#
directive|define
name|CLK_FIMC2
value|258
end_define

begin_define
define|#
directive|define
name|CLK_FIMC3
value|259
end_define

begin_define
define|#
directive|define
name|CLK_CSIS0
value|260
end_define

begin_define
define|#
directive|define
name|CLK_CSIS1
value|261
end_define

begin_define
define|#
directive|define
name|CLK_JPEG
value|262
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_FIMC0
value|263
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_FIMC1
value|264
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_FIMC2
value|265
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_FIMC3
value|266
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_JPEG
value|267
end_define

begin_define
define|#
directive|define
name|CLK_VP
value|268
end_define

begin_define
define|#
directive|define
name|CLK_MIXER
value|269
end_define

begin_define
define|#
directive|define
name|CLK_TVENC
value|270
end_define

begin_comment
comment|/* Exynos4210 only */
end_comment

begin_define
define|#
directive|define
name|CLK_HDMI
value|271
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_TV
value|272
end_define

begin_define
define|#
directive|define
name|CLK_MFC
value|273
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_MFCL
value|274
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_MFCR
value|275
end_define

begin_define
define|#
directive|define
name|CLK_G3D
value|276
end_define

begin_define
define|#
directive|define
name|CLK_G2D
value|277
end_define

begin_define
define|#
directive|define
name|CLK_ROTATOR
value|278
end_define

begin_comment
comment|/* Exynos4210 only */
end_comment

begin_define
define|#
directive|define
name|CLK_MDMA
value|279
end_define

begin_comment
comment|/* Exynos4210 only */
end_comment

begin_define
define|#
directive|define
name|CLK_SMMU_G2D
value|280
end_define

begin_comment
comment|/* Exynos4210 only */
end_comment

begin_define
define|#
directive|define
name|CLK_SMMU_ROTATOR
value|281
end_define

begin_comment
comment|/* Exynos4210 only */
end_comment

begin_define
define|#
directive|define
name|CLK_SMMU_MDMA
value|282
end_define

begin_comment
comment|/* Exynos4210 only */
end_comment

begin_define
define|#
directive|define
name|CLK_FIMD0
value|283
end_define

begin_define
define|#
directive|define
name|CLK_MIE0
value|284
end_define

begin_define
define|#
directive|define
name|CLK_MDNIE0
value|285
end_define

begin_comment
comment|/* Exynos4412 only */
end_comment

begin_define
define|#
directive|define
name|CLK_DSIM0
value|286
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_FIMD0
value|287
end_define

begin_define
define|#
directive|define
name|CLK_FIMD1
value|288
end_define

begin_comment
comment|/* Exynos4210 only */
end_comment

begin_define
define|#
directive|define
name|CLK_MIE1
value|289
end_define

begin_comment
comment|/* Exynos4210 only */
end_comment

begin_define
define|#
directive|define
name|CLK_DSIM1
value|290
end_define

begin_comment
comment|/* Exynos4210 only */
end_comment

begin_define
define|#
directive|define
name|CLK_SMMU_FIMD1
value|291
end_define

begin_comment
comment|/* Exynos4210 only */
end_comment

begin_define
define|#
directive|define
name|CLK_PDMA0
value|292
end_define

begin_define
define|#
directive|define
name|CLK_PDMA1
value|293
end_define

begin_define
define|#
directive|define
name|CLK_PCIE_PHY
value|294
end_define

begin_define
define|#
directive|define
name|CLK_SATA_PHY
value|295
end_define

begin_comment
comment|/* Exynos4210 only */
end_comment

begin_define
define|#
directive|define
name|CLK_TSI
value|296
end_define

begin_define
define|#
directive|define
name|CLK_SDMMC0
value|297
end_define

begin_define
define|#
directive|define
name|CLK_SDMMC1
value|298
end_define

begin_define
define|#
directive|define
name|CLK_SDMMC2
value|299
end_define

begin_define
define|#
directive|define
name|CLK_SDMMC3
value|300
end_define

begin_define
define|#
directive|define
name|CLK_SDMMC4
value|301
end_define

begin_define
define|#
directive|define
name|CLK_SATA
value|302
end_define

begin_comment
comment|/* Exynos4210 only */
end_comment

begin_define
define|#
directive|define
name|CLK_SROMC
value|303
end_define

begin_define
define|#
directive|define
name|CLK_USB_HOST
value|304
end_define

begin_define
define|#
directive|define
name|CLK_USB_DEVICE
value|305
end_define

begin_define
define|#
directive|define
name|CLK_PCIE
value|306
end_define

begin_define
define|#
directive|define
name|CLK_ONENAND
value|307
end_define

begin_define
define|#
directive|define
name|CLK_NFCON
value|308
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_PCIE
value|309
end_define

begin_define
define|#
directive|define
name|CLK_GPS
value|310
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_GPS
value|311
end_define

begin_define
define|#
directive|define
name|CLK_UART0
value|312
end_define

begin_define
define|#
directive|define
name|CLK_UART1
value|313
end_define

begin_define
define|#
directive|define
name|CLK_UART2
value|314
end_define

begin_define
define|#
directive|define
name|CLK_UART3
value|315
end_define

begin_define
define|#
directive|define
name|CLK_UART4
value|316
end_define

begin_define
define|#
directive|define
name|CLK_I2C0
value|317
end_define

begin_define
define|#
directive|define
name|CLK_I2C1
value|318
end_define

begin_define
define|#
directive|define
name|CLK_I2C2
value|319
end_define

begin_define
define|#
directive|define
name|CLK_I2C3
value|320
end_define

begin_define
define|#
directive|define
name|CLK_I2C4
value|321
end_define

begin_define
define|#
directive|define
name|CLK_I2C5
value|322
end_define

begin_define
define|#
directive|define
name|CLK_I2C6
value|323
end_define

begin_define
define|#
directive|define
name|CLK_I2C7
value|324
end_define

begin_define
define|#
directive|define
name|CLK_I2C_HDMI
value|325
end_define

begin_define
define|#
directive|define
name|CLK_TSADC
value|326
end_define

begin_define
define|#
directive|define
name|CLK_SPI0
value|327
end_define

begin_define
define|#
directive|define
name|CLK_SPI1
value|328
end_define

begin_define
define|#
directive|define
name|CLK_SPI2
value|329
end_define

begin_define
define|#
directive|define
name|CLK_I2S1
value|330
end_define

begin_define
define|#
directive|define
name|CLK_I2S2
value|331
end_define

begin_define
define|#
directive|define
name|CLK_PCM0
value|332
end_define

begin_define
define|#
directive|define
name|CLK_I2S0
value|333
end_define

begin_define
define|#
directive|define
name|CLK_PCM1
value|334
end_define

begin_define
define|#
directive|define
name|CLK_PCM2
value|335
end_define

begin_define
define|#
directive|define
name|CLK_PWM
value|336
end_define

begin_define
define|#
directive|define
name|CLK_SLIMBUS
value|337
end_define

begin_define
define|#
directive|define
name|CLK_SPDIF
value|338
end_define

begin_define
define|#
directive|define
name|CLK_AC97
value|339
end_define

begin_define
define|#
directive|define
name|CLK_MODEMIF
value|340
end_define

begin_define
define|#
directive|define
name|CLK_CHIPID
value|341
end_define

begin_define
define|#
directive|define
name|CLK_SYSREG
value|342
end_define

begin_define
define|#
directive|define
name|CLK_HDMI_CEC
value|343
end_define

begin_define
define|#
directive|define
name|CLK_MCT
value|344
end_define

begin_define
define|#
directive|define
name|CLK_WDT
value|345
end_define

begin_define
define|#
directive|define
name|CLK_RTC
value|346
end_define

begin_define
define|#
directive|define
name|CLK_KEYIF
value|347
end_define

begin_define
define|#
directive|define
name|CLK_AUDSS
value|348
end_define

begin_define
define|#
directive|define
name|CLK_MIPI_HSI
value|349
end_define

begin_comment
comment|/* Exynos4210 only */
end_comment

begin_define
define|#
directive|define
name|CLK_PIXELASYNCM0
value|351
end_define

begin_define
define|#
directive|define
name|CLK_PIXELASYNCM1
value|352
end_define

begin_define
define|#
directive|define
name|CLK_FIMC_LITE0
value|353
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_define
define|#
directive|define
name|CLK_FIMC_LITE1
value|354
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_define
define|#
directive|define
name|CLK_PPMUISPX
value|355
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_define
define|#
directive|define
name|CLK_PPMUISPMX
value|356
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_define
define|#
directive|define
name|CLK_FIMC_ISP
value|357
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_define
define|#
directive|define
name|CLK_FIMC_DRC
value|358
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_define
define|#
directive|define
name|CLK_FIMC_FD
value|359
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_define
define|#
directive|define
name|CLK_MCUISP
value|360
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_define
define|#
directive|define
name|CLK_GICISP
value|361
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_define
define|#
directive|define
name|CLK_SMMU_ISP
value|362
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_define
define|#
directive|define
name|CLK_SMMU_DRC
value|363
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_define
define|#
directive|define
name|CLK_SMMU_FD
value|364
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_define
define|#
directive|define
name|CLK_SMMU_LITE0
value|365
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_define
define|#
directive|define
name|CLK_SMMU_LITE1
value|366
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_define
define|#
directive|define
name|CLK_MCUCTL_ISP
value|367
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_define
define|#
directive|define
name|CLK_MPWM_ISP
value|368
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_define
define|#
directive|define
name|CLK_I2C0_ISP
value|369
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_define
define|#
directive|define
name|CLK_I2C1_ISP
value|370
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_define
define|#
directive|define
name|CLK_MTCADC_ISP
value|371
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_define
define|#
directive|define
name|CLK_PWM_ISP
value|372
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_define
define|#
directive|define
name|CLK_WDT_ISP
value|373
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_define
define|#
directive|define
name|CLK_UART_ISP
value|374
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_define
define|#
directive|define
name|CLK_ASYNCAXIM
value|375
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_define
define|#
directive|define
name|CLK_SMMU_ISPCX
value|376
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_define
define|#
directive|define
name|CLK_SPI0_ISP
value|377
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_define
define|#
directive|define
name|CLK_SPI1_ISP
value|378
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_define
define|#
directive|define
name|CLK_PWM_ISP_SCLK
value|379
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_define
define|#
directive|define
name|CLK_SPI0_ISP_SCLK
value|380
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_define
define|#
directive|define
name|CLK_SPI1_ISP_SCLK
value|381
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_define
define|#
directive|define
name|CLK_UART_ISP_SCLK
value|382
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_define
define|#
directive|define
name|CLK_TMU_APBIF
value|383
end_define

begin_comment
comment|/* mux clocks */
end_comment

begin_define
define|#
directive|define
name|CLK_MOUT_FIMC0
value|384
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_FIMC1
value|385
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_FIMC2
value|386
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_FIMC3
value|387
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_CAM0
value|388
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_CAM1
value|389
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_CSIS0
value|390
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_CSIS1
value|391
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_G3D0
value|392
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_G3D1
value|393
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_G3D
value|394
end_define

begin_define
define|#
directive|define
name|CLK_ACLK400_MCUISP
value|395
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_comment
comment|/* gate clocks - ppmu */
end_comment

begin_define
define|#
directive|define
name|CLK_PPMULEFT
value|400
end_define

begin_define
define|#
directive|define
name|CLK_PPMURIGHT
value|401
end_define

begin_define
define|#
directive|define
name|CLK_PPMUCAMIF
value|402
end_define

begin_define
define|#
directive|define
name|CLK_PPMUTV
value|403
end_define

begin_define
define|#
directive|define
name|CLK_PPMUMFC_L
value|404
end_define

begin_define
define|#
directive|define
name|CLK_PPMUMFC_R
value|405
end_define

begin_define
define|#
directive|define
name|CLK_PPMUG3D
value|406
end_define

begin_define
define|#
directive|define
name|CLK_PPMUIMAGE
value|407
end_define

begin_define
define|#
directive|define
name|CLK_PPMULCD0
value|408
end_define

begin_define
define|#
directive|define
name|CLK_PPMULCD1
value|409
end_define

begin_comment
comment|/* Exynos4210 only */
end_comment

begin_define
define|#
directive|define
name|CLK_PPMUFILE
value|410
end_define

begin_define
define|#
directive|define
name|CLK_PPMUGPS
value|411
end_define

begin_define
define|#
directive|define
name|CLK_PPMUDMC0
value|412
end_define

begin_define
define|#
directive|define
name|CLK_PPMUDMC1
value|413
end_define

begin_define
define|#
directive|define
name|CLK_PPMUCPU
value|414
end_define

begin_define
define|#
directive|define
name|CLK_PPMUACP
value|415
end_define

begin_comment
comment|/* div clocks */
end_comment

begin_define
define|#
directive|define
name|CLK_DIV_ISP0
value|450
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_define
define|#
directive|define
name|CLK_DIV_ISP1
value|451
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_define
define|#
directive|define
name|CLK_DIV_MCUISP0
value|452
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_define
define|#
directive|define
name|CLK_DIV_MCUISP1
value|453
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_define
define|#
directive|define
name|CLK_DIV_ACLK200
value|454
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_define
define|#
directive|define
name|CLK_DIV_ACLK400_MCUISP
value|455
end_define

begin_comment
comment|/* Exynos4x12 only */
end_comment

begin_comment
comment|/* must be greater than maximal clock id */
end_comment

begin_define
define|#
directive|define
name|CLK_NR_CLKS
value|456
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_CLOCK_EXYNOS_4_H */
end_comment

end_unit

