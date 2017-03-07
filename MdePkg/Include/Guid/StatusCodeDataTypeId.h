begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   GUID used to identify id for the caller who is initiating the Status Code.    Copyright (c) 2006 - 2013, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   These GUIDs and structures are defined in UEFI Platform Initialization Specification 1.2    Volume 3: Shared Architectural Elements  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PI_STATUS_CODE_DATA_TYPE_ID_GUID_H__
end_ifndef

begin_define
define|#
directive|define
name|__PI_STATUS_CODE_DATA_TYPE_ID_GUID_H__
end_define

begin_include
include|#
directive|include
file|<PiDxe.h>
end_include

begin_include
include|#
directive|include
file|<Protocol/DebugSupport.h>
end_include

begin_comment
comment|///
end_comment

begin_comment
comment|/// Global ID for the EFI_STATUS_CODE_STRING structure
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_STATUS_CODE_DATA_TYPE_STRING_GUID
define|\
value|{ 0x92D11080, 0x496F, 0x4D95, { 0xBE, 0x7E, 0x03, 0x74, 0x88, 0x38, 0x2B, 0x0A } }
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// A NULL-terminated ASCII string.
comment|///
name|EfiStringAscii
block|,
comment|///
comment|/// A double NULL-terminated Unicode string.
comment|///
name|EfiStringUnicode
block|,
comment|///
comment|/// An EFI_STATUS_CODE_STRING_TOKEN representing the string.  The actual
comment|/// string can be obtained by querying the HII Database
comment|///
name|EfiStringToken
block|}
name|EFI_STRING_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Specifies the format of the data in EFI_STATUS_CODE_STRING_DATA.String.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The HII package list which contains the string.  Handle is a dynamic value that may
comment|/// not be the same for different boots.  Type EFI_HII_HANDLE is defined in
comment|/// EFI_HII_DATABASE_PROTOCOL.NewPackageList() in the UEFI Specification.
comment|///
name|EFI_HII_HANDLE
name|Handle
decl_stmt|;
comment|///
comment|/// When combined with Handle, the string token can be used to retrieve the string.
comment|/// Type EFI_STRING_ID is defined in EFI_IFR_OP_HEADER in the UEFI Specification.
comment|///
name|EFI_STRING_ID
name|Token
decl_stmt|;
block|}
name|EFI_STATUS_CODE_STRING_TOKEN
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
comment|///
comment|/// ASCII formatted string.
comment|///
name|CHAR8
modifier|*
name|Ascii
decl_stmt|;
comment|///
comment|/// Unicode formatted string.
comment|///
name|CHAR16
modifier|*
name|Unicode
decl_stmt|;
comment|///
comment|/// HII handle/token pair.
comment|///
name|EFI_STATUS_CODE_STRING_TOKEN
name|Hii
decl_stmt|;
block|}
name|EFI_STATUS_CODE_STRING
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This data type defines a string type of extended data. A string can accompany
end_comment

begin_comment
comment|/// any status code. The string can provide additional information about the
end_comment

begin_comment
comment|/// status code. The string can be ASCII, Unicode, or a Human Interface Infrastructure
end_comment

begin_comment
comment|/// (HII) token/GUID pair.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The data header identifying the data. DataHeader.HeaderSize should be
comment|/// sizeof (EFI_STATUS_CODE_DATA), DataHeader.Size should be
comment|/// sizeof (EFI_STATUS_CODE_STRING_DATA) - HeaderSize, and
comment|/// DataHeader.Type should be
comment|/// EFI_STATUS_CODE_DATA_TYPE_STRING_GUID.
comment|///
name|EFI_STATUS_CODE_DATA
name|DataHeader
decl_stmt|;
comment|///
comment|/// Specifies the format of the data in String.
comment|///
name|EFI_STRING_TYPE
name|StringType
decl_stmt|;
comment|///
comment|/// A pointer to the extended data. The data follows the format specified by
comment|/// StringType.
comment|///
name|EFI_STATUS_CODE_STRING
name|String
decl_stmt|;
block|}
name|EFI_STATUS_CODE_STRING_DATA
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiStatusCodeDataTypeStringGuid
decl_stmt|;
end_decl_stmt

begin_comment
comment|///
end_comment

begin_comment
comment|/// Global ID for the following structures:
end_comment

begin_comment
comment|///   - EFI_DEVICE_PATH_EXTENDED_DATA
end_comment

begin_comment
comment|///   - EFI_DEVICE_HANDLE_EXTENDED_DATA
end_comment

begin_comment
comment|///   - EFI_RESOURCE_ALLOC_FAILURE_ERROR_DATA
end_comment

begin_comment
comment|///   - EFI_COMPUTING_UNIT_VOLTAGE_ERROR_DATA
end_comment

begin_comment
comment|///   - EFI_COMPUTING_UNIT_MICROCODE_UPDATE_ERROR_DATA
end_comment

