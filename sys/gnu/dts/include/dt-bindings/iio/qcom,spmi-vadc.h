begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2012-2014, The Linux Foundation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 and  * only version 2 as published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_QCOM_SPMI_VADC_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_QCOM_SPMI_VADC_H
end_define

begin_comment
comment|/* Voltage ADC channels */
end_comment

begin_define
define|#
directive|define
name|VADC_USBIN
value|0x00
end_define

begin_define
define|#
directive|define
name|VADC_DCIN
value|0x01
end_define

begin_define
define|#
directive|define
name|VADC_VCHG_SNS
value|0x02
end_define

begin_define
define|#
directive|define
name|VADC_SPARE1_03
value|0x03
end_define

begin_define
define|#
directive|define
name|VADC_USB_ID_MV
value|0x04
end_define

begin_define
define|#
directive|define
name|VADC_VCOIN
value|0x05
end_define

begin_define
define|#
directive|define
name|VADC_VBAT_SNS
value|0x06
end_define

begin_define
define|#
directive|define
name|VADC_VSYS
value|0x07
end_define

begin_define
define|#
directive|define
name|VADC_DIE_TEMP
value|0x08
end_define

begin_define
define|#
directive|define
name|VADC_REF_625MV
value|0x09
end_define

begin_define
define|#
directive|define
name|VADC_REF_1250MV
value|0x0a
end_define

begin_define
define|#
directive|define
name|VADC_CHG_TEMP
value|0x0b
end_define

begin_define
define|#
directive|define
name|VADC_SPARE1
value|0x0c
end_define

begin_define
define|#
directive|define
name|VADC_SPARE2
value|0x0d
end_define

begin_define
define|#
directive|define
name|VADC_GND_REF
value|0x0e
end_define

begin_define
define|#
directive|define
name|VADC_VDD_VADC
value|0x0f
end_define

begin_define
define|#
directive|define
name|VADC_P_MUX1_1_1
value|0x10
end_define

begin_define
define|#
directive|define
name|VADC_P_MUX2_1_1
value|0x11
end_define

begin_define
define|#
directive|define
name|VADC_P_MUX3_1_1
value|0x12
end_define

begin_define
define|#
directive|define
name|VADC_P_MUX4_1_1
value|0x13
end_define

begin_define
define|#
directive|define
name|VADC_P_MUX5_1_1
value|0x14
end_define

begin_define
define|#
directive|define
name|VADC_P_MUX6_1_1
value|0x15
end_define

begin_define
define|#
directive|define
name|VADC_P_MUX7_1_1
value|0x16
end_define

begin_define
define|#
directive|define
name|VADC_P_MUX8_1_1
value|0x17
end_define

begin_define
define|#
directive|define
name|VADC_P_MUX9_1_1
value|0x18
end_define

begin_define
define|#
directive|define
name|VADC_P_MUX10_1_1
value|0x19
end_define

begin_define
define|#
directive|define
name|VADC_P_MUX11_1_1
value|0x1a
end_define

begin_define
define|#
directive|define
name|VADC_P_MUX12_1_1
value|0x1b
end_define

begin_define
define|#
directive|define
name|VADC_P_MUX13_1_1
value|0x1c
end_define

begin_define
define|#
directive|define
name|VADC_P_MUX14_1_1
value|0x1d
end_define

begin_define
define|#
directive|define
name|VADC_P_MUX15_1_1
value|0x1e
end_define

begin_define
define|#
directive|define
name|VADC_P_MUX16_1_1
value|0x1f
end_define

begin_define
define|#
directive|define
name|VADC_P_MUX1_1_3
value|0x20
end_define

begin_define
define|#
directive|define
name|VADC_P_MUX2_1_3
value|0x21
end_define

begin_define
define|#
directive|define
name|VADC_P_MUX3_1_3
value|0x22
end_define

begin_define
define|#
directive|define
name|VADC_P_MUX4_1_3
value|0x23
end_define

begin_define
define|#
directive|define
name|VADC_P_MUX5_1_3
value|0x24
end_define

