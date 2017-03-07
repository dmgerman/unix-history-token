begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI Bluetooth Configuration Protocol as defined in UEFI 2.5.   This protocol abstracts user interface configuration for Bluetooth device.    Copyright (c) 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials are licensed and made available under    the terms and conditions of the BSD License that accompanies this distribution.     The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.                                                  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:             This Protocol is introduced in UEFI Specification 2.5  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_BLUETOOTH_CONFIG_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_BLUETOOTH_CONFIG_PROTOCOL_H__
end_define

begin_include
include|#
directive|include
file|<IndustryStandard/Bluetooth.h>
end_include

begin_define
define|#
directive|define
name|EFI_BLUETOOTH_CONFIG_PROTOCOL_GUID
define|\
value|{ \     0x62960cf3, 0x40ff, 0x4263, { 0xa7, 0x7c, 0xdf, 0xde, 0xbd, 0x19, 0x1b, 0x4b } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_BLUETOOTH_CONFIG_PROTOCOL
name|EFI_BLUETOOTH_CONFIG_PROTOCOL
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT32
name|EFI_BLUETOOTH_CONFIG_REMOTE_DEVICE_STATE_TYPE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_BLUETOOTH_CONFIG_REMOTE_DEVICE_STATE_CONNECTED
value|0x1
end_define

begin_define
define|#
directive|define
name|EFI_BLUETOOTH_CONFIG_REMOTE_DEVICE_STATE_PAIRED
value|0x2
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_BLUETOOTH_SCAN_CALLBACK_INFORMATION
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// 48bit Bluetooth device address.
comment|///
name|BLUETOOTH_ADDRESS
name|BDAddr
decl_stmt|;
comment|///
comment|/// State of the remote deive
comment|///
name|UINT8
name|RemoteDeviceState
decl_stmt|;
comment|///
comment|/// Bluetooth ClassOfDevice. See Bluetooth specification for detail.
comment|///
name|BLUETOOTH_CLASS_OF_DEVICE
name|ClassOfDevice
decl_stmt|;
comment|///
comment|/// Remote device name
comment|///
name|UINT8
name|RemoteDeviceName
index|[
name|BLUETOOTH_HCI_COMMAND_LOCAL_READABLE_NAME_MAX_SIZE
index|]
decl_stmt|;
block|}
name|EFI_BLUETOOTH_SCAN_CALLBACK_INFORMATION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_BLUETOOTH_CONFIG_DATA_TYPE
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// Local/Remote Bluetooth device name. Data structure is zero terminated CHAR8[].
comment|///
name|EfiBluetoothConfigDataTypeDeviceName
block|,
comment|///
comment|/// Local/Remote Bluetooth device ClassOfDevice. Data structure is BLUETOOTH_CLASS_OF_DEVICE.
comment|///
name|EfiBluetoothConfigDataTypeClassOfDevice
block|,
comment|///
comment|/// Remote Bluetooth device state. Data structure is EFI_BLUETOOTH_CONFIG_REMOTE_DEVICE_STATE_TYPE.
comment|///
name|EfiBluetoothConfigDataTypeRemoteDeviceState
block|,
comment|///
comment|/// Local/Remote Bluetooth device SDP information. Data structure is UINT8[].
comment|///
name|EfiBluetoothConfigDataTypeSdpInfo
block|,
comment|///
comment|/// Local Bluetooth device address. Data structure is BLUETOOTH_ADDRESS.
comment|///
name|EfiBluetoothConfigDataTypeBDADDR
block|,
comment|///
comment|/// Local Bluetooth discoverable state. Data structure is UINT8. (Page scan and/or Inquiry scan)
comment|///
name|EfiBluetoothConfigDataTypeDiscoverable
block|,
comment|///
comment|/// Local Bluetooth controller stored paired device list. Data structure is BLUETOOTH_ADDRESS[].
comment|///
name|EfiBluetoothConfigDataTypeControllerStoredPairedDeviceList
block|,
comment|///
comment|/// Local available device list. Data structure is BLUETOOTH_ADDRESS[].
comment|///
name|EfiBluetoothConfigDataTypeAvailableDeviceList
block|,
name|EfiBluetoothConfigDataTypeMax
block|, }
name|EFI_BLUETOOTH_CONFIG_DATA_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_BLUETOOTH_PIN_CALLBACK_TYPE.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// For SSP - passkey entry. Input buffer is Passkey (4 bytes). No output buffer.
comment|/// See Bluetooth HCI command for detail.
comment|///
name|EfiBluetoothCallbackTypeUserPasskeyNotification
block|,
comment|///
comment|/// For SSP - just work and numeric comparison. Input buffer is numeric value (4 bytes).
comment|/// Output buffer is BOOLEAN (1 byte). See Bluetooth HCI command for detail.
comment|///
name|EfiBluetoothCallbackTypeUserConfirmationRequest
block|,
comment|///
comment|/// For SSP - OOB. See Bluetooth HCI command for detail.
comment|///
name|EfiBluetoothCallbackTypeOOBDataRequest
block|,
comment|///
comment|/// For legacy paring. No input buffer. Output buffer is PIN code(<= 16 bytes).
comment|/// See Bluetooth HCI command for detail.
comment|///
name|EfiBluetoothCallbackTypePinCodeRequest
block|,
name|EfiBluetoothCallbackTypeMax
block|}
name|EFI_BLUETOOTH_PIN_CALLBACK_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_BLUETOOTH_CONNECT_COMPLETE_CALLBACK_TYPE.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// This callback is called when Bluetooth receive Disconnection_Complete event. Input buffer is Event
comment|/// Parameters of Disconnection_Complete Event defined in Bluetooth specification.
comment|///
name|EfiBluetoothConnCallbackTypeDisconnected
block|,
comment|///
comment|/// This callback is called when Bluetooth receive Connection_Complete event. Input buffer is Event
comment|/// Parameters of Connection_Complete Event defined in Bluetooth specification.
comment|///
name|EfiBluetoothConnCallbackTypeConnected
block|,
comment|///
comment|/// This callback is called when Bluetooth receive Authentication_Complete event. Input buffer is Event
comment|/// Parameters of Authentication_Complete Event defined in Bluetooth specification.
comment|///
name|EfiBluetoothConnCallbackTypeAuthenticated
block|,
comment|///
comment|/// This callback is called when Bluetooth receive Encryption_Change event. Input buffer is Event
comment|/// Parameters of Encryption_Change Event defined in Bluetooth specification.
comment|///
name|EfiBluetoothConnCallbackTypeEncrypted
block|}
name|EFI_BLUETOOTH_CONNECT_COMPLETE_CALLBACK_TYPE
typedef|;
end_typedef

