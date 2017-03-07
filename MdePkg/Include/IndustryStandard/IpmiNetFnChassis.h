begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   IPMI 2.0 definitions from the IPMI Specification Version 2.0, Revision 1.1.    This file contains all NetFn Chassis commands, including:     Chassis Commands (Chapter 28)    See IPMI specification, Appendix G, Command Assignments   and Appendix H, Sub-function Assignments.    Copyright (c) 1999 - 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED. **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IPMI_NET_FN_CHASSIS_H_
end_ifndef

begin_define
define|#
directive|define
name|_IPMI_NET_FN_CHASSIS_H_
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_comment
comment|//
end_comment

begin_comment
comment|// Net function definition for Chassis command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_NETFN_CHASSIS
value|0x00
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Below is Definitions for Chassis commands (Chapter 28)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get Chassis Capabilities command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_CHASSIS_GET_CAPABILITIES
value|0x00
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get Chassis Capabilities" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get Chassis Status command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_CHASSIS_GET_STATUS
value|0x01
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get Chassis Status" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Chassis Control command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_CHASSIS_CONTROL
value|0x02
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Chassis Control" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Chassis Reset command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_CHASSIS_RESET
value|0x03
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Chassis Reset" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Chassis Identify command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_CHASSIS_IDENTIFY
value|0x04
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Chassis Identify" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Set Chassis Capabilities command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_CHASSIS_SET_CAPABILITIES
value|0x05
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Set Chassis Capabilities" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Set Power Restore Policy command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_CHASSIS_SET_POWER_RESTORE_POLICY
value|0x06
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Set Power Restore Policy" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get System Restart Cause command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_CHASSIS_GET_SYSTEM_RESTART_CAUSE
value|0x07
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get System Restart Cause" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|Unknown
block|,
name|ChassisControlCommand
block|,
name|ResetViaPushButton
block|,
name|PowerupViaPowerButton
block|,
name|WatchdogExpiration
block|,
name|Oem
block|,
name|AutoPowerOnAlwaysRestore
block|,
name|AutoPowerOnRestorePrevious
block|,
name|ResetViaPef
block|,
name|PowerCycleViaPef
block|,
name|SoftReset
block|,
name|PowerUpViaRtc
block|}
name|IPMI_SYSTEM_RESTART_CAUSE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|CompletionCode
decl_stmt|;
name|UINT8
name|Cause
range|:
literal|4
decl_stmt|;
name|UINT8
name|Reserved
range|:
literal|4
decl_stmt|;
name|UINT8
name|ChannelNumber
decl_stmt|;
block|}
name|IPMI_GET_SYSTEM_RESTART_CAUSE_RESPONSE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Set System BOOT options command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_CHASSIS_SET_SYSTEM_BOOT_OPTIONS
value|0x08
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Set System boot options" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|ParameterSelector
range|:
literal|7
decl_stmt|;
name|UINT8
name|MarkParameterInvalid
range|:
literal|1
decl_stmt|;
name|UINT8
name|ParameterData
index|[
literal|1
index|]
decl_stmt|;
block|}
name|IPMI_SET_BOOT_OPTIONS_REQUEST
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get System BOOT options command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_CHASSIS_GET_SYSTEM_BOOT_OPTIONS
value|0x09
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get System boot options" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|ParameterSelector
range|:
literal|7
decl_stmt|;
name|UINT8
name|Reserved
range|:
literal|1
decl_stmt|;
name|UINT8
name|SetSelector
decl_stmt|;
name|UINT8
name|BlockSelector
decl_stmt|;
block|}
name|IPMI_GET_BOOT_OPTIONS_REQUEST
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Parameter
decl_stmt|;
name|UINT8
name|Valid
decl_stmt|;
name|UINT8
name|Data1
decl_stmt|;
name|UINT8
name|Data2
decl_stmt|;
name|UINT8
name|Data3
decl_stmt|;
name|UINT8
name|Data4
decl_stmt|;
name|UINT8
name|Data5
decl_stmt|;
block|}
name|IPMI_GET_THE_SYSTEM_BOOT_OPTIONS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|ParameterVersion
decl_stmt|;
name|UINT8
name|ParameterValid
decl_stmt|;
name|UINT8
name|ChannelNumber
decl_stmt|;
name|UINT32
name|SessionId
decl_stmt|;
name|UINT32
name|TimeStamp
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|3
index|]
decl_stmt|;
block|}
name|IPMI_BOOT_INITIATOR
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Response Parameters for IPMI Get Boot Options
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|SetInProgress
range|:
literal|2
decl_stmt|;
name|UINT8
name|Reserved
range|:
literal|6
decl_stmt|;
block|}
name|IPMI_BOOT_OPTIONS_RESPONSE_PARAMETER_0
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|ServicePartitionSelector
decl_stmt|;
block|}
name|IPMI_BOOT_OPTIONS_RESPONSE_PARAMETER_1
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|ServicePartitionDiscovered
range|:
literal|1
decl_stmt|;
name|UINT8
name|ServicePartitionScanRequest
range|:
literal|1
decl_stmt|;
name|UINT8
name|Reserved
range|:
literal|5
decl_stmt|;
block|}
name|IPMI_BOOT_OPTIONS_RESPONSE_PARAMETER_2
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|BmcBootFlagValid
range|:
literal|5
decl_stmt|;
name|UINT8
name|Reserved
range|:
literal|3
decl_stmt|;
block|}
name|IPMI_BOOT_OPTIONS_RESPONSE_PARAMETER_3
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|WriteMask
decl_stmt|;
name|UINT8
name|BootInitiatorAcknowledgeData
decl_stmt|;
block|}
name|IPMI_BOOT_OPTIONS_RESPONSE_PARAMETER_4
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BOOT_OPTION_HANDLED_BY_BIOS
value|0x01
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// Data 1
comment|//
name|UINT8
name|Reserved0
range|:
literal|6
decl_stmt|;
name|UINT8
name|PersistentOptions
range|:
literal|1
decl_stmt|;
name|UINT8
name|BootFlagValid
range|:
literal|1
decl_stmt|;
comment|//
comment|// Data 2
comment|//
name|UINT8
name|LockReset
range|:
literal|1
decl_stmt|;
name|UINT8
name|ScreenBlank
range|:
literal|1
decl_stmt|;
name|UINT8
name|BootDeviceSelector
range|:
literal|4
decl_stmt|;
name|UINT8
name|LockKeyboard
range|:
literal|1
decl_stmt|;
name|UINT8
name|CmosClear
range|:
literal|1
decl_stmt|;
comment|//
comment|//
comment|// Data 3
name|UINT8
name|ConsoleRedirection
range|:
literal|2
decl_stmt|;
name|UINT8
name|LockSleep
range|:
literal|1
decl_stmt|;
name|UINT8
name|UserPasswordBypass
range|:
literal|1
decl_stmt|;
name|UINT8
name|ForceProgressEventTrap
range|:
literal|1
decl_stmt|;
name|UINT8
name|BiosVerbosity
range|:
literal|2
decl_stmt|;
name|UINT8
name|LockPower
range|:
literal|1
decl_stmt|;
comment|//
comment|// Data 4
comment|//
name|UINT8
name|BiosMuxControlOverride
range|:
literal|2
decl_stmt|;
name|UINT8
name|BiosSharedModeOverride
range|:
literal|1
decl_stmt|;
name|UINT8
name|Reserved1
range|:
literal|4
decl_stmt|;
block|}
name|IPMI_BOOT_OPTIONS_RESPONSE_PARAMETER_5
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|ChannelNumber
range|:
literal|4
decl_stmt|;
name|UINT8
name|Reserved
range|:
literal|4
decl_stmt|;
name|UINT8
name|SessionId
index|[
literal|4
index|]
decl_stmt|;
name|UINT8
name|BootInfoTimeStamp
index|[
literal|4
index|]
decl_stmt|;
block|}
name|IPMI_BOOT_OPTIONS_RESPONSE_PARAMETER_6
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|SetSelector
decl_stmt|;
name|UINT8
name|BlockData
index|[
literal|16
index|]
decl_stmt|;
block|}
name|IPMI_BOOT_OPTIONS_RESPONSE_PARAMETER_7
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|IPMI_BOOT_OPTIONS_RESPONSE_PARAMETER_0
name|Parm0
decl_stmt|;
name|IPMI_BOOT_OPTIONS_RESPONSE_PARAMETER_1
name|Parm1
decl_stmt|;
name|IPMI_BOOT_OPTIONS_RESPONSE_PARAMETER_2
name|Parm2
decl_stmt|;
name|IPMI_BOOT_OPTIONS_RESPONSE_PARAMETER_3
name|Parm3
decl_stmt|;
name|IPMI_BOOT_OPTIONS_RESPONSE_PARAMETER_4
name|Parm4
decl_stmt|;
name|IPMI_BOOT_OPTIONS_RESPONSE_PARAMETER_5
name|Parm5
decl_stmt|;
name|IPMI_BOOT_OPTIONS_RESPONSE_PARAMETER_6
name|Parm6
decl_stmt|;
name|IPMI_BOOT_OPTIONS_RESPONSE_PARAMETER_7
name|Parm7
decl_stmt|;
block|}
name|IPMI_BOOT_OPTIONS_PARAMETERS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|CompletionCode
decl_stmt|;
name|UINT8
name|ParameterVersion
range|:
literal|4
decl_stmt|;
name|UINT8
name|Reserved
range|:
literal|4
decl_stmt|;
name|UINT8
name|ParameterSelector
range|:
literal|7
decl_stmt|;
name|UINT8
name|ParameterValid
range|:
literal|1
decl_stmt|;
name|UINT8
name|ParameterData
index|[
literal|1
index|]
decl_stmt|;
block|}
name|IPMI_GET_BOOT_OPTIONS_RESPONSE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Set front panel button enables command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_CHASSIS_SET_FRONT_PANEL_BUTTON_ENABLES
value|0x0A
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|DisablePoweroffButton
range|:
literal|1
decl_stmt|;
name|UINT8
name|DisableResetButton
range|:
literal|1
decl_stmt|;
name|UINT8
name|DisableDiagnosticInterruptButton
range|:
literal|1
decl_stmt|;
name|UINT8
name|DisableStandbyButton
range|:
literal|1
decl_stmt|;
name|UINT8
name|Reserved
range|:
literal|4
decl_stmt|;
block|}
name|IPMI_CHASSIS_SET_FRONT_PANEL_BUTTON_ENABLES_REQUEST
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Set front panel button enables" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Set Power Cycle Interval command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_CHASSIS_SET_POWER_CYCLE_INTERVALS
value|0x0B
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Set Power Cycle Interval" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get POH Counter command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_CHASSIS_GET_POH_COUNTER
value|0x0F
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get POH Counter" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

end_unit

