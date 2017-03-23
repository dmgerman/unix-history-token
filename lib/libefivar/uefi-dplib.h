begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2017 Netflix, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Taken from MdePkg/Library/UefiDevicePathLib/UefiDevicePathLib.h  * hash a11928f3310518ab1c6fd34e8d0fdbb72de9602c 2017-Mar-01  */
end_comment

begin_comment
comment|/** @file   Definition for Device Path library.  Copyright (c) 2013 - 2015, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UEFI_DEVICE_PATH_LIB_H_
end_ifndef

begin_define
define|#
directive|define
name|_UEFI_DEVICE_PATH_LIB_H_
end_define

begin_include
include|#
directive|include
file|<Uefi.h>
end_include

begin_include
include|#
directive|include
file|<Protocol/DevicePathUtilities.h>
end_include

begin_include
include|#
directive|include
file|<Protocol/DebugPort.h>
end_include

begin_include
include|#
directive|include
file|<Protocol/DevicePathToText.h>
end_include

begin_include
include|#
directive|include
file|<Protocol/DevicePathFromText.h>
end_include

begin_include
include|#
directive|include
file|<Guid/PcAnsi.h>
end_include

begin_include
include|#
directive|include
file|<Library/DebugLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/PrintLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/BaseLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/BaseMemoryLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/MemoryAllocationLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/UefiBootServicesTableLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/DevicePathLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/PcdLib.h>
end_include

begin_include
include|#
directive|include
file|<IndustryStandard/Bluetooth.h>
end_include

begin_define
define|#
directive|define
name|IS_COMMA
parameter_list|(
name|a
parameter_list|)
value|((a) == ',')
end_define

begin_define
define|#
directive|define
name|IS_HYPHEN
parameter_list|(
name|a
parameter_list|)
value|((a) == '-')
end_define

begin_define
define|#
directive|define
name|IS_DOT
parameter_list|(
name|a
parameter_list|)
value|((a) == '.')
end_define

begin_define
define|#
directive|define
name|IS_LEFT_PARENTH
parameter_list|(
name|a
parameter_list|)
value|((a) == '(')
end_define

begin_define
define|#
directive|define
name|IS_RIGHT_PARENTH
parameter_list|(
name|a
parameter_list|)
value|((a) == ')')
end_define

begin_define
define|#
directive|define
name|IS_SLASH
parameter_list|(
name|a
parameter_list|)
value|((a) == '/')
end_define

begin_define
define|#
directive|define
name|IS_NULL
parameter_list|(
name|a
parameter_list|)
value|((a) == '\0')
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Private Data structure
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|Str
decl_stmt|;
name|UINTN
name|Count
decl_stmt|;
name|UINTN
name|Capacity
decl_stmt|;
block|}
name|POOL_PRINT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
function_decl|(
modifier|*
name|DEVICE_PATH_FROM_TEXT
function_decl|)
parameter_list|(
name|IN
name|char
modifier|*
name|Str
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|VOID
function_decl|(
modifier|*
name|DEVICE_PATH_TO_TEXT
function_decl|)
parameter_list|(
name|IN
name|OUT
name|POOL_PRINT
modifier|*
name|Str
parameter_list|,
name|IN
name|VOID
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

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Type
decl_stmt|;
name|UINT8
name|SubType
decl_stmt|;
name|DEVICE_PATH_TO_TEXT
name|Function
decl_stmt|;
block|}
name|DEVICE_PATH_TO_TEXT_TABLE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Type
decl_stmt|;
specifier|const
name|char
modifier|*
name|Text
decl_stmt|;
block|}
name|DEVICE_PATH_TO_TEXT_GENERIC_TABLE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|const
name|char
modifier|*
name|DevicePathNodeText
decl_stmt|;
name|DEVICE_PATH_FROM_TEXT
name|Function
decl_stmt|;
block|}
name|DEVICE_PATH_FROM_TEXT_TABLE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|BOOLEAN
name|ClassExist
decl_stmt|;
name|UINT8
name|Class
decl_stmt|;
name|BOOLEAN
name|SubClassExist
decl_stmt|;
name|UINT8
name|SubClass
decl_stmt|;
block|}
name|USB_CLASS_TEXT
typedef|;
end_typedef

begin_define
define|#
directive|define
name|USB_CLASS_AUDIO
value|1
end_define

begin_define
define|#
directive|define
name|USB_CLASS_CDCCONTROL
value|2
end_define

begin_define
define|#
directive|define
name|USB_CLASS_HID
value|3
end_define

begin_define
define|#
directive|define
name|USB_CLASS_IMAGE
value|6
end_define

begin_define
define|#
directive|define
name|USB_CLASS_PRINTER
value|7
end_define

begin_define
define|#
directive|define
name|USB_CLASS_MASS_STORAGE
value|8
end_define

begin_define
define|#
directive|define
name|USB_CLASS_HUB
value|9
end_define

begin_define
define|#
directive|define
name|USB_CLASS_CDCDATA
value|10
end_define

begin_define
define|#
directive|define
name|USB_CLASS_SMART_CARD
value|11
end_define

begin_define
define|#
directive|define
name|USB_CLASS_VIDEO
value|14
end_define

begin_define
define|#
directive|define
name|USB_CLASS_DIAGNOSTIC
value|220
end_define

begin_define
define|#
directive|define
name|USB_CLASS_WIRELESS
value|224
end_define

begin_define
define|#
directive|define
name|USB_CLASS_RESERVE
value|254
end_define

begin_define
define|#
directive|define
name|USB_SUBCLASS_FW_UPDATE
value|1
end_define

begin_define
define|#
directive|define
name|USB_SUBCLASS_IRDA_BRIDGE
value|2
end_define

begin_define
define|#
directive|define
name|USB_SUBCLASS_TEST
value|3
end_define

begin_define
define|#
directive|define
name|RFC_1700_UDP_PROTOCOL
value|17
end_define

begin_define
define|#
directive|define
name|RFC_1700_TCP_PROTOCOL
value|6
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
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
name|EFI_GUID
name|Guid
decl_stmt|;
name|UINT8
name|VendorDefinedData
index|[
literal|1
index|]
decl_stmt|;
block|}
name|VENDOR_DEFINED_HARDWARE_DEVICE_PATH
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
name|EFI_GUID
name|Guid
decl_stmt|;
name|UINT8
name|VendorDefinedData
index|[
literal|1
index|]
decl_stmt|;
block|}
name|VENDOR_DEFINED_MESSAGING_DEVICE_PATH
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
name|EFI_GUID
name|Guid
decl_stmt|;
name|UINT8
name|VendorDefinedData
index|[
literal|1
index|]
decl_stmt|;
block|}
name|VENDOR_DEFINED_MEDIA_DEVICE_PATH
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
name|UINT32
name|Hid
decl_stmt|;
name|UINT32
name|Uid
decl_stmt|;
name|UINT32
name|Cid
decl_stmt|;
name|CHAR8
name|HidUidCidStr
index|[
literal|3
index|]
decl_stmt|;
block|}
name|ACPI_EXTENDED_HID_DEVICE_PATH_WITH_STR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
name|UINT16
name|NetworkProtocol
decl_stmt|;
name|UINT16
name|LoginOption
decl_stmt|;
name|UINT64
name|Lun
decl_stmt|;
name|UINT16
name|TargetPortalGroupTag
decl_stmt|;
name|CHAR8
name|TargetName
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ISCSI_DEVICE_PATH_WITH_NAME
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_DEVICE_PATH_PROTOCOL
name|Header
decl_stmt|;
name|EFI_GUID
name|Guid
decl_stmt|;
name|UINT8
name|VendorDefinedData
index|[
literal|1
index|]
decl_stmt|;
block|}
name|VENDOR_DEVICE_PATH_WITH_DATA
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_ifdef
ifdef|#
directive|ifdef
name|FreeBSD
end_ifdef

begin_comment
comment|/* Remove these on FreeBSD */
end_comment

