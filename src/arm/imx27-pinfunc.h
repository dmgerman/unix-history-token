begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2013 Markus Pargmann<mpa@pengutronix.de>, Pengutronix  *  * The code contained herein is licensed under the GNU General Public  * License. You may obtain a copy of the GNU General Public License  * Version 2 or later at the following locations:  *  * http://www.opensource.org/licenses/gpl-license.html  * http://www.gnu.org/copyleft/gpl.html  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DTS_IMX27_PINFUNC_H
end_ifndef

begin_define
define|#
directive|define
name|__DTS_IMX27_PINFUNC_H
end_define

begin_comment
comment|/*  * The pin function ID is a tuple of  *<pin mux_id>  * mux_id consists of  * function + (direction<< 2) + (gpio_oconf<< 4) + (gpio_iconfa<< 8) + (gpio_iconfb<< 10)  *  * function:      0 - Primary function  *                1 - Alternate function  *                2 - GPIO  * direction:     0 - Input  *                1 - Output  * gpio_oconf:    0 - A_IN  *                1 - B_IN  *                2 - C_IN  *                3 - Data Register  * gpio_iconfa/b: 0 - GPIO_IN  *                1 - Interrupt Status Register  *                2 - 0  *                3 - 1  *  * 'pin' is an integer between 0 and 0xbf. imx27 has 6 ports with 32 configurable  * configurable pins each. 'pin' is PORT * 32 + PORT_PIN, PORT_PIN is the pin  * number on the specific port (between 0 and 31).  */
end_comment

