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
file|<dt-bindings/clock/sun6i-a31-ccu.h>
end_include

begin_include
include|#
directive|include
file|<dt-bindings/reset/sun6i-a31-ccu.h>
end_include

begin_include
include|#
directive|include
file|"ccu_a31.h"
end_include

begin_comment
comment|/* Non-exported clocks */
end_comment

begin_define
define|#
directive|define
name|CLK_PLL_CPU
value|0
end_define

begin_define
define|#
directive|define
name|CLK_PLL_AUDIO_BASE
value|1
end_define

begin_define
define|#
directive|define
name|CLK_PLL_AUDIO
value|2
end_define

begin_define
define|#
directive|define
name|CLK_PLL_AUDIO_2X
value|3
end_define

begin_define
define|#
directive|define
name|CLK_PLL_AUDIO_4X
value|4
end_define

begin_define
define|#
directive|define
name|CLK_PLL_AUDIO_8X
value|5
end_define

begin_define
define|#
directive|define
name|CLK_PLL_VIDEO0
value|6
end_define

begin_define
define|#
directive|define
name|CLK_PLL_VIDEO0_2X
value|7
end_define

begin_define
define|#
directive|define
name|CLK_PLL_VE
value|8
end_define

begin_define
define|#
directive|define
name|CLK_PLL_DDR
value|9
end_define

begin_define
define|#
directive|define
name|CLK_PLL_PERIPH_2X
value|11
end_define

begin_define
define|#
directive|define
name|CLK_PLL_VIDEO1
value|12
end_define

begin_define
define|#
directive|define
name|CLK_PLL_VIDEO1_2X
value|13
end_define

begin_define
define|#
directive|define
name|CLK_PLL_GPU
value|14
end_define

begin_define
define|#
directive|define
name|CLK_PLL_MIPI
value|15
end_define

begin_define
define|#
directive|define
name|CLK_PLL9
value|16
end_define

begin_define
define|#
directive|define
name|CLK_PLL10
value|17
end_define

begin_define
define|#
directive|define
name|CLK_AXI
value|19
end_define

begin_define
define|#
directive|define
name|CLK_AHB1
value|20
end_define

begin_define
define|#
directive|define
name|CLK_APB1
value|21
end_define

begin_define
define|#
directive|define
name|CLK_APB2
value|22
end_define

begin_define
define|#
directive|define
name|CLK_MDFS
value|107
end_define

begin_define
define|#
directive|define
name|CLK_SDRAM0
value|108
end_define

begin_define
define|#
directive|define
name|CLK_SDRAM1
value|109
end_define

begin_define
define|#
directive|define
name|CLK_MBUS0
value|141
end_define

begin_define
define|#
directive|define
name|CLK_MBUS1
value|142
end_define

