begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Provides library functions to construct and parse UEFI Device Paths.    This library provides defines, macros, and functions to help create and parse    EFI_DEVICE_PATH_PROTOCOL structures.  Copyright (c) 2006 - 2013, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DEVICE_PATH_LIB_H__
end_ifndef

begin_define
define|#
directive|define
name|__DEVICE_PATH_LIB_H__
end_define

begin_define
define|#
directive|define
name|END_DEVICE_PATH_LENGTH
value|(sizeof (EFI_DEVICE_PATH_PROTOCOL))
end_define

begin_comment
comment|/**   Determine whether a given device path is valid.   If DevicePath is NULL, then ASSERT().    @param  DevicePath  A pointer to a device path data structure.   @param  MaxSize     The maximum size of the device path data structure.    @retval TRUE        DevicePath is valid.   @retval FALSE       The length of any node node in the DevicePath is less                       than sizeof (EFI_DEVICE_PATH_PROTOCOL).   @retval FALSE       If MaxSize is not zero, the size of the DevicePath                       exceeds MaxSize.   @retval FALSE       If PcdMaximumDevicePathNodeCount is not zero, the node                       count of the DevicePath exceeds PcdMaximumDevicePathNodeCount. **/
end_comment

begin_function_decl
name|BOOLEAN
name|EFIAPI
name|IsDevicePathValid
parameter_list|(
name|IN
name|CONST
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|DevicePath
parameter_list|,
name|IN
name|UINTN
name|MaxSize
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Returns the Type field of a device path node.    Returns the Type field of the device path node specified by Node.    If Node is NULL, then ASSERT().    @param  Node      A pointer to a device path node data structure.    @return The Type field of the device path node specified by Node.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|DevicePathType
parameter_list|(
name|IN
name|CONST
name|VOID
modifier|*
name|Node
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Returns the SubType field of a device path node.    Returns the SubType field of the device path node specified by Node.    If Node is NULL, then ASSERT().    @param  Node      A pointer to a device path node data structure.    @return The SubType field of the device path node specified by Node.  **/
end_comment

begin_function_decl
name|UINT8
name|EFIAPI
name|DevicePathSubType
parameter_list|(
name|IN
name|CONST
name|VOID
modifier|*
name|Node
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Returns the 16-bit Length field of a device path node.    Returns the 16-bit Length field of the device path node specified by Node.     Node is not required to be aligned on a 16-bit boundary, so it is recommended   that a function such as ReadUnaligned16() be used to extract the contents of    the Length field.    If Node is NULL, then ASSERT().    @param  Node      A pointer to a device path node data structure.    @return The 16-bit Length field of the device path node specified by Node.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|DevicePathNodeLength
parameter_list|(
name|IN
name|CONST
name|VOID
modifier|*
name|Node
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Returns a pointer to the next node in a device path.    Returns a pointer to the device path node that follows the device path node specified by Node.    If Node is NULL, then ASSERT().    @param  Node      A pointer to a device path node data structure.    @return a pointer to the device path node that follows the device path node specified by Node.  **/
end_comment

begin_function_decl
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|EFIAPI
name|NextDevicePathNode
parameter_list|(
name|IN
name|CONST
name|VOID
modifier|*
name|Node
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Determines if a device path node is an end node of a device path.   This includes nodes that are the end of a device path instance and nodes that    are the end of an entire device path.    Determines if the device path node specified by Node is an end node of a device path.     This includes nodes that are the end of a device path instance and nodes that are the    end of an entire device path.  If Node represents an end node of a device path,    then TRUE is returned.  Otherwise, FALSE is returned.    If Node is NULL, then ASSERT().    @param  Node      A pointer to a device path node data structure.    @retval TRUE      The device path node specified by Node is an end node of a device path.   @retval FALSE     The device path node specified by Node is not an end node of a device path.    **/
end_comment

begin_function_decl
name|BOOLEAN
name|EFIAPI
name|IsDevicePathEndType
parameter_list|(
name|IN
name|CONST
name|VOID
modifier|*
name|Node
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Determines if a device path node is an end node of an entire device path.    Determines if a device path node specified by Node is an end node of an entire device path.   If Node represents the end of an entire device path, then TRUE is returned.   Otherwise, FALSE is returned.    If Node is NULL, then ASSERT().    @param  Node      A pointer to a device path node data structure.    @retval TRUE      The device path node specified by Node is the end of an entire device path.   @retval FALSE     The device path node specified by Node is not the end of an entire device path.  **/
end_comment

begin_function_decl
name|BOOLEAN
name|EFIAPI
name|IsDevicePathEnd
parameter_list|(
name|IN
name|CONST
name|VOID
modifier|*
name|Node
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Determines if a device path node is an end node of a device path instance.    Determines if a device path node specified by Node is an end node of a device path instance.   If Node represents the end of a device path instance, then TRUE is returned.   Otherwise, FALSE is returned.    If Node is NULL, then ASSERT().    @param  Node      A pointer to a device path node data structure.    @retval TRUE      The device path node specified by Node is the end of a device path instance.   @retval FALSE     The device path node specified by Node is not the end of a device path instance.  **/
end_comment

begin_function_decl
name|BOOLEAN
name|EFIAPI
name|IsDevicePathEndInstance
parameter_list|(
name|IN
name|CONST
name|VOID
modifier|*
name|Node
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Sets the length, in bytes, of a device path node.    Sets the length of the device path node specified by Node to the value specified    by NodeLength.  NodeLength is returned.  Node is not required to be aligned on    a 16-bit boundary, so it is recommended that a function such as WriteUnaligned16()   be used to set the contents of the Length field.    If Node is NULL, then ASSERT().   If NodeLength>= 0x10000, then ASSERT().   If NodeLength< sizeof (EFI_DEVICE_PATH_PROTOCOL), then ASSERT().    @param  Node      A pointer to a device path node data structure.   @param  Length    The length, in bytes, of the device path node.    @return Length  **/
end_comment

begin_function_decl
name|UINT16
name|EFIAPI
name|SetDevicePathNodeLength
parameter_list|(
name|IN
name|OUT
name|VOID
modifier|*
name|Node
parameter_list|,
name|IN
name|UINTN
name|Length
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Fills in all the fields of a device path node that is the end of an entire device path.    Fills in all the fields of a device path node specified by Node so Node represents    the end of an entire device path.  The Type field of Node is set to    END_DEVICE_PATH_TYPE, the SubType field of Node is set to    END_ENTIRE_DEVICE_PATH_SUBTYPE, and the Length field of Node is set to    END_DEVICE_PATH_LENGTH.  Node is not required to be aligned on a 16-bit boundary,    so it is recommended that a function such as WriteUnaligned16() be used to set    the contents of the Length field.     If Node is NULL, then ASSERT().     @param  Node      A pointer to a device path node data structure.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|SetDevicePathEndNode
parameter_list|(
name|OUT
name|VOID
modifier|*
name|Node
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Returns the size of a device path in bytes.    This function returns the size, in bytes, of the device path data structure    specified by DevicePath including the end of device path node.   If DevicePath is NULL or invalid, then 0 is returned.    @param  DevicePath  A pointer to a device path data structure.    @retval 0           If DevicePath is NULL or invalid.   @retval Others      The size of a device path in bytes.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|GetDevicePathSize
parameter_list|(
name|IN
name|CONST
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|DevicePath
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Creates a new copy of an existing device path.    This function allocates space for a new copy of the device path specified by DevicePath.  If   DevicePath is NULL, then NULL is returned.  If the memory is successfully allocated, then the   contents of DevicePath are copied to the newly allocated buffer, and a pointer to that buffer   is returned.  Otherwise, NULL is returned.     The memory for the new device path is allocated from EFI boot services memory.    It is the responsibility of the caller to free the memory allocated.       @param  DevicePath                 A pointer to a device path data structure.    @retval NULL    DevicePath is NULL or invalid.   @retval Others  A pointer to the duplicated device path.    **/
end_comment

begin_function_decl
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|EFIAPI
name|DuplicateDevicePath
parameter_list|(
name|IN
name|CONST
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|DevicePath
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Creates a new device path by appending a second device path to a first device path.    This function creates a new device path by appending a copy of SecondDevicePath to a copy of   FirstDevicePath in a newly allocated buffer.  Only the end-of-device-path device node from   SecondDevicePath is retained. The newly created device path is returned.     If FirstDevicePath is NULL, then it is ignored, and a duplicate of SecondDevicePath is returned.     If SecondDevicePath is NULL, then it is ignored, and a duplicate of FirstDevicePath is returned.     If both FirstDevicePath and SecondDevicePath are NULL, then a copy of an end-of-device-path is   returned.     If there is not enough memory for the newly allocated buffer, then NULL is returned.   The memory for the new device path is allocated from EFI boot services memory. It is the   responsibility of the caller to free the memory allocated.    @param  FirstDevicePath            A pointer to a device path data structure.   @param  SecondDevicePath           A pointer to a device path data structure.      @retval NULL      If there is not enough memory for the newly allocated buffer.   @retval NULL      If FirstDevicePath or SecondDevicePath is invalid.   @retval Others    A pointer to the new device path if success.                     Or a copy an end-of-device-path if both FirstDevicePath and SecondDevicePath are NULL.  **/
end_comment

begin_function_decl
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|EFIAPI
name|AppendDevicePath
parameter_list|(
name|IN
name|CONST
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|FirstDevicePath
parameter_list|,
name|OPTIONAL
name|IN
name|CONST
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|SecondDevicePath
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Creates a new path by appending the device node to the device path.    This function creates a new device path by appending a copy of the device node specified by   DevicePathNode to a copy of the device path specified by DevicePath in an allocated buffer.   The end-of-device-path device node is moved after the end of the appended device node.   If DevicePathNode is NULL then a copy of DevicePath is returned.   If DevicePath is NULL then a copy of DevicePathNode, followed by an end-of-device path device   node is returned.   If both DevicePathNode and DevicePath are NULL then a copy of an end-of-device-path device node   is returned.   If there is not enough memory to allocate space for the new device path, then NULL is returned.     The memory is allocated from EFI boot services memory. It is the responsibility of the caller to   free the memory allocated.    @param  DevicePath                 A pointer to a device path data structure.   @param  DevicePathNode             A pointer to a single device path node.    @retval NULL      There is not enough memory for the new device path.   @retval Others    A pointer to the new device path if success.                     A copy of DevicePathNode followed by an end-of-device-path node                      if both FirstDevicePath and SecondDevicePath are NULL.                     A copy of an end-of-device-path node if both FirstDevicePath and SecondDevicePath are NULL.  **/
end_comment

begin_function_decl
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|EFIAPI
name|AppendDevicePathNode
parameter_list|(
name|IN
name|CONST
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|DevicePath
parameter_list|,
name|OPTIONAL
name|IN
name|CONST
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|DevicePathNode
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Creates a new device path by appending the specified device path instance to the specified device   path.     This function creates a new device path by appending a copy of the device path instance specified   by DevicePathInstance to a copy of the device path secified by DevicePath in a allocated buffer.   The end-of-device-path device node is moved after the end of the appended device path instance   and a new end-of-device-path-instance node is inserted between.    If DevicePath is NULL, then a copy if DevicePathInstance is returned.   If DevicePathInstance is NULL, then NULL is returned.   If DevicePath or DevicePathInstance is invalid, then NULL is returned.   If there is not enough memory to allocate space for the new device path, then NULL is returned.     The memory is allocated from EFI boot services memory. It is the responsibility of the caller to   free the memory allocated.      @param  DevicePath                 A pointer to a device path data structure.   @param  DevicePathInstance         A pointer to a device path instance.    @return A pointer to the new device path.  **/
end_comment

begin_function_decl
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|EFIAPI
name|AppendDevicePathInstance
parameter_list|(
name|IN
name|CONST
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|DevicePath
parameter_list|,
name|OPTIONAL
name|IN
name|CONST
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|DevicePathInstance
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Creates a copy of the current device path instance and returns a pointer to the next device path   instance.    This function creates a copy of the current device path instance. It also updates DevicePath to   point to the next device path instance in the device path (or NULL if no more) and updates Size   to hold the size of the device path instance copy.   If DevicePath is NULL, then NULL is returned.   If DevicePath points to a invalid device path, then NULL is returned.   If there is not enough memory to allocate space for the new device path, then NULL is returned.     The memory is allocated from EFI boot services memory. It is the responsibility of the caller to   free the memory allocated.   If Size is NULL, then ASSERT().     @param  DevicePath                 On input, this holds the pointer to the current device path                                      instance. On output, this holds the pointer to the next device                                      path instance or NULL if there are no more device path                                      instances in the device path pointer to a device path data                                      structure.   @param  Size                       On output, this holds the size of the device path instance, in                                      bytes or zero, if DevicePath is NULL.    @return A pointer to the current device path instance.  **/
end_comment

begin_function_decl
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|EFIAPI
name|GetNextDevicePathInstance
parameter_list|(
name|IN
name|OUT
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
modifier|*
name|DevicePath
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|Size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Creates a device node.    This function creates a new device node in a newly allocated buffer of size NodeLength and   initializes the device path node header with NodeType and NodeSubType.  The new device path node   is returned.   If NodeLength is smaller than a device path header, then NULL is returned.     If there is not enough memory to allocate space for the new device path, then NULL is returned.     The memory is allocated from EFI boot services memory. It is the responsibility of the caller to   free the memory allocated.    @param  NodeType                   The device node type for the new device node.   @param  NodeSubType                The device node sub-type for the new device node.   @param  NodeLength                 The length of the new device node.    @return The new device path.  **/
end_comment

begin_function_decl
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|EFIAPI
name|CreateDeviceNode
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
end_function_decl

begin_comment
comment|/**   Determines if a device path is single or multi-instance.    This function returns TRUE if the device path specified by DevicePath is multi-instance.   Otherwise, FALSE is returned.   If DevicePath is NULL or invalid, then FALSE is returned.    @param  DevicePath                 A pointer to a device path data structure.    @retval  TRUE                      DevicePath is multi-instance.   @retval  FALSE                     DevicePath is not multi-instance, or DevicePath is NULL or invalid.  **/
end_comment

begin_function_decl
name|BOOLEAN
name|EFIAPI
name|IsDevicePathMultiInstance
parameter_list|(
name|IN
name|CONST
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|DevicePath
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Retrieves the device path protocol from a handle.    This function returns the device path protocol from the handle specified by Handle.  If Handle is   NULL or Handle does not contain a device path protocol, then NULL is returned.     @param  Handle                     The handle from which to retrieve the device path protocol.    @return The device path protocol from the handle specified by Handle.  **/
end_comment

begin_function_decl
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|EFIAPI
name|DevicePathFromHandle
parameter_list|(
name|IN
name|EFI_HANDLE
name|Handle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Allocates a device path for a file and appends it to an existing device path.    If Device is a valid device handle that contains a device path protocol, then a device path for   the file specified by FileName  is allocated and appended to the device path associated with the   handle Device.  The allocated device path is returned.  If Device is NULL or Device is a handle   that does not support the device path protocol, then a device path containing a single device   path node for the file specified by FileName is allocated and returned.   The memory for the new device path is allocated from EFI boot services memory. It is the responsibility   of the caller to free the memory allocated.      If FileName is NULL, then ASSERT().   If FileName is not aligned on a 16-bit boundary, then ASSERT().    @param  Device                     A pointer to a device handle.  This parameter is optional and                                      may be NULL.   @param  FileName                   A pointer to a Null-terminated Unicode string.    @return The allocated device path.  **/
end_comment

begin_function_decl
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|EFIAPI
name|FileDevicePath
parameter_list|(
name|IN
name|EFI_HANDLE
name|Device
parameter_list|,
name|OPTIONAL
name|IN
name|CONST
name|CHAR16
modifier|*
name|FileName
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Converts a device path to its text representation.    @param DevicePath      A Pointer to the device to be converted.   @param DisplayOnly     If DisplayOnly is TRUE, then the shorter text representation                          of the display node is used, where applicable. If DisplayOnly                          is FALSE, then the longer text representation of the display node                          is used.   @param AllowShortcuts  If AllowShortcuts is TRUE, then the shortcut forms of text                          representation for a device node can be used, where applicable.    @return A pointer to the allocated text representation of the device path or           NULL if DeviceNode is NULL or there was insufficient memory.  **/
end_comment

begin_function_decl
name|CHAR16
modifier|*
name|EFIAPI
name|ConvertDevicePathToText
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
end_function_decl

begin_comment
comment|/**   Converts a device node to its string representation.    @param DeviceNode        A Pointer to the device node to be converted.   @param DisplayOnly       If DisplayOnly is TRUE, then the shorter text representation                            of the display node is used, where applicable. If DisplayOnly                            is FALSE, then the longer text representation of the display node                            is used.   @param AllowShortcuts    If AllowShortcuts is TRUE, then the shortcut forms of text                            representation for a device node can be used, where applicable.    @return A pointer to the allocated text representation of the device node or NULL if DeviceNode           is NULL or there was insufficient memory.  **/
end_comment

begin_function_decl
name|CHAR16
modifier|*
name|EFIAPI
name|ConvertDeviceNodeToText
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
end_function_decl

begin_comment
comment|/**   Convert text to the binary representation of a device node.    @param TextDeviceNode  TextDeviceNode points to the text representation of a device                          node. Conversion starts with the first character and continues                          until the first non-device node character.    @return A pointer to the EFI device node or NULL if TextDeviceNode is NULL or there was           insufficient memory or text unsupported.  **/
end_comment

begin_function_decl
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|EFIAPI
name|ConvertTextToDeviceNode
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|TextDeviceNode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Convert text to the binary representation of a device path.    @param TextDevicePath  TextDevicePath points to the text representation of a device                          path. Conversion starts with the first character and continues                          until the first non-device node character.    @return A pointer to the allocated device path or NULL if TextDeviceNode is NULL or           there was insufficient memory.  **/
end_comment

begin_function_decl
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|EFIAPI
name|ConvertTextToDevicePath
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|TextDevicePath
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

