begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013 Heiko Stuebner<heiko@sntech.de>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Device Tree binding constants clock controllers of Samsung S3C2443 and later.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLOCK_SAMSUNG_S3C2443_CLOCK_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLOCK_SAMSUNG_S3C2443_CLOCK_H
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
name|MSYSCLK
value|1
end_define

begin_define
define|#
directive|define
name|ESYSCLK
value|2
end_define

begin_define
define|#
directive|define
name|ARMDIV
value|3
end_define

begin_define
define|#
directive|define
name|ARMCLK
value|4
end_define

begin_define
define|#
directive|define
name|HCLK
value|5
end_define

begin_define
define|#
directive|define
name|PCLK
value|6
end_define

begin_comment
comment|/* Special clocks */
end_comment

begin_define
define|#
directive|define
name|SCLK_HSSPI0
value|16
end_define

begin_define
define|#
directive|define
name|SCLK_FIMD
value|17
end_define

begin_define
define|#
directive|define
name|SCLK_I2S0
value|18
end_define

begin_define
define|#
directive|define
name|SCLK_I2S1
value|19
end_define

begin_define
define|#
directive|define
name|SCLK_HSMMC1
value|20
end_define

begin_define
define|#
directive|define
name|SCLK_HSMMC_EXT
value|21
end_define

begin_define
define|#
directive|define
name|SCLK_CAM
value|22
end_define

begin_define
define|#
directive|define
name|SCLK_UART
value|23
end_define

begin_define
define|#
directive|define
name|SCLK_USBH
value|24
end_define

begin_comment
comment|/* Muxes */
end_comment

begin_define
define|#
directive|define
name|MUX_HSSPI0
value|32
end_define

begin_define
define|#
directive|define
name|MUX_HSSPI1
value|33
end_define

begin_define
define|#
directive|define
name|MUX_HSMMC0
value|34
end_define

begin_define
define|#
directive|define
name|MUX_HSMMC1
value|35
end_define

begin_comment
comment|/* hclk-gates */
end_comment

begin_define
define|#
directive|define
name|HCLK_DMA0
value|48
end_define

begin_define
define|#
directive|define
name|HCLK_DMA1
value|49
end_define

begin_define
define|#
directive|define
name|HCLK_DMA2
value|50
end_define

begin_define
define|#
directive|define
name|HCLK_DMA3
value|51
end_define

begin_define
define|#
directive|define
name|HCLK_DMA4
value|52
end_define

begin_define
define|#
directive|define
name|HCLK_DMA5
value|53
end_define

begin_define
define|#
directive|define
name|HCLK_DMA6
value|54
end_define

begin_define
define|#
directive|define
name|HCLK_DMA7
value|55
end_define

begin_define
define|#
directive|define
name|HCLK_CAM
value|56
end_define

begin_define
define|#
directive|define
name|HCLK_LCD
value|57
end_define

begin_define
define|#
directive|define
name|HCLK_USBH
value|58
end_define

begin_define
define|#
directive|define
name|HCLK_USBD
value|59
end_define

begin_define
define|#
directive|define
name|HCLK_IROM
value|60
end_define

begin_define
define|#
directive|define
name|HCLK_HSMMC0
value|61
end_define

begin_define
define|#
directive|define
name|HCLK_HSMMC1
value|62
end_define

begin_define
define|#
directive|define
name|HCLK_CFC
value|63
end_define

begin_define
define|#
directive|define
name|HCLK_SSMC
value|64
end_define

begin_define
define|#
directive|define
name|HCLK_DRAM
value|65
end_define

begin_define
define|#
directive|define
name|HCLK_2D
value|66
end_define

begin_comment
comment|/* pclk-gates */
end_comment

begin_define
define|#
directive|define
name|PCLK_UART0
value|72
end_define

begin_define
define|#
directive|define
name|PCLK_UART1
value|73
end_define

begin_define
define|#
directive|define
name|PCLK_UART2
value|74
end_define

begin_define
define|#
directive|define
name|PCLK_UART3
value|75
end_define

begin_define
define|#
directive|define
name|PCLK_I2C0
value|76
end_define

begin_define
define|#
directive|define
name|PCLK_SDI
value|77
end_define

begin_define
define|#
directive|define
name|PCLK_SPI0
value|78
end_define

begin_define
define|#
directive|define
name|PCLK_ADC
value|79
end_define

begin_define
define|#
directive|define
name|PCLK_AC97
value|80
end_define

begin_define
define|#
directive|define
name|PCLK_I2S0
value|81
end_define

begin_define
define|#
directive|define
name|PCLK_PWM
value|82
end_define

begin_define
define|#
directive|define
name|PCLK_WDT
value|83
end_define

begin_define
define|#
directive|define
name|PCLK_RTC
value|84
end_define

begin_define
define|#
directive|define
name|PCLK_GPIO
value|85
end_define

begin_define
define|#
directive|define
name|PCLK_SPI1
value|86
end_define

begin_define
define|#
directive|define
name|PCLK_CHIPID
value|87
end_define

begin_define
define|#
directive|define
name|PCLK_I2C1
value|88
end_define

begin_define
define|#
directive|define
name|PCLK_I2S1
value|89
end_define

begin_define
define|#
directive|define
name|PCLK_PCM
value|90
end_define

begin_comment
comment|/* Total number of clocks. */
end_comment

begin_define
define|#
directive|define
name|NR_CLKS
value|(PCLK_PCM + 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_CLOCK_SAMSUNG_S3C2443_CLOCK_H */
end_comment

end_unit

