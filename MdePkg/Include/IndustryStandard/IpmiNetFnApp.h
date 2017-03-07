begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   IPMI 2.0 definitions from the IPMI Specification Version 2.0, Revision 1.1.    This file contains all NetFn App commands, including:     IPM Device "Global" Commands (Chapter 20)     Firmware Firewall& Command Discovery Commands (Chapter 21)     BMC Watchdog Timer Commands (Chapter 27)     IPMI Messaging Support Commands (Chapter 22)     RMCP+ Support and Payload Commands (Chapter 24)    See IPMI specification, Appendix G, Command Assignments   and Appendix H, Sub-function Assignments.    Copyright (c) 1999 - 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED. **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IPMI_NET_FN_APP_H_
end_ifndef

begin_define
define|#
directive|define
name|_IPMI_NET_FN_APP_H_
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
comment|// Net function definition for App command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_NETFN_APP
value|0x06
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Below is Definitions for IPM Device "Global" Commands  (Chapter 20)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get Device ID command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_GET_DEVICE_ID
value|0x1
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get Device ID" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|CompletionCode
decl_stmt|;
name|UINT8
name|DeviceId
decl_stmt|;
name|UINT8
name|DeviceRevision
range|:
literal|4
decl_stmt|;
name|UINT8
name|Reserved
range|:
literal|3
decl_stmt|;
name|UINT8
name|DeviceSdr
range|:
literal|1
decl_stmt|;
name|UINT8
name|MajorFirmwareRev
range|:
literal|7
decl_stmt|;
name|UINT8
name|UpdateMode
range|:
literal|1
decl_stmt|;
name|UINT8
name|MinorFirmwareRev
decl_stmt|;
name|UINT8
name|SpecificationVersion
decl_stmt|;
name|UINT8
name|SensorDeviceSupport
range|:
literal|1
decl_stmt|;
name|UINT8
name|SdrRepositorySupport
range|:
literal|1
decl_stmt|;
name|UINT8
name|SelDeviceSupport
range|:
literal|1
decl_stmt|;
name|UINT8
name|FruInventorySupport
range|:
literal|1
decl_stmt|;
name|UINT8
name|IpmbMessageReceiver
range|:
literal|1
decl_stmt|;
name|UINT8
name|IpmbMessageGenerator
range|:
literal|1
decl_stmt|;
name|UINT8
name|BridgeSupport
range|:
literal|1
decl_stmt|;
name|UINT8
name|ChassisSupport
range|:
literal|1
decl_stmt|;
name|UINT8
name|ManufacturerId
index|[
literal|3
index|]
decl_stmt|;
name|UINT16
name|ProductId
decl_stmt|;
name|UINT32
name|AuxFirmwareRevInfo
decl_stmt|;
block|}
name|IPMI_GET_DEVICE_ID_RESPONSE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Cold Reset command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_COLD_RESET
value|0x2
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Cold Reset" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Warm Reset command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_WARM_RESET
value|0x3
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Warm Reset" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get Self Results command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_GET_SELFTEST_RESULTS
value|0x4
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get Self Test Results" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|CompletionCode
decl_stmt|;
name|UINT8
name|Result
decl_stmt|;
name|UINT8
name|Param
decl_stmt|;
block|}
name|IPMI_SELF_TEST_RESULT_RESPONSE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IPMI_APP_SELFTEST_NO_ERROR
value|0x55
end_define

begin_define
define|#
directive|define
name|IPMI_APP_SELFTEST_NOT_IMPLEMENTED
value|0x56
end_define

begin_define
define|#
directive|define
name|IPMI_APP_SELFTEST_ERROR
value|0x57
end_define

begin_define
define|#
directive|define
name|IPMI_APP_SELFTEST_FATAL_HW_ERROR
value|0x58
end_define

begin_define
define|#
directive|define
name|IPMI_APP_SELFTEST_INACCESSIBLE_SEL
value|0x80
end_define

begin_define
define|#
directive|define
name|IPMI_APP_SELFTEST_INACCESSIBLE_SDR
value|0x40
end_define

begin_define
define|#
directive|define
name|IPMI_APP_SELFTEST_INACCESSIBLE_FRU
value|0x20
end_define

begin_define
define|#
directive|define
name|IPMI_APP_SELFTEST_IPMB_SIGNAL_FAIL
value|0x10
end_define

begin_define
define|#
directive|define
name|IPMI_APP_SELFTEST_SDR_REPOSITORY_EMPTY
value|0x08
end_define

begin_define
define|#
directive|define
name|IPMI_APP_SELFTEST_FRU_CORRUPT
value|0x04
end_define

begin_define
define|#
directive|define
name|IPMI_APP_SELFTEST_FW_BOOTBLOCK_CORRUPT
value|0x02
end_define

