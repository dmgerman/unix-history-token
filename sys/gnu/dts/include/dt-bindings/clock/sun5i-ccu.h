begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2016 Maxime Ripard  *  * Maxime Ripard<maxime.ripard@free-electrons.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLK_SUN5I_H_
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLK_SUN5I_H_
end_define

begin_define
define|#
directive|define
name|CLK_HOSC
value|1
end_define

begin_define
define|#
directive|define
name|CLK_CPU
value|17
end_define

begin_define
define|#
directive|define
name|CLK_AHB_OTG
value|23
end_define

begin_define
define|#
directive|define
name|CLK_AHB_EHCI
value|24
end_define

begin_define
define|#
directive|define
name|CLK_AHB_OHCI
value|25
end_define

begin_define
define|#
directive|define
name|CLK_AHB_SS
value|26
end_define

begin_define
define|#
directive|define
name|CLK_AHB_DMA
value|27
end_define

begin_define
define|#
directive|define
name|CLK_AHB_BIST
value|28
end_define

begin_define
define|#
directive|define
name|CLK_AHB_MMC0
value|29
end_define

begin_define
define|#
directive|define
name|CLK_AHB_MMC1
value|30
end_define

begin_define
define|#
directive|define
name|CLK_AHB_MMC2
value|31
end_define

begin_define
define|#
directive|define
name|CLK_AHB_NAND
value|32
end_define

begin_define
define|#
directive|define
name|CLK_AHB_SDRAM
value|33
end_define

begin_define
define|#
directive|define
name|CLK_AHB_EMAC
value|34
end_define

begin_define
define|#
directive|define
name|CLK_AHB_TS
value|35
end_define

begin_define
define|#
directive|define
name|CLK_AHB_SPI0
value|36
end_define

begin_define
define|#
directive|define
name|CLK_AHB_SPI1
value|37
end_define

begin_define
define|#
directive|define
name|CLK_AHB_SPI2
value|38
end_define

begin_define
define|#
directive|define
name|CLK_AHB_GPS
value|39
end_define

begin_define
define|#
directive|define
name|CLK_AHB_HSTIMER
value|40
end_define

begin_define
define|#
directive|define
name|CLK_AHB_VE
value|41
end_define

begin_define
define|#
directive|define
name|CLK_AHB_TVE
value|42
end_define

begin_define
define|#
directive|define
name|CLK_AHB_LCD
value|43
end_define

begin_define
define|#
directive|define
name|CLK_AHB_CSI
value|44
end_define

begin_define
define|#
directive|define
name|CLK_AHB_HDMI
value|45
end_define

begin_define
define|#
directive|define
name|CLK_AHB_DE_BE
value|46
end_define

begin_define
define|#
directive|define
name|CLK_AHB_DE_FE
value|47
end_define

begin_define
define|#
directive|define
name|CLK_AHB_IEP
value|48
end_define

begin_define
define|#
directive|define
name|CLK_AHB_GPU
value|49
end_define

begin_define
define|#
directive|define
name|CLK_APB0_CODEC
value|50
end_define

begin_define
define|#
directive|define
name|CLK_APB0_SPDIF
value|51
end_define

begin_define
define|#
directive|define
name|CLK_APB0_I2S
value|52
end_define

begin_define
define|#
directive|define
name|CLK_APB0_PIO
value|53
end_define

begin_define
define|#
directive|define
name|CLK_APB0_IR
value|54
end_define

begin_define
define|#
directive|define
name|CLK_APB0_KEYPAD
value|55
end_define

begin_define
define|#
directive|define
name|CLK_APB1_I2C0
value|56
end_define

begin_define
define|#
directive|define
name|CLK_APB1_I2C1
value|57
end_define

begin_define
define|#
directive|define
name|CLK_APB1_I2C2
value|58
end_define

begin_define
define|#
directive|define
name|CLK_APB1_UART0
value|59
end_define

begin_define
define|#
directive|define
name|CLK_APB1_UART1
value|60
end_define

begin_define
define|#
directive|define
name|CLK_APB1_UART2
value|61
end_define

begin_define
define|#
directive|define
name|CLK_APB1_UART3
value|62
end_define

begin_define
define|#
directive|define
name|CLK_NAND
value|63
end_define

begin_define
define|#
directive|define
name|CLK_MMC0
value|64
end_define

begin_define
define|#
directive|define
name|CLK_MMC1
value|65
end_define

begin_define
define|#
directive|define
name|CLK_MMC2
value|66
end_define

begin_define
define|#
directive|define
name|CLK_TS
value|67
end_define

begin_define
define|#
directive|define
name|CLK_SS
value|68
end_define

begin_define
define|#
directive|define
name|CLK_SPI0
value|69
end_define

begin_define
define|#
directive|define
name|CLK_SPI1
value|70
end_define

begin_define
define|#
directive|define
name|CLK_SPI2
value|71
end_define

begin_define
define|#
directive|define
name|CLK_IR
value|72
end_define

begin_define
define|#
directive|define
name|CLK_I2S
value|73
end_define

begin_define
define|#
directive|define
name|CLK_SPDIF
value|74
end_define

begin_define
define|#
directive|define
name|CLK_KEYPAD
value|75
end_define

begin_define
define|#
directive|define
name|CLK_USB_OHCI
value|76
end_define

begin_define
define|#
directive|define
name|CLK_USB_PHY0
value|77
end_define

begin_define
define|#
directive|define
name|CLK_USB_PHY1
value|78
end_define

begin_define
define|#
directive|define
name|CLK_GPS
value|79
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_VE
value|80
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_CSI
value|81
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_TS
value|82
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_TVE
value|83
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_DE_FE
value|84
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_DE_BE
value|85
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_ACE
value|86
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_IEP
value|87
end_define

begin_define
define|#
directive|define
name|CLK_DE_BE
value|88
end_define

begin_define
define|#
directive|define
name|CLK_DE_FE
value|89
end_define

begin_define
define|#
directive|define
name|CLK_TCON_CH0
value|90
end_define

begin_define
define|#
directive|define
name|CLK_TCON_CH1
value|92
end_define

begin_define
define|#
directive|define
name|CLK_CSI
value|93
end_define

begin_define
define|#
directive|define
name|CLK_VE
value|94
end_define

begin_define
define|#
directive|define
name|CLK_CODEC
value|95
end_define

begin_define
define|#
directive|define
name|CLK_AVS
value|96
end_define

begin_define
define|#
directive|define
name|CLK_HDMI
value|97
end_define

begin_define
define|#
directive|define
name|CLK_GPU
value|98
end_define

begin_define
define|#
directive|define
name|CLK_IEP
value|100
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_CLK_SUN5I_H_ */
end_comment

end_unit

