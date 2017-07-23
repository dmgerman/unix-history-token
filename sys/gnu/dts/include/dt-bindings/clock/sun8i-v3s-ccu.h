begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2016 Icenowy Zheng<icenowy@aosc.xyz>  *  * Based on sun8i-h3-ccu.h, which is:  * Copyright (C) 2016 Maxime Ripard<maxime.ripard@free-electrons.com>  *  * This file is dual-licensed: you can use it either under the terms  * of the GPL or the X11 license, at your option. Note that this dual  * licensing only applies to this file, and not this project as a  * whole.  *  *  a) This file is free software; you can redistribute it and/or  *     modify it under the terms of the GNU General Public License as  *     published by the Free Software Foundation; either version 2 of the  *     License, or (at your option) any later version.  *  *     This file is distributed in the hope that it will be useful,  *     but WITHOUT ANY WARRANTY; without even the implied warranty of  *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  *     GNU General Public License for more details.  *  * Or, alternatively,  *  *  b) Permission is hereby granted, free of charge, to any person  *     obtaining a copy of this software and associated documentation  *     files (the "Software"), to deal in the Software without  *     restriction, including without limitation the rights to use,  *     copy, modify, merge, publish, distribute, sublicense, and/or  *     sell copies of the Software, and to permit persons to whom the  *     Software is furnished to do so, subject to the following  *     conditions:  *  *     The above copyright notice and this permission notice shall be  *     included in all copies or substantial portions of the Software.  *  *     THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  *     EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES  *     OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  *     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT  *     HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,  *     WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  *     FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  *     OTHER DEALINGS IN THE SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_CLK_SUN8I_V3S_H_
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_CLK_SUN8I_V3S_H_
end_define

begin_define
define|#
directive|define
name|CLK_CPU
value|14
end_define

begin_define
define|#
directive|define
name|CLK_BUS_CE
value|20
end_define

begin_define
define|#
directive|define
name|CLK_BUS_DMA
value|21
end_define

begin_define
define|#
directive|define
name|CLK_BUS_MMC0
value|22
end_define

begin_define
define|#
directive|define
name|CLK_BUS_MMC1
value|23
end_define

begin_define
define|#
directive|define
name|CLK_BUS_MMC2
value|24
end_define

begin_define
define|#
directive|define
name|CLK_BUS_DRAM
value|25
end_define

begin_define
define|#
directive|define
name|CLK_BUS_EMAC
value|26
end_define

begin_define
define|#
directive|define
name|CLK_BUS_HSTIMER
value|27
end_define

begin_define
define|#
directive|define
name|CLK_BUS_SPI0
value|28
end_define

begin_define
define|#
directive|define
name|CLK_BUS_OTG
value|29
end_define

begin_define
define|#
directive|define
name|CLK_BUS_EHCI0
value|30
end_define

begin_define
define|#
directive|define
name|CLK_BUS_OHCI0
value|31
end_define

begin_define
define|#
directive|define
name|CLK_BUS_VE
value|32
end_define

begin_define
define|#
directive|define
name|CLK_BUS_TCON0
value|33
end_define

begin_define
define|#
directive|define
name|CLK_BUS_CSI
value|34
end_define

begin_define
define|#
directive|define
name|CLK_BUS_DE
value|35
end_define

begin_define
define|#
directive|define
name|CLK_BUS_CODEC
value|36
end_define

begin_define
define|#
directive|define
name|CLK_BUS_PIO
value|37
end_define

begin_define
define|#
directive|define
name|CLK_BUS_I2C0
value|38
end_define

begin_define
define|#
directive|define
name|CLK_BUS_I2C1
value|39
end_define

begin_define
define|#
directive|define
name|CLK_BUS_UART0
value|40
end_define

begin_define
define|#
directive|define
name|CLK_BUS_UART1
value|41
end_define

begin_define
define|#
directive|define
name|CLK_BUS_UART2
value|42
end_define

begin_define
define|#
directive|define
name|CLK_BUS_EPHY
value|43
end_define

begin_define
define|#
directive|define
name|CLK_BUS_DBG
value|44
end_define

begin_define
define|#
directive|define
name|CLK_MMC0
value|45
end_define

begin_define
define|#
directive|define
name|CLK_MMC0_SAMPLE
value|46
end_define

begin_define
define|#
directive|define
name|CLK_MMC0_OUTPUT
value|47
end_define

begin_define
define|#
directive|define
name|CLK_MMC1
value|48
end_define

begin_define
define|#
directive|define
name|CLK_MMC1_SAMPLE
value|49
end_define

begin_define
define|#
directive|define
name|CLK_MMC1_OUTPUT
value|50
end_define

begin_define
define|#
directive|define
name|CLK_MMC2
value|51
end_define

begin_define
define|#
directive|define
name|CLK_MMC2_SAMPLE
value|52
end_define

begin_define
define|#
directive|define
name|CLK_MMC2_OUTPUT
value|53
end_define

begin_define
define|#
directive|define
name|CLK_CE
value|54
end_define

begin_define
define|#
directive|define
name|CLK_SPI0
value|55
end_define

begin_define
define|#
directive|define
name|CLK_USB_PHY0
value|56
end_define

begin_define
define|#
directive|define
name|CLK_USB_OHCI0
value|57
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_VE
value|59
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_CSI
value|60
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_EHCI
value|61
end_define

begin_define
define|#
directive|define
name|CLK_DRAM_OHCI
value|62
end_define

begin_define
define|#
directive|define
name|CLK_DE
value|63
end_define

begin_define
define|#
directive|define
name|CLK_TCON0
value|64
end_define

begin_define
define|#
directive|define
name|CLK_CSI_MISC
value|65
end_define

begin_define
define|#
directive|define
name|CLK_CSI0_MCLK
value|66
end_define

begin_define
define|#
directive|define
name|CLK_CSI1_SCLK
value|67
end_define

begin_define
define|#
directive|define
name|CLK_CSI1_MCLK
value|68
end_define

begin_define
define|#
directive|define
name|CLK_VE
value|69
end_define

begin_define
define|#
directive|define
name|CLK_AC_DIG
value|70
end_define

begin_define
define|#
directive|define
name|CLK_AVS
value|71
end_define

begin_define
define|#
directive|define
name|CLK_MIPI_CSI
value|73
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_CLK_SUN8I_V3S_H_ */
end_comment

end_unit