begin_comment
comment|///   - EFI_COMPUTING_UNIT_TIMER_EXPIRED_ERROR_DATA
end_comment

begin_comment
comment|///   - EFI_HOST_PROCESSOR_MISMATCH_ERROR_DATA
end_comment

begin_comment
comment|///   - EFI_MEMORY_RANGE_EXTENDED_DATA
end_comment

begin_comment
comment|///   - EFI_DEBUG_ASSERT_DATA
end_comment

begin_comment
comment|///   - EFI_STATUS_CODE_EXCEP_EXTENDED_DATA
end_comment

begin_comment
comment|///   - EFI_STATUS_CODE_START_EXTENDED_DATA
end_comment

begin_comment
comment|///   - EFI_LEGACY_OPROM_EXTENDED_DATA
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_STATUS_CODE_SPECIFIC_DATA_GUID
define|\
value|{ 0x335984bd, 0xe805, 0x409a, { 0xb8, 0xf8, 0xd2, 0x7e, 0xce, 0x5f, 0xf7, 0xa6 } }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Extended data about the device path, which is used for many errors and
end_comment

begin_comment
comment|/// progress codes to point to the device.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The device path is used to point to the physical device in case there is more than one device
end_comment

begin_comment
comment|/// belonging to the same subclass. For example, the system may contain two USB keyboards and one
end_comment

begin_comment
comment|/// PS/2* keyboard. The driver that parses the status code can use the device path extended data to
end_comment

begin_comment
comment|/// differentiate between the three. The index field is not useful in this case because there is no standard
end_comment

begin_comment
comment|/// numbering convention. Device paths are preferred over using device handles because device handles
end_comment

begin_comment
comment|/// for a given device can change from one boot to another and do not mean anything beyond Boot
end_comment

begin_comment
comment|/// Services time. In certain cases, the bus driver may not create a device handle for a given device if it
end_comment

begin_comment
comment|/// detects a critical error. In these cases, the device path extended data can be used to refer to the
end_comment

begin_comment
comment|/// device, but there may not be any device handles with an instance of
end_comment

begin_comment
comment|/// EFI_DEVICE_PATH_PROTOCOL that matches DevicePath. The variable device path structure
end_comment

begin_comment
comment|/// is included in this structure to make it self sufficient.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The data header identifying the data. DataHeader.HeaderSize should be
comment|/// sizeof (EFI_STATUS_CODE_DATA). DataHeader.Size should be the size
comment|/// of variable-length DevicePath, and DataHeader.Size is zero for a virtual
comment|/// device that does not have a device path. DataHeader.Type should be
comment|/// EFI_STATUS_CODE_SPECIFIC_DATA_GUID.
comment|///
name|EFI_STATUS_CODE_DATA
name|DataHeader
decl_stmt|;
comment|///
comment|/// The device path to the controller or the hardware device. Note that this parameter is a
comment|/// variable-length device path structure and not a pointer to such a structure. This structure is
comment|/// populated only if it is a physical device. For virtual devices, the Size field in DataHeader
comment|/// is set to zero and this field is not populated.
comment|///
comment|//  EFI_DEVICE_PATH_PROTOCOL         DevicePath;
block|}
name|EFI_DEVICE_PATH_EXTENDED_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Device handle Extended Data. Used for many
end_comment

begin_comment
comment|/// errors and progress codes to point to the device.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The handle of the device with which the progress or error code is associated. The handle is
end_comment

begin_comment
comment|/// guaranteed to be accurate only at the time the status code is reported. Handles are dynamic entities
end_comment

begin_comment
comment|/// between boots, so handles cannot be considered to be valid if the system has reset subsequent to the
end_comment

begin_comment
comment|/// status code being reported. Handles may be used to determine a wide variety of useful information
end_comment

begin_comment
comment|/// about the source of the status code.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The data header identifying the data. DataHeader.HeaderSize should be
comment|/// sizeof (EFI_STATUS_CODE_DATA), DataHeader.Size should be
comment|/// sizeof (EFI_DEVICE_HANDLE_EXTENDED_DATA) - HeaderSize, and
comment|/// DataHeader.Type should be EFI_STATUS_CODE_SPECIFIC_DATA_GUID.
comment|///
name|EFI_STATUS_CODE_DATA
name|DataHeader
decl_stmt|;
comment|///
comment|/// The device handle.
comment|///
name|EFI_HANDLE
name|Handle
decl_stmt|;
block|}
name|EFI_DEVICE_HANDLE_EXTENDED_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure defines extended data describing a PCI resource allocation error.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @par Note:
end_comment

begin_comment
comment|///   The following structure contains variable-length fields and cannot be defined as a C-style
end_comment

begin_comment
comment|///   structure.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This extended data conveys details for a PCI resource allocation failure error. See the PCI
end_comment

