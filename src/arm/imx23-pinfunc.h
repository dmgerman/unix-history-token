begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Header providing constants for i.MX23 pinctrl bindings.  *  * Copyright (C) 2013 Lothar WaÃmann<LW@KARO-electronics.de>  *  * The code contained herein is licensed under the GNU General Public  * License. You may obtain a copy of the GNU General Public License  * Version 2 at the following locations:  *  * http://www.opensource.org/licenses/gpl-license.html  * http://www.gnu.org/copyleft/gpl.html  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_MX23_PINCTRL_H__
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_MX23_PINCTRL_H__
end_define

begin_include
include|#
directive|include
file|"mxs-pinfunc.h"
end_include

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D00__GPMI_D00
value|0x0000
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D01__GPMI_D01
value|0x0010
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D02__GPMI_D02
value|0x0020
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D03__GPMI_D03
value|0x0030
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D04__GPMI_D04
value|0x0040
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D05__GPMI_D05
value|0x0050
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D06__GPMI_D06
value|0x0060
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D07__GPMI_D07
value|0x0070
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D08__GPMI_D08
value|0x0080
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D09__GPMI_D09
value|0x0090
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D10__GPMI_D10
value|0x00a0
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D11__GPMI_D11
value|0x00b0
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D12__GPMI_D12
value|0x00c0
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D13__GPMI_D13
value|0x00d0
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D14__GPMI_D14
value|0x00e0
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D15__GPMI_D15
value|0x00f0
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_CLE__GPMI_CLE
value|0x0100
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_ALE__GPMI_ALE
value|0x0110
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_CE2N__GPMI_CE2N
value|0x0120
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_RDY0__GPMI_RDY0
value|0x0130
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_RDY1__GPMI_RDY1
value|0x0140
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_RDY2__GPMI_RDY2
value|0x0150
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_RDY3__GPMI_RDY3
value|0x0160
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_WPN__GPMI_WPN
value|0x0170
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_WRN__GPMI_WRN
value|0x0180
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_RDN__GPMI_RDN
value|0x0190
end_define

begin_define
define|#
directive|define
name|MX23_PAD_AUART1_CTS__AUART1_CTS
value|0x01a0
end_define

begin_define
define|#
directive|define
name|MX23_PAD_AUART1_RTS__AUART1_RTS
value|0x01b0
end_define

begin_define
define|#
directive|define
name|MX23_PAD_AUART1_RX__AUART1_RX
value|0x01c0
end_define

begin_define
define|#
directive|define
name|MX23_PAD_AUART1_TX__AUART1_TX
value|0x01d0
end_define

begin_define
define|#
directive|define
name|MX23_PAD_I2C_SCL__I2C_SCL
value|0x01e0
end_define

begin_define
define|#
directive|define
name|MX23_PAD_I2C_SDA__I2C_SDA
value|0x01f0
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D00__LCD_D00
value|0x1000
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D01__LCD_D01
value|0x1010
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D02__LCD_D02
value|0x1020
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D03__LCD_D03
value|0x1030
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D04__LCD_D04
value|0x1040
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D05__LCD_D05
value|0x1050
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D06__LCD_D06
value|0x1060
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D07__LCD_D07
value|0x1070
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D08__LCD_D08
value|0x1080
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D09__LCD_D09
value|0x1090
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D10__LCD_D10
value|0x10a0
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D11__LCD_D11
value|0x10b0
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D12__LCD_D12
value|0x10c0
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D13__LCD_D13
value|0x10d0
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D14__LCD_D14
value|0x10e0
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D15__LCD_D15
value|0x10f0
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D16__LCD_D16
value|0x1100
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D17__LCD_D17
value|0x1110
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_RESET__LCD_RESET
value|0x1120
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_RS__LCD_RS
value|0x1130
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_WR__LCD_WR
value|0x1140
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_CS__LCD_CS
value|0x1150
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_DOTCK__LCD_DOTCK
value|0x1160
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_ENABLE__LCD_ENABLE
value|0x1170
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_HSYNC__LCD_HSYNC
value|0x1180
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_VSYNC__LCD_VSYNC
value|0x1190
end_define

begin_define
define|#
directive|define
name|MX23_PAD_PWM0__PWM0
value|0x11a0
end_define

begin_define
define|#
directive|define
name|MX23_PAD_PWM1__PWM1
value|0x11b0
end_define

begin_define
define|#
directive|define
name|MX23_PAD_PWM2__PWM2
value|0x11c0
end_define

begin_define
define|#
directive|define
name|MX23_PAD_PWM3__PWM3
value|0x11d0
end_define

