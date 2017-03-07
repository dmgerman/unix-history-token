begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   TCG EFI Platform Definition in TCG_EFI_Platform_1_20_Final    Copyright (c) 2006 - 2017, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__UEFI_TCG_PLATFORM_H__
end_ifndef

begin_define
define|#
directive|define
name|__UEFI_TCG_PLATFORM_H__
end_define

begin_include
include|#
directive|include
file|<IndustryStandard/Tpm12.h>
end_include

begin_include
include|#
directive|include
file|<IndustryStandard/Tpm20.h>
end_include

begin_include
include|#
directive|include
file|<Uefi.h>
end_include

begin_comment
comment|//
end_comment

begin_comment
comment|// Standard event types
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EV_POST_CODE
value|((TCG_EVENTTYPE) 0x00000001)
end_define

begin_define
define|#
directive|define
name|EV_NO_ACTION
value|((TCG_EVENTTYPE) 0x00000003)
end_define

begin_define
define|#
directive|define
name|EV_SEPARATOR
value|((TCG_EVENTTYPE) 0x00000004)
end_define

begin_define
define|#
directive|define
name|EV_S_CRTM_CONTENTS
value|((TCG_EVENTTYPE) 0x00000007)
end_define

begin_define
define|#
directive|define
name|EV_S_CRTM_VERSION
value|((TCG_EVENTTYPE) 0x00000008)
end_define

begin_define
define|#
directive|define
name|EV_CPU_MICROCODE
value|((TCG_EVENTTYPE) 0x00000009)
end_define

begin_define
define|#
directive|define
name|EV_TABLE_OF_DEVICES
value|((TCG_EVENTTYPE) 0x0000000B)
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// EFI specific event types
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EV_EFI_EVENT_BASE
value|((TCG_EVENTTYPE) 0x80000000)
end_define

begin_define
define|#
directive|define
name|EV_EFI_VARIABLE_DRIVER_CONFIG
value|(EV_EFI_EVENT_BASE + 1)
end_define

begin_define
define|#
directive|define
name|EV_EFI_VARIABLE_BOOT
value|(EV_EFI_EVENT_BASE + 2)
end_define

begin_define
define|#
directive|define
name|EV_EFI_BOOT_SERVICES_APPLICATION
value|(EV_EFI_EVENT_BASE + 3)
end_define

begin_define
define|#
directive|define
name|EV_EFI_BOOT_SERVICES_DRIVER
value|(EV_EFI_EVENT_BASE + 4)
end_define

begin_define
define|#
directive|define
name|EV_EFI_RUNTIME_SERVICES_DRIVER
value|(EV_EFI_EVENT_BASE + 5)
end_define

begin_define
define|#
directive|define
name|EV_EFI_GPT_EVENT
value|(EV_EFI_EVENT_BASE + 6)
end_define

begin_define
define|#
directive|define
name|EV_EFI_ACTION
value|(EV_EFI_EVENT_BASE + 7)
end_define

begin_define
define|#
directive|define
name|EV_EFI_PLATFORM_FIRMWARE_BLOB
value|(EV_EFI_EVENT_BASE + 8)
end_define

begin_define
define|#
directive|define
name|EV_EFI_HANDOFF_TABLES
value|(EV_EFI_EVENT_BASE + 9)
end_define

begin_define
define|#
directive|define
name|EV_EFI_VARIABLE_AUTHORITY
value|(EV_EFI_EVENT_BASE + 0xE0)
end_define

begin_define
define|#
directive|define
name|EFI_CALLING_EFI_APPLICATION
define|\
value|"Calling EFI Application from Boot Option"
end_define

begin_define
define|#
directive|define
name|EFI_RETURNING_FROM_EFI_APPLICATOIN
define|\
value|"Returning from EFI Application from Boot Option"
end_define

begin_define
define|#
directive|define
name|EFI_EXIT_BOOT_SERVICES_INVOCATION
define|\
value|"Exit Boot Services Invocation"
end_define

begin_define
define|#
directive|define
name|EFI_EXIT_BOOT_SERVICES_FAILED
define|\
value|"Exit Boot Services Returned with Failure"
end_define

begin_define
define|#
directive|define
name|EFI_EXIT_BOOT_SERVICES_SUCCEEDED
define|\
value|"Exit Boot Services Returned with Success"
end_define

begin_define
define|#
directive|define
name|EV_POSTCODE_INFO_POST_CODE
value|"POST CODE"
end_define

begin_define
define|#
directive|define
name|POST_CODE_STR_LEN
value|(sizeof(EV_POSTCODE_INFO_POST_CODE) - 1)
end_define