begin_comment
comment|/// specification and the ACPI specification for details on PCI resource allocations and the format for
end_comment

begin_comment
comment|/// resource descriptors. This error does not detail why the resource allocation failed. It may be due to a
end_comment

begin_comment
comment|/// bad resource request or a lack of available resources to satisfy a valid request. The variable device
end_comment

begin_comment
comment|/// path structure and the resource structures are included in this structure to make it self sufficient.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The data header identifying the data. DataHeader.HeaderSize should be sizeof
comment|/// (EFI_STATUS_CODE_DATA), DataHeader.Size should be
comment|/// (DevicePathSize + DevicePathSize + DevicePathSize +
comment|/// sizeof(UINT32) + 3 * sizeof (UINT16) ), and DataHeader.Type
comment|/// should be EFI_STATUS_CODE_SPECIFIC_DATA_GUID.
comment|///
name|EFI_STATUS_CODE_DATA
name|DataHeader
decl_stmt|;
comment|///
comment|/// The PCI BAR. Applicable only for PCI devices. Ignored for all other devices.
comment|///
name|UINT32
name|Bar
decl_stmt|;
comment|///
comment|/// DevicePathSize should be zero if it is a virtual device that is not associated with
comment|/// a device path. Otherwise, this parameter is the length of the variable-length
comment|/// DevicePath.
comment|///
name|UINT16
name|DevicePathSize
decl_stmt|;
comment|///
comment|/// Represents the size the ReqRes parameter. ReqResSize should be zero if the
comment|/// requested resources are not provided as a part of extended data.
comment|///
name|UINT16
name|ReqResSize
decl_stmt|;
comment|///
comment|/// Represents the size the AllocRes parameter. AllocResSize should be zero if the
comment|/// allocated resources are not provided as a part of extended data.
comment|///
name|UINT16
name|AllocResSize
decl_stmt|;
comment|///
comment|/// The device path to the controller or the hardware device that did not get the requested
comment|/// resources. Note that this parameter is the variable-length device path structure and not
comment|/// a pointer to this structure.
comment|///
comment|//  EFI_DEVICE_PATH_PROTOCOL       DevicePath;
comment|///
comment|/// The requested resources in the format of an ACPI 2.0 resource descriptor. This
comment|/// parameter is not a pointer; it is the complete resource descriptor.
comment|///
comment|//  UINT8                          ReqRes[];
comment|///
comment|/// The allocated resources in the format of an ACPI 2.0 resource descriptor. This
comment|/// parameter is not a pointer; it is the complete resource descriptor.
comment|///
comment|//  UINT8                          AllocRes[];
block|}
name|EFI_RESOURCE_ALLOC_FAILURE_ERROR_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure provides a calculation for base-10 representations.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Not consistent with PI 1.2 Specification.
end_comment

begin_comment
comment|/// This data type is not defined in the PI 1.2 Specification, but is
end_comment

begin_comment
comment|/// required by several of the other data structures in this file.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The INT16 number by which to multiply the base-2 representation.
comment|///
name|INT16
name|Value
decl_stmt|;
comment|///
comment|/// The INT16 number by which to raise the base-2 calculation.
comment|///
name|INT16
name|Exponent
decl_stmt|;
block|}
name|EFI_EXP_BASE10_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure provides the voltage at the time of error. It also provides
end_comment

begin_comment
comment|/// the threshold value indicating the minimum or maximum voltage that is considered
end_comment

begin_comment
comment|/// an error. If the voltage is less then the threshold, the error indicates that the
end_comment

begin_comment
comment|/// voltage fell below the minimum acceptable value. If the voltage is greater then the threshold,
end_comment

begin_comment
comment|/// the error indicates that the voltage rose above the maximum acceptable value.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The data header identifying the data. DataHeader.HeaderSize should be
comment|/// sizeof (EFI_STATUS_CODE_DATA), DataHeader.Size should be
comment|/// sizeof (EFI_COMPUTING_UNIT_VOLTAGE_ERROR_DATA) -
comment|/// HeaderSize, and DataHeader.Type should be
comment|/// EFI_STATUS_CODE_SPECIFIC_DATA_GUID.
comment|///
name|EFI_STATUS_CODE_DATA
name|DataHeader
decl_stmt|;
comment|///
comment|/// The voltage value at the time of the error.
comment|///
name|EFI_EXP_BASE10_DATA
name|Voltage
decl_stmt|;
comment|///
comment|/// The voltage threshold.
comment|///
name|EFI_EXP_BASE10_DATA
name|Threshold
decl_stmt|;
block|}
name|EFI_COMPUTING_UNIT_VOLTAGE_ERROR_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Microcode Update Extended Error Data
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The data header identifying the data. DataHeader.HeaderSize should be
comment|/// sizeof (EFI_STATUS_CODE_DATA), DataHeader.Size should be
comment|/// sizeof (EFI_COMPUTING_UNIT_MICROCODE_UPDATE_ERROR_DATA) -
comment|/// HeaderSize, and DataHeader.Type should be
comment|/// EFI_STATUS_CODE_SPECIFIC_DATA_GUID.
comment|///
name|EFI_STATUS_CODE_DATA
name|DataHeader
decl_stmt|;
comment|///
comment|/// The version of the microcode update from the header.
comment|///
name|UINT32
name|Version
decl_stmt|;
block|}
name|EFI_COMPUTING_UNIT_MICROCODE_UPDATE_ERROR_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure provides details about the computing unit timer expiration error.
end_comment