begin_comment
comment|/**   Returns the size of a device path in bytes.    This function returns the size, in bytes, of the device path data structure   specified by DevicePath including the end of device path node.   If DevicePath is NULL or invalid, then 0 is returned.    @param  DevicePath  A pointer to a device path data structure.    @retval 0           If DevicePath is NULL or invalid.   @retval Others      The size of a device path in bytes.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|UefiDevicePathLibGetDevicePathSize
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
comment|/**   Creates a new copy of an existing device path.    This function allocates space for a new copy of the device path specified by DevicePath.   If DevicePath is NULL, then NULL is returned.  If the memory is successfully   allocated, then the contents of DevicePath are copied to the newly allocated   buffer, and a pointer to that buffer is returned.  Otherwise, NULL is returned.   The memory for the new device path is allocated from EFI boot services memory.   It is the responsibility of the caller to free the memory allocated.    @param  DevicePath    A pointer to a device path data structure.    @retval NULL          DevicePath is NULL or invalid.   @retval Others        A pointer to the duplicated device path.  **/
end_comment

begin_function_decl
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|EFIAPI
name|UefiDevicePathLibDuplicateDevicePath
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
comment|/**   Creates a new device path by appending a second device path to a first device path.    This function creates a new device path by appending a copy of SecondDevicePath   to a copy of FirstDevicePath in a newly allocated buffer.  Only the end-of-device-path   device node from SecondDevicePath is retained. The newly created device path is   returned. If FirstDevicePath is NULL, then it is ignored, and a duplicate of   SecondDevicePath is returned.  If SecondDevicePath is NULL, then it is ignored,   and a duplicate of FirstDevicePath is returned. If both FirstDevicePath and   SecondDevicePath are NULL, then a copy of an end-of-device-path is returned.    If there is not enough memory for the newly allocated buffer, then NULL is returned.   The memory for the new device path is allocated from EFI boot services memory.   It is the responsibility of the caller to free the memory allocated.    @param  FirstDevicePath            A pointer to a device path data structure.   @param  SecondDevicePath           A pointer to a device path data structure.    @retval NULL      If there is not enough memory for the newly allocated buffer.   @retval NULL      If FirstDevicePath or SecondDevicePath is invalid.   @retval Others    A pointer to the new device path if success.                     Or a copy an end-of-device-path if both FirstDevicePath and SecondDevicePath are NULL.  **/
end_comment

