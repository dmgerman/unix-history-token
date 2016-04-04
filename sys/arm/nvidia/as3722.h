begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Michal Meloun<mmel@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AS3722_H_
end_ifndef

begin_include
include|#
directive|include
file|<sys/clock.h>
end_include

begin_define
define|#
directive|define
name|AS3722_SD0_VOLTAGE
value|0x00
end_define

begin_define
define|#
directive|define
name|AS3722_SD_VSEL_MASK
value|0x7F
end_define

begin_comment
comment|/* For all SD */
end_comment

begin_define
define|#
directive|define
name|AS3722_SD0_VSEL_MIN
value|0x01
end_define

begin_define
define|#
directive|define
name|AS3722_SD0_VSEL_MAX
value|0x5A
end_define

begin_define
define|#
directive|define
name|AS3722_SD0_VSEL_LOW_VOL_MAX
value|0x6E
end_define

begin_define
define|#
directive|define
name|AS3722_SD1_VOLTAGE
value|0x01
end_define

begin_define
define|#
directive|define
name|AS3722_SD2_VOLTAGE
value|0x02
end_define

begin_define
define|#
directive|define
name|AS3722_SD2_VSEL_MIN
value|0x01
end_define

begin_define
define|#
directive|define
name|AS3722_SD2_VSEL_MAX
value|0x7F
end_define

begin_define
define|#
directive|define
name|AS3722_SD3_VOLTAGE
value|0x03
end_define

begin_define
define|#
directive|define
name|AS3722_SD4_VOLTAGE
value|0x04
end_define

begin_define
define|#
directive|define
name|AS3722_SD5_VOLTAGE
value|0x05
end_define

begin_define
define|#
directive|define
name|AS3722_SD6_VOLTAGE
value|0x06
end_define

begin_define
define|#
directive|define
name|AS3722_GPIO0_CONTROL
value|0x08
end_define

begin_define
define|#
directive|define
name|AS3722_GPIO_INVERT
value|0x80
end_define

begin_define
define|#
directive|define
name|AS3722_GPIO_IOSF_MASK
value|0x0F
end_define

begin_define
define|#
directive|define
name|AS3722_GPIO_IOSF_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|AS3722_GPIO_MODE_MASK
value|0x07
end_define

begin_define
define|#
directive|define
name|AS3722_GPIO_MODE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|AS3722_GPIO1_CONTROL
value|0x09
end_define

begin_define
define|#
directive|define
name|AS3722_GPIO2_CONTROL
value|0x0A
end_define

begin_define
define|#
directive|define
name|AS3722_GPIO3_CONTROL
value|0x0B
end_define

begin_define
define|#
directive|define
name|AS3722_GPIO4_CONTROL
value|0x0C
end_define

begin_define
define|#
directive|define
name|AS3722_GPIO5_CONTROL
value|0x0D
end_define

begin_define
define|#
directive|define
name|AS3722_GPIO6_CONTROL
value|0x0E
end_define

begin_define
define|#
directive|define
name|AS3722_GPIO7_CONTROL
value|0x0F
end_define

begin_define
define|#
directive|define
name|AS3722_LDO0_VOLTAGE
value|0x10
end_define

begin_define
define|#
directive|define
name|AS3722_LDO0_VSEL_MASK
value|0x1F
end_define

begin_define
define|#
directive|define
name|AS3722_LDO0_VSEL_MIN
value|0x01
end_define

begin_define
define|#
directive|define
name|AS3722_LDO0_VSEL_MAX
value|0x12
end_define

begin_define
define|#
directive|define
name|AS3722_LDO0_NUM_VOLT
value|0x12
end_define

begin_define
define|#
directive|define
name|AS3722_LDO1_VOLTAGE
value|0x11
end_define

begin_define
define|#
directive|define
name|AS3722_LDO_VSEL_MASK
value|0x7F
end_define

begin_define
define|#
directive|define
name|AS3722_LDO_VSEL_MIN
value|0x01
end_define

begin_define
define|#
directive|define
name|AS3722_LDO_VSEL_MAX
value|0x7F
end_define

begin_define
define|#
directive|define
name|AS3722_LDO_VSEL_DNU_MIN
value|0x25
end_define

begin_define
define|#
directive|define
name|AS3722_LDO_VSEL_DNU_MAX
value|0x3F
end_define

