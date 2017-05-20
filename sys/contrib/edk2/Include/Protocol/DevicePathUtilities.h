begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI_DEVICE_PATH_UTILITIES_PROTOCOL as defined in UEFI 2.0.     Use to create and manipulate device paths and device nodes.    Copyright (c) 2006 - 2010, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DEVICE_PATH_UTILITIES_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__DEVICE_PATH_UTILITIES_PROTOCOL_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Device Path Utilities protocol
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_DEVICE_PATH_UTILITIES_PROTOCOL_GUID
define|\
value|{ \     0x379be4e, 0xd706, 0x437d, {0xb0, 0x37, 0xed, 0xb8, 0x2f, 0xb7, 0x72, 0xa4 } \   }
end_define

begin_comment
comment|/**   Returns the size of the device path, in bytes.    @param  DevicePath Points to the start of the EFI device path.    @return Size  Size of the specified device path, in bytes, including the end-of-path tag.   @retval 0     DevicePath is NULL     **/
end_comment

begin_typedef
typedef|typedef
name|UINTN
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DEVICE_PATH_UTILS_GET_DEVICE_PATH_SIZE
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|DevicePath
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Create a duplicate of the specified path.    @param  DevicePath Points to the source EFI device path.    @retval Pointer    A pointer to the duplicate device path.   @retval NULL       insufficient memory or DevicePath is NULL  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DEVICE_PATH_UTILS_DUP_DEVICE_PATH
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|DevicePath
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Create a new path by appending the second device path to the first.   If Src1 is NULL and Src2 is non-NULL, then a duplicate of Src2 is returned.    If Src1 is non-NULL and Src2 is NULL, then a duplicate of Src1 is returned.   If Src1 and Src2 are both NULL, then a copy of an end-of-device-path is returned.    @param  Src1 Points to the first device path.   @param  Src2 Points to the second device path.    @retval Pointer  A pointer to the newly created device path.   @retval NULL     Memory could not be allocated  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DEVICE_PATH_UTILS_APPEND_PATH
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|Src1
parameter_list|,
name|IN
name|CONST
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|Src2
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Creates a new path by appending the device node to the device path.   If DeviceNode is NULL then a copy of DevicePath is returned.    If DevicePath is NULL then a copy of DeviceNode, followed by an end-of-device path device node is returned.   If both DeviceNode and DevicePath are NULL then a copy of an end-of-device-path device node is returned.    @param  DevicePath Points to the device path.   @param  DeviceNode Points to the device node.    @retval Pointer    A pointer to the allocated device node.   @retval NULL       There was insufficient memory.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DEVICE_PATH_UTILS_APPEND_NODE
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|DevicePath
parameter_list|,
name|IN
name|CONST
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|DeviceNode
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Creates a new path by appending the specified device path instance to the specified device path.    @param  DevicePath         Points to the device path. If NULL, then ignored.   @param  DevicePathInstance Points to the device path instance.    @retval Pointer            A pointer to the newly created device path   @retval NULL               Memory could not be allocated or DevicePathInstance is NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DEVICE_PATH_UTILS_APPEND_INSTANCE
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|DevicePath
parameter_list|,
name|IN
name|CONST
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|DevicePathInstance
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Creates a copy of the current device path instance and returns a pointer to the next device path   instance.    @param  DevicePathInstance     On input, this holds the pointer to the current device path                                  instance. On output, this holds the pointer to the next                                  device path instance or NULL if there are no more device                                  path instances in the device path.     @param  DevicePathInstanceSize On output, this holds the size of the device path instance,                                  in bytes or zero, if DevicePathInstance is NULL.                                  If NULL, then the instance size is not output.    @retval Pointer                A pointer to the copy of the current device path instance.   @retval NULL                   DevicePathInstace was NULL on entry or there was insufficient memory.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DEVICE_PATH_UTILS_GET_NEXT_INSTANCE
function_decl|)
parameter_list|(
name|IN
name|OUT
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
modifier|*
name|DevicePathInstance
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|DevicePathInstanceSize
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Creates a device node    @param  NodeType    NodeType is the device node type (EFI_DEVICE_PATH.Type) for                       the new device node.   @param  NodeSubType NodeSubType is the device node sub-type                       EFI_DEVICE_PATH.SubType) for the new device node.   @param  NodeLength  NodeLength is the length of the device node                       (EFI_DEVICE_PATH.Length) for the new device node.    @retval Pointer     A pointer to the newly created device node.   @retval NULL        NodeLength is less than                       the size of the header or there was insufficient memory.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DEVICE_PATH_UTILS_CREATE_NODE
function_decl|)
parameter_list|(
name|IN
name|UINT8
name|NodeType
parameter_list|,
name|IN
name|UINT8
name|NodeSubType
parameter_list|,
name|IN
name|UINT16
name|NodeLength
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Returns whether a device path is multi-instance.    @param  DevicePath Points to the device path. If NULL, then ignored.    @retval TRUE       The device path has more than one instance   @retval FALSE      The device path is empty or contains only a single instance.  **/
end_comment

begin_typedef
typedef|typedef
name|BOOLEAN
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DEVICE_PATH_UTILS_IS_MULTI_INSTANCE
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|DevicePath
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This protocol is used to creates and manipulates device paths and device nodes.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_UTILS_GET_DEVICE_PATH_SIZE
name|GetDevicePathSize
decl_stmt|;
name|EFI_DEVICE_PATH_UTILS_DUP_DEVICE_PATH
name|DuplicateDevicePath
decl_stmt|;
name|EFI_DEVICE_PATH_UTILS_APPEND_PATH
name|AppendDevicePath
decl_stmt|;
name|EFI_DEVICE_PATH_UTILS_APPEND_NODE
name|AppendDeviceNode
decl_stmt|;
name|EFI_DEVICE_PATH_UTILS_APPEND_INSTANCE
name|AppendDevicePathInstance
decl_stmt|;
name|EFI_DEVICE_PATH_UTILS_GET_NEXT_INSTANCE
name|GetNextDevicePathInstance
decl_stmt|;
name|EFI_DEVICE_PATH_UTILS_IS_MULTI_INSTANCE
name|IsDevicePathMultiInstance
decl_stmt|;
name|EFI_DEVICE_PATH_UTILS_CREATE_NODE
name|CreateDeviceNode
decl_stmt|;
block|}
name|EFI_DEVICE_PATH_UTILITIES_PROTOCOL
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiDevicePathUtilitiesProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