begin_comment
comment|/// The timer limit provides the timeout value of the timer prior to expiration.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The data header identifying the data. DataHeader.HeaderSize should be
comment|/// sizeof (EFI_STATUS_CODE_DATA), DataHeader.Size should be
comment|/// sizeof (EFI_COMPUTING_UNIT_TIMER_EXPIRED_ERROR_DATA) -
comment|/// HeaderSize, and DataHeader.Type should be
comment|/// EFI_STATUS_CODE_SPECIFIC_DATA_GUID.
comment|///
name|EFI_STATUS_CODE_DATA
name|DataHeader
decl_stmt|;
comment|///
comment|/// The number of seconds that the computing unit timer was configured to expire.
comment|///
name|EFI_EXP_BASE10_DATA
name|TimerLimit
decl_stmt|;
block|}
name|EFI_COMPUTING_UNIT_TIMER_EXPIRED_ERROR_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Attribute bits for EFI_HOST_PROCESSOR_MISMATCH_ERROR_DATA.Attributes
end_comment

begin_comment
comment|/// All other attributes are reserved for future use and must be initialized to 0.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_COMPUTING_UNIT_MISMATCH_SPEED
value|0x0001
end_define

begin_define
define|#
directive|define
name|EFI_COMPUTING_UNIT_MISMATCH_FSB_SPEED
value|0x0002
end_define

begin_define
define|#
directive|define
name|EFI_COMPUTING_UNIT_MISMATCH_FAMILY
value|0x0004
end_define

begin_define
define|#
directive|define
name|EFI_COMPUTING_UNIT_MISMATCH_MODEL
value|0x0008
end_define

begin_define
define|#
directive|define
name|EFI_COMPUTING_UNIT_MISMATCH_STEPPING
value|0x0010
end_define

begin_define
define|#
directive|define
name|EFI_COMPUTING_UNIT_MISMATCH_CACHE_SIZE
value|0x0020
end_define

begin_define
define|#
directive|define
name|EFI_COMPUTING_UNIT_MISMATCH_OEM1
value|0x1000
end_define

begin_define
define|#
directive|define
name|EFI_COMPUTING_UNIT_MISMATCH_OEM2
value|0x2000
end_define

begin_define
define|#
directive|define
name|EFI_COMPUTING_UNIT_MISMATCH_OEM3
value|0x4000
end_define

begin_define
define|#
directive|define
name|EFI_COMPUTING_UNIT_MISMATCH_OEM4
value|0x8000
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure defines extended data for processor mismatch errors.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This provides information to indicate which processors mismatch, and how they mismatch. The
end_comment

begin_comment
comment|/// status code contains the instance number of the processor that is in error. This structure's
end_comment

begin_comment
comment|/// Instance indicates the second processor that does not match. This differentiation allows the
end_comment

begin_comment
comment|/// consumer to determine which two processors do not match. The Attributes indicate what
end_comment

begin_comment
comment|/// mismatch is being reported. Because Attributes is a bit field, more than one mismatch can be
end_comment

begin_comment
comment|/// reported with one error code.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The data header identifying the data. DataHeader.HeaderSize should be
comment|/// sizeof (EFI_STATUS_CODE_DATA), DataHeader.Size should be
comment|/// sizeof (EFI_ HOST_PROCESSOR_MISMATCH_ERROR_DATA) -
comment|/// HeaderSize , and DataHeader.Type should be
comment|/// EFI_STATUS_CODE_SPECIFIC_DATA_GUID.
comment|///
name|EFI_STATUS_CODE_DATA
name|DataHeader
decl_stmt|;
comment|///
comment|/// The unit number of the computing unit that does not match.
comment|///
name|UINT32
name|Instance
decl_stmt|;
comment|///
comment|/// The attributes describing the failure.
comment|///
name|UINT16
name|Attributes
decl_stmt|;
block|}
name|EFI_HOST_PROCESSOR_MISMATCH_ERROR_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure provides details about the computing unit thermal failure.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure provides the temperature at the time of error. It also provides the threshold value
end_comment

