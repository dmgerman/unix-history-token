begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file      The file defines the EFI Debugport protocol.   This protocol is used by debug agent to communicate with the   remote debug host.      Copyright (c) 2006 - 2013, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DEBUG_PORT_H__
end_ifndef

begin_define
define|#
directive|define
name|__DEBUG_PORT_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// DebugPortIo protocol {EBA4E8D2-3858-41EC-A281-2647BA9660D0}
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_DEBUGPORT_PROTOCOL_GUID
define|\
value|{ \     0xEBA4E8D2, 0x3858, 0x41EC, {0xA2, 0x81, 0x26, 0x47, 0xBA, 0x96, 0x60, 0xD0 } \   }
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiDebugPortProtocolGuid
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|struct
name|_EFI_DEBUGPORT_PROTOCOL
name|EFI_DEBUGPORT_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// DebugPort member functions
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/**                                                                    Resets the debugport.        @param  This                  A pointer to the EFI_DEBUGPORT_PROTOCOL instance.                                    @retval EFI_SUCCESS           The debugport device was reset and is in usable state.   @retval EFI_DEVICE_ERROR      The debugport device could not be reset and is unusable.                                     **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DEBUGPORT_RESET
function_decl|)
parameter_list|(
name|IN
name|EFI_DEBUGPORT_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Writes data to the debugport.        @param  This                  A pointer to the EFI_DEBUGPORT_PROTOCOL instance.   @param  Timeout               The number of microseconds to wait before timing out a write operation.   @param  BufferSize            On input, the requested number of bytes of data to write. On output, the                                 number of bytes of data actually written.   @param  Buffer                A pointer to a buffer containing the data to write.                                                                      @retval EFI_SUCCESS           The data was written.   @retval EFI_DEVICE_ERROR      The device reported an error.   @retval EFI_TIMEOUT           The data write was stopped due to a timeout.                                     **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DEBUGPORT_WRITE
function_decl|)
parameter_list|(
name|IN
name|EFI_DEBUGPORT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT32
name|Timeout
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
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Reads data from the debugport.        @param  This                  A pointer to the EFI_DEBUGPORT_PROTOCOL instance.   @param  Timeout               The number of microseconds to wait before timing out a read operation.   @param  BufferSize            On input, the requested number of bytes of data to read. On output, the                                 number of bytes of data actually number of bytes                                 of data read and returned in Buffer.   @param  Buffer                A pointer to a buffer into which the data read will be saved.                                      @retval EFI_SUCCESS           The data was read.   @retval EFI_DEVICE_ERROR      The device reported an error.   @retval EFI_TIMEOUT           The operation was stopped due to a timeout or overrun.                                     **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DEBUGPORT_READ
function_decl|)
parameter_list|(
name|IN
name|EFI_DEBUGPORT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT32
name|Timeout
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
comment|/**                                                                    Checks to see if any data is available to be read from the debugport device.        @param  This                  A pointer to the EFI_DEBUGPORT_PROTOCOL instance.                                      @retval EFI_SUCCESS           At least one byte of data is available to be read.   @retval EFI_DEVICE_ERROR      The debugport device is not functioning correctly.   @retval EFI_NOT_READY         No data is available to be read.                                     **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DEBUGPORT_POLL
function_decl|)
parameter_list|(
name|IN
name|EFI_DEBUGPORT_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This protocol provides the communication link between the debug agent and the remote host.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_DEBUGPORT_PROTOCOL
block|{
name|EFI_DEBUGPORT_RESET
name|Reset
decl_stmt|;
name|EFI_DEBUGPORT_WRITE
name|Write
decl_stmt|;
name|EFI_DEBUGPORT_READ
name|Read
decl_stmt|;
name|EFI_DEBUGPORT_POLL
name|Poll
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|//
end_comment

begin_comment
comment|// DEBUGPORT variable definitions...
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_DEBUGPORT_VARIABLE_NAME
value|L"DEBUGPORT"
end_define

begin_define
define|#
directive|define
name|EFI_DEBUGPORT_VARIABLE_GUID
value|EFI_DEBUGPORT_PROTOCOL_GUID
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiDebugPortVariableGuid
decl_stmt|;
end_decl_stmt

begin_comment
comment|//
end_comment

begin_comment
comment|// DebugPort device path definitions...
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|DEVICE_PATH_MESSAGING_DEBUGPORT
value|EFI_DEBUGPORT_PROTOCOL_GUID
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiDebugPortDevicePathGuid
decl_stmt|;
end_decl_stmt

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
block|}
name|DEBUGPORT_DEVICE_PATH
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

