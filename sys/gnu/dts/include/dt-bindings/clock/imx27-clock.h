begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2014 Alexander Shiyan<shc_work@mail.ru>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_CLOCK_IMX27_H
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_CLOCK_IMX27_H
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_DUMMY
value|0
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_CKIH
value|1
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_CKIL
value|2
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_MPLL
value|3
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_SPLL
value|4
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_MPLL_MAIN2
value|5
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_AHB
value|6
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_IPG
value|7
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_NFC_DIV
value|8
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_PER1_DIV
value|9
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_PER2_DIV
value|10
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_PER3_DIV
value|11
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_PER4_DIV
value|12
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_VPU_SEL
value|13
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_VPU_DIV
value|14
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_USB_DIV
value|15
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_CPU_SEL
value|16
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_CLKO_SEL
value|17
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_CPU_DIV
value|18
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_CLKO_DIV
value|19
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_SSI1_SEL
value|20
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_SSI2_SEL
value|21
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_SSI1_DIV
value|22
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_SSI2_DIV
value|23
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_CLKO_EN
value|24
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_SSI2_IPG_GATE
value|25
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_SSI1_IPG_GATE
value|26
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_SLCDC_IPG_GATE
value|27
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_SDHC3_IPG_GATE
value|28
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_SDHC2_IPG_GATE
value|29
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_SDHC1_IPG_GATE
value|30
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_SCC_IPG_GATE
value|31
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_SAHARA_IPG_GATE
value|32
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_RTC_IPG_GATE
value|33
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_PWM_IPG_GATE
value|34
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_OWIRE_IPG_GATE
value|35
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_LCDC_IPG_GATE
value|36
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_KPP_IPG_GATE
value|37
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_IIM_IPG_GATE
value|38
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_I2C2_IPG_GATE
value|39
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_I2C1_IPG_GATE
value|40
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_GPT6_IPG_GATE
value|41
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_GPT5_IPG_GATE
value|42
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_GPT4_IPG_GATE
value|43
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_GPT3_IPG_GATE
value|44
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_GPT2_IPG_GATE
value|45
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_GPT1_IPG_GATE
value|46
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_GPIO_IPG_GATE
value|47
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_FEC_IPG_GATE
value|48
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_EMMA_IPG_GATE
value|49
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_DMA_IPG_GATE
value|50
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_CSPI3_IPG_GATE
value|51
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_CSPI2_IPG_GATE
value|52
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_CSPI1_IPG_GATE
value|53
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_NFC_BAUD_GATE
value|54
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_SSI2_BAUD_GATE
value|55
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_SSI1_BAUD_GATE
value|56
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_VPU_BAUD_GATE
value|57
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_PER4_GATE
value|58
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_PER3_GATE
value|59
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_PER2_GATE
value|60
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_PER1_GATE
value|61
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_USB_AHB_GATE
value|62
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_SLCDC_AHB_GATE
value|63
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_SAHARA_AHB_GATE
value|64
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_LCDC_AHB_GATE
value|65
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_VPU_AHB_GATE
value|66
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_FEC_AHB_GATE
value|67
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_EMMA_AHB_GATE
value|68
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_EMI_AHB_GATE
value|69
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_DMA_AHB_GATE
value|70
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_CSI_AHB_GATE
value|71
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_BROM_AHB_GATE
value|72
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_ATA_AHB_GATE
value|73
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_WDOG_IPG_GATE
value|74
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_USB_IPG_GATE
value|75
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_UART6_IPG_GATE
value|76
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_UART5_IPG_GATE
value|77
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_UART4_IPG_GATE
value|78
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_UART3_IPG_GATE
value|79
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_UART2_IPG_GATE
value|80
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_UART1_IPG_GATE
value|81
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_CKIH_DIV1P5
value|82
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_FPM
value|83
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_MPLL_OSC_SEL
value|84
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_MPLL_SEL
value|85
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_SPLL_GATE
value|86
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_MSHC_DIV
value|87
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_RTIC_IPG_GATE
value|88
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_MSHC_IPG_GATE
value|89
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_RTIC_AHB_GATE
value|90
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_MSHC_BAUD_GATE
value|91
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_CKIH_GATE
value|92
end_define

begin_define
define|#
directive|define
name|IMX27_CLK_MAX
value|93
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