begin_define
define|#
directive|define
name|AS3722_LDO_NUM_VOLT
value|0x80
end_define

begin_define
define|#
directive|define
name|AS3722_LDO2_VOLTAGE
value|0x12
end_define

begin_define
define|#
directive|define
name|AS3722_LDO3_VOLTAGE
value|0x13
end_define

begin_define
define|#
directive|define
name|AS3722_LDO3_VSEL_MASK
value|0x3F
end_define

begin_define
define|#
directive|define
name|AS3722_LDO3_VSEL_MIN
value|0x01
end_define

begin_define
define|#
directive|define
name|AS3722_LDO3_VSEL_MAX
value|0x2D
end_define

begin_define
define|#
directive|define
name|AS3722_LDO3_NUM_VOLT
value|0x2D
end_define

begin_define
define|#
directive|define
name|AS3722_LDO3_MODE_MASK
value|(0x3<< 6)
end_define

begin_define
define|#
directive|define
name|AS3722_LDO3_MODE_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 6)& 0x3)
end_define

begin_define
define|#
directive|define
name|AS3722_LDO3_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 6)
end_define

begin_define
define|#
directive|define
name|AS3722_LDO3_MODE_PMOS
value|AS3722_LDO3_MODE(0)
end_define

begin_define
define|#
directive|define
name|AS3722_LDO3_MODE_PMOS_TRACKING
value|AS3722_LDO3_MODE(1)
end_define

begin_define
define|#
directive|define
name|AS3722_LDO3_MODE_NMOS
value|AS3722_LDO3_MODE(2)
end_define

begin_define
define|#
directive|define
name|AS3722_LDO3_MODE_SWITCH
value|AS3722_LDO3_MODE(3)
end_define

begin_define
define|#
directive|define
name|AS3722_LDO4_VOLTAGE
value|0x14
end_define

begin_define
define|#
directive|define
name|AS3722_LDO5_VOLTAGE
value|0x15
end_define

begin_define
define|#
directive|define
name|AS3722_LDO6_VOLTAGE
value|0x16
end_define

begin_define
define|#
directive|define
name|AS3722_LDO6_SEL_BYPASS
value|0x3F
end_define

begin_define
define|#
directive|define
name|AS3722_LDO7_VOLTAGE
value|0x17
end_define

begin_define
define|#
directive|define
name|AS3722_LDO9_VOLTAGE
value|0x19
end_define

begin_define
define|#
directive|define
name|AS3722_LDO10_VOLTAGE
value|0x1A
end_define

begin_define
define|#
directive|define
name|AS3722_LDO11_VOLTAGE
value|0x1B
end_define

begin_define
define|#
directive|define
name|AS3722_LDO3_SETTINGS
value|0x1D
end_define

begin_define
define|#
directive|define
name|AS3722_GPIO_DEB1
value|0x1E
end_define

begin_define
define|#
directive|define
name|AS3722_GPIO_DEB2
value|0x1F
end_define

begin_define
define|#
directive|define
name|AS3722_GPIO_SIGNAL_OUT
value|0x20
end_define

begin_define
define|#
directive|define
name|AS3722_GPIO_SIGNAL_IN
value|0x21
end_define

begin_define
define|#
directive|define
name|AS3722_REG_SEQU_MOD1
value|0x22
end_define

begin_define
define|#
directive|define
name|AS3722_REG_SEQU_MOD2
value|0x23
end_define

begin_define
define|#
directive|define
name|AS3722_REG_SEQU_MOD3
value|0x24
end_define

begin_define
define|#
directive|define
name|AS3722_SD_PHSW_CTRL
value|0x27
end_define

begin_define
define|#
directive|define
name|AS3722_SD_PHSW_STATUS
value|0x28
end_define

begin_define
define|#
directive|define
name|AS3722_SD0_CONTROL
value|0x29
end_define

begin_define
define|#
directive|define
name|AS3722_SD0_MODE_FAST
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AS3722_SD1_CONTROL
value|0x2A
end_define

begin_define
define|#
directive|define
name|AS3722_SD1_MODE_FAST
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AS3722_SDMPH_CONTROL
value|0x2B
end_define

begin_define
define|#
directive|define
name|AS3722_SD23_CONTROL
value|0x2C
end_define

begin_define
define|#
directive|define
name|AS3722_SD3_MODE_FAST
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|AS3722_SD2_MODE_FAST
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AS3722_SD4_CONTROL
value|0x2D
end_define