begin_define
define|#
directive|define
name|MX23_PAD_PWM4__PWM4
value|0x11e0
end_define

begin_define
define|#
directive|define
name|MX23_PAD_SSP1_CMD__SSP1_CMD
value|0x2000
end_define

begin_define
define|#
directive|define
name|MX23_PAD_SSP1_DETECT__SSP1_DETECT
value|0x2010
end_define

begin_define
define|#
directive|define
name|MX23_PAD_SSP1_DATA0__SSP1_DATA0
value|0x2020
end_define

begin_define
define|#
directive|define
name|MX23_PAD_SSP1_DATA1__SSP1_DATA1
value|0x2030
end_define

begin_define
define|#
directive|define
name|MX23_PAD_SSP1_DATA2__SSP1_DATA2
value|0x2040
end_define

begin_define
define|#
directive|define
name|MX23_PAD_SSP1_DATA3__SSP1_DATA3
value|0x2050
end_define

begin_define
define|#
directive|define
name|MX23_PAD_SSP1_SCK__SSP1_SCK
value|0x2060
end_define

begin_define
define|#
directive|define
name|MX23_PAD_ROTARYA__ROTARYA
value|0x2070
end_define

begin_define
define|#
directive|define
name|MX23_PAD_ROTARYB__ROTARYB
value|0x2080
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_A00__EMI_A00
value|0x2090
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_A01__EMI_A01
value|0x20a0
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_A02__EMI_A02
value|0x20b0
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_A03__EMI_A03
value|0x20c0
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_A04__EMI_A04
value|0x20d0
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_A05__EMI_A05
value|0x20e0
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_A06__EMI_A06
value|0x20f0
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_A07__EMI_A07
value|0x2100
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_A08__EMI_A08
value|0x2110
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_A09__EMI_A09
value|0x2120
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_A10__EMI_A10
value|0x2130
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_A11__EMI_A11
value|0x2140
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_A12__EMI_A12
value|0x2150
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_BA0__EMI_BA0
value|0x2160
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_BA1__EMI_BA1
value|0x2170
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_CASN__EMI_CASN
value|0x2180
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_CE0N__EMI_CE0N
value|0x2190
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_CE1N__EMI_CE1N
value|0x21a0
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_CE1N__GPMI_CE1N
value|0x21b0
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_CE0N__GPMI_CE0N
value|0x21c0
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_CKE__EMI_CKE
value|0x21d0
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_RASN__EMI_RASN
value|0x21e0
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_WEN__EMI_WEN
value|0x21f0
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_D00__EMI_D00
value|0x3000
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_D01__EMI_D01
value|0x3010
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_D02__EMI_D02
value|0x3020
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_D03__EMI_D03
value|0x3030
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_D04__EMI_D04
value|0x3040
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_D05__EMI_D05
value|0x3050
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_D06__EMI_D06
value|0x3060
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_D07__EMI_D07
value|0x3070
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_D08__EMI_D08
value|0x3080
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_D09__EMI_D09
value|0x3090
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_D10__EMI_D10
value|0x30a0
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_D11__EMI_D11
value|0x30b0
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_D12__EMI_D12
value|0x30c0
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_D13__EMI_D13
value|0x30d0
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_D14__EMI_D14
value|0x30e0
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_D15__EMI_D15
value|0x30f0
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_DQM0__EMI_DQM0
value|0x3100
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_DQM1__EMI_DQM1
value|0x3110
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_DQS0__EMI_DQS0
value|0x3120
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_DQS1__EMI_DQS1
value|0x3130
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_CLK__EMI_CLK
value|0x3140
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_CLKN__EMI_CLKN
value|0x3150
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D00__LCD_D8
value|0x0001
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D01__LCD_D9
value|0x0011
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D02__LCD_D10
value|0x0021
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D03__LCD_D11
value|0x0031
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D04__LCD_D12
value|0x0041
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D05__LCD_D13
value|0x0051
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D06__LCD_D14
value|0x0061
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D07__LCD_D15
value|0x0071
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D08__LCD_D18
value|0x0081
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D09__LCD_D19
value|0x0091
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D10__LCD_D20
value|0x00a1
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D11__LCD_D21
value|0x00b1
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D12__LCD_D22
value|0x00c1
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D13__LCD_D23
value|0x00d1
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D14__AUART2_RX
value|0x00e1
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D15__AUART2_TX
value|0x00f1
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_CLE__LCD_D16
value|0x0101
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_ALE__LCD_D17
value|0x0111
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_CE2N__ATA_A2
value|0x0121
end_define

begin_define
define|#
directive|define
name|MX23_PAD_AUART1_RTS__IR_CLK
value|0x01b1
end_define

