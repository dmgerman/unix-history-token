begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Guid used to define the Firmware File System 2.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   GUIDs introduced in PI Version 1.0.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FIRMWARE_FILE_SYSTEM2_GUID_H__
end_ifndef

begin_define
define|#
directive|define
name|__FIRMWARE_FILE_SYSTEM2_GUID_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The firmware volume header contains a data field for
end_comment

begin_comment
comment|/// the file system GUID
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_FIRMWARE_FILE_SYSTEM2_GUID
define|\
value|{ 0x8c8ce578, 0x8a3d, 0x4f1c, { 0x99, 0x35, 0x89, 0x61, 0x85, 0xc3, 0x2d, 0xd3 } }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// A Volume Top File (VTF) is a file that must be
end_comment

begin_comment
comment|/// located such that the last byte of the file is
end_comment

begin_comment
comment|/// also the last byte of the firmware volume
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_FFS_VOLUME_TOP_FILE_GUID
define|\
value|{ 0x1BA0062E, 0xC779, 0x4582, { 0x85, 0x66, 0x33, 0x6A, 0xE8, 0xF7, 0x8F, 0x9 } }
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiFirmwareFileSystem2Guid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiFirmwareVolumeTopFileGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

