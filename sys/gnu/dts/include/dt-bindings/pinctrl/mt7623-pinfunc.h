begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__DTS_MT7623_PINFUNC_H
end_ifndef

begin_define
define|#
directive|define
name|__DTS_MT7623_PINFUNC_H
end_define

begin_include
include|#
directive|include
file|<dt-bindings/pinctrl/mt65xx.h>
end_include

begin_define
define|#
directive|define
name|MT7623_PIN_0_PWRAP_SPI0_MI_FUNC_GPIO0
value|(MTK_PIN_NO(0) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_0_PWRAP_SPI0_MI_FUNC_PWRAP_SPIDO
value|(MTK_PIN_NO(0) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_0_PWRAP_SPI0_MI_FUNC_PWRAP_SPIDI
value|(MTK_PIN_NO(0) | 2)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_1_PWRAP_SPI0_MO_FUNC_GPIO1
value|(MTK_PIN_NO(1) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_1_PWRAP_SPI0_MO_FUNC_PWRAP_SPIDI
value|(MTK_PIN_NO(1) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_1_PWRAP_SPI0_MO_FUNC_PWRAP_SPIDO
value|(MTK_PIN_NO(1) | 2)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_2_PWRAP_INT_FUNC_GPIO2
value|(MTK_PIN_NO(2) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_2_PWRAP_INT_FUNC_PWRAP_INT
value|(MTK_PIN_NO(2) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_3_PWRAP_SPI0_CK_FUNC_GPIO3
value|(MTK_PIN_NO(3) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_3_PWRAP_SPI0_CK_FUNC_PWRAP_SPICK_I
value|(MTK_PIN_NO(3) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_4_PWRAP_SPI0_CSN_FUNC_GPIO4
value|(MTK_PIN_NO(4) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_4_PWRAP_SPI0_CSN_FUNC_PWRAP_SPICS_B_I
value|(MTK_PIN_NO(4) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_5_PWRAP_SPI0_CK2_FUNC_GPIO5
value|(MTK_PIN_NO(5) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_5_PWRAP_SPI0_CK2_FUNC_PWRAP_SPICK2_I
value|(MTK_PIN_NO(5) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_6_PWRAP_SPI0_CSN2_FUNC_GPIO6
value|(MTK_PIN_NO(6) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_6_PWRAP_SPI0_CSN2_FUNC_PWRAP_SPICS2_B_I
value|(MTK_PIN_NO(6) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_7_SPI1_CSN_FUNC_GPIO7
value|(MTK_PIN_NO(7) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_7_SPI1_CSN_FUNC_SPI1_CS
value|(MTK_PIN_NO(7) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_8_SPI1_MI_FUNC_GPIO8
value|(MTK_PIN_NO(8) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_8_SPI1_MI_FUNC_SPI1_MI
value|(MTK_PIN_NO(8) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_8_SPI1_MI_FUNC_SPI1_MO
value|(MTK_PIN_NO(8) | 2)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_9_SPI1_MO_FUNC_GPIO9
value|(MTK_PIN_NO(9) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_9_SPI1_MO_FUNC_SPI1_MO
value|(MTK_PIN_NO(9) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_9_SPI1_MO_FUNC_SPI1_MI
value|(MTK_PIN_NO(9) | 2)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_10_RTC32K_CK_FUNC_GPIO10
value|(MTK_PIN_NO(10) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_10_RTC32K_CK_FUNC_RTC32K_CK
value|(MTK_PIN_NO(10) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_11_WATCHDOG_FUNC_GPIO11
value|(MTK_PIN_NO(11) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_11_WATCHDOG_FUNC_WATCHDOG
value|(MTK_PIN_NO(11) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_12_SRCLKENA_FUNC_GPIO12
value|(MTK_PIN_NO(12) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_12_SRCLKENA_FUNC_SRCLKENA
value|(MTK_PIN_NO(12) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_13_SRCLKENAI_FUNC_GPIO13
value|(MTK_PIN_NO(13) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_13_SRCLKENAI_FUNC_SRCLKENAI
value|(MTK_PIN_NO(13) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_14_GPIO14_FUNC_GPIO14
value|(MTK_PIN_NO(14) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_14_GPIO14_FUNC_URXD2
value|(MTK_PIN_NO(14) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_14_GPIO14_FUNC_UTXD2
value|(MTK_PIN_NO(14) | 2)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_15_GPIO15_FUNC_GPIO15
value|(MTK_PIN_NO(15) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_15_GPIO15_FUNC_UTXD2
value|(MTK_PIN_NO(15) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_15_GPIO15_FUNC_URXD2
value|(MTK_PIN_NO(15) | 2)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_18_PCM_CLK_FUNC_GPIO18
value|(MTK_PIN_NO(18) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_18_PCM_CLK_FUNC_PCM_CLK0
value|(MTK_PIN_NO(18) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_18_PCM_CLK_FUNC_AP_PCM_CLKO
value|(MTK_PIN_NO(18) | 6)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_19_PCM_SYNC_FUNC_GPIO19
value|(MTK_PIN_NO(19) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_19_PCM_SYNC_FUNC_PCM_SYNC
value|(MTK_PIN_NO(19) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_19_PCM_SYNC_FUNC_AP_PCM_SYNC
value|(MTK_PIN_NO(19) | 6)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_20_PCM_RX_FUNC_GPIO20
value|(MTK_PIN_NO(20) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_20_PCM_RX_FUNC_PCM_RX
value|(MTK_PIN_NO(20) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_20_PCM_RX_FUNC_PCM_TX
value|(MTK_PIN_NO(20) | 4)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_20_PCM_RX_FUNC_AP_PCM_RX
value|(MTK_PIN_NO(20) | 6)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_21_PCM_TX_FUNC_GPIO21
value|(MTK_PIN_NO(21) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_21_PCM_TX_FUNC_PCM_TX
value|(MTK_PIN_NO(21) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_21_PCM_TX_FUNC_PCM_RX
value|(MTK_PIN_NO(21) | 4)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_21_PCM_TX_FUNC_AP_PCM_TX
value|(MTK_PIN_NO(21) | 6)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_22_EINT0_FUNC_GPIO22
value|(MTK_PIN_NO(22) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_22_EINT0_FUNC_UCTS0
value|(MTK_PIN_NO(22) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_22_EINT0_FUNC_PCIE0_PERST_N
value|(MTK_PIN_NO(22) | 2)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_23_EINT1_FUNC_GPIO23
value|(MTK_PIN_NO(23) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_23_EINT1_FUNC_URTS0
value|(MTK_PIN_NO(23) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_23_EINT1_FUNC_PCIE1_PERST_N
value|(MTK_PIN_NO(23) | 2)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_24_EINT2_FUNC_GPIO24
value|(MTK_PIN_NO(24) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_24_EINT2_FUNC_UCTS1
value|(MTK_PIN_NO(24) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_24_EINT2_FUNC_PCIE2_PERST_N
value|(MTK_PIN_NO(24) | 2)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_25_EINT3_FUNC_GPIO25
value|(MTK_PIN_NO(25) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_25_EINT3_FUNC_URTS1
value|(MTK_PIN_NO(25) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_26_EINT4_FUNC_GPIO26
value|(MTK_PIN_NO(26) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_26_EINT4_FUNC_UCTS3
value|(MTK_PIN_NO(26) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_26_EINT4_FUNC_PCIE2_WAKE_N
value|(MTK_PIN_NO(26) | 6)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_27_EINT5_FUNC_GPIO27
value|(MTK_PIN_NO(27) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_27_EINT5_FUNC_URTS3
value|(MTK_PIN_NO(27) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_27_EINT5_FUNC_PCIE1_WAKE_N
value|(MTK_PIN_NO(27) | 6)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_28_EINT6_FUNC_GPIO28
value|(MTK_PIN_NO(28) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_28_EINT6_FUNC_DRV_VBUS
value|(MTK_PIN_NO(28) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_28_EINT6_FUNC_PCIE0_WAKE_N
value|(MTK_PIN_NO(28) | 6)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_29_EINT7_FUNC_GPIO29
value|(MTK_PIN_NO(29) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_29_EINT7_FUNC_IDDIG
value|(MTK_PIN_NO(29) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_29_EINT7_FUNC_MSDC1_WP
value|(MTK_PIN_NO(29) | 2)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_29_EINT7_FUNC_PCIE2_PERST_N
value|(MTK_PIN_NO(29) | 6)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_33_I2S1_DATA_FUNC_GPIO33
value|(MTK_PIN_NO(33) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_33_I2S1_DATA_FUNC_I2S1_DATA
value|(MTK_PIN_NO(33) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_33_I2S1_DATA_FUNC_PCM_TX
value|(MTK_PIN_NO(33) | 3)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_33_I2S1_DATA_FUNC_AP_PCM_TX
value|(MTK_PIN_NO(33) | 6)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_34_I2S1_DATA_IN_FUNC_GPIO34
value|(MTK_PIN_NO(34) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_34_I2S1_DATA_IN_FUNC_I2S1_DATA_IN
value|(MTK_PIN_NO(34) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_34_I2S1_DATA_IN_FUNC_PCM_RX
value|(MTK_PIN_NO(34) | 3)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_34_I2S1_DATA_IN_FUNC_AP_PCM_RX
value|(MTK_PIN_NO(34) | 6)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_35_I2S1_BCK_FUNC_GPIO35
value|(MTK_PIN_NO(35) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_35_I2S1_BCK_FUNC_I2S1_BCK
value|(MTK_PIN_NO(35) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_35_I2S1_BCK_FUNC_PCM_CLK0
value|(MTK_PIN_NO(35) | 3)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_35_I2S1_BCK_FUNC_AP_PCM_CLKO
value|(MTK_PIN_NO(35) | 6)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_36_I2S1_LRCK_FUNC_GPIO36
value|(MTK_PIN_NO(36) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_36_I2S1_LRCK_FUNC_I2S1_LRCK
value|(MTK_PIN_NO(36) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_36_I2S1_LRCK_FUNC_PCM_SYNC
value|(MTK_PIN_NO(36) | 3)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_36_I2S1_LRCK_FUNC_AP_PCM_SYNC
value|(MTK_PIN_NO(36) | 6)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_37_I2S1_MCLK_FUNC_GPIO37
value|(MTK_PIN_NO(37) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_37_I2S1_MCLK_FUNC_I2S1_MCLK
value|(MTK_PIN_NO(37) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_39_JTMS_FUNC_GPIO39
value|(MTK_PIN_NO(39) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_39_JTMS_FUNC_JTMS
value|(MTK_PIN_NO(39) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_40_JTCK_FUNC_GPIO40
value|(MTK_PIN_NO(40) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_40_JTCK_FUNC_JTCK
value|(MTK_PIN_NO(40) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_41_JTDI_FUNC_GPIO41
value|(MTK_PIN_NO(41) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_41_JTDI_FUNC_JTDI
value|(MTK_PIN_NO(41) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_42_JTDO_FUNC_GPIO42
value|(MTK_PIN_NO(42) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_42_JTDO_FUNC_JTDO
value|(MTK_PIN_NO(42) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_43_NCLE_FUNC_GPIO43
value|(MTK_PIN_NO(43) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_43_NCLE_FUNC_NCLE
value|(MTK_PIN_NO(43) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_43_NCLE_FUNC_EXT_XCS2
value|(MTK_PIN_NO(43) | 2)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_44_NCEB1_FUNC_GPIO44
value|(MTK_PIN_NO(44) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_44_NCEB1_FUNC_NCEB1
value|(MTK_PIN_NO(44) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_44_NCEB1_FUNC_IDDIG
value|(MTK_PIN_NO(44) | 2)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_45_NCEB0_FUNC_GPIO45
value|(MTK_PIN_NO(45) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_45_NCEB0_FUNC_NCEB0
value|(MTK_PIN_NO(45) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_45_NCEB0_FUNC_DRV_VBUS
value|(MTK_PIN_NO(45) | 2)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_46_IR_FUNC_GPIO46
value|(MTK_PIN_NO(46) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_46_IR_FUNC_IR
value|(MTK_PIN_NO(46) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_47_NREB_FUNC_GPIO47
value|(MTK_PIN_NO(47) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_47_NREB_FUNC_NREB
value|(MTK_PIN_NO(47) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_48_NRNB_FUNC_GPIO48
value|(MTK_PIN_NO(48) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_48_NRNB_FUNC_NRNB
value|(MTK_PIN_NO(48) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_49_I2S0_DATA_FUNC_GPIO49
value|(MTK_PIN_NO(49) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_49_I2S0_DATA_FUNC_I2S0_DATA
value|(MTK_PIN_NO(49) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_49_I2S0_DATA_FUNC_PCM_TX
value|(MTK_PIN_NO(49) | 3)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_49_I2S0_DATA_FUNC_AP_I2S_DO
value|(MTK_PIN_NO(49) | 6)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_53_SPI0_CSN_FUNC_GPIO53
value|(MTK_PIN_NO(53) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_53_SPI0_CSN_FUNC_SPI0_CS
value|(MTK_PIN_NO(53) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_53_SPI0_CSN_FUNC_PWM1
value|(MTK_PIN_NO(53) | 5)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_54_SPI0_CK_FUNC_GPIO54
value|(MTK_PIN_NO(54) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_54_SPI0_CK_FUNC_SPI0_CK
value|(MTK_PIN_NO(54) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_55_SPI0_MI_FUNC_GPIO55
value|(MTK_PIN_NO(55) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_55_SPI0_MI_FUNC_SPI0_MI
value|(MTK_PIN_NO(55) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_55_SPI0_MI_FUNC_SPI0_MO
value|(MTK_PIN_NO(55) | 2)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_55_SPI0_MI_FUNC_MSDC1_WP
value|(MTK_PIN_NO(55) | 3)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_55_SPI0_MI_FUNC_PWM2
value|(MTK_PIN_NO(55) | 5)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_56_SPI0_MO_FUNC_GPIO56
value|(MTK_PIN_NO(56) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_56_SPI0_MO_FUNC_SPI0_MO
value|(MTK_PIN_NO(56) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_56_SPI0_MO_FUNC_SPI0_MI
value|(MTK_PIN_NO(56) | 2)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_57_SDA1_FUNC_GPIO57
value|(MTK_PIN_NO(57) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_57_SDA1_FUNC_SDA1
value|(MTK_PIN_NO(57) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_58_SCL1_FUNC_GPIO58
value|(MTK_PIN_NO(58) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_58_SCL1_FUNC_SCL1
value|(MTK_PIN_NO(58) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_60_WB_RSTB_FUNC_GPIO60
value|(MTK_PIN_NO(60) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_60_WB_RSTB_FUNC_WB_RSTB
value|(MTK_PIN_NO(60) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_61_GPIO61_FUNC_GPIO61
value|(MTK_PIN_NO(61) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_61_GPIO61_FUNC_TEST_FD
value|(MTK_PIN_NO(61) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_62_GPIO62_FUNC_GPIO62
value|(MTK_PIN_NO(62) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_62_GPIO62_FUNC_TEST_FC
value|(MTK_PIN_NO(62) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_63_WB_SCLK_FUNC_GPIO63
value|(MTK_PIN_NO(63) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_63_WB_SCLK_FUNC_WB_SCLK
value|(MTK_PIN_NO(63) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_64_WB_SDATA_FUNC_GPIO64
value|(MTK_PIN_NO(64) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_64_WB_SDATA_FUNC_WB_SDATA
value|(MTK_PIN_NO(64) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_65_WB_SEN_FUNC_GPIO65
value|(MTK_PIN_NO(65) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_65_WB_SEN_FUNC_WB_SEN
value|(MTK_PIN_NO(65) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_66_WB_CRTL0_FUNC_GPIO66
value|(MTK_PIN_NO(66) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_66_WB_CRTL0_FUNC_WB_CRTL0
value|(MTK_PIN_NO(66) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_67_WB_CRTL1_FUNC_GPIO67
value|(MTK_PIN_NO(67) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_67_WB_CRTL1_FUNC_WB_CRTL1
value|(MTK_PIN_NO(67) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_68_WB_CRTL2_FUNC_GPIO68
value|(MTK_PIN_NO(68) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_68_WB_CRTL2_FUNC_WB_CRTL2
value|(MTK_PIN_NO(68) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_69_WB_CRTL3_FUNC_GPIO69
value|(MTK_PIN_NO(69) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_69_WB_CRTL3_FUNC_WB_CRTL3
value|(MTK_PIN_NO(69) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_70_WB_CRTL4_FUNC_GPIO70
value|(MTK_PIN_NO(70) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_70_WB_CRTL4_FUNC_WB_CRTL4
value|(MTK_PIN_NO(70) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_71_WB_CRTL5_FUNC_GPIO71
value|(MTK_PIN_NO(71) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_71_WB_CRTL5_FUNC_WB_CRTL5
value|(MTK_PIN_NO(71) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_72_I2S0_DATA_IN_FUNC_GPIO72
value|(MTK_PIN_NO(72) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_72_I2S0_DATA_IN_FUNC_I2S0_DATA_IN
value|(MTK_PIN_NO(72) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_72_I2S0_DATA_IN_FUNC_PCM_RX
value|(MTK_PIN_NO(72) | 3)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_72_I2S0_DATA_IN_FUNC_PWM0
value|(MTK_PIN_NO(72) | 4)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_72_I2S0_DATA_IN_FUNC_DISP_PWM
value|(MTK_PIN_NO(72) | 5)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_72_I2S0_DATA_IN_FUNC_AP_I2S_DI
value|(MTK_PIN_NO(72) | 6)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_73_I2S0_LRCK_FUNC_GPIO73
value|(MTK_PIN_NO(73) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_73_I2S0_LRCK_FUNC_I2S0_LRCK
value|(MTK_PIN_NO(73) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_73_I2S0_LRCK_FUNC_PCM_SYNC
value|(MTK_PIN_NO(73) | 3)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_73_I2S0_LRCK_FUNC_AP_I2S_LRCK
value|(MTK_PIN_NO(73) | 6)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_74_I2S0_BCK_FUNC_GPIO74
value|(MTK_PIN_NO(74) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_74_I2S0_BCK_FUNC_I2S0_BCK
value|(MTK_PIN_NO(74) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_74_I2S0_BCK_FUNC_PCM_CLK0
value|(MTK_PIN_NO(74) | 3)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_74_I2S0_BCK_FUNC_AP_I2S_BCK
value|(MTK_PIN_NO(74) | 6)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_75_SDA0_FUNC_GPIO75
value|(MTK_PIN_NO(75) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_75_SDA0_FUNC_SDA0
value|(MTK_PIN_NO(75) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_76_SCL0_FUNC_GPIO76
value|(MTK_PIN_NO(76) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_76_SCL0_FUNC_SCL0
value|(MTK_PIN_NO(76) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_79_URXD0_FUNC_GPIO79
value|(MTK_PIN_NO(79) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_79_URXD0_FUNC_URXD0
value|(MTK_PIN_NO(79) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_79_URXD0_FUNC_UTXD0
value|(MTK_PIN_NO(79) | 2)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_80_UTXD0_FUNC_GPIO80
value|(MTK_PIN_NO(80) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_80_UTXD0_FUNC_UTXD0
value|(MTK_PIN_NO(80) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_80_UTXD0_FUNC_URXD0
value|(MTK_PIN_NO(80) | 2)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_81_URXD1_FUNC_GPIO81
value|(MTK_PIN_NO(81) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_81_URXD1_FUNC_URXD1
value|(MTK_PIN_NO(81) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_81_URXD1_FUNC_UTXD1
value|(MTK_PIN_NO(81) | 2)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_82_UTXD1_FUNC_GPIO82
value|(MTK_PIN_NO(82) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_82_UTXD1_FUNC_UTXD1
value|(MTK_PIN_NO(82) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_82_UTXD1_FUNC_URXD1
value|(MTK_PIN_NO(82) | 2)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_83_LCM_RST_FUNC_GPIO83
value|(MTK_PIN_NO(83) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_83_LCM_RST_FUNC_LCM_RST
value|(MTK_PIN_NO(83) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_84_DSI_TE_FUNC_GPIO84
value|(MTK_PIN_NO(84) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_84_DSI_TE_FUNC_DSI_TE
value|(MTK_PIN_NO(84) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_95_MIPI_TCN_FUNC_GPIO95
value|(MTK_PIN_NO(95) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_95_MIPI_TCN_FUNC_TCN
value|(MTK_PIN_NO(95) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_96_MIPI_TCP_FUNC_GPIO96
value|(MTK_PIN_NO(96) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_96_MIPI_TCP_FUNC_TCP
value|(MTK_PIN_NO(96) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_97_MIPI_TDN1_FUNC_GPIO97
value|(MTK_PIN_NO(97) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_97_MIPI_TDN1_FUNC_TDN1
value|(MTK_PIN_NO(97) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_98_MIPI_TDP1_FUNC_GPIO98
value|(MTK_PIN_NO(98) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_98_MIPI_TDP1_FUNC_TDP1
value|(MTK_PIN_NO(98) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_99_MIPI_TDN0_FUNC_GPIO99
value|(MTK_PIN_NO(99) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_99_MIPI_TDN0_FUNC_TDN0
value|(MTK_PIN_NO(99) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_100_MIPI_TDP0_FUNC_GPIO100
value|(MTK_PIN_NO(100) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_100_MIPI_TDP0_FUNC_TDP0
value|(MTK_PIN_NO(100) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_105_MSDC1_CMD_FUNC_GPIO105
value|(MTK_PIN_NO(105) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_105_MSDC1_CMD_FUNC_MSDC1_CMD
value|(MTK_PIN_NO(105) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_105_MSDC1_CMD_FUNC_SDA1
value|(MTK_PIN_NO(105) | 3)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_105_MSDC1_CMD_FUNC_I2SOUT_BCK
value|(MTK_PIN_NO(105) | 6)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_106_MSDC1_CLK_FUNC_GPIO106
value|(MTK_PIN_NO(106) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_106_MSDC1_CLK_FUNC_MSDC1_CLK
value|(MTK_PIN_NO(106) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_106_MSDC1_CLK_FUNC_SCL1
value|(MTK_PIN_NO(106) | 3)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_106_MSDC1_CLK_FUNC_I2SOUT_LRCK
value|(MTK_PIN_NO(106) | 6)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_107_MSDC1_DAT0_FUNC_GPIO107
value|(MTK_PIN_NO(107) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_107_MSDC1_DAT0_FUNC_MSDC1_DAT0
value|(MTK_PIN_NO(107) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_107_MSDC1_DAT0_FUNC_UTXD0
value|(MTK_PIN_NO(107) | 5)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_107_MSDC1_DAT0_FUNC_I2SOUT_DATA_OUT
value|(MTK_PIN_NO(107) | 6)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_108_MSDC1_DAT1_FUNC_GPIO108
value|(MTK_PIN_NO(108) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_108_MSDC1_DAT1_FUNC_MSDC1_DAT1
value|(MTK_PIN_NO(108) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_108_MSDC1_DAT1_FUNC_PWM0
value|(MTK_PIN_NO(108) | 3)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_108_MSDC1_DAT1_FUNC_URXD0
value|(MTK_PIN_NO(108) | 5)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_108_MSDC1_DAT1_FUNC_PWM1
value|(MTK_PIN_NO(108) | 6)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_109_MSDC1_DAT2_FUNC_GPIO109
value|(MTK_PIN_NO(109) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_109_MSDC1_DAT2_FUNC_MSDC1_DAT2
value|(MTK_PIN_NO(109) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_109_MSDC1_DAT2_FUNC_SDA2
value|(MTK_PIN_NO(109) | 3)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_109_MSDC1_DAT2_FUNC_UTXD1
value|(MTK_PIN_NO(109) | 5)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_109_MSDC1_DAT2_FUNC_PWM2
value|(MTK_PIN_NO(109) | 6)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_110_MSDC1_DAT3_FUNC_GPIO110
value|(MTK_PIN_NO(110) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_110_MSDC1_DAT3_FUNC_MSDC1_DAT3
value|(MTK_PIN_NO(110) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_110_MSDC1_DAT3_FUNC_SCL2
value|(MTK_PIN_NO(110) | 3)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_110_MSDC1_DAT3_FUNC_URXD1
value|(MTK_PIN_NO(110) | 5)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_110_MSDC1_DAT3_FUNC_PWM3
value|(MTK_PIN_NO(110) | 6)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_111_MSDC0_DAT7_FUNC_GPIO111
value|(MTK_PIN_NO(111) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_111_MSDC0_DAT7_FUNC_MSDC0_DAT7
value|(MTK_PIN_NO(111) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_111_MSDC0_DAT7_FUNC_NLD7
value|(MTK_PIN_NO(111) | 4)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_112_MSDC0_DAT6_FUNC_GPIO112
value|(MTK_PIN_NO(112) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_112_MSDC0_DAT6_FUNC_MSDC0_DAT6
value|(MTK_PIN_NO(112) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_112_MSDC0_DAT6_FUNC_NLD6
value|(MTK_PIN_NO(112) | 4)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_113_MSDC0_DAT5_FUNC_GPIO113
value|(MTK_PIN_NO(113) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_113_MSDC0_DAT5_FUNC_MSDC0_DAT5
value|(MTK_PIN_NO(113) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_113_MSDC0_DAT5_FUNC_NLD5
value|(MTK_PIN_NO(113) | 4)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_114_MSDC0_DAT4_FUNC_GPIO114
value|(MTK_PIN_NO(114) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_114_MSDC0_DAT4_FUNC_MSDC0_DAT4
value|(MTK_PIN_NO(114) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_114_MSDC0_DAT4_FUNC_NLD4
value|(MTK_PIN_NO(114) | 4)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_115_MSDC0_RSTB_FUNC_GPIO115
value|(MTK_PIN_NO(115) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_115_MSDC0_RSTB_FUNC_MSDC0_RSTB
value|(MTK_PIN_NO(115) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_115_MSDC0_RSTB_FUNC_NLD8
value|(MTK_PIN_NO(115) | 4)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_116_MSDC0_CMD_FUNC_GPIO116
value|(MTK_PIN_NO(116) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_116_MSDC0_CMD_FUNC_MSDC0_CMD
value|(MTK_PIN_NO(116) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_116_MSDC0_CMD_FUNC_NALE
value|(MTK_PIN_NO(116) | 4)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_117_MSDC0_CLK_FUNC_GPIO117
value|(MTK_PIN_NO(117) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_117_MSDC0_CLK_FUNC_MSDC0_CLK
value|(MTK_PIN_NO(117) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_117_MSDC0_CLK_FUNC_NWEB
value|(MTK_PIN_NO(117) | 4)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_118_MSDC0_DAT3_FUNC_GPIO118
value|(MTK_PIN_NO(118) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_118_MSDC0_DAT3_FUNC_MSDC0_DAT3
value|(MTK_PIN_NO(118) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_118_MSDC0_DAT3_FUNC_NLD3
value|(MTK_PIN_NO(118) | 4)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_119_MSDC0_DAT2_FUNC_GPIO119
value|(MTK_PIN_NO(119) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_119_MSDC0_DAT2_FUNC_MSDC0_DAT2
value|(MTK_PIN_NO(119) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_119_MSDC0_DAT2_FUNC_NLD2
value|(MTK_PIN_NO(119) | 4)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_120_MSDC0_DAT1_FUNC_GPIO120
value|(MTK_PIN_NO(120) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_120_MSDC0_DAT1_FUNC_MSDC0_DAT1
value|(MTK_PIN_NO(120) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_120_MSDC0_DAT1_FUNC_NLD1
value|(MTK_PIN_NO(120) | 4)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_121_MSDC0_DAT0_FUNC_GPIO121
value|(MTK_PIN_NO(121) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_121_MSDC0_DAT0_FUNC_MSDC0_DAT0
value|(MTK_PIN_NO(121) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_121_MSDC0_DAT0_FUNC_NLD0
value|(MTK_PIN_NO(121) | 4)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_121_MSDC0_DAT0_FUNC_WATCHDOG
value|(MTK_PIN_NO(121) | 5)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_122_GPIO122_FUNC_GPIO122
value|(MTK_PIN_NO(122) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_122_GPIO122_FUNC_TEST
value|(MTK_PIN_NO(122) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_122_GPIO122_FUNC_SDA2
value|(MTK_PIN_NO(122) | 4)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_122_GPIO122_FUNC_URXD0
value|(MTK_PIN_NO(122) | 5)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_123_HTPLG_FUNC_GPIO123
value|(MTK_PIN_NO(123) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_123_HTPLG_FUNC_HTPLG
value|(MTK_PIN_NO(123) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_123_HTPLG_FUNC_SCL2
value|(MTK_PIN_NO(123) | 4)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_123_HTPLG_FUNC_UTXD0
value|(MTK_PIN_NO(123) | 5)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_124_GPIO124_FUNC_GPIO124
value|(MTK_PIN_NO(124) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_124_GPIO124_FUNC_TEST
value|(MTK_PIN_NO(124) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_124_GPIO124_FUNC_SDA1
value|(MTK_PIN_NO(124) | 4)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_124_GPIO124_FUNC_PWM3
value|(MTK_PIN_NO(124) | 5)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_125_GPIO125_FUNC_GPIO125
value|(MTK_PIN_NO(125) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_125_GPIO125_FUNC_TEST
value|(MTK_PIN_NO(125) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_125_GPIO125_FUNC_SCL1
value|(MTK_PIN_NO(125) | 4)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_125_GPIO125_FUNC_PWM4
value|(MTK_PIN_NO(125) | 5)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_126_I2S0_MCLK_FUNC_GPIO126
value|(MTK_PIN_NO(126) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_126_I2S0_MCLK_FUNC_I2S0_MCLK
value|(MTK_PIN_NO(126) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_126_I2S0_MCLK_FUNC_AP_I2S_MCLK
value|(MTK_PIN_NO(126) | 6)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_199_SPI1_CK_FUNC_GPIO199
value|(MTK_PIN_NO(199) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_199_SPI1_CK_FUNC_SPI1_CK
value|(MTK_PIN_NO(199) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_200_URXD2_FUNC_GPIO200
value|(MTK_PIN_NO(200) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_200_URXD2_FUNC_URXD2
value|(MTK_PIN_NO(200) | 6)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_201_UTXD2_FUNC_GPIO201
value|(MTK_PIN_NO(201) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_201_UTXD2_FUNC_UTXD2
value|(MTK_PIN_NO(201) | 6)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_203_PWM0_FUNC_GPIO203
value|(MTK_PIN_NO(203) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_203_PWM0_FUNC_PWM0
value|(MTK_PIN_NO(203) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_203_PWM0_FUNC_DISP_PWM
value|(MTK_PIN_NO(203) | 2)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_204_PWM1_FUNC_GPIO204
value|(MTK_PIN_NO(204) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_204_PWM1_FUNC_PWM1
value|(MTK_PIN_NO(204) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_205_PWM2_FUNC_GPIO205
value|(MTK_PIN_NO(205) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_205_PWM2_FUNC_PWM2
value|(MTK_PIN_NO(205) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_206_PWM3_FUNC_GPIO206
value|(MTK_PIN_NO(206) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_206_PWM3_FUNC_PWM3
value|(MTK_PIN_NO(206) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_207_PWM4_FUNC_GPIO207
value|(MTK_PIN_NO(207) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_207_PWM4_FUNC_PWM4
value|(MTK_PIN_NO(207) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_208_AUD_EXT_CK1_FUNC_GPIO208
value|(MTK_PIN_NO(208) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_208_AUD_EXT_CK1_FUNC_AUD_EXT_CK1
value|(MTK_PIN_NO(208) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_208_AUD_EXT_CK1_FUNC_PWM0
value|(MTK_PIN_NO(208) | 2)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_208_AUD_EXT_CK1_FUNC_PCIE0_PERST_N
value|(MTK_PIN_NO(208) | 3)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_208_AUD_EXT_CK1_FUNC_DISP_PWM
value|(MTK_PIN_NO(208) | 5)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_209_AUD_EXT_CK2_FUNC_GPIO209
value|(MTK_PIN_NO(209) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_209_AUD_EXT_CK2_FUNC_AUD_EXT_CK2
value|(MTK_PIN_NO(209) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_209_AUD_EXT_CK2_FUNC_MSDC1_WP
value|(MTK_PIN_NO(209) | 2)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_209_AUD_EXT_CK2_FUNC_PCIE1_PERST_N
value|(MTK_PIN_NO(209) | 3)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_209_AUD_EXT_CK2_FUNC_PWM1
value|(MTK_PIN_NO(209) | 5)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_236_EXT_SDIO3_FUNC_GPIO236
value|(MTK_PIN_NO(236) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_236_EXT_SDIO3_FUNC_EXT_SDIO3
value|(MTK_PIN_NO(236) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_236_EXT_SDIO3_FUNC_IDDIG
value|(MTK_PIN_NO(236) | 2)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_237_EXT_SDIO2_FUNC_GPIO237
value|(MTK_PIN_NO(237) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_237_EXT_SDIO2_FUNC_EXT_SDIO2
value|(MTK_PIN_NO(237) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_237_EXT_SDIO2_FUNC_DRV_VBUS
value|(MTK_PIN_NO(237) | 2)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_238_EXT_SDIO1_FUNC_GPIO238
value|(MTK_PIN_NO(238) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_238_EXT_SDIO1_FUNC_EXT_SDIO1
value|(MTK_PIN_NO(238) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_239_EXT_SDIO0_FUNC_GPIO239
value|(MTK_PIN_NO(239) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_239_EXT_SDIO0_FUNC_EXT_SDIO0
value|(MTK_PIN_NO(239) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_240_EXT_XCS_FUNC_GPIO240
value|(MTK_PIN_NO(240) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_240_EXT_XCS_FUNC_EXT_XCS
value|(MTK_PIN_NO(240) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_241_EXT_SCK_FUNC_GPIO241
value|(MTK_PIN_NO(241) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_241_EXT_SCK_FUNC_EXT_SCK
value|(MTK_PIN_NO(241) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_242_URTS2_FUNC_GPIO242
value|(MTK_PIN_NO(242) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_242_URTS2_FUNC_URTS2
value|(MTK_PIN_NO(242) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_242_URTS2_FUNC_UTXD3
value|(MTK_PIN_NO(242) | 2)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_242_URTS2_FUNC_URXD3
value|(MTK_PIN_NO(242) | 3)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_242_URTS2_FUNC_SCL1
value|(MTK_PIN_NO(242) | 4)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_243_UCTS2_FUNC_GPIO243
value|(MTK_PIN_NO(243) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_243_UCTS2_FUNC_UCTS2
value|(MTK_PIN_NO(243) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_243_UCTS2_FUNC_URXD3
value|(MTK_PIN_NO(243) | 2)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_243_UCTS2_FUNC_UTXD3
value|(MTK_PIN_NO(243) | 3)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_243_UCTS2_FUNC_SDA1
value|(MTK_PIN_NO(243) | 4)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_250_GPIO250_FUNC_GPIO250
value|(MTK_PIN_NO(250) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_250_GPIO250_FUNC_TEST_MD7
value|(MTK_PIN_NO(250) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_250_GPIO250_FUNC_PCIE0_CLKREQ_N
value|(MTK_PIN_NO(250) | 6)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_251_GPIO251_FUNC_GPIO251
value|(MTK_PIN_NO(251) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_251_GPIO251_FUNC_TEST_MD6
value|(MTK_PIN_NO(251) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_251_GPIO251_FUNC_PCIE0_WAKE_N
value|(MTK_PIN_NO(251) | 6)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_252_GPIO252_FUNC_GPIO252
value|(MTK_PIN_NO(252) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_252_GPIO252_FUNC_TEST_MD5
value|(MTK_PIN_NO(252) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_252_GPIO252_FUNC_PCIE1_CLKREQ_N
value|(MTK_PIN_NO(252) | 6)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_253_GPIO253_FUNC_GPIO253
value|(MTK_PIN_NO(253) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_253_GPIO253_FUNC_TEST_MD4
value|(MTK_PIN_NO(253) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_253_GPIO253_FUNC_PCIE1_WAKE_N
value|(MTK_PIN_NO(253) | 6)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_254_GPIO254_FUNC_GPIO254
value|(MTK_PIN_NO(254) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_254_GPIO254_FUNC_TEST_MD3
value|(MTK_PIN_NO(254) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_254_GPIO254_FUNC_PCIE2_CLKREQ_N
value|(MTK_PIN_NO(254) | 6)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_255_GPIO255_FUNC_GPIO255
value|(MTK_PIN_NO(255) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_255_GPIO255_FUNC_TEST_MD2
value|(MTK_PIN_NO(255) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_255_GPIO255_FUNC_PCIE2_WAKE_N
value|(MTK_PIN_NO(255) | 6)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_256_GPIO256_FUNC_GPIO256
value|(MTK_PIN_NO(256) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_256_GPIO256_FUNC_TEST_MD1
value|(MTK_PIN_NO(256) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_257_GPIO257_FUNC_GPIO257
value|(MTK_PIN_NO(257) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_257_GPIO257_FUNC_TEST_MD0
value|(MTK_PIN_NO(257) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_261_MSDC1_INS_FUNC_GPIO261
value|(MTK_PIN_NO(261) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_261_MSDC1_INS_FUNC_MSDC1_INS
value|(MTK_PIN_NO(261) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_262_G2_TXEN_FUNC_GPIO262
value|(MTK_PIN_NO(262) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_262_G2_TXEN_FUNC_G2_TXEN
value|(MTK_PIN_NO(262) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_263_G2_TXD3_FUNC_GPIO263
value|(MTK_PIN_NO(263) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_263_G2_TXD3_FUNC_G2_TXD3
value|(MTK_PIN_NO(263) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_264_G2_TXD2_FUNC_GPIO264
value|(MTK_PIN_NO(264) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_264_G2_TXD2_FUNC_G2_TXD2
value|(MTK_PIN_NO(264) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_265_G2_TXD1_FUNC_GPIO265
value|(MTK_PIN_NO(265) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_265_G2_TXD1_FUNC_G2_TXD1
value|(MTK_PIN_NO(265) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_266_G2_TXD0_FUNC_GPIO266
value|(MTK_PIN_NO(266) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_266_G2_TXD0_FUNC_G2_TXD0
value|(MTK_PIN_NO(266) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_267_G2_TXCLK_FUNC_GPIO267
value|(MTK_PIN_NO(267) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_267_G2_TXCLK_FUNC_G2_TXC
value|(MTK_PIN_NO(267) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_268_G2_RXCLK_FUNC_GPIO268
value|(MTK_PIN_NO(268) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_268_G2_RXCLK_FUNC_G2_RXC
value|(MTK_PIN_NO(268) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_269_G2_RXD0_FUNC_GPIO269
value|(MTK_PIN_NO(269) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_269_G2_RXD0_FUNC_G2_RXD0
value|(MTK_PIN_NO(269) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_270_G2_RXD1_FUNC_GPIO270
value|(MTK_PIN_NO(270) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_270_G2_RXD1_FUNC_G2_RXD1
value|(MTK_PIN_NO(270) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_271_G2_RXD2_FUNC_GPIO271
value|(MTK_PIN_NO(271) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_271_G2_RXD2_FUNC_G2_RXD2
value|(MTK_PIN_NO(271) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_272_G2_RXD3_FUNC_GPIO272
value|(MTK_PIN_NO(272) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_272_G2_RXD3_FUNC_G2_RXD3
value|(MTK_PIN_NO(272) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_274_G2_RXDV_FUNC_GPIO274
value|(MTK_PIN_NO(274) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_274_G2_RXDV_FUNC_G2_RXDV
value|(MTK_PIN_NO(274) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_275_G2_MDC_FUNC_GPIO275
value|(MTK_PIN_NO(275) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_275_G2_MDC_FUNC_MDC
value|(MTK_PIN_NO(275) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_276_G2_MDIO_FUNC_GPIO276
value|(MTK_PIN_NO(276) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_276_G2_MDIO_FUNC_MDIO
value|(MTK_PIN_NO(276) | 1)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_278_JTAG_RESET_FUNC_GPIO278
value|(MTK_PIN_NO(278) | 0)
end_define

begin_define
define|#
directive|define
name|MT7623_PIN_278_JTAG_RESET_FUNC_JTAG_RESET
value|(MTK_PIN_NO(278) | 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DTS_MT7623_PINFUNC_H */
end_comment

end_unit