begin_define
define|#
directive|define
name|AS3722_SD4_MODE_FAST
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AS3722_SD5_CONTROL
value|0x2E
end_define

begin_define
define|#
directive|define
name|AS3722_SD5_MODE_FAST
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AS3722_SD6_CONTROL
value|0x2F
end_define

begin_define
define|#
directive|define
name|AS3722_SD6_MODE_FAST
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AS3722_SD_DVM
value|0x30
end_define

begin_define
define|#
directive|define
name|AS3722_RESET_REASON
value|0x31
end_define

begin_define
define|#
directive|define
name|AS3722_BATTERY_VOLTAGE_MONITOR
value|0x32
end_define

begin_define
define|#
directive|define
name|AS3722_STARTUP_CONTROL
value|0x33
end_define

begin_define
define|#
directive|define
name|AS3722_RESET_TIMER
value|0x34
end_define

begin_define
define|#
directive|define
name|AS3722_REFERENCE_CONTROL
value|0x35
end_define

begin_define
define|#
directive|define
name|AS3722_RESET_CONTROL
value|0x36
end_define

begin_define
define|#
directive|define
name|AS3722_OVERTEMPERATURE_CONTROL
value|0x37
end_define

begin_define
define|#
directive|define
name|AS3722_WATCHDOG_CONTROL
value|0x38
end_define

begin_define
define|#
directive|define
name|AS3722_REG_STANDBY_MOD1
value|0x39
end_define

begin_define
define|#
directive|define
name|AS3722_REG_STANDBY_MOD2
value|0x3A
end_define

begin_define
define|#
directive|define
name|AS3722_REG_STANDBY_MOD3
value|0x3B
end_define

begin_define
define|#
directive|define
name|AS3722_ENABLE_CTRL1
value|0x3C
end_define

begin_define
define|#
directive|define
name|AS3722_SD3_EXT_ENABLE_MASK
value|0xC0
end_define

begin_define
define|#
directive|define
name|AS3722_SD2_EXT_ENABLE_MASK
value|0x30
end_define

begin_define
define|#
directive|define
name|AS3722_SD1_EXT_ENABLE_MASK
value|0x0C
end_define

begin_define
define|#
directive|define
name|AS3722_SD0_EXT_ENABLE_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|AS3722_ENABLE_CTRL2
value|0x3D
end_define

begin_define
define|#
directive|define
name|AS3722_SD6_EXT_ENABLE_MASK
value|0x30
end_define

begin_define
define|#
directive|define
name|AS3722_SD5_EXT_ENABLE_MASK
value|0x0C
end_define

begin_define
define|#
directive|define
name|AS3722_SD4_EXT_ENABLE_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|AS3722_ENABLE_CTRL3
value|0x3E
end_define

begin_define
define|#
directive|define
name|AS3722_LDO3_EXT_ENABLE_MASK
value|0xC0
end_define

begin_define
define|#
directive|define
name|AS3722_LDO2_EXT_ENABLE_MASK
value|0x30
end_define

begin_define
define|#
directive|define
name|AS3722_LDO1_EXT_ENABLE_MASK
value|0x0C
end_define

begin_define
define|#
directive|define
name|AS3722_LDO0_EXT_ENABLE_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|AS3722_ENABLE_CTRL4
value|0x3F
end_define

begin_define
define|#
directive|define
name|AS3722_LDO7_EXT_ENABLE_MASK
value|0xC0
end_define

begin_define
define|#
directive|define
name|AS3722_LDO6_EXT_ENABLE_MASK
value|0x30
end_define

begin_define
define|#
directive|define
name|AS3722_LDO5_EXT_ENABLE_MASK
value|0x0C
end_define

begin_define
define|#
directive|define
name|AS3722_LDO4_EXT_ENABLE_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|AS3722_ENABLE_CTRL5
value|0x40
end_define

begin_define
define|#
directive|define
name|AS3722_LDO11_EXT_ENABLE_MASK
value|0xC0
end_define

begin_define
define|#
directive|define
name|AS3722_LDO10_EXT_ENABLE_MASK
value|0x30
end_define

begin_define
define|#
directive|define
name|AS3722_LDO9_EXT_ENABLE_MASK
value|0x0C
end_define

