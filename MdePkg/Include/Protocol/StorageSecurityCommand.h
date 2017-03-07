begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI Storage Security Command Protocol as defined in UEFI 2.3.1 specification.   This protocol is used to abstract mass storage devices to allow code running in   the EFI boot services environment to send security protocol commands to mass   storage devices without specific knowledge of the type of device or controller   that manages the device.    Copyright (c) 2011, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STORAGE_SECURITY_COMMAND_H__
end_ifndef

begin_define
define|#
directive|define
name|__STORAGE_SECURITY_COMMAND_H__
end_define

begin_define
define|#
directive|define
name|EFI_STORAGE_SECURITY_COMMAND_PROTOCOL_GUID
define|\
value|{ \     0xC88B0B6D, 0x0DFC, 0x49A7, {0x9C, 0xB4, 0x49, 0x07, 0x4B, 0x4C, 0x3A, 0x78 } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_STORAGE_SECURITY_COMMAND_PROTOCOL
name|EFI_STORAGE_SECURITY_COMMAND_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   Send a security protocol command to a device that receives data and/or the result   of one or more commands sent by SendData.    The ReceiveData function sends a security protocol command to the given MediaId.   The security protocol command sent is defined by SecurityProtocolId and contains   the security protocol specific data SecurityProtocolSpecificData. The function   returns the data from the security protocol command in PayloadBuffer.    For devices supporting the SCSI command set, the security protocol command is sent   using the SECURITY PROTOCOL IN command defined in SPC-4.    For devices supporting the ATA command set, the security protocol command is sent   using one of the TRUSTED RECEIVE commands defined in ATA8-ACS if PayloadBufferSize   is non-zero.    If the PayloadBufferSize is zero, the security protocol command is sent using the   Trusted Non-Data command defined in ATA8-ACS.    If PayloadBufferSize is too small to store the available data from the security   protocol command, the function shall copy PayloadBufferSize bytes into the   PayloadBuffer and return EFI_WARN_BUFFER_TOO_SMALL.    If PayloadBuffer or PayloadTransferSize is NULL and PayloadBufferSize is non-zero,   the function shall return EFI_INVALID_PARAMETER.    If the given MediaId does not support security protocol commands, the function shall   return EFI_UNSUPPORTED. If there is no media in the device, the function returns   EFI_NO_MEDIA. If the MediaId is not the ID for the current media in the device,   the function returns EFI_MEDIA_CHANGED.    If the security protocol fails to complete within the Timeout period, the function   shall return EFI_TIMEOUT.    If the security protocol command completes without an error, the function shall   return EFI_SUCCESS. If the security protocol command completes with an error, the   function shall return EFI_DEVICE_ERROR.    @param  This                         Indicates a pointer to the calling context.   @param  MediaId                      ID of the medium to receive data from.   @param  Timeout                      The timeout, in 100ns units, to use for the execution                                        of the security protocol command. A Timeout value of 0                                        means that this function will wait indefinitely for the                                        security protocol command to execute. If Timeout is greater                                        than zero, then this function will return EFI_TIMEOUT if the                                        time required to execute the receive data command is greater than Timeout.   @param  SecurityProtocolId           The value of the "Security Protocol" parameter of                                        the security protocol command to be sent.   @param  SecurityProtocolSpecificData The value of the "Security Protocol Specific" parameter                                        of the security protocol command to be sent.   @param  PayloadBufferSize            Size in bytes of the payload data buffer.   @param  PayloadBuffer                A pointer to a destination buffer to store the security                                        protocol command specific payload data for the security                                        protocol command. The caller is responsible for having                                        either implicit or explicit ownership of the buffer.   @param  PayloadTransferSize          A pointer to a buffer to store the size in bytes of the                                        data written to the payload data buffer.    @retval EFI_SUCCESS                  The security protocol command completed successfully.   @retval EFI_WARN_BUFFER_TOO_SMALL    The PayloadBufferSize was too small to store the available                                        data from the device. The PayloadBuffer contains the truncated data.   @retval EFI_UNSUPPORTED              The given MediaId does not support security protocol commands.   @retval EFI_DEVICE_ERROR             The security protocol command completed with an error.   @retval EFI_NO_MEDIA                 There is no media in the device.   @retval EFI_MEDIA_CHANGED            The MediaId is not for the current media.   @retval EFI_INVALID_PARAMETER        The PayloadBuffer or PayloadTransferSize is NULL and                                        PayloadBufferSize is non-zero.   @retval EFI_TIMEOUT                  A timeout occurred while waiting for the security                                        protocol command to execute.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_STORAGE_SECURITY_RECEIVE_DATA
function_decl|)
parameter_list|(
name|IN
name|EFI_STORAGE_SECURITY_COMMAND_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT32
name|MediaId
parameter_list|,
name|IN
name|UINT64
name|Timeout
parameter_list|,
name|IN
name|UINT8
name|SecurityProtocolId
parameter_list|,
name|IN
name|UINT16
name|SecurityProtocolSpecificData
parameter_list|,
name|IN
name|UINTN
name|PayloadBufferSize
parameter_list|,
name|OUT
name|VOID
modifier|*
name|PayloadBuffer
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|PayloadTransferSize
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Send a security protocol command to a device.    The SendData function sends a security protocol command containing the payload   PayloadBuffer to the given MediaId. The security protocol command sent is   defined by SecurityProtocolId and contains the security protocol specific data   SecurityProtocolSpecificData. If the underlying protocol command requires a   specific padding for the command payload, the SendData function shall add padding   bytes to the command payload to satisfy the padding requirements.    For devices supporting the SCSI command set, the security protocol command is sent   using the SECURITY PROTOCOL OUT command defined in SPC-4.    For devices supporting the ATA command set, the security protocol command is sent   using one of the TRUSTED SEND commands defined in ATA8-ACS if PayloadBufferSize   is non-zero. If the PayloadBufferSize is zero, the security protocol command is   sent using the Trusted Non-Data command defined in ATA8-ACS.    If PayloadBuffer is NULL and PayloadBufferSize is non-zero, the function shall   return EFI_INVALID_PARAMETER.    If the given MediaId does not support security protocol commands, the function   shall return EFI_UNSUPPORTED. If there is no media in the device, the function   returns EFI_NO_MEDIA. If the MediaId is not the ID for the current media in the   device, the function returns EFI_MEDIA_CHANGED.    If the security protocol fails to complete within the Timeout period, the function   shall return EFI_TIMEOUT.    If the security protocol command completes without an error, the function shall return   EFI_SUCCESS. If the security protocol command completes with an error, the function   shall return EFI_DEVICE_ERROR.    @param  This                         Indicates a pointer to the calling context.   @param  MediaId                      ID of the medium to receive data from.   @param  Timeout                      The timeout, in 100ns units, to use for the execution                                        of the security protocol command. A Timeout value of 0                                        means that this function will wait indefinitely for the                                        security protocol command to execute. If Timeout is greater                                        than zero, then this function will return EFI_TIMEOUT if the                                         time required to execute the receive data command is greater than Timeout.   @param  SecurityProtocolId           The value of the "Security Protocol" parameter of                                        the security protocol command to be sent.   @param  SecurityProtocolSpecificData The value of the "Security Protocol Specific" parameter                                        of the security protocol command to be sent.   @param  PayloadBufferSize            Size in bytes of the payload data buffer.   @param  PayloadBuffer                A pointer to a destination buffer to store the security                                        protocol command specific payload data for the security                                        protocol command.    @retval EFI_SUCCESS                  The security protocol command completed successfully.   @retval EFI_UNSUPPORTED              The given MediaId does not support security protocol commands.   @retval EFI_DEVICE_ERROR             The security protocol command completed with an error.   @retval EFI_NO_MEDIA                 There is no media in the device.   @retval EFI_MEDIA_CHANGED            The MediaId is not for the current media.   @retval EFI_INVALID_PARAMETER        The PayloadBuffer is NULL and PayloadBufferSize is non-zero.   @retval EFI_TIMEOUT                  A timeout occurred while waiting for the security                                        protocol command to execute.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_STORAGE_SECURITY_SEND_DATA
function_decl|)
parameter_list|(
name|IN
name|EFI_STORAGE_SECURITY_COMMAND_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT32
name|MediaId
parameter_list|,
name|IN
name|UINT64
name|Timeout
parameter_list|,
name|IN
name|UINT8
name|SecurityProtocolId
parameter_list|,
name|IN
name|UINT16
name|SecurityProtocolSpecificData
parameter_list|,
name|IN
name|UINTN
name|PayloadBufferSize
parameter_list|,
name|IN
name|VOID
modifier|*
name|PayloadBuffer
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_STORAGE_SECURITY_COMMAND_PROTOCOL is used to send security protocol
end_comment

begin_comment
comment|/// commands to a mass storage device. Two types of security protocol commands
end_comment

begin_comment
comment|/// are supported. SendData sends a command with data to a device. ReceiveData
end_comment

begin_comment
comment|/// sends a command that receives data and/or the result of one or more commands
end_comment

begin_comment
comment|/// sent by SendData.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The security protocol command formats supported shall be based on the definition
end_comment

begin_comment
comment|/// of the SECURITY PROTOCOL IN and SECURITY PROTOCOL OUT commands defined in SPC-4.
end_comment

begin_comment
comment|/// If the device uses the SCSI command set, no translation is needed in the firmware
end_comment

begin_comment
comment|/// and the firmware can package the parameters into a SECURITY PROTOCOL IN or SECURITY
end_comment

begin_comment
comment|/// PROTOCOL OUT command and send the command to the device. If the device uses a
end_comment

begin_comment
comment|/// non-SCSI command set, the firmware shall map the command and data payload to the
end_comment

begin_comment
comment|/// corresponding command and payload format defined in the non-SCSI command set
end_comment

begin_comment
comment|/// (for example, TRUSTED RECEIVE and TRUSTED SEND in ATA8-ACS).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The firmware shall automatically add an EFI_STORAGE_SECURITY_COMMAND_PROTOCOL
end_comment

begin_comment
comment|/// for any storage devices detected during system boot that support SPC-4, ATA8-ACS
end_comment

begin_comment
comment|/// or their successors.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_STORAGE_SECURITY_COMMAND_PROTOCOL
block|{
name|EFI_STORAGE_SECURITY_RECEIVE_DATA
name|ReceiveData
decl_stmt|;
name|EFI_STORAGE_SECURITY_SEND_DATA
name|SendData
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiStorageSecurityCommandProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

