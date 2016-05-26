begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Emmanuel Vadot<manu@freeebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AXP209REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_AXP209REG_H_
end_define

begin_comment
comment|/* Power State Register */
end_comment

begin_define
define|#
directive|define
name|AXP209_PSR
value|0x00
end_define

begin_define
define|#
directive|define
name|AXP209_PSR_ACIN
value|0x80
end_define

begin_define
define|#
directive|define
name|AXP209_PSR_ACIN_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|AXP209_PSR_VBUS
value|0x20
end_define

begin_define
define|#
directive|define
name|AXP209_PSR_VBUS_SHIFT
value|5
end_define

begin_comment
comment|/* Shutdown and battery control */
end_comment

begin_define
define|#
directive|define
name|AXP209_SHUTBAT
value|0x32
end_define

begin_define
define|#
directive|define
name|AXP209_SHUTBAT_SHUTDOWN
value|0x80
end_define

begin_comment
comment|/* Voltage/Current Monitor */
end_comment

begin_define
define|#
directive|define
name|AXP209_ACIN_VOLTAGE
value|0x56
end_define

begin_define
define|#
directive|define
name|AXP209_ACIN_CURRENT
value|0x58
end_define

begin_define
define|#
directive|define
name|AXP209_VBUS_VOLTAGE
value|0x5A
end_define

begin_define
define|#
directive|define
name|AXP209_VBUS_CURRENT
value|0x5C
end_define

begin_define
define|#
directive|define
name|AXP209_BAT_VOLTAGE
value|0x78
end_define

begin_define
define|#
directive|define
name|AXP209_BAT_CHARGE_CURRENT
value|0x7A
end_define

begin_define
define|#
directive|define
name|AXP209_BAT_DISCHARGE_CURRENT
value|0x7C
end_define

begin_define
define|#
directive|define
name|AXP209_VOLT_STEP
value|1700
end_define

begin_define
define|#
directive|define
name|AXP209_BATVOLT_STEP
value|1100
end_define

begin_define
define|#
directive|define
name|AXP209_ACCURRENT_STEP
value|625
end_define

begin_define
define|#
directive|define
name|AXP209_VBUSCURRENT_STEP
value|375
end_define

begin_define
define|#
directive|define
name|AXP209_BATCURRENT_STEP
value|500
end_define

begin_comment
comment|/* Temperature monitor */
end_comment

begin_define
define|#
directive|define
name|AXP209_TEMPMON
value|0x5e
end_define

begin_define
define|#
directive|define
name|AXP209_TEMPMON_MIN
value|1447
end_define

begin_comment
comment|/* -144.7C */
end_comment

begin_comment
comment|/* Sensors conversion macros */
end_comment

begin_define
define|#
directive|define
name|AXP209_SENSOR_H
parameter_list|(
name|a
parameter_list|)
value|((a)<< 4)
end_define

begin_define
define|#
directive|define
name|AXP209_SENSOR_L
parameter_list|(
name|a
parameter_list|)
value|((a)& 0xf)
end_define

begin_define
define|#
directive|define
name|AXP209_SENSOR_BAT_H
parameter_list|(
name|a
parameter_list|)
value|((a)<< 5)
end_define

begin_define
define|#
directive|define
name|AXP209_SENSOR_BAT_L
parameter_list|(
name|a
parameter_list|)
value|((a)& 0x1f)
end_define

begin_define
define|#
directive|define
name|AXP209_0C_TO_K
value|2732
end_define

begin_comment
comment|/* ADC Sensors */
end_comment

begin_define
define|#
directive|define
name|AXP209_ADC_ENABLE1
value|0x82
end_define

begin_define
define|#
directive|define
name|AXP209_ADC_ENABLE2
value|0x83
end_define

begin_define
define|#
directive|define
name|AXP209_ADC1_BATVOLT
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|AXP209_ADC1_BATCURRENT
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|AXP209_ADC1_ACVOLT
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|AXP209_ADC1_ACCURRENT
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AXP209_ADC1_VBUSVOLT
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|AXP209_ADC1_VBUSCURRENT
value|(1<< 2)
end_define

begin_comment
comment|/* Interrupt related registers */
end_comment

begin_define
define|#
directive|define
name|AXP209_IRQ1_ENABLE
value|0x40
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ1_STATUS
value|0x48
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ1_AC_OVERVOLT
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ1_AC_CONN
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ1_AC_DISCONN
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ1_VBUS_OVERVOLT
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ1_VBUS_CONN
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ1_VBUS_DISCONN
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ1_VBUS_LOW
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ2_ENABLE
value|0x41
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ2_STATUS
value|0x49
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ2_BATT_CONN
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ2_BATT_DISCONN
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ2_BATT_CHARGE_ACCT_ON
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ2_BATT_CHARGE_ACCT_OFF
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ2_BATT_CHARGING
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ2_BATT_CHARGED
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ2_BATT_TEMP_OVER
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ2_BATT_TEMP_LOW
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ3_ENABLE
value|0x42
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ3_STATUS
value|0x4A
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ3_TEMP_OVER
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ3_CHARGE_CURRENT_LOW
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ3_DCDC2_LOW
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ3_DCDC3_LOW
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ3_LDO3_LOW
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ3_PEK_SHORT
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ3_PEK_LONG
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ4_ENABLE
value|0x43
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ4_STATUS
value|0x4B
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ4_NOE_START
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ4_NOE_SHUT
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ4_VBUS_VALID
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ4_VBUS_INVALID
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ4_VBUS_SESSION
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ4_VBUS_SESSION_END
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ4_APS_LOW_1
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ4_APS_LOW_2
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ5_ENABLE
value|0x44
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ5_STATUS
value|0x4C
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ5_TIMER_EXPIRE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ5_PEK_RISE_EDGE
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ5_PEK_FALL_EDGE
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ5_GPIO3
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ5_GPIO2
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ5_GPIO1
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ5_GPIO0
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AXP209_IRQ_ACK
value|0xff
end_define

begin_comment
comment|/* GPIOs registers */
end_comment

begin_define
define|#
directive|define
name|AXP209_GPIO_FUNC_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|AXP209_GPIO_FUNC_DRVLO
value|0x0
end_define

begin_define
define|#
directive|define
name|AXP209_GPIO_FUNC_DRVHI
value|0x1
end_define

begin_define
define|#
directive|define
name|AXP209_GPIO_FUNC_INPUT
value|0x2
end_define

begin_define
define|#
directive|define
name|AXP209_GPIO0_CTRL
value|0x90
end_define

begin_define
define|#
directive|define
name|AXP209_GPIO1_CTRL
value|0x92
end_define

begin_define
define|#
directive|define
name|AXP209_GPIO2_CTRL
value|0x93
end_define

begin_define
define|#
directive|define
name|AXP209_GPIO_STATUS
value|0x94
end_define

begin_define
define|#
directive|define
name|AXP209_GPIO_DATA
parameter_list|(
name|x
parameter_list|)
value|(1<< (x + 4))
end_define

begin_enum
enum|enum
name|axp209_sensor
block|{
name|AXP209_TEMP
block|,
name|AXP209_ACVOLT
block|,
name|AXP209_ACCURRENT
block|,
name|AXP209_VBUSVOLT
block|,
name|AXP209_VBUSCURRENT
block|,
name|AXP209_BATVOLT
block|,
name|AXP209_BATCHARGECURRENT
block|,
name|AXP209_BATDISCHARGECURRENT
block|, }
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AXP209REG_H_ */
end_comment

end_unit

