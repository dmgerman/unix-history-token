begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Header providing constants for i.MX28 pinctrl bindings.  *  * Copyright (C) 2013 Lothar WaÃmann<LW@KARO-electronics.de>  *  * The code contained herein is licensed under the GNU General Public  * License. You may obtain a copy of the GNU General Public License  * Version 2 at the following locations:  *  * http://www.opensource.org/licenses/gpl-license.html  * http://www.gnu.org/copyleft/gpl.html  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_MX28_PINCTRL_H__
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_MX28_PINCTRL_H__
end_define

begin_include
include|#
directive|include
file|"mxs-pinfunc.h"
end_include

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_D00__GPMI_D0
value|0x0000
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_D01__GPMI_D1
value|0x0010
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_D02__GPMI_D2
value|0x0020
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_D03__GPMI_D3
value|0x0030
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_D04__GPMI_D4
value|0x0040
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_D05__GPMI_D5
value|0x0050
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_D06__GPMI_D6
value|0x0060
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_D07__GPMI_D7
value|0x0070
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_CE0N__GPMI_CE0N
value|0x0100
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_CE1N__GPMI_CE1N
value|0x0110
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_CE2N__GPMI_CE2N
value|0x0120
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_CE3N__GPMI_CE3N
value|0x0130
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_RDY0__GPMI_READY0
value|0x0140
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_RDY1__GPMI_READY1
value|0x0150
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_RDY2__GPMI_READY2
value|0x0160
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_RDY3__GPMI_READY3
value|0x0170
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_RDN__GPMI_RDN
value|0x0180
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_WRN__GPMI_WRN
value|0x0190
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_ALE__GPMI_ALE
value|0x01a0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_CLE__GPMI_CLE
value|0x01b0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_RESETN__GPMI_RESETN
value|0x01c0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D00__LCD_D0
value|0x1000
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D01__LCD_D1
value|0x1010
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D02__LCD_D2
value|0x1020
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D03__LCD_D3
value|0x1030
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D04__LCD_D4
value|0x1040
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D05__LCD_D5
value|0x1050
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D06__LCD_D6
value|0x1060
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D07__LCD_D7
value|0x1070
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D08__LCD_D8
value|0x1080
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D09__LCD_D9
value|0x1090
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D10__LCD_D10
value|0x10a0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D11__LCD_D11
value|0x10b0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D12__LCD_D12
value|0x10c0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D13__LCD_D13
value|0x10d0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D14__LCD_D14
value|0x10e0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D15__LCD_D15
value|0x10f0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D16__LCD_D16
value|0x1100
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D17__LCD_D17
value|0x1110
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D18__LCD_D18
value|0x1120
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D19__LCD_D19
value|0x1130
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D20__LCD_D20
value|0x1140
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D21__LCD_D21
value|0x1150
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D22__LCD_D22
value|0x1160
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D23__LCD_D23
value|0x1170
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_RD_E__LCD_RD_E
value|0x1180
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_WR_RWN__LCD_WR_RWN
value|0x1190
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_RS__LCD_RS
value|0x11a0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_CS__LCD_CS
value|0x11b0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_VSYNC__LCD_VSYNC
value|0x11c0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_HSYNC__LCD_HSYNC
value|0x11d0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_DOTCLK__LCD_DOTCLK
value|0x11e0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_ENABLE__LCD_ENABLE
value|0x11f0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP0_DATA0__SSP0_D0
value|0x2000
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP0_DATA1__SSP0_D1
value|0x2010
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP0_DATA2__SSP0_D2
value|0x2020
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP0_DATA3__SSP0_D3
value|0x2030
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP0_DATA4__SSP0_D4
value|0x2040
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP0_DATA5__SSP0_D5
value|0x2050
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP0_DATA6__SSP0_D6
value|0x2060
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP0_DATA7__SSP0_D7
value|0x2070
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP0_CMD__SSP0_CMD
value|0x2080
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP0_DETECT__SSP0_CARD_DETECT
value|0x2090
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP0_SCK__SSP0_SCK
value|0x20a0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP1_SCK__SSP1_SCK
value|0x20c0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP1_CMD__SSP1_CMD
value|0x20d0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP1_DATA0__SSP1_D0
value|0x20e0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP1_DATA3__SSP1_D3
value|0x20f0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP2_SCK__SSP2_SCK
value|0x2100
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP2_MOSI__SSP2_CMD
value|0x2110
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP2_MISO__SSP2_D0
value|0x2120
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP2_SS0__SSP2_D3
value|0x2130
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP2_SS1__SSP2_D4
value|0x2140
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP2_SS2__SSP2_D5
value|0x2150
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP3_SCK__SSP3_SCK
value|0x2180
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP3_MOSI__SSP3_CMD
value|0x2190
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP3_MISO__SSP3_D0
value|0x21a0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP3_SS0__SSP3_D3
value|0x21b0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART0_RX__AUART0_RX
value|0x3000
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART0_TX__AUART0_TX
value|0x3010
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART0_CTS__AUART0_CTS
value|0x3020
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART0_RTS__AUART0_RTS
value|0x3030
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART1_RX__AUART1_RX
value|0x3040
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART1_TX__AUART1_TX
value|0x3050
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART1_CTS__AUART1_CTS
value|0x3060
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART1_RTS__AUART1_RTS
value|0x3070
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART2_RX__AUART2_RX
value|0x3080
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART2_TX__AUART2_TX
value|0x3090
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART2_CTS__AUART2_CTS
value|0x30a0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART2_RTS__AUART2_RTS
value|0x30b0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART3_RX__AUART3_RX
value|0x30c0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART3_TX__AUART3_TX
value|0x30d0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART3_CTS__AUART3_CTS
value|0x30e0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART3_RTS__AUART3_RTS
value|0x30f0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_PWM0__PWM_0
value|0x3100
end_define