begin_comment
comment|/// indicating the minimum temperature that is considered an error.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The data header identifying the data. DataHeader.HeaderSize should be
comment|/// sizeof (EFI_STATUS_CODE_DATA), DataHeader.Size should be
comment|/// sizeof (EFI_COMPUTING_UNIT_THERMAL_ERROR_DATA) -
comment|/// HeaderSize , and DataHeader.Type should be
comment|/// EFI_STATUS_CODE_SPECIFIC_DATA_GUID.
comment|///
name|EFI_STATUS_CODE_DATA
name|DataHeader
decl_stmt|;
comment|///
comment|/// The thermal value at the time of the error.
comment|///
name|EFI_EXP_BASE10_DATA
name|Temperature
decl_stmt|;
comment|///
comment|/// The thermal threshold.
comment|///
name|EFI_EXP_BASE10_DATA
name|Threshold
decl_stmt|;
block|}
name|EFI_COMPUTING_UNIT_THERMAL_ERROR_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Enumeration of valid cache types
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|EfiInitCacheDataOnly
block|,
name|EfiInitCacheInstrOnly
block|,
name|EfiInitCacheBoth
block|,
name|EfiInitCacheUnspecified
block|}
name|EFI_INIT_CACHE_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Embedded cache init extended data
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The data header identifying the data. DataHeader.HeaderSize should be
comment|/// sizeof (EFI_STATUS_CODE_DATA), DataHeader.Size should be
comment|/// sizeof (EFI_CACHE_INIT_DATA) - HeaderSize , and
comment|/// DataHeader.Type should be EFI_STATUS_CODE_SPECIFIC_DATA_GUID.
comment|///
name|EFI_STATUS_CODE_DATA
name|DataHeader
decl_stmt|;
comment|///
comment|/// The cache level. Starts with 1 for level 1 cache.
comment|///
name|UINT32
name|Level
decl_stmt|;
comment|///
comment|/// The type of cache.
comment|///
name|EFI_INIT_CACHE_TYPE
name|Type
decl_stmt|;
block|}
name|EFI_CACHE_INIT_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|EFI_CPU_STATE_CHANGE_CAUSE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The reasons that the processor is disabled.
end_comment

begin_comment
comment|/// Used to fill in EFI_COMPUTING_UNIT_CPU_DISABLED_ERROR_DATA.Cause.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_CPU_CAUSE_INTERNAL_ERROR
value|0x0001
end_define

begin_define
define|#
directive|define
name|EFI_CPU_CAUSE_THERMAL_ERROR
value|0x0002
end_define

begin_define
define|#
directive|define
name|EFI_CPU_CAUSE_SELFTEST_FAILURE
value|0x0004
end_define

begin_define
define|#
directive|define
name|EFI_CPU_CAUSE_PREBOOT_TIMEOUT
value|0x0008
end_define

begin_define
define|#
directive|define
name|EFI_CPU_CAUSE_FAILED_TO_START
value|0x0010
end_define

begin_define
define|#
directive|define
name|EFI_CPU_CAUSE_CONFIG_ERROR
value|0x0020
end_define

begin_define
define|#
directive|define
name|EFI_CPU_CAUSE_USER_SELECTION
value|0x0080
end_define

begin_define
define|#
directive|define
name|EFI_CPU_CAUSE_BY_ASSOCIATION
value|0x0100
end_define

begin_define
define|#
directive|define
name|EFI_CPU_CAUSE_UNSPECIFIED
value|0x8000
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure provides information about the disabled computing unit.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure provides details as to why and how the computing unit was disabled. The causes
end_comment

begin_comment
comment|/// should cover the typical reasons a processor would be disabled. How the processor was disabled is
end_comment

begin_comment
comment|/// important because there are distinct differences between hardware and software disabling.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The data header identifying the data. DataHeader.HeaderSize should be
comment|/// sizeof (EFI_STATUS_CODE_DATA), DataHeader.Size should be
comment|/// sizeof (EFI_COMPUTING_UNIT_CPU_DISABLED_ERROR_DATA) -
comment|/// HeaderSize, and DataHeader.Type should be
comment|/// EFI_STATUS_CODE_SPECIFIC_DATA_GUID.
comment|///
name|EFI_STATUS_CODE_DATA
name|DataHeader
decl_stmt|;
comment|///
comment|/// The reason for disabling the processor.
comment|///
name|UINT32
name|Cause
decl_stmt|;
comment|///
comment|/// TRUE if the processor is disabled via software means such as not listing it in the ACPI tables.
comment|/// Such a processor will respond to Interprocessor Interrupts (IPIs). FALSE if the processor is hardware
comment|/// disabled, which means it is invisible to software and will not respond to IPIs.
comment|///
name|BOOLEAN
name|SoftwareDisabled
decl_stmt|;
block|}
name|EFI_COMPUTING_UNIT_CPU_DISABLED_ERROR_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Memory Error Granularity Definition
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT8
name|EFI_MEMORY_ERROR_GRANULARITY
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Memory Error Granularities.  Used to fill in EFI_MEMORY_EXTENDED_ERROR_DATA.Granularity.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_MEMORY_ERROR_OTHER
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_MEMORY_ERROR_UNKNOWN
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_MEMORY_ERROR_DEVICE
value|0x03
end_define

