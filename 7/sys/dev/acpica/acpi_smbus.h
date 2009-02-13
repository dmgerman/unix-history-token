begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Hans Petter Selasky  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ACPI_SMBUS_H_
end_ifndef

begin_define
define|#
directive|define
name|_ACPI_SMBUS_H_
end_define

begin_comment
comment|/*  * System Management Bus register offsets  */
end_comment

begin_define
define|#
directive|define
name|SMBUS_PRTCL
value|0
end_define

begin_define
define|#
directive|define
name|SMBUS_STS
value|1
end_define

begin_define
define|#
directive|define
name|SMBUS_STS_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|SMBUS_ADDR
value|2
end_define

begin_define
define|#
directive|define
name|SMBUS_CMD
value|3
end_define

begin_define
define|#
directive|define
name|SMBUS_DATA
value|4
end_define

begin_comment
comment|/* 32 bytes */
end_comment

begin_define
define|#
directive|define
name|SMBUS_BCNT
value|36
end_define

begin_define
define|#
directive|define
name|SMBUS_ALRM_ADDR
value|37
end_define

begin_define
define|#
directive|define
name|SMBUS_ALRM_DATA
value|38
end_define

begin_comment
comment|/* 2 bytes */
end_comment

begin_comment
comment|/*  * Smart-Battery commands and definitions  */
end_comment

begin_comment
comment|/* Base address */
end_comment

begin_define
define|#
directive|define
name|SMBATT_ADDRESS
value|0x16
end_define

begin_comment
comment|/* access: READ WRITE WORD */
end_comment

begin_define
define|#
directive|define
name|SMBATT_CMD_MANUFACTURER_ACCESS
value|0
end_define

begin_comment
comment|/*  * access: READ WRITE WORD  * unit  : mAh (CAPACITY_MODE=0) or 10 mWh (CAPACITY_MODE=1)  * range : 0 .. 65535 inclusively  */
end_comment

begin_define
define|#
directive|define
name|SMBATT_CMD_REMAINING_CAPACITY_ALARM
value|0x1
end_define

begin_comment
comment|/*  * access: READ WRITE WORD  * unit  : minutes  * range : 0 .. 65535 inclusively  */
end_comment

begin_define
define|#
directive|define
name|SMBATT_CMD_REMAINING_TIME_ALARM
value|0x2
end_define

begin_comment
comment|/* access: READ WRITE WORD */
end_comment

begin_define
define|#
directive|define
name|SMBATT_CMD_BATTERY_MODE
value|0x3
end_define

begin_define
define|#
directive|define
name|SMBATT_BM_INTERNAL_CHARGE_CONTROLLER
value|(1<<  0)
end_define

begin_comment
comment|/* READ */
end_comment

begin_define
define|#
directive|define
name|SMBATT_BM_PRIMARY_BATTERY_SUPPORT
value|(1<<  1)
end_define

begin_comment
comment|/* READ */
end_comment

begin_define
define|#
directive|define
name|SMBATT_BM_CONDITION_FLAG
value|(1<<  7)
end_define

begin_comment
comment|/* READ */
end_comment

begin_define
define|#
directive|define
name|SMBATT_BM_CHARGE_CONTROLLER_ENABLED
value|(1<<  8)
end_define

begin_comment
comment|/* READ WRITE */
end_comment

begin_define
define|#
directive|define
name|SMBATT_BM_PRIMARY_BATTERY
value|(1<<  9)
end_define

begin_comment
comment|/* READ WRITE */
end_comment

begin_define
define|#
directive|define
name|SMBATT_BM_ALARM_MODE
value|(1<< 13)
end_define

begin_comment
comment|/* READ WRITE */
end_comment

begin_define
define|#
directive|define
name|SMBATT_BM_CHARGER_MODE
value|(1<< 14)
end_define

begin_comment
comment|/* READ WRITE */
end_comment

begin_define
define|#
directive|define
name|SMBATT_BM_CAPACITY_MODE
value|(1<< 15)
end_define

begin_comment
comment|/* READ WRITE */
end_comment

begin_comment
comment|/*  * access: READ WRITE WORD  * unit  : mAh (CAPACITY_MODE=0) or 10 mWh (CAPACITY_MODE=1)  * range : signed WORD  */
end_comment

begin_define
define|#
directive|define
name|SMBATT_CMD_AT_RATE
value|0x4
end_define

begin_comment
comment|/*  * access: READ WORD  * unit  : minutes  * range : 0 .. 65534, 65535 has special meaning  */
end_comment

begin_define
define|#
directive|define
name|SMBATT_CMD_AT_RATE_TIME_TO_FULL
value|0x5
end_define

begin_comment
comment|/*  * access: READ WORD  * unit  : minutes  * range : 0 .. 65534, 65535 has special meaning  */
end_comment

