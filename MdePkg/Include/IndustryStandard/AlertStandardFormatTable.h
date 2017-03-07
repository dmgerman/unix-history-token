begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file      ACPI Alert Standard Format Description Table ASF! as described in the ASF2.0 Specification    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.              **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALERT_STANDARD_FORMAT_TABLE_H_
end_ifndef

begin_define
define|#
directive|define
name|_ALERT_STANDARD_FORMAT_TABLE_H_
end_define

begin_include
include|#
directive|include
file|<IndustryStandard/Acpi.h>
end_include

begin_comment
comment|//
end_comment

begin_comment
comment|// Ensure proper structure formats
end_comment

begin_comment
comment|//
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_comment
comment|///
end_comment

begin_comment
comment|/// Information Record header that appears at the beginning of each record
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Type
decl_stmt|;
name|UINT8
name|Reserved
decl_stmt|;
name|UINT16
name|RecordLength
decl_stmt|;
block|}
name|EFI_ACPI_ASF_RECORD_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure contains information that identifies the system's type
end_comment

begin_comment
comment|/// and configuration
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_ACPI_ASF_RECORD_HEADER
name|RecordHeader
decl_stmt|;
name|UINT8
name|MinWatchDogResetValue
decl_stmt|;
name|UINT8
name|MinPollingInterval
decl_stmt|;
name|UINT16
name|SystemID
decl_stmt|;
name|UINT32
name|IANAManufactureID
decl_stmt|;
name|UINT8
name|FeatureFlags
decl_stmt|;
name|UINT8
name|Reserved
index|[
literal|3
index|]
decl_stmt|;
block|}
name|EFI_ACPI_ASF_INFO
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// ASF Alert Data
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|DeviceAddress
decl_stmt|;
name|UINT8
name|Command
decl_stmt|;
name|UINT8
name|DataMask
decl_stmt|;
name|UINT8
name|CompareValue
decl_stmt|;
name|UINT8
name|EventSenseType
decl_stmt|;
name|UINT8
name|EventType
decl_stmt|;
name|UINT8
name|EventOffset
decl_stmt|;
name|UINT8
name|EventSourceType
decl_stmt|;
name|UINT8
name|EventSeverity
decl_stmt|;
name|UINT8
name|SensorNumber
decl_stmt|;
name|UINT8
name|Entity
decl_stmt|;
name|UINT8
name|EntityInstance
decl_stmt|;
block|}
name|EFI_ACPI_ASF_ALERTDATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Alert sensors definition
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_ACPI_ASF_RECORD_HEADER
name|RecordHeader
decl_stmt|;
name|UINT8
name|AssertionEventBitMask
decl_stmt|;
name|UINT8
name|DeassertionEventBitMask
decl_stmt|;
name|UINT8
name|NumberOfAlerts
decl_stmt|;
name|UINT8
name|ArrayElementLength
decl_stmt|;
comment|///< For ASF version 1.0 and later, this filed is set to 0x0C
comment|///
comment|/// EFI_ACPI_ASF_ALERTDATA           DeviceArray[ANYSIZE_ARRAY];
comment|///
block|}
name|EFI_ACPI_ASF_ALRT
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Alert Control Data
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Function
decl_stmt|;
name|UINT8
name|DeviceAddress
decl_stmt|;
name|UINT8
name|Command
decl_stmt|;
name|UINT8
name|DataValue
decl_stmt|;
block|}
name|EFI_ACPI_ASF_CONTROLDATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Alert Remote Control System Actions
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_ACPI_ASF_RECORD_HEADER
name|RecordHeader
decl_stmt|;
name|UINT8
name|NumberOfControls
decl_stmt|;
name|UINT8
name|ArrayElementLength
decl_stmt|;
comment|///< For ASF version 1.0 and later, this filed is set to 0x4
name|UINT16
name|RctlReserved
decl_stmt|;
comment|///
comment|/// EFI_ACPI_ASF_CONTROLDATA;        DeviceArray[ANYSIZE_ARRAY];
comment|///
block|}
name|EFI_ACPI_ASF_RCTL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Remote Control Capabilities
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_ACPI_ASF_RECORD_HEADER
name|RecordHeader
decl_stmt|;
name|UINT8
name|RemoteControlCapabilities
index|[
literal|7
index|]
decl_stmt|;
name|UINT8
name|RMCPCompletionCode
decl_stmt|;
name|UINT32
name|RMCPIANA
decl_stmt|;
name|UINT8
name|RMCPSpecialCommand
decl_stmt|;
name|UINT8
name|RMCPSpecialCommandParameter
index|[
literal|2
index|]
decl_stmt|;
name|UINT8
name|RMCPBootOptions
index|[
literal|2
index|]
decl_stmt|;
name|UINT8
name|RMCPOEMParameters
index|[
literal|2
index|]
decl_stmt|;
block|}
name|EFI_ACPI_ASF_RMCP
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// SMBus Devices with fixed addresses
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_ACPI_ASF_RECORD_HEADER
name|RecordHeader
decl_stmt|;
name|UINT8
name|SEEPROMAddress
decl_stmt|;
name|UINT8
name|NumberOfDevices
decl_stmt|;
comment|///
comment|/// UINT8                            FixedSmbusAddresses[ANYSIZE_ARRAY];
comment|///
block|}
name|EFI_ACPI_ASF_ADDR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// ASF! Description Table Header
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|EFI_ACPI_DESCRIPTION_HEADER
name|EFI_ACPI_ASF_DESCRIPTION_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The revision stored in ASF! DESCRIPTION TABLE as BCD value
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_2_0_ASF_DESCRIPTION_TABLE_REVISION
value|0x20
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// "ASF!" ASF Description Table Signature
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ACPI_ASF_DESCRIPTION_TABLE_SIGNATURE
value|SIGNATURE_32 ('A', 'S', 'F', '!')
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

begin_comment
comment|// _ALERT_STANDARD_FORMAT_TABLE_H
end_comment

end_unit