begin_define
define|#
directive|define
name|EFI_MEMORY_ERROR_PARTITION
value|0x04
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Memory Error Operation Definition
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT8
name|EFI_MEMORY_ERROR_OPERATION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Memory Error Operations.  Used to fill in EFI_MEMORY_EXTENDED_ERROR_DATA.Operation.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_MEMORY_OPERATION_OTHER
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_MEMORY_OPERATION_UNKNOWN
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_MEMORY_OPERATION_READ
value|0x03
end_define

begin_define
define|#
directive|define
name|EFI_MEMORY_OPERATION_WRITE
value|0x04
end_define

begin_define
define|#
directive|define
name|EFI_MEMORY_OPERATION_PARTIAL_WRITE
value|0x05
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure provides specific details about the memory error that was detected. It provides
end_comment

begin_comment
comment|/// enough information so that consumers can identify the exact failure and provides enough
end_comment

begin_comment
comment|/// information to enable corrective action if necessary.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The data header identifying the data. DataHeader.HeaderSize should be
comment|/// sizeof (EFI_STATUS_CODE_DATA), DataHeader.Size should be
comment|/// sizeof (EFI_MEMORY_EXTENDED_ERROR_DATA) - HeaderSize, and
comment|/// DataHeader.Type should be EFI_STATUS_CODE_SPECIFIC_DATA_GUID.
comment|///
name|EFI_STATUS_CODE_DATA
name|DataHeader
decl_stmt|;
comment|///
comment|/// The error granularity type.
comment|///
name|EFI_MEMORY_ERROR_GRANULARITY
name|Granularity
decl_stmt|;
comment|///
comment|/// The operation that resulted in the error being detected.
comment|///
name|EFI_MEMORY_ERROR_OPERATION
name|Operation
decl_stmt|;
comment|///
comment|/// The error syndrome, vendor-specific ECC syndrome, or CRC data associated with
comment|/// the error.  If unknown, should be initialized to 0.
comment|/// Inconsistent with specification here:
comment|/// This field in StatusCodes spec0.9 is defined as UINT32, keep code unchanged.
comment|///
name|UINTN
name|Syndrome
decl_stmt|;
comment|///
comment|/// The physical address of the error.
comment|///
name|EFI_PHYSICAL_ADDRESS
name|Address
decl_stmt|;
comment|///
comment|/// The range, in bytes, within which the error address can be determined.
comment|///
name|UINTN
name|Resolution
decl_stmt|;
block|}
name|EFI_MEMORY_EXTENDED_ERROR_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// A definition to describe that the operation is performed on multiple devices within the array.
end_comment

begin_comment
comment|/// May be used for EFI_STATUS_CODE_DIMM_NUMBER.Array and EFI_STATUS_CODE_DIMM_NUMBER.Device.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_MULTIPLE_MEMORY_DEVICE_OPERATION
value|0xfffe
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// A definition to describe that the operation is performed on all devices within the array.
end_comment

begin_comment
comment|/// May be used for EFI_STATUS_CODE_DIMM_NUMBER.Array and EFI_STATUS_CODE_DIMM_NUMBER.Device.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ALL_MEMORY_DEVICE_OPERATION
value|0xffff
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// A definition to describe that the operation is performed on multiple arrays.
end_comment

begin_comment
comment|/// May be used for EFI_STATUS_CODE_DIMM_NUMBER.Array and EFI_STATUS_CODE_DIMM_NUMBER.Device.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_MULTIPLE_MEMORY_ARRAY_OPERATION
value|0xfffe
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// A definition to describe that the operation is performed on all the arrays.
end_comment

begin_comment
comment|/// May be used for EFI_STATUS_CODE_DIMM_NUMBER.Array and EFI_STATUS_CODE_DIMM_NUMBER.Device.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_ALL_MEMORY_ARRAY_OPERATION
value|0xffff
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// This extended data provides some context that consumers can use to locate a DIMM within the
end_comment

begin_comment
comment|/// overall memory scheme.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This extended data provides some context that consumers can use to locate a DIMM within the
end_comment

begin_comment
comment|/// overall memory scheme. The Array and Device numbers may indicate a specific DIMM, or they
end_comment