begin_function_decl
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|EFIAPI
name|UefiDevicePathLibAppendDevicePath
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
comment|/**   Creates a new path by appending the device node to the device path.    This function creates a new device path by appending a copy of the device node   specified by DevicePathNode to a copy of the device path specified by DevicePath   in an allocated buffer. The end-of-device-path device node is moved after the   end of the appended device node.   If DevicePathNode is NULL then a copy of DevicePath is returned.   If DevicePath is NULL then a copy of DevicePathNode, followed by an end-of-device   path device node is returned.   If both DevicePathNode and DevicePath are NULL then a copy of an end-of-device-path   device node is returned.   If there is not enough memory to allocate space for the new device path, then   NULL is returned.   The memory is allocated from EFI boot services memory. It is the responsibility   of the caller to free the memory allocated.    @param  DevicePath                 A pointer to a device path data structure.   @param  DevicePathNode             A pointer to a single device path node.    @retval NULL      If there is not enough memory for the new device path.   @retval Others    A pointer to the new device path if success.                     A copy of DevicePathNode followed by an end-of-device-path node                     if both FirstDevicePath and SecondDevicePath are NULL.                     A copy of an end-of-device-path node if both FirstDevicePath                     and SecondDevicePath are NULL.  **/
end_comment

begin_function_decl
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|EFIAPI
name|UefiDevicePathLibAppendDevicePathNode
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
comment|/**   Creates a new device path by appending the specified device path instance to the specified device   path.    This function creates a new device path by appending a copy of the device path   instance specified by DevicePathInstance to a copy of the device path specified   by DevicePath in a allocated buffer.   The end-of-device-path device node is moved after the end of the appended device   path instance and a new end-of-device-path-instance node is inserted between.   If DevicePath is NULL, then a copy if DevicePathInstance is returned.   If DevicePathInstance is NULL, then NULL is returned.   If DevicePath or DevicePathInstance is invalid, then NULL is returned.   If there is not enough memory to allocate space for the new device path, then   NULL is returned.   The memory is allocated from EFI boot services memory. It is the responsibility   of the caller to free the memory allocated.    @param  DevicePath                 A pointer to a device path data structure.   @param  DevicePathInstance         A pointer to a device path instance.    @return A pointer to the new device path.  **/
end_comment

begin_function_decl
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|EFIAPI
name|UefiDevicePathLibAppendDevicePathInstance
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
comment|/**   Creates a copy of the current device path instance and returns a pointer to the next device path   instance.    This function creates a copy of the current device path instance. It also updates   DevicePath to point to the next device path instance in the device path (or NULL   if no more) and updates Size to hold the size of the device path instance copy.   If DevicePath is NULL, then NULL is returned.   If DevicePath points to a invalid device path, then NULL is returned.   If there is not enough memory to allocate space for the new device path, then   NULL is returned.   The memory is allocated from EFI boot services memory. It is the responsibility   of the caller to free the memory allocated.   If Size is NULL, then ASSERT().    @param  DevicePath                 On input, this holds the pointer to the current                                      device path instance. On output, this holds                                      the pointer to the next device path instance                                      or NULL if there are no more device path                                      instances in the device path pointer to a                                      device path data structure.   @param  Size                       On output, this holds the size of the device                                      path instance, in bytes or zero, if DevicePath                                      is NULL.    @return A pointer to the current device path instance.  **/
end_comment

