begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013 Samsung Electronics Co., Ltd.  * Author: Andrzej Hajda<a.hajda@samsung.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Device Tree binding constants for Exynos5440 clock controller. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLOCK_EXYNOS_5440_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLOCK_EXYNOS_5440_H
end_define

begin_define
define|#
directive|define
name|CLK_XTAL
value|1
end_define

begin_define
define|#
directive|define
name|CLK_ARM_CLK
value|2
end_define

begin_define
define|#
directive|define
name|CLK_SPI_BAUD
value|16
end_define

begin_define
define|#
directive|define
name|CLK_PB0_250
value|17
end_define

begin_define
define|#
directive|define
name|CLK_PR0_250
value|18
end_define

begin_define
define|#
directive|define
name|CLK_PR1_250
value|19
end_define

begin_define
define|#
directive|define
name|CLK_B_250
value|20
end_define

begin_define
define|#
directive|define
name|CLK_B_125
value|21
end_define

begin_define
define|#
directive|define
name|CLK_B_200
value|22
end_define

begin_define
define|#
directive|define
name|CLK_SATA
value|23
end_define

begin_define
define|#
directive|define
name|CLK_USB
value|24
end_define

begin_define
define|#
directive|define
name|CLK_GMAC0
value|25
end_define

begin_define
define|#
directive|define
name|CLK_CS250
value|26
end_define

begin_define
define|#
directive|define
name|CLK_PB0_250_O
value|27
end_define

begin_define
define|#
directive|define
name|CLK_PR0_250_O
value|28
end_define

begin_define
define|#
directive|define
name|CLK_PR1_250_O
value|29
end_define

begin_define
define|#
directive|define
name|CLK_B_250_O
value|30
end_define

begin_define
define|#
directive|define
name|CLK_B_125_O
value|31
end_define

begin_define
define|#
directive|define
name|CLK_B_200_O
value|32
end_define

begin_define
define|#
directive|define
name|CLK_SATA_O
value|33
end_define

begin_define
define|#
directive|define
name|CLK_USB_O
value|34
end_define

begin_define
define|#
directive|define
name|CLK_GMAC0_O
value|35
end_define

begin_define
define|#
directive|define
name|CLK_CS250_O
value|36
end_define

begin_comment
comment|/* must be greater than maximal clock id */
end_comment

begin_define
define|#
directive|define
name|CLK_NR_CLKS
value|37
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_CLOCK_EXYNOS_5440_H */
end_comment

end_unit

