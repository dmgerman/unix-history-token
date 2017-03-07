begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Hob guid for Information about the graphics mode.    Copyright (c) 2015 - 2016, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution. The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This HOB is introduced in in PI Version 1.4.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GRAPHICS_INFO_HOB_GUID_H_
end_ifndef

begin_define
define|#
directive|define
name|_GRAPHICS_INFO_HOB_GUID_H_
end_define

begin_include
include|#
directive|include
file|<Protocol/GraphicsOutput.h>
end_include

begin_define
define|#
directive|define
name|EFI_PEI_GRAPHICS_INFO_HOB_GUID
define|\
value|{ \     0x39f62cce, 0x6825, 0x4669, { 0xbb, 0x56, 0x54, 0x1a, 0xba, 0x75, 0x3a, 0x07 } \   }
end_define

begin_define
define|#
directive|define
name|EFI_PEI_GRAPHICS_DEVICE_INFO_HOB_GUID
define|\
value|{ \     0xe5cb2ac9, 0xd35d, 0x4430, { 0x93, 0x6e, 0x1d, 0xe3, 0x32, 0x47, 0x8d, 0xe7 } \   }
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_PHYSICAL_ADDRESS
name|FrameBufferBase
decl_stmt|;
name|UINT32
name|FrameBufferSize
decl_stmt|;
name|EFI_GRAPHICS_OUTPUT_MODE_INFORMATION
name|GraphicsMode
decl_stmt|;
block|}
name|EFI_PEI_GRAPHICS_INFO_HOB
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|VendorId
decl_stmt|;
comment|///< Ignore if the value is 0xFFFF.
name|UINT16
name|DeviceId
decl_stmt|;
comment|///< Ignore if the value is 0xFFFF.
name|UINT16
name|SubsystemVendorId
decl_stmt|;
comment|///< Ignore if the value is 0xFFFF.
name|UINT16
name|SubsystemId
decl_stmt|;
comment|///< Ignore if the value is 0xFFFF.
name|UINT8
name|RevisionId
decl_stmt|;
comment|///< Ignore if the value is 0xFF.
name|UINT8
name|BarIndex
decl_stmt|;
comment|///< Ignore if the value is 0xFF.
block|}
name|EFI_PEI_GRAPHICS_DEVICE_INFO_HOB
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiGraphicsInfoHobGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiGraphicsDeviceInfoHobGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

