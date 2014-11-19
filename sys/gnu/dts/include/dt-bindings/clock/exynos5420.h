begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013 Samsung Electronics Co., Ltd.  * Author: Andrzej Hajda<a.hajda@samsung.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Device Tree binding constants for Exynos5420 clock controller. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLOCK_EXYNOS_5420_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLOCK_EXYNOS_5420_H
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
name|CLK_FOUT_CPLL
value|3
end_define

begin_define
define|#
directive|define
name|CLK_FOUT_DPLL
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
name|CLK_FOUT_RPLL
value|6
end_define

begin_define
define|#
directive|define
name|CLK_FOUT_IPLL
value|7
end_define

begin_define
define|#
directive|define
name|CLK_FOUT_SPLL
value|8
end_define

begin_define
define|#
directive|define
name|CLK_FOUT_VPLL
value|9
end_define

begin_define
define|#
directive|define
name|CLK_FOUT_MPLL
value|10
end_define

begin_define
define|#
directive|define
name|CLK_FOUT_BPLL
value|11
end_define

begin_define
define|#
directive|define
name|CLK_FOUT_KPLL
value|12
end_define

begin_comment
comment|/* gate for special clocks (sclk) */
end_comment

begin_define
define|#
directive|define
name|CLK_SCLK_UART0
value|128
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_UART1
value|129
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_UART2
value|130
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_UART3
value|131
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MMC0
value|132
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MMC1
value|133
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MMC2
value|134
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SPI0
value|135
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SPI1
value|136
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SPI2
value|137
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_I2S1
value|138
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_I2S2
value|139
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_PCM1
value|140
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_PCM2
value|141
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SPDIF
value|142
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_HDMI
value|143
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_PIXEL
value|144
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_DP1
value|145
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MIPI1
value|146
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_FIMD1
value|147
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MAUDIO0
value|148
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MAUPCM0
value|149
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_USBD300
value|150
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_USBD301
value|151
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_USBPHY300
value|152
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_USBPHY301
value|153
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_UNIPRO
value|154
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_PWM
value|155
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_GSCL_WA
value|156
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_GSCL_WB
value|157
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_HDMIPHY
value|158
end_define

begin_define
define|#
directive|define
name|CLK_MAU_EPLL
value|159
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_HSIC_12M
value|160
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MPHY_IXTAL24
value|161
end_define

begin_comment
comment|/* gate clocks */
end_comment

begin_define
define|#
directive|define
name|CLK_UART0
value|257
end_define

begin_define
define|#
directive|define
name|CLK_UART1
value|258
end_define

begin_define
define|#
directive|define
name|CLK_UART2
value|259
end_define

begin_define
define|#
directive|define
name|CLK_UART3
value|260
end_define

begin_define
define|#
directive|define
name|CLK_I2C0
value|261
end_define

begin_define
define|#
directive|define
name|CLK_I2C1
value|262
end_define

begin_define
define|#
directive|define
name|CLK_I2C2
value|263
end_define

begin_define
define|#
directive|define
name|CLK_I2C3
value|264
end_define

begin_define
define|#
directive|define
name|CLK_USI0
value|265
end_define

begin_define
define|#
directive|define
name|CLK_USI1
value|266
end_define

begin_define
define|#
directive|define
name|CLK_USI2
value|267
end_define

begin_define
define|#
directive|define
name|CLK_USI3
value|268
end_define

begin_define
define|#
directive|define
name|CLK_I2C_HDMI
value|269
end_define

begin_define
define|#
directive|define
name|CLK_TSADC
value|270
end_define

begin_define
define|#
directive|define
name|CLK_SPI0
value|271
end_define

begin_define
define|#
directive|define
name|CLK_SPI1
value|272
end_define

begin_define
define|#
directive|define
name|CLK_SPI2
value|273
end_define

begin_define
define|#
directive|define
name|CLK_KEYIF
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
name|CLK_I2S2
value|276
end_define

begin_define
define|#
directive|define
name|CLK_PCM1
value|277
end_define

begin_define
define|#
directive|define
name|CLK_PCM2
value|278
end_define

begin_define
define|#
directive|define
name|CLK_PWM
value|279
end_define

begin_define
define|#
directive|define
name|CLK_SPDIF
value|280
end_define

begin_define
define|#
directive|define
name|CLK_USI4
value|281
end_define

