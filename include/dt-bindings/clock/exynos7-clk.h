begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2014 Samsung Electronics Co., Ltd.  * Author: Naveen Krishna Ch<naveenkrishna.ch@gmail.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLOCK_EXYNOS7_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLOCK_EXYNOS7_H
end_define

begin_comment
comment|/* TOPC */
end_comment

begin_define
define|#
directive|define
name|DOUT_ACLK_PERIS
value|1
end_define

begin_define
define|#
directive|define
name|DOUT_SCLK_BUS0_PLL
value|2
end_define

begin_define
define|#
directive|define
name|DOUT_SCLK_BUS1_PLL
value|3
end_define

begin_define
define|#
directive|define
name|DOUT_SCLK_CC_PLL
value|4
end_define

begin_define
define|#
directive|define
name|DOUT_SCLK_MFC_PLL
value|5
end_define

begin_define
define|#
directive|define
name|DOUT_ACLK_CCORE_133
value|6
end_define

begin_define
define|#
directive|define
name|DOUT_ACLK_MSCL_532
value|7
end_define

begin_define
define|#
directive|define
name|ACLK_MSCL_532
value|8
end_define

begin_define
define|#
directive|define
name|DOUT_SCLK_AUD_PLL
value|9
end_define

begin_define
define|#
directive|define
name|FOUT_AUD_PLL
value|10
end_define

begin_define
define|#
directive|define
name|TOPC_NR_CLK
value|11
end_define

begin_comment
comment|/* TOP0 */
end_comment

begin_define
define|#
directive|define
name|DOUT_ACLK_PERIC1
value|1
end_define

begin_define
define|#
directive|define
name|DOUT_ACLK_PERIC0
value|2
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_UART0
value|3
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_UART1
value|4
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_UART2
value|5
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_UART3
value|6
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SPI0
value|7
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SPI1
value|8
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SPI2
value|9
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SPI3
value|10
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SPI4
value|11
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_SPDIF
value|12
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_PCM1
value|13
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_I2S1
value|14
end_define

begin_define
define|#
directive|define
name|TOP0_NR_CLK
value|15
end_define

begin_comment
comment|/* TOP1 */
end_comment

begin_define
define|#
directive|define
name|DOUT_ACLK_FSYS1_200
value|1
end_define

begin_define
define|#
directive|define
name|DOUT_ACLK_FSYS0_200
value|2
end_define

begin_define
define|#
directive|define
name|DOUT_SCLK_MMC2
value|3
end_define

begin_define
define|#
directive|define
name|DOUT_SCLK_MMC1
value|4
end_define

begin_define
define|#
directive|define
name|DOUT_SCLK_MMC0
value|5
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MMC2
value|6
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MMC1
value|7
end_define

begin_define
define|#
directive|define
name|CLK_SCLK_MMC0
value|8
end_define

begin_define
define|#
directive|define
name|TOP1_NR_CLK
value|9
end_define

begin_comment
comment|/* CCORE */
end_comment

begin_define
define|#
directive|define
name|PCLK_RTC
value|1
end_define

begin_define
define|#
directive|define
name|CCORE_NR_CLK
value|2
end_define

begin_comment
comment|/* PERIC0 */
end_comment

begin_define
define|#
directive|define
name|PCLK_UART0
value|1
end_define

begin_define
define|#
directive|define
name|SCLK_UART0
value|2
end_define

begin_define
define|#
directive|define
name|PCLK_HSI2C0
value|3
end_define

begin_define
define|#
directive|define
name|PCLK_HSI2C1
value|4
end_define

begin_define
define|#
directive|define
name|PCLK_HSI2C4
value|5
end_define

begin_define
define|#
directive|define
name|PCLK_HSI2C5
value|6
end_define

begin_define
define|#
directive|define
name|PCLK_HSI2C9
value|7
end_define

begin_define
define|#
directive|define
name|PCLK_HSI2C10
value|8
end_define

begin_define
define|#
directive|define
name|PCLK_HSI2C11
value|9
end_define

begin_define
define|#
directive|define
name|PCLK_PWM
value|10
end_define

begin_define
define|#
directive|define
name|SCLK_PWM
value|11
end_define

begin_define
define|#
directive|define
name|PCLK_ADCIF
value|12
end_define