begin_define
define|#
directive|define
name|MX27_PAD_USBH2_CLK__USBH2_CLK
value|0x00 0x000
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBH2_CLK__GPIO1_0
value|0x00 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBH2_DIR__USBH2_DIR
value|0x01 0x000
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBH2_DIR__GPIO1_1
value|0x01 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBH2_DATA7__USBH2_DATA7
value|0x02 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBH2_DATA7__GPIO1_2
value|0x02 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBH2_NXT__USBH2_NXT
value|0x03 0x000
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBH2_NXT__GPIO1_3
value|0x03 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBH2_STP__USBH2_STP
value|0x04 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBH2_STP__GPIO1_4
value|0x04 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_LSCLK__LSCLK
value|0x05 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_LSCLK__GPIO1_5
value|0x05 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_LD0__LD0
value|0x06 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_LD0__GPIO1_6
value|0x06 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_LD1__LD1
value|0x07 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_LD1__GPIO1_7
value|0x07 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_LD2__LD2
value|0x08 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_LD2__GPIO1_8
value|0x08 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_LD3__LD3
value|0x09 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_LD3__GPIO1_9
value|0x09 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_LD4__LD4
value|0x0a 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_LD4__GPIO1_10
value|0x0a 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_LD5__LD5
value|0x0b 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_LD5__GPIO1_11
value|0x0b 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_LD6__LD6
value|0x0c 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_LD6__GPIO1_12
value|0x0c 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_LD7__LD7
value|0x0d 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_LD7__GPIO1_13
value|0x0d 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_LD8__LD8
value|0x0e 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_LD8__GPIO1_14
value|0x0e 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_LD9__LD9
value|0x0f 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_LD9__GPIO1_15
value|0x0f 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_LD10__LD10
value|0x10 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_LD10__GPIO1_16
value|0x10 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_LD11__LD11
value|0x11 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_LD11__GPIO1_17
value|0x11 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_LD12__LD12
value|0x12 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_LD12__GPIO1_18
value|0x12 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_LD13__LD13
value|0x13 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_LD13__GPIO1_19
value|0x13 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_LD14__LD14
value|0x14 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_LD14__GPIO1_20
value|0x14 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_LD15__LD15
value|0x15 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_LD15__GPIO1_21
value|0x15 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_LD16__LD16
value|0x16 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_LD16__GPIO1_22
value|0x16 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_LD17__LD17
value|0x17 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_LD17__GPIO1_23
value|0x17 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_REV__REV
value|0x18 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_REV__GPIO1_24
value|0x18 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CLS__CLS
value|0x19 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CLS__GPIO1_25
value|0x19 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_PS__PS
value|0x1a 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_PS__GPIO1_26
value|0x1a 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SPL_SPR__SPL_SPR
value|0x1b 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SPL_SPR__GPIO1_27
value|0x1b 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_HSYNC__HSYNC
value|0x1c 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_HSYNC__GPIO1_28
value|0x1c 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_VSYNC__VSYNC
value|0x1d 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_VSYNC__GPIO1_29
value|0x1d 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CONTRAST__CONTRAST
value|0x1e 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CONTRAST__GPIO1_30
value|0x1e 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_OE_ACD__OE_ACD
value|0x1f 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_OE_ACD__GPIO1_31
value|0x1f 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SD2_D0__SD2_D0
value|0x24 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SD2_D0__MSHC_DATA0
value|0x24 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SD2_D0__GPIO2_4
value|0x24 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SD2_D1__SD2_D1
value|0x25 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SD2_D1__MSHC_DATA1
value|0x25 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SD2_D1__GPIO2_5
value|0x25 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SD2_D2__SD2_D2
value|0x26 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SD2_D2__MSHC_DATA2
value|0x26 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SD2_D2__GPIO2_6
value|0x26 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SD2_D3__SD2_D3
value|0x27 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SD2_D3__MSHC_DATA3
value|0x27 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SD2_D3__GPIO2_7
value|0x27 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SD2_CMD__SD2_CMD
value|0x28 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SD2_CMD__MSHC_BS
value|0x28 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SD2_CMD__GPIO2_8
value|0x28 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SD2_CLK__SD2_CLK
value|0x29 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SD2_CLK__MSHC_SCLK
value|0x29 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SD2_CLK__GPIO2_9
value|0x29 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSI_D0__CSI_D0
value|0x2a 0x000
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSI_D0__UART6_TXD
value|0x2a 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSI_D0__GPIO2_10
value|0x2a 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSI_D1__CSI_D1
value|0x2b 0x000
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSI_D1__UART6_RXD
value|0x2b 0x001
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSI_D1__GPIO2_11
value|0x2b 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSI_D2__CSI_D2
value|0x2c 0x000
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSI_D2__UART6_CTS
value|0x2c 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSI_D2__GPIO2_12
value|0x2c 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSI_D3__CSI_D3
value|0x2d 0x000
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSI_D3__UART6_RTS
value|0x2d 0x001
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSI_D3__GPIO2_13
value|0x2d 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSI_D4__CSI_D4
value|0x2e 0x000
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSI_D4__GPIO2_14
value|0x2e 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSI_MCLK__CSI_MCLK
value|0x2f 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSI_MCLK__GPIO2_15
value|0x2f 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSI_PIXCLK__CSI_PIXCLK
value|0x30 0x000
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSI_PIXCLK__GPIO2_16
value|0x30 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSI_D5__CSI_D5
value|0x31 0x000
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSI_D5__GPIO2_17
value|0x31 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSI_D6__CSI_D6
value|0x32 0x000
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSI_D6__UART5_TXD
value|0x32 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSI_D6__GPIO2_18
value|0x32 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSI_D7__CSI_D7
value|0x33 0x000
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSI_D7__UART5_RXD
value|0x33 0x001
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSI_D7__GPIO2_19
value|0x33 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSI_VSYNC__CSI_VSYNC
value|0x34 0x000
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSI_VSYNC__UART5_CTS
value|0x34 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSI_VSYNC__GPIO2_20
value|0x34 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSI_HSYNC__CSI_HSYNC
value|0x35 0x000
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSI_HSYNC__UART5_RTS
value|0x35 0x001
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSI_HSYNC__GPIO2_21
value|0x35 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBH1_SUSP__USBH1_SUSP
value|0x36 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBH1_SUSP__GPIO2_22
value|0x36 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USB_PWR__USB_PWR
value|0x37 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USB_PWR__GPIO2_23
value|0x37 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USB_OC_B__USB_OC_B
value|0x38 0x000
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USB_OC_B__GPIO2_24
value|0x38 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBH1_RCV__USBH1_RCV
value|0x39 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBH1_RCV__GPIO2_25
value|0x39 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBH1_FS__USBH1_FS
value|0x3a 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBH1_FS__UART4_RTS
value|0x3a 0x001
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBH1_FS__GPIO2_26
value|0x3a 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBH1_OE_B__USBH1_OE_B
value|0x3b 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBH1_OE_B__GPIO2_27
value|0x3b 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBH1_TXDM__USBH1_TXDM
value|0x3c 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBH1_TXDM__UART4_TXD
value|0x3c 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBH1_TXDM__GPIO2_28
value|0x3c 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBH1_TXDP__USBH1_TXDP
value|0x3d 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBH1_TXDP__UART4_CTS
value|0x3d 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBH1_TXDP__GPIO2_29
value|0x3d 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBH1_RXDM__USBH1_RXDM
value|0x3e 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBH1_RXDM__GPIO2_30
value|0x3e 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBH1_RXDP__USBH1_RXDP
value|0x3f 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBH1_RXDP__UART4_RXD
value|0x3f 0x001
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBH1_RXDP__GPIO2_31
value|0x3f 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_I2C2_SDA__I2C2_SDA
value|0x45 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_I2C2_SDA__GPIO3_5
value|0x45 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_I2C2_SCL__I2C2_SCL
value|0x46 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_I2C2_SCL__GPIO3_6
value|0x46 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBOTG_DATA5__USBOTG_DATA5
value|0x47 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBOTG_DATA5__GPIO3_7
value|0x47 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBOTG_DATA6__USBOTG_DATA6
value|0x48 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBOTG_DATA6__GPIO3_8
value|0x48 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBOTG_DATA0__USBOTG_DATA0
value|0x49 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBOTG_DATA0__GPIO3_9
value|0x49 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBOTG_DATA2__USBOTG_DATA2
value|0x4a 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBOTG_DATA2__GPIO3_10
value|0x4a 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBOTG_DATA1__USBOTG_DATA1
value|0x4b 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBOTG_DATA1__GPIO3_11
value|0x4b 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBOTG_DATA4__USBOTG_DATA4
value|0x4c 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBOTG_DATA4__GPIO3_12
value|0x4c 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBOTG_DATA3__USBOTG_DATA3
value|0x4d 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBOTG_DATA3__GPIO3_13
value|0x4d 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_TOUT__TOUT
value|0x4e 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_TOUT__GPIO3_14
value|0x4e 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_TIN__TIN
value|0x4f 0x000
end_define

