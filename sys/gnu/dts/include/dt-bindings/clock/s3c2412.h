begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013 Heiko Stuebner<heiko@sntech.de>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Device Tree binding constants clock controllers of Samsung S3C2412.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLOCK_SAMSUNG_S3C2412_CLOCK_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLOCK_SAMSUNG_S3C2412_CLOCK_H
end_define

begin_comment
comment|/*  * Let each exported clock get a unique index, which is used on DT-enabled  * platforms to lookup the clock from a clock specifier. These indices are  * therefore considered an ABI and so must not be changed. This implies  * that new clocks should be added either in free spaces between clock groups  * or at the end.  */
end_comment

begin_comment
comment|/* Core clocks. */
end_comment

begin_comment
comment|/* id 1 is reserved */
end_comment

begin_define
define|#
directive|define
name|MPLL
value|2
end_define

begin_define
define|#
directive|define
name|UPLL
value|3
end_define

begin_define
define|#
directive|define
name|MDIVCLK
value|4
end_define

begin_define
define|#
directive|define
name|MSYSCLK
value|5
end_define

begin_define
define|#
directive|define
name|USYSCLK
value|6
end_define

begin_define
define|#
directive|define
name|HCLK
value|7
end_define

begin_define
define|#
directive|define
name|PCLK
value|8
end_define

begin_define
define|#
directive|define
name|ARMDIV
value|9
end_define

begin_define
define|#
directive|define
name|ARMCLK
value|10
end_define

begin_comment
comment|/* Special clocks */
end_comment

begin_define
define|#
directive|define
name|SCLK_CAM
value|16
end_define

begin_define
define|#
directive|define
name|SCLK_UART
value|17
end_define

begin_define
define|#
directive|define
name|SCLK_I2S
value|18
end_define

begin_define
define|#
directive|define
name|SCLK_USBD
value|19
end_define

begin_define
define|#
directive|define
name|SCLK_USBH
value|20
end_define

begin_comment
comment|/* pclk-gates */
end_comment

begin_define
define|#
directive|define
name|PCLK_WDT
value|32
end_define

begin_define
define|#
directive|define
name|PCLK_SPI
value|33
end_define

begin_define
define|#
directive|define
name|PCLK_I2S
value|34
end_define

begin_define
define|#
directive|define
name|PCLK_I2C
value|35
end_define

begin_define
define|#
directive|define
name|PCLK_ADC
value|36
end_define

begin_define
define|#
directive|define
name|PCLK_RTC
value|37
end_define

begin_define
define|#
directive|define
name|PCLK_GPIO
value|38
end_define

begin_define
define|#
directive|define
name|PCLK_UART2
value|39
end_define

begin_define
define|#
directive|define
name|PCLK_UART1
value|40
end_define

begin_define
define|#
directive|define
name|PCLK_UART0
value|41
end_define

begin_define
define|#
directive|define
name|PCLK_SDI
value|42
end_define

begin_define
define|#
directive|define
name|PCLK_PWM
value|43
end_define

begin_define
define|#
directive|define
name|PCLK_USBD
value|44
end_define

begin_comment
comment|/* hclk-gates */
end_comment

begin_define
define|#
directive|define
name|HCLK_HALF
value|48
end_define

begin_define
define|#
directive|define
name|HCLK_X2
value|49
end_define

begin_define
define|#
directive|define
name|HCLK_SDRAM
value|50
end_define

begin_define
define|#
directive|define
name|HCLK_USBH
value|51
end_define

begin_define
define|#
directive|define
name|HCLK_LCD
value|52
end_define

begin_define
define|#
directive|define
name|HCLK_NAND
value|53
end_define

begin_define
define|#
directive|define
name|HCLK_DMA3
value|54
end_define

begin_define
define|#
directive|define
name|HCLK_DMA2
value|55
end_define

begin_define
define|#
directive|define
name|HCLK_DMA1
value|56
end_define

begin_define
define|#
directive|define
name|HCLK_DMA0
value|57
end_define

begin_comment
comment|/* Total number of clocks. */
end_comment

begin_define
define|#
directive|define
name|NR_CLKS
value|(HCLK_DMA0 + 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_CLOCK_SAMSUNG_S3C2412_CLOCK_H */
end_comment

end_unit