begin_define
define|#
directive|define
name|IPMI_APP_SELFTEST_FW_CORRUPT
value|0x01
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Manufacturing Test ON command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_MANUFACTURING_TEST_ON
value|0x5
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Manufacturing Test ON" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Set ACPI Power State command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_SET_ACPI_POWERSTATE
value|0x6
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Set ACPI Power State" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|AcpiSystemPowerState
range|:
literal|7
decl_stmt|;
name|UINT8
name|AcpiSystemStateChange
range|:
literal|1
decl_stmt|;
name|UINT8
name|AcpiDevicePowerState
range|:
literal|7
decl_stmt|;
name|UINT8
name|AcpiDeviceStateChange
range|:
literal|1
decl_stmt|;
block|}
name|IPMI_SET_ACPI_POWER_STATE_REQUEST
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get ACPI Power State command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_GET_ACPI_POWERSTATE
value|0x7
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get ACPI Power State" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get Device GUID command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_GET_DEVICE_GUID
value|0x8
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get Device GUID" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Message structure definition for "Get Device Guid" IPMI command
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|CompletionCode
decl_stmt|;
name|UINT8
name|Guid
index|[
literal|16
index|]
decl_stmt|;
block|}
name|IPMI_GET_DEVICE_GUID_RESPONSE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|//  Below is Definitions for BMC Watchdog Timer Commands (Chapter 27)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Reset WatchDog Timer command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_RESET_WATCHDOG_TIMER
value|0x22
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Reset WatchDog Timer" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|TimerUse
range|:
literal|3
decl_stmt|;
name|UINT8
name|Reserved
range|:
literal|3
decl_stmt|;
name|UINT8
name|TimerRunning
range|:
literal|1
decl_stmt|;
name|UINT8
name|TimerUseExpirationFlagLog
range|:
literal|1
decl_stmt|;
block|}
name|IPMI_WATCHDOG_TIMER_USE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Set WatchDog Timer command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_SET_WATCHDOG_TIMER
value|0x24
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Set WatchDog Timer" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|IPMI_WATCHDOG_TIMER_USE
name|TimerUse
decl_stmt|;
name|UINT8
name|TimerActions
decl_stmt|;
name|UINT8
name|PretimeoutInterval
decl_stmt|;
name|UINT8
name|TimerUseExpirationFlagsClear
decl_stmt|;
name|UINT16
name|InitialCountdownValue
decl_stmt|;
block|}
name|IPMI_SET_WATCHDOG_TIMER_REQUEST
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get WatchDog Timer command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_GET_WATCHDOG_TIMER
value|0x25
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get WatchDog Timer" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|CompletionCode
decl_stmt|;
name|IPMI_WATCHDOG_TIMER_USE
name|TimerUse
decl_stmt|;
name|UINT8
name|TimerActions
decl_stmt|;
name|UINT8
name|PretimeoutInterval
decl_stmt|;
name|UINT8
name|TimerUseExpirationFlagsClear
decl_stmt|;
name|UINT16
name|InitialCountdownValue
decl_stmt|;
name|UINT16
name|PresentCountdownValue
decl_stmt|;
block|}
name|IPMI_GET_WATCHDOG_TIMER_RESPONSE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|//  Below is Definitions for IPMI Messaging Support Commands (Chapter 22)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Set BMC Global Enables command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_SET_BMC_GLOBAL_ENABLES
value|0x2E
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Set BMC Global Enables " command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get BMC Global Enables command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_GET_BMC_GLOBAL_ENABLES
value|0x2F
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get BMC Global Enables " command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Clear Message Flags command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_CLEAR_MESSAGE_FLAGS
value|0x30
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Clear Message Flags" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get Message Flags command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_GET_MESSAGE_FLAGS
value|0x31
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get Message Flags" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Enable Message Channel Receive command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_ENABLE_MESSAGE_CHANNEL_RECEIVE
value|0x32
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Enable Message Channel Receive" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get Message command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_GET_MESSAGE
value|0x33
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get Message" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Send Message command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_SEND_MESSAGE
value|0x34
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Send Message" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Read Event Message Buffer command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_READ_EVENT_MSG_BUFFER
value|0x35
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Read Event Message Buffer" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get BT Interface Capabilities command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_GET_BT_INTERFACE_CAPABILITY
value|0x36
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get BT Interface Capabilities" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get System GUID command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_GET_SYSTEM_GUID
value|0x37
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get System GUID" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get Channel Authentication Capabilities command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_GET_CHANNEL_AUTHENTICATION_CAPABILITIES
value|0x38
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get Channel Authentication Capabilities" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get Session Challenge command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_GET_SESSION_CHALLENGE
value|0x39
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get Session Challenge" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Activate Session command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_ACTIVATE_SESSION
value|0x3A
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Activate Session" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Set Session Privelege Level command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_SET_SESSION_PRIVELEGE_LEVEL
value|0x3B
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Set Session Privelege Level" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Close Session command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_CLOSE_SESSION
value|0x3C
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Close Session" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get Session Info command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_GET_SESSION_INFO
value|0x3D
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get Session Info" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get Auth Code command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_GET_AUTHCODE
value|0x3F
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get AuthCode" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Set Channel Access command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_SET_CHANNEL_ACCESS
value|0x40
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Set Channel Access" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get Channel Access command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_GET_CHANNEL_ACCESS
value|0x41
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get Channel Access" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|ChannelNo
range|:
literal|4
decl_stmt|;
name|UINT8
name|Reserve1
range|:
literal|4
decl_stmt|;
name|UINT8
name|Reserve2
range|:
literal|6
decl_stmt|;
name|UINT8
name|MemoryType
range|:
literal|2
decl_stmt|;
block|}
name|IPMI_GET_CHANNEL_ACCESS_REQUEST
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
name|AccessMode
range|:
literal|3
decl_stmt|;
name|UINT8
name|UserLevelAuthEnabled
range|:
literal|1
decl_stmt|;
name|UINT8
name|MessageAuthEnable
range|:
literal|1
decl_stmt|;
name|UINT8
name|Alert
range|:
literal|1
decl_stmt|;
name|UINT8
name|Reserve1
range|:
literal|2
decl_stmt|;
name|UINT8
name|ChannelPriviledgeLimit
range|:
literal|4
decl_stmt|;
name|UINT8
name|Reserve2
range|:
literal|4
decl_stmt|;
block|}
name|IPMI_GET_CHANNEL_ACCESS_RESPONSE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get Channel Info command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_GET_CHANNEL_INFO
value|0x42
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get Channel Info" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|CompletionCode
decl_stmt|;
name|UINT8
name|ChannelNo
range|:
literal|4
decl_stmt|;
name|UINT8
name|Reserve1
range|:
literal|4
decl_stmt|;
name|UINT8
name|ChannelMediumType
range|:
literal|7
decl_stmt|;
name|UINT8
name|Reserve2
range|:
literal|1
decl_stmt|;
name|UINT8
name|ChannelProtocolType
range|:
literal|5
decl_stmt|;
name|UINT8
name|Reserve3
range|:
literal|3
decl_stmt|;
name|UINT8
name|ActiveSessionCount
range|:
literal|6
decl_stmt|;
name|UINT8
name|SessionSupport
range|:
literal|2
decl_stmt|;
name|UINT8
name|VendorId
index|[
literal|3
index|]
decl_stmt|;
name|UINT16
name|AuxChannelInfo
decl_stmt|;
block|}
name|IPMI_GET_CHANNEL_INFO_RESPONSE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get Channel Info command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_GET_CHANNEL_INFO
value|0x42
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get Channel Info" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Set User Access command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_SET_USER_ACCESS
value|0x43
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Set User Access" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get User Access command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_GET_USER_ACCESS
value|0x44
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get User Access" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Set User Name command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_SET_USER_NAME
value|0x45
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Set User Name" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get User Name command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_GET_USER_NAME
value|0x46
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get User Name" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Set User Password command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_SET_USER_PASSWORD
value|0x47
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Set User Password" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Below is Definitions for RMCP+ Support and Payload Commands (Chapter 24)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Activate Payload command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_ACTIVATE_PAYLOAD
value|0x48
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Activate Payload" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for De-Activate Payload command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_DEACTIVATE_PAYLOAD
value|0x49
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "DeActivate Payload" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get Payload activation Status command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_GET_PAYLOAD_ACTIVATION_STATUS
value|0x4a
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get Payload activation Status" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get Payload Instance Info command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_GET_PAYLOAD_INSTANCE_INFO
value|0x4b
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get Payload Instance Info" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Set User Payload Access command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_SET_USER_PAYLOAD_ACCESS
value|0x4C
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Set User Payload Access" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get User Payload Access command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_GET_USER_PAYLOAD_ACCESS
value|0x4D
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get User Payload Access" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get Channel Payload Support command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_GET_CHANNEL_PAYLOAD_SUPPORT
value|0x4E
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get Channel Payload Support" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get Channel Payload Version command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_GET_CHANNEL_PAYLOAD_VERSION
value|0x4F
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get Channel Payload Version" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get Channel OEM Payload Info command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_GET_CHANNEL_OEM_PAYLOAD_INFO
value|0x50
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get Channel OEM Payload Info" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for  Master Write-Read command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_MASTER_WRITE_READ
value|0x52
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Master Write Read" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for  Get Channel Cipher Suites command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_GET_CHANNEL_CIPHER_SUITES
value|0x54
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get Channel Cipher Suites" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Below is Definitions for RMCP+ Support and Payload Commands (Chapter 24, Section 3)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for  Suspend-Resume Payload Encryption command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_SUSPEND_RESUME_PAYLOAD_ENCRYPTION
value|0x55
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Suspend-Resume Payload Encryption" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Below is Definitions for IPMI Messaging Support Commands (Chapter 22, Section 25 and 9)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for  Set Channel Security Keys command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_SET_CHANNEL_SECURITY_KEYS
value|0x56
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Set Channel Security Keys" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for  Get System Interface Capabilities command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_APP_GET_SYSTEM_INTERFACE_CAPABILITIES
value|0x57
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get System Interface Capabilities" command to follow here
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