begin_define
define|#
directive|define
name|SMBATT_CMD_AT_RATE_TIME_TO_EMPTY
value|0x6
end_define

begin_comment
comment|/*  * access: READ WORD */
end_comment

begin_define
define|#
directive|define
name|SMBATT_CMD_AT_RATE_OK
value|0x7
end_define

begin_comment
comment|/*  * access: READ WORD  * unit  : 0.1 degrees Kelvin  * range : 0 .. 6553.5 Kelvin  */
end_comment

begin_define
define|#
directive|define
name|SMBATT_CMD_TEMPERATURE
value|0x8
end_define

begin_comment
comment|/*  * access: READ WORD  * unit  : mV  * range : 0 .. 65535 inclusively  */
end_comment

begin_define
define|#
directive|define
name|SMBATT_CMD_VOLTAGE
value|0x9
end_define

begin_comment
comment|/*  * access: READ WORD  * unit  : mA  * range : signed WORD  */
end_comment

begin_define
define|#
directive|define
name|SMBATT_CMD_CURRENT
value|0xa
end_define

begin_comment
comment|/*  * access: READ WORD  * unit  : mA  * range : signed WORD  */
end_comment

begin_define
define|#
directive|define
name|SMBATT_CMD_AVERAGE_CURRENT
value|0xb
end_define

begin_comment
comment|/*  * access: READ WORD  * unit  : percent  * range : 0..100 inclusively  */
end_comment

begin_define
define|#
directive|define
name|SMBATT_CMD_MAX_ERROR
value|0xc
end_define

begin_comment
comment|/*  * access: READ WORD  * unit  : percent  * range : 0..100 inclusively  */
end_comment

begin_define
define|#
directive|define
name|SMBATT_CMD_RELATIVE_STATE_OF_CHARGE
value|0xd
end_define

begin_comment
comment|/*  * access: READ WORD  * unit  : percent  * range : 0..100 inclusively  */
end_comment

begin_define
define|#
directive|define
name|SMBATT_CMD_ABSOLUTE_STATE_OF_CHARGE
value|0xe
end_define

begin_comment
comment|/*  * access: READ WORD  * unit  : mAh (CAPACITY_MODE=0) or 10 mWh (CAPACITY_MODE=1)  * range : 0..65535 inclusively  */
end_comment

begin_define
define|#
directive|define
name|SMBATT_CMD_REMAINING_CAPACITY
value|0xf
end_define

begin_comment
comment|/*  * access: READ WORD  * unit  : mAh (CAPACITY_MODE=0) or 10 mWh (CAPACITY_MODE=1)  * range : 0..65535 inclusively  */
end_comment

begin_define
define|#
directive|define
name|SMBATT_CMD_FULL_CHARGE_CAPACITY
value|0x10
end_define

begin_comment
comment|/*  * access: READ WORD  * unit  : minutes  * range : 0..65534, 65535 is reserved  */
end_comment

begin_define
define|#
directive|define
name|SMBATT_CMD_RUN_TIME_TO_EMPTY
value|0x11
end_define

begin_comment
comment|/*  * access: READ WORD  * unit  : minutes  * range : 0..65534, 65535 is reserved  */
end_comment

begin_define
define|#
directive|define
name|SMBATT_CMD_AVERAGE_TIME_TO_EMPTY
value|0x12
end_define

begin_comment
comment|/*  * access: READ WORD  * unit  : minutes  * range : 0..65534, 65535 is reserved  */
end_comment

begin_define
define|#
directive|define
name|SMBATT_CMD_AVERAGE_TIME_TO_FULL
value|0x13
end_define

begin_comment
comment|/*  * access: READ WORD  * unit  : mA  */
end_comment

begin_define
define|#
directive|define
name|SMBATT_CMD_CHARGING_CURRENT
value|0x14
end_define

begin_comment
comment|/*  * access: READ WORD  * unit  : mV  * range : 0 .. 65534, 65535 reserved  */
end_comment

begin_define
define|#
directive|define
name|SMBATT_CMD_CHARGING_VOLTAGE
value|0x15
end_define

begin_comment
comment|/* access: READ WORD */
end_comment

begin_define
define|#
directive|define
name|SMBATT_CMD_BATTERY_STATUS
value|0x16
end_define

begin_comment
comment|/* alarm bits */
end_comment

begin_define
define|#
directive|define
name|SMBATT_BS_OVER_CHARGED_ALARM
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|SMBATT_BS_TERMINATE_CHARGE_ALARM
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|SMBATT_BS_RESERVED_2
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|SMBATT_BS_OVER_TEMP_ALARM
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|SMBATT_BS_TERMINATE_DISCHARGE_ALARM
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|SMBATT_BS_RESERVED_1
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|SMBATT_BS_REMAINING_CAPACITY_ALARM
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|SMBATT_BS_REMAINING_TIME_ALARM
value|(1<< 8)
end_define

