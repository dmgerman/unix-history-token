begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI_DEVICE_PATH_TO_TEXT_PROTOCOL as defined in UEFI 2.0.     This protocol provides service to convert device nodes and paths to text.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DEVICE_PATH_TO_TEXT_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__DEVICE_PATH_TO_TEXT_PROTOCOL_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Device Path To Text protocol
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_DEVICE_PATH_TO_TEXT_PROTOCOL_GUID
define|\
value|{ \     0x8b843e20, 0x8132, 0x4852, {0x90, 0xcc, 0x55, 0x1a, 0x4e, 0x4a, 0x7f, 0x1c } \   }
end_define

begin_comment
comment|/**   Convert a device node to its text representation.    @param  DeviceNode     Points to the device node to be converted.   @param  DisplayOnly    If DisplayOnly is TRUE, then the shorter text representation                          of the display node is used, where applicable. If DisplayOnly                          is FALSE, then the longer text representation of the display node                          is used.   @param  AllowShortcuts If AllowShortcuts is TRUE, then the shortcut forms of text                          representation for a device node can be used, where applicable.    @retval a_pointer      a pointer to the allocated text representation of the device node data   @retval NULL           if DeviceNode is NULL or there was insufficient memory.  **/
end_comment

begin_typedef
typedef|typedef
name|CHAR16
modifier|*
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DEVICE_PATH_TO_TEXT_NODE
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|DeviceNode
parameter_list|,
name|IN
name|BOOLEAN
name|DisplayOnly
parameter_list|,
name|IN
name|BOOLEAN
name|AllowShortcuts
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Convert a device path to its text representation.    @param  DevicePath     Points to the device path to be converted.   @param  DisplayOnly    If DisplayOnly is TRUE, then the shorter text representation                          of the display node is used, where applicable. If DisplayOnly                          is FALSE, then the longer text representation of the display node                          is used.     @param  AllowShortcuts The AllowShortcuts is FALSE, then the shortcut forms of                          text representation for a device node cannot be used.    @retval a_pointer      a pointer to the allocated text representation of the device node.   @retval NULL           if DevicePath is NULL or there was insufficient memory.  **/
end_comment

begin_typedef
typedef|typedef
name|CHAR16
modifier|*
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DEVICE_PATH_TO_TEXT_PATH
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|DevicePath
parameter_list|,
name|IN
name|BOOLEAN
name|DisplayOnly
parameter_list|,
name|IN
name|BOOLEAN
name|AllowShortcuts
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This protocol converts device paths and device nodes to text.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_TO_TEXT_NODE
name|ConvertDeviceNodeToText
decl_stmt|;
name|EFI_DEVICE_PATH_TO_TEXT_PATH
name|ConvertDevicePathToText
decl_stmt|;
block|}
name|EFI_DEVICE_PATH_TO_TEXT_PROTOCOL
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiDevicePathToTextProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