begin_define
define|#
directive|define
name|MX28_PAD_PWM1__PWM_1
value|0x3110
end_define

begin_define
define|#
directive|define
name|MX28_PAD_PWM2__PWM_2
value|0x3120
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SAIF0_MCLK__SAIF0_MCLK
value|0x3140
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SAIF0_LRCLK__SAIF0_LRCLK
value|0x3150
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SAIF0_BITCLK__SAIF0_BITCLK
value|0x3160
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SAIF0_SDATA0__SAIF0_SDATA0
value|0x3170
end_define

begin_define
define|#
directive|define
name|MX28_PAD_I2C0_SCL__I2C0_SCL
value|0x3180
end_define

begin_define
define|#
directive|define
name|MX28_PAD_I2C0_SDA__I2C0_SDA
value|0x3190
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SAIF1_SDATA0__SAIF1_SDATA0
value|0x31a0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SPDIF__SPDIF_TX
value|0x31b0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_PWM3__PWM_3
value|0x31c0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_PWM4__PWM_4
value|0x31d0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_RESET__LCD_RESET
value|0x31e0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_MDC__ENET0_MDC
value|0x4000
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_MDIO__ENET0_MDIO
value|0x4010
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_RX_EN__ENET0_RX_EN
value|0x4020
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_RXD0__ENET0_RXD0
value|0x4030
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_RXD1__ENET0_RXD1
value|0x4040
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_TX_CLK__ENET0_TX_CLK
value|0x4050
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_TX_EN__ENET0_TX_EN
value|0x4060
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_TXD0__ENET0_TXD0
value|0x4070
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_TXD1__ENET0_TXD1
value|0x4080
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_RXD2__ENET0_RXD2
value|0x4090
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_RXD3__ENET0_RXD3
value|0x40a0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_TXD2__ENET0_TXD2
value|0x40b0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_TXD3__ENET0_TXD3
value|0x40c0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_RX_CLK__ENET0_RX_CLK
value|0x40d0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_COL__ENET0_COL
value|0x40e0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_CRS__ENET0_CRS
value|0x40f0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET_CLK__CLKCTRL_ENET
value|0x4100
end_define

