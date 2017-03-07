begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   UEFI 2.0 Loaded image protocol definition.    Every EFI driver and application is passed an image handle when it is loaded.   This image handle will contain a Loaded Image Protocol.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__LOADED_IMAGE_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__LOADED_IMAGE_PROTOCOL_H__
end_define

begin_define
define|#
directive|define
name|EFI_LOADED_IMAGE_PROTOCOL_GUID
define|\
value|{ \     0x5B1B31A1, 0x9562, 0x11d2, {0x8E, 0x3F, 0x00, 0xA0, 0xC9, 0x69, 0x72, 0x3B } \   }
end_define

begin_define
define|#
directive|define
name|EFI_LOADED_IMAGE_DEVICE_PATH_PROTOCOL_GUID
define|\
value|{ \     0xbc62157e, 0x3e33, 0x4fec, {0x99, 0x20, 0x2d, 0x3b, 0x36, 0xd7, 0x50, 0xdf } \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Protocol GUID defined in EFI1.1.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|LOADED_IMAGE_PROTOCOL
value|EFI_LOADED_IMAGE_PROTOCOL_GUID
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_SYSTEM_TABLE& EFI_IMAGE_UNLOAD are defined in EfiApi.h
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_LOADED_IMAGE_PROTOCOL_REVISION
value|0x1000
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Revision defined in EFI1.1.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_LOADED_IMAGE_INFORMATION_REVISION
value|EFI_LOADED_IMAGE_PROTOCOL_REVISION
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Can be used on any image handle to obtain information about the loaded image.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Revision
decl_stmt|;
comment|///< Defines the revision of the EFI_LOADED_IMAGE_PROTOCOL structure.
comment|///< All future revisions will be backward compatible to the current revision.
name|EFI_HANDLE
name|ParentHandle
decl_stmt|;
comment|///< Parent image's image handle. NULL if the image is loaded directly from
comment|///< the firmware's boot manager.
name|EFI_SYSTEM_TABLE
modifier|*
name|SystemTable
decl_stmt|;
comment|///< the image's EFI system table pointer.
comment|//
comment|// Source location of image
comment|//
name|EFI_HANDLE
name|DeviceHandle
decl_stmt|;
comment|///< The device handle that the EFI Image was loaded from.
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|FilePath
decl_stmt|;
comment|///< A pointer to the file path portion specific to DeviceHandle
comment|///< that the EFI Image was loaded from.
name|VOID
modifier|*
name|Reserved
decl_stmt|;
comment|///< Reserved. DO NOT USE.
comment|//
comment|// Images load options
comment|//
name|UINT32
name|LoadOptionsSize
decl_stmt|;
comment|///< The size in bytes of LoadOptions.
name|VOID
modifier|*
name|LoadOptions
decl_stmt|;
comment|///< A pointer to the image's binary load options.
comment|//
comment|// Location of where image was loaded
comment|//
name|VOID
modifier|*
name|ImageBase
decl_stmt|;
comment|///< The base address at which the image was loaded.
name|UINT64
name|ImageSize
decl_stmt|;
comment|///< The size in bytes of the loaded image.
name|EFI_MEMORY_TYPE
name|ImageCodeType
decl_stmt|;
comment|///< The memory type that the code sections were loaded as.
name|EFI_MEMORY_TYPE
name|ImageDataType
decl_stmt|;
comment|///< The memory type that the data sections were loaded as.
name|EFI_IMAGE_UNLOAD
name|Unload
decl_stmt|;
block|}
name|EFI_LOADED_IMAGE_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// For backward-compatible with EFI1.1.
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
name|EFI_LOADED_IMAGE_PROTOCOL
name|EFI_LOADED_IMAGE
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiLoadedImageProtocolGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiLoadedImageDevicePathProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

