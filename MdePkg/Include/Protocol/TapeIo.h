begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI_TAPE_IO_PROTOCOL as defined in the UEFI 2.0.   Provide services to control and access a tape device.  Copyright (c) 2006 - 2010, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_TAPE_IO_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_TAPE_IO_PROTOCOL_H__
end_define

begin_define
define|#
directive|define
name|EFI_TAPE_IO_PROTOCOL_GUID
define|\
value|{ \     0x1e93e633, 0xd65a, 0x459e, {0xab, 0x84, 0x93, 0xd9, 0xec, 0x26, 0x6d, 0x18 } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_TAPE_IO_PROTOCOL
name|EFI_TAPE_IO_PROTOCOL
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_TAPE_HEADER
block|{
name|UINT64
name|Signature
decl_stmt|;
name|UINT32
name|Revision
decl_stmt|;
name|UINT32
name|BootDescSize
decl_stmt|;
name|UINT32
name|BootDescCRC
decl_stmt|;
name|EFI_GUID
name|TapeGUID
decl_stmt|;
name|EFI_GUID
name|TapeType
decl_stmt|;
name|EFI_GUID
name|TapeUnique
decl_stmt|;
name|UINT32
name|BLLocation
decl_stmt|;
name|UINT32
name|BLBlocksize
decl_stmt|;
name|UINT32
name|BLFilesize
decl_stmt|;
name|CHAR8
name|OSVersion
index|[
literal|40
index|]
decl_stmt|;
name|CHAR8
name|AppVersion
index|[
literal|40
index|]
decl_stmt|;
name|CHAR8
name|CreationDate
index|[
literal|10
index|]
decl_stmt|;
name|CHAR8
name|CreationTime
index|[
literal|10
index|]
decl_stmt|;
name|CHAR8
name|SystemName
index|[
literal|256
index|]
decl_stmt|;
comment|// UTF-8
name|CHAR8
name|TapeTitle
index|[
literal|120
index|]
decl_stmt|;
comment|// UTF-8
name|CHAR8
name|pad
index|[
literal|468
index|]
decl_stmt|;
comment|// pad to 1024
block|}
name|EFI_TAPE_HEADER
typedef|;
end_typedef

begin_comment
comment|/**   Reads from the tape.    @param  This       A pointer to the EFI_TAPE_IO_PROTOCOL instance.   @param  BufferSize The size of the buffer in bytes pointed to by Buffer.   @param  Buffer     The pointer to the buffer for data to be read into.    @retval EFI_SUCCESS           Data was successfully transferred from the media.   @retval EFI_END_OF_FILE       A filemark was encountered which limited the data                                 transferred by the read operation or the head is positioned                                 just after a filemark.   @retval EFI_NO_MEDIA          No media is loaded in the device.   @retval EFI_NOT_READY         The transfer failed since the device was not ready (e.g. not                                 online). The transfer may be retried at a later time.   @retval EFI_UNSUPPORTED       The device does not support this type of transfer.   @retval EFI_TIMEOUT           The transfer failed to complete within the timeout specified.   @retval EFI_MEDIA_CHANGED     The media in the device was changed since the last access.                                 The transfer was aborted since the current position of the                                 media may be incorrect.   @retval EFI_INVALID_PARAMETER A NULL Buffer was specified with a non-zero                                 BufferSize, or the device is operating in fixed block                                 size mode and the BufferSize was not a multiple of                                 device's fixed block size   @retval EFI_DEVICE_ERROR      A device error occurred while attempting to transfer data                                 from the media.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TAPE_READ
function_decl|)
parameter_list|(
name|IN
name|EFI_TAPE_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
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
comment|/**   Writes to the tape.    @param  This       A pointer to the EFI_TAPE_IO_PROTOCOL instance.   @param  BufferSize Size of the buffer in bytes pointed to by Buffer.   @param  Buffer     The pointer to the buffer for data to be written from.    @retval EFI_SUCCESS           Data was successfully transferred to the media.   @retval EFI_END_OF_MEDIA      The logical end of media has been reached. Data may have                                 been successfully transferred to the media.   @retval EFI_NO_MEDIA          No media is loaded in the device.   @retval EFI_NOT_READY         The transfer failed since the device was not ready (e.g. not                                 online). The transfer may be retried at a later time.   @retval EFI_UNSUPPORTED       The device does not support this type of transfer.   @retval EFI_TIMEOUT           The transfer failed to complete within the timeout specified.   @retval EFI_MEDIA_CHANGED     The media in the device was changed since the last access.                                 The transfer was aborted since the current position of the                                 media may be incorrect.   @retval EFI_WRITE_PROTECTED   The media in the device is write-protected. The transfer                                 was aborted since a write cannot be completed.   @retval EFI_INVALID_PARAMETER A NULL Buffer was specified with a non-zero                                 BufferSize, or the device is operating in fixed block                                 size mode and the BufferSize was not a multiple of                                 device's fixed block size   @retval EFI_DEVICE_ERROR      A device error occurred while attempting to transfer data                                 from the media.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TAPE_WRITE
function_decl|)
parameter_list|(
name|IN
name|EFI_TAPE_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINTN
modifier|*
name|BufferSize
parameter_list|,
name|IN
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Rewinds the tape.    @param  This A pointer to the EFI_TAPE_IO_PROTOCOL instance.    @retval EFI_SUCCESS      The media was successfully repositioned.   @retval EFI_NO_MEDIA     No media is loaded in the device.   @retval EFI_NOT_READY    Repositioning the media failed since the device was not                            ready (e.g. not online). The transfer may be retried at a later time.   @retval EFI_UNSUPPORTED  The device does not support this type of media repositioning.   @retval EFI_TIMEOUT      Repositioning of the media did not complete within the timeout specified.   @retval EFI_DEVICE_ERROR A device error occurred while attempting to reposition the media.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TAPE_REWIND
function_decl|)
parameter_list|(
name|IN
name|EFI_TAPE_IO_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Positions the tape.    @param  This      A pointer to the EFI_TAPE_IO_PROTOCOL instance.   @param  Direction Direction and number of data blocks or filemarks to space over on media.   @param  Type      Type of mark to space over on media.                     The following Type marks are mandatory:                     BLOCK type    : 0                      FILEMARK type : 1    @retval EFI_SUCCESS       The media was successfully repositioned.   @retval EFI_END_OF_MEDIA  Beginning or end of media was reached before the                             indicated number of data blocks or filemarks were found.   @retval EFI_NO_MEDIA      No media is loaded in the device.   @retval EFI_NOT_READY     The reposition failed since the device was not ready (e.g. not                             online). The reposition may be retried at a later time.   @retval EFI_UNSUPPORTED   The device does not support this type of repositioning.   @retval EFI_TIMEOUT       The repositioning failed to complete within the timeout specified.   @retval EFI_MEDIA_CHANGED The media in the device was changed since the last access.                             Repositioning the media was aborted since the current                             position of the media may be incorrect.   @retval EFI_DEVICE_ERROR  A device error occurred while attempting to reposition the media.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TAPE_SPACE
function_decl|)
parameter_list|(
name|IN
name|EFI_TAPE_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|INTN
name|Direction
parameter_list|,
name|IN
name|UINTN
name|Type
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Writes filemarks to the media.    @param  This  A pointer to the EFI_TAPE_IO_PROTOCOL instance.   @param  Count Number of filemarks to write to the media.    @retval EFI_SUCCESS       Data was successfully transferred from the media.   @retval EFI_NO_MEDIA      No media is loaded in the device.   @retval EFI_NOT_READY     The transfer failed since the device was not ready (e.g. not                             online). The transfer may be retried at a later time.   @retval EFI_UNSUPPORTED   The device does not support this type of repositioning.   @retval EFI_TIMEOUT       The transfer failed to complete within the timeout specified.   @retval EFI_MEDIA_CHANGED The media in the device was changed since the last access.                             The transfer was aborted since the current position of the                             media may be incorrect.   @retval EFI_DEVICE_ERROR  A device error occurred while attempting to transfer data from the media.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TAPE_WRITEFM
function_decl|)
parameter_list|(
name|IN
name|EFI_TAPE_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINTN
name|Count
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Resets the tape device.    @param  This                 A pointer to the EFI_TAPE_IO_PROTOCOL instance.   @param  ExtendedVerification Indicates whether the parent bus should also be reset.    @retval  EFI_SUCCESS      The bus and/or device were successfully reset.   @retval  EFI_NO_MEDIA     No media is loaded in the device.   @retval  EFI_NOT_READY    The reset failed since the device and/or bus was not ready.                             The reset may be retried at a later time.   @retval  EFI_UNSUPPORTED  The device does not support this type of reset.   @retval  EFI_TIMEOUT      The reset did not complete within the timeout allowed.   @retval  EFI_DEVICE_ERROR A device error occurred while attempting to reset the bus and/or device.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_TAPE_RESET
function_decl|)
parameter_list|(
name|IN
name|EFI_TAPE_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|BOOLEAN
name|ExtendedVerification
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_TAPE_IO_PROTOCOL provides basic sequential operations for tape devices.
end_comment

begin_comment
comment|/// These include read, write, rewind, space, write filemarks and reset functions.
end_comment

begin_comment
comment|/// Per this specification, a boot application uses the services of this protocol
end_comment

begin_comment
comment|/// to load the bootloader image from tape.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_TAPE_IO_PROTOCOL
block|{
name|EFI_TAPE_READ
name|TapeRead
decl_stmt|;
name|EFI_TAPE_WRITE
name|TapeWrite
decl_stmt|;
name|EFI_TAPE_REWIND
name|TapeRewind
decl_stmt|;
name|EFI_TAPE_SPACE
name|TapeSpace
decl_stmt|;
name|EFI_TAPE_WRITEFM
name|TapeWriteFM
decl_stmt|;
name|EFI_TAPE_RESET
name|TapeReset
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiTapeIoProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