begin_define
define|#
directive|define
name|MX28_PAD_JTAG_RTCK__JTAG_RTCK
value|0x4140
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_D00__EMI_DATA0
value|0x5000
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_D01__EMI_DATA1
value|0x5010
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_D02__EMI_DATA2
value|0x5020
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_D03__EMI_DATA3
value|0x5030
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_D04__EMI_DATA4
value|0x5040
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_D05__EMI_DATA5
value|0x5050
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_D06__EMI_DATA6
value|0x5060
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_D07__EMI_DATA7
value|0x5070
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_D08__EMI_DATA8
value|0x5080
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_D09__EMI_DATA9
value|0x5090
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_D10__EMI_DATA10
value|0x50a0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_D11__EMI_DATA11
value|0x50b0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_D12__EMI_DATA12
value|0x50c0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_D13__EMI_DATA13
value|0x50d0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_D14__EMI_DATA14
value|0x50e0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_D15__EMI_DATA15
value|0x50f0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_ODT0__EMI_ODT0
value|0x5100
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_DQM0__EMI_DQM0
value|0x5110
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_ODT1__EMI_ODT1
value|0x5120
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_DQM1__EMI_DQM1
value|0x5130
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_DDR_OPEN_FB__EMI_DDR_OPEN_FEEDBACK
value|0x5140
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_CLK__EMI_CLK
value|0x5150
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_DQS0__EMI_DQS0
value|0x5160
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_DQS1__EMI_DQS1
value|0x5170
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_DDR_OPEN__EMI_DDR_OPEN
value|0x51a0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_A00__EMI_ADDR0
value|0x6000
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_A01__EMI_ADDR1
value|0x6010
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_A02__EMI_ADDR2
value|0x6020
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_A03__EMI_ADDR3
value|0x6030
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_A04__EMI_ADDR4
value|0x6040
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_A05__EMI_ADDR5
value|0x6050
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_A06__EMI_ADDR6
value|0x6060
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_A07__EMI_ADDR7
value|0x6070
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_A08__EMI_ADDR8
value|0x6080
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_A09__EMI_ADDR9
value|0x6090
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_A10__EMI_ADDR10
value|0x60a0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_A11__EMI_ADDR11
value|0x60b0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_A12__EMI_ADDR12
value|0x60c0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_A13__EMI_ADDR13
value|0x60d0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_A14__EMI_ADDR14
value|0x60e0
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_BA0__EMI_BA0
value|0x6100
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_BA1__EMI_BA1
value|0x6110
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_BA2__EMI_BA2
value|0x6120
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_CASN__EMI_CASN
value|0x6130
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_RASN__EMI_RASN
value|0x6140
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_WEN__EMI_WEN
value|0x6150
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_CE0N__EMI_CE0N
value|0x6160
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_CE1N__EMI_CE1N
value|0x6170
end_define

