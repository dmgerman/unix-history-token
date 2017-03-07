begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Guid& data structure used for EFI System Resource Table (ESRT)    Copyright (c) 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution. The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   GUIDs defined in UEFI 2.5 spec.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYSTEM_RESOURCE_TABLE_H__
end_ifndef

begin_define
define|#
directive|define
name|_SYSTEM_RESOURCE_TABLE_H__
end_define

begin_define
define|#
directive|define
name|EFI_SYSTEM_RESOURCE_TABLE_GUID
define|\
value|{ \     0xb122a263, 0x3661, 0x4f68, {0x99, 0x29, 0x78, 0xf8, 0xb0, 0xd6, 0x21, 0x80 } \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Current Entry Version
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_SYSTEM_RESOURCE_TABLE_FIRMWARE_RESOURCE_VERSION
value|1
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Firmware Type Definitions
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|ESRT_FW_TYPE_UNKNOWN
value|0x00000000
end_define

begin_define
define|#
directive|define
name|ESRT_FW_TYPE_SYSTEMFIRMWARE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ESRT_FW_TYPE_DEVICEFIRMWARE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ESRT_FW_TYPE_UEFIDRIVER
value|0x00000003
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Last Attempt Status Values
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|LAST_ATTEMPT_STATUS_SUCCESS
value|0x00000000
end_define

begin_define
define|#
directive|define
name|LAST_ATTEMPT_STATUS_ERROR_UNSUCCESSFUL
value|0x00000001
end_define

begin_define
define|#
directive|define
name|LAST_ATTEMPT_STATUS_ERROR_INSUFFICIENT_RESOURCES
value|0x00000002
end_define

begin_define
define|#
directive|define
name|LAST_ATTEMPT_STATUS_ERROR_INCORRECT_VERSION
value|0x00000003
end_define

begin_define
define|#
directive|define
name|LAST_ATTEMPT_STATUS_ERROR_INVALID_FORMAT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|LAST_ATTEMPT_STATUS_ERROR_AUTH_ERROR
value|0x00000005
end_define

begin_define
define|#
directive|define
name|LAST_ATTEMPT_STATUS_ERROR_PWR_EVT_AC
value|0x00000006
end_define

begin_define
define|#
directive|define
name|LAST_ATTEMPT_STATUS_ERROR_PWR_EVT_BATT
value|0x00000007
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The firmware class field contains a GUID that identifies a firmware component
comment|/// that can be updated via UpdateCapsule(). This GUID must be unique within all
comment|/// entries of the ESRT.
comment|///
name|EFI_GUID
name|FwClass
decl_stmt|;
comment|///
comment|/// Identifies the type of firmware resource.
comment|///
name|UINT32
name|FwType
decl_stmt|;
comment|///
comment|/// The firmware version field represents the current version of the firmware
comment|/// resource, value must always increase as a larger number represents a newer
comment|/// version.
comment|///
name|UINT32
name|FwVersion
decl_stmt|;
comment|///
comment|/// The lowest firmware resource version to which a firmware resource can be
comment|/// rolled back for the given system/device. Generally this is used to protect
comment|/// against known and fixed security issues.
comment|///
name|UINT32
name|LowestSupportedFwVersion
decl_stmt|;
comment|///
comment|/// The capsule flags field contains the CapsuleGuid flags (bits 0- 15) as defined
comment|/// in the EFI_CAPSULE_HEADER that will be set in the capsule header.
comment|///
name|UINT32
name|CapsuleFlags
decl_stmt|;
comment|///
comment|/// The last attempt version field describes the last firmware version for which
comment|/// an update was attempted (uses the same format as Firmware Version).
comment|/// Last Attempt Version is updated each time an UpdateCapsule() is attempted for
comment|/// an ESRT entry and is preserved across reboots (non-volatile). However, in
comment|/// cases where the attempt version is not recorded due to limitations in the
comment|/// update process, the field shall set to zero after a failed update. Similarly,
comment|/// in the case of a removable device, this value is set to 0 in cases where the
comment|/// device has not been updated since being added to the system.
comment|///
name|UINT32
name|LastAttemptVersion
decl_stmt|;
comment|///
comment|/// The last attempt status field describes the result of the last firmware update
comment|/// attempt for the firmware resource entry.
comment|/// LastAttemptStatus is updated each time an UpdateCapsule() is attempted for an
comment|/// ESRT entry and is preserved across reboots (non-volatile).
comment|/// If a firmware update has never been attempted or is unknown, for example after
comment|/// fresh insertion of a removable device, LastAttemptStatus must be set to Success.
comment|///
name|UINT32
name|LastAttemptStatus
decl_stmt|;
block|}
name|EFI_SYSTEM_RESOURCE_ENTRY
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The number of firmware resources in the table, must not be zero.
comment|///
name|UINT32
name|FwResourceCount
decl_stmt|;
comment|///
comment|/// The maximum number of resource array entries that can be within the table
comment|/// without reallocating the table, must not be zero.
comment|///
name|UINT32
name|FwResourceCountMax
decl_stmt|;
comment|///
comment|/// The version of the EFI_SYSTEM_RESOURCE_ENTRY entities used in this table.
comment|/// This field should be set to 1.
comment|///
name|UINT64
name|FwResourceVersion
decl_stmt|;
comment|///
comment|/// Array of EFI_SYSTEM_RESOURCE_ENTRY
comment|///
comment|//EFI_SYSTEM_RESOURCE_ENTRY  Entries[];
block|}
name|EFI_SYSTEM_RESOURCE_TABLE
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiSystemResourceTableGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

