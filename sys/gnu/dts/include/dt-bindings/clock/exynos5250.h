begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013 Samsung Electronics Co., Ltd.  * Author: Andrzej Hajda<a.hajda@samsung.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Device Tree binding constants for Exynos5250 clock controller. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLOCK_EXYNOS_5250_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLOCK_EXYNOS_5250_H
end_define

begin_comment
comment|/* core clocks */
end_comment

begin_define
define|#
directive|define
name|CLK_FIN_PLL
value|1
end_define

begin_define
define|#
directive|define
name|CLK_FOUT_APLL
value|2
end_define

begin_define
define|#
directive|define
name|CLK_FOUT_MPLL
value|3
end_define

begin_define
define|#
directive|define
name|CLK_FOUT_BPLL
value|4
end_define

begin_define
define|#
directive|define
name|CLK_FOUT_GPLL
value|5
end_define

begin_define
define|#
directive|define
name|CLK_FOUT_CPLL
value|6
end_define

begin_define
define|#
directive|define
name|CLK_FOUT_EPLL
value|7
end_define

begin_define
define|#
directive|define
name|CLK_FOUT_VPLL
value|8
end_define

begin_comment
comment|/* gate for special clocks (sclk) */
end_comment

begin_define
define|#
directive|define
name|CLK_SCLK_CAM_BAYER
value|128
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_CAM0
value|129
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_CAM1
value|130
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_GSCL_WA
value|131
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_GSCL_WB
value|132
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_FIMD1
value|133
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MIPI1
value|134
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_DP
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
name|CLK_SCLK_PIXEL
value|137
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_AUDIO0
value|138
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MMC0
value|139
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MMC1
value|140
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MMC2
value|141
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MMC3
value|142
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SATA
value|143
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_USB3
value|144
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_JPEG
value|145
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_UART0
value|146
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_UART1
value|147
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_UART2
value|148
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_UART3
value|149
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_PWM
value|150
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_AUDIO1
value|151
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_AUDIO2
value|152
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SPDIF
value|153
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SPI0
value|154
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SPI1
value|155
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SPI2
value|156
end_define

begin_define
define|#
directive|define
name|CLK_DIV_I2S1
value|157
end_define

begin_define
define|#
directive|define
name|CLK_DIV_I2S2
value|158
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_HDMIPHY
value|159
end_define

begin_define
define|#
directive|define
name|CLK_DIV_PCM0
value|160
end_define

begin_comment
comment|/* gate clocks */
end_comment

begin_define
define|#
directive|define
name|CLK_GSCL0
value|256
end_define

begin_define
define|#
directive|define
name|CLK_GSCL1
value|257
end_define

begin_define
define|#
directive|define
name|CLK_GSCL2
value|258
end_define

begin_define
define|#
directive|define
name|CLK_GSCL3
value|259
end_define

begin_define
define|#
directive|define
name|CLK_GSCL_WA
value|260
end_define

begin_define
define|#
directive|define
name|CLK_GSCL_WB
value|261
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_GSCL0
value|262
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_GSCL1
value|263
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_GSCL2
value|264
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_GSCL3
value|265
end_define

begin_define
define|#
directive|define
name|CLK_MFC
value|266
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_MFCL
value|267
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_MFCR
value|268
end_define

begin_define
define|#
directive|define
name|CLK_ROTATOR
value|269
end_define

begin_define
define|#
directive|define
name|CLK_JPEG
value|270
end_define

begin_define
define|#
directive|define
name|CLK_MDMA1
value|271
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_ROTATOR
value|272
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_JPEG
value|273
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_MDMA1
value|274
end_define

begin_define
define|#
directive|define
name|CLK_PDMA0
value|275
end_define

begin_define
define|#
directive|define
name|CLK_PDMA1
value|276
end_define

begin_define
define|#
directive|define
name|CLK_SATA
value|277
end_define

begin_define
define|#
directive|define
name|CLK_USBOTG
value|278
end_define

begin_define
define|#
directive|define
name|CLK_MIPI_HSI
value|279
end_define

begin_define
define|#
directive|define
name|CLK_SDMMC0
value|280
end_define

begin_define
define|#
directive|define
name|CLK_SDMMC1
value|281
end_define

begin_define
define|#
directive|define
name|CLK_SDMMC2
value|282
end_define

begin_define
define|#
directive|define
name|CLK_SDMMC3
value|283
end_define

begin_define
define|#
directive|define
name|CLK_SROMC
value|284
end_define

begin_define
define|#
directive|define
name|CLK_USB2
value|285
end_define

begin_define
define|#
directive|define
name|CLK_USB3
value|286
end_define

begin_define
define|#
directive|define
name|CLK_SATA_PHYCTRL
value|287
end_define

begin_define
define|#
directive|define
name|CLK_SATA_PHYI2C
value|288
end_define

begin_define
define|#
directive|define
name|CLK_UART0
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
name|CLK_UART2
value|291
end_define

begin_define
define|#
directive|define
name|CLK_UART3
value|292
end_define

begin_define
define|#
directive|define
name|CLK_UART4
value|293
end_define

begin_define
define|#
directive|define
name|CLK_I2C0
value|294
end_define

begin_define
define|#
directive|define
name|CLK_I2C1
value|295
end_define

begin_define
define|#
directive|define
name|CLK_I2C2
value|296
end_define

begin_define
define|#
directive|define
name|CLK_I2C3
value|297
end_define

