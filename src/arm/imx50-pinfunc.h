begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2013 Greg Ungerer<gerg@uclinux.org>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DTS_IMX50_PINFUNC_H
end_ifndef

begin_define
define|#
directive|define
name|__DTS_IMX50_PINFUNC_H
end_define

begin_comment
comment|/*  * The pin function ID is a tuple of  *<mux_reg conf_reg input_reg mux_mode input_val>  */
end_comment

begin_define
define|#
directive|define
name|MX50_PAD_KEY_COL0__KPP_COL_0
value|0x020 0x2cc 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_KEY_COL0__GPIO4_0
value|0x020 0x2cc 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_KEY_COL0__EIM_NANDF_CLE
value|0x020 0x2cc 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_KEY_COL0__CTI_TRIGIN7
value|0x020 0x2cc 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_KEY_COL0__USBPHY1_TXREADY
value|0x020 0x2cc 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_KEY_ROW0__KPP_ROW_0
value|0x024 0x2d0 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_KEY_ROW0__GPIO4_1
value|0x024 0x2d0 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_KEY_ROW0__EIM_NANDF_ALE
value|0x024 0x2d0 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_KEY_ROW0__CTI_TRIGIN_ACK7
value|0x024 0x2d0 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_KEY_ROW0__USBPHY1_RXVALID
value|0x024 0x2d0 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_KEY_COL1__KPP_COL_1
value|0x028 0x2d4 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_KEY_COL1__GPIO4_2
value|0x028 0x2d4 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_KEY_COL1__EIM_NANDF_CEN_0
value|0x028 0x2d4 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_KEY_COL1__CTI_TRIGOUT_ACK6
value|0x028 0x2d4 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_KEY_COL1__USBPHY1_RXACTIVE
value|0x028 0x2d4 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_KEY_ROW1__KPP_ROW_1
value|0x02c 0x2d8 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_KEY_ROW1__GPIO4_3
value|0x02c 0x2d8 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_KEY_ROW1__EIM_NANDF_CEN_1
value|0x02c 0x2d8 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_KEY_ROW1__CTI_TRIGOUT_ACK7
value|0x02c 0x2d8 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_KEY_ROW1__USBPHY1_RXERROR
value|0x02c 0x2d8 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_KEY_COL2__KPP_COL_1
value|0x030 0x2dc 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_KEY_COL2__GPIO4_4
value|0x030 0x2dc 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_KEY_COL2__EIM_NANDF_CEN_2
value|0x030 0x2dc 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_KEY_COL2__CTI_TRIGOUT6
value|0x030 0x2dc 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_KEY_COL2__USBPHY1_SIECLOCK
value|0x030 0x2dc 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_KEY_ROW2__KPP_ROW_2
value|0x034 0x2e0 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_KEY_ROW2__GPIO4_5
value|0x034 0x2e0 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_KEY_ROW2__EIM_NANDF_CEN_3
value|0x034 0x2e0 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_KEY_ROW2__CTI_TRIGOUT7
value|0x034 0x2e0 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_KEY_ROW2__USBPHY1_LINESTATE_0
value|0x034 0x2e0 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_KEY_COL3__KPP_COL_2
value|0x038 0x2e4 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_KEY_COL3__GPIO4_6
value|0x038 0x2e4 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_KEY_COL3__EIM_NANDF_READY0
value|0x038 0x2e4 0x7b4 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_KEY_COL3__SDMA_EXT_EVENT_0
value|0x038 0x2e4 0x7b8 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_KEY_COL3__USBPHY1_LINESTATE_1
value|0x038 0x2e4 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_KEY_ROW3__KPP_ROW_3
value|0x03c 0x2e8 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_KEY_ROW3__GPIO4_7
value|0x03c 0x2e8 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_KEY_ROW3__EIM_NANDF_DQS
value|0x03c 0x2e8 0x7b0 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_KEY_ROW3__SDMA_EXT_EVENT_1
value|0x03c 0x2e8 0x7bc 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_KEY_ROW3__USBPHY1_VBUSVALID
value|0x03c 0x2e8 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_I2C1_SCL__I2C1_SCL
value|0x040 0x2ec 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_I2C1_SCL__GPIO6_18
value|0x040 0x2ec 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_I2C1_SCL__UART2_TXD_MUX
value|0x040 0x2ec 0x7cc 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_I2C1_SDA__I2C1_SDA
value|0x044 0x2f0 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_I2C1_SDA__GPIO6_19
value|0x044 0x2f0 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_I2C1_SDA__UART2_RXD_MUX
value|0x044 0x2f0 0x7cc 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_I2C2_SCL__I2C2_SCL
value|0x048 0x2f4 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_I2C2_SCL__GPIO6_20
value|0x048 0x2f4 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_I2C2_SCL__UART2_CTS
value|0x048 0x2f4 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_I2C2_SDA__I2C2_SDA
value|0x04c 0x2f8 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_I2C2_SDA__GPIO6_21
value|0x04c 0x2f8 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_I2C2_SDA__UART2_RTS
value|0x04c 0x2f8 0x7c8 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_I2C3_SCL__I2C3_SCL
value|0x050 0x2fc 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_I2C3_SCL__GPIO6_22
value|0x050 0x2fc 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_I2C3_SCL__FEC_MDC
value|0x050 0x2fc 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_I2C3_SCL__GPC_PMIC_RDY
value|0x050 0x2fc 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_I2C3_SCL__GPT_CAPIN1
value|0x050 0x2fc 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_I2C3_SCL__OBSERVE_MUX_OBSRV_INT_OUT0
value|0x050 0x2fc 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_I2C3_SCL__USBOH1_USBOTG_OC
value|0x050 0x2fc 0x7e8 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_I2C3_SDA__I2C3_SDA
value|0x054 0x300 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_I2C3_SDA__GPIO6_23
value|0x054 0x300 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_I2C3_SDA__FEC_MDIO
value|0x054 0x300 0x774 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_I2C3_SDA__TZIC_PWRFAIL_INT
value|0x054 0x300 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_I2C3_SDA__SRTC_ALARM_DEB
value|0x054 0x300 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_I2C3_SDA__GPT_CAPIN2
value|0x054 0x300 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_I2C3_SDA__OBSERVE_MUX_OBSRV_INT_OUT1
value|0x054 0x300 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_I2C3_SDA__USBOH1_USBOTG_PWR
value|0x054 0x300 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_PWM1__PWM1_PWMO
value|0x058 0x304 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_PWM1__GPIO6_24
value|0x058 0x304 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_PWM1__USBOH1_USBOTG_OC
value|0x058 0x304 0x7e8 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_PWM1__GPT_CMPOUT1
value|0x058 0x304 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_PWM1__OBSERVE_MUX_OBSRV_INT_OUT2
value|0x058 0x304 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_PWM1__SJC_FAIL
value|0x058 0x304 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_PWM2__PWM2_PWMO
value|0x05c 0x308 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_PWM2__GPIO6_25
value|0x05c 0x308 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_PWM2__USBOH1_USBOTG_PWR
value|0x05c 0x308 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_PWM2__GPT_CMPOUT2
value|0x05c 0x308 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_PWM2__OBSERVE_MUX_OBSRV_INT_OUT3
value|0x05c 0x308 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_PWM2__SRC_ANY_PU_RST
value|0x05c 0x308 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_OWIRE__OWIRE_LINE
value|0x060 0x30c 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_OWIRE__GPIO6_26
value|0x060 0x30c 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_OWIRE__USBOH1_USBH1_OC
value|0x060 0x30c 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_OWIRE__CCM_SSI_EXT1_CLK
value|0x060 0x30c 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_OWIRE__EPDC_PWRIRQ
value|0x060 0x30c 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_OWIRE__GPT_CMPOUT3
value|0x060 0x30c 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_OWIRE__OBSERVE_MUX_OBSRV_INT_OUT4
value|0x060 0x30c 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_OWIRE__SJC_JTAG_ACT
value|0x060 0x30c 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPITO__EPIT1_EPITO
value|0x064 0x310 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPITO__GPIO6_27
value|0x064 0x310 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPITO__USBOH1_USBH1_PWR
value|0x064 0x310 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPITO__CCM_SSI_EXT2_CLK
value|0x064 0x310 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPITO__DPLLIP1_TOG_EN
value|0x064 0x310 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPITO__GPT_CLK_IN
value|0x064 0x310 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPITO__PMU_IRQ_B
value|0x064 0x310 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPITO__SJC_DE_B
value|0x064 0x310 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_WDOG__WDOG1_WDOG_B
value|0x068 0x314 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_WDOG__GPIO6_28
value|0x068 0x314 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_WDOG__WDOG1_WDOG_RST_B_DEB
value|0x068 0x314 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_WDOG__CCM_XTAL32K
value|0x068 0x314 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_WDOG__SJC_DONE
value|0x068 0x314 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SSI_TXFS__AUDMUX_AUD3_TXFS
value|0x06c 0x318 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SSI_TXFS__GPIO6_0
value|0x06c 0x318 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SSI_TXFS__SRC_BT_FUSE_RSV_1
value|0x06c 0x318 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SSI_TXFS__USBPHY1_DATAOUT_8
value|0x06c 0x318 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SSI_TXC__AUDMUX_AUD3_TXC
value|0x070 0x31c 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SSI_TXC__GPIO6_1
value|0x070 0x31c 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SSI_TXC__SRC_BT_FUSE_RSV_0
value|0x070 0x31c 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SSI_TXC__USBPHY1_DATAOUT_9
value|0x070 0x31c 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SSI_TXD__AUDMUX_AUD3_TXD
value|0x074 0x320 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SSI_TXD__GPIO6_2
value|0x074 0x320 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SSI_TXD__CSPI_RDY
value|0x074 0x320 0x6e8 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SSI_TXD__USBPHY1_DATAOUT_10
value|0x074 0x320 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SSI_RXD__AUDMUX_AUD3_RXD
value|0x078 0x324 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SSI_RXD__GPIO6_3
value|0x078 0x324 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SSI_RXD__CSPI_SS3
value|0x078 0x324 0x6f4 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SSI_RXD__USBPHY1_DATAOUT_11
value|0x078 0x324 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SSI_RXFS__AUDMUX_AUD3_RXFS
value|0x07c 0x328 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SSI_RXFS__GPIO6_4
value|0x07c 0x328 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SSI_RXFS__UART5_TXD_MUX
value|0x07c 0x328 0x7e4 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SSI_RXFS__EIM_WEIM_D_6
value|0x07c 0x328 0x804 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SSI_RXFS__CSPI_SS2
value|0x07c 0x328 0x6f0 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SSI_RXFS__FEC_COL
value|0x07c 0x328 0x770 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SSI_RXFS__FEC_MDC
value|0x07c 0x328 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SSI_RXFS__USBPHY1_DATAOUT_12
value|0x07c 0x328 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SSI_RXC__AUDMUX_AUD3_RXC
value|0x080 0x32c 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SSI_RXC__GPIO6_5
value|0x080 0x32c 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SSI_RXC__UART5_RXD_MUX
value|0x080 0x32c 0x7e4 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SSI_RXC__EIM_WEIM_D_7
value|0x080 0x32c 0x808 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SSI_RXC__CSPI_SS1
value|0x080 0x32c 0x6ec 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SSI_RXC__FEC_RX_CLK
value|0x080 0x32c 0x780 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SSI_RXC__FEC_MDIO
value|0x080 0x32c 0x774 0x6 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SSI_RXC__USBPHY1_DATAOUT_13
value|0x080 0x32c 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART1_TXD__UART1_TXD_MUX
value|0x084 0x330 0x7c4 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART1_TXD__GPIO6_6
value|0x084 0x330 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART1_TXD__USBPHY1_DATAOUT_14
value|0x084 0x330 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART1_RXD__UART1_RXD_MUX
value|0x088 0x334 0x7c4 0x0 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART1_RXD__GPIO6_7
value|0x088 0x334 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART1_RXD__USBPHY1_DATAOUT_15
value|0x088 0x334 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART1_CTS__UART1_CTS
value|0x08c 0x338 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART1_CTS__GPIO6_8
value|0x08c 0x338 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART1_CTS__UART5_TXD_MUX
value|0x08c 0x338 0x7e4 0x2 0x2
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART1_CTS__ESDHC4_DAT4
value|0x08c 0x338 0x760 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART1_CTS__ESDHC4_CMD
value|0x08c 0x338 0x74c 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART1_CTS__USBPHY2_DATAOUT_8
value|0x08c 0x338 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART1_RTS__UART1_RTS
value|0x090 0x33c 0x7c0 0x0 0x3
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART1_RTS__GPIO6_9
value|0x090 0x33c 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART1_RTS__UART5_RXD_MUX
value|0x090 0x33c 0x7e4 0x2 0x3
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART1_RTS__ESDHC4_DAT5
value|0x090 0x33c 0x764 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART1_RTS__ESDHC4_CLK
value|0x090 0x33c 0x748 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART1_RTS__USBPHY2_DATAOUT_9
value|0x090 0x33c 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART2_TXD__UART2_TXD_MUX
value|0x094 0x340 0x7cc 0x0 0x2
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART2_TXD__GPIO6_10
value|0x094 0x340 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART2_TXD__ESDHC4_DAT6
value|0x094 0x340 0x768 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART2_TXD__ESDHC4_DAT4
value|0x094 0x340 0x760 0x5 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART2_TXD__USBPHY2_DATAOUT_10
value|0x094 0x340 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART2_RXD__UART2_RXD_MUX
value|0x098 0x344 0x7cc 0x0 0x3
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART2_RXD__GPIO6_11
value|0x098 0x344 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART2_RXD__ESDHC4_DAT7
value|0x098 0x344 0x76c 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART2_RXD__ESDHC4_DAT5
value|0x098 0x344 0x764 0x5 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART2_RXD__USBPHY2_DATAOUT_11
value|0x098 0x344 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART2_CTS__UART2_CTS
value|0x09c 0x348 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART2_CTS__GPIO6_12
value|0x09c 0x348 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART2_CTS__ESDHC4_CMD
value|0x09c 0x348 0x74c 0x4 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART2_CTS__ESDHC4_DAT6
value|0x09c 0x348 0x768 0x5 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART2_CTS__USBPHY2_DATAOUT_12
value|0x09c 0x348 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART2_RTS__UART2_RTS
value|0x0a0 0x34c 0x7c8 0x0 0x2
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART2_RTS__GPIO6_13
value|0x0a0 0x34c 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART2_RTS__ESDHC4_CLK
value|0x0a0 0x34c 0x748 0x4 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART2_RTS__ESDHC4_DAT7
value|0x0a0 0x34c 0x76c 0x5 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART2_RTS__USBPHY2_DATAOUT_13
value|0x0a0 0x34c 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART3_TXD__UART3_TXD_MUX
value|0x0a4 0x350 0x7d4 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART3_TXD__GPIO6_14
value|0x0a4 0x350 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART3_TXD__ESDHC1_DAT4
value|0x0a4 0x350 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART3_TXD__ESDHC4_DAT0
value|0x0a4 0x350 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART3_TXD__ESDHC2_WP
value|0x0a4 0x350 0x744 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART3_TXD__EIM_WEIM_D_12
value|0x0a4 0x350 0x81c 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART3_TXD__USBPHY2_DATAOUT_14
value|0x0a4 0x350 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART3_RXD__UART3_RXD_MUX
value|0x0a8 0x354 0x7d4 0x0 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART3_RXD__GPIO6_15
value|0x0a8 0x354 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART3_RXD__ESDHC1_DAT5
value|0x0a8 0x354 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART3_RXD__ESDHC4_DAT1
value|0x0a8 0x354 0x754 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART3_RXD__ESDHC2_CD
value|0x0a8 0x354 0x740 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART3_RXD__EIM_WEIM_D_13
value|0x0a8 0x354 0x820 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART3_RXD__USBPHY2_DATAOUT_15
value|0x0a8 0x354 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART4_TXD__UART4_TXD_MUX
value|0x0ac 0x358 0x7dc 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART4_TXD__GPIO6_16
value|0x0ac 0x358 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART4_TXD__UART3_CTS
value|0x0ac 0x358 0x7d0 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART4_TXD__ESDHC1_DAT6
value|0x0ac 0x358 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART4_TXD__ESDHC4_DAT2
value|0x0ac 0x358 0x758 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART4_TXD__ESDHC2_LCTL
value|0x0ac 0x358 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART4_TXD__EIM_WEIM_D_14
value|0x0ac 0x358 0x824 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART4_RXD__UART4_RXD_MUX
value|0x0b0 0x35c 0x7dc 0x0 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART4_RXD__GPIO6_17
value|0x0b0 0x35c 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART4_RXD__UART3_RTS
value|0x0b0 0x35c 0x7d0 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART4_RXD__ESDHC1_DAT7
value|0x0b0 0x35c 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART4_RXD__ESDHC4_DAT3
value|0x0b0 0x35c 0x75c 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART4_RXD__ESDHC1_LCTL
value|0x0b0 0x35c 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_UART4_RXD__EIM_WEIM_D_15
value|0x0b0 0x35c 0x828 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_CSPI_SCLK__CSPI_SCLK
value|0x0b4 0x360 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_CSPI_SCLK__GPIO4_8
value|0x0b4 0x360 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_CSPI_MOSI__CSPI_MOSI
value|0x0b8 0x364 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_CSPI_MOSI__GPIO4_9
value|0x0b8 0x364 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_CSPI_MISO__CSPI_MISO
value|0x0bc 0x368 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_CSPI_MISO__GPIO4_10
value|0x0bc 0x368 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_CSPI_SS0__CSPI_SS0
value|0x0c0 0x36c 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_CSPI_SS0__GPIO4_11
value|0x0c0 0x36c 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI1_SCLK__ECSPI1_SCLK
value|0x0c4 0x370 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI1_SCLK__GPIO4_12
value|0x0c4 0x370 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI1_SCLK__CSPI_RDY
value|0x0c4 0x370 0x6e8 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI1_SCLK__ECSPI2_RDY
value|0x0c4 0x370 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI1_SCLK__UART3_RTS
value|0x0c4 0x370 0x7d0 0x4 0x2
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI1_SCLK__EPDC_SDCE_6
value|0x0c4 0x370 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI1_SCLK__EIM_WEIM_D_8
value|0x0c4 0x370 0x80c 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI1_MOSI__ECSPI1_MOSI
value|0x0c8 0x374 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI1_MOSI__GPIO4_13
value|0x0c8 0x374 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI1_MOSI__CSPI_SS1
value|0x0c8 0x374 0x6ec 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI1_MOSI__ECSPI2_SS1
value|0x0c8 0x374 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI1_MOSI__UART3_CTS
value|0x0c8 0x374 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI1_MOSI__EPDC_SDCE_7
value|0x0c8 0x374 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI1_MOSI__EIM_WEIM_D_9
value|0x0c8 0x374 0x810 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI1_MISO__ECSPI1_MISO
value|0x0cc 0x378 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI1_MISO__GPIO4_14
value|0x0cc 0x378 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI1_MISO__CSPI_SS2
value|0x0cc 0x378 0x6f0 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI1_MISO__ECSPI2_SS2
value|0x0cc 0x378 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI1_MISO__UART4_RTS
value|0x0cc 0x378 0x7d8 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI1_MISO__EPDC_SDCE_8
value|0x0cc 0x378 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI1_MISO__EIM_WEIM_D_10
value|0x0cc 0x378 0x814 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI1_SS0__ECSPI1_SS0
value|0x0d0 0x37c 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI1_SS0__GPIO4_15
value|0x0d0 0x37c 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI1_SS0__CSPI_SS3
value|0x0d0 0x37c 0x6f4 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI1_SS0__ECSPI2_SS3
value|0x0d0 0x37c 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI1_SS0__UART4_CTS
value|0x0d0 0x37c 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI1_SS0__EPDC_SDCE_9
value|0x0d0 0x37c 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI1_SS0__EIM_WEIM_D_11
value|0x0d0 0x37c 0x818 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI2_SCLK__ECSPI2_SCLK
value|0x0d4 0x380 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI2_SCLK__GPIO4_16
value|0x0d4 0x380 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI2_SCLK__ELCDIF_WR_RWN
value|0x0d4 0x380 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI2_SCLK__ECSPI1_RDY
value|0x0d4 0x380 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI2_SCLK__UART5_RTS
value|0x0d4 0x380 0x7e0 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI2_SCLK__ELCDIF_DOTCLK
value|0x0d4 0x380 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI2_SCLK__EIM_NANDF_CEN_4
value|0x0d4 0x380 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI2_SCLK__EIM_WEIM_D_8
value|0x0d4 0x380 0x80c 0x7 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI2_MOSI__ECSPI2_MOSI
value|0x0d8 0x384 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI2_MOSI__GPIO4_17
value|0x0d8 0x384 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI2_MOSI__ELCDIF_RE_E
value|0x0d8 0x384 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI2_MOSI__ECSPI1_SS1
value|0x0d8 0x384 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI2_MOSI__UART5_CTS
value|0x0d8 0x384 0x7e0 0x4 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI2_MOSI__ELCDIF_ENABLE
value|0x0d8 0x384 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI2_MOSI__EIM_NANDF_CEN_5
value|0x0d8 0x384 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI2_MOSI__EIM_WEIM_D_9
value|0x0d8 0x384 0x810 0x7 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI2_MISO__ECSPI2_MISO
value|0x0dc 0x388 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI2_MISO__GPIO4_18
value|0x0dc 0x388 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI2_MISO__ELCDIF_RS
value|0x0dc 0x388 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI2_MISO__ECSPI1_SS2
value|0x0dc 0x388 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI2_MISO__UART5_TXD_MUX
value|0x0dc 0x388 0x7e4 0x4 0x4
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI2_MISO__ELCDIF_VSYNC
value|0x0dc 0x388 0x73c 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI2_MISO__EIM_NANDF_CEN_6
value|0x0dc 0x388 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI2_MISO__EIM_WEIM_D_10
value|0x0dc 0x388 0x814 0x7 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI2_SS0__ECSPI2_SS0
value|0x0e0 0x38c 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI2_SS0__GPIO4_19
value|0x0e0 0x38c 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI2_SS0__ELCDIF_CS
value|0x0e0 0x38c 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI2_SS0__ECSPI2_SS3
value|0x0e0 0x38c 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI2_SS0__UART5_RXD_MUX
value|0x0e0 0x38c 0x7e4 0x4 0x5
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI2_SS0__ELCDIF_HSYNC
value|0x0e0 0x38c 0x6f8 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI2_SS0__EIM_NANDF_CEN_7
value|0x0e0 0x38c 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_ECSPI2_SS0__EIM_WEIM_D_11
value|0x0e0 0x38c 0x818 0x7 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD1_CLK__ESDHC1_CLK
value|0x0e4 0x390 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD1_CLK__GPIO5_0
value|0x0e4 0x390 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD1_CLK__CCM_CLKO
value|0x0e4 0x390 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD1_CMD__ESDHC1_CMD
value|0x0e8 0x394 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD1_CMD__GPIO5_1
value|0x0e8 0x394 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD1_CMD__CCM_CLKO2
value|0x0e8 0x394 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD1_D0__ESDHC1_DAT0
value|0x0ec 0x398 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD1_D0__GPIO5_2
value|0x0ec 0x398 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD1_D0__CCM_PLL1_BYP
value|0x0ec 0x398 0x6dc 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD1_D1__ESDHC1_DAT1
value|0x0f0 0x39c 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD1_D1__GPIO5_3
value|0x0f0 0x39c 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD1_D1__CCM_PLL2_BYP
value|0x0f0 0x39c 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD1_D2__ESDHC1_DAT2
value|0x0f4 0x3a0 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD1_D2__GPIO5_4
value|0x0f4 0x3a0 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD1_D2__CCM_PLL3_BYP
value|0x0f4 0x3a0 0x6e4 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD1_D3__ESDHC1_DAT3
value|0x0f8 0x3a4 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD1_D3__GPIO5_5
value|0x0f8 0x3a4 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_CLK__ESDHC2_CLK
value|0x0fc 0x3a8 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_CLK__GPIO5_6
value|0x0fc 0x3a8 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_CLK__MSHC_SCLK
value|0x0fc 0x3a8 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_CMD__ESDHC2_CMD
value|0x100 0x3ac 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_CMD__GPIO5_7
value|0x100 0x3ac 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_CMD__MSHC_BS
value|0x100 0x3ac 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_D0__ESDHC2_DAT0
value|0x104 0x3b0 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_D0__GPIO5_8
value|0x104 0x3b0 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_D0__MSHC_DATA_0
value|0x104 0x3b0 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_D0__KPP_COL_4
value|0x104 0x3b0 0x790 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_D1__ESDHC2_DAT1
value|0x108 0x3b4 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_D1__GPIO5_9
value|0x108 0x3b4 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_D1__MSHC_DATA_1
value|0x108 0x3b4 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_D1__KPP_ROW_4
value|0x108 0x3b4 0x7a0 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_D2__ESDHC2_DAT2
value|0x10c 0x3b8 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_D2__GPIO5_10
value|0x10c 0x3b8 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_D2__MSHC_DATA_2
value|0x10c 0x3b8 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_D2__KPP_COL_5
value|0x10c 0x3b8 0x794 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_D3__ESDHC2_DAT3
value|0x110 0x3bc 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_D3__GPIO5_11
value|0x110 0x3bc 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_D3__MSHC_DATA_3
value|0x110 0x3bc 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_D3__KPP_ROW_5
value|0x110 0x3bc 0x7a4 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_D4__ESDHC2_DAT4
value|0x114 0x3c0 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_D4__GPIO5_12
value|0x114 0x3c0 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_D4__AUDMUX_AUD4_RXFS
value|0x114 0x3c0 0x6d0 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_D4__KPP_COL_6
value|0x114 0x3c0 0x798 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_D4__EIM_WEIM_D_0
value|0x114 0x3c0 0x7ec 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_D4__CCM_CCM_OUT_0
value|0x114 0x3c0 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_D5__ESDHC2_DAT5
value|0x118 0x3c4 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_D5__GPIO5_13
value|0x118 0x3c4 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_D5__AUDMUX_AUD4_RXC
value|0x118 0x3c4 0x6cc 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_D5__KPP_ROW_6
value|0x118 0x3c4 0x7a8 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_D5__EIM_WEIM_D_1
value|0x118 0x3c4 0x7f0 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_D5__CCM_CCM_OUT_1
value|0x118 0x3c4 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_D6__ESDHC2_DAT6
value|0x11c 0x3c8 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_D6__GPIO5_14
value|0x11c 0x3c8 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_D6__AUDMUX_AUD4_RXD
value|0x11c 0x3c8 0x6c4 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_D6__KPP_COL_7
value|0x11c 0x3c8 0x79c 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_D6__EIM_WEIM_D_2
value|0x11c 0x3c8 0x7f4 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_D6__CCM_CCM_OUT_2
value|0x11c 0x3c8 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_D7__ESDHC2_DAT7
value|0x120 0x3cc 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_D7__GPIO5_15
value|0x120 0x3cc 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_D7__AUDMUX_AUD4_TXFS
value|0x120 0x3cc 0x6d8 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_D7__KPP_ROW_7
value|0x120 0x3cc 0x7ac 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_D7__EIM_WEIM_D_3
value|0x120 0x3cc 0x7f8 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_D7__CCM_STOP
value|0x120 0x3cc 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_WP__ESDHC2_WP
value|0x124 0x3d0 0x744 0x0 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_WP__GPIO5_16
value|0x124 0x3d0 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_WP__AUDMUX_AUD4_TXD
value|0x124 0x3d0 0x6c8 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_WP__EIM_WEIM_D_4
value|0x124 0x3d0 0x7fc 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_WP__CCM_WAIT
value|0x124 0x3d0 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_CD__ESDHC2_CD
value|0x128 0x3d4 0x740 0x0 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_CD__GPIO5_17
value|0x128 0x3d4 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_CD__AUDMUX_AUD4_TXC
value|0x128 0x3d4 0x6d4 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_CD__EIM_WEIM_D_5
value|0x128 0x3d4 0x800 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD2_CD__CCM_REF_EN_B
value|0x128 0x3d4 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D0__ELCDIF_DAT_0
value|0x12c 0x40c 0x6fc 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D0__GPIO2_0
value|0x12c 0x40c 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D0__FEC_TX_CLK
value|0x12c 0x40c 0x78c 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D0__EIM_WEIM_A_16
value|0x12c 0x40c 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D0__SDMA_DEBUG_PC_0
value|0x12c 0x40c 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D0__USBPHY1_VSTATUS_0
value|0x12c 0x40c 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D1__ELCDIF_DAT_1
value|0x130 0x410 0x700 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D1__GPIO2_1
value|0x130 0x410 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D1__FEC_RX_ERR
value|0x130 0x410 0x788 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D1__EIM_WEIM_A_17
value|0x130 0x410 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D1__SDMA_DEBUG_PC_1
value|0x130 0x410 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D1__USBPHY1_VSTATUS_1
value|0x130 0x410 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D2__ELCDIF_DAT_2
value|0x134 0x414 0x704 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D2__GPIO2_2
value|0x134 0x414 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D2__FEC_RX_DV
value|0x134 0x414 0x784 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D2__EIM_WEIM_A_18
value|0x134 0x414 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D2__SDMA_DEBUG_PC_2
value|0x134 0x414 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D2__USBPHY1_VSTATUS_2
value|0x134 0x414 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D3__ELCDIF_DAT_3
value|0x138 0x418 0x708 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D3__GPIO2_3
value|0x138 0x418 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D3__FEC_RDATA_1
value|0x138 0x418 0x77c 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D3__EIM_WEIM_A_19
value|0x138 0x418 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D3__FEC_COL
value|0x138 0x418 0x770 0x4 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D3__SDMA_DEBUG_PC_3
value|0x138 0x418 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D3__USBPHY1_VSTATUS_3
value|0x138 0x418 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D4__ELCDIF_DAT_4
value|0x13c 0x41c 0x70c 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D4__GPIO2_4
value|0x13c 0x41c 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D4__FEC_RDATA_0
value|0x13c 0x41c 0x778 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D4__EIM_WEIM_A_20
value|0x13c 0x41c 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D4__SDMA_DEBUG_PC_4
value|0x13c 0x41c 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D4__USBPHY1_VSTATUS_4
value|0x13c 0x41c 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D5__ELCDIF_DAT_5
value|0x140 0x420 0x710 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D5__GPIO2_5
value|0x140 0x420 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D5__FEC_TX_EN
value|0x140 0x420 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D5__EIM_WEIM_A_21
value|0x140 0x420 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D5__SDMA_DEBUG_PC_5
value|0x140 0x420 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D5__USBPHY1_VSTATUS_5
value|0x140 0x420 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D6__ELCDIF_DAT_6
value|0x144 0x424 0x714 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D6__GPIO2_6
value|0x144 0x424 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D6__FEC_TDATA_1
value|0x144 0x424 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D6__EIM_WEIM_A_22
value|0x144 0x424 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D6__FEC_RX_CLK
value|0x144 0x424 0x780 0x4 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D6__SDMA_DEBUG_PC_6
value|0x144 0x424 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D6__USBPHY1_VSTATUS_6
value|0x144 0x424 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D7__ELCDIF_DAT_7
value|0x148 0x428 0x718 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D7__GPIO2_7
value|0x148 0x428 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D7__FEC_TDATA_0
value|0x148 0x428 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D7__EIM_WEIM_A_23
value|0x148 0x428 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D7__SDMA_DEBUG_PC_7
value|0x148 0x428 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D7__USBPHY1_VSTATUS_7
value|0x148 0x428 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_WR__ELCDIF_WR_RWN
value|0x14c 0x42c 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_WR__GPIO2_16
value|0x14c 0x42c 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_WR__ELCDIF_DOTCLK
value|0x14c 0x42c 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_WR__EIM_WEIM_A_24
value|0x14c 0x42c 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_WR__SDMA_DEBUG_PC_8
value|0x14c 0x42c 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_WR__USBPHY1_AVALID
value|0x14c 0x42c 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_RD__ELCDIF_RD_E
value|0x150 0x430 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_RD__GPIO2_19
value|0x150 0x430 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_RD__ELCDIF_ENABLE
value|0x150 0x430 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_RD__EIM_WEIM_A_25
value|0x150 0x430 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_RD__SDMA_DEBUG_PC_9
value|0x150 0x430 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_RD__USBPHY1_BVALID
value|0x150 0x430 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_RS__ELCDIF_RS
value|0x154 0x434 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_RS__GPIO2_17
value|0x154 0x434 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_RS__ELCDIF_VSYNC
value|0x154 0x434 0x73c 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_RS__EIM_WEIM_A_26
value|0x154 0x434 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_RS__SDMA_DEBUG_PC_10
value|0x154 0x434 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_RS__USBPHY1_ENDSESSION
value|0x154 0x434 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_CS__ELCDIF_CS
value|0x158 0x438 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_CS__GPIO2_21
value|0x158 0x438 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_CS__ELCDIF_HSYNC
value|0x158 0x438 0x6f8 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_CS__EIM_WEIM_A_27
value|0x158 0x438 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_CS__EIM_WEIM_CS_3
value|0x158 0x438 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_CS__SDMA_DEBUG_PC_11
value|0x158 0x438 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_CS__USBPHY1_IDDIG
value|0x158 0x438 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_BUSY__ELCDIF_BUSY
value|0x15c 0x43c 0x6f8 0x0 0x2
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_BUSY__GPIO2_18
value|0x15c 0x43c 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_BUSY__EIM_WEIM_CS_3
value|0x15c 0x43c 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_BUSY__SDMA_DEBUG_PC_12
value|0x15c 0x43c 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_BUSY__USBPHY2_HOSTDISCONNECT
value|0x15c 0x43c 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_RESET__ELCDIF_RESET
value|0x160 0x440 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_RESET__GPIO2_20
value|0x160 0x440 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_RESET__EIM_WEIM_CS_3
value|0x160 0x440 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_RESET__SDMA_DEBUG_PC_13
value|0x160 0x440 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_RESET__USBPHY2_BISTOK
value|0x160 0x440 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_CMD__ESDHC3_CMD
value|0x164 0x444 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_CMD__GPIO5_18
value|0x164 0x444 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_CMD__EIM_NANDF_WRN
value|0x164 0x444 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_CMD__SSP_CMD
value|0x164 0x444 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_CLK__ESDHC3_CLK
value|0x168 0x448 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_CLK__GPIO5_19
value|0x168 0x448 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_CLK__EIM_NANDF_RDN
value|0x168 0x448 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_CLK__SSP_CLK
value|0x168 0x448 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_D0__ESDHC3_DAT0
value|0x16c 0x44c 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_D0__GPIO5_20
value|0x16c 0x44c 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_D0__EIM_NANDF_D_4
value|0x16c 0x44c 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_D0__SSP_D0
value|0x16c 0x44c 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_D0__CCM_PLL1_BYP
value|0x16c 0x44c 0x6dc 0x7 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_D1__ESDHC3_DAT1
value|0x170 0x450 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_D1__GPIO5_21
value|0x170 0x450 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_D1__EIM_NANDF_D_5
value|0x170 0x450 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_D1__SSP_D1
value|0x170 0x450 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_D1__CCM_PLL2_BYP
value|0x170 0x450 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_D2__ESDHC3_DAT2
value|0x174 0x454 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_D2__GPIO5_22
value|0x174 0x454 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_D2__EIM_NANDF_D_6
value|0x174 0x454 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_D2__SSP_D2
value|0x174 0x454 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_D2__CCM_PLL3_BYP
value|0x174 0x454 0x6e4 0x7 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_D3__ESDHC3_DAT3
value|0x178 0x458 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_D3__GPIO5_23
value|0x178 0x458 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_D3__EIM_NANDF_D_7
value|0x178 0x458 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_D3__SSP_D3
value|0x178 0x458 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_D4__ESDHC3_DAT4
value|0x17c 0x45c 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_D4__GPIO5_24
value|0x17c 0x45c 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_D4__EIM_NANDF_D_0
value|0x17c 0x45c 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_D4__SSP_D4
value|0x17c 0x45c 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_D5__ESDHC3_DAT5
value|0x180 0x460 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_D5__GPIO5_25
value|0x180 0x460 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_D5__EIM_NANDF_D_1
value|0x180 0x460 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_D5__SSP_D5
value|0x180 0x460 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_D6__ESDHC3_DAT6
value|0x184 0x464 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_D6__GPIO5_26
value|0x184 0x464 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_D6__EIM_NANDF_D_2
value|0x184 0x464 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_D6__SSP_D6
value|0x184 0x464 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_D7__ESDHC3_DAT7
value|0x188 0x468 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_D7__GPIO5_27
value|0x188 0x468 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_D7__EIM_NANDF_D_3
value|0x188 0x468 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_D7__SSP_D7
value|0x188 0x468 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_WP__ESDHC3_WP
value|0x18c 0x46C 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_WP__GPIO5_28
value|0x18c 0x46C 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_WP__EIM_NANDF_RESETN
value|0x18c 0x46C 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_WP__SSP_CD
value|0x18c 0x46C 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_WP__ESDHC4_LCTL
value|0x18c 0x46C 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_SD3_WP__EIM_WEIM_CS_3
value|0x18c 0x46C 0x000 0x5 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D8__ELCDIF_DAT_8
value|0x190 0x470 0x71c 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D8__GPIO2_8
value|0x190 0x470 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D8__EIM_NANDF_CLE
value|0x190 0x470 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D8__ESDHC1_LCTL
value|0x190 0x470 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D8__ESDHC4_CMD
value|0x190 0x470 0x74c 0x4 0x2
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D8__KPP_COL_4
value|0x190 0x470 0x790 0x5 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D8__FEC_TX_CLK
value|0x190 0x470 0x78c 0x6 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D8__USBPHY1_DATAOUT_0
value|0x190 0x470 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D9__ELCDIF_DAT_9
value|0x194 0x474 0x720 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D9__GPIO2_9
value|0x194 0x474 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D9__EIM_NANDF_ALE
value|0x194 0x474 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D9__ESDHC2_LCTL
value|0x194 0x474 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D9__ESDHC4_CLK
value|0x194 0x474 0x748 0x4 0x2
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D9__KPP_ROW_4
value|0x194 0x474 0x7a0 0x5 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D9__FEC_RX_ER
value|0x194 0x474 0x788 0x6 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D9__USBPHY1_DATAOUT_1
value|0x194 0x474 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D10__ELCDIF_DAT_10
value|0x198 0x478 0x724 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D10__GPIO2_10
value|0x198 0x478 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D10__EIM_NANDF_CEN_0
value|0x198 0x478 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D10__ESDHC3_LCTL
value|0x198 0x478 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D10__ESDHC4_DAT0
value|0x198 0x478 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D10__KPP_COL_5
value|0x198 0x478 0x794 0x5 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D10__FEC_RX_DV
value|0x198 0x478 0x784 0x6 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D10__USBPHY1_DATAOUT_2
value|0x198 0x478 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D11__ELCDIF_DAT_11
value|0x19c 0x47c 0x728 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D11__GPIO2_11
value|0x19c 0x47c 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D11__EIM_NANDF_CEN_1
value|0x19c 0x47c 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D11__ESDHC4_DAT1
value|0x19c 0x47c 0x754 0x4 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D11__KPP_ROW_5
value|0x19c 0x47c 0x7a4 0x5 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D11__FEC_RDATA_1
value|0x19c 0x47c 0x77c 0x6 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D11__USBPHY1_DATAOUT_3
value|0x19c 0x47c 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D12__ELCDIF_DAT_12
value|0x1a0 0x480 0x72c 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D12__GPIO2_12
value|0x1a0 0x480 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D12__EIM_NANDF_CEN_2
value|0x1a0 0x480 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D12__ESDHC1_CD
value|0x1a0 0x480 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D12__ESDHC4_DAT2
value|0x1a0 0x480 0x758 0x4 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D12__KPP_COL_6
value|0x1a0 0x480 0x798 0x5 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D12__FEC_RDATA_0
value|0x1a0 0x480 0x778 0x6 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D12__USBPHY1_DATAOUT_4
value|0x1a0 0x480 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D13__ELCDIF_DAT_13
value|0x1a4 0x484 0x730 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D13__GPIO2_13
value|0x1a4 0x484 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D13__EIM_NANDF_CEN_3
value|0x1a4 0x484 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D13__ESDHC3_CD
value|0x1a4 0x484 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D13__ESDHC4_DAT3
value|0x1a4 0x484 0x75c 0x4 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D13__KPP_ROW_6
value|0x1a4 0x484 0x7a8 0x5 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D13__FEC_TX_EN
value|0x1a4 0x484 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D13__USBPHY1_DATAOUT_5
value|0x1a4 0x484 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D14__ELCDIF_DAT_14
value|0x1a8 0x488 0x734 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D14__GPIO2_14
value|0x1a8 0x488 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D14__EIM_NANDF_READY0
value|0x1a8 0x488 0x7b4 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D14__ESDHC1_WP
value|0x1a8 0x488 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D14__ESDHC4_WP
value|0x1a8 0x488 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D14__KPP_COL_7
value|0x1a8 0x488 0x79c 0x5 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D14__FEC_TDATA_1
value|0x1a8 0x488 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D14__USBPHY1_DATAOUT_6
value|0x1a8 0x488 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D15__ELCDIF_DAT_15
value|0x1ac 0x48c 0x738 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D15__GPIO2_15
value|0x1ac 0x48c 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D15__EIM_NANDF_DQS
value|0x1ac 0x48c 0x7b0 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D15__ESDHC3_RST
value|0x1ac 0x48c 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D15__ESDHC4_CD
value|0x1ac 0x48c 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D15__KPP_ROW_7
value|0x1ac 0x48c 0x7ac 0x5 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D15__FEC_TDATA_0
value|0x1ac 0x48c 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_DISP_D15__USBPHY1_DATAOUT_7
value|0x1ac 0x48c 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D0__EPDC_SDDO_0
value|0x1b0 0x54c 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D0__GPIO3_0
value|0x1b0 0x54c 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D0__EIM_WEIM_D_0
value|0x1b0 0x54c 0x7ec 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D0__ELCDIF_RS
value|0x1b0 0x54c 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D0__ELCDIF_DOTCLK
value|0x1b0 0x54c 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D0__SDMA_DEBUG_EVT_CHN_LINES_0
value|0x1b0 0x54c 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D0__USBPHY2_DATAOUT_0
value|0x1b0 0x54c 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D1__EPDC_SDDO_1
value|0x1b4 0x550 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D1__GPIO3_1
value|0x1b4 0x550 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D1__EIM_WEIM_D_1
value|0x1b4 0x550 0x7f0 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D1__ELCDIF_CS
value|0x1b4 0x550 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D1__ELCDIF_ENABLE
value|0x1b4 0x550 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D1__SDMA_DEBUG_EVT_CHN_LINES_1
value|0x1b4 0x550 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D1__USBPHY2_DATAOUT_1
value|0x1b4 0x550 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D2__EPDC_SDDO_2
value|0x1b8 0x554 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D2__GPIO3_2
value|0x1b8 0x554 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D2__EIM_WEIM_D_2
value|0x1b8 0x554 0x7f4 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D2__ELCDIF_WR_RWN
value|0x1b8 0x554 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D2__ELCDIF_VSYNC
value|0x1b8 0x554 0x73c 0x4 0x2
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D2__SDMA_DEBUG_EVT_CHN_LINES_2
value|0x1b8 0x554 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D2__USBPHY2_DATAOUT_2
value|0x1b8 0x554 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D3__EPDC_SDDO_3
value|0x1bc 0x558 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D3__GPIO3_3
value|0x1bc 0x558 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D3__EIM_WEIM_D_3
value|0x1bc 0x558 0x7f8 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D3__ELCDIF_RD_E
value|0x1bc 0x558 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D3__ELCDIF_HSYNC
value|0x1bc 0x558 0x6f8 0x4 0x3
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D3__SDMA_DEBUG_EVT_CHN_LINES_3
value|0x1bc 0x558 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D3__USBPHY2_DATAOUT_3
value|0x1bc 0x558 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D4__EPDC_SDDO_4
value|0x1c0 0x55c 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D4__GPIO3_4
value|0x1c0 0x55c 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D4__EIM_WEIM_D_4
value|0x1c0 0x55c 0x7fc 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D4__SDMA_DEBUG_EVT_CHN_LINES_4
value|0x1c0 0x55c 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D4__USBPHY2_DATAOUT_4
value|0x1c0 0x55c 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D5__EPDC_SDDO_5
value|0x1c4 0x560 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D5__GPIO3_5
value|0x1c4 0x560 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D5__EIM_WEIM_D_5
value|0x1c4 0x560 0x800 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D5__SDMA_DEBUG_EVT_CHN_LINES_5
value|0x1c4 0x560 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D5__USBPHY2_DATAOUT_5
value|0x1c4 0x560 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D6__EPDC_SDDO_6
value|0x1c8 0x564 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D6__GPIO3_6
value|0x1c8 0x564 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D6__EIM_WEIM_D_6
value|0x1c8 0x564 0x804 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D6__SDMA_DEBUG_EVT_CHN_LINES_6
value|0x1c8 0x564 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D6__USBPHY2_DATAOUT_6
value|0x1c8 0x564 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D7__EPDC_SDDO_7
value|0x1cc 0x568 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D7__GPIO3_7
value|0x1cc 0x568 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D7__EIM_WEIM_D_7
value|0x1cc 0x568 0x808 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D7__SDMA_DEBUG_EVT_CHN_LINES_7
value|0x1cc 0x568 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D7__USBPHY2_DATAOUT_7
value|0x1cc 0x568 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D8__EPDC_SDDO_8
value|0x1d0 0x56c 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D8__GPIO3_8
value|0x1d0 0x56c 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D8__EIM_WEIM_D_8
value|0x1d0 0x56c 0x80c 0x2 0x2
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D8__ELCDIF_DAT_24
value|0x1d0 0x56c 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D8__SDMA_DEBUG_MATCHED_DMBUS
value|0x1d0 0x56c 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D8__USBPHY2_VSTATUS_0
value|0x1d0 0x56c 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D9__EPDC_SDDO_9
value|0x1d4 0x570 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D9__GPIO3_9
value|0x1d4 0x570 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D9__EIM_WEIM_D_9
value|0x1d4 0x570 0x810 0x2 0x2
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D9__ELCDIF_DAT_25
value|0x1d4 0x570 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D9__SDMA_DEBUG_EVENT_CHANNEL_SEL
value|0x1d4 0x570 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D9__USBPHY2_VSTATUS_1
value|0x1d4 0x570 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D10__EPDC_SDDO_10
value|0x1d8 0x574 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D10__GPIO3_10
value|0x1d8 0x574 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D10__EIM_WEIM_D_10
value|0x1d8 0x574 0x814 0x2 0x2
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D10__ELCDIF_DAT_26
value|0x1d8 0x574 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D10__SDMA_DEBUG_EVENT_CHANNEL_0
value|0x1d8 0x574 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D10__USBPHY2_VSTATUS_2
value|0x1d8 0x574 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D11__EPDC_SDDO_11
value|0x1dc 0x578 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D11__GPIO3_11
value|0x1dc 0x578 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D11__EIM_WEIM_D_11
value|0x1dc 0x578 0x818 0x2 0x2
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D11__ELCDIF_DAT_27
value|0x1dc 0x578 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D11__SDMA_DEBUG_EVENT_CHANNEL_1
value|0x1dc 0x578 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D11__USBPHY2_VSTATUS_3
value|0x1dc 0x578 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D12__EPDC_SDDO_12
value|0x1e0 0x57c 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D12__GPIO3_12
value|0x1e0 0x57c 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D12__EIM_WEIM_D_12
value|0x1e0 0x57c 0x81c 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D12__ELCDIF_DAT_28
value|0x1e0 0x57c 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D12__SDMA_DEBUG_EVENT_CHANNEL_2
value|0x1e0 0x57c 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D12__USBPHY2_VSTATUS_4
value|0x1e0 0x57c 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D13__EPDC_SDDO_13
value|0x1e4 0x580 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D13__GPIO3_13
value|0x1e4 0x580 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D13__EIM_WEIM_D_13
value|0x1e4 0x580 0x820 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D13__ELCDIF_DAT_29
value|0x1e4 0x580 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D13__SDMA_DEBUG_EVENT_CHANNEL_3
value|0x1e4 0x580 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D13__USBPHY2_VSTATUS_5
value|0x1e4 0x580 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D14__EPDC_SDDO_14
value|0x1e8 0x584 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D14__GPIO3_14
value|0x1e8 0x584 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D14__EIM_WEIM_D_14
value|0x1e8 0x584 0x824 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D14__ELCDIF_DAT_30
value|0x1e8 0x584 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D14__AUDMUX_AUD6_TXD
value|0x1e8 0x584 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D14__SDMA_DEBUG_EVENT_CHANNEL_4
value|0x1e8 0x584 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D14__USBPHY2_VSTATUS_6
value|0x1e8 0x584 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D15__EPDC_SDDO_15
value|0x1ec 0x588 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D15__GPIO3_15
value|0x1ec 0x588 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D15__EIM_WEIM_D_15
value|0x1ec 0x588 0x828 0x2 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D15__ELCDIF_DAT_31
value|0x1ec 0x588 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D15__AUDMUX_AUD6_TXC
value|0x1ec 0x588 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D15__SDMA_DEBUG_EVENT_CHANNEL_5
value|0x1ec 0x588 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_D15__USBPHY2_VSTATUS_7
value|0x1ec 0x588 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_GDCLK__EPDC_GDCLK
value|0x1f0 0x58c 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_GDCLK__GPIO3_16
value|0x1f0 0x58c 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_GDCLK__EIM_WEIM_D_16
value|0x1f0 0x58c 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_GDCLK__ELCDIF_DAT_16
value|0x1f0 0x58c 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_GDCLK__AUDMUX_AUD6_TXFS
value|0x1f0 0x58c 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_GDCLK__SDMA_DEBUG_CORE_STATE_0
value|0x1f0 0x58c 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_GDCLK__USBPHY2_BISTOK
value|0x1f0 0x58c 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_GDSP__EPCD_GDSP
value|0x1f4 0x590 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_GDSP__GPIO3_17
value|0x1f4 0x590 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_GDSP__EIM_WEIM_D_17
value|0x1f4 0x590 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_GDSP__ELCDIF_DAT_17
value|0x1f4 0x590 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_GDSP__AUDMUX_AUD6_RXD
value|0x1f4 0x590 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_GDSP__SDMA_DEBUG_CORE_STATE_1
value|0x1f4 0x590 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_GDSP__USBPHY2_BVALID
value|0x1f4 0x590 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_GDOE__EPCD_GDOE
value|0x1f8 0x594 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_GDOE__GPIO3_18
value|0x1f8 0x594 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_GDOE__EIM_WEIM_D_18
value|0x1f8 0x594 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_GDOE__ELCDIF_DAT_18
value|0x1f8 0x594 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_GDOE__AUDMUX_AUD6_RXC
value|0x1f8 0x594 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_GDOE__SDMA_DEBUG_CORE_STATE_2
value|0x1f8 0x594 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_GDOE__USBPHY2_ENDSESSION
value|0x1f8 0x594 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_GDRL__EPCD_GDRL
value|0x1fc 0x598 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_GDRL__GPIO3_19
value|0x1fc 0x598 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_GDRL__EIM_WEIM_D_19
value|0x1f8 0x598 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_GDRL__ELCDIF_DAT_19
value|0x1fc 0x598 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_GDRL__AUDMUX_AUD6_RXFS
value|0x1fc 0x598 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_GDRL__SDMA_DEBUG_CORE_STATE_3
value|0x1fc 0x598 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_GDRL__USBPHY2_IDDIG
value|0x1fc 0x598 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDCLK__EPCD_SDCLK
value|0x200 0x59c 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDCLK__GPIO3_20
value|0x200 0x59c 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDCLK__EIM_WEIM_D_20
value|0x200 0x59c 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDCLK__ELCDIF_DAT_20
value|0x200 0x59c 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDCLK__AUDMUX_AUD5_TXD
value|0x200 0x59c 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDCLK__SDMA_DEBUG_BUS_DEVICE_0
value|0x200 0x59c 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDCLK__USBPHY2_HOSTDISCONNECT
value|0x200 0x59c 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDOEZ__EPCD_SDOEZ
value|0x204 0x5a0 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDOEZ__GPIO3_21
value|0x204 0x5a0 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDOEZ__EIM_WEIM_D_21
value|0x204 0x5a0 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDOEZ__ELCDIF_DAT_21
value|0x204 0x5a0 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDOEZ__AUDMUX_AUD5_TXC
value|0x204 0x5a0 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDOEZ__SDMA_DEBUG_BUS_DEVICE_1
value|0x204 0x5a0 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDOEZ__USBPHY2_TXREADY
value|0x204 0x5a0 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDOED__EPCD_SDOED
value|0x208 0x5a4 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDOED__GPIO3_22
value|0x208 0x5a4 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDOED__EIM_WEIM_D_22
value|0x208 0x5a4 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDOED__ELCDIF_DAT_22
value|0x208 0x5a4 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDOED__AUDMUX_AUD5_TXFS
value|0x208 0x5a4 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDOED__SDMA_DEBUG_BUS_DEVICE_2
value|0x208 0x5a4 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDOED__USBPHY2_RXVALID
value|0x208 0x5a4 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDOE__EPCD_SDOE
value|0x20c 0x5a8 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDOE__GPIO3_23
value|0x20c 0x5a8 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDOE__EIM_WEIM_D_23
value|0x20c 0x5a8 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDOE__ELCDIF_DAT_23
value|0x20c 0x5a8 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDOE__AUDMUX_AUD5_RXD
value|0x20c 0x5a8 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDOE__SDMA_DEBUG_BUS_DEVICE_3
value|0x20c 0x5a8 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDOE__USBPHY2_RXACTIVE
value|0x20c 0x5a8 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDLE__EPCD_SDLE
value|0x210 0x5ac 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDLE__GPIO3_24
value|0x210 0x5ac 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDLE__EIM_WEIM_D_24
value|0x210 0x5ac 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDLE__ELCDIF_DAT_8
value|0x210 0x5ac 0x71c 0x3 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDLE__AUDMUX_AUD5_RXC
value|0x210 0x5ac 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDLE__SDMA_DEBUG_BUS_DEVICE_4
value|0x210 0x5ac 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDLE__USBPHY2_RXERROR
value|0x210 0x5ac 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDCLKN__EPCD_SDCLKN
value|0x214 0x5b0 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDCLKN__GPIO3_25
value|0x214 0x5b0 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDCLKN__EIM_WEIM_D_25
value|0x214 0x5b0 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDCLKN__ELCDIF_DAT_9
value|0x214 0x5b0 0x720 0x3 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDCLKN__AUDMUX_AUD5_RXFS
value|0x214 0x5b0 0x000 0x4 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDCLKN__SDMA_DEBUG_BUS_ERROR
value|0x214 0x5b0 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDCLKN__USBPHY2_SIECLOCK
value|0x214 0x5b0 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDSHR__EPCD_SDSHR
value|0x218 0x5b4 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDSHR__GPIO3_26
value|0x218 0x5b4 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDSHR__EIM_WEIM_D_26
value|0x218 0x5b4 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDSHR__ELCDIF_DAT_10
value|0x218 0x5b4 0x724 0x3 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDSHR__AUDMUX_AUD4_TXD
value|0x218 0x5b4 0x6c8 0x4 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDSHR__SDMA_DEBUG_BUS_RWB
value|0x218 0x5b4 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDSHR__USBPHY2_LINESTATE_0
value|0x218 0x5b4 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_PWRCOM__EPCD_PWRCOM
value|0x21c 0x5b8 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_PWRCOM__GPIO3_27
value|0x21c 0x5b8 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_PWRCOM__EIM_WEIM_D_27
value|0x21c 0x5b8 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_PWRCOM__ELCDIF_DAT_11
value|0x21c 0x5b8 0x728 0x3 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_PWRCOM__AUDMUX_AUD4_TXC
value|0x21c 0x5b8 0x6d4 0x4 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_PWRCOM__SDMA_DEBUG_CORE_RUN
value|0x21c 0x5b8 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_PWRCOM__USBPHY2_LINESTATE_1
value|0x21c 0x5b8 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_PWRSTAT__EPCD_PWRSTAT
value|0x220 0x5bc 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_PWRSTAT__GPIO3_28
value|0x220 0x5bc 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_PWRSTAT__EIM_WEIM_D_28
value|0x220 0x5bc 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_PWRSTAT__ELCDIF_DAT_12
value|0x220 0x5bc 0x72c 0x3 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_PWRSTAT__AUDMUX_AUD4_TXFS
value|0x220 0x5bc 0x6d8 0x4 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_PWRSTAT__SDMA_DEBUG_MODE
value|0x220 0x5bc 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_PWRSTAT__USBPHY2_VBUSVALID
value|0x220 0x5bc 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_PWRCTRL0__EPCD_PWRCTRL0
value|0x224 0x5c0 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_PWRCTRL0__GPIO3_29
value|0x224 0x5c0 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_PWRCTRL0__EIM_WEIM_D_29
value|0x224 0x5c0 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_PWRCTRL0__ELCDIF_DAT_13
value|0x224 0x5c0 0x730 0x3 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_PWRCTRL0__AUDMUX_AUD4_RXD
value|0x224 0x5c0 0x6c4 0x4 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_PWRCTRL0__SDMA_DEBUG_RTBUFFER_WRITE
value|0x224 0x5c0 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_PWRCTRL0__USBPHY2_AVALID
value|0x224 0x5c0 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_PWRCTRL1__EPCD_PWRCTRL1
value|0x228 0x5c4 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_PWRCTRL1__GPIO3_30
value|0x228 0x5c4 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_PWRCTRL1__EIM_WEIM_D_30
value|0x228 0x5c4 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_PWRCTRL1__ELCDIF_DAT_14
value|0x228 0x5c4 0x734 0x3 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_PWRCTRL1__AUDMUX_AUD4_RXC
value|0x228 0x5c4 0x6cc 0x4 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_PWRCTRL1__SDMA_DEBUG_YIELD
value|0x228 0x5c4 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_PWRCTRL1__USBPHY1_ONBIST
value|0x228 0x5c4 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_PWRCTRL2__EPCD_PWRCTRL2
value|0x22c 0x5c8 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_PWRCTRL2__GPIO3_31
value|0x22c 0x5c8 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_PWRCTRL2__EIM_WEIM_D_31
value|0x22c 0x5c8 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_PWRCTRL2__ELCDIF_DAT_15
value|0x22c 0x5c8 0x738 0x3 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_PWRCTRL2__AUDMUX_AUD4_RXFS
value|0x22c 0x5c8 0x6d0 0x4 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_PWRCTRL2__SDMA_EXT_EVENT_0
value|0x22c 0x5c8 0x7b8 0x6 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_PWRCTRL2__USBPHY2_ONBIST
value|0x22c 0x5c8 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_PWRCTRL3__EPCD_PWRCTRL3
value|0x230 0x5cc 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_PWRCTRL3__GPIO4_20
value|0x230 0x5cc 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_PWRCTRL3__EIM_WEIM_EB_2
value|0x230 0x5cc 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_PWRCTRL3__SDMA_EXT_EVENT_1
value|0x230 0x5cc 0x7bc 0x6 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_PWRCTRL3__USBPHY1_BISTOK
value|0x230 0x5cc 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_VCOM0__EPCD_VCOM_0
value|0x234 0x5d0 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_VCOM0__GPIO4_21
value|0x234 0x5d0 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_VCOM0__EIM_WEIM_EB_3
value|0x234 0x5d0 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_VCOM0__USBPHY2_BISTOK
value|0x234 0x5d0 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_VCOM1__EPCD_VCOM_1
value|0x238 0x5d4 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_VCOM1__GPIO4_22
value|0x238 0x5d4 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_VCOM1__EIM_WEIM_CS_3
value|0x238 0x5d4 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_BDR0__EPCD_BDR_0
value|0x23c 0x5d8 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_BDR0__GPIO4_23
value|0x23c 0x5d8 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_BDR0__ELCDIF_DAT_7
value|0x23c 0x5d8 0x718 0x3 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_BDR1__EPCD_BDR_1
value|0x240 0x5dc 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_BDR1__GPIO4_24
value|0x240 0x5dc 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_BDR1__ELCDIF_DAT_6
value|0x240 0x5dc 0x714 0x3 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDCE0__EPCD_SDCE_0
value|0x244 0x5e0 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDCE0__GPIO4_25
value|0x244 0x5e0 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDCE0__ELCDIF_DAT_5
value|0x244 0x5e0 0x710 0x3 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDCE1__EPCD_SDCE_1
value|0x248 0x5e4 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDCE1__GPIO4_26
value|0x248 0x5e4 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDCE1__ELCDIF_DAT_4
value|0x248 0x5e4 0x70c 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDCE2__EPCD_SDCE_2
value|0x24c 0x5e8 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDCE2__GPIO4_27
value|0x24c 0x5e8 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDCE2__ELCDIF_DAT_3
value|0x24c 0x5e8 0x708 0x3 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDCE3__EPCD_SDCE_3
value|0x250 0x5ec 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDCE3__GPIO4_28
value|0x250 0x5ec 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDCE3__ELCDIF_DAT_2
value|0x250 0x5ec 0x704 0x3 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDCE4__EPCD_SDCE_4
value|0x254 0x5f0 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDCE4__GPIO4_29
value|0x254 0x5f0 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDCE4__ELCDIF_DAT_1
value|0x254 0x5f0 0x700 0x3 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDCE5__EPCD_SDCE_5
value|0x258 0x5f4 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDCE5__GPIO4_30
value|0x258 0x5f4 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EPDC_SDCE5__ELCDIF_DAT_0
value|0x258 0x5f4 0x6fc 0x3 0x1
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA0__EIM_WEIM_A_0
value|0x25c 0x5f8 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA0__GPIO1_0
value|0x25c 0x5f8 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA0__KPP_COL_4
value|0x25c 0x5f8 0x790 0x3 0x2
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA0__TPIU_TRACE_0
value|0x25c 0x5f8 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA0__SRC_BT_CFG1_0
value|0x25c 0x5f8 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA1__EIM_WEIM_A_1
value|0x260 0x5fc 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA1__GPIO1_1
value|0x260 0x5fc 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA1__KPP_ROW_4
value|0x260 0x5fc 0x7a0 0x3 0x2
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA1__TPIU_TRACE_1
value|0x260 0x5fc 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA1__SRC_BT_CFG1_1
value|0x260 0x5fc 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA2__EIM_WEIM_A_2
value|0x264 0x600 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA2__GPIO1_2
value|0x264 0x600 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA2__KPP_COL_5
value|0x264 0x600 0x794 0x3 0x2
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA2__TPIU_TRACE_2
value|0x264 0x600 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA2__SRC_BT_CFG1_2
value|0x264 0x600 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA3__EIM_WEIM_A_3
value|0x268 0x604 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA3__GPIO1_3
value|0x268 0x604 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA3__KPP_ROW_5
value|0x268 0x604 0x7a4 0x3 0x2
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA3__TPIU_TRACE_3
value|0x268 0x604 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA3__SRC_BT_CFG1_3
value|0x268 0x604 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA4__EIM_WEIM_A_4
value|0x26c 0x608 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA4__GPIO1_4
value|0x26c 0x608 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA4__KPP_COL_6
value|0x26c 0x608 0x798 0x3 0x2
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA4__TPIU_TRACE_4
value|0x26c 0x608 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA4__SRC_BT_CFG1_4
value|0x26c 0x608 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA5__EIM_WEIM_A_5
value|0x270 0x60c 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA5__GPIO1_5
value|0x270 0x60c 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA5__KPP_ROW_6
value|0x270 0x60c 0x7a8 0x3 0x2
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA5__TPIU_TRACE_5
value|0x270 0x60c 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA5__SRC_BT_CFG1_5
value|0x270 0x60c 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA6__EIM_WEIM_A_6
value|0x274 0x610 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA6__GPIO1_6
value|0x274 0x610 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA6__KPP_COL_7
value|0x274 0x610 0x79c 0x3 0x2
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA6__TPIU_TRACE_6
value|0x274 0x610 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA6__SRC_BT_CFG1_6
value|0x274 0x610 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA7__EIM_WEIM_A_7
value|0x278 0x614 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA7__GPIO1_7
value|0x278 0x614 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA7__KPP_ROW_7
value|0x278 0x614 0x7ac 0x3 0x2
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA7__TPIU_TRACE_7
value|0x278 0x614 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA7__SRC_BT_CFG1_7
value|0x278 0x614 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA8__EIM_WEIM_A_8
value|0x27c 0x618 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA8__GPIO1_8
value|0x27c 0x618 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA8__EIM_NANDF_CLE
value|0x27c 0x618 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA8__TPIU_TRACE_8
value|0x27c 0x618 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA8__SRC_BT_CFG2_0
value|0x27c 0x618 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA9__EIM_WEIM_A_9
value|0x280 0x61c 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA9__GPIO1_9
value|0x280 0x61c 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA9__EIM_NANDF_ALE
value|0x280 0x61c 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA9__TPIU_TRACE_9
value|0x280 0x61c 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA9__SRC_BT_CFG2_1
value|0x280 0x61c 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA10__EIM_WEIM_A_10
value|0x284 0x620 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA10__GPIO1_10
value|0x284 0x620 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA10__EIM_NANDF_CEN_0
value|0x284 0x620 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA10__TPIU_TRACE_10
value|0x284 0x620 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA10__SRC_BT_CFG2_2
value|0x284 0x620 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA11__EIM_WEIM_A_11
value|0x288 0x624 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA11__GPIO1_11
value|0x288 0x624 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA11__EIM_NANDF_CEN_1
value|0x288 0x624 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA11__TPIU_TRACE_11
value|0x288 0x624 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA11__SRC_BT_CFG2_3
value|0x288 0x624 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA12__EIM_WEIM_A_12
value|0x28c 0x628 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA12__GPIO1_12
value|0x28c 0x628 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA12__EIM_NANDF_CEN_2
value|0x28c 0x628 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA12__EPDC_SDCE_6
value|0x28c 0x628 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA12__TPIU_TRACE_12
value|0x28c 0x628 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA12__SRC_BT_CFG2_4
value|0x28c 0x628 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA13__EIM_WEIM_A_13
value|0x290 0x62c 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA13__GPIO1_13
value|0x290 0x62c 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA13__EIM_NANDF_CEN_3
value|0x290 0x62c 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA13__EPDC_SDCE_7
value|0x290 0x62c 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA13__TPIU_TRACE_13
value|0x290 0x62c 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA13__SRC_BT_CFG2_5
value|0x290 0x62c 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA14__EIM_WEIM_A_14
value|0x294 0x630 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA14__GPIO1_14
value|0x294 0x630 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA14__EIM_NANDF_READY0
value|0x294 0x630 0x7b4 0x2 0x2
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA14__EPDC_SDCE_8
value|0x294 0x630 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA14__TPIU_TRACE_14
value|0x294 0x630 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA14__SRC_BT_CFG2_6
value|0x294 0x630 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA15__EIM_WEIM_A_15
value|0x298 0x634 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA15__GPIO1_15
value|0x298 0x634 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA15__EIM_NANDF_DQS
value|0x298 0x634 0x7b0 0x2 0x2
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA15__EPDC_SDCE_9
value|0x298 0x634 0x000 0x3 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA15__TPIU_TRACE_15
value|0x298 0x634 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_DA15__SRC_BT_CFG2_7
value|0x298 0x634 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_CS2__EIM_WEIM_CS_2
value|0x29c 0x638 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_CS2__GPIO1_16
value|0x29c 0x638 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_CS2__EIM_WEIM_A_27
value|0x29c 0x638 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_CS2__TPIU_TRCLK
value|0x29c 0x638 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_CS2__SRC_BT_CFG3_0
value|0x29c 0x638 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_CS1__EIM_WEIM_CS_1
value|0x2a0 0x63c 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_CS1__GPIO1_17
value|0x2a0 0x63c 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_CS1__TPIU_TRCTL
value|0x2a0 0x63c 0x000 0x6 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_CS1__SRC_BT_CFG3_1
value|0x2a0 0x63c 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_CS0__EIM_WEIM_CS_0
value|0x2a4 0x640 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_CS0__GPIO1_18
value|0x2a4 0x640 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_CS0__SRC_BT_CFG3_2
value|0x2a4 0x640 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_EB0__EIM_WEIM_EB_0
value|0x2a8 0x644 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_EB0__GPIO1_19
value|0x2a8 0x644 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_EB0__SRC_BT_CFG3_3
value|0x2a8 0x644 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_EB1__EIM_WEIM_EB_1
value|0x2ac 0x648 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_EB1__GPIO1_20
value|0x2ac 0x648 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_EB1__SRC_BT_CFG3_4
value|0x2ac 0x648 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_WAIT__EIM_WEIM_WAIT
value|0x2b0 0x64c 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_WAIT__GPIO1_21
value|0x2b0 0x64c 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_WAIT__EIM_WEIM_DTACK_B
value|0x2b0 0x64c 0x000 0x2 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_WAIT__SRC_BT_CFG3_5
value|0x2b0 0x64c 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_BCLK__EIM_WEIM_BCLK
value|0x2b4 0x650 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_BCLK__GPIO1_22
value|0x2b4 0x650 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_BCLK__SRC_BT_CFG3_6
value|0x2b4 0x650 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_RDY__EIM_WEIM_RDY
value|0x2b8 0x654 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_RDY__GPIO1_23
value|0x2b8 0x654 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_RDY__SRC_BT_CFG3_7
value|0x2b8 0x654 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_OE__EIM_WEIM_OE
value|0x2bc 0x658 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_OE__GPIO1_24
value|0x2bc 0x658 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_OE__INT_BOOT
value|0x2bc 0x658 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_RW__EIM_WEIM_RW
value|0x2c0 0x65c 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_RW__GPIO1_25
value|0x2c0 0x65c 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_RW__SYSTEM_RST
value|0x2c0 0x65c 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_LBA__EIM_WEIM_LBA
value|0x2c4 0x660 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_LBA__GPIO1_26
value|0x2c4 0x660 0x000 0x1 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_LBA__TESTER_ACK
value|0x2c4 0x660 0x000 0x7 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_CRE__EIM_WEIM_CRE
value|0x2c8 0x664 0x000 0x0 0x0
end_define

begin_define
define|#
directive|define
name|MX50_PAD_EIM_CRE__GPIO1_27
value|0x2c8 0x664 0x000 0x1 0x0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DTS_IMX50_PINFUNC_H */
end_comment

end_unit