begin_define
define|#
directive|define
name|EV_POSTCODE_INFO_SMM_CODE
value|"SMM CODE"
end_define

begin_define
define|#
directive|define
name|SMM_CODE_STR_LEN
value|(sizeof(EV_POSTCODE_INFO_SMM_CODE) - 1)
end_define

begin_define
define|#
directive|define
name|EV_POSTCODE_INFO_ACPI_DATA
value|"ACPI DATA"
end_define

begin_define
define|#
directive|define
name|ACPI_DATA_LEN
value|(sizeof(EV_POSTCODE_INFO_ACPI_DATA) - 1)
end_define

begin_define
define|#
directive|define
name|EV_POSTCODE_INFO_BIS_CODE
value|"BIS CODE"
end_define

begin_define
define|#
directive|define
name|BIS_CODE_LEN
value|(sizeof(EV_POSTCODE_INFO_BIS_CODE) - 1)
end_define

begin_define
define|#
directive|define
name|EV_POSTCODE_INFO_UEFI_PI
value|"UEFI PI"
end_define

begin_define
define|#
directive|define
name|UEFI_PI_LEN
value|(sizeof(EV_POSTCODE_INFO_UEFI_PI) - 1)
end_define

begin_define
define|#
directive|define
name|EV_POSTCODE_INFO_OPROM
value|"Embedded Option ROM"
end_define

begin_define
define|#
directive|define
name|OPROM_LEN
value|(sizeof(EV_POSTCODE_INFO_OPROM) - 1)
end_define

begin_define
define|#
directive|define
name|FIRMWARE_DEBUGGER_EVENT_STRING
value|"UEFI Debug Mode"
end_define

begin_define
define|#
directive|define
name|FIRMWARE_DEBUGGER_EVENT_STRING_LEN
value|(sizeof(FIRMWARE_DEBUGGER_EVENT_STRING) - 1)
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Set structure alignment to 1-byte
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

begin_typedef
typedef|typedef
name|UINT32
name|TCG_EVENTTYPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|TPM_PCRINDEX
name|TCG_PCRINDEX
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|TPM_DIGEST
name|TCG_DIGEST
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Event Log Entry Structure Definition
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTCG_PCR_EVENT
block|{
name|TCG_PCRINDEX
name|PCRIndex
decl_stmt|;
comment|///< PCRIndex event extended to
name|TCG_EVENTTYPE
name|EventType
decl_stmt|;
comment|///< TCG EFI event type
name|TCG_DIGEST
name|Digest
decl_stmt|;
comment|///< Value extended into PCRIndex
name|UINT32
name|EventSize
decl_stmt|;
comment|///< Size of the event data
name|UINT8
name|Event
index|[
literal|1
index|]
decl_stmt|;
comment|///< The event data
block|}
name|TCG_PCR_EVENT
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TSS_EVENT_DATA_MAX_SIZE
value|256
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// TCG_PCR_EVENT_HDR
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTCG_PCR_EVENT_HDR
block|{
name|TCG_PCRINDEX
name|PCRIndex
decl_stmt|;
name|TCG_EVENTTYPE
name|EventType
decl_stmt|;
name|TCG_DIGEST
name|Digest
decl_stmt|;
name|UINT32
name|EventSize
decl_stmt|;
block|}
name|TCG_PCR_EVENT_HDR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_PLATFORM_FIRMWARE_BLOB
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// BlobLength should be of type UINTN but we use UINT64 here
end_comment

begin_comment
comment|/// because PEI is 32-bit while DXE is 64-bit on x64 platforms
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdEFI_PLATFORM_FIRMWARE_BLOB
block|{
name|EFI_PHYSICAL_ADDRESS
name|BlobBase
decl_stmt|;
name|UINT64
name|BlobLength
decl_stmt|;
block|}
name|EFI_PLATFORM_FIRMWARE_BLOB
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_IMAGE_LOAD_EVENT
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure is used in EV_EFI_BOOT_SERVICES_APPLICATION,
end_comment

