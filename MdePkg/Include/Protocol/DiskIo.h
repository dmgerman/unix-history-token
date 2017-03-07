begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Disk IO protocol as defined in the UEFI 2.0 specification.    The Disk IO protocol is used to convert block oriented devices into byte   oriented devices. The Disk IO protocol is intended to layer on top of the   Block IO protocol.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DISK_IO_H__
end_ifndef

begin_define
define|#
directive|define
name|__DISK_IO_H__
end_define

begin_define
define|#
directive|define
name|EFI_DISK_IO_PROTOCOL_GUID
define|\
value|{ \     0xce345171, 0xba0b, 0x11d2, {0x8e, 0x4f, 0x0, 0xa0, 0xc9, 0x69, 0x72, 0x3b } \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Protocol GUID name defined in EFI1.1.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|DISK_IO_PROTOCOL
value|EFI_DISK_IO_PROTOCOL_GUID
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_DISK_IO_PROTOCOL
name|EFI_DISK_IO_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Protocol defined in EFI1.1.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|EFI_DISK_IO_PROTOCOL
name|EFI_DISK_IO
typedef|;
end_typedef

begin_comment
comment|/**   Read BufferSize bytes from Offset into Buffer.    @param  This                  Protocol instance pointer.   @param  MediaId               Id of the media, changes every time the media is replaced.   @param  Offset                The starting byte offset to read from   @param  BufferSize            Size of Buffer   @param  Buffer                Buffer containing read data    @retval EFI_SUCCESS           The data was read correctly from the device.   @retval EFI_DEVICE_ERROR      The device reported an error while performing the read.   @retval EFI_NO_MEDIA          There is no media in the device.   @retval EFI_MEDIA_CHNAGED     The MediaId does not matched the current device.   @retval EFI_INVALID_PARAMETER The read request contains device addresses that are not                                 valid for the device.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DISK_READ
function_decl|)
parameter_list|(
name|IN
name|EFI_DISK_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT32
name|MediaId
parameter_list|,
name|IN
name|UINT64
name|Offset
parameter_list|,
name|IN
name|UINTN
name|BufferSize
parameter_list|,
name|OUT
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Writes a specified number of bytes to a device.    @param  This       Indicates a pointer to the calling context.   @param  MediaId    ID of the medium to be written.   @param  Offset     The starting byte offset on the logical block I/O device to write.   @param  BufferSize The size in bytes of Buffer. The number of bytes to write to the device.   @param  Buffer     A pointer to the buffer containing the data to be written.    @retval EFI_SUCCESS           The data was written correctly to the device.   @retval EFI_WRITE_PROTECTED   The device can not be written to.   @retval EFI_DEVICE_ERROR      The device reported an error while performing the write.   @retval EFI_NO_MEDIA          There is no media in the device.   @retval EFI_MEDIA_CHNAGED     The MediaId does not matched the current device.   @retval EFI_INVALID_PARAMETER The write request contains device addresses that are not                                  valid for the device.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DISK_WRITE
function_decl|)
parameter_list|(
name|IN
name|EFI_DISK_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT32
name|MediaId
parameter_list|,
name|IN
name|UINT64
name|Offset
parameter_list|,
name|IN
name|UINTN
name|BufferSize
parameter_list|,
name|IN
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|EFI_DISK_IO_PROTOCOL_REVISION
value|0x00010000
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Revision defined in EFI1.1
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_DISK_IO_INTERFACE_REVISION
value|EFI_DISK_IO_PROTOCOL_REVISION
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// This protocol is used to abstract Block I/O interfaces.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_DISK_IO_PROTOCOL
block|{
comment|///
comment|/// The revision to which the disk I/O interface adheres. All future
comment|/// revisions must be backwards compatible. If a future version is not
comment|/// backwards compatible, it is not the same GUID.
comment|///
name|UINT64
name|Revision
decl_stmt|;
name|EFI_DISK_READ
name|ReadDisk
decl_stmt|;
name|EFI_DISK_WRITE
name|WriteDisk
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiDiskIoProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

