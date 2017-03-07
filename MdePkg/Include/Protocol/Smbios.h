begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   SMBIOS Protocol as defined in PI1.2 Specification VOLUME 5 Standard.    SMBIOS protocol allows consumers to log SMBIOS data records, and enables the producer    to create the SMBIOS tables for a platform.    This protocol provides an interface to add, remove or discover SMBIOS records. The driver which   produces this protocol is responsible for creating the SMBIOS data tables and installing the pointer   to the tables in the EFI System Configuration Table.   The caller is responsible for only adding SMBIOS records that are valid for the SMBIOS   MajorVersion and MinorVersion. When an enumerated SMBIOS field's values are   controlled by the DMTF, new values can be used as soon as they are defined by the DMTF without   requiring an update to MajorVersion and MinorVersion.   The SMBIOS protocol can only be called a TPL< TPL_NOTIFY.    Copyright (c) 2006 - 2011, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SMBIOS_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__SMBIOS_PROTOCOL_H__
end_define

begin_include
include|#
directive|include
file|<IndustryStandard/SmBios.h>
end_include

begin_define
define|#
directive|define
name|EFI_SMBIOS_PROTOCOL_GUID
define|\
value|{ 0x3583ff6, 0xcb36, 0x4940, { 0x94, 0x7e, 0xb9, 0xb3, 0x9f, 0x4a, 0xfa, 0xf7 }}
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_BIOS_INFORMATION
value|SMBIOS_TYPE_BIOS_INFORMATION
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_SYSTEM_INFORMATION
value|SMBIOS_TYPE_SYSTEM_INFORMATION
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_BASEBOARD_INFORMATION
value|SMBIOS_TYPE_BASEBOARD_INFORMATION
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_SYSTEM_ENCLOSURE
value|SMBIOS_TYPE_SYSTEM_ENCLOSURE
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_PROCESSOR_INFORMATION
value|SMBIOS_TYPE_PROCESSOR_INFORMATION
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_MEMORY_CONTROLLER_INFORMATION
value|SMBIOS_TYPE_MEMORY_CONTROLLER_INFORMATION
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_MEMORY_MODULE_INFORMATON
value|SMBIOS_TYPE_MEMORY_MODULE_INFORMATON
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_CACHE_INFORMATION
value|SMBIOS_TYPE_CACHE_INFORMATION
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_PORT_CONNECTOR_INFORMATION
value|SMBIOS_TYPE_PORT_CONNECTOR_INFORMATION
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_SYSTEM_SLOTS
value|SMBIOS_TYPE_SYSTEM_SLOTS
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_ONBOARD_DEVICE_INFORMATION
value|SMBIOS_TYPE_ONBOARD_DEVICE_INFORMATION
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_OEM_STRINGS
value|SMBIOS_TYPE_OEM_STRINGS
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_SYSTEM_CONFIGURATION_OPTIONS
value|SMBIOS_TYPE_SYSTEM_CONFIGURATION_OPTIONS
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_BIOS_LANGUAGE_INFORMATION
value|SMBIOS_TYPE_BIOS_LANGUAGE_INFORMATION
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_GROUP_ASSOCIATIONS
value|SMBIOS_TYPE_GROUP_ASSOCIATIONS
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_SYSTEM_EVENT_LOG
value|SMBIOS_TYPE_SYSTEM_EVENT_LOG
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_PHYSICAL_MEMORY_ARRAY
value|SMBIOS_TYPE_PHYSICAL_MEMORY_ARRAY
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_MEMORY_DEVICE
value|SMBIOS_TYPE_MEMORY_DEVICE
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_32BIT_MEMORY_ERROR_INFORMATION
value|SMBIOS_TYPE_32BIT_MEMORY_ERROR_INFORMATION
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_MEMORY_ARRAY_MAPPED_ADDRESS
value|SMBIOS_TYPE_MEMORY_ARRAY_MAPPED_ADDRESS
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_MEMORY_DEVICE_MAPPED_ADDRESS
value|SMBIOS_TYPE_MEMORY_DEVICE_MAPPED_ADDRESS
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_BUILT_IN_POINTING_DEVICE
value|SMBIOS_TYPE_BUILT_IN_POINTING_DEVICE
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_PORTABLE_BATTERY
value|SMBIOS_TYPE_PORTABLE_BATTERY
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_SYSTEM_RESET
value|SMBIOS_TYPE_SYSTEM_RESET
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_HARDWARE_SECURITY
value|SMBIOS_TYPE_HARDWARE_SECURITY
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_SYSTEM_POWER_CONTROLS
value|SMBIOS_TYPE_SYSTEM_POWER_CONTROLS
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_VOLTAGE_PROBE
value|SMBIOS_TYPE_VOLTAGE_PROBE
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_COOLING_DEVICE
value|SMBIOS_TYPE_COOLING_DEVICE
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_TEMPERATURE_PROBE
value|SMBIOS_TYPE_TEMPERATURE_PROBE
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_ELECTRICAL_CURRENT_PROBE
value|SMBIOS_TYPE_ELECTRICAL_CURRENT_PROBE
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_OUT_OF_BAND_REMOTE_ACCESS
value|SMBIOS_TYPE_OUT_OF_BAND_REMOTE_ACCESS
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_BOOT_INTEGRITY_SERVICE
value|SMBIOS_TYPE_BOOT_INTEGRITY_SERVICE
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_SYSTEM_BOOT_INFORMATION
value|SMBIOS_TYPE_SYSTEM_BOOT_INFORMATION
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_64BIT_MEMORY_ERROR_INFORMATION
value|SMBIOS_TYPE_64BIT_MEMORY_ERROR_INFORMATION
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_MANAGEMENT_DEVICE
value|SMBIOS_TYPE_MANAGEMENT_DEVICE
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_MANAGEMENT_DEVICE_COMPONENT
value|SMBIOS_TYPE_MANAGEMENT_DEVICE_COMPONENT
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_MANAGEMENT_DEVICE_THRESHOLD_DATA
value|SMBIOS_TYPE_MANAGEMENT_DEVICE_THRESHOLD_DATA
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_MEMORY_CHANNEL
value|SMBIOS_TYPE_MEMORY_CHANNEL
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_IPMI_DEVICE_INFORMATION
value|SMBIOS_TYPE_IPMI_DEVICE_INFORMATION
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_SYSTEM_POWER_SUPPLY
value|SMBIOS_TYPE_SYSTEM_POWER_SUPPLY
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_ADDITIONAL_INFORMATION
value|SMBIOS_TYPE_ADDITIONAL_INFORMATION
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_ONBOARD_DEVICES_EXTENDED_INFORMATION
value|SMBIOS_TYPE_ONBOARD_DEVICES_EXTENDED_INFORMATION
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_MANAGEMENT_CONTROLLER_HOST_INTERFACE
value|SMBIOS_TYPE_MANAGEMENT_CONTROLLER_HOST_INTERFACE
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_INACTIVE
value|SMBIOS_TYPE_INACTIVE
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_TYPE_END_OF_TABLE
value|SMBIOS_TYPE_END_OF_TABLE
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_OEM_BEGIN
value|SMBIOS_OEM_BEGIN
end_define

