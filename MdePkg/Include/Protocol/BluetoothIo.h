begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI Bluetooth IO Service Binding Protocol as defined in UEFI 2.5.   EFI Bluetooth IO Protocol as defined in UEFI 2.5.   The EFI Bluetooth IO Service Binding Protocol is used to locate EFI Bluetooth IO Protocol drivers to    create and destroy child of the driver to communicate with other Bluetooth device by using Bluetooth IO protocol.    Copyright (c) 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials are licensed and made available under    the terms and conditions of the BSD License that accompanies this distribution.     The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.                                                  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:             This Protocol is introduced in UEFI Specification 2.5  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_BLUETOOTH_IO_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_BLUETOOTH_IO_PROTOCOL_H__
end_define

begin_include
include|#
directive|include
file|<IndustryStandard/Bluetooth.h>
end_include

begin_define
define|#
directive|define
name|EFI_BLUETOOTH_IO_SERVICE_BINDING_PROTOCOL_GUID
define|\
value|{ \     0x388278d3, 0x7b85, 0x42f0, { 0xab, 0xa9, 0xfb, 0x4b, 0xfd, 0x69, 0xf5, 0xab   } \   }
end_define

begin_define
define|#
directive|define
name|EFI_BLUETOOTH_IO_PROTOCOL_GUID
define|\
value|{ \     0x467313de, 0x4e30, 0x43f1, { 0x94, 0x3e, 0x32, 0x3f, 0x89, 0x84, 0x5d, 0xb5  } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_BLUETOOTH_IO_PROTOCOL
name|EFI_BLUETOOTH_IO_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_BLUETOOTH_DEVICE_INFO
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The version of the structure
comment|///
name|UINT32
name|Version
decl_stmt|;
comment|///
comment|/// 48bit Bluetooth device address.
comment|///
name|BLUETOOTH_ADDRESS
name|BD_ADDR
decl_stmt|;
comment|///
comment|/// Bluetooth PageScanRepetitionMode. See Bluetooth specification for detail.
comment|///
name|UINT8
name|PageScanRepetitionMode
decl_stmt|;
comment|///
comment|/// Bluetooth ClassOfDevice. See Bluetooth specification for detail.
comment|///
name|BLUETOOTH_CLASS_OF_DEVICE
name|ClassOfDevice
decl_stmt|;
comment|///
comment|/// Bluetooth CloseOffset. See Bluetooth specification for detail.
comment|///
name|UINT16
name|ClockOffset
decl_stmt|;
comment|///
comment|/// Bluetooth RSSI. See Bluetooth specification for detail.
comment|///
name|UINT8
name|RSSI
decl_stmt|;
comment|///
comment|/// Bluetooth ExtendedInquiryResponse. See Bluetooth specification for detail.
comment|///
name|UINT8
name|ExtendedInquiryResponse
index|[
literal|240
index|]
decl_stmt|;
block|}
name|EFI_BLUETOOTH_DEVICE_INFO
typedef|;
end_typedef