begin_define
define|#
directive|define
name|AS3722_PWM_CONTROL_L
value|0x41
end_define

begin_define
define|#
directive|define
name|AS3722_PWM_CONTROL_H
value|0x42
end_define

begin_define
define|#
directive|define
name|AS3722_WATCHDOG_TIMER
value|0x46
end_define

begin_define
define|#
directive|define
name|AS3722_WATCHDOG_SOFTWARE_SIGNAL
value|0x48
end_define

begin_define
define|#
directive|define
name|AS3722_IO_VOLTAGE
value|0x49
end_define

begin_define
define|#
directive|define
name|AS3722_I2C_PULL_UP
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AS3722_INT_PULL_UP
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|AS3722_BATTERY_VOLTAGE_MONITOR2
value|0x4A
end_define

begin_define
define|#
directive|define
name|AS3722_SD_CONTROL
value|0x4D
end_define

begin_define
define|#
directive|define
name|AS3722_SDN_CTRL
parameter_list|(
name|x
parameter_list|)
value|(1<< (x))
end_define

begin_define
define|#
directive|define
name|AS3722_LDO_CONTROL0
value|0x4E
end_define

begin_define
define|#
directive|define
name|AS3722_LDO7_CTRL
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|AS3722_LDO6_CTRL
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|AS3722_LDO5_CTRL
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|AS3722_LDO4_CTRL
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|AS3722_LDO3_CTRL
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|AS3722_LDO2_CTRL
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AS3722_LDO1_CTRL
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AS3722_LDO0_CTRL
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AS3722_LDO_CONTROL1
value|0x4F
end_define

begin_define
define|#
directive|define
name|AS3722_LDO11_CTRL
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|AS3722_LDO10_CTRL
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AS3722_LDO9_CTRL
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AS3722_SD0_PROTECT
value|0x50
end_define

begin_define
define|#
directive|define
name|AS3722_SD6_PROTECT
value|0x51
end_define

begin_define
define|#
directive|define
name|AS3722_PWM_VCONTROL1
value|0x52
end_define

begin_define
define|#
directive|define
name|AS3722_PWM_VCONTROL2
value|0x53
end_define

begin_define
define|#
directive|define
name|AS3722_PWM_VCONTROL3
value|0x54
end_define

begin_define
define|#
directive|define
name|AS3722_PWM_VCONTROL4
value|0x55
end_define

begin_define
define|#
directive|define
name|AS3722_BB_CHARGER
value|0x57
end_define

begin_define
define|#
directive|define
name|AS3722_CTRL_SEQU1
value|0x58
end_define

begin_define
define|#
directive|define
name|AS3722_CTRL_SEQU2
value|0x59
end_define

begin_define
define|#
directive|define
name|AS3722_OV_CURRENT
value|0x5A
end_define

begin_define
define|#
directive|define
name|AS3722_OV_CURRENT_DEB
value|0x5B
end_define

begin_define
define|#
directive|define
name|AS3722_SDLV_DEB
value|0x5C
end_define

begin_define
define|#
directive|define
name|AS3722_OC_PG_CTRL
value|0x5D
end_define

begin_define
define|#
directive|define
name|AS3722_OC_PG_CTRL2
value|0x5E
end_define

begin_define
define|#
directive|define
name|AS3722_CTRL_STATUS
value|0x5F
end_define

begin_define
define|#
directive|define
name|AS3722_RTC_CONTROL
value|0x60
end_define

begin_define
define|#
directive|define
name|AS3722_RTC_AM_PM_MODE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|AS3722_RTC_CLK32K_OUT_EN
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|AS3722_RTC_IRQ_MODE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|AS3722_RTC_ON
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|AS3722_RTC_ALARM_WAKEUP_EN
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AS3722_RTC_REP_WAKEUP_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|AS3722_RTC_SECOND
value|0x61
end_define

begin_define
define|#
directive|define
name|AS3722_RTC_MINUTE
value|0x62
end_define

begin_define
define|#
directive|define
name|AS3722_RTC_HOUR
value|0x63
end_define

begin_define
define|#
directive|define
name|AS3722_RTC_DAY
value|0x64
end_define

begin_define
define|#
directive|define
name|AS3722_RTC_MONTH
value|0x65
end_define

begin_define
define|#
directive|define
name|AS3722_RTC_YEAR
value|0x66
end_define

