begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   GUID and related data structures used with the Debug Image Info Table.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   GUID defined in UEFI 2.0 spec.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DEBUG_IMAGE_INFO_GUID_H__
end_ifndef

begin_define
define|#
directive|define
name|__DEBUG_IMAGE_INFO_GUID_H__
end_define

begin_include
include|#
directive|include
file|<Protocol/LoadedImage.h>
end_include

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_DEBUG_IMAGE_INFO_TABLE configuration table GUID declaration.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_DEBUG_IMAGE_INFO_TABLE_GUID
define|\
value|{ \     0x49152e77, 0x1ada, 0x4764, {0xb7, 0xa2, 0x7a, 0xfe, 0xfe, 0xd9, 0x5e, 0x8b } \   }
end_define

begin_define
define|#
directive|define
name|EFI_DEBUG_IMAGE_INFO_UPDATE_IN_PROGRESS
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_DEBUG_IMAGE_INFO_TABLE_MODIFIED
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_DEBUG_IMAGE_INFO_TYPE_NORMAL
value|0x01
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT64
name|Signature
decl_stmt|;
comment|///< A constant UINT64 that has the value EFI_SYSTEM_TABLE_SIGNATURE
name|EFI_PHYSICAL_ADDRESS
name|EfiSystemTableBase
decl_stmt|;
comment|///< The physical address of the EFI system table.
name|UINT32
name|Crc32
decl_stmt|;
comment|///< A 32-bit CRC value that is used to verify the EFI_SYSTEM_TABLE_POINTER structure is valid.
block|}
name|EFI_SYSTEM_TABLE_POINTER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Indicates the type of image info structure. For PE32 EFI images,
comment|/// this is set to EFI_DEBUG_IMAGE_INFO_TYPE_NORMAL.
comment|///
name|UINT32
name|ImageInfoType
decl_stmt|;
comment|///
comment|/// A pointer to an instance of the loaded image protocol for the associated image.
comment|///
name|EFI_LOADED_IMAGE_PROTOCOL
modifier|*
name|LoadedImageProtocolInstance
decl_stmt|;
comment|///
comment|/// Indicates the image handle of the associated image.
comment|///
name|EFI_HANDLE
name|ImageHandle
decl_stmt|;
block|}
name|EFI_DEBUG_IMAGE_INFO_NORMAL
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|UINT32
modifier|*
name|ImageInfoType
decl_stmt|;
name|EFI_DEBUG_IMAGE_INFO_NORMAL
modifier|*
name|NormalImage
decl_stmt|;
block|}
name|EFI_DEBUG_IMAGE_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// UpdateStatus is used by the system to indicate the state of the debug image info table.
comment|///
specifier|volatile
name|UINT32
name|UpdateStatus
decl_stmt|;
comment|///
comment|/// The number of EFI_DEBUG_IMAGE_INFO elements in the array pointed to by EfiDebugImageInfoTable.
comment|///
name|UINT32
name|TableSize
decl_stmt|;
comment|///
comment|/// A pointer to the first element of an array of EFI_DEBUG_IMAGE_INFO structures.
comment|///
name|EFI_DEBUG_IMAGE_INFO
modifier|*
name|EfiDebugImageInfoTable
decl_stmt|;
block|}
name|EFI_DEBUG_IMAGE_INFO_TABLE_HEADER
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiDebugImageInfoTableGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

