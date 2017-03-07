begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EDID Override Protocol from the UEFI 2.0 specification.    Allow platform to provide EDID information to the producer of the Graphics Output   protocol.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EDID_OVERRIDE_H__
end_ifndef

begin_define
define|#
directive|define
name|__EDID_OVERRIDE_H__
end_define

begin_define
define|#
directive|define
name|EFI_EDID_OVERRIDE_PROTOCOL_GUID
define|\
value|{ \     0x48ecb431, 0xfb72, 0x45c0, {0xa9, 0x22, 0xf4, 0x58, 0xfe, 0x4, 0xb, 0xd5 } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_EDID_OVERRIDE_PROTOCOL
name|EFI_EDID_OVERRIDE_PROTOCOL
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_EDID_OVERRIDE_DONT_OVERRIDE
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_EDID_OVERRIDE_ENABLE_HOT_PLUG
value|0x02
end_define

begin_comment
comment|/**   Returns policy information and potentially a replacement EDID for the specified video output device.    @param  This              The EFI_EDID_OVERRIDE_PROTOCOL instance.   @param  ChildHandle       A child handle produced by the Graphics Output EFI                             driver that represents a video output device.   @param  Attributes        The attributes associated with ChildHandle video output device.   @param  EdidSize          A pointer to the size, in bytes, of the Edid buffer.   @param  Edid              A pointer to callee allocated buffer that contains the EDID that                             should be used for ChildHandle. A value of NULL                             represents no EDID override for ChildHandle.    @retval EFI_SUCCESS       Valid overrides returned for ChildHandle.   @retval EFI_UNSUPPORTED   ChildHandle has no overrides.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_EDID_OVERRIDE_PROTOCOL_GET_EDID
function_decl|)
parameter_list|(
name|IN
name|EFI_EDID_OVERRIDE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
modifier|*
name|ChildHandle
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|Attributes
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|EdidSize
parameter_list|,
name|IN
name|OUT
name|UINT8
modifier|*
modifier|*
name|Edid
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This protocol is produced by the platform to allow the platform to provide
end_comment

begin_comment
comment|/// EDID information to the producer of the Graphics Output protocol.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_EDID_OVERRIDE_PROTOCOL
block|{
name|EFI_EDID_OVERRIDE_PROTOCOL_GET_EDID
name|GetEdid
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiEdidOverrideProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