begin_comment
comment|/* status bits */
end_comment

begin_define
define|#
directive|define
name|SMBATT_BS_INITIALIZED
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|SMBATT_BS_DISCHARGING
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|SMBATT_BS_FULLY_CHARGED
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|SMBATT_BS_FULLY_DISCHARGED
value|(1<< 4)
end_define

begin_comment
comment|/* error bits */
end_comment

begin_define
define|#
directive|define
name|SMBATT_BS_GET_ERROR
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xf)
end_define

begin_define
define|#
directive|define
name|SMBATT_BS_ERROR_OK
value|0
end_define

begin_define
define|#
directive|define
name|SMBATT_BS_ERROR_BUSY
value|1
end_define

begin_define
define|#
directive|define
name|SMBATT_BS_ERROR_RESERVED_COMMAND
value|2
end_define

begin_define
define|#
directive|define
name|SMBATT_BS_ERROR_UNSUPPORTED_COMMAND
value|3
end_define

begin_define
define|#
directive|define
name|SMBATT_BS_ERROR_ACCESS_DENIED
value|4
end_define

begin_define
define|#
directive|define
name|SMBATT_BS_ERROR_OVER_UNDER_FLOW
value|5
end_define

begin_define
define|#
directive|define
name|SMBATT_BS_ERROR_BADSIZE
value|6
end_define

begin_define
define|#
directive|define
name|SMBATT_BS_ERROR_UNKNOWN
value|7
end_define

begin_comment
comment|/*  * access: READ WORD  * unit  : cycle(s)  * range : 0 .. 65534, 65535 reserved  */
end_comment

begin_define
define|#
directive|define
name|SMBATT_CMD_CYCLE_COUNT
value|0x17
end_define

begin_comment
comment|/*  * access: READ WORD  * unit  : mAh (CAPACITY_MODE=0) or 10 mWh (CAPACITY_MODE=1)  * range : 0..65535 inclusively  */
end_comment

begin_define
define|#
directive|define
name|SMBATT_CMD_DESIGN_CAPACITY
value|0x18
end_define

begin_comment
comment|/*  * access: READ WORD  * unit  : mV  * range : 0..65535 mV  */
end_comment

begin_define
define|#
directive|define
name|SMBATT_CMD_DESIGN_VOLTAGE
value|0x19
end_define

begin_comment
comment|/* access: READ WORD */
end_comment

begin_define
define|#
directive|define
name|SMBATT_CMD_SPECIFICATION_INFO
value|0x1a
end_define

begin_define
define|#
directive|define
name|SMBATT_SI_GET_REVISION
parameter_list|(
name|x
parameter_list|)
value|(((x)>>  0)& 0xf)
end_define

begin_define
define|#
directive|define
name|SMBATT_SI_GET_VERSION
parameter_list|(
name|x
parameter_list|)
value|(((x)>>  4)& 0xf)
end_define

begin_define
define|#
directive|define
name|SMBATT_SI_GET_VSCALE
parameter_list|(
name|x
parameter_list|)
value|(((x)>>  8)& 0xf)
end_define

begin_define
define|#
directive|define
name|SMBATT_SI_GET_IPSCALE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0xf)
end_define

begin_comment
comment|/* access: READ WORD */
end_comment

begin_define
define|#
directive|define
name|SMBATT_CMD_MANUFACTURE_DATE
value|0x1b
end_define

begin_define
define|#
directive|define
name|SMBATT_MD_GET_DAY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1f)
end_define

begin_define
define|#
directive|define
name|SMBATT_MD_GET_MONTH
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 5)& 0xf)
end_define

begin_define
define|#
directive|define
name|SMBATT_MD_GET_YEAR
parameter_list|(
name|x
parameter_list|)
value|((((x)>> 9)& 0x7f) + 1980)
end_define

begin_comment
comment|/* access: READ WORD */
end_comment

begin_define
define|#
directive|define
name|SMBATT_CMD_SERIAL_NUMBER
value|0x1c
end_define

begin_comment
comment|/* access: READ BLOCK */
end_comment

begin_define
define|#
directive|define
name|SMBATT_CMD_MANUFACTURER_NAME
value|0x20
end_define

begin_comment
comment|/* access: READ BLOCK */
end_comment

begin_define
define|#
directive|define
name|SMBATT_CMD_DEVICE_NAME
value|0x21
end_define

begin_comment
comment|/* access: READ BLOCK */
end_comment

begin_define
define|#
directive|define
name|SMBATT_CMD_DEVICE_CHEMISTRY
value|0x22
end_define

begin_comment
comment|/* access: READ BLOCK */
end_comment

begin_define
define|#
directive|define
name|SMBATT_CMD_MANUFACTURER_DATA
value|0x23
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_ACPI_SMBUS_H_ */
end_comment

end_unit

