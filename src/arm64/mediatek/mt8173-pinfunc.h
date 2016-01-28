begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2014 MediaTek Inc.  * Author: Hongzhou.Yang<hongzhou.yang@mediatek.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DTS_MT8173_PINFUNC_H
end_ifndef

begin_define
define|#
directive|define
name|__DTS_MT8173_PINFUNC_H
end_define

begin_include
include|#
directive|include
file|<dt-bindings/pinctrl/mt65xx.h>
end_include

begin_define
define|#
directive|define
name|MT8173_PIN_0_EINT0__FUNC_GPIO0
value|(MTK_PIN_NO(0) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_0_EINT0__FUNC_IRDA_PDN
value|(MTK_PIN_NO(0) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_0_EINT0__FUNC_I2S1_WS
value|(MTK_PIN_NO(0) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_0_EINT0__FUNC_AUD_SPDIF
value|(MTK_PIN_NO(0) | 3)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_0_EINT0__FUNC_UTXD0
value|(MTK_PIN_NO(0) | 4)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_0_EINT0__FUNC_DBG_MON_A_20_
value|(MTK_PIN_NO(0) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_1_EINT1__FUNC_GPIO1
value|(MTK_PIN_NO(1) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_1_EINT1__FUNC_IRDA_RXD
value|(MTK_PIN_NO(1) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_1_EINT1__FUNC_I2S1_BCK
value|(MTK_PIN_NO(1) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_1_EINT1__FUNC_SDA5
value|(MTK_PIN_NO(1) | 3)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_1_EINT1__FUNC_URXD0
value|(MTK_PIN_NO(1) | 4)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_1_EINT1__FUNC_DBG_MON_A_21_
value|(MTK_PIN_NO(1) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_2_EINT2__FUNC_GPIO2
value|(MTK_PIN_NO(2) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_2_EINT2__FUNC_IRDA_TXD
value|(MTK_PIN_NO(2) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_2_EINT2__FUNC_I2S1_MCK
value|(MTK_PIN_NO(2) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_2_EINT2__FUNC_SCL5
value|(MTK_PIN_NO(2) | 3)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_2_EINT2__FUNC_UTXD3
value|(MTK_PIN_NO(2) | 4)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_2_EINT2__FUNC_DBG_MON_A_22_
value|(MTK_PIN_NO(2) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_3_EINT3__FUNC_GPIO3
value|(MTK_PIN_NO(3) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_3_EINT3__FUNC_DSI1_TE
value|(MTK_PIN_NO(3) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_3_EINT3__FUNC_I2S1_DO_1
value|(MTK_PIN_NO(3) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_3_EINT3__FUNC_SDA3
value|(MTK_PIN_NO(3) | 3)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_3_EINT3__FUNC_URXD3
value|(MTK_PIN_NO(3) | 4)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_3_EINT3__FUNC_DBG_MON_A_23_
value|(MTK_PIN_NO(3) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_4_EINT4__FUNC_GPIO4
value|(MTK_PIN_NO(4) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_4_EINT4__FUNC_DISP_PWM1
value|(MTK_PIN_NO(4) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_4_EINT4__FUNC_I2S1_DO_2
value|(MTK_PIN_NO(4) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_4_EINT4__FUNC_SCL3
value|(MTK_PIN_NO(4) | 3)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_4_EINT4__FUNC_UCTS3
value|(MTK_PIN_NO(4) | 4)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_4_EINT4__FUNC_SFWP_B
value|(MTK_PIN_NO(4) | 6)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_5_EINT5__FUNC_GPIO5
value|(MTK_PIN_NO(5) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_5_EINT5__FUNC_PCM1_CLK
value|(MTK_PIN_NO(5) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_5_EINT5__FUNC_I2S2_WS
value|(MTK_PIN_NO(5) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_5_EINT5__FUNC_SPI_CK_3_
value|(MTK_PIN_NO(5) | 3)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_5_EINT5__FUNC_URTS3
value|(MTK_PIN_NO(5) | 4)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_5_EINT5__FUNC_AP_MD32_JTAG_TMS
value|(MTK_PIN_NO(5) | 5)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_5_EINT5__FUNC_SFOUT
value|(MTK_PIN_NO(5) | 6)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_6_EINT6__FUNC_GPIO6
value|(MTK_PIN_NO(6) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_6_EINT6__FUNC_PCM1_SYNC
value|(MTK_PIN_NO(6) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_6_EINT6__FUNC_I2S2_BCK
value|(MTK_PIN_NO(6) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_6_EINT6__FUNC_SPI_MI_3_
value|(MTK_PIN_NO(6) | 3)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_6_EINT6__FUNC_AP_MD32_JTAG_TCK
value|(MTK_PIN_NO(6) | 5)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_6_EINT6__FUNC_SFCS0
value|(MTK_PIN_NO(6) | 6)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_7_EINT7__FUNC_GPIO7
value|(MTK_PIN_NO(7) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_7_EINT7__FUNC_PCM1_DI
value|(MTK_PIN_NO(7) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_7_EINT7__FUNC_I2S2_DI_1
value|(MTK_PIN_NO(7) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_7_EINT7__FUNC_SPI_MO_3_
value|(MTK_PIN_NO(7) | 3)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_7_EINT7__FUNC_AP_MD32_JTAG_TDI
value|(MTK_PIN_NO(7) | 5)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_7_EINT7__FUNC_SFHOLD
value|(MTK_PIN_NO(7) | 6)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_8_EINT8__FUNC_GPIO8
value|(MTK_PIN_NO(8) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_8_EINT8__FUNC_PCM1_DO
value|(MTK_PIN_NO(8) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_8_EINT8__FUNC_I2S2_DI_2
value|(MTK_PIN_NO(8) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_8_EINT8__FUNC_SPI_CS_3_
value|(MTK_PIN_NO(8) | 3)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_8_EINT8__FUNC_AUD_SPDIF
value|(MTK_PIN_NO(8) | 4)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_8_EINT8__FUNC_AP_MD32_JTAG_TDO
value|(MTK_PIN_NO(8) | 5)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_8_EINT8__FUNC_SFIN
value|(MTK_PIN_NO(8) | 6)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_9_EINT9__FUNC_GPIO9
value|(MTK_PIN_NO(9) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_9_EINT9__FUNC_USB_DRVVBUS_P0
value|(MTK_PIN_NO(9) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_9_EINT9__FUNC_I2S2_MCK
value|(MTK_PIN_NO(9) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_9_EINT9__FUNC_USB_DRVVBUS_P1
value|(MTK_PIN_NO(9) | 4)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_9_EINT9__FUNC_AP_MD32_JTAG_TRST
value|(MTK_PIN_NO(9) | 5)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_9_EINT9__FUNC_SFCK
value|(MTK_PIN_NO(9) | 6)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_10_EINT10__FUNC_GPIO10
value|(MTK_PIN_NO(10) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_10_EINT10__FUNC_CLKM0
value|(MTK_PIN_NO(10) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_10_EINT10__FUNC_DSI1_TE
value|(MTK_PIN_NO(10) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_10_EINT10__FUNC_DISP_PWM1
value|(MTK_PIN_NO(10) | 3)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_10_EINT10__FUNC_PWM4
value|(MTK_PIN_NO(10) | 4)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_10_EINT10__FUNC_IRDA_RXD
value|(MTK_PIN_NO(10) | 5)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_11_EINT11__FUNC_GPIO11
value|(MTK_PIN_NO(11) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_11_EINT11__FUNC_CLKM1
value|(MTK_PIN_NO(11) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_11_EINT11__FUNC_I2S3_WS
value|(MTK_PIN_NO(11) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_11_EINT11__FUNC_USB_DRVVBUS_P0
value|(MTK_PIN_NO(11) | 3)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_11_EINT11__FUNC_PWM5
value|(MTK_PIN_NO(11) | 4)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_11_EINT11__FUNC_IRDA_TXD
value|(MTK_PIN_NO(11) | 5)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_11_EINT11__FUNC_USB_DRVVBUS_P1
value|(MTK_PIN_NO(11) | 6)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_11_EINT11__FUNC_DBG_MON_B_30_
value|(MTK_PIN_NO(11) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_12_EINT12__FUNC_GPIO12
value|(MTK_PIN_NO(12) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_12_EINT12__FUNC_CLKM2
value|(MTK_PIN_NO(12) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_12_EINT12__FUNC_I2S3_BCK
value|(MTK_PIN_NO(12) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_12_EINT12__FUNC_SRCLKENA0
value|(MTK_PIN_NO(12) | 3)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_12_EINT12__FUNC_I2S2_WS
value|(MTK_PIN_NO(12) | 5)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_12_EINT12__FUNC_DBG_MON_B_32_
value|(MTK_PIN_NO(12) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_13_EINT13__FUNC_GPIO13
value|(MTK_PIN_NO(13) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_13_EINT13__FUNC_CLKM3
value|(MTK_PIN_NO(13) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_13_EINT13__FUNC_I2S3_MCK
value|(MTK_PIN_NO(13) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_13_EINT13__FUNC_SRCLKENA0
value|(MTK_PIN_NO(13) | 3)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_13_EINT13__FUNC_I2S2_BCK
value|(MTK_PIN_NO(13) | 5)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_13_EINT13__FUNC_DBG_MON_A_32_
value|(MTK_PIN_NO(13) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_14_EINT14__FUNC_GPIO14
value|(MTK_PIN_NO(14) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_14_EINT14__FUNC_CMDAT0
value|(MTK_PIN_NO(14) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_14_EINT14__FUNC_CMCSD0
value|(MTK_PIN_NO(14) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_14_EINT14__FUNC_CLKM2
value|(MTK_PIN_NO(14) | 4)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_14_EINT14__FUNC_DBG_MON_B_6_
value|(MTK_PIN_NO(14) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_15_EINT15__FUNC_GPIO15
value|(MTK_PIN_NO(15) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_15_EINT15__FUNC_CMDAT1
value|(MTK_PIN_NO(15) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_15_EINT15__FUNC_CMCSD1
value|(MTK_PIN_NO(15) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_15_EINT15__FUNC_CMFLASH
value|(MTK_PIN_NO(15) | 3)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_15_EINT15__FUNC_CLKM3
value|(MTK_PIN_NO(15) | 4)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_15_EINT15__FUNC_DBG_MON_B_29_
value|(MTK_PIN_NO(15) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_16_IDDIG__FUNC_GPIO16
value|(MTK_PIN_NO(16) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_16_IDDIG__FUNC_IDDIG
value|(MTK_PIN_NO(16) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_16_IDDIG__FUNC_CMFLASH
value|(MTK_PIN_NO(16) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_16_IDDIG__FUNC_PWM5
value|(MTK_PIN_NO(16) | 4)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_17_WATCHDOG__FUNC_GPIO17
value|(MTK_PIN_NO(17) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_17_WATCHDOG__FUNC_WATCHDOG_AO
value|(MTK_PIN_NO(17) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_18_CEC__FUNC_GPIO18
value|(MTK_PIN_NO(18) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_18_CEC__FUNC_CEC
value|(MTK_PIN_NO(18) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_19_HDMISCK__FUNC_GPIO19
value|(MTK_PIN_NO(19) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_19_HDMISCK__FUNC_HDMISCK
value|(MTK_PIN_NO(19) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_19_HDMISCK__FUNC_HDCP_SCL
value|(MTK_PIN_NO(19) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_20_HDMISD__FUNC_GPIO20
value|(MTK_PIN_NO(20) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_20_HDMISD__FUNC_HDMISD
value|(MTK_PIN_NO(20) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_20_HDMISD__FUNC_HDCP_SDA
value|(MTK_PIN_NO(20) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_21_HTPLG__FUNC_GPIO21
value|(MTK_PIN_NO(21) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_21_HTPLG__FUNC_HTPLG
value|(MTK_PIN_NO(21) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_22_MSDC3_DAT0__FUNC_GPIO22
value|(MTK_PIN_NO(22) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_22_MSDC3_DAT0__FUNC_MSDC3_DAT0
value|(MTK_PIN_NO(22) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_23_MSDC3_DAT1__FUNC_GPIO23
value|(MTK_PIN_NO(23) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_23_MSDC3_DAT1__FUNC_MSDC3_DAT1
value|(MTK_PIN_NO(23) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_24_MSDC3_DAT2__FUNC_GPIO24
value|(MTK_PIN_NO(24) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_24_MSDC3_DAT2__FUNC_MSDC3_DAT2
value|(MTK_PIN_NO(24) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_25_MSDC3_DAT3__FUNC_GPIO25
value|(MTK_PIN_NO(25) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_25_MSDC3_DAT3__FUNC_MSDC3_DAT3
value|(MTK_PIN_NO(25) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_26_MSDC3_CLK__FUNC_GPIO26
value|(MTK_PIN_NO(26) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_26_MSDC3_CLK__FUNC_MSDC3_CLK
value|(MTK_PIN_NO(26) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_27_MSDC3_CMD__FUNC_GPIO27
value|(MTK_PIN_NO(27) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_27_MSDC3_CMD__FUNC_MSDC3_CMD
value|(MTK_PIN_NO(27) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_28_MSDC3_DSL__FUNC_GPIO28
value|(MTK_PIN_NO(28) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_28_MSDC3_DSL__FUNC_MSDC3_DSL
value|(MTK_PIN_NO(28) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_29_UCTS2__FUNC_GPIO29
value|(MTK_PIN_NO(29) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_29_UCTS2__FUNC_UCTS2
value|(MTK_PIN_NO(29) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_30_URTS2__FUNC_GPIO30
value|(MTK_PIN_NO(30) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_30_URTS2__FUNC_URTS2
value|(MTK_PIN_NO(30) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_31_URXD2__FUNC_GPIO31
value|(MTK_PIN_NO(31) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_31_URXD2__FUNC_URXD2
value|(MTK_PIN_NO(31) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_31_URXD2__FUNC_UTXD2
value|(MTK_PIN_NO(31) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_32_UTXD2__FUNC_GPIO32
value|(MTK_PIN_NO(32) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_32_UTXD2__FUNC_UTXD2
value|(MTK_PIN_NO(32) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_32_UTXD2__FUNC_URXD2
value|(MTK_PIN_NO(32) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_33_DAICLK__FUNC_GPIO33
value|(MTK_PIN_NO(33) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_33_DAICLK__FUNC_MRG_CLK
value|(MTK_PIN_NO(33) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_33_DAICLK__FUNC_PCM0_CLK
value|(MTK_PIN_NO(33) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_34_DAIPCMIN__FUNC_GPIO34
value|(MTK_PIN_NO(34) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_34_DAIPCMIN__FUNC_MRG_DI
value|(MTK_PIN_NO(34) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_34_DAIPCMIN__FUNC_PCM0_DI
value|(MTK_PIN_NO(34) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_35_DAIPCMOUT__FUNC_GPIO35
value|(MTK_PIN_NO(35) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_35_DAIPCMOUT__FUNC_MRG_DO
value|(MTK_PIN_NO(35) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_35_DAIPCMOUT__FUNC_PCM0_DO
value|(MTK_PIN_NO(35) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_36_DAISYNC__FUNC_GPIO36
value|(MTK_PIN_NO(36) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_36_DAISYNC__FUNC_MRG_SYNC
value|(MTK_PIN_NO(36) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_36_DAISYNC__FUNC_PCM0_SYNC
value|(MTK_PIN_NO(36) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_37_EINT16__FUNC_GPIO37
value|(MTK_PIN_NO(37) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_37_EINT16__FUNC_USB_DRVVBUS_P0
value|(MTK_PIN_NO(37) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_37_EINT16__FUNC_USB_DRVVBUS_P1
value|(MTK_PIN_NO(37) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_37_EINT16__FUNC_PWM0
value|(MTK_PIN_NO(37) | 3)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_37_EINT16__FUNC_PWM1
value|(MTK_PIN_NO(37) | 4)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_37_EINT16__FUNC_PWM2
value|(MTK_PIN_NO(37) | 5)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_37_EINT16__FUNC_CLKM0
value|(MTK_PIN_NO(37) | 6)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_38_CONN_RST__FUNC_GPIO38
value|(MTK_PIN_NO(38) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_38_CONN_RST__FUNC_USB_DRVVBUS_P0
value|(MTK_PIN_NO(38) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_38_CONN_RST__FUNC_USB_DRVVBUS_P1
value|(MTK_PIN_NO(38) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_38_CONN_RST__FUNC_CLKM1
value|(MTK_PIN_NO(38) | 6)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_39_CM2MCLK__FUNC_GPIO39
value|(MTK_PIN_NO(39) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_39_CM2MCLK__FUNC_CM2MCLK
value|(MTK_PIN_NO(39) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_39_CM2MCLK__FUNC_CMCSD0
value|(MTK_PIN_NO(39) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_39_CM2MCLK__FUNC_DBG_MON_A_17_
value|(MTK_PIN_NO(39) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_40_CMPCLK__FUNC_GPIO40
value|(MTK_PIN_NO(40) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_40_CMPCLK__FUNC_CMPCLK
value|(MTK_PIN_NO(40) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_40_CMPCLK__FUNC_CMCSK
value|(MTK_PIN_NO(40) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_40_CMPCLK__FUNC_CMCSD2
value|(MTK_PIN_NO(40) | 3)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_40_CMPCLK__FUNC_DBG_MON_A_18_
value|(MTK_PIN_NO(40) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_41_CMMCLK__FUNC_GPIO41
value|(MTK_PIN_NO(41) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_41_CMMCLK__FUNC_CMMCLK
value|(MTK_PIN_NO(41) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_41_CMMCLK__FUNC_DBG_MON_A_19_
value|(MTK_PIN_NO(41) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_42_DSI_TE__FUNC_GPIO42
value|(MTK_PIN_NO(42) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_42_DSI_TE__FUNC_DSI_TE
value|(MTK_PIN_NO(42) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_43_SDA2__FUNC_GPIO43
value|(MTK_PIN_NO(43) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_43_SDA2__FUNC_SDA2
value|(MTK_PIN_NO(43) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_44_SCL2__FUNC_GPIO44
value|(MTK_PIN_NO(44) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_44_SCL2__FUNC_SCL2
value|(MTK_PIN_NO(44) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_45_SDA0__FUNC_GPIO45
value|(MTK_PIN_NO(45) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_45_SDA0__FUNC_SDA0
value|(MTK_PIN_NO(45) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_46_SCL0__FUNC_GPIO46
value|(MTK_PIN_NO(46) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_46_SCL0__FUNC_SCL0
value|(MTK_PIN_NO(46) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_47_RDN0_A__FUNC_GPIO47
value|(MTK_PIN_NO(47) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_47_RDN0_A__FUNC_CMDAT2
value|(MTK_PIN_NO(47) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_48_RDP0_A__FUNC_GPIO48
value|(MTK_PIN_NO(48) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_48_RDP0_A__FUNC_CMDAT3
value|(MTK_PIN_NO(48) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_49_RDN1_A__FUNC_GPIO49
value|(MTK_PIN_NO(49) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_49_RDN1_A__FUNC_CMDAT4
value|(MTK_PIN_NO(49) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_50_RDP1_A__FUNC_GPIO50
value|(MTK_PIN_NO(50) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_50_RDP1_A__FUNC_CMDAT5
value|(MTK_PIN_NO(50) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_51_RCN_A__FUNC_GPIO51
value|(MTK_PIN_NO(51) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_51_RCN_A__FUNC_CMDAT6
value|(MTK_PIN_NO(51) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_52_RCP_A__FUNC_GPIO52
value|(MTK_PIN_NO(52) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_52_RCP_A__FUNC_CMDAT7
value|(MTK_PIN_NO(52) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_53_RDN2_A__FUNC_GPIO53
value|(MTK_PIN_NO(53) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_53_RDN2_A__FUNC_CMDAT8
value|(MTK_PIN_NO(53) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_53_RDN2_A__FUNC_CMCSD3
value|(MTK_PIN_NO(53) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_54_RDP2_A__FUNC_GPIO54
value|(MTK_PIN_NO(54) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_54_RDP2_A__FUNC_CMDAT9
value|(MTK_PIN_NO(54) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_54_RDP2_A__FUNC_CMCSD2
value|(MTK_PIN_NO(54) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_55_RDN3_A__FUNC_GPIO55
value|(MTK_PIN_NO(55) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_55_RDN3_A__FUNC_CMHSYNC
value|(MTK_PIN_NO(55) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_55_RDN3_A__FUNC_CMCSD1
value|(MTK_PIN_NO(55) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_56_RDP3_A__FUNC_GPIO56
value|(MTK_PIN_NO(56) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_56_RDP3_A__FUNC_CMVSYNC
value|(MTK_PIN_NO(56) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_56_RDP3_A__FUNC_CMCSD0
value|(MTK_PIN_NO(56) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_57_MSDC0_DAT0__FUNC_GPIO57
value|(MTK_PIN_NO(57) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_57_MSDC0_DAT0__FUNC_MSDC0_DAT0
value|(MTK_PIN_NO(57) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_57_MSDC0_DAT0__FUNC_I2S1_WS
value|(MTK_PIN_NO(57) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_57_MSDC0_DAT0__FUNC_DBG_MON_B_7_
value|(MTK_PIN_NO(57) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_58_MSDC0_DAT1__FUNC_GPIO58
value|(MTK_PIN_NO(58) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_58_MSDC0_DAT1__FUNC_MSDC0_DAT1
value|(MTK_PIN_NO(58) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_58_MSDC0_DAT1__FUNC_I2S1_BCK
value|(MTK_PIN_NO(58) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_58_MSDC0_DAT1__FUNC_DBG_MON_B_8_
value|(MTK_PIN_NO(58) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_59_MSDC0_DAT2__FUNC_GPIO59
value|(MTK_PIN_NO(59) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_59_MSDC0_DAT2__FUNC_MSDC0_DAT2
value|(MTK_PIN_NO(59) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_59_MSDC0_DAT2__FUNC_I2S1_MCK
value|(MTK_PIN_NO(59) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_59_MSDC0_DAT2__FUNC_DBG_MON_B_9_
value|(MTK_PIN_NO(59) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_60_MSDC0_DAT3__FUNC_GPIO60
value|(MTK_PIN_NO(60) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_60_MSDC0_DAT3__FUNC_MSDC0_DAT3
value|(MTK_PIN_NO(60) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_60_MSDC0_DAT3__FUNC_I2S1_DO_1
value|(MTK_PIN_NO(60) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_60_MSDC0_DAT3__FUNC_DBG_MON_B_10_
value|(MTK_PIN_NO(60) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_61_MSDC0_DAT4__FUNC_GPIO61
value|(MTK_PIN_NO(61) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_61_MSDC0_DAT4__FUNC_MSDC0_DAT4
value|(MTK_PIN_NO(61) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_61_MSDC0_DAT4__FUNC_I2S1_DO_2
value|(MTK_PIN_NO(61) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_61_MSDC0_DAT4__FUNC_DBG_MON_B_11_
value|(MTK_PIN_NO(61) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_62_MSDC0_DAT5__FUNC_GPIO62
value|(MTK_PIN_NO(62) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_62_MSDC0_DAT5__FUNC_MSDC0_DAT5
value|(MTK_PIN_NO(62) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_62_MSDC0_DAT5__FUNC_I2S2_WS
value|(MTK_PIN_NO(62) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_62_MSDC0_DAT5__FUNC_DBG_MON_B_12_
value|(MTK_PIN_NO(62) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_63_MSDC0_DAT6__FUNC_GPIO63
value|(MTK_PIN_NO(63) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_63_MSDC0_DAT6__FUNC_MSDC0_DAT6
value|(MTK_PIN_NO(63) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_63_MSDC0_DAT6__FUNC_I2S2_BCK
value|(MTK_PIN_NO(63) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_63_MSDC0_DAT6__FUNC_DBG_MON_B_13_
value|(MTK_PIN_NO(63) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_64_MSDC0_DAT7__FUNC_GPIO64
value|(MTK_PIN_NO(64) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_64_MSDC0_DAT7__FUNC_MSDC0_DAT7
value|(MTK_PIN_NO(64) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_64_MSDC0_DAT7__FUNC_I2S2_DI_1
value|(MTK_PIN_NO(64) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_64_MSDC0_DAT7__FUNC_DBG_MON_B_14_
value|(MTK_PIN_NO(64) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_65_MSDC0_CLK__FUNC_GPIO65
value|(MTK_PIN_NO(65) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_65_MSDC0_CLK__FUNC_MSDC0_CLK
value|(MTK_PIN_NO(65) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_65_MSDC0_CLK__FUNC_DBG_MON_B_16_
value|(MTK_PIN_NO(65) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_66_MSDC0_CMD__FUNC_GPIO66
value|(MTK_PIN_NO(66) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_66_MSDC0_CMD__FUNC_MSDC0_CMD
value|(MTK_PIN_NO(66) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_66_MSDC0_CMD__FUNC_I2S2_DI_2
value|(MTK_PIN_NO(66) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_66_MSDC0_CMD__FUNC_DBG_MON_B_15_
value|(MTK_PIN_NO(66) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_67_MSDC0_DSL__FUNC_GPIO67
value|(MTK_PIN_NO(67) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_67_MSDC0_DSL__FUNC_MSDC0_DSL
value|(MTK_PIN_NO(67) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_67_MSDC0_DSL__FUNC_DBG_MON_B_17_
value|(MTK_PIN_NO(67) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_68_MSDC0_RST___FUNC_GPIO68
value|(MTK_PIN_NO(68) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_68_MSDC0_RST___FUNC_MSDC0_RSTB
value|(MTK_PIN_NO(68) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_68_MSDC0_RST___FUNC_I2S2_MCK
value|(MTK_PIN_NO(68) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_68_MSDC0_RST___FUNC_DBG_MON_B_18_
value|(MTK_PIN_NO(68) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_69_SPI_CK__FUNC_GPIO69
value|(MTK_PIN_NO(69) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_69_SPI_CK__FUNC_SPI_CK_0_
value|(MTK_PIN_NO(69) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_69_SPI_CK__FUNC_I2S3_DO_1
value|(MTK_PIN_NO(69) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_69_SPI_CK__FUNC_PWM0
value|(MTK_PIN_NO(69) | 3)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_69_SPI_CK__FUNC_PWM5
value|(MTK_PIN_NO(69) | 4)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_69_SPI_CK__FUNC_I2S2_MCK
value|(MTK_PIN_NO(69) | 5)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_69_SPI_CK__FUNC_DBG_MON_B_19_
value|(MTK_PIN_NO(69) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_70_SPI_MI__FUNC_GPIO70
value|(MTK_PIN_NO(70) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_70_SPI_MI__FUNC_SPI_MI_0_
value|(MTK_PIN_NO(70) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_70_SPI_MI__FUNC_I2S3_DO_2
value|(MTK_PIN_NO(70) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_70_SPI_MI__FUNC_PWM1
value|(MTK_PIN_NO(70) | 3)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_70_SPI_MI__FUNC_SPI_MO_0_
value|(MTK_PIN_NO(70) | 4)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_70_SPI_MI__FUNC_I2S2_DI_1
value|(MTK_PIN_NO(70) | 5)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_70_SPI_MI__FUNC_DSI1_TE
value|(MTK_PIN_NO(70) | 6)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_70_SPI_MI__FUNC_DBG_MON_B_20_
value|(MTK_PIN_NO(70) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_71_SPI_MO__FUNC_GPIO71
value|(MTK_PIN_NO(71) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_71_SPI_MO__FUNC_SPI_MO_0_
value|(MTK_PIN_NO(71) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_71_SPI_MO__FUNC_I2S3_DO_3
value|(MTK_PIN_NO(71) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_71_SPI_MO__FUNC_PWM2
value|(MTK_PIN_NO(71) | 3)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_71_SPI_MO__FUNC_SPI_MI_0_
value|(MTK_PIN_NO(71) | 4)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_71_SPI_MO__FUNC_I2S2_DI_2
value|(MTK_PIN_NO(71) | 5)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_71_SPI_MO__FUNC_DBG_MON_B_21_
value|(MTK_PIN_NO(71) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_72_SPI_CS__FUNC_GPIO72
value|(MTK_PIN_NO(72) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_72_SPI_CS__FUNC_SPI_CS_0_
value|(MTK_PIN_NO(72) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_72_SPI_CS__FUNC_I2S3_DO_4
value|(MTK_PIN_NO(72) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_72_SPI_CS__FUNC_PWM3
value|(MTK_PIN_NO(72) | 3)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_72_SPI_CS__FUNC_PWM6
value|(MTK_PIN_NO(72) | 4)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_72_SPI_CS__FUNC_DISP_PWM1
value|(MTK_PIN_NO(72) | 5)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_72_SPI_CS__FUNC_DBG_MON_B_22_
value|(MTK_PIN_NO(72) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_73_MSDC1_DAT0__FUNC_GPIO73
value|(MTK_PIN_NO(73) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_73_MSDC1_DAT0__FUNC_MSDC1_DAT0
value|(MTK_PIN_NO(73) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_73_MSDC1_DAT0__FUNC_DBG_MON_B_24_
value|(MTK_PIN_NO(73) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_74_MSDC1_DAT1__FUNC_GPIO74
value|(MTK_PIN_NO(74) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_74_MSDC1_DAT1__FUNC_MSDC1_DAT1
value|(MTK_PIN_NO(74) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_74_MSDC1_DAT1__FUNC_DBG_MON_B_25_
value|(MTK_PIN_NO(74) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_75_MSDC1_DAT2__FUNC_GPIO75
value|(MTK_PIN_NO(75) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_75_MSDC1_DAT2__FUNC_MSDC1_DAT2
value|(MTK_PIN_NO(75) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_75_MSDC1_DAT2__FUNC_DBG_MON_B_26_
value|(MTK_PIN_NO(75) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_76_MSDC1_DAT3__FUNC_GPIO76
value|(MTK_PIN_NO(76) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_76_MSDC1_DAT3__FUNC_MSDC1_DAT3
value|(MTK_PIN_NO(76) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_76_MSDC1_DAT3__FUNC_DBG_MON_B_27_
value|(MTK_PIN_NO(76) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_77_MSDC1_CLK__FUNC_GPIO77
value|(MTK_PIN_NO(77) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_77_MSDC1_CLK__FUNC_MSDC1_CLK
value|(MTK_PIN_NO(77) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_77_MSDC1_CLK__FUNC_DBG_MON_B_28_
value|(MTK_PIN_NO(77) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_78_MSDC1_CMD__FUNC_GPIO78
value|(MTK_PIN_NO(78) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_78_MSDC1_CMD__FUNC_MSDC1_CMD
value|(MTK_PIN_NO(78) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_78_MSDC1_CMD__FUNC_DBG_MON_B_23_
value|(MTK_PIN_NO(78) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_79_PWRAP_SPI0_MI__FUNC_GPIO79
value|(MTK_PIN_NO(79) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_79_PWRAP_SPI0_MI__FUNC_PWRAP_SPIMI
value|(MTK_PIN_NO(79) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_79_PWRAP_SPI0_MI__FUNC_PWRAP_SPIMO
value|(MTK_PIN_NO(79) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_80_PWRAP_SPI0_MO__FUNC_GPIO80
value|(MTK_PIN_NO(80) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_80_PWRAP_SPI0_MO__FUNC_PWRAP_SPIMO
value|(MTK_PIN_NO(80) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_80_PWRAP_SPI0_MO__FUNC_PWRAP_SPIMI
value|(MTK_PIN_NO(80) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_81_PWRAP_SPI0_CK__FUNC_GPIO81
value|(MTK_PIN_NO(81) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_81_PWRAP_SPI0_CK__FUNC_PWRAP_SPICK
value|(MTK_PIN_NO(81) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_82_PWRAP_SPI0_CSN__FUNC_GPIO82
value|(MTK_PIN_NO(82) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_82_PWRAP_SPI0_CSN__FUNC_PWRAP_SPICS
value|(MTK_PIN_NO(82) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_83_AUD_CLK_MOSI__FUNC_GPIO83
value|(MTK_PIN_NO(83) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_83_AUD_CLK_MOSI__FUNC_AUD_CLK_MOSI
value|(MTK_PIN_NO(83) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_84_AUD_DAT_MISO__FUNC_GPIO84
value|(MTK_PIN_NO(84) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_84_AUD_DAT_MISO__FUNC_AUD_DAT_MISO
value|(MTK_PIN_NO(84) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_84_AUD_DAT_MISO__FUNC_AUD_DAT_MOSI
value|(MTK_PIN_NO(84) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_85_AUD_DAT_MOSI__FUNC_GPIO85
value|(MTK_PIN_NO(85) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_85_AUD_DAT_MOSI__FUNC_AUD_DAT_MOSI
value|(MTK_PIN_NO(85) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_85_AUD_DAT_MOSI__FUNC_AUD_DAT_MISO
value|(MTK_PIN_NO(85) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_86_RTC32K_CK__FUNC_GPIO86
value|(MTK_PIN_NO(86) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_86_RTC32K_CK__FUNC_RTC32K_CK
value|(MTK_PIN_NO(86) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_87_DISP_PWM0__FUNC_GPIO87
value|(MTK_PIN_NO(87) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_87_DISP_PWM0__FUNC_DISP_PWM0
value|(MTK_PIN_NO(87) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_87_DISP_PWM0__FUNC_DISP_PWM1
value|(MTK_PIN_NO(87) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_87_DISP_PWM0__FUNC_DBG_MON_B_31_
value|(MTK_PIN_NO(87) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_88_SRCLKENAI__FUNC_GPIO88
value|(MTK_PIN_NO(88) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_88_SRCLKENAI__FUNC_SRCLKENAI
value|(MTK_PIN_NO(88) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_89_SRCLKENAI2__FUNC_GPIO89
value|(MTK_PIN_NO(89) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_89_SRCLKENAI2__FUNC_SRCLKENAI2
value|(MTK_PIN_NO(89) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_90_SRCLKENA0__FUNC_GPIO90
value|(MTK_PIN_NO(90) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_90_SRCLKENA0__FUNC_SRCLKENA0
value|(MTK_PIN_NO(90) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_91_SRCLKENA1__FUNC_GPIO91
value|(MTK_PIN_NO(91) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_91_SRCLKENA1__FUNC_SRCLKENA1
value|(MTK_PIN_NO(91) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_92_PCM_CLK__FUNC_GPIO92
value|(MTK_PIN_NO(92) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_92_PCM_CLK__FUNC_PCM1_CLK
value|(MTK_PIN_NO(92) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_92_PCM_CLK__FUNC_I2S0_BCK
value|(MTK_PIN_NO(92) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_92_PCM_CLK__FUNC_DBG_MON_A_24_
value|(MTK_PIN_NO(92) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_93_PCM_SYNC__FUNC_GPIO93
value|(MTK_PIN_NO(93) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_93_PCM_SYNC__FUNC_PCM1_SYNC
value|(MTK_PIN_NO(93) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_93_PCM_SYNC__FUNC_I2S0_WS
value|(MTK_PIN_NO(93) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_93_PCM_SYNC__FUNC_DBG_MON_A_25_
value|(MTK_PIN_NO(93) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_94_PCM_RX__FUNC_GPIO94
value|(MTK_PIN_NO(94) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_94_PCM_RX__FUNC_PCM1_DI
value|(MTK_PIN_NO(94) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_94_PCM_RX__FUNC_I2S0_DI
value|(MTK_PIN_NO(94) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_94_PCM_RX__FUNC_DBG_MON_A_26_
value|(MTK_PIN_NO(94) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_95_PCM_TX__FUNC_GPIO95
value|(MTK_PIN_NO(95) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_95_PCM_TX__FUNC_PCM1_DO
value|(MTK_PIN_NO(95) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_95_PCM_TX__FUNC_I2S0_DO
value|(MTK_PIN_NO(95) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_95_PCM_TX__FUNC_DBG_MON_A_27_
value|(MTK_PIN_NO(95) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_96_URXD1__FUNC_GPIO96
value|(MTK_PIN_NO(96) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_96_URXD1__FUNC_URXD1
value|(MTK_PIN_NO(96) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_96_URXD1__FUNC_UTXD1
value|(MTK_PIN_NO(96) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_96_URXD1__FUNC_DBG_MON_A_28_
value|(MTK_PIN_NO(96) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_97_UTXD1__FUNC_GPIO97
value|(MTK_PIN_NO(97) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_97_UTXD1__FUNC_UTXD1
value|(MTK_PIN_NO(97) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_97_UTXD1__FUNC_URXD1
value|(MTK_PIN_NO(97) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_97_UTXD1__FUNC_DBG_MON_A_29_
value|(MTK_PIN_NO(97) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_98_URTS1__FUNC_GPIO98
value|(MTK_PIN_NO(98) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_98_URTS1__FUNC_URTS1
value|(MTK_PIN_NO(98) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_98_URTS1__FUNC_UCTS1
value|(MTK_PIN_NO(98) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_98_URTS1__FUNC_DBG_MON_A_30_
value|(MTK_PIN_NO(98) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_99_UCTS1__FUNC_GPIO99
value|(MTK_PIN_NO(99) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_99_UCTS1__FUNC_UCTS1
value|(MTK_PIN_NO(99) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_99_UCTS1__FUNC_URTS1
value|(MTK_PIN_NO(99) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_99_UCTS1__FUNC_DBG_MON_A_31_
value|(MTK_PIN_NO(99) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_100_MSDC2_DAT0__FUNC_GPIO100
value|(MTK_PIN_NO(100) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_100_MSDC2_DAT0__FUNC_MSDC2_DAT0
value|(MTK_PIN_NO(100) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_100_MSDC2_DAT0__FUNC_USB_DRVVBUS_P0
value|(MTK_PIN_NO(100) | 3)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_100_MSDC2_DAT0__FUNC_SDA5
value|(MTK_PIN_NO(100) | 4)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_100_MSDC2_DAT0__FUNC_USB_DRVVBUS_P1
value|(MTK_PIN_NO(100) | 5)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_100_MSDC2_DAT0__FUNC_DBG_MON_B_0_
value|(MTK_PIN_NO(100) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_101_MSDC2_DAT1__FUNC_GPIO101
value|(MTK_PIN_NO(101) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_101_MSDC2_DAT1__FUNC_MSDC2_DAT1
value|(MTK_PIN_NO(101) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_101_MSDC2_DAT1__FUNC_AUD_SPDIF
value|(MTK_PIN_NO(101) | 3)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_101_MSDC2_DAT1__FUNC_SCL5
value|(MTK_PIN_NO(101) | 4)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_101_MSDC2_DAT1__FUNC_DBG_MON_B_1_
value|(MTK_PIN_NO(101) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_102_MSDC2_DAT2__FUNC_GPIO102
value|(MTK_PIN_NO(102) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_102_MSDC2_DAT2__FUNC_MSDC2_DAT2
value|(MTK_PIN_NO(102) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_102_MSDC2_DAT2__FUNC_UTXD0
value|(MTK_PIN_NO(102) | 3)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_102_MSDC2_DAT2__FUNC_PWM0
value|(MTK_PIN_NO(102) | 5)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_102_MSDC2_DAT2__FUNC_SPI_CK_1_
value|(MTK_PIN_NO(102) | 6)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_102_MSDC2_DAT2__FUNC_DBG_MON_B_2_
value|(MTK_PIN_NO(102) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_103_MSDC2_DAT3__FUNC_GPIO103
value|(MTK_PIN_NO(103) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_103_MSDC2_DAT3__FUNC_MSDC2_DAT3
value|(MTK_PIN_NO(103) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_103_MSDC2_DAT3__FUNC_URXD0
value|(MTK_PIN_NO(103) | 3)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_103_MSDC2_DAT3__FUNC_PWM1
value|(MTK_PIN_NO(103) | 5)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_103_MSDC2_DAT3__FUNC_SPI_MI_1_
value|(MTK_PIN_NO(103) | 6)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_103_MSDC2_DAT3__FUNC_DBG_MON_B_3_
value|(MTK_PIN_NO(103) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_104_MSDC2_CLK__FUNC_GPIO104
value|(MTK_PIN_NO(104) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_104_MSDC2_CLK__FUNC_MSDC2_CLK
value|(MTK_PIN_NO(104) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_104_MSDC2_CLK__FUNC_UTXD3
value|(MTK_PIN_NO(104) | 3)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_104_MSDC2_CLK__FUNC_SDA3
value|(MTK_PIN_NO(104) | 4)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_104_MSDC2_CLK__FUNC_PWM2
value|(MTK_PIN_NO(104) | 5)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_104_MSDC2_CLK__FUNC_SPI_MO_1_
value|(MTK_PIN_NO(104) | 6)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_104_MSDC2_CLK__FUNC_DBG_MON_B_4_
value|(MTK_PIN_NO(104) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_105_MSDC2_CMD__FUNC_GPIO105
value|(MTK_PIN_NO(105) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_105_MSDC2_CMD__FUNC_MSDC2_CMD
value|(MTK_PIN_NO(105) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_105_MSDC2_CMD__FUNC_URXD3
value|(MTK_PIN_NO(105) | 3)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_105_MSDC2_CMD__FUNC_SCL3
value|(MTK_PIN_NO(105) | 4)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_105_MSDC2_CMD__FUNC_PWM3
value|(MTK_PIN_NO(105) | 5)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_105_MSDC2_CMD__FUNC_SPI_CS_1_
value|(MTK_PIN_NO(105) | 6)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_105_MSDC2_CMD__FUNC_DBG_MON_B_5_
value|(MTK_PIN_NO(105) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_106_SDA3__FUNC_GPIO106
value|(MTK_PIN_NO(106) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_106_SDA3__FUNC_SDA3
value|(MTK_PIN_NO(106) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_107_SCL3__FUNC_GPIO107
value|(MTK_PIN_NO(107) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_107_SCL3__FUNC_SCL3
value|(MTK_PIN_NO(107) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_108_JTMS__FUNC_GPIO108
value|(MTK_PIN_NO(108) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_108_JTMS__FUNC_JTMS
value|(MTK_PIN_NO(108) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_108_JTMS__FUNC_MFG_JTAG_TMS
value|(MTK_PIN_NO(108) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_108_JTMS__FUNC_AP_MD32_JTAG_TMS
value|(MTK_PIN_NO(108) | 5)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_108_JTMS__FUNC_DFD_TMS
value|(MTK_PIN_NO(108) | 6)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_109_JTCK__FUNC_GPIO109
value|(MTK_PIN_NO(109) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_109_JTCK__FUNC_JTCK
value|(MTK_PIN_NO(109) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_109_JTCK__FUNC_MFG_JTAG_TCK
value|(MTK_PIN_NO(109) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_109_JTCK__FUNC_AP_MD32_JTAG_TCK
value|(MTK_PIN_NO(109) | 5)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_109_JTCK__FUNC_DFD_TCK
value|(MTK_PIN_NO(109) | 6)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_110_JTDI__FUNC_GPIO110
value|(MTK_PIN_NO(110) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_110_JTDI__FUNC_JTDI
value|(MTK_PIN_NO(110) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_110_JTDI__FUNC_MFG_JTAG_TDI
value|(MTK_PIN_NO(110) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_110_JTDI__FUNC_AP_MD32_JTAG_TDI
value|(MTK_PIN_NO(110) | 5)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_110_JTDI__FUNC_DFD_TDI
value|(MTK_PIN_NO(110) | 6)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_111_JTDO__FUNC_GPIO111
value|(MTK_PIN_NO(111) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_111_JTDO__FUNC_JTDO
value|(MTK_PIN_NO(111) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_111_JTDO__FUNC_MFG_JTAG_TDO
value|(MTK_PIN_NO(111) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_111_JTDO__FUNC_AP_MD32_JTAG_TDO
value|(MTK_PIN_NO(111) | 5)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_111_JTDO__FUNC_DFD_TDO
value|(MTK_PIN_NO(111) | 6)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_112_JTRST_B__FUNC_GPIO112
value|(MTK_PIN_NO(112) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_112_JTRST_B__FUNC_JTRST_B
value|(MTK_PIN_NO(112) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_112_JTRST_B__FUNC_MFG_JTAG_TRSTN
value|(MTK_PIN_NO(112) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_112_JTRST_B__FUNC_AP_MD32_JTAG_TRST
value|(MTK_PIN_NO(112) | 5)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_112_JTRST_B__FUNC_DFD_NTRST
value|(MTK_PIN_NO(112) | 6)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_113_URXD0__FUNC_GPIO113
value|(MTK_PIN_NO(113) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_113_URXD0__FUNC_URXD0
value|(MTK_PIN_NO(113) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_113_URXD0__FUNC_UTXD0
value|(MTK_PIN_NO(113) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_113_URXD0__FUNC_I2S2_WS
value|(MTK_PIN_NO(113) | 6)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_113_URXD0__FUNC_DBG_MON_A_0_
value|(MTK_PIN_NO(113) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_114_UTXD0__FUNC_GPIO114
value|(MTK_PIN_NO(114) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_114_UTXD0__FUNC_UTXD0
value|(MTK_PIN_NO(114) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_114_UTXD0__FUNC_URXD0
value|(MTK_PIN_NO(114) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_114_UTXD0__FUNC_I2S2_BCK
value|(MTK_PIN_NO(114) | 6)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_114_UTXD0__FUNC_DBG_MON_A_1_
value|(MTK_PIN_NO(114) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_115_URTS0__FUNC_GPIO115
value|(MTK_PIN_NO(115) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_115_URTS0__FUNC_URTS0
value|(MTK_PIN_NO(115) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_115_URTS0__FUNC_UCTS0
value|(MTK_PIN_NO(115) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_115_URTS0__FUNC_I2S2_MCK
value|(MTK_PIN_NO(115) | 6)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_115_URTS0__FUNC_DBG_MON_A_2_
value|(MTK_PIN_NO(115) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_116_UCTS0__FUNC_GPIO116
value|(MTK_PIN_NO(116) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_116_UCTS0__FUNC_UCTS0
value|(MTK_PIN_NO(116) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_116_UCTS0__FUNC_URTS0
value|(MTK_PIN_NO(116) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_116_UCTS0__FUNC_I2S2_DI_1
value|(MTK_PIN_NO(116) | 6)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_116_UCTS0__FUNC_DBG_MON_A_3_
value|(MTK_PIN_NO(116) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_117_URXD3__FUNC_GPIO117
value|(MTK_PIN_NO(117) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_117_URXD3__FUNC_URXD3
value|(MTK_PIN_NO(117) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_117_URXD3__FUNC_UTXD3
value|(MTK_PIN_NO(117) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_117_URXD3__FUNC_DBG_MON_A_9_
value|(MTK_PIN_NO(117) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_118_UTXD3__FUNC_GPIO118
value|(MTK_PIN_NO(118) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_118_UTXD3__FUNC_UTXD3
value|(MTK_PIN_NO(118) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_118_UTXD3__FUNC_URXD3
value|(MTK_PIN_NO(118) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_118_UTXD3__FUNC_DBG_MON_A_10_
value|(MTK_PIN_NO(118) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_119_KPROW0__FUNC_GPIO119
value|(MTK_PIN_NO(119) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_119_KPROW0__FUNC_KROW0
value|(MTK_PIN_NO(119) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_119_KPROW0__FUNC_DBG_MON_A_11_
value|(MTK_PIN_NO(119) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_120_KPROW1__FUNC_GPIO120
value|(MTK_PIN_NO(120) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_120_KPROW1__FUNC_KROW1
value|(MTK_PIN_NO(120) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_120_KPROW1__FUNC_PWM6
value|(MTK_PIN_NO(120) | 3)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_120_KPROW1__FUNC_DBG_MON_A_12_
value|(MTK_PIN_NO(120) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_121_KPROW2__FUNC_GPIO121
value|(MTK_PIN_NO(121) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_121_KPROW2__FUNC_KROW2
value|(MTK_PIN_NO(121) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_121_KPROW2__FUNC_IRDA_PDN
value|(MTK_PIN_NO(121) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_121_KPROW2__FUNC_USB_DRVVBUS_P0
value|(MTK_PIN_NO(121) | 3)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_121_KPROW2__FUNC_PWM4
value|(MTK_PIN_NO(121) | 4)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_121_KPROW2__FUNC_USB_DRVVBUS_P1
value|(MTK_PIN_NO(121) | 5)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_121_KPROW2__FUNC_DBG_MON_A_13_
value|(MTK_PIN_NO(121) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_122_KPCOL0__FUNC_GPIO122
value|(MTK_PIN_NO(122) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_122_KPCOL0__FUNC_KCOL0
value|(MTK_PIN_NO(122) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_122_KPCOL0__FUNC_DBG_MON_A_14_
value|(MTK_PIN_NO(122) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_123_KPCOL1__FUNC_GPIO123
value|(MTK_PIN_NO(123) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_123_KPCOL1__FUNC_KCOL1
value|(MTK_PIN_NO(123) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_123_KPCOL1__FUNC_IRDA_RXD
value|(MTK_PIN_NO(123) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_123_KPCOL1__FUNC_PWM5
value|(MTK_PIN_NO(123) | 3)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_123_KPCOL1__FUNC_DBG_MON_A_15_
value|(MTK_PIN_NO(123) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_124_KPCOL2__FUNC_GPIO124
value|(MTK_PIN_NO(124) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_124_KPCOL2__FUNC_KCOL2
value|(MTK_PIN_NO(124) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_124_KPCOL2__FUNC_IRDA_TXD
value|(MTK_PIN_NO(124) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_124_KPCOL2__FUNC_USB_DRVVBUS_P0
value|(MTK_PIN_NO(124) | 3)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_124_KPCOL2__FUNC_PWM3
value|(MTK_PIN_NO(124) | 4)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_124_KPCOL2__FUNC_USB_DRVVBUS_P1
value|(MTK_PIN_NO(124) | 5)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_124_KPCOL2__FUNC_DBG_MON_A_16_
value|(MTK_PIN_NO(124) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_125_SDA1__FUNC_GPIO125
value|(MTK_PIN_NO(125) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_125_SDA1__FUNC_SDA1
value|(MTK_PIN_NO(125) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_126_SCL1__FUNC_GPIO126
value|(MTK_PIN_NO(126) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_126_SCL1__FUNC_SCL1
value|(MTK_PIN_NO(126) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_127_LCM_RST__FUNC_GPIO127
value|(MTK_PIN_NO(127) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_127_LCM_RST__FUNC_LCM_RST
value|(MTK_PIN_NO(127) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_128_I2S0_LRCK__FUNC_GPIO128
value|(MTK_PIN_NO(128) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_128_I2S0_LRCK__FUNC_I2S0_WS
value|(MTK_PIN_NO(128) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_128_I2S0_LRCK__FUNC_I2S1_WS
value|(MTK_PIN_NO(128) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_128_I2S0_LRCK__FUNC_I2S2_WS
value|(MTK_PIN_NO(128) | 3)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_128_I2S0_LRCK__FUNC_SPI_CK_2_
value|(MTK_PIN_NO(128) | 5)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_128_I2S0_LRCK__FUNC_DBG_MON_A_4_
value|(MTK_PIN_NO(128) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_129_I2S0_BCK__FUNC_GPIO129
value|(MTK_PIN_NO(129) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_129_I2S0_BCK__FUNC_I2S0_BCK
value|(MTK_PIN_NO(129) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_129_I2S0_BCK__FUNC_I2S1_BCK
value|(MTK_PIN_NO(129) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_129_I2S0_BCK__FUNC_I2S2_BCK
value|(MTK_PIN_NO(129) | 3)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_129_I2S0_BCK__FUNC_SPI_MI_2_
value|(MTK_PIN_NO(129) | 5)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_129_I2S0_BCK__FUNC_DBG_MON_A_5_
value|(MTK_PIN_NO(129) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_130_I2S0_MCK__FUNC_GPIO130
value|(MTK_PIN_NO(130) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_130_I2S0_MCK__FUNC_I2S0_MCK
value|(MTK_PIN_NO(130) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_130_I2S0_MCK__FUNC_I2S1_MCK
value|(MTK_PIN_NO(130) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_130_I2S0_MCK__FUNC_I2S2_MCK
value|(MTK_PIN_NO(130) | 3)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_130_I2S0_MCK__FUNC_SPI_MO_2_
value|(MTK_PIN_NO(130) | 5)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_130_I2S0_MCK__FUNC_DBG_MON_A_6_
value|(MTK_PIN_NO(130) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_131_I2S0_DATA0__FUNC_GPIO131
value|(MTK_PIN_NO(131) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_131_I2S0_DATA0__FUNC_I2S0_DO
value|(MTK_PIN_NO(131) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_131_I2S0_DATA0__FUNC_I2S1_DO_1
value|(MTK_PIN_NO(131) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_131_I2S0_DATA0__FUNC_I2S2_DI_1
value|(MTK_PIN_NO(131) | 3)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_131_I2S0_DATA0__FUNC_SPI_CS_2_
value|(MTK_PIN_NO(131) | 5)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_131_I2S0_DATA0__FUNC_DBG_MON_A_7_
value|(MTK_PIN_NO(131) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_132_I2S0_DATA1__FUNC_GPIO132
value|(MTK_PIN_NO(132) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_132_I2S0_DATA1__FUNC_I2S0_DI
value|(MTK_PIN_NO(132) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_132_I2S0_DATA1__FUNC_I2S1_DO_2
value|(MTK_PIN_NO(132) | 2)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_132_I2S0_DATA1__FUNC_I2S2_DI_2
value|(MTK_PIN_NO(132) | 3)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_132_I2S0_DATA1__FUNC_DBG_MON_A_8_
value|(MTK_PIN_NO(132) | 7)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_133_SDA4__FUNC_GPIO133
value|(MTK_PIN_NO(133) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_133_SDA4__FUNC_SDA4
value|(MTK_PIN_NO(133) | 1)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_134_SCL4__FUNC_GPIO134
value|(MTK_PIN_NO(134) | 0)
end_define

begin_define
define|#
directive|define
name|MT8173_PIN_134_SCL4__FUNC_SCL4
value|(MTK_PIN_NO(134) | 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DTS_MT8173_PINFUNC_H */
end_comment

end_unit