begin_decl_stmt
specifier|static
name|struct
name|aw_ccung_reset
name|a31_ccu_resets
index|[]
init|=
block|{
name|CCU_RESET
argument_list|(
argument|RST_USB_PHY0
argument_list|,
literal|0xcc
argument_list|,
literal|0
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_USB_PHY1
argument_list|,
literal|0xcc
argument_list|,
literal|1
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_USB_PHY2
argument_list|,
literal|0xcc
argument_list|,
literal|2
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_AHB1_MIPI_DSI
argument_list|,
literal|0x2c0
argument_list|,
literal|1
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_AHB1_SS
argument_list|,
literal|0x2c0
argument_list|,
literal|5
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_AHB1_DMA
argument_list|,
literal|0x2c0
argument_list|,
literal|6
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_AHB1_MMC0
argument_list|,
literal|0x2c0
argument_list|,
literal|8
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_AHB1_MMC1
argument_list|,
literal|0x2c0
argument_list|,
literal|9
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_AHB1_MMC2
argument_list|,
literal|0x2c0
argument_list|,
literal|10
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_AHB1_MMC3
argument_list|,
literal|0x2c0
argument_list|,
literal|11
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_AHB1_NAND1
argument_list|,
literal|0x2c0
argument_list|,
literal|12
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_AHB1_NAND0
argument_list|,
literal|0x2c0
argument_list|,
literal|13
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_AHB1_SDRAM
argument_list|,
literal|0x2c0
argument_list|,
literal|14
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_AHB1_EMAC
argument_list|,
literal|0x2c0
argument_list|,
literal|17
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_AHB1_TS
argument_list|,
literal|0x2c0
argument_list|,
literal|18
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_AHB1_HSTIMER
argument_list|,
literal|0x2c0
argument_list|,
literal|19
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_AHB1_SPI0
argument_list|,
literal|0x2c0
argument_list|,
literal|20
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_AHB1_SPI1
argument_list|,
literal|0x2c0
argument_list|,
literal|21
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_AHB1_SPI2
argument_list|,
literal|0x2c0
argument_list|,
literal|22
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_AHB1_SPI3
argument_list|,
literal|0x2c0
argument_list|,
literal|23
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_AHB1_OTG
argument_list|,
literal|0x2c0
argument_list|,
literal|24
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_AHB1_EHCI0
argument_list|,
literal|0x2c0
argument_list|,
literal|26
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_AHB1_EHCI1
argument_list|,
literal|0x2c0
argument_list|,
literal|27
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_AHB1_OHCI0
argument_list|,
literal|0x2c0
argument_list|,
literal|29
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_AHB1_OHCI1
argument_list|,
literal|0x2c0
argument_list|,
literal|30
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_AHB1_OHCI2
argument_list|,
literal|0x2c0
argument_list|,
literal|31
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_AHB1_VE
argument_list|,
literal|0x2c4
argument_list|,
literal|0
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_AHB1_LCD0
argument_list|,
literal|0x2c4
argument_list|,
literal|4
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_AHB1_LCD1
argument_list|,
literal|0x2c4
argument_list|,
literal|5
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_AHB1_CSI
argument_list|,
literal|0x2c4
argument_list|,
literal|8
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_AHB1_HDMI
argument_list|,
literal|0x2c4
argument_list|,
literal|11
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_AHB1_BE0
argument_list|,
literal|0x2c4
argument_list|,
literal|12
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_AHB1_BE1
argument_list|,
literal|0x2c4
argument_list|,
literal|13
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_AHB1_FE0
argument_list|,
literal|0x2c4
argument_list|,
literal|14
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_AHB1_FE1
argument_list|,
literal|0x2c4
argument_list|,
literal|15
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_AHB1_MP
argument_list|,
literal|0x2c4
argument_list|,
literal|18
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_AHB1_GPU
argument_list|,
literal|0x2c4
argument_list|,
literal|20
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_AHB1_DEU0
argument_list|,
literal|0x2c4
argument_list|,
literal|23
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_AHB1_DEU1
argument_list|,
literal|0x2c4
argument_list|,
literal|24
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_AHB1_DRC0
argument_list|,
literal|0x2c4
argument_list|,
literal|25
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_AHB1_DRC1
argument_list|,
literal|0x2c4
argument_list|,
literal|26
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_AHB1_LVDS
argument_list|,
literal|0x2c8
argument_list|,
literal|0
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_APB1_CODEC
argument_list|,
literal|0x2d0
argument_list|,
literal|0
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_APB1_SPDIF
argument_list|,
literal|0x2d0
argument_list|,
literal|1
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_APB1_DIGITAL_MIC
argument_list|,
literal|0x2d0
argument_list|,
literal|4
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_APB1_DAUDIO0
argument_list|,
literal|0x2d0
argument_list|,
literal|12
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_APB1_DAUDIO1
argument_list|,
literal|0x2d0
argument_list|,
literal|13
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_APB2_I2C0
argument_list|,
literal|0x2d8
argument_list|,
literal|0
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_APB2_I2C1
argument_list|,
literal|0x2d8
argument_list|,
literal|1
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_APB2_I2C2
argument_list|,
literal|0x2d8
argument_list|,
literal|2
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_APB2_I2C3
argument_list|,
literal|0x2d8
argument_list|,
literal|3
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_APB2_UART0
argument_list|,
literal|0x2d8
argument_list|,
literal|16
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_APB2_UART1
argument_list|,
literal|0x2d8
argument_list|,
literal|17
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_APB2_UART2
argument_list|,
literal|0x2d8
argument_list|,
literal|18
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_APB2_UART3
argument_list|,
literal|0x2d8
argument_list|,
literal|19
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_APB2_UART4
argument_list|,
literal|0x2d8
argument_list|,
literal|20
argument_list|)
name|CCU_RESET
argument_list|(
argument|RST_APB2_UART5
argument_list|,
literal|0x2d8
argument_list|,
literal|21
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|aw_ccung_gate
name|a31_ccu_gates
index|[]
init|=
block|{
name|CCU_GATE
argument_list|(
argument|CLK_AHB1_MIPIDSI
argument_list|,
literal|"ahb1-mipidsi"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x60
argument_list|,
literal|1
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_AHB1_SS
argument_list|,
literal|"ahb1-ss"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x60
argument_list|,
literal|5
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_AHB1_DMA
argument_list|,
literal|"ahb1-dma"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x60
argument_list|,
literal|6
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_AHB1_MMC0
argument_list|,
literal|"ahb1-mmc0"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x60
argument_list|,
literal|8
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_AHB1_MMC1
argument_list|,
literal|"ahb1-mmc1"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x60
argument_list|,
literal|9
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_AHB1_MMC2
argument_list|,
literal|"ahb1-mmc2"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x60
argument_list|,
literal|10
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_AHB1_MMC3
argument_list|,
literal|"ahb1-mmc3"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x60
argument_list|,
literal|11
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_AHB1_NAND1
argument_list|,
literal|"ahb1-nand1"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x60
argument_list|,
literal|12
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_AHB1_NAND0
argument_list|,
literal|"ahb1-nand0"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x60
argument_list|,
literal|13
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_AHB1_SDRAM
argument_list|,
literal|"ahb1-sdram"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x60
argument_list|,
literal|14
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_AHB1_EMAC
argument_list|,
literal|"ahb1-emac"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x60
argument_list|,
literal|17
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_AHB1_TS
argument_list|,
literal|"ahb1-ts"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x60
argument_list|,
literal|18
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_AHB1_HSTIMER
argument_list|,
literal|"ahb1-hstimer"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x60
argument_list|,
literal|19
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_AHB1_SPI0
argument_list|,
literal|"ahb1-spi0"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x60
argument_list|,
literal|20
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_AHB1_SPI1
argument_list|,
literal|"ahb1-spi1"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x60
argument_list|,
literal|21
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_AHB1_SPI2
argument_list|,
literal|"ahb1-spi2"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x60
argument_list|,
literal|22
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_AHB1_SPI3
argument_list|,
literal|"ahb1-spi3"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x60
argument_list|,
literal|23
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_AHB1_OTG
argument_list|,
literal|"ahb1-otg"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x60
argument_list|,
literal|24
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_AHB1_EHCI0
argument_list|,
literal|"ahb1-ehci0"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x60
argument_list|,
literal|26
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_AHB1_EHCI1
argument_list|,
literal|"ahb1-ehci1"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x60
argument_list|,
literal|27
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_AHB1_OHCI0
argument_list|,
literal|"ahb1-ohci0"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x60
argument_list|,
literal|29
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_AHB1_OHCI1
argument_list|,
literal|"ahb1-ohci1"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x60
argument_list|,
literal|30
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_AHB1_OHCI2
argument_list|,
literal|"ahb1-ohci2"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x60
argument_list|,
literal|31
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_AHB1_VE
argument_list|,
literal|"ahb1-ve"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x64
argument_list|,
literal|0
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_AHB1_LCD0
argument_list|,
literal|"ahb1-lcd0"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x64
argument_list|,
literal|4
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_AHB1_LCD1
argument_list|,
literal|"ahb1-lcd1"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x64
argument_list|,
literal|5
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_AHB1_CSI
argument_list|,
literal|"ahb1-csi"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x64
argument_list|,
literal|8
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_AHB1_HDMI
argument_list|,
literal|"ahb1-hdmi"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x64
argument_list|,
literal|11
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_AHB1_BE0
argument_list|,
literal|"ahb1-be0"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x64
argument_list|,
literal|12
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_AHB1_BE1
argument_list|,
literal|"ahb1-be1"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x64
argument_list|,
literal|13
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_AHB1_FE0
argument_list|,
literal|"ahb1-fe0"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x64
argument_list|,
literal|14
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_AHB1_FE1
argument_list|,
literal|"ahb1-fe1"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x64
argument_list|,
literal|15
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_AHB1_MP
argument_list|,
literal|"ahb1-mp"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x64
argument_list|,
literal|18
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_AHB1_GPU
argument_list|,
literal|"ahb1-gpu"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x64
argument_list|,
literal|20
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_AHB1_DEU0
argument_list|,
literal|"ahb1-deu0"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x64
argument_list|,
literal|23
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_AHB1_DEU1
argument_list|,
literal|"ahb1-deu1"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x64
argument_list|,
literal|24
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_AHB1_DRC0
argument_list|,
literal|"ahb1-drc0"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x64
argument_list|,
literal|25
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_AHB1_DRC1
argument_list|,
literal|"ahb1-drc1"
argument_list|,
literal|"ahb1"
argument_list|,
literal|0x64
argument_list|,
literal|26
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_APB1_CODEC
argument_list|,
literal|"apb1-codec"
argument_list|,
literal|"apb1"
argument_list|,
literal|0x68
argument_list|,
literal|0
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_APB1_SPDIF
argument_list|,
literal|"apb1-spdif"
argument_list|,
literal|"apb1"
argument_list|,
literal|0x68
argument_list|,
literal|1
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_APB1_DIGITAL_MIC
argument_list|,
literal|"apb1-digital-mic"
argument_list|,
literal|"apb1"
argument_list|,
literal|0x68
argument_list|,
literal|4
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_APB1_PIO
argument_list|,
literal|"apb1-pio"
argument_list|,
literal|"apb1"
argument_list|,
literal|0x68
argument_list|,
literal|5
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_APB1_DAUDIO0
argument_list|,
literal|"apb1-daudio0"
argument_list|,
literal|"apb1"
argument_list|,
literal|0x68
argument_list|,
literal|12
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_APB1_DAUDIO1
argument_list|,
literal|"apb1-daudio1"
argument_list|,
literal|"apb1"
argument_list|,
literal|0x68
argument_list|,
literal|13
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_APB2_I2C0
argument_list|,
literal|"apb2-i2c0"
argument_list|,
literal|"apb2"
argument_list|,
literal|0x6c
argument_list|,
literal|0
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_APB2_I2C1
argument_list|,
literal|"apb2-i2c1"
argument_list|,
literal|"apb2"
argument_list|,
literal|0x6c
argument_list|,
literal|1
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_APB2_I2C2
argument_list|,
literal|"apb2-i2c2"
argument_list|,
literal|"apb2"
argument_list|,
literal|0x6c
argument_list|,
literal|2
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_APB2_I2C3
argument_list|,
literal|"apb2-i2c3"
argument_list|,
literal|"apb2"
argument_list|,
literal|0x6c
argument_list|,
literal|3
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_APB2_UART0
argument_list|,
literal|"apb2-uart0"
argument_list|,
literal|"apb2"
argument_list|,
literal|0x6c
argument_list|,
literal|16
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_APB2_UART1
argument_list|,
literal|"apb2-uart1"
argument_list|,
literal|"apb2"
argument_list|,
literal|0x6c
argument_list|,
literal|17
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_APB2_UART2
argument_list|,
literal|"apb2-uart2"
argument_list|,
literal|"apb2"
argument_list|,
literal|0x6c
argument_list|,
literal|18
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_APB2_UART3
argument_list|,
literal|"apb2-uart3"
argument_list|,
literal|"apb2"
argument_list|,
literal|0x6c
argument_list|,
literal|19
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_APB2_UART4
argument_list|,
literal|"apb2-uart4"
argument_list|,
literal|"apb2"
argument_list|,
literal|0x6c
argument_list|,
literal|20
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_APB2_UART5
argument_list|,
literal|"apb2-uart5"
argument_list|,
literal|"apb2"
argument_list|,
literal|0x6c
argument_list|,
literal|21
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_DAUDIO0
argument_list|,
literal|"daudio0"
argument_list|,
literal|"daudio0mux"
argument_list|,
literal|0xb0
argument_list|,
literal|31
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_DAUDIO1
argument_list|,
literal|"daudio1"
argument_list|,
literal|"daudio1mux"
argument_list|,
literal|0xb4
argument_list|,
literal|31
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_USB_PHY0
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
argument|CLK_USB_PHY1
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
argument|CLK_USB_PHY2
argument_list|,
literal|"usb-phy2"
argument_list|,
literal|"osc24M"
argument_list|,
literal|0xcc
argument_list|,
literal|10
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_USB_OHCI0
argument_list|,
literal|"usb-ohci0"
argument_list|,
literal|"osc24M"
argument_list|,
literal|0xcc
argument_list|,
literal|16
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_USB_OHCI1
argument_list|,
literal|"usb-ohci1"
argument_list|,
literal|"osc24M"
argument_list|,
literal|0xcc
argument_list|,
literal|17
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_USB_OHCI2
argument_list|,
literal|"usb-ohci2"
argument_list|,
literal|"osc24M"
argument_list|,
literal|0xcc
argument_list|,
literal|18
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_DRAM_VE
argument_list|,
literal|"dram-ve"
argument_list|,
literal|"mdfs"
argument_list|,
literal|0x100
argument_list|,
literal|0
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_DRAM_CSI_ISP
argument_list|,
literal|"dram-csi_isp"
argument_list|,
literal|"mdfs"
argument_list|,
literal|0x100
argument_list|,
literal|1
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_DRAM_TS
argument_list|,
literal|"dram-ts"
argument_list|,
literal|"mdfs"
argument_list|,
literal|0x100
argument_list|,
literal|3
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_DRAM_DRC0
argument_list|,
literal|"dram-drc0"
argument_list|,
literal|"mdfs"
argument_list|,
literal|0x100
argument_list|,
literal|16
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_DRAM_DRC1
argument_list|,
literal|"dram-drc1"
argument_list|,
literal|"mdfs"
argument_list|,
literal|0x100
argument_list|,
literal|17
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_DRAM_DEU0
argument_list|,
literal|"dram-deu0"
argument_list|,
literal|"mdfs"
argument_list|,
literal|0x100
argument_list|,
literal|18
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_DRAM_DEU1
argument_list|,
literal|"dram-deu1"
argument_list|,
literal|"mdfs"
argument_list|,
literal|0x100
argument_list|,
literal|19
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_DRAM_FE0
argument_list|,
literal|"dram-fe0"
argument_list|,
literal|"mdfs"
argument_list|,
literal|0x100
argument_list|,
literal|24
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_DRAM_FE1
argument_list|,
literal|"dram-fe1"
argument_list|,
literal|"mdfs"
argument_list|,
literal|0x100
argument_list|,
literal|25
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_DRAM_BE0
argument_list|,
literal|"dram-be0"
argument_list|,
literal|"mdfs"
argument_list|,
literal|0x100
argument_list|,
literal|26
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_DRAM_BE1
argument_list|,
literal|"dram-be1"
argument_list|,
literal|"mdfs"
argument_list|,
literal|0x100
argument_list|,
literal|27
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_DRAM_MP
argument_list|,
literal|"dram-mp"
argument_list|,
literal|"mdfs"
argument_list|,
literal|0x100
argument_list|,
literal|28
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_CODEC
argument_list|,
literal|"codec"
argument_list|,
literal|"pll_audio"
argument_list|,
literal|0x140
argument_list|,
literal|31
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_AVS
argument_list|,
literal|"avs"
argument_list|,
literal|"pll_audio"
argument_list|,
literal|0x144
argument_list|,
literal|31
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_DIGITAL_MIC
argument_list|,
literal|"digital-mic"
argument_list|,
literal|"pll_audio"
argument_list|,
literal|0x148
argument_list|,
literal|31
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_HDMI_DDC
argument_list|,
literal|"hdmi-ddc"
argument_list|,
literal|"osc24M"
argument_list|,
literal|0x150
argument_list|,
literal|30
argument_list|)
name|CCU_GATE
argument_list|(
argument|CLK_PS
argument_list|,
literal|"ps"
argument_list|,
literal|"lcd1_ch1"
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
name|pll_parents
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
name|pll_cpu_clk
argument_list|,
name|CLK_PLL_CPU
argument_list|,
comment|/* id */
literal|"pll_cpu"
argument_list|,
name|pll_parents
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
operator||
name|AW_CLK_SCALE_CHANGE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* flags */
end_comment

begin_expr_stmt
name|NKMP_CLK
argument_list|(
name|pll_audio_clk
argument_list|,
name|CLK_PLL_AUDIO
argument_list|,
comment|/* id */
literal|"pll_audio"
argument_list|,
name|pll_parents
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
literal|4
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
comment|/* m factor */
literal|16
argument_list|,
literal|3
argument_list|,
literal|1
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
name|CLK_PLL_AUDIO_2X
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
name|CLK_PLL_AUDIO_4X
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
name|CLK_PLL_AUDIO_8X
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

begin_expr_stmt
name|NM_CLK_WITH_FRAC
argument_list|(
name|pll_video0_clk
argument_list|,
name|CLK_PLL_VIDEO0
argument_list|,
comment|/* id */
literal|"pll_video0"
argument_list|,
name|pll_parents
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
name|pll_video0_2x_parents
index|[]
init|=
block|{
literal|"pll_video0"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|FIXED_CLK
argument_list|(
name|pll_video0_2x_clk
argument_list|,
name|CLK_PLL_VIDEO0_2X
argument_list|,
comment|/* id */
literal|"pll_video0-2x"
argument_list|,
comment|/* name */
name|pll_video0_2x_parents
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
name|NM_CLK_WITH_FRAC
argument_list|(
name|pll_ve_clk
argument_list|,
name|CLK_PLL_VE
argument_list|,
comment|/* id */
literal|"pll_ve"
argument_list|,
name|pll_parents
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

begin_expr_stmt
name|NKMP_CLK_WITH_UPDATE
argument_list|(
name|pll_ddr_clk
argument_list|,
name|CLK_PLL_DDR
argument_list|,
comment|/* id */
literal|"pll_ddr"
argument_list|,
name|pll_parents
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

begin_expr_stmt
name|NKMP_CLK
argument_list|(
name|pll_periph_clk
argument_list|,
name|CLK_PLL_PERIPH
argument_list|,
comment|/* id */
literal|"pll_periph"
argument_list|,
name|pll_parents
argument_list|,
comment|/* name, parents */
literal|0x28
argument_list|,
comment|/* offset */
literal|8
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* n factor */
literal|5
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
comment|/* k factor */
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

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|pll_periph_2x_parents
index|[]
init|=
block|{
literal|"pll_periph"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|FIXED_CLK
argument_list|(
name|pll_periph_2x_clk
argument_list|,
name|CLK_PLL_PERIPH_2X
argument_list|,
comment|/* id */
literal|"pll_periph-2x"
argument_list|,
comment|/* name */
name|pll_periph_2x_parents
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
name|NM_CLK_WITH_FRAC
argument_list|(
name|pll_video1_clk
argument_list|,
name|CLK_PLL_VIDEO1
argument_list|,
comment|/* id */
literal|"pll_video1"
argument_list|,
name|pll_parents
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
name|pll_video1_2x_parents
index|[]
init|=
block|{
literal|"pll_video1"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|FIXED_CLK
argument_list|(
name|pll_video1_2x_clk
argument_list|,
name|CLK_PLL_VIDEO1_2X
argument_list|,
comment|/* id */
literal|"pll_video1-2x"
argument_list|,
comment|/* name */
name|pll_video1_2x_parents
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
name|NM_CLK_WITH_FRAC
argument_list|(
name|pll_gpu_clk
argument_list|,
name|CLK_PLL_GPU
argument_list|,
comment|/* id */
literal|"pll_gpu"
argument_list|,
name|pll_parents
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

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|pll_mipi_parents
index|[]
init|=
block|{
literal|"pll_video0"
block|,
literal|"pll_video1"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NKMP_CLK
argument_list|(
name|pll_mipi_clk
argument_list|,
name|CLK_PLL_MIPI
argument_list|,
comment|/* id */
literal|"pll_mipi"
argument_list|,
name|pll_mipi_parents
argument_list|,
comment|/* name, parents */
literal|0x40
argument_list|,
comment|/* offset */
literal|8
argument_list|,
literal|4
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
literal|1
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
name|NM_CLK_WITH_FRAC
argument_list|(
name|pll9_clk
argument_list|,
name|CLK_PLL9
argument_list|,
comment|/* id */
literal|"pll9"
argument_list|,
name|pll_parents
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

begin_expr_stmt
name|NM_CLK_WITH_FRAC
argument_list|(
name|pll10_clk
argument_list|,
name|CLK_PLL10
argument_list|,
comment|/* id */
literal|"pll10"
argument_list|,
name|pll_parents
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
name|struct
name|clk_div_table
name|axi_div_table
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
literal|1
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
literal|3
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
literal|4
block|, }
block|,
block|{
operator|.
name|value
operator|=
literal|4
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
literal|5
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
literal|6
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
literal|7
block|,
operator|.
name|divider
operator|=
literal|4
block|, }
block|,
block|{ }
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|axi_parents
index|[]
init|=
block|{
literal|"cpu"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DIV_CLK
argument_list|(
name|axi_clk
argument_list|,
name|CLK_AXI
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
comment|/* shift, mask */
literal|0
argument_list|,
name|axi_div_table
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
name|cpu_parents
index|[]
init|=
block|{
literal|"osc32k"
block|,
literal|"osc24M"
block|,
literal|"pll_cpu"
block|,
literal|"pll_cpu"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|MUX_CLK
argument_list|(
name|cpu_clk
argument_list|,
name|CLK_CPU
argument_list|,
comment|/* id */
literal|"cpu"
argument_list|,
name|cpu_parents
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
literal|"pll_periph"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|PREDIV_CLK
argument_list|(
name|ahb1_clk
argument_list|,
name|CLK_AHB1
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
name|CLK_APB1
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
comment|/* shift, mask */
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
literal|"pll_periph"
block|,
literal|"pll_periph"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NM_CLK
argument_list|(
name|apb2_clk
argument_list|,
name|CLK_APB2
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
name|mod_parents
index|[]
init|=
block|{
literal|"osc24M"
block|,
literal|"pll_periph"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NM_CLK
argument_list|(
name|nand0_clk
argument_list|,
name|CLK_NAND0
argument_list|,
literal|"nand0"
argument_list|,
name|mod_parents
argument_list|,
comment|/* id, name, parents */
literal|0x80
argument_list|,
comment|/* offset */
literal|16
argument_list|,
literal|3
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
name|nand1_clk
argument_list|,
name|CLK_NAND1
argument_list|,
literal|"nand1"
argument_list|,
name|mod_parents
argument_list|,
comment|/* id, name, parents */
literal|0x80
argument_list|,
comment|/* offset */
literal|16
argument_list|,
literal|3
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
name|CLK_MMC0
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
name|CLK_MMC1
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
name|CLK_MMC2
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

begin_expr_stmt
name|NM_CLK
argument_list|(
name|mmc3_clk
argument_list|,
name|CLK_MMC2
argument_list|,
literal|"mmc3"
argument_list|,
name|mod_parents
argument_list|,
comment|/* id, name, parents */
literal|0x94
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
literal|"pll_periph"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NM_CLK
argument_list|(
name|ts_clk
argument_list|,
name|CLK_TS
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
literal|4
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
name|ss_clk
argument_list|,
name|CLK_SS
argument_list|,
literal|"ss"
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
literal|4
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
name|CLK_SPI0
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
literal|4
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
name|spi1_clk
argument_list|,
name|CLK_SPI1
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
literal|4
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
name|spi2_clk
argument_list|,
name|CLK_SPI2
argument_list|,
literal|"spi2"
argument_list|,
name|mod_parents
argument_list|,
comment|/* id, name, parents */
literal|0xA8
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
literal|4
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
name|spi3_clk
argument_list|,
name|CLK_SPI3
argument_list|,
literal|"spi3"
argument_list|,
name|mod_parents
argument_list|,
comment|/* id, name, parents */
literal|0xAC
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
literal|4
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

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|daudio_parents
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
name|daudio0mux_clk
argument_list|,
literal|0
argument_list|,
literal|"daudio0mux"
argument_list|,
name|daudio_parents
argument_list|,
literal|0xb0
argument_list|,
literal|16
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MUX_CLK
argument_list|(
name|daudio1mux_clk
argument_list|,
literal|0
argument_list|,
literal|"daudio1mux"
argument_list|,
name|daudio_parents
argument_list|,
literal|0xb4
argument_list|,
literal|16
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|mdfs_parents
index|[]
init|=
block|{
literal|"pll_ddr"
block|,
literal|"pll_periph"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NM_CLK
argument_list|(
name|mdfs_clk
argument_list|,
name|CLK_MDFS
argument_list|,
literal|"mdfs"
argument_list|,
name|mdfs_parents
argument_list|,
comment|/* id, name, parents */
literal|0xF0
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
literal|4
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

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|dram_parents
index|[]
init|=
block|{
literal|"pll_ddr"
block|,
literal|"pll_periph"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NM_CLK
argument_list|(
name|sdram0_clk
argument_list|,
name|CLK_SDRAM0
argument_list|,
literal|"sdram0"
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
literal|4
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* m factor */
literal|4
argument_list|,
literal|1
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

begin_expr_stmt
name|NM_CLK
argument_list|(
name|sdram1_clk
argument_list|,
name|CLK_SDRAM1
argument_list|,
literal|"sdram1"
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
literal|8
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* m factor */
literal|12
argument_list|,
literal|1
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
name|befe_parents
index|[]
init|=
block|{
literal|"pll_video0"
block|,
literal|"pll_video1"
block|,
literal|"pll_periph-2x"
block|,
literal|"pll_gpu"
block|,
literal|"pll9"
block|,
literal|"pll10"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NM_CLK
argument_list|(
name|be0_clk
argument_list|,
name|CLK_BE0
argument_list|,
literal|"be0"
argument_list|,
name|befe_parents
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
literal|3
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

begin_expr_stmt
name|NM_CLK
argument_list|(
name|be1_clk
argument_list|,
name|CLK_BE1
argument_list|,
literal|"be1"
argument_list|,
name|befe_parents
argument_list|,
comment|/* id, name, parents */
literal|0x108
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
literal|3
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

begin_expr_stmt
name|NM_CLK
argument_list|(
name|fe0_clk
argument_list|,
name|CLK_FE0
argument_list|,
literal|"fe0"
argument_list|,
name|befe_parents
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
literal|3
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

begin_expr_stmt
name|NM_CLK
argument_list|(
name|fe1_clk
argument_list|,
name|CLK_FE1
argument_list|,
literal|"fe1"
argument_list|,
name|befe_parents
argument_list|,
comment|/* id, name, parents */
literal|0x108
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
literal|3
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
name|mp_parents
index|[]
init|=
block|{
literal|"pll_video0"
block|,
literal|"pll_video1"
block|,
literal|"pll9"
block|,
literal|"pll10"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NM_CLK
argument_list|(
name|mp_clk
argument_list|,
name|CLK_MP
argument_list|,
literal|"mp"
argument_list|,
name|mp_parents
argument_list|,
comment|/* id, name, parents */
literal|0x108
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
literal|3
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
name|lcd_ch0_parents
index|[]
init|=
block|{
literal|"pll_video0"
block|,
literal|"pll_video1"
block|,
literal|"pll_video0-2x"
block|,
literal|"pll_video1-2x"
block|,
literal|"pll_mipi"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NM_CLK
argument_list|(
name|lcd0_ch0_clk
argument_list|,
name|CLK_LCD0_CH0
argument_list|,
literal|"lcd0_ch0"
argument_list|,
name|lcd_ch0_parents
argument_list|,
comment|/* id, name, parents */
literal|0x118
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
literal|0
argument_list|,
literal|1
argument_list|,
name|AW_CLK_FACTOR_FIXED
argument_list|,
comment|/* m factor (fake )*/
literal|24
argument_list|,
literal|3
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

begin_expr_stmt
name|NM_CLK
argument_list|(
name|lcd1_ch0_clk
argument_list|,
name|CLK_LCD1_CH0
argument_list|,
literal|"lcd1_ch0"
argument_list|,
name|lcd_ch0_parents
argument_list|,
comment|/* id, name, parents */
literal|0x11C
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
literal|0
argument_list|,
literal|1
argument_list|,
name|AW_CLK_FACTOR_FIXED
argument_list|,
comment|/* m factor (fake )*/
literal|24
argument_list|,
literal|3
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
name|lcd_ch1_parents
index|[]
init|=
block|{
literal|"pll_video0"
block|,
literal|"pll_video1"
block|,
literal|"pll_video0-2x"
block|,
literal|"pll_video1-2x"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NM_CLK
argument_list|(
name|lcd0_ch1_clk
argument_list|,
name|CLK_LCD0_CH1
argument_list|,
literal|"lcd0_ch1"
argument_list|,
name|lcd_ch1_parents
argument_list|,
comment|/* id, name, parents */
literal|0x12C
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
literal|3
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

begin_expr_stmt
name|NM_CLK
argument_list|(
name|lcd1_ch1_clk
argument_list|,
name|CLK_LCD1_CH1
argument_list|,
literal|"lcd1_ch1"
argument_list|,
name|lcd_ch1_parents
argument_list|,
comment|/* id, name, parents */
literal|0x130
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
literal|3
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
comment|/* CSI0 0x134 Need Mux table */
end_comment

begin_comment
comment|/* CSI1 0x138 Need Mux table */
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
name|CLK_VE
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

begin_expr_stmt
name|NM_CLK
argument_list|(
name|hdmi_clk
argument_list|,
name|CLK_HDMI
argument_list|,
literal|"hdmi"
argument_list|,
name|lcd_ch1_parents
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
name|mbus_parents
index|[]
init|=
block|{
literal|"osc24M"
block|,
literal|"pll_periph"
block|,
literal|"pll_ddr"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NM_CLK
argument_list|(
name|mbus0_clk
argument_list|,
name|CLK_MBUS0
argument_list|,
literal|"mbus0"
argument_list|,
name|mbus_parents
argument_list|,
comment|/* id, name, parents */
literal|0x15C
argument_list|,
comment|/* offset */
literal|16
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

begin_expr_stmt
name|NM_CLK
argument_list|(
name|mbus1_clk
argument_list|,
name|CLK_MBUS1
argument_list|,
literal|"mbus1"
argument_list|,
name|mbus_parents
argument_list|,
comment|/* id, name, parents */
literal|0x160
argument_list|,
comment|/* offset */
literal|16
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
name|mipi_parents
index|[]
init|=
block|{
literal|"pll_video0"
block|,
literal|"pll_video1"
block|,
literal|"pll_video0-2x"
block|,
literal|"pll_video1-2x"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NM_CLK
argument_list|(
name|mipi_dsi_clk
argument_list|,
name|CLK_MIPI_DSI
argument_list|,
literal|"mipi_dsi"
argument_list|,
name|mipi_parents
argument_list|,
comment|/* id, name, parents */
literal|0x168
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

begin_expr_stmt
name|NM_CLK
argument_list|(
name|mipi_dsi_dphy_clk
argument_list|,
name|CLK_MIPI_DSI_DPHY
argument_list|,
literal|"mipi_dsi_dphy"
argument_list|,
name|mipi_parents
argument_list|,
comment|/* id, name, parents */
literal|0x168
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

begin_expr_stmt
name|NM_CLK
argument_list|(
name|mipi_csi_dphy_clk
argument_list|,
name|CLK_MIPI_CSI_DPHY
argument_list|,
literal|"mipi_csi_dphy"
argument_list|,
name|mipi_parents
argument_list|,
comment|/* id, name, parents */
literal|0x16C
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
name|iep_parents
index|[]
init|=
block|{
literal|"pll_video0"
block|,
literal|"pll_video1"
block|,
literal|"pll_periph-2x"
block|,
literal|"pll_gpu"
block|,
literal|"pll9"
block|,
literal|"pll10"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NM_CLK
argument_list|(
name|iep_drc0_clk
argument_list|,
name|CLK_IEP_DRC0
argument_list|,
literal|"iep_drc0"
argument_list|,
name|iep_parents
argument_list|,
comment|/* id, name, parents */
literal|0x180
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

begin_expr_stmt
name|NM_CLK
argument_list|(
name|iep_drc1_clk
argument_list|,
name|CLK_IEP_DRC1
argument_list|,
literal|"iep_drc1"
argument_list|,
name|iep_parents
argument_list|,
comment|/* id, name, parents */
literal|0x184
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

begin_expr_stmt
name|NM_CLK
argument_list|(
name|iep_deu0_clk
argument_list|,
name|CLK_IEP_DEU0
argument_list|,
literal|"iep_deu0"
argument_list|,
name|iep_parents
argument_list|,
comment|/* id, name, parents */
literal|0x188
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

begin_expr_stmt
name|NM_CLK
argument_list|(
name|iep_deu1_clk
argument_list|,
name|CLK_IEP_DEU1
argument_list|,
literal|"iep_deu1"
argument_list|,
name|iep_parents
argument_list|,
comment|/* id, name, parents */
literal|0x18C
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
name|gpu_parents
index|[]
init|=
block|{
literal|"pll_gpu"
block|,
literal|"pll_periph-2x"
block|,
literal|"pll_video0"
block|,
literal|"pll_video1"
block|,
literal|"pll9"
block|,
literal|"pll10"
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|PREDIV_CLK
argument_list|(
name|gpu_core_clk
argument_list|,
name|CLK_GPU_CORE
argument_list|,
comment|/* id */
literal|"gpu_core"
argument_list|,
name|gpu_parents
argument_list|,
comment|/* name, parents */
literal|0x1A0
argument_list|,
comment|/* offset */
literal|24
argument_list|,
literal|3
argument_list|,
comment|/* mux */
literal|0
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* div */
literal|0
argument_list|,
literal|0
argument_list|,
literal|3
argument_list|,
name|AW_CLK_FACTOR_HAS_COND
operator||
name|AW_CLK_FACTOR_FIXED
argument_list|,
comment|/* prediv */
literal|24
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

begin_expr_stmt
name|PREDIV_CLK
argument_list|(
name|gpu_memory_clk
argument_list|,
name|CLK_GPU_MEMORY
argument_list|,
comment|/* id */
literal|"gpu_memory"
argument_list|,
name|gpu_parents
argument_list|,
comment|/* name, parents */
literal|0x1A4
argument_list|,
comment|/* offset */
literal|24
argument_list|,
literal|3
argument_list|,
comment|/* mux */
literal|0
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* div */
literal|0
argument_list|,
literal|0
argument_list|,
literal|3
argument_list|,
name|AW_CLK_FACTOR_HAS_COND
operator||
name|AW_CLK_FACTOR_FIXED
argument_list|,
comment|/* prediv */
literal|24
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

begin_expr_stmt
name|PREDIV_CLK
argument_list|(
name|gpu_hyd_clk
argument_list|,
name|CLK_GPU_HYD
argument_list|,
comment|/* id */
literal|"gpu_hyd"
argument_list|,
name|gpu_parents
argument_list|,
comment|/* name, parents */
literal|0x1A8
argument_list|,
comment|/* offset */
literal|24
argument_list|,
literal|3
argument_list|,
comment|/* mux */
literal|0
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* div */
literal|0
argument_list|,
literal|0
argument_list|,
literal|3
argument_list|,
name|AW_CLK_FACTOR_HAS_COND
operator||
name|AW_CLK_FACTOR_FIXED
argument_list|,
comment|/* prediv */
literal|24
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

begin_comment
comment|/* ATS 0x1B0 */
end_comment

begin_comment
comment|/* Trace 0x1B4 */
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
name|pll_cpu_clk
block|,
operator|&
name|pll_audio_clk
block|,
operator|&
name|pll_periph_clk
block|,
operator|&
name|pll_ddr_clk
block|,
operator|&
name|pll_mipi_clk
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
name|pll_ve_clk
block|,
operator|&
name|pll_video1_clk
block|,
operator|&
name|pll_gpu_clk
block|,
operator|&
name|pll9_clk
block|,
operator|&
name|pll10_clk
block|,
operator|&
name|apb2_clk
block|,
operator|&
name|nand0_clk
block|,
operator|&
name|nand1_clk
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
name|mmc3_clk
block|,
operator|&
name|ts_clk
block|,
operator|&
name|ss_clk
block|,
operator|&
name|spi0_clk
block|,
operator|&
name|spi1_clk
block|,
operator|&
name|spi2_clk
block|,
operator|&
name|spi3_clk
block|,
operator|&
name|mdfs_clk
block|,
operator|&
name|sdram0_clk
block|,
operator|&
name|sdram1_clk
block|,
operator|&
name|be0_clk
block|,
operator|&
name|be1_clk
block|,
operator|&
name|fe0_clk
block|,
operator|&
name|fe1_clk
block|,
operator|&
name|mp_clk
block|,
operator|&
name|lcd0_ch0_clk
block|,
operator|&
name|lcd1_ch0_clk
block|,
operator|&
name|lcd0_ch1_clk
block|,
operator|&
name|lcd1_ch1_clk
block|,
operator|&
name|ve_clk
block|,
operator|&
name|hdmi_clk
block|,
operator|&
name|mbus0_clk
block|,
operator|&
name|mbus1_clk
block|,
operator|&
name|mipi_dsi_clk
block|,
operator|&
name|mipi_dsi_dphy_clk
block|,
operator|&
name|mipi_csi_dphy_clk
block|,
operator|&
name|iep_drc0_clk
block|,
operator|&
name|iep_drc1_clk
block|,
operator|&
name|iep_deu0_clk
block|,
operator|&
name|iep_deu1_clk
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
name|gpu_core_clk
block|,
operator|&
name|gpu_memory_clk
block|,
operator|&
name|gpu_hyd_clk
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
name|cpu_clk
block|,
operator|&
name|daudio0mux_clk
block|,
operator|&
name|daudio1mux_clk
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
name|pll_audio_2x_clk
block|,
operator|&
name|pll_audio_4x_clk
block|,
operator|&
name|pll_audio_8x_clk
block|,
operator|&
name|pll_video0_2x_clk
block|,
operator|&
name|pll_periph_2x_clk
block|,
operator|&
name|pll_video1_2x_clk
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
block|{ }
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|ccu_a31_register_clocks
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
name|a31_ccu_resets
expr_stmt|;
name|sc
operator|->
name|nresets
operator|=
name|nitems
argument_list|(
name|a31_ccu_resets
argument_list|)
expr_stmt|;
name|sc
operator|->
name|gates
operator|=
name|a31_ccu_gates
expr_stmt|;
name|sc
operator|->
name|ngates
operator|=
name|nitems
argument_list|(
name|a31_ccu_gates
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