begin_define
define|#
directive|define
name|MX27_PAD_TIN__GPIO3_15
value|0x4f 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SSI4_FS__SSI4_FS
value|0x50 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SSI4_FS__GPIO3_16
value|0x50 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SSI4_RXDAT__SSI4_RXDAT
value|0x51 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SSI4_RXDAT__GPIO3_17
value|0x51 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SSI4_TXDAT__SSI4_TXDAT
value|0x52 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SSI4_TXDAT__GPIO3_18
value|0x52 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SSI4_CLK__SSI4_CLK
value|0x53 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SSI4_CLK__GPIO3_19
value|0x53 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SSI1_FS__SSI1_FS
value|0x54 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SSI1_FS__GPIO3_20
value|0x54 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SSI1_RXDAT__SSI1_RXDAT
value|0x55 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SSI1_RXDAT__GPIO3_21
value|0x55 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SSI1_TXDAT__SSI1_TXDAT
value|0x56 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SSI1_TXDAT__GPIO3_22
value|0x56 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SSI1_CLK__SSI1_CLK
value|0x57 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SSI1_CLK__GPIO3_23
value|0x57 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SSI2_FS__SSI2_FS
value|0x58 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SSI2_FS__GPT5_TOUT
value|0x58 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SSI2_FS__GPIO3_24
value|0x58 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SSI2_RXDAT__SSI2_RXDAT
value|0x59 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SSI2_RXDAT__GPTS_TIN
value|0x59 0x001
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SSI2_RXDAT__GPIO3_25
value|0x59 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SSI2_TXDAT__SSI2_TXDAT
value|0x5a 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SSI2_TXDAT__GPT4_TOUT
value|0x5a 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SSI2_TXDAT__GPIO3_26
value|0x5a 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SSI2_CLK__SSI2_CLK
value|0x5b 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SSI2_CLK__GPT4_TIN
value|0x5b 0x001
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SSI2_CLK__GPIO3_27
value|0x5b 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SSI3_FS__SSI3_FS
value|0x5c 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SSI3_FS__SLCDC2_D0
value|0x5c 0x001
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SSI3_FS__GPIO3_28
value|0x5c 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SSI3_RXDAT__SSI3_RXDAT
value|0x5d 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SSI3_RXDAT__SLCDC2_RS
value|0x5d 0x001
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SSI3_RXDAT__GPIO3_29
value|0x5d 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SSI3_TXDAT__SSI3_TXDAT
value|0x5e 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SSI3_TXDAT__SLCDC2_CS
value|0x5e 0x001
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SSI3_TXDAT__GPIO3_30
value|0x5e 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SSI3_CLK__SSI3_CLK
value|0x5f 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SSI3_CLK__SLCDC2_CLK
value|0x5f 0x001
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SSI3_CLK__GPIO3_31
value|0x5f 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SD3_CMD__SD3_CMD
value|0x60 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SD3_CMD__FEC_TXD0
value|0x60 0x006
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SD3_CMD__GPIO4_0
value|0x60 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SD3_CLK__SD3_CLK
value|0x61 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SD3_CLK__ETMTRACEPKT15
value|0x61 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SD3_CLK__FEC_TXD1
value|0x61 0x006
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SD3_CLK__GPIO4_1
value|0x61 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA0__ATA_DATA0
value|0x62 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA0__SD3_D0
value|0x62 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA0__FEC_TXD2
value|0x62 0x006
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA0__GPIO4_2
value|0x62 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA1__ATA_DATA1
value|0x63 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA1__SD3_D1
value|0x63 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA1__FEC_TXD3
value|0x63 0x006
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA1__GPIO4_3
value|0x63 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA2__ATA_DATA2
value|0x64 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA2__SD3_D2
value|0x64 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA2__FEC_RX_ER
value|0x64 0x002
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA2__GPIO4_4
value|0x64 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA3__ATA_DATA3
value|0x65 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA3__SD3_D3
value|0x65 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA3__FEC_RXD1
value|0x65 0x002
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA3__GPIO4_5
value|0x65 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA4__ATA_DATA4
value|0x66 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA4__ETMTRACEPKT14
value|0x66 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA4__FEC_RXD2
value|0x66 0x002
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA4__GPIO4_6
value|0x66 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA5__ATA_DATA5
value|0x67 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA5__ETMTRACEPKT13
value|0x67 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA5__FEC_RXD3
value|0x67 0x002
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA5__GPIO4_7
value|0x67 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA6__ATA_DATA6
value|0x68 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA6__FEC_MDIO
value|0x68 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA6__GPIO4_8
value|0x68 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA7__ATA_DATA7
value|0x69 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA7__ETMTRACEPKT12
value|0x69 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA7__FEC_MDC
value|0x69 0x006
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA7__GPIO4_9
value|0x69 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA8__ATA_DATA8
value|0x6a 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA8__ETMTRACEPKT11
value|0x6a 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA8__FEC_CRS
value|0x6a 0x002
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA8__GPIO4_10
value|0x6a 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA9__ATA_DATA9
value|0x6b 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA9__ETMTRACEPKT10
value|0x6b 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA9__FEC_TX_CLK
value|0x6b 0x002
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA9__GPIO4_11
value|0x6b 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA10__ATA_DATA10
value|0x6c 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA10__ETMTRACEPKT9
value|0x6c 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA10__FEC_RXD0
value|0x6c 0x002
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA10__GPIO4_12
value|0x6c 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA11__ATA_DATA11
value|0x6d 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA11__ETMTRACEPKT8
value|0x6d 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA11__FEC_RX_DV
value|0x6d 0x002
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA11__GPIO4_13
value|0x6d 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA12__ATA_DATA12
value|0x6e 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA12__ETMTRACEPKT7
value|0x6e 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA12__FEC_RX_CLK
value|0x6e 0x002
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA12__GPIO4_14
value|0x6e 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA13__ATA_DATA13
value|0x6f 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA13__ETMTRACEPKT6
value|0x6f 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA13__FEC_COL
value|0x6f 0x002
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA13__GPIO4_15
value|0x6f 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA14__ATA_DATA14
value|0x70 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA14__ETMTRACEPKT5
value|0x70 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA14__FEC_TX_ER
value|0x70 0x006
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA14__GPIO4_16
value|0x70 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_I2C_DATA__I2C_DATA
value|0x71 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_I2C_DATA__GPIO4_17
value|0x71 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_I2C_CLK__I2C_CLK
value|0x72 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_I2C_CLK__GPIO4_18
value|0x72 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSPI2_SS2__CSPI2_SS2
value|0x73 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSPI2_SS2__USBH2_DATA4
value|0x73 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSPI2_SS2__GPIO4_19
value|0x73 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSPI2_SS1__CSPI2_SS1
value|0x74 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSPI2_SS1__USBH2_DATA3
value|0x74 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSPI2_SS1__GPIO4_20
value|0x74 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSPI2_SS0__CSPI2_SS0
value|0x75 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSPI2_SS0__USBH2_DATA6
value|0x75 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSPI2_SS0__GPIO4_21
value|0x75 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSPI2_SCLK__CSPI2_SCLK
value|0x76 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSPI2_SCLK__USBH2_DATA0
value|0x76 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSPI2_SCLK__GPIO4_22
value|0x76 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSPI2_MISO__CSPI2_MISO
value|0x77 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSPI2_MISO__USBH2_DATA2
value|0x77 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSPI2_MISO__GPIO4_23
value|0x77 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSPI2_MOSI__CSPI2_MOSI
value|0x78 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSPI2_MOSI__USBH2_DATA1
value|0x78 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSPI2_MOSI__GPIO4_24
value|0x78 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSPI1_RDY__CSPI1_RDY
value|0x79 0x000
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSPI1_RDY__GPIO4_25
value|0x79 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSPI1_SS2__CSPI1_SS2
value|0x7a 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSPI1_SS2__USBH2_DATA5
value|0x7a 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSPI1_SS2__GPIO4_26
value|0x7a 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSPI1_SS1__CSPI1_SS1
value|0x7b 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSPI1_SS1__GPIO4_27
value|0x7b 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSPI1_SS0__CSPI1_SS0
value|0x7c 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSPI1_SS0__GPIO4_28
value|0x7c 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSPI1_SCLK__CSPI1_SCLK
value|0x7d 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSPI1_SCLK__GPIO4_29
value|0x7d 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSPI1_MISO__CSPI1_MISO
value|0x7e 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSPI1_MISO__GPIO4_30
value|0x7e 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSPI1_MOSI__CSPI1_MOSI
value|0x7f 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CSPI1_MOSI__GPIO4_31
value|0x7f 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBOTG_NXT__USBOTG_NXT
value|0x80 0x000
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBOTG_NXT__KP_COL6A
value|0x80 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBOTG_NXT__GPIO5_0
value|0x80 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBOTG_STP__USBOTG_STP
value|0x81 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBOTG_STP__KP_ROW6A
value|0x81 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBOTG_STP__GPIO5_1
value|0x81 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBOTG_DIR__USBOTG_DIR
value|0x82 0x000
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBOTG_DIR__KP_ROW7A
value|0x82 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBOTG_DIR__GPIO5_2
value|0x82 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_UART2_CTS__UART2_CTS
value|0x83 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_UART2_CTS__KP_COL7
value|0x83 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_UART2_CTS__GPIO5_3
value|0x83 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_UART2_RTS__UART2_RTS
value|0x84 0x000
end_define