begin_comment
comment|/**   Get Bluetooth device information.    @param  This            Pointer to the EFI_BLUETOOTH_IO_PROTOCOL instance.   @param  DeviceInfoSize  A pointer to the size, in bytes, of the DeviceInfo buffer.   @param  DeviceInfo      A pointer to a callee allocated buffer that returns Bluetooth device information.    @retval EFI_SUCCESS           The Bluetooth device information is returned successfully.   @retval EFI_DEVICE_ERROR      A hardware error occurred trying to retrieve the Bluetooth device information.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLUETOOTH_IO_GET_DEVICE_INFO
function_decl|)
parameter_list|(
name|IN
name|EFI_BLUETOOTH_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|DeviceInfoSize
parameter_list|,
name|OUT
name|VOID
modifier|*
modifier|*
name|DeviceInfo
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Get Bluetooth SDP information.    @param  This            Pointer to the EFI_BLUETOOTH_IO_PROTOCOL instance.   @param  SdpInfoSize     A pointer to the size, in bytes, of the SdpInfo buffer.   @param  SdpInfo         A pointer to a callee allocated buffer that returns Bluetooth SDP information.    @retval EFI_SUCCESS           The Bluetooth device information is returned successfully.   @retval EFI_DEVICE_ERROR      A hardware error occurred trying to retrieve the Bluetooth SDP information.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLUETOOTH_IO_GET_SDP_INFO
function_decl|)
parameter_list|(
name|IN
name|EFI_BLUETOOTH_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|SdpInfoSize
parameter_list|,
name|OUT
name|VOID
modifier|*
modifier|*
name|SdpInfo
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Send L2CAP message (including L2CAP header).    @param  This            Pointer to the EFI_BLUETOOTH_IO_PROTOCOL instance.   @param  BufferSize      On input, indicates the size, in bytes, of the data buffer specified by Buffer.                            On output, indicates the amount of data actually transferred.   @param  Buffer          A pointer to the buffer of data that will be transmitted to Bluetooth L2CAP layer.   @param  Timeout         Indicating the transfer should be completed within this time frame. The units are in                            milliseconds. If Timeout is 0, then the caller must wait for the function to be completed                            until EFI_SUCCESS or EFI_DEVICE_ERROR is returned.    @retval EFI_SUCCESS             The L2CAP message is sent successfully.   @retval EFI_INVALID_PARAMETER   One or more of the following conditions is TRUE:                                   - BufferSize is NULL.                                   - *BufferSize is 0.                                   - Buffer is NULL.   @retval EFI_TIMEOUT             Sending L2CAP message fail due to timeout.   @retval EFI_DEVICE_ERROR        Sending L2CAP message fail due to host controller or device error.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLUETOOTH_IO_L2CAP_RAW_SEND
function_decl|)
parameter_list|(
name|IN
name|EFI_BLUETOOTH_IO_PROTOCOL
modifier|*
name|This
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
parameter_list|,
name|IN
name|UINTN
name|Timeout
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Receive L2CAP message (including L2CAP header).    @param  This            Pointer to the EFI_BLUETOOTH_IO_PROTOCOL instance.   @param  BufferSize      On input, indicates the size, in bytes, of the data buffer specified by Buffer.                            On output, indicates the amount of data actually transferred.   @param  Buffer          A pointer to the buffer of data that will be received from Bluetooth L2CAP layer.   @param  Timeout         Indicating the transfer should be completed within this time frame. The units are in                            milliseconds. If Timeout is 0, then the caller must wait for the function to be completed                            until EFI_SUCCESS or EFI_DEVICE_ERROR is returned.    @retval EFI_SUCCESS             The L2CAP message is received successfully.   @retval EFI_INVALID_PARAMETER   One or more of the following conditions is TRUE:                                   - BufferSize is NULL.                                   - *BufferSize is 0.                                   - Buffer is NULL.   @retval EFI_TIMEOUT             Receiving L2CAP message fail due to timeout.   @retval EFI_DEVICE_ERROR        Receiving L2CAP message fail due to host controller or device error.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLUETOOTH_IO_L2CAP_RAW_RECEIVE
function_decl|)
parameter_list|(
name|IN
name|EFI_BLUETOOTH_IO_PROTOCOL
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
parameter_list|,
name|IN
name|UINTN
name|Timeout
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Callback function, it is called when asynchronous transfer is completed.    @param  ChannelID         Bluetooth L2CAP message channel ID.   @param  Data              Data received via asynchronous transfer.   @param  DataLength        The length of Data in bytes, received via asynchronous transfer.   @param  Context           Context passed from asynchronous transfer request.    @retval EFI_SUCCESS       The callback function complete successfully.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLUETOOTH_IO_ASYNC_FUNC_CALLBACK
function_decl|)
parameter_list|(
name|IN
name|UINT16
name|ChannelID
parameter_list|,
name|IN
name|VOID
modifier|*
name|Data
parameter_list|,
name|IN
name|UINTN
name|DataLength
parameter_list|,
name|IN
name|VOID
modifier|*
name|Context
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Receive L2CAP message (including L2CAP header) in non-blocking way.    @param  This            Pointer to the EFI_BLUETOOTH_IO_PROTOCOL instance.   @param  IsNewTransfer   If TRUE, a new transfer will be submitted. If FALSE, the request is deleted.   @param  PollingInterval Indicates the periodic rate, in milliseconds, that the transfer is to be executed.   @param  DataLength      Specifies the length, in bytes, of the data to be received.   @param  Callback        The callback function. This function is called if the asynchronous transfer is                            completed.   @param  Context         Data passed into Callback function. This is optional parameter and may be NULL.       @retval EFI_SUCCESS             The L2CAP asynchronous receive request is submitted successfully.   @retval EFI_INVALID_PARAMETER   One or more of the following conditions is TRUE:                                   - DataLength is 0.                                   - If IsNewTransfer is TRUE, and an asynchronous receive request already exists.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLUETOOTH_IO_L2CAP_RAW_ASYNC_RECEIVE
function_decl|)
parameter_list|(
name|IN
name|EFI_BLUETOOTH_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|BOOLEAN
name|IsNewTransfer
parameter_list|,
name|IN
name|UINTN
name|PollingInterval
parameter_list|,
name|IN
name|UINTN
name|DataLength
parameter_list|,
name|IN
name|EFI_BLUETOOTH_IO_ASYNC_FUNC_CALLBACK
name|Callback
parameter_list|,
name|IN
name|VOID
modifier|*
name|Context
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Send L2CAP message (excluding L2CAP header) to a specific channel.    @param  This            Pointer to the EFI_BLUETOOTH_IO_PROTOCOL instance.   @param  Handle          A handle created by EFI_BLUETOOTH_IO_PROTOCOL.L2CapConnect indicates which channel to send.   @param  BufferSize      On input, indicates the size, in bytes, of the data buffer specified by Buffer.                            On output, indicates the amount of data actually transferred.   @param  Buffer          A pointer to the buffer of data that will be transmitted to Bluetooth L2CAP layer.   @param  Timeout         Indicating the transfer should be completed within this time frame. The units are in                            milliseconds. If Timeout is 0, then the caller must wait for the function to be completed                            until EFI_SUCCESS or EFI_DEVICE_ERROR is returned.    @retval EFI_SUCCESS             The L2CAP message is sent successfully.   @retval EFI_NOT_FOUND           Handle is invalid or not found.   @retval EFI_INVALID_PARAMETER   One or more of the following conditions is TRUE:                                   - BufferSize is NULL.                                   - *BufferSize is 0.                                   - Buffer is NULL.   @retval EFI_TIMEOUT             Sending L2CAP message fail due to timeout.   @retval EFI_DEVICE_ERROR        Sending L2CAP message fail due to host controller or device error.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLUETOOTH_IO_L2CAP_SEND
function_decl|)
parameter_list|(
name|IN
name|EFI_BLUETOOTH_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|Handle
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
parameter_list|,
name|IN
name|UINTN
name|Timeout
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Receive L2CAP message (excluding L2CAP header) from a specific channel.    @param  This            Pointer to the EFI_BLUETOOTH_IO_PROTOCOL instance.   @param  Handle          A handle created by EFI_BLUETOOTH_IO_PROTOCOL.L2CapConnect indicates which channel to receive.   @param  BufferSize      Indicates the size, in bytes, of the data buffer specified by Buffer.   @param  Buffer          A pointer to the buffer of data that will be received from Bluetooth L2CAP layer.   @param  Timeout         Indicating the transfer should be completed within this time frame. The units are in                            milliseconds. If Timeout is 0, then the caller must wait for the function to be completed                            until EFI_SUCCESS or EFI_DEVICE_ERROR is returned.    @retval EFI_SUCCESS             The L2CAP message is received successfully.   @retval EFI_NOT_FOUND           Handle is invalid or not found.   @retval EFI_INVALID_PARAMETER   One or more of the following conditions is TRUE:                                   - BufferSize is NULL.                                   - *BufferSize is 0.                                   - Buffer is NULL.   @retval EFI_TIMEOUT             Receiving L2CAP message fail due to timeout.   @retval EFI_DEVICE_ERROR        Receiving L2CAP message fail due to host controller or device error.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLUETOOTH_IO_L2CAP_RECEIVE
function_decl|)
parameter_list|(
name|IN
name|EFI_BLUETOOTH_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|Handle
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|BufferSize
parameter_list|,
name|OUT
name|VOID
modifier|*
modifier|*
name|Buffer
parameter_list|,
name|IN
name|UINTN
name|Timeout
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Callback function, it is called when asynchronous transfer is completed.    @param  Data              Data received via asynchronous transfer.   @param  DataLength        The length of Data in bytes, received via asynchronous transfer.   @param  Context           Context passed from asynchronous transfer request.    @retval EFI_SUCCESS       The callback function complete successfully.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLUETOOTH_IO_CHANNEL_SERVICE_CALLBACK
function_decl|)
parameter_list|(
name|IN
name|VOID
modifier|*
name|Data
parameter_list|,
name|IN
name|UINTN
name|DataLength
parameter_list|,
name|IN
name|VOID
modifier|*
name|Context
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Receive L2CAP message (excluding L2CAP header) in non-blocking way from a specific channel.    @param  This            Pointer to the EFI_BLUETOOTH_IO_PROTOCOL instance.   @param  Handel          A handle created by EFI_BLUETOOTH_IO_PROTOCOL.L2CapConnect indicates which channel to receive.   @param  Callback        The callback function. This function is called if the asynchronous transfer is                            completed.   @param  Context         Data passed into Callback function. This is optional parameter and may be NULL.       @retval EFI_SUCCESS             The L2CAP asynchronous receive request is submitted successfully.   @retval EFI_NOT_FOUND           Handle is invalid or not found.   @retval EFI_INVALID_PARAMETER   One or more of the following conditions is TRUE:                                   - DataLength is 0.                                   - If an asynchronous receive request already exists on same Handle.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLUETOOTH_IO_L2CAP_ASYNC_RECEIVE
function_decl|)
parameter_list|(
name|IN
name|EFI_BLUETOOTH_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|Handle
parameter_list|,
name|IN
name|EFI_BLUETOOTH_IO_CHANNEL_SERVICE_CALLBACK
name|Callback
parameter_list|,
name|IN
name|VOID
modifier|*
name|Context
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Do L2CAP connection.    @param  This            Pointer to the EFI_BLUETOOTH_IO_PROTOCOL instance.   @param  Handel          A handle to indicate this L2CAP connection.   @param  Psm             Bluetooth PSM. See Bluetooth specification for detail.   @param  Mtu             Bluetooth MTU. See Bluetooth specification for detail.   @param  Callback        The callback function. This function is called whenever there is message received                            in this channel.   @param  Context         Data passed into Callback function. This is optional parameter and may be NULL.      @retval EFI_SUCCESS             The Bluetooth L2CAP layer connection is created successfully.   @retval EFI_INVALID_PARAMETER   One or more of the following conditions is TRUE:                                   - Handle is NULL.   @retval EFI_DEVICE_ERROR        A hardware error occurred trying to do Bluetooth L2CAP connection.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLUETOOTH_IO_L2CAP_CONNECT
function_decl|)
parameter_list|(
name|IN
name|EFI_BLUETOOTH_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|EFI_HANDLE
modifier|*
name|Handle
parameter_list|,
name|IN
name|UINT16
name|Psm
parameter_list|,
name|IN
name|UINT16
name|Mtu
parameter_list|,
name|IN
name|EFI_BLUETOOTH_IO_CHANNEL_SERVICE_CALLBACK
name|Callback
parameter_list|,
name|IN
name|VOID
modifier|*
name|Context
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Do L2CAP disconnection.    @param  This            Pointer to the EFI_BLUETOOTH_IO_PROTOCOL instance.   @param  Handel          A handle to indicate this L2CAP connection.      @retval EFI_SUCCESS             The Bluetooth L2CAP layer is disconnected successfully.   @retval EFI_NOT_FOUND           Handle is invalid or not found.   @retval EFI_DEVICE_ERROR        A hardware error occurred trying to do Bluetooth L2CAP disconnection.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLUETOOTH_IO_L2CAP_DISCONNECT
function_decl|)
parameter_list|(
name|IN
name|EFI_BLUETOOTH_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|Handle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Register L2CAP callback function for special channel.    @param  This            Pointer to the EFI_BLUETOOTH_IO_PROTOCOL instance.   @param  Handel          A handle to indicate this L2CAP connection.   @param  Psm             Bluetooth PSM. See Bluetooth specification for detail.   @param  Mtu             Bluetooth MTU. See Bluetooth specification for detail.   @param  Callback        The callback function. This function is called whenever there is message received                            in this channel. NULL means unregister.   @param  Context         Data passed into Callback function. This is optional parameter and may be NULL.      @retval EFI_SUCCESS             The Bluetooth L2CAP callback function is registered successfully.   @retval EFI_ALREADY_STARTED     The callback function already exists when register.   @retval EFI_NOT_FOUND           The callback function does not exist when unregister.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLUETOOTH_IO_L2CAP_REGISTER_SERVICE
function_decl|)
parameter_list|(
name|IN
name|EFI_BLUETOOTH_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|EFI_HANDLE
modifier|*
name|Handle
parameter_list|,
name|IN
name|UINT16
name|Psm
parameter_list|,
name|IN
name|UINT16
name|Mtu
parameter_list|,
name|IN
name|EFI_BLUETOOTH_IO_CHANNEL_SERVICE_CALLBACK
name|Callback
parameter_list|,
name|IN
name|VOID
modifier|*
name|Context
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This protocol provides service for Bluetooth L2CAP (Logical Link Control and Adaptation Protocol)
end_comment

begin_comment
comment|/// and SDP (Service Discovery Protocol).
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_BLUETOOTH_IO_PROTOCOL
block|{
name|EFI_BLUETOOTH_IO_GET_DEVICE_INFO
name|GetDeviceInfo
decl_stmt|;
name|EFI_BLUETOOTH_IO_GET_SDP_INFO
name|GetSdpInfo
decl_stmt|;
name|EFI_BLUETOOTH_IO_L2CAP_RAW_SEND
name|L2CapRawSend
decl_stmt|;
name|EFI_BLUETOOTH_IO_L2CAP_RAW_RECEIVE
name|L2CapRawReceive
decl_stmt|;
name|EFI_BLUETOOTH_IO_L2CAP_RAW_ASYNC_RECEIVE
name|L2CapRawAsyncReceive
decl_stmt|;
name|EFI_BLUETOOTH_IO_L2CAP_SEND
name|L2CapSend
decl_stmt|;
name|EFI_BLUETOOTH_IO_L2CAP_RECEIVE
name|L2CapReceive
decl_stmt|;
name|EFI_BLUETOOTH_IO_L2CAP_ASYNC_RECEIVE
name|L2CapAsyncReceive
decl_stmt|;
name|EFI_BLUETOOTH_IO_L2CAP_CONNECT
name|L2CapConnect
decl_stmt|;
name|EFI_BLUETOOTH_IO_L2CAP_DISCONNECT
name|L2CapDisconnect
decl_stmt|;
name|EFI_BLUETOOTH_IO_L2CAP_REGISTER_SERVICE
name|L2CapRegisterService
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiBluetoothIoServiceBindingProtocolGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiBluetoothIoProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