begin_comment
comment|/// may be populated with the group definitions in "Related Definitions" below.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The data header identifying the data. DataHeader.HeaderSize should be
comment|/// sizeof (EFI_STATUS_CODE_DATA), DataHeader.Size should be
comment|/// sizeof (EFI_STATUS_CODE_DIMM_NUMBER) - HeaderSize, and
comment|/// DataHeader.Type should be EFI_STATUS_CODE_SPECIFIC_DATA_GUID.
comment|///
name|EFI_STATUS_CODE_DATA
name|DataHeader
decl_stmt|;
comment|///
comment|/// The memory array number.
comment|///
name|UINT16
name|Array
decl_stmt|;
comment|///
comment|/// The device number within that Array.
comment|///
name|UINT16
name|Device
decl_stmt|;
block|}
name|EFI_STATUS_CODE_DIMM_NUMBER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure defines extended data describing memory modules that do not match.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This extended data may be used to convey the specifics of memory modules that do not match.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The data header identifying the data. DataHeader.HeaderSize should be
comment|/// sizeof (EFI_STATUS_CODE_DATA), DataHeader.Size should be
comment|/// sizeof (EFI_MEMORY_MODULE_MISMATCH_ERROR_DATA) -
comment|/// HeaderSize, and DataHeader.Type should be
comment|/// EFI_STATUS_CODE_SPECIFIC_DATA_GUID.
comment|///
name|EFI_STATUS_CODE_DATA
name|DataHeader
decl_stmt|;
comment|///
comment|/// The instance number of the memory module that does not match.
comment|///
name|EFI_STATUS_CODE_DIMM_NUMBER
name|Instance
decl_stmt|;
block|}
name|EFI_MEMORY_MODULE_MISMATCH_ERROR_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure defines extended data describing a memory range.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This extended data may be used to convey the specifics of a memory range.  Ranges are specified
end_comment

begin_comment
comment|/// with a start address and a length.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The data header identifying the data. DataHeader.HeaderSize should be
comment|/// sizeof (EFI_STATUS_CODE_DATA), DataHeader.Size should be
comment|/// sizeof (EFI_MEMORY_RANGE_EXTENDED_DATA) - HeaderSize, and
comment|/// DataHeader.Type should be EFI_STATUS_CODE_SPECIFIC_DATA_GUID.
comment|///
name|EFI_STATUS_CODE_DATA
name|DataHeader
decl_stmt|;
comment|///
comment|/// The starting address of the memory range.
comment|///
name|EFI_PHYSICAL_ADDRESS
name|Start
decl_stmt|;
comment|///
comment|/// The length in bytes of the memory range.
comment|///
name|EFI_PHYSICAL_ADDRESS
name|Length
decl_stmt|;
block|}
name|EFI_MEMORY_RANGE_EXTENDED_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure provides the assert information that is typically associated with a debug assertion failing.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The data indicates the location of the assertion that failed in the source code. This information
end_comment

begin_comment
comment|/// includes the file name and line number that are necessary to find the failing assertion in source code.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The data header identifying the data. DataHeader.HeaderSize should be
comment|/// sizeof (EFI_STATUS_CODE_DATA), DataHeader.Size should be
comment|/// sizeof (EFI_DEBUG_ASSERT_DATA) - HeaderSize , and
comment|/// DataHeader.Type should be EFI_STATUS_CODE_SPECIFIC_DATA_GUID.
comment|///
name|EFI_STATUS_CODE_DATA
name|DataHeader
decl_stmt|;
comment|///
comment|/// The line number of the source file where the fault was generated.
comment|///
name|UINT32
name|LineNumber
decl_stmt|;
comment|///
comment|/// The size in bytes of FileName.
comment|///
name|UINT32
name|FileNameSize
decl_stmt|;
comment|///
comment|/// A pointer to a NULL-terminated ASCII or Unicode string that represents
comment|/// the file name of the source file where the fault was generated.
comment|///
name|EFI_STATUS_CODE_STRING_DATA
modifier|*
name|FileName
decl_stmt|;
block|}
name|EFI_DEBUG_ASSERT_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// System Context Data EBC/IA32/IPF
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
union|union
block|{
comment|///
comment|/// The context of the EBC virtual machine when the exception was generated. Type
comment|/// EFI_SYSTEM_CONTEXT_EBC is defined in EFI_DEBUG_SUPPORT_PROTOCOL
comment|/// in the UEFI Specification.
comment|///
name|EFI_SYSTEM_CONTEXT_EBC
name|SystemContextEbc
decl_stmt|;
comment|///
comment|/// The context of the IA-32 processor when the exception was generated. Type
comment|/// EFI_SYSTEM_CONTEXT_IA32 is defined in the
comment|/// EFI_DEBUG_SUPPORT_PROTOCOL in the UEFI Specification.
comment|///
name|EFI_SYSTEM_CONTEXT_IA32
name|SystemContextIa32
decl_stmt|;
comment|///
comment|/// The context of the Itanium(R) processor when the exception was generated. Type
comment|/// EFI_SYSTEM_CONTEXT_IPF is defined in the
comment|/// EFI_DEBUG_SUPPORT_PROTOCOL in the UEFI Specification.
comment|///
name|EFI_SYSTEM_CONTEXT_IPF
name|SystemContextIpf
decl_stmt|;
comment|///
comment|/// The context of the X64 processor when the exception was generated. Type
comment|/// EFI_SYSTEM_CONTEXT_X64 is defined in the
comment|/// EFI_DEBUG_SUPPORT_PROTOCOL in the UEFI Specification.
comment|///
name|EFI_SYSTEM_CONTEXT_X64
name|SystemContextX64
decl_stmt|;
comment|///
comment|/// The context of the ARM processor when the exception was generated. Type
comment|/// EFI_SYSTEM_CONTEXT_ARM is defined in the
comment|/// EFI_DEBUG_SUPPORT_PROTOCOL in the UEFI Specification.
comment|///
name|EFI_SYSTEM_CONTEXT_ARM
name|SystemContextArm
decl_stmt|;
block|}
name|EFI_STATUS_CODE_EXCEP_SYSTEM_CONTEXT
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure defines extended data describing a processor exception error.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This extended data allows the processor context that is present at the time of the exception to be
end_comment