begin_define
define|#
directive|define
name|MX27_PAD_UART2_RTS__KP_ROW7
value|0x84 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_UART2_RTS__GPIO5_4
value|0x84 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_PWMO__PWMO
value|0x85 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_PWMO__GPIO5_5
value|0x85 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_UART2_TXD__UART2_TXD
value|0x86 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_UART2_TXD__KP_COL6
value|0x86 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_UART2_TXD__GPIO5_6
value|0x86 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_UART2_RXD__UART2_RXD
value|0x87 0x000
end_define

begin_define
define|#
directive|define
name|MX27_PAD_UART2_RXD__KP_ROW6
value|0x87 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_UART2_RXD__GPIO5_7
value|0x87 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_UART3_TXD__UART3_TXD
value|0x88 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_UART3_TXD__GPIO5_8
value|0x88 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_UART3_RXD__UART3_RXD
value|0x89 0x000
end_define

begin_define
define|#
directive|define
name|MX27_PAD_UART3_RXD__GPIO5_9
value|0x89 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_UART3_CTS__UART3_CTS
value|0x8a 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_UART3_CTS__GPIO5_10
value|0x8a 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_UART3_RTS__UART3_RTS
value|0x8b 0x000
end_define

begin_define
define|#
directive|define
name|MX27_PAD_UART3_RTS__GPIO5_11
value|0x8b 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_UART1_TXD__UART1_TXD
value|0x8c 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_UART1_TXD__GPIO5_12
value|0x8c 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_UART1_RXD__UART1_RXD
value|0x8d 0x000
end_define

