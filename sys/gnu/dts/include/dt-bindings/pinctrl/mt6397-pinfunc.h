begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SPDX-License-Identifier: GPL-2.0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DTS_MT6397_PINFUNC_H
end_ifndef

begin_define
define|#
directive|define
name|__DTS_MT6397_PINFUNC_H
end_define

begin_include
include|#
directive|include
file|<dt-bindings/pinctrl/mt65xx.h>
end_include

begin_define
define|#
directive|define
name|MT6397_PIN_0_INT__FUNC_GPIO0
value|(MTK_PIN_NO(0) | 0)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_0_INT__FUNC_INT
value|(MTK_PIN_NO(0) | 1)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_1_SRCVOLTEN__FUNC_GPIO1
value|(MTK_PIN_NO(1) | 0)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_1_SRCVOLTEN__FUNC_SRCVOLTEN
value|(MTK_PIN_NO(1) | 1)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_1_SRCVOLTEN__FUNC_TEST_CK1
value|(MTK_PIN_NO(1) | 6)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_2_SRCLKEN_PERI__FUNC_GPIO2
value|(MTK_PIN_NO(2) | 0)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_2_SRCLKEN_PERI__FUNC_SRCLKEN_PERI
value|(MTK_PIN_NO(2) | 1)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_2_SRCLKEN_PERI__FUNC_TEST_CK2
value|(MTK_PIN_NO(2) | 6)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_3_RTC_32K1V8__FUNC_GPIO3
value|(MTK_PIN_NO(3) | 0)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_3_RTC_32K1V8__FUNC_RTC_32K1V8
value|(MTK_PIN_NO(3) | 1)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_3_RTC_32K1V8__FUNC_TEST_CK3
value|(MTK_PIN_NO(3) | 6)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_4_WRAP_EVENT__FUNC_GPIO4
value|(MTK_PIN_NO(4) | 0)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_4_WRAP_EVENT__FUNC_WRAP_EVENT
value|(MTK_PIN_NO(4) | 1)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_5_SPI_CLK__FUNC_GPIO5
value|(MTK_PIN_NO(5) | 0)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_5_SPI_CLK__FUNC_SPI_CLK
value|(MTK_PIN_NO(5) | 1)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_6_SPI_CSN__FUNC_GPIO6
value|(MTK_PIN_NO(6) | 0)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_6_SPI_CSN__FUNC_SPI_CSN
value|(MTK_PIN_NO(6) | 1)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_7_SPI_MOSI__FUNC_GPIO7
value|(MTK_PIN_NO(7) | 0)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_7_SPI_MOSI__FUNC_SPI_MOSI
value|(MTK_PIN_NO(7) | 1)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_8_SPI_MISO__FUNC_GPIO8
value|(MTK_PIN_NO(8) | 0)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_8_SPI_MISO__FUNC_SPI_MISO
value|(MTK_PIN_NO(8) | 1)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_9_AUD_CLK_MOSI__FUNC_GPIO9
value|(MTK_PIN_NO(9) | 0)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_9_AUD_CLK_MOSI__FUNC_AUD_CLK
value|(MTK_PIN_NO(9) | 1)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_9_AUD_CLK_MOSI__FUNC_TEST_IN0
value|(MTK_PIN_NO(9) | 6)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_9_AUD_CLK_MOSI__FUNC_TEST_OUT0
value|(MTK_PIN_NO(9) | 7)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_10_AUD_DAT_MISO__FUNC_GPIO10
value|(MTK_PIN_NO(10) | 0)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_10_AUD_DAT_MISO__FUNC_AUD_MISO
value|(MTK_PIN_NO(10) | 1)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_10_AUD_DAT_MISO__FUNC_TEST_IN1
value|(MTK_PIN_NO(10) | 6)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_10_AUD_DAT_MISO__FUNC_TEST_OUT1
value|(MTK_PIN_NO(10) | 7)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_11_AUD_DAT_MOSI__FUNC_GPIO11
value|(MTK_PIN_NO(11) | 0)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_11_AUD_DAT_MOSI__FUNC_AUD_MOSI
value|(MTK_PIN_NO(11) | 1)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_11_AUD_DAT_MOSI__FUNC_TEST_IN2
value|(MTK_PIN_NO(11) | 6)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_11_AUD_DAT_MOSI__FUNC_TEST_OUT2
value|(MTK_PIN_NO(11) | 7)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_12_COL0__FUNC_GPIO12
value|(MTK_PIN_NO(12) | 0)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_12_COL0__FUNC_COL0_USBDL
value|(MTK_PIN_NO(12) | 1)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_12_COL0__FUNC_EINT10_1X
value|(MTK_PIN_NO(12) | 2)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_12_COL0__FUNC_PWM1_3X
value|(MTK_PIN_NO(12) | 3)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_12_COL0__FUNC_TEST_IN3
value|(MTK_PIN_NO(12) | 6)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_12_COL0__FUNC_TEST_OUT3
value|(MTK_PIN_NO(12) | 7)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_13_COL1__FUNC_GPIO13
value|(MTK_PIN_NO(13) | 0)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_13_COL1__FUNC_COL1
value|(MTK_PIN_NO(13) | 1)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_13_COL1__FUNC_EINT11_1X
value|(MTK_PIN_NO(13) | 2)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_13_COL1__FUNC_SCL0_2X
value|(MTK_PIN_NO(13) | 3)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_13_COL1__FUNC_TEST_IN4
value|(MTK_PIN_NO(13) | 6)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_13_COL1__FUNC_TEST_OUT4
value|(MTK_PIN_NO(13) | 7)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_14_COL2__FUNC_GPIO14
value|(MTK_PIN_NO(14) | 0)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_14_COL2__FUNC_COL2
value|(MTK_PIN_NO(14) | 1)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_14_COL2__FUNC_EINT12_1X
value|(MTK_PIN_NO(14) | 2)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_14_COL2__FUNC_SDA0_2X
value|(MTK_PIN_NO(14) | 3)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_14_COL2__FUNC_TEST_IN5
value|(MTK_PIN_NO(14) | 6)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_14_COL2__FUNC_TEST_OUT5
value|(MTK_PIN_NO(14) | 7)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_15_COL3__FUNC_GPIO15
value|(MTK_PIN_NO(15) | 0)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_15_COL3__FUNC_COL3
value|(MTK_PIN_NO(15) | 1)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_15_COL3__FUNC_EINT13_1X
value|(MTK_PIN_NO(15) | 2)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_15_COL3__FUNC_SCL1_2X
value|(MTK_PIN_NO(15) | 3)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_15_COL3__FUNC_TEST_IN6
value|(MTK_PIN_NO(15) | 6)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_15_COL3__FUNC_TEST_OUT6
value|(MTK_PIN_NO(15) | 7)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_16_COL4__FUNC_GPIO16
value|(MTK_PIN_NO(16) | 0)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_16_COL4__FUNC_COL4
value|(MTK_PIN_NO(16) | 1)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_16_COL4__FUNC_EINT14_1X
value|(MTK_PIN_NO(16) | 2)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_16_COL4__FUNC_SDA1_2X
value|(MTK_PIN_NO(16) | 3)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_16_COL4__FUNC_TEST_IN7
value|(MTK_PIN_NO(16) | 6)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_16_COL4__FUNC_TEST_OUT7
value|(MTK_PIN_NO(16) | 7)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_17_COL5__FUNC_GPIO17
value|(MTK_PIN_NO(17) | 0)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_17_COL5__FUNC_COL5
value|(MTK_PIN_NO(17) | 1)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_17_COL5__FUNC_EINT15_1X
value|(MTK_PIN_NO(17) | 2)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_17_COL5__FUNC_SCL2_2X
value|(MTK_PIN_NO(17) | 3)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_17_COL5__FUNC_TEST_IN8
value|(MTK_PIN_NO(17) | 6)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_17_COL5__FUNC_TEST_OUT8
value|(MTK_PIN_NO(17) | 7)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_18_COL6__FUNC_GPIO18
value|(MTK_PIN_NO(18) | 0)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_18_COL6__FUNC_COL6
value|(MTK_PIN_NO(18) | 1)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_18_COL6__FUNC_EINT16_1X
value|(MTK_PIN_NO(18) | 2)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_18_COL6__FUNC_SDA2_2X
value|(MTK_PIN_NO(18) | 3)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_18_COL6__FUNC_GPIO32K_0
value|(MTK_PIN_NO(18) | 4)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_18_COL6__FUNC_GPIO26M_0
value|(MTK_PIN_NO(18) | 5)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_18_COL6__FUNC_TEST_IN9
value|(MTK_PIN_NO(18) | 6)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_18_COL6__FUNC_TEST_OUT9
value|(MTK_PIN_NO(18) | 7)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_19_COL7__FUNC_GPIO19
value|(MTK_PIN_NO(19) | 0)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_19_COL7__FUNC_COL7
value|(MTK_PIN_NO(19) | 1)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_19_COL7__FUNC_EINT17_1X
value|(MTK_PIN_NO(19) | 2)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_19_COL7__FUNC_PWM2_3X
value|(MTK_PIN_NO(19) | 3)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_19_COL7__FUNC_GPIO32K_1
value|(MTK_PIN_NO(19) | 4)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_19_COL7__FUNC_GPIO26M_1
value|(MTK_PIN_NO(19) | 5)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_19_COL7__FUNC_TEST_IN10
value|(MTK_PIN_NO(19) | 6)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_19_COL7__FUNC_TEST_OUT10
value|(MTK_PIN_NO(19) | 7)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_20_ROW0__FUNC_GPIO20
value|(MTK_PIN_NO(20) | 0)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_20_ROW0__FUNC_ROW0
value|(MTK_PIN_NO(20) | 1)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_20_ROW0__FUNC_EINT18_1X
value|(MTK_PIN_NO(20) | 2)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_20_ROW0__FUNC_SCL0_3X
value|(MTK_PIN_NO(20) | 3)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_20_ROW0__FUNC_TEST_IN11
value|(MTK_PIN_NO(20) | 6)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_20_ROW0__FUNC_TEST_OUT11
value|(MTK_PIN_NO(20) | 7)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_21_ROW1__FUNC_GPIO21
value|(MTK_PIN_NO(21) | 0)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_21_ROW1__FUNC_ROW1
value|(MTK_PIN_NO(21) | 1)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_21_ROW1__FUNC_EINT19_1X
value|(MTK_PIN_NO(21) | 2)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_21_ROW1__FUNC_SDA0_3X
value|(MTK_PIN_NO(21) | 3)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_21_ROW1__FUNC_AUD_TSTCK
value|(MTK_PIN_NO(21) | 4)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_21_ROW1__FUNC_TEST_IN12
value|(MTK_PIN_NO(21) | 6)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_21_ROW1__FUNC_TEST_OUT12
value|(MTK_PIN_NO(21) | 7)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_22_ROW2__FUNC_GPIO22
value|(MTK_PIN_NO(22) | 0)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_22_ROW2__FUNC_ROW2
value|(MTK_PIN_NO(22) | 1)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_22_ROW2__FUNC_EINT20_1X
value|(MTK_PIN_NO(22) | 2)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_22_ROW2__FUNC_SCL1_3X
value|(MTK_PIN_NO(22) | 3)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_22_ROW2__FUNC_TEST_IN13
value|(MTK_PIN_NO(22) | 6)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_22_ROW2__FUNC_TEST_OUT13
value|(MTK_PIN_NO(22) | 7)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_23_ROW3__FUNC_GPIO23
value|(MTK_PIN_NO(23) | 0)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_23_ROW3__FUNC_ROW3
value|(MTK_PIN_NO(23) | 1)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_23_ROW3__FUNC_EINT21_1X
value|(MTK_PIN_NO(23) | 2)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_23_ROW3__FUNC_SDA1_3X
value|(MTK_PIN_NO(23) | 3)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_23_ROW3__FUNC_TEST_IN14
value|(MTK_PIN_NO(23) | 6)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_23_ROW3__FUNC_TEST_OUT14
value|(MTK_PIN_NO(23) | 7)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_24_ROW4__FUNC_GPIO24
value|(MTK_PIN_NO(24) | 0)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_24_ROW4__FUNC_ROW4
value|(MTK_PIN_NO(24) | 1)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_24_ROW4__FUNC_EINT22_1X
value|(MTK_PIN_NO(24) | 2)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_24_ROW4__FUNC_SCL2_3X
value|(MTK_PIN_NO(24) | 3)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_24_ROW4__FUNC_TEST_IN15
value|(MTK_PIN_NO(24) | 6)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_24_ROW4__FUNC_TEST_OUT15
value|(MTK_PIN_NO(24) | 7)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_25_ROW5__FUNC_GPIO25
value|(MTK_PIN_NO(25) | 0)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_25_ROW5__FUNC_ROW5
value|(MTK_PIN_NO(25) | 1)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_25_ROW5__FUNC_EINT23_1X
value|(MTK_PIN_NO(25) | 2)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_25_ROW5__FUNC_SDA2_3X
value|(MTK_PIN_NO(25) | 3)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_25_ROW5__FUNC_TEST_IN16
value|(MTK_PIN_NO(25) | 6)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_25_ROW5__FUNC_TEST_OUT16
value|(MTK_PIN_NO(25) | 7)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_26_ROW6__FUNC_GPIO26
value|(MTK_PIN_NO(26) | 0)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_26_ROW6__FUNC_ROW6
value|(MTK_PIN_NO(26) | 1)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_26_ROW6__FUNC_EINT24_1X
value|(MTK_PIN_NO(26) | 2)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_26_ROW6__FUNC_PWM3_3X
value|(MTK_PIN_NO(26) | 3)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_26_ROW6__FUNC_GPIO32K_2
value|(MTK_PIN_NO(26) | 4)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_26_ROW6__FUNC_GPIO26M_2
value|(MTK_PIN_NO(26) | 5)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_26_ROW6__FUNC_TEST_IN17
value|(MTK_PIN_NO(26) | 6)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_26_ROW6__FUNC_TEST_OUT17
value|(MTK_PIN_NO(26) | 7)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_27_ROW7__FUNC_GPIO27
value|(MTK_PIN_NO(27) | 0)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_27_ROW7__FUNC_ROW7
value|(MTK_PIN_NO(27) | 1)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_27_ROW7__FUNC_EINT3_1X
value|(MTK_PIN_NO(27) | 2)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_27_ROW7__FUNC_CBUS
value|(MTK_PIN_NO(27) | 3)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_27_ROW7__FUNC_GPIO32K_3
value|(MTK_PIN_NO(27) | 4)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_27_ROW7__FUNC_GPIO26M_3
value|(MTK_PIN_NO(27) | 5)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_27_ROW7__FUNC_TEST_IN18
value|(MTK_PIN_NO(27) | 6)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_27_ROW7__FUNC_TEST_OUT18
value|(MTK_PIN_NO(27) | 7)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_28_PWM1__FUNC_GPIO28
value|(MTK_PIN_NO(28) | 0)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_28_PWM1__FUNC_PWM1
value|(MTK_PIN_NO(28) | 1)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_28_PWM1__FUNC_EINT4_1X
value|(MTK_PIN_NO(28) | 2)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_28_PWM1__FUNC_GPIO32K_4
value|(MTK_PIN_NO(28) | 4)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_28_PWM1__FUNC_GPIO26M_4
value|(MTK_PIN_NO(28) | 5)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_28_PWM1__FUNC_TEST_IN19
value|(MTK_PIN_NO(28) | 6)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_28_PWM1__FUNC_TEST_OUT19
value|(MTK_PIN_NO(28) | 7)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_29_PWM2__FUNC_GPIO29
value|(MTK_PIN_NO(29) | 0)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_29_PWM2__FUNC_PWM2
value|(MTK_PIN_NO(29) | 1)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_29_PWM2__FUNC_EINT5_1X
value|(MTK_PIN_NO(29) | 2)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_29_PWM2__FUNC_GPIO32K_5
value|(MTK_PIN_NO(29) | 4)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_29_PWM2__FUNC_GPIO26M_5
value|(MTK_PIN_NO(29) | 5)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_29_PWM2__FUNC_TEST_IN20
value|(MTK_PIN_NO(29) | 6)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_29_PWM2__FUNC_TEST_OUT20
value|(MTK_PIN_NO(29) | 7)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_30_PWM3__FUNC_GPIO30
value|(MTK_PIN_NO(30) | 0)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_30_PWM3__FUNC_PWM3
value|(MTK_PIN_NO(30) | 1)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_30_PWM3__FUNC_EINT6_1X
value|(MTK_PIN_NO(30) | 2)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_30_PWM3__FUNC_COL0
value|(MTK_PIN_NO(30) | 3)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_30_PWM3__FUNC_GPIO32K_6
value|(MTK_PIN_NO(30) | 4)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_30_PWM3__FUNC_GPIO26M_6
value|(MTK_PIN_NO(30) | 5)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_30_PWM3__FUNC_TEST_IN21
value|(MTK_PIN_NO(30) | 6)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_30_PWM3__FUNC_TEST_OUT21
value|(MTK_PIN_NO(30) | 7)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_31_SCL0__FUNC_GPIO31
value|(MTK_PIN_NO(31) | 0)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_31_SCL0__FUNC_SCL0
value|(MTK_PIN_NO(31) | 1)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_31_SCL0__FUNC_EINT7_1X
value|(MTK_PIN_NO(31) | 2)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_31_SCL0__FUNC_PWM1_2X
value|(MTK_PIN_NO(31) | 3)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_31_SCL0__FUNC_TEST_IN22
value|(MTK_PIN_NO(31) | 6)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_31_SCL0__FUNC_TEST_OUT22
value|(MTK_PIN_NO(31) | 7)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_32_SDA0__FUNC_GPIO32
value|(MTK_PIN_NO(32) | 0)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_32_SDA0__FUNC_SDA0
value|(MTK_PIN_NO(32) | 1)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_32_SDA0__FUNC_EINT8_1X
value|(MTK_PIN_NO(32) | 2)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_32_SDA0__FUNC_TEST_IN23
value|(MTK_PIN_NO(32) | 6)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_32_SDA0__FUNC_TEST_OUT23
value|(MTK_PIN_NO(32) | 7)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_33_SCL1__FUNC_GPIO33
value|(MTK_PIN_NO(33) | 0)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_33_SCL1__FUNC_SCL1
value|(MTK_PIN_NO(33) | 1)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_33_SCL1__FUNC_EINT9_1X
value|(MTK_PIN_NO(33) | 2)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_33_SCL1__FUNC_PWM2_2X
value|(MTK_PIN_NO(33) | 3)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_33_SCL1__FUNC_TEST_IN24
value|(MTK_PIN_NO(33) | 6)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_33_SCL1__FUNC_TEST_OUT24
value|(MTK_PIN_NO(33) | 7)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_34_SDA1__FUNC_GPIO34
value|(MTK_PIN_NO(34) | 0)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_34_SDA1__FUNC_SDA1
value|(MTK_PIN_NO(34) | 1)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_34_SDA1__FUNC_EINT0_1X
value|(MTK_PIN_NO(34) | 2)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_34_SDA1__FUNC_TEST_IN25
value|(MTK_PIN_NO(34) | 6)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_34_SDA1__FUNC_TEST_OUT25
value|(MTK_PIN_NO(34) | 7)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_35_SCL2__FUNC_GPIO35
value|(MTK_PIN_NO(35) | 0)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_35_SCL2__FUNC_SCL2
value|(MTK_PIN_NO(35) | 1)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_35_SCL2__FUNC_EINT1_1X
value|(MTK_PIN_NO(35) | 2)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_35_SCL2__FUNC_PWM3_2X
value|(MTK_PIN_NO(35) | 3)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_35_SCL2__FUNC_TEST_IN26
value|(MTK_PIN_NO(35) | 6)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_35_SCL2__FUNC_TEST_OUT26
value|(MTK_PIN_NO(35) | 7)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_36_SDA2__FUNC_GPIO36
value|(MTK_PIN_NO(36) | 0)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_36_SDA2__FUNC_SDA2
value|(MTK_PIN_NO(36) | 1)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_36_SDA2__FUNC_EINT2_1X
value|(MTK_PIN_NO(36) | 2)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_36_SDA2__FUNC_TEST_IN27
value|(MTK_PIN_NO(36) | 6)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_36_SDA2__FUNC_TEST_OUT27
value|(MTK_PIN_NO(36) | 7)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_37_HDMISD__FUNC_GPIO37
value|(MTK_PIN_NO(37) | 0)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_37_HDMISD__FUNC_HDMISD
value|(MTK_PIN_NO(37) | 1)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_37_HDMISD__FUNC_TEST_IN28
value|(MTK_PIN_NO(37) | 6)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_37_HDMISD__FUNC_TEST_OUT28
value|(MTK_PIN_NO(37) | 7)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_38_HDMISCK__FUNC_GPIO38
value|(MTK_PIN_NO(38) | 0)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_38_HDMISCK__FUNC_HDMISCK
value|(MTK_PIN_NO(38) | 1)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_38_HDMISCK__FUNC_TEST_IN29
value|(MTK_PIN_NO(38) | 6)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_38_HDMISCK__FUNC_TEST_OUT29
value|(MTK_PIN_NO(38) | 7)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_39_HTPLG__FUNC_GPIO39
value|(MTK_PIN_NO(39) | 0)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_39_HTPLG__FUNC_HTPLG
value|(MTK_PIN_NO(39) | 1)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_39_HTPLG__FUNC_TEST_IN30
value|(MTK_PIN_NO(39) | 6)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_39_HTPLG__FUNC_TEST_OUT30
value|(MTK_PIN_NO(39) | 7)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_40_CEC__FUNC_GPIO40
value|(MTK_PIN_NO(40) | 0)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_40_CEC__FUNC_CEC
value|(MTK_PIN_NO(40) | 1)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_40_CEC__FUNC_TEST_IN31
value|(MTK_PIN_NO(40) | 6)
end_define

begin_define
define|#
directive|define
name|MT6397_PIN_40_CEC__FUNC_TEST_OUT31
value|(MTK_PIN_NO(40) | 7)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DTS_MT6397_PINFUNC_H */
end_comment

end_unit