begin_comment
comment|/// reported with the exception. The format and contents of the context data varies depending on the
end_comment

begin_comment
comment|/// processor architecture.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The data header identifying the data. DataHeader.HeaderSize should be
comment|/// sizeof (EFI_STATUS_CODE_DATA), DataHeader.Size should be
comment|/// sizeof (EFI_STATUS_CODE_EXCEP_EXTENDED_DATA) - HeaderSize,
comment|/// and DataHeader.Type should be
comment|/// EFI_STATUS_CODE_SPECIFIC_DATA_GUID.
comment|///
name|EFI_STATUS_CODE_DATA
name|DataHeader
decl_stmt|;
comment|///
comment|/// The system context.
comment|///
name|EFI_STATUS_CODE_EXCEP_SYSTEM_CONTEXT
name|Context
decl_stmt|;
block|}
name|EFI_STATUS_CODE_EXCEP_EXTENDED_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure defines extended data describing a call to a driver binding protocol start function.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This extended data records information about a Start() function call. Start() is a member of
end_comment

begin_comment
comment|/// the UEFI Driver Binding Protocol.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The data header identifying the data. DataHeader.HeaderSize should be
comment|/// sizeof (EFI_STATUS_CODE_DATA), DataHeader.Size should be
comment|/// sizeof (EFI_STATUS_CODE_START_EXTENDED_DATA) - HeaderSize,
comment|/// and DataHeader.Type should be
comment|/// EFI_STATUS_CODE_SPECIFIC_DATA_GUID.
comment|///
name|EFI_STATUS_CODE_DATA
name|DataHeader
decl_stmt|;
comment|///
comment|/// The controller handle.
comment|///
name|EFI_HANDLE
name|ControllerHandle
decl_stmt|;
comment|///
comment|/// The driver binding handle.
comment|///
name|EFI_HANDLE
name|DriverBindingHandle
decl_stmt|;
comment|///
comment|/// The size of the RemainingDevicePath. It is zero if the Start() function is
comment|/// called with RemainingDevicePath = NULL.  The UEFI Specification allows
comment|/// that the Start() function of bus drivers can be called in this way.
comment|///
name|UINT16
name|DevicePathSize
decl_stmt|;
comment|///
comment|/// Matches the RemainingDevicePath parameter being passed to the Start() function.
comment|/// Note that this parameter is the variable-length device path and not a pointer
comment|/// to the device path.
comment|///
comment|//  EFI_DEVICE_PATH_PROTOCOL   RemainingDevicePath;
block|}
name|EFI_STATUS_CODE_START_EXTENDED_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This structure defines extended data describing a legacy option ROM (OpROM).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The device handle and ROM image base can be used by consumers to determine which option ROM
end_comment

begin_comment
comment|/// failed. Due to the black-box nature of legacy option ROMs, the amount of information that can be
end_comment

begin_comment
comment|/// obtained may be limited.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The data header identifying the data. DataHeader.HeaderSize should be
comment|/// sizeof (EFI_STATUS_CODE_DATA), DataHeader.Size should be
comment|/// sizeof (EFI_LEGACY_OPROM_EXTENDED_DATA) - HeaderSize, and
comment|/// DataHeader.Type should be EFI_STATUS_CODE_SPECIFIC_DATA_GUID.
comment|///
name|EFI_STATUS_CODE_DATA
name|DataHeader
decl_stmt|;
comment|///
comment|/// The handle corresponding to the device that this legacy option ROM is being invoked.
comment|///
name|EFI_HANDLE
name|DeviceHandle
decl_stmt|;
comment|///
comment|/// The base address of the shadowed legacy ROM image.  May or may not point to the shadow RAM area.
comment|///
name|EFI_PHYSICAL_ADDRESS
name|RomImageBase
decl_stmt|;
block|}
name|EFI_LEGACY_OPROM_EXTENDED_DATA
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiStatusCodeSpecificDataGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

