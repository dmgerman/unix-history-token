begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2017 Emmanuel Vadot<manu@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<dev/extres/clk/clk_div.h>
end_include

begin_include
include|#
directive|include
file|<dev/extres/clk/clk_fixed.h>
end_include

begin_include
include|#
directive|include
file|<dev/extres/clk/clk_mux.h>
end_include

begin_include
include|#
directive|include
file|<arm/allwinner/clkng/aw_ccung.h>
end_include

begin_include
include|#
directive|include
file|<arm/allwinner/clkng/aw_clk.h>
end_include

begin_include
include|#
directive|include
file|<arm/allwinner/clkng/aw_clk_nm.h>
end_include

begin_include
include|#
directive|include
file|<arm/allwinner/clkng/aw_clk_nkmp.h>
end_include

begin_include
include|#
directive|include
file|<arm/allwinner/clkng/aw_clk_prediv_mux.h>
end_include

begin_include
include|#
directive|include
file|"ccu_a64.h"
end_include

begin_decl_stmt
specifier|static
name|struct
name|aw_ccung_reset
name|a64_ccu_resets
index|[]
init|=
block|{
name|CCU_RESET
argument_list|(
argument|A64_RST_USB_PHY0
argument_list|,
literal|0x0cc
argument_list|,
literal|0
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_USB_PHY1
argument_list|,
literal|0x0cc
argument_list|,
literal|1
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_USB_HSIC
argument_list|,
literal|0x0cc
argument_list|,
literal|2
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_MIPI_DSI
argument_list|,
literal|0x2c0
argument_list|,
literal|1
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_CE
argument_list|,
literal|0x2c0
argument_list|,
literal|5
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_DMA
argument_list|,
literal|0x2c0
argument_list|,
literal|6
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_MMC0
argument_list|,
literal|0x2c0
argument_list|,
literal|8
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_MMC1
argument_list|,
literal|0x2c0
argument_list|,
literal|9
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_MMC2
argument_list|,
literal|0x2c0
argument_list|,
literal|10
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_NAND
argument_list|,
literal|0x2c0
argument_list|,
literal|13
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_DRAM
argument_list|,
literal|0x2c0
argument_list|,
literal|14
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_EMAC
argument_list|,
literal|0x2c0
argument_list|,
literal|17
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_TS
argument_list|,
literal|0x2c0
argument_list|,
literal|18
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_HSTIMER
argument_list|,
literal|0x2c0
argument_list|,
literal|19
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_SPI0
argument_list|,
literal|0x2c0
argument_list|,
literal|20
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_SPI1
argument_list|,
literal|0x2c0
argument_list|,
literal|21
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_OTG
argument_list|,
literal|0x2c0
argument_list|,
literal|23
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_EHCI0
argument_list|,
literal|0x2c0
argument_list|,
literal|24
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_EHCI1
argument_list|,
literal|0x2c0
argument_list|,
literal|25
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_OHCI0
argument_list|,
literal|0x2c0
argument_list|,
literal|26
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_OHCI1
argument_list|,
literal|0x2c0
argument_list|,
literal|27
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_VE
argument_list|,
literal|0x2c4
argument_list|,
literal|0
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_TCON0
argument_list|,
literal|0x2c4
argument_list|,
literal|3
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_TCON1
argument_list|,
literal|0x2c4
argument_list|,
literal|4
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_DEINTERLACE
argument_list|,
literal|0x2c4
argument_list|,
literal|5
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_CSI
argument_list|,
literal|0x2c4
argument_list|,
literal|8
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_HDMI0
argument_list|,
literal|0x2c4
argument_list|,
literal|10
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_HDMI1
argument_list|,
literal|0x2c4
argument_list|,
literal|11
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_DE
argument_list|,
literal|0x2c4
argument_list|,
literal|12
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_GPU
argument_list|,
literal|0x2c4
argument_list|,
literal|20
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_MSGBOX
argument_list|,
literal|0x2c4
argument_list|,
literal|21
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_SPINLOCK
argument_list|,
literal|0x2c4
argument_list|,
literal|22
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_DBG
argument_list|,
literal|0x2c4
argument_list|,
literal|31
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_LVDS
argument_list|,
literal|0x2C8
argument_list|,
literal|31
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_CODEC
argument_list|,
literal|0x2D0
argument_list|,
literal|0
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_SPDIF
argument_list|,
literal|0x2D0
argument_list|,
literal|1
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_THS
argument_list|,
literal|0x2D0
argument_list|,
literal|8
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_I2S0
argument_list|,
literal|0x2D0
argument_list|,
literal|12
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_I2S1
argument_list|,
literal|0x2D0
argument_list|,
literal|13
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_I2S2
argument_list|,
literal|0x2D0
argument_list|,
literal|14
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_I2C0
argument_list|,
literal|0x2D8
argument_list|,
literal|0
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_I2C1
argument_list|,
literal|0x2D8
argument_list|,
literal|1
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_I2C2
argument_list|,
literal|0x2D8
argument_list|,
literal|2
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_SCR
argument_list|,
literal|0x2D8
argument_list|,
literal|5
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_UART0
argument_list|,
literal|0x2D8
argument_list|,
literal|16
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_UART1
argument_list|,
literal|0x2D8
argument_list|,
literal|17
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_UART2
argument_list|,
literal|0x2D8
argument_list|,
literal|18
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_UART3
argument_list|,
literal|0x2D8
argument_list|,
literal|19
argument_list|)
name|CCU_RESET
argument_list|(
argument|A64_RST_BUS_UART4
argument_list|,
literal|0x2D8
argument_list|,
literal|20
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|aw_ccung_gate
name|a64_ccu_gates
index|[]
init|=
block|{
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_MIPI_DSI
argument_list|,
literal|"bus-mipi-dsi"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x60
argument_list|,
literal|1
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_CE
argument_list|,
literal|"bus-ce"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x60
argument_list|,
literal|5
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_DMA
argument_list|,
literal|"bus-dma"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x60
argument_list|,
literal|6
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_MMC0
argument_list|,
literal|"bus-mmc0"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x60
argument_list|,
literal|8
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_MMC1
argument_list|,
literal|"bus-mmc1"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x60
argument_list|,
literal|9
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_MMC2
argument_list|,
literal|"bus-mmc2"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x60
argument_list|,
literal|10
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_NAND
argument_list|,
literal|"bus-nand"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x60
argument_list|,
literal|13
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_DRAM
argument_list|,
literal|"bus-dram"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x60
argument_list|,
literal|14
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_EMAC
argument_list|,
literal|"bus-emac"
argument_list|,
literal|"ahb2"
argument_list|,
literal|0x60
argument_list|,
literal|16
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_TS
argument_list|,
literal|"bus-ts"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x60
argument_list|,
literal|18
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_HSTIMER
argument_list|,
literal|"bus-hstimer"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x60
argument_list|,
literal|19
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_SPI0
argument_list|,
literal|"bus-spi0"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x60
argument_list|,
literal|20
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_SPI1
argument_list|,
literal|"bus-spi1"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x60
argument_list|,
literal|21
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_OTG
argument_list|,
literal|"bus-otg"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x60
argument_list|,
literal|23
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_EHCI0
argument_list|,
literal|"bus-ehci0"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x60
argument_list|,
literal|24
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_EHCI1
argument_list|,
literal|"bus-ehci1"
argument_list|,
literal|"ahb2"
argument_list|,
literal|0x60
argument_list|,
literal|25
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_OHCI0
argument_list|,
literal|"bus-ohci0"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x60
argument_list|,
literal|26
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_OHCI1
argument_list|,
literal|"bus-ohci1"
argument_list|,
literal|"ahb2"
argument_list|,
literal|0x60
argument_list|,
literal|27
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_VE
argument_list|,
literal|"bus-ve"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x64
argument_list|,
literal|0
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_TCON0
argument_list|,
literal|"bus-tcon0"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x64
argument_list|,
literal|3
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_TCON1
argument_list|,
literal|"bus-tcon1"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x64
argument_list|,
literal|4
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_DEINTERLACE
argument_list|,
literal|"bus-deinterlace"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x64
argument_list|,
literal|5
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_CSI
argument_list|,
literal|"bus-csi"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x64
argument_list|,
literal|8
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_HDMI
argument_list|,
literal|"bus-hdmi"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x64
argument_list|,
literal|11
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_DE
argument_list|,
literal|"bus-de"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x64
argument_list|,
literal|12
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_GPU
argument_list|,
literal|"bus-gpu"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x64
argument_list|,
literal|20
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_MSGBOX
argument_list|,
literal|"bus-msgbox"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x64
argument_list|,
literal|21
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_SPINLOCK
argument_list|,
literal|"bus-spinlock"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x64
argument_list|,
literal|22
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_CODEC
argument_list|,
literal|"bus-codec"
argument_list|,
literal|"apb1"
argument_list|,
literal|0x68
argument_list|,
literal|0
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_SPDIF
argument_list|,
literal|"bus-spdif"
argument_list|,
literal|"apb1"
argument_list|,
literal|0x68
argument_list|,
literal|1
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_PIO
argument_list|,
literal|"bus-pio"
argument_list|,
literal|"apb1"
argument_list|,
literal|0x68
argument_list|,
literal|5
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_THS
argument_list|,
literal|"bus-ths"
argument_list|,
literal|"apb1"
argument_list|,
literal|0x68
argument_list|,
literal|8
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_I2S0
argument_list|,
literal|"bus-i2s0"
argument_list|,
literal|"apb1"
argument_list|,
literal|0x68
argument_list|,
literal|12
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_I2S1
argument_list|,
literal|"bus-i2s1"
argument_list|,
literal|"apb1"
argument_list|,
literal|0x68
argument_list|,
literal|13
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_I2S2
argument_list|,
literal|"bus-i2s2"
argument_list|,
literal|"apb1"
argument_list|,
literal|0x68
argument_list|,
literal|14
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_I2C0
argument_list|,
literal|"bus-i2c0"
argument_list|,
literal|"apb2"
argument_list|,
literal|0x6C
argument_list|,
literal|0
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_I2C1
argument_list|,
literal|"bus-i2c1"
argument_list|,
literal|"apb2"
argument_list|,
literal|0x6C
argument_list|,
literal|1
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_I2C2
argument_list|,
literal|"bus-i2c2"
argument_list|,
literal|"apb2"
argument_list|,
literal|0x6C
argument_list|,
literal|2
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_SCR
argument_list|,
literal|"bus-src"
argument_list|,
literal|"apb2"
argument_list|,
literal|0x6C
argument_list|,
literal|5
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_UART0
argument_list|,
literal|"bus-uart0"
argument_list|,
literal|"apb2"
argument_list|,
literal|0x6C
argument_list|,
literal|16
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_UART1
argument_list|,
literal|"bus-uart1"
argument_list|,
literal|"apb2"
argument_list|,
literal|0x6C
argument_list|,
literal|17
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_UART2
argument_list|,
literal|"bus-uart2"
argument_list|,
literal|"apb2"
argument_list|,
literal|0x6C
argument_list|,
literal|18
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_UART3
argument_list|,
literal|"bus-uart3"
argument_list|,
literal|"apb2"
argument_list|,
literal|0x6C
argument_list|,
literal|19
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_UART4
argument_list|,
literal|"bus-uart4"
argument_list|,
literal|"apb2"
argument_list|,
literal|0x6C
argument_list|,
literal|20
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_BUS_DBG
argument_list|,
literal|"bus-dbg"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x70
argument_list|,
literal|7
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_USB_PHY0
argument_list|,
literal|"usb-phy0"
argument_list|,
literal|"osc24M"
argument_list|,
literal|0xcc
argument_list|,
literal|8
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_USB_PHY1
argument_list|,
literal|"usb-phy1"
argument_list|,
literal|"osc24M"
argument_list|,
literal|0xcc
argument_list|,
literal|9
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_USB_HSIC
argument_list|,
literal|"usb-hsic"
argument_list|,
literal|"pll_hsic"
argument_list|,
literal|0xcc
argument_list|,
literal|10
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_USB_HSIC_12M
argument_list|,
literal|"usb-hsic-12M"
argument_list|,
literal|"osc12M"
argument_list|,
literal|0xcc
argument_list|,
literal|11
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_USB_OHCI0
argument_list|,
literal|"usb-ohci0"
argument_list|,
literal|"osc12M"
argument_list|,
literal|0xcc
argument_list|,
literal|16
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_USB_OHCI1
argument_list|,
literal|"usb-ohci1"
argument_list|,
literal|"usb-ohci0"
argument_list|,
literal|0xcc
argument_list|,
literal|17
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_DRAM_VE
argument_list|,
literal|"dram-ve"
argument_list|,
literal|"dram"
argument_list|,
literal|0x100
argument_list|,
literal|0
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_DRAM_CSI
argument_list|,
literal|"dram-csi"
argument_list|,
literal|"dram"
argument_list|,
literal|0x100
argument_list|,
literal|1
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_DRAM_DEINTERLACE
argument_list|,
literal|"dram-deinterlace"
argument_list|,
literal|"dram"
argument_list|,
literal|0x100
argument_list|,
literal|2
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_DRAM_TS
argument_list|,
literal|"dram-ts"
argument_list|,
literal|"dram"
argument_list|,
literal|0x100
argument_list|,
literal|3
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_CSI_MISC
argument_list|,
literal|"csi-misc"
argument_list|,
literal|"osc24M"
argument_list|,
literal|0x130
argument_list|,
literal|31
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_AC_DIG_4X
argument_list|,
literal|"ac-dig-4x"
argument_list|,
literal|"pll_audio-4x"
argument_list|,
literal|0x140
argument_list|,
literal|30
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_AC_DIG
argument_list|,
literal|"ac-dig"
argument_list|,
literal|"pll_audio"
argument_list|,
literal|0x140
argument_list|,
literal|31
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_AVS
argument_list|,
literal|"avs"
argument_list|,
literal|"osc24M"
argument_list|,
literal|0x144
argument_list|,
literal|31
argument_list|)
name|CCU_GATE
argument_list|(
argument|A64_CLK_HDMI_DDC
argument_list|,
literal|"hdmi-ddc"
argument_list|,
literal|"osc24M"
argument_list|,
literal|0x154
argument_list|,
literal|31
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|osc12m_parents
index|[]
init|=
block|{
literal|"osc24M"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|FIXED_CLK
argument_list|(
name|osc12m_clk
argument_list|,
name|A64_CLK_OSC_12M
argument_list|,
comment|/* id */
literal|"osc12M"
argument_list|,
comment|/* name */
name|osc12m_parents
argument_list|,
comment|/* parent */
literal|0
argument_list|,
comment|/* freq */
literal|1
argument_list|,
comment|/* mult */
literal|2
argument_list|,
comment|/* div */
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* flags */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|pll_cpux_parents
index|[]
init|=
block|{
literal|"osc24M"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NKMP_CLK
argument_list|(
name|pll_cpux_clk
argument_list|,
name|A64_CLK_PLL_CPUX
argument_list|,
comment|/* id */
literal|"pll_cpux"
argument_list|,
name|pll_cpux_parents
argument_list|,
comment|/* name, parents */
literal|0x00
argument_list|,
comment|/* offset */
literal|8
argument_list|,
literal|5
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* n factor */
literal|4
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* k factor */
literal|0
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* m factor */
literal|16
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
name|AW_CLK_FACTOR_POWER_OF_TWO
argument_list|,
comment|/* p factor */
literal|31
argument_list|,
comment|/* gate */
literal|28
argument_list|,
literal|1000
argument_list|,
comment|/* lock */
name|AW_CLK_HAS_GATE
operator||
name|AW_CLK_HAS_LOCK
operator||
name|AW_CLK_SCALE_CHANGE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* flags */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|pll_audio_parents
index|[]
init|=
block|{
literal|"osc24M"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NKMP_CLK
argument_list|(
name|pll_audio_clk
argument_list|,
name|A64_CLK_PLL_AUDIO
argument_list|,
comment|/* id */
literal|"pll_audio"
argument_list|,
name|pll_audio_parents
argument_list|,
comment|/* name, parents */
literal|0x08
argument_list|,
comment|/* offset */
literal|8
argument_list|,
literal|7
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* n factor */
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
name|AW_CLK_FACTOR_FIXED
argument_list|,
comment|/* k factor (fake) */
literal|0
argument_list|,
literal|5
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* m factor */
literal|16
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* p factor */
literal|31
argument_list|,
comment|/* gate */
literal|28
argument_list|,
literal|1000
argument_list|,
comment|/* lock */
name|AW_CLK_HAS_GATE
operator||
name|AW_CLK_HAS_LOCK
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* flags */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|pll_audio_mult_parents
index|[]
init|=
block|{
literal|"pll_audio"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|FIXED_CLK
argument_list|(
name|pll_audio_2x_clk
argument_list|,
name|A64_CLK_PLL_AUDIO_2X
argument_list|,
comment|/* id */
literal|"pll_audio-2x"
argument_list|,
comment|/* name */
name|pll_audio_mult_parents
argument_list|,
comment|/* parent */
literal|0
argument_list|,
comment|/* freq */
literal|2
argument_list|,
comment|/* mult */
literal|1
argument_list|,
comment|/* div */
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* flags */
end_comment

begin_expr_stmt
name|FIXED_CLK
argument_list|(
name|pll_audio_4x_clk
argument_list|,
name|A64_CLK_PLL_AUDIO_4X
argument_list|,
comment|/* id */
literal|"pll_audio-4x"
argument_list|,
comment|/* name */
name|pll_audio_mult_parents
argument_list|,
comment|/* parent */
literal|0
argument_list|,
comment|/* freq */
literal|4
argument_list|,
comment|/* mult */
literal|1
argument_list|,
comment|/* div */
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* flags */
end_comment

begin_expr_stmt
name|FIXED_CLK
argument_list|(
name|pll_audio_8x_clk
argument_list|,
name|A64_CLK_PLL_AUDIO_8X
argument_list|,
comment|/* id */
literal|"pll_audio-8x"
argument_list|,
comment|/* name */
name|pll_audio_mult_parents
argument_list|,
comment|/* parent */
literal|0
argument_list|,
comment|/* freq */
literal|8
argument_list|,
comment|/* mult */
literal|1
argument_list|,
comment|/* div */
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* flags */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|pll_video0_parents
index|[]
init|=
block|{
literal|"osc24M"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NM_CLK_WITH_FRAC
argument_list|(
name|pll_video0_clk
argument_list|,
name|A64_CLK_PLL_VIDEO0
argument_list|,
comment|/* id */
literal|"pll_video0"
argument_list|,
name|pll_video0_parents
argument_list|,
comment|/* name, parents */
literal|0x10
argument_list|,
comment|/* offset */
literal|8
argument_list|,
literal|7
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* n factor */
literal|0
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* m factor */
literal|31
argument_list|,
literal|28
argument_list|,
literal|1000
argument_list|,
comment|/* gate, lock, lock retries */
name|AW_CLK_HAS_LOCK
argument_list|,
comment|/* flags */
literal|270000000
argument_list|,
literal|297000000
argument_list|,
comment|/* freq0, freq1 */
literal|24
argument_list|,
literal|25
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* mode sel, freq sel */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|pll_ve_parents
index|[]
init|=
block|{
literal|"osc24M"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NM_CLK_WITH_FRAC
argument_list|(
name|pll_ve_clk
argument_list|,
name|A64_CLK_PLL_VE
argument_list|,
comment|/* id */
literal|"pll_ve"
argument_list|,
name|pll_ve_parents
argument_list|,
comment|/* name, parents */
literal|0x18
argument_list|,
comment|/* offset */
literal|8
argument_list|,
literal|7
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* n factor */
literal|0
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* m factor */
literal|31
argument_list|,
literal|28
argument_list|,
literal|1000
argument_list|,
comment|/* gate, lock, lock retries */
name|AW_CLK_HAS_LOCK
argument_list|,
comment|/* flags */
literal|270000000
argument_list|,
literal|297000000
argument_list|,
comment|/* freq0, freq1 */
literal|24
argument_list|,
literal|25
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* mode sel, freq sel */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|pll_ddr0_parents
index|[]
init|=
block|{
literal|"osc24M"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NKMP_CLK_WITH_UPDATE
argument_list|(
name|pll_ddr0_clk
argument_list|,
name|A64_CLK_PLL_DDR0
argument_list|,
comment|/* id */
literal|"pll_ddr0"
argument_list|,
name|pll_ddr0_parents
argument_list|,
comment|/* name, parents */
literal|0x20
argument_list|,
comment|/* offset */
literal|8
argument_list|,
literal|5
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* n factor */
literal|4
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* k factor */
literal|0
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* m factor */
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
name|AW_CLK_FACTOR_FIXED
argument_list|,
comment|/* p factor (fake) */
literal|31
argument_list|,
comment|/* gate */
literal|28
argument_list|,
literal|1000
argument_list|,
comment|/* lock */
literal|20
argument_list|,
comment|/* update */
name|AW_CLK_HAS_GATE
operator||
name|AW_CLK_HAS_LOCK
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* flags */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|pll_periph0_2x_parents
index|[]
init|=
block|{
literal|"osc24M"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|pll_periph0_parents
index|[]
init|=
block|{
literal|"pll_periph0_2x"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NKMP_CLK
argument_list|(
name|pll_periph0_2x_clk
argument_list|,
name|A64_CLK_PLL_PERIPH0_2X
argument_list|,
comment|/* id */
literal|"pll_periph0_2x"
argument_list|,
name|pll_periph0_2x_parents
argument_list|,
comment|/* name, parents */
literal|0x28
argument_list|,
comment|/* offset */
literal|8
argument_list|,
literal|5
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* n factor */
literal|4
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* k factor */
literal|0
argument_list|,
literal|0
argument_list|,
literal|2
argument_list|,
name|AW_CLK_FACTOR_FIXED
argument_list|,
comment|/* m factor (fake) */
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
name|AW_CLK_FACTOR_FIXED
argument_list|,
comment|/* p factor (fake) */
literal|31
argument_list|,
comment|/* gate */
literal|28
argument_list|,
literal|1000
argument_list|,
comment|/* lock */
name|AW_CLK_HAS_GATE
operator||
name|AW_CLK_HAS_LOCK
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* flags */
end_comment

begin_expr_stmt
name|FIXED_CLK
argument_list|(
name|pll_periph0_clk
argument_list|,
name|A64_CLK_PLL_PERIPH0
argument_list|,
comment|/* id */
literal|"pll_periph0"
argument_list|,
comment|/* name */
name|pll_periph0_parents
argument_list|,
comment|/* parent */
literal|0
argument_list|,
comment|/* freq */
literal|1
argument_list|,
comment|/* mult */
literal|2
argument_list|,
comment|/* div */
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* flags */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|pll_periph1_2x_parents
index|[]
init|=
block|{
literal|"osc24M"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|pll_periph1_parents
index|[]
init|=
block|{
literal|"pll_periph1_2x"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NKMP_CLK
argument_list|(
name|pll_periph1_2x_clk
argument_list|,
name|A64_CLK_PLL_PERIPH1_2X
argument_list|,
comment|/* id */
literal|"pll_periph1_2x"
argument_list|,
name|pll_periph1_2x_parents
argument_list|,
comment|/* name, parents */
literal|0x2C
argument_list|,
comment|/* offset */
literal|8
argument_list|,
literal|5
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* n factor */
literal|4
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* k factor */
literal|0
argument_list|,
literal|0
argument_list|,
literal|2
argument_list|,
name|AW_CLK_FACTOR_FIXED
argument_list|,
comment|/* m factor (fake) */
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
name|AW_CLK_FACTOR_FIXED
argument_list|,
comment|/* p factor (fake) */
literal|31
argument_list|,
comment|/* gate */
literal|28
argument_list|,
literal|1000
argument_list|,
comment|/* lock */
name|AW_CLK_HAS_GATE
operator||
name|AW_CLK_HAS_LOCK
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* flags */
end_comment

begin_expr_stmt
name|FIXED_CLK
argument_list|(
name|pll_periph1_clk
argument_list|,
name|A64_CLK_PLL_PERIPH1
argument_list|,
comment|/* id */
literal|"pll_periph1"
argument_list|,
comment|/* name */
name|pll_periph1_parents
argument_list|,
comment|/* parent */
literal|0
argument_list|,
comment|/* freq */
literal|1
argument_list|,
comment|/* mult */
literal|2
argument_list|,
comment|/* div */
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* flags */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|pll_video1_parents
index|[]
init|=
block|{
literal|"osc24M"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NM_CLK_WITH_FRAC
argument_list|(
name|pll_video1_clk
argument_list|,
name|A64_CLK_PLL_VIDEO1
argument_list|,
comment|/* id */
literal|"pll_video1"
argument_list|,
name|pll_video1_parents
argument_list|,
comment|/* name, parents */
literal|0x30
argument_list|,
comment|/* offset */
literal|8
argument_list|,
literal|7
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* n factor */
literal|0
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* m factor */
literal|31
argument_list|,
literal|28
argument_list|,
literal|1000
argument_list|,
comment|/* gate, lock, lock retries */
name|AW_CLK_HAS_LOCK
argument_list|,
comment|/* flags */
literal|270000000
argument_list|,
literal|297000000
argument_list|,
comment|/* freq0, freq1 */
literal|24
argument_list|,
literal|25
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* mode sel, freq sel */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|pll_gpu_parents
index|[]
init|=
block|{
literal|"osc24M"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NM_CLK_WITH_FRAC
argument_list|(
name|pll_gpu_clk
argument_list|,
name|A64_CLK_PLL_GPU
argument_list|,
comment|/* id */
literal|"pll_gpu"
argument_list|,
name|pll_gpu_parents
argument_list|,
comment|/* name, parents */
literal|0x38
argument_list|,
comment|/* offset */
literal|8
argument_list|,
literal|7
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* n factor */
literal|0
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* m factor */
literal|31
argument_list|,
literal|28
argument_list|,
literal|1000
argument_list|,
comment|/* gate, lock, lock retries */
name|AW_CLK_HAS_LOCK
argument_list|,
comment|/* flags */
literal|270000000
argument_list|,
literal|297000000
argument_list|,
comment|/* freq0, freq1 */
literal|24
argument_list|,
literal|25
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* mode sel, freq sel */
end_comment

begin_comment
comment|/* PLL MIPI is missing */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|pll_hsic_parents
index|[]
init|=
block|{
literal|"osc24M"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NM_CLK_WITH_FRAC
argument_list|(
name|pll_hsic_clk
argument_list|,
name|A64_CLK_PLL_HSIC
argument_list|,
comment|/* id */
literal|"pll_hsic"
argument_list|,
name|pll_hsic_parents
argument_list|,
comment|/* name, parents */
literal|0x44
argument_list|,
comment|/* offset */
literal|8
argument_list|,
literal|7
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* n factor */
literal|0
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* m factor */
literal|31
argument_list|,
literal|28
argument_list|,
literal|1000
argument_list|,
comment|/* gate, lock, lock retries */
name|AW_CLK_HAS_LOCK
argument_list|,
comment|/* flags */
literal|270000000
argument_list|,
literal|297000000
argument_list|,
comment|/* freq0, freq1 */
literal|24
argument_list|,
literal|25
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* mode sel, freq sel */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|pll_de_parents
index|[]
init|=
block|{
literal|"osc24M"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NM_CLK_WITH_FRAC
argument_list|(
name|pll_de_clk
argument_list|,
name|A64_CLK_PLL_DE
argument_list|,
comment|/* id */
literal|"pll_de"
argument_list|,
name|pll_de_parents
argument_list|,
comment|/* name, parents */
literal|0x48
argument_list|,
comment|/* offset */
literal|8
argument_list|,
literal|7
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* n factor */
literal|0
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* m factor */
literal|31
argument_list|,
literal|28
argument_list|,
literal|1000
argument_list|,
comment|/* gate, lock, lock retries */
name|AW_CLK_HAS_LOCK
argument_list|,
comment|/* flags */
literal|270000000
argument_list|,
literal|297000000
argument_list|,
comment|/* freq0, freq1 */
literal|24
argument_list|,
literal|25
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* mode sel, freq sel */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|pll_ddr1_parents
index|[]
init|=
block|{
literal|"osc24M"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NKMP_CLK_WITH_UPDATE
argument_list|(
name|pll_ddr1_clk
argument_list|,
name|A64_CLK_PLL_DDR1
argument_list|,
comment|/* id */
literal|"pll_ddr1"
argument_list|,
name|pll_ddr1_parents
argument_list|,
comment|/* name, parents */
literal|0x4C
argument_list|,
comment|/* offset */
literal|8
argument_list|,
literal|7
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* n factor */
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
name|AW_CLK_FACTOR_FIXED
argument_list|,
comment|/* k factor (fake) */
literal|0
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* m factor */
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
name|AW_CLK_FACTOR_FIXED
argument_list|,
comment|/* p factor (fake) */
literal|31
argument_list|,
comment|/* gate */
literal|28
argument_list|,
literal|1000
argument_list|,
comment|/* lock */
literal|20
argument_list|,
comment|/* update */
name|AW_CLK_HAS_GATE
operator||
name|AW_CLK_HAS_LOCK
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* flags */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|cpux_parents
index|[]
init|=
block|{
literal|"osc32k"
block|,
literal|"osc24M"
block|,
literal|"pll_cpux"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|MUX_CLK
argument_list|(
name|cpux_clk
argument_list|,
name|A64_CLK_CPUX
argument_list|,
comment|/* id */
literal|"cpux"
argument_list|,
name|cpux_parents
argument_list|,
comment|/* name, parents */
literal|0x50
argument_list|,
literal|16
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* offset, shift, width */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|axi_parents
index|[]
init|=
block|{
literal|"cpux"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DIV_CLK
argument_list|(
name|axi_clk
argument_list|,
name|A64_CLK_AXI
argument_list|,
comment|/* id */
literal|"axi"
argument_list|,
name|axi_parents
argument_list|,
comment|/* name, parents */
literal|0x50
argument_list|,
comment|/* offset */
literal|0
argument_list|,
literal|2
argument_list|,
comment|/* shift, width */
literal|0
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* flags, div table */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|apb_parents
index|[]
init|=
block|{
literal|"cpux"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DIV_CLK
argument_list|(
name|apb_clk
argument_list|,
name|A64_CLK_APB
argument_list|,
comment|/* id */
literal|"apb"
argument_list|,
name|apb_parents
argument_list|,
comment|/* name, parents */
literal|0x50
argument_list|,
comment|/* offset */
literal|8
argument_list|,
literal|2
argument_list|,
comment|/* shift, width */
literal|0
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* flags, div table */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|ahb1_parents
index|[]
init|=
block|{
literal|"osc32k"
block|,
literal|"osc24M"
block|,
literal|"axi"
block|,
literal|"pll_periph0"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|PREDIV_CLK
argument_list|(
name|ahb1_clk
argument_list|,
name|A64_CLK_AHB1
argument_list|,
comment|/* id */
literal|"ahb1"
argument_list|,
name|ahb1_parents
argument_list|,
comment|/* name, parents */
literal|0x54
argument_list|,
comment|/* offset */
literal|12
argument_list|,
literal|2
argument_list|,
comment|/* mux */
literal|4
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
name|AW_CLK_FACTOR_POWER_OF_TWO
argument_list|,
comment|/* div */
literal|6
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
name|AW_CLK_FACTOR_HAS_COND
argument_list|,
comment|/* prediv */
literal|12
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* prediv condition */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|apb1_parents
index|[]
init|=
block|{
literal|"ahb1"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|clk_div_table
name|apb1_div_table
index|[]
init|=
block|{
block|{
operator|.
name|value
operator|=
literal|0
block|,
operator|.
name|divider
operator|=
literal|2
block|, }
block|,
block|{
operator|.
name|value
operator|=
literal|1
block|,
operator|.
name|divider
operator|=
literal|2
block|, }
block|,
block|{
operator|.
name|value
operator|=
literal|2
block|,
operator|.
name|divider
operator|=
literal|4
block|, }
block|,
block|{
operator|.
name|value
operator|=
literal|3
block|,
operator|.
name|divider
operator|=
literal|8
block|, }
block|,
block|{ }
block|, }
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DIV_CLK
argument_list|(
name|apb1_clk
argument_list|,
name|A64_CLK_APB1
argument_list|,
comment|/* id */
literal|"apb1"
argument_list|,
name|apb1_parents
argument_list|,
comment|/* name, parents */
literal|0x54
argument_list|,
comment|/* offset */
literal|8
argument_list|,
literal|2
argument_list|,
comment|/* shift, width */
name|CLK_DIV_WITH_TABLE
argument_list|,
comment|/* flags */
name|apb1_div_table
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* div table */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|apb2_parents
index|[]
init|=
block|{
literal|"osc32k"
block|,
literal|"osc24M"
block|,
literal|"pll_periph0_2x"
block|,
literal|"pll_periph0_2x"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NM_CLK
argument_list|(
name|apb2_clk
argument_list|,
name|A64_CLK_APB2
argument_list|,
comment|/* id */
literal|"apb2"
argument_list|,
name|apb2_parents
argument_list|,
comment|/* name, parents */
literal|0x58
argument_list|,
comment|/* offset */
literal|16
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
name|AW_CLK_FACTOR_POWER_OF_TWO
argument_list|,
comment|/* n factor */
literal|0
argument_list|,
literal|5
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* m factor */
literal|24
argument_list|,
literal|2
argument_list|,
comment|/* mux */
literal|0
argument_list|,
comment|/* gate */
name|AW_CLK_HAS_MUX
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|ahb2_parents
index|[]
init|=
block|{
literal|"ahb1"
block|,
literal|"pll_periph0"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|PREDIV_CLK
argument_list|(
name|ahb2_clk
argument_list|,
name|A64_CLK_AHB2
argument_list|,
comment|/* id */
literal|"ahb2"
argument_list|,
name|ahb2_parents
argument_list|,
comment|/* name, parents */
literal|0x5c
argument_list|,
comment|/* offset */
literal|0
argument_list|,
literal|2
argument_list|,
comment|/* mux */
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
name|AW_CLK_FACTOR_FIXED
argument_list|,
comment|/* div */
literal|0
argument_list|,
literal|0
argument_list|,
literal|2
argument_list|,
name|AW_CLK_FACTOR_HAS_COND
operator||
name|AW_CLK_FACTOR_FIXED
argument_list|,
comment|/* prediv */
literal|0
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* prediv condition */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|mod_parents
index|[]
init|=
block|{
literal|"osc24M"
block|,
literal|"pll_periph0_2x"
block|,
literal|"pll_periph1_2x"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NM_CLK
argument_list|(
name|nand_clk
argument_list|,
name|A64_CLK_NAND
argument_list|,
literal|"nand"
argument_list|,
name|mod_parents
argument_list|,
comment|/* id, name, parents */
literal|0x80
argument_list|,
comment|/* offset */
literal|16
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
name|AW_CLK_FACTOR_POWER_OF_TWO
argument_list|,
comment|/* n factor */
literal|0
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* m factor */
literal|24
argument_list|,
literal|2
argument_list|,
comment|/* mux */
literal|31
argument_list|,
comment|/* gate */
name|AW_CLK_HAS_GATE
operator||
name|AW_CLK_HAS_MUX
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* flags */
end_comment

begin_expr_stmt
name|NM_CLK
argument_list|(
name|mmc0_clk
argument_list|,
name|A64_CLK_MMC0
argument_list|,
literal|"mmc0"
argument_list|,
name|mod_parents
argument_list|,
comment|/* id, name, parents */
literal|0x88
argument_list|,
comment|/* offset */
literal|16
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
name|AW_CLK_FACTOR_POWER_OF_TWO
argument_list|,
comment|/* n factor */
literal|0
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* m factor */
literal|24
argument_list|,
literal|2
argument_list|,
comment|/* mux */
literal|31
argument_list|,
comment|/* gate */
name|AW_CLK_HAS_GATE
operator||
name|AW_CLK_HAS_MUX
operator||
name|AW_CLK_REPARENT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* flags */
end_comment

begin_expr_stmt
name|NM_CLK
argument_list|(
name|mmc1_clk
argument_list|,
name|A64_CLK_MMC1
argument_list|,
literal|"mmc1"
argument_list|,
name|mod_parents
argument_list|,
comment|/* id, name, parents */
literal|0x8c
argument_list|,
comment|/* offset */
literal|16
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
name|AW_CLK_FACTOR_POWER_OF_TWO
argument_list|,
comment|/* n factor */
literal|0
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* m factor */
literal|24
argument_list|,
literal|2
argument_list|,
comment|/* mux */
literal|31
argument_list|,
comment|/* gate */
name|AW_CLK_HAS_GATE
operator||
name|AW_CLK_HAS_MUX
operator||
name|AW_CLK_REPARENT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* flags */
end_comment

begin_expr_stmt
name|NM_CLK
argument_list|(
name|mmc2_clk
argument_list|,
name|A64_CLK_MMC2
argument_list|,
literal|"mmc2"
argument_list|,
name|mod_parents
argument_list|,
comment|/* id, name, parents */
literal|0x90
argument_list|,
comment|/* offset */
literal|16
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
name|AW_CLK_FACTOR_POWER_OF_TWO
argument_list|,
comment|/* n factor */
literal|0
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* m factor */
literal|24
argument_list|,
literal|2
argument_list|,
comment|/* mux */
literal|31
argument_list|,
comment|/* gate */
name|AW_CLK_HAS_GATE
operator||
name|AW_CLK_HAS_MUX
operator||
name|AW_CLK_REPARENT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* flags */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|ts_parents
index|[]
init|=
block|{
literal|"osc24M"
block|,
literal|"pll_periph0"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NM_CLK
argument_list|(
name|ts_clk
argument_list|,
name|A64_CLK_TS
argument_list|,
literal|"ts"
argument_list|,
name|ts_parents
argument_list|,
comment|/* id, name, parents */
literal|0x98
argument_list|,
comment|/* offset */
literal|16
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
name|AW_CLK_FACTOR_POWER_OF_TWO
argument_list|,
comment|/* n factor */
literal|0
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* m factor */
literal|24
argument_list|,
literal|2
argument_list|,
comment|/* mux */
literal|31
argument_list|,
comment|/* gate */
name|AW_CLK_HAS_GATE
operator||
name|AW_CLK_HAS_MUX
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* flags */
end_comment

begin_expr_stmt
name|NM_CLK
argument_list|(
name|ce_clk
argument_list|,
name|A64_CLK_CE
argument_list|,
literal|"ce"
argument_list|,
name|mod_parents
argument_list|,
comment|/* id, name, parents */
literal|0x9C
argument_list|,
comment|/* offset */
literal|16
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
name|AW_CLK_FACTOR_POWER_OF_TWO
argument_list|,
comment|/* n factor */
literal|0
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* m factor */
literal|24
argument_list|,
literal|2
argument_list|,
comment|/* mux */
literal|31
argument_list|,
comment|/* gate */
name|AW_CLK_HAS_GATE
operator||
name|AW_CLK_HAS_MUX
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* flags */
end_comment

begin_expr_stmt
name|NM_CLK
argument_list|(
name|spi0_clk
argument_list|,
name|A64_CLK_SPI0
argument_list|,
literal|"spi0"
argument_list|,
name|mod_parents
argument_list|,
comment|/* id, name, parents */
literal|0xA0
argument_list|,
comment|/* offset */
literal|16
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
name|AW_CLK_FACTOR_POWER_OF_TWO
argument_list|,
comment|/* n factor */
literal|0
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* m factor */
literal|24
argument_list|,
literal|2
argument_list|,
comment|/* mux */
literal|31
argument_list|,
comment|/* gate */
name|AW_CLK_HAS_GATE
operator||
name|AW_CLK_HAS_MUX
operator||
name|AW_CLK_REPARENT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* flags */
end_comment

begin_expr_stmt
name|NM_CLK
argument_list|(
name|spi1_clk
argument_list|,
name|A64_CLK_SPI1
argument_list|,
literal|"spi1"
argument_list|,
name|mod_parents
argument_list|,
comment|/* id, name, parents */
literal|0xA4
argument_list|,
comment|/* offset */
literal|16
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
name|AW_CLK_FACTOR_POWER_OF_TWO
argument_list|,
comment|/* n factor */
literal|0
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* m factor */
literal|24
argument_list|,
literal|2
argument_list|,
comment|/* mux */
literal|31
argument_list|,
comment|/* gate */
name|AW_CLK_HAS_GATE
operator||
name|AW_CLK_HAS_MUX
operator||
name|AW_CLK_REPARENT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* flags */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|i2s_parents
index|[]
init|=
block|{
literal|"pll_audio-8x"
block|,
literal|"pll_audio-4x"
block|,
literal|"pll_audio-2x"
block|,
literal|"pll_audio"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|MUX_CLK
argument_list|(
name|i2s0mux_clk
argument_list|,
literal|0
argument_list|,
literal|"i2s0mux"
argument_list|,
name|i2s_parents
argument_list|,
comment|/* id, name, parents */
literal|0xb0
argument_list|,
literal|16
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* offset, mux shift, mux width */
end_comment

begin_expr_stmt
name|MUX_CLK
argument_list|(
name|i2s1mux_clk
argument_list|,
literal|0
argument_list|,
literal|"i2s1mux"
argument_list|,
name|i2s_parents
argument_list|,
comment|/* id, name, parents */
literal|0xb4
argument_list|,
literal|16
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* offset, mux shift, mux width */
end_comment

begin_expr_stmt
name|MUX_CLK
argument_list|(
name|i2s2mux_clk
argument_list|,
literal|0
argument_list|,
literal|"i2s2mux"
argument_list|,
name|i2s_parents
argument_list|,
comment|/* id, name, parents */
literal|0xb8
argument_list|,
literal|16
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* offset, mux shift, mux width */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|spdif_parents
index|[]
init|=
block|{
literal|"pll_audio"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NM_CLK
argument_list|(
name|spdif_clk
argument_list|,
name|A64_CLK_SPDIF
argument_list|,
literal|"spdif"
argument_list|,
name|spdif_parents
argument_list|,
comment|/* id, name, parents */
literal|0xC0
argument_list|,
comment|/* offset */
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
name|AW_CLK_FACTOR_FIXED
argument_list|,
comment|/* n factor (fake); */
literal|0
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* m factor */
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* mux */
literal|31
argument_list|,
comment|/* gate */
name|AW_CLK_HAS_GATE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* flags */
end_comment

begin_comment
comment|/* USBPHY clk sel */
end_comment

begin_comment
comment|/* DRAM needs update bit */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|dram_parents
index|[]
init|=
block|{
literal|"pll_ddr0"
block|,
literal|"pll_ddr1"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NM_CLK
argument_list|(
name|dram_clk
argument_list|,
name|A64_CLK_DRAM
argument_list|,
literal|"dram"
argument_list|,
name|dram_parents
argument_list|,
comment|/* id, name, parents */
literal|0xF4
argument_list|,
comment|/* offset */
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
name|AW_CLK_FACTOR_FIXED
argument_list|,
comment|/* n factor (fake) */
literal|0
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* m factor */
literal|20
argument_list|,
literal|2
argument_list|,
comment|/* mux */
literal|0
argument_list|,
comment|/* gate */
name|AW_CLK_HAS_MUX
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* flags */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|de_parents
index|[]
init|=
block|{
literal|"pll_periph0_2x"
block|,
literal|"pll_de"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NM_CLK
argument_list|(
name|de_clk
argument_list|,
name|A64_CLK_DE
argument_list|,
literal|"de"
argument_list|,
name|de_parents
argument_list|,
comment|/* id, name, parents */
literal|0x104
argument_list|,
comment|/* offset */
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
name|AW_CLK_FACTOR_FIXED
argument_list|,
comment|/* n factor (fake) */
literal|0
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* m factor */
literal|24
argument_list|,
literal|2
argument_list|,
comment|/* mux */
literal|31
argument_list|,
comment|/* gate */
name|AW_CLK_HAS_MUX
operator||
name|AW_CLK_HAS_GATE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* flags */
end_comment

begin_comment
comment|/* TCON0/1 Needs mux table */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|deinterlace_parents
index|[]
init|=
block|{
literal|"pll_periph0"
block|,
literal|"pll_periph1"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NM_CLK
argument_list|(
name|deinterlace_clk
argument_list|,
name|A64_CLK_DEINTERLACE
argument_list|,
literal|"deinterlace"
argument_list|,
name|deinterlace_parents
argument_list|,
comment|/* id, name, parents */
literal|0x124
argument_list|,
comment|/* offset */
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
name|AW_CLK_FACTOR_FIXED
argument_list|,
comment|/* n factor (fake) */
literal|0
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* m factor */
literal|24
argument_list|,
literal|2
argument_list|,
comment|/* mux */
literal|31
argument_list|,
comment|/* gate */
name|AW_CLK_HAS_MUX
operator||
name|AW_CLK_HAS_GATE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* flags */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|csi_sclk_parents
index|[]
init|=
block|{
literal|"pll_periph0"
block|,
literal|"pll_periph1"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NM_CLK
argument_list|(
name|csi_sclk_clk
argument_list|,
name|A64_CLK_CSI_SCLK
argument_list|,
literal|"csi-sclk"
argument_list|,
name|csi_sclk_parents
argument_list|,
comment|/* id, name, parents */
literal|0x134
argument_list|,
comment|/* offset */
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
name|AW_CLK_FACTOR_FIXED
argument_list|,
comment|/* n factor (fake) */
literal|16
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* m factor */
literal|24
argument_list|,
literal|2
argument_list|,
comment|/* mux */
literal|31
argument_list|,
comment|/* gate */
name|AW_CLK_HAS_MUX
operator||
name|AW_CLK_HAS_GATE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* flags */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|csi_mclk_parents
index|[]
init|=
block|{
literal|"osc24M"
block|,
literal|"pll_video0"
block|,
literal|"pll_periph1"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NM_CLK
argument_list|(
name|csi_mclk_clk
argument_list|,
name|A64_CLK_CSI_MCLK
argument_list|,
literal|"csi-mclk"
argument_list|,
name|csi_mclk_parents
argument_list|,
comment|/* id, name, parents */
literal|0x134
argument_list|,
comment|/* offset */
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
name|AW_CLK_FACTOR_FIXED
argument_list|,
comment|/* n factor (fake) */
literal|0
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* m factor */
literal|8
argument_list|,
literal|2
argument_list|,
comment|/* mux */
literal|15
argument_list|,
comment|/* gate */
name|AW_CLK_HAS_MUX
operator||
name|AW_CLK_HAS_GATE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* flags */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|ve_parents
index|[]
init|=
block|{
literal|"pll_ve"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NM_CLK
argument_list|(
name|ve_clk
argument_list|,
name|A64_CLK_VE
argument_list|,
literal|"ve"
argument_list|,
name|ve_parents
argument_list|,
comment|/* id, name, parents */
literal|0x13C
argument_list|,
comment|/* offset */
literal|16
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* n factor */
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
name|AW_CLK_FACTOR_FIXED
argument_list|,
comment|/* m factor (fake) */
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* mux */
literal|31
argument_list|,
comment|/* gate */
name|AW_CLK_HAS_GATE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* flags */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|hdmi_parents
index|[]
init|=
block|{
literal|"pll_video0"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NM_CLK
argument_list|(
name|hdmi_clk
argument_list|,
name|A64_CLK_HDMI
argument_list|,
literal|"hdmi"
argument_list|,
name|hdmi_parents
argument_list|,
comment|/* id, name, parents */
literal|0x150
argument_list|,
comment|/* offset */
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
name|AW_CLK_FACTOR_FIXED
argument_list|,
comment|/* n factor (fake) */
literal|0
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* m factor */
literal|24
argument_list|,
literal|2
argument_list|,
comment|/* mux */
literal|31
argument_list|,
comment|/* gate */
name|AW_CLK_HAS_MUX
operator||
name|AW_CLK_HAS_GATE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* flags */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|mbus_parents
index|[]
init|=
block|{
literal|"osc24M"
block|,
literal|"pll_periph0_2x"
block|,
literal|"pll_ddr0"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NM_CLK
argument_list|(
name|mbus_clk
argument_list|,
name|A64_CLK_MBUS
argument_list|,
literal|"mbus"
argument_list|,
name|mbus_parents
argument_list|,
comment|/* id, name, parents */
literal|0x15C
argument_list|,
comment|/* offset */
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
name|AW_CLK_FACTOR_FIXED
argument_list|,
comment|/* n factor (fake) */
literal|0
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* m factor */
literal|24
argument_list|,
literal|2
argument_list|,
comment|/* mux */
literal|31
argument_list|,
comment|/* gate */
name|AW_CLK_HAS_MUX
operator||
name|AW_CLK_HAS_GATE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* flags */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|gpu_parents
index|[]
init|=
block|{
literal|"pll_gpu"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NM_CLK
argument_list|(
name|gpu_clk
argument_list|,
name|A64_CLK_GPU
argument_list|,
literal|"gpu"
argument_list|,
name|gpu_parents
argument_list|,
comment|/* id, name, parents */
literal|0x1A0
argument_list|,
comment|/* offset */
literal|0
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* n factor */
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
name|AW_CLK_FACTOR_FIXED
argument_list|,
comment|/* m factor (fake) */
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* mux */
literal|31
argument_list|,
comment|/* gate */
name|AW_CLK_HAS_GATE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* flags */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|aw_clk_nkmp_def
modifier|*
name|nkmp_clks
index|[]
init|=
block|{
operator|&
name|pll_cpux_clk
block|,
operator|&
name|pll_audio_clk
block|,
operator|&
name|pll_periph0_2x_clk
block|,
operator|&
name|pll_periph1_2x_clk
block|,
operator|&
name|pll_ddr0_clk
block|,
operator|&
name|pll_ddr1_clk
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|aw_clk_nm_def
modifier|*
name|nm_clks
index|[]
init|=
block|{
operator|&
name|pll_video0_clk
block|,
operator|&
name|pll_video1_clk
block|,
operator|&
name|pll_ve_clk
block|,
operator|&
name|pll_gpu_clk
block|,
operator|&
name|pll_de_clk
block|,
operator|&
name|pll_hsic_clk
block|,
operator|&
name|apb2_clk
block|,
operator|&
name|nand_clk
block|,
operator|&
name|mmc0_clk
block|,
operator|&
name|mmc1_clk
block|,
operator|&
name|mmc2_clk
block|,
operator|&
name|ts_clk
block|,
operator|&
name|ce_clk
block|,
operator|&
name|spi0_clk
block|,
operator|&
name|spi1_clk
block|,
operator|&
name|spdif_clk
block|,
operator|&
name|dram_clk
block|,
operator|&
name|de_clk
block|,
operator|&
name|deinterlace_clk
block|,
operator|&
name|csi_sclk_clk
block|,
operator|&
name|csi_mclk_clk
block|,
operator|&
name|ve_clk
block|,
operator|&
name|hdmi_clk
block|,
operator|&
name|mbus_clk
block|,
operator|&
name|gpu_clk
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|aw_clk_prediv_mux_def
modifier|*
name|prediv_mux_clks
index|[]
init|=
block|{
operator|&
name|ahb1_clk
block|,
operator|&
name|ahb2_clk
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|clk_mux_def
modifier|*
name|mux_clks
index|[]
init|=
block|{
operator|&
name|cpux_clk
block|,
operator|&
name|i2s0mux_clk
block|,
operator|&
name|i2s1mux_clk
block|,
operator|&
name|i2s2mux_clk
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|clk_div_def
modifier|*
name|div_clks
index|[]
init|=
block|{
operator|&
name|axi_clk
block|,
operator|&
name|apb1_clk
block|,
operator|&
name|apb_clk
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|clk_fixed_def
modifier|*
name|fixed_factor_clks
index|[]
init|=
block|{
operator|&
name|osc12m_clk
block|,
operator|&
name|pll_periph0_clk
block|,
operator|&
name|pll_periph1_clk
block|,
operator|&
name|pll_audio_2x_clk
block|,
operator|&
name|pll_audio_4x_clk
block|,
operator|&
name|pll_audio_8x_clk
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|aw_clk_init
name|init_clks
index|[]
init|=
block|{
block|{
literal|"ahb1"
block|,
literal|"pll_periph0"
block|,
literal|0
block|,
name|false
block|}
block|,
block|{
literal|"ahb2"
block|,
literal|"pll_periph0"
block|,
literal|0
block|,
name|false
block|}
block|,
block|{
literal|"dram"
block|,
literal|"pll_ddr"
block|,
literal|0
block|,
name|false
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|ccu_a64_register_clocks
parameter_list|(
name|struct
name|aw_ccung_softc
modifier|*
name|sc
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
name|sc
operator|->
name|resets
operator|=
name|a64_ccu_resets
expr_stmt|;
name|sc
operator|->
name|nresets
operator|=
name|nitems
argument_list|(
name|a64_ccu_resets
argument_list|)
expr_stmt|;
name|sc
operator|->
name|gates
operator|=
name|a64_ccu_gates
expr_stmt|;
name|sc
operator|->
name|ngates
operator|=
name|nitems
argument_list|(
name|a64_ccu_gates
argument_list|)
expr_stmt|;
name|sc
operator|->
name|clk_init
operator|=
name|init_clks
expr_stmt|;
name|sc
operator|->
name|n_clk_init
operator|=
name|nitems
argument_list|(
name|init_clks
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|nitems
argument_list|(
name|nkmp_clks
argument_list|)
condition|;
name|i
operator|++
control|)
name|aw_clk_nkmp_register
argument_list|(
name|sc
operator|->
name|clkdom
argument_list|,
name|nkmp_clks
index|[
name|i
index|]
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|nitems
argument_list|(
name|nm_clks
argument_list|)
condition|;
name|i
operator|++
control|)
name|aw_clk_nm_register
argument_list|(
name|sc
operator|->
name|clkdom
argument_list|,
name|nm_clks
index|[
name|i
index|]
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|nitems
argument_list|(
name|prediv_mux_clks
argument_list|)
condition|;
name|i
operator|++
control|)
name|aw_clk_prediv_mux_register
argument_list|(
name|sc
operator|->
name|clkdom
argument_list|,
name|prediv_mux_clks
index|[
name|i
index|]
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|nitems
argument_list|(
name|mux_clks
argument_list|)
condition|;
name|i
operator|++
control|)
name|clknode_mux_register
argument_list|(
name|sc
operator|->
name|clkdom
argument_list|,
name|mux_clks
index|[
name|i
index|]
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|nitems
argument_list|(
name|div_clks
argument_list|)
condition|;
name|i
operator|++
control|)
name|clknode_div_register
argument_list|(
name|sc
operator|->
name|clkdom
argument_list|,
name|div_clks
index|[
name|i
index|]
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|nitems
argument_list|(
name|fixed_factor_clks
argument_list|)
condition|;
name|i
operator|++
control|)
name|clknode_fixed_register
argument_list|(
name|sc
operator|->
name|clkdom
argument_list|,
name|fixed_factor_clks
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