begin_define
define|#
directive|define
name|CLK_USI5
value|282
end_define

begin_define
define|#
directive|define
name|CLK_USI6
value|283
end_define

begin_define
define|#
directive|define
name|CLK_ACLK66_PSGEN
value|300
end_define

begin_define
define|#
directive|define
name|CLK_CHIPID
value|301
end_define

begin_define
define|#
directive|define
name|CLK_SYSREG
value|302
end_define

begin_define
define|#
directive|define
name|CLK_TZPC0
value|303
end_define

begin_define
define|#
directive|define
name|CLK_TZPC1
value|304
end_define

begin_define
define|#
directive|define
name|CLK_TZPC2
value|305
end_define

begin_define
define|#
directive|define
name|CLK_TZPC3
value|306
end_define

begin_define
define|#
directive|define
name|CLK_TZPC4
value|307
end_define

begin_define
define|#
directive|define
name|CLK_TZPC5
value|308
end_define

begin_define
define|#
directive|define
name|CLK_TZPC6
value|309
end_define

begin_define
define|#
directive|define
name|CLK_TZPC7
value|310
end_define

begin_define
define|#
directive|define
name|CLK_TZPC8
value|311
end_define

begin_define
define|#
directive|define
name|CLK_TZPC9
value|312
end_define

begin_define
define|#
directive|define
name|CLK_HDMI_CEC
value|313
end_define

begin_define
define|#
directive|define
name|CLK_SECKEY
value|314
end_define

begin_define
define|#
directive|define
name|CLK_MCT
value|315
end_define

begin_define
define|#
directive|define
name|CLK_WDT
value|316
end_define

begin_define
define|#
directive|define
name|CLK_RTC
value|317
end_define

begin_define
define|#
directive|define
name|CLK_TMU
value|318
end_define

begin_define
define|#
directive|define
name|CLK_TMU_GPU
value|319
end_define

begin_define
define|#
directive|define
name|CLK_PCLK66_GPIO
value|330
end_define

begin_define
define|#
directive|define
name|CLK_ACLK200_FSYS2
value|350
end_define

begin_define
define|#
directive|define
name|CLK_MMC0
value|351
end_define

begin_define
define|#
directive|define
name|CLK_MMC1
value|352
end_define

begin_define
define|#
directive|define
name|CLK_MMC2
value|353
end_define

begin_define
define|#
directive|define
name|CLK_SROMC
value|354
end_define

begin_define
define|#
directive|define
name|CLK_UFS
value|355
end_define

begin_define
define|#
directive|define
name|CLK_ACLK200_FSYS
value|360
end_define

begin_define
define|#
directive|define
name|CLK_TSI
value|361
end_define

begin_define
define|#
directive|define
name|CLK_PDMA0
value|362
end_define

begin_define
define|#
directive|define
name|CLK_PDMA1
value|363
end_define

begin_define
define|#
directive|define
name|CLK_RTIC
value|364
end_define

begin_define
define|#
directive|define
name|CLK_USBH20
value|365
end_define

begin_define
define|#
directive|define
name|CLK_USBD300
value|366
end_define

begin_define
define|#
directive|define
name|CLK_USBD301
value|367
end_define

begin_define
define|#
directive|define
name|CLK_ACLK400_MSCL
value|380
end_define

begin_define
define|#
directive|define
name|CLK_MSCL0
value|381
end_define

begin_define
define|#
directive|define
name|CLK_MSCL1
value|382
end_define

begin_define
define|#
directive|define
name|CLK_MSCL2
value|383
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_MSCL0
value|384
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_MSCL1
value|385
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_MSCL2
value|386
end_define

begin_define
define|#
directive|define
name|CLK_ACLK333
value|400
end_define

begin_define
define|#
directive|define
name|CLK_MFC
value|401
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_MFCL
value|402
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_MFCR
value|403
end_define

begin_define
define|#
directive|define
name|CLK_ACLK200_DISP1
value|410
end_define

begin_define
define|#
directive|define
name|CLK_DSIM1
value|411
end_define

begin_define
define|#
directive|define
name|CLK_DP1
value|412
end_define

begin_define
define|#
directive|define
name|CLK_HDMI
value|413
end_define

begin_define
define|#
directive|define
name|CLK_ACLK300_DISP1
value|420
end_define

begin_define
define|#
directive|define
name|CLK_FIMD1
value|421
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_FIMD1M0
value|422
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_FIMD1M1
value|423
end_define

