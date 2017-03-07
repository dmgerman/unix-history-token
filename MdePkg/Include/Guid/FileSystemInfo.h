begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Provides a GUID and a data structure that can be used with EFI_FILE_PROTOCOL.GetInfo()   or EFI_FILE_PROTOCOL.SetInfo() to get or set information about the system's volume.   This GUID is defined in UEFI specification.  Copyright (c) 2006 - 2010, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                                                          **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FILE_SYSTEM_INFO_H__
end_ifndef

begin_define
define|#
directive|define
name|__FILE_SYSTEM_INFO_H__
end_define

begin_define
define|#
directive|define
name|EFI_FILE_SYSTEM_INFO_ID
define|\
value|{ \     0x9576e93, 0x6d3f, 0x11d2, {0x8e, 0x39, 0x0, 0xa0, 0xc9, 0x69, 0x72, 0x3b } \   }
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The size of the EFI_FILE_SYSTEM_INFO structure, including the Null-terminated VolumeLabel string.
comment|///
name|UINT64
name|Size
decl_stmt|;
comment|///
comment|/// TRUE if the volume only supports read access.
comment|///
name|BOOLEAN
name|ReadOnly
decl_stmt|;
comment|///
comment|/// The number of bytes managed by the file system.
comment|///
name|UINT64
name|VolumeSize
decl_stmt|;
comment|///
comment|/// The number of available bytes for use by the file system.
comment|///
name|UINT64
name|FreeSpace
decl_stmt|;
comment|///
comment|/// The nominal block size by which files are typically grown.
comment|///
name|UINT32
name|BlockSize
decl_stmt|;
comment|///
comment|/// The Null-terminated string that is the volume's label.
comment|///
name|CHAR16
name|VolumeLabel
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_FILE_SYSTEM_INFO
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The VolumeLabel field of the EFI_FILE_SYSTEM_INFO data structure is variable length.
end_comment

begin_comment
comment|/// Whenever code needs to know the size of the EFI_FILE_SYSTEM_INFO data structure, it needs
end_comment

begin_comment
comment|/// to be the size of the data structure without the VolumeLable field.  The following macro
end_comment

begin_comment
comment|/// computes this size correctly no matter how big the VolumeLable array is declared.
end_comment

begin_comment
comment|/// This is required to make the EFI_FILE_SYSTEM_INFO data structure ANSI compilant.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|SIZE_OF_EFI_FILE_SYSTEM_INFO
value|OFFSET_OF (EFI_FILE_SYSTEM_INFO, VolumeLabel)
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiFileSystemInfoGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

