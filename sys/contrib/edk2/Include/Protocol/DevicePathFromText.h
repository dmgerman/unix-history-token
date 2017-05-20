begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI_DEVICE_PATH_FROM_TEXT_PROTOCOL as defined in UEFI 2.0.     This protocol provides service to convert text to device paths and device nodes.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DEVICE_PATH_FROM_TEXT_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__DEVICE_PATH_FROM_TEXT_PROTOCOL_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Device Path From Text protocol
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_DEVICE_PATH_FROM_TEXT_PROTOCOL_GUID
define|\
value|{ \     0x5c99a21, 0xc70f, 0x4ad2, {0x8a, 0x5f, 0x35, 0xdf, 0x33, 0x43, 0xf5, 0x1e  } \   }
end_define

begin_comment
comment|/**   Convert text to the binary representation of a device node.    @param  TextDeviceNode TextDeviceNode points to the text representation of a device                          node. Conversion starts with the first character and continues                          until the first non-device node character.    @retval a_pointer      Pointer to the EFI device node.   @retval NULL           if TextDeviceNode is NULL or there was insufficient memory.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DEVICE_PATH_FROM_TEXT_NODE
function_decl|)
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|TextDeviceNode
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Convert text to the binary representation of a device node.    @param  TextDeviceNode TextDevicePath points to the text representation of a device                          path. Conversion starts with the first character and continues                          until the first non-device path character.    @retval a_pointer      Pointer to the allocated device path.   @retval NULL           if TextDeviceNode is NULL or there was insufficient memory.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DEVICE_PATH_FROM_TEXT_PATH
function_decl|)
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|TextDevicePath
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This protocol converts text to device paths and device nodes.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_FROM_TEXT_NODE
name|ConvertTextToDeviceNode
decl_stmt|;
name|EFI_DEVICE_PATH_FROM_TEXT_PATH
name|ConvertTextToDevicePath
decl_stmt|;
block|}
name|EFI_DEVICE_PATH_FROM_TEXT_PROTOCOL
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiDevicePathFromTextProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