begin_define
define|#
directive|define
name|PERIC0_NR_CLK
value|13
end_define

begin_comment
comment|/* PERIC1 */
end_comment

begin_define
define|#
directive|define
name|PCLK_UART1
value|1
end_define

begin_define
define|#
directive|define
name|PCLK_UART2
value|2
end_define

begin_define
define|#
directive|define
name|PCLK_UART3
value|3
end_define

begin_define
define|#
directive|define
name|SCLK_UART1
value|4
end_define

begin_define
define|#
directive|define
name|SCLK_UART2
value|5
end_define

begin_define
define|#
directive|define
name|SCLK_UART3
value|6
end_define

begin_define
define|#
directive|define
name|PCLK_HSI2C2
value|7
end_define

begin_define
define|#
directive|define
name|PCLK_HSI2C3
value|8
end_define

begin_define
define|#
directive|define
name|PCLK_HSI2C6
value|9
end_define

begin_define
define|#
directive|define
name|PCLK_HSI2C7
value|10
end_define

begin_define
define|#
directive|define
name|PCLK_HSI2C8
value|11
end_define

begin_define
define|#
directive|define
name|PCLK_SPI0
value|12
end_define

begin_define
define|#
directive|define
name|PCLK_SPI1
value|13
end_define

begin_define
define|#
directive|define
name|PCLK_SPI2
value|14
end_define

begin_define
define|#
directive|define
name|PCLK_SPI3
value|15
end_define

begin_define
define|#
directive|define
name|PCLK_SPI4
value|16
end_define

begin_define
define|#
directive|define
name|SCLK_SPI0
value|17
end_define

begin_define
define|#
directive|define
name|SCLK_SPI1
value|18
end_define

begin_define
define|#
directive|define
name|SCLK_SPI2
value|19
end_define

begin_define
define|#
directive|define
name|SCLK_SPI3
value|20
end_define

begin_define
define|#
directive|define
name|SCLK_SPI4
value|21
end_define

begin_define
define|#
directive|define
name|PCLK_I2S1
value|22
end_define

begin_define
define|#
directive|define
name|PCLK_PCM1
value|23
end_define

begin_define
define|#
directive|define
name|PCLK_SPDIF
value|24
end_define

begin_define
define|#
directive|define
name|SCLK_I2S1
value|25
end_define

begin_define
define|#
directive|define
name|SCLK_PCM1
value|26
end_define

begin_define
define|#
directive|define
name|SCLK_SPDIF
value|27
end_define

begin_define
define|#
directive|define
name|PERIC1_NR_CLK
value|28
end_define

begin_comment
comment|/* PERIS */
end_comment

begin_define
define|#
directive|define
name|PCLK_CHIPID
value|1
end_define

begin_define
define|#
directive|define
name|SCLK_CHIPID
value|2
end_define

begin_define
define|#
directive|define
name|PCLK_WDT
value|3
end_define

begin_define
define|#
directive|define
name|PCLK_TMU
value|4
end_define

begin_define
define|#
directive|define
name|SCLK_TMU
value|5
end_define

begin_define
define|#
directive|define
name|PERIS_NR_CLK
value|6
end_define

begin_comment
comment|/* FSYS0 */
end_comment

begin_define
define|#
directive|define
name|ACLK_MMC2
value|1
end_define

begin_define
define|#
directive|define
name|ACLK_AXIUS_USBDRD30X_FSYS0X
value|2
end_define

begin_define
define|#
directive|define
name|ACLK_USBDRD300
value|3
end_define

begin_define
define|#
directive|define
name|SCLK_USBDRD300_SUSPENDCLK
value|4
end_define

begin_define
define|#
directive|define
name|SCLK_USBDRD300_REFCLK
value|5
end_define

begin_define
define|#
directive|define
name|PHYCLK_USBDRD300_UDRD30_PIPE_PCLK_USER
value|6
end_define

begin_define
define|#
directive|define
name|PHYCLK_USBDRD300_UDRD30_PHYCLK_USER
value|7
end_define

begin_define
define|#
directive|define
name|OSCCLK_PHY_CLKOUT_USB30_PHY
value|8
end_define

begin_define
define|#
directive|define
name|ACLK_PDMA0
value|9
end_define

begin_define
define|#
directive|define
name|ACLK_PDMA1
value|10
end_define