begin_define
define|#
directive|define
name|MX27_PAD_UART1_RXD__GPIO5_13
value|0x8d 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_UART1_CTS__UART1_CTS
value|0x8e 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_UART1_CTS__GPIO5_14
value|0x8e 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_UART1_RTS__UART1_RTS
value|0x8f 0x000
end_define

begin_define
define|#
directive|define
name|MX27_PAD_UART1_RTS__GPIO5_15
value|0x8f 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_RTCK__RTCK
value|0x90 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_RTCK__OWIRE
value|0x90 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_RTCK__GPIO5_16
value|0x90 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_RESET_OUT_B__RESET_OUT_B
value|0x91 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_RESET_OUT_B__GPIO5_17
value|0x91 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SD1_D0__SD1_D0
value|0x92 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SD1_D0__CSPI3_MISO
value|0x92 0x001
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SD1_D0__GPIO5_18
value|0x92 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SD1_D1__SD1_D1
value|0x93 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SD1_D1__GPIO5_19
value|0x93 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SD1_D2__SD1_D2
value|0x94 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SD1_D2__GPIO5_20
value|0x94 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SD1_D3__SD1_D3
value|0x95 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SD1_D3__CSPI3_SS
value|0x95 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SD1_D3__GPIO5_21
value|0x95 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SD1_CMD__SD1_CMD
value|0x96 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SD1_CMD__CSPI3_MOSI
value|0x96 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SD1_CMD__GPIO5_22
value|0x96 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SD1_CLK__SD1_CLK
value|0x97 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SD1_CLK__CSPI3_SCLK
value|0x97 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_SD1_CLK__GPIO5_23
value|0x97 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBOTG_CLK__USBOTG_CLK
value|0x98 0x000
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBOTG_CLK__GPIO5_24
value|0x98 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBOTG_DATA7__USBOTG_DATA7
value|0x99 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_USBOTG_DATA7__GPIO5_25
value|0x99 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_NFRB__NFRB
value|0xa0 0x000
end_define

