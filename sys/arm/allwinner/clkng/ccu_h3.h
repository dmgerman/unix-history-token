begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2017 Emmanuel Vadot<manu@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CCU_H3_H__
end_ifndef

begin_define
define|#
directive|define
name|__CCU_H3_H__
end_define

begin_define
define|#
directive|define
name|H3_RST_USB_PHY0
value|0
end_define

begin_define
define|#
directive|define
name|H3_RST_USB_PHY1
value|1
end_define

begin_define
define|#
directive|define
name|H3_RST_USB_PHY2
value|2
end_define

begin_define
define|#
directive|define
name|H3_RST_USB_PHY3
value|3
end_define

begin_define
define|#
directive|define
name|H3_RST_MBUS
value|4
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_CE
value|5
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_DMA
value|6
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_MMC0
value|7
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_MMC1
value|8
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_MMC2
value|9
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_NAND
value|10
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_DRAM
value|11
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_EMAC
value|12
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_TS
value|13
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_HSTIMER
value|14
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_SPI0
value|15
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_SPI1
value|16
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_OTG
value|17
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_EHCI0
value|18
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_EHCI1
value|19
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_EHCI2
value|20
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_EHCI3
value|21
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_OHCI0
value|22
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_OHCI1
value|23
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_OHCI2
value|24
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_OHCI3
value|25
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_VE
value|26
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_TCON0
value|27
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_TCON1
value|28
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_DEINTERLACE
value|29
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_CSI
value|30
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_TVE
value|31
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_HDMI0
value|32
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_HDMI1
value|33
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_DE
value|34
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_GPU
value|35
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_MSGBOX
value|36
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_SPINLOCK
value|37
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_DBG
value|38
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_EPHY
value|39
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_CODEC
value|40
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_SPDIF
value|41
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_THS
value|42
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_I2S0
value|43
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_I2S1
value|44
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_I2S2
value|45
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_I2C0
value|46
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_I2C1
value|47
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_I2C2
value|48
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_UART0
value|49
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_UART1
value|50
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_UART2
value|51
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_UART3
value|52
end_define

begin_define
define|#
directive|define
name|H3_RST_BUS_SCR
value|53
end_define

begin_define
define|#
directive|define
name|H3_CLK_PLL_CPUX
value|0
end_define

begin_define
define|#
directive|define
name|H3_CLK_PLL_AUDIO_BASE
value|1
end_define

begin_define
define|#
directive|define
name|H3_CLK_PLL_AUDIO
value|2
end_define

begin_define
define|#
directive|define
name|H3_CLK_PLL_AUDIO_2X
value|3
end_define

begin_define
define|#
directive|define
name|H3_CLK_PLL_AUDIO_4X
value|4
end_define

begin_define
define|#
directive|define
name|H3_CLK_PLL_AUDIO_8X
value|5
end_define

begin_define
define|#
directive|define
name|H3_CLK_PLL_VIDEO
value|6
end_define

begin_define
define|#
directive|define
name|H3_CLK_PLL_VE
value|7
end_define

begin_define
define|#
directive|define
name|H3_CLK_PLL_DDR
value|8
end_define

begin_define
define|#
directive|define
name|H3_CLK_PLL_PERIPH0
value|9
end_define

begin_define
define|#
directive|define
name|H3_CLK_PLL_PERIPH0_2X
value|10
end_define

begin_define
define|#
directive|define
name|H3_CLK_PLL_GPU
value|11
end_define

begin_define
define|#
directive|define
name|H3_CLK_PLL_PERIPH1
value|12
end_define

begin_define
define|#
directive|define
name|H3_CLK_PLL_DE
value|13
end_define

begin_define
define|#
directive|define
name|H3_CLK_CPUX
value|14
end_define

begin_define
define|#
directive|define
name|H3_CLK_AXI
value|15
end_define

begin_define
define|#
directive|define
name|H3_CLK_AHB1
value|16
end_define

begin_define
define|#
directive|define
name|H3_CLK_APB1
value|17
end_define

begin_define
define|#
directive|define
name|H3_CLK_APB2
value|18
end_define