begin_define
define|#
directive|define
name|MX23_PAD_AUART1_RX__IR_RX
value|0x01c1
end_define

begin_define
define|#
directive|define
name|MX23_PAD_AUART1_TX__IR_TX
value|0x01d1
end_define

begin_define
define|#
directive|define
name|MX23_PAD_I2C_SCL__GPMI_RDY2
value|0x01e1
end_define

begin_define
define|#
directive|define
name|MX23_PAD_I2C_SDA__GPMI_CE2N
value|0x01f1
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D00__ETM_DA8
value|0x1001
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D01__ETM_DA9
value|0x1011
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D02__ETM_DA10
value|0x1021
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D03__ETM_DA11
value|0x1031
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D04__ETM_DA12
value|0x1041
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D05__ETM_DA13
value|0x1051
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D06__ETM_DA14
value|0x1061
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D07__ETM_DA15
value|0x1071
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D08__ETM_DA0
value|0x1081
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D09__ETM_DA1
value|0x1091
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D10__ETM_DA2
value|0x10a1
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D11__ETM_DA3
value|0x10b1
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D12__ETM_DA4
value|0x10c1
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D13__ETM_DA5
value|0x10d1
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D14__ETM_DA6
value|0x10e1
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D15__ETM_DA7
value|0x10f1
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_RESET__ETM_TCTL
value|0x1121
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_RS__ETM_TCLK
value|0x1131
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_DOTCK__GPMI_RDY3
value|0x1161
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_ENABLE__I2C_SCL
value|0x1171
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_HSYNC__I2C_SDA
value|0x1181
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_VSYNC__LCD_BUSY
value|0x1191
end_define

begin_define
define|#
directive|define
name|MX23_PAD_PWM0__ROTARYA
value|0x11a1
end_define

begin_define
define|#
directive|define
name|MX23_PAD_PWM1__ROTARYB
value|0x11b1
end_define

begin_define
define|#
directive|define
name|MX23_PAD_PWM2__GPMI_RDY3
value|0x11c1
end_define

begin_define
define|#
directive|define
name|MX23_PAD_PWM3__ETM_TCTL
value|0x11d1
end_define

begin_define
define|#
directive|define
name|MX23_PAD_PWM4__ETM_TCLK
value|0x11e1
end_define

begin_define
define|#
directive|define
name|MX23_PAD_SSP1_DETECT__GPMI_CE3N
value|0x2011
end_define

begin_define
define|#
directive|define
name|MX23_PAD_SSP1_DATA1__I2C_SCL
value|0x2031
end_define

begin_define
define|#
directive|define
name|MX23_PAD_SSP1_DATA2__I2C_SDA
value|0x2041
end_define

begin_define
define|#
directive|define
name|MX23_PAD_ROTARYA__AUART2_RTS
value|0x2071
end_define

begin_define
define|#
directive|define
name|MX23_PAD_ROTARYB__AUART2_CTS
value|0x2081
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D00__SSP2_DATA0
value|0x0002
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D01__SSP2_DATA1
value|0x0012
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D02__SSP2_DATA2
value|0x0022
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D03__SSP2_DATA3
value|0x0032
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D04__SSP2_DATA4
value|0x0042
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D05__SSP2_DATA5
value|0x0052
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D06__SSP2_DATA6
value|0x0062
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D07__SSP2_DATA7
value|0x0072
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D08__SSP1_DATA4
value|0x0082
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D09__SSP1_DATA5
value|0x0092
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D10__SSP1_DATA6
value|0x00a2
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D11__SSP1_DATA7
value|0x00b2
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D15__GPMI_CE3N
value|0x00f2
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_RDY0__SSP2_DETECT
value|0x0132
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_RDY1__SSP2_CMD
value|0x0142
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_WRN__SSP2_SCK
value|0x0182
end_define

begin_define
define|#
directive|define
name|MX23_PAD_AUART1_CTS__SSP1_DATA4
value|0x01a2
end_define

begin_define
define|#
directive|define
name|MX23_PAD_AUART1_RTS__SSP1_DATA5
value|0x01b2
end_define

begin_define
define|#
directive|define
name|MX23_PAD_AUART1_RX__SSP1_DATA6
value|0x01c2
end_define

begin_define
define|#
directive|define
name|MX23_PAD_AUART1_TX__SSP1_DATA7
value|0x01d2
end_define

begin_define
define|#
directive|define
name|MX23_PAD_I2C_SCL__AUART1_TX
value|0x01e2
end_define