begin_define
define|#
directive|define
name|MX28_PAD_EMI_CKE__EMI_CKE
value|0x6180
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_D00__SSP1_D0
value|0x0001
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_D01__SSP1_D1
value|0x0011
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_D02__SSP1_D2
value|0x0021
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_D03__SSP1_D3
value|0x0031
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_D04__SSP1_D4
value|0x0041
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_D05__SSP1_D5
value|0x0051
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_D06__SSP1_D6
value|0x0061
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_D07__SSP1_D7
value|0x0071
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_CE0N__SSP3_D0
value|0x0101
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_CE1N__SSP3_D3
value|0x0111
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_CE2N__CAN1_TX
value|0x0121
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_CE3N__CAN1_RX
value|0x0131
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_RDY0__SSP1_CARD_DETECT
value|0x0141
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_RDY1__SSP1_CMD
value|0x0151
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_RDY2__CAN0_TX
value|0x0161
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_RDY3__CAN0_RX
value|0x0171
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_RDN__SSP3_SCK
value|0x0181
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_WRN__SSP1_SCK
value|0x0191
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_ALE__SSP3_D1
value|0x01a1
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_CLE__SSP3_D2
value|0x01b1
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_RESETN__SSP3_CMD
value|0x01c1
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D03__ETM_DA8
value|0x1031
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D04__ETM_DA9
value|0x1041
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D08__ETM_DA3
value|0x1081
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D09__ETM_DA4
value|0x1091
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D20__ENET1_1588_EVENT2_OUT
value|0x1141
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D21__ENET1_1588_EVENT2_IN
value|0x1151
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D22__ENET1_1588_EVENT3_OUT
value|0x1161
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D23__ENET1_1588_EVENT3_IN
value|0x1171
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_RD_E__LCD_VSYNC
value|0x1181
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_WR_RWN__LCD_HSYNC
value|0x1191
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_RS__LCD_DOTCLK
value|0x11a1
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_CS__LCD_ENABLE
value|0x11b1
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_VSYNC__SAIF1_SDATA0
value|0x11c1
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_HSYNC__SAIF1_SDATA1
value|0x11d1
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_DOTCLK__SAIF1_MCLK
value|0x11e1
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP0_DATA4__SSP2_D0
value|0x2041
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP0_DATA5__SSP2_D3
value|0x2051
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP0_DATA6__SSP2_CMD
value|0x2061
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP0_DATA7__SSP2_SCK
value|0x2071
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP1_SCK__SSP2_D1
value|0x20c1
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP1_CMD__SSP2_D2
value|0x20d1
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP1_DATA0__SSP2_D6
value|0x20e1
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP1_DATA3__SSP2_D7
value|0x20f1
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP2_SCK__AUART2_RX
value|0x2101
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP2_MOSI__AUART2_TX
value|0x2111
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP2_MISO__AUART3_RX
value|0x2121
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP2_SS0__AUART3_TX
value|0x2131
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP2_SS1__SSP2_D1
value|0x2141
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP2_SS2__SSP2_D2
value|0x2151
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP3_SCK__AUART4_TX
value|0x2181
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP3_MOSI__AUART4_RX
value|0x2191
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP3_MISO__AUART4_RTS
value|0x21a1
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP3_SS0__AUART4_CTS
value|0x21b1
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART0_RX__I2C0_SCL
value|0x3001
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART0_TX__I2C0_SDA
value|0x3011
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART0_CTS__AUART4_RX
value|0x3021
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART0_RTS__AUART4_TX
value|0x3031
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART1_RX__SSP2_CARD_DETECT
value|0x3041
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART1_TX__SSP3_CARD_DETECT
value|0x3051
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART1_CTS__USB0_OVERCURRENT
value|0x3061
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART1_RTS__USB0_ID
value|0x3071
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART2_RX__SSP3_D1
value|0x3081
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART2_TX__SSP3_D2
value|0x3091
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART2_CTS__I2C1_SCL
value|0x30a1
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART2_RTS__I2C1_SDA
value|0x30b1
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART3_RX__CAN0_TX
value|0x30c1
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART3_TX__CAN0_RX
value|0x30d1
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART3_CTS__CAN1_TX
value|0x30e1
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART3_RTS__CAN1_RX
value|0x30f1
end_define

begin_define
define|#
directive|define
name|MX28_PAD_PWM0__I2C1_SCL
value|0x3101
end_define

begin_define
define|#
directive|define
name|MX28_PAD_PWM1__I2C1_SDA
value|0x3111
end_define

begin_define
define|#
directive|define
name|MX28_PAD_PWM2__USB0_ID
value|0x3121
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SAIF0_MCLK__PWM_3
value|0x3141
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SAIF0_LRCLK__PWM_4
value|0x3151
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SAIF0_BITCLK__PWM_5
value|0x3161
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SAIF0_SDATA0__PWM_6
value|0x3171
end_define