begin_define
define|#
directive|define
name|CLK_I2C4
value|298
end_define

begin_define
define|#
directive|define
name|CLK_I2C5
value|299
end_define

begin_define
define|#
directive|define
name|CLK_I2C6
value|300
end_define

begin_define
define|#
directive|define
name|CLK_I2C7
value|301
end_define

begin_define
define|#
directive|define
name|CLK_I2C_HDMI
value|302
end_define

begin_define
define|#
directive|define
name|CLK_ADC
value|303
end_define

begin_define
define|#
directive|define
name|CLK_SPI0
value|304
end_define

begin_define
define|#
directive|define
name|CLK_SPI1
value|305
end_define

begin_define
define|#
directive|define
name|CLK_SPI2
value|306
end_define

begin_define
define|#
directive|define
name|CLK_I2S1
value|307
end_define

begin_define
define|#
directive|define
name|CLK_I2S2
value|308
end_define

begin_define
define|#
directive|define
name|CLK_PCM1
value|309
end_define

begin_define
define|#
directive|define
name|CLK_PCM2
value|310
end_define

begin_define
define|#
directive|define
name|CLK_PWM
value|311
end_define

begin_define
define|#
directive|define
name|CLK_SPDIF
value|312
end_define

begin_define
define|#
directive|define
name|CLK_AC97
value|313
end_define

begin_define
define|#
directive|define
name|CLK_HSI2C0
value|314
end_define

begin_define
define|#
directive|define
name|CLK_HSI2C1
value|315
end_define

begin_define
define|#
directive|define
name|CLK_HSI2C2
value|316
end_define

begin_define
define|#
directive|define
name|CLK_HSI2C3
value|317
end_define

begin_define
define|#
directive|define
name|CLK_CHIPID
value|318
end_define

begin_define
define|#
directive|define
name|CLK_SYSREG
value|319
end_define

begin_define
define|#
directive|define
name|CLK_PMU
value|320
end_define

begin_define
define|#
directive|define
name|CLK_CMU_TOP
value|321
end_define

begin_define
define|#
directive|define
name|CLK_CMU_CORE
value|322
end_define

begin_define
define|#
directive|define
name|CLK_CMU_MEM
value|323
end_define

begin_define
define|#
directive|define
name|CLK_TZPC0
value|324
end_define

begin_define
define|#
directive|define
name|CLK_TZPC1
value|325
end_define

begin_define
define|#
directive|define
name|CLK_TZPC2
value|326
end_define

begin_define
define|#
directive|define
name|CLK_TZPC3
value|327
end_define

begin_define
define|#
directive|define
name|CLK_TZPC4
value|328
end_define

begin_define
define|#
directive|define
name|CLK_TZPC5
value|329
end_define

begin_define
define|#
directive|define
name|CLK_TZPC6
value|330
end_define

begin_define
define|#
directive|define
name|CLK_TZPC7
value|331
end_define

begin_define
define|#
directive|define
name|CLK_TZPC8
value|332
end_define

begin_define
define|#
directive|define
name|CLK_TZPC9
value|333
end_define

begin_define
define|#
directive|define
name|CLK_HDMI_CEC
value|334
end_define

begin_define
define|#
directive|define
name|CLK_MCT
value|335
end_define

begin_define
define|#
directive|define
name|CLK_WDT
value|336
end_define

begin_define
define|#
directive|define
name|CLK_RTC
value|337
end_define

begin_define
define|#
directive|define
name|CLK_TMU
value|338
end_define

begin_define
define|#
directive|define
name|CLK_FIMD1
value|339
end_define

begin_define
define|#
directive|define
name|CLK_MIE1
value|340
end_define

begin_define
define|#
directive|define
name|CLK_DSIM0
value|341
end_define

begin_define
define|#
directive|define
name|CLK_DP
value|342
end_define

begin_define
define|#
directive|define
name|CLK_MIXER
value|343
end_define

begin_define
define|#
directive|define
name|CLK_HDMI
value|344
end_define

begin_define
define|#
directive|define
name|CLK_G2D
value|345
end_define

begin_define
define|#
directive|define
name|CLK_MDMA0
value|346
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_MDMA0
value|347
end_define

begin_define
define|#
directive|define
name|CLK_SSS
value|348
end_define

begin_define
define|#
directive|define
name|CLK_G3D
value|349
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_TV
value|350
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_FIMD1
value|351
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_2D
value|352
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_FIMC_ISP
value|353
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_FIMC_DRC
value|354
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_FIMC_SCC
value|355
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_FIMC_SCP
value|356
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_FIMC_FD
value|357
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_FIMC_MCU
value|358
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_FIMC_ODC
value|359
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_FIMC_DIS0
value|360
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_FIMC_DIS1
value|361
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_FIMC_3DNR
value|362
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_FIMC_LITE0
value|363
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_FIMC_LITE1
value|364
end_define

begin_define
define|#
directive|define
name|CLK_CAMIF_TOP
value|365
end_define

begin_comment
comment|/* mux clocks */
end_comment

begin_define
define|#
directive|define
name|CLK_MOUT_HDMI
value|1024
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_GPLL
value|1025
end_define

begin_comment
comment|/* must be greater than maximal clock id */
end_comment

begin_define
define|#
directive|define
name|CLK_NR_CLKS
value|1026
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_CLOCK_EXYNOS_5250_H */
end_comment

end_unit