begin_define
define|#
directive|define
name|MX27_PAD_NFRB__ETMTRACEPKT3
value|0xa0 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_NFRB__GPIO6_0
value|0xa0 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_NFCLE__NFCLE
value|0xa1 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_NFCLE__ETMTRACEPKT0
value|0xa1 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_NFCLE__GPIO6_1
value|0xa1 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_NFWP_B__NFWP_B
value|0xa2 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_NFWP_B__ETMTRACEPKT1
value|0xa2 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_NFWP_B__GPIO6_2
value|0xa2 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_NFCE_B__NFCE_B
value|0xa3 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_NFCE_B__ETMTRACEPKT2
value|0xa3 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_NFCE_B__GPIO6_3
value|0xa3 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_NFALE__NFALE
value|0xa4 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_NFALE__ETMPIPESTAT0
value|0xa4 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_NFALE__GPIO6_4
value|0xa4 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_NFRE_B__NFRE_B
value|0xa5 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_NFRE_B__ETMPIPESTAT1
value|0xa5 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_NFRE_B__GPIO6_5
value|0xa5 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_NFWE_B__NFWE_B
value|0xa6 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_NFWE_B__ETMPIPESTAT2
value|0xa6 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_NFWE_B__GPIO6_6
value|0xa6 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_PC_POE__PC_POE
value|0xa7 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_PC_POE__ATA_BUFFER_EN
value|0xa7 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_PC_POE__GPIO6_7
value|0xa7 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_PC_RW_B__PC_RW_B
value|0xa8 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_PC_RW_B__ATA_IORDY
value|0xa8 0x001
end_define

