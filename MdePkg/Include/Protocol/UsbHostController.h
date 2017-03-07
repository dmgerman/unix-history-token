begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI_USB_HC_PROTOCOL as defined in EFI 1.10.    The USB Host Controller Protocol is used by code, typically USB bus drivers,    running in the EFI boot services environment, to perform data transactions    over a USB bus. In addition, it provides an abstraction for the root hub of the USB bus.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_USB_HOSTCONTROLLER_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB_HOSTCONTROLLER_H_
end_define

begin_include
include|#
directive|include
file|<Protocol/Usb2HostController.h>
end_include

begin_define
define|#
directive|define
name|EFI_USB_HC_PROTOCOL_GUID
define|\
value|{ \     0xf5089266, 0x1aa0, 0x4953, {0x97, 0xd8, 0x56, 0x2f, 0x8a, 0x73, 0xb5, 0x19 } \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Forward reference for pure ANSI compatability
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|struct
name|_EFI_USB_HC_PROTOCOL
name|EFI_USB_HC_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Protocol definitions
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/**                                                                    Provides software reset for the USB host controller.        @param  This                  A pointer to the EFI_USB_HC_PROTOCOL instance.   @param  Attributes            A bit mask of the reset operation to perform.                                    @retval EFI_SUCCESS           The reset operation succeeded.   @retval EFI_UNSUPPORTED       The type of reset specified by Attributes is not currently supported                                 by the host controller hardware.                                       @retval EFI_INVALID_PARAMETER Attributes is not valid.   @retval EFI_DEVICE_ERROR      An error was encountered while attempting to perform the reset operation.                                     **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USB_HC_PROTOCOL_RESET
function_decl|)
parameter_list|(
name|IN
name|EFI_USB_HC_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT16
name|Attributes
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Retrieves current state of the USB host controller.        @param  This                  A pointer to the EFI_USB_HC_PROTOCOL instance.   @param  State                 A pointer to the EFI_USB_HC_STATE data structure that                                 indicates current state of the USB host controller.                                      @retval EFI_SUCCESS           The state information of the host controller was returned in State.   @retval EFI_INVALID_PARAMETER State is NULL.   @retval EFI_DEVICE_ERROR      An error was encountered while attempting to retrieve the host controller's                                 current state.                                                                                                   **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USB_HC_PROTOCOL_GET_STATE
function_decl|)
parameter_list|(
name|IN
name|EFI_USB_HC_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|EFI_USB_HC_STATE
modifier|*
name|State
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Sets the USB host controller to a specific state.        @param  This                  A pointer to the EFI_USB_HC_PROTOCOL instance.   @param  State                 Indicates the state of the host controller that will be set.                                                                    @retval EFI_SUCCESS           The USB host controller was successfully placed in the state specified by                                 State.                                                                      @retval EFI_INVALID_PARAMETER State is NULL.   @retval EFI_DEVICE_ERROR      Failed to set the state specified by State due to device error.                                                                  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USB_HC_PROTOCOL_SET_STATE
function_decl|)
parameter_list|(
name|IN
name|EFI_USB_HC_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_USB_HC_STATE
name|State
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Submits control transfer to a target USB device.        @param  This                  A pointer to the EFI_USB_HC_PROTOCOL instance.   @param  DeviceAddress         Represents the address of the target device on the USB, which is                                 assigned during USB enumeration.                                   @param  IsSlowDevice          Indicates whether the target device is slow device or full-speed                                 device.                                                            @param  MaximumPacketLength   Indicates the maximum packet size that the default control                                  transfer endpoint is capable of sending or receiving.        @param  Request               A pointer to the USB device request that will be sent to the USB                                 device.   @param  TransferDirection     Specifies the data direction for the transfer. There are three                                  values available, EfiUsbDataIn, EfiUsbDataOut and EfiUsbNoData.   @param  Data                  A pointer to the buffer of data that will be transmitted to USB                                   device or received from USB device.                               @param  DataLength            On input, indicates the size, in bytes, of the data buffer specified                                 by Data. On output, indicates the amount of data actually                                            transferred.                                                           @param  TimeOut               Indicates the maximum time, in milliseconds, which the transfer                                 is allowed to complete.                                           @param  TransferResult        A pointer to the detailed result information generated by this                                   control transfer.                                    @retval EFI_SUCCESS           The control transfer was completed successfully.   @retval EFI_OUT_OF_RESOURCES  The control transfer could not be completed due to a lack of resources.                                   @retval EFI_INVALID_PARAMETER Some parameters are invalid.   @retval EFI_TIMEOUT           The control transfer failed due to timeout.   @retval EFI_DEVICE_ERROR      The control transfer failed due to host controller or device error.                                  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USB_HC_PROTOCOL_CONTROL_TRANSFER
function_decl|)
parameter_list|(
name|IN
name|EFI_USB_HC_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT8
name|DeviceAddress
parameter_list|,
name|IN
name|BOOLEAN
name|IsSlowDevice
parameter_list|,
name|IN
name|UINT8
name|MaximumPacketLength
parameter_list|,
name|IN
name|EFI_USB_DEVICE_REQUEST
modifier|*
name|Request
parameter_list|,
name|IN
name|EFI_USB_DATA_DIRECTION
name|TransferDirection
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
name|Data
name|OPTIONAL
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|DataLength
name|OPTIONAL
parameter_list|,
name|IN
name|UINTN
name|TimeOut
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|TransferResult
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Submits bulk transfer to a bulk endpoint of a USB device.        @param  This                  A pointer to the EFI_USB_HC_PROTOCOL instance.   @param  DeviceAddress         Represents the address of the target device on the USB, which is                                 assigned during USB enumeration.                                   @param  EndPointAddress       The combination of an endpoint number and an endpoint                                  direction of the target USB device. Each endpoint address                                  supports data transfer in one direction except the control                                  endpoint (whose default endpoint address is 0). It is the                                  caller's responsibility to make sure that the EndPointAddress                                  represents a bulk endpoint.                    @param  MaximumPacketLength   Indicates the maximum packet size that the default control                                  transfer endpoint is capable of sending or receiving.        @param  Data                  A pointer to the buffer of data that will be transmitted to USB                                   device or received from USB device.                               @param  DataLength            On input, indicates the size, in bytes, of the data buffer specified                                 by Data. On output, indicates the amount of data actually                                            transferred.                @param  DataToggle            A pointer to the data toggle value.                                                                              @param  TimeOut               Indicates the maximum time, in milliseconds, which the transfer                                 is allowed to complete.                                           @param  TransferResult        A pointer to the detailed result information of the bulk transfer.                                    @retval EFI_SUCCESS           The bulk transfer was completed successfully.   @retval EFI_OUT_OF_RESOURCES  The bulk transfer could not be completed due to a lack of resources.                                   @retval EFI_INVALID_PARAMETER Some parameters are invalid.   @retval EFI_TIMEOUT           The bulk transfer failed due to timeout.   @retval EFI_DEVICE_ERROR      The bulk transfer failed due to host controller or device error.                                  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USB_HC_PROTOCOL_BULK_TRANSFER
function_decl|)
parameter_list|(
name|IN
name|EFI_USB_HC_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT8
name|DeviceAddress
parameter_list|,
name|IN
name|UINT8
name|EndPointAddress
parameter_list|,
name|IN
name|UINT8
name|MaximumPacketLength
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
name|Data
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|DataLength
parameter_list|,
name|IN
name|OUT
name|UINT8
modifier|*
name|DataToggle
parameter_list|,
name|IN
name|UINTN
name|TimeOut
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|TransferResult
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Submits an asynchronous interrupt transfer to an interrupt endpoint of a USB device.        @param  This                  A pointer to the EFI_USB_HC_PROTOCOL instance.   @param  DeviceAddress         Represents the address of the target device on the USB, which is                                 assigned during USB enumeration.                                   @param  EndPointAddress       The combination of an endpoint number and an endpoint                                 direction of the target USB device. Each endpoint address                                 supports data transfer in one direction except the control                                 endpoint (whose default endpoint address is zero). It is the                                 caller's responsibility to make sure that the                                 EndPointAddress represents an interrupt endpoint.        @param  IsSlowDevice          Indicates whether the target device is slow device or full-speed                                 device.                                                                             @param  MaximumPacketLength   Indicates the maximum packet size that the default control                                  transfer endpoint is capable of sending or receiving.        @param  IsNewTransfer         If TRUE, an asynchronous interrupt pipe is built between the host                                                        and the target interrupt endpoint. If FALSE, the specified asynchronous                                  interrupt pipe is canceled. If TRUE, and an interrupt transfer exists                                  for the target end point, then EFI_INVALID_PARAMETER is returned.         @param  DataToggle            A pointer to the data toggle value. On input, it is valid when                                  IsNewTransfer is TRUE, and it indicates the initial data toggle                                  value the asynchronous interrupt transfer should adopt. On output,                                  it is valid when IsNewTransfer is FALSE, and it is updated to indicate                                  the data toggle value of the subsequent asynchronous interrupt transfer.        @param  PollingInterval       Indicates the interval, in milliseconds, that the asynchronous                                 interrupt transfer is polled.    @param  DataLength            Indicates the length of data to be received at the rate specified by                                 PollingInterval from the target asynchronous interrupt                                               endpoint. This parameter is only required when IsNewTransfer is TRUE.                                                               @param  CallBackFunction      The Callback function. This function is called at the rate specified by                                  PollingInterval. This parameter is only required when IsNewTransfer is TRUE.                                  @param  Context               The context that is passed to the CallBackFunction.                                    @retval EFI_SUCCESS           The asynchronous interrupt transfer request has been successfully                                 submitted or canceled.       @retval EFI_OUT_OF_RESOURCES  The request could not be completed due to a lack of resources.                                   @retval EFI_INVALID_PARAMETER Some parameters are invalid.   @retval EFI_TIMEOUT           The bulk transfer failed due to timeout.   @retval EFI_DEVICE_ERROR      The bulk transfer failed due to host controller or device error.                                  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USB_HC_PROTOCOL_ASYNC_INTERRUPT_TRANSFER
function_decl|)
parameter_list|(
name|IN
name|EFI_USB_HC_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT8
name|DeviceAddress
parameter_list|,
name|IN
name|UINT8
name|EndPointAddress
parameter_list|,
name|IN
name|BOOLEAN
name|IsSlowDevice
parameter_list|,
name|IN
name|UINT8
name|MaxiumPacketLength
parameter_list|,
name|IN
name|BOOLEAN
name|IsNewTransfer
parameter_list|,
name|IN
name|OUT
name|UINT8
modifier|*
name|DataToggle
parameter_list|,
name|IN
name|UINTN
name|PollingInterval
name|OPTIONAL
parameter_list|,
name|IN
name|UINTN
name|DataLength
name|OPTIONAL
parameter_list|,
name|IN
name|EFI_ASYNC_USB_TRANSFER_CALLBACK
name|CallBackFunction
name|OPTIONAL
parameter_list|,
name|IN
name|VOID
modifier|*
name|Context
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Submits synchronous interrupt transfer to an interrupt endpoint of a USB device.        @param  This                  A pointer to the EFI_USB_HC_PROTOCOL instance.   @param  DeviceAddress         Represents the address of the target device on the USB, which is                                 assigned during USB enumeration.                                   @param  EndPointAddress       The combination of an endpoint number and an endpoint                                 direction of the target USB device. Each endpoint address                                 supports data transfer in one direction except the control                                 endpoint (whose default endpoint address is zero). It is the                                 caller's responsibility to make sure that the                                 EndPointAddress represents an interrupt endpoint.     @param  IsSlowDevice          Indicates whether the target device is slow device or full-speed                                 device.                                                                             @param  MaximumPacketLength   Indicates the maximum packet size that the default control                                  transfer endpoint is capable of sending or receiving.          @param  Data                  A pointer to the buffer of data that will be transmitted to USB                                 device or received from USB device.                                                                                            asynchronous interrupt pipe is canceled.                            @param  DataLength            On input, the size, in bytes, of the data buffer specified by Data.                                 On output, the number of bytes transferred.                             @param  DataToggle            A pointer to the data toggle value. On input, it indicates the initial                                  data toggle value the synchronous interrupt transfer should adopt;                                  on output, it is updated to indicate the data toggle value of the                                  subsequent synchronous interrupt transfer.                                  @param  TimeOut               Indicates the maximum time, in milliseconds, which the transfer                                     is allowed to complete.                                               @param  TransferResult        A pointer to the detailed result information from the synchronous                                 interrupt transfer.                                    @retval EFI_SUCCESS           The synchronous interrupt transfer was completed successfully.   @retval EFI_OUT_OF_RESOURCES  The request could not be completed due to a lack of resources.                                     @retval EFI_INVALID_PARAMETER Some parameters are invalid.   @retval EFI_TIMEOUT           The synchronous interrupt transfer failed due to timeout.   @retval EFI_DEVICE_ERROR      The synchronous interrupt transfer failed due to host controller or device error.                                  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USB_HC_PROTOCOL_SYNC_INTERRUPT_TRANSFER
function_decl|)
parameter_list|(
name|IN
name|EFI_USB_HC_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT8
name|DeviceAddress
parameter_list|,
name|IN
name|UINT8
name|EndPointAddress
parameter_list|,
name|IN
name|BOOLEAN
name|IsSlowDevice
parameter_list|,
name|IN
name|UINT8
name|MaximumPacketLength
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
name|Data
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|DataLength
parameter_list|,
name|IN
name|OUT
name|UINT8
modifier|*
name|DataToggle
parameter_list|,
name|IN
name|UINTN
name|TimeOut
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|TransferResult
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Submits isochronous transfer to an isochronous endpoint of a USB device.        @param  This                  A pointer to the EFI_USB_HC_PROTOCOL instance.   @param  DeviceAddress         Represents the address of the target device on the USB, which is                                 assigned during USB enumeration.                                   @param  EndPointAddress       The combination of an endpoint number and an endpoint                                 direction of the target USB device. Each endpoint address                                 supports data transfer in one direction except the control                                 endpoint (whose default endpoint address is 0). It is the caller's                                 responsibility to make sure that the EndPointAddress                                 represents an isochronous endpoint.                     @param  MaximumPacketLength   Indicates the maximum packet size that the default control                                  transfer endpoint is capable of sending or receiving.          @param  Data                  A pointer to the buffer of data that will be transmitted to USB                                 device or received from USB device.                                                                                            asynchronous interrupt pipe is canceled.                            @param  DataLength            Specifies the length, in bytes, of the data to be sent to or received                                 from the USB device.                                                    @param  TransferResult        A pointer to the detailed result information from the isochronous                                 transfer.                                    @retval EFI_SUCCESS           The isochronous transfer was completed successfully.   @retval EFI_OUT_OF_RESOURCES  The isochronous could not be completed due to a lack of resources.                                     @retval EFI_INVALID_PARAMETER Some parameters are invalid.   @retval EFI_TIMEOUT           The isochronous transfer failed due to timeout.   @retval EFI_DEVICE_ERROR      The isochronous transfer failed due to host controller or device error.                                  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USB_HC_PROTOCOL_ISOCHRONOUS_TRANSFER
function_decl|)
parameter_list|(
name|IN
name|EFI_USB_HC_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT8
name|DeviceAddress
parameter_list|,
name|IN
name|UINT8
name|EndPointAddress
parameter_list|,
name|IN
name|UINT8
name|MaximumPacketLength
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
name|Data
parameter_list|,
name|IN
name|UINTN
name|DataLength
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|TransferResult
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Submits nonblocking isochronous transfer to an isochronous endpoint of a USB device.        @param  This                  A pointer to the EFI_USB_HC_PROTOCOL instance.   @param  DeviceAddress         Represents the address of the target device on the USB, which is                                 assigned during USB enumeration.                                   @param  EndPointAddress       The combination of an endpoint number and an endpoint                                 direction of the target USB device. Each endpoint address                                 supports data transfer in one direction except the control                                 endpoint (whose default endpoint address is zero). It is the                                 caller's responsibility to make sure that the                                 EndPointAddress represents an isochronous endpoint.                @param  MaximumPacketLength   Indicates the maximum packet size that the default control                                  transfer endpoint is capable of sending or receiving. For isochronous                                  endpoints, this value is used to reserve the bus time in the schedule,                                  required for the perframe data payloads. The pipe may, on an ongoing basis,                                 actually use less bandwidth than that reserved.         @param  Data                  A pointer to the buffer of data that will be transmitted to USB                                 device or received from USB device.                                                                                            asynchronous interrupt pipe is canceled.                            @param  DataLength            Specifies the length, in bytes, of the data to be sent to or received                                 from the USB device.                                                    @param  IsochronousCallback   The Callback function.This function is called if the requested                                 isochronous transfer is completed.   @param  Context               Data passed to the IsochronousCallback function. This is                                 an optional parameter and may be NULL.                                    @retval EFI_SUCCESS           The asynchronous isochronous transfer was completed successfully.   @retval EFI_OUT_OF_RESOURCES  The asynchronous isochronous could not be completed due to a lack of resources.                                     @retval EFI_INVALID_PARAMETER Some parameters are invalid.                                  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USB_HC_PROTOCOL_ASYNC_ISOCHRONOUS_TRANSFER
function_decl|)
parameter_list|(
name|IN
name|EFI_USB_HC_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT8
name|DeviceAddress
parameter_list|,
name|IN
name|UINT8
name|EndPointAddress
parameter_list|,
name|IN
name|UINT8
name|MaximumPacketLength
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
name|Data
parameter_list|,
name|IN
name|UINTN
name|DataLength
parameter_list|,
name|IN
name|EFI_ASYNC_USB_TRANSFER_CALLBACK
name|IsochronousCallBack
parameter_list|,
name|IN
name|VOID
modifier|*
name|Context
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Retrieves the number of root hub ports.        @param  This                  A pointer to the EFI_USB_HC_PROTOCOL instance.   @param  PortNumber            A pointer to the number of the root hub ports.                                                                    @retval EFI_SUCCESS           The port number was retrieved successfully.   @retval EFI_DEVICE_ERROR      An error was encountered while attempting to retrieve the port number.   @retval EFI_INVALID_PARAMETER PortNumber is NULL.                                  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USB_HC_PROTOCOL_GET_ROOTHUB_PORT_NUMBER
function_decl|)
parameter_list|(
name|IN
name|EFI_USB_HC_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|UINT8
modifier|*
name|PortNumber
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Retrieves the current status of a USB root hub port.        @param  This                  A pointer to the EFI_USB_HC_PROTOCOL instance.   @param  PortNumber            Specifies the root hub port from which the status is to be retrieved.                                 This value is zero based. For example, if a root hub has two ports,                                 then the first port is numbered 0, and the second port is                                 numbered 1.   @param  PortStatus            A pointer to the current port status bits and port status change bits.                                                                    @retval EFI_SUCCESS           The status of the USB root hub port specified by PortNumber                                 was returned in PortStatus.                                   @retval EFI_INVALID_PARAMETER PortNumber is invalid.                                  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USB_HC_PROTOCOL_GET_ROOTHUB_PORT_STATUS
function_decl|)
parameter_list|(
name|IN
name|EFI_USB_HC_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT8
name|PortNumber
parameter_list|,
name|OUT
name|EFI_USB_PORT_STATUS
modifier|*
name|PortStatus
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Sets a feature for the specified root hub port.        @param  This                  A pointer to the EFI_USB_HC_PROTOCOL instance.   @param  PortNumber            Specifies the root hub port from which the status is to be retrieved.                                 This value is zero based. For example, if a root hub has two ports,                                 then the first port is numbered 0, and the second port is                                 numbered 1.   @param  PortFeature           Indicates the feature selector associated with the feature set                                 request.                                    @retval EFI_SUCCESS           The feature specified by PortFeature was set for the USB                                 root hub port specified by PortNumber.                     @retval EFI_INVALID_PARAMETER PortNumber is invalid or PortFeature is invalid for this function.                                  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USB_HC_PROTOCOL_SET_ROOTHUB_PORT_FEATURE
function_decl|)
parameter_list|(
name|IN
name|EFI_USB_HC_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT8
name|PortNumber
parameter_list|,
name|IN
name|EFI_USB_PORT_FEATURE
name|PortFeature
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**                                                                    Clears a feature for the specified root hub port.        @param  This                  A pointer to the EFI_USB_HC_PROTOCOL instance.   @param  PortNumber            Specifies the root hub port from which the status is to be retrieved.                                 This value is zero based. For example, if a root hub has two ports,                                 then the first port is numbered 0, and the second port is                                 numbered 1.   @param  PortFeature           Indicates the feature selector associated with the feature clear                                 request.                                    @retval EFI_SUCCESS           The feature specified by PortFeature was cleared for the USB                                 root hub port specified by PortNumber.                     @retval EFI_INVALID_PARAMETER PortNumber is invalid or PortFeature is invalid for this function.                                  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_USB_HC_PROTOCOL_CLEAR_ROOTHUB_PORT_FEATURE
function_decl|)
parameter_list|(
name|IN
name|EFI_USB_HC_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT8
name|PortNumber
parameter_list|,
name|IN
name|EFI_USB_PORT_FEATURE
name|PortFeature
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_USB_HC_PROTOCOL provides USB host controller management, basic data transactions
end_comment

begin_comment
comment|/// over a USB bus, and USB root hub access. A device driver that wishes to manage a USB bus in a
end_comment

begin_comment
comment|/// system retrieves the EFI_USB_HC_PROTOCOL instance that is associated with the USB bus to be
end_comment

begin_comment
comment|/// managed. A device handle for a USB host controller will minimally contain an
end_comment

begin_comment
comment|/// EFI_DEVICE_PATH_PROTOCOL instance, and an EFI_USB_HC_PROTOCOL instance.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_USB_HC_PROTOCOL
block|{
name|EFI_USB_HC_PROTOCOL_RESET
name|Reset
decl_stmt|;
name|EFI_USB_HC_PROTOCOL_GET_STATE
name|GetState
decl_stmt|;
name|EFI_USB_HC_PROTOCOL_SET_STATE
name|SetState
decl_stmt|;
name|EFI_USB_HC_PROTOCOL_CONTROL_TRANSFER
name|ControlTransfer
decl_stmt|;
name|EFI_USB_HC_PROTOCOL_BULK_TRANSFER
name|BulkTransfer
decl_stmt|;
name|EFI_USB_HC_PROTOCOL_ASYNC_INTERRUPT_TRANSFER
name|AsyncInterruptTransfer
decl_stmt|;
name|EFI_USB_HC_PROTOCOL_SYNC_INTERRUPT_TRANSFER
name|SyncInterruptTransfer
decl_stmt|;
name|EFI_USB_HC_PROTOCOL_ISOCHRONOUS_TRANSFER
name|IsochronousTransfer
decl_stmt|;
name|EFI_USB_HC_PROTOCOL_ASYNC_ISOCHRONOUS_TRANSFER
name|AsyncIsochronousTransfer
decl_stmt|;
name|EFI_USB_HC_PROTOCOL_GET_ROOTHUB_PORT_NUMBER
name|GetRootHubPortNumber
decl_stmt|;
name|EFI_USB_HC_PROTOCOL_GET_ROOTHUB_PORT_STATUS
name|GetRootHubPortStatus
decl_stmt|;
name|EFI_USB_HC_PROTOCOL_SET_ROOTHUB_PORT_FEATURE
name|SetRootHubPortFeature
decl_stmt|;
name|EFI_USB_HC_PROTOCOL_CLEAR_ROOTHUB_PORT_FEATURE
name|ClearRootHubPortFeature
decl_stmt|;
comment|///
comment|/// The major revision number of the USB host controller. The revision information
comment|/// indicates the release of the Universal Serial Bus Specification with which the
comment|/// host controller is compliant.
comment|///
name|UINT16
name|MajorRevision
decl_stmt|;
comment|///
comment|/// The minor revision number of the USB host controller. The revision information
comment|/// indicates the release of the Universal Serial Bus Specification with which the
comment|/// host controller is compliant.
comment|///
name|UINT16
name|MinorRevision
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiUsbHcProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

