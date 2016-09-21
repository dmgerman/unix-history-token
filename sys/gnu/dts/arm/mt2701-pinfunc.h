begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2015 MediaTek Inc.  * Author: Biao Huang<biao.huang@mediatek.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DTS_MT2701_PINFUNC_H
end_ifndef

begin_define
define|#
directive|define
name|__DTS_MT2701_PINFUNC_H
end_define

begin_include
include|#
directive|include
file|<dt-bindings/pinctrl/mt65xx.h>
end_include

begin_define
define|#
directive|define
name|MT2701_PIN_0_PWRAP_SPI0_MI__FUNC_GPIO0
value|(MTK_PIN_NO(0) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_0_PWRAP_SPI0_MI__FUNC_PWRAP_SPIDO
value|(MTK_PIN_NO(0) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_0_PWRAP_SPI0_MI__FUNC_PWRAP_SPIDI
value|(MTK_PIN_NO(0) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_1_PWRAP_SPI0_MO__FUNC_GPIO1
value|(MTK_PIN_NO(1) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_1_PWRAP_SPI0_MO__FUNC_PWRAP_SPIDI
value|(MTK_PIN_NO(1) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_1_PWRAP_SPI0_MO__FUNC_PWRAP_SPIDO
value|(MTK_PIN_NO(1) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_2_PWRAP_INT__FUNC_GPIO2
value|(MTK_PIN_NO(2) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_2_PWRAP_INT__FUNC_PWRAP_INT
value|(MTK_PIN_NO(2) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_3_PWRAP_SPI0_CK__FUNC_GPIO3
value|(MTK_PIN_NO(3) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_3_PWRAP_SPI0_CK__FUNC_PWRAP_SPICK_I
value|(MTK_PIN_NO(3) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_4_PWRAP_SPI0_CSN__FUNC_GPIO4
value|(MTK_PIN_NO(4) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_4_PWRAP_SPI0_CSN__FUNC_PWRAP_SPICS_B_I
value|(MTK_PIN_NO(4) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_5_PWRAP_SPI0_CK2__FUNC_GPIO5
value|(MTK_PIN_NO(5) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_5_PWRAP_SPI0_CK2__FUNC_PWRAP_SPICK2_I
value|(MTK_PIN_NO(5) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_5_PWRAP_SPI0_CK2__FUNC_ANT_SEL1
value|(MTK_PIN_NO(5) | 5)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_6_PWRAP_SPI0_CSN2__FUNC_GPIO6
value|(MTK_PIN_NO(6) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_6_PWRAP_SPI0_CSN2__FUNC_PWRAP_SPICS2_B_I
value|(MTK_PIN_NO(6) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_6_PWRAP_SPI0_CSN2__FUNC_ANT_SEL0
value|(MTK_PIN_NO(6) | 5)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_6_PWRAP_SPI0_CSN2__FUNC_DBG_MON_A_0
value|(MTK_PIN_NO(6) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_7_SPI1_CSN__FUNC_GPIO7
value|(MTK_PIN_NO(7) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_7_SPI1_CSN__FUNC_SPI1_CS
value|(MTK_PIN_NO(7) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_7_SPI1_CSN__FUNC_KCOL0
value|(MTK_PIN_NO(7) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_7_SPI1_CSN__FUNC_DBG_MON_B_12
value|(MTK_PIN_NO(7) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_8_SPI1_MI__FUNC_GPIO8
value|(MTK_PIN_NO(8) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_8_SPI1_MI__FUNC_SPI1_MI
value|(MTK_PIN_NO(8) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_8_SPI1_MI__FUNC_SPI1_MO
value|(MTK_PIN_NO(8) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_8_SPI1_MI__FUNC_KCOL1
value|(MTK_PIN_NO(8) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_8_SPI1_MI__FUNC_DBG_MON_B_13
value|(MTK_PIN_NO(8) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_9_SPI1_MO__FUNC_GPIO9
value|(MTK_PIN_NO(9) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_9_SPI1_MO__FUNC_SPI1_MO
value|(MTK_PIN_NO(9) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_9_SPI1_MO__FUNC_SPI1_MI
value|(MTK_PIN_NO(9) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_9_SPI1_MO__FUNC_EXT_FRAME_SYNC
value|(MTK_PIN_NO(9) | 3)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_9_SPI1_MO__FUNC_KCOL2
value|(MTK_PIN_NO(9) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_9_SPI1_MO__FUNC_DBG_MON_B_14
value|(MTK_PIN_NO(9) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_10_RTC32K_CK__FUNC_GPIO10
value|(MTK_PIN_NO(10) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_10_RTC32K_CK__FUNC_RTC32K_CK
value|(MTK_PIN_NO(10) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_11_WATCHDOG__FUNC_GPIO11
value|(MTK_PIN_NO(11) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_11_WATCHDOG__FUNC_WATCHDOG
value|(MTK_PIN_NO(11) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_12_SRCLKENA__FUNC_GPIO12
value|(MTK_PIN_NO(12) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_12_SRCLKENA__FUNC_SRCLKENA
value|(MTK_PIN_NO(12) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_13_SRCLKENAI__FUNC_GPIO13
value|(MTK_PIN_NO(13) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_13_SRCLKENAI__FUNC_SRCLKENAI
value|(MTK_PIN_NO(13) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_14_URXD2__FUNC_GPIO14
value|(MTK_PIN_NO(14) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_14_URXD2__FUNC_URXD2
value|(MTK_PIN_NO(14) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_14_URXD2__FUNC_UTXD2
value|(MTK_PIN_NO(14) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_14_URXD2__FUNC_SRCCLKENAI2
value|(MTK_PIN_NO(14) | 5)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_14_URXD2__FUNC_DBG_MON_B_30
value|(MTK_PIN_NO(14) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_15_UTXD2__FUNC_GPIO15
value|(MTK_PIN_NO(15) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_15_UTXD2__FUNC_UTXD2
value|(MTK_PIN_NO(15) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_15_UTXD2__FUNC_URXD2
value|(MTK_PIN_NO(15) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_15_UTXD2__FUNC_DBG_MON_B_31
value|(MTK_PIN_NO(15) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_18_PCM_CLK__FUNC_GPIO18
value|(MTK_PIN_NO(18) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_18_PCM_CLK__FUNC_PCM_CLK0
value|(MTK_PIN_NO(18) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_18_PCM_CLK__FUNC_MRG_CLK
value|(MTK_PIN_NO(18) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_18_PCM_CLK__FUNC_MM_TEST_CK
value|(MTK_PIN_NO(18) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_18_PCM_CLK__FUNC_CONN_DSP_JCK
value|(MTK_PIN_NO(18) | 5)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_18_PCM_CLK__FUNC_WCN_PCM_CLKO
value|(MTK_PIN_NO(18) | 6)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_18_PCM_CLK__FUNC_DBG_MON_A_3
value|(MTK_PIN_NO(18) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_19_PCM_SYNC__FUNC_GPIO19
value|(MTK_PIN_NO(19) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_19_PCM_SYNC__FUNC_PCM_SYNC
value|(MTK_PIN_NO(19) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_19_PCM_SYNC__FUNC_MRG_SYNC
value|(MTK_PIN_NO(19) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_19_PCM_SYNC__FUNC_CONN_DSP_JINTP
value|(MTK_PIN_NO(19) | 5)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_19_PCM_SYNC__FUNC_WCN_PCM_SYNC
value|(MTK_PIN_NO(19) | 6)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_19_PCM_SYNC__FUNC_DBG_MON_A_5
value|(MTK_PIN_NO(19) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_20_PCM_RX__FUNC_GPIO20
value|(MTK_PIN_NO(20) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_20_PCM_RX__FUNC_PCM_RX
value|(MTK_PIN_NO(20) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_20_PCM_RX__FUNC_MRG_RX
value|(MTK_PIN_NO(20) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_20_PCM_RX__FUNC_MRG_TX
value|(MTK_PIN_NO(20) | 3)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_20_PCM_RX__FUNC_PCM_TX
value|(MTK_PIN_NO(20) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_20_PCM_RX__FUNC_CONN_DSP_JDI
value|(MTK_PIN_NO(20) | 5)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_20_PCM_RX__FUNC_WCN_PCM_RX
value|(MTK_PIN_NO(20) | 6)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_20_PCM_RX__FUNC_DBG_MON_A_4
value|(MTK_PIN_NO(20) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_21_PCM_TX__FUNC_GPIO21
value|(MTK_PIN_NO(21) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_21_PCM_TX__FUNC_PCM_TX
value|(MTK_PIN_NO(21) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_21_PCM_TX__FUNC_MRG_TX
value|(MTK_PIN_NO(21) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_21_PCM_TX__FUNC_MRG_RX
value|(MTK_PIN_NO(21) | 3)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_21_PCM_TX__FUNC_PCM_RX
value|(MTK_PIN_NO(21) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_21_PCM_TX__FUNC_CONN_DSP_JMS
value|(MTK_PIN_NO(21) | 5)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_21_PCM_TX__FUNC_WCN_PCM_TX
value|(MTK_PIN_NO(21) | 6)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_21_PCM_TX__FUNC_DBG_MON_A_2
value|(MTK_PIN_NO(21) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_22_EINT0__FUNC_GPIO22
value|(MTK_PIN_NO(22) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_22_EINT0__FUNC_UCTS0
value|(MTK_PIN_NO(22) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_22_EINT0__FUNC_KCOL3
value|(MTK_PIN_NO(22) | 3)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_22_EINT0__FUNC_CONN_DSP_JDO
value|(MTK_PIN_NO(22) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_22_EINT0__FUNC_EXT_FRAME_SYNC
value|(MTK_PIN_NO(22) | 5)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_22_EINT0__FUNC_DBG_MON_A_30
value|(MTK_PIN_NO(22) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_22_EINT0__FUNC_PCIE0_PERST_N
value|(MTK_PIN_NO(22) | 10)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_23_EINT1__FUNC_GPIO23
value|(MTK_PIN_NO(23) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_23_EINT1__FUNC_URTS0
value|(MTK_PIN_NO(23) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_23_EINT1__FUNC_KCOL2
value|(MTK_PIN_NO(23) | 3)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_23_EINT1__FUNC_CONN_MCU_TDO
value|(MTK_PIN_NO(23) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_23_EINT1__FUNC_EXT_FRAME_SYNC
value|(MTK_PIN_NO(23) | 5)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_23_EINT1__FUNC_DBG_MON_A_29
value|(MTK_PIN_NO(23) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_23_EINT1__FUNC_PCIE1_PERST_N
value|(MTK_PIN_NO(23) | 10)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_24_EINT2__FUNC_GPIO24
value|(MTK_PIN_NO(24) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_24_EINT2__FUNC_UCTS1
value|(MTK_PIN_NO(24) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_24_EINT2__FUNC_KCOL1
value|(MTK_PIN_NO(24) | 3)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_24_EINT2__FUNC_CONN_MCU_DBGACK_N
value|(MTK_PIN_NO(24) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_24_EINT2__FUNC_DBG_MON_A_28
value|(MTK_PIN_NO(24) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_24_EINT2__FUNC_PCIE2_PERST_N
value|(MTK_PIN_NO(24) | 10)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_25_EINT3__FUNC_GPIO25
value|(MTK_PIN_NO(25) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_25_EINT3__FUNC_URTS1
value|(MTK_PIN_NO(25) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_25_EINT3__FUNC_KCOL0
value|(MTK_PIN_NO(25) | 3)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_25_EINT3__FUNC_CONN_MCU_DBGI_N
value|(MTK_PIN_NO(25) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_25_EINT3__FUNC_DBG_MON_A_27
value|(MTK_PIN_NO(25) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_26_EINT4__FUNC_GPIO26
value|(MTK_PIN_NO(26) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_26_EINT4__FUNC_UCTS3
value|(MTK_PIN_NO(26) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_26_EINT4__FUNC_DRV_VBUS_P1
value|(MTK_PIN_NO(26) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_26_EINT4__FUNC_KROW3
value|(MTK_PIN_NO(26) | 3)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_26_EINT4__FUNC_CONN_MCU_TCK0
value|(MTK_PIN_NO(26) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_26_EINT4__FUNC_CONN_MCU_AICE_JCKC
value|(MTK_PIN_NO(26) | 5)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_26_EINT4__FUNC_PCIE2_WAKE_N
value|(MTK_PIN_NO(26) | 6)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_26_EINT4__FUNC_DBG_MON_A_26
value|(MTK_PIN_NO(26) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_27_EINT5__FUNC_GPIO27
value|(MTK_PIN_NO(27) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_27_EINT5__FUNC_URTS3
value|(MTK_PIN_NO(27) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_27_EINT5__FUNC_IDDIG_P1
value|(MTK_PIN_NO(27) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_27_EINT5__FUNC_KROW2
value|(MTK_PIN_NO(27) | 3)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_27_EINT5__FUNC_CONN_MCU_TDI
value|(MTK_PIN_NO(27) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_27_EINT5__FUNC_PCIE1_WAKE_N
value|(MTK_PIN_NO(27) | 6)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_27_EINT5__FUNC_DBG_MON_A_25
value|(MTK_PIN_NO(27) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_28_EINT6__FUNC_GPIO28
value|(MTK_PIN_NO(28) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_28_EINT6__FUNC_DRV_VBUS
value|(MTK_PIN_NO(28) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_28_EINT6__FUNC_KROW1
value|(MTK_PIN_NO(28) | 3)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_28_EINT6__FUNC_CONN_MCU_TRST_B
value|(MTK_PIN_NO(28) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_28_EINT6__FUNC_PCIE0_WAKE_N
value|(MTK_PIN_NO(28) | 6)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_28_EINT6__FUNC_DBG_MON_A_24
value|(MTK_PIN_NO(28) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_29_EINT7__FUNC_GPIO29
value|(MTK_PIN_NO(29) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_29_EINT7__FUNC_IDDIG
value|(MTK_PIN_NO(29) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_29_EINT7__FUNC_MSDC1_WP
value|(MTK_PIN_NO(29) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_29_EINT7__FUNC_KROW0
value|(MTK_PIN_NO(29) | 3)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_29_EINT7__FUNC_CONN_MCU_TMS
value|(MTK_PIN_NO(29) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_29_EINT7__FUNC_CONN_MCU_AICE_JMSC
value|(MTK_PIN_NO(29) | 5)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_29_EINT7__FUNC_DBG_MON_A_23
value|(MTK_PIN_NO(29) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_29_EINT7__FUNC_PCIE2_PERST_N
value|(MTK_PIN_NO(29) | 14)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_33_I2S1_DATA__FUNC_GPIO33
value|(MTK_PIN_NO(33) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_33_I2S1_DATA__FUNC_I2S1_DATA
value|(MTK_PIN_NO(33) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_33_I2S1_DATA__FUNC_I2S1_DATA_BYPS
value|(MTK_PIN_NO(33) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_33_I2S1_DATA__FUNC_PCM_TX
value|(MTK_PIN_NO(33) | 3)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_33_I2S1_DATA__FUNC_IMG_TEST_CK
value|(MTK_PIN_NO(33) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_33_I2S1_DATA__FUNC_G1_RXD0
value|(MTK_PIN_NO(33) | 5)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_33_I2S1_DATA__FUNC_WCN_PCM_TX
value|(MTK_PIN_NO(33) | 6)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_33_I2S1_DATA__FUNC_DBG_MON_B_8
value|(MTK_PIN_NO(33) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_34_I2S1_DATA_IN__FUNC_GPIO34
value|(MTK_PIN_NO(34) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_34_I2S1_DATA_IN__FUNC_I2S1_DATA_IN
value|(MTK_PIN_NO(34) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_34_I2S1_DATA_IN__FUNC_PCM_RX
value|(MTK_PIN_NO(34) | 3)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_34_I2S1_DATA_IN__FUNC_VDEC_TEST_CK
value|(MTK_PIN_NO(34) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_34_I2S1_DATA_IN__FUNC_G1_RXD1
value|(MTK_PIN_NO(34) | 5)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_34_I2S1_DATA_IN__FUNC_WCN_PCM_RX
value|(MTK_PIN_NO(34) | 6)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_34_I2S1_DATA_IN__FUNC_DBG_MON_B_7
value|(MTK_PIN_NO(34) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_35_I2S1_BCK__FUNC_GPIO35
value|(MTK_PIN_NO(35) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_35_I2S1_BCK__FUNC_I2S1_BCK
value|(MTK_PIN_NO(35) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_35_I2S1_BCK__FUNC_PCM_CLK0
value|(MTK_PIN_NO(35) | 3)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_35_I2S1_BCK__FUNC_G1_RXD2
value|(MTK_PIN_NO(35) | 5)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_35_I2S1_BCK__FUNC_WCN_PCM_CLKO
value|(MTK_PIN_NO(35) | 6)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_35_I2S1_BCK__FUNC_DBG_MON_B_9
value|(MTK_PIN_NO(35) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_36_I2S1_LRCK__FUNC_GPIO36
value|(MTK_PIN_NO(36) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_36_I2S1_LRCK__FUNC_I2S1_LRCK
value|(MTK_PIN_NO(36) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_36_I2S1_LRCK__FUNC_PCM_SYNC
value|(MTK_PIN_NO(36) | 3)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_36_I2S1_LRCK__FUNC_G1_RXD3
value|(MTK_PIN_NO(36) | 5)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_36_I2S1_LRCK__FUNC_WCN_PCM_SYNC
value|(MTK_PIN_NO(36) | 6)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_36_I2S1_LRCK__FUNC_DBG_MON_B_10
value|(MTK_PIN_NO(36) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_37_I2S1_MCLK__FUNC_GPIO37
value|(MTK_PIN_NO(37) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_37_I2S1_MCLK__FUNC_I2S1_MCLK
value|(MTK_PIN_NO(37) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_37_I2S1_MCLK__FUNC_G1_RXDV
value|(MTK_PIN_NO(37) | 5)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_37_I2S1_MCLK__FUNC_DBG_MON_B_11
value|(MTK_PIN_NO(37) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_39_JTMS__FUNC_GPIO39
value|(MTK_PIN_NO(39) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_39_JTMS__FUNC_JTMS
value|(MTK_PIN_NO(39) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_39_JTMS__FUNC_CONN_MCU_TMS
value|(MTK_PIN_NO(39) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_39_JTMS__FUNC_CONN_MCU_AICE_JMSC
value|(MTK_PIN_NO(39) | 3)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_39_JTMS__FUNC_DFD_TMS_XI
value|(MTK_PIN_NO(39) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_40_JTCK__FUNC_GPIO40
value|(MTK_PIN_NO(40) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_40_JTCK__FUNC_JTCK
value|(MTK_PIN_NO(40) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_40_JTCK__FUNC_CONN_MCU_TCK1
value|(MTK_PIN_NO(40) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_40_JTCK__FUNC_CONN_MCU_AICE_JCKC
value|(MTK_PIN_NO(40) | 3)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_40_JTCK__FUNC_DFD_TCK_XI
value|(MTK_PIN_NO(40) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_41_JTDI__FUNC_GPIO41
value|(MTK_PIN_NO(41) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_41_JTDI__FUNC_JTDI
value|(MTK_PIN_NO(41) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_41_JTDI__FUNC_CONN_MCU_TDI
value|(MTK_PIN_NO(41) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_41_JTDI__FUNC_DFD_TDI_XI
value|(MTK_PIN_NO(41) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_42_JTDO__FUNC_GPIO42
value|(MTK_PIN_NO(42) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_42_JTDO__FUNC_JTDO
value|(MTK_PIN_NO(42) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_42_JTDO__FUNC_CONN_MCU_TDO
value|(MTK_PIN_NO(42) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_42_JTDO__FUNC_DFD_TDO
value|(MTK_PIN_NO(42) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_43_NCLE__FUNC_GPIO43
value|(MTK_PIN_NO(43) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_43_NCLE__FUNC_NCLE
value|(MTK_PIN_NO(43) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_43_NCLE__FUNC_EXT_XCS2
value|(MTK_PIN_NO(43) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_44_NCEB1__FUNC_GPIO44
value|(MTK_PIN_NO(44) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_44_NCEB1__FUNC_NCEB1
value|(MTK_PIN_NO(44) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_44_NCEB1__FUNC_IDDIG
value|(MTK_PIN_NO(44) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_45_NCEB0__FUNC_GPIO45
value|(MTK_PIN_NO(45) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_45_NCEB0__FUNC_NCEB0
value|(MTK_PIN_NO(45) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_45_NCEB0__FUNC_DRV_VBUS
value|(MTK_PIN_NO(45) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_46_IR__FUNC_GPIO46
value|(MTK_PIN_NO(46) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_46_IR__FUNC_IR
value|(MTK_PIN_NO(46) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_47_NREB__FUNC_GPIO47
value|(MTK_PIN_NO(47) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_47_NREB__FUNC_NREB
value|(MTK_PIN_NO(47) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_47_NREB__FUNC_IDDIG_P1
value|(MTK_PIN_NO(47) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_48_NRNB__FUNC_GPIO48
value|(MTK_PIN_NO(48) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_48_NRNB__FUNC_NRNB
value|(MTK_PIN_NO(48) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_48_NRNB__FUNC_DRV_VBUS_P1
value|(MTK_PIN_NO(48) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_49_I2S0_DATA__FUNC_GPIO49
value|(MTK_PIN_NO(49) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_49_I2S0_DATA__FUNC_I2S0_DATA
value|(MTK_PIN_NO(49) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_49_I2S0_DATA__FUNC_I2S0_DATA_BYPS
value|(MTK_PIN_NO(49) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_49_I2S0_DATA__FUNC_PCM_TX
value|(MTK_PIN_NO(49) | 3)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_49_I2S0_DATA__FUNC_WCN_I2S_DO
value|(MTK_PIN_NO(49) | 6)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_49_I2S0_DATA__FUNC_DBG_MON_B_3
value|(MTK_PIN_NO(49) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_53_SPI0_CSN__FUNC_GPIO53
value|(MTK_PIN_NO(53) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_53_SPI0_CSN__FUNC_SPI0_CS
value|(MTK_PIN_NO(53) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_53_SPI0_CSN__FUNC_SPDIF
value|(MTK_PIN_NO(53) | 3)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_53_SPI0_CSN__FUNC_ADC_CK
value|(MTK_PIN_NO(53) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_53_SPI0_CSN__FUNC_PWM1
value|(MTK_PIN_NO(53) | 5)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_53_SPI0_CSN__FUNC_DBG_MON_A_7
value|(MTK_PIN_NO(53) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_54_SPI0_CK__FUNC_GPIO54
value|(MTK_PIN_NO(54) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_54_SPI0_CK__FUNC_SPI0_CK
value|(MTK_PIN_NO(54) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_54_SPI0_CK__FUNC_SPDIF_IN1
value|(MTK_PIN_NO(54) | 3)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_54_SPI0_CK__FUNC_ADC_DAT_IN
value|(MTK_PIN_NO(54) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_54_SPI0_CK__FUNC_DBG_MON_A_10
value|(MTK_PIN_NO(54) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_55_SPI0_MI__FUNC_GPIO55
value|(MTK_PIN_NO(55) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_55_SPI0_MI__FUNC_SPI0_MI
value|(MTK_PIN_NO(55) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_55_SPI0_MI__FUNC_SPI0_MO
value|(MTK_PIN_NO(55) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_55_SPI0_MI__FUNC_MSDC1_WP
value|(MTK_PIN_NO(55) | 3)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_55_SPI0_MI__FUNC_ADC_WS
value|(MTK_PIN_NO(55) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_55_SPI0_MI__FUNC_PWM2
value|(MTK_PIN_NO(55) | 5)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_55_SPI0_MI__FUNC_DBG_MON_A_8
value|(MTK_PIN_NO(55) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_56_SPI0_MO__FUNC_GPIO56
value|(MTK_PIN_NO(56) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_56_SPI0_MO__FUNC_SPI0_MO
value|(MTK_PIN_NO(56) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_56_SPI0_MO__FUNC_SPI0_MI
value|(MTK_PIN_NO(56) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_56_SPI0_MO__FUNC_SPDIF_IN0
value|(MTK_PIN_NO(56) | 3)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_56_SPI0_MO__FUNC_DBG_MON_A_9
value|(MTK_PIN_NO(56) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_57_SDA1__FUNC_GPIO57
value|(MTK_PIN_NO(57) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_57_SDA1__FUNC_SDA1
value|(MTK_PIN_NO(57) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_58_SCL1__FUNC_GPIO58
value|(MTK_PIN_NO(58) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_58_SCL1__FUNC_SCL1
value|(MTK_PIN_NO(58) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_72_I2S0_DATA_IN__FUNC_GPIO72
value|(MTK_PIN_NO(72) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_72_I2S0_DATA_IN__FUNC_I2S0_DATA_IN
value|(MTK_PIN_NO(72) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_72_I2S0_DATA_IN__FUNC_PCM_RX
value|(MTK_PIN_NO(72) | 3)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_72_I2S0_DATA_IN__FUNC_PWM0
value|(MTK_PIN_NO(72) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_72_I2S0_DATA_IN__FUNC_DISP_PWM
value|(MTK_PIN_NO(72) | 5)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_72_I2S0_DATA_IN__FUNC_WCN_I2S_DI
value|(MTK_PIN_NO(72) | 6)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_72_I2S0_DATA_IN__FUNC_DBG_MON_B_2
value|(MTK_PIN_NO(72) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_73_I2S0_LRCK__FUNC_GPIO73
value|(MTK_PIN_NO(73) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_73_I2S0_LRCK__FUNC_I2S0_LRCK
value|(MTK_PIN_NO(73) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_73_I2S0_LRCK__FUNC_PCM_SYNC
value|(MTK_PIN_NO(73) | 3)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_73_I2S0_LRCK__FUNC_WCN_I2S_LRCK
value|(MTK_PIN_NO(73) | 6)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_73_I2S0_LRCK__FUNC_DBG_MON_B_5
value|(MTK_PIN_NO(73) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_74_I2S0_BCK__FUNC_GPIO74
value|(MTK_PIN_NO(74) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_74_I2S0_BCK__FUNC_I2S0_BCK
value|(MTK_PIN_NO(74) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_74_I2S0_BCK__FUNC_PCM_CLK0
value|(MTK_PIN_NO(74) | 3)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_74_I2S0_BCK__FUNC_WCN_I2S_BCK
value|(MTK_PIN_NO(74) | 6)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_74_I2S0_BCK__FUNC_DBG_MON_B_4
value|(MTK_PIN_NO(74) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_75_SDA0__FUNC_GPIO75
value|(MTK_PIN_NO(75) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_75_SDA0__FUNC_SDA0
value|(MTK_PIN_NO(75) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_76_SCL0__FUNC_GPIO76
value|(MTK_PIN_NO(76) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_76_SCL0__FUNC_SCL0
value|(MTK_PIN_NO(76) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_77_SDA2__FUNC_GPIO77
value|(MTK_PIN_NO(77) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_77_SDA2__FUNC_SDA2
value|(MTK_PIN_NO(77) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_78_SCL2__FUNC_GPIO78
value|(MTK_PIN_NO(78) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_78_SCL2__FUNC_SCL2
value|(MTK_PIN_NO(78) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_79_URXD0__FUNC_GPIO79
value|(MTK_PIN_NO(79) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_79_URXD0__FUNC_URXD0
value|(MTK_PIN_NO(79) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_79_URXD0__FUNC_UTXD0
value|(MTK_PIN_NO(79) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_79_URXD0__FUNC_
value|(MTK_PIN_NO(79) | 5)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_80_UTXD0__FUNC_GPIO80
value|(MTK_PIN_NO(80) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_80_UTXD0__FUNC_UTXD0
value|(MTK_PIN_NO(80) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_80_UTXD0__FUNC_URXD0
value|(MTK_PIN_NO(80) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_81_URXD1__FUNC_GPIO81
value|(MTK_PIN_NO(81) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_81_URXD1__FUNC_URXD1
value|(MTK_PIN_NO(81) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_81_URXD1__FUNC_UTXD1
value|(MTK_PIN_NO(81) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_82_UTXD1__FUNC_GPIO82
value|(MTK_PIN_NO(82) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_82_UTXD1__FUNC_UTXD1
value|(MTK_PIN_NO(82) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_82_UTXD1__FUNC_URXD1
value|(MTK_PIN_NO(82) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_83_LCM_RST__FUNC_GPIO83
value|(MTK_PIN_NO(83) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_83_LCM_RST__FUNC_LCM_RST
value|(MTK_PIN_NO(83) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_83_LCM_RST__FUNC_VDAC_CK_XI
value|(MTK_PIN_NO(83) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_83_LCM_RST__FUNC_DBG_MON_B_1
value|(MTK_PIN_NO(83) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_84_DSI_TE__FUNC_GPIO84
value|(MTK_PIN_NO(84) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_84_DSI_TE__FUNC_DSI_TE
value|(MTK_PIN_NO(84) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_84_DSI_TE__FUNC_DBG_MON_B_0
value|(MTK_PIN_NO(84) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_91_TDN3__FUNC_GPI91
value|(MTK_PIN_NO(91) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_91_TDN3__FUNC_TDN3
value|(MTK_PIN_NO(91) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_92_TDP3__FUNC_GPI92
value|(MTK_PIN_NO(92) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_92_TDP3__FUNC_TDP3
value|(MTK_PIN_NO(92) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_93_TDN2__FUNC_GPI93
value|(MTK_PIN_NO(93) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_93_TDN2__FUNC_TDN2
value|(MTK_PIN_NO(93) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_94_TDP2__FUNC_GPI94
value|(MTK_PIN_NO(94) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_94_TDP2__FUNC_TDP2
value|(MTK_PIN_NO(94) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_95_TCN__FUNC_GPI95
value|(MTK_PIN_NO(95) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_95_TCN__FUNC_TCN
value|(MTK_PIN_NO(95) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_96_TCP__FUNC_GPI96
value|(MTK_PIN_NO(96) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_96_TCP__FUNC_TCP
value|(MTK_PIN_NO(96) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_97_TDN1__FUNC_GPI97
value|(MTK_PIN_NO(97) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_97_TDN1__FUNC_TDN1
value|(MTK_PIN_NO(97) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_98_TDP1__FUNC_GPI98
value|(MTK_PIN_NO(98) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_98_TDP1__FUNC_TDP1
value|(MTK_PIN_NO(98) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_99_TDN0__FUNC_GPI99
value|(MTK_PIN_NO(99) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_99_TDN0__FUNC_TDN0
value|(MTK_PIN_NO(99) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_100_TDP0__FUNC_GPI100
value|(MTK_PIN_NO(100) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_100_TDP0__FUNC_TDP0
value|(MTK_PIN_NO(100) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_101_SPI2_CSN__FUNC_GPIO101
value|(MTK_PIN_NO(101) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_101_SPI2_CSN__FUNC_SPI2_CS
value|(MTK_PIN_NO(101) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_101_SPI2_CSN__FUNC_SCL3
value|(MTK_PIN_NO(101) | 3)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_101_SPI2_CSN__FUNC_KROW0
value|(MTK_PIN_NO(101) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_102_SPI2_MI__FUNC_GPIO102
value|(MTK_PIN_NO(102) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_102_SPI2_MI__FUNC_SPI2_MI
value|(MTK_PIN_NO(102) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_102_SPI2_MI__FUNC_SPI2_MO
value|(MTK_PIN_NO(102) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_102_SPI2_MI__FUNC_SDA3
value|(MTK_PIN_NO(102) | 3)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_102_SPI2_MI__FUNC_KROW1
value|(MTK_PIN_NO(102) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_103_SPI2_MO__FUNC_GPIO103
value|(MTK_PIN_NO(103) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_103_SPI2_MO__FUNC_SPI2_MO
value|(MTK_PIN_NO(103) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_103_SPI2_MO__FUNC_SPI2_MI
value|(MTK_PIN_NO(103) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_103_SPI2_MO__FUNC_SCL3
value|(MTK_PIN_NO(103) | 3)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_103_SPI2_MO__FUNC_KROW2
value|(MTK_PIN_NO(103) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_104_SPI2_CLK__FUNC_GPIO104
value|(MTK_PIN_NO(104) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_104_SPI2_CLK__FUNC_SPI2_CK
value|(MTK_PIN_NO(104) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_104_SPI2_CLK__FUNC_SDA3
value|(MTK_PIN_NO(104) | 3)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_104_SPI2_CLK__FUNC_KROW3
value|(MTK_PIN_NO(104) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_105_MSDC1_CMD__FUNC_GPIO105
value|(MTK_PIN_NO(105) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_105_MSDC1_CMD__FUNC_MSDC1_CMD
value|(MTK_PIN_NO(105) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_105_MSDC1_CMD__FUNC_ANT_SEL0
value|(MTK_PIN_NO(105) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_105_MSDC1_CMD__FUNC_SDA1
value|(MTK_PIN_NO(105) | 3)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_105_MSDC1_CMD__FUNC_I2SOUT_BCK
value|(MTK_PIN_NO(105) | 6)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_105_MSDC1_CMD__FUNC_DBG_MON_B_27
value|(MTK_PIN_NO(105) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_106_MSDC1_CLK__FUNC_GPIO106
value|(MTK_PIN_NO(106) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_106_MSDC1_CLK__FUNC_MSDC1_CLK
value|(MTK_PIN_NO(106) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_106_MSDC1_CLK__FUNC_ANT_SEL1
value|(MTK_PIN_NO(106) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_106_MSDC1_CLK__FUNC_SCL1
value|(MTK_PIN_NO(106) | 3)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_106_MSDC1_CLK__FUNC_I2SOUT_LRCK
value|(MTK_PIN_NO(106) | 6)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_106_MSDC1_CLK__FUNC_DBG_MON_B_28
value|(MTK_PIN_NO(106) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_107_MSDC1_DAT0__FUNC_GPIO107
value|(MTK_PIN_NO(107) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_107_MSDC1_DAT0__FUNC_MSDC1_DAT0
value|(MTK_PIN_NO(107) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_107_MSDC1_DAT0__FUNC_ANT_SEL2
value|(MTK_PIN_NO(107) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_107_MSDC1_DAT0__FUNC_UTXD0
value|(MTK_PIN_NO(107) | 5)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_107_MSDC1_DAT0__FUNC_I2SOUT_DATA_OUT
value|(MTK_PIN_NO(107) | 6)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_107_MSDC1_DAT0__FUNC_DBG_MON_B_26
value|(MTK_PIN_NO(107) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_108_MSDC1_DAT1__FUNC_GPIO108
value|(MTK_PIN_NO(108) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_108_MSDC1_DAT1__FUNC_MSDC1_DAT1
value|(MTK_PIN_NO(108) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_108_MSDC1_DAT1__FUNC_ANT_SEL3
value|(MTK_PIN_NO(108) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_108_MSDC1_DAT1__FUNC_PWM0
value|(MTK_PIN_NO(108) | 3)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_108_MSDC1_DAT1__FUNC_URXD0
value|(MTK_PIN_NO(108) | 5)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_108_MSDC1_DAT1__FUNC_PWM1
value|(MTK_PIN_NO(108) | 6)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_108_MSDC1_DAT1__FUNC_DBG_MON_B_25
value|(MTK_PIN_NO(108) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_109_MSDC1_DAT2__FUNC_GPIO109
value|(MTK_PIN_NO(109) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_109_MSDC1_DAT2__FUNC_MSDC1_DAT2
value|(MTK_PIN_NO(109) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_109_MSDC1_DAT2__FUNC_ANT_SEL4
value|(MTK_PIN_NO(109) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_109_MSDC1_DAT2__FUNC_SDA2
value|(MTK_PIN_NO(109) | 3)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_109_MSDC1_DAT2__FUNC_UTXD1
value|(MTK_PIN_NO(109) | 5)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_109_MSDC1_DAT2__FUNC_PWM2
value|(MTK_PIN_NO(109) | 6)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_109_MSDC1_DAT2__FUNC_DBG_MON_B_24
value|(MTK_PIN_NO(109) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_110_MSDC1_DAT3__FUNC_GPIO110
value|(MTK_PIN_NO(110) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_110_MSDC1_DAT3__FUNC_MSDC1_DAT3
value|(MTK_PIN_NO(110) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_110_MSDC1_DAT3__FUNC_ANT_SEL5
value|(MTK_PIN_NO(110) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_110_MSDC1_DAT3__FUNC_SCL2
value|(MTK_PIN_NO(110) | 3)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_110_MSDC1_DAT3__FUNC_EXT_FRAME_SYNC
value|(MTK_PIN_NO(110) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_110_MSDC1_DAT3__FUNC_URXD1
value|(MTK_PIN_NO(110) | 5)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_110_MSDC1_DAT3__FUNC_PWM3
value|(MTK_PIN_NO(110) | 6)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_110_MSDC1_DAT3__FUNC_DBG_MON_B_23
value|(MTK_PIN_NO(110) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_111_MSDC0_DAT7__FUNC_GPIO111
value|(MTK_PIN_NO(111) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_111_MSDC0_DAT7__FUNC_MSDC0_DAT7
value|(MTK_PIN_NO(111) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_111_MSDC0_DAT7__FUNC_NLD7
value|(MTK_PIN_NO(111) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_112_MSDC0_DAT6__FUNC_GPIO112
value|(MTK_PIN_NO(112) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_112_MSDC0_DAT6__FUNC_MSDC0_DAT6
value|(MTK_PIN_NO(112) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_112_MSDC0_DAT6__FUNC_NLD6
value|(MTK_PIN_NO(112) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_113_MSDC0_DAT5__FUNC_GPIO113
value|(MTK_PIN_NO(113) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_113_MSDC0_DAT5__FUNC_MSDC0_DAT5
value|(MTK_PIN_NO(113) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_113_MSDC0_DAT5__FUNC_NLD5
value|(MTK_PIN_NO(113) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_114_MSDC0_DAT4__FUNC_GPIO114
value|(MTK_PIN_NO(114) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_114_MSDC0_DAT4__FUNC_MSDC0_DAT4
value|(MTK_PIN_NO(114) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_114_MSDC0_DAT4__FUNC_NLD4
value|(MTK_PIN_NO(114) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_115_MSDC0_RSTB__FUNC_GPIO115
value|(MTK_PIN_NO(115) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_115_MSDC0_RSTB__FUNC_MSDC0_RSTB
value|(MTK_PIN_NO(115) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_115_MSDC0_RSTB__FUNC_NLD8
value|(MTK_PIN_NO(115) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_116_MSDC0_CMD__FUNC_GPIO116
value|(MTK_PIN_NO(116) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_116_MSDC0_CMD__FUNC_MSDC0_CMD
value|(MTK_PIN_NO(116) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_116_MSDC0_CMD__FUNC_NALE
value|(MTK_PIN_NO(116) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_117_MSDC0_CLK__FUNC_GPIO117
value|(MTK_PIN_NO(117) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_117_MSDC0_CLK__FUNC_MSDC0_CLK
value|(MTK_PIN_NO(117) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_117_MSDC0_CLK__FUNC_NWEB
value|(MTK_PIN_NO(117) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_118_MSDC0_DAT3__FUNC_GPIO118
value|(MTK_PIN_NO(118) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_118_MSDC0_DAT3__FUNC_MSDC0_DAT3
value|(MTK_PIN_NO(118) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_118_MSDC0_DAT3__FUNC_NLD3
value|(MTK_PIN_NO(118) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_119_MSDC0_DAT2__FUNC_GPIO119
value|(MTK_PIN_NO(119) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_119_MSDC0_DAT2__FUNC_MSDC0_DAT2
value|(MTK_PIN_NO(119) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_119_MSDC0_DAT2__FUNC_NLD2
value|(MTK_PIN_NO(119) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_120_MSDC0_DAT1__FUNC_GPIO120
value|(MTK_PIN_NO(120) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_120_MSDC0_DAT1__FUNC_MSDC0_DAT1
value|(MTK_PIN_NO(120) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_120_MSDC0_DAT1__FUNC_NLD1
value|(MTK_PIN_NO(120) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_121_MSDC0_DAT0__FUNC_GPIO121
value|(MTK_PIN_NO(121) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_121_MSDC0_DAT0__FUNC_MSDC0_DAT0
value|(MTK_PIN_NO(121) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_121_MSDC0_DAT0__FUNC_NLD0
value|(MTK_PIN_NO(121) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_121_MSDC0_DAT0__FUNC_WATCHDOG
value|(MTK_PIN_NO(121) | 5)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_122_CEC__FUNC_GPIO122
value|(MTK_PIN_NO(122) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_122_CEC__FUNC_CEC
value|(MTK_PIN_NO(122) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_122_CEC__FUNC_SDA2
value|(MTK_PIN_NO(122) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_122_CEC__FUNC_URXD0
value|(MTK_PIN_NO(122) | 5)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_123_HTPLG__FUNC_GPIO123
value|(MTK_PIN_NO(123) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_123_HTPLG__FUNC_HTPLG
value|(MTK_PIN_NO(123) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_123_HTPLG__FUNC_SCL2
value|(MTK_PIN_NO(123) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_123_HTPLG__FUNC_UTXD0
value|(MTK_PIN_NO(123) | 5)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_124_HDMISCK__FUNC_GPIO124
value|(MTK_PIN_NO(124) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_124_HDMISCK__FUNC_HDMISCK
value|(MTK_PIN_NO(124) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_124_HDMISCK__FUNC_SDA1
value|(MTK_PIN_NO(124) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_124_HDMISCK__FUNC_PWM3
value|(MTK_PIN_NO(124) | 5)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_125_HDMISD__FUNC_GPIO125
value|(MTK_PIN_NO(125) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_125_HDMISD__FUNC_HDMISD
value|(MTK_PIN_NO(125) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_125_HDMISD__FUNC_SCL1
value|(MTK_PIN_NO(125) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_125_HDMISD__FUNC_PWM4
value|(MTK_PIN_NO(125) | 5)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_126_I2S0_MCLK__FUNC_GPIO126
value|(MTK_PIN_NO(126) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_126_I2S0_MCLK__FUNC_I2S0_MCLK
value|(MTK_PIN_NO(126) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_126_I2S0_MCLK__FUNC_WCN_I2S_MCLK
value|(MTK_PIN_NO(126) | 6)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_126_I2S0_MCLK__FUNC_DBG_MON_B_6
value|(MTK_PIN_NO(126) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_199_SPI1_CLK__FUNC_GPIO199
value|(MTK_PIN_NO(199) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_199_SPI1_CLK__FUNC_SPI1_CK
value|(MTK_PIN_NO(199) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_199_SPI1_CLK__FUNC_EXT_FRAME_SYNC
value|(MTK_PIN_NO(199) | 3)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_199_SPI1_CLK__FUNC_KCOL3
value|(MTK_PIN_NO(199) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_199_SPI1_CLK__FUNC_DBG_MON_B_15
value|(MTK_PIN_NO(199) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_200_SPDIF_OUT__FUNC_GPIO200
value|(MTK_PIN_NO(200) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_200_SPDIF_OUT__FUNC_SPDIF_OUT
value|(MTK_PIN_NO(200) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_200_SPDIF_OUT__FUNC_G1_TXD3
value|(MTK_PIN_NO(200) | 5)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_200_SPDIF_OUT__FUNC_URXD2
value|(MTK_PIN_NO(200) | 6)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_200_SPDIF_OUT__FUNC_DBG_MON_B_16
value|(MTK_PIN_NO(200) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_201_SPDIF_IN0__FUNC_GPIO201
value|(MTK_PIN_NO(201) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_201_SPDIF_IN0__FUNC_SPDIF_IN0
value|(MTK_PIN_NO(201) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_201_SPDIF_IN0__FUNC_G1_TXEN
value|(MTK_PIN_NO(201) | 5)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_201_SPDIF_IN0__FUNC_UTXD2
value|(MTK_PIN_NO(201) | 6)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_201_SPDIF_IN0__FUNC_DBG_MON_B_17
value|(MTK_PIN_NO(201) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_202_SPDIF_IN1__FUNC_GPIO202
value|(MTK_PIN_NO(202) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_202_SPDIF_IN1__FUNC_SPDIF_IN1
value|(MTK_PIN_NO(202) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_203_PWM0__FUNC_GPIO203
value|(MTK_PIN_NO(203) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_203_PWM0__FUNC_PWM0
value|(MTK_PIN_NO(203) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_203_PWM0__FUNC_DISP_PWM
value|(MTK_PIN_NO(203) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_203_PWM0__FUNC_G1_TXD2
value|(MTK_PIN_NO(203) | 5)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_203_PWM0__FUNC_DBG_MON_B_18
value|(MTK_PIN_NO(203) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_203_PWM0__FUNC_I2S2_DATA
value|(MTK_PIN_NO(203) | 9)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_204_PWM1__FUNC_GPIO204
value|(MTK_PIN_NO(204) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_204_PWM1__FUNC_PWM1
value|(MTK_PIN_NO(204) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_204_PWM1__FUNC_CLKM3
value|(MTK_PIN_NO(204) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_204_PWM1__FUNC_G1_TXD1
value|(MTK_PIN_NO(204) | 5)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_204_PWM1__FUNC_DBG_MON_B_19
value|(MTK_PIN_NO(204) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_204_PWM1__FUNC_I2S3_DATA
value|(MTK_PIN_NO(204) | 9)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_205_PWM2__FUNC_GPIO205
value|(MTK_PIN_NO(205) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_205_PWM2__FUNC_PWM2
value|(MTK_PIN_NO(205) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_205_PWM2__FUNC_CLKM2
value|(MTK_PIN_NO(205) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_205_PWM2__FUNC_G1_TXD0
value|(MTK_PIN_NO(205) | 5)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_205_PWM2__FUNC_DBG_MON_B_20
value|(MTK_PIN_NO(205) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_206_PWM3__FUNC_GPIO206
value|(MTK_PIN_NO(206) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_206_PWM3__FUNC_PWM3
value|(MTK_PIN_NO(206) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_206_PWM3__FUNC_CLKM1
value|(MTK_PIN_NO(206) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_206_PWM3__FUNC_EXT_FRAME_SYNC
value|(MTK_PIN_NO(206) | 3)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_206_PWM3__FUNC_G1_TXC
value|(MTK_PIN_NO(206) | 5)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_206_PWM3__FUNC_DBG_MON_B_21
value|(MTK_PIN_NO(206) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_207_PWM4__FUNC_GPIO207
value|(MTK_PIN_NO(207) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_207_PWM4__FUNC_PWM4
value|(MTK_PIN_NO(207) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_207_PWM4__FUNC_CLKM0
value|(MTK_PIN_NO(207) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_207_PWM4__FUNC_EXT_FRAME_SYNC
value|(MTK_PIN_NO(207) | 3)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_207_PWM4__FUNC_G1_RXC
value|(MTK_PIN_NO(207) | 5)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_207_PWM4__FUNC_DBG_MON_B_22
value|(MTK_PIN_NO(207) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_208_AUD_EXT_CK1__FUNC_GPIO208
value|(MTK_PIN_NO(208) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_208_AUD_EXT_CK1__FUNC_AUD_EXT_CK1
value|(MTK_PIN_NO(208) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_208_AUD_EXT_CK1__FUNC_PWM0
value|(MTK_PIN_NO(208) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_208_AUD_EXT_CK1__FUNC_ANT_SEL5
value|(MTK_PIN_NO(208) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_208_AUD_EXT_CK1__FUNC_DISP_PWM
value|(MTK_PIN_NO(208) | 5)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_208_AUD_EXT_CK1__FUNC_DBG_MON_A_31
value|(MTK_PIN_NO(208) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_208_AUD_EXT_CK1__FUNC_PCIE0_PERST_N
value|(MTK_PIN_NO(208) | 11)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_209_AUD_EXT_CK2__FUNC_GPIO209
value|(MTK_PIN_NO(209) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_209_AUD_EXT_CK2__FUNC_AUD_EXT_CK2
value|(MTK_PIN_NO(209) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_209_AUD_EXT_CK2__FUNC_MSDC1_WP
value|(MTK_PIN_NO(209) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_209_AUD_EXT_CK2__FUNC_PWM1
value|(MTK_PIN_NO(209) | 5)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_209_AUD_EXT_CK2__FUNC_DBG_MON_A_32
value|(MTK_PIN_NO(209) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_209_AUD_EXT_CK2__FUNC_PCIE1_PERST_N
value|(MTK_PIN_NO(209) | 11)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_236_EXT_SDIO3__FUNC_GPIO236
value|(MTK_PIN_NO(236) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_236_EXT_SDIO3__FUNC_EXT_SDIO3
value|(MTK_PIN_NO(236) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_236_EXT_SDIO3__FUNC_IDDIG
value|(MTK_PIN_NO(236) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_236_EXT_SDIO3__FUNC_DBG_MON_A_1
value|(MTK_PIN_NO(236) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_237_EXT_SDIO2__FUNC_GPIO237
value|(MTK_PIN_NO(237) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_237_EXT_SDIO2__FUNC_EXT_SDIO2
value|(MTK_PIN_NO(237) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_237_EXT_SDIO2__FUNC_DRV_VBUS
value|(MTK_PIN_NO(237) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_238_EXT_SDIO1__FUNC_GPIO238
value|(MTK_PIN_NO(238) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_238_EXT_SDIO1__FUNC_EXT_SDIO1
value|(MTK_PIN_NO(238) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_238_EXT_SDIO1__FUNC_IDDIG_P1
value|(MTK_PIN_NO(238) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_239_EXT_SDIO0__FUNC_GPIO239
value|(MTK_PIN_NO(239) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_239_EXT_SDIO0__FUNC_EXT_SDIO0
value|(MTK_PIN_NO(239) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_239_EXT_SDIO0__FUNC_DRV_VBUS_P1
value|(MTK_PIN_NO(239) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_240_EXT_XCS__FUNC_GPIO240
value|(MTK_PIN_NO(240) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_240_EXT_XCS__FUNC_EXT_XCS
value|(MTK_PIN_NO(240) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_241_EXT_SCK__FUNC_GPIO241
value|(MTK_PIN_NO(241) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_241_EXT_SCK__FUNC_EXT_SCK
value|(MTK_PIN_NO(241) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_242_URTS2__FUNC_GPIO242
value|(MTK_PIN_NO(242) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_242_URTS2__FUNC_URTS2
value|(MTK_PIN_NO(242) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_242_URTS2__FUNC_UTXD3
value|(MTK_PIN_NO(242) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_242_URTS2__FUNC_URXD3
value|(MTK_PIN_NO(242) | 3)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_242_URTS2__FUNC_SCL1
value|(MTK_PIN_NO(242) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_242_URTS2__FUNC_DBG_MON_B_32
value|(MTK_PIN_NO(242) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_243_UCTS2__FUNC_GPIO243
value|(MTK_PIN_NO(243) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_243_UCTS2__FUNC_UCTS2
value|(MTK_PIN_NO(243) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_243_UCTS2__FUNC_URXD3
value|(MTK_PIN_NO(243) | 2)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_243_UCTS2__FUNC_UTXD3
value|(MTK_PIN_NO(243) | 3)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_243_UCTS2__FUNC_SDA1
value|(MTK_PIN_NO(243) | 4)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_243_UCTS2__FUNC_DBG_MON_A_6
value|(MTK_PIN_NO(243) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_244_HDMI_SDA_RX__FUNC_GPIO244
value|(MTK_PIN_NO(244) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_244_HDMI_SDA_RX__FUNC_HDMI_SDA_RX
value|(MTK_PIN_NO(244) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_245_HDMI_SCL_RX__FUNC_GPIO245
value|(MTK_PIN_NO(245) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_245_HDMI_SCL_RX__FUNC_HDMI_SCL_RX
value|(MTK_PIN_NO(245) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_246_MHL_SENCE__FUNC_GPIO246
value|(MTK_PIN_NO(246) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_247_HDMI_HPD_CBUS_RX__FUNC_GPIO247
value|(MTK_PIN_NO(247) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_247_HDMI_HPD_CBUS_RX__FUNC_HDMI_HPD_RX
value|(MTK_PIN_NO(247) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_248_HDMI_TESTOUTP_RX__FUNC_GPIO248
value|(MTK_PIN_NO(248) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_248_HDMI_TESTOUTP_RX__FUNC_HDMI_TESTOUTP_RX
value|(MTK_PIN_NO(248) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_249_MSDC0E_RSTB__FUNC_MSDC0E_RSTB
value|(MTK_PIN_NO(249) | 9)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_250_MSDC0E_DAT7__FUNC_MSDC3_DAT7
value|(MTK_PIN_NO(250) | 9)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_250_MSDC0E_DAT7__FUNC_PCIE0_CLKREQ_N
value|(MTK_PIN_NO(250) | 14)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_251_MSDC0E_DAT6__FUNC_MSDC3_DAT6
value|(MTK_PIN_NO(251) | 9)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_251_MSDC0E_DAT6__FUNC_PCIE0_WAKE_N
value|(MTK_PIN_NO(251) | 14)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_252_MSDC0E_DAT5__FUNC_MSDC3_DAT5
value|(MTK_PIN_NO(252) | 9)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_252_MSDC0E_DAT5__FUNC_PCIE1_CLKREQ_N
value|(MTK_PIN_NO(252) | 14)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_253_MSDC0E_DAT4__FUNC_MSDC3_DAT4
value|(MTK_PIN_NO(253) | 9)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_253_MSDC0E_DAT4__FUNC_PCIE1_WAKE_N
value|(MTK_PIN_NO(253) | 14)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_254_MSDC0E_DAT3__FUNC_MSDC3_DAT3
value|(MTK_PIN_NO(254) | 9)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_254_MSDC0E_DAT3__FUNC_PCIE2_CLKREQ_N
value|(MTK_PIN_NO(254) | 14)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_255_MSDC0E_DAT2__FUNC_MSDC3_DAT2
value|(MTK_PIN_NO(255) | 9)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_255_MSDC0E_DAT2__FUNC_PCIE2_WAKE_N
value|(MTK_PIN_NO(255) | 14)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_256_MSDC0E_DAT1__FUNC_MSDC3_DAT1
value|(MTK_PIN_NO(256) | 9)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_257_MSDC0E_DAT0__FUNC_MSDC3_DAT0
value|(MTK_PIN_NO(257) | 9)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_258_MSDC0E_CMD__FUNC_MSDC3_CMD
value|(MTK_PIN_NO(258) | 9)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_259_MSDC0E_CLK__FUNC_MSDC3_CLK
value|(MTK_PIN_NO(259) | 9)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_260_MSDC0E_DSL__FUNC_MSDC3_DSL
value|(MTK_PIN_NO(260) | 9)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_261_MSDC1_INS__FUNC_GPIO261
value|(MTK_PIN_NO(261) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_261_MSDC1_INS__FUNC_MSDC1_INS
value|(MTK_PIN_NO(261) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_261_MSDC1_INS__FUNC_DBG_MON_B_29
value|(MTK_PIN_NO(261) | 7)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_262_G2_TXEN__FUNC_GPIO262
value|(MTK_PIN_NO(262) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_262_G2_TXEN__FUNC_G2_TXEN
value|(MTK_PIN_NO(262) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_263_G2_TXD3__FUNC_GPIO263
value|(MTK_PIN_NO(263) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_263_G2_TXD3__FUNC_G2_TXD3
value|(MTK_PIN_NO(263) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_263_G2_TXD3__FUNC_ANT_SEL5
value|(MTK_PIN_NO(263) | 6)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_264_G2_TXD2__FUNC_GPIO264
value|(MTK_PIN_NO(264) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_264_G2_TXD2__FUNC_G2_TXD2
value|(MTK_PIN_NO(264) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_264_G2_TXD2__FUNC_ANT_SEL4
value|(MTK_PIN_NO(264) | 6)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_265_G2_TXD1__FUNC_GPIO265
value|(MTK_PIN_NO(265) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_265_G2_TXD1__FUNC_G2_TXD1
value|(MTK_PIN_NO(265) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_265_G2_TXD1__FUNC_ANT_SEL3
value|(MTK_PIN_NO(265) | 6)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_266_G2_TXD0__FUNC_GPIO266
value|(MTK_PIN_NO(266) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_266_G2_TXD0__FUNC_G2_TXD0
value|(MTK_PIN_NO(266) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_266_G2_TXD0__FUNC_ANT_SEL2
value|(MTK_PIN_NO(266) | 6)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_267_G2_TXC__FUNC_GPIO267
value|(MTK_PIN_NO(267) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_267_G2_TXC__FUNC_G2_TXC
value|(MTK_PIN_NO(267) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_268_G2_RXC__FUNC_GPIO268
value|(MTK_PIN_NO(268) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_268_G2_RXC__FUNC_G2_RXC
value|(MTK_PIN_NO(268) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_269_G2_RXD0__FUNC_GPIO269
value|(MTK_PIN_NO(269) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_269_G2_RXD0__FUNC_G2_RXD0
value|(MTK_PIN_NO(269) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_270_G2_RXD1__FUNC_GPIO270
value|(MTK_PIN_NO(270) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_270_G2_RXD1__FUNC_G2_RXD1
value|(MTK_PIN_NO(270) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_271_G2_RXD2__FUNC_GPIO271
value|(MTK_PIN_NO(271) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_271_G2_RXD2__FUNC_G2_RXD2
value|(MTK_PIN_NO(271) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_272_G2_RXD3__FUNC_GPIO272
value|(MTK_PIN_NO(272) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_272_G2_RXD3__FUNC_G2_RXD3
value|(MTK_PIN_NO(272) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_274_G2_RXDV__FUNC_GPIO274
value|(MTK_PIN_NO(274) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_274_G2_RXDV__FUNC_G2_RXDV
value|(MTK_PIN_NO(274) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_275_MDC__FUNC_GPIO275
value|(MTK_PIN_NO(275) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_275_MDC__FUNC_MDC
value|(MTK_PIN_NO(275) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_275_MDC__FUNC_ANT_SEL0
value|(MTK_PIN_NO(275) | 6)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_276_MDIO__FUNC_GPIO276
value|(MTK_PIN_NO(276) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_276_MDIO__FUNC_MDIO
value|(MTK_PIN_NO(276) | 1)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_276_MDIO__FUNC_ANT_SEL1
value|(MTK_PIN_NO(276) | 6)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_278_JTAG_RESET__FUNC_GPIO278
value|(MTK_PIN_NO(278) | 0)
end_define

begin_define
define|#
directive|define
name|MT2701_PIN_278_JTAG_RESET__FUNC_JTAG_RESET
value|(MTK_PIN_NO(278) | 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DTS_MT2701_PINFUNC_H */
end_comment

end_unit