begin_define
define|#
directive|define
name|VADC_P_MUX6_1_3
value|0x25
end_define

begin_define
define|#
directive|define
name|VADC_P_MUX7_1_3
value|0x26
end_define

begin_define
define|#
directive|define
name|VADC_P_MUX8_1_3
value|0x27
end_define

begin_define
define|#
directive|define
name|VADC_P_MUX9_1_3
value|0x28
end_define

begin_define
define|#
directive|define
name|VADC_P_MUX10_1_3
value|0x29
end_define

begin_define
define|#
directive|define
name|VADC_P_MUX11_1_3
value|0x2a
end_define

begin_define
define|#
directive|define
name|VADC_P_MUX12_1_3
value|0x2b
end_define

begin_define
define|#
directive|define
name|VADC_P_MUX13_1_3
value|0x2c
end_define

begin_define
define|#
directive|define
name|VADC_P_MUX14_1_3
value|0x2d
end_define

begin_define
define|#
directive|define
name|VADC_P_MUX15_1_3
value|0x2e
end_define

begin_define
define|#
directive|define
name|VADC_P_MUX16_1_3
value|0x2f
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX1_BAT_THERM
value|0x30
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX2_BAT_ID
value|0x31
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX3_XO_THERM
value|0x32
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX4_AMUX_THM1
value|0x33
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX5_AMUX_THM2
value|0x34
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX6_AMUX_THM3
value|0x35
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX7_HW_ID
value|0x36
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX8_AMUX_THM4
value|0x37
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX9_AMUX_THM5
value|0x38
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX10_USB_ID
value|0x39
end_define

begin_define
define|#
directive|define
name|VADC_AMUX_PU1
value|0x3a
end_define

begin_define
define|#
directive|define
name|VADC_AMUX_PU2
value|0x3b
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX3_BUF_XO_THERM
value|0x3c
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX1_PU1_BAT_THERM
value|0x70
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX2_PU1_BAT_ID
value|0x71
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX3_PU1_XO_THERM
value|0x72
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX4_PU1_AMUX_THM1
value|0x73
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX5_PU1_AMUX_THM2
value|0x74
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX6_PU1_AMUX_THM3
value|0x75
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX7_PU1_AMUX_HW_ID
value|0x76
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX8_PU1_AMUX_THM4
value|0x77
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX9_PU1_AMUX_THM5
value|0x78
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX10_PU1_AMUX_USB_ID
value|0x79
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX3_BUF_PU1_XO_THERM
value|0x7c
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX1_PU2_BAT_THERM
value|0xb0
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX2_PU2_BAT_ID
value|0xb1
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX3_PU2_XO_THERM
value|0xb2
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX4_PU2_AMUX_THM1
value|0xb3
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX5_PU2_AMUX_THM2
value|0xb4
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX6_PU2_AMUX_THM3
value|0xb5
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX7_PU2_AMUX_HW_ID
value|0xb6
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX8_PU2_AMUX_THM4
value|0xb7
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX9_PU2_AMUX_THM5
value|0xb8
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX10_PU2_AMUX_USB_ID
value|0xb9
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX3_BUF_PU2_XO_THERM
value|0xbc
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX1_PU1_PU2_BAT_THERM
value|0xf0
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX2_PU1_PU2_BAT_ID
value|0xf1
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX3_PU1_PU2_XO_THERM
value|0xf2
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX4_PU1_PU2_AMUX_THM1
value|0xf3
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX5_PU1_PU2_AMUX_THM2
value|0xf4
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX6_PU1_PU2_AMUX_THM3
value|0xf5
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX7_PU1_PU2_AMUX_HW_ID
value|0xf6
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX8_PU1_PU2_AMUX_THM4
value|0xf7
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX9_PU1_PU2_AMUX_THM5
value|0xf8
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX10_PU1_PU2_AMUX_USB_ID
value|0xf9
end_define

begin_define
define|#
directive|define
name|VADC_LR_MUX3_BUF_PU1_PU2_XO_THERM
value|0xfc
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_BINDINGS_QCOM_SPMI_VADC_H */
end_comment

end_unit