begin_define
define|#
directive|define
name|MX28_PAD_I2C0_SCL__TIMROT_ROTARYA
value|0x3181
end_define

begin_define
define|#
directive|define
name|MX28_PAD_I2C0_SDA__TIMROT_ROTARYB
value|0x3191
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SAIF1_SDATA0__PWM_7
value|0x31a1
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_RESET__LCD_VSYNC
value|0x31e1
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_MDC__GPMI_CE4N
value|0x4001
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_MDIO__GPMI_CE5N
value|0x4011
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_RX_EN__GPMI_CE6N
value|0x4021
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_RXD0__GPMI_CE7N
value|0x4031
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_RXD1__GPMI_READY4
value|0x4041
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_TX_CLK__HSADC_TRIGGER
value|0x4051
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_TX_EN__GPMI_READY5
value|0x4061
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_TXD0__GPMI_READY6
value|0x4071
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_TXD1__GPMI_READY7
value|0x4081
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_RXD2__ENET1_RXD0
value|0x4091
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_RXD3__ENET1_RXD1
value|0x40a1
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_TXD2__ENET1_TXD0
value|0x40b1
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_TXD3__ENET1_TXD1
value|0x40c1
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_RX_CLK__ENET0_RX_ER
value|0x40d1
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_COL__ENET1_TX_EN
value|0x40e1
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_CRS__ENET1_RX_EN
value|0x40f1
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_CE2N__ENET0_RX_ER
value|0x0122
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_CE3N__SAIF1_MCLK
value|0x0132
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_RDY0__USB0_ID
value|0x0142
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_RDY2__ENET0_TX_ER
value|0x0162
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_RDY3__HSADC_TRIGGER
value|0x0172
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_ALE__SSP3_D4
value|0x01a2
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_CLE__SSP3_D5
value|0x01b2
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D00__ETM_DA0
value|0x1002
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D01__ETM_DA1
value|0x1012
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D02__ETM_DA2
value|0x1022
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D03__ETM_DA3
value|0x1032
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D04__ETM_DA4
value|0x1042
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D05__ETM_DA5
value|0x1052
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D06__ETM_DA6
value|0x1062
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D07__ETM_DA7
value|0x1072
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D08__ETM_DA8
value|0x1082
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D09__ETM_DA9
value|0x1092
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D10__ETM_DA10
value|0x10a2
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D11__ETM_DA11
value|0x10b2
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D12__ETM_DA12
value|0x10c2
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D13__ETM_DA13
value|0x10d2
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D14__ETM_DA14
value|0x10e2
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D15__ETM_DA15
value|0x10f2
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D16__ETM_DA7
value|0x1102
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D17__ETM_DA6
value|0x1112
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D18__ETM_DA5
value|0x1122
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D19__ETM_DA4
value|0x1132
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D20__ETM_DA3
value|0x1142
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D21__ETM_DA2
value|0x1152
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D22__ETM_DA1
value|0x1162
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D23__ETM_DA0
value|0x1172
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_RD_E__ETM_TCTL
value|0x1182
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_WR_RWN__ETM_TCLK
value|0x1192
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_HSYNC__ETM_TCTL
value|0x11d2
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_DOTCLK__ETM_TCLK
value|0x11e2
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP1_SCK__ENET0_1588_EVENT2_OUT
value|0x20c2
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP1_CMD__ENET0_1588_EVENT2_IN
value|0x20d2
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP1_DATA0__ENET0_1588_EVENT3_OUT
value|0x20e2
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP1_DATA3__ENET0_1588_EVENT3_IN
value|0x20f2
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP2_SCK__SAIF0_SDATA1
value|0x2102
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP2_MOSI__SAIF0_SDATA2
value|0x2112
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP2_MISO__SAIF1_SDATA1
value|0x2122
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP2_SS0__SAIF1_SDATA2
value|0x2132
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP2_SS1__USB1_OVERCURRENT
value|0x2142
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP2_SS2__USB0_OVERCURRENT
value|0x2152
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP3_SCK__ENET1_1588_EVENT0_OUT
value|0x2182
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP3_MOSI__ENET1_1588_EVENT0_IN
value|0x2192
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP3_MISO__ENET1_1588_EVENT1_OUT
value|0x21a2
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP3_SS0__ENET1_1588_EVENT1_IN
value|0x21b2
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART0_RX__DUART_CTS
value|0x3002
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART0_TX__DUART_RTS
value|0x3012
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART0_CTS__DUART_RX
value|0x3022
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART0_RTS__DUART_TX
value|0x3032
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART1_RX__PWM_0
value|0x3042
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART1_TX__PWM_1
value|0x3052
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART1_CTS__TIMROT_ROTARYA
value|0x3062
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART1_RTS__TIMROT_ROTARYB
value|0x3072
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART2_RX__SSP3_D4
value|0x3082
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART2_TX__SSP3_D5
value|0x3092
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART2_CTS__SAIF1_BITCLK
value|0x30a2
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART2_RTS__SAIF1_LRCLK
value|0x30b2
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART3_RX__ENET0_1588_EVENT0_OUT
value|0x30c2
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART3_TX__ENET0_1588_EVENT0_IN
value|0x30d2
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART3_CTS__ENET0_1588_EVENT1_OUT
value|0x30e2
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART3_RTS__ENET0_1588_EVENT1_IN
value|0x30f2
end_define

