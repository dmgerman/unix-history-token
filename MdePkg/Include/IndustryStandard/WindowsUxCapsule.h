begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Defines Windows UX Capsule GUID and layout defined at Microsoft   Windows UEFI Firmware Update Platform specification    Copyright (c) 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials    are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_WINDOWS_UX_CAPSULE_GUID_H_
end_ifndef

begin_define
define|#
directive|define
name|_WINDOWS_UX_CAPSULE_GUID_H_
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Version
decl_stmt|;
name|UINT8
name|Checksum
decl_stmt|;
name|UINT8
name|ImageType
decl_stmt|;
name|UINT8
name|Reserved
decl_stmt|;
name|UINT32
name|Mode
decl_stmt|;
name|UINT32
name|OffsetX
decl_stmt|;
name|UINT32
name|OffsetY
decl_stmt|;
comment|//UINT8  Image[];
block|}
name|DISPLAY_DISPLAY_PAYLOAD
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_CAPSULE_HEADER
name|CapsuleHeader
decl_stmt|;
name|DISPLAY_DISPLAY_PAYLOAD
name|ImagePayload
decl_stmt|;
block|}
name|EFI_DISPLAY_CAPSULE
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_define
define|#
directive|define
name|WINDOWS_UX_CAPSULE_GUID
define|\
value|{ \     0x3b8c8162, 0x188c, 0x46a4, { 0xae, 0xc9, 0xbe, 0x43, 0xf1, 0xd6, 0x56, 0x97}  \   }
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gWindowsUxCapsuleGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