begin_define
define|#
directive|define
name|MX23_PAD_I2C_SDA__AUART1_RX
value|0x01f2
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D08__SAIF2_SDATA0
value|0x1082
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D09__SAIF1_SDATA0
value|0x1092
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D10__SAIF_MCLK_BITCLK
value|0x10a2
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D11__SAIF_LRCLK
value|0x10b2
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D12__SAIF2_SDATA1
value|0x10c2
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D13__SAIF2_SDATA2
value|0x10d2
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D14__SAIF1_SDATA2
value|0x10e2
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D15__SAIF1_SDATA1
value|0x10f2
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D16__SAIF_ALT_BITCLK
value|0x1102
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_RESET__GPMI_CE3N
value|0x1122
end_define

begin_define
define|#
directive|define
name|MX23_PAD_PWM0__DUART_RX
value|0x11a2
end_define

begin_define
define|#
directive|define
name|MX23_PAD_PWM1__DUART_TX
value|0x11b2
end_define

begin_define
define|#
directive|define
name|MX23_PAD_PWM3__AUART1_CTS
value|0x11d2
end_define

begin_define
define|#
directive|define
name|MX23_PAD_PWM4__AUART1_RTS
value|0x11e2
end_define

begin_define
define|#
directive|define
name|MX23_PAD_SSP1_CMD__JTAG_TDO
value|0x2002
end_define

begin_define
define|#
directive|define
name|MX23_PAD_SSP1_DETECT__USB_OTG_ID
value|0x2012
end_define

begin_define
define|#
directive|define
name|MX23_PAD_SSP1_DATA0__JTAG_TDI
value|0x2022
end_define

begin_define
define|#
directive|define
name|MX23_PAD_SSP1_DATA1__JTAG_TCLK
value|0x2032
end_define

begin_define
define|#
directive|define
name|MX23_PAD_SSP1_DATA2__JTAG_RTCK
value|0x2042
end_define

begin_define
define|#
directive|define
name|MX23_PAD_SSP1_DATA3__JTAG_TMS
value|0x2052
end_define

begin_define
define|#
directive|define
name|MX23_PAD_SSP1_SCK__JTAG_TRST
value|0x2062
end_define

begin_define
define|#
directive|define
name|MX23_PAD_ROTARYA__SPDIF
value|0x2072
end_define

begin_define
define|#
directive|define
name|MX23_PAD_ROTARYB__GPMI_CE3N
value|0x2082
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D00__GPIO_0_0
value|0x0003
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D01__GPIO_0_1
value|0x0013
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D02__GPIO_0_2
value|0x0023
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D03__GPIO_0_3
value|0x0033
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D04__GPIO_0_4
value|0x0043
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D05__GPIO_0_5
value|0x0053
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D06__GPIO_0_6
value|0x0063
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D07__GPIO_0_7
value|0x0073
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D08__GPIO_0_8
value|0x0083
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D09__GPIO_0_9
value|0x0093
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D10__GPIO_0_10
value|0x00a3
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D11__GPIO_0_11
value|0x00b3
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D12__GPIO_0_12
value|0x00c3
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D13__GPIO_0_13
value|0x00d3
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D14__GPIO_0_14
value|0x00e3
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_D15__GPIO_0_15
value|0x00f3
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_CLE__GPIO_0_16
value|0x0103
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_ALE__GPIO_0_17
value|0x0113
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_CE2N__GPIO_0_18
value|0x0123
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_RDY0__GPIO_0_19
value|0x0133
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_RDY1__GPIO_0_20
value|0x0143
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_RDY2__GPIO_0_21
value|0x0153
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_RDY3__GPIO_0_22
value|0x0163
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_WPN__GPIO_0_23
value|0x0173
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_WRN__GPIO_0_24
value|0x0183
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_RDN__GPIO_0_25
value|0x0193
end_define

begin_define
define|#
directive|define
name|MX23_PAD_AUART1_CTS__GPIO_0_26
value|0x01a3
end_define

begin_define
define|#
directive|define
name|MX23_PAD_AUART1_RTS__GPIO_0_27
value|0x01b3
end_define

begin_define
define|#
directive|define
name|MX23_PAD_AUART1_RX__GPIO_0_28
value|0x01c3
end_define

begin_define
define|#
directive|define
name|MX23_PAD_AUART1_TX__GPIO_0_29
value|0x01d3
end_define

begin_define
define|#
directive|define
name|MX23_PAD_I2C_SCL__GPIO_0_30
value|0x01e3
end_define