begin_define
define|#
directive|define
name|CLK_ACLK166
value|430
end_define

begin_define
define|#
directive|define
name|CLK_MIXER
value|431
end_define

begin_define
define|#
directive|define
name|CLK_ACLK266
value|440
end_define

begin_define
define|#
directive|define
name|CLK_ROTATOR
value|441
end_define

begin_define
define|#
directive|define
name|CLK_MDMA1
value|442
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_ROTATOR
value|443
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_MDMA1
value|444
end_define

begin_define
define|#
directive|define
name|CLK_ACLK300_JPEG
value|450
end_define

begin_define
define|#
directive|define
name|CLK_JPEG
value|451
end_define

begin_define
define|#
directive|define
name|CLK_JPEG2
value|452
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_JPEG
value|453
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_JPEG2
value|454
end_define

begin_define
define|#
directive|define
name|CLK_ACLK300_GSCL
value|460
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_GSCL0
value|461
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_GSCL1
value|462
end_define

begin_define
define|#
directive|define
name|CLK_GSCL_WA
value|463
end_define

begin_define
define|#
directive|define
name|CLK_GSCL_WB
value|464
end_define

begin_define
define|#
directive|define
name|CLK_GSCL0
value|465
end_define

begin_define
define|#
directive|define
name|CLK_GSCL1
value|466
end_define

begin_define
define|#
directive|define
name|CLK_FIMC_3AA
value|467
end_define

begin_define
define|#
directive|define
name|CLK_ACLK266_G2D
value|470
end_define

begin_define
define|#
directive|define
name|CLK_SSS
value|471
end_define

begin_define
define|#
directive|define
name|CLK_SLIM_SSS
value|472
end_define

begin_define
define|#
directive|define
name|CLK_MDMA0
value|473
end_define

begin_define
define|#
directive|define
name|CLK_ACLK333_G2D
value|480
end_define

begin_define
define|#
directive|define
name|CLK_G2D
value|481
end_define

begin_define
define|#
directive|define
name|CLK_ACLK333_432_GSCL
value|490
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_3AA
value|491
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_FIMCL0
value|492
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_FIMCL1
value|493
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_FIMCL3
value|494
end_define

begin_define
define|#
directive|define
name|CLK_FIMC_LITE3
value|495
end_define

begin_define
define|#
directive|define
name|CLK_FIMC_LITE0
value|496
end_define

begin_define
define|#
directive|define
name|CLK_FIMC_LITE1
value|497
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_G3D
value|500
end_define

begin_define
define|#
directive|define
name|CLK_G3D
value|501
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_MIXER
value|502
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_G2D
value|503
end_define

begin_define
define|#
directive|define
name|CLK_SMMU_MDMA0
value|504
end_define

begin_define
define|#
directive|define
name|CLK_MC
value|505
end_define

begin_define
define|#
directive|define
name|CLK_TOP_RTC
value|506
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_UART_ISP
value|510
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SPI0_ISP
value|511
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SPI1_ISP
value|512
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_PWM_ISP
value|513
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_ISP_SENSOR0
value|514
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_ISP_SENSOR1
value|515
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_ISP_SENSOR2
value|516
end_define

begin_define
define|#
directive|define
name|CLK_ACLK432_SCALER
value|517
end_define

begin_define
define|#
directive|define
name|CLK_ACLK432_CAM
value|518
end_define

begin_define
define|#
directive|define
name|CLK_ACLK_FL1550_CAM
value|519
end_define

begin_define
define|#
directive|define
name|CLK_ACLK550_CAM
value|520
end_define

begin_comment
comment|/* mux clocks */
end_comment

begin_define
define|#
directive|define
name|CLK_MOUT_HDMI
value|640
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_G3D
value|641
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_VPLL
value|642
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_MAUDIO0
value|643
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_USER_ACLK333
value|644
end_define

begin_define
define|#
directive|define
name|CLK_MOUT_SW_ACLK333
value|645
end_define

begin_comment
comment|/* divider clocks */
end_comment

begin_define
define|#
directive|define
name|CLK_DOUT_PIXEL
value|768
end_define

begin_comment
comment|/* must be greater than maximal clock id */
end_comment

begin_define
define|#
directive|define
name|CLK_NR_CLKS
value|769
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_CLOCK_EXYNOS_5420_H */
end_comment

end_unit