begin_function_decl
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|EFIAPI
name|UefiDevicePathLibGetNextDevicePathInstance
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
comment|/**   Creates a device node.    This function creates a new device node in a newly allocated buffer of size   NodeLength and initializes the device path node header with NodeType and NodeSubType.   The new device path node is returned.   If NodeLength is smaller than a device path header, then NULL is returned.   If there is not enough memory to allocate space for the new device path, then   NULL is returned.   The memory is allocated from EFI boot services memory. It is the responsibility   of the caller to free the memory allocated.    @param  NodeType                   The device node type for the new device node.   @param  NodeSubType                The device node sub-type for the new device node.   @param  NodeLength                 The length of the new device node.    @return The new device path.  **/
end_comment

begin_function_decl
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|EFIAPI
name|UefiDevicePathLibCreateDeviceNode
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
comment|/**   Determines if a device path is single or multi-instance.    This function returns TRUE if the device path specified by DevicePath is   multi-instance.   Otherwise, FALSE is returned.   If DevicePath is NULL or invalid, then FALSE is returned.    @param  DevicePath                 A pointer to a device path data structure.    @retval  TRUE                      DevicePath is multi-instance.   @retval  FALSE                     DevicePath is not multi-instance, or DevicePath                                      is NULL or invalid.  **/
end_comment

begin_function_decl
name|BOOLEAN
name|EFIAPI
name|UefiDevicePathLibIsDevicePathMultiInstance
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
comment|/**   Converts a device path to its text representation.    @param DevicePath      A Pointer to the device to be converted.   @param DisplayOnly     If DisplayOnly is TRUE, then the shorter text representation                          of the display node is used, where applicable. If DisplayOnly                          is FALSE, then the longer text representation of the display node                          is used.   @param AllowShortcuts  If AllowShortcuts is TRUE, then the shortcut forms of text                          representation for a device node can be used, where applicable.    @return A pointer to the allocated text representation of the device path or           NULL if DeviceNode is NULL or there was insufficient memory.  **/
end_comment

begin_function_decl
name|CHAR16
modifier|*
name|EFIAPI
name|UefiDevicePathLibConvertDevicePathToText
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
name|UefiDevicePathLibConvertDeviceNodeToText
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
name|UefiDevicePathLibConvertTextToDeviceNode
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
comment|/**   Convert text to the binary representation of a device path.     @param TextDevicePath  TextDevicePath points to the text representation of a device                          path. Conversion starts with the first character and continues                          until the first non-device node character.    @return A pointer to the allocated device path or NULL if TextDeviceNode is NULL or           there was insufficient memory.  **/
end_comment

begin_function_decl
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|EFIAPI
name|UefiDevicePathLibConvertTextToDevicePath
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|TextDevicePath
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * Small FreeBSD shim layer. Fast and lose hacks to make this code work with FreeBSD.  */
end_comment

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_define
define|#
directive|define
name|_PCD_GET_MODE_32_PcdMaximumDevicePathNodeCount
value|1000
end_define

begin_define
define|#
directive|define
name|MAX_UINTN
value|UINTPTR_MAX
end_define

begin_define
define|#
directive|define
name|AllocatePool
parameter_list|(
name|x
parameter_list|)
value|malloc(x)
end_define

begin_define
define|#
directive|define
name|AllocateZeroPool
parameter_list|(
name|x
parameter_list|)
value|calloc(1,x)
end_define

begin_define
define|#
directive|define
name|AsciiStrLen
parameter_list|(
name|s
parameter_list|)
value|strlen(s)
end_define

begin_define
define|#
directive|define
name|CopyGuid
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
value|memcpy(dst, src, sizeof(uuid_t))
end_define

begin_define
define|#
directive|define
name|CopyMem
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|l
parameter_list|)
value|memcpy(d, s, l)
end_define

begin_define
define|#
directive|define
name|FreePool
parameter_list|(
name|x
parameter_list|)
value|free(x)
end_define

begin_define
define|#
directive|define
name|LShiftU64
parameter_list|(
name|x
parameter_list|,
name|s
parameter_list|)
value|((x)<< s)
end_define

begin_define
define|#
directive|define
name|ReadUnaligned64
parameter_list|(
name|x
parameter_list|)
value|le64dec(x)
end_define