begin_define
define|#
directive|define
name|AS3722_RTC_ALARM_SECOND
value|0x67
end_define

begin_define
define|#
directive|define
name|AS3722_RTC_ALARM_MINUTE
value|0x68
end_define

begin_define
define|#
directive|define
name|AS3722_RTC_ALARM_HOUR
value|0x69
end_define

begin_define
define|#
directive|define
name|AS3722_RTC_ALARM_DAY
value|0x6A
end_define

begin_define
define|#
directive|define
name|AS3722_RTC_ALARM_MONTH
value|0x6B
end_define

begin_define
define|#
directive|define
name|AS3722_RTC_ALARM_YEAR
value|0x6C
end_define

begin_define
define|#
directive|define
name|AS3722_SRAM
value|0x6D
end_define

begin_define
define|#
directive|define
name|AS3722_RTC_ACCESS
value|0x6F
end_define

begin_define
define|#
directive|define
name|AS3722_REG_STATUS
value|0x73
end_define

begin_define
define|#
directive|define
name|AS3722_INTERRUPT_MASK1
value|0x74
end_define

begin_define
define|#
directive|define
name|AS3722_INTERRUPT_MASK2
value|0x75
end_define

begin_define
define|#
directive|define
name|AS3722_INTERRUPT_MASK3
value|0x76
end_define

begin_define
define|#
directive|define
name|AS3722_INTERRUPT_MASK4
value|0x77
end_define

begin_define
define|#
directive|define
name|AS3722_INTERRUPT_STATUS1
value|0x78
end_define

begin_define
define|#
directive|define
name|AS3722_INTERRUPT_STATUS2
value|0x79
end_define

begin_define
define|#
directive|define
name|AS3722_INTERRUPT_STATUS3
value|0x7A
end_define

begin_define
define|#
directive|define
name|AS3722_INTERRUPT_STATUS4
value|0x7B
end_define

begin_define
define|#
directive|define
name|AS3722_TEMP_STATUS
value|0x7D
end_define

begin_define
define|#
directive|define
name|AS3722_ADC0_CONTROL
value|0x80
end_define

begin_define
define|#
directive|define
name|AS3722_ADC1_CONTROL
value|0x81
end_define

begin_define
define|#
directive|define
name|AS3722_ADC0_MSB_RESULT
value|0x82
end_define

begin_define
define|#
directive|define
name|AS3722_ADC0_LSB_RESULT
value|0x83
end_define

begin_define
define|#
directive|define
name|AS3722_ADC1_MSB_RESULT
value|0x84
end_define

begin_define
define|#
directive|define
name|AS3722_ADC1_LSB_RESULT
value|0x85
end_define

begin_define
define|#
directive|define
name|AS3722_ADC1_THRESHOLD_HI_MSB
value|0x86
end_define

begin_define
define|#
directive|define
name|AS3722_ADC1_THRESHOLD_HI_LSB
value|0x87
end_define

begin_define
define|#
directive|define
name|AS3722_ADC1_THRESHOLD_LO_MSB
value|0x88
end_define

begin_define
define|#
directive|define
name|AS3722_ADC1_THRESHOLD_LO_LSB
value|0x89
end_define

begin_define
define|#
directive|define
name|AS3722_ADC_CONFIGURATION
value|0x8A
end_define

begin_define
define|#
directive|define
name|AS3722_ASIC_ID1
value|0x90
end_define

begin_define
define|#
directive|define
name|AS3722_ASIC_ID2
value|0x91
end_define

begin_define
define|#
directive|define
name|AS3722_LOCK
value|0x9E
end_define

begin_define
define|#
directive|define
name|AS3722_FUSE7
value|0x9E
end_define

begin_define
define|#
directive|define
name|AS3722_FUSE7_SD0_LOW_VOLTAGE
value|(1<< 4)
end_define