begin_comment
comment|/// EV_EFI_BOOT_SERVICES_DRIVER and EV_EFI_RUNTIME_SERVICES_DRIVER
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdEFI_IMAGE_LOAD_EVENT
block|{
name|EFI_PHYSICAL_ADDRESS
name|ImageLocationInMemory
decl_stmt|;
name|UINTN
name|ImageLengthInMemory
decl_stmt|;
name|UINTN
name|ImageLinkTimeAddress
decl_stmt|;
name|UINTN
name|LengthOfDevicePath
decl_stmt|;
name|EFI_DEVICE_PATH_PROTOCOL
name|DevicePath
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_IMAGE_LOAD_EVENT
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_HANDOFF_TABLE_POINTERS
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure is used in EV_EFI_HANDOFF_TABLES event to facilitate
end_comment

begin_comment
comment|/// the measurement of given configuration tables.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdEFI_HANDOFF_TABLE_POINTERS
block|{
name|UINTN
name|NumberOfTables
decl_stmt|;
name|EFI_CONFIGURATION_TABLE
name|TableEntry
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_HANDOFF_TABLE_POINTERS
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_VARIABLE_DATA
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure serves as the header for measuring variables. The name of the
end_comment

begin_comment
comment|/// variable (in Unicode format) should immediately follow, then the variable
end_comment

begin_comment
comment|/// data.
end_comment

begin_comment
comment|/// This is defined in TCG EFI Platform Spec for TPM1.1 or 1.2 V1.22
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdEFI_VARIABLE_DATA
block|{
name|EFI_GUID
name|VariableName
decl_stmt|;
name|UINTN
name|UnicodeNameLength
decl_stmt|;
name|UINTN
name|VariableDataLength
decl_stmt|;
name|CHAR16
name|UnicodeName
index|[
literal|1
index|]
decl_stmt|;
name|INT8
name|VariableData
index|[
literal|1
index|]
decl_stmt|;
comment|///< Driver or platform-specific data
block|}
name|EFI_VARIABLE_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// UEFI_VARIABLE_DATA
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure serves as the header for measuring variables. The name of the
end_comment

begin_comment
comment|/// variable (in Unicode format) should immediately follow, then the variable
end_comment

begin_comment
comment|/// data.
end_comment

begin_comment
comment|/// This is defined in TCG PC Client Firmware Profile Spec 00.21
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdUEFI_VARIABLE_DATA
block|{
name|EFI_GUID
name|VariableName
decl_stmt|;
name|UINT64
name|UnicodeNameLength
decl_stmt|;
name|UINT64
name|VariableDataLength
decl_stmt|;
name|CHAR16
name|UnicodeName
index|[
literal|1
index|]
decl_stmt|;
name|INT8
name|VariableData
index|[
literal|1
index|]
decl_stmt|;
comment|///< Driver or platform-specific data
block|}
name|UEFI_VARIABLE_DATA
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// For TrEE1.0 compatibility
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_GUID
name|VariableName
decl_stmt|;
name|UINT64
name|UnicodeNameLength
decl_stmt|;
comment|// The TCG Definition used UINTN
name|UINT64
name|VariableDataLength
decl_stmt|;
comment|// The TCG Definition used UINTN
name|CHAR16
name|UnicodeName
index|[
literal|1
index|]
decl_stmt|;
name|INT8
name|VariableData
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_VARIABLE_DATA_TREE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tdEFI_GPT_DATA
block|{
name|EFI_PARTITION_TABLE_HEADER
name|EfiPartitionHeader
decl_stmt|;
name|UINTN
name|NumberOfPartitions
decl_stmt|;
name|EFI_PARTITION_ENTRY
name|Partitions
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_GPT_DATA
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Crypto Agile Log Entry Format
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTCG_PCR_EVENT2
block|{
name|TCG_PCRINDEX
name|PCRIndex
decl_stmt|;
name|TCG_EVENTTYPE
name|EventType
decl_stmt|;
name|TPML_DIGEST_VALUES
name|Digest
decl_stmt|;
name|UINT32
name|EventSize
decl_stmt|;
name|UINT8
name|Event
index|[
literal|1
index|]
decl_stmt|;
block|}
name|TCG_PCR_EVENT2
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// TCG PCR Event2 Header
end_comment

begin_comment
comment|// Follow TCG EFI Protocol Spec 5.2 Crypto Agile Log Entry Format
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTCG_PCR_EVENT2_HDR
block|{
name|TCG_PCRINDEX
name|PCRIndex
decl_stmt|;
name|TCG_EVENTTYPE
name|EventType
decl_stmt|;
name|TPML_DIGEST_VALUES
name|Digests
decl_stmt|;
name|UINT32
name|EventSize
decl_stmt|;
block|}
name|TCG_PCR_EVENT2_HDR
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Log Header Entry Data
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// TCG defined hashing algorithm ID.
comment|//
name|UINT16
name|algorithmId
decl_stmt|;
comment|//
comment|// The size of the digest for the respective hashing algorithm.
comment|//
name|UINT16
name|digestSize
decl_stmt|;
block|}
name|TCG_EfiSpecIdEventAlgorithmSize
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TCG_EfiSpecIDEventStruct_SIGNATURE_02
value|"Spec ID Event02"
end_define

begin_define
define|#
directive|define
name|TCG_EfiSpecIDEventStruct_SIGNATURE_03
value|"Spec ID Event03"
end_define

begin_define
define|#
directive|define
name|TCG_EfiSpecIDEventStruct_SPEC_VERSION_MAJOR_TPM12
value|1
end_define

begin_define
define|#
directive|define
name|TCG_EfiSpecIDEventStruct_SPEC_VERSION_MINOR_TPM12
value|2
end_define

begin_define
define|#
directive|define
name|TCG_EfiSpecIDEventStruct_SPEC_ERRATA_TPM12
value|2
end_define

begin_define
define|#
directive|define
name|TCG_EfiSpecIDEventStruct_SPEC_VERSION_MAJOR_TPM2
value|2
end_define

begin_define
define|#
directive|define
name|TCG_EfiSpecIDEventStruct_SPEC_VERSION_MINOR_TPM2
value|0
end_define

begin_define
define|#
directive|define
name|TCG_EfiSpecIDEventStruct_SPEC_ERRATA_TPM2
value|0
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|signature
index|[
literal|16
index|]
decl_stmt|;
comment|//
comment|// The value for the Platform Class.
comment|// The enumeration is defined in the TCG ACPI Specification Client Common Header.
comment|//
name|UINT32
name|platformClass
decl_stmt|;
comment|//
comment|// The TCG EFI Platform Specification minor version number this BIOS supports.
comment|// Any BIOS supporting version (1.22) MUST set this value to 02h.
comment|// Any BIOS supporting version (2.0) SHALL set this value to 0x00.
comment|//
name|UINT8
name|specVersionMinor
decl_stmt|;
comment|//
comment|// The TCG EFI Platform Specification major version number this BIOS supports.
comment|// Any BIOS supporting version (1.22) MUST set this value to 01h.
comment|// Any BIOS supporting version (2.0) SHALL set this value to 0x02.
comment|//
name|UINT8
name|specVersionMajor
decl_stmt|;
comment|//
comment|// The TCG EFI Platform Specification errata for this specification this BIOS supports.
comment|// Any BIOS supporting version and errata (1.22) MUST set this value to 02h.
comment|// Any BIOS supporting version and errata (2.0) SHALL set this value to 0x00.
comment|//
name|UINT8
name|specErrata
decl_stmt|;
comment|//
comment|// Specifies the size of the UINTN fields used in various data structures used in this specification.
comment|// 0x01 indicates UINT32 and 0x02 indicates UINT64.
comment|//
name|UINT8
name|uintnSize
decl_stmt|;
comment|//
comment|// This field is added in "Spec ID Event03".
comment|// The number of hashing algorithms used in this event log (except the first event).
comment|// All events in this event log use all hashing algorithms defined here.
comment|//
comment|//UINT32              numberOfAlgorithms;
comment|//
comment|// This field is added in "Spec ID Event03".
comment|// An array of size numberOfAlgorithms of value pairs.
comment|//
comment|//TCG_EfiSpecIdEventAlgorithmSize digestSize[numberOfAlgorithms];
comment|//
comment|// Size in bytes of the VendorInfo field.
comment|// Maximum value SHALL be FFh bytes.
comment|//
comment|//UINT8               vendorInfoSize;
comment|//
comment|// Provided for use by the BIOS implementer.
comment|// The value might be used, for example, to provide more detailed information about the specific BIOS such as BIOS revision numbers, etc.
comment|// The values within this field are not standardized and are implementer-specific.
comment|// Platform-specific or -unique information SHALL NOT be provided in this field.
comment|//
comment|//UINT8               vendorInfo[vendorInfoSize];
block|}
name|TCG_EfiSpecIDEventStruct
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TCG_EfiStartupLocalityEvent_SIGNATURE
value|"StartupLocality"
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// PC Client PTP spec Table 8 Relationship between Locality and Locality Attribute
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|LOCALITY_0_INDICATOR
value|0x01
end_define

begin_define
define|#
directive|define
name|LOCALITY_1_INDICATOR
value|0x02
end_define

begin_define
define|#
directive|define
name|LOCALITY_2_INDICATOR
value|0x03
end_define

begin_define
define|#
directive|define
name|LOCALITY_3_INDICATOR
value|0x04
end_define

begin_define
define|#
directive|define
name|LOCALITY_4_INDICATOR
value|0x05
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Startup Locality Event
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdTCG_EfiStartupLocalityEvent
block|{
name|UINT8
name|Signature
index|[
literal|16
index|]
decl_stmt|;
comment|//
comment|// The Locality Indicator which sent the TPM2_Startup command
comment|//
name|UINT8
name|StartupLocality
decl_stmt|;
block|}
name|TCG_EfiStartupLocalityEvent
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Restore original structure alignment
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