begin_define
define|#
directive|define
name|FSYS0_NR_CLK
value|11
end_define

begin_comment
comment|/* FSYS1 */
end_comment

begin_define
define|#
directive|define
name|ACLK_MMC1
value|1
end_define

begin_define
define|#
directive|define
name|ACLK_MMC0
value|2
end_define

begin_define
define|#
directive|define
name|FSYS1_NR_CLK
value|3
end_define

begin_comment
comment|/* MSCL */
end_comment

begin_define
define|#
directive|define
name|USERMUX_ACLK_MSCL_532
value|1
end_define

begin_define
define|#
directive|define
name|DOUT_PCLK_MSCL
value|2
end_define

begin_define
define|#
directive|define
name|ACLK_MSCL_0
value|3
end_define

begin_define
define|#
directive|define
name|ACLK_MSCL_1
value|4
end_define

begin_define
define|#
directive|define
name|ACLK_JPEG
value|5
end_define

begin_define
define|#
directive|define
name|ACLK_G2D
value|6
end_define

begin_define
define|#
directive|define
name|ACLK_LH_ASYNC_SI_MSCL_0
value|7
end_define

begin_define
define|#
directive|define
name|ACLK_LH_ASYNC_SI_MSCL_1
value|8
end_define

begin_define
define|#
directive|define
name|ACLK_AXI2ACEL_BRIDGE
value|9
end_define

begin_define
define|#
directive|define
name|ACLK_XIU_MSCLX_0
value|10
end_define

begin_define
define|#
directive|define
name|ACLK_XIU_MSCLX_1
value|11
end_define

begin_define
define|#
directive|define
name|ACLK_QE_MSCL_0
value|12
end_define

begin_define
define|#
directive|define
name|ACLK_QE_MSCL_1
value|13
end_define

begin_define
define|#
directive|define
name|ACLK_QE_JPEG
value|14
end_define

begin_define
define|#
directive|define
name|ACLK_QE_G2D
value|15
end_define

begin_define
define|#
directive|define
name|ACLK_PPMU_MSCL_0
value|16
end_define

begin_define
define|#
directive|define
name|ACLK_PPMU_MSCL_1
value|17
end_define

begin_define
define|#
directive|define
name|ACLK_MSCLNP_133
value|18
end_define

begin_define
define|#
directive|define
name|ACLK_AHB2APB_MSCL0P
value|19
end_define

begin_define
define|#
directive|define
name|ACLK_AHB2APB_MSCL1P
value|20
end_define

begin_define
define|#
directive|define
name|PCLK_MSCL_0
value|21
end_define

begin_define
define|#
directive|define
name|PCLK_MSCL_1
value|22
end_define

begin_define
define|#
directive|define
name|PCLK_JPEG
value|23
end_define

begin_define
define|#
directive|define
name|PCLK_G2D
value|24
end_define

begin_define
define|#
directive|define
name|PCLK_QE_MSCL_0
value|25
end_define

begin_define
define|#
directive|define
name|PCLK_QE_MSCL_1
value|26
end_define

begin_define
define|#
directive|define
name|PCLK_QE_JPEG
value|27
end_define

begin_define
define|#
directive|define
name|PCLK_QE_G2D
value|28
end_define

begin_define
define|#
directive|define
name|PCLK_PPMU_MSCL_0
value|29
end_define

begin_define
define|#
directive|define
name|PCLK_PPMU_MSCL_1
value|30
end_define

begin_define
define|#
directive|define
name|PCLK_AXI2ACEL_BRIDGE
value|31
end_define

begin_define
define|#
directive|define
name|PCLK_PMU_MSCL
value|32
end_define

begin_define
define|#
directive|define
name|MSCL_NR_CLK
value|33
end_define

begin_comment
comment|/* AUD */
end_comment

begin_define
define|#
directive|define
name|SCLK_I2S
value|1
end_define

begin_define
define|#
directive|define
name|SCLK_PCM
value|2
end_define

begin_define
define|#
directive|define
name|PCLK_I2S
value|3
end_define

begin_define
define|#
directive|define
name|PCLK_PCM
value|4
end_define

begin_define
define|#
directive|define
name|ACLK_ADMA
value|5
end_define

begin_define
define|#
directive|define
name|AUD_NR_CLK
value|6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_CLOCK_EXYNOS7_H */
end_comment

end_unit

