begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file provides location, format and authentication status of a firmware volume.    Copyright (c) 2013, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   This PPI is introduced in PI Version 1.3 errata.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_PEI_FIRMWARE_VOLUME_INFO2_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_PEI_FIRMWARE_VOLUME_INFO2_H__
end_define

begin_define
define|#
directive|define
name|EFI_PEI_FIRMWARE_VOLUME_INFO2_PPI_GUID
define|\
value|{ 0xea7ca24b, 0xded5, 0x4dad, { 0xa3, 0x89, 0xbf, 0x82, 0x7e, 0x8f, 0x9b, 0x38 } }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_PEI_FIRMWARE_VOLUME_INFO2_PPI
name|EFI_PEI_FIRMWARE_VOLUME_INFO2_PPI
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|///  This PPI describes the location and format of a firmware volume.
end_comment

begin_comment
comment|///  The FvFormat can be EFI_FIRMWARE_FILE_SYSTEM2_GUID or the GUID for
end_comment

begin_comment
comment|///  a user-defined format. The  EFI_FIRMWARE_FILE_SYSTEM2_GUID is
end_comment

begin_comment
comment|///  the PI Firmware Volume format.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_PEI_FIRMWARE_VOLUME_INFO2_PPI
block|{
comment|///
comment|/// Unique identifier of the format of the memory-mapped firmware volume.
comment|///
name|EFI_GUID
name|FvFormat
decl_stmt|;
comment|///
comment|/// Points to a buffer which allows the EFI_PEI_FIRMWARE_VOLUME_PPI to process
comment|/// the volume. The format of this buffer is specific to the FvFormat.
comment|/// For memory-mapped firmware volumes, this typically points to the first byte
comment|/// of the firmware volume.
comment|///
name|VOID
modifier|*
name|FvInfo
decl_stmt|;
comment|///
comment|/// Size of the data provided by FvInfo. For memory-mapped firmware volumes,
comment|/// this is typically the size of the firmware volume.
comment|///
name|UINT32
name|FvInfoSize
decl_stmt|;
comment|///
comment|/// If the firmware volume originally came from a firmware file, then these
comment|/// point to the parent firmware volume name and firmware volume file.
comment|/// If it did not originally come from a firmware file, these should be NULL.
comment|///
name|EFI_GUID
modifier|*
name|ParentFvName
decl_stmt|;
comment|///
comment|/// If the firmware volume originally came from a firmware file, then these
comment|/// point to the parent firmware volume name and firmware volume file.
comment|/// If it did not originally come from a firmware file, these should be NULL.
comment|///
name|EFI_GUID
modifier|*
name|ParentFileName
decl_stmt|;
comment|///
comment|/// Authentication Status.
comment|///
name|UINT32
name|AuthenticationStatus
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPeiFirmwareVolumeInfo2PpiGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