begin_define
define|#
directive|define
name|MX28_PAD_PWM0__DUART_RX
value|0x3102
end_define

begin_define
define|#
directive|define
name|MX28_PAD_PWM1__DUART_TX
value|0x3112
end_define

begin_define
define|#
directive|define
name|MX28_PAD_PWM2__USB1_OVERCURRENT
value|0x3122
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SAIF0_MCLK__AUART4_CTS
value|0x3142
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SAIF0_LRCLK__AUART4_RTS
value|0x3152
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SAIF0_BITCLK__AUART4_RX
value|0x3162
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SAIF0_SDATA0__AUART4_TX
value|0x3172
end_define

begin_define
define|#
directive|define
name|MX28_PAD_I2C0_SCL__DUART_RX
value|0x3182
end_define

begin_define
define|#
directive|define
name|MX28_PAD_I2C0_SDA__DUART_TX
value|0x3192
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SAIF1_SDATA0__SAIF0_SDATA1
value|0x31a2
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SPDIF__ENET1_RX_ER
value|0x31b2
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_MDC__SAIF0_SDATA1
value|0x4002
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_MDIO__SAIF0_SDATA2
value|0x4012
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_RX_EN__SAIF1_SDATA1
value|0x4022
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_RXD0__SAIF1_SDATA2
value|0x4032
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_TX_CLK__ENET0_1588_EVENT2_OUT
value|0x4052
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_RXD2__ENET0_1588_EVENT0_OUT
value|0x4092
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_RXD3__ENET0_1588_EVENT0_IN
value|0x40a2
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_TXD2__ENET0_1588_EVENT1_OUT
value|0x40b2
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_TXD3__ENET0_1588_EVENT1_IN
value|0x40c2
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_RX_CLK__ENET0_1588_EVENT2_IN
value|0x40d2
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_COL__ENET0_1588_EVENT3_OUT
value|0x40e2
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_CRS__ENET0_1588_EVENT3_IN
value|0x40f2
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_D00__GPIO_0_0
value|0x0003
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_D01__GPIO_0_1
value|0x0013
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_D02__GPIO_0_2
value|0x0023
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_D03__GPIO_0_3
value|0x0033
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_D04__GPIO_0_4
value|0x0043
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_D05__GPIO_0_5
value|0x0053
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_D06__GPIO_0_6
value|0x0063
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_D07__GPIO_0_7
value|0x0073
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_CE0N__GPIO_0_16
value|0x0103
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_CE1N__GPIO_0_17
value|0x0113
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_CE2N__GPIO_0_18
value|0x0123
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_CE3N__GPIO_0_19
value|0x0133
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_RDY0__GPIO_0_20
value|0x0143
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_RDY1__GPIO_0_21
value|0x0153
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_RDY2__GPIO_0_22
value|0x0163
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_RDY3__GPIO_0_23
value|0x0173
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_RDN__GPIO_0_24
value|0x0183
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_WRN__GPIO_0_25
value|0x0193
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_ALE__GPIO_0_26
value|0x01a3
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_CLE__GPIO_0_27
value|0x01b3
end_define