begin_define
define|#
directive|define
name|ReallocatePool
parameter_list|(
name|old
parameter_list|,
name|new
parameter_list|,
name|ptr
parameter_list|)
value|realloc(ptr, new)
end_define

begin_comment
comment|/*  * Quirky StrCmp returns 0 if equal, 1 if not. This is what the code  * expects, though that expectation is likely a bug (it casts the  * return value. EDK2's StrCmp returns values just like C's strcmp,  * but the parse code casts this to an UINTN, which is bogus. This  * definition papers over that bogusness to do the right thing.  If  * iSCSI protocol string processing is ever fixed, we can remove this  * bletcherous kludge.  */
end_comment

begin_define
define|#
directive|define
name|StrCmp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(strcmp(a, b) != 0)
end_define

begin_define
define|#
directive|define
name|StrCpyS
parameter_list|(
name|d
parameter_list|,
name|l
parameter_list|,
name|s
parameter_list|)
value|strcpy(d, s)
end_define

begin_define
define|#
directive|define
name|StrHexToUint64
parameter_list|(
name|x
parameter_list|)
value|strtoll(x, NULL, 16)
end_define

begin_define
define|#
directive|define
name|StrHexToUintn
parameter_list|(
name|x
parameter_list|)
value|strtoll(x, NULL, 16)
end_define

begin_define
define|#
directive|define
name|StrLen
parameter_list|(
name|x
parameter_list|)
value|strlen(x)
end_define

begin_define
define|#
directive|define
name|StrSize
parameter_list|(
name|x
parameter_list|)
value|(strlen(x) + 1)
end_define

begin_define
define|#
directive|define
name|StrnCatS
parameter_list|(
name|d
parameter_list|,
name|l
parameter_list|,
name|s
parameter_list|,
name|len
parameter_list|)
value|strncat(d, s, len)
end_define

begin_define
define|#
directive|define
name|StrnCmp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|n
parameter_list|)
value|strncmp(a, b, n)
end_define

begin_define
define|#
directive|define
name|StrnLenS
parameter_list|(
name|str
parameter_list|,
name|max
parameter_list|)
value|strlen(str)
end_define

begin_define
define|#
directive|define
name|Strtoi
parameter_list|(
name|x
parameter_list|)
value|strtol(x, NULL, 0)
end_define

begin_define
define|#
directive|define
name|Strtoi64
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|*(long long *)y = strtoll(x, NULL, 0)
end_define

begin_define
define|#
directive|define
name|SwapBytes64
parameter_list|(
name|u64
parameter_list|)
value|bswap64(u64)
end_define

begin_define
define|#
directive|define
name|UnicodeStrToAsciiStrS
parameter_list|(
name|src
parameter_list|,
name|dest
parameter_list|,
name|len
parameter_list|)
value|strlcpy(dest, src, len)
end_define

begin_define
define|#
directive|define
name|ZeroMem
parameter_list|(
name|p
parameter_list|,
name|l
parameter_list|)
value|memset(p, 0, l)
end_define

begin_undef
undef|#
directive|undef
name|ASSERT
end_undef

begin_define
define|#
directive|define
name|ASSERT
parameter_list|(
name|x
parameter_list|)
end_define

begin_comment
comment|/*  * Define AllocateCopyPool and others so that we "forget" about the  * previous non-static deifnition since we want these to be static  * inlines.  */
end_comment

begin_define
define|#
directive|define
name|AllocateCopyPool
value|AllocateCopyPoolFreeBSD
end_define

begin_define
define|#
directive|define
name|CompareGuid
value|CompareGuidFreeBSD
end_define

begin_define
define|#
directive|define
name|StrHexToBytes
value|StrHexToBytesFreeBSD
end_define

begin_define
define|#
directive|define
name|StrToGuid
value|StrToGuidFreeBSD
end_define

