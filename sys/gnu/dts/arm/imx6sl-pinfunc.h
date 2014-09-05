begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2013 Freescale Semiconductor, Inc.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DTS_IMX6SL_PINFUNC_H
end_ifndef

begin_define
define|#
directive|define
name|__DTS_IMX6SL_PINFUNC_H
end_define

begin_comment
comment|/*  * The pin function ID is a tuple of  *<mux_reg conf_reg input_reg mux_mode input_val>  */
end_comment

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_MCLK__AUDIO_CLK_OUT
value|0x04c 0x2a4 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_MCLK__PWM4_OUT
value|0x04c 0x2a4 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_MCLK__ECSPI3_RDY
value|0x04c 0x2a4 0x6b4 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_MCLK__FEC_MDC
value|0x04c 0x2a4 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_MCLK__WDOG2_RESET_B_DEB
value|0x04c 0x2a4 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_MCLK__GPIO1_IO06
value|0x04c 0x2a4 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_MCLK__SPDIF_EXT_CLK
value|0x04c 0x2a4 0x7f4 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_RXC__AUD3_RXC
value|0x050 0x2a8 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_RXC__I2C1_SDA
value|0x050 0x2a8 0x720 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_RXC__UART3_TX_DATA
value|0x050 0x2a8 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_RXC__UART3_RX_DATA
value|0x050 0x2a8 0x80c 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_RXC__FEC_TX_CLK
value|0x050 0x2a8 0x70c 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_RXC__I2C3_SDA
value|0x050 0x2a8 0x730 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_RXC__GPIO1_IO01
value|0x050 0x2a8 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_RXC__ECSPI3_SS1
value|0x050 0x2a8 0x6c4 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_RXD__AUD3_RXD
value|0x054 0x2ac 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_RXD__ECSPI3_MOSI
value|0x054 0x2ac 0x6bc 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_RXD__UART4_RX_DATA
value|0x054 0x2ac 0x814 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_RXD__UART4_TX_DATA
value|0x054 0x2ac 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_RXD__FEC_RX_ER
value|0x054 0x2ac 0x708 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_RXD__SD1_LCTL
value|0x054 0x2ac 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_RXD__GPIO1_IO02
value|0x054 0x2ac 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_RXFS__AUD3_RXFS
value|0x058 0x2b0 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_RXFS__I2C1_SCL
value|0x058 0x2b0 0x71c 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_RXFS__UART3_RX_DATA
value|0x058 0x2b0 0x80c 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_RXFS__UART3_TX_DATA
value|0x058 0x2b0 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_RXFS__FEC_MDIO
value|0x058 0x2b0 0x6f4 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_RXFS__I2C3_SCL
value|0x058 0x2b0 0x72c 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_RXFS__GPIO1_IO00
value|0x058 0x2b0 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_RXFS__ECSPI3_SS0
value|0x058 0x2b0 0x6c0 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_TXC__AUD3_TXC
value|0x05c 0x2b4 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_TXC__ECSPI3_MISO
value|0x05c 0x2b4 0x6b8 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_TXC__UART4_TX_DATA
value|0x05c 0x2b4 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_TXC__UART4_RX_DATA
value|0x05c 0x2b4 0x814 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_TXC__FEC_RX_DV
value|0x05c 0x2b4 0x704 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_TXC__SD2_LCTL
value|0x05c 0x2b4 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_TXC__GPIO1_IO03
value|0x05c 0x2b4 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_TXD__AUD3_TXD
value|0x060 0x2b8 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_TXD__ECSPI3_SCLK
value|0x060 0x2b8 0x6b0 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_TXD__UART4_CTS_B
value|0x060 0x2b8 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_TXD__UART4_RTS_B
value|0x060 0x2b8 0x810 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_TXD__FEC_TX_DATA0
value|0x060 0x2b8 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_TXD__SD4_LCTL
value|0x060 0x2b8 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_TXD__GPIO1_IO05
value|0x060 0x2b8 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_TXFS__AUD3_TXFS
value|0x064 0x2bc 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_TXFS__PWM3_OUT
value|0x064 0x2bc 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_TXFS__UART4_RTS_B
value|0x064 0x2bc 0x810 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_TXFS__UART4_CTS_B
value|0x064 0x2bc 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_TXFS__FEC_RX_DATA1
value|0x064 0x2bc 0x6fc 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_TXFS__SD3_LCTL
value|0x064 0x2bc 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_AUD_TXFS__GPIO1_IO04
value|0x064 0x2bc 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI1_MISO__ECSPI1_MISO
value|0x068 0x358 0x684 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI1_MISO__AUD4_TXFS
value|0x068 0x358 0x5f8 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI1_MISO__UART5_RTS_B
value|0x068 0x358 0x818 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI1_MISO__UART5_CTS_B
value|0x068 0x358 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI1_MISO__EPDC_BDR0
value|0x068 0x358 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI1_MISO__SD2_WP
value|0x068 0x358 0x834 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI1_MISO__GPIO4_IO10
value|0x068 0x358 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI1_MOSI__ECSPI1_MOSI
value|0x06c 0x35c 0x688 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI1_MOSI__AUD4_TXC
value|0x06c 0x35c 0x5f4 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI1_MOSI__UART5_TX_DATA
value|0x06c 0x35c 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI1_MOSI__UART5_RX_DATA
value|0x06c 0x35c 0x81c 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI1_MOSI__EPDC_VCOM1
value|0x06c 0x35c 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI1_MOSI__SD2_VSELECT
value|0x06c 0x35c 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI1_MOSI__GPIO4_IO09
value|0x06c 0x35c 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI1_SCLK__ECSPI1_SCLK
value|0x070 0x360 0x67c 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI1_SCLK__AUD4_TXD
value|0x070 0x360 0x5e8 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI1_SCLK__UART5_RX_DATA
value|0x070 0x360 0x81c 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI1_SCLK__UART5_TX_DATA
value|0x070 0x360 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI1_SCLK__EPDC_VCOM0
value|0x070 0x360 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI1_SCLK__SD2_RESET
value|0x070 0x360 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI1_SCLK__GPIO4_IO08
value|0x070 0x360 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI1_SCLK__USB_OTG2_OC
value|0x070 0x360 0x820 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI1_SS0__ECSPI1_SS0
value|0x074 0x364 0x68c 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI1_SS0__AUD4_RXD
value|0x074 0x364 0x5e4 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI1_SS0__UART5_CTS_B
value|0x074 0x364 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI1_SS0__UART5_RTS_B
value|0x074 0x364 0x818 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI1_SS0__EPDC_BDR1
value|0x074 0x364 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI1_SS0__SD2_CD_B
value|0x074 0x364 0x830 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI1_SS0__GPIO4_IO11
value|0x074 0x364 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI1_SS0__USB_OTG2_PWR
value|0x074 0x364 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI2_MISO__ECSPI2_MISO
value|0x078 0x368 0x6a0 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI2_MISO__SDMA_EXT_EVENT0
value|0x078 0x368 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI2_MISO__UART3_RTS_B
value|0x078 0x368 0x808 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI2_MISO__UART3_CTS_B
value|0x078 0x368 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI2_MISO__CSI_MCLK
value|0x078 0x368 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI2_MISO__SD1_WP
value|0x078 0x368 0x82c 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI2_MISO__GPIO4_IO14
value|0x078 0x368 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI2_MISO__USB_OTG1_OC
value|0x078 0x368 0x824 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI2_MOSI__ECSPI2_MOSI
value|0x07c 0x36c 0x6a4 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI2_MOSI__SDMA_EXT_EVENT1
value|0x07c 0x36c 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI2_MOSI__UART3_TX_DATA
value|0x07c 0x36c 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI2_MOSI__UART3_RX_DATA
value|0x07c 0x36c 0x80c 0x2 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI2_MOSI__CSI_HSYNC
value|0x07c 0x36c 0x670 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI2_MOSI__SD1_VSELECT
value|0x07c 0x36c 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI2_MOSI__GPIO4_IO13
value|0x07c 0x36c 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI2_SCLK__ECSPI2_SCLK
value|0x080 0x370 0x69c 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI2_SCLK__SPDIF_EXT_CLK
value|0x080 0x370 0x7f4 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI2_SCLK__UART3_RX_DATA
value|0x080 0x370 0x80c 0x2 0x3
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI2_SCLK__UART3_TX_DATA
value|0x080 0x370 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI2_SCLK__CSI_PIXCLK
value|0x080 0x370 0x674 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI2_SCLK__SD1_RESET
value|0x080 0x370 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI2_SCLK__GPIO4_IO12
value|0x080 0x370 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI2_SCLK__USB_OTG2_OC
value|0x080 0x370 0x820 0x6 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI2_SS0__ECSPI2_SS0
value|0x084 0x374 0x6a8 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI2_SS0__ECSPI1_SS3
value|0x084 0x374 0x698 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI2_SS0__UART3_CTS_B
value|0x084 0x374 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI2_SS0__UART3_RTS_B
value|0x084 0x374 0x808 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI2_SS0__CSI_VSYNC
value|0x084 0x374 0x678 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI2_SS0__SD1_CD_B
value|0x084 0x374 0x828 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI2_SS0__GPIO4_IO15
value|0x084 0x374 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_ECSPI2_SS0__USB_OTG1_PWR
value|0x084 0x374 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_BDR0__EPDC_BDR0
value|0x088 0x378 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_BDR0__SD4_CLK
value|0x088 0x378 0x850 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_BDR0__UART3_RTS_B
value|0x088 0x378 0x808 0x2 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_BDR0__UART3_CTS_B
value|0x088 0x378 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_BDR0__EIM_ADDR26
value|0x088 0x378 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_BDR0__SPDC_RL
value|0x088 0x378 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_BDR0__GPIO2_IO05
value|0x088 0x378 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_BDR0__EPDC_SDCE7
value|0x088 0x378 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_BDR1__EPDC_BDR1
value|0x08c 0x37c 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_BDR1__SD4_CMD
value|0x08c 0x37c 0x858 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_BDR1__UART3_CTS_B
value|0x08c 0x37c 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_BDR1__UART3_RTS_B
value|0x08c 0x37c 0x808 0x2 0x3
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_BDR1__EIM_CRE
value|0x08c 0x37c 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_BDR1__SPDC_UD
value|0x08c 0x37c 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_BDR1__GPIO2_IO06
value|0x08c 0x37c 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_BDR1__EPDC_SDCE8
value|0x08c 0x37c 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D0__EPDC_DATA00
value|0x090 0x380 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D0__ECSPI4_MOSI
value|0x090 0x380 0x6d8 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D0__LCD_DATA24
value|0x090 0x380 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D0__CSI_DATA00
value|0x090 0x380 0x630 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D0__SPDC_DATA00
value|0x090 0x380 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D0__GPIO1_IO07
value|0x090 0x380 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D1__EPDC_DATA01
value|0x094 0x384 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D1__ECSPI4_MISO
value|0x094 0x384 0x6d4 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D1__LCD_DATA25
value|0x094 0x384 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D1__CSI_DATA01
value|0x094 0x384 0x634 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D1__SPDC_DATA01
value|0x094 0x384 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D1__GPIO1_IO08
value|0x094 0x384 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D10__EPDC_DATA10
value|0x098 0x388 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D10__ECSPI3_SS0
value|0x098 0x388 0x6c0 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D10__EPDC_PWR_CTRL2
value|0x098 0x388 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D10__EIM_ADDR18
value|0x098 0x388 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D10__SPDC_DATA10
value|0x098 0x388 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D10__GPIO1_IO17
value|0x098 0x388 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D10__SD4_WP
value|0x098 0x388 0x87c 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D11__EPDC_DATA11
value|0x09c 0x38c 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D11__ECSPI3_SCLK
value|0x09c 0x38c 0x6b0 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D11__EPDC_PWR_CTRL3
value|0x09c 0x38c 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D11__EIM_ADDR19
value|0x09c 0x38c 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D11__SPDC_DATA11
value|0x09c 0x38c 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D11__GPIO1_IO18
value|0x09c 0x38c 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D11__SD4_CD_B
value|0x09c 0x38c 0x854 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D12__EPDC_DATA12
value|0x0a0 0x390 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D12__UART2_RX_DATA
value|0x0a0 0x390 0x804 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D12__UART2_TX_DATA
value|0x0a0 0x390 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D12__EPDC_PWR_COM
value|0x0a0 0x390 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D12__EIM_ADDR20
value|0x0a0 0x390 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D12__SPDC_DATA12
value|0x0a0 0x390 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D12__GPIO1_IO19
value|0x0a0 0x390 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D12__ECSPI3_SS1
value|0x0a0 0x390 0x6c4 0x6 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D13__EPDC_DATA13
value|0x0a4 0x394 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D13__UART2_TX_DATA
value|0x0a4 0x394 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D13__UART2_RX_DATA
value|0x0a4 0x394 0x804 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D13__EPDC_PWR_IRQ
value|0x0a4 0x394 0x6e8 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D13__EIM_ADDR21
value|0x0a4 0x394 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D13__SPDC_DATA13
value|0x0a4 0x394 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D13__GPIO1_IO20
value|0x0a4 0x394 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D13__ECSPI3_SS2
value|0x0a4 0x394 0x6c8 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D14__EPDC_DATA14
value|0x0a8 0x398 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D14__UART2_RTS_B
value|0x0a8 0x398 0x800 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D14__UART2_CTS_B
value|0x0a8 0x398 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D14__EPDC_PWR_STAT
value|0x0a8 0x398 0x6ec 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D14__EIM_ADDR22
value|0x0a8 0x398 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D14__SPDC_DATA14
value|0x0a8 0x398 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D14__GPIO1_IO21
value|0x0a8 0x398 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D14__ECSPI3_SS3
value|0x0a8 0x398 0x6cc 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D15__EPDC_DATA15
value|0x0ac 0x39c 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D15__UART2_CTS_B
value|0x0ac 0x39c 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D15__UART2_RTS_B
value|0x0ac 0x39c 0x800 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D15__EPDC_PWR_WAKE
value|0x0ac 0x39c 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D15__EIM_ADDR23
value|0x0ac 0x39c 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D15__SPDC_DATA15
value|0x0ac 0x39c 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D15__GPIO1_IO22
value|0x0ac 0x39c 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D15__ECSPI3_RDY
value|0x0ac 0x39c 0x6b4 0x6 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D2__EPDC_DATA02
value|0x0b0 0x3a0 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D2__ECSPI4_SS0
value|0x0b0 0x3a0 0x6dc 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D2__LCD_DATA26
value|0x0b0 0x3a0 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D2__CSI_DATA02
value|0x0b0 0x3a0 0x638 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D2__SPDC_DATA02
value|0x0b0 0x3a0 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D2__GPIO1_IO09
value|0x0b0 0x3a0 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D3__EPDC_DATA03
value|0x0b4 0x3a4 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D3__ECSPI4_SCLK
value|0x0b4 0x3a4 0x6d0 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D3__LCD_DATA27
value|0x0b4 0x3a4 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D3__CSI_DATA03
value|0x0b4 0x3a4 0x63c 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D3__SPDC_DATA03
value|0x0b4 0x3a4 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D3__GPIO1_IO10
value|0x0b4 0x3a4 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D4__EPDC_DATA04
value|0x0b8 0x3a8 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D4__ECSPI4_SS1
value|0x0b8 0x3a8 0x6e0 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D4__LCD_DATA28
value|0x0b8 0x3a8 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D4__CSI_DATA04
value|0x0b8 0x3a8 0x640 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D4__SPDC_DATA04
value|0x0b8 0x3a8 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D4__GPIO1_IO11
value|0x0b8 0x3a8 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D5__EPDC_DATA05
value|0x0bc 0x3ac 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D5__ECSPI4_SS2
value|0x0bc 0x3ac 0x6e4 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D5__LCD_DATA29
value|0x0bc 0x3ac 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D5__CSI_DATA05
value|0x0bc 0x3ac 0x644 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D5__SPDC_DATA05
value|0x0bc 0x3ac 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D5__GPIO1_IO12
value|0x0bc 0x3ac 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D6__EPDC_DATA06
value|0x0c0 0x3b0 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D6__ECSPI4_SS3
value|0x0c0 0x3b0 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D6__LCD_DATA30
value|0x0c0 0x3b0 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D6__CSI_DATA06
value|0x0c0 0x3b0 0x648 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D6__SPDC_DATA06
value|0x0c0 0x3b0 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D6__GPIO1_IO13
value|0x0c0 0x3b0 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D7__EPDC_DATA07
value|0x0c4 0x3b4 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D7__ECSPI4_RDY
value|0x0c4 0x3b4 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D7__LCD_DATA31
value|0x0c4 0x3b4 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D7__CSI_DATA07
value|0x0c4 0x3b4 0x64c 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D7__SPDC_DATA07
value|0x0c4 0x3b4 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D7__GPIO1_IO14
value|0x0c4 0x3b4 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D8__EPDC_DATA08
value|0x0c8 0x3b8 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D8__ECSPI3_MOSI
value|0x0c8 0x3b8 0x6bc 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D8__EPDC_PWR_CTRL0
value|0x0c8 0x3b8 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D8__EIM_ADDR16
value|0x0c8 0x3b8 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D8__SPDC_DATA08
value|0x0c8 0x3b8 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D8__GPIO1_IO15
value|0x0c8 0x3b8 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D8__SD4_RESET
value|0x0c8 0x3b8 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D9__EPDC_DATA09
value|0x0cc 0x3bc 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D9__ECSPI3_MISO
value|0x0cc 0x3bc 0x6b8 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D9__EPDC_PWR_CTRL1
value|0x0cc 0x3bc 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D9__EIM_ADDR17
value|0x0cc 0x3bc 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D9__SPDC_DATA09
value|0x0cc 0x3bc 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D9__GPIO1_IO16
value|0x0cc 0x3bc 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_D9__SD4_VSELECT
value|0x0cc 0x3bc 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_GDCLK__EPDC_GDCLK
value|0x0d0 0x3c0 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_GDCLK__ECSPI2_SS2
value|0x0d0 0x3c0 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_GDCLK__SPDC_YCKR
value|0x0d0 0x3c0 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_GDCLK__CSI_PIXCLK
value|0x0d0 0x3c0 0x674 0x3 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_GDCLK__SPDC_YCKL
value|0x0d0 0x3c0 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_GDCLK__GPIO1_IO31
value|0x0d0 0x3c0 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_GDCLK__SD2_RESET
value|0x0d0 0x3c0 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_GDOE__EPDC_GDOE
value|0x0d4 0x3c4 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_GDOE__ECSPI2_SS3
value|0x0d4 0x3c4 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_GDOE__SPDC_YOER
value|0x0d4 0x3c4 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_GDOE__CSI_HSYNC
value|0x0d4 0x3c4 0x670 0x3 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_GDOE__SPDC_YOEL
value|0x0d4 0x3c4 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_GDOE__GPIO2_IO00
value|0x0d4 0x3c4 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_GDOE__SD2_VSELECT
value|0x0d4 0x3c4 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_GDRL__EPDC_GDRL
value|0x0d8 0x3c8 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_GDRL__ECSPI2_RDY
value|0x0d8 0x3c8 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_GDRL__SPDC_YDIOUR
value|0x0d8 0x3c8 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_GDRL__CSI_MCLK
value|0x0d8 0x3c8 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_GDRL__SPDC_YDIOUL
value|0x0d8 0x3c8 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_GDRL__GPIO2_IO01
value|0x0d8 0x3c8 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_GDRL__SD2_WP
value|0x0d8 0x3c8 0x834 0x6 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_GDSP__EPDC_GDSP
value|0x0dc 0x3cc 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_GDSP__PWM4_OUT
value|0x0dc 0x3cc 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_GDSP__SPDC_YDIODR
value|0x0dc 0x3cc 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_GDSP__CSI_VSYNC
value|0x0dc 0x3cc 0x678 0x3 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_GDSP__SPDC_YDIODL
value|0x0dc 0x3cc 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_GDSP__GPIO2_IO02
value|0x0dc 0x3cc 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_GDSP__SD2_CD_B
value|0x0dc 0x3cc 0x830 0x6 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRCOM__EPDC_PWR_COM
value|0x0e0 0x3d0 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRCOM__SD4_DATA0
value|0x0e0 0x3d0 0x85c 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRCOM__LCD_DATA20
value|0x0e0 0x3d0 0x7c8 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRCOM__EIM_BCLK
value|0x0e0 0x3d0 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRCOM__USB_OTG1_ID
value|0x0e0 0x3d0 0x5dc 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRCOM__GPIO2_IO11
value|0x0e0 0x3d0 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRCOM__SD3_RESET
value|0x0e0 0x3d0 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRCTRL0__EPDC_PWR_CTRL0
value|0x0e4 0x3d4 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRCTRL0__AUD5_RXC
value|0x0e4 0x3d4 0x604 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRCTRL0__LCD_DATA16
value|0x0e4 0x3d4 0x7b8 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRCTRL0__EIM_RW
value|0x0e4 0x3d4 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRCTRL0__SPDC_YCKL
value|0x0e4 0x3d4 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRCTRL0__GPIO2_IO07
value|0x0e4 0x3d4 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRCTRL0__SD4_RESET
value|0x0e4 0x3d4 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRCTRL1__EPDC_PWR_CTRL1
value|0x0e8 0x3d8 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRCTRL1__AUD5_TXFS
value|0x0e8 0x3d8 0x610 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRCTRL1__LCD_DATA17
value|0x0e8 0x3d8 0x7bc 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRCTRL1__EIM_OE_B
value|0x0e8 0x3d8 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRCTRL1__SPDC_YOEL
value|0x0e8 0x3d8 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRCTRL1__GPIO2_IO08
value|0x0e8 0x3d8 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRCTRL1__SD4_VSELECT
value|0x0e8 0x3d8 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRCTRL2__EPDC_PWR_CTRL2
value|0x0ec 0x3dc 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRCTRL2__AUD5_TXD
value|0x0ec 0x3dc 0x600 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRCTRL2__LCD_DATA18
value|0x0ec 0x3dc 0x7c0 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRCTRL2__EIM_CS0_B
value|0x0ec 0x3dc 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRCTRL2__SPDC_YDIOUL
value|0x0ec 0x3dc 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRCTRL2__GPIO2_IO09
value|0x0ec 0x3dc 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRCTRL2__SD4_WP
value|0x0ec 0x3dc 0x87c 0x6 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRCTRL3__EPDC_PWR_CTRL3
value|0x0f0 0x3e0 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRCTRL3__AUD5_TXC
value|0x0f0 0x3e0 0x60c 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRCTRL3__LCD_DATA19
value|0x0f0 0x3e0 0x7c4 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRCTRL3__EIM_CS1_B
value|0x0f0 0x3e0 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRCTRL3__SPDC_YDIODL
value|0x0f0 0x3e0 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRCTRL3__GPIO2_IO10
value|0x0f0 0x3e0 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRCTRL3__SD4_CD_B
value|0x0f0 0x3e0 0x854 0x6 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRINT__EPDC_PWR_IRQ
value|0x0f4 0x3e4 0x6e8 0x0 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRINT__SD4_DATA1
value|0x0f4 0x3e4 0x860 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRINT__LCD_DATA21
value|0x0f4 0x3e4 0x7cc 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRINT__EIM_ACLK_FREERUN
value|0x0f4 0x3e4 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRINT__USB_OTG2_ID
value|0x0f4 0x3e4 0x5e0 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRINT__GPIO2_IO12
value|0x0f4 0x3e4 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRINT__SD3_VSELECT
value|0x0f4 0x3e4 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRSTAT__EPDC_PWR_STAT
value|0x0f8 0x3e8 0x6ec 0x0 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRSTAT__SD4_DATA2
value|0x0f8 0x3e8 0x864 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRSTAT__LCD_DATA22
value|0x0f8 0x3e8 0x7d0 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRSTAT__EIM_WAIT_B
value|0x0f8 0x3e8 0x884 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRSTAT__ARM_EVENTI
value|0x0f8 0x3e8 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRSTAT__GPIO2_IO13
value|0x0f8 0x3e8 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRSTAT__SD3_WP
value|0x0f8 0x3e8 0x84c 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRWAKEUP__EPDC_PWR_WAKE
value|0x0fc 0x3ec 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRWAKEUP__SD4_DATA3
value|0x0fc 0x3ec 0x868 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRWAKEUP__LCD_DATA23
value|0x0fc 0x3ec 0x7d4 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRWAKEUP__EIM_DTACK_B
value|0x0fc 0x3ec 0x880 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRWAKEUP__ARM_EVENTO
value|0x0fc 0x3ec 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRWAKEUP__GPIO2_IO14
value|0x0fc 0x3ec 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_PWRWAKEUP__SD3_CD_B
value|0x0fc 0x3ec 0x838 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDCE0__EPDC_SDCE0
value|0x100 0x3f0 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDCE0__ECSPI2_SS1
value|0x100 0x3f0 0x6ac 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDCE0__PWM3_OUT
value|0x100 0x3f0 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDCE0__EIM_CS2_B
value|0x100 0x3f0 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDCE0__SPDC_YCKR
value|0x100 0x3f0 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDCE0__GPIO1_IO27
value|0x100 0x3f0 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDCE1__EPDC_SDCE1
value|0x104 0x3f4 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDCE1__WDOG2_B
value|0x104 0x3f4 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDCE1__PWM4_OUT
value|0x104 0x3f4 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDCE1__EIM_LBA_B
value|0x104 0x3f4 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDCE1__SPDC_YOER
value|0x104 0x3f4 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDCE1__GPIO1_IO28
value|0x104 0x3f4 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDCE2__EPDC_SDCE2
value|0x108 0x3f8 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDCE2__I2C3_SCL
value|0x108 0x3f8 0x72c 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDCE2__PWM1_OUT
value|0x108 0x3f8 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDCE2__EIM_EB0_B
value|0x108 0x3f8 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDCE2__SPDC_YDIOUR
value|0x108 0x3f8 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDCE2__GPIO1_IO29
value|0x108 0x3f8 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDCE3__EPDC_SDCE3
value|0x10c 0x3fc 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDCE3__I2C3_SDA
value|0x10c 0x3fc 0x730 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDCE3__PWM2_OUT
value|0x10c 0x3fc 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDCE3__EIM_EB1_B
value|0x10c 0x3fc 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDCE3__SPDC_YDIODR
value|0x10c 0x3fc 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDCE3__GPIO1_IO30
value|0x10c 0x3fc 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDCLK__EPDC_SDCLK_P
value|0x110 0x400 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDCLK__ECSPI2_MOSI
value|0x110 0x400 0x6a4 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDCLK__I2C2_SCL
value|0x110 0x400 0x724 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDCLK__CSI_DATA08
value|0x110 0x400 0x650 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDCLK__SPDC_CL
value|0x110 0x400 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDCLK__GPIO1_IO23
value|0x110 0x400 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDLE__EPDC_SDLE
value|0x114 0x404 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDLE__ECSPI2_MISO
value|0x114 0x404 0x6a0 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDLE__I2C2_SDA
value|0x114 0x404 0x728 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDLE__CSI_DATA09
value|0x114 0x404 0x654 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDLE__SPDC_LD
value|0x114 0x404 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDLE__GPIO1_IO24
value|0x114 0x404 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDOE__EPDC_SDOE
value|0x118 0x408 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDOE__ECSPI2_SS0
value|0x118 0x408 0x6a8 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDOE__SPDC_XDIOR
value|0x118 0x408 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDOE__CSI_DATA10
value|0x118 0x408 0x658 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDOE__SPDC_XDIOL
value|0x118 0x408 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDOE__GPIO1_IO25
value|0x118 0x408 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDSHR__EPDC_SDSHR
value|0x11c 0x40c 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDSHR__ECSPI2_SCLK
value|0x11c 0x40c 0x69c 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDSHR__EPDC_SDCE4
value|0x11c 0x40c 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDSHR__CSI_DATA11
value|0x11c 0x40c 0x65c 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDSHR__SPDC_XDIOR
value|0x11c 0x40c 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_SDSHR__GPIO1_IO26
value|0x11c 0x40c 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_VCOM0__EPDC_VCOM0
value|0x120 0x410 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_VCOM0__AUD5_RXFS
value|0x120 0x410 0x608 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_VCOM0__UART3_RX_DATA
value|0x120 0x410 0x80c 0x2 0x4
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_VCOM0__UART3_TX_DATA
value|0x120 0x410 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_VCOM0__EIM_ADDR24
value|0x120 0x410 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_VCOM0__SPDC_VCOM0
value|0x120 0x410 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_VCOM0__GPIO2_IO03
value|0x120 0x410 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_VCOM0__EPDC_SDCE5
value|0x120 0x410 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_VCOM1__EPDC_VCOM1
value|0x124 0x414 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_VCOM1__AUD5_RXD
value|0x124 0x414 0x5fc 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_VCOM1__UART3_TX_DATA
value|0x124 0x414 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_VCOM1__UART3_RX_DATA
value|0x124 0x414 0x80c 0x2 0x5
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_VCOM1__EIM_ADDR25
value|0x124 0x414 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_VCOM1__SPDC_VCOM1
value|0x124 0x414 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_VCOM1__GPIO2_IO04
value|0x124 0x414 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_EPDC_VCOM1__EPDC_SDCE6
value|0x124 0x414 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_CRS_DV__FEC_RX_DV
value|0x128 0x418 0x704 0x0 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_CRS_DV__SD4_DATA1
value|0x128 0x418 0x860 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_CRS_DV__AUD6_TXC
value|0x128 0x418 0x624 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_CRS_DV__ECSPI4_MISO
value|0x128 0x418 0x6d4 0x3 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_CRS_DV__GPT_COMPARE2
value|0x128 0x418 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_CRS_DV__GPIO4_IO25
value|0x128 0x418 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_CRS_DV__ARM_TRACE31
value|0x128 0x418 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_MDC__FEC_MDC
value|0x12c 0x41c 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_MDC__SD4_DATA4
value|0x12c 0x41c 0x86c 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_MDC__AUDIO_CLK_OUT
value|0x12c 0x41c 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_MDC__SD1_RESET
value|0x12c 0x41c 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_MDC__SD3_RESET
value|0x12c 0x41c 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_MDC__GPIO4_IO23
value|0x12c 0x41c 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_MDC__ARM_TRACE29
value|0x12c 0x41c 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_MDIO__FEC_MDIO
value|0x130 0x420 0x6f4 0x0 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_MDIO__SD4_CLK
value|0x130 0x420 0x850 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_MDIO__AUD6_RXFS
value|0x130 0x420 0x620 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_MDIO__ECSPI4_SS0
value|0x130 0x420 0x6dc 0x3 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_MDIO__GPT_CAPTURE1
value|0x130 0x420 0x710 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_MDIO__GPIO4_IO20
value|0x130 0x420 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_MDIO__ARM_TRACE26
value|0x130 0x420 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_REF_CLK__FEC_REF_OUT
value|0x134 0x424 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_REF_CLK__SD4_RESET
value|0x134 0x424 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_REF_CLK__WDOG1_B
value|0x134 0x424 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_REF_CLK__PWM4_OUT
value|0x134 0x424 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_REF_CLK__CCM_PMIC_READY
value|0x134 0x424 0x62c 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_REF_CLK__GPIO4_IO26
value|0x134 0x424 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_REF_CLK__SPDIF_EXT_CLK
value|0x134 0x424 0x7f4 0x6 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_RX_ER__FEC_RX_ER
value|0x138 0x428 0x708 0x0 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_RX_ER__SD4_DATA0
value|0x138 0x428 0x85c 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_RX_ER__AUD6_RXD
value|0x138 0x428 0x614 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_RX_ER__ECSPI4_MOSI
value|0x138 0x428 0x6d8 0x3 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_RX_ER__GPT_COMPARE1
value|0x138 0x428 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_RX_ER__GPIO4_IO19
value|0x138 0x428 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_RX_ER__ARM_TRACE25
value|0x138 0x428 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_RXD0__FEC_RX_DATA0
value|0x13c 0x42c 0x6f8 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_RXD0__SD4_DATA5
value|0x13c 0x42c 0x870 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_RXD0__USB_OTG1_ID
value|0x13c 0x42c 0x5dc 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_RXD0__SD1_VSELECT
value|0x13c 0x42c 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_RXD0__SD3_VSELECT
value|0x13c 0x42c 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_RXD0__GPIO4_IO17
value|0x13c 0x42c 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_RXD0__ARM_TRACE24
value|0x13c 0x42c 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_RXD1__FEC_RX_DATA1
value|0x140 0x430 0x6fc 0x0 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_RXD1__SD4_DATA2
value|0x140 0x430 0x864 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_RXD1__AUD6_TXFS
value|0x140 0x430 0x628 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_RXD1__ECSPI4_SS1
value|0x140 0x430 0x6e0 0x3 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_RXD1__GPT_COMPARE3
value|0x140 0x430 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_RXD1__GPIO4_IO18
value|0x140 0x430 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_RXD1__FEC_COL
value|0x140 0x430 0x6f0 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_TX_CLK__FEC_TX_CLK
value|0x144 0x434 0x70c 0x0 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_TX_CLK__SD4_CMD
value|0x144 0x434 0x858 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_TX_CLK__AUD6_RXC
value|0x144 0x434 0x61c 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_TX_CLK__ECSPI4_SCLK
value|0x144 0x434 0x6d0 0x3 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_TX_CLK__GPT_CAPTURE2
value|0x144 0x434 0x714 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_TX_CLK__GPIO4_IO21
value|0x144 0x434 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_TX_CLK__ARM_TRACE27
value|0x144 0x434 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_TX_EN__FEC_TX_EN
value|0x148 0x438 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_TX_EN__SD4_DATA6
value|0x148 0x438 0x874 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_TX_EN__SPDIF_IN
value|0x148 0x438 0x7f0 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_TX_EN__SD1_WP
value|0x148 0x438 0x82c 0x3 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_TX_EN__SD3_WP
value|0x148 0x438 0x84c 0x4 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_TX_EN__GPIO4_IO22
value|0x148 0x438 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_TX_EN__ARM_TRACE28
value|0x148 0x438 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_TXD0__FEC_TX_DATA0
value|0x14c 0x43c 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_TXD0__SD4_DATA3
value|0x14c 0x43c 0x868 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_TXD0__AUD6_TXD
value|0x14c 0x43c 0x618 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_TXD0__ECSPI4_SS2
value|0x14c 0x43c 0x6e4 0x3 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_TXD0__GPT_CLKIN
value|0x14c 0x43c 0x718 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_TXD0__GPIO4_IO24
value|0x14c 0x43c 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_TXD0__ARM_TRACE30
value|0x14c 0x43c 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_TXD1__FEC_TX_DATA1
value|0x150 0x440 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_TXD1__SD4_DATA7
value|0x150 0x440 0x878 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_TXD1__SPDIF_OUT
value|0x150 0x440 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_TXD1__SD1_CD_B
value|0x150 0x440 0x828 0x3 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_TXD1__SD3_CD_B
value|0x150 0x440 0x838 0x4 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_TXD1__GPIO4_IO16
value|0x150 0x440 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_FEC_TXD1__FEC_RX_CLK
value|0x150 0x440 0x700 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_HSIC_DAT__USB_H_DATA
value|0x154 0x444 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_HSIC_DAT__I2C1_SCL
value|0x154 0x444 0x71c 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_HSIC_DAT__PWM1_OUT
value|0x154 0x444 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_HSIC_DAT__XTALOSC_REF_CLK_24M
value|0x154 0x444 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_HSIC_DAT__GPIO3_IO19
value|0x154 0x444 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_HSIC_STROBE__USB_H_STROBE
value|0x158 0x448 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_HSIC_STROBE__I2C1_SDA
value|0x158 0x448 0x720 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_HSIC_STROBE__PWM2_OUT
value|0x158 0x448 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_HSIC_STROBE__XTALOSC_REF_CLK_32K
value|0x158 0x448 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_HSIC_STROBE__GPIO3_IO20
value|0x158 0x448 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_I2C1_SCL__I2C1_SCL
value|0x15c 0x44c 0x71c 0x0 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_I2C1_SCL__UART1_RTS_B
value|0x15c 0x44c 0x7f8 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_I2C1_SCL__UART1_CTS_B
value|0x15c 0x44c 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_I2C1_SCL__ECSPI3_SS2
value|0x15c 0x44c 0x6c8 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_I2C1_SCL__FEC_RX_DATA0
value|0x15c 0x44c 0x6f8 0x3 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_I2C1_SCL__SD3_RESET
value|0x15c 0x44c 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_I2C1_SCL__GPIO3_IO12
value|0x15c 0x44c 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_I2C1_SCL__ECSPI1_SS1
value|0x15c 0x44c 0x690 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_I2C1_SDA__I2C1_SDA
value|0x160 0x450 0x720 0x0 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_I2C1_SDA__UART1_CTS_B
value|0x160 0x450 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_I2C1_SDA__UART1_RTS_B
value|0x160 0x450 0x7f8 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_I2C1_SDA__ECSPI3_SS3
value|0x160 0x450 0x6cc 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_I2C1_SDA__FEC_TX_EN
value|0x160 0x450 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_I2C1_SDA__SD3_VSELECT
value|0x160 0x450 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_I2C1_SDA__GPIO3_IO13
value|0x160 0x450 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_I2C1_SDA__ECSPI1_SS2
value|0x160 0x450 0x694 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_I2C2_SCL__I2C2_SCL
value|0x164 0x454 0x724 0x0 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_I2C2_SCL__AUD4_RXFS
value|0x164 0x454 0x5f0 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_I2C2_SCL__SPDIF_IN
value|0x164 0x454 0x7f0 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_I2C2_SCL__FEC_TX_DATA1
value|0x164 0x454 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_I2C2_SCL__SD3_WP
value|0x164 0x454 0x84c 0x4 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_I2C2_SCL__GPIO3_IO14
value|0x164 0x454 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_I2C2_SCL__ECSPI1_RDY
value|0x164 0x454 0x680 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_I2C2_SDA__I2C2_SDA
value|0x168 0x458 0x728 0x0 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_I2C2_SDA__AUD4_RXC
value|0x168 0x458 0x5ec 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_I2C2_SDA__SPDIF_OUT
value|0x168 0x458 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_I2C2_SDA__FEC_REF_OUT
value|0x168 0x458 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_I2C2_SDA__SD3_CD_B
value|0x168 0x458 0x838 0x4 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_I2C2_SDA__GPIO3_IO15
value|0x168 0x458 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL0__KEY_COL0
value|0x16c 0x474 0x734 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL0__I2C2_SCL
value|0x16c 0x474 0x724 0x1 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL0__LCD_DATA00
value|0x16c 0x474 0x778 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL0__EIM_AD00
value|0x16c 0x474 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL0__SD1_CD_B
value|0x16c 0x474 0x828 0x4 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL0__GPIO3_IO24
value|0x16c 0x474 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL1__KEY_COL1
value|0x170 0x478 0x738 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL1__ECSPI4_MOSI
value|0x170 0x478 0x6d8 0x1 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL1__LCD_DATA02
value|0x170 0x478 0x780 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL1__EIM_AD02
value|0x170 0x478 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL1__SD3_DATA4
value|0x170 0x478 0x83c 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL1__GPIO3_IO26
value|0x170 0x478 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL2__KEY_COL2
value|0x174 0x47c 0x73c 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL2__ECSPI4_SS0
value|0x174 0x47c 0x6dc 0x1 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL2__LCD_DATA04
value|0x174 0x47c 0x788 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL2__EIM_AD04
value|0x174 0x47c 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL2__SD3_DATA6
value|0x174 0x47c 0x844 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL2__GPIO3_IO28
value|0x174 0x47c 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL3__KEY_COL3
value|0x178 0x480 0x740 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL3__AUD6_RXFS
value|0x178 0x480 0x620 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL3__LCD_DATA06
value|0x178 0x480 0x790 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL3__EIM_AD06
value|0x178 0x480 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL3__SD4_DATA6
value|0x178 0x480 0x874 0x4 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL3__GPIO3_IO30
value|0x178 0x480 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL3__SD1_RESET
value|0x178 0x480 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL4__KEY_COL4
value|0x17c 0x484 0x744 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL4__AUD6_RXD
value|0x17c 0x484 0x614 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL4__LCD_DATA08
value|0x17c 0x484 0x798 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL4__EIM_AD08
value|0x17c 0x484 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL4__SD4_CLK
value|0x17c 0x484 0x850 0x4 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL4__GPIO4_IO00
value|0x17c 0x484 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL4__USB_OTG1_PWR
value|0x17c 0x484 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL5__KEY_COL5
value|0x180 0x488 0x748 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL5__AUD6_TXFS
value|0x180 0x488 0x628 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL5__LCD_DATA10
value|0x180 0x488 0x7a0 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL5__EIM_AD10
value|0x180 0x488 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL5__SD4_DATA0
value|0x180 0x488 0x85c 0x4 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL5__GPIO4_IO02
value|0x180 0x488 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL5__USB_OTG2_PWR
value|0x180 0x488 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL6__KEY_COL6
value|0x184 0x48c 0x74c 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL6__UART4_RX_DATA
value|0x184 0x48c 0x814 0x1 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL6__UART4_TX_DATA
value|0x184 0x48c 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL6__LCD_DATA12
value|0x184 0x48c 0x7a8 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL6__EIM_AD12
value|0x184 0x48c 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL6__SD4_DATA2
value|0x184 0x48c 0x864 0x4 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL6__GPIO4_IO04
value|0x184 0x48c 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL6__SD3_RESET
value|0x184 0x48c 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL7__KEY_COL7
value|0x188 0x490 0x750 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL7__UART4_RTS_B
value|0x188 0x490 0x810 0x1 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL7__UART4_CTS_B
value|0x188 0x490 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL7__LCD_DATA14
value|0x188 0x490 0x7b0 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL7__EIM_AD14
value|0x188 0x490 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL7__SD4_DATA4
value|0x188 0x490 0x86c 0x4 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL7__GPIO4_IO06
value|0x188 0x490 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_COL7__SD1_WP
value|0x188 0x490 0x82c 0x6 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW0__KEY_ROW0
value|0x18c 0x494 0x754 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW0__I2C2_SDA
value|0x18c 0x494 0x728 0x1 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW0__LCD_DATA01
value|0x18c 0x494 0x77c 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW0__EIM_AD01
value|0x18c 0x494 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW0__SD1_WP
value|0x18c 0x494 0x82c 0x4 0x3
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW0__GPIO3_IO25
value|0x18c 0x494 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW1__KEY_ROW1
value|0x190 0x498 0x758 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW1__ECSPI4_MISO
value|0x190 0x498 0x6d4 0x1 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW1__LCD_DATA03
value|0x190 0x498 0x784 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW1__EIM_AD03
value|0x190 0x498 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW1__SD3_DATA5
value|0x190 0x498 0x840 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW1__GPIO3_IO27
value|0x190 0x498 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW2__KEY_ROW2
value|0x194 0x49c 0x75c 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW2__ECSPI4_SCLK
value|0x194 0x49c 0x6d0 0x1 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW2__LCD_DATA05
value|0x194 0x49c 0x78c 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW2__EIM_AD05
value|0x194 0x49c 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW2__SD3_DATA7
value|0x194 0x49c 0x848 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW2__GPIO3_IO29
value|0x194 0x49c 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW3__KEY_ROW3
value|0x198 0x4a0 0x760 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW3__AUD6_RXC
value|0x198 0x4a0 0x61c 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW3__LCD_DATA07
value|0x198 0x4a0 0x794 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW3__EIM_AD07
value|0x198 0x4a0 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW3__SD4_DATA7
value|0x198 0x4a0 0x878 0x4 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW3__GPIO3_IO31
value|0x198 0x4a0 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW3__SD1_VSELECT
value|0x198 0x4a0 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW4__KEY_ROW4
value|0x19c 0x4a4 0x764 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW4__AUD6_TXC
value|0x19c 0x4a4 0x624 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW4__LCD_DATA09
value|0x19c 0x4a4 0x79c 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW4__EIM_AD09
value|0x19c 0x4a4 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW4__SD4_CMD
value|0x19c 0x4a4 0x858 0x4 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW4__GPIO4_IO01
value|0x19c 0x4a4 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW4__USB_OTG1_OC
value|0x19c 0x4a4 0x824 0x6 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW5__KEY_ROW5
value|0x1a0 0x4a8 0x768 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW5__AUD6_TXD
value|0x1a0 0x4a8 0x618 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW5__LCD_DATA11
value|0x1a0 0x4a8 0x7a4 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW5__EIM_AD11
value|0x1a0 0x4a8 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW5__SD4_DATA1
value|0x1a0 0x4a8 0x860 0x4 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW5__GPIO4_IO03
value|0x1a0 0x4a8 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW5__USB_OTG2_OC
value|0x1a0 0x4a8 0x820 0x6 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW6__KEY_ROW6
value|0x1a4 0x4ac 0x76c 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW6__UART4_TX_DATA
value|0x1a4 0x4ac 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW6__UART4_RX_DATA
value|0x1a4 0x4ac 0x814 0x1 0x3
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW6__LCD_DATA13
value|0x1a4 0x4ac 0x7ac 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW6__EIM_AD13
value|0x1a4 0x4ac 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW6__SD4_DATA3
value|0x1a4 0x4ac 0x868 0x4 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW6__GPIO4_IO05
value|0x1a4 0x4ac 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW6__SD3_VSELECT
value|0x1a4 0x4ac 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW7__KEY_ROW7
value|0x1a8 0x4b0 0x770 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW7__UART4_CTS_B
value|0x1a8 0x4b0 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW7__UART4_RTS_B
value|0x1a8 0x4b0 0x810 0x1 0x3
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW7__LCD_DATA15
value|0x1a8 0x4b0 0x7b4 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW7__EIM_AD15
value|0x1a8 0x4b0 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW7__SD4_DATA5
value|0x1a8 0x4b0 0x870 0x4 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW7__GPIO4_IO07
value|0x1a8 0x4b0 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_KEY_ROW7__SD1_CD_B
value|0x1a8 0x4b0 0x828 0x6 0x3
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_CLK__LCD_CLK
value|0x1ac 0x4b4 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_CLK__SD4_DATA4
value|0x1ac 0x4b4 0x86c 0x1 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_CLK__LCD_WR_RWN
value|0x1ac 0x4b4 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_CLK__EIM_RW
value|0x1ac 0x4b4 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_CLK__PWM4_OUT
value|0x1ac 0x4b4 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_CLK__GPIO2_IO15
value|0x1ac 0x4b4 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT0__LCD_DATA00
value|0x1b0 0x4b8 0x778 0x0 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT0__ECSPI1_MOSI
value|0x1b0 0x4b8 0x688 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT0__USB_OTG2_ID
value|0x1b0 0x4b8 0x5e0 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT0__PWM1_OUT
value|0x1b0 0x4b8 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT0__UART5_DTR_B
value|0x1b0 0x4b8 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT0__GPIO2_IO20
value|0x1b0 0x4b8 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT0__ARM_TRACE00
value|0x1b0 0x4b8 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT0__SRC_BOOT_CFG00
value|0x1b0 0x4b8 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT1__LCD_DATA01
value|0x1b4 0x4bc 0x77c 0x0 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT1__ECSPI1_MISO
value|0x1b4 0x4bc 0x684 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT1__USB_OTG1_ID
value|0x1b4 0x4bc 0x5dc 0x2 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT1__PWM2_OUT
value|0x1b4 0x4bc 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT1__AUD4_RXFS
value|0x1b4 0x4bc 0x5f0 0x4 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT1__GPIO2_IO21
value|0x1b4 0x4bc 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT1__ARM_TRACE01
value|0x1b4 0x4bc 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT1__SRC_BOOT_CFG01
value|0x1b4 0x4bc 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT10__LCD_DATA10
value|0x1b8 0x4c0 0x7a0 0x0 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT10__KEY_COL1
value|0x1b8 0x4c0 0x738 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT10__CSI_DATA07
value|0x1b8 0x4c0 0x64c 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT10__EIM_DATA04
value|0x1b8 0x4c0 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT10__ECSPI2_MISO
value|0x1b8 0x4c0 0x6a0 0x4 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT10__GPIO2_IO30
value|0x1b8 0x4c0 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT10__ARM_TRACE10
value|0x1b8 0x4c0 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT10__SRC_BOOT_CFG10
value|0x1b8 0x4c0 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT11__LCD_DATA11
value|0x1bc 0x4c4 0x7a4 0x0 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT11__KEY_ROW1
value|0x1bc 0x4c4 0x758 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT11__CSI_DATA06
value|0x1bc 0x4c4 0x648 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT11__EIM_DATA05
value|0x1bc 0x4c4 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT11__ECSPI2_SS1
value|0x1bc 0x4c4 0x6ac 0x4 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT11__GPIO2_IO31
value|0x1bc 0x4c4 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT11__ARM_TRACE11
value|0x1bc 0x4c4 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT11__SRC_BOOT_CFG11
value|0x1bc 0x4c4 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT12__LCD_DATA12
value|0x1c0 0x4c8 0x7a8 0x0 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT12__KEY_COL2
value|0x1c0 0x4c8 0x73c 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT12__CSI_DATA05
value|0x1c0 0x4c8 0x644 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT12__EIM_DATA06
value|0x1c0 0x4c8 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT12__UART5_RTS_B
value|0x1c0 0x4c8 0x818 0x4 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT12__UART5_CTS_B
value|0x1c0 0x4c8 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT12__GPIO3_IO00
value|0x1c0 0x4c8 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT12__ARM_TRACE12
value|0x1c0 0x4c8 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT12__SRC_BOOT_CFG12
value|0x1c0 0x4c8 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT13__LCD_DATA13
value|0x1c4 0x4cc 0x7ac 0x0 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT13__KEY_ROW2
value|0x1c4 0x4cc 0x75c 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT13__CSI_DATA04
value|0x1c4 0x4cc 0x640 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT13__EIM_DATA07
value|0x1c4 0x4cc 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT13__UART5_CTS_B
value|0x1c4 0x4cc 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT13__UART5_RTS_B
value|0x1c4 0x4cc 0x818 0x4 0x3
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT13__GPIO3_IO01
value|0x1c4 0x4cc 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT13__ARM_TRACE13
value|0x1c4 0x4cc 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT13__SRC_BOOT_CFG13
value|0x1c4 0x4cc 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT14__LCD_DATA14
value|0x1c8 0x4d0 0x7b0 0x0 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT14__KEY_COL3
value|0x1c8 0x4d0 0x740 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT14__CSI_DATA03
value|0x1c8 0x4d0 0x63c 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT14__EIM_DATA08
value|0x1c8 0x4d0 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT14__UART5_RX_DATA
value|0x1c8 0x4d0 0x81c 0x4 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT14__UART5_TX_DATA
value|0x1c8 0x4d0 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT14__GPIO3_IO02
value|0x1c8 0x4d0 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT14__ARM_TRACE14
value|0x1c8 0x4d0 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT14__SRC_BOOT_CFG14
value|0x1c8 0x4d0 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT15__LCD_DATA15
value|0x1cc 0x4d4 0x7b4 0x0 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT15__KEY_ROW3
value|0x1cc 0x4d4 0x760 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT15__CSI_DATA02
value|0x1cc 0x4d4 0x638 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT15__EIM_DATA09
value|0x1cc 0x4d4 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT15__UART5_TX_DATA
value|0x1cc 0x4d4 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT15__UART5_RX_DATA
value|0x1cc 0x4d4 0x81c 0x4 0x3
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT15__GPIO3_IO03
value|0x1cc 0x4d4 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT15__ARM_TRACE15
value|0x1cc 0x4d4 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT15__SRC_BOOT_CFG15
value|0x1cc 0x4d4 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT16__LCD_DATA16
value|0x1d0 0x4d8 0x7b8 0x0 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT16__KEY_COL4
value|0x1d0 0x4d8 0x744 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT16__CSI_DATA01
value|0x1d0 0x4d8 0x634 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT16__EIM_DATA10
value|0x1d0 0x4d8 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT16__I2C2_SCL
value|0x1d0 0x4d8 0x724 0x4 0x3
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT16__GPIO3_IO04
value|0x1d0 0x4d8 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT16__ARM_TRACE16
value|0x1d0 0x4d8 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT16__SRC_BOOT_CFG24
value|0x1d0 0x4d8 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT17__LCD_DATA17
value|0x1d4 0x4dc 0x7bc 0x0 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT17__KEY_ROW4
value|0x1d4 0x4dc 0x764 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT17__CSI_DATA00
value|0x1d4 0x4dc 0x630 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT17__EIM_DATA11
value|0x1d4 0x4dc 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT17__I2C2_SDA
value|0x1d4 0x4dc 0x728 0x4 0x3
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT17__GPIO3_IO05
value|0x1d4 0x4dc 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT17__ARM_TRACE17
value|0x1d4 0x4dc 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT17__SRC_BOOT_CFG25
value|0x1d4 0x4dc 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT18__LCD_DATA18
value|0x1d8 0x4e0 0x7c0 0x0 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT18__KEY_COL5
value|0x1d8 0x4e0 0x748 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT18__CSI_DATA15
value|0x1d8 0x4e0 0x66c 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT18__EIM_DATA12
value|0x1d8 0x4e0 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT18__GPT_CAPTURE1
value|0x1d8 0x4e0 0x710 0x4 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT18__GPIO3_IO06
value|0x1d8 0x4e0 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT18__ARM_TRACE18
value|0x1d8 0x4e0 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT18__SRC_BOOT_CFG26
value|0x1d8 0x4e0 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT19__LCD_DATA19
value|0x1dc 0x4e4 0x7c4 0x0 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT19__KEY_ROW5
value|0x1dc 0x4e4 0x768 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT19__CSI_DATA14
value|0x1dc 0x4e4 0x668 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT19__EIM_DATA13
value|0x1dc 0x4e4 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT19__GPT_CAPTURE2
value|0x1dc 0x4e4 0x714 0x4 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT19__GPIO3_IO07
value|0x1dc 0x4e4 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT19__ARM_TRACE19
value|0x1dc 0x4e4 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT19__SRC_BOOT_CFG27
value|0x1dc 0x4e4 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT2__LCD_DATA02
value|0x1e0 0x4e8 0x780 0x0 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT2__ECSPI1_SS0
value|0x1e0 0x4e8 0x68c 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT2__EPIT2_OUT
value|0x1e0 0x4e8 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT2__PWM3_OUT
value|0x1e0 0x4e8 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT2__AUD4_RXC
value|0x1e0 0x4e8 0x5ec 0x4 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT2__GPIO2_IO22
value|0x1e0 0x4e8 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT2__ARM_TRACE02
value|0x1e0 0x4e8 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT2__SRC_BOOT_CFG02
value|0x1e0 0x4e8 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT20__LCD_DATA20
value|0x1e4 0x4ec 0x7c8 0x0 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT20__KEY_COL6
value|0x1e4 0x4ec 0x74c 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT20__CSI_DATA13
value|0x1e4 0x4ec 0x664 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT20__EIM_DATA14
value|0x1e4 0x4ec 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT20__GPT_COMPARE1
value|0x1e4 0x4ec 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT20__GPIO3_IO08
value|0x1e4 0x4ec 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT20__ARM_TRACE20
value|0x1e4 0x4ec 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT20__SRC_BOOT_CFG28
value|0x1e4 0x4ec 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT21__LCD_DATA21
value|0x1e8 0x4f0 0x7cc 0x0 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT21__KEY_ROW6
value|0x1e8 0x4f0 0x76c 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT21__CSI_DATA12
value|0x1e8 0x4f0 0x660 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT21__EIM_DATA15
value|0x1e8 0x4f0 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT21__GPT_COMPARE2
value|0x1e8 0x4f0 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT21__GPIO3_IO09
value|0x1e8 0x4f0 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT21__ARM_TRACE21
value|0x1e8 0x4f0 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT21__SRC_BOOT_CFG29
value|0x1e8 0x4f0 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT22__LCD_DATA22
value|0x1ec 0x4f4 0x7d0 0x0 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT22__KEY_COL7
value|0x1ec 0x4f4 0x750 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT22__CSI_DATA11
value|0x1ec 0x4f4 0x65c 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT22__EIM_EB3_B
value|0x1ec 0x4f4 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT22__GPT_COMPARE3
value|0x1ec 0x4f4 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT22__GPIO3_IO10
value|0x1ec 0x4f4 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT22__ARM_TRACE22
value|0x1ec 0x4f4 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT22__SRC_BOOT_CFG30
value|0x1ec 0x4f4 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT23__LCD_DATA23
value|0x1f0 0x4f8 0x7d4 0x0 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT23__KEY_ROW7
value|0x1f0 0x4f8 0x770 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT23__CSI_DATA10
value|0x1f0 0x4f8 0x658 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT23__EIM_EB2_B
value|0x1f0 0x4f8 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT23__GPT_CLKIN
value|0x1f0 0x4f8 0x718 0x4 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT23__GPIO3_IO11
value|0x1f0 0x4f8 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT23__ARM_TRACE23
value|0x1f0 0x4f8 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT23__SRC_BOOT_CFG31
value|0x1f0 0x4f8 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT3__LCD_DATA03
value|0x1f4 0x4fc 0x784 0x0 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT3__ECSPI1_SCLK
value|0x1f4 0x4fc 0x67c 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT3__UART5_DSR_B
value|0x1f4 0x4fc 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT3__PWM4_OUT
value|0x1f4 0x4fc 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT3__AUD4_RXD
value|0x1f4 0x4fc 0x5e4 0x4 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT3__GPIO2_IO23
value|0x1f4 0x4fc 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT3__ARM_TRACE03
value|0x1f4 0x4fc 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT3__SRC_BOOT_CFG03
value|0x1f4 0x4fc 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT4__LCD_DATA04
value|0x1f8 0x500 0x788 0x0 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT4__ECSPI1_SS1
value|0x1f8 0x500 0x690 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT4__CSI_VSYNC
value|0x1f8 0x500 0x678 0x2 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT4__WDOG2_RESET_B_DEB
value|0x1f8 0x500 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT4__AUD4_TXC
value|0x1f8 0x500 0x5f4 0x4 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT4__GPIO2_IO24
value|0x1f8 0x500 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT4__ARM_TRACE04
value|0x1f8 0x500 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT4__SRC_BOOT_CFG04
value|0x1f8 0x500 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT5__LCD_DATA05
value|0x1fc 0x504 0x78c 0x0 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT5__ECSPI1_SS2
value|0x1fc 0x504 0x694 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT5__CSI_HSYNC
value|0x1fc 0x504 0x670 0x2 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT5__EIM_CS3_B
value|0x1fc 0x504 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT5__AUD4_TXFS
value|0x1fc 0x504 0x5f8 0x4 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT5__GPIO2_IO25
value|0x1fc 0x504 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT5__ARM_TRACE05
value|0x1fc 0x504 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT5__SRC_BOOT_CFG05
value|0x1fc 0x504 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT6__LCD_DATA06
value|0x200 0x508 0x790 0x0 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT6__ECSPI1_SS3
value|0x200 0x508 0x698 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT6__CSI_PIXCLK
value|0x200 0x508 0x674 0x2 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT6__EIM_DATA00
value|0x200 0x508 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT6__AUD4_TXD
value|0x200 0x508 0x5e8 0x4 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT6__GPIO2_IO26
value|0x200 0x508 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT6__ARM_TRACE06
value|0x200 0x508 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT6__SRC_BOOT_CFG06
value|0x200 0x508 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT7__LCD_DATA07
value|0x204 0x50c 0x794 0x0 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT7__ECSPI1_RDY
value|0x204 0x50c 0x680 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT7__CSI_MCLK
value|0x204 0x50c 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT7__EIM_DATA01
value|0x204 0x50c 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT7__AUDIO_CLK_OUT
value|0x204 0x50c 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT7__GPIO2_IO27
value|0x204 0x50c 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT7__ARM_TRACE07
value|0x204 0x50c 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT7__SRC_BOOT_CFG07
value|0x204 0x50c 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT8__LCD_DATA08
value|0x208 0x510 0x798 0x0 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT8__KEY_COL0
value|0x208 0x510 0x734 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT8__CSI_DATA09
value|0x208 0x510 0x654 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT8__EIM_DATA02
value|0x208 0x510 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT8__ECSPI2_SCLK
value|0x208 0x510 0x69c 0x4 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT8__GPIO2_IO28
value|0x208 0x510 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT8__ARM_TRACE08
value|0x208 0x510 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT8__SRC_BOOT_CFG08
value|0x208 0x510 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT9__LCD_DATA09
value|0x20c 0x514 0x79c 0x0 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT9__KEY_ROW0
value|0x20c 0x514 0x754 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT9__CSI_DATA08
value|0x20c 0x514 0x650 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT9__EIM_DATA03
value|0x20c 0x514 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT9__ECSPI2_MOSI
value|0x20c 0x514 0x6a4 0x4 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT9__GPIO2_IO29
value|0x20c 0x514 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT9__ARM_TRACE09
value|0x20c 0x514 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_DAT9__SRC_BOOT_CFG09
value|0x20c 0x514 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_ENABLE__LCD_ENABLE
value|0x210 0x518 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_ENABLE__SD4_DATA5
value|0x210 0x518 0x870 0x1 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_ENABLE__LCD_RD_E
value|0x210 0x518 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_ENABLE__EIM_OE_B
value|0x210 0x518 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_ENABLE__UART2_RX_DATA
value|0x210 0x518 0x804 0x4 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_ENABLE__UART2_TX_DATA
value|0x210 0x518 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_ENABLE__GPIO2_IO16
value|0x210 0x518 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_HSYNC__LCD_HSYNC
value|0x214 0x51c 0x774 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_HSYNC__SD4_DATA6
value|0x214 0x51c 0x874 0x1 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_HSYNC__LCD_CS
value|0x214 0x51c 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_HSYNC__EIM_CS0_B
value|0x214 0x51c 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_HSYNC__UART2_TX_DATA
value|0x214 0x51c 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_HSYNC__UART2_RX_DATA
value|0x214 0x51c 0x804 0x4 0x3
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_HSYNC__GPIO2_IO17
value|0x214 0x51c 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_HSYNC__ARM_TRACE_CLK
value|0x214 0x51c 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_RESET__LCD_RESET
value|0x218 0x520 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_RESET__EIM_DTACK_B
value|0x218 0x520 0x880 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_RESET__LCD_BUSY
value|0x218 0x520 0x774 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_RESET__EIM_WAIT_B
value|0x218 0x520 0x884 0x3 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_RESET__UART2_CTS_B
value|0x218 0x520 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_RESET__UART2_RTS_B
value|0x218 0x520 0x800 0x4 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_RESET__GPIO2_IO19
value|0x218 0x520 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_RESET__CCM_PMIC_READY
value|0x218 0x520 0x62c 0x6 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_VSYNC__LCD_VSYNC
value|0x21c 0x524 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_VSYNC__SD4_DATA7
value|0x21c 0x524 0x878 0x1 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_VSYNC__LCD_RS
value|0x21c 0x524 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_VSYNC__EIM_CS1_B
value|0x21c 0x524 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_VSYNC__UART2_RTS_B
value|0x21c 0x524 0x800 0x4 0x3
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_VSYNC__UART2_CTS_B
value|0x21c 0x524 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_VSYNC__GPIO2_IO18
value|0x21c 0x524 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_LCD_VSYNC__ARM_TRACE_CTL
value|0x21c 0x524 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_PWM1__PWM1_OUT
value|0x220 0x528 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_PWM1__CCM_CLKO
value|0x220 0x528 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_PWM1__AUDIO_CLK_OUT
value|0x220 0x528 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_PWM1__FEC_REF_OUT
value|0x220 0x528 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_PWM1__CSI_MCLK
value|0x220 0x528 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_PWM1__GPIO3_IO23
value|0x220 0x528 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_PWM1__EPIT1_OUT
value|0x220 0x528 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_REF_CLK_24M__XTALOSC_REF_CLK_24M
value|0x224 0x52c 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_REF_CLK_24M__I2C3_SCL
value|0x224 0x52c 0x72c 0x1 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_REF_CLK_24M__PWM3_OUT
value|0x224 0x52c 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_REF_CLK_24M__USB_OTG2_ID
value|0x224 0x52c 0x5e0 0x3 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_REF_CLK_24M__CCM_PMIC_READY
value|0x224 0x52c 0x62c 0x4 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_REF_CLK_24M__GPIO3_IO21
value|0x224 0x52c 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_REF_CLK_24M__SD3_WP
value|0x224 0x52c 0x84c 0x6 0x3
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_REF_CLK_32K__XTALOSC_REF_CLK_32K
value|0x228 0x530 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_REF_CLK_32K__I2C3_SDA
value|0x228 0x530 0x730 0x1 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_REF_CLK_32K__PWM4_OUT
value|0x228 0x530 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_REF_CLK_32K__USB_OTG1_ID
value|0x228 0x530 0x5dc 0x3 0x3
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_REF_CLK_32K__SD1_LCTL
value|0x228 0x530 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_REF_CLK_32K__GPIO3_IO22
value|0x228 0x530 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_REF_CLK_32K__SD3_CD_B
value|0x228 0x530 0x838 0x6 0x3
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_CLK__SD1_CLK
value|0x22c 0x534 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_CLK__FEC_MDIO
value|0x22c 0x534 0x6f4 0x1 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_CLK__KEY_COL0
value|0x22c 0x534 0x734 0x2 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_CLK__EPDC_SDCE4
value|0x22c 0x534 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_CLK__GPIO5_IO15
value|0x22c 0x534 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_CMD__SD1_CMD
value|0x230 0x538 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_CMD__FEC_TX_CLK
value|0x230 0x538 0x70c 0x1 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_CMD__KEY_ROW0
value|0x230 0x538 0x754 0x2 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_CMD__EPDC_SDCE5
value|0x230 0x538 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_CMD__GPIO5_IO14
value|0x230 0x538 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT0__SD1_DATA0
value|0x234 0x53c 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT0__FEC_RX_ER
value|0x234 0x53c 0x708 0x1 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT0__KEY_COL1
value|0x234 0x53c 0x738 0x2 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT0__EPDC_SDCE6
value|0x234 0x53c 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT0__GPIO5_IO11
value|0x234 0x53c 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT1__SD1_DATA1
value|0x238 0x540 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT1__FEC_RX_DV
value|0x238 0x540 0x704 0x1 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT1__KEY_ROW1
value|0x238 0x540 0x758 0x2 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT1__EPDC_SDCE7
value|0x238 0x540 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT1__GPIO5_IO08
value|0x238 0x540 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT2__SD1_DATA2
value|0x23c 0x544 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT2__FEC_RX_DATA1
value|0x23c 0x544 0x6fc 0x1 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT2__KEY_COL2
value|0x23c 0x544 0x73c 0x2 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT2__EPDC_SDCE8
value|0x23c 0x544 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT2__GPIO5_IO13
value|0x23c 0x544 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT3__SD1_DATA3
value|0x240 0x548 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT3__FEC_TX_DATA0
value|0x240 0x548 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT3__KEY_ROW2
value|0x240 0x548 0x75c 0x2 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT3__EPDC_SDCE9
value|0x240 0x548 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT3__GPIO5_IO06
value|0x240 0x548 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT4__SD1_DATA4
value|0x244 0x54c 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT4__FEC_MDC
value|0x244 0x54c 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT4__KEY_COL3
value|0x244 0x54c 0x740 0x2 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT4__EPDC_SDCLK_N
value|0x244 0x54c 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT4__UART4_RX_DATA
value|0x244 0x54c 0x814 0x4 0x4
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT4__UART4_TX_DATA
value|0x244 0x54c 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT4__GPIO5_IO12
value|0x244 0x54c 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT5__SD1_DATA5
value|0x248 0x550 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT5__FEC_RX_DATA0
value|0x248 0x550 0x6f8 0x1 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT5__KEY_ROW3
value|0x248 0x550 0x760 0x2 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT5__EPDC_SDOED
value|0x248 0x550 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT5__UART4_TX_DATA
value|0x248 0x550 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT5__UART4_RX_DATA
value|0x248 0x550 0x814 0x4 0x5
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT5__GPIO5_IO09
value|0x248 0x550 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT6__SD1_DATA6
value|0x24c 0x554 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT6__FEC_TX_EN
value|0x24c 0x554 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT6__KEY_COL4
value|0x24c 0x554 0x744 0x2 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT6__EPDC_SDOEZ
value|0x24c 0x554 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT6__UART4_RTS_B
value|0x24c 0x554 0x810 0x4 0x4
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT6__UART4_CTS_B
value|0x24c 0x554 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT6__GPIO5_IO07
value|0x24c 0x554 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT7__SD1_DATA7
value|0x250 0x558 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT7__FEC_TX_DATA1
value|0x250 0x558 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT7__KEY_ROW4
value|0x250 0x558 0x764 0x2 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT7__CCM_PMIC_READY
value|0x250 0x558 0x62c 0x3 0x3
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT7__UART4_CTS_B
value|0x250 0x558 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT7__UART4_RTS_B
value|0x250 0x558 0x810 0x4 0x5
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD1_DAT7__GPIO5_IO10
value|0x250 0x558 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_CLK__SD2_CLK
value|0x254 0x55c 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_CLK__AUD4_RXFS
value|0x254 0x55c 0x5f0 0x1 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_CLK__ECSPI3_SCLK
value|0x254 0x55c 0x6b0 0x2 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_CLK__CSI_DATA00
value|0x254 0x55c 0x630 0x3 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_CLK__GPIO5_IO05
value|0x254 0x55c 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_CMD__SD2_CMD
value|0x258 0x560 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_CMD__AUD4_RXC
value|0x258 0x560 0x5ec 0x1 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_CMD__ECSPI3_SS0
value|0x258 0x560 0x6c0 0x2 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_CMD__CSI_DATA01
value|0x258 0x560 0x634 0x3 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_CMD__EPIT1_OUT
value|0x258 0x560 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_CMD__GPIO5_IO04
value|0x258 0x560 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT0__SD2_DATA0
value|0x25c 0x564 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT0__AUD4_RXD
value|0x25c 0x564 0x5e4 0x1 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT0__ECSPI3_MOSI
value|0x25c 0x564 0x6bc 0x2 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT0__CSI_DATA02
value|0x25c 0x564 0x638 0x3 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT0__UART5_RTS_B
value|0x25c 0x564 0x818 0x4 0x4
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT0__UART5_CTS_B
value|0x25c 0x564 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT0__GPIO5_IO01
value|0x25c 0x564 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT1__SD2_DATA1
value|0x260 0x568 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT1__AUD4_TXC
value|0x260 0x568 0x5f4 0x1 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT1__ECSPI3_MISO
value|0x260 0x568 0x6b8 0x2 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT1__CSI_DATA03
value|0x260 0x568 0x63c 0x3 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT1__UART5_CTS_B
value|0x260 0x568 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT1__UART5_RTS_B
value|0x260 0x568 0x818 0x4 0x5
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT1__GPIO4_IO30
value|0x260 0x568 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT2__SD2_DATA2
value|0x264 0x56c 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT2__AUD4_TXFS
value|0x264 0x56c 0x5f8 0x1 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT2__FEC_COL
value|0x264 0x56c 0x6f0 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT2__CSI_DATA04
value|0x264 0x56c 0x640 0x3 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT2__UART5_RX_DATA
value|0x264 0x56c 0x81c 0x4 0x4
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT2__UART5_TX_DATA
value|0x264 0x56c 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT2__GPIO5_IO03
value|0x264 0x56c 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT3__SD2_DATA3
value|0x268 0x570 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT3__AUD4_TXD
value|0x268 0x570 0x5e8 0x1 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT3__FEC_RX_CLK
value|0x268 0x570 0x700 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT3__CSI_DATA05
value|0x268 0x570 0x644 0x3 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT3__UART5_TX_DATA
value|0x268 0x570 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT3__UART5_RX_DATA
value|0x268 0x570 0x81c 0x4 0x5
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT3__GPIO4_IO28
value|0x268 0x570 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT4__SD2_DATA4
value|0x26c 0x574 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT4__SD3_DATA4
value|0x26c 0x574 0x83c 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT4__UART2_RX_DATA
value|0x26c 0x574 0x804 0x2 0x4
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT4__UART2_TX_DATA
value|0x26c 0x574 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT4__CSI_DATA06
value|0x26c 0x574 0x648 0x3 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT4__SPDIF_OUT
value|0x26c 0x574 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT4__GPIO5_IO02
value|0x26c 0x574 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT5__SD2_DATA5
value|0x270 0x578 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT5__SD3_DATA5
value|0x270 0x578 0x840 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT5__UART2_TX_DATA
value|0x270 0x578 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT5__UART2_RX_DATA
value|0x270 0x578 0x804 0x2 0x5
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT5__CSI_DATA07
value|0x270 0x578 0x64c 0x3 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT5__SPDIF_IN
value|0x270 0x578 0x7f0 0x4 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT5__GPIO4_IO31
value|0x270 0x578 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT6__SD2_DATA6
value|0x274 0x57c 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT6__SD3_DATA6
value|0x274 0x57c 0x844 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT6__UART2_RTS_B
value|0x274 0x57c 0x800 0x2 0x4
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT6__UART2_CTS_B
value|0x274 0x57c 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT6__CSI_DATA08
value|0x274 0x57c 0x650 0x3 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT6__SD2_WP
value|0x274 0x57c 0x834 0x4 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT6__GPIO4_IO29
value|0x274 0x57c 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT7__SD2_DATA7
value|0x278 0x580 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT7__SD3_DATA7
value|0x278 0x580 0x848 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT7__UART2_CTS_B
value|0x278 0x580 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT7__UART2_RTS_B
value|0x278 0x580 0x800 0x2 0x5
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT7__CSI_DATA09
value|0x278 0x580 0x654 0x3 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT7__SD2_CD_B
value|0x278 0x580 0x830 0x4 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_DAT7__GPIO5_IO00
value|0x278 0x580 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_RST__SD2_RESET
value|0x27c 0x584 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_RST__FEC_REF_OUT
value|0x27c 0x584 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_RST__WDOG2_B
value|0x27c 0x584 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_RST__SPDIF_OUT
value|0x27c 0x584 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_RST__CSI_MCLK
value|0x27c 0x584 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD2_RST__GPIO4_IO27
value|0x27c 0x584 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD3_CLK__SD3_CLK
value|0x280 0x588 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD3_CLK__AUD5_RXFS
value|0x280 0x588 0x608 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD3_CLK__KEY_COL5
value|0x280 0x588 0x748 0x2 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD3_CLK__CSI_DATA10
value|0x280 0x588 0x658 0x3 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD3_CLK__WDOG1_RESET_B_DEB
value|0x280 0x588 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD3_CLK__GPIO5_IO18
value|0x280 0x588 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD3_CLK__USB_OTG1_PWR
value|0x280 0x588 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD3_CMD__SD3_CMD
value|0x284 0x58c 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD3_CMD__AUD5_RXC
value|0x284 0x58c 0x604 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD3_CMD__KEY_ROW5
value|0x284 0x58c 0x768 0x2 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD3_CMD__CSI_DATA11
value|0x284 0x58c 0x65c 0x3 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD3_CMD__USB_OTG2_ID
value|0x284 0x58c 0x5e0 0x4 0x3
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD3_CMD__GPIO5_IO21
value|0x284 0x58c 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD3_CMD__USB_OTG2_PWR
value|0x284 0x58c 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD3_DAT0__SD3_DATA0
value|0x288 0x590 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD3_DAT0__AUD5_RXD
value|0x288 0x590 0x5fc 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD3_DAT0__KEY_COL6
value|0x288 0x590 0x74c 0x2 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD3_DAT0__CSI_DATA12
value|0x288 0x590 0x660 0x3 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD3_DAT0__USB_OTG1_ID
value|0x288 0x590 0x5dc 0x4 0x4
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD3_DAT0__GPIO5_IO19
value|0x288 0x590 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD3_DAT1__SD3_DATA1
value|0x28c 0x594 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD3_DAT1__AUD5_TXC
value|0x28c 0x594 0x60c 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD3_DAT1__KEY_ROW6
value|0x28c 0x594 0x76c 0x2 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD3_DAT1__CSI_DATA13
value|0x28c 0x594 0x664 0x3 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD3_DAT1__SD1_VSELECT
value|0x28c 0x594 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD3_DAT1__GPIO5_IO20
value|0x28c 0x594 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD3_DAT1__JTAG_DE_B
value|0x28c 0x594 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD3_DAT2__SD3_DATA2
value|0x290 0x598 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD3_DAT2__AUD5_TXFS
value|0x290 0x598 0x610 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD3_DAT2__KEY_COL7
value|0x290 0x598 0x750 0x2 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD3_DAT2__CSI_DATA14
value|0x290 0x598 0x668 0x3 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD3_DAT2__EPIT1_OUT
value|0x290 0x598 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD3_DAT2__GPIO5_IO16
value|0x290 0x598 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD3_DAT2__USB_OTG2_OC
value|0x290 0x598 0x820 0x6 0x3
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD3_DAT3__SD3_DATA3
value|0x294 0x59c 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD3_DAT3__AUD5_TXD
value|0x294 0x59c 0x600 0x1 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD3_DAT3__KEY_ROW7
value|0x294 0x59c 0x770 0x2 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD3_DAT3__CSI_DATA15
value|0x294 0x59c 0x66c 0x3 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD3_DAT3__EPIT2_OUT
value|0x294 0x59c 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD3_DAT3__GPIO5_IO17
value|0x294 0x59c 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_SD3_DAT3__USB_OTG1_OC
value|0x294 0x59c 0x824 0x6 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_UART1_RXD__UART1_RX_DATA
value|0x298 0x5a0 0x7fc 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_UART1_RXD__UART1_TX_DATA
value|0x298 0x5a0 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_UART1_RXD__PWM1_OUT
value|0x298 0x5a0 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_UART1_RXD__UART4_RX_DATA
value|0x298 0x5a0 0x814 0x2 0x6
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_UART1_RXD__UART4_TX_DATA
value|0x298 0x5a0 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_UART1_RXD__FEC_COL
value|0x298 0x5a0 0x6f0 0x3 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_UART1_RXD__UART5_RX_DATA
value|0x298 0x5a0 0x81c 0x4 0x6
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_UART1_RXD__UART5_TX_DATA
value|0x298 0x5a0 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_UART1_RXD__GPIO3_IO16
value|0x298 0x5a0 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_UART1_TXD__UART1_TX_DATA
value|0x29c 0x5a4 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_UART1_TXD__UART1_RX_DATA
value|0x29c 0x5a4 0x7fc 0x0 0x1
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_UART1_TXD__PWM2_OUT
value|0x29c 0x5a4 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_UART1_TXD__UART4_TX_DATA
value|0x29c 0x5a4 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_UART1_TXD__UART4_RX_DATA
value|0x29c 0x5a4 0x814 0x2 0x7
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_UART1_TXD__FEC_RX_CLK
value|0x29c 0x5a4 0x700 0x3 0x2
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_UART1_TXD__UART5_TX_DATA
value|0x29c 0x5a4 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_UART1_TXD__UART5_RX_DATA
value|0x29c 0x5a4 0x81c 0x4 0x7
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_UART1_TXD__GPIO3_IO17
value|0x29c 0x5a4 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_UART1_TXD__UART5_DCD_B
value|0x29c 0x5a4 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_WDOG_B__WDOG1_B
value|0x2a0 0x5a8 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_WDOG_B__WDOG1_RESET_B_DEB
value|0x2a0 0x5a8 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_WDOG_B__UART5_RI_B
value|0x2a0 0x5a8 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX6SL_PAD_WDOG_B__GPIO3_IO18
value|0x2a0 0x5a8 0x000 0x5 0x0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DTS_IMX6SL_PINFUNC_H */
end_comment

end_unit