begin_define
define|#
directive|define
name|MX23_PAD_I2C_SDA__GPIO_0_31
value|0x01f3
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D00__GPIO_1_0
value|0x1003
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D01__GPIO_1_1
value|0x1013
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D02__GPIO_1_2
value|0x1023
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D03__GPIO_1_3
value|0x1033
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D04__GPIO_1_4
value|0x1043
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D05__GPIO_1_5
value|0x1053
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D06__GPIO_1_6
value|0x1063
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D07__GPIO_1_7
value|0x1073
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D08__GPIO_1_8
value|0x1083
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D09__GPIO_1_9
value|0x1093
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D10__GPIO_1_10
value|0x10a3
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D11__GPIO_1_11
value|0x10b3
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D12__GPIO_1_12
value|0x10c3
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D13__GPIO_1_13
value|0x10d3
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D14__GPIO_1_14
value|0x10e3
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D15__GPIO_1_15
value|0x10f3
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D16__GPIO_1_16
value|0x1103
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_D17__GPIO_1_17
value|0x1113
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_RESET__GPIO_1_18
value|0x1123
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_RS__GPIO_1_19
value|0x1133
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_WR__GPIO_1_20
value|0x1143
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_CS__GPIO_1_21
value|0x1153
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_DOTCK__GPIO_1_22
value|0x1163
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_ENABLE__GPIO_1_23
value|0x1173
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_HSYNC__GPIO_1_24
value|0x1183
end_define

begin_define
define|#
directive|define
name|MX23_PAD_LCD_VSYNC__GPIO_1_25
value|0x1193
end_define

begin_define
define|#
directive|define
name|MX23_PAD_PWM0__GPIO_1_26
value|0x11a3
end_define

begin_define
define|#
directive|define
name|MX23_PAD_PWM1__GPIO_1_27
value|0x11b3
end_define

begin_define
define|#
directive|define
name|MX23_PAD_PWM2__GPIO_1_28
value|0x11c3
end_define

begin_define
define|#
directive|define
name|MX23_PAD_PWM3__GPIO_1_29
value|0x11d3
end_define

begin_define
define|#
directive|define
name|MX23_PAD_PWM4__GPIO_1_30
value|0x11e3
end_define

begin_define
define|#
directive|define
name|MX23_PAD_SSP1_CMD__GPIO_2_0
value|0x2003
end_define

begin_define
define|#
directive|define
name|MX23_PAD_SSP1_DETECT__GPIO_2_1
value|0x2013
end_define

begin_define
define|#
directive|define
name|MX23_PAD_SSP1_DATA0__GPIO_2_2
value|0x2023
end_define

begin_define
define|#
directive|define
name|MX23_PAD_SSP1_DATA1__GPIO_2_3
value|0x2033
end_define

begin_define
define|#
directive|define
name|MX23_PAD_SSP1_DATA2__GPIO_2_4
value|0x2043
end_define

begin_define
define|#
directive|define
name|MX23_PAD_SSP1_DATA3__GPIO_2_5
value|0x2053
end_define

begin_define
define|#
directive|define
name|MX23_PAD_SSP1_SCK__GPIO_2_6
value|0x2063
end_define

begin_define
define|#
directive|define
name|MX23_PAD_ROTARYA__GPIO_2_7
value|0x2073
end_define

begin_define
define|#
directive|define
name|MX23_PAD_ROTARYB__GPIO_2_8
value|0x2083
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_A00__GPIO_2_9
value|0x2093
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_A01__GPIO_2_10
value|0x20a3
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_A02__GPIO_2_11
value|0x20b3
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_A03__GPIO_2_12
value|0x20c3
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_A04__GPIO_2_13
value|0x20d3
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_A05__GPIO_2_14
value|0x20e3
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_A06__GPIO_2_15
value|0x20f3
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_A07__GPIO_2_16
value|0x2103
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_A08__GPIO_2_17
value|0x2113
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_A09__GPIO_2_18
value|0x2123
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_A10__GPIO_2_19
value|0x2133
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_A11__GPIO_2_20
value|0x2143
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_A12__GPIO_2_21
value|0x2153
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_BA0__GPIO_2_22
value|0x2163
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_BA1__GPIO_2_23
value|0x2173
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_CASN__GPIO_2_24
value|0x2183
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_CE0N__GPIO_2_25
value|0x2193
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_CE1N__GPIO_2_26
value|0x21a3
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_CE1N__GPIO_2_27
value|0x21b3
end_define

begin_define
define|#
directive|define
name|MX23_PAD_GPMI_CE0N__GPIO_2_28
value|0x21c3
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_CKE__GPIO_2_29
value|0x21d3
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_RASN__GPIO_2_30
value|0x21e3
end_define

begin_define
define|#
directive|define
name|MX23_PAD_EMI_WEN__GPIO_2_31
value|0x21f3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DT_BINDINGS_MX23_PINCTRL_H__ */
end_comment

end_unit

