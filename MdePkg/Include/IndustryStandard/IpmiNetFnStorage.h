begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   IPMI 2.0 definitions from the IPMI Specification Version 2.0, Revision 1.1.    This file contains all NetFn Storage commands, including:     FRU Inventory Commands (Chapter 34)     SDR Repository (Chapter 33)     System Event Log(SEL) Commands (Chapter 31)     SEL Record Formats (Chapter 32)    See IPMI specification, Appendix G, Command Assignments   and Appendix H, Sub-function Assignments.    Copyright (c) 1999 - 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED. **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IPMI_NET_FN_STORAGE_H_
end_ifndef

begin_define
define|#
directive|define
name|_IPMI_NET_FN_STORAGE_H_
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
comment|// Net function definition for Storage command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_NETFN_STORAGE
value|0x0A
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// All Storage commands and their structure definitions to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Below is Definitions for FRU Inventory Commands (Chapter 34)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get Fru Inventory Area Info command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_STORAGE_GET_FRU_INVENTORY_AREAINFO
value|0x10
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get Fru Inventory Area Info" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get Fru Data command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_STORAGE_READ_FRU_DATA
value|0x11
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get Fru Data" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|FruDeviceId
decl_stmt|;
name|UINT16
name|FruOffset
decl_stmt|;
block|}
name|IPMI_FRU_COMMON_DATA
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|IPMI_FRU_COMMON_DATA
name|Data
decl_stmt|;
name|UINT8
name|Count
decl_stmt|;
block|}
name|IPMI_FRU_READ_COMMAND
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Write Fru Data command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_STORAGE_WRITE_FRU_DATA
value|0x12
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Write Fru Data" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|IPMI_FRU_COMMON_DATA
name|Data
decl_stmt|;
name|UINT8
name|FruData
index|[
literal|16
index|]
decl_stmt|;
block|}
name|IPMI_FRU_WRITE_COMMAND
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|//  Below is Definitions for SDR Repository (Chapter 33)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get SDR Repository Info command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_STORAGE_GET_SDR_REPOSITORY_INFO
value|0x20
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get SDR Repository Info" command to follow here
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
name|Version
decl_stmt|;
name|UINT16
name|RecordCount
decl_stmt|;
name|UINT16
name|FreeSpace
decl_stmt|;
name|UINT32
name|RecentAdditionTimeStamp
decl_stmt|;
name|UINT32
name|RecentEraseTimeStamp
decl_stmt|;
name|UINT8
name|SdrRepAllocInfoCmd
range|:
literal|1
decl_stmt|;
name|UINT8
name|SdrRepReserveCmd
range|:
literal|1
decl_stmt|;
name|UINT8
name|PartialAddSdrCmd
range|:
literal|1
decl_stmt|;
name|UINT8
name|DeleteSdrRepCmd
range|:
literal|1
decl_stmt|;
name|UINT8
name|Reserved
range|:
literal|1
decl_stmt|;
name|UINT8
name|SdrRepUpdateOp
range|:
literal|2
decl_stmt|;
name|UINT8
name|Overflow
range|:
literal|1
decl_stmt|;
block|}
name|IPMI_GET_SDR_REPOSITORY_INFO
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get SDR Repository Allocateion Info command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_STORAGE_GET_SDR_REPOSITORY_ALLOCATION_INFO
value|0x21
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get SDR Repository Allocateion Info" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Reserve SDR Repository command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_STORAGE_RESERVE_SDR_REPOSITORY
value|0x22
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Reserve SDR Repository" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get SDR command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_STORAGE_GET_SDR
value|0x23
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get SDR" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|RecordId
decl_stmt|;
comment|// 1
name|UINT8
name|Version
decl_stmt|;
comment|// 3
name|UINT8
name|RecordType
decl_stmt|;
comment|// 4
name|UINT8
name|RecordLength
decl_stmt|;
comment|// 5
name|UINT8
name|OwnerId
decl_stmt|;
comment|// 6
name|UINT8
name|OwnerLun
decl_stmt|;
comment|// 7
name|UINT8
name|SensorNumber
decl_stmt|;
comment|// 8
name|UINT8
name|EntityId
decl_stmt|;
comment|// 9
name|UINT8
name|EntityInstance
decl_stmt|;
comment|// 10
name|UINT8
name|EventScanningEnabled
range|:
literal|1
decl_stmt|;
comment|// 11
name|UINT8
name|EventScanningDisabled
range|:
literal|1
decl_stmt|;
comment|// 11
name|UINT8
name|InitSensorType
range|:
literal|1
decl_stmt|;
comment|// 11
name|UINT8
name|InitHysteresis
range|:
literal|1
decl_stmt|;
comment|// 11
name|UINT8
name|InitThresholds
range|:
literal|1
decl_stmt|;
comment|// 11
name|UINT8
name|InitEvent
range|:
literal|1
decl_stmt|;
comment|// 11
name|UINT8
name|InitScanning
range|:
literal|1
decl_stmt|;
comment|// 11
name|UINT8
name|Reserved
range|:
literal|1
decl_stmt|;
comment|// 11
name|UINT8
name|EventMessageControl
range|:
literal|2
decl_stmt|;
comment|// 12
name|UINT8
name|ThresholdAccessSupport
range|:
literal|2
decl_stmt|;
comment|// 12
name|UINT8
name|HysteresisSupport
range|:
literal|2
decl_stmt|;
comment|// 12
name|UINT8
name|ReArmSupport
range|:
literal|1
decl_stmt|;
comment|// 12
name|UINT8
name|IgnoreSensor
range|:
literal|1
decl_stmt|;
comment|// 12
name|UINT8
name|SensorType
decl_stmt|;
comment|// 13
name|UINT8
name|EventType
decl_stmt|;
comment|// 14
name|UINT8
name|Reserved1
index|[
literal|7
index|]
decl_stmt|;
comment|// 15
name|UINT8
name|UnitType
decl_stmt|;
comment|// 22
name|UINT8
name|Reserved2
decl_stmt|;
comment|// 23
name|UINT8
name|Linearization
range|:
literal|7
decl_stmt|;
comment|// 24
name|UINT8
name|Reserved3
range|:
literal|1
decl_stmt|;
comment|// 24
name|UINT8
name|MLo
decl_stmt|;
comment|// 25
name|UINT8
name|Toleremce
range|:
literal|6
decl_stmt|;
comment|// 26
name|UINT8
name|MHi
range|:
literal|2
decl_stmt|;
comment|// 26
name|UINT8
name|BLo
decl_stmt|;
comment|// 27
name|UINT8
name|AccuracyLow
range|:
literal|6
decl_stmt|;
comment|// 28
name|UINT8
name|BHi
range|:
literal|2
decl_stmt|;
comment|// 28
name|UINT8
name|Reserved4
range|:
literal|2
decl_stmt|;
comment|// 29
name|UINT8
name|AccuracyExp
range|:
literal|2
decl_stmt|;
comment|// 29
name|UINT8
name|AccuracyHi
range|:
literal|4
decl_stmt|;
comment|// 29
name|UINT8
name|BExp
range|:
literal|4
decl_stmt|;
comment|// 30
name|UINT8
name|RExp
range|:
literal|4
decl_stmt|;
comment|// 30
name|UINT8
name|NominalReadingSpscified
range|:
literal|1
decl_stmt|;
comment|// 31
name|UINT8
name|NominalMaxSpscified
range|:
literal|1
decl_stmt|;
comment|// 31
name|UINT8
name|NominalMinSpscified
range|:
literal|1
decl_stmt|;
comment|// 31
name|UINT8
name|Reserved5
range|:
literal|5
decl_stmt|;
comment|// 31
name|UINT8
name|NominalReading
decl_stmt|;
comment|// 32
name|UINT8
name|Reserved6
index|[
literal|4
index|]
decl_stmt|;
comment|// 33
name|UINT8
name|UpperNonRecoverThreshold
decl_stmt|;
comment|// 37
name|UINT8
name|UpperCriticalThreshold
decl_stmt|;
comment|// 38
name|UINT8
name|UpperNonCriticalThreshold
decl_stmt|;
comment|// 39
name|UINT8
name|LowerNonRecoverThreshold
decl_stmt|;
comment|// 40
name|UINT8
name|LowerCriticalThreshold
decl_stmt|;
comment|// 41
name|UINT8
name|LowerNonCriticalThreshold
decl_stmt|;
comment|// 42
name|UINT8
name|Reserved7
index|[
literal|5
index|]
decl_stmt|;
comment|// 43
name|UINT8
name|IdStringLength
decl_stmt|;
comment|// 48
name|UINT8
name|AsciiIdString
index|[
literal|16
index|]
decl_stmt|;
comment|// 49 - 64
block|}
name|IPMI_SDR_RECORD_STRUCT_1
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|RecordId
decl_stmt|;
comment|// 1
name|UINT8
name|Version
decl_stmt|;
comment|// 3
name|UINT8
name|RecordType
decl_stmt|;
comment|// 4
name|UINT8
name|RecordLength
decl_stmt|;
comment|// 5
name|UINT8
name|OwnerId
decl_stmt|;
comment|// 6
name|UINT8
name|OwnerLun
decl_stmt|;
comment|// 7
name|UINT8
name|SensorNumber
decl_stmt|;
comment|// 8
name|UINT8
name|EntityId
decl_stmt|;
comment|// 9
name|UINT8
name|EntityInstance
decl_stmt|;
comment|// 10
name|UINT8
name|SensorScanning
range|:
literal|1
decl_stmt|;
comment|// 11
name|UINT8
name|EventScanning
range|:
literal|1
decl_stmt|;
comment|// 11
name|UINT8
name|InitSensorType
range|:
literal|1
decl_stmt|;
comment|// 11
name|UINT8
name|InitHysteresis
range|:
literal|1
decl_stmt|;
comment|// 11
name|UINT8
name|InitThresholds
range|:
literal|1
decl_stmt|;
comment|// 11
name|UINT8
name|InitEvent
range|:
literal|1
decl_stmt|;
comment|// 11
name|UINT8
name|InitScanning
range|:
literal|1
decl_stmt|;
comment|// 11
name|UINT8
name|Reserved
range|:
literal|1
decl_stmt|;
comment|// 11
name|UINT8
name|EventMessageControl
range|:
literal|2
decl_stmt|;
comment|// 12
name|UINT8
name|ThresholdAccessSupport
range|:
literal|2
decl_stmt|;
comment|// 12
name|UINT8
name|HysteresisSupport
range|:
literal|2
decl_stmt|;
comment|// 12
name|UINT8
name|ReArmSupport
range|:
literal|1
decl_stmt|;
comment|// 12
name|UINT8
name|IgnoreSensor
range|:
literal|1
decl_stmt|;
comment|// 12
name|UINT8
name|SensorType
decl_stmt|;
comment|// 13
name|UINT8
name|EventType
decl_stmt|;
comment|// 14
name|UINT8
name|Reserved1
index|[
literal|7
index|]
decl_stmt|;
comment|// 15
name|UINT8
name|UnitType
decl_stmt|;
comment|// 22
name|UINT8
name|Reserved2
index|[
literal|9
index|]
decl_stmt|;
comment|// 23
name|UINT8
name|IdStringLength
decl_stmt|;
comment|// 32
name|UINT8
name|AsciiIdString
index|[
literal|16
index|]
decl_stmt|;
comment|// 33 - 48
block|}
name|IPMI_SDR_RECORD_STRUCT_2
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Reserved1
range|:
literal|1
decl_stmt|;
name|UINT8
name|ControllerSlaveAddress
range|:
literal|7
decl_stmt|;
name|UINT8
name|FruDeviceId
decl_stmt|;
name|UINT8
name|BusId
range|:
literal|3
decl_stmt|;
name|UINT8
name|Lun
range|:
literal|2
decl_stmt|;
name|UINT8
name|Reserved
range|:
literal|2
decl_stmt|;
name|UINT8
name|LogicalFruDevice
range|:
literal|1
decl_stmt|;
name|UINT8
name|Reserved3
range|:
literal|4
decl_stmt|;
name|UINT8
name|ChannelNumber
range|:
literal|4
decl_stmt|;
block|}
name|IPMI_FRU_DATA_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|RecordId
decl_stmt|;
comment|// 1
name|UINT8
name|Version
decl_stmt|;
comment|// 3
name|UINT8
name|RecordType
decl_stmt|;
comment|// 4
name|UINT8
name|RecordLength
decl_stmt|;
comment|// 5
name|IPMI_FRU_DATA_INFO
name|FruDeviceData
decl_stmt|;
comment|// 6
name|UINT8
name|Reserved1
decl_stmt|;
comment|// 10
name|UINT8
name|DeviceType
decl_stmt|;
comment|// 11
name|UINT8
name|DeviceTypeModifier
decl_stmt|;
comment|// 12
name|UINT8
name|FruEntityId
decl_stmt|;
comment|// 13
name|UINT8
name|FruEntityInstance
decl_stmt|;
comment|// 14
name|UINT8
name|OemReserved
decl_stmt|;
comment|// 15
name|UINT8
name|Length
range|:
literal|4
decl_stmt|;
comment|// 16
name|UINT8
name|Reserved2
range|:
literal|1
decl_stmt|;
comment|// 16
name|UINT8
name|StringType
range|:
literal|3
decl_stmt|;
comment|// 16
name|UINT8
name|String
index|[
literal|16
index|]
decl_stmt|;
comment|// 17
block|}
name|IPMI_SDR_RECORD_STRUCT_11
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|NextRecordId
decl_stmt|;
comment|//1
name|UINT16
name|RecordId
decl_stmt|;
comment|//3
name|UINT8
name|Version
decl_stmt|;
comment|//5
name|UINT8
name|RecordType
decl_stmt|;
comment|//6
name|UINT8
name|RecordLength
decl_stmt|;
comment|//7
name|UINT8
name|ManufacturerId
index|[
literal|3
index|]
decl_stmt|;
comment|//8
name|UINT8
name|StringChars
index|[
literal|20
index|]
decl_stmt|;
block|}
name|IPMI_SDR_RECORD_STRUCT_C0
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|NextRecordId
decl_stmt|;
comment|//1
name|UINT16
name|RecordId
decl_stmt|;
comment|//3
name|UINT8
name|Version
decl_stmt|;
comment|//5
name|UINT8
name|RecordType
decl_stmt|;
comment|//6
name|UINT8
name|RecordLength
decl_stmt|;
comment|//7
block|}
name|IPMI_SDR_RECORD_STRUCT_HEADER
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|IPMI_SDR_RECORD_STRUCT_1
name|SensorType1
decl_stmt|;
name|IPMI_SDR_RECORD_STRUCT_2
name|SensorType2
decl_stmt|;
name|IPMI_SDR_RECORD_STRUCT_11
name|SensorType11
decl_stmt|;
name|IPMI_SDR_RECORD_STRUCT_C0
name|SensorTypeC0
decl_stmt|;
name|IPMI_SDR_RECORD_STRUCT_HEADER
name|SensorHeader
decl_stmt|;
block|}
name|IPMI_SENSOR_RECORD_STRUCT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|ReservationId
decl_stmt|;
name|UINT16
name|RecordId
decl_stmt|;
name|UINT8
name|RecordOffset
decl_stmt|;
name|UINT8
name|BytesToRead
decl_stmt|;
block|}
name|IPMI_GET_SDR_REQUEST
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Add SDR command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_STORAGE_ADD_SDR
value|0x24
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Add SDR" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Partial Add SDR command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_STORAGE_PARTIAL_ADD_SDR
value|0x25
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Partial Add SDR" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Delete SDR command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_STORAGE_DELETE_SDR
value|0x26
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Delete SDR" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Clear SDR Repository command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_STORAGE_CLEAR_SDR
value|0x27
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Clear SDR Repository" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get SDR Repository Time command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_STORAGE_GET_SDR_REPOSITORY_TIME
value|0x28
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get SDR Repository Time" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Set SDR Repository Time command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_STORAGE_SET_SDR_REPOSITORY_TIME
value|0x29
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Set SDR Repository Time" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Enter SDR Repository Update Mode command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_STORAGE_ENTER_SDR_UPDATE_MODE
value|0x2A
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Enter SDR Repository Update Mode" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Exit SDR Repository Update Mode command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_STORAGE_EXIT_SDR_UPDATE_MODE
value|0x2B
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Exit SDR Repository Update Mode" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Run Initialize Agent command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_STORAGE_RUN_INIT_AGENT
value|0x2C
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Run Initialize Agent" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Below is Definitions for System Event Log(SEL) Commands (Chapter 31)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get SEL Info command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_STORAGE_GET_SEL_INFO
value|0x40
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get SEL Info" command to follow here
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
name|Version
decl_stmt|;
comment|// Version of SEL
name|UINT16
name|NoOfEntries
decl_stmt|;
comment|// No of Entries in the SEL
name|UINT16
name|FreeSpace
decl_stmt|;
comment|// Free space in Bytes
name|UINT32
name|RecentAddTimeStamp
decl_stmt|;
comment|// Most Recent Addition of Time Stamp
name|UINT32
name|RecentEraseTimeStamp
decl_stmt|;
comment|// Most Recent Erasure of Time Stamp
name|UINT8
name|OperationSupport
decl_stmt|;
comment|// Operation Support
block|}
name|IPMI_GET_SEL_INFO_RESPONSE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get SEL Allocation Info command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_STORAGE_GET_SEL_ALLOCATION_INFO
value|0x41
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get SEL Allocation Info" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Reserve SEL command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_STORAGE_RESERVE_SEL
value|0x42
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Reserve SEL" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get SEL Entry command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_STORAGE_GET_SEL_ENTRY
value|0x43
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get SEL Entry" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|ReserveId
index|[
literal|2
index|]
decl_stmt|;
comment|// Reservation ID, LS Byte First
name|UINT8
name|SelRecID
index|[
literal|2
index|]
decl_stmt|;
comment|// Sel Record ID, LS Byte First
name|UINT8
name|Offset
decl_stmt|;
comment|// Offset Into Record
name|UINT8
name|BytesToRead
decl_stmt|;
comment|// Bytes to be Read, 0xFF for entire record
block|}
name|IPMI_GET_SEL_ENTRY_REQUEST
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Add SEL Entry command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_STORAGE_ADD_SEL_ENTRY
value|0x44
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Add SEL Entry" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Partial Add SEL Entry command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_STORAGE_PARTIAL_ADD_SEL_ENTRY
value|0x45
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Partial Add SEL Entry" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Delete SEL Entry command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_STORAGE_DELETE_SEL_ENTRY
value|0x46
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Delete SEL Entry" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|ReserveId
index|[
literal|2
index|]
decl_stmt|;
comment|// Reservation ID, LS byte first
name|UINT8
name|RecordToDelete
index|[
literal|2
index|]
decl_stmt|;
comment|// Record to Delete, LS Byte First
block|}
name|IPMI_DELETE_SEL_REQUEST
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Clear SEL command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_STORAGE_CLEAR_SEL
value|0x47
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Clear SEL" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Reserve
index|[
literal|2
index|]
decl_stmt|;
comment|// Reserve ID, LSB first
name|UINT8
name|AscC
decl_stmt|;
comment|// Ascii for 'C' (0x43)
name|UINT8
name|AscL
decl_stmt|;
comment|// Ascii for 'L' (0x4c)
name|UINT8
name|AscR
decl_stmt|;
comment|// Ascii for 'R' (0x52)
name|UINT8
name|Erase
decl_stmt|;
comment|// 0xAA, Initiate Erase, 0x00 Get Erase Status
block|}
name|IPMI_CLEAR_SEL_REQUEST
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get SEL Time command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_STORAGE_GET_SEL_TIME
value|0x48
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get SEL Time" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Set SEL Time command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_STORAGE_SET_SEL_TIME
value|0x49
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Set SEL Time" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Get Auxillary Log Status command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_STORAGE_GET_AUXILLARY_LOG_STATUS
value|0x5A
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Get Auxillary Log Status" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Set Auxillary Log Status command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_STORAGE_SET_AUXILLARY_LOG_STATUS
value|0x5B
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Constants and Structure definitions for "Set Auxillary Log Status" command to follow here
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_COMPLETE_SEL_RECORD
value|0xFF
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Below is Definitions for SEL Record Formats (Chapter 32)
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|RecordId
decl_stmt|;
name|UINT8
name|RecordType
decl_stmt|;
name|UINT32
name|TimeStamp
decl_stmt|;
name|UINT16
name|GeneratorId
decl_stmt|;
name|UINT8
name|EvMRevision
decl_stmt|;
name|UINT8
name|SensorType
decl_stmt|;
name|UINT8
name|SensorNumber
decl_stmt|;
name|UINT8
name|EventDirType
decl_stmt|;
name|UINT8
name|OEMEvData1
decl_stmt|;
name|UINT8
name|OEMEvData2
decl_stmt|;
name|UINT8
name|OEMEvData3
decl_stmt|;
block|}
name|IPMI_SEL_EVENT_RECORD_DATA
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IPMI_SEL_SYSTEM_RECORD
value|0x02
end_define

begin_define
define|#
directive|define
name|IPMI_EVM_REVISION
value|0x04
end_define

begin_define
define|#
directive|define
name|IPMI_BIOS_ID
value|0x18
end_define

begin_define
define|#
directive|define
name|IPMI_FORMAT_REV
value|0x00
end_define

begin_define
define|#
directive|define
name|IPMI_FORMAT_REV1
value|0x01
end_define

begin_define
define|#
directive|define
name|IPMI_SOFTWARE_ID
value|0x01
end_define

begin_define
define|#
directive|define
name|IPMI_PLATFORM_VAL_ID
value|0x01
end_define

begin_define
define|#
directive|define
name|IPMI_GENERATOR_ID
parameter_list|(
name|i
parameter_list|,
name|f
parameter_list|)
value|((i<< 1) | (f<< 1) | IPMI_SOFTWARE_ID)
end_define

begin_define
define|#
directive|define
name|IPMI_SENSOR_TYPE_EVENT_CODE_DISCRETE
value|0x6F
end_define

begin_define
define|#
directive|define
name|IPMI_OEM_SPECIFIC_DATA
value|0x02
end_define

begin_define
define|#
directive|define
name|IPMI_SENSOR_SPECIFIC_DATA
value|0x03
end_define

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