begin_define
define|#
directive|define
name|MX28_PAD_GPMI_RESETN__GPIO_0_28
value|0x01c3
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D00__GPIO_1_0
value|0x1003
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D01__GPIO_1_1
value|0x1013
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D02__GPIO_1_2
value|0x1023
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D03__GPIO_1_3
value|0x1033
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D04__GPIO_1_4
value|0x1043
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D05__GPIO_1_5
value|0x1053
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D06__GPIO_1_6
value|0x1063
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D07__GPIO_1_7
value|0x1073
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D08__GPIO_1_8
value|0x1083
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D09__GPIO_1_9
value|0x1093
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D10__GPIO_1_10
value|0x10a3
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D11__GPIO_1_11
value|0x10b3
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D12__GPIO_1_12
value|0x10c3
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D13__GPIO_1_13
value|0x10d3
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D14__GPIO_1_14
value|0x10e3
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D15__GPIO_1_15
value|0x10f3
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D16__GPIO_1_16
value|0x1103
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D17__GPIO_1_17
value|0x1113
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D18__GPIO_1_18
value|0x1123
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D19__GPIO_1_19
value|0x1133
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D20__GPIO_1_20
value|0x1143
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D21__GPIO_1_21
value|0x1153
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D22__GPIO_1_22
value|0x1163
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_D23__GPIO_1_23
value|0x1173
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_RD_E__GPIO_1_24
value|0x1183
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_WR_RWN__GPIO_1_25
value|0x1193
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_RS__GPIO_1_26
value|0x11a3
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_CS__GPIO_1_27
value|0x11b3
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_VSYNC__GPIO_1_28
value|0x11c3
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_HSYNC__GPIO_1_29
value|0x11d3
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_DOTCLK__GPIO_1_30
value|0x11e3
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_ENABLE__GPIO_1_31
value|0x11f3
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP0_DATA0__GPIO_2_0
value|0x2003
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP0_DATA1__GPIO_2_1
value|0x2013
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP0_DATA2__GPIO_2_2
value|0x2023
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP0_DATA3__GPIO_2_3
value|0x2033
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP0_DATA4__GPIO_2_4
value|0x2043
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP0_DATA5__GPIO_2_5
value|0x2053
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP0_DATA6__GPIO_2_6
value|0x2063
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP0_DATA7__GPIO_2_7
value|0x2073
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP0_CMD__GPIO_2_8
value|0x2083
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP0_DETECT__GPIO_2_9
value|0x2093
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP0_SCK__GPIO_2_10
value|0x20a3
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP1_SCK__GPIO_2_12
value|0x20c3
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP1_CMD__GPIO_2_13
value|0x20d3
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP1_DATA0__GPIO_2_14
value|0x20e3
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP1_DATA3__GPIO_2_15
value|0x20f3
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP2_SCK__GPIO_2_16
value|0x2103
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP2_MOSI__GPIO_2_17
value|0x2113
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP2_MISO__GPIO_2_18
value|0x2123
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP2_SS0__GPIO_2_19
value|0x2133
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP2_SS1__GPIO_2_20
value|0x2143
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP2_SS2__GPIO_2_21
value|0x2153
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP3_SCK__GPIO_2_24
value|0x2183
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP3_MOSI__GPIO_2_25
value|0x2193
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP3_MISO__GPIO_2_26
value|0x21a3
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SSP3_SS0__GPIO_2_27
value|0x21b3
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART0_RX__GPIO_3_0
value|0x3003
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART0_TX__GPIO_3_1
value|0x3013
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART0_CTS__GPIO_3_2
value|0x3023
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART0_RTS__GPIO_3_3
value|0x3033
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART1_RX__GPIO_3_4
value|0x3043
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART1_TX__GPIO_3_5
value|0x3053
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART1_CTS__GPIO_3_6
value|0x3063
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART1_RTS__GPIO_3_7
value|0x3073
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART2_RX__GPIO_3_8
value|0x3083
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART2_TX__GPIO_3_9
value|0x3093
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART2_CTS__GPIO_3_10
value|0x30a3
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART2_RTS__GPIO_3_11
value|0x30b3
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART3_RX__GPIO_3_12
value|0x30c3
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART3_TX__GPIO_3_13
value|0x30d3
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART3_CTS__GPIO_3_14
value|0x30e3
end_define

