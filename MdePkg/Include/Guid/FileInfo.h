begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Provides a GUID and a data structure that can be used with EFI_FILE_PROTOCOL.SetInfo()   and EFI_FILE_PROTOCOL.GetInfo() to set or get generic file information.   This GUID is defined in UEFI specification.  Copyright (c) 2006 - 2010, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FILE_INFO_H__
end_ifndef

begin_define
define|#
directive|define
name|__FILE_INFO_H__
end_define

begin_define
define|#
directive|define
name|EFI_FILE_INFO_ID
define|\
value|{ \     0x9576e92, 0x6d3f, 0x11d2, {0x8e, 0x39, 0x0, 0xa0, 0xc9, 0x69, 0x72, 0x3b } \   }
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The size of the EFI_FILE_INFO structure, including the Null-terminated FileName string.
comment|///
name|UINT64
name|Size
decl_stmt|;
comment|///
comment|/// The size of the file in bytes.
comment|///
name|UINT64
name|FileSize
decl_stmt|;
comment|///
comment|/// PhysicalSize The amount of physical space the file consumes on the file system volume.
comment|///
name|UINT64
name|PhysicalSize
decl_stmt|;
comment|///
comment|/// The time the file was created.
comment|///
name|EFI_TIME
name|CreateTime
decl_stmt|;
comment|///
comment|/// The time when the file was last accessed.
comment|///
name|EFI_TIME
name|LastAccessTime
decl_stmt|;
comment|///
comment|/// The time when the file's contents were last modified.
comment|///
name|EFI_TIME
name|ModificationTime
decl_stmt|;
comment|///
comment|/// The attribute bits for the file.
comment|///
name|UINT64
name|Attribute
decl_stmt|;
comment|///
comment|/// The Null-terminated name of the file.
comment|///
name|CHAR16
name|FileName
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_FILE_INFO
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The FileName field of the EFI_FILE_INFO data structure is variable length.
end_comment

begin_comment
comment|/// Whenever code needs to know the size of the EFI_FILE_INFO data structure, it needs to
end_comment

begin_comment
comment|/// be the size of the data structure without the FileName field.  The following macro
end_comment

begin_comment
comment|/// computes this size correctly no matter how big the FileName array is declared.
end_comment

begin_comment
comment|/// This is required to make the EFI_FILE_INFO data structure ANSI compilant.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|SIZE_OF_EFI_FILE_INFO
value|OFFSET_OF (EFI_FILE_INFO, FileName)
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiFileInfoGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