begin_define
define|#
directive|define
name|WriteUnaligned64
value|WriteUnaligned64FreeBSD
end_define

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|AllocateCopyPool
parameter_list|(
name|size_t
name|l
parameter_list|,
specifier|const
name|void
modifier|*
name|p
parameter_list|)
block|{
name|void
modifier|*
name|rv
decl_stmt|;
name|rv
operator|=
name|malloc
argument_list|(
name|l
argument_list|)
expr_stmt|;
if|if
condition|(
name|rv
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
name|memcpy
argument_list|(
name|rv
argument_list|,
name|p
argument_list|,
name|l
argument_list|)
expr_stmt|;
return|return
operator|(
name|rv
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|BOOLEAN
name|CompareGuid
parameter_list|(
specifier|const
name|GUID
modifier|*
name|g1
parameter_list|,
specifier|const
name|GUID
modifier|*
name|g2
parameter_list|)
block|{
name|uint32_t
name|ignored_status
decl_stmt|;
return|return
operator|(
name|uuid_compare
argument_list|(
operator|(
specifier|const
name|uuid_t
operator|*
operator|)
name|g1
argument_list|,
operator|(
specifier|const
name|uuid_t
operator|*
operator|)
name|g2
argument_list|,
operator|&
name|ignored_status
argument_list|)
operator|==
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|StrHexToBytes
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|size_t
name|len
parameter_list|,
name|uint8_t
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|)
block|{
name|size_t
name|i
decl_stmt|;
name|char
name|hex
index|[
literal|3
index|]
decl_stmt|;
comment|/* 	 * Sanity check preconditions. 	 */
if|if
condition|(
name|buflen
operator|!=
name|len
operator|/
literal|2
operator|||
operator|(
name|len
operator|%
literal|1
operator|)
operator|==
literal|1
condition|)
return|return
literal|1
return|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|len
condition|;
name|i
operator|+=
literal|2
control|)
block|{
if|if
condition|(
operator|!
name|isxdigit
argument_list|(
name|str
index|[
name|i
index|]
argument_list|)
operator|||
operator|!
name|isxdigit
argument_list|(
name|str
index|[
name|i
operator|+
literal|1
index|]
argument_list|)
condition|)
return|return
literal|1
return|;
name|hex
index|[
literal|0
index|]
operator|=
name|str
index|[
name|i
index|]
expr_stmt|;
name|hex
index|[
literal|1
index|]
operator|=
name|str
index|[
name|i
operator|+
literal|1
index|]
expr_stmt|;
name|hex
index|[
literal|2
index|]
operator|=
literal|'\0'
expr_stmt|;
name|buf
index|[
name|i
operator|/
literal|2
index|]
operator|=
name|strtol
argument_list|(
name|hex
argument_list|,
name|NULL
argument_list|,
literal|16
argument_list|)
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|StrToGuid
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|GUID
modifier|*
name|guid
parameter_list|)
block|{
name|uint32_t
name|status
decl_stmt|;
name|uuid_from_string
argument_list|(
name|str
argument_list|,
operator|(
name|uuid_t
operator|*
operator|)
name|guid
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|WriteUnaligned64
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
name|memcpy
argument_list|(
name|ptr
argument_list|,
operator|&
name|val
argument_list|,
sizeof|sizeof
argument_list|(
name|val
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Hack to allow converting %g to %s in printfs. Hack because  * it's single entry, uses a static buffer, etc. Sufficient for  * the day for this file though. IF you ever have to convert  * two %g's in one format, punt. Did I mention this was super lame.  * Not to mention it's name.... Also, the error GUID is horrific.  */
end_comment

begin_function
specifier|static
specifier|inline
specifier|const
name|char
modifier|*
name|guid_str
parameter_list|(
specifier|const
name|GUID
modifier|*
name|g
parameter_list|)
block|{
specifier|static
name|char
name|buf
index|[
literal|36
operator|+
literal|1
index|]
decl_stmt|;
name|char
modifier|*
name|str
init|=
name|NULL
decl_stmt|;
name|int32_t
name|ignored_status
decl_stmt|;
name|uuid_to_string
argument_list|(
operator|(
specifier|const
name|uuid_t
operator|*
operator|)
name|g
argument_list|,
operator|&
name|str
argument_list|,
operator|&
name|ignored_status
argument_list|)
expr_stmt|;
if|if
condition|(
name|str
operator|!=
name|NULL
condition|)
name|strlcpy
argument_list|(
name|buf
argument_list|,
name|str
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|strlcpy
argument_list|(
name|buf
argument_list|,
literal|"groot-cannot-decode-guid-groot-smash"
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|)
expr_stmt|;
comment|/* ^^^^^^^ 36 characters ^^^^^^^ */
name|free
argument_list|(
name|str
argument_list|)
expr_stmt|;
return|return
name|buf
return|;
block|}
end_function

begin_define
define|#
directive|define
name|G
parameter_list|(
name|x
parameter_list|)
value|guid_str((const GUID *)(const void *)x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|GLOBAL_REMOVE_IF_UNREFERENCED
end_undef

begin_define
define|#
directive|define
name|GLOBAL_REMOVE_IF_UNREFERENCED
value|static
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