begin_define
define|#
directive|define
name|EFI_SMBIOS_OEM_END
value|SMBIOS_OEM_END
end_define

begin_typedef
typedef|typedef
name|SMBIOS_TABLE_STRING
name|EFI_SMBIOS_STRING
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|SMBIOS_TYPE
name|EFI_SMBIOS_TYPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|SMBIOS_HANDLE
name|EFI_SMBIOS_HANDLE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|SMBIOS_STRUCTURE
name|EFI_SMBIOS_TABLE_HEADER
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_EFI_SMBIOS_PROTOCOL
name|EFI_SMBIOS_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   Add an SMBIOS record.      This function allows any agent to add SMBIOS records. The caller is responsible for ensuring   Record is formatted in a way that matches the version of the SMBIOS specification as defined in   the MajorRevision and MinorRevision fields of the EFI_SMBIOS_PROTOCOL.   Record must follow the SMBIOS structure evolution and usage guidelines in the SMBIOS   specification. Record starts with the formatted area of the SMBIOS structure and the length is   defined by EFI_SMBIOS_TABLE_HEADER.Length. Each SMBIOS structure is terminated by a   double-null (0x0000), either directly following the formatted area (if no strings are present) or   directly following the last string. The number of optional strings is not defined by the formatted area,   but is fixed by the call to Add(). A string can be a place holder, but it must not be a NULL string as   two NULL strings look like the double-null that terminates the structure.      @param[in]        This                The EFI_SMBIOS_PROTOCOL instance.   @param[in]        ProducerHandle      The handle of the controller or driver associated with the SMBIOS information. NULL means no handle.   @param[in, out]   SmbiosHandle        On entry, the handle of the SMBIOS record to add. If FFFEh, then a unique handle                                         will be assigned to the SMBIOS record. If the SMBIOS handle is already in use,                                         EFI_ALREADY_STARTED is returned and the SMBIOS record is not updated.   @param[in]        Record              The data for the fixed portion of the SMBIOS record. The format of the record is                                         determined by EFI_SMBIOS_TABLE_HEADER.Type. The size of the formatted                                         area is defined by EFI_SMBIOS_TABLE_HEADER.Length and either followed                                         by a double-null (0x0000) or a set of null terminated strings and a null.      @retval EFI_SUCCESS                   Record was added.   @retval EFI_OUT_OF_RESOURCES          Record was not added.   @retval EFI_ALREADY_STARTED           The SmbiosHandle passed in was already in use. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMBIOS_ADD
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_SMBIOS_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|ProducerHandle
name|OPTIONAL
parameter_list|,
name|IN
name|OUT
name|EFI_SMBIOS_HANDLE
modifier|*
name|SmbiosHandle
parameter_list|,
name|IN
name|EFI_SMBIOS_TABLE_HEADER
modifier|*
name|Record
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Update the string associated with an existing SMBIOS record.      This function allows the update of specific SMBIOS strings. The number of valid strings for any   SMBIOS record is defined by how many strings were present when Add() was called.      @param[in]    This            The EFI_SMBIOS_PROTOCOL instance.   @param[in]    SmbiosHandle    SMBIOS Handle of structure that will have its string updated.   @param[in]    StringNumber    The non-zero string number of the string to update.   @param[in]    String          Update the StringNumber string with String.      @retval EFI_SUCCESS           SmbiosHandle had its StringNumber String updated.   @retval EFI_INVALID_PARAMETER SmbiosHandle does not exist.   @retval EFI_UNSUPPORTED       String was not added because it is longer than the SMBIOS Table supports.   @retval EFI_NOT_FOUND         The StringNumber.is not valid for this SMBIOS record.     **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMBIOS_UPDATE_STRING
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_SMBIOS_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_SMBIOS_HANDLE
modifier|*
name|SmbiosHandle
parameter_list|,
name|IN
name|UINTN
modifier|*
name|StringNumber
parameter_list|,
name|IN
name|CHAR8
modifier|*
name|String
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Remove an SMBIOS record.      This function removes an SMBIOS record using the handle specified by SmbiosHandle.      @param[in]    This                The EFI_SMBIOS_PROTOCOL instance.   @param[in]    SmbiosHandle        The handle of the SMBIOS record to remove.      @retval EFI_SUCCESS               SMBIOS record was removed.   @retval EFI_INVALID_PARAMETER     SmbiosHandle does not specify a valid SMBIOS record. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMBIOS_REMOVE
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_SMBIOS_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_SMBIOS_HANDLE
name|SmbiosHandle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Allow the caller to discover all or some of the SMBIOS records.      This function allows all of the SMBIOS records to be discovered. It's possible to find   only the SMBIOS records that match the optional Type argument.      @param[in]        This            The EFI_SMBIOS_PROTOCOL instance.   @param[in, out]   SmbiosHandle    On entry, points to the previous handle of the SMBIOS record. On exit, points to the                                     next SMBIOS record handle. If it is FFFEh on entry, then the first SMBIOS record                                     handle will be returned. If it returns FFFEh on exit, then there are no more SMBIOS records.   @param[in]        Type            On entry, it points to the type of the next SMBIOS record to return. If NULL, it                                     indicates that the next record of any type will be returned. Type is not                                     modified by the this function.   @param[out]       Record          On exit, points to a pointer to the the SMBIOS Record consisting of the formatted area                                     followed by the unformatted area. The unformatted area optionally contains text strings.   @param[out]       ProducerHandle  On exit, points to the ProducerHandle registered by Add(). If no                                     ProducerHandle was passed into Add() NULL is returned. If a NULL pointer is                                     passed in no data will be returned.   @retval EFI_SUCCESS               SMBIOS record information was successfully returned in Record.                                     SmbiosHandle is the handle of the current SMBIOS record   @retval EFI_NOT_FOUND             The SMBIOS record with SmbiosHandle was the last available record. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMBIOS_GET_NEXT
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_SMBIOS_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|EFI_SMBIOS_HANDLE
modifier|*
name|SmbiosHandle
parameter_list|,
name|IN
name|EFI_SMBIOS_TYPE
modifier|*
name|Type
name|OPTIONAL
parameter_list|,
name|OUT
name|EFI_SMBIOS_TABLE_HEADER
modifier|*
modifier|*
name|Record
parameter_list|,
name|OUT
name|EFI_HANDLE
modifier|*
name|ProducerHandle
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|_EFI_SMBIOS_PROTOCOL
block|{
name|EFI_SMBIOS_ADD
name|Add
decl_stmt|;
name|EFI_SMBIOS_UPDATE_STRING
name|UpdateString
decl_stmt|;
name|EFI_SMBIOS_REMOVE
name|Remove
decl_stmt|;
name|EFI_SMBIOS_GET_NEXT
name|GetNext
decl_stmt|;
name|UINT8
name|MajorVersion
decl_stmt|;
comment|///< The major revision of the SMBIOS specification supported.
name|UINT8
name|MinorVersion
decl_stmt|;
comment|///< The minor revision of the SMBIOS specification supported.
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiSmbiosProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __SMBIOS_PROTOCOL_H__
end_comment

end_unit

