begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2014 Alexander Shiyan<shc_work@mail.ru>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_CLOCK_IMX21_H
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_CLOCK_IMX21_H
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_DUMMY
value|0
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_CKIL
value|1
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_CKIH
value|2
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_FPM
value|3
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_CKIH_DIV1P5
value|4
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_MPLL_GATE
value|5
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_SPLL_GATE
value|6
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_FPM_GATE
value|7
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_CKIH_GATE
value|8
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_MPLL_OSC_SEL
value|9
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_IPG
value|10
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_HCLK
value|11
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_MPLL_SEL
value|12
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_SPLL_SEL
value|13
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_SSI1_SEL
value|14
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_SSI2_SEL
value|15
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_USB_DIV
value|16
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_FCLK
value|17
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_MPLL
value|18
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_SPLL
value|19
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_NFC_DIV
value|20
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_SSI1_DIV
value|21
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_SSI2_DIV
value|22
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_PER1
value|23
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_PER2
value|24
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_PER3
value|25
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_PER4
value|26
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_UART1_IPG_GATE
value|27
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_UART2_IPG_GATE
value|28
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_UART3_IPG_GATE
value|29
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_UART4_IPG_GATE
value|30
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_CSPI1_IPG_GATE
value|31
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_CSPI2_IPG_GATE
value|32
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_SSI1_GATE
value|33
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_SSI2_GATE
value|34
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_SDHC1_IPG_GATE
value|35
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_SDHC2_IPG_GATE
value|36
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_GPIO_GATE
value|37
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_I2C_GATE
value|38
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_DMA_GATE
value|39
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_USB_GATE
value|40
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_EMMA_GATE
value|41
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_SSI2_BAUD_GATE
value|42
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_SSI1_BAUD_GATE
value|43
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_LCDC_IPG_GATE
value|44
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_NFC_GATE
value|45
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_LCDC_HCLK_GATE
value|46
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_PER4_GATE
value|47
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_BMI_GATE
value|48
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_USB_HCLK_GATE
value|49
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_SLCDC_GATE
value|50
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_SLCDC_HCLK_GATE
value|51
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_EMMA_HCLK_GATE
value|52
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_BROM_GATE
value|53
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_DMA_HCLK_GATE
value|54
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_CSI_HCLK_GATE
value|55
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_CSPI3_IPG_GATE
value|56
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_WDOG_GATE
value|57
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_GPT1_IPG_GATE
value|58
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_GPT2_IPG_GATE
value|59
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_GPT3_IPG_GATE
value|60
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_PWM_IPG_GATE
value|61
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_RTC_GATE
value|62
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_KPP_GATE
value|63
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_OWIRE_GATE
value|64
end_define

begin_define
define|#
directive|define
name|IMX21_CLK_MAX
value|65
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