begin_struct_decl
struct_decl|struct
name|as3722_reg_sc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|as3722_gpio_pin
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|as3722_softc
block|{
name|device_t
name|dev
decl_stmt|;
name|struct
name|sx
name|lock
decl_stmt|;
name|int
name|bus_addr
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq_res
decl_stmt|;
name|void
modifier|*
name|irq_h
decl_stmt|;
name|uint8_t
name|chip_rev
decl_stmt|;
name|int
name|int_pullup
decl_stmt|;
name|int
name|i2c_pullup
decl_stmt|;
comment|/* Regulators. */
name|struct
name|as3722_reg_sc
modifier|*
modifier|*
name|regs
decl_stmt|;
name|int
name|nregs
decl_stmt|;
comment|/* GPIO */
name|device_t
name|gpio_busdev
decl_stmt|;
name|struct
name|as3722_gpio_pin
modifier|*
modifier|*
name|gpio_pins
decl_stmt|;
name|int
name|gpio_npins
decl_stmt|;
name|struct
name|sx
name|gpio_lock
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RD1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
value|as3722_read(sc, reg, val)
end_define

begin_define
define|#
directive|define
name|WR1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
value|as3722_write(sc, reg, val)
end_define

begin_define
define|#
directive|define
name|RM1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|clr
parameter_list|,
name|set
parameter_list|)
value|as3722_modify(sc, reg, clr, set)
end_define

begin_function_decl
name|int
name|as3722_read
parameter_list|(
name|struct
name|as3722_softc
modifier|*
name|sc
parameter_list|,
name|uint8_t
name|reg
parameter_list|,
name|uint8_t
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|as3722_write
parameter_list|(
name|struct
name|as3722_softc
modifier|*
name|sc
parameter_list|,
name|uint8_t
name|reg
parameter_list|,
name|uint8_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|as3722_modify
parameter_list|(
name|struct
name|as3722_softc
modifier|*
name|sc
parameter_list|,
name|uint8_t
name|reg
parameter_list|,
name|uint8_t
name|clear
parameter_list|,
name|uint8_t
name|set
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|as3722_read_buf
parameter_list|(
name|struct
name|as3722_softc
modifier|*
name|sc
parameter_list|,
name|uint8_t
name|reg
parameter_list|,
name|uint8_t
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|as3722_write_buf
parameter_list|(
name|struct
name|as3722_softc
modifier|*
name|sc
parameter_list|,
name|uint8_t
name|reg
parameter_list|,
name|uint8_t
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Regulators */
end_comment

begin_function_decl
name|int
name|as3722_regulator_attach
parameter_list|(
name|struct
name|as3722_softc
modifier|*
name|sc
parameter_list|,
name|phandle_t
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|as3722_regulator_map
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|phandle_t
name|xref
parameter_list|,
name|int
name|ncells
parameter_list|,
name|pcell_t
modifier|*
name|cells
parameter_list|,
name|int
modifier|*
name|num
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* RTC */
end_comment

begin_function_decl
name|int
name|as3722_rtc_attach
parameter_list|(
name|struct
name|as3722_softc
modifier|*
name|sc
parameter_list|,
name|phandle_t
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|as3722_rtc_gettime
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|struct
name|timespec
modifier|*
name|ts
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|as3722_rtc_settime
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|struct
name|timespec
modifier|*
name|ts
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* GPIO */
end_comment

begin_function_decl
name|device_t
name|as3722_gpio_get_bus
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|as3722_gpio_pin_max
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
modifier|*
name|maxpin
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|as3722_gpio_pin_getname
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|uint32_t
name|pin
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|as3722_gpio_pin_getflags
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|uint32_t
name|pin
parameter_list|,
name|uint32_t
modifier|*
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|as3722_gpio_pin_getcaps
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|uint32_t
name|pin
parameter_list|,
name|uint32_t
modifier|*
name|caps
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|as3722_gpio_pin_setflags
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|uint32_t
name|pin
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|as3722_gpio_pin_set
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|uint32_t
name|pin
parameter_list|,
name|unsigned
name|int
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|as3722_gpio_pin_get
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|uint32_t
name|pin
parameter_list|,
name|unsigned
name|int
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|as3722_gpio_pin_toggle
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|uint32_t
name|pin
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|as3722_gpio_map_gpios
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|phandle_t
name|pdev
parameter_list|,
name|phandle_t
name|gparent
parameter_list|,
name|int
name|gcells
parameter_list|,
name|pcell_t
modifier|*
name|gpios
parameter_list|,
name|uint32_t
modifier|*
name|pin
parameter_list|,
name|uint32_t
modifier|*
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|as3722_gpio_attach
parameter_list|(
name|struct
name|as3722_softc
modifier|*
name|sc
parameter_list|,
name|phandle_t
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|as3722_pinmux_configure
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|phandle_t
name|cfgxref
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AS3722_H_ */
end_comment

end_unit