begin_define
define|#
directive|define
name|MX28_PAD_AUART3_RTS__GPIO_3_15
value|0x30f3
end_define

begin_define
define|#
directive|define
name|MX28_PAD_PWM0__GPIO_3_16
value|0x3103
end_define

begin_define
define|#
directive|define
name|MX28_PAD_PWM1__GPIO_3_17
value|0x3113
end_define

begin_define
define|#
directive|define
name|MX28_PAD_PWM2__GPIO_3_18
value|0x3123
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SAIF0_MCLK__GPIO_3_20
value|0x3143
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SAIF0_LRCLK__GPIO_3_21
value|0x3153
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SAIF0_BITCLK__GPIO_3_22
value|0x3163
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SAIF0_SDATA0__GPIO_3_23
value|0x3173
end_define

begin_define
define|#
directive|define
name|MX28_PAD_I2C0_SCL__GPIO_3_24
value|0x3183
end_define

begin_define
define|#
directive|define
name|MX28_PAD_I2C0_SDA__GPIO_3_25
value|0x3193
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SAIF1_SDATA0__GPIO_3_26
value|0x31a3
end_define

begin_define
define|#
directive|define
name|MX28_PAD_SPDIF__GPIO_3_27
value|0x31b3
end_define

begin_define
define|#
directive|define
name|MX28_PAD_PWM3__GPIO_3_28
value|0x31c3
end_define

begin_define
define|#
directive|define
name|MX28_PAD_PWM4__GPIO_3_29
value|0x31d3
end_define

begin_define
define|#
directive|define
name|MX28_PAD_LCD_RESET__GPIO_3_30
value|0x31e3
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_MDC__GPIO_4_0
value|0x4003
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_MDIO__GPIO_4_1
value|0x4013
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_RX_EN__GPIO_4_2
value|0x4023
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_RXD0__GPIO_4_3
value|0x4033
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_RXD1__GPIO_4_4
value|0x4043
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_TX_CLK__GPIO_4_5
value|0x4053
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_TX_EN__GPIO_4_6
value|0x4063
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_TXD0__GPIO_4_7
value|0x4073
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_TXD1__GPIO_4_8
value|0x4083
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_RXD2__GPIO_4_9
value|0x4093
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_RXD3__GPIO_4_10
value|0x40a3
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_TXD2__GPIO_4_11
value|0x40b3
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_TXD3__GPIO_4_12
value|0x40c3
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_RX_CLK__GPIO_4_13
value|0x40d3
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_COL__GPIO_4_14
value|0x40e3
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET0_CRS__GPIO_4_15
value|0x40f3
end_define

begin_define
define|#
directive|define
name|MX28_PAD_ENET_CLK__GPIO_4_16
value|0x4103
end_define

begin_define
define|#
directive|define
name|MX28_PAD_JTAG_RTCK__GPIO_4_20
value|0x4143
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DT_BINDINGS_MX28_PINCTRL_H__ */
end_comment

end_unit