begin_comment
comment|/**   Initialize Bluetooth host controller and local device.    @param  This          Pointer to the EFI_BLUETOOTH_CONFIG_PROTOCOL instance.    @retval EFI_SUCCESS           The Bluetooth host controller and local device is initialized successfully.   @retval EFI_DEVICE_ERROR      A hardware error occurred trying to initialize the Bluetooth host controller                                  and local device.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLUETOOTH_CONFIG_INIT
function_decl|)
parameter_list|(
name|IN
name|EFI_BLUETOOTH_CONFIG_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Callback function, it is called if a Bluetooth device is found during scan process.    @param  This            Pointer to the EFI_BLUETOOTH_CONFIG_PROTOCOL instance.   @param  Context         Context passed from scan request.   @param  CallbackInfo    Data related to scan result. NULL CallbackInfo means scan complete.    @retval EFI_SUCCESS       The callback function complete successfully.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLUETOOTH_CONFIG_SCAN_CALLBACK_FUNCTION
function_decl|)
parameter_list|(
name|IN
name|EFI_BLUETOOTH_CONFIG_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|VOID
modifier|*
name|Context
parameter_list|,
name|IN
name|EFI_BLUETOOTH_SCAN_CALLBACK_INFORMATION
modifier|*
name|CallbackInfo
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Scan Bluetooth device.    @param  This          Pointer to the EFI_BLUETOOTH_CONFIG_PROTOCOL instance.   @param  ReScan        If TRUE, a new scan request is submitted no matter there is scan result before.                          If FALSE and there is scan result, the previous scan result is returned and no scan request                          is submitted.   @param  ScanType      Bluetooth scan type, Inquiry and/or Page. See Bluetooth specification for detail.   @param  Callback      The callback function. This function is called if a Bluetooth device is found during scan                          process.   @param  Context       Data passed into Callback function. This is optional parameter and may be NULL.    @retval EFI_SUCCESS           The Bluetooth scan request is submitted.   @retval EFI_DEVICE_ERROR      A hardware error occurred trying to scan the Bluetooth device.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLUETOOTH_CONFIG_SCAN
function_decl|)
parameter_list|(
name|IN
name|EFI_BLUETOOTH_CONFIG_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|BOOLEAN
name|ReScan
parameter_list|,
name|IN
name|UINT8
name|ScanType
parameter_list|,
name|IN
name|EFI_BLUETOOTH_CONFIG_SCAN_CALLBACK_FUNCTION
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
comment|/**   Connect a Bluetooth device.    @param  This          Pointer to the EFI_BLUETOOTH_CONFIG_PROTOCOL instance.   @param  BD_ADDR       The address of Bluetooth device to be connected.    @retval EFI_SUCCESS           The Bluetooth device is connected successfully.   @retval EFI_ALREADY_STARTED   The Bluetooth device is already connected.   @retval EFI_NOT_FOUND         The Bluetooth device is not found.   @retval EFI_DEVICE_ERROR      A hardware error occurred trying to connect the Bluetooth device.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLUETOOTH_CONFIG_CONNECT
function_decl|)
parameter_list|(
name|IN
name|EFI_BLUETOOTH_CONFIG_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|BLUETOOTH_ADDRESS
modifier|*
name|BD_ADDR
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Disconnect a Bluetooth device.    @param  This          Pointer to the EFI_BLUETOOTH_CONFIG_PROTOCOL instance.   @param  BD_ADDR       The address of Bluetooth device to be connected.   @param  Reason        Bluetooth disconnect reason. See Bluetooth specification for detail.    @retval EFI_SUCCESS           The Bluetooth device is disconnected successfully.   @retval EFI_NOT_STARTED       The Bluetooth device is not connected.   @retval EFI_NOT_FOUND         The Bluetooth device is not found.   @retval EFI_DEVICE_ERROR      A hardware error occurred trying to disconnect the Bluetooth device.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLUETOOTH_CONFIG_DISCONNECT
function_decl|)
parameter_list|(
name|IN
name|EFI_BLUETOOTH_CONFIG_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|BLUETOOTH_ADDRESS
modifier|*
name|BD_ADDR
parameter_list|,
name|IN
name|UINT8
name|Reason
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Get Bluetooth configuration data.    @param  This          Pointer to the EFI_BLUETOOTH_CONFIG_PROTOCOL instance.   @param  DataType      Configuration data type.   @param  DataSize      On input, indicates the size, in bytes, of the data buffer specified by Data.                         On output, indicates the amount of data actually returned.   @param  Data          A pointer to the buffer of data that will be returned.    @retval EFI_SUCCESS           The Bluetooth configuration data is returned successfully.   @retval EFI_INVALID_PARAMETER One or more of the following conditions is TRUE:                                 - DataSize is NULL.                                 - *DataSize is 0.                                 - Data is NULL.   @retval EFI_UNSUPPORTED       The DataType is unsupported.   @retval EFI_NOT_FOUND         The DataType is not found.   @retval EFI_BUFFER_TOO_SMALL  The buffer is too small to hold the buffer.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLUETOOTH_CONFIG_GET_DATA
function_decl|)
parameter_list|(
name|IN
name|EFI_BLUETOOTH_CONFIG_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_BLUETOOTH_CONFIG_DATA_TYPE
name|DataType
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|DataSize
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
name|Data
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Set Bluetooth configuration data.    @param  This          Pointer to the EFI_BLUETOOTH_CONFIG_PROTOCOL instance.   @param  DataType      Configuration data type.   @param  DataSize      Indicates the size, in bytes, of the data buffer specified by Data.   @param  Data          A pointer to the buffer of data that will be set.    @retval EFI_SUCCESS           The Bluetooth configuration data is set successfully.   @retval EFI_INVALID_PARAMETER One or more of the following conditions is TRUE:                                 - DataSize is 0.                                 - Data is NULL.   @retval EFI_UNSUPPORTED       The DataType is unsupported.   @retval EFI_BUFFER_TOO_SMALL  Cannot set configuration data.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLUETOOTH_CONFIG_SET_DATA
function_decl|)
parameter_list|(
name|IN
name|EFI_BLUETOOTH_CONFIG_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_BLUETOOTH_CONFIG_DATA_TYPE
name|DataType
parameter_list|,
name|IN
name|UINTN
name|DataSize
parameter_list|,
name|IN
name|VOID
modifier|*
name|Data
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Get remove Bluetooth device configuration data.    @param  This          Pointer to the EFI_BLUETOOTH_CONFIG_PROTOCOL instance.   @param  DataType      Configuration data type.   @param  BDAddr        Remote Bluetooth device address.   @param  DataSize      On input, indicates the size, in bytes, of the data buffer specified by Data.                         On output, indicates the amount of data actually returned.   @param  Data          A pointer to the buffer of data that will be returned.    @retval EFI_SUCCESS           The remote Bluetooth device configuration data is returned successfully.   @retval EFI_INVALID_PARAMETER One or more of the following conditions is TRUE:                                 - DataSize is NULL.                                 - *DataSize is 0.                                 - Data is NULL.   @retval EFI_UNSUPPORTED       The DataType is unsupported.   @retval EFI_NOT_FOUND         The DataType is not found.   @retval EFI_BUFFER_TOO_SMALL  The buffer is too small to hold the buffer.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLUETOOTH_CONFIG_GET_REMOTE_DATA
function_decl|)
parameter_list|(
name|IN
name|EFI_BLUETOOTH_CONFIG_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_BLUETOOTH_CONFIG_DATA_TYPE
name|DataType
parameter_list|,
name|IN
name|BLUETOOTH_ADDRESS
name|BDAddr
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|DataSize
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
name|Data
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   The callback function for PIN code.    @param  This                Pointer to the EFI_BLUETOOTH_CONFIG_PROTOCOL instance.   @param  Context             Context passed from registration.   @param  CallbackType        Callback type in EFI_BLUETOOTH_PIN_CALLBACK_TYPE.   @param  InputBuffer         A pointer to the buffer of data that is input from callback caller.   @param  InputBufferSize     Indicates the size, in bytes, of the data buffer specified by InputBuffer.   @param  OutputBuffer        A pointer to the buffer of data that will be output from callback callee.                                Callee allocates this buffer by using EFI Boot Service AllocatePool().   @param  OutputBufferSize    Indicates the size, in bytes, of the data buffer specified by OutputBuffer.    @retval EFI_SUCCESS   The callback function complete successfully.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLUETOOTH_CONFIG_REGISTER_PIN_CALLBACK_FUNCTION
function_decl|)
parameter_list|(
name|IN
name|EFI_BLUETOOTH_CONFIG_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|VOID
modifier|*
name|Context
parameter_list|,
name|IN
name|EFI_BLUETOOTH_PIN_CALLBACK_TYPE
name|CallbackType
parameter_list|,
name|IN
name|VOID
modifier|*
name|InputBuffer
parameter_list|,
name|IN
name|UINTN
name|InputBufferSize
parameter_list|,
name|OUT
name|VOID
modifier|*
modifier|*
name|OutputBuffer
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|OutputBufferSize
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Register PIN callback function.    @param  This          Pointer to the EFI_BLUETOOTH_CONFIG_PROTOCOL instance.   @param  Callback      The callback function. NULL means unregister.   @param  Context       Data passed into Callback function. This is optional parameter and may be NULL.    @retval EFI_SUCCESS   The PIN callback function is registered successfully.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLUETOOTH_CONFIG_REGISTER_PIN_CALLBACK
function_decl|)
parameter_list|(
name|IN
name|EFI_BLUETOOTH_CONFIG_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_BLUETOOTH_CONFIG_REGISTER_PIN_CALLBACK_FUNCTION
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
comment|/**   The callback function to get link key.    @param  This                Pointer to the EFI_BLUETOOTH_CONFIG_PROTOCOL instance.   @param  Context             Context passed from registration.   @param  BDAddr              A pointer to Bluetooth device address.   @param  LinkKey             A pointer to the buffer of link key.    @retval EFI_SUCCESS   The callback function complete successfully.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLUETOOTH_CONFIG_REGISTER_GET_LINK_KEY_CALLBACK_FUNCTION
function_decl|)
parameter_list|(
name|IN
name|EFI_BLUETOOTH_CONFIG_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|VOID
modifier|*
name|Context
parameter_list|,
name|IN
name|BLUETOOTH_ADDRESS
modifier|*
name|BDAddr
parameter_list|,
name|OUT
name|UINT8
name|LinkKey
index|[
name|BLUETOOTH_HCI_LINK_KEY_SIZE
index|]
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Register get link key callback function.    @param  This          Pointer to the EFI_BLUETOOTH_CONFIG_PROTOCOL instance.   @param  Callback      The callback function. NULL means unregister.   @param  Context       Data passed into Callback function. This is optional parameter and may be NULL.    @retval EFI_SUCCESS   The link key callback function is registered successfully.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLUETOOTH_CONFIG_REGISTER_GET_LINK_KEY_CALLBACK
function_decl|)
parameter_list|(
name|IN
name|EFI_BLUETOOTH_CONFIG_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_BLUETOOTH_CONFIG_REGISTER_GET_LINK_KEY_CALLBACK_FUNCTION
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
comment|/**   The callback function to set link key.    @param  This                Pointer to the EFI_BLUETOOTH_CONFIG_PROTOCOL instance.   @param  Context             Context passed from registration.   @param  BDAddr              A pointer to Bluetooth device address.   @param  LinkKey             A pointer to the buffer of link key.    @retval EFI_SUCCESS   The callback function complete successfully.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLUETOOTH_CONFIG_REGISTER_SET_LINK_KEY_CALLBACK_FUNCTION
function_decl|)
parameter_list|(
name|IN
name|EFI_BLUETOOTH_CONFIG_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|VOID
modifier|*
name|Context
parameter_list|,
name|IN
name|BLUETOOTH_ADDRESS
modifier|*
name|BDAddr
parameter_list|,
name|IN
name|UINT8
name|LinkKey
index|[
name|BLUETOOTH_HCI_LINK_KEY_SIZE
index|]
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Register set link key callback function.    @param  This          Pointer to the EFI_BLUETOOTH_CONFIG_PROTOCOL instance.   @param  Callback      The callback function. NULL means unregister.   @param  Context       Data passed into Callback function. This is optional parameter and may be NULL.    @retval EFI_SUCCESS   The link key callback function is registered successfully.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLUETOOTH_CONFIG_REGISTER_SET_LINK_KEY_CALLBACK
function_decl|)
parameter_list|(
name|IN
name|EFI_BLUETOOTH_CONFIG_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_BLUETOOTH_CONFIG_REGISTER_SET_LINK_KEY_CALLBACK_FUNCTION
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
comment|/**   The callback function. It is called after connect completed.    @param  This                Pointer to the EFI_BLUETOOTH_CONFIG_PROTOCOL instance.   @param  Context             Context passed from registration.   @param  CallbackType        Callback type in EFI_BLUETOOTH_CONNECT_COMPLETE_CALLBACK_TYPE.   @param  BDAddr              A pointer to Bluetooth device address.   @param  InputBuffer         A pointer to the buffer of data that is input from callback caller.   @param  InputBufferSize     Indicates the size, in bytes, of the data buffer specified by InputBuffer.    @retval EFI_SUCCESS   The callback function complete successfully.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLUETOOTH_CONFIG_REGISTER_CONNECT_COMPLETE_CALLBACK_FUNCTION
function_decl|)
parameter_list|(
name|IN
name|EFI_BLUETOOTH_CONFIG_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|VOID
modifier|*
name|Context
parameter_list|,
name|IN
name|EFI_BLUETOOTH_CONNECT_COMPLETE_CALLBACK_TYPE
name|CallbackType
parameter_list|,
name|IN
name|BLUETOOTH_ADDRESS
modifier|*
name|BDAddr
parameter_list|,
name|IN
name|VOID
modifier|*
name|InputBuffer
parameter_list|,
name|IN
name|UINTN
name|InputBufferSize
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Register link connect complete callback function.    @param  This          Pointer to the EFI_BLUETOOTH_CONFIG_PROTOCOL instance.   @param  Callback      The callback function. NULL means unregister.   @param  Context       Data passed into Callback function. This is optional parameter and may be NULL.    @retval EFI_SUCCESS   The link connect complete callback function is registered successfully.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLUETOOTH_CONFIG_REGISTER_CONNECT_COMPLETE_CALLBACK
function_decl|)
parameter_list|(
name|IN
name|EFI_BLUETOOTH_CONFIG_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_BLUETOOTH_CONFIG_REGISTER_CONNECT_COMPLETE_CALLBACK_FUNCTION
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
comment|/// This protocol abstracts user interface configuration for Bluetooth device.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_BLUETOOTH_CONFIG_PROTOCOL
block|{
name|EFI_BLUETOOTH_CONFIG_INIT
name|Init
decl_stmt|;
name|EFI_BLUETOOTH_CONFIG_SCAN
name|Scan
decl_stmt|;
name|EFI_BLUETOOTH_CONFIG_CONNECT
name|Connect
decl_stmt|;
name|EFI_BLUETOOTH_CONFIG_DISCONNECT
name|Disconnect
decl_stmt|;
name|EFI_BLUETOOTH_CONFIG_GET_DATA
name|GetData
decl_stmt|;
name|EFI_BLUETOOTH_CONFIG_SET_DATA
name|SetData
decl_stmt|;
name|EFI_BLUETOOTH_CONFIG_GET_REMOTE_DATA
name|GetRemoteData
decl_stmt|;
name|EFI_BLUETOOTH_CONFIG_REGISTER_PIN_CALLBACK
name|RegisterPinCallback
decl_stmt|;
name|EFI_BLUETOOTH_CONFIG_REGISTER_GET_LINK_KEY_CALLBACK
name|RegisterGetLinkKeyCallback
decl_stmt|;
name|EFI_BLUETOOTH_CONFIG_REGISTER_SET_LINK_KEY_CALLBACK
name|RegisterSetLinkKeyCallback
decl_stmt|;
name|EFI_BLUETOOTH_CONFIG_REGISTER_CONNECT_COMPLETE_CALLBACK
name|RegisterLinkConnectCompleteCallback
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiBluetoothConfigProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

