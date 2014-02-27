begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2013 Freescale Semiconductor, Inc.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DTS_VF610_PINFUNC_H
end_ifndef

begin_define
define|#
directive|define
name|__DTS_VF610_PINFUNC_H
end_define

begin_comment
comment|/*  * The pin function ID for VF610 is a tuple of:  *<mux_reg input_reg mux_mode input_val>  */
end_comment

begin_define
define|#
directive|define
name|ALT0
value|0x0
end_define

begin_define
define|#
directive|define
name|ALT1
value|0x1
end_define

begin_define
define|#
directive|define
name|ALT2
value|0x2
end_define

begin_define
define|#
directive|define
name|ALT3
value|0x3
end_define

begin_define
define|#
directive|define
name|ALT4
value|0x4
end_define

begin_define
define|#
directive|define
name|ALT5
value|0x5
end_define

begin_define
define|#
directive|define
name|ALT6
value|0x6
end_define

begin_define
define|#
directive|define
name|ALT7
value|0x7
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA6__GPIO_0
value|0x000 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA6__RMII_CLKOUT
value|0x000 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA6__RMII_CLKIN
value|0x000 0x2F0 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA6__DCU1_TCON11
value|0x000 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA6__DCU1_R2
value|0x000 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA8__GPIO_1
value|0x004 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA8__TCLK
value|0x004 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA8__DCU0_R0
value|0x004 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA8__MLB_CLK
value|0x004 0x354 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA9__GPIO_2
value|0x008 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA9__TDI
value|0x008 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA9__RMII_CLKOUT
value|0x008 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA9__RMII_CLKIN
value|0x008 0x2F0 ALT3 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA9__DCU0_R1
value|0x008 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA9__WDOG_B
value|0x008 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA10__GPIO_3
value|0x00C 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA10__TDO
value|0x00C 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA10__EXT_AUDIO_MCLK
value|0x00C 0x2EC ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA10__DCU0_G0
value|0x00C 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA10__ENET_TS_CLKIN
value|0x00C 0x2F4 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA10__MLB_SIGNAL
value|0x00C 0x35C ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA11__GPIO_4
value|0x010 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA11__TMS
value|0x010 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA11__DCU0_G1
value|0x010 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA11__MLB_DATA
value|0x010 0x358 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA12__GPIO_5
value|0x014 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA12__TRACECK
value|0x014 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA12__EXT_AUDIO_MCLK
value|0x014 0x2EC ALT2 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA12__VIU_DATA13
value|0x014 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA12__I2C0_SCL
value|0x014 0x33C ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA16__GPIO_6
value|0x018 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA16__TRACED0
value|0x018 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA16__USB0_VBUS_EN
value|0x018 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA16__ADC1_SE0
value|0x018 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA16__LCD29
value|0x018 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA16__SAI2_TX_BCLK
value|0x018 0x370 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA16__VIU_DATA14
value|0x018 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA16__I2C0_SDA
value|0x018 0x340 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA17__GPIO_7
value|0x01C 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA17__TRACED1
value|0x01C 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA17__USB0_VBUS_OC
value|0x01C 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA17__ADC1_SE1
value|0x01C 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA17__LCD30
value|0x01C 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA17__USB0_SOF_PULSE
value|0x01C 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA17__VIU_DATA15
value|0x01C 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA17__I2C1_SCL
value|0x01C 0x344 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA18__GPIO_8
value|0x020 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA18__TRACED2
value|0x020 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA18__ADC0_SE0
value|0x020 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA18__FTM1_QD_PHA
value|0x020 0x334 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA18__LCD31
value|0x020 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA18__SAI2_TX_DATA
value|0x020 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA18__VIU_DATA16
value|0x020 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA18__I2C1_SDA
value|0x020 0x348 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA19__GPIO_9
value|0x024 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA19__TRACED3
value|0x024 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA19__ADC0_SE1
value|0x024 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA19__FTM1_QD_PHB
value|0x024 0x338 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA19__LCD32
value|0x024 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA19__SAI2_TX_SYNC
value|0x024 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA19__VIU_DATA17
value|0x024 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA19__QSPI1_A_QSCK
value|0x024 0x374 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA20__GPIO_10
value|0x028 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA20__TRACED4
value|0x028 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA20__LCD33
value|0x028 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA20__UART3_TX
value|0x028 0x394 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA20__DCU1_HSYNC
value|0x028 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA21__GPIO_11
value|0x02C 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA21__TRACED5
value|0x02C 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA21__SAI2_RX_BCLK
value|0x02C 0x364 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA21__UART3_RX
value|0x02C 0x390 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA21__DCU1_VSYNC
value|0x02C 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA22__GPIO_12
value|0x030 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA22__TRACED6
value|0x030 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA22__SAI2_RX_DATA
value|0x030 0x368 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA22__I2C2_SCL
value|0x030 0x34C ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA22__DCU1_TAG
value|0x030 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA23__GPIO_13
value|0x034 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA23__TRACED7
value|0x034 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA23__SAI2_RX_SYNC
value|0x034 0x36C ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA23__I2C2_SDA
value|0x034 0x350 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA23__DCU1_DE
value|0x034 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA24__GPIO_14
value|0x038 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA24__TRACED8
value|0x038 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA24__USB1_VBUS_EN
value|0x038 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA24__ESDHC1_CLK
value|0x038 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA24__DCU1_TCON4
value|0x038 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA24__DDR_TEST_PAD_CTRL
value|0x038 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA25__GPIO_15
value|0x03C 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA25__TRACED9
value|0x03C 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA25__USB1_VBUS_OC
value|0x03C 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA25__ESDHC1_CMD
value|0x03C 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA25__DCU1_TCON5
value|0x03C 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA26__GPIO_16
value|0x040 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA26__TRACED10
value|0x040 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA26__SAI3_TX_BCLK
value|0x040 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA26__ESDHC1_DAT0
value|0x040 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA26__DCU1_TCON6
value|0x040 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA27__GPIO_17
value|0x044 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA27__TRACED11
value|0x044 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA27__SAI3_RX_BCLK
value|0x044 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA27__ESDHC1_DAT1
value|0x044 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA27__DCU1_TCON7
value|0x044 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA28__GPIO_18
value|0x048 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA28__TRACED12
value|0x048 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA28__SAI3_RX_DATA
value|0x048 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA28__ENET1_1588_TMR0
value|0x048 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA28__UART4_TX
value|0x048 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA28__ESDHC1_DATA2
value|0x048 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA28__DCU1_TCON8
value|0x048 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA29__GPIO_19
value|0x04C 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA29__TRACED13
value|0x04C 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA29__SAI3_TX_DATA
value|0x04C 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA29__ENET1_1588_TMR1
value|0x04C 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA29__UART4_RX
value|0x04C 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA29__ESDHC1_DAT3
value|0x04C 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA29__DCU1_TCON9
value|0x04C 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA30__GPIO_20
value|0x050 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA30__TRACED14
value|0x050 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA30__SAI3_RX_SYNC
value|0x050 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA30__ENET1_1588_TMR2
value|0x050 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA30__UART4_RTS
value|0x050 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA30__I2C3_SCL
value|0x050 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA30__UART3_TX
value|0x050 0x394 ALT7 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA31__GPIO_21
value|0x054 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA31__TRACED15
value|0x054 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA31__SAI3_TX_SYNC
value|0x054 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA31__ENET1_1588_TMR3
value|0x054 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA31__UART4_CTS
value|0x054 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA31__I2C3_SDA
value|0x054 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA31__UART3_RX
value|0x054 0x390 ALT7 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB0__GPIO_22
value|0x058 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB0__FTM0_CH0
value|0x058 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB0__ADC0_SE2
value|0x058 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB0__TRACE_CTL
value|0x058 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB0__LCD34
value|0x058 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB0__SAI2_RX_BCLK
value|0x058 0x364 ALT5 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB0__VIU_DATA18
value|0x058 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB0__QSPI1_A_QPCS0
value|0x058 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB1__GPIO_23
value|0x05C 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB1__FTM0_CH1
value|0x05C 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB1__ADC0_SE3
value|0x05C 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB1__SRC_RCON30
value|0x05C 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB1__LCD35
value|0x05C 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB1__SAI2_RX_DATA
value|0x05C 0x368 ALT5 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB1__VIU_DATA19
value|0x05C 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB1__QSPI1_A_DATA3
value|0x05C 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB2__GPIO_24
value|0x060 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB2__FTM0_CH2
value|0x060 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB2__ADC1_SE2
value|0x060 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB2__SRC_RCON31
value|0x060 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB2__LCD36
value|0x060 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB2__SAI2_RX_SYNC
value|0x060 0x36C ALT5 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB2__VIDEO_IN0_DATA20
value|0x060 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB2__QSPI1_A_DATA2
value|0x060 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB3__GPIO_25
value|0x064 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB3__FTM0_CH3
value|0x064 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB3__ADC1_SE3
value|0x064 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB3__PDB_EXTRIG
value|0x064 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB3__LCD37
value|0x064 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB3__VIU_DATA21
value|0x064 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB3__QSPI1_A_DATA1
value|0x064 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB4__GPIO_26
value|0x068 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB4__FTM0_CH4
value|0x068 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB4__UART1_TX
value|0x068 0x380 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB4__ADC0_SE4
value|0x068 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB4__LCD38
value|0x068 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB4__VIU_FID
value|0x068 0x3A8 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB4__VIU_DATA22
value|0x068 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB4__QSPI1_A_DATA0
value|0x068 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB5__GPIO_27
value|0x06C 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB5__FTM0_CH5
value|0x06C 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB5__UART1_RX
value|0x06C 0x37C ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB5__ADC1_SE4
value|0x06C 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB5__LCD39
value|0x06C 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB5__VIU_DE
value|0x06C 0x3A4 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB5__QSPI1_A_DQS
value|0x06C 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB6__GPIO_28
value|0x070 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB6__FTM0_CH6
value|0x070 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB6__UART1_RTS
value|0x070 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB6__QSPI0_QPCS1_A
value|0x070 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB6__LCD_LCD40
value|0x070 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB6__FB_CLKOUT
value|0x070 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB6__VIU_HSYNC
value|0x070 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB6__UART2_TX
value|0x070 0x38C ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB7__GPIO_29
value|0x074 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB7__FTM0_CH7
value|0x074 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB7__UART1_CTS
value|0x074 0x378 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB7__QSPI0_B_QPCS1
value|0x074 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB7__LCD41
value|0x074 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB7__VIU_VSYNC
value|0x074 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB7__UART2_RX
value|0x074 0x388 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB8__GPIO_30
value|0x078 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB8__FTM1_CH0
value|0x078 0x32C ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB8__FTM1_QD_PHA
value|0x078 0x334 ALT3 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB8__VIU_DE
value|0x078 0x3A4 ALT5 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB8__DCU1_R6
value|0x078 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB9__GPIO_31
value|0x07C 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB9__FTM1_CH1
value|0x07C 0x330 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB9__FTM1_QD_PHB
value|0x07C 0x338 ALT3 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB9__DCU1_R7
value|0x07C 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB10__GPIO_32
value|0x080 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB10__UART0_TX
value|0x080 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB10__DCU0_TCON4
value|0x080 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB10__VIU_DE
value|0x080 0x3A4 ALT5 0x2
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB10__CKO1
value|0x080 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB10__ENET_TS_CLKIN
value|0x080 0x2F4 ALT7 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB11__GPIO_33
value|0x084 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB11__UART0_RX
value|0x084 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB11__DCU0_TCON5
value|0x084 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB11__SNVS_ALARM_OUT_B
value|0x084 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB11__CKO2
value|0x084 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB11_ENET0_1588_TMR0
value|0x084 0x304 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB12__GPIO_34
value|0x088 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB12__UART0_RTS
value|0x088 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB12__DSPI0_CS5
value|0x088 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB12__DCU0_TCON6
value|0x088 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB12__FB_AD1
value|0x088 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB12__NMI
value|0x088 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB12__ENET0_1588_TMR1
value|0x088 0x308 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB13__GPIO_35
value|0x08C 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB13__UART0_CTS
value|0x08C 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB13__DSPI0_CS4
value|0x08C 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB13__DCU0_TCON7
value|0x08C 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB13__FB_AD0
value|0x08C 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB13__TRACE_CTL
value|0x08C 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB14__GPIO_36
value|0x090 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB14__CAN0_RX
value|0x090 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB14__I2C0_SCL
value|0x090 0x33C ALT2 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB14__DCU0_TCON8
value|0x090 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB14__DCU1_PCLK
value|0x090 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB15__GPIO_37
value|0x094 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB15__CAN0_TX
value|0x094 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB15__I2C0_SDA
value|0x094 0x340 ALT2 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB15__DCU0_TCON9
value|0x094 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB15__VIU_PIX_CLK
value|0x094 0x3AC ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB16__GPIO_38
value|0x098 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB16__CAN1_RX
value|0x098 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB16__I2C1_SCL
value|0x098 0x344 ALT2 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB16__DCU0_TCON10
value|0x098 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB17__GPIO_39
value|0x09C 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB17__CAN1_TX
value|0x09C 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB17__I2C1_SDA
value|0x09C 0x348 ALT2 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB17__DCU0_TCON11
value|0x09C 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB18__GPIO_40
value|0x0A0 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB18__DSPI0_CS1
value|0x0A0 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB18__EXT_AUDIO_MCLK
value|0x0A0 0x2EC ALT2 0x2
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB18__VIU_DATA9
value|0x0A0 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB19__GPIO_41
value|0x0A4 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB19__DSPI0_CS0
value|0x0A4 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB19__VIU_DATA10
value|0x0A4 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB20__GPIO_42
value|0x0A8 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB20__DSPI0_SIN
value|0x0A8 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB20__LCD42
value|0x0A8 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB20__VIU_DATA11
value|0x0A8 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB21__GPIO_43
value|0x0AC 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB21__DSPI0_SOUT
value|0x0AC 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB21__LCD43
value|0x0AC 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB21__VIU_DATA12
value|0x0AC 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB21__DCU1_PCLK
value|0x0AC 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB22__GPIO_44
value|0x0B0 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB22__DSPI0_SCK
value|0x0B0 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB22__VLCD
value|0x0B0 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB22__VIU_FID
value|0x0B0 0x3A8 ALT5 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC0__GPIO_45
value|0x0B4 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC0__ENET_RMII0_MDC
value|0x0B4 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC0__FTM1_CH0
value|0x0B4 0x32C ALT2 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC0__DSPI0_CS3
value|0x0B4 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC0__ESAI_SCKT
value|0x0B4 0x310 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC0__ESDHC0_CLK
value|0x0B4 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC0__VIU_DATA0
value|0x0B4 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC0__SRC_RCON18
value|0x0B4 0x398 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC1__GPIO_46
value|0x0B8 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC1__ENET_RMII0_MDIO
value|0x0B8 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC1__FTM1_CH1
value|0x0B8 0x330 ALT2 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC1__DSPI0_CS2
value|0x0B8 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC1__ESAI_FST
value|0x0B8 0x30C ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC1__ESDHC0_CMD
value|0x0B8 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC1__VIU_DATA1
value|0x0B8 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC1__SRC_RCON19
value|0x0B8 0x39C ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC2__GPIO_47
value|0x0BC 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC2__ENET_RMII0_CRS
value|0x0BC 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC2__UART1_TX
value|0x0BC 0x380 ALT2 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC2__ESAI_SDO0
value|0x0BC 0x314 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC2__ESDHC0_DAT0
value|0x0BC 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC2__VIU_DATA2
value|0x0BC 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC2__SRC_RCON20
value|0x0BC 0x3A0 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC3__GPIO_48
value|0x0C0 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC3__ENET_RMII0_RXD1
value|0x0C0 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC3__UART1_RX
value|0x0C0 0x37C ALT2 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC3__ESAI_SDO1
value|0x0C0 0x318 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC3__ESDHC0_DAT1
value|0x0C0 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC3__VIU_DATA3
value|0x0C0 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC3__DCU0_R0
value|0x0C0 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC4__GPIO_49
value|0x0C4 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC4__ENET_RMII0_RXD0
value|0x0C4 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC4__UART1_RTS
value|0x0C4 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC4__DSPI1_CS1
value|0x0C4 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC4__ESAI_SDO2
value|0x0C4 0x31C ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC4__ESDHC0_DAT2
value|0x0C4 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC4__VIU_DATA4
value|0x0C4 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC4__DCU0_R1
value|0x0C4 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC5__GPIO_50
value|0x0C8 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC5__ENET_RMII0_RXER
value|0x0C8 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC5__UART1_CTS
value|0x0C8 0x378 ALT2 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC5__DSPI1_CS0
value|0x0C8 0x300 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC5__ESAI_SDO3
value|0x0C8 0x320 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC5__ESDHC0_DAT3
value|0x0C8 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC5__VIU_DATA5
value|0x0C8 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC5__DCU0_G0
value|0x0C8 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC6__GPIO_51
value|0x0CC 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC6__ENET_RMII0_TXD1
value|0x0CC 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC6__DSPI1_SIN
value|0x0CC 0x2FC ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC6__ESAI_SDI0
value|0x0CC 0x328 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC6__ESDHC0_WP
value|0x0CC 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC6__VIU_DATA6
value|0x0CC 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC6__DCU0_G1
value|0x0CC 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC7__GPIO_52
value|0x0D0 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC7__ENET_RMII0_TXD0
value|0x0D0 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC7__DSPI1_SOUT
value|0x0D0 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC7__ESAI_SDI1
value|0x0D0 0x324 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC7__VIU_DATA7
value|0x0D0 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC7__DCU0_B0
value|0x0D0 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC8__GPIO_53
value|0x0D4 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC8__ENET_RMII0_TXEN
value|0x0D4 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC8__DSPI1_SCK
value|0x0D4 0x2F8 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC8__VIU_DATA8
value|0x0D4 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC8__DCU0_B1
value|0x0D4 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC9__GPIO_54
value|0x0D8 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC9__ENET_RMII1_MDC
value|0x0D8 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC9__ESAI_SCKT
value|0x0D8 0x310 ALT3 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC9__MLB_CLK
value|0x0D8 0x354 ALT6 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC9__DEBUG_OUT0
value|0x0D8 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC10__GPIO_55
value|0x0DC 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC10__ENET_RMII1_MDIO
value|0x0DC 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC10__ESAI_FST
value|0x0DC 0x30C ALT3 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC10__MLB_SIGNAL
value|0x0DC 0x35C ALT6 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC10__DEBUG_OUT1
value|0x0DC 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC11__GPIO_56
value|0x0E0 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC11__ENET_RMII1_CRS
value|0x0E0 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC11__ESAI_SDO0
value|0x0E0 0x314 ALT3 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC11__MLB_DATA
value|0x0E0 0x358 ALT6 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC11__DEBUG_OUT
value|0x0E0 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC12__GPIO_57
value|0x0E4 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC12__ENET_RMII_RXD1
value|0x0E4 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC12__ESAI_SDO1
value|0x0E4 0x318 ALT3 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC12__SAI2_TX_BCLK
value|0x0E4 0x370 ALT5 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC12__DEBUG_OUT3
value|0x0E4 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC13__GPIO_58
value|0x0E8 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC13__ENET_RMII1_RXD0
value|0x0E8 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC13__ESAI_SDO2
value|0x0E8 0x31C ALT3 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC13__SAI2_RX_BCLK
value|0x0E8 0x364 ALT5 0x2
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC13__DEBUG_OUT4
value|0x0E8 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC14__GPIO_59
value|0x0EC 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC14__ENET_RMII1_RXER
value|0x0EC 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC14__ESAI_SDO3
value|0x0EC 0x320 ALT3 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC14__UART5_TX
value|0x0EC 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC14__SAI2_RX_DATA
value|0x0EC 0x368 ALT5 0x2
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC14__ADC0_SE6
value|0x0EC 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC14__DEBUG_OUT5
value|0x0EC 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC15__GPIO_60
value|0x0F0 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC15__ENET_RMII1_TXD1
value|0x0F0 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC15__ESAI_SDI0
value|0x0F0 0x328 ALT3 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC15__UART5_RX
value|0x0F0 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC15__SAI2_TX_DATA
value|0x0F0 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC15__ADC0_SE7
value|0x0F0 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC15__DEBUG_OUT6
value|0x0F0 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC16__GPIO_61
value|0x0F4 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC16__ENET_RMII1_TXD0
value|0x0F4 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC16__ESAI_SDI1
value|0x0F4 0x324 ALT3 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC16__UART5_RTS
value|0x0F4 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC16__SAI2_RX_SYNC
value|0x0F4 0x36C ALT5 0x2
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC16__ADC1_SE6
value|0x0F4 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC16__DEBUG_OUT7
value|0x0F4 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC17__GPIO_62
value|0x0F8 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC17__ENET_RMII1_TXEN
value|0x0F8 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC17__ADC1_SE7
value|0x0F8 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC17__UART5_CTS
value|0x0F8 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC17__SAI2_TX_SYNC
value|0x0F8 0x374 ALT5 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC17__USB1_SOF_PULSE
value|0x0F8 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC17__DEBUG_OUT8
value|0x0F8 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD31__GPIO_63
value|0x0FC 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD31__FB_AD31
value|0x0FC 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD31__NF_IO15
value|0x0FC 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD31__FTM3_CH0
value|0x0FC 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD31__DSPI2_CS1
value|0x0FC 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD31__DEBUG_OUT9
value|0x0FC 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD30__GPIO_64
value|0x100 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD30__FB_AD30
value|0x100 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD30__NF_IO14
value|0x100 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD30__FTM3_CH1
value|0x100 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD30__DSPI2_CS0
value|0x100 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD30__DEBUG_OUT10
value|0x100 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD29__GPIO_65
value|0x104 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD29__FB_AD29
value|0x104 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD29__NF_IO13
value|0x104 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD29__FTM3_CH2
value|0x104 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD29__DSPI2_SIN
value|0x104 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD29__DEBUG_OUT11
value|0x104 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD28__GPIO_66
value|0x108 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD28__FB_AD28
value|0x108 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD28__NF_IO12
value|0x108 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD28__I2C2_SCL
value|0x108 0x34C ALT3 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD28__FTM3_CH3
value|0x108 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD28__DSPI2_SOUT
value|0x108 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD28__DEBUG_OUT12
value|0x108 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD27__GPIO_67
value|0x10C 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD27__FB_AD27
value|0x10C 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD27__NF_IO11
value|0x10C 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD27__I2C2_SDA
value|0x10C 0x350 ALT3 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD27__FTM3_CH4
value|0x10C 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD27__DSPI2_SCK
value|0x10C 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD27__DEBUG_OUT13
value|0x10C 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD26__GPIO_68
value|0x110 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD26__FB_AD26
value|0x110 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD26__NF_IO10
value|0x110 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD26__FTM3_CH5
value|0x110 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD26__ESDHC1_WP
value|0x110 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD26__DEBUG_OUT14
value|0x110 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD25__GPIO_69
value|0x114 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD25__FB_AD25
value|0x114 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD25__NF_IO9
value|0x114 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD25__FTM3_CH6
value|0x114 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD25__DEBUG_OUT15
value|0x114 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD24__GPIO_70
value|0x118 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD24__FB_AD24
value|0x118 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD24__NF_IO8
value|0x118 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD24__FTM3_CH7
value|0x118 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD24__DEBUG_OUT16
value|0x118 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD23__GPIO_71
value|0x11C 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD23__FB_AD23
value|0x11C 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD23__NF_IO7
value|0x11C 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD23__FTM2_CH0
value|0x11C 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD23__ENET0_1588_TMR0
value|0x11C 0x304 ALT4 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD23__ESDHC0_DAT4
value|0x11C 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD23__UART2_TX
value|0x11C 0x38C ALT6 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD23__DCU1_R3
value|0x11C 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD22__GPIO_72
value|0x120 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD22__FB_AD22
value|0x120 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD22__NF_IO6
value|0x120 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD22__FTM2_CH1
value|0x120 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD22__ENET0_1588_TMR1
value|0x120 0x308 ALT4 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD22__ESDHC0_DAT5
value|0x120 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD22__UART2_RX
value|0x120 0x388 ALT6 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD22__DCU1_R4
value|0x120 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD21__GPIO_73
value|0x124 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD21__FB_AD21
value|0x124 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD21__NF_IO5
value|0x124 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD21__ENET0_1588_TMR2
value|0x124 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD21__ESDHC0_DAT6
value|0x124 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD21__UART2_RTS
value|0x124 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD21__DCU1_R5
value|0x124 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD20__GPIO_74
value|0x128 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD20__FB_AD20
value|0x128 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD20__NF_IO4
value|0x128 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD20__ENET0_1588_TMR3
value|0x128 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD20__ESDHC0_DAT7
value|0x128 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD20__UART2_CTS
value|0x128 0x384 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD20__DCU1_R0
value|0x128 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD19__GPIO_75
value|0x12C 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD19__FB_AD19
value|0x12C 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD19__NF_IO3
value|0x12C 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD19__ESAI_SCKR
value|0x12C 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD19__I2C0_SCL
value|0x12C 0x33C ALT4 0x2
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD19__FTM2_QD_PHA
value|0x12C 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD19__DCU1_R1
value|0x12C 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD18__GPIO_76
value|0x130 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD18__FB_AD18
value|0x130 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD18__NF_IO2
value|0x130 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD18__ESAI_FSR
value|0x130 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD18__I2C0_SDA
value|0x130 0x340 ALT4 0x2
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD18__FTM2_QD_PHB
value|0x130 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD18__DCU1_G0
value|0x130 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD17__GPIO_77
value|0x134 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD17__FB_AD17
value|0x134 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD17__NF_IO1
value|0x134 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD17__ESAI_HCKR
value|0x134 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD17__I2C1_SCL
value|0x134 0x344 ALT4 0x2
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD17__DCU1_G1
value|0x134 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD16__GPIO_78
value|0x138 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD16__FB_AD16
value|0x138 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD16__NF_IO0
value|0x138 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD16__ESAI_HCKT
value|0x138 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD16__I2C1_SDA
value|0x138 0x348 ALT4 0x2
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD16__DCU1_G2
value|0x138 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD0__GPIO_79
value|0x13C 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD0__QSPI0_A_QSCK
value|0x13C 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD0__UART2_TX
value|0x13C 0x38C ALT2 0x2
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD0__FB_AD15
value|0x13C 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD0__SPDIF_EXTCLK
value|0x13C 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD0__DEBUG_OUT17
value|0x13C 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD1__GPIO_80
value|0x140 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD1__QSPI0_A_CS0
value|0x140 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD1__UART2_RX
value|0x140 0x388 ALT2 0x2
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD1__FB_AD14
value|0x140 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD1__SPDIF_IN1
value|0x140 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD1__DEBUG_OUT18
value|0x140 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD2__GPIO_81
value|0x144 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD2__QSPI0_A_DATA3
value|0x144 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD2__UART2_RTS
value|0x144 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD2__DSPI1_CS3
value|0x144 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD2__FB_AD13
value|0x144 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD2__SPDIF_OUT1
value|0x144 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD2__DEBUG_OUT19
value|0x144 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD3__GPIO_82
value|0x148 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD3__QSPI0_A_DATA2
value|0x148 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD3__UART2_CTS
value|0x148 0x384 ALT2 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD3__DSPI1_CS2
value|0x148 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD3__FB_AD12
value|0x148 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD3__SPDIF_PLOCK
value|0x148 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD3__DEBUG_OUT20
value|0x148 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD4__GPIO_83
value|0x14C 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD4__QSPI0_A_DATA1
value|0x14C 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD4__DSPI1_CS1
value|0x14C 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD4__FB_AD11
value|0x14C 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD4__SPDIF_SRCLK
value|0x14C 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD4__DEBUG_OUT21
value|0x14C 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD5__GPIO_84
value|0x150 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD5__QSPI0_A_DATA0
value|0x150 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD5__DSPI1_CS0
value|0x150 0x300 ALT3 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD5__FB_AD10
value|0x150 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD5__DEBUG_OUT22
value|0x150 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD6__GPIO_85
value|0x154 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD6__QSPI1_A_DQS
value|0x154 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD6__DSPI1_SIN
value|0x154 0x2FC ALT3 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD6__FB_AD9
value|0x154 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD6__DEBUG_OUT23
value|0x154 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD7__GPIO_86
value|0x158 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD7__QSPI0_B_QSCK
value|0x158 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD7__DSPI1_SOUT
value|0x158 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD7__FB_AD8
value|0x158 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD7__DEBUG_OUT24
value|0x158 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD8__GPIO_87
value|0x15C 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD8__QSPI0_B_CS0
value|0x15C 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD8__FB_CLKOUT
value|0x15C 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD8__DSPI1_SCK
value|0x15C 0x2F8 ALT3 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD8__FB_AD7
value|0x15C 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD8__DEBUG_OUT25
value|0x15C 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD9__GPIO_88
value|0x160 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD9__QSPI0_B_DATA3
value|0x160 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD9__DSPI3_CS1
value|0x160 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD9__FB_AD6
value|0x160 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD9__SAI1_TX_SYNC
value|0x160 0x360 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD9__DCU1_B0
value|0x160 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD10__GPIO_89
value|0x164 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD10__QSPI0_B_DATA2
value|0x164 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD10__DSPI3_CS0
value|0x164 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD10__FB_AD5
value|0x164 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD10__DCU1_B1
value|0x164 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD11__GPIO_90
value|0x168 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD11__QSPI0_B_DATA1
value|0x168 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD11__DSPI3_SIN
value|0x168 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD11__FB_AD4
value|0x168 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD11__DEBUG_OUT26
value|0x168 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD12__GPIO_91
value|0x16C 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD12__QSPI0_B_DATA0
value|0x16C 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD12__DSPI3_SOUT
value|0x16C 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD12__FB_AD3
value|0x16C 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD12__DEBUG_OUT27
value|0x16C 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD13__GPIO_92
value|0x170 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD13__QSPI0_B_DQS
value|0x170 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD13__DSPI3_SCK
value|0x170 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD13__FB_AD2
value|0x170 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTD13__DEBUG_OUT28
value|0x170 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB23__GPIO_93
value|0x174 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB23__SAI0_TX_BCLK
value|0x174 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB23__UART1_TX
value|0x174 0x380 ALT2 0x2
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB23__SRC_RCON18
value|0x174 0x398 ALT3 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB23__FB_MUXED_ALE
value|0x174 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB23__FB_TS_B
value|0x174 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB23__UART3_RTS
value|0x174 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB23__DCU1_G3
value|0x174 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB24__GPIO_94
value|0x178 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB24__SAI0_RX_BCLK
value|0x178 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB24__UART1_RX
value|0x178 0x37C ALT2 0x2
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB24__SRC_RCON19
value|0x178 0x39C ALT3 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB24__FB_MUXED_TSIZ0
value|0x178 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB24__NF_WE_B
value|0x178 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB24__UART3_CTS
value|0x178 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB24__DCU1_G4
value|0x178 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB25__GPIO_95
value|0x17C 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB25__SAI0_RX_DATA
value|0x17C 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB25__UART1_RTS
value|0x17C 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB25__SRC_RCON20
value|0x17C 0x3A0 ALT3 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB25__FB_CS1_B
value|0x17C 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB25__NF_CE0_B
value|0x17C 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB25__DCU1_G5
value|0x17C 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB26__GPIO_96
value|0x180 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB26__SAI0_TX_DATA
value|0x180 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB26__UART1_CTS
value|0x180 0x378 ALT2 0x2
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB26__SRC_RCON21
value|0x180 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB26__FB_CS0_B
value|0x180 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB26__NF_CE1_B
value|0x180 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB26__DCU1_G6
value|0x180 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB27__GPIO_97
value|0x184 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB27__SAI0_RX_SYNC
value|0x184 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB27__SRC_RCON22
value|0x184 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB27__FB_OE_B
value|0x184 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB27__FB_MUXED_TBST_B
value|0x184 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB27__NF_RE_B
value|0x184 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB27__DCU1_G7
value|0x184 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB28__GPIO_98
value|0x188 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB28__SAI0_TX_SYNC
value|0x188 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB28__SRC_RCON23
value|0x188 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB28__FB_RW_B
value|0x188 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTB28__DCU1_B6
value|0x188 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC26__GPIO_99
value|0x18C 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC26__SAI1_TX_BCLK
value|0x18C 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC26__DSPI0_CS5
value|0x18C 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC26__SRC_RCON24
value|0x18C 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC26__FB_TA_B
value|0x18C 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC26__NF_RB_B
value|0x18C 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC26__DCU1_B7
value|0x18C 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC27__GPIO_100
value|0x190 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC27__SAI1_RX_BCLK
value|0x190 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC27__DSPI0_CS4
value|0x190 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC27__SRC_RCON25
value|0x190 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC27__FB_BE3_B
value|0x190 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC27__FB_CS3_B
value|0x190 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC27__NF_ALE
value|0x190 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC27__DCU1_B2
value|0x190 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC28__GPIO_101
value|0x194 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC28__SAI1_RX_DATA
value|0x194 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC28__DSPI0_CS3
value|0x194 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC28__SRC_RCON26
value|0x194 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC28__FB_BE2_B
value|0x194 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC28__FB_CS2_B
value|0x194 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC28__NF_CLE
value|0x194 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC28__DCU1_B3
value|0x194 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC29__GPIO_102
value|0x198 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC29__SAI1_TX_DATA
value|0x198 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC29__DSPI0_CS2
value|0x198 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC29__SRC_RCON27
value|0x198 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC29__FB_BE1_B
value|0x198 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC29__FB_MUXED_TSIZE1
value|0x198 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC29__DCU1_B4
value|0x198 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC30__GPIO_103
value|0x19C 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC30__SAI1_RX_SYNC
value|0x19C 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC30__DSPI1_CS2
value|0x19C 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC30__SRC_RCON28
value|0x19C 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC30__FB_MUXED_BE0_B
value|0x19C 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC30__FB_TSIZ0
value|0x19C 0x000 ALT5 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC30__ADC0_SE5
value|0x19C 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC30__DCU1_B5
value|0x19C 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC31__GPIO_104
value|0x1A0 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC31__SAI1_TX_SYNC
value|0x1A0 0x360 ALT1 0x1
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC31__SRC_RCON29
value|0x1A0 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC31__ADC1_SE5
value|0x1A0 0x000 ALT6 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTC31__DCU1_B6
value|0x1A0 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE0__GPIO_105
value|0x1A4 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE0__DCU0_HSYNC
value|0x1A4 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE0__SRC_BMODE1
value|0x1A4 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE0__LCD0
value|0x1A4 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE0__DEBUG_OUT29
value|0x1A4 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE1__GPIO_106
value|0x1A8 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE1__DCU0_VSYNC
value|0x1A8 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE1__SRC_BMODE0
value|0x1A8 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE1__LCD1
value|0x1A8 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE1__DEBUG_OUT30
value|0x1A8 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE2__GPIO_107
value|0x1AC 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE2__DCU0_PCLK
value|0x1AC 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE2__LCD2
value|0x1AC 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE2__DEBUG_OUT31
value|0x1AC 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE3__GPIO_108
value|0x1B0 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE3__DCU0_TAG
value|0x1B0 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE3__LCD3
value|0x1B0 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE3__DEBUG_OUT32
value|0x1B0 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE4__GPIO_109
value|0x1B4 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE4__DCU0_DE
value|0x1B4 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE4__LCD4
value|0x1B4 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE4__DEBUG_OUT33
value|0x1B4 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE5__GPIO_110
value|0x1B8 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE5__DCU0_R0
value|0x1B8 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE5__LCD5
value|0x1B8 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE5__DEBUG_OUT34
value|0x1B8 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE6__GPIO_111
value|0x1BC 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE6__DCU0_R1
value|0x1BC 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE6__LCD6
value|0x1BC 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE6__DEBUG_OUT35
value|0x1BC 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE7__GPIO_112
value|0x1C0 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE7__DCU0_R2
value|0x1C0 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE7__SRC_RCON0
value|0x1C0 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE7__LCD7
value|0x1C0 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE7__DEBUG_OUT36
value|0x1C0 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE8__GPIO_113
value|0x1C4 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE8__DCU0_R3
value|0x1C4 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE8__SRC_RCON1
value|0x1C4 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE8__LCD8
value|0x1C4 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE8__DEBUG_OUT37
value|0x1C4 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE9__GPIO_114
value|0x1C8 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE9__DCU0_R4
value|0x1C8 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE9__SRC_RCON2
value|0x1C8 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE9__LCD9
value|0x1C8 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE9__DEBUG_OUT38
value|0x1C8 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE10__GPIO_115
value|0x1CC 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE10__DCU0_R5
value|0x1CC 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE10__SRC_RCON3
value|0x1CC 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE10__LCD10
value|0x1CC 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE10__DEBUG_OUT39
value|0x1CC 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE11__GPIO_116
value|0x1D0 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE11__DCU0_R6
value|0x1D0 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE11__SRC_RCON4
value|0x1D0 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE11__LCD11
value|0x1D0 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE11__DEBUG_OUT40
value|0x1D0 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE12__GPIO_117
value|0x1D4 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE12__DCU0_R7
value|0x1D4 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE12__DSPI1_CS3
value|0x1D4 0x000 ALT2 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE12__SRC_RCON5
value|0x1D4 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE12__LCD12
value|0x1D4 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE12__LPT_ALT0
value|0x1D4 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE13__GPIO_118
value|0x1D8 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE13__DCU0_G0
value|0x1D8 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE13__LCD13
value|0x1D8 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE13__DEBUG_OUT41
value|0x1D8 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE14__GPIO_119
value|0x1DC 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE14__DCU0_G1
value|0x1DC 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE14__LCD14
value|0x1DC 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE14__DEBUG_OUT42
value|0x1DC 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE15__GPIO_120
value|0x1E0 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE15__DCU0_G2
value|0x1E0 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE15__SRC_RCON6
value|0x1E0 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE15__LCD15
value|0x1E0 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE15__DEBUG_OUT43
value|0x1E0 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE16__GPIO_121
value|0x1E4 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE16__DCU0_G3
value|0x1E4 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE16__SRC_RCON7
value|0x1E4 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE16__LCD16
value|0x1E4 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE17__GPIO_122
value|0x1E8 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE17__DCU0_G4
value|0x1E8 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE17__SRC_RCON8
value|0x1E8 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE17__LCD17
value|0x1E8 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE18__GPIO_123
value|0x1EC 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE18__DCU0_G5
value|0x1EC 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE18__SRC_RCON9
value|0x1EC 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE18__LCD18
value|0x1EC 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE19__GPIO_124
value|0x1F0 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE19__DCU0_G6
value|0x1F0 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE19__SRC_RCON10
value|0x1F0 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE19__LCD19
value|0x1F0 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE19__I2C0_SCL
value|0x1F0 0x33C ALT5 0x3
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE20__GPIO_125
value|0x1F4 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE20__DCU0_G7
value|0x1F4 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE20__SRC_RCON11
value|0x1F4 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE20__LCD20
value|0x1F4 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE20__I2C0_SDA
value|0x1F4 0x340 ALT5 0x3
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE20__EWM_IN
value|0x1F4 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE21__GPIO_126
value|0x1F8 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE21__DCU0_B0
value|0x1F8 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE21__LCD21
value|0x1F8 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE22__GPIO_127
value|0x1FC 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE22__DCU0_B1
value|0x1FC 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE22__LCD22
value|0x1FC 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE23__GPIO_128
value|0x200 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE23__DCU0_B2
value|0x200 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE23__SRC_RCON12
value|0x200 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE23__LCD23
value|0x200 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE24__GPIO_129
value|0x204 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE24__DCU0_B3
value|0x204 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE24__SRC_RCON13
value|0x204 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE24__LCD24
value|0x204 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE25__GPIO_130
value|0x208 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE25__DCU0_B4
value|0x208 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE25__SRC_RCON14
value|0x208 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE25__LCD25
value|0x208 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE26__GPIO_131
value|0x20C 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE26__DCU0_B5
value|0x20C 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE26__SRC_RCON15
value|0x20C 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE26__LCD26
value|0x20C 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE27__GPIO_132
value|0x210 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE27__DCU0_B6
value|0x210 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE27__SRC_RCON16
value|0x210 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE27__LCD27
value|0x210 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE27__I2C1_SCL
value|0x210 0x344 ALT5 0x3
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE28__GPIO_133
value|0x214 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE28__DCU0_B7
value|0x214 0x000 ALT1 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE28__SRC_RCON17
value|0x214 0x000 ALT3 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE28__LCD28
value|0x214 0x000 ALT4 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE28__I2C1_SDA
value|0x214 0x348 ALT5 0x3
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTE28__EWM_OUT
value|0x214 0x000 ALT7 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA7__GPIO_134
value|0x218 0x000 ALT0 0x0
end_define

begin_define
define|#
directive|define
name|VF610_PAD_PTA7__VIU_PIX_CLK
value|0x218 0x3AC ALT1 0x1
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

