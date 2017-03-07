begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Guid& data structure used for Capsule process result variables      Copyright (c) 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   GUIDs defined in UEFI 2.4 spec.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CAPSULE_REPORT_GUID_H__
end_ifndef

begin_define
define|#
directive|define
name|_CAPSULE_REPORT_GUID_H__
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// This is the GUID for capsule result variable.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_CAPSULE_REPORT_GUID
define|\
value|{ \     0x39b68c46, 0xf7fb, 0x441b, {0xb6, 0xec, 0x16, 0xb0, 0xf6, 0x98, 0x21, 0xf3 } \   }
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Size in bytes of the variable including any data beyond header as specified by CapsuleGuid
comment|///
name|UINT32
name|VariableTotalSize
decl_stmt|;
comment|///
comment|/// For alignment
comment|///
name|UINT32
name|Reserved
decl_stmt|;
comment|///
comment|/// Guid from EFI_CAPSULE_HEADER
comment|///
name|EFI_GUID
name|CapsuleGuid
decl_stmt|;
comment|///
comment|/// Timestamp using system time when processing completed
comment|///
name|EFI_TIME
name|CapsuleProcessed
decl_stmt|;
comment|///
comment|/// Result of the capsule processing. Exact interpretation of any error code may depend
comment|/// upon type of capsule processed
comment|///
name|EFI_STATUS
name|CapsuleStatus
decl_stmt|;
block|}
name|EFI_CAPSULE_RESULT_VARIABLE_HEADER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Version of this structure, currently 0x00000001
comment|///
name|UINT16
name|Version
decl_stmt|;
comment|///
comment|/// The index of the payload within the FMP capsule which was processed to generate this report
comment|/// Starting from zero
comment|///
name|UINT8
name|PayloadIndex
decl_stmt|;
comment|///
comment|/// The UpdateImageIndex from EFI_FIRMWARE_MANAGEMENT_CAPSULE_IMAGE_HEADER
comment|/// (after unsigned conversion from UINT8 to UINT16).
comment|///
name|UINT8
name|UpdateImageIndex
decl_stmt|;
comment|///
comment|/// The UpdateImageTypeId Guid from EFI_FIRMWARE_MANAGEMENT_CAPSULE_IMAGE_HEADER.
comment|///
name|EFI_GUID
name|UpdateImageTypeId
decl_stmt|;
comment|///
comment|/// In case of capsule loaded from disk, the zero-terminated array containing file name of capsule that was processed.
comment|/// In case of capsule submitted directly to UpdateCapsule() there is no file name, and this field is required to contain a single 16-bit zero character
comment|///  which is included in VariableTotalSize.
comment|///
comment|/// CHAR16 CapsuleFileName[];
comment|///
comment|///
comment|/// This field will contain a zero-terminated CHAR16 string containing the text representation of the device path of device publishing Firmware Management Protocol
comment|/// (if present). In case where device path is not present and the target is not otherwise known to firmware, or when payload was blocked by policy, or skipped,
comment|/// this field is required to contain a single 16-bit zero character which is included in VariableTotalSize.
comment|///
comment|/// CHAR16 CapsuleTarget[];
comment|///
block|}
name|EFI_CAPSULE_RESULT_VARIABLE_FMP
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiCapsuleReportGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

