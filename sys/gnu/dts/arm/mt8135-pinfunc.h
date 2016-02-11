begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2014 MediaTek Inc.  * Author: Hongzhou.Yang<hongzhou.yang@mediatek.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DTS_MT8135_PINFUNC_H
end_ifndef

begin_define
define|#
directive|define
name|__DTS_MT8135_PINFUNC_H
end_define

begin_include
include|#
directive|include
file|<dt-bindings/pinctrl/mt65xx.h>
end_include

begin_define
define|#
directive|define
name|MT8135_PIN_0_MSDC0_DAT7__FUNC_GPIO0
value|(MTK_PIN_NO(0) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_0_MSDC0_DAT7__FUNC_MSDC0_DAT7
value|(MTK_PIN_NO(0) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_0_MSDC0_DAT7__FUNC_EINT49
value|(MTK_PIN_NO(0) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_0_MSDC0_DAT7__FUNC_I2SOUT_DAT
value|(MTK_PIN_NO(0) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_0_MSDC0_DAT7__FUNC_DAC_DAT_OUT
value|(MTK_PIN_NO(0) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_0_MSDC0_DAT7__FUNC_PCM1_DO
value|(MTK_PIN_NO(0) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_0_MSDC0_DAT7__FUNC_SPI1_MO
value|(MTK_PIN_NO(0) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_0_MSDC0_DAT7__FUNC_NALE
value|(MTK_PIN_NO(0) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_1_MSDC0_DAT6__FUNC_GPIO1
value|(MTK_PIN_NO(1) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_1_MSDC0_DAT6__FUNC_MSDC0_DAT6
value|(MTK_PIN_NO(1) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_1_MSDC0_DAT6__FUNC_EINT48
value|(MTK_PIN_NO(1) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_1_MSDC0_DAT6__FUNC_I2SIN_WS
value|(MTK_PIN_NO(1) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_1_MSDC0_DAT6__FUNC_DAC_WS
value|(MTK_PIN_NO(1) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_1_MSDC0_DAT6__FUNC_PCM1_WS
value|(MTK_PIN_NO(1) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_1_MSDC0_DAT6__FUNC_SPI1_CSN
value|(MTK_PIN_NO(1) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_1_MSDC0_DAT6__FUNC_NCLE
value|(MTK_PIN_NO(1) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_2_MSDC0_DAT5__FUNC_GPIO2
value|(MTK_PIN_NO(2) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_2_MSDC0_DAT5__FUNC_MSDC0_DAT5
value|(MTK_PIN_NO(2) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_2_MSDC0_DAT5__FUNC_EINT47
value|(MTK_PIN_NO(2) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_2_MSDC0_DAT5__FUNC_I2SIN_CK
value|(MTK_PIN_NO(2) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_2_MSDC0_DAT5__FUNC_DAC_CK
value|(MTK_PIN_NO(2) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_2_MSDC0_DAT5__FUNC_PCM1_CK
value|(MTK_PIN_NO(2) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_2_MSDC0_DAT5__FUNC_SPI1_CLK
value|(MTK_PIN_NO(2) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_2_MSDC0_DAT5__FUNC_NLD4
value|(MTK_PIN_NO(2) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_3_MSDC0_DAT4__FUNC_GPIO3
value|(MTK_PIN_NO(3) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_3_MSDC0_DAT4__FUNC_MSDC0_DAT4
value|(MTK_PIN_NO(3) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_3_MSDC0_DAT4__FUNC_EINT46
value|(MTK_PIN_NO(3) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_3_MSDC0_DAT4__FUNC_A_FUNC_CK
value|(MTK_PIN_NO(3) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_3_MSDC0_DAT4__FUNC_LSCE1B_2X
value|(MTK_PIN_NO(3) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_3_MSDC0_DAT4__FUNC_NLD5
value|(MTK_PIN_NO(3) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_4_MSDC0_CMD__FUNC_GPIO4
value|(MTK_PIN_NO(4) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_4_MSDC0_CMD__FUNC_MSDC0_CMD
value|(MTK_PIN_NO(4) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_4_MSDC0_CMD__FUNC_EINT41
value|(MTK_PIN_NO(4) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_4_MSDC0_CMD__FUNC_A_FUNC_DOUT_0
value|(MTK_PIN_NO(4) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_4_MSDC0_CMD__FUNC_USB_TEST_IO_0
value|(MTK_PIN_NO(4) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_4_MSDC0_CMD__FUNC_LRSTB_2X
value|(MTK_PIN_NO(4) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_4_MSDC0_CMD__FUNC_NRNB
value|(MTK_PIN_NO(4) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_5_MSDC0_CLK__FUNC_GPIO5
value|(MTK_PIN_NO(5) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_5_MSDC0_CLK__FUNC_MSDC0_CLK
value|(MTK_PIN_NO(5) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_5_MSDC0_CLK__FUNC_EINT40
value|(MTK_PIN_NO(5) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_5_MSDC0_CLK__FUNC_A_FUNC_DOUT_1
value|(MTK_PIN_NO(5) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_5_MSDC0_CLK__FUNC_USB_TEST_IO_1
value|(MTK_PIN_NO(5) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_5_MSDC0_CLK__FUNC_LPTE
value|(MTK_PIN_NO(5) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_5_MSDC0_CLK__FUNC_NREB
value|(MTK_PIN_NO(5) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_6_MSDC0_DAT3__FUNC_GPIO6
value|(MTK_PIN_NO(6) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_6_MSDC0_DAT3__FUNC_MSDC0_DAT3
value|(MTK_PIN_NO(6) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_6_MSDC0_DAT3__FUNC_EINT45
value|(MTK_PIN_NO(6) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_6_MSDC0_DAT3__FUNC_A_FUNC_DOUT_2
value|(MTK_PIN_NO(6) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_6_MSDC0_DAT3__FUNC_USB_TEST_IO_2
value|(MTK_PIN_NO(6) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_6_MSDC0_DAT3__FUNC_LSCE0B_2X
value|(MTK_PIN_NO(6) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_6_MSDC0_DAT3__FUNC_NLD7
value|(MTK_PIN_NO(6) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_7_MSDC0_DAT2__FUNC_GPIO7
value|(MTK_PIN_NO(7) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_7_MSDC0_DAT2__FUNC_MSDC0_DAT2
value|(MTK_PIN_NO(7) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_7_MSDC0_DAT2__FUNC_EINT44
value|(MTK_PIN_NO(7) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_7_MSDC0_DAT2__FUNC_A_FUNC_DOUT_3
value|(MTK_PIN_NO(7) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_7_MSDC0_DAT2__FUNC_USB_TEST_IO_3
value|(MTK_PIN_NO(7) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_7_MSDC0_DAT2__FUNC_LSA0_2X
value|(MTK_PIN_NO(7) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_7_MSDC0_DAT2__FUNC_NLD14
value|(MTK_PIN_NO(7) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_8_MSDC0_DAT1__FUNC_GPIO8
value|(MTK_PIN_NO(8) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_8_MSDC0_DAT1__FUNC_MSDC0_DAT1
value|(MTK_PIN_NO(8) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_8_MSDC0_DAT1__FUNC_EINT43
value|(MTK_PIN_NO(8) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_8_MSDC0_DAT1__FUNC_USB_TEST_IO_4
value|(MTK_PIN_NO(8) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_8_MSDC0_DAT1__FUNC_LSCK_2X
value|(MTK_PIN_NO(8) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_8_MSDC0_DAT1__FUNC_NLD11
value|(MTK_PIN_NO(8) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_9_MSDC0_DAT0__FUNC_GPIO9
value|(MTK_PIN_NO(9) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_9_MSDC0_DAT0__FUNC_MSDC0_DAT0
value|(MTK_PIN_NO(9) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_9_MSDC0_DAT0__FUNC_EINT42
value|(MTK_PIN_NO(9) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_9_MSDC0_DAT0__FUNC_USB_TEST_IO_5
value|(MTK_PIN_NO(9) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_9_MSDC0_DAT0__FUNC_LSDA_2X
value|(MTK_PIN_NO(9) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_10_NCEB0__FUNC_GPIO10
value|(MTK_PIN_NO(10) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_10_NCEB0__FUNC_NCEB0
value|(MTK_PIN_NO(10) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_10_NCEB0__FUNC_EINT139
value|(MTK_PIN_NO(10) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_10_NCEB0__FUNC_TESTA_OUT4
value|(MTK_PIN_NO(10) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_11_NCEB1__FUNC_GPIO11
value|(MTK_PIN_NO(11) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_11_NCEB1__FUNC_NCEB1
value|(MTK_PIN_NO(11) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_11_NCEB1__FUNC_EINT140
value|(MTK_PIN_NO(11) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_11_NCEB1__FUNC_USB_DRVVBUS
value|(MTK_PIN_NO(11) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_11_NCEB1__FUNC_TESTA_OUT5
value|(MTK_PIN_NO(11) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_12_NRNB__FUNC_GPIO12
value|(MTK_PIN_NO(12) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_12_NRNB__FUNC_NRNB
value|(MTK_PIN_NO(12) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_12_NRNB__FUNC_EINT141
value|(MTK_PIN_NO(12) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_12_NRNB__FUNC_A_FUNC_DOUT_4
value|(MTK_PIN_NO(12) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_12_NRNB__FUNC_TESTA_OUT6
value|(MTK_PIN_NO(12) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_13_NCLE__FUNC_GPIO13
value|(MTK_PIN_NO(13) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_13_NCLE__FUNC_NCLE
value|(MTK_PIN_NO(13) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_13_NCLE__FUNC_EINT142
value|(MTK_PIN_NO(13) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_13_NCLE__FUNC_A_FUNC_DOUT_5
value|(MTK_PIN_NO(13) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_13_NCLE__FUNC_CM2PDN_1X
value|(MTK_PIN_NO(13) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_13_NCLE__FUNC_NALE
value|(MTK_PIN_NO(13) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_13_NCLE__FUNC_TESTA_OUT7
value|(MTK_PIN_NO(13) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_14_NALE__FUNC_GPIO14
value|(MTK_PIN_NO(14) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_14_NALE__FUNC_NALE
value|(MTK_PIN_NO(14) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_14_NALE__FUNC_EINT143
value|(MTK_PIN_NO(14) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_14_NALE__FUNC_A_FUNC_DOUT_6
value|(MTK_PIN_NO(14) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_14_NALE__FUNC_CM2MCLK_1X
value|(MTK_PIN_NO(14) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_14_NALE__FUNC_IRDA_RXD
value|(MTK_PIN_NO(14) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_14_NALE__FUNC_NCLE
value|(MTK_PIN_NO(14) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_14_NALE__FUNC_TESTA_OUT8
value|(MTK_PIN_NO(14) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_15_NREB__FUNC_GPIO15
value|(MTK_PIN_NO(15) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_15_NREB__FUNC_NREB
value|(MTK_PIN_NO(15) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_15_NREB__FUNC_EINT144
value|(MTK_PIN_NO(15) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_15_NREB__FUNC_A_FUNC_DOUT_7
value|(MTK_PIN_NO(15) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_15_NREB__FUNC_CM2RST_1X
value|(MTK_PIN_NO(15) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_15_NREB__FUNC_IRDA_TXD
value|(MTK_PIN_NO(15) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_15_NREB__FUNC_TESTA_OUT9
value|(MTK_PIN_NO(15) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_16_NWEB__FUNC_GPIO16
value|(MTK_PIN_NO(16) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_16_NWEB__FUNC_NWEB
value|(MTK_PIN_NO(16) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_16_NWEB__FUNC_EINT145
value|(MTK_PIN_NO(16) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_16_NWEB__FUNC_A_FUNC_DIN_0
value|(MTK_PIN_NO(16) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_16_NWEB__FUNC_CM2PCLK_1X
value|(MTK_PIN_NO(16) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_16_NWEB__FUNC_IRDA_PDN
value|(MTK_PIN_NO(16) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_16_NWEB__FUNC_TESTA_OUT10
value|(MTK_PIN_NO(16) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_17_NLD0__FUNC_GPIO17
value|(MTK_PIN_NO(17) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_17_NLD0__FUNC_NLD0
value|(MTK_PIN_NO(17) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_17_NLD0__FUNC_EINT146
value|(MTK_PIN_NO(17) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_17_NLD0__FUNC_A_FUNC_DIN_1
value|(MTK_PIN_NO(17) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_17_NLD0__FUNC_CM2DAT_1X_0
value|(MTK_PIN_NO(17) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_17_NLD0__FUNC_I2SIN_CK
value|(MTK_PIN_NO(17) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_17_NLD0__FUNC_DAC_CK
value|(MTK_PIN_NO(17) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_17_NLD0__FUNC_TESTA_OUT11
value|(MTK_PIN_NO(17) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_18_NLD1__FUNC_GPIO18
value|(MTK_PIN_NO(18) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_18_NLD1__FUNC_NLD1
value|(MTK_PIN_NO(18) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_18_NLD1__FUNC_EINT147
value|(MTK_PIN_NO(18) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_18_NLD1__FUNC_A_FUNC_DIN_2
value|(MTK_PIN_NO(18) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_18_NLD1__FUNC_CM2DAT_1X_1
value|(MTK_PIN_NO(18) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_18_NLD1__FUNC_I2SIN_WS
value|(MTK_PIN_NO(18) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_18_NLD1__FUNC_DAC_WS
value|(MTK_PIN_NO(18) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_18_NLD1__FUNC_TESTA_OUT12
value|(MTK_PIN_NO(18) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_19_NLD2__FUNC_GPIO19
value|(MTK_PIN_NO(19) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_19_NLD2__FUNC_NLD2
value|(MTK_PIN_NO(19) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_19_NLD2__FUNC_EINT148
value|(MTK_PIN_NO(19) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_19_NLD2__FUNC_A_FUNC_DIN_3
value|(MTK_PIN_NO(19) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_19_NLD2__FUNC_CM2DAT_1X_2
value|(MTK_PIN_NO(19) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_19_NLD2__FUNC_I2SOUT_DAT
value|(MTK_PIN_NO(19) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_19_NLD2__FUNC_DAC_DAT_OUT
value|(MTK_PIN_NO(19) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_19_NLD2__FUNC_TESTA_OUT13
value|(MTK_PIN_NO(19) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_20_NLD3__FUNC_GPIO20
value|(MTK_PIN_NO(20) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_20_NLD3__FUNC_NLD3
value|(MTK_PIN_NO(20) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_20_NLD3__FUNC_EINT149
value|(MTK_PIN_NO(20) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_20_NLD3__FUNC_A_FUNC_DIN_4
value|(MTK_PIN_NO(20) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_20_NLD3__FUNC_CM2DAT_1X_3
value|(MTK_PIN_NO(20) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_20_NLD3__FUNC_TESTA_OUT14
value|(MTK_PIN_NO(20) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_21_NLD4__FUNC_GPIO21
value|(MTK_PIN_NO(21) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_21_NLD4__FUNC_NLD4
value|(MTK_PIN_NO(21) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_21_NLD4__FUNC_EINT150
value|(MTK_PIN_NO(21) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_21_NLD4__FUNC_A_FUNC_DIN_5
value|(MTK_PIN_NO(21) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_21_NLD4__FUNC_CM2DAT_1X_4
value|(MTK_PIN_NO(21) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_21_NLD4__FUNC_TESTA_OUT15
value|(MTK_PIN_NO(21) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_22_NLD5__FUNC_GPIO22
value|(MTK_PIN_NO(22) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_22_NLD5__FUNC_NLD5
value|(MTK_PIN_NO(22) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_22_NLD5__FUNC_EINT151
value|(MTK_PIN_NO(22) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_22_NLD5__FUNC_A_FUNC_DIN_6
value|(MTK_PIN_NO(22) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_22_NLD5__FUNC_CM2DAT_1X_5
value|(MTK_PIN_NO(22) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_22_NLD5__FUNC_TESTA_OUT16
value|(MTK_PIN_NO(22) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_23_NLD6__FUNC_GPIO23
value|(MTK_PIN_NO(23) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_23_NLD6__FUNC_NLD6
value|(MTK_PIN_NO(23) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_23_NLD6__FUNC_EINT152
value|(MTK_PIN_NO(23) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_23_NLD6__FUNC_A_FUNC_DIN_7
value|(MTK_PIN_NO(23) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_23_NLD6__FUNC_CM2DAT_1X_6
value|(MTK_PIN_NO(23) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_23_NLD6__FUNC_TESTA_OUT17
value|(MTK_PIN_NO(23) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_24_NLD7__FUNC_GPIO24
value|(MTK_PIN_NO(24) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_24_NLD7__FUNC_NLD7
value|(MTK_PIN_NO(24) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_24_NLD7__FUNC_EINT153
value|(MTK_PIN_NO(24) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_24_NLD7__FUNC_A_FUNC_DIN_8
value|(MTK_PIN_NO(24) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_24_NLD7__FUNC_CM2DAT_1X_7
value|(MTK_PIN_NO(24) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_24_NLD7__FUNC_TESTA_OUT18
value|(MTK_PIN_NO(24) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_25_NLD8__FUNC_GPIO25
value|(MTK_PIN_NO(25) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_25_NLD8__FUNC_NLD8
value|(MTK_PIN_NO(25) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_25_NLD8__FUNC_EINT154
value|(MTK_PIN_NO(25) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_25_NLD8__FUNC_CM2DAT_1X_8
value|(MTK_PIN_NO(25) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_26_NLD9__FUNC_GPIO26
value|(MTK_PIN_NO(26) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_26_NLD9__FUNC_NLD9
value|(MTK_PIN_NO(26) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_26_NLD9__FUNC_EINT155
value|(MTK_PIN_NO(26) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_26_NLD9__FUNC_CM2DAT_1X_9
value|(MTK_PIN_NO(26) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_26_NLD9__FUNC_PWM1
value|(MTK_PIN_NO(26) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_27_NLD10__FUNC_GPIO27
value|(MTK_PIN_NO(27) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_27_NLD10__FUNC_NLD10
value|(MTK_PIN_NO(27) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_27_NLD10__FUNC_EINT156
value|(MTK_PIN_NO(27) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_27_NLD10__FUNC_CM2VSYNC_1X
value|(MTK_PIN_NO(27) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_27_NLD10__FUNC_PWM2
value|(MTK_PIN_NO(27) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_28_NLD11__FUNC_GPIO28
value|(MTK_PIN_NO(28) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_28_NLD11__FUNC_NLD11
value|(MTK_PIN_NO(28) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_28_NLD11__FUNC_EINT157
value|(MTK_PIN_NO(28) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_28_NLD11__FUNC_CM2HSYNC_1X
value|(MTK_PIN_NO(28) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_28_NLD11__FUNC_PWM3
value|(MTK_PIN_NO(28) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_29_NLD12__FUNC_GPIO29
value|(MTK_PIN_NO(29) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_29_NLD12__FUNC_NLD12
value|(MTK_PIN_NO(29) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_29_NLD12__FUNC_EINT158
value|(MTK_PIN_NO(29) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_29_NLD12__FUNC_I2SIN_CK
value|(MTK_PIN_NO(29) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_29_NLD12__FUNC_DAC_CK
value|(MTK_PIN_NO(29) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_29_NLD12__FUNC_PCM1_CK
value|(MTK_PIN_NO(29) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_30_NLD13__FUNC_GPIO30
value|(MTK_PIN_NO(30) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_30_NLD13__FUNC_NLD13
value|(MTK_PIN_NO(30) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_30_NLD13__FUNC_EINT159
value|(MTK_PIN_NO(30) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_30_NLD13__FUNC_I2SIN_WS
value|(MTK_PIN_NO(30) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_30_NLD13__FUNC_DAC_WS
value|(MTK_PIN_NO(30) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_30_NLD13__FUNC_PCM1_WS
value|(MTK_PIN_NO(30) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_31_NLD14__FUNC_GPIO31
value|(MTK_PIN_NO(31) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_31_NLD14__FUNC_NLD14
value|(MTK_PIN_NO(31) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_31_NLD14__FUNC_EINT160
value|(MTK_PIN_NO(31) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_31_NLD14__FUNC_I2SOUT_DAT
value|(MTK_PIN_NO(31) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_31_NLD14__FUNC_DAC_DAT_OUT
value|(MTK_PIN_NO(31) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_31_NLD14__FUNC_PCM1_DO
value|(MTK_PIN_NO(31) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_32_NLD15__FUNC_GPIO32
value|(MTK_PIN_NO(32) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_32_NLD15__FUNC_NLD15
value|(MTK_PIN_NO(32) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_32_NLD15__FUNC_EINT161
value|(MTK_PIN_NO(32) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_32_NLD15__FUNC_DISP_PWM
value|(MTK_PIN_NO(32) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_32_NLD15__FUNC_PWM4
value|(MTK_PIN_NO(32) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_32_NLD15__FUNC_PCM1_DI
value|(MTK_PIN_NO(32) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_33_MSDC0_RSTB__FUNC_GPIO33
value|(MTK_PIN_NO(33) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_33_MSDC0_RSTB__FUNC_MSDC0_RSTB
value|(MTK_PIN_NO(33) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_33_MSDC0_RSTB__FUNC_EINT50
value|(MTK_PIN_NO(33) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_33_MSDC0_RSTB__FUNC_I2SIN_DAT
value|(MTK_PIN_NO(33) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_33_MSDC0_RSTB__FUNC_PCM1_DI
value|(MTK_PIN_NO(33) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_33_MSDC0_RSTB__FUNC_SPI1_MI
value|(MTK_PIN_NO(33) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_33_MSDC0_RSTB__FUNC_NLD10
value|(MTK_PIN_NO(33) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_34_IDDIG__FUNC_GPIO34
value|(MTK_PIN_NO(34) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_34_IDDIG__FUNC_IDDIG
value|(MTK_PIN_NO(34) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_34_IDDIG__FUNC_EINT34
value|(MTK_PIN_NO(34) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_35_SCL3__FUNC_GPIO35
value|(MTK_PIN_NO(35) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_35_SCL3__FUNC_SCL3
value|(MTK_PIN_NO(35) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_35_SCL3__FUNC_EINT96
value|(MTK_PIN_NO(35) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_35_SCL3__FUNC_CLKM6
value|(MTK_PIN_NO(35) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_35_SCL3__FUNC_PWM6
value|(MTK_PIN_NO(35) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_36_SDA3__FUNC_GPIO36
value|(MTK_PIN_NO(36) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_36_SDA3__FUNC_SDA3
value|(MTK_PIN_NO(36) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_36_SDA3__FUNC_EINT97
value|(MTK_PIN_NO(36) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_37_AUD_CLK_MOSI__FUNC_GPIO37
value|(MTK_PIN_NO(37) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_37_AUD_CLK_MOSI__FUNC_AUD_CLK
value|(MTK_PIN_NO(37) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_37_AUD_CLK_MOSI__FUNC_ADC_CK
value|(MTK_PIN_NO(37) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_37_AUD_CLK_MOSI__FUNC_HDMI_SDATA0
value|(MTK_PIN_NO(37) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_37_AUD_CLK_MOSI__FUNC_EINT19
value|(MTK_PIN_NO(37) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_37_AUD_CLK_MOSI__FUNC_USB_TEST_IO_6
value|(MTK_PIN_NO(37) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_37_AUD_CLK_MOSI__FUNC_TESTA_OUT19
value|(MTK_PIN_NO(37) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_38_AUD_DAT_MOSI__FUNC_GPIO38
value|(MTK_PIN_NO(38) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_38_AUD_DAT_MOSI__FUNC_AUD_DAT_MOSI
value|(MTK_PIN_NO(38) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_38_AUD_DAT_MOSI__FUNC_ADC_WS
value|(MTK_PIN_NO(38) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_38_AUD_DAT_MOSI__FUNC_AUD_DAT_MISO
value|(MTK_PIN_NO(38) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_38_AUD_DAT_MOSI__FUNC_EINT21
value|(MTK_PIN_NO(38) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_38_AUD_DAT_MOSI__FUNC_USB_TEST_IO_7
value|(MTK_PIN_NO(38) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_38_AUD_DAT_MOSI__FUNC_TESTA_OUT20
value|(MTK_PIN_NO(38) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_39_AUD_DAT_MISO__FUNC_GPIO39
value|(MTK_PIN_NO(39) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_39_AUD_DAT_MISO__FUNC_AUD_DAT_MISO
value|(MTK_PIN_NO(39) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_39_AUD_DAT_MISO__FUNC_ADC_DAT_IN
value|(MTK_PIN_NO(39) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_39_AUD_DAT_MISO__FUNC_AUD_DAT_MOSI
value|(MTK_PIN_NO(39) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_39_AUD_DAT_MISO__FUNC_EINT20
value|(MTK_PIN_NO(39) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_39_AUD_DAT_MISO__FUNC_USB_TEST_IO_8
value|(MTK_PIN_NO(39) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_39_AUD_DAT_MISO__FUNC_TESTA_OUT21
value|(MTK_PIN_NO(39) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_40_DAC_CLK__FUNC_GPIO40
value|(MTK_PIN_NO(40) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_40_DAC_CLK__FUNC_DAC_CK
value|(MTK_PIN_NO(40) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_40_DAC_CLK__FUNC_EINT22
value|(MTK_PIN_NO(40) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_40_DAC_CLK__FUNC_HDMI_SDATA1
value|(MTK_PIN_NO(40) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_40_DAC_CLK__FUNC_USB_TEST_IO_9
value|(MTK_PIN_NO(40) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_40_DAC_CLK__FUNC_TESTA_OUT22
value|(MTK_PIN_NO(40) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_41_DAC_WS__FUNC_GPIO41
value|(MTK_PIN_NO(41) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_41_DAC_WS__FUNC_DAC_WS
value|(MTK_PIN_NO(41) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_41_DAC_WS__FUNC_EINT24
value|(MTK_PIN_NO(41) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_41_DAC_WS__FUNC_HDMI_SDATA2
value|(MTK_PIN_NO(41) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_41_DAC_WS__FUNC_USB_TEST_IO_10
value|(MTK_PIN_NO(41) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_41_DAC_WS__FUNC_TESTA_OUT23
value|(MTK_PIN_NO(41) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_42_DAC_DAT_OUT__FUNC_GPIO42
value|(MTK_PIN_NO(42) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_42_DAC_DAT_OUT__FUNC_DAC_DAT_OUT
value|(MTK_PIN_NO(42) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_42_DAC_DAT_OUT__FUNC_EINT23
value|(MTK_PIN_NO(42) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_42_DAC_DAT_OUT__FUNC_HDMI_SDATA3
value|(MTK_PIN_NO(42) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_42_DAC_DAT_OUT__FUNC_USB_TEST_IO_11
value|(MTK_PIN_NO(42) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_42_DAC_DAT_OUT__FUNC_TESTA_OUT24
value|(MTK_PIN_NO(42) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_43_PWRAP_SPI0_MO__FUNC_GPIO43
value|(MTK_PIN_NO(43) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_43_PWRAP_SPI0_MO__FUNC_PWRAP_SPIDI
value|(MTK_PIN_NO(43) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_43_PWRAP_SPI0_MO__FUNC_EINT29
value|(MTK_PIN_NO(43) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_44_PWRAP_SPI0_MI__FUNC_GPIO44
value|(MTK_PIN_NO(44) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_44_PWRAP_SPI0_MI__FUNC_PWRAP_SPIDO
value|(MTK_PIN_NO(44) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_44_PWRAP_SPI0_MI__FUNC_EINT28
value|(MTK_PIN_NO(44) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_45_PWRAP_SPI0_CSN__FUNC_GPIO45
value|(MTK_PIN_NO(45) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_45_PWRAP_SPI0_CSN__FUNC_PWRAP_SPICS_B_I
value|(MTK_PIN_NO(45) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_45_PWRAP_SPI0_CSN__FUNC_EINT27
value|(MTK_PIN_NO(45) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_46_PWRAP_SPI0_CLK__FUNC_GPIO46
value|(MTK_PIN_NO(46) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_46_PWRAP_SPI0_CLK__FUNC_PWRAP_SPICK_I
value|(MTK_PIN_NO(46) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_46_PWRAP_SPI0_CLK__FUNC_EINT26
value|(MTK_PIN_NO(46) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_47_PWRAP_EVENT__FUNC_GPIO47
value|(MTK_PIN_NO(47) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_47_PWRAP_EVENT__FUNC_PWRAP_EVENT_IN
value|(MTK_PIN_NO(47) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_47_PWRAP_EVENT__FUNC_EINT25
value|(MTK_PIN_NO(47) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_47_PWRAP_EVENT__FUNC_TESTA_OUT2
value|(MTK_PIN_NO(47) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_48_RTC32K_CK__FUNC_GPIO48
value|(MTK_PIN_NO(48) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_48_RTC32K_CK__FUNC_RTC32K_CK
value|(MTK_PIN_NO(48) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_49_WATCHDOG__FUNC_GPIO49
value|(MTK_PIN_NO(49) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_49_WATCHDOG__FUNC_WATCHDOG
value|(MTK_PIN_NO(49) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_49_WATCHDOG__FUNC_EINT36
value|(MTK_PIN_NO(49) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_50_SRCLKENA__FUNC_GPIO50
value|(MTK_PIN_NO(50) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_50_SRCLKENA__FUNC_SRCLKENA
value|(MTK_PIN_NO(50) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_50_SRCLKENA__FUNC_EINT38
value|(MTK_PIN_NO(50) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_51_SRCVOLTEN__FUNC_GPIO51
value|(MTK_PIN_NO(51) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_51_SRCVOLTEN__FUNC_SRCVOLTEN
value|(MTK_PIN_NO(51) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_51_SRCVOLTEN__FUNC_EINT37
value|(MTK_PIN_NO(51) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_52_EINT0__FUNC_GPIO52
value|(MTK_PIN_NO(52) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_52_EINT0__FUNC_EINT0
value|(MTK_PIN_NO(52) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_52_EINT0__FUNC_PWM1
value|(MTK_PIN_NO(52) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_52_EINT0__FUNC_CLKM0
value|(MTK_PIN_NO(52) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_52_EINT0__FUNC_SPDIF_OUT
value|(MTK_PIN_NO(52) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_52_EINT0__FUNC_USB_TEST_IO_12
value|(MTK_PIN_NO(52) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_52_EINT0__FUNC_USB_SCL
value|(MTK_PIN_NO(52) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_53_URXD2__FUNC_GPIO53
value|(MTK_PIN_NO(53) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_53_URXD2__FUNC_URXD2
value|(MTK_PIN_NO(53) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_53_URXD2__FUNC_EINT83
value|(MTK_PIN_NO(53) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_53_URXD2__FUNC_HDMI_LRCK
value|(MTK_PIN_NO(53) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_53_URXD2__FUNC_CLKM3
value|(MTK_PIN_NO(53) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_53_URXD2__FUNC_UTXD2
value|(MTK_PIN_NO(53) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_54_UTXD2__FUNC_GPIO54
value|(MTK_PIN_NO(54) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_54_UTXD2__FUNC_UTXD2
value|(MTK_PIN_NO(54) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_54_UTXD2__FUNC_EINT82
value|(MTK_PIN_NO(54) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_54_UTXD2__FUNC_HDMI_BCK_OUT
value|(MTK_PIN_NO(54) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_54_UTXD2__FUNC_CLKM2
value|(MTK_PIN_NO(54) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_54_UTXD2__FUNC_URXD2
value|(MTK_PIN_NO(54) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_55_UCTS2__FUNC_GPIO55
value|(MTK_PIN_NO(55) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_55_UCTS2__FUNC_UCTS2
value|(MTK_PIN_NO(55) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_55_UCTS2__FUNC_EINT84
value|(MTK_PIN_NO(55) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_55_UCTS2__FUNC_PWM1
value|(MTK_PIN_NO(55) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_55_UCTS2__FUNC_URTS2
value|(MTK_PIN_NO(55) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_56_URTS2__FUNC_GPIO56
value|(MTK_PIN_NO(56) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_56_URTS2__FUNC_URTS2
value|(MTK_PIN_NO(56) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_56_URTS2__FUNC_EINT85
value|(MTK_PIN_NO(56) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_56_URTS2__FUNC_PWM2
value|(MTK_PIN_NO(56) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_56_URTS2__FUNC_UCTS2
value|(MTK_PIN_NO(56) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_57_JTCK__FUNC_GPIO57
value|(MTK_PIN_NO(57) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_57_JTCK__FUNC_JTCK
value|(MTK_PIN_NO(57) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_57_JTCK__FUNC_EINT188
value|(MTK_PIN_NO(57) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_57_JTCK__FUNC_DSP1_ICK
value|(MTK_PIN_NO(57) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_58_JTDO__FUNC_GPIO58
value|(MTK_PIN_NO(58) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_58_JTDO__FUNC_JTDO
value|(MTK_PIN_NO(58) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_58_JTDO__FUNC_EINT190
value|(MTK_PIN_NO(58) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_58_JTDO__FUNC_DSP2_IMS
value|(MTK_PIN_NO(58) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_59_JTRST_B__FUNC_GPIO59
value|(MTK_PIN_NO(59) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_59_JTRST_B__FUNC_JTRST_B
value|(MTK_PIN_NO(59) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_59_JTRST_B__FUNC_EINT0
value|(MTK_PIN_NO(59) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_59_JTRST_B__FUNC_DSP2_ICK
value|(MTK_PIN_NO(59) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_60_JTDI__FUNC_GPIO60
value|(MTK_PIN_NO(60) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_60_JTDI__FUNC_JTDI
value|(MTK_PIN_NO(60) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_60_JTDI__FUNC_EINT189
value|(MTK_PIN_NO(60) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_60_JTDI__FUNC_DSP1_IMS
value|(MTK_PIN_NO(60) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_61_JRTCK__FUNC_GPIO61
value|(MTK_PIN_NO(61) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_61_JRTCK__FUNC_JRTCK
value|(MTK_PIN_NO(61) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_61_JRTCK__FUNC_EINT187
value|(MTK_PIN_NO(61) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_61_JRTCK__FUNC_DSP1_ID
value|(MTK_PIN_NO(61) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_62_JTMS__FUNC_GPIO62
value|(MTK_PIN_NO(62) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_62_JTMS__FUNC_JTMS
value|(MTK_PIN_NO(62) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_62_JTMS__FUNC_EINT191
value|(MTK_PIN_NO(62) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_62_JTMS__FUNC_DSP2_ID
value|(MTK_PIN_NO(62) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_63_MSDC1_INSI__FUNC_GPIO63
value|(MTK_PIN_NO(63) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_63_MSDC1_INSI__FUNC_MSDC1_INSI
value|(MTK_PIN_NO(63) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_63_MSDC1_INSI__FUNC_SCL5
value|(MTK_PIN_NO(63) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_63_MSDC1_INSI__FUNC_PWM6
value|(MTK_PIN_NO(63) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_63_MSDC1_INSI__FUNC_CLKM5
value|(MTK_PIN_NO(63) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_63_MSDC1_INSI__FUNC_TESTB_OUT6
value|(MTK_PIN_NO(63) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_64_MSDC1_SDWPI__FUNC_GPIO64
value|(MTK_PIN_NO(64) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_64_MSDC1_SDWPI__FUNC_MSDC1_SDWPI
value|(MTK_PIN_NO(64) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_64_MSDC1_SDWPI__FUNC_EINT58
value|(MTK_PIN_NO(64) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_64_MSDC1_SDWPI__FUNC_SDA5
value|(MTK_PIN_NO(64) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_64_MSDC1_SDWPI__FUNC_PWM7
value|(MTK_PIN_NO(64) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_64_MSDC1_SDWPI__FUNC_CLKM6
value|(MTK_PIN_NO(64) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_64_MSDC1_SDWPI__FUNC_TESTB_OUT7
value|(MTK_PIN_NO(64) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_65_MSDC2_INSI__FUNC_GPIO65
value|(MTK_PIN_NO(65) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_65_MSDC2_INSI__FUNC_MSDC2_INSI
value|(MTK_PIN_NO(65) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_65_MSDC2_INSI__FUNC_USB_TEST_IO_27
value|(MTK_PIN_NO(65) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_65_MSDC2_INSI__FUNC_TESTA_OUT3
value|(MTK_PIN_NO(65) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_66_MSDC2_SDWPI__FUNC_GPIO66
value|(MTK_PIN_NO(66) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_66_MSDC2_SDWPI__FUNC_MSDC2_SDWPI
value|(MTK_PIN_NO(66) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_66_MSDC2_SDWPI__FUNC_EINT66
value|(MTK_PIN_NO(66) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_66_MSDC2_SDWPI__FUNC_USB_TEST_IO_28
value|(MTK_PIN_NO(66) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_67_URXD4__FUNC_GPIO67
value|(MTK_PIN_NO(67) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_67_URXD4__FUNC_URXD4
value|(MTK_PIN_NO(67) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_67_URXD4__FUNC_EINT89
value|(MTK_PIN_NO(67) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_67_URXD4__FUNC_URXD1
value|(MTK_PIN_NO(67) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_67_URXD4__FUNC_UTXD4
value|(MTK_PIN_NO(67) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_67_URXD4__FUNC_TESTB_OUT10
value|(MTK_PIN_NO(67) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_68_UTXD4__FUNC_GPIO68
value|(MTK_PIN_NO(68) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_68_UTXD4__FUNC_UTXD4
value|(MTK_PIN_NO(68) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_68_UTXD4__FUNC_EINT88
value|(MTK_PIN_NO(68) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_68_UTXD4__FUNC_UTXD1
value|(MTK_PIN_NO(68) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_68_UTXD4__FUNC_URXD4
value|(MTK_PIN_NO(68) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_68_UTXD4__FUNC_TESTB_OUT11
value|(MTK_PIN_NO(68) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_69_URXD1__FUNC_GPIO69
value|(MTK_PIN_NO(69) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_69_URXD1__FUNC_URXD1
value|(MTK_PIN_NO(69) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_69_URXD1__FUNC_EINT79
value|(MTK_PIN_NO(69) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_69_URXD1__FUNC_URXD4
value|(MTK_PIN_NO(69) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_69_URXD1__FUNC_UTXD1
value|(MTK_PIN_NO(69) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_69_URXD1__FUNC_TESTB_OUT24
value|(MTK_PIN_NO(69) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_70_UTXD1__FUNC_GPIO70
value|(MTK_PIN_NO(70) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_70_UTXD1__FUNC_UTXD1
value|(MTK_PIN_NO(70) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_70_UTXD1__FUNC_EINT78
value|(MTK_PIN_NO(70) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_70_UTXD1__FUNC_UTXD4
value|(MTK_PIN_NO(70) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_70_UTXD1__FUNC_URXD1
value|(MTK_PIN_NO(70) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_70_UTXD1__FUNC_TESTB_OUT25
value|(MTK_PIN_NO(70) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_71_UCTS1__FUNC_GPIO71
value|(MTK_PIN_NO(71) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_71_UCTS1__FUNC_UCTS1
value|(MTK_PIN_NO(71) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_71_UCTS1__FUNC_EINT80
value|(MTK_PIN_NO(71) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_71_UCTS1__FUNC_CLKM0
value|(MTK_PIN_NO(71) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_71_UCTS1__FUNC_URTS1
value|(MTK_PIN_NO(71) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_71_UCTS1__FUNC_TESTB_OUT31
value|(MTK_PIN_NO(71) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_72_URTS1__FUNC_GPIO72
value|(MTK_PIN_NO(72) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_72_URTS1__FUNC_URTS1
value|(MTK_PIN_NO(72) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_72_URTS1__FUNC_EINT81
value|(MTK_PIN_NO(72) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_72_URTS1__FUNC_CLKM1
value|(MTK_PIN_NO(72) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_72_URTS1__FUNC_UCTS1
value|(MTK_PIN_NO(72) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_72_URTS1__FUNC_TESTB_OUT21
value|(MTK_PIN_NO(72) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_73_PWM1__FUNC_GPIO73
value|(MTK_PIN_NO(73) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_73_PWM1__FUNC_PWM1
value|(MTK_PIN_NO(73) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_73_PWM1__FUNC_EINT73
value|(MTK_PIN_NO(73) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_73_PWM1__FUNC_USB_DRVVBUS
value|(MTK_PIN_NO(73) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_73_PWM1__FUNC_DISP_PWM
value|(MTK_PIN_NO(73) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_73_PWM1__FUNC_TESTB_OUT8
value|(MTK_PIN_NO(73) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_74_PWM2__FUNC_GPIO74
value|(MTK_PIN_NO(74) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_74_PWM2__FUNC_PWM2
value|(MTK_PIN_NO(74) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_74_PWM2__FUNC_EINT74
value|(MTK_PIN_NO(74) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_74_PWM2__FUNC_DPI33_CK
value|(MTK_PIN_NO(74) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_74_PWM2__FUNC_PWM5
value|(MTK_PIN_NO(74) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_74_PWM2__FUNC_URXD2
value|(MTK_PIN_NO(74) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_74_PWM2__FUNC_DISP_PWM
value|(MTK_PIN_NO(74) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_74_PWM2__FUNC_TESTB_OUT9
value|(MTK_PIN_NO(74) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_75_PWM3__FUNC_GPIO75
value|(MTK_PIN_NO(75) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_75_PWM3__FUNC_PWM3
value|(MTK_PIN_NO(75) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_75_PWM3__FUNC_EINT75
value|(MTK_PIN_NO(75) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_75_PWM3__FUNC_DPI33_D0
value|(MTK_PIN_NO(75) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_75_PWM3__FUNC_PWM6
value|(MTK_PIN_NO(75) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_75_PWM3__FUNC_UTXD2
value|(MTK_PIN_NO(75) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_75_PWM3__FUNC_DISP_PWM
value|(MTK_PIN_NO(75) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_75_PWM3__FUNC_TESTB_OUT12
value|(MTK_PIN_NO(75) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_76_PWM4__FUNC_GPIO76
value|(MTK_PIN_NO(76) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_76_PWM4__FUNC_PWM4
value|(MTK_PIN_NO(76) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_76_PWM4__FUNC_EINT76
value|(MTK_PIN_NO(76) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_76_PWM4__FUNC_DPI33_D1
value|(MTK_PIN_NO(76) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_76_PWM4__FUNC_PWM7
value|(MTK_PIN_NO(76) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_76_PWM4__FUNC_DISP_PWM
value|(MTK_PIN_NO(76) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_76_PWM4__FUNC_TESTB_OUT13
value|(MTK_PIN_NO(76) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_77_MSDC2_DAT2__FUNC_GPIO77
value|(MTK_PIN_NO(77) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_77_MSDC2_DAT2__FUNC_MSDC2_DAT2
value|(MTK_PIN_NO(77) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_77_MSDC2_DAT2__FUNC_EINT63
value|(MTK_PIN_NO(77) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_77_MSDC2_DAT2__FUNC_DSP2_IMS
value|(MTK_PIN_NO(77) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_77_MSDC2_DAT2__FUNC_DPI33_D6
value|(MTK_PIN_NO(77) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_77_MSDC2_DAT2__FUNC_TESTA_OUT25
value|(MTK_PIN_NO(77) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_78_MSDC2_DAT3__FUNC_GPIO78
value|(MTK_PIN_NO(78) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_78_MSDC2_DAT3__FUNC_MSDC2_DAT3
value|(MTK_PIN_NO(78) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_78_MSDC2_DAT3__FUNC_EINT64
value|(MTK_PIN_NO(78) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_78_MSDC2_DAT3__FUNC_DSP2_ID
value|(MTK_PIN_NO(78) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_78_MSDC2_DAT3__FUNC_DPI33_D7
value|(MTK_PIN_NO(78) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_78_MSDC2_DAT3__FUNC_TESTA_OUT26
value|(MTK_PIN_NO(78) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_79_MSDC2_CMD__FUNC_GPIO79
value|(MTK_PIN_NO(79) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_79_MSDC2_CMD__FUNC_MSDC2_CMD
value|(MTK_PIN_NO(79) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_79_MSDC2_CMD__FUNC_EINT60
value|(MTK_PIN_NO(79) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_79_MSDC2_CMD__FUNC_DSP1_IMS
value|(MTK_PIN_NO(79) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_79_MSDC2_CMD__FUNC_PCM1_WS
value|(MTK_PIN_NO(79) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_79_MSDC2_CMD__FUNC_DPI33_D3
value|(MTK_PIN_NO(79) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_79_MSDC2_CMD__FUNC_TESTA_OUT0
value|(MTK_PIN_NO(79) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_80_MSDC2_CLK__FUNC_GPIO80
value|(MTK_PIN_NO(80) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_80_MSDC2_CLK__FUNC_MSDC2_CLK
value|(MTK_PIN_NO(80) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_80_MSDC2_CLK__FUNC_EINT59
value|(MTK_PIN_NO(80) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_80_MSDC2_CLK__FUNC_DSP1_ICK
value|(MTK_PIN_NO(80) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_80_MSDC2_CLK__FUNC_PCM1_CK
value|(MTK_PIN_NO(80) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_80_MSDC2_CLK__FUNC_DPI33_D2
value|(MTK_PIN_NO(80) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_80_MSDC2_CLK__FUNC_TESTA_OUT1
value|(MTK_PIN_NO(80) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_81_MSDC2_DAT1__FUNC_GPIO81
value|(MTK_PIN_NO(81) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_81_MSDC2_DAT1__FUNC_MSDC2_DAT1
value|(MTK_PIN_NO(81) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_81_MSDC2_DAT1__FUNC_EINT62
value|(MTK_PIN_NO(81) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_81_MSDC2_DAT1__FUNC_DSP2_ICK
value|(MTK_PIN_NO(81) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_81_MSDC2_DAT1__FUNC_PCM1_DO
value|(MTK_PIN_NO(81) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_81_MSDC2_DAT1__FUNC_DPI33_D5
value|(MTK_PIN_NO(81) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_82_MSDC2_DAT0__FUNC_GPIO82
value|(MTK_PIN_NO(82) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_82_MSDC2_DAT0__FUNC_MSDC2_DAT0
value|(MTK_PIN_NO(82) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_82_MSDC2_DAT0__FUNC_EINT61
value|(MTK_PIN_NO(82) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_82_MSDC2_DAT0__FUNC_DSP1_ID
value|(MTK_PIN_NO(82) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_82_MSDC2_DAT0__FUNC_PCM1_DI
value|(MTK_PIN_NO(82) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_82_MSDC2_DAT0__FUNC_DPI33_D4
value|(MTK_PIN_NO(82) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_83_MSDC1_DAT0__FUNC_GPIO83
value|(MTK_PIN_NO(83) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_83_MSDC1_DAT0__FUNC_MSDC1_DAT0
value|(MTK_PIN_NO(83) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_83_MSDC1_DAT0__FUNC_EINT53
value|(MTK_PIN_NO(83) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_83_MSDC1_DAT0__FUNC_SCL1
value|(MTK_PIN_NO(83) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_83_MSDC1_DAT0__FUNC_PWM2
value|(MTK_PIN_NO(83) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_83_MSDC1_DAT0__FUNC_CLKM1
value|(MTK_PIN_NO(83) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_83_MSDC1_DAT0__FUNC_TESTB_OUT2
value|(MTK_PIN_NO(83) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_84_MSDC1_DAT1__FUNC_GPIO84
value|(MTK_PIN_NO(84) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_84_MSDC1_DAT1__FUNC_MSDC1_DAT1
value|(MTK_PIN_NO(84) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_84_MSDC1_DAT1__FUNC_EINT54
value|(MTK_PIN_NO(84) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_84_MSDC1_DAT1__FUNC_SDA1
value|(MTK_PIN_NO(84) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_84_MSDC1_DAT1__FUNC_PWM3
value|(MTK_PIN_NO(84) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_84_MSDC1_DAT1__FUNC_CLKM2
value|(MTK_PIN_NO(84) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_84_MSDC1_DAT1__FUNC_TESTB_OUT3
value|(MTK_PIN_NO(84) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_85_MSDC1_CMD__FUNC_GPIO85
value|(MTK_PIN_NO(85) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_85_MSDC1_CMD__FUNC_MSDC1_CMD
value|(MTK_PIN_NO(85) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_85_MSDC1_CMD__FUNC_EINT52
value|(MTK_PIN_NO(85) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_85_MSDC1_CMD__FUNC_SDA0
value|(MTK_PIN_NO(85) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_85_MSDC1_CMD__FUNC_PWM1
value|(MTK_PIN_NO(85) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_85_MSDC1_CMD__FUNC_CLKM0
value|(MTK_PIN_NO(85) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_85_MSDC1_CMD__FUNC_TESTB_OUT1
value|(MTK_PIN_NO(85) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_86_MSDC1_CLK__FUNC_GPIO86
value|(MTK_PIN_NO(86) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_86_MSDC1_CLK__FUNC_MSDC1_CLK
value|(MTK_PIN_NO(86) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_86_MSDC1_CLK__FUNC_EINT51
value|(MTK_PIN_NO(86) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_86_MSDC1_CLK__FUNC_SCL0
value|(MTK_PIN_NO(86) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_86_MSDC1_CLK__FUNC_DISP_PWM
value|(MTK_PIN_NO(86) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_86_MSDC1_CLK__FUNC_TESTB_OUT0
value|(MTK_PIN_NO(86) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_87_MSDC1_DAT2__FUNC_GPIO87
value|(MTK_PIN_NO(87) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_87_MSDC1_DAT2__FUNC_MSDC1_DAT2
value|(MTK_PIN_NO(87) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_87_MSDC1_DAT2__FUNC_EINT55
value|(MTK_PIN_NO(87) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_87_MSDC1_DAT2__FUNC_SCL4
value|(MTK_PIN_NO(87) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_87_MSDC1_DAT2__FUNC_PWM4
value|(MTK_PIN_NO(87) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_87_MSDC1_DAT2__FUNC_CLKM3
value|(MTK_PIN_NO(87) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_87_MSDC1_DAT2__FUNC_TESTB_OUT4
value|(MTK_PIN_NO(87) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_88_MSDC1_DAT3__FUNC_GPIO88
value|(MTK_PIN_NO(88) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_88_MSDC1_DAT3__FUNC_MSDC1_DAT3
value|(MTK_PIN_NO(88) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_88_MSDC1_DAT3__FUNC_EINT56
value|(MTK_PIN_NO(88) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_88_MSDC1_DAT3__FUNC_SDA4
value|(MTK_PIN_NO(88) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_88_MSDC1_DAT3__FUNC_PWM5
value|(MTK_PIN_NO(88) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_88_MSDC1_DAT3__FUNC_CLKM4
value|(MTK_PIN_NO(88) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_88_MSDC1_DAT3__FUNC_TESTB_OUT5
value|(MTK_PIN_NO(88) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_89_MSDC4_DAT0__FUNC_GPIO89
value|(MTK_PIN_NO(89) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_89_MSDC4_DAT0__FUNC_MSDC4_DAT0
value|(MTK_PIN_NO(89) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_89_MSDC4_DAT0__FUNC_EINT133
value|(MTK_PIN_NO(89) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_89_MSDC4_DAT0__FUNC_EXT_FRAME_SYNC
value|(MTK_PIN_NO(89) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_89_MSDC4_DAT0__FUNC_USB_DRVVBUS
value|(MTK_PIN_NO(89) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_89_MSDC4_DAT0__FUNC_A_FUNC_DIN_9
value|(MTK_PIN_NO(89) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_89_MSDC4_DAT0__FUNC_LPTE
value|(MTK_PIN_NO(89) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_90_MSDC4_DAT1__FUNC_GPIO90
value|(MTK_PIN_NO(90) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_90_MSDC4_DAT1__FUNC_MSDC4_DAT1
value|(MTK_PIN_NO(90) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_90_MSDC4_DAT1__FUNC_EINT134
value|(MTK_PIN_NO(90) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_90_MSDC4_DAT1__FUNC_A_FUNC_DIN_10
value|(MTK_PIN_NO(90) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_90_MSDC4_DAT1__FUNC_LRSTB_1X
value|(MTK_PIN_NO(90) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_91_MSDC4_DAT5__FUNC_GPIO91
value|(MTK_PIN_NO(91) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_91_MSDC4_DAT5__FUNC_MSDC4_DAT5
value|(MTK_PIN_NO(91) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_91_MSDC4_DAT5__FUNC_EINT136
value|(MTK_PIN_NO(91) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_91_MSDC4_DAT5__FUNC_I2SIN_WS
value|(MTK_PIN_NO(91) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_91_MSDC4_DAT5__FUNC_DAC_WS
value|(MTK_PIN_NO(91) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_91_MSDC4_DAT5__FUNC_PCM1_WS
value|(MTK_PIN_NO(91) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_91_MSDC4_DAT5__FUNC_A_FUNC_DIN_11
value|(MTK_PIN_NO(91) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_91_MSDC4_DAT5__FUNC_SPI1_CSN
value|(MTK_PIN_NO(91) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_92_MSDC4_DAT6__FUNC_GPIO92
value|(MTK_PIN_NO(92) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_92_MSDC4_DAT6__FUNC_MSDC4_DAT6
value|(MTK_PIN_NO(92) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_92_MSDC4_DAT6__FUNC_EINT137
value|(MTK_PIN_NO(92) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_92_MSDC4_DAT6__FUNC_I2SOUT_DAT
value|(MTK_PIN_NO(92) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_92_MSDC4_DAT6__FUNC_DAC_DAT_OUT
value|(MTK_PIN_NO(92) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_92_MSDC4_DAT6__FUNC_PCM1_DO
value|(MTK_PIN_NO(92) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_92_MSDC4_DAT6__FUNC_A_FUNC_DIN_12
value|(MTK_PIN_NO(92) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_92_MSDC4_DAT6__FUNC_SPI1_MO
value|(MTK_PIN_NO(92) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_93_MSDC4_DAT7__FUNC_GPIO93
value|(MTK_PIN_NO(93) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_93_MSDC4_DAT7__FUNC_MSDC4_DAT7
value|(MTK_PIN_NO(93) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_93_MSDC4_DAT7__FUNC_EINT138
value|(MTK_PIN_NO(93) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_93_MSDC4_DAT7__FUNC_I2SIN_DAT
value|(MTK_PIN_NO(93) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_93_MSDC4_DAT7__FUNC_PCM1_DI
value|(MTK_PIN_NO(93) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_93_MSDC4_DAT7__FUNC_A_FUNC_DIN_13
value|(MTK_PIN_NO(93) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_93_MSDC4_DAT7__FUNC_SPI1_MI
value|(MTK_PIN_NO(93) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_94_MSDC4_DAT4__FUNC_GPIO94
value|(MTK_PIN_NO(94) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_94_MSDC4_DAT4__FUNC_MSDC4_DAT4
value|(MTK_PIN_NO(94) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_94_MSDC4_DAT4__FUNC_EINT135
value|(MTK_PIN_NO(94) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_94_MSDC4_DAT4__FUNC_I2SIN_CK
value|(MTK_PIN_NO(94) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_94_MSDC4_DAT4__FUNC_DAC_CK
value|(MTK_PIN_NO(94) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_94_MSDC4_DAT4__FUNC_PCM1_CK
value|(MTK_PIN_NO(94) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_94_MSDC4_DAT4__FUNC_A_FUNC_DIN_14
value|(MTK_PIN_NO(94) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_94_MSDC4_DAT4__FUNC_SPI1_CLK
value|(MTK_PIN_NO(94) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_95_MSDC4_DAT2__FUNC_GPIO95
value|(MTK_PIN_NO(95) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_95_MSDC4_DAT2__FUNC_MSDC4_DAT2
value|(MTK_PIN_NO(95) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_95_MSDC4_DAT2__FUNC_EINT131
value|(MTK_PIN_NO(95) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_95_MSDC4_DAT2__FUNC_I2SIN_WS
value|(MTK_PIN_NO(95) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_95_MSDC4_DAT2__FUNC_CM2PDN_2X
value|(MTK_PIN_NO(95) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_95_MSDC4_DAT2__FUNC_DAC_WS
value|(MTK_PIN_NO(95) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_95_MSDC4_DAT2__FUNC_PCM1_WS
value|(MTK_PIN_NO(95) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_95_MSDC4_DAT2__FUNC_LSCE0B_1X
value|(MTK_PIN_NO(95) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_96_MSDC4_CLK__FUNC_GPIO96
value|(MTK_PIN_NO(96) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_96_MSDC4_CLK__FUNC_MSDC4_CLK
value|(MTK_PIN_NO(96) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_96_MSDC4_CLK__FUNC_EINT129
value|(MTK_PIN_NO(96) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_96_MSDC4_CLK__FUNC_DPI1_CK_2X
value|(MTK_PIN_NO(96) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_96_MSDC4_CLK__FUNC_CM2PCLK_2X
value|(MTK_PIN_NO(96) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_96_MSDC4_CLK__FUNC_PWM4
value|(MTK_PIN_NO(96) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_96_MSDC4_CLK__FUNC_PCM1_DI
value|(MTK_PIN_NO(96) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_96_MSDC4_CLK__FUNC_LSCK_1X
value|(MTK_PIN_NO(96) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_97_MSDC4_DAT3__FUNC_GPIO97
value|(MTK_PIN_NO(97) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_97_MSDC4_DAT3__FUNC_MSDC4_DAT3
value|(MTK_PIN_NO(97) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_97_MSDC4_DAT3__FUNC_EINT132
value|(MTK_PIN_NO(97) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_97_MSDC4_DAT3__FUNC_I2SOUT_DAT
value|(MTK_PIN_NO(97) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_97_MSDC4_DAT3__FUNC_CM2RST_2X
value|(MTK_PIN_NO(97) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_97_MSDC4_DAT3__FUNC_DAC_DAT_OUT
value|(MTK_PIN_NO(97) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_97_MSDC4_DAT3__FUNC_PCM1_DO
value|(MTK_PIN_NO(97) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_97_MSDC4_DAT3__FUNC_LSCE1B_1X
value|(MTK_PIN_NO(97) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_98_MSDC4_CMD__FUNC_GPIO98
value|(MTK_PIN_NO(98) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_98_MSDC4_CMD__FUNC_MSDC4_CMD
value|(MTK_PIN_NO(98) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_98_MSDC4_CMD__FUNC_EINT128
value|(MTK_PIN_NO(98) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_98_MSDC4_CMD__FUNC_DPI1_DE_2X
value|(MTK_PIN_NO(98) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_98_MSDC4_CMD__FUNC_PWM3
value|(MTK_PIN_NO(98) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_98_MSDC4_CMD__FUNC_LSDA_1X
value|(MTK_PIN_NO(98) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_99_MSDC4_RSTB__FUNC_GPIO99
value|(MTK_PIN_NO(99) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_99_MSDC4_RSTB__FUNC_MSDC4_RSTB
value|(MTK_PIN_NO(99) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_99_MSDC4_RSTB__FUNC_EINT130
value|(MTK_PIN_NO(99) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_99_MSDC4_RSTB__FUNC_I2SIN_CK
value|(MTK_PIN_NO(99) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_99_MSDC4_RSTB__FUNC_CM2MCLK_2X
value|(MTK_PIN_NO(99) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_99_MSDC4_RSTB__FUNC_DAC_CK
value|(MTK_PIN_NO(99) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_99_MSDC4_RSTB__FUNC_PCM1_CK
value|(MTK_PIN_NO(99) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_99_MSDC4_RSTB__FUNC_LSA0_1X
value|(MTK_PIN_NO(99) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_100_SDA0__FUNC_GPIO100
value|(MTK_PIN_NO(100) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_100_SDA0__FUNC_SDA0
value|(MTK_PIN_NO(100) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_100_SDA0__FUNC_EINT91
value|(MTK_PIN_NO(100) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_100_SDA0__FUNC_CLKM1
value|(MTK_PIN_NO(100) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_100_SDA0__FUNC_PWM1
value|(MTK_PIN_NO(100) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_100_SDA0__FUNC_A_FUNC_DIN_15
value|(MTK_PIN_NO(100) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_101_SCL0__FUNC_GPIO101
value|(MTK_PIN_NO(101) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_101_SCL0__FUNC_SCL0
value|(MTK_PIN_NO(101) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_101_SCL0__FUNC_EINT90
value|(MTK_PIN_NO(101) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_101_SCL0__FUNC_CLKM0
value|(MTK_PIN_NO(101) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_101_SCL0__FUNC_DISP_PWM
value|(MTK_PIN_NO(101) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_101_SCL0__FUNC_A_FUNC_DIN_16
value|(MTK_PIN_NO(101) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_102_EINT10_AUXIN2__FUNC_GPIO102
value|(MTK_PIN_NO(102) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_102_EINT10_AUXIN2__FUNC_EINT10
value|(MTK_PIN_NO(102) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_102_EINT10_AUXIN2__FUNC_USB_TEST_IO_16
value|(MTK_PIN_NO(102) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_102_EINT10_AUXIN2__FUNC_TESTB_OUT16
value|(MTK_PIN_NO(102) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_102_EINT10_AUXIN2__FUNC_A_FUNC_DIN_17
value|(MTK_PIN_NO(102) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_103_EINT11_AUXIN3__FUNC_GPIO103
value|(MTK_PIN_NO(103) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_103_EINT11_AUXIN3__FUNC_EINT11
value|(MTK_PIN_NO(103) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_103_EINT11_AUXIN3__FUNC_USB_TEST_IO_17
value|(MTK_PIN_NO(103) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_103_EINT11_AUXIN3__FUNC_TESTB_OUT17
value|(MTK_PIN_NO(103) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_103_EINT11_AUXIN3__FUNC_A_FUNC_DIN_18
value|(MTK_PIN_NO(103) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_104_EINT16_AUXIN4__FUNC_GPIO104
value|(MTK_PIN_NO(104) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_104_EINT16_AUXIN4__FUNC_EINT16
value|(MTK_PIN_NO(104) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_104_EINT16_AUXIN4__FUNC_USB_TEST_IO_18
value|(MTK_PIN_NO(104) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_104_EINT16_AUXIN4__FUNC_TESTB_OUT18
value|(MTK_PIN_NO(104) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_104_EINT16_AUXIN4__FUNC_A_FUNC_DIN_19
value|(MTK_PIN_NO(104) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_105_I2S_CLK__FUNC_GPIO105
value|(MTK_PIN_NO(105) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_105_I2S_CLK__FUNC_I2SIN_CK
value|(MTK_PIN_NO(105) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_105_I2S_CLK__FUNC_EINT10
value|(MTK_PIN_NO(105) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_105_I2S_CLK__FUNC_DAC_CK
value|(MTK_PIN_NO(105) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_105_I2S_CLK__FUNC_PCM1_CK
value|(MTK_PIN_NO(105) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_105_I2S_CLK__FUNC_USB_TEST_IO_19
value|(MTK_PIN_NO(105) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_105_I2S_CLK__FUNC_TESTB_OUT19
value|(MTK_PIN_NO(105) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_105_I2S_CLK__FUNC_A_FUNC_DIN_20
value|(MTK_PIN_NO(105) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_106_I2S_WS__FUNC_GPIO106
value|(MTK_PIN_NO(106) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_106_I2S_WS__FUNC_I2SIN_WS
value|(MTK_PIN_NO(106) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_106_I2S_WS__FUNC_EINT13
value|(MTK_PIN_NO(106) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_106_I2S_WS__FUNC_DAC_WS
value|(MTK_PIN_NO(106) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_106_I2S_WS__FUNC_PCM1_WS
value|(MTK_PIN_NO(106) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_106_I2S_WS__FUNC_USB_TEST_IO_20
value|(MTK_PIN_NO(106) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_106_I2S_WS__FUNC_TESTB_OUT20
value|(MTK_PIN_NO(106) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_106_I2S_WS__FUNC_A_FUNC_DIN_21
value|(MTK_PIN_NO(106) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_107_I2S_DATA_IN__FUNC_GPIO107
value|(MTK_PIN_NO(107) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_107_I2S_DATA_IN__FUNC_I2SIN_DAT
value|(MTK_PIN_NO(107) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_107_I2S_DATA_IN__FUNC_EINT11
value|(MTK_PIN_NO(107) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_107_I2S_DATA_IN__FUNC_PCM1_DI
value|(MTK_PIN_NO(107) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_107_I2S_DATA_IN__FUNC_USB_TEST_IO_21
value|(MTK_PIN_NO(107) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_107_I2S_DATA_IN__FUNC_TESTB_OUT22
value|(MTK_PIN_NO(107) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_107_I2S_DATA_IN__FUNC_A_FUNC_DIN_22
value|(MTK_PIN_NO(107) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_108_I2S_DATA_OUT__FUNC_GPIO108
value|(MTK_PIN_NO(108) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_108_I2S_DATA_OUT__FUNC_I2SOUT_DAT
value|(MTK_PIN_NO(108) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_108_I2S_DATA_OUT__FUNC_EINT12
value|(MTK_PIN_NO(108) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_108_I2S_DATA_OUT__FUNC_DAC_DAT_OUT
value|(MTK_PIN_NO(108) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_108_I2S_DATA_OUT__FUNC_PCM1_DO
value|(MTK_PIN_NO(108) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_108_I2S_DATA_OUT__FUNC_USB_TEST_IO_22
value|(MTK_PIN_NO(108) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_108_I2S_DATA_OUT__FUNC_TESTB_OUT23
value|(MTK_PIN_NO(108) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_108_I2S_DATA_OUT__FUNC_A_FUNC_DIN_23
value|(MTK_PIN_NO(108) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_109_EINT5__FUNC_GPIO109
value|(MTK_PIN_NO(109) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_109_EINT5__FUNC_EINT5
value|(MTK_PIN_NO(109) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_109_EINT5__FUNC_PWM5
value|(MTK_PIN_NO(109) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_109_EINT5__FUNC_CLKM3
value|(MTK_PIN_NO(109) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_109_EINT5__FUNC_GPU_JTRSTB
value|(MTK_PIN_NO(109) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_109_EINT5__FUNC_USB_TEST_IO_23
value|(MTK_PIN_NO(109) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_109_EINT5__FUNC_TESTB_OUT26
value|(MTK_PIN_NO(109) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_109_EINT5__FUNC_A_FUNC_DIN_24
value|(MTK_PIN_NO(109) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_110_EINT6__FUNC_GPIO110
value|(MTK_PIN_NO(110) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_110_EINT6__FUNC_EINT6
value|(MTK_PIN_NO(110) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_110_EINT6__FUNC_PWM6
value|(MTK_PIN_NO(110) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_110_EINT6__FUNC_CLKM4
value|(MTK_PIN_NO(110) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_110_EINT6__FUNC_GPU_JTMS
value|(MTK_PIN_NO(110) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_110_EINT6__FUNC_USB_TEST_IO_24
value|(MTK_PIN_NO(110) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_110_EINT6__FUNC_TESTB_OUT27
value|(MTK_PIN_NO(110) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_110_EINT6__FUNC_A_FUNC_DIN_25
value|(MTK_PIN_NO(110) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_111_EINT7__FUNC_GPIO111
value|(MTK_PIN_NO(111) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_111_EINT7__FUNC_EINT7
value|(MTK_PIN_NO(111) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_111_EINT7__FUNC_PWM7
value|(MTK_PIN_NO(111) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_111_EINT7__FUNC_CLKM5
value|(MTK_PIN_NO(111) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_111_EINT7__FUNC_GPU_JTDO
value|(MTK_PIN_NO(111) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_111_EINT7__FUNC_USB_TEST_IO_25
value|(MTK_PIN_NO(111) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_111_EINT7__FUNC_TESTB_OUT28
value|(MTK_PIN_NO(111) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_111_EINT7__FUNC_A_FUNC_DIN_26
value|(MTK_PIN_NO(111) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_112_EINT8__FUNC_GPIO112
value|(MTK_PIN_NO(112) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_112_EINT8__FUNC_EINT8
value|(MTK_PIN_NO(112) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_112_EINT8__FUNC_DISP_PWM
value|(MTK_PIN_NO(112) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_112_EINT8__FUNC_CLKM6
value|(MTK_PIN_NO(112) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_112_EINT8__FUNC_GPU_JTDI
value|(MTK_PIN_NO(112) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_112_EINT8__FUNC_USB_TEST_IO_26
value|(MTK_PIN_NO(112) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_112_EINT8__FUNC_TESTB_OUT29
value|(MTK_PIN_NO(112) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_112_EINT8__FUNC_EXT_FRAME_SYNC
value|(MTK_PIN_NO(112) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_113_EINT9__FUNC_GPIO113
value|(MTK_PIN_NO(113) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_113_EINT9__FUNC_EINT9
value|(MTK_PIN_NO(113) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_113_EINT9__FUNC_GPU_JTCK
value|(MTK_PIN_NO(113) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_113_EINT9__FUNC_USB_DRVVBUS
value|(MTK_PIN_NO(113) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_113_EINT9__FUNC_TESTB_OUT30
value|(MTK_PIN_NO(113) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_113_EINT9__FUNC_A_FUNC_DIN_27
value|(MTK_PIN_NO(113) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_114_LPCE1B__FUNC_GPIO114
value|(MTK_PIN_NO(114) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_114_LPCE1B__FUNC_LPCE1B
value|(MTK_PIN_NO(114) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_114_LPCE1B__FUNC_EINT127
value|(MTK_PIN_NO(114) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_114_LPCE1B__FUNC_PWM2
value|(MTK_PIN_NO(114) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_114_LPCE1B__FUNC_TESTB_OUT14
value|(MTK_PIN_NO(114) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_114_LPCE1B__FUNC_A_FUNC_DIN_28
value|(MTK_PIN_NO(114) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_115_LPCE0B__FUNC_GPIO115
value|(MTK_PIN_NO(115) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_115_LPCE0B__FUNC_LPCE0B
value|(MTK_PIN_NO(115) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_115_LPCE0B__FUNC_EINT126
value|(MTK_PIN_NO(115) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_115_LPCE0B__FUNC_PWM1
value|(MTK_PIN_NO(115) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_115_LPCE0B__FUNC_TESTB_OUT15
value|(MTK_PIN_NO(115) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_115_LPCE0B__FUNC_A_FUNC_DIN_29
value|(MTK_PIN_NO(115) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_116_DISP_PWM__FUNC_GPIO116
value|(MTK_PIN_NO(116) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_116_DISP_PWM__FUNC_DISP_PWM
value|(MTK_PIN_NO(116) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_116_DISP_PWM__FUNC_EINT77
value|(MTK_PIN_NO(116) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_116_DISP_PWM__FUNC_LSDI
value|(MTK_PIN_NO(116) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_116_DISP_PWM__FUNC_PWM1
value|(MTK_PIN_NO(116) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_116_DISP_PWM__FUNC_PWM2
value|(MTK_PIN_NO(116) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_116_DISP_PWM__FUNC_PWM3
value|(MTK_PIN_NO(116) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_117_EINT1__FUNC_GPIO117
value|(MTK_PIN_NO(117) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_117_EINT1__FUNC_EINT1
value|(MTK_PIN_NO(117) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_117_EINT1__FUNC_PWM2
value|(MTK_PIN_NO(117) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_117_EINT1__FUNC_CLKM1
value|(MTK_PIN_NO(117) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_117_EINT1__FUNC_USB_TEST_IO_13
value|(MTK_PIN_NO(117) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_117_EINT1__FUNC_USB_SDA
value|(MTK_PIN_NO(117) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_118_EINT2__FUNC_GPIO118
value|(MTK_PIN_NO(118) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_118_EINT2__FUNC_EINT2
value|(MTK_PIN_NO(118) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_118_EINT2__FUNC_PWM3
value|(MTK_PIN_NO(118) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_118_EINT2__FUNC_CLKM2
value|(MTK_PIN_NO(118) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_118_EINT2__FUNC_USB_TEST_IO_14
value|(MTK_PIN_NO(118) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_118_EINT2__FUNC_SRCLKENAI2
value|(MTK_PIN_NO(118) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_118_EINT2__FUNC_A_FUNC_DIN_30
value|(MTK_PIN_NO(118) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_119_EINT3__FUNC_GPIO119
value|(MTK_PIN_NO(119) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_119_EINT3__FUNC_EINT3
value|(MTK_PIN_NO(119) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_119_EINT3__FUNC_USB_TEST_IO_15
value|(MTK_PIN_NO(119) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_119_EINT3__FUNC_SRCLKENAI1
value|(MTK_PIN_NO(119) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_119_EINT3__FUNC_EXT_26M_CK
value|(MTK_PIN_NO(119) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_120_EINT4__FUNC_GPIO120
value|(MTK_PIN_NO(120) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_120_EINT4__FUNC_EINT4
value|(MTK_PIN_NO(120) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_120_EINT4__FUNC_PWM4
value|(MTK_PIN_NO(120) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_120_EINT4__FUNC_USB_DRVVBUS
value|(MTK_PIN_NO(120) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_120_EINT4__FUNC_A_FUNC_DIN_31
value|(MTK_PIN_NO(120) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_121_DPIDE__FUNC_GPIO121
value|(MTK_PIN_NO(121) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_121_DPIDE__FUNC_DPI0_DE
value|(MTK_PIN_NO(121) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_121_DPIDE__FUNC_EINT100
value|(MTK_PIN_NO(121) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_121_DPIDE__FUNC_I2SOUT_DAT
value|(MTK_PIN_NO(121) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_121_DPIDE__FUNC_DAC_DAT_OUT
value|(MTK_PIN_NO(121) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_121_DPIDE__FUNC_PCM1_DO
value|(MTK_PIN_NO(121) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_121_DPIDE__FUNC_IRDA_TXD
value|(MTK_PIN_NO(121) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_122_DPICK__FUNC_GPIO122
value|(MTK_PIN_NO(122) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_122_DPICK__FUNC_DPI0_CK
value|(MTK_PIN_NO(122) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_122_DPICK__FUNC_EINT101
value|(MTK_PIN_NO(122) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_122_DPICK__FUNC_I2SIN_DAT
value|(MTK_PIN_NO(122) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_122_DPICK__FUNC_PCM1_DI
value|(MTK_PIN_NO(122) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_122_DPICK__FUNC_IRDA_PDN
value|(MTK_PIN_NO(122) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_123_DPIG4__FUNC_GPIO123
value|(MTK_PIN_NO(123) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_123_DPIG4__FUNC_DPI0_G4
value|(MTK_PIN_NO(123) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_123_DPIG4__FUNC_EINT114
value|(MTK_PIN_NO(123) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_123_DPIG4__FUNC_CM2DAT_2X_0
value|(MTK_PIN_NO(123) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_123_DPIG4__FUNC_DSP2_ID
value|(MTK_PIN_NO(123) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_124_DPIG5__FUNC_GPIO124
value|(MTK_PIN_NO(124) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_124_DPIG5__FUNC_DPI0_G5
value|(MTK_PIN_NO(124) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_124_DPIG5__FUNC_EINT115
value|(MTK_PIN_NO(124) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_124_DPIG5__FUNC_CM2DAT_2X_1
value|(MTK_PIN_NO(124) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_124_DPIG5__FUNC_DSP2_ICK
value|(MTK_PIN_NO(124) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_125_DPIR3__FUNC_GPIO125
value|(MTK_PIN_NO(125) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_125_DPIR3__FUNC_DPI0_R3
value|(MTK_PIN_NO(125) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_125_DPIR3__FUNC_EINT121
value|(MTK_PIN_NO(125) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_125_DPIR3__FUNC_CM2DAT_2X_7
value|(MTK_PIN_NO(125) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_126_DPIG1__FUNC_GPIO126
value|(MTK_PIN_NO(126) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_126_DPIG1__FUNC_DPI0_G1
value|(MTK_PIN_NO(126) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_126_DPIG1__FUNC_EINT111
value|(MTK_PIN_NO(126) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_126_DPIG1__FUNC_DSP1_ICK
value|(MTK_PIN_NO(126) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_127_DPIVSYNC__FUNC_GPIO127
value|(MTK_PIN_NO(127) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_127_DPIVSYNC__FUNC_DPI0_VSYNC
value|(MTK_PIN_NO(127) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_127_DPIVSYNC__FUNC_EINT98
value|(MTK_PIN_NO(127) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_127_DPIVSYNC__FUNC_I2SIN_CK
value|(MTK_PIN_NO(127) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_127_DPIVSYNC__FUNC_DAC_CK
value|(MTK_PIN_NO(127) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_127_DPIVSYNC__FUNC_PCM1_CK
value|(MTK_PIN_NO(127) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_128_DPIHSYNC__FUNC_GPIO128
value|(MTK_PIN_NO(128) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_128_DPIHSYNC__FUNC_DPI0_HSYNC
value|(MTK_PIN_NO(128) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_128_DPIHSYNC__FUNC_EINT99
value|(MTK_PIN_NO(128) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_128_DPIHSYNC__FUNC_I2SIN_WS
value|(MTK_PIN_NO(128) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_128_DPIHSYNC__FUNC_DAC_WS
value|(MTK_PIN_NO(128) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_128_DPIHSYNC__FUNC_PCM1_WS
value|(MTK_PIN_NO(128) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_128_DPIHSYNC__FUNC_IRDA_RXD
value|(MTK_PIN_NO(128) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_129_DPIB0__FUNC_GPIO129
value|(MTK_PIN_NO(129) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_129_DPIB0__FUNC_DPI0_B0
value|(MTK_PIN_NO(129) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_129_DPIB0__FUNC_EINT102
value|(MTK_PIN_NO(129) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_129_DPIB0__FUNC_SCL0
value|(MTK_PIN_NO(129) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_129_DPIB0__FUNC_DISP_PWM
value|(MTK_PIN_NO(129) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_130_DPIB1__FUNC_GPIO130
value|(MTK_PIN_NO(130) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_130_DPIB1__FUNC_DPI0_B1
value|(MTK_PIN_NO(130) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_130_DPIB1__FUNC_EINT103
value|(MTK_PIN_NO(130) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_130_DPIB1__FUNC_CLKM0
value|(MTK_PIN_NO(130) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_130_DPIB1__FUNC_SDA0
value|(MTK_PIN_NO(130) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_130_DPIB1__FUNC_PWM1
value|(MTK_PIN_NO(130) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_131_DPIB2__FUNC_GPIO131
value|(MTK_PIN_NO(131) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_131_DPIB2__FUNC_DPI0_B2
value|(MTK_PIN_NO(131) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_131_DPIB2__FUNC_EINT104
value|(MTK_PIN_NO(131) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_131_DPIB2__FUNC_CLKM1
value|(MTK_PIN_NO(131) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_131_DPIB2__FUNC_SCL1
value|(MTK_PIN_NO(131) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_131_DPIB2__FUNC_PWM2
value|(MTK_PIN_NO(131) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_132_DPIB3__FUNC_GPIO132
value|(MTK_PIN_NO(132) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_132_DPIB3__FUNC_DPI0_B3
value|(MTK_PIN_NO(132) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_132_DPIB3__FUNC_EINT105
value|(MTK_PIN_NO(132) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_132_DPIB3__FUNC_CLKM2
value|(MTK_PIN_NO(132) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_132_DPIB3__FUNC_SDA1
value|(MTK_PIN_NO(132) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_132_DPIB3__FUNC_PWM3
value|(MTK_PIN_NO(132) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_133_DPIB4__FUNC_GPIO133
value|(MTK_PIN_NO(133) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_133_DPIB4__FUNC_DPI0_B4
value|(MTK_PIN_NO(133) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_133_DPIB4__FUNC_EINT106
value|(MTK_PIN_NO(133) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_133_DPIB4__FUNC_CLKM3
value|(MTK_PIN_NO(133) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_133_DPIB4__FUNC_SCL2
value|(MTK_PIN_NO(133) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_133_DPIB4__FUNC_PWM4
value|(MTK_PIN_NO(133) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_134_DPIB5__FUNC_GPIO134
value|(MTK_PIN_NO(134) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_134_DPIB5__FUNC_DPI0_B5
value|(MTK_PIN_NO(134) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_134_DPIB5__FUNC_EINT107
value|(MTK_PIN_NO(134) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_134_DPIB5__FUNC_CLKM4
value|(MTK_PIN_NO(134) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_134_DPIB5__FUNC_SDA2
value|(MTK_PIN_NO(134) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_134_DPIB5__FUNC_PWM5
value|(MTK_PIN_NO(134) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_135_DPIB6__FUNC_GPIO135
value|(MTK_PIN_NO(135) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_135_DPIB6__FUNC_DPI0_B6
value|(MTK_PIN_NO(135) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_135_DPIB6__FUNC_EINT108
value|(MTK_PIN_NO(135) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_135_DPIB6__FUNC_CLKM5
value|(MTK_PIN_NO(135) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_135_DPIB6__FUNC_SCL3
value|(MTK_PIN_NO(135) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_135_DPIB6__FUNC_PWM6
value|(MTK_PIN_NO(135) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_136_DPIB7__FUNC_GPIO136
value|(MTK_PIN_NO(136) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_136_DPIB7__FUNC_DPI0_B7
value|(MTK_PIN_NO(136) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_136_DPIB7__FUNC_EINT109
value|(MTK_PIN_NO(136) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_136_DPIB7__FUNC_CLKM6
value|(MTK_PIN_NO(136) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_136_DPIB7__FUNC_SDA3
value|(MTK_PIN_NO(136) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_136_DPIB7__FUNC_PWM7
value|(MTK_PIN_NO(136) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_137_DPIG0__FUNC_GPIO137
value|(MTK_PIN_NO(137) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_137_DPIG0__FUNC_DPI0_G0
value|(MTK_PIN_NO(137) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_137_DPIG0__FUNC_EINT110
value|(MTK_PIN_NO(137) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_137_DPIG0__FUNC_DSP1_ID
value|(MTK_PIN_NO(137) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_138_DPIG2__FUNC_GPIO138
value|(MTK_PIN_NO(138) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_138_DPIG2__FUNC_DPI0_G2
value|(MTK_PIN_NO(138) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_138_DPIG2__FUNC_EINT112
value|(MTK_PIN_NO(138) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_138_DPIG2__FUNC_DSP1_IMS
value|(MTK_PIN_NO(138) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_139_DPIG3__FUNC_GPIO139
value|(MTK_PIN_NO(139) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_139_DPIG3__FUNC_DPI0_G3
value|(MTK_PIN_NO(139) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_139_DPIG3__FUNC_EINT113
value|(MTK_PIN_NO(139) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_139_DPIG3__FUNC_DSP2_IMS
value|(MTK_PIN_NO(139) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_140_DPIG6__FUNC_GPIO140
value|(MTK_PIN_NO(140) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_140_DPIG6__FUNC_DPI0_G6
value|(MTK_PIN_NO(140) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_140_DPIG6__FUNC_EINT116
value|(MTK_PIN_NO(140) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_140_DPIG6__FUNC_CM2DAT_2X_2
value|(MTK_PIN_NO(140) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_141_DPIG7__FUNC_GPIO141
value|(MTK_PIN_NO(141) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_141_DPIG7__FUNC_DPI0_G7
value|(MTK_PIN_NO(141) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_141_DPIG7__FUNC_EINT117
value|(MTK_PIN_NO(141) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_141_DPIG7__FUNC_CM2DAT_2X_3
value|(MTK_PIN_NO(141) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_142_DPIR0__FUNC_GPIO142
value|(MTK_PIN_NO(142) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_142_DPIR0__FUNC_DPI0_R0
value|(MTK_PIN_NO(142) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_142_DPIR0__FUNC_EINT118
value|(MTK_PIN_NO(142) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_142_DPIR0__FUNC_CM2DAT_2X_4
value|(MTK_PIN_NO(142) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_143_DPIR1__FUNC_GPIO143
value|(MTK_PIN_NO(143) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_143_DPIR1__FUNC_DPI0_R1
value|(MTK_PIN_NO(143) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_143_DPIR1__FUNC_EINT119
value|(MTK_PIN_NO(143) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_143_DPIR1__FUNC_CM2DAT_2X_5
value|(MTK_PIN_NO(143) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_144_DPIR2__FUNC_GPIO144
value|(MTK_PIN_NO(144) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_144_DPIR2__FUNC_DPI0_R2
value|(MTK_PIN_NO(144) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_144_DPIR2__FUNC_EINT120
value|(MTK_PIN_NO(144) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_144_DPIR2__FUNC_CM2DAT_2X_6
value|(MTK_PIN_NO(144) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_145_DPIR4__FUNC_GPIO145
value|(MTK_PIN_NO(145) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_145_DPIR4__FUNC_DPI0_R4
value|(MTK_PIN_NO(145) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_145_DPIR4__FUNC_EINT122
value|(MTK_PIN_NO(145) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_145_DPIR4__FUNC_CM2DAT_2X_8
value|(MTK_PIN_NO(145) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_146_DPIR5__FUNC_GPIO146
value|(MTK_PIN_NO(146) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_146_DPIR5__FUNC_DPI0_R5
value|(MTK_PIN_NO(146) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_146_DPIR5__FUNC_EINT123
value|(MTK_PIN_NO(146) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_146_DPIR5__FUNC_CM2DAT_2X_9
value|(MTK_PIN_NO(146) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_147_DPIR6__FUNC_GPIO147
value|(MTK_PIN_NO(147) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_147_DPIR6__FUNC_DPI0_R6
value|(MTK_PIN_NO(147) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_147_DPIR6__FUNC_EINT124
value|(MTK_PIN_NO(147) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_147_DPIR6__FUNC_CM2VSYNC_2X
value|(MTK_PIN_NO(147) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_148_DPIR7__FUNC_GPIO148
value|(MTK_PIN_NO(148) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_148_DPIR7__FUNC_DPI0_R7
value|(MTK_PIN_NO(148) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_148_DPIR7__FUNC_EINT125
value|(MTK_PIN_NO(148) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_148_DPIR7__FUNC_CM2HSYNC_2X
value|(MTK_PIN_NO(148) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_149_TDN3__FUNC_GPIO149
value|(MTK_PIN_NO(149) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_149_TDN3__FUNC_EINT36
value|(MTK_PIN_NO(149) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_150_TDP3__FUNC_GPIO150
value|(MTK_PIN_NO(150) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_150_TDP3__FUNC_EINT35
value|(MTK_PIN_NO(150) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_151_TDN2__FUNC_GPIO151
value|(MTK_PIN_NO(151) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_151_TDN2__FUNC_EINT169
value|(MTK_PIN_NO(151) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_152_TDP2__FUNC_GPIO152
value|(MTK_PIN_NO(152) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_152_TDP2__FUNC_EINT168
value|(MTK_PIN_NO(152) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_153_TCN__FUNC_GPIO153
value|(MTK_PIN_NO(153) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_153_TCN__FUNC_EINT163
value|(MTK_PIN_NO(153) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_154_TCP__FUNC_GPIO154
value|(MTK_PIN_NO(154) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_154_TCP__FUNC_EINT162
value|(MTK_PIN_NO(154) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_155_TDN1__FUNC_GPIO155
value|(MTK_PIN_NO(155) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_155_TDN1__FUNC_EINT167
value|(MTK_PIN_NO(155) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_156_TDP1__FUNC_GPIO156
value|(MTK_PIN_NO(156) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_156_TDP1__FUNC_EINT166
value|(MTK_PIN_NO(156) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_157_TDN0__FUNC_GPIO157
value|(MTK_PIN_NO(157) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_157_TDN0__FUNC_EINT165
value|(MTK_PIN_NO(157) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_158_TDP0__FUNC_GPIO158
value|(MTK_PIN_NO(158) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_158_TDP0__FUNC_EINT164
value|(MTK_PIN_NO(158) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_159_RDN3__FUNC_GPIO159
value|(MTK_PIN_NO(159) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_159_RDN3__FUNC_EINT18
value|(MTK_PIN_NO(159) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_160_RDP3__FUNC_GPIO160
value|(MTK_PIN_NO(160) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_160_RDP3__FUNC_EINT30
value|(MTK_PIN_NO(160) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_161_RDN2__FUNC_GPIO161
value|(MTK_PIN_NO(161) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_161_RDN2__FUNC_EINT31
value|(MTK_PIN_NO(161) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_162_RDP2__FUNC_GPIO162
value|(MTK_PIN_NO(162) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_162_RDP2__FUNC_EINT32
value|(MTK_PIN_NO(162) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_163_RCN__FUNC_GPIO163
value|(MTK_PIN_NO(163) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_163_RCN__FUNC_EINT33
value|(MTK_PIN_NO(163) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_164_RCP__FUNC_GPIO164
value|(MTK_PIN_NO(164) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_164_RCP__FUNC_EINT39
value|(MTK_PIN_NO(164) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_165_RDN1__FUNC_GPIO165
value|(MTK_PIN_NO(165) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_166_RDP1__FUNC_GPIO166
value|(MTK_PIN_NO(166) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_167_RDN0__FUNC_GPIO167
value|(MTK_PIN_NO(167) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_168_RDP0__FUNC_GPIO168
value|(MTK_PIN_NO(168) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_169_RDN1_A__FUNC_GPIO169
value|(MTK_PIN_NO(169) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_169_RDN1_A__FUNC_CMDAT6
value|(MTK_PIN_NO(169) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_169_RDN1_A__FUNC_EINT175
value|(MTK_PIN_NO(169) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_170_RDP1_A__FUNC_GPIO170
value|(MTK_PIN_NO(170) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_170_RDP1_A__FUNC_CMDAT7
value|(MTK_PIN_NO(170) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_170_RDP1_A__FUNC_EINT174
value|(MTK_PIN_NO(170) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_171_RCN_A__FUNC_GPIO171
value|(MTK_PIN_NO(171) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_171_RCN_A__FUNC_CMDAT8
value|(MTK_PIN_NO(171) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_171_RCN_A__FUNC_EINT171
value|(MTK_PIN_NO(171) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_172_RCP_A__FUNC_GPIO172
value|(MTK_PIN_NO(172) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_172_RCP_A__FUNC_CMDAT9
value|(MTK_PIN_NO(172) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_172_RCP_A__FUNC_EINT170
value|(MTK_PIN_NO(172) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_173_RDN0_A__FUNC_GPIO173
value|(MTK_PIN_NO(173) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_173_RDN0_A__FUNC_CMHSYNC
value|(MTK_PIN_NO(173) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_173_RDN0_A__FUNC_EINT173
value|(MTK_PIN_NO(173) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_174_RDP0_A__FUNC_GPIO174
value|(MTK_PIN_NO(174) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_174_RDP0_A__FUNC_CMVSYNC
value|(MTK_PIN_NO(174) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_174_RDP0_A__FUNC_EINT172
value|(MTK_PIN_NO(174) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_175_RDN1_B__FUNC_GPIO175
value|(MTK_PIN_NO(175) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_175_RDN1_B__FUNC_CMDAT2
value|(MTK_PIN_NO(175) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_175_RDN1_B__FUNC_EINT181
value|(MTK_PIN_NO(175) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_175_RDN1_B__FUNC_CMCSD2
value|(MTK_PIN_NO(175) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_176_RDP1_B__FUNC_GPIO176
value|(MTK_PIN_NO(176) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_176_RDP1_B__FUNC_CMDAT3
value|(MTK_PIN_NO(176) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_176_RDP1_B__FUNC_EINT180
value|(MTK_PIN_NO(176) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_176_RDP1_B__FUNC_CMCSD3
value|(MTK_PIN_NO(176) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_177_RCN_B__FUNC_GPIO177
value|(MTK_PIN_NO(177) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_177_RCN_B__FUNC_CMDAT4
value|(MTK_PIN_NO(177) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_177_RCN_B__FUNC_EINT177
value|(MTK_PIN_NO(177) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_178_RCP_B__FUNC_GPIO178
value|(MTK_PIN_NO(178) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_178_RCP_B__FUNC_CMDAT5
value|(MTK_PIN_NO(178) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_178_RCP_B__FUNC_EINT176
value|(MTK_PIN_NO(178) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_179_RDN0_B__FUNC_GPIO179
value|(MTK_PIN_NO(179) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_179_RDN0_B__FUNC_CMDAT0
value|(MTK_PIN_NO(179) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_179_RDN0_B__FUNC_EINT179
value|(MTK_PIN_NO(179) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_179_RDN0_B__FUNC_CMCSD0
value|(MTK_PIN_NO(179) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_180_RDP0_B__FUNC_GPIO180
value|(MTK_PIN_NO(180) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_180_RDP0_B__FUNC_CMDAT1
value|(MTK_PIN_NO(180) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_180_RDP0_B__FUNC_EINT178
value|(MTK_PIN_NO(180) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_180_RDP0_B__FUNC_CMCSD1
value|(MTK_PIN_NO(180) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_181_CMPCLK__FUNC_GPIO181
value|(MTK_PIN_NO(181) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_181_CMPCLK__FUNC_CMPCLK
value|(MTK_PIN_NO(181) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_181_CMPCLK__FUNC_EINT182
value|(MTK_PIN_NO(181) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_181_CMPCLK__FUNC_CMCSK
value|(MTK_PIN_NO(181) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_181_CMPCLK__FUNC_CM2MCLK_4X
value|(MTK_PIN_NO(181) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_181_CMPCLK__FUNC_TS_AUXADC_SEL_3
value|(MTK_PIN_NO(181) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_181_CMPCLK__FUNC_VENC_TEST_CK
value|(MTK_PIN_NO(181) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_181_CMPCLK__FUNC_TESTA_OUT27
value|(MTK_PIN_NO(181) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_182_CMMCLK__FUNC_GPIO182
value|(MTK_PIN_NO(182) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_182_CMMCLK__FUNC_CMMCLK
value|(MTK_PIN_NO(182) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_182_CMMCLK__FUNC_EINT183
value|(MTK_PIN_NO(182) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_182_CMMCLK__FUNC_TS_AUXADC_SEL_2
value|(MTK_PIN_NO(182) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_182_CMMCLK__FUNC_TESTA_OUT28
value|(MTK_PIN_NO(182) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_183_CMRST__FUNC_GPIO183
value|(MTK_PIN_NO(183) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_183_CMRST__FUNC_CMRST
value|(MTK_PIN_NO(183) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_183_CMRST__FUNC_EINT185
value|(MTK_PIN_NO(183) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_183_CMRST__FUNC_TS_AUXADC_SEL_1
value|(MTK_PIN_NO(183) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_183_CMRST__FUNC_TESTA_OUT30
value|(MTK_PIN_NO(183) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_184_CMPDN__FUNC_GPIO184
value|(MTK_PIN_NO(184) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_184_CMPDN__FUNC_CMPDN
value|(MTK_PIN_NO(184) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_184_CMPDN__FUNC_EINT184
value|(MTK_PIN_NO(184) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_184_CMPDN__FUNC_TS_AUXADC_SEL_0
value|(MTK_PIN_NO(184) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_184_CMPDN__FUNC_TESTA_OUT29
value|(MTK_PIN_NO(184) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_185_CMFLASH__FUNC_GPIO185
value|(MTK_PIN_NO(185) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_185_CMFLASH__FUNC_CMFLASH
value|(MTK_PIN_NO(185) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_185_CMFLASH__FUNC_EINT186
value|(MTK_PIN_NO(185) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_185_CMFLASH__FUNC_CM2MCLK_3X
value|(MTK_PIN_NO(185) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_185_CMFLASH__FUNC_MFG_TEST_CK_1
value|(MTK_PIN_NO(185) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_185_CMFLASH__FUNC_TESTA_OUT31
value|(MTK_PIN_NO(185) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_186_MRG_I2S_PCM_CLK__FUNC_GPIO186
value|(MTK_PIN_NO(186) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_186_MRG_I2S_PCM_CLK__FUNC_MRG_I2S_P_CLK
value|(MTK_PIN_NO(186) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_186_MRG_I2S_PCM_CLK__FUNC_EINT14
value|(MTK_PIN_NO(186) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_186_MRG_I2S_PCM_CLK__FUNC_I2SIN_CK
value|(MTK_PIN_NO(186) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_186_MRG_I2S_PCM_CLK__FUNC_PCM0_CK
value|(MTK_PIN_NO(186) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_186_MRG_I2S_PCM_CLK__FUNC_DSP2_ICK
value|(MTK_PIN_NO(186) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_186_MRG_I2S_PCM_CLK__FUNC_IMG_TEST_CK
value|(MTK_PIN_NO(186) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_186_MRG_I2S_PCM_CLK__FUNC_USB_SCL
value|(MTK_PIN_NO(186) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_187_MRG_I2S_PCM_SYNC__FUNC_GPIO187
value|(MTK_PIN_NO(187) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_187_MRG_I2S_PCM_SYNC__FUNC_MRG_I2S_SYNC
value|(MTK_PIN_NO(187) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_187_MRG_I2S_PCM_SYNC__FUNC_EINT16
value|(MTK_PIN_NO(187) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_187_MRG_I2S_PCM_SYNC__FUNC_I2SIN_WS
value|(MTK_PIN_NO(187) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_187_MRG_I2S_PCM_SYNC__FUNC_PCM0_WS
value|(MTK_PIN_NO(187) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_187_MRG_I2S_PCM_SYNC__FUNC_DISP_TEST_CK
value|(MTK_PIN_NO(187) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_188_MRG_I2S_PCM_RX__FUNC_GPIO188
value|(MTK_PIN_NO(188) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_188_MRG_I2S_PCM_RX__FUNC_MRG_I2S_PCM_RX
value|(MTK_PIN_NO(188) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_188_MRG_I2S_PCM_RX__FUNC_EINT15
value|(MTK_PIN_NO(188) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_188_MRG_I2S_PCM_RX__FUNC_I2SIN_DAT
value|(MTK_PIN_NO(188) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_188_MRG_I2S_PCM_RX__FUNC_PCM0_DI
value|(MTK_PIN_NO(188) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_188_MRG_I2S_PCM_RX__FUNC_DSP2_ID
value|(MTK_PIN_NO(188) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_188_MRG_I2S_PCM_RX__FUNC_MFG_TEST_CK
value|(MTK_PIN_NO(188) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_188_MRG_I2S_PCM_RX__FUNC_USB_SDA
value|(MTK_PIN_NO(188) | 7)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_189_MRG_I2S_PCM_TX__FUNC_GPIO189
value|(MTK_PIN_NO(189) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_189_MRG_I2S_PCM_TX__FUNC_MRG_I2S_PCM_TX
value|(MTK_PIN_NO(189) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_189_MRG_I2S_PCM_TX__FUNC_EINT17
value|(MTK_PIN_NO(189) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_189_MRG_I2S_PCM_TX__FUNC_I2SOUT_DAT
value|(MTK_PIN_NO(189) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_189_MRG_I2S_PCM_TX__FUNC_PCM0_DO
value|(MTK_PIN_NO(189) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_189_MRG_I2S_PCM_TX__FUNC_VDEC_TEST_CK
value|(MTK_PIN_NO(189) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_190_SRCLKENAI__FUNC_GPIO190
value|(MTK_PIN_NO(190) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_190_SRCLKENAI__FUNC_SRCLKENAI
value|(MTK_PIN_NO(190) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_191_URXD3__FUNC_GPIO191
value|(MTK_PIN_NO(191) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_191_URXD3__FUNC_URXD3
value|(MTK_PIN_NO(191) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_191_URXD3__FUNC_EINT87
value|(MTK_PIN_NO(191) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_191_URXD3__FUNC_UTXD3
value|(MTK_PIN_NO(191) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_191_URXD3__FUNC_TS_AUX_ST
value|(MTK_PIN_NO(191) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_191_URXD3__FUNC_PWM4
value|(MTK_PIN_NO(191) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_192_UTXD3__FUNC_GPIO192
value|(MTK_PIN_NO(192) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_192_UTXD3__FUNC_UTXD3
value|(MTK_PIN_NO(192) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_192_UTXD3__FUNC_EINT86
value|(MTK_PIN_NO(192) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_192_UTXD3__FUNC_URXD3
value|(MTK_PIN_NO(192) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_192_UTXD3__FUNC_TS_AUX_CS_B
value|(MTK_PIN_NO(192) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_192_UTXD3__FUNC_PWM3
value|(MTK_PIN_NO(192) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_193_SDA2__FUNC_GPIO193
value|(MTK_PIN_NO(193) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_193_SDA2__FUNC_SDA2
value|(MTK_PIN_NO(193) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_193_SDA2__FUNC_EINT95
value|(MTK_PIN_NO(193) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_193_SDA2__FUNC_CLKM5
value|(MTK_PIN_NO(193) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_193_SDA2__FUNC_PWM5
value|(MTK_PIN_NO(193) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_193_SDA2__FUNC_TS_AUX_PWDB
value|(MTK_PIN_NO(193) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_194_SCL2__FUNC_GPIO194
value|(MTK_PIN_NO(194) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_194_SCL2__FUNC_SCL2
value|(MTK_PIN_NO(194) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_194_SCL2__FUNC_EINT94
value|(MTK_PIN_NO(194) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_194_SCL2__FUNC_CLKM4
value|(MTK_PIN_NO(194) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_194_SCL2__FUNC_PWM4
value|(MTK_PIN_NO(194) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_194_SCL2__FUNC_TS_AUXADC_TEST_CK
value|(MTK_PIN_NO(194) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_195_SDA1__FUNC_GPIO195
value|(MTK_PIN_NO(195) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_195_SDA1__FUNC_SDA1
value|(MTK_PIN_NO(195) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_195_SDA1__FUNC_EINT93
value|(MTK_PIN_NO(195) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_195_SDA1__FUNC_CLKM3
value|(MTK_PIN_NO(195) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_195_SDA1__FUNC_PWM3
value|(MTK_PIN_NO(195) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_195_SDA1__FUNC_TS_AUX_SCLK_PWDB
value|(MTK_PIN_NO(195) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_196_SCL1__FUNC_GPIO196
value|(MTK_PIN_NO(196) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_196_SCL1__FUNC_SCL1
value|(MTK_PIN_NO(196) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_196_SCL1__FUNC_EINT92
value|(MTK_PIN_NO(196) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_196_SCL1__FUNC_CLKM2
value|(MTK_PIN_NO(196) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_196_SCL1__FUNC_PWM2
value|(MTK_PIN_NO(196) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_196_SCL1__FUNC_TS_AUX_DIN
value|(MTK_PIN_NO(196) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_197_MSDC3_DAT2__FUNC_GPIO197
value|(MTK_PIN_NO(197) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_197_MSDC3_DAT2__FUNC_MSDC3_DAT2
value|(MTK_PIN_NO(197) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_197_MSDC3_DAT2__FUNC_EINT71
value|(MTK_PIN_NO(197) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_197_MSDC3_DAT2__FUNC_SCL6
value|(MTK_PIN_NO(197) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_197_MSDC3_DAT2__FUNC_PWM5
value|(MTK_PIN_NO(197) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_197_MSDC3_DAT2__FUNC_CLKM4
value|(MTK_PIN_NO(197) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_197_MSDC3_DAT2__FUNC_MFG_TEST_CK_2
value|(MTK_PIN_NO(197) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_198_MSDC3_DAT3__FUNC_GPIO198
value|(MTK_PIN_NO(198) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_198_MSDC3_DAT3__FUNC_MSDC3_DAT3
value|(MTK_PIN_NO(198) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_198_MSDC3_DAT3__FUNC_EINT72
value|(MTK_PIN_NO(198) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_198_MSDC3_DAT3__FUNC_SDA6
value|(MTK_PIN_NO(198) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_198_MSDC3_DAT3__FUNC_PWM6
value|(MTK_PIN_NO(198) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_198_MSDC3_DAT3__FUNC_CLKM5
value|(MTK_PIN_NO(198) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_198_MSDC3_DAT3__FUNC_MFG_TEST_CK_3
value|(MTK_PIN_NO(198) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_199_MSDC3_CMD__FUNC_GPIO199
value|(MTK_PIN_NO(199) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_199_MSDC3_CMD__FUNC_MSDC3_CMD
value|(MTK_PIN_NO(199) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_199_MSDC3_CMD__FUNC_EINT68
value|(MTK_PIN_NO(199) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_199_MSDC3_CMD__FUNC_SDA2
value|(MTK_PIN_NO(199) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_199_MSDC3_CMD__FUNC_PWM2
value|(MTK_PIN_NO(199) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_199_MSDC3_CMD__FUNC_CLKM1
value|(MTK_PIN_NO(199) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_199_MSDC3_CMD__FUNC_MFG_TEST_CK_4
value|(MTK_PIN_NO(199) | 6)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_200_MSDC3_CLK__FUNC_GPIO200
value|(MTK_PIN_NO(200) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_200_MSDC3_CLK__FUNC_MSDC3_CLK
value|(MTK_PIN_NO(200) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_200_MSDC3_CLK__FUNC_EINT67
value|(MTK_PIN_NO(200) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_200_MSDC3_CLK__FUNC_SCL2
value|(MTK_PIN_NO(200) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_200_MSDC3_CLK__FUNC_PWM1
value|(MTK_PIN_NO(200) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_200_MSDC3_CLK__FUNC_CLKM0
value|(MTK_PIN_NO(200) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_201_MSDC3_DAT1__FUNC_GPIO201
value|(MTK_PIN_NO(201) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_201_MSDC3_DAT1__FUNC_MSDC3_DAT1
value|(MTK_PIN_NO(201) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_201_MSDC3_DAT1__FUNC_EINT70
value|(MTK_PIN_NO(201) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_201_MSDC3_DAT1__FUNC_SDA3
value|(MTK_PIN_NO(201) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_201_MSDC3_DAT1__FUNC_PWM4
value|(MTK_PIN_NO(201) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_201_MSDC3_DAT1__FUNC_CLKM3
value|(MTK_PIN_NO(201) | 5)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_202_MSDC3_DAT0__FUNC_GPIO202
value|(MTK_PIN_NO(202) | 0)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_202_MSDC3_DAT0__FUNC_MSDC3_DAT0
value|(MTK_PIN_NO(202) | 1)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_202_MSDC3_DAT0__FUNC_EINT69
value|(MTK_PIN_NO(202) | 2)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_202_MSDC3_DAT0__FUNC_SCL3
value|(MTK_PIN_NO(202) | 3)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_202_MSDC3_DAT0__FUNC_PWM3
value|(MTK_PIN_NO(202) | 4)
end_define

begin_define
define|#
directive|define
name|MT8135_PIN_202_MSDC3_DAT0__FUNC_CLKM2
value|(MTK_PIN_NO(202) | 5)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DTS_MT8135_PINFUNC_H */
end_comment

end_unit

