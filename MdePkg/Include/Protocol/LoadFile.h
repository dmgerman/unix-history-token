begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Load File protocol as defined in the UEFI 2.0 specification.    The load file protocol exists to supports the addition of new boot devices,    and to support booting from devices that do not map well to file system.    Network boot is done via a LoadFile protocol.    UEFI 2.0 can boot from any device that produces a LoadFile protocol.  Copyright (c) 2006 - 2016, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_LOAD_FILE_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_LOAD_FILE_PROTOCOL_H__
end_define

begin_define
define|#
directive|define
name|EFI_LOAD_FILE_PROTOCOL_GUID
define|\
value|{ \     0x56EC3091, 0x954C, 0x11d2, {0x8E, 0x3F, 0x00, 0xA0, 0xC9, 0x69, 0x72, 0x3B } \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Protocol Guid defined by EFI1.1.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|LOAD_FILE_PROTOCOL
value|EFI_LOAD_FILE_PROTOCOL_GUID
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_LOAD_FILE_PROTOCOL
name|EFI_LOAD_FILE_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Backward-compatible with EFI1.1
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|EFI_LOAD_FILE_PROTOCOL
name|EFI_LOAD_FILE_INTERFACE
typedef|;
end_typedef

begin_comment
comment|/**   Causes the driver to load a specified file.    @param  This       Protocol instance pointer.   @param  FilePath   The device specific path of the file to load.   @param  BootPolicy If TRUE, indicates that the request originates from the                      boot manager is attempting to load FilePath as a boot                      selection. If FALSE, then FilePath must match as exact file                      to be loaded.   @param  BufferSize On input the size of Buffer in bytes. On output with a return                      code of EFI_SUCCESS, the amount of data transferred to                      Buffer. On output with a return code of EFI_BUFFER_TOO_SMALL,                      the size of Buffer required to retrieve the requested file.   @param  Buffer     The memory buffer to transfer the file to. IF Buffer is NULL,                      then the size of the requested file is returned in                      BufferSize.    @retval EFI_SUCCESS           The file was loaded.   @retval EFI_UNSUPPORTED       The device does not support the provided BootPolicy   @retval EFI_INVALID_PARAMETER FilePath is not a valid device path, or                                 BufferSize is NULL.   @retval EFI_NO_MEDIA          No medium was present to load the file.   @retval EFI_DEVICE_ERROR      The file was not loaded due to a device error.   @retval EFI_NO_RESPONSE       The remote system did not respond.   @retval EFI_NOT_FOUND         The file was not found.   @retval EFI_ABORTED           The file load process was manually cancelled.   @retval EFI_WARN_FILE_SYSTEM  The resulting Buffer contains UEFI-compliant file system. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_LOAD_FILE
function_decl|)
parameter_list|(
name|IN
name|EFI_LOAD_FILE_PROTOCOL
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
name|_EFI_LOAD_FILE_PROTOCOL
block|{
name|EFI_LOAD_FILE
name|LoadFile
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiLoadFileProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

