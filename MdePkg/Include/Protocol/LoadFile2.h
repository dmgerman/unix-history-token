begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Load File protocol as defined in the UEFI 2.0 specification.    Load file protocol exists to supports the addition of new boot devices,    and to support booting from devices that do not map well to file system.    Network boot is done via a LoadFile protocol.    UEFI 2.0 can boot from any device that produces a LoadFile protocol.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_LOAD_FILE2_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_LOAD_FILE2_PROTOCOL_H__
end_define

begin_define
define|#
directive|define
name|EFI_LOAD_FILE2_PROTOCOL_GUID
define|\
value|{ \     0x4006c0c1, 0xfcb3, 0x403e, {0x99, 0x6d, 0x4a, 0x6c, 0x87, 0x24, 0xe0, 0x6d } \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Protocol Guid defined by UEFI2.1.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|LOAD_FILE2_PROTOCOL
value|EFI_LOAD_FILE2_PROTOCOL_GUID
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_LOAD_FILE2_PROTOCOL
name|EFI_LOAD_FILE2_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   Causes the driver to load a specified file.    @param  This       Protocol instance pointer.   @param  FilePath   The device specific path of the file to load.   @param  BootPolicy Should always be FALSE.   @param  BufferSize On input the size of Buffer in bytes. On output with a return                      code of EFI_SUCCESS, the amount of data transferred to                      Buffer. On output with a return code of EFI_BUFFER_TOO_SMALL,                      the size of Buffer required to retrieve the requested file.   @param  Buffer     The memory buffer to transfer the file to. IF Buffer is NULL,                      then no the size of the requested file is returned in                      BufferSize.    @retval EFI_SUCCESS           The file was loaded.   @retval EFI_UNSUPPORTED       BootPolicy is TRUE.   @retval EFI_INVALID_PARAMETER FilePath is not a valid device path, or                                 BufferSize is NULL.   @retval EFI_NO_MEDIA          No medium was present to load the file.   @retval EFI_DEVICE_ERROR      The file was not loaded due to a device error.   @retval EFI_NO_RESPONSE       The remote system did not respond.   @retval EFI_NOT_FOUND         The file was not found   @retval EFI_ABORTED           The file load process was manually canceled.   @retval EFI_BUFFER_TOO_SMALL  The BufferSize is too small to read the current                                  directory entry. BufferSize has been updated with                                 the size needed to complete the request.   **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_LOAD_FILE2
function_decl|)
parameter_list|(
name|IN
name|EFI_LOAD_FILE2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|FilePath
parameter_list|,
name|IN
name|BOOLEAN
name|BootPolicy
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|BufferSize
parameter_list|,
name|IN
name|VOID
modifier|*
name|Buffer
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_LOAD_FILE_PROTOCOL is a simple protocol used to obtain files from arbitrary devices.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_LOAD_FILE2_PROTOCOL
block|{
name|EFI_LOAD_FILE2
name|LoadFile
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiLoadFile2ProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

