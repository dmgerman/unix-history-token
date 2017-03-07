begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2014 Samsung Electronics Co., Ltd.  * Copyright (c) 2016 Krzysztof Kozlowski  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Device Tree binding constants for Exynos5421 clock controller. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLOCK_EXYNOS_5410_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLOCK_EXYNOS_5410_H
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
name|CLK_FOUT_MPLL
value|4
end_define

begin_define
define|#
directive|define
name|CLK_FOUT_BPLL
value|5
end_define

begin_define
define|#
directive|define
name|CLK_FOUT_KPLL
value|6
end_define

begin_define
define|#
directive|define
name|CLK_FOUT_EPLL
value|7
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
name|CLK_SCLK_PWM
value|155
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
name|CLK_UART3
value|260
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
name|CLK_SSS
value|471
end_define

begin_define
define|#
directive|define
name|CLK_NR_CLKS
value|512
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_CLOCK_EXYNOS_5410_H */
end_comment

end_unit