begin_define
define|#
directive|define
name|MX27_PAD_PC_RW_B__GPIO6_8
value|0xa8 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_IOIS16__IOIS16
value|0xa9 0x000
end_define

begin_define
define|#
directive|define
name|MX27_PAD_IOIS16__ATA_INTRQ
value|0xa9 0x001
end_define

begin_define
define|#
directive|define
name|MX27_PAD_IOIS16__GPIO6_9
value|0xa9 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_PC_RST__PC_RST
value|0xaa 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_PC_RST__ATA_RESET_B
value|0xaa 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_PC_RST__GPIO6_10
value|0xaa 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_PC_BVD2__PC_BVD2
value|0xab 0x000
end_define

begin_define
define|#
directive|define
name|MX27_PAD_PC_BVD2__ATA_DMACK
value|0xab 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_PC_BVD2__GPIO6_11
value|0xab 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_PC_BVD1__PC_BVD1
value|0xac 0x000
end_define

begin_define
define|#
directive|define
name|MX27_PAD_PC_BVD1__ATA_DMARQ
value|0xac 0x001
end_define

begin_define
define|#
directive|define
name|MX27_PAD_PC_BVD1__GPIO6_12
value|0xac 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_PC_VS2__PC_VS2
value|0xad 0x000
end_define

begin_define
define|#
directive|define
name|MX27_PAD_PC_VS2__ATA_DA0
value|0xad 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_PC_VS2__GPIO6_13
value|0xad 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_PC_VS1__PC_VS1
value|0xae 0x000
end_define

begin_define
define|#
directive|define
name|MX27_PAD_PC_VS1__ATA_DA1
value|0xae 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_PC_VS1__GPIO6_14
value|0xae 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CLKO__CLKO
value|0xaf 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CLKO__GPIO6_15
value|0xaf 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_PC_PWRON__PC_PWRON
value|0xb0 0x000
end_define

begin_define
define|#
directive|define
name|MX27_PAD_PC_PWRON__ATA_DA2
value|0xb0 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_PC_PWRON__GPIO6_16
value|0xb0 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_PC_READY__PC_READY
value|0xb1 0x000
end_define

begin_define
define|#
directive|define
name|MX27_PAD_PC_READY__ATA_CS0
value|0xb1 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_PC_READY__GPIO6_17
value|0xb1 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_PC_WAIT_B__PC_WAIT_B
value|0xb2 0x000
end_define

begin_define
define|#
directive|define
name|MX27_PAD_PC_WAIT_B__ATA_CS1
value|0xb2 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_PC_WAIT_B__GPIO6_18
value|0xb2 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_PC_CD2_B__PC_CD2_B
value|0xb3 0x000
end_define

begin_define
define|#
directive|define
name|MX27_PAD_PC_CD2_B__ATA_DIOW
value|0xb3 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_PC_CD2_B__GPIO6_19
value|0xb3 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_PC_CD1_B__PC_CD1_B
value|0xb4 0x000
end_define

begin_define
define|#
directive|define
name|MX27_PAD_PC_CD1_B__ATA_DIOR
value|0xb4 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_PC_CD1_B__GPIO6_20
value|0xb4 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CS4_B__CS4_B
value|0xb5 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CS4_B__ETMTRACESYNC
value|0xb5 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CS4_B__GPIO6_21
value|0xb5 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CS5_B__CS5_B
value|0xb6 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CS5_B__ETMTRACECLK
value|0xb6 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_CS5_B__GPIO6_22
value|0xb6 0x032
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA15__ATA_DATA15
value|0xb7 0x004
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA15__ETMTRACEPKT4
value|0xb7 0x005
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA15__FEC_TX_EN
value|0xb7 0x006
end_define

begin_define
define|#
directive|define
name|MX27_PAD_ATA_DATA15__GPIO6_23
value|0xb7 0x032
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DTS_IMX27_PINFUNC_H */
end_comment

end_unit