begin_define
define|#
directive|define
name|H3_CLK_AHB2
value|19
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_CE
value|20
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_DMA
value|21
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_MMC0
value|22
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_MMC1
value|23
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_MMC2
value|24
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_NAND
value|25
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_DRAM
value|26
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_EMAC
value|27
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_TS
value|28
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_HSTIMER
value|29
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_SPI0
value|30
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_SPI1
value|31
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_OTG
value|32
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_EHCI0
value|33
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_EHCI1
value|34
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_EHCI2
value|35
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_EHCI3
value|36
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_OHCI0
value|37
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_OHCI1
value|38
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_OHCI2
value|39
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_OHCI3
value|40
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_VE
value|41
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_TCON0
value|42
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_TCON1
value|43
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_DEINTERLACE
value|44
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_CSI
value|45
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_TVE
value|46
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_HDMI
value|47
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_DE
value|48
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_GPU
value|49
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_MSGBOX
value|50
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_SPINLOCK
value|51
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_CODEC
value|52
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_SPDIF
value|53
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_PIO
value|54
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_THS
value|55
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_I2S0
value|56
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_I2S1
value|57
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_I2S2
value|58
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_I2C0
value|59
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_I2C1
value|60
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_I2C2
value|61
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_UART0
value|62
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_UART1
value|63
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_UART2
value|64
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_UART3
value|65
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_SCR
value|66
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_EPHY
value|67
end_define

begin_define
define|#
directive|define
name|H3_CLK_BUS_DBG
value|68
end_define

begin_define
define|#
directive|define
name|H3_CLK_THS
value|69
end_define

begin_define
define|#
directive|define
name|H3_CLK_NAND
value|70
end_define

begin_define
define|#
directive|define
name|H3_CLK_MMC0
value|71
end_define

begin_define
define|#
directive|define
name|H3_CLK_MMC0_SAMPLE
value|72
end_define

begin_define
define|#
directive|define
name|H3_CLK_MMC0_OUTPUT
value|73
end_define

begin_define
define|#
directive|define
name|H3_CLK_MMC1
value|74
end_define

begin_define
define|#
directive|define
name|H3_CLK_MMC1_SAMPLE
value|75
end_define

begin_define
define|#
directive|define
name|H3_CLK_MMC1_OUTPUT
value|76
end_define

begin_define
define|#
directive|define
name|H3_CLK_MMC2
value|77
end_define

begin_define
define|#
directive|define
name|H3_CLK_MMC2_SAMPLE
value|78
end_define

begin_define
define|#
directive|define
name|H3_CLK_MMC2_OUTPUT
value|79
end_define

begin_define
define|#
directive|define
name|H3_CLK_TS
value|80
end_define

begin_define
define|#
directive|define
name|H3_CLK_CE
value|81
end_define

begin_define
define|#
directive|define
name|H3_CLK_SPI0
value|82
end_define

begin_define
define|#
directive|define
name|H3_CLK_SPI1
value|83
end_define

begin_define
define|#
directive|define
name|H3_CLK_I2S0
value|84
end_define

begin_define
define|#
directive|define
name|H3_CLK_I2S1
value|85
end_define

begin_define
define|#
directive|define
name|H3_CLK_I2S2
value|86
end_define

begin_define
define|#
directive|define
name|H3_CLK_SPDIF
value|87
end_define

begin_define
define|#
directive|define
name|H3_CLK_USBPHY0
value|88
end_define

begin_define
define|#
directive|define
name|H3_CLK_USBPHY1
value|89
end_define

begin_define
define|#
directive|define
name|H3_CLK_USBPHY2
value|90
end_define

begin_define
define|#
directive|define
name|H3_CLK_USBPHY3
value|91
end_define

begin_define
define|#
directive|define
name|H3_CLK_USBOHCI0
value|92
end_define

begin_define
define|#
directive|define
name|H3_CLK_USBOHCI1
value|93
end_define

begin_define
define|#
directive|define
name|H3_CLK_USBOHCI2
value|94
end_define

begin_define
define|#
directive|define
name|H3_CLK_USBOHCI3
value|95
end_define

begin_function_decl
name|void
name|ccu_h3_register_clocks
parameter_list|(
name|struct
name|aw_ccung_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __CCU_H3_H__ */
end_comment

end_unit

